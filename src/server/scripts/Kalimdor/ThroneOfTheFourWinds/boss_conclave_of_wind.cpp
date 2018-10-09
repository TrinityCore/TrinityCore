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
#include "AreaBoundary.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Spell.h"
#include "Player.h"

enum Spells
{
    // Conclave of Wind
    SPELL_WINDS_PRE_EFFECT_WARNING      = 96508,
    SPELL_POWER_DRAIN                   = 89840,
    SPELL_WIND_DISTANCE_CHECKER         = 85763,

    // Anshal
    SPELL_PRE_FIGHT_VISUAL_WEST         = 85537,
    SPELL_WITHERING_WINDS_DAMAGE        = 93168,
    SPELL_NURTURE                       = 85422,
    SPELL_SOOTHING_BREEZE               = 86205,
    SPELL_ZEPHYR                        = 84638,
    SPELL_TELEPORT_TO_CENTER_WEST       = 89844,

    // Nezir
    SPELL_PRE_FIGHT_VISUAL_NORTH        = 85532,
    SPELL_CHILLING_WINDS_DAMAGE         = 93163,
    SPELL_TELEPORT_TO_CENTER_NORTH      = 89843,

    // Rohash
    SPELL_PRE_FIGHT_VISUAL_EAST         = 85538,
    SPELL_DEAFENING_WINDS_DAMAGE        = 93166,
    SPELL_SLICING_GALE                  = 86182,
    SPELL_STORM_SHIELD                  = 93059,
    SPELL_SUMMON_TORNADOS               = 86192,
    SPELL_WIND_BLAST                    = 86193,

    // World Trigger
    SPELL_POWER_GAIN                    = 89898,

    // West Wind
    SPELL_WITHERING_WINDS_RESET_AURA    = 89137,

    // North Wind
    SPELL_CHILLING_WINDS_RESET_AURA     = 89135,

    // East Wind
    SPELL_DEAFENING_WINDS_RESET_AURA    = 89136,

    // Ravenous Creeper Trigger
    SPELL_NURTURE_VISUAL                = 85428,
    SPELL_NURTURE_SUMMON                = 85429,

    // Ravenous Creeper
    SPELL_TOXIC_SPORES                  = 86281,
    SPELL_AI_CLEAR_TARGET               = 89020,

    // World Trigger
    SPELL_WIND_BLAST_SPEED_BUFF         = 93106,
};

#define SPELL_DEAFENING_WINDS   RAID_MODE<uint32>(85573, 93190, 93191, 93192)
#define SPELL_CHILLING_WINDS    RAID_MODE<uint32>(85578, 93147, 93148, 93149)
#define SPELL_WITHERING_WINDS   RAID_MODE<uint32>(85576, 93181, 93182, 93183)

enum Events
{
    // Conclave of Wind
    EVENT_PRE_WIND_EFFECT_WARNING = 1,
    EVENT_TELEPORT_TO_CENTER,

    // Anshal
    EVENT_SOOTHING_BREEZE,
    EVENT_NURTURE,

    // Nezir

    // Rohash
    EVENT_SLICING_GALE,
    EVENT_STORM_SHIELD,
    EVENT_SUMMON_TORNADOS,
    EVENT_WIND_BLAST,

    // Ravenous Creeper Trigger
    EVENT_SUMMON_RAVENOUS_CREEPER,

    // Ravenous Creeper
    EVENT_ATTACK_PLAYERS,
    EVENT_TOXIC_SPORES,
};

enum Actions
{
    ACTION_NO_NEARBY_PLAYER     = 1,
    ACTION_PLAYER_LEFT_PLATFORM = 2,
};

enum Texts
{
    // Conclave of Wind
    SAY_AGGRO                           = 0,
    SAY_OUT_OF_RANGE                    = 1,
    SAY_GATHER_STRENGTH                 = 2,
    SAY_ANNOUNCE_GATHER_POWER           = 3,
    SAY_SPECIAL_ABILITY                 = 4,
    SAY_SLAY                            = 5,

    // Rohash
    SAY_ANNOUNCE_WIND_BLAST             = 6,

