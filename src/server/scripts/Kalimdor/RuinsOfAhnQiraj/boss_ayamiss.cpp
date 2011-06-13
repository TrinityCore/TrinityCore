/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
 
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ruins_of_ahnqiraj.h"

enum eAyamiss
{
    SPELL_STINGERSPRAY          =  25749,
    SPELL_POISONSTINGER         =  25748,                          //only used in phase1
    SPELL_PARALYZE              =  25725,
    SPELL_TRASH                 =  3391,
    SPELL_FRENZY                =  8269,
    SPELL_LASH                  =  25852,

    EMOTE_FRENZY                =  -1000002,

    SPELL_FEED                  =  25721,
};

class boss_ayamiss : public CreatureScript
{
    public:
        boss_ayamiss() : CreatureScript("boss_ayamiss") { }

        struct boss_ayamissAI : public ScriptedAI
        {
            boss_ayamissAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            uint32 STINGERSPRAY_Timer;
            uint32 POISONSTINGER_Timer;
            uint32 SUMMONSWARMER_Timer;
            uint32 phase;

            InstanceScript* instance;

            void Reset()
            {
                STINGERSPRAY_Timer = 30000;
                POISONSTINGER_Timer = 30000;
                SUMMONSWARMER_Timer = 60000;
                phase = 1;

            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                //If he is 70% start phase 2
                if (phase == 1 && !HealthAbovePct(70) && !me->IsNonMeleeSpellCasted(false))
                {
                    phase=2;
                }

                //STINGERSPRAY_Timer (only in phase2)
                if (phase == 2 && STINGERSPRAY_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_STINGERSPRAY);
                    STINGERSPRAY_Timer = 30000;
                } else STINGERSPRAY_Timer -= diff;

                //POISONSTINGER_Timer (only in phase1)
                if (phase == 1 && POISONSTINGER_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_POISONSTINGER);
                    POISONSTINGER_Timer = 30000;
                } else POISONSTINGER_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_ayamissAI (creature);
        }
};

void AddSC_boss_ayamiss()
{
    new boss_ayamiss();
}
