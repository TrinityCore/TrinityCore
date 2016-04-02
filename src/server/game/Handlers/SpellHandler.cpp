/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "DBCStores.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Spell.h"
#include "Totem.h"
#include "ScriptMgr.h"
#include "GameObjectAI.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "Config.h"

void WorldSession::HandleClientCastFlags(WorldPacket& recvPacket, uint8 castFlags, SpellCastTargets& targets)
{
    // some spell cast packet including more data (for projectiles?)
    if (castFlags & 0x02)
    {
        // not sure about these two
        float elevation, speed;
        recvPacket >> elevation;
        recvPacket >> speed;

        targets.SetElevation(elevation);
        targets.SetSpeed(speed);

        uint8 hasMovementData;
        recvPacket >> hasMovementData;
        if (hasMovementData)
        {
            recvPacket.SetOpcode(recvPacket.read<uint32>());
            HandleMovementOpcodes(recvPacket);
        }
    }
}

void WorldSession::HandleUseItemOpcode(WorldPacket& recvPacket)
{
    /// @todo add targets.read() check
    Player* pUser = _player;

    // ignore for remote control state
    if (pUser->m_mover != pUser)
        return;

    uint8 bagIndex, slot, castFlags;
    uint8 castCount;                                        // next cast if exists (single or not)
    ObjectGuid itemGUID;
    uint32 glyphIndex;                                      // something to do with glyphs?
    uint32 spellId;                                         // cast spell id

    recvPacket >> bagIndex >> slot >> castCount >> spellId >> itemGUID >> glyphIndex >> castFlags;

    if (glyphIndex >= MAX_GLYPH_SLOT_INDEX)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL);
        return;
    }

    Item* pItem = pUser->GetUseableItemByPos(bagIndex, slot);
    if (!pItem)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL);
        return;
    }

    if (pItem->GetGUID() != itemGUID)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL);
        return;
    }

    TC_LOG_DEBUG("network", "WORLD: CMSG_USE_ITEM packet, bagIndex: %u, slot: %u, castCount: %u, spellId: %u, Item: %u, glyphIndex: %u, data length = %i", bagIndex, slot, castCount, spellId, pItem->GetEntry(), glyphIndex, (uint32)recvPacket.size());

    ItemTemplate const* proto = pItem->GetTemplate();
    if (!proto)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, pItem, NULL);
        return;
    }

    // some item classes can be used only in equipped state
    if (proto->InventoryType != INVTYPE_NON_EQUIP && !pItem->IsEquipped())
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, pItem, NULL);
        return;
    }

    InventoryResult msg = pUser->CanUseItem(pItem);
    if (msg != EQUIP_ERR_OK)
    {
        pUser->SendEquipError(msg, pItem, NULL);
        return;
    }

    // only allow conjured consumable, bandage, poisons (all should have the 2^21 item flag set in DB)
    if (proto->Class == ITEM_CLASS_CONSUMABLE && !(proto->Flags & ITEM_PROTO_FLAG_USEABLE_IN_ARENA) && pUser->InArena())
    {
        pUser->SendEquipError(EQUIP_ERR_NOT_DURING_ARENA_MATCH, pItem, NULL);
        return;
    }

    // don't allow items banned in arena
    if (proto->Flags & ITEM_PROTO_FLAG_NOT_USEABLE_IN_ARENA && pUser->InArena())
    {
        pUser->SendEquipError(EQUIP_ERR_NOT_DURING_ARENA_MATCH, pItem, NULL);
        return;
    }

    if (pUser->IsInCombat())
    {
        for (int i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(proto->Spells[i].SpellId))
            {
                if (!spellInfo->CanBeUsedInCombat())
                {
                    pUser->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
                    return;
                }
            }
        }
    }

    // check also  BIND_WHEN_PICKED_UP and BIND_QUEST_ITEM for .additem or .additemset case by GM (not binded at adding to inventory)
    if (pItem->GetTemplate()->Bonding == BIND_WHEN_USE || pItem->GetTemplate()->Bonding == BIND_WHEN_PICKED_UP || pItem->GetTemplate()->Bonding == BIND_QUEST_ITEM)
    {
        if (!pItem->IsSoulBound())
        {
            pItem->SetState(ITEM_CHANGED, pUser);
            pItem->SetBinding(true);
        }
    }

    SpellCastTargets targets;
    targets.Read(recvPacket, pUser);
    HandleClientCastFlags(recvPacket, castFlags, targets);

    // Note: If script stop casting it must send appropriate data to client to prevent stuck item in gray state.
    if (!sScriptMgr->OnItemUse(pUser, pItem, targets))
    {
        // no script or script not process request by self
        pUser->CastItemUseSpell(pItem, targets, castCount, glyphIndex);
    }
}

