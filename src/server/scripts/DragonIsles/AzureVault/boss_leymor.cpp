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
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SharedDefines.h"
#include "TemporarySummon.h"
#include "azure_vault.h"

enum LeymorSpells
{
    // Leymor
    SPELL_STASIS                            = 375729,
    SPELL_ARCANE_ERUPTION                   = 375749,
    SPELL_LEY_LINE_SPROUTS                  = 374364,
    SPELL_LEY_LINE_SPROUTS_MISSILE          = 374362,
    SPELL_CONSUMING_STOMP                   = 374720,
    SPELL_CONSUMING_STOMP_DAMAGE            = 374731,
    SPELL_ERUPTING_FISSURE                  = 386660,
    SPELL_ERUPTING_FISSURE_SPROUT_SELECTOR  = 394154,
    SPELL_EXPLOSIVE_BRAND                   = 374567,
    SPELL_EXPLOSIVE_BRAND_DAMAGE            = 374570,
    SPELL_EXPLOSIVE_BRAND_KNOCKBACK         = 374582,
    SPELL_INFUSED_STRIKE                    = 374789,

    // Ley-Line Sprout
    SPELL_VOLATILE_SAPLING                  = 388654,
    SPELL_LEY_LINE_SPROUT_AT                = 374161,
    SPELL_ARCANE_POWER                      = 374736,

    // Volatile Sapling
    SPELL_SAPPY_BURST                       = 375591,

    // Arcane Tender
    SPELL_STASIS_RITUAL                     = 375732,
    SPELL_STASIS_RITUAL_MISSILE             = 375738,
    SPELL_ERRATIC_GROWTH_CHANNEL            = 375596,
    SPELL_WILD_ERUPTION                     = 375652,
    SPELL_WILD_ERUPTION_MISSILE             = 375650
};

enum LeymorEvents
{
    // Leymor
    EVENT_LEYMOR_AWAKE                      = 1,
    EVENT_LEY_LINE_SPROUTS,
    EVENT_CONSUMING_STOMP,
    EVENT_ERUPTING_FISSURE,
    EVENT_EXPLOSIVE_BRAND,
    EVENT_INFUSED_STRIKE,

    // Arcane Tender
    EVENT_ERRATIC_GROWTH                    = 1,
    EVENT_WILD_ERUPTION,
    EVENT_INFUSED_GROUND,
};

enum LeymorTexts
{
    SAY_ANNOUNCE_AWAKEN                 = 0
};

enum LeymorVisuals
{
    SPELL_VISUAL_KIT_SPROUT_DEATH       = 159239
};

enum LeymorNpcs
{
    NPC_LEYLINE_SPROUTS                 = 190509
};

enum LeymorActions
{
    ACTION_ARCANE_TENDER_DEATH          = 1
};

