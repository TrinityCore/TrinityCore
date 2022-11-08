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
#include "CellImpl.h"
#include "Common.h"
#include "Corpse.h"
#include "Creature.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Item.h"
#include "Log.h"
#include "Loot.h"
#include "LootItemStorage.h"
#include "LootMgr.h"
#include "LootPackets.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellMgr.h"

class AELootCreatureCheck
{
public:
    static float constexpr LootDistance = 30.0f;

    AELootCreatureCheck(Player* looter, ObjectGuid mainLootTarget) : _looter(looter), _mainLootTarget(mainLootTarget) { }

    bool operator()(Creature* creature) const
    {
        if (creature->IsAlive())
            return false;

        if (creature->GetGUID() == _mainLootTarget)
            return false;

        if (!_looter->IsWithinDist(creature, LootDistance))
            return false;

        return _looter->isAllowedToLoot(creature);
    }

    Player* _looter;
    ObjectGuid _mainLootTarget;
};

void WorldSession::HandleAutostoreLootItemOpcode(WorldPackets::Loot::LootItem& packet)
{
    Player* player = GetPlayer();
    AELootResult aeResult;
    AELootResult* aeResultPtr = player->GetAELootView().size() > 1 ? &aeResult : nullptr;

    /// @todo Implement looting by LootObject guid
    for (WorldPackets::Loot::LootRequest const& req : packet.Loot)
    {
        Loot* loot = Trinity::Containers::MapGetValuePtr(player->GetAELootView(), req.Object);
        if (!loot)
        {
            player->SendLootRelease(ObjectGuid::Empty);
            continue;
        }

        ObjectGuid lguid = loot->GetOwnerGUID();

        if (lguid.IsGameObject())
        {
            GameObject* go = player->GetMap()->GetGameObject(lguid);

            // not check distance for GO in case owned GO (fishing bobber case, for example) or Fishing hole GO
            if (!go || ((go->GetOwnerGUID() != player->GetGUID() && go->GetGoType() != GAMEOBJECT_TYPE_FISHINGHOLE) && !go->IsWithinDistInMap(player)))
            {
                player->SendLootRelease(lguid);
                continue;
            }
        }
        else if (lguid.IsCreatureOrVehicle())
        {
            Creature* creature = GetPlayer()->GetMap()->GetCreature(lguid);
            if (!creature)
            {
                player->SendLootError(req.Object, lguid, LOOT_ERROR_NO_LOOT);
                continue;
            }

            if (!creature->IsWithinDistInMap(player, AELootCreatureCheck::LootDistance))
            {
                player->SendLootError(req.Object, lguid, LOOT_ERROR_TOO_FAR);
                continue;
            }
        }

        player->StoreLootItem(lguid, req.LootListID, loot, aeResultPtr);

        // If player is removing the last LootItem, delete the empty container.
        if (loot->isLooted() && lguid.IsItem())
            player->GetSession()->DoLootRelease(loot);
    }

    if (aeResultPtr)
    {
        for (AELootResult::ResultValue const& resultValue : aeResult)
        {
            player->SendNewItem(resultValue.item, resultValue.count, false, false, true);
            player->UpdateCriteria(CriteriaType::LootItem, resultValue.item->GetEntry(), resultValue.count);
            player->UpdateCriteria(CriteriaType::GetLootByType, resultValue.item->GetEntry(), resultValue.count, resultValue.lootType);
            player->UpdateCriteria(CriteriaType::LootAnyItem, resultValue.item->GetEntry(), resultValue.count);
        }
    }

    Unit::ProcSkillsAndAuras(player, nullptr, PROC_FLAG_LOOTED, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);
}

