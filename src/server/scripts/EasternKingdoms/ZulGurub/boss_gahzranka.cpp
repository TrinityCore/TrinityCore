/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Gahz'ranka
SD%Complete: 85
SDComment: Massive Geyser with knockback not working. Spell buggy.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#define SPELL_FROSTBREATH            16099
#define SPELL_MASSIVEGEYSER          22421                  //Not working. Cause its a summon...
#define SPELL_SLAM                   24326

class boss_gahzranka : public CreatureScript
{
    public:
        boss_gahzranka() : CreatureScript("boss_gahzranka") { }

        struct boss_gahzrankaAI : public ScriptedAI
        {
            boss_gahzrankaAI(Creature* creature) : ScriptedAI(creature) { }
            uint32 Frostbreath_Timer;
            uint32 MassiveGeyser_Timer;
            uint32 Slam_Timer;

            void Reset()
            {
                Frostbreath_Timer = 8000;
                MassiveGeyser_Timer = 25000;
                Slam_Timer = 17000;
            }

            void EnterCombat(Unit* /*who*/)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //Frostbreath_Timer
                if (Frostbreath_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_FROSTBREATH);
                    Frostbreath_Timer = urand(7000, 11000);
                } else Frostbreath_Timer -= diff;

                //MassiveGeyser_Timer
                if (MassiveGeyser_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_MASSIVEGEYSER);
                    DoResetThreat();

                    MassiveGeyser_Timer = urand(22000, 32000);
                } else MassiveGeyser_Timer -= diff;

                //Slam_Timer
                if (Slam_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SLAM);
                    Slam_Timer = urand(12000, 20000);
                } else Slam_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_gahzrankaAI(creature);
        }
};

void AddSC_boss_gahzranka()
{
    new boss_gahzranka();
}

