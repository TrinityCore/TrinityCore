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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "temple_of_ahnqiraj.h"

enum Yells
{
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_SPLIT                   = 2,
    SAY_DEATH                   = 3
};

enum Spells
{
    SPELL_ARCANE_EXPLOSION      = 26192,
    SPELL_EARTH_SHOCK           = 26194,
    SPELL_TRUE_FULFILLMENT      = 785,
    SPELL_TRUE_FULFILLMENT_2    = 2313,
    SPELL_INITIALIZE_IMAGE      = 3730,
    SPELL_SUMMON_IMAGES         = 747,
    SPELL_GENERIC_DISMOUNT      = 61286
};

enum Events
{
    EVENT_ARCANE_EXPLOSION      = 1,
    EVENT_FULLFILMENT           = 2,
    EVENT_BLINK                 = 3,
    EVENT_EARTH_SHOCK           = 4
};

uint32 const BlinkSpells[3] = { 4801, 8195, 20449 };

class boss_skeram : public CreatureScript
{
    public:
        boss_skeram() : CreatureScript("boss_skeram") { }

        struct boss_skeramAI : public BossAI
        {
            boss_skeramAI(Creature* creature) : BossAI(creature, DATA_SKERAM)
            {
                Initialize();
            }

            void Initialize()
            {
                _flag = 0;
                _hpct = 75.0f;
            }

            void Reset() override
            {
                Initialize();
                me->SetVisible(true);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_SLAY);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                ScriptedAI::EnterEvadeMode(why);
                if (me->IsSummon())
                    me->DespawnOrUnsummon();
            }

            void JustSummoned(Creature* creature) override
            {
                // Shift the boss and images (Get it? *Shift*?)
                uint8 rand = 0;
                if (_flag != 0)
                {
                    while (_flag & (1 << rand))
                        rand = urand(0, 2);
                    DoCast(me, BlinkSpells[rand]);
                    _flag |= (1 << rand);
                    _flag |= (1 << 7);
                }

                while (_flag & (1 << rand))
                    rand = urand(0, 2);
                creature->CastSpell(creature, BlinkSpells[rand]);
                _flag |= (1 << rand);

                if (_flag & (1 << 7))
                    _flag = 0;

                if (Unit* Target = SelectTarget(SelectTargetMethod::Random))
                    creature->AI()->AttackStart(Target);

                float ImageHealthPct;

                if (me->GetHealthPct() < 25.0f)
                    ImageHealthPct = 0.50f;
                else if (me->GetHealthPct() < 50.0f)
                    ImageHealthPct = 0.20f;
                else
                    ImageHealthPct = 0.10f;

                creature->SetMaxHealth(me->GetMaxHealth() * ImageHealthPct);
                creature->SetHealth(creature->GetMaxHealth() * (me->GetHealthPct() / 100.0f));

                summons.Summon(creature);
            }

            void JustDied(Unit* killer) override
            {
                if (!me->IsSummon())
                {
                    Talk(SAY_DEATH);
                    BossAI::JustDied(killer);
                }
                else
                    me->DespawnOrUnsummon();
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                events.Reset();

                events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 6s, 12s);
                events.ScheduleEvent(EVENT_FULLFILMENT, 15s);
                events.ScheduleEvent(EVENT_BLINK, 30s, 45s);
                events.ScheduleEvent(EVENT_EARTH_SHOCK, 2s);

                Talk(SAY_AGGRO);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ARCANE_EXPLOSION:
                            DoCastAOE(SPELL_ARCANE_EXPLOSION, true);
                            events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 8s, 18s);
                            break;
                        case EVENT_FULLFILMENT:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 45.0f, true))
                                DoCast(target, SPELL_TRUE_FULFILLMENT);
                            events.ScheduleEvent(EVENT_FULLFILMENT, 20s, 30s);
                            break;
                        case EVENT_BLINK:
                            DoCast(me, BlinkSpells[urand(0, 2)]);
                            ResetThreatList();
                            me->SetVisible(true);
                            events.ScheduleEvent(EVENT_BLINK, 10s, 30s);
                            break;
                        case EVENT_EARTH_SHOCK:
                            DoCastVictim(SPELL_EARTH_SHOCK);
                            events.ScheduleEvent(EVENT_EARTH_SHOCK, 2s);
                            break;
                    }
                }

                if (!me->IsSummon() && me->GetHealthPct() < _hpct)
                {
                    DoCastAOE(SPELL_SUMMON_IMAGES, true);
                    Talk(SAY_SPLIT);
                    _hpct -= 25.0f;
                    me->SetVisible(false);
                    events.RescheduleEvent(EVENT_BLINK, 2s);
                }

                if (me->IsWithinMeleeRange(me->GetVictim()))
                {
                    events.RescheduleEvent(EVENT_EARTH_SHOCK, 2s);
                    DoMeleeAttackIfReady();
                }
            }

        private:
            float _hpct;
            uint8 _flag;
        };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAQ40AI<boss_skeramAI>(creature);
    }
};

// 26192 - Arcane Explosion
class spell_skeram_arcane_explosion : public SpellScriptLoader
{
    public:
        spell_skeram_arcane_explosion() : SpellScriptLoader("spell_skeram_arcane_explosion") { }

        class spell_skeram_arcane_explosion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_skeram_arcane_explosion_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([](WorldObject* object) -> bool
                {
                    if (object->GetTypeId() == TYPEID_PLAYER)
                        return false;

                    if (Creature* creature = object->ToCreature())
                        return !creature->IsPet();

                    return true;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_skeram_arcane_explosion_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_skeram_arcane_explosion_SpellScript();
        }
};

// 785 - True Fulfillment
class spell_skeram_true_fulfillment : public SpellScriptLoader
{
public:
    spell_skeram_true_fulfillment() : SpellScriptLoader("spell_skeram_true_fulfillment") { }

    class spell_skeram_true_fulfillment_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skeram_true_fulfillment_SpellScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ SPELL_TRUE_FULFILLMENT_2, SPELL_GENERIC_DISMOUNT });
        }

        void HandleEffect(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_GENERIC_DISMOUNT, true);
            GetCaster()->CastSpell(GetHitUnit(), SPELL_TRUE_FULFILLMENT_2, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_skeram_true_fulfillment_SpellScript::HandleEffect, EFFECT_0, SPELL_AURA_MOD_CHARM);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skeram_true_fulfillment_SpellScript();
    }
};

void AddSC_boss_skeram()
{
    new boss_skeram();
    new spell_skeram_arcane_explosion();
    new spell_skeram_true_fulfillment();
}
