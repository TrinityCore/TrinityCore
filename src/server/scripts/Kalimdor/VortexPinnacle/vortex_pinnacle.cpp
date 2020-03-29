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

#include "ScriptMgr.h"
#include "AreaBoundary.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "vortex_pinnacle.h"

enum Texts
{
    SAY_FEIGN_DEATH = 0
};

enum Spells
{
    // Lurking Tempest
    SPELL_LIGHTNING_BOLT                = 89105,
    SPELL_LURK                          = 85467, // dummy aura while not playing dead
    SPELL_LURK_SEARCH                   = 85294, // periodically triggers either SPELL_LURK_CHECK or SPELL_FEIGN_DEATH_CHECK
    SPELL_LURK_CHECK                    = 85291,
    SPELL_FEIGN_DEATH                   = 85267,
    SPELL_FEIGN_DEATH_CHECK             = 86493,
    SPELL_LURK_RESSURECT                = 85281, // 1250 ms duration, on remove SPELL_LURK (85467) is cast
    SPELL_LURK_FIND_VICTIM              = 86456,

    // Young Storm Dragon
    SPELL_HEALING_WELL                  = 88201,
    SPELL_CHILLING_BLAST                = 88194,

    // Howling Gale
    SPELL_HOWLING_GALE_VISUAL_STRONG    = 85086,
    SPELL_HOWLING_GALE_KNOCKBACK_STRONG = 85159,
    SPELL_HOWLING_GALE_VISUAL_WEAK      = 85137,
    SPELL_HOWLING_GALE_KNOCKBACK_WEAK   = 85085,

    // Slipstream Landing Zone
    SPELL_GENERIC_EJECT_ALL_PASSENGERS  = 79737, // Generic Eject All Passengers - Always Allow

    // Grounding Field
    SPELL_PRISM_BEAMS                   = 87724,
    SPELL_GROUNDING_FIELD               = 87725,

    // Skyfall npc
    SPELL_SKYFALL_VISUAL                = 85719,
    SPELL_SKYFALL                       = 87850,

    // Skyfall Star npc
    SPELL_ARCANE_BARRAGE                = 87845
};

enum Events
{
    EVENT_NONE,

    // Young Storm Dragon
    EVENT_TAKEOFF,
    EVENT_ATTACK,
    EVENT_HEALING_WELL,
    EVENT_CHILLING_BLAST,

    // Grounding Field
    EVENT_CAST_PRISM_BEAMS,

    // Skyfall Star
    EVENT_FLY_RANDOM,

    // Slipstream Landing Zone
    EVENT_EJECT_ALL_PASSENGERS
};

enum Points
{
    POINT_NONE,
    POINT_RANDOM
};

// TO-DO:
// - Grounding Field npc (47085) is broken somewhere, it won't load script assigned in DB. They are summoned in
//       SummonGroundingFieldPrism() void (instance_vortex_pinnacle.cpp), same like Slipstream which acts just fine.

// 45704 - Lurking Tempest
struct npc_lurking_tempest : public ScriptedAI
{
    npc_lurking_tempest(Creature* creature) : ScriptedAI(creature), _summonedByErtan(false) { }

