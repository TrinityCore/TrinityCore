/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss epoch
SDAuthor: Tartalo
SD%Complete: 80
SDComment: TODO: Intro, consecutive attacks to a random target durin time wrap, adjust timers
SDCategory:
Script Data End */

#include "ScriptPCH.h"
#include "culling_of_stratholme.h"

enum Spells
{
    SPELL_CURSE_OF_EXERTION                     = 52772,
    SPELL_TIME_WARP                             = 52766, //Time slows down, reducing attack, casting and movement speed by 70% for 6 sec.
    SPELL_TIME_STOP                             = 58848, //Stops time in a 50 yard sphere for 2 sec.
    SPELL_WOUNDING_STRIKE                       = 52771, //Used only on the tank
    H_SPELL_WOUNDING_STRIKE                     = 58830
};

enum Yells
{
    SAY_INTRO                                   = -1595000, //"Prince Arthas Menethil, on this day, a powerful darkness has taken hold of your soul. The death you are destined to visit upon others will this day be your own."
    SAY_AGGRO                                   = -1595001, //"We'll see about that, young prince."
    SAY_TIME_WARP_1                             = -1595002, //"Tick tock, tick tock..."
    SAY_TIME_WARP_2                             = -1595003, //"Not quick enough!"
    SAY_TIME_WARP_3                             = -1595004, //"Let's get this over with. "
    SAY_SLAY_1                                  = -1595005, //"There is no future for you."
    SAY_SLAY_2                                  = -1595006, //"This is the hour of our greatest triumph!"
    SAY_SLAY_3                                  = -1595007, //"You were destined to fail. "
    SAY_DEATH                                   = -1595008 //"*gurgles*"
};

class boss_epoch : public CreatureScript
{
public:
    boss_epoch() : CreatureScript("boss_epoch") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_epochAI (pCreature);
    }

    struct boss_epochAI : public ScriptedAI
    {
        boss_epochAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        uint8 uiStep;

        uint32 uiStepTimer;
        uint32 uiWoundingStrikeTimer;
        uint32 uiTimeWarpTimer;
        uint32 uiTimeStopTimer;
        uint32 uiCurseOfExertionTimer;

        InstanceScript* pInstance;

        void Reset()
        {
            uiStep = 1;
            uiStepTimer = 26000;
            uiCurseOfExertionTimer = 9300;
            uiTimeWarpTimer = 25300;
            uiTimeStopTimer = 21300;
            uiWoundingStrikeTimer = 5300;

            if (pInstance)
                pInstance->SetData(DATA_EPOCH_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
                pInstance->SetData(DATA_EPOCH_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiCurseOfExertionTimer < diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_CURSE_OF_EXERTION);
                uiCurseOfExertionTimer = 9300;
            } else uiCurseOfExertionTimer -= diff;

            if (uiWoundingStrikeTimer < diff)
            {
                DoCastVictim(SPELL_WOUNDING_STRIKE);
                uiWoundingStrikeTimer = 5300;
            } else uiWoundingStrikeTimer -= diff;

            if (uiTimeStopTimer < diff)
            {
                DoCastAOE(SPELL_TIME_STOP);
                uiTimeStopTimer = 21300;
            } else uiTimeStopTimer -= diff;

            if (uiTimeWarpTimer < diff)
            {
                DoScriptText(RAND(SAY_TIME_WARP_1, SAY_TIME_WARP_2, SAY_TIME_WARP_3), me);
                DoCastAOE(SPELL_TIME_WARP);
                uiTimeWarpTimer = 25300;
            } else uiTimeWarpTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (pInstance)
                pInstance->SetData(DATA_EPOCH_EVENT, DONE);
        }

        void KilledUnit(Unit * victim)
        {
            if (victim == me)
                return;

            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }
    };

};

void AddSC_boss_epoch()
{
    new boss_epoch();
}
