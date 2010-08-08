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
SDName: Boss_instructormalicia
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptPCH.h"
#include "scholomance.h"

#define SPELL_CALLOFGRAVES         17831
#define SPELL_CORRUPTION           11672
#define SPELL_FLASHHEAL            10917
#define SPELL_RENEW                10929
#define SPELL_HEALINGTOUCH         9889
class boss_instructor_malicia : public CreatureScript
{
public:
    boss_instructor_malicia() : CreatureScript("boss_instructor_malicia") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_instructormaliciaAI (pCreature);
    }

    struct boss_instructormaliciaAI : public ScriptedAI
    {
        boss_instructormaliciaAI(Creature *c) : ScriptedAI(c) {}

        uint32 CallOfGraves_Timer;
        uint32 Corruption_Timer;
        uint32 FlashHeal_Timer;
        uint32 Renew_Timer;
        uint32 HealingTouch_Timer;
        uint32 FlashCounter;
        uint32 TouchCounter;

        void Reset()
        {
            CallOfGraves_Timer = 4000;
            Corruption_Timer = 8000;
            FlashHeal_Timer = 38000;
            Renew_Timer = 32000;
            HealingTouch_Timer = 45000;
            FlashCounter = 0;
            TouchCounter = 0;
        }

        void JustDied(Unit * /*killer*/)
        {
            InstanceScript *pInstance = me->GetInstanceScript();
            if (pInstance)
            {
                pInstance->SetData(DATA_INSTRUCTORMALICIA_DEATH, 0);

                if (pInstance->GetData(TYPE_GANDLING) == IN_PROGRESS)
                    me->SummonCreature(1853, 180.73, -9.43856, 75.507, 1.61399, TEMPSUMMON_DEAD_DESPAWN, 0);
            }
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //CallOfGraves_Timer
            if (CallOfGraves_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CALLOFGRAVES);
                CallOfGraves_Timer = 65000;
            } else CallOfGraves_Timer -= diff;

            //Corruption_Timer
            if (Corruption_Timer <= diff)
            {
                Unit *pTarget = NULL;
                pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (pTarget) DoCast(pTarget, SPELL_CORRUPTION);

                Corruption_Timer = 24000;
            } else Corruption_Timer -= diff;

            //Renew_Timer
            if (Renew_Timer <= diff)
            {
                DoCast(me, SPELL_RENEW);
                Renew_Timer = 10000;
            } else Renew_Timer -= diff;

            //FlashHeal_Timer
            if (FlashHeal_Timer <= diff)
            {
                DoCast(me, SPELL_FLASHHEAL);

                //5 Flashheals will be casted
                if (FlashCounter < 2)
                {
                    FlashHeal_Timer = 5000;
                    ++FlashCounter;
                }
                else
                {
                    FlashCounter=0;
                    FlashHeal_Timer = 30000;
                }
            } else FlashHeal_Timer -= diff;

            //HealingTouch_Timer
            if (HealingTouch_Timer <= diff)
            {
                DoCast(me, SPELL_HEALINGTOUCH);

                //3 Healingtouchs will be casted
                if (HealingTouch_Timer < 2)
                {
                    HealingTouch_Timer = 5500;
                    ++TouchCounter;
                }
                else
                {
                    TouchCounter=0;
                    HealingTouch_Timer = 30000;
                }
            } else HealingTouch_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_instructormalicia()
{
    new boss_instructor_malicia();
}
