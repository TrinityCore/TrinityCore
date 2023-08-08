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

#include "AnticheatMgr.h"
#include "AnticheatScripts.h"
#include "AccountMgr.h"
#include "Battleground.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SharedDefines.h"
#include "SpellAuras.h"
#include "World.h"
#include "WorldSession.h"

constexpr auto LANG_ANTICHEAT_ALERT = 30087;
constexpr auto LANG_ANTICHEAT_TELEPORT = 30088;
constexpr auto LANG_ANTICHEAT_IGNORECONTROL = 30089;
constexpr auto LANG_ANTICHEAT_DUEL = 30090;
constexpr auto LANG_ANTICHEAT_BG_EXPLOIT = 30091;
constexpr auto LANG_ANTICHEAT_COUNTERMEASURE = 30092;

// Time between server sends acknowledgement, and client is actually acknowledged
constexpr auto ALLOWED_ACK_LAG = 2000;

enum Spells
{
    SHACKLES = 38505,
    LFG_SPELL_DUNGEON_DESERTER = 71041,
    BG_SPELL_DESERTER = 26013,
    SILENCED = 23207,
    RESURRECTION_SICKNESS = 15007,
    SLOWDOWN = 61458
};

AnticheatMgr::AnticheatMgr()
{
    /*
    **    May you do good and not evil.
    **    May you find forgiveness for yourself and forgive others.
    **    May you share freely, never taking more than you give.
    **    CTHULHU is watching ^(;,;)^
    */
    _opackorders =
    {
        { SMSG_FORCE_WALK_SPEED_CHANGE, CMSG_FORCE_WALK_SPEED_CHANGE_ACK },
        { SMSG_FORCE_RUN_SPEED_CHANGE, CMSG_FORCE_RUN_SPEED_CHANGE_ACK },
        { SMSG_FORCE_RUN_BACK_SPEED_CHANGE, CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK },
        { SMSG_FORCE_SWIM_SPEED_CHANGE, CMSG_FORCE_SWIM_SPEED_CHANGE_ACK },
        { SMSG_FORCE_SWIM_BACK_SPEED_CHANGE, CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK },
        { SMSG_FORCE_TURN_RATE_CHANGE, CMSG_FORCE_TURN_RATE_CHANGE_ACK },
        { SMSG_FORCE_PITCH_RATE_CHANGE, CMSG_FORCE_PITCH_RATE_CHANGE_ACK },
        { SMSG_FORCE_FLIGHT_SPEED_CHANGE, CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK },
        { SMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE, CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK },
        { SMSG_FORCE_MOVE_ROOT, CMSG_FORCE_MOVE_ROOT_ACK },
        { SMSG_FORCE_MOVE_UNROOT, CMSG_FORCE_MOVE_UNROOT_ACK },
        { SMSG_MOVE_KNOCK_BACK, CMSG_MOVE_KNOCK_BACK_ACK },
        { SMSG_MOVE_FEATHER_FALL, SMSG_MOVE_NORMAL_FALL, CMSG_MOVE_FEATHER_FALL_ACK },
        { SMSG_MOVE_SET_HOVER, SMSG_MOVE_UNSET_HOVER, CMSG_MOVE_HOVER_ACK },
        { SMSG_MOVE_SET_CAN_FLY, SMSG_MOVE_UNSET_CAN_FLY, CMSG_MOVE_SET_CAN_FLY_ACK },
        { SMSG_MOVE_WATER_WALK, SMSG_MOVE_LAND_WALK, CMSG_MOVE_WATER_WALK_ACK },
        { SMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY, SMSG_MOVE_UNSET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY, CMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY_ACK },
        { SMSG_MOVE_GRAVITY_ENABLE, CMSG_MOVE_GRAVITY_ENABLE_ACK },
        { SMSG_MOVE_GRAVITY_DISABLE, CMSG_MOVE_GRAVITY_DISABLE_ACK },
        { SMSG_MOVE_SET_COLLISION_HGT, CMSG_MOVE_SET_COLLISION_HGT_ACK }
    };
}

AnticheatMgr::~AnticheatMgr()
{
    m_Players.clear();
}

void AnticheatMgr::LoadBlockedLuaFunctions()
{
    if (!sWorld->getBoolConfig(CONFIG_LUABLOCKER_ENABLE))
    {
        TC_LOG_INFO("server.loading", ">> Anticheat.LUAblocker conf is set to 0");
        return;
    }
    uint32 oldmsTime = getMSTime();
    auto pstmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_ANTICHEAT_FUNCTIONS);
    auto result = WorldDatabase.Query(pstmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Anticheat loaded 0 LUA blocked private functions");
        return;
    }
    uint32 count = 0;
    do
    {
        auto fields = result->Fetch();
        _luaBlockedFunctions[fields[0].GetString()] = fields[1].GetBool();
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Anticheat loaded %u LUA blocked private functions in %u ms", count, GetMSTimeDiffToNow(oldmsTime));
}

void AnticheatMgr::SaveLuaCheater(uint32 guid, uint32 accountId, std::string macro)
{
    auto pstmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ANTICHEAT_LUA_CHEATERS);
    pstmt->setUInt32(0, guid);
    pstmt->setUInt32(1, accountId);
    pstmt->setString(2, macro);
    CharacterDatabase.Execute(pstmt);
}

bool AnticheatMgr::CheckIsLuaCheater(uint32 accountId)
{
    auto pstmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ANTICHEAT_LUA_CHEATERS);
    pstmt->setUInt32(0, accountId);
    auto result = CharacterDatabase.Query(pstmt);
    if (result)
        return true;

    return false;
}

bool AnticheatMgr::CheckBlockedLuaFunctions(AccountData accountData[NUM_ACCOUNT_DATA_TYPES], Player* player)
{
    for (auto& kv : _luaBlockedFunctions)
    {
        for (uint8 i = 0; i < NUM_ACCOUNT_DATA_TYPES; ++i)
        {
            std::string currentData = accountData[i].Data;
            std::size_t pos = currentData.find(kv.first);
            if (pos != std::string::npos)
            {
                // Code inside this if statement block will only execute if the variable 'pos' is not equal to std::string::npos.
                // std::string::npos is a special value indicating the absence of a valid position.
                // The following below is all done to capture the macro used and stored it in the SaveLuaCheater

                const static std::size_t defaultLength = 200;
                // Declares a constant variable 'defaultLength' with a value of 200.
                // This variable represents the default length of a substring to be extracted.

                std::size_t minPos = int64(int(pos) - 50) < 0 ? 0 : pos - 50;
                // Calculates the minimum position from where the substring will be extracted.
                // It subtracts 50 from the 'pos' value, casts it to int64, and checks if it's less than 0.
                // If it is less than 0, sets 'minPos' to 0, otherwise sets 'minPos' to 'pos - 50'.
                // With out the - 50 we will get a crash on certain substrings

                std::size_t length = defaultLength + minPos > currentData.length() - 1 ? currentData.length() - minPos : defaultLength;
                // Calculates the length of the substring to be extracted.
                // It adds 'defaultLength' to 'minPos' and checks if it's greater than the length of 'currentData' minus 1.
                // If it is greater, sets 'length' to 'currentData.length() - minPos', otherwise sets it to 'defaultLength'.

                std::string macro = currentData.substr(minPos, length);
                // Extracts a substring from 'currentData' starting at 'minPos' with a length of 'length' and assigns it to the variable 'macro'.

                if (player)
                {
                    // Checks if the 'player' pointer is not null (i.e., it points to a valid object, aka The NULL CHECK).

                    TC_LOG_INFO("anticheat", "ANTICHEAT COUNTER MEASURE::Player %s has inaccessible LUA MACRO, placing on watch list", player->GetName().c_str());
                    // Outputs a log message indicating that the player has an inaccessible Lua macro and is being placed on a watch list.

                    SaveLuaCheater(player->GetGUID(), player->GetSession()->GetAccountId(), macro);
                    // Calls the 'SaveLuaCheater' function, passing in the player's GUID, session account ID, and the 'macro' string.
                    // This function saves information about the Lua cheater, such as the id of the player account, character, and macro used, for further analysis or enforcement actions.
                }

                return true;
            }
        }
    }

    return false;
}

void AnticheatMgr::StartHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
        return;

    // GMs are the enforcer of the server, they should be exempt.
    if (player->IsGameMaster())
        return;

    uint32 key = player->GetGUID().GetCounter();

    if (player->IsInFlight() || player->GetTransport() || player->GetVehicle())
    {
        m_Players[key].SetLastMovementInfo(movementInfo);
        m_Players[key].SetLastOpcode(opcode);
        return;
    }

    // Dear future me. Please forgive me.
    // I can't even begin to express how sorry I am for this order
    // If you bought this you have been scammed.
    // Visit TC: https://discord.com/invite/HPP3wNh for help on the Open Source Anticheat
    // The project compromised of various developers of the open source scene and we hang out there.
    // We would never charge for modules or "lessons"
    SpeedHackDetection(player, movementInfo);
    FlyHackDetection(player, movementInfo);
    TeleportHackDetection(player, movementInfo);
    JumpHackDetection(player, movementInfo, opcode);
    TeleportPlaneHackDetection(player, movementInfo, opcode);
    ClimbHackDetection(player, movementInfo, opcode);
    IgnoreControlHackDetection(player, movementInfo, opcode);
    GravityHackDetection(player, movementInfo);
    if (player->GetLiquidStatus() == LIQUID_MAP_WATER_WALK)
    {
        WalkOnWaterHackDetection(player, movementInfo);
    }
    else
    {
        ZAxisHackDetection(player, movementInfo);
    }
    if (player->GetLiquidStatus() == LIQUID_MAP_UNDER_WATER)
    {
        AntiSwimHackDetection(player, movementInfo, opcode);
    }
    AntiKnockBackHackDetection(player, movementInfo);
    NoFallDamageDetection(player, movementInfo);
    if (Battleground* bg = player->GetBattleground())
    {
        if (bg->GetStatus() == STATUS_WAIT_JOIN)
        {
            BGStartExploit(player, movementInfo);
        }
    }
    m_Players[key].SetLastMovementInfo(movementInfo);
    m_Players[key].SetLastOpcode(opcode);
}

