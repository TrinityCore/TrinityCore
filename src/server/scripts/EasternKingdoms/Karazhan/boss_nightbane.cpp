/* Copyright (C) 2006 - 2010 Trinity <http://www.trinitycore.org/>
 * Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Nightbane
SD%Complete: 80
SDComment: SDComment: Timers may incorrect
SDCategory: Karazhan
EndScriptData */

#include "ScriptPCH.h"
#include "karazhan.h"

//phase 1
#define SPELL_BELLOWING_ROAR        39427
#define SPELL_CHARRED_EARTH         30129
#define SPELL_DISTRACTING_ASH       30130
#define SPELL_SMOLDERING_BREATH     30210
#define SPELL_TAIL_SWEEP            25653
//phase 2
#define SPELL_RAIN_OF_BONES         37098
#define SPELL_SMOKING_BLAST         37057
#define SPELL_FIREBALL_BARRAGE      30282
#define SPELL_SEARING_CINDERS       30127
#define SPELL_SUMMON_SKELETON       30170

#define EMOTE_SUMMON                "An ancient being awakens in the distance..."
#define YELL_AGGRO                  "What fools! I shall bring a quick end to your suffering!"
#define YELL_FLY_PHASE              "Miserable vermin. I shall exterminate you from the air!"
#define YELL_LAND_PHASE_1           "Enough! I shall land and crush you myself!"
#define YELL_LAND_PHASE_2           "Insects! Let me show you my strength up close!"
#define EMOTE_BREATH                "takes a deep breath."

float IntroWay[8][3] =
{
    {-11053.37,-1794.48,149},
    {-11141.07,-1841.40,125},
    {-11187.28,-1890.23,125},
    {-11189.20,-1931.25,125},
    {-11153.76,-1948.93,125},
    {-11128.73,-1929.75,125},
    {-11140   , -1915  ,122},
    {-11163   , -1903  ,91.473}
};

