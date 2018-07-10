/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef GameObjectData_h__
#define GameObjectData_h__

#include "Common.h"
#include "SharedDefines.h"
#include "SpawnData.h"
#include "WorldPacket.h"
#include "GameObjectTemplate.h"
#include <string>
#include <vector>

namespace WorldPackets {
    namespace Query {
        class QueryGameObjectResponse;
    }
}

#define MAX_GAMEOBJECT_QUEST_ITEMS 6


// From `gameobject_template_addon`, `gameobject_overrides`
struct GameObjectOverride
{
    uint32 Faction;
    uint32 Flags;
};

// From `gameobject_template_addon`
struct GameObjectTemplateAddon : public GameObjectOverride
{
    uint32 Mingold;
    uint32 Maxgold;
};

struct GameObjectLocale
{
    std::vector<std::string> Name;
    std::vector<std::string> CastBarCaption;
};

struct TC_GAME_API QuaternionData
{
    float x, y, z, w;

    QuaternionData() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) { }
    QuaternionData(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W) { }

    bool isUnit() const;
    static QuaternionData fromEulerAnglesZYX(float Z, float Y, float X);
};

// `gameobject_addon` table
struct GameObjectAddon
{
    QuaternionData ParentRotation;
    InvisibilityType invisibilityType;
    uint32 InvisibilityValue;
};

// `gameobject` table
struct GameObjectData : public SpawnData
{
    GameObjectData() : SpawnData(SPAWN_TYPE_GAMEOBJECT) { }
    QuaternionData rotation;
    uint32 animprogress = 0;
    GOState goState = GO_STATE_ACTIVE;
    uint8 artKit = 0;
};

#endif // GameObjectData_h__
