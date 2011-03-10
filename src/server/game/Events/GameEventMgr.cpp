/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "GameEventMgr.h"
#include "World.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"
#include "PoolMgr.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "GossipDef.h"
#include "Player.h"
#include "BattlegroundMgr.h"

bool GameEventMgr::CheckOneGameEvent(uint16 entry) const
{
    switch(mGameEvent[entry].state)
    {
        default:
        case GAMEEVENT_NORMAL:
        {
            time_t currenttime = time(NULL);
            // Get the event information
            return mGameEvent[entry].start < currenttime
                && currenttime < mGameEvent[entry].end
                && (currenttime - mGameEvent[entry].start) % (mGameEvent[entry].occurence * MINUTE) < mGameEvent[entry].length * MINUTE;
        }
        // if the state is conditions or nextphase, then the event should be active
        case GAMEEVENT_WORLD_CONDITIONS:
        case GAMEEVENT_WORLD_NEXTPHASE:
            return true;
        // finished world events are inactive
        case GAMEEVENT_WORLD_FINISHED:
        case GAMEEVENT_INTERNAL:
            return false;
        // if inactive world event, check the prerequisite events
        case GAMEEVENT_WORLD_INACTIVE:
        {
            time_t currenttime = time(NULL);
            for (std::set<uint16>::const_iterator itr = mGameEvent[entry].prerequisite_events.begin(); itr != mGameEvent[entry].prerequisite_events.end(); ++itr)
            {
                if ((mGameEvent[*itr].state != GAMEEVENT_WORLD_NEXTPHASE && mGameEvent[*itr].state != GAMEEVENT_WORLD_FINISHED) ||   // if prereq not in nextphase or finished state, then can't start this one
                    mGameEvent[*itr].nextstart > currenttime)               // if not in nextphase state for long enough, can't start this one
                    return false;
            }
            // all prerequisite events are met
            // but if there are no prerequisites, this can be only activated through gm command
            return !(mGameEvent[entry].prerequisite_events.empty());
        }
    }
}

uint32 GameEventMgr::NextCheck(uint16 entry) const
{
    time_t currenttime = time(NULL);

    // for NEXTPHASE state world events, return the delay to start the next event, so the followup event will be checked correctly
    if ((mGameEvent[entry].state == GAMEEVENT_WORLD_NEXTPHASE || mGameEvent[entry].state == GAMEEVENT_WORLD_FINISHED) && mGameEvent[entry].nextstart >= currenttime)
        return uint32(mGameEvent[entry].nextstart - currenttime);

    // for CONDITIONS state world events, return the length of the wait period, so if the conditions are met, this check will be called again to set the timer as NEXTPHASE event
    if (mGameEvent[entry].state == GAMEEVENT_WORLD_CONDITIONS)
    {
        if (mGameEvent[entry].length)
            return mGameEvent[entry].length * 60 ;
        else
            return max_ge_check_delay;
    }

    // outdated event: we return max
    if (currenttime > mGameEvent[entry].end)
        return max_ge_check_delay;

    // never started event, we return delay before start
    if (mGameEvent[entry].start > currenttime)
        return uint32(mGameEvent[entry].start - currenttime);

    uint32 delay;
    // in event, we return the end of it
    if ((((currenttime - mGameEvent[entry].start) % (mGameEvent[entry].occurence * 60)) < (mGameEvent[entry].length * 60)))
        // we return the delay before it ends
        delay = (mGameEvent[entry].length * MINUTE) - ((currenttime - mGameEvent[entry].start) % (mGameEvent[entry].occurence * MINUTE));
    else                                                    // not in window, we return the delay before next start
        delay = (mGameEvent[entry].occurence * MINUTE) - ((currenttime - mGameEvent[entry].start) % (mGameEvent[entry].occurence * MINUTE));
    // In case the end is before next check
    if (mGameEvent[entry].end  < time_t(currenttime + delay))
        return uint32(mGameEvent[entry].end - currenttime);
    else
        return delay;
}

void GameEventMgr::StartInternalEvent(uint16 event_id)
{
    if (event_id < 1 || event_id >= mGameEvent.size())
        return;

    if (!mGameEvent[event_id].isValid())
        return;

    if (m_ActiveEvents.find(event_id) != m_ActiveEvents.end())
        return;

    StartEvent(event_id);
}

bool GameEventMgr::StartEvent(uint16 event_id, bool overwrite)
{
    if (mGameEvent[event_id].state == GAMEEVENT_NORMAL
        || mGameEvent[event_id].state == GAMEEVENT_INTERNAL)
    {
        AddActiveEvent(event_id);
        ApplyNewEvent(event_id);
        if (overwrite)
        {
            mGameEvent[event_id].start = time(NULL);
            if (mGameEvent[event_id].end <= mGameEvent[event_id].start)
                mGameEvent[event_id].end = mGameEvent[event_id].start+mGameEvent[event_id].length;
        }
        return false;
    }
    else
    {
        if (mGameEvent[event_id].state == GAMEEVENT_WORLD_INACTIVE)
            // set to conditions phase
            mGameEvent[event_id].state = GAMEEVENT_WORLD_CONDITIONS;

        // add to active events
        AddActiveEvent(event_id);
        // add spawns
        ApplyNewEvent(event_id);

        // check if can go to next state
        bool conditions_met = CheckOneGameEventConditions(event_id);
        // save to db
        SaveWorldEventStateToDB(event_id);
        // force game event update to set the update timer if conditions were met from a command
        // this update is needed to possibly start events dependent on the started one
        // or to scedule another update where the next event will be started
        if (overwrite && conditions_met)
            sWorld->ForceGameEventUpdate();

        return conditions_met;
    }
}

void GameEventMgr::StopEvent(uint16 event_id, bool overwrite)
{
    bool serverwide_evt = mGameEvent[event_id].state != GAMEEVENT_NORMAL && mGameEvent[event_id].state != GAMEEVENT_INTERNAL;

    RemoveActiveEvent(event_id);
    UnApplyEvent(event_id);

    if (overwrite && !serverwide_evt)
    {
        mGameEvent[event_id].start = time(NULL) - mGameEvent[event_id].length * MINUTE;
        if (mGameEvent[event_id].end <= mGameEvent[event_id].start)
            mGameEvent[event_id].end = mGameEvent[event_id].start+mGameEvent[event_id].length;
    }
    else if (serverwide_evt)
    {
        // if finished world event, then only gm command can stop it
        if (overwrite || mGameEvent[event_id].state != GAMEEVENT_WORLD_FINISHED)
        {
            // reset conditions
            mGameEvent[event_id].nextstart = 0;
            mGameEvent[event_id].state = GAMEEVENT_WORLD_INACTIVE;
            std::map<uint32 /*condition id*/, GameEventFinishCondition>::iterator itr;
            for (itr = mGameEvent[event_id].conditions.begin(); itr != mGameEvent[event_id].conditions.end(); ++itr)
                itr->second.done = 0;
            SQLTransaction trans = CharacterDatabase.BeginTransaction();
            trans->PAppend("DELETE FROM game_event_save WHERE event_id = '%u'",event_id);
            trans->PAppend("DELETE FROM game_event_condition_save WHERE event_id = '%u'",event_id);
            CharacterDatabase.CommitTransaction(trans);
        }
    }
}

