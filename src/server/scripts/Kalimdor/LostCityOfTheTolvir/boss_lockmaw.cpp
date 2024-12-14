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
#include "Containers.h"
#include "InstanceScript.h"
#include "lost_city_of_the_tolvir.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum LockmawSpells
{
    // Lockmaw
    SPELL_VISCOUS_POISON        = 81630,
    SPELL_SCENT_OF_BLOOD        = 81690,
    SPELL_VENOMOUS_RAGE         = 81706,
    SPELL_DUST_FLAIL            = 81652,
    SPELL_DUST_FLAIL_CHANNELED  = 81642,

    // Add Stalker
    SPELL_SUMMON_CROCOLISK      = 84242,
    SPELL_AUGH_1                = 84809, // Casts Paralytic Blow Dart
    SPELL_AUGH_2                = 84808, // Casts Whirlwind

    // Adds
    SPELL_STEALTHED             = 84244,

    // Dust Flail
    SPELL_DUST_FLAIL_PERIODIC   = 81646,

    // Augh (Add)
    SPELL_PARALYTIC_BLOW_DART   = 84799,
    SPELL_SMOKE_BOMB            = 84768,
    SPELL_RANDOM_AGGRO_TAUNT    = 50230,
    SPELL_WHIRLWIND             = 84784,

    // Augh (Boss)
    SPELL_FRENZY                = 91415,
    SPELL_DRAGONS_BREATH        = 83776,
    SPELL_WHIRLWIND_BOSS        = 91408
};

enum LockmawEvents
{
    // Lockmaw
    EVENT_VISCOUS_POISON = 1,
    EVENT_SCENT_OF_BLOOD,
    EVENT_VENOMOUS_RAGE,
    EVENT_DUST_FLAIL,
    EVENT_CHANNEL_DUST_FLAIL,
    EVENT_TURN_AGGRESSIVE,
    EVENT_SUMMON_AUGH_ADD,

    // Augh (Add)
    EVENT_MOVE_TOWARDS_BOSS,
    EVENT_HARASS_PLAYERS,
    EVENT_PARALYTIC_BLOW_DART,
    EVENT_SCREAM,
    EVENT_SMOKE_BOMB,
    EVENT_WHIRLWIND,
    EVENT_STEALTHED,
    EVENT_LEAVE_ARENA,

    // Augh (Boss)
    EVENT_SAY_INTRO_2,
    EVENT_SET_EMOTE_STATE,
    EVENT_TURN_ATTACKABLE,
    EVENT_SAY_INTRO_3,
    EVENT_SAY_INTRO_4,
    EVENT_SAY_INTRO_5,
    EVENT_DRAGONS_BREATH
};

enum LockmawPhases
{
    // Augh (Boss)
    PHASE_INTRO     = 1,
    PHASE_COMBAT    = 2
};

enum LockmawTexts
{
    // Augh (Adds)
    SAY_HARASS_PLAYER       = 0,
    SAY_SCREAM              = 1,

    // Augh (Boss)
    SAY_ANNOUNCE_APPEARANCE = 0,
    SAY_INTRO_1             = 1,
    SAY_INTRO_2             = 2,
    SAY_INTRO_3             = 3,
    SAY_INTRO_4             = 4,
    SAY_INTRO_5             = 5
};

enum class LockmawAughAddType : uint8
{
    ParalyticBlowDart   = 0,
    Whirlwind           = 1
};

enum LockmawMovemPoints
{
    POINT_PARALYTIC_BLOW_DART   = 0,
    POINT_AUGH_HOME_POSITION    = 0
};

// Instead of using a fixate or taunt aura, the Crocolisks use a flat threat amount instead
static constexpr float SCENT_OF_BLOOD_THREAT_AMOUNT = 500000.f;
static Position const AughRespawnPosition = { -11062.5f, -1662.39f, 0.7606202f, 0.8028514f };

