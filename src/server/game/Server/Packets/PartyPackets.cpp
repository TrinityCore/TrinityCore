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

#include "PartyPackets.h"
#include "Pet.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "Realm.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "Vehicle.h"
#include "World.h"
#include "WorldSession.h"

WorldPacket const* WorldPackets::Party::PartyCommandResult::Write()
{
    _worldPacket.WriteBits(Name.size(), 9);

    _worldPacket.WriteBits(Command, 4);
    _worldPacket.WriteBits(Result, 6);

    _worldPacket << uint32(ResultData);
    _worldPacket << ResultGUID;
    _worldPacket.WriteString(Name);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Party::PartyInviteClient::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();

    _worldPacket.ResetBitPos();
    uint32 targetNameLen = _worldPacket.ReadBits(9);
    uint32 targetRealmLen = _worldPacket.ReadBits(9);

    _worldPacket >> ProposedRoles;
    _worldPacket >> TargetGUID;

    TargetName = _worldPacket.ReadString(targetNameLen);
    TargetRealm = _worldPacket.ReadString(targetRealmLen);
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

WorldPacket const* WorldPackets::Party::PartyInvite::Write()
{
    _worldPacket.WriteBit(CanAccept);
    _worldPacket.WriteBit(MightCRZYou);
    _worldPacket.WriteBit(IsXRealm);
    _worldPacket.WriteBit(MustBeBNetFriend);
    _worldPacket.WriteBit(AllowMultipleRoles);
    _worldPacket.WriteBit(QuestSessionActive);
    _worldPacket.WriteBits(InviterName.length(), 6);

    _worldPacket << InviterRealm;
    _worldPacket << InviterGUID;
    _worldPacket << InviterBNetAccountId;
    _worldPacket << uint16(Unk1);
    _worldPacket << uint8(ProposedRoles);
    _worldPacket << uint32(LfgSlots.size());
    _worldPacket << uint32(LfgCompletedMask);

    _worldPacket.WriteString(InviterName);

    for (uint32 LfgSlot : LfgSlots)
        _worldPacket << LfgSlot;

    return &_worldPacket;
}

void WorldPackets::Party::PartyInvite::Initialize(Player const* inviter, int32 proposedRoles, bool canAccept)
{
    CanAccept = canAccept;

    InviterName = inviter->GetName();
    InviterGUID = inviter->GetGUID();
    InviterBNetAccountId = inviter->GetSession()->GetAccountGUID();

    ProposedRoles = proposedRoles;

    InviterRealm = Auth::VirtualRealmInfo(realm.Id.GetAddress(), true, false, realm.Name, realm.NormalizedName);
}

void WorldPackets::Party::PartyInviteResponse::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    Accept = _worldPacket.ReadBit();
    bool hasRolesDesired = _worldPacket.ReadBit();

    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();

    if (hasRolesDesired)
        _worldPacket >> RolesDesired.emplace();
}

void WorldPackets::Party::PartyUninvite::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    uint32 reasonLen = _worldPacket.ReadBits(8);

    _worldPacket >> TargetGUID;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();

    Reason = _worldPacket.ReadString(reasonLen);
}

