#include "WorldSession.h"
#include "PetBattlePackets.h"
#include "PetBattle.h"
#include "BattlePetMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Creature.h"
#include "Log.h"

using namespace WorldPackets::PetBattle;

void WorldSession::HandlePetBattleRequestWild(WorldPackets::PetBattle::PetBattleRequestWild& packet)
{
    Player* player = GetPlayer();

    TC_LOG_INFO("server.worldserver",
        "PET_BATTLE: Player '{}' clicked wild pet (GUID: {}). Initiating battle...",
        player->GetName(), packet.TargetGUID.ToString());

    // Locate the wild creature
    Creature* wildPet = ObjectAccessor::GetCreature(*player, packet.TargetGUID);
    if (!wildPet)
    {
        TC_LOG_WARN("server.worldserver",
            "PET_BATTLE: Wild pet GUID {} not found near player.", packet.TargetGUID.ToString());
        PetBattleRequestFailed failed;
        failed.Reason = 1;
        // The opcode is intentionally marked unhandled in the normal send
        // table, so this error reply must bypass that filter.
        SendPacket(failed.Write(), true);
        return;
    }

    bool hasLivingBattlePet = false;
    for (WorldPackets::BattlePet::BattlePetSlot const& slot : GetBattlePetMgr()->GetSlots())
    {
        if (slot.Locked || slot.Pet.Guid.IsEmpty())
            continue;

        if (BattlePets::BattlePet const* pet = GetBattlePetMgr()->GetPet(slot.Pet.Guid))
            if (pet->PacketInfo.Health > 0)
            {
                hasLivingBattlePet = true;
                break;
            }
    }

    if (!hasLivingBattlePet)
    {
        TC_LOG_WARN("server.worldserver", "PET_BATTLE: Player '{}' has no living pet in a battle slot.", player->GetName());
        PetBattleRequestFailed failed;
        failed.Reason = 1;
        SendPacket(failed.Write(), true);
        return;
    }

    // Start the wild battle session using the location received from the client
    sPetBattleMgr->StartWildBattle(player, wildPet, packet.Location);
}

void WorldSession::HandlePetBattleInput(WorldPackets::PetBattle::PetBattleInput& packet)
{
    sPetBattleMgr->HandleInput(GetPlayer(), packet);
}

void WorldSession::HandlePetBattleReplaceFrontPet(WorldPackets::PetBattle::PetBattleReplaceFrontPet& packet)
{
    sPetBattleMgr->HandleReplaceFrontPet(GetPlayer(), packet);
}

void WorldSession::HandlePetBattleFinalNotify(WorldPackets::PetBattle::PetBattleFinalNotify& /*packet*/)
{
    sPetBattleMgr->HandleFinalNotify(GetPlayer());
}

void WorldSession::HandlePetBattleQuitNotify(WorldPackets::PetBattle::PetBattleQuitNotify& /*packet*/)
{
    sPetBattleMgr->HandleQuitNotify(GetPlayer());
}
