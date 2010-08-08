/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Rend_Blackhand
SD%Complete: 100
SDComment: Intro event NYI
SDCategory: Blackrock Spire
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_WHIRLWIND                 26038
#define SPELL_CLEAVE                    20691
#define SPELL_THUNDERCLAP               23931               //Not sure if he cast this spell

class boss_rend_blackhand : public CreatureScript
{
public:
    boss_rend_blackhand() : CreatureScript("boss_rend_blackhand") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_rend_blackhandAI (pCreature);
    }

    struct boss_rend_blackhandAI : public ScriptedAI
    {
        boss_rend_blackhandAI(Creature *c) : ScriptedAI(c) {}

        uint32 WhirlWind_Timer;
        uint32 Cleave_Timer;
        uint32 Thunderclap_Timer;

        void Reset()
        {
            WhirlWind_Timer = 20000;
            Cleave_Timer = 5000;
            Thunderclap_Timer = 9000;
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //WhirlWind_Timer
            if (WhirlWind_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_WHIRLWIND);
                WhirlWind_Timer = 18000;
            } else WhirlWind_Timer -= diff;

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = 10000;
            } else Cleave_Timer -= diff;

            //Thunderclap_Timer
            if (Thunderclap_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_THUNDERCLAP);
                Thunderclap_Timer = 16000;
            } else Thunderclap_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_rend_blackhand()
{
    new boss_rend_blackhand();
}
