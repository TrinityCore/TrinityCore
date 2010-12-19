/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "SQLStorage.h"
#include "CreatureTextMgr.h"
#include "ProgressBar.h"
#include "ObjectMgr.h"

void CreatureTextMgr::LoadCreatureTexts()
{
    uint32 oldMSTime = getMSTime();

    mTextMap.clear(); // for reload case
    mTextRepeatMap.clear(); //reset all currently used temp texts

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_LOAD_CRETEXT);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        barGoLink bar(1);
        bar.step();
        sLog.outString(">> Loaded 0 ceature texts. DB table `creature_texts` is empty.");
        sLog.outString();
        return;
    }

    barGoLink bar(result->GetRowCount());
    uint32 textCount = 0;
    uint32 creatureCount = 0;

    do
    {
        bar.step();
        Field* fields = result->Fetch();
        CreatureTextEntry temp;

        temp.entry          = fields[0].GetUInt32();
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
        if (temp.type >= CHAT_TYPE_ZONE_YELL)//CHAT_TYPE_ZONE_YELL and more will be used later
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
            ++creatureCount;
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

        ++textCount;
    } while (result->NextRow());

    sLog.outString(">> Loaded %u creature texts for %u creatures in %u ms", textCount, creatureCount, GetMSTimeDiffToNow(oldMSTime));
    sLog.outString();
}

