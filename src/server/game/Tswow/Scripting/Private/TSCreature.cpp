/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
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
#include <memory.h>
#include "Object.h"
#include "Creature.h"

#include "TSIncludes.h"
#include "TSCreature.h"
#include "TSPlayer.h"
#include "TSGroup.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "SpellHistory.h"
#include "ThreatManager.h"
#include "ObjectGuid.h"
#include "CreatureAI.h"
#include "MotionMaster.h"
#include "Player.h"
#include "TSMap.h"

TSCreature::TSCreature(Creature *creature) : TSUnit(creature)
{
    this->creature = creature;
}

TSCreature::TSCreature() : TSUnit()
{
    this->creature = nullptr;
}

/**
 * Returns `true` if the [Creature] is set to not give reputation when killed,
 *   and returns `false` otherwise.
 *
 * @return bool reputationDisabled
 */
bool TSCreature::IsReputationGainDisabled() 
{
    return creature->IsReputationGainDisabled();
}
    
/**
 * Returns `true` if the [Creature] completes the [Quest] with the ID `questID`,
 *   and returns `false` otherwise.
 *
 * @param uint32 questID : the ID of a [Quest]
 * @return bool completesQuest
 */
bool TSCreature::CanCompleteQuest(uint32 quest_id) 
{
    
#if defined TRINITY || AZEROTHCORE
    return creature->hasInvolvedQuest(quest_id);
#else
    return creature->HasInvolvedQuest(quest_id);
#endif
}
    
/**
 * Returns `true` if the [Creature] can be targeted for attack,
 *   and returns `false` otherwise.
 *
 * @param bool mustBeDead = false : if `true`, only returns `true` if the [Creature] is also dead. Otherwise, it must be alive.
 * @return bool targetable
 */
bool TSCreature::IsTargetableForAttack(bool mustBeDead) 
{
    
#ifdef MANGOS
    return creature->IsTargetableForAttack(mustBeDead);
#else
    return creature->isTargetableForAttack(mustBeDead);
#endif
}
    
/**
 * Returns `true` if the [Creature] can assist `friend` in combat against `enemy`,
 *   and returns `false` otherwise.
 *
 * @param [Unit] friend : the Unit we will be assisting
 * @param [Unit] enemy : the Unit that we would attack if we assist `friend`
 * @param bool checkFaction = true : if `true`, the [Creature] must be the same faction as `friend` to assist
 * @return bool canAssist
 */
bool TSCreature::CanAssistTo(TSUnit _u,TSUnit _enemy,bool checkfaction)
{
    auto u = _u.unit;
    auto enemy = _enemy.unit;
    return creature->CanAssistTo(u, enemy, checkfaction);
}
    
/**
 * Returns `true` if the [Creature] has searched for combat assistance already,
 *   and returns `false` otherwise.
 *
 * @return bool searchedForAssistance
 */
bool TSCreature::HasSearchedAssistance() 
{
    return creature->HasSearchedAssistance();
}
    
/**
 * Returns `true` if the [Creature] will give its loot to `player`,
 *   and returns `false` otherwise.
 *
 * @return bool tapped
 */
bool TSCreature::IsTappedBy(TSPlayer _player)
{
    auto player = _player.player;
    
#if defined TRINITY || AZEROTHCORE
    return creature->isTappedBy(player);
#else
    return creature->IsTappedBy(player);
#endif
}
    
/**
 * Returns `true` if the [Creature] will give its loot to a [Player] or [Group],
 *   and returns `false` otherwise.
 *
 * @return bool hasLootRecipient
 */
bool TSCreature::HasLootRecipient() 
{
#if defined TRINITY || AZEROTHCORE
    return creature->hasLootRecipient();
#else
    return creature->HasLootRecipient();
#endif
}
    
/**
 * Returns `true` if the [Creature] can start attacking nearby hostile [Unit]s,
 *   and returns `false` otherwise.
 *
 * @return bool canAggro
 */
bool TSCreature::CanAggro() 
{
#if defined TRINITY || AZEROTHCORE
    return !creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
#else
    return creature->CanInitiateAttack();
    return !creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
#endif
}
    
/**
 * Returns `true` if the [Creature] can move through deep water,
 *   and returns `false` otherwise.
 *
 * @return bool canSwim
 */
