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

#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "waycrest_manor.h"

enum LordAndLadyWaycrestSpells
{
    // Lord Waycrest
    SPELL_WASTING_STRIKE                = 261438,
    SPELL_VIRULENT_PATHOGEN_SELECTOR    = 261439,
    SPELL_VIRULENT_PATHOGEN_DAMAGE      = 261440,
    SPELL_VIRULENT_PATHOGEN_INFECT_AREA = 261441,
    SPELL_PUTRID_VITALITY               = 261447,
    SPELL_LORD_WAYCREST_DUMMY_ABSORB    = 273699,
    SPELL_CONTAGIOUS_REMNANTS           = 268385,

    // Lady Waycrest
    SPELL_SOUL_ARMOR                    = 271590,
    SPELL_DISCORDANT_CADENZA            = 268306,
    SPELL_DISCORDANT_CADENZA_DAMAGE     = 268308,
    SPELL_WRACKING_BOLT                 = 268281,
    SPELL_WRACKING_CHORD_SELECTOR       = 268278,
    SPELL_WRACKING_CHORD_DAMAGE         = 268271,
    SPELL_VITALITY_TRANSFER             = 261446,
    SPELL_HEAL                          = 210237,
    SPELL_MOVE_TO_ARENA                 = 267082
};

enum LordAndLadyWaycrestVisual
{
    SPELL_VISUAL_DISCORDANT_CADENZA_MISSILE = 76184
};

enum LordAndLadyWaycrestTexts
{
    // Lord Waycrest
    SAY_VIRULENT_PATHOGEN   = 0,

    // Lady Waycrest
    SAY_AGGRO               = 0,
    SAY_DISCORDANT_CADENZA  = 2,
    SAY_HEAL                = 3,
    SAY_DIED                = 4,

    // Shared
    SAY_SLAY                = 1
};

enum LordAndLadyWaycrestEvents
{
    // Lord Waycrest
    EVENT_WASTING_STRIKE = 1,
    EVENT_VIRULENT_PATHOGEN,
    EVENT_RESET_HEAL,

    // Lady Waycrest
    EVENT_WRACKING_CHORD,
    EVENT_DISCORDANT_CADENZA,
    EVENT_JOIN_FIGHT
};

enum LordAndLadyWaycrestActions
{
    ACTION_HEAL_LORD_WAYCREST = 1,
    ACTION_HEAL_AND_JOIN_FIGHT
};

constexpr Position LordWaycrestCombatPosition = { -549.781f, -260.094f, 185.267f };

// 131527 - Lord Waycrest
struct boss_lord_waycrest : public BossAI
{
    boss_lord_waycrest(Creature* creature) : BossAI(creature, DATA_LORD_WAYCREST), _timesHealed(0), _healed(false)
    {
        SetBoundary(instance->GetBossBoundary(DATA_LORD_AND_LADY_WAYCREST));
    }

    void Reset() override
    {
        events.Reset();
        _timesHealed = 0;
        _healed = false;
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (me->IsInEvadeMode())
            return;

        instance->SetBossState(DATA_LORD_AND_LADY_WAYCREST, FAIL);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VIRULENT_PATHOGEN_DAMAGE);

        _EnterEvadeMode();
        _DespawnAtEvade();