void GameEventMgr::LoadFromDB()
{
    {
        uint32 oldMSTime = getMSTime();

        QueryResult result = WorldDatabase.Query("SELECT entry,UNIX_TIMESTAMP(start_time),UNIX_TIMESTAMP(end_time),occurence,length,holiday,description,world_event FROM game_event");
        if (!result)
        {
            mGameEvent.clear();
            sLog->outErrorDb(">> Loaded 0 game events. DB table `game_event` is empty.");
            sLog->outString();
            return;
        }

        uint32 count = 0;
        do
        {
            Field *fields = result->Fetch();

            uint16 event_id = fields[0].GetUInt16();
            if (event_id == 0)
            {
                sLog->outErrorDb("`game_event` game event id (%i) is reserved and can't be used.",event_id);
                continue;
            }

            GameEventData& pGameEvent = mGameEvent[event_id];
            uint64 starttime        = fields[1].GetUInt64();
            pGameEvent.start        = time_t(starttime);
            uint64 endtime          = fields[2].GetUInt64();
            pGameEvent.end          = time_t(endtime);
            pGameEvent.occurence    = fields[3].GetUInt32();
            pGameEvent.length       = fields[4].GetUInt32();
            pGameEvent.holiday_id   = HolidayIds(fields[5].GetUInt32());

            pGameEvent.state        = (GameEventState)(fields[7].GetUInt8());
            pGameEvent.nextstart    = 0;

            if (pGameEvent.length == 0 && pGameEvent.state == GAMEEVENT_NORMAL)                            // length>0 is validity check
            {
                sLog->outErrorDb("`game_event` game event id (%i) isn't a world event and has length = 0, thus it can't be used.",event_id);
                continue;
            }

            if (pGameEvent.holiday_id != HOLIDAY_NONE)
            {
                if (!sHolidaysStore.LookupEntry(pGameEvent.holiday_id))
                {
                    sLog->outErrorDb("`game_event` game event id (%i) have not existed holiday id %u.",event_id,pGameEvent.holiday_id);
                    pGameEvent.holiday_id = HOLIDAY_NONE;
                }
            }

            pGameEvent.description  = fields[6].GetString();

            ++count;
        }
        while (result->NextRow());

        sLog->outString(">> Loaded %u game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        sLog->outString();
    }

    sLog->outString("Loading Game Event Saves Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                       0       1        2
        QueryResult result = CharacterDatabase.Query("SELECT event_id, state, next_start FROM game_event_save");

        if (!result)
        {
            sLog->outString(">> Loaded 0 game event saves in game events. DB table `game_event_save` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint16 event_id = fields[0].GetUInt16();

                if (event_id >= mGameEvent.size())
                {
                    sLog->outErrorDb("`game_event_save` game event id (%i) is out of range compared to max event id in `game_event`", event_id);
                    continue;
                }

                if (mGameEvent[event_id].state != GAMEEVENT_NORMAL && mGameEvent[event_id].state != GAMEEVENT_INTERNAL)
                {
                    mGameEvent[event_id].state = (GameEventState)(fields[1].GetUInt8());
                    mGameEvent[event_id].nextstart    = time_t(fields[2].GetUInt32());
                }
                else
                {
                    sLog->outErrorDb("game_event_save includes event save for non-worldevent id %u", event_id);
                    continue;
                }

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u game event saves in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event Prerequisite Data...");
    {
        uint32 oldMSTime = getMSTime();

        QueryResult result = WorldDatabase.Query("SELECT event_id, prerequisite_event FROM game_event_prerequisite");
        if (!result)
        {
            sLog->outString(">> Loaded 0 game event prerequisites in game events. DB table `game_event_prerequisite` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint16 event_id = fields[0].GetUInt16();

                if (event_id >= mGameEvent.size())
                {
                    sLog->outErrorDb("`game_event_prerequisite` game event id (%i) is out of range compared to max event id in `game_event`", event_id);
                    continue;
                }

                if (mGameEvent[event_id].state != GAMEEVENT_NORMAL && mGameEvent[event_id].state != GAMEEVENT_INTERNAL)
                {
                    uint16 prerequisite_event = fields[1].GetUInt16();
                    if (prerequisite_event >= mGameEvent.size())
                    {
                        sLog->outErrorDb("`game_event_prerequisite` game event prerequisite id (%i) is out of range compared to max event id in `game_event`", prerequisite_event);
                        continue;
                    }
                    mGameEvent[event_id].prerequisite_events.insert(prerequisite_event);
                }
                else
                {
                    sLog->outErrorDb("game_event_prerequisiste includes event entry for non-worldevent id %u", event_id);
                    continue;
                }

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u game event prerequisites in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }


    sLog->outString("Loading Game Event Creature Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                        1                2
        QueryResult result = WorldDatabase.Query("SELECT creature.guid, game_event_creature.event FROM creature"
                                                 " JOIN game_event_creature ON creature.guid = game_event_creature.guid");

        if (!result)
        {
            sLog->outString(">> Loaded 0 creatures in game events. DB table `game_event_creature` is empty");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint32 guid    = fields[0].GetUInt32();
                int16 event_id = fields[1].GetInt16();

                int32 internal_event_id = mGameEvent.size() + event_id - 1;

                if (internal_event_id < 0 || internal_event_id >= int32(mGameEventCreatureGuids.size()))
                {
                    sLog->outErrorDb("`game_event_creature` game event id (%i) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                GuidList& crelist = mGameEventCreatureGuids[internal_event_id];
                crelist.push_back(guid);

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u creatures in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event GO Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                   1                2
        QueryResult result = WorldDatabase.Query("SELECT gameobject.guid, game_event_gameobject.event "
            "FROM gameobject JOIN game_event_gameobject ON gameobject.guid=game_event_gameobject.guid");

        if (!result)
        {
            sLog->outString(">> Loaded 0 gameobjects in game events. DB table `game_event_gameobject` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint32 guid    = fields[0].GetUInt32();
                int16 event_id = fields[1].GetInt16();

                int32 internal_event_id = mGameEvent.size() + event_id - 1;

                if (internal_event_id < 0 || internal_event_id >= int32(mGameEventGameobjectGuids.size()))
                {
                    sLog->outErrorDb("`game_event_gameobject` game event id (%i) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                GuidList& golist = mGameEventGameobjectGuids[internal_event_id];
                golist.push_back(guid);

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u gameobjects in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event Model/Equipment Change Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                       0                     1                              2                               3
        QueryResult result = WorldDatabase.Query("SELECT creature.guid, game_event_model_equip.event, game_event_model_equip.modelid, game_event_model_equip.equipment_id "
                                                 "FROM creature JOIN game_event_model_equip ON creature.guid=game_event_model_equip.guid");

        if (!result)
        {
            sLog->outString(">> Loaded 0 model/equipment changes in game events. DB table `game_event_model_equip` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint32 guid     = fields[0].GetUInt32();
                uint16 event_id = fields[1].GetUInt16();

                if (event_id >= mGameEventModelEquip.size())
                {
                    sLog->outErrorDb("`game_event_model_equip` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                ModelEquipList& equiplist = mGameEventModelEquip[event_id];
                ModelEquip newModelEquipSet;
                newModelEquipSet.modelid = fields[2].GetUInt32();
                newModelEquipSet.equipment_id = fields[3].GetUInt32();
                newModelEquipSet.equipement_id_prev = 0;
                newModelEquipSet.modelid_prev = 0;

                if (newModelEquipSet.equipment_id > 0)
                {
                    if (!sObjectMgr->GetEquipmentInfo(newModelEquipSet.equipment_id))
                    {
                        sLog->outErrorDb("Table `game_event_model_equip` have creature (Guid: %u) with equipment_id %u not found in table `creature_equip_template`, set to no equipment.",
                                         guid, newModelEquipSet.equipment_id);
                        continue;
                    }
                }

                equiplist.push_back(std::pair<uint32, ModelEquip>(guid, newModelEquipSet));

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u model/equipment changes in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event Quest Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                               0     1      2
        QueryResult result = WorldDatabase.Query("SELECT id, quest, event FROM game_event_creature_quest");

        if (!result)
        {
            sLog->outString(">> Loaded 0 quests additions in game events. DB table `game_event_creature_quest` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint32 id       = fields[0].GetUInt32();
                uint32 quest    = fields[1].GetUInt32();
                uint16 event_id = fields[2].GetUInt16();

                if (event_id >= mGameEventCreatureQuests.size())
                {
                    sLog->outErrorDb("`game_event_creature_quest` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                QuestRelList& questlist = mGameEventCreatureQuests[event_id];
                questlist.push_back(QuestRelation(id, quest));

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u quests additions in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event GO Quest Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                               0     1      2
        QueryResult result = WorldDatabase.Query("SELECT id, quest, event FROM game_event_gameobject_quest");

        if (!result)
        {
            sLog->outString(">> Loaded 0 go quests additions in game events. DB table `game_event_gameobject_quest` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint32 id       = fields[0].GetUInt32();
                uint32 quest    = fields[1].GetUInt32();
                uint16 event_id = fields[2].GetUInt16();

                if (event_id >= mGameEventGameObjectQuests.size())
                {
                    sLog->outErrorDb("`game_event_gameobject_quest` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                QuestRelList& questlist = mGameEventGameObjectQuests[event_id];
                questlist.push_back(QuestRelation(id, quest));

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u quests additions in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event Quest Condition Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                 0       1         2           3
        QueryResult result = WorldDatabase.Query("SELECT quest, event_id, condition_id, num FROM game_event_quest_condition");

        if (!result)
        {
            sLog->outString(">> Loaded 0 quest event conditions in game events. DB table `game_event_quest_condition` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint32 quest     = fields[0].GetUInt32();
                uint16 event_id  = fields[1].GetUInt16();
                uint32 condition = fields[2].GetUInt32();
                float num       = fields[3].GetFloat();

                if (event_id >= mGameEvent.size())
                {
                    sLog->outErrorDb("`game_event_quest_condition` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                mQuestToEventConditions[quest].event_id = event_id;
                mQuestToEventConditions[quest].condition = condition;
                mQuestToEventConditions[quest].num = num;

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u quest event conditions in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event Condition Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                  0          1            2             3                      4
        QueryResult result = WorldDatabase.Query("SELECT event_id, condition_id, req_num, max_world_state_field, done_world_state_field FROM game_event_condition");

        if (!result)
        {
            sLog->outString(">> Loaded 0 conditions in game events. DB table `game_event_condition` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint16 event_id  = fields[0].GetUInt16();
                uint32 condition = fields[1].GetUInt32();

                if (event_id >= mGameEvent.size())
                {
                    sLog->outErrorDb("`game_event_condition` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                mGameEvent[event_id].conditions[condition].reqNum = fields[2].GetFloat();
                mGameEvent[event_id].conditions[condition].done = 0;
                mGameEvent[event_id].conditions[condition].max_world_state = fields[3].GetUInt32();
                mGameEvent[event_id].conditions[condition].done_world_state = fields[4].GetUInt32();

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u conditions in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event Condition Save Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                      0           1         2
        QueryResult result = CharacterDatabase.Query("SELECT event_id, condition_id, done FROM game_event_condition_save");

        if (!result)
        {
            sLog->outString(">> Loaded 0 condition saves in game events. DB table `game_event_condition_save` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint16 event_id  = fields[0].GetUInt16();
                uint32 condition = fields[1].GetUInt32();

                if (event_id >= mGameEvent.size())
                {
                    sLog->outErrorDb("`game_event_condition_save` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                std::map<uint32, GameEventFinishCondition>::iterator itr = mGameEvent[event_id].conditions.find(condition);
                if (itr != mGameEvent[event_id].conditions.end())
                {
                    itr->second.done = fields[2].GetFloat();
                }
                else
                {
                    sLog->outErrorDb("game_event_condition_save contains not present condition evt id %u cond id %u",event_id, condition);
                    continue;
                }

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u condition saves in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event NPCflag Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                0       1        2
        QueryResult result = WorldDatabase.Query("SELECT guid, event_id, npcflag FROM game_event_npcflag");

        if (!result)
        {
            sLog->outString(">> Loaded 0 npcflags in game events. DB table `game_event_npcflag` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint32 guid     = fields[0].GetUInt32();
                uint16 event_id = fields[1].GetUInt16();
                uint32 npcflag  = fields[2].GetUInt32();

                if (event_id >= mGameEvent.size())
                {
                    sLog->outErrorDb("`game_event_npcflag` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                mGameEventNPCFlags[event_id].push_back(GuidNPCFlagPair(guid,npcflag));

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u npcflags in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event Vendor Additions Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                 0      1     2      3         4          5
        QueryResult result = WorldDatabase.Query("SELECT event, guid, item, maxcount, incrtime, ExtendedCost FROM game_event_npc_vendor ORDER BY guid, slot ASC");

        if (!result)
        {
            sLog->outString(">> Loaded 0 vendor additions in game events. DB table `game_event_npc_vendor` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint16 event_id  = fields[0].GetUInt16();

                if (event_id >= mGameEventVendors.size())
                {
                    sLog->outErrorDb("`game_event_npc_vendor` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                NPCVendorList& vendors = mGameEventVendors[event_id];
                NPCVendorEntry newEntry;
                uint32 guid = fields[1].GetUInt32();
                newEntry.item = fields[2].GetUInt32();
                newEntry.maxcount = fields[3].GetInt32();
                newEntry.incrtime = fields[4].GetUInt32();
                newEntry.ExtendedCost = fields[5].GetUInt32();
                // get the event npc flag for checking if the npc will be vendor during the event or not
                uint32 event_npc_flag = 0;
                NPCFlagList& flist = mGameEventNPCFlags[event_id];
                for (NPCFlagList::const_iterator itr = flist.begin(); itr != flist.end(); ++itr)
                {
                    if (itr->first == guid)
                    {
                        event_npc_flag = itr->second;
                        break;
                    }
                }
                // get creature entry
                newEntry.entry = 0;

                if (CreatureData const* data = sObjectMgr->GetCreatureData(guid))
                    newEntry.entry = data->id;

                // check validity with event's npcflag
                if (!sObjectMgr->IsVendorItemValid(newEntry.entry, newEntry.item, newEntry.maxcount, newEntry.incrtime, newEntry.ExtendedCost, NULL, NULL, event_npc_flag))
                    continue;

                vendors.push_back(newEntry);

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u vendor additions in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event Battleground Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                 0      1
        QueryResult result = WorldDatabase.Query("SELECT event, bgflag FROM game_event_battleground_holiday");

        if (!result)
        {
            sLog->outString(">> Loaded 0 battleground holidays in game events. DB table `game_event_condition` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint16 event_id = fields[0].GetUInt16();

                if (event_id >= mGameEvent.size())
                {
                    sLog->outErrorDb("`game_event_battleground_holiday` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                mGameEventBattlegroundHolidays[event_id] = fields[1].GetUInt32();

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u battleground holidays in game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }

    sLog->outString("Loading Game Event Pool Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                       1                    2
        QueryResult result = WorldDatabase.Query("SELECT pool_template.entry, game_event_pool.event FROM pool_template"
                                                 " JOIN game_event_pool ON pool_template.entry = game_event_pool.pool_entry");

        if (!result)
        {
            sLog->outString(">> Loaded 0 pools for game events. DB table `game_event_pool` is empty.");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field *fields = result->Fetch();

                uint32 entry   = fields[0].GetUInt32();
                int16 event_id = fields[1].GetInt16();

                int32 internal_event_id = mGameEvent.size() + event_id - 1;

                if (internal_event_id < 0 || internal_event_id >= int32(mGameEventPoolIds.size()))
                {
                    sLog->outErrorDb("`game_event_pool` game event id (%i) is out of range compared to max event id in `game_event`",event_id);
                    continue;
                }

                if (!sPoolMgr->CheckPool(entry))
                {
                    sLog->outErrorDb("Pool Id (%u) has all creatures or gameobjects with explicit chance sum <>100 and no equal chance defined. The pool system cannot pick one to spawn.", entry);
                    continue;
                }

                IdList& poollist = mGameEventPoolIds[internal_event_id];
                poollist.push_back(entry);

                ++count;
            }
            while (result->NextRow());

            sLog->outString(">> Loaded %u pools for game events in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

uint32 GameEventMgr::GetNPCFlag(Creature * cr)
{
    uint32 mask = 0;
    uint32 guid = cr->GetDBTableGUIDLow();

    for (ActiveEvents::iterator e_itr = m_ActiveEvents.begin(); e_itr != m_ActiveEvents.end(); ++e_itr)
    {
        for (NPCFlagList::iterator itr = mGameEventNPCFlags[*e_itr].begin();
            itr != mGameEventNPCFlags[*e_itr].end();
            ++ itr)
            if (itr->first == guid)
                mask |= itr->second;
    }

    return mask;
}

void GameEventMgr::Initialize()
{
    QueryResult result = WorldDatabase.Query("SELECT MAX(entry) FROM game_event");
    if (result)
    {
        Field *fields = result->Fetch();

        uint32 maxEventId = fields[0].GetUInt16();

        // Id starts with 1 and vector with 0, thus increment
        maxEventId++;

        mGameEvent.resize(maxEventId);
        mGameEventCreatureGuids.resize(maxEventId * 2 - 1);
        mGameEventGameobjectGuids.resize(maxEventId * 2 - 1);
        mGameEventCreatureQuests.resize(maxEventId);
        mGameEventGameObjectQuests.resize(maxEventId);
        mGameEventVendors.resize(maxEventId);
        mGameEventBattlegroundHolidays.resize(maxEventId, 0);
        mGameEventPoolIds.resize(maxEventId * 2 - 1);
        mGameEventNPCFlags.resize(maxEventId);
        mGameEventModelEquip.resize(maxEventId);
    }
}

uint32 GameEventMgr::StartSystem()                           // return the next event delay in ms
{
    m_ActiveEvents.clear();
    uint32 delay = Update();
    isSystemInit = true;
    return delay;
}

void GameEventMgr::StartArenaSeason()
{
    QueryResult result = WorldDatabase.PQuery("SELECT event FROM season_linked_event WHERE season = '%i'",sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID));

    if (!result)
    {
        sLog->outError("ArenaSeason (%i) must be an existant Arena Season",sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID));
        return;
    }

    Field *fields = result->Fetch();

    uint16 eventId = fields[0].GetUInt16();

    StartEvent(eventId,true);
    sLog->outString("Arena Season %i started...",sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID));
    sLog->outString();
}

uint32 GameEventMgr::Update()                               // return the next event delay in ms
{
    time_t currenttime = time(NULL);
    uint32 nextEventDelay = max_ge_check_delay;             // 1 day
    uint32 calcDelay;
    std::set<uint16> activate, deactivate;
    for (uint16 itr = 1; itr < mGameEvent.size(); ++itr)
    {
        // must do the activating first, and after that the deactivating
        // so first queue it
        //sLog->outErrorDb("Checking event %u",itr);
        if (CheckOneGameEvent(itr))
        {
            // if the world event is in NEXTPHASE state, and the time has passed to finish this event, then do so
            if (mGameEvent[itr].state == GAMEEVENT_WORLD_NEXTPHASE && mGameEvent[itr].nextstart <= currenttime)
            {
                // set this event to finished, null the nextstart time
                mGameEvent[itr].state = GAMEEVENT_WORLD_FINISHED;
                mGameEvent[itr].nextstart = 0;
                // save the state of this gameevent
                SaveWorldEventStateToDB(itr);
                // queue for deactivation
                if (IsActiveEvent(itr))
                    deactivate.insert(itr);
                // go to next event, this no longer needs an event update timer
                continue;
            }
            else if (mGameEvent[itr].state == GAMEEVENT_WORLD_CONDITIONS && CheckOneGameEventConditions(itr))
                // changed, save to DB the gameevent state, will be updated in next update cycle
                SaveWorldEventStateToDB(itr);

            //sLog->outDebug("GameEvent %u is active",itr->first);
            // queue for activation
            if (!IsActiveEvent(itr))
                activate.insert(itr);
        }
        else
        {
            //sLog->outDebug("GameEvent %u is not active",itr->first);
            if (IsActiveEvent(itr))
                deactivate.insert(itr);
            else
            {
                if (!isSystemInit)
                {
                    int16 event_nid = (-1) * (itr);
                    // spawn all negative ones for this event
                    GameEventSpawn(event_nid);
                }
            }
        }
        calcDelay = NextCheck(itr);
        if (calcDelay < nextEventDelay)
            nextEventDelay = calcDelay;
    }
    // now activate the queue
    // a now activated event can contain a spawn of a to-be-deactivated one
    // following the activate - deactivate order, deactivating the first event later will leave the spawn in (wont disappear then reappear clientside)
    for (std::set<uint16>::iterator itr = activate.begin(); itr != activate.end(); ++itr)
        // start the event
        // returns true the started event completed
        // in that case, initiate next update in 1 second
        if (StartEvent(*itr))
            nextEventDelay = 0;
    for (std::set<uint16>::iterator itr = deactivate.begin(); itr != deactivate.end(); ++itr)
        StopEvent(*itr);
    sLog->outDetail("Next game event check in %u seconds.", nextEventDelay + 1);
    return (nextEventDelay + 1) * IN_MILLISECONDS;           // Add 1 second to be sure event has started/stopped at next call
}

void GameEventMgr::UnApplyEvent(uint16 event_id)
{
    sLog->outDetail("GameEvent %u \"%s\" removed.", event_id, mGameEvent[event_id].description.c_str());
    // un-spawn positive event tagged objects
    GameEventUnspawn(event_id);
    // spawn negative event tagget objects
    int16 event_nid = (-1) * event_id;
    GameEventSpawn(event_nid);
    // restore equipment or model
    ChangeEquipOrModel(event_id, false);
    // Remove quests that are events only to non event npc
    UpdateEventQuests(event_id, false);
    UpdateWorldStates(event_id, false);
    // update npcflags in this event
    UpdateEventNPCFlags(event_id);
    // remove vendor items
    UpdateEventNPCVendor(event_id, false);
    // update bg holiday
    UpdateBattlegroundSettings();
}

void GameEventMgr::ApplyNewEvent(uint16 event_id)
{
    switch(sWorld->getIntConfig(CONFIG_EVENT_ANNOUNCE))
    {
        case 0:                                             // disable
            break;
        case 1:                                             // announce events
            sWorld->SendWorldText(LANG_EVENTMESSAGE, mGameEvent[event_id].description.c_str());
            break;
    }

    sLog->outDetail("GameEvent %u \"%s\" started.", event_id, mGameEvent[event_id].description.c_str());

    // spawn positive event tagget objects
    GameEventSpawn(event_id);
    // un-spawn negative event tagged objects
    int16 event_nid = (-1) * event_id;
    GameEventUnspawn(event_nid);
    // Change equipement or model
    ChangeEquipOrModel(event_id, true);
    // Add quests that are events only to non event npc
    UpdateEventQuests(event_id, true);
    UpdateWorldStates(event_id, true);
    // update npcflags in this event
    UpdateEventNPCFlags(event_id);
    // add vendor items
    UpdateEventNPCVendor(event_id, true);
    // update bg holiday
    UpdateBattlegroundSettings();
}

void GameEventMgr::UpdateEventNPCFlags(uint16 event_id)
{
    // go through the creatures whose npcflags are changed in the event
    for (NPCFlagList::iterator itr = mGameEventNPCFlags[event_id].begin(); itr != mGameEventNPCFlags[event_id].end(); ++itr)
    {
        // get the creature data from the low guid to get the entry, to be able to find out the whole guid
        if (CreatureData const* data = sObjectMgr->GetCreatureData(itr->first))
        {
            Creature * cr = HashMapHolder<Creature>::Find(MAKE_NEW_GUID(itr->first,data->id,HIGHGUID_UNIT));
            // if we found the creature, modify its npcflag
            if (cr)
            {
                uint32 npcflag = GetNPCFlag(cr);
                if (const CreatureInfo * ci = cr->GetCreatureInfo())
                    npcflag |= ci->npcflag;
                cr->SetUInt32Value(UNIT_NPC_FLAGS,npcflag);
                // reset gossip options, since the flag change might have added / removed some
                //cr->ResetGossipOptions();
            }
            // if we didn't find it, then the npcflag will be updated when the creature is loaded
        }
    }
}

void GameEventMgr::UpdateBattlegroundSettings()
{
    uint32 mask = 0;
    for (ActiveEvents::const_iterator itr = m_ActiveEvents.begin(); itr != m_ActiveEvents.end(); ++itr)
        mask |= mGameEventBattlegroundHolidays[*itr];
    sBattlegroundMgr->SetHolidayWeekends(mask);
}

void GameEventMgr::UpdateEventNPCVendor(uint16 event_id, bool activate)
{
    for (NPCVendorList::iterator itr = mGameEventVendors[event_id].begin(); itr != mGameEventVendors[event_id].end(); ++itr)
    {
        if (activate)
            sObjectMgr->AddVendorItem(itr->entry, itr->item, itr->maxcount, itr->incrtime, itr->ExtendedCost, false);
        else
            sObjectMgr->RemoveVendorItem(itr->entry, itr->item, false);
    }
}

void GameEventMgr::GameEventSpawn(int16 event_id)
{
    int32 internal_event_id = mGameEvent.size() + event_id - 1;

    if (internal_event_id < 0 || internal_event_id >= int32(mGameEventCreatureGuids.size()))
    {
        sLog->outError("GameEventMgr::GameEventSpawn attempt access to out of range mGameEventCreatureGuids element %i (size: " SIZEFMTD ")",
            internal_event_id, mGameEventCreatureGuids.size());
        return;
    }

    for (GuidList::iterator itr = mGameEventCreatureGuids[internal_event_id].begin(); itr != mGameEventCreatureGuids[internal_event_id].end(); ++itr)
    {
        // Add to correct cell
        if (CreatureData const* data = sObjectMgr->GetCreatureData(*itr))
        {
            sObjectMgr->AddCreatureToGrid(*itr, data);

            // Spawn if necessary (loaded grids only)
            Map* map = const_cast<Map*>(sMapMgr->CreateBaseMap(data->mapid));
            // We use spawn coords to spawn
            if (!map->Instanceable() && map->IsLoaded(data->posX, data->posY))
            {
                Creature* pCreature = new Creature;
                //sLog->outDebug("Spawning creature %u",*itr);
                if (!pCreature->LoadFromDB(*itr, map))
                    delete pCreature;
                else
                    map->Add(pCreature);
            }
        }
    }

    if (internal_event_id < 0 || internal_event_id >= int32(mGameEventGameobjectGuids.size()))
    {
        sLog->outError("GameEventMgr::GameEventSpawn attempt access to out of range mGameEventGameobjectGuids element %i (size: " SIZEFMTD ")",
            internal_event_id, mGameEventGameobjectGuids.size());
        return;
    }

    for (GuidList::iterator itr = mGameEventGameobjectGuids[internal_event_id].begin(); itr != mGameEventGameobjectGuids[internal_event_id].end(); ++itr)
    {
        // Add to correct cell
        if (GameObjectData const* data = sObjectMgr->GetGOData(*itr))
        {
            sObjectMgr->AddGameobjectToGrid(*itr, data);
            // Spawn if necessary (loaded grids only)
            // this base map checked as non-instanced and then only existed
            Map* map = const_cast<Map*>(sMapMgr->CreateBaseMap(data->mapid));
            // We use current coords to unspawn, not spawn coords since creature can have changed grid
            if (!map->Instanceable() && map->IsLoaded(data->posX, data->posY))
            {
                GameObject* pGameobject = new GameObject;
                //sLog->outDebug("Spawning gameobject %u", *itr);
                if (!pGameobject->LoadFromDB(*itr, map))
                    delete pGameobject;
                else
                {
                    if (pGameobject->isSpawnedByDefault())
                        map->Add(pGameobject);
                }
            }
        }
    }

    if (internal_event_id < 0 || internal_event_id >= int32(mGameEventPoolIds.size()))
    {
        sLog->outError("GameEventMgr::GameEventSpawn attempt access to out of range mGameEventPoolIds element %u (size: " SIZEFMTD ")",
            internal_event_id, mGameEventPoolIds.size());
        return;
    }

    for (IdList::iterator itr = mGameEventPoolIds[internal_event_id].begin(); itr != mGameEventPoolIds[internal_event_id].end(); ++itr)
        sPoolMgr->SpawnPool(*itr);
}

void GameEventMgr::GameEventUnspawn(int16 event_id)
{
    int32 internal_event_id = mGameEvent.size() + event_id - 1;

    if (internal_event_id < 0 || internal_event_id >= int32(mGameEventCreatureGuids.size()))
    {
        sLog->outError("GameEventMgr::GameEventUnspawn attempt access to out of range mGameEventCreatureGuids element %i (size: " SIZEFMTD ")",
            internal_event_id, mGameEventCreatureGuids.size());
        return;
    }

    for (GuidList::iterator itr = mGameEventCreatureGuids[internal_event_id].begin(); itr != mGameEventCreatureGuids[internal_event_id].end(); ++itr)
    {
        // check if it's needed by another event, if so, don't remove
        if (event_id > 0 && hasCreatureActiveEventExcept(*itr,event_id))
            continue;
        // Remove the creature from grid
        if (CreatureData const* data = sObjectMgr->GetCreatureData(*itr))
        {
            sObjectMgr->RemoveCreatureFromGrid(*itr, data);

            if (Creature* pCreature = ObjectAccessor::GetObjectInWorld(MAKE_NEW_GUID(*itr, data->id, HIGHGUID_UNIT), (Creature*)NULL))
                pCreature->AddObjectToRemoveList();
        }
    }

    if (internal_event_id < 0 || internal_event_id >= int32(mGameEventGameobjectGuids.size()))
    {
        sLog->outError("GameEventMgr::GameEventUnspawn attempt access to out of range mGameEventGameobjectGuids element %i (size: " SIZEFMTD ")",
            internal_event_id, mGameEventGameobjectGuids.size());
        return;
    }

    for (GuidList::iterator itr = mGameEventGameobjectGuids[internal_event_id].begin(); itr != mGameEventGameobjectGuids[internal_event_id].end(); ++itr)
    {
        // check if it's needed by another event, if so, don't remove
        if (event_id >0 && hasGameObjectActiveEventExcept(*itr,event_id))
            continue;
        // Remove the gameobject from grid
        if (GameObjectData const* data = sObjectMgr->GetGOData(*itr))
        {
            sObjectMgr->RemoveGameobjectFromGrid(*itr, data);

            if (GameObject* pGameobject = ObjectAccessor::GetObjectInWorld(MAKE_NEW_GUID(*itr, data->id, HIGHGUID_GAMEOBJECT), (GameObject*)NULL))
                pGameobject->AddObjectToRemoveList();
        }
    }
    if (internal_event_id < 0 || internal_event_id >= int32(mGameEventPoolIds.size()))
    {
        sLog->outError("GameEventMgr::GameEventUnspawn attempt access to out of range mGameEventPoolIds element %u (size: " SIZEFMTD ")",internal_event_id,mGameEventPoolIds.size());
        return;
    }

    for (IdList::iterator itr = mGameEventPoolIds[internal_event_id].begin(); itr != mGameEventPoolIds[internal_event_id].end(); ++itr)
    {
        sPoolMgr->DespawnPool(*itr);
    }
}

void GameEventMgr::ChangeEquipOrModel(int16 event_id, bool activate)
{
    for (ModelEquipList::iterator itr = mGameEventModelEquip[event_id].begin(); itr != mGameEventModelEquip[event_id].end(); ++itr)
    {
        // Remove the creature from grid
        CreatureData const* data = sObjectMgr->GetCreatureData(itr->first);
        if (!data)
            continue;

        // Update if spawned
        Creature* pCreature = ObjectAccessor::GetObjectInWorld(MAKE_NEW_GUID(itr->first, data->id,HIGHGUID_UNIT), (Creature*)NULL);
        if (pCreature)
        {
            if (activate)
            {
                itr->second.equipement_id_prev = pCreature->GetCurrentEquipmentId();
                itr->second.modelid_prev = pCreature->GetDisplayId();
                pCreature->LoadEquipment(itr->second.equipment_id, true);
                if (itr->second.modelid >0 && itr->second.modelid_prev != itr->second.modelid)
                {
                    CreatureModelInfo const *minfo = sObjectMgr->GetCreatureModelInfo(itr->second.modelid);
                    if (minfo)
                    {
                        pCreature->SetDisplayId(itr->second.modelid);
                        pCreature->SetNativeDisplayId(itr->second.modelid);
                        pCreature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS,minfo->bounding_radius);
                        pCreature->SetFloatValue(UNIT_FIELD_COMBATREACH,minfo->combat_reach);
                    }
                }
            }
            else
            {
                pCreature->LoadEquipment(itr->second.equipement_id_prev, true);
                if (itr->second.modelid_prev >0 && itr->second.modelid_prev != itr->second.modelid)
                {
                    CreatureModelInfo const *minfo = sObjectMgr->GetCreatureModelInfo(itr->second.modelid_prev);
                    if (minfo)
                    {
                        pCreature->SetDisplayId(itr->second.modelid_prev);
                        pCreature->SetNativeDisplayId(itr->second.modelid_prev);
                        pCreature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS,minfo->bounding_radius);
                        pCreature->SetFloatValue(UNIT_FIELD_COMBATREACH,minfo->combat_reach);
                    }
                }
            }
        }
        else                                                // If not spawned
        {
            CreatureData const* data2 = sObjectMgr->GetCreatureData(itr->first);
            if (data2 && activate)
            {
                CreatureInfo const *cinfo = ObjectMgr::GetCreatureTemplate(data2->id);
                uint32 display_id = sObjectMgr->ChooseDisplayId(0,cinfo,data2);
                CreatureModelInfo const *minfo = sObjectMgr->GetCreatureModelRandomGender(display_id);
                if (minfo)
                    display_id = minfo->modelid;

                if (data2->equipmentId == 0)
                    itr->second.equipement_id_prev = cinfo->equipmentId;
                else if (data2->equipmentId != -1)
                    itr->second.equipement_id_prev = data->equipmentId;
                itr->second.modelid_prev = display_id;
            }
        }
        // now last step: put in data
                                                            // just to have write access to it
        CreatureData& data2 = sObjectMgr->NewOrExistCreatureData(itr->first);
        if (activate)
        {
            data2.displayid = itr->second.modelid;
            data2.equipmentId = itr->second.equipment_id;
        }
        else
        {
            data2.displayid = itr->second.modelid_prev;
            data2.equipmentId = itr->second.equipement_id_prev;
        }
    }
}

bool GameEventMgr::hasCreatureQuestActiveEventExcept(uint32 quest_id, uint16 event_id)
{
    for (ActiveEvents::iterator e_itr = m_ActiveEvents.begin(); e_itr != m_ActiveEvents.end(); ++e_itr)
    {
        if ((*e_itr) != event_id)
            for (QuestRelList::iterator itr = mGameEventCreatureQuests[*e_itr].begin();
                itr != mGameEventCreatureQuests[*e_itr].end();
                ++ itr)
                if (itr->second == quest_id)
                    return true;
    }
    return false;
}

bool GameEventMgr::hasGameObjectQuestActiveEventExcept(uint32 quest_id, uint16 event_id)
{
    for (ActiveEvents::iterator e_itr = m_ActiveEvents.begin(); e_itr != m_ActiveEvents.end(); ++e_itr)
    {
        if ((*e_itr) != event_id)
            for (QuestRelList::iterator itr = mGameEventGameObjectQuests[*e_itr].begin();
                itr != mGameEventGameObjectQuests[*e_itr].end();
                ++ itr)
                if (itr->second == quest_id)
                    return true;
    }
    return false;
}
bool GameEventMgr::hasCreatureActiveEventExcept(uint32 creature_id, uint16 event_id)
{
    for (ActiveEvents::iterator e_itr = m_ActiveEvents.begin(); e_itr != m_ActiveEvents.end(); ++e_itr)
    {
        if ((*e_itr) != event_id)
        {
            int32 internal_event_id = mGameEvent.size() + (*e_itr) - 1;
            for (GuidList::iterator itr = mGameEventCreatureGuids[internal_event_id].begin();
                itr != mGameEventCreatureGuids[internal_event_id].end();
                ++ itr)
                if (*itr == creature_id)
                    return true;
        }
    }
    return false;
}
bool GameEventMgr::hasGameObjectActiveEventExcept(uint32 go_id, uint16 event_id)
{
    for (ActiveEvents::iterator e_itr = m_ActiveEvents.begin(); e_itr != m_ActiveEvents.end(); ++e_itr)
    {
        if ((*e_itr) != event_id)
        {
            int32 internal_event_id = mGameEvent.size() + (*e_itr) - 1;
            for (GuidList::iterator itr = mGameEventGameobjectGuids[internal_event_id].begin();
                itr != mGameEventGameobjectGuids[internal_event_id].end();
                ++ itr)
                if (*itr == go_id)
                    return true;
        }
    }
    return false;
}

void GameEventMgr::UpdateEventQuests(uint16 event_id, bool activate)
{
    QuestRelList::iterator itr;
    for (itr = mGameEventCreatureQuests[event_id].begin(); itr != mGameEventCreatureQuests[event_id].end(); ++itr)
    {
        QuestRelations* CreatureQuestMap = sObjectMgr->GetCreatureQuestRelationMap();
        if (activate)                                           // Add the pair(id,quest) to the multimap
            CreatureQuestMap->insert(QuestRelations::value_type(itr->first, itr->second));
        else
        {
            if (!hasCreatureQuestActiveEventExcept(itr->second,event_id))
            {
                // Remove the pair(id,quest) from the multimap
                QuestRelations::iterator qitr = CreatureQuestMap->find(itr->first);
                if (qitr == CreatureQuestMap->end())
                    continue;
                QuestRelations::iterator lastElement = CreatureQuestMap->upper_bound(itr->first);
                for (; qitr != lastElement; ++qitr)
                {
                    if (qitr->second == itr->second)
                    {
                        CreatureQuestMap->erase(qitr);          // iterator is now no more valid
                        break;                                  // but we can exit loop since the element is found
                    }
                }
            }
        }
    }
    for (itr = mGameEventGameObjectQuests[event_id].begin(); itr != mGameEventGameObjectQuests[event_id].end(); ++itr)
    {
        QuestRelations* GameObjectQuestMap = sObjectMgr->GetGOQuestRelationMap();
        if (activate)                                           // Add the pair(id,quest) to the multimap
            GameObjectQuestMap->insert(QuestRelations::value_type(itr->first, itr->second));
        else
        {
            if (!hasGameObjectQuestActiveEventExcept(itr->second,event_id))
            {
                // Remove the pair(id,quest) from the multimap
                QuestRelations::iterator qitr = GameObjectQuestMap->find(itr->first);
                if (qitr == GameObjectQuestMap->end())
                    continue;
                QuestRelations::iterator lastElement = GameObjectQuestMap->upper_bound(itr->first);
                for (; qitr != lastElement; ++qitr)
                {
                    if (qitr->second == itr->second)
                    {
                        GameObjectQuestMap->erase(qitr);        // iterator is now no more valid
                        break;                                  // but we can exit loop since the element is found
                    }
                }
            }
        }
    }
}

void GameEventMgr::UpdateWorldStates(uint16 event_id, bool Activate)
{
    GameEventData const& event = mGameEvent[event_id];
    if (event.holiday_id != HOLIDAY_NONE)
    {
        BattlegroundTypeId bgTypeId = BattlegroundMgr::WeekendHolidayIdToBGType(event.holiday_id);
        if (bgTypeId != BATTLEGROUND_TYPE_NONE)
        {
            BattlemasterListEntry const * bl = sBattlemasterListStore.LookupEntry(bgTypeId);
            if (bl && bl->HolidayWorldStateId)
            {
                WorldPacket data;
                sBattlegroundMgr->BuildUpdateWorldStatePacket(&data, bl->HolidayWorldStateId, Activate ? 1 : 0);
                sWorld->SendGlobalMessage(&data);
            }
        }
    }
}

GameEventMgr::GameEventMgr() : isSystemInit(false)
{
}

void GameEventMgr::HandleQuestComplete(uint32 quest_id)
{
    // translate the quest to event and condition
    QuestIdToEventConditionMap::iterator itr = mQuestToEventConditions.find(quest_id);
    // quest is registered
    if (itr != mQuestToEventConditions.end())
    {
        uint16 event_id = itr->second.event_id;
        uint32 condition = itr->second.condition;
        float num = itr->second.num;

        // the event is not active, so return, don't increase condition finishes
        if (!IsActiveEvent(event_id))
            return;
        // not in correct phase, return
        if (mGameEvent[event_id].state != GAMEEVENT_WORLD_CONDITIONS)
            return;
        std::map<uint32,GameEventFinishCondition>::iterator citr = mGameEvent[event_id].conditions.find(condition);
        // condition is registered
        if (citr != mGameEvent[event_id].conditions.end())
        {
            // increase the done count, only if less then the req
            if (citr->second.done < citr->second.reqNum)
            {
                citr->second.done += num;
                // check max limit
                if (citr->second.done > citr->second.reqNum)
                    citr->second.done = citr->second.reqNum;
                // save the change to db
                SQLTransaction trans = CharacterDatabase.BeginTransaction();
                trans->PAppend("DELETE FROM game_event_condition_save WHERE event_id = '%u' AND condition_id = '%u'",event_id,condition);
                trans->PAppend("INSERT INTO game_event_condition_save (event_id, condition_id, done) VALUES (%u,%u,%f)",event_id,condition,citr->second.done);
                CharacterDatabase.CommitTransaction(trans);
                // check if all conditions are met, if so, update the event state
                if (CheckOneGameEventConditions(event_id))
                {
                    // changed, save to DB the gameevent state
                    SaveWorldEventStateToDB(event_id);
                    // force update events to set timer
                    sWorld->ForceGameEventUpdate();
                }
            }
        }
    }
}

bool GameEventMgr::CheckOneGameEventConditions(uint16 event_id)
{
    for (std::map<uint32,GameEventFinishCondition>::iterator itr = mGameEvent[event_id].conditions.begin(); itr != mGameEvent[event_id].conditions.end(); ++itr)
        if (itr->second.done < itr->second.reqNum)
            // return false if a condition doesn't match
            return false;
    // set the phase
    mGameEvent[event_id].state = GAMEEVENT_WORLD_NEXTPHASE;
    // set the followup events' start time
    if (!mGameEvent[event_id].nextstart)
    {
        time_t currenttime = time(NULL);
        mGameEvent[event_id].nextstart = currenttime + mGameEvent[event_id].length * 60;
    }
    return true;
}

void GameEventMgr::SaveWorldEventStateToDB(uint16 event_id)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    trans->PAppend("DELETE FROM game_event_save WHERE event_id = '%u'",event_id);
    if (mGameEvent[event_id].nextstart)
        trans->PAppend("INSERT INTO game_event_save (event_id, state, next_start) VALUES ('%u','%u', "UI64FMTD")",event_id,mGameEvent[event_id].state,(uint64)(mGameEvent[event_id].nextstart));
    else
        trans->PAppend("INSERT INTO game_event_save (event_id, state, next_start) VALUES ('%u','%u','0')",event_id,mGameEvent[event_id].state);
    CharacterDatabase.CommitTransaction(trans);
}

void GameEventMgr::SendWorldStateUpdate(Player * plr, uint16 event_id)
{
    std::map<uint32,GameEventFinishCondition>::iterator itr;
    for (itr = mGameEvent[event_id].conditions.begin(); itr !=mGameEvent[event_id].conditions.end(); ++itr)
    {
        if (itr->second.done_world_state)
            plr->SendUpdateWorldState(itr->second.done_world_state, (uint32)(itr->second.done));
        if (itr->second.max_world_state)
            plr->SendUpdateWorldState(itr->second.max_world_state, (uint32)(itr->second.reqNum));
    }
}

bool IsHolidayActive(HolidayIds id)
{
    if (id == HOLIDAY_NONE)
        return false;

    GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
    GameEventMgr::ActiveEvents const& ae = sGameEventMgr->GetActiveEventList();

    for (GameEventMgr::ActiveEvents::const_iterator itr = ae.begin(); itr != ae.end(); ++itr)
        if (events[*itr].holiday_id == id)
            return true;

    return false;
}

 bool IsEventActive(uint16 event_id)
{
    GameEventMgr::ActiveEvents const& ae = sGameEventMgr->GetActiveEventList();
    return ae.find(event_id) != ae.end();
}