struct boss_lockmaw : public BossAI
{
    boss_lockmaw(Creature* creature) : BossAI(creature, BOSS_LOCKMAW), _enraged(false), _aughAddType(LockmawAughAddType::ParalyticBlowDart) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_VISCOUS_POISON, 10s);
        events.ScheduleEvent(EVENT_SCENT_OF_BLOOD, 5s);
        events.ScheduleEvent(EVENT_DUST_FLAIL, 18s);
        events.ScheduleEvent(EVENT_SUMMON_AUGH_ADD, 8s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SCENT_OF_BLOOD);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VISCOUS_POISON);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
            return;

        if (!_enraged && me->HealthBelowPctDamaged(30, damage))
        {
            events.ScheduleEvent(EVENT_VENOMOUS_RAGE, 1ms);
            _enraged = true;
        }
    }

    bool CanAIAttack(Unit const* victim) const override
    {
        // Patch 4.0.6 (2011-02-08): Lockmaw no longer tolerates fighting in his treasure room.
        return victim && victim->IsOutdoors();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_DUST_FLAIL_CASTER:
                summon->CastSpell(nullptr, SPELL_DUST_FLAIL_PERIODIC);
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

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_VISCOUS_POISON:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 45.f, true, 0.f))
                        DoCast(target, SPELL_VISCOUS_POISON);
                    else
                        DoCastVictim(SPELL_VISCOUS_POISON);

                    events.Repeat(30s);
                    break;
                case EVENT_SCENT_OF_BLOOD:
                    // just a occasional cleanup of despawned summons to keep the container slim
                    summons.RemoveNotExisting();
                    DoCastAOE(SPELL_SCENT_OF_BLOOD);
                    events.Repeat(30s);
                    break;
                case EVENT_VENOMOUS_RAGE:
                    DoCastSelf(SPELL_VENOMOUS_RAGE);
                    break;
                case EVENT_DUST_FLAIL:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCastSelf(SPELL_DUST_FLAIL);
                    events.ScheduleEvent(EVENT_CHANNEL_DUST_FLAIL, 1s);
                    events.Repeat(30s);
                    break;
                case EVENT_CHANNEL_DUST_FLAIL:
                    if (Creature const* dustFlail = instance->GetCreature(DATA_DUST_FLAIL))
                    {
                        // because splines need one update tick to update the position, we have to set the orientation manually because we need it NOW.
                        me->SetOrientation(me->GetAbsoluteAngle(dustFlail));
                        me->SetFacingToObject(dustFlail);
                        DoCastSelf(SPELL_DUST_FLAIL_CHANNELED);
                        events.ScheduleEvent(EVENT_TURN_AGGRESSIVE, 7s);
                    }
                    else
                        me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_TURN_AGGRESSIVE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_SUMMON_AUGH_ADD:
                    instance->SetData(DATA_SHUFFLE_ADD_STALKERS, 0);
                    if (Creature* addStalker = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ADD_STALKER_1)))
                    {
                        addStalker->CastSpell(nullptr, _aughAddType == LockmawAughAddType::ParalyticBlowDart ? SPELL_AUGH_1 : SPELL_AUGH_2);
                        events.Repeat(_aughAddType == LockmawAughAddType::ParalyticBlowDart ? 20s : 40s);
                        _aughAddType = _aughAddType == LockmawAughAddType::ParalyticBlowDart ? LockmawAughAddType::Whirlwind : LockmawAughAddType::ParalyticBlowDart;
                    }
                    break;
                default:
                    break;
            }
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
private:
    bool _enraged;
    LockmawAughAddType _aughAddType;
};

struct npc_lockmaw_frenzied_crocolisk : public ScriptedAI
{
    npc_lockmaw_frenzied_crocolisk(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoZoneInCombat();
        DoCastSelf(SPELL_STEALTHED);
        me->SetCorpseDelay(5); // Frenzied Crocolisks despawn 5 seconds after death

        if (Unit* victim = SelectTarget(SelectTargetMethod::Random, 0, 500.f, true, true, SPELL_SCENT_OF_BLOOD))
            AddThreat(victim, SCENT_OF_BLOOD_THREAT_AMOUNT);
    }
};

static constexpr float AUGH_DISTANCE_TO_BOSS = 20.f;

struct npc_lockmaw_augh_add : public ScriptedAI
{
    npc_lockmaw_augh_add(Creature* creature) : ScriptedAI(creature), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();

