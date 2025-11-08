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

/*
 * Timers requires to be revisited
 * The way Shadow Nova \ Conflagration is handled requires re-checks,
   there are spells with unknown purpose. Also maybe it should be handled in one event instead of two
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "sunwell_plateau.h"

enum SacrolashTexts
{
    // Sacrolash
    SAY_INTRO_SAC               = 0,
    SAY_SHADOW_NOVA             = 1,
    SAY_SLAY_SAC                = 2,
    SAY_ALYTHESS_DEAD           = 3,
    SAY_BERSERK_SAC             = 4,
    SAY_DEATH_SAC               = 5,
    EMOTE_SHADOW_NOVA_SAC       = 6,
    EMOTE_CONFLAGRATION_SAC     = 7,

    // Alythess
    SAY_INTRO_ALY               = 0,
    SAY_CONFLAGRATION           = 1,
    SAY_SLAY_ALY                = 2,
    SAY_SACROLASH_DEAD          = 3,
    SAY_BERSERK_ALY             = 4,
    SAY_DEATH_ALY               = 5,
    EMOTE_CONFLAGRATION_ALY     = 6,
    EMOTE_SHADOW_NOVA_ALY       = 7
};

enum SacrolashSpells
{
    // Sacrolash - Passive
    SPELL_DUAL_WIELD_PASSIVE    = 42459,
    SPELL_SHADOWFORM            = 45455,

    // Sacrolash - Combat
    SPELL_SHADOW_BLADES         = 45248,
    SPELL_CONFOUNDING_BLOW      = 45256,
    SPELL_SUMMON_SHADOW_IMAGES  = 45258,
    SPELL_SHADOW_NOVA           = 45329,
    SPELL_SHADOW_NOVA_DUMMY     = 45332,       // NYI, related to how Shadow Nova \ Conflagration is handled

    // Alythess - Passive
    SPELL_FIREFORM              = 45457,

    // Alythess - Combat
    SPELL_PYROGENICS            = 45230,
    SPELL_BLAZE                 = 45235,
    SPELL_FLAME_SEAR            = 46771,
    SPELL_CONFLAGRATION         = 45342,
    SPELL_CONFLAGRATION_DUMMY   = 45333,       // NYI, related to how Shadow Nova \ Conflagration is handled

    // Shared
    SPELL_DARK_FLAME_AURA_SAC   = 45343,
    SPELL_DARK_FLAME_AURA_ALY   = 47300,
    SPELL_EMPOWER               = 45366,
    SPELL_BERSERK               = 46587,
    SPELL_INSTAKILL_SELF        = 29878,

    // Shadow Image
    SPELL_SHADOW_IMAGE_VISUAL   = 45263,
    SPELL_SHADOW_FURY           = 45270,
    SPELL_DARK_STRIKE           = 45271,
    SPELL_SHADOWSTEP            = 45273,

    // Scripts
    SPELL_BLAZE_SUMMON          = 45236,
    SPELL_DARK_FLAME            = 45345,
    SPELL_DARK_TOUCHED          = 45347,
    SPELL_FLAME_TOUCHED         = 45348,
    SPELL_BURN                  = 45246,
    SPELL_CONFLAGRATION_TRIGGER = 46768
};

enum SacrolashEvents
{
    // Sacrolash - Intro
    EVENT_SAC_INTRO             = 1,

    // Alythess - Intro
    EVENT_ALY_INTRO_1,
    EVENT_ALY_INTRO_2,

    // Sacrolash - Combat
    EVENT_SHADOW_BLADES,
    EVENT_CONFOUNDING_BLOW,
    EVENT_SUMMON_SHADOW_IMAGES,

    // Alythess - Combat
    EVENT_PYROGENICS,
    EVENT_BLAZE,
    EVENT_FLAME_SEAR,

    // Shared
    EVENT_BERSERK,
    EVENT_SISTER_DEAD,
    EVENT_CONFLAGRATION,
    EVENT_SHADOW_NOVA,
    EVENT_DEATH_1,
    EVENT_DEATH_2
};

enum SacrolashMisc
{
    ACTION_START_INTRO          = 0,
    ACTION_SISTER_DEAD          = 1,
    SOUND_INTRO                 = 12484
};

// 25165 - Lady Sacrolash
struct boss_sacrolash : public BossAI
{
    boss_sacrolash(Creature* creature) : BossAI(creature, DATA_EREDAR_TWINS), _sisterIsDead(false), _isAboutToDie(false) { }

    void Reset() override
    {
        _Reset();

        DoCastSelf(SPELL_DUAL_WIELD_PASSIVE);
        DoCastSelf(SPELL_SHADOWFORM);

        _sisterIsDead = false;
        _isAboutToDie = false;

        me->GetMap()->Respawn(SPAWN_TYPE_CREATURE, instance->GetData64(DATA_ALYTHESS));
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        // Prevents sending Badge of Justice from each boss
        me->SetLootMode(0);

        DoCastSelf(SPELL_DARK_FLAME_AURA_SAC);
        DoCastSelf(SPELL_DARK_FLAME_AURA_ALY);

        events.ScheduleEvent(EVENT_SHADOW_BLADES, 10s, 15s);
        events.ScheduleEvent(EVENT_CONFOUNDING_BLOW, 15s, 20s);
        events.ScheduleEvent(EVENT_SUMMON_SHADOW_IMAGES, 10s, 30s);
        events.ScheduleEvent(EVENT_SHADOW_NOVA, 30s, 35s);
        events.ScheduleEvent(EVENT_BERSERK, 6min);
    }

    void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_sisterIsDead)
            return;

        if (damage >= me->GetHealth() && who != me)
        {
            damage = me->GetHealth() -1;

            if (!_isAboutToDie)
            {
                _isAboutToDie = true;

                if (Creature* alythess = instance->GetCreature(DATA_ALYTHESS))
                    if (alythess->IsAlive())
                        alythess->AI()->DoAction(ACTION_SISTER_DEAD);

                events.Reset();
                me->InterruptNonMeleeSpells(false);
                events.ScheduleEvent(EVENT_DEATH_1, 0s);
            }
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _DespawnAtEvade();
        if (Creature* alythess = instance->GetCreature(DATA_ALYTHESS))
            alythess->RemoveCorpse(false);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_BERSERK:
                Talk(SAY_BERSERK_SAC);
                break;
            case SPELL_EMPOWER:
                Talk(SAY_ALYTHESS_DEAD);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_INTRO:
                events.ScheduleEvent(EVENT_SAC_INTRO, 0s);
                break;
            case ACTION_SISTER_DEAD:
                me->ResetLootMode();
                _sisterIsDead = true;
                events.ScheduleEvent(EVENT_SISTER_DEAD, 0s);
                events.ScheduleEvent(EVENT_CONFLAGRATION, 15s, 20s);
                events.CancelEvent(EVENT_SHADOW_NOVA);
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* victim) override
    {
        // Do not say if killed self by spell
        if (victim != me)
            Talk(SAY_SLAY_SAC);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_sisterIsDead)
        {
            // It is important to make encounter complete only if both sisters are defeated
            // Otherwise if only one sister will be defeated and wipe occured, second sister will despawn on evade and never respawn
            _JustDied();
            Talk(SAY_DEATH_SAC);
        }
        else
            me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SAC_INTRO:
                        DoPlaySoundToSet(me, SOUND_INTRO);
                        Talk(SAY_INTRO_SAC);
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHADOW_BLADES:
                    DoCastSelf(SPELL_SHADOW_BLADES);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_CONFOUNDING_BLOW:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_CONFOUNDING_BLOW);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_SUMMON_SHADOW_IMAGES:
                    DoCastSelf(SPELL_SUMMON_SHADOW_IMAGES);
                    events.Repeat(8s, 20s);
                    break;
                case EVENT_SHADOW_NOVA:
                {
                    Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true);

                    if (target)
                    {
                        DoCast(target, SPELL_SHADOW_NOVA);
                        Talk(EMOTE_SHADOW_NOVA_SAC, target);
                        Talk(SAY_SHADOW_NOVA);
                    }
                    events.Repeat(30s, 35s);
                    break;
                }
                case EVENT_CONFLAGRATION:
                {
                    Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true);

                    if (target)
                    {
                        DoCast(target, SPELL_CONFLAGRATION);
                        Talk(EMOTE_CONFLAGRATION_SAC, target);
                    }
                    events.Repeat(30s, 35s);
                    break;
                }
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;
                case EVENT_SISTER_DEAD:
                    DoCastSelf(SPELL_EMPOWER);
                    break;
                case EVENT_DEATH_1:
                    me->SetReactState(REACT_PASSIVE);
                    events.ScheduleEvent(EVENT_DEATH_2, 3s);
                    break;
                case EVENT_DEATH_2:
                    me->SetCorpseDelay(60, true);
                    DoCastSelf(SPELL_INSTAKILL_SELF);
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
    bool _sisterIsDead;
    bool _isAboutToDie;
};

// 25166 - Grand Warlock Alythess
struct boss_alythess : public BossAI
{
    boss_alythess(Creature* creature) : BossAI(creature, DATA_EREDAR_TWINS), _sisterIsDead(false), _isAboutToDie(false) { }

    void InitializeAI() override
    {
        BossAI::InitializeAI();
        SetCombatMovement(false);
    }

    void Reset() override
    {
        _Reset();

        DoCastSelf(SPELL_FIREFORM);

        _sisterIsDead = false;
        _isAboutToDie = false;

        me->GetMap()->Respawn(SPAWN_TYPE_CREATURE, instance->GetData64(DATA_SACROLASH));
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        // Prevents sending Badge of Justice from each boss
        me->SetLootMode(0);

        DoCastSelf(SPELL_DARK_FLAME_AURA_SAC);
        DoCastSelf(SPELL_DARK_FLAME_AURA_ALY);

        events.ScheduleEvent(EVENT_PYROGENICS, 15s, 30s);
        events.ScheduleEvent(EVENT_BLAZE, 0s);
        events.ScheduleEvent(EVENT_FLAME_SEAR, 10s, 12s);
        events.ScheduleEvent(EVENT_CONFLAGRATION, 15s, 20s);
        events.ScheduleEvent(EVENT_BERSERK, 6min);
    }

    void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_sisterIsDead)
            return;

        if (damage >= me->GetHealth() && who != me)
        {
            damage = me->GetHealth() -1;

            if (!_isAboutToDie)
            {
                _isAboutToDie = true;

                if (Creature* sacrolash = instance->GetCreature(DATA_SACROLASH))
                    if (sacrolash->IsAlive())
                        sacrolash->AI()->DoAction(ACTION_SISTER_DEAD);

                events.Reset();
                me->InterruptNonMeleeSpells(false);
                events.ScheduleEvent(EVENT_DEATH_1, 0s);
            }
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _DespawnAtEvade();
        if (Creature* sacrolash = instance->GetCreature(DATA_SACROLASH))
            sacrolash->RemoveCorpse(false);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_BERSERK:
                Talk(SAY_BERSERK_ALY);
                break;
            case SPELL_EMPOWER:
                Talk(SAY_SACROLASH_DEAD);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_INTRO:
                events.ScheduleEvent(EVENT_ALY_INTRO_1, 0s);
                break;
            case ACTION_SISTER_DEAD:
                me->ResetLootMode();
                _sisterIsDead = true;
                events.ScheduleEvent(EVENT_SISTER_DEAD, 0s);
                events.ScheduleEvent(EVENT_SHADOW_NOVA, 15s, 20s);
                events.CancelEvent(EVENT_CONFLAGRATION);
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* victim) override
    {
        // Do not say if killed self by spell
        if (victim != me)
            Talk(SAY_SLAY_ALY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_sisterIsDead)
        {
            // It is important to make encounter complete only if both sisters are defeated
            // Otherwise if only one sister will be defeated and wipe occured, second sister will despawn on evade and never respawn
            _JustDied();
            Talk(SAY_DEATH_ALY);
        }
        else
            me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ALY_INTRO_1:
                        DoPlaySoundToSet(me, SOUND_INTRO);
                        events.ScheduleEvent(EVENT_ALY_INTRO_2, 2s);
                        break;
                    case EVENT_ALY_INTRO_2:
                        Talk(SAY_INTRO_ALY);
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PYROGENICS:
                    DoCastSelf(SPELL_PYROGENICS);
                    events.Repeat(20s, 40s);
                    break;
                case EVENT_BLAZE:
                    DoCastVictim(SPELL_BLAZE);
                    events.Repeat(3s, 4s);
                    break;
                case EVENT_FLAME_SEAR:
                    DoCastSelf(SPELL_FLAME_SEAR, { SPELLVALUE_MAX_TARGETS, 5 });
                    events.Repeat(8s, 13s);
                    break;
                case EVENT_CONFLAGRATION:
                {
                    Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true);

                    if (target)
                    {
                        DoCast(target, SPELL_CONFLAGRATION);
                        Talk(EMOTE_CONFLAGRATION_ALY, target);
                        Talk(SAY_CONFLAGRATION);
                    }
                    events.Repeat(30s, 35s);
                    break;
                }
                case EVENT_SHADOW_NOVA:
                {
                    Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true);

                    if (target)
                    {
                        DoCast(target, SPELL_SHADOW_NOVA);
                        Talk(EMOTE_SHADOW_NOVA_ALY, target);
                    }
                    events.Repeat(30s, 35s);
                    break;
                }
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;
                case EVENT_SISTER_DEAD:
                    DoCastSelf(SPELL_EMPOWER);
                    break;
                case EVENT_DEATH_1:
                    me->SetReactState(REACT_PASSIVE);
                    events.ScheduleEvent(EVENT_DEATH_2, 3s);
                    break;
                case EVENT_DEATH_2:
                    me->SetCorpseDelay(60, true);
                    DoCastSelf(SPELL_INSTAKILL_SELF);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _sisterIsDead;
    bool _isAboutToDie;
};

// 25214 - Shadow Image
struct npc_shadow_image : public ScriptedAI
{
    npc_shadow_image(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        ScriptedAI::InitializeAI();
        me->SetCorpseDelay(0);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SHADOW_IMAGE_VISUAL);

        DoZoneInCombat();

        _scheduler.Schedule(1s, [this](TaskContext /*task*/)
        {
            AttackRandomTarget();
        });

        _scheduler.Schedule(10s, [this](TaskContext /*task*/)
        {
            me->KillSelf();
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void AttackRandomTarget()
    {
        ResetThreatList();
        DoZoneInCombat();

        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
        {
            AddThreat(target, 1000000.0f);
            AttackStart(target);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        switch (urand(0, 2))
        {
            case 0:
            {
                _scheduler.Schedule(2s, [this](TaskContext task)
                {
                    if (me->IsWithinMeleeRange(me->GetVictim()))
                        DoCastSelf(SPELL_SHADOW_FURY);
                    else
                        task.Repeat(100ms);
                });
                break;
            }
            case 1:
            {
                _scheduler.Schedule(2s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_DARK_STRIKE);
                    task.Repeat(1s);
                });
                break;
            }
            case 2:
            {
                _scheduler.Schedule(2s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_DARK_STRIKE);
                    task.Repeat(1s);
                });

                _scheduler.Schedule(3s, [this](TaskContext task)
                {
                    DoCastVictim(SPELL_SHADOWSTEP);
                    task.Repeat(1s);
                });
                break;
            }
            default:
                break;
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_SHADOW_FURY:
                me->DespawnOrUnsummon(1s);
                break;
            case SPELL_DARK_STRIKE:
                // Not sure where exactly this should be called. What is known is it is called not always,
                // before Dark Strike, in both scenarios with Dark Strike. What should be checked is the exact place where it should be called.
                // Also looks like it is called every time before first Dark Strike, but that should be re-checked
                if (roll_chance_i(50))
                    AttackRandomTarget();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 45235 - Blaze
class spell_eredar_twins_blaze : public SpellScript
{
    PrepareSpellScript(spell_eredar_twins_blaze);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLAZE_SUMMON });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_BLAZE_SUMMON, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_eredar_twins_blaze::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 45343 - Dark Flame Aura