void AnticheatMgr::SpeedHackDetection(Player* player, MovementInfo movementInfo)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_SPEEDHACK_ENABLE))
        return;

    uint32 key = player->GetGUID().GetCounter();

    // We also must check the map because the movementFlag can be modified by the client.
    // If we just check the flag, they could always add that flag and always skip the speed hacking detection.
    // Abandon all hope ye who enter beyond this point
    // We exempt all transports found in 335 to prevent false speed hack hits
    if (m_Players[key].GetLastMovementInfo().HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT) && player->GetMapId())
    {
        switch (player->GetMapId())
        {
        case 369: //Transport: DEEPRUN TRAM
        case 607: //Transport: Strands of the Ancients
        case 582: //Transport: Rut'theran to Auberdine
        case 584: //Transport: Menethil to Theramore
        case 586: //Transport: Exodar to Auberdine
        case 587: //Transport: Feathermoon Ferry
        case 588: //Transport: Menethil to Auberdine
        case 589: //Transport: Orgrimmar to Grom'Gol
        case 590: //Transport: Grom'Gol to Undercity
        case 591: //Transport: Undercity to Orgrimmar
        case 592: //Transport: Borean Tundra Test
        case 593: //Transport: Booty Bay to Ratchet
        case 594: //Transport: Howling Fjord Sister Mercy (Quest)
        case 596: //Transport: Naglfar
        case 610: //Transport: Tirisfal to Vengeance Landing
        case 612: //Transport: Menethil to Valgarde
        case 613: //Transport: Orgrimmar to Warsong Hold
        case 614: //Transport: Stormwind to Valiance Keep
        case 620: //Transport: Moa'ki to Unu'pe
        case 621: //Transport: Moa'ki to Kamagua
        case 622: //Transport: Orgrim's Hammer
        case 623: //Transport: The Skybreaker
        case 641: //Transport: Alliance Airship BG
        case 642: //Transport: Horde Airship BG
        case 647: //Transport: Orgrimmar to Thunder Bluff
        case 672: //Transport: The Skybreaker (Icecrown Citadel Raid)
        case 673: //Transport: Orgrim's Hammer (Icecrown Citadel Raid)
        case 712: //Transport: The Skybreaker (IC Dungeon)
        case 713: //Transport: Orgrim's Hammer (IC Dungeon)
        case 718: //Transport: The Mighty Wind (Icecrown Citadel Raid)
            return;
        }
    }

    // sometimes I believe the compiler ignores all my comments
    uint32 distance2D = (uint32)movementInfo.pos.GetExactDist2d(&m_Players[key].GetLastMovementInfo().pos);

    // We don't need to check for a speedhack if the player hasn't moved
    // This is necessary since MovementHandler fires if you rotate the camera in place
    if (!distance2D)
        return;

    uint8 moveType = 0;

    // we need to know HOW is the player moving
    // TO-DO: Should we check the incoming movement flags?
    if (player->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
        moveType = MOVE_SWIM;
    else if (player->IsFlying())
        moveType = MOVE_FLIGHT;
    else if (player->HasUnitMovementFlag(MOVEMENTFLAG_WALKING))
        moveType = MOVE_WALK;
    else
        moveType = MOVE_RUN;

    // how many yards the player can do in one sec.
    // We remove the added speed for jumping because otherwise permanently jumping doubles your allowed speed
    uint32 speedRate = (uint32)(player->GetSpeed(UnitMoveType(moveType)));

    // how long the player took to move to here.
    uint32 timeDiff = getMSTimeDiff(m_Players[key].GetLastMovementInfo().time, movementInfo.time);

    // Ah ah ah! You'll never understand why this one works. Or will you?
    // This covers packet manipulation
    if (int32(timeDiff) < 0 && sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_TIMEMANIPULATION))
    {
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_WRITELOG))
        {
            uint32 latency = player->GetSession()->GetLatency();
            std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
            TC_LOG_INFO("anticheat", "AnticheatMgr:: Time Manipulation - Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
        }
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTSCREEN))
        {   // display warning at the center of the screen, hacky way?
            std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] TIME MANIPULATION COUNTER MEASURE ALERT";
            WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
            data << str;
            sWorld->SendGlobalGMMessage(&data);
        }
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTCHAT))
        {
            std::string str = "|cFFFFFC00 TIME MANIPULATION COUNTER MEASURE ALERT";
            sWorld->SendGMText(LANG_ANTICHEAT_COUNTERMEASURE, str.c_str(), player->GetName().c_str(), player->GetName().c_str());
        }
        timeDiff = 1;
        BuildReport(player, COUNTER_MEASURES_REPORT);
    }

    if (!timeDiff && sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_TIMEMANIPULATION))
    {
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_WRITELOG))
        {
            std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
            TC_LOG_INFO("anticheat", "ANTICHEAT COUNTER MEASURE:: %s Time Diff Corrected(Map: %u) (possible Zero Time Manipulation) - Flagged at: %s", player->GetName().c_str(), player->GetMapId(), goXYZ.c_str());
        }
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTSCREEN))
        {   // display warning at the center of the screen, hacky way?
            std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] TIME MANIPULATION COUNTER MEASURE ALERT";
            WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
            data << str;
            sWorld->SendGlobalGMMessage(&data);
        }
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTCHAT))
        {
            std::string str = "|cFFFFFC00 TIME MANIPULATION COUNTER MEASURE ALERT";
            sWorld->SendGMText(LANG_ANTICHEAT_COUNTERMEASURE, str.c_str(), player->GetName().c_str(), player->GetName().c_str());
        }
        timeDiff = 1;
        BuildReport(player, COUNTER_MEASURES_REPORT);
    }

    // this is the distance doable by the player in 1 sec, using the time done to move to this point.
    uint32 clientSpeedRate = distance2D * 1000 / timeDiff; // Only Chuck Norris can divide by zero so we divide by 1

    // we create a diff speed in uint32 for further precision checking to avoid legit fall and slide

    // create a conf to establish a speed limit tolerance over server rate set speed
    // this is done so we can ignore minor violations that are not false positives such as going 1 or 2 over the speed limit
    _assignedspeeddiff = sWorld->getIntConfig(CONFIG_ANTICHEAT_SPEED_LIMIT_TOLERANCE);

    // We did the (uint32) cast to accept a margin of tolerance for seasonal spells and buffs such as sugar rush
    // We check the last MovementInfo for the falling flag since falling down a hill and sliding a bit triggered a false positive
    if ((clientSpeedRate >= _assignedspeeddiff + speedRate) && !m_Players[key].GetLastMovementInfo().HasMovementFlag(MOVEMENTFLAG_FALLING))
    {

        if (!player->CanTeleport())
        {
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                uint32 latency = 0;
                latency = player->GetSession()->GetLatency();
                std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                TC_LOG_INFO("anticheat", "AnticheatMgr:: Speed-Hack (Speed Movement at %u above allowed Server Set rate %u.) detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", clientSpeedRate, speedRate, player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
            }
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_SPEEDHACK))
            {
                if (Aura* slowcheater = player->AddAura(SLOWDOWN, player))// SLOWDOWN
                {
                    slowcheater->SetDuration(1000);
                }
                BuildReport(player, SPEED_HACK_REPORT);
                if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_WRITELOG))
                {
                    std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                    TC_LOG_INFO("anticheat.module", "ANTICHEAT COUNTER MEASURE:: %s Speed Hack Countered and has been set to Server Rate - Flagged at: %s", player->GetName().c_str(), goXYZ.c_str());
                }
                if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTSCREEN))
                {   // display warning at the center of the screen, hacky way?
                    std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] SPEED HACK COUNTER MEASURE ALERT";
                    WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
                    data << str;
                    sWorld->SendGlobalGMMessage(&data);
                }
                if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTCHAT))
                {
                    std::string str = "|cFFFFFC00 SPEED HACK COUNTER MEASURE ALERT";
                    sWorld->SendGMText(LANG_ANTICHEAT_COUNTERMEASURE, str.c_str(), player->GetName().c_str(), player->GetName().c_str());
                }
                BuildReport(player, COUNTER_MEASURES_REPORT);
            }
            BuildReport(player, SPEED_HACK_REPORT);
        }
        return;
    }
}

void AnticheatMgr::FlyHackDetection(Player* player, MovementInfo movementInfo)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_FLYHACK_ENABLE))
        return;

    uint32 key = player->GetGUID().GetCounter();

    //we check to ensure they are not flying
    if (!m_Players[key].GetLastMovementInfo().HasMovementFlag(MOVEMENTFLAG_FLYING))
        return;

    //we check to see if they have legal flight auras
    if (player->HasAuraType(SPELL_AURA_FLY) ||
        player->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) ||
        player->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED))
        return;

    /*Thanks to @LilleCarl for info to check extra flag*/
    bool stricterChecks = true;
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_FLYHACKSTRICT_ENABLE))
    {// super strict way to check, you can only ascend\descend in water and air, we check u are ascending\descending and not in water.
     // we are not checking for legal flight here because those checks were dont earlier.
        stricterChecks = !(movementInfo.HasMovementFlag(MOVEMENTFLAG_ASCENDING | MOVEMENTFLAG_DESCENDING) && !player->IsInWater());
    }

    // if you are not flying and not ascending then we do a return, you are then not guilty.
    if (!movementInfo.HasMovementFlag(MOVEMENTFLAG_CAN_FLY) && !movementInfo.HasMovementFlag(MOVEMENTFLAG_FLYING) && stricterChecks)
    {
        return;
    }

    if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
    {
        uint32 latency = 0;
        latency = player->GetSession()->GetLatency();
        std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
        TC_LOG_INFO("anticheat", "AnticheatMgr:: Fly-Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
    }
    if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_FLYHACK))
    {   // display warning at the center of the screen, hacky way?
        std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] FLY HACK COUNTER MEASURE ALERT";
        WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
        data << str;
        sWorld->SendGlobalGMMessage(&data);

        // Drop them with a op code set if they use a exploit or hack app
        WorldPacket cheater(12);
        cheater.SetOpcode(SMSG_MOVE_UNSET_CAN_FLY);

        cheater << player->GetPackGUID();
        cheater << uint32(0);
        player->SendMessageToSet(&cheater, true);

        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTCHAT))
        {
            std::string str = "|cFFFFFC00 FLY HACK COUNTER MEASURE ALERT";
            sWorld->SendGMText(LANG_ANTICHEAT_COUNTERMEASURE, str.c_str(), player->GetName().c_str(), player->GetName().c_str());
        }
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_WRITELOG))
        {
            std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
            TC_LOG_INFO("anticheat", "ANTICHEAT COUNTER MEASURE:: Fly Hack detected player %s (%s) - SMSG_MOVE_UNSET_CAN_FLY Set - Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), goXYZ.c_str());
        }
        BuildReport(player, COUNTER_MEASURES_REPORT);
    }

    BuildReport(player, FLY_HACK_REPORT);
}