    void Reset() override
    {
        SetCombatMovement(false);
        DoCast(me, SPELL_LURK);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _summonedByErtan = true;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!me->IsInCombat() && me->IsWithinDist(who, _summonedByErtan ? 100.0f : 45.0f) && me->IsValidAttackTarget(who))
            AttackStart(who);
    }

    void JustEngagedWith(Unit* /*target*/) override
    {
        DoCast(me, SPELL_LURK_SEARCH);
    }

    void SpellHit(Unit* /*unit*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_FEIGN_DEATH)
            Talk(SAY_FEIGN_DEATH);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!me->HasAura(SPELL_LURK) || !UpdateVictim())
            return;

        // Just stop combat when target is far away.
        if (!_summonedByErtan && !me->IsWithinDistInMap(me->GetVictim(), 45.0f))
        {
            me->DeleteThreatList();
            me->CombatStop(true);
            return;
        }

        DoSpellAttackIfReady(SPELL_LIGHTNING_BOLT);
    }

private:
    bool _summonedByErtan; // Is it summoned by Grand Vizier Ertan?
};

struct npc_vp_howling_gale : public NullCreatureAI
{
    npc_vp_howling_gale(Creature* creature) : NullCreatureAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->DeleteThreatList();
        me->CombatStop(false);
    }
};

enum Slipstreams
{
    // Spells
    SPELL_SLIPSTREAM_ENTER = 84965,
    SPELL_SLIPSTREAM_FIRST = 84980,
    SPELL_SLIPSTREAM_SECOND = 84988,
    SPELL_SLIPSTREAM_THIRD = 85394,
    SPELL_SLIPSTREAM_FOURTH = 85397,
    SPELL_SLIPSTREAM_LAST = 85016,
    SPELL_SLIPSTREAM_ASAAD = 95911,
    SPELL_SLIPSTREAM_SHORTCUT_ALTAIRUS = 89498,
    SPELL_SLIPSTREAM_SHORTCUT_ASAAD = 89500,
    SPELL_SLIPSTREAM_CONTROL_VEHICLE_FIRST = 84978,
    SPELL_SLIPSTREAM_CONTROL_VEHICLE_SECOND = 84989,
    SPELL_SLIPSTREAM_CONTROL_VEHICLE_THIRD = 85395,
    SPELL_SLIPSTREAM_CONTROL_VEHICLE_FOURTH = 85396,
    SPELL_SLIPSTREAM_CONTROL_VEHICLE_LAST = 85017
};

// 45455 - Slipstream
struct npc_slipstream : public NullCreatureAI
{
    npc_slipstream(Creature* creature) : NullCreatureAI(creature), _instance(me->GetInstanceScript()), _guid(me->GetGUID())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetExtraUnitMovementFlags(MOVEMENTFLAG2_NO_STRAFE | MOVEMENTFLAG2_NO_JUMPING);
    }

    void OnSpellClick(Unit* clicker, bool& result) override
    {
        if (!clicker)
            return;

        if (_instance->GetGuidData(DATA_SLIPSTREAM_ERTAN_1) == _guid || _instance->GetGuidData(DATA_SLIPSTREAM_ALTAIRUS_1) == _guid)
            DoCast(clicker, SPELL_SLIPSTREAM_FIRST);
        else if (_instance->GetGuidData(DATA_SLIPSTREAM_ASAAD_1) == _guid)
            DoCast(clicker, SPELL_SLIPSTREAM_ASAAD);
        else if (_instance->GetGuidData(DATA_SLIPSTREAM_ENTRANCE_1) == _guid)
            DoCast(clicker, SPELL_SLIPSTREAM_SHORTCUT_ALTAIRUS);
        else if (_instance->GetGuidData(DATA_SLIPSTREAM_ENTRANCE_2) == _guid)
            DoCast(clicker, SPELL_SLIPSTREAM_SHORTCUT_ASAAD);

        clicker->CastSpell(me, SPELL_SLIPSTREAM_ENTER);
        result = true;
    }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            return;

        for (AuraEffect const* effect : me->GetAuraEffectsByType(SPELL_AURA_CONTROL_VEHICLE))
        {
            switch (effect->GetSpellInfo()->Id)
            {
            case SPELL_SLIPSTREAM_CONTROL_VEHICLE_FIRST:
                DoCast(who, SPELL_SLIPSTREAM_SECOND);
                break;
            case SPELL_SLIPSTREAM_CONTROL_VEHICLE_SECOND:
                if (_instance->GetGuidData(DATA_SLIPSTREAM_ERTAN_3) == _guid)
                    DoCast(who, SPELL_SLIPSTREAM_LAST);
                else
                    DoCast(who, SPELL_SLIPSTREAM_THIRD);
                break;
            case SPELL_SLIPSTREAM_CONTROL_VEHICLE_THIRD:
                DoCast(who, SPELL_SLIPSTREAM_FOURTH);
                break;
            case SPELL_SLIPSTREAM_CONTROL_VEHICLE_FOURTH:
                DoCast(who, SPELL_SLIPSTREAM_LAST);
                break;
            default:
                break;
            }
        }
    }
private:
    InstanceScript* _instance;
    ObjectGuid _guid;
};

// 45504 - Slipstream Landing Zone (can be converted to SAI later, whatever masters say)
struct npc_slipstream_landing_zone : public ScriptedAI
{
    npc_slipstream_landing_zone(Creature* creature) : ScriptedAI(creature)
    {
        me->SetDisableGravity(true);
        me->SetExtraUnitMovementFlags(MOVEMENTFLAG2_NO_STRAFE | MOVEMENTFLAG2_NO_JUMPING);
    }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (who && apply)
            _events.ScheduleEvent(EVENT_EJECT_ALL_PASSENGERS, 1s + 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_EJECT_ALL_PASSENGERS:
                DoCast(me, SPELL_GENERIC_EJECT_ALL_PASSENGERS);
                break;
            default:
                break;
            }
        }
    }

private:
    EventMap _events;
};

// 45919 - Young Storm Dragon
struct npc_vp_young_storm_dragon : public ScriptedAI
{
    npc_vp_young_storm_dragon(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        _events.Reset();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _EnterEvadeMode();
        me->SetHover(false);
        me->SendMovementSetSplineAnim(Movement::AnimType::ToGround);
        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
        ScriptedAI::EnterEvadeMode(why);
    }

    void JustEngagedWith(Unit* /*target*/) override
    {
        me->AttackStop();
        me->SetReactState(REACT_PASSIVE);
        _events.ScheduleEvent(EVENT_HEALING_WELL, 1ms);
        _events.ScheduleEvent(EVENT_TAKEOFF, 2s + 800ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_TAKEOFF:
            {
                me->SendMovementSetSplineAnim(Movement::AnimType::ToFly);
                me->SetHover(true);
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
                _events.ScheduleEvent(EVENT_ATTACK, 3s);
                break;
            }
            case EVENT_ATTACK:
                me->SetReactState(REACT_AGGRESSIVE);
                _events.RescheduleEvent(EVENT_CHILLING_BLAST, 14s);
                _events.RescheduleEvent(EVENT_HEALING_WELL, 15s);
                break;
            case EVENT_CHILLING_BLAST:
                DoCastVictim(SPELL_CHILLING_BLAST);
                _events.Repeat(14s);
                break;
            case EVENT_HEALING_WELL:
                DoCast(me, SPELL_HEALING_WELL);
                _events.Repeat(15s);
                break;
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

// 47085 - Grounding Field
struct npc_grounding_field : public ScriptedAI
{
    npc_grounding_field(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 action) override
    {
        if (action != ACTION_GROUNDING_FIELD_TOP)
            return;

        DoCast(me, SPELL_GROUNDING_FIELD);
        _events.ScheduleEvent(EVENT_CAST_PRISM_BEAMS, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CAST_PRISM_BEAMS:
                    me->CastStop();
                    DoCast(me, SPELL_PRISM_BEAMS);
                    _events.Repeat(5s);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
};

// 45981 - Skyfall
struct npc_skyfall : public ScriptedAI
{
    npc_skyfall(Creature* creature) : ScriptedAI(creature), _deadStarsCounter(0) { }

    void Reset() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        DoCastSelf(SPELL_SKYFALL_VISUAL);
    }

    void JustEngagedWith(Unit* /*target*/) override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(SPELL_SKYFALL);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_SKYFALL_STAR_DEAD)
        {
            _deadStarsCounter++;
            if (_deadStarsCounter == 8)
                me->DespawnOrUnsummon();
        }
    }

    void UpdateAI(uint32 /*diff*/) override
    {
    }
private:
    uint8 _deadStarsCounter;
};

// 45932 - Skyfall Star
struct npc_skyfall_star : public CreatureAI
{
    npc_skyfall_star(Creature* creature) : CreatureAI(creature) {  }

    void Reset() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*target*/) override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCast(me, SPELL_ARCANE_BARRAGE);
        _events.ScheduleEvent(EVENT_FLY_RANDOM, 1ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature * skyfall = me->FindNearestCreature(NPC_SKYFALL, 100.0f, true))
            skyfall->AI()->DoAction(ACTION_SKYFALL_STAR_DEAD);
        me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType == POINT_MOTION_TYPE || pointId == POINT_RANDOM)
            _events.ScheduleEvent(EVENT_FLY_RANDOM, 1s);
    };

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        uint32 eventId = _events.ExecuteEvent();
        if (!eventId || eventId != EVENT_FLY_RANDOM)
            return;

        // Fly to random near position.
        Position pos = me->GetRandomNearPosition(10.0f);
        pos.m_positionZ += frand(4.0f, 6.0f);
        me->GetMotionMaster()->MovePoint(POINT_RANDOM, pos);
    }

