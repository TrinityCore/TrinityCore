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
 * Intro requires additional re-checks, something may be missing or implemented wrongly.
  Visually it doesn't look good because of several core bugs \ wrong implementation
 * Everything related to Burn requires additional re-checks since something may be implemented wrongly
 * Effect of SPELL_CLEAR_RETURN_STATE is NYI
 * SPELL_TAUNT_HIT_CHANCE has no effect currently
 */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "sunwell_plateau.h"

enum BrutallusTexts
{
    SAY_INTRO                           = 0,
    SAY_INTRO_BREAK_ICE                 = 1,
    SAY_INTRO_CHARGE                    = 2,
    SAY_INTRO_KILL_MADRIGOSA            = 3,
    SAY_INTRO_TAUNT                     = 4,

    SAY_AGGRO                           = 5,
    SAY_SLAY                            = 6,
    SAY_LOVE                            = 7,
    SAY_BERSERK                         = 8,
    SAY_DEATH                           = 9,

    SAY_MADR_ICE_BARRIER                = 0,
    SAY_MADR_INTRO                      = 1,
    SAY_MADR_ICE_BLOCK                  = 2,
    SAY_MADR_TRAP                       = 3,
    SAY_MADR_DEATH                      = 4
};

enum BrutallusSpells
{
    // Passive
    SPELL_DUAL_WIELD_PASSIVE            = 42459,
    SPELL_TAUNT_HIT_CHANCE              = 45210,

    // Combat
    SPELL_METEOR_SLASH                  = 45150,
    SPELL_STOMP                         = 45185,
    SPELL_BURN_PRIMER                   = 45141,
    SPELL_BERSERK                       = 26662,

    // Intro - Madrigosa
    SPELL_FREEZE                        = 46609,
    SPELL_FROST_BREATH                  = 45065,
    SPELL_FROST_BLAST                   = 44872,
    SPELL_FROSTBOLT                     = 44843,
    SPELL_ENCAPSULATE                   = 44883,
    SPELL_SELF_STUN                     = 45066,
    SPELL_PERMANENT_FEIGN_DEATH         = 29266,

    // Intro - Brutallus
    SPELL_FLAME_RING_1                  = 44873,
    SPELL_FLAME_RING_2                  = 44874,
    SPELL_FEL_FIREBALL                  = 44844,
    SPELL_ARCANE_EXPLOSION_VISUAL       = 35426,
    SPELL_CHARGE                        = 44884,
    SPELL_CLEAR_RETURN_STATE            = 38289,
    SPELL_FULL_HEAL                     = 17683,
    SPELL_BREAK_ICE                     = 46637,

    // Intro - Shared
    SPELL_CLEAR_ALL_DEBUFFS             = 34098,

    // Outro - Brutallus
    SPELL_SUMMON_DEATH_CLOUD            = 45884,

    // Outro - Madrigosa
    SPELL_SUMMON_FELBLAZE_PRE_VISUAL    = 44885,
    SPELL_SUMMON_FELBLAZE               = 45069,

    // Scripts
    SPELL_BURN_DAMAGE                   = 46394,
    SPELL_FREEZE_OBJECT                 = 46610,
    SPELL_BREAK_ICE_OBJECT              = 46638,
    SPELL_BREAK_ICE_KNOCK_BACK          = 47030
};

enum BrutallusEvents
{
    EVENT_METEOR_SLASH                  = 1,
    EVENT_STOMP,
    EVENT_BURN,
    EVENT_BERSERK,

    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_INTRO_4,
    EVENT_INTRO_5,
    EVENT_INTRO_6,
    EVENT_INTRO_7,
    EVENT_INTRO_8,
    EVENT_INTRO_9,
    EVENT_INTRO_10,
    EVENT_INTRO_11,
    EVENT_INTRO_12,
    EVENT_INTRO_13,
    EVENT_INTRO_14,
    EVENT_INTRO_15,
    EVENT_INTRO_16,
    EVENT_INTRO_17,
    EVENT_INTRO_18,
    EVENT_INTRO_19,
    EVENT_INTRO_20,
    EVENT_INTRO_21,
    EVENT_INTRO_22,
    EVENT_INTRO_23,
    EVENT_INTRO_24,
    EVENT_INTRO_25,
    EVENT_INTRO_26,

