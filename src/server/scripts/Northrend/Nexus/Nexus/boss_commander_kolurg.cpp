/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/* Script Data Start
SDName: Boss Commander Kolurg
SDAuthor: LordVanMartin
SD%Complete:
SDComment:  Only Alliance Heroic
SDCategory:
Script Data End */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#define SPELL_BATTLE_SHOUT                                    31403
#define SPELL_CHARGE                                          60067
#define SPELL_FRIGHTENING_SHOUT                               19134
#define SPELL_WHIRLWIND_1                                     38619
#define SPELL_WHIRLWIND_2                                     38618

//not used
//Yell
#define SAY_AGGRO                                          -1576024
#define SAY_KILL                                           -1576025
#define SAY_DEATH                                          -1576026

class boss_commander_kolurg : public CreatureScript
{
public:
    boss_commander_kolurg() : CreatureScript("boss_commander_kolurg") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_commander_kolurgAI (creature);
    }

    struct boss_commander_kolurgAI : public ScriptedAI
    {
        boss_commander_kolurgAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() {}
        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void UpdateAI(uint32 /*diff*/)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
        void JustDied(Unit* /*killer*/)  {}
    };

};

void AddSC_boss_commander_kolurg()
{
    new boss_commander_kolurg();
}
