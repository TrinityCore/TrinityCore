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

#include "AreaTriggerAI.h"
#include "CellImpl.h"
#include "Containers.h"
#include "GameObject.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "ecodome_aldani.h"

enum AzhiccarSpells
{
    // Intro
    SPELL_DEVOUR_INTRO                    = 1233112,
    SPELL_DEVOUR_INTRO_SELECTOR           = 1233116,
    SPELL_DEVOUR_INSTAKILL                = 1233147,
    SPELL_KNOCKBACK                       = 1222792,

    // Combat
    SPELL_DEVOUR                          = 1217232,
    SPELL_DEVOUR_AREATRIGGER              = 1217240,
    SPELL_DEVOUR_SELECTOR                 = 1217255,
    SPELL_DEVOURER_VORTEX                 = 1227068,
    SPELL_DIGESTIVE_SPITTLE               = 1217446,
    SPELL_ENERGY_CONTROLLER               = 1217202,
    SPELL_FEAST                           = 1217241,
    SPELL_FEAST_HEAL                      = 1217247,
    SPELL_FEAST_INSTAKILL                 = 1217252,
    SPELL_INVADING_SHRIEK_DAMAGE          = 1231850,
    SPELL_INVADING_SHRIEK_DUMMY           = 1217330,
    SPELL_INVADING_SHRIEK_PERIODIC        = 1217327,
    SPELL_INVADING_SHRIEK_SUMMON          = 1217331,
    SPELL_PLAYER_DETECTION                = 1217757,
    SPELL_THRASH                          = 1217664,
    SPELL_TOXIC_REGURGITATION_CAST        = 1227745,
    SPELL_TOXIC_REGURGITATION_MARKER      = 1227748,
    SPELL_TOXIC_REGURGITATION_MISSILE     = 1217438,
    SPELL_TOXIC_REGURGITATION_SELECTOR    = 1217436
};

enum AzhiccarEvents
{
    EVENT_INVADING_SHRIEK = 1,
    EVENT_TOXIC_REGURGITATION,
    EVENT_CHECK_ENERGY
};

enum AzhiccarActions
{
    ACTION_START_INTRO = 1
};

enum AzhiccarTexts
{
    SAY_DEVOUR = 0
};

enum AzhiccarMisc
{
    ANIMKIT_NONE   = 0,
    ANIMKIT_EMERGE = 21290,

    SPELL_VISUALKIT_ALARM = 222521,

    POINT_AZHICCAR = 0,

    SPELL_VISUAL_DEVOURED = 155836,

    NPC_PORTAL_STALKER = 237454
};

static constexpr Position AzhiccarPosition = { 436.8889f, -746.0f, 1002.0926f };
static constexpr Position OrphanSpellVisualPosition = { 436.8889f, -746.0f, 1018.0926f };

