/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "WorldPacket.h"
#include "Log.h"
#include "Corpse.h"
#include "GameObject.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "WorldSession.h"
#include "LootMgr.h"
#include "Object.h"
#include "Group.h"
#include "World.h"
#include "Util.h"

void WorldSession::HandleAutostoreLootItemOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_AUTOSTORE_LOOT_ITEM");
    Player* player = GetPlayer();
    uint64 lguid = player->GetLootGUID();
    Loot* loot = NULL;
    uint8 lootSlot = 0;

    recv_data >> lootSlot;

    if (IS_GAMEOBJECT_GUID(lguid))
    {
        GameObject* go = player->GetMap()->GetGameObject(lguid);

        // not check distance for GO in case owned GO (fishing bobber case, for example) or Fishing hole GO
        if (!go || ((go->GetOwnerGUID() != _player->GetGUID() && go->GetGoType() != GAMEOBJECT_TYPE_FISHINGHOLE) && !go->IsWithinDistInMap(_player, INTERACTION_DISTANCE)))
        {
            player->SendLootRelease(lguid);
            return;
        }

        loot = &go->loot;
    }
    else if (IS_ITEM_GUID(lguid))
    {
        Item* pItem = player->GetItemByGuid(lguid);

        if (!pItem)
        {
            player->SendLootRelease(lguid);
            return;
        }

        loot = &pItem->loot;
    }
    else if (IS_CORPSE_GUID(lguid))
    {
        Corpse* bones = ObjectAccessor::GetCorpse(*player, lguid);
        if (!bones)
        {
            player->SendLootRelease(lguid);
            return;
        }

        loot = &bones->loot;
    }
    else
    {
        Creature* pCreature = GetPlayer()->GetMap()->GetCreature(lguid);

        bool ok_loot = pCreature && pCreature->isAlive() == (player->getClass() == CLASS_ROGUE && pCreature->lootForPickPocketed);

        if (!ok_loot || !pCreature->IsWithinDistInMap(_player, INTERACTION_DISTANCE))
        {
            player->SendLootRelease(lguid);
            return;
        }

        loot = &pCreature->loot;
    }

    player->StoreLootItem(lootSlot, loot);
}

void WorldSession::HandleLootMoneyOpcode(WorldPacket & /*recv_data*/)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_LOOT_MONEY");

    Player* player = GetPlayer();
    uint64 guid = player->GetLootGUID();
    if (!guid)
        return;

    Loot* loot = NULL;
    bool shareMoney = true;

    switch (GUID_HIPART(guid))
    {
        case HIGHGUID_GAMEOBJECT:
        {
            GameObject* go = GetPlayer()->GetMap()->GetGameObject(guid);

            // do not check distance for GO if player is the owner of it (ex. fishing bobber)
            if (go && ((go->GetOwnerGUID() == player->GetGUID() || go->IsWithinDistInMap(player, INTERACTION_DISTANCE))))
                loot = &go->loot;

            break;
        }
        case HIGHGUID_CORPSE:                               // remove insignia ONLY in BG
        {
            Corpse* bones = ObjectAccessor::GetCorpse(*player, guid);

            if (bones && bones->IsWithinDistInMap(player, INTERACTION_DISTANCE))
            {
                loot = &bones->loot;
                shareMoney = false;
            }

            break;
        }
        case HIGHGUID_ITEM:
        {
            if (Item* item = player->GetItemByGuid(guid))
            {
                loot = &item->loot;
                shareMoney = false;
            }
            break;
        }
        case HIGHGUID_UNIT:
        case HIGHGUID_VEHICLE:
        {
            Creature* creature = player->GetMap()->GetCreature(guid);
            bool lootAllowed = creature && creature->isAlive() == (player->getClass() == CLASS_ROGUE && creature->lootForPickPocketed);
            if (lootAllowed && creature->IsWithinDistInMap(player, INTERACTION_DISTANCE))
            {
                loot = &creature->loot;
                if (creature->isAlive())
                    shareMoney = false;
            }
            break;
        }
        default:
            return;                                         // unlootable type
    }

    if (loot)
    {
        loot->NotifyMoneyRemoved();
        if (shareMoney && player->GetGroup())      //item, pickpocket and players can be looted only single player
        {
            Group* group = player->GetGroup();

            std::vector<Player*> playersNear;
            for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* member = itr->getSource();
                if (!member)
                    continue;

                if (player->IsWithinDistInMap(member, sWorld->getFloatConfig(CONFIG_GROUP_XP_DISTANCE), false))
                    playersNear.push_back(member);
            }

            uint32 goldPerPlayer = uint32((loot->gold) / (playersNear.size()));

            for (std::vector<Player*>::const_iterator i = playersNear.begin(); i != playersNear.end(); ++i)
            {
                (*i)->ModifyMoney(goldPerPlayer);
                (*i)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY, goldPerPlayer);

                WorldPacket data(SMSG_LOOT_MONEY_NOTIFY, 4 + 1);
                data << uint32(goldPerPlayer);
                data << uint8(playersNear.size() > 1 ? 0 : 1);     // Controls the text displayed in chat. 0 is "Your share is..." and 1 is "You loot..."
                (*i)->GetSession()->SendPacket(&data);
            }
        }
        else
        {
            player->ModifyMoney(loot->gold);
            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY, loot->gold);

            WorldPacket data(SMSG_LOOT_MONEY_NOTIFY, 4 + 1);
            data << uint32(loot->gold);
            data << uint8(1);   // "You loot..."
            SendPacket(&data);
        }

        loot->gold = 0;
    }
}

