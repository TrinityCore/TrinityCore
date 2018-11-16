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
#include "Vehicle.h"

enum Spells
{
    // Al'Akir
    SPELL_WIND_BURST                                        = 87770,
    SPELL_LIGHTNING_STRIKE_TARGETING                        = 91327,
    SPELL_ICE_STORM                                         = 88239,
    SPELL_ELECTROCUTE                                       = 88427,
    SPELL_SQUALL_LINE_BACK_LEFT                             = 88781,
    SPELL_SQUALL_LINE_BACK_RIGHT                            = 91104,
    SPELL_SQUALL_LINE_SCRIPT                                = 91129,
    SPELL_SQUALL_LINE_SCRIPT_2                              = 91110,
    SPELL_ACID_RAIN                                         = 88290,
    SPELL_STORMLING                                         = 88272,
    SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE_TRIGGER     = 89528,
    SPELL_RELENTLESS_STORM_CHANNEL                          = 88875,

    // Squall Line Vehicle
    SPELL_SQUALL_LINE_FORCE_CAST                            = 88779,

    // Lightning Strike Trigger
    SPELL_LIGHTNING_STRIKE_SUMMON                           = 93250,
    SPELL_LIGHTNING_STRIKE_PERIODIC                         = 88238,

    // Lightning Strike Trigger (Heroic Chain-Caster)
    SPELL_LIGHTNING_STRIKE_DAMAGE                           = 88214,
    SPELL_LIGHTNING_STRIKE_VISUAL                           = 88230,

    // Ice Storm
    SPELL_ICE_STORM_PING                                    = 87406,
    SPELL_ICE_STORM_CHARGE                                  = 87103,
    SPELL_ICE_STORM_UNK                                     = 87408, // Todo: research purpose

    // Ice Storm (Damage)
    SPELL_ICE_STORM_PRE_VISUAL                              = 87472,
    SPELL_ICE_STORM_AURA                                    = 87469,

    // Stormling Pre-effect
    SPELL_STORMLING_PRE_EFFECT_VISUAL                       = 87913,
    SPELL_STORMLING_SUMMON                                  = 87914,

    // Stormling
    SPELL_FEEDBACK                                          = 87904,

    // Relentless Storm Initial Vehicle
    SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE             = 89527,

    // World Trigger (Infinite AOI)
    SPELL_RELENTLESS_STORM_VISUAL                           = 88866,
    SPELL_STORM_DISTANCE_CHECK                              = 88899,

    // Player
    SPELL_EYE_OF_THE_STORM                                  = 82724,
    SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE_TELEPORT    = 89661,
    SPELL_PET_FLIGHT                                        = 90786,
};

#define SPELL_ACID_RAIN         RAID_MODE<uint32>(88290, 101451, 101452, 101453)
#define SPELL_ACID_RAIN_DAMAGE  RAID_MODE<uint32>(88301, 93279, 93280, 93281)

enum Texts
{
    SAY_CONCLAVE_OF_WIND_DEFEATED   = 0,
    SAY_AGGRO                       = 1,
    SAY_ANNOUNCE_WIND_BURST         = 2,
    SAY_SQUALL_LINE                 = 3,
    SAY_PHASE_TWO                   = 4,
    SAY_SUMMON_STORMLING            = 5,
    SAY_PHASE_THREE                 = 6,
};

enum Events
{
    // Al'Akir
    EVENT_WIND_BURST = 1,
    EVENT_LIGHTNING_STRIKE,
    EVENT_ICE_STORM,
    EVENT_SQUALL_LINE,
    EVENT_SUMMON_STORMLING,
    EVENT_EYE_OF_THE_STORM,

    // Ice Storm
    EVENT_PING_ICE_STORM_TRIGGERS,
    EVENT_ICE_STORM_CHARGE,

    // Stormling
    EVENT_ATTACK_PLAYERS,
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

enum Data
{
    DATA_PRIMARY_LIGHTNING_STRIKE_TARGET = 0
};

enum SummonGroups
{
    SUMMON_GROUP_SLIPSTREAM = 0
};

#define MAX_HOME_POSITION_DISTANCE 70.0f

class DelayedSpellCastEvent : public BasicEvent
{
    public:
        DelayedSpellCastEvent(Creature* owner, uint32 spellId) :  _owner(owner), _spellId(spellId) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, _spellId);
            return true;
        }
    private:
        Creature* _owner;
        uint32 _spellId;
};

