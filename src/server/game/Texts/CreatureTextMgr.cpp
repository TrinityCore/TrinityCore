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

#include "CreatureTextMgr.h"
#include "CreatureTextMgrImpl.h"
#include "CellImpl.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GridNotifiersImpl.h"
#include "Log.h"
#include "MiscPackets.h"
#include "ObjectMgr.h"
#include "World.h"

class CreatureTextBuilder
{
    public:
        CreatureTextBuilder(WorldObject const* obj, uint8 gender, ChatMsg msgtype, uint8 textGroup, uint32 id, uint32 language, WorldObject const* target)
            : _source(obj), _gender(gender), _msgType(msgtype), _textGroup(textGroup), _textId(id), _language(language), _target(target) { }

        WorldPackets::Packet* operator()(LocaleConstant locale) const
        {
            std::string const& text = sCreatureTextMgr->GetLocalizedChatString(_source->GetEntry(), _gender, _textGroup, _textId, locale);
            WorldPackets::Chat::Chat* chat = new WorldPackets::Chat::Chat();
            chat->Initialize(_msgType, Language(_language), _source, _target, text, 0, "", locale);
            return chat;
        }

    private:
        WorldObject const* _source;
        uint8 _gender;
        ChatMsg _msgType;
        uint8 _textGroup;
        uint32 _textId;
        uint32 _language;
        WorldObject const* _target;
};

class PlayerTextBuilder
{
    public:
        PlayerTextBuilder(WorldObject const* obj, WorldObject const* speaker, uint8 gender, ChatMsg msgtype, uint8 textGroup, uint32 id, uint32 language, WorldObject const* target)
            : _source(obj), _talker(speaker), _gender(gender), _msgType(msgtype), _textGroup(textGroup), _textId(id), _language(language), _target(target) { }

        WorldPackets::Packet* operator()(LocaleConstant locale) const
        {
            std::string const& text = sCreatureTextMgr->GetLocalizedChatString(_source->GetEntry(), _gender, _textGroup, _textId, locale);
            WorldPackets::Chat::Chat* chat = new WorldPackets::Chat::Chat();
            chat->Initialize(_msgType, Language(_language), _talker, _target, text, 0, "", locale);
            return chat;
        }

    private:
        WorldObject const* _source;
        WorldObject const* _talker;
        uint8 _gender;
        ChatMsg _msgType;
        uint8 _textGroup;
        uint32 _textId;
        uint32 _language;
        WorldObject const* _target;
};

CreatureTextMgr* CreatureTextMgr::instance()
{
    static CreatureTextMgr instance;
    return &instance;
}

void CreatureTextMgr::LoadCreatureTexts()
{
    uint32 oldMSTime = getMSTime();

    mTextMap.clear(); // for reload case
    //all currently used temp texts are NOT reset

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_TEXT);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 ceature texts. DB table `creature_text` is empty.");

        return;
    }

    uint32 textCount = 0;

    do
    {
        Field* fields = result->Fetch();
        CreatureTextEntry temp;

        temp.creatureId      = fields[0].GetUInt32();
        temp.groupId         = fields[1].GetUInt8();
        temp.id              = fields[2].GetUInt8();
        temp.text            = fields[3].GetString();
        temp.type            = ChatMsg(fields[4].GetUInt8());
        temp.lang            = Language(fields[5].GetUInt8());
        temp.probability     = fields[6].GetFloat();
        temp.emote           = Emote(fields[7].GetUInt32());
        temp.duration        = fields[8].GetUInt32();
        temp.sound           = fields[9].GetUInt32();
        temp.BroadcastTextId = fields[10].GetUInt32();
        temp.TextRange       = CreatureTextRange(fields[11].GetUInt8());

        if (temp.sound)
        {
            if (!sSoundKitStore.LookupEntry(temp.sound))
            {
                TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry %u, Group %u in table `creature_text` has Sound %u but sound does not exist.", temp.creatureId, temp.groupId, temp.sound);
                temp.sound = 0;
            }
        }

        if (!GetLanguageDescByID(temp.lang))
        {
            TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry %u, Group %u in table `creature_text` using Language %u but Language does not exist.", temp.creatureId, temp.groupId, uint32(temp.lang));
            temp.lang = LANG_UNIVERSAL;
        }

        if (temp.type >= MAX_CHAT_MSG_TYPE)
        {
            TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry %u, Group %u in table `creature_text` has Type %u but this Chat Type does not exist.", temp.creatureId, temp.groupId, uint32(temp.type));
            temp.type = CHAT_MSG_SAY;
        }

        if (temp.emote)
        {
            if (!sEmotesStore.LookupEntry(temp.emote))
            {
                TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry %u, Group %u in table `creature_text` has Emote %u but emote does not exist.", temp.creatureId, temp.groupId, uint32(temp.emote));
                temp.emote = EMOTE_ONESHOT_NONE;
            }
        }

        if (temp.BroadcastTextId)
        {
            if (!sBroadcastTextStore.LookupEntry(temp.BroadcastTextId))
            {
                TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry %u, Group %u, Id %u in table `creature_text` has non-existing or incompatible BroadcastTextId %u.", temp.creatureId, temp.groupId, temp.id, temp.BroadcastTextId);
                temp.BroadcastTextId = 0;
            }
        }

        if (temp.TextRange > TEXT_RANGE_WORLD)
        {
            TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry %u, Group %u, Id %u in table `creature_text` has incorrect TextRange %u.", temp.creatureId, temp.groupId, temp.id, temp.TextRange);
            temp.TextRange = TEXT_RANGE_NORMAL;
        }

        // add the text into our entry's group
        mTextMap[temp.creatureId][temp.groupId].push_back(temp);

        ++textCount;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u creature texts for " SZFMTD " creatures in %u ms", textCount, mTextMap.size(), GetMSTimeDiffToNow(oldMSTime));
}