void AnticheatMgr::JumpHackDetection(Player* player, MovementInfo  movementInfo, uint32 opcode)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_JUMPHACK_ENABLE))
        return;

    // we pull the player's individual guid
    uint32 key = player->GetGUID().GetCounter();

    const float ground_Z = movementInfo.pos.GetPositionZ() - player->GetMapHeight(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY(), movementInfo.pos.GetPositionZ());

    const bool no_fly_auras = !(player->HasAuraType(SPELL_AURA_FLY) || player->HasAuraType(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED)
        || player->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) || player->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED)
        || player->HasAuraType(SPELL_AURA_MOD_MOUNTED_FLIGHT_SPEED_ALWAYS));
    const bool no_fly_flags = ((movementInfo.flags & (MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING)) == 0);
    const bool no_swim_in_water = !player->IsInWater();
    const bool no_swim_above_water = movementInfo.pos.GetPositionZ() - 7.0f >= player->GetMap()->GetWaterLevel(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY());
    const bool no_swim_water = no_swim_in_water && no_swim_above_water;

    // Chain or double multi jumping is not a thing in 335
    if (m_Players[key].GetLastOpcode() == MSG_MOVE_JUMP && opcode == MSG_MOVE_JUMP)
    {
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
        {
            uint32 latency = 0;
            latency = player->GetSession()->GetLatency();
            std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
            TC_LOG_INFO("anticheat", "AnticheatMgr:: Jump-Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
        }
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_JUMPHACK))
        {   // display warning at the center of the screen, hacky way?
            std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] JUMP HACK COUNTER MEASURE ALERT";
            WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
            data << str;
            sWorld->SendGlobalGMMessage(&data);

            player->GetMotionMaster()->MoveFallPlayer();

            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_WRITELOG))
            {
                std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                TC_LOG_INFO("anticheat.module", "ANTICHEAT COUNTER MEASURE:: %s JUMP Hack Countered and has been set to fall - Flagged at: %s", player->GetName().c_str(), goXYZ.c_str());
            }
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTSCREEN))
            {   // display warning at the center of the screen, hacky way?
                std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] JUMP HACK COUNTER MEASURE ALERT";
                WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
                data << str;
                sWorld->SendGlobalGMMessage(&data);
            }
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTCHAT))
            {
                std::string str = "|cFFFFFC00 JUMP HACK COUNTER MEASURE ALERT";
                sWorld->SendGMText(LANG_ANTICHEAT_COUNTERMEASURE, str.c_str(), player->GetName().c_str(), player->GetName().c_str());
            }
            BuildReport(player, COUNTER_MEASURES_REPORT);
        }
        BuildReport(player, JUMP_HACK_REPORT);
    }
    else if (no_fly_auras && no_fly_flags && no_swim_water)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ADV_JUMPHACK_ENABLE))
            return;

        if (m_Players[key].GetLastOpcode() == MSG_MOVE_JUMP && !player->IsFalling())
            return;

        uint32 distance2D = (uint32)movementInfo.pos.GetExactDist2d(&m_Players[key].GetLastMovementInfo().pos);

        // This is necessary since MovementHandler fires if you rotate the camera in place
        if (!distance2D)
            return;

        if (!player->HasUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY) && movementInfo.jump.zspeed < -10.0f)
            return;

        if (player->HasAuraType(SPELL_AURA_WATER_WALK) || player->HasAuraType(SPELL_AURA_FEATHER_FALL) ||
            player->HasAuraType(SPELL_AURA_SAFE_FALL))
        {
            return;
        }

        // We exempt select areas found in 335 to prevent false hack hits
        if (player->GetAreaId())
        {
            switch (player->GetAreaId())
            {
                case 4273: //Celestial Planetarium Observer Battle has a narrow path that false flags
                    return;
            }
        }

        if (ground_Z > 5.0f && movementInfo.pos.GetPositionZ() >= player->GetPositionZ())
        {
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                uint32 latency = 0;
                latency = player->GetSession()->GetLatency();
                std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                TC_LOG_INFO("anticheat", "AnticheatMgr:: Stricter Jump-Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
            }
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ADVJUMPHACK))
            {   // display warning at the center of the screen, hacky way?
                std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] ADVANCE JUMP HACK COUNTER MEASURE ALERT";
                WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
                data << str;
                sWorld->SendGlobalGMMessage(&data);

                player->GetMotionMaster()->MoveFallPlayer();

                if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_WRITELOG))
                {
                    std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                    TC_LOG_INFO("anticheat.module", "ANTICHEAT COUNTER MEASURE:: %s ADVANCE JUMP Hack Countered and has been set to fall - Flagged at: %s", player->GetName().c_str(), goXYZ.c_str());
                }
                if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTSCREEN))
                {   // display warning at the center of the screen, hacky way?
                    std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] ADVANCE JUMP HACK COUNTER MEASURE ALERT";
                    WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
                    data << str;
                    sWorld->SendGlobalGMMessage(&data);
                }
                if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTCHAT))
                {
                    std::string str = "|cFFFFFC00 ADVANCE JUMP HACK COUNTER MEASURE ALERT";
                    sWorld->SendGMText(LANG_ANTICHEAT_COUNTERMEASURE, str.c_str(), player->GetName().c_str(), player->GetName().c_str());
                }
                BuildReport(player, COUNTER_MEASURES_REPORT);
            }
            BuildReport(player, JUMP_HACK_REPORT);
        }
    }
}

void AnticheatMgr::TeleportPlaneHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_TELEPANEHACK_ENABLE))
        return;

    if (player->HasAuraType(SPELL_AURA_WATER_WALK) || player->HasAuraType(SPELL_AURA_WATER_BREATHING) || player->HasAuraType(SPELL_AURA_GHOST))
        return;

    uint32 key = player->GetGUID().GetCounter();

    uint32 distance2D = (uint32)movementInfo.pos.GetExactDist2d(&m_Players[key].GetLastMovementInfo().pos);

    // We don't need to check for a water walking hack if the player hasn't moved
    // This is necessary since MovementHandler fires if you rotate the camera in place
    if (!distance2D)
        return;

    if (m_Players[key].GetLastOpcode() == MSG_MOVE_JUMP)
        return;

    if (opcode == (MSG_MOVE_FALL_LAND))
        return;

    if (player->GetLiquidStatus() == LIQUID_MAP_ABOVE_WATER)
        return;

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_SWIMMING))
        return;

    // If he is flying we dont need to check
    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING))
        return;

    // We exempt select areas found in 335 to prevent false hack hits
    if (player->GetAreaId())
    {
        switch (player->GetAreaId())
        {
            case 4273: //Celestial Planetarium Observer Battle has a narrow path that false flags
                return;
        }
    }

    float pos_z = player->GetPositionZ();
    float ground_Z = player->GetFloorZ();
    float groundZ = player->GetMapHeight(player->GetPositionX(), player->GetPositionY(), MAX_HEIGHT);
    float floorZ = player->GetMapHeight(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());

    // we are not really walking there
    if (groundZ == floorZ && (fabs(ground_Z - pos_z) > 2.0f || fabs(ground_Z - pos_z) < -1.0f))
    {
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
        {
            uint32 latency = 0;
            latency = player->GetSession()->GetLatency();
            std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
            TC_LOG_INFO("anticheat", "AnticheatMgr:: Teleport To Plane - Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
        }
        BuildReport(player, TELEPORT_PLANE_HACK_REPORT);
    }
}

// basic detection
void AnticheatMgr::ClimbHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_CLIMBHACK_ENABLE))
        return;

    // in this case we don't care if they are "legal" flags, they are handled in another parts of the Anticheat Manager.
    if (player->IsInWater() ||
        player->IsFlying() ||
        player->IsFalling())
        return;

    // If the player jumped, we dont want to check for climb hack
    // This can lead to false positives for climbing game objects legit
    if (opcode == MSG_MOVE_JUMP)
        return;

    if (player->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
        return;

    Position playerPos;

    float diffz = fabs(movementInfo.pos.GetPositionZ() - playerPos.GetPositionZ());
    float tanangle = movementInfo.pos.GetExactDist2d(&playerPos) / diffz;

    if (!player->HasUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING | MOVEMENTFLAG_SWIMMING))
    {
        if (movementInfo.pos.GetPositionZ() > playerPos.GetPositionZ() &&
            diffz > 1.87f && tanangle < 0.57735026919f) // 30 degrees
        {
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                uint32 latency = 0;
                latency = player->GetSession()->GetLatency();
                std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                TC_LOG_INFO("anticheat", "AnticheatMgr:: Climb-Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
            }

            BuildReport(player, CLIMB_HACK_REPORT);
        }
    }

}

