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

/* ScriptData
SDName: Boss_Doomlord_Kazzak
SD%Complete: 70
SDComment: Using incorrect spell for Mark of Kazzak
SDCategory: Hellfire Peninsula
EndScriptData */

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
                events.Reset();
                events.ScheduleEvent(EVENT_SHADOW_VOLLEY, urand(6000, 10000));
                events.ScheduleEvent(EVENT_CLEAVE, 7000);
                events.ScheduleEvent(EVENT_THUNDERCLAP, urand(14000, 18000));
                events.ScheduleEvent(EVENT_VOIDBOLT, 30000);
                events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 25000);
                events.ScheduleEvent(EVENT_ENRAGE, 60000);
                events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 33000);
            }

            void JustRespawned()
            {
                Talk(SAY_INTRO);
            }

            void EnterCombat(Unit * /*who*/)
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

            void JustDied(Unit * /*victim*/)
            {
                Talk(SAY_DEATH);
            }

            void UpdateAI(const uint32 diff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;
                    
                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
                    
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_SHADOW_VOLLEY:
                            DoCastVictim(SPELL_SHADOWVOLLEY);
                            events.ScheduleEvent(EVENT_SHADOW_VOLLEY, urand(4000, 6000));
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 12000));
                            break;
                        case EVENT_THUNDERCLAP:
                            DoCastVictim(SPELL_THUNDERCLAP);
                            events.ScheduleEvent(EVENT_THUNDERCLAP, urand(10000, 14000));
                            break;
                        case EVENT_VOIDBOLT:
                            DoCastVictim(SPELL_VOIDBOLT);
                            events.ScheduleEvent(EVENT_VOIDBOLT, urand(15000, 18000));
                            break;
                        case EVENT_MARK_OF_KAZZAK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                if (target->GetPower(POWER_MANA))
                                    DoCast(target, SPELL_MARKOFKAZZAK);
                            events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 20000);
                            break;
                        case EVENT_ENRAGE:
                            Talk(EMOTE_FRENZY);
                            DoCast(me, SPELL_ENRAGE);
                            events.ScheduleEvent(EVENT_ENRAGE, 30000);
                            break;
                        case EVENT_TWISTED_REFLECTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_TWISTEDREFLECTION);
                            events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 15000);
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
    
        CreatureAI *GetAI(Creature* creature) const
        {
            return new boss_doomlordkazzakAI (creature);
        }
};

void AddSC_boss_doomlordkazzak()
{
    new boss_doomlord_kazzak();
}
