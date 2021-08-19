/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "WorldSession.h"
#include "AccountMgr.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "Common.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Language.h"
#include "LanguageMgr.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "Util.h"
#include "World.h"
#include "WorldPacket.h"

void WorldSession::HandleChatMessageOpcode(WorldPackets::Chat::ChatMessage& chatMessage)
{
    ChatMsg type;

    switch (chatMessage.GetOpcode())
    {
        case CMSG_CHAT_MESSAGE_SAY:
            type = CHAT_MSG_SAY;
            break;
        case CMSG_CHAT_MESSAGE_YELL:
            type = CHAT_MSG_YELL;
            break;
        case CMSG_CHAT_MESSAGE_GUILD:
            type = CHAT_MSG_GUILD;
            break;
        case CMSG_CHAT_MESSAGE_OFFICER:
            type = CHAT_MSG_OFFICER;
            break;
        case CMSG_CHAT_MESSAGE_PARTY:
            type = CHAT_MSG_PARTY;
            break;
        case CMSG_CHAT_MESSAGE_RAID:
            type = CHAT_MSG_RAID;
            break;
        case CMSG_CHAT_MESSAGE_RAID_WARNING:
            type = CHAT_MSG_RAID_WARNING;
            break;
        case CMSG_CHAT_MESSAGE_INSTANCE_CHAT:
            type = CHAT_MSG_INSTANCE_CHAT;
            break;
        default:
            TC_LOG_ERROR("network", "HandleMessagechatOpcode : Unknown chat opcode (%u)", chatMessage.GetOpcode());
            return;
    }

    HandleChatMessage(type, Language(chatMessage.Language), chatMessage.Text);
}

void WorldSession::HandleChatMessageWhisperOpcode(WorldPackets::Chat::ChatMessageWhisper& chatMessageWhisper)
{
    HandleChatMessage(CHAT_MSG_WHISPER, Language(chatMessageWhisper.Language), chatMessageWhisper.Text, chatMessageWhisper.Target);
}

void WorldSession::HandleChatMessageChannelOpcode(WorldPackets::Chat::ChatMessageChannel& chatMessageChannel)
{
    HandleChatMessage(CHAT_MSG_CHANNEL, Language(chatMessageChannel.Language), chatMessageChannel.Text, chatMessageChannel.Target, chatMessageChannel.ChannelGUID);
}

void WorldSession::HandleChatMessageEmoteOpcode(WorldPackets::Chat::ChatMessageEmote& chatMessageEmote)
{
    HandleChatMessage(CHAT_MSG_EMOTE, LANG_UNIVERSAL, chatMessageEmote.Text);
}

