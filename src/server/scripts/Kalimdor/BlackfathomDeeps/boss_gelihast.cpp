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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "blackfathom_deeps.h"

enum Spells
{
    SPELL_NET                                              = 6533
};

class boss_gelihast : public CreatureScript
{
public:
    boss_gelihast() : CreatureScript("boss_gelihast") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_gelihastAI>(creature);
    }

    struct boss_gelihastAI : public ScriptedAI
    {
        boss_gelihastAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 netTimer;

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            netTimer = urand(2000, 4000);
            if (instance)
                instance->SetData(TYPE_GELIHAST, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            if (instance)
                instance->SetData(TYPE_GELIHAST, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (instance)
                instance->SetData(TYPE_GELIHAST, DONE);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (netTimer < diff)
            {
                DoCastVictim(SPELL_NET);
                netTimer = urand(4000, 7000);
            } else netTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_gelihast()
{
    new boss_gelihast();
}
