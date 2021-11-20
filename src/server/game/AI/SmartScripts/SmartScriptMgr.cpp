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

#include "SmartScriptMgr.h"
#include "CreatureTextMgr.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameEventMgr.h"
#include "InstanceScript.h"
#include "Log.h"
#include "MovementDefines.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Timer.h"
#include "UnitDefines.h"
#include "Unit.h"
#include "WaypointDefines.h"

#define TC_SAI_IS_BOOLEAN_VALID(e, value) \
{ \
    if (value > 1) \
    { \
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses param %s of type Boolean with value %u, valid values are 0 or 1, skipped.", \
            e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), STRINGIZE(value), value); \
        return false; \
    } \
}

SmartWaypointMgr* SmartWaypointMgr::instance()
{
    static SmartWaypointMgr instance;
    return &instance;
}

void SmartWaypointMgr::LoadFromDB()
{
    uint32 oldMSTime = getMSTime();

    _waypointStore.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_SMARTAI_WP);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 SmartAI Waypoint Paths. DB table `waypoints` is empty.");

        return;
    }

    uint32 count = 0;
    uint32 total = 0;
    uint32 lastEntry = 0;
    uint32 lastId = 1;

    do
    {
        Field* fields = result->Fetch();
        uint32 entry = fields[0].GetUInt32();
        uint32 id = fields[1].GetUInt32();
        float x = fields[2].GetFloat();
        float y = fields[3].GetFloat();
        float z = fields[4].GetFloat();
        float o = fields[5].GetFloat();
        uint32 delay = fields[6].GetUInt32();

        if (lastEntry != entry)
        {
            lastId = 1;
            ++count;
        }

        if (lastId != id)
            TC_LOG_ERROR("sql.sql", "SmartWaypointMgr::LoadFromDB: Path entry %u, unexpected point id %u, expected %u.", entry, id, lastId);

        ++lastId;

        WaypointPath& path = _waypointStore[entry];
        path.id = entry;
        path.nodes.emplace_back(id, x, y, z, o, delay);

        lastEntry = entry;
        ++total;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u SmartAI waypoint paths (total %u waypoints) in %u ms", count, total, GetMSTimeDiffToNow(oldMSTime));
}

WaypointPath const* SmartWaypointMgr::GetPath(uint32 id)
{
    auto itr = _waypointStore.find(id);
    if (itr != _waypointStore.end())
        return &itr->second;
    return nullptr;
}

SmartAIMgr* SmartAIMgr::instance()
{
    static SmartAIMgr instance;
    return &instance;
}

void SmartAIMgr::LoadSmartAIFromDB()
{
    LoadHelperStores();

    uint32 oldMSTime = getMSTime();

    for (SmartAIEventMap& eventmap : mEventMap)
        eventmap.clear();  //Drop Existing SmartAI List

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_SMART_SCRIPTS);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 SmartAI scripts. DB table `smartai_scripts` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        SmartScriptHolder temp;

        temp.entryOrGuid = fields[0].GetInt32();
        if (!temp.entryOrGuid)
        {
            TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: invalid entryorguid (0), skipped loading.");
            continue;
        }

        SmartScriptType source_type = (SmartScriptType)fields[1].GetUInt8();
        if (source_type >= SMART_SCRIPT_TYPE_MAX)
        {
            TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: invalid source_type (%u), skipped loading.", uint32(source_type));
            continue;
        }
        if (temp.entryOrGuid >= 0)
        {
            switch (source_type)
            {
                case SMART_SCRIPT_TYPE_CREATURE:
                {
                    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate((uint32)temp.entryOrGuid);
                    if (!creatureInfo)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: Creature entry (%u) does not exist, skipped loading.", uint32(temp.entryOrGuid));
                        continue;
                    }

                    if (creatureInfo->AIName != "SmartAI")
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: Creature entry (%u) is not using SmartAI, skipped loading.", uint32(temp.entryOrGuid));
                        continue;
                    }
                    break;
                }
                case SMART_SCRIPT_TYPE_GAMEOBJECT:
                {
                    GameObjectTemplate const* gameObjectInfo = sObjectMgr->GetGameObjectTemplate((uint32)temp.entryOrGuid);
                    if (!gameObjectInfo)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: GameObject entry (%u) does not exist, skipped loading.", uint32(temp.entryOrGuid));
                        continue;
                    }

                    if (gameObjectInfo->AIName != "SmartGameObjectAI")
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: GameObject entry (%u) is not using SmartGameObjectAI, skipped loading.", uint32(temp.entryOrGuid));
                        continue;
                    }
                    break;
                }
                case SMART_SCRIPT_TYPE_AREATRIGGER:
                {
                    if (!sAreaTriggerStore.LookupEntry((uint32)temp.entryOrGuid))
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: AreaTrigger entry (%u) does not exist, skipped loading.", uint32(temp.entryOrGuid));
                        continue;
                    }
                    break;
                }
                case SMART_SCRIPT_TYPE_TIMED_ACTIONLIST:
                    break;//nothing to check, really
                default:
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: not yet implemented source_type %u", (uint32)source_type);
                    continue;
            }
        }
        else
        {
            switch (source_type)
            {
                case SMART_SCRIPT_TYPE_CREATURE:
                {
                    CreatureData const* creature = sObjectMgr->GetCreatureData(uint32(std::abs(temp.entryOrGuid)));
                    if (!creature)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: Creature guid (%u) does not exist, skipped loading.", uint32(std::abs(temp.entryOrGuid)));
                        continue;
                    }

                    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(creature->id);
                    if (!creatureInfo)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: Creature entry (%u) guid (%u) does not exist, skipped loading.", creature->id, uint32(std::abs(temp.entryOrGuid)));
                        continue;
                    }

                    if (creatureInfo->AIName != "SmartAI")
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: Creature entry (%u) guid (%u) is not using SmartAI, skipped loading.", creature->id, uint32(std::abs(temp.entryOrGuid)));
                        continue;
                    }
                    break;
                }
                case SMART_SCRIPT_TYPE_GAMEOBJECT:
                {
                    GameObjectData const* gameObject = sObjectMgr->GetGameObjectData(uint32(std::abs(temp.entryOrGuid)));
                    if (!gameObject)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: GameObject guid (%u) does not exist, skipped loading.", uint32(std::abs(temp.entryOrGuid)));
                        continue;
                    }

                    GameObjectTemplate const* gameObjectInfo = sObjectMgr->GetGameObjectTemplate(gameObject->id);
                    if (!gameObjectInfo)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: GameObject entry (%u) guid (%u) does not exist, skipped loading.", gameObject->id, uint32(std::abs(temp.entryOrGuid)));
                        continue;
                    }

                    if (gameObjectInfo->AIName != "SmartGameObjectAI")
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: GameObject entry (%u) guid (%u) is not using SmartGameObjectAI, skipped loading.", gameObject->id, uint32(std::abs(temp.entryOrGuid)));
                        continue;
                    }
                    break;
                }
                default:
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: GUID-specific scripting not yet implemented for source_type %u", (uint32)source_type);
                    continue;
            }
        }

        temp.source_type = source_type;
        temp.event_id = fields[2].GetUInt16();
        temp.link = fields[3].GetUInt16();
        temp.event.type = (SMART_EVENT)fields[4].GetUInt8();
        temp.event.event_phase_mask = fields[5].GetUInt16();
        temp.event.event_chance = fields[6].GetUInt8();
        temp.event.event_flags = fields[7].GetUInt16();

        temp.event.raw.param1 = fields[8].GetUInt32();
        temp.event.raw.param2 = fields[9].GetUInt32();
        temp.event.raw.param3 = fields[10].GetUInt32();
        temp.event.raw.param4 = fields[11].GetUInt32();
        temp.event.raw.param5 = fields[12].GetUInt32();

        temp.action.type = (SMART_ACTION)fields[13].GetUInt8();
        temp.action.raw.param1 = fields[14].GetUInt32();
        temp.action.raw.param2 = fields[15].GetUInt32();
        temp.action.raw.param3 = fields[16].GetUInt32();
        temp.action.raw.param4 = fields[17].GetUInt32();
        temp.action.raw.param5 = fields[18].GetUInt32();
        temp.action.raw.param6 = fields[19].GetUInt32();

        temp.target.type = (SMARTAI_TARGETS)fields[20].GetUInt8();
        temp.target.raw.param1 = fields[21].GetUInt32();
        temp.target.raw.param2 = fields[22].GetUInt32();
        temp.target.raw.param3 = fields[23].GetUInt32();
        temp.target.raw.param4 = fields[24].GetUInt32();
        temp.target.x = fields[25].GetFloat();
        temp.target.y = fields[26].GetFloat();
        temp.target.z = fields[27].GetFloat();
        temp.target.o = fields[28].GetFloat();

        //check target
        if (!IsTargetValid(temp))
            continue;

        // check all event and action params
        if (!IsEventValid(temp))
            continue;

        // specific check for timed events
        switch (temp.event.type)
        {
            case SMART_EVENT_UPDATE:
            case SMART_EVENT_UPDATE_OOC:
            case SMART_EVENT_UPDATE_IC:
            case SMART_EVENT_HEALTH_PCT:
            case SMART_EVENT_MANA_PCT:
            case SMART_EVENT_RANGE:
            case SMART_EVENT_FRIENDLY_HEALTH_PCT:
            case SMART_EVENT_FRIENDLY_MISSING_BUFF:
            case SMART_EVENT_HAS_AURA:
            case SMART_EVENT_TARGET_BUFFED:
                if (temp.event.minMaxRepeat.repeatMin == 0 && temp.event.minMaxRepeat.repeatMax == 0 && !(temp.event.event_flags & SMART_EVENT_FLAG_NOT_REPEATABLE) && temp.source_type != SMART_SCRIPT_TYPE_TIMED_ACTIONLIST)
                {
                    temp.event.event_flags |= SMART_EVENT_FLAG_NOT_REPEATABLE;
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: Entry %d SourceType %u, Event %u, Missing Repeat flag.",
                        temp.entryOrGuid, temp.GetScriptType(), temp.event_id);
                }
                break;
            case SMART_EVENT_VICTIM_CASTING:
                if (temp.event.minMaxRepeat.min == 0 && temp.event.minMaxRepeat.max == 0 && !(temp.event.event_flags & SMART_EVENT_FLAG_NOT_REPEATABLE) && temp.source_type != SMART_SCRIPT_TYPE_TIMED_ACTIONLIST)
                {
                    temp.event.event_flags |= SMART_EVENT_FLAG_NOT_REPEATABLE;
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: Entry %d SourceType %u, Event %u, Missing Repeat flag.",
                        temp.entryOrGuid, temp.GetScriptType(), temp.event_id);
                }
                break;
            case SMART_EVENT_FRIENDLY_IS_CC:
                if (temp.event.friendlyCC.repeatMin == 0 && temp.event.friendlyCC.repeatMax == 0 && !(temp.event.event_flags & SMART_EVENT_FLAG_NOT_REPEATABLE) && temp.source_type != SMART_SCRIPT_TYPE_TIMED_ACTIONLIST)
                {
                    temp.event.event_flags |= SMART_EVENT_FLAG_NOT_REPEATABLE;
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: Entry %d SourceType %u, Event %u, Missing Repeat flag.",
                        temp.entryOrGuid, temp.GetScriptType(), temp.event_id);
                }
                break;
            default:
                break;
        }

        // creature entry / guid not found in storage, create empty event list for it and increase counters
        if (mEventMap[source_type].find(temp.entryOrGuid) == mEventMap[source_type].end())
        {
            ++count;
            SmartAIEventList eventList;
            mEventMap[source_type][temp.entryOrGuid] = eventList;
        }
        // store the new event
        mEventMap[source_type][temp.entryOrGuid].push_back(temp);
    }
    while (result->NextRow());

    // Post Loading Validation
    for (SmartAIEventMap& eventmap : mEventMap)
    {
        for (std::pair<int32 const, SmartAIEventList>& eventlistpair : eventmap)
        {
            for (SmartScriptHolder const& e : eventlistpair.second)
            {
                if (e.link)
                {
                    if (!FindLinkedEvent(eventlistpair.second, e.link))
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: Entry %d SourceType %u, Event %u, Link Event %u not found or invalid.",
                            e.entryOrGuid, e.GetScriptType(), e.event_id, e.link);
                    }
                }

                if (e.GetEventType() == SMART_EVENT_LINK)
                {
                    if (!FindLinkedSourceEvent(eventlistpair.second, e.event_id))
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr::LoadSmartAIFromDB: Entry %d SourceType %u, Event %u, Link Source Event not found or invalid. Event will never trigger.",
                            e.entryOrGuid, e.GetScriptType(), e.event_id);
                    }
                }
            }
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u SmartAI scripts in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    UnLoadHelperStores();
}

