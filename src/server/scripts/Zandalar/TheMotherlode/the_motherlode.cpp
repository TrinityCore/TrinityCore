/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "the_motherlode.h"

//136776
struct npc_mine_cart_136776 : public ScriptedAI
{
    npc_mine_cart_136776(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetFaction(35);
        me->SetReactState(REACT_PASSIVE);
    }
};

void AddSC_the_motherlode()
{
     RegisterCreatureAI(npc_mine_cart_136776);
}