WorldPacket const* WorldPackets::Party::GroupDecline::Write()
{
    _worldPacket.WriteBits(Name.length(), 9);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

void WorldPackets::Party::RequestPartyMemberStats::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    _worldPacket >> TargetGUID;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyMemberPhase const& phase)
{
    data << uint32(phase.Flags);
    data << uint16(phase.Id);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyMemberPhaseStates const& phases)
{
    data << uint32(phases.PhaseShiftFlags);
    data << uint32(phases.List.size());
    data << phases.PersonalGUID;

    for (WorldPackets::Party::PartyMemberPhase const& phase : phases.List)
        data << phase;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyMemberAuraStates const& aura)
{
    data << int32(aura.SpellID);
    data << uint16(aura.Flags);
    data << uint32(aura.ActiveFlags);
    data << int32(aura.Points.size());
    for (float points : aura.Points)
        data << float(points);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::CTROptions const& ctrOptions)
{
    data << uint32(ctrOptions.ContentTuningConditionMask);
    data << int32(ctrOptions.Unused901);
    data << uint32(ctrOptions.ExpansionLevelMask);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyMemberPetStats const& petStats)
{
    data << petStats.GUID;
    data << int32(petStats.ModelId);
    data << int32(petStats.CurrentHealth);
    data << int32(petStats.MaxHealth);
    data << uint32(petStats.Auras.size());
    for (WorldPackets::Party::PartyMemberAuraStates const& aura : petStats.Auras)
        data << aura;

    data.WriteBits(petStats.Name.size(), 8);
    data.FlushBits();
    data.WriteString(petStats.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyMemberStats const& memberStats)
{
    for (uint32 i = 0; i < 2; i++)
        data << uint8(memberStats.PartyType[i]);

    data << uint16(memberStats.Status);
    data << uint8(memberStats.PowerType);
    data << uint16(memberStats.PowerDisplayID);
    data << int32(memberStats.CurrentHealth);
    data << int32(memberStats.MaxHealth);
    data << uint16(memberStats.CurrentPower);
    data << uint16(memberStats.MaxPower);
    data << uint16(memberStats.Level);
    data << uint16(memberStats.SpecID);
    data << uint16(memberStats.ZoneID);
    data << uint16(memberStats.WmoGroupID);
    data << uint32(memberStats.WmoDoodadPlacementID);
    data << int16(memberStats.PositionX);
    data << int16(memberStats.PositionY);
    data << int16(memberStats.PositionZ);
    data << int32(memberStats.VehicleSeat);
    data << uint32(memberStats.Auras.size());
    data << memberStats.Phases;
    data << memberStats.ChromieTime;

    for (WorldPackets::Party::PartyMemberAuraStates const& aura : memberStats.Auras)
        data << aura;

    data.WriteBit(memberStats.PetStats.has_value());
    data.FlushBits();

    data << memberStats.DungeonScore;

    if (memberStats.PetStats.has_value())
        data << *memberStats.PetStats;

    return data;
}

WorldPacket const* WorldPackets::Party::PartyMemberFullState::Write()
{
    _worldPacket.WriteBit(ForEnemy);

    _worldPacket << MemberStats;
    _worldPacket << MemberGuid;

    return &_worldPacket;
}

void WorldPackets::Party::SetPartyLeader::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    _worldPacket >> TargetGUID;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

void WorldPackets::Party::SetPartyAssignment::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    Set = _worldPacket.ReadBit();
    _worldPacket >> Assignment;
    _worldPacket >> Target;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

void WorldPackets::Party::SetRole::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    _worldPacket >> TargetGUID;
    _worldPacket >> Role;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

WorldPacket const* WorldPackets::Party::RoleChangedInform::Write()
{
    _worldPacket << uint8(PartyIndex);
    _worldPacket << From;
    _worldPacket << ChangedUnit;
    _worldPacket << uint8(OldRole);
    _worldPacket << uint8(NewRole);

    return &_worldPacket;
}

void WorldPackets::Party::LeaveGroup::Read()
{
    if (_worldPacket.ReadBit())
        _worldPacket >> PartyIndex.emplace();
}

void WorldPackets::Party::SetLootMethod::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    _worldPacket >> LootMethod;
    _worldPacket >> LootMasterGUID;
    _worldPacket >> LootThreshold;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

void WorldPackets::Party::MinimapPingClient::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    _worldPacket >> PositionX;
    _worldPacket >> PositionY;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

WorldPacket const* WorldPackets::Party::MinimapPing::Write()
{
    _worldPacket << Sender;
    _worldPacket << PositionX;
    _worldPacket << PositionY;

    return &_worldPacket;
}

void WorldPackets::Party::UpdateRaidTarget::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    _worldPacket >> Target;
    _worldPacket >> Symbol;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

WorldPacket const* WorldPackets::Party::SendRaidTargetUpdateSingle::Write()
{
    _worldPacket << PartyIndex;
    _worldPacket << Symbol;
    _worldPacket << Target;
    _worldPacket << ChangedBy;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Party::SendRaidTargetUpdateAll::Write()
{
    _worldPacket << uint8(PartyIndex);
    _worldPacket << uint32(TargetIcons.size());

    for (auto itr = TargetIcons.begin(); itr != TargetIcons.end(); ++itr)
    {
        _worldPacket << itr->second;
        _worldPacket << uint8(itr->first);
    }

    return &_worldPacket;
}

void WorldPackets::Party::ConvertRaid::Read()
{
    Raid = _worldPacket.ReadBit();
}

void WorldPackets::Party::RequestPartyJoinUpdates::Read()
{
    if (_worldPacket.ReadBit())
        _worldPacket >> PartyIndex.emplace();
}

void WorldPackets::Party::SetAssistantLeader::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    Apply = _worldPacket.ReadBit();
    _worldPacket >> Target;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

void WorldPackets::Party::DoReadyCheck::Read()
{
    if (_worldPacket.ReadBit())
        _worldPacket >> PartyIndex.emplace();
}

WorldPacket const* WorldPackets::Party::ReadyCheckStarted::Write()
{
    _worldPacket << PartyIndex;
    _worldPacket << PartyGUID;
    _worldPacket << InitiatorGUID;
    _worldPacket << Duration;

    return &_worldPacket;
}

void WorldPackets::Party::ReadyCheckResponseClient::Read()
{
    IsReady = _worldPacket.ReadBit();
    if (_worldPacket.ReadBit())
        _worldPacket >> PartyIndex.emplace();
}

WorldPacket const* WorldPackets::Party::ReadyCheckResponse::Write()
{
    _worldPacket << PartyGUID;
    _worldPacket << Player;

    _worldPacket.WriteBit(IsReady);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Party::ReadyCheckCompleted::Write()
{
    _worldPacket << PartyIndex;
    _worldPacket << PartyGUID;

    return &_worldPacket;
}

void WorldPackets::Party::OptOutOfLoot::Read()
{
    PassOnLoot = _worldPacket.ReadBit();
}

void WorldPackets::Party::InitiateRolePoll::Read()
{
    if (_worldPacket.ReadBit())
        _worldPacket >> PartyIndex.emplace();
}

WorldPacket const* WorldPackets::Party::RolePollInform::Write()
{
    _worldPacket << PartyIndex;
    _worldPacket << From;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Party::GroupNewLeader::Write()
{
    _worldPacket << PartyIndex;
    _worldPacket.WriteBits(Name.size(), 9);
    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyPlayerInfo const& playerInfo)
{
    data.WriteBits(playerInfo.Name.size(), 6);
    data.WriteBits(playerInfo.VoiceStateID.size() + 1, 6);
    data.WriteBit(playerInfo.Connected);
    data.WriteBit(playerInfo.VoiceChatSilenced);
    data.WriteBit(playerInfo.FromSocialQueue);
    data << playerInfo.GUID;
    data << uint8(playerInfo.Subgroup);
    data << uint8(playerInfo.Flags);
    data << uint8(playerInfo.RolesAssigned);
    data << uint8(playerInfo.Class);
    data << uint8(playerInfo.FactionGroup);
    data.WriteString(playerInfo.Name);
    if (!playerInfo.VoiceStateID.empty())
        data << playerInfo.VoiceStateID;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyLFGInfo const& lfgInfos)
{
    data << uint8(lfgInfos.MyFlags);
    data << uint32(lfgInfos.Slot);
    data << uint32(lfgInfos.MyRandomSlot);
    data << uint8(lfgInfos.MyPartialClear);
    data << float(lfgInfos.MyGearDiff);
    data << uint8(lfgInfos.MyStrangerCount);
    data << uint8(lfgInfos.MyKickVoteCount);
    data << uint8(lfgInfos.BootCount);
    data.WriteBit(lfgInfos.Aborted);
    data.WriteBit(lfgInfos.MyFirstReward);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyLootSettings const& lootSettings)
{
    data << uint8(lootSettings.Method);
    data << lootSettings.LootMaster;
    data << uint8(lootSettings.Threshold);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyDifficultySettings const& difficultySettings)
{
    data << uint32(difficultySettings.DungeonDifficultyID);
    data << uint32(difficultySettings.RaidDifficultyID);
    data << uint32(difficultySettings.LegacyRaidDifficultyID);

    return data;
}

WorldPacket const* WorldPackets::Party::PartyUpdate::Write()
{
    _worldPacket << uint16(PartyFlags);
    _worldPacket << uint8(PartyIndex);
    _worldPacket << uint8(PartyType);
    _worldPacket << int32(MyIndex);
    _worldPacket << PartyGUID;
    _worldPacket << uint32(SequenceNum);
    _worldPacket << LeaderGUID;
    _worldPacket << uint8(LeaderFactionGroup);
    _worldPacket << uint32(PlayerList.size());
    _worldPacket.WriteBit(LfgInfos.has_value());
    _worldPacket.WriteBit(LootSettings.has_value());
    _worldPacket.WriteBit(DifficultySettings.has_value());
    _worldPacket.FlushBits();

    for (WorldPackets::Party::PartyPlayerInfo const& playerInfos : PlayerList)
        _worldPacket << playerInfos;

    if (LootSettings.has_value())
        _worldPacket << *LootSettings;

    if (DifficultySettings.has_value())
        _worldPacket << *DifficultySettings;

    if (LfgInfos.has_value())
        _worldPacket << *LfgInfos;

    return &_worldPacket;
}

void WorldPackets::Party::SetEveryoneIsAssistant::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    EveryoneIsAssistant = _worldPacket.ReadBit();
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

void WorldPackets::Party::ChangeSubGroup::Read()
{
    _worldPacket >> TargetGUID;
    _worldPacket >> NewSubGroup;
    if (_worldPacket.ReadBit())
        _worldPacket >> PartyIndex.emplace();
}

void WorldPackets::Party::SwapSubGroups::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    _worldPacket >> FirstTarget;
    _worldPacket >> SecondTarget;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

void WorldPackets::Party::ClearRaidMarker::Read()
{
    _worldPacket >> MarkerId;
}

WorldPacket const* WorldPackets::Party::RaidMarkersChanged::Write()
{
    _worldPacket << uint8(PartyIndex);
    _worldPacket << uint32(ActiveMarkers);

    _worldPacket.WriteBits(RaidMarkers.size(), 4);
    _worldPacket.FlushBits();

    for (RaidMarker const* raidMarker : RaidMarkers)
    {
        _worldPacket << raidMarker->TransportGUID;
        _worldPacket << raidMarker->Location.GetMapId();
        _worldPacket << raidMarker->Location.PositionXYZStream();
    }

    return &_worldPacket;
}

void WorldPackets::Party::PartyMemberFullState::Initialize(Player const* player)
{
    ForEnemy = false;

    MemberGuid = player->GetGUID();

    // Status
    MemberStats.Status = MEMBER_STATUS_ONLINE;

    if (player->IsPvP())
        MemberStats.Status |= MEMBER_STATUS_PVP;

    if (!player->IsAlive())
    {
        if (player->HasPlayerFlag(PLAYER_FLAGS_GHOST))
            MemberStats.Status |= MEMBER_STATUS_GHOST;
        else
            MemberStats.Status |= MEMBER_STATUS_DEAD;
    }

    if (player->IsFFAPvP())
        MemberStats.Status |= MEMBER_STATUS_PVP_FFA;

    if (player->isAFK())
        MemberStats.Status |= MEMBER_STATUS_AFK;

    if (player->isDND())
        MemberStats.Status |= MEMBER_STATUS_DND;

    if (player->GetVehicle())
        MemberStats.Status |= MEMBER_STATUS_VEHICLE;

    // Level
    MemberStats.Level = player->GetLevel();

    // Health
    MemberStats.CurrentHealth = player->GetHealth();
    MemberStats.MaxHealth = player->GetMaxHealth();

    // Power
    MemberStats.PowerType = player->GetPowerType();
    MemberStats.PowerDisplayID = 0;
    MemberStats.CurrentPower = player->GetPower(player->GetPowerType());
    MemberStats.MaxPower = player->GetMaxPower(player->GetPowerType());

    // Position
    MemberStats.ZoneID = player->GetZoneId();
    MemberStats.PositionX = int16(player->GetPositionX());
    MemberStats.PositionY = int16(player->GetPositionY());
    MemberStats.PositionZ = int16(player->GetPositionZ());

    MemberStats.SpecID = AsUnderlyingType(player->GetPrimarySpecialization());
    MemberStats.PartyType[0] = player->m_playerData->PartyType[0];
    MemberStats.PartyType[1] = player->m_playerData->PartyType[1];

    if (WmoLocation const* wmoLocation = player->GetCurrentWmo())
    {
        MemberStats.WmoGroupID = wmoLocation->GroupId;
        MemberStats.WmoDoodadPlacementID = wmoLocation->UniqueId;
    }

    // Vehicle
    if (::Vehicle const* vehicle = player->GetVehicle())
        if (VehicleSeatEntry const* vehicleSeat = vehicle->GetSeatForPassenger(player))
            MemberStats.VehicleSeat = vehicleSeat->ID;

    // Auras
    for (AuraApplication const* aurApp : player->GetVisibleAuras())
    {
        WorldPackets::Party::PartyMemberAuraStates aura;

        aura.SpellID = aurApp->GetBase()->GetId();
        aura.ActiveFlags = aurApp->GetEffectMask();
        aura.Flags = aurApp->GetFlags();

        if (aurApp->GetFlags() & AFLAG_SCALABLE)
        {
            for (AuraEffect const* aurEff : aurApp->GetBase()->GetAuraEffects())
            {
                if (!aurEff)
                    continue;

                if (aurApp->HasEffect(aurEff->GetEffIndex()))
                    aura.Points.push_back(float(aurEff->GetAmount()));
            }
        }

        MemberStats.Auras.push_back(aura);
    }

    // Phases
    PhasingHandler::FillPartyMemberPhase(&MemberStats.Phases, player->GetPhaseShift());

    // Pet
    if (player->GetPet())
    {
        ::Pet* pet = player->GetPet();

        MemberStats.PetStats.emplace();

        MemberStats.PetStats->GUID = pet->GetGUID();
        MemberStats.PetStats->Name = pet->GetName();
        MemberStats.PetStats->ModelId = pet->GetDisplayId();

        MemberStats.PetStats->CurrentHealth = pet->GetHealth();
        MemberStats.PetStats->MaxHealth = pet->GetMaxHealth();

        for (AuraApplication const* aurApp : pet->GetVisibleAuras())
        {
            WorldPackets::Party::PartyMemberAuraStates aura;

            aura.SpellID = aurApp->GetBase()->GetId();
            aura.ActiveFlags = aurApp->GetEffectMask();
            aura.Flags = aurApp->GetFlags();

            if (aurApp->GetFlags() & AFLAG_SCALABLE)
            {
                for (AuraEffect const* aurEff : aurApp->GetBase()->GetAuraEffects())
                {
                    if (!aurEff)
                        continue;

                    if (aurApp->HasEffect(aurEff->GetEffIndex()))
                        aura.Points.push_back(float(aurEff->GetAmount()));
                }
            }

            MemberStats.PetStats->Auras.push_back(aura);
        }
    }
}

WorldPacket const* WorldPackets::Party::PartyKillLog::Write()
{
    _worldPacket << Player;
    _worldPacket << Victim;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Party::BroadcastSummonCast::Write()
{
    _worldPacket << Target;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Party::BroadcastSummonResponse::Write()
{
    _worldPacket << Target;
    _worldPacket.WriteBit(Accepted);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Party::SetRestrictPingsToAssistants::Read()
{
    _worldPacket >> OptionalInit(PartyIndex);
    _worldPacket >> Bits<1>(RestrictPingsToAssistants);
    if (PartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

void WorldPackets::Party::SendPingUnit::Read()
{
    _worldPacket >> SenderGUID;
    _worldPacket >> TargetGUID;
    Type = _worldPacket.read<PingSubjectType, uint8>();
    _worldPacket >> PinFrameID;
}

WorldPacket const* WorldPackets::Party::ReceivePingUnit::Write()
{
    _worldPacket << SenderGUID;
    _worldPacket << TargetGUID;
    _worldPacket << uint8(Type);
    _worldPacket << uint32(PinFrameID);

    return &_worldPacket;
}

void WorldPackets::Party::SendPingWorldPoint::Read()
{
    _worldPacket >> SenderGUID;
    _worldPacket >> MapID;
    _worldPacket >> Point;
    _worldPacket >> As<uint8>(Type);
    _worldPacket >> PinFrameID;
}

WorldPacket const* WorldPackets::Party::ReceivePingWorldPoint::Write()
{
    _worldPacket << SenderGUID;
    _worldPacket << MapID;
    _worldPacket << Point;
    _worldPacket << uint8(Type);
    _worldPacket << PinFrameID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Party::CancelPingPin::Write()
{
    _worldPacket << SenderGUID;
    _worldPacket << PinFrameID;

    return &_worldPacket;
}
