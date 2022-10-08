/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "karazhan_legion.h"
#include "AreaTrigger.h"
#include <G3D/Vector3.h>
#include <G3D/Triangle.h>
#include <G3D/Plane.h>
#include <G3D/CollisionDetection.h>

enum Spells
{
    // Moroes
    SPELL_VANISH                            = 227736,
    SPELL_GARROTE                           = 227742,
    SPELL_COAT_CHECK                        = 227832,
    SPELL_GHASTLY_PURGE                     = 227872,

    // Keira Berrybuck
    SPELL_EMPOWERED_ARMS                    = 227616,

    // Robin Daris
    SPELL_WHIRLING_EDGE                     = 227463,
    SPELL_WHIRLING_EDGE_AREA                = 227472,
    SPELL_WHIRLING_EDGE_DMG                 = 227473,

    //Rafe Dreuger
    SPELL_IRON_WHIRLWIND                    = 227646,

    // Crispin Ference
    SPELL_WILL_BREAKER                      = 227672,

    // Dorothea Millstipe
    SPELL_ARCANE_BLAST                      = 227575,
    SPELL_MANA_DRAIN                        = 227545,

    //Catrona Von'Indi
    SPELL_SMITE                             = 227452,
    SPELL_HEALING_STREAM                    = 227578,
    SPELL_GHOSTLY_TRAP                      = 227909
};

enum Events
{
    // Moroes
    EVENT_GARROTE                           = 1,
    EVENT_COAT_CHECK                        = 2,
    EVENT_GHASTLY_PURGE                     = 3,

    // Keira Berrybuck
    EVENT_EMPOWERED_ARMS                    = 1,

    // Robin Daris
    EVENT_WHIRLING_EDGE                     = 2,

    // Rafe Dreuger
    EVENT_IRON_WHIRLWIND                    = 3,

    // Crispin Ference
    EVENT_WILL_BREAKER                      = 4,

    // Dorothea Millstipe
    EVENT_ARCANE_BLAST                      = 5,
    EVENT_MANA_DRAIN                        = 6,

    // Catriona Von'Indi
    EVENT_SMITE                             = 7,
    EVENT_HEALING_STREAM                    = 8
};

enum Says
{
    SAY_INTRO                               = 0,
    SAY_AGGRO                               = 1,
    SAY_COAT                                = 2,
    SAY_VANISH                              = 3,
    SAY_GHASTLY                             = 4,
    SAY_KILL                                = 5,
    SAY_WIPE                                = 6,
    SAY_DEATH                               = 7
};

enum Adds
{
    NPC_KEIRA_BERRYBUCK                     = 114319,
    NPC_ROBIN_DARRIS                        = 114320,
    NPC_RAFE_DREUGER                        = 114318,
    NPC_CRISPIN_FERENCE                     = 114321,
    NPC_DOROTHEA_MILLSTIPE                  = 114316,
    NPC_CATRIONA_VONINDI                    = 114317
};

uint32 DinnerGuests[] =
{
    NPC_KEIRA_BERRYBUCK,
    NPC_ROBIN_DARRIS,
    NPC_RAFE_DREUGER,
    NPC_CRISPIN_FERENCE,
    NPC_DOROTHEA_MILLSTIPE,
    NPC_CATRIONA_VONINDI
};

constexpr uint32 NPC_WHIRLING_EDGE          = 114327;

Position const GuestSummonPosition[] =
{
    { -10976.33f, -1879.969f, 81.8118f, 3.1953f },
    { -10988.88f, -1878.576f, 81.8118f, 0.0473f },
    { -10986.42f, -1876.755f, 81.81189f, 4.263f },
    { -10978.35f, -1877.719f, 81.81189f, 4.872f }
};

class boss_new_moroes : public CreatureScript
{
    public:
        boss_new_moroes() : CreatureScript("boss_new_moroes") { }

