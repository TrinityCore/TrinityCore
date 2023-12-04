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
#include "DB2Stores.h"
#include "GossipDef.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Pet.h"
#include "Player.h"
#include "SpellPackets.h"
#include "TalentPackets.h"

void WorldSession::HandleLearnTalentOpcode(WorldPackets::Talent::LearnTalent& packet)
{
    if (_player->LearnTalent(packet.TalentID, packet.RequestedRank))
        _player->SendTalentsInfoData();
}

void WorldSession::HandleLearnPreviewTalentsOpcode(WorldPackets::Talent::LearnPreviewTalents& packet)
{
    for (WorldPackets::Talent::TalentInfo const& talent : packet.Talents)
        _player->LearnTalent(talent.TalentID, talent.Rank);

    _player->SendTalentsInfoData();
}

void WorldSession::HandleConfirmRespecWipeOpcode(WorldPackets::Talent::ConfirmRespecWipe& confirmRespecWipe)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(confirmRespecWipe.RespecMaster, UNIT_NPC_FLAG_TRAINER, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleConfirmRespecWipeOpcode - {} not found or you can't interact with him.", confirmRespecWipe.RespecMaster.ToString());
        return;
    }

    if (confirmRespecWipe.RespecType != SPEC_RESET_TALENTS)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleConfirmRespecWipeOpcode - reset type {} is not implemented.", confirmRespecWipe.RespecType);
        return;
    }

    if (!unit->CanResetTalents(_player))
        return;

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if (!_player->ResetTalents())
        return;

    _player->SendTalentsInfoData();
    unit->CastSpell(_player, 14867, true);                  //spell: "Untalent Visual Effect"
}

void WorldSession::HandleUnlearnSkillOpcode(WorldPackets::Spells::UnlearnSkill& packet)
{
    SkillRaceClassInfoEntry const* rcEntry = sDB2Manager.GetSkillRaceClassInfo(packet.SkillLine, GetPlayer()->GetRace(), GetPlayer()->GetClass());
    if (!rcEntry || !(rcEntry->Flags & SKILL_FLAG_UNLEARNABLE))
        return;

    GetPlayer()->SetSkill(packet.SkillLine, 0, 0, 0);
}

void WorldSession::HandleTradeSkillSetFavorite(WorldPackets::Spells::TradeSkillSetFavorite const& tradeSkillSetFavorite)
{
    if (!_player->HasSpell(tradeSkillSetFavorite.RecipeID))
        return;

    _player->SetSpellFavorite(tradeSkillSetFavorite.RecipeID, tradeSkillSetFavorite.IsFavorite);
}

void WorldSession::HandleRemoveGlyphOpcode(WorldPackets::Talent::RemoveGlyph& packet)
{
    if (packet.GlyphSlot >= MAX_GLYPH_SLOT_INDEX)
    {
        TC_LOG_DEBUG("network", "Client sent wrong glyph slot number in opcode CMSG_REMOVE_GLYPH {}", packet.GlyphSlot);
        return;
    }

    if (uint32 glyph = _player->GetGlyph(packet.GlyphSlot))
    {
        if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyph))
        {
            _player->RemoveAurasDueToSpell(gp->SpellID);
            _player->SetGlyph(packet.GlyphSlot, 0);
            _player->SendTalentsInfoData();
        }
    }
}