bool TSCreature::CanSwim() 
{
    return creature->CanSwim();
}
    
/**
 * Returns `true` if the [Creature] can move on land,
 *   and returns `false` otherwise.
 *
 * @return bool canWalk
 */
bool TSCreature::CanWalk() 
{
    return creature->CanWalk();
}
    
/**
 * Returns `true` if the [Creature] is returning to its spawn position from combat,
 *   and returns `false` otherwise.
 *
 * @return bool inEvadeMode
 */
bool TSCreature::IsInEvadeMode() 
{
    return creature->IsInEvadeMode();
}
    
/**
 * Returns `true` if the [Creature]'s rank is Elite or Rare Elite,
 *   and returns `false` otherwise.
 *
 * @return bool isElite
 */
bool TSCreature::IsElite() 
{
#if defined TRINITY || AZEROTHCORE
    return creature->isElite();
#else
    return creature->IsElite();
#endif
}
    
/**
 * Returns `true` if the [Creature] is a city guard,
 *   and returns `false` otherwise.
 *
 * @return bool isGuard
 */
bool TSCreature::IsGuard() 
{
    return creature->IsGuard();
}
    
/**
 * Returns `true` if the [Creature] is a civilian,
 *   and returns `false` otherwise.
 *
 * @return bool isCivilian
 */
bool TSCreature::IsCivilian() 
{
    return creature->IsCivilian();
}
    
/**
 * Returns `true` if the [Creature] is the leader of a player faction,
 *   and returns `false` otherwise.
 *
 * @return bool isLeader
 */
bool TSCreature::IsRacialLeader() 
{
    return creature->IsRacialLeader();
}
    
/**
 * Returns `true` if the [Creature]'s rank is Boss,
 *   and returns `false` otherwise.
 *
 * @return bool isWorldBoss
 */
bool TSCreature::IsWorldBoss() 
{
#if defined TRINITY || AZEROTHCORE
    return creature->isWorldBoss();
#else
    return creature->IsWorldBoss();
#endif
}
    
/**
 * Returns `true` if the [Creature] cannot cast `spellId` due to a category cooldown,
 *   and returns `false` otherwise.
 *
 * @param uint32 spellId : the ID of a [Spell]
 * @return bool hasCooldown
 */
bool TSCreature::HasCategoryCooldown(uint32 spell) 
{
    
#if defined TRINITY
    if (const SpellInfo* info = sSpellMgr->GetSpellInfo(spell))
        return info->GetCategory() && creature->GetSpellHistory()->HasCooldown(spell);
    else
        return false;
#elif AZEROTHCORE
    if (const SpellInfo* info = sSpellMgr->GetSpellInfo(spell))
        return info->GetCategory() && creature->HasSpellCooldown(spell);
    else
        return false;
#else
    return creature->HasCategoryCooldown(spell);
#endif
}
    
/**
 * Returns `true` if the [Creature] can cast `spellId` when mind-controlled,
 *   and returns `false` otherwise.
 *
 * @param uint32 spellId : the ID of a [Spell]
 * @return bool hasSpell
 */
bool TSCreature::HasSpell(uint32 id) 
{
    return creature->HasSpell(id);
}
    
/**
 * Returns `true` if the [Creature] starts the [Quest] `questId`,
 *   and returns `false` otherwise.
 *
 * @param uint32 questId : the ID of a [Quest]
 * @return bool hasQuest
 */
bool TSCreature::HasQuest(uint32 questId) 
{
    
#if defined TRINITY || AZEROTHCORE
    return creature->hasQuest(questId);
#else
    return creature->HasQuest(questId);
#endif
}
    
/**
 * Returns `true` if the [Creature] has `spellId` on cooldown,
 *   and returns `false` otherwise.
 *
 * @param uint32 spellId : the ID of a [Spell]
 * @return bool hasCooldown
 */
bool TSCreature::HasSpellCooldown(uint32 spellId) 
{
    
#ifdef TRINITY
    return creature->GetSpellHistory()->HasCooldown(spellId);
#else
    return creature->HasSpellCooldown(spellId);
#endif
}
    
/**
 * Returns `true` if the [Creature] can fly,
 *   and returns `false` otherwise.
 *
 * @return bool canFly
 */
