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
#include "CollectionMgr.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "GameObjectAI.h"
#include "GameObjectPackets.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Item.h"
#include "Log.h"
#include "Map.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "Totem.h"
#include "TotemPackets.h"
#include "World.h"

void WorldSession::HandleUseItemOpcode(WorldPackets::Spells::UseItem& packet)
{
    Player* user = _player;

    // ignore for remote control state
    if (user->GetUnitBeingMoved() != user)
        return;

    Item* item = user->GetUseableItemByPos(packet.PackSlot, packet.Slot);
    if (!item)
    {
        user->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
        return;
    }

    if (item->GetGUID() != packet.CastItem)
    {
        user->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
        return;
    }

    ItemTemplate const* proto = item->GetTemplate();
    if (!proto)
    {
        user->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, item, nullptr);
        return;
    }

    // some item classes can be used only in equipped state
    if (proto->GetInventoryType() != INVTYPE_NON_EQUIP && !item->IsEquipped())
    {
        user->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, item, nullptr);
        return;
    }

    InventoryResult msg = user->CanUseItem(item);
    if (msg != EQUIP_ERR_OK)
    {
        user->SendEquipError(msg, item, nullptr);
        return;
    }

    // only allow conjured consumable, bandage, poisons (all should have the 2^21 item flag set in DB)
    if (proto->GetClass() == ITEM_CLASS_CONSUMABLE && !proto->HasFlag(ITEM_FLAG_IGNORE_DEFAULT_ARENA_RESTRICTIONS) && user->InArena())
    {
        user->SendEquipError(EQUIP_ERR_NOT_DURING_ARENA_MATCH, item, nullptr);
        return;
    }

    // don't allow items banned in arena
    if (proto->HasFlag(ITEM_FLAG_NOT_USEABLE_IN_ARENA) && user->InArena())
    {
        user->SendEquipError(EQUIP_ERR_NOT_DURING_ARENA_MATCH, item, nullptr);
        return;
    }

    if (user->IsInCombat())
    {
        for (ItemEffectEntry const* effect : item->GetEffects())
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(effect->SpellID, user->GetMap()->GetDifficultyID()))
            {
                if (!spellInfo->CanBeUsedInCombat())
                {
                    user->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, item, nullptr);
                    return;
                }
            }
        }
    }

    // check also  BIND_ON_ACQUIRE and BIND_QUEST for .additem or .additemset case by GM (not binded at adding to inventory)
    if (item->GetBonding() == BIND_ON_USE || item->GetBonding() == BIND_ON_ACQUIRE || item->GetBonding() == BIND_QUEST)
    {
        if (!item->IsSoulBound())
        {
            item->SetState(ITEM_CHANGED, user);
            item->SetBinding(true);
            GetCollectionMgr()->AddItemAppearance(item);
        }
    }

    user->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::ItemUse);

    SpellCastTargets targets(user, packet.Cast);

    // Note: If script stop casting it must send appropriate data to client to prevent stuck item in gray state.
    if (!sScriptMgr->OnItemUse(user, item, targets, packet.Cast.CastID))
    {
        // no script or script not process request by self
        user->CastItemUseSpell(item, targets, packet.Cast.CastID, packet.Cast.Misc);
    }
}

