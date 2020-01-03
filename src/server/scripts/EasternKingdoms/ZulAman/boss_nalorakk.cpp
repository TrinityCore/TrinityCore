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
SDName: Boss_Nalorakk
SD%Complete: 100
SDComment:
SDCategory: Zul'Aman
EndScriptData */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "zulaman.h"

enum Yells
{
    YELL_NALORAKK_WAVE1   =  0,
    YELL_NALORAKK_WAVE2   =  1,
    YELL_NALORAKK_WAVE3   =  2,
    YELL_NALORAKK_WAVE4   =  3,
    YELL_AGGRO            =  4,
    YELL_SURGE            =  5,
    YELL_SHIFTEDTOBEAR    =  6,
    YELL_SHIFTEDTOTROLL   =  7,
    YELL_BERSERK          =  8,
    YELL_KILL_ONE         =  9,
    YELL_KILL_TWO         = 10,
    YELL_DEATH            = 11

//  Not yet implemented
//  YELL_NALORAKK_EVENT1  = 12,
//  YELL_NALORAKK_EVENT2  = 13
};

enum Spells
{
    // Troll form
    SPELL_BRUTALSWIPE     = 42384,
    SPELL_MANGLE          = 42389,
    SPELL_MANGLEEFFECT    = 44955,
    SPELL_SURGE           = 42402,
    SPELL_BEARFORM        = 42377,

    // Bear form
    SPELL_LACERATINGSLASH = 42395,
    SPELL_RENDFLESH       = 42397,
    SPELL_DEAFENINGROAR   = 42398,

    SPELL_BERSERK         = 45078
};

// Trash Waves
float NalorakkWay[8][3] =
{
    { 18.569f, 1414.512f, 11.42f}, // waypoint 1
    {-17.264f, 1419.551f, 12.62f},
    {-52.642f, 1419.357f, 27.31f}, // waypoint 2
    {-69.908f, 1419.721f, 27.31f},
    {-79.929f, 1395.958f, 27.31f},
    {-80.072f, 1374.555f, 40.87f}, // waypoint 3
    {-80.072f, 1314.398f, 40.87f},
    {-80.072f, 1295.775f, 48.60f}  // waypoint 4
};

class boss_nalorakk : public CreatureScript
{
    public:
        boss_nalorakk() : CreatureScript("boss_nalorakk") { }

        struct boss_nalorakkAI : public BossAI
        {
            boss_nalorakkAI(Creature* creature) : BossAI(creature, BOSS_NALORAKK)
            {
                Initialize();
                inMove = false;
                MoveEvent = true;
                MovePhase = 0;
                waitTimer = 0;
                LaceratingSlash_Timer = 0;
                RendFlesh_Timer = 0;
                DeafeningRoar_Timer = 0;
            }

            void Initialize()
            {
                Surge_Timer = urand(15000, 20000);
                BrutalSwipe_Timer = urand(7000, 12000);
                Mangle_Timer = urand(10000, 15000);
                ShapeShift_Timer = urand(45000, 50000);
                Berserk_Timer = 600000;

                inBearForm = false;
            }

            uint32 BrutalSwipe_Timer;
            uint32 Mangle_Timer;
            uint32 Surge_Timer;

            uint32 LaceratingSlash_Timer;
            uint32 RendFlesh_Timer;
            uint32 DeafeningRoar_Timer;

            uint32 ShapeShift_Timer;
            uint32 Berserk_Timer;

            bool inBearForm;
            bool MoveEvent;
            bool inMove;
            uint32 MovePhase;
            uint32 waitTimer;

            void Reset() override
            {
                _Reset();

                if (MoveEvent)
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    inMove = false;
                    waitTimer = 0;
                    me->SetSpeedRate(MOVE_RUN, 2);
                    me->SetWalk(false);
                }
                else
                    me->GetMotionMaster()->MovePoint(0, NalorakkWay[7][0], NalorakkWay[7][1], NalorakkWay[7][2]);

                Initialize();
                // me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, 5122);  /// @todo find the correct equipment id
            }

            void SendAttacker(Unit* target) const
            {
                std::vector<Creature*> tempList;

                Trinity::AllFriendlyCreaturesInGrid check(me);
                Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> searcher(me, tempList, check);
                Cell::VisitGridObjects(me, searcher, 25.0f);

                if (tempList.empty())
                    return;

                for (Creature* creature : tempList)
                {
                    creature->SetNoCallAssistance(true);
                    creature->AI()->AttackStart(target);
                }
            }

            void AttackStart(Unit* who) override
            {
                if (!MoveEvent)
                    BossAI::AttackStart(who);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!MoveEvent)
                    BossAI::MoveInLineOfSight(who);
                else
                {
                    if (me->IsHostileTo(who))
                    {
                        if (!inMove)
                        {
                            switch (MovePhase)
                            {
                                case 0:
                                    if (me->IsWithinDistInMap(who, 50))
                                    {
                                        Talk(YELL_NALORAKK_WAVE1);

                                        me->GetMotionMaster()->MovePoint(1, NalorakkWay[1][0], NalorakkWay[1][1], NalorakkWay[1][2]);
                                        ++MovePhase;
                                        inMove = true;

                                        SendAttacker(who);
                                    }
                                    break;
                                case 2:
                                    if (me->IsWithinDistInMap(who, 40))
                                    {
                                        Talk(YELL_NALORAKK_WAVE2);

                                        me->GetMotionMaster()->MovePoint(3, NalorakkWay[3][0], NalorakkWay[3][1], NalorakkWay[3][2]);
                                        ++MovePhase;
                                        inMove = true;

                                        SendAttacker(who);
                                    }
                                    break;
                                case 5:
                                    if (me->IsWithinDistInMap(who, 40))
                                    {
                                        Talk(YELL_NALORAKK_WAVE3);

                                        me->GetMotionMaster()->MovePoint(6, NalorakkWay[6][0], NalorakkWay[6][1], NalorakkWay[6][2]);
                                        ++MovePhase;
                                        inMove = true;

                                        SendAttacker(who);
                                    }
                                    break;
                                case 7:
                                    if (me->IsWithinDistInMap(who, 50))
                                    {
                                        SendAttacker(who);

                                        Talk(YELL_NALORAKK_WAVE4);

                                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                                        MoveEvent = false;
                                    }
                                    break;
                            }
                        }
                    }
                }
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();

