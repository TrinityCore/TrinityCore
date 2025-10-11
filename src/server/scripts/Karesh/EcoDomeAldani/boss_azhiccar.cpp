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
#include "ecodome_aldani.h"

enum AzhiccarSpells
{
    // Intro
    SPELL_DEVOUR_INSTAKILL                = 1233147,
    SPELL_DEVOUR_INTRO                    = 1233112,
    SPELL_DEVOUR_SELECTOR                 = 1233116,
    SPELL_KNOCKBACK                       = 1222792,

    // Combat
    SPELL_PLAYER_DETECTION                = 1217757,
    SPELL_ENERGY_CONTROLLER               = 1217202,
    SPELL_TOXIC_REGURGITATION_SELECTOR    = 1217436,
    SPELL_TOXIC_REGURGITATION_CAST        = 1227745,
    SPELL_TOXIC_REGURGITATION_MISSILE     = 1217438,
    SPELL_TOXIC_REGURGITATION_MARKER      = 1227748,
    SPELL_DIGESTIVE_SPITTLE               = 1217446,

    SPELL_THRASH                          = 1217664,
    SPELL_DEVOUR                          = 1217232,
    SPELL_FEAST                           = 1217241,

    SPELL_INVADING_SHRIEK_PERIODIC        = 1217327,
    SPELL_INVADING_SHRIEK_DAMAGE          = 1231850,
    SPELL_INVADING_SHRIEK_DUMMY           = 1217330,
    SPELL_INVADING_SHRIEK_SUMMON          = 1217331
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
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        _EnterEvadeMode();
        _DespawnAtEvade();
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
                        DoCast(SPELL_DEVOUR);
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
        int64 const targetsHit = GetUnitTargetCountForEffect(EFFECT_0);
        if (targetsHit > 0)
            return;

        GetCaster()->CastSpell(GetCaster(), SPELL_THRASH, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_azhiccar_player_detection::HandlePlayerDetection);
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

        unit->CastSpell(unit, SPELL_DIGESTIVE_SPITTLE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_DIGESTIVE_SPITTLE);
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
        if (spellInfo->Id == SPELL_DEVOUR_SELECTOR)
        {
            _scheduler.Schedule(2500ms, 4500ms, [this](TaskContext)
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

    RegisterSpellScript(spell_azhiccar_toxic_regurgitation_selector);
    RegisterSpellScript(spell_azhiccar_toxic_regurgitation_cast);
    RegisterSpellAndAuraScriptPair(spell_azhiccar_invading_shriek, spell_azhiccar_invading_shriek_aura);
    RegisterSpellScript(spell_azhiccar_invading_shriek_dummy);
    RegisterSpellScript(spell_azhiccar_player_detection);
    RegisterAreaTriggerAI(at_azhiccar_digestive_spittle);

    // Intro
    RegisterAreaTriggerAI(at_azhiccar_intro);
    RegisterEcodomeAldaniCreatureAI(npc_azhiccar_intro_creature);
    RegisterSpellScript(spell_azhiccar_devour_intro_selector);
}
