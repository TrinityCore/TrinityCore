/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef TRINITY_MAP_FACTIONED_H
#define TRINITY_MAP_FACTIONED_H

#include "Map.h"

class TC_GAME_API MapFactioned : public Map
{
    friend class MapManager;
    public:
        typedef std::unordered_map<TeamId, Map*> FactionedMaps;

        MapFactioned(uint32 id, time_t expiry);
        MapFactioned(MapFactioned const& right) = delete;
        MapFactioned(MapFactioned&& right) = delete;
        MapFactioned& operator=(MapInstanced const& right) = delete;
        MapFactioned& operator=(MapInstanced&& right) = delete;
        ~MapFactioned();

        // functions overwrite Map versions
        void Update(uint32 diff) override;
        void DelayedUpdate(uint32 diff) override;

        void RemoveRespawnTime(SpawnObjectType type, ObjectGuid::LowType spawnId, CharacterDatabaseTransaction dbTrans = nullptr, bool alwaysDeleteFromDB = false) override;
        void CreateGameobject(ObjectGuid::LowType spawnId, bool addToMap, Position const& spawnPoint) override;
        void CreateCreature(ObjectGuid::LowType spawnId, bool addToMap, Position const& spawnPoint) override;

        void UnloadAll() override;

        Map* CreateFactionMapForTeam(TeamId teamId);

        Map* FindFactionMap(TeamId teamId, uint32 instanceId = 0) const
        {
            for (auto& factionMapPair : _factionedMaps)
            {
                Map* map = factionMapPair.second;

                if (instanceId)
                {
                    if (map->GetInstanceId() == instanceId)
                        return map;
                }
                else if (map->GetTeamId() == teamId)
                    return map;
            }
            return nullptr;
        }

        FactionedMaps& GetFactionedMaps() { return _factionedMaps; }
        virtual void InitVisibilityDistance() override;

    private:
        Map* CreateFactionMap(TeamId team);

        FactionedMaps _factionedMaps;
};

#endif