class spell_eredar_twins_dark_flame_aura_shadow : public AuraScript
{
    PrepareAuraScript(spell_eredar_twins_dark_flame_aura_shadow);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DARK_FLAME,
            SPELL_FLAME_TOUCHED,
            SPELL_DARK_TOUCHED,
            SPELL_SHADOW_BLADES,
            SPELL_CONFOUNDING_BLOW,
            SPELL_SHADOW_NOVA,
            SPELL_SHADOW_FURY,
            SPELL_DARK_STRIKE
        });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        // Don't allow to proc if target has Dark Flame
        if (eventInfo.GetActionTarget()->HasAura(SPELL_DARK_FLAME))
            return false;

        // Allow proc from melee damage (Shadow Image deals no melee damage (see on-spawn aura), only Sacrolash does)
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo)
            return true;

        // Allow proc from shadow spells
        switch (spellInfo->Id)
        {
            case SPELL_SHADOW_BLADES:
            case SPELL_CONFOUNDING_BLOW:
            case SPELL_SHADOW_NOVA:
            case SPELL_SHADOW_FURY:
            case SPELL_DARK_STRIKE:
                return true;
            default:
                return false;
        }

        return false;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        Unit* target = eventInfo.GetActionTarget();

        if (target->HasAura(SPELL_FLAME_TOUCHED))
        {
            target->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
            target->CastSpell(target, SPELL_DARK_FLAME, true);
        }
        else
            target->CastSpell(target, SPELL_DARK_TOUCHED, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_eredar_twins_dark_flame_aura_shadow::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_eredar_twins_dark_flame_aura_shadow::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 47300 - Dark Flame Aura
class spell_eredar_twins_dark_flame_aura_fire : public AuraScript
{
    PrepareAuraScript(spell_eredar_twins_dark_flame_aura_fire);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DARK_FLAME,
            SPELL_FLAME_TOUCHED,
            SPELL_DARK_TOUCHED,
            SPELL_BLAZE,
            SPELL_FLAME_SEAR,
            SPELL_CONFLAGRATION,
            SPELL_BURN,
            SPELL_CONFLAGRATION_TRIGGER
        });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        // Don't allow to proc if target has Dark Flame
        if (eventInfo.GetActionTarget()->HasAura(SPELL_DARK_FLAME))
            return false;

        // Don't allow to proc from melee damage, Alythess any way doesn't do melee damage
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo)
            return false;

        // Allow proc from fire spells
        switch (spellInfo->Id)
        {
            case SPELL_BLAZE:
            case SPELL_FLAME_SEAR:
            case SPELL_CONFLAGRATION:
            case SPELL_BURN:
            case SPELL_CONFLAGRATION_TRIGGER:
                return true;
            default:
                return false;
        }

        return false;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        Unit* target = eventInfo.GetActionTarget();

        if (target->HasAura(SPELL_DARK_TOUCHED))
        {
            target->RemoveAurasDueToSpell(SPELL_DARK_TOUCHED);
            target->CastSpell(target, SPELL_DARK_FLAME, true);
        }
        else
            target->CastSpell(target, SPELL_FLAME_TOUCHED, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_eredar_twins_dark_flame_aura_fire::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_eredar_twins_dark_flame_aura_fire::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 4937
class at_witchs_sanctum : public OnlyOnceAreaTriggerScript
{
public:
    at_witchs_sanctum() : OnlyOnceAreaTriggerScript("at_witchs_sanctum") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (Creature* sacrolash = instance->GetCreature(DATA_SACROLASH))
                sacrolash->AI()->DoAction(ACTION_START_INTRO);

            if (Creature* alythess = instance->GetCreature(DATA_ALYTHESS))
                alythess->AI()->DoAction(ACTION_START_INTRO);
        }

        return true;
    }
};

void AddSC_boss_eredar_twins()
{
    RegisterSunwellPlateauCreatureAI(boss_sacrolash);
    RegisterSunwellPlateauCreatureAI(boss_alythess);
    RegisterSunwellPlateauCreatureAI(npc_shadow_image);
    RegisterSpellScript(spell_eredar_twins_blaze);
    RegisterSpellScript(spell_eredar_twins_dark_flame_aura_shadow);
    RegisterSpellScript(spell_eredar_twins_dark_flame_aura_fire);
    new at_witchs_sanctum();
}