                Talk(YELL_AGGRO);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(YELL_DEATH);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                switch (urand(0, 1))
                {
                    case 0:
                        Talk(YELL_KILL_ONE);
                        break;
                    case 1:
                        Talk(YELL_KILL_TWO);
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (MoveEvent)
                {
                    if (type != POINT_MOTION_TYPE)
                        return;

                    if (!inMove)
                        return;

                    if (MovePhase != id)
                        return;

                    switch (MovePhase)
                    {
                        case 2:
                            me->SetOrientation(3.1415f*2);
                            inMove = false;
                            return;
                        case 1:
                        case 3:
                        case 4:
                        case 6:
                            ++MovePhase;
                            waitTimer = 1;
                            inMove = true;
                            return;
                        case 5:
                            me->SetOrientation(3.1415f*0.5f);
                            inMove = false;
                            return;
                        case 7:
                            me->SetOrientation(3.1415f*0.5f);
                            inMove = false;
                            return;
                    }

                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (waitTimer && inMove)
                {
                    if (waitTimer <= diff)
                    {
                        me->GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);
                        me->GetMotionMaster()->MovePoint(MovePhase, NalorakkWay[MovePhase][0], NalorakkWay[MovePhase][1], NalorakkWay[MovePhase][2]);
                        waitTimer = 0;
                    }
                    else
                        waitTimer -= diff;
                }

                if (!UpdateVictim())
                    return;

                if (Berserk_Timer <= diff)
                {
                    DoCast(me, SPELL_BERSERK, true);
                    Talk(YELL_BERSERK);
                    Berserk_Timer = 600000;
                }
                else
                    Berserk_Timer -= diff;

                if (ShapeShift_Timer <= diff)
                {
                    if (inBearForm)
                    {
                        // me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, 5122);
                        Talk(YELL_SHIFTEDTOTROLL);
                        me->RemoveAurasDueToSpell(SPELL_BEARFORM);
                        Surge_Timer = urand(15000, 20000);
                        BrutalSwipe_Timer = urand(7000, 12000);
                        Mangle_Timer = urand(10000, 15000);
                        ShapeShift_Timer = urand(45000, 50000);
                        inBearForm = false;
                    }
                    else
                    {
                        // me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, 0);
                        Talk(YELL_SHIFTEDTOBEAR);
                        DoCast(me, SPELL_BEARFORM, true);
                        LaceratingSlash_Timer = 2000; // dur 18s
                        RendFlesh_Timer = 3000;  // dur 5s
                        DeafeningRoar_Timer = urand(5000, 10000);  // dur 2s
                        ShapeShift_Timer = urand(20000, 25000); // dur 30s
                        inBearForm = true;
                    }
                }
                else
                    ShapeShift_Timer -= diff;

                if (!inBearForm)
                {
                    if (BrutalSwipe_Timer <= diff)
                    {
                        DoCastVictim(SPELL_BRUTALSWIPE);
                        BrutalSwipe_Timer = urand(7000, 12000);
                    }
                    else
                        BrutalSwipe_Timer -= diff;

                    if (Mangle_Timer <= diff)
                    {
                        if (me->GetVictim() && !me->EnsureVictim()->HasAura(SPELL_MANGLEEFFECT))
                        {
                            DoCastVictim(SPELL_MANGLE);
                            Mangle_Timer = 1000;
                        }
                        else Mangle_Timer = urand(10000, 15000);
                    }
                    else
                        Mangle_Timer -= diff;

                    if (Surge_Timer <= diff)
                    {
                        Talk(YELL_SURGE);
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 45, true);
                        if (target)
                            DoCast(target, SPELL_SURGE);
                        Surge_Timer = urand(15000, 20000);
                    }
                    else
                        Surge_Timer -= diff;
                }
                else
                {
                    if (LaceratingSlash_Timer <= diff)
                    {
                        DoCastVictim(SPELL_LACERATINGSLASH);
                        LaceratingSlash_Timer = urand(18000, 23000);
                    }
                    else
                        LaceratingSlash_Timer -= diff;

                    if (RendFlesh_Timer <= diff)
                    {
                        DoCastVictim(SPELL_RENDFLESH);
                        RendFlesh_Timer = urand(5000, 10000);
                    }
                    else
                        RendFlesh_Timer -= diff;

                    if (DeafeningRoar_Timer <= diff)
                    {
                        DoCastVictim(SPELL_DEAFENINGROAR);
                        DeafeningRoar_Timer = urand(15000, 20000);
                    }
                    else
                        DeafeningRoar_Timer -= diff;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulAmanAI<boss_nalorakkAI>(creature);
        }
};

void AddSC_boss_nalorakk()
{
    new boss_nalorakk();
}
