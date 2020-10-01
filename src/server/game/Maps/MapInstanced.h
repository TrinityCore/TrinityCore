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

#include "Map.h"
#include "InstanceSaveMgr.h"
#include "DBCEnums.h"

class GarrisonMap;

class TC_GAME_API MapInstanced : public Map
{
    friend class MapManager;
    public:
        typedef std::unordered_map< uint32, Map*> InstancedMaps;

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
            return(i == m_InstancedMaps.end() ? nullptr : i->second);
        }
        bool DestroyInstance(InstancedMaps::iterator &itr);

        InstancedMaps &GetInstancedMaps() { return m_InstancedMaps; }
        virtual void InitVisibilityDistance() override;

    private:
        InstanceMap* CreateInstance(uint32 InstanceId, InstanceSave* save, Difficulty difficulty, TeamId team);
        BattlegroundMap* CreateBattleground(uint32 InstanceId, Battleground* bg);
        GarrisonMap* CreateGarrison(uint32 instanceId, Player* owner);

        InstancedMaps m_InstancedMaps;
};
#endif
