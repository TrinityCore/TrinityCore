#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "Config/Config.h"
#include "Opcodes.h"
#include "MovementAnticheat.h"
#include "Chat.h"
#include "Player.h"
#include "GameObject.h"
#include "WorldSession.h"
#include "MoveSpline.h"
#include "World.h"
#include "MovementPacketSender.h"
#include "Geometry.h"

using namespace Geometry;

const char* GetMovementCheatName(CheatType flagId)
{
    switch (flagId)
    {
        case CHEAT_TYPE_TIME_BACK:
            return "ReverseTime";
        case CHEAT_TYPE_NULL_CLIENT_TIME:
            return "NullClientTime";
        case CHEAT_TYPE_SKIPPED_HEARTBEATS:
            return "SkippedHeartbeats";
        case CHEAT_TYPE_TIME_DESYNC:
            return "TimeDesync";
        case CHEAT_TYPE_NUM_DESYNC:
            return "NumDesyncs";
        case CHEAT_TYPE_OVERSPEED_DIST:
            return "OverspeedDist";
        case CHEAT_TYPE_OVERSPEED_JUMP:
            return "OverspeedJump";
        case CHEAT_TYPE_JUMP_SPEED_CHANGE:
            return "JumpSpeedChange";
        case CHEAT_TYPE_MULTI_JUMP:
            return "MultiJump";
        case CHEAT_TYPE_WALL_CLIMB:
            return "WallClimb";
        case CHEAT_TYPE_PVE_FLYHACK:
            return "PvEUnreachable";
        case CHEAT_TYPE_FLY_HACK_SWIM:
            return "FlyHackSwim";
        case CHEAT_TYPE_NO_FALL_TIME:
            return "NoFallTime";
        case CHEAT_TYPE_TELEPORT:
            return "TeleportHack";
        case CHEAT_TYPE_TELEPORT_TRANSPORT:
            return "TeleToTransport";
        case CHEAT_TYPE_FAKE_TRANSPORT:
            return "FakeTransport";
        case CHEAT_TYPE_WATER_WALK:
            return "WaterWalk";
        case CHEAT_TYPE_SLOW_FALL:
            return "SlowFall";
        case CHEAT_TYPE_HOVER:
            return "Hover";
        case CHEAT_TYPE_FIXED_Z:
            return "FixedZ";
        case CHEAT_TYPE_ROOT_MOVE:
            return "MovementRooted";
        case CHEAT_TYPE_SELF_ROOT:
            return "SelfRoot";
        case CHEAT_TYPE_WRONG_ACK_DATA:
            return "WrongAckData";
        case CHEAT_TYPE_PENDING_ACK_DELAY:
            return "PendingAckDelay";
        case CHEAT_TYPE_EXPLORE:
            return "Exploration";
        case CHEAT_TYPE_EXPLORE_HIGH_LEVEL:
            return "ExploreHighLevelArea";
        case CHEAT_TYPE_FORBIDDEN_AREA:
            return "ForbiddenArea";
    }

    return "UnknownCheat";
}

MovementAnticheat::MovementAnticheat(Player* _me) : me(_me), m_session(_me->GetSession())
{
}

MovementInfo& MovementAnticheat::GetLastMovementInfo()
{
    return me->m_movementInfo;
}

MovementInfo const& MovementAnticheat::GetLastMovementInfo() const
{
    return me->m_movementInfo;
}

uint32 MovementAnticheat::Update(uint32 diff, std::stringstream& reason)
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_ENABLED))
        return CHEAT_ACTION_NONE;

    // Every X seconds, combine detected cheats
    if (m_updateCheckTimer >= diff)
    {
        m_updateCheckTimer -= diff;
        return CHEAT_ACTION_NONE;
    }

    return Finalize(reason);
}

uint32 MovementAnticheat::Finalize(std::stringstream& reason)
{
    if (m_maxOverspeedDistance < fabs(m_overspeedDistance))
        m_maxOverspeedDistance = fabs(m_overspeedDistance);
    if (m_maxClientDesync < static_cast<uint32>(abs(m_clientDesync)))
        m_maxClientDesync = abs(m_clientDesync);

    m_cheatOccuranceTick[CHEAT_TYPE_OVERSPEED_DIST] = uint32(fabs(m_overspeedDistance));
    m_cheatOccuranceTick[CHEAT_TYPE_TIME_DESYNC] = abs(m_clientDesync);

    DEBUG_UNIT(me, DEBUG_CHEAT, "Desync %ims / %fyards", m_clientDesync, m_overspeedDistance);
    m_updateCheckTimer = CHEATS_UPDATE_INTERVAL;

    // Add up penalties for all cheats detected
    uint32 result = ComputeCheatAction(reason);

    // Log data
    if (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_LOG_DATA) && me->IsInWorld())
    {
        LogsDatabase.PExecute("INSERT INTO logs_movement "
            "(account, guid, posx, posy, posz, map, desyncMs, desyncDist, cheats) VALUES "
            "(%u,      %u,   %f,   %f,   %f,   %u,  %i,       %f,         '%s');",
            m_session->GetAccountId(), me->GetGUIDLow(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(),
            me->GetMapId(), m_clientDesync, m_overspeedDistance, reason.rdbuf()->in_avail() ? reason.str().c_str() : "");
    }

    // Reset to zero tick counts
    m_cheatOccuranceTick.fill(0);

    m_clientDesync = 0;
    m_overspeedDistance = 0.0f;
    return result;
}

void MovementAnticheat::AddCheats(uint32 cheats, uint32 count)
{
    if (!cheats)
        return;

    if (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_NOTIFY_CHEATERS))
    {
        for (uint32 i = 0; i < CHEATS_COUNT; ++i)
        {
            if ((cheats & (1 << i)) && m_session->GetPlayer())
                ChatHandler(m_session->GetPlayer()).PSendSysMessage("[AntiCheat] Cheat : %s", GetMovementCheatName(CheatType(i)));
        }
    }

    for (uint32 i = 0; i < CHEATS_COUNT; ++i)
        if (cheats & (1 << i))
            StoreCheat(i, count);
}

void MovementAnticheat::StoreCheat(uint32 type, uint32 count)
{
    m_cheatOccuranceTotal[type] += count;
    m_cheatOccuranceTick[type] += count;
}

