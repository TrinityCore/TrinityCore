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
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "violet_hold_assault.h"

enum Spells
{
    SPELL_BLOOD_SWARN                    = 202659,
    SPELL_BLOOD_SWARN_DMG                = 202785,
    SPELL_BLOOD_SWARN_AREA               = 202947,
    SPELL_VAMPIRIC_KISS                  = 202676,
    SPELL_VAMPIRIC_KISS_DMG              = 202766,
    SPELL_VAMPIRIC_KISS_PLAYER           = 202805,
    SPELL_UNCONTROLLABLE_FRENZY          = 202804,
    SPELL_FRENZIED_BLOODTHIRST           = 202779,
    SPELL_BLOOD_CALL                     = 203381,
    SPELL_BLOOD_CALL_DUMMY               = 203405,
    SPELL_BLOOD_CALL_SUMMON              = 203452,
    SPELL_SHROUD_OF_SORROW               = 203033,
    SPELL_SHROUD_OF_SORROW_DMG           = 203057,
    SPELL_ESSENCE_OF_BLOOD_PRINCESS      = 202779,
    SPELL_ESSENCE_OF_BLOOD_PRINCESS_PLYR = 202781,
    SPELL_ETERNAL_HUNGER                 = 203462,
};

enum Events
{
    EVENT_VAMPIRIC_KISS     = 1,
    EVENT_BLOOD_SWARN       = 2,
    EVENT_BLOOD_CALL        = 3,

    EVENT_CHECK_DISTANCE    = 4,
    EVENT_FOLLOW_SUMMONER   = 5,
};

enum Adds
{
    NPC_CONGEALED_BLOOD = 102941,
    NPC_THALENA_DUMMY   = 102659,
};

enum Says
{
    SAY_AGGRO           = 0,
    SAY_KISS            = 1,
    SAY_UNCONTROLLABLE  = 2,
    SAY_KILL            = 3,
    SAY_DEATH           = 4,
};


class boss_blood_princess_thalena : public CreatureScript
{
    public:
        boss_blood_princess_thalena() : CreatureScript("boss_blood_princess_thalena")
        {}

        struct boss_blood_princess_thalena_AI : public BossAI
        {
            boss_blood_princess_thalena_AI(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCESS)
            {}

            void Reset() override
            {
                _Reset();
            }

            void EnterCombat(Unit* /**/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                DoCast(me, SPELL_SHROUD_OF_SORROW, true);
                events.ScheduleEvent(EVENT_VAMPIRIC_KISS, Seconds(15));
                events.ScheduleEvent(EVENT_BLOOD_SWARN, Seconds(20));

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_BLOOD_CALL, Seconds(30));
            }

            void EnterEvadeMode(EvadeReason reason) override
            {
                me->RemoveAllAreaTriggers();
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ESSENCE_OF_BLOOD_PRINCESS);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ESSENCE_OF_BLOOD_PRINCESS_PLYR);
                CreatureAI::EnterEvadeMode(reason);
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_VAMPIRIC_KISS:
                    {
                        Talk(SAY_KISS);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, HealerSelector(me, true)))
                            DoCast(target, SPELL_VAMPIRIC_KISS);
                        else
                            DoCastVictim(SPELL_VAMPIRIC_KISS);
                        break;
                    }

                    case EVENT_BLOOD_CALL:
                    {
                        DoCast(me, SPELL_BLOOD_CALL);
                        events.ScheduleEvent(EVENT_BLOOD_CALL, Seconds(30));
                        break;
                    }

                    case EVENT_BLOOD_SWARN:
                    {
                        DoCast(me, SPELL_BLOOD_SWARN);
                        events.ScheduleEvent(EVENT_BLOOD_SWARN, Seconds(20));
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_blood_princess_thalena_AI(creature);
        }
};

class npc_vha_congealing_blood : public CreatureScript
{
    public:
        npc_vha_congealing_blood() : CreatureScript("npc_vha_congealing_blood")
        {}

        struct npc_vha_congealing_blood_AI : public ScriptedAI
        {
            npc_vha_congealing_blood_AI(Creature* creature) : ScriptedAI(creature)
            {
                _princess = nullptr;
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (!summoner)
                    return;

                _princess = me->FindNearestCreature(BOSS_BLOOD_PRINCESS, 500.f);

                if (_princess)
                {

                    me->GetMotionMaster()->MoveFollow(_princess, 0, 0);
                    _events.ScheduleEvent(EVENT_CHECK_DISTANCE, Seconds(1));
                    _events.ScheduleEvent(EVENT_FOLLOW_SUMMONER, Seconds(5));
                }
            }

            void CheckDistance()
            {
                if (!_princess)
                    return;

                if (me->IsWithinDist(_princess, 3.f))
                {
                    _events.Reset();
                    _princess->CastSpell(_princess, SPELL_ETERNAL_HUNGER, true);
                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    if (eventId == EVENT_CHECK_DISTANCE)
                    {
                        CheckDistance();
                        _events.ScheduleEvent(EVENT_CHECK_DISTANCE, Seconds(1));
                    }
                    else if (eventId == EVENT_FOLLOW_SUMMONER)
                    {
                        if (_princess)
                            me->GetMotionMaster()->MoveFollow(_princess, 0, 0);
                        _events.ScheduleEvent(EVENT_FOLLOW_SUMMONER, Seconds(5));
                    }
                }
            }

            private:
                EventMap _events;
                Creature* _princess;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_congealing_blood_AI(creature);
        }
};

