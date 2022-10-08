/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "ScriptedCreature.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "violet_hold_assault.h"

enum Spells
{
    SPELL_DOOM                  = 201148,
    SPELL_ETERNAL_DARKNESS      = 201153,
    SPELL_HYSTERIA              = 201146,
    SPELL_SHADOW_CRASH          = 201920,
    SPELL_SHADOW_CRASH_VISUAL   = 197783,
    SPELL_SHADOW_CRASH_TRIGGER  = 201120,
    SPELL_SHADOW_CRASH_AURA     = 201121,
    SPELL_SUMMON_TENTACLE       = 201300,
    SPELL_COLLAPSING_SHADOWS    = 201256,
    SPELL_COLLAPSING_SHADOWS_DMG = 201255,

    // Faceless Tendril
    SPELL_ETERNAL_DARKNESS_FACELESS = 201172,
    SPELL_ETERNAL_DARKNESS_BUFF     = 227178,
};

enum Events
{
    EVENT_DOOM              = 1,
    EVENT_HYSTERIA          = 2,
    EVENT_SHADOW_CRASH      = 3,
};

enum Says
{
    SAY_INTRO                       = 0,
    SAY_AGGRO                       = 1,
    SAY_HYSTERIA                    = 2,
    SAY_HYSTERIA_2                  = 3,
    SAY_HYSTERIA_3                  = 4,

    SAY_ETERNAL_DARKNESS            = 5,
    SAY_ETERNAL_DARKNESS_2          = 6,
    SAY_ETERNAL_DARKNESS_3          = 7,
    SAY_KILL                        = 8,
    SAY_WIPE                        = 9,
    SAY_DEATH                       = 10,
    SAY_DEATH_2                     = 11,

    SAY_AGGRO_WHISPER               = 12,
    SAY_KILL_WHISPER                = 13,
    SAY_HYSTERIA_WHISP_1            = 14,
    SAY_HYSTERIA_WHISP_2            = 15,
    SAY_HYSTERIA_WHISP_3            = 16,
    SAY_ETERNAL_DARKNESS_WHISP_1    = 17,
    SAY_ETERNAL_DARKNESS_WHISP_2    = 18,
    SAY_ETERNAL_DARKNESS_WHISP_3    = 19,
    SAY_DEATH_WHISP                 = 20,
    SAY_DEATH_WHISP_2               = 21,
};

class boss_mind_flayer_kaarhj : public CreatureScript
{
    public:
        boss_mind_flayer_kaarhj() : CreatureScript("boss_mind_flayer_kaarhj")
        {
            // Empty
        }

        struct boss_mind_flayer_kaarhj_AI : public BossAI
        {
            boss_mind_flayer_kaarhj_AI(Creature* creature) : BossAI(creature, DATA_MINDFLAYER_KAARHJ)
            {
            }

            void Reset() override
            {
                _firstDarkness = false;
                _secondDarkness = false;
                _Reset();
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                WhisperAll(SAY_AGGRO_WHISPER);
                _EnterCombat();
                events.ScheduleEvent(EVENT_SHADOW_CRASH, urand(3, 5) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_DOOM, 8 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_HYSTERIA, 12 * IN_MILLISECONDS);
            }

            void DamageTaken(Unit* /**/, uint32& /*damage*/) override
            {
                if (me->HealthBelowPct(80) && !_firstDarkness)
                {
                    uint32 talk_id = urand(SAY_ETERNAL_DARKNESS, SAY_ETERNAL_DARKNESS_3);
                    Talk(talk_id);
                    WhisperTalk(talk_id);
                    _firstDarkness = true;
                    DoCast(SPELL_ETERNAL_DARKNESS);
                }
                else if (me->HealthBelowPct(40) && !_secondDarkness)
                {
                    uint32 talk_id = urand(SAY_ETERNAL_DARKNESS, SAY_ETERNAL_DARKNESS_3);
                    Talk(talk_id);
                    WhisperTalk(talk_id);
                    _secondDarkness = true;
                    DoCast(SPELL_ETERNAL_DARKNESS);
                }
            }