        struct boss_new_moroes_AI : public BossAI
        {
            explicit boss_new_moroes_AI(Creature* creature) : BossAI(creature, DATA_MOROES)
            {
                _IsPurged = false;
                Trinity::Containers::RandomShuffle(DinnerGuests);
                ChoseGuests();
            }

            void DamageTaken(Unit* /**/, uint32 & damage) override
            {
                if (me->HealthBelowPct(60) && !_IsPurged)
                {
                    Talk(SAY_GHASTLY);
                    _IsPurged = true;
                    events.ScheduleEvent(EVENT_GHASTLY_PURGE, 100ms);
                }
            }

            void Reset() override
            {
                _Reset();
            }

            void ChoseGuests()
            {
                summons.DespawnAll();
                for (uint8 i = 0; i < 4; ++i)
                    me->SummonCreature(DinnerGuests[i], GuestSummonPosition[i], TEMPSUMMON_CORPSE_DESPAWN, 5000);
            }

            void JustReachedHome() override
            {
                Talk(SAY_WIPE);
                _JustReachedHome();
                ChoseGuests();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                BossAI::EnterEvadeMode(why);
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                _IsPurged = false;
                _EnterCombat();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_GARROTE, 8s);
                events.ScheduleEvent(EVENT_COAT_CHECK, 30s);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_GHASTLY_PURGE:
                    {
                        DoCast(me, SPELL_GHASTLY_PURGE, true);
                        break;
                    }

                    case EVENT_GARROTE:
                    {
                        if (roll_chance_i(33))
                            Talk(SAY_VANISH);

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_VANISH);

                        events.ScheduleEvent(EVENT_GARROTE, 15s);
                        break;
                    }

                    case EVENT_COAT_CHECK:
                    {
                        DoCastVictim(SPELL_COAT_CHECK);
                        events.ScheduleEvent(EVENT_COAT_CHECK, 30s);
                        break;
                    }
                }
            }

            private:
                bool _IsPurged;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_new_moroes_AI(creature);
        }
};

class npc_kara_moroes_guest : public CreatureScript
{
    public:
        npc_kara_moroes_guest() : CreatureScript("npc_kara_moroes_guest") { }

        struct npc_kara_moroes_guest_AI : public ScriptedAI
        {
            public:
                explicit npc_kara_moroes_guest_AI(Creature* creature) : ScriptedAI(creature), _summons(me) { }

                void Reset()
                {
                    _summons.DespawnAll();
                    me->RemoveAllAreaTriggers();
                    _events.Reset();
                }

                void JustDied(Unit* /**/) override
                {
                    _summons.DespawnAll();
                    me->RemoveAllAreaTriggers();
                    _events.Reset();

                    InstanceScript* instance = me->GetInstanceScript();

                    if (instance)
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                }

                void EnterEvadeMode(EvadeReason why) override
                {
                    me->RemoveAllAreaTriggers();

                    InstanceScript* instance = me->GetInstanceScript();

                    if (instance)
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                    CreatureAI::EnterEvadeMode(why);
                }

                void EnterCombat(Unit* /**/) override
                {
                    InstanceScript* instance = me->GetInstanceScript();

                    if (instance)
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                    DoZoneInCombat();
                    ScheduleTasks();
                }

                void ScheduleTasks()
                {
                    switch (me->GetEntry())
                    {
                        case NPC_KEIRA_BERRYBUCK:
                        {
                            _events.ScheduleEvent(EVENT_EMPOWERED_ARMS, 15s);
                            break;
                        }

                        case NPC_ROBIN_DARRIS:
                        {
                            _events.ScheduleEvent(EVENT_WHIRLING_EDGE, 2s);
                            break;
                        }

                        case NPC_CATRIONA_VONINDI:
                        {
                            _events.ScheduleEvent(EVENT_SMITE, 5s);
                            _events.ScheduleEvent(EVENT_HEALING_STREAM, 15s);
                            break;
                        }

                        case NPC_DOROTHEA_MILLSTIPE:
                        {
                            _events.ScheduleEvent(EVENT_ARCANE_BLAST, 5s);
                            _events.ScheduleEvent(EVENT_MANA_DRAIN, 15s);
                        }

                        case NPC_RAFE_DREUGER:
                        {
                            _events.ScheduleEvent(EVENT_IRON_WHIRLWIND, 10s);
                            break;
                        }

                        case NPC_CRISPIN_FERENCE:
                        {
                            _events.ScheduleEvent(EVENT_WILL_BREAKER, 15s);
                            break;
                        }
                    }
                }

