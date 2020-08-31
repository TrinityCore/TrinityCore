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
#include "deadmines.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "VehicleDefines.h"
#include "GridNotifiers.h"
#include "Map.h"

enum Texts
{
    // Helix Gearbreaker
    SAY_AGGRO                   = 0,
    SAY_STICKY_BOMB             = 1,
    SAY_THROW_HELIX             = 2,
    SAY_ANNOUNCE_CHEST_BOMB     = 3,
    SAY_OAF_DEAD                = 4,
    SAY_SLAY                    = 5,
    SAY_DEATH                   = 6,

    // Lumbering Oaf
    SAY_OAF_SMASH_1             = 0,
    SAY_OAF_SMASH_2             = 1,

    // Helix' Crew
    SAY_CREW_JOIN_FIGHT         = 0
};

enum Spells
{
    // Helix Gearbreaker
    SPELL_THROW_BOMB_TARGETING          = 88268,
    SPELL_RIDE_FACE_TARGETING           = 88349,
    SPELL_RIDE_VEHICLE_OAF              = 52391,
    SPELL_RIDE_VEHICLE                  = 88360,
    SPELL_HELIX_RIDE_FACE_TIMER_AURA    = 88351,
    SPELL_HELIX_RIDE                    = 88337,
    SPELL_HELIX_CHEST_BOMB_EMOTE        = 91572,
    SPELL_CHEST_BOMB                    = 88352,
    SPELL_CHEST_BOMB_DAMAGE             = 88250,
    SPELL_OAFGUARD                      = 90546,
    SPELL_EMOTE_TALK                    = 79506,
    SPELL_VEHICLE_SWITCH_TO_SEAT_3      = 84225,
    SPELL_FORCECAST_EJECT_PASSENGER_1   = 88353,

    // Lumbering Oaf
    SPELL_OAF_GRAB_TARGETING            = 88289,
    SPELL_CHARGE                        = 88295,
    SPELL_OAF_SMASH                     = 88300,
    SPELL_HOLD_THROWN                   = 88373,
    SPELL_ATTACK_THROWN                 = 88374,

    // Sticky Bomb
    SPELL_ARMING_VISUAL_YELLOW          = 88315,
    SPELL_ARMING_VISUAL_ORANGE          = 88316,
    SPELL_ARMING_VISUAL_RED             = 88317,
    SPELL_STICKY_BOMB_ARMED_STATE       = 88319,
    SPELL_STICKY_BOMB_PERIODIC_TRIGGER  = 88329,
    SPELL_EXPLODE                       = 88974
};

uint32 const BombArmingVisualSpells[] =
{
    SPELL_ARMING_VISUAL_YELLOW,
    SPELL_ARMING_VISUAL_ORANGE,
    SPELL_ARMING_VISUAL_RED
};

enum DisplayIds
{
    DISPLAY_ID_BOMB_INVISIBLE = 11686
};

enum Events
{
    // Helix Gearbreaker
    EVENT_SUMMON_HELIX_CREW = 1,
    EVENT_HELIX_RIDE,
    EVENT_STICKY_BOMB,
    EVENT_OAF_SMASH,
    EVENT_THROW_HELIX,
    EVENT_RIDE_FACE,

    // Lumbering Oaf
    EVENT_PREPARE_OAF_SMASH,
    EVENT_OAF_SMASH_CHARGE,

    // Sticky Bomb
    EVENT_ARM_BOMB,
    EVENT_PERIODIC_TRIGGER,
    EVENT_EXPLOSION_COUNTDOWN,

    // Helix' Crew
    EVENT_THROW_BOMB,
    EVENT_TALK_READY
};

enum Actions
{
    // Lumbering Oaf
    ACTION_OAF_SMASH = 1,

    // Helix' Crw
    ACTION_TALK_CREW,

    // Sticky Bomb
    ACTION_BOMB_DETONATED,
};

enum Points
{
    POINT_CHARGE_PREP = 1
};

enum Phases
{
    PHASE_1 = 1,
    PHASE_2 = 2
};

