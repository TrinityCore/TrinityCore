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
#include "Archaeology.h"
#include "Common.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameClient.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "QueryCallback.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "Totem.h"
#include "World.h"
#include "WorldPacket.h"

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
            HandleMovementOpcodes(recvPacket);
    }
    else if (castFlags & 0x8)   // Archaeology
    {
        ArchData archData;
        uint32 count;
        uint8 type;
        recvPacket >> count;
        for (uint32 i = 0; i < count; ++i)
        {
            recvPacket >> type;
            switch (type)
            {
                case 2: // Keystones
                    recvPacket >> archData.KeyId;       // Item id
                    recvPacket >> archData.KeyCount;    // Item count
                    break;
                case 1: // Fragments
                    recvPacket >> archData.FragId;      // Currency id
                    recvPacket >> archData.FragCount;   // Currency count
                    break;
                default:
                    break;
            }
        }

        if (Player* player = GetPlayer())
            player->SetArchData(archData);
    }
}

void WorldSession::HandleUseItemOpcode(WorldPackets::Spells::UseItem& packet)
{
    Player* user = _player;

    // ignore for remote control state
    if (user->IsCharming())
        return;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(packet.Cast.SpellID);
    if (!spellInfo)
        return;

    if (user->CanRequestSpellCast(spellInfo))
        user->RequestSpellCast(PendingSpellCastRequest(std::move(packet.Cast), SpellCastRequestItemData(packet.PackSlot, packet.Slot, packet.CastItem)), spellInfo);
}

void WorldSession::HandleOpenItemOpcode(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_OPEN_ITEM packet, data length = %i", (uint32)recvPacket.size());

    Player* player = GetPlayer();

    // ignore for remote control state
    if (player->IsCharming())
        return;

    // additional check, client outputs message on its own
    if (!player->IsAlive())
    {
        player->SendEquipError(EQUIP_ERR_PLAYER_DEAD, nullptr, nullptr);
        return;
    }

    uint8 bagIndex, slot;
    recvPacket >> bagIndex >> slot;

    TC_LOG_INFO("network", "bagIndex: %u, slot: %u", bagIndex, slot);

    Item* item = player->GetItemByPos(bagIndex, slot);
    if (!item)
    {
        player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
        return;
    }

    ItemTemplate const* proto = item->GetTemplate();
    if (!proto)
    {
        player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, item, nullptr);
        return;
    }

    // Verify that the bag is an actual bag or wrapped item that can be used "normally"
    if (!(proto->GetFlags() & ITEM_FLAG_HAS_LOOT) && !item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_WRAPPED))
    {
        player->SendEquipError(EQUIP_ERR_CLIENT_LOCKED_OUT, item, nullptr);
        TC_LOG_INFO("entities.player.cheat", "Possible hacking attempt: Player %s [guid: %u] tried to open item [guid: %u, entry: %u] which is not openable!",
            player->GetName().c_str(), player->GetGUID().GetCounter(), item->GetGUID().GetCounter(), proto->GetId());
        return;
    }

    // locked item
    uint32 lockId = proto->GetLockID();
    if (lockId)
    {
        LockEntry const* lockInfo = sLockStore.LookupEntry(lockId);

        if (!lockInfo)
        {
            player->SendEquipError(EQUIP_ERR_ITEM_LOCKED, item, nullptr);
            TC_LOG_ERROR("network", "WORLD::OpenItem: item [guid = %u] has an unknown lockId: %u!", item->GetGUID().GetCounter(), lockId);
            return;
        }

        // was not unlocked yet
        if (item->IsLocked())
        {
            player->SendEquipError(EQUIP_ERR_ITEM_LOCKED, item, nullptr);
            return;
        }
    }

    if (item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_WRAPPED))// wrapped?
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GIFT_BY_ITEM);

        stmt->setUInt32(0, item->GetGUID().GetCounter());
        _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt)
            .WithPreparedCallback(std::bind(&WorldSession::HandleOpenWrappedItemCallback, this, item->GetPos(), item->GetGUID(), std::placeholders::_1)));
    }
    else
        player->SendLoot(item->GetGUID(), LOOT_CORPSE);
}