void WorldSession::HandleOpenItemOpcode(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_OPEN_ITEM packet, data length = %i", (uint32)recvPacket.size());

    Player* pUser = _player;

    // ignore for remote control state
    if (pUser->m_mover != pUser)
        return;

    uint8 bagIndex, slot;

    recvPacket >> bagIndex >> slot;

    TC_LOG_INFO("network", "bagIndex: %u, slot: %u", bagIndex, slot);

    Item* item = pUser->GetItemByPos(bagIndex, slot);
    if (!item)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL);
        return;
    }

    ItemTemplate const* proto = item->GetTemplate();
    if (!proto)
    {
        pUser->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, item, NULL);
        return;
    }

    // Verify that the bag is an actual bag or wrapped item that can be used "normally"
    if (!(proto->Flags & ITEM_PROTO_FLAG_OPENABLE) && !item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FLAG_WRAPPED))
    {
        pUser->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, item, NULL);
        TC_LOG_ERROR("network", "Possible hacking attempt: Player %s [guid: %u] tried to open item [guid: %u, entry: %u] which is not openable!",
                pUser->GetName().c_str(), pUser->GetGUID().GetCounter(), item->GetGUID().GetCounter(), proto->ItemId);
        return;
    }

    // locked item
    uint32 lockId = proto->LockID;
    if (lockId)
    {
        LockEntry const* lockInfo = sLockStore.LookupEntry(lockId);

        if (!lockInfo)
        {
            pUser->SendEquipError(EQUIP_ERR_ITEM_LOCKED, item, NULL);
            TC_LOG_ERROR("network", "WORLD::OpenItem: item [guid = %u] has an unknown lockId: %u!", item->GetGUID().GetCounter(), lockId);
            return;
        }

        // was not unlocked yet
        if (item->IsLocked())
        {
            pUser->SendEquipError(EQUIP_ERR_ITEM_LOCKED, item, NULL);
            return;
        }
    }

    if (item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FLAG_WRAPPED))// wrapped?
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GIFT_BY_ITEM);

        stmt->setUInt32(0, item->GetGUID().GetCounter());

        PreparedQueryResult result = CharacterDatabase.Query(stmt);

        if (result)
        {
            Field* fields = result->Fetch();
            uint32 entry = fields[0].GetUInt32();
            uint32 flags = fields[1].GetUInt32();

            item->SetGuidValue(ITEM_FIELD_GIFTCREATOR, ObjectGuid::Empty);
            item->SetEntry(entry);
            item->SetUInt32Value(ITEM_FIELD_FLAGS, flags);
            item->SetState(ITEM_CHANGED, pUser);
        }
        else
        {
            TC_LOG_ERROR("network", "Wrapped item %u don't have record in character_gifts table and will deleted", item->GetGUID().GetCounter());
            pUser->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
            return;
        }

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GIFT);

        stmt->setUInt32(0, item->GetGUID().GetCounter());

        CharacterDatabase.Execute(stmt);
    }
    else
        pUser->SendLoot(item->GetGUID(), LOOT_CORPSE);
}

void WorldSession::HandleGameObjectUseOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    recvData >> guid;

    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_GAMEOBJ_USE Message [%s]", guid.ToString().c_str());

    if (GameObject* obj = GetPlayer()->GetGameObjectIfCanInteractWith(guid))
    {
        // ignore for remote control state
        if (GetPlayer()->m_mover != GetPlayer())
            if (!(GetPlayer()->IsOnVehicle(GetPlayer()->m_mover) || GetPlayer()->IsMounted()) && !obj->GetGOInfo()->IsUsableMounted())
                return;

        obj->Use(GetPlayer());
    }
}

void WorldSession::HandleGameobjectReportUse(WorldPacket& recvPacket)
{
    ObjectGuid guid;
    recvPacket >> guid;

    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_GAMEOBJ_REPORT_USE Message [%s]", guid.ToString().c_str());

    // ignore for remote control state
    if (_player->m_mover != _player)
        return;

    if (GameObject* go = GetPlayer()->GetGameObjectIfCanInteractWith(guid))
    {
        if (go->AI()->GossipHello(_player))
            return;

        _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT, go->GetEntry());
    }
}