// 234893 - Azhiccar
struct boss_azhiccar : public BossAI
{
    boss_azhiccar(Creature* creature) : BossAI(creature, DATA_AZHICCAR), _invadingShriekCount(1), _toxicRegurgitationCount(1) { }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_AZHICCAR_INTRO) == DONE)
        {
            me->SetUninteractible(false);
            me->SetImmuneToAll(false);
            me->SetAIAnimKitId(ANIMKIT_NONE);
            me->PlayOneShotAnimKitId(ANIMKIT_EMERGE);
        }

        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);

        DoCastSelf(SPELL_DEVOURER_VORTEX);
    }

    void Reset() override
    {
        BossAI::Reset();

        _invadingShriekCount = 1;
        _toxicRegurgitationCount = 1;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        DoCastSelf(SPELL_PLAYER_DETECTION);
        DoCastSelf(SPELL_ENERGY_CONTROLLER);

        events.ScheduleEvent(EVENT_TOXIC_REGURGITATION, 15400ms);
        events.ScheduleEvent(EVENT_INVADING_SHRIEK, 5200ms);

        if (IsHeroicOrHigher())
            events.ScheduleEvent(EVENT_CHECK_ENERGY, 500s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        summons.DespawnAll();
        me->RemoveAllAreaTriggers();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        summons.DespawnAll();
        me->RemoveAllAreaTriggers();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DEVOUR:
            {
                Talk(SAY_DEVOUR);
                break;
            }
            default:
                break;
        }
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_START_INTRO:
            {
                me->SetAIAnimKitId(ANIMKIT_NONE);
                me->PlayOneShotAnimKitId(ANIMKIT_EMERGE);

                scheduler.Schedule(2s + 170ms, [this](TaskContext context)
                {
                    DoCastSelf(SPELL_KNOCKBACK);
                    DoCastSelf(SPELL_DEVOUR_INTRO);

                    context.Schedule(7s, [this](TaskContext)
                    {
                        me->SetUninteractible(false);
                        me->SetImmuneToAll(false);
                        instance->SetData(DATA_AZHICCAR_INTRO, DONE);
                    });
                });
                break;
            }
            default:
                break;
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

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INVADING_SHRIEK:
                {
                    std::vector<float> portalAngles =
                    {
                        float(M_PI / 4.0f),
                        -float(M_PI / 4.0f),
                        -(3.0f * float(M_PI / 4.0f)),
                        (3.0f * float(M_PI / 4.0f))
                    };

                    Trinity::Containers::RandomResize(portalAngles, 3);

                    for (float angle : portalAngles)
                    {
                        angle += me->GetOrientation();
                        float dist = 30.0f;
                        Position pos = me->GetPosition();
                        me->MovePosition(pos, dist, angle);
                        me->SummonCreature(NPC_PORTAL_STALKER, pos, TEMPSUMMON_TIMED_DESPAWN, 4100ms);
                    }

                    DoCastSelf(SPELL_INVADING_SHRIEK_PERIODIC);

                    _invadingShriekCount++;
                    if (_invadingShriekCount % 2 == 0)
                        events.Repeat(37200ms);
                    else
                        events.Repeat(48500ms);
                    break;
                }
                case EVENT_TOXIC_REGURGITATION:
                {
                    DoCastSelf(SPELL_TOXIC_REGURGITATION_SELECTOR);
                    _toxicRegurgitationCount++;
                    if (_toxicRegurgitationCount % 2 == 0)
                        events.Repeat(18200ms);
                    else
                        events.Repeat(67500ms);
                    break;
                }
                case EVENT_CHECK_ENERGY:
                {
                    if (me->GetPower(POWER_ENERGY) >= 100)
                    {
                        DoCastSelf(SPELL_DEVOUR);

                        // Todo: implement m+ mechanic for spawning more Devourer Mites
                    }
                    else
                        events.Repeat(500ms);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    uint32 _invadingShriekCount;
    uint32 _toxicRegurgitationCount;
};

// 1217202 - Energy Controller
class spell_azhiccar_energy_controller : public AuraScript
{
    static constexpr std::array<uint8, 3> AzhiccarEnergizeCycle = { 1, 2, 2 };

    void PeriodicTick(AuraEffect const* aurEff) const
    {
        if (GetTarget()->HasAura(SPELL_DEVOUR))
            return;

        uint8 cycleIdx = aurEff->GetTickNumber() % AzhiccarEnergizeCycle.size();
        GetTarget()->ModifyPower(POWER_ENERGY, AzhiccarEnergizeCycle[cycleIdx]);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_azhiccar_energy_controller::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 1217436 - Toxic Regurgitation
class spell_azhiccar_toxic_regurgitation_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TOXIC_REGURGITATION_MARKER, SPELL_TOXIC_REGURGITATION_CAST });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();

        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR;
        args.TriggeringSpell = GetSpell();

        caster->CastSpell(caster, SPELL_TOXIC_REGURGITATION_CAST, args);
        caster->CastSpell(GetHitUnit(), SPELL_TOXIC_REGURGITATION_MARKER, args);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_azhiccar_toxic_regurgitation_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1227745 - Toxic Regurgitation
class spell_azhiccar_toxic_regurgitation_cast : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TOXIC_REGURGITATION_MISSILE });
    }

    void HandleOnHit() const
    {
        Unit* caster = GetCaster();

        std::list<Player*> players;
        Trinity::UnitAuraCheck check(true, SPELL_TOXIC_REGURGITATION_MARKER);
        Trinity::PlayerListSearcher<Trinity::UnitAuraCheck> searcher(caster, players, check);
        Cell::VisitWorldObjects(caster, searcher, 200.0f);

        for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
            caster->CastSpell(*itr, SPELL_TOXIC_REGURGITATION_MISSILE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_azhiccar_toxic_regurgitation_cast::HandleOnHit);
    }
};