uint32 MovementAnticheat::ComputeCheatAction(std::stringstream& reason)
{
    uint32 action = CHEAT_ACTION_NONE;

    auto AddPenaltyForCheat = [&action, &reason, this](bool total, CheatType cheatType, eConfigBoolValues enabledConfig, eConfigUInt32Values thresholdConfig, eConfigUInt32Values penaltyConfig)
    { 
        if (sWorld.getConfig(enabledConfig))
        {
            ASSERT(cheatType < CHEATS_COUNT);
            uint32 count = total ? m_cheatOccuranceTotal[cheatType] : m_cheatOccuranceTick[cheatType];
            uint32 threshold = sWorld.getConfig(thresholdConfig);
            uint32 penalty = sWorld.getConfig(penaltyConfig);

            if (threshold && count >= threshold)
            {
                if (!reason.str().empty())
                    reason << "/";
                reason << GetMovementCheatName(cheatType) << (total ? "(Total:" : "(Tick:") << count << ")";
                action |= penalty;

                if (total)
                    m_cheatOccuranceTotal[cheatType] = 0;
            }
        }
    };

    AddPenaltyForCheat(false, CHEAT_TYPE_TIME_BACK, CONFIG_BOOL_AC_MOVEMENT_CHEAT_REVERSE_TIME_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_REVERSE_TIME_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_REVERSE_TIME_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_NULL_CLIENT_TIME, CONFIG_BOOL_AC_MOVEMENT_CHEAT_NULL_TIME_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_NULL_TIME_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_NULL_TIME_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_SKIPPED_HEARTBEATS, CONFIG_BOOL_AC_MOVEMENT_CHEAT_SKIPPED_HEARTBEATS_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_SKIPPED_HEARTBEATS_THRESHOLD_TICK, CONFIG_UINT32_AC_MOVEMENT_CHEAT_SKIPPED_HEARTBEATS_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_SKIPPED_HEARTBEATS, CONFIG_BOOL_AC_MOVEMENT_CHEAT_SKIPPED_HEARTBEATS_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_SKIPPED_HEARTBEATS_THRESHOLD_TOTAL, CONFIG_UINT32_AC_MOVEMENT_CHEAT_SKIPPED_HEARTBEATS_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_TIME_DESYNC, CONFIG_BOOL_AC_MOVEMENT_CHEAT_TIME_DESYNC_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_TIME_DESYNC_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_TIME_DESYNC_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_NUM_DESYNC, CONFIG_BOOL_AC_MOVEMENT_CHEAT_NUM_DESYNCS_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_NUM_DESYNCS_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_NUM_DESYNCS_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_OVERSPEED_DIST, CONFIG_BOOL_AC_MOVEMENT_CHEAT_OVERSPEED_DISTANCE_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_OVERSPEED_DISTANCE_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_OVERSPEED_DISTANCE_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_OVERSPEED_JUMP, CONFIG_BOOL_AC_MOVEMENT_CHEAT_OVERSPEED_JUMP_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_OVERSPEED_JUMP_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_OVERSPEED_JUMP_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_JUMP_SPEED_CHANGE, CONFIG_BOOL_AC_MOVEMENT_CHEAT_JUMP_SPEED_CHANGE_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_JUMP_SPEED_CHANGE_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_JUMP_SPEED_CHANGE_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_MULTI_JUMP, CONFIG_BOOL_AC_MOVEMENT_CHEAT_MULTI_JUMP_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_MULTI_JUMP_THRESHOLD_TICK, CONFIG_UINT32_AC_MOVEMENT_CHEAT_MULTI_JUMP_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_MULTI_JUMP, CONFIG_BOOL_AC_MOVEMENT_CHEAT_MULTI_JUMP_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_MULTI_JUMP_THRESHOLD_TOTAL, CONFIG_UINT32_AC_MOVEMENT_CHEAT_MULTI_JUMP_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_WALL_CLIMB, CONFIG_BOOL_AC_MOVEMENT_CHEAT_WALL_CLIMB_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_WALL_CLIMB_THRESHOLD_TICK, CONFIG_UINT32_AC_MOVEMENT_CHEAT_WALL_CLIMB_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_WALL_CLIMB, CONFIG_BOOL_AC_MOVEMENT_CHEAT_WALL_CLIMB_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_WALL_CLIMB_THRESHOLD_TOTAL, CONFIG_UINT32_AC_MOVEMENT_CHEAT_WALL_CLIMB_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_PVE_FLYHACK, CONFIG_BOOL_AC_MOVEMENT_CHEAT_UNREACHABLE_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_UNREACHABLE_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_UNREACHABLE_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_FLY_HACK_SWIM, CONFIG_BOOL_AC_MOVEMENT_CHEAT_FLY_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_FLY_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_FLY_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_NO_FALL_TIME, CONFIG_BOOL_AC_MOVEMENT_CHEAT_NO_FALL_TIME_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_NO_FALL_TIME_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_NO_FALL_TIME_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_TELEPORT, CONFIG_BOOL_AC_MOVEMENT_CHEAT_TELEPORT_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_TELEPORT_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_TELEPORT_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_TELEPORT_TRANSPORT, CONFIG_BOOL_AC_MOVEMENT_CHEAT_TELE_TO_TRANSPORT_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_TELE_TO_TRANSPORT_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_TELE_TO_TRANSPORT_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_FAKE_TRANSPORT, CONFIG_BOOL_AC_MOVEMENT_CHEAT_FAKE_TRANSPORT_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_FAKE_TRANSPORT_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_FAKE_TRANSPORT_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_WATER_WALK, CONFIG_BOOL_AC_MOVEMENT_CHEAT_WATER_WALK_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_WATER_WALK_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_WATER_WALK_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_SLOW_FALL, CONFIG_BOOL_AC_MOVEMENT_CHEAT_SLOW_FALL_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_SLOW_FALL_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_SLOW_FALL_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_HOVER, CONFIG_BOOL_AC_MOVEMENT_CHEAT_HOVER_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_HOVER_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_HOVER_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_FIXED_Z, CONFIG_BOOL_AC_MOVEMENT_CHEAT_FIXED_Z_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_FIXED_Z_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_FIXED_Z_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_ROOT_MOVE, CONFIG_BOOL_AC_MOVEMENT_CHEAT_ROOT_MOVE_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_ROOT_MOVE_THRESHOLD_TICK, CONFIG_UINT32_AC_MOVEMENT_CHEAT_ROOT_MOVE_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_ROOT_MOVE, CONFIG_BOOL_AC_MOVEMENT_CHEAT_ROOT_MOVE_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_ROOT_MOVE_THRESHOLD_TOTAL, CONFIG_UINT32_AC_MOVEMENT_CHEAT_ROOT_MOVE_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_SELF_ROOT, CONFIG_BOOL_AC_MOVEMENT_CHEAT_SELF_ROOT_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_SELF_ROOT_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_SELF_ROOT_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_WRONG_ACK_DATA, CONFIG_BOOL_AC_MOVEMENT_CHEAT_WRONG_ACK_DATA_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_WRONG_ACK_DATA_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_WRONG_ACK_DATA_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_PENDING_ACK_DELAY, CONFIG_BOOL_AC_MOVEMENT_CHEAT_PENDING_ACK_DELAY_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_PENDING_ACK_DELAY_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_PENDING_ACK_DELAY_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_EXPLORE, CONFIG_BOOL_AC_MOVEMENT_CHEAT_EXPLORE_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_EXPLORE_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_EXPLORE_PENALTY);
    AddPenaltyForCheat(true, CHEAT_TYPE_EXPLORE_HIGH_LEVEL, CONFIG_BOOL_AC_MOVEMENT_CHEAT_EXPLORE_HIGH_LEVEL_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_EXPLORE_HIGH_LEVEL_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_EXPLORE_HIGH_LEVEL_PENALTY);
    AddPenaltyForCheat(false, CHEAT_TYPE_FORBIDDEN_AREA, CONFIG_BOOL_AC_MOVEMENT_CHEAT_FORBIDDEN_AREA_ENABLED, CONFIG_UINT32_AC_MOVEMENT_CHEAT_FORBIDDEN_AREA_THRESHOLD, CONFIG_UINT32_AC_MOVEMENT_CHEAT_FORBIDDEN_AREA_PENALTY);

    return action;
}