SmartAIEventList SmartAIMgr::GetScript(int32 entry, SmartScriptType type)
{
    SmartAIEventList temp;
    if (mEventMap[uint32(type)].find(entry) != mEventMap[uint32(type)].end())
        return mEventMap[uint32(type)][entry];
    else
    {
        if (entry > 0)//first search is for guid (negative), do not drop error if not found
            TC_LOG_DEBUG("scripts.ai", "SmartAIMgr::GetScript: Could not load Script for Entry %d ScriptType %u.", entry, uint32(type));
        return temp;
    }
}

SmartScriptHolder& SmartAIMgr::FindLinkedSourceEvent(SmartAIEventList& list, uint32 eventId)
{
    SmartAIEventList::iterator itr = std::find_if(list.begin(), list.end(),
        [eventId](SmartScriptHolder& source) { return source.link == eventId; });

    if (itr != list.end())
        return *itr;

    static SmartScriptHolder SmartScriptHolderDummy;
    return SmartScriptHolderDummy;
}

SmartScriptHolder& SmartAIMgr::FindLinkedEvent(SmartAIEventList& list, uint32 link)
{
    SmartAIEventList::iterator itr = std::find_if(list.begin(), list.end(),
        [link](SmartScriptHolder& linked) { return linked.event_id == link && linked.GetEventType() == SMART_EVENT_LINK; });

    if (itr != list.end())
        return *itr;

    static SmartScriptHolder SmartScriptHolderDummy;
    return SmartScriptHolderDummy;
}

/*static*/ bool SmartAIMgr::EventHasInvoker(SMART_EVENT event)
{
    switch (event)
    { // white list of events that actually have an invoker passed to them
        case SMART_EVENT_AGGRO:
        case SMART_EVENT_DEATH:
        case SMART_EVENT_KILL:
        case SMART_EVENT_SUMMONED_UNIT:
        case SMART_EVENT_SUMMONED_UNIT_DIES:
        case SMART_EVENT_SPELLHIT:
        case SMART_EVENT_SPELLHIT_TARGET:
        case SMART_EVENT_DAMAGED:
        case SMART_EVENT_RECEIVE_HEAL:
        case SMART_EVENT_RECEIVE_EMOTE:
        case SMART_EVENT_JUST_SUMMONED:
        case SMART_EVENT_DAMAGED_TARGET:
        case SMART_EVENT_SUMMON_DESPAWNED:
        case SMART_EVENT_PASSENGER_BOARDED:
        case SMART_EVENT_PASSENGER_REMOVED:
        case SMART_EVENT_GOSSIP_HELLO:
        case SMART_EVENT_GOSSIP_SELECT:
        case SMART_EVENT_ACCEPTED_QUEST:
        case SMART_EVENT_REWARD_QUEST:
        case SMART_EVENT_FOLLOW_COMPLETED:
        case SMART_EVENT_ON_SPELLCLICK:
        case SMART_EVENT_GO_LOOT_STATE_CHANGED:
        case SMART_EVENT_AREATRIGGER_ONTRIGGER:
        case SMART_EVENT_IC_LOS:
        case SMART_EVENT_OOC_LOS:
        case SMART_EVENT_DISTANCE_CREATURE:
        case SMART_EVENT_FRIENDLY_HEALTH_PCT:
        case SMART_EVENT_FRIENDLY_IS_CC:
        case SMART_EVENT_FRIENDLY_MISSING_BUFF:
        case SMART_EVENT_ACTION_DONE:
        case SMART_EVENT_RANGE:
        case SMART_EVENT_VICTIM_CASTING:
        case SMART_EVENT_TARGET_BUFFED:
        case SMART_EVENT_INSTANCE_PLAYER_ENTER:
        case SMART_EVENT_TRANSPORT_ADDCREATURE:
        case SMART_EVENT_DATA_SET:
            return true;
        default:
            return false;
    }
}

bool SmartAIMgr::IsTargetValid(SmartScriptHolder const& e)
{
    if (std::abs(e.target.o) > 2 * float(M_PI))
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u has abs(`target.o` = %f) > 2*PI (orientation is expressed in radians)",
            e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.target.o);

    switch (e.GetTargetType())
    {
        case SMART_TARGET_CREATURE_DISTANCE:
        case SMART_TARGET_CREATURE_RANGE:
        {
            if (e.target.unitDistance.creature && !sObjectMgr->GetCreatureTemplate(e.target.unitDistance.creature))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Creature entry %u as target_param1, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.target.unitDistance.creature);
                return false;
            }
            break;
        }
        case SMART_TARGET_GAMEOBJECT_DISTANCE:
        case SMART_TARGET_GAMEOBJECT_RANGE:
        {
            if (e.target.goDistance.entry && !sObjectMgr->GetGameObjectTemplate(e.target.goDistance.entry))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent GameObject entry %u as target_param1, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.target.goDistance.entry);
                return false;
            }
            break;
        }
        case SMART_TARGET_CREATURE_GUID:
        {
            if (e.target.unitGUID.entry && !IsCreatureValid(e, e.target.unitGUID.entry))
                return false;
            break;
        }
        case SMART_TARGET_GAMEOBJECT_GUID:
        {
            if (e.target.goGUID.entry && !IsGameObjectValid(e, e.target.goGUID.entry))
                return false;
            break;
        }
        case SMART_TARGET_PLAYER_DISTANCE:
        case SMART_TARGET_CLOSEST_PLAYER:
        {
            if (e.target.playerDistance.dist == 0)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u has maxDist 0 as target_param1, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }
            break;
        }
        case SMART_TARGET_ACTION_INVOKER:
        case SMART_TARGET_ACTION_INVOKER_VEHICLE:
        case SMART_TARGET_INVOKER_PARTY:
            if (e.GetScriptType() != SMART_SCRIPT_TYPE_TIMED_ACTIONLIST && e.GetEventType() != SMART_EVENT_LINK && !EventHasInvoker(e.event.type))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u has invoker target, but event does not provide any invoker!", e.entryOrGuid, e.GetScriptType(), e.GetEventType(), e.GetActionType());
                return false;
            }
            break;
        case SMART_TARGET_HOSTILE_SECOND_AGGRO:
        case SMART_TARGET_HOSTILE_LAST_AGGRO:
        case SMART_TARGET_HOSTILE_RANDOM:
        case SMART_TARGET_HOSTILE_RANDOM_NOT_TOP:
            TC_SAI_IS_BOOLEAN_VALID(e, e.target.hostilRandom.playerOnly);
            break;
        case SMART_TARGET_FARTHEST:
            TC_SAI_IS_BOOLEAN_VALID(e, e.target.farthest.playerOnly);
            TC_SAI_IS_BOOLEAN_VALID(e, e.target.farthest.isInLos);
            break;
        case SMART_TARGET_CLOSEST_CREATURE:
            TC_SAI_IS_BOOLEAN_VALID(e, e.target.unitClosest.dead);
            break;
        case SMART_TARGET_CLOSEST_ENEMY:
            TC_SAI_IS_BOOLEAN_VALID(e, e.target.closestAttackable.playerOnly);
            break;
        case SMART_TARGET_CLOSEST_FRIENDLY:
            TC_SAI_IS_BOOLEAN_VALID(e, e.target.closestFriendly.playerOnly);
            break;
        case SMART_TARGET_OWNER_OR_SUMMONER:
            TC_SAI_IS_BOOLEAN_VALID(e, e.target.owner.useCharmerOrOwner);
            break;
        case SMART_TARGET_CLOSEST_GAMEOBJECT:
        case SMART_TARGET_PLAYER_RANGE:
        case SMART_TARGET_SELF:
        case SMART_TARGET_VICTIM:
        case SMART_TARGET_POSITION:
        case SMART_TARGET_NONE:
        case SMART_TARGET_THREAT_LIST:
        case SMART_TARGET_STORED:
        case SMART_TARGET_LOOT_RECIPIENTS:
        case SMART_TARGET_VEHICLE_PASSENGER:
        case SMART_TARGET_CLOSEST_UNSPAWNED_GAMEOBJECT:
            break;
        default:
            TC_LOG_ERROR("sql.sql", "SmartAIMgr: Not handled target_type(%u), Entry %d SourceType %u Event %u Action %u, skipped.", e.GetTargetType(), e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
            return false;
    }

    if (!CheckUnusedTargetParams(e))
        return false;

    return true;
}

bool SmartAIMgr::IsMinMaxValid(SmartScriptHolder const& e, uint32 min, uint32 max)
{
    if (max < min)
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses min/max params wrong (%u/%u), skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), min, max);
        return false;
    }
    return true;
}

bool SmartAIMgr::NotNULL(SmartScriptHolder const& e, uint32 data)
{
    if (!data)
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u Parameter can not be NULL, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
        return false;
    }
    return true;
}

bool SmartAIMgr::IsCreatureValid(SmartScriptHolder const& e, uint32 entry)
{
    if (!sObjectMgr->GetCreatureTemplate(entry))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Creature entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
        return false;
    }
    return true;
}

bool SmartAIMgr::IsQuestValid(SmartScriptHolder const& e, uint32 entry)
{
    if (!sObjectMgr->GetQuestTemplate(entry))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Quest entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
        return false;
    }
    return true;
}

bool SmartAIMgr::IsGameObjectValid(SmartScriptHolder const& e, uint32 entry)
{
    if (!sObjectMgr->GetGameObjectTemplate(entry))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent GameObject entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
        return false;
    }
    return true;
}

bool SmartAIMgr::IsSpellValid(SmartScriptHolder const& e, uint32 entry)
{
    if (!sSpellMgr->GetSpellInfo(entry))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Spell entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
        return false;
    }
    return true;
}

bool SmartAIMgr::IsItemValid(SmartScriptHolder const& e, uint32 entry)
{
    if (!sItemStore.LookupEntry(entry))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Item entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
        return false;
    }
    return true;
}

bool SmartAIMgr::IsTextEmoteValid(SmartScriptHolder const& e, uint32 entry)
{
    if (!sEmotesTextStore.LookupEntry(entry))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Text Emote entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
        return false;
    }
    return true;
}

bool SmartAIMgr::IsEmoteValid(SmartScriptHolder const& e, uint32 entry)
{
    if (!sEmotesStore.LookupEntry(entry))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Emote entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
        return false;
    }
    return true;
}

bool SmartAIMgr::IsAreaTriggerValid(SmartScriptHolder const& e, uint32 entry)
{
    if (!sAreaTriggerStore.LookupEntry(entry))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent AreaTrigger entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
        return false;
    }
    return true;
}

bool SmartAIMgr::IsSoundValid(SmartScriptHolder const& e, uint32 entry)
{
    if (!sSoundEntriesStore.LookupEntry(entry))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Sound entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), entry);
        return false;
    }
    return true;
}

