/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "TSLoot.h"
#include "TSBase.h"
#include "TSMain.h"
#include "TSArray.h"
#include "TSString.h"
#include "TSUnit.h"
#include "TSClasses.h"
#include "TSPosition.h"

class TC_GAME_API TSCreature : public TSUnit {
public:
    Creature *creature;

    TSCreature(Creature* creature);
    TSCreature();
    TSCreature* operator->() { return this;}
    bool IsNull() { return creature == nullptr; }
    bool IsReputationGainDisabled();
    bool CanCompleteQuest(uint32 quest_id);
    bool IsTargetableForAttack(bool mustBeDead);
    bool CanAssistTo(TSUnit u, TSUnit enemy, bool checkfaction);
    bool HasSearchedAssistance();
    bool IsTappedBy(TSPlayer player);
    bool HasLootRecipient();
    bool CanAggro();
    bool CanSwim();
    bool CanWalk();
    bool IsInEvadeMode();
    bool IsElite();
    bool IsGuard();
    bool IsCivilian();
    bool IsRacialLeader();
    bool IsWorldBoss();
    bool HasCategoryCooldown(uint32 spell);
    bool HasSpell(uint32 id);
    bool HasQuest(uint32 questId);
    bool HasSpellCooldown(uint32 spellId);
    bool CanFly();
    bool IsTrigger();
    bool IsDamageEnoughForLootingAndReward();
    bool CanStartAttack(TSUnit target, bool force);
    bool HasLootMode(uint16 lootMode);
    float GetAttackDistance(TSUnit _target);
    uint32 GetRespawnDelay();
    float GetWanderRadius();
    uint32 GetWaypointPath();
    uint32 GetCurrentWaypointId();
    uint32 GetDefaultMovementType();
    float GetAggroRange(TSUnit target);
    TSGroup GetLootRecipientGroup();
    TSPlayer GetLootRecipient();
    TSString GetScriptName();
    TSString GetAIName();
    uint32 GetScriptId();
    uint32 GetCreatureSpellCooldownDelay(uint32 spell);
    uint32 GetCorpseDelay();
    TSPosition GetHomePosition();
    void SetHomePosition(float x, float y, float z, float o);
    TSUnit GetAITarget(uint32 targetType, bool playerOnly, uint32 position, float dist, int32 aura);
    TSArray<TSUnit> GetAITargets();
    int GetAITargetsCount();
    uint32 GetNPCFlags();
    uint32 GetShieldBlockValue();
    uint16 GetLootMode();
    uint32 GetDBTableGUIDLow();
    void SetNPCFlags(uint32 flags);
    void SetDisableGravity(bool disable);
    void SetLootMode(uint16 lootMode);
    void SetDeathState(int32 state);
    void SetWalk(bool enable);
    void SetEquipmentSlots(uint32 main_hand, uint32 off_hand, uint32 ranged);
    void SetAggroEnabled(bool allow);
    void SetDisableReputationGain(bool disable);
    void SetInCombatWithZone();
    void SetWanderRadius(float dist);
    void SetRespawnDelay(uint32 delay);
    void SetDefaultMovementType(int32 type);
    void SetNoSearchAssistance(bool val);
    void SetNoCallAssistance(bool val);
    void SetHover(bool enable);
    void DespawnOrUnsummon(uint32 msTimeToDespawn);
    void Respawn();
    void RemoveCorpse();
    void MoveWaypoint();
    void CallAssistance();
    void CallForHelp(float radius);
    void FleeToGetAssistance();
    void AttackStart(TSUnit target);
    void SaveToDB();
    TSUnit SelectVictim();
    void UpdateEntry(uint32 entry, uint32 dataGuidLow);
    void ResetLootMode();
    void RemoveLootMode(uint16 lootMode);
    void AddLootMode(uint16 lootMode);
    uint32 GetCreatureFamily();
    TSLoot GetLoot();
};