                void ExecuteEvent(uint32 eventId)
                {
                    switch (eventId)
                    {
                        case EVENT_EMPOWERED_ARMS:
                        {
                            if (Creature* moroes = me->FindNearestCreature(BOSS_MOROES, 500.f))
                                DoCast(moroes, SPELL_EMPOWERED_ARMS);
                            _events.ScheduleEvent(EVENT_EMPOWERED_ARMS, 30s);
                            break;
                        }

                        case EVENT_WHIRLING_EDGE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                                DoCast(target, SPELL_WHIRLING_EDGE);
                            _events.ScheduleEvent(EVENT_WHIRLING_EDGE, 15s);
                            break;
                        }

                        case EVENT_SMITE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                                DoCast(target, SPELL_SMITE);

                            _events.ScheduleEvent(EVENT_SMITE, 5s);
                            break;
                        }

                        case EVENT_HEALING_STREAM:
                        {
                            if (Creature* moroes = me->FindNearestCreature(BOSS_MOROES, 500.f))
                                DoCast(moroes, SPELL_HEALING_STREAM);

                            _events.ScheduleEvent(EVENT_HEALING_STREAM, 15s);
                            break;
                        }

                        case EVENT_MANA_DRAIN:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                                DoCast(target, SPELL_MANA_DRAIN);

                            _events.ScheduleEvent(EVENT_MANA_DRAIN, 15s);
                            break;
                        }

                        case EVENT_ARCANE_BLAST:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                                DoCast(target, SPELL_ARCANE_BLAST);

                            _events.ScheduleEvent(EVENT_ARCANE_BLAST, 5s);
                            break;
                        }

                        case EVENT_IRON_WHIRLWIND:
                        {
                            DoCast(me, SPELL_IRON_WHIRLWIND);
                            _events.ScheduleEvent(EVENT_IRON_WHIRLWIND, 15s);
                            break;
                        }

                        case EVENT_WILL_BREAKER:
                        {
                            DoCastVictim(SPELL_WILL_BREAKER);
                            _events.ScheduleEvent(EVENT_WILL_BREAKER, 30s);
                            break;
                        }
                    }
                }

                void JustSummoned(Creature* summon) override
                {
                    if (!summon)
                        return;

                    _summons.Summon(summon);
                }

                void UpdateAI(uint32 diff) override
                {
                    if (me->HasAura(SPELL_GHOSTLY_TRAP))
                        return;

                    if (!UpdateVictim())
                        return;

                    _events.Update(diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    while (uint32 eventId = _events.ExecuteEvent())
                        ExecuteEvent(eventId);

                    DoMeleeAttackIfReady();
                }

                private:
                    SummonList _summons;
                    EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_moroes_guest_AI(creature);
        }
};

class spell_kara_will_breaker : public SpellScriptLoader
{
    public:
        spell_kara_will_breaker() : SpellScriptLoader("spell_kara_will_breaker") { }

