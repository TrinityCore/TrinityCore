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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "trial_of_the_crusader.h"

enum Yells
{
    SAY_INTRO               = 0,
    SAY_AGGRO               = 1,
    EMOTE_LEGION_FLAME      = 2,
    EMOTE_NETHER_PORTAL     = 3,
    SAY_MISTRESS_OF_PAIN    = 4,
    EMOTE_INCINERATE        = 5,
    SAY_INCINERATE          = 6,
    EMOTE_INFERNAL_ERUPTION = 7,
    SAY_INFERNAL_ERUPTION   = 8,
    SAY_KILL_PLAYER         = 9,
    SAY_DEATH               = 10,
    SAY_BERSERK             = 11
};

enum Summons
{
    NPC_LEGION_FLAME     = 34784,
    NPC_INFERNAL_VOLCANO = 34813,
    NPC_FEL_INFERNAL     = 34815, // immune to all CC on Heroic (stuns, banish, interrupt, etc)
    NPC_NETHER_PORTAL    = 34825,
    NPC_MISTRESS_OF_PAIN = 34826
};

enum BossSpells
{
    SPELL_LEGION_FLAME                  = 66197,
    SPELL_LEGION_FLAME_EFFECT           = 66201,
    SPELL_NETHER_POWER                  = 66228,
    SPELL_FEL_LIGHTNING                 = 66528,
    SPELL_FEL_FIREBALL                  = 66532,
    SPELL_INCINERATE_FLESH              = 66237,
    SPELL_BURNING_INFERNO               = 66242,
    SPELL_INFERNAL_ERUPTION             = 66258,
    SPELL_INFERNAL_ERUPTION_EFFECT      = 66252,
    SPELL_NETHER_PORTAL                 = 66269,
    SPELL_NETHER_PORTAL_EFFECT          = 66263,
    SPELL_LORD_JARAXXUS_HITTIN_YA       = 66327,
    SPELL_FEL_LIGHTNING_INTRO           = 67888,
    SPELL_BERSERK                       = 64238,

    // Mistress of Pain spells
    SPELL_SHIVAN_SLASH                  = 66378,
    SPELL_SPINNING_SPIKE                = 66283,
    SPELL_MISTRESS_KISS                 = 66336,
    SPELL_MISTRESS_KISS_DAMAGE_SILENCE  = 66359,

    // Felflame Infernal
    SPELL_FEL_STREAK_VISUAL             = 66493
};

enum Events
{
    // Lord Jaraxxus
    EVENT_INTRO = 1,
    EVENT_FEL_FIREBALL,
    EVENT_FEL_LIGHTNING,
    EVENT_INCINERATE_FLESH,
    EVENT_NETHER_POWER,
    EVENT_LEGION_FLAME,
    EVENT_SUMMON_NETHER_PORTAL,
    EVENT_SUMMON_INFERNAL_ERUPTION,
    EVENT_ENRAGE,
    EVENT_TAUNT_GNOME,
    EVENT_KILL_GNOME,
    EVENT_CHANGE_ORIENTATION,
    EVENT_START_COMBAT,

    // Mistress of Pain
    EVENT_SHIVAN_SLASH,
    EVENT_SPINNING_SPIKE,
    EVENT_MISTRESS_KISS
};

enum Misc
{
    PHASE_INTRO             = 1,
    PHASE_COMBAT            = 2,
    SPLINE_INITIAL_MOVEMENT = 1,
    POINT_SUMMONED          = 1
};

struct boss_jaraxxus : public BossAI
{
    boss_jaraxxus(Creature* creature) : BossAI(creature, DATA_JARAXXUS) { }