void MovementAnticheat::HandleCommand(ChatHandler* handler) const
{
    handler->PSendSysMessage("MaxSpaceDesync=%f", m_maxOverspeedDistance);
    handler->PSendSysMessage("MaxTimeDesync=%u", m_maxClientDesync);

    handler->SendSysMessage("Cheats detected: ");
    for (uint32 i = 0; i < CHEATS_COUNT; ++i)
        if (m_cheatOccuranceTotal[i])
            handler->PSendSysMessage("%2u x %s (cheat %u - 0x%x)", m_cheatOccuranceTotal[i], GetMovementCheatName(CheatType(i)), i, 1 << i);
}

void MovementAnticheat::Init()
{
    m_cheatOccuranceTick.fill(0);
    m_cheatOccuranceTotal.fill(0);

    m_overspeedDistance  = 0.f;
    m_maxOverspeedDistance = 0.f;
    m_clientDesync    = 0;
    m_maxClientDesync = 0;

    m_jumpCount = 0;
    m_jumpFlagCount = 0;
    m_jumpFlagTime = 0;
    m_knockBack = false;

    m_updateCheckTimer = CHEATS_UPDATE_INTERVAL;
}

void MovementAnticheat::InitNewPlayer(Player* pPlayer)
{
    me = pPlayer;
    m_jumpCount = 0;
    m_jumpFlagCount = 0;
    m_jumpFlagTime = 0;
    m_knockBack = false;
}

void MovementAnticheat::ResetJumpCounters()
{
    m_jumpCount = 0;
    m_jumpFlagCount = 0;
    m_jumpFlagTime = 0;
}

void MovementAnticheat::OnKnockBack(Player* pPlayer, float speedxy, float speedz, float cos, float sin)
{
    if (me != pPlayer)
        InitNewPlayer(pPlayer);

    GetLastMovementInfo().jump.startClientTime = WorldTimer::getMSTime() - GetLastMovementInfo().stime + GetLastMovementInfo().ctime;
    GetLastMovementInfo().jump.start.x = me->GetPositionX();
    GetLastMovementInfo().jump.start.y = me->GetPositionY();
    GetLastMovementInfo().jump.start.z = me->GetPositionZ();
    GetLastMovementInfo().jump.cosAngle = cos;
    GetLastMovementInfo().jump.sinAngle = sin;
    GetLastMovementInfo().jump.xyspeed = speedxy;
    GetLastMovementInfo().moveFlags = MOVEFLAG_JUMPING | (GetLastMovementInfo().moveFlags & ~MOVEFLAG_MASK_MOVING_OR_TURN);
    m_knockBack = true;
}

void MovementAnticheat::OnUnreachable(Unit* attacker)
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_ENABLED) ||
        !sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_UNREACHABLE_ENABLED) ||
        (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_PLAYERS_ONLY) && (m_session->GetSecurity() != SEC_PLAYER)))
        return;

    if (IsInKnockBack() ||
        (attacker->GetCharmerOrOwnerGuid() == me->GetObjectGuid()) ||
        (me->GetTransport()))
        return;

    float waterLevel = (me->GetTerrain()->GetWaterLevel(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()) + 5.0f);
    if (me->GetPositionZ() < waterLevel)
        return;
    if (attacker->GetPositionZ() < waterLevel)
        return;

    AddCheats(1 << CHEAT_TYPE_PVE_FLYHACK);
}

void MovementAnticheat::OnExplore(AreaEntry const* pArea)
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_ENABLED) ||
        (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_PLAYERS_ONLY) && (m_session->GetSecurity() != SEC_PLAYER)))
        return;

    if (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_EXPLORE_ENABLED))
        AddCheats(1 << CHEAT_TYPE_EXPLORE);

    if (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_EXPLORE_HIGH_LEVEL_ENABLED) &&
        (static_cast<int32>(me->GetLevel() + 10) < pArea->AreaLevel))
        AddCheats(1 << CHEAT_TYPE_EXPLORE_HIGH_LEVEL);
}

