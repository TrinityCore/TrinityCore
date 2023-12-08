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
#include "Map.h"
#include "MotionMaster.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Player.h"
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
    SPELL_POWER_ENERGIZE_ICE_POWER_PERIODIC     = 389453,
    SPELL_FROST_BOMB_CAST                       = 386781,
    SPELL_FROST_BOMB_AURA                       = 386881,
    SPELL_FROST_BOMB_DAMAGE                     = 386910,
    SPELL_FROZEN_GROUND_AT                      = 387149,
    SPELL_ICY_DEVASTATOR                        = 387151,
    SPELL_ABSOLUTE_ZERO_CAST                    = 387928,
    SPELL_ABSOLUTE_ZERO_JUMP                    = 387981,
    SPELL_ABSOLUTE_ZERO_JUMP_BACK               = 388082,
    SPELL_ABSOLUTE_ZERO_SHIELD                  = 388084,
    SPELL_ABSOLUTE_ZERO_DAMAGE                  = 388008,
    SPELL_ACTIVATE_VAULT_RUNE                   = 390209,
    SPELL_VAULT_RUNE_AT_AURA                    = 388065,
    SPELL_VAULT_RUNE_SHIELD                     = 390201,
    SPELL_INACTIVE_VAULT_RUNE                   = 390238,

    // Conversation
    SPELL_TELASH_APPROACH_CONV                  = 389379
};

enum TelashEvents
{
    EVENT_FROST_BOMB        = 1,
    EVENT_ICY_DEVASTATOR    = 2,
    EVENT_ABSOLUTE_ZERO     = 3
};

enum TelashSummonGroups
{
    SUMMON_GROUP_TELASH_VAULT_RUNES = 0
};

enum TelashActions
{
    ACTION_RESCHEDULE_SPELLS = 1,
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

Position const TelashJumpBackPositions[] =
{
    { -5350.0835f, 1089.8976f, 340.5709f, 5.0882f },
    { -5310.4464f, 1066.8134f, 340.5967f, 3.9184f },
    { -5350.3934f, 1043.9323f, 340.5894f, 2.0924f }
};

// 186737 - Telash Greywing
struct boss_telash_greywing : public BossAI
{
    boss_telash_greywing(Creature* creature) : BossAI(creature, DATA_TELASH_GREYWING), _isInCenter(false), _frostBombRemaining(0), _icyDevastatorRemaining(0) { }

