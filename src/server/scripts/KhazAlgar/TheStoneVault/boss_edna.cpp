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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Containers.h"
#include "Conversation.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "TemporarySummon.h"
#include "the_stonevault.h"

enum EdnaSpells
{
    // Intro
    SPELL_REFRACTING_BEAM_INTRO    = 464888,
    SPELL_SKARDEN_SPAWN_PERIODIC   = 447230,
    SPELL_SKARDEN_SPAWN_RP         = 451728,
    SPELL_SHADOW_DISSOLVE_IN       = 448168,

    // Combat
    SPELL_EDNA_ENERGIZE            = 451705,
    SPELL_EDNA_START_ENERGY        = 456814,
    SPELL_EARTH_SHATTERER          = 424879,
    SPELL_EARTH_SHATTERER_MISSILE  = 448218,
    SPELL_REFRACTING_BEAM          = 424795,
    SPELL_REFRACTING_BEAM_DAMAGE   = 424805,
    SPELL_REFRACTING_BEAM_SELECTOR = 452738,
    SPELL_VOLATILE_SPIKE_SELECTOR  = 424903,
    SPELL_VOLATILE_SPIKE_MISSILE   = 424908,
    SPELL_VOLATILE_EXPLOSION       = 424913,
    SPELL_SEISMIC_SMASH            = 424888,
    SPELL_STONE_SHIELD             = 424893,
    SPELL_EDNA_DEFEATED            = 464827,

    SPELL_ANCHOR_HERE              = 45313
};

enum EdnaEvents
{
    EVENT_VOLATILE_SPIKE   = 1,
    EVENT_REFRACTING_BEAM,
    EVENT_SEISMIC_SMASH,
    EVENT_CHECK_ENERGY
};

enum EdnaTexts
{
    SAY_INTRO               = 0,
    SAY_AGGRO               = 1,
    SAY_VOLATILE_SPIKE      = 2,
    SAY_REFRACTING_BEAM     = 3,
    SAY_SEISMIC_SMASH       = 4,
    SAY_SEISMIC_SMASH_ALERT = 5,
    SAY_EARTH_SHATTERER     = 6,
    SAY_SLAY                = 7,
    SAY_WIPE                = 8,
    SAY_DEATH               = 9
};

enum EdnaMisc
{
    POINT_EDNA         = 0,
    POINT_START_COMBAT = 1,

    CONVERSATION_INTRO = 25768,

    NPC_VOLATILE_SPIKE = 223237
};

static constexpr Position EdnaCombatPosition = { 1.94097f, 0.512153f, 361.66537f };
static constexpr Position SkardenSpawnPositions[4] =
{
    { -11.276042f, -19.234375f, 361.8286f,  2.490876f },
    { -11.395833f,  19.628473f, 361.8286f,  3.805543f },
    { -25.248264f,  34.609375f, 361.8286f,  4.397980f },
    { -20.77257f,  -34.930557f, 361.82837f, 1.994346f }
};

// 210108 - E.D.N.A.
struct boss_edna : public BossAI
{
    boss_edna(Creature* creature) : BossAI(creature, DATA_EDNA), _refractingBeamCount(1), _seismicSmashCount(1), _volatileSpikeCount(1) { }

    void InitializeAI() override
    {
        if (instance->GetBossState(DATA_EDNA) != NOT_STARTED)
            me->Relocate(EdnaCombatPosition);
    }

