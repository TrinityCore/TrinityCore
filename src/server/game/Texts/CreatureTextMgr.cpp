/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "DatabaseEnv.h"
#include "SQLStorage.h"
#include "CreatureTextMgr.h"
#include "ProgressBar.h"
#include "ObjectMgr.h"

void CreatureTextMgr::LoadCreatureTexts()
{
    mTextMap.clear(); // for reload case
    mTextRepeatMap.clear(); //reset all currently used temp texts

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_LOAD_CRETEXT);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        barGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Loaded 0 Creature Texts. DB table `creature_texts` is empty.");
        return;
    }

    barGoLink bar(result->GetRowCount());
    uint32 TextCount = 0;
    uint32 CreatureCount = 0;

    do
    {
        bar.step();
        Field* fields = result->Fetch();
        CreatureTextEntry temp;

        temp.entry        = fields[0].GetUInt32();
        temp.group          = fields[1].GetUInt8();
        temp.id             = fields[2].GetUInt8();
        temp.text           = fields[3].GetString();
        temp.type           = ChatType(fields[4].GetUInt8());
        temp.lang           = Language(fields[5].GetUInt8());
        temp.probability    = fields[6].GetFloat();
        temp.emote          = Emote(fields[7].GetUInt32());
        temp.duration       = fields[8].GetUInt32();
        temp.sound          = fields[9].GetUInt32();

        if (temp.sound)
        {
            if (!sSoundEntriesStore.LookupEntry(temp.sound)){
                sLog.outErrorDb("CreatureTextMgr:  Entry %u, Group %u in table `creature_texts` has Sound %u but sound does not exist.", temp.entry, temp.group, temp.sound);
                temp.sound = 0;
            }
        }
        if (!GetLanguageDescByID(temp.lang))
        {
            sLog.outErrorDb("CreatureTextMgr:  Entry %u, Group %u in table `creature_texts` using Language %u but Language does not exist.", temp.entry, temp.group, uint32(temp.lang));
            temp.lang = LANG_UNIVERSAL;
        }
        if (temp.type > CHAT_TYPE_ZONE_YELL)
        {
            sLog.outErrorDb("CreatureTextMgr:  Entry %u, Group %u in table `creature_texts` has Type %u but this Chat Type does not exist.", temp.entry, temp.group, uint32(temp.type));
            temp.type = CHAT_TYPE_SAY;
        }
        if (temp.emote)
        {
            if (!sEmotesStore.LookupEntry(temp.emote))
            {
                sLog.outErrorDb("CreatureTextMgr:  Entry %u, Group %u in table `creature_texts` has Emote %u but emote does not exist.", temp.entry, temp.group, uint32(temp.emote));
                temp.emote = EMOTE_ONESHOT_NONE;
            }
        }
        //entry not yet added, add empty TextHolder (list of groups)
        if (mTextMap.find(temp.entry) == mTextMap.end())
        {
            ++CreatureCount;
            CreatureTextHolder TextHolder;
            mTextMap[temp.entry] = TextHolder;
        }
        //group not yet added, add empty TextGroup (list of texts)
        if (mTextMap[temp.entry].find(temp.group) == mTextMap[temp.entry].end())
        {
            CreatureTextGroup TextGroup;
            mTextMap[temp.entry][temp.group] = TextGroup;
        }
        //add the text into our entry's group
        mTextMap[temp.entry][temp.group].push_back(temp);

        ++TextCount;
    } while (result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded %u Creature Texts for %u Creatures.", TextCount, CreatureCount);
}