void AnticheatMgr::TeleportHackDetection(Player* player, MovementInfo movementInfo)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_TELEPORTHACK_ENABLE))
        return;

    uint32 key = player->GetGUID().GetCounter();

    if (m_Players[key].GetLastMovementInfo().pos.GetPositionX() == movementInfo.pos.GetPositionX())
        return;

    float lastX = m_Players[key].GetLastMovementInfo().pos.GetPositionX();
    float newX = movementInfo.pos.GetPositionX();

    float lastY = m_Players[key].GetLastMovementInfo().pos.GetPositionY();
    float newY = movementInfo.pos.GetPositionY();

    float lastZ = m_Players[key].GetLastMovementInfo().pos.GetPositionZ();
    float newZ = movementInfo.pos.GetPositionZ();

    float xDiff = fabs(lastX - newX);
    float yDiff = fabs(lastY - newY);

    if (player->IsFalling() || (player->IsFalling() && player->IsMounted()))
        return;

    // We exempt all transports found in 335 to prevent false tele hack hits
    if (m_Players[key].GetLastMovementInfo().HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT) && player->GetMapId())
    {
        switch (player->GetMapId())
        {
            case 369: //Transport: DEEPRUN TRAM
            case 607: //Transport: Strands of the Ancients
            case 582: //Transport: Rut'theran to Auberdine
            case 584: //Transport: Menethil to Theramore
            case 586: //Transport: Exodar to Auberdine
            case 587: //Transport: Feathermoon Ferry
            case 588: //Transport: Menethil to Auberdine
            case 589: //Transport: Orgrimmar to Grom'Gol
            case 590: //Transport: Grom'Gol to Undercity
            case 591: //Transport: Undercity to Orgrimmar
            case 592: //Transport: Borean Tundra Test
            case 593: //Transport: Booty Bay to Ratchet
            case 594: //Transport: Howling Fjord Sister Mercy (Quest)
            case 596: //Transport: Naglfar
            case 610: //Transport: Tirisfal to Vengeance Landing
            case 612: //Transport: Menethil to Valgarde
            case 613: //Transport: Orgrimmar to Warsong Hold
            case 614: //Transport: Stormwind to Valiance Keep
            case 620: //Transport: Moa'ki to Unu'pe
            case 621: //Transport: Moa'ki to Kamagua
            case 622: //Transport: Orgrim's Hammer
            case 623: //Transport: The Skybreaker
            case 641: //Transport: Alliance Airship BG
            case 642: //Transport: Horde Airship BG
            case 647: //Transport: Orgrimmar to Thunder Bluff
            case 672: //Transport: The Skybreaker (Icecrown Citadel Raid)
            case 673: //Transport: Orgrim's Hammer (Icecrown Citadel Raid)
            case 712: //Transport: The Skybreaker (IC Dungeon)
            case 713: //Transport: Orgrim's Hammer (IC Dungeon)
            case 718: //Transport: The Mighty Wind (Icecrown Citadel Raid)
                return;
        }
    }

    /* Dueling exploit detection*/
    if (player->duel)
    {
        if ((xDiff >= 50.0f || yDiff >= 50.0f) && !player->CanTeleport() && !player->IsBeingTeleported())
        {
            Player* opponent = player->duel->Opponent;

            std::string str = "|cFFFFFC00[DUEL ALERT Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] Possible Teleport Hack Detected! While Dueling [|cFF60FF00" + std::string(opponent->GetName().c_str()) + "|cFF00FFFF]";
            WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
            data << str;
            sWorld->SendGlobalGMMessage(&data);
            uint32 latency = 0;
            latency = player->GetSession()->GetLatency();
            std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
            uint32 latency2 = 0;
            latency2 = opponent->GetSession()->GetLatency();
            std::string goXYZ2 = ".go xyz " + std::to_string(opponent->GetPositionX()) + " " + std::to_string(opponent->GetPositionY()) + " " + std::to_string(opponent->GetPositionZ() + 1.0f) + " " + std::to_string(opponent->GetMap()->GetId()) + " " + std::to_string(opponent->GetOrientation());
            sWorld->SendGMText(LANG_ANTICHEAT_DUEL, player->GetName().c_str(), latency, opponent->GetName().c_str(), latency2);

            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                TC_LOG_INFO("anticheat", "AnticheatMgr:: DUEL ALERT Teleport-Hack detected player %s (%s) while dueling %s - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), opponent->GetName().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
                TC_LOG_INFO("anticheat", "AnticheatMgr:: DUEL ALERT Teleport-Hack detected player %s (%s) while dueling %s - Latency: %u ms - IP: %s - Cheat Flagged at: %s", opponent->GetName().c_str(), opponent->GetGUID().ToString().c_str(), player->GetName().c_str(), latency2, opponent->GetSession()->GetRemoteAddress().c_str(), goXYZ2.c_str());
            }
            BuildReport(player, TELEPORT_HACK_REPORT);
            BuildReport(opponent, TELEPORT_HACK_REPORT);
        }
        else if (player->CanTeleport())
            player->SetCanTeleport(false);
    }
    /* Please work */
    if ((xDiff >= 50.0f || yDiff >= 50.0f) && !player->CanTeleport() && !player->IsBeingTeleported())// teleport helpers in play
    {
        if (m_Players[key].GetTotalReports() > sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORTS_INGAME_NOTIFICATION))
        {// we do this because we can not get the collumn count being propper when we add more collumns for the report, so we make a indvidual warning for Teleport Hack
            _alertFrequency = sWorld->getIntConfig(CONFIG_ANTICHEAT_ALERT_FREQUENCY);
            // So we dont divide by 0 by accident
            if (_alertFrequency < 1)
                _alertFrequency = 1;
            if (++_counter % _alertFrequency == 0)
            {
                // display warning at the center of the screen, hacky way?
                std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] Possible Teleport Hack Detected!";
                WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
                data << str;
                sWorld->SendGlobalGMMessage(&data);
                uint32 latency = 0;
                latency = player->GetSession()->GetLatency();
                // need better way to limit chat spam
                if (m_Players[key].GetTotalReports() >= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORT_IN_CHAT_MIN) && m_Players[key].GetTotalReports() <= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORT_IN_CHAT_MAX))
                {
                    sWorld->SendGMText(LANG_ANTICHEAT_TELEPORT, player->GetName().c_str(), latency);
                }
                _counter = 0;
            }
        }
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
        {
            uint32 latency = 0;
            latency = player->GetSession()->GetLatency();
            std::string goXYZ = ".go xyz " + std::to_string(newX) + " " + std::to_string(newY) + " " + std::to_string(newZ + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
            TC_LOG_INFO("anticheat", "AnticheatMgr:: Teleport-Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
        }
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_TELEPORT))
        {
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_WRITELOG))
            {
                std::string LastgoXYZ = ".go xyz " + std::to_string(lastX) + " " + std::to_string(lastY) + " " + std::to_string(lastZ + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                TC_LOG_INFO("anticheat", "ANTICHEAT COUNTER MEASURE:: %s TELEPORT HACK REVERTED PLAYER BACK TO %s", player->GetName().c_str(), LastgoXYZ.c_str());
            }
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTSCREEN))
            {   // display warning at the center of the screen, hacky way?
                std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] TELEPORT COUNTER MEASURE ALERT";
                WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
                data << str;
                sWorld->SendGlobalGMMessage(&data);
            }
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTCHAT))
            {
                std::string str = "|cFFFFFC00 TELEPORT COUNTER MEASURE ALERT";
                sWorld->SendGMText(LANG_ANTICHEAT_COUNTERMEASURE, str.c_str(), player->GetName().c_str(), player->GetName().c_str());
            }
            player->TeleportTo(player->GetMapId(), lastX, lastY, lastZ, player->GetOrientation());
            BuildReport(player, COUNTER_MEASURES_REPORT);
        }
        BuildReport(player, TELEPORT_HACK_REPORT);
    }
    else if (player->CanTeleport())// if we hit the teleport helpers in the source then we return it to false
        player->SetCanTeleport(false);
}

void AnticheatMgr::IgnoreControlHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode)
{
    uint32 key = player->GetGUID().GetCounter();

    float lastX = m_Players[key].GetLastMovementInfo().pos.GetPositionX();
    float newX = movementInfo.pos.GetPositionX();

    float lastY = m_Players[key].GetLastMovementInfo().pos.GetPositionY();
    float newY = movementInfo.pos.GetPositionY();

    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_IGNORECONTROLHACK_ENABLE))
        return;

    if (m_Players[key].GetLastOpcode() == MSG_MOVE_JUMP)
        return;

    if (opcode == (MSG_MOVE_FALL_LAND))
        return;

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_SWIMMING))
        return;

    uint32 latency = 0;
    latency = player->GetSession()->GetLatency() >= 400;
    //So here we check if hte player has a root state and not in a vehicle
    // except for lag, we can legitimately blame lag for false hits, so we see if they are above 400 then we exempt the check
    if (player->HasAuraType(SPELL_AURA_MOD_ROOT) && !player->GetVehicle() && !latency)
    {// Here we check if the x and y position changes while rooted, Nothing moves when rooted, no exception
        bool unrestricted = newX != lastX || newY != lastY;
        if (unrestricted)
        {// we do this because we can not get the collumn count being propper when we add more collumns for the report, so we make a indvidual warning for Ignore Control
            if (m_Players[key].GetTotalReports() > sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORTS_INGAME_NOTIFICATION))
            {
                _alertFrequency = sWorld->getIntConfig(CONFIG_ANTICHEAT_ALERT_FREQUENCY);
                // So we dont divide by 0 by accident
                if (_alertFrequency < 1)
                    _alertFrequency = 1;
                if (++_counter % _alertFrequency == 0)
                {
                    // display warning at the center of the screen, hacky way?
                    std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] Possible Ignore Control Hack Detected!";
                    WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
                    data << str;
                    sWorld->SendGlobalGMMessage(&data);
                    uint32 latency = 0;
                    latency = player->GetSession()->GetLatency();
                    // need better way to limit chat spam
                    if (m_Players[key].GetTotalReports() >= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORT_IN_CHAT_MIN) && m_Players[key].GetTotalReports() <= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORT_IN_CHAT_MAX))
                    {
                        sWorld->SendGMText(LANG_ANTICHEAT_IGNORECONTROL, player->GetName().c_str(), latency);
                    }
                    _counter = 0;
                }
            }
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                uint32 latency = 0;
                latency = player->GetSession()->GetLatency();
                std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                TC_LOG_INFO("anticheat", "AnticheatMgr:: Ignore Control - Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
            }
            BuildReport(player, IGNORE_CONTROL_REPORT);
        }
    }
}