bool SmartAIMgr::CheckUnusedEventParams(SmartScriptHolder const& e)
{
    size_t paramsStructSize = [&]() -> size_t
    {
        constexpr size_t NO_PARAMS = size_t(0);
        switch (e.event.type)
        {
            case SMART_EVENT_UPDATE_IC: return sizeof(SmartEvent::minMaxRepeat);
            case SMART_EVENT_UPDATE_OOC: return sizeof(SmartEvent::minMaxRepeat);
            case SMART_EVENT_HEALTH_PCT: return sizeof(SmartEvent::minMaxRepeat);
            case SMART_EVENT_MANA_PCT: return sizeof(SmartEvent::minMaxRepeat);
            case SMART_EVENT_AGGRO: return NO_PARAMS;
            case SMART_EVENT_KILL: return sizeof(SmartEvent::kill);
            case SMART_EVENT_DEATH: return NO_PARAMS;
            case SMART_EVENT_EVADE: return NO_PARAMS;
            case SMART_EVENT_SPELLHIT: return sizeof(SmartEvent::spellHit);
            case SMART_EVENT_RANGE: return sizeof(SmartEvent::minMaxRepeat);
            case SMART_EVENT_OOC_LOS: return sizeof(SmartEvent::los);
            case SMART_EVENT_RESPAWN: return sizeof(SmartEvent::respawn);
            case SMART_EVENT_VICTIM_CASTING: return sizeof(SmartEvent::targetCasting);
            case SMART_EVENT_FRIENDLY_IS_CC: return sizeof(SmartEvent::friendlyCC);
            case SMART_EVENT_FRIENDLY_MISSING_BUFF: return sizeof(SmartEvent::missingBuff);
            case SMART_EVENT_SUMMONED_UNIT: return sizeof(SmartEvent::summoned);
            case SMART_EVENT_ACCEPTED_QUEST: return sizeof(SmartEvent::quest);
            case SMART_EVENT_REWARD_QUEST: return sizeof(SmartEvent::quest);
            case SMART_EVENT_REACHED_HOME: return NO_PARAMS;
            case SMART_EVENT_RECEIVE_EMOTE: return sizeof(SmartEvent::emote);
            case SMART_EVENT_HAS_AURA: return sizeof(SmartEvent::aura);
            case SMART_EVENT_TARGET_BUFFED: return sizeof(SmartEvent::aura);
            case SMART_EVENT_RESET: return NO_PARAMS;
            case SMART_EVENT_IC_LOS: return sizeof(SmartEvent::los);
            case SMART_EVENT_PASSENGER_BOARDED: return sizeof(SmartEvent::minMax);
            case SMART_EVENT_PASSENGER_REMOVED: return sizeof(SmartEvent::minMax);
            case SMART_EVENT_CHARMED: return sizeof(SmartEvent::charm);
            case SMART_EVENT_SPELLHIT_TARGET: return sizeof(SmartEvent::spellHit);
            case SMART_EVENT_DAMAGED: return sizeof(SmartEvent::minMaxRepeat);
            case SMART_EVENT_DAMAGED_TARGET: return sizeof(SmartEvent::minMaxRepeat);
            case SMART_EVENT_MOVEMENTINFORM: return sizeof(SmartEvent::movementInform);
            case SMART_EVENT_SUMMON_DESPAWNED: return sizeof(SmartEvent::summoned);
            case SMART_EVENT_CORPSE_REMOVED: return NO_PARAMS;
            case SMART_EVENT_AI_INIT: return NO_PARAMS;
            case SMART_EVENT_DATA_SET: return sizeof(SmartEvent::dataSet);
            case SMART_EVENT_WAYPOINT_REACHED: return sizeof(SmartEvent::waypoint);
            case SMART_EVENT_TRANSPORT_ADDPLAYER: return NO_PARAMS;
            case SMART_EVENT_TRANSPORT_ADDCREATURE: return sizeof(SmartEvent::transportAddCreature);
            case SMART_EVENT_TRANSPORT_REMOVE_PLAYER: return NO_PARAMS;
            case SMART_EVENT_TRANSPORT_RELOCATE: return sizeof(SmartEvent::transportRelocate);
            case SMART_EVENT_INSTANCE_PLAYER_ENTER: return sizeof(SmartEvent::instancePlayerEnter);
            case SMART_EVENT_AREATRIGGER_ONTRIGGER: return sizeof(SmartEvent::areatrigger);
            case SMART_EVENT_QUEST_ACCEPTED: return NO_PARAMS;
            case SMART_EVENT_QUEST_OBJ_COMPLETION: return NO_PARAMS;
            case SMART_EVENT_QUEST_COMPLETION: return NO_PARAMS;
            case SMART_EVENT_QUEST_REWARDED: return NO_PARAMS;
            case SMART_EVENT_QUEST_FAIL: return NO_PARAMS;
            case SMART_EVENT_TEXT_OVER: return sizeof(SmartEvent::textOver);
            case SMART_EVENT_RECEIVE_HEAL: return sizeof(SmartEvent::minMaxRepeat);
            case SMART_EVENT_JUST_SUMMONED: return NO_PARAMS;
            case SMART_EVENT_WAYPOINT_PAUSED: return sizeof(SmartEvent::waypoint);
            case SMART_EVENT_WAYPOINT_RESUMED: return sizeof(SmartEvent::waypoint);
            case SMART_EVENT_WAYPOINT_STOPPED: return sizeof(SmartEvent::waypoint);
            case SMART_EVENT_WAYPOINT_ENDED: return sizeof(SmartEvent::waypoint);
            case SMART_EVENT_TIMED_EVENT_TRIGGERED: return sizeof(SmartEvent::timedEvent);
            case SMART_EVENT_UPDATE: return sizeof(SmartEvent::minMaxRepeat);
            case SMART_EVENT_LINK: return NO_PARAMS;
            case SMART_EVENT_GOSSIP_SELECT: return sizeof(SmartEvent::gossip);
            case SMART_EVENT_JUST_CREATED: return NO_PARAMS;
            case SMART_EVENT_GOSSIP_HELLO: return sizeof(SmartEvent::gossipHello);
            case SMART_EVENT_FOLLOW_COMPLETED: return NO_PARAMS;
            case SMART_EVENT_GAME_EVENT_START: return sizeof(SmartEvent::gameEvent);
            case SMART_EVENT_GAME_EVENT_END: return sizeof(SmartEvent::gameEvent);
            case SMART_EVENT_GO_LOOT_STATE_CHANGED: return sizeof(SmartEvent::goLootStateChanged);
            case SMART_EVENT_GO_EVENT_INFORM: return sizeof(SmartEvent::eventInform);
            case SMART_EVENT_ACTION_DONE: return sizeof(SmartEvent::doAction);
            case SMART_EVENT_ON_SPELLCLICK: return NO_PARAMS;
            case SMART_EVENT_FRIENDLY_HEALTH_PCT: return sizeof(SmartEvent::friendlyHealthPct);
            case SMART_EVENT_DISTANCE_CREATURE: return sizeof(SmartEvent::distance);
            case SMART_EVENT_DISTANCE_GAMEOBJECT: return sizeof(SmartEvent::distance);
            case SMART_EVENT_COUNTER_SET: return sizeof(SmartEvent::counter);
            //case SMART_EVENT_SCENE_START: return sizeof(SmartEvent::raw);
            //case SMART_EVENT_SCENE_TRIGGER: return sizeof(SmartEvent::raw);
            //case SMART_EVENT_SCENE_CANCEL: return sizeof(SmartEvent::raw);
            //case SMART_EVENT_SCENE_COMPLETE: return sizeof(SmartEvent::raw);
            case SMART_EVENT_SUMMONED_UNIT_DIES: return sizeof(SmartEvent::summoned);
            default:
                TC_LOG_WARN("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u is using an event with no unused params specified in SmartAIMgr::CheckUnusedEventParams(), please report this.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return sizeof(SmartEvent::raw);
        }
    }();

    static size_t rawCount = sizeof(SmartEvent::raw) / sizeof(uint32);
    size_t paramsCount = paramsStructSize / sizeof(uint32);

    for (size_t index = paramsCount; index < rawCount; index++)
    {
        uint32 value = ((uint32*)&e.event.raw)[index];
        if (value != 0)
        {
            TC_LOG_WARN("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u has unused event_param%zu with value %u, it should be 0.",
                e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), index + 1, value);
        }
    }

    return true;
}