        class spell_will_breaker_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_will_breaker_SpellScript);

                void FilterTargets(SpellTargets & targets)
                {
                    if (targets.empty())
                        return;

                    Unit* caster = GetCaster();

                    float radius = 100.0f;

                    G3D::Vector2 v1, v2, v3;

                    v1.x = caster->GetPositionX();
                    v1.y = caster->GetPositionY();

                    v2.x = caster->GetPositionX() + (radius * cosf(caster->GetOrientation()));
                    v2.y = caster->GetPositionY() + (radius * sinf(caster->GetOrientation()));

                    v3 = v2 - v1;


                    targets.remove_if([&] (WorldObject* target)
                    {
                        G3D::Vector2 v4 = { target->GetPositionX() - caster->GetPositionX(), target->GetPositionY() - caster->GetPositionY() };

                        float angle = (v3.dot(v4) / (v3.length() * v4.length()));

                        angle = std::acos(angle);

                        float dist = v4.length() * sinf(angle);

                        if (dist > 8.0f)
                            return true;

                        return false;
                    });
                }

                void Register() override
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_will_breaker_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_104);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_will_breaker_SpellScript();
        }
};

class spell_moroes_ghastly_purge : public SpellScriptLoader
{
    public:
        spell_moroes_ghastly_purge() : SpellScriptLoader("spell_moroes_ghastly_purge") { }

        class spell_ghastly_purge_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_ghastly_purge_SpellScript);

                void FilterTargets(SpellTargets & targets)
                {
                    if (targets.empty())
                        return;

                    targets.remove_if([] (WorldObject*& target)
                    {
                        switch (target->GetEntry())
                        {
                            case NPC_KEIRA_BERRYBUCK:
                            case NPC_ROBIN_DARRIS:
                            case NPC_RAFE_DREUGER:
                            case NPC_CRISPIN_FERENCE:
                            case NPC_DOROTHEA_MILLSTIPE:
                            case NPC_CATRIONA_VONINDI:
                                return false;

                            default:
                                return true;
                        }
                    });
                }

                void Register() override
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ghastly_purge_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ghastly_purge_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ghastly_purge_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ghastly_purge_SpellScript::FilterTargets, EFFECT_3, TARGET_UNIT_SRC_AREA_ENTRY);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ghastly_purge_SpellScript::FilterTargets, EFFECT_4, TARGET_UNIT_SRC_AREA_ENTRY);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ghastly_purge_SpellScript::FilterTargets, EFFECT_5, TARGET_UNIT_SRC_AREA_ENTRY);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ghastly_purge_SpellScript::FilterTargets, EFFECT_6, TARGET_UNIT_SRC_AREA_ENTRY);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ghastly_purge_SpellScript::FilterTargets, EFFECT_7, TARGET_UNIT_SRC_AREA_ENTRY);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ghastly_purge_SpellScript::FilterTargets, EFFECT_8, TARGET_UNIT_SRC_AREA_ENTRY);
                }

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ghastly_purge_SpellScript();
        }
};

class spell_moroes_vanish : public SpellScriptLoader
{
    public:
        spell_moroes_vanish() : SpellScriptLoader("spell_moroes_vanish") { }

        class spell_vanish_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_vanish_SpellScript);

                void HandleHit(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_GARROTE, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_vanish_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_vanish_SpellScript();
        }
};

class at_kara_whirling_edge : public AreaTriggerEntityScript
{
    public:
        at_kara_whirling_edge() : AreaTriggerEntityScript("at_kara_whirling_edge") { }

        class at_kara_whirling_edge_AI : public AreaTriggerAI
        {
            public:
                explicit at_kara_whirling_edge_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

                void OnUnitEnter(Unit* target) override
                {
                    if (!target)
                        return;

                    if (target->GetTypeId() == TYPEID_PLAYER)
                        at->GetCaster()->CastSpell(target, SPELL_WHIRLING_EDGE_DMG, true);
                }

                void OnUnitExit(Unit* target) override
                {
                    if (!target)
                        return;

                    if (target->GetTypeId() == TYPEID_PLAYER)
                        target->RemoveAurasDueToSpell(SPELL_WHIRLING_EDGE_DMG);
                }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_whirling_edge_AI(at);
        }
};

void AddSC_boss_moroes_karazhan_legion()
{
    new boss_new_moroes();
    new npc_kara_moroes_guest();
    new spell_moroes_vanish();
    new spell_moroes_ghastly_purge();
    new spell_kara_will_breaker();
    new at_kara_whirling_edge();
}
