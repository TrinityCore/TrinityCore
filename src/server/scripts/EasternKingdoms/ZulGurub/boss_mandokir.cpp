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
SDName: Boss_Mandokir
SD%Complete: 90
SDComment: Ohgan function needs improvements.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"

enum Mandokir
{
    SAY_AGGRO               = 0,
    SAY_DING_KILL           = 1,
    SAY_WATCH               = 2,
    SAY_WATCH_WHISPER       = 3,                    //is this text for real? easter egg?
    SAY_GRATS_JINDO         = 0,

    SPELL_CHARGE            = 24408,
    SPELL_CLEAVE            = 7160,
    SPELL_FEAR              = 29321,
    SPELL_WHIRLWIND         = 15589,
    SPELL_MORTAL_STRIKE     = 16856,
    SPELL_ENRAGE            = 24318,
    SPELL_WATCH             = 24314,
    SPELL_LEVEL_UP          = 24312,

//Ohgans Spells
    SPELL_SUNDERARMOR       = 24317,

    NPC_SPEAKER             = 11391
};

class boss_mandokir : public CreatureScript
{
    public:

        boss_mandokir()
            : CreatureScript("boss_mandokir")
        {
        }

        struct boss_mandokirAI : public ScriptedAI
        {
            boss_mandokirAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            uint32 KillCount;
            uint32 Watch_Timer;
            uint32 TargetInRange;
            uint32 Cleave_Timer;
            uint32 Whirlwind_Timer;
            uint32 Fear_Timer;
            uint32 MortalStrike_Timer;
            uint32 Check_Timer;
            float targetX;
            float targetY;
            float targetZ;

            InstanceScript* instance;

            bool endWatch;
            bool someWatched;
            bool RaptorDead;
            bool CombatStart;
            bool SpeakerDead;

            uint64 WatchTarget;

            void Reset()
            {
                KillCount = 0;
                Watch_Timer = 33000;
                Cleave_Timer = 7000;
                Whirlwind_Timer = 20000;
                Fear_Timer = 1000;
                MortalStrike_Timer = 1000;
                Check_Timer = 1000;

                targetX = 0.0f;
                targetY = 0.0f;
                targetZ = 0.0f;
                TargetInRange = 0;

                WatchTarget = 0;

                someWatched = false;
                endWatch = false;
                RaptorDead = false;
                CombatStart = false;
                SpeakerDead = false;

                DoCast(me, 23243);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                {
                    ++KillCount;

                    if (KillCount == 3)
                    {
                        Talk(SAY_DING_KILL);

                        if (instance)
                        {
                            uint64 JindoGUID = instance->GetData64(DATA_JINDO);
                            if (JindoGUID)
                            {
                                if (Creature* jTemp = Creature::GetCreature(*me, JindoGUID))
                                {
                                    if (jTemp->isAlive())
                                        jTemp->AI()->Talk(SAY_GRATS_JINDO);
                                }
                            }
                        }
                        DoCast(me, SPELL_LEVEL_UP, true);
                        KillCount = 0;
                    }
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!SpeakerDead)
                {
                    if (!me->FindNearestCreature(NPC_SPEAKER, 100.0f, true))
                    {
                        me->GetMotionMaster()->MovePoint(0, -12196.3f, -1948.37f, 130.36f);
                        SpeakerDead = true;
                    }
                }

                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE && SpeakerDead)
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);

                if (!UpdateVictim())
                    return;

