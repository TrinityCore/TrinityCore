/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss Pathaleon the Calculator
SD%Complete: 50
SDComment: Event missing. Script for himself 99% blizzlike.
SDCategory: Tempest Keep, The Mechanar
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mechanar.h"

enum Says
{
    SAY_AGGRO                      = 0,
    SAY_DOMINATION                 = 1,
    SAY_SUMMON                     = 2,
    SAY_ENRAGE                     = 3,
    SAY_SLAY                       = 4,
    SAY_DEATH                      = 5
};

enum Spells
{
    SPELL_MANA_TAP                 = 36021,
    SPELL_ARCANE_TORRENT           = 36022,
    SPELL_DOMINATION               = 35280,
    H_SPELL_ARCANE_EXPLOSION       = 15453,
    SPELL_FRENZY                   = 36992,
    SPELL_SUMMON_NETHER_WRAITH_1   = 35285, // Not scripted
    SPELL_SUMMON_NETHER_WRAITH_2   = 35286, // Not scripted
    SPELL_SUMMON_NETHER_WRAITH_3   = 35287, // Not scripted
    SPELL_SUMMON_NETHER_WRAITH_4   = 35288, // Not scripted
    SPELL_DETONATION               = 35058, // Used by Nether Wraith
    SPELL_ARCANE_MISSILES          = 35034  // Used by Nether Wraith
};

enum Events
{
    EVENT_SUMMON                   = 1,
    EVENT_MANA_TAP                 = 2,
    EVENT_ARCANE_TORRENT           = 3,
    EVENT_DOMINATION               = 4,
    EVENT_ARCANE_EXPLOSION         = 5
};

enum Creatures
{
    NPC_NETHER_WRAITH               = 21062
};

class boss_pathaleon_the_calculator : public CreatureScript
{
    public:
        boss_pathaleon_the_calculator(): CreatureScript("boss_pathaleon_the_calculator") { }

        struct boss_pathaleon_the_calculatorAI : public BossAI
        {
            boss_pathaleon_the_calculatorAI(Creature* creature) : BossAI(creature, DATA_PATHALEON_THE_CALCULATOR) { }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_SUMMON, 30000);
                events.ScheduleEvent(EVENT_MANA_TAP, urand(12000, 20000));
                events.ScheduleEvent(EVENT_ARCANE_TORRENT, urand(16000, 25000));
                events.ScheduleEvent(EVENT_DOMINATION, urand(25000, 40000));
                events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, urand(8000, 13000));
                Talk(SAY_AGGRO);
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

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(20, damage) && !me->HasAura(SPELL_FRENZY))
                {
                    DoCast(me, SPELL_FRENZY);
                    Talk(SAY_ENRAGE);
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
                        case EVENT_SUMMON:
                            for (uint8 i = 0; i < 3; ++i)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                {
                                    if (Creature* Wraith = me->SummonCreature(NPC_NETHER_WRAITH, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000))
                                        Wraith->AI()->AttackStart(target);
                                }
                            }
                            Talk(SAY_SUMMON);
                            events.ScheduleEvent(EVENT_SUMMON, urand(30000, 45000));
                            break;
                        case EVENT_MANA_TAP:
                            DoCastVictim(SPELL_MANA_TAP, true);
                            events.ScheduleEvent(EVENT_MANA_TAP, urand(14000, 22000));
                            break;
                        case EVENT_ARCANE_TORRENT:
                            DoCastVictim(SPELL_ARCANE_TORRENT, true);
                            events.ScheduleEvent(EVENT_ARCANE_TORRENT, urand(12000, 18000));
                            break;
                        case EVENT_DOMINATION:
                            Talk(SAY_DOMINATION);
                            DoCastVictim(SPELL_DOMINATION, true);
                            events.ScheduleEvent(EVENT_DOMINATION, urand(25000, 30000));
                            break;
                        case EVENT_ARCANE_EXPLOSION: // Heroic only
                            DoCastVictim(H_SPELL_ARCANE_EXPLOSION, true);
                            events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, urand(10000, 14000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_pathaleon_the_calculatorAI(creature);
        }
};

class npc_nether_wraith : public CreatureScript
{
    public:

        npc_nether_wraith() : CreatureScript("npc_nether_wraith") { }

        struct npc_nether_wraithAI : public ScriptedAI
        {
            npc_nether_wraithAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                ArcaneMissiles_Timer = urand(1000, 4000);
                Detonation_Timer = 20000;
                Die_Timer = 2200;
                Detonation = false;
            }

            uint32 ArcaneMissiles_Timer;
            uint32 Detonation_Timer;
            uint32 Die_Timer;
            bool Detonation;

            void Reset() override
            {
                Initialize();
            }

            void EnterCombat(Unit* /*who*/) override { }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (ArcaneMissiles_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(target, SPELL_ARCANE_MISSILES);
                    else
                        DoCastVictim(SPELL_ARCANE_MISSILES);
                    ArcaneMissiles_Timer = urand(5000, 10000);
                }
                else
                    ArcaneMissiles_Timer -=diff;

                if (!Detonation)
                {
                    if (Detonation_Timer <= diff)
                    {
                        DoCast(me, SPELL_DETONATION);
                        Detonation = true;
                    }
                    else
                        Detonation_Timer -= diff;
                }

                if (Detonation)
                {
                    if (Die_Timer <= diff)
                    {
                        me->setDeathState(JUST_DIED);
                        me->RemoveCorpse();
                    }
                    else
                        Die_Timer -= diff;
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_nether_wraithAI(creature);
        }
};

void AddSC_boss_pathaleon_the_calculator()
{
    new boss_pathaleon_the_calculator();
    new npc_nether_wraith();
}

