/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

/*
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "npc_pet_dk_".
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CombatAI.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

enum DeathKnightSpells
{
    // Ebon Gargoyle
    SPELL_DK_SUMMON_GARGOYLE_1      = 49206,
    SPELL_DK_SUMMON_GARGOYLE_2      = 50514,
    SPELL_DK_DISMISS_GARGOYLE       = 50515,
    SPELL_DK_SANCTUARY              = 54661,

    // Dancing Rune Weapon
    SPELL_DK_DANCING_RUNE_WEAPON    = 49028,
    SPELL_COPY_WEAPON = 63416,
    SPELL_DK_RUNE_WEAPON_MARK = 50474,
    SPELL_DK_DANCING_RUNE_WEAPON_VISUAL = 53160,
    SPELL_FAKE_AGGRO_RADIUS_8_YARD = 49812,
    SPELL_DK_RUNE_WEAPON_SCALING_01 = 51905,
    SPELL_DK_RUNE_WEAPON_SCALING = 51906,
    SPELL_PET_SCALING__MASTER_SPELL_06__SPELL_HIT_EXPERTISE_SPELL_PENETRATION = 67561,
    SPELL_DK_PET_SCALING_03 = 61697,
    SPELL_AGGRO_8_YD_PBAE = 49813,
    // Main Spells
    SPELL_BLOOD_STRIKE = 49926,
    SPELL_PLAGUE_STRIKE = 49917,
    
    SPELL_DISMISS_RUNEBLADE = 50707 // Right now despawn is done by its duration
};

class npc_pet_dk_ebon_gargoyle : public CreatureScript
{
    public:
        npc_pet_dk_ebon_gargoyle() : CreatureScript("npc_pet_dk_ebon_gargoyle") { }

        struct npc_pet_dk_ebon_gargoyleAI : CasterAI
        {
            npc_pet_dk_ebon_gargoyleAI(Creature* creature) : CasterAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                // Not needed to be despawned now
                _despawnTimer = 0;
            }

            void InitializeAI() override
            {
                Initialize();

                CasterAI::InitializeAI();
                ObjectGuid ownerGuid = me->GetOwnerGUID();
                if (!ownerGuid)
                    return;

                // Find victim of Summon Gargoyle spell
                std::list<Unit*> targets;
                Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, 30.0f);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, targets, u_check);
                me->VisitNearbyObject(30.0f, searcher);
                for (std::list<Unit*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                    if ((*iter)->HasAura(SPELL_DK_SUMMON_GARGOYLE_1, ownerGuid))
                    {
                        me->Attack((*iter), false);
                        break;
                    }
            }

            void JustDied(Unit* /*killer*/) override
            {
                // Stop Feeding Gargoyle when it dies
                if (Unit* owner = me->GetOwner())
                    owner->RemoveAurasDueToSpell(SPELL_DK_SUMMON_GARGOYLE_2);
            }

            // Fly away when dismissed
            void SpellHit(Unit* source, SpellInfo const* spell) override
            {
                if (spell->Id != SPELL_DK_DISMISS_GARGOYLE || !me->IsAlive())
                    return;

                Unit* owner = me->GetOwner();
                if (!owner || owner != source)
                    return;

                // Stop Fighting
                me->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE, true);

                // Sanctuary
                me->CastSpell(me, SPELL_DK_SANCTUARY, true);
                me->SetReactState(REACT_PASSIVE);

                //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
                // Fly Away
                me->SetCanFly(true);
                me->SetSpeed(MOVE_FLIGHT, 0.75f, true);
                me->SetSpeed(MOVE_RUN, 0.75f, true);
                float x = me->GetPositionX() + 20 * std::cos(me->GetOrientation());
                float y = me->GetPositionY() + 20 * std::sin(me->GetOrientation());
                float z = me->GetPositionZ() + 40;
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MovePoint(0, x, y, z);

                // Despawn as soon as possible
                _despawnTimer = 4 * IN_MILLISECONDS;
            }

            void UpdateAI(uint32 diff) override
            {
                if (_despawnTimer > 0)
                {
                    if (_despawnTimer > diff)
                        _despawnTimer -= diff;
                    else
                        me->DespawnOrUnsummon();
                    return;
                }

                CasterAI::UpdateAI(diff);
            }

        private:
           uint32 _despawnTimer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_pet_dk_ebon_gargoyleAI(creature);
        }
};

