/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "Vehicle.h"
#include "blackwing_descent.h"

enum Spells
{
    // Magmaw
    SPELL_RIDE_VEHICLE                          = 77901,
    SPELL_BIRTH                                 = 26586,
    SPELL_MAGMA_SPIT_TARGETING                  = 95280,
    SPELL_MAGMA_SPIT_MISSILE                    = 78359,
    SPELL_LAVA_SPEW                             = 77839,
    SPELL_MAGMA_SPIT_MOLTEN_TANTRUM             = 78068,
    SPELL_MANGLE_1                              = 89773,
    SPELL_MANGLE_2                              = 78412,
    SPELL_MANGLE_TARGETING                      = 92047,
    SPELL_SWELTERING_ARMOR                      = 78199,
    SPELL_PILLAR_OF_FLAME                       = 77998,
    SPELL_PILLAR_OF_FLAME_MISSILE_PERIODIC      = 78006,
    SPELL_MASSIVE_CRASH                         = 88253,
    SPELL_IMPALE_SELF                           = 77907,
    SPELL_EJECT_PASSENGER_3                     = 95204,

    // Exposed Head of Magmaw
    SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE   = 79010,
    SPELL_POINT_OF_VULNERABILITY                = 79011,
    SPELL_RIDE_VEHICLE_EXPOSED_HEAD             = 89743,
    SPELL_QUEST_INVIS_5                         = 95478,
    SPELL_RIDE_VEHICLE_HEAD                     = 94996,

    // Pillar of Flame
    SPELL_PILLAR_OF_FLAME_DUMMY                 = 78017,
    SPELL_PILLAR_OF_FLAME_PERIODIC              = 77970,

    // Magmaw's Pincer
    SPELL_LAUNCH_HOOK_1                         = 77917,
    SPELL_LAUNCH_HOOK_2                         = 77941,
    SPELL_EJECT_PASSENGER_1                     = 77946,

    // Magmaw Spike Stalker
    SPELL_CHAIN_VISUAL_1                        = 77940,
    SPELL_CHAIN_VISUAL_2                        = 77929,
};

enum Events
{
    // Magmaw
    EVENT_MAGMA_PROJECTILE = 1,
    EVENT_LAVA_SPEW,
    EVENT_MANGLE,
    EVENT_PREPARE_MASSIVE_CRASH,
    EVENT_MASSIVE_CRASH,
    EVENT_ANNOUNCE_PINCERS_EXPOSED,
    EVENT_FINISH_MASSIVE_CRASH,
    EVENT_IMPALE_SELF,
    EVENT_EJECT_PASSENGER_1,
    EVENT_EXPOSE_HEAD,
    EVENT_HIDE_HEAD,
    EVENT_FINISH_IMPALE_SELF,
};

enum Actions
{
    ACTION_IMPALE_MAGMAW = 0
};

enum Texts
{
    // Magmaw
    SAY_ANNOUNCE_LAVA_PARASITES = 0,
    SAY_ANNOUNCE_EXPOSE_PINCERS = 1,
    SAY_ANNOUNCE_EXPOSED_HEAD   = 2
};

enum VehicleSeats
{
    SEAT_MAGMAWS_PINCER_1           = 0,
    SEAT_MAGMAWS_PINCER_2           = 1,
    SEAT_EXPOSED_HEAD_OF_MAGMAW_1   = 3,
    SEAT_EXPOSED_HEAD_OF_MAGMAW_2   = 4,
};

enum Data
{
    DATA_FREE_PINCER = 0
};

Position const ExposedHeadOfMagmawPos = { -299.0f, -28.9861f, 191.0293f, 4.118977f };

struct boss_magmaw : public BossAI
{
    boss_magmaw(Creature* creature) : BossAI(creature, DATA_MAGMAW)
    {
        Initialize();
    }

    void Initialize()
    {
        _magmaProjectileCount = 0;
        _exposedHead1 = nullptr;
        _exposedHead2 = nullptr;
        _pincer1 = nullptr;
        _pincer2 = nullptr;
        _hasExposedHead = false;
        _headEngaged = false;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
    }

    void JustAppeared() override
    {
        SetupBody();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_MAGMA_PROJECTILE, 5s, 6s);
        events.ScheduleEvent(EVENT_LAVA_SPEW, 19s);
        //events.ScheduleEvent(EVENT_MANGLE, 1min + 30s);
        events.ScheduleEvent(EVENT_PREPARE_MASSIVE_CRASH, 10s);

