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
SDName: Boss_The_Maker
SD%Complete: 80
SDComment: Mind control no support
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "blood_furnace.h"

enum eEnums
{
    SAY_AGGRO                   = 0,
    SAY_KILL                    = 1,
    SAY_DIE                     = 2,

    SPELL_ACID_SPRAY            = 38153,
    SPELL_EXPLODING_BREAKER     = 30925,
    SPELL_KNOCKDOWN             = 20276,
    SPELL_DOMINATION            = 25772
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
            boss_the_makerAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

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

                if (!instance)
                    return;

                instance->SetData(TYPE_THE_MAKER_EVENT, NOT_STARTED);
                instance->HandleGameObject(instance->GetData64(DATA_DOOR2), true);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);

                if (!instance)
                    return;

                instance->SetData(TYPE_THE_MAKER_EVENT, IN_PROGRESS);
                instance->HandleGameObject(instance->GetData64(DATA_DOOR2), false);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DIE);

                if (!instance)
                    return;

                instance->SetData(TYPE_THE_MAKER_EVENT, DONE);
                instance->HandleGameObject(instance->GetData64(DATA_DOOR2), true);
                instance->HandleGameObject(instance->GetData64(DATA_DOOR3), true);

             }

            void UpdateAI(uint32 diff)
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
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_EXPLODING_BREAKER);
                    ExplodingBreaker_Timer = 4000+rand()%8000;
                }
                else
                    ExplodingBreaker_Timer -=diff;

                /* // Disabled until Core Support for mind control
                if (domination_timer_timer <= diff)
                {
                Unit* target;
                target = SelectUnit(SELECT_TARGET_RANDOM, 0);

                DoCast(target, SPELL_DOMINATION);

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

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_the_makerAI(creature);
        }
};

void AddSC_boss_the_maker()
{
    new boss_the_maker();
}

