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

#include "Anticheat.h"
#include "AccountMgr.h"
#include "DBCStoresMgr.h"
#include "GameTime.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "Player.h"
#include "Realm.h"
#include "Vehicle.h"
#include "World.h"
#include "WorldSession.h"

Anticheat::Anticheat(Player* player)
{
    pPlayer = player;
    m_skipOnePacketForASH = false;
    m_isjumping = false;
    m_canfly = false;
    m_ACKmounted = false;
    m_rootUpd = false;
    m_antiNoFallDmg = false;
    m_antiNoFallDmgLastChance = false;

    m_mountTimer = 0;
    m_rootUpdTimer = 0;
    m_flyhackTimer = 0;
    m_antiNoFallDmgTimer = 0;
    m_reloadModelsDisplayTimer = 0;

    lastMoveClientTimestamp = 0;
    lastMoveServerTimestamp = 0;
}

Anticheat::~Anticheat()
{
    m_skipOnePacketForASH = false;
    m_isjumping = false;
    m_canfly = false;
    m_ACKmounted = false;
    m_rootUpd = false;
    m_antiNoFallDmg = false;
    m_antiNoFallDmgLastChance = false;

    m_mountTimer = 0;
    m_rootUpdTimer = 0;
    m_flyhackTimer = 0;
    m_antiNoFallDmgTimer = 0;
    m_reloadModelsDisplayTimer = 0;

    lastMoveClientTimestamp = 0;
    lastMoveServerTimestamp = 0;
    pPlayer = nullptr;
}

// Anticheat System
void Anticheat::update(uint32 p_time)
{
    if (m_flyhackTimer >= 0)
    {
        if (p_time >= m_flyhackTimer)
        {
            if (!checkOnFlyHack() && sWorld->customGetBoolConfig(CONFIG_AFH_KICK_ENABLED))
                pPlayer->GetSession()->KickPlayer("AFH kicked by flyhackTimer");

            m_flyhackTimer = sWorld->customGetIntConfig(CONFIG_ANTICHEAT_FLYHACK_TIMER);
        }
        else
            m_flyhackTimer -= p_time;
    }

    if (m_reloadModelsDisplayTimer > 0)
    {
        if (p_time >= m_reloadModelsDisplayTimer)
        {
            pPlayer->RemoveAura(54844);
            m_reloadModelsDisplayTimer = 0;
        }
        else
            m_reloadModelsDisplayTimer -= p_time;
    }

    if (m_ACKmounted && m_mountTimer > 0)
    {
        if (p_time >= m_mountTimer)
        {
            m_mountTimer = 0;
            m_ACKmounted = false;
        }
        else
            m_mountTimer -= p_time;
    }

    if (m_rootUpd && m_rootUpdTimer > 0)
    {
        if (p_time >= m_rootUpdTimer)
        {
            m_rootUpdTimer = 0;
            m_rootUpd = false;
        }
        else
            m_rootUpdTimer -= p_time;
    }

    if (m_antiNoFallDmg && m_antiNoFallDmgTimer > 0)
    {
        if (p_time >= m_antiNoFallDmgTimer)
        {
            m_antiNoFallDmgTimer = 0;
            m_antiNoFallDmg = false;
            m_antiNoFallDmgLastChance = true;
        }
        else
            m_antiNoFallDmgTimer -= p_time;
    }
}