void AnticheatMgr::WalkOnWaterHackDetection(Player* player, MovementInfo movementInfo)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_WATERWALKHACK_ENABLE))
        return;

    // we pull the player's individual guid
    uint32 key = player->GetGUID().GetCounter();
    uint32 distance2D = (uint32)movementInfo.pos.GetExactDist2d(&m_Players[key].GetLastMovementInfo().pos);

    // We don't need to check for a waterwalk hack if the player hasn't moved
    // This is necessary since MovementHandler fires if you rotate the camera in place
    if (!distance2D)
        return;

    // if the player is water walking on water then we are good.
    if (player->GetLiquidStatus() == LIQUID_MAP_WATER_WALK && !player->IsFlying())
    {
        if (!m_Players[key].GetLastMovementInfo().HasMovementFlag(MOVEMENTFLAG_WATERWALKING) && !movementInfo.HasMovementFlag(MOVEMENTFLAG_WATERWALKING))
        {
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                uint32 latency = 0;
                latency = player->GetSession()->GetLatency();
                std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                TC_LOG_INFO("anticheat", "AnticheatMgr:: Walk on Water - Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
            }
            BuildReport(player, WALK_WATER_HACK_REPORT);
        }
    }

    // if we are a ghost we can walk on water
    if (!player->IsAlive())
        return;

    // Prevents the False Positive for water walking when you ressurrect.
    if (m_Players[key].GetLastOpcode() == MSG_DELAY_GHOST_TELEPORT)
        return;

    // if the player previous movement and current movement is water walking then we do a follow up check
    if (m_Players[key].GetLastMovementInfo().HasMovementFlag(MOVEMENTFLAG_WATERWALKING) && movementInfo.HasMovementFlag(MOVEMENTFLAG_WATERWALKING))
    { // if player has the following auras then we return
        if (player->HasAuraType(SPELL_AURA_WATER_WALK) || player->HasAuraType(SPELL_AURA_FEATHER_FALL) ||
            player->HasAuraType(SPELL_AURA_SAFE_FALL))
        {
            return;
        }

    }
    else if (!m_Players[key].GetLastMovementInfo().HasMovementFlag(MOVEMENTFLAG_WATERWALKING) && !movementInfo.HasMovementFlag(MOVEMENTFLAG_WATERWALKING))
    {
        //Boomer Review Time:
        //Return stops code execution of the entire function
        return;
    }

    if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
    {
        uint32 latency = 0;
        latency = player->GetSession()->GetLatency();
        std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
        TC_LOG_INFO("anticheat", "AnticheatMgr:: Walk on Water - Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
    }
    BuildReport(player, WALK_WATER_HACK_REPORT);

}

void AnticheatMgr::ZAxisHackDetection(Player* player, MovementInfo movementInfo)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ZAXISHACK_ENABLE))
        return;

   uint32 key = player->GetGUID().GetCounter();

   // If he is flying we dont need to check
   if (movementInfo.HasMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING))
       return;

   // If the player is allowed to waterwalk (or he is dead because he automatically waterwalks then) we dont need to check any further
   // We also stop if the player is in water, because otherwise you get a false positive for swimming
   if (movementInfo.HasMovementFlag(MOVEMENTFLAG_WATERWALKING) || player->IsInWater() || !player->IsAlive())
       return;

   // We want to exclude this LiquidStatus from detection because it leads to false positives on boats, docks etc.
   // Basically everytime you stand on a game object in water
   if (player->GetLiquidStatus() == LIQUID_MAP_ABOVE_WATER)
       return;

   // We exempt select areas found in 335 to prevent false hack hits
   if (player->GetAreaId())
   {
       switch (player->GetAreaId())
       {
            case 4273: //Celestial Planetarium Observer Battle has a narrow path that false flags
            case 495:  //Ring of Judgement just being in the area false flags
            case 4161: //Wymrest Temple just being in the area false flags
            case 10: // Duskwood bridge
            case 40: // Westfall bridge
            case 321: // Hammerfall wooden balcony
                return;
       }
   }

   //Ring of Judgement
   if (player && GetWMOAreaTableEntryByTripple(4932, 0, 22984))
       return;

   // This is Black Magic. Check only for x and y difference but no z difference that is greater then or equal to z +2.5 of the ground
   if (m_Players[key].GetLastMovementInfo().pos.GetPositionZ() == movementInfo.pos.GetPositionZ()
       && player->GetPositionZ() >= player->GetFloorZ() + 2.5f)
   {
       if (m_Players[key].GetTotalReports() > sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORTS_INGAME_NOTIFICATION))
       {// we do this because we can not get the collumn count being propper when we add more collumns for the report, so we make a indvidual warning for Ignore Zaxis Hack
           _alertFrequency = sWorld->getIntConfig(CONFIG_ANTICHEAT_ALERT_FREQUENCY);
           // So we dont divide by 0 by accident
           if (_alertFrequency < 1)
               _alertFrequency = 1;
           if (++_counter % _alertFrequency == 0)
           {
                // display warning at the center of the screen, hacky way?
                std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] Possible Ignore Zaxis Hack Detected!";
                WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
                data << str;
                sWorld->SendGlobalGMMessage(&data);
                uint32 latency = 0;
                latency = player->GetSession()->GetLatency();
                // need better way to limit chat spam
                if (m_Players[key].GetTotalReports() >= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORT_IN_CHAT_MIN) && m_Players[key].GetTotalReports() <= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORT_IN_CHAT_MAX))
                {
                    sWorld->SendGMText(LANG_ANTICHEAT_ALERT, player->GetName().c_str(), player->GetName().c_str(), latency);
                }
                _counter = 0;
           }
       }
       if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
       {
           uint32 latency = 0;
           latency = player->GetSession()->GetLatency();
           std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
           TC_LOG_INFO("anticheat", "AnticheatMgr:: Ignore Zaxis Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
       }
       if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_IGNOREZ))
       {   // display warning at the center of the screen, hacky way?
           std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] IGNORE-Z HACK COUNTER MEASURE ALERT";
           WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
           data << str;
           sWorld->SendGlobalGMMessage(&data);

           player->GetMotionMaster()->MoveFallPlayer();

           if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_WRITELOG))
           {
               std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
               TC_LOG_INFO("anticheat.module", "ANTICHEAT COUNTER MEASURE:: %s IGNORE-Z Hack Countered and has been set to fall - Flagged at: %s", player->GetName().c_str(), goXYZ.c_str());
           }
           if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTSCREEN))
           {   // display warning at the center of the screen, hacky way?
               std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] AIGNORE-Z HACK COUNTER MEASURE ALERT";
               WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
               data << str;
               sWorld->SendGlobalGMMessage(&data);
           }
           if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTCHAT))
           {
               std::string str = "|cFFFFFC00 IGNORE-Z HACK COUNTER MEASURE ALERT";
               sWorld->SendGMText(LANG_ANTICHEAT_COUNTERMEASURE, str.c_str(), player->GetName().c_str(), player->GetName().c_str());
           }
           BuildReport(player, COUNTER_MEASURES_REPORT);
       }
       BuildReport(player, ZAXIS_HACK_REPORT);
   }

}

// basic detection
void AnticheatMgr::AntiSwimHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ANTISWIM_ENABLE))
        return;

    if (player->GetAreaId())
    {
        switch (player->GetAreaId())
        {
            case 2100: //Maraudon https://github.com/TrinityCore/TrinityCore/issues/27946
                return;
        }
    }

    if (player->GetLiquidStatus() == (LIQUID_MAP_ABOVE_WATER | LIQUID_MAP_WATER_WALK | LIQUID_MAP_IN_WATER))
        return;

    if (opcode == MSG_MOVE_JUMP)
        return;

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_SWIMMING))
        return;

    if (player->GetLiquidStatus() == LIQUID_MAP_UNDER_WATER && !movementInfo.HasMovementFlag(MOVEMENTFLAG_SWIMMING))
    {
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
        {
            uint32 latency = 0;
            latency = player->GetSession()->GetLatency();
            std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
            TC_LOG_INFO("anticheat", "AnticheatMgr:: Anti-Swim-Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
        }

        BuildReport(player, ANTISWIM_HACK_REPORT);

    }
}

void AnticheatMgr::GravityHackDetection(Player* player, MovementInfo movementInfo)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_GRAVITY_ENABLE))
        return;

    if (player->HasAuraType(SPELL_AURA_FEATHER_FALL))
    {
        return;
    }

    uint32 key = player->GetGUID().GetCounter();
    if (m_Players[key].GetLastOpcode() == MSG_MOVE_JUMP)
    {
        if (!player->HasUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY) && movementInfo.jump.zspeed < -10.0f)
        {
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                uint32 latency = 0;
                latency = player->GetSession()->GetLatency();
                std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                TC_LOG_INFO("anticheat", "AnticheatMgr:: Gravity-Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
            }
            BuildReport(player, GRAVITY_HACK_REPORT);
        }
    }
}

// basic detection
void AnticheatMgr::AntiKnockBackHackDetection(Player* player, MovementInfo movementInfo)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ANTIKNOCKBACK_ENABLE))
        return;

    uint32 key = player->GetGUID().GetCounter();

    //if a knockback helper is not passed then we ignore
    //if player has root state we ignore, knock back does not break root
    if (!player->CanKnockback() || player->HasUnitState(UNIT_STATE_ROOT))
        return;

    if (movementInfo.pos == m_Players[key].GetLastMovementInfo().pos)
    {
        if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
        {
            uint32 latency = 0;
            latency = player->GetSession()->GetLatency();
            std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
            TC_LOG_INFO("anticheat", "AnticheatMgr:: Anti-Knock Back - Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
        }
        BuildReport(player, ANTIKNOCK_BACK_HACK_REPORT);
    }
    else if (player->CanKnockback())
        player->SetCanKnockback(false);
}

// basic detection
void AnticheatMgr::NoFallDamageDetection(Player* player, MovementInfo movementInfo)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_NO_FALL_DAMAGE_ENABLE))
        return;

    // ghost can not get damaged
    if (player->HasAuraType(SPELL_AURA_GHOST))
        return;

    // players with water walk aura jumping on to the water from ledge would not get damage and neither will safe fall and feather fall
    if (((player->HasAuraType(SPELL_AURA_WATER_WALK) && player->GetLiquidStatus() == LIQUID_MAP_WATER_WALK && !player->IsFlying())) ||
        player->HasAuraType(SPELL_AURA_FEATHER_FALL) || player->HasAuraType(SPELL_AURA_SAFE_FALL))
    {
        return;
    }

    uint32 key = player->GetGUID().GetCounter();

    float lastZ = m_Players[key].GetLastMovementInfo().pos.GetPositionZ();
    float newZ = movementInfo.pos.GetPositionZ();
    float zDiff = fabs(lastZ - newZ);
    int32 safe_fall = player->GetTotalAuraModifier(SPELL_AURA_SAFE_FALL);
    float damageperc = 0.018f * (zDiff - safe_fall) - 0.2426f;
    uint32 damage = (uint32)(damageperc * player->GetMaxHealth() * sWorld->getRate(RATE_DAMAGE_FALL));

    // in the Player::Handlefall 14.57f is used to calculated the damageperc formula below to 0 for fall damamge

    if (movementInfo.pos.GetPositionZ() < m_Players[key].GetLastMovementInfo().pos.GetPositionZ() && zDiff > 14.57f)
    {
        if (movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING) || m_Players[key].GetLastMovementInfo().HasMovementFlag(MOVEMENTFLAG_FALLING))
        {
            if (damage == 0 && !player->IsImmunedToDamage(SPELL_SCHOOL_MASK_NORMAL))
            {
                if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
                {
                    uint32 latency = 0;
                    latency = player->GetSession()->GetLatency();
                    std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                    TC_LOG_INFO("anticheat", "AnticheatMgr:: No Fall Damage - Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
                }
                BuildReport(player, NO_FALL_DAMAGE_HACK_REPORT);
            }
        }
    }
}

