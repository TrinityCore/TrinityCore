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
#include "CellImpl.h"
#include "Conversation.h"
#include "Creature.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "PathGenerator.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "city_of_threads.h"

enum OratorKrixVizkSpells
{
    SPELL_ORATION                          = 454689,
    SPELL_CHAINS_OF_OPPRESSION             = 434691,
    SPELL_CHAINS_OF_OPPRESSION_PERIODIC    = 440310,
    SPELL_CHAINS_OF_OPPRESSION_CHARGE      = 434712,
    SPELL_CHAINS_OF_OPPRESSION_DAMAGE      = 434710,
    SPELL_SUBJUGATE                        = 434722,
    SPELL_TERRORIZE_SELECTOR               = 434808,
    SPELL_TERRORIZE                        = 434779,
    SPELL_SHADOWS_OF_DOUBT_SELECTOR        = 448560,
    SPELL_SHADOWS_OF_DOUBT                 = 448561,
    SPELL_DOUBT                            = 448562,
    SPELL_VOCIFEROUS_INDOCTRINATION        = 434829,
    SPELL_VOCIFEROUS_INDOCTRINATION_DAMAGE = 434832,
    SPELL_LINGERING_INFLUENCE_AREATRIGGER  = 434923,
    SPELL_LINGERING_INFLUENCE_DAMAGE       = 434926
};

enum OratorKrixVizkConversations
{
    CONVERSATION_ORATOR_INTRO_1   = 24642,
    CONVERSATION_ORATOR_INTRO_2   = 24643,
    CONVERSATION_ORATOR_INTRO_3   = 24644
};

enum OratorKrixVizkTexts
{
    SAY_AGGRO                     = 0,
    SAY_SUBJUGATE                 = 1,
    SAY_TERRORIZE                 = 2,
    SAY_VOCIFEROUS_INDOCTRINATION = 3,
    SAY_KILL                      = 4,
    SAY_DEATH                     = 5
};

enum OratorKrixVizkEvents
{
    EVENT_SUBJUGATE   = 1,
    EVENT_TERRORIZE,
    EVENT_SHADOWS_OF_DOUBT,
    EVENT_ENERGIZE
};

enum OratorKrixVizkMisc
{
    AREATRIGGER_BARRIER           = 35803,
    DISPLAY_POWERID               = 527
};

// 163
// 164
template<uint32 conversationEntry, uint32 data>
struct at_orator_conversation_intro : AreaTriggerAI
{
    at_orator_conversation_intro(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        if (Creature* oratorKrixVizk = instance->GetCreature(data))
            Conversation::CreateConversation(conversationEntry, oratorKrixVizk, player->GetPosition(), player->GetGUID());

        at->Remove();
    }
};

