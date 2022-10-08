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
#include "SpellAuraEffects.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "SpellInfo.h"
#include "AreaTrigger.h"
#include "karazhan_legion.h"

enum Spells
{
    SPELL_MASS_REPETANCE                    = 227508,
    SPELL_SACRED_GROUND                     = 227789,
    SPELL_SACRED_GROUND_DMG                 = 227848,
    SPELL_HOLY_SHOCK                        = 227800,
    SPELL_HOLY_BULWARK                      = 227817,
    SPELL_HOLY_BOLT                         = 227809,
    SPELL_HOLY_WRATH                        = 227823
};

enum Events
{
    EVENT_MASS_REPETANCE                    = 1,
    EVENT_HOLY_SHOCK                        = 2,
    EVENT_HOLY_BOLT                         = 3,
    EVENT_SACRED_GROUND                     = 4,
    EVENT_HOLY_BULWARK                      = 5,
    EVENT_HOLY_WRATH                        = 6
};

enum Says
{
    SAY_AGGRO                               = 0,
    SAY_HOLY_BOLT                           = 1,
    SAY_HOLY_SHOCK                          = 2,
    SAY_SACRED_GROUND                       = 3,
    SAY_MASS_REPETANCE                      = 4,
    SAY_HOLY_BULWARK                        = 5,
    SAY_HOLY_WRATH                          = 6,
    SAY_KILL                                = 7,
    SAY_WIPE                                = 8,
    SAY_DEATH                               = 9
};

constexpr int32 ACTION_HOLY_BULWARK         = 1;
constexpr int32 ACTION_PREPARE_HOLY_WRATH   = 2;

class boss_new_maiden_of_virtue : public CreatureScript
{
    public:
        boss_new_maiden_of_virtue() : CreatureScript("boss_new_maiden_of_virtue") { }

        struct boss_new_maiden_of_virtue_AI : public BossAI
        {
            explicit boss_new_maiden_of_virtue_AI(Creature* creature) : BossAI(creature, DATA_MAIDEN_OF_VIRTUE) { }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void JustDied(Unit* /**/) override
            {
                me->RemoveAllAreaTriggers();
                Talk(SAY_DEATH);
                _JustDied();
            }

            void JustReachedHome() override
            {
                Talk(SAY_WIPE);
                me->RemoveAllAreaTriggers();
                _JustReachedHome();
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                me->RemoveAllAreaTriggers();
                BossAI::EnterEvadeMode(why);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_HOLY_BULWARK)
                    events.ScheduleEvent(EVENT_HOLY_BULWARK, 500ms);
                else if (action == ACTION_PREPARE_HOLY_WRATH)
                {
                    events.DelayEvents(5000);
                    events.ScheduleEvent(EVENT_HOLY_WRATH, 1);
                }
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_MASS_REPETANCE, 50s);
                events.ScheduleEvent(EVENT_HOLY_SHOCK, 15s);
                events.ScheduleEvent(EVENT_SACRED_GROUND, 12s);
                events.ScheduleEvent(EVENT_HOLY_BOLT, 10s);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_MASS_REPETANCE:
                    {
                        Talk(SAY_MASS_REPETANCE);
                        DoCast(me, SPELL_MASS_REPETANCE);
                        events.ScheduleEvent(EVENT_MASS_REPETANCE, 50s);
                        break;
                    }

                    case EVENT_HOLY_BULWARK:
                    {
                        if (roll_chance_f(50))
                            Talk(SAY_HOLY_BULWARK);

                        me->CastSpell(me, SPELL_HOLY_BULWARK, false);
                        events.ScheduleEvent(EVENT_HOLY_WRATH, 1s);
                        break;
                    }

                    case EVENT_HOLY_WRATH:
                    {
                        Talk(SAY_HOLY_WRATH);
                        me->CastSpell(me, SPELL_HOLY_WRATH, false);
                        break;
                    }

                    case EVENT_HOLY_SHOCK:
                    {
                        if (roll_chance_i(50))
                            Talk(SAY_HOLY_SHOCK);

                        DoCastVictim(SPELL_HOLY_SHOCK);
                        events.ScheduleEvent(EVENT_HOLY_SHOCK, 15s);
                        break;
                    }

