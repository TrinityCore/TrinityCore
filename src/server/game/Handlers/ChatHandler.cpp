/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Common.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "GuildMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "DatabaseEnv.h"
#include "CellImpl.h"
#include "Chat.h"
#include "ChannelMgr.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "Language.h"
#include "Log.h"
#include "Opcodes.h"
#include "Player.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Util.h"
#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "ChatPackets.h"

void WorldSession::HandleChatMessageOpcode(WorldPackets::Chat::ChatMessage& packet)
{
    ChatMsg type;

    switch (packet.GetOpcode())
    {/*
        case CMSG_MESSAGECHAT_SAY:
            type = CHAT_MSG_SAY;
            break;
        case CMSG_MESSAGECHAT_YELL:
            type = CHAT_MSG_YELL;
            break;
        case CMSG_MESSAGECHAT_GUILD:
            type = CHAT_MSG_GUILD;
            break;
        case CMSG_MESSAGECHAT_OFFICER:
            type = CHAT_MSG_OFFICER;
            break;
        case CMSG_MESSAGECHAT_PARTY:
            type = CHAT_MSG_PARTY;
            break;
        case CMSG_MESSAGECHAT_RAID:
            type = CHAT_MSG_RAID;
            break;
        case CMSG_MESSAGECHAT_RAID_WARNING:
            type = CHAT_MSG_RAID_WARNING;
            break;
        default:*/
            TC_LOG_ERROR("network", "HandleMessagechatOpcode : Unknown chat opcode (%u)", packet.GetOpcode());
            return;
    }

    HandleChatMessage(type, packet.Language, packet.Text);
}

void WorldSession::HandleChatMessageWhisperOpcode(WorldPackets::Chat::ChatMessageWhisper& packet)
{
    HandleChatMessage(CHAT_MSG_WHISPER, packet.Language, packet.Text, packet.Target);
}

void WorldSession::HandleChatMessageChannelOpcode(WorldPackets::Chat::ChatMessageChannel& packet)
{
    HandleChatMessage(CHAT_MSG_CHANNEL, packet.Language, packet.Text, packet.Target);
}

void WorldSession::HandleChatMessageEmoteOpcode(WorldPackets::Chat::ChatMessageEmote& packet)
{
    HandleChatMessage(CHAT_MSG_EMOTE, LANG_UNIVERSAL, packet.Text);
}