void AnticheatMgr::BGreport(Player* player)
{
    uint32 key = player->GetGUID().GetCounter();

    _alertFrequency = sWorld->getIntConfig(CONFIG_ANTICHEAT_ALERT_FREQUENCY);
    // So we dont divide by 0 by accident
    if (_alertFrequency < 1)
        _alertFrequency = 1;
    if (++_counter % _alertFrequency == 0)
    {
        // display warning at the center of the screen, hacky way?
        std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] Player Outside of Starting SPOT before BG has started!";
        WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
        data << str;
        sWorld->SendGlobalGMMessage(&data);
        uint32 latency = 0;
        latency = player->GetSession()->GetLatency();
        // need better way to limit chat spam
        if (m_Players[key].GetTotalReports() >= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORT_IN_CHAT_MIN) && m_Players[key].GetTotalReports() <= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORT_IN_CHAT_MAX))
        {
            sWorld->SendGMText(LANG_ANTICHEAT_BG_EXPLOIT, player->GetName().c_str(), player->GetName().c_str(), latency);
        }
        _counter = 0;
    }

    if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
    {
        uint32 latency = 0;
        latency = player->GetSession()->GetLatency();
        std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
        TC_LOG_INFO("anticheat", "AnticheatMgr:: BG Start Spot Exploit-Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
    }

    BuildReport(player, TELEPORT_HACK_REPORT);
}

Position const* AnticheatMgr::GetTeamStartPosition(TeamId teamId) const
{
    return &_startPosition[teamId];
}

void AnticheatMgr::CheckBGOriginPositions(Player* player)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_BG_START_COUNTERHACK_ENABLE))
        return;

    Position const* startPos = GetTeamStartPosition(Battleground::GetTeamIndexByTeamId(player->GetBGTeam()));

    if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_WRITELOG))
    {
        std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
        TC_LOG_INFO("anticheat", "ANTICHEAT COUNTER MEASURE:: Sending %s back to start location (BG Map: %u) (possible exploit) - Flagged at: %s", player->GetName().c_str(), player->GetMapId(), goXYZ.c_str());
    }
    if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTSCREEN))
    {   // display warning at the center of the screen, hacky way?
        std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] BG START SPOT COUNTER MEASURE ALERT";
        WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
        data << str;
        sWorld->SendGlobalGMMessage(&data);
    }
    if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_CM_ALERTCHAT))
    {
        std::string str = "|cFFFFFC00 BG START SPOT COUNTER MEASURE ALERT";
        sWorld->SendGMText(LANG_ANTICHEAT_COUNTERMEASURE, str.c_str(), player->GetName().c_str(), player->GetName().c_str());
    }
    player->TeleportTo(player->GetMapId(), startPos->GetPositionX(), startPos->GetPositionY(), startPos->GetPositionZ(), startPos->GetOrientation());
}

void AnticheatMgr::BGStartExploit(Player* player, MovementInfo movementInfo)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_BG_START_HACK_ENABLE))
        return;

    uint32 key = player->GetGUID().GetCounter();

    switch (player->GetMapId())
    {
        case 30: // Alterac Valley
        {
            if (Battleground* bg = player->GetBattleground())
            {
                if (bg->GetStatus() == STATUS_WAIT_JOIN)
                {
                    // Outside of starting area before BG has started.
                    if ((player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionX() < 770.0f) ||
                        (player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionX() > 940.31f) ||
                        (player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionY() < -525.0f))
                    {
                        sAnticheatMgr->BGreport(player);
                        sAnticheatMgr->CheckBGOriginPositions(player);
                    }
                    if ((player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionY() > -535.0f) ||
                        (player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionX() > -1283.33f) ||
                        (player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionY() < -716.0f))
                    {
                        sAnticheatMgr->BGreport(player);
                        sAnticheatMgr->CheckBGOriginPositions(player);
                    }
                }
            }
            break;
        }
        case 489: // Warsong Gulch
        {
            // Only way to get this high is with engineering items malfunction.
            if (!(movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING_FAR) || m_Players[key].GetLastOpcode() == MSG_MOVE_JUMP) && movementInfo.pos.GetPositionZ() > 380.0f)
            {
                sAnticheatMgr->BGreport(player);
                sAnticheatMgr->CheckBGOriginPositions(player);
            }

            if (Battleground* bg = player->GetBattleground())
            {
                if (bg->GetStatus() == STATUS_WAIT_JOIN)
                {
                    // Outside of starting area before BG has started.
                    if ((player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionX() < 1490.0f) ||
                        (player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionY() > 1500.0f) ||
                        (player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionY() < 1450.0f))
                    {
                        sAnticheatMgr->BGreport(player);
                        sAnticheatMgr->CheckBGOriginPositions(player);
                    }
                    if ((player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionX() > 957.0f) ||
                        (player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionY() < 1416.0f) ||
                        (player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionY() > 1466.0f))
                    {
                        sAnticheatMgr->BGreport(player);
                        sAnticheatMgr->CheckBGOriginPositions(player);
                    }
                }
            }
            break;
        }
        case 529: // Arathi Basin
        {
            if (Battleground* bg = player->GetBattleground())
            {
                if (bg->GetStatus() == STATUS_WAIT_JOIN)
                {
                    // Outside of starting area before BG has started.
                    if ((player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionX() < 1270.0f) ||
                        (player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionY() < 1258.0f) ||
                        (player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionY() > 1361.0f))
                    {
                        sAnticheatMgr->BGreport(player);
                        sAnticheatMgr->CheckBGOriginPositions(player);
                    }
                    if ((player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionX() > 730.0f) ||
                        (player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionY() > 724.8f))
                    {
                        sAnticheatMgr->BGreport(player);
                        sAnticheatMgr->CheckBGOriginPositions(player);
                    }
                }
            }
            break;
        }
        case 566: // Eye of the Storm
        {
            if (Battleground* bg = player->GetBattleground())
            {
                if (bg->GetStatus() == STATUS_WAIT_JOIN)
                {
                    // Outside of starting area before BG has started.
                    if ((player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionX() < 2512.0f) ||
                        (player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionY() > 1610.0f) ||
                        (player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionY() < 1584.0f))
                    {
                        sAnticheatMgr->BGreport(player);
                        sAnticheatMgr->CheckBGOriginPositions(player);
                    }
                    if ((player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionX() > 1816.0f) ||
                        (player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionY() > 1554.0f) ||
                        (player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionY() < 1526.0f))
                    {
                        sAnticheatMgr->BGreport(player);
                        sAnticheatMgr->CheckBGOriginPositions(player);
                    }
                }
            }
            break;
        }
        case 628: // Island Of Conquest
        {
            if (Battleground* bg = player->GetBattleground())
            {
                if (bg->GetStatus() == STATUS_WAIT_JOIN)
                {
                    // Outside of starting area before BG has started.
                    if ((player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionX() > 412.0f) ||
                        (player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionY() < -911.0f) ||
                        (player->GetTeamId() == TEAM_ALLIANCE && movementInfo.pos.GetPositionY() > -760.0f))
                    {
                        sAnticheatMgr->BGreport(player);
                        sAnticheatMgr->CheckBGOriginPositions(player);
                    }
                    if ((player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionX() < 1147.8f) ||
                        (player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionY() < -855.0f) ||
                        (player->GetTeamId() == TEAM_HORDE && movementInfo.pos.GetPositionY() > -676.0f))
                    {
                        sAnticheatMgr->BGreport(player);
                        sAnticheatMgr->CheckBGOriginPositions(player);
                    }
                }
            }
            break;
        }
        return;
    }
}

void AnticheatMgr::StartScripts()
{
    new AnticheatScripts();
}

void AnticheatMgr::HandlePlayerLogin(Player* player)
{
    // we must delete this to prevent errors in case of crash
    CharacterDatabase.PExecute("DELETE FROM players_reports_status WHERE guid=%u", player->GetGUID().GetCounter());
    // we initialize the pos of lastMovementPosition var.
    m_Players[player->GetGUID().GetCounter()].SetPosition(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation());
    QueryResult resultDB = CharacterDatabase.PQuery("SELECT * FROM daily_players_reports WHERE guid=%u;", player->GetGUID().GetCounter());

    if (resultDB)
        m_Players[player->GetGUID().GetCounter()].SetDailyReportState(true);
}

void AnticheatMgr::HandlePlayerLogout(Player* player)
{
    // TO-DO Make a table that stores the cheaters of the day, with more detailed information.

    // We must also delete it at logout to prevent have data of offline players in the db when we query the database (IE: The GM Command)
    CharacterDatabase.PExecute("DELETE FROM players_reports_status WHERE guid=%u", player->GetGUID().GetCounter());
    // Delete not needed data from the memory.
    m_Players.erase(player->GetGUID().GetCounter());
}

void AnticheatMgr::AckUpdate(Player* player, uint32 diff)
{
    if (_updateCheckTimer <= diff)
    {
        DoActions(player);
        _updateCheckTimer = 4000;
    }
    else
    {
        _updateCheckTimer -= diff;
    }
}

void AnticheatMgr::DoActions(Player* player)
{
    auto const now = getMSTime();

    for (auto& order : _opackorders)
    {
        if (order.counter > 0 && order.lastRcvd < order.lastSent && (now - order.lastSent) > ALLOWED_ACK_LAG)
        {
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                uint32 latency = 0;
                latency = player->GetSession()->GetLatency();
                std::string goXYZ = ".go xyz " + std::to_string(player->GetPositionX()) + " " + std::to_string(player->GetPositionY()) + " " + std::to_string(player->GetPositionZ() + 1.0f) + " " + std::to_string(player->GetMap()->GetId()) + " " + std::to_string(player->GetOrientation());
                TC_LOG_INFO("anticheat", "AnticheatMgr:: OP Ack Manipulation - Hack detected player %s (%s) - Latency: %u ms - IP: %s - Cheat Flagged at: %s", player->GetName().c_str(), player->GetGUID().ToString().c_str(), latency, player->GetSession()->GetRemoteAddress().c_str(), goXYZ.c_str());
                order.counter = 0;
            }
            BuildReport(player, OP_ACK_HACK_REPORT);
        }
    }
}

