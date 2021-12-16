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
#include "magisters_terrace.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"

enum Yells
{
    SAY_AGGRO                       = 0,
    SAY_ENERGY                      = 1,
    SAY_OVERLOAD                    = 2,
    SAY_KILL                        = 3,
    EMOTE_DISCHARGE_ENERGY          = 4

    //is this text for real?
    //#define SAY_DEATH             "What...happen...ed."
};

enum Spells
{
    SPELL_CHAIN_LIGHTNING           = 44318,
    SPELL_OVERLOAD                  = 44353,
    SPELL_ARCANE_SHOCK              = 44319,

    SPELL_SUMMON_PURE_ENERGY        = 44322, // mod scale -10
    H_SPELL_SUMMON_PURE_ENERGY1     = 46154, // mod scale -5
    H_SPELL_SUMMON_PURE_ENERGY2     = 46159  // mod scale -5
};

enum Events
{
    EVENT_ENERGY_BOLT               = 1,
    EVENT_ENERGY_FEEDBACK,
    EVENT_CHAIN_LIGHTNING,
    EVENT_OVERLOAD,
    EVENT_ARCANE_SHOCK
};

enum Misc
{
    INTERVAL_MODIFIER               = 15,
    INTERVAL_SWITCH                 = 6
};

class boss_vexallus : public CreatureScript
{
    public:
        boss_vexallus() : CreatureScript("boss_vexallus") { }

        struct boss_vexallusAI : public BossAI
        {
            boss_vexallusAI(Creature* creature) : BossAI(creature, DATA_VEXALLUS)
            {
                _intervalHealthAmount = 1;
                _enraged = false;
            }

            void Reset() override
            {
                _Reset();
                _intervalHealthAmount = 1;
                _enraged = false;
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_KILL);
            }

            void JustEngagedWith(Unit* who) override
            {
                Talk(SAY_AGGRO);
                BossAI::JustEngagedWith(who);

                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 8s);
                events.ScheduleEvent(EVENT_ARCANE_SHOCK, 5s);
            }

            void JustSummoned(Creature* summoned) override
            {
                if (Unit* temp = SelectTarget(SelectTargetMethod::Random, 0))
                    summoned->GetMotionMaster()->MoveFollow(temp, 0, 0);

                summons.Summon(summoned);
            }

            void DamageTaken(Unit* /*who*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
            {
                if (_enraged)
                    return;

                // 85%, 70%, 55%, 40%, 25%
                if (!HealthAbovePct(100 - INTERVAL_MODIFIER * _intervalHealthAmount))
                {
                    // increase amount, unless we're at 10%, then we switch and return
                    if (_intervalHealthAmount == INTERVAL_SWITCH)
                    {
                        _enraged = true;
                        events.Reset();
                        events.ScheduleEvent(EVENT_OVERLOAD, 1200ms);
                        return;
                    }
                    else
                        ++_intervalHealthAmount;

                    Talk(SAY_ENERGY);
                    Talk(EMOTE_DISCHARGE_ENERGY);

                    if (IsHeroic())
                    {
                        DoCast(me, H_SPELL_SUMMON_PURE_ENERGY1);
                        DoCast(me, H_SPELL_SUMMON_PURE_ENERGY2);
                    }
                    else
                        DoCast(me, SPELL_SUMMON_PURE_ENERGY);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 8s);
                            break;
                        case EVENT_ARCANE_SHOCK:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 20.0f, true))
                                DoCast(target, SPELL_ARCANE_SHOCK);
                            events.ScheduleEvent(EVENT_ARCANE_SHOCK, 8s);
                            break;
                        case EVENT_OVERLOAD:
                            DoCastVictim(SPELL_OVERLOAD);
                            events.ScheduleEvent(EVENT_OVERLOAD, 2s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _intervalHealthAmount;
            bool _enraged;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetMagistersTerraceAI<boss_vexallusAI>(creature);
        };
};

enum NpcPureEnergy
{
    SPELL_ENERGY_BOLT               = 46156,
    SPELL_ENERGY_FEEDBACK           = 44335,
    SPELL_PURE_ENERGY_PASSIVE       = 44326
};

class npc_pure_energy : public CreatureScript
{
    public:
        npc_pure_energy() : CreatureScript("npc_pure_energy") { }

        struct npc_pure_energyAI : public ScriptedAI
        {
            npc_pure_energyAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
            }

            void JustDied(Unit* killer) override
            {
                if (killer)
                    killer->CastSpell(killer, SPELL_ENERGY_FEEDBACK, true);
                me->RemoveAurasDueToSpell(SPELL_PURE_ENERGY_PASSIVE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetMagistersTerraceAI<npc_pure_energyAI>(creature);
        };
};

void AddSC_boss_vexallus()
{
    new boss_vexallus();
    new npc_pure_energy();
}