void Anticheat::punish(uint8 method)
{
    switch (method)
    {
        /* NoFallingDamage */
        case 1:
        {
            TC_LOG_INFO("anticheat", "MovementHandler::NoFallingDamage by Account id : {}, Player {}", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName());
            sWorld->SendGMText(LANG_GM_ANNOUNCE_NOFALLINGDMG, pPlayer->GetSession()->GetAccountId(), pPlayer->GetName().c_str());
            AccountMgr::RecordAntiCheatLog(pPlayer->GetSession()->GetAccountId(),
                pPlayer->GetName().c_str(),
                getDescriptionACForLogs(9),
                getPositionACForLogs(),
                int32(realm.Id.Realm));
            if (sWorld->customGetBoolConfig(CONFIG_ANTICHEAT_NOFALLINGDMG_KICK_ENABLED))
                pPlayer->GetSession()->KickPlayer("Kicked by anticheat::NoFallingDamage");
            break;
        }
        /* DOUBLE_JUMP */
        case 2:
        {
            TC_LOG_INFO("anticheat", "MovementHandler::DOUBLE_JUMP by Account id : {}, Player {}", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName());
            sWorld->SendGMText(LANG_GM_ANNOUNCE_DOUBLE_JUMP, pPlayer->GetName().c_str());
            AccountMgr::RecordAntiCheatLog(pPlayer->GetSession()->GetAccountId(),
                pPlayer->GetName().c_str(),
                getDescriptionACForLogs(6),
                getPositionACForLogs(),
                int32(realm.Id.Realm));
            if (sWorld->customGetBoolConfig(CONFIG_ANTICHEAT_DOUBLEJUMP_ENABLED))
                pPlayer->GetSession()->KickPlayer("Kicked by anticheat::DOUBLE_JUMP");
            break;
        }
        /* Fake_Jumper */
        case 3:
        {
            // fake jumper -> for example gagarin air mode with falling flag (like player jumping), but client can't sent a new coords when falling
            TC_LOG_INFO("anticheat", "MovementHandler::Fake_Jumper by Account id : {}, Player {}", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName());
            sWorld->SendGMText(LANG_GM_ANNOUNCE_JUMPER_FAKE, pPlayer->GetName().c_str());
            AccountMgr::RecordAntiCheatLog(pPlayer->GetSession()->GetAccountId(),
                pPlayer->GetName().c_str(),
                getDescriptionACForLogs(7),
                getPositionACForLogs(),
                int32(realm.Id.Realm));
            if (sWorld->customGetBoolConfig(CONFIG_FAKEJUMPER_KICK_ENABLED))
                pPlayer->GetSession()->KickPlayer("Kicked by anticheat::Fake_Jumper");
            break;
        }
        /* Fake_flying */
        case 4:
        {
            TC_LOG_INFO("anticheat", "MovementHandler::Fake_flying mode (using MOVEMENTFLAG_FLYING flag doesn't restricted) by Account id : {}, Player {}", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName());
            sWorld->SendGMText(LANG_GM_ANNOUNCE_JUMPER_FLYING, pPlayer->GetName().c_str());
            AccountMgr::RecordAntiCheatLog(pPlayer->GetSession()->GetAccountId(),
                pPlayer->GetName().c_str(),
                getDescriptionACForLogs(8),
                getPositionACForLogs(),
                int32(realm.Id.Realm));
            if (sWorld->customGetBoolConfig(CONFIG_FAKEFLYINGMODE_KICK_ENABLED))
                pPlayer->GetSession()->KickPlayer("Kicked by anticheat::Fake_flying mode");
            break;
        }
        default:
            break;
    }
}

void Anticheat::resetFallingData(float z)
{
    pPlayer->UpdateLastZ(z);

    if (isWaitingLandOrSwimOpcode())
        m_antiNoFallDmg = false;
    if (isUnderLastChanceForLandOrSwimOpcode())
        m_antiNoFallDmgLastChance = false;
}

void Anticheat::startWaitingLandOrSwimOpcode()
{
    m_antiNoFallDmgTimer = 3000;
    m_antiNoFallDmg = true;
}

void Anticheat::updateFallInformationIfNeed(float newZ)
{
    pPlayer->UpdateLastZ(newZ);
}

void Anticheat::setUnderACKmount()
{
    m_mountTimer = 3000;
    m_ACKmounted = true;
}

void Anticheat::setRootACKUpd(uint32 delay)
{
    m_rootUpdTimer = 1500 + delay;
    m_rootUpd = true;
}

