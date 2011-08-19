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
SDName: boss_postmaster_malown
SD%Complete: 50
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptPCH.h"

//Spell ID to summon this guy is 24627 "Summon Postmaster Malown"
//He should be spawned along with three other elites once the third postbox has been opened

#define SAY_MALOWNED    "You just got MALOWNED!"

#define SPELL_WAILINGDEAD    7713
#define SPELL_BACKHAND    6253
#define SPELL_CURSEOFWEAKNESS    8552
#define SPELL_CURSEOFTONGUES    12889
#define SPELL_CALLOFTHEGRAVE    17831

class boss_postmaster_malown : public CreatureScript
{
public:
    boss_postmaster_malown() : CreatureScript("boss_postmaster_malown") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_postmaster_malownAI (creature);
    }

    struct boss_postmaster_malownAI : public ScriptedAI
    {
        boss_postmaster_malownAI(Creature* c) : ScriptedAI(c) {}

        uint32 WailingDead_Timer;
        uint32 Backhand_Timer;
        uint32 CurseOfWeakness_Timer;
        uint32 CurseOfTongues_Timer;
        uint32 CallOfTheGrave_Timer;
        bool HasYelled;

        void Reset()
        {
            WailingDead_Timer = 19000; //lasts 6 sec
            Backhand_Timer = 8000; //2 sec stun
            CurseOfWeakness_Timer = 20000; //lasts 2 mins
            CurseOfTongues_Timer = 22000;
            CallOfTheGrave_Timer = 25000;
            HasYelled = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //WailingDead
            if (WailingDead_Timer <= diff)
            {
                //Cast
                if (rand()%100 < 65) //65% chance to cast
                {
                    DoCast(me->getVictim(), SPELL_WAILINGDEAD);
                }
                //19 seconds until we should cast this again
                WailingDead_Timer = 19000;
            } else WailingDead_Timer -= diff;

            //Backhand
            if (Backhand_Timer <= diff)
            {
                //Cast
                if (rand()%100 < 45) //45% chance to cast
                {
                    DoCast(me->getVictim(), SPELL_BACKHAND);
                }
                //8 seconds until we should cast this again
                Backhand_Timer = 8000;
            } else Backhand_Timer -= diff;

            //CurseOfWeakness
            if (CurseOfWeakness_Timer <= diff)
            {
                //Cast
                if (rand()%100 < 3) //3% chance to cast
                {
                    DoCast(me->getVictim(), SPELL_CURSEOFWEAKNESS);
                }
                //20 seconds until we should cast this again
                CurseOfWeakness_Timer = 20000;
            } else CurseOfWeakness_Timer -= diff;

            //CurseOfTongues
            if (CurseOfTongues_Timer <= diff)
            {
                //Cast
                if (rand()%100 < 3) //3% chance to cast
                {
                    DoCast(me->getVictim(), SPELL_CURSEOFTONGUES);
                }
                //22 seconds until we should cast this again
                CurseOfTongues_Timer = 22000;
            } else CurseOfTongues_Timer -= diff;

            //CallOfTheGrave
            if (CallOfTheGrave_Timer <= diff)
            {
                //Cast
                if (rand()%100 < 5) //5% chance to cast
                {
                    DoCast(me->getVictim(), SPELL_CALLOFTHEGRAVE);
                }
                //25 seconds until we should cast this again
                CallOfTheGrave_Timer = 25000;
            } else CallOfTheGrave_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_postmaster_malown()
{
    new boss_postmaster_malown();
}