// 1217327 - Invading Shriek
class spell_azhiccar_invading_shriek : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_INVADING_SHRIEK_DAMAGE });
    }

    void HandleAfterCast() const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_INVADING_SHRIEK_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_azhiccar_invading_shriek::HandleAfterCast);
    }
};

class spell_azhiccar_invading_shriek_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_INVADING_SHRIEK_DAMAGE });
    }

    void OnApply(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        std::vector<Creature*> stalkers;
        GetCaster()->GetCreatureListWithEntryInGrid(stalkers, NPC_PORTAL_STALKER, 150.0f);
        Trinity::Containers::RandomShuffle(stalkers);

        for (Creature* creature : stalkers)
            _stalkerList.push(creature->GetGUID());
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() > 1)
        {
            Unit* caster = GetCaster();
            ObjectGuid guid = _stalkerList.front();
            _stalkerList.pop();

            if (Creature* stalker = ObjectAccessor::GetCreature(*caster, guid))
                caster->CastSpell(stalker->GetPosition(), SPELL_INVADING_SHRIEK_DUMMY, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                    .TriggeringAura = aurEff
                });
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_azhiccar_invading_shriek_aura::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_azhiccar_invading_shriek_aura::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    std::queue<ObjectGuid> _stalkerList;
};

// 1217330 - Invading Shriek
class spell_azhiccar_invading_shriek_dummy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INVADING_SHRIEK_SUMMON });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), SPELL_INVADING_SHRIEK_SUMMON, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_azhiccar_invading_shriek_dummy::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1217758 - Player Detection (SERVERSIDE)
class spell_azhiccar_player_detection : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_THRASH });
    }

    void HandlePlayerDetection() const
    {
        Unit* caster = GetCaster();
        int64 const targetsHit = GetUnitTargetCountForEffect(EFFECT_0);
        if (targetsHit > 0)
            return;

        Spell* currentChanneledSpell = caster->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
        if (currentChanneledSpell && (currentChanneledSpell->GetSpellInfo()->Id == SPELL_DEVOUR))
            return;

        if (caster->HasAura(SPELL_DEVOUR))
            return;

        caster->CastSpell(caster, SPELL_THRASH, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_azhiccar_player_detection::HandlePlayerDetection);
    }
};

// 1217232 - Devour
class spell_azhiccar_devour : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DEVOUR_AREATRIGGER });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_DEVOUR_AREATRIGGER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        GetCaster()->CastSpell(GetCaster(), SPELL_DEVOUR_SELECTOR, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_azhiccar_devour::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 1217255 - Devour
class spell_azhiccar_devour_selector : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        std::function<void(Movement::MoveSplineInit&)> initializer = [](Movement::MoveSplineInit& init)
        {
            init.SetBackward();
            init.MoveTo(AzhiccarPosition.GetPositionX(), AzhiccarPosition.GetPositionY(), AzhiccarPosition.GetPositionZ(), false);
        };
        target->SendPlaySpellVisualKit(SPELL_VISUALKIT_ALARM, 4, 9000);
        target->GetMotionMaster()->LaunchMoveSpline(std::move(initializer), POINT_AZHICCAR, MOTION_PRIORITY_NORMAL, POINT_MOTION_TYPE);
        target->SetSpeed(MOVE_RUN_BACK, 12.0f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_azhiccar_devour_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1217241 - Feast
// 1217252 - Feast
class spell_azhiccar_feast : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FEAST_HEAL });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_FEAST_HEAL, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_azhiccar_feast::HandleHit, EFFECT_0, SPELL_EFFECT_ANY);
    }
};