    EVENT_FROSTBOLT,

    EVENT_OUTRO_1,
    EVENT_OUTRO_2,
    EVENT_OUTRO_3
};

enum BrutallusActions
{
    ACTION_START_OUTRO                  = 0
};

enum BrutallusPoints
{
    POINT_MADRIGOSA_LAND_1              = 0,
    POINT_MADRIGOSA_LIFTOFF             = 1,
    POINT_MADRIGOSA_LAND_2              = 2,
    POINT_MADRIGOSA_LAND_3              = 3,
    POINT_BRUTALLUS_OFFSET              = 4,
    POINT_BRUTALLUS_COMBAT              = 5
};

Position const MadrigosaSpawnPos        = { 1470.3624f, 738.1818f, 64.166770f, 4.625122547149658203f };
Position const MadrigosaMoveLandPos1    = { 1463.8200f, 661.2120f, 19.797100f, 0.0f };
Position const MadrigosaMoveLiftoffPos  = { 1464.6943f, 652.1426f, 39.277885f, 0.0f };
Position const MadrigosaMoveLandPos2    = { 1464.6943f, 652.1426f, 20.819180f, 0.0f };
Position const MadrigosaMoveLandPos3    = { 1464.6943f, 652.1426f, 19.819180f, 0.0f };
Position const BrutallusMoveOffsetPos   = { 1464.4820f, 583.9001f, 44.392480f, 0.0f };
Position const BrutallusMoveCombatPos   = { 1478.7400f, 621.8980f, 22.654501f, 0.0f };

// 24882 - Brutallus
struct boss_brutallus : public BossAI
{
    boss_brutallus(Creature* creature) : BossAI(creature, DATA_BRUTALLUS) { }

    void Reset() override
    {
        _Reset();

        /// @todo: Dual Wield doesn't get apply after evade for unknown reason. Investigate this
        DoCastSelf(SPELL_DUAL_WIELD_PASSIVE);
        DoCastSelf(SPELL_TAUNT_HIT_CHANCE);
    }

    void JustEngagedWith(Unit* who) override
    {
        if (who->GetEntry() == NPC_MADRIGOSA)
            return;

        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_METEOR_SLASH, 10s);
        events.ScheduleEvent(EVENT_STOMP, 30s);
        events.ScheduleEvent(EVENT_BURN, 20s);
        events.ScheduleEvent(EVENT_BERSERK, 6min);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_STOMP:
                Talk(SAY_LOVE);
                break;
            case SPELL_BERSERK:
                Talk(SAY_BERSERK);
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        Talk(SAY_DEATH);

        DoCastSelf(SPELL_SUMMON_DEATH_CLOUD, true);

