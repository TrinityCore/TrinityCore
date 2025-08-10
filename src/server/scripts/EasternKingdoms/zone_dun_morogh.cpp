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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"

enum FrozenMountaineer
{
    DATA_SET_ICE_BROKEN      = 1,
    EVENT_RUN_AWAY           = 1,
    SAY_MONSTEREMOTE         = 0,
    SPELL_SUMMON_FROZEN_TOMB = 77906,
    SPELL_FREEZE_ANIM        = 77910
};

/*######
# npc_frozen_mountaineer
######*/

class npc_frozen_mountaineer : public CreatureScript
{
public:
    npc_frozen_mountaineer() : CreatureScript("npc_frozen_mountaineer") { }

    struct npc_frozen_mountaineerAI : public ScriptedAI
    {
        npc_frozen_mountaineerAI(Creature* creature) : ScriptedAI(creature), _dataOneSet(false) { }

        void Reset() override
        {
            _events.Reset();
            DoCastSelf(SPELL_SUMMON_FROZEN_TOMB, true);
            DoCastSelf(SPELL_FREEZE_ANIM, true);
        }

        void SetData(uint32 /*type*/, uint32 data) override
        {
            if (data == DATA_SET_ICE_BROKEN && !_dataOneSet)
            {
                me->RemoveAllAuras();
                Talk(SAY_MONSTEREMOTE);
                _dataOneSet = true;
                _events.ScheduleEvent(EVENT_RUN_AWAY, Seconds(3));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!_dataOneSet)
                return;

            _events.Update(diff);

            if (_events.ExecuteEvent() == EVENT_RUN_AWAY)
            {
                me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + (std::cos(me->GetOrientation()) * 15.0f), me->GetPositionY() + (std::sin(me->GetOrientation()) * 15.0f), me->GetPositionZ());
                me->DespawnOrUnsummon(Seconds(2));
            }
        }
    private:
        EventMap _events;
        bool _dataOneSet;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_frozen_mountaineerAI(creature);
    }
};

enum DecontaminationData
{
    NPC_DECONTAMINATION_BUNNY           = 46165,
    NPC_CLEAN_CANNON_X2                 = 46208,
    NPC_SANITRON_5000                   = 46185,
    NPC_SAFE_TECHNICIAN                 = 46230,

    SAY_SANITRON_START                  = 0,
    SAY_SANITRON_FINISH                 = 1,
    SAY_SANITRON_DESTROY                = 2,

    SAY_TECHNICIAN_CLEAN_CANNON         = 0,
    SAY_TECHNICIAN_SANITRON_DESTROY     = 1,

    PATH_SANITRON_LEFT_START            = 4618500,
    PATH_SANITRON_MIDDLE_START          = 4618501,
    PATH_SANITRON_RIGHT_START           = 4618502,

    WAYPOINT_SANITRON_STAGE_ONE         = 0,
    WAYPOINT_SANITRON_STAGE_TWO         = 1,
    WAYPOINT_SANITRON_STAGE_THREE       = 2,
    WAYPOINT_SANITRON_FINISH            = 3,

    ACTION_TECHNICIAN_START_EVENT       = 1,

    POINT_SAFE_TECHNICIAN_SANITRON      = 1,
    POINT_SAFE_TECHNICIAN_FINISH        = 2,

    SPELL_DECONTAMINATE_STAGE_1         = 86075,
    SPELL_DECONTAMINATE_STAGE_2         = 86098,
    SPELL_DECONTAMINATE_STAGE_3         = 86086,
    SPELL_CLEAN_CANNON_CLEAN_BURST      = 86080,
    SPELL_FORCE_CAST_GNOMEREGAN_AURA    = 86298,
    SPELL_SANITRON_COSMETIC_EXPLOSION   = 46419
};

// 46185 - Sanitron 5000
struct npc_sanitron_5000 : public NullCreatureAI
{
    npc_sanitron_5000(Creature* creature) : NullCreatureAI(creature) { }

    uint32 GetPathId() const
    {
        if (me->HasStringId("SanitronLeft"))
            return PATH_SANITRON_LEFT_START;
        else if (me->HasStringId("SanitronMiddle"))
            return PATH_SANITRON_MIDDLE_START;
        else if (me->HasStringId("SanitronRight"))
            return PATH_SANITRON_RIGHT_START;
        return 0;
    }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            return;

        Player* player = passenger->ToPlayer();
        if (!player)
            return;