bool TSCreature::CanFly() 
{
    return creature->CanFly();
}
    
#if defined(TRINITY) || AZEROTHCORE
/**
 * Returns `true` if the [Creature] is an invisible trigger,
 *   and returns `false` otherwise.
 *
 * @return bool canFly
 */
bool TSCreature::IsTrigger() 
{
    return creature->IsTrigger();
}
    
/**
 * Returns true if the [Creature] is damaged enough for looting
 *
 * @return bool isDamagedEnough
 */
bool TSCreature::IsDamageEnoughForLootingAndReward() 
{
    return creature->IsDamageEnoughForLootingAndReward();
}
    
/**
 * Returns true if the [Creature] can start attacking specified target
 *
 * Does not work on most targets
 *
 * @param [Unit] target
 * @param bool force = true : force [Creature] to attack
 */
bool TSCreature::CanStartAttack(TSUnit _target,bool force)
{
    auto target = _target.unit;
#ifndef AZEROTHCORE
    return creature->CanStartAttack(target, force);
#else
    return creature->CanStartAttack(target);
#endif
}
    
/**
 * Returns true if [Creature] has the specified loot mode
 *
 * @param uint16 lootMode
 * @return bool hasLootMode
 */
bool TSCreature::HasLootMode(uint16 lootMode) 
{
    return creature->HasLootMode(lootMode);
}
#endif
    
/**
 * Returns the time it takes for this [Creature] to respawn once killed.
 *
 * This value does not usually change over a [Creature]'s lifespan,
 *   but can be modified by [Creature:SetRespawnDelay].
 *
 * @return uint32 respawnDelay : the respawn delay, in seconds
 */
uint32 TSCreature::GetRespawnDelay() 
{
    return creature->GetRespawnDelay();
}
    
/**
 * Returns the radius the [Creature] is permitted to wander from its
 *   respawn point.
 *
 * @return float wanderRadius
 */
float TSCreature::GetWanderRadius() 
{
#if defined TRINITY || AZEROTHCORE
    return creature->GetWanderDistance();
#else
    return creature->GetRespawnRadius();
#endif
}
    
#if defined(TRINITY) || AZEROTHCORE
/**
 * Returns the current waypoint path ID of the [Creature].
 *
 * @return uint32 pathId
 */
uint32 TSCreature::GetWaypointPath() 
{
    return creature->GetWaypointPath();
}
#endif
    
/**
 * Returns the current waypoint ID of the [Creature].
 *
 * @return uint32 wpId
 */
uint32 TSCreature::GetCurrentWaypointId() 
{
#ifdef TRINITY
    return creature->GetCurrentWaypointInfo().first;
#elif AZEROTHCORE
    return creature->GetCurrentWaypointID();
#else
    return creature->GetMotionMaster()->getLastReachedWaypoint();
#endif
}
    
/**
 * Returns the default movement type for this [Creature].
 *
 * @return [MovementGeneratorType] defaultMovementType
 */
uint32 TSCreature::GetDefaultMovementType() 
{
    return creature->GetDefaultMovementType();
}
    
/**
 * Returns the aggro range of the [Creature] for `target`.
 *
 * @param [Unit] target
 * @return float aggroRange
 */
float TSCreature::GetAggroRange(TSUnit _target)
{
    auto target = _target.unit;
    
#if defined TRINITY || AZEROTHCORE
    return creature->GetAggroRange(target);
#else
    float AttackDist = creature->GetAttackDistance(target);
    float ThreatRadius = sWorld.getConfig(CONFIG_FLOAT_THREAT_RADIUS);
    return ThreatRadius > AttackDist ? ThreatRadius : AttackDist;
#endif
}
    
#ifndef AZEROTHCORE
/**
 * Returns the effective aggro range of the [Creature] for `target`.
 *
 * If this is smaller than the minimum aggro range set in the config file,
 *   that is used as the aggro range instead.
 *
 * @param [Unit] target
 * @return float attackDistance
 */
float TSCreature::GetAttackDistance(TSUnit _target)
{
    auto target = _target.unit;
    return creature->GetAttackDistance(target);
}
#endif
    
/**
 * Returns the [Group] that can loot this [Creature].
 *
 * @return [Group] lootRecipientGroup : the group or `nil`
 */