void CreatureTextMgr::SendChat(Creature* source, uint8 textGroup, uint64 whisperGuid, ChatType msgtype, Language language, TextRange range)
{
    if (!source)
        return;
    CreatureTextMap::const_iterator sList = mTextMap.find(source->GetEntry());
    if (sList == mTextMap.end())
    {
        sLog.outErrorDb("CreatureTextMgr: Could not find Text for Creature(%s) Entry %u in 'creature_text' table. Ignoring.",source->GetName(), source->GetEntry());
        return;
    }
    CreatureTextHolder TextHolder = (*sList).second;
    CreatureTextHolder::const_iterator itr = TextHolder.find(textGroup);
    if (itr == TextHolder.end())
    {
        sLog.outErrorDb("CreatureTextMgr: Could not find TextGroup %u for Creature(%s) GuidLow %u Entry %u. Ignoring.",uint32(textGroup), source->GetName(), source->GetGUIDLow(), source->GetEntry());
        return;
    }
    CreatureTextGroup TextGroup = (*itr).second;//has all texts in the group
    CreatureTextRepeatIds repeatGroup = GetRepeatGroup(source,textGroup);//has all textIDs from the group that were already said
    CreatureTextGroup tempGroup;//will use this to talk after sorting repeatGroup

    for (CreatureTextGroup::const_iterator giter = TextGroup.begin(); giter != TextGroup.end(); ++giter)
    {
        if (std::find(repeatGroup.begin(), repeatGroup.end(), (*giter).id) == repeatGroup.end())
            tempGroup.push_back((*giter));
    }
    if (tempGroup.empty())
    {
        //mTextRepeatMap[source->GetGUID()][textGroup].clear();
        CreatureTextRepeatMap::iterator mapItr = mTextRepeatMap.find(source->GetGUID());
        if (mapItr != mTextRepeatMap.end())
        {
            CreatureTextRepeatGroup::iterator groupItr = (*mapItr).second.find(textGroup);
            (*groupItr).second.clear();
        }
        tempGroup = TextGroup;
    }
    uint8 count = 0;
    float lastChance = -1;
    bool isEqualChanced = true;

    float totalChance = 0;

    for (CreatureTextGroup::const_iterator iter = tempGroup.begin(); iter != tempGroup.end(); ++iter)
    {
        if (lastChance >= 0 && lastChance != (*iter).probability)
            isEqualChanced = false;

        lastChance = (*iter).probability;
        totalChance += (*iter).probability;
        count++;
    }
    if (isEqualChanced)
    {
        uint32 pos = urand(0,count - 1);
        CreatureTextGroup::const_iterator iter = tempGroup.begin() + pos;
        SendChatString(source, (*iter).text.c_str(), (*iter).type, (*iter).lang, whisperGuid);
        SetRepeatId(source, textGroup, (*iter).id);
    }else
    {
        for (CreatureTextGroup::const_iterator iter = tempGroup.begin(); iter != tempGroup.end(); ++iter)
        {
            uint32 chance = uint32((*iter).probability);
            uint32 r = urand(0, 100);
            if (r <= chance)
            {                
                SendChatString(source, (*iter).text.c_str(), (*iter).type, (*iter).lang, whisperGuid);
                if (totalChance == 100.0f)// only if total chances are 100 do not repeat
                    SetRepeatId(source, textGroup, (*iter).id);
                return;
            }
        }
        uint32 pos = urand(0,count - 1);
        CreatureTextGroup::const_iterator iter = tempGroup.begin() + pos;
        SendChatString(source, (*iter).text.c_str(), (*iter).type, (*iter).lang, whisperGuid);
        SetRepeatId(source, textGroup, (*iter).id);
    }
}

void CreatureTextMgr::SetRepeatId(Creature* source, uint8 textGroup, uint8 id)
{
    if (!source)
        return;

    if (mTextRepeatMap.find(source->GetGUID()) == mTextRepeatMap.end())
    {
        CreatureTextRepeatGroup TextGroup;
        mTextRepeatMap[source->GetGUID()] = TextGroup;
    }
    if (mTextRepeatMap[source->GetGUID()].find(textGroup) == mTextRepeatMap[source->GetGUID()].end())
    {
        CreatureTextRepeatIds ids;
        mTextRepeatMap[source->GetGUID()][textGroup] = ids;
    }

    if (std::find(mTextRepeatMap[source->GetGUID()][textGroup].begin(), mTextRepeatMap[source->GetGUID()][textGroup].end(), id) == mTextRepeatMap[source->GetGUID()][textGroup].end())
    {
        mTextRepeatMap[source->GetGUID()][textGroup].push_back(id);
    }
    else
        sLog.outErrorDb("CreatureTextMgr: TextGroup %u for Creature(%s) GuidLow %u Entry %u, id %u already added",uint32(textGroup), source->GetName(), source->GetGUIDLow(), source->GetEntry(), uint32(id));
}

CreatureTextRepeatIds CreatureTextMgr::GetRepeatGroup(Creature* source, uint8 textGroup)
{
    ASSERT(source);//should never happen
    CreatureTextRepeatIds ids;

    CreatureTextRepeatMap::const_iterator mapItr = mTextRepeatMap.find(source->GetGUID());
    if (mapItr != mTextRepeatMap.end())
    {
        CreatureTextRepeatGroup::const_iterator groupItr = (*mapItr).second.find(textGroup);
        if (groupItr != (*mapItr).second.end())
        {
            ids = (*groupItr).second;
        }
    }
    return ids;
}

void CreatureTextMgr::SendChatString(WorldObject* source, char const* text, ChatType msgtype, Language language, uint64 whisperGuid, TextRange range) const
{
    if (!source)
        return;

    WorldPacket data(SMSG_MESSAGECHAT, 200);
    BuildMonsterChat(&data, source, msgtype, text, language, whisperGuid);//build our packet
    SendChatPacket(&data, source, msgtype, whisperGuid, range);//send our packet
}

