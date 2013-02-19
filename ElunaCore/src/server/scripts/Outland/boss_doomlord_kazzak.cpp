/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "SpellScript.h"

enum Texts
{
    SAY_INTRO       = 0,
    SAY_AGGRO       = 1,
    SAY_SURPREME    = 2,
    SAY_KILL        = 3,
    SAY_DEATH       = 4,
    EMOTE_FRENZY    = 5,
    SAY_RAND        = 6
};

enum Spells
{
    SPELL_SHADOW_VOLLEY         = 32963,
    SPELL_CLEAVE                = 31779,
    SPELL_THUNDERCLAP           = 36706,
    SPELL_VOID_BOLT             = 39329,
    SPELL_MARK_OF_KAZZAK        = 32960,
    SPELL_MARK_OF_KAZZAK_DAMAGE = 32961,
    SPELL_ENRAGE                = 32964,
    SPELL_CAPTURE_SOUL          = 32966,
    SPELL_TWISTED_REFLECTION    = 21063,
    SPELL_BERSERK               = 32965,
};

enum Events
{
    EVENT_SHADOW_VOLLEY         = 1,
    EVENT_CLEAVE                = 2,
    EVENT_THUNDERCLAP           = 3,
    EVENT_VOID_BOLT             = 4,
    EVENT_MARK_OF_KAZZAK        = 5,
    EVENT_ENRAGE                = 6,
    EVENT_TWISTED_REFLECTION    = 7,
    EVENT_BERSERK               = 8
};

class boss_doomlord_kazzak : public CreatureScript
{
    public:
        boss_doomlord_kazzak() : CreatureScript("boss_doomlord_kazzak") { }

        struct boss_doomlordkazzakAI : public ScriptedAI
        {
            boss_doomlordkazzakAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_SHADOW_VOLLEY, urand(6000, 10000));
                _events.ScheduleEvent(EVENT_CLEAVE, 7000);
                _events.ScheduleEvent(EVENT_THUNDERCLAP, urand(14000, 18000));
                _events.ScheduleEvent(EVENT_VOID_BOLT, 30000);
                _events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 25000);
                _events.ScheduleEvent(EVENT_ENRAGE, 60000);
                _events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 33000);
                _events.ScheduleEvent(EVENT_BERSERK, 180000);
            }

            void JustRespawned()
            {
                Talk(SAY_INTRO);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);
            }

            void KilledUnit(Unit* victim)
            {
                // When Kazzak kills a player (not pets/totems), he regens some health
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

                DoCast(me, SPELL_CAPTURE_SOUL);

                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);
            }

            void UpdateAI(uint32 const diff)
            {
                // Return since we have no target
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADOW_VOLLEY:
                            DoCastVictim(SPELL_SHADOW_VOLLEY);
                            _events.ScheduleEvent(EVENT_SHADOW_VOLLEY, urand(4000, 6000));
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            _events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 12000));
                            break;
                        case EVENT_THUNDERCLAP:
                            DoCastVictim(SPELL_THUNDERCLAP);
                            _events.ScheduleEvent(EVENT_THUNDERCLAP, urand(10000, 14000));
                            break;
                        case EVENT_VOID_BOLT:
                            DoCastVictim(SPELL_VOID_BOLT);
                            _events.ScheduleEvent(EVENT_VOID_BOLT, urand(15000, 18000));
                            break;
                        case EVENT_MARK_OF_KAZZAK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_MARK_OF_KAZZAK);
                            _events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 20000);
                            break;
                        case EVENT_ENRAGE:
                            Talk(EMOTE_FRENZY);
                            DoCast(me, SPELL_ENRAGE);
                            _events.ScheduleEvent(EVENT_ENRAGE, 30000);
                            break;
                        case EVENT_TWISTED_REFLECTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_TWISTED_REFLECTION);
                            _events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 15000);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_doomlordkazzakAI (creature);
        }
};

class spell_mark_of_kazzak : public SpellScriptLoader
{
    public:
        spell_mark_of_kazzak() : SpellScriptLoader("spell_mark_of_kazzak") { }

        class spell_mark_of_kazzak_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mark_of_kazzak_AuraScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MARK_OF_KAZZAK_DAMAGE))
                    return false;
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Unit* owner = GetUnitOwner())
                    amount = CalculatePct(owner->GetPower(POWER_MANA), 5);
            }

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* target = GetTarget();

                if (target->GetPower(POWER_MANA) == 0)
                {
                    target->CastSpell(target, SPELL_MARK_OF_KAZZAK_DAMAGE, true, NULL, aurEff);
                    // Remove aura
                    SetDuration(0);
                }
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mark_of_kazzak_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_MANA_LEECH);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mark_of_kazzak_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_MANA_LEECH);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_mark_of_kazzak_AuraScript();
        }
};

void AddSC_boss_doomlordkazzak()
{
    new boss_doomlord_kazzak();
    new spell_mark_of_kazzak();
}
