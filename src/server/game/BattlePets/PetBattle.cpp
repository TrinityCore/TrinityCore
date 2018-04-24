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
#include "BattlePetMgr.h"
#include "Creature.h"
#include "PetBattle.h"
#include "PetBattlePackets.h"
#include "Player.h"

PetBattle::PetBattle(uint64 battleID, Player* player1, Player* player2, ObjectGuid wildBattlePet) :
    m_battleId(battleID), m_currentRound(0), m_player1(player1->GetGUID()), m_player2(player2->GetGUID()), m_wildBattlePet(wildBattlePet)
{
    // Player1 must have at least 1 opponent
    ASSERT(!m_player2.IsEmpty() || !m_wildBattlePet.IsEmpty());

    if (m_player2.IsEmpty())
        m_battleType = PET_BATTLE_PVE;
    else
        m_battleType = PET_BATTLE_PVP;

    trapStatus[0] = PET_BATTLE_TRAP_STATUS_HEALTH_TOO_HIGH;
    trapStatus[1] = PET_BATTLE_TRAP_STATUS_HEALTH_TOO_HIGH;
}

void PetBattle::Start()
{
    if (m_battleType == PET_BATTLE_PVE)
    {
    }
    else
    {
        //TODO
    }
}

void PetBattle::BuildPlayerUpdate(uint8 index, WorldPackets::PetBattle::PetBattlePlayerUpdate& playerUpdate)
{
    // Common
    playerUpdate.TrapStatus = trapStatus[index];

    if (index == 0)
        FillPlayerUpdate(GetPlayer1(), playerUpdate);
    else
    {
        if (m_battleType == PET_BATTLE_PVE)
            FillPlayerUpdate(GetOriginalWildPet(), playerUpdate);
        else
            FillPlayerUpdate(GetPlayer2(), playerUpdate);
    }
}

void PetBattle::FillPlayerUpdate(Player* player, WorldPackets::PetBattle::PetBattlePlayerUpdate& playerUpdate)
{
    BattlePetMgr* battlePetMgr = player->GetSession()->GetBattlePetMgr();

    playerUpdate.PlayerGUID = player->GetGUID();

    playerUpdate.TrapAbilityID = battlePetMgr->GetTrapAbilityId();

    playerUpdate.RoundTimeSecs = 0; // ?

    playerUpdate.FrontPet = 0; // ?
    playerUpdate.InputFlags = 6; // ?

    std::vector<WorldPackets::BattlePet::BattlePetSlot> slots = battlePetMgr->GetSlots();

    for (WorldPackets::BattlePet::BattlePetSlot slot : slots)
    {
        WorldPackets::PetBattle::PetBattlePetUpdate petBattlePetUpdate;
        petBattlePetUpdate.BattlePetGUID    = slot.Pet.Guid;
        petBattlePetUpdate.SpeciesID        = slot.Pet.Species;
        petBattlePetUpdate.Level            = slot.Pet.Level;
        petBattlePetUpdate.Xp               = slot.Pet.Exp;
        petBattlePetUpdate.CurHealth        = slot.Pet.Health;
        petBattlePetUpdate.MaxHealth        = slot.Pet.MaxHealth;
        petBattlePetUpdate.Power            = slot.Pet.Power;
        petBattlePetUpdate.Speed            = slot.Pet.Speed;
        petBattlePetUpdate.BreedQuality     = slot.Pet.Breed;

        petBattlePetUpdate.DisplayID        = slot.Pet.CreatureID; //TODO
        petBattlePetUpdate.NpcTeamMemberID  = 0; //TODO
        petBattlePetUpdate.StatusFlags      = 0; //TODO

        playerUpdate.PetBattlePetUpdates.push_back(petBattlePetUpdate);
    }
}

void PetBattle::FillPlayerUpdate(WildBattlePet* /*wildBattlePet*/, WorldPackets::PetBattle::PetBattlePlayerUpdate& /*playerUpdate*/)
{
}

void PetBattle::End()
{

}

WildBattlePet* PetBattle::GetOriginalWildPet()
{
    if (Player* player1 = GetPlayer1())
        if (Creature* creature = ObjectAccessor::GetCreature(*player1, m_wildBattlePet))
            creature->GetWildBattlePet();

    return nullptr;
}