void AnticheatMgr::OrderSent(WorldPacket const* data)
{
    for (auto& order : _opackorders)
    {
        if (order.serverOpcode1 == data->GetOpcode() || order.serverOpcode2 == data->GetOpcode())
        {
            order.lastSent = getMSTime();
            ++order.counter;
            break;
        }
    }
}

void AnticheatMgr::CheckForOrderAck(uint32 opcode)
{
    for (auto& order : _opackorders)
    {
        if (order.clientResp == opcode)
        {
            --order.counter;
            break;
        }
    }
}

void AnticheatMgr::SetAllowedMovement(Player* player, bool)
{
    player->SetCanTeleport(true);
}

void AnticheatMgr::SavePlayerData(Player* player)
{
    AnticheatData playerData = m_Players[player->GetGUID().GetCounter()];
    CharacterDatabase.PExecute("REPLACE INTO players_reports_status (guid,average,total_reports,speed_reports,fly_reports,jump_reports,waterwalk_reports,teleportplane_reports,climb_reports,teleport_reports,ignorecontrol_reports,zaxis_reports,antiswim_reports,gravity_reports,antiknockback_reports,no_fall_damage_reports,op_ack_hack_reports,counter_measures_reports,creation_time) VALUES (%u,%f,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u);", player->GetGUID().GetCounter(), playerData.GetAverage(), playerData.GetTotalReports(), playerData.GetTypeReports(SPEED_HACK_REPORT), playerData.GetTypeReports(FLY_HACK_REPORT), playerData.GetTypeReports(JUMP_HACK_REPORT), playerData.GetTypeReports(WALK_WATER_HACK_REPORT), playerData.GetTypeReports(TELEPORT_PLANE_HACK_REPORT), playerData.GetTypeReports(CLIMB_HACK_REPORT), playerData.GetTypeReports(TELEPORT_HACK_REPORT), playerData.GetTypeReports(IGNORE_CONTROL_REPORT), playerData.GetTypeReports(ZAXIS_HACK_REPORT), playerData.GetTypeReports(ANTISWIM_HACK_REPORT), playerData.GetTypeReports(GRAVITY_HACK_REPORT), playerData.GetTypeReports(ANTIKNOCK_BACK_HACK_REPORT), playerData.GetTypeReports(NO_FALL_DAMAGE_HACK_REPORT), playerData.GetTypeReports(OP_ACK_HACK_REPORT), playerData.GetTypeReports(COUNTER_MEASURES_REPORT), m_Players[player->GetGUID()].GetCreationTime());
}

void AnticheatMgr::SavePlayerDataDaily(Player* player)
{
    AnticheatData playerData = m_Players[player->GetGUID().GetCounter()];
    CharacterDatabase.PExecute("REPLACE INTO daily_players_reports (guid,average,total_reports,speed_reports,fly_reports,jump_reports,waterwalk_reports,teleportplane_reports,climb_reports,teleport_reports,ignorecontrol_reports,zaxis_reports,antiswim_reports,gravity_reports,antiknockback_reports,no_fall_damage_reports,op_ack_hack_reports,counter_measures_reports,creation_time) VALUES (%u,%f,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u);", player->GetGUID().GetCounter(), playerData.GetAverage(), playerData.GetTotalReports(), playerData.GetTypeReports(SPEED_HACK_REPORT), playerData.GetTypeReports(FLY_HACK_REPORT), playerData.GetTypeReports(JUMP_HACK_REPORT), playerData.GetTypeReports(WALK_WATER_HACK_REPORT), playerData.GetTypeReports(TELEPORT_PLANE_HACK_REPORT), playerData.GetTypeReports(CLIMB_HACK_REPORT), playerData.GetTypeReports(TELEPORT_HACK_REPORT), playerData.GetTypeReports(IGNORE_CONTROL_REPORT), playerData.GetTypeReports(ZAXIS_HACK_REPORT), playerData.GetTypeReports(ANTISWIM_HACK_REPORT), playerData.GetTypeReports(GRAVITY_HACK_REPORT), playerData.GetTypeReports(ANTIKNOCK_BACK_HACK_REPORT), playerData.GetTypeReports(NO_FALL_DAMAGE_HACK_REPORT), playerData.GetTypeReports(OP_ACK_HACK_REPORT), playerData.GetTypeReports(COUNTER_MEASURES_REPORT), m_Players[player->GetGUID()].GetCreationTime());
}

void AnticheatMgr::OnPlayerMove(Player* player, MovementInfo mi, uint32 opcode)
{
    if (!AccountMgr::IsAdminAccount(player->GetSession()->GetSecurity()) || sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE_ON_GM))
        sAnticheatMgr->StartHackDetection(player, mi, opcode);
}

uint32 AnticheatMgr::GetTotalReports(uint32 lowGUID)
{
    return m_Players[lowGUID].GetTotalReports();
}

float AnticheatMgr::GetAverage(uint32 lowGUID)
{
    return m_Players[lowGUID].GetAverage();
}

uint32 AnticheatMgr::GetTypeReports(uint32 lowGUID, uint8 type)
{
    return m_Players[lowGUID].GetTypeReports(type);
}

bool AnticheatMgr::MustCheckTempReports(uint8 type)
{
    if (type == JUMP_HACK_REPORT)
        return false;

    if (type == TELEPORT_HACK_REPORT)
        return false;

    if (type == IGNORE_CONTROL_REPORT)
        return false;

    if (type == GRAVITY_HACK_REPORT)
        return false;

    if (type == ANTIKNOCK_BACK_HACK_REPORT)
        return false;

    if (type == NO_FALL_DAMAGE_HACK_REPORT)
        return false;

    if (type == OP_ACK_HACK_REPORT)
        return false;

    return true;
}

//
// Dear maintainer:
//
// Once you are done trying to 'optimize' this script,
// and have identify potentionally if there was a terrible
// mistake that was here or not, please increment the
// following counter as a warning to the next guy:
//
// total_hours_wasted_here = 42
//