TSGroup TSCreature::GetLootRecipientGroup() 
{
#if defined TRINITY || AZEROTHCORE
     return TSGroup(creature->GetLootRecipientGroup());
#else
     return TSGroup(creature->GetGroupLootRecipient());
#endif
}
    
/**
 * Returns the [Player] that can loot this [Creature].
 *
 * @return [Player] lootRecipient : the player or `nil`
 */
TSPlayer  TSCreature::GetLootRecipient() 
{
     return TSPlayer(creature->GetLootRecipient());
}
    
/**
 * Returns the [Creature]'s script name.
 *
 * This is used by the core to apply C++ scripts to the Creature.
 *
 * It is not used by Eluna. Eluna will  AI scripts.
 *
 * @return string scriptName
 */
TSString TSCreature::GetScriptName()
{
     return TSString(creature->GetScriptName());
}
    
/**
 * Returns the [Creature]'s AI name.
 *
 * This is used by the core to assign the Creature's default AI.
 *
 * If the Creature is scripted by Eluna, the AI is n.
 *
 * @return string AIName
 */
TSString TSCreature::GetAIName()
{
     return TSString(creature->GetAIName());
}
    
/**
 * Returns the [Creature]'s script ID.
 *
 * Every C++ script name is assigned a unique ID by the core.
 *   This returns the ID for this [Creature]'s script name.
 *
 * @return uint32 scriptID
 */
uint32 TSCreature::GetScriptId() 
{
    return creature->GetScriptId();
}
    
/**
 * Returns the [Creature]'s cooldown for `spellID`.
 *
 * @param uint32 spellID
 * @return uint32 cooldown : the cooldown, in milliseconds
 */
uint32 TSCreature::GetCreatureSpellCooldownDelay(uint32 spell) 
{
    
#ifdef TRINITY
    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell))
        return creature->GetSpellHistory()->GetRemainingCooldown(spellInfo);
    else
        return 0;
#elif AZEROTHCORE
    if (sSpellMgr->GetSpellInfo(spell))
        return creature->GetSpellCooldown(spell);
    else
        return 0;
#else
    return creature->GetCreatureSpellCooldownDelay(spell);
#endif
}
    
/**
 * Returns the delay between when the [Creature] dies and when its body despawns.
 *
 * @return uint32 corpseDelay : the delay, in seconds
 */
uint32 TSCreature::GetCorpseDelay() 
{
    return creature->GetCorpseDelay();
}
    
/**
 * Returns position the [Creature] returns to when evading from combat
 *   or respawning.
 *
 * @return float x
 * @return float y
 * @return float z
 * @return float o
 */
TSPosition TSCreature::GetHomePosition() 
{
    float x, y, z, o;
#if defined TRINITY || AZEROTHCORE
    creature->GetHomePosition(x, y, z, o);
#else
    creature->GetRespawnCoord(x, y, z, &o);
#endif
    return TSPosition(GetMap()->GetMapId(),x,y,z,o);
}
    
/**
 * Sets the position the [Creature] returns to when evading from combat
 *   or respawning.
 *
 * @param float x
 * @param float y
 * @param float z
 * @param float o
 */
void TSCreature::SetHomePosition(float x,float y,float z,float o) 
{
    
#if defined TRINITY || AZEROTHCORE
    creature->SetHomePosition(x, y, z, o);
#else
    creature->SetRespawnCoord(x, y, z, o);
#endif
    
}
    
enum SelectAggroTarget
{
    SELECT_TARGET_RANDOM = 0,   // Just selects a random target
    SELECT_TARGET_TOPAGGRO,     // Selects targes from top aggro to bottom
    SELECT_TARGET_BOTTOMAGGRO,  // Selects targets from bottom aggro to top
    SELECT_TARGET_NEAREST,
    SELECT_TARGET_FARTHEST
};
    
