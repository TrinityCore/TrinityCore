/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "Player.h"
#include "Pet.h"
#include "Vehicle.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "ObjectMgr.h"

WorldPacket const* WorldPackets::Party::PartyCommandResult::Write()
{
    _worldPacket.WriteBits(Name.size(), 9);

    _worldPacket.WriteBits(Command, 4);
    _worldPacket.WriteBits(Result, 6);

    _worldPacket << ResultData;
    _worldPacket << ResultGUID;
    _worldPacket.WriteString(Name);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Party::PartyInviteClient::Read()
{
    uint32 targetNameLen, targetRealmLen;

    _worldPacket >> PartyIndex;
    _worldPacket >> ProposedRoles;
    _worldPacket >> TargetGUID;
    _worldPacket >> TargetCfgRealmID;

    targetNameLen = _worldPacket.ReadBits(9);
    targetRealmLen = _worldPacket.ReadBits(9);

    TargetName = _worldPacket.ReadString(targetNameLen);
    TargetRealm = _worldPacket.ReadString(targetRealmLen);
}

WorldPacket const* WorldPackets::Party::PartyInvite::Write()
{
    // Order guessed
    _worldPacket.WriteBit(CanAccept);
    _worldPacket.WriteBit(MightCRZYou);
    _worldPacket.WriteBit(MustBeBNetFriend);
    _worldPacket.WriteBit(AllowMultipleRoles);
    _worldPacket.WriteBit(IsXRealm);

    _worldPacket.WriteBits(InviterName.size(), 6);

    _worldPacket << InviterGUID;
    _worldPacket << InviterBNetAccountId;

    _worldPacket << InviterVirtualRealmAddress;
    _worldPacket << Unk1;

    _worldPacket.WriteBit(IsLocal);
    _worldPacket.WriteBit(Unk2);

    _worldPacket.WriteBits(InviterRealmNameActual.size(), 8);
    _worldPacket.WriteBits(InviterRealmNameNormalized.size(), 8);
    _worldPacket.WriteString(InviterRealmNameActual);
    _worldPacket.WriteString(InviterRealmNameNormalized);

    _worldPacket << ProposedRoles;
    _worldPacket << int32(LfgSlots.size());
    _worldPacket << LfgCompletedMask;

    _worldPacket.WriteString(InviterName);

    for (int32 LfgSlot : LfgSlots)
        _worldPacket << LfgSlot;

    return &_worldPacket;
}

void WorldPackets::Party::PartyInvite::Initialize(Player* const inviter, int32 proposedRoles, bool canAccept)
{
    CanAccept = canAccept;

    InviterName = inviter->GetName();
    InviterGUID = inviter->GetGUID();
    InviterBNetAccountId = inviter->GetSession()->GetAccountGUID();

    ProposedRoles = proposedRoles;

    std::string realmName = sObjectMgr->GetRealmName(realm.Id.Realm);

    InviterVirtualRealmAddress = GetVirtualRealmAddress();
    InviterRealmNameActual = realmName;
    InviterRealmNameNormalized = realmName;
}

void WorldPackets::Party::PartyInviteResponse::Read()
{
    _worldPacket >> PartyIndex;

    Accept = _worldPacket.ReadBit();

    bool hasRolesDesired = _worldPacket.ReadBit();
    if (hasRolesDesired)
    {
        RolesDesired = boost::in_place();
        _worldPacket >> *RolesDesired;
    }
}

void WorldPackets::Party::PartyUninvite::Read()
{
    _worldPacket >> PartyIndex;
    _worldPacket >> TargetGUID;

    uint8 reasonLen = _worldPacket.ReadBits(8);
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
    _worldPacket >> PartyIndex;
    _worldPacket >> TargetGUID;
}

WorldPacket const* WorldPackets::Party::PartyMemberStats::Write()
{
    _worldPacket.WriteBit(ForEnemy);

    _worldPacket << MemberStats;

    return &_worldPacket;
}

void WorldPackets::Party::SetPartyLeader::Read()
{
    _worldPacket >> PartyIndex;
    _worldPacket >> TargetGUID;
}

void WorldPackets::Party::SetRole::Read()
{
    _worldPacket >> PartyIndex;
    _worldPacket >> TargetGUID;
    _worldPacket >> Role;
}

WorldPacket const* WorldPackets::Party::RoleChangedInform::Write()
{
    _worldPacket << PartyIndex;
    _worldPacket << From;
    _worldPacket << ChangedUnit;
    _worldPacket << OldRole;
    _worldPacket << NewRole;

    return &_worldPacket;
}

void WorldPackets::Party::LeaveGroup::Read()
{
    _worldPacket >> PartyIndex;
}

void WorldPackets::Party::SetLootMethod::Read()
{
    _worldPacket >> PartyIndex;
    _worldPacket >> LootMethod;
    _worldPacket >> LootMasterGUID;
    _worldPacket >> LootThreshold;
}

void WorldPackets::Party::MinimapPingClient::Read()
{
    _worldPacket >> PositionX;
    _worldPacket >> PositionY;
    _worldPacket >> PartyIndex;
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
    _worldPacket >> PartyIndex;
    _worldPacket >> Target;
    _worldPacket >> Symbol;
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
    _worldPacket << PartyIndex;

    _worldPacket << int32(TargetIcons.size());

    std::map<uint8, ObjectGuid>::const_iterator itr;
    for (itr = TargetIcons.begin(); itr != TargetIcons.end(); itr++)
    {
        _worldPacket << itr->second;
        _worldPacket << itr->first;
    }

    return &_worldPacket;
}

void WorldPackets::Party::ConvertRaid::Read()
{
    Raid = _worldPacket.ReadBit();
}

void WorldPackets::Party::RequestPartyJoinUpdates::Read()
{
    _worldPacket >> PartyIndex;
}

void WorldPackets::Party::SetAssistantLeader::Read()
{
    _worldPacket >> PartyIndex;
    _worldPacket >> Target;
    Apply = _worldPacket.ReadBit();
}

void WorldPackets::Party::DoReadyCheck::Read()
{
    _worldPacket >> PartyIndex;
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
    _worldPacket >> PartyIndex;
    IsReady = _worldPacket.ReadBit();
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
    _worldPacket >> PartyIndex;
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
    _worldPacket.WriteBits(Name.size(), 6);
    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Party::PartyUpdate::Write()
{
    _worldPacket << PartyType;
    _worldPacket << PartyIndex;
    _worldPacket << PartyFlags;

    _worldPacket << MyIndex;
    _worldPacket << PartyGUID;
    _worldPacket << SequenceNum;
    _worldPacket << LeaderGUID;

    _worldPacket << PlayerList;

    _worldPacket.WriteBit(LfgInfos.is_initialized());
    _worldPacket.WriteBit(LootSettings.is_initialized());
    _worldPacket.WriteBit(DifficultySettings.is_initialized());

    _worldPacket.FlushBits();

    if (LfgInfos.is_initialized())
        _worldPacket << *LfgInfos;

    if (LootSettings.is_initialized())
        _worldPacket << *LootSettings;

    if (DifficultySettings.is_initialized())
        _worldPacket << *DifficultySettings;

    return &_worldPacket;
}

void WorldPackets::Party::SetEveryoneIsAssistant::Read()
{
    _worldPacket >> PartyIndex;
    EveryoneIsAssistant = _worldPacket.ReadBit();
}

void WorldPackets::Party::ChangeSubGroup::Read()
{
    _worldPacket >> TargetGUID;
    _worldPacket >> PartyIndex;
    _worldPacket >> NewSubGroup;
}

void WorldPackets::Party::SwapSubGroups::Read()
{
    _worldPacket >> PartyIndex;
    _worldPacket >> FirstTarget;
    _worldPacket >> SecondTarget;
}

void WorldPackets::Party::ClearRaidMarker::Read()
{
    _worldPacket >> MarkerId;
}

WorldPacket const* WorldPackets::Party::RaidMarkersChanged::Write()
{
    _worldPacket << PartyIndex;
    _worldPacket << ActiveMarkers;

    _worldPacket.WriteBits(RaidMarkers.size(), 4);
    _worldPacket.FlushBits();

    for (RaidMarker* raidMarker : RaidMarkers)
    {
        _worldPacket << raidMarker->TransportGUID;
        _worldPacket << raidMarker->Location.GetMapId();
        _worldPacket << raidMarker->Location.PositionXYZStream();
    }

    return &_worldPacket;
}

void WorldPackets::Party::PartyMemberStats::Initialize(Player const* player)
{
    ForEnemy = false;

    MemberStats.GUID = player->GetGUID();

    // Status
    MemberStats.Status = MEMBER_STATUS_ONLINE;

    if (player->IsPvP())
        MemberStats.Status |= MEMBER_STATUS_PVP;

    if (!player->IsAlive())
    {
        if (player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
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

    // Level
    MemberStats.Level = player->getLevel();

    // Health
    MemberStats.CurrentHealth = player->GetHealth();
    MemberStats.MaxHealth = player->GetMaxHealth();

    // Power
    MemberStats.PowerType = player->getPowerType();
    MemberStats.CurrentPower = player->GetPower(player->getPowerType());
    MemberStats.MaxPower = player->GetMaxPower(player->getPowerType());

    // Position
    MemberStats.ZoneID = player->GetZoneId();
    MemberStats.PositionX = int16(player->GetPositionX());
    MemberStats.PositionY = int16(player->GetPositionY());
    MemberStats.PositionZ = int16(player->GetPositionZ());

    // Unk
    MemberStats.Unk322 = 0;             // Always 0
    MemberStats.Unk704[0] = 1;          // Always 1
    MemberStats.Unk704[1] = 0;          // Always 0
    MemberStats.Unk200000 = 0;          // Always 0

    MemberStats.Unk2000000 = 0;
    MemberStats.Unk4000000 = 0;

    // Vehicle
    if (player->GetVehicle() && player->GetVehicle()->GetVehicleInfo())
        MemberStats.VehicleSeat = player->GetVehicle()->GetVehicleInfo()->SeatID[player->m_movementInfo.transport.seat];

    // Auras
    for (uint8 i = 0; i < MAX_AURAS; ++i)
    {
        if (AuraApplication const* aurApp = player->GetVisibleAura(i))
        {
            WorldPackets::Party::GroupAura aura;

            aura.SpellId = aurApp->GetBase()->GetId();
            aura.EffectMask = aurApp->GetEffectMask();
            aura.Scalings = aurApp->GetFlags(); // ??

            if (aurApp->GetFlags() & AFLAG_SCALABLE)
            {
                for (uint32 e = 0; e < MAX_SPELL_EFFECTS; ++e)
                {
                    float scale = 0.0f;
                    if (AuraEffect const* eff = aurApp->GetBase()->GetEffect(e))
                        scale = float(eff->GetAmount());
                    aura.EffectScales.push_back(scale);
                }
            }

            MemberStats.AuraList.push_back(aura);
        }
    }

    // Phases
    std::set<uint32> const& phases = player->GetPhases();
    MemberStats.Phases.PhaseShiftFlags = 0x08 | (phases.size() ? 0x10 : 0);
    MemberStats.Phases.PersonalGUID = ObjectGuid::Empty;
    for (uint32 phaseId : phases)
    {
        WorldPackets::Party::GroupPhase phase;
        phase.Id = phaseId;
        phase.Flags = 1;
        MemberStats.Phases.List.push_back(phase);
    }

    // Pet
    if (player->GetPet())
    {
        Pet* pet = player->GetPet();

        MemberStats.PetStats = boost::in_place();

        MemberStats.PetStats->GUID = pet->GetGUID();
        MemberStats.PetStats->Name = pet->GetName();
        MemberStats.PetStats->ModelId = pet->GetDisplayId();

        MemberStats.PetStats->CurrentHealth = pet->GetHealth();
        MemberStats.PetStats->MaxHealth = pet->GetMaxHealth();

        for (uint8 i = 0; i < MAX_AURAS; ++i)
        {
            if (AuraApplication const* aurApp = pet->GetVisibleAura(i))
            {
                WorldPackets::Party::GroupAura aura;

                aura.SpellId = aurApp->GetBase()->GetId();
                aura.EffectMask = aurApp->GetEffectMask();
                aura.Scalings = aurApp->GetFlags(); // ??

                if (aurApp->GetFlags() & AFLAG_SCALABLE)
                {
                    for (uint32 e = 0; e < MAX_SPELL_EFFECTS; ++e)
                    {
                        float scale = 0.0f;
                        if (AuraEffect const* eff = aurApp->GetBase()->GetEffect(e))
                            scale = float(eff->GetAmount());
                        aura.EffectScales.push_back(scale);
                    }
                }

                MemberStats.PetStats->AuraList.push_back(aura);
            }
        }
    }
}

WorldPacket const* WorldPackets::Party::PartyKillLog::Write()
{
    _worldPacket << Player;
    _worldPacket << Victim;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::GroupPhase const& phase)
{
    data << phase.Flags;
    data << phase.Id;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::GroupPhases const& phases)
{
    data << phases.PhaseShiftFlags;
    data << int32(phases.List.size());
    data << phases.PersonalGUID;

    for (WorldPackets::Party::GroupPhase const& phase : phases.List)
        data << phase;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::GroupAura const& aura)
{
    data << aura.SpellId;
    data << aura.Scalings;
    data << aura.EffectMask;

    data << int32(aura.EffectScales.size());
    for (float scale : aura.EffectScales)
        data << scale;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, std::vector<WorldPackets::Party::GroupAura> const& auraList)
{
    data << int32(auraList.size());
    for (WorldPackets::Party::GroupAura const& aura : auraList)
        data << aura;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::GroupPetStats const& petStats)
{
    data << petStats.GUID;

    data << petStats.ModelId;

    data << petStats.CurrentHealth;
    data << petStats.MaxHealth;

    data << petStats.AuraList;

    data.WriteBits(petStats.Name.size(), 8);
    data.FlushBits();
    data.WriteString(petStats.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::GroupMemberStats const& memberStats)
{
    data << memberStats.GUID;

    for (uint8 i = 0; i < 2; i++)
        data << memberStats.Unk704[i];

    data << memberStats.Status;

    data << memberStats.PowerType;

    data << memberStats.Unk322;

    data << memberStats.CurrentHealth;
    data << memberStats.MaxHealth;

    data << memberStats.CurrentPower;
    data << memberStats.MaxPower;

    data << memberStats.Level;

    data << memberStats.Unk200000;

    data << memberStats.ZoneID;

    data << memberStats.Unk2000000;
    data << memberStats.Unk4000000;

    data << memberStats.PositionX;
    data << memberStats.PositionY;
    data << memberStats.PositionZ;

    data << memberStats.VehicleSeat;

    data << int32(memberStats.AuraList.size());

    data << memberStats.Phases;

    for (WorldPackets::Party::GroupAura const& aura : memberStats.AuraList)
        data << aura;

    data.WriteBit(memberStats.PetStats.is_initialized());
    data.FlushBits();

    if (memberStats.PetStats.is_initialized())
        data << *memberStats.PetStats;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, std::vector<WorldPackets::Party::GroupPlayerInfos> const& playerList)
{
    data << int32(playerList.size());

    for (WorldPackets::Party::GroupPlayerInfos const& playerInfos : playerList)
        data << playerInfos;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::GroupPlayerInfos const& playerInfos)
{
    data.WriteBits(playerInfos.Name.size(), 6);
    data.FlushBits();

    data << playerInfos.GUID;
    data << playerInfos.Status;
    data << playerInfos.Subgroup;
    data << playerInfos.Flags;
    data << playerInfos.RolesAssigned;
    data << playerInfos.Class;

    data.WriteString(playerInfos.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::GroupLfgInfos const& lfgInfos)
{
    data << lfgInfos.MyFlags;
    data << lfgInfos.Slot;
    data << lfgInfos.MyRandomSlot;
    data << lfgInfos.MyPartialClear;
    data << lfgInfos.MyGearDiff;
    data << lfgInfos.MyStrangerCount;
    data << lfgInfos.MyKickVoteCount;
    data << lfgInfos.BootCount;

    data.WriteBit(lfgInfos.Aborted);
    data.WriteBit(lfgInfos.MyFirstReward);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::GroupLootSettings const& lootSettings)
{
    data << lootSettings.Method;
    data << lootSettings.LootMaster;
    data << lootSettings.Threshold;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::GroupDifficultySettings const& difficultySettings)
{
    data << difficultySettings.DungeonDifficultyID;
    data << difficultySettings.RaidDifficultyID;
    data << difficultySettings.LegacyRaidDifficultyID;

    return data;
}
