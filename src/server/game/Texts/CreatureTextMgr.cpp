/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "DatabaseEnv.h"
#include "ObjectMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "Chat.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"

class CreatureTextBuilder
{
    public:
        CreatureTextBuilder(WorldObject* obj, ChatMsg msgtype, uint8 textGroup, uint32 id, uint32 language, WorldObject const* target)
            : _source(obj), _msgType(msgtype), _textGroup(textGroup), _textId(id), _language(language), _target(target)
        {
        }

        size_t operator()(WorldPacket* data, LocaleConstant locale) const
        {
            std::string const& text = sCreatureTextMgr->GetLocalizedChatString(_source->GetEntry(), _textGroup, _textId, locale);

            return ChatHandler::BuildChatPacket(*data, _msgType, Language(_language), _source, _target, text, 0, "", locale);
        }

        WorldObject* _source;
        ChatMsg _msgType;
        uint8 _textGroup;
        uint32 _textId;
        uint32 _language;
        WorldObject const* _target;
};

class PlayerTextBuilder
{
    public:
        PlayerTextBuilder(WorldObject* obj, WorldObject* speaker, ChatMsg msgtype, uint8 textGroup, uint32 id, uint32 language, WorldObject const* target)
            : _source(obj), _talker(speaker), _msgType(msgtype), _textGroup(textGroup), _textId(id), _language(language), _target(target)
        {
        }

        size_t operator()(WorldPacket* data, LocaleConstant locale) const
        {
            std::string const& text = sCreatureTextMgr->GetLocalizedChatString(_source->GetEntry(), _textGroup, _textId, locale);

            return ChatHandler::BuildChatPacket(*data, _msgType, Language(_language), _talker, _target, text, 0, "", locale);
        }

        WorldObject* _source;
        WorldObject* _talker;
        ChatMsg _msgType;
        uint8 _textGroup;
        uint32 _textId;
        uint32 _language;
        WorldObject const* _target;
};

void CreatureTextMgr::LoadCreatureTexts()
{
    uint32 oldMSTime = getMSTime();

    mTextMap.clear(); // for reload case
    mTextRepeatMap.clear(); //reset all currently used temp texts

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_TEXT);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 ceature texts. DB table `creature_texts` is empty.");

        return;
    }

    uint32 textCount = 0;
    uint32 creatureCount = 0;

    do
    {
        Field* fields = result->Fetch();
        CreatureTextEntry temp;

        temp.entry          = fields[0].GetUInt32();
        temp.group          = fields[1].GetUInt8();
        temp.id             = fields[2].GetUInt8();
        temp.text           = fields[3].GetString();
        temp.type           = ChatMsg(fields[4].GetUInt8());
        temp.lang           = Language(fields[5].GetUInt8());
        temp.probability    = fields[6].GetFloat();
        temp.emote          = Emote(fields[7].GetUInt32());
        temp.duration       = fields[8].GetUInt32();
        temp.sound          = fields[9].GetUInt32();

        if (temp.sound)
        {
            if (!sSoundEntriesStore.LookupEntry(temp.sound)){
                TC_LOG_ERROR("sql.sql", "CreatureTextMgr:  Entry %u, Group %u in table `creature_texts` has Sound %u but sound does not exist.", temp.entry, temp.group, temp.sound);
                temp.sound = 0;
            }
        }
        if (!GetLanguageDescByID(temp.lang))
        {
            TC_LOG_ERROR("sql.sql", "CreatureTextMgr:  Entry %u, Group %u in table `creature_texts` using Language %u but Language does not exist.", temp.entry, temp.group, uint32(temp.lang));
            temp.lang = LANG_UNIVERSAL;
        }
        if (temp.type >= MAX_CHAT_MSG_TYPE)
        {
            TC_LOG_ERROR("sql.sql", "CreatureTextMgr:  Entry %u, Group %u in table `creature_texts` has Type %u but this Chat Type does not exist.", temp.entry, temp.group, uint32(temp.type));
            temp.type = CHAT_MSG_SAY;
        }
        if (temp.emote)
        {
            if (!sEmotesStore.LookupEntry(temp.emote))
            {
                TC_LOG_ERROR("sql.sql", "CreatureTextMgr:  Entry %u, Group %u in table `creature_texts` has Emote %u but emote does not exist.", temp.entry, temp.group, uint32(temp.emote));
                temp.emote = EMOTE_ONESHOT_NONE;
            }
        }
        //entry not yet added, add empty TextHolder (list of groups)
        if (mTextMap.find(temp.entry) == mTextMap.end())
            ++creatureCount;

        //add the text into our entry's group
        mTextMap[temp.entry][temp.group].push_back(temp);

        ++textCount;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u creature texts for %u creatures in %u ms", textCount, creatureCount, GetMSTimeDiffToNow(oldMSTime));

}