void AnticheatMgr::BuildReport(Player* player, uint8 reportType)
{
    uint32 key = player->GetGUID().GetCounter();

    if (MustCheckTempReports(reportType))
    {
        uint32 actualTime = getMSTime();

        if (!m_Players[key].GetTempReportsTimer(reportType))
            m_Players[key].SetTempReportsTimer(actualTime, reportType);

        if (getMSTimeDiff(m_Players[key].GetTempReportsTimer(reportType), actualTime) < 3000)
        {
            m_Players[key].SetTempReports(m_Players[key].GetTempReports(reportType) + 1, reportType);

            if (m_Players[key].GetTempReports(reportType) < 3)
                return;
        }
        else
        {
            m_Players[key].SetTempReportsTimer(actualTime, reportType);
            m_Players[key].SetTempReports(1, reportType);
            return;
        }
    }

    // generating creationTime for average calculation
    if (!m_Players[key].GetTotalReports())
        m_Players[key].SetCreationTime(getMSTime());

    // increasing total_reports
    m_Players[key].SetTotalReports(m_Players[key].GetTotalReports() + 1);
    // increasing specific cheat report
    m_Players[key].SetTypeReports(reportType, m_Players[key].GetTypeReports(reportType) + 1);

    // diff time for average calculation
    uint32 diffTime = getMSTimeDiff(m_Players[key].GetCreationTime(), getMSTime()) / IN_MILLISECONDS;

    if (diffTime > 0)
    {
        // Average == Reports per second
        float average = float(m_Players[key].GetTotalReports()) / float(diffTime);
        m_Players[key].SetAverage(average);
    }

    if (sWorld->getIntConfig(CONFIG_ANTICHEAT_MAX_REPORTS_FOR_DAILY_REPORT) < m_Players[key].GetTotalReports())
    {
        if (!m_Players[key].GetDailyReportState())
        {
            AnticheatData playerData = m_Players[player->GetGUID().GetCounter()];
            CharacterDatabase.PExecute("REPLACE INTO players_reports_status (guid,average,total_reports,speed_reports,fly_reports,jump_reports,waterwalk_reports,teleportplane_reports,climb_reports,teleport_reports,ignorecontrol_reports,zaxis_reports,antiswim_reports,gravity_reports,antiknockback_reports,no_fall_damage_reports,op_ack_hack_reports,counter_measures_reports,creation_time) VALUES (%u,%f,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u);", player->GetGUID().GetCounter(), playerData.GetAverage(), playerData.GetTotalReports(), playerData.GetTypeReports(SPEED_HACK_REPORT), playerData.GetTypeReports(FLY_HACK_REPORT), playerData.GetTypeReports(JUMP_HACK_REPORT), playerData.GetTypeReports(WALK_WATER_HACK_REPORT), playerData.GetTypeReports(TELEPORT_PLANE_HACK_REPORT), playerData.GetTypeReports(CLIMB_HACK_REPORT), playerData.GetTypeReports(TELEPORT_HACK_REPORT), playerData.GetTypeReports(IGNORE_CONTROL_REPORT), playerData.GetTypeReports(ZAXIS_HACK_REPORT), playerData.GetTypeReports(ANTISWIM_HACK_REPORT), playerData.GetTypeReports(GRAVITY_HACK_REPORT), playerData.GetTypeReports(ANTIKNOCK_BACK_HACK_REPORT), playerData.GetTypeReports(NO_FALL_DAMAGE_HACK_REPORT), playerData.GetTypeReports(OP_ACK_HACK_REPORT), playerData.GetTypeReports(COUNTER_MEASURES_REPORT), m_Players[player->GetGUID()].GetCreationTime());
            m_Players[key].SetDailyReportState(true);
        }
    }

    if (m_Players[key].GetTotalReports() > sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORTS_INGAME_NOTIFICATION))
    {
        _alertFrequency = sWorld->getIntConfig(CONFIG_ANTICHEAT_ALERT_FREQUENCY);
        // So we dont divide by 0 by accident
        if (_alertFrequency < 1)
            _alertFrequency = 1;
        if (++_counter % _alertFrequency == 0)
        {
            // display warning at the center of the screen, hacky way?
            std::string str = "|cFFFFFC00[Playername:]|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] Possible cheater!";
            WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
            data << str;
            sWorld->SendGlobalGMMessage(&data);
        }
        // need better way to limit chat spam
        if (m_Players[key].GetTotalReports() >= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORT_IN_CHAT_MIN) && (m_Players[key].GetTotalReports() <= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORT_IN_CHAT_MAX)))
        {
            uint32 latency = 0;
            latency = player->GetSession()->GetLatency();
            sWorld->SendGMText(LANG_ANTICHEAT_ALERT, player->GetName().c_str(), player->GetName().c_str(), latency);
        }
        _counter = 0;
    }
    // Automatic Moderation, not recommended but not hated
    // Auto Kick
    if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_AUTOKICK_ENABLE))
    {
        if (m_Players[key].GetTotalReports() > sWorld->getIntConfig(CONFIG_ANTICHEAT_MAX_REPORTS_FOR_KICKS))
        {
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                TC_LOG_INFO("anticheat", "AnticheatMgr:: Reports reached assigned threshhold and counteracted by kicking player %s (%s)", player->GetName().c_str(), player->GetGUID().ToString().c_str());
            }
            // display warning at the center of the screen, hacky way?
            std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] Auto Kicked for Reaching Cheat Threshhold!";
            WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
            data << str;
            sWorld->SendGlobalGMMessage(&data);
            // kick offender when reports are reached for automatic moderation
            player->GetSession()->KickPlayer("Anticheat Module");
            // publically shame them with a server message
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_ANNOUNCEKICK_ENABLE))
            {
                std::string plr = player->GetName();
                std::string tag_colour = "7bbef7";
                std::string plr_colour = "ff0000";
                std::ostringstream stream;
                stream << "|CFF" << plr_colour << "[AntiCheat]|r|CFF" << tag_colour <<
                    " Player |r|cff" << plr_colour << plr << "|r|cff" << tag_colour <<
                    " has been kicked by the Anticheat Module.|r";
                sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
            }
        }
    }
    // Auto Ban
    if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_AUTOBAN_ENABLE))
    {
        if (m_Players[key].GetTotalReports() > sWorld->getIntConfig(CONFIG_ANTICHEAT_MAX_REPORTS_FOR_BANS))
        {
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                TC_LOG_INFO("anticheat", "AnticheatMgr:: Reports reached assigned threshhold and counteracted by banning player %s (%s)", player->GetName().c_str(), player->GetGUID().ToString().c_str());
            }
            // display warning at the center of the screen, hacky way?
            std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] Auto Banned Account for Reaching Cheat Threshhold!";
            WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
            data << str;
            sWorld->SendGlobalGMMessage(&data);
            //Auto Ban the Offender Indefinately their whole account.
            std::string accountName;
            AccountMgr::GetName(player->GetSession()->GetAccountId(), accountName);
            sWorld->BanAccount(BAN_ACCOUNT, accountName, "0s", "Anticheat module Auto Banned Account for Reach Cheat Threshhold", "Server");
            // publically shame them with a server message
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_ANNOUNCEBAN_ENABLE))
            {
                std::string plr = player->GetName();
                std::string tag_colour = "7bbef7";
                std::string plr_colour = "ff0000";
                std::ostringstream stream;
                stream << "|CFF" << plr_colour << "[AntiCheat]|r|CFF" << tag_colour <<
                    " Player |r|cff" << plr_colour << plr << "|r|cff" << tag_colour <<
                    " has been Banned by the Anticheat Module.|r";
                sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
            }
        }
    }
    //Auto Jail
    if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_AUTOJAIL_ENABLE))
    {
        if (m_Players[key].GetTotalReports() > sWorld->getIntConfig(CONFIG_ANTICHEAT_MAX_REPORTS_FOR_JAILS))
        {
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_WRITELOG_ENABLE))
            {
                TC_LOG_INFO("anticheat", "AnticheatMgr:: Reports reached assigned threshhold and counteracted by jailing player %s (%s)", player->GetName().c_str(), player->GetGUID().ToString().c_str());
            }
            // display warning at the center of the screen, hacky way?
            std::string str = "|cFFFFFC00[Playername:|cFF00FFFF[|cFF60FF00" + player->GetName() + "|cFF00FFFF] Auto Jailed Account for Reaching Cheat Threshhold!";
            WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
            data << str;
            sWorld->SendGlobalGMMessage(&data);
            // This is where they end up going shaw shank redemption style
            // GM Jail Location is uncommit and used as default for the jailing. Feel free to commit it out with double forward slashes (//) and uncommit,
            // removing the double forward slashes (//) if you wish to use the other locations.
            WorldLocation loc = WorldLocation(1, 16226.5f, 16403.6f, -64.5f, 3.2f);// GM Jail Location
            //WorldLocation loc = WorldLocation(35, -98.0155, 149.8360,-40.3827, 3.2f);// Alliance Jail Stormwind Stockade Location
            //WorldLocation loc = WorldLocation(0, -11139.1845, -1742.4421, -29.7365, 3.2f);// Horde Jail The Pit of Criminals Location

            player->TeleportTo(loc);// we defined loc as the jail location so we tele them there
            player->SetHomebind(loc, 876);// GM Jail Homebind location
            player->CastSpell(player, SHACKLES);// shackle him in place to ensure no exploit happens for jail break attempt

            if (Aura* dungdesert = player->AddAura(LFG_SPELL_DUNGEON_DESERTER, player))// LFG_SPELL_DUNGEON_DESERTER
            {
                dungdesert->SetDuration(-1);
            }
            if (Aura* bgdesert = player->AddAura(BG_SPELL_DESERTER, player))// BG_SPELL_DESERTER
            {
                bgdesert->SetDuration(-1);
            }
            if (Aura* silent = player->AddAura(SILENCED, player))// SILENCED
            {
                silent->SetDuration(-1);
            }

            // publically shame them with a server message
            if (sWorld->getBoolConfig(CONFIG_ANTICHEAT_ANNOUNCEJAIL_ENABLE))
            {
                std::string plr = player->GetName();
                std::string tag_colour = "7bbef7";
                std::string plr_colour = "ff0000";
                std::ostringstream stream;
                stream << "|CFF" << plr_colour << "[AntiCheat]|r|CFF" << tag_colour <<
                    " Player |r|cff" << plr_colour << plr << "|r|cff" << tag_colour <<
                    " has been Jailed by the Anticheat Module.|r";
                sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
            }
        }
    }
}
// these are the supporters for the gm commands in cs_anticheat.cpp
void AnticheatMgr::AnticheatGlobalCommand(ChatHandler* handler)
{   // .anticheat global gm command
    // save All Anticheat Player Data before displaying global stats
    for (SessionMap::const_iterator itr = sWorld->GetAllSessions().begin(); itr != sWorld->GetAllSessions().end(); ++itr)
        if (Player* plr = itr->second->GetPlayer())
        {
            sAnticheatMgr->SavePlayerData(plr);
            sAnticheatMgr->SavePlayerDataDaily(plr);
        }

    QueryResult resultDB = CharacterDatabase.Query("SELECT guid,average,total_reports FROM players_reports_status WHERE total_reports != 0 ORDER BY average ASC LIMIT 3;");
    if (!resultDB)
    {
        handler->PSendSysMessage("No players found.");
        return;
    }
    else
    {
        handler->SendSysMessage("=============================");
        handler->PSendSysMessage("Players with the lowest averages:");
        do
        {
            Field* fieldsDB = resultDB->Fetch();

            uint32 guid = fieldsDB[0].GetUInt32();
            float average = fieldsDB[1].GetFloat();
            uint32 total_reports = fieldsDB[2].GetUInt32();

            if (Player* player = ObjectAccessor::FindPlayerByLowGUID(guid))
                handler->PSendSysMessage("Player: %s Average: %f Total Reports: %u", player->GetName().c_str(), average, total_reports);

        } while (resultDB->NextRow());
    }

    resultDB = CharacterDatabase.Query("SELECT guid,average,total_reports FROM players_reports_status WHERE total_reports != 0 ORDER BY total_reports DESC LIMIT 3;");

    if (!resultDB)
    {
        handler->PSendSysMessage("No players found.");
        return;
    }
    else
    {
        handler->SendSysMessage("=============================");
        handler->PSendSysMessage("Players with the more reports:");
        do
        {
            Field* fieldsDB = resultDB->Fetch();

            uint32 guid = fieldsDB[0].GetUInt32();
            float average = fieldsDB[1].GetFloat();
            uint32 total_reports = fieldsDB[2].GetUInt32();

            if (Player* player = ObjectAccessor::FindPlayerByLowGUID(guid))
                handler->PSendSysMessage("Player: %s Total Reports: %u Average: %f", player->GetName().c_str(), total_reports, average);

        } while (resultDB->NextRow());
    }
}

// .anticheat delete gm cmd
void AnticheatMgr::AnticheatDeleteCommand(uint32 guid)
{
    if (!guid)
    {
        for (AnticheatPlayersDataMap::iterator it = m_Players.begin(); it != m_Players.end(); ++it)
        {
            (*it).second.SetTotalReports(0);
            (*it).second.SetAverage(0);
            (*it).second.SetCreationTime(0);
            for (uint8 i = 0; i < MAX_REPORT_TYPES; i++)
            {
                (*it).second.SetTempReports(0, i);
                (*it).second.SetTempReportsTimer(0, i);
                (*it).second.SetTypeReports(i, 0);
            }
        }
        CharacterDatabase.PExecute("DELETE FROM players_reports_status;");
    }
    else
    {
        m_Players[guid].SetTotalReports(0);
        m_Players[guid].SetAverage(0);
        m_Players[guid].SetCreationTime(0);
        for (uint8 i = 0; i < MAX_REPORT_TYPES; i++)
        {
            m_Players[guid].SetTempReports(0, i);
            m_Players[guid].SetTempReportsTimer(0, i);
            m_Players[guid].SetTypeReports(i, 0);
        }
        CharacterDatabase.PExecute("DELETE FROM players_reports_status WHERE guid=%u;", guid);
    }
}

// .anticheat purge gm cmd
void AnticheatMgr::AnticheatPurgeCommand(ChatHandler* /*handler*/)
{// we purge the whole daily_players_reports table in the character database
    CharacterDatabase.Execute("TRUNCATE TABLE daily_players_reports;");
}

void AnticheatMgr::ResetDailyReportStates()
{// this resets the daily reports to zero
    for (AnticheatPlayersDataMap::iterator it = m_Players.begin(); it != m_Players.end(); ++it)
        m_Players[(*it).first].SetDailyReportState(false);
}