void WorldSession::HandleCastSpellOpcode(WorldPacket& recvPacket)
{
    uint32 spellId;
    uint8  castCount, castFlags;
    recvPacket >> castCount >> spellId >> castFlags;

    TC_LOG_DEBUG("network", "WORLD: got cast spell packet, castCount: %u, spellId: %u, castFlags: %u, data length = %u", castCount, spellId, castFlags, (uint32)recvPacket.size());

    // ignore for remote control state (for player case)
    Unit* mover = _player->m_mover;
    if (mover != _player && mover->GetTypeId() == TYPEID_PLAYER)
    {
        recvPacket.rfinish(); // prevent spam at ignore packet
        return;
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        TC_LOG_ERROR("network", "WORLD: unknown spell id %u", spellId);
        recvPacket.rfinish(); // prevent spam at ignore packet
        return;
    }

    if (spellInfo->IsPassive())
    {
        recvPacket.rfinish(); // prevent spam at ignore packet
        return;
    }

    Unit* caster = mover;
    if (caster->GetTypeId() == TYPEID_UNIT && !caster->ToCreature()->HasSpell(spellId))
    {
        // If the vehicle creature does not have the spell but it allows the passenger to cast own spells
        // change caster to player and let him cast
        if (!_player->IsOnVehicle(caster) || spellInfo->CheckVehicle(_player) != SPELL_CAST_OK)
        {
            recvPacket.rfinish(); // prevent spam at ignore packet
            return;
        }

        caster = _player;
    }

    if (caster->GetTypeId() == TYPEID_PLAYER && !caster->ToPlayer()->HasActiveSpell(spellId))
    {
        // not have spell in spellbook
        recvPacket.rfinish(); // prevent spam at ignore packet
        return;
    }

    // Client is resending autoshot cast opcode when other spell is cast during shoot rotation
    // Skip it to prevent "interrupt" message
    if (spellInfo->IsAutoRepeatRangedSpell() && caster->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL)
        && caster->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL)->m_spellInfo == spellInfo)
    {
        recvPacket.rfinish();
        return;
    }

    // can't use our own spells when we're in possession of another unit,
    if (_player->isPossessing())
    {
        recvPacket.rfinish(); // prevent spam at ignore packet
        return;
    }

    // client provided targets
    SpellCastTargets targets;
    targets.Read(recvPacket, caster);
    HandleClientCastFlags(recvPacket, castFlags, targets);

    // auto-selection buff level base at target level (in spellInfo)
    if (targets.GetUnitTarget())
    {
        SpellInfo const* actualSpellInfo = spellInfo->GetAuraRankForLevel(targets.GetUnitTarget()->getLevel());

        // if rank not found then function return NULL but in explicit cast case original spell can be cast and later failed with appropriate error message
        if (actualSpellInfo)
            spellInfo = actualSpellInfo;
    }

    Spell* spell = new Spell(caster, spellInfo, TRIGGERED_NONE, ObjectGuid::Empty, false);
    spell->m_cast_count = castCount;                       // set count of casts
    spell->prepare(&targets);
}

void WorldSession::HandleCancelCastOpcode(WorldPacket& recvPacket)
{
    uint32 spellId;

    recvPacket.read_skip<uint8>();                          // counter, increments with every CANCEL packet, don't use for now
    recvPacket >> spellId;

    if (_player->IsNonMeleeSpellCast(false))
        _player->InterruptNonMeleeSpells(false, spellId, false);
}