            void EnterEvadeMode(EvadeReason /**/) override
            {
                Talk(SAY_WIPE);
                CreatureAI::EnterEvadeMode();
            }

            void KilledUnit(Unit* unit) override
            {
                if (unit && unit->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_KILL);
                    WhisperAll(SAY_KILL_WHISPER);
                }
            }

            void WhisperAll(uint32 id)
            {
                auto & players = me->GetMap()->GetPlayers();

                if (players.isEmpty())
                    return;

                for (auto itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                        Talk(id, player);
                }
            }

            void WhisperTalk(uint32 talk_id)
            {
                switch (talk_id)
                {
                    case SAY_HYSTERIA:
                        WhisperAll(SAY_HYSTERIA_WHISP_1);
                        break;
                    case SAY_HYSTERIA_2:
                        WhisperAll(SAY_HYSTERIA_WHISP_2);
                        break;
                    case SAY_HYSTERIA_3:
                        WhisperAll(SAY_HYSTERIA_WHISP_3);
                        break;
                    case SAY_ETERNAL_DARKNESS:
                        WhisperAll(SAY_ETERNAL_DARKNESS_WHISP_1);
                        break;
                    case SAY_ETERNAL_DARKNESS_2:
                        WhisperAll(SAY_ETERNAL_DARKNESS_WHISP_2);
                        break;
                    case SAY_ETERNAL_DARKNESS_3:
                        WhisperAll(SAY_ETERNAL_DARKNESS_WHISP_3);
                        break;
                    case SAY_DEATH:
                        WhisperAll(SAY_DEATH_WHISP);
                        break;
                    case SAY_DEATH_2:
                        WhisperAll(SAY_DEATH_WHISP_2);
                        break;
                    default : break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                uint32 talk_id = urand(SAY_DEATH, SAY_DEATH_2);
                Talk(talk_id);
                WhisperTalk(talk_id);
                _JustDied();
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
                        case EVENT_SHADOW_CRASH:
                            DoCast(me, SPELL_SHADOW_CRASH);
                            events.ScheduleEvent(EVENT_SHADOW_CRASH, urand(22,24) * IN_MILLISECONDS);
                            break;

                        case EVENT_DOOM:
                            if (Unit* victim = me->GetVictim())
                                DoCast(victim, SPELL_DOOM);
                            events.ScheduleEvent(EVENT_DOOM, urand(18, 20) * IN_MILLISECONDS);
                            break;

                        case EVENT_HYSTERIA:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            {
                                uint32 talk_id = urand(SAY_HYSTERIA, SAY_HYSTERIA_3);
                                Talk(talk_id);
                                WhisperTalk(talk_id);
                                DoCast(target, SPELL_HYSTERIA);
                            }
                            events.ScheduleEvent(EVENT_HYSTERIA, 15 * IN_MILLISECONDS);
                            break;

                    default:
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                bool _firstDarkness, _secondDarkness;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_mind_flayer_kaarhj_AI(creature);
        }
};

class npc_faceless_tendril : public CreatureScript
{
    public:
        npc_faceless_tendril() : CreatureScript("npc_faceless_tendril")
        {}

        struct npc_faceless_tendril_AI : public ScriptedAI
        {
            npc_faceless_tendril_AI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset() override
            {
                me->setActive(true);
                me->SetReactState(REACT_AGGRESSIVE);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (Creature* kaarhj = me->FindNearestCreature(101950, 250.0f, true))
                {
                    if (Unit* target = kaarhj->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_ETERNAL_DARKNESS_FACELESS);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_faceless_tendril_AI(creature);
        }
};

class spell_shadow_crash : public SpellScriptLoader
{
    public:
        spell_shadow_crash() : SpellScriptLoader("spell_shadow_crash")
        {

        }

        class spell_shadow_crash_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_shadow_crash_SpellScript);

                void HandleDummy()
                {
                    if (!GetCaster())
                        return;

                    for (auto & it : targetsList)
                        GetCaster()->CastSpell(it, SPELL_SHADOW_CRASH_VISUAL, true);
                }

