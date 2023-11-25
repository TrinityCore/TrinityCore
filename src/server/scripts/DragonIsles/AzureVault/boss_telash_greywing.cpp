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
#include "MotionMaster.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SharedDefines.h"
#include "azure_vault.h"

enum TelashSpells
{
    // Telash
    SPELL_ICE_POWER_PERIODIC        = 389453,
    SPELL_FROST_BOMB_CAST           = 386781,
    SPELL_FROST_BOMB_AURA           = 386881,
    SPELL_FROST_BOMB_DAMAGE         = 386910,
    SPELL_FROZEN_GROUND_AT          = 387149,
    SPELL_ICY_DEVASTATOR            = 387151,
    SPELL_ABSOLUTE_ZERO_CAST        = 387928,
    SPELL_ABSOLUTE_ZERO_JUMP        = 387981,
    SPELL_ABSOLUTE_ZERO_JUMP_BACK   = 388082,
    SPELL_ABSOLUTE_ZERO_SHIELD      = 388084,
    SPELL_ABSOLUTE_ZERO_DAMAGE      = 388008,
    SPELL_ACTIVATE_VAULT_RUNE       = 390209,
    SPELL_VAULT_RUNE_AT_AURA        = 388065,
    SPELL_VAULT_RUNE_SHIELD         = 390201,
    SPELL_INACTIVE_VAULT_RUNE       = 390238,

    // Conversation
    SPELL_TELASH_APPROACH_CONV      = 389379
};

enum TelashEvents
{
    EVENT_FROST_BOMBS       = 1,
    EVENT_ICY_DEVASTATOR    = 2,
    EVENT_ABSOLUTE_ZERO     = 3
};

enum TelashSummonGroups
{
    SUMMON_GROUP_TELASH_VAULT_RUNES = 0
};

enum TelashText
{
    SAY_AGGRO                       = 0,
    SAY_FROST_BOMB                  = 1,
    SAY_ICY_DEVASTATOR              = 2,
    SAY_FLY_TO_MIDDLE               = 3,
    SAY_ANNOUNCE_ABSOLUTE_ZERO      = 4,
    SAY_DEATH                       = 5
};

Position const TelashJumpPosition = { -5336.8003f, 1066.6493f, 344.32678f };

// 186737 - Telash Greywing
struct boss_telash_greywing : public BossAI
{
    boss_telash_greywing(Creature* creature) : BossAI(creature, DATA_TELASH_GREYWING), _isInCenter(false) { }

    void JustAppeared() override
    {
        me->SummonCreatureGroup(SUMMON_GROUP_TELASH_VAULT_RUNES);
        me->SetPower(POWER_ENERGY, 60);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        Talk(SAY_AGGRO);
        DoCast(SPELL_ICE_POWER_PERIODIC);
        events.ScheduleEvent(EVENT_FROST_BOMBS, 4s);
        events.ScheduleEvent(EVENT_ICY_DEVASTATOR, 14s);
        events.ScheduleEvent(EVENT_ABSOLUTE_ZERO, 500ms);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Reset();
        me->DespawnOrUnsummon(5s, 30s);
        summons.DespawnAll();
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        summons.DespawnAll();
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == EVENT_JUMP)
        {
            if (_isInCenter == false)
            {
                DoCastSelf(SPELL_ABSOLUTE_ZERO_DAMAGE);
                _isInCenter = true;
            }
            else if (_isInCenter == true)
            {
                DoCastSelf(SPELL_ICE_POWER_PERIODIC);
                me->RemoveAurasDueToSpell(SPELL_ABSOLUTE_ZERO_SHIELD);
                me->SetReactState(REACT_AGGRESSIVE);
                events.ScheduleEvent(EVENT_FROST_BOMBS, 12s + 200ms);
                events.ScheduleEvent(EVENT_ICY_DEVASTATOR, IsMythicPlus() ? (19s + 600ms) : (23s + 200ms));
                _isInCenter = false;
            }
        }
    }
 
    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FROST_BOMBS:
                    Talk(SAY_FROST_BOMB);
                    DoCastSelf(SPELL_FROST_BOMB_CAST);
                    events.ScheduleEvent(EVENT_FROST_BOMBS, 15s);
                    break;
                case EVENT_ICY_DEVASTATOR:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 75.0f, true))
                    {
                        Talk(SAY_ICY_DEVASTATOR);
                        DoCast(target, SPELL_ICY_DEVASTATOR);
                        events.ScheduleEvent(EVENT_ICY_DEVASTATOR, 23s);
                    }
                    break;
                case EVENT_ABSOLUTE_ZERO:
                    if (me->GetPower(POWER_ENERGY) >= 100)
                    {
                        Talk(SAY_FLY_TO_MIDDLE);
                        Talk(SAY_ANNOUNCE_ABSOLUTE_ZERO);
                        me->SetReactState(REACT_PASSIVE);
                        me->SetDisableGravity(true, true);
                        me->RemoveAurasDueToSpell(SPELL_ICE_POWER_PERIODIC);
                        DoCastSelf(SPELL_ABSOLUTE_ZERO_CAST);
                        DoCastSelf(SPELL_ABSOLUTE_ZERO_SHIELD);
                        DoCastSelf(SPELL_ACTIVATE_VAULT_RUNE);
                        events.CancelEvent(EVENT_FROST_BOMBS);
                        events.CancelEvent(EVENT_ICY_DEVASTATOR);
                    }
                    events.Repeat(500ms);
                    break;
                default:
                    break;
            }
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        DoMeleeAttackIfReady();
    }
