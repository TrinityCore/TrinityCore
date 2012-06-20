/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "sethekk_halls.h"

enum Texts
{
    SAY_INTRO           = 0,
    SAY_AGGRO           = 1,
    SAY_SLAY            = 2,
    SAY_DEATH           = 3,
    EMOTE_ARCANE_EXP    = 4
};

enum Spells
{
    SPELL_ARCANE_BUBBLE         = 9438,
    SPELL_SLOW                  = 35032,
    SPELL_ARCANE_VOLLEY         = 35059,
    SPELL_MANA_SHIELD           = 38151,
    SPELL_BLINK                 = 38194,
    SPELL_ARCANE_EXPLOSION      = 38197,
    SPELL_BLINK_TELEPORT        = 38203,
    SPELL_POLYMORPH             = 38245
};

enum Events
{
    EVENT_ARCANE_VOLLEY = 1,
    EVENT_POLYMORPH     = 2,
    EVENT_BLINK         = 3,
    EVENT_SLOW          = 4
};

class boss_talon_king_ikiss : public CreatureScript
{
    public:
        boss_talon_king_ikiss() : CreatureScript("boss_talon_king_ikiss") { }

        struct boss_talon_king_ikissAI : public BossAI
        {
            boss_talon_king_ikissAI(Creature* creature) : BossAI(creature, DATA_TALON_KING_IKISS)
            {
                _introDone = false;
            }

            void Reset()
            {
                _Reset();
                events.ScheduleEvent(EVENT_ARCANE_VOLLEY, 5000);
                events.ScheduleEvent(EVENT_POLYMORPH, 8000);
                events.ScheduleEvent(EVENT_BLINK, 35000);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SLOW, urand(15000,30000));

                _isManaShield = false;
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (_introDone)
                    return;
                    
                if (!me->IsWithinDistInMap(who, 100.0f))
                    return;
                    
                 _introDone = true;
                 Talk(SAY_INTRO);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
            }

            void JustDied(Unit* /*Killer*/)
            {
                Talk(SAY_DEATH);
                
                _JustDied();
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_SLAY);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                    
                if (!_isManaShield && HealthBelowPct(20))
                {
                    DoCast(me, SPELL_MANA_SHIELD);
                    _isManaShield = true;
                }
                
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ARCANE_VOLLEY:
                            DoCast(me, SPELL_ARCANE_VOLLEY);
                            events.ScheduleEvent(EVENT_ARCANE_VOLLEY, urand(7000, 12000));
                            break;
                        case EVENT_POLYMORPH:
                            if (Unit* target = IsHeroic() ? SelectTarget(SELECT_TARGET_RANDOM, 0) : SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                                DoCast(target, SPELL_POLYMORPH);
                            events.ScheduleEvent(EVENT_POLYMORPH, urand(15000,17500));
                            break;
                        case EVENT_SLOW:
                            DoCast(me, SPELL_SLOW);
                            events.ScheduleEvent(EVENT_SLOW, urand(15000,30000));
                            break;
                        case EVENT_BLINK:
                            Talk(EMOTE_ARCANE_EXP);
                            
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                if (me->IsNonMeleeSpellCasted(false))
                                    me->InterruptNonMeleeSpells(false);
                        
                                DoCast(target, SPELL_BLINK);
                                DoCast(me, SPELL_ARCANE_BUBBLE, true);
                                DoCast(me, SPELL_ARCANE_EXPLOSION);
                                DoResetThreat();
                            }
                            events.ScheduleEvent(EVENT_BLINK, urand(35000,40000));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
            
            private:
                bool _isManaShield;
                bool _introDone;
        };
        
        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_talon_king_ikissAI (creature);
        }
};

class spell_talon_king_ikiss_blink : public SpellScriptLoader
{
    public:
        spell_talon_king_ikiss_blink() : SpellScriptLoader("spell_talon_king_ikiss_blink") { }

        class spell_talon_king_ikiss_blink_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_talon_king_ikiss_blink_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_BLINK_TELEPORT))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                    caster->CastSpell(target, SPELL_BLINK_TELEPORT, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_talon_king_ikiss_blink_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_talon_king_ikiss_blink_SpellScript();
        }
};

void AddSC_boss_talon_king_ikiss()
{
    new boss_talon_king_ikiss();
    new spell_talon_king_ikiss_blink();
}