                if (me->getVictim() && me->isAlive())
                {
                    if (!CombatStart)
                    {
                        //At combat Start Mandokir is mounted so we must unmount it first
                        me->Dismount();

                        //And summon his raptor
                        me->SummonCreature(14988, me->getVictim()->GetPositionX(), me->getVictim()->GetPositionY(), me->getVictim()->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 35000);
                        CombatStart = true;
                    }

                    if (Watch_Timer <= diff)                         //Every 20 Sec Mandokir will check this
                    {
                        if (WatchTarget)                             //If someone is watched and If the Position of the watched target is different from the one stored, or are attacking, mandokir will charge him
                        {
                            Unit* unit = Unit::GetUnit(*me, WatchTarget);

                            if (unit && (
                                targetX != unit->GetPositionX() ||
                                targetY != unit->GetPositionY() ||
                                targetZ != unit->GetPositionZ() ||
                                unit->isInCombat()))
                            {
                                if (me->IsWithinMeleeRange(unit))
                                {
                                    DoCast(unit, 24316);
                                }
                                else
                                {
                                    DoCast(unit, SPELL_CHARGE);
                                    //me->SendMonsterMove(unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ(), 0, true, 1);
                                    AttackStart(unit);
                                }
                            }
                        }
                        someWatched = false;
                        Watch_Timer = 20000;
                    } else Watch_Timer -= diff;

                    if ((Watch_Timer < 8000) && !someWatched)       //8 sec(cast time + expire time) before the check for the watch effect mandokir will cast watch debuff on a random target
                    {
                        if (Unit* p = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            Talk(SAY_WATCH, p->GetGUID());
                            DoCast(p, SPELL_WATCH);
                            WatchTarget = p->GetGUID();
                            someWatched = true;
                            endWatch = true;
                        }
                    }

                    if ((Watch_Timer < 1000) && endWatch)           //1 sec before the debuf expire, store the target position
                    {
                        Unit* unit = Unit::GetUnit(*me, WatchTarget);
                        if (unit)
                        {
                            targetX = unit->GetPositionX();
                            targetY = unit->GetPositionY();
                            targetZ = unit->GetPositionZ();
                        }
                        endWatch = false;
                    }

                    if (!someWatched)
                    {
                        //Cleave
                        if (Cleave_Timer <= diff)
                        {
                            DoCast(me->getVictim(), SPELL_CLEAVE);
                            Cleave_Timer = 7000;
                        } else Cleave_Timer -= diff;

                        //Whirlwind
                        if (Whirlwind_Timer <= diff)
                        {
                            DoCast(me, SPELL_WHIRLWIND);
                            Whirlwind_Timer = 18000;
                        } else Whirlwind_Timer -= diff;

                        //If more then 3 targets in melee range mandokir will cast fear
                        if (Fear_Timer <= diff)
                        {
                            TargetInRange = 0;

                            std::list<HostileReference*>::const_iterator i = me->getThreatManager().getThreatList().begin();
                            for (; i != me->getThreatManager().getThreatList().end(); ++i)
                            {
                                Unit* unit = Unit::GetUnit(*me, (*i)->getUnitGuid());
                                if (unit && me->IsWithinMeleeRange(unit))
                                    ++TargetInRange;
                            }

                            if (TargetInRange > 3)
                                DoCast(me->getVictim(), SPELL_FEAR);

                            Fear_Timer = 4000;
                        } else Fear_Timer -=diff;

                        //Mortal Strike if target below 50% hp
                        if (me->getVictim() && me->getVictim()->HealthBelowPct(50))
                        {
                            if (MortalStrike_Timer <= diff)
                            {
                                DoCast(me->getVictim(), SPELL_MORTAL_STRIKE);
                                MortalStrike_Timer = 15000;
                            } else MortalStrike_Timer -= diff;
                        }
                    }
                    //Checking if Ohgan is dead. If yes Mandokir will enrage.
                    if (Check_Timer <= diff)
                    {
                        if (instance)
                        {
                            if (instance->GetData(DATA_OHGAN) == DONE)
                            {
                                if (!RaptorDead)
                                {
                                    DoCast(me, SPELL_ENRAGE);
                                    RaptorDead = true;
                                }
                            }
                        }

                        Check_Timer = 1000;
                    } else Check_Timer -= diff;

                    DoMeleeAttackIfReady();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_mandokirAI(creature);
        }
};

//Ohgan
class mob_ohgan : public CreatureScript
{
    public:

        mob_ohgan()
            : CreatureScript("mob_ohgan")
        {
        }

        struct mob_ohganAI : public ScriptedAI
        {
            mob_ohganAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            uint32 SunderArmor_Timer;
            InstanceScript* instance;

            void Reset()
            {
                SunderArmor_Timer = 5000;
            }

            void EnterCombat(Unit* /*who*/) {}

            void JustDied(Unit* /*killer*/)
            {
                if (instance)
                    instance->SetData(DATA_OHGAN, DONE);
            }

            void UpdateAI (const uint32 diff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //SunderArmor_Timer
                if (SunderArmor_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SUNDERARMOR);
                    SunderArmor_Timer = urand(10000, 15000);
                } else SunderArmor_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ohganAI(creature);
        }
};

void AddSC_boss_mandokir()
{
    new boss_mandokir();
    new mob_ohgan();
}

