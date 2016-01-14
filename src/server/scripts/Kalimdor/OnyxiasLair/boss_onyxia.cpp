/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Onyxia
SD%Complete: 95
SDComment: <Known bugs>
               Ground visual for Deep Breath effect;
               Not summoning whelps on phase 3 (lacks info)
           </Known bugs>
SDCategory: Onyxia's Lair
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "onyxias_lair.h"

enum Yells
{
    // Say
    SAY_AGGRO                   = 0,
    SAY_KILL                    = 1,
    SAY_PHASE_2_TRANS           = 2,
    SAY_PHASE_3_TRANS           = 3,
    // Emote
    EMOTE_BREATH                = 4
};

enum Spells
{
    // Phase 1 spells
    SPELL_WING_BUFFET           = 18500,
    SPELL_FLAME_BREATH          = 18435,
    SPELL_CLEAVE                = 68868,
    SPELL_TAIL_SWEEP            = 68867,

    // Phase 2 spells
    SPELL_DEEP_BREATH           = 23461,
    SPELL_FIREBALL              = 18392,

    //Not much choise about these. We have to make own defintion on the direction/start-end point
    SPELL_BREATH_NORTH_TO_SOUTH = 17086,                    // 20x in "array"
    SPELL_BREATH_SOUTH_TO_NORTH = 18351,                    // 11x in "array"

    SPELL_BREATH_EAST_TO_WEST   = 18576,                    // 7x in "array"
    SPELL_BREATH_WEST_TO_EAST   = 18609,                    // 7x in "array"

    SPELL_BREATH_SE_TO_NW       = 18564,                    // 12x in "array"
    SPELL_BREATH_NW_TO_SE       = 18584,                    // 12x in "array"
    SPELL_BREATH_SW_TO_NE       = 18596,                    // 12x in "array"
    SPELL_BREATH_NE_TO_SW       = 18617,                    // 12x in "array"

    //SPELL_BREATH                = 21131,                  // 8x in "array", different initial cast than the other arrays

    // Phase 3 spells
    SPELL_BELLOWING_ROAR         = 18431
};

enum Events
{
    EVENT_BELLOWING_ROAR = 1,
    EVENT_FLAME_BREATH   = 2,
    EVENT_TAIL_SWEEP     = 3,
    EVENT_CLEAVE         = 4,
    EVENT_WING_BUFFET    = 5,
    EVENT_DEEP_BREATH    = 6,
    EVENT_MOVEMENT       = 7,
    EVENT_FIREBALL       = 8,
    EVENT_LAIR_GUARD     = 9,
    EVENT_WHELP_SPAWN    = 10
};

struct OnyxMove
{
    uint8 LocId;
    uint8 LocIdEnd;
    uint32 SpellId;
    float fX, fY, fZ;
};

static OnyxMove MoveData[8]=
{
    {0, 1, SPELL_BREATH_WEST_TO_EAST,   -33.5561f, -182.682f, -56.9457f}, //west
    {1, 0, SPELL_BREATH_EAST_TO_WEST,   -31.4963f, -250.123f, -55.1278f}, //east
    {2, 4, SPELL_BREATH_NW_TO_SE,         6.8951f, -180.246f, -55.896f}, //north-west
    {3, 5, SPELL_BREATH_NE_TO_SW,        10.2191f, -247.912f, -55.896f}, //north-east
    {4, 2, SPELL_BREATH_SE_TO_NW,       -63.5156f, -240.096f, -55.477f}, //south-east
    {5, 3, SPELL_BREATH_SW_TO_NE,       -58.2509f, -189.020f, -55.790f}, //south-west
    {6, 7, SPELL_BREATH_SOUTH_TO_NORTH, -65.8444f, -213.809f, -55.2985f}, //south
    {7, 6, SPELL_BREATH_NORTH_TO_SOUTH,  22.8763f, -217.152f, -55.0548f}, //north
};

Position const MiddleRoomLocation = {-23.6155f, -215.357f, -55.7344f, 0.0f};

Position const Phase2Location = {-80.924f, -214.299f, -82.942f, 0.0f};
Position const Phase2Floating = { -80.924f, -214.299f, -57.942f, 0.0f };

