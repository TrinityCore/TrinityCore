/*
 * Copyright 2021 BfaCore
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
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "uldir.h"

const Position middle_pos = { -268.0f, -255.0f, 695.302f, 3.27f };
const Position cudgel_retrive_pos = { -296.0f, -250.0f, 695.538f, 3.14f };

//Weapon ID 160116

enum Texts
{
    SAY_DEPLOY_CUDGEL = 1,
    SAY_RETRIEVE_CUDGEL = 0,
    SAY_POWERED_DOWN = 2,
    SAY_DEATH,
    SAY_AGGRO = 4,
    SAY_PLASMA_DISCHARGE,
    SAY_POWERED_DOWN_ENDS = 7,
    SAY_WIPE = 9,
};

enum Spells
{
    //Phase one
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
	SPELL_PLASMA_DISHARGE_DUMMY = 271222,
    SPELL_PLASMA_DISCHARGE_PERIODIC = 278889, //137578
    SPELL_PLASMA_AT_DAMAGE = 271225,
	SPELL_BLOOD_STORM_AT_DAMAGE = 270290,
	SPELL_CUDGEL_OF_GORE_CHARGE  = 271296, //138017
    SPELL_CUDGEL_OF_GORE_DAMAGE_KNOCK = 271811,
	SPELL_SANGUINE_STATIC = 272582,
	SPELL_POWERED_DOWN    = 271965,
    //Phase two
	SPELL_RETRIEVE_CUDGEL = 271728,	
	SPELL_COMBUSTIBLE_FUEL = 272584,
	SPELL_SLOUGH_OFF       = 273179,
    SPELL_ULDIR_DEFENSIVE_BEAM_MAIN = 275441, //npc 1402846 is using this // visual which triggering also fast periodic aura damage
	SPELL_ULDIR_DEFENSIVE_BEAM_CREATE_AT = 274921,
    SPELL_ULDIR_DEFENSIVE_BEAM_DAMAGE = 268253,
    //Mythic
    SPELL_ENLARGED_HEART = 275205, //tank
    SPELL_HARDENED_ARTERIES_DEBUFF = 275189,
    SPELL_HARDENED_ARTERIES_EXP = 275193,
};

enum Events
{
    EVENT_PLASMA_DISCHARGE = 1,
    EVENT_CUDGEL_OF_GORE,
    EVENT_INIT_PHASE_TWO,
    EVENT_MYTHIC_MECHANICS,
    EVENT_ULDIR_DEFENSIVE_BEAM
};

//137119
struct boss_taloc : public BossAI
{
    boss_taloc(Creature* creature) : BossAI(creature, DATA_TALOC) { }

private:
    Vehicle* vehicle;

    void Reset() override
    {
        BossAI::Reset();
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);       
        me->SetCurrentEquipmentId(0);
        me->RemoveAllAreaTriggers();
        phase_one = false;
        phase_two = false;
        vehicle = me->GetVehicleKit();
        me->SetCurrentEquipmentId(2);
    };

    void EnterCombat(Unit* u) override
    {        
        _EnterCombat();
        Talk(SAY_AGGRO);
        phase_one = true;
        me->SetHealth(me->CountPctFromMaxHealth(60));
        DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);
        events.ScheduleEvent(EVENT_PLASMA_DISCHARGE, 5s);
        events.ScheduleEvent(EVENT_CUDGEL_OF_GORE, 50s);
        if (IsMythic())
        {
            events.ScheduleEvent(EVENT_MYTHIC_MECHANICS, 12s);
        }
    }

    void DamageTaken(Unit* done_by, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(35) && !phase_two)
        {            
            phase_two = true;
            events.CancelEvent(EVENT_PLASMA_DISCHARGE);
            events.CancelEvent(EVENT_CUDGEL_OF_GORE);
            events.CancelEvent(EVENT_MYTHIC_MECHANICS);
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->MovePoint(1, middle_pos, true);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade();
        me->RemoveAllAreaTriggers();
        if (GameObject* taloc_elevator = me->GetGameObject(GO_TALOC_ELEVATOR))
        {
            taloc_elevator->SetTransportState(GO_STATE_TRANSPORT_STOPPED);
        }
    }

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (uiPointId == 1)
        {
            Talk(SAY_POWERED_DOWN);
            me->CastSpell(me, SPELL_POWERED_DOWN);
            me->SetReactState(REACT_PASSIVE);
            //me->HandleEmoteCommand();
            events.ScheduleEvent(EVENT_INIT_PHASE_TWO, 20s);
        }

        if (uiPointId == 2)
        {
            Talk(SAY_RETRIEVE_CUDGEL);

            if (Creature* cudgel = me->FindNearestCreature(138070, 100.0f, true))
            {
                cudgel->EnterVehicle(me);
                cudgel->SetVisible(false);
                me->SetCurrentEquipmentId(1);
                if (Unit* tar = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                {
                    me->SetFacingToObject(tar, true);
                    DoCast(tar, SPELL_CUDGEL_OF_GORE_CHARGE);
                    me->GetScheduler().Schedule(3s, [this, tar](TaskContext context)
                    {
                        DoCast(tar, SPELL_CUDGEL_OF_GORE_DAMAGE_KNOCK);
                    });
                }
            }
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_PLASMA_DISCHARGE:
        {            
            UnitList list;
            SelectTargetList(list, 3, SELECT_TARGET_RANDOM, 500.0f, true);
            for (Unit* tar : list)
            {
                Talk(SAY_PLASMA_DISCHARGE);
                me->AddAura(SPELL_PLASMA_DISCHARGE_PERIODIC, tar);
            }
            events.Repeat(20s);
            break;
        }
        case EVENT_CUDGEL_OF_GORE:
        {
            if (me->GetPower(POWER_ENERGY) == 100)
            {
                me->SetPower(POWER_ENERGY, 0);
                me->GetMotionMaster()->MovePoint(2, cudgel_retrive_pos, true);
            }
            events.Repeat(30s);
            break;
        }
        case EVENT_INIT_PHASE_TWO:
        {
            phase_one = true;
            me->RemoveAura(SPELL_POWERED_DOWN);
            Talk(SAY_POWERED_DOWN_ENDS);
            me->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_PLASMA_DISCHARGE, 5s);
            events.ScheduleEvent(EVENT_CUDGEL_OF_GORE, 50s);
            if (IsMythic())
            {
                events.ScheduleEvent(EVENT_MYTHIC_MECHANICS, 12s);
            }
            break;
        }
        case EVENT_MYTHIC_MECHANICS:
        {
            DoCastVictim(SPELL_ENLARGED_HEART);
            UnitList list;
            SelectTargetList(list, 10, SELECT_TARGET_RANDOM, 500.0f, true);
            for (Unit* targets : list)
            {  
                me->AddAura(SPELL_HARDENED_ARTERIES_DEBUFF, targets);
                me->GetScheduler().Schedule(8s, [this, targets] (TaskContext context)
                {
                    DoCast(targets, SPELL_HARDENED_ARTERIES_EXP);
                });
            }
            events.Repeat(35s);
            break;
        }
        case EVENT_ULDIR_DEFENSIVE_BEAM:
            if (IsHeroic() || IsMythic())
            {
                std::list<Creature*> uldir_defensive_beam;
                me->GetCreatureListWithEntryInGrid(uldir_defensive_beam, 140286, 500.0f);
                for (auto& beams : uldir_defensive_beam)
                {
                    me->AddAura(SPELL_ULDIR_DEFENSIVE_BEAM_MAIN, beams);
                }
            }
            break;
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        Talk(SAY_WIPE);
        me->RemoveAllAreaTriggers();
    }

    void JustDied(Unit* u) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        me->RemoveAllAreaTriggers();
        if (GameObject* taloc_elevator = me->GetGameObject(GO_TALOC_ELEVATOR))
        {
            taloc_elevator->SetTransportState(GO_STATE_TRANSPORT_ACTIVE);
        }
    }

private:
    bool phase_one;
    bool phase_two;
};

//270449
class spell_plasma_discharge : public SpellScript
{
    PrepareSpellScript(spell_plasma_discharge);

    void Damage()
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->GetMap()->IsMythic())
            {
                int32 MythicValue = 49784;
                SetHitDamage(MythicValue);
            }
            if (caster->GetMap()->IsHeroic())
            {
                int32 HeroicValue = 36719;
                SetHitDamage(HeroicValue);
            }
            if (caster->GetMap()->IsLFR())
            {
                int32 NormalValue = 26242;
                SetHitDamage(NormalValue);
            }
        }
    };

    void Register() override
    {
        OnHit += SpellHitFn(spell_plasma_discharge::Damage);
    }
};

//137578
struct npc_blood_storm : public ScriptedAI
{
    npc_blood_storm(Creature* creature) : ScriptedAI(creature)
    {
        creature->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
    }
};

void AddSC_boss_taloc()
{
    RegisterCreatureAI(boss_taloc);
    RegisterSpellScript(spell_plasma_discharge);
    RegisterCreatureAI(npc_blood_storm);
}