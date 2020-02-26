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
#include "SpellInfo.h"
#include "SpellScript.h"
#include "gundrak.h"

enum Spells
{
    SPELL_SUMMON_PHANTOM           = 55205,
    SPELL_SUMMON_PHANTOM_TRANSFORM = 55097,
    SPELL_DETERMINED_GORE          = 55102,
    SPELL_DETERMINED_STAB          = 55104,
    SPELL_GROUND_TREMOR            = 55142,
    SPELL_NUMBING_SHOUT            = 55106,
    SPELL_QUAKE                    = 55101,
    SPELL_NUMBING_ROAR             = 55100,
    SPELL_MOJO_FRENZY              = 55163,
    SPELL_MOJO_FRENZY_CAST_SPEED   = 55096,
    SPELL_TRANSFORMATION           = 55098 // Periodic, The caster transforms into a powerful mammoth, increasing Physical damage done by 25% and granting immunity to Stun effects.
};

enum Says
{
    SAY_AGGRO                      = 0,
    SAY_SLAY                       = 1,
    SAY_DEATH                      = 2,
    SAY_TRANSFORM                  = 3,
    SAY_QUAKE                      = 4,
    EMOTE_BEGIN_TRANSFORM          = 5,
    EMOTE_TRANSFORMED              = 6,
    EMOTE_ACTIVATE_ALTAR           = 7
};

enum Events
{
    EVENT_GROUND_TREMOR            = 1,
    EVENT_NUMBLING_SHOUT,
    EVENT_DETERMINED_STAB,
    EVENT_TRANFORMATION,
    EVENT_PHANTOM
};

enum Misc
{
    DATA_LESS_RABI                 = 1
};

enum Phases
{
    PHASE_INTRO                    = 1,
    PHASE_COMBAT
};

class boss_moorabi : public CreatureScript
{
    public:
        boss_moorabi() : CreatureScript("boss_moorabi") { }

        struct boss_moorabiAI : public BossAI
        {
            boss_moorabiAI(Creature* creature) : BossAI(creature, DATA_MOORABI), _transformed(false) { }

            void Reset() override
            {
                _Reset();
                _transformed = false;
                events.SetPhase(PHASE_INTRO);
                events.ScheduleEvent(EVENT_PHANTOM, Seconds(21), 0, PHASE_INTRO);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                Talk(SAY_AGGRO);
                DoCastSelf(SPELL_MOJO_FRENZY, true);

                events.SetPhase(PHASE_COMBAT);
                events.ScheduleEvent(EVENT_GROUND_TREMOR, 18s);
                events.ScheduleEvent(EVENT_NUMBLING_SHOUT, 10s);
                events.ScheduleEvent(EVENT_DETERMINED_STAB, 20s);
                events.ScheduleEvent(EVENT_TRANFORMATION, 12s);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _DespawnAtEvade();
            }

            void JustSummoned(Creature* /*summon*/) override {}

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_LESS_RABI)
                    return _transformed ? 0 : 1;
                return 0;
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(EMOTE_ACTIVATE_ALTAR);
                Talk(SAY_DEATH);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == SPELL_TRANSFORMATION)
                {
                    _transformed = true;
                    Talk(EMOTE_TRANSFORMED);
                    events.CancelEvent(EVENT_TRANFORMATION);
                    me->RemoveAurasDueToSpell(SPELL_MOJO_FRENZY);
                }
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
                        case EVENT_GROUND_TREMOR:
                            if (roll_chance_i(50))
                                Talk(SAY_QUAKE);
                            DoCastAOE(_transformed ? SPELL_QUAKE : SPELL_GROUND_TREMOR);
                            events.Repeat(Seconds(10));
                            break;
                        case EVENT_NUMBLING_SHOUT:
                            DoCastAOE(_transformed ? SPELL_NUMBING_ROAR : SPELL_NUMBING_SHOUT);
                            events.Repeat(Seconds(10));
                            break;
                        case EVENT_DETERMINED_STAB:
                            DoCastAOE(_transformed ? SPELL_DETERMINED_GORE : SPELL_DETERMINED_STAB);
                            events.Repeat(Seconds(8));
                            break;
                        case EVENT_TRANFORMATION:
                            Talk(EMOTE_BEGIN_TRANSFORM);
                            Talk(SAY_TRANSFORM);
                            DoCastSelf(SPELL_TRANSFORMATION);
                            DoCastSelf(SPELL_SUMMON_PHANTOM_TRANSFORM, true);
                            events.Repeat(Seconds(10));
                            break;
                        case EVENT_PHANTOM:
                            DoCastSelf(SPELL_SUMMON_PHANTOM, true);
                            events.Repeat(Seconds(20), Seconds(25));
                            break;
                        default:
                            break;
                    }

                    if(me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _transformed;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetGundrakAI<boss_moorabiAI>(creature);
        }
};

class achievement_less_rabi : public AchievementCriteriaScript
{
    public:
        achievement_less_rabi() : AchievementCriteriaScript("achievement_less_rabi") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Moorabi = target->ToCreature())
                if (Moorabi->AI()->GetData(DATA_LESS_RABI))
                    return true;

            return false;
        }
};

// 55163 - Mojo Frenzy
class spell_moorabi_mojo_frenzy : public SpellScriptLoader
{
    public:
        spell_moorabi_mojo_frenzy() : SpellScriptLoader("spell_moorabi_mojo_frenzy") { }

        class spell_moorabi_mojo_frenzy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_moorabi_mojo_frenzy_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_MOJO_FRENZY_CAST_SPEED });
            }

            void HandlePeriodic(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();

                Unit* owner = GetUnitOwner();
                int32 castSpeedBonus = (100.0f - owner->GetHealthPct()) * 4; // between 0% and 400% cast speed bonus
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(castSpeedBonus);
                owner->CastSpell(owner, SPELL_MOJO_FRENZY_CAST_SPEED, args);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_moorabi_mojo_frenzy_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_moorabi_mojo_frenzy_AuraScript();
        }
};

void AddSC_boss_moorabi()
{
    new boss_moorabi();
    new achievement_less_rabi();
    new spell_moorabi_mojo_frenzy();
}
