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

#include "Map.h"
#include "World.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Transport.h"
#include "ScriptedCreature.h"
#include "WaypointManager.h"
#include "GossipDef.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "MapRefManager.h"
#include "ScriptMgr.h"

/// Put scripts in the execution queue
void Map::ScriptsStart(ScriptMapMap const& scripts, uint32 id, Object* source, Object* target)
{
    ///- Find the script map
    ScriptMapMap::const_iterator s = scripts.find(id);
    if (s == scripts.end())
        return;

    // prepare static data
    uint64 sourceGUID = source ? source->GetGUID() : (uint64)0; //some script commands doesn't have source
    uint64 targetGUID = target ? target->GetGUID() : (uint64)0;
    uint64 ownerGUID  = (source->GetTypeId() == TYPEID_ITEM) ? ((Item*)source)->GetOwnerGUID() : (uint64)0;

    ///- Schedule script execution for all scripts in the script map
    ScriptMap const* s2 = &(s->second);
    bool immedScript = false;
    for (ScriptMap::const_iterator iter = s2->begin(); iter != s2->end(); ++iter)
    {
        ScriptAction sa;
        sa.sourceGUID = sourceGUID;
        sa.targetGUID = targetGUID;
        sa.ownerGUID  = ownerGUID;

        sa.script = &iter->second;
        m_scriptSchedule.insert(ScriptScheduleMap::value_type(time_t(sWorld->GetGameTime() + iter->first), sa));
        if (iter->first == 0)
            immedScript = true;

        sScriptMgr->IncreaseScheduledScriptsCount();
    }
    ///- If one of the effects should be immediate, launch the script execution
    if (/*start &&*/ immedScript && !i_scriptLock)
    {
        i_scriptLock = true;
        ScriptsProcess();
        i_scriptLock = false;
    }
}

void Map::ScriptCommandStart(ScriptInfo const& script, uint32 delay, Object* source, Object* target)
{
    // NOTE: script record _must_ exist until command executed

    // prepare static data
    uint64 sourceGUID = source ? source->GetGUID() : (uint64)0;
    uint64 targetGUID = target ? target->GetGUID() : (uint64)0;
    uint64 ownerGUID  = (source->GetTypeId() == TYPEID_ITEM) ? ((Item*)source)->GetOwnerGUID() : (uint64)0;

    ScriptAction sa;
    sa.sourceGUID = sourceGUID;
    sa.targetGUID = targetGUID;
    sa.ownerGUID  = ownerGUID;

    sa.script = &script;
    m_scriptSchedule.insert(ScriptScheduleMap::value_type(time_t(sWorld->GetGameTime() + delay), sa));

    sScriptMgr->IncreaseScheduledScriptsCount();

    ///- If effects should be immediate, launch the script execution
    if (delay == 0 && !i_scriptLock)
    {
        i_scriptLock = true;
        ScriptsProcess();
        i_scriptLock = false;
    }
}

// Helpers for ScriptProcess method.
inline Player* Map::_GetScriptPlayerSourceOrTarget(Object* source, Object* target, const ScriptInfo* scriptInfo) const
{
    Player* player = NULL;
    if (!source && !target)
        sLog->outError("%s source and target objects are NULL.", scriptInfo->GetDebugInfo().c_str());
    else
    {
        // Check target first, then source.
        if (target)
            player = target->ToPlayer();
        if (!player && source)
            player = source->ToPlayer();

        if (!player)
            sLog->outError("%s neither source nor target object is player (source: TypeId: %u, Entry: %u, GUID: %u; target: TypeId: %u, Entry: %u, GUID: %u), skipping.",
                scriptInfo->GetDebugInfo().c_str(),
                source ? source->GetTypeId() : 0, source ? source->GetEntry() : 0, source ? source->GetGUIDLow() : 0,
                target ? target->GetTypeId() : 0, target ? target->GetEntry() : 0, target ? target->GetGUIDLow() : 0);
    }
    return player;
}

inline Creature* Map::_GetScriptCreatureSourceOrTarget(Object* source, Object* target, const ScriptInfo* scriptInfo, bool bReverse) const
{
    Creature* creature = NULL;
    if (!source && !target)
        sLog->outError("%s source and target objects are NULL.", scriptInfo->GetDebugInfo().c_str());
    else
    {
        if (bReverse)
        {
            // Check target first, then source.
            if (target)
                creature = target->ToCreature();
            if (!creature && source)
                creature = source->ToCreature();
        }
        else
        {
            // Check source first, then target.
            if (source)
                creature = source->ToCreature();
            if (!creature && target)
                creature = target->ToCreature();
        }

        if (!creature)
            sLog->outError("%s neither source nor target are creatures (source: TypeId: %u, Entry: %u, GUID: %u; target: TypeId: %u, Entry: %u, GUID: %u), skipping.",
                scriptInfo->GetDebugInfo().c_str(),
                source ? source->GetTypeId() : 0, source ? source->GetEntry() : 0, source ? source->GetGUIDLow() : 0,
                target ? target->GetTypeId() : 0, target ? target->GetEntry() : 0, target ? target->GetGUIDLow() : 0);
    }
    return creature;
}

