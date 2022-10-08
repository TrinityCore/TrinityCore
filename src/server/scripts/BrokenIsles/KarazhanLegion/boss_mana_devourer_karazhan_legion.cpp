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
#include "SpellAuras.h"
#include "AreaTrigger.h"
#include "karazhan_legion.h"

enum Spells
{
    SPELL_ARCANE_BOMB                       = 227618,
    SPELL_ENERGY_VOID                       = 227523,
    SPELL_ENERGY_VOID_DMG                   = 227524,
    SPELL_ENERGY_VOID_MANA                  = 227528,
    SPELL_UNSTABLE_MANA                     = 227502,
    SPELL_COALESCE_POWER                    = 227297,
    SPELL_COALESCE_POWER_TRIGGER            = 230210,
    SPELL_LOOSE_MANA_TRIGGER                = 228066,
    SPELL_LOOSE_MANA_AREA                   = 227296,
    SPELL_ENERGY_DISCHARGE                  = 227457,
    SPELL_RESTORE_MANA_AURA                 = 227451,
    SPELL_RESTORE_MANA                      = 232066,
    SPELL_ABSORB_LOOSE_MANA                 = 227466,
    SPELL_DECIMATING_ESSENCE                = 227507,
    SPELL_FADE_DARKSCREEN                   = 105278
};

enum Events
{
    EVENT_ARCANE_BOMB                       = 1,
    EVENT_COALESCE_POWER                    = 2,
    EVENT_CHECK_ENERGY                      = 3,
    EVENT_ENERGY_VOID                       = 4,
    EVENT_ENERGY_DISCHARGE                  = 5,
    EVENT_DECIMATING_ESSENCE                = 6,
    EVENT_MOVE_POINT                        = 7
};

constexpr uint32 ACTION_FULL_MANA           = 1;
constexpr uint32 NPC_LOOSE_MANA             = 98080;

const Position GuardianStudyPos = { 4145.191f, -2030.723f, 730.595f };

class boss_new_mana_devourer : public CreatureScript
{
    public:
        boss_new_mana_devourer() : CreatureScript("boss_new_mana_devourer") { }

        struct boss_new_mana_devourer_AI : public BossAI
        {
            explicit boss_new_mana_devourer_AI(Creature* creature) : BossAI(creature, DATA_MANA_DEVOURER) { }

            void EnterCombat(Unit* /**/) override
            {
                me->SetPower(POWER_MANA, 0);
                me->SetMaxPower(POWER_MANA, 10000);
                DoCast(me, SPELL_RESTORE_MANA_AURA, true);

                _EnterCombat();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_ARCANE_BOMB, 5s);
                events.ScheduleEvent(EVENT_COALESCE_POWER, 30s);
                events.ScheduleEvent(EVENT_ENERGY_VOID, 15s);
                events.ScheduleEvent(EVENT_ENERGY_DISCHARGE, 25s, 30s);
            }

            void JustDied(Unit* /**/) override
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UNSTABLE_MANA);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->DoCastSpellOnPlayers(SPELL_FADE_DARKSCREEN);

                for (auto & it : me->GetMap()->GetPlayers())
                {
                    if (Player* ptr = it.GetSource())
                        ptr->NearTeleportTo(GuardianStudyPos);
                }

                _JustDied();
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAurasDueToSpell(SPELL_RESTORE_MANA_AURA);
                me->RemoveAllAreaTriggers();
                BossAI::EnterEvadeMode(why);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_FULL_MANA)
                    events.ScheduleEvent(EVENT_DECIMATING_ESSENCE, 100ms);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_ARCANE_BOMB:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_ARCANE_BOMB);

                        events.ScheduleEvent(EVENT_ARCANE_BOMB, 15s);
                        break;
                    }

                    case EVENT_ENERGY_VOID:
                    {
                        DoCast(me, SPELL_ENERGY_VOID);
                        events.ScheduleEvent(EVENT_ENERGY_VOID, 20s);
                        break;
                    }

                    case EVENT_COALESCE_POWER:
                    {
                        DoCast(me, SPELL_COALESCE_POWER);
                        events.ScheduleEvent(EVENT_COALESCE_POWER, 30s);
                    }

                    case EVENT_ENERGY_DISCHARGE:
                    {
                        DoCast(me, SPELL_ENERGY_DISCHARGE);
                        events.ScheduleEvent(EVENT_ENERGY_DISCHARGE, 25s, 30s);
                        break;
                    }

                    case EVENT_DECIMATING_ESSENCE:
                    {
                        me->CastSpell(me, SPELL_DECIMATING_ESSENCE, false);
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_new_mana_devourer_AI(creature);
        }
};