void WorldSession::HandleChatMessage(ChatMsg type, Language lang, std::string msg, std::string target /*= ""*/, Optional<ObjectGuid> channelGuid /*= {}*/)
{
    Player* sender = GetPlayer();

    if (lang == LANG_UNIVERSAL && type != CHAT_MSG_EMOTE)
    {
        TC_LOG_ERROR("entities.player.cheat", "CMSG_MESSAGECHAT: Possible hacking-attempt: %s tried to send a message in universal language", GetPlayerInfo().c_str());
        SendNotification(LANG_UNKNOWN_LANGUAGE);
        return;
    }

    // prevent talking at unknown language (cheating)
    auto languageData = sLanguageMgr->GetLanguageDescById(lang);
    if (languageData.begin() == languageData.end())
    {
        SendNotification(LANG_UNKNOWN_LANGUAGE);
        return;
    }

    if (std::none_of(languageData.begin(), languageData.end(),
        [sender](std::pair<uint32 const, LanguageDesc> const& langDesc) { return langDesc.second.SkillId == 0 || sender->HasSkill(langDesc.second.SkillId); }))
    {
        // also check SPELL_AURA_COMPREHEND_LANGUAGE (client offers option to speak in that language)
        if (!sender->HasAuraTypeWithMiscvalue(SPELL_AURA_COMPREHEND_LANGUAGE, lang))
        {
            SendNotification(LANG_NOT_LEARNED_LANGUAGE);
            return;
        }
    }

    // send in universal language if player in .gm on mode (ignore spell effects)
    if (sender->IsGameMaster())
        lang = LANG_UNIVERSAL;
    else
    {
        // send in universal language in two side iteration allowed mode
        if (HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHAT))
            lang = LANG_UNIVERSAL;
        else
        {
            switch (type)
            {
                case CHAT_MSG_PARTY:
                case CHAT_MSG_RAID:
                case CHAT_MSG_RAID_WARNING:
                    // allow two side chat at group channel if two side group allowed
                    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP))
                        lang = LANG_UNIVERSAL;
                    break;
                case CHAT_MSG_GUILD:
                case CHAT_MSG_OFFICER:
                    // allow two side chat at guild channel if two side guild allowed
                    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD))
                        lang = LANG_UNIVERSAL;
                    break;
                default:
                    break;
            }
        }

        // but overwrite it by SPELL_AURA_MOD_LANGUAGE auras (only single case used)
        Unit::AuraEffectList const& ModLangAuras = sender->GetAuraEffectsByType(SPELL_AURA_MOD_LANGUAGE);
        if (!ModLangAuras.empty())
            lang = Language(ModLangAuras.front()->GetMiscValue());
    }

    if (!CanSpeak())
    {
        std::string timeStr = secsToTimeString(m_muteTime - GameTime::GetGameTime());
        SendNotification(GetTrinityString(LANG_WAIT_BEFORE_SPEAKING), timeStr.c_str());
        return;
    }

    if (sender->HasAura(GM_SILENCE_AURA) && type != CHAT_MSG_WHISPER)
    {
        SendNotification(GetTrinityString(LANG_GM_SILENCE), sender->GetName().c_str());
        return;
    }

    if (msg.empty())
        return;

    if (ChatHandler(this).ParseCommands(msg.c_str()))
        return;

    // Strip invisible characters for non-addon messages
    if (sWorld->getBoolConfig(CONFIG_CHAT_FAKE_MESSAGE_PREVENTING))
        stripLineInvisibleChars(msg);

    if (sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY) && !ChatHandler(this).isValidChatMessage(msg.c_str()))
    {
        TC_LOG_ERROR("network", "Player %s (%s) sent a chatmessage with an invalid link: %s", GetPlayer()->GetName().c_str(),
            GetPlayer()->GetGUID().ToString().c_str(), msg.c_str());

        if (sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_KICK))
            KickPlayer();

        return;
    }

    switch (type)
    {
        case CHAT_MSG_SAY:
        {
            // Prevent cheating
            if (!sender->IsAlive())
                return;

            if (sender->getLevel() < sWorld->getIntConfig(CONFIG_CHAT_SAY_LEVEL_REQ))
            {
                SendNotification(GetTrinityString(LANG_SAY_REQ), sWorld->getIntConfig(CONFIG_CHAT_SAY_LEVEL_REQ));
                return;
            }

            sender->Say(msg, lang);
            break;
        }
        case CHAT_MSG_EMOTE:
        {
            // Prevent cheating
            if (!sender->IsAlive())
                return;

            if (sender->getLevel() < sWorld->getIntConfig(CONFIG_CHAT_EMOTE_LEVEL_REQ))
            {
                SendNotification(GetTrinityString(LANG_SAY_REQ), sWorld->getIntConfig(CONFIG_CHAT_EMOTE_LEVEL_REQ));
                return;
            }

            sender->TextEmote(msg);
            break;
        }
        case CHAT_MSG_YELL:
        {
            // Prevent cheating
            if (!sender->IsAlive())
                return;

            if (sender->getLevel() < sWorld->getIntConfig(CONFIG_CHAT_YELL_LEVEL_REQ))
            {
                SendNotification(GetTrinityString(LANG_SAY_REQ), sWorld->getIntConfig(CONFIG_CHAT_YELL_LEVEL_REQ));
                return;
            }

            sender->Yell(msg, lang);
            break;
        }
        case CHAT_MSG_WHISPER:
        {
            /// @todo implement cross realm whispers (someday)
            ExtendedPlayerName extName = ExtractExtendedPlayerName(target);

            if (!normalizePlayerName(extName.Name))
            {
                SendChatPlayerNotfoundNotice(target);
                break;
            }

            Player* receiver = ObjectAccessor::FindConnectedPlayerByName(extName.Name);
            if (!receiver || (lang != LANG_ADDON && !receiver->isAcceptWhispers() && receiver->GetSession()->HasPermission(rbac::RBAC_PERM_CAN_FILTER_WHISPERS) && !receiver->IsInWhisperWhiteList(sender->GetGUID())))
            {
                SendChatPlayerNotfoundNotice(target);
                return;
            }
            if (!sender->IsGameMaster() && sender->getLevel() < sWorld->getIntConfig(CONFIG_CHAT_WHISPER_LEVEL_REQ) && !receiver->IsInWhisperWhiteList(sender->GetGUID()))
            {
                SendNotification(GetTrinityString(LANG_WHISPER_REQ), sWorld->getIntConfig(CONFIG_CHAT_WHISPER_LEVEL_REQ));
                return;
            }

            if (GetPlayer()->GetTeam() != receiver->GetTeam() && !HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHAT) && !receiver->IsInWhisperWhiteList(sender->GetGUID()))
            {
                SendChatPlayerNotfoundNotice(target);
                return;
            }

            if (GetPlayer()->HasAura(1852) && !receiver->IsGameMaster())
            {
                SendNotification(GetTrinityString(LANG_GM_SILENCE), GetPlayer()->GetName().c_str());
                return;
            }

            // If player is a Gamemaster and doesn't accept whisper, we auto-whitelist every player that the Gamemaster is talking to
            // We also do that if a player is under the required level for whispers.
            if (receiver->getLevel() < sWorld->getIntConfig(CONFIG_CHAT_WHISPER_LEVEL_REQ) ||
                (HasPermission(rbac::RBAC_PERM_CAN_FILTER_WHISPERS) && !sender->isAcceptWhispers() && !sender->IsInWhisperWhiteList(receiver->GetGUID())))
                sender->AddWhisperWhiteList(receiver->GetGUID());

            GetPlayer()->Whisper(msg, lang, receiver);
            break;
        }
        case CHAT_MSG_PARTY:
        {
            // if player is in battleground, he cannot say to battleground members by /p
            Group* group = GetPlayer()->GetOriginalGroup();
            if (!group)
            {
                group = sender->GetGroup();
                if (!group || group->isBGGroup())
                    return;
            }

            if (group->IsLeader(GetPlayer()->GetGUID()))
                type = CHAT_MSG_PARTY_LEADER;

            sScriptMgr->OnPlayerChat(GetPlayer(), type, lang, msg, group);

            WorldPackets::Chat::Chat packet;
            packet.Initialize(ChatMsg(type), lang, sender, nullptr, msg);
            group->BroadcastPacket(packet.Write(), false, group->GetMemberGroup(GetPlayer()->GetGUID()));
            break;
        }
        case CHAT_MSG_GUILD:
        {
            if (GetPlayer()->GetGuildId())
            {
                if (Guild* guild = sGuildMgr->GetGuildById(GetPlayer()->GetGuildId()))
                {
                    sScriptMgr->OnPlayerChat(GetPlayer(), type, lang, msg, guild);

                    guild->BroadcastToGuild(this, false, msg, lang == LANG_ADDON ? LANG_ADDON : LANG_UNIVERSAL);
                }
            }
            break;
        }
        case CHAT_MSG_OFFICER:
        {
            if (GetPlayer()->GetGuildId())
            {
                if (Guild* guild = sGuildMgr->GetGuildById(GetPlayer()->GetGuildId()))
                {
                    sScriptMgr->OnPlayerChat(GetPlayer(), type, lang, msg, guild);

                    guild->BroadcastToGuild(this, true, msg, lang == LANG_ADDON ? LANG_ADDON : LANG_UNIVERSAL);
                }
            }
            break;
        }
        case CHAT_MSG_RAID:
        {
            Group* group = GetPlayer()->GetGroup();
            if (!group || !group->isRaidGroup() || group->isBGGroup())
                return;

            if (group->IsLeader(GetPlayer()->GetGUID()))
                type = CHAT_MSG_RAID_LEADER;

            sScriptMgr->OnPlayerChat(GetPlayer(), type, lang, msg, group);

            WorldPackets::Chat::Chat packet;
            packet.Initialize(ChatMsg(type), lang, sender, nullptr, msg);
            group->BroadcastPacket(packet.Write(), false);
            break;
        }
        case CHAT_MSG_RAID_WARNING:
        {
            Group* group = GetPlayer()->GetGroup();
            if (!group || !(group->isRaidGroup() || sWorld->getBoolConfig(CONFIG_CHAT_PARTY_RAID_WARNINGS)) || !(group->IsLeader(GetPlayer()->GetGUID()) || group->IsAssistant(GetPlayer()->GetGUID())) || group->isBGGroup())
                return;

            sScriptMgr->OnPlayerChat(GetPlayer(), type, lang, msg, group);

            WorldPackets::Chat::Chat packet;
            //in battleground, raid warning is sent only to players in battleground - code is ok
            packet.Initialize(CHAT_MSG_RAID_WARNING, lang, sender, nullptr, msg);
            group->BroadcastPacket(packet.Write(), false);
            break;
        }
        case CHAT_MSG_CHANNEL:
        {
            if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHAT_CHANNEL_REQ))
            {
                if (sender->getLevel() < sWorld->getIntConfig(CONFIG_CHAT_CHANNEL_LEVEL_REQ))
                {
                    SendNotification(GetTrinityString(LANG_CHANNEL_REQ), sWorld->getIntConfig(CONFIG_CHAT_CHANNEL_LEVEL_REQ));
                    return;
                }
            }

            Channel* chn = channelGuid
                ? ChannelMgr::GetChannelForPlayerByGuid(*channelGuid, sender)
                : ChannelMgr::GetChannelForPlayerByNamePart(target, sender);
            if (chn)
            {
                sScriptMgr->OnPlayerChat(sender, type, lang, msg, chn);
                chn->Say(sender->GetGUID(), msg, lang);
            }
            break;
        }
        case CHAT_MSG_INSTANCE_CHAT:
        {
            Group* group = GetPlayer()->GetGroup();
            if (!group)
                return;

            if (group->IsLeader(GetPlayer()->GetGUID()))
                type = CHAT_MSG_INSTANCE_CHAT_LEADER;

            sScriptMgr->OnPlayerChat(GetPlayer(), type, lang, msg, group);

            WorldPackets::Chat::Chat packet;
            packet.Initialize(ChatMsg(type), lang, sender, nullptr, msg);
            group->BroadcastPacket(packet.Write(), false);
            break;
        }
        default:
            TC_LOG_ERROR("network", "CHAT: unknown message type %u, lang: %u", type, lang);
            break;
    }
}

