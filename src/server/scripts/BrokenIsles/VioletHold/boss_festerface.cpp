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
    // Festerface
    SPELL_CONGEALING_VOMIT          = 201598,
    SPELL_CONGEALING_VOMIT_SUMMON   = 201569,
    SPELL_YUM                       = 201715,
    SPELL_UH_OH                     = 201729,

    // Congealing Goo
    SPELL_FETID_STENCH              = 201476,
    SPELL_ICKY_GOO                  = 202266,
    SPELL_RECONGEALING              = 201495,

    // Black Bile
    SPELL_NECROTIC_AURA             = 201753,
};

enum Events
{
    EVENT_CONGEALING_VOMIT   = 1,
    EVENT_CHECK_NEAR_GOO     = 2,
    EVENT_REGEN_ENERGY       = 3,

    EVENT_FETID_STENCH       = 4,
};

enum Adds
{
    NPC_BLACK_BILE      = 102169,
    NPC_CONGEALING_GOO  = 102158,
};

enum Says
{
    SAY_AGGRO               = 0,
    SAY_CONGEALING          = 1,
    SAY_YUM                 = 2,
    SAY_KILL                = 3,
    SAY_DEATH               = 4,
    SAY_CONGEALING_WARN     = 5,

    SAY_RECONGEALING_WARN   = 0,
};

class boss_festerface : public CreatureScript
{
    public:

        boss_festerface() : CreatureScript("boss_festerface")
        {}

        struct boss_festerface_AI : public BossAI
        {
            boss_festerface_AI(Creature* creature) : BossAI(creature, DATA_FESTERFACE)
            {}

            void Reset() override
            {
                _Reset();
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                events.ScheduleEvent(EVENT_CONGEALING_VOMIT, Seconds(10));
                events.ScheduleEvent(EVENT_CHECK_NEAR_GOO, Seconds(12));

                if (IsHeroic())
                {
                    me->SetMaxPower(POWER_ENERGY, 100);
                    events.ScheduleEvent(EVENT_REGEN_ENERGY, Seconds(1));
                }
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void EnterEvadeMode(EvadeReason reason) override
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NECROTIC_AURA);
                CreatureAI::EnterEvadeMode(reason);
            }

            void JustSummoned(Creature* summon) override
            {
                if (!summon)
                    return;

                if (summon->GetEntry() == NPC_BLACK_BILE)
                {
                    instance->DoCastSpellOnPlayers(SPELL_NECROTIC_AURA);
                    summon->AddUnitState(UNIT_STATE_ROOT);
                }

                BossAI::JustSummoned(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                if (!summon)
                    return;

                BossAI::SummonedCreatureDespawn(summon);

                if (summon->GetEntry() == NPC_CONGEALING_GOO && IsHeroic())
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 20);
            }

            void SummonedCreatureDies(Creature* summon, Unit* /**/) override
            {
                if (!summon)
                    return;

                if (summon->GetEntry() == NPC_BLACK_BILE)
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NECROTIC_AURA);
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
                    case EVENT_REGEN_ENERGY:
                    {
                        if (me->GetPower(POWER_ENERGY) >= 100)
                            DoCast(me, SPELL_UH_OH);
                        else
                            me->ModifyPower(POWER_ENERGY, 2);

                        events.ScheduleEvent(EVENT_REGEN_ENERGY, Seconds(1));
                        break;
                    }

                    case EVENT_CONGEALING_VOMIT:
                    {
                        Talk(SAY_CONGEALING_WARN);
                        Talk(SAY_CONGEALING);
                        Creature* portalIntro = me->FindNearestCreature(NPC_TELETRANSPORTATION_PORTAL, 500.f, true);

                        if (portalIntro)
                        {
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->StopMoving();
                            me->SetFacingToObject(portalIntro);
                            DoCast(me, SPELL_CONGEALING_VOMIT);

                        }

                        events.ScheduleEvent(EVENT_CONGEALING_VOMIT, Seconds(50));
                        break;
                    }

                    case EVENT_CHECK_NEAR_GOO:
                    {
                        Creature* goo = me->FindNearestCreature(NPC_CONGEALING_GOO, 5.f, true);

                        if (goo && goo->HasAura(SPELL_RECONGEALING))
                        {
                            Talk(SAY_YUM);
                            DoCast(goo, SPELL_YUM);
                            goo->DespawnOrUnsummon(3000);
                        }

                        events.ScheduleEvent(EVENT_CHECK_NEAR_GOO, Seconds(2));
                    }

                    default : break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_festerface_AI(creature);
        }
};

class npc_vha_congealing_goo : public CreatureScript
{
    public:
        npc_vha_congealing_goo() : CreatureScript("npc_vha_congealing_goo")
        {}

        struct npc_vha_congealing_goo_AI : public ScriptedAI
        {
            npc_vha_congealing_goo_AI(Creature* creature) : ScriptedAI(creature)
            {
                me->AddUnitState(UNIT_STATE_ROOT);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCast(me, SPELL_FETID_STENCH, true);
            }

            void DamageTaken(Unit* /**/, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(5, damage))
                {
                    damage = 0;
                    me->RemoveAllAuras();
                    me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetHealth(1);
                    Talk(SAY_RECONGEALING_WARN);
                    DoCast(me, SPELL_RECONGEALING);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_congealing_goo_AI(creature);
        }
};

class at_vha_icky_goo : public AreaTriggerEntityScript
{
    public:
        at_vha_icky_goo() : AreaTriggerEntityScript("at_vha_icky_goo")
        {}

        struct at_vha_icky_goo_AI : public AreaTriggerAI
        {
            at_vha_icky_goo_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void OnUnitEnter(Unit* unit) override
            {
                if (!unit)
                    return;

                if (unit->GetTypeId() == TYPEID_PLAYER)
                {
                    unit->CastSpell(unit, SPELL_ICKY_GOO, true);
                }
            }

            void OnUnitExit(Unit* unit) override
            {
                if (!unit)
                    return;

                if (unit->GetTypeId() == TYPEID_PLAYER)
                    unit->RemoveAurasDueToSpell(SPELL_ICKY_GOO);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_vha_icky_goo_AI(at);
        }
};

class spell_festerface_congealing_vomit : public SpellScriptLoader
{
    public:
        spell_festerface_congealing_vomit() : SpellScriptLoader("spell_festerface_congealing_vomit")
        {}

        class spell_congealing_vomit_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_congealing_vomit_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetCaster())
                        return;

                    uint32 summonCount = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints;
                    float dist = 5.f;

                    for (uint32 i = 0; i < summonCount; ++i, dist += 15.f)
                    {
                        Position pos = GetCaster()->GetNearPosition(dist, 0);
                        GetCaster()->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_CONGEALING_VOMIT_SUMMON, true);
                    }

                    GetCaster()->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_congealing_vomit_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_congealing_vomit_SpellScript();
        }
};

class spell_vha_recongealing : public SpellScriptLoader
{
    public:
        spell_vha_recongealing() : SpellScriptLoader("spell_vha_recongealing")
        {}

        class spell_recongealing_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_recongealing_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    GetUnitOwner()->SetFullHealth();
                    GetUnitOwner()->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_FETID_STENCH, true);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_recongealing_AuraScript::HandleOnRemove, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_recongealing_AuraScript();
        }
};


void AddSC_boss_festerface()
{
    new boss_festerface();
    new npc_vha_congealing_goo();
    new at_vha_icky_goo();
    new spell_festerface_congealing_vomit();
    new spell_vha_recongealing();
}