void MovementAnticheat::OnTransport(Player* pPlayer, ObjectGuid transportGuid)
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_ENABLED) ||
        !sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_FAKE_TRANSPORT_ENABLED) ||
        (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_PLAYERS_ONLY) && (m_session->GetSecurity() != SEC_PLAYER)))
        return;

    // Do not allow bypassing anticheat by pretending to be on a transport.
    GameObject* pTransport = pPlayer->GetMap()->GetGameObject(transportGuid);

    if (!pTransport || !pTransport->IsTransport() || !pTransport->IsWithinDist(pPlayer, 70.0f, false))
        AddCheats(1 << CHEAT_TYPE_FAKE_TRANSPORT);
}

void MovementAnticheat::OnWrongAckData()
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_ENABLED) ||
        !sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_WRONG_ACK_DATA_ENABLED) ||
        (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_PLAYERS_ONLY) && (m_session->GetSecurity() != SEC_PLAYER)))
        return;

    AddCheats(1 << CHEAT_TYPE_WRONG_ACK_DATA);
}

void MovementAnticheat::OnFailedToAckChange()
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_ENABLED) ||
        !sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_PENDING_ACK_DELAY_ENABLED) ||
        (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_PLAYERS_ONLY) && (m_session->GetSecurity() != SEC_PLAYER)))
        return;

    AddCheats(1 << CHEAT_TYPE_PENDING_ACK_DELAY);
}

UnitMoveType MovementAnticheat::GetMoveTypeForMovementInfo(MovementInfo const& movementInfo) const
{
    UnitMoveType type = MOVE_RUN;
    if (movementInfo.HasMovementFlag(MOVEFLAG_SWIMMING))
        type = movementInfo.HasMovementFlag(MOVEFLAG_BACKWARD) ? MOVE_SWIM_BACK : MOVE_SWIM;
    else if (movementInfo.HasMovementFlag(MOVEFLAG_WALK_MODE))
        type = MOVE_WALK;
    else if (movementInfo.HasMovementFlag(MOVEFLAG_MASK_MOVING))
        type = movementInfo.HasMovementFlag(MOVEFLAG_BACKWARD) ? MOVE_RUN_BACK : MOVE_RUN;

    return type;
}

bool IsFlagAckOpcode(uint16 opcode)
{
    switch (opcode)
    {
        case CMSG_FORCE_MOVE_ROOT_ACK:
        case CMSG_FORCE_MOVE_UNROOT_ACK:
        case CMSG_MOVE_WATER_WALK_ACK:
        case CMSG_MOVE_HOVER_ACK:
        case CMSG_MOVE_FEATHER_FALL_ACK:
            return true;
    }

    return false;
}

bool IsStopOpcode(uint16 opcode)
{
    switch (opcode)
    {
        case MSG_MOVE_STOP:
        case MSG_MOVE_STOP_STRAFE:
        case MSG_MOVE_STOP_TURN:
        case MSG_MOVE_STOP_PITCH:
        case MSG_MOVE_STOP_SWIM:
            return true;
    }

    return false;
}

bool IsFallEndOpcode(uint16 opcode)
{
    switch (opcode)
    {
        case MSG_MOVE_FALL_LAND:
        case MSG_MOVE_START_SWIM:
            return true;
    }

    return false;
}

bool ShouldRejectMovement(uint32 cheatFlags)
{
    if ((cheatFlags & (1 << CHEAT_TYPE_OVERSPEED_JUMP)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_OVERSPEED_JUMP_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_JUMP_SPEED_CHANGE)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_JUMP_SPEED_CHANGE_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_MULTI_JUMP)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_MULTI_JUMP_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_WALL_CLIMB)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_WALL_CLIMB_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_FLY_HACK_SWIM)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_FLY_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_NO_FALL_TIME)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_NO_FALL_TIME_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_TELEPORT)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_TELEPORT_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_TELEPORT_TRANSPORT)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_TELE_TO_TRANSPORT_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_WATER_WALK)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_WATER_WALK_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_SLOW_FALL)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_SLOW_FALL_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_HOVER)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_HOVER_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_FIXED_Z)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_FIXED_Z_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_ROOT_MOVE)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_ROOT_MOVE_REJECT))
        return true;

    if ((cheatFlags & (1 << CHEAT_TYPE_SELF_ROOT)) &&
        sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_SELF_ROOT_REJECT))
        return true;

    return false;
}

bool ShouldAcceptCorpseMovement(Player* pPlayer, MovementInfo& movementInfo, uint16 opcode)
{
    // Server controlled movement.
    if (!pPlayer->movespline->Finalized())
        return true;

    // A few opcodes can happen soon after death.
    if (pPlayer->GetDeathTimer() > (CORPSE_REPOP_TIME - (10 * IN_MILLISECONDS)))
    {
        if (IsStopOpcode(opcode))
            return true;

        if (IsFallEndOpcode(opcode))
            return true;

        if (IsFlagAckOpcode(opcode))
            return true;

        if ((opcode == MSG_MOVE_HEARTBEAT) &&
            movementInfo.HasMovementFlag(MOVEFLAG_JUMPING | MOVEFLAG_FALLINGFAR))
            return true;
    }

    return false;
}

bool MovementAnticheat::HandlePositionTests(Player* pPlayer, MovementInfo& movementInfo, uint16 opcode)
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_ENABLED) ||
        (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_PLAYERS_ONLY) && (m_session->GetSecurity() != SEC_PLAYER)))
        return true;
    
    if (pPlayer != me)
        InitNewPlayer(pPlayer);

    if (opcode == CMSG_MOVE_FEATHER_FALL_ACK)
        GetLastMovementInfo().jump.startClientTime = movementInfo.jump.startClientTime = movementInfo.ctime;
    
    // Do not accept position changes if player is dead and has not released spirit.
    if (me->GetDeathState() == CORPSE)
    {
        ResetJumpCounters();
        m_knockBack = false;

        if (ShouldAcceptCorpseMovement(pPlayer, movementInfo, opcode))
            return true;
        
        if (IsFlagAckOpcode(opcode))
        {
            me->m_movementInfo.moveFlags = movementInfo.moveFlags;
            me->m_movementInfo.CorrectData(me);
        }
        me->RemoveUnitMovementFlag(MOVEFLAG_MASK_MOVING_OR_TURN);
        me->SendHeartBeat(true);
        return false;
    }
    
    uint32 cheatFlags = 0x0;