class SquallLineImmunityRemovalEvent : public BasicEvent
{
    public:
        SquallLineImmunityRemovalEvent(Unit* owner, uint32 spellId) : _owner(owner), _spellId(spellId) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->ApplySpellImmune(0, IMMUNITY_ID, _spellId, false);
            return true;
        }
    private:
        Unit* _owner;
        uint32 _spellId;
};

Position const SquallLineDistanceReferencePos = { -13.16094f, 780.8931f, 191.1842f };
Position const RelentlessStormTeleportReferencePosition = { -126.0f, 838.0f, 316.0f };

struct boss_alakir : public BossAI
{
    boss_alakir(Creature* creature) : BossAI(creature, DATA_ALAKIR)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        _useLeftSquallLineSpell = true;
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
        events.ScheduleEvent(EVENT_SQUALL_LINE, 10s);
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

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetData(DATA_ACID_RAIN_WEATHER, NOT_STARTED);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ACID_RAIN_DAMAGE);
        summons.DespawnAll();

        if (GameObject* platform = instance->GetGameObject(DATA_SKYWALL_RAID_CENTER_PLATFORM))
            platform->SetDestructibleState(GO_DESTRUCTIBLE_INTACT);

        if (GameObject* draftEffect = instance->GetGameObject(DATA_SKYWALL_WIND_DRAFT_EFFECT_CENTER))
            draftEffect->ResetDoorOrButton();

        if (Creature* worldTrigger = instance->GetCreature(DATA_WORLD_TRIGGER_INFINITE_AOI))
            worldTrigger->RemoveAllAuras();

        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetData(DATA_ACID_RAIN_WEATHER, NOT_STARTED);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ACID_RAIN_DAMAGE);

        if (Creature* worldTrigger = instance->GetCreature(DATA_WORLD_TRIGGER_INFINITE_AOI))
            worldTrigger->RemoveAllAuras();
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

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(80, damage) && events.IsInPhase(PHASE_ONE))
        {
            DoCastSelf(SPELL_ACID_RAIN);
            instance->SetData(DATA_ACID_RAIN_WEATHER, IN_PROGRESS);
            Talk(SAY_PHASE_TWO);
            events.SetPhase(PHASE_TWO);
            events.ScheduleEvent(EVENT_SUMMON_STORMLING, 10s, 11s, 0, PHASE_TWO);
        }
        else if (me->HealthBelowPctDamaged(25, damage) && events.IsInPhase(PHASE_TWO))
        {
            Talk(SAY_PHASE_THREE);
            me->SetCanFly(true);
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->SetFacingTo(3.141593f);
            me->InterruptNonMeleeSpells(true);
            me->RemoveAurasDueToSpell(SPELL_ACID_RAIN);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ACID_RAIN_DAMAGE);
            instance->SetData(DATA_ACID_RAIN_WEATHER, NOT_STARTED);
            DoCastAOE(SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE_TRIGGER);
            DoCastAOE(SPELL_RELENTLESS_STORM_CHANNEL);
            summons.DespawnAll();
            events.CancelEvent(EVENT_SQUALL_LINE);
            events.SetPhase(PHASE_THREE);
            events.ScheduleEvent(EVENT_EYE_OF_THE_STORM, 7s, 0, PHASE_THREE);

            if (GameObject* platform = instance->GetGameObject(DATA_SKYWALL_RAID_CENTER_PLATFORM))
                platform->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);

            if (GameObject* draftEffect = instance->GetGameObject(DATA_SKYWALL_WIND_DRAFT_EFFECT_CENTER))
                draftEffect->UseDoorOrButton();

            if (Creature* worldTrigger = instance->GetCreature(DATA_WORLD_TRIGGER_INFINITE_AOI))
            {
                worldTrigger->CastSpell(worldTrigger, SPELL_RELENTLESS_STORM_VISUAL);
                worldTrigger->CastSpell(worldTrigger, SPELL_STORM_DISTANCE_CHECK);
            }
        }
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
                summon->m_Events.AddEvent(new DelayedSpellCastEvent(summon, SPELL_ICE_STORM_AURA), summon->m_Events.CalculateTime(3500));
                break;
            case NPC_SQUALL_LINE_VEHICLE_SW:
                DoCastSelf(SPELL_SQUALL_LINE_SCRIPT);
                summon->GetMotionMaster()->MoveCirclePath(me->GetPositionX(), me->GetPositionY(), SquallLineDistanceReferencePos.GetPositionZ(), me->GetExactDist(SquallLineDistanceReferencePos), true, 11);
                // Delay the spell cast by 100ms to give the core time to place the accessories into the seats for the following spellscript to take effect
                summon->m_Events.AddEvent(new DelayedSpellCastEvent(summon, SPELL_SQUALL_LINE_FORCE_CAST), summon->m_Events.CalculateTime(100));
                break;
            case NPC_SQUALL_LINE_VEHICLE_SE:
                DoCastSelf(SPELL_SQUALL_LINE_SCRIPT);
                summon->GetMotionMaster()->MoveCirclePath(me->GetPositionX(), me->GetPositionY(), SquallLineDistanceReferencePos.GetPositionZ(), me->GetExactDist(SquallLineDistanceReferencePos), false, 11);
                summon->m_Events.AddEvent(new DelayedSpellCastEvent(summon, SPELL_SQUALL_LINE_FORCE_CAST), summon->m_Events.CalculateTime(100));
                break;
            case NPC_SQUALL_LINE_SW:
            case NPC_SQUALL_LINE_SE:
                // We don't use that spell. We just cast it because in sniffs they do the same
                DoCast(summon, SPELL_SQUALL_LINE_SCRIPT_2);
                break;
            case NPC_STORMLING_PRE_EFFECT:
                summon->CastSpell(summon, SPELL_STORMLING_PRE_EFFECT_VISUAL);
                summon->m_Events.AddEvent(new DelayedSpellCastEvent(summon, SPELL_STORMLING_SUMMON), summon->m_Events.CalculateTime(3500));
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
                case EVENT_SQUALL_LINE:
                    if (events.IsInPhase(PHASE_ONE))
                        Talk(SAY_SQUALL_LINE);

                    DoCastSelf(_useLeftSquallLineSpell ? SPELL_SQUALL_LINE_BACK_LEFT : SPELL_SQUALL_LINE_BACK_RIGHT);
                    _useLeftSquallLineSpell = !_useLeftSquallLineSpell;
                    events.Repeat(31s);
                    break;
                case EVENT_SUMMON_STORMLING:
                    Talk(SAY_SUMMON_STORMLING);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_STORMLING);
                    events.Repeat(20s);
                    break;
                case EVENT_EYE_OF_THE_STORM:
                    instance->DoCastSpellOnPlayers(SPELL_EYE_OF_THE_STORM);
                    break;
                default:
                    break;
            }
        }
        if (me->IsWithinMeleeRange(me->GetVictim()))
            DoMeleeAttackIfReady();
        else
            DoSpellAttackIfReady(SPELL_ELECTROCUTE);
    }

