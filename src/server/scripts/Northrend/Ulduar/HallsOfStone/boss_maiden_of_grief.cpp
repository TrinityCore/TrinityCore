/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss maiden_of_grief
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_maiden_of_grief' where entry = '';
*** SQL END ***/
#include "ScriptPCH.h"
#include "halls_of_stone.h"

enum Spells
{
    SPELL_PARTING_SORROW                          = 59723,
    SPELL_STORM_OF_GRIEF_N                        = 50752,
    SPELL_STORM_OF_GRIEF_H                        = 59772,
    SPELL_SHOCK_OF_SORROW_N                       = 50760,
    SPELL_SHOCK_OF_SORROW_H                       = 59726,
    SPELL_PILLAR_OF_WOE_N                         = 50761,
    SPELL_PILLAR_OF_WOE_H                         = 59727
};

enum Yells
{
    SAY_AGGRO                                     = -1599000,
    SAY_SLAY_1                                    = -1599001,
    SAY_SLAY_2                                    = -1599002,
    SAY_SLAY_3                                    = -1599003,
    SAY_SLAY_4                                    = -1599004,
    SAY_DEATH                                     = -1599005,
    SAY_STUN                                      = -1599006
};

enum Achievements
{
    ACHIEV_GOOD_GRIEF_START_EVENT                 = 20383,
};

class boss_maiden_of_grief : public CreatureScript
{
public:
    boss_maiden_of_grief() : CreatureScript("boss_maiden_of_grief") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_maiden_of_griefAI (pCreature);
    }

    struct boss_maiden_of_griefAI : public ScriptedAI
    {
        boss_maiden_of_griefAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = me->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 PartingSorrowTimer;
        uint32 StormOfGriefTimer;
        uint32 ShockOfSorrowTimer;
        uint32 PillarOfWoeTimer;

        void Reset()
        {
            PartingSorrowTimer = 25000 + rand()%5000;
            StormOfGriefTimer = 10000;
            ShockOfSorrowTimer = 20000+rand()%5000;
            PillarOfWoeTimer = 5000 + rand()%10000;

            if (pInstance)
            {
                pInstance->SetData(DATA_MAIDEN_OF_GRIEF_EVENT, NOT_STARTED);
                pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_GOOD_GRIEF_START_EVENT);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
            {
                if (GameObject *pDoor = pInstance->instance->GetGameObject(pInstance->GetData64(DATA_MAIDEN_DOOR)))
                    if (pDoor->GetGoState() == GO_STATE_READY)
                    {
                        EnterEvadeMode();
                        return;
                    }

                pInstance->SetData(DATA_MAIDEN_OF_GRIEF_EVENT, IN_PROGRESS);
                pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_GOOD_GRIEF_START_EVENT);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (IsHeroic())
            {
                if (PartingSorrowTimer <= diff)
                {
                    Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);

                    if (pTarget)
                        DoCast(pTarget, SPELL_PARTING_SORROW);

                    PartingSorrowTimer = 30000 + rand()%10000;
                } else PartingSorrowTimer -= diff;
            }

            if (StormOfGriefTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_STORM_OF_GRIEF_N, true);
                StormOfGriefTimer = 15000 + rand()%5000;
            } else StormOfGriefTimer -= diff;

            if (ShockOfSorrowTimer <= diff)
            {
                DoResetThreat();
                DoScriptText(SAY_STUN, me);
                DoCast(me, SPELL_SHOCK_OF_SORROW_N);
                ShockOfSorrowTimer = 20000 + rand()%10000;
            } else ShockOfSorrowTimer -= diff;

            if (PillarOfWoeTimer <= diff)
            {
                Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1);

                if (pTarget)
                    DoCast(pTarget, SPELL_PILLAR_OF_WOE_N);
                else
                    DoCast(me->getVictim(), SPELL_PILLAR_OF_WOE_N);

                PillarOfWoeTimer = 5000 + rand()%20000;
            } else PillarOfWoeTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (pInstance)
                pInstance->SetData(DATA_MAIDEN_OF_GRIEF_EVENT, DONE);
        }

        void KilledUnit(Unit * victim)
        {
            if (victim == me)
                return;

            DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3,SAY_SLAY_4), me);
        }
    };

};


void AddSC_boss_maiden_of_grief()
{
    new boss_maiden_of_grief();
}
