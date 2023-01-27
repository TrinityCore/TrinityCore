/*
* Copyright (C) 2021 ShadowCore
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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "castle_nathria.h"

enum Spells
{
    SPELL_GIANT_FISTS_DUMMY = 335297,
    SPELL_GIANT_FISTS_DAMAGE = 335298,
    SPELL_HATEFUL_GAZE_MARK = 331209,
    SPELL_HEADLESS_CHARGE_MAIN = 339067,
    SPELL_HEADLESS_CHARGE_APPLY_AT = 339068, //21486
    SPELL_HEADLESS_CHARGE_CREATE_AT = 339069, //21487
    SPELL_DESTRUCTIVE_IMPACT = 332969,
    SPELL_CRUMBLING_FOUNDATION_PERIODIC = 332443,
    SPELL_CRUMBLING_FOUNDATION_DAMAGE = 332444,
    SPELL_COLLAPSING_FOUNDATION = 332197,
    SPELL_DESTRUCTIVE_STOMP = 332318,
    SPELL_FALLING_RUMBLE_MISSILE = 332552,
    SPELL_STONEQUAKE_AT_DAMAGE = 335361,
    SPELL_STONEQUAKE_CREATE_AT_ONE = 335371,//21139
    SPELL_STONEQUAKE_CREATE_AT_TWO = 348698,//22410
    SPELL_COLOSSAL_ROAR_CAST = 332687,
    SPELL_COLOSSAL_ROAR_DAMAGE = 332698,
    SPELL_GRUESOME_RAGE = 341250,
    //Heroic
    //Mythic
    SPELL_SEISMIC_SHIFT_TRIGGER = 340803,
    SPELL_SEISMIC_SHIFT_DAMAGE = 341087,
    SPELL_SEISMIC_SHIFT_TARGET_DEBUFF = 340817,
    ACTION_PILLAR_HIT,
    ACTION_WALL_HIT,
    EVENT_ENERGY_GAIN = 1,
};

//164407
struct boss_sludgefist : public BossAI
{
    boss_sludgefist(Creature* creature) : BossAI(creature, DATA_SLUDGEFIST) { }

private:
    bool hp30;

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->SetReactState(REACT_DEFENSIVE);
        //me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
        me->CastSpell(nullptr, SPELL_GIANT_FISTS_DUMMY, true);
        if (instance->GetBossState(DATA_COUNCIL_OF_BLOOD) != DONE)
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
        else
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        hp30 = false;
        events.ScheduleEvent(EVENT_ENERGY_GAIN, 1s);
        events.ScheduleEvent(SPELL_COLOSSAL_ROAR_CAST, 1s);
        events.ScheduleEvent(SPELL_GIANT_FISTS_DAMAGE, 2s);
        events.ScheduleEvent(SPELL_FALLING_RUMBLE_MISSILE, 12s);
        events.ScheduleEvent(SPELL_DESTRUCTIVE_STOMP, 17s);
        if (IsMythic())
            events.ScheduleEvent(SPELL_SEISMIC_SHIFT_TRIGGER, 16s);
    }

  //  void ExecuteEvent(uint32 eventId) override
   // {
    //    if (me->GetPower(POWER_ENERGY) == 100)
      //  {
        //    me->SetPower(POWER_ENERGY, 0);
          //  if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
           // {
             //   me->AddAura(SPELL_HATEFUL_GAZE_MARK, target);
              //  me->GetScheduler().Schedule(6100ms, [this, target](TaskContext /*context*/)
                //    {
                  //      if (!target)
                    //        return;

                      //  me->AddAura(SPELL_HEADLESS_CHARGE_APPLY_AT);
                      //  me->GetMotionMaster()->MoveCharge(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 20.0f, 0, true);
                   // });
          //  }
       // }
        //switch (eventId)
        //{
       // case EVENT_ENERGY_GAIN:
         //   me->ModifyPower(POWER_ENERGY, +2);
           // events.Repeat(1s);
           // break;

       // case SPELL_GIANT_FISTS_DAMAGE:
         //   if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 10.0f))
    //        {
    //            if (target->SelectNearestPlayer(10.0f))
     //               me->CastSpell(target, SPELL_GIANT_FISTS_DAMAGE, true);
       //         else
         //       {
           //         me->CastSpell(target, SPELL_GIANT_FISTS_DAMAGE, true);
             //       me->CastSpell(target, SPELL_GIANT_FISTS_DAMAGE, true);
               // }
 //           }
   //         events.Repeat(2s);
     //       break;

       // case SPELL_DESTRUCTIVE_STOMP:
         //   me->CastSpell(nullptr, SPELL_DESTRUCTIVE_STOMP, false);
           // events.Repeat(20s, 25s);
          //  break;