inline Unit* Map::_GetScriptUnit(Object* obj, bool isSource, const ScriptInfo* scriptInfo) const
{
    Unit* unit = NULL;
    if (!obj)
        sLog->outError("%s %s object is NULL.", scriptInfo->GetDebugInfo().c_str(), isSource ? "source" : "target");
    else if (!obj->isType(TYPEMASK_UNIT))
        sLog->outError("%s %s object is not unit (TypeId: %u, Entry: %u, GUID: %u), skipping.",
            scriptInfo->GetDebugInfo().c_str(), isSource ? "source" : "target", obj->GetTypeId(), obj->GetEntry(), obj->GetGUIDLow());
    else
    {
        unit = obj->ToUnit();
        if (!unit)
            sLog->outError("%s %s object could not be casted to unit.",
                scriptInfo->GetDebugInfo().c_str(), isSource ? "source" : "target");
    }
    return unit;
}

inline Player* Map::_GetScriptPlayer(Object* obj, bool isSource, const ScriptInfo* scriptInfo) const
{
    Player* player = NULL;
    if (!obj)
        sLog->outError("%s %s object is NULL.", scriptInfo->GetDebugInfo().c_str(), isSource ? "source" : "target");
    else
    {
        player = obj->ToPlayer();
        if (!player)
            sLog->outError("%s %s object is not a player (TypeId: %u, Entry: %u, GUID: %u).",
                scriptInfo->GetDebugInfo().c_str(), isSource ? "source" : "target", obj->GetTypeId(), obj->GetEntry(), obj->GetGUIDLow());
    }
    return player;
}

inline Creature* Map::_GetScriptCreature(Object* obj, bool isSource, const ScriptInfo* scriptInfo) const
{
    Creature* creature = NULL;
    if (!obj)
        sLog->outError("%s %s object is NULL.", scriptInfo->GetDebugInfo().c_str(), isSource ? "source" : "target");
    else
    {
        creature = obj->ToCreature();
        if (!creature)
            sLog->outError("%s %s object is not a creature (TypeId: %u, Entry: %u, GUID: %u).", scriptInfo->GetDebugInfo().c_str(),
                isSource ? "source" : "target", obj->GetTypeId(), obj->GetEntry(), obj->GetGUIDLow());
    }
    return creature;
}

inline WorldObject* Map::_GetScriptWorldObject(Object* obj, bool isSource, const ScriptInfo* scriptInfo) const
{
    WorldObject* pWorldObject = NULL;
    if (!obj)
        sLog->outError("%s %s object is NULL.",
            scriptInfo->GetDebugInfo().c_str(), isSource ? "source" : "target");
    else
    {
        pWorldObject = dynamic_cast<WorldObject*>(obj);
        if (!pWorldObject)
            sLog->outError("%s %s object is not a world object (TypeId: %u, Entry: %u, GUID: %u).",
                scriptInfo->GetDebugInfo().c_str(), isSource ? "source" : "target", obj->GetTypeId(), obj->GetEntry(), obj->GetGUIDLow());
    }
    return pWorldObject;
}