    void Reset() override
    {
        BossAI::Reset();

        _refractingBeamCount = 1;
        _seismicSmashCount = 1;
        _volatileSpikeCount = 1;
    }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_EDNA_INTRO_STATE) == DONE)
        {
            me->RemoveAurasDueToSpell(SPELL_SKARDEN_SPAWN_PERIODIC);
            me->SetImmuneToPC(false);
        }

        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 4);

        if (IsMythic() || IsMythicPlus())
            DoCastSelf(SPELL_EDNA_START_ENERGY);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_DEATH);
        DoCast(SPELL_EDNA_DEFEATED);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_WIPE);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void DoAction(int32 actionId) override
    {
        if (actionId != ACTION_START_EDNA_INTRO)
            return;

        Conversation::CreateConversation(CONVERSATION_INTRO, me, me->GetPosition(), ObjectGuid::Empty);
        scheduler.Schedule(3s, [this](TaskContext /*context*/)
        {
            me->RemoveAurasDueToSpell(SPELL_SKARDEN_SPAWN_PERIODIC);
            me->GetMotionMaster()->MovePoint(POINT_START_COMBAT, EdnaCombatPosition, true, {}, {}, MovementWalkRunSpeedSelectionMode::ForceWalk);
        });
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id != POINT_START_COMBAT)
            return;

        scheduler.Schedule(1s, [this](TaskContext /*context*/)
        {
            instance->SetData(DATA_EDNA_INTRO_STATE, DONE);
            Talk(SAY_INTRO);
            DoCastSelf(SPELL_ANCHOR_HERE, TRIGGERED_FULL_MASK);
            me->SetImmuneToPC(false);
        });
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        if (IsMythic() || IsMythicPlus())
        {
            events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);
            events.ScheduleEvent(EVENT_VOLATILE_SPIKE, 6s);
            events.ScheduleEvent(EVENT_REFRACTING_BEAM, 14s);
            events.ScheduleEvent(EVENT_SEISMIC_SMASH, 18s);

            DoCastSelf(SPELL_EDNA_ENERGIZE);
        }
        else
        {
            events.ScheduleEvent(EVENT_VOLATILE_SPIKE, 8100ms);
            events.ScheduleEvent(EVENT_REFRACTING_BEAM, 11800ms);
            events.ScheduleEvent(EVENT_SEISMIC_SMASH, 15400ms);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
            case EVENT_VOLATILE_SPIKE:
            {
                Talk(SAY_VOLATILE_SPIKE);
                DoCast(SPELL_VOLATILE_SPIKE_SELECTOR);

                _volatileSpikeCount++;
                if (IsMythic() || IsMythicPlus())
                {
                    if (_volatileSpikeCount % 2 == 0)
                        events.Repeat(20s);
                    else
                        events.Repeat(28s);
                }
                else
                    events.Repeat(14600ms);
                break;
            }
            case EVENT_REFRACTING_BEAM:
            {
                Talk(SAY_REFRACTING_BEAM);
                DoCast(SPELL_REFRACTING_BEAM_SELECTOR);

                _refractingBeamCount++;
                if (IsMythic() || IsMythicPlus())
                {
                    if (_refractingBeamCount % 2 == 0)
                        events.Repeat(20s);
                    else
                        events.Repeat(28s);
                }
                else
                    events.Repeat(10900ms);

                break;
            }
            case EVENT_SEISMIC_SMASH:
            {
                Talk(SAY_SEISMIC_SMASH);
                Talk(SAY_SEISMIC_SMASH_ALERT);
                DoCastVictim(SPELL_SEISMIC_SMASH);

                _seismicSmashCount++;
                if (IsMythic() || IsMythicPlus())
                {
                    if (_seismicSmashCount % 2 == 0)
                        events.Repeat(20s);
                    else
                        events.Repeat(28s);
                }
                else
                    events.Repeat(23100ms);
                break;
            }
            case EVENT_CHECK_ENERGY:
            {
                if (me->GetPower(POWER_ENERGY) >= 95)
                {
                    Talk(SAY_EARTH_SHATTERER);
                    DoCast(SPELL_EARTH_SHATTERER);
                    events.Repeat(4s);
                }
                else
                    events.Repeat(500ms);
                break;
            }
            default:
                break;
        }
    }

private:
    uint16 _refractingBeamCount;
    uint16 _seismicSmashCount;
    uint16 _volatileSpikeCount;
};

// 224516 - Skardyn Invader
struct npc_skardyn_invader : public ScriptedAI
{
    npc_skardyn_invader(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SHADOW_DISSOLVE_IN);

