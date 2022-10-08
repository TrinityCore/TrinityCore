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

#include "Scenario.h"
#include "GameObject.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "WorldStatePackets.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"

struct scenario_the_defense_of_karabor : public InstanceScript
{
    scenario_the_defense_of_karabor(InstanceMap* map) : InstanceScript(map) { }

    void Initialize() override
    {

    }

    void OnPlayerEnter(Player* player) override
    {

    }

    void Update(uint32 diff) override
    {

    }

private:

};


void AddSC_scenario_the_defense_of_karabor()
{

}