// 216619 - Orator Krix'vizk <The Fifth Strand>
struct boss_orator_krix_vizk : public BossAI
{
    boss_orator_krix_vizk(Creature* creature) : BossAI(creature, DATA_ORATOR_KRIX_VIZK), _subjugateCount(1), _terrorizeCount(1), _energizeCount(0) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_ORATION);
        me->SetPower(POWER_ENERGY, 0);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        WorldObject* obj = nullptr;
        Trinity::ObjectEntryAndPrivateOwnerIfExistsCheck check(ObjectGuid::Empty, AREATRIGGER_BARRIER);
        Trinity::WorldObjectSearcher<Trinity::ObjectEntryAndPrivateOwnerIfExistsCheck> checker(me, obj, check, GRID_MAP_TYPE_MASK_AREATRIGGER);
        Cell::VisitGridObjects(me, checker, 100.0f);

        if (!obj)
            return;

        if (AreaTrigger* at = obj->ToAreaTrigger())
            at->Remove();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_KILL);
    }

    void Reset() override
    {
        _Reset();

        _subjugateCount = 1;
        _terrorizeCount = 1;
        _energizeCount = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        DoCastSelf(SPELL_CHAINS_OF_OPPRESSION);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        me->SetOverrideDisplayPowerId(DISPLAY_POWERID); // No aura handle

        events.ScheduleEvent(EVENT_ENERGIZE, 1s);
        events.ScheduleEvent(EVENT_SUBJUGATE, 4500ms);
        events.ScheduleEvent(EVENT_TERRORIZE, 9400ms);

        if (IsMythic() || IsMythicPlus())
            events.ScheduleEvent(EVENT_SHADOWS_OF_DOUBT, 15200ms);
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
                case EVENT_SUBJUGATE:
                {
                    Talk(SAY_SUBJUGATE);
                    DoCastVictim(SPELL_SUBJUGATE);
                    _subjugateCount++;
                    if (_subjugateCount % 2 == 0)
                        events.ScheduleEvent(EVENT_SUBJUGATE, 17100ms);
                    else
                        events.ScheduleEvent(EVENT_SUBJUGATE, 12s);
                    break;
                }
                case EVENT_TERRORIZE:
                {
                    Talk(SAY_TERRORIZE);
                    DoCast(SPELL_TERRORIZE_SELECTOR);
                    _terrorizeCount++;
                    if (_terrorizeCount % 2 == 0)
                        events.ScheduleEvent(EVENT_TERRORIZE, 8100ms);
                    else
                        events.ScheduleEvent(EVENT_TERRORIZE, 21100ms);
                    break;
                }
                case EVENT_SHADOWS_OF_DOUBT:
                {
                    DoCast(SPELL_SHADOWS_OF_DOUBT_SELECTOR);
                    events.ScheduleEvent(EVENT_SHADOWS_OF_DOUBT, 30300ms);
                    break;
                }
                case EVENT_ENERGIZE:
                {
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        Talk(SAY_VOCIFEROUS_INDOCTRINATION);
                        DoCastSelf(SPELL_VOCIFEROUS_INDOCTRINATION);
                        events.RescheduleEvent(EVENT_ENERGIZE, 6s);
                    }
                    else
                    {
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 4);
                        _energizeCount++;
                        events.ScheduleEvent(EVENT_ENERGIZE, (_energizeCount % 2) ? 1200ms : 800ms);
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    uint8 _subjugateCount;
    uint8 _terrorizeCount;
    uint8 _energizeCount;
};

// 434808 - Terrorize
class spell_orator_krix_vizk_terrorize_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TERRORIZE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_TERRORIZE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_orator_krix_vizk_terrorize_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 448560 - Shadows of Doubt
class spell_orator_krix_vizk_shadows_of_doubt_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOWS_OF_DOUBT });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SHADOWS_OF_DOUBT, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_orator_krix_vizk_shadows_of_doubt_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 440310 - Chains of Oppression
class spell_orator_krix_vizk_chains_of_oppression_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CHAINS_OF_OPPRESSION_DAMAGE, SPELL_CHAINS_OF_OPPRESSION_CHARGE });
    }

    void Tick(AuraEffect const* /*aurEff*/) const
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetTarget();
            CastSpellExtraArgs args;
            args.TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR;

            caster->CastSpell(target, SPELL_CHAINS_OF_OPPRESSION_DAMAGE, args);
            target->CastSpell(caster, SPELL_CHAINS_OF_OPPRESSION_CHARGE, args);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_orator_krix_vizk_chains_of_oppression_periodic::Tick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 448561 - Shadows of Doubt
class spell_orator_krix_vizk_shadows_of_doubt_periodic : public AuraScript
{
    static constexpr uint8 MAX_SHADOW_OF_DOUBTS = 5;
    static constexpr uint32 DOUBT_AT_CREATE_PROPERTIES = 165;

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DOUBT });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE && GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        for (uint8 i = 0; i < MAX_SHADOW_OF_DOUBTS; ++i)
        {
            Unit* target = GetTarget();
            float angle = 2.f * float(M_PI) / MAX_SHADOW_OF_DOUBTS * i;
            Position dest(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), angle);
            AreaTrigger::CreateAreaTrigger({ DOUBT_AT_CREATE_PROPERTIES, true }, dest, -1, caster, target);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_orator_krix_vizk_shadows_of_doubt_periodic::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 434829 - Vociferous Indoctrination