private:
    EventMap _events;
};

enum CatchFall
{
    SPELL_CATCH_FALL_SUMMON = 89522,
    SPELL_CATCH_FALL_TRIGGERED = 89525,
    SPELL_SLIPSTREAM_DUMMY = 85063
};

struct npc_vp_catch_fall : public NullCreatureAI
{
    npc_vp_catch_fall(Creature* creature) : NullCreatureAI(creature) { }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (apply)
            who->m_Events.AddEventAtOffset([who]()
                {
                    if (Creature * vehicle = who->GetVehicleCreatureBase())
                        vehicle->CastSpell(who, SPELL_CATCH_FALL_TRIGGERED, true);
                }, 6s);
        else
            me->DespawnOrUnsummon(400ms);

        who->SetDisableGravity(apply, true);
    }
};

// 85294 - Lurk Search
class spell_lurk_search : public AuraScript
{
    PrepareAuraScript(spell_lurk_search);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_LURK_CHECK,
                SPELL_FEIGN_DEATH_CHECK
            });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Creature* owner = GetOwner()->ToCreature();
        if (!owner)
            return;

        if (owner->HasAura(SPELL_LURK))
        {
            if (owner->IsInCombat())
                owner->CastSpell(owner, SPELL_LURK_CHECK, true);
        }
        else if (owner->HasAura(SPELL_FEIGN_DEATH))
            owner->CastSpell(owner, SPELL_FEIGN_DEATH_CHECK, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_lurk_search::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 85291 - Lurk Search (triggers Feign Death)
// 86493 - Lurk Search (triggers Lurk Ressurect)
class PlayerOrPetOrientationCheck
{
public:
    PlayerOrPetOrientationCheck(Unit* caster) : caster(caster) { }

    bool operator()(WorldObject* object)
    {
        return (!object->ToUnit()->IsCharmedOwnedByPlayerOrPlayer() || !object->isInFront(caster, 2.5f));
    }

private:
    Unit* caster;
};

class spell_lurk_search_check : public SpellScript
{
    PrepareSpellScript(spell_lurk_search_check);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_FEIGN_DEATH,
                SPELL_LURK_RESSURECT
            });
    }

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove_if(PlayerOrPetOrientationCheck(GetCaster()));
        countFacingUnits = unitList.size();
    }

    void OnLaunch(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        switch (GetSpellInfo()->Id)
        {
            case SPELL_LURK_CHECK:
                if (countFacingUnits && !caster->HasAura(SPELL_FEIGN_DEATH))
                    caster->CastSpell(caster, SPELL_FEIGN_DEATH, true);
                break;
            case SPELL_FEIGN_DEATH_CHECK:
                if (!countFacingUnits)
                    caster->CastSpell(caster, SPELL_LURK_RESSURECT, true);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lurk_search_check::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectLaunch += SpellEffectFn(spell_lurk_search_check::OnLaunch, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    uint32 countFacingUnits = 0;
};

// 85267 - Feign Death
class spell_feign_death : public SpellScript
{
    PrepareSpellScript(spell_feign_death);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LURK });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* creature = GetHitUnit()->ToCreature();
        if (!creature)
            return;

        creature->RemoveAurasDueToSpell(SPELL_LURK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_feign_death::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 85281 - Lurk Ressurect
class spell_lurk_ressurect : public AuraScript
{
    PrepareAuraScript(spell_lurk_ressurect);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_LURK,
                SPELL_FEIGN_DEATH,
                SPELL_LURK_SEARCH,
                SPELL_LURK_FIND_VICTIM
            });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Creature* owner = GetOwner()->ToCreature();
        if (!owner)
            return;

        owner->RemoveAurasDueToSpell(SPELL_FEIGN_DEATH);
        owner->RemoveAurasDueToSpell(SPELL_LURK_SEARCH);

        owner->DeleteThreatList();
        owner->CombatStop(true);

        owner->CastSpell(owner, SPELL_LURK_FIND_VICTIM, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature * owner = GetOwner()->ToCreature())
            owner->CastSpell(owner, SPELL_LURK, true);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_lurk_ressurect::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_lurk_ressurect::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 86456 - Lurk Search
class spell_lurk_search_victim : public SpellScript
{
    PrepareSpellScript(spell_lurk_search_victim);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->AddThreat(GetHitUnit(), 0.0f);
        GetCaster()->SetInCombatWith(GetHitUnit());
        GetHitUnit()->SetInCombatWith(GetCaster());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lurk_search_victim::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 85084 - Howling Gale
class spell_vp_howling_gale : public AuraScript
{
    PrepareAuraScript(spell_vp_howling_gale);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HOWLING_GALE_VISUAL_STRONG,
                SPELL_HOWLING_GALE_KNOCKBACK_STRONG,
                SPELL_HOWLING_GALE_VISUAL_WEAK,
                SPELL_HOWLING_GALE_KNOCKBACK_WEAK
            });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetTarget();
        bool weakOrb = GetAura()->IsProcOnCooldown(std::chrono::steady_clock::now());
        caster->CastSpell(caster, weakOrb ? SPELL_HOWLING_GALE_VISUAL_WEAK : SPELL_HOWLING_GALE_VISUAL_STRONG);
        caster->CastSpell(caster, weakOrb ? SPELL_HOWLING_GALE_KNOCKBACK_WEAK : SPELL_HOWLING_GALE_KNOCKBACK_STRONG);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_vp_howling_gale::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 85159, 85085 - Howling Gale
class spell_vp_howling_gale_knockback : public AuraScript
{
    PrepareAuraScript(spell_vp_howling_gale_knockback);

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->ModifyAuraState(AURA_STATE_UNKNOWN22, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->ModifyAuraState(AURA_STATE_UNKNOWN22, false);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_vp_howling_gale_knockback::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_vp_howling_gale_knockback::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 84978, 84989, 85395, 85396, 85017 - Slipstream
class spell_slipstream : public SpellScript
{
    PrepareSpellScript(spell_slipstream);

    void SetTarget(WorldObject*& target)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* slipstream = GetCaster()->GetVehicleCreatureBase();
        if (!slipstream)
            return;

        switch (GetSpellInfo()->Id)
        {
        case SPELL_SLIPSTREAM_CONTROL_VEHICLE_FIRST:
            if (slipstream->GetGUID() == instance->GetGuidData(DATA_SLIPSTREAM_ERTAN_1))
                target = instance->GetCreature(DATA_SLIPSTREAM_ERTAN_2);
            else if (slipstream->GetGUID() == instance->GetGuidData(DATA_SLIPSTREAM_ALTAIRUS_1))
                target = instance->GetCreature(DATA_SLIPSTREAM_ALTAIRUS_2);
            break;
        case SPELL_SLIPSTREAM_CONTROL_VEHICLE_SECOND:
            if (slipstream->GetGUID() == instance->GetGuidData(DATA_SLIPSTREAM_ERTAN_2))
                target = instance->GetCreature(DATA_SLIPSTREAM_ERTAN_3);
            else if (slipstream->GetGUID() == instance->GetGuidData(DATA_SLIPSTREAM_ALTAIRUS_2))
                target = instance->GetCreature(DATA_SLIPSTREAM_ALTAIRUS_3);
            break;
        case SPELL_SLIPSTREAM_CONTROL_VEHICLE_THIRD:
            target = instance->GetCreature(DATA_SLIPSTREAM_ALTAIRUS_4);
            break;
        case SPELL_SLIPSTREAM_CONTROL_VEHICLE_FOURTH:
            target = instance->GetCreature(DATA_SLIPSTREAM_ALTAIRUS_5);
            break;
        case SPELL_SLIPSTREAM_CONTROL_VEHICLE_LAST:
            if (Creature * landingZone = slipstream->FindNearestCreature(NPC_SLIPSTREAM_LANDING_ZONE, 100.0f))
                target = landingZone;
            break;
        default:
            break;
        }
    }
    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_slipstream::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

// 87726 - Grounding Field
class spell_grounding_field : public SpellScript
{
    PrepareSpellScript(spell_grounding_field);

    void GetNearbyGroundFields()
    {
        std::list<Creature*> groundingFields;
        GetCaster()->GetCreatureListWithEntryInGrid(groundingFields, NPC_GROUNDING_FIELD, 60.0f);

        if (groundingFields.size() < 3)
            prevent = true;

        int count = 0;
        for (Creature* groundingField : groundingFields)
        {
            if (GetCaster()->GetGUID() == groundingField->GetGUID())
                continue;

            GroundFieldPositions[count++] = groundingField->GetPosition();
            if (count == 3)
                break;
        }
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        TriangleBoundary triangle(GroundFieldPositions[0], GroundFieldPositions[1], GroundFieldPositions[2], true);
        targets.remove_if([&](WorldObject* target)
            {
                return triangle.IsWithinBoundary(target);
            });
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_grounding_field::GetNearbyGroundFields);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_grounding_field::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
private:
    bool prevent = false;
    Position GroundFieldPositions[3];
};

// 87850 - Skyfall
class spell_skyfall : public SpellScript
{
    PrepareSpellScript(spell_skyfall);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->GetVictim())
            return;

        if (Creature* creature = GetHitCreature())
            creature->CombatStart(caster->GetVictim());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_skyfall::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 88201 - Healing Well
class spell_vp_healing_well : public SpellScript
{
    PrepareSpellScript(spell_vp_healing_well);

    void SetDest(SpellDestination& dest)
    {
        float offset = GetCaster()->GetFloorZ() - GetCaster()->GetPositionZ();
        dest.RelocateOffset({ 0.0f, 0.0f, offset, 0.0f });
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_vp_healing_well::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

Position const EntranceTeleportPos = { -361.0174f,  -6.359375f, 632.7807f, 0.0f };
Position const AltairusTeleportPos = { -906.08f,    -176.514f,  664.5053f, 0.0f };
Position const AsaadTeleportPos = { -1193.67f,   472.835f,   634.8653f, 0.0f };

class spell_vp_catch_fall : public SpellScript
{
    PrepareSpellScript(spell_vp_catch_fall);

    void SetDest(SpellDestination& dest)
    {
        float z = GetCaster()->GetPositionZ();
        float zOffset = 644.926f - z;

        if (z > 680.0f)
            zOffset = 733.072f - z;
        else if (z > 640.0f)
            zOffset = 649.714f - z;

        dest.RelocateOffset({ 0.0f, 0.0f, zOffset, 0.0f });
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_vp_catch_fall::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

class at_vp_catch_fall : public AreaTriggerScript
{
public:
    at_vp_catch_fall() : AreaTriggerScript("at_vp_catch_fall") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
    {
        if (player->HasAura(SPELL_SLIPSTREAM_DUMMY))
            return false;

        player->CastSpell(player, SPELL_CATCH_FALL_SUMMON, true);

        return true;
    }
};

void AddSC_vortex_pinnacle()
{
    RegisterVortexPinnacleCreatureAI(npc_lurking_tempest);
    RegisterVortexPinnacleCreatureAI(npc_vp_howling_gale);
    RegisterVortexPinnacleCreatureAI(npc_slipstream);
    RegisterVortexPinnacleCreatureAI(npc_slipstream_landing_zone);
    RegisterVortexPinnacleCreatureAI(npc_vp_young_storm_dragon);
    RegisterVortexPinnacleCreatureAI(npc_vp_catch_fall);
    RegisterVortexPinnacleCreatureAI(npc_grounding_field);
    RegisterVortexPinnacleCreatureAI(npc_skyfall);
    RegisterVortexPinnacleCreatureAI(npc_skyfall_star);
    RegisterAuraScript(spell_lurk_search);
    RegisterSpellScript(spell_lurk_search_check);
    RegisterSpellScript(spell_feign_death);
    RegisterAuraScript(spell_lurk_ressurect);
    RegisterSpellScript(spell_lurk_search_victim);
    RegisterAuraScript(spell_vp_howling_gale);
    RegisterAuraScript(spell_vp_howling_gale_knockback);
    RegisterSpellScript(spell_slipstream);
    RegisterSpellScript(spell_grounding_field);
    RegisterSpellScript(spell_skyfall);
    RegisterSpellScript(spell_vp_healing_well);
    RegisterSpellScript(spell_vp_catch_fall);
    new at_vp_catch_fall();
}