enum DancingRuneWeapon
{
    DATA_INITIAL_TARGET_GUID = 1,

    EVENT_SPELL_CAST_1 = 1,
    EVENT_SPELL_CAST_2 = 2
};

class npc_pet_dk_rune_weapon : public CreatureScript
{
    public:
        npc_pet_dk_rune_weapon() : CreatureScript("npc_pet_dk_rune_weapon") { }

        struct npc_pet_dk_rune_weaponAI : ScriptedAI
        {
            npc_pet_dk_rune_weaponAI(Creature* creature) : ScriptedAI(creature)
            {
                // Prevent early victim engage
                creature->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                DoCast(summoner, SPELL_COPY_WEAPON, true);
                DoCast(summoner, SPELL_DK_RUNE_WEAPON_MARK, true);
                DoCast(me, SPELL_DK_DANCING_RUNE_WEAPON_VISUAL, true);
                DoCast(me, SPELL_FAKE_AGGRO_RADIUS_8_YARD, true);
                DoCast(me, SPELL_DK_RUNE_WEAPON_SCALING_01, true);
                DoCast(me, SPELL_DK_RUNE_WEAPON_SCALING, true);
                DoCast(me, SPELL_PET_SCALING__MASTER_SPELL_06__SPELL_HIT_EXPERTISE_SPELL_PENETRATION, true);
                DoCast(me, SPELL_DK_PET_SCALING_03, true);

                _events.ScheduleEvent(EVENT_SPELL_CAST_2, 6 * IN_MILLISECONDS);

                me->SetRedirectThreat(summoner->GetGUID(), 100);
            }