/*
        case SPELL_FALLING_RUMBLE_MISSILE:
        {
            UnitList targetList;
            SelectTargetList(targetList, 5, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->CastSpell(targets, SPELL_FALLING_RUMBLE_MISSILE, true);
                me->CastSpell(targets, SPELL_STONEQUAKE_CREATE_AT_ONE, true);
                me->CastSpell(targets, SPELL_STONEQUAKE_CREATE_AT_TWO, true);
            }
            events.Repeat(15s, 18s);
            break;
        }

        case SPELL_COLOSSAL_ROAR_CAST:
            me->CastSpell(nullptr, SPELL_COLOSSAL_ROAR_CAST, false);
            events.Repeat(30s);
            break;

        case SPELL_SEISMIC_SHIFT_TRIGGER:
            me->CastSpell(nullptr, SPELL_SEISMIC_SHIFT_TRIGGER, true);
            events.Repeat(28s);
            break;
        }
    }
  */  
    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_COLOSSAL_ROAR_CAST:
        {
            me->CastSpell(nullptr, SPELL_COLOSSAL_ROAR_DAMAGE, true);
            break;
        }
        case SPELL_SEISMIC_SHIFT_TRIGGER:
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 100.0f);
            for (Player* targets : playerList)
            {
                me->AddAura(SPELL_SEISMIC_SHIFT_TARGET_DEBUFF, targets);
                targets->GetScheduler().Schedule(4100ms, [this, targets](TaskContext /*context*/)
                    {
                        if (!targets)
                            return;

                        me->CastSpell(targets, SPELL_SEISMIC_SHIFT_DAMAGE, true);
                    });
            }
            break;
        }
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPct(30) && !hp30)
        {
            hp30 = true;
            me->CastSpell(nullptr, SPELL_GRUESOME_RAGE, true);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_PILLAR_HIT:
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 100.0f);
            for (Player* targets : playerList)
            {
                me->AddAura(SPELL_CRUMBLING_FOUNDATION_PERIODIC, targets);
            }
            break;
        }
        case ACTION_WALL_HIT:
            me->CastSpell(nullptr, SPELL_COLLAPSING_FOUNDATION, true);
            break;
        }
    }


    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        me->RemoveAllAreaTriggers();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*victim*/) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
    }
};

//339068, experimental part
struct at_headless_charge : public AreaTriggerAI
{
    at_headless_charge(AreaTrigger* at) : AreaTriggerAI(at) { }

private:
    bool pillarCharged;
    bool wallHit;

    void OnCreate() override
    {
        pillarCharged = false;
        wallHit = false;
    }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (at->GetCaster())
            at->GetCaster()->CastSpell(target, SPELL_HEADLESS_CHARGE_MAIN, true);

        if (pillarCharged || wallHit)
            return;

        std::list<Player*> playerList;
        at->GetPlayerListInGrid(playerList, 10.0f);
        if (playerList.size() >= 5)
        {
            pillarCharged = true;
            at->GetCaster()->RemoveAura(SPELL_HEADLESS_CHARGE_APPLY_AT);
            at->GetCaster()->GetAI()->DoAction(ACTION_PILLAR_HIT);
        }
    }
};

//335371
struct at_stonequake : public AreaTriggerAI
{
    at_stonequake(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(360000);
    }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (at->GetCaster())
            at->GetCaster()->AddAura(SPELL_STONEQUAKE_AT_DAMAGE, target);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_STONEQUAKE_AT_DAMAGE))
            target->RemoveAura(SPELL_STONEQUAKE_AT_DAMAGE);
    }
};

void AddSC_boss_sludgefist()
{
    RegisterCreatureAI(boss_sludgefist);
    RegisterAreaTriggerAI(at_headless_charge);
    RegisterAreaTriggerAI(at_stonequake);
}