        if (Creature* ladyWaycrest = instance->GetCreature(DATA_LADY_WAYCREST))
            ladyWaycrest->AI()->EnterEvadeMode(why);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_timesHealed != 3 && me->GetHealth() <= damage)
            damage = me->GetHealth() - 1;

        if (me->HealthBelowPctDamaged(30, damage) && !_healed)
        {
            if (_timesHealed < 2)
            {
                if (Creature* ladyWaycrest = instance->GetCreature(DATA_LADY_WAYCREST))
                    ladyWaycrest->AI()->DoAction(ACTION_HEAL_LORD_WAYCREST);

                events.ScheduleEvent(EVENT_RESET_HEAL, 3s);
            }
            else if (_timesHealed == 2)
            {
                if (Creature* ladyWaycrest = instance->GetCreature(DATA_LADY_WAYCREST))
                    ladyWaycrest->AI()->DoAction(ACTION_HEAL_AND_JOIN_FIGHT);
            }

            _timesHealed++;
            _healed = true;
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_LORD_WAYCREST_DUMMY_ABSORB);
        me->GetMotionMaster()->MoveJumpWithGravity(LordWaycrestCombatPosition, 20.0f, 15.1852f);

        instance->SetBossState(DATA_LORD_AND_LADY_WAYCREST, IN_PROGRESS);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (Creature* ladyWaycrest = instance->GetCreature(DATA_LADY_WAYCREST))
            ladyWaycrest->AI()->DoZoneInCombat();

        events.ScheduleEvent(EVENT_WASTING_STRIKE, 7200ms);
        events.ScheduleEvent(EVENT_VIRULENT_PATHOGEN, 10800ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (Creature* ladyWaycrest = instance->GetCreature(DATA_LADY_WAYCREST))
        {
            if (ladyWaycrest->IsAlive())
                return;
            else
                instance->SetBossState(DATA_LORD_AND_LADY_WAYCREST, DONE);
        }

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VIRULENT_PATHOGEN_DAMAGE);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_WASTING_STRIKE:
            {
                DoCastVictim(SPELL_WASTING_STRIKE);
                events.Repeat(17000ms);
                break;
            }
            case EVENT_VIRULENT_PATHOGEN:
            {
                Talk(SAY_VIRULENT_PATHOGEN);
                DoCast(SPELL_VIRULENT_PATHOGEN_SELECTOR);
                events.Repeat(17000ms);
                break;
            }
            case EVENT_RESET_HEAL:
            {
                _healed = false;
                break;
            }
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
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    uint8 _timesHealed;
    bool _healed;
};

// 136918 - Lady Waycrest
struct boss_lady_waycrest : public BossAI
{
    boss_lady_waycrest(Creature* creature) : BossAI(creature, DATA_LADY_WAYCREST), _isInArena(false)
    {
        SetBoundary(instance->GetBossBoundary(DATA_LORD_AND_LADY_WAYCREST));
    }

    void Reset() override
    {
        events.Reset();
        _isInArena = false;
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (me->IsInEvadeMode())
            return;

        instance->SetBossState(DATA_LORD_AND_LADY_WAYCREST, FAIL);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        _EnterEvadeMode();
        _DespawnAtEvade();

        if (Creature* lordWaycrest = instance->GetCreature(DATA_LORD_WAYCREST))
            lordWaycrest->AI()->EnterEvadeMode(why);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_SOUL_ARMOR);
        Talk(SAY_AGGRO);

        instance->SetBossState(DATA_LORD_AND_LADY_WAYCREST, IN_PROGRESS);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (Creature* lordWaycrest = instance->GetCreature(DATA_LORD_WAYCREST))
            lordWaycrest->AI()->DoZoneInCombat();

        events.ScheduleEvent(EVENT_WRACKING_CHORD, 1100ms);
        events.ScheduleEvent(EVENT_DISCORDANT_CADENZA, 13300ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_DIED);

        if (Creature* lordWaycrest = instance->GetCreature(DATA_LORD_WAYCREST))
        {
            if (lordWaycrest->IsAlive())
                return;
            else
                instance->SetBossState(DATA_LORD_AND_LADY_WAYCREST, DONE);
        }
    }

    void HealLordWaycrest()
    {
        Talk(SAY_HEAL);
        me->InterruptNonMeleeSpells(true);

        if (Creature* lordWaycrest = instance->GetCreature(DATA_LORD_WAYCREST))
            DoCast(lordWaycrest, SPELL_VITALITY_TRANSFER);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_HEAL_LORD_WAYCREST:
            {
                HealLordWaycrest();
                break;
            }
            case ACTION_HEAL_AND_JOIN_FIGHT:
            {
                if (!_isInArena)
                {
                    HealLordWaycrest();
                    events.RescheduleEvent(EVENT_WRACKING_CHORD, 10100ms);
                    events.ScheduleEvent(EVENT_JOIN_FIGHT, 3s);
                }
                break;
            }
            default:
                break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_WRACKING_CHORD:
            {
                DoCast(SPELL_WRACKING_CHORD_SELECTOR);
                if (_isInArena)
                    events.Repeat(8500ms);
                else
                    events.Repeat(2400ms);
                break;
            }
            case EVENT_DISCORDANT_CADENZA:
            {
                Talk(SAY_DISCORDANT_CADENZA);
                DoCast(SPELL_DISCORDANT_CADENZA);
                events.Repeat(21800ms);
                break;
            }
            case EVENT_JOIN_FIGHT:
            {
                me->RemoveAurasDueToSpell(SPELL_SOUL_ARMOR);
                DoCastSelf(SPELL_MOVE_TO_ARENA);
                _isInArena = true;
                break;
            }
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
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _isInArena;
};

