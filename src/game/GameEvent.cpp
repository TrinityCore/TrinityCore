/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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

#include "GameEvent.h"
#include "World.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "Policies/SingletonImp.h"
#include "IRCClient.h"

INSTANTIATE_SINGLETON_1(GameEvent);

bool GameEvent::CheckOneGameEvent(uint16 entry) const
{
    // Get the event information
    time_t currenttime = time(NULL);
    if( mGameEvent[entry].start < currenttime && currenttime < mGameEvent[entry].end &&
        ((currenttime - mGameEvent[entry].start) % (mGameEvent[entry].occurence * MINUTE)) < (mGameEvent[entry].length * MINUTE) )
        return true;
    else
        return false;
}

uint32 GameEvent::NextCheck(uint16 entry) const
{
    time_t currenttime = time(NULL);

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

void GameEvent::StartEvent( uint16 event_id, bool overwrite )
{
    AddActiveEvent(event_id);
    ApplyNewEvent(event_id);
    if(overwrite)
    {
        mGameEvent[event_id].start = time(NULL);
        if(mGameEvent[event_id].end <= mGameEvent[event_id].start)
            mGameEvent[event_id].end = mGameEvent[event_id].start+mGameEvent[event_id].length;
    }
}

void GameEvent::StopEvent( uint16 event_id, bool overwrite )
{
    RemoveActiveEvent(event_id);
    UnApplyEvent(event_id);
    if(overwrite)
    {
        mGameEvent[event_id].start = time(NULL) - mGameEvent[event_id].length * MINUTE;
        if(mGameEvent[event_id].end <= mGameEvent[event_id].start)
            mGameEvent[event_id].end = mGameEvent[event_id].start+mGameEvent[event_id].length;
    }
}

void GameEvent::LoadFromDB()
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

    QueryResult *result = WorldDatabase.Query("SELECT entry,UNIX_TIMESTAMP(start_time),UNIX_TIMESTAMP(end_time),occurence,length,description FROM game_event");
    if( !result )
    {
        mGameEvent.clear();
        sLog.outString(">> Table game_event is empty:");
        sLog.outString();
        return;
    }

    uint32 count = 0;

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

        if(pGameEvent.length==0)                            // length>0 is validity check
        {
            sLog.outErrorDb("`game_event` game event id (%i) have length 0 and can't be used.",event_id);
            continue;
        }

        pGameEvent.description  = fields[5].GetCppString();

    } while( result->NextRow() );

    sLog.outString();
    sLog.outString( ">> Loaded %u game events", count );
    delete result;

    mGameEventCreatureGuids.resize(mGameEvent.size()*2-1);
    //                                   1              2
    result = WorldDatabase.Query("SELECT creature.guid, game_event_creature.event "
        "FROM creature JOIN game_event_creature ON creature.guid = game_event_creature.guid");

    count = 0;
    if( !result )
    {
        barGoLink bar2(1);
        bar2.step();

        sLog.outString();
        sLog.outString(">> Loaded %u creatures in game events", count );
    }
    else
    {

        barGoLink bar2( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar2.step();

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
        sLog.outString();
        sLog.outString( ">> Loaded %u creatures in game events", count );
        delete result;
    }

    mGameEventGameobjectGuids.resize(mGameEvent.size()*2-1);
    //                                   1                2
    result = WorldDatabase.Query("SELECT gameobject.guid, game_event_gameobject.event "
        "FROM gameobject JOIN game_event_gameobject ON gameobject.guid=game_event_gameobject.guid");

    count = 0;
    if( !result )
    {
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u gameobjects in game events", count );
    }
    else
    {

        barGoLink bar3( result->GetRowCount() );
        do
        {
            Field *fields = result->Fetch();

            bar3.step();

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
        sLog.outString();
        sLog.outString( ">> Loaded %u gameobjects in game events", count );

        delete result;
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
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u model/equipment changes in game events", count );
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
        sLog.outString();
        sLog.outString( ">> Loaded %u model/equipment changes in game events", count );

        delete result;
    }

    mGameEventQuests.resize(mGameEvent.size());
    //                                   0   1      2
    result = WorldDatabase.Query("SELECT id, quest, event FROM game_event_creature_quest");

    count = 0;
    if( !result )
    {
        barGoLink bar3(1);
        bar3.step();

        sLog.outString();
        sLog.outString(">> Loaded %u quests additions in game events", count );
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

            if(event_id >= mGameEventQuests.size())
            {
                sLog.outErrorDb("`game_event_creature_quest` game event id (%u) is out of range compared to max event id in `game_event`",event_id);
                continue;
            }

            ++count;
            QuestRelList& questlist = mGameEventQuests[event_id];
            questlist.push_back(QuestRelation(id, quest));

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u quests additions in game events", count );

        delete result;
    }
}

uint32 GameEvent::Initialize()                              // return the next event delay in ms
{
    m_ActiveEvents.clear();
    uint32 delay = Update();
    sLog.outBasic("Game Event system initialized." );
    isSystemInit = true;
    return delay;
}

uint32 GameEvent::Update()                                  // return the next event delay in ms
{
    uint32 nextEventDelay = max_ge_check_delay;             // 1 day
    uint32 calcDelay;
    for (uint16 itr = 1; itr < mGameEvent.size(); itr++)
    {
        //sLog.outErrorDb("Checking event %u",itr);
        if (CheckOneGameEvent(itr))
        {
            //sLog.outDebug("GameEvent %u is active",itr->first);
            if (!IsActiveEvent(itr))
                StartEvent(itr);
        }
        else
        {
            //sLog.outDebug("GameEvent %u is not active",itr->first);
            if (IsActiveEvent(itr))
                StopEvent(itr);
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
    sLog.outBasic("Next game event check in %u seconds.", nextEventDelay + 1);
    return (nextEventDelay + 1) * 1000;                     // Add 1 second to be sure event has started/stopped at next call
}

void GameEvent::UnApplyEvent(uint16 event_id)
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
}

void GameEvent::ApplyNewEvent(uint16 event_id)
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

    if((sIRC.BOTMASK & 256) != 0)
    {
        std::string ircchan = "#";
        ircchan += sIRC._irc_chan[sIRC.anchn].c_str();
        sIRC.Send_IRC_Channel(ircchan, sIRC.MakeMsg("\00304,08\037/!\\\037\017\00304 Game Event \00304,08\037/!\\\037\017 %s", "%s", mGameEvent[event_id].description.c_str()), true);
    }

    // spawn positive event tagget objects
    GameEventSpawn(event_id);
    // un-spawn negative event tagged objects
    int16 event_nid = (-1) * event_id;
    GameEventUnspawn(event_nid);
    // Change equipement or model
    ChangeEquipOrModel(event_id, true);
    // Add quests that are events only to non event npc
    UpdateEventQuests(event_id, true);
}

void GameEvent::GameEventSpawn(int16 event_id)
{
    int32 internal_event_id = mGameEvent.size() + event_id - 1;

    if(internal_event_id < 0 || internal_event_id >= mGameEventCreatureGuids.size())
    {
        sLog.outError("GameEvent::GameEventSpawn attempt access to out of range mGameEventCreatureGuids element %i (size: %u)",internal_event_id,mGameEventCreatureGuids.size());
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
        sLog.outError("GameEvent::GameEventSpawn attempt access to out of range mGameEventGameobjectGuids element %i (size: %u)",internal_event_id,mGameEventGameobjectGuids.size());
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
}

void GameEvent::GameEventUnspawn(int16 event_id)
{
    int32 internal_event_id = mGameEvent.size() + event_id - 1;

    if(internal_event_id < 0 || internal_event_id >= mGameEventCreatureGuids.size())
    {
        sLog.outError("GameEvent::GameEventUnspawn attempt access to out of range mGameEventCreatureGuids element %i (size: %u)",internal_event_id,mGameEventCreatureGuids.size());
        return;
    }

    for (GuidList::iterator itr = mGameEventCreatureGuids[internal_event_id].begin();itr != mGameEventCreatureGuids[internal_event_id].end();++itr)
    {
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
        sLog.outError("GameEvent::GameEventUnspawn attempt access to out of range mGameEventGameobjectGuids element %i (size: %u)",internal_event_id,mGameEventGameobjectGuids.size());
        return;
    }

    for (GuidList::iterator itr = mGameEventGameobjectGuids[internal_event_id].begin();itr != mGameEventGameobjectGuids[internal_event_id].end();++itr)
    {
        // Remove the gameobject from grid
        if(GameObjectData const* data = objmgr.GetGOData(*itr))
        {
            objmgr.RemoveGameobjectFromGrid(*itr, data);

            if( GameObject* pGameobject = ObjectAccessor::Instance().GetObjectInWorld(MAKE_NEW_GUID(*itr, data->id, HIGHGUID_GAMEOBJECT), (GameObject*)NULL) )
                pGameobject->AddObjectToRemoveList();
        }
    }
}

void GameEvent::ChangeEquipOrModel(int16 event_id, bool activate)
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
            CreatureData const* data = objmgr.GetCreatureData(itr->first);
            if (data && activate)
            {
                CreatureInfo const *cinfo = objmgr.GetCreatureTemplate(data->id);
                uint32 display_id = objmgr.ChooseDisplayId(0,cinfo,data);
                CreatureModelInfo const *minfo = objmgr.GetCreatureModelRandomGender(display_id);
                if (minfo)
                    display_id = minfo->modelid;
                if (data->equipmentId == 0)
                    itr->second.equipement_id_prev = cinfo->equipmentId;
                else if (data->equipmentId != -1)
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

void GameEvent::UpdateEventQuests(uint16 event_id, bool Activate)
{
    QuestRelList::iterator itr;
    for (itr = mGameEventQuests[event_id].begin();itr != mGameEventQuests[event_id].end();++itr)
    {
        QuestRelations &CreatureQuestMap = objmgr.mCreatureQuestRelations;
        if (Activate)                                       // Add the pair(id,quest) to the multimap
            CreatureQuestMap.insert(QuestRelations::value_type(itr->first, itr->second));
        else
        {                                                   // Remove the pair(id,quest) from the multimap
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

GameEvent::GameEvent()
{
    isSystemInit = false;
}