// 1217441 - Digestive Spittle
// Id - 36181
struct at_azhiccar_digestive_spittle : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_DIGESTIVE_SPITTLE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_DIGESTIVE_SPITTLE);
    }
};

// 1217240 Devour
// Id - 38188
struct at_azhiccar_devour_force : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->ApplyMovementForce(at->GetGUID(), at->GetPosition(), 3.0f, MovementForceType::Gravity);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveMovementForce(at->GetGUID());
    }
};

// 1217240 Devour
// Id - 38189
struct at_azhiccar_devour : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (unit->IsPlayer())
            caster->CastSpell(unit, SPELL_FEAST, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        else if (unit->HasAura(SPELL_DEVOUR_SELECTOR))
            caster->CastSpell(unit, SPELL_FEAST_INSTAKILL, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

// Id - XXX
struct at_azhiccar_intro : AreaTriggerAI
{
    at_azhiccar_intro(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        if (Creature* azhiccar = instance->GetCreature(DATA_AZHICCAR))
            azhiccar->AI()->DoAction(ACTION_START_INTRO);

        at->Remove();
    }
};

// 245411 - Ravaging Scavenger
// 245412 - Voracious Gorger
struct npc_azhiccar_intro_creature : public ScriptedAI
{
    npc_azhiccar_intro_creature(Creature* creature) : ScriptedAI(creature) { }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DEVOUR_INTRO_SELECTOR)
        {
            _scheduler.Schedule(2000ms, 4500ms, [this](TaskContext)
            {
                me->SendPlayOrphanSpellVisual(OrphanSpellVisualPosition, me->GetPosition(), SPELL_VISUAL_DEVOURED, 45.0f, false);
                DoCastSelf(SPELL_DEVOUR_INSTAKILL);
                me->DespawnOrUnsummon(5s);
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 1233116 - Devour
class spell_azhiccar_devour_intro_selector : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        std::function<void(Movement::MoveSplineInit&)> initializer = [](Movement::MoveSplineInit& init)
        {
            init.SetBackward();
            init.MoveTo(AzhiccarPosition.GetPositionX(), AzhiccarPosition.GetPositionY(), AzhiccarPosition.GetPositionZ(), false);
        };
        target->SendPlaySpellVisualKit(SPELL_VISUALKIT_ALARM, 4, 9000);
        target->GetMotionMaster()->LaunchMoveSpline(std::move(initializer), POINT_AZHICCAR, MOTION_PRIORITY_NORMAL, POINT_MOTION_TYPE);
        target->SetSpeed(MOVE_RUN_BACK, 16.0f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_azhiccar_devour_intro_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_azhiccar()
{
    RegisterEcodomeAldaniCreatureAI(boss_azhiccar);

    RegisterSpellScript(spell_azhiccar_energy_controller);
    RegisterSpellScript(spell_azhiccar_toxic_regurgitation_selector);
    RegisterSpellScript(spell_azhiccar_toxic_regurgitation_cast);
    RegisterSpellAndAuraScriptPair(spell_azhiccar_invading_shriek, spell_azhiccar_invading_shriek_aura);
    RegisterSpellScript(spell_azhiccar_invading_shriek_dummy);
    RegisterSpellScript(spell_azhiccar_player_detection);
    RegisterSpellScript(spell_azhiccar_devour);
    RegisterSpellScript(spell_azhiccar_devour_selector);
    RegisterSpellScript(spell_azhiccar_feast);
    RegisterAreaTriggerAI(at_azhiccar_digestive_spittle);
    RegisterAreaTriggerAI(at_azhiccar_devour_force);
    RegisterAreaTriggerAI(at_azhiccar_devour);

    // Intro
    RegisterAreaTriggerAI(at_azhiccar_intro);
    RegisterEcodomeAldaniCreatureAI(npc_azhiccar_intro_creature);
    RegisterSpellScript(spell_azhiccar_devour_intro_selector);
}