        _scheduler.Schedule(2400ms, [this](TaskContext /*context*/)
        {
            TempSummon* summon = me->ToTempSummon();
            if (!summon)
                return;

            if (Unit* summoner = summon->GetSummonerUnit())
            {
                me->GetMotionMaster()->MovePoint(POINT_EDNA, summoner->GetPosition());
                summoner->CastSpell(me, SPELL_REFRACTING_BEAM_INTRO, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 451705 - E.D.N.A. Energize
class spell_edna_energize : public AuraScript
{
    static constexpr std::array<uint8, 6> EdnaEnergizeCycle = { 2, 2, 2, 2, 3, 2 };

    void PeriodicTick(AuraEffect const* aurEff) const
    {
        uint8 cycleIdx = aurEff->GetTickNumber() % EdnaEnergizeCycle.size();
        GetTarget()->ModifyPower(POWER_ENERGY, EdnaEnergizeCycle[cycleIdx]);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_edna_energize::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 447230 - Skarden Spawn RP
class spell_edna_skarden_spawn_rp_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SKARDEN_SPAWN_RP });
    }

    void HandlePeriodic(AuraEffect const* aurEff) const
    {
        Unit* target = GetTarget();

        target->CastSpell(target, SPELL_SKARDEN_SPAWN_RP, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_edna_skarden_spawn_rp_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 451728 - Skarden Spawn RP
class spell_edna_skarden_spawn_rp : public SpellScript
{
    static void SetDest(SpellDestination& dest)
    {
        dest.Relocate(Trinity::Containers::SelectRandomContainerElement(SkardenSpawnPositions));
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_edna_skarden_spawn_rp::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 424889 - Seismic Reverberation
class spell_edna_seismic_reverberation : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STONE_SHIELD });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        Unit* target = GetTarget();

        target->CastSpell(target, SPELL_STONE_SHIELD, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_edna_seismic_reverberation::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 424903 - Volatile Spike
class spell_edna_volatile_spike_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VOLATILE_SPIKE_MISSILE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit()->GetPosition(), SPELL_VOLATILE_SPIKE_MISSILE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
            .OriginalCastId = GetSpell()->m_castId
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_edna_volatile_spike_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 452738 - Refracting Beam
class spell_edna_refracting_beam_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_REFRACTING_BEAM })
            && ValidateSpellEffect({ { SPELL_REFRACTING_BEAM_DAMAGE, EFFECT_3 } });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->m_Events.AddEvent([this, hitUnitGUID = GetHitUnit()->GetGUID()]()
        {
            Unit* hitUnit = ObjectAccessor::GetUnit(*GetCaster(), hitUnitGUID);
            if (!hitUnit)
                return;

            GetCaster()->CastSpell(GetHitUnit(), SPELL_REFRACTING_BEAM, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell(),
                .OriginalCastId = GetSpell()->m_castId
            });
        }, _timeMultiplier * 500ms);

        _timeMultiplier++;
    }

    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_REFRACTING_BEAM_DAMAGE, GetCastDifficulty());
        uint32 maxTargets = spell->GetEffect(EFFECT_3).CalcValue(GetCaster());

        if (targets.size() > maxTargets)
            targets.resize(maxTargets);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_edna_refracting_beam_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_edna_refracting_beam_selector::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }

private:
    uint8 _timeMultiplier = 0u;
};

// 424805 - Refracting Beam
class spell_edna_refracting_beam_instakill : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        static constexpr uint8 MAX_TARGETS = 1;

        if (targets.size() <= MAX_TARGETS)
            return;

        auto closestTargetItr = std::ranges::min_element(targets, [caster = GetCaster()](WorldObject const* left, WorldObject const* right)
        {
            return caster->GetDistance(left->GetPosition()) < caster->GetDistance(right->GetPosition());
        });

        if (closestTargetItr == targets.end())
            return;

        WorldObject* closestTarget = *closestTargetItr;
        targets.clear();
        targets.push_back(closestTarget);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_edna_refracting_beam_instakill::FilterTargets, EFFECT_2, TARGET_UNIT_LINE_CASTER_TO_DEST);
    }
};

// 424879 - Earth Shatterer
class spell_edna_earth_shatterer : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EARTH_SHATTERER_MISSILE });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        std::list<Creature*> volatileSpikes;
        GetCreatureListWithEntryInGrid(volatileSpikes, caster, NPC_VOLATILE_SPIKE, 200.0f);

        for (Creature* spike : volatileSpikes)
        {
            caster->CastSpell(spike, SPELL_EARTH_SHATTERER_MISSILE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell(),
                .OriginalCastId = GetSpell()->m_castId
            });
        }
    }

    void HandleAfterCast() const
    {
        Unit* caster = GetCaster();
        caster->SetPower(caster->GetPowerType(), 0);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_edna_earth_shatterer::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        AfterCast += SpellCastFn(spell_edna_earth_shatterer::HandleAfterCast);
    }
};

// 424909 - Volatile Spike
// Id - 33613
struct at_edna_volatile_spike : AreaTriggerAI
{
    at_edna_volatile_spike(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_VOLATILE_EXPLOSION, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        if (Creature* casterCreature = caster->ToCreature())
            casterCreature->DespawnOrUnsummon();
    }
};

void AddSC_boss_edna()
{
    RegisterTheStonevaultCreatureAI(boss_edna);
    RegisterTheStonevaultCreatureAI(npc_skardyn_invader);
    RegisterSpellScript(spell_edna_energize);
    RegisterSpellScript(spell_edna_skarden_spawn_rp_periodic);
    RegisterSpellScript(spell_edna_skarden_spawn_rp);
    RegisterSpellScript(spell_edna_seismic_reverberation);
    RegisterSpellScript(spell_edna_volatile_spike_selector);
    RegisterSpellScript(spell_edna_refracting_beam_selector);
    RegisterSpellScript(spell_edna_refracting_beam_instakill);
    RegisterSpellScript(spell_edna_earth_shatterer);
    RegisterAreaTriggerAI(at_edna_volatile_spike);
}
