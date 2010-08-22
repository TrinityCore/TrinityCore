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
SDName: Boss_Halycon
SD%Complete: 100
SDComment:
SDCategory: Blackrock Spire
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_CROWDPUMMEL       10887
#define SPELL_MIGHTYBLOW        14099

#define ADD_1X                  -169.839203f
#define ADD_1Y                  -324.961395f
#define ADD_1Z                  64.401443f
#define ADD_1O                  3.124724f

class boss_halycon : public CreatureScript
{
public:
    boss_halycon() : CreatureScript("boss_halycon") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_halyconAI (pCreature);
    }

    struct boss_halyconAI : public ScriptedAI
    {
        boss_halyconAI(Creature *c) : ScriptedAI(c) {}

        uint32 CrowdPummel_Timer;
        uint32 MightyBlow_Timer;
        bool Summoned;

        void Reset()
        {
            CrowdPummel_Timer = 8000;
            MightyBlow_Timer = 14000;
            Summoned = false;
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //CrowdPummel_Timer
            if (CrowdPummel_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CROWDPUMMEL);
                CrowdPummel_Timer = 14000;
            } else CrowdPummel_Timer -= diff;

            //MightyBlow_Timer
            if (MightyBlow_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MIGHTYBLOW);
                MightyBlow_Timer = 10000;
            } else MightyBlow_Timer -= diff;

            //Summon Gizrul
            if (!Summoned && me->GetHealth()*100 / me->GetMaxHealth() < 25)
            {
                me->SummonCreature(10268,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,300000);
                Summoned = true;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_halycon()
{
    new boss_halycon();
}