Position const SpawnLocations[3]=
{
    //Whelps
    {-30.127f, -254.463f, -89.440f, 0.0f},
    {-30.817f, -177.106f, -89.258f, 0.0f},
    //Lair Guard
    {-145.950f, -212.831f, -68.659f, 0.0f}
};

class boss_onyxia : public CreatureScript
{
public:
    boss_onyxia() : CreatureScript("boss_onyxia") { }

    struct boss_onyxiaAI : public BossAI
    {
        boss_onyxiaAI(Creature* creature) : BossAI(creature, DATA_ONYXIA)
        {
            Initialize();
        }

        void Initialize()
        {
            Phase = PHASE_START;
            MovePoint = urand(0, 5);
            PointData = GetMoveData();
            SummonWhelpCount = 0;
            triggerGUID.Clear();
            tankGUID.Clear();
            IsMoving = false;
        }

        void Reset() override
        {
            Initialize();

            if (!IsCombatMovementAllowed())
                SetCombatMovement(true);

            _Reset();
            me->SetReactState(REACT_AGGRESSIVE);
            instance->SetData(DATA_ONYXIA_PHASE, Phase);
            instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_FLAME_BREATH, urand(10000, 20000));
            events.ScheduleEvent(EVENT_TAIL_SWEEP, urand(15000, 20000));
            events.ScheduleEvent(EVENT_CLEAVE, urand(2000, 5000));
            events.ScheduleEvent(EVENT_WING_BUFFET, urand(10000, 20000));
            instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->SetInCombatWithZone();
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                summoned->AI()->AttackStart(target);