void WorldSession::HandleOpenItemOpcode(WorldPackets::Spells::OpenItem& packet)
{
    Player* player = GetPlayer();

    // ignore for remote control state
    if (player->GetUnitBeingMoved() != player)
        return;
    TC_LOG_INFO("network", "bagIndex: %u, slot: %u", packet.Slot, packet.PackSlot);

    // additional check, client outputs message on its own
    if (!player->IsAlive())
    {
        player->SendEquipError(EQUIP_ERR_PLAYER_DEAD, nullptr, nullptr);
        return;
    }

    Item* item = player->GetItemByPos(packet.Slot, packet.PackSlot);
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
    if (!proto->HasFlag(ITEM_FLAG_HAS_LOOT) && !item->IsWrapped())
    {
        player->SendEquipError(EQUIP_ERR_CLIENT_LOCKED_OUT, item, nullptr);
        TC_LOG_ERROR("entities.player.cheat", "Possible hacking attempt: Player %s %s tried to open item [%s, entry: %u] which is not openable!",
            player->GetName().c_str(), player->GetGUID().ToString().c_str(), item->GetGUID().ToString().c_str(), proto->GetId());
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
            TC_LOG_ERROR("network", "WORLD::OpenItem: item %s has an unknown lockId: %u!", item->GetGUID().ToString().c_str(), lockId);
            return;
        }

        // was not unlocked yet
        if (item->IsLocked())
        {
            player->SendEquipError(EQUIP_ERR_ITEM_LOCKED, item, nullptr);
            return;
        }
    }

    if (item->IsWrapped())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GIFT_BY_ITEM);
        stmt->setUInt64(0, item->GetGUID().GetCounter());
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

    if (item->GetGUID() != itemGuid || !item->IsWrapped()) // during getting result, gift was swapped with another item
        return;

    if (!result)
    {
        TC_LOG_ERROR("network", "Wrapped item %s does't have record in character_gifts table and will deleted", item->GetGUID().ToString().c_str());
        GetPlayer()->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
        return;
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    Field* fields = result->Fetch();
    uint32 entry = fields[0].GetUInt32();
    uint32 flags = fields[1].GetUInt32();

    item->SetGiftCreator(ObjectGuid::Empty);
    item->SetEntry(entry);
    item->SetItemFlags(ItemFieldFlags(flags));
    item->SetMaxDurability(item->GetTemplate()->MaxDurability);
    item->SetState(ITEM_CHANGED, GetPlayer());

    GetPlayer()->SaveInventoryAndGoldToDB(trans);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GIFT);
    stmt->setUInt64(0, itemGuid.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void WorldSession::HandleGameObjectUseOpcode(WorldPackets::GameObject::GameObjUse& packet)
{
    if (GameObject* obj = GetPlayer()->GetGameObjectIfCanInteractWith(packet.Guid))
    {
        // ignore for remote control state
        if (GetPlayer()->GetUnitBeingMoved() != GetPlayer())
            if (!(GetPlayer()->IsOnVehicle(GetPlayer()->GetUnitBeingMoved()) || GetPlayer()->IsMounted()) && !obj->GetGOInfo()->IsUsableMounted())
                return;

        obj->Use(GetPlayer());
    }
}

void WorldSession::HandleGameobjectReportUse(WorldPackets::GameObject::GameObjReportUse& packet)
{
    // ignore for remote control state
    if (_player->GetUnitBeingMoved() != _player)
        return;

    if (GameObject* go = GetPlayer()->GetGameObjectIfCanInteractWith(packet.Guid))
    {
        if (go->AI()->OnReportUse(_player))
            return;

        _player->UpdateCriteria(CriteriaType::UseGameobject, go->GetEntry());
    }
}

void WorldSession::HandleCastSpellOpcode(WorldPackets::Spells::CastSpell& cast)
{
    // ignore for remote control state (for player case)
    Unit* mover = _player->GetUnitBeingMoved();
    if (mover != _player && mover->GetTypeId() == TYPEID_PLAYER)
        return;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(cast.Cast.SpellID, mover->GetMap()->GetDifficultyID());
    if (!spellInfo)
    {
        TC_LOG_ERROR("network", "WORLD: unknown spell id %u", cast.Cast.SpellID);
        return;
    }

    if (spellInfo->IsPassive())
        return;

    Unit* caster = mover;
    if (caster->GetTypeId() == TYPEID_UNIT && !caster->ToCreature()->HasSpell(spellInfo->Id))
    {
        // If the vehicle creature does not have the spell but it allows the passenger to cast own spells
        // change caster to player and let him cast
        if (!_player->IsOnVehicle(caster) || spellInfo->CheckVehicle(_player) != SPELL_CAST_OK)
            return;

        caster = _player;
    }

    TriggerCastFlags triggerFlag = TRIGGERED_NONE;

    // client provided targets
    SpellCastTargets targets(caster, cast.Cast);

    // check known spell or raid marker spell (which not requires player to know it)
    if (caster->GetTypeId() == TYPEID_PLAYER && !caster->ToPlayer()->HasActiveSpell(spellInfo->Id) && !spellInfo->HasEffect(SPELL_EFFECT_CHANGE_RAID_MARKER) && !spellInfo->HasAttribute(SPELL_ATTR8_RAID_MARKER))
    {
        bool allow = false;


        // allow casting of unknown spells for special lock cases
        if (GameObject* go = targets.GetGOTarget())
            if (go->GetSpellForLock(caster->ToPlayer()) == spellInfo)
                allow = true;

        // allow casting of spells triggered by clientside periodic trigger auras
        if (caster->HasAuraTypeWithTriggerSpell(SPELL_AURA_PERIODIC_TRIGGER_SPELL_FROM_CLIENT, spellInfo->Id))
        {
            allow = true;
            triggerFlag = TRIGGERED_FULL_MASK;
        }

        if (!allow)
            return;
    }

    // Check possible spell cast overrides
    spellInfo = caster->GetCastSpellInfo(spellInfo);

    // can't use our own spells when we're in possession of another unit,
    if (_player->isPossessing())
        return;

    // Client is resending autoshot cast opcode when other spell is cast during shoot rotation
    // Skip it to prevent "interrupt" message
    // Also check targets! target may have changed and we need to interrupt current spell
    if (spellInfo->IsAutoRepeatRangedSpell())
        if (Spell* spell = caster->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
            if (spell->m_spellInfo == spellInfo && spell->m_targets.GetUnitTargetGUID() == targets.GetUnitTargetGUID())
                return;

    // auto-selection buff level base at target level (in spellInfo)
    if (targets.GetUnitTarget())
    {
        SpellInfo const* actualSpellInfo = spellInfo->GetAuraRankForLevel(targets.GetUnitTarget()->GetLevelForTarget(caster));

        // if rank not found then function return NULL but in explicit cast case original spell can be cast and later failed with appropriate error message
        if (actualSpellInfo)
            spellInfo = actualSpellInfo;
    }

    if (cast.Cast.MoveUpdate)
        HandleMovementOpcode(CMSG_MOVE_STOP, *cast.Cast.MoveUpdate);

    Spell* spell = new Spell(caster, spellInfo, triggerFlag);

    WorldPackets::Spells::SpellPrepare spellPrepare;
    spellPrepare.ClientCastID = cast.Cast.CastID;
    spellPrepare.ServerCastID = spell->m_castId;
    SendPacket(spellPrepare.Write());

    spell->m_fromClient = true;
    spell->m_misc.Raw.Data[0] = cast.Cast.Misc[0];
    spell->m_misc.Raw.Data[1] = cast.Cast.Misc[1];
    spell->prepare(targets);
}

void WorldSession::HandleCancelCastOpcode(WorldPackets::Spells::CancelCast& packet)
{
    if (_player->IsNonMeleeSpellCast(false))
        _player->InterruptNonMeleeSpells(false, packet.SpellID, false);
}

void WorldSession::HandleCancelAuraOpcode(WorldPackets::Spells::CancelAura& cancelAura)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(cancelAura.SpellID, _player->GetMap()->GetDifficultyID());
    if (!spellInfo)
        return;

    // not allow remove spells with attr SPELL_ATTR0_CANT_CANCEL
    if (spellInfo->HasAttribute(SPELL_ATTR0_CANT_CANCEL))
        return;

    // channeled spell case (it currently cast then)
    if (spellInfo->IsChanneled())
    {
        if (Spell* curSpell = _player->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            if (curSpell->GetSpellInfo()->Id == uint32(cancelAura.SpellID))
                _player->InterruptSpell(CURRENT_CHANNELED_SPELL);
        return;
    }

    // non channeled case:
    // don't allow remove non positive spells
    // don't allow cancelling passive auras (some of them are visible)
    if (!spellInfo->IsPositive() || spellInfo->IsPassive())
        return;

    _player->RemoveOwnedAura(cancelAura.SpellID, cancelAura.CasterGUID, 0, AURA_REMOVE_BY_CANCEL);
}

void WorldSession::HandlePetCancelAuraOpcode(WorldPackets::Spells::PetCancelAura& packet)
{
    if (sSpellMgr->GetSpellInfo(packet.SpellID, DIFFICULTY_NONE))
    {
        TC_LOG_ERROR("network", "WORLD: unknown PET spell id %u", packet.SpellID);
        return;
    }

    Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, packet.PetGUID);

    if (!pet)
    {
        TC_LOG_ERROR("network", "HandlePetCancelAura: Attempt to cancel an aura for non-existant %s by player '%s'", packet.PetGUID.ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    if (pet != GetPlayer()->GetGuardianPet() && pet != GetPlayer()->GetCharmed())
    {
        TC_LOG_ERROR("network", "HandlePetCancelAura: %s is not a pet of player '%s'", packet.PetGUID.ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    if (!pet->IsAlive())
    {
        pet->SendPetActionFeedback(PetActionFeedback::Dead, 0);
        return;
    }

    pet->RemoveOwnedAura(packet.SpellID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
}

void WorldSession::HandleCancelGrowthAuraOpcode(WorldPackets::Spells::CancelGrowthAura& /*cancelGrowthAura*/)
{
    _player->RemoveAurasByType(SPELL_AURA_MOD_SCALE, [](AuraApplication const* aurApp)
    {
        SpellInfo const* spellInfo = aurApp->GetBase()->GetSpellInfo();
        return !spellInfo->HasAttribute(SPELL_ATTR0_CANT_CANCEL) && spellInfo->IsPositive() && !spellInfo->IsPassive();
    });
}

void WorldSession::HandleCancelMountAuraOpcode(WorldPackets::Spells::CancelMountAura& /*cancelMountAura*/)
{
    _player->RemoveAurasByType(SPELL_AURA_MOUNTED, [](AuraApplication const* aurApp)
    {
        SpellInfo const* spellInfo = aurApp->GetBase()->GetSpellInfo();
        return !spellInfo->HasAttribute(SPELL_ATTR0_CANT_CANCEL) && spellInfo->IsPositive() && !spellInfo->IsPassive();
    });
}

void WorldSession::HandleCancelAutoRepeatSpellOpcode(WorldPackets::Spells::CancelAutoRepeatSpell& /*cancelAutoRepeatSpell*/)
{
    // may be better send SMSG_CANCEL_AUTO_REPEAT?
    // cancel and prepare for deleting
    _player->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
}

void WorldSession::HandleCancelChanneling(WorldPackets::Spells::CancelChannelling& cancelChanneling)
{
    // ignore for remote control state (for player case)
    Unit* mover = _player->GetUnitBeingMoved();
    if (mover != _player && mover->GetTypeId() == TYPEID_PLAYER)
        return;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(cancelChanneling.ChannelSpell, mover->GetMap()->GetDifficultyID());
    if (!spellInfo)
        return;

    // not allow remove spells with attr SPELL_ATTR0_CANT_CANCEL
    if (spellInfo->HasAttribute(SPELL_ATTR0_CANT_CANCEL))
        return;

    Spell* spell = mover->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
    if (!spell || spell->GetSpellInfo()->Id != spellInfo->Id)
        return;

    mover->InterruptSpell(CURRENT_CHANNELED_SPELL);
}

void WorldSession::HandleTotemDestroyed(WorldPackets::Totem::TotemDestroyed& totemDestroyed)
{
    // ignore for remote control state
    if (_player->GetUnitBeingMoved() != _player)
        return;

    uint8 slotId = totemDestroyed.Slot;
    slotId += SUMMON_SLOT_TOTEM;

    if (slotId >= MAX_TOTEM_SLOT)
        return;

    if (!_player->m_SummonSlot[slotId])
        return;

    Creature* totem = ObjectAccessor::GetCreature(*_player, _player->m_SummonSlot[slotId]);
    if (totem && totem->IsTotem() && totem->GetGUID() == totemDestroyed.TotemGUID)
        totem->ToTotem()->UnSummon();
}

void WorldSession::HandleSelfResOpcode(WorldPackets::Spells::SelfRes& selfRes)
{
    if (_player->m_activePlayerData->SelfResSpells.FindIndex(selfRes.SpellID) < 0)
        return;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(selfRes.SpellID, _player->GetMap()->GetDifficultyID());
    if (!spellInfo)
        return;

    if (_player->HasAuraType(SPELL_AURA_PREVENT_RESURRECTION) && !spellInfo->HasAttribute(SPELL_ATTR7_BYPASS_NO_RESURRECT_AURA))
        return; // silent return, client should display error by itself and not send this opcode

    _player->CastSpell(_player, selfRes.SpellID, _player->GetMap()->GetDifficultyID());
    _player->RemoveSelfResSpell(selfRes.SpellID);
}

void WorldSession::HandleSpellClick(WorldPackets::Spells::SpellClick& spellClick)
{
    // this will get something not in world. crash
    Creature* unit = ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, spellClick.SpellClickUnitGuid);

    if (!unit)
        return;

    /// @todo Unit::SetCharmedBy: 28782 is not in world but 0 is trying to charm it! -> crash
    if (!unit->IsInWorld())
        return;

    unit->HandleSpellClick(_player);
}

void WorldSession::HandleMirrorImageDataRequest(WorldPackets::Spells::GetMirrorImageData& getMirrorImageData)
{
    ObjectGuid guid = getMirrorImageData.UnitGUID;

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

    if (Player* player = creator->ToPlayer())
    {
        WorldPackets::Spells::MirrorImageComponentedData mirrorImageComponentedData;
        mirrorImageComponentedData.UnitGUID = guid;
        mirrorImageComponentedData.DisplayID = creator->GetDisplayId();
        mirrorImageComponentedData.RaceID = creator->GetRace();
        mirrorImageComponentedData.Gender = creator->GetGender();
        mirrorImageComponentedData.ClassID = creator->GetClass();


        for (UF::ChrCustomizationChoice const& customization : player->m_playerData->Customizations)
            mirrorImageComponentedData.Customizations.push_back(customization);

        Guild* guild = player->GetGuild();
        mirrorImageComponentedData.GuildGUID = (guild ? guild->GetGUID() : ObjectGuid::Empty);

        mirrorImageComponentedData.ItemDisplayID.reserve(11);

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
            EQUIPMENT_SLOT_TABARD,
            EQUIPMENT_SLOT_BACK,
        };

        // Display items in visible slots
        for (EquipmentSlots slot : itemSlots)
        {
            uint32 itemDisplayId;
            if (Item const* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                itemDisplayId = item->GetDisplayId(player);
            else
                itemDisplayId = 0;

            mirrorImageComponentedData.ItemDisplayID.push_back(itemDisplayId);
        }
        SendPacket(mirrorImageComponentedData.Write());
    }
    else
    {
        WorldPackets::Spells::MirrorImageCreatureData mirrorImageCreatureData;
        mirrorImageCreatureData.UnitGUID = guid;
        mirrorImageCreatureData.DisplayID = creator->GetDisplayId();
        SendPacket(mirrorImageCreatureData.Write());
    }
}

void WorldSession::HandleMissileTrajectoryCollision(WorldPackets::Spells::MissileTrajectoryCollision& packet)
{
    Unit* caster = ObjectAccessor::GetUnit(*_player, packet.Target);
    if (!caster)
        return;

    Spell* spell = caster->FindCurrentSpellBySpellId(packet.SpellID);
    if (!spell || !spell->m_targets.HasDst())
        return;

    Position pos = *spell->m_targets.GetDstPos();
    pos.Relocate(packet.CollisionPos);
    spell->m_targets.ModDst(pos);

    // we changed dest, recalculate flight time
    spell->RecalculateDelayMomentForDst();

    WorldPackets::Spells::NotifyMissileTrajectoryCollision notify;
    notify.Caster = packet.Target;
    notify.CastID = packet.CastID;
    notify.CollisionPos = packet.CollisionPos;
    caster->SendMessageToSet(notify.Write(), true);
}

void WorldSession::HandleUpdateMissileTrajectory(WorldPackets::Spells::UpdateMissileTrajectory& packet)
{
    Unit* caster = ObjectAccessor::GetUnit(*_player, packet.Guid);
    Spell* spell = caster ? caster->GetCurrentSpell(CURRENT_GENERIC_SPELL) : nullptr;
    if (!spell || spell->m_spellInfo->Id != uint32(packet.SpellID) || spell->m_castId != packet.CastID || !spell->m_targets.HasDst() || !spell->m_targets.HasSrc())
        return;

    spell->m_targets.ModSrc(packet.FirePos);
    spell->m_targets.ModDst(packet.ImpactPos);
    spell->m_targets.SetPitch(packet.Pitch);
    spell->m_targets.SetSpeed(packet.Speed);

    if (packet.Status)
        HandleMovementOpcode(CMSG_MOVE_STOP, *packet.Status);
}

void WorldSession::HandleRequestCategoryCooldowns(WorldPackets::Spells::RequestCategoryCooldowns& /*requestCategoryCooldowns*/)
{
    _player->SendSpellCategoryCooldowns();
}
