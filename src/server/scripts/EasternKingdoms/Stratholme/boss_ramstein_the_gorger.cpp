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
SDName: Boss_Ramstein_The_Gorger
SD%Complete: 70
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptPCH.h"
#include "stratholme.h"

#define SPELL_TRAMPLE       5568
#define SPELL_KNOCKOUT    17307

 #define C_MINDLESS_UNDEAD   11030

class boss_ramstein_the_gorger : public CreatureScript
{
public:
    boss_ramstein_the_gorger() : CreatureScript("boss_ramstein_the_gorger") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ramstein_the_gorgerAI (pCreature);
    }

    struct boss_ramstein_the_gorgerAI : public ScriptedAI
    {
        boss_ramstein_the_gorgerAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = me->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 Trample_Timer;
        uint32 Knockout_Timer;

        void Reset()
        {
            Trample_Timer = 3000;
            Knockout_Timer = 12000;
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void JustDied(Unit* /*Killer*/)
        {
            for (uint8 i = 0; i < 30; ++i)
            {
                if (Creature* mob = me->SummonCreature(C_MINDLESS_UNDEAD,3969.35f+irand(-10,10),-3391.87f+irand(-10,10),119.11f,5.91f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,1800000))
                    mob->AI()->AttackStart(me->SelectNearestTarget(500));
            }

            if (pInstance)
                pInstance->SetData(TYPE_RAMSTEIN,DONE);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Trample
            if (Trample_Timer <= diff)
            {
                DoCast(me, SPELL_TRAMPLE);
                Trample_Timer = 7000;
            } else Trample_Timer -= diff;

            //Knockout
            if (Knockout_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_KNOCKOUT);
                Knockout_Timer = 10000;
            } else Knockout_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_ramstein_the_gorger()
{
    new boss_ramstein_the_gorger();
}