            void MoveInLineOfSight(Unit* /*who*/) override { }
            void AttackStart(Unit* /*who*/) override { }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                switch (type)
                {
                    case DATA_INITIAL_TARGET_GUID:
                        _targetGUID = guid;
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (Unit* target = ObjectAccessor::GetUnit(*me, _targetGUID))
                        {
                            if (me->Attack(target, true))
                                me->GetMotionMaster()->MoveChase(target);
                            DoCast(target, SPELL_AGGRO_8_YD_PBAE, true);
                            _events.ScheduleEvent(EVENT_SPELL_CAST_1, 1 * IN_MILLISECONDS);
                        }
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (me->HasReactState(REACT_PASSIVE))
                    return;

                if (me->IsInCombat() && (!me->GetVictim() || !me->IsValidAttackTarget(me->GetVictim())))
                    EnterEvadeMode(EVADE_REASON_NO_HOSTILES);

                if (!me->IsInCombat())
                {
                    Unit* ownerTarget = nullptr;
                    if (Player* owner = me->GetCharmerOrOwner()->ToPlayer())
                        ownerTarget = owner->GetSelectedUnit();

                    // recognize which victim will be choosen
                    if (ownerTarget && ownerTarget->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (!ownerTarget->HasBreakableByDamageCrowdControlAura(ownerTarget))
                            if (me->Attack(ownerTarget, true))
                                me->GetMotionMaster()->MoveChase(ownerTarget);
                    }
                    else if (ownerTarget && (ownerTarget->GetTypeId() != TYPEID_PLAYER) && IsInThreatList(ownerTarget))
                    {
                        if (!ownerTarget->HasBreakableByDamageCrowdControlAura(ownerTarget))
                            if (me->Attack(ownerTarget, true))
                                me->GetMotionMaster()->MoveChase(ownerTarget);
                    }
                    else
                        Init();
                }

                /*
                    Investigate further if these casts are done by
                    any owned aura, eitherway SMSG_SPELL_GO
                    is sent every X seconds.
                */
                _events.Update(diff);

                while (uint32 _eventId = _events.ExecuteEvent())
                {
                    switch (_eventId)
                    {
                        case EVENT_SPELL_CAST_1:
                            // Cast every second
                            if (Unit* victim = ObjectAccessor::GetUnit(*me, _targetGUID))
                                DoCast(victim, SPELL_AGGRO_8_YD_PBAE, true);
                            _events.ScheduleEvent(EVENT_SPELL_CAST_1, 1 * IN_MILLISECONDS);
                            break;
                        case EVENT_SPELL_CAST_2:
                            // Cast every 6 seconds
                            DoCast(me, SPELL_DK_DANCING_RUNE_WEAPON_VISUAL, true);
                            _events.ScheduleEvent(EVENT_SPELL_CAST_2, 6 * IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                if (!me->IsAlive())
                    return;

                Unit* owner = me->GetCharmerOrOwner();

                me->CombatStop(true);
                if (owner && !me->HasUnitState(UNIT_STATE_FOLLOW))
                {
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle(), MOTION_SLOT_ACTIVE);
                }
                Init();
            }

            void Init()
            {
                Unit* owner = me->GetCharmerOrOwner();

                std::list<Unit*> targets;
                Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, 30.0f);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, targets, u_check);
                me->VisitNearbyObject(40.0f, searcher);

                Unit* highestThreatUnit = nullptr;
                float highestThreat = 0.0f;
                Unit* nearestPlayer = nullptr;
                for (std::list<Unit*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                {
                    // Consider only units without CC
                    if (!(*iter)->HasBreakableByDamageCrowdControlAura((*iter)))
                    {
                        // Take first found unit
                        if (!highestThreatUnit && (*iter)->GetTypeId() != TYPEID_PLAYER)
                        {
                            highestThreatUnit = (*iter);
                            continue;
                        }
                        if (!nearestPlayer && ((*iter)->GetTypeId() == TYPEID_PLAYER))
                        {
                            nearestPlayer = (*iter);
                            continue;
                        }
                        // else compare best fit unit with current unit
                        ThreatContainer::StorageType triggers = (*iter)->getThreatManager().getThreatList();
                        for (ThreatContainer::StorageType::const_iterator trig_citr = triggers.begin(); trig_citr != triggers.end(); ++trig_citr)
                        {
                            // Try to find threat referenced to owner
                            if ((*trig_citr)->getTarget() == owner)
                            {
                                // Check if best fit hostile unit hs lower threat than this current unit
                                if (highestThreat < (*trig_citr)->getThreat())
                                {
                                    // If so, update best fit unit
                                    highestThreat = (*trig_citr)->getThreat();
                                    highestThreatUnit = (*iter);
                                    break;
                                }
                            }
                        }
                        // In case no unit with threat was found so far, always check for nearest unit (only for players)
                        if ((*iter)->GetTypeId() == TYPEID_PLAYER)
                        {
                            // If this player is closer than the previous one, update it
                            if (me->GetDistance((*iter)->GetPosition()) < me->GetDistance(nearestPlayer->GetPosition()))
                                nearestPlayer = (*iter);
                        }
                    }
                }
                // Prioritize units with threat referenced to owner
                if (highestThreat > 0.0f && highestThreatUnit)
                {
                    if (me->Attack(highestThreatUnit, true))
                        me->GetMotionMaster()->MoveChase(highestThreatUnit);
                }
                // If there is no such target, try to attack nearest hostile unit if such exists
                else if (nearestPlayer)
                {
                    if (me->Attack(nearestPlayer, true))
                        me->GetMotionMaster()->MoveChase(nearestPlayer);
                }
            }

            bool IsInThreatList(Unit* target)
            {
                Unit* owner = me->GetCharmerOrOwner();

                std::list<Unit*> targets;
                Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, 30.0f);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, targets, u_check);
                me->VisitNearbyObject(40.0f, searcher);

                for (std::list<Unit*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                {
                    if ((*iter) == target)
                    {
                        // Consider only units without CC
                        if (!(*iter)->HasBreakableByDamageCrowdControlAura((*iter)))
                        {
                            ThreatContainer::StorageType triggers = (*iter)->getThreatManager().getThreatList();
                            for (ThreatContainer::StorageType::const_iterator trig_citr = triggers.begin(); trig_citr != triggers.end(); ++trig_citr)
                            {
                                // Try to find threat referenced to owner
                                if ((*trig_citr)->getTarget() == owner)
                                    return true;
                            }
                        }
                    }
                }
                return false;
            }

        private:
            ObjectGuid _targetGUID;
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_pet_dk_rune_weaponAI(creature);
        }
};

void AddSC_deathknight_pet_scripts()
{
    new npc_pet_dk_ebon_gargoyle();
    new npc_pet_dk_rune_weapon();
}
