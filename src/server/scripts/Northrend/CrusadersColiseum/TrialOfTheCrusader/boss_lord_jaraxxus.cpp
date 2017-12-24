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
    SPELL_LEGION_FLAME                  = 66197, // player should run away from raid because he triggers Legion Flame
    SPELL_LEGION_FLAME_EFFECT           = 66201, // used by trigger npc
    SPELL_NETHER_POWER                  = 66228, // +20% of spell damage per stack, stackable up to 5/10 times, must be dispelled/stealed
    SPELL_FEL_LIGHTING                  = 66528, // jumps to nearby targets
    SPELL_FEL_FIREBALL                  = 66532, // does heavy damage to the tank, interruptable
    SPELL_INCINERATE_FLESH              = 66237, // target must be healed or will trigger Burning Inferno
    SPELL_BURNING_INFERNO               = 66242, // triggered by Incinerate Flesh
    SPELL_INFERNAL_ERUPTION             = 66258, // summons Infernal Volcano
    SPELL_INFERNAL_ERUPTION_EFFECT      = 66252, // summons Felflame Infernal (3 at Normal and inifinity at Heroic)
    SPELL_NETHER_PORTAL                 = 66269, // summons Nether Portal
    SPELL_NETHER_PORTAL_EFFECT          = 66263, // summons Mistress of Pain (1 at Normal and infinity at Heroic)
    SPELL_LORD_JARAXXUS_HITTIN_YA       = 66327,
    SPELL_FEL_LIGHTNING                 = 67888,

    SPELL_BERSERK                       = 64238, // unused

    // Mistress of Pain spells
    SPELL_SHIVAN_SLASH                  = 67098,
    SPELL_SPINNING_STRIKE               = 66283,
    SPELL_MISTRESS_KISS                 = 66336,
    SPELL_LORD_HITTIN                   = 66326,   // special effect preventing more specific spells be cast on the same player within 10 seconds
    SPELL_MISTRESS_KISS_DAMAGE_SILENCE  = 66359,

    // Felflame Infernal
    SPELL_FEL_STREAK_VISUAL             = 66493,
    SPELL_FEL_STREAK                    = 66494,
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
    EVENT_SUMMONO_NETHER_PORTAL,
    EVENT_SUMMON_INFERNAL_ERUPTION,
    EVENT_TAUNT_GNOME,
    EVENT_KILL_GNOME,
    EVENT_CHANGE_ORIENTATION,
    EVENT_START_COMBAT,

    // Mistress of Pain
    EVENT_SHIVAN_SLASH,
    EVENT_SPINNING_STRIKE,
    EVENT_MISTRESS_KISS
};

enum Misc
{
    PHASE_INTRO             = 1,
    PHASE_COMBAT            = 2,
    SPLINE_INITIAL_MOVEMENT = 1,
    POINT_SUMMONED          = 1
};

class boss_jaraxxus : public CreatureScript
{
    public:
        boss_jaraxxus() : CreatureScript("boss_jaraxxus") { }

        struct boss_jaraxxusAI : public BossAI
        {
            boss_jaraxxusAI(Creature* creature) : BossAI(creature, DATA_JARAXXUS) { }

            void Reset() override
            {
                _Reset();
                if (instance->GetBossState(DATA_JARAXXUS) == NOT_STARTED)
                    DoAction(ACTION_JARAXXUS_INTRO);
            }

