/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#include "GameEventMgr.h"
#include "World.h"
#include "ObjectMgr.h"
#include "PoolHandler.h"
#include "ProgressBar.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "Policies/SingletonImp.h"
#include "GossipDef.h"
#include "Player.h"
#include "BattleGroundMgr.h"

INSTANTIATE_SINGLETON_1(GameEventMgr);

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
            for(std::set<uint16>::const_iterator itr = mGameEvent[entry].prerequisite_events.begin(); itr != mGameEvent[entry].prerequisite_events.end(); ++itr)
            {
                if( (mGameEvent[*itr].state != GAMEEVENT_WORLD_NEXTPHASE && mGameEvent[*itr].state != GAMEEVENT_WORLD_FINISHED) ||   // if prereq not in nextphase or finished state, then can't start this one
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
        return (mGameEvent[entry].nextstart - currenttime);

    // for CONDITIONS state world events, return the length of the wait period, so if the conditions are met, this check will be called again to set the timer as NEXTPHASE event
    if (mGameEvent[entry].state == GAMEEVENT_WORLD_CONDITIONS)
        return mGameEvent[entry].length ? mGameEvent[entry].length * 60 : max_ge_check_delay;

    // outdated event: we return max
    if (currenttime > mGameEvent[entry].end)
        return max_ge_check_delay;

    // never started event, we return delay before start
    if (mGameEvent[entry].start > currenttime)
        return (mGameEvent[entry].start - currenttime);

    uint32 delay;
    // in event, we return the end of it
    if ((((currenttime - mGameEvent[entry].start) % (mGameEvent[entry].occurence * 60)) < (mGameEvent[entry].length * 60)))
        // we return the delay before it ends
        delay = (mGameEvent[entry].length * MINUTE) - ((currenttime - mGameEvent[entry].start) % (mGameEvent[entry].occurence * MINUTE));
    else                                                    // not in window, we return the delay before next start
        delay = (mGameEvent[entry].occurence * MINUTE) - ((currenttime - mGameEvent[entry].start) % (mGameEvent[entry].occurence * MINUTE));
    // In case the end is before next check
    if (mGameEvent[entry].end  < time_t(currenttime + delay))
        return (mGameEvent[entry].end - currenttime);
    else
        return delay;
}

void GameEventMgr::StartInternalEvent(uint16 event_id)
{
    if(event_id < 1 || event_id >= mGameEvent.size())
        return;

    if(!mGameEvent[event_id].isValid())
        return;

    if(m_ActiveEvents.find(event_id) != m_ActiveEvents.end())
        return;

    StartEvent(event_id);
}

bool GameEventMgr::StartEvent( uint16 event_id, bool overwrite )
{
    if(mGameEvent[event_id].state == GAMEEVENT_NORMAL
        || mGameEvent[event_id].state == GAMEEVENT_INTERNAL)
    {
        AddActiveEvent(event_id);
        ApplyNewEvent(event_id);
        if(overwrite)
        {
            mGameEvent[event_id].start = time(NULL);
            if(mGameEvent[event_id].end <= mGameEvent[event_id].start)
                mGameEvent[event_id].end = mGameEvent[event_id].start+mGameEvent[event_id].length;
        }
        return false;
    }
    else
    {
        if( mGameEvent[event_id].state == GAMEEVENT_WORLD_INACTIVE )
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
        if(overwrite && conditions_met)
            sWorld.ForceGameEventUpdate();

        return conditions_met;
    }
}

void GameEventMgr::StopEvent( uint16 event_id, bool overwrite )
{
    bool serverwide_evt = mGameEvent[event_id].state != GAMEEVENT_NORMAL && mGameEvent[event_id].state != GAMEEVENT_INTERNAL;

    RemoveActiveEvent(event_id);
    UnApplyEvent(event_id);

    if(overwrite && !serverwide_evt)
    {
        mGameEvent[event_id].start = time(NULL) - mGameEvent[event_id].length * MINUTE;
        if(mGameEvent[event_id].end <= mGameEvent[event_id].start)
            mGameEvent[event_id].end = mGameEvent[event_id].start+mGameEvent[event_id].length;
    }
    else if(serverwide_evt)
    {
        // if finished world event, then only gm command can stop it
        if(overwrite || mGameEvent[event_id].state != GAMEEVENT_WORLD_FINISHED)
        {
            // reset conditions
            mGameEvent[event_id].nextstart = 0;
            mGameEvent[event_id].state = GAMEEVENT_WORLD_INACTIVE;
            std::map<uint32 /*condition id*/, GameEventFinishCondition>::iterator itr;
            for(itr = mGameEvent[event_id].conditions.begin(); itr != mGameEvent[event_id].conditions.end(); ++itr)
                itr->second.done = 0;
            CharacterDatabase.BeginTransaction();
            CharacterDatabase.PExecute("DELETE FROM game_event_save WHERE event_id = '%u'",event_id);
            CharacterDatabase.PExecute("DELETE FROM game_event_condition_save WHERE event_id = '%u'",event_id);
            CharacterDatabase.CommitTransaction();
        }
    }
}

void GameEventMgr::LoadFromDB()
{
    {
        QueryResult *result = WorldDatabase.Query("SELECT MAX(entry) FROM game_event");
        if( !result )
        {
            sLog.outString(">> Table game_event is empty.");
            sLog.outString();
            return;
        }

        Field *fields = result->Fetch();

        uint32 max_event_id = fields[0].GetUInt16();
        delete result;

        mGameEvent.resize(max_event_id+1);
    }

    QueryResult *result = WorldDatabase.Query("SELECT entry,UNIX_TIMESTAMP(start_time),UNIX_TIMESTAMP(end_time),occurence,length,holiday,description,world_event FROM game_event");
    if( !result )
    {
        mGameEvent.clear();
        sLog.outString(">> Table game_event is empty!");
        sLog.outString();
        return;
    }

    uint32 count = 0;

    {
        barGoLink bar( result->GetRowCount() );
        do
        {
            ++count;
            Field *fields = result->Fetch();

            bar.step();

            uint16 event_id = fields[0].GetUInt16();
            if(event_id==0)
            {
                sLog.outErrorDb("`game_event` game event id (%i) is reserved and can't be used.",event_id);
                continue;
            }

            GameEventData& pGameEvent = mGameEvent[event_id];
            uint64 starttime        = fields[1].GetUInt64();
            pGameEvent.start        = time_t(starttime);
            uint64 endtime          = fields[2].GetUInt64();
            pGameEvent.end          = time_t(endtime);
            pGameEvent.occurence    = fields[3].GetUInt32();
            pGameEvent.length       = fields[4].GetUInt32();
            pGameEvent.holiday_id   = fields[5].GetUInt32();

            pGameEvent.state        = (GameEventState)(fields[7].GetUInt8());
            pGameEvent.nextstart    = 0;

            if(pGameEvent.length==0 && pGameEvent.state == GAMEEVENT_NORMAL)                            // length>0 is validity check
            {
                sLog.outErrorDb("`game_event` game event id (%i) isn't a world event and has length = 0, thus it can't be used.",event_id);
                continue;
            }

            if(pGameEvent.holiday_id)
            {
                if(!sHolidaysStore.LookupEntry(pGameEvent.holiday_id))
                {
                    sLog.outErrorDb("`game_event` game event id (%i) have not existed holiday id %u.",event_id,pGameEvent.holiday_id);
                    pGameEvent.holiday_id = 0;
                }
            }

            pGameEvent.description  = fields[6].GetCppString();

        } while( result->NextRow() );
        delete result;

        sLog.outString();
        sLog.outString( ">> Loaded %u game events", count );
    }

    // load game event saves
    //                                       0         1      2
    result = CharacterDatabase.Query("SELECT event_id, state, UNIX_TIMESTAMP(next_start) FROM game_event_save");

    count = 0;
    if( !result )
    {
        barGoLink bar2(1);
        bar2.step();

        sLog.outString();
        sLog.outString(">> Loaded %u game event saves in game events", count );
    }
    else
    {

        barGoLink bar2( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar2.step();

            uint16 event_id = fields[0].GetUInt16();

            if(event_id >= mGameEvent.size())
            {
                sLog.outErrorDb("`game_event_save` game event id (%i) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            if(mGameEvent[event_id].state != GAMEEVENT_NORMAL && mGameEvent[event_id].state != GAMEEVENT_INTERNAL)
            {
                mGameEvent[event_id].state = (GameEventState)(fields[1].GetUInt8());
                mGameEvent[event_id].nextstart    = time_t(fields[2].GetUInt64());
            }
            else
            {
                sLog.outErrorDb("game_event_save includes event save for non-worldevent id %u",event_id);
                continue;
            }

            ++count;

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u game event saves in game events", count );
        delete result;
    }

    // load game event links (prerequisites)
    result = WorldDatabase.Query("SELECT event_id, prerequisite_event FROM game_event_prerequisite");
    if( !result )
    {
        barGoLink bar2(1);
        bar2.step();

        sLog.outString();
        sLog.outString(">> Loaded %u game event prerequisites in game events", count );
    }
    else
    {

        barGoLink bar2( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar2.step();

            uint16 event_id = fields[0].GetUInt16();

            if(event_id >= mGameEvent.size())
            {
                sLog.outErrorDb("`game_event_prerequisite` game event id (%i) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }


            if(mGameEvent[event_id].state != GAMEEVENT_NORMAL && mGameEvent[event_id].state != GAMEEVENT_INTERNAL)
            {
                uint16 prerequisite_event = fields[1].GetUInt16();
                if(prerequisite_event >= mGameEvent.size())
                {
                    sLog.outErrorDb("`game_event_prerequisite` game event prerequisite id (%i) is out of range compared to max event id in `game_event`",prerequisite_event);
                    continue;
                }
                mGameEvent[event_id].prerequisite_events.insert(prerequisite_event);
            }
            else
            {
                sLog.outErrorDb("game_event_prerequisiste includes event entry for non-worldevent id %u",event_id);
                continue;
            }

            ++count;

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u game event prerequisites in game events", count );
        delete result;
    }

    mGameEventCreatureGuids.resize(mGameEvent.size()*2-1);
    //                                   1              2
    result = WorldDatabase.Query("SELECT creature.guid, game_event_creature.event "
        "FROM creature JOIN game_event_creature ON creature.guid = game_event_creature.guid");

    count = 0;
    if( !result )
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded %u creatures in game events", count );
    }
    else
    {

        barGoLink bar( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar.step();

            uint32 guid    = fields[0].GetUInt32();
            int16 event_id = fields[1].GetInt16();

            int32 internal_event_id = mGameEvent.size() + event_id - 1;

            if(internal_event_id < 0 || internal_event_id >= mGameEventCreatureGuids.size())
            {
                sLog.outErrorDb("`game_event_creature` game event id (%i) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            ++count;
            GuidList& crelist = mGameEventCreatureGuids[internal_event_id];
            crelist.push_back(guid);

        } while( result->NextRow() );
        delete result;

        sLog.outString();
        sLog.outString( ">> Loaded %u creatures in game events", count );
    }

    mGameEventGameobjectGuids.resize(mGameEvent.size()*2-1);
    //                                   1                2
    result = WorldDatabase.Query("SELECT gameobject.guid, game_event_gameobject.event "
        "FROM gameobject JOIN game_event_gameobject ON gameobject.guid=game_event_gameobject.guid");

    count = 0;
    if( !result )
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded %u gameobjects in game events", count );
    }
    else
    {

        barGoLink bar( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar.step();

            uint32 guid    = fields[0].GetUInt32();
            int16 event_id = fields[1].GetInt16();

            int32 internal_event_id = mGameEvent.size() + event_id - 1;

            if(internal_event_id < 0 || internal_event_id >= mGameEventGameobjectGuids.size())
            {
                sLog.outErrorDb("`game_event_gameobject` game event id (%i) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            ++count;
            GuidList& golist = mGameEventGameobjectGuids[internal_event_id];
            golist.push_back(guid);

        } while( result->NextRow() );
        delete result;

        sLog.outString();
        sLog.outString( ">> Loaded %u gameobjects in game events", count );
    }

    mGameEventModelEquip.resize(mGameEvent.size());
    //                                   0              1                             2
    result = WorldDatabase.Query("SELECT creature.guid, game_event_model_equip.event, game_event_model_equip.modelid,"
    //   3
        "game_event_model_equip.equipment_id "
        "FROM creature JOIN game_event_model_equip ON creature.guid=game_event_model_equip.guid");

    count = 0;
    if( !result )
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded %u model/equipment changes in game events", count );
    }
    else
    {

        barGoLink bar( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar.step();
            uint32 guid     = fields[0].GetUInt32();
            uint16 event_id = fields[1].GetUInt16();

            if(event_id >= mGameEventModelEquip.size())
            {
                sLog.outErrorDb("`game_event_model_equip` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            ++count;
            ModelEquipList& equiplist = mGameEventModelEquip[event_id];
            ModelEquip newModelEquipSet;
            newModelEquipSet.modelid = fields[2].GetUInt32();
            newModelEquipSet.equipment_id = fields[3].GetUInt32();
            newModelEquipSet.equipement_id_prev = 0;
            newModelEquipSet.modelid_prev = 0;

            if(newModelEquipSet.equipment_id > 0)
            {
                if(!objmgr.GetEquipmentInfo(newModelEquipSet.equipment_id))
                {
                    sLog.outErrorDb("Table `game_event_model_equip` have creature (Guid: %u) with equipment_id %u not found in table `creature_equip_template`, set to no equipment.", guid, newModelEquipSet.equipment_id);
                    continue;
                }
            }

            equiplist.push_back(std::pair<uint32, ModelEquip>(guid, newModelEquipSet));

        } while( result->NextRow() );
        delete result;

        sLog.outString();
        sLog.outString( ">> Loaded %u model/equipment changes in game events", count );
    }

    mGameEventCreatureQuests.resize(mGameEvent.size());
    //                                   0   1      2
    result = WorldDatabase.Query("SELECT id, quest, event FROM game_event_creature_quest");

    count = 0;
    if( !result )
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded %u quests additions in game events", count );
    }
    else
    {

        barGoLink bar( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar.step();
            uint32 id       = fields[0].GetUInt32();
            uint32 quest    = fields[1].GetUInt32();
            uint16 event_id = fields[2].GetUInt16();

            if(event_id >= mGameEventCreatureQuests.size())
            {
                sLog.outErrorDb("`game_event_creature_quest` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            ++count;
            QuestRelList& questlist = mGameEventCreatureQuests[event_id];
            questlist.push_back(QuestRelation(id, quest));

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u quests additions in game events", count );

        delete result;
    }

    mGameEventGameObjectQuests.resize(mGameEvent.size());
    //                                   0   1      2
    result = WorldDatabase.Query("SELECT id, quest, event FROM game_event_gameobject_quest");

    count = 0;
    if( !result )
    {
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u go quests additions in game events", count );
    }
    else
    {

        barGoLink bar3( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar3.step();
            uint32 id       = fields[0].GetUInt32();
            uint32 quest    = fields[1].GetUInt32();
            uint16 event_id = fields[2].GetUInt16();

            if(event_id >= mGameEventGameObjectQuests.size())
            {
                sLog.outErrorDb("`game_event_gameobject_quest` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            ++count;
            QuestRelList& questlist = mGameEventGameObjectQuests[event_id];
            questlist.push_back(QuestRelation(id, quest));

        } while( result->NextRow() );
        delete result;

        sLog.outString();
        sLog.outString( ">> Loaded %u quests additions in game events", count );
    }

    // Load quest to (event,condition) mapping
    //                                   0      1         2             3
    result = WorldDatabase.Query("SELECT quest, event_id, condition_id, num FROM game_event_quest_condition");

    count = 0;
    if( !result )
    {
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u quest event conditions in game events", count );
    }
    else
    {

        barGoLink bar3( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar3.step();
            uint32 quest     = fields[0].GetUInt32();
            uint16 event_id  = fields[1].GetUInt16();
            uint32 condition = fields[2].GetUInt32();
            float num       = fields[3].GetFloat();

            if(event_id >= mGameEvent.size())
            {
                sLog.outErrorDb("`game_event_quest_condition` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            ++count;
            mQuestToEventConditions[quest].event_id = event_id;
            mQuestToEventConditions[quest].condition = condition;
            mQuestToEventConditions[quest].num = num;

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u quest event conditions in game events", count );

        delete result;
    }

    // load conditions of the events
    //                                   0         1             2        3                      4
    result = WorldDatabase.Query("SELECT event_id, condition_id, req_num, max_world_state_field, done_world_state_field FROM game_event_condition");

    count = 0;
    if( !result )
    {
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u conditions in game events", count );
    }
    else
    {

        barGoLink bar3( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar3.step();
            uint16 event_id  = fields[0].GetUInt16();
            uint32 condition = fields[1].GetUInt32();

            if(event_id >= mGameEvent.size())
            {
                sLog.outErrorDb("`game_event_condition` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            mGameEvent[event_id].conditions[condition].reqNum = fields[2].GetFloat();
            mGameEvent[event_id].conditions[condition].done = 0;
            mGameEvent[event_id].conditions[condition].max_world_state = fields[3].GetUInt32();
            mGameEvent[event_id].conditions[condition].done_world_state = fields[4].GetUInt32();

            ++count;

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u conditions in game events", count );

        delete result;
    }

    // load condition saves
    //                                       0         1             2
    result = CharacterDatabase.Query("SELECT event_id, condition_id, done FROM game_event_condition_save");

    count = 0;
    if( !result )
    {
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u condition saves in game events", count );
    }
    else
    {

        barGoLink bar3( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar3.step();
            uint16 event_id  = fields[0].GetUInt16();
            uint32 condition = fields[1].GetUInt32();

            if(event_id >= mGameEvent.size())
            {
                sLog.outErrorDb("`game_event_condition_save` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            std::map<uint32, GameEventFinishCondition>::iterator itr = mGameEvent[event_id].conditions.find(condition);
            if(itr != mGameEvent[event_id].conditions.end())
            {
                itr->second.done = fields[2].GetFloat();
            }
            else
            {
                sLog.outErrorDb("game_event_condition_save contains not present condition evt id %u cond id %u",event_id, condition);
                continue;
            }

            ++count;

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u condition saves in game events", count );

        delete result;
    }

    mGameEventNPCFlags.resize(mGameEvent.size());
    // load game event npcflag
    //                                   0         1        2
    result = WorldDatabase.Query("SELECT guid, event_id, npcflag FROM game_event_npcflag");

    count = 0;
    if( !result )
    {
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u npcflags in game events", count );
    }
    else
    {

        barGoLink bar3( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar3.step();
            uint32 guid     = fields[0].GetUInt32();
            uint16 event_id = fields[1].GetUInt16();
            uint32 npcflag  = fields[2].GetUInt32();

            if(event_id >= mGameEvent.size())
            {
                sLog.outErrorDb("`game_event_npcflag` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            mGameEventNPCFlags[event_id].push_back(GuidNPCFlagPair(guid,npcflag));

            ++count;

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u npcflags in game events", count );

        delete result;
    }

    mGameEventVendors.resize(mGameEvent.size());
    //                                   0      1      2     3         4         5
    result = WorldDatabase.Query("SELECT event, guid, item, maxcount, incrtime, ExtendedCost FROM game_event_npc_vendor");

    count = 0;
    if( !result )
    {
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u vendor additions in game events", count );
    }
    else
    {

        barGoLink bar3( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar3.step();
            uint16 event_id  = fields[0].GetUInt16();

            if(event_id >= mGameEventVendors.size())
            {
                sLog.outErrorDb("`game_event_npc_vendor` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            NPCVendorList& vendors = mGameEventVendors[event_id];
            NPCVendorEntry newEntry;
            uint32 guid = fields[1].GetUInt32();
            newEntry.item = fields[2].GetUInt32();
            newEntry.maxcount = fields[3].GetUInt32();
            newEntry.incrtime = fields[4].GetUInt32();
            newEntry.ExtendedCost = fields[5].GetUInt32();
            // get the event npc flag for checking if the npc will be vendor during the event or not
            uint32 event_npc_flag = 0;
            NPCFlagList& flist = mGameEventNPCFlags[event_id];
            for(NPCFlagList::const_iterator itr = flist.begin(); itr != flist.end(); ++itr)
            {
                if(itr->first == guid)
                {
                    event_npc_flag = itr->second;
                    break;
                }
            }
            // get creature entry
            newEntry.entry = 0;

            if( CreatureData const* data = objmgr.GetCreatureData(guid) )
                newEntry.entry = data->id;

            // check validity with event's npcflag
            if(!objmgr.IsVendorItemValid(newEntry.entry, newEntry.item, newEntry.maxcount, newEntry.incrtime, newEntry.ExtendedCost, NULL, NULL, event_npc_flag))
                continue;
            ++count;
            vendors.push_back(newEntry);

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u vendor additions in game events", count );

        delete result;
    }

    // load game event npc gossip ids
    //                                   0         1        2
    result = WorldDatabase.Query("SELECT guid, event_id, textid FROM game_event_npc_gossip");

    count = 0;
    if( !result )
    {
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u npc gossip textids in game events", count );
    }
    else
    {

        barGoLink bar3( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar3.step();
            uint32 guid     = fields[0].GetUInt32();
            uint16 event_id = fields[1].GetUInt16();
            uint32 textid  = fields[2].GetUInt32();

            if(event_id >= mGameEvent.size())
            {
                sLog.outErrorDb("`game_event_npc_gossip` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            mNPCGossipIds[guid]=EventNPCGossipIdPair(event_id, textid);

            ++count;

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u npc gossip textids in game events", count );

        delete result;
    }

    // set all flags to 0
    mGameEventBattleGroundHolidays.resize(mGameEvent.size(),0);
    // load game event battleground flags
    //                                   0     1
    result = WorldDatabase.Query("SELECT event, bgflag FROM game_event_battleground_holiday");

    count = 0;
    if( !result )
    {
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u battleground holidays in game events", count );
    }
    else
    {

        barGoLink bar3( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar3.step();

            uint16 event_id = fields[0].GetUInt16();

            if(event_id >= mGameEvent.size())
            {
                sLog.outErrorDb("`game_event_battleground_holiday` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            ++count;

            mGameEventBattleGroundHolidays[event_id] = fields[1].GetUInt32();

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u battleground holidays in game events", count );

        delete result;
    }

    ////////////////////////
    // GameEventPool
    ////////////////////////

    mGameEventPoolIds.resize(mGameEvent.size()*2-1);
    //                                   1                    2
    result = WorldDatabase.Query("SELECT pool_template.entry, game_event_pool.event "
        "FROM pool_template JOIN game_event_pool ON pool_template.entry = game_event_pool.pool_entry");

    count = 0;
    if( !result )
    {
        barGoLink bar2(1);
        bar2.step();

        sLog.outString();
        sLog.outString(">> Loaded %u pools in game events", count );
    }
    else
    {

        barGoLink bar2( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar2.step();

            uint32 entry   = fields[0].GetUInt16();
            int16 event_id = fields[1].GetInt16();

            int32 internal_event_id = mGameEvent.size() + event_id - 1;

            if(internal_event_id < 0 || internal_event_id >= mGameEventPoolIds.size())
            {
                sLog.outErrorDb("`game_event_pool` game event id (%i) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            if (!poolhandler.CheckPool(entry))
            {
                sLog.outErrorDb("Pool Id (%u) has all creatures or gameobjects with explicit chance sum <>100 and no equal chance defined. The pool system cannot pick one to spawn.", entry);
                continue;
            }

            ++count;
            IdList& poollist = mGameEventPoolIds[internal_event_id];
            poollist.push_back(entry);

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u pools in game events", count );
        delete result;
    }
}

uint32 GameEventMgr::GetNPCFlag(Creature * cr)
{
    uint32 mask = 0;
    uint32 guid = cr->GetDBTableGUIDLow();

    for(ActiveEvents::iterator e_itr = m_ActiveEvents.begin(); e_itr != m_ActiveEvents.end(); ++e_itr)
    {
        for(NPCFlagList::iterator itr = mGameEventNPCFlags[*e_itr].begin();
            itr != mGameEventNPCFlags[*e_itr].end();
            ++ itr)
            if(itr->first == guid)
                mask |= itr->second;
    }

    return mask;
}

uint32 GameEventMgr::GetNpcTextId(uint32 guid)
{
    GuidEventNpcGossipIdMap::iterator itr = mNPCGossipIds.find(guid);
    if(itr != mNPCGossipIds.end())
        if(IsActiveEvent(itr->second.first))
            return itr->second.second;
    return 0;
}

uint32 GameEventMgr::Initialize()                           // return the next event delay in ms
{
    m_ActiveEvents.clear();
    uint32 delay = Update();
    sLog.outBasic("Game Event system initialized." );
    isSystemInit = true;
    return delay;
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
        //sLog.outErrorDb("Checking event %u",itr);
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
                if(IsActiveEvent(itr))
                    deactivate.insert(itr);
                // go to next event, this no longer needs an event update timer
                continue;
            }
            else if (mGameEvent[itr].state == GAMEEVENT_WORLD_CONDITIONS && CheckOneGameEventConditions(itr))
                // changed, save to DB the gameevent state, will be updated in next update cycle
                SaveWorldEventStateToDB(itr);

            //sLog.outDebug("GameEvent %u is active",itr->first);
            // queue for activation
            if (!IsActiveEvent(itr))
                activate.insert(itr);
        }
        else
        {
            //sLog.outDebug("GameEvent %u is not active",itr->first);
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
    for(std::set<uint16>::iterator itr = activate.begin(); itr != activate.end(); ++itr)
        // start the event
        // returns true the started event completed
        // in that case, initiate next update in 1 second
        if(StartEvent(*itr))
            nextEventDelay = 0;
    for(std::set<uint16>::iterator itr = deactivate.begin(); itr != deactivate.end(); ++itr)
        StopEvent(*itr);
    sLog.outDetail("Next game event check in %u seconds.", nextEventDelay + 1);
    return (nextEventDelay + 1) * IN_MILISECONDS;           // Add 1 second to be sure event has started/stopped at next call
}

void GameEventMgr::UnApplyEvent(uint16 event_id)
{
    sLog.outString("GameEvent %u \"%s\" removed.", event_id, mGameEvent[event_id].description.c_str());
    // un-spawn positive event tagged objects
    GameEventUnspawn(event_id);
    // spawn negative event tagget objects
    int16 event_nid = (-1) * event_id;
    GameEventSpawn(event_nid);
    // restore equipment or model
    ChangeEquipOrModel(event_id, false);
    // Remove quests that are events only to non event npc
    UpdateEventQuests(event_id, false);
    // update npcflags in this event
    UpdateEventNPCFlags(event_id);
    // remove vendor items
    UpdateEventNPCVendor(event_id, false);
    // update bg holiday
    UpdateBattleGroundSettings();
}

void GameEventMgr::ApplyNewEvent(uint16 event_id)
{
    switch(sWorld.getConfig(CONFIG_EVENT_ANNOUNCE))
    {
        case 0:                                             // disable
            break;
        case 1:                                             // announce events
            sWorld.SendWorldText(LANG_EVENTMESSAGE, mGameEvent[event_id].description.c_str());
            break;
    }

    sLog.outString("GameEvent %u \"%s\" started.", event_id, mGameEvent[event_id].description.c_str());

    // spawn positive event tagget objects
    GameEventSpawn(event_id);
    // un-spawn negative event tagged objects
    int16 event_nid = (-1) * event_id;
    GameEventUnspawn(event_nid);
    // Change equipement or model
    ChangeEquipOrModel(event_id, true);
    // Add quests that are events only to non event npc
    UpdateEventQuests(event_id, true);
    // update npcflags in this event
    UpdateEventNPCFlags(event_id);
    // add vendor items
    UpdateEventNPCVendor(event_id, true);
    // update bg holiday
    UpdateBattleGroundSettings();
}

void GameEventMgr::UpdateEventNPCFlags(uint16 event_id)
{
    // go through the creatures whose npcflags are changed in the event
    for(NPCFlagList::iterator itr = mGameEventNPCFlags[event_id].begin(); itr != mGameEventNPCFlags[event_id].end(); ++itr)
    {
        // get the creature data from the low guid to get the entry, to be able to find out the whole guid
        if( CreatureData const* data = objmgr.GetCreatureData(itr->first) )
        {
            Creature * cr = HashMapHolder<Creature>::Find(MAKE_NEW_GUID(itr->first,data->id,HIGHGUID_UNIT));
            // if we found the creature, modify its npcflag
            if(cr)
            {
                uint32 npcflag = GetNPCFlag(cr);
                if(const CreatureInfo * ci = cr->GetCreatureInfo())
                    npcflag |= ci->npcflag;
                cr->SetUInt32Value(UNIT_NPC_FLAGS,npcflag);
                // reset gossip options, since the flag change might have added / removed some
                cr->ResetGossipOptions();
                // update to world
                cr->SendUpdateObjectToAllExcept(NULL);
            }
            // if we didn't find it, then the npcflag will be updated when the creature is loaded
        }
    }
}

void GameEventMgr::UpdateBattleGroundSettings()
{
    uint32 mask = 0;
    for(ActiveEvents::const_iterator itr = m_ActiveEvents.begin(); itr != m_ActiveEvents.end(); ++itr )
        mask |= mGameEventBattleGroundHolidays[*itr];
    sBattleGroundMgr.SetHolidayWeekends(mask);
}

void GameEventMgr::UpdateEventNPCVendor(uint16 event_id, bool activate)
{
    for(NPCVendorList::iterator itr = mGameEventVendors[event_id].begin(); itr != mGameEventVendors[event_id].end(); ++itr)
    {
        if(activate)
            objmgr.AddVendorItem(itr->entry, itr->item, itr->maxcount, itr->incrtime, itr->ExtendedCost, false);
        else
            objmgr.RemoveVendorItem(itr->entry, itr->item, false);
    }
}

void GameEventMgr::GameEventSpawn(int16 event_id)
{
    int32 internal_event_id = mGameEvent.size() + event_id - 1;

    if(internal_event_id < 0 || internal_event_id >= mGameEventCreatureGuids.size())
    {
        sLog.outError("GameEventMgr::GameEventSpawn attempt access to out of range mGameEventCreatureGuids element %i (size: %u)",internal_event_id,mGameEventCreatureGuids.size());
        return;
    }

    for (GuidList::iterator itr = mGameEventCreatureGuids[internal_event_id].begin();itr != mGameEventCreatureGuids[internal_event_id].end();++itr)
    {
        // Add to correct cell
        CreatureData const* data = objmgr.GetCreatureData(*itr);
        if (data)
        {
            objmgr.AddCreatureToGrid(*itr, data);

            // Spawn if necessary (loaded grids only)
            Map* map = const_cast<Map*>(MapManager::Instance().GetBaseMap(data->mapid));
            // We use spawn coords to spawn
            if(!map->Instanceable() && !map->IsRemovalGrid(data->posX,data->posY))
            {
                Creature* pCreature = new Creature;
                //sLog.outDebug("Spawning creature %u",*itr);
                if (!pCreature->LoadFromDB(*itr, map))
                {
                    delete pCreature;
                }
                else
                {
                    map->Add(pCreature);
                }
            }
        }
    }

    if(internal_event_id < 0 || internal_event_id >= mGameEventGameobjectGuids.size())
    {
        sLog.outError("GameEventMgr::GameEventSpawn attempt access to out of range mGameEventGameobjectGuids element %i (size: %u)",internal_event_id,mGameEventGameobjectGuids.size());
        return;
    }

    for (GuidList::iterator itr = mGameEventGameobjectGuids[internal_event_id].begin();itr != mGameEventGameobjectGuids[internal_event_id].end();++itr)
    {
        // Add to correct cell
        GameObjectData const* data = objmgr.GetGOData(*itr);
        if (data)
        {
            objmgr.AddGameobjectToGrid(*itr, data);
            // Spawn if necessary (loaded grids only)
            // this base map checked as non-instanced and then only existed
            Map* map = const_cast<Map*>(MapManager::Instance().GetBaseMap(data->mapid));
            // We use current coords to unspawn, not spawn coords since creature can have changed grid
            if(!map->Instanceable() && !map->IsRemovalGrid(data->posX, data->posY))
            {
                GameObject* pGameobject = new GameObject;
                //sLog.outDebug("Spawning gameobject %u", *itr);
                if (!pGameobject->LoadFromDB(*itr, map))
                {
                    delete pGameobject;
                }
                else
                {
                    if(pGameobject->isSpawnedByDefault())
                        map->Add(pGameobject);
                }
            }
        }
    }

    if(internal_event_id < 0 || internal_event_id >= mGameEventPoolIds.size())
    {
        sLog.outError("GameEventMgr::GameEventSpawn attempt access to out of range mGameEventPoolIds element %i (size: %u)",internal_event_id,mGameEventPoolIds.size());
        return;
    }

    for (IdList::iterator itr = mGameEventPoolIds[internal_event_id].begin();itr != mGameEventPoolIds[internal_event_id].end();++itr)
    {
        poolhandler.SpawnPool(*itr);
    }
}

void GameEventMgr::GameEventUnspawn(int16 event_id)
{
    int32 internal_event_id = mGameEvent.size() + event_id - 1;

    if(internal_event_id < 0 || internal_event_id >= mGameEventCreatureGuids.size())
    {
        sLog.outError("GameEventMgr::GameEventUnspawn attempt access to out of range mGameEventCreatureGuids element %i (size: %u)",internal_event_id,mGameEventCreatureGuids.size());
        return;
    }

    for (GuidList::iterator itr = mGameEventCreatureGuids[internal_event_id].begin();itr != mGameEventCreatureGuids[internal_event_id].end();++itr)
    {
        // check if it's needed by another event, if so, don't remove
        if( event_id > 0 && hasCreatureActiveEventExcept(*itr,event_id) )
            continue;
        // Remove the creature from grid
        if( CreatureData const* data = objmgr.GetCreatureData(*itr) )
        {
            objmgr.RemoveCreatureFromGrid(*itr, data);

            if( Creature* pCreature = ObjectAccessor::Instance().GetObjectInWorld(MAKE_NEW_GUID(*itr, data->id, HIGHGUID_UNIT), (Creature*)NULL) )
            {
                pCreature->CleanupsBeforeDelete();
                pCreature->AddObjectToRemoveList();
            }
        }
    }

    if(internal_event_id < 0 || internal_event_id >= mGameEventGameobjectGuids.size())
    {
        sLog.outError("GameEventMgr::GameEventUnspawn attempt access to out of range mGameEventGameobjectGuids element %i (size: %u)",internal_event_id,mGameEventGameobjectGuids.size());
        return;
    }

    for (GuidList::iterator itr = mGameEventGameobjectGuids[internal_event_id].begin();itr != mGameEventGameobjectGuids[internal_event_id].end();++itr)
    {
        // check if it's needed by another event, if so, don't remove
        if( event_id >0 && hasGameObjectActiveEventExcept(*itr,event_id) )
            continue;
        // Remove the gameobject from grid
        if(GameObjectData const* data = objmgr.GetGOData(*itr))
        {
            objmgr.RemoveGameobjectFromGrid(*itr, data);

            if( GameObject* pGameobject = ObjectAccessor::Instance().GetObjectInWorld(MAKE_NEW_GUID(*itr, data->id, HIGHGUID_GAMEOBJECT), (GameObject*)NULL) )
                pGameobject->AddObjectToRemoveList();
        }
    }
    if(internal_event_id < 0 || internal_event_id >= mGameEventPoolIds.size())
    {
        sLog.outError("GameEventMgr::GameEventUnspawn attempt access to out of range mGameEventPoolIds element %i (size: %u)",internal_event_id,mGameEventPoolIds.size());
        return;
    }

    for (IdList::iterator itr = mGameEventPoolIds[internal_event_id].begin();itr != mGameEventPoolIds[internal_event_id].end();++itr)
    {
        poolhandler.DespawnPool(*itr);
    }
}

void GameEventMgr::ChangeEquipOrModel(int16 event_id, bool activate)
{
    for(ModelEquipList::iterator itr = mGameEventModelEquip[event_id].begin();itr != mGameEventModelEquip[event_id].end();++itr)
    {
        // Remove the creature from grid
        CreatureData const* data = objmgr.GetCreatureData(itr->first);
        if(!data)
            continue;

        // Update if spawned
        Creature* pCreature = ObjectAccessor::Instance().GetObjectInWorld(MAKE_NEW_GUID(itr->first, data->id,HIGHGUID_UNIT), (Creature*)NULL);
        if (pCreature)
        {
            if (activate)
            {
                itr->second.equipement_id_prev = pCreature->GetCurrentEquipmentId();
                itr->second.modelid_prev = pCreature->GetDisplayId();
                pCreature->LoadEquipment(itr->second.equipment_id, true);
                if (itr->second.modelid >0 && itr->second.modelid_prev != itr->second.modelid)
                {
                    CreatureModelInfo const *minfo = objmgr.GetCreatureModelInfo(itr->second.modelid);
                    if (minfo)
                    {
                        pCreature->SetDisplayId(itr->second.modelid);
                        pCreature->SetNativeDisplayId(itr->second.modelid);
                        pCreature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS,minfo->bounding_radius);
                        pCreature->SetFloatValue(UNIT_FIELD_COMBATREACH,minfo->combat_reach );
                    }
                }
            }
            else
            {
                pCreature->LoadEquipment(itr->second.equipement_id_prev, true);
                if (itr->second.modelid_prev >0 && itr->second.modelid_prev != itr->second.modelid)
                {
                    CreatureModelInfo const *minfo = objmgr.GetCreatureModelInfo(itr->second.modelid_prev);
                    if (minfo)
                    {
                        pCreature->SetDisplayId(itr->second.modelid_prev);
                        pCreature->SetNativeDisplayId(itr->second.modelid_prev);
                        pCreature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS,minfo->bounding_radius);
                        pCreature->SetFloatValue(UNIT_FIELD_COMBATREACH,minfo->combat_reach );
                    }
                }
            }
        }
        else                                                // If not spawned
        {
            CreatureData const* data2 = objmgr.GetCreatureData(itr->first);
            if (data2 && activate)
            {
                CreatureInfo const *cinfo = objmgr.GetCreatureTemplate(data2->id);
                uint32 display_id = objmgr.ChooseDisplayId(0,cinfo,data2);
                CreatureModelInfo const *minfo = objmgr.GetCreatureModelRandomGender(display_id);
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
        CreatureData& data2 = objmgr.NewOrExistCreatureData(itr->first);
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
    for(ActiveEvents::iterator e_itr = m_ActiveEvents.begin(); e_itr != m_ActiveEvents.end(); ++e_itr)
    {
        if((*e_itr) != event_id)
            for(QuestRelList::iterator itr = mGameEventCreatureQuests[*e_itr].begin();
                itr != mGameEventCreatureQuests[*e_itr].end();
                ++ itr)
                if(itr->second == quest_id)
                    return true;
    }
    return false;
}

bool GameEventMgr::hasGameObjectQuestActiveEventExcept(uint32 quest_id, uint16 event_id)
{
    for(ActiveEvents::iterator e_itr = m_ActiveEvents.begin(); e_itr != m_ActiveEvents.end(); ++e_itr)
    {
        if((*e_itr) != event_id)
            for(QuestRelList::iterator itr = mGameEventGameObjectQuests[*e_itr].begin();
                itr != mGameEventGameObjectQuests[*e_itr].end();
                ++ itr)
                if(itr->second == quest_id)
                    return true;
    }
    return false;
}
bool GameEventMgr::hasCreatureActiveEventExcept(uint32 creature_id, uint16 event_id)
{
    for(ActiveEvents::iterator e_itr = m_ActiveEvents.begin(); e_itr != m_ActiveEvents.end(); ++e_itr)
    {
        if((*e_itr) != event_id)
        {
            int32 internal_event_id = mGameEvent.size() + (*e_itr) - 1;
            for(GuidList::iterator itr = mGameEventCreatureGuids[internal_event_id].begin();
                itr != mGameEventCreatureGuids[internal_event_id].end();
                ++ itr)
                if(*itr == creature_id)
                    return true;
        }
    }
    return false;
}
bool GameEventMgr::hasGameObjectActiveEventExcept(uint32 go_id, uint16 event_id)
{
    for(ActiveEvents::iterator e_itr = m_ActiveEvents.begin(); e_itr != m_ActiveEvents.end(); ++e_itr)
    {
        if((*e_itr) != event_id)
        {
            int32 internal_event_id = mGameEvent.size() + (*e_itr) - 1;
            for(GuidList::iterator itr = mGameEventGameobjectGuids[internal_event_id].begin();
                itr != mGameEventGameobjectGuids[internal_event_id].end();
                ++ itr)
                if(*itr == go_id)
                    return true;
        }
    }
    return false;
}

void GameEventMgr::UpdateEventQuests(uint16 event_id, bool Activate)
{
    QuestRelList::iterator itr;
    for (itr = mGameEventCreatureQuests[event_id].begin();itr != mGameEventCreatureQuests[event_id].end();++itr)
    {
        QuestRelations &CreatureQuestMap = objmgr.mCreatureQuestRelations;
        if (Activate)                                       // Add the pair(id,quest) to the multimap
            CreatureQuestMap.insert(QuestRelations::value_type(itr->first, itr->second));
        else
        {
            if(!hasCreatureQuestActiveEventExcept(itr->second,event_id))
            {
                // Remove the pair(id,quest) from the multimap
                QuestRelations::iterator qitr = CreatureQuestMap.find(itr->first);
                if (qitr == CreatureQuestMap.end())
                    continue;
                QuestRelations::iterator lastElement = CreatureQuestMap.upper_bound(itr->first);
                for ( ;qitr != lastElement;++qitr)
                {
                    if (qitr->second == itr->second)
                    {
                        CreatureQuestMap.erase(qitr);           // iterator is now no more valid
                        break;                                  // but we can exit loop since the element is found
                    }
                }
            }
        }
    }
    for (itr = mGameEventGameObjectQuests[event_id].begin();itr != mGameEventGameObjectQuests[event_id].end();++itr)
    {
        QuestRelations &GameObjectQuestMap = objmgr.mGOQuestRelations;
        if (Activate)                                       // Add the pair(id,quest) to the multimap
            GameObjectQuestMap.insert(QuestRelations::value_type(itr->first, itr->second));
        else
        {
            if(!hasGameObjectQuestActiveEventExcept(itr->second,event_id))
            {
                // Remove the pair(id,quest) from the multimap
                QuestRelations::iterator qitr = GameObjectQuestMap.find(itr->first);
                if (qitr == GameObjectQuestMap.end())
                    continue;
                QuestRelations::iterator lastElement = GameObjectQuestMap.upper_bound(itr->first);
                for ( ;qitr != lastElement;++qitr)
                {
                    if (qitr->second == itr->second)
                    {
                        GameObjectQuestMap.erase(qitr);           // iterator is now no more valid
                        break;                                  // but we can exit loop since the element is found
                    }
                }
            }
        }
    }}

GameEventMgr::GameEventMgr()
{
    isSystemInit = false;
}

void GameEventMgr::HandleQuestComplete(uint32 quest_id)
{
    // translate the quest to event and condition
    QuestIdToEventConditionMap::iterator itr = mQuestToEventConditions.find(quest_id);
    // quest is registered
    if(itr != mQuestToEventConditions.end())
    {
        uint16 event_id = itr->second.event_id;
        uint32 condition = itr->second.condition;
        float num = itr->second.num;

        // the event is not active, so return, don't increase condition finishes
        if(!IsActiveEvent(event_id))
            return;
        // not in correct phase, return
        if(mGameEvent[event_id].state != GAMEEVENT_WORLD_CONDITIONS)
            return;
        std::map<uint32,GameEventFinishCondition>::iterator citr = mGameEvent[event_id].conditions.find(condition);
        // condition is registered
        if(citr != mGameEvent[event_id].conditions.end())
        {
            // increase the done count, only if less then the req
            if(citr->second.done < citr->second.reqNum)
            {
                citr->second.done += num;
                // check max limit
                if(citr->second.done > citr->second.reqNum)
                    citr->second.done = citr->second.reqNum;
                // save the change to db
                CharacterDatabase.BeginTransaction();
                CharacterDatabase.PExecute("DELETE FROM game_event_condition_save WHERE event_id = '%u' AND condition_id = '%u'",event_id,condition);
                CharacterDatabase.PExecute("INSERT INTO game_event_condition_save (event_id, condition_id, done) VALUES (%u,%u,%f)",event_id,condition,citr->second.done);
                CharacterDatabase.CommitTransaction();
                // check if all conditions are met, if so, update the event state
                if(CheckOneGameEventConditions(event_id))
                {
                    // changed, save to DB the gameevent state
                    SaveWorldEventStateToDB(event_id);
                    // force update events to set timer
                    sWorld.ForceGameEventUpdate();
                }
            }
        }
    }
}

bool GameEventMgr::CheckOneGameEventConditions(uint16 event_id)
{
    for(std::map<uint32,GameEventFinishCondition>::iterator itr = mGameEvent[event_id].conditions.begin(); itr != mGameEvent[event_id].conditions.end(); ++itr)
        if(itr->second.done < itr->second.reqNum)
            // return false if a condition doesn't match
            return false;
    // set the phase
    mGameEvent[event_id].state = GAMEEVENT_WORLD_NEXTPHASE;
    // set the followup events' start time
    if(!mGameEvent[event_id].nextstart)
    {
        time_t currenttime = time(NULL);
        mGameEvent[event_id].nextstart = currenttime + mGameEvent[event_id].length * 60;
    }
    return true;
}

void GameEventMgr::SaveWorldEventStateToDB(uint16 event_id)
{
    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("DELETE FROM game_event_save WHERE event_id = '%u'",event_id);
    if(mGameEvent[event_id].nextstart)
        CharacterDatabase.PExecute("INSERT INTO game_event_save (event_id, state, next_start) VALUES ('%u','%u',FROM_UNIXTIME("UI64FMTD"))",event_id,mGameEvent[event_id].state,(uint64)(mGameEvent[event_id].nextstart));
    else
        CharacterDatabase.PExecute("INSERT INTO game_event_save (event_id, state, next_start) VALUES ('%u','%u','0000-00-00 00:00:00')",event_id,mGameEvent[event_id].state);
    CharacterDatabase.CommitTransaction();
}

void GameEventMgr::HandleWorldEventGossip(Player *plr, Creature *c)
{
    // this function is used to send world state update before sending gossip menu
    // find the npc's gossip id (if set) in an active game event
    // if present, send the event's world states
    GuidEventNpcGossipIdMap::iterator itr = mNPCGossipIds.find(c->GetDBTableGUIDLow());
    if(itr != mNPCGossipIds.end())
        if(IsActiveEvent(itr->second.first))
            // send world state updates to the player about the progress
            SendWorldStateUpdate(plr, itr->second.first);
}

void GameEventMgr::SendWorldStateUpdate(Player * plr, uint16 event_id)
{
    std::map<uint32,GameEventFinishCondition>::iterator itr;
    for(itr = mGameEvent[event_id].conditions.begin(); itr !=mGameEvent[event_id].conditions.end(); ++itr)
    {
        if(itr->second.done_world_state)
            plr->SendUpdateWorldState(itr->second.done_world_state, (uint32)(itr->second.done));
        if(itr->second.max_world_state)
            plr->SendUpdateWorldState(itr->second.max_world_state, (uint32)(itr->second.reqNum));
    }
}

TRINITY_DLL_SPEC bool IsHolidayActive( HolidayIds id )
{
    GameEventMgr::GameEventDataMap const& events = gameeventmgr.GetEventMap();
    GameEventMgr::ActiveEvents const& ae = gameeventmgr.GetActiveEventList();

    for(GameEventMgr::ActiveEvents::const_iterator itr = ae.begin(); itr != ae.end(); ++itr)
        if(events[*itr].holiday_id==id)
            return true;

    return false;
}
