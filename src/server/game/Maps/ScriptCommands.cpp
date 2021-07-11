/*
* Copyright (C) 2017-2018 LightsHope <https://github.com/lightshope>
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

#include "Map.h"
#include "ScriptMgr.h"
#include "GridSearchers.h"
#include "InstanceData.h"
#include "CreatureEventAI.h"
#include "CreatureAIImpl.h"
#include "NullCreatureAI.h"
#include "GameEventMgr.h"
#include "ObjectMgr.h"
#include "Group.h"

// Script commands should return false by default.
// If they return true the rest of the script is aborted.

inline bool ShouldAbortScript(ScriptInfo const& script)
{
    return (script.raw.data[4] & SF_GENERAL_ABORT_ON_FAILURE);
}

// SCRIPT_COMMAND_TALK (0)
bool Map::ScriptCommand_Talk(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    WorldObject* pSource = source;

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_TALK (script id %u) call for a nullptr or non-worldobject source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    Unit* unitTarget = ToUnit(target);
    int32 textId = script.talk.textId[0];

    // May have text for random
    if (script.talk.textId[1])
    {
        int i = 2;
        for (; i < MAX_TEXT_ID; ++i)
        {
            if (!script.talk.textId[i])
                break;
        }

        // Use one random
        textId = script.talk.textId[rand() % i];
    }

    DoScriptText(textId, pSource, unitTarget, script.talk.chatType > 0 ? script.talk.chatType : -1);

    return false;
}

// SCRIPT_COMMAND_EMOTE (1)
bool Map::ScriptCommand_Emote(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_EMOTE (script id %u) call for a nullptr or non-worldobject source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    uint32 emoteCount = 1;
    for (; emoteCount < MAX_EMOTE_ID && script.emote.emoteId[emoteCount]; ++emoteCount);
    uint32 const emoteId = script.emote.emoteId[urand(0, emoteCount - 1)];

    // This is a targeted emote.
    if (script.emote.isTargeted)
    {
        Creature* pCreatureSource = pSource->ToCreature();
        if (!pCreatureSource)
        {
            sLog.outError("SCRIPT_COMMAND_EMOTE (script id %u) call for targeted emote with non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
            return ShouldAbortScript(script);
        }

        Unit* pTarget = ToUnit(target);
        if (!pTarget)
        {
            sLog.outError("SCRIPT_COMMAND_EMOTE (script id %u) call for targeted emote with non-unit target (TypeId: %u), skipping.", script.id, target ? target->GetTypeId() : 0);
            return ShouldAbortScript(script);
        }

        // Abort if target is in combat, or already doing a targeted emote.
        if (pCreatureSource->IsInCombat() || pCreatureSource->HasCreatureState(CSTATE_TARGETED_EMOTE))
            return ShouldAbortScript(script);

        pCreatureSource->PauseOutOfCombatMovement(8 * IN_MILLISECONDS);
        pCreatureSource->AddCreatureState(CSTATE_TARGETED_EMOTE);

        TargetedEmoteEvent *pEmoteEvent = new TargetedEmoteEvent(*pCreatureSource, pTarget->GetObjectGuid(), emoteId);
        pCreatureSource->m_Events.AddEvent(pEmoteEvent, pCreatureSource->m_Events.CalculateTime(2000));
        TargetedEmoteCleanupEvent *pCleanupEvent = new TargetedEmoteCleanupEvent(*pCreatureSource, pCreatureSource->GetOrientation());
        pCreatureSource->m_Events.AddEvent(pCleanupEvent, pCreatureSource->m_Events.CalculateTime(6000));
    }
    else
        pSource->HandleEmote(emoteId);

    return false;
}

// SCRIPT_COMMAND_FIELD_SET(2)
bool Map::ScriptCommand_FieldSet(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    if (!source)
    {
        sLog.outError("SCRIPT_COMMAND_FIELD_SET (script id %u) call for a nullptr object, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    if (script.setField.fieldId <= OBJECT_FIELD_ENTRY || script.setField.fieldId >= source->GetValuesCount())
    {
        sLog.outError("SCRIPT_COMMAND_FIELD_SET (script id %u) call for wrong field %u (max count: %u) in object (TypeId: %u).",
            script.id, script.setField.fieldId, source->GetValuesCount(), source->GetTypeId());
        return ShouldAbortScript(script);
    }

    source->SetUInt32Value(script.setField.fieldId, script.setField.fieldValue);

    return false;
}

// SCRIPT_COMMAND_MOVE_TO (3)
bool Map::ScriptCommand_MoveTo(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_MOVE_TO (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsAlive())
        return ShouldAbortScript(script);

    float x = script.x;
    float y = script.y;
    float z = script.z;

    switch (script.moveTo.coordinatesType)
    {
        case SO_MOVETO_COORDINATES_RELATIVE_TO_TARGET:
        {
            if (WorldObject* pTarget = target)
            {
                // Coordinates are added to those of the target.
                x += pTarget->GetPositionX();
                y += pTarget->GetPositionY();
                z += pTarget->GetPositionZ();
            }
            else
            {
                sLog.outError("SCRIPT_COMMAND_MOVE_TO (script id %u) call with datalong = %u for a nullptr or non-worldobject target, skipping.", script.id, script.moveTo.coordinatesType);
                return ShouldAbortScript(script);
            }
            break;
        }
        case SO_MOVETO_COORDINATES_DISTANCE_FROM_TARGET:
        {
            if (WorldObject* pTarget = target)
            {
                // X is distance from the target.
                float distance = x;
                float angle = script.o < 0.0f ? pTarget->GetAngle(pSource) : frand(0, 2 * M_PI_F);
                pTarget->GetNearPoint(pSource, x, y, z, 0, distance, angle);
            }
            else
            {
                sLog.outError("SCRIPT_COMMAND_MOVE_TO (script id %u) call with datalong = %u for a nullptr or non-worldobject target, skipping.", script.id, script.moveTo.coordinatesType);
                return ShouldAbortScript(script);
            }
            break;
        }
        case SO_MOVETO_COORDINATES_RANDOM_POINT:
        {
            pSource->GetRandomPoint(x, y, z, script.o, x, y, z);
            break;
        }
    }

    // Only move if we can move.
    if (pSource->HasUnitState(UNIT_STAT_NOT_MOVE) && !(script.moveTo.flags & SF_MOVETO_FORCED))
        return ShouldAbortScript(script);

    float speed = script.moveTo.travelTime != 0 ? pSource->GetDistance(x, y, z) / ((float)script.moveTo.travelTime * 0.001f) : 0.0f;
    float orientation = script.o > 0.0f ? script.o : -10.0f;

    // o is distance in this case
    if (script.moveTo.coordinatesType == SO_MOVETO_COORDINATES_RANDOM_POINT)
        orientation = -10.0f;

    if (script.moveTo.flags & SF_MOVETO_POINT_MOVEGEN)
        pSource->GetMotionMaster()->MovePoint(script.moveTo.pointId, x, y, z, script.moveTo.movementOptions, speed, orientation);
    else
        pSource->MonsterMoveWithSpeed(x, y, z, orientation, speed, script.moveTo.movementOptions);

    return false;
}

// SCRIPT_COMMAND_MODIFY_FLAGS (4)
bool Map::ScriptCommand_ModifyFlags(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    if (!source)
    {
        sLog.outError("SCRIPT_COMMAND_MODIFY_FLAGS (script id %u) call for a nullptr object, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    if (script.modFlags.fieldId <= OBJECT_FIELD_ENTRY || script.modFlags.fieldId >= source->GetValuesCount())
    {
        sLog.outError("SCRIPT_COMMAND_MODIFY_FLAGS (script id %u) call for wrong field %u (max count: %u) in object (TypeId: %u).",
            script.id, script.modFlags.fieldId, source->GetValuesCount(), source->GetTypeId());
        return ShouldAbortScript(script);
    }

    // Add Flags
    if (script.modFlags.mode == SO_MODIFYFLAGS_SET)
        source->SetFlag(script.modFlags.fieldId, script.modFlags.fieldValue);
    // Remove Flags
    else if (script.modFlags.mode == SO_MODIFYFLAGS_REMOVE)
        source->RemoveFlag(script.modFlags.fieldId, script.modFlags.fieldValue);
    // Toggle Flags
    else
    {
        if (source->HasFlag(script.modFlags.fieldId, script.modFlags.fieldValue))
            source->RemoveFlag(script.modFlags.fieldId, script.modFlags.fieldValue);
        else
            source->SetFlag(script.modFlags.fieldId, script.modFlags.fieldValue);
    }

    return false;
}

// SCRIPT_COMMAND_INTERRUPT_CASTS (5)
bool Map::ScriptCommand_InterruptCasts(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_INTERRUPT_CAST (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->InterruptNonMeleeSpells(script.interruptCasts.withDelayed, script.interruptCasts.spellId);

    return false;
}

// SCRIPT_COMMAND_TELEPORT_TO (6)
bool Map::ScriptCommand_TeleportTo(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_TELEPORT_TO (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (pSource->GetTypeId() == TYPEID_PLAYER)
        (static_cast<Player*>(pSource))->TeleportTo(script.teleportTo.mapId, script.x, script.y, script.z, script.o, script.teleportTo.teleportOptions);
    else
        pSource->NearTeleportTo(script, script.teleportTo.teleportOptions);

    return false;
}

// SCRIPT_COMMAND_QUEST_EXPLORED (7)
bool Map::ScriptCommand_QuestExplored(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Player* pPlayer;

    if (!((pPlayer = ToPlayer(target)) || (pPlayer = ToPlayer(source))))
    {
        sLog.outError("SCRIPT_COMMAND_QUEST_EXPLORED (script id %u) call for a nullptr player, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    WorldObject* pWorldObject = source && !source->IsPlayer() ? source : (target && !target->IsPlayer() ? target : nullptr);
    Group* pGroup = pPlayer->GetGroup();

    if (script.questExplored.group && pGroup)
    {
        for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* pGroupMember = itr->getSource();
            if (pGroupMember && (script.questExplored.distance == 0 || !pWorldObject || pWorldObject->IsWithinDistInMap(pGroupMember, float(script.questExplored.distance))))
                pGroupMember->AreaExploredOrEventHappens(script.questExplored.questId);
            else
                pGroupMember->FailQuest(script.questExplored.questId);
        }
    }
    else if ((script.questExplored.distance == 0 || !pWorldObject || pWorldObject->IsWithinDistInMap(pPlayer, float(script.questExplored.distance))))
        pPlayer->AreaExploredOrEventHappens(script.questExplored.questId);
    else
        pPlayer->FailQuest(script.questExplored.questId);

    return false;
}

// SCRIPT_COMMAND_KILL_CREDIT (8)
bool Map::ScriptCommand_KillCredit(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Player* pSource;

    // accept player in any one from target/source arg
    if ((pSource = ToPlayer(target)) || (pSource = ToPlayer(source)))
    {
        if (script.killCredit.isGroupCredit)
            pSource->RewardPlayerAndGroupAtEvent(script.killCredit.creatureEntry, pSource);
        else
            pSource->KilledMonsterCredit(script.killCredit.creatureEntry);
    }
    else
    {
        sLog.outError("SCRIPT_COMMAND_KILL_CREDIT (script id %u) call for a nullptr object, skipping.", script.id);
        return ShouldAbortScript(script);
    }
    

    return false;
}

// SCRIPT_COMMAND_RESPAWN_GAMEOBJECT (9)
bool Map::ScriptCommand_RespawnGameObject(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    GameObject* pGo = nullptr;
    uint32 guidlow = script.respawnGo.goGuid;

    if (guidlow)
    {
        GameObjectData const* goData = sObjectMgr.GetGOData(guidlow);
        if (!goData)
            return ShouldAbortScript(script); // checked at load

        pGo = GetGameObject(ObjectGuid(HIGHGUID_GAMEOBJECT, goData->id, guidlow));
    }
    else if (target && target->GetTypeId() == TYPEID_GAMEOBJECT)
        pGo = static_cast<GameObject*>(target);
    else if (source && source->GetTypeId() == TYPEID_GAMEOBJECT)
        pGo = static_cast<GameObject*>(source);

    if (!pGo)
    {
        sLog.outError("SCRIPT_COMMAND_RESPAWN_GAMEOBJECT (script id %u) failed for gameobject(guid: %u).", script.id, guidlow);
        return ShouldAbortScript(script);
    }

    int32 time_to_despawn = script.respawnGo.despawnDelay < 5 ? 5 : script.respawnGo.despawnDelay;

    if (pGo->GetGoType() == GAMEOBJECT_TYPE_FISHINGNODE ||
        pGo->GetGoType() == GAMEOBJECT_TYPE_DOOR)
    {
        sLog.outError("SCRIPT_COMMAND_RESPAWN_GAMEOBJECT (script id %u) can not be used with gameobject of type %u (guid: %u).", script.id, uint32(pGo->GetGoType()), script.respawnGo.goGuid);
        return ShouldAbortScript(script);
    }

    if (pGo->isSpawned())
        return ShouldAbortScript(script);          //gameobject already spawned

    pGo->SetLootState(GO_READY);
    pGo->SetRespawnTime(time_to_despawn);        //despawn object in ? seconds

    Add(pGo);

    return false;
}

// SCRIPT_COMMAND_TEMP_SUMMON_CREATURE (10)
bool Map::ScriptCommand_SummonCreature(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    if (!script.summonCreature.creatureEntry)
    {
        sLog.outError("SCRIPT_COMMAND_TEMP_SUMMON_CREATURE (script id %u) call for a nullptr creature, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    WorldObject* pSummoner = source;

    if (!pSummoner)
    {
        sLog.outError("SCRIPT_COMMAND_TEMP_SUMMON_CREATURE (script id %u) call for a nullptr or non-worldobject source (TypeId: %u, skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    float x = script.x;
    float y = script.y;
    float z = script.z;
    float o = script.o;

    if (script.summonCreature.flags & SF_SUMMONCREATURE_UNIQUE || script.summonCreature.flags & SF_SUMMONCREATURE_UNIQUE_TEMP)
    {
        float dist = script.summonCreature.uniqueDistance ? script.summonCreature.uniqueDistance : (pSummoner->GetDistance(x, y, z) + 50.0f) * 2;
        std::list<Creature*> foundCreatures;

        GetCreatureListWithEntryInGrid(foundCreatures, pSummoner, script.summonCreature.creatureEntry, dist);

        if (!foundCreatures.empty())
        {
            uint32 exAmount = 0;
            uint32 reqAmount = script.summonCreature.uniqueLimit ? script.summonCreature.uniqueLimit : 1;

            if (script.summonCreature.flags & SF_SUMMONCREATURE_UNIQUE)
                exAmount = foundCreatures.size();
            else
                exAmount = count_if(foundCreatures.begin(), foundCreatures.end(), [&](Creature* c) { return c->IsTemporarySummon(); });

            if (exAmount >= reqAmount)
                return ShouldAbortScript(script);
        }
    }

    Creature* pCreature = pSummoner->SummonCreature(script.summonCreature.creatureEntry, x, y, z, o,
        TempSummonType(script.summonCreature.despawnType), script.summonCreature.despawnDelay, script.summonCreature.flags & SF_SUMMONCREATURE_ACTIVE, 0,
        (script.summonCreature.flags & SF_SUMMONCREATURE_NULL_AI) ? (CreatureAiSetter)([](Creature* pCreature) { pCreature->GetMotionMaster()->Initialize(); pCreature->SetAI(new NullCreatureAI(pCreature));}) : nullptr);

    if (!pCreature)
    {
        sLog.outError("SCRIPT_COMMAND_TEMP_SUMMON (script id %u) failed for creature (entry: %u).", script.id, script.summonCreature.creatureEntry);
        return ShouldAbortScript(script);
    }

    if (script.summonCreature.flags & SF_SUMMONCREATURE_SET_RUN)
        pCreature->SetWalk(false);

    if (script.summonCreature.attackTarget >= 0)
    {
        if (Unit* pAttackTarget = ToUnit(GetTargetByType(pSummoner, ToUnit(target), this, script.summonCreature.attackTarget)))
        {
            if (pCreature->AI())
                pCreature->AI()->AttackStart(pAttackTarget);
        }
    }

    if (script.summonCreature.scriptId)
        ScriptsStart(sGenericScripts, script.summonCreature.scriptId, pCreature->GetObjectGuid(), target ? target->GetObjectGuid() : ObjectGuid());

    return false;
}

// SCRIPT_COMMAND_OPEN_DOOR (11)
bool Map::ScriptCommand_OpenDoor(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    GameObject* pDoor = nullptr;
    uint32 guidlow = script.openDoor.goGuid;

    if (guidlow)
    {
        GameObjectData const* goData = sObjectMgr.GetGOData(guidlow);
        if (!goData)                                // checked at load
            return ShouldAbortScript(script);

        pDoor = GetGameObject(ObjectGuid(HIGHGUID_GAMEOBJECT, goData->id, guidlow));
    }
    else if (target && target->GetTypeId() == TYPEID_GAMEOBJECT)
        pDoor = static_cast<GameObject*>(target);
    else if (source && source->GetTypeId() == TYPEID_GAMEOBJECT)
        pDoor = static_cast<GameObject*>(source);

    if (!pDoor)
    {
        sLog.outError("SCRIPT_COMMAND_OPEN_DOOR (script id %u) failed for gameobject(guid: %u).", script.id, guidlow);
        return ShouldAbortScript(script);
    }

    if (pDoor->GetGoType() != GAMEOBJECT_TYPE_DOOR)
    {
        sLog.outError("SCRIPT_COMMAND_OPEN_DOOR (script id %u) failed for non-door(GoType: %u).", script.id, pDoor->GetGoType());
        return ShouldAbortScript(script);
    }

    if (pDoor->GetGoState() != GO_STATE_READY)
        return ShouldAbortScript(script);         //door already  open

    int32 time_to_close = script.openDoor.resetDelay < 3 ? 3 : script.openDoor.resetDelay; // Ustaag <Nostalrius> : duree minimale de reset fixee a 3 sec au lieu de 15

    pDoor->UseDoorOrButton(time_to_close);

    if (target && target->isType(TYPEMASK_GAMEOBJECT) && (static_cast<GameObject*>(target))->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
        (static_cast<GameObject*>(target))->UseDoorOrButton(time_to_close);

    return false;
}

// SCRIPT_COMMAND_CLOSE_DOOR (12)
bool Map::ScriptCommand_CloseDoor(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    GameObject* pDoor = nullptr;
    uint32 guidlow = script.closeDoor.goGuid;

    if (guidlow)
    {
        GameObjectData const* goData = sObjectMgr.GetGOData(guidlow);
        if (!goData)                                // checked at load
            return ShouldAbortScript(script);

        pDoor = GetGameObject(ObjectGuid(HIGHGUID_GAMEOBJECT, goData->id, guidlow));
    }
    else if (target && target->GetTypeId() == TYPEID_GAMEOBJECT)
        pDoor = static_cast<GameObject*>(target);
    else if (source && source->GetTypeId() == TYPEID_GAMEOBJECT)
        pDoor = static_cast<GameObject*>(source);

    if (!pDoor)
    {
        sLog.outError("SCRIPT_COMMAND_CLOSE_DOOR (script id %u) failed for gameobject(guid: %u).", script.id, guidlow);
        return ShouldAbortScript(script);
    }
    if (pDoor->GetGoType() != GAMEOBJECT_TYPE_DOOR)
    {
        sLog.outError("SCRIPT_COMMAND_CLOSE_DOOR (script id %u) failed for non-door(GoType: %u).", script.id, pDoor->GetGoType());
        return ShouldAbortScript(script);
    }

    if (pDoor->GetGoState() == GO_STATE_READY)
        return ShouldAbortScript(script);         //door already closed

    int32 time_to_open = script.closeDoor.resetDelay < 3 ? 3 : script.closeDoor.resetDelay; // Ustaag <Nostalrius> : duree minimale de reset fixee a 3 sec au lieu de 15

    pDoor->UseDoorOrButton(time_to_open);

    if (target && target->isType(TYPEMASK_GAMEOBJECT) && (static_cast<GameObject*>(target))->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
        (static_cast<GameObject*>(target))->UseDoorOrButton(time_to_open);

    return false;
}

// SCRIPT_COMMAND_ACTIVATE_OBJECT (13)
bool Map::ScriptCommand_ActivateGameObject(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pUser = nullptr;
    GameObject* pGo = nullptr;

    if (!((pUser = ToUnit(source)) || (pUser = ToUnit(target))))
    {
        sLog.outError("SCRIPT_COMMAND_ACTIVATE_OBJECT (script id %u) call for a nullptr user, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    if (!((pGo = ToGameObject(target)) || (pGo = ToGameObject(source))))
    {
        sLog.outError("SCRIPT_COMMAND_ACTIVATE_OBJECT (script id %u) call for a nullptr gameobject, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    pGo->Use(pUser);
    return false;
}

// SCRIPT_COMMAND_REMOVE_AURA (14)
bool Map::ScriptCommand_RemoveAura(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_REMOVE_AURA (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->RemoveAurasDueToSpell(script.removeAura.spellId);
    return false;
}

// SCRIPT_COMMAND_CAST_SPELL (15)
bool Map::ScriptCommand_CastSpell(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    SpellCaster* pTarget = ToSpellCaster(target);

    if (!source)
    {
        sLog.outError("SCRIPT_COMMAND_CAST_SPELL (script id %u) call for a nullptr source, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    SpellCaster* pSource = source->ToSpellCaster();
    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_CAST_SPELL (script id %u) call for a non-unit and non-gameobject source, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    if (!pTarget)
        return ShouldAbortScript(script);

    if ((script.castSpell.flags & CF_INTERRUPT_PREVIOUS) && pSource->IsNonMeleeSpellCasted(false))
        pSource->InterruptNonMeleeSpells(false);

    Unit* pUnitTarget = pTarget->ToUnit();
    Creature* pCreatureSource = source->ToCreature();

    if (pCreatureSource && pUnitTarget)
        pCreatureSource->TryToCast(pUnitTarget, script.castSpell.spellId, script.castSpell.flags, 0u);
    else
        pSource->CastSpell(pTarget, script.castSpell.spellId, (script.castSpell.flags & CF_TRIGGERED) != 0);

    return false;
}

// SCRIPT_COMMAND_PLAY_SOUND (16)
bool Map::ScriptCommand_PlaySound(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    WorldObject* pSource = source;

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_PLAY_SOUND (script id %u) call for a nullptr or non-worldobject source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    Player* pTarget = nullptr;

    if ((script.playSound.flags & SF_PLAYSOUND_ONLY_TO_TARGET) && !(pTarget = ToPlayer(target)))
    {
        sLog.outError("SCRIPT_COMMAND_PLAY_SOUND (script id %u) in targeted mode call for a nullptr or non-player target (TypeId: %u), skipping.", script.id, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (script.playSound.flags & SF_PLAYSOUND_DISTANCE_DEPENDENT)
        pSource->PlayDistanceSound(script.playSound.soundId, pTarget);
    else
        pSource->PlayDirectSound(script.playSound.soundId, pTarget);

    return false;
}

// SCRIPT_COMMAND_CREATE_ITEM (17)
bool Map::ScriptCommand_CreateItem(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Player* pReceiver;

    if (!((pReceiver = ToPlayer(target)) || (pReceiver = ToPlayer(source))))
    {
        sLog.outError("SCRIPT_COMMAND_CREATE_ITEM (script id %u) call for a nullptr or non-player object (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (Item* pItem = pReceiver->StoreNewItemInInventorySlot(script.createItem.itemId, script.createItem.amount))
        pReceiver->SendNewItem(pItem, script.createItem.amount, true, false);

    return false;
}

// SCRIPT_COMMAND_DESPAWN_CREATURE (18)
bool Map::ScriptCommand_DespawnCreature(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_DESPAWN_CREATURE (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    // Fix possible crash due to double aura deletion when creature is despawned on death.
    uint32 const despawnDelay = !pSource->IsAlive() && (script.despawn.despawnDelay == 0) ? 1 : script.despawn.despawnDelay;

    pSource->DespawnOrUnsummon(despawnDelay);

    return false;
}

// SCRIPT_COMMAND_SET_EQUIPMENT (19)
bool Map::ScriptCommand_SetEquipment(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_DESPAWN_CREATURE (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (script.setEquipment.resetDefault)
    {
        pSource->LoadEquipment(pSource->GetCreatureInfo()->equipment_id, true);
        return false;
    }

    // main hand
    if (script.setEquipment.slot[0] >= 0)
        pSource->SetVirtualItem(VIRTUAL_ITEM_SLOT_0, script.setEquipment.slot[0]);

    // off hand
    if (script.setEquipment.slot[1] >= 0)
        pSource->SetVirtualItem(VIRTUAL_ITEM_SLOT_1, script.setEquipment.slot[1]);

    // ranged
    if (script.setEquipment.slot[2] >= 0)
        pSource->SetVirtualItem(VIRTUAL_ITEM_SLOT_2, script.setEquipment.slot[2]);

    return false;
}

// SCRIPT_COMMAND_MOVEMENT (20)
bool Map::ScriptCommand_SetMovementType(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource;
    Unit* pTarget;

    if (pSource = ToCreature(source))
        pTarget = ToUnit(target);
    else if (pSource = ToCreature(target))
        pTarget = ToUnit(source);
    else
    {
        sLog.outError("SCRIPT_COMMAND_MOVEMENT (script id %u) call for a nullptr or non-creature source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsAlive())
        return ShouldAbortScript(script);

    switch (script.movement.movementType)
    {
        case IDLE_MOTION_TYPE:
            if (pSource->IsMoving())
                pSource->StopMoving();
            if (script.movement.clear)
                pSource->GetMotionMaster()->Clear(false, true);
            pSource->GetMotionMaster()->MoveIdle();
            break;
        case RANDOM_MOTION_TYPE:
            if (script.movement.clear)
                pSource->GetMotionMaster()->Clear(false, true);
            pSource->GetMotionMaster()->MoveRandom(script.movement.boolParam, script.x);
            break;
        case WAYPOINT_MOTION_TYPE:
            if (script.movement.clear)
                pSource->GetMotionMaster()->Clear(false, true);
            pSource->GetMotionMaster()->MoveWaypoint(script.movement.intParam, 0, 0, 0, 0, script.movement.boolParam);
            break;
        case CONFUSED_MOTION_TYPE:
            pSource->GetMotionMaster()->MoveConfused();
            break;
        case CHASE_MOTION_TYPE:
            if (script.movement.boolParam) // chase victim
            {
                if (Unit* pVictim = pSource->GetVictim())
                    pSource->GetMotionMaster()->MoveChase(pVictim, script.x, script.o);
                break;
            }
            else if (pTarget)
                pSource->GetMotionMaster()->MoveChase(pTarget, script.x, script.o);
            break;
        case HOME_MOTION_TYPE:
            pSource->GetMotionMaster()->MoveTargetedHome();
            break;
        case FLEEING_MOTION_TYPE:
            if (script.movement.boolParam) // flee from victim
            {
                if (Unit* pVictim = pSource->GetVictim())
                    pSource->GetMotionMaster()->MoveFleeing(pVictim, script.movement.intParam);
                break;
            }
            else if (pTarget)
                pSource->GetMotionMaster()->MoveFleeing(pTarget, script.movement.intParam);
            break;
        case DISTRACT_MOTION_TYPE:
            pSource->GetMotionMaster()->MoveDistract(script.movement.intParam);
            break;
        case FOLLOW_MOTION_TYPE:
            if (pTarget)
                pSource->GetMotionMaster()->MoveFollow(pTarget, script.x, script.o);
            break;
        case CHARGE_MOTION_TYPE:
            if (pTarget)
                pSource->GetMotionMaster()->MoveCharge(pTarget, script.movement.intParam, script.movement.boolParam);
            break;
        case DISTANCING_MOTION_TYPE:
            if (pTarget && (!script.movement.intParam || (script.movement.intParam <= pSource->GetPowerPercent(POWER_MANA))))
                pSource->MoveAwayFromTarget(pTarget, script.x);
            break;
        default:
            sLog.outError("SCRIPT_COMMAND_MOVEMENT (script id %u) call for an invalid motion type (MotionType: %u), skipping.", script.id, script.movement.movementType);
            return ShouldAbortScript(script);
    }

    return false;
}

// SCRIPT_COMMAND_SET_ACTIVEOBJECT (21)
bool Map::ScriptCommand_SetActiveObject(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource;

    if (!((pSource = ToCreature(source)) || (pSource = ToCreature(target))))
    {
        sLog.outError("SCRIPT_COMMAND_SET_ACTIVEOBJECT (script id %u) call for a nullptr or non-creature source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->SetActiveObjectState(script.activeObject.activate);

    return false;
}

// SCRIPT_COMMAND_SET_FACTION (22)
bool Map::ScriptCommand_SetFaction(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource;

    if (!((pSource = ToCreature(source)) || (pSource = ToCreature(target))))
    {
        sLog.outError("SCRIPT_COMMAND_SET_FACTION (script id %u) call for a nullptr or non-creature source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (script.faction.factionId)
        pSource->SetFactionTemporary(script.faction.factionId, script.faction.flags);
    else
        pSource->ClearTemporaryFaction();

    return false;
}

// SCRIPT_COMMAND_MORPH_TO_ENTRY_OR_MODEL (23)
bool Map::ScriptCommand_Morph(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource;

    if (!((pSource = ToUnit(source)) || (pSource = ToUnit(target))))
    {
        sLog.outError("SCRIPT_COMMAND_MORPH_TO_ENTRY_OR_MODEL (script id %u) call for a nullptr or non-unit source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsAlive())
        return ShouldAbortScript(script);

    if (!script.morph.creatureOrModelEntry)
        pSource->DeMorph();
    else if (script.morph.isDisplayId)
        pSource->SetDisplayId(script.morph.creatureOrModelEntry);
    else
    {
        CreatureInfo const* ci = ObjectMgr::GetCreatureTemplate(script.morph.creatureOrModelEntry);
        uint32 display_id = Creature::ChooseDisplayId(ci);

        pSource->SetDisplayId(display_id);
    }

    return false;
}

// SCRIPT_COMMAND_MOUNT_TO_ENTRY_OR_MODEL (24)
bool Map::ScriptCommand_Mount(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_MOUNT_TO_ENTRY_OR_MODEL (script id %u) call for a nullptr or non-unit source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    uint32 displayId = script.mount.isDisplayId || !script.mount.creatureOrModelEntry ? script.mount.creatureOrModelEntry : Creature::ChooseDisplayId(ObjectMgr::GetCreatureTemplate(script.mount.creatureOrModelEntry));

    if (pSource->IsAlive())
    {
        bool ok;
        if (displayId)
            ok = pSource->Mount(displayId) == MOUNTRESULT_OK;
        else
            ok = pSource->Unmount() == DISMOUNTRESULT_OK;

        if (!ok && ShouldAbortScript(script))
            return true;
    }

    if (script.mount.permanent)
    {
        Creature* pCreature = ToCreature(source);
        if (!pCreature)
        {
            sLog.outError("SCRIPT_COMMAND_MOUNT_TO_ENTRY_OR_MODEL (script id %u) call for a nullptr or non-creature source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
            return ShouldAbortScript(script);
        }
        pCreature->SetDefaultMount(displayId);
    }

    return false;
}

// SCRIPT_COMMAND_SET_RUN (25)
bool Map::ScriptCommand_SetRun(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource;

    if (!((pSource = ToCreature(source)) || (pSource = ToCreature(target))))
    {
        sLog.outError("SCRIPT_COMMAND_SET_RUN (script id %u) call for a nullptr or non-creature source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->SetWalk(!script.run.run);

    return false;
}

// SCRIPT_COMMAND_ATTACK_START (26)
bool Map::ScriptCommand_AttackStart(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pAttacker = ToCreature(source);
    Unit* pTarget = ToUnit(target);

    if (!pAttacker || !pTarget)
    {
        sLog.outError("SCRIPT_COMMAND_ATTACK_START (script id %u) call for a nullptr source or target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pAttacker->IsAlive())
        return ShouldAbortScript(script);

    if (!pAttacker->IsValidAttackTarget(pTarget) || !pAttacker->IsInMap(pTarget))
    {
        sLog.outError("SCRIPT_COMMAND_ATTACK_START (script id %u) for an invalid attack target, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    if (pAttacker->AI())
        pAttacker->AI()->AttackStart(pTarget);
    else
        return ShouldAbortScript(script);

    return false;
}

// SCRIPT_COMMAND_UPDATE_ENTRY (27)
bool Map::ScriptCommand_UpdateEntry(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_UPDATE_ENTRY (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (pSource->GetEntry() != script.updateEntry.creatureEntry)
        pSource->UpdateEntry(script.updateEntry.creatureEntry);

    return false;
}

// SCRIPT_COMMAND_STAND_STATE (28)
bool Map::ScriptCommand_SetStandState(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_STAND_STATE (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsAlive())
        return ShouldAbortScript(script);

    pSource->SetStandState(script.standState.standState);

    return false;
}

// SCRIPT_COMMAND_MODIFY_THREAT (29)
bool Map::ScriptCommand_ModifyThreat(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_MODIFY_THREAT (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (script.modThreat.target == SO_MODIFYTHREAT_ALL_ATTACKERS)
    {
        ThreatList const& threatList = pSource->GetThreatManager().getThreatList();
        for (const auto i : threatList)
            if (Unit* Temp = pSource->GetMap()->GetUnit(i->getUnitGuid()))
                pSource->GetThreatManager().modifyThreatPercent(Temp, script.x);
    }
    else
    {
        if (Unit* pTarget = ToUnit(GetTargetByType(pSource, target, this, script.modThreat.target)))
            pSource->GetThreatManager().modifyThreatPercent(pTarget, script.x);
    }

    return false;
}

// SCRIPT_COMMAND_SEND_TAXI_PATH (30)
bool Map::ScriptCommand_SendTaxiPath(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Player* pPlayer;

    if (!((pPlayer = ToPlayer(target)) || (pPlayer = ToPlayer(source))))
    {
        sLog.outError("SCRIPT_COMMAND_SEND_TAXI_PATH (script id %u) call for a non-player source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pPlayer->IsAlive())
        return ShouldAbortScript(script);

    pPlayer->ActivateTaxiPathTo(script.sendTaxiPath.taxiPathId, 0, true);

    return false;
}

// SCRIPT_COMMAND_TERMINATE_SCRIPT (31)
bool Map::ScriptCommand_TerminateScript(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    if (script.terminateScript.creatureEntry)
    {
        WorldObject* pSearcher;
        if (!((pSearcher = source) || (pSearcher = target)))
        {
            sLog.outError("SCRIPT_COMMAND_TERMINATE_SCRIPT (script id %u) call for a nullptr object, skipping.", script.id);
            return ShouldAbortScript(script);
        }

        Creature* pCreatureBuddy = nullptr;
        MaNGOS::NearestCreatureEntryWithLiveStateInObjectRangeCheck u_check(*pSearcher, script.terminateScript.creatureEntry, true, script.terminateScript.searchRadius);
        MaNGOS::CreatureLastSearcher<MaNGOS::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(pCreatureBuddy, u_check);
        Cell::VisitGridObjects(pSearcher, searcher, script.terminateScript.searchRadius);

        if ((script.terminateScript.flags == SO_TERMINATESCRIPT_IF_NOT_FOUND) && !pCreatureBuddy)
            return true; // when npc was not found alive
        else if ((script.terminateScript.flags == SO_TERMINATESCRIPT_IF_FOUND) && pCreatureBuddy)
            return true; // when npc was found alive
    }
    else
        return true; // Terminate further steps of this script

    return false;
}

// SCRIPT_COMMAND_TERMINATE_CONDITION (32)
bool Map::ScriptCommand_TerminateCondition(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    WorldObject* pSource = source;
    WorldObject* pTarget = target;

    bool terminateResult = IsConditionSatisfied(script.terminateCond.conditionId, pTarget, this, pSource, CONDITION_FROM_DBSCRIPTS);
    
    if (script.terminateCond.flags & SF_TERMINATECONDITION_WHEN_FALSE)
        terminateResult = !terminateResult;

    if (terminateResult && script.terminateCond.failQuest)
    {
        Player* pPlayer;

        if ((pPlayer = ToPlayer(pSource)) || (pPlayer = ToPlayer(pTarget)))
            pPlayer->GroupEventFailHappens(script.terminateCond.failQuest);
    }

    return terminateResult; // Terminate further steps of this script
}

// SCRIPT_COMMAND_ENTER_EVADE_MODE (33)
bool Map::ScriptCommand_Evade(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource;

    if (!((pSource = ToCreature(source)) || (pSource = ToCreature(target))))
    {
        sLog.outError("SCRIPT_COMMAND_ENTER_EVADE_MODE (script id %u) call for a nullptr or non-creature source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (pSource->AI() && pSource->IsAlive())
        pSource->AI()->EnterEvadeMode();
    else
        return ShouldAbortScript(script);

    return false;
}

// SCRIPT_COMMAND_SET_HOME_POSITION (34)
bool Map::ScriptCommand_SetHomePosition(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource;

    if (!((pSource = ToCreature(source)) || (pSource = ToCreature(target))))
    {
        sLog.outError("SCRIPT_COMMAND_SET_HOME_POSITION (script id %u) call for a nullptr or non-creature source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    switch (script.setHome.mode)
    {
        case SO_SETHOME_PROVIDED_POSITION:
        {
            pSource->SetHomePosition(script.x, script.y, script.z, script.o);
            break;
        }
        case SO_SETHOME_CURRENT_POSITION:
        {
            pSource->SaveHomePosition();
            break;
        }
        case SO_SETHOME_DEFAULT_POSITION:
        {
            pSource->ResetHomePosition();
            break;
        }
    }

    return false;
}

// SCRIPT_COMMAND_TURN_TO (35)
bool Map::ScriptCommand_TurnTo(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_TURN_TO (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsAlive())
        return ShouldAbortScript(script);

    switch (script.turnTo.facingLogic)
    {
        case SO_TURNTO_FACE_TARGET:
        {
            if (WorldObject* pTarget = target)
                pSource->SetFacingToObject(pTarget);
            else
            {
                sLog.outError("SCRIPT_COMMAND_TURN_TO (script id %u) call with datalong=0 for a non-worldobject target (TypeId: %u), skipping", script.id, target ? target->GetTypeId() : 0);
                return ShouldAbortScript(script);
            }
            break;
        }
        case SO_TURNTO_PROVIDED_ORIENTATION:
        {
            pSource->SetFacingTo(script.o);
            break;
        }
    }

    return false;
}

// SCRIPT_COMMAND_MEETINGSTONE (36)
bool Map::ScriptCommand_MeetingStone(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Player* pPlayer;

    if (!((pPlayer = ToPlayer(target)) || (pPlayer = ToPlayer(source))))
    {
        sLog.outError("SCRIPT_COMMAND_MEETINGSTONE (script id %u) call for a nullptr or non-player source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!sLFGMgr.IsPlayerInQueue(pPlayer->GetObjectGuid()))
        sLFGMgr.AddToQueue(pPlayer, script.meetingstone.areaId);

    return false;
}

// SCRIPT_COMMAND_SET_INST_DATA (37)
bool Map::ScriptCommand_SetData(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    InstanceData* pInst = GetInstanceData();
    
    if (!pInst)
    {
        sLog.outError("SCRIPT_COMMAND_SET_INST_DATA (script id %u) call for map without an instance script, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    uint32 uiData = script.setData.data;
    switch (script.setData.type)
    {
        case SO_INSTDATA_INCREMENT:
        {
            uiData+= pInst->GetData(script.setData.field);
            break;
        }
        case SO_INSTDATA_DECREMENT:
        {
            uint32 uiOldData = pInst->GetData(script.setData.field);
            uiData = (uiData < uiOldData) ? (uiOldData - uiData) : 0;
            break;
        }
    }

    pInst->SetData(script.setData.field, uiData);
    return false;
}

// SCRIPT_COMMAND_SET_INST_DATA64 (38)
bool Map::ScriptCommand_SetData64(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    InstanceData* pInst = GetInstanceData();
    
    if (!pInst)
    {
        sLog.outError("SCRIPT_COMMAND_SET_INST_DATA64 (script id %u) call for map without an instance script, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    switch (script.setData64.type)
    {
        case SO_INSTDATA64_RAW:
        {
            pInst->SetData64(script.setData64.field, script.setData64.data);
            break;
        }
        case SO_INSTDATA64_SOURCE_GUID:
        {
            if (source)
                pInst->SetData64(script.setData64.field, source->GetGUID());
            else
            {
                sLog.outError("SCRIPT_COMMAND_SET_INST_DATA64 (script id %u) call for a nullptr source, skipping.", script.id);
                return ShouldAbortScript(script);
            }
            break;
        }
    }

    return false;
}

// SCRIPT_COMMAND_START_SCRIPT (39)
bool Map::ScriptCommand_StartScript(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    uint32 const roll = urand(1, 100);
    uint32 sum = 0;
    uint32 chosenId = 0;

    for (int i = 0; i < 4; i++)
    {
        uint32 const currentId = script.startScript.scriptId[i];

        if (!currentId)
            continue;

        uint32 const currentChance = script.startScript.chance[i];

        if ((roll > sum) && (roll <= (sum + currentChance)))
        {
            chosenId = currentId;
            break;
        }

        sum += currentChance;
    }

    if (chosenId)
        ScriptsStart(sGenericScripts, chosenId, source ? source->GetObjectGuid() : ObjectGuid(), target ? target->GetObjectGuid() : ObjectGuid());
    else
        return ShouldAbortScript(script);

    return false;
}

// SCRIPT_COMMAND_REMOVE_ITEM (40)
bool Map::ScriptCommand_RemoveItem(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Player* pPlayer;

    if (!((pPlayer = ToPlayer(target)) || (pPlayer = ToPlayer(source))))
    {
        sLog.outError("SCRIPT_COMMAND_REMOVE_ITEM (script id %u) call for a nullptr or non-player source and target (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pPlayer->DestroyItemCount(script.createItem.itemId, script.createItem.amount, true);

    return false;
}

// SCRIPT_COMMAND_REMOVE_OBJECT (41)
bool Map::ScriptCommand_RemoveGameObject(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    GameObject* pGo = nullptr;

    if (!((pGo = ToGameObject(target)) || (pGo = ToGameObject(source))))
    {
        sLog.outError("SCRIPT_COMMAND_REMOVE_OBJECT (script id %u) call for a nullptr gameobject, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    pGo->SetLootState(GO_JUST_DEACTIVATED);
    pGo->AddObjectToRemoveList();
    return false;
}

// SCRIPT_COMMAND_SET_MELEE_ATTACK (42)
bool Map::ScriptCommand_SetMeleeAttack(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SET_MELEE_ATTACK (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (pSource->AI())
        pSource->AI()->SetMeleeAttack(script.enableMelee.enabled);
    else
        return ShouldAbortScript(script);

    return false;
}

// SCRIPT_COMMAND_SET_COMBAT_MOVEMENT (43)
bool Map::ScriptCommand_SetCombatMovement(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SET_COMBAT_MOVEMENT (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (pSource->AI())
        pSource->AI()->SetCombatMovement(script.combatMovement.enabled);
    else
        return ShouldAbortScript(script);

    return false;
}

// SCRIPT_COMMAND_SET_PHASE (44)
bool Map::ScriptCommand_SetPhase(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SET_PHASE (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    auto* pAI = dynamic_cast<CreatureEventAI*>(pSource->AI());

    if (!pAI)
        return ShouldAbortScript(script);

    uint32 uiPhase = script.setPhase.phase;

    switch (script.setPhase.mode)
    {
        case SO_SETPHASE_INCREMENT:
        {
            uiPhase+= pAI->m_Phase;
            break;
        }
        case SO_SETPHASE_DECREMENT:
        {
            uint32 uiOldPhase = pAI->m_Phase;
            uiPhase = (uiPhase < uiOldPhase) ? (uiOldPhase - uiPhase) : 0;
            break;
        }
    }

    if (uiPhase >= MAX_PHASE)
    {
        sLog.outErrorDb("SCRIPT_COMMAND_SET_PHASE (script id %u) attempt to increment Phase above %u. Phase mask cannot be used with phases past %u. CreatureEntry = %d", script.id, MAX_PHASE - 1, MAX_PHASE - 1, pSource->GetEntry());
        return ShouldAbortScript(script);
    }

    pAI->m_Phase = uiPhase;

    return false;
}

// SCRIPT_COMMAND_SET_PHASE_RANDOM (45)
bool Map::ScriptCommand_SetPhaseRandom(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SET_PHASE_RANDOM (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    auto* pAI = dynamic_cast<CreatureEventAI*>(pSource->AI());

    if (!pAI)
        return ShouldAbortScript(script);

    uint32 phase1 = script.setPhaseRandom.phase[0];
    uint32 phase2 = script.setPhaseRandom.phase[1];
    uint32 phase3 = script.setPhaseRandom.phase[2];
    uint32 phase4 = script.setPhaseRandom.phase[3];

    if (phase4)
        pAI->m_Phase = RAND(phase1, phase2, phase3, phase4);
    else if (phase3)
        pAI->m_Phase = RAND(phase1, phase2, phase3);
    else
        pAI->m_Phase = RAND(phase1, phase2);

    return false;
}

// SCRIPT_COMMAND_SET_PHASE_RANGE (46)
bool Map::ScriptCommand_SetPhaseRange(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SET_PHASE_RANGE (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    auto* pAI = dynamic_cast<CreatureEventAI*>(pSource->AI());

    if (!pAI)
        return ShouldAbortScript(script);

    pAI->m_Phase = urand(script.setPhaseRange.phaseMin, script.setPhaseRange.phaseMax);

    return false;
}

// SCRIPT_COMMAND_FLEE (47)
bool Map::ScriptCommand_Flee(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_FLEE (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsAlive())
        return ShouldAbortScript(script);

    if (script.flee.seekAssistance)
        pSource->DoFleeToGetAssistance();
    else
        pSource->DoFlee();

    return false;
}

// SCRIPT_COMMAND_DEAL_DAMAGE (48)
bool Map::ScriptCommand_DealDamage(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_DEAL_DAMAGE (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    Unit* pTarget = ToUnit(source);

    if (!pTarget)
    {
        sLog.outError("SCRIPT_COMMAND_DEAL_DAMAGE (script id %u) call for a nullptr or non-unit target (TypeId: %u), skipping.", script.id, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pTarget->IsAlive())
        return ShouldAbortScript(script);

    uint32 damage = script.dealDamage.isPercent ? pTarget->GetMaxHealth()*(script.dealDamage.damage / 100.0f) : script.dealDamage.damage;
    pSource->DealDamage(pTarget, damage, nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);

    return false;
}

// SCRIPT_COMMAND_ZONE_COMBAT_PULSE (49)
bool Map::ScriptCommand_ZoneCombatPulse(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_ZONE_COMBAT_PULSE (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsAlive())
        return ShouldAbortScript(script);

    pSource->SetInCombatWithZone(script.combatPulse.initialPulse);

    return false;
}

// SCRIPT_COMMAND_CALL_FOR_HELP (50)
bool Map::ScriptCommand_CallForHelp(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_CALL_FOR_HELP (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsAlive())
        return ShouldAbortScript(script);

    pSource->CallForHelp(script.x);

    return false;
}

// SCRIPT_COMMAND_SET_SHEATH (51)
bool Map::ScriptCommand_SetSheath(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SET_SHEATH (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->SetSheath(SheathState(script.setSheath.sheathState));

    return false;
}

// SCRIPT_COMMAND_INVINCIBILITY (52)
bool Map::ScriptCommand_Invincibility(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_INVINCIBILITY (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    auto* pAI = dynamic_cast<CreatureEventAI*>(pSource->AI());

    if (!pAI)
        return ShouldAbortScript(script);

    pAI->SetInvincibilityHealthLevel(script.invincibility.health, script.invincibility.isPercent);

    return false;
}

// SCRIPT_COMMAND_GAME_EVENT (53)
bool Map::ScriptCommand_GameEvent(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    if (script.gameEvent.start)
        sGameEventMgr.StartEvent(script.gameEvent.eventId, script.gameEvent.overwrite);
    else
        sGameEventMgr.StopEvent(script.gameEvent.eventId, script.gameEvent.overwrite);

    return false;
}

// SCRIPT_COMMAND_SET_SERVER_VARIABLE (54)
bool Map::ScriptCommand_ServerVariable(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    sObjectMgr.SetSavedVariable(script.serverVariable.index, script.serverVariable.value, true);

    return false;
}

// SCRIPT_COMMAND_CREATURE_SPELLS (55)
bool Map::ScriptCommand_CreatureSpells(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_CREATURE_SPELLS (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    uint32 const roll = urand(1, 100);
    uint32 sum = 0;
    uint32 chosenId = 0;

    for (int i = 0; i < 4; i++)
    {
        uint32 const currentId = script.creatureSpells.spellListId[i];
        uint32 const currentChance = script.creatureSpells.chance[i];

        if (!currentChance)
            continue;

        if ((roll > sum) && (roll <= (sum + currentChance)))
        {
            chosenId = currentId;
            break;
        }

        sum += currentChance;
    }

    if (pSource->AI())
        pSource->AI()->SetSpellsList(chosenId);
    else
        return ShouldAbortScript(script);

    return false;
}

// SCRIPT_COMMAND_REMOVE_GUARDIANS (56)
bool Map::ScriptCommand_RemoveGuardians(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_REMOVE_GUARDIANS (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }
    
    if (script.removeGuardian.creatureId)
    {
        pSource->RemoveGuardiansWithEntry(script.removeGuardian.creatureId);
    }
    else
        pSource->RemoveGuardians();

    return false;
}

// SCRIPT_COMMAND_ADD_SPELL_COOLDOWN (57)
bool Map::ScriptCommand_AddSpellCooldown(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_ADD_SPELL_COOLDOWN (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (SpellEntry const* pSpellEntry = sSpellMgr.GetSpellEntry(script.addCooldown.spellId))
    pSource->AddCooldown(*pSpellEntry, nullptr, false, script.addCooldown.cooldown * IN_MILLISECONDS);
    if (Player* pPlayer = pSource->ToPlayer())
        pPlayer->SendSpellCooldown(script.addCooldown.spellId, script.addCooldown.cooldown * IN_MILLISECONDS, pPlayer->GetObjectGuid());

    return false;
}

// SCRIPT_COMMAND_REMOVE_SPELL_COOLDOWN (58)
bool Map::ScriptCommand_RemoveSpellCooldown(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_REMOVE_SPELL_COOLDOWN (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (script.removeCooldown.spellId)
        pSource->RemoveSpellCooldown(script.removeCooldown.spellId, true);
    else
        pSource->RemoveAllCooldowns();

    return false;
}

// SCRIPT_COMMAND_SET_REACT_STATE (59)
bool Map::ScriptCommand_SetReactState(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SET_REACT_STATE (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->SetReactState(ReactStates(script.setReactState.state));

    return false;
}

// SCRIPT_COMMAND_START_WAYPOINTS (60)
bool Map::ScriptCommand_StartWaypoints(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_START_WAYPOINTS (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsAlive())
        return ShouldAbortScript(script);

    pSource->GetMotionMaster()->Clear(false, true);
    pSource->GetMotionMaster()->MoveWaypoint(script.startWaypoints.startPoint, script.startWaypoints.wpSource, script.startWaypoints.initialDelay, script.startWaypoints.overwriteGuid, script.startWaypoints.overwriteEntry, script.startWaypoints.canRepeat);

    return false;
}

// SCRIPT_COMMAND_START_MAP_EVENT (61)
bool Map::ScriptCommand_StartMapEvent(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    if (!StartScriptedEvent(script.startMapEvent.eventId, source, target, script.startMapEvent.timeLimit, script.startMapEvent.failureCondition, script.startMapEvent.failureScript, script.startMapEvent.successCondition, script.startMapEvent.successScript))
        return ShouldAbortScript(script);

    return false;
}

// SCRIPT_COMMAND_END_MAP_EVENT (62)
bool Map::ScriptCommand_EndMapEvent(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    auto itr = m_mScriptedEvents.find(script.endMapEvent.eventId);

    if (itr == m_mScriptedEvents.end())
        return ShouldAbortScript(script);

    itr->second.EndEvent(script.endMapEvent.success);

    return false;
}

// SCRIPT_COMMAND_ADD_MAP_EVENT_TARGET (63)
bool Map::ScriptCommand_AddMapEventTarget(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    if (!source)
    {
        sLog.outError("SCRIPT_COMMAND_ADD_MAP_EVENT_TARGET (script id %u) call for a nullptr source, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    ScriptedEvent* pEvent = GetScriptedMapEvent(script.addMapEventTarget.eventId);

    if (!pEvent)
    {
        sLog.outError("SCRIPT_COMMAND_ADD_MAP_EVENT_TARGET (script id %u) call for a non-existing scripted map event (EventId: %u), skipping.", script.id, script.addMapEventTarget.eventId);
        return ShouldAbortScript(script);
    }

    pEvent->AddOrUpdateExtraTarget(source, script.addMapEventTarget.failureCondition, script.addMapEventTarget.failureScript, script.addMapEventTarget.successCondition, script.addMapEventTarget.successScript);

    return false;
}

// SCRIPT_COMMAND_REMOVE_MAP_EVENT_TARGET (64)
bool Map::ScriptCommand_RemoveMapEventTarget(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    ScriptedEvent* pEvent = GetScriptedMapEvent(script.removeMapEventTarget.eventId);

    if (!pEvent)
    {
        sLog.outError("SCRIPT_COMMAND_REMOVE_MAP_EVENT_TARGET (script id %u) call for a non-existing scripted map event (EventId: %u), skipping.", script.id, script.removeMapEventTarget.eventId);
        return ShouldAbortScript(script);
    }

    switch (script.removeMapEventTarget.targets)
    {
        case SO_REMOVETARGET_SELF:
        {
            if (!source)
                return ShouldAbortScript(script);

            for (auto itr = pEvent->m_vTargets.begin(); itr != pEvent->m_vTargets.end(); ++itr)
            {
                if (itr->target == source->GetObjectGuid())
                {
                    pEvent->m_vTargets.erase(itr);
                    return false;
                }
            }
            break;
        }
        case SO_REMOVETARGET_ONE_FIT_CONDITION:
        case SO_REMOVETARGET_ALL_FIT_CONDITION:
        {
            if (!script.removeMapEventTarget.conditionId)
            {
                sLog.outError("SCRIPT_COMMAND_REMOVE_MAP_EVENT_TARGET (script id %u) call with `datalong3`=%u but without a condition Id, skipping.", script.id, script.removeMapEventTarget.targets);
                return ShouldAbortScript(script);
            }

            for (auto itr = pEvent->m_vTargets.begin(); itr != pEvent->m_vTargets.end();)
            {
                if (WorldObject* pObject = GetWorldObject(itr->target))
                {
                    if (IsConditionSatisfied(script.removeMapEventTarget.conditionId, source, this, pObject, CONDITION_FROM_DBSCRIPTS))
                    {
                        itr = pEvent->m_vTargets.erase(itr);
                        if (script.removeMapEventTarget.targets == SO_REMOVETARGET_ONE_FIT_CONDITION)
                            return false;
                        continue;
                    }
                }
                
                ++itr;
            }
            break;
        }
        case SO_REMOVETARGET_ALL_TARGETS:
        {
            pEvent->m_vTargets.clear();
            break;
        }
    }

    return false;
}

// SCRIPT_COMMAND_SET_MAP_EVENT_DATA (65)
bool Map::ScriptCommand_SetMapEventData(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    ScriptedEvent* pEvent = GetScriptedMapEvent(script.setMapEventData.eventId);

    if (!pEvent)
    {
        sLog.outError("SCRIPT_COMMAND_SET_MAP_EVENT_DATA (script id %u) call for a non-existing scripted map event (EventId: %u), skipping.", script.id, script.setMapEventData.eventId);
        return ShouldAbortScript(script);
    }

    switch (script.setMapEventData.type)
    {
        case SO_MAPEVENTDATA_RAW:
        {
            pEvent->SetData(script.setMapEventData.index, script.setMapEventData.data);
            break;
        }
        case SO_MAPEVENTDATA_INCREMENT:
        {
            pEvent->IncrementData(script.setMapEventData.index, script.setMapEventData.data);
            break;
        }
        case SO_MAPEVENTDATA_DECREMENT:
        {
            pEvent->DecrementData(script.setMapEventData.index, script.setMapEventData.data);
            break;
        }
    }

    return false;
}

// SCRIPT_COMMAND_SEND_MAP_EVENT (66)
bool Map::ScriptCommand_SendMapEvent(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    ScriptedEvent* pEvent = GetScriptedMapEvent(script.sendMapEvent.eventId);

    if (!pEvent)
    {
        sLog.outError("SCRIPT_COMMAND_SEND_MAP_EVENT (script id %u) call for a non-existing scripted map event (EventId: %u), skipping.", script.id, script.sendMapEvent.eventId);
        return ShouldAbortScript(script);
    }

    switch (script.sendMapEvent.targets)
    {
        case SO_SENDMAPEVENT_MAIN_TARGETS_ONLY:
        {
            pEvent->SendEventToMainTargets(script.sendMapEvent.data);
            break;
        }
        case SO_SENDMAPEVENT_EXTRA_TARGETS_ONLY:
        {
            pEvent->SendEventToAdditionalTargets(script.sendMapEvent.data);
            break;
        }
        case SO_SENDMAPEVENT_ALL_TARGETS:
        {
            pEvent->SendEventToAllTargets(script.sendMapEvent.data);
            break;
        }
    }

    return false;
}

// SCRIPT_COMMAND_SET_DEFAULT_MOVEMENT (67)
bool Map::ScriptCommand_SetDefaultMovement(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SET_DEFAULT_MOVEMENT (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->SetDefaultMovementType(MovementGeneratorType(script.setDefaultMovement.movementType));

    if (script.setDefaultMovement.movementType == RANDOM_MOTION_TYPE)
        pSource->SetWanderDistance(script.setDefaultMovement.param1);

    if (pSource->IsAlive())
        pSource->GetMotionMaster()->InitializeNewDefault(script.setDefaultMovement.alwaysReplace);

    return false;
}

// SCRIPT_COMMAND_START_SCRIPT_FOR_ALL (68)
bool Map::ScriptCommand_StartScriptForAll(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    if (!source)
    {
        sLog.outError("SCRIPT_COMMAND_START_SCRIPT_FOR_ALL (script id %u) call for a nullptr source, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    std::list<WorldObject*> targets;

    MaNGOS::AllWorldObjectsInRange u_check(source, script.startScriptForAll.searchRadius);
    MaNGOS::WorldObjectListSearcher<MaNGOS::AllWorldObjectsInRange> searcher(targets, u_check);

    Cell::VisitAllObjects(source, searcher, script.startScriptForAll.searchRadius);

    for (const auto pWorldObject : targets)
    {
        if (!pWorldObject)
            continue;

        switch (script.startScriptForAll.objectType)
        {
            case SO_STARTFORALL_GAMEOBJECTS:
            {
                if (!pWorldObject->IsGameObject())
                    continue;
                break;
            }
            case SO_STARTFORALL_UNITS:
            {
                if (!pWorldObject->IsUnit())
                    continue;
                break;
            }
            case SO_STARTFORALL_CREATURES:
            {
                if (!pWorldObject->IsCreature())
                    continue;
                break;
            }
            case SO_STARTFORALL_PLAYERS:
            {
                if (!pWorldObject->IsPlayer())
                    continue;
                break;
            }
        }

        if (!script.startScriptForAll.objectEntry || (pWorldObject->GetEntry() == script.startScriptForAll.objectEntry))
            ScriptsStart(sGenericScripts, script.startScriptForAll.scriptId, pWorldObject->GetObjectGuid(), target ? target->GetObjectGuid() : ObjectGuid());
    }
    
    return false;
}

// SCRIPT_COMMAND_EDIT_MAP_EVENT (69)
bool Map::ScriptCommand_EditMapEvent(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    ScriptedEvent* pEvent = GetScriptedMapEvent(script.editMapEvent.eventId);

    if (!pEvent)
    {
        sLog.outError("SCRIPT_COMMAND_EDIT_MAP_EVENT (script id %u) call for a non-existing scripted map event (EventId: %u), skipping.", script.id, script.editMapEvent.eventId);
        return ShouldAbortScript(script);
    }

    if (script.editMapEvent.successCondition >= 0)
        pEvent->m_uiSuccessCondition = script.editMapEvent.successCondition;

    if (script.editMapEvent.successScript >= 0)
        pEvent->m_uiSuccessScript = script.editMapEvent.successScript;

    if (script.editMapEvent.failureCondition >= 0)
        pEvent->m_uiFailureCondition = script.editMapEvent.failureCondition;

    if (script.editMapEvent.failureScript >= 0)
        pEvent->m_uiFailureScript = script.editMapEvent.failureScript;

    return false;
}

// SCRIPT_COMMAND_FAIL_QUEST (70)
bool Map::ScriptCommand_FailQuest(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Player* pSource;

    // accept player in any one from target/source arg
    if ((pSource = ToPlayer(target)) || (pSource = ToPlayer(source)))
        pSource->GroupEventFailHappens(script.failQuest.questId);
    else
    {
        sLog.outError("SCRIPT_COMMAND_FAIL_QUEST (script id %u) call for a nullptr object, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    return false;
}

// SCRIPT_COMMAND_RESPAWN_CREATURE (71)
bool Map::ScriptCommand_RespawnCreature(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_RESPAWN_CREATURE (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (pSource->IsAlive())
    {
        if (script.respawnCreature.evenAlive)
            pSource->SetDeathState(JUST_DIED);
        else
            return ShouldAbortScript(script);
    }

    pSource->Respawn();

    return false;
}

// SCRIPT_COMMAND_ASSIST_UNIT (72)
bool Map::ScriptCommand_AssistUnit(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_ASSIST_UNIT (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    Unit* pTarget = ToUnit(target);

    if (!pTarget)
    {
        sLog.outError("SCRIPT_COMMAND_ASSIST_UNIT (script id %u) call for a nullptr or non-unit target (TypeId: %u), skipping.", script.id, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsInMap(pTarget))
        return ShouldAbortScript(script);

    Unit* pAttacker = pTarget->GetAttackerForHelper();

    if (!pAttacker)
        return false;

    if (Unit* pVictim = pSource->GetVictim())
    {
        if (pVictim == pAttacker)
            return false;

        if (pSource->IsValidAttackTarget(pAttacker) && pSource->IsWithinDistInMap(pAttacker, 40.0f))
            pSource->AddThreat(pAttacker);
    }
    else
    {
        if (pSource->AI() && pSource->IsValidAttackTarget(pAttacker) && pSource->IsWithinDistInMap(pAttacker, 40.0f))
            pSource->AI()->AttackStart(pAttacker);
    }

    return false;
}

// SCRIPT_COMMAND_COMBAT_STOP (73)
bool Map::ScriptCommand_CombatStop(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_COMBAT_STOP (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (pSource->IsInCombat())
    {
        pSource->CombatStop(true);
        pSource->DeleteThreatList();
    }  

    return false;
}

// SCRIPT_COMMAND_ADD_AURA (74)
bool Map::ScriptCommand_AddAura(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_ADD_AURA (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->AddAura(script.addAura.spellId, script.addAura.flags);

    return false;
}

// SCRIPT_COMMAND_ADD_THREAT (75)
bool Map::ScriptCommand_AddThreat(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_ADD_THREAT (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (!pSource->IsInCombat() || !pSource->IsAlive())
        return false;

    Unit* pTarget = ToUnit(target);

    if (!pTarget)
    {
        sLog.outError("SCRIPT_COMMAND_ADD_THREAT (script id %u) call for a nullptr or non-unit target (TypeId: %u), skipping.", script.id, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (pSource->IsValidAttackTarget(pTarget) && pSource->IsInMap(pTarget))
        pSource->AddThreat(pTarget);

    return false;
}

// SCRIPT_COMMAND_SUMMON_OBJECT (76)
bool Map::ScriptCommand_SummonObject(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    if (!source)
    {
        sLog.outError("SCRIPT_COMMAND_SUMMON_OBJECT (script id %u) call for a nullptr source, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    float x = script.x ? script.x : source->GetPositionX();
    float y = script.y ? script.y : source->GetPositionY();
    float z = script.z ? script.z : source->GetPositionZ();
    float o = script.o ? script.o : source->GetOrientation();

    source->SummonGameObject(script.summonObject.gameobject_entry, x, y, z, o, 0, 0, 0, 0, script.summonObject.respawn_time);

    return false;
}

// SCRIPT_COMMAND_SET_FLY (77)
bool Map::ScriptCommand_SetFly(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Unit* pSource = ToUnit(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SET_FLY (script id %u) call for a nullptr or non-unit source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->SetFly(script.setFly.enabled);

    return false;
}

// SCRIPT_COMMAND_JOIN_CREATURE_GROUP (78)
bool Map::ScriptCommand_JoinCreatureGroup(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_JOIN_CREATURE_GROUP (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    Creature* pTarget = ToCreature(target);

    if (!pTarget)
    {
        sLog.outError("SCRIPT_COMMAND_JOIN_CREATURE_GROUP (script id %u) call for a nullptr or non-creature target (TypeId: %u), skipping.", script.id, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->JoinCreatureGroup(pTarget, script.x, script.o, script.joinCreatureGroup.options);

    return false;
}

// SCRIPT_COMMAND_LEAVE_CREATURE_GROUP (79)
bool Map::ScriptCommand_LeaveCreatureGroup(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_LEAVE_CREATURE_GROUP (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->LeaveCreatureGroup();

    return false;
}

// SCRIPT_COMMAND_SET_GO_STATE (80)
bool Map::ScriptCommand_SetGoState(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    GameObject* pGo = nullptr;

    if (!((pGo = ToGameObject(target)) || (pGo = ToGameObject(source))))
    {
        sLog.outError("SCRIPT_COMMAND_SET_GO_STATE (script id %u) call for a nullptr gameobject, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    pGo->SetGoState(GOState(script.setGoState.state));
    return false;
}

// SCRIPT_COMMAND_DESPAWN_GAMEOBJECT (81)
bool Map::ScriptCommand_DespawnGameObject(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    GameObject* pGo = nullptr;
    uint32 guidlow = script.despawnGo.goGuid;

    if (guidlow)
    {
        GameObjectData const* goData = sObjectMgr.GetGOData(guidlow);
        if (!goData)
            return ShouldAbortScript(script); // checked at load

        pGo = GetGameObject(ObjectGuid(HIGHGUID_GAMEOBJECT, goData->id, guidlow));
    }
    else if (target && target->GetTypeId() == TYPEID_GAMEOBJECT)
        pGo = static_cast<GameObject*>(target);
    else if (source && source->GetTypeId() == TYPEID_GAMEOBJECT)
        pGo = static_cast<GameObject*>(source);

    if (!pGo)
    {
        sLog.outError("SCRIPT_COMMAND_DESPAWN_GAMEOBJECT (script id %u) failed for gameobject(guid: %u).", script.id, guidlow);
        return ShouldAbortScript(script);
    }

    if (!pGo->isSpawned())
        return ShouldAbortScript(script);          // gameobject already despawned

    pGo->SetLootState(GO_JUST_DEACTIVATED);
    if (script.despawnGo.respawnDelay)
        pGo->SetRespawnDelay(script.despawnGo.respawnDelay);        // respawn object in ? seconds

    return false;
}

// SCRIPT_COMMAND_LOAD_GAMEOBJECT (82)
bool Map::ScriptCommand_LoadGameObject(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    GameObjectData const* pGameObjectData = sObjectMgr.GetGOData(script.loadGo.goGuid);

    if (GetId() != pGameObjectData->position.mapId)
    {
        sLog.outError("SCRIPT_COMMAND_LOAD_GAMEOBJECT (script id %u) tried to spawn guid %u on wrong map %u.", script.id, script.loadGo.goGuid, GetId());
        return ShouldAbortScript(script);
    }

    if (GetGameObject(ObjectGuid(HIGHGUID_GAMEOBJECT, pGameObjectData->id, script.loadGo.goGuid)))
        return ShouldAbortScript(script); // already spawned

    GameObject* pGameobject = GameObject::CreateGameObject(pGameObjectData->id);
    if (!pGameobject->LoadFromDB(script.loadGo.goGuid, this))
        delete pGameobject;
    else
        Add(pGameobject);

    return false;
}

// SCRIPT_COMMAND_QUEST_CREDIT (83)
bool Map::ScriptCommand_QuestCredit(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Player* pPlayer;

    if (!((pPlayer = ToPlayer(target)) || (pPlayer = ToPlayer(source))))
    {
        sLog.outError("SCRIPT_COMMAND_QUEST_CREDIT (script id %u) call for a nullptr player, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    WorldObject* pWorldObject = source && !source->IsPlayer() ? source : (target && !target->IsPlayer() ? target : nullptr);
    if (!pWorldObject)
    {
        sLog.outError("SCRIPT_COMMAND_QUEST_CREDIT (script id %u) call for a nullptr target, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    pPlayer->TalkedToCreature(pWorldObject->GetEntry(), pWorldObject->GetObjectGuid());

    return false;
}

// SCRIPT_COMMAND_SET_GOSSIP_MENU (84)
bool Map::ScriptCommand_SetGossipMenu(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SET_GOSSIP_MENU (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->SetDefaultGossipMenuId(script.setGossipMenu.gossipMenuId);

    return false;
}

// SCRIPT_COMMAND_SEND_SCRIPT_EVENT (85)
bool Map::ScriptCommand_SendScriptEvent(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Creature* pSource = ToCreature(source);

    if (!pSource)
    {
        sLog.outError("SCRIPT_COMMAND_SEND_SCRIPT_EVENT (script id %u) call for a nullptr or non-creature source (TypeId: %u), skipping.", script.id, source ? source->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    if (pSource->AI())
        pSource->AI()->OnScriptEventHappened(script.sendScriptEvent.eventId, script.sendScriptEvent.eventData, target);
    else
        return ShouldAbortScript(script);

    return false;
}

// SCRIPT_COMMAND_SET_PVP (86)
bool Map::ScriptCommand_SetPvP(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    Player* pSource;

    if (!((pSource = ToPlayer(target)) || (pSource = ToPlayer(source))))
    {
        sLog.outError("SCRIPT_COMMAND_SET_PVP (script id %u) call for a nullptr or non-player object (TypeIdSource: %u)(TypeIdTarget: %u), skipping.", script.id, source ? source->GetTypeId() : 0, target ? target->GetTypeId() : 0);
        return ShouldAbortScript(script);
    }

    pSource->UpdatePvP(script.setPvP.enabled);
    if (script.setPvP.enabled)
        pSource->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);

    return false;
}

// SCRIPT_COMMAND_RESET_DOOR_OR_BUTTON (87)
bool Map::ScriptCommand_ResetDoorOrButton(ScriptInfo const& script, WorldObject* source, WorldObject* target)
{
    GameObject* pGo = nullptr;

    if (!((pGo = ToGameObject(target)) || (pGo = ToGameObject(source))))
    {
        sLog.outError("SCRIPT_COMMAND_RESET_DOOR_OR_BUTTON (script id %u) call for a nullptr gameobject, skipping.", script.id);
        return ShouldAbortScript(script);
    }

    pGo->ResetDoorOrButton();
    return false;
}