        _exposedHead1->SetInCombatWithZone();
        _exposedHead2->SetInCombatWithZone();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (_headEngaged)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, _exposedHead1);
        instance->SetData(DATA_MAGMAW, FAIL);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_headEngaged)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, _exposedHead1);
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        switch (summon->GetEntry())
        {
            case NPC_PILLAR_OF_FLAME:
                summon->CastSpell(summon, SPELL_PILLAR_OF_FLAME_DUMMY);
                summon->SetDisplayId(summon->GetCreatureTemplate()->Modelid1);
                summon->DespawnOrUnsummon(7s);
                Talk(SAY_ANNOUNCE_LAVA_PARASITES);
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_MASSIVE_CRASH:
            {
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
                _exposedHead1->CastSpell(_exposedHead1, SPELL_RIDE_VEHICLE_HEAD, true);
                events.ScheduleEvent(EVENT_ANNOUNCE_PINCERS_EXPOSED, 1s);
                events.ScheduleEvent(EVENT_FINISH_MASSIVE_CRASH, 7s);
                Unit* head = _exposedHead1;
                head->m_Events.AddEventAtOffset([head]()
                {
                    head->CastSpell(head, SPELL_RIDE_VEHICLE_EXPOSED_HEAD, true);
                }, 6s);

                break;
            }
            case SPELL_IMPALE_SELF:
                DoCastSelf(SPELL_EJECT_PASSENGER_3);
                Talk(SAY_ANNOUNCE_EXPOSED_HEAD);
                me->RemoveAurasDueToSpell(SPELL_CHAIN_VISUAL_1);
                me->RemoveAurasDueToSpell(SPELL_CHAIN_VISUAL_2);
                events.ScheduleEvent(EVENT_HIDE_HEAD, 29s);
                events.ScheduleEvent(EVENT_FINISH_IMPALE_SELF, 33s);
                break;
            default:
                break;
        }
    }

    void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
    {
        if (!passenger)
            return;
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case DATA_FREE_PINCER:
                if (_pincer1->GetVehicleKit() && _pincer1->GetVehicleKit()->GetAvailableSeatCount())
                    return _pincer1->GetGUID();
                else if (_pincer2->GetVehicleKit() && _pincer2->GetVehicleKit()->GetAvailableSeatCount())
                    return _pincer2->GetGUID();
            default:
                return ObjectGuid::Empty;
        }

        return ObjectGuid::Empty;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_IMPALE_MAGMAW:
                events.Reset();
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->RemoveAurasDueToSpell(SPELL_MASSIVE_CRASH);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
                if (Creature* spikeStalker = me->FindNearestCreature(NPC_MAGMAW_SPIKE_STALKER, 50.0f))
                    me->SetFacingToObject(spikeStalker);
                events.ScheduleEvent(EVENT_IMPALE_SELF, 1s);
                events.ScheduleEvent(EVENT_EJECT_PASSENGER_1, 2s + 300ms);
                events.ScheduleEvent(EVENT_EXPOSE_HEAD, 4s + 700ms);
                _hasExposedHead = true;
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) && !_hasExposedHead)
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MAGMA_PROJECTILE:
                    if (_magmaProjectileCount < 4)
                    {
                        DoCastAOE(SPELL_MAGMA_SPIT_TARGETING);
                        _magmaProjectileCount++;
                        events.Repeat(6s);
                    }
                    else
                    {
                        DoCastAOE(SPELL_PILLAR_OF_FLAME);
                        _magmaProjectileCount = 0;
                        events.Repeat(8s);
                    }
                    break;
                case EVENT_LAVA_SPEW:
                    DoCastAOE(SPELL_LAVA_SPEW);
                    events.Repeat(24s);
                    break;
                case EVENT_MANGLE:
                    DoCastAOE(SPELL_MANGLE_TARGETING);
                    break;
                case EVENT_PREPARE_MASSIVE_CRASH:
                    if (ObjectGuid guid = instance->GetGuidData(DATA_PREPARE_MASSIVE_CRASH_AND_GET_TARGET_GUID))
                    {
                        if (Creature* stalker = ObjectAccessor::GetCreature(*me, guid))
                        {
                            me->AttackStop();
                            me->SetReactState(REACT_PASSIVE);
                            me->SetFacingToObject(stalker, true);
                            events.ScheduleEvent(EVENT_MASSIVE_CRASH, 5s);
                        }
                    }
                    break;
                case EVENT_MASSIVE_CRASH:
                    DoCast(SPELL_MASSIVE_CRASH);
                    _pincer1->CastSpell(_pincer1, SPELL_EJECT_PASSENGER_1);
                    _pincer2->CastSpell(_pincer2, SPELL_EJECT_PASSENGER_1);
                    break;
                case EVENT_ANNOUNCE_PINCERS_EXPOSED:
                    Talk(SAY_ANNOUNCE_EXPOSE_PINCERS);
                    break;
                case EVENT_FINISH_MASSIVE_CRASH:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_IMPALE_SELF:
                    DoCastSelf(SPELL_IMPALE_SELF);
                    break;
                case EVENT_EJECT_PASSENGER_1:
                    _pincer1->CastSpell(_pincer1, SPELL_EJECT_PASSENGER_1);
                    _pincer2->CastSpell(_pincer2, SPELL_EJECT_PASSENGER_1);
                    break;
                case EVENT_EXPOSE_HEAD:
                    if (!_headEngaged)
                    {
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, _exposedHead1, 2);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me);
                        _headEngaged = true;
                    }
                    _exposedHead1->CastSpell(_exposedHead1, SPELL_RIDE_VEHICLE_HEAD, true);
                    _exposedHead1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    break;
                case EVENT_HIDE_HEAD:
                    _exposedHead1->CastSpell(_exposedHead1, SPELL_RIDE_VEHICLE_EXPOSED_HEAD, true);
                    _exposedHead1->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    break;
                case EVENT_FINISH_IMPALE_SELF:
                    _hasExposedHead = false;
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                default:
                    break;
            }
        }

        if (Unit* victim = me->GetVictim())
        {
            if (me->IsWithinMeleeRange(victim))
                DoMeleeAttackIfReady();
            else
                DoSpellAttackIfReady(SPELL_MAGMA_SPIT_MOLTEN_TANTRUM);
        }
    }