            void JustReachedHome() override
            {
                _JustReachedHome();
                instance->SetBossState(DATA_JARAXXUS, FAIL);
                DoCastSelf(SPELL_JARAXXUS_CHAINS);
                me->SetImmuneToPC(true);
                me->SetReactState(REACT_PASSIVE);
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
                _JustDied();
                Talk(SAY_DEATH);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_FEL_FIREBALL, 5 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_FEL_LIGHTNING, urand(10 * IN_MILLISECONDS, 15 * IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_INCINERATE_FLESH, urand(20 * IN_MILLISECONDS, 25 * IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_NETHER_POWER, 40 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_LEGION_FLAME, 30 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMONO_NETHER_PORTAL, 20 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_INFERNAL_ERUPTION, 80 * IN_MILLISECONDS);
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
                            events.ScheduleEvent(EVENT_FEL_FIREBALL, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            break;
                        case EVENT_FEL_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, true, -SPELL_LORD_HITTIN))
                                DoCast(target, SPELL_FEL_LIGHTING);
                            events.ScheduleEvent(EVENT_FEL_LIGHTNING, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            break;
                        case EVENT_INCINERATE_FLESH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, true, -SPELL_LORD_HITTIN))
                            {
                                Talk(EMOTE_INCINERATE, target);
                                Talk(SAY_INCINERATE);
                                DoCast(target, SPELL_INCINERATE_FLESH);
                            }
                            events.ScheduleEvent(EVENT_INCINERATE_FLESH, urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            break;
                        case EVENT_NETHER_POWER:
                            me->CastCustomSpell(SPELL_NETHER_POWER, SPELLVALUE_AURA_STACK, RAID_MODE<uint32>(5, 10, 5, 10), me, true);
                            events.ScheduleEvent(EVENT_NETHER_POWER, 40*IN_MILLISECONDS);
                            break;
                        case EVENT_LEGION_FLAME:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, true, -SPELL_LORD_HITTIN))
                            {
                                Talk(EMOTE_LEGION_FLAME, target);
                                DoCast(target, SPELL_LEGION_FLAME);
                            }
                            events.ScheduleEvent(EVENT_LEGION_FLAME, 30*IN_MILLISECONDS);
                            break;
                        case EVENT_SUMMONO_NETHER_PORTAL:
                            Talk(EMOTE_NETHER_PORTAL);
                            Talk(SAY_MISTRESS_OF_PAIN);
                            DoCast(SPELL_NETHER_PORTAL);
                            events.ScheduleEvent(EVENT_SUMMONO_NETHER_PORTAL, 2*MINUTE*IN_MILLISECONDS);
                            break;
                        case EVENT_SUMMON_INFERNAL_ERUPTION:
                            Talk(EMOTE_INFERNAL_ERUPTION);
                            Talk(SAY_INFERNAL_ERUPTION);
                            DoCast(SPELL_INFERNAL_ERUPTION);
                            events.ScheduleEvent(EVENT_SUMMON_INFERNAL_ERUPTION, 2*MINUTE*IN_MILLISECONDS);
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
                            DoCastSelf(SPELL_FEL_LIGHTNING);
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
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<boss_jaraxxusAI>(creature);
        }
};

class npc_legion_flame : public CreatureScript
{
    public:
        npc_legion_flame() : CreatureScript("npc_legion_flame") { }

        struct npc_legion_flameAI : public ScriptedAI
        {
            npc_legion_flameAI(Creature* creature) : ScriptedAI(creature)
            {
                SetCombatMovement(false);
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                me->SetInCombatWithZone();
                DoCast(SPELL_LEGION_FLAME_EFFECT);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                UpdateVictim();
                if (_instance->GetBossState(DATA_JARAXXUS) != IN_PROGRESS)
                    me->DespawnOrUnsummon();
            }
            private:
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_legion_flameAI>(creature);
        }
};

class npc_infernal_volcano : public CreatureScript
{
    public:
        npc_infernal_volcano() : CreatureScript("npc_infernal_volcano") { }

        struct npc_infernal_volcanoAI : public ScriptedAI
        {
            npc_infernal_volcanoAI(Creature* creature) : ScriptedAI(creature), _summons(me)
            {
                SetCombatMovement(false);
            }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);

                if (!IsHeroic())
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED));
                else
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED));

                _summons.DespawnAll();
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCast(SPELL_INFERNAL_ERUPTION_EFFECT);
            }

            void JustSummoned(Creature* summoned) override
            {
                _summons.Summon(summoned);
                // makes immediate corpse despawn of summoned Felflame Infernals
                summoned->SetCorpseDelay(0);
            }

            void JustDied(Unit* /*killer*/) override
            {
                // used to despawn corpse immediately
                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 /*diff*/) override { }

            private:
                SummonList _summons;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_infernal_volcanoAI>(creature);
        }
};

class npc_fel_infernal : public CreatureScript
{
    public:
        npc_fel_infernal() : CreatureScript("npc_fel_infernal") { }

        struct npc_fel_infernalAI : public ScriptedAI
        {
            npc_fel_infernalAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                _scheduler.Schedule(Seconds(2), [this](TaskContext context)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, SPELL_FEL_STREAK_VISUAL);
                    context.Repeat(Seconds(15));
                });
                me->SetInCombatWithZone();
            }

            void UpdateAI(uint32 diff) override
            {
                if (_instance->GetBossState(DATA_JARAXXUS) != IN_PROGRESS)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_fel_infernalAI>(creature);
        }
};

class npc_nether_portal : public CreatureScript
{
    public:
        npc_nether_portal() : CreatureScript("npc_nether_portal") { }

        struct npc_nether_portalAI : public ScriptedAI
        {
            npc_nether_portalAI(Creature* creature) : ScriptedAI(creature), _summons(me) { }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);

