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

#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SharedDefines.h"
#include "Vehicle.h"
#include "scarlet_halls.h"

enum HarlanSpells
{
    // Armsmaster Harlan
    SPELL_HARLAN_DRAGONS_REACH              = 111217,
    SPELL_HARLAN_CALL_REINFORCEMENT         = 111755,
    SPELL_HARLAN_HEROIC_LEAP_JUMP           = 111219,
    SPELL_HARLAN_BERSERKERS_RAGE            = 111221,
    SPELL_HARLAN_BLADES_OF_LIGHT_CAST       = 111216,
    SPELL_HARLAN_BLADES_OF_LIGHT_VEHICLE    = 112955,
    SPELL_HARLAN_BLADES_OF_LIGHT_DAMAGE     = 111215,
    SPELL_HARLAN_LEAVE_VEHICLE              = 112953,

    // Scarlet Defender
    SPELL_SCARLET_DEFENDER_UNARMORED        = 113969
};

enum HarlanEvents
{
    EVENT_HARLAN_DRAGONS_REACH          = 1,
    EVENT_HARLAN_CALL_FOR_HELP,
    EVENT_HARLAN_HEROIC_LEAP,
    EVENT_HARLAN_BERSERKER_RAGE,
    EVENT_HARLAN_BLADES_OF_LIGHT,
    EVENT_HARLAN_CALL_REINFORCEMENT,
    EVENT_HARLAN_FINISH_BLADES_OF_LIGHT,
};

enum HarlanTexts
{
    SAY_HARLAN_AGGRO                    = 0,
    SAY_HARLAN_CALL_FOR_HELP            = 1,
    ANNOUNCE_HARLAN_CALL_FOR_HELP       = 2,
    ANNOUNCE_HARLAN_BLADE_FOR_LIGHT     = 3,
    SAY_HARLAN_DEATH                    = 4
};

enum HarlanPathIds
{
    PATH_HARLAN_BLADES_OF_LIGHT_LEFT    = 5863200,
    PATH_HARLAN_BLADES_OF_LIGHT_RIGHT   = 5863201
};

// 58632 - Armsmaster Harlan
struct boss_armsmaster_harlan : public BossAI
{
    boss_armsmaster_harlan(Creature* creature) : BossAI(creature, DATA_ARMSMASTER_HARLAN), _berserkerRage(false) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_HARLAN_AGGRO);
        events.ScheduleEvent(EVENT_HARLAN_DRAGONS_REACH, 7s);
        events.ScheduleEvent(EVENT_HARLAN_CALL_FOR_HELP, 20s);
        events.ScheduleEvent(EVENT_HARLAN_HEROIC_LEAP, 41s);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void Reset() override
    {
        _Reset();
        _berserkerRage = false;
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_HARLAN_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == EVENT_JUMP)
        {
            me->SetReactState(REACT_PASSIVE);
            Talk(ANNOUNCE_HARLAN_BLADE_FOR_LIGHT);
            events.CancelEvent(EVENT_HARLAN_DRAGONS_REACH);
            events.CancelEvent(EVENT_HARLAN_CALL_FOR_HELP);
            events.CancelEvent(EVENT_HARLAN_HEROIC_LEAP);
            DoCastSelf(SPELL_HARLAN_BLADES_OF_LIGHT_CAST);
        }
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_berserkerRage && me->HealthBelowPctDamaged(50, damage))
        {
            _berserkerRage = true;
            DoCastSelf(SPELL_HARLAN_BERSERKERS_RAGE);
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        events.ScheduleEvent(EVENT_HARLAN_FINISH_BLADES_OF_LIGHT, 1s);
        events.ScheduleEvent(EVENT_HARLAN_DRAGONS_REACH, 6s);
        events.ScheduleEvent(EVENT_HARLAN_CALL_FOR_HELP, 19s);
        events.ScheduleEvent(EVENT_HARLAN_HEROIC_LEAP, 29s);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HARLAN_DRAGONS_REACH:
                    DoCastVictim(SPELL_HARLAN_DRAGONS_REACH);
                    events.ScheduleEvent(EVENT_HARLAN_DRAGONS_REACH, 7s);
                    break;
                case EVENT_HARLAN_CALL_FOR_HELP:
                    Talk(SAY_HARLAN_CALL_FOR_HELP);
                    events.ScheduleEvent(EVENT_HARLAN_CALL_REINFORCEMENT, 4s);
                    break;
                case EVENT_HARLAN_HEROIC_LEAP:
                    DoCast(SPELL_HARLAN_HEROIC_LEAP_JUMP);
                    break;
                case EVENT_HARLAN_CALL_REINFORCEMENT:
                    Talk(ANNOUNCE_HARLAN_CALL_FOR_HELP);
                    DoCast(SPELL_HARLAN_CALL_REINFORCEMENT);
                    events.ScheduleEvent(EVENT_HARLAN_CALL_FOR_HELP, 20s);
                    break;
                case EVENT_HARLAN_FINISH_BLADES_OF_LIGHT:
                    me->RemoveAurasDueToSpell(SPELL_HARLAN_BLADES_OF_LIGHT_CAST);
                    me->SetHover(false);
                    DoCastSelf(SPELL_HARLAN_LEAVE_VEHICLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
private:
    bool _berserkerRage;
};

// 111216 - Blades of Light
class spell_harlan_blades_of_light : public SpellScript
{
    void HandleAfterCast()
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        caster->GetMotionMaster()->Clear();
        caster->SetHover(true);

        if (urand(0, 1) == 0)
            caster->GetMotionMaster()->MovePath(PATH_HARLAN_BLADES_OF_LIGHT_LEFT, false);
        else
            caster->GetMotionMaster()->MovePath(PATH_HARLAN_BLADES_OF_LIGHT_RIGHT, false);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_harlan_blades_of_light::HandleAfterCast);
    }
};

