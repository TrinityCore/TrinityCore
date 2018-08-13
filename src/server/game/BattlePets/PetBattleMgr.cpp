/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "BattlePet.h"
#include "BattlePetDataStore.h"
#include "ObjectAccessor.h"
#include "PetBattleMgr.h"
#include "WildBattlePet.h"

PetBattleMgr::PetBattleMgr()
{
    m_MaxPetBattleID = 0;
}

void PetBattleMgr::HandleWildRequest(Player* player, PetBattleRequest request)
{
    PetBattleRequestResult result = CanPlayerEnterInPetBattle(player, request);

    if (result != PET_BATTLE_REQUEST_OK)
    {
        SendRequestFailed(player, result);
        return;
    }

    SendFinalizeLocation(player, request);

    // TEMP SOLUTION - NEED REMOVAL
    if (Creature* npc = player->GetNPCIfCanInteractWith(request.opponentGUID, UNIT_NPC_FLAG_WILD_BATTLE_PET))
        DoCapture(player, npc->GetWildBattlePet());
}

PetBattleRequestResult PetBattleMgr::CanPlayerEnterInPetBattle(Player* player, PetBattleRequest& request)
{
    if (!player || !player->IsInWorld())
        return PET_BATTLE_REQUEST_CREATE_FAILED;

    if (player->isDead())
        return PET_BATTLE_REQUEST_NOT_WHILE_DEAD;

    // Player can't be already in battle
    if (player->IsInPetBattle())
        return PET_BATTLE_REQUEST_IN_BATTLE;

    if (request.opponentGUID.IsCreature())
    {
        Creature* creature = player->GetNPCIfCanInteractWith(request.opponentGUID, UNIT_NPC_FLAG_WILD_BATTLE_PET);

        if (!creature)
            return PET_BATTLE_REQUEST_TARGET_INVALID;

        if (creature->IsInPetBattle())
            return PET_BATTLE_REQUEST_WILD_PET_TAPPED;

        if (!player->IsWithinDist3d(creature, INTERACTION_DISTANCE))
            return PET_BATTLE_REQUEST_TARGET_OUT_OF_RANGE;

        if (!player->IsWithinLOSInMap(creature))
            return PET_BATTLE_REQUEST_NOT_HERE_OBSTRUCTED;
    }
    // else if TODO for PVP (opponent is player)
    else
        return PET_BATTLE_REQUEST_TARGET_INVALID;

    // Player can't be in combat
    if (player->IsInCombat())
        return PET_BATTLE_REQUEST_NOT_WHILE_IN_COMBAT;

    // TODO : Check Location

    // Load player pets
    BattlePetMgr* battlePetMgr = player->GetSession()->GetBattlePetMgr();
    uint8 totalPetCount = battlePetMgr->GetPetCount();

    if (!totalPetCount)
        return PET_BATTLE_REQUEST_NO_PETS_IN_SLOT;

    uint8 alivePetCount = battlePetMgr->GetPetCount(true);

    if (!alivePetCount)
        return PET_BATTLE_REQUEST_ALL_PETS_DEAD;

    return PET_BATTLE_REQUEST_OK;
}

void PetBattleMgr::SendRequestFailed(Player* player, PetBattleRequestResult reason)
{
    WorldPackets::PetBattle::RequestFailed requestFailed;
    requestFailed.Reason = (uint8)reason;
    player->GetSession()->SendPacket(requestFailed.Write());
}

void PetBattleMgr::SendFinalizeLocation(Player* player, PetBattleRequest request)
{
    WorldPackets::PetBattle::FinalizeLocation finalizeLocation;
    finalizeLocation.Location = request.Location;
    player->GetSession()->SendPacket(finalizeLocation.Write());
}

void PetBattleMgr::StartPetBattle(Player* /*player*/, PetBattleRequest /*request*/)
{
    /*uint64 petBattleID = ++m_MaxPetBattleID;
    m_petBattles[petBattleID] = new PetBattle(petBattleID);
    m_petBattles[petBattleID]->Start();*/
}

void PetBattleMgr::EndPetBattle(uint64 petBattleId)
{
    auto petBattleItr = m_petBattles.find(petBattleId);
    if (petBattleItr == m_petBattles.end())
        return;

    petBattleItr->second->End();
    delete petBattleItr->second;
    m_petBattles.erase(petBattleId);
}

void PetBattleMgr::DoCapture(Player* player, WildBattlePet* wildBattlePet)
{
    if (!wildBattlePet)
        return;

    BattlePet* battlePet = wildBattlePet->GetBattlePet();

    if (!battlePet || !battlePet->GetSpecies())
        return;

    if (battlePet->GetSpecies()->Flags & BATTLE_PET_SPECIES_FLAG_NOT_CAPTURABLE)
        return;

    player->GetSession()->GetBattlePetMgr()->AddPet(battlePet);
    wildBattlePet->GetCreature()->DisappearAndDie();
}

PetBattleMgr* PetBattleMgr::Instance()
{
    static PetBattleMgr instance;
    return &instance;
}
