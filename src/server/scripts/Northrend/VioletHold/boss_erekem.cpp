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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_BLOODLUST                             = 54516,
    SPELL_BREAK_BONDS                           = 59463,
    SPELL_CHAIN_HEAL                            = 54481,
    SPELL_EARTH_SHIELD                          = 54479,
    SPELL_EARTH_SHOCK                           = 54511,
    SPELL_LIGHTNING_BOLT                        = 53044,
    SPELL_STORMSTRIKE                           = 51876,
    SPELL_WINDFURY                              = 54493
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_ADD_KILLED                              = 4,
    SAY_BOTH_ADDS_KILLED                        = 5
};

struct boss_erekem : public BossAI
{
    boss_erekem(Creature* creature) : BossAI(creature, DATA_EREKEM)
    {
        Initialize();
    }

    void Initialize()
    {
        _phase = 0;
    }

    void Reset() override
    {
        Initialize();
        BossAI::Reset();
        me->SetCanDualWield(false);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        DoCast(me, SPELL_EARTH_SHIELD);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == EFFECT_MOTION_TYPE && pointId == POINT_INTRO)
            me->SetFacingTo(4.921828f);
    }

    void JustReachedHome() override
    {
        BossAI::JustReachedHome();
        instance->SetData(DATA_HANDLE_CELLS, DATA_EREKEM);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    bool CheckGuardAuras(Creature* guard) const
    {
        static uint32 const MechanicImmunityList =
              (1 << MECHANIC_SNARE)
            | (1 << MECHANIC_ROOT)
            | (1 << MECHANIC_FEAR)
            | (1 << MECHANIC_STUN)
            | (1 << MECHANIC_SLEEP)
            | (1 << MECHANIC_CHARM)
            | (1 << MECHANIC_SAPPED)
            | (1 << MECHANIC_HORROR)
            | (1 << MECHANIC_POLYMORPH)
            | (1 << MECHANIC_DISORIENTED)
            | (1 << MECHANIC_FREEZE)
            | (1 << MECHANIC_TURN);

        static std::list<AuraType> const AuraImmunityList =
        {
            SPELL_AURA_MOD_STUN,
            SPELL_AURA_MOD_DECREASE_SPEED,
            SPELL_AURA_MOD_ROOT,
            SPELL_AURA_MOD_CONFUSE,
            SPELL_AURA_MOD_FEAR
        };

        if (guard->HasAuraWithMechanic(MechanicImmunityList))
            return true;

        for (AuraType type : AuraImmunityList)
            if (guard->HasAuraType(type))
                return true;

        return false;
    }

    bool CheckGuardAlive() const
    {
        for (uint32 i = DATA_EREKEM_GUARD_1; i <= DATA_EREKEM_GUARD_2; ++i)
        {
            if (Creature* guard = ObjectAccessor::GetCreature(*me, instance->GetGuidData(i)))
                if (guard->IsAlive())
                    return true;
        }

        return false;
    }

    Unit* GetChainHealTarget() const
    {
        if (HealthBelowPct(85))
            return me;

        for (uint32 i = DATA_EREKEM_GUARD_1; i <= DATA_EREKEM_GUARD_2; ++i)
        {
            if (Creature* guard = ObjectAccessor::GetCreature(*me, instance->GetGuidData(i)))
                if (guard->IsAlive() && !guard->HealthAbovePct(75))
                    return guard;
        }

        return nullptr;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (_phase == 0 && !CheckGuardAlive())
        {
            _phase = 1;
            me->SetCanDualWield(true);
            DoCast(me, SPELL_WINDFURY, true);
        }

        scheduler.Update(diff, [this]
        {
            if (_phase == 1)
                DoSpellAttackIfReady(SPELL_STORMSTRIKE);
            else
                DoMeleeAttackIfReady();
        });
    }

    void ScheduleTasks() override
    {
        scheduler.Schedule(Seconds(20), [this](TaskContext task)
        {
            if (Unit* ally = DoSelectLowestHpFriendly(30.0f))
                DoCast(ally, SPELL_EARTH_SHIELD);

            task.Repeat(Seconds(20));
        });

        scheduler.Schedule(Seconds(2), [this](TaskContext task)
        {
            DoCast(SPELL_BLOODLUST);
            task.Repeat(Seconds(35), Seconds(45));
        });

        scheduler.Schedule(Seconds(2), [this](TaskContext task)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f))
                DoCast(target, SPELL_LIGHTNING_BOLT);

            task.Repeat(Milliseconds(2500));
        });

        scheduler.Schedule(Seconds(10), [this](TaskContext task)
        {
            if (Unit* ally = DoSelectLowestHpFriendly(40.0f))
                DoCast(ally, SPELL_CHAIN_HEAL);

            if (!CheckGuardAlive())
                task.Repeat(Seconds(3));
            else
                task.Repeat(Seconds(8), Seconds(11));
        });

        scheduler.Schedule(Seconds(2), Seconds(8), [this](TaskContext task)
        {
            DoCastVictim(SPELL_EARTH_SHOCK);
            task.Repeat(Seconds(8), Seconds(13));
        });

        scheduler.Schedule(0s, [this](TaskContext task)
        {
            for (uint32 i = DATA_EREKEM_GUARD_1; i <= DATA_EREKEM_GUARD_2; ++i)
            {
                Creature* guard = ObjectAccessor::GetCreature(*me, instance->GetGuidData(i));

                if (guard && guard->IsAlive() && CheckGuardAuras(guard))
                {
                    DoCastAOE(SPELL_BREAK_BONDS);
                    task.Repeat(Seconds(10));
                    return;
                }
            }
            task.Repeat(Milliseconds(500));
        });
    }

private:
    uint8 _phase;
};

enum GuardSpells
{
    SPELL_GUSHING_WOUND                   = 39215,
    SPELL_HOWLING_SCREECH                 = 54462,
    SPELL_STRIKE                          = 14516
};

struct npc_erekem_guard : public ScriptedAI
{
    npc_erekem_guard(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoZoneInCombat();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

    void ScheduledTasks()
    {
        scheduler.Schedule(Seconds(4), Seconds(8), [this](TaskContext task)
        {
            DoCastVictim(SPELL_STRIKE);
            task.Repeat(Seconds(4), Seconds(8));
        });

        scheduler.Schedule(Seconds(8), Seconds(13), [this](TaskContext task)
        {
            DoCastAOE(SPELL_HOWLING_SCREECH);
            task.Repeat(Seconds(8), Seconds(13));
        });

        scheduler.Schedule(Seconds(1), Seconds(3), [this](TaskContext task)
        {
            DoCastVictim(SPELL_GUSHING_WOUND);
            task.Repeat(Seconds(7), Seconds(12));
        });
    }

private:
    TaskScheduler scheduler;
};

void AddSC_boss_erekem()
{
    RegisterVioletHoldCreatureAI(boss_erekem);
    RegisterVioletHoldCreatureAI(npc_erekem_guard);
}