        Talk(SAY_SANITRON_START);
        player->TalkedToCreature(me->GetEntry(), me->GetGUID());
        me->GetMotionMaster()->MovePath(GetPathId(), false);
    }

    void ForceCastOnPassenger(FindCreatureOptions const& options, uint32 spellId)
    {
        std::list<Creature*> bunnys;
        me->GetCreatureListWithOptionsInGrid(bunnys, 20.0f, options);

        Vehicle* veh = me->GetVehicleKit();
        if (!veh)
            return;

        Unit* passenger = veh->GetPassenger(0);
        if (!passenger)
            return;

        for (Creature* bunny : bunnys)
        {
            bunny->CastSpell(passenger, spellId, false);
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_SANITRON_LEFT_START || pathId == PATH_SANITRON_MIDDLE_START || pathId == PATH_SANITRON_RIGHT_START)
        {
            if (waypointId == WAYPOINT_SANITRON_STAGE_ONE)
                ForceCastOnPassenger({ .CreatureId = NPC_DECONTAMINATION_BUNNY, .StringId = "DecontaminationStageOne" }, SPELL_DECONTAMINATE_STAGE_1);
            else if (waypointId == WAYPOINT_SANITRON_STAGE_TWO)
            {
                ForceCastOnPassenger({ .CreatureId = NPC_CLEAN_CANNON_X2 }, SPELL_CLEAN_CANNON_CLEAN_BURST);
                ForceCastOnPassenger({ .CreatureId = NPC_DECONTAMINATION_BUNNY, .StringId = "DecontaminationStageTwo" }, SPELL_DECONTAMINATE_STAGE_2);
            }
            else if (waypointId == WAYPOINT_SANITRON_STAGE_THREE)
                ForceCastOnPassenger({ .CreatureId = NPC_DECONTAMINATION_BUNNY, .StringId = "DecontaminationStageThree" }, SPELL_DECONTAMINATE_STAGE_3);
            else if (waypointId == WAYPOINT_SANITRON_FINISH)
            {
                _scheduler.Schedule(2s, [this](TaskContext task)
                {
                    Talk(SAY_SANITRON_DESTROY);
                    DoCast(SPELL_SANITRON_COSMETIC_EXPLOSION);
                    task.Schedule(1s, [this](TaskContext /*task*/)
                    {
                        if (Creature* technician = me->FindNearestCreatureWithOptions(30.0f, { .CreatureId = NPC_SAFE_TECHNICIAN, .StringId = "SafeTechnicianSanitron" }))
                            technician->AI()->DoAction(ACTION_TECHNICIAN_START_EVENT);

                        me->KillSelf();
                    });
                });
            }
        }
    }

    void WaypointStarted(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_SANITRON_LEFT_START || pathId == PATH_SANITRON_MIDDLE_START || pathId == PATH_SANITRON_RIGHT_START)
        {
            if (waypointId == WAYPOINT_SANITRON_STAGE_THREE)
            {
                if (Creature* technician = me->FindNearestCreatureWithOptions(30.0f, { .CreatureId = NPC_SAFE_TECHNICIAN, .StringId = "SafeTechnicianSayText" }))
                    technician->AI()->Talk(SAY_TECHNICIAN_CLEAN_CANNON);
            }
            else if (waypointId == WAYPOINT_SANITRON_FINISH)
            {
                Talk(SAY_SANITRON_FINISH);
                DoCast(SPELL_FORCE_CAST_GNOMEREGAN_AURA);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

Position const SafeTechnicianSanitron = { -5178.169f, 696.795f, 288.22797f };

// 46230 - S.A.F.E Technician
struct npc_safe_technician_sanitron : public NullCreatureAI
{
    npc_safe_technician_sanitron(Creature* creature) : NullCreatureAI(creature), _isEventStarted(false) { }

    void DoAction(int32 action) override
    {
        if (action == ACTION_TECHNICIAN_START_EVENT)
        {
            if (!_isEventStarted)
            {
                _isEventStarted = true;
                me->SetEmoteState(EMOTE_STATE_NONE);
                me->SetFacingTo(0.2967f);
                _scheduler.Schedule(2s + 500ms, [this](TaskContext /*task*/)
                {
                    me->GetMotionMaster()->MovePoint(POINT_SAFE_TECHNICIAN_SANITRON, SafeTechnicianSanitron);
                });
            }
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_SAFE_TECHNICIAN_SANITRON)
        {
            me->SetFacingTo(1.5009f);
            _scheduler.Schedule(1s, [this](TaskContext task)
            {
                Talk(SAY_TECHNICIAN_SANITRON_DESTROY);
                task.Schedule(2s, [this](TaskContext task)
                {
                    me->SetEmoteState(EMOTE_STATE_USESTANDING);
                    task.Schedule(5s, [this](TaskContext /*task*/)
                    {
                        me->SetWalk(true);
                        me->SetEmoteState(EMOTE_STATE_NONE);
                        me->GetMotionMaster()->MovePoint(POINT_SAFE_TECHNICIAN_FINISH, me->GetHomePosition(), true, me->GetHomePosition().GetOrientation());
                    });
                });
            });
        }
        else if (pointId == POINT_SAFE_TECHNICIAN_FINISH)
        {
            me->SetEmoteState(EMOTE_STATE_WORK_MINING);
            _isEventStarted = false;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    bool _isEventStarted;
};

void AddSC_dun_morogh()
{
    // Creature
    new npc_frozen_mountaineer();
    RegisterCreatureAI(npc_sanitron_5000);
    RegisterCreatureAI(npc_safe_technician_sanitron);
}
