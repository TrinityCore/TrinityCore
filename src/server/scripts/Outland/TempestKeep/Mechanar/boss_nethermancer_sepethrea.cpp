/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedCreature.h"
#include "mechanar.h"

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
    public: boss_nethermancer_sepethrea(): CreatureScript("boss_nethermancer_sepethrea") {}

        struct boss_nethermancer_sepethreaAI : public BossAI
        {
            boss_nethermancer_sepethreaAI(Creature* creature) : BossAI(creature, DATA_NETHERMANCER_SEPRETHREA) {}

            void EnterCombat(Unit* who)
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_FROST_ATTACK, urand(7000, 10000));
                events.ScheduleEvent(EVENT_ARCANE_BLAST, urand(12000, 18000));
                events.ScheduleEvent(EVENT_DRAGONS_BREATH, urand(18000, 22000));
                events.ScheduleEvent(EVENT_KNOCKBACK, urand(22000, 28000));
                events.ScheduleEvent(EVENT_SOLARBURN, 30000);
                Talk(SAY_AGGRO);
                DoCast(who, SPELL_SUMMON_RAGIN_FLAMES);
                Talk(SAY_SUMMON);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void UpdateAI(uint32 diff)
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
                            events.ScheduleEvent(EVENT_FROST_ATTACK, urand(7000, 10000));
                            break;
                        case EVENT_ARCANE_BLAST:
                            DoCastVictim(SPELL_ARCANE_BLAST, true);
                            events.ScheduleEvent(EVENT_ARCANE_BLAST, 15000);
                            break;
                        case EVENT_DRAGONS_BREATH:
                            DoCastVictim(SPELL_DRAGONS_BREATH, true);
                            events.ScheduleEvent(EVENT_DRAGONS_BREATH, urand(12000, 22000));
                            if (roll_chance_i(50))
                                Talk(SAY_DRAGONS_BREATH);
                            break;
                        case EVENT_KNOCKBACK:
                            DoCastVictim(SPELL_KNOCKBACK, true);
                            events.ScheduleEvent(EVENT_KNOCKBACK, urand(15000, 25000));
                            break;
                        case EVENT_SOLARBURN:
                            DoCastVictim(SPELL_SOLARBURN, true);
                            events.ScheduleEvent(EVENT_SOLARBURN, 30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_nethermancer_sepethreaAI(creature);
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
                    instance = creature->GetInstanceScript();
                }

                InstanceScript* instance;

                uint32 inferno_Timer;
                uint32 flame_timer;
                uint32 Check_Timer;

                bool onlyonce;

                void Reset()
                {
                    inferno_Timer = 10000;
                    flame_timer = 500;
                    Check_Timer = 2000;
                    onlyonce = false;
                    me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
                    me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
                    me->SetSpeed(MOVE_RUN, DUNGEON_MODE(0.5f, 0.7f));
                }

                void EnterCombat(Unit* /*who*/)
                {
                }

                void UpdateAI(uint32 diff)
                {
                    //Check_Timer
                    if (Check_Timer <= diff)
                    {
                        if (instance)
                        {
                            if (instance->GetData(DATA_NETHERMANCER_SEPRETHREA) != IN_PROGRESS)
                            {
                                //remove
                                me->setDeathState(JUST_DIED);
                                me->RemoveCorpse();
                            }
                        }
                        Check_Timer = 1000;
                    } else Check_Timer -= diff;

                    if (!UpdateVictim())
                        return;

                    if (!onlyonce)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            me->GetMotionMaster()->MoveChase(target);
                        onlyonce = true;
                    }

                    if (inferno_Timer <= diff)
                    {
                        DoCastVictim(SPELL_INFERNO);
                        me->TauntApply(me->GetVictim());
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
            CreatureAI* GetAI(Creature* creature) const
            {
                return new npc_ragin_flamesAI(creature);
            }
};

void AddSC_boss_nethermancer_sepethrea()
{
    new boss_nethermancer_sepethrea();
    new npc_ragin_flames();
}