        if (Creature* madrigosa = instance->GetCreature(DATA_MADRIGOSA))
            madrigosa->AI()->DoAction(ACTION_START_OUTRO);
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
                case EVENT_METEOR_SLASH:
                    DoCastSelf(SPELL_METEOR_SLASH);
                    events.Repeat(12s);
                    break;
                case EVENT_STOMP:
                    DoCastVictim(SPELL_STOMP);
                    events.Repeat(32s);
                    break;
                case EVENT_BURN:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 100.0f, true, true, -SPELL_BURN_DAMAGE))
                        DoCast(target, SPELL_BURN_PRIMER);
                    events.Repeat(20s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

// 24895 - Madrigosa
struct npc_madrigosa : public ScriptedAI
{
    npc_madrigosa(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_INTRO_1, 2500ms);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE)
        {
            switch (id)
            {
                case POINT_MADRIGOSA_LAND_1:
                    _events.ScheduleEvent(EVENT_INTRO_2, 0s);
                    break;
                case POINT_MADRIGOSA_LIFTOFF:
                    _events.ScheduleEvent(EVENT_INTRO_9, 0s);
                    break;
                case POINT_MADRIGOSA_LAND_2:
                    _events.ScheduleEvent(EVENT_INTRO_13, 0s);
                    break;
                case POINT_MADRIGOSA_LAND_3:
                    _events.ScheduleEvent(EVENT_INTRO_14, 1s);
                    break;
                default:
                    break;
            }
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_OUTRO)
            _events.ScheduleEvent(EVENT_OUTRO_1, 1min);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;
    }

    /// @temporary: Find a better solution to end combat without breaking visuals (Feign Death)
    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_1:
                    me->GetMotionMaster()->MovePoint(POINT_MADRIGOSA_LAND_1, MadrigosaMoveLandPos1);
                    break;
                case EVENT_INTRO_2:
                    Talk(SAY_MADR_ICE_BARRIER);
                    if (Creature* trigger = _instance->GetCreature(DATA_WORLD_TRIGGER))
                        me->SetFacingToObject(trigger);
                    DoCastSelf(SPELL_FREEZE);
                    _events.ScheduleEvent(EVENT_INTRO_3, 7s);
                    break;
                case EVENT_INTRO_3:
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        me->SetFacingToObject(brutallus);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                    me->SetDisableGravity(false);
                    me->SetHover(false);
                    Talk(SAY_MADR_INTRO);
                    _events.ScheduleEvent(EVENT_INTRO_4, 6s);
                    break;
                case EVENT_INTRO_4:
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        brutallus->AI()->Talk(SAY_INTRO);
                    _events.ScheduleEvent(EVENT_INTRO_5, 4s);
                    break;
                case EVENT_INTRO_5:
                    me->SetImmuneToNPC(false);
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        AttackStart(brutallus);
                    _events.ScheduleEvent(EVENT_INTRO_6, 5s);
                    break;
                case EVENT_INTRO_6:
                    DoCastSelf(SPELL_FROST_BREATH);
                    _events.ScheduleEvent(EVENT_INTRO_7, 5s);
                    break;
                case EVENT_INTRO_7:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                    me->SetReactState(REACT_PASSIVE);
                    _events.ScheduleEvent(EVENT_INTRO_8, 2500ms);
                    break;
                case EVENT_INTRO_8:
                {
                    me->SetDisableGravity(true);
                    me->SetHover(true);
                    me->GetMotionMaster()->MovePoint(POINT_MADRIGOSA_LIFTOFF, MadrigosaMoveLiftoffPos);
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                    {
                        brutallus->SetDisableGravity(true);
                        brutallus->SetControlled(true, UNIT_STATE_ROOT);
                    }
                    break;
                }
                case EVENT_INTRO_9:
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        me->SetFacingToObject(brutallus);
                    Talk(SAY_MADR_ICE_BLOCK);
                    DoCastSelf(SPELL_FROST_BLAST);
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        brutallus->SetReactState(REACT_PASSIVE);
                    _events.ScheduleEvent(EVENT_FROSTBOLT, RAND(1200ms, 2400ms, 3600ms));
                    _events.ScheduleEvent(EVENT_INTRO_10, 8500ms);
                    break;
                case EVENT_INTRO_10:
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        brutallus->CastSpell(brutallus, SPELL_FLAME_RING_1);
                    _events.ScheduleEvent(EVENT_INTRO_11, 6s);
                    break;
                case EVENT_INTRO_11:
                {
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                    {
                        brutallus->AI()->Talk(SAY_INTRO_BREAK_ICE);
                        /// @temporary: SPELL_CLEAR_ALL_DEBUFFS doesn't remove that aura
                        brutallus->RemoveAurasDueToSpell(SPELL_FROST_BLAST);
                        brutallus->CastSpell(brutallus, SPELL_CLEAR_ALL_DEBUFFS);
                        brutallus->CastSpell(brutallus, SPELL_FLAME_RING_2);
                        brutallus->SetFacingTo(1.383456826210021972f);
                        brutallus->CastSpell(brutallus, SPELL_FEL_FIREBALL);
                        brutallus->SetImmuneToNPC(true);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_12, 6s);
                    break;
                }
                case EVENT_INTRO_12:
                    me->GetMotionMaster()->MovePoint(POINT_MADRIGOSA_LAND_2, MadrigosaMoveLandPos2);
                    _events.CancelEvent(EVENT_FROSTBOLT);
                    break;
                case EVENT_INTRO_13:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                    me->GetMotionMaster()->MovePoint(POINT_MADRIGOSA_LAND_3, MadrigosaMoveLandPos3);
                    me->SetAnimTier(AnimTier::Ground);
                    break;
                case EVENT_INTRO_14:
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        me->SetFacingToObject(brutallus);
                    _events.ScheduleEvent(EVENT_INTRO_15, 2500ms);
                    break;
                case EVENT_INTRO_15:
                {
                    DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                    DoCastSelf(SPELL_ENCAPSULATE);
                    Talk(SAY_MADR_TRAP);
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                    {
                        brutallus->SetDisableGravity(false);
                        brutallus->SetControlled(false, UNIT_STATE_ROOT);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_16, 1500ms);
                    break;
                }
                case EVENT_INTRO_16:
                {
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                    {
                        brutallus->SetDisableGravity(true);
                        brutallus->SetHover(true);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_17, 2s);
                    break;
                }
                case EVENT_INTRO_17:
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        brutallus->GetMotionMaster()->MovePoint(POINT_BRUTALLUS_OFFSET, BrutallusMoveOffsetPos);
                    _events.ScheduleEvent(EVENT_INTRO_18, 9s);
                    break;
                case EVENT_INTRO_18:
                {
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                    {
                        brutallus->CastSpell(brutallus, SPELL_ARCANE_EXPLOSION_VISUAL);
                        brutallus->CastSpell(brutallus, SPELL_CLEAR_ALL_DEBUFFS);
                        brutallus->AI()->Talk(SAY_INTRO_CHARGE);
                        brutallus->GetMotionMaster()->MoveFall();
                    }
                    me->InterruptNonMeleeSpells(false);
                    _events.ScheduleEvent(EVENT_INTRO_19, 1s);
                    break;
                }
                case EVENT_INTRO_19:
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        me->SetFacingToObject(brutallus);
                    DoCastSelf(SPELL_SELF_STUN);
                    me->SetImmuneToNPC(true);
                    _events.ScheduleEvent(EVENT_INTRO_20, 1500ms);
                    break;
                case EVENT_INTRO_20:
                {
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                    {
                        brutallus->SetDisableGravity(false);
                        brutallus->SetHover(false);
                        brutallus->CastSpell(brutallus, SPELL_CHARGE);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_21, 1s);
                    break;
                }
                case EVENT_INTRO_21:
                    me->RemoveAurasDueToSpell(SPELL_SELF_STUN);
                    DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
                    Talk(SAY_MADR_DEATH);
                    _events.ScheduleEvent(EVENT_INTRO_22, 2s);
                    break;
                case EVENT_INTRO_22:
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        brutallus->CastSpell(brutallus, SPELL_CLEAR_RETURN_STATE);
                    _events.ScheduleEvent(EVENT_INTRO_23, 1s);
                    break;
                case EVENT_INTRO_23:
                {
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                    {
                        brutallus->CastSpell(brutallus, SPELL_FULL_HEAL);
                        brutallus->GetMotionMaster()->MovePoint(POINT_BRUTALLUS_COMBAT, BrutallusMoveCombatPos);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_24, 3500ms);
                    break;
                }
                case EVENT_INTRO_24:
                {
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                    {
                        brutallus->AI()->Talk(SAY_INTRO_KILL_MADRIGOSA);
                        brutallus->SetFacingTo(0.069813169538974761f);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_25, 7s);
                    break;
                }
                case EVENT_INTRO_25:
                {
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                    {
                        brutallus->AI()->Talk(SAY_INTRO_TAUNT);
                        brutallus->CastSpell(brutallus, SPELL_BREAK_ICE);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_26, 2500ms);
                    break;
                }
                case EVENT_INTRO_26:
                {
                    me->SetHomePosition(me->GetPosition());

                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                    {
                        brutallus->SetImmuneToNPC(false);
                        brutallus->SetHomePosition(brutallus->GetPosition());
                        brutallus->SetReactState(REACT_AGGRESSIVE);
                        /// @temporary: Should not be called, find a better solution to end combat
                        brutallus->AI()->EnterEvadeMode();
                    }
                    break;
                }

                case EVENT_FROSTBOLT:
                    if (Creature* brutallus = _instance->GetCreature(DATA_BRUTALLUS))
                        DoCast(brutallus, SPELL_FROSTBOLT);
                    _events.Repeat(RAND(1200ms, 2400ms, 3600ms));
                    break;

                case EVENT_OUTRO_1:
                    DoCastSelf(SPELL_SUMMON_FELBLAZE_PRE_VISUAL);
                    _events.ScheduleEvent(EVENT_OUTRO_2, 3s);
                    break;
                case EVENT_OUTRO_2:
                    // We are not ready to summon Felmyst (currently it creates double spawn)
                    // DoCastSelf(SPELL_SUMMON_FELBLAZE);
                    _events.ScheduleEvent(EVENT_OUTRO_3, 9s);
                    break;
                case EVENT_OUTRO_3:
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

