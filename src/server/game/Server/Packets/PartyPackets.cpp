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
#include "Group.h"
#include "Pet.h"
#include "Player.h"
#include "PhasingHandler.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"

void WorldPackets::Party::PartyMemberState::Initialize(Player const* player)
{
    MemberGuid = player->GetGUID();

    // Update Flags
    if (GetOpcode() == SMSG_PARTY_MEMBER_FULL_STATE)
    {
        ChangeMask = GROUP_UPDATE_FLAG_STATUS | GROUP_UPDATE_FLAG_CUR_HP | GROUP_UPDATE_FLAG_MAX_HP
            | GROUP_UPDATE_FLAG_CUR_POWER | GROUP_UPDATE_FLAG_MAX_POWER | GROUP_UPDATE_FLAG_LEVEL
            | GROUP_UPDATE_FLAG_ZONE | GROUP_UPDATE_FLAG_WMO_GROUP_ID | GROUP_UPDATE_FLAG_POSITION | GROUP_UPDATE_FLAG_AURAS
            | GROUP_UPDATE_FLAG_PET_AURAS | GROUP_UPDATE_FLAG_PHASE | GROUP_UPDATE_FLAG_UNK400000 | GROUP_UPDATE_FLAG_UNK800000
            | GROUP_UPDATE_FLAG_UNK1000000 | GROUP_UPDATE_FLAG_UNK2000000 | GROUP_UPDATE_FLAG_UNK4000000 | GROUP_UPDATE_FLAG_UNK8000000
            | GROUP_UPDATE_FLAG_UNK10000000 | GROUP_UPDATE_FLAG_UNK20000000 | GROUP_UPDATE_FLAG_UNK40000000;

        // Additional update flags depending on the player's state
        if (player->GetPowerType() != POWER_MANA)
            ChangeMask |= GROUP_UPDATE_FLAG_POWER_TYPE;

        if (player->GetPet())
            ChangeMask |= GROUP_UPDATE_FLAG_PET_GUID | GROUP_UPDATE_FLAG_PET_NAME | GROUP_UPDATE_FLAG_PET_MODEL_ID
            | GROUP_UPDATE_FLAG_PET_CUR_HP | GROUP_UPDATE_FLAG_PET_MAX_HP | GROUP_UPDATE_FLAG_PET_POWER_TYPE | GROUP_UPDATE_FLAG_PET_CUR_POWER
            | GROUP_UPDATE_FLAG_PET_MAX_POWER;

        if (player->GetVehicle())
            ChangeMask |= GROUP_UPDATE_FLAG_VEHICLE_SEAT;
    }
    else
    {
        ChangeMask = player->GetGroupUpdateFlag();

        // Additional update flags based on the current group update flags
        if (ChangeMask & GROUP_UPDATE_FLAG_POWER_TYPE)
            ChangeMask |= (GROUP_UPDATE_FLAG_CUR_POWER | GROUP_UPDATE_FLAG_MAX_POWER);

        if (ChangeMask & GROUP_UPDATE_FLAG_PET_POWER_TYPE)
            ChangeMask |= (GROUP_UPDATE_FLAG_PET_CUR_POWER | GROUP_UPDATE_FLAG_PET_MAX_POWER);
    }

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
    MemberStats.PowerType = player->GetPowerType();
    MemberStats.CurrentPower = player->GetPower(player->GetPowerType());
    MemberStats.MaxPower = player->GetMaxPower(player->GetPowerType());

    // Position
    MemberStats.ZoneID = player->GetZoneId();
    MemberStats.PositionX = int16(player->GetPositionX());
    MemberStats.PositionY = int16(player->GetPositionY());
    MemberStats.PositionZ = int16(player->GetPositionZ());
    MemberStats.WmoGroupID = uint16(player->GetWMOGroupId());

    // Vehicle
    if (player->GetVehicle() && player->GetVehicle()->GetVehicleInfo())
        MemberStats.VehicleSeat = player->GetVehicle()->GetVehicleInfo()->SeatID[player->m_movementInfo.transport.seat];

    // Auras
    MemberStats.AuraMask = player->GetAuraUpdateMaskForRaid();
    MemberStats.AuraCount = player->GetAppliedAuras().size();
    for (uint8 i = 0; i < MAX_AURAS; ++i)
    {
        if (!(MemberStats.AuraMask & (uint64(1) << i)))
            continue;

        WorldPackets::Party::PartyMemberAuraStates aura;

        if (AuraApplication const* aurApp = player->GetVisibleAura(i))
        {
            aura.SpellID = aurApp->GetBase()->GetId();
            aura.Flags = aurApp->GetFlags();

            if (aurApp->GetFlags() & AFLAG_ANY_EFFECT_AMOUNT_SENT)
            {
                for (uint32 j = 0; j < MAX_SPELL_EFFECTS; ++j)
                {
                    if (AuraEffect const* aurEff = aurApp->GetBase()->GetEffect(j))
                        aura.Points.push_back(aurEff->GetAmount());
                    else
                        aura.Points.push_back(0);
                }
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
        MemberStats.PetStats->PowerType = pet->GetPowerType();
        MemberStats.PetStats->CurrentPower = pet->GetPower(pet->GetPowerType());
        MemberStats.PetStats->MaxPower = pet->GetMaxPower(pet->GetPowerType());

        // Auras
        MemberStats.PetStats->AuraMask = pet->GetAuraUpdateMaskForRaid();
        for (uint8 i = 0; i < MAX_AURAS; ++i)
        {
            if (!(MemberStats.PetStats->AuraMask & (uint64(1) << i)))
                continue;

            WorldPackets::Party::PartyMemberAuraStates aura;

            if (AuraApplication const* aurApp = pet->GetVisibleAura(i))
            {
                aura.SpellID = aurApp->GetBase()->GetId();
                aura.Flags = aurApp->GetFlags();

                if (aurApp->GetFlags() & AFLAG_ANY_EFFECT_AMOUNT_SENT)
                {
                    for (uint32 j = 0; j < MAX_SPELL_EFFECTS; ++j)
                    {
                        if (AuraEffect const* aurEff = aurApp->GetBase()->GetEffect(j))
                            aura.Points.push_back(aurEff->GetAmount());
                        else
                            aura.Points.push_back(0);
                    }
                }

            }

            MemberStats.PetStats->Auras.push_back(aura);
        }
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyMemberPhaseStates const& phases)
{
    data << uint32(phases.PhaseShiftFlags);
    data << uint32(phases.List.size());

    for (uint16 phaseId : phases.List)
        data << uint16(phaseId);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Party::PartyMemberAuraStates const& aura)
{
    data << uint32(aura.SpellID);
    data << uint16(aura.Flags);
    for (int32 points : aura.Points)
        data << int32(points);

    return data;
}

WorldPacket const* WorldPackets::Party::PartyMemberState::Write()
{
    if (_worldPacket.GetOpcode() == SMSG_PARTY_MEMBER_FULL_STATE)
        _worldPacket << uint8(ForEnemy);

    _worldPacket << MemberGuid.WriteAsPacked();
    _worldPacket << uint32(ChangeMask);

    if (ChangeMask & GROUP_UPDATE_FLAG_STATUS)
        _worldPacket << uint16(MemberStats.Status);

    if (ChangeMask & GROUP_UPDATE_FLAG_CUR_HP)
        _worldPacket << int32(MemberStats.CurrentHealth);

    if (ChangeMask & GROUP_UPDATE_FLAG_MAX_HP)
        _worldPacket << int32(MemberStats.MaxHealth);

    if (ChangeMask & GROUP_UPDATE_FLAG_POWER_TYPE)
        _worldPacket << uint8(MemberStats.PowerType);

    if (ChangeMask & GROUP_UPDATE_FLAG_CUR_POWER)
        _worldPacket << uint16(MemberStats.CurrentPower);

    if (ChangeMask & GROUP_UPDATE_FLAG_MAX_POWER)
        _worldPacket << uint16(MemberStats.MaxPower);

    if (ChangeMask & GROUP_UPDATE_FLAG_LEVEL)
        _worldPacket << uint16(MemberStats.Level);

    if (ChangeMask & GROUP_UPDATE_FLAG_ZONE)
        _worldPacket << uint16(MemberStats.ZoneID);

    if (ChangeMask & GROUP_UPDATE_FLAG_WMO_GROUP_ID)
        _worldPacket << int16(MemberStats.WmoGroupID);

    if (ChangeMask & GROUP_UPDATE_FLAG_POSITION)
    {
        _worldPacket << int16(MemberStats.PositionX);
        _worldPacket << int16(MemberStats.PositionY);
        _worldPacket << int16(MemberStats.PositionZ);
    }

    if (ChangeMask & GROUP_UPDATE_FLAG_AURAS)
    {
        _worldPacket << uint8(_worldPacket.GetOpcode() == SMSG_PARTY_MEMBER_FULL_STATE);
        _worldPacket << uint64(MemberStats.AuraMask);
        _worldPacket << uint32(MemberStats.Auras.size());
        for (WorldPackets::Party::PartyMemberAuraStates const& aura : MemberStats.Auras)
            _worldPacket << aura;
    }

    if (MemberStats.PetStats.has_value())
    {
        if (ChangeMask & GROUP_UPDATE_FLAG_PET_GUID)
            _worldPacket << MemberStats.PetStats->GUID;

        if (ChangeMask & GROUP_UPDATE_FLAG_PET_NAME)
            _worldPacket << MemberStats.PetStats->Name;

        if (ChangeMask & GROUP_UPDATE_FLAG_PET_MODEL_ID)
            _worldPacket << int16(MemberStats.PetStats->ModelId);

        if (ChangeMask & GROUP_UPDATE_FLAG_PET_CUR_HP)
            _worldPacket << int32(MemberStats.PetStats->CurrentHealth);

        if (ChangeMask & GROUP_UPDATE_FLAG_PET_MAX_HP)
            _worldPacket << int32(MemberStats.PetStats->MaxHealth);

        if (ChangeMask & GROUP_UPDATE_FLAG_PET_POWER_TYPE)
            _worldPacket << uint8(MemberStats.PetStats->PowerType);

        if (ChangeMask & GROUP_UPDATE_FLAG_PET_CUR_POWER)
            _worldPacket << uint16(MemberStats.PetStats->CurrentPower);

        if (ChangeMask & GROUP_UPDATE_FLAG_PET_MAX_POWER)
            _worldPacket << uint16(MemberStats.PetStats->MaxPower);
    }

    // Pet auras may be sent even when no pet is present
    if (ChangeMask & GROUP_UPDATE_FLAG_PET_AURAS)
    {
        _worldPacket << uint8(_worldPacket.GetOpcode() == SMSG_PARTY_MEMBER_FULL_STATE);
        _worldPacket << uint64(MemberStats.PetStats.has_value() ? MemberStats.PetStats->AuraMask : 0);
        _worldPacket << uint32(MemberStats.PetStats.has_value() ? MemberStats.PetStats->Auras.size() : 0);

        if (MemberStats.PetStats.has_value())
            for (WorldPackets::Party::PartyMemberAuraStates const& aura : MemberStats.PetStats->Auras)
                _worldPacket << aura;
    }

    if (ChangeMask & GROUP_UPDATE_FLAG_VEHICLE_SEAT)
        _worldPacket << int32(MemberStats.VehicleSeat);

    if (ChangeMask & GROUP_UPDATE_FLAG_PHASE)
        _worldPacket << MemberStats.Phases;

    return &_worldPacket;
}
