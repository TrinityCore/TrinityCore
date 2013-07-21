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
    SAY_INTRO                                   = 0, //"Prince Arthas Menethil, on this day, a powerful darkness has taken hold of your soul. The death you are destined to visit upon others will this day be your own."
    SAY_AGGRO                                   = 1, //"We'll see about that, young prince."
    SAY_TIME_WARP_1                             = 2, //"Tick tock, tick tock..."
    SAY_TIME_WARP_2                             = 2, //"Not quick enough!"
    SAY_TIME_WARP_3                             = 2, //"Let's get this over with. "
    SAY_SLAY_1                                  = 3, //"There is no future for you."
    SAY_SLAY_2                                  = 3, //"This is the hour of our greatest triumph!"
    SAY_SLAY_3                                  = 3, //"You were destined to fail. "
    SAY_DEATH                                   = 4 //"*gurgles*"
};

class boss_epoch : public CreatureScript
{
public:
    boss_epoch() : CreatureScript("boss_epoch") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_epochAI (creature);
    }

    struct boss_epochAI : public ScriptedAI
    {
        boss_epochAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint8 uiStep;

        uint32 uiStepTimer;
        uint32 uiWoundingStrikeTimer;
        uint32 uiTimeWarpTimer;
        uint32 uiTimeStopTimer;
        uint32 uiCurseOfExertionTimer;

        InstanceScript* instance;

        void Reset()
        {
            uiStep = 1;
            uiStepTimer = 26000;
            uiCurseOfExertionTimer = 9300;
            uiTimeWarpTimer = 25300;
            uiTimeStopTimer = 21300;
            uiWoundingStrikeTimer = 5300;

            if (instance)
                instance->SetData(DATA_EPOCH_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);

            if (instance)
                instance->SetData(DATA_EPOCH_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiCurseOfExertionTimer < diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_CURSE_OF_EXERTION);
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
                Talk(SAY_TIME_WARP_1);
                DoCastAOE(SPELL_TIME_WARP);
                uiTimeWarpTimer = 25300;
            } else uiTimeWarpTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(DATA_EPOCH_EVENT, DONE);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;

            Talk(SAY_SLAY_1);
        }
    };

};

void AddSC_boss_epoch()
{
    new boss_epoch();
}
