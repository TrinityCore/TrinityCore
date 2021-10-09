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

/*
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "npc_pet_dk_".
 */

#include "ScriptMgr.h"
#include "CombatAI.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum DeathKnightSpells
{
    SPELL_DK_SUMMON_GARGOYLE_1 = 49206,
    SPELL_DK_SUMMON_GARGOYLE_2 = 50514,
    SPELL_DK_DISMISS_GARGOYLE = 50515,
    SPELL_DK_SANCTUARY = 54661,
    SPELL_DK_DANCING_RUNE_WEAPON = 49028,
    SPELL_COPY_WEAPON = 63416,
    SPELL_DK_RUNE_WEAPON_MARK = 50474,
    SPELL_DK_DANCING_RUNE_WEAPON_VISUAL = 53160,
    SPELL_FAKE_AGGRO_RADIUS_8_YARD = 49812,
    SPELL_DK_RUNE_WEAPON_SCALING_01 = 51905,
    SPELL_DK_RUNE_WEAPON_SCALING = 51906,
    SPELL_PET_SCALING__MASTER_SPELL_06__SPELL_HIT_EXPERTISE_SPELL_PENETRATION = 67561,
    SPELL_DK_PET_SCALING_03 = 61697,
    SPELL_AGGRO_8_YD_PBAE = 49813,
    SPELL_DISMISS_RUNEBLADE = 50707, // Right now despawn is done by its duration
};

struct npc_pet_dk_ebon_gargoyle : CasterAI
{
    npc_pet_dk_ebon_gargoyle(Creature* creature) : CasterAI(creature) { }

    void InitializeAI() override
    {
        CasterAI::InitializeAI();
        ObjectGuid ownerGuid = me->GetOwnerGUID();
        if (!ownerGuid)
            return;

        // Find victim of Summon Gargoyle spell
        std::list<Unit*> targets;
        Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, 30.0f);
        Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, targets, u_check);
        Cell::VisitAllObjects(me, searcher, 30.0f);
        for (Unit* target : targets)
        {
            if (target->HasAura(SPELL_DK_SUMMON_GARGOYLE_1, ownerGuid))
            {
                me->Attack(target, false);
                break;
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        // Stop Feeding Gargoyle when it dies
        if (Unit* owner = me->GetOwner())
            owner->RemoveAurasDueToSpell(SPELL_DK_SUMMON_GARGOYLE_2);
    }

    // Fly away when dismissed
    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_DK_DISMISS_GARGOYLE || !me->IsAlive())
            return;

        Unit* owner = me->GetOwner();
        if (!owner || owner != caster)
            return;

        // Stop Fighting
        me->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE, true);

        // Sanctuary
        me->CastSpell(me, SPELL_DK_SANCTUARY, true);
        me->SetReactState(REACT_PASSIVE);

        //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
        // Fly Away
        me->SetCanFly(true);
        me->SetSpeedRate(MOVE_FLIGHT, 0.75f);
        me->SetSpeedRate(MOVE_RUN, 0.75f);
        float x = me->GetPositionX() + 20 * std::cos(me->GetOrientation());
        float y = me->GetPositionY() + 20 * std::sin(me->GetOrientation());
        float z = me->GetPositionZ() + 40;
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MovePoint(0, x, y, z);

        // Despawn as soon as possible
        me->DespawnOrUnsummon(Seconds(4));
    }
};

struct npc_pet_dk_guardian : public AggressorAI
{
    npc_pet_dk_guardian(Creature* creature) : AggressorAI(creature) { }

    bool CanAIAttack(Unit const* target) const override
    {
        if (!target)
            return false;
        Unit* owner = me->GetOwner();
        if (owner && !target->IsInCombatWith(owner))
            return false;
        return AggressorAI::CanAIAttack(target);
    }
};

enum DancingRuneWeaponMisc
{
    TASK_GROUP_COMBAT = 1,
    DATA_INITIAL_TARGET_GUID = 1,
};