void WorldSession::HandleCancelAuraOpcode(WorldPacket& recvPacket)
{
    uint32 spellId;
    recvPacket >> spellId;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
        return;

    // not allow remove spells with attr SPELL_ATTR0_CANT_CANCEL
    if (spellInfo->HasAttribute(SPELL_ATTR0_CANT_CANCEL))
        return;

    // channeled spell case (it currently cast then)
    if (spellInfo->IsChanneled())
    {
        if (Spell* curSpell = _player->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            if (curSpell->m_spellInfo->Id == spellId)
                _player->InterruptSpell(CURRENT_CHANNELED_SPELL);
        return;
    }

    // non channeled case:
    // don't allow remove non positive spells
    // don't allow cancelling passive auras (some of them are visible)
    if (!spellInfo->IsPositive() || spellInfo->IsPassive())
        return;

    // maybe should only remove one buff when there are multiple?
    _player->RemoveOwnedAura(spellId, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);

    // If spell being removed is a resource tracker, see if player was tracking both (herbs / minerals) and remove the other
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TRACK_BOTH_RESOURCES) && spellInfo->HasAura(SPELL_AURA_TRACK_RESOURCES))
    {
        Unit::AuraEffectList const& auraEffects = _player->GetAuraEffectsByType(SPELL_AURA_TRACK_RESOURCES);
        if (!auraEffects.empty())
        {
            // Build list of spell IDs to cancel. Trying to cancel the aura while iterating
            //  over AuraEffectList caused "incompatible iterator" errors on second pass
            std::list<uint32> spellIDs;

            for (Unit::AuraEffectList::const_iterator auraEffect = auraEffects.begin(); auraEffect != auraEffects.end(); ++auraEffect)
                spellIDs.push_back((*auraEffect)->GetId());

            // Remove all auras related to resource tracking (only Herbs and Minerals in 3.3.5a)
            for (std::list<uint32>::iterator it = spellIDs.begin(); it != spellIDs.end(); ++it)
                _player->RemoveOwnedAura(*it, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
        }
    }
}

