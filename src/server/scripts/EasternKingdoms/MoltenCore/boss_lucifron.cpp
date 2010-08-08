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
SDName: Boss_Lucifron
SD%Complete: 100
SDComment:
SDCategory: Molten Core
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_IMPENDINGDOOM 19702
#define SPELL_LUCIFRONCURSE 19703
#define SPELL_SHADOWSHOCK   20603

class boss_lucifron : public CreatureScript
{
public:
    boss_lucifron() : CreatureScript("boss_lucifron") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_lucifronAI (pCreature);
    }

    struct boss_lucifronAI : public ScriptedAI
    {
        boss_lucifronAI(Creature *c) : ScriptedAI(c) {}

        uint32 ImpendingDoom_Timer;
        uint32 LucifronCurse_Timer;
        uint32 ShadowShock_Timer;

        void Reset()
        {
            ImpendingDoom_Timer = 10000;                        //Initial cast after 10 seconds so the debuffs alternate
            LucifronCurse_Timer = 20000;                        //Initial cast after 20 seconds
            ShadowShock_Timer = 6000;                           //6 seconds
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //Impending doom timer
            if (ImpendingDoom_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_IMPENDINGDOOM);
                ImpendingDoom_Timer = 20000;
            } else ImpendingDoom_Timer -= diff;

            //Lucifron's curse timer
            if (LucifronCurse_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_LUCIFRONCURSE);
                LucifronCurse_Timer = 15000;
            } else LucifronCurse_Timer -= diff;

            //Shadowshock
            if (ShadowShock_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SHADOWSHOCK);
                ShadowShock_Timer = 6000;
            } else ShadowShock_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_lucifron()
{
    new boss_lucifron();
}
