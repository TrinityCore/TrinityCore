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

#include "AccountMgr.h"
#include "DBCStores.h"
#include "GameTime.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "Player.h"
#include "Realm.h"
#include "Vehicle.h"
#include "World.h"
#include "WorldSession.h"

// Anticheat System
void Player::SetUnderACKmount()
{
    m_mountTimer = 3000;
    m_ACKmounted = true;
}

void Player::SetRootACKUpd(uint32 delay)
{
    m_rootUpdTimer = 1500 + delay;
    m_rootUpd = true;
}

void Player::UpdateMovementInfo(MovementInfo const& movementInfo)
{
    SetLastMoveClientTimestamp(movementInfo.time);
    SetLastMoveServerTimestamp(GameTime::GetGameTimeMS());
}

bool Player::CheckOnFlyHack()
{
    if (sWorld->isMapDisabledForAC(GetMapId()))
        return true;

    if (IsCanFlybyServer())
        return true;

    if (ToUnit()->IsFalling() || IsFalling())
        return true;

    if (IsFlying() && !CanFly()) // kick flyhacks
    {
        TC_LOG_INFO("anticheat", "Player::CheckMovementInfo :  FlyHack Detected for Account id : %u, Player %s", GetPlayerMovingMe()->GetSession()->GetAccountId(), GetPlayerMovingMe()->GetName().c_str());
        TC_LOG_INFO("anticheat", "Player::========================================================");
        TC_LOG_INFO("anticheat", "Player IsFlying but CanFly is false");

        sWorld->SendGMText(LANG_GM_ANNOUNCE_AFH_CANFLYWRONG, GetPlayerMovingMe()->GetName().c_str());
        AccountMgr::RecordAntiCheatLog(GetSession()->GetAccountId(), GetName().c_str(), GetDescriptionACForLogs(1), GetPositionACForLogs(), int32(realm.Id.Realm));
        return false;
    }

    if (IsFlying() || IsLevitating() || IsInFlight())
        return true;

    if (GetTransport() || GetVehicle() || GetVehicleKit())
        return true;

    if (HasAuraType(SPELL_AURA_CONTROL_VEHICLE))
        return true;

    if (HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
        return true;

    if (HasUnitState(UNIT_STATE_IGNORE_ANTISPEEDHACK))
        return true;

    if (GetPlayerMovingMe())
    {
        if (GetPlayerMovingMe()->UnderACKmount())
            return true;

        if (GetPlayerMovingMe()->IsSkipOnePacketForASH())
            return true;
    }
    else
        return true;

    Position npos = GetPosition();
    float pz = npos.GetPositionZ();
    if (!IsInWater() && HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
    {
        float waterlevel = GetBaseMap()->GetWaterLevel(npos.GetPositionX(), npos.GetPositionY()); // water walking
        bool hovergaura = HasAuraType(SPELL_AURA_WATER_WALK) || HasAuraType(SPELL_AURA_HOVER);
        if (waterlevel && (pz - waterlevel) <= (hovergaura ? GetCollisionHeight() + 1.5f + GetHoverOffset() : GetCollisionHeight() + GetHoverOffset()))
            return true;

        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  FlyHack Detected for Account id : %u, Player %s", GetPlayerMovingMe()->GetSession()->GetAccountId(), GetPlayerMovingMe()->GetName().c_str());
        TC_LOG_INFO("anticheat", "Player::========================================================");
        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  Player has a MOVEMENTFLAG_SWIMMING, but not in water");

        sWorld->SendGMText(LANG_GM_ANNOUNCE_AFK_SWIMMING, GetPlayerMovingMe()->GetName().c_str());
        AccountMgr::RecordAntiCheatLog(GetSession()->GetAccountId(), GetName().c_str(), GetDescriptionACForLogs(2), GetPositionACForLogs(), int32(realm.Id.Realm));
        return false;
    }
    else
    {
        float z = GetMap()->GetHeight(GetPhaseMask(), npos.GetPositionX(), npos.GetPositionY(), pz + GetCollisionHeight() + 0.5f, true, 50.0f); // smart flyhacks -> SimpleFly
        float diff = pz - z;
        if (diff > 6.8f)
            if (diff > 6.8f + GetHoverOffset()) // better calculate the second time for false situations, but not call GetHoverOffset everytime (economy resource)
            {
                float waterlevel = GetBaseMap()->GetWaterLevel(npos.GetPositionX(), npos.GetPositionY()); // water walking
                if (waterlevel && waterlevel + GetCollisionHeight() + GetHoverOffset() > pz)
                    return true;

                float cx, cy, cz;
                GetClosePoint(cx, cy, cz, DEFAULT_PLAYER_BOUNDING_RADIUS, 6.0f, 0, 6.8f); // first check
                if (pz - cz > 6.8f)
                {
                    // check dynamic collision for transport (TODO navmesh for transport map)
                    GetMap()->getObjectHitPos(GetPhaseMask(), GetPositionX(), GetPositionY(), GetPositionZ() + GetCollisionHeight(), cx, cy, cz + GetCollisionHeight(), cx, cy, cz, -GetCollisionHeight());

                    if (pz - cz > 6.8f)
                    {
                        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  FlyHack Detected for Account id : %u, Player %s", GetPlayerMovingMe()->GetSession()->GetAccountId(), GetPlayerMovingMe()->GetName().c_str());
                        TC_LOG_INFO("anticheat", "Player::========================================================");
                        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  playerZ = %f", pz);
                        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  normalZ = %f", z);
                        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  checkz = %f", cz);
                        sWorld->SendGMText(LANG_GM_ANNOUNCE_AFH, GetPlayerMovingMe()->GetName().c_str());
                        AccountMgr::RecordAntiCheatLog(GetSession()->GetAccountId(), GetName().c_str(), GetDescriptionACForLogs(3, pz, z), GetPositionACForLogs(), int32(realm.Id.Realm));
                        return false;
                    }
                }
            }
    }

    return true;
}

bool Player::CheckMovementInfo(MovementInfo const& movementInfo, bool jump)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_SPEEDHACK_ENABLED))
        return true;

    if (sWorld->isMapDisabledForAC(GetMapId()))
        return true;

    uint32 ctime = GetLastMoveClientTimestamp();
    if (ctime)
    {
        if (ToUnit()->IsFalling() || IsInFlight())
            return true;

        bool vehicle = false;
        if (GetVehicleKit() && GetVehicleKit()->GetBase())
            vehicle = true;

        if (GetVehicle())
            return true;

        if (!IsControlledByPlayer())
            return true;

        if (HasUnitState(UNIT_STATE_IGNORE_ANTISPEEDHACK))
            return true;

        if (GetPlayerMovingMe())
        {
            if (GetPlayerMovingMe()->IsSkipOnePacketForASH())
            {
                GetPlayerMovingMe()->SetSkipOnePacketForASH(false);
                return true;
            }
        }
        else
            return true;

        bool transportflag = movementInfo.GetMovementFlags() & MOVEMENTFLAG_ONTRANSPORT;
        float x, y, z;
        Position npos;

        // Position coords for new point
        if (!transportflag)
            npos = movementInfo.pos;
        else
            npos = movementInfo.transport.pos;

        // Position coords for previous point (old)
        //         Just CheckMovementInfo are calling before player change UnitMovementFlag MOVEMENTFLAG_ONTRANSPORT
        if (transportflag)
        {
            if (GetTransOffsetX() == 0.f) // if it elevator or fist step - player can have zero this coord
                return true;

            x = GetTransOffsetX();
            y = GetTransOffsetY();
            z = GetTransOffsetZ();
        }
        else
            GetPosition(x, y, z);

        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_IGNORE_CONTROL_MOVEMENT_ENABLED))
        {
            if (HasUnitState(UNIT_STATE_ROOT) && !UnderACKRootUpd())
            {
                bool unrestricted = npos.GetPositionX() != x || npos.GetPositionY() != y;
                if (unrestricted)
                {
                    TC_LOG_INFO("anticheat", "CheckMovementInfo :  Ignore controll Hack detected for Account id : %u, Player %s", GetSession()->GetAccountId(), GetName().c_str());
                    sWorld->SendGMText(LANG_GM_ANNOUNCE_MOVE_UNDER_CONTROL, GetSession()->GetAccountId(), GetName().c_str());
                    AccountMgr::RecordAntiCheatLog(GetSession()->GetAccountId(), GetName().c_str(), GetDescriptionACForLogs(4), GetPositionACForLogs(), int32(realm.Id.Realm));
                    return false;
                }
            }
        }

        float distance, movetime, speed, difftime, normaldistance, delay, delaysentrecieve;
        std::string mapname = GetMap()->GetMapName();

        // calculate distance - don't use func, because x,z can be offset transport coords
        distance = sqrt((npos.GetPositionY() - y) * (npos.GetPositionY() - y) + (npos.GetPositionX() - x) * (npos.GetPositionX() - x));
        
        if (!jump && !CanFly() && !isSwimming() && !transportflag)
        {
            float diffz = fabs(movementInfo.pos.GetPositionZ() - z);
            float tanangle = distance / diffz;

            if (movementInfo.pos.GetPositionZ() > z &&
                diffz > 1.87f &&
                tanangle < 0.57735026919f) // 30 degrees
            {
                TC_LOG_INFO("anticheat", "Player::CheckMovementInfo :  Climb-Hack detected for Account id : %u, Player %s, diffZ = %f, distance = %f, angle = %f, Map = %s, mapId = %u, X = %f, Y = %f, Z = %f",
                    GetSession()->GetAccountId(), GetName().c_str(), diffz, distance, tanangle, mapname.c_str(), GetMapId(), x, y, z);
                sWorld->SendGMText(LANG_GM_ANNOUNCE_WALLCLIMB, GetSession()->GetAccountId(), GetName().c_str(), diffz, distance, tanangle, mapname.c_str(), GetMapId(), x, y, z);
                AccountMgr::RecordAntiCheatLog(GetSession()->GetAccountId(), GetName().c_str(), GetDescriptionACForLogs(5, diffz, distance), GetPositionACForLogs(), int32(realm.Id.Realm));
                return false;
            }
        }

        uint32 oldstime = GetLastMoveServerTimestamp();
        uint32 stime = GameTime::GetGameTimeMS();
        uint32 ping, realping;
        movetime = movementInfo.time;
        realping = GetSession()->GetLatency();
        ping = realping;
        if (ping < 60)
            ping = 60;

        if (!vehicle)
            speed = GetSpeed(MOVE_RUN);
        else
            speed = GetVehicleKit()->GetBase()->GetSpeed(MOVE_RUN);
        if (isSwimming())
        {
            if (!vehicle)
                speed = GetSpeed(MOVE_SWIM);
            else
                speed = GetVehicleKit()->GetBase()->GetSpeed(MOVE_SWIM);
        }
        if (IsFlying() || GetPlayerMovingMe()->CanFly())
        {
            if (!vehicle)
                speed = GetSpeed(MOVE_FLIGHT);
            else
                speed = GetVehicleKit()->GetBase()->GetSpeed(MOVE_FLIGHT);
        }

        delaysentrecieve = (ctime - oldstime) / 10000000000;
        delay = fabsf(movetime - stime) / 10000000000 + delaysentrecieve;
        difftime = (movetime - ctime + ping) * 0.001f + delay;
        normaldistance = speed * difftime; // if movetime faked and lower, difftime should be with "-"
        if (GetPlayerMovingMe()->UnderACKmount())
            normaldistance *= 3.0f;
        if (distance < normaldistance)
            return true;

        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  SpeedHack Detected for Account id : %u, Player %s", GetSession()->GetAccountId(), GetName().c_str());
        TC_LOG_INFO("anticheat", "Unit::========================================================");
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  oldX = %f", x);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  oldY = %f", y);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  newX = %f", npos.GetPositionX());
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  newY = %f", npos.GetPositionY());
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  packetdistance = %f", distance);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  available distance = %f", normaldistance);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  movetime = %f", movetime);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  delay sent ptk - recieve pkt (previous) = %f", delaysentrecieve);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  FullDelay = %f", delay);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  difftime = %f", difftime);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  real ping = %u", realping);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  Fping = %u", ping);

        sWorld->SendGMText(LANG_GM_ANNOUNCE_ASH, GetName().c_str(), normaldistance, distance);
        AccountMgr::RecordAntiCheatLog(GetSession()->GetAccountId(), GetName().c_str(), GetDescriptionACForLogs(0, distance, normaldistance), GetPositionACForLogs(), int32(realm.Id.Realm));
    }
    else
        return true;

    return false;
}

