/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __TRINITY_MAPSCENARIO_H
#define __TRINITY_MAPSCENARIO_H

#include "Map.h"
#include "Scenario.h"

typedef std::unordered_map<uint8, CriteriaProgressMap> StepCriteriaProgressMap;

class TC_GAME_API InstanceScenario : public Scenario
{
    public:
        InstanceScenario(Map* map, ScenarioData const* scenarioData);
        ~InstanceScenario() { delete _map; }

        void SaveToDB();
        void LoadInstanceData(uint32 instanceId);

    protected:
        std::string GetOwnerInfo() const override;
        void SendPacket(WorldPacket const* data) const override { _map->SendToPlayers(data); }

        Map* _map;
        ScenarioData const* _data;
        StepCriteriaProgressMap _stepCriteriaProgress;
};

#endif