void WorldSession::HandleOpenWrappedItemCallback(uint16 pos, ObjectGuid itemGuid, PreparedQueryResult result)
{
    if (!GetPlayer())
        return;

    Item* item = GetPlayer()->GetItemByPos(pos);
    if (!item)
        return;

    if (item->GetGUID() != itemGuid || !item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_WRAPPED)) // during getting result, gift was swapped with another item
        return;

    if (!result)
    {
        TC_LOG_ERROR("network", "Wrapped item %u don't have record in character_gifts table and will deleted", itemGuid.GetCounter());
        GetPlayer()->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
        return;
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    Field* fields = result->Fetch();
    uint32 entry = fields[0].GetUInt32();
    uint32 flags = fields[1].GetUInt32();

    item->SetGuidValue(ITEM_FIELD_GIFTCREATOR, ObjectGuid::Empty);
    item->SetEntry(entry);
    item->SetUInt32Value(ITEM_FIELD_FLAGS, flags);
    item->SetUInt32Value(ITEM_FIELD_MAXDURABILITY, item->GetTemplate()->MaxDurability);
    item->SetState(ITEM_CHANGED, GetPlayer());

    GetPlayer()->SaveInventoryAndGoldToDB(trans);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GIFT);
    stmt->setUInt32(0, itemGuid.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void WorldSession::HandleGameObjectUseOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    recvData >> guid;

    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_GAMEOBJ_USE Message [%s]", guid.ToString().c_str());

    if (GameObject* obj = GetPlayer()->GetGameObjectIfCanInteractWith(guid))
    {
        // ignore for remote control state
        if (GetPlayer()->IsCharming())
            if (!(GetPlayer()->IsOnVehicle(GetPlayer()->GetCharmed()) || GetPlayer()->IsMounted()) && !obj->GetGOInfo()->IsUsableMounted())
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
    if (_player->IsCharming())
        return;

    if (GameObject* go = GetPlayer()->GetGameObjectIfCanInteractWith(guid))
    {
        if (go->AI()->OnReportUse(_player))
            return;

        _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT, go->GetEntry());
    }
}

void WorldSession::HandleCastSpellOpcode(WorldPackets::Spells::CastSpell& cast)
{
    // ignore for remote control state (for player case)
    Unit* mover = GetGameClient()->GetActivelyMovedUnit();
    if (!mover || (mover != _player && mover->IsPlayer()))
        return;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(cast.Cast.SpellID);
    if (!spellInfo || spellInfo->IsPassive())
        return;

    if (mover->CanRequestSpellCast(spellInfo))
        mover->RequestSpellCast(PendingSpellCastRequest(std::move(cast.Cast)), spellInfo);
    else if (mover->IsPlayer())
        Spell::SendCastResult(mover->ToPlayer(), spellInfo, cast.Cast.CastID, SPELL_FAILED_SPELL_IN_PROGRESS);
}

void WorldSession::HandleCancelCastOpcode(WorldPacket& recvPacket)
{
    uint32 spellId = 0;
    uint8 castId = 0;

    recvPacket >> castId;
    recvPacket >> spellId;

    if (_player->IsNonMeleeSpellCast(false))
        _player->InterruptNonMeleeSpells(false, spellId, false);

    _player->CancelPendingCastRequest();
}