class spell_thalena_vampiric_kiss : public SpellScriptLoader
{
    public:
        spell_thalena_vampiric_kiss() : SpellScriptLoader("spell_thalena_vampiric_kiss")
        {}

        class spell_vampiric_kiss_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_vampiric_kiss_SpellScript);

                void HandleHit(SpellEffIndex)
                {
                    if (!GetHitUnit() || !GetCaster())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_VAMPIRIC_KISS_DMG, true);
                }

                void Register()
                {
                    OnEffectHitTarget += SpellEffectFn(spell_vampiric_kiss_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_vampiric_kiss_SpellScript();
        }
};

class spell_thalena_vampiric_kiss_player : public SpellScriptLoader
{
    public:
        spell_thalena_vampiric_kiss_player() : SpellScriptLoader("spell_thalena_vampiric_kiss_player")
        {}

        class spell_vampiric_kiss_player_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_vampiric_kiss_player_SpellScript);

            SpellCastResult HandleCheckCast()
            {
                if (!GetExplTargetUnit())
                    return SPELL_FAILED_NO_VALID_TARGETS;

                if (GetExplTargetUnit()->HasAura(SPELL_ESSENCE_OF_BLOOD_PRINCESS))
                    return SPELL_FAILED_BAD_TARGETS;

                if (GetExplTargetUnit()->GetGUID() == GetCaster()->GetGUID())
                    return SPELL_FAILED_BAD_TARGETS;

                return SPELL_FAILED_SUCCESS;
            }

            void HandleOnHit()
            {
                if (!GetCaster())
                    return;

                GetCaster()->RemoveAurasDueToSpell(SPELL_FRENZIED_BLOODTHIRST);
                GetCaster()->CastSpell(GetCaster(), SPELL_ESSENCE_OF_BLOOD_PRINCESS, true);
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_vampiric_kiss_player_SpellScript::HandleCheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_vampiric_kiss_player_SpellScript();
        }
};

class spell_thalena_blood_call : public SpellScriptLoader
{
    public:
        spell_thalena_blood_call() : SpellScriptLoader("spell_thalena_blood_call")
        {}

        class spell_blood_call_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_blood_call_SpellScript);

                void HandleDummy(SpellEffIndex)
                {
                    if (!GetCaster() || !GetHitUnit())
                        return;

                    std::list<Creature*> pools;
                    GetCaster()->GetCreatureListWithEntryInGrid(pools, NPC_THALENA_DUMMY);

                    if (!pools.empty())
                    {
                        for (auto & it : pools)
                            it->CastSpell(it, SPELL_BLOOD_CALL_DUMMY, true);
                    }
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_blood_call_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_blood_call_SpellScript();
        }
};

class spell_thalena_blood_swarn : public SpellScriptLoader
{
    public:
        spell_thalena_blood_swarn() : SpellScriptLoader("spell_thalena_blood_swarn")
        {}

        class spell_blood_swarn_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_blood_swarn_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitUnit() || !GetCaster())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_BLOOD_SWARN_DMG, true);
                }

                void Register()
                {
                    OnEffectHitTarget += SpellEffectFn(spell_blood_swarn_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_blood_swarn_SpellScript();
        }
};

class spell_thalena_frenzied_bloodthirst : public SpellScriptLoader
{
    public:
        spell_thalena_frenzied_bloodthirst() : SpellScriptLoader("spell_thalena_frenzied_bloodthirst")
        {}

        class spell_uncontrollable_frenzy_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_uncontrollable_frenzy_AuraScript);

                void HandleOnRemove(AuraEffect const*, AuraEffectHandleModes /**/)
                {
                    if (!GetUnitOwner() || !GetCaster())
                        return;

                    Unit* owner = GetUnitOwner();

                    if (!owner->HasAura(SPELL_ESSENCE_OF_BLOOD_PRINCESS))
                    {
                        if (Creature* princess = owner->FindNearestCreature(BOSS_BLOOD_PRINCESS, 500.f))
                        {
                            princess->AI()->Talk(SAY_UNCONTROLLABLE);
                            princess->CastSpell(owner, SPELL_UNCONTROLLABLE_FRENZY, true);
                        }
                    }
                }

                void Register()
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_uncontrollable_frenzy_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_uncontrollable_frenzy_AuraScript();
        }
};

class at_vha_blood_swarn : public AreaTriggerEntityScript
{
    public:
        at_vha_blood_swarn() : AreaTriggerEntityScript("at_vha_blood_swarn")
        {}

        struct at_vha_blood_swarn_AI : public AreaTriggerAI
        {
            at_vha_blood_swarn_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void OnUnitEnter(Unit* unit) override
            {
                if (!unit)
                    return;

                if (unit->GetTypeId() == TYPEID_PLAYER)
                    unit->CastSpell(unit, SPELL_BLOOD_SWARN_AREA, true);
            }

            void OnUnitExit(Unit* unit) override
            {
                if (!unit)
                    return;

                if (unit->GetTypeId() == TYPEID_PLAYER)
                    unit->RemoveAurasDueToSpell(SPELL_BLOOD_SWARN_AREA);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_vha_blood_swarn_AI(at);
        }
};

void AddSC_boss_blood_princess_thalena()
{
    new boss_blood_princess_thalena();
    new npc_vha_congealing_blood();
    new spell_thalena_blood_swarn();
    new spell_thalena_frenzied_bloodthirst();
    new spell_thalena_vampiric_kiss();
    new spell_thalena_vampiric_kiss_player();
    new spell_thalena_blood_call();
    new at_vha_blood_swarn();
}