#define APPEND_CHEAT(t) cheatFlags |= (1 << t)

    if (movementInfo.ctime == 0)
        APPEND_CHEAT(CHEAT_TYPE_NULL_CLIENT_TIME);

    bool failedSplineCheck = false;
    
    // Server controlled movement.
    if (!me->movespline->Finalized())
    {
        auto const previousPoint = me->movespline->PreviousDestination();
        auto const nextPoint = me->movespline->CurrentDestination();
        float const distanceServer = GetDistance3D(previousPoint, nextPoint);
        float const distanceClient = GetDistance3D(GetLastMovementInfo().pos, movementInfo.pos);

        // Player is moving a greater distance than it takes to reach next point?
        if (distanceClient > distanceServer)
            failedSplineCheck = true;
    }
    // Client controlled movement.
    else
    {
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
        // Not allowed to change jump speed while jumping
        if ((movementInfo.moveFlags & (MOVEFLAG_JUMPING | MOVEFLAG_FALLINGFAR)) &&
           (GetLastMovementInfo().moveFlags & (MOVEFLAG_JUMPING | MOVEFLAG_FALLINGFAR)) &&
           (movementInfo.jump.xyspeed > GetLastMovementInfo().jump.xyspeed + 0.0001f) &&
           (GetLastMovementInfo().jump.xyspeed > 0.0001f) &&
           (!IsInKnockBack()))
            APPEND_CHEAT(CHEAT_TYPE_JUMP_SPEED_CHANGE);
#endif

        if (opcode == MSG_MOVE_JUMP && movementInfo.jump.xyspeed > (me->GetSpeedForMovementInfo(GetLastMovementInfo()) + 0.0001f))
            APPEND_CHEAT(CHEAT_TYPE_OVERSPEED_JUMP);

        if (CheckMultiJump(opcode))
            APPEND_CHEAT(CHEAT_TYPE_MULTI_JUMP);

        if (opcode == MSG_MOVE_STOP_SWIM && (movementInfo.moveFlags & MOVEFLAG_SWIMMING))
            APPEND_CHEAT(CHEAT_TYPE_FLY_HACK_SWIM);

        if (uint32 flags = CheckTimeDesync(movementInfo))
            cheatFlags |= flags;

        bool teleportDetected;
        if (teleportDetected = CheckTeleport(movementInfo))
            APPEND_CHEAT(CHEAT_TYPE_TELEPORT);

        if (CheckForbiddenArea(movementInfo))
            APPEND_CHEAT(CHEAT_TYPE_FORBIDDEN_AREA);

        if (CheckTeleportToTransport(movementInfo))
            APPEND_CHEAT(CHEAT_TYPE_TELEPORT_TRANSPORT);

        if (CheckWallClimb(movementInfo, opcode))
            APPEND_CHEAT(CHEAT_TYPE_WALL_CLIMB);

        if (CheckNoFallTime(movementInfo, opcode))
            APPEND_CHEAT(CHEAT_TYPE_NO_FALL_TIME);
        
        // Distance computation related. No need to do it if teleport detected.
        if (!teleportDetected)
        {
            if (uint32 flags = CheckSpeedHack(movementInfo, opcode))
                cheatFlags |= flags;
        }
    }

    if (IsFallEndOpcode(opcode) || 
        movementInfo.HasMovementFlag(MOVEFLAG_ROOT))
        m_knockBack = false;

    AddCheats(cheatFlags);

    bool const sendHeartbeat = ShouldRejectMovement(cheatFlags);

    if (sendHeartbeat || failedSplineCheck)
    {
        // Movement flags get verified first. Don't undo them if they passed.
        if (IsFlagAckOpcode(opcode))
        {
            me->m_movementInfo.moveFlags = movementInfo.moveFlags;
            me->m_movementInfo.CorrectData(me);
        }     
        
        if (sendHeartbeat)
        {
            if ((cheatFlags & (1 << CHEAT_TYPE_OVERSPEED_JUMP)) &&
                sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_OVERSPEED_JUMP_REJECT))
            {
                UnitMoveType moveType = GetMoveTypeForMovementInfo(GetLastMovementInfo());
                float speedRate = me->GetSpeed(moveType) / baseMoveSpeed[moveType];
                MovementPacketSender::SendSpeedChangeToAll(me, moveType, speedRate);
            }

            if ((cheatFlags & (1 << CHEAT_TYPE_NO_FALL_TIME)) &&
                sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_NO_FALL_TIME_REJECT))
            {
                // Teleport to ground height in this case.
                float const x = GetLastMovementInfo().pos.x;
                float const y = GetLastMovementInfo().pos.y;
                float const z = me->GetTerrain()->GetWaterOrGroundLevel(movementInfo.pos) + 5;
                GetLastMovementInfo().RemoveMovementFlag(MOVEFLAG_JUMPING | MOVEFLAG_FALLINGFAR);
                GetLastMovementInfo().ctime = 0; // Not a client packet. Pauses extrapolation.
                me->TeleportPositionRelocation(x, y, z, 0);
            }
            me->SendHeartBeat(true);
        } 

        return false;
    }

    return true;
#undef APPEND_CHEAT
}

bool MovementAnticheat::HandleFlagTests(Player* pPlayer, MovementInfo& movementInfo, uint16 opcode)
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_ENABLED) ||
        (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_PLAYERS_ONLY) && (m_session->GetSecurity() != SEC_PLAYER)))
        return true;
    
    if (me != pPlayer)
        InitNewPlayer(pPlayer);

    auto const currentMoveFlags = movementInfo.moveFlags;
    uint32 removeMoveFlags = 0;

    uint32 cheatFlags = 0x0;
