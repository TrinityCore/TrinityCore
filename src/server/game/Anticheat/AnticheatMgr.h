/*
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

#ifndef SC_ACMGR_H
#define SC_ACMGR_H

#include <ace/Singleton.h>
#include "Common.h"
#include "SharedDefines.h"
#include "ScriptPCH.h"
#include "AnticheatData.h"
#include "Chat.h"

class Player;
class AnticheatData;

enum ReportTypes
{
    SPEED_HACK_REPORT = 0,
    FLY_HACK_REPORT,
    WALK_WATER_HACK_REPORT,
    JUMP_HACK_REPORT,
    TELEPORT_PLANE_HACK_REPORT,
    CLIMB_HACK_REPORT,

   // MAX_REPORT_TYPES
};

enum DetectionTypes
{
    SPEED_HACK_DETECTION            = 1,
    FLY_HACK_DETECTION              = 2,
    WALK_WATER_HACK_DETECTION       = 4,
    JUMP_HACK_DETECTION             = 8,
    TELEPORT_PLANE_HACK_DETECTION   = 16,
    CLIMB_HACK_DETECTION            = 32
};

// GUIDLow is the key.
typedef std::map<uint32, AnticheatData> AnticheatPlayersDataMap;

class AnticheatMgr
{
    friend class ACE_Singleton<AnticheatMgr, ACE_Null_Mutex>;
    AnticheatMgr();
    ~AnticheatMgr();

    public:

        void StartHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode);
        void DeletePlayerReport(Player* player, bool login);
        void DeletePlayerData(Player* player);
        void CreatePlayerData(Player* player);
        void SavePlayerData(Player* player);

        void StartScripts();

        void HandlePlayerLogin(Player* player);
        void HandlePlayerLogout(Player* player);

        uint32 GetTotalReports(uint32 lowGUID);
        float GetAverage(uint32 lowGUID);
        uint32 GetTypeReports(uint32 lowGUID, uint8 type);

        void AnticheatGlobalCommand(ChatHandler* handler);
        void AnticheatDeleteCommand(uint32 guid);

        void ResetDailyReportStates();
    private:
        void SpeedHackDetection(Player* player, MovementInfo movementInfo);
        void FlyHackDetection(Player* player, MovementInfo movementInfo);
        void WalkOnWaterHackDetection(Player* player, MovementInfo movementInfo);
        void JumpHackDetection(Player* player, MovementInfo movementInfo,uint32 opcode);
        void TeleportPlaneHackDetection(Player* player, MovementInfo);
        void ClimbHackDetection(Player* player,MovementInfo movementInfo,uint32 opcode);

        void BuildReport(Player* player,uint8 reportType);

        bool MustCheckTempReports(uint8 type);

        AnticheatPlayersDataMap m_Players;                        ///< Player data
};

#define sAnticheatMgr ACE_Singleton<AnticheatMgr, ACE_Null_Mutex>::instance()

#endif