void WorldSession::HandleChatAddonMessageOpcode(WorldPackets::Chat::ChatAddonMessage& chatAddonMessage)
{
    HandleChatAddonMessage(chatAddonMessage.Params.Type, chatAddonMessage.Params.Prefix, chatAddonMessage.Params.Text, chatAddonMessage.Params.IsLogged);
}

void WorldSession::HandleChatAddonMessageTargetedOpcode(WorldPackets::Chat::ChatAddonMessageTargeted& chatAddonMessageTargeted)
{
    HandleChatAddonMessage(chatAddonMessageTargeted.Params.Type, chatAddonMessageTargeted.Params.Prefix, chatAddonMessageTargeted.Params.Text,
        chatAddonMessageTargeted.Params.IsLogged, chatAddonMessageTargeted.Target, chatAddonMessageTargeted.ChannelGUID);
}

void WorldSession::HandleChatAddonMessage(ChatMsg type, std::string prefix, std::string text, bool isLogged, std::string target /*= ""*/, Optional<ObjectGuid> channelGuid /*= {}*/)
{
    Player* sender = GetPlayer();

    if (prefix.empty() || prefix.length() > 16)
        return;

    // Disabled addon channel?
    if (!sWorld->getBoolConfig(CONFIG_ADDON_CHANNEL))
        return;

    if (prefix == AddonChannelCommandHandler::PREFIX && AddonChannelCommandHandler(this).ParseCommands(text.c_str()))
        return;

    switch (type)
    {
        case CHAT_MSG_GUILD:
        case CHAT_MSG_OFFICER:
        {
            if (sender->GetGuildId())
                if (Guild* guild = sGuildMgr->GetGuildById(sender->GetGuildId()))
                    guild->BroadcastAddonToGuild(this, type == CHAT_MSG_OFFICER, text, prefix, isLogged);
            break;
        }
        case CHAT_MSG_WHISPER:
        {
            /// @todo implement cross realm whispers (someday)
            ExtendedPlayerName extName = ExtractExtendedPlayerName(target);

            if (!normalizePlayerName(extName.Name))
                break;

            Player* receiver = ObjectAccessor::FindPlayerByName(extName.Name);
            if (!receiver)
                break;

            sender->WhisperAddon(text, prefix, isLogged, receiver);
            break;
        }
        // Messages sent to "RAID" while in a party will get delivered to "PARTY"
        case CHAT_MSG_PARTY:
        case CHAT_MSG_RAID:
        case CHAT_MSG_INSTANCE_CHAT:
        {
            Group* group = nullptr;
            int32 subGroup = -1;
            if (type != CHAT_MSG_INSTANCE_CHAT)
                group = sender->GetOriginalGroup();

            if (!group)
            {
                group = sender->GetGroup();
                if (!group)
                    break;

                if (type == CHAT_MSG_PARTY)
                    subGroup = sender->GetSubGroup();
            }

            WorldPackets::Chat::Chat packet;
            packet.Initialize(type, isLogged ? LANG_ADDON_LOGGED : LANG_ADDON, sender, nullptr, text, 0, "", DEFAULT_LOCALE, prefix);
            group->BroadcastAddonMessagePacket(packet.Write(), prefix, true, subGroup, sender->GetGUID());
            break;
        }
        case CHAT_MSG_CHANNEL:
        {
            Channel* chn = channelGuid
                ? ChannelMgr::GetChannelForPlayerByGuid(*channelGuid, sender)
                : ChannelMgr::GetChannelForPlayerByNamePart(target, sender);
            if (chn)
                chn->AddonSay(sender->GetGUID(), prefix, text.c_str(), isLogged);
            break;
        }
        default:
        {
            TC_LOG_ERROR("misc", "HandleAddonMessagechatOpcode: unknown addon message type %u", type);
            break;
        }
    }
}