class spell_orator_krix_vizk_vociferous_indoctrination_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VOCIFEROUS_INDOCTRINATION_DAMAGE, SPELL_LINGERING_INFLUENCE_AREATRIGGER });
    }

    void Tick(AuraEffect const* aurEff) const
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_VOCIFEROUS_INDOCTRINATION_DAMAGE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (Unit* caster = GetCaster())
            GetTarget()->CastSpell(caster, SPELL_LINGERING_INFLUENCE_AREATRIGGER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);

        if (Creature* creatureTarget = GetTarget()->ToCreature())
            creatureTarget->SetPower(POWER_ENERGY, 0);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_orator_krix_vizk_vociferous_indoctrination_periodic::Tick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_orator_krix_vizk_vociferous_indoctrination_periodic::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 434691 - Chains of Oppression
// Id - 31997
struct at_orator_krix_vizk_chains_of_oppression : AreaTriggerAI
{
    at_orator_krix_vizk_chains_of_oppression(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_CHAINS_OF_OPPRESSION_PERIODIC, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        if (!unit->IsPlayer())
            return;

        unit->RemoveAurasDueToSpell(SPELL_CHAINS_OF_OPPRESSION_PERIODIC);
    }
};

// 434923 - Lingering Influence
// ID - 32026
struct at_orator_krix_vizk_lingering_influence : AreaTriggerAI
{
    at_orator_krix_vizk_lingering_influence(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_LINGERING_INFLUENCE_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        if (!unit->IsPlayer())
            return;

        unit->RemoveAurasDueToSpell(SPELL_LINGERING_INFLUENCE_DAMAGE);
    }

    void OnInitialize() override
    {
        std::array<DBCPosition2D, 2> points =
        { {
            { 0.0f, 1.0f },
            { 1.0f, 18.0f }
        } };

        at->SetTimeToTargetScale(6000);
        at->SetOverrideScaleCurve(points, 2);
    }
};

// 165
struct at_orator_krix_vizk_doubt : AreaTriggerAI
{
    explicit at_orator_krix_vizk_doubt(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger), _canHitOrigin(false) {}

    void OnInitialize() override
    {
        Position destPos = at->GetPosition();
        at->MovePositionToFirstCollision(destPos, 200.0f, 0.0f);

        PathGenerator path(at);
        path.CalculatePath(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ(), true);

        at->InitSplines(path.GetPath());

        _canHitOrigin = false;
        _scheduler.Schedule(1s, [this](TaskContext /*task*/)
        {
            _canHitOrigin = true;
        });
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnDestinationReached() override
    {
        at->Remove();
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        if (!_canHitOrigin && unit == at->GetTarget())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_DOUBT, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

private:
    TaskScheduler _scheduler;
    bool _canHitOrigin;
};

void AddSC_boss_orator_krix_vizk()
{
    new GenericAreaTriggerEntityScript<at_orator_conversation_intro<CONVERSATION_ORATOR_INTRO_1, DATA_ORATOR_CONVO>>("at_orator_conversation_intro_1");
    new GenericAreaTriggerEntityScript<at_orator_conversation_intro<CONVERSATION_ORATOR_INTRO_2, DATA_ORATOR_KRIX_VIZK>>("at_orator_conversation_intro_2");
    new GenericAreaTriggerEntityScript<at_orator_conversation_intro<CONVERSATION_ORATOR_INTRO_3, DATA_ORATOR_KRIX_VIZK>>("at_orator_conversation_intro_3");

    RegisterCityOfThreadsCreatureAI(boss_orator_krix_vizk);

    RegisterSpellScript(spell_orator_krix_vizk_terrorize_selector);
    RegisterSpellScript(spell_orator_krix_vizk_shadows_of_doubt_selector);
    RegisterSpellScript(spell_orator_krix_vizk_chains_of_oppression_periodic);
    RegisterSpellScript(spell_orator_krix_vizk_shadows_of_doubt_periodic);
    RegisterSpellScript(spell_orator_krix_vizk_vociferous_indoctrination_periodic);

    RegisterAreaTriggerAI(at_orator_krix_vizk_chains_of_oppression);
    RegisterAreaTriggerAI(at_orator_krix_vizk_lingering_influence);
    RegisterAreaTriggerAI(at_orator_krix_vizk_doubt);
}
