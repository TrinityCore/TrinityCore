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
SDName: Boss krystallus
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

#include "ScriptPCH.h"
#include "halls_of_stone.h"

enum Spells
{
    SPELL_BOULDER_TOSS                             = 50843,
    H_SPELL_BOULDER_TOSS                           = 59742,
    SPELL_GROUND_SPIKE                             = 59750,
    SPELL_GROUND_SLAM                              = 50827,
    SPELL_SHATTER                                  = 50810,
    H_SPELL_SHATTER                                = 61546,
    SPELL_SHATTER_EFFECT                           = 50811,
    H_SPELL_SHATTER_EFFECT                         = 61547,
    SPELL_STONED                                   = 50812,
    SPELL_STOMP                                    = 48131,
    H_SPELL_STOMP                                  = 59744
};

enum Yells
{
    SAY_AGGRO                                   = -1599007,
    SAY_KILL                                    = -1599008,
    SAY_DEATH                                   = -1599009,
    SAY_SHATTER                                 = -1599010
};

class boss_krystallus : public CreatureScript
{
public:
    boss_krystallus() : CreatureScript("boss_krystallus") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_krystallusAI (creature);
    }

    struct boss_krystallusAI : public ScriptedAI
    {
        boss_krystallusAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiBoulderTossTimer;
        uint32 uiGroundSpikeTimer;
        uint32 uiGroundSlamTimer;
        uint32 uiShatterTimer;
        uint32 uiStompTimer;

        bool bIsSlam;

        InstanceScript* instance;

        void Reset()
        {
            bIsSlam = false;

            uiBoulderTossTimer = urand(3000, 9000);
            uiGroundSpikeTimer = urand(9000, 14000);
            uiGroundSlamTimer = urand(15000, 18000);
            uiStompTimer = urand(20000, 29000);
            uiShatterTimer = 0;

            if (instance)
                instance->SetData(DATA_KRYSTALLUS_EVENT, NOT_STARTED);
        }
        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (instance)
                instance->SetData(DATA_KRYSTALLUS_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiBoulderTossTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_BOULDER_TOSS);
                uiBoulderTossTimer = urand(9000, 15000);
            } else uiBoulderTossTimer -= diff;

            if (uiGroundSpikeTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_GROUND_SPIKE);
                uiGroundSpikeTimer = urand(12000, 17000);
            } else uiGroundSpikeTimer -= diff;

            if (uiStompTimer <= diff)
            {
                DoCast(me, SPELL_STOMP);
                uiStompTimer = urand(20000, 29000);
            } else uiStompTimer -= diff;

            if (uiGroundSlamTimer <= diff)
            {
                DoCast(me, SPELL_GROUND_SLAM);
                bIsSlam = true;
                uiShatterTimer = 10000;
                uiGroundSlamTimer = urand(15000, 18000);
            } else uiGroundSlamTimer -= diff;

            if (bIsSlam)
            {
                if (uiShatterTimer <= diff)
                {
                    DoCast(me, DUNGEON_MODE(SPELL_SHATTER, H_SPELL_SHATTER));
                } else uiShatterTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (instance)
                instance->SetData(DATA_KRYSTALLUS_EVENT, DONE);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;
            DoScriptText(SAY_KILL, me);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* pSpell)
        {
            //this part should be in the core
            if (pSpell->Id == SPELL_SHATTER || pSpell->Id == H_SPELL_SHATTER)
            {
                //this spell must have custom handling in the core, dealing damage based on distance
                target->CastSpell(target, DUNGEON_MODE(SPELL_SHATTER_EFFECT, H_SPELL_SHATTER_EFFECT), true);

                if (target->HasAura(SPELL_STONED))
                    target->RemoveAurasDueToSpell(SPELL_STONED);

                //clear this, if we are still performing
                if (bIsSlam)
                {
                    bIsSlam = false;

                    //and correct movement, if not already
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                    {
                        if (me->getVictim())
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                    }
                }
            }
        }
    };

};

void AddSC_boss_krystallus()
{
    new boss_krystallus();
}