void WorldSession::HandleLootOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_LOOT");

    uint64 guid;
    recv_data >> guid;

    // Check possible cheat
    if (!_player->isAlive())
        return;

    GetPlayer()->SendLoot(guid, LOOT_CORPSE);

    // interrupt cast
    if (GetPlayer()->IsNonMeleeSpellCasted(false))
        GetPlayer()->InterruptNonMeleeSpells(false);
}

void WorldSession::HandleLootReleaseOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_LOOT_RELEASE");

    // cheaters can modify lguid to prevent correct apply loot release code and re-loot
    // use internal stored guid
    recv_data.read_skip<uint64>();                          // guid;

    if (uint64 lguid = GetPlayer()->GetLootGUID())
        DoLootRelease(lguid);
}

void WorldSession::DoLootRelease(uint64 lguid)
{
    Player  *player = GetPlayer();
    Loot    *loot;

    player->SetLootGUID(0);
    player->SendLootRelease(lguid);

    player->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOOTING);

    if (!player->IsInWorld())
        return;

    if (IS_GAMEOBJECT_GUID(lguid))
    {
        GameObject* go = GetPlayer()->GetMap()->GetGameObject(lguid);

        // not check distance for GO in case owned GO (fishing bobber case, for example) or Fishing hole GO
        if (!go || ((go->GetOwnerGUID() != _player->GetGUID() && go->GetGoType() != GAMEOBJECT_TYPE_FISHINGHOLE) && !go->IsWithinDistInMap(_player, INTERACTION_DISTANCE)))
            return;

        loot = &go->loot;

        if (go->GetGoType() == GAMEOBJECT_TYPE_DOOR)
        {
            // locked doors are opened with spelleffect openlock, prevent remove its as looted
            go->UseDoorOrButton();
        }
        else if (loot->isLooted() || go->GetGoType() == GAMEOBJECT_TYPE_FISHINGNODE)
        {
            // GO is mineral vein? so it is not removed after its looted
            if (go->GetGoType() == GAMEOBJECT_TYPE_CHEST)
            {
                uint32 go_min = go->GetGOInfo()->chest.minSuccessOpens;
                uint32 go_max = go->GetGOInfo()->chest.maxSuccessOpens;

                // only vein pass this check
                if (go_min != 0 && go_max > go_min)
                {
                    float amount_rate = sWorld->getRate(RATE_MINING_AMOUNT);
                    float min_amount = go_min*amount_rate;
                    float max_amount = go_max*amount_rate;

                    go->AddUse();
                    float uses = float(go->GetUseCount());

                    if (uses < max_amount)
                    {
                        if (uses >= min_amount)
                        {
                            float chance_rate = sWorld->getRate(RATE_MINING_NEXT);

                            int32 ReqValue = 175;
                            LockEntry const* lockInfo = sLockStore.LookupEntry(go->GetGOInfo()->chest.lockId);
                            if (lockInfo)
                                ReqValue = lockInfo->Skill[0];
                            float skill = float(player->GetSkillValue(SKILL_MINING))/(ReqValue+25);
                            double chance = pow(0.8*chance_rate, 4*(1/double(max_amount))*double(uses));
                            if (roll_chance_f((float)(100*chance+skill)))
                            {
                                go->SetLootState(GO_READY);
                            }
                            else                            // not have more uses
                                go->SetLootState(GO_JUST_DEACTIVATED);
                        }
                        else                                // 100% chance until min uses
                            go->SetLootState(GO_READY);
                    }
                    else                                    // max uses already
                        go->SetLootState(GO_JUST_DEACTIVATED);
                }
                else                                        // not vein
                    go->SetLootState(GO_JUST_DEACTIVATED);
            }
            else if (go->GetGoType() == GAMEOBJECT_TYPE_FISHINGHOLE)
            {                                               // The fishing hole used once more
                go->AddUse();                               // if the max usage is reached, will be despawned in next tick
                if (go->GetUseCount() >= urand(go->GetGOInfo()->fishinghole.minSuccessOpens, go->GetGOInfo()->fishinghole.maxSuccessOpens))
                {
                    go->SetLootState(GO_JUST_DEACTIVATED);
                }
                else
                    go->SetLootState(GO_READY);
            }
            else // not chest (or vein/herb/etc)
                go->SetLootState(GO_JUST_DEACTIVATED);

            loot->clear();
        }
        else
        {
            // not fully looted object
            go->SetLootState(GO_ACTIVATED);

            // if the round robin player release, reset it.
            if (player->GetGUID() == loot->roundRobinPlayer)
            {
                if (Group* pGroup = player->GetGroup())
                {
                    if (pGroup->GetLootMethod() != MASTER_LOOT)
                    {
                        loot->roundRobinPlayer = 0;
                    }
                }
                else
                    loot->roundRobinPlayer = 0;
            }
        }
    }
    else if (IS_CORPSE_GUID(lguid))        // ONLY remove insignia at BG
    {
        Corpse* corpse = ObjectAccessor::GetCorpse(*player, lguid);
        if (!corpse || !corpse->IsWithinDistInMap(_player, INTERACTION_DISTANCE))
            return;

        loot = &corpse->loot;

        if (loot->isLooted())
        {
            loot->clear();
            corpse->RemoveFlag(CORPSE_FIELD_DYNAMIC_FLAGS, CORPSE_DYNFLAG_LOOTABLE);
        }
    }
    else if (IS_ITEM_GUID(lguid))
    {
        Item* pItem = player->GetItemByGuid(lguid);
        if (!pItem)
            return;

        ItemTemplate const* proto = pItem->GetTemplate();

        // destroy only 5 items from stack in case prospecting and milling
        if (proto->Flags & (ITEM_PROTO_FLAG_PROSPECTABLE | ITEM_PROTO_FLAG_MILLABLE))
        {
            pItem->m_lootGenerated = false;
            pItem->loot.clear();

            uint32 count = pItem->GetCount();

            // >=5 checked in spell code, but will work for cheating cases also with removing from another stacks.
            if (count > 5)
                count = 5;

            player->DestroyItemCount(pItem, count, true);
        }
        else
            // FIXME: item must not be deleted in case not fully looted state. But this pre-request implement loot saving in DB at item save. Or cheating possible.
            player->DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
        return;                                             // item can be looted only single player
    }
    else
    {
        Creature* pCreature = GetPlayer()->GetMap()->GetCreature(lguid);

        bool ok_loot = pCreature && pCreature->isAlive() == (player->getClass() == CLASS_ROGUE && pCreature->lootForPickPocketed);
        if (!ok_loot || !pCreature->IsWithinDistInMap(_player, INTERACTION_DISTANCE))
            return;

        loot = &pCreature->loot;
        if (loot->isLooted())
        {
            // skip pickpocketing loot for speed, skinning timer reduction is no-op in fact
            if (!pCreature->isAlive())
                pCreature->AllLootRemovedFromCorpse();

            pCreature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            loot->clear();
        }
        else
        {
            // if the round robin player release, reset it.
            if (player->GetGUID() == loot->roundRobinPlayer)
            {
                if (Group* pGroup = player->GetGroup())
                {
                    if (pGroup->GetLootMethod() != MASTER_LOOT)
                    {
                        loot->roundRobinPlayer = 0;
                        pGroup->SendLooter(pCreature, NULL);

                        // force update of dynamic flags, otherwise other group's players still not able to loot.
                        pCreature->ForceValuesUpdateAtIndex(UNIT_DYNAMIC_FLAGS);
                    }
                }
                else
                    loot->roundRobinPlayer = 0;
            }
        }
    }

    //Player is not looking at loot list, he doesn't need to see updates on the loot list
    loot->RemoveLooter(player->GetGUID());
}