void WorldSession::HandlePetCancelAuraOpcode(WorldPacket& recvPacket)
{
    ObjectGuid guid;
    uint32 spellId;

    recvPacket >> guid;
    recvPacket >> spellId;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        TC_LOG_ERROR("network", "WORLD: unknown PET spell id %u", spellId);
        return;
    }

    Creature* pet=ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, guid);

    if (!pet)
    {
        TC_LOG_ERROR("network", "HandlePetCancelAura: Attempt to cancel an aura for non-existant %s by player '%s'", guid.ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    if (pet != GetPlayer()->GetGuardianPet() && pet != GetPlayer()->GetCharm())
    {
        TC_LOG_ERROR("network", "HandlePetCancelAura: %s is not a pet of player '%s'", guid.ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    if (!pet->IsAlive())
    {
        pet->SendPetActionFeedback(FEEDBACK_PET_DEAD);
        return;
    }

    pet->RemoveOwnedAura(spellId, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
}

void WorldSession::HandleCancelGrowthAuraOpcode(WorldPacket& /*recvPacket*/) { }

void WorldSession::HandleCancelAutoRepeatSpellOpcode(WorldPacket& /*recvPacket*/)
{
    // may be better send SMSG_CANCEL_AUTO_REPEAT?
    // cancel and prepare for deleting
    _player->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
}

void WorldSession::HandleCancelChanneling(WorldPacket& recvData)
{
    recvData.read_skip<uint32>();                          // spellid, not used

    // ignore for remote control state (for player case)
    Unit* mover = _player->m_mover;
    if (mover != _player && mover->GetTypeId() == TYPEID_PLAYER)
        return;

    mover->InterruptSpell(CURRENT_CHANNELED_SPELL);
}

void WorldSession::HandleTotemDestroyed(WorldPacket& recvPacket)
{
    // ignore for remote control state
    if (_player->m_mover != _player)
        return;

    uint8 slotId;

    recvPacket >> slotId;

    ++slotId;
    if (slotId >= MAX_TOTEM_SLOT)
        return;

    if (!_player->m_SummonSlot[slotId])
        return;

    Creature* totem = GetPlayer()->GetMap()->GetCreature(_player->m_SummonSlot[slotId]);

    if (totem && totem->IsTotem())
        totem->ToTotem()->UnSummon();
}

void WorldSession::HandleSelfResOpcode(WorldPacket & /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_SELF_RES");                  // empty opcode

    if (_player->HasAuraType(SPELL_AURA_PREVENT_RESURRECTION))
        return; // silent return, client should display error by itself and not send this opcode

    if (_player->GetUInt32Value(PLAYER_SELF_RES_SPELL))
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(_player->GetUInt32Value(PLAYER_SELF_RES_SPELL));
        if (spellInfo)
            _player->CastSpell(_player, spellInfo, false, nullptr);

        _player->SetUInt32Value(PLAYER_SELF_RES_SPELL, 0);
    }
}

void WorldSession::HandleSpellClick(WorldPacket& recvData)
{
    ObjectGuid guid;
    recvData >> guid;

    // this will get something not in world. crash
    Creature* unit = ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, guid);

    if (!unit)
        return;

    /// @todo Unit::SetCharmedBy: 28782 is not in world but 0 is trying to charm it! -> crash
    if (!unit->IsInWorld())
        return;

    unit->HandleSpellClick(_player);
}

void WorldSession::HandleMirrorImageDataRequest(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_GET_MIRRORIMAGE_DATA");
    ObjectGuid guid;
    recvData >> guid;

    // Get unit for which data is needed by client
    Unit* unit = ObjectAccessor::GetUnit(*_player, guid);
    if (!unit)
        return;

    if (!unit->HasAuraType(SPELL_AURA_CLONE_CASTER))
        return;

    // Get creator of the unit (SPELL_AURA_CLONE_CASTER does not stack)
    Unit* creator = unit->GetAuraEffectsByType(SPELL_AURA_CLONE_CASTER).front()->GetCaster();
    if (!creator)
        return;

    WorldPacket data(SMSG_MIRRORIMAGE_DATA, 68);
    data << uint64(guid);
    data << uint32(creator->GetDisplayId());
    data << uint8(creator->getRace());
    data << uint8(creator->getGender());
    data << uint8(creator->getClass());

    if (creator->GetTypeId() == TYPEID_PLAYER)
    {
        Player* player = creator->ToPlayer();
        data << uint8(player->GetByteValue(PLAYER_BYTES, 0));   // skin
        data << uint8(player->GetByteValue(PLAYER_BYTES, 1));   // face
        data << uint8(player->GetByteValue(PLAYER_BYTES, 2));   // hair
        data << uint8(player->GetByteValue(PLAYER_BYTES, 3));   // haircolor
        data << uint8(player->GetByteValue(PLAYER_BYTES_2, 0)); // facialhair
        data << uint32(player->GetGuildId());                   // unk

        static EquipmentSlots const itemSlots[] =
        {
            EQUIPMENT_SLOT_HEAD,
            EQUIPMENT_SLOT_SHOULDERS,
            EQUIPMENT_SLOT_BODY,
            EQUIPMENT_SLOT_CHEST,
            EQUIPMENT_SLOT_WAIST,
            EQUIPMENT_SLOT_LEGS,
            EQUIPMENT_SLOT_FEET,
            EQUIPMENT_SLOT_WRISTS,
            EQUIPMENT_SLOT_HANDS,
            EQUIPMENT_SLOT_BACK,
            EQUIPMENT_SLOT_TABARD,
            EQUIPMENT_SLOT_END
        };

        // Display items in visible slots
        for (EquipmentSlots const* itr = &itemSlots[0]; *itr != EQUIPMENT_SLOT_END; ++itr)
        {
            if (*itr == EQUIPMENT_SLOT_HEAD && player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM))
                data << uint32(0);
            else if (*itr == EQUIPMENT_SLOT_BACK && player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_CLOAK))
                data << uint32(0);
            else if (Item const* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, *itr))
                data << uint32(item->GetTemplate()->DisplayInfoID);
            else
                data << uint32(0);
        }
    }
    else
    {
        // Skip player data for creatures
        data << uint8(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
    }

    SendPacket(&data);
}

void WorldSession::HandleUpdateProjectilePosition(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_UPDATE_PROJECTILE_POSITION");

    ObjectGuid casterGuid;
    uint32 spellId;
    uint8 castCount;
    float x, y, z;    // Position of missile hit

    recvPacket >> casterGuid;
    recvPacket >> spellId;
    recvPacket >> castCount;
    recvPacket >> x;
    recvPacket >> y;
    recvPacket >> z;

    Unit* caster = ObjectAccessor::GetUnit(*_player, casterGuid);
    if (!caster)
        return;

    Spell* spell = caster->FindCurrentSpellBySpellId(spellId);
    if (!spell || !spell->m_targets.HasDst())
        return;

    Position pos = *spell->m_targets.GetDstPos();
    pos.Relocate(x, y, z);
    spell->m_targets.ModDst(pos);

    WorldPacket data(SMSG_SET_PROJECTILE_POSITION, 21);
    data << uint64(casterGuid);
    data << uint8(castCount);
    data << float(x);
    data << float(y);
    data << float(z);
    caster->SendMessageToSet(&data, true);
}
