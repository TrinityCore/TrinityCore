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
SDName: Boss_Magmus
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "ScriptPCH.h"

enum Spells
{
    SPELL_FIERYBURST                                       = 13900,
    SPELL_WARSTOMP                                         = 24375
};

enum eEnums
{
    DATA_THRONE_DOOR                              = 24 // not id or guid of doors but number of enum in blackrock_depths.h
};

class boss_magmus : public CreatureScript
{
public:
    boss_magmus() : CreatureScript("boss_magmus") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_magmusAI (pCreature);
    }

    struct boss_magmusAI : public ScriptedAI
    {
        boss_magmusAI(Creature* c) : ScriptedAI(c) {}

        uint32 FieryBurst_Timer;
        uint32 WarStomp_Timer;

        void Reset()
        {
            FieryBurst_Timer = 5000;
            WarStomp_Timer =0;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //FieryBurst_Timer
            if (FieryBurst_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FIERYBURST);
                FieryBurst_Timer = 6000;
            } else FieryBurst_Timer -= diff;

            //WarStomp_Timer
            if (HealthBelowPct(51))
            {
                if (WarStomp_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_WARSTOMP);
                    WarStomp_Timer = 8000;
                } else WarStomp_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
        // When he die open door to last chamber
        void JustDied(Unit* who)
        {
            if (InstanceScript* pInstance = who->GetInstanceScript())
                pInstance->HandleGameObject(pInstance->GetData64(DATA_THRONE_DOOR), true);
        }
    };

};

void AddSC_boss_magmus()
{
    new boss_magmus();
}