bool SmartAIMgr::CheckUnusedActionParams(SmartScriptHolder const& e)
{
    size_t paramsStructSize = [&]() -> size_t
    {
        constexpr size_t NO_PARAMS = size_t(0);
        switch (e.action.type)
        {
            case SMART_ACTION_NONE: return NO_PARAMS;
            case SMART_ACTION_TALK: return sizeof(SmartAction::talk);
            case SMART_ACTION_SET_FACTION: return sizeof(SmartAction::faction);
            case SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL: return sizeof(SmartAction::morphOrMount);
            case SMART_ACTION_SOUND: return sizeof(SmartAction::sound);
            case SMART_ACTION_PLAY_EMOTE: return sizeof(SmartAction::emote);
            case SMART_ACTION_FAIL_QUEST: return sizeof(SmartAction::quest);
            case SMART_ACTION_OFFER_QUEST: return sizeof(SmartAction::questOffer);
            case SMART_ACTION_SET_REACT_STATE: return sizeof(SmartAction::react);
            case SMART_ACTION_ACTIVATE_GOBJECT: return NO_PARAMS;
            case SMART_ACTION_RANDOM_EMOTE: return sizeof(SmartAction::randomEmote);
            case SMART_ACTION_CAST: return sizeof(SmartAction::cast);
            case SMART_ACTION_SUMMON_CREATURE: return sizeof(SmartAction::summonCreature);
            case SMART_ACTION_THREAT_SINGLE_PCT: return sizeof(SmartAction::threatPCT);
            case SMART_ACTION_THREAT_ALL_PCT: return sizeof(SmartAction::threatPCT);
            case SMART_ACTION_CALL_AREAEXPLOREDOREVENTHAPPENS: return sizeof(SmartAction::quest);
            //case SMART_ACTION_RESERVED_16: return sizeof(SmartAction::raw);
            case SMART_ACTION_SET_EMOTE_STATE: return sizeof(SmartAction::emote);
            case SMART_ACTION_AUTO_ATTACK: return sizeof(SmartAction::autoAttack);
            case SMART_ACTION_ALLOW_COMBAT_MOVEMENT: return sizeof(SmartAction::combatMove);
            case SMART_ACTION_SET_EVENT_PHASE: return sizeof(SmartAction::setEventPhase);
            case SMART_ACTION_INC_EVENT_PHASE: return sizeof(SmartAction::incEventPhase);
            case SMART_ACTION_EVADE: return sizeof(SmartAction::evade);
            case SMART_ACTION_FLEE_FOR_ASSIST: return sizeof(SmartAction::fleeAssist);
            case SMART_ACTION_CALL_GROUPEVENTHAPPENS: return sizeof(SmartAction::quest);
            case SMART_ACTION_COMBAT_STOP: return NO_PARAMS;
            case SMART_ACTION_REMOVEAURASFROMSPELL: return sizeof(SmartAction::removeAura);
            case SMART_ACTION_FOLLOW: return sizeof(SmartAction::follow);
            case SMART_ACTION_RANDOM_PHASE: return sizeof(SmartAction::randomPhase);
            case SMART_ACTION_RANDOM_PHASE_RANGE: return sizeof(SmartAction::randomPhaseRange);
            case SMART_ACTION_RESET_GOBJECT: return NO_PARAMS;
            case SMART_ACTION_CALL_KILLEDMONSTER: return sizeof(SmartAction::killedMonster);
            case SMART_ACTION_SET_INST_DATA: return sizeof(SmartAction::setInstanceData);
            case SMART_ACTION_SET_INST_DATA64: return sizeof(SmartAction::setInstanceData64);
            case SMART_ACTION_UPDATE_TEMPLATE: return sizeof(SmartAction::updateTemplate);
            case SMART_ACTION_DIE: return NO_PARAMS;
            case SMART_ACTION_SET_IN_COMBAT_WITH_ZONE: return NO_PARAMS;
            case SMART_ACTION_CALL_FOR_HELP: return sizeof(SmartAction::callHelp);
            case SMART_ACTION_SET_SHEATH: return sizeof(SmartAction::setSheath);
            case SMART_ACTION_FORCE_DESPAWN: return sizeof(SmartAction::forceDespawn);
            case SMART_ACTION_SET_INVINCIBILITY_HP_LEVEL: return sizeof(SmartAction::invincHP);
            case SMART_ACTION_MOUNT_TO_ENTRY_OR_MODEL: return sizeof(SmartAction::morphOrMount);
            case SMART_ACTION_SET_INGAME_PHASE_MASK: return sizeof(SmartAction::ingamePhaseMask);
            case SMART_ACTION_SET_DATA: return sizeof(SmartAction::setData);
            case SMART_ACTION_ATTACK_STOP: return NO_PARAMS;
            case SMART_ACTION_SET_VISIBILITY: return sizeof(SmartAction::visibility);
            case SMART_ACTION_SET_ACTIVE: return sizeof(SmartAction::active);
            case SMART_ACTION_ATTACK_START: return NO_PARAMS;
            case SMART_ACTION_SUMMON_GO: return sizeof(SmartAction::summonGO);
            case SMART_ACTION_KILL_UNIT: return NO_PARAMS;
            case SMART_ACTION_ACTIVATE_TAXI: return sizeof(SmartAction::taxi);
            case SMART_ACTION_WP_START: return sizeof(SmartAction::wpStart);
            case SMART_ACTION_WP_PAUSE: return sizeof(SmartAction::wpPause);
            case SMART_ACTION_WP_STOP: return sizeof(SmartAction::wpStop);
            case SMART_ACTION_ADD_ITEM: return sizeof(SmartAction::item);
            case SMART_ACTION_REMOVE_ITEM: return sizeof(SmartAction::item);
            case SMART_ACTION_SET_RUN: return sizeof(SmartAction::setRun);
            case SMART_ACTION_SET_DISABLE_GRAVITY: return sizeof(SmartAction::setDisableGravity);
            case SMART_ACTION_TELEPORT: return sizeof(SmartAction::teleport);
            case SMART_ACTION_SET_COUNTER: return sizeof(SmartAction::setCounter);
            case SMART_ACTION_STORE_TARGET_LIST: return sizeof(SmartAction::storeTargets);
            case SMART_ACTION_WP_RESUME: return NO_PARAMS;
            case SMART_ACTION_SET_ORIENTATION: return NO_PARAMS;
            case SMART_ACTION_CREATE_TIMED_EVENT: return sizeof(SmartAction::timeEvent);
            case SMART_ACTION_PLAYMOVIE: return sizeof(SmartAction::movie);
            case SMART_ACTION_MOVE_TO_POS: return sizeof(SmartAction::moveToPos);
            case SMART_ACTION_ENABLE_TEMP_GOBJ: return sizeof(SmartAction::enableTempGO);
            case SMART_ACTION_EQUIP: return sizeof(SmartAction::equip);
            case SMART_ACTION_CLOSE_GOSSIP: return NO_PARAMS;
            case SMART_ACTION_TRIGGER_TIMED_EVENT: return sizeof(SmartAction::timeEvent);
            case SMART_ACTION_REMOVE_TIMED_EVENT: return sizeof(SmartAction::timeEvent);
            case SMART_ACTION_ADD_AURA: return sizeof(SmartAction::addAura);
            case SMART_ACTION_CALL_SCRIPT_RESET: return NO_PARAMS;
            case SMART_ACTION_SET_RANGED_MOVEMENT: return sizeof(SmartAction::setRangedMovement);
            case SMART_ACTION_CALL_TIMED_ACTIONLIST: return sizeof(SmartAction::timedActionList);
            case SMART_ACTION_SET_NPC_FLAG: return sizeof(SmartAction::flag);
            case SMART_ACTION_ADD_NPC_FLAG: return sizeof(SmartAction::flag);
            case SMART_ACTION_REMOVE_NPC_FLAG: return sizeof(SmartAction::flag);
            case SMART_ACTION_SIMPLE_TALK: return sizeof(SmartAction::simpleTalk);
            case SMART_ACTION_SELF_CAST: return sizeof(SmartAction::cast);
            case SMART_ACTION_CROSS_CAST: return sizeof(SmartAction::crossCast);
            case SMART_ACTION_CALL_RANDOM_TIMED_ACTIONLIST: return sizeof(SmartAction::randTimedActionList);
            case SMART_ACTION_CALL_RANDOM_RANGE_TIMED_ACTIONLIST: return sizeof(SmartAction::randRangeTimedActionList);
            case SMART_ACTION_RANDOM_MOVE: return sizeof(SmartAction::moveRandom);
            case SMART_ACTION_SET_UNIT_FIELD_BYTES_1: return sizeof(SmartAction::setunitByte);
            case SMART_ACTION_REMOVE_UNIT_FIELD_BYTES_1: return sizeof(SmartAction::delunitByte);
            case SMART_ACTION_INTERRUPT_SPELL: return sizeof(SmartAction::interruptSpellCasting);
            case SMART_ACTION_SEND_GO_CUSTOM_ANIM: return sizeof(SmartAction::sendGoCustomAnim);
            case SMART_ACTION_JUMP_TO_POS: return sizeof(SmartAction::jump);
            case SMART_ACTION_SEND_GOSSIP_MENU: return sizeof(SmartAction::sendGossipMenu);
            case SMART_ACTION_GO_SET_LOOT_STATE: return sizeof(SmartAction::setGoLootState);
            case SMART_ACTION_SEND_TARGET_TO_TARGET: return sizeof(SmartAction::sendTargetToTarget);
            case SMART_ACTION_SET_HOME_POS: return NO_PARAMS;
            case SMART_ACTION_SET_HEALTH_REGEN: return sizeof(SmartAction::setHealthRegen);
            case SMART_ACTION_SET_ROOT: return sizeof(SmartAction::setRoot);
            case SMART_ACTION_SET_GO_FLAG: return sizeof(SmartAction::goFlag);
            case SMART_ACTION_ADD_GO_FLAG: return sizeof(SmartAction::goFlag);
            case SMART_ACTION_REMOVE_GO_FLAG: return sizeof(SmartAction::goFlag);
            case SMART_ACTION_SUMMON_CREATURE_GROUP: return sizeof(SmartAction::creatureGroup);
            case SMART_ACTION_SET_POWER: return sizeof(SmartAction::power);
            case SMART_ACTION_ADD_POWER: return sizeof(SmartAction::power);
            case SMART_ACTION_REMOVE_POWER: return sizeof(SmartAction::power);
            case SMART_ACTION_GAME_EVENT_STOP: return sizeof(SmartAction::gameEventStop);
            case SMART_ACTION_GAME_EVENT_START: return sizeof(SmartAction::gameEventStart);
            case SMART_ACTION_START_CLOSEST_WAYPOINT: return sizeof(SmartAction::closestWaypointFromList);
            case SMART_ACTION_MOVE_OFFSET: return NO_PARAMS;
            case SMART_ACTION_RANDOM_SOUND: return sizeof(SmartAction::randomSound);
            case SMART_ACTION_SET_CORPSE_DELAY: return sizeof(SmartAction::corpseDelay);
            case SMART_ACTION_DISABLE_EVADE: return sizeof(SmartAction::disableEvade);
            case SMART_ACTION_GO_SET_GO_STATE: return sizeof(SmartAction::goState);
            case SMART_ACTION_ADD_THREAT: return sizeof(SmartAction::threat);
            case SMART_ACTION_LOAD_EQUIPMENT: return sizeof(SmartAction::loadEquipment);
            case SMART_ACTION_TRIGGER_RANDOM_TIMED_EVENT: return sizeof(SmartAction::randomTimedEvent);
            case SMART_ACTION_PAUSE_MOVEMENT: return sizeof(SmartAction::pauseMovement);
            //case SMART_ACTION_PLAY_ANIMKIT: return sizeof(SmartAction::raw);
            //case SMART_ACTION_SCENE_PLAY: return sizeof(SmartAction::raw);
            //case SMART_ACTION_SCENE_CANCEL: return sizeof(SmartAction::raw);
            case SMART_ACTION_SPAWN_SPAWNGROUP: return sizeof(SmartAction::groupSpawn);
            case SMART_ACTION_DESPAWN_SPAWNGROUP: return sizeof(SmartAction::groupSpawn);
            case SMART_ACTION_RESPAWN_BY_SPAWNID: return sizeof(SmartAction::respawnData);
            case SMART_ACTION_INVOKER_CAST: return sizeof(SmartAction::cast);
            case SMART_ACTION_PLAY_CINEMATIC: return sizeof(SmartAction::cinematic);
            case SMART_ACTION_SET_MOVEMENT_SPEED: return sizeof(SmartAction::movementSpeed);
            //case SMART_ACTION_PLAY_SPELL_VISUAL_KIT: return sizeof(SmartAction::raw);
            case SMART_ACTION_OVERRIDE_LIGHT: return sizeof(SmartAction::overrideLight);
            case SMART_ACTION_OVERRIDE_WEATHER: return sizeof(SmartAction::overrideWeather);
            //case SMART_ACTION_SET_AI_ANIM_KIT: return sizeof(SmartAction::raw);
            case SMART_ACTION_SET_HOVER: return sizeof(SmartAction::setHover);
            case SMART_ACTION_SET_HEALTH_PCT: return sizeof(SmartAction::setHealthPct);
            //case SMART_ACTION_CREATE_CONVERSATION: return sizeof(SmartAction::raw);
            case SMART_ACTION_SET_IMMUNE_PC: return sizeof(SmartAction::setImmunePC);
            case SMART_ACTION_SET_IMMUNE_NPC: return sizeof(SmartAction::setImmuneNPC);
            case SMART_ACTION_SET_UNINTERACTIBLE: return sizeof(SmartAction::setUninteractible);
            case SMART_ACTION_ACTIVATE_GAMEOBJECT: return sizeof(SmartAction::activateGameObject);
            default:
                TC_LOG_WARN("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u is using an action with no unused params specified in SmartAIMgr::CheckUnusedActionParams(), please report this.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return sizeof(SmartAction::raw);
        }
    }();

    static size_t rawCount = sizeof(SmartAction::raw) / sizeof(uint32);
    size_t paramsCount = paramsStructSize / sizeof(uint32);

    for (size_t index = paramsCount; index < rawCount; index++)
    {
        uint32 value = ((uint32*)&e.action.raw)[index];
        if (value != 0)
        {
            TC_LOG_WARN("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u has unused action_param%zu with value %u, it should be 0.",
                e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), index + 1, value);
        }
    }

    return true;
}

bool SmartAIMgr::CheckUnusedTargetParams(SmartScriptHolder const& e)
{
    size_t paramsStructSize = [&]() -> size_t
    {
        constexpr size_t NO_PARAMS = size_t(0);
        switch (e.target.type)
        {
            case SMART_TARGET_NONE: return NO_PARAMS;
            case SMART_TARGET_SELF: return NO_PARAMS;
            case SMART_TARGET_VICTIM: return NO_PARAMS;
            case SMART_TARGET_HOSTILE_SECOND_AGGRO: return sizeof(SmartTarget::hostilRandom);
            case SMART_TARGET_HOSTILE_LAST_AGGRO: return sizeof(SmartTarget::hostilRandom);
            case SMART_TARGET_HOSTILE_RANDOM: return sizeof(SmartTarget::hostilRandom);
            case SMART_TARGET_HOSTILE_RANDOM_NOT_TOP: return sizeof(SmartTarget::hostilRandom);
            case SMART_TARGET_ACTION_INVOKER: return NO_PARAMS;
            case SMART_TARGET_POSITION: return NO_PARAMS; //uses x,y,z,o
            case SMART_TARGET_CREATURE_RANGE: return sizeof(SmartTarget::unitRange);
            case SMART_TARGET_CREATURE_GUID: return sizeof(SmartTarget::unitGUID);
            case SMART_TARGET_CREATURE_DISTANCE: return sizeof(SmartTarget::unitDistance);
            case SMART_TARGET_STORED: return sizeof(SmartTarget::stored);
            case SMART_TARGET_GAMEOBJECT_RANGE: return sizeof(SmartTarget::goRange);
            case SMART_TARGET_GAMEOBJECT_GUID: return sizeof(SmartTarget::goGUID);
            case SMART_TARGET_GAMEOBJECT_DISTANCE: return sizeof(SmartTarget::goDistance);
            case SMART_TARGET_INVOKER_PARTY: return NO_PARAMS;
            case SMART_TARGET_PLAYER_RANGE: return sizeof(SmartTarget::playerRange);
            case SMART_TARGET_PLAYER_DISTANCE: return sizeof(SmartTarget::playerDistance);
            case SMART_TARGET_CLOSEST_CREATURE: return sizeof(SmartTarget::unitClosest);
            case SMART_TARGET_CLOSEST_GAMEOBJECT: return sizeof(SmartTarget::goClosest);
            case SMART_TARGET_CLOSEST_PLAYER: return sizeof(SmartTarget::playerDistance);
            case SMART_TARGET_ACTION_INVOKER_VEHICLE: return NO_PARAMS;
            case SMART_TARGET_OWNER_OR_SUMMONER: return sizeof(SmartTarget::owner);
            case SMART_TARGET_THREAT_LIST: return sizeof(SmartTarget::threatList);
            case SMART_TARGET_CLOSEST_ENEMY: return sizeof(SmartTarget::closestAttackable);
            case SMART_TARGET_CLOSEST_FRIENDLY: return sizeof(SmartTarget::closestFriendly);
            case SMART_TARGET_LOOT_RECIPIENTS: return NO_PARAMS;
            case SMART_TARGET_FARTHEST: return sizeof(SmartTarget::farthest);
            case SMART_TARGET_VEHICLE_PASSENGER: return sizeof(SmartTarget::vehicle);
            case SMART_TARGET_CLOSEST_UNSPAWNED_GAMEOBJECT: return sizeof(SmartTarget::goClosest);
            default:
                TC_LOG_WARN("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u is using a target with no unused params specified in SmartAIMgr::CheckUnusedTargetParams(), please report this.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return sizeof(SmartTarget::raw);
        }
    }();

    static size_t rawCount = sizeof(SmartTarget::raw) / sizeof(uint32);
    size_t paramsCount = paramsStructSize / sizeof(uint32);

    for (size_t index = paramsCount; index < rawCount; index++)
    {
        uint32 value = ((uint32*)&e.target.raw)[index];
        if (value != 0)
        {
            TC_LOG_WARN("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u has unused target_param%zu with value %u, it should be 0.",
                e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), index + 1, value);
        }
    }

    return true;
}

