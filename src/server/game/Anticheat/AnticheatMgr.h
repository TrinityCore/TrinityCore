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

#ifndef SC_ACMGR_H
#define SC_ACMGR_H

#include "Common.h"
#include "SharedDefines.h"
#include "ScriptMgr.h"
#include "AnticheatData.h"
#include "Chat.h"
#include "Player.h"
#include <unordered_map>
#include "WorldSession.h"

class Player;
class AnticheatData;

enum ReportTypes
{
    SPEED_HACK_REPORT = 0,
    FLY_HACK_REPORT = 1,
    WALK_WATER_HACK_REPORT = 2,
    JUMP_HACK_REPORT = 3,
    TELEPORT_PLANE_HACK_REPORT = 4,
    CLIMB_HACK_REPORT = 5,
    TELEPORT_HACK_REPORT = 6,
    IGNORE_CONTROL_REPORT = 7,
    ZAXIS_HACK_REPORT = 8,
    ANTISWIM_HACK_REPORT = 9,
    GRAVITY_HACK_REPORT = 10,
    ANTIKNOCK_BACK_HACK_REPORT = 11,
    NO_FALL_DAMAGE_HACK_REPORT = 12,
    OP_ACK_HACK_REPORT = 13,
    COUNTER_MEASURES_REPORT = 14

   // MAX_REPORT_TYPES
};

// GUIDLow is the key.
typedef std::map<uint32, AnticheatData> AnticheatPlayersDataMap;

class TC_GAME_API ServerOrderData
{
public:
    ServerOrderData(uint32 serv, uint32 resp) : serverOpcode1(serv), serverOpcode2(0), clientResp(resp), lastSent(0), lastRcvd(0), counter(0) {}
    ServerOrderData(uint32 serv1, uint32 serv2, uint32 resp) : serverOpcode1(serv1), serverOpcode2(serv2), clientResp(resp), lastSent(0), lastRcvd(0), counter(0) {}

    uint32 serverOpcode1;
    uint32 serverOpcode2;
    uint32 clientResp;

    uint32 lastSent;
    uint32 lastRcvd;
    int32 counter;
};

class TC_GAME_API AnticheatMgr
{
    AnticheatMgr();
    ~AnticheatMgr();

    public:
        static AnticheatMgr* instance()
        {
           static AnticheatMgr* instance = new AnticheatMgr();
           return instance;
        }
        void SetAllowedMovement(Player* player, bool);
        void StartHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode);
        void SavePlayerData(Player* player);
        void SavePlayerDataDaily(Player* player);
        void OnPlayerMove(Player* player, MovementInfo mi, uint32 opcode);
        void StartScripts();

        void HandlePlayerLogin(Player* player);
        void HandlePlayerLogout(Player* player);
        void AckUpdate(Player* player, uint32 diff);
        void DoActions(Player* player);

        // orders
        void OrderSent(WorldPacket const* data);
        void CheckForOrderAck(uint32 opcode);
        std::vector<ServerOrderData> _opackorders; // Packets sent by server, triggering *_ACK from client

        uint32 GetTotalReports(uint32 lowGUID);
        float GetAverage(uint32 lowGUID);
        uint32 GetTypeReports(uint32 lowGUID, uint8 type);

        void AnticheatGlobalCommand(ChatHandler* handler);
        void AnticheatDeleteCommand(uint32 guid);
        void AnticheatPurgeCommand(ChatHandler* handler);
        void ResetDailyReportStates();
        void SetMapId(uint32 MapID) { m_MapId = MapID; }
        [[nodiscard]] uint32 GetMapId() const { return m_MapId; }
        void LoadBlockedLuaFunctions();
        void SaveLuaCheater(uint32 guid, uint32 accountId, std::string macro);
        bool CheckIsLuaCheater(uint32 accountId);
        bool CheckBlockedLuaFunctions(AccountData accountData[NUM_ACCOUNT_DATA_TYPES], Player* player = nullptr);

    private:
        void SpeedHackDetection(Player* player, MovementInfo movementInfo);
        void FlyHackDetection(Player* player, MovementInfo movementInfo);
        void WalkOnWaterHackDetection(Player* player, MovementInfo movementInfo);
        void JumpHackDetection(Player* player, MovementInfo movementInfo,uint32 opcode);
        void TeleportPlaneHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode);
        void ClimbHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode);
        void IgnoreControlHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode);
        void TeleportHackDetection(Player* player, MovementInfo movementInfo);
        void ZAxisHackDetection(Player* player, MovementInfo movementInfo);
        void AntiSwimHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode);
        void AntiKnockBackHackDetection(Player* player, MovementInfo movementInfo);
        void GravityHackDetection(Player* player, MovementInfo movementInfo);
        void NoFallDamageDetection(Player* player, MovementInfo movementInfo);
        void BGreport(Player* player);
        void CheckBGOriginPositions(Player* player);
        void BGStartExploit(Player* player, MovementInfo movementInfo);
        void BuildReport(Player* player,uint8 reportType);

        bool MustCheckTempReports(uint8 type);
        uint32 _counter = 0;
        uint32 _alertFrequency = 0;
        uint32 _assignedspeeddiff = 0;
        uint32 _updateCheckTimer = 4000;
        uint32 m_MapId = uint32(-1);
        std::unordered_map<std::string, bool> _luaBlockedFunctions;
        std::array<Position, PVP_TEAMS_COUNT> _startPosition;
        Position const* GetTeamStartPosition(TeamId teamId) const;
        AnticheatPlayersDataMap m_Players;                        ///< Player data
};

#define sAnticheatMgr AnticheatMgr::instance()

#endif