// 111394 - Blades of Light
class spell_harlan_blades_of_light_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HARLAN_BLADES_OF_LIGHT_CAST });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->HasAuraType(AuraType::SPELL_AURA_SPIRIT_OF_REDEMPTION))
            return;

        GetHitUnit()->CastSpell(GetCaster(), SPELL_HARLAN_BLADES_OF_LIGHT_VEHICLE, true);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_HARLAN_BLADES_OF_LIGHT_DAMAGE, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_harlan_blades_of_light_selector::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 112953 - Leave Vehicle
class spell_harlan_leave_vehicle : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->ExitVehicle();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_harlan_leave_vehicle::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 113959 - Heavy Armor
class spell_scarlet_defender_heavy_armor : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SCARLET_DEFENDER_UNARMORED);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_scarlet_defender_heavy_armor::OnRemove, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

constexpr Position CallReinforcmentsRightPosition = { 1182.020f, 447.325f, 11.98933f };
constexpr Position CallReinforcmentsLeftPosition = { 1181.833f, 440.649f, 11.98763f };

// 111755 - Call Reinforcements
class spell_call_reinforcements_right : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(CallReinforcmentsRightPosition);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_call_reinforcements_right::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

// 111756 - Call Reinforcements
class spell_call_reinforcements_left : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(CallReinforcmentsLeftPosition);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_call_reinforcements_left::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

// 128930 - Eject Spirits of Redemption
class spell_eject_spirits_of_redemption : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        Vehicle* veh = GetCaster()->GetVehicleKit();
        if (!veh)
            return;

        for (auto const& [_, seat] : veh->Seats)
        {
            Unit* passenger = ObjectAccessor::GetUnit(*GetCaster(), seat.Passenger.Guid);
            if (!passenger)
                continue;

            if (passenger->HasAuraType(AuraType::SPELL_AURA_SPIRIT_OF_REDEMPTION))
                passenger->ExitVehicle();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_eject_spirits_of_redemption::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_armsmaster_harlan()
{
    // Creature
    RegisterScarletHallsCreatureAI(boss_armsmaster_harlan);

    // Spells
    RegisterSpellScript(spell_harlan_blades_of_light);
    RegisterSpellScript(spell_harlan_blades_of_light_selector);
    RegisterSpellScript(spell_harlan_leave_vehicle);
    RegisterSpellScript(spell_scarlet_defender_heavy_armor);
    RegisterSpellScript(spell_call_reinforcements_right);
    RegisterSpellScript(spell_call_reinforcements_left);
    RegisterSpellScript(spell_eject_spirits_of_redemption);
}
