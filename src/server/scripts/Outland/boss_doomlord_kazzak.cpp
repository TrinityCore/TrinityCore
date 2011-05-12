/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"

enum Yells
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
    SPELL_SHADOWVOLLEY          = 32963,
    SPELL_CLEAVE                = 31779,
    SPELL_THUNDERCLAP           = 36706,
    SPELL_VOIDBOLT              = 39329,
    SPELL_MARKOFKAZZAK          = 32960,
    SPELL_MARKOFKAZZAK_DAMAGE   = 32961,
    SPELL_ENRAGE                = 32964,
    SPELL_CAPTURESOUL           = 32966,
    SPELL_TWISTEDREFLECTION     = 21063
};

enum Events
{
    EVENT_SHADOW_VOLLEY         = 1,
    EVENT_CLEAVE                = 2,
    EVENT_THUNDERCLAP           = 3,
    EVENT_VOIDBOLT              = 4,
    EVENT_MARK_OF_KAZZAK        = 5,
    EVENT_ENRAGE                = 6,
    EVENT_TWISTED_REFLECTION    = 7
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
                _events.ScheduleEvent(EVENT_VOIDBOLT, 30000);
                _events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 25000);
                _events.ScheduleEvent(EVENT_ENRAGE, 60000);
                _events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 33000);
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

                DoCast(me, SPELL_CAPTURESOUL);

                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*victim*/)
            {
                Talk(SAY_DEATH);
            }

            void UpdateAI(uint32 const diff)
            {
                // Return since we have no target
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while(uint32 eventId = _events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_SHADOW_VOLLEY:
                            DoCastVictim(SPELL_SHADOWVOLLEY);
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
                        case EVENT_VOIDBOLT:
                            DoCastVictim(SPELL_VOIDBOLT);
                            _events.ScheduleEvent(EVENT_VOIDBOLT, urand(15000, 18000));
                            break;
                        case EVENT_MARK_OF_KAZZAK:
                            std::list<Unit*> targetList;
                            {
                                const std::list<HostileReference*>& threatlist = me->getThreatManager().getThreatList();
                                for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                                    if ((*itr)->getTarget()->GetTypeId() == TYPEID_PLAYER && (*itr)->getTarget()->getPowerType() == POWER_MANA)
                                        targetList.push_back((*itr)->getTarget());
                            }

                            std::list<Unit*>::iterator itr = targetList.begin();
                            advance(itr, urand(0, targetList.size()-1));
                            DoCast(*itr, SPELL_MARKOFKAZZAK);
                            _events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 20000);
                            break;
                        case EVENT_ENRAGE:
                            Talk(EMOTE_FRENZY);
                            DoCast(me, SPELL_ENRAGE);
                            _events.ScheduleEvent(EVENT_ENRAGE, 30000);
                            break;
                        case EVENT_TWISTED_REFLECTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_TWISTEDREFLECTION);
                            _events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 15000);
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

class spell_doomlord_kazzak_mark_of_kazzak : public SpellScriptLoader
{
    public:
        spell_doomlord_kazzak_mark_of_kazzak() : SpellScriptLoader("spell_doomlord_kazzak_mark_of_kazzak") { }

        class spell_doomlord_kazzak_mark_of_kazzak_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_doomlord_kazzak_mark_of_kazzak_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();

                int32 curmana = GetHitUnit()->GetPower(POWER_MANA);
                int32 maxmana = GetHitUnit()->GetMaxPower(POWER_MANA);

                // If mana is above 5 procent, drain. Otherwise cast 32961 (player on self with Doomlord Kazzak as casterguid)
                if (curmana * 100 > maxmana * 5)
                    GetHitUnit()->ModifyPower(POWER_MANA, -5);
                else
                    GetHitUnit()->CastSpell(GetHitUnit(), SPELL_MARKOFKAZZAK_DAMAGE, true, NULL, NULL, GetCasterGUID());
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_doomlord_kazzak_mark_of_kazzak_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_MANA_LEECH);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_doomlord_kazzak_mark_of_kazzak_AuraScript();
        }
};

void AddSC_boss_doomlordkazzak()
{
    new boss_doomlord_kazzak();
    new spell_doomlord_kazzak_mark_of_kazzak();
}