void CreatureTextMgr::BuildMonsterChat(WorldPacket *data, WorldObject* source, ChatType msgtype, char const* text, Language language, uint64 whisperGuid) const
{
    if (!source)
        return;

    ChatMsg sendType = CHAT_MSG_MONSTER_SAY;
    switch (msgtype)
    {
        case CHAT_TYPE_YELL:
            sendType = CHAT_MSG_MONSTER_YELL;
            break;
        case CHAT_TYPE_TEXT_EMOTE:
            sendType = CHAT_MSG_MONSTER_EMOTE;
            break;
        case CHAT_TYPE_BOSS_EMOTE:
            sendType = CHAT_MSG_RAID_BOSS_EMOTE;
            break;
        case CHAT_TYPE_WHISPER:
            if (whisperGuid)
                sendType = CHAT_MSG_MONSTER_WHISPER;
            else
            {
                sLog.outError("CreatureTextMgr: WorldObject(%s) TypeId %u GuidLow %u sent CHAT_TYPE_WHISPER with targetGuid 0. Ignoring.",source->GetName(), uint32(source->GetTypeId()), source->GetGUIDLow());
                return;
            }
            break;
        case CHAT_TYPE_BOSS_WHISPER:
            if (whisperGuid)
                sendType = CHAT_MSG_RAID_BOSS_WHISPER;
            else
            {
                sLog.outError("CreatureTextMgr: WorldObject(%s) TypeId %u GuidLow %u sent CHAT_TYPE_BOSS_WHISPER with targetGuid 0. Ignoring.",source->GetName(), uint32(source->GetTypeId()), source->GetGUIDLow());
                return;
            }
            break;
        case CHAT_TYPE_SAY://default type
        default:
            break;
    }
    *data << (uint8)sendType;
    *data << (uint32)language;
    *data << (uint64)source->GetGUID();
    *data << (uint32)0;                                     // 2.1.0
    *data << (uint32)(strlen(source->GetName())+1);
    *data << source->GetName();
    *data << (uint64)whisperGuid;                           // Unit Target
    if (whisperGuid && !IS_PLAYER_GUID(whisperGuid))        //can only whisper players 
    {
        sLog.outError("CreatureTextMgr: WorldObject(%s) TypeId %u GuidLow %u sent WHISPER msg to Non-Player target. Ignoring.",source->GetName(), uint32(source->GetTypeId()), source->GetGUIDLow());
        return;
        //*data << (uint32)1;                                 // target name length
        //*data << (uint8)0;                                  // target name
    }
    *data << (uint32)(strlen(text)+1);
    *data << text;
    *data << (uint8)0;                                      // ChatTag
}

void CreatureTextMgr::SendChatPacket(WorldPacket *data, WorldObject* source, ChatType msgtype, uint64 whisperGuid, TextRange range) const
{
    if (!source)
        return;

    float dist = sWorld.getFloatConfig(CONFIG_LISTEN_RANGE_SAY);
    
    switch (msgtype)
    {
        case CHAT_TYPE_YELL:
            dist = sWorld.getFloatConfig(CONFIG_LISTEN_RANGE_YELL);
            break;
        case CHAT_TYPE_BOSS_EMOTE:
        case CHAT_TYPE_TEXT_EMOTE:
            dist = sWorld.getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE);
            break;
        case CHAT_TYPE_WHISPER:
        case CHAT_TYPE_BOSS_WHISPER:
            {
                    if (range != TEXT_RANGE_NORMAL)
                {
                    sLog.outError("CreatureTextMgr: WorldObject(%s) TypeId %u GuidLow %u sent WHISPER msg with TextRange set. Ignoring.",source->GetName(), uint32(source->GetTypeId()), source->GetGUIDLow());
                    return;
                }
                Player *player = sObjectMgr.GetPlayer(whisperGuid);
                if (!player || !player->GetSession())
                    return;
                player->GetSession()->SendPacket(data);
            }
            return;
        case CHAT_TYPE_SAY://default dist
        default:
            break;
    }

    switch (range)
    {
        case TEXT_RANGE_AREA:
            {
                uint32 areaId = source->GetAreaId();
                Map::PlayerList const& pList = source->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = pList.begin(); itr != pList.end(); ++itr)
                    if (itr->getSource()->GetAreaId() == areaId)
                        (itr->getSource())->GetSession()->SendPacket(data);
            }
            return;
        case TEXT_RANGE_ZONE:
            {
                uint32 zoneId = source->GetZoneId();
                Map::PlayerList const& pList = source->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = pList.begin(); itr != pList.end(); ++itr)
                    if (itr->getSource()->GetZoneId() == zoneId)
                        (itr->getSource())->GetSession()->SendPacket(data);
            }
            return;
        case TEXT_RANGE_MAP:
            {
                Map::PlayerList const& pList = source->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = pList.begin(); itr != pList.end(); ++itr)
                        (itr->getSource())->GetSession()->SendPacket(data);
            }
            return;
        case TEXT_RANGE_WORLD:
            {
                sWorld.SendGlobalMessage(data);
            }
            return;
        case TEXT_RANGE_NORMAL:
        default:
            break;
    }
    source->SendMessageToSetInRange(data, dist, true);
}