void WorldSession::HandleLootMoneyOpcode(WorldPackets::Loot::LootMoney& /*packet*/)
{
    Player* player = GetPlayer();
    for (std::pair<ObjectGuid const, Loot*> const& lootView : player->GetAELootView())
    {
        Loot* loot = lootView.second;
        ObjectGuid guid = loot->GetOwnerGUID();
        bool shareMoney = loot->loot_type == LOOT_CORPSE;

        loot->NotifyMoneyRemoved(player->GetMap());
        if (shareMoney && player->GetGroup())      //item, pickpocket and players can be looted only single player
        {
            Group* group = player->GetGroup();

            std::vector<Player*> playersNear;
            for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* member = itr->GetSource();
                if (!member)
                    continue;

                if (player->IsAtGroupRewardDistance(member))
                    playersNear.push_back(member);
            }

            uint64 goldPerPlayer = uint64(loot->gold / playersNear.size());

            for (std::vector<Player*>::const_iterator i = playersNear.begin(); i != playersNear.end(); ++i)
            {
                uint64 goldMod = CalculatePct(goldPerPlayer, (*i)->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MONEY_GAIN, 1));

                (*i)->ModifyMoney(goldPerPlayer + goldMod);
                (*i)->UpdateCriteria(CriteriaType::MoneyLootedFromCreatures, goldPerPlayer);

                WorldPackets::Loot::LootMoneyNotify packet;
                packet.Money = goldPerPlayer;
                packet.MoneyMod = goldMod;
                packet.SoleLooter = playersNear.size() <= 1 ? true : false;
                (*i)->SendDirectMessage(packet.Write());
            }
        }
        else
        {
            uint64 goldMod = CalculatePct(loot->gold, player->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MONEY_GAIN, 1));

            player->ModifyMoney(loot->gold + goldMod);
            player->UpdateCriteria(CriteriaType::MoneyLootedFromCreatures, loot->gold);

            WorldPackets::Loot::LootMoneyNotify packet;
            packet.Money = loot->gold;
            packet.MoneyMod = goldMod;
            packet.SoleLooter = true; // "You loot..."
            SendPacket(packet.Write());
        }

        loot->gold = 0;

        // Delete the money loot record from the DB
        if (loot->loot_type == LOOT_ITEM)
            sLootItemStorage->RemoveStoredMoneyForContainer(guid.GetCounter());

        // Delete container if empty
        if (loot->isLooted() && guid.IsItem())
            player->GetSession()->DoLootRelease(loot);
    }
}

void WorldSession::HandleLootOpcode(WorldPackets::Loot::LootUnit& packet)
{
    // Check possible cheat
    if (!GetPlayer()->IsAlive() || !packet.Unit.IsCreatureOrVehicle())
        return;

    // interrupt cast
    if (GetPlayer()->IsNonMeleeSpellCast(false))
        GetPlayer()->InterruptNonMeleeSpells(false);

    GetPlayer()->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Looting);

    std::list<Creature*> corpses;
    AELootCreatureCheck check(_player, packet.Unit);
    Trinity::CreatureListSearcher<AELootCreatureCheck> searcher(_player, corpses, check);
    Cell::VisitGridObjects(_player, searcher, AELootCreatureCheck::LootDistance);

    if (!corpses.empty())
        SendPacket(WorldPackets::Loot::AELootTargets(uint32(corpses.size() + 1)).Write());

    GetPlayer()->SendLoot(packet.Unit, LOOT_CORPSE);

    if (!corpses.empty())
    {
        // main target
        SendPacket(WorldPackets::Loot::AELootTargetsAck().Write());

        for (Creature* creature : corpses)
        {
            GetPlayer()->SendLoot(creature->GetGUID(), LOOT_CORPSE, true);
            SendPacket(WorldPackets::Loot::AELootTargetsAck().Write());
        }
    }
}

void WorldSession::HandleLootReleaseOpcode(WorldPackets::Loot::LootRelease& packet)
{
    // cheaters can modify lguid to prevent correct apply loot release code and re-loot
    // use internal stored guid
    if (Loot* loot = GetPlayer()->GetLootByWorldObjectGUID(packet.Unit))
        DoLootRelease(loot);
}

