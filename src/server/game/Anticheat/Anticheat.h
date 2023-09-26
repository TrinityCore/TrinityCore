/*
 * Copyright (C) 2016-2019 AtieshCore <https://at-wow.org/>
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

#ifndef _ANTICHEAT_H
#define _ANTICHEAT_H

#include "Common.h"
//#include "Player.h"
//#include "MovementInfo.h"

class Player;
struct MovementInfo;

class TC_GAME_API Anticheat
{
public:
    Anticheat(Player* player);
    ~Anticheat();
public:

    void update(uint32 p_time);
    void punish(uint8 method);

    void resetFallingData(float z);
    void startWaitingLandOrSwimOpcode();
    void updateFallInformationIfNeed(float newZ);
    bool isWaitingLandOrSwimOpcode() const { return m_antiNoFallDmg; }
    bool isUnderLastChanceForLandOrSwimOpcode() const { return m_antiNoFallDmgLastChance; }
    void setSuccessfullyLanded() { m_antiNoFallDmgLastChance = false; m_antiNoFallDmg = false; }

    void setSkipOnePacketForASH(bool blinked) { m_skipOnePacketForASH = blinked; }
    bool isSkipOnePacketForASH() const { return m_skipOnePacketForASH; }
    void setJumpingbyOpcode(bool jump) { m_isjumping = jump; }
    bool isJumpingbyOpcode() const { return m_isjumping; }
    void setCanFlybyServer(bool canfly) { m_canfly = canfly; }
    bool isCanFlybyServer() const { return m_canfly; }

    bool underACKmount() const { return m_ACKmounted; }
    bool underACKRootUpd() const { return m_rootUpd; }

    void setUnderACKmount();
    void setRootACKUpd(uint32 delay);

    void setLastMoveClientTimestamp(uint32 timestamp) { lastMoveClientTimestamp = timestamp; }
    void setLastMoveServerTimestamp(uint32 timestamp) { lastMoveServerTimestamp = timestamp; }
    uint32 getLastMoveClientTimestamp() const { return lastMoveClientTimestamp; }
    uint32 getLastMoveServerTimestamp() const { return lastMoveServerTimestamp; }
    void updateMovementInfo(MovementInfo const& movementInfo);

    bool checkOnFlyHack();
    bool checkMovementInfo(MovementInfo const& movementInfo, bool jump);

    std::string getDescriptionACForLogs(uint8 type, float param1 = 0.f, float param2 = 0.f) const;
    std::string getPositionACForLogs() const;

    void setReloadModelsDisplayTimer();

private:
    Player* pPlayer = nullptr;
    
    bool m_skipOnePacketForASH; // Used for skip 1 movement packet after charge or blink
    bool m_isjumping;           // Used for jump-opcode in movementhandler
    bool m_canfly;              // Used for access at fly flag - handled restricted access
    bool m_ACKmounted;
    bool m_rootUpd;
    bool m_antiNoFallDmg;
    bool m_antiNoFallDmgLastChance;
    uint32 m_mountTimer;
    uint32 m_rootUpdTimer;
    uint32 m_flyhackTimer;
    uint32 m_antiNoFallDmgTimer;
    uint32 m_reloadModelsDisplayTimer;

    // Timestamp on client clock of the moment the most recently processed movement packet was SENT by the client
    uint32 lastMoveClientTimestamp;
    // Timestamp on server clock of the moment the most recently processed movement packet was RECEIVED from the client
    uint32 lastMoveServerTimestamp;
};

#endif // _ANTICHEAT_H