/**
* Returns a target from the [Creature]'s threat list based on the
*   supplied arguments.
*
*     enum SelectAggroTarget
*     {
*         SELECT_TARGET_RANDOM = 0,  //Just selects a random target
*         SELECT_TARGET_TOPAGGRO,    //Selects targets from top aggro to bottom
*         SELECT_TARGET_BOTTOMAGGRO, //Selects targets from bottom aggro to top
*         SELECT_TARGET_NEAREST,
*         SELECT_TARGET_FARTHEST
*
* For example, if you wanted to select the third-farthest [Player]
*   within 50 yards that has the [Aura] "Corrupted Blood" (ID 24328),
*   you could use this function like so:
*
*     target = creature:GetAITarget(4, true, 3, 50, 24328)
*
* @param [SelectAggroTarget] targetType : how the threat list should be sorted
* @param bool playerOnly = false : if `true`, skips targets that aren't [Player]s
* @param uint32 position = 0 : used as an offset into the threat list. If `targetType` is random, used as the number of players from top of aggro to choose from
* @param float distance = 0.0 : if positive, the maximum distance for the target. If negative, the minimum distance
* @param int32 aura = 0 : if positive, the target must have this [Aura]. If negative, the the target must not have this Aura
* @return [Unit] target : the target, or `nil`
*/
TSUnit  TSCreature::GetAITarget(uint32 targetType,bool playerOnly,uint32 position,float dist,int32 aura) 
{
    // TODO: Fix
    return TSUnit(nullptr);
}
    
/**
 * Returns all [Unit]s in the [Creature]'s threat list.
 *
 * @return table targets
 */
TSArray<TSUnit> TSCreature::GetAITargets() 
{
#ifdef TRINITY
    auto const& threatlist = creature->GetThreatManager().GetThreatenedByMeList();
#elif defined AZEROTHCORE
    auto const& threatlist = creature->getThreatManager().getThreatList();
#else
    ThreatList const& threatlist = creature->GetThreatManager().getThreatList();
#endif
    TSArray <TSUnit> tbl;
    uint32 i = 0;
    for (auto itr = threatlist.begin(); itr != threatlist.end(); ++itr)
    {
#ifdef TRINITY
        Unit* target = itr->second->GetOwner();
#else
        Unit* target = (*itr)->getTarget();
#endif
        if (target) tbl.push(TSUnit(target));
    }
    
    return tbl;
}
    
/**
 * Returns the number of [Unit]s in this [Creature]'s threat list.
 *
 * @return int targetsCount
 */
int TSCreature::GetAITargetsCount() 
{
#ifdef TRINITY
    return creature->GetThreatManager().GetThreatenedByMeList().size();
#elif AZEROTHCORE
    return creature->getThreatManager().getThreatList().size();
#else
    return creature->GetThreatManager().getThreatList().size();
#endif
}
    
/**
 * Returns the [Creature]'s NPC flags.
 *
 * These are used to control whether the NPC is a vendor, can repair items,
 *   can give quests, etc.
 *
 * @return [NPCFlags] npcFlags
 */
uint32 TSCreature::GetNPCFlags() 
{
    return creature->GetUInt32Value(UNIT_NPC_FLAGS);
}
    
#if defined(CLASSIC) || defined(TBC) || defined(WOTLK)
/**
 * Returns the [Creature]'s shield block value.
 *
 * @return uint32 shieldBlockValue
 */
uint32 TSCreature::GetShieldBlockValue() 
{
    return creature->GetShieldBlockValue();
}
#endif
    
#if defined(TRINITY) || AZEROTHCORE
uint16 TSCreature::GetLootMode() 
{
    return creature->GetLootMode();
}
#endif
    
/**
 * Returns the guid of the [Creature] that is used as the ID in the database
 *
 * @return uint32 dbguid
 */
uint32 TSCreature::GetDBTableGUIDLow() 
{
#ifdef TRINITY
    return creature->GetSpawnId();
#else
    // on mangos based this is same as lowguid
    return creature->GetGUIDLow();
#endif
}
    
/**
 * Sets the [Creature]'s NPC flags to `flags`.
 *
 * @param [NPCFlags] flags
 */
void TSCreature::SetNPCFlags(uint32 flags) 
{
    
    creature->SetUInt32Value(UNIT_NPC_FLAGS, flags);
}
    
    
/**
 * Makes the [Creature] able to fly if enabled.
 *
 * @param bool disable
 */
void TSCreature::SetDisableGravity(bool disable) 
{
    
#if defined TRINITY || AZEROTHCORE
    creature->SetDisableGravity(disable);
#else
    creature->SetLevitate(disable);
#endif
}
    
#if defined TRINITY || AZEROTHCORE
void TSCreature::SetLootMode(uint16 lootMode) 
{
    
    creature->SetLootMode(lootMode);
}
#endif
    
