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
#include "vault_of_archavon.h"

enum Events
{
    EVENT_NULL,
    // Koralon
    EVENT_BURNING_BREATH,
    EVENT_BURNING_FURY,
    EVENT_FLAME_CINDER,
    EVENT_METEOR_FISTS,

    // Flame Warder
    EVENT_FW_LAVA_BIRST,
    EVENT_FW_METEOR_FISTS_A,
    EVENT_FW_METEOR_FISTS_B,
};

enum Spells
{
    // Spells Koralon
    SPELL_BURNING_BREATH                        = 66665,
    SPELL_BURNING_FURY                          = 66721,
    SPELL_FLAME_CINDER                          = 66684,
    SPELL_FLAME_CINDER_B                        = 66681, // don't know the real relation to SPELL_FLAME_CINDER_A atm.
    SPELL_METEOR_FISTS                          = 66725,

    // Spells Flame Warder
    SPELL_FW_LAVA_BIRST                         = 66813,
    SPELL_FW_METEOR_FISTS_A                     = 66808,
    SPELL_FW_METEOR_FISTS_B                     = 67331,
};

#define EMOTE_METEOR_FISTS                      "Koralon the Flame Watcher casts Meteor Fists!"

class boss_koralon : public CreatureScript
{
    public:
        boss_koralon() : CreatureScript("boss_koralon") { }

        struct boss_koralonAI : public BossAI
        {
            boss_koralonAI(Creature* creature) : BossAI(creature, DATA_KORALON)
            {
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();

                DoCast(me, SPELL_BURNING_FURY);

                events.ScheduleEvent(EVENT_BURNING_FURY, 20000);
                events.ScheduleEvent(EVENT_BURNING_BREATH, 15000);
                events.ScheduleEvent(EVENT_METEOR_FISTS, 35000);
                events.ScheduleEvent(EVENT_FLAME_CINDER, 25000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BURNING_FURY:
                            DoCast(me, SPELL_BURNING_FURY);
                            events.ScheduleEvent(EVENT_BURNING_FURY, 20000);
                            break;
                        case EVENT_BURNING_BREATH:
                            DoCast(me, SPELL_BURNING_BREATH);
                            events.ScheduleEvent(EVENT_BURNING_BREATH, 45000);
                            break;
                        case EVENT_METEOR_FISTS:
                            DoCast(me, SPELL_METEOR_FISTS);
                            me->MonsterTextEmote(EMOTE_METEOR_FISTS, 0, true);
                            events.ScheduleEvent(EVENT_METEOR_FISTS, 45000);
                            break;
                        case EVENT_FLAME_CINDER:
                            DoCast(me, SPELL_FLAME_CINDER);
                            events.ScheduleEvent(EVENT_FLAME_CINDER, 25000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_koralonAI(creature);
        }
};

/*######
##  Mob Flame Warder
######*/
class mob_flame_warder : public CreatureScript
{
    public:
        mob_flame_warder() : CreatureScript("mob_flame_warder") { }

        struct mob_flame_warderAI : public ScriptedAI
        {
            mob_flame_warderAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoZoneInCombat();

                events.ScheduleEvent(EVENT_FW_LAVA_BIRST, 5000);
                events.ScheduleEvent(EVENT_FW_METEOR_FISTS_A, 10000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FW_LAVA_BIRST:
                            DoCastVictim(SPELL_FW_LAVA_BIRST);
                            events.ScheduleEvent(EVENT_FW_LAVA_BIRST, 15000);
                            break;
                        case EVENT_FW_METEOR_FISTS_A:
                            DoCast(me, SPELL_FW_METEOR_FISTS_A);
                            events.ScheduleEvent(EVENT_FW_METEOR_FISTS_B, 1500);
                            break;
                        case EVENT_FW_METEOR_FISTS_B:
                            DoCast(me, SPELL_FW_METEOR_FISTS_B);
                            events.ScheduleEvent(EVENT_FW_METEOR_FISTS_A, 20000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_flame_warderAI(creature);
        }
};

class spell_koralon_meteor_fists : public SpellScriptLoader
{
    public:
        spell_koralon_meteor_fists() : SpellScriptLoader("spell_koralon_meteor_fists") { }

        class spell_koralon_meteor_fists_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_koralon_meteor_fists_SpellScript);

            uint32 totalTargets;

            void FilterTargets(std::list<Unit*>& unitList)
            {
                totalTargets = NULL;
                for (std::list<Unit*>::iterator itr = unitList.begin() ; itr != unitList.end(); ++itr)
                {
                    Unit *target = (*itr);
                    if (!target)
                        continue;

                    if (!target->IsWithinDist(GetExplTargetUnit(), 10.0f))
                    {
                        unitList.remove(target);
                        continue;
                    }
                    
                    totalTargets++;
                }
            }

            void CalculateSplitDamage()
            {
                if (totalTargets)
                    SetHitDamage(GetHitDamage() / totalTargets);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_koralon_meteor_fists_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_TARGET_ENEMY);
                OnHit += SpellHitFn(spell_koralon_meteor_fists_SpellScript::CalculateSplitDamage);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_koralon_meteor_fists_SpellScript();
        }
};

void AddSC_boss_koralon()
{
    new boss_koralon();
    new mob_flame_warder();
    new spell_koralon_meteor_fists();
}