private:
    ObjectGuid _primaryLightningStrikeTarget;
    bool _useLeftSquallLineSpell;
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
        if (spell->Id == SPELL_ICE_STORM_PING && target->GetExactDist2d(me) > 10.0f)
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

                    Position pos = alakir->GetPosition();
                    pos.SetOrientation(alakir->GetAngle(me) + float(M_PI / 4));

                    std::vector<Position> possibleDestinations;
                    for (Position destination : _iceStormPositions)
                    {
                        if (pos.HasInLine(&destination, alakir->GetCombatReach()))
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

struct npc_alakir_stormling : public ScriptedAI
{
    npc_alakir_stormling(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_ATTACK_PLAYERS, 2s + 300ms);
        if (Creature* alakir = _instance->GetCreature(DATA_ALAKIR))
            _alakirPos = alakir->GetHomePosition();
    }

    void AttackStart(Unit* who) override
    {
        if (IsTargetOnPlatform(who))
            ScriptedAI::AttackStart(who);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastAOE(SPELL_FEEDBACK, true);
        me->DespawnOrUnsummon(4s);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();
        UpdatePlatformVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ATTACK_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    Position _alakirPos;

    void UpdatePlatformVictim()
    {
        if (Unit* victim = me->GetVictim())
            if (victim->GetExactDist2d(_alakirPos) > MAX_HOME_POSITION_DISTANCE)
                me->AttackStop();
    }

    bool IsTargetOnPlatform(Unit* target) const
    {
        return (target->GetExactDist2d(_alakirPos) < MAX_HOME_POSITION_DISTANCE);
    }
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

class spell_alakir_electrocute : public AuraScript
{
    PrepareAuraScript(spell_alakir_electrocute);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();

        if (!caster || !target)
            return;

        if (caster->IsWithinMeleeRange(target))
        {
            Remove();
            return;
        }

        if (AuraEffect* aurEff = GetEffect(EFFECT_0))
        {
            int32 basePoints = 3600;
            basePoints += CalculatePct(basePoints * (aurEff->GetTickNumber() - 1), 50);
            aurEff->ChangeAmount(basePoints);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_alakir_electrocute::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

class SquallLineGapTargetSelector
{
    public:
        SquallLineGapTargetSelector(uint8 seatIndex) : _seatIndex(seatIndex) { }

        bool operator()(WorldObject* object)
        {
            Unit* target = object->ToUnit();
            if (!target)
                return true;

            if (Vehicle* vehicle = target->GetVehicle())
                if (TempSummon* summon = vehicle->GetBase()->ToTempSummon())
                    if (summon->GetTimer() < 49 * IN_MILLISECONDS)
                        return true;


            if (target->GetTransSeat() == _seatIndex || target->GetTransSeat() == _seatIndex + 2)
                return true;

            return false;
        }
    private:
        uint8 _seatIndex;
};

class spell_alakir_squall_line_pre_aura : public SpellScript
{
    PrepareSpellScript(spell_alakir_squall_line_pre_aura);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        uint8 seatIndex = urand(0, 5);
        targets.remove_if(SquallLineGapTargetSelector(seatIndex));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_alakir_squall_line_pre_aura::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_alakir_squall_line_script : public SpellScript
{
    PrepareSpellScript(spell_alakir_squall_line_script);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetHitUnit();
            if (caster->GetVehicleKit() && caster->GetVehicleKit()->GetAvailableSeatCount())
            {
                target->CastSpell(caster, GetSpellInfo()->Effects[effIndex].BasePoints, true);
                target->ApplySpellImmune(0, IMMUNITY_ID, GetSpellInfo()->Id, true);
                target->m_Events.AddEvent(new SquallLineImmunityRemovalEvent(target, GetSpellInfo()->Id), target->m_Events.CalculateTime(6000));
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_squall_line_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_alakir_relentless_storm_initial_vehicle_ride_trigger : public SpellScript
{
    PrepareSpellScript(spell_alakir_relentless_storm_initial_vehicle_ride_trigger);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_relentless_storm_initial_vehicle_ride_trigger::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_alakir_relentless_storm_initial_vehicle_ride : public SpellScript
{
    PrepareSpellScript(spell_alakir_relentless_storm_initial_vehicle_ride);

    void SetTarget(WorldObject*& target)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (ObjectGuid guid = instance->GetObjectGuid(DATA_FREE_RELENTLESS_STORM_VEHICLE))
                if (Creature* hurricane = ObjectAccessor::GetCreature(*GetCaster(), guid))
                    target = hurricane;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_alakir_relentless_storm_initial_vehicle_ride::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

class spell_alakir_eye_of_the_storm : public SpellScript
{
    PrepareSpellScript(spell_alakir_eye_of_the_storm);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE_TELEPORT });
    }

    void HandleExtraEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        float x = RelentlessStormTeleportReferencePosition.GetPositionX() + frand(-15.0f, 15.0f);
        float y = RelentlessStormTeleportReferencePosition.GetPositionY() + frand(-15.0f, 15.0f);
        float z = RelentlessStormTeleportReferencePosition.GetPositionZ() + frand(-15.0f, 15.0f);

        target->CastSpell(x, y, z, SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE_TELEPORT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_eye_of_the_storm::HandleExtraEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

void AddSC_boss_alakir()
{
    RegisterThroneOfTheFourWindsCreatureAI(boss_alakir);
    RegisterThroneOfTheFourWindsCreatureAI(npc_alakir_ice_storm);
    RegisterThroneOfTheFourWindsCreatureAI(npc_alakir_stormling);

    RegisterSpellScript(spell_alakir_lightning_strike_script);
    RegisterSpellScript(spell_alakir_lightning_strike_periodic);
    RegisterSpellScript(spell_alakir_lightning_strike_damage);
    RegisterAuraScript(spell_alakir_electrocute);
    RegisterSpellScript(spell_alakir_squall_line_pre_aura);
    RegisterSpellScript(spell_alakir_squall_line_script);
    RegisterSpellScript(spell_alakir_relentless_storm_initial_vehicle_ride_trigger);
    RegisterSpellScript(spell_alakir_relentless_storm_initial_vehicle_ride);
    RegisterSpellScript(spell_alakir_eye_of_the_storm);
}