struct boss_nightbaneAI : public ScriptedAI
{
    boss_nightbaneAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        Intro = true;
    }

    ScriptedInstance* pInstance;

    uint32 Phase;

    bool RainBones;
    bool Skeletons;

    uint32 BellowingRoarTimer;
    uint32 CharredEarthTimer;
    uint32 DistractingAshTimer;
    uint32 SmolderingBreathTimer;
    uint32 TailSweepTimer;
    uint32 RainofBonesTimer;
    uint32 SmokingBlastTimer;
    uint32 FireballBarrageTimer;
    uint32 SearingCindersTimer;

    uint32 FlyCount;
    uint32 FlyTimer;

    bool Intro;
    bool Flying;
    bool Movement;

    uint32 WaitTimer;
    uint32 MovePhase;

    void Reset()
    {
        BellowingRoarTimer = 30000;
        CharredEarthTimer = 15000;
        DistractingAshTimer = 20000;
        SmolderingBreathTimer = 10000;
        TailSweepTimer = 12000;
        RainofBonesTimer = 10000;
        SmokingBlastTimer = 20000;
        FireballBarrageTimer = 13000;
        SearingCindersTimer = 14000;
        WaitTimer = 1000;

        Phase =1;
        FlyCount = 0;
        MovePhase = 0;

        me->SetSpeed(MOVE_RUN, 2.0f);
        me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
        me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        me->setActive(true);

        if (pInstance)
        {
            if (pInstance->GetData(TYPE_NIGHTBANE) == DONE || pInstance->GetData(TYPE_NIGHTBANE) == IN_PROGRESS)
                me->DisappearAndDie();
            else
                pInstance->SetData(TYPE_NIGHTBANE, NOT_STARTED);
        }

        HandleTerraceDoors(true);

        Flying = false;
        Movement = false;

        if (!Intro)
        {
            me->SetHomePosition(IntroWay[7][0],IntroWay[7][1],IntroWay[7][2],0);
            me->GetMotionMaster()->MoveTargetedHome();
        }
    }

    void HandleTerraceDoors(bool open)
    {
        if (pInstance)
        {
            pInstance->HandleGameObject(pInstance->GetData64(DATA_MASTERS_TERRACE_DOOR_1), open);
            pInstance->HandleGameObject(pInstance->GetData64(DATA_MASTERS_TERRACE_DOOR_2), open);
        }
    }

    void EnterCombat(Unit * /*who*/)
    {
        if (pInstance)
            pInstance->SetData(TYPE_NIGHTBANE, IN_PROGRESS);

        HandleTerraceDoors(false);
        me->MonsterYell(YELL_AGGRO, LANG_UNIVERSAL, NULL);
    }

    void AttackStart(Unit* who)
    {
        if (!Intro && !Flying)
            ScriptedAI::AttackStart(who);
    }

    void JustDied(Unit* /*killer*/)
    {
        if (pInstance)
            pInstance->SetData(TYPE_NIGHTBANE, DONE);

        HandleTerraceDoors(true);
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!Intro && !Flying)
            ScriptedAI::MoveInLineOfSight(who);
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
                return;

        if (Intro)
        {
            if (id >= 8)
            {
                Intro = false;
                me->SetHomePosition(IntroWay[7][0],IntroWay[7][1],IntroWay[7][2],0);
                return;
            }

            WaitTimer = 1;
        }

        if (Flying)
        {
            if (id == 0)
            {
                me->MonsterTextEmote(EMOTE_BREATH, 0, true);
                Flying = false;
                Phase = 2;
                return;
            }

            if (id == 3)
            {
                MovePhase = 4;
                WaitTimer = 1;
                return;
            }

            if (id == 8)
            {
                Flying = false;
                Phase = 1;
                Movement = true;
                return;
            }

            WaitTimer = 1;
        }
    }

    void JustSummoned(Creature *summoned)
    {
        summoned->AI()->AttackStart(me->getVictim());
    }

    void TakeOff()
    {
        me->MonsterYell(YELL_FLY_PHASE, LANG_UNIVERSAL, NULL);

        me->InterruptSpell(CURRENT_GENERIC_SPELL);
        me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
        me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
        (*me).GetMotionMaster()->Clear(false);
        (*me).GetMotionMaster()->MovePoint(0,IntroWay[2][0],IntroWay[2][1],IntroWay[2][2]);

        Flying = true;

        FlyTimer = urand(45000,60000); //timer wrong between 45 and 60 seconds
        ++FlyCount;

        RainofBonesTimer = 5000; //timer wrong (maybe)
        RainBones = false;
        Skeletons = false;
     }

    void UpdateAI(const uint32 diff)
    {
        /* The timer for this was never setup apparently, not sure if the code works properly:
        if (WaitTimer <= diff)
        {
            if (Intro)
            {
                if (MovePhase >= 7)
                {
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                    me->GetMotionMaster()->MovePoint(8,IntroWay[7][0],IntroWay[7][1],IntroWay[7][2]);
                }
                else
                {
                    me->GetMotionMaster()->MovePoint(MovePhase,IntroWay[MovePhase][0],IntroWay[MovePhase][1],IntroWay[MovePhase][2]);
                    ++MovePhase;
                }
            }
            if (Flying)
            {
                if (MovePhase >= 7)
                {
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                    me->GetMotionMaster()->MovePoint(8,IntroWay[7][0],IntroWay[7][1],IntroWay[7][2]);
                }
                else
                {
                    me->GetMotionMaster()->MovePoint(MovePhase,IntroWay[MovePhase][0],IntroWay[MovePhase][1],IntroWay[MovePhase][2]);
                    ++MovePhase;
                }
            }

            WaitTimer = 0;
        } else WaitTimer -= diff;
        */

        if (!UpdateVictim())
            return;

        if (Flying)
            return;

        //  Phase 1 "GROUND FIGHT"
        if (Phase == 1)
        {
            if (Movement)
            {
                DoStartMovement(me->getVictim());
                Movement = false;
            }

            if (BellowingRoarTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_BELLOWING_ROAR);
                BellowingRoarTimer = urand(30000,40000);
            } else BellowingRoarTimer -= diff;

            if (SmolderingBreathTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SMOLDERING_BREATH);
                SmolderingBreathTimer = 20000;
            } else SmolderingBreathTimer -= diff;

            if (CharredEarthTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_CHARRED_EARTH);
                CharredEarthTimer = 20000;
            } else CharredEarthTimer -= diff;

            if (TailSweepTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    if (!me->HasInArc(M_PI, pTarget))
                        DoCast(pTarget, SPELL_TAIL_SWEEP);
                TailSweepTimer = 15000;
            } else TailSweepTimer -= diff;

            if (SearingCindersTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_SEARING_CINDERS);
                SearingCindersTimer = 10000;
            } else SearingCindersTimer -= diff;

            uint32 Prozent;
            Prozent = (me->GetHealth()*100) / me->GetMaxHealth();

            if (Prozent < 75 && FlyCount == 0) // first take off 75%
                TakeOff();

            if (Prozent < 50 && FlyCount == 1) // secound take off 50%
                TakeOff();

            if (Prozent < 25 && FlyCount == 2) // third take off 25%
                TakeOff();

            DoMeleeAttackIfReady();
        }

        //Phase 2 "FLYING FIGHT"
        if (Phase == 2)
        {
            if (!RainBones)
            {
                if (!Skeletons)
                {
                    for (uint8 i = 0; i <= 3; ++i)
                    {
                        DoCast(me->getVictim(), SPELL_SUMMON_SKELETON);
                        Skeletons = true;
                    }
                }

                if (RainofBonesTimer < diff && !RainBones) // only once at the beginning of phase 2
                {
                    DoCast(me->getVictim(), SPELL_RAIN_OF_BONES);
                    RainBones = true;
                    SmokingBlastTimer = 20000;
                } else RainofBonesTimer -= diff;

                if (DistractingAshTimer <= diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget, SPELL_DISTRACTING_ASH);
                    DistractingAshTimer = 2000; //timer wrong
                } else DistractingAshTimer -= diff;
            }

            if (RainBones)
            {
                if (SmokingBlastTimer <= diff)
                 {
                    DoCast(me->getVictim(), SPELL_SMOKING_BLAST);
                    SmokingBlastTimer = 1500; //timer wrong
                 } else SmokingBlastTimer -= diff;
            }

            if (FireballBarrageTimer <= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_FARTHEST, 0))
                    DoCast(pTarget, SPELL_FIREBALL_BARRAGE);
                FireballBarrageTimer = 20000;
            } else FireballBarrageTimer -= diff;

            if (FlyTimer <= diff) //landing
            {
                me->MonsterYell(RAND(*YELL_LAND_PHASE_1,*YELL_LAND_PHASE_2), LANG_UNIVERSAL, NULL);

                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MovePoint(3,IntroWay[3][0],IntroWay[3][1],IntroWay[3][2]);

                Flying = true;
            } else FlyTimer -= diff;
        }
    }
};

CreatureAI* GetAI_boss_nightbane(Creature* pCreature)
{
    return new boss_nightbaneAI (pCreature);
}

void AddSC_boss_nightbane()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_nightbane";
    newscript->GetAI = &GetAI_boss_nightbane;
    newscript->RegisterSelf();
}