/**
 * Sets the [Creature]'s death state to `deathState`.
 *
 * @param [DeathState] deathState
 */
void TSCreature::SetDeathState(int32 state) 
{
    
#if defined TRINITY || AZEROTHCORE
    creature->setDeathState((DeathState)state);
#else
    creature->SetDeathState((DeathState)state);
#endif
}
    
/**
 * Sets whether the [Creature] is currently walking or running.
 *
 * @param bool enable = true : `true` to enable walking, `false` for running
 */
void TSCreature::SetWalk(bool enable) 
{
    
    creature->SetWalk(enable);
}
    
/**
 * Equips given [Item]s to the [Unit]. Using 0 removes the equipped [Item]
 *
 * @param uint32 main_hand : main hand [Item]'s entry
 * @param uint32 off_hand : off hand [Item]'s entry
 * @param uint32 ranged : ranged [Item]'s entry
 */
void TSCreature::SetEquipmentSlots(uint32 main_hand,uint32 off_hand,uint32 ranged) 
{
    
#if defined TRINITY || AZEROTHCORE
    creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, main_hand);
    creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, off_hand);
    creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, ranged);
#else
    creature->SetVirtualItem(VIRTUAL_ITEM_SLOT_0, main_hand);
    creature->SetVirtualItem(VIRTUAL_ITEM_SLOT_1, off_hand);
    creature->SetVirtualItem(VIRTUAL_ITEM_SLOT_2, ranged);
#endif
}
    
/**
 * Sets whether the [Creature] can be aggroed.
 *
 * @param bool allow = true : `true` to allow aggro, `false` to disable aggro
 */
void TSCreature::SetAggroEnabled(bool allow) 
{
    
#if defined TRINITY || AZEROTHCORE
    if (allow)
        creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
    else
        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
#else
    if (allow)
        creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
    else
        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
#endif
    
}
    
/**
 * Sets whether the [Creature] gives reputation or not.
 *
 * @param bool disable = true : `true` to disable reputation, `false` to enable
 */
void TSCreature::SetDisableReputationGain(bool disable) 
{
    
    creature->SetDisableReputationGain(disable);
}
    
/**
 * Sets the [Creature] as in combat with all [Player]s in the dungeon instance.
 *
 * This is used by raid bosses to prevent Players from using out-of-combat
 *   actions once the encounter has begun.
 */
void TSCreature::SetInCombatWithZone() 
{
#if defined AZEROTHCORE
    if (creature->IsAIEnabled)
        creature->AI()->DoZoneInCombat();
#elif defined TRINITY
    if (creature->IsAIEnabled())
        creature->AI()->DoZoneInCombat();
#else
    creature->SetInCombatWithZone();
#endif
}
    
/**
 * Sets the distance the [Creature] can wander from it's spawn point.
 *
 * @param float distance
 */
void TSCreature::SetWanderRadius(float dist) 
{
    
#if defined TRINITY || AZEROTHCORE
    creature->SetWanderDistance(dist);
#else
    creature->SetRespawnRadius(dist);
#endif
}
    
/**
 * Sets the time it takes for the [Creature] to respawn when killed.
 *
 * @param uint32 delay : the delay, in seconds
 */
void TSCreature::SetRespawnDelay(uint32 delay) 
{
    
    creature->SetRespawnDelay(delay);
}
    
/**
 * Sets the default movement type of the [Creature].
 *
 * @param [MovementGeneratorType] type
 */
void TSCreature::SetDefaultMovementType(int32 type) 
{
    
    creature->SetDefaultMovementType((MovementGeneratorType)type);
}
    
/**
 * Sets whether the [Creature] can search for assistance at low health or not.
 *
 * @param bool enable = true : `true` to disable searching, `false` to allow
 */
void TSCreature::SetNoSearchAssistance(bool val) 
{
    
    creature->SetNoSearchAssistance(val);
}
    
/**
 * Sets whether the [Creature] can call nearby enemies for help in combat or not.
 *
 * @param bool enable = true : `true` to disable calling for help, `false` to enable
 */
void TSCreature::SetNoCallAssistance(bool val) 
{
    
    creature->SetNoCallAssistance(val);
}
    