void CreatureTextMgr::LoadCreatureTextLocales()
{
    uint32 oldMSTime = getMSTime();

    mLocaleTextMap.clear(); // for reload case

    QueryResult result = WorldDatabase.Query("SELECT CreatureId, GroupId, ID, Locale, Text FROM creature_text_locale");

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 creatureId        = fields[0].GetUInt32();
        uint32 groupId           = fields[1].GetUInt8();
        uint32 id                = fields[2].GetUInt8();
        std::string localeName   = fields[3].GetString();

        LocaleConstant locale    = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        CreatureTextLocale& data = mLocaleTextMap[CreatureTextId(creatureId, groupId, id)];
        ObjectMgr::AddLocaleString(fields[4].GetString(), locale, data.Text);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u creature localized texts in %u ms", uint32(mLocaleTextMap.size()), GetMSTimeDiffToNow(oldMSTime));
}

uint32 CreatureTextMgr::SendChat(Creature* source, uint8 textGroup, WorldObject const* whisperTarget /*= nullptr*/, ChatMsg msgType /*= CHAT_MSG_ADDON*/, Language language /*= LANG_ADDON*/, CreatureTextRange range /*= TEXT_RANGE_NORMAL*/, uint32 sound /*= 0*/, Team team /*= TEAM_OTHER*/, bool gmOnly /*= false*/, Player* srcPlr /*= nullptr*/)
{
    if (!source)
        return 0;

    CreatureTextMap::const_iterator sList = mTextMap.find(source->GetEntry());
    if (sList == mTextMap.end())
    {
        TC_LOG_ERROR("sql.sql.creaturetextmgr", "CreatureTextMgr: Could not find Text for Creature %s (%s) in 'creature_text' table. Ignoring.", source->GetName().c_str(), source->GetGUID().ToString().c_str());
        return 0;
    }

    CreatureTextHolder const& textHolder = sList->second;
    CreatureTextHolder::const_iterator itr = textHolder.find(textGroup);
    if (itr == textHolder.end())
    {
        TC_LOG_ERROR("sql.sql.creaturetextmgr", "CreatureTextMgr: Could not find TextGroup %u for Creature %s (%s) in 'creature_text' table. Ignoring.", uint32(textGroup), source->GetName().c_str(), source->GetGUID().ToString().c_str());
        return 0;
    }

    CreatureTextGroup const& textGroupContainer = itr->second;  //has all texts in the group
    CreatureTextRepeatIds repeatGroup = source->GetTextRepeatGroup(textGroup);//has all textIDs from the group that were already said
    CreatureTextGroup tempGroup;//will use this to talk after sorting repeatGroup

    for (CreatureTextGroup::const_iterator giter = textGroupContainer.begin(); giter != textGroupContainer.end(); ++giter)
        if (std::find(repeatGroup.begin(), repeatGroup.end(), giter->id) == repeatGroup.end())
            tempGroup.push_back(*giter);

    if (tempGroup.empty())
    {
        source->ClearTextRepeatGroup(textGroup);
        tempGroup = textGroupContainer;
    }

    auto iter = Trinity::Containers::SelectRandomWeightedContainerElement(tempGroup, [](CreatureTextEntry const& t) -> double
    {
        return t.probability;
    });

    ChatMsg finalType = (msgType == CHAT_MSG_ADDON) ? iter->type : msgType;
    Language finalLang = (language == LANG_ADDON) ? iter->lang : language;
    uint32 finalSound = iter->sound;
    if (sound)
        finalSound = sound;
    else if (BroadcastTextEntry const* bct = sBroadcastTextStore.LookupEntry(iter->BroadcastTextId))
        if (uint32 broadcastTextSoundId = bct->SoundEntriesID[source->getGender() == GENDER_FEMALE ? 1 : 0])
            finalSound = broadcastTextSoundId;

    if (range == TEXT_RANGE_NORMAL)
        range = iter->TextRange;

    if (finalSound)
        SendSound(source, finalSound, finalType, whisperTarget, range, team, gmOnly, iter->BroadcastTextId);

    Unit* finalSource = source;
    if (srcPlr)
        finalSource = srcPlr;

    if (iter->emote)
        SendEmote(finalSource, iter->emote);

    if (srcPlr)
    {
        PlayerTextBuilder builder(source, finalSource, finalSource->getGender(), finalType, iter->groupId, iter->id, finalLang, whisperTarget);
        SendChatPacket(finalSource, builder, finalType, whisperTarget, range, team, gmOnly);
    }
    else
    {
        CreatureTextBuilder builder(finalSource, finalSource->getGender(), finalType, iter->groupId, iter->id, finalLang, whisperTarget);
        SendChatPacket(finalSource, builder, finalType, whisperTarget, range, team, gmOnly);
    }

    source->SetTextRepeatId(textGroup, iter->id);
    return iter->duration;
}

