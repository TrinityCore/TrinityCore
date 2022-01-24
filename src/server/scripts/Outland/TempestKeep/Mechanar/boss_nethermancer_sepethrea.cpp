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

/* ScriptData
SDName: Boss_Nethermancer_Sepethrea
SD%Complete: 90
SDComment: Need adjustments to initial summons
SDCategory: Tempest Keep, The Mechanar
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "mechanar.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"

enum Says
{
    SAY_AGGRO                      = 0,
    SAY_SUMMON                     = 1,
    SAY_DRAGONS_BREATH             = 2,
    SAY_SLAY                       = 3,
    SAY_DEATH                      = 4
};

enum Spells
{
    SPELL_SUMMON_RAGIN_FLAMES      = 35275, // Not scripted
    SPELL_FROST_ATTACK             = 35263,
    SPELL_ARCANE_BLAST             = 35314,
    SPELL_DRAGONS_BREATH           = 35250,
    SPELL_KNOCKBACK                = 37317,
    SPELL_SOLARBURN                = 35267,
    H_SPELL_SUMMON_RAGIN_FLAMES    = 39084, // Not scripted
    SPELL_INFERNO                  = 35268, // Not scripted
    H_SPELL_INFERNO                = 39346, // Not scripted
    SPELL_FIRE_TAIL                = 35278  // Not scripted
};

enum Events
{
    EVENT_FROST_ATTACK             = 1,
    EVENT_ARCANE_BLAST             = 2,
    EVENT_DRAGONS_BREATH           = 3,
    EVENT_KNOCKBACK                = 4,
    EVENT_SOLARBURN                = 5
};

class boss_nethermancer_sepethrea : public CreatureScript
{
    public: boss_nethermancer_sepethrea(): CreatureScript("boss_nethermancer_sepethrea") { }

        struct boss_nethermancer_sepethreaAI : public BossAI
        {
            boss_nethermancer_sepethreaAI(Creature* creature) : BossAI(creature, DATA_NETHERMANCER_SEPRETHREA) { }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                events.ScheduleEvent(EVENT_FROST_ATTACK, 7s, 10s);
                events.ScheduleEvent(EVENT_ARCANE_BLAST, 12s, 18s);
                events.ScheduleEvent(EVENT_DRAGONS_BREATH, 18s, 22s);
                events.ScheduleEvent(EVENT_KNOCKBACK, 22s, 28s);
                events.ScheduleEvent(EVENT_SOLARBURN, 30s);
                Talk(SAY_AGGRO);
                DoCast(who, SPELL_SUMMON_RAGIN_FLAMES);
                Talk(SAY_SUMMON);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
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
                        case EVENT_FROST_ATTACK:
                            DoCastVictim(SPELL_FROST_ATTACK, true);
                            events.ScheduleEvent(EVENT_FROST_ATTACK, 7s, 10s);
                            break;
                        case EVENT_ARCANE_BLAST:
                            DoCastVictim(SPELL_ARCANE_BLAST, true);
                            events.ScheduleEvent(EVENT_ARCANE_BLAST, 15s);
                            break;
                        case EVENT_DRAGONS_BREATH:
                            DoCastVictim(SPELL_DRAGONS_BREATH, true);
                            events.ScheduleEvent(EVENT_DRAGONS_BREATH, 12s, 22s);
                            if (roll_chance_i(50))
                                Talk(SAY_DRAGONS_BREATH);
                            break;
                        case EVENT_KNOCKBACK:
                            DoCastVictim(SPELL_KNOCKBACK, true);
                            events.ScheduleEvent(EVENT_KNOCKBACK, 15s, 25s);
                            break;
                        case EVENT_SOLARBURN:
                            DoCastVictim(SPELL_SOLARBURN, true);
                            events.ScheduleEvent(EVENT_SOLARBURN, 30s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetMechanarAI<boss_nethermancer_sepethreaAI>(creature);
        }
};

class npc_ragin_flames : public CreatureScript
{
    public:
        npc_ragin_flames() : CreatureScript("npc_ragin_flames") { }

            struct npc_ragin_flamesAI : public ScriptedAI
            {
                npc_ragin_flamesAI(Creature* creature) : ScriptedAI(creature)
                {
                    Initialize();
                    instance = creature->GetInstanceScript();
                }

                void Initialize()
                {
                    inferno_Timer = 10000;
                    flame_timer = 500;
                    Check_Timer = 2000;
                    onlyonce = false;
                }

                InstanceScript* instance;

                uint32 inferno_Timer;
                uint32 flame_timer;
                uint32 Check_Timer;

                bool onlyonce;

                void Reset() override
                {
                    Initialize();
                    me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
                    me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
                    me->SetSpeedRate(MOVE_RUN, DUNGEON_MODE(0.5f, 0.7f));
                }

                void JustEngagedWith(Unit* /*who*/) override
                {
                }

                void UpdateAI(uint32 diff) override
                {
                    //Check_Timer
                    if (Check_Timer <= diff)
                    {
                        if (instance->GetBossState(DATA_NETHERMANCER_SEPRETHREA) != IN_PROGRESS)
                        {
                            //remove
                            me->DespawnOrUnsummon();
                            return;
                        }
                        Check_Timer = 1000;
                    } else Check_Timer -= diff;

                    if (!UpdateVictim())
                        return;

                    if (!onlyonce)
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                            me->GetMotionMaster()->MoveChase(target);
                        onlyonce = true;
                    }

                    if (inferno_Timer <= diff)
                    {
                        DoCastVictim(SPELL_INFERNO);
                        inferno_Timer = 10000;
                    } else inferno_Timer -= diff;

                    if (flame_timer <= diff)
                    {
                        DoCast(me, SPELL_FIRE_TAIL);
                        flame_timer = 500;
                    } else flame_timer -=diff;

                    DoMeleeAttackIfReady();
                }

            };
            CreatureAI* GetAI(Creature* creature) const override
            {
                return GetMechanarAI<npc_ragin_flamesAI>(creature);
            }
};

void AddSC_boss_nethermancer_sepethrea()
{
    new boss_nethermancer_sepethrea();
    new npc_ragin_flames();
}