void Anticheat::updateMovementInfo(MovementInfo const& movementInfo)
{
    setLastMoveClientTimestamp(movementInfo.time);
    setLastMoveServerTimestamp(GameTime::GetGameTimeMS());
}

bool Anticheat::checkOnFlyHack()
{
    if (sWorld->isAreaIdDisabledForAC(pPlayer->GetAreaId()))
        return true;

    if (isCanFlybyServer())
        return true;

    if (pPlayer->ToUnit()->IsFalling() || pPlayer->IsFalling())
        return true;

    if (pPlayer->IsFlying() && !pPlayer->CanFly()) // kick flyhacks
    {
        TC_LOG_INFO("anticheat", "Player::CheckMovementInfo :  FlyHack Detected for Account id : {}, Player {}", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName());
        TC_LOG_INFO("anticheat", "Player::========================================================");
        TC_LOG_INFO("anticheat", "Player IsFlying but CanFly is false");

        sWorld->SendGMText(LANG_GM_ANNOUNCE_AFH_CANFLYWRONG, pPlayer->GetName().c_str());
        AccountMgr::RecordAntiCheatLog(pPlayer->GetSession()->GetAccountId(),
            pPlayer->GetName().c_str(),
            getDescriptionACForLogs(1),
            getPositionACForLogs(),
            int32(realm.Id.Realm));
        return false;
    }

    if (pPlayer->IsFlying() || pPlayer->IsGravityDisabled() || pPlayer->IsInFlight())
        return true;

    if (pPlayer->GetTransport() || pPlayer->GetVehicle() || pPlayer->GetVehicleKit())
        return true;

    if (pPlayer->HasAuraType(SPELL_AURA_CONTROL_VEHICLE))
        return true;

    if (pPlayer->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
        return true;

    if (pPlayer->HasUnitState(UNIT_STATE_IGNORE_ANTISPEEDHACK))
        return true;

    if (underACKmount())
        return true;

    if (isSkipOnePacketForASH())
        return true;

    Position npos = pPlayer->GetPosition();
    float pz = npos.GetPositionZ();
    if (!pPlayer->IsInWater() && pPlayer->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
    {
        float waterlevel = pPlayer->GetMap()->GetWaterLevel(npos.GetPositionX(), npos.GetPositionY()); // water walking
        bool hovergaura = pPlayer->HasAuraType(SPELL_AURA_WATER_WALK) || pPlayer->HasAuraType(SPELL_AURA_HOVER);
        if (waterlevel && (pz - waterlevel) <= (hovergaura ? pPlayer->GetCollisionHeight() + 1.5f + pPlayer->GetHoverOffset() : pPlayer->GetCollisionHeight() + pPlayer->GetHoverOffset()))
            return true;

        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  FlyHack Detected for Account id : {}, Player {}", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName());
        TC_LOG_INFO("anticheat", "Player::========================================================");
        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  Player has a MOVEMENTFLAG_SWIMMING, but not in water");

        sWorld->SendGMText(LANG_GM_ANNOUNCE_AFK_SWIMMING, pPlayer->GetName().c_str());
        AccountMgr::RecordAntiCheatLog(pPlayer->GetSession()->GetAccountId(),
            pPlayer->GetName().c_str(),
            getDescriptionACForLogs(2),
            getPositionACForLogs(),
            int32(realm.Id.Realm));
        return false;
    }
    else
    {
        if (pPlayer->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
            return true;

        float z = pPlayer->GetMap()->GetHeight(pPlayer->GetPhaseMask(), npos.GetPositionX(), npos.GetPositionY(), pz + pPlayer->GetCollisionHeight() + 0.5f, true, 50.0f); // smart flyhacks -> SimpleFly
        float diff = pz - z;
        if (diff > 6.8f)
            if (diff > 6.8f + pPlayer->GetHoverOffset()) // better calculate the second time for false situations, but not call GetHoverOffset everytime (economy resource)
            {
                float waterlevel = pPlayer->GetMap()->GetWaterLevel(npos.GetPositionX(), npos.GetPositionY()); // water walking
                if (waterlevel && waterlevel + pPlayer->GetCollisionHeight() + pPlayer->GetHoverOffset() > pz)
                    return true;

                float cx, cy, cz;
                pPlayer->GetTheClosestPoint(cx, cy, cz, 0.5, pz, 6.8f); // first check
                if (pz - cz > 6.8f)
                {
                    // check dynamic collision for transport (TODO navmesh for transport map)
                    pPlayer->GetMap()->getObjectHitPos(pPlayer->GetPhaseMask(), pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ() + pPlayer->GetCollisionHeight(), cx, cy, cz + pPlayer->GetCollisionHeight(), cx, cy, cz, -pPlayer->GetCollisionHeight());

                    if (pz - cz > 6.8f)
                    {
                        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  FlyHack Detected for Account id : {}, Player {}", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName());
                        TC_LOG_INFO("anticheat", "Player::========================================================");
                        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  playerZ = {}", pz);
                        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  normalZ = {}", z);
                        TC_LOG_INFO("anticheat", "Player::CheckOnFlyHack :  checkz = {}", cz);
                        sWorld->SendGMText(LANG_GM_ANNOUNCE_AFH, pPlayer->GetName().c_str());
                        AccountMgr::RecordAntiCheatLog(pPlayer->GetSession()->GetAccountId(),
                            pPlayer->GetName().c_str(),
                            getDescriptionACForLogs(3, pz, z),
                            getPositionACForLogs(),
                            int32(realm.Id.Realm));
                        return false;
                    }
                }
            }
    }

    return true;
}

bool Anticheat::checkMovementInfo(MovementInfo const& movementInfo, bool jump)
{
    if (!sWorld->customGetBoolConfig(CONFIG_ANTICHEAT_SPEEDHACK_ENABLED))
        return true;

    if (sWorld->isAreaIdDisabledForAC(pPlayer->GetAreaId()))
        return true;

    uint32 oldctime = getLastMoveClientTimestamp();
    if (oldctime)
    {
        if (pPlayer->ToUnit()->IsFalling() || pPlayer->IsInFlight())
            return true;

        bool vehicle = false;
        if (pPlayer->GetVehicleKit() && pPlayer->GetVehicleKit()->GetBase())
            vehicle = true;

        if (pPlayer->GetVehicle())
            return true;

        if (!pPlayer->IsControlledByPlayer())
            return true;

        if (pPlayer->HasUnitState(UNIT_STATE_IGNORE_ANTISPEEDHACK))
            return true;

        if (isSkipOnePacketForASH())
        {
            setSkipOnePacketForASH(false);
            return true;
        }

        bool transportflag = movementInfo.GetMovementFlags() & MOVEMENTFLAG_ONTRANSPORT || pPlayer->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
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
            if (pPlayer->GetTransOffsetX() == 0.f) // if it elevator or fist step - player can have zero this coord
                return true;

            x = pPlayer->GetTransOffsetX();
            y = pPlayer->GetTransOffsetY();
            z = pPlayer->GetTransOffsetZ();
        }
        else
            pPlayer->GetPosition(x, y, z);

        if (sWorld->customGetBoolConfig(CONFIG_ANTICHEAT_IGNORE_CONTROL_MOVEMENT_ENABLED))
        {
            if (pPlayer->HasUnitState(UNIT_STATE_ROOT) && !underACKRootUpd())
            {
                bool unrestricted = npos.GetPositionX() != x || npos.GetPositionY() != y;
                if (unrestricted)
                {
                    TC_LOG_INFO("anticheat", "CheckMovementInfo :  Ignore controll Hack detected for Account id : {}, Player {}", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName());
                    sWorld->SendGMText(LANG_GM_ANNOUNCE_MOVE_UNDER_CONTROL, pPlayer->GetSession()->GetAccountId(), pPlayer->GetName().c_str());
                    AccountMgr::RecordAntiCheatLog(pPlayer->GetSession()->GetAccountId(),
                        pPlayer->GetName().c_str(),
                        getDescriptionACForLogs(4),
                        getPositionACForLogs(),
                        int32(realm.Id.Realm));
                    return false;
                }
            }
        }

        float flyspeed = 0.f;
        float distance, runspeed, difftime, normaldistance, delay, diffPacketdelay;
        uint32 ptime;
        std::string mapname = pPlayer->GetMap()->GetMapName();

        // calculate distance - don't use func, because x,z can be offset transport coords
        distance = sqrt((npos.GetPositionY() - y) * (npos.GetPositionY() - y) + (npos.GetPositionX() - x) * (npos.GetPositionX() - x));

        if (!jump && !pPlayer->CanFly() && !pPlayer->isSwimming() && !transportflag)
        {
            float diffz = fabs(movementInfo.pos.GetPositionZ() - z);
            float tanangle = distance / diffz;

            if (movementInfo.pos.GetPositionZ() > z &&
                diffz > 1.87f &&
                tanangle < 0.57735026919f) // 30 degrees
            {
                TC_LOG_INFO("anticheat", "Player::CheckMovementInfo :  Climb-Hack detected for Account id : {}, Player {}, diffZ = {}, distance = {}, angle = {}, Map = {}, mapId = {}, X = {}, Y = {}, Z = {}",
                    pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), diffz, distance, tanangle, mapname, pPlayer->GetMapId(), x, y, z);
                sWorld->SendGMText(LANG_GM_ANNOUNCE_WALLCLIMB, pPlayer->GetSession()->GetAccountId(), pPlayer->GetName().c_str(), diffz, distance, tanangle, mapname.c_str(), pPlayer->GetMapId(), x, y, z);
                AccountMgr::RecordAntiCheatLog(pPlayer->GetSession()->GetAccountId(),
                    pPlayer->GetName().c_str(),
                    getDescriptionACForLogs(5, diffz, distance),
                    getPositionACForLogs(),
                    int32(realm.Id.Realm));
                return false;
            }
        }

        uint32 oldstime = getLastMoveServerTimestamp();
        uint32 stime = GameTime::GetGameTimeMS();
        uint32 ping;
        ptime = movementInfo.time;

        if (!vehicle)
            runspeed = pPlayer->GetSpeed(MOVE_RUN);
        else
            runspeed = pPlayer->GetVehicleKit()->GetBase()->GetSpeed(MOVE_RUN);

        if (pPlayer->isSwimming())
        {
            if (!vehicle)
                runspeed = pPlayer->GetSpeed(MOVE_SWIM);
            else
                runspeed = pPlayer->GetVehicleKit()->GetBase()->GetSpeed(MOVE_SWIM);
        }

        if (pPlayer->IsFlying() || pPlayer->CanFly())
        {
            if (!vehicle)
                flyspeed = pPlayer->GetSpeed(MOVE_FLIGHT);
            else
                flyspeed = pPlayer->GetVehicleKit()->GetBase()->GetSpeed(MOVE_FLIGHT);
        }

        if (flyspeed > runspeed)
            runspeed = flyspeed;

        delay = ptime - oldctime;
        diffPacketdelay = 10000000 - delay;

        if (oldctime > ptime)
        {
            TC_LOG_INFO("anticheat", "oldctime > ptime");
            delay = 0;
        }
        diffPacketdelay = diffPacketdelay * 0.0000000001f;
        difftime = delay * 0.001f + diffPacketdelay;

        // if movetime faked and lower, difftime should be with "-"
        normaldistance = (runspeed * difftime) + 0.002f; // 0.002f a little safe temporary hack
        if (underACKmount())
            normaldistance += 20.0f;
        if (distance < normaldistance)
            return true;

        ping = uint32(diffPacketdelay * 10000.f);

        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  SpeedHack Detected for Account id : {}, Player {}", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName());
        TC_LOG_INFO("anticheat", "Unit::========================================================");
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  oldX = {}", x);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  oldY = {}", y);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  newX = {}", npos.GetPositionX());
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  newY = {}", npos.GetPositionY());
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  packetdistance = {}", distance);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  available distance = {}", normaldistance);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  oldStime = {}", oldstime);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  oldCtime = {}", oldctime);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  serverTime = {}", stime);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  packetTime = {}", ptime);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  diff delay between old ptk and current pkt = {}", diffPacketdelay);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  FullDelay = {}", delay / 1000.f);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  difftime = {}", difftime);
        TC_LOG_INFO("anticheat", "Unit::CheckMovementInfo :  ping = {}", ping);

        sWorld->SendGMText(LANG_GM_ANNOUNCE_ASH, pPlayer->GetName().c_str(), normaldistance, distance);
        AccountMgr::RecordAntiCheatLog(pPlayer->GetSession()->GetAccountId(),
            pPlayer->GetName().c_str(),
            getDescriptionACForLogs(0, distance, normaldistance),
            getPositionACForLogs(),
            int32(realm.Id.Realm));
    }
    else
        return true;

    return false;
}