#define APPEND_CHEAT(t) cheatFlags |= (1 << t)

    // Client is rooted, but there is no root server side.
    if ((currentMoveFlags & MOVEFLAG_ROOT) &&
        !(GetLastMovementInfo().moveFlags & MOVEFLAG_ROOT) &&
        !me->HasPendingMovementChange(ROOT) &&
        !me->HasUnitState(UNIT_STAT_ROOT | UNIT_STAT_PENDING_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_PENDING_STUNNED) &&
        (opcode != CMSG_FORCE_MOVE_ROOT_ACK))
    {
        APPEND_CHEAT(CHEAT_TYPE_SELF_ROOT);
        removeMoveFlags |= MOVEFLAG_ROOT;
    }

    // Moving while rooted. We do not apply root flag until ack, so should be no false positives.
    if ((currentMoveFlags & MOVEFLAG_MASK_MOVING) &&
        ((currentMoveFlags & MOVEFLAG_ROOT) || (GetLastMovementInfo().moveFlags & MOVEFLAG_ROOT)) &&
        !me->HasPendingMovementChange(ROOT) &&
        (opcode != CMSG_FORCE_MOVE_UNROOT_ACK))
    {
        APPEND_CHEAT(CHEAT_TYPE_ROOT_MOVE);
        removeMoveFlags |= MOVEFLAG_MASK_MOVING;
        movementInfo.moveFlags |= MOVEFLAG_ROOT;
    }

    // This flag is only for creatures.
    if (currentMoveFlags & MOVEFLAG_FIXED_Z)
    {
        APPEND_CHEAT(CHEAT_TYPE_FIXED_Z);
        removeMoveFlags |= MOVEFLAG_FIXED_Z;
    }

    // This flag is only for creatures.
    if ((currentMoveFlags & MOVEFLAG_LEVITATING) &&
        !me->HasUnitState(UNIT_STAT_FLYING_ALLOWED))
    {
        APPEND_CHEAT(CHEAT_TYPE_FLY_HACK_SWIM);
        removeMoveFlags |= MOVEFLAG_LEVITATING;
    }

    if ((currentMoveFlags & MOVEFLAG_SWIMMING) &&
        (currentMoveFlags & MOVEFLAG_FLYING) &&
        !me->IsTaxiFlying() &&
        !me->HasUnitState(UNIT_STAT_FLYING_ALLOWED))
    {
        APPEND_CHEAT(CHEAT_TYPE_FLY_HACK_SWIM);
        removeMoveFlags |= MOVEFLAG_SWIMMING | MOVEFLAG_FLYING;
    }

    if ((currentMoveFlags & MOVEFLAG_WATERWALKING) &&
        !(GetLastMovementInfo().moveFlags & MOVEFLAG_WATERWALKING) &&
        !me->HasAuraType(SPELL_AURA_WATER_WALK) &&
        !me->HasAuraType(SPELL_AURA_GHOST) &&
        !me->HasPendingMovementChange(WATER_WALK) &&
        (opcode != CMSG_MOVE_WATER_WALK_ACK))
    {
        APPEND_CHEAT(CHEAT_TYPE_WATER_WALK);
        removeMoveFlags |= MOVEFLAG_WATERWALKING;
    }

    if ((currentMoveFlags & MOVEFLAG_SAFE_FALL) &&
        !(GetLastMovementInfo().moveFlags & MOVEFLAG_SAFE_FALL) &&
        !me->HasAuraType(SPELL_AURA_FEATHER_FALL) &&
        !me->HasPendingMovementChange(FEATHER_FALL) &&
        (opcode != CMSG_MOVE_FEATHER_FALL_ACK))
    {
        APPEND_CHEAT(CHEAT_TYPE_SLOW_FALL);
        removeMoveFlags |= MOVEFLAG_SAFE_FALL;
    }

    if ((currentMoveFlags & MOVEFLAG_HOVER) &&
        !(GetLastMovementInfo().moveFlags & MOVEFLAG_HOVER) &&
        !me->HasAuraType(SPELL_AURA_HOVER) &&
        !me->HasPendingMovementChange(SET_HOVER) &&
        (opcode != CMSG_MOVE_HOVER_ACK))
    {
        APPEND_CHEAT(CHEAT_TYPE_HOVER);
        removeMoveFlags |= MOVEFLAG_HOVER;
    }
#undef APPEND_CHEAT

    AddCheats(cheatFlags);

    if (ShouldRejectMovement(cheatFlags))
    {
        me->RemoveUnitMovementFlag(removeMoveFlags);
        me->SendHeartBeat(true);
        return false;
    }
    else if (removeMoveFlags)
        movementInfo.RemoveMovementFlag(removeMoveFlags);

    return true;
}

#define JUMP_FLAG_THRESHOLD 5
#define FAR_FALL_FLAG_TIME 3000
#define HEIGHT_LEEWAY 5.0f

bool ShouldResetNoFallTimeCheck(MovementInfo const& movementInfo, uint16 opcode)
{
    if (movementInfo.HasMovementFlag(MOVEFLAG_FALLINGFAR | MOVEFLAG_ROOT | MOVEFLAG_FLYING | MOVEFLAG_SWIMMING | MOVEFLAG_SAFE_FALL | MOVEFLAG_ONTRANSPORT))
        return true;

    switch (opcode)
    {
        case MSG_MOVE_JUMP:
        case MSG_MOVE_FALL_LAND:
        case MSG_MOVE_START_SWIM:
        case CMSG_MOVE_KNOCK_BACK_ACK:
        {
            return true;
        }
    }

    return false;
}

bool MovementAnticheat::CheckNoFallTime(MovementInfo const& movementInfo, uint16 opcode)
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_NO_FALL_TIME_ENABLED))
        return false;

    if (ShouldResetNoFallTimeCheck(movementInfo, opcode))
    {
        m_jumpFlagCount = 0;
        m_jumpFlagTime = 0;
        return false;
    }
    
    if (movementInfo.HasMovementFlag(MOVEFLAG_JUMPING))
    {
        m_jumpFlagCount++;

        if (!m_jumpFlagTime)
            m_jumpFlagTime = movementInfo.stime;
    }
    
    return m_jumpFlagTime &&
       (m_jumpFlagCount > JUMP_FLAG_THRESHOLD) &&
       (movementInfo.stime - m_jumpFlagTime > (IsInKnockBack() ? FAR_FALL_FLAG_TIME * 2 : FAR_FALL_FLAG_TIME)) &&
       (movementInfo.pos.z + 1.0f > GetLastMovementInfo().pos.z) &&
       (movementInfo.pos.z > me->GetTerrain()->GetWaterOrGroundLevel(movementInfo.pos) + HEIGHT_LEEWAY);
}