// 186644 - Leymor
struct boss_leymor : public BossAI
{
    boss_leymor(Creature* creature) : BossAI(creature, DATA_LEYMOR), _killedArcaneTender(0) { }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_LEYMOR_INTRO_DONE))
            return;

        me->SetUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        DoCastSelf(SPELL_STASIS);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ARCANE_TENDER_DEATH)
        {
            _killedArcaneTender++;
            if (_killedArcaneTender >= 3)
            {
                instance->SetData(DATA_LEYMOR_INTRO_DONE, 1);

                scheduler.Schedule(1s, [this](TaskContext /*context*/)
                {
                    me->RemoveAurasDueToSpell(SPELL_STASIS);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                    DoCastSelf(SPELL_ARCANE_ERUPTION);
                    Talk(SAY_ANNOUNCE_AWAKEN);
                });
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void OnChannelFinished(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_CONSUMING_STOMP)
            DoCastAOE(SPELL_CONSUMING_STOMP_DAMAGE, true);
    };

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_LEY_LINE_SPROUTS, 3s);
        events.ScheduleEvent(EVENT_CONSUMING_STOMP, 45s);
        events.ScheduleEvent(EVENT_ERUPTING_FISSURE, 20s);
        events.ScheduleEvent(EVENT_EXPLOSIVE_BRAND, 31s);
        events.ScheduleEvent(EVENT_INFUSED_STRIKE, 10s);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
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
                case EVENT_LEY_LINE_SPROUTS:
                    DoCastSelf(SPELL_LEY_LINE_SPROUTS);
                    events.ScheduleEvent(EVENT_LEY_LINE_SPROUTS, 48s);
                    break;
                case EVENT_CONSUMING_STOMP:
                    DoCastSelf(SPELL_CONSUMING_STOMP);
                    events.ScheduleEvent(EVENT_CONSUMING_STOMP, 48s);
                    break;
                case EVENT_ERUPTING_FISSURE:
                    DoCastVictim(SPELL_ERUPTING_FISSURE);
                    events.ScheduleEvent(EVENT_ERUPTING_FISSURE, 48s);
                    break;
                case EVENT_EXPLOSIVE_BRAND:
                    DoCastSelf(SPELL_EXPLOSIVE_BRAND);
                    events.ScheduleEvent(EVENT_EXPLOSIVE_BRAND, 48s);
                    break;
                case EVENT_INFUSED_STRIKE:
                    DoCastVictim(SPELL_INFUSED_STRIKE);
                    events.ScheduleEvent(EVENT_INFUSED_STRIKE, 48s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    int32 _killedArcaneTender;
};

// 191164 - Arcane Tender
struct npc_arcane_tender : public ScriptedAI
{
    npc_arcane_tender(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        Creature* leymor = me->GetInstanceScript()->GetCreature(DATA_LEYMOR);
        if (!leymor)
            return;

        if (!leymor->IsAIEnabled())
            return;

        leymor->AI()->DoAction(ACTION_ARCANE_TENDER_DEATH);
    }

    void JustAppeared() override
    {
        Creature* leymor = me->GetInstanceScript()->GetCreature(DATA_LEYMOR);
        if (!leymor)
            return;

        DoCast(leymor, SPELL_STASIS_RITUAL);
    }

    void JustReachedHome() override
    {
        JustAppeared();
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_ERRATIC_GROWTH, 22s);
        _events.ScheduleEvent(EVENT_WILD_ERUPTION, 12s);
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
                case EVENT_ERRATIC_GROWTH:
                    DoCastAOE(SPELL_ERRATIC_GROWTH_CHANNEL);
                    _events.ScheduleEvent(EVENT_ERRATIC_GROWTH, 22s);
                    break;
                case EVENT_WILD_ERUPTION:
                    DoCastAOE(SPELL_WILD_ERUPTION);
                    _events.ScheduleEvent(EVENT_WILD_ERUPTION, 12s);
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
};

// 190509 - Ley-Line Sprout
struct npc_ley_line_sprouts : public ScriptedAI
{
    npc_ley_line_sprouts(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_LEY_LINE_SPROUT_AT);

        DoCastAOE(SPELL_ARCANE_POWER, true);
    }

    void JustSummoned(Creature* summon) override
    {
        Creature* leymor = me->GetInstanceScript()->GetCreature(DATA_LEYMOR);
        if (!leymor)
            return;

        if (!leymor->IsAIEnabled())
            return;

        leymor->AI()->JustSummoned(summon);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (IsMythic() || IsMythicPlus())
            DoCastAOE(SPELL_VOLATILE_SAPLING, true);

        if (TempSummon* tempSummon = me->ToTempSummon())
        {
            if (Unit* summoner = tempSummon->GetSummonerUnit())
            {
                if (Aura* aura = summoner->GetAura(SPELL_ARCANE_POWER))
                    aura->ModStackAmount(-1);
            }
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_EXPLOSIVE_BRAND_DAMAGE && spellInfo->Id != SPELL_ERUPTING_FISSURE_SPROUT_SELECTOR)
            return;

        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SPROUT_DEATH, 0, 0);
        me->KillSelf();
    }
};

