/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Jeklik
SD%Complete: 85
SDComment: Problem in finding the right flying batriders for spawning and making them fly.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"

enum Jeklik
{
    SAY_AGGRO                   = 0,
    SAY_RAIN_FIRE               = 1,
    SAY_DEATH                   = 2,

    SPELL_CHARGE                = 22911,
    SPELL_SONICBURST            = 23918,
    SPELL_SCREECH               = 6605,
    SPELL_SHADOW_WORD_PAIN      = 23952,
    SPELL_MIND_FLAY             = 23953,
    SPELL_CHAIN_MIND_FLAY       = 26044, //Right ID unknown. So disabled
    SPELL_GREATERHEAL           = 23954,
    SPELL_BAT_FORM              = 23966,

    // Batriders Spell
    SPELL_BOMB                  = 40332 //Wrong ID but Magmadars bomb is not working...
};

class boss_jeklik : public CreatureScript
{
    public:

        boss_jeklik()
            : CreatureScript("boss_jeklik")
        {
        }

        struct boss_jeklikAI : public ScriptedAI
        {
            boss_jeklikAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 Charge_Timer;
            uint32 SonicBurst_Timer;
            uint32 Screech_Timer;
            uint32 SpawnBats_Timer;
            uint32 ShadowWordPain_Timer;
            uint32 MindFlay_Timer;
            uint32 ChainMindFlay_Timer;
            uint32 GreaterHeal_Timer;
            uint32 SpawnFlyingBats_Timer;

            bool PhaseTwo;

            void Reset()
            {
                Charge_Timer = 20000;
                SonicBurst_Timer = 8000;
                Screech_Timer = 13000;
                SpawnBats_Timer = 60000;
                ShadowWordPain_Timer = 6000;
                MindFlay_Timer = 11000;
                ChainMindFlay_Timer = 26000;
                GreaterHeal_Timer = 50000;
                SpawnFlyingBats_Timer = 10000;

                PhaseTwo = false;
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);
                DoCast(me, SPELL_BAT_FORM);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);

                if (instance)
                    instance->SetData(DATA_JEKLIK, DONE);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->getVictim() && me->isAlive())
                {
                    if (HealthAbovePct(50))
                    {
                        if (Charge_Timer <= diff)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                DoCast(target, SPELL_CHARGE);
                                AttackStart(target);
                            }

                            Charge_Timer = urand(15000, 30000);
                        } else Charge_Timer -= diff;

                        if (SonicBurst_Timer <= diff)
                        {
                            DoCast(me->getVictim(), SPELL_SONICBURST);
                            SonicBurst_Timer = urand(8000, 13000);
                        } else SonicBurst_Timer -= diff;

                        if (Screech_Timer <= diff)
                        {
                            DoCast(me->getVictim(), SPELL_SCREECH);
                            Screech_Timer = urand(18000, 26000);
                        } else Screech_Timer -= diff;

                        if (SpawnBats_Timer <= diff)
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);

                            Creature* Bat = NULL;
                            Bat = me->SummonCreature(11368, -12291.6220f, -1380.2640f, 144.8304f, 5.483f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                            if (target && Bat) Bat ->AI()->AttackStart(target);

                            Bat = me->SummonCreature(11368, -12289.6220f, -1380.2640f, 144.8304f, 5.483f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                            if (target && Bat) Bat ->AI()->AttackStart(target);

                            Bat = me->SummonCreature(11368, -12293.6220f, -1380.2640f, 144.8304f, 5.483f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                            if (target && Bat) Bat ->AI()->AttackStart(target);

                            Bat = me->SummonCreature(11368, -12291.6220f, -1380.2640f, 144.8304f, 5.483f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                            if (target && Bat) Bat ->AI()->AttackStart(target);

                            Bat = me->SummonCreature(11368, -12289.6220f, -1380.2640f, 144.8304f, 5.483f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                            if (target && Bat) Bat ->AI()->AttackStart(target);
                            Bat = me->SummonCreature(11368, -12293.6220f, -1380.2640f, 144.8304f, 5.483f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                            if (target && Bat) Bat ->AI()->AttackStart(target);

                            SpawnBats_Timer = 60000;
                        } else SpawnBats_Timer -= diff;
                    }
                    else
                    {
                        if (PhaseTwo)
                        {
                            if (PhaseTwo && ShadowWordPain_Timer <= diff)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                {
                                    DoCast(target, SPELL_SHADOW_WORD_PAIN);
                                    ShadowWordPain_Timer = urand(12000, 18000);
                                }
                            }ShadowWordPain_Timer -=diff;

                            if (MindFlay_Timer <= diff)
                            {
                                DoCast(me->getVictim(), SPELL_MIND_FLAY);
                                MindFlay_Timer = 16000;
                            }MindFlay_Timer -=diff;

                            if (ChainMindFlay_Timer <= diff)
                            {
                                me->InterruptNonMeleeSpells(false);
                                DoCast(me->getVictim(), SPELL_CHAIN_MIND_FLAY);
                                ChainMindFlay_Timer = urand(15000, 30000);
                            }ChainMindFlay_Timer -=diff;

                            if (GreaterHeal_Timer <= diff)
                            {
                                me->InterruptNonMeleeSpells(false);
                                DoCast(me, SPELL_GREATERHEAL);
                                GreaterHeal_Timer = urand(25000, 35000);
                            }GreaterHeal_Timer -=diff;

                            if (SpawnFlyingBats_Timer <= diff)
                            {
                                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                if (!target)
                                    return;

                                Creature* FlyingBat = me->SummonCreature(14965, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ()+15, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                                if (FlyingBat)
                                    FlyingBat->AI()->AttackStart(target);

                                SpawnFlyingBats_Timer = urand(10000, 15000);
                            } else SpawnFlyingBats_Timer -=diff;
                        }
                        else
                        {
                            me->SetDisplayId(15219);
                            DoResetThreat();
                            PhaseTwo = true;
                        }
                    }

                    DoMeleeAttackIfReady();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_jeklikAI(creature);
        }
};

//Flying Bat
class mob_batrider : public CreatureScript
{
    public:

        mob_batrider()
            : CreatureScript("mob_batrider")
        {
        }

        struct mob_batriderAI : public ScriptedAI
        {
            mob_batriderAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 Bomb_Timer;
            uint32 Check_Timer;

            void Reset()
            {
                Bomb_Timer = 2000;
                Check_Timer = 1000;

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void EnterCombat(Unit* /*who*/) {}

            void UpdateAI (const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                //Bomb_Timer
                if (Bomb_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        DoCast(target, SPELL_BOMB);
                        Bomb_Timer = 5000;
                    }
                } else Bomb_Timer -= diff;

                //Check_Timer
                if (Check_Timer <= diff)
                {
                    if (instance)
                    {
                        if (instance->GetData(DATA_JEKLIK) == DONE)
                        {
                            me->setDeathState(JUST_DIED);
                            me->RemoveCorpse();
                            return;
                        }
                    }

                    Check_Timer = 1000;
                } else Check_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_batriderAI(creature);
        }
};

void AddSC_boss_jeklik()
{
    new boss_jeklik();
    new mob_batrider();
}

