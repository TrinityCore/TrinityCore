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

    // Exposed Head of Magmaw
    SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE   = 79010,
    SPELL_POINT_OF_VULNERABILITY                = 79011,
    SPELL_RIDE_VEHICLE_EXPOSED_HEAD             = 89743,
    SPELL_QUEST_INVIS_5                         = 95478,
};

enum Events
{
};

enum Actions
{
};

enum Texts
{
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
    boss_magmaw(Creature* creature) : BossAI(creature, DATA_MAGMAW), vehicle(me->GetVehicleKit()) { }

    void Reset() override
    {
        _Reset();
    }

    void JustAppeared() override
    {
        SetupBody();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
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
    }

    void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
    {
        if (!passenger)
            return;

        if (passenger->GetEntry() == NPC_EXPOSED_HEAD_OF_MAGMAW)
            passenger->SetFacingTo(me->GetOrientation());
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
};

void AddSC_boss_magmaw()
{
    RegisterBlackwingDescentCreatureAI(boss_magmaw);
}