void WorldSession::HandleCancelAuraOpcode(WorldPacket& recvPacket)
{
    uint32 spellId;
    recvPacket >> spellId;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
        return;

    // not allow remove spells with attr SPELL_ATTR0_NO_AURA_CANCEL
    if (spellInfo->HasAttribute(SPELL_ATTR0_NO_AURA_CANCEL))
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
    _player->RemoveOwnedAura(spellId, ObjectGuid::Empty, 0, AuraRemoveFlags::ByCancel);

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
                _player->RemoveOwnedAura(*it, ObjectGuid::Empty, 0, AuraRemoveFlags::ByCancel);
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

    Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, guid);
    if (!pet)
    {
        TC_LOG_ERROR("network", "HandlePetCancelAura: Attempt to cancel an aura for non-existant %s by player '%s'", guid.ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    if (pet != GetPlayer()->GetGuardianPet() && pet != GetPlayer()->GetCharmed())
    {
        TC_LOG_ERROR("network", "HandlePetCancelAura: %s is not a pet of player '%s'", guid.ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    if (!pet->IsAlive())
    {
        pet->SendPetActionFeedback(FEEDBACK_PET_DEAD);
        return;
    }

    pet->RemoveOwnedAura(spellId, ObjectGuid::Empty, 0, AuraRemoveFlags::ByCancel);
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
    uint32 spellId = 0;
    recvData >> spellId;    // Spell Id

    Unit* mover = GetGameClient()->GetActivelyMovedUnit();

    // ignore for remote control state (for player case)
    if (!mover)
        return;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
        return;

    // not allow cancel channeling with attr SPELL_ATTR0_NO_AURA_CANCEL
    if (spellInfo->HasAttribute(SPELL_ATTR0_NO_AURA_CANCEL))
        return;

    Spell* spell = mover->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
    if (!spell || spell->GetSpellInfo()->Id != spellInfo->Id)
        return;

    mover->InterruptSpell(CURRENT_CHANNELED_SPELL);
}

void WorldSession::HandleTotemDestroyed(WorldPacket& recvPacket)
{
    // ignore for remote control state
    if (_player->IsCharming())
        return;

    uint8 slotId;
    uint64 guid;
    recvPacket >> slotId;
    recvPacket >> guid;

    ++slotId;
    if (slotId >= MAX_TOTEM_SLOT)
        return;

    if (!_player->m_SummonSlot[slotId])
        return;

    Creature* totem = ObjectAccessor::GetCreature(*GetPlayer(), _player->m_SummonSlot[slotId]);
    if (totem && totem->IsTotem() && totem->GetGUID() == guid)
        totem->ToTotem()->UnSummon();
}

void WorldSession::HandleSelfResOpcode(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_SELF_RES");                  // empty opcode

    if (_player->HasAuraType(SPELL_AURA_PREVENT_RESURRECTION))
        return; // silent return, client should display error by itself and not send this opcode

    if (uint32 spellId = _player->GetUInt32Value(PLAYER_SELF_RES_SPELL))
    {
        _player->CastSpell(_player, spellId);
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
    recvData.read_skip<uint32>(); // DisplayId ?

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
        Guild* guild = nullptr;

        if (uint32 guildId = player->GetGuildId())
            guild = sGuildMgr->GetGuildById(guildId);

        data << uint8(player->GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_SKIN_ID));
        data << uint8(player->GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_FACE_ID));
        data << uint8(player->GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_STYLE_ID));
        data << uint8(player->GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_COLOR_ID));
        data << uint8(player->GetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_FACIAL_STYLE));
        data << uint64(guild ? guild->GetGUID() : 0);

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
                data << uint32(item->GetTemplate()->GetDisplayID());
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

    // we changed dest, recalculate flight time
    spell->RecalculateDelayMomentForDst();

    WorldPacket data(SMSG_SET_PROJECTILE_POSITION, 21);
    data << uint64(casterGuid);
    data << uint8(castCount);
    data << float(x);
    data << float(y);
    data << float(z);
    caster->SendMessageToSet(&data, true);
}

void WorldSession::HandleRequestCategoryCooldowns(WorldPacket& /*recvPacket*/)
{
    _player->SendSpellCategoryCooldowns();
}

void WorldSession::HandleCancelQueuedSpellOpcode(WorldPackets::Spells::CancelQueuedSpell& /*cancelQueuedSpell*/)
{
    Unit* mover = _player->GetCharmedOrSelf();
    if (mover != _player && mover->IsPlayer())
        return;

    mover->CancelPendingCastRequest();
}
void WorldSession::HandleUpdateMissileTrajectory(WorldPackets::Spells::UpdateMissileTrajectory& updateMissileTrajectory)
{
    Unit* caster = ObjectAccessor::GetUnit(*_player, updateMissileTrajectory.Guid);
    Spell* spell = caster ? caster->GetCurrentSpell(CURRENT_GENERIC_SPELL) : nullptr;
    if (!spell || int32(spell->m_spellInfo->Id) != updateMissileTrajectory.SpellID || !spell->m_targets.HasDst() || !spell->m_targets.HasSrc())
        return;

    Position pos = *spell->m_targets.GetSrcPos();
    pos.Relocate(updateMissileTrajectory.FirePos);
    spell->m_targets.ModSrc(pos);

    pos = spell->m_targets.GetDstPos()->GetPosition();
    pos.Relocate(updateMissileTrajectory.ImpactPos);
    spell->m_targets.ModDst(pos);

    spell->m_targets.SetElevation(updateMissileTrajectory.Pitch);
    spell->m_targets.SetSpeed(updateMissileTrajectory.Speed);
}