class spell_devourer_coalesce_power : public SpellScriptLoader
{
    public:
        spell_devourer_coalesce_power() : SpellScriptLoader("spell_devourer_coalesce_power") { }

        class spell_coalesce_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_coalesce_AuraScript);

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    Unit* && owner = GetUnitOwner();

                    if (owner->GetPowerPct(POWER_MANA) >= 5.f)
                    {
                        owner->SetPower(POWER_MANA, owner->GetPower(POWER_MANA) - owner->GetMaxPower(POWER_MANA) * 0.05f);
                        Position pos = owner->GetNearPosition(50.f, frand(0, 2 * float(M_PI)));

                        auto* orb = owner->SummonCreature(NPC_LOOSE_MANA, pos);

                        if (orb)
                        {
                            orb->CastSpell(orb, SPELL_LOOSE_MANA_AREA, true);
                            orb->GetMotionMaster()->MoveFollow(owner, 0, 0);
                        }
                    }
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_coalesce_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_coalesce_AuraScript();
        }
};

class spell_devourer_mana_restore : public SpellScriptLoader
{
    public:
        spell_devourer_mana_restore() : SpellScriptLoader("spell_devourer_mana_restore") { }

        class spell_mana_restore_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_mana_restore_AuraScript);

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_RESTORE_MANA, true);

                    if (GetUnitOwner()->GetPower(POWER_MANA) == GetUnitOwner()->GetMaxPower(POWER_MANA))
                        GetUnitOwner()->GetAI()->DoAction(ACTION_FULL_MANA);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_mana_restore_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mana_restore_AuraScript();
        }
};

class spell_devourer_energy_void : public SpellScriptLoader
{
    public:
        spell_devourer_energy_void() : SpellScriptLoader("spell_devourer_energy_void") { }

        class spell_energy_void_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_energy_void_AuraScript);

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    Unit* owner = GetUnitOwner();

                    Aura* unstable = owner->GetAura(SPELL_UNSTABLE_MANA);

                    if (unstable)
                        unstable->ModStackAmount(-1);
                    else
                        owner->CastSpell(owner, SPELL_ENERGY_VOID_MANA, true);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_energy_void_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_energy_void_AuraScript();
        }
};

class at_kara_energy_void : public AreaTriggerEntityScript
{
    public:
        at_kara_energy_void() : AreaTriggerEntityScript("at_kara_energy_void") { }

        struct at_kara_energy_void_AI : public AreaTriggerAI
        {
            explicit at_kara_energy_void_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {
                _timerCheck = 0;
            }

            void OnUnitEnter(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->CastSpell(target, SPELL_ENERGY_VOID_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_ENERGY_VOID_DMG);
            }

            void OnUpdate(uint32 diff) override
            {
                _timerCheck += diff;

                if (_timerCheck >= 1000)
                {
                    _timerCheck = 0;
                    /*for (auto & it : at->GetInsideUnits())
                    {
                        if (Player* ptr = ObjectAccessor::GetPlayer(*at, it))
                        {
                            if (Aura* mana = ptr->GetAura(SPELL_UNSTABLE_MANA))
                            {
                                float visualRadius = at->GetFloatValue(AREATRIGGER_EXTRA_SCALE_CURVE + 5);
                                at->SetFloatValue(AREATRIGGER_EXTRA_SCALE_CURVE + 5, visualRadius - visualRadius * 0.05f);
                            }
                        }
                    }*/
                }
            }

            private:
                uint32 _timerCheck;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_energy_void_AI(at);
        }
};

class at_kara_loose_mana : public AreaTriggerEntityScript
{
    public:
        at_kara_loose_mana() : AreaTriggerEntityScript("at_kara_loose_mana") { }

        struct at_kara_loose_mana_AI : public AreaTriggerAI
        {
            explicit at_kara_loose_mana_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {
                _moved = false;
            }

            void OnUnitEnter(Unit* target) override
            {
                if (!target)
                    return;

                if (target->GetTypeId() == TYPEID_PLAYER)
                {
                    _events.Reset();
                    target->CastSpell(target, SPELL_UNSTABLE_MANA, true);
                    at->Remove();
                }
                else if (target->GetEntry() == BOSS_MANA_DEVOURER)
                {
                    _events.Reset();
                    target->CastSpell(target, SPELL_ABSORB_LOOSE_MANA, true);
                    at->Remove();
                }
            }

            private:
                bool _moved;
                EventMap _events;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_loose_mana_AI(at);
        }
};

void AddSC_boss_mana_devourer_karazhan_legion()
{
    new boss_new_mana_devourer();
    new spell_devourer_coalesce_power();
    new spell_devourer_energy_void();
    new spell_devourer_mana_restore();
    new at_kara_loose_mana();
    new at_kara_energy_void();
}
