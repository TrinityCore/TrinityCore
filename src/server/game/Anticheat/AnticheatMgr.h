/*
* Copyright (C) 2011-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "AnticheatData.h"
#include "Common.h"
#include "SharedDefines.h"
#include "ScriptMgr.h"
#include "Player.h"

class ChatHandler;
class AnticheatCheck;

enum DetectionTypes
{
    SPEED_HACK_DETECTION            = 0x01,
    FLY_HACK_DETECTION              = 0x02,
    WALK_WATER_HACK_DETECTION       = 0x04,
    JUMP_HACK_DETECTION             = 0x08,
    TELEPORT_PLANE_HACK_DETECTION   = 0x10,
    CLIMB_HACK_DETECTION            = 0x20
};

typedef std::unordered_map<ObjectGuid, AnticheatData> AnticheatPlayersDataMap;

class AnticheatMgr
{
    friend class AnticheatCheck;

    AnticheatMgr();
    ~AnticheatMgr();

    public:
        static AnticheatMgr* instance();

        void StartHackDetection(Player* player, MovementInfo const& movementInfo, uint16 opcode);

        void HandlePlayerLogin(Player* player, PreparedQueryResult result);
        void HandlePlayerLogout(ObjectGuid const& guid);
        void SavePlayerData(ObjectGuid const& guid, SQLTransaction& trans);

        inline uint32 GetTotalReports(ObjectGuid const& guid) { return m_playerMap[guid].GetTotalReports(); }
        inline float GetAverage(ObjectGuid const& guid) { return m_playerMap[guid].GetAverage(); }
        inline uint32 GetTypeReports(ObjectGuid const& guid, ReportTypes type) { return m_playerMap[guid].GetTypeReports(type); }

        // use sparingly, triggers a global anticheat save to DB, requires to lock player map and does some synchronous queries
        bool AnticheatGlobalCommand(ChatHandler* handler);

        void ResetDailyReportStates();

        void LoadSettings();

    private:
        AnticheatPlayersDataMap m_playerMap;
        std::vector<AnticheatCheck*> m_checks;

        bool m_enabled;
};

#define sAnticheatMgr AnticheatMgr::instance()

class AnticheatCheck
{
    public:
        virtual ~AnticheatCheck() { }
        virtual bool OnCheck(Player* player, AnticheatData* playerData, MovementInfo const& movementInfo, uint16 opcode = 0) const = 0;

        virtual void HackReport(Player* player, AnticheatData* playerData) const = 0;
};

template <ReportTypes type>
class AnticheatCheckBase : public AnticheatCheck
{
    public:
        bool OnCheck(Player* /*player*/, AnticheatData* /*playerData*/, MovementInfo const& /*movementInfo*/, uint16 /*opcode = 0*/) const override
        {
            ASSERT(false && "AnticheatCheckBase::OnCheck called directly");
            return false; // prevent some compilers from warning
        }

        void HackReport(Player* player, AnticheatData* playerData) const final override;
};

class SpeedHackCheck : public AnticheatCheckBase<REPORT_TYPE_SPEED>
{
    public:
        bool OnCheck(Player* player, AnticheatData* playerData, MovementInfo const& movementInfo, uint16 opcode = 0) const override;
};

class FlyHackCheck : public AnticheatCheckBase<REPORT_TYPE_FLY>
{
    public:
        bool OnCheck(Player* player, AnticheatData* playerData, MovementInfo const& movementInfo, uint16 opcode = 0) const override;
};

class WalkOnWaterCheck : public AnticheatCheckBase<REPORT_TYPE_WATERWALK>
{
    public:
        bool OnCheck(Player* player, AnticheatData* playerData, MovementInfo const& movementInfo, uint16 opcode = 0) const override;
};

class JumpHackCheck : public AnticheatCheckBase<REPORT_TYPE_JUMP>
{
    public:
        bool OnCheck(Player* player, AnticheatData* playerData, MovementInfo const& movementInfo, uint16 opcode = 0) const override;
};

class TeleportPlaneCheck : public AnticheatCheckBase<REPORT_TYPE_TELEPORT_PLANE>
{
    public:
        bool OnCheck(Player* player, AnticheatData* playerData, MovementInfo const& movementInfo, uint16 opcode = 0) const override;
};

class ClimbHackCheck : public AnticheatCheckBase<REPORT_TYPE_CLIMB>
{
    public:
        bool OnCheck(Player* player, AnticheatData* playerData, MovementInfo const& movementInfo, uint16 opcode = 0) const override;
};

#endif
