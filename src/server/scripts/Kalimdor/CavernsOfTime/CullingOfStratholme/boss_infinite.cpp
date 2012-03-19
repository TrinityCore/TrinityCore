/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

enum corruptorData
{
    SPELL_VOID_STIKE        = 60590,
    SPELL_CORRUPTING_BLIGHT = 60588,
    SPELL_CHANNEL_VISUAL    = 31387,

    SAY_CORRUPTOR_AGGRO     = -1595045,
    SAY_CORRUPTOR_DEAD      = -1595046,
    SAY_CORRUPTOR_DESPAWN   = -1595047,

    NPC_TIME_RIFT           = 28409,
};

class boss_infinite_corruptor : public CreatureScript
{
public:
    boss_infinite_corruptor() : CreatureScript("boss_infinite_corruptor") { }

    struct boss_infinite_corruptorAI : public ScriptedAI
    {
        boss_infinite_corruptorAI(Creature *creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            timeRift = NULL;
            Reset();
        }

        InstanceScript* instance;
        uint32 uiStrikeTimer;
        uint32 uiBlightTimer;
        Creature* timeRift;

        void JustReachedHome()
        {
            // Data for visual
            if (timeRift)
                timeRift->DisappearAndDie();
            timeRift = me->SummonCreature(NPC_TIME_RIFT, me->GetPositionX() - 10.0f, me->GetPositionY(), me->GetPositionZ());

            // Visual Channeling
            if(timeRift)
                me->CastSpell(timeRift, SPELL_CHANNEL_VISUAL, true);
        }

        void Reset()
        {
            JustReachedHome();

            // Starting Timers
            uiStrikeTimer = urand(1000,3000);
            uiBlightTimer = urand(5000,8000);
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->Yell(SAY_CORRUPTOR_AGGRO, LANG_UNIVERSAL, 0);
        }

        void JustDied(Unit* pKiller)
        {
            me->Yell(SAY_CORRUPTOR_DEAD, LANG_UNIVERSAL, 0);
            if (instance)
                instance->SetData(DATA_INFINITE_EVENT, DONE);
        }

        void DoAction(const int32 id)
        {
            if(id == 0) // Called from InstanceScript
            {
                me->YellToZone(SAY_CORRUPTOR_DESPAWN, LANG_UNIVERSAL, 0);
                me->DespawnOrUnsummon(1000);
            }
        }
        void UpdateAI(const uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;

            if(uiStrikeTimer < uiDiff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                   DoCast(target, SPELL_VOID_STIKE);
                uiStrikeTimer = urand(3000, 8000);
            }
            else uiStrikeTimer -= uiDiff;

            if(uiBlightTimer < uiDiff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM))
                   DoCast(target, SPELL_CORRUPTING_BLIGHT);
                uiBlightTimer = urand(6000, 9000);
            }
            else uiBlightTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_infinite_corruptorAI(creature);
    }
};

void AddSC_boss_infinite_corruptor()
{
    new boss_infinite_corruptor();
}
