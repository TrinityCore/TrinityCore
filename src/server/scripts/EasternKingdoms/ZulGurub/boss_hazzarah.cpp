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
SDName: Boss_Hazzarah
SD%Complete: 100
SDComment:
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"

#define SPELL_MANABURN         26046
#define SPELL_SLEEP            24664

class boss_hazzarah : public CreatureScript
{
    public:

        boss_hazzarah()
            : CreatureScript("boss_hazzarah")
        {
        }

        struct boss_hazzarahAI : public ScriptedAI
        {
            boss_hazzarahAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 ManaBurn_Timer;
            uint32 Sleep_Timer;
            uint32 Illusions_Timer;

            void Reset()
            {
                ManaBurn_Timer = urand(4000, 10000);
                Sleep_Timer = urand(10000, 18000);
                Illusions_Timer = urand(10000, 18000);
            }

            void EnterCombat(Unit* /*who*/)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                //ManaBurn_Timer
                if (ManaBurn_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_MANABURN);
                    ManaBurn_Timer = urand(8000, 16000);
                } else ManaBurn_Timer -= diff;

                //Sleep_Timer
                if (Sleep_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SLEEP);
                    Sleep_Timer = urand(12000, 20000);
                } else Sleep_Timer -= diff;

                //Illusions_Timer
                if (Illusions_Timer <= diff)
                {
                    //We will summon 3 illusions that will spawn on a random gamer and attack this gamer
                    //We will just use one model for the beginning
                    Unit* target = NULL;
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        if (!target)
                            return;

                        Creature* Illusion = me->SummonCreature(15163, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                        if (Illusion)
                            Illusion->AI()->AttackStart(target);
                    }

                    Illusions_Timer = urand(15000, 25000);
                } else Illusions_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_hazzarahAI(creature);
        }
};

void AddSC_boss_hazzarah()
{
    new boss_hazzarah();
}