void WorldSession::HandleChatMessage(ChatMsg type, uint32 lang, std::string msg, std::string target /*= ""*/)
{
    Player* sender = GetPlayer();

    if (lang == LANG_UNIVERSAL && type != CHAT_MSG_EMOTE)
    {
        TC_LOG_ERROR("network", "CMSG_MESSAGECHAT: Possible hacking-attempt: %s tried to send a message in universal language", GetPlayerInfo().c_str());
        SendNotification(LANG_UNKNOWN_LANGUAGE);
        return;
    }

    // prevent talking at unknown language (cheating)
    LanguageDesc const* langDesc = GetLanguageDescByID(lang);
    if (!langDesc)
    {
        SendNotification(LANG_UNKNOWN_LANGUAGE);
        return;
    }

    if (langDesc->skill_id != 0 && !sender->HasSkill(langDesc->skill_id))
    {
        // also check SPELL_AURA_COMPREHEND_LANGUAGE (client offers option to speak in that language)
        Unit::AuraEffectList const& langAuras = sender->GetAuraEffectsByType(SPELL_AURA_COMPREHEND_LANGUAGE);
        bool foundAura = false;
        for (Unit::AuraEffectList::const_iterator i = langAuras.begin(); i != langAuras.end(); ++i)
        {
            if ((*i)->GetMiscValue() == int32(lang))
            {
                foundAura = true;
                break;
            }
        }
        if (!foundAura)
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
            lang = ModLangAuras.front()->GetMiscValue();
    }

    if (!sender->CanSpeak())
    {
        std::string timeStr = secsToTimeString(m_muteTime - time(NULL));
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
        case CHAT_MSG_EMOTE:
        case CHAT_MSG_YELL:
        {
            // Prevent cheating
            if (!sender->IsAlive())
                return;

            if (sender->getLevel() < sWorld->getIntConfig(CONFIG_CHAT_SAY_LEVEL_REQ))
            {
                SendNotification(GetTrinityString(LANG_SAY_REQ), sWorld->getIntConfig(CONFIG_CHAT_SAY_LEVEL_REQ));
                return;
            }

            if (type == CHAT_MSG_SAY)
                sender->Say(msg, Language(lang));
            else if (type == CHAT_MSG_EMOTE)
                sender->TextEmote(msg);
            else if (type == CHAT_MSG_YELL)
                sender->Yell(msg, Language(lang));
            break;
        }
        case CHAT_MSG_WHISPER:
        {
            /// @todo implement cross realm whispers (someday)
            ExtendedPlayerName extName = ExtractExtendedPlayerName(target);

            if (!normalizePlayerName(extName.Name))
            {
                SendPlayerNotFoundNotice(target);
                break;
            }

            Player* receiver = ObjectAccessor::FindConnectedPlayerByName(extName.Name);
            if (!receiver || (lang != LANG_ADDON && !receiver->isAcceptWhispers() && receiver->GetSession()->HasPermission(rbac::RBAC_PERM_CAN_FILTER_WHISPERS) && !receiver->IsInWhisperWhiteList(sender->GetGUID())))
            {
                SendPlayerNotFoundNotice(target);
                return;
            }
            if (!sender->IsGameMaster() && sender->getLevel() < sWorld->getIntConfig(CONFIG_CHAT_WHISPER_LEVEL_REQ) && !receiver->IsInWhisperWhiteList(sender->GetGUID()))
            {
                SendNotification(GetTrinityString(LANG_WHISPER_REQ), sWorld->getIntConfig(CONFIG_CHAT_WHISPER_LEVEL_REQ));
                return;
            }

            if (GetPlayer()->GetTeam() != receiver->GetTeam() && !HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHAT) && !receiver->IsInWhisperWhiteList(sender->GetGUID()))
            {
                SendWrongFactionNotice();
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

            GetPlayer()->Whisper(msg, Language(lang), receiver);
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
            packet.Initalize(ChatMsg(type), Language(lang), sender, nullptr, msg);
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
            Group* group = GetPlayer()->GetOriginalGroup();
            if (!group)
                return;

            if (group->IsLeader(GetPlayer()->GetGUID()))
                type = CHAT_MSG_RAID_LEADER;

            sScriptMgr->OnPlayerChat(GetPlayer(), type, lang, msg, group);

            WorldPackets::Chat::Chat packet;
            packet.Initalize(ChatMsg(type), Language(lang), sender, nullptr, msg);
            group->BroadcastPacket(packet.Write(), false);
            break;
        }
        case CHAT_MSG_RAID_WARNING:
        {
            Group* group = GetPlayer()->GetGroup();
            if (!group || !group->isRaidGroup() || !(group->IsLeader(GetPlayer()->GetGUID()) || group->IsAssistant(GetPlayer()->GetGUID())) || group->isBGGroup())
                return;

            sScriptMgr->OnPlayerChat(GetPlayer(), type, lang, msg, group);

            WorldPackets::Chat::Chat packet;
            //in battleground, raid warning is sent only to players in battleground - code is ok
            packet.Initalize(CHAT_MSG_RAID_WARNING, Language(lang), sender, NULL, msg);
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

            if (ChannelMgr* cMgr = ChannelMgr::ForTeam(sender->GetTeam()))
            {
                if (Channel* chn = cMgr->GetChannel(target, sender))
                {
                    sScriptMgr->OnPlayerChat(sender, type, lang, msg, chn);
                    chn->Say(sender->GetGUID(), msg.c_str(), lang);
                }
            }
            break;
        }
        default:
            TC_LOG_ERROR("network", "CHAT: unknown message type %u, lang: %u", type, lang);
            break;
    }
}

void WorldSession::HandleChatAddonMessageOpcode(WorldPackets::Chat::ChatAddonMessage& packet)
{
    ChatMsg type;

    switch (packet.GetOpcode())
    {/*
        case CMSG_MESSAGECHAT_ADDON_GUILD:
            type = CHAT_MSG_GUILD;
            break;
        case CMSG_MESSAGECHAT_ADDON_OFFICER:
            type = CHAT_MSG_OFFICER;
            break;
        case CMSG_MESSAGECHAT_ADDON_PARTY:
            type = CHAT_MSG_PARTY;
            break;
        case CMSG_MESSAGECHAT_ADDON_RAID:
            type = CHAT_MSG_RAID;
            break;*/
        default:
            TC_LOG_ERROR("network", "HandleChatAddonMessageOpcode: Unknown addon chat opcode (%u)", packet.GetOpcode());
            return;
    }

    HandleChatAddonMessage(type, packet.Prefix, packet.Text);
}

void WorldSession::HandleChatAddonMessageWhisperOpcode(WorldPackets::Chat::ChatAddonMessageWhisper& packet)
{
    HandleChatAddonMessage(CHAT_MSG_WHISPER, packet.Prefix, packet.Text, packet.Target);
}