    // World Trigger
    SAY_ANNOUNCE_NEAR_FULL_STRENGHTH    = 0
};

enum SpellVisualKits
{
    SPELL_VISUAL_STORM_SHIELD = 18812
};

enum GuidData
{
    DATA_WIND_BLAST_TRIGGER = 0
};

#define MAX_HOME_POSITION_DISTANCE 65.0f

// A collection of helpers that all creatures related to the encounter can access
namespace ConclaveHandler
{
    bool IsTargetOnPlatform(Position attackerPosition, Unit* target)
    {
        // Do not attack our target when he is on the fall catcher vehicle
        if (target->GetVehicle())
            return false;

        return target->GetExactDist2d(attackerPosition) < MAX_HOME_POSITION_DISTANCE;
    }
}

Position const WesternPlatformCenterPosition    = { -48.081f,   1053.930f, 199.572f  };
Position const WindBlastTriggerPosition         = { -111.3979f, 594.4973f, 206.2773f };

struct boss_anshal : public BossAI
{
    boss_anshal(Creature* creature) : BossAI(creature, DATA_CONCLAVE_OF_WIND)
    {
        Initialize();
    }

    void Initialize()
    {
    }

    void AttackStart(Unit* who) override
    {
        if (ConclaveHandler::IsTargetOnPlatform(me->GetHomePosition(), who))
        {
            BossAI::AttackStart(who);
            events.CancelEvent(EVENT_PRE_WIND_EFFECT_WARNING);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        _JustEngagedWith();
        me->SetReactState(REACT_AGGRESSIVE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        me->RemoveAurasDueToSpell(SPELL_PRE_FIGHT_VISUAL_WEST);
        events.ScheduleEvent(EVENT_SOOTHING_BREEZE, 15s, 16s);
        events.ScheduleEvent(EVENT_NURTURE, 27s, 28s);

        if (ConclaveHandler::IsTargetOnPlatform(me->GetHomePosition(), who))
            Talk(SAY_AGGRO);
        else
            events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, 1s);
    }

    void Reset()
    {
        _Reset();
        Initialize();
        me->SetReactState(REACT_PASSIVE);
        me->SetPower(POWER_MANA, 0);
        _ravenousCreeperGUIDs.clear();
    }

    void KilledUnit(Unit* killed) override
    {
        if (killed->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
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

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_NO_NEARBY_PLAYER:
                if (!me->HasAura(SPELL_WITHERING_WINDS))
                {
                    Talk(SAY_OUT_OF_RANGE);
                    me->InterruptNonMeleeSpells(true);
                    DoCastSelf(SPELL_WITHERING_WINDS);
                    me->AttackStop();
                    me->StopMoving();
                    events.ScheduleEvent(EVENT_TELEPORT_TO_CENTER, 1s);
                }
                break;
            case ACTION_PLAYER_LEFT_PLATFORM:
                if (!me->IsInCombat())
                    break;
                events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, 2s);
                break;
            default:
                break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_WIND_DISTANCE_CHECKER)
        {
            me->RemoveAurasDueToSpell(SPELL_WINDS_PRE_EFFECT_WARNING);
            me->RemoveAurasDueToSpell(SPELL_WITHERING_WINDS);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        if (summon->GetEntry() == NPC_RAVENOUS_CREEPER)
            _ravenousCreeperGUIDs.insert(summon->GetGUID());
    }

    uint32 GetData(uint32 type) const override
    {
        return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PRE_WIND_EFFECT_WARNING:
                    DoCastSelf(SPELL_WINDS_PRE_EFFECT_WARNING, true);
                    events.Repeat(2s + 500ms);
                    break;
                case EVENT_TELEPORT_TO_CENTER:
                    DoCastSelf(SPELL_TELEPORT_TO_CENTER_WEST);
                    break;
                case EVENT_SOOTHING_BREEZE:
                {
                    Unit* target = me;
                    // Clean expired guids from memory
                    for (ObjectGuid guid : _ravenousCreeperGUIDs)
                    {
                        if (!ObjectAccessor::GetCreature(*me, guid))
                            _ravenousCreeperGUIDs.erase(guid);
                    }

                    if (ObjectGuid creeperGuid = Trinity::Containers::SelectRandomContainerElement(_ravenousCreeperGUIDs))
                        if (Creature* creeper = ObjectAccessor::GetCreature(*me, creeperGuid))
                            target = creeper;

                    DoCast(target, SPELL_SOOTHING_BREEZE);
                    break;
                }
                case EVENT_NURTURE:
                    DoCastSelf(SPELL_NURTURE);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }

private:
    GuidSet _ravenousCreeperGUIDs;
};

struct boss_nezir : public BossAI
{
    boss_nezir(Creature* creature) : BossAI(creature, DATA_CONCLAVE_OF_WIND)
    {
        Initialize();
    }