private:
    bool _isInCenter;
};

// 30743 - Vault Rune
struct at_telash_greywing_vault_rune : AreaTriggerAI
{
    at_telash_greywing_vault_rune(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (caster->HasAura(SPELL_VAULT_RUNE_SHIELD))
            return;

        caster->CastSpell(nullptr, SPELL_VAULT_RUNE_SHIELD, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        for (ObjectGuid const& guid : at->GetInsideUnits())
        {
            Player* player = ObjectAccessor::GetPlayer(*at, guid);
            if (!player)
                continue;

            if (player->isDead())
                continue;
            return;
        }

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->RemoveAurasDueToSpell(SPELL_VAULT_RUNE_SHIELD);
    }

    void OnRemove() override
    {
        if (!at->GetMap()->IsMythic() && !at->GetMap()->IsMythicPlus())
            return;

        for (ObjectGuid const& guid : at->GetInsideUnits())
        {
            Player* player = ObjectAccessor::GetPlayer(*at, guid);
            if (!player)
                continue;

            if (player->isDead())
                continue;

            at->GetCaster()->CastSpell(at->GetCaster(), SPELL_INACTIVE_VAULT_RUNE, true);
            break;
        }
    }
};

// 389453 - Ice Power (periodic)
class spell_telash_ice_power_perodic : public AuraScript
{
    PrepareAuraScript(spell_telash_ice_power_perodic);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        target->SetPower(POWER_ENERGY, target->GetPower(POWER_ENERGY) + 2);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_telash_ice_power_perodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 386781 - Frost Bomb
class spell_telash_frost_bomb_cast : public SpellScript
{
    PrepareSpellScript(spell_telash_frost_bomb_cast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FROST_BOMB_AURA });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_FROST_BOMB_AURA, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_telash_frost_bomb_cast::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 386881 - Frost Bomb
class spell_telash_frost_bomb_aura : public AuraScript
{
    PrepareAuraScript(spell_telash_frost_bomb_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FROST_BOMB_DAMAGE, SPELL_FROZEN_GROUND_AT });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(GetTarget(), SPELL_FROZEN_GROUND_AT, true);
            caster->CastSpell(GetTarget(), SPELL_FROST_BOMB_DAMAGE, true);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_telash_frost_bomb_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 387928 - Absolute Zero
class spell_telash_absolute_zero_cast : public SpellScript
{
    PrepareSpellScript(spell_telash_absolute_zero_cast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ABSOLUTE_ZERO_JUMP });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        // spell targets a GroupAI so we change it to Dest Dest
        GetCaster()->CastSpell(TelashJumpPosition, SPELL_ABSOLUTE_ZERO_JUMP, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_telash_absolute_zero_cast::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 390209 - Activate Vault Rune
class spell_telash_activate_vault_rune : public SpellScript
{
    PrepareSpellScript(spell_telash_activate_vault_rune);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VAULT_RUNE_AT_AURA });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->HasAura(SPELL_INACTIVE_VAULT_RUNE))
            return;

        GetHitUnit()->CastSpell(nullptr, SPELL_VAULT_RUNE_AT_AURA, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_telash_activate_vault_rune::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

static Position const TelashJumpBackPositions[] =
{
    { -5350.0835f, 1089.8976f, 340.5709f, 5.0882f },
    { -5310.4464f, 1066.8134f, 340.5967f, 3.9184f },
    { -5350.3934f, 1043.9323f, 340.5894f, 2.0924f }
};

// 388008 - Absolute Zero
class spell_telash_absolute_zero_damage : public SpellScript
{
    PrepareSpellScript(spell_telash_absolute_zero_damage);

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        Unit* victim = caster->GetAI()->SelectTarget(SelectTargetMethod::MaxThreat);
        if (!victim)
            return;

        float currentDistance = 1000.0f;
        Position const* currentPosition = nullptr;

        for (Position const& pos : TelashJumpBackPositions)
        {
            float dist = victim->GetDistance(pos);
            if (dist < currentDistance)
            {
                currentDistance = dist;
                currentPosition = &pos;
            }
        }

        if (!currentPosition)
            return;

        caster->CastSpell(*currentPosition, SPELL_ABSOLUTE_ZERO_JUMP_BACK, true);
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_VAULT_RUNE_AT_AURA);
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_VAULT_RUNE_SHIELD);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_telash_absolute_zero_damage::HandleAfterCast);
        OnEffectHitTarget += SpellEffectFn(spell_telash_absolute_zero_damage::HandleHitTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_telash_greywing()
{
    // Creature
    RegisterAzureVaultCreatureAI(boss_telash_greywing);

    // AreaTrigger
    RegisterAreaTriggerAI(at_telash_greywing_vault_rune);

    // Spells
    RegisterSpellScript(spell_telash_ice_power_perodic);
    RegisterSpellScript(spell_telash_frost_bomb_cast);
    RegisterSpellScript(spell_telash_frost_bomb_aura);
    RegisterSpellScript(spell_telash_absolute_zero_cast);
    RegisterSpellScript(spell_telash_activate_vault_rune);
    RegisterSpellScript(spell_telash_absolute_zero_damage);
}
