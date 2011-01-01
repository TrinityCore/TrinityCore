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
SDName: Boss_The_Best
SD%Complete: 100
SDComment:
SDCategory: Blackrock Spire
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_FLAMEBREAK            16785
#define SPELL_IMMOLATE              20294
#define SPELL_TERRIFYINGROAR        14100

class boss_the_beast : public CreatureScript
{
public:
    boss_the_beast() : CreatureScript("boss_the_beast") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_thebeastAI (pCreature);
    }

    struct boss_thebeastAI : public ScriptedAI
    {
        boss_thebeastAI(Creature *c) : ScriptedAI(c) {}

        uint32 Flamebreak_Timer;
        uint32 Immolate_Timer;
        uint32 TerrifyingRoar_Timer;

        void Reset()
        {
            Flamebreak_Timer = 12000;
            Immolate_Timer = 3000;
            TerrifyingRoar_Timer = 23000;
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Flamebreak_Timer
            if (Flamebreak_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FLAMEBREAK);
                Flamebreak_Timer = 10000;
            } else Flamebreak_Timer -= diff;

            //Immolate_Timer
            if (Immolate_Timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_IMMOLATE);
                Immolate_Timer = 8000;
            } else Immolate_Timer -= diff;

            //TerrifyingRoar_Timer
            if (TerrifyingRoar_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_TERRIFYINGROAR);
                TerrifyingRoar_Timer = 20000;
            } else TerrifyingRoar_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_thebeast()
{
    new boss_the_beast();
}