/**
 * Sets whether the creature is hovering / levitating or not.
 *
 * @param bool enable = true : `true` to enable hovering, `false` to disable
 */
void TSCreature::SetHover(bool enable) 
{
    
#if defined TRINITY || AZEROTHCORE
    creature->SetHover(enable);
#else
    // Copy paste from Aura::HandleAuraHover
    // TODO: implement core side properly
    WorldPacket data;
    if (enable)
        data.Initialize(SMSG_MOVE_SET_HOVER, 8 + 4);
    else
        data.Initialize(SMSG_MOVE_UNSET_HOVER, 8 + 4);
    data << creature->GetPackGUID();
    data << uint32(0);
#ifdef CMANGOS
    creature->SendMessageToSet(data, true);
#else
    creature->SendMessageToSet(&data, true);
#endif
#endif
}
    
/**
 * Despawn this [Creature].
 *
 * @param uint32 delay = 0 : dely to despawn in milliseconds
 */
void TSCreature::DespawnOrUnsummon(uint32 msTimeToDespawn) 
{
    
#if defined TRINITY || AZEROTHCORE
    creature->DespawnOrUnsummon(Milliseconds(msTimeToDespawn));
#else
    creature->ForcedDespawn(msTimeToDespawn);
#endif
}
    
/**
 * Respawn this [Creature].
 */
void TSCreature::Respawn() 
{
    creature->Respawn();
}
    
/**
 * Remove this [Creature]'s corpse.
 */
void TSCreature::RemoveCorpse() 
{
    creature->RemoveCorpse();
}
    
/**
 * Make the [Creature] start following its waypoint path.
 */
void TSCreature::MoveWaypoint() 
{
#if defined TRINITY || AZEROTHCORE
    creature->GetMotionMaster()->MovePath(creature->GetWaypointPath(), true);
#else
    creature->GetMotionMaster()->MoveWaypoint();
#endif
}
    
/**
 * Make the [Creature] call for assistance in combat from other nearby [Creature]s.
 */
void TSCreature::CallAssistance() 
{
    creature->CallAssistance();
}
    
/**
 * Make the [Creature] call for help in combat from friendly [Creature]s within `radius`.
 *
 * @param float radius
 */
void TSCreature::CallForHelp(float radius) 
{
    
    creature->CallForHelp(radius);
}
    
/**
 * Make the [Creature] flee combat to get assistance from a nearby friendly [Creature].
 */
void TSCreature::FleeToGetAssistance() 
{
    creature->DoFleeToGetAssistance();
}
    
/**
 * Make the [Creature] attack `target`.
 *
 * @param [Unit] target
 */
void TSCreature::AttackStart(TSUnit _target)
{
    auto target = _target.unit;
    
    creature->AI()->AttackStart(target);
}
    
/**
 * Save the [Creature] in the database.
 */
void TSCreature::SaveToDB() 
{
    creature->SaveToDB();
}
    
/**
 * Make the [Creature] try to find a new target.
 *
 * This should be called every update cycle for the Creature's AI.
 */
TSUnit  TSCreature::SelectVictim() 
{
#if defined TRINITY || AZEROTHCORE
     return TSUnit(creature->SelectVictim());
#else
     return TSUnit(creature->SelectHostileTarget());
#endif
}
    
/**
 * Transform the [Creature] into another Creature.
 *
 * @param uint32 entry : the Creature ID to transform into
 * @param uint32 dataGUIDLow = 0 : use this Creature's model and equipment instead of the defaults
 */
void TSCreature::UpdateEntry(uint32 entry,uint32 dataGuidLow) 
{
    
#if defined TRINITY || AZEROTHCORE
    creature->UpdateEntry(entry, dataGuidLow ? eObjectMgr->GetCreatureData(dataGuidLow) : NULL);
#else
    creature->UpdateEntry(entry, ALLIANCE, dataGuidLow ? eObjectMgr->GetCreatureData(dataGuidLow) : NULL);
#endif
}
    
#if defined TRINITY || AZEROTHCORE
/**
 * Resets [Creature]'s loot mode to default
 */
void TSCreature::ResetLootMode() 
{
    creature->ResetLootMode();
}
    
/**
 * Removes specified loot mode from [Creature]
 *
 * @param uint16 lootMode
 */
