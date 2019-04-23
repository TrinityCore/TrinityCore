/*
* Copyright (C) 2008-2019 by MAGICSTORM
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "Player.h"
#include "SpellInfo.h"
#include "WorldSession.h"
#include "SpellScript.h"
#include "MoveSpline.h"
#include "MoveSplineFlag.h"
#include "MoveSplineInit.h"
#include "Conversation.h"
#include "Group.h"
#include "GroupMgr.h"
#include "Vehicle.h"
#include "GridNotifiersImpl.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerPackets.h"
 
Position const Waypointspawn[6] =
{
 { -1110.553f, 6949.951f, 0.0006f },
 { -1082.276f, 7001.35f, 0.0006f },
 { -1131.501f, 7029.581f, 0.0006f },
 { -1175.358f, 6998.841f, 0.0006f },
 { -1173.099f, 6950.416f, 0.0006f },
 { -1106.778f, 6947.764f, 0.0006f },
};

class boss_levantus : public CreatureScript
{
public:
    boss_levantus() : CreatureScript("boss_levantus") { }

    struct boss_levantusAI : ScriptedAI
    {
        boss_levantusAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap _events;

        void Reset() override
        {
            me->SetControlled(true, UNIT_STATE_ROOT);
            me->SetHealth(me->GetMaxHealth());
            me->GetMotionMaster()->MoveTargetedHome();

            _events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            _events.ScheduleEvent(1, 5000);
            _events.ScheduleEvent(2, 8000);
            _events.ScheduleEvent(4, 35000);
            _events.ScheduleEvent(5, 15000);
            _events.ScheduleEvent(6, 25000);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->SetControlled(false, UNIT_STATE_ROOT);
            me->GetMotionMaster()->MoveTargetedHome();
            Reset();

            _EnterEvadeMode();
        }

        void JustDied(Unit* killer) override
        {
        }

        void UpdateAI(uint32 diff)
        {
            _events.Update(diff);

            if (!UpdateVictim())
                return;

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                {
                    for (uint32 i = 1; i < 7; i++) // +1
                    {
                        me->CastSpell(Waypointspawn[i].GetPositionX() + urand(0, 25), Waypointspawn[i].GetPositionY() + urand(0, 25), Waypointspawn[i].GetPositionZ(), 217212, true);
                    }

                    _events.ScheduleEvent(1, 10000);
                    break;
                }
                case 2:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(target, 217361, true);
                    _events.ScheduleEvent(2, 5000);
                    break;
                case 3:
                    if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                        me->CastSpell(target, 217229, true);
                    break;
                case 4:
                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST))
                    {
                        if (target->GetDistance(me) < 30)
                            me->CastSpell(target, 217249, true); // todo
                        else
                            _events.ScheduleEvent(3, 1000);
                    }
                    _events.ScheduleEvent(4, 60000);
                    break;
                case 5:
                {
                    DoCast(217344);
                    _events.ScheduleEvent(5, 30000);
                    break;
                }
                case 6:
                {
                    DoCast(217235);
                    _events.ScheduleEvent(6, 30000);
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
        return new boss_levantusAI(creature);
    }
};

class areatrigger_gen_gust_of_wind : public AreaTriggerEntityScript
{
public:
    areatrigger_gen_gust_of_wind() : AreaTriggerEntityScript("areatrigger_gen_gust_of_wind") { }

    struct areatrigger_gen_gust_of_windAI : AreaTriggerAI
    {
        areatrigger_gen_gust_of_windAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger), _areatrigger(areatrigger) { }

        void OnInitialize() override
        {
            timer = 0.5 * IN_MILLISECONDS;
        }

        void OnUpdate(uint32 diff) override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (timer <= diff)
            {
                std::list<Unit*> targetList;
                float radius = 5.0f;

                Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(_areatrigger, caster, radius);
                Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(_areatrigger, targetList, u_check);
                Cell::VisitAllObjects(_areatrigger, searcher, radius);

                if (!targetList.empty())
                    for (auto itr : targetList)
                    {
                        if (!itr->HasAura(217206))
                            itr->CastSpell(itr, 217206, true);
                    }

                timer = 0.5 * IN_MILLISECONDS;
            }
            else
                timer -= diff;
        }

    private:
        uint32 timer;
        AreaTrigger* _areatrigger;
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_gen_gust_of_windAI(areatrigger);
    }
};

class areatrigger_gen_electrify : public AreaTriggerEntityScript
{
public:
    areatrigger_gen_electrify() : AreaTriggerEntityScript("areatrigger_gen_electrify") { }

    struct areatrigger_gen_electrifyAI : AreaTriggerAI
    {
        areatrigger_gen_electrifyAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger), _areatrigger(areatrigger) { }

        void OnInitialize() override
        {
            timer = 2 * IN_MILLISECONDS;
        }

        void OnUpdate(uint32 diff) override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (timer <= diff)
            {
                std::list<Unit*> targetList;
                float radius = 100.0f;

                caster->GetAttackableUnitListInRange(targetList, radius);

                if (!targetList.empty())

                    for (auto itr : targetList)
                    {
                        if (!itr->HasAura(217352) && itr->IsInWater())
                            itr->CastSpell(itr, 217352, true);
                    }
                _areatrigger->Remove();
            }
            else
                timer -= diff;
        }

    private:
        uint32 timer;
        AreaTrigger* _areatrigger;
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_gen_electrifyAI(areatrigger);
    }
};

class areatrigger_gen_massive_spout : public AreaTriggerEntityScript
 {
public:
    areatrigger_gen_massive_spout() : AreaTriggerEntityScript("areatrigger_gen_massive_spout") { }

    struct areatrigger_gen_massive_spoutAI : AreaTriggerAI
    {
        areatrigger_gen_massive_spoutAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger), _areatrigger(areatrigger) { }

        void OnInitialize() override
        {
            timer = 2 * IN_MILLISECONDS;
        }

        void OnUpdate(uint32 diff) override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;


            if (timer <= diff)
            {
                std::list<Unit*> targetList;
                float radius = 200.0f; // 217277

                caster->GetAttackableUnitListInRange(targetList, radius);
 
                if (!targetList.empty())
                    for (auto itr : targetList)
                    {
                        if (caster->isInFront(itr))
                            caster->CastSpell(itr, 217277, true);
                    }
                timer = 2 * IN_MILLISECONDS;
            }
            else
                timer -= diff;

        }

    private:
        uint32 timer;
        AreaTrigger* _areatrigger;
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override

    {
        return new areatrigger_gen_massive_spoutAI(areatrigger);
    }
};

void AddSC_boss_levantus()
{
    new boss_levantus();
    new areatrigger_gen_gust_of_wind();
    new areatrigger_gen_electrify();
    new areatrigger_gen_massive_spout();

}