    void Initialize()
    {
    }

    void AttackStart(Unit* who) override
    {
        if (ConclaveHandler::IsTargetOnPlatform(me->GetHomePosition(), who))
        {
            BossAI::AttackStart(who);
            events.CancelEvent(EVENT_PRE_WIND_EFFECT_WARNING);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        _JustEngagedWith();
        me->SetReactState(REACT_AGGRESSIVE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        me->RemoveAurasDueToSpell(SPELL_PRE_FIGHT_VISUAL_NORTH);

        if (ConclaveHandler::IsTargetOnPlatform(me->GetHomePosition(), who))
            Talk(SAY_AGGRO);
        else
            events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, 1s);
    }

    void Reset()
    {
        _Reset();
        Initialize();
        me->SetReactState(REACT_PASSIVE);
        me->SetPower(POWER_MANA, 0);
    }

    void KilledUnit(Unit* killed) override
    {
        if (killed->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
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

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_NO_NEARBY_PLAYER:
                if (!me->HasAura(SPELL_CHILLING_WINDS))
                {
                    Talk(SAY_OUT_OF_RANGE);
                    me->InterruptNonMeleeSpells(true);
                    DoCastSelf(SPELL_CHILLING_WINDS);
                    me->AttackStop();
                    me->StopMoving();
                    events.ScheduleEvent(EVENT_TELEPORT_TO_CENTER, 1s);
                }
                break;
            case ACTION_PLAYER_LEFT_PLATFORM:
                if (!me->IsInCombat())
                    break;
                events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, 2s);
                break;
            default:
                break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_WIND_DISTANCE_CHECKER)
        {
            me->RemoveAurasDueToSpell(SPELL_WINDS_PRE_EFFECT_WARNING);
            me->RemoveAurasDueToSpell(SPELL_CHILLING_WINDS);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
    }

    uint32 GetData(uint32 type) const override
    {
        return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PRE_WIND_EFFECT_WARNING:
                    DoCastSelf(SPELL_WINDS_PRE_EFFECT_WARNING, true);
                    events.Repeat(2s + 500ms);
                    break;
                case EVENT_TELEPORT_TO_CENTER:
                    DoCastSelf(SPELL_TELEPORT_TO_CENTER_NORTH);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct boss_rohash : public BossAI
{
    boss_rohash(Creature* creature) : BossAI(creature, DATA_CONCLAVE_OF_WIND)
    {
        Initialize();
    }

    void Initialize()
    {
    }

    void AttackStart(Unit* who) override
    {
        if (ConclaveHandler::IsTargetOnPlatform(me->GetHomePosition(), who))
        {
            BossAI::AttackStart(who);
            events.CancelEvent(EVENT_PRE_WIND_EFFECT_WARNING);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        _JustEngagedWith();
        me->SetReactState(REACT_AGGRESSIVE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        me->RemoveAurasDueToSpell(SPELL_PRE_FIGHT_VISUAL_EAST);
        events.ScheduleEvent(EVENT_SLICING_GALE, 1s);
        events.ScheduleEvent(EVENT_SUMMON_TORNADOS, 8s);
        events.ScheduleEvent(EVENT_WIND_BLAST, 32s + 500ms);

        if (IsHeroic())
            events.ScheduleEvent(EVENT_STORM_SHIELD, 30s);

        if (ConclaveHandler::IsTargetOnPlatform(me->GetHomePosition(), who))
            Talk(SAY_AGGRO);
        else
            events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, 1s);
    }

    void Reset()
    {
        _Reset();
        Initialize();
        me->SetReactState(REACT_PASSIVE);
        me->SetPower(POWER_MANA, 0);
        if (Creature* dummy = DoSummon(NPC_WORLD_TRIGGER_IMMUNE_TO_PC, WindBlastTriggerPosition, 0, TEMPSUMMON_MANUAL_DESPAWN))
        {
            _windBlastTriggerGUID = dummy->GetGUID();
            dummy->CastSpell(dummy, SPELL_WIND_BLAST_SPEED_BUFF, true);
            dummy->GetMotionMaster()->MoveCirclePath(me->GetPositionX(), me->GetPositionY(), dummy->GetPositionZ(), dummy->GetExactDist2d(me), true, 19);
        }
    }

    void KilledUnit(Unit* killed) override
    {
        if (killed->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
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

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_NO_NEARBY_PLAYER:
                if (!me->HasAura(SPELL_DEAFENING_WINDS))
                {
                    Talk(SAY_OUT_OF_RANGE);
                    me->InterruptNonMeleeSpells(true);
                    DoCastSelf(SPELL_DEAFENING_WINDS);
                    me->AttackStop();
                }
                break;
            case ACTION_PLAYER_LEFT_PLATFORM:
                if (!me->IsInCombat())
                    break;
                events.ScheduleEvent(EVENT_PRE_WIND_EFFECT_WARNING, 2s);
                break;
            default:
                break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_WIND_DISTANCE_CHECKER)
        {
            me->RemoveAurasDueToSpell(SPELL_WINDS_PRE_EFFECT_WARNING);
            me->RemoveAurasDueToSpell(SPELL_DEAFENING_WINDS);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_TORNADO:
                summon->SetHomePosition(me->GetPosition());
                summon->GetMotionMaster()->MoveRandom(25.0f);
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        return 0;
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        if (type == DATA_WIND_BLAST_TRIGGER)
            return _windBlastTriggerGUID;

        return ObjectGuid::Empty;
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PRE_WIND_EFFECT_WARNING:
                    DoCastSelf(SPELL_WINDS_PRE_EFFECT_WARNING, true);
                    events.Repeat(2s + 500ms);
                    break;
                case EVENT_SLICING_GALE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, MAX_HOME_POSITION_DISTANCE, true, 0))
                        DoCast(target, SPELL_SLICING_GALE);
                    events.Repeat(2s + 100ms);
                    break;
                case EVENT_STORM_SHIELD:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_STORM_SHIELD, 0, 0);
                    DoCastSelf(SPELL_STORM_SHIELD);
                    break;
                case EVENT_SUMMON_TORNADOS:
                    DoCastSelf(SPELL_SUMMON_TORNADOS);
                    break;
                case EVENT_WIND_BLAST:
                    DoCastAOE(SPELL_WIND_BLAST);
                    break;
                default:
                    break;
            }
        }
    }
private:
    ObjectGuid _windBlastTriggerGUID;
};

struct npc_conclave_of_wind_ravenous_creeper_trigger : public ScriptedAI
{
    npc_conclave_of_wind_ravenous_creeper_trigger(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCastSelf(SPELL_NURTURE_VISUAL);
        _events.ScheduleEvent(EVENT_SUMMON_RAVENOUS_CREEPER, 8s + 250ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SUMMON_RAVENOUS_CREEPER:
                    DoCastSelf(SPELL_NURTURE_SUMMON, true);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
};

CircleBoundary const anshalPlatformCircle(Position(-47.953f, 1053.439f), MAX_HOME_POSITION_DISTANCE);
CreatureBoundary const AnshalPlatformBoundary = { &anshalPlatformCircle };

struct npc_conclave_of_wind_ravenous_creeper : public ScriptedAI
{
    npc_conclave_of_wind_ravenous_creeper(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        SetBoundary(&AnshalPlatformBoundary);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoZoneInCombat();
        _events.ScheduleEvent(EVENT_ATTACK_PLAYERS, 1s + 500ms);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_TOXIC_SPORES, 5s, 6s);
    }

    void AttackStart(Unit* who) override
    {
        if (ConclaveHandler::IsTargetOnPlatform(WesternPlatformCenterPosition, who))
            ScriptedAI::AttackStart(who);
        /*
        else
            DoCast(who, SPELL_AI_CLEAR_TARGET); //our threat system works different.Need to merge the threat system rewrite first.
        */
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_AI_CLEAR_TARGET)
            DoModifyThreatPercent(target, -100);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->SetLastDamagedTime(0);
        me->SetCannotReachTarget(false);
        me->DoNotReacquireTarget();
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ATTACK_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_TOXIC_SPORES:
                    DoCastSelf(SPELL_TOXIC_SPORES);
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
};

class spell_conclave_of_wind_winds_pre_effect_warning : public AuraScript
{
    PrepareAuraScript(spell_conclave_of_wind_winds_pre_effect_warning);