// 261439 - Virulent Pathogen
// 261441 - Virulent Pathogen (Expire)
class spell_lord_and_lady_waycrest_virulent_pathogen_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VIRULENT_PATHOGEN_DAMAGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_VIRULENT_PATHOGEN_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lord_and_lady_waycrest_virulent_pathogen_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 261440 - Virulent Pathogen
class spell_lord_and_lady_waycrest_virulent_pathogen_damage : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VIRULENT_PATHOGEN_INFECT_AREA, SPELL_CONTAGIOUS_REMNANTS });
    }

    void HandleDamage(AuraEffect const* /*aurEff*/ , AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE && GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        Unit* target = GetTarget();

        target->CastSpell(target, SPELL_VIRULENT_PATHOGEN_INFECT_AREA, true);

        if (target->GetMap()->IsHeroicOrHigher())
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(target, SPELL_CONTAGIOUS_REMNANTS, false);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_lord_and_lady_waycrest_virulent_pathogen_damage::HandleDamage, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

class DiscordantCadenzaDamageEvent : public BasicEvent
{
public:
    explicit DiscordantCadenzaDamageEvent(Unit* caster, Position dest) : _caster(caster), _dest(dest) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        _caster->CastSpell(_dest, SPELL_DISCORDANT_CADENZA_DAMAGE, true);
        return true;
    }

private:
    Unit* _caster;
    Position _dest;
};

// 268307 - Discordant Cadenza
class spell_lord_and_lady_waycrest_discordant_cadenza_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DISCORDANT_CADENZA_DAMAGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        static constexpr Seconds TRAVEL_SPEED = 2s;

        caster->SendPlayOrphanSpellVisual(target->GetPosition(), SPELL_VISUAL_DISCORDANT_CADENZA_MISSILE, float(TRAVEL_SPEED.count()), true);
        caster->m_Events.AddEventAtOffset(new DiscordantCadenzaDamageEvent(caster, target->GetPosition()), TRAVEL_SPEED);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lord_and_lady_waycrest_discordant_cadenza_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 268278 - Wracking Chord
class spell_lord_and_lady_waycrest_wracking_chord_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WRACKING_BOLT });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_WRACKING_BOLT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lord_and_lady_waycrest_wracking_chord_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 268272 - Wracking Bolt Ping
class spell_lord_and_lady_waycrest_wracking_bolt_missile : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WRACKING_CHORD_DAMAGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_WRACKING_CHORD_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lord_and_lady_waycrest_wracking_bolt_missile::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 261446 - Vitality Transfer
class spell_lord_and_lady_waycrest_vitality_transfer : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HEAL, SPELL_PUTRID_VITALITY });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() == 5)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            Unit* target = GetTarget();
            caster->SetHealth(caster->GetHealth() - caster->CountPctFromMaxHealth(30));
            target->CastSpell(target, SPELL_HEAL, true);
            target->CastSpell(target, SPELL_PUTRID_VITALITY, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_lord_and_lady_waycrest_vitality_transfer::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 268387 - Contagious Remnants
class spell_lord_and_lady_waycrest_contagious_remnants : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VIRULENT_PATHOGEN_DAMAGE });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_VIRULENT_PATHOGEN_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lord_and_lady_waycrest_contagious_remnants::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_boss_lord_and_lady_waycrest()
{
    RegisterWaycrestManorCreatureAI(boss_lord_waycrest);
    RegisterWaycrestManorCreatureAI(boss_lady_waycrest);

    RegisterSpellScript(spell_lord_and_lady_waycrest_virulent_pathogen_selector);
    RegisterSpellScript(spell_lord_and_lady_waycrest_virulent_pathogen_damage);
    RegisterSpellScript(spell_lord_and_lady_waycrest_discordant_cadenza_selector);
    RegisterSpellScript(spell_lord_and_lady_waycrest_wracking_chord_selector);
    RegisterSpellScript(spell_lord_and_lady_waycrest_wracking_bolt_missile);
    RegisterSpellScript(spell_lord_and_lady_waycrest_vitality_transfer);
    RegisterSpellScript(spell_lord_and_lady_waycrest_contagious_remnants);
}