private:
    void SetupBody()
    {
        if (_pincer1 = DoSummon(NPC_MAGMAWS_PINCER_1, me->GetPosition()))
        {
            _pincer1->EnterVehicle(me, SEAT_MAGMAWS_PINCER_1);
            _pincer1->SetDisplayId(_pincer1->GetCreatureTemplate()->Modelid3);
        }

        if (_pincer2 = DoSummon(NPC_MAGMAWS_PINCER_2, me->GetPosition()))
        {
            _pincer2->EnterVehicle(me, SEAT_MAGMAWS_PINCER_2);
            _pincer2->SetDisplayId(_pincer2->GetCreatureTemplate()->Modelid3);
        }

        _exposedHead1 = DoSummon(NPC_EXPOSED_HEAD_OF_MAGMAW, ExposedHeadOfMagmawPos);
        _exposedHead2 = DoSummon(NPC_EXPOSED_HEAD_OF_MAGMAW_2, me->GetPosition());

        if (!_exposedHead1 || !_exposedHead2)
            return;

        _exposedHead1->SetReactState(REACT_PASSIVE);
        _exposedHead2->SetReactState(REACT_PASSIVE);

        _exposedHead2->EnterVehicle(me, SEAT_EXPOSED_HEAD_OF_MAGMAW_2);
        DoCastSelf(SPELL_BIRTH);

        // First we link the real exposed head
        _exposedHead1->CastSpell(me, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        _exposedHead1->CastSpell(_exposedHead1, SPELL_POINT_OF_VULNERABILITY);
        _exposedHead1->CastSpell(_exposedHead2, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        // ... now the dummy exposed head
        _exposedHead2->CastSpell(me, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        _exposedHead2->CastSpell(_exposedHead2, SPELL_POINT_OF_VULNERABILITY);
        // ... and now Magmaw
        DoCast(_exposedHead2, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        DoCast(_exposedHead1, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);

        _exposedHead2->CastSpell(_exposedHead2, SPELL_QUEST_INVIS_5);

        ObjectGuid guid = me->GetGUID();
        Unit* head = _exposedHead1;
        head->m_Events.AddEventAtOffset([head, guid]()
        {
            if (Unit* target = ObjectAccessor::GetUnit(*head, guid))
                head->CastSpell(target, SPELL_RIDE_VEHICLE_EXPOSED_HEAD, true);
        }, 1s + 200ms);
    }

    Creature* _exposedHead1;
    Creature* _exposedHead2;
    Creature* _pincer1;
    Creature* _pincer2;
    uint8 _magmaProjectileCount;
    bool _hasExposedHead;
    bool _headEngaged;
};

class IsOnVehicleCheck
{
    public:
        IsOnVehicleCheck() { }

        bool operator()(WorldObject* object)
        {
            return object->ToUnit()->GetVehicle();
        }
};

class spell_magmaw_magma_spit: public SpellScript
{
    PrepareSpellScript(spell_magmaw_magma_spit);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGMA_SPIT_MISSILE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(IsOnVehicleCheck());

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 8 : 3);
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_MAGMA_SPIT_MISSILE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magmaw_magma_spit::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_magma_spit::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class VictimCheck
{
    public:
        VictimCheck(Unit* attacker) : _attacker(attacker)  { }

        bool operator()(WorldObject* object)
        {
            return (_attacker->GetVictim() && _attacker->GetVictim() != object->ToUnit());
        }
    private:
        Unit* _attacker;
};

class spell_magmaw_mangle : public SpellScript
{
    PrepareSpellScript(spell_magmaw_mangle);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MANGLE_1,
                SPELL_MANGLE_2,
                SPELL_SWELTERING_ARMOR
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(VictimCheck(GetCaster()));
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetHitUnit();
        caster->CastSpell(target, SPELL_MANGLE_1, true);
        target->CastSpell(target, SPELL_MANGLE_2, true);
        target->CastSpell(target, SPELL_SWELTERING_ARMOR, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magmaw_mangle::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_mangle::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_magmaw_pillar_of_flame_dummy : public SpellScript
{
    PrepareSpellScript(spell_magmaw_pillar_of_flame_dummy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PILLAR_OF_FLAME_MISSILE_PERIODIC,
                SPELL_PILLAR_OF_FLAME_PERIODIC
            });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_PILLAR_OF_FLAME_MISSILE_PERIODIC);
        if (Unit* caster = GetCaster())
            caster->m_Events.AddEventAtOffset([caster]()
            {
                caster->CastSpell(caster, SPELL_PILLAR_OF_FLAME_PERIODIC);
            }, 2s);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_pillar_of_flame_dummy::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class spell_magmaw_pillar_of_flame_forcecast : public SpellScript
{
    PrepareSpellScript(spell_magmaw_pillar_of_flame_forcecast);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(IsOnVehicleCheck());

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magmaw_pillar_of_flame_forcecast::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_magmaw_ride_vehicle : public SpellScript
{
    PrepareSpellScript(spell_magmaw_ride_vehicle);

    void SetTarget(WorldObject*& target)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* magmaw = instance->GetCreature(DATA_MAGMAW))
            {
                if (Creature* pincer = ObjectAccessor::GetCreature(*GetCaster(), magmaw->AI()->GetGUID(DATA_FREE_PINCER)))
                    target = pincer;
                else
                    target = nullptr;
            }
        }
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_magmaw_ride_vehicle::SetTarget, EFFECT_0, TARGET_UNIT_TARGET_ANY);
    }
};

class spell_magmaw_launch_hook : public AuraScript
{
    PrepareAuraScript(spell_magmaw_launch_hook);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_LAUNCH_HOOK_1,
                SPELL_LAUNCH_HOOK_2,
                SPELL_CHAIN_VISUAL_1,
                SPELL_CHAIN_VISUAL_2
            });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (target->HasAura(SPELL_LAUNCH_HOOK_1) /*&&*/ || target->HasAura(SPELL_LAUNCH_HOOK_2))
        {
            if (InstanceScript* instance = target->GetInstanceScript())
                if (Creature* magmaw = instance->GetCreature(DATA_MAGMAW))
                    magmaw->AI()->DoAction(ACTION_IMPALE_MAGMAW);

            target->CastSpell(target, SPELL_CHAIN_VISUAL_1);
            target->CastSpell(target, SPELL_CHAIN_VISUAL_2);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_magmaw_launch_hook::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_magmaw()
{
    RegisterBlackwingDescentCreatureAI(boss_magmaw);
    RegisterSpellScript(spell_magmaw_magma_spit);
    RegisterSpellScript(spell_magmaw_mangle);
    RegisterSpellScript(spell_magmaw_pillar_of_flame_dummy);
    RegisterSpellScript(spell_magmaw_pillar_of_flame_forcecast);
    RegisterSpellScript(spell_magmaw_ride_vehicle);
    RegisterAuraScript(spell_magmaw_launch_hook);
}