void WorldSession::HandleChatMessageAFKOpcode(WorldPackets::Chat::ChatMessageAFK& chatMessageAFK)
{
    Player* sender = GetPlayer();

    if (sender->IsInCombat())
        return;

    if (sender->HasAura(GM_SILENCE_AURA))
    {
        SendNotification(GetTrinityString(LANG_GM_SILENCE), sender->GetName().c_str());
        return;
    }

    if (sender->isAFK()) // Already AFK
    {
        if (chatMessageAFK.Text.empty())
            sender->ToggleAFK(); // Remove AFK
        else
            sender->autoReplyMsg = chatMessageAFK.Text; // Update message
    }
    else // New AFK mode
    {
        sender->autoReplyMsg = chatMessageAFK.Text.empty() ? GetTrinityString(LANG_PLAYER_AFK_DEFAULT) : chatMessageAFK.Text;

        if (sender->isDND())
            sender->ToggleDND();

        sender->ToggleAFK();
    }

    if (Guild* guild = sender->GetGuild())
        guild->SendEventAwayChanged(sender->GetGUID(), sender->isAFK(), sender->isDND());

    sScriptMgr->OnPlayerChat(sender, CHAT_MSG_AFK, LANG_UNIVERSAL, chatMessageAFK.Text);
}

void WorldSession::HandleChatMessageDNDOpcode(WorldPackets::Chat::ChatMessageDND& chatMessageDND)
{
    Player* sender = GetPlayer();

    if (sender->IsInCombat())
        return;

    if (sender->HasAura(GM_SILENCE_AURA))
    {
        SendNotification(GetTrinityString(LANG_GM_SILENCE), sender->GetName().c_str());
        return;
    }

    if (sender->isDND()) // Already DND
    {
        if (chatMessageDND.Text.empty())
            sender->ToggleDND(); // Remove DND
        else
            sender->autoReplyMsg = chatMessageDND.Text; // Update message
    }
    else // New DND mode
    {
        sender->autoReplyMsg = chatMessageDND.Text.empty() ? GetTrinityString(LANG_PLAYER_DND_DEFAULT) : chatMessageDND.Text;

        if (sender->isAFK())
            sender->ToggleAFK();

        sender->ToggleDND();
    }

    if (Guild* guild = sender->GetGuild())
        guild->SendEventAwayChanged(sender->GetGUID(), sender->isAFK(), sender->isDND());

    sScriptMgr->OnPlayerChat(sender, CHAT_MSG_DND, LANG_UNIVERSAL, chatMessageDND.Text);
}

