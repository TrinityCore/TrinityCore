/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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

enum Enums
{
    //Spells
    SPELL_HUGE_SHARP_TEETH          = 114078,
    SPELL_INTERDIMENSIONAL_HOP      = 135056,

    //Events

};

// 58336 - Darkmoon Rabbit
class npc_darkmoon_rabbit_ird : public CreatureScript
{
public:
    npc_darkmoon_rabbit_ird() : CreatureScript("npc_darkmoon_rabbit_ird") { }

    struct npc_darkmoon_rabbit_irdAI : public ScriptedAI
    {
        npc_darkmoon_rabbit_irdAI(Creature* creature) : ScriptedAI(creature) { }

        void EnterCombat(Unit* who) override
        {
            me->CastSpell(who, SPELL_HUGE_SHARP_TEETH);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            events.Reset();
            _EnterEvadeMode();
            me->GetMotionMaster()->MoveTargetedHome();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!UpdateVictim())
                    return;

            /*while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    default:
                    break;
                }
            }*/

            DoMeleeAttackIfReady();
        }

        EventMap events;
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new npc_darkmoon_rabbit_irdAI(p_Creature);
    }
};

void AddSC_darkmoon_rabbit()
{
    new npc_darkmoon_rabbit_ird();
}