bool SmartAIMgr::IsEventValid(SmartScriptHolder& e)
{
    if (e.event.type >= SMART_EVENT_END)
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: EntryOrGuid %d using event(%u) has invalid event type (%u), skipped.", e.entryOrGuid, e.event_id, e.GetEventType());
        return false;
    }

    // in SMART_SCRIPT_TYPE_TIMED_ACTIONLIST all event types are overriden by core
    if (e.GetScriptType() != SMART_SCRIPT_TYPE_TIMED_ACTIONLIST && !(SmartAIEventMask[e.event.type][1] & SmartAITypeMask[e.GetScriptType()][1]))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: EntryOrGuid %d, event type %u can not be used for Script type %u", e.entryOrGuid, e.GetEventType(), e.GetScriptType());
        return false;
    }

    if (e.action.type <= 0 || e.action.type >= SMART_ACTION_END)
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: EntryOrGuid %d using event(%u) has invalid action type (%u), skipped.", e.entryOrGuid, e.event_id, e.GetActionType());
        return false;
    }

    if (e.event.event_phase_mask > SMART_EVENT_PHASE_ALL)
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: EntryOrGuid %d using event(%u) has invalid phase mask (%u), skipped.", e.entryOrGuid, e.event_id, e.event.event_phase_mask);
        return false;
    }

    if (e.event.event_flags > SMART_EVENT_FLAGS_ALL)
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: EntryOrGuid %d using event(%u) has invalid event flags (%u), skipped.", e.entryOrGuid, e.event_id, e.event.event_flags);
        return false;
    }

    if (e.link && e.link == e.event_id)
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: EntryOrGuid %d SourceType %u, Event %u, Event is linking self (infinite loop), skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id);
        return false;
    }

    if (e.GetScriptType() == SMART_SCRIPT_TYPE_TIMED_ACTIONLIST)
    {
        e.event.type = SMART_EVENT_UPDATE_OOC;//force default OOC, can change when calling the script!
        if (!IsMinMaxValid(e, e.event.minMaxRepeat.min, e.event.minMaxRepeat.max))
            return false;

        if (!IsMinMaxValid(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax))
            return false;
    }
    else
    {
        switch (e.GetEventType())
        {
            case SMART_EVENT_UPDATE:
            case SMART_EVENT_UPDATE_IC:
            case SMART_EVENT_UPDATE_OOC:
            case SMART_EVENT_HEALTH_PCT:
            case SMART_EVENT_MANA_PCT:
            case SMART_EVENT_RANGE:
            case SMART_EVENT_DAMAGED:
            case SMART_EVENT_DAMAGED_TARGET:
            case SMART_EVENT_RECEIVE_HEAL:
                if (!IsMinMaxValid(e, e.event.minMaxRepeat.min, e.event.minMaxRepeat.max))
                    return false;

                if (!IsMinMaxValid(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax))
                    return false;
                break;
            case SMART_EVENT_SPELLHIT:
            case SMART_EVENT_SPELLHIT_TARGET:
                if (e.event.spellHit.spell)
                {
                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(e.event.spellHit.spell);
                    if (!spellInfo)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Spell entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.event.spellHit.spell);
                        return false;
                    }
                    if (e.event.spellHit.school && (e.event.spellHit.school & spellInfo->SchoolMask) != spellInfo->SchoolMask)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses Spell entry %u with invalid school mask, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.event.spellHit.spell);
                        return false;
                    }
                }
                if (!IsMinMaxValid(e, e.event.spellHit.cooldownMin, e.event.spellHit.cooldownMax))
                    return false;
                break;
            case SMART_EVENT_OOC_LOS:
            case SMART_EVENT_IC_LOS:
                if (!IsMinMaxValid(e, e.event.los.cooldownMin, e.event.los.cooldownMax))
                    return false;
                if (e.event.los.hostilityMode >= AsUnderlyingType(SmartEvent::LOSHostilityMode::End))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses hostilityMode with invalid value %u (max allowed value %u), skipped.",
                        e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.event.los.hostilityMode, AsUnderlyingType(SmartEvent::LOSHostilityMode::End) - 1);
                    return false;
                }

                TC_SAI_IS_BOOLEAN_VALID(e, e.event.los.playerOnly);
                break;
            case SMART_EVENT_RESPAWN:
                if (e.event.respawn.type == SMART_SCRIPT_RESPAWN_CONDITION_MAP && !sMapStore.LookupEntry(e.event.respawn.map))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Map entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.event.respawn.map);
                    return false;
                }
                if (e.event.respawn.type == SMART_SCRIPT_RESPAWN_CONDITION_AREA && !sAreaTableStore.LookupEntry(e.event.respawn.area))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Area entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.event.respawn.area);
                    return false;
                }
                break;
            case SMART_EVENT_FRIENDLY_IS_CC:
                if (!IsMinMaxValid(e, e.event.friendlyCC.repeatMin, e.event.friendlyCC.repeatMax))
                    return false;
                break;
            case SMART_EVENT_FRIENDLY_MISSING_BUFF:
            {
                if (!IsSpellValid(e, e.event.missingBuff.spell))
                    return false;

                if (!NotNULL(e, e.event.missingBuff.radius))
                    return false;

                if (!IsMinMaxValid(e, e.event.missingBuff.repeatMin, e.event.missingBuff.repeatMax))
                    return false;
                break;
            }
            case SMART_EVENT_KILL:
                if (!IsMinMaxValid(e, e.event.kill.cooldownMin, e.event.kill.cooldownMax))
                    return false;

                if (e.event.kill.creature && !IsCreatureValid(e, e.event.kill.creature))
                    return false;

                TC_SAI_IS_BOOLEAN_VALID(e, e.event.kill.playerOnly);
                break;
            case SMART_EVENT_VICTIM_CASTING:
                if (e.event.targetCasting.spellId > 0 && !sSpellMgr->GetSpellInfo(e.event.targetCasting.spellId))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Spell entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.event.spellHit.spell);
                    return false;
                }

                if (!IsMinMaxValid(e, e.event.targetCasting.repeatMin, e.event.targetCasting.repeatMax))
                    return false;
                break;
            case SMART_EVENT_PASSENGER_BOARDED:
            case SMART_EVENT_PASSENGER_REMOVED:
                if (!IsMinMaxValid(e, e.event.minMax.repeatMin, e.event.minMax.repeatMax))
                    return false;
                break;
            case SMART_EVENT_SUMMON_DESPAWNED:
            case SMART_EVENT_SUMMONED_UNIT:
            case SMART_EVENT_SUMMONED_UNIT_DIES:
                if (e.event.summoned.creature && !IsCreatureValid(e, e.event.summoned.creature))
                    return false;

                if (!IsMinMaxValid(e, e.event.summoned.cooldownMin, e.event.summoned.cooldownMax))
                    return false;
                break;
            case SMART_EVENT_ACCEPTED_QUEST:
            case SMART_EVENT_REWARD_QUEST:
                if (e.event.quest.quest && !IsQuestValid(e, e.event.quest.quest))
                    return false;

                if (!IsMinMaxValid(e, e.event.quest.cooldownMin, e.event.quest.cooldownMax))
                    return false;
                break;
            case SMART_EVENT_RECEIVE_EMOTE:
            {
                if (e.event.emote.emote && !IsTextEmoteValid(e, e.event.emote.emote))
                    return false;

                if (!IsMinMaxValid(e, e.event.emote.cooldownMin, e.event.emote.cooldownMax))
                    return false;
                break;
            }
            case SMART_EVENT_HAS_AURA:
            case SMART_EVENT_TARGET_BUFFED:
            {
                if (!IsSpellValid(e, e.event.aura.spell))
                    return false;

                if (!IsMinMaxValid(e, e.event.aura.repeatMin, e.event.aura.repeatMax))
                    return false;
                break;
            }
            case SMART_EVENT_TRANSPORT_ADDCREATURE:
            {
                if (e.event.transportAddCreature.creature && !IsCreatureValid(e, e.event.transportAddCreature.creature))
                    return false;
                break;
            }
            case SMART_EVENT_MOVEMENTINFORM:
            {
                if (IsInvalidMovementGeneratorType(e.event.movementInform.type))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses invalid Motion type %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.event.movementInform.type);
                    return false;
                }
                break;
            }
            case SMART_EVENT_DATA_SET:
            {
                if (!IsMinMaxValid(e, e.event.dataSet.cooldownMin, e.event.dataSet.cooldownMax))
                    return false;
                break;
            }
            case SMART_EVENT_AREATRIGGER_ONTRIGGER:
            {
                if (e.event.areatrigger.id && !IsAreaTriggerValid(e, e.event.areatrigger.id))
                    return false;
                break;
            }
            case SMART_EVENT_TEXT_OVER:
                if (!IsTextValid(e, e.event.textOver.textGroupID))
                    return false;
                break;
            case SMART_EVENT_GAME_EVENT_START:
            case SMART_EVENT_GAME_EVENT_END:
            {
                GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
                if (e.event.gameEvent.gameEventId >= events.size() || !events[e.event.gameEvent.gameEventId].isValid())
                    return false;
                break;
            }
            case SMART_EVENT_ACTION_DONE:
            {
                if (e.event.doAction.eventId > EVENT_CHARGE)
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses invalid event id %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.event.doAction.eventId);
                    return false;
                }
                break;
            }
            case SMART_EVENT_FRIENDLY_HEALTH_PCT:
                if (!IsMinMaxValid(e, e.event.friendlyHealthPct.repeatMin, e.event.friendlyHealthPct.repeatMax))
                    return false;

                if (e.event.friendlyHealthPct.maxHpPct > 100 || e.event.friendlyHealthPct.minHpPct > 100)
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u has pct value above 100, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                    return false;
                }

                switch (e.GetTargetType())
                {
                    case SMART_TARGET_CREATURE_RANGE:
                    case SMART_TARGET_CREATURE_GUID:
                    case SMART_TARGET_CREATURE_DISTANCE:
                    case SMART_TARGET_CLOSEST_CREATURE:
                    case SMART_TARGET_CLOSEST_PLAYER:
                    case SMART_TARGET_PLAYER_RANGE:
                    case SMART_TARGET_PLAYER_DISTANCE:
                        break;
                    case SMART_TARGET_ACTION_INVOKER:
                        if (!NotNULL(e, e.event.friendlyHealthPct.radius))
                            return false;
                        break;
                    default:
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses invalid target_type %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.GetTargetType());
                        return false;
                }
                break;
            case SMART_EVENT_DISTANCE_CREATURE:
                if (e.event.distance.guid == 0 && e.event.distance.entry == 0)
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Event SMART_EVENT_DISTANCE_CREATURE did not provide creature guid or entry, skipped.");
                    return false;
                }

                if (e.event.distance.guid != 0 && e.event.distance.entry != 0)
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Event SMART_EVENT_DISTANCE_CREATURE provided both an entry and guid, skipped.");
                    return false;
                }

                if (e.event.distance.guid != 0 && !sObjectMgr->GetCreatureData(e.event.distance.guid))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Event SMART_EVENT_DISTANCE_CREATURE using invalid creature guid %u, skipped.", e.event.distance.guid);
                    return false;
                }

                if (e.event.distance.entry != 0 && !sObjectMgr->GetCreatureTemplate(e.event.distance.entry))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Event SMART_EVENT_DISTANCE_CREATURE using invalid creature entry %u, skipped.", e.event.distance.entry);
                    return false;
                }
                break;
            case SMART_EVENT_DISTANCE_GAMEOBJECT:
                if (e.event.distance.guid == 0 && e.event.distance.entry == 0)
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Event SMART_EVENT_DISTANCE_GAMEOBJECT did not provide gameobject guid or entry, skipped.");
                    return false;
                }

                if (e.event.distance.guid != 0 && e.event.distance.entry != 0)
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Event SMART_EVENT_DISTANCE_GAMEOBJECT provided both an entry and guid, skipped.");
                    return false;
                }

                if (e.event.distance.guid != 0 && !sObjectMgr->GetGameObjectData(e.event.distance.guid))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Event SMART_EVENT_DISTANCE_GAMEOBJECT using invalid gameobject guid %u, skipped.", e.event.distance.guid);
                    return false;
                }

                if (e.event.distance.entry != 0 && !sObjectMgr->GetGameObjectTemplate(e.event.distance.entry))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Event SMART_EVENT_DISTANCE_GAMEOBJECT using invalid gameobject entry %u, skipped.", e.event.distance.entry);
                    return false;
                }
                break;
            case SMART_EVENT_COUNTER_SET:
                if (!IsMinMaxValid(e, e.event.counter.cooldownMin, e.event.counter.cooldownMax))
                    return false;

                if (e.event.counter.id == 0)
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Event SMART_EVENT_COUNTER_SET using invalid counter id %u, skipped.", e.event.counter.id);
                    return false;
                }

                if (e.event.counter.value == 0)
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Event SMART_EVENT_COUNTER_SET using invalid value %u, skipped.", e.event.counter.value);
                    return false;
                }
                break;
            case SMART_EVENT_RESET:
                if (e.action.type == SMART_ACTION_CALL_SCRIPT_RESET)
                {
                    // There might be SMART_TARGET_* cases where this should be allowed, they will be handled if needed
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u uses event SMART_EVENT_RESET and action SMART_ACTION_CALL_SCRIPT_RESET, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id);
                    return false;
                }
                break;
            case SMART_EVENT_CHARMED:
                TC_SAI_IS_BOOLEAN_VALID(e, e.event.charm.onRemove);
                break;
            case SMART_EVENT_LINK:
            case SMART_EVENT_GO_LOOT_STATE_CHANGED:
            case SMART_EVENT_GO_EVENT_INFORM:
            case SMART_EVENT_TIMED_EVENT_TRIGGERED:
            case SMART_EVENT_INSTANCE_PLAYER_ENTER:
            case SMART_EVENT_TRANSPORT_RELOCATE:
            case SMART_EVENT_CORPSE_REMOVED:
            case SMART_EVENT_AI_INIT:
            case SMART_EVENT_TRANSPORT_ADDPLAYER:
            case SMART_EVENT_TRANSPORT_REMOVE_PLAYER:
            case SMART_EVENT_AGGRO:
            case SMART_EVENT_DEATH:
            case SMART_EVENT_EVADE:
            case SMART_EVENT_REACHED_HOME:
            case SMART_EVENT_QUEST_ACCEPTED:
            case SMART_EVENT_QUEST_OBJ_COMPLETION:
            case SMART_EVENT_QUEST_COMPLETION:
            case SMART_EVENT_QUEST_REWARDED:
            case SMART_EVENT_QUEST_FAIL:
            case SMART_EVENT_JUST_SUMMONED:
            case SMART_EVENT_WAYPOINT_REACHED:
            case SMART_EVENT_WAYPOINT_PAUSED:
            case SMART_EVENT_WAYPOINT_RESUMED:
            case SMART_EVENT_WAYPOINT_STOPPED:
            case SMART_EVENT_WAYPOINT_ENDED:
            case SMART_EVENT_GOSSIP_SELECT:
            case SMART_EVENT_GOSSIP_HELLO:
            case SMART_EVENT_JUST_CREATED:
            case SMART_EVENT_FOLLOW_COMPLETED:
            case SMART_EVENT_ON_SPELLCLICK:
                break;
            // Unused
            case SMART_EVENT_TARGET_HEALTH_PCT:
            case SMART_EVENT_FRIENDLY_HEALTH:
            case SMART_EVENT_TARGET_MANA_PCT:
            case SMART_EVENT_CHARMED_TARGET:
            case SMART_EVENT_WAYPOINT_START:
            case SMART_EVENT_EVENT_PHASE_CHANGE:
            case SMART_EVENT_IS_BEHIND_TARGET:
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Unused event_type(%u), Entry %d SourceType %u Event %u, skipped.", e.GetEventType(), e.entryOrGuid, e.GetScriptType(), e.event_id);
                return false;
            default:
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Not handled event_type(%u), Entry %d SourceType %u Event %u Action %u, skipped.", e.GetEventType(), e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
        }
    }

    if (!CheckUnusedEventParams(e))
        return false;

    switch (e.GetActionType())
    {
        case SMART_ACTION_TALK:
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.talk.useTalkTarget);
            if (!IsTextValid(e, e.action.talk.textGroupID))
                return false;
            break;
        case SMART_ACTION_SIMPLE_TALK:
            if (!IsTextValid(e, e.action.simpleTalk.textGroupID))
                return false;
            break;
        case SMART_ACTION_SET_FACTION:
            if (e.action.faction.factionID && !sFactionTemplateStore.LookupEntry(e.action.faction.factionID))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Faction %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.faction.factionID);
                return false;
            }
            break;
        case SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL:
        case SMART_ACTION_MOUNT_TO_ENTRY_OR_MODEL:
            if (e.action.morphOrMount.creature || e.action.morphOrMount.model)
            {
                if (e.action.morphOrMount.creature > 0 && !sObjectMgr->GetCreatureTemplate(e.action.morphOrMount.creature))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Creature entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.morphOrMount.creature);
                    return false;
                }

                if (e.action.morphOrMount.model)
                {
                    if (e.action.morphOrMount.creature)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u has ModelID set with also set CreatureId, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                        return false;
                    }
                    else if (!sCreatureDisplayInfoStore.LookupEntry(e.action.morphOrMount.model))
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Model id %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.morphOrMount.model);
                        return false;
                    }
                }
            }
            break;
        case SMART_ACTION_SOUND:
            if (!IsSoundValid(e, e.action.sound.sound))
                return false;
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.sound.onlySelf);
            break;
        case SMART_ACTION_SET_EMOTE_STATE:
        case SMART_ACTION_PLAY_EMOTE:
            if (!IsEmoteValid(e, e.action.emote.emote))
                return false;
            break;
        case SMART_ACTION_OFFER_QUEST:
            if (!IsQuestValid(e, e.action.questOffer.questID))
                return false;

            TC_SAI_IS_BOOLEAN_VALID(e, e.action.questOffer.directAdd);
            break;
        case SMART_ACTION_FAIL_QUEST:
            if (!IsQuestValid(e, e.action.quest.quest))
                return false;
            break;
        case SMART_ACTION_ACTIVATE_TAXI:
            {
                if (!sTaxiPathStore.LookupEntry(e.action.taxi.id))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses invalid Taxi path ID %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.taxi.id);
                    return false;
                }
                break;
            }
        case SMART_ACTION_RANDOM_EMOTE:
        {
            if (std::all_of(std::begin(e.action.randomEmote.emotes), std::end(e.action.randomEmote.emotes), [](uint32 emote) { return emote == 0; }))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u does not have any non-zero emote",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }

            for (uint32 emote : e.action.randomEmote.emotes)
                if (emote && !IsEmoteValid(e, emote))
                    return false;
            break;
        }
        case SMART_ACTION_CALL_RANDOM_TIMED_ACTIONLIST:
        {
            if (std::all_of(std::begin(e.action.randTimedActionList.actionLists), std::end(e.action.randTimedActionList.actionLists), [](uint32 actionList) { return actionList == 0; }))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u does not have any non-zero action list",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }
            break;
        }
        case SMART_ACTION_START_CLOSEST_WAYPOINT:
        {
            if (std::all_of(std::begin(e.action.closestWaypointFromList.wps), std::end(e.action.closestWaypointFromList.wps), [](uint32 wp) { return wp == 0; }))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u does not have any non-zero waypoint id",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }
            break;
        }
        case SMART_ACTION_RANDOM_SOUND:
        {
            if (std::all_of(std::begin(e.action.randomSound.sounds), std::end(e.action.randomSound.sounds), [](uint32 sound) { return sound == 0; }))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u does not have any non-zero sound",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }

            for (uint32 sound : e.action.randomSound.sounds)
                if (sound && !IsSoundValid(e, sound))
                    return false;

            TC_SAI_IS_BOOLEAN_VALID(e, e.action.randomSound.onlySelf);
            break;
        }
        case SMART_ACTION_CAST:
        {
            if (!IsSpellValid(e, e.action.cast.spell))
                return false;

            for (SpellEffectInfo const& spellEffectInfo : sSpellMgr->AssertSpellInfo(e.action.cast.spell)->GetEffects())
            {
                if (spellEffectInfo.IsEffect(SPELL_EFFECT_KILL_CREDIT) || spellEffectInfo.IsEffect(SPELL_EFFECT_KILL_CREDIT2))
                {
                    if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_CASTER)
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u Effect: SPELL_EFFECT_KILL_CREDIT: (SpellId: %u targetA: %u - targetB: %u) has invalid target for this Action",
                            e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.cast.spell, spellEffectInfo.TargetA.GetTarget(), spellEffectInfo.TargetB.GetTarget());
                }
            }
            break;
        }
        case SMART_ACTION_CROSS_CAST:
        {
            if (!IsSpellValid(e, e.action.crossCast.spell))
                return false;
            break;
        }
        case SMART_ACTION_INVOKER_CAST:
            if (e.GetScriptType() != SMART_SCRIPT_TYPE_TIMED_ACTIONLIST && e.GetEventType() != SMART_EVENT_LINK && !EventHasInvoker(e.event.type))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u has invoker cast action, but event does not provide any invoker!", e.entryOrGuid, e.GetScriptType(), e.GetEventType(), e.GetActionType());
                return false;
            }
            [[fallthrough]];
        case SMART_ACTION_SELF_CAST:
            if (!IsSpellValid(e, e.action.cast.spell))
                return false;
            break;
        case SMART_ACTION_ADD_AURA:
            if (!IsSpellValid(e, e.action.addAura.spell))
                return false;
            break;
        case SMART_ACTION_CALL_AREAEXPLOREDOREVENTHAPPENS:
        case SMART_ACTION_CALL_GROUPEVENTHAPPENS:
            if (Quest const* qid = sObjectMgr->GetQuestTemplate(e.action.quest.quest))
            {
                if (!qid->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT))
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u SpecialFlags for Quest entry %u does not include FLAGS_EXPLORATION_OR_EVENT(2), skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.quest.quest);
                    return false;
                }
            }
            else
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Quest entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.quest.quest);
                return false;
            }
            break;
        case SMART_ACTION_SET_EVENT_PHASE:
            if (e.action.setEventPhase.phase >= SMART_EVENT_PHASE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u attempts to set phase %u. Phase mask cannot be used past phase %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.setEventPhase.phase, SMART_EVENT_PHASE_MAX-1);
                return false;
            }
            break;
        case SMART_ACTION_INC_EVENT_PHASE:
            if (!e.action.incEventPhase.inc && !e.action.incEventPhase.dec)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u is incrementing phase by 0, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }
            else if (e.action.incEventPhase.inc > SMART_EVENT_PHASE_MAX || e.action.incEventPhase.dec > SMART_EVENT_PHASE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u attempts to increment phase by too large value, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }
            break;
        case SMART_ACTION_REMOVEAURASFROMSPELL:
            if (e.action.removeAura.spell != 0 && !IsSpellValid(e, e.action.removeAura.spell))
                return false;

            TC_SAI_IS_BOOLEAN_VALID(e, e.action.removeAura.onlyOwnedAuras);
            break;
        case SMART_ACTION_RANDOM_PHASE:
        {
            if (std::all_of(std::begin(e.action.randomPhase.phases), std::end(e.action.randomPhase.phases), [](uint32 phase) { return phase == 0; }))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u does not have any non-zero phase",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }

            if (std::any_of(std::begin(e.action.randomPhase.phases), std::end(e.action.randomPhase.phases), [](uint32 phase) { return phase >= SMART_EVENT_PHASE_MAX; }))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u attempts to set invalid phase, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }
            break;
        }
        case SMART_ACTION_RANDOM_PHASE_RANGE:       //PhaseMin, PhaseMax
        {
            if (e.action.randomPhaseRange.phaseMin >= SMART_EVENT_PHASE_MAX ||
                e.action.randomPhaseRange.phaseMax >= SMART_EVENT_PHASE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u attempts to set invalid phase, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }

            if (!IsMinMaxValid(e, e.action.randomPhaseRange.phaseMin, e.action.randomPhaseRange.phaseMax))
                return false;
            break;
        }
        case SMART_ACTION_SUMMON_CREATURE:
        {
            if (!IsCreatureValid(e, e.action.summonCreature.creature))
                return false;

            CacheSpellContainerBounds sBounds = GetSummonCreatureSpellContainerBounds(e.action.summonCreature.creature);
            for (CacheSpellContainer::const_iterator itr = sBounds.first; itr != sBounds.second; ++itr)
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u creature summon: There is a summon spell for creature entry %u (SpellId: %u, effect: %u)",
                                e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.summonCreature.creature, itr->second.first, itr->second.second);

            if (e.action.summonCreature.type < TEMPSUMMON_TIMED_OR_DEAD_DESPAWN || e.action.summonCreature.type > TEMPSUMMON_MANUAL_DESPAWN)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses incorrect TempSummonType %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.summonCreature.type);
                return false;
            }

            TC_SAI_IS_BOOLEAN_VALID(e, e.action.summonCreature.attackInvoker);
            break;
        }
        case SMART_ACTION_CALL_KILLEDMONSTER:
        {
            if (!IsCreatureValid(e, e.action.killedMonster.creature))
                return false;

            CacheSpellContainerBounds sBounds = GetKillCreditSpellContainerBounds(e.action.killedMonster.creature);
            for (CacheSpellContainer::const_iterator itr = sBounds.first; itr != sBounds.second; ++itr)
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u Kill Credit: There is a killcredit spell for creatureEntry %u (SpellId: %u effect: %u)",
                                e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.killedMonster.creature, itr->second.first, itr->second.second);

            if (e.GetTargetType() == SMART_TARGET_POSITION)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses incorrect TargetType %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.GetTargetType());
                return false;
            }
            break;
        }
        case SMART_ACTION_UPDATE_TEMPLATE:
            if (!IsCreatureValid(e, e.action.updateTemplate.creature))
                return false;

            TC_SAI_IS_BOOLEAN_VALID(e, e.action.updateTemplate.updateLevel);
            break;
        case SMART_ACTION_SET_SHEATH:
            if (e.action.setSheath.sheath && e.action.setSheath.sheath >= MAX_SHEATH_STATE)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses incorrect Sheath state %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.setSheath.sheath);
                return false;
            }
            break;
        case SMART_ACTION_SET_REACT_STATE:
            {
                if (e.action.react.state > REACT_AGGRESSIVE)
                {
                    TC_LOG_ERROR("sql.sql", "SmartAIMgr: Creature %d Event %u Action %u uses invalid React State %u, skipped.", e.entryOrGuid, e.event_id, e.GetActionType(), e.action.react.state);
                    return false;
                }
                break;
            }
        case SMART_ACTION_SUMMON_GO:
        {
            if (!IsGameObjectValid(e, e.action.summonGO.entry))
                return false;

            CacheSpellContainerBounds sBounds = GetSummonGameObjectSpellContainerBounds(e.action.summonGO.entry);
            for (CacheSpellContainer::const_iterator itr = sBounds.first; itr != sBounds.second; ++itr)
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u gameobject summon: There is a summon spell for gameobject entry %u (SpellId: %u, effect: %u)",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.summonGO.entry, itr->second.first, itr->second.second);
            break;
        }
        case SMART_ACTION_REMOVE_ITEM:
            if (!IsItemValid(e, e.action.item.entry))
                return false;

            if (!NotNULL(e, e.action.item.count))
                return false;
            break;
        case SMART_ACTION_ADD_ITEM:
        {
            if (!IsItemValid(e, e.action.item.entry))
                return false;

            if (!NotNULL(e, e.action.item.count))
                return false;

            CacheSpellContainerBounds sBounds = GetCreateItemSpellContainerBounds(e.action.item.entry);
            for (CacheSpellContainer::const_iterator itr = sBounds.first; itr != sBounds.second; ++itr)
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u Create Item: There is a create item spell for item %u (SpellId: %u effect: %u)",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.item.entry, itr->second.first, itr->second.second);
            break;
        }
        case SMART_ACTION_TELEPORT:
            if (!sMapStore.LookupEntry(e.action.teleport.mapID))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Map entry %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.teleport.mapID);
                return false;
            }
            break;
        case SMART_ACTION_WP_STOP:
            if (e.action.wpStop.quest && !IsQuestValid(e, e.action.wpStop.quest))
                return false;
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.wpStop.fail);
            break;
        case SMART_ACTION_WP_START:
        {
            WaypointPath const* path = sSmartWaypointMgr->GetPath(e.action.wpStart.pathID);
            if (!path || path->nodes.empty())
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Creature %d Event %u Action %u uses non-existent WaypointPath id %u, skipped.", e.entryOrGuid, e.event_id, e.GetActionType(), e.action.wpStart.pathID);
                return false;
            }
            if (e.action.wpStart.quest && !IsQuestValid(e, e.action.wpStart.quest))
                return false;

            TC_SAI_IS_BOOLEAN_VALID(e, e.action.wpStart.run);
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.wpStart.repeat);
            break;
        }
        case SMART_ACTION_CREATE_TIMED_EVENT:
        {
            if (!IsMinMaxValid(e, e.action.timeEvent.min, e.action.timeEvent.max))
                return false;

            if (!IsMinMaxValid(e, e.action.timeEvent.repeatMin, e.action.timeEvent.repeatMax))
                return false;
            break;
        }
        case SMART_ACTION_CALL_RANDOM_RANGE_TIMED_ACTIONLIST:
        {
            if (!IsMinMaxValid(e, e.action.randRangeTimedActionList.idMin, e.action.randRangeTimedActionList.idMax))
                return false;
            break;
        }
        case SMART_ACTION_SET_POWER:
        case SMART_ACTION_ADD_POWER:
        case SMART_ACTION_REMOVE_POWER:
            if (e.action.power.powerType > MAX_POWERS)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent Power %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.power.powerType);
                return false;
            }
            break;
        case SMART_ACTION_GAME_EVENT_STOP:
        {
            uint32 eventId = e.action.gameEventStop.id;

            GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
            if (eventId < 1 || eventId >= events.size())
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %u SourceType %u Event %u Action %u uses non-existent event, eventId %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.gameEventStop.id);
                return false;
            }

            GameEventData const& eventData = events[eventId];
            if (!eventData.isValid())
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %u SourceType %u Event %u Action %u uses non-existent event, eventId %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.gameEventStop.id);
                return false;
            }
            break;
        }
        case SMART_ACTION_GAME_EVENT_START:
        {
            uint32 eventId = e.action.gameEventStart.id;

            GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
            if (eventId < 1 || eventId >= events.size())
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %u SourceType %u Event %u Action %u uses non-existent event, eventId %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.gameEventStart.id);
                return false;
            }

            GameEventData const& eventData = events[eventId];
            if (!eventData.isValid())
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %u SourceType %u Event %u Action %u uses non-existent event, eventId %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.gameEventStart.id);
                return false;
            }
            break;
        }
        case SMART_ACTION_EQUIP:
        {
            if (e.GetScriptType() == SMART_SCRIPT_TYPE_CREATURE)
            {
                if (int8 equipId = static_cast<int8>(e.action.equip.entry))
                {
                    EquipmentInfo const* eInfo = sObjectMgr->GetEquipmentInfo(e.entryOrGuid, equipId);
                    if (!eInfo)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartScript: SMART_ACTION_EQUIP uses non-existent equipment info id %u for creature %u, skipped.", equipId, e.entryOrGuid);
                        return false;
                    }
                }
            }
            break;
        }
        case SMART_ACTION_SET_INST_DATA:
        {
            if (e.action.setInstanceData.type > 1)
            {
                TC_LOG_ERROR("sql.sql", "Entry %u SourceType %u Event %u Action %u uses invalid data type %u (value range 0-1), skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.setInstanceData.type);
                return false;
            }
            else if (e.action.setInstanceData.type == 1)
            {
                if (e.action.setInstanceData.data > TO_BE_DECIDED)
                {
                    TC_LOG_ERROR("sql.sql", "Entry %u SourceType %u Event %u Action %u uses invalid boss state %u (value range 0-5), skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.setInstanceData.data);
                    return false;
                }
            }
            break;
        }
        case SMART_ACTION_RESPAWN_BY_SPAWNID:
            if (!sObjectMgr->GetSpawnData(SpawnObjectType(e.action.respawnData.spawnType), e.action.respawnData.spawnId))
            {
                TC_LOG_ERROR("sql.sql", "Entry %u SourceType %u Event %u Action %u specifies invalid spawn data (%u,%u)", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.respawnData.spawnType, e.action.respawnData.spawnId);
                return false;
            }
            break;
        case SMART_ACTION_ENABLE_TEMP_GOBJ:
            if (!e.action.enableTempGO.duration)
            {
                TC_LOG_ERROR("sql.sql", "Entry %u SourceType %u Event %u Action %u does not specify duration", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }
            break;
        case SMART_ACTION_PAUSE_MOVEMENT:
            if (!e.action.pauseMovement.pauseTimer)
            {
                TC_LOG_ERROR("sql.sql", "Entry %u SourceType %u Event %u Action %u does not specify pause duration", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }

            TC_SAI_IS_BOOLEAN_VALID(e, e.action.pauseMovement.force);
            break;
        case SMART_ACTION_SET_MOVEMENT_SPEED:
        {
            if (e.action.movementSpeed.movementType >= MAX_MOVE_TYPE)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %u SourceType %u Event %u Action %u uses invalid movementType %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.movementSpeed.movementType);
                return false;
            }

            if (!e.action.movementSpeed.speedInteger && !e.action.movementSpeed.speedFraction)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %u SourceType %u Event %u Action %u uses speed 0, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
                return false;
            }

            break;
        }
        case SMART_ACTION_OVERRIDE_LIGHT:
        {
            AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(e.action.overrideLight.zoneId);
            if (!areaEntry)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent zoneId %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.overrideLight.zoneId);
                return false;
            }

            if (areaEntry->ParentAreaID != 0)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses subzone (ID: %u) instead of zone, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.overrideLight.zoneId);
                return false;
            }

            if (!sLightStore.LookupEntry(e.action.overrideLight.areaLightId))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent areaLightId %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.overrideLight.areaLightId);
                return false;
            }

            if (e.action.overrideLight.overrideLightId && !sLightStore.LookupEntry(e.action.overrideLight.overrideLightId))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent overrideLightId %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.overrideLight.overrideLightId);
                return false;
            }

            break;
        }
        case SMART_ACTION_OVERRIDE_WEATHER:
        {
            AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(e.action.overrideWeather.zoneId);
            if (!areaEntry)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses non-existent zoneId %u, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.overrideWeather.zoneId);
                return false;
            }

            if (areaEntry->ParentAreaID != 0)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u uses subzone (ID: %u) instead of zone, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.overrideWeather.zoneId);
                return false;
            }

            break;
        }
        case SMART_ACTION_SET_HEALTH_PCT:
        {
            if (e.action.setHealthPct.percent > 100 || !e.action.setHealthPct.percent)
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u is trying to set invalid HP percent %u, skipped.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.setHealthPct.percent);
                return false;
            }
            break;
        }
        case SMART_ACTION_AUTO_ATTACK:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.autoAttack.attack);
            break;
        }
        case SMART_ACTION_ALLOW_COMBAT_MOVEMENT:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.combatMove.move);
            break;
        }
        case SMART_ACTION_CALL_FOR_HELP:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.callHelp.withEmote);
            break;
        }
        case SMART_ACTION_SET_VISIBILITY:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.visibility.state);
            break;
        }
        case SMART_ACTION_SET_ACTIVE:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.active.state);
            break;
        }
        case SMART_ACTION_SET_RUN:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.setRun.run);
            break;
        }
        case SMART_ACTION_SET_DISABLE_GRAVITY:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.setDisableGravity.disable);
            break;
        }
        case SMART_ACTION_SET_COUNTER:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.setCounter.reset);
            break;
        }
        case SMART_ACTION_CALL_TIMED_ACTIONLIST:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.timedActionList.allowOverride);
            break;
        }
        case SMART_ACTION_INTERRUPT_SPELL:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.interruptSpellCasting.withDelayed);
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.interruptSpellCasting.withInstant);
            break;
        }
        case SMART_ACTION_FLEE_FOR_ASSIST:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.fleeAssist.withEmote);
            break;
        }
        case SMART_ACTION_MOVE_TO_POS:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.moveToPos.transport);
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.moveToPos.disablePathfinding);
            break;
        }
        case SMART_ACTION_SET_ROOT:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.setRoot.root);
            break;
        }
        case SMART_ACTION_DISABLE_EVADE:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.disableEvade.disable);
            break;
        }
        case SMART_ACTION_LOAD_EQUIPMENT:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.loadEquipment.force);
            break;
        }
        case SMART_ACTION_SET_HOVER:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.setHover.enable);
            break;
        }
        case SMART_ACTION_EVADE:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.evade.toRespawnPosition);
            break;
        }
        case SMART_ACTION_SET_HEALTH_REGEN:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.setHealthRegen.regenHealth);
            break;
        }
        case SMART_ACTION_SET_IMMUNE_PC:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.setImmunePC.immunePC);
            break;
        }
        case SMART_ACTION_SET_IMMUNE_NPC:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.setImmuneNPC.immuneNPC);
            break;
        }
        case SMART_ACTION_SET_UNINTERACTIBLE:
        {
            TC_SAI_IS_BOOLEAN_VALID(e, e.action.setUninteractible.uninteractible);
            break;
        }
        case SMART_ACTION_ACTIVATE_GAMEOBJECT:
        {
            if (!NotNULL(e, e.action.activateGameObject.gameObjectAction))
                return false;

            if (e.action.activateGameObject.gameObjectAction >= uint32(GameObjectActions::Max))
            {
                TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u has gameObjectAction parameter out of range (max allowed %u, current value %u), skipped.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), uint32(GameObjectActions::Max) - 1, e.action.activateGameObject.gameObjectAction);
                return false;
            }
            break;
        }
        case SMART_ACTION_FOLLOW:
        case SMART_ACTION_SET_ORIENTATION:
        case SMART_ACTION_STORE_TARGET_LIST:
        case SMART_ACTION_COMBAT_STOP:
        case SMART_ACTION_DIE:
        case SMART_ACTION_SET_IN_COMBAT_WITH_ZONE:
        case SMART_ACTION_WP_RESUME:
        case SMART_ACTION_KILL_UNIT:
        case SMART_ACTION_SET_INVINCIBILITY_HP_LEVEL:
        case SMART_ACTION_RESET_GOBJECT:
        case SMART_ACTION_ATTACK_START:
        case SMART_ACTION_THREAT_ALL_PCT:
        case SMART_ACTION_THREAT_SINGLE_PCT:
        case SMART_ACTION_SET_INST_DATA64:
        case SMART_ACTION_SET_DATA:
        case SMART_ACTION_ATTACK_STOP:
        case SMART_ACTION_WP_PAUSE:
        case SMART_ACTION_FORCE_DESPAWN:
        case SMART_ACTION_SET_INGAME_PHASE_MASK:
        case SMART_ACTION_PLAYMOVIE:
        case SMART_ACTION_CLOSE_GOSSIP:
        case SMART_ACTION_TRIGGER_TIMED_EVENT:
        case SMART_ACTION_REMOVE_TIMED_EVENT:
        case SMART_ACTION_ACTIVATE_GOBJECT:
        case SMART_ACTION_CALL_SCRIPT_RESET:
        case SMART_ACTION_SET_RANGED_MOVEMENT:
        case SMART_ACTION_SET_NPC_FLAG:
        case SMART_ACTION_ADD_NPC_FLAG:
        case SMART_ACTION_REMOVE_NPC_FLAG:
        case SMART_ACTION_RANDOM_MOVE:
        case SMART_ACTION_SET_UNIT_FIELD_BYTES_1:
        case SMART_ACTION_REMOVE_UNIT_FIELD_BYTES_1:
        case SMART_ACTION_SEND_GO_CUSTOM_ANIM:
        case SMART_ACTION_JUMP_TO_POS:
        case SMART_ACTION_SEND_GOSSIP_MENU:
        case SMART_ACTION_GO_SET_LOOT_STATE:
        case SMART_ACTION_GO_SET_GO_STATE:
        case SMART_ACTION_SEND_TARGET_TO_TARGET:
        case SMART_ACTION_SET_HOME_POS:
        case SMART_ACTION_SET_GO_FLAG:
        case SMART_ACTION_ADD_GO_FLAG:
        case SMART_ACTION_REMOVE_GO_FLAG:
        case SMART_ACTION_SUMMON_CREATURE_GROUP:
        case SMART_ACTION_MOVE_OFFSET:
        case SMART_ACTION_SET_CORPSE_DELAY:
        case SMART_ACTION_ADD_THREAT:
        case SMART_ACTION_TRIGGER_RANDOM_TIMED_EVENT:
        case SMART_ACTION_SPAWN_SPAWNGROUP:
        case SMART_ACTION_DESPAWN_SPAWNGROUP:
        case SMART_ACTION_PLAY_CINEMATIC:
            break;
        // Unused
        case SMART_ACTION_SET_UNIT_FLAG:
        case SMART_ACTION_REMOVE_UNIT_FLAG:
        case SMART_ACTION_INSTALL_AI_TEMPLATE:
        case SMART_ACTION_SET_SWIM:
        case SMART_ACTION_OVERRIDE_SCRIPT_BASE_OBJECT:
        case SMART_ACTION_RESET_SCRIPT_BASE_OBJECT:
        case SMART_ACTION_SET_DYNAMIC_FLAG:
        case SMART_ACTION_ADD_DYNAMIC_FLAG:
        case SMART_ACTION_REMOVE_DYNAMIC_FLAG:
        case SMART_ACTION_SET_CAN_FLY:
        case SMART_ACTION_REMOVE_AURAS_BY_TYPE:
        case SMART_ACTION_SET_SIGHT_DIST:
        case SMART_ACTION_FLEE:
        case SMART_ACTION_REMOVE_ALL_GAMEOBJECTS:
            TC_LOG_ERROR("sql.sql", "SmartAIMgr: Unused action_type(%u), event_type(%u), Entry %d SourceType %u Event %u, skipped.", e.GetActionType(), e.GetEventType(), e.entryOrGuid, e.GetScriptType(), e.event_id);
            return false;
        default:
            TC_LOG_ERROR("sql.sql", "SmartAIMgr: Not handled action_type(%u), event_type(%u), Entry %d SourceType %u Event %u, skipped.", e.GetActionType(), e.GetEventType(), e.entryOrGuid, e.GetScriptType(), e.event_id);
            return false;
    }

    if (!CheckUnusedActionParams(e))
        return false;

    return true;
}

