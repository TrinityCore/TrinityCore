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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"
#include "GridNotifiers.h"
#include "MoveSplineInit.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "Vehicle.h"

enum RollingBoulders
{
    SPELL_ROLLING_BOULDERS_PERIODIC_AURA    = 96837,
    SPELL_ROLLING_BOULDERS_SEARCH_EFFECT    = 96839,
    SPELL_ROLLING_BOULDERS_SUMMON_LEFT      = 96827,
    SPELL_ROLLING_BOULDERS_SUMMON_CENTER    = 96828,
    SPELL_ROLLING_BOULDERS_SUMMON_RIGHT     = 96829,
    SPELL_THUNDERCLAP                       = 15588,
    SPELL_KNOCK_AWAY                        = 97616,
    SPELL_EXPLODING_BOULDER                 = 96836,
    SPELL_EXPLODING_BOULDER_VISUAL          = 96831,
    SPELL_ROLLING_BOULDERS                  = 96833,

    NPC_BOULDER_LEFT                        = 52351,
    NPC_BOULDER_CENTER                      = 52354,
    NPC_BOULDER_RIGHT                       = 52353,

    EVENT_THUNDERCLAP                       = 1,
    EVENT_KNOCK_AWAY                        = 2,

    ACTION_ROLL_BOULDER                     = 0,
    SEAT_0                                  = 0
};

uint32 boulderCombinationFirst[] =
{
    SPELL_ROLLING_BOULDERS_SUMMON_RIGHT,
    SPELL_ROLLING_BOULDERS_SUMMON_CENTER,
    SPELL_ROLLING_BOULDERS_SUMMON_LEFT
};

uint32 boulderCombinationSecond[] =
{
    SPELL_ROLLING_BOULDERS_SUMMON_RIGHT,
    SPELL_ROLLING_BOULDERS_SUMMON_LEFT,
    SPELL_ROLLING_BOULDERS_SUMMON_CENTER
};

Position const BoulderMovePosLeft   = { -12128.5f,  -1809.7f,   81.73696f }; // jump to -12134.33 Y: -1809.78 Z: 83.9827
Position const BoulderMovePosCenter = { -12117.74f, -1818.293f, 80.22023f }; // jump to -12123.57 Y: -1818.352 Z: 80.20083
Position const BoulderMovePosRight  = { -12126.91f, -1827.861f, 81.26235f }; // jump to -12132.74 Y: -1827.843 Z: 83.37392

class ExplodingBoulderEvent : public BasicEvent
{
    public:
        ExplodingBoulderEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->RemoveAurasDueToSpell(SPELL_EXPLODING_BOULDER_VISUAL);
            _owner->CastSpell(_owner, SPELL_EXPLODING_BOULDER);
            _owner->DespawnOrUnsummon(1s);
            if (Vehicle* vehicle = _owner->GetVehicleKit())
                if (Unit* passenger = vehicle->GetPassenger(SEAT_0))
                    if (Creature* creature = passenger->ToCreature())
                        creature->DespawnOrUnsummon(1s);
            return true;
        }
    private:
        Creature* _owner;
};

class RollingBouldersCastEvent : public BasicEvent
{
    public:
        RollingBouldersCastEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, SPELL_ROLLING_BOULDERS);
            return true;
        }
    private:
        Creature* _owner;
};

struct npc_zulgurub_berserking_boulder_roller : public ScriptedAI
{
    npc_zulgurub_berserking_boulder_roller(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        _useSecondCombination = false;
    }

    void Reset() override
    {
        Initialize();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_THUNDERCLAP, 2s);
        _events.ScheduleEvent(EVENT_KNOCK_AWAY, 6s, 7s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        _events.Reset();
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ROLLING_BOULDERS_SEARCH_EFFECT)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveAurasDueToSpell(SPELL_ROLLING_BOULDERS_PERIODIC_AURA);
            AttackStart(target);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ROLL_BOULDER)
        {
            uint32 spellId = !_useSecondCombination ? boulderCombinationFirst[_boulderCount] : boulderCombinationSecond[_boulderCount];
            DoCastSelf(spellId, true);

            if (_boulderCount < 2)
                _boulderCount++;
            else
            {
                _boulderCount = 0;
                _useSecondCombination = !_useSecondCombination ? true : false;
            }
        }
    }

    void JustSummoned(Creature* summon) override
    {
        Position destination;
        switch (summon->GetEntry())
        {
            case NPC_BOULDER_LEFT:
                destination = BoulderMovePosLeft;
                break;
            case NPC_BOULDER_CENTER:
                destination = BoulderMovePosCenter;
                break;
            case NPC_BOULDER_RIGHT:
                destination = BoulderMovePosRight;
                break;
            default:
                break;
        }

        Movement::MoveSplineInit init(summon);
        init.MoveTo(destination.GetPositionX(), destination.GetPositionY(), destination.GetPositionZ());
        if (uint32 time = init.Launch())
            summon->m_Events.AddEventAtOffset(new ExplodingBoulderEvent(summon), Milliseconds(time));

        summon->m_Events.AddEventAtOffset(new RollingBouldersCastEvent(summon), 600ms);
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
                case EVENT_THUNDERCLAP:
                    DoCastAOE(SPELL_THUNDERCLAP);
                    _events.Repeat(15s, 16s);
                    break;
                case EVENT_KNOCK_AWAY:
                    DoCastVictim(SPELL_KNOCK_AWAY);
                    _events.Repeat(19s, 20s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    uint8 _boulderCount;
    bool _useSecondCombination;
};

class spell_zulgurub_rolling_boulders : public AuraScript
{
    PrepareAuraScript(spell_zulgurub_rolling_boulders);

    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        // Serverside spell. We just skip that part and do it directly via script
        PreventDefaultAction();
        if (Creature* creature = GetTarget()->ToCreature())
            if (creature->IsAIEnabled)
                creature->AI()->DoAction(ACTION_ROLL_BOULDER);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_zulgurub_rolling_boulders::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_zulgurub()
{
    RegisterZulGurubCreatureAI(npc_zulgurub_berserking_boulder_roller);
    RegisterAuraScript(spell_zulgurub_rolling_boulders);
}
