/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Marli
SD%Complete: 80
SDComment: Charging healers and casters not working. Perhaps wrong Spell Timers.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"

enum Says
{
    SAY_AGGRO                 = 0,
    SAY_TRANSFORM             = 1,
    SAY_SPIDER_SPAWN          = 2,
    SAY_DEATH                 = 3
};

enum Spells
{
    SPELL_CHARGE              = 22911,
    SPELL_ASPECT_OF_MARLI     = 24686, // A stun spell
    SPELL_ENVOLWINGWEB        = 24110,
    SPELL_POISON_VOLLEY       = 24099,
    SPELL_SPIDER_FORM         = 24084,
    // The Spider Spell
    SPELL_LEVELUP             = 24312  // Not right Spell.
};

enum Events
{
    EVENT_SPAWN_START_SPIDERS = 1, // Phase 1
    EVENT_POISON_VOLLEY       = 2, // Phase All
    EVENT_SPAWN_SPIDER        = 3, // Phase All
    EVENT_CHARGE_PLAYER       = 4, // Phase 3
    EVENT_ASPECT_OF_MARLI     = 5, // Phase 2
    EVENT_TRANSFORM           = 6, // Phase 2
    EVENT_TRANSFORM_BACK      = 7  // Phase 3
};

enum Phases
{
    PHASE_ONE                 = 1,
    PHASE_TWO                 = 2,
    PHASE_THREE               = 3
};

enum Misc
{
    NPC_SPIDER                = 15041
};

class boss_marli : public CreatureScript
{
    public: boss_marli() : CreatureScript("boss_marli") { }

        struct boss_marliAI : public BossAI
        {
            boss_marliAI(Creature* creature) : BossAI(creature, DATA_MARLI) { }

            void Reset() override
            {
                if (events.IsInPhase(PHASE_THREE))
                    me->HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, 35.0f, false); // hack
                _Reset();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_SPAWN_START_SPIDERS, 1000, 0, PHASE_ONE);
                Talk(SAY_AGGRO);
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
                        case EVENT_SPAWN_START_SPIDERS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                Talk(SAY_SPIDER_SPAWN);
                                for (uint8 i = 0; i < 4; ++i)
                                    if (Creature* spider = me->SummonCreature(NPC_SPIDER, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000))
                                        spider->AI()->AttackStart(target);
                            }
                            events.ScheduleEvent(EVENT_ASPECT_OF_MARLI, 12000, 0, PHASE_TWO);
                            events.ScheduleEvent(EVENT_TRANSFORM, 45000, 0, PHASE_TWO);
                            events.ScheduleEvent(EVENT_POISON_VOLLEY, 15000);
                            events.ScheduleEvent(EVENT_SPAWN_SPIDER, 30000);
                            events.ScheduleEvent(EVENT_TRANSFORM, 45000, 0, PHASE_TWO);
                            events.SetPhase(PHASE_TWO);
                            break;
                        case EVENT_POISON_VOLLEY:
                            DoCastVictim(SPELL_POISON_VOLLEY, true);
                            events.ScheduleEvent(EVENT_POISON_VOLLEY, urand(10000, 20000));
                            break;
                        case EVENT_ASPECT_OF_MARLI:
                            DoCastVictim(SPELL_ASPECT_OF_MARLI, true);
                            events.ScheduleEvent(EVENT_ASPECT_OF_MARLI, urand(13000, 18000), 0, PHASE_TWO);
                            break;
                        case EVENT_SPAWN_SPIDER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                if (Creature* spider = me->SummonCreature(NPC_SPIDER, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000))
                                    spider->AI()->AttackStart(target);
                            events.ScheduleEvent(EVENT_SPAWN_SPIDER, urand(12000, 17000));
                            break;
                        case EVENT_TRANSFORM:
                        {
                            Talk(SAY_TRANSFORM);
                            DoCast(me, SPELL_SPIDER_FORM); // SPELL_AURA_TRANSFORM
                            /*
                            CreatureTemplate const* cinfo = me->GetCreatureTemplate();
                            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 35)));
                            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 35)));
                            me->UpdateDamagePhysical(BASE_ATTACK);
                            */
                            me->HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, 35.0f, true); // hack
                            DoCastVictim(SPELL_ENVOLWINGWEB);
                            if (DoGetThreat(me->GetVictim()))
                                DoModifyThreatPercent(me->GetVictim(), -100);
                            events.ScheduleEvent(EVENT_CHARGE_PLAYER, 1500, 0, PHASE_THREE);
                            events.ScheduleEvent(EVENT_TRANSFORM_BACK, 25000, 0, PHASE_THREE);
                            events.SetPhase(PHASE_THREE);
                            break;
                        }
                        case EVENT_CHARGE_PLAYER:
                        {
                            Unit* target = NULL;
                            int i = 0;
                            while (i++ < 3) // max 3 tries to get a random target with power_mana
                            {
                                target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true);  // not aggro leader
                                if (target && target->getPowerType() == POWER_MANA)
                                    break;
                            }
                            if (target)
                            {
                                DoCast(target, SPELL_CHARGE);
                                AttackStart(target);
                            }
                            events.ScheduleEvent(EVENT_CHARGE_PLAYER, 8000, 0, PHASE_THREE);
                            break;
                        }
                        case EVENT_TRANSFORM_BACK:
                        {
                            me->RemoveAura(SPELL_SPIDER_FORM);
                            /*
                            CreatureTemplate const* cinfo = me->GetCreatureTemplate();
                            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 1)));
                            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 1)));
                            me->UpdateDamagePhysical(BASE_ATTACK);
                            */
                            me->HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, 35.0f, false); // hack
                            events.ScheduleEvent(EVENT_ASPECT_OF_MARLI, 12000, 0, PHASE_TWO);
                            events.ScheduleEvent(EVENT_TRANSFORM, 45000, 0, PHASE_TWO);
                            events.ScheduleEvent(EVENT_POISON_VOLLEY, 15000);
                            events.ScheduleEvent(EVENT_SPAWN_SPIDER, 30000);
                            events.ScheduleEvent(EVENT_TRANSFORM, urand(35000, 60000), 0, PHASE_TWO);
                            events.SetPhase(PHASE_TWO);
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_marliAI(creature);
        }
};

// Spawn of Marli
class npc_spawn_of_marli : public CreatureScript
{
    public: npc_spawn_of_marli() : CreatureScript("npc_spawn_of_marli") { }

        struct npc_spawn_of_marliAI : public ScriptedAI
        {
            npc_spawn_of_marliAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                LevelUp_Timer = 3000;
            }

            uint32 LevelUp_Timer;

            void Reset() override
            {
                Initialize();
            }

            void EnterCombat(Unit* /*who*/) override { }

            void UpdateAI(uint32 diff) override
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //LevelUp_Timer
                if (LevelUp_Timer <= diff)
                {
                    DoCast(me, SPELL_LEVELUP);
                    LevelUp_Timer = 3000;
                } else LevelUp_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_spawn_of_marliAI(creature);
        }
};

void AddSC_boss_marli()
{
    new boss_marli();
    new npc_spawn_of_marli();
}