    void JustAppeared() override
    {
        me->SummonCreatureGroup(SUMMON_GROUP_TELASH_VAULT_RUNES);
        me->SetPower(me->GetPowerType(), 60);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        _frostBombRemaining = 1;
        _icyDevastatorRemaining = 1;

        Talk(SAY_AGGRO);
        DoCast(SPELL_POWER_ENERGIZE_ICE_POWER_PERIODIC);
        events.ScheduleEvent(EVENT_FROST_BOMB, 3500ms);
        events.ScheduleEvent(EVENT_ICY_DEVASTATOR, 14500ms);
        events.ScheduleEvent(EVENT_ABSOLUTE_ZERO, 500ms);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
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
            if (!_isInCenter)
            {
                DoCastSelf(SPELL_ABSOLUTE_ZERO_DAMAGE);
                _isInCenter = true;
            }
            else
            {
                DoCastSelf(SPELL_POWER_ENERGIZE_ICE_POWER_PERIODIC);
                me->RemoveAurasDueToSpell(SPELL_ABSOLUTE_ZERO_SHIELD);
                me->SetReactState(REACT_AGGRESSIVE);
                _isInCenter = false;
            }
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
                case EVENT_FROST_BOMB:
                {
                    Talk(SAY_FROST_BOMB);
                    DoCastSelf(SPELL_FROST_BOMB_CAST);

                    _frostBombRemaining--;
                    if (!_frostBombRemaining)
                    {
                        if (_icyDevastatorRemaining == 1)
                        {
                            events.CancelEvent(EVENT_ICY_DEVASTATOR);
                            events.ScheduleEvent(EVENT_ICY_DEVASTATOR, 10800ms);
                        }
                        break;
                    }

                    events.ScheduleEvent(EVENT_FROST_BOMB, _frostBombRemaining == 2 ? 18200ms : 15800ms);
                    break;
                }
                case EVENT_ICY_DEVASTATOR:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 75.0f, true))
                    {
                        Talk(SAY_ICY_DEVASTATOR);
                        DoCast(target, SPELL_ICY_DEVASTATOR);

                        _icyDevastatorRemaining--;
                        if (!_icyDevastatorRemaining)
                        {
                            if (_frostBombRemaining == 1)
                            {
                                events.CancelEvent(EVENT_FROST_BOMB);
                                events.ScheduleEvent(EVENT_FROST_BOMB, 7300ms);
                            }
                            break;
                        }
                        events.ScheduleEvent(EVENT_ICY_DEVASTATOR, 23100ms);
                    }
                    break;
                }
                case EVENT_ABSOLUTE_ZERO:
                    if (me->GetPower(me->GetPowerType()) >= 100)
                    {
                        Talk(SAY_FLY_TO_MIDDLE);
                        Talk(SAY_ANNOUNCE_ABSOLUTE_ZERO);
                        me->SetReactState(REACT_PASSIVE);
                        me->SetDisableGravity(true, true);
                        me->RemoveAurasDueToSpell(SPELL_POWER_ENERGIZE_ICE_POWER_PERIODIC);
                        DoCastSelf(SPELL_ABSOLUTE_ZERO_CAST);
                        DoCastSelf(SPELL_ABSOLUTE_ZERO_SHIELD);
                        DoCastSelf(SPELL_ACTIVATE_VAULT_RUNE);
                        events.CancelEvent(EVENT_FROST_BOMB);
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

    void DoAction(int32 param) override
    {
        if (param == ACTION_RESCHEDULE_SPELLS)
        {
            _frostBombRemaining = 3;
            _icyDevastatorRemaining = 2;

            events.ScheduleEvent(EVENT_FROST_BOMB, 4300ms);
            events.ScheduleEvent(EVENT_ICY_DEVASTATOR, 15200ms);
        }
    }

private:
    bool _isInCenter;
    uint8 _frostBombRemaining;
    uint8 _icyDevastatorRemaining;
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

            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_INACTIVE_VAULT_RUNE, true);
            break;
        }
    }
};

// 389453 - Ice Power (periodic)
class spell_telash_ice_power_periodic : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        target->SetPower(target->GetPowerType(), target->GetPower(POWER_ENERGY) + 2);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_telash_ice_power_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 386781 - Frost Bomb
class spell_telash_frost_bomb_cast : public SpellScript
{
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
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_FROST_BOMB_DAMAGE,
            SPELL_FROZEN_GROUND_AT
        });
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
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ABSOLUTE_ZERO_JUMP });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
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
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_VAULT_RUNE_AT_AURA,
            SPELL_INACTIVE_VAULT_RUNE
        });
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

// 388008 - Absolute Zero
class spell_telash_absolute_zero_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ABSOLUTE_ZERO_JUMP_BACK,
            SPELL_VAULT_RUNE_AT_AURA,
            SPELL_VAULT_RUNE_SHIELD
        });
    }

    Position const& GetClosestPositionToMaxThreatTarget(Unit* victim)
    {
        float nearestDist = std::numeric_limits<float>::max();
        Position const* nearestPos = &TelashJumpBackPositions[0];

        for (Position const& pos : TelashJumpBackPositions)
        {
            float dist = victim->GetDistance(pos);
            if (dist < nearestDist)
            {
                nearestDist = dist;
                nearestPos = &pos;
            }
        }

        return *nearestPos;
    }

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        UnitAI* casterAI = caster->GetAI();
        if (!casterAI)
            return;

        Unit* victim = casterAI->SelectTarget(SelectTargetMethod::MaxThreat);
        if (!victim)
            return;

        casterAI->DoAction(ACTION_RESCHEDULE_SPELLS);
        caster->CastSpell(GetClosestPositionToMaxThreatTarget(victim), SPELL_ABSOLUTE_ZERO_JUMP_BACK, true);
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
    RegisterSpellScript(spell_telash_ice_power_periodic);
    RegisterSpellScript(spell_telash_frost_bomb_cast);
    RegisterSpellScript(spell_telash_frost_bomb_aura);
    RegisterSpellScript(spell_telash_absolute_zero_cast);
    RegisterSpellScript(spell_telash_activate_vault_rune);
    RegisterSpellScript(spell_telash_absolute_zero_damage);
}