// 45141 - Burn
class spell_brutallus_burn_primer : public SpellScript
{
    PrepareSpellScript(spell_brutallus_burn_primer);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BURN_DAMAGE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (!target->HasAura(SPELL_BURN_DAMAGE))
            target->CastSpell(target, SPELL_BURN_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_brutallus_burn_primer::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 45151 - Burn
class spell_brutallus_burn_ally : public SpellScript
{
    PrepareSpellScript(spell_brutallus_burn_ally);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BURN_DAMAGE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (!target->HasAura(SPELL_BURN_DAMAGE))
            target->CastSpell(target, SPELL_BURN_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_brutallus_burn_ally::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 46394 - Burn
class spell_brutallus_burn : public AuraScript
{
    PrepareAuraScript(spell_brutallus_burn);

    void HandleEffectPeriodicUpdate(AuraEffect* aurEff)
    {
        if (aurEff->GetTickNumber() % 11 == 0)
            aurEff->SetAmount(aurEff->GetAmount() * 2);
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_brutallus_burn::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 45185 - Stomp
class spell_brutallus_stomp : public SpellScript
{
    PrepareSpellScript(spell_brutallus_stomp);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BURN_DAMAGE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_BURN_DAMAGE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_brutallus_stomp::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 46609 - Freeze
class spell_brutallus_freeze : public SpellScript
{
    PrepareSpellScript(spell_brutallus_freeze);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FREEZE_OBJECT });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_FREEZE_OBJECT);

        /// @temporary: ActivateObject from the spell above doesn't work
        if (InstanceScript* instance = GetHitUnit()->GetInstanceScript())
        {
            if (GameObject* iceBarrier = instance->GetGameObject(DATA_ICE_BARRIER))
            {
                iceBarrier->SetLootState(GO_READY);
                iceBarrier->UseDoorOrButton();
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_brutallus_freeze::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 46637 - Break Ice
class spell_brutallus_break_ice : public AuraScript
{
    PrepareAuraScript(spell_brutallus_break_ice);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BREAK_ICE_OBJECT, SPELL_BREAK_ICE_KNOCK_BACK });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_BREAK_ICE_OBJECT);

        /// @temporary: ActivateObject from the spell above doesn't work
        if (InstanceScript* instance = GetTarget()->GetInstanceScript())
        {
            if (GameObject* iceBarrier = instance->GetGameObject(DATA_ICE_BARRIER))
            {
                iceBarrier->SetLootState(GO_READY);
                iceBarrier->UseDoorOrButton();
            }
        }
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_BREAK_ICE_KNOCK_BACK);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_brutallus_break_ice::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_brutallus_break_ice::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 4853
class at_the_dead_scar : public OnlyOnceAreaTriggerScript
{
public:
    at_the_dead_scar() : OnlyOnceAreaTriggerScript("at_the_dead_scar") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        player->SummonCreature(NPC_MADRIGOSA, MadrigosaSpawnPos, TEMPSUMMON_MANUAL_DESPAWN);
        return true;
    }
};

void AddSC_boss_brutallus()
{
    RegisterSunwellPlateauCreatureAI(boss_brutallus);
    RegisterSunwellPlateauCreatureAI(npc_madrigosa);
    RegisterSpellScript(spell_brutallus_burn_primer);
    RegisterSpellScript(spell_brutallus_burn_ally);
    RegisterSpellScript(spell_brutallus_burn);
    RegisterSpellScript(spell_brutallus_stomp);
    RegisterSpellScript(spell_brutallus_freeze);
    RegisterSpellScript(spell_brutallus_break_ice);
    new at_the_dead_scar();
}