bool SmartAIMgr::IsTextValid(SmartScriptHolder const& e, uint32 id)
{
    if (e.GetScriptType() != SMART_SCRIPT_TYPE_CREATURE)
        return true;

    uint32 entry = 0;

    if (e.GetEventType() == SMART_EVENT_TEXT_OVER)
    {
        entry = e.event.textOver.creatureEntry;
    }
    else
    {
        switch (e.GetTargetType())
        {
            case SMART_TARGET_CREATURE_DISTANCE:
            case SMART_TARGET_CREATURE_RANGE:
            case SMART_TARGET_CLOSEST_CREATURE:
                return true; // ignore
            default:
                if (e.entryOrGuid < 0)
                {
                    ObjectGuid::LowType guid = ObjectGuid::LowType(-e.entryOrGuid);
                    CreatureData const* data = sObjectMgr->GetCreatureData(guid);
                    if (!data)
                    {
                        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u using non-existent Creature guid %d, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), guid);
                        return false;
                    }
                    else
                        entry = data->id;
                }
                else
                    entry = uint32(e.entryOrGuid);
                break;
        }
    }

    if (!entry || !sCreatureTextMgr->TextExist(entry, uint8(id)))
    {
        TC_LOG_ERROR("sql.sql", "SmartAIMgr: Entry %d SourceType %u Event %u Action %u using non-existent Text id %d, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), id);
        return false;
    }

    return true;
}