    void Reset() override
    {
        me->SetCombatPulseDelay(0);
        me->ResetLootMode();
        events.Reset();
        summons.DespawnAll();

        if (instance->GetBossState(DATA_JARAXXUS) == NOT_STARTED)
            DoAction(ACTION_JARAXXUS_INTRO);
        else if (instance->GetBossState(DATA_JARAXXUS) == FAIL)
        {
            DoCastSelf(SPELL_JARAXXUS_CHAINS);
            me->SetImmuneToPC(true);
            me->SetReactState(REACT_PASSIVE);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_FEL_FIREBALL, 6s);
        events.ScheduleEvent(EVENT_FEL_LIGHTNING, 17s);
        events.ScheduleEvent(EVENT_INCINERATE_FLESH, 14s);
        events.ScheduleEvent(EVENT_NETHER_POWER, 22s);
        events.ScheduleEvent(EVENT_LEGION_FLAME, 20s);
        events.ScheduleEvent(EVENT_SUMMON_NETHER_PORTAL, 20s);
        events.ScheduleEvent(EVENT_SUMMON_INFERNAL_ERUPTION, 1min + 20s);
        events.ScheduleEvent(EVENT_ENRAGE, 10min);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SetBossState(DATA_JARAXXUS, FAIL);
        me->DespawnOrUnsummon();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_JARAXXUS_INTRO)
        {
            me->SetReactState(REACT_PASSIVE);
            events.SetPhase(PHASE_INTRO);
            events.ScheduleEvent(EVENT_INTRO, 1s);
        }
        else if (action == ACTION_JARAXXUS_ENGAGE)
        {
            me->RemoveAurasDueToSpell(SPELL_JARAXXUS_CHAINS);
            me->SetImmuneToPC(false);
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat();
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == SPLINE_CHAIN_MOTION_TYPE && pointId == POINT_SUMMONED)
            if (Creature* wilfred = instance->GetCreature(DATA_FIZZLEBANG))
            {
                me->SetFacingToObject(wilfred);
                events.ScheduleEvent(EVENT_TAUNT_GNOME, 9s);
            }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL_PLAYER);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FEL_FIREBALL:
                    DoCastVictim(SPELL_FEL_FIREBALL);
                    events.Repeat(11s, 13s);
                    break;
                case EVENT_FEL_LIGHTNING:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_FEL_LIGHTNING);
                    events.Repeat(10s, 30s);
                    break;
                case EVENT_INCINERATE_FLESH:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                    {
                        Talk(EMOTE_INCINERATE, target);
                        Talk(SAY_INCINERATE);
                        DoCast(target, SPELL_INCINERATE_FLESH);
                    }
                    events.Repeat(23s);
                    break;
                case EVENT_NETHER_POWER:
                {
                    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                    args.AddSpellMod(SPELLVALUE_AURA_STACK, RAID_MODE(5, 10, 5, 10));
                    me->CastSpell(me, SPELL_NETHER_POWER, args);
                    events.Repeat(42s);
                    break;
                }
                case EVENT_LEGION_FLAME:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                    {
                        Talk(EMOTE_LEGION_FLAME, target);
                        DoCast(target, SPELL_LEGION_FLAME);
                    }
                    events.Repeat(30s);
                    break;
                case EVENT_SUMMON_NETHER_PORTAL:
                    Talk(EMOTE_NETHER_PORTAL);
                    Talk(SAY_MISTRESS_OF_PAIN);
                    DoCast(SPELL_NETHER_PORTAL);
                    events.Repeat(2min);
                    break;
                case EVENT_SUMMON_INFERNAL_ERUPTION:
                    Talk(EMOTE_INFERNAL_ERUPTION);
                    Talk(SAY_INFERNAL_ERUPTION);
                    DoCast(SPELL_INFERNAL_ERUPTION);
                    events.Repeat(2min);
                    break;
                case EVENT_INTRO:
                    DoCastSelf(SPELL_LORD_JARAXXUS_HITTIN_YA, true);
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_SUMMONED, SPLINE_INITIAL_MOVEMENT, true);
                    break;
                case EVENT_TAUNT_GNOME:
                    Talk(SAY_INTRO);
                    events.ScheduleEvent(EVENT_KILL_GNOME, 9s);
                    break;
                case EVENT_KILL_GNOME:
                    DoCastSelf(SPELL_FEL_LIGHTNING_INTRO);
                    events.ScheduleEvent(EVENT_CHANGE_ORIENTATION, 3s);
                    break;
                case EVENT_CHANGE_ORIENTATION:
                    me->SetFacingTo(4.729842f);
                    events.ScheduleEvent(EVENT_START_COMBAT, 7s);
                    break;
                case EVENT_START_COMBAT:
                    me->SetImmuneToPC(false);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    break;
                case EVENT_ENRAGE:
                    Talk(SAY_BERSERK);
                    DoCastSelf(SPELL_BERSERK, true);
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