std::string Player::GetDescriptionACForLogs(uint8 type, float param1, float param2) const
{
    std::ostringstream str;

    switch (type)
    {
        case 0: // ASH
        {
            str << "AntiSpeedHack: distance from packet = " << param1 << ", available distance = " << param2;
            break;
        }
        case 1: // AFH - IsFlying but CanFly is false
        {
            str << "AntiFlyHack: Player IsFlying but CanFly is false";
            break;
        }
        case 2: // AFH - Player has a MOVEMENTFLAG_SWIMMING, but not in water
        {
            str << "AntiFlyHack: Player has a MOVEMENTFLAG_SWIMMING, but not in water";
            break;
        }
        case 3: // AFH - just z checks (smaughack)
        {
            str << "AntiFlyHack: Player::CheckOnFlyHack : playerZ = " << param1 << ", but normalZ = " << param2;
            break;
        }
        case 4: // Ignore control Hack
        {
            str << "Ignore controll Hack detected";
            break;
        }
        case 5: // Climb-Hack
        {
            str << "Climb-Hack detected , diffZ = " << param1 << ", distance = " << param2;
            break;
        }
        case 6: // doublejumper
        {
            str << "Double-jump detected";
            break;
        }
        case 7: // fakejumper
        {
            str << "FakeJumper detected";
            break;
        }
        case 8: // fakeflying
        {
            str << "FakeFlying mode detected";
            break;
        }
        default:
            break;
    }
    return str.str();
}

std::string Player::GetPositionACForLogs() const
{
    uint32 areaId = GetAreaId();
    std::string areaName = "Unknown";
    std::string zoneName = "Unknown";
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId))
    {
        int locale = GetSession()->GetSessionDbcLocale();
        areaName = area->area_name[locale];
        if (AreaTableEntry const* zone = sAreaTableStore.LookupEntry(area->zone))
            zoneName = zone->area_name[locale];
    }

    std::ostringstream str;
    str << "Map: " << GetMapId() << " (" << (FindMap() ? FindMap()->GetMapName() : "Unknown") << ") Area: " << areaId << " (" << areaName.c_str() << ") Zone: " << zoneName.c_str() << " XYZ: " << GetPositionX() << " " << GetPositionY() << " " << GetPositionZ();
    return str.str();
}
