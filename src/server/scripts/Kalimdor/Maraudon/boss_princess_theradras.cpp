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
SDName: Boss_Princess_Theradras
SD%Complete: 100
SDComment:
SDCategory: Maraudon
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_DUSTFIELD             21909
#define SPELL_BOULDER               21832
#define SPELL_THRASH                3391
#define SPELL_REPULSIVEGAZE         21869
class boss_princess_theradras : public CreatureScript
{
public:
    boss_princess_theradras() : CreatureScript("boss_princess_theradras") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ptheradrasAI (pCreature);
    }

    struct boss_ptheradrasAI : public ScriptedAI
    {
        boss_ptheradrasAI(Creature *c) : ScriptedAI(c) {}

        uint32 Dustfield_Timer;
        uint32 Boulder_Timer;
        uint32 Thrash_Timer;
        uint32 RepulsiveGaze_Timer;

        void Reset()
        {
            Dustfield_Timer = 8000;
            Boulder_Timer = 2000;
            Thrash_Timer = 5000;
            RepulsiveGaze_Timer = 23000;
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void JustDied(Unit* /*killer*/)
        {
            me->SummonCreature(12238,28.067,61.875,-123.405,4.67,TEMPSUMMON_TIMED_DESPAWN,600000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //Dustfield_Timer
            if (Dustfield_Timer <= diff)
            {
                DoCast(me, SPELL_DUSTFIELD);
                Dustfield_Timer = 14000;
            } else Dustfield_Timer -= diff;

            //Boulder_Timer
            if (Boulder_Timer <= diff)
            {
                Unit *pTarget = NULL;
                pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (pTarget)
                    DoCast(pTarget, SPELL_BOULDER);
                Boulder_Timer = 10000;
            } else Boulder_Timer -= diff;

            //RepulsiveGaze_Timer
            if (RepulsiveGaze_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_REPULSIVEGAZE);
                RepulsiveGaze_Timer = 20000;
            } else RepulsiveGaze_Timer -= diff;

            //Thrash_Timer
            if (Thrash_Timer <= diff)
            {
                DoCast(me, SPELL_THRASH);
                Thrash_Timer = 18000;
            } else Thrash_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_ptheradras()
{
    new boss_princess_theradras();
}