uint32 MovementAnticheat::CheckTimeDesync(MovementInfo const& movementInfo)
{
    uint32 cheatFlags = 0x0;
#define APPEND_CHEAT(t) cheatFlags |= (1 << t)

    if (GetLastMovementInfo().ctime)
    {
        if (GetLastMovementInfo().moveFlags & MOVEFLAG_MASK_MOVING)
        {
            int32 currentDesync = (int32)WorldTimer::getMSTimeDiff(GetLastMovementInfo().ctime, movementInfo.ctime) - WorldTimer::getMSTimeDiff(GetLastMovementInfo().stime, movementInfo.stime);
            m_clientDesync += currentDesync;
            if (currentDesync > 1000)
                APPEND_CHEAT(CHEAT_TYPE_NUM_DESYNC);
        }
        // Client going back in time?
        if (movementInfo.ctime < GetLastMovementInfo().ctime)
            APPEND_CHEAT(CHEAT_TYPE_TIME_BACK);
    }

    return cheatFlags;
#undef APPEND_CHEAT
}

bool MovementAnticheat::CheckMultiJump(uint16 opcode)
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_MULTI_JUMP_ENABLED))
        return false;

    switch (opcode)
    {
        case MSG_MOVE_JUMP:
        {
            m_jumpCount++;
            if (m_jumpCount > 2)
                return true;
            break;
        }
        case MSG_MOVE_FALL_LAND:
        case MSG_MOVE_START_SWIM:
        {
            m_jumpCount = 0;
            break;
        }
    }

    return false;
}

#define NO_WALL_CLIMB_CHECK_MOVE_FLAGS (MOVEFLAG_JUMPING | MOVEFLAG_FALLINGFAR | MOVEFLAG_SWIMMING | MOVEFLAG_CAN_FLY | MOVEFLAG_FLYING | MOVEFLAG_PITCH_UP | MOVEFLAG_PITCH_DOWN | MOVEFLAG_ONTRANSPORT)
#define NO_WALL_CLIMB_CHECK_UNIT_FLAGS (UNIT_FLAG_UNK_0 | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_CONFUSED | UNIT_FLAG_FLEEING | UNIT_FLAG_POSSESSED)

bool MovementAnticheat::CheckWallClimb(MovementInfo const& movementInfo, uint16 opcode) const
{
    // Not currently handled cases.
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_WALL_CLIMB_ENABLED) ||
       (opcode != MSG_MOVE_HEARTBEAT) ||
       (GetLastMovementInfo().moveFlags & NO_WALL_CLIMB_CHECK_MOVE_FLAGS) ||
       (movementInfo.moveFlags & NO_WALL_CLIMB_CHECK_MOVE_FLAGS) ||
       (me->HasFlag(UNIT_FIELD_FLAGS, NO_WALL_CLIMB_CHECK_UNIT_FLAGS)) ||
        IsInKnockBack() || me->IsTaxiFlying())
        return false;
    
    float const deltaXY = GetDistance2D(GetLastMovementInfo().pos, movementInfo.pos);
    if (deltaXY < 0.5f)
        return false;

    float const deltaZ = movementInfo.pos.z - GetLastMovementInfo().pos.z;
    if (deltaZ < 0.5f)
        return false;

    float const angleRad = atan(deltaZ / deltaXY);
    //float const angleDeg = angleRad * (360 / (M_PI_F * 2));

    return angleRad > sWorld.getConfig(CONFIG_FLOAT_AC_MOVEMENT_CHEAT_WALL_CLIMB_ANGLE);
}

bool MovementAnticheat::CheckForbiddenArea(MovementInfo const& movementInfo) const
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_FORBIDDEN_AREA_ENABLED))
        return false;

    switch(me->GetMapId())
    {
        case 30: // Alterac Valley
        {
            if (BattleGround* bg = me->GetBattleGround())
            {
                if (bg->GetStatus() == STATUS_WAIT_JOIN)
                {
                    // Outside of starting area before BG has started.
                    if (me->GetTeam() == ALLIANCE && movementInfo.pos.x < 770.0f)
                        return true;
                    if (me->GetTeam() == HORDE && movementInfo.pos.y > -540.0f)
                        return true;
                }
            }
            break;
        }
        case 489: // Warsong Gulch
        {
            // Only way to get this high is with engineering items malfunction.
            if (!(movementInfo.moveFlags & (MOVEFLAG_FALLINGFAR | MOVEFLAG_JUMPING)) && movementInfo.pos.z > 380.0f)
                return true;

            if (BattleGround* bg = me->GetBattleGround())
            {
                if (bg->GetStatus() == STATUS_WAIT_JOIN)
                {
                    // Outside of starting area before BG has started.
                    if (me->GetTeam() == ALLIANCE && movementInfo.pos.x < 1490.0f)
                        return true;
                    if (me->GetTeam() == HORDE && movementInfo.pos.x > 957.0f)
                        return true;
                }
            }
            break;
        }
        case 529: // Arathi Basin
        {
            if (BattleGround* bg = me->GetBattleGround())
            {
                if (bg->GetStatus() == STATUS_WAIT_JOIN)
                {
                    // Outside of starting area before BG has started.
                    if (me->GetTeam() == ALLIANCE && movementInfo.pos.x < 1270.0f)
                        return true;
                    if (me->GetTeam() == HORDE && movementInfo.pos.x > 730.0f)
                        return true;
                }
            }
            break;
        }
    }

    return false;
}

