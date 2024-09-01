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
#include "Common.h"
#include "DBCStores.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Pet.h"
#include "Player.h"
#include "TalentPackets.h"
#include "WorldPacket.h"

void WorldSession::HandleLearnTalentOpcode(WorldPacket& recvData)
{
    uint32 talent_id, requested_rank;
    recvData >> talent_id >> requested_rank;

    _player->LearnTalent(talent_id, requested_rank);
    _player->SendTalentsInfoData(false);
}

void WorldSession::HandleLearnPreviewTalents(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "CMSG_LEARN_PREVIEW_TALENTS");

    uint32 talentsCount;
    recvPacket >> talentsCount;

    uint32 talentId, talentRank;

    // Client has max 44 talents for tree for 3 trees, rounded up : 150
    uint32 const MaxTalentsCount = 150;

    for (uint32 i = 0; i < talentsCount && i < MaxTalentsCount; ++i)
    {
        recvPacket >> talentId >> talentRank;

        _player->LearnTalent(talentId, talentRank);
    }

    _player->SendTalentsInfoData(false);

    recvPacket.rfinish();
}

void WorldSession::HandleTalentWipeConfirmOpcode(WorldPackets::Talents::ConfirmRespecWipe& confirmRespecWipe)
{
    TC_LOG_DEBUG("network", "MSG_TALENT_WIPE_CONFIRM");

    Creature* trainer = GetPlayer()->GetNPCIfCanInteractWith(confirmRespecWipe.RespecMaster, UNIT_NPC_FLAG_TRAINER);
    if (!trainer)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTalentWipeConfirmOpcode - {} not found or you can't interact with him.", confirmRespecWipe.RespecMaster);
        return;
    }

    if (!trainer->CanResetTalents(_player, false))
        return;

    uint32 cost = _player->ResetTalentsCost();
    if (!_player->HasEnoughMoney(cost))
        return; // // silently return, client should display the error by itself

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if (!_player->ResetTalents())
    {
        _player->SendTalentWipeConfirm(ObjectGuid::Empty);
        return;
    }

    _player->ModifyMoney(-(int32)cost);
    _player->IncreaseResetTalentsCostAndCounters(cost);
    _player->SendTalentsInfoData(false);

    trainer->CastSpell(_player, 14867 /*SPELL_UNTALENT_VISUAL_EFFECT*/, true);
}

void WorldSession::HandleUnlearnSkillOpcode(WorldPacket& recvData)
{
    uint32 skillId;
    recvData >> skillId;

    SkillRaceClassInfoEntry const* rcEntry = GetSkillRaceClassInfo(skillId, GetPlayer()->GetRace(), GetPlayer()->GetClass());
    if (!rcEntry || !(rcEntry->Flags & SKILL_FLAG_UNLEARNABLE))
        return;

    GetPlayer()->SetSkill(skillId, 0, 0, 0);
}
