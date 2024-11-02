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
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
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

// Id xxxx - Areatrigger
struct at_orator_conversation_intro_1 : AreaTriggerAI
{
    at_orator_conversation_intro_1(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        if (Creature* oratorKrixVizk = instance->GetCreature(DATA_ORATOR_CONVO)) // Different creature
            Conversation::CreateConversation(CONVERSATION_ORATOR_INTRO_1, oratorKrixVizk, player->GetPosition(), player->GetGUID());

        at->Remove();
    }
};

// Id xxxx - Areatrigger
struct at_orator_conversation_intro_2 : AreaTriggerAI
{
    at_orator_conversation_intro_2(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        if (Creature* oratorKrixVizk = instance->GetCreature(DATA_ORATOR_KRIX_VIZK))
            Conversation::CreateConversation(CONVERSATION_ORATOR_INTRO_2, oratorKrixVizk, player->GetPosition(), player->GetGUID());

        at->Remove();
    }
};

// Id xxxx - Areatrigger
struct at_orator_conversation_intro_3 : AreaTriggerAI
{
    at_orator_conversation_intro_3(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        if (Creature* oratorKrixVizk = instance->GetCreature(DATA_ORATOR_KRIX_VIZK))
            Conversation::CreateConversation(CONVERSATION_ORATOR_INTRO_3, oratorKrixVizk, player->GetPosition(), player->GetGUID());

        at->Remove();
    }
};

// 216619 - Orator Krix'vizk <The Fifth Strand>
struct boss_orator_krix_vizk : public BossAI
{
    boss_orator_krix_vizk(Creature* creature) : BossAI(creature, DATA_ORATOR_KRIX_VIZK) { }

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
        events.Reset();
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
        events.ScheduleEvent(EVENT_TERRORIZE, 8100ms);

        if (IsMythic() || IsMythicPlus())
            events.ScheduleEvent(EVENT_SHADOWS_OF_DOUBT, 15300ms);
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
                    events.ScheduleEvent(EVENT_SUBJUGATE, 12800ms);
                    break;
                }
                case EVENT_TERRORIZE:
                {
                    Talk(SAY_TERRORIZE);
                    DoCast(SPELL_TERRORIZE_SELECTOR);
                    events.ScheduleEvent(EVENT_TERRORIZE, 8100ms);
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
                        events.ScheduleEvent(EVENT_ENERGIZE, 1s);
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
};

// 434808 - Terrorize
class spell_orator_krix_vizk_terrorize_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TERRORIZE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_TERRORIZE, CastSpellExtraArgsInit{
            .OriginalCastId = GetSpell()->m_originalCastId
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

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SHADOWS_OF_DOUBT, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .OriginalCastId = GetSpell()->m_originalCastId
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

    void Tick(AuraEffect const* /*aurEff*/)
    {
        GetCaster()->CastSpell(GetTarget(), SPELL_CHAINS_OF_OPPRESSION_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });

        GetTarget()->CastSpell(GetCaster(), SPELL_CHAINS_OF_OPPRESSION_CHARGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_orator_krix_vizk_chains_of_oppression_periodic::Tick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 448561 - Shadows of Doubt
class spell_orator_krix_vizk_shadows_of_doubt_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DOUBT });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE || GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
            GetCaster()->CastSpell(GetTarget(), SPELL_DOUBT, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .OriginalCastId = GetAura()->GetCastId()
        });
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

    void Tick(AuraEffect const* /*aurEff*/)
    {
        GetCaster()->CastSpell(GetTarget(), SPELL_VOCIFEROUS_INDOCTRINATION_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .OriginalCastId = GetAura()->GetCastId()
        });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetCaster(), SPELL_LINGERING_INFLUENCE_AREATRIGGER, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });

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

        at->GetCaster()->CastSpell(unit, SPELL_CHAINS_OF_OPPRESSION_PERIODIC, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void OnUnitExit(Unit* unit) override
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

        at->GetCaster()->CastSpell(unit, SPELL_LINGERING_INFLUENCE_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void OnUnitExit(Unit* unit) override
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

void AddSC_boss_orator_krix_vizk()
{
    RegisterAreaTriggerAI(at_orator_conversation_intro_1);
    RegisterAreaTriggerAI(at_orator_conversation_intro_2);
    RegisterAreaTriggerAI(at_orator_conversation_intro_3);
    RegisterCityOfThreadsCreatureAI(boss_orator_krix_vizk);

    RegisterSpellScript(spell_orator_krix_vizk_terrorize_selector);
    RegisterSpellScript(spell_orator_krix_vizk_shadows_of_doubt_selector);
    RegisterSpellScript(spell_orator_krix_vizk_chains_of_oppression_periodic);
    RegisterSpellScript(spell_orator_krix_vizk_shadows_of_doubt_periodic);
    RegisterSpellScript(spell_orator_krix_vizk_vociferous_indoctrination_periodic);

    RegisterAreaTriggerAI(at_orator_krix_vizk_chains_of_oppression);
    RegisterAreaTriggerAI(at_orator_krix_vizk_lingering_influence);
}
