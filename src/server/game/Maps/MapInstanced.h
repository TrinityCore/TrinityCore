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

#ifndef TRINITY_MAP_INSTANCED_H
#define TRINITY_MAP_INSTANCED_H

#include "DBCEnums.h"
#include "InstanceSaveMgr.h"
#include "Map.h"
#include "UniqueTrackablePtr.h"

class TC_GAME_API MapInstanced : public Map
{
    friend class MapManager;
    public:
        typedef std::unordered_map<uint32, Trinity::unique_trackable_ptr<Map>> InstancedMaps;

        MapInstanced(uint32 id, time_t expiry);
        ~MapInstanced() { }

        // functions overwrite Map versions
        void Update(uint32 diff) override;
        void DelayedUpdate(uint32 diff) override;
        //void RelocationNotify();
        void UnloadAll() override;
        EnterState CannotEnter(Player* /*player*/) override;

        Map* CreateInstanceForPlayer(uint32 mapId, Player* player, uint32 loginInstanceId = 0);
        Map* FindInstanceMap(uint32 instanceId) const
        {
            InstancedMaps::const_iterator i = m_InstancedMaps.find(instanceId);
            return(i == m_InstancedMaps.end() ? nullptr : i->second.get());
        }
        bool DestroyInstance(InstancedMaps::iterator &itr);

        void AddGridMapReference(GridCoord const& p)
        {
            ++GridMapReference[p.x_coord][p.y_coord];
            SetUnloadReferenceLock(GridCoord((MAX_NUMBER_OF_GRIDS - 1) - p.x_coord, (MAX_NUMBER_OF_GRIDS - 1) - p.y_coord), true);
        }

        void RemoveGridMapReference(GridCoord const& p)
        {
            --GridMapReference[p.x_coord][p.y_coord];
            if (!GridMapReference[p.x_coord][p.y_coord])
                SetUnloadReferenceLock(GridCoord((MAX_NUMBER_OF_GRIDS - 1) - p.x_coord, (MAX_NUMBER_OF_GRIDS - 1) - p.y_coord), false);
        }

        InstancedMaps &GetInstancedMaps() { return m_InstancedMaps; }
        virtual void InitVisibilityDistance() override;

    private:
        InstanceMap* CreateInstance(uint32 InstanceId, InstanceSave* save, Difficulty difficulty, TeamId InstanceTeam);
        BattlegroundMap* CreateBattleground(uint32 InstanceId, Battleground* bg);

        InstancedMaps m_InstancedMaps;

        uint16 GridMapReference[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
};
#endif
