/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "Player.h"

enum TikiTarget
{
    SPELL_TIKI_TARGET_VISUAL_1 = 71064,
    SPELL_TIKI_TARGET_VISUAL_2 = 71065,
    SPELL_TIKI_TARGET_VISUAL_3 = 71066
};

/*######
# npc_tiki_target "Used by entry 38038"
######*/

class npc_tiki_target : public CreatureScript
{
public:
    npc_tiki_target() : CreatureScript("npc_tiki_target") { }

    struct npc_tiki_targetAI : public ScriptedAI
    {
        npc_tiki_targetAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            DoCast(me, RAND(SPELL_TIKI_TARGET_VISUAL_1, SPELL_TIKI_TARGET_VISUAL_2, SPELL_TIKI_TARGET_VISUAL_3));
        }

        void DamageTaken(Unit* who, uint32& damage) override
        {
            if (who->GetTypeId() == TYPEID_UNIT && me->HealthBelowPct(85))
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {

        }

    private:
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tiki_targetAI(creature);
    }
};

void AddSC_durotar_area_echo_isles()
{
    new npc_tiki_target();
}

