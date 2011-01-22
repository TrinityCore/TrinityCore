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

#include <ace/Singleton.h>

enum ReportTypes
{
    SPEED_HACK_REPORT = 0,
    FLY_HACK_REPORT,
    WALK_WATER_HACK_REPORT,
    JUMP_HACK_REPORT,
    TELEPORT_PLANE_HACK_REPORT,
    
    MAX_REPORT_TYPES
};

const std::string report_types[MAX_REPORT_TYPES] = {"speed_reports", "fly_reports", "waterwalk_reports", "jump_reports", "teleportplane_reports" };

class AnticheatMgr
{
    friend class ACE_Singleton<AnticheatMgr, ACE_Null_Mutex>;
    AnticheatMgr();
    ~AnticheatMgr();

    public:
        void StartHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode);
        void HandleHackDetectionTimer(Player* player, uint32 timeDiff);
        void DisableAnticheatDetection(Player* player, bool teleport = false);
        void DeletePlayerReport(Player* player);
    private:
        void SpeedHackDetection(Player* player, MovementInfo movementInfo);
        void FlyHackDetection(Player* player, MovementInfo movementInfo);
        void WalkOnWaterHackDetection(Player* player, MovementInfo movementInfo);
        void JumpHackDetection(Player* player, MovementInfo movementInfo,uint32 opcode);
        void TeleportPlaneHackDetection(Player* player, MovementInfo);

        void BuildReport(Player* player,uint8 reportType);
};

#define sAnticheatMgr ACE_Singleton<AnticheatMgr, ACE_Null_Mutex>::instance()