void WorldSession::HandleLootMasterGiveOpcode(WorldPacket & recv_data)
{
    uint8 slotid;
    uint64 lootguid, target_playerguid;

    recv_data >> lootguid >> slotid >> target_playerguid;

    if (!_player->GetGroup() || _player->GetGroup()->GetLooterGuid() != _player->GetGUID())
    {
        _player->SendLootRelease(GetPlayer()->GetLootGUID());
        return;
    }

    Player* target = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(target_playerguid, 0, HIGHGUID_PLAYER));
    if (!target)
        return;

    sLog->outDebug(LOG_FILTER_NETWORKIO, "WorldSession::HandleLootMasterGiveOpcode (CMSG_LOOT_MASTER_GIVE, 0x02A3) Target = [%s].", target->GetName());

    if (_player->GetLootGUID() != lootguid)
        return;

    Loot* pLoot = NULL;

    if (IS_CRE_OR_VEH_GUID(GetPlayer()->GetLootGUID()))
    {
        Creature* pCreature = GetPlayer()->GetMap()->GetCreature(lootguid);
        if (!pCreature)
            return;

        pLoot = &pCreature->loot;
    }
    else if (IS_GAMEOBJECT_GUID(GetPlayer()->GetLootGUID()))
    {
        GameObject* pGO = GetPlayer()->GetMap()->GetGameObject(lootguid);
        if (!pGO)
            return;

        pLoot = &pGO->loot;
    }

    if (!pLoot)
        return;

    if (slotid > pLoot->items.size())
    {
        sLog->outDebug(LOG_FILTER_LOOT, "MasterLootItem: Player %s might be using a hack! (slot %d, size %lu)", GetPlayer()->GetName(), slotid, (unsigned long)pLoot->items.size());
        return;
    }

    LootItem& item = pLoot->items[slotid];

    ItemPosCountVec dest;
    InventoryResult msg = target->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item.itemid, item.count);
    if (msg != EQUIP_ERR_OK)
    {
        target->SendEquipError(msg, NULL, NULL, item.itemid);
        // send duplicate of error massage to master looter
        _player->SendEquipError(msg, NULL, NULL, item.itemid);
        return;
    }

    // list of players allowed to receive this item in trade
    AllowedLooterSet* looters = item.GetAllowedLooters();

    // not move item from loot to target inventory
    Item* newitem = target->StoreNewItem(dest, item.itemid, true, item.randomPropertyId, (looters->size() > 1) ? looters : NULL);
    target->SendNewItem(newitem, uint32(item.count), false, false, true);
    target->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM, item.itemid, item.count);
    target->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE, pLoot->loot_type, item.count);
    target->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM, item.itemid, item.count);

    // mark as looted
    item.count=0;
    item.is_looted=true;

    pLoot->NotifyItemRemoved(slotid);
    --pLoot->unlootedCount;
}