            switch (summoned->GetEntry())
            {
                case NPC_WHELP:
                    ++SummonWhelpCount;
                    break;
                case NPC_LAIRGUARD:
                    summoned->setActive(true);
                    break;
            }
            summons.Summon(summoned);
        }


        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_KILL);
        }

        void SpellHit(Unit* /*pCaster*/, const SpellInfo* Spell) override
        {
            if (Spell->Id == SPELL_BREATH_EAST_TO_WEST ||
                Spell->Id == SPELL_BREATH_WEST_TO_EAST ||
                Spell->Id == SPELL_BREATH_SE_TO_NW ||
                Spell->Id == SPELL_BREATH_NW_TO_SE ||
                Spell->Id == SPELL_BREATH_SW_TO_NE ||
                Spell->Id == SPELL_BREATH_NE_TO_SW)
            {
                PointData = GetMoveData();
                MovePoint = PointData->LocIdEnd;

                me->SetSpeed(MOVE_FLIGHT, 1.5f);
                me->GetMotionMaster()->MovePoint(8, MiddleRoomLocation);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case 8:
                        PointData = GetMoveData();
                        if (PointData)
                        {
                            me->SetSpeed(MOVE_FLIGHT, 1.0f);
                            me->GetMotionMaster()->MovePoint(PointData->LocId, PointData->fX, PointData->fY, PointData->fZ);
                        }
                        break;
                    case 9:
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        if (Creature* trigger = ObjectAccessor::GetCreature(*me, triggerGUID))
                            me->Kill(trigger);
                        me->SetReactState(REACT_AGGRESSIVE);
                        // tank selection based on phase one. If tank is not there i take nearest one
                        if (Unit* tank = ObjectAccessor::GetUnit(*me, tankGUID))
                            me->GetMotionMaster()->MoveChase(tank);
                        else if (Unit* newtarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                            me->GetMotionMaster()->MoveChase(newtarget);
                        events.ScheduleEvent(EVENT_BELLOWING_ROAR, 5000);
                        events.ScheduleEvent(EVENT_FLAME_BREATH, urand(10000, 20000));
                        events.ScheduleEvent(EVENT_TAIL_SWEEP, urand(15000, 20000));
                        events.ScheduleEvent(EVENT_CLEAVE, urand(2000, 5000));
                        events.ScheduleEvent(EVENT_WING_BUFFET, urand(15000, 30000));
                        break;
                    case 10:
                        me->SetCanFly(true);
                        me->SetDisableGravity(true);
                        me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        me->SetFacingTo(me->GetOrientation() + float(M_PI));
                        if (Creature * trigger = me->SummonCreature(NPC_TRIGGER, MiddleRoomLocation, TEMPSUMMON_CORPSE_DESPAWN))
                            triggerGUID = trigger->GetGUID();
                        me->GetMotionMaster()->MoveTakeoff(11, Phase2Floating);
                        me->SetSpeed(MOVE_FLIGHT, 1.0f);
                        Talk(SAY_PHASE_2_TRANS);
                        instance->SetData(DATA_ONYXIA_PHASE, Phase);
                        events.ScheduleEvent(EVENT_WHELP_SPAWN, 5000);
                        events.ScheduleEvent(EVENT_LAIR_GUARD, 15000);
                        events.ScheduleEvent(EVENT_DEEP_BREATH, 75000);
                        events.ScheduleEvent(EVENT_MOVEMENT, 10000);
                        events.ScheduleEvent(EVENT_FIREBALL, 18000);
                        break;
                    case 11:
                        if (PointData)
                            me->GetMotionMaster()->MovePoint(PointData->LocId, PointData->fX, PointData->fY, PointData->fZ);
                        me->GetMotionMaster()->MoveIdle();
                        break;
                    default:
                        IsMoving = false;
                        break;
                }
            }
        }

        void SpellHitTarget(Unit* target, const SpellInfo* Spell) override
        {
            //Workaround - Couldn't find a way to group this spells (All Eruption)
            if (((Spell->Id >= 17086 && Spell->Id <= 17095) ||
                (Spell->Id == 17097) ||
                (Spell->Id >= 18351 && Spell->Id <= 18361) ||
                (Spell->Id >= 18564 && Spell->Id <= 18576) ||
                (Spell->Id >= 18578 && Spell->Id <= 18607) ||
                (Spell->Id == 18609) ||
                (Spell->Id >= 18611 && Spell->Id <= 18628) ||
                (Spell->Id >= 21132 && Spell->Id <= 21133) ||
                (Spell->Id >= 21135 && Spell->Id <= 21139) ||
                (Spell->Id >= 22191 && Spell->Id <= 22202) ||
                (Spell->Id >= 22267 && Spell->Id <= 22268)) &&
                (target->GetTypeId() == TYPEID_PLAYER))
            {
                instance->SetData(DATA_SHE_DEEP_BREATH_MORE, FAIL);
            }
        }

        OnyxMove* GetMoveData()
        {
            uint8 MaxCount = sizeof(MoveData) / sizeof(OnyxMove);

            for (uint8 i = 0; i < MaxCount; ++i)
            {
                if (MoveData[i].LocId == MovePoint)
                    return &MoveData[i];
            }

            return NULL;
        }

        void SetNextRandomPoint()
        {
            uint8 MaxCount = sizeof(MoveData) / sizeof(OnyxMove);

            uint8 iTemp = urand(0, MaxCount - 1);

            if (iTemp >= MovePoint)
                ++iTemp;

            MovePoint = iTemp;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            //Common to PHASE_START && PHASE_END
            if (Phase == PHASE_START || Phase == PHASE_END)
            {
                //Specific to PHASE_START || PHASE_END
                if (Phase == PHASE_START)
                {
                    if (HealthBelowPct(65))
                    {
                        if (Unit* target = me->GetVictim())
                            tankGUID = target->GetGUID();
                        SetCombatMovement(false);
                        Phase = PHASE_BREATH;
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->GetMotionMaster()->MovePoint(10, Phase2Location);
                        return;
                    }
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BELLOWING_ROAR: // Phase PHASE_END
                        {
                            DoCastVictim(SPELL_BELLOWING_ROAR);
                            // Eruption
                            GameObject* Floor = NULL;
                            Trinity::GameObjectInRangeCheck check(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 15);
                            Trinity::GameObjectLastSearcher<Trinity::GameObjectInRangeCheck> searcher(me, Floor, check);
                            me->VisitNearbyGridObject(30, searcher);
                            if (Floor)
                                instance->SetGuidData(DATA_FLOOR_ERUPTION_GUID, Floor->GetGUID());
                            events.ScheduleEvent(EVENT_BELLOWING_ROAR, 30000);
                            break;
                        }
                        case EVENT_FLAME_BREATH:   // Phase PHASE_START and PHASE_END
                            DoCastVictim(SPELL_FLAME_BREATH);
                            events.ScheduleEvent(EVENT_FLAME_BREATH, urand(10000, 20000));
                            break;
                        case EVENT_TAIL_SWEEP:     // Phase PHASE_START and PHASE_END
                            DoCastAOE(SPELL_TAIL_SWEEP);
                            events.ScheduleEvent(EVENT_TAIL_SWEEP, urand(15000, 20000));
                            break;
                        case EVENT_CLEAVE:         // Phase PHASE_START and PHASE_END
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(2000, 5000));
                            break;
                        case EVENT_WING_BUFFET:    // Phase PHASE_START and PHASE_END
                            DoCastVictim(SPELL_WING_BUFFET);
                            events.ScheduleEvent(EVENT_WING_BUFFET, urand(15000, 30000));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
            else
            {
                if (HealthBelowPct(40))
                {
                    Phase = PHASE_END;
                    instance->SetData(DATA_ONYXIA_PHASE, PHASE_END);
                    Talk(SAY_PHASE_3_TRANS);
                    SetCombatMovement(true);
                    IsMoving = false;
                    Position const pos = me->GetHomePosition();
                    me->GetMotionMaster()->MovePoint(9, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() + 12.0f);
                    events.ScheduleEvent(EVENT_BELLOWING_ROAR, 30000);
                    return;
                }

                if (!me->isMoving())
                    if (Creature* trigger = ObjectAccessor::GetCreature(*me, triggerGUID))
                        me->SetFacingToObject(trigger);

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEEP_BREATH:      // Phase PHASE_BREATH
                            if (!IsMoving)
                            {
                                if (me->IsNonMeleeSpellCast(false))
                                    me->InterruptNonMeleeSpells(false);

                                Talk(EMOTE_BREATH);
                                if (PointData) /// @todo: In what cases is this null? What should we do?
                                    DoCast(me, PointData->SpellId);
                                events.ScheduleEvent(EVENT_DEEP_BREATH, 75000);
                            }
                            else
                                events.ScheduleEvent(EVENT_DEEP_BREATH, 1000);
                            break;
                        case EVENT_MOVEMENT:         // Phase PHASE_BREATH
                            if (!IsMoving && !(me->HasUnitState(UNIT_STATE_CASTING)))
                            {
                                SetNextRandomPoint();
                                PointData = GetMoveData();

                                if (!PointData)
                                    return;

                                me->GetMotionMaster()->MovePoint(PointData->LocId, PointData->fX, PointData->fY, PointData->fZ);
                                IsMoving = true;
                                events.ScheduleEvent(EVENT_MOVEMENT, 25000);
                            }
                            else
                                events.ScheduleEvent(EVENT_MOVEMENT, 500);
                            break;
                        case EVENT_FIREBALL:         // Phase PHASE_BREATH
                            if (!IsMoving)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    DoCast(target, SPELL_FIREBALL);
                                events.ScheduleEvent(EVENT_FIREBALL, 8000);
                            }
                            else
                                events.ScheduleEvent(EVENT_FIREBALL, 1000);
                            break;
                        case EVENT_LAIR_GUARD:       // Phase PHASE_BREATH
                            me->SummonCreature(NPC_LAIRGUARD, SpawnLocations[2], TEMPSUMMON_CORPSE_DESPAWN);
                            events.ScheduleEvent(EVENT_LAIR_GUARD, 30000);
                            break;
                        case EVENT_WHELP_SPAWN:      // Phase PHASE_BREATH
                            me->SummonCreature(NPC_WHELP, SpawnLocations[0], TEMPSUMMON_CORPSE_DESPAWN);
                            me->SummonCreature(NPC_WHELP, SpawnLocations[1], TEMPSUMMON_CORPSE_DESPAWN);
                            if (SummonWhelpCount >= RAID_MODE(20, 40))
                            {
                                SummonWhelpCount = 0;
                                events.ScheduleEvent(EVENT_WHELP_SPAWN, 90000);
                            }
                            else
                                events.ScheduleEvent(EVENT_WHELP_SPAWN, 500);
                            break;
                        default:
                            break;
                    }
                }
            }
        }

        private:
            OnyxMove* PointData;
            uint8 Phase;
            uint8 MovePoint;
            uint8 SummonWhelpCount;
            ObjectGuid triggerGUID;
            ObjectGuid tankGUID;
            bool IsMoving;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_onyxiaAI>(creature);
    }
};

void AddSC_boss_onyxia()
{
    new boss_onyxia();
}