void WorldSession::DoLootRelease(Loot* loot)
{
    ObjectGuid lguid = loot->GetOwnerGUID();
    Player  *player = GetPlayer();

    if (player->GetLootGUID() == lguid)
        player->SetLootGUID(ObjectGuid::Empty);

    player->SendLootRelease(lguid);
    player->m_AELootView.erase(loot->GetGUID());

    if (player->GetAELootView().empty())
        player->RemoveUnitFlag(UNIT_FLAG_LOOTING);

    if (!player->IsInWorld())
        return;

    if (lguid.IsGameObject())
    {
        GameObject* go = GetPlayer()->GetMap()->GetGameObject(lguid);

        // not check distance for GO in case owned GO (fishing bobber case, for example) or Fishing hole GO
        if (!go || ((go->GetOwnerGUID() != player->GetGUID() && go->GetGoType() != GAMEOBJECT_TYPE_FISHINGHOLE) && !go->IsWithinDistInMap(player)))
            return;

        if (go->GetGoType() == GAMEOBJECT_TYPE_DOOR)
        {
            // locked doors are opened with spelleffect openlock, prevent remove its as looted
            go->UseDoorOrButton();
        }
        else if (loot->isLooted() || go->GetGoType() == GAMEOBJECT_TYPE_FISHINGNODE)
        {
            if (go->GetGoType() == GAMEOBJECT_TYPE_FISHINGHOLE)
            {                                               // The fishing hole used once more
                go->AddUse();                               // if the max usage is reached, will be despawned in next tick
                if (go->GetUseCount() >= go->GetGOValue()->FishingHole.MaxOpens)
                    go->SetLootState(GO_JUST_DEACTIVATED);
                else
                    go->SetLootState(GO_READY);
            }
            else
                go->SetLootState(GO_JUST_DEACTIVATED);

            loot->clear();
        }
        else
        {
            // not fully looted object
            go->SetLootState(GO_ACTIVATED, player);

            // if the round robin player release, reset it.
            if (player->GetGUID() == loot->roundRobinPlayer)
                loot->roundRobinPlayer.Clear();
        }
    }
    else if (lguid.IsCorpse())        // ONLY remove insignia at BG
    {
        Corpse* corpse = ObjectAccessor::GetCorpse(*player, lguid);
        if (!corpse || !corpse->IsWithinDistInMap(player, INTERACTION_DISTANCE))
            return;

        if (loot->isLooted())
        {
            corpse->m_loot = nullptr;
            corpse->RemoveCorpseDynamicFlag(CORPSE_DYNFLAG_LOOTABLE);
        }
    }
    else if (lguid.IsItem())
    {
        Item* pItem = player->GetItemByGuid(lguid);
        if (!pItem)
            return;

        ItemTemplate const* proto = pItem->GetTemplate();

        // destroy only 5 items from stack in case prospecting and milling
        if (loot->loot_type == LOOT_PROSPECTING || loot->loot_type == LOOT_MILLING)
        {
            pItem->m_lootGenerated = false;
            pItem->m_loot.reset();

            uint32 count = pItem->GetCount();

            // >=5 checked in spell code, but will work for cheating cases also with removing from another stacks.
            if (count > 5)
                count = 5;

            player->DestroyItemCount(pItem, count, true);
        }
        else
        {
            // Only delete item if no loot or money (unlooted loot is saved to db) or if it isn't an openable item
            if (loot->isLooted() || !proto->HasFlag(ITEM_FLAG_HAS_LOOT))
                player->DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
        }
        return;                                             // item can be looted only single player
    }
    else
    {
        Creature* creature = GetPlayer()->GetMap()->GetCreature(lguid);
        if (!creature)
            return;

        if (!creature->IsWithinDistInMap(player, AELootCreatureCheck::LootDistance))
            return;

        if (creature->IsAlive() != (loot && loot->loot_type == LOOT_PICKPOCKETING))
            return;

        if (loot->isLooted())
        {
            creature->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);

            // skip pickpocketing loot for speed, skinning timer reduction is no-op in fact
            if (!creature->IsAlive())
                creature->AllLootRemovedFromCorpse();
        }
        else
        {
            // if the round robin player release, reset it.
            if (player->GetGUID() == loot->roundRobinPlayer)
            {
                loot->roundRobinPlayer.Clear();
                loot->NotifyLootList(creature->GetMap());
            }
            // force dynflag update to update looter and lootable info
            creature->ForceUpdateFieldChange(creature->m_values.ModifyValue(&Object::m_objectData).ModifyValue(&UF::ObjectData::DynamicFlags));
        }
    }

    //Player is not looking at loot list, he doesn't need to see updates on the loot list
    loot->RemoveLooter(player->GetGUID());
}

void WorldSession::DoLootReleaseAll()
{
    std::unordered_map<ObjectGuid, Loot*> lootView = _player->GetAELootView();
    for (auto const& [lootGuid, loot] : lootView)
        DoLootRelease(loot);
}