void WorldSession::HandleEmoteOpcode(WorldPackets::Chat::EmoteClient& /* packet */)
{
    if (!GetPlayer()->IsAlive() || GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        return;

    sScriptMgr->OnPlayerClearEmote(GetPlayer());

    _player->SetEmoteState(EMOTE_ONESHOT_NONE);
}

void WorldSession::HandleTextEmoteOpcode(WorldPackets::Chat::CTextEmote& packet)
{
    if (!_player->IsAlive())
        return;

    if (!CanSpeak())
    {
        std::string timeStr = secsToTimeString(m_muteTime - GameTime::GetGameTime());
        SendNotification(GetTrinityString(LANG_WAIT_BEFORE_SPEAKING), timeStr.c_str());
        return;
    }

    sScriptMgr->OnPlayerTextEmote(_player, packet.SoundIndex, packet.EmoteID, packet.Target);

    EmotesTextEntry const* em = sEmotesTextStore.LookupEntry(packet.EmoteID);
    if (!em)
        return;

    uint32 emoteAnim = em->EmoteID;

    switch (emoteAnim)
    {
        case EMOTE_STATE_SLEEP:
        case EMOTE_STATE_SIT:
        case EMOTE_STATE_KNEEL:
        case EMOTE_ONESHOT_NONE:
            break;
        case EMOTE_STATE_DANCE:
        case EMOTE_STATE_READ:
            _player->SetEmoteState(Emote(emoteAnim));
            break;
        default:
            // Only allow text-emotes for "dead" entities (feign death included)
            if (_player->HasUnitState(UNIT_STATE_DIED))
                break;
            _player->HandleEmoteCommand(emoteAnim, { packet.SpellVisualKitIDs.data(), packet.SpellVisualKitIDs.data() + packet.SpellVisualKitIDs.size() });
            break;
    }

    WorldPackets::Chat::STextEmote textEmote;
    textEmote.SourceGUID = _player->GetGUID();
    textEmote.SourceAccountGUID = GetAccountGUID();
    textEmote.TargetGUID = packet.Target;
    textEmote.EmoteID = packet.EmoteID;
    textEmote.SoundIndex = packet.SoundIndex;
    _player->SendMessageToSetInRange(textEmote.Write(), sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE), true);

    Unit* unit = ObjectAccessor::GetUnit(*_player, packet.Target);

    _player->UpdateCriteria(CRITERIA_TYPE_DO_EMOTE, packet.SoundIndex, 0, 0, unit);

    // Send scripted event call
    if (unit)
        if (Creature* creature = unit->ToCreature())
            creature->AI()->ReceiveEmote(_player, packet.EmoteID);

    if (emoteAnim != EMOTE_ONESHOT_NONE)
        _player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Anim);
}

void WorldSession::HandleChatIgnoredOpcode(WorldPackets::Chat::ChatReportIgnored& chatReportIgnored)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(chatReportIgnored.IgnoredGUID);
    if (!player || !player->GetSession())
        return;

    WorldPackets::Chat::Chat packet;
    packet.Initialize(CHAT_MSG_IGNORED, LANG_UNIVERSAL, _player, _player, GetPlayer()->GetName());
    player->SendDirectMessage(packet.Write());
}

void WorldSession::SendChatPlayerNotfoundNotice(std::string const& name)
{
    SendPacket(WorldPackets::Chat::ChatPlayerNotfound(name).Write());
}

void WorldSession::SendPlayerAmbiguousNotice(std::string const& name)
{
    SendPacket(WorldPackets::Chat::ChatPlayerAmbiguous(name).Write());
}

void WorldSession::SendChatRestricted(ChatRestrictionType restriction)
{
    WorldPackets::Chat::ChatRestricted packet;
    packet.Reason = restriction;
    SendPacket(packet.Write());
}
