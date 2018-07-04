/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "WorldSession.h"
#include "BattlePetMgr.h"
#include "BattlePetPackets.h"
#include "Player.h"

void WorldSession::HandleBattlePetRequestJournal(WorldPackets::BattlePet::BattlePetRequestJournal& /*battlePetRequestJournal*/)
{
    GetBattlePetMgr()->SendJournal();
}

void WorldSession::HandleBattlePetSetBattleSlot(WorldPackets::BattlePet::BattlePetSetBattleSlot& battlePetSetBattleSlot)
{
    if (BattlePetMgr::BattlePet* pet = GetBattlePetMgr()->GetPet(battlePetSetBattleSlot.PetGuid))
        GetBattlePetMgr()->GetSlot(battlePetSetBattleSlot.Slot)->Pet = pet->PacketInfo;
}

void WorldSession::HandleBattlePetModifyName(WorldPackets::BattlePet::BattlePetModifyName& battlePetModifyName)
{
    if (BattlePetMgr::BattlePet* pet = GetBattlePetMgr()->GetPet(battlePetModifyName.PetGuid))
    {
        pet->PacketInfo.Name = battlePetModifyName.Name;

        if (pet->SaveInfo != BATTLE_PET_NEW)
            pet->SaveInfo = BATTLE_PET_CHANGED;
    }
}

void WorldSession::HandleBattlePetDeletePet(WorldPackets::BattlePet::BattlePetDeletePet& battlePetDeletePet)
{
    GetBattlePetMgr()->RemovePet(battlePetDeletePet.PetGuid);
}

void WorldSession::HandleBattlePetSetFlags(WorldPackets::BattlePet::BattlePetSetFlags& battlePetSetFlags)
{
    if (BattlePetMgr::BattlePet* pet = GetBattlePetMgr()->GetPet(battlePetSetFlags.PetGuid))
    {
        if (battlePetSetFlags.ControlType == FLAGS_CONTROL_TYPE_APPLY)
            pet->PacketInfo.Flags |= battlePetSetFlags.Flags;
        else // FLAGS_CONTROL_TYPE_REMOVE
            pet->PacketInfo.Flags &= ~battlePetSetFlags.Flags;

        if (pet->SaveInfo != BATTLE_PET_NEW)
            pet->SaveInfo = BATTLE_PET_CHANGED;
    }
}

void WorldSession::HandleCageBattlePet(WorldPackets::BattlePet::CageBattlePet& cageBattlePet)
{
    GetBattlePetMgr()->CageBattlePet(cageBattlePet.PetGuid);
}

void WorldSession::HandleBattlePetSummon(WorldPackets::BattlePet::BattlePetSummon& battlePetSummon)
{
    if (_player->GetGuidValue(PLAYER_FIELD_SUMMONED_BATTLE_PET_ID) != battlePetSummon.PetGuid)
        GetBattlePetMgr()->SummonPet(battlePetSummon.PetGuid);
    else
        GetBattlePetMgr()->DismissPet();
}
