/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#define QUEST_NIGHTBANE             9644

float IntroWay[8][3] =
{
    {-11053.37f, -1794.48f, 149.00f},
    {-11141.07f, -1841.40f, 125.00f},
    {-11187.28f, -1890.23f, 125.00f},
    {-11189.20f, -1931.25f, 125.00f},
    {-11153.76f, -1948.93f, 125.00f},
    {-11128.73f, -1929.75f, 125.00f},
    {-11140.00f, -1915.00f, 122.00f},
    {-11163.00f, -1903.00f, 91.473f}
};

class boss_nightbane : public CreatureScript
{
public:
    boss_nightbane() : CreatureScript("boss_nightbane") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_nightbaneAI (pCreature);
    }

    struct boss_nightbaneAI : public ScriptedAI
    {
        boss_nightbaneAI(Creature* c) : ScriptedAI(c)
        {
            _instance = c->GetInstanceScript();
            Intro = true;
        }

        InstanceScript* _instance;

        uint32 BellowingRoarTimer;
        uint32 CharredEarthTimer;
        uint32 DistractingAshTimer;
        uint32 SmolderingBreathTimer;
        uint32 TailSweepTimer;
        uint32 RainofBonesTimer;
        uint32 SmokingBlastTimer;
        uint32 FireballBarrageTimer;
        uint32 SearingCindersTimer;

        uint32 Phase;
        uint8 MovePhase;
        uint8 FlyCount;
        uint32 FlyTimer;

        bool RainBones;
        bool Skeletons;
        bool Intro;
        bool Flying;
        bool Movement;

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

            Phase = 1;
            FlyCount = 0;
            MovePhase = 0;
            Movement = false;
            Flying = false;

            me->SetSpeed(MOVE_RUN, 2.0f);
            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
            me->setActive(true);

            HandleTerraceDoors(true);
            me->SetReactState(REACT_PASSIVE);

            if (!Intro)
            {
                _instance->SetData(TYPE_NIGHTBANE, NOT_STARTED);
                me->DisappearAndDie();
            }
            else
                _instance->DoSendNotifyToInstance(EMOTE_SUMMON);
        }

        void HandleTerraceDoors(bool open)
        {
            if (_instance)
            {
                _instance->HandleGameObject(_instance->GetData64(DATA_MASTERS_TERRACE_DOOR_1), open);
                _instance->HandleGameObject(_instance->GetData64(DATA_MASTERS_TERRACE_DOOR_2), open);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            HandleTerraceDoors(false);
            me->MonsterYell(YELL_AGGRO, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit * /*killer*/)
        {
            if (_instance)
                _instance->SetData(TYPE_NIGHTBANE, DONE);

            HandleTerraceDoors(true);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                    return;

            if (id == 8)
            {
                me->MonsterTextEmote(EMOTE_BREATH, 0, true);
                Phase = 2;
                return;
            }

            if (id == 7)
            {
                if (Phase == 2)
                {
                    Flying = false;
                    Phase = 1;
                    me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                }

                DoResetThreat();
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_UNK_6);
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetInCombatWithZone();
                if (me->getVictim())
                    me->GetMotionMaster()->MoveChase(me->getVictim());
                return;
            }

            ++MovePhase;
            Movement = true;
        }

        void JustSummoned(Creature* summoned)
        {
            summoned->SetInCombatWithZone();
        }

        void TakeOff()
        {
            me->MonsterYell(YELL_FLY_PHASE, LANG_UNIVERSAL, 0);
            me->SetReactState(REACT_PASSIVE);
            me->InterruptSpell(CURRENT_GENERIC_SPELL);
            me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            me->GetMotionMaster()->Clear(false);
            me->GetMotionMaster()->MovePoint(8, IntroWay[2][0], IntroWay[2][1], IntroWay[2][2]);

            FlyTimer = urand(45000, 60000);
            ++FlyCount;

            RainofBonesTimer = 5000;
            RainBones = false;
            Skeletons = false;

            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
         }

        void UpdateAI(uint32 const diff)
        {
            if (Intro && !Movement)
            {
                Intro = false;
                Movement = true;
            }

            if (Movement)
            {
                Movement = false;
                me->GetMotionMaster()->MovePoint(MovePhase, IntroWay[MovePhase][0], IntroWay[MovePhase][1], IntroWay[MovePhase][2]);
            }

            if (!UpdateVictim())
                return;

            if (Flying)
                return;

            //  Phase 1 "GROUND FIGHT"
            if (Phase == 1)
            {
                if (BellowingRoarTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_BELLOWING_ROAR);
                    BellowingRoarTimer = urand(30000, 40000);
                } else BellowingRoarTimer -= diff;

                if (SmolderingBreathTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SMOLDERING_BREATH);
                    SmolderingBreathTimer = 20000;
                } else SmolderingBreathTimer -= diff;

                if (CharredEarthTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_CHARRED_EARTH);
                    CharredEarthTimer = 20000;
                } else CharredEarthTimer -= diff;

                if (TailSweepTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        if (!me->HasInArc(M_PI, target))
                            DoCast(target, SPELL_TAIL_SWEEP);
                    TailSweepTimer = 15000;
                } else TailSweepTimer -= diff;

                if (SearingCindersTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_SEARING_CINDERS);
                    SearingCindersTimer = 10000;
                } else SearingCindersTimer -= diff;

                uint32 Prozent = uint32(me->GetHealthPct());

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
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_DISTRACTING_ASH);
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
                    if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0))
                        DoCast(target, SPELL_FIREBALL_BARRAGE);
                    FireballBarrageTimer = 20000;
                } else FireballBarrageTimer -= diff;

                if (FlyTimer <= diff) //landing
                {
                    me->MonsterYell(RAND(*YELL_LAND_PHASE_1, *YELL_LAND_PHASE_2), LANG_UNIVERSAL, 0);
                    Movement = true;
                    MovePhase = 3;
                    Flying = true;
                } else FlyTimer -= diff;
            }
        }
    };
};

class go_blackened_urn : public GameObjectScript
{
public:
    go_blackened_urn() : GameObjectScript("go_blackened_urn") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        InstanceScript* _instance = go->GetInstanceScript();
        if (!_instance)
            return false;

        // already summoned
        if (_instance->GetData(TYPE_NIGHTBANE) != NOT_STARTED)
            return false;

        if (player->GetQuestStatus(QUEST_NIGHTBANE) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_NIGHTBANE) == QUEST_STATUS_REWARDED)
            go->SummonCreature(17225, -11003.7f, -1760.19f, 140.25f, 0.29f);

        _instance->SetData(TYPE_NIGHTBANE, IN_PROGRESS);
        return false;
    }
};

void AddSC_boss_nightbane()
{
    new boss_nightbane();
    new go_blackened_urn();
}
