/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Common.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Opcodes.h"
#include "Player.h"
#include "Pet.h"
#include "UpdateMask.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "TalentPackets.h"

void WorldSession::HandleLearnTalentOpcode(WorldPackets::Talent::LearnTalent& packet)
{
    bool anythingLearned = false;
    for (uint32 talentId : packet.Talents)
    {
        if (_player->LearnTalent(talentId))
            anythingLearned = true;
    }

    if (anythingLearned)
        _player->SendTalentsInfoData();
}

void WorldSession::HandleConfirmRespecWipeOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "MSG_TALENT_WIPE_CONFIRM");
    ObjectGuid guid;
    recvData >> guid;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_TRAINER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleConfirmRespecWipeOpcode - %s not found or you can't interact with him.", guid.ToString().c_str());
        return;
    }

    if (!unit->isCanTrainingAndResetTalentsOf(_player))
        return;

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if (!_player->ResetTalents())
    {
        GetPlayer()->SendRespecWipeConfirm(ObjectGuid::Empty, 0);
        return;
    }

    _player->SendTalentsInfoData();
    unit->CastSpell(_player, 14867, true);                  //spell: "Untalent Visual Effect"
}

void WorldSession::HandleUnlearnSkillOpcode(WorldPacket& recvData)
{
    uint32 skillId;
    recvData >> skillId;

    SkillRaceClassInfoEntry const* rcEntry = GetSkillRaceClassInfo(skillId, GetPlayer()->getRace(), GetPlayer()->getClass());
    if (!rcEntry || !(rcEntry->Flags & SKILL_FLAG_UNLEARNABLE))
        return;

    GetPlayer()->SetSkill(skillId, 0, 0, 0);
}

void WorldSession::HandleSetSpecializationOpcode(WorldPackets::Talent::SetSpecialization& packet)
{
    Player* player = GetPlayer();

    if (packet.SpecGroupIndex >= MAX_SPECIALIZATIONS)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleSetSpecializationOpcode - specialization index %u out of range", packet.SpecGroupIndex);
        return;
    }

    ChrSpecializationEntry const* chrSpec = sChrSpecializationByIndexStore[player->getClass()][packet.SpecGroupIndex];

    if (!chrSpec)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleSetSpecializationOpcode - specialization index %u not found", packet.SpecGroupIndex);
        return;
    }

    if (chrSpec->ClassID != player->getClass())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleSetSpecializationOpcode - specialization %u does not belong to class %u", chrSpec->ID, player->getClass());
        return;
    }

    if (player->getLevel() < MIN_SPECIALIZATION_LEVEL)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleSetSpecializationOpcode - player level too low for specializations");
        return;
    }

    player->LearnTalentSpecialization(chrSpec->ID);
}