void SmartAIMgr::LoadHelperStores()
{
    uint32 oldMSTime = getMSTime();

    SpellInfo const* spellInfo = nullptr;
    for (uint32 i = 0; i < sSpellMgr->GetSpellInfoStoreSize(); ++i)
    {
        spellInfo = sSpellMgr->GetSpellInfo(i);
        if (!spellInfo)
            continue;

        for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
        {
            if (spellEffectInfo.IsEffect(SPELL_EFFECT_SUMMON))
                SummonCreatureSpellStore.insert(std::make_pair(uint32(spellEffectInfo.MiscValue), std::make_pair(i, spellEffectInfo.EffectIndex)));

            else if (spellEffectInfo.IsEffect(SPELL_EFFECT_SUMMON_OBJECT_WILD))
                SummonGameObjectSpellStore.insert(std::make_pair(uint32(spellEffectInfo.MiscValue), std::make_pair(i, spellEffectInfo.EffectIndex)));

            else if (spellEffectInfo.IsEffect(SPELL_EFFECT_KILL_CREDIT) || spellEffectInfo.IsEffect(SPELL_EFFECT_KILL_CREDIT2))
                KillCreditSpellStore.insert(std::make_pair(uint32(spellEffectInfo.MiscValue), std::make_pair(i, spellEffectInfo.EffectIndex)));

            else if (spellEffectInfo.IsEffect(SPELL_EFFECT_CREATE_ITEM))
                CreateItemSpellStore.insert(std::make_pair(uint32(spellEffectInfo.ItemType), std::make_pair(i, spellEffectInfo.EffectIndex)));
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded SmartAIMgr Helpers in %u ms", GetMSTimeDiffToNow(oldMSTime));
}

void SmartAIMgr::UnLoadHelperStores()
{
    SummonCreatureSpellStore.clear();
    SummonGameObjectSpellStore.clear();
    KillCreditSpellStore.clear();
    CreateItemSpellStore.clear();
}

CacheSpellContainerBounds SmartAIMgr::GetSummonCreatureSpellContainerBounds(uint32 creatureEntry) const
{
    return SummonCreatureSpellStore.equal_range(creatureEntry);
}

CacheSpellContainerBounds SmartAIMgr::GetSummonGameObjectSpellContainerBounds(uint32 gameObjectEntry) const
{
    return SummonGameObjectSpellStore.equal_range(gameObjectEntry);
}

CacheSpellContainerBounds SmartAIMgr::GetKillCreditSpellContainerBounds(uint32 killCredit) const
{
    return KillCreditSpellStore.equal_range(killCredit);
}

CacheSpellContainerBounds SmartAIMgr::GetCreateItemSpellContainerBounds(uint32 itemId) const
{
    return CreateItemSpellStore.equal_range(itemId);
}

ObjectGuidVector::ObjectGuidVector(ObjectVector const& objectVector) : _objectVector(objectVector)
{
    _guidVector.reserve(_objectVector.size());
    for (WorldObject* obj : _objectVector)
        _guidVector.push_back(obj->GetGUID());
}

void ObjectGuidVector::UpdateObjects(WorldObject const& ref) const
{
    _objectVector.clear();

    for (ObjectGuid const& guid : _guidVector)
        if (WorldObject* obj = ObjectAccessor::GetWorldObject(ref, guid))
            _objectVector.push_back(obj);
}