std::string Anticheat::getDescriptionACForLogs(uint8 type, float param1, float param2) const
{
    std::string str = "";
    switch (type)
    {        
        case 0: // ASH
        {
            str = fmt::format("AntiSpeedHack: distance from packet =  {}, available distance = {}", param1, param2);
            break;
        }
        case 1: // AFH - IsFlying but CanFly is false
        {
            str = "AntiFlyHack: Player IsFlying but CanFly is false";
            break;
        }
        case 2: // AFH - Player has a MOVEMENTFLAG_SWIMMING, but not in water
        {
            str = "AntiFlyHack: Player has a MOVEMENTFLAG_SWIMMING, but not in water";
            break;
        }
        case 3: // AFH - just z checks (smaughack)
        {
            str = fmt::format("AntiFlyHack: Player::CheckOnFlyHack : playerZ = {}, but normalZ = {}", param1, param2);
            break;
        }
        case 4: // Ignore control Hack
        {
            str = "Ignore controll Hack detected";
            break;
        }
        case 5: // Climb-Hack
        {
            str = fmt::format("Climb-Hack detected , diffZ =  {}, distance = {}", param1, param2);
            break;
        }
        case 6: // doublejumper
        {
            str = "Double-jump detected";
            break;
        }
        case 7: // fakejumper
        {
            str = "FakeJumper detected";
            break;
        }
        case 8: // fakeflying
        {
            str = "FakeFlying mode detected";
            break;
        }
        case 9: // NoFallingDmg
        {
            str = "NoFallingDamage mode detected";
            break;
        }
        default:
            break;
    }
    return str;
}

std::string Anticheat::getPositionACForLogs() const
{
    uint32 areaId = pPlayer->GetAreaId();
    std::string areaName = "Unknown";
    std::string zoneName = "Unknown";
    if (AreaTableDBC const* area = sDBCStoresMgr->GetAreaTableDBC(areaId))
    {
        int locale = pPlayer->GetSession()->GetSessionDbcLocale();
        areaName = area->AreaName[locale];
        if (AreaTableDBC const* zone = sDBCStoresMgr->GetAreaTableDBC(area->ParentAreaID))
            zoneName = zone->AreaName[locale];
    }

    return fmt::format("Map: {} ({}) Area: {} ({}) Zone: {} XYZ: {} {} {}", pPlayer->GetMapId(), pPlayer->FindMap() ? pPlayer->FindMap()->GetMapName() : "Unknown", areaId, areaName.c_str(), zoneName.c_str(), pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ());
}

void Anticheat::setReloadModelsDisplayTimer()
{
    pPlayer->CastSpell(pPlayer, 54844, true);
    m_reloadModelsDisplayTimer = 500;
    m_flyhackTimer = 3000;
}
