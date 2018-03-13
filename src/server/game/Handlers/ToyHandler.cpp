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
#include "DB2Stores.h"
#include "Item.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "ToyPackets.h"

void WorldSession::HandleAddToy(WorldPackets::Toy::AddToy& packet)
{
    if (!packet.Guid)
        return;

    Item* item = _player->GetItemByGuid(packet.Guid);
    if (!item)
    {
        _player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
        return;
    }

    if (!sDB2Manager.IsToyItem(item->GetEntry()))
        return;

    InventoryResult msg = _player->CanUseItem(item);
    if (msg != EQUIP_ERR_OK)
    {
        _player->SendEquipError(msg, item, nullptr);
        return;
    }

    if (_collectionMgr->AddToy(item->GetEntry(), false))
        _player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
}

void WorldSession::HandleUseToy(WorldPackets::Toy::UseToy& packet)
{
    uint32 itemId = packet.Cast.Misc[0];
    ItemTemplate const* item = sObjectMgr->GetItemTemplate(itemId);
    if (!item)
        return;

    if (!_collectionMgr->HasToy(itemId))
        return;

    auto effect = std::find_if(item->Effects.begin(), item->Effects.end(), [&packet](ItemEffectEntry const* effect)
    {
        return packet.Cast.SpellID == effect->SpellID;
    });

    if (effect == item->Effects.end())
        return;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(packet.Cast.SpellID);
    if (!spellInfo)
    {
        TC_LOG_ERROR("network", "HandleUseToy: unknown spell id: %u used by Toy Item entry %u", packet.Cast.SpellID, itemId);
        return;
    }

    if (_player->isPossessing())
        return;

    SpellCastTargets targets(_player, packet.Cast);

    Spell* spell = new Spell(_player, spellInfo, TRIGGERED_NONE, ObjectGuid::Empty, false);

    WorldPackets::Spells::SpellPrepare spellPrepare;
    spellPrepare.ClientCastID = packet.Cast.CastID;
    spellPrepare.ServerCastID = spell->m_castId;
    SendPacket(spellPrepare.Write());

    spell->m_fromClient = true;
    spell->m_castItemEntry = itemId;
    spell->m_misc.Raw.Data[0] = packet.Cast.Misc[0];
    spell->m_misc.Raw.Data[1] = packet.Cast.Misc[1];
    spell->m_castFlagsEx |= CAST_FLAG_EX_USE_TOY_SPELL;
    spell->prepare(&targets);
}
