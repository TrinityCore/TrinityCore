/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2016-2019 MagicStorm
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

#include "trial_of_valor.h"

 // 209 Trial of Valor area 2
class npc_enter_the_eternal_battlefield : public CreatureScript
{
public:
    npc_enter_the_eternal_battlefield() : CreatureScript("npc_enter_the_eternal_battlefield") { }

    struct npc_enter_the_eternal_battlefieldAI : public ScriptedAI
    {
        npc_enter_the_eternal_battlefieldAI(Creature* creature) : ScriptedAI(creature) { }

        Player* player;

        void UpdateAI(uint32 diff)
        {
            if (player = me->SelectNearestPlayer(2.0f))
                player->TeleportTo(1648, 340.323f, 354.52f, 30.7229f, 0.89f);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_enter_the_eternal_battlefieldAI(creature);
    }
};

void AddSC_trial_of_valor()
{
    new npc_enter_the_eternal_battlefield();
}