uint32 CreatureTextMgr::SendChat(Creature* source, uint8 textGroup, uint64 whisperGuid, ChatType msgtype, Language language, TextRange range, uint32 sound, Team team, bool gmOnly, Player* srcPlr)
{
    if (!source)
        return 0;
    CreatureTextMap::const_iterator sList = mTextMap.find(source->GetEntry());
    if (sList == mTextMap.end())
    {
        sLog.outErrorDb("CreatureTextMgr: Could not find Text for Creature(%s) Entry %u in 'creature_text' table. Ignoring.",source->GetName(), source->GetEntry());
        return 0;
    }
    CreatureTextHolder TextHolder = (*sList).second;
    CreatureTextHolder::const_iterator itr = TextHolder.find(textGroup);
    if (itr == TextHolder.end())
    {
        sLog.outErrorDb("CreatureTextMgr: Could not find TextGroup %u for Creature(%s) GuidLow %u Entry %u. Ignoring.",uint32(textGroup), source->GetName(), source->GetGUIDLow(), source->GetEntry());
        return 0;
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
    int32 offset = -1;
    if (!isEqualChanced)
    {
        for (CreatureTextGroup::const_iterator iter = tempGroup.begin(); iter != tempGroup.end(); ++iter)
        {
            uint32 chance = uint32((*iter).probability);
            uint32 r = urand(0, 100);
            offset++;
            if (r <= chance)
                break;
        }
    }
    uint32 pos = 0;
    if (isEqualChanced || offset < 0)
        pos = urand(0,count - 1);
    else if (offset >= 0)
        pos = offset;
    CreatureTextGroup::const_iterator iter = tempGroup.begin() + pos;

    ChatType finalType = (msgtype == CHAT_TYPE_END) ? (*iter).type : msgtype;
    Language finalLang = (language == LANG_ADDON) ? (*iter).lang : language;
    uint32 finalSound = sound ? sound : (*iter).sound;

    if (finalSound)
        SendSound(source, finalSound, finalType, whisperGuid, range, team, gmOnly);

    if ((*iter).emote)
        SendEmote(srcPlr ? srcPlr->ToUnit() : source, (*iter).emote);

    SendChatString(srcPlr ? srcPlr->ToUnit() : source, (*iter).text.c_str(), finalType, finalLang, whisperGuid, range, team, gmOnly);
    if (isEqualChanced || (!isEqualChanced && totalChance == 100.0f))
        SetRepeatId(source, textGroup, (*iter).id);

    return (*iter).duration;
}

void CreatureTextMgr::SendSound(Creature* source,uint32 sound, ChatType msgtype, uint64 whisperGuid, TextRange range, Team team, bool gmOnly)
{
    if (!sound || !source)
        return;
    WorldPacket data(SMSG_PLAY_SOUND, 4);
    data << uint32(sound);
    SendChatPacket(&data, source, msgtype, whisperGuid, range, team, gmOnly);
}
void CreatureTextMgr::SendEmote(Unit* source, uint32 emote)
{
    if (!source) return;
    source->HandleEmoteCommand(emote);
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

void CreatureTextMgr::SendChatString(WorldObject* source, char const* text, ChatType msgtype, Language language, uint64 whisperGuid, TextRange range, Team team, bool gmOnly) const
{
    if (!source)
        return;

    WorldPacket data(SMSG_MESSAGECHAT, 200);
    BuildMonsterChat(&data, source, msgtype, text, language, whisperGuid);//build our packet
    SendChatPacket(&data, source, msgtype, whisperGuid, range, team, gmOnly);//send our packet
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

void CreatureTextMgr::SendChatPacket(WorldPacket *data, WorldObject* source, ChatType msgtype, uint64 whisperGuid, TextRange range, Team team, bool gmOnly) const
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
                if (range == TEXT_RANGE_NORMAL)//ignores team and gmOnly
                {
                    Player *player = sObjectMgr.GetPlayer(whisperGuid);
                    if (!player || !player->GetSession())
                        return;
                    player->GetSession()->SendPacket(data);
                    return;
                }
            }
            break;
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
                    if (itr->getSource()->GetAreaId() == areaId && (!team || Team(itr->getSource()->GetTeam()) == team) && (!gmOnly || itr->getSource()->isGameMaster()))
                    {
                        if (data->GetOpcode() == SMSG_MESSAGECHAT)//override whisperguid with actual player's guid
                            data->put<uint64>(1+4+8+4+4+(int32)(strlen(source->GetName())+1), uint64(itr->getSource()->GetGUID()));
                        (itr->getSource())->GetSession()->SendPacket(data);
                    }
            }
            return;
        case TEXT_RANGE_ZONE:
            {
                uint32 zoneId = source->GetZoneId();
                Map::PlayerList const& pList = source->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = pList.begin(); itr != pList.end(); ++itr)
                    if (itr->getSource()->GetZoneId() == zoneId && (!team || Team(itr->getSource()->GetTeam()) == team) && (!gmOnly || itr->getSource()->isGameMaster()))
                    {
                        if (data->GetOpcode() == SMSG_MESSAGECHAT)//override whisperguid with actual player's guid
                            data->put<uint64>(1+4+8+4+4+(int32)(strlen(source->GetName())+1), uint64(itr->getSource()->GetGUID()));
                        (itr->getSource())->GetSession()->SendPacket(data);
                    }
            }
            return;
        case TEXT_RANGE_MAP:
            {
                Map::PlayerList const& pList = source->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = pList.begin(); itr != pList.end(); ++itr)
                {
                    if (data->GetOpcode() == SMSG_MESSAGECHAT)//override whisperguid with actual player's guid
                        data->put<uint64>(1+4+8+4+4+(int32)(strlen(source->GetName())+1), uint64(itr->getSource()->GetGUID()));
                    if ((!team || Team(itr->getSource()->GetTeam()) == team) && (!gmOnly || itr->getSource()->isGameMaster()))
                        (itr->getSource())->GetSession()->SendPacket(data);
                }
            }
            return;
        case TEXT_RANGE_WORLD:
            {
                const SessionMap smap = sWorld.GetAllSessions();
                for (SessionMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
                {
                    if (Player* plr = (*iter).second->GetPlayer())
                    {
                        if (data->GetOpcode() == SMSG_MESSAGECHAT)//override whisperguid with actual player's guid
                            data->put<uint64>(1+4+8+4+4+(int32)(strlen(source->GetName())+1), uint64(plr->GetGUID()));
                        if (plr->GetSession()  && (!team || Team(plr->GetTeam()) == team) && (!gmOnly || plr->isGameMaster()))
                            plr->GetSession()->SendPacket(data);
                    }
                }
            }
            return;
        case TEXT_RANGE_NORMAL:
        default:
            break;
    }
    source->SendMessageToSetInRange(data, dist, true);
}

bool CreatureTextMgr::TextExist(uint32 sourceEntry, uint8 textGroup)
{
    if (!sourceEntry)
        return false;
    CreatureTextMap::const_iterator sList = mTextMap.find(sourceEntry);
    if (sList == mTextMap.end())
    {
        sLog.outDebug("CreatureTextMgr::TextExist: Could not find Text for Creature (entry %u) in 'creature_text' table.", sourceEntry);
        return false;
    }
    CreatureTextHolder TextHolder = (*sList).second;
    CreatureTextHolder::const_iterator itr = TextHolder.find(textGroup);
    if (itr == TextHolder.end())
    {
        sLog.outDebug("CreatureTextMgr::TextExist: Could not find TextGroup %u for Creature (entry %u).",uint32(textGroup), sourceEntry);
        return false;
    }
    return true;
}