                    case EVENT_HOLY_BOLT:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        {
                            Talk(SAY_HOLY_BOLT);
                            DoCast(target, SPELL_HOLY_BOLT);
                        }

                        events.ScheduleEvent(EVENT_HOLY_BOLT, 10s);
                        break;
                    }

                    case EVENT_SACRED_GROUND:
                    {
                        Talk(SAY_SACRED_GROUND);
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me, true));

                        if (!target)
                            DoCastVictim(SPELL_SACRED_GROUND);
                        else
                            DoCast(target, SPELL_SACRED_GROUND);

                        events.ScheduleEvent(EVENT_SACRED_GROUND, 23s, 25s);
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_new_maiden_of_virtue_AI(creature);
        }
};

class spell_maiden_holy_bulwark : public SpellScriptLoader
{
    public:
        spell_maiden_holy_bulwark() : SpellScriptLoader("spell_maiden_holy_bulwark") { }

        class spell_holy_bulwark_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_holy_bulwark_AuraScript);

                bool Load() override
                {
                    _damageRestant = 0;
                    return true;
                }

                void HandleOnAbsorb(AuraEffect* aurEff, DamageInfo& /**/, uint32& absorbAmount)
                {
                    _damageRestant += absorbAmount;

                    if (_damageRestant >= uint32(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints))
                        GetUnitOwner()->RemoveAura(aurEff->GetBase());
                }

                void Register() override
                {
                    AfterEffectAbsorb += AuraEffectAbsorbFn(spell_holy_bulwark_AuraScript::HandleOnAbsorb, EFFECT_0);
                }

            private:
                uint32 _damageRestant;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_holy_bulwark_AuraScript();
        }
};

class spell_maiden_mass_repetance : public SpellScriptLoader
{
    public:
        spell_maiden_mass_repetance() : SpellScriptLoader("spell_maiden_mass_repetance") { }

        class spell_mass_repentance_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_mass_repentance_SpellScript);

                void HandleAfterCast()
                {
                    if (GetCaster()->GetAI())
                        GetCaster()->GetAI()->DoAction(ACTION_HOLY_BULWARK);
                }

                void Register() override
                {
                    AfterCast += SpellCastFn(spell_mass_repentance_SpellScript::HandleAfterCast);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mass_repentance_SpellScript();
        }
};

class spell_maiden_holy_wrath : public SpellScriptLoader
{
    public:
        spell_maiden_holy_wrath() : SpellScriptLoader("spell_maiden_holy_wrath") { }

        class spell_holy_wrath_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_holy_wrath_SpellScript);

                void HandleBeforeCast()
                {
                    if (GetCaster()->HasAura(SPELL_HOLY_BULWARK))
                        GetCaster()->GetAI()->DoAction(ACTION_PREPARE_HOLY_WRATH);
                }

                void Register() override
                {
                    BeforeCast += SpellCastFn(spell_holy_wrath_SpellScript::HandleBeforeCast);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_holy_wrath_SpellScript();
        }
};

class at_sacred_ground : public AreaTriggerEntityScript
{
    public:
        at_sacred_ground() : AreaTriggerEntityScript("at_sacred_ground") { }

        struct at_sacred_ground_AI : public AreaTriggerAI
        {
            explicit at_sacred_ground_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {
                _timerCheck = 0;
            }

            void OnUpdate(uint32 diff) override
            {
                _timerCheck += diff;

                if (_timerCheck >= IN_MILLISECONDS + 500)
                {
                    _timerCheck = 0;

                    for (auto & it : at->GetInsideUnits())
                    {
                        Player* ptr = ObjectAccessor::GetPlayer(*at, it);

                        if (!ptr)
                            continue;

                        ptr->CastSpell(ptr, SPELL_SACRED_GROUND_DMG, true);
                    }
                }
            }

            private:
                uint32 _timerCheck;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_sacred_ground_AI(at);
        }
};

void AddSC_boss_maiden_of_virtue_karazhan_legion()
{
    new boss_new_maiden_of_virtue();
    new at_sacred_ground();
    new spell_maiden_holy_bulwark();
    new spell_maiden_mass_repetance();
    new spell_maiden_holy_wrath();
}
