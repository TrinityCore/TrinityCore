/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SDName: Boss_Princess_Theradras
SD%Complete: 100
SDComment:
SDCategory: Maraudon
EndScriptData */

#include "ScriptMgr.h"
#include "maraudon.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_DUSTFIELD             = 21909,
    SPELL_BOULDER               = 21832,
    SPELL_THRASH                = 3391,
    SPELL_REPULSIVEGAZE         = 21869
};

class boss_princess_theradras : public CreatureScript
{
public:
    boss_princess_theradras() : CreatureScript("boss_princess_theradras") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMaraudonAI<boss_ptheradrasAI>(creature);
    }

    struct boss_ptheradrasAI : public ScriptedAI
    {
        boss_ptheradrasAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            DustfieldTimer = 8000;
            BoulderTimer = 2000;
            ThrashTimer = 5000;
            RepulsiveGazeTimer = 23000;
        }

        uint32 DustfieldTimer;
        uint32 BoulderTimer;
        uint32 ThrashTimer;
        uint32 RepulsiveGazeTimer;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void JustDied(Unit* /*killer*/) override
        {
            me->SummonCreature(12238, 28.067f, 61.875f, -123.405f, 4.67f, TEMPSUMMON_TIMED_DESPAWN, 600000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            //DustfieldTimer
            if (DustfieldTimer <= diff)
            {
                DoCast(me, SPELL_DUSTFIELD);
                DustfieldTimer = 14000;
            }
            else DustfieldTimer -= diff;

            //BoulderTimer
            if (BoulderTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_BOULDER);
                BoulderTimer = 10000;
            }
            else BoulderTimer -= diff;

            //RepulsiveGazeTimer
            if (RepulsiveGazeTimer <= diff)
            {
                DoCastVictim(SPELL_REPULSIVEGAZE);
                RepulsiveGazeTimer = 20000;
            }
            else RepulsiveGazeTimer -= diff;

            //ThrashTimer
            if (ThrashTimer <= diff)
            {
                DoCast(me, SPELL_THRASH);
                ThrashTimer = 18000;
            }
            else ThrashTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_ptheradras()
{
    new boss_princess_theradras();
}