struct npc_legion_flame : public ScriptedAI
{
    npc_legion_flame(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
    {
        SetCombatMovement(false);
    }

    void Reset() override
    {
        if (_instance->GetBossState(DATA_JARAXXUS) != IN_PROGRESS)
        {
            me->DespawnOrUnsummon();
            return;
        }

        if (Creature* jaraxxus = _instance->GetCreature(DATA_JARAXXUS))
            jaraxxus->AI()->JustSummoned(me);

        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(SPELL_LEGION_FLAME_EFFECT, true);
    }

private:
    InstanceScript* _instance;
};

struct npc_infernal_volcano : public ScriptedAI
{
    npc_infernal_volcano(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(SPELL_INFERNAL_ERUPTION_EFFECT, true);
        if (IsHeroic())
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
    }
};

struct npc_fel_infernal : public ScriptedAI
{
    npc_fel_infernal(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        if (_instance->GetBossState(DATA_JARAXXUS) != IN_PROGRESS)
        {
            me->DespawnOrUnsummon();
            return;
        }

        if (Creature* jaraxxus = _instance->GetCreature(DATA_JARAXXUS))
            jaraxxus->AI()->JustSummoned(me);

        _scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });

        _scheduler.Schedule(Seconds(2), [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                DoCast(target, SPELL_FEL_STREAK_VISUAL);
            context.Repeat(Seconds(15));
        });

        DoCastSelf(SPELL_LORD_JARAXXUS_HITTIN_YA, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

struct npc_nether_portal : public ScriptedAI
{
    npc_nether_portal(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(SPELL_NETHER_PORTAL_EFFECT, true);
        if (IsHeroic())
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
    }
};

struct npc_mistress_of_pain : public ScriptedAI
{
    npc_mistress_of_pain(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        if (_instance->GetBossState(DATA_JARAXXUS) != IN_PROGRESS)
        {
            me->DespawnOrUnsummon();
            return;
        }

        if (Creature* jaraxxus = _instance->GetCreature(DATA_JARAXXUS))
            jaraxxus->AI()->JustSummoned(me);

        DoCastSelf(SPELL_LORD_JARAXXUS_HITTIN_YA, true);
        _instance->SetData(DATA_MISTRESS_OF_PAIN_COUNT, INCREASE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SHIVAN_SLASH, 4s);
        _events.ScheduleEvent(EVENT_SPINNING_SPIKE, 9s);
        if (IsHeroic())
            _events.ScheduleEvent(EVENT_MISTRESS_KISS, 15s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SetData(DATA_MISTRESS_OF_PAIN_COUNT, DECREASE);
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
                case EVENT_SHIVAN_SLASH:
                    DoCastVictim(SPELL_SHIVAN_SLASH);
                    _events.Repeat(3s, 10s);
                    return;
                case EVENT_SPINNING_SPIKE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_SPINNING_SPIKE);
                    _events.Repeat(20s);
                    return;
                case EVENT_MISTRESS_KISS:
                    DoCastSelf(SPELL_MISTRESS_KISS);
                    _events.Repeat(30s);
                    return;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

// 66334, 67905, 67906, 67907 - Mistress' Kiss
class spell_mistress_kiss : public AuraScript
{
    PrepareAuraScript(spell_mistress_kiss);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MISTRESS_KISS_DAMAGE_SILENCE });
    }

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (Unit* caster = GetCaster())
            if (target->HasUnitState(UNIT_STATE_CASTING))
            {
                caster->CastSpell(target, SPELL_MISTRESS_KISS_DAMAGE_SILENCE, true);
                target->RemoveAurasDueToSpell(GetSpellInfo()->Id);
            }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mistress_kiss::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 66336, 67076, 67077, 67078 - Mistress' Kiss
class spell_mistress_kiss_area : public SpellScript
{
    PrepareSpellScript(spell_mistress_kiss_area);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        // get a list of players with mana
        targets.remove_if([](WorldObject* target)
        {
            return target->GetTypeId() == TYPEID_PLAYER && target->ToPlayer()->GetPowerType() == POWER_MANA;
        });

        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mistress_kiss_area::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_mistress_kiss_area::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 66493 - Fel Streak
class spell_fel_streak_visual : public SpellScript
{
    PrepareSpellScript(spell_fel_streak_visual);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), static_cast<uint32>(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fel_streak_visual::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_jaraxxus()
{
    RegisterTrialOfTheCrusaderCreatureAI(boss_jaraxxus);
    RegisterTrialOfTheCrusaderCreatureAI(npc_legion_flame);
    RegisterTrialOfTheCrusaderCreatureAI(npc_infernal_volcano);
    RegisterTrialOfTheCrusaderCreatureAI(npc_fel_infernal);
    RegisterTrialOfTheCrusaderCreatureAI(npc_nether_portal);
    RegisterTrialOfTheCrusaderCreatureAI(npc_mistress_of_pain);
    RegisterSpellScript(spell_mistress_kiss);
    RegisterSpellScript(spell_mistress_kiss_area);
    RegisterSpellScript(spell_fel_streak_visual);
}
