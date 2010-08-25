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
SDName: Boss_Ironaya
SD%Complete: 100
SDComment:
SDCategory: Uldaman
EndScriptData */

#include "ScriptPCH.h"

#define SAY_AGGRO                   -1070000

#define SPELL_ARCINGSMASH           8374
#define SPELL_KNOCKAWAY             10101
#define SPELL_WSTOMP                11876

class boss_ironaya : public CreatureScript
{
    public:

        boss_ironaya()
            : CreatureScript("boss_ironaya")
        {
        }

        struct boss_ironayaAI : public ScriptedAI
        {
            boss_ironayaAI(Creature *c) : ScriptedAI(c) {}

            uint32 Arcing_Timer;
            bool hasCastedWstomp;
            bool hasCastedKnockaway;

            void Reset()
            {
                Arcing_Timer = 3000;
                hasCastedKnockaway = false;
                hasCastedWstomp = false;
            }

            void EnterCombat(Unit * /*who*/)
            {
                DoScriptText(SAY_AGGRO, me);
            }

            void UpdateAI(const uint32 diff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //If we are <50% hp do knockaway ONCE
                if (!hasCastedKnockaway && HealthBelowPct(50))
                {
                    DoCast(me->getVictim(), SPELL_KNOCKAWAY, true);

                    // current aggro target is knocked away pick new target
                    Unit* Target = SelectUnit(SELECT_TARGET_TOPAGGRO, 0);

                    if (!Target || Target == me->getVictim())
                        Target = SelectUnit(SELECT_TARGET_TOPAGGRO, 1);

                    if (Target)
                        me->TauntApply(Target);

                    //Shouldn't cast this agian
                    hasCastedKnockaway = true;
                }

                //Arcing_Timer
                if (Arcing_Timer <= diff)
                {
                    DoCast(me, SPELL_ARCINGSMASH);
                    Arcing_Timer = 13000;
                } else Arcing_Timer -= diff;

                if (!hasCastedWstomp && HealthBelowPct(25))
                {
                    DoCast(me, SPELL_WSTOMP);
                    hasCastedWstomp = true;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_ironayaAI(creature);
        }
};

//This is the actual function called only once durring InitScripts()
//It must define all handled functions that are to be run in this script
void AddSC_boss_ironaya()
{
    new boss_ironaya();
}