void CreatureTextMgr::LoadCreatureTextLocales()
{
    uint32 oldMSTime = getMSTime();

    mLocaleTextMap.clear(); // for reload case

    QueryResult result = WorldDatabase.Query("SELECT entry, groupid, id, text_loc1, text_loc2, text_loc3, text_loc4, text_loc5, text_loc6, text_loc7, text_loc8 FROM locales_creature_text");

    if (!result)
        return;

    uint32 textCount = 0;

    do
    {
        Field* fields = result->Fetch();
        CreatureTextLocale& loc = mLocaleTextMap[CreatureTextId(fields[0].GetUInt32(), uint32(fields[1].GetUInt8()), uint32(fields[2].GetUInt8()))];
        for (uint8 i = 1; i < TOTAL_LOCALES; ++i)
        {
            LocaleConstant locale = LocaleConstant(i);
            ObjectMgr::AddLocaleString(fields[3 + i - 1].GetString(), locale, loc.Text);
        }

        ++textCount;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u creature localized texts in %u ms", textCount, GetMSTimeDiffToNow(oldMSTime));

}

uint32 CreatureTextMgr::SendChat(Creature* source, uint8 textGroup, WorldObject const* whisperTarget /*= NULL*/, ChatMsg msgType /*= CHAT_MSG_ADDON*/, Language language /*= LANG_ADDON*/, CreatureTextRange range /*= TEXT_RANGE_NORMAL*/, uint32 sound /*= 0*/, Team team /*= TEAM_OTHER*/, bool gmOnly /*= false*/, Player* srcPlr /*= NULL*/)
{
    if (!source)
        return 0;

    CreatureTextMap::const_iterator sList = mTextMap.find(source->GetEntry());
    if (sList == mTextMap.end())
    {
        TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Could not find Text for Creature %s (Entry %u, GUID %u) in 'creature_text' table. Ignoring.", source->GetName().c_str(), source->GetEntry(), source->GetGUIDLow());
        return 0;
    }

    CreatureTextHolder const& textHolder = sList->second;
    CreatureTextHolder::const_iterator itr = textHolder.find(textGroup);
    if (itr == textHolder.end())
    {
        TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Could not find TextGroup %u for Creature %s (Entry %u, GUID %u) in 'creature_text' table. Ignoring.", uint32(textGroup), source->GetName().c_str(), source->GetEntry(), source->GetGUIDLow());
        return 0;
    }

    CreatureTextGroup const& textGroupContainer = itr->second;  //has all texts in the group
    CreatureTextRepeatIds repeatGroup = GetRepeatGroup(source, textGroup);//has all textIDs from the group that were already said
    CreatureTextGroup tempGroup;//will use this to talk after sorting repeatGroup

    for (CreatureTextGroup::const_iterator giter = textGroupContainer.begin(); giter != textGroupContainer.end(); ++giter)
        if (std::find(repeatGroup.begin(), repeatGroup.end(), giter->id) == repeatGroup.end())
            tempGroup.push_back(*giter);

    if (tempGroup.empty())
    {
        CreatureTextRepeatMap::iterator mapItr = mTextRepeatMap.find(source->GetGUID());
        if (mapItr != mTextRepeatMap.end())
        {
            CreatureTextRepeatGroup::iterator groupItr = mapItr->second.find(textGroup);
            groupItr->second.clear();
        }

        tempGroup = textGroupContainer;
    }

    uint8 count = 0;
    float lastChance = -1;
    bool isEqualChanced = true;

    float totalChance = 0;

    for (CreatureTextGroup::const_iterator iter = tempGroup.begin(); iter != tempGroup.end(); ++iter)
    {
        if (lastChance >= 0 && lastChance != iter->probability)
            isEqualChanced = false;

        lastChance = iter->probability;
        totalChance += iter->probability;
        ++count;
    }

    int32 offset = -1;
    if (!isEqualChanced)
    {
        for (CreatureTextGroup::const_iterator iter = tempGroup.begin(); iter != tempGroup.end(); ++iter)
        {
            uint32 chance = uint32(iter->probability);
            uint32 r = urand(0, 100);
            ++offset;
            if (r <= chance)
                break;
        }
    }

    uint32 pos = 0;
    if (isEqualChanced || offset < 0)
        pos = urand(0, count - 1);
    else if (offset >= 0)
        pos = offset;

    CreatureTextGroup::const_iterator iter = tempGroup.begin() + pos;

    ChatMsg finalType = (msgType == CHAT_MSG_ADDON) ? iter->type : msgType;
    Language finalLang = (language == LANG_ADDON) ? iter->lang : language;
    uint32 finalSound = sound ? sound : iter->sound;

    if (finalSound)
        SendSound(source, finalSound, finalType, whisperTarget, range, team, gmOnly);

    Unit* finalSource = source;
    if (srcPlr)
        finalSource = srcPlr;

    if (iter->emote)
        SendEmote(finalSource, iter->emote);

    if (srcPlr)
    {
        PlayerTextBuilder builder(source, finalSource, finalType, iter->group, iter->id, finalLang, whisperTarget);
        SendChatPacket(finalSource, builder, finalType, whisperTarget, range, team, gmOnly);
    }
    else
    {
        CreatureTextBuilder builder(finalSource, finalType, iter->group, iter->id, finalLang, whisperTarget);
        SendChatPacket(finalSource, builder, finalType, whisperTarget, range, team, gmOnly);
    }
    if (isEqualChanced || (!isEqualChanced && totalChance == 100.0f))
        SetRepeatId(source, textGroup, iter->id);

    return iter->duration;
}

float CreatureTextMgr::GetRangeForChatType(ChatMsg msgType) const
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

void CreatureTextMgr::SendSound(Creature* source, uint32 sound, ChatMsg msgType, WorldObject const* whisperTarget, CreatureTextRange range, Team team, bool gmOnly)
{
    if (!sound || !source)
        return;

    WorldPacket data(SMSG_PLAY_SOUND, 4);
    data << uint32(sound);
    SendNonChatPacket(source, &data, msgType, whisperTarget, range, team, gmOnly);
}

void CreatureTextMgr::SendNonChatPacket(WorldObject* source, WorldPacket* data, ChatMsg msgType, WorldObject const* whisperTarget, CreatureTextRange range, Team team, bool gmOnly) const
{
    float dist = GetRangeForChatType(msgType);

    switch (msgType)
    {
        case CHAT_MSG_MONSTER_WHISPER:
        case CHAT_MSG_RAID_BOSS_WHISPER:
        {
            if (range == TEXT_RANGE_NORMAL)//ignores team and gmOnly
            {
                if (!whisperTarget || whisperTarget->GetTypeId() != TYPEID_PLAYER)
                    return;

                whisperTarget->ToPlayer()->GetSession()->SendPacket(data);
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
                    itr->GetSource()->GetSession()->SendPacket(data);
            return;
        }
        case TEXT_RANGE_ZONE:
        {
            uint32 zoneId = source->GetZoneId();
            Map::PlayerList const& players = source->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                if (itr->GetSource()->GetZoneId() == zoneId && (!team || Team(itr->GetSource()->GetTeam()) == team) && (!gmOnly || itr->GetSource()->IsGameMaster()))
                    itr->GetSource()->GetSession()->SendPacket(data);
            return;
        }
        case TEXT_RANGE_MAP:
        {
            Map::PlayerList const& players = source->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                if ((!team || Team(itr->GetSource()->GetTeam()) == team) && (!gmOnly || itr->GetSource()->IsGameMaster()))
                    itr->GetSource()->GetSession()->SendPacket(data);
            return;
        }
        case TEXT_RANGE_WORLD:
        {
            SessionMap const& smap = sWorld->GetAllSessions();
            for (SessionMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
                if (Player* player = iter->second->GetPlayer())
                    if (player->GetSession()  && (!team || Team(player->GetTeam()) == team) && (!gmOnly || player->IsGameMaster()))
                        player->GetSession()->SendPacket(data);
            return;
        }
        case TEXT_RANGE_NORMAL:
        default:
            break;
    }

    source->SendMessageToSetInRange(data, dist, true);
}

void CreatureTextMgr::SendEmote(Unit* source, uint32 emote)
{
    if (!source)
        return;

    source->HandleEmoteCommand(emote);
}

void CreatureTextMgr::SetRepeatId(Creature* source, uint8 textGroup, uint8 id)
{
    if (!source)
        return;

    CreatureTextRepeatIds& repeats = mTextRepeatMap[source->GetGUID()][textGroup];
    if (std::find(repeats.begin(), repeats.end(), id) == repeats.end())
        repeats.push_back(id);
    else
        TC_LOG_ERROR("sql.sql", "CreatureTextMgr: TextGroup %u for Creature(%s) GuidLow %u Entry %u, id %u already added", uint32(textGroup), source->GetName().c_str(), source->GetGUIDLow(), source->GetEntry(), uint32(id));
}

CreatureTextRepeatIds CreatureTextMgr::GetRepeatGroup(Creature* source, uint8 textGroup)
{
    ASSERT(source);//should never happen
    CreatureTextRepeatIds ids;

    CreatureTextRepeatMap::const_iterator mapItr = mTextRepeatMap.find(source->GetGUID());
    if (mapItr != mTextRepeatMap.end())
    {
        CreatureTextRepeatGroup::const_iterator groupItr = (*mapItr).second.find(textGroup);
        if (groupItr != mapItr->second.end())
            ids = groupItr->second;
    }
    return ids;
}

bool CreatureTextMgr::TextExist(uint32 sourceEntry, uint8 textGroup)
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

std::string CreatureTextMgr::GetLocalizedChatString(uint32 entry, uint8 textGroup, uint32 id, LocaleConstant locale) const
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

    std::string baseText = groupItr->text;
    if (locale == DEFAULT_LOCALE)
        return baseText;

    if (locale > MAX_LOCALES)
        return baseText;

    LocaleCreatureTextMap::const_iterator locItr = mLocaleTextMap.find(CreatureTextId(entry, uint32(textGroup), id));
    if (locItr == mLocaleTextMap.end())
        return baseText;

    ObjectMgr::GetLocaleString(locItr->second.Text, locale, baseText);

    return baseText;
}