    void OnAuraRemoveHandler(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            if (Unit* caster = GetCaster())
                if (Creature* conclave = caster->ToCreature())
                    if (conclave->IsAIEnabled)
                        conclave->AI()->DoAction(ACTION_NO_NEARBY_PLAYER);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_conclave_of_wind_winds_pre_effect_warning::OnAuraRemoveHandler, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_conclave_of_wind_teleport_to_center : public SpellScript
{
    PrepareSpellScript(spell_conclave_of_wind_teleport_to_center);

    void SetDest(SpellDestination& dest)
    {
        if (Creature* creature = GetCaster()->ToCreature())
            dest.Relocate(creature->GetHomePosition());
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_conclave_of_wind_teleport_to_center::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

class spell_conclave_of_wind_winds : public AuraScript
{
    PrepareAuraScript(spell_conclave_of_wind_winds);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WITHERING_WINDS_DAMAGE,
                SPELL_CHILLING_WINDS_DAMAGE,
                SPELL_DEAFENING_WINDS_DAMAGE
            });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        Unit* owner = GetUnitOwner();
        uint8 tickNumber = aurEff->GetTickNumber();
        int32 damage = std::min<uint32>(1500 * tickNumber, 150000);
        uint32 spellId = 0;
        switch (owner->GetEntry())
        {
            case BOSS_ANSHAL:
                spellId = SPELL_WITHERING_WINDS_DAMAGE;
                break;
            case BOSS_NEZIR:
                spellId = SPELL_CHILLING_WINDS_DAMAGE;
                break;
            case BOSS_ROHASH:
                spellId = SPELL_DEAFENING_WINDS_DAMAGE;
                break;
            default:
                break;
        }

        if (spellId)
            owner->CastCustomSpell(spellId, SPELLVALUE_BASE_POINT0, damage, owner, true);
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_conclave_of_wind_winds::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_conclave_of_wind_wind_blast : public SpellScript
{
    PrepareSpellScript(spell_conclave_of_wind_wind_blast);

    void SetTarget(WorldObject*& target)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (Creature* rohash = instance->GetCreature(DATA_ROHASH))
                if (Creature* trigger = ObjectAccessor::GetCreature(*GetCaster(), rohash->AI()->GetGUID(DATA_WIND_BLAST_TRIGGER)))
                    target = trigger;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_conclave_of_wind_wind_blast::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

void AddSC_boss_conclave_of_wind()
{
    RegisterThroneOfTheFourWindsCreatureAI(boss_anshal);
    RegisterThroneOfTheFourWindsCreatureAI(boss_nezir);
    RegisterThroneOfTheFourWindsCreatureAI(boss_rohash);
    RegisterThroneOfTheFourWindsCreatureAI(npc_conclave_of_wind_ravenous_creeper_trigger);
    RegisterThroneOfTheFourWindsCreatureAI(npc_conclave_of_wind_ravenous_creeper);

    RegisterAuraScript(spell_conclave_of_wind_winds_pre_effect_warning);
    RegisterSpellScript(spell_conclave_of_wind_teleport_to_center);
    RegisterAuraScript(spell_conclave_of_wind_winds);
    RegisterSpellScript(spell_conclave_of_wind_wind_blast);
}
