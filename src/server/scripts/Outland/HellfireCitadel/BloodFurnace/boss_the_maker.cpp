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
SDName: Boss_The_Maker
SD%Complete: 80
SDComment: Mind control no support
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

#include "ScriptPCH.h"
#include "blood_furnace.h"

enum eEnums
{
    SAY_AGGRO_1                 = -1542009,
    SAY_AGGRO_2                 = -1542010,
    SAY_AGGRO_3                 = -1542011,
    SAY_KILL_1                  = -1542012,
    SAY_KILL_2                  = -1542013,
    SAY_DIE                     = -1542014,

    SPELL_ACID_SPRAY            = 38153,                    // heroic 38973 ??? 38153
    SPELL_EXPLODING_BREAKER     = 30925,
    SPELL_KNOCKDOWN             = 20276,
    SPELL_DOMINATION            = 25772                     // ???
};

class boss_the_maker : public CreatureScript
{
    public:

        boss_the_maker()
            : CreatureScript("boss_the_maker")
        {
        }

        struct boss_the_makerAI : public ScriptedAI
        {
            boss_the_makerAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            uint32 AcidSpray_Timer;
            uint32 ExplodingBreaker_Timer;
            uint32 Domination_Timer;
            uint32 Knockdown_Timer;

            void Reset()
            {
                AcidSpray_Timer = 15000;
                ExplodingBreaker_Timer = 6000;
                Domination_Timer = 120000;
                Knockdown_Timer = 10000;

                if (!pInstance)
                    return;

                pInstance->SetData(TYPE_THE_MAKER_EVENT, NOT_STARTED);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR2), true);
            }

            void EnterCombat(Unit * /*who*/)
            {
                DoScriptText(RAND(SAY_AGGRO_1,SAY_AGGRO_2,SAY_AGGRO_3), me);

                if (!pInstance)
                    return;

                pInstance->SetData(TYPE_THE_MAKER_EVENT, IN_PROGRESS);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR2), false);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2), me);
            }

            void JustDied(Unit* /*Killer*/)
            {
                DoScriptText(SAY_DIE, me);

                if (!pInstance)
                    return;

                pInstance->SetData(TYPE_THE_MAKER_EVENT, DONE);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR2), true);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR3), true);

             }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (AcidSpray_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_ACID_SPRAY);
                    AcidSpray_Timer = 15000+rand()%8000;
                }
                else
                    AcidSpray_Timer -=diff;

                if (ExplodingBreaker_Timer <= diff)
                {
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                        DoCast(pTarget, SPELL_EXPLODING_BREAKER);
                    ExplodingBreaker_Timer = 4000+rand()%8000;
                }
                else
                    ExplodingBreaker_Timer -=diff;

                /* // Disabled until Core Support for mind control
                if (domination_timer_timer <= diff)
                {
                Unit *pTarget;
                pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);

                DoCast(pTarget, SPELL_DOMINATION);

                domination_timer = 120000;
                } else domination_timer -=diff;
                */

                if (Knockdown_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_KNOCKDOWN);
                    Knockdown_Timer = 4000+rand()%8000;
                }
                else
                    Knockdown_Timer -=diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new boss_the_makerAI (Creature);
        }
};

void AddSC_boss_the_maker()
{
    new boss_the_maker();
}