enum Seats
{
    SEAT_HELIX          = 0,
    SEAT_PREPARE_THROW  = 2
};

Position const LumberingOafSummonPosition   = { -302.3611f, -516.3455f, 52.03153f, 0.1745329f };
Position const OafSmashStartigPosition      = { -289.8343f, -526.2162f, 49.83808f };
Position const ChargePos                    = { -289.5868f, -489.5746f, 49.91263f };

static constexpr uint8 const HelixCrewPositionCount = 4;
Position const HelixFirstCrewPositions[HelixCrewPositionCount] =
{
    { -283.8438f, -503.3698f, 60.512f,   1.902409f },
    { -285.8681f, -503.8264f, 60.55348f, 5.009095f },
    { -292.6788f, -503.7274f, 60.27357f, 4.468043f },
    { -289.8316f, -503.4063f, 60.36356f, 1.815142f }
};

Position const HelixSecondCrewPositions[HelixCrewPositionCount] =
{
    {-282.2639f, -503.8333f, 60.60244f, 5.201081f },
    {-287.474f,  -503.2708f, 60.44886f, 1.675516f },
    {-291.0781f, -504.0938f, 60.25187f, 4.607669f },
    {-294.1632f, -503.2326f, 60.1258f,  1.867502f }
};

struct boss_helix_gearbreaker : public BossAI
{
    boss_helix_gearbreaker(Creature* creature) : BossAI(creature, DATA_HELIX_GEARBREAKER), _firstStickyBomb(false)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);

        DoCastAOE(SPELL_HELIX_RIDE);

        events.SetPhase(PHASE_1);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_SUMMON_HELIX_CREW, 5s, 0, PHASE_1);

        events.ScheduleEvent(EVENT_STICKY_BOMB, 6s, 0, PHASE_1);
        events.ScheduleEvent(EVENT_OAF_SMASH, 17s, 0, PHASE_1);
        events.ScheduleEvent(EVENT_THROW_HELIX, 34s, 0, PHASE_1);
        events.ScheduleEvent(EVENT_HELIX_RIDE, 5s);
        events.ScheduleEvent(EVENT_HELIX_RIDE, 56s); // According to sniffs there are two spell casts
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_RIDE_VEHICLE);
        DoCastAOE(SPELL_FORCECAST_EJECT_PASSENGER_1, true);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_OAFGUARD);
        DoSummon(NPC_LUMBERING_OAF, LumberingOafSummonPosition, 2 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();

        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_RIDE_VEHICLE);
        if (Creature* lumberingOaf = instance->GetCreature(DATA_LUMBERING_OAF))
            if (lumberingOaf->IsAlive())
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, lumberingOaf);

        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
            case NPC_LUMBERING_OAF:
                Talk(SAY_OAF_DEAD);
                DoCastSelf(SPELL_EMOTE_TALK);
                me->RemoveAurasDueToSpell(SPELL_OAFGUARD);

                events.SetPhase(PHASE_2);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SUMMON_HELIX_CREW, 3s, 0, PHASE_2);
                if (!me->GetVehicleBase())
                    events.ScheduleEvent(EVENT_RIDE_FACE, 2s + 500ms, 0, PHASE_2);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // Helix cannot die while he is protected by his Lumbering Oaf
        if (damage >= me->GetHealth() && me->HasAura(SPELL_OAFGUARD))
            damage = me->GetHealth() - 1;
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_RIDE_VEHICLE)
            AttackStart(target);
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

                case EVENT_SUMMON_HELIX_CREW:
                    for (uint8 i = 0; i < HelixCrewPositionCount; i++)
                    {
                        if (events.IsInPhase(PHASE_1))
                        {
                            if (Creature* crew = DoSummon(NPC_HELIX_CREW, HelixFirstCrewPositions[i], 2 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN))
                                if (!i && crew->IsAIEnabled)
                                    crew->AI()->DoAction(ACTION_TALK_CREW);
                        }
                        else
                            DoSummon(NPC_HELIX_CREW, HelixSecondCrewPositions[i], 2 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    }
                    break;
                case EVENT_HELIX_RIDE:
                    DoCastAOE(SPELL_HELIX_RIDE);
                    events.Repeat(56s);
                    break;
                case EVENT_STICKY_BOMB:
                    DoCastAOE(SPELL_THROW_BOMB_TARGETING);
                    if (!_firstStickyBomb)
                    {
                        Talk(SAY_STICKY_BOMB);
                        _firstStickyBomb = true;
                    }
                    events.Repeat(3s + 500ms);
                    break;
                case EVENT_OAF_SMASH:
                    if (Creature* oaf = instance->GetCreature(DATA_LUMBERING_OAF))
                        if (oaf->IsAIEnabled)
                            oaf->AI()->DoAction(ACTION_OAF_SMASH);

                    events.RescheduleEvent(EVENT_STICKY_BOMB, 11s, 0, PHASE_1);
                    events.Repeat(52s);
                    break;
                case EVENT_THROW_HELIX:
                    Talk(SAY_THROW_HELIX);
                    DoCastSelf(SPELL_VEHICLE_SWITCH_TO_SEAT_3);
                    events.ScheduleEvent(EVENT_RIDE_FACE, 2s, 0, PHASE_1);
                    events.Repeat(52s);
                    events.RescheduleEvent(EVENT_STICKY_BOMB, 22s, 0, PHASE_1);
                    break;
                case EVENT_RIDE_FACE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastAOE(SPELL_RIDE_FACE_TARGETING);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    bool _firstStickyBomb;
};

