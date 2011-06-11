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
SDName: The_Eye
SD%Complete: 100
SDComment:
SDCategory: Tempest Keep, The Eye
EndScriptData */

/* ContentData
mob_crystalcore_devastator
EndContentData */

#include "ScriptPCH.h"
#include "the_eye.h"

enum eSpells
{
    SPELL_COUNTERCHARGE    = 35035,
    SPELL_KNOCKAWAY        = 22893,
};

class mob_crystalcore_devastator : public CreatureScript
{
    public:

        mob_crystalcore_devastator()
            : CreatureScript("mob_crystalcore_devastator")
        {
        }
        struct mob_crystalcore_devastatorAI : public ScriptedAI
        {
            mob_crystalcore_devastatorAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 Knockaway_Timer;
            uint32 Countercharge_Timer;

            void Reset()
            {
                Countercharge_Timer = 9000;
                Knockaway_Timer = 25000;
            }

            void EnterCombat(Unit* /*who*/)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                //Check if we have a current target
                //Knockaway_Timer
                if (Knockaway_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_KNOCKAWAY, true);

                    // current aggro target is knocked away pick new target
                    Unit* pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO, 0);

                    if (!pTarget || pTarget == me->getVictim())
                        pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO, 1);

                    if (pTarget)
                        me->TauntApply(pTarget);

                    Knockaway_Timer = 23000;
                }
                else
                    Knockaway_Timer -= diff;

                //Countercharge_Timer
                if (Countercharge_Timer <= diff)
                {
                    DoCast(me, SPELL_COUNTERCHARGE);
                    Countercharge_Timer = 45000;
                }
                else
                    Countercharge_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_crystalcore_devastatorAI(creature);
        }
};
void AddSC_the_eye()
{
    new mob_crystalcore_devastator();
}

