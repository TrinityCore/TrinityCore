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
    SPELL_PILLAR_OF_FLAME                       = 77998,
    SPELL_PILLAR_OF_FLAME_MISSILE_PERIODIC      = 78006,

    SPELL_MASSIVE_CRASH                         = 88253,
    SPELL_MASSIVE_CRASH_DAMAGE                  = 88287,

    // Exposed Head of Magmaw
    SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE   = 79010,
    SPELL_POINT_OF_VULNERABILITY                = 79011,
    SPELL_RIDE_VEHICLE_EXPOSED_HEAD             = 89743,
    SPELL_QUEST_INVIS_5                         = 95478,

    // Pillar of Flame
    SPELL_PILLAR_OF_FLAME_DUMMY                 = 78017,
    SPELL_PILLAR_OF_FLAME_PERIODIC              = 77970,

    // Room Stalker
    SPELL_LIGHT_SHOW                            = 87949,
};

enum Events
{
    // Magmaw
    EVENT_MAGMA_PROJECTILE = 1,
    EVENT_LAVA_SPEW,
    EVENT_MANGLE,
};

enum Actions
{
};

enum Texts
{
    // Magmaw
    SAY_ANNOUNCE_LAVA_PARASITES = 0,
};

enum VehicleSeats
{
    SEAT_MAGMAWS_PINCER_1           = 0,
    SEAT_MAGMAWS_PINCER_2           = 1,
    SEAT_EXPOSED_HEAD_OF_MAGMAW_1   = 3,
    SEAT_EXPOSED_HEAD_OF_MAGMAW_2   = 4,
};

Position const ExposedHeadOfMagmawPos = { -299.0f, -28.9861f, 191.0293f, 4.118977f };

class DelayedSpellCastEvent : public BasicEvent
{
    public:
        DelayedSpellCastEvent(Unit* owner, ObjectGuid targetGUID, uint32 spellId, bool triggered = false) :
            _owner(owner), _targetGUID(targetGUID), _spellId(spellId), _triggered(triggered) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (Unit* target = ObjectAccessor::GetUnit(*_owner, _targetGUID))
                _owner->CastSpell(target, _spellId, _triggered);
            return true;
        }

    private:
        Unit* _owner;
        ObjectGuid _targetGUID;
        uint32 _spellId;
        bool _triggered;
};

struct boss_magmaw : public BossAI
{
    boss_magmaw(Creature* creature) : BossAI(creature, DATA_MAGMAW), vehicle(me->GetVehicleKit())
    {
        Initialize();
    }

    void Initialize()
    {
        _magmaProjectileCount = 0;
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
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
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

    void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
    {
        if (!passenger)
            return;

        if (passenger->GetEntry() == NPC_EXPOSED_HEAD_OF_MAGMAW)
            passenger->SetFacingTo(me->GetOrientation());
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
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
        if (Creature* pincer1 = DoSummon(NPC_MAGMAWS_PINCER_1, me->GetPosition()))
        {
            pincer1->EnterVehicle(me, SEAT_MAGMAWS_PINCER_1);
            pincer1->SetDisplayId(pincer1->GetCreatureTemplate()->Modelid3);
        }

        if (Creature* pincer2 = DoSummon(NPC_MAGMAWS_PINCER_2, me->GetPosition()))
        {
            pincer2->EnterVehicle(me, SEAT_MAGMAWS_PINCER_2);
            pincer2->SetDisplayId(pincer2->GetCreatureTemplate()->Modelid3);
        }

        Creature* exposedHead = DoSummon(NPC_EXPOSED_HEAD_OF_MAGMAW, ExposedHeadOfMagmawPos);
        Creature* exposedHead2 = DoSummon(NPC_EXPOSED_HEAD_OF_MAGMAW_2, me->GetPosition());

        if (!exposedHead || !exposedHead2)
            return;

        exposedHead->SetReactState(REACT_PASSIVE);
        exposedHead2->SetReactState(REACT_PASSIVE);

        exposedHead2->EnterVehicle(me, SEAT_EXPOSED_HEAD_OF_MAGMAW_2);
        DoCastSelf(SPELL_BIRTH);

        // First we link the real exposed head
        exposedHead->CastSpell(me, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        exposedHead->CastSpell(exposedHead, SPELL_POINT_OF_VULNERABILITY);
        exposedHead->CastSpell(exposedHead2, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        // ... now the dummy exposed head
        exposedHead2->CastSpell(me, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        exposedHead2->CastSpell(exposedHead2, SPELL_POINT_OF_VULNERABILITY);
        // ... and now Magmaw
        DoCast(exposedHead2, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        DoCast(exposedHead, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);

        exposedHead2->CastSpell(exposedHead2, SPELL_QUEST_INVIS_5);

        exposedHead->m_Events.AddEventAtOffset(
            new DelayedSpellCastEvent(exposedHead, me->GetGUID(), SPELL_RIDE_VEHICLE_EXPOSED_HEAD, true), 1s + 200ms);
    }

    Creature* GetExposedHeadOfMagmaw()
    {
        if (Unit* passenger = vehicle->GetPassenger(SEAT_EXPOSED_HEAD_OF_MAGMAW_1))
            if (passenger->GetTypeId() == TYPEID_UNIT)
                return passenger->ToCreature();

        return nullptr;
    }

    Vehicle const* vehicle;
    uint8 _magmaProjectileCount;
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
        VictimCheck(Unit* _attacker) : attacker(_attacker)  { }

        bool operator()(WorldObject* object)
        {
            return (attacker->GetVictim() && attacker->GetVictim() != object->ToUnit());
        }
    private:
        Unit* attacker;
};

class spell_magmaw_mangle : public SpellScript
{
    PrepareSpellScript(spell_magmaw_mangle);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MANGLE_1,
                SPELL_MANGLE_2
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
            caster->m_Events.AddEventAtOffset(new DelayedSpellCastEvent(caster, caster->GetGUID(), SPELL_PILLAR_OF_FLAME_PERIODIC), 2s);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_pillar_of_flame_dummy::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class spell_magmaw_pillar_of_flame_forcecast : public SpellScript
{
    PrepareSpellScript(spell_magmaw_pillar_of_flame_forcecast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MANGLE_1,
                SPELL_MANGLE_2
            });
    }

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

void AddSC_boss_magmaw()
{
    RegisterBlackwingDescentCreatureAI(boss_magmaw);
    RegisterSpellScript(spell_magmaw_magma_spit);
    RegisterSpellScript(spell_magmaw_mangle);
    RegisterSpellScript(spell_magmaw_pillar_of_flame_dummy);
    RegisterSpellScript(spell_magmaw_pillar_of_flame_forcecast);
}