uint32 MovementAnticheat::CheckSpeedHack(MovementInfo const& movementInfo, uint16 opcode)
{
    if ((opcode == CMSG_MOVE_KNOCK_BACK_ACK) ||
        me->IsTaxiFlying() || 
        me->IsBeingTeleported())
        return 0;

    uint32 cheatFlags = 0x0;
#define APPEND_CHEAT(t) cheatFlags |= (1 << t)

    int32 clientTimeDiff = movementInfo.ctime - GetLastMovementInfo().ctime;
    if (sWorld.getConfig(CONFIG_INT32_AC_ANTICHEAT_MAX_ALLOWED_DESYNC) && clientTimeDiff > sWorld.getConfig(CONFIG_INT32_AC_ANTICHEAT_MAX_ALLOWED_DESYNC))
        clientTimeDiff = sWorld.getConfig(CONFIG_INT32_AC_ANTICHEAT_MAX_ALLOWED_DESYNC);

    if (sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_SPEED_HACK_ENABLED))
    {
        float intX, intY, intZ, intO;

        // Check vs extrapolation
        if (me->ExtrapolateMovement(GetLastMovementInfo(), clientTimeDiff, intX, intY, intZ, intO))
        {
            auto const intDX = intX - movementInfo.pos.x;
            auto const intDY = intY - movementInfo.pos.y;
            auto const intDZ = intZ - movementInfo.pos.z;

            auto interpolDist = pow(intDX, 2) + pow(intDY, 2);
            if ((movementInfo.moveFlags | GetLastMovementInfo().moveFlags) & MOVEFLAG_JUMPING)
                interpolDist += pow(intDZ, 2);
            interpolDist = sqrt(interpolDist);

            float allowedDX = pow(intX - GetLastMovementInfo().pos.x, 2);
            float allowedDY = pow(intY - GetLastMovementInfo().pos.y, 2);
            float allowedDXY = sqrt(allowedDX + allowedDY);
            float realDistance2D_sq = pow(movementInfo.pos.x - GetLastMovementInfo().pos.x, 2) + pow(movementInfo.pos.y - GetLastMovementInfo().pos.y, 2);

            if (realDistance2D_sq > (allowedDY + allowedDX) * 1.1f)
                m_overspeedDistance += sqrt(realDistance2D_sq) - sqrt(allowedDY + allowedDX);

            DEBUG_UNIT(me, DEBUG_CHEAT, "[Opcode:%u:0x%x] Flags 0x%x [DT=%u:DR=%.2f]", opcode, opcode, movementInfo.moveFlags, movementInfo.ctime - GetLastMovementInfo().ctime, interpolDist);
        }
        // Simple calculation for transports
        else if (!movementInfo.t_guid.IsEmpty() && (movementInfo.moveFlags & MOVEFLAG_ONTRANSPORT) &&
                 !GetLastMovementInfo().t_guid.IsEmpty() && (GetLastMovementInfo().moveFlags & MOVEFLAG_ONTRANSPORT))
        {
            float const distanceTraveled = GetDistance2D(GetLastMovementInfo().t_pos, movementInfo.t_pos);
            float const timeFactor = float(1 * IN_MILLISECONDS) / float(std::max(1, clientTimeDiff));
            if (distanceTraveled > 0)
            {
                float const distanceAllowed1 = me->GetSpeedForMovementInfo(movementInfo) / timeFactor;
                float const distanceAllowed2 = me->GetSpeedForMovementInfo(GetLastMovementInfo()) / timeFactor;
                float const distanceAllowed = std::max(distanceAllowed1, distanceAllowed2);
                if (distanceTraveled > distanceAllowed * 2.0f)
                    m_overspeedDistance += (distanceTraveled - distanceAllowed);
            }
        }
    }

    // Client should send heartbeats every 500ms
    if (clientTimeDiff > 1000 && GetLastMovementInfo().ctime && GetLastMovementInfo().moveFlags & MOVEFLAG_MASK_MOVING)
        APPEND_CHEAT(CHEAT_TYPE_SKIPPED_HEARTBEATS);

    return cheatFlags;
#undef APPEND_CHEAT
}

bool MovementAnticheat::CheckTeleportToTransport(MovementInfo const& movementInfo) const
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_TELE_TO_TRANSPORT_ENABLED))
        return false;

    // Minimal checks on transports
    if (movementInfo.moveFlags & MOVEFLAG_ONTRANSPORT)
    {
        // To transport tele hack detection
        if (GetLastMovementInfo().ctime && !(GetLastMovementInfo().moveFlags & MOVEFLAG_ONTRANSPORT))
        {
            float dist2d = (movementInfo.pos.x - GetLastMovementInfo().pos.x) * (movementInfo.pos.x - GetLastMovementInfo().pos.x);
            dist2d += (movementInfo.pos.y - GetLastMovementInfo().pos.y) * (movementInfo.pos.y - GetLastMovementInfo().pos.y);
            if (dist2d > 100 * 100)
                return true;
        }
    }
    return false;
}

bool MovementAnticheat::CheckTeleport(MovementInfo const& movementInfo) const
{
    if (!sWorld.getConfig(CONFIG_BOOL_AC_MOVEMENT_CHEAT_TELEPORT_ENABLED))
        return false;

    if (!me->m_transport && !me->HasMovementFlag(MOVEFLAG_ONTRANSPORT) && !me->IsTaxiFlying())
    {
        if (!IsTeleportAllowed(movementInfo))
            return true;
    }

    return false;
}

#define ALLOWED_TRANSPORT_DISTANCE 100.0f

bool MovementAnticheat::IsTeleportAllowed(MovementInfo const& movementInfo) const
{
    if ((me->GetPositionX() == 0.0f || me->GetPositionY() == 0.0f || me->GetPositionZ() == 0.0f) ||
       (movementInfo.GetPos().x == 0.0f || movementInfo.GetPos().y == 0.0f || movementInfo.GetPos().z == 0.0f) ||
       (me->IsLaunched()) || 
       (me->IsBeingTeleported()))
        return true;

    float const distance = GetDistance3D(me->GetPosition(), movementInfo.pos);
    float maxDistance = sWorld.getConfig(CONFIG_FLOAT_AC_MOVEMENT_CHEAT_TELEPORT_DISTANCE) * std::max(1.0f, me->GetSpeedRate(GetMoveTypeForMovementInfo(movementInfo)) * 0.1f);

    // Exclude elevators
    uint32 destZoneId = 0;
    uint32 destAreaId = 0;
    me->GetTerrain()->GetZoneAndAreaId(destZoneId, destAreaId, movementInfo.pos.x, movementInfo.pos.y, movementInfo.pos.z);
    if (destZoneId == me->GetZoneId() && destAreaId == me->GetAreaId())
    {
        // Undercity Lift
        if ((me->GetZoneId() == 1497 && me->GetAreaId() == 1497) ||
        // Thousand Needles Lift
           (me->GetZoneId() == 2257 || (me->GetZoneId() == 400 && me->GetAreaId() == 485)))
            maxDistance = std::max(maxDistance, ALLOWED_TRANSPORT_DISTANCE);
    }

    return distance < maxDistance;
}