                void FilterTargets(std::list<WorldObject*>& targets)
                {
                    if (targets.empty())
                        return;

                    targets.remove_if([] (WorldObject* target)
                    {
                        if (target && target->ToPlayer())
                            return false;

                        return true;
                    });

                    for (auto & it : targets)
                        if (it && it->ToUnit())
                            targetsList.push_back(it->ToUnit());
                }

                void Register()
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shadow_crash_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                    OnCast += SpellCastFn(spell_shadow_crash_SpellScript::HandleDummy);
                }

                private:
                    std::list<Unit*> targetsList;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_shadow_crash_SpellScript();
        }
};


class spell_eternal_darkness : public SpellScriptLoader
{
    public:

        spell_eternal_darkness() : SpellScriptLoader("spell_eternal_darkness")
        {}

        class spell_eternal_darkness_AuraScript : public AuraScript
        {
            public:

                PrepareAuraScript(spell_eternal_darkness_AuraScript);

                void HandleSummons(AuraEffect const* /*aurEff*/)
                {
                    if (!GetCaster())
                        return;

                    GetCaster()->CastSpell(GetCaster(), SPELL_SUMMON_TENTACLE, true);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_eternal_darkness_AuraScript::HandleSummons, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_eternal_darkness_AuraScript();
        }
};

class spell_eternal_darkness_dmg : public SpellScriptLoader
{
    public:
        spell_eternal_darkness_dmg() : SpellScriptLoader("spell_eternal_darkness_dmg")
        {}

        class spell_eternal_darkness_dmg_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_eternal_darkness_dmg_AuraScript);

                void HandleStacks(AuraEffect const* /**/)
                {
                    if (!GetCaster())
                        return;

                    GetCaster()->CastSpell(GetCaster(), SPELL_ETERNAL_DARKNESS_BUFF, true);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_eternal_darkness_dmg_AuraScript::HandleStacks, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_eternal_darkness_dmg_AuraScript();
        }
};

class at_shadow_crash : public AreaTriggerEntityScript
{
    public:
        at_shadow_crash() : AreaTriggerEntityScript("at_shadow_crash")
        {}

        struct at_shadow_crash_AI : public AreaTriggerAI
        {
            at_shadow_crash_AI(AreaTrigger* area) : AreaTriggerAI(area)
            {

            }

            void OnUnitEnter(Unit* unit) override
            {
                if (unit && unit->GetTypeId() == TYPEID_PLAYER)
                    unit->CastSpell(unit, SPELL_SHADOW_CRASH_AURA, true);
            }

            void OnUnitExit(Unit* unit) override
            {
                if (unit)
                    unit->RemoveAurasDueToSpell(SPELL_SHADOW_CRASH_AURA);
            }

            void OnRemove() override
            {
                if (Unit* kaahrj = at->FindNearestCreature(101950, 250.0f, true))
                {
                    if (kaahrj->GetMap()->IsHeroic())
                        kaahrj->CastSpell(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), SPELL_COLLAPSING_SHADOWS, true);
                }
            }

        };

        AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
        {
            return new at_shadow_crash_AI(areatrigger);
        }

};

class at_collapsing_shadow : public AreaTriggerEntityScript
{
    public:
        at_collapsing_shadow() : AreaTriggerEntityScript("at_collapsing_shadow")
        {

        }

        struct at_collapsing_shadow_AI : public AreaTriggerAI
        {
            at_collapsing_shadow_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {

            }

            void OnUnitEnter(Unit* unit) override
            {
                if (unit && unit->GetTypeId() == TYPEID_PLAYER)
                    unit->CastSpell(unit, SPELL_COLLAPSING_SHADOWS_DMG, true);
            }

            void OnUnitExit(Unit* unit) override
            {
                if (unit)
                    unit->RemoveAurasDueToSpell(SPELL_COLLAPSING_SHADOWS_DMG);
            }

        };

        AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
        {
            return new at_collapsing_shadow_AI(areatrigger);
        }
};


void AddSC_boss_mind_flayer_kaarhj()
{
    new npc_faceless_tendril();
    new boss_mind_flayer_kaarhj();
    new spell_shadow_crash();
    new spell_eternal_darkness();
    new spell_eternal_darkness_dmg();
    new at_shadow_crash();
    new at_collapsing_shadow();
}