        if (me->GetEntry() == NPC_AUGH_ADD_1)
            me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_AUGH_ADD_1)
        {
            DoCastSelf(SPELL_STEALTHED);
            _events.ScheduleEvent(EVENT_STEALTHED, 1ms);
            _events.ScheduleEvent(EVENT_MOVE_TOWARDS_BOSS, 2s);
        }
        else
        {
            DoZoneInCombat();
            _events.ScheduleEvent(EVENT_STEALTHED, 2s);
            _events.ScheduleEvent(EVENT_WHIRLWIND, 3s);
        }
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE && pointId != POINT_PARALYTIC_BLOW_DART)
            return;

        _events.ScheduleEvent(EVENT_HARASS_PLAYERS, 1ms);
        _events.ScheduleEvent(EVENT_PARALYTIC_BLOW_DART, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        // Augh does perform events even if he is not engaged, so we do not return here
        UpdateVictim();

        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TOWARDS_BOSS:
                {
                    DoZoneInCombat();
                    Creature* lockmaw = _instance->GetCreature(BOSS_LOCKMAW);
                    if (!lockmaw)
                    {
                        // This should never happen at this stage, but just to be sure....
                        me->DespawnOrUnsummon();
                        return;
                    }
                    me->GetMotionMaster()->MovePoint(POINT_PARALYTIC_BLOW_DART, lockmaw->GetPosition(), true, std::nullopt, std::nullopt, MovementWalkRunSpeedSelectionMode::ForceWalk, AUGH_DISTANCE_TO_BOSS);
                    break;
                }
                case EVENT_HARASS_PLAYERS:
                    Talk(SAY_HARASS_PLAYER);
                    break;
                case EVENT_PARALYTIC_BLOW_DART:
                    DoCastAOE(SPELL_PARALYTIC_BLOW_DART, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    _events.ScheduleEvent(EVENT_SCREAM, 3s);
                    break;
                case EVENT_SCREAM:
                    Talk(SAY_SCREAM);
                    _events.ScheduleEvent(EVENT_SMOKE_BOMB, 1s);
                    break;
                case EVENT_SMOKE_BOMB:
                    DoCastAOE(SPELL_SMOKE_BOMB);
                    me->DespawnOrUnsummon(3s + 500ms);
                    break;
                case EVENT_WHIRLWIND:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastAOE(SPELL_RANDOM_AGGRO_TAUNT);
                    DoCastSelf(SPELL_WHIRLWIND);
                    _events.ScheduleEvent(EVENT_LEAVE_ARENA, 20s);
                    break;
                case EVENT_STEALTHED:
                    DoCastSelf(SPELL_STEALTHED);
                    break;
                case EVENT_LEAVE_ARENA:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    if (Creature* addStalker = me->FindNearestCreature(NPC_ADD_STALKER, 200.f))
                        me->GetMotionMaster()->MovePoint(0, addStalker->GetPosition());
                    me->DespawnOrUnsummon(4s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_lockmaw_augh_boss : public ScriptedAI
{
    npc_lockmaw_augh_boss(Creature* creature) : ScriptedAI(creature), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
        if (_instance->GetData(DATA_HEROIC_AUGH_DESPAWNED))
            me->Relocate(AughRespawnPosition);
        else
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);

        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        if (!_instance->GetData(DATA_HEROIC_AUGH_DESPAWNED))
        {
            Talk(SAY_ANNOUNCE_APPEARANCE);
            me->GetMotionMaster()->MovePoint(POINT_AUGH_HOME_POSITION, AughRespawnPosition, true, std::nullopt, std::nullopt, MovementWalkRunSpeedSelectionMode::ForceWalk);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetEmoteState(EMOTE_ONESHOT_NONE);
        DoCastSelf(SPELL_FRENZY);
        _events.SetPhase(PHASE_COMBAT);
        _events.ScheduleEvent(EVENT_PARALYTIC_BLOW_DART, 8s);
        _events.ScheduleEvent(EVENT_WHIRLWIND, 9s);
        _events.ScheduleEvent(EVENT_DRAGONS_BREATH, 6s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _instance->SetData(DATA_HEROIC_AUGH_DESPAWNED, 1);
        me->DespawnOrUnsummon(0s, 30s);
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE && pointId != POINT_AUGH_HOME_POSITION)
            return;

        me->SetFacingTo(AughRespawnPosition.GetOrientation());
        Talk(SAY_INTRO_1);

        _events.SetPhase(PHASE_INTRO);
        _events.ScheduleEvent(EVENT_SAY_INTRO_2, 3s, 0, PHASE_INTRO);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !_events.IsInPhase(PHASE_INTRO))
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SAY_INTRO_2:
                    Talk(SAY_INTRO_2);
                    _events.ScheduleEvent(EVENT_SET_EMOTE_STATE, 3s + 500ms, 0, PHASE_INTRO);
                    break;
                case EVENT_SET_EMOTE_STATE:
                    me->SetEmoteState(EMOTE_STATE_SPELL_CHANNEL_OMNI);
                    _events.ScheduleEvent(EVENT_TURN_ATTACKABLE, 3s + 500ms, 0, PHASE_INTRO);
                    break;
                case EVENT_TURN_ATTACKABLE:
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    _events.ScheduleEvent(EVENT_SAY_INTRO_3, 11s, 0, PHASE_INTRO);
                    break;
                case EVENT_SAY_INTRO_3:
                    Talk(SAY_INTRO_3);
                    _events.ScheduleEvent(EVENT_SAY_INTRO_4, 8s + 500ms, 0, PHASE_INTRO);
                    break;
                case EVENT_SAY_INTRO_4:
                    Talk(SAY_INTRO_4);
                    _events.ScheduleEvent(EVENT_SAY_INTRO_5, 8s + 500ms, 0, PHASE_INTRO);
                    break;
                case EVENT_SAY_INTRO_5:
                    Talk(SAY_INTRO_5);
                    _events.ScheduleEvent(EVENT_SAY_INTRO_3, 21s, 0, PHASE_INTRO);
                    break;
                case EVENT_PARALYTIC_BLOW_DART:
                    DoCastAOE(SPELL_PARALYTIC_BLOW_DART, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    _events.Repeat(10s, 15s);
                    break;
                case EVENT_WHIRLWIND:
                    DoCastAOE(SPELL_RANDOM_AGGRO_TAUNT);
                    DoCastSelf(SPELL_WHIRLWIND_BOSS);
                    _events.Repeat(29s);
                    break;
                case EVENT_DRAGONS_BREATH:
                    DoCastAOE(SPELL_DRAGONS_BREATH);
                    _events.Repeat(28s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

class spell_lockmaw_scent_of_blood : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_CROCOLISK });
    }

    void SelectTarget(std::list<WorldObject*>& targets)
    {
        if (targets.size() <= 1)
            return;

        std::list<WorldObject*> targetsCopy = targets;
        targetsCopy.remove_if([caster = GetCaster()](WorldObject const* target)
        {
            return caster->GetVictim() != target;
        });

        if (!targetsCopy.empty())
        {
            Trinity::Containers::RandomResize(targetsCopy, 1);
            targets = targetsCopy;
        }
        else
            Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleCrocoliskSummoning()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        // Shuffle the stored add stalkers so that we will get four random add stalkers in the next step below
        instance->SetData(DATA_SHUFFLE_ADD_STALKERS, 0);

        for (uint32 i = DATA_ADD_STALKER_1; i <= DATA_ADD_STALKER_4; ++i)
            if (Creature* addStalker = ObjectAccessor::GetCreature(*caster, instance->GetGuidData(i)))
                addStalker->CastSpell(nullptr, SPELL_SUMMON_CROCOLISK);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lockmaw_scent_of_blood::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        AfterCast += SpellCastFn(spell_lockmaw_scent_of_blood::HandleCrocoliskSummoning);
    }
};

void AddSC_boss_lockmaw()
{
    RegisterLostCityOfTheTolvirAI(boss_lockmaw);
    RegisterLostCityOfTheTolvirAI(npc_lockmaw_frenzied_crocolisk);
    RegisterLostCityOfTheTolvirAI(npc_lockmaw_augh_add);
    RegisterLostCityOfTheTolvirAI(npc_lockmaw_augh_boss);
    RegisterSpellScript(spell_lockmaw_scent_of_blood);
}
