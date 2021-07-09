/*
 * Copyright (C) 2011-2016 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef WMOROOT_H
#define WMOROOT_H
#include <string>
#include <vector>

#include "ChunkedData.h"
#include "Utils.h"
#include "WorldModelGroup.h"

class WorldModelRoot
{
public:
    WorldModelRoot(std::string path);
    ~WorldModelRoot();
    std::string Path;
    ChunkedData* Data;
    WorldModelHeader Header;
    std::vector<DoodadInstance> DoodadInstances;
    std::vector<DoodadSet> DoodadSets;
    std::vector<WorldModelGroup> Groups;
private:
    void ReadGroups();
    void ReadDoodadSets();
    void ReadDoodadInstances();
    void ReadHeader();
};
#endif