void WorldSession::HandleChatAddonMessage(ChatMsg type, std::string prefix, std::string text, std::string target /*= ""*/)
{
    Player* sender = GetPlayer();

    if (prefix.empty() || prefix.length() > 16)
        return;

    // Disabled addon channel?
    if (!sWorld->getBoolConfig(CONFIG_ADDON_CHANNEL))
        return;

    switch (type)
    {
        case CHAT_MSG_GUILD:
        case CHAT_MSG_OFFICER:
        {
            if (sender->GetGuildId())
                if (Guild* guild = sGuildMgr->GetGuildById(sender->GetGuildId()))
                    guild->BroadcastAddonToGuild(this, type == CHAT_MSG_OFFICER, text, prefix);
            break;
        }
        case CHAT_MSG_WHISPER:
        {
            if (!normalizePlayerName(target))
                break;

            Player* receiver = sObjectAccessor->FindPlayerByName(target);
            if (!receiver)
                break;

            sender->WhisperAddon(text, prefix, receiver);
            break;
        }
        // Messages sent to "RAID" while in a party will get delivered to "PARTY"
        case CHAT_MSG_PARTY:
        case CHAT_MSG_RAID:
        {

            Group* group = sender->GetGroup();
            if (!group)
                break;

            WorldPackets::Chat::Chat packet;
            packet.Initalize(type, LANG_ADDON, sender, nullptr, text, 0, "", DEFAULT_LOCALE, prefix);
            group->BroadcastAddonMessagePacket(packet.Write(), prefix, true, -1, sender->GetGUID());
            break;
        }
        default:
        {
            TC_LOG_ERROR("misc", "HandleAddonMessagechatOpcode: unknown addon message type %u", type);
            break;
        }
    }
}

void WorldSession::HandleChatMessageAFKOpcode(WorldPackets::Chat::ChatMessageAFK& packet)
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
        if (packet.Text.empty())
            sender->ToggleAFK(); // Remove AFK
        else
            sender->autoReplyMsg = packet.Text; // Update message
    }
    else // New AFK mode
    {
        sender->autoReplyMsg = packet.Text.empty() ? GetTrinityString(LANG_PLAYER_AFK_DEFAULT) : packet.Text;

        if (sender->isDND())
            sender->ToggleDND();

        sender->ToggleAFK();
    }

    sScriptMgr->OnPlayerChat(sender, CHAT_MSG_AFK, LANG_UNIVERSAL, packet.Text);
}

void WorldSession::HandleChatMessageDNDOpcode(WorldPackets::Chat::ChatMessageDND& packet)
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
        if (packet.Text.empty())
            sender->ToggleDND(); // Remove DND
        else
            sender->autoReplyMsg = packet.Text; // Update message
    }
    else // New DND mode
    {
        sender->autoReplyMsg = packet.Text.empty() ? GetTrinityString(LANG_PLAYER_DND_DEFAULT) : packet.Text;

        if (sender->isAFK())
            sender->ToggleAFK();

        sender->ToggleDND();
    }

    sScriptMgr->OnPlayerChat(sender, CHAT_MSG_DND, LANG_UNIVERSAL, packet.Text);
}

void WorldSession::HandleEmoteOpcode(WorldPacket& recvData)
{
    if (!GetPlayer()->IsAlive() || GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        return;

    uint32 emote;
    recvData >> emote;
    sScriptMgr->OnPlayerEmote(GetPlayer(), emote);
    GetPlayer()->HandleEmoteCommand(emote);
}

void WorldSession::HandleTextEmoteOpcode(WorldPackets::Chat::CTextEmote& packet)
{
    if (!_player->IsAlive())
        return;

    if (!_player->CanSpeak())
    {
        std::string timeStr = secsToTimeString(m_muteTime - time(NULL));
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
            _player->SetUInt32Value(UNIT_NPC_EMOTESTATE, emoteAnim);
            break;
        default:
            // Only allow text-emotes for "dead" entities (feign death included)
            if (_player->HasUnitState(UNIT_STATE_DIED))
                break;
            _player->HandleEmoteCommand(emoteAnim);
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

    _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE, packet.SoundIndex, 0, 0, unit);

    // Send scripted event call
    if (unit)
        if (Creature* creature = unit->ToCreature())
            creature->AI()->ReceiveEmote(_player, packet.SoundIndex);
}

void WorldSession::HandleChatIgnoredOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    uint8 unk;
    //TC_LOG_DEBUG("network", "WORLD: Received CMSG_CHAT_IGNORED");

    recvData >> unk;                                       // probably related to spam reporting
    guid[5] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[2]);

    Player* player = ObjectAccessor::FindConnectedPlayer(guid);
    if (!player || !player->GetSession())
        return;

    WorldPackets::Chat::Chat packet;
    packet.Initalize(CHAT_MSG_IGNORED, LANG_UNIVERSAL, _player, _player, GetPlayer()->GetName());
    player->SendDirectMessage(packet.Write());
}

void WorldSession::SendPlayerNotFoundNotice(std::string const& name)
{
    WorldPacket data(SMSG_CHAT_PLAYER_NOT_FOUND, name.size()+1);
    data << name;
    SendPacket(&data);
}

void WorldSession::SendPlayerAmbiguousNotice(std::string const& name)
{
    WorldPacket data(SMSG_CHAT_PLAYER_AMBIGUOUS, name.size()+1);
    data << name;
    SendPacket(&data);
}

void WorldSession::SendWrongFactionNotice()
{
    WorldPacket data(SMSG_CHAT_WRONG_FACTION, 0);
    SendPacket(&data);
}

void WorldSession::SendChatRestrictedNotice(ChatRestrictionType restriction)
{
    WorldPacket data(SMSG_CHAT_RESTRICTED, 1);
    data << uint8(restriction);
    SendPacket(&data);
}