inline void Map::_ScriptProcessDoor(Object* source, Object* target, const ScriptInfo* scriptInfo) const
{
    bool bOpen = false;
    uint32 guid = scriptInfo->ToggleDoor.GOGuid;
    int32 nTimeToToggle = std::max(15, int32(scriptInfo->ToggleDoor.ResetDelay));
    switch (scriptInfo->command)
    {
        case SCRIPT_COMMAND_OPEN_DOOR: bOpen = true; break;
        case SCRIPT_COMMAND_CLOSE_DOOR: break;
        default:
            sLog->outError("%s unknown command for _ScriptProcessDoor.", scriptInfo->GetDebugInfo().c_str());
            return;
    }
    if (!guid)
        sLog->outError("%s door guid is not specified.", scriptInfo->GetDebugInfo().c_str());
    else if (!source)
        sLog->outError("%s source object is NULL.", scriptInfo->GetDebugInfo().c_str());
    else if (!source->isType(TYPEMASK_UNIT))
        sLog->outError("%s source object is not unit (TypeId: %u, Entry: %u, GUID: %u), skipping.", scriptInfo->GetDebugInfo().c_str(),
            source->GetTypeId(), source->GetEntry(), source->GetGUIDLow());
    else
    {
        WorldObject* wSource = dynamic_cast <WorldObject*> (source);
        if (!wSource)
            sLog->outError("%s source object could not be casted to world object (TypeId: %u, Entry: %u, GUID: %u), skipping.",
                scriptInfo->GetDebugInfo().c_str(), source->GetTypeId(), source->GetEntry(), source->GetGUIDLow());
        else
        {
            GameObject* pDoor = _FindGameObject(wSource, guid);
            if (!pDoor)
                sLog->outError("%s gameobject was not found (guid: %u).", scriptInfo->GetDebugInfo().c_str(), guid);
            else if (pDoor->GetGoType() != GAMEOBJECT_TYPE_DOOR)
                sLog->outError("%s gameobject is not a door (GoType: %u, Entry: %u, GUID: %u).",
                    scriptInfo->GetDebugInfo().c_str(), pDoor->GetGoType(), pDoor->GetEntry(), pDoor->GetGUIDLow());
            else if (bOpen == (pDoor->GetGoState() == GO_STATE_READY))
            {
                pDoor->UseDoorOrButton(nTimeToToggle);

                if (target && target->isType(TYPEMASK_GAMEOBJECT))
                {
                    GameObject* goTarget = target->ToGameObject();
                    if (goTarget && goTarget->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
                        goTarget->UseDoorOrButton(nTimeToToggle);
                }
            }
        }
    }
}

inline GameObject* Map::_FindGameObject(WorldObject* pSearchObject, uint32 guid) const
{
    GameObject* pGameObject = NULL;

    CellPair p(Trinity::ComputeCellPair(pSearchObject->GetPositionX(), pSearchObject->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;

    Trinity::GameObjectWithDbGUIDCheck goCheck(*pSearchObject, guid);
    Trinity::GameObjectSearcher<Trinity::GameObjectWithDbGUIDCheck> checker(pSearchObject, pGameObject, goCheck);

    TypeContainerVisitor<Trinity::GameObjectSearcher<Trinity::GameObjectWithDbGUIDCheck>, GridTypeMapContainer > objectChecker(checker);
    cell.Visit(p, objectChecker, *pSearchObject->GetMap());

    return pGameObject;
}

/// Process queued scripts
void Map::ScriptsProcess()
{
    if (m_scriptSchedule.empty())
        return;

    ///- Process overdue queued scripts
    ScriptScheduleMap::iterator iter = m_scriptSchedule.begin();
    // ok as multimap is a *sorted* associative container
    while (!m_scriptSchedule.empty() && (iter->first <= sWorld->GetGameTime()))
    {
        ScriptAction const& step = iter->second;

        Object* source = NULL;
        if (step.sourceGUID)
        {
            switch (GUID_HIPART(step.sourceGUID))
            {
                case HIGHGUID_ITEM: // as well as HIGHGUID_CONTAINER
                    if (Player* player = HashMapHolder<Player>::Find(step.ownerGUID))
                        source = player->GetItemByGuid(step.sourceGUID);
                    break;
                case HIGHGUID_UNIT:
                case HIGHGUID_VEHICLE:
                    source = HashMapHolder<Creature>::Find(step.sourceGUID);
                    break;
                case HIGHGUID_PET:
                    source = HashMapHolder<Pet>::Find(step.sourceGUID);
                    break;
                case HIGHGUID_PLAYER:
                    source = HashMapHolder<Player>::Find(step.sourceGUID);
                    break;
                case HIGHGUID_GAMEOBJECT:
                    source = HashMapHolder<GameObject>::Find(step.sourceGUID);
                    break;
                case HIGHGUID_CORPSE:
                    source = HashMapHolder<Corpse>::Find(step.sourceGUID);
                    break;
                case HIGHGUID_MO_TRANSPORT:
                    for (MapManager::TransportSet::iterator iter = sMapMgr->m_Transports.begin(); iter != sMapMgr->m_Transports.end(); ++iter)
                    {
                        if ((*iter)->GetGUID() == step.sourceGUID)
                        {
                            source = *iter;
                            break;
                        }
                    }
                    break;
                default:
                    sLog->outError("%s source with unsupported high guid (GUID: " UI64FMTD ", high guid: %u).",
                        step.script->GetDebugInfo().c_str(), step.sourceGUID, GUID_HIPART(step.sourceGUID));
                    break;
            }
        }

        Object* target = NULL;
        if (step.targetGUID)
        {
            switch (GUID_HIPART(step.targetGUID))
            {
                case HIGHGUID_UNIT:
                case HIGHGUID_VEHICLE:
                    target = HashMapHolder<Creature>::Find(step.targetGUID);
                    break;
                case HIGHGUID_PET:
                    target = HashMapHolder<Pet>::Find(step.targetGUID);
                    break;
                case HIGHGUID_PLAYER:                       // empty GUID case also
                    target = HashMapHolder<Player>::Find(step.targetGUID);
                    break;
                case HIGHGUID_GAMEOBJECT:
                    target = HashMapHolder<GameObject>::Find(step.targetGUID);
                    break;
                case HIGHGUID_CORPSE:
                    target = HashMapHolder<Corpse>::Find(step.targetGUID);
                    break;
                default:
                    sLog->outError("%s target with unsupported high guid (GUID: " UI64FMTD ", high guid: %u).",
                        step.script->GetDebugInfo().c_str(), step.targetGUID, GUID_HIPART(step.targetGUID));
                    break;
            }
        }

        switch (step.script->command)
        {
            case SCRIPT_COMMAND_TALK:
                if (step.script->Talk.ChatType > CHAT_TYPE_WHISPER && step.script->Talk.ChatType != CHAT_MSG_RAID_BOSS_WHISPER)
                {
                    sLog->outError("%s invalid chat type (%u) specified, skipping.", step.script->GetDebugInfo().c_str(), step.script->Talk.ChatType);
                    break;
                }
                if (step.script->Talk.Flags & SF_TALK_USE_PLAYER)
                {
                    if (Player* pSource = _GetScriptPlayerSourceOrTarget(source, target, step.script))
                    {
                        LocaleConstant loc_idx = pSource->GetSession()->GetSessionDbLocaleIndex();
                        std::string text(sObjectMgr->GetTrinityString(step.script->Talk.TextID, loc_idx));

                        switch (step.script->Talk.ChatType)
                        {
                            case CHAT_TYPE_SAY:
                                pSource->Say(text, LANG_UNIVERSAL);
                                break;
                            case CHAT_TYPE_YELL:
                                pSource->Yell(text, LANG_UNIVERSAL);
                                break;
                            case CHAT_TYPE_TEXT_EMOTE:
                            case CHAT_TYPE_BOSS_EMOTE:
                                pSource->TextEmote(text);
                                break;
                            case CHAT_TYPE_WHISPER:
                            case CHAT_MSG_RAID_BOSS_WHISPER:
                            {
                                uint64 targetGUID = target ? target->GetGUID() : 0;
                                if (!targetGUID || !IS_PLAYER_GUID(targetGUID))
                                    sLog->outError("%s attempt to whisper to non-player unit, skipping.", step.script->GetDebugInfo().c_str());
                                else
                                    pSource->Whisper(text, LANG_UNIVERSAL, targetGUID);
                                break;
                            }
                            default:
                                break;                              // must be already checked at load
                        }
                    }
                }
                else
                {
                    // Source or target must be Creature.
                    if (Creature* cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script))
                    {
                        uint64 targetGUID = target ? target->GetGUID() : 0;
                        switch (step.script->Talk.ChatType)
                        {
                            case CHAT_TYPE_SAY:
                                cSource->Say(step.script->Talk.TextID, LANG_UNIVERSAL, targetGUID);
                                break;
                            case CHAT_TYPE_YELL:
                                cSource->Yell(step.script->Talk.TextID, LANG_UNIVERSAL, targetGUID);
                                break;
                            case CHAT_TYPE_TEXT_EMOTE:
                                cSource->TextEmote(step.script->Talk.TextID, targetGUID);
                                break;
                            case CHAT_TYPE_BOSS_EMOTE:
                                cSource->MonsterTextEmote(step.script->Talk.TextID, targetGUID, true);
                                break;
                            case CHAT_TYPE_WHISPER:
                                if (!targetGUID || !IS_PLAYER_GUID(targetGUID))
                                    sLog->outError("%s attempt to whisper to non-player unit, skipping.", step.script->GetDebugInfo().c_str());
                                else
                                    cSource->Whisper(step.script->Talk.TextID, targetGUID);
                                break;
                            case CHAT_MSG_RAID_BOSS_WHISPER:
                                if (!targetGUID || !IS_PLAYER_GUID(targetGUID))
                                    sLog->outError("%s attempt to raidbosswhisper to non-player unit, skipping.", step.script->GetDebugInfo().c_str());
                                else
                                    cSource->MonsterWhisper(step.script->Talk.TextID, targetGUID, true);
                                break;
                            default:
                                break;                              // must be already checked at load
                        }
                    }
                }
                break;

            case SCRIPT_COMMAND_EMOTE:
                // Source or target must be Creature.
                if (Creature* cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script))
                {
                    if (step.script->Emote.Flags & SF_EMOTE_USE_STATE)
                        cSource->SetUInt32Value(UNIT_NPC_EMOTESTATE, step.script->Emote.EmoteID);
                    else
                        cSource->HandleEmoteCommand(step.script->Emote.EmoteID);
                }
                break;

            case SCRIPT_COMMAND_FIELD_SET:
                // Source or target must be Creature.
                if (Creature* cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script))
                {
                    // Validate field number.
                    if (step.script->FieldSet.FieldID <= OBJECT_FIELD_ENTRY || step.script->FieldSet.FieldID >= cSource->GetValuesCount())
                        sLog->outError("%s wrong field %u (max count: %u) in object (TypeId: %u, Entry: %u, GUID: %u) specified, skipping.",
                            step.script->GetDebugInfo().c_str(), step.script->FieldSet.FieldID,
                            cSource->GetValuesCount(), cSource->GetTypeId(), cSource->GetEntry(), cSource->GetGUIDLow());
                    else
                        cSource->SetUInt32Value(step.script->FieldSet.FieldID, step.script->FieldSet.FieldValue);
                }
                break;

            case SCRIPT_COMMAND_MOVE_TO:
                // Source or target must be Creature.
                if (Creature* cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script))
                {
                    cSource->SendMonsterMoveWithSpeed(step.script->MoveTo.DestX, step.script->MoveTo.DestY, step.script->MoveTo.DestZ, step.script->MoveTo.TravelTime);
                    cSource->GetMap()->CreatureRelocation(cSource, step.script->MoveTo.DestX, step.script->MoveTo.DestY, step.script->MoveTo.DestZ, 0);
                }
                break;

            case SCRIPT_COMMAND_FLAG_SET:
                // Source or target must be Creature.
                if (Creature* cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script))
                {
                    // Validate field number.
                    if (step.script->FlagToggle.FieldID <= OBJECT_FIELD_ENTRY || step.script->FlagToggle.FieldID >= cSource->GetValuesCount())
                        sLog->outError("%s wrong field %u (max count: %u) in object (TypeId: %u, Entry: %u, GUID: %u) specified, skipping.",
                            step.script->GetDebugInfo().c_str(), step.script->FlagToggle.FieldID,
                            source->GetValuesCount(), source->GetTypeId(), source->GetEntry(), source->GetGUIDLow());
                    else
                        cSource->SetFlag(step.script->FlagToggle.FieldID, step.script->FlagToggle.FieldValue);
                }
                break;

            case SCRIPT_COMMAND_FLAG_REMOVE:
                // Source or target must be Creature.
                if (Creature* cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script))
                {
                    // Validate field number.
                    if (step.script->FlagToggle.FieldID <= OBJECT_FIELD_ENTRY || step.script->FlagToggle.FieldID >= cSource->GetValuesCount())
                        sLog->outError("%s wrong field %u (max count: %u) in object (TypeId: %u, Entry: %u, GUID: %u) specified, skipping.",
                            step.script->GetDebugInfo().c_str(), step.script->FlagToggle.FieldID,
                            source->GetValuesCount(), source->GetTypeId(), source->GetEntry(), source->GetGUIDLow());
                    else
                        cSource->RemoveFlag(step.script->FlagToggle.FieldID, step.script->FlagToggle.FieldValue);
                }
                break;

            case SCRIPT_COMMAND_TELEPORT_TO:
                if (step.script->TeleportTo.Flags & SF_TELEPORT_USE_CREATURE)
                {
                    // Source or target must be Creature.
                    if (Creature* cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script, true))
                        cSource->NearTeleportTo(step.script->TeleportTo.DestX, step.script->TeleportTo.DestY, step.script->TeleportTo.DestZ, step.script->TeleportTo.Orientation);
                }
                else
                {
                    // Source or target must be Player.
                    if (Player* pSource = _GetScriptPlayerSourceOrTarget(source, target, step.script))
                        pSource->TeleportTo(step.script->TeleportTo.MapID, step.script->TeleportTo.DestX, step.script->TeleportTo.DestY, step.script->TeleportTo.DestZ, step.script->TeleportTo.Orientation);
                }
                break;

            case SCRIPT_COMMAND_QUEST_EXPLORED:
            {
                if (!source)
                {
                    sLog->outError("%s source object is NULL.", step.script->GetDebugInfo().c_str());
                    break;
                }
                if (!target)
                {
                    sLog->outError("%s target object is NULL.", step.script->GetDebugInfo().c_str());
                    break;
                }

                // when script called for item spell casting then target == (unit or GO) and source is player
                WorldObject* worldObject;
                Player* pTarget = target->ToPlayer();
                if (pTarget)
                {
                    if (source->GetTypeId() != TYPEID_UNIT && source->GetTypeId() != TYPEID_GAMEOBJECT && source->GetTypeId() != TYPEID_PLAYER)
                    {
                        sLog->outError("%s source is not unit, gameobject or player (TypeId: %u, Entry: %u, GUID: %u), skipping.",
                            step.script->GetDebugInfo().c_str(), source->GetTypeId(), source->GetEntry(), source->GetGUIDLow());
                        break;
                    }
                    worldObject = dynamic_cast<WorldObject*>(source);
                }
                else
                {
                    pTarget = source->ToPlayer();
                    if (target)
                    {
                        if (target->GetTypeId() != TYPEID_UNIT && target->GetTypeId() != TYPEID_GAMEOBJECT && target->GetTypeId() != TYPEID_PLAYER)
                        {
                            sLog->outError("%s target is not unit, gameobject or player (TypeId: %u, Entry: %u, GUID: %u), skipping.",
                                step.script->GetDebugInfo().c_str(), target->GetTypeId(), target->GetEntry(), target->GetGUIDLow());
                            break;
                        }
                        worldObject =  dynamic_cast<WorldObject*>(target);
                    }
                    else
                    {
                        sLog->outError("%s neither source nor target is player (source: TypeId: %u, Entry: %u, GUID: %u; target: TypeId: %u, Entry: %u, GUID: %u), skipping.",
                            step.script->GetDebugInfo().c_str(),
                            source ? source->GetTypeId() : 0, source ? source->GetEntry() : 0, source ? source->GetGUIDLow() : 0,
                            target ? target->GetTypeId() : 0, target ? target->GetEntry() : 0, target ? target->GetGUIDLow() : 0);
                        break;
                    }
                }

                // quest id and flags checked at script loading
                if ((worldObject->GetTypeId() != TYPEID_UNIT || ((Unit*)worldObject)->isAlive()) &&
                    (step.script->QuestExplored.Distance == 0 || worldObject->IsWithinDistInMap(pTarget, float(step.script->QuestExplored.Distance))))
                    pTarget->AreaExploredOrEventHappens(step.script->QuestExplored.QuestID);
                else
                    pTarget->FailQuest(step.script->QuestExplored.QuestID);

                break;
            }

            case SCRIPT_COMMAND_KILL_CREDIT:
                // Source or target must be Player.
                if (Player* pSource = _GetScriptPlayerSourceOrTarget(source, target, step.script))
                {
                    if (step.script->KillCredit.Flags & SF_KILLCREDIT_REWARD_GROUP)
                        pSource->RewardPlayerAndGroupAtEvent(step.script->KillCredit.CreatureEntry, pSource);
                    else
                        pSource->KilledMonsterCredit(step.script->KillCredit.CreatureEntry, 0);
                }
                break;

            case SCRIPT_COMMAND_RESPAWN_GAMEOBJECT:
                if (!step.script->RespawnGameobject.GOGuid)
                {
                    sLog->outError("%s gameobject guid (datalong) is not specified.", step.script->GetDebugInfo().c_str());
                    break;
                }

                // Source or target must be WorldObject.
                if (WorldObject* pSummoner = _GetScriptWorldObject(source, true, step.script))
                {
                    GameObject* pGO = _FindGameObject(pSummoner, step.script->RespawnGameobject.GOGuid);
                    if (!pGO)
                    {
                        sLog->outError("%s gameobject was not found (guid: %u).", step.script->GetDebugInfo().c_str(), step.script->RespawnGameobject.GOGuid);
                        break;
                    }

                    if (pGO->GetGoType() == GAMEOBJECT_TYPE_FISHINGNODE ||
                        pGO->GetGoType() == GAMEOBJECT_TYPE_DOOR        ||
                        pGO->GetGoType() == GAMEOBJECT_TYPE_BUTTON      ||
                        pGO->GetGoType() == GAMEOBJECT_TYPE_TRAP)
                    {
                        sLog->outError("%s can not be used with gameobject of type %u (guid: %u).",
                            step.script->GetDebugInfo().c_str(), uint32(pGO->GetGoType()), step.script->RespawnGameobject.GOGuid);
                        break;
                    }

                    // Check that GO is not spawned
                    if (!pGO->isSpawned())
                    {
                        int32 nTimeToDespawn = std::max(5, int32(step.script->RespawnGameobject.DespawnDelay));
                        pGO->SetLootState(GO_READY);
                        pGO->SetRespawnTime(nTimeToDespawn);

                        pGO->GetMap()->AddToMap(pGO);
                    }
                }
                break;

            case SCRIPT_COMMAND_TEMP_SUMMON_CREATURE:
            {
                // Source must be WorldObject.
                if (WorldObject* pSummoner = _GetScriptWorldObject(source, true, step.script))
                {
                    if (!step.script->TempSummonCreature.CreatureEntry)
                        sLog->outError("%s creature entry (datalong) is not specified.", step.script->GetDebugInfo().c_str());
                    else
                    {
                        float x = step.script->TempSummonCreature.PosX;
                        float y = step.script->TempSummonCreature.PosY;
                        float z = step.script->TempSummonCreature.PosZ;
                        float o = step.script->TempSummonCreature.Orientation;

                        if (!pSummoner->SummonCreature(step.script->TempSummonCreature.CreatureEntry, x, y, z, o, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, step.script->TempSummonCreature.DespawnDelay))
                            sLog->outError("%s creature was not spawned (entry: %u).", step.script->GetDebugInfo().c_str(), step.script->TempSummonCreature.CreatureEntry);
                    }
                }
                break;
            }

            case SCRIPT_COMMAND_OPEN_DOOR:
            case SCRIPT_COMMAND_CLOSE_DOOR:
                _ScriptProcessDoor(source, target, step.script);
                break;

            case SCRIPT_COMMAND_ACTIVATE_OBJECT:
                // Source must be Unit.
                if (Unit* pSource = _GetScriptUnit(source, true, step.script))
                {
                    // Target must be GameObject.
                    if (!target)
                    {
                        sLog->outError("%s target object is NULL.", step.script->GetDebugInfo().c_str());
                        break;
                    }

                    if (target->GetTypeId() != TYPEID_GAMEOBJECT)
                    {
                        sLog->outError("%s target object is not gameobject (TypeId: %u, Entry: %u, GUID: %u), skipping.",
                            step.script->GetDebugInfo().c_str(), target->GetTypeId(), target->GetEntry(), target->GetGUIDLow());
                        break;
                    }

                    if (GameObject* pGO = target->ToGameObject())
                        pGO->Use(pSource);
                }
                break;

            case SCRIPT_COMMAND_REMOVE_AURA:
            {
                // Source (datalong2 != 0) or target (datalong2 == 0) must be Unit.
                bool bReverse = step.script->RemoveAura.Flags & SF_REMOVEAURA_REVERSE;
                if (Unit* pTarget = _GetScriptUnit(bReverse ? source : target, bReverse, step.script))
                    pTarget->RemoveAurasDueToSpell(step.script->RemoveAura.SpellID);
                break;
            }

            case SCRIPT_COMMAND_CAST_SPELL:
            {
                // TODO: Allow gameobjects to be targets and casters
                if (!source && !target)
                {
                    sLog->outError("%s source and target objects are NULL.", step.script->GetDebugInfo().c_str());
                    break;
                }

                Unit* uSource = NULL;
                Unit* uTarget = NULL;
                // source/target cast spell at target/source (script->datalong2: 0: s->t 1: s->s 2: t->t 3: t->s
                switch (step.script->CastSpell.Flags)
                {
                    case SF_CASTSPELL_SOURCE_TO_TARGET: // source -> target
                        uSource = source ? source->ToUnit() : NULL;
                        uTarget = target ? target->ToUnit() : NULL;
                        break;
                    case SF_CASTSPELL_SOURCE_TO_SOURCE: // source -> source
                        uSource = source ? source->ToUnit() : NULL;
                        uTarget = uSource;
                        break;
                    case SF_CASTSPELL_TARGET_TO_TARGET: // target -> target
                        uSource = target ? target->ToUnit() : NULL;
                        uTarget = uSource;
                        break;
                    case SF_CASTSPELL_TARGET_TO_SOURCE: // target -> source
                        uSource = target ? target->ToUnit() : NULL;
                        uTarget = source ? source->ToUnit() : NULL;
                        break;
                    case SF_CASTSPELL_SEARCH_CREATURE: // source -> creature with entry
                        uSource = source ? source->ToUnit() : NULL;
                        uTarget = uSource ? GetClosestCreatureWithEntry(uSource, abs(step.script->CastSpell.CreatureEntry), step.script->CastSpell.SearchRadius) : NULL;
                        break;
                }

                if (!uSource || !uSource->isType(TYPEMASK_UNIT))
                {
                    sLog->outError("%s no source unit found for spell %u", step.script->GetDebugInfo().c_str(), step.script->CastSpell.SpellID);
                    break;
                }

                if (!uTarget || !uTarget->isType(TYPEMASK_UNIT))
                {
                    sLog->outError("%s no target unit found for spell %u", step.script->GetDebugInfo().c_str(), step.script->CastSpell.SpellID);
                    break;
                }

                bool triggered = (step.script->CastSpell.Flags != 4) ?
                    step.script->CastSpell.CreatureEntry & SF_CASTSPELL_TRIGGERED :
                    step.script->CastSpell.CreatureEntry < 0;
                uSource->CastSpell(uTarget, step.script->CastSpell.SpellID, triggered);
                break;
            }

            case SCRIPT_COMMAND_PLAY_SOUND:
                // Source must be WorldObject.
                if (WorldObject* pSource = _GetScriptWorldObject(source, true, step.script))
                {
                    // PlaySound.Flags bitmask: 0/1=anyone/target
                    Player* pTarget = NULL;
                    if (step.script->PlaySound.Flags & SF_PLAYSOUND_TARGET_PLAYER)
                    {
                        // Target must be Player.
                        pTarget = _GetScriptPlayer(target, false, step.script);
                        if (!pTarget)
                            break;
                    }

                    // PlaySound.Flags bitmask: 0/2=without/with distance dependent
                    if (step.script->PlaySound.Flags & SF_PLAYSOUND_DISTANCE_SOUND)
                        pSource->PlayDistanceSound(step.script->PlaySound.SoundID, pTarget);
                    else
                        pSource->PlayDirectSound(step.script->PlaySound.SoundID, pTarget);
                }
                break;

            case SCRIPT_COMMAND_CREATE_ITEM:
                // Target or source must be Player.
                if (Player* pReceiver = _GetScriptPlayerSourceOrTarget(source, target, step.script))
                {
                    ItemPosCountVec dest;
                    InventoryResult msg = pReceiver->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, step.script->CreateItem.ItemEntry, step.script->CreateItem.Amount);
                    if (msg == EQUIP_ERR_OK)
                    {
                        if (Item* item = pReceiver->StoreNewItem(dest, step.script->CreateItem.ItemEntry, true))
                            pReceiver->SendNewItem(item, step.script->CreateItem.Amount, false, true);
                    }
                    else
                        pReceiver->SendEquipError(msg, NULL, NULL, step.script->CreateItem.ItemEntry);
                }
                break;

            case SCRIPT_COMMAND_DESPAWN_SELF:
                // Target or source must be Creature.
                if (Creature* cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script, true))
                    cSource->DespawnOrUnsummon(step.script->DespawnSelf.DespawnDelay);
                break;

            case SCRIPT_COMMAND_LOAD_PATH:
                // Source must be Unit.
                if (Unit* pSource = _GetScriptUnit(source, true, step.script))
                {
                    if (!sWaypointMgr->GetPath(step.script->LoadPath.PathID))
                        sLog->outError("%s source object has an invalid path (%u), skipping.", step.script->GetDebugInfo().c_str(), step.script->LoadPath.PathID);
                    else
                        pSource->GetMotionMaster()->MovePath(step.script->LoadPath.PathID, step.script->LoadPath.IsRepeatable);
                }
                break;

            case SCRIPT_COMMAND_CALLSCRIPT_TO_UNIT:
            {
                if (!step.script->CallScript.CreatureEntry)
                {
                    sLog->outError("%s creature entry is not specified, skipping.", step.script->GetDebugInfo().c_str());
                    break;
                }
                if (!step.script->CallScript.ScriptID)
                {
                    sLog->outError("%s script id is not specified, skipping.", step.script->GetDebugInfo().c_str());
                    break;
                }

                Creature* cTarget = NULL;
                if (source) //using grid searcher
                {
                    WorldObject* wSource = dynamic_cast <WorldObject*> (source);

                    CellPair p(Trinity::ComputeCellPair(wSource->GetPositionX(), wSource->GetPositionY()));
                    Cell cell(p);
                    cell.data.Part.reserved = ALL_DISTRICT;

                    Trinity::CreatureWithDbGUIDCheck target_check(wSource, step.script->CallScript.CreatureEntry);
                    Trinity::CreatureSearcher<Trinity::CreatureWithDbGUIDCheck> checker(wSource, cTarget, target_check);

                    TypeContainerVisitor<Trinity::CreatureSearcher <Trinity::CreatureWithDbGUIDCheck>, GridTypeMapContainer > unit_checker(checker);
                    cell.Visit(p, unit_checker, *wSource->GetMap());
                }
                else //check hashmap holders
                {
                    if (CreatureData const* data = sObjectMgr->GetCreatureData(step.script->CallScript.CreatureEntry))
                        cTarget = ObjectAccessor::GetObjectInWorld<Creature>(data->mapid, data->posX, data->posY, MAKE_NEW_GUID(step.script->CallScript.CreatureEntry, data->id, HIGHGUID_UNIT), cTarget);
                }

                if (!cTarget)
                {
                    sLog->outError("%s target was not found (entry: %u)", step.script->GetDebugInfo().c_str(), step.script->CallScript.CreatureEntry);
                    break;
                }

                //Lets choose our ScriptMap map
                ScriptMapMap* datamap = GetScriptsMapByType(ScriptsType(step.script->CallScript.ScriptType));
                //if no scriptmap present...
                if (!datamap)
                {
                    sLog->outError("%s unknown scriptmap (%u) specified, skipping.", step.script->GetDebugInfo().c_str(), step.script->CallScript.ScriptType);
                    break;
                }

                // Insert script into schedule but do not start it
                ScriptsStart(*datamap, step.script->CallScript.ScriptID, cTarget, NULL);
                break;
            }

            case SCRIPT_COMMAND_KILL:
                // Source or target must be Creature.
                if (Creature* cSource = _GetScriptCreatureSourceOrTarget(source, target, step.script))
                {
                    if (cSource->isDead())
                        sLog->outError("%s creature is already dead (Entry: %u, GUID: %u)",
                            step.script->GetDebugInfo().c_str(), cSource->GetEntry(), cSource->GetGUIDLow());
                    else
                    {
                        cSource->setDeathState(JUST_DIED);
                        if (step.script->Kill.RemoveCorpse == 1)
                            cSource->RemoveCorpse();
                    }
                }
                break;

            case SCRIPT_COMMAND_ORIENTATION:
                // Source must be Unit.
                if (Unit* pSource = _GetScriptUnit(source, true, step.script))
                {
                    if (step.script->Orientation.Flags& SF_ORIENTATION_FACE_TARGET)
                    {
                        // Target must be Unit.
                        Unit* pTarget = _GetScriptUnit(target, false, step.script);
                        if (!pTarget)
                            break;

                        pSource->SetInFront(pTarget);
                    }
                    else
                        pSource->SetOrientation(step.script->Orientation.Orientation);

                    pSource->SendMovementFlagUpdate();
                }
                break;

            case SCRIPT_COMMAND_EQUIP:
                // Source must be Creature.
                if (Creature* cSource = _GetScriptCreature(source, true, step.script))
                    cSource->LoadEquipment(step.script->Equip.EquipmentID);
                break;

            case SCRIPT_COMMAND_MODEL:
                // Source must be Creature.
                if (Creature* cSource = _GetScriptCreature(source, true, step.script))
                    cSource->SetDisplayId(step.script->Model.ModelID);
                break;

            case SCRIPT_COMMAND_CLOSE_GOSSIP:
                // Source must be Player.
                if (Player* pSource = _GetScriptPlayer(source, true, step.script))
                    pSource->PlayerTalkClass->SendCloseGossip();
                break;

            case SCRIPT_COMMAND_PLAYMOVIE:
                // Source must be Player.
                if (Player* pSource = _GetScriptPlayer(source, true, step.script))
                    pSource->SendMovieStart(step.script->PlayMovie.MovieID);
                break;

            default:
                sLog->outError("Unknown script command %s.", step.script->GetDebugInfo().c_str());
                break;
        }

        m_scriptSchedule.erase(iter);
        iter = m_scriptSchedule.begin();
        sScriptMgr->DecreaseScheduledScriptCount();
    }
}
