/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "throne_of_the_four_winds.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Spell.h"

enum Spells
{
    // Al'Akir
    SPELL_WIND_BURST                        = 87770,
    SPELL_LIGHTNING_STRIKE_TARGETING        = 91327,
    SPELL_ICE_STORM                         = 88239,
    SPELL_ELECTROCUTE                       = 88427,

    // Lightning Strike Trigger
    SPELL_LIGHTNING_STRIKE_SUMMON           = 93250,
    SPELL_LIGHTNING_STRIKE_PERIODIC         = 88238,

    // Lightning Strike Trigger (Heroic Chain-Caster)
    SPELL_LIGHTNING_STRIKE_DAMAGE           = 88214,
    SPELL_LIGHTNING_STRIKE_VISUAL           = 88230,

    // Ice Storm
    SPELL_ICE_STORM_PING                    = 87406,
    SPELL_ICE_STORM_CHARGE                  = 87103,

    // Ice Storm (Damage)
    SPELL_ICE_STORM_PRE_VISUAL              = 87472,
    SPELL_ICE_STORM_AURA                    = 87469,
};

enum Events
{
    // Al'Akir
    EVENT_WIND_BURST = 1,
    EVENT_LIGHTNING_STRIKE,
    EVENT_ICE_STORM,

    // Ice Storm
    EVENT_PING_ICE_STORM_TRIGGERS,
    EVENT_ICE_STORM_CHARGE,
};

enum Phases
{
    PHASE_ONE   = 1,
    PHASE_TWO   = 2,
    PHASE_THREE = 3
};

enum Actions
{
};

enum Texts
{
    SAY_CONCLAVE_OF_WIND_DEFEATED   = 0,
    SAY_AGGRO                       = 1,
    SAY_ANNOUNCE_WIND_BURST         = 2,
};

enum Data
{
    DATA_PRIMARY_LIGHTNING_STRIKE_TARGET = 0
};

enum SummonGroups
{
    SUMMON_GROUP_SLIPSTREAM = 0
};

class IceStormAuraEvent : public BasicEvent
{
    public:
        IceStormAuraEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, SPELL_ICE_STORM_AURA);
            return true;
        }
    private:
        Creature* _owner;
};

struct boss_alakir : public BossAI
{
    boss_alakir(Creature* creature) : BossAI(creature, DATA_ALAKIR)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        me->SetReactState(REACT_AGGRESSIVE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_WIND_BURST, 23s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_LIGHTNING_STRIKE, 9s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_ICE_STORM, 5s, 0, PHASE_ONE);
    }

    void Reset()
    {
        _Reset();
        if (instance->GetBossState(DATA_CONCLAVE_OF_WIND) == DONE)
            me->SummonCreatureGroup(SUMMON_GROUP_SLIPSTREAM);
    }

    void KilledUnit(Unit* killed) override
    {
        //if (killed->GetTypeId() == TYPEID_PLAYER)
        //    Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CONCLAVE_DEFEATED:
                Talk(SAY_CONCLAVE_OF_WIND_DEFEATED);
                me->SummonCreatureGroup(SUMMON_GROUP_SLIPSTREAM);
                break;
            default:
                break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case 0:
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SLIPSTREAM:
                summon->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                break;
            case NPC_ICE_STORM:
                summon->CastSpell(summon, SPELL_ICE_STORM_PRE_VISUAL);
                summon->m_Events.AddEvent(new IceStormAuraEvent(summon), summon->m_Events.CalculateTime(3500));
                break;
            default:
                break;
        }
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        if (type == DATA_PRIMARY_LIGHTNING_STRIKE_TARGET)
            return _primaryLightningStrikeTarget;

        return ObjectGuid::Empty;
    }

    void SetGUID(ObjectGuid const& guid, int32 type) override
    {
        if (type == DATA_PRIMARY_LIGHTNING_STRIKE_TARGET)
            _primaryLightningStrikeTarget = guid;
    }

    uint32 GetData(uint32 type) const override
    {
        return 0;
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
                case EVENT_WIND_BURST:
                    Talk(SAY_ANNOUNCE_WIND_BURST);
                    //DoCastAOE(SPELL_WIND_BURST);
                    events.Repeat(26s);
                    break;
                case EVENT_LIGHTNING_STRIKE:
                    DoCastAOE(SPELL_LIGHTNING_STRIKE_TARGETING);
                    events.Repeat(8s);
                    break;
                case EVENT_ICE_STORM:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 70.0f, true, 0))
                        DoCast(target, SPELL_ICE_STORM);
                    events.Repeat(16s);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }

private:
    ObjectGuid _primaryLightningStrikeTarget;
};

struct npc_alakir_ice_storm : public ScriptedAI
{
    npc_alakir_ice_storm(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_PING_ICE_STORM_TRIGGERS, 1s);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ICE_STORM_PING)
            _iceStormPositions.push_back(target->GetPosition());
    }

    void MovementInform(uint32 /*type*/, uint32 pointId) override
    {
        if (pointId == EVENT_CHARGE)
            _events.ScheduleEvent(EVENT_ICE_STORM_CHARGE, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PING_ICE_STORM_TRIGGERS:
                    DoCastAOE(SPELL_ICE_STORM_PING);
                    _events.ScheduleEvent(EVENT_ICE_STORM_CHARGE, 500ms);
                    break;
                case EVENT_ICE_STORM_CHARGE:
                {
                    Creature* alakir = _instance->GetCreature(DATA_ALAKIR);
                    if (!alakir)
                        break;

                    Position* pos = &alakir->GetPosition();
                    pos->SetOrientation(alakir->GetAngle(me));
                    pos->RelocateOffset({ 0.0f, 0.0f, 0.0f, float(M_PI / 2)});

                    std::vector<Position> possibleDestinations;
                    for (Position destination : _iceStormPositions)
                    {
                        if (pos->HasInArc(float(M_PI / 2), &destination, 0.0f))
                            possibleDestinations.push_back(destination);
                    }

                    if (!possibleDestinations.empty())
                    {
                        Position dest = Trinity::Containers::SelectRandomContainerElement(possibleDestinations);
                        me->CastSpell(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), SPELL_ICE_STORM_CHARGE, true);
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    InstanceScript* _instance;
    std::vector<Position> _iceStormPositions;
};

class spell_alakir_lightning_strike_script : public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_strike_script);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_LIGHTNING_STRIKE_SUMMON,
                SPELL_LIGHTNING_STRIKE_PERIODIC
            });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();
        target->SetFacingToObject(caster);
        target->SetOrientation(target->GetAngle(caster)); // Update orientation immediately for the following cast

        if (InstanceScript* instance = caster->GetInstanceScript())
            if (Creature* alakir = instance->GetCreature(DATA_ALAKIR))
                alakir->AI()->SetGUID(caster->GetGUID(), DATA_PRIMARY_LIGHTNING_STRIKE_TARGET);

        if (target->GetMap()->IsHeroic())
            target->CastSpell(target, SPELL_LIGHTNING_STRIKE_SUMMON, true);
        else
            target->CastSpell(target, SPELL_LIGHTNING_STRIKE_PERIODIC, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_lightning_strike_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_alakir_lightning_strike_periodic : public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_strike_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_LIGHTNING_STRIKE_DAMAGE,
                SPELL_LIGHTNING_STRIKE_VISUAL
            });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_LIGHTNING_STRIKE_DAMAGE, true);

        float orientation = caster->GetOrientation();
        float coneAngle = float(M_PI / 3);
        float coneSegment = coneAngle / 10;
        for (uint8 i = 0; i < 10; i++)
        {
            float angle = orientation - (coneAngle / 2) + (coneSegment * i);
            float x = caster->GetPositionX() + cos(angle) * 60.0f;
            float y = caster->GetPositionY() + sin(angle) * 60.0f;
            float z = caster->GetPositionZ();
            caster->CastSpell(x, y, z, SPELL_LIGHTNING_STRIKE_VISUAL, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_lightning_strike_periodic::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_alakir_lightning_strike_damage : public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_strike_damage);

    void HandleDamageReuction(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (InstanceScript* instance = caster->GetInstanceScript())
            if (Creature* alakir = instance->GetCreature(DATA_ALAKIR))
                if (GetHitUnit()->GetGUID() != alakir->AI()->GetGUID(DATA_PRIMARY_LIGHTNING_STRIKE_TARGET))
                    SetHitDamage(GetHitDamage() * 0.5f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_lightning_strike_damage::HandleDamageReuction, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_boss_alakir()
{
    RegisterThroneOfTheFourWindsCreatureAI(boss_alakir);
    RegisterThroneOfTheFourWindsCreatureAI(npc_alakir_ice_storm);

    RegisterSpellScript(spell_alakir_lightning_strike_script);
    RegisterSpellScript(spell_alakir_lightning_strike_periodic);
    RegisterSpellScript(spell_alakir_lightning_strike_damage);
}