struct npc_helix_lumbering_oaf : public ScriptedAI
{
    npc_helix_lumbering_oaf(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        if (Creature* helix = _instance->GetCreature(DATA_HELIX_GEARBREAKER))
            if (helix->IsAIEnabled)
                helix->AI()->DoZoneInCombat();
    }

    void JustAppeared() override
    {
        if (Creature* helix = _instance->GetCreature(DATA_HELIX_GEARBREAKER))
            helix->EnterVehicle(me);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_OAF_SMASH:
                DoCastAOE(SPELL_OAF_GRAB_TARGETING);
                break;
            default:
                break;
        }
    }

    void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
    {
        if (!passenger)
            return;

        if (apply && passenger->GetTypeId() == TYPEID_PLAYER)
        {
            Talk(SAY_OAF_SMASH_1);
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            _events.ScheduleEvent(EVENT_PREPARE_OAF_SMASH, 1s);
        }

        if (Creature* helix = passenger->ToCreature())
        {
            if (apply)
            {
                if (seatId == SEAT_PREPARE_THROW)
                {
                    helix->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    DoCastSelf(SPELL_HOLD_THROWN);
                }
                else if (seatId == SEAT_HELIX)
                {
                    helix->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    helix->SetReactState(REACT_PASSIVE);
                    helix->AttackStop();
                }
            }
            else if (seatId == SEAT_PREPARE_THROW)
            {
                me->RemoveAurasDueToSpell(SPELL_HOLD_THROWN);
                DoCastSelf(SPELL_ATTACK_THROWN);
            }
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (point)
        {
            case POINT_CHARGE_PREP:
                me->SetFacingTo(1.570796f);
                _events.ScheduleEvent(EVENT_OAF_SMASH_CHARGE, 1s);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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
                case EVENT_PREPARE_OAF_SMASH:
                    Talk(SAY_OAF_SMASH_2);
                    me->GetMotionMaster()->MovePoint(POINT_CHARGE_PREP, OafSmashStartigPosition, true);
                    break;
                case EVENT_OAF_SMASH_CHARGE:
                    DoCastAOE(SPELL_CHARGE);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_helix_sticky_bomb : public NullCreatureAI
{
    npc_helix_sticky_bomb(Creature* creature) : NullCreatureAI(creature), _countdown(0) { }

    void Reset() override
    {
        _events.ScheduleEvent(EVENT_ARM_BOMB, 2s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_BOMB_DETONATED:
                me->SetDisplayId(DISPLAY_ID_BOMB_INVISIBLE);
                me->RemoveAllAuras();
                me->DespawnOrUnsummon(2s + 500ms);
                _events.Reset();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARM_BOMB:
                    if (_countdown < 3)
                    {
                        DoCastSelf(BombArmingVisualSpells[_countdown]);
                        _events.Repeat(1s);
                        _countdown++;
                    }
                    else
                    {
                        DoCastSelf(SPELL_STICKY_BOMB_ARMED_STATE);
                        _events.ScheduleEvent(EVENT_PERIODIC_TRIGGER, 1s);
                    }
                    break;
            case EVENT_PERIODIC_TRIGGER:
                DoCastSelf(SPELL_STICKY_BOMB_PERIODIC_TRIGGER);
                _events.ScheduleEvent(EVENT_EXPLOSION_COUNTDOWN, 15s + 500ms);
                break;
            case EVENT_EXPLOSION_COUNTDOWN:
                if (_countdown)
                {
                    DoCastSelf(SPELL_ARMING_VISUAL_RED);
                    _events.Repeat(1s);
                    _countdown--;
                }
                else
                {
                    DoCastSelf(SPELL_EXPLODE);
                    DoAction(ACTION_BOMB_DETONATED);
                }
                break;
            default:
                break;
            }
        }
    }
private:
    EventMap _events;
    uint8 _countdown;
};

struct npc_helix_crew : public PassiveAI
{
    npc_helix_crew(Creature* creature) : PassiveAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_THROW_BOMB, 1s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_TALK_CREW:
                _events.ScheduleEvent(EVENT_TALK_READY, 1s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_THROW_BOMB:
                    DoCastAOE(SPELL_THROW_BOMB_TARGETING);
                    _events.Repeat(5s);
                    break;
                case EVENT_TALK_READY:
                    Talk(SAY_CREW_JOIN_FIGHT);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
};

class spell_helix_throw_bomb_targeting : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_helix_throw_bomb_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_helix_throw_bomb_targeting::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_helix_sticky_bomb_periodic_trigger : public AuraScript
{
    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        Creature* target = GetTarget()->ToCreature();
        if (!target || !target->IsAIEnabled)
            return;

        SpellInfo const* spell = sSpellMgr->GetSpellInfo(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell);
        if (!spell)
            return;

        if (Player* player = target->SelectNearestPlayer(spell->Effects[EFFECT_0].CalcRadius()))
        {
            if (!player->GetVehicleBase() && player->GetExactDist(target) <= 1.0f)
            {
                target->CastSpell(target, spell->Id, true);
                target->AI()->DoAction(ACTION_BOMB_DETONATED);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_helix_sticky_bomb_periodic_trigger::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_helix_oaf_grab_targeting : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_helix_oaf_grab_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_helix_oaf_grab_targeting::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_helix_force_player_to_ride_oaf : public SpellScript
{
    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_helix_force_player_to_ride_oaf::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_helix_oaf_smash : public SpellScript
{
    void HandleLaunch(SpellEffIndex effIndex)
    {
        // We do our own knockback here because the boss is immune to knockback effects
        // ... and because we have to use some additional spellinfo data
        if (Unit* caster = GetCaster())
        {
            float angle = caster->GetOrientation();
            float x = caster->GetPositionX() + cos(angle) * 1;
            float y = caster->GetPositionX() + sin(angle) * 1;
            float speedxy = float(GetSpellInfo()->Effects[effIndex].MiscValue) * 0.1;
            float speedz = float(GetSpellInfo()->Effects[effIndex].MiscValueB) * 0.1;

            caster->KnockbackFrom(x, y, speedxy, speedz);

            if (Creature* creature = caster->ToCreature())
            {
                creature->SetReactState(REACT_AGGRESSIVE);
                creature->setAttackTimer(BASE_ATTACK, creature->GetFloatValue(UNIT_FIELD_BASEATTACKTIME));
            }
        }
    }

    void Register()
    {
        OnEffectLaunch.Register(&spell_helix_oaf_smash::HandleLaunch, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
    }
};

class spell_helix_helix_ride : public AuraScript
{
    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_helix_helix_ride::AfterApply, EFFECT_0, SPELL_AURA_SET_VEHICLE_ID, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_helix_ride_face_targeting : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HELIX_RIDE,
                SPELL_HELIX_RIDE_FACE_TIMER_AURA
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([](WorldObject const* obj)->bool
        {
            Unit const* target = obj->ToUnit();
            return !target || !target->HasAura(SPELL_HELIX_RIDE);
        });

        // Make sure that we will always leap to a different player if available
        if (targets.size() > 1)
        {
            targets.remove_if([](WorldObject const* obj)->bool
            {
                Unit const* target = obj->ToUnit();
                return target->GetVehicleBase();
            });
        }

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Unit* target = GetHitUnit())
        {
            caster->GetThreatManager().ResetAllThreat();
            caster->CastSpell(caster, SPELL_HELIX_RIDE_FACE_TIMER_AURA);
            caster->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_helix_ride_face_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_helix_ride_face_targeting::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_helix_helix_ride_face_timer_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_RIDE_VEHICLE_OAF,
                SPELL_CHEST_BOMB,
                SPELL_HELIX_CHEST_BOMB_EMOTE
            });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        InstanceScript* instance = target->GetInstanceScript();
        if (!instance)
            return;

        if (target->GetMap()->IsHeroic())
        {
            if (Unit* player = target->GetVehicleBase())
            {
                target->CastSpell(player, SPELL_CHEST_BOMB);
                target->CastSpell(player, SPELL_HELIX_CHEST_BOMB_EMOTE);
            }
        }

        Creature* oaf = instance->GetCreature(DATA_LUMBERING_OAF);
        // Lumbering oaf is dead when the last face riding expires. Continue with phase two behaivior and leap straight up to the next player
        if (!oaf || oaf->isDead())
            target->CastSpell(target, SPELL_RIDE_FACE_TARGETING);
        else
            target->CastSpell(oaf, SPELL_RIDE_VEHICLE_OAF);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_helix_helix_ride_face_timer_aura::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_helix_chest_bomb_emote : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* creature = caster->ToCreature())
                if (creature->IsAIEnabled)
                    creature->AI()->Talk(SAY_ANNOUNCE_CHEST_BOMB, GetHitUnit());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_helix_chest_bomb_emote::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_helix_chest_bomb : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CHEST_BOMB_DAMAGE });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* owner = GetOwner()->ToUnit())
            owner->CastSpell(owner, SPELL_CHEST_BOMB_DAMAGE);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_helix_chest_bomb::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_helix_ride_vehicle : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_helix_ride_vehicle::AfterRemove, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
    }
};


void AddSC_boss_helix_gearbreaker()
{
    RegisterDeadminesCreatureAI(boss_helix_gearbreaker);
    RegisterDeadminesCreatureAI(npc_helix_lumbering_oaf);
    RegisterDeadminesCreatureAI(npc_helix_sticky_bomb);
    RegisterDeadminesCreatureAI(npc_helix_crew);
    RegisterSpellScript(spell_helix_throw_bomb_targeting);
    RegisterSpellScript(spell_helix_sticky_bomb_periodic_trigger);
    RegisterSpellScript(spell_helix_oaf_grab_targeting);
    RegisterSpellScript(spell_helix_force_player_to_ride_oaf);
    RegisterSpellScript(spell_helix_oaf_smash);
    RegisterSpellScript(spell_helix_helix_ride);
    RegisterSpellScript(spell_helix_ride_face_targeting);
    RegisterSpellScript(spell_helix_helix_ride_face_timer_aura);
    RegisterSpellScript(spell_helix_chest_bomb_emote);
    RegisterSpellScript(spell_helix_chest_bomb);
    RegisterSpellScript(spell_helix_ride_vehicle);
}