void TSCreature::RemoveLootMode(uint16 lootMode) 
{
    
    creature->RemoveLootMode(lootMode);
}
    
/**
 * Adds a loot mode to the [Creature]
 *
 * @param uint16 lootMode
 */
void TSCreature::AddLootMode(uint16 lootMode) 
{
    
    creature->AddLootMode(lootMode);
}
#endif
    
/**
 * Returns the [Creature]'s creature family ID (enumerated in CreatureFamily.dbc).
 *
 * <pre>
 * enum CreatureFamily
 * {
 *     CREATURE_FAMILY_NONE                = 0,    // TrinityCore only
 *     CREATURE_FAMILY_WOLF                = 1,
 *     CREATURE_FAMILY_CAT                 = 2,
 *     CREATURE_FAMILY_SPIDER              = 3,
 *     CREATURE_FAMILY_BEAR                = 4,
 *     CREATURE_FAMILY_BOAR                = 5,
 *     CREATURE_FAMILY_CROCOLISK           = 6,
 *     CREATURE_FAMILY_CARRION_BIRD        = 7,
 *     CREATURE_FAMILY_CRAB                = 8,
 *     CREATURE_FAMILY_GORILLA             = 9,
 *     CREATURE_FAMILY_HORSE_CUSTOM        = 10,   // Does not exist in DBC but used for horse like beasts in DB
 *     CREATURE_FAMILY_RAPTOR              = 11,
 *     CREATURE_FAMILY_TALLSTRIDER         = 12,
 *     CREATURE_FAMILY_FELHUNTER           = 15,
 *     CREATURE_FAMILY_VOIDWALKER          = 16,
 *     CREATURE_FAMILY_SUCCUBUS            = 17,
 *     CREATURE_FAMILY_DOOMGUARD           = 19,
 *     CREATURE_FAMILY_SCORPID             = 20,
 *     CREATURE_FAMILY_TURTLE              = 21,
 *     CREATURE_FAMILY_IMP                 = 23,
 *     CREATURE_FAMILY_BAT                 = 24,
 *     CREATURE_FAMILY_HYENA               = 25,
 *     CREATURE_FAMILY_BIRD_OF_PREY        = 26,   // Named CREATURE_FAMILY_OWL in Mangos
 *     CREATURE_FAMILY_WIND_SERPENT        = 27,
 *     CREATURE_FAMILY_REMOTE_CONTROL      = 28,
 *     CREATURE_FAMILY_FELGUARD            = 29,   // This and below is TBC+
 *     CREATURE_FAMILY_DRAGONHAWK          = 30,
 *     CREATURE_FAMILY_RAVAGER             = 31,
 *     CREATURE_FAMILY_WARP_STALKER        = 32,
 *     CREATURE_FAMILY_SPOREBAT            = 33,
 *     CREATURE_FAMILY_NETHER_RAY          = 34,
 *     CREATURE_FAMILY_SERPENT             = 35,
 *     CREATURE_FAMILY_SEA_LION            = 36,   // TBC only
 *     CREATURE_FAMILY_MOTH                = 37,   // This and below is WotLK+
 *     CREATURE_FAMILY_CHIMAERA            = 38,
 *     CREATURE_FAMILY_DEVILSAUR           = 39,
 *     CREATURE_FAMILY_GHOUL               = 40,
 *     CREATURE_FAMILY_SILITHID            = 41,
 *     CREATURE_FAMILY_WORM                = 42,
 *     CREATURE_FAMILY_RHINO               = 43,
 *     CREATURE_FAMILY_WASP                = 44,
 *     CREATURE_FAMILY_CORE_HOUND          = 45,
 *     CREATURE_FAMILY_SPIRIT_BEAST        = 46
 * </pre>
 *
 * @return [CreatureFamily] creatureFamily
 */
uint32 TSCreature::GetCreatureFamily() 
{
    uint32 entry = creature->GetEntry();
    
#if defined TRINITY || AZEROTHCORE
    CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(entry);
    if (cInfo)
        return cInfo->family;
#else
    CreatureInfo const* cInfo = ObjectMgr::GetCreatureTemplate(entry);
    if (cInfo)
        return cInfo->Family;
#endif
}
    
// Inherited from Unit
// Inherited from WorldObject
// Inherited from Object