struct npc_pet_dk_rune_weapon : ScriptedAI
{
    npc_pet_dk_rune_weapon(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* summoner) override
    {
        me->SetReactState(REACT_PASSIVE);

        if (summoner->GetTypeId() != TYPEID_UNIT)
            return;

        Unit* unitSummoner = summoner->ToUnit();

        DoCast(unitSummoner, SPELL_COPY_WEAPON, true);
        DoCast(unitSummoner, SPELL_DK_RUNE_WEAPON_MARK, true);
        DoCastSelf(SPELL_DK_DANCING_RUNE_WEAPON_VISUAL, true);
        DoCastSelf(SPELL_FAKE_AGGRO_RADIUS_8_YARD, true);
        DoCastSelf(SPELL_DK_RUNE_WEAPON_SCALING_01, true);
        DoCastSelf(SPELL_DK_RUNE_WEAPON_SCALING, true);
        DoCastSelf(SPELL_PET_SCALING__MASTER_SPELL_06__SPELL_HIT_EXPERTISE_SPELL_PENETRATION, true);
        DoCastSelf(SPELL_DK_PET_SCALING_03, true);

        _scheduler.Schedule(500ms, [this](TaskContext /*activate*/)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            if (!_targetGUID.IsEmpty())
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, _targetGUID))
                    me->EngageWithTarget(target);
            }
        }).Schedule(6s, [this](TaskContext visual)
        {
            // Cast every 6 seconds
            DoCastSelf(SPELL_DK_DANCING_RUNE_WEAPON_VISUAL, true);
            visual.Repeat();
        });
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id == DATA_INITIAL_TARGET_GUID)
            _targetGUID = guid;
    }

    void JustEnteredCombat(Unit* who) override
    {
        ScriptedAI::JustEnteredCombat(who);

        // Investigate further if these casts are done by any owned aura, eitherway SMSG_SPELL_GO is sent every X seconds.
        _scheduler.Schedule(1s, TASK_GROUP_COMBAT, [this](TaskContext aggro8YD)
        {
            // Cast every second
            if (Unit* victim = me->GetVictim())
                DoCast(victim, SPELL_AGGRO_8_YD_PBAE, true);
            aggro8YD.Repeat();
        });
    }

    void UpdateAI(uint32 diff) override
    {
        Unit* owner = me->GetOwner();
        if (!owner)
        {
            me->DespawnOrUnsummon();
            return;
        }

        _scheduler.Update(diff);

        if (!UpdateRuneWeaponVictim())
            return;

        DoMeleeAttackIfReady();
    }

    bool CanAIAttack(Unit const* who) const override
    {
        Unit* owner = me->GetOwner();
        return owner && who->IsAlive() && me->IsValidAttackTarget(who) && !who->HasBreakableByDamageCrowdControlAura() && who->IsInCombatWith(owner) && ScriptedAI::CanAIAttack(who);
    }

    // Do not reload Creature templates on evade mode enter - prevent visual lost
    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _scheduler.CancelGroup(TASK_GROUP_COMBAT);

        if (!me->IsAlive())
        {
            EngagementOver();
            return;
        }

        Unit* owner = me->GetCharmerOrOwner();

        me->CombatStop(true);
        me->SetLootRecipient(nullptr);
        me->ResetPlayerDamageReq();
        me->SetLastDamagedTime(0);
        me->SetCannotReachTarget(false);
        me->DoNotReacquireSpellFocusTarget();
        me->SetTarget(ObjectGuid::Empty);
        EngagementOver();

        if (owner && !me->HasUnitState(UNIT_STATE_FOLLOW))
        {
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle());
        }
    }

private:
    // custom UpdateVictim implementation to handle special target selection
    // we prioritize between things that are in combat with owner based on the owner's threat to them
    bool UpdateRuneWeaponVictim()
    {
        Unit* owner = me->GetOwner();
        if (!owner)
            return false;

        if (!me->IsEngaged() && !owner->IsInCombat())
            return false;

        Unit* currentTarget = me->GetVictim();
        if (currentTarget && !CanAIAttack(currentTarget))
        {
            me->InterruptNonMeleeSpells(true); // do not finish casting on invalid targets
            me->AttackStop();
            currentTarget = nullptr;
        }

        Unit* selectedTarget = nullptr;

        // first, try to get the initial target
        if (Unit* initialTarget = ObjectAccessor::GetUnit(*me, _targetGUID))
        {
            if (CanAIAttack(initialTarget))
                selectedTarget = initialTarget;
        }
        else if (!_targetGUID.IsEmpty())
            _targetGUID.Clear();

        CombatManager const& mgr = owner->GetCombatManager();
        if (!selectedTarget)
        {
            if (mgr.HasPvPCombat())
            {
                // select pvp target
                float minDistance = 0.f;
                for (auto const& pair : mgr.GetPvPCombatRefs())
                {
                    Unit* target = pair.second->GetOther(owner);
                    if (target->GetTypeId() != TYPEID_PLAYER)
                        continue;
                    if (!CanAIAttack(target))
                        continue;

                    float dist = owner->GetDistance(target);
                    if (!selectedTarget || dist < minDistance)
                    {
                        selectedTarget = target;
                        minDistance = dist;
                    }
                }
            }
        }

        if (!selectedTarget)
        {
            // select pve target
            float maxThreat = 0.f;
            for (auto const& pair : mgr.GetPvECombatRefs())
            {
                Unit* target = pair.second->GetOther(owner);
                if (!CanAIAttack(target))
                    continue;

                float threat = target->GetThreatManager().GetThreat(owner);
                if (threat >= maxThreat)
                {
                    selectedTarget = target;
                    maxThreat = threat;
                }
            }
        }

        if (!selectedTarget)
        {
            EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
            return false;
        }

        if (selectedTarget != me->GetVictim())
            AttackStart(selectedTarget);
        return true;
    }

    TaskScheduler _scheduler;
    ObjectGuid _targetGUID;
};

void AddSC_deathknight_pet_scripts()
{
    RegisterCreatureAI(npc_pet_dk_ebon_gargoyle);
    RegisterCreatureAI(npc_pet_dk_guardian);
    RegisterCreatureAI(npc_pet_dk_rune_weapon);
}
