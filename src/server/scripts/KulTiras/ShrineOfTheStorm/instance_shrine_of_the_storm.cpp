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

#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"
#include "shrine_of_the_storm.h"

struct instance_shrine_of_the_storm : public InstanceScript
{
    instance_shrine_of_the_storm(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
    }

    void OnPlayerEnter(Player* player) override
    {
        if (!TeamInInstance)
            TeamInInstance = player->GetTeam();
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);

        if (!TeamInInstance)
        {
            Map::PlayerList const &players = instance->GetPlayers();
            if (!players.isEmpty())
                if (Player* player = players.begin()->GetSource())
                    TeamInInstance = player->GetTeam();
        }

        switch (creature->GetEntry())
        {
        case NPC_REXXAR:
            if (TeamInInstance == ALLIANCE)
                creature->UpdateEntry(NPC_BROTHER_PIKE);
            break;
        default:
            break;
        }
    }

protected:
    uint32 TeamInInstance;
};

void AddSC_instance_shrine_of_the_storm()
{
    RegisterInstanceScript(instance_shrine_of_the_storm, 1864);
}