float CreatureTextMgr::GetRangeForChatType(ChatMsg msgType)
{
    float dist = sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY);
    switch (msgType)
    {
        case CHAT_MSG_MONSTER_YELL:
            dist = sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_YELL);
            break;
        case CHAT_MSG_MONSTER_EMOTE:
        case CHAT_MSG_RAID_BOSS_EMOTE:
            dist = sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE);
            break;
        default:
            break;
    }

    return dist;
}

void CreatureTextMgr::SendSound(Creature* source, uint32 sound, ChatMsg msgType, WorldObject const* whisperTarget /*= nullptr*/, CreatureTextRange range /*= TEXT_RANGE_NORMAL*/,
    Team team /*= TEAM_OTHER*/, bool gmOnly /*= false*/, uint32 keyBroadcastTextId /*= 0*/)
{
    if (!sound || !source)
        return;

    SendNonChatPacket(source, WorldPackets::Misc::PlaySound(source->GetGUID(), sound, keyBroadcastTextId).Write(), msgType, whisperTarget, range, team, gmOnly);
}

void CreatureTextMgr::SendNonChatPacket(WorldObject* source, WorldPacket const* data, ChatMsg msgType, WorldObject const* whisperTarget, CreatureTextRange range, Team team, bool gmOnly)
{
    switch (msgType)
    {
        case CHAT_MSG_MONSTER_PARTY:
        {
            if (!whisperTarget)
                return;

            if (Player const* whisperPlayer = whisperTarget->ToPlayer())
            {
                if (Group const* group = whisperPlayer->GetGroup())
                    group->BroadcastWorker([data](Player* player) { player->SendDirectMessage(data); });
            }
            return;
        }
        case CHAT_MSG_MONSTER_WHISPER:
        case CHAT_MSG_RAID_BOSS_WHISPER:
        {
            if (range == TEXT_RANGE_NORMAL) // ignores team and gmOnly
            {
                if (!whisperTarget || whisperTarget->GetTypeId() != TYPEID_PLAYER)
                    return;

                whisperTarget->ToPlayer()->SendDirectMessage(data);
                return;
            }
            break;
        }
        default:
            break;
    }

    switch (range)
    {
        case TEXT_RANGE_AREA:
        {
            uint32 areaId = source->GetAreaId();
            Map::PlayerList const& players = source->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                if (itr->GetSource()->GetAreaId() == areaId && (!team || Team(itr->GetSource()->GetTeam()) == team) && (!gmOnly || itr->GetSource()->IsGameMaster()))
                    itr->GetSource()->SendDirectMessage(data);
            return;
        }
        case TEXT_RANGE_ZONE:
        {
            uint32 zoneId = source->GetZoneId();
            Map::PlayerList const& players = source->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                if (itr->GetSource()->GetZoneId() == zoneId && (!team || Team(itr->GetSource()->GetTeam()) == team) && (!gmOnly || itr->GetSource()->IsGameMaster()))
                    itr->GetSource()->SendDirectMessage(data);
            return;
        }
        case TEXT_RANGE_MAP:
        {
            Map::PlayerList const& players = source->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                if ((!team || Team(itr->GetSource()->GetTeam()) == team) && (!gmOnly || itr->GetSource()->IsGameMaster()))
                    itr->GetSource()->SendDirectMessage(data);
            return;
        }
        case TEXT_RANGE_WORLD:
        {
            SessionMap const& smap = sWorld->GetAllSessions();
            for (SessionMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
                if (Player* player = iter->second->GetPlayer())
                    if ((!team || Team(player->GetTeam()) == team) && (!gmOnly || player->IsGameMaster()))
                        player->SendDirectMessage(data);
            return;
        }
        case TEXT_RANGE_NORMAL:
        default:
            break;
    }

    float dist = GetRangeForChatType(msgType);
    source->SendMessageToSetInRange(data, dist, true);
}

void CreatureTextMgr::SendEmote(Unit* source, uint32 emote)
{
    if (!source)
        return;

    source->HandleEmoteCommand(emote);
}

bool CreatureTextMgr::TextExist(uint32 sourceEntry, uint8 textGroup) const
{
    if (!sourceEntry)
        return false;

    CreatureTextMap::const_iterator sList = mTextMap.find(sourceEntry);
    if (sList == mTextMap.end())
    {
        TC_LOG_DEBUG("entities.unit", "CreatureTextMgr::TextExist: Could not find Text for Creature (entry %u) in 'creature_text' table.", sourceEntry);
        return false;
    }

    CreatureTextHolder const& textHolder = sList->second;
    CreatureTextHolder::const_iterator itr = textHolder.find(textGroup);
    if (itr == textHolder.end())
    {
        TC_LOG_DEBUG("entities.unit", "CreatureTextMgr::TextExist: Could not find TextGroup %u for Creature (entry %u).", uint32(textGroup), sourceEntry);
        return false;
    }

    return true;
}

std::string CreatureTextMgr::GetLocalizedChatString(uint32 entry, uint8 gender, uint8 textGroup, uint32 id, LocaleConstant locale) const
{
    CreatureTextMap::const_iterator mapitr = mTextMap.find(entry);
    if (mapitr == mTextMap.end())
        return "";

    CreatureTextHolder::const_iterator holderItr = mapitr->second.find(textGroup);
    if (holderItr == mapitr->second.end())
        return "";

    CreatureTextGroup::const_iterator groupItr = holderItr->second.begin();
    for (; groupItr != holderItr->second.end(); ++groupItr)
        if (groupItr->id == id)
            break;

    if (groupItr == holderItr->second.end())
        return "";

    if (locale >= TOTAL_LOCALES)
        locale = DEFAULT_LOCALE;

    std::string baseText = "";
    BroadcastTextEntry const* bct = sBroadcastTextStore.LookupEntry(groupItr->BroadcastTextId);

    if (bct)
        baseText = DB2Manager::GetBroadcastTextValue(bct, locale, gender);
    else
        baseText = groupItr->text;

    if (locale != DEFAULT_LOCALE && !bct)
    {
        LocaleCreatureTextMap::const_iterator locItr = mLocaleTextMap.find(CreatureTextId(entry, uint32(textGroup), id));
        if (locItr != mLocaleTextMap.end())
            ObjectMgr::GetLocaleString(locItr->second.Text, locale, baseText);
    }

    return baseText;
}