void WorldSession::HandleLootMasterGiveOpcode(WorldPackets::Loot::MasterLootItem& masterLootItem)
{
    AELootResult aeResult;

    if (!_player->GetGroup() || _player->GetGroup()->GetMasterLooterGuid() != _player->GetGUID())
    {
        _player->SendLootError(ObjectGuid::Empty, ObjectGuid::Empty, LOOT_ERROR_DIDNT_KILL);
        return;
    }

    // player on other map
    Player* target = ObjectAccessor::GetPlayer(*_player, masterLootItem.Target);
    if (!target)
    {
        _player->SendLootError(ObjectGuid::Empty, ObjectGuid::Empty, LOOT_ERROR_PLAYER_NOT_FOUND);
        return;
    }

    TC_LOG_DEBUG("network", "WorldSession::HandleLootMasterGiveOpcode (CMSG_LOOT_MASTER_GIVE, 0x02A3) Target = [%s].", target->GetName().c_str());

    for (WorldPackets::Loot::LootRequest const& req : masterLootItem.Loot)
    {
        Loot* loot = Trinity::Containers::MapGetValuePtr(_player->GetAELootView(), req.Object);

        if (!_player->IsInRaidWith(target) || !_player->IsInMap(target))
        {
            _player->SendLootError(req.Object, ObjectGuid::Empty, LOOT_ERROR_MASTER_OTHER);
            TC_LOG_INFO("entities.player.cheat", "MasterLootItem: Player %s tried to give an item to ineligible player %s !", GetPlayer()->GetName().c_str(), target->GetName().c_str());
            return;
        }

        if (!loot || loot->GetLootMethod() != MASTER_LOOT)
            return;

        if (req.LootListID >= loot->items.size())
        {
            TC_LOG_DEBUG("loot", "MasterLootItem: Player %s might be using a hack! (slot %d, size " SZFMTD ")",
                GetPlayer()->GetName().c_str(), req.LootListID, loot->items.size());
            return;
        }

        LootItem& item = loot->items[req.LootListID];

        ItemPosCountVec dest;
        InventoryResult msg = target->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item.itemid, item.count);
        if (!item.AllowedForPlayer(target, true))
            msg = EQUIP_ERR_CANT_EQUIP_EVER;
        if (msg != EQUIP_ERR_OK)
        {
            if (msg == EQUIP_ERR_ITEM_MAX_COUNT)
                _player->SendLootError(req.Object, ObjectGuid::Empty, LOOT_ERROR_MASTER_UNIQUE_ITEM);
            else if (msg == EQUIP_ERR_INV_FULL)
                _player->SendLootError(req.Object, ObjectGuid::Empty, LOOT_ERROR_MASTER_INV_FULL);
            else
                _player->SendLootError(req.Object, ObjectGuid::Empty, LOOT_ERROR_MASTER_OTHER);
            return;
        }

        // now move item from loot to target inventory
        Item* newitem = target->StoreNewItem(dest, item.itemid, true, item.randomBonusListId, item.GetAllowedLooters(), item.context, item.BonusListIDs);
        aeResult.Add(newitem, item.count, loot->loot_type);

        // mark as looted
        item.count = 0;
        item.is_looted = true;

        loot->NotifyItemRemoved(req.LootListID, GetPlayer()->GetMap());
        --loot->unlootedCount;
    }

    for (AELootResult::ResultValue const& resultValue : aeResult)
    {
        target->SendNewItem(resultValue.item, resultValue.count, false, false, true);
        target->UpdateCriteria(CriteriaType::LootItem, resultValue.item->GetEntry(), resultValue.count);
        target->UpdateCriteria(CriteriaType::GetLootByType, resultValue.item->GetEntry(), resultValue.count, resultValue.lootType);
        target->UpdateCriteria(CriteriaType::LootAnyItem, resultValue.item->GetEntry(), resultValue.count);
    }
}

void WorldSession::HandleLootRoll(WorldPackets::Loot::LootRoll& packet)
{
    LootRoll* lootRoll = GetPlayer()->GetLootRoll(packet.LootObj, packet.LootListID);
    if (!lootRoll)
        return;

    lootRoll->PlayerVote(GetPlayer(), RollVote(packet.RollType));
}

void WorldSession::HandleSetLootSpecialization(WorldPackets::Loot::SetLootSpecialization& packet)
{
    if (packet.SpecID)
    {
        if (ChrSpecializationEntry const* chrSpec = sChrSpecializationStore.LookupEntry(packet.SpecID))
            if (chrSpec->ClassID == GetPlayer()->GetClass())
                GetPlayer()->SetLootSpecId(packet.SpecID);
    }
    else
        GetPlayer()->SetLootSpecId(0);
}
