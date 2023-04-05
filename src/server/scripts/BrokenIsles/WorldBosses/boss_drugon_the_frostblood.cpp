﻿/*
* Copyright (C) 2021 BfaCore Reforged
* Copyright 2023 AzgathCore
* Copyright 2021 
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
#include "GridNotifiers.h"
#include "CombatAI.h"
#include "PhasingHandler.h"
#include "SpellScript.h"

 // Drugon the Frostblood
class boss_drugon_frostblood : public CreatureScript
{
public:
    boss_drugon_frostblood() : CreatureScript("boss_drugon_frostblood") { }

    struct boss_drugon_frostbloodAI : ScriptedAI
    {
        boss_drugon_frostbloodAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap _events;

        void Reset() override
        {
            me->SetHealth(me->GetMaxHealth());
            me->GetMotionMaster()->MoveTargetedHome();

            _events.Reset();
        }

        //void EnterCombat(Unit* who)
        void JustEngagedWith(Unit* /*who*/) override
        {
            _events.ScheduleEvent(1, Milliseconds(10000));
            _events.ScheduleEvent(3, Milliseconds(15000));
            _events.ScheduleEvent(4, Milliseconds(5000));
            _events.ScheduleEvent(5, Milliseconds(30000));
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            if (why == EvadeReason::NoHostiles)//if (why == EVADE_REASON_NO_HOSTILES)//org
                me->GetMotionMaster()->MoveTargetedHome();
            Reset();

            _EnterEvadeMode();
        }

        void JustDied(Unit* /*killer*/) override
        {

        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
            case 1:
                me->GetMotionMaster()->MoveTargetedHome(); //event 5 and 6
                break;
            default:
                break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            _events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                        me->CastSpell(target, 219803, true);
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                    _events.ScheduleEvent(2, Milliseconds(2000));
                    _events.ScheduleEvent(1, Milliseconds(urand(4000, 7000)));
                    break;
                case 2:
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                    break;
                case 3:
                    DoCast(219493);
                    _events.ScheduleEvent(3, Milliseconds(30000));
                    break;
                case 4:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                        me->CastSpell(target, 219542, true);
                    _events.ScheduleEvent(4, Milliseconds(urand(17000, 22000)));
                    break;
                    
                case 5:
                    //if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))//org
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                    {
                        me->CastSpell(target, 219602, true);
                        me->GetMotionMaster()->MovePoint(1, target->GetPosition());
                        _events.ScheduleEvent(6, Milliseconds(3000));
                        _events.ScheduleEvent(6, Milliseconds(4000));
                        _events.ScheduleEvent(6, Milliseconds(5000));
                        _events.ScheduleEvent(6, Milliseconds(6000));
                        _events.ScheduleEvent(6, Milliseconds(7000));
                        _events.ScheduleEvent(6, Milliseconds(8000));
                        _events.ScheduleEvent(6, Milliseconds(9000));
                        _events.ScheduleEvent(6, Milliseconds(10000));
                    }
                    _events.ScheduleEvent(5, Milliseconds(60000));
                    break;
                case 6:
                {
                    std::list<Unit*> targetList;
                    float radius = 7.f;
                    me->GetAttackableUnitListInRange(targetList, radius);
                    if (!targetList.empty())
                    {
                        for (auto itr : targetList)
                        {
                            if (me->IsValidAttackTarget(itr))
                            {
                                if (itr->HasAura(219602))
                                {
                                    me->CastSpell(itr, 219610, true);
                                    _events.CancelEvent(6);
                                    me->GetMotionMaster()->MoveTargetedHome(); //event 5 and 6
                                }
                                else
                                    me->CastSpell(itr, 219625, true);
                            }
                        }
                    }
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
        return new boss_drugon_frostbloodAI(creature);
    }
};

// 219493
// Snow Crash
class spell_gen_snow_crash : public SpellScriptLoader
{
public:
    spell_gen_snow_crash() : SpellScriptLoader("spell_gen_snow_crash") { }

    class spell_gen_snow_crash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gen_snow_crash_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (caster)
            {
                if (WorldLocation* dest = GetHitDest())
                {
                    //caster->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), 219497, true);//org
                    //caster->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), 219520, true);//org

                    //I wrote these below,may crash
                    //caster->CastSpell(caster, 219497, CastSpellExtraArgs(dest));//Ver 1.0
                    //caster->CastSpell(caster, 219520, CastSpellExtraArgs(dest));

                    caster->CastSpell(CastSpellTargetArg(dest->GetPosition()), 219497);//ver 2.0
                    caster->CastSpell(CastSpellTargetArg(dest->GetPosition()), 219520);
                    
                }
            }
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_gen_snow_crash_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gen_snow_crash_SpellScript();
    }
};


void AddSC_boss_drugon_the_frostblood()
{
    new boss_drugon_frostblood();
    new spell_gen_snow_crash();
}