                if (!IsHeroic())
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED));
                else
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED));

                _summons.DespawnAll();
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCast(SPELL_NETHER_PORTAL_EFFECT);
            }

            void JustSummoned(Creature* summoned) override
            {
                _summons.Summon(summoned);
                // makes immediate corpse despawn of summoned Mistress of Pain
                summoned->SetCorpseDelay(0);
            }

            void JustDied(Unit* /*killer*/) override
            {
                // used to despawn corpse immediately
                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 /*diff*/) override { }

            private:
                SummonList _summons;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_nether_portalAI>(creature);
        }
};

class npc_mistress_of_pain : public CreatureScript
{
    public:
        npc_mistress_of_pain() : CreatureScript("npc_mistress_of_pain") { }

        struct npc_mistress_of_painAI : public ScriptedAI
        {
            npc_mistress_of_painAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
                _instance->SetData(DATA_MISTRESS_OF_PAIN_COUNT, INCREASE);
            }

            void Reset() override
            {
                _events.ScheduleEvent(EVENT_SHIVAN_SLASH, 30*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_SPINNING_STRIKE, 30*IN_MILLISECONDS);
                if (IsHeroic())
                    _events.ScheduleEvent(EVENT_MISTRESS_KISS, 15*IN_MILLISECONDS);
                me->SetInCombatWithZone();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _instance->SetData(DATA_MISTRESS_OF_PAIN_COUNT, DECREASE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (_instance->GetBossState(DATA_JARAXXUS) != IN_PROGRESS)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

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
                            _events.ScheduleEvent(EVENT_SHIVAN_SLASH, 30*IN_MILLISECONDS);
                            return;
                        case EVENT_SPINNING_STRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_SPINNING_STRIKE);
                            _events.ScheduleEvent(EVENT_SPINNING_STRIKE, 30*IN_MILLISECONDS);
                            return;
                        case EVENT_MISTRESS_KISS:
                            DoCast(me, SPELL_MISTRESS_KISS);
                            _events.ScheduleEvent(EVENT_MISTRESS_KISS, 30*IN_MILLISECONDS);
                            return;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
            private:
                InstanceScript* _instance;
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_mistress_of_painAI>(creature);
        }
};

class spell_mistress_kiss : public SpellScriptLoader
{
    public:
        spell_mistress_kiss() : SpellScriptLoader("spell_mistress_kiss") { }

        class spell_mistress_kiss_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mistress_kiss_AuraScript);

            bool Load() override
            {
                return ValidateSpellInfo({ SPELL_MISTRESS_KISS_DAMAGE_SILENCE });
            }

            void HandleDummyTick(AuraEffect const* /*aurEff*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetTarget();
                if (caster && target)
                {
                    if (target->HasUnitState(UNIT_STATE_CASTING))
                    {
                        caster->CastSpell(target, SPELL_MISTRESS_KISS_DAMAGE_SILENCE, true);
                        target->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mistress_kiss_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mistress_kiss_AuraScript();
        }
};

class MistressKissTargetSelector
{
    public:
        MistressKissTargetSelector() { }

        bool operator()(WorldObject* unit) const
        {
            if (unit->GetTypeId() == TYPEID_PLAYER && unit->ToUnit()->GetPowerType() == POWER_MANA)
                return false;

            return true;
        }
};

class spell_mistress_kiss_area : public SpellScriptLoader
{
    public:
        spell_mistress_kiss_area() : SpellScriptLoader("spell_mistress_kiss_area") { }

        class spell_mistress_kiss_area_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mistress_kiss_area_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                // get a list of players with mana
                targets.remove_if(MistressKissTargetSelector());
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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mistress_kiss_area_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_mistress_kiss_area_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mistress_kiss_area_SpellScript();
        }
};

class spell_fel_streak_visual : public SpellScriptLoader
{
public:
    spell_fel_streak_visual() : SpellScriptLoader("spell_fel_streak_visual") { }

    class spell_fel_streak_visual_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_fel_streak_visual_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_FEL_STREAK });
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_fel_streak_visual_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_fel_streak_visual_SpellScript();
    }
};

void AddSC_boss_jaraxxus()
{
    new boss_jaraxxus();
    new npc_legion_flame();
    new npc_infernal_volcano();
    new npc_fel_infernal();
    new npc_nether_portal();
    new npc_mistress_of_pain();

    new spell_mistress_kiss();
    new spell_mistress_kiss_area();
    new spell_fel_streak_visual();
}