// 196559 - Volatile Sapling
struct npc_volatile_sapling : public ScriptedAI
{
    npc_volatile_sapling(Creature* creature) : ScriptedAI(creature), _isSappyBurstCast(false) { }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->GetHealth() <= damage)
        {
            damage = me->GetHealth() - 1;

            if (!_isSappyBurstCast)
            {
                me->CastSpell(nullptr, SPELL_SAPPY_BURST, false);
                _isSappyBurstCast = true;
            }
        }
    }

    void OnSpellFailed(SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_SAPPY_BURST)
            return;

        me->KillSelf();
    }

private:
    bool _isSappyBurstCast;
};

static Position const LeyLineSproutGroupOrigin[] =
{
    { -5129.39f, 1253.30f, 555.58f },
    { -5101.68f, 1253.71f, 555.90f },
    { -5114.70f, 1230.28f, 555.89f },
    { -5141.62f, 1230.33f, 555.83f },
    { -5155.62f, 1253.60f, 555.87f },
    { -5141.42f, 1276.70f, 555.89f },
    { -5114.78f, 1277.42f, 555.87f }
};

// 374364 - Ley-Line Sprouts
class spell_ley_line_sprouts : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LEY_LINE_SPROUTS_MISSILE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        for (Position const& pos : LeyLineSproutGroupOrigin)
        {
            for (int8 i = 0; i < 2; i++)
                GetCaster()->CastSpell(pos, SPELL_LEY_LINE_SPROUTS_MISSILE, true);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_ley_line_sprouts::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 375732 - Stasis Ritual
class spell_stasis_ritual : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STASIS_RITUAL_MISSILE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(nullptr, SPELL_STASIS_RITUAL_MISSILE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_stasis_ritual::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 375652 - Wild Eruption
class spell_wild_eruption : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WILD_ERUPTION_MISSILE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(*GetHitDest(), SPELL_WILD_ERUPTION_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_wild_eruption::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 375749 - Arcane Eruption
struct at_leymor_arcane_eruption : AreaTriggerAI
{
    at_leymor_arcane_eruption(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->ApplyMovementForce(at->GetGUID(), at->GetPosition(), -20.0f, MovementForceType::Gravity);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->RemoveMovementForce(at->GetGUID());
    }
};

// 374567 - Explosive Brand
class spell_explosive_brand : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EXPLOSIVE_BRAND_KNOCKBACK });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(nullptr, SPELL_EXPLOSIVE_BRAND_KNOCKBACK, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_explosive_brand::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 374567 - Explosive Brand
class spell_explosive_brand_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EXPLOSIVE_BRAND_DAMAGE });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_EXPLOSIVE_BRAND_DAMAGE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_explosive_brand_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 374720 - Consuming Stomp
class spell_consuming_stomp : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->KillSelf();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_consuming_stomp::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 386660 - Erupting Fissure
class spell_erupting_fissure : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ERUPTING_FISSURE_SPROUT_SELECTOR });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(*GetHitDest(), SPELL_ERUPTING_FISSURE_SPROUT_SELECTOR, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_erupting_fissure::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 375591 - Sappy Burst
class spell_sappy_burst : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->KillSelf();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sappy_burst::HandleHitTarget, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_leymor()
{
    // Creature
    RegisterAzureVaultCreatureAI(boss_leymor);
    RegisterAzureVaultCreatureAI(npc_arcane_tender);
    RegisterAzureVaultCreatureAI(npc_ley_line_sprouts);
    RegisterAzureVaultCreatureAI(npc_volatile_sapling);

    // Spells
    RegisterSpellScript(spell_ley_line_sprouts);
    RegisterSpellScript(spell_stasis_ritual);
    RegisterSpellScript(spell_wild_eruption);
    RegisterSpellScript(spell_consuming_stomp);
    RegisterSpellScript(spell_erupting_fissure);
    RegisterSpellScript(spell_sappy_burst);
    RegisterSpellAndAuraScriptPair(spell_explosive_brand, spell_explosive_brand_AuraScript);

    // AreaTrigger
    RegisterAreaTriggerAI(at_leymor_arcane_eruption);
}
