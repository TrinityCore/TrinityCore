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

#include "WorldSession.h"
#include "AzeritePackets.h"
#include "DB2Stores.h"
#include "NPCPackets.h"
#include "Player.h"
#include "SpellHistory.h"

void WorldSession::HandleAzeriteEssenceUnlockMilestone(WorldPackets::Azerite::AzeriteEssenceUnlockMilestone& azeriteEssenceUnlockMilestone)
{
}

void WorldSession::HandleAzeriteEssenceActivateEssence(WorldPackets::Azerite::AzeriteEssenceActivateEssence& azeriteEssenceActivateEssence)
{
}

void WorldSession::HandleAzeriteEmpoweredItemViewed(WorldPackets::Azerite::AzeriteEmpoweredItemViewed& azeriteEmpoweredItemViewed)
{
}

void WorldSession::HandleAzeriteEmpoweredItemSelectPower(WorldPackets::Azerite::AzeriteEmpoweredItemSelectPower& azeriteEmpoweredItemSelectPower)
{
}

void WorldSession::SendAzeriteRespecNPC(ObjectGuid npc)
{
    WorldPackets::NPC::NPCInteractionOpenResult npcInteraction;
    npcInteraction.Npc = npc;
    npcInteraction.InteractionType = PlayerInteractionType::AzeriteRespec;
    npcInteraction.Success = true;
    SendPacket(npcInteraction.Write());
}
