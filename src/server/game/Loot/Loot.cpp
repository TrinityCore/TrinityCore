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

#include "Loot.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameTime.h"
#include "Group.h"
#include "Item.h"
#include "ItemBonusMgr.h"
#include "ItemTemplate.h"
#include "Log.h"
#include "LootMgr.h"
#include "LootPackets.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Random.h"
#include "World.h"
#include "WorldSession.h"

//
// --------- LootItem ---------
//

// Constructor, copies most fields from LootStoreItem and generates random count
LootItem::LootItem(LootStoreItem const& li)
{
    itemid = li.itemid;
    LootListId = 0;
    conditions = li.conditions;

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemid);
    freeforall = proto && proto->HasFlag(ITEM_FLAG_MULTI_DROP);
    follow_loot_rules = !li.needs_quest || (proto && proto->HasFlag(ITEM_FLAGS_CU_FOLLOW_LOOT_RULES));

    needs_quest = li.needs_quest;

    randomBonusListId = GenerateItemRandomBonusListId(itemid);
    context = ItemContext::NONE;
    count = 0;
    is_looted = false;
    is_blocked = false;
    is_underthreshold = false;
    is_counted = false;
    rollWinnerGUID = ObjectGuid::Empty;
}

LootItem::LootItem(LootItem const&) = default;
LootItem::LootItem(LootItem&&) noexcept = default;
LootItem& LootItem::operator=(LootItem const&) = default;
LootItem& LootItem::operator=(LootItem&&) noexcept = default;
LootItem::~LootItem() = default;

// Basic checks for player/item compatibility - if false no chance to see the item in the loot
bool LootItem::AllowedForPlayer(Player const* player, Loot const* loot) const
{
    return AllowedForPlayer(player, loot, itemid, needs_quest, follow_loot_rules, false, conditions);
}

bool LootItem::AllowedForPlayer(Player const* player, Loot const* loot, uint32 itemid, bool needs_quest, bool follow_loot_rules, bool strictUsabilityCheck,
    ConditionContainer const& conditions)
{
    // DB conditions check
    if (!sConditionMgr->IsObjectMeetToConditions(player, conditions))
        return false;

    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itemid);
    if (!pProto)
        return false;

    // not show loot for not own team
    if (pProto->HasFlag(ITEM_FLAG2_FACTION_HORDE) && player->GetTeam() != HORDE)
        return false;

    if (pProto->HasFlag(ITEM_FLAG2_FACTION_ALLIANCE) && player->GetTeam() != ALLIANCE)
        return false;

    // Master looter can see all items even if the character can't loot them
    if (loot && loot->GetLootMethod() == MASTER_LOOT && follow_loot_rules && loot->GetLootMasterGUID() == player->GetGUID())
        return true;

    // Don't allow loot for players without profession or those who already know the recipe
    if (pProto->HasFlag(ITEM_FLAG_HIDE_UNUSABLE_RECIPE))
    {
        if (!player->HasSkill(pProto->GetRequiredSkill()))
            return false;

        for (ItemEffectEntry const* itemEffect : pProto->Effects)
        {
            if (itemEffect->TriggerType != ITEM_SPELLTRIGGER_ON_LEARN)
                continue;

            if (player->HasSpell(itemEffect->SpellID))
                return false;
        }
    }

    // check quest requirements
    if (!pProto->HasFlag(ITEM_FLAGS_CU_IGNORE_QUEST_STATUS) && ((needs_quest || (pProto->GetStartQuest() && player->GetQuestStatus(pProto->GetStartQuest()) != QUEST_STATUS_NONE)) && !player->HasQuestForItem(itemid)))
        return false;

    if (strictUsabilityCheck)
    {
        if ((pProto->IsWeapon() || pProto->IsArmor()) && !pProto->IsUsableByLootSpecialization(player, true))
            return false;

        if (player->CanRollNeedForItem(pProto, nullptr, false) != EQUIP_ERR_OK)
            return false;
    }

    return true;
}

void LootItem::AddAllowedLooter(const Player* player)
{
    allowedGUIDs.insert(player->GetGUID());
}

bool LootItem::HasAllowedLooter(ObjectGuid const& looter) const
{
    return allowedGUIDs.find(looter) != allowedGUIDs.end();
}

Optional<LootSlotType> LootItem::GetUiTypeForPlayer(Player const* player, Loot const& loot) const
{
    if (is_looted)
        return {};

    if (allowedGUIDs.find(player->GetGUID()) == allowedGUIDs.end())
        return {};

    if (freeforall)
    {
        if (std::unique_ptr<NotNormalLootItemList> const* ffaItems = Trinity::Containers::MapGetValuePtr(loot.GetPlayerFFAItems(), player->GetGUID()))
        {
            auto ffaItemItr = std::find_if(ffaItems->get()->begin(), ffaItems->get()->end(), [&](NotNormalLootItem const& ffaItem)
            {
                return ffaItem.LootListId == LootListId;
            });
            if (ffaItemItr != ffaItems->get()->end() && !ffaItemItr->is_looted)
                return loot.GetLootMethod() == FREE_FOR_ALL ? LOOT_SLOT_TYPE_OWNER : LOOT_SLOT_TYPE_ALLOW_LOOT;
        }
        return {};
    }

    if (needs_quest && !follow_loot_rules)
        return loot.GetLootMethod() == FREE_FOR_ALL ? LOOT_SLOT_TYPE_OWNER : LOOT_SLOT_TYPE_ALLOW_LOOT;

    switch (loot.GetLootMethod())
    {
        case FREE_FOR_ALL:
            return LOOT_SLOT_TYPE_OWNER;
        case ROUND_ROBIN:
            if (!loot.roundRobinPlayer.IsEmpty() && loot.roundRobinPlayer != player->GetGUID())
                return {};

            return LOOT_SLOT_TYPE_ALLOW_LOOT;
        case MASTER_LOOT:
            if (is_underthreshold)
            {
                if (!loot.roundRobinPlayer.IsEmpty() && loot.roundRobinPlayer != player->GetGUID())
                    return {};

                return LOOT_SLOT_TYPE_ALLOW_LOOT;
            }

            return loot.GetLootMasterGUID() == player->GetGUID() ? LOOT_SLOT_TYPE_MASTER : LOOT_SLOT_TYPE_LOCKED;
        case GROUP_LOOT:
        case NEED_BEFORE_GREED:
            if (is_underthreshold)
                if (!loot.roundRobinPlayer.IsEmpty() && loot.roundRobinPlayer != player->GetGUID())
                    return {};

            if (is_blocked)
                return LOOT_SLOT_TYPE_ROLL_ONGOING;

            if (rollWinnerGUID.IsEmpty()) // all passed
                return LOOT_SLOT_TYPE_ALLOW_LOOT;

            if (rollWinnerGUID == player->GetGUID())
                return LOOT_SLOT_TYPE_OWNER;

            return {};
        case PERSONAL_LOOT:
            return LOOT_SLOT_TYPE_OWNER;
        default:
            break;
    }

    return {};
}

//
// ------- Loot Roll -------
//

// Send the roll for the whole group
void LootRoll::SendStartRoll()
{
    ItemTemplate const* itemTemplate = ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(m_lootItem->itemid));
    for (auto const& [playerGuid, roll] : m_rollVoteMap)
    {
        if (roll.Vote != RollVote::NotEmitedYet)
            continue;

        Player* player = ObjectAccessor::GetPlayer(m_map, playerGuid);
        if (!player)
            continue;

        WorldPackets::Loot::StartLootRoll startLootRoll;
        startLootRoll.LootObj = m_loot->GetGUID();
        startLootRoll.MapID = m_map->GetId();
        startLootRoll.RollTime = LOOT_ROLL_TIMEOUT;
        startLootRoll.Method = m_loot->GetLootMethod();
        startLootRoll.ValidRolls = m_voteMask;
        // In NEED_BEFORE_GREED need disabled for non-usable item for player
        if (m_loot->GetLootMethod() == NEED_BEFORE_GREED && player->CanRollNeedForItem(itemTemplate, m_map, true) != EQUIP_ERR_OK)
            startLootRoll.ValidRolls &= ~ROLL_FLAG_TYPE_NEED;

        FillPacket(startLootRoll.Item);
        startLootRoll.Item.UIType = LOOT_SLOT_TYPE_ROLL_ONGOING;
        startLootRoll.DungeonEncounterID = m_loot->GetDungeonEncounterId();

        player->SendDirectMessage(startLootRoll.Write());
    }

    // Handle auto pass option
    for (auto const& [playerGuid, roll] : m_rollVoteMap)
    {
        if (roll.Vote != RollVote::Pass)
            continue;

        SendRoll(playerGuid, -1, RollVote::Pass, {});
    }
}

// Send all passed message
void LootRoll::SendAllPassed()
{
    WorldPackets::Loot::LootAllPassed lootAllPassed;
    lootAllPassed.LootObj = m_loot->GetGUID();
    FillPacket(lootAllPassed.Item);
    lootAllPassed.Item.UIType = LOOT_SLOT_TYPE_ALLOW_LOOT;
    lootAllPassed.DungeonEncounterID = m_loot->GetDungeonEncounterId();
    lootAllPassed.Write();

    for (auto const& [playerGuid, roll] : m_rollVoteMap)
    {
        if (roll.Vote != RollVote::NotValid)
            continue;

        Player* player = ObjectAccessor::GetPlayer(m_map, playerGuid);
        if (!player)
            continue;

        player->SendDirectMessage(lootAllPassed.GetRawPacket());
    }
}

// Send roll of targetGuid to the whole group (included targuetGuid)
void LootRoll::SendRoll(ObjectGuid const& targetGuid, int32 rollNumber, RollVote rollType, Optional<ObjectGuid> const& rollWinner)
{
    WorldPackets::Loot::LootRollBroadcast lootRoll;
    lootRoll.LootObj = m_loot->GetGUID();
    lootRoll.Player = targetGuid;
    lootRoll.Roll = rollNumber;
    lootRoll.RollType = AsUnderlyingType(rollType);
    lootRoll.Autopassed = false;
    FillPacket(lootRoll.Item);
    lootRoll.Item.UIType = LOOT_SLOT_TYPE_ROLL_ONGOING;
    lootRoll.DungeonEncounterID = m_loot->GetDungeonEncounterId();
    lootRoll.Write();

    for (auto const& [playerGuid, roll] : m_rollVoteMap)
    {
        if (roll.Vote == RollVote::NotValid)
            continue;

        if (playerGuid == rollWinner)
            continue;

        Player* player = ObjectAccessor::GetPlayer(m_map, playerGuid);
        if (!player)
            continue;

        player->SendDirectMessage(lootRoll.GetRawPacket());
    }

    if (rollWinner)
    {
        if (Player* player = ObjectAccessor::GetPlayer(m_map, *rollWinner))
        {
            lootRoll.Item.UIType = LOOT_SLOT_TYPE_ALLOW_LOOT;
            lootRoll.Clear();
            player->SendDirectMessage(lootRoll.Write());
        }
    }
}

// Send roll 'value' of the whole group and the winner to the whole group
void LootRoll::SendLootRollWon(ObjectGuid const& targetGuid, int32 rollNumber, RollVote rollType)
{
    // Send roll values
    for (auto const& [playerGuid, roll] : m_rollVoteMap)
    {
        switch (roll.Vote)
        {
            case RollVote::Pass:
                break;
            case RollVote::NotEmitedYet:
            case RollVote::NotValid:
                SendRoll(playerGuid, 0, RollVote::Pass, targetGuid);
                break;
            default:
                SendRoll(playerGuid, roll.RollNumber, roll.Vote, targetGuid);
                break;
        }
    }

    WorldPackets::Loot::LootRollWon lootRollWon;
    lootRollWon.LootObj = m_loot->GetGUID();
    lootRollWon.Winner = targetGuid;
    lootRollWon.Roll = rollNumber;
    lootRollWon.RollType = AsUnderlyingType(rollType);
    FillPacket(lootRollWon.Item);
    lootRollWon.Item.UIType = LOOT_SLOT_TYPE_LOCKED;
    lootRollWon.DungeonEncounterID = m_loot->GetDungeonEncounterId();
    lootRollWon.MainSpec = true;    // offspec rolls not implemented
    lootRollWon.Write();

    for (auto const& [playerGuid, roll] : m_rollVoteMap)
    {
        if (roll.Vote == RollVote::NotValid)
            continue;

        if (playerGuid == targetGuid)
            continue;

        Player* player = ObjectAccessor::GetPlayer(m_map, playerGuid);
        if (!player)
            continue;

        player->SendDirectMessage(lootRollWon.GetRawPacket());
    }

    if (Player* player = ObjectAccessor::GetPlayer(m_map, targetGuid))
    {
        lootRollWon.Item.UIType = LOOT_SLOT_TYPE_ALLOW_LOOT;
        lootRollWon.Clear();
        player->SendDirectMessage(lootRollWon.Write());
    }
}

void LootRoll::FillPacket(WorldPackets::Loot::LootItemData& lootItem) const
{
    lootItem.Quantity = m_lootItem->count;
    lootItem.LootListID = m_lootItem->LootListId;
    lootItem.CanTradeToTapList = m_lootItem->allowedGUIDs.size() > 1;
    lootItem.Loot.Initialize(*m_lootItem);
}

LootRoll::~LootRoll()
{
    if (m_isStarted)
        SendAllPassed();

    for (auto const& [playerGuid, roll] : m_rollVoteMap)
    {
        if (roll.Vote != RollVote::NotEmitedYet)
            continue;

        Player* player = ObjectAccessor::GetPlayer(m_map, playerGuid);
        if (!player)
            continue;

        player->RemoveLootRoll(this);
    }
}

// Try to start the group roll for the specified item (it may fail for quest item or any condition
// If this method return false the roll have to be removed from the container to avoid any problem
bool LootRoll::TryToStart(Map* map, Loot& loot, uint32 lootListId, uint16 enchantingSkill)
{
    if (!m_isStarted)
    {
        if (lootListId >= loot.items.size())
            return false;

        m_map = map;

        // initialize the data needed for the roll
        m_lootItem = &loot.items[lootListId];

        m_loot = &loot;
        m_lootItem->is_blocked = true;                          // block the item while rolling

        uint32 playerCount = 0;
        for (ObjectGuid allowedLooter : m_lootItem->GetAllowedLooters())
        {
            Player* plr = ObjectAccessor::GetPlayer(m_map, allowedLooter);
            if (!plr || !m_lootItem->HasAllowedLooter(plr->GetGUID()))     // check if player meet the condition to be able to roll this item
            {
                m_rollVoteMap[allowedLooter].Vote = RollVote::NotValid;
                continue;
            }
            // initialize player vote map
            m_rollVoteMap[allowedLooter].Vote = plr->GetPassOnGroupLoot() ? RollVote::Pass : RollVote::NotEmitedYet;
            if (!plr->GetPassOnGroupLoot())
                plr->AddLootRoll(this);

            ++playerCount;
        }

        // initialize item prototype and check enchant possibilities for this group
        ItemTemplate const* itemTemplate = ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(m_lootItem->itemid));
        m_voteMask = ROLL_ALL_TYPE_MASK;
        if (itemTemplate->HasFlag(ITEM_FLAG2_CAN_ONLY_ROLL_GREED))
            m_voteMask = RollMask(m_voteMask & ~ROLL_FLAG_TYPE_NEED);
        if (ItemDisenchantLootEntry const* disenchant = GetItemDisenchantLoot(); !disenchant || disenchant->SkillRequired > enchantingSkill)
            m_voteMask = RollMask(m_voteMask & ~ROLL_FLAG_TYPE_DISENCHANT);

        if (playerCount > 1)                                    // check if more than one player can loot this item
        {
            // start the roll
            SendStartRoll();
            m_endTime = GameTime::Now() + LOOT_ROLL_TIMEOUT;
            m_isStarted = true;
            return true;
        }
        // no need to start roll if one or less player can loot this item so place it under threshold
        m_lootItem->is_underthreshold = true;
        m_lootItem->is_blocked = false;
    }
    return false;
}

// Add vote from playerGuid
bool LootRoll::PlayerVote(Player* player, RollVote vote)
{
    ObjectGuid const& playerGuid = player->GetGUID();
    RollVoteMap::iterator voterItr = m_rollVoteMap.find(playerGuid);
    if (voterItr == m_rollVoteMap.end())
        return false;

    voterItr->second.Vote = vote;

    if (vote != RollVote::Pass && vote != RollVote::NotValid)
        voterItr->second.RollNumber = urand(1, 100);

    switch (vote)
    {
        case RollVote::Pass:                                // Player choose pass
        {
            SendRoll(playerGuid, -1, RollVote::Pass, {});
            break;
        }
        case RollVote::Need:                                // player choose Need
        {
            SendRoll(playerGuid, 0, RollVote::Need, {});
            player->UpdateCriteria(CriteriaType::RollAnyNeed, 1);
            break;
        }
        case RollVote::Greed:                               // player choose Greed
        {
            SendRoll(playerGuid, -1, RollVote::Greed, {});
            player->UpdateCriteria(CriteriaType::RollAnyGreed, 1);
            break;
        }
        case RollVote::Disenchant:                          // player choose Disenchant
        {
            SendRoll(playerGuid, -1, RollVote::Disenchant, {});
            player->UpdateCriteria(CriteriaType::RollAnyGreed, 1);
            break;
        }
        default:                                            // Roll removed case
            return false;
    }
    return true;
}

// check if we can found a winner for this roll or if timer is expired
bool LootRoll::UpdateRoll()
{
    RollVoteMap::const_iterator winnerItr = m_rollVoteMap.end();

    if (AllPlayerVoted(winnerItr) || m_endTime <= GameTime::Now())
    {
        Finish(winnerItr);
        return true;
    }
    return false;
}

bool LootRoll::IsLootItem(ObjectGuid const& lootObject, uint32 lootListId) const
{
    return m_loot->GetGUID() == lootObject && m_lootItem->LootListId == lootListId;
}

/**
* \brief Check if all player have voted and return true in that case. Also return current winner.
* \param winnerItr > will be different than m_rollCoteMap.end() if winner exist. (Someone voted greed or need)
* \returns true if all players voted
**/
bool LootRoll::AllPlayerVoted(RollVoteMap::const_iterator& winnerItr)
{
    uint32 notVoted = 0;
    bool isSomeoneNeed = false;

    winnerItr = m_rollVoteMap.end();
    for (RollVoteMap::const_iterator itr = m_rollVoteMap.begin(); itr != m_rollVoteMap.end(); ++itr)
    {
        switch (itr->second.Vote)
        {
            case RollVote::Need:
                if (!isSomeoneNeed || winnerItr == m_rollVoteMap.end() || itr->second.RollNumber > winnerItr->second.RollNumber)
                {
                    isSomeoneNeed = true;                                               // first passage will force to set winner because need is prioritized
                    winnerItr = itr;
                }
                break;
            case RollVote::Greed:
            case RollVote::Disenchant:
                if (!isSomeoneNeed)                                                      // if at least one need is detected then winner can't be a greed
                {
                    if (winnerItr == m_rollVoteMap.end() || itr->second.RollNumber > winnerItr->second.RollNumber)
                        winnerItr = itr;
                }
                break;
            // Explicitly passing excludes a player from winning loot, so no action required.
            case RollVote::Pass:
                break;
            case RollVote::NotEmitedYet:
                ++notVoted;
                break;
            default:
                break;
        }
    }

    return notVoted == 0;
}

ItemDisenchantLootEntry const* LootRoll::GetItemDisenchantLoot() const
{
    WorldPackets::Item::ItemInstance itemInstance;
    itemInstance.Initialize(*m_lootItem);

    BonusData bonusData;
    bonusData.Initialize(itemInstance);
    if (!bonusData.CanDisenchant)
        return nullptr;

    ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(m_lootItem->itemid);
    uint32 itemLevel = Item::GetItemLevel(itemTemplate, bonusData, 1, 0, 0, 0, 0, false, 0);
    return Item::GetDisenchantLoot(itemTemplate, bonusData.Quality, itemLevel);
}

// terminate the roll
void LootRoll::Finish(RollVoteMap::const_iterator winnerItr)
{
    m_lootItem->is_blocked = false;
    if (winnerItr == m_rollVoteMap.end())
    {
        SendAllPassed();
    }
    else
    {
        m_lootItem->rollWinnerGUID = winnerItr->first;

        SendLootRollWon(winnerItr->first, winnerItr->second.RollNumber, winnerItr->second.Vote);

        if (Player* player = ObjectAccessor::FindConnectedPlayer(winnerItr->first))
        {
            if (winnerItr->second.Vote == RollVote::Need)
                player->UpdateCriteria(CriteriaType::RollNeed, m_lootItem->itemid, winnerItr->second.RollNumber);
            else if (winnerItr->second.Vote == RollVote::Disenchant)
                player->UpdateCriteria(CriteriaType::CastSpell, 13262);
            else
                player->UpdateCriteria(CriteriaType::RollGreed, m_lootItem->itemid, winnerItr->second.RollNumber);

            if (winnerItr->second.Vote == RollVote::Disenchant)
            {
                ItemDisenchantLootEntry const* disenchant = ASSERT_NOTNULL(GetItemDisenchantLoot());
                Loot loot(m_map, m_loot->GetOwnerGUID(), LOOT_DISENCHANTING, nullptr);
                loot.FillLoot(disenchant->ID, LootTemplates_Disenchant, player, true, false, LOOT_MODE_DEFAULT, ItemContext::NONE);
                if (!loot.AutoStore(player, NULL_BAG, NULL_SLOT, true))
                {
                    for (uint32 i = 0; i < loot.items.size(); ++i)
                        if (LootItem* disenchantLoot = loot.LootItemInSlot(i, player))
                            player->SendItemRetrievalMail(disenchantLoot->itemid, disenchantLoot->count, disenchantLoot->context);
                }
                else
                    m_loot->NotifyItemRemoved(m_lootItem->LootListId, m_map);
            }
            else
                player->StoreLootItem(m_loot->GetOwnerGUID(), m_lootItem->LootListId, m_loot);
        }
    }
    m_isStarted = false;
}

//
// --------- Loot ---------
//

Loot::Loot(Map* map, ObjectGuid owner, LootType type, Group const* group) : gold(0), unlootedCount(0), loot_type(type),
    _guid(map ? ObjectGuid::Create<HighGuid::LootObject>(map->GetId(), 0, map->GenerateLowGuid<HighGuid::LootObject>()) : ObjectGuid::Empty),
    _owner(owner), _itemContext(ItemContext::NONE), _lootMethod(group ? group->GetLootMethod() : FREE_FOR_ALL),
    _lootMaster(group ? group->GetMasterLooterGuid() : ObjectGuid::Empty), _wasOpened(false), _changed(false), _dungeonEncounterId(0)
{
}

Loot::~Loot()
{
    GuidSet activeLooters = std::move(PlayersLooting);
    for (ObjectGuid playerGuid : activeLooters)
        if (Player* player = ObjectAccessor::FindConnectedPlayer(playerGuid))
            player->GetSession()->DoLootRelease(this);
}

void Loot::NotifyLootList(Map const* map) const
{
    WorldPackets::Loot::LootList lootList;

    lootList.Owner = GetOwnerGUID();
    lootList.LootObj = GetGUID();

    if (GetLootMethod() == MASTER_LOOT && hasOverThresholdItem())
        lootList.Master = GetLootMasterGUID();

    if (!roundRobinPlayer.IsEmpty())
        lootList.RoundRobinWinner = roundRobinPlayer;

    lootList.Write();

    for (ObjectGuid allowedLooterGuid : _allowedLooters)
        if (Player* allowedLooter = ObjectAccessor::GetPlayer(map, allowedLooterGuid))
            allowedLooter->SendDirectMessage(lootList.GetRawPacket());
}

void Loot::NotifyItemRemoved(uint8 lootListId, Map const* map)
{
    // notify all players that are looting this that the item was removed
    // convert the index to the slot the player sees
    for (auto itr = PlayersLooting.begin(); itr != PlayersLooting.end();)
    {
        LootItem const& item = items[lootListId];
        if (item.GetAllowedLooters().find(*itr) == item.GetAllowedLooters().end())
        {
            ++itr;
            continue;
        }

        if (Player* player = ObjectAccessor::GetPlayer(map, *itr))
        {
            player->SendNotifyLootItemRemoved(GetGUID(), GetOwnerGUID(), lootListId);
            ++itr;
        }
        else
            itr = PlayersLooting.erase(itr);
    }
}

void Loot::NotifyMoneyRemoved(Map const* map)
{
    // notify all players that are looting this that the money was removed
    for (auto itr = PlayersLooting.begin(); itr != PlayersLooting.end();)
    {
        if (Player* player = ObjectAccessor::GetPlayer(map, *itr))
        {
            player->SendNotifyLootMoneyRemoved(GetGUID());
            ++itr;
        }
        else
            itr = PlayersLooting.erase(itr);
    }
}

void Loot::OnLootOpened(Map* map, ObjectGuid looter)
{
    AddLooter(looter);
    if (!_wasOpened)
    {
        _wasOpened = true;

        if (_lootMethod == GROUP_LOOT || _lootMethod == NEED_BEFORE_GREED)
        {
            uint16 maxEnchantingSkill = 0;
            for (ObjectGuid allowedLooterGuid : _allowedLooters)
                if (Player* allowedLooter = ObjectAccessor::GetPlayer(map, allowedLooterGuid))
                    maxEnchantingSkill = std::max(maxEnchantingSkill, allowedLooter->GetSkillValue(SKILL_ENCHANTING));

            for (uint32 lootListId = 0; lootListId < items.size(); ++lootListId)
            {
                LootItem& item = items[lootListId];
                if (!item.is_blocked)
                    continue;

                auto&& [itr, inserted] = _rolls.try_emplace(lootListId);
                if (!itr->second.TryToStart(map, *this, lootListId, maxEnchantingSkill))
                    _rolls.erase(itr);
            }

            if (!_rolls.empty())
                _changed = true;
        }
        else if (_lootMethod == MASTER_LOOT)
        {
            if (looter == _lootMaster)
            {
                if (Player* lootMaster = ObjectAccessor::GetPlayer(map, looter))
                {
                    WorldPackets::Loot::MasterLootCandidateList masterLootCandidateList;
                    masterLootCandidateList.LootObj = GetGUID();
                    masterLootCandidateList.Players = _allowedLooters;
                    lootMaster->SendDirectMessage(masterLootCandidateList.Write());
                }
            }
        }
    }
}

bool Loot::HasAllowedLooter(ObjectGuid const& looter) const
{
    return _allowedLooters.find(looter) != _allowedLooters.end();
}

void Loot::generateMoneyLoot(uint32 minAmount, uint32 maxAmount)
{
    if (maxAmount > 0)
    {
        if (maxAmount <= minAmount)
            gold = uint32(maxAmount * sWorld->getRate(RATE_DROP_MONEY));
        else if ((maxAmount - minAmount) < 32700)
            gold = uint32(urand(minAmount, maxAmount) * sWorld->getRate(RATE_DROP_MONEY));
        else
            gold = uint32(urand(minAmount >> 8, maxAmount >> 8) * sWorld->getRate(RATE_DROP_MONEY)) << 8;
    }
}

// Calls processor of corresponding LootTemplate (which handles everything including references)
bool Loot::FillLoot(uint32 lootId, LootStore const& store, Player* lootOwner, bool personal, bool noEmptyError, uint16 lootMode /*= LOOT_MODE_DEFAULT*/, ItemContext context /*= ItemContext::NONE*/)
{
    // Must be provided
    if (!lootOwner)
        return false;

    LootTemplate const* tab = store.GetLootFor(lootId);

    if (!tab)
    {
        if (!noEmptyError)
            TC_LOG_ERROR("sql.sql", "Table '{}' loot id #{} used but it doesn't have records.", store.GetName(), lootId);
        return false;
    }

    _itemContext = context;

    items.reserve(MAX_NR_LOOT_ITEMS);

    tab->Process(*this, store.IsRatesAllowed(), lootMode, 0);    // Processing is done there, callback via Loot::AddItem()

    // Setting access rights for group loot case
    Group const* group = lootOwner->GetGroup();
    if (!personal && group)
    {
        if (loot_type == LOOT_CORPSE)
            roundRobinPlayer = lootOwner->GetGUID();

        for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            if (Player const* player = itr->GetSource())    // should actually be looted object instead of lootOwner but looter has to be really close so doesnt really matter
                if (player->IsAtGroupRewardDistance(lootOwner))
                    FillNotNormalLootFor(player);

        for (LootItem& item : items)
        {
            if (!item.follow_loot_rules || item.freeforall)
                continue;

            if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item.itemid))
            {
                if (proto->GetQuality() < uint32(group->GetLootThreshold()))
                    item.is_underthreshold = true;
                else
                {
                    switch (_lootMethod)
                    {
                        case MASTER_LOOT:
                        case GROUP_LOOT:
                        case NEED_BEFORE_GREED:
                        {
                            item.is_blocked = true;
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        }
    }
    // ... for personal loot
    else
        FillNotNormalLootFor(lootOwner);

    return true;
}

// Inserts the item into the loot (called by LootTemplate processors)
void Loot::AddItem(LootStoreItem const& item)
{
    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item.itemid);
    if (!proto)
        return;

    uint32 count = urand(item.mincount, item.maxcount);
    uint32 stacks = count / proto->GetMaxStackSize() + ((count % proto->GetMaxStackSize()) ? 1 : 0);

    for (uint32 i = 0; i < stacks && items.size() < MAX_NR_LOOT_ITEMS; ++i)
    {
        LootItem generatedLoot(item);
        generatedLoot.context = _itemContext;
        generatedLoot.count = std::min(count, proto->GetMaxStackSize());
        generatedLoot.LootListId = items.size();
        generatedLoot.BonusListIDs = ItemBonusMgr::GetBonusListsForItem(generatedLoot.itemid, _itemContext);

        items.push_back(generatedLoot);
        count -= proto->GetMaxStackSize();
    }
}

bool Loot::AutoStore(Player* player, uint8 bag, uint8 slot, bool broadcast, bool createdByPlayer)
{
    bool allLooted = true;
    for (uint32 i = 0; i < items.size(); ++i)
    {
        NotNormalLootItem* ffaitem = nullptr;

        LootItem* lootItem = LootItemInSlot(i, player, &ffaitem);
        if (!lootItem || lootItem->is_looted)
            continue;

        if (!lootItem->HasAllowedLooter(player->GetGUID()))
            continue;

        if (lootItem->is_blocked)
            continue;

        // dont allow protected item to be looted by someone else
        if (!lootItem->rollWinnerGUID.IsEmpty() && lootItem->rollWinnerGUID != GetGUID())
            continue;

        ItemPosCountVec dest;
        InventoryResult msg = player->CanStoreNewItem(bag, slot, dest, lootItem->itemid, lootItem->count);
        if (msg != EQUIP_ERR_OK && slot != NULL_SLOT)
            msg = player->CanStoreNewItem(bag, NULL_SLOT, dest, lootItem->itemid, lootItem->count);
        if (msg != EQUIP_ERR_OK && bag != NULL_BAG)
            msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, lootItem->itemid, lootItem->count);
        if (msg != EQUIP_ERR_OK)
        {
            player->SendEquipError(msg, nullptr, nullptr, lootItem->itemid);
            allLooted = false;
            continue;
        }

        if (ffaitem)
            ffaitem->is_looted = true;

        if (!lootItem->freeforall)
            lootItem->is_looted = true;

        --unlootedCount;

        if (Item* pItem = player->StoreNewItem(dest, lootItem->itemid, true, lootItem->randomBonusListId, GuidSet(), lootItem->context, &lootItem->BonusListIDs))
        {
            player->SendNewItem(pItem, lootItem->count, false, createdByPlayer, broadcast, GetDungeonEncounterId());
            player->ApplyItemLootedSpell(pItem, true);
        }
        else
            player->ApplyItemLootedSpell(sObjectMgr->GetItemTemplate(lootItem->itemid));
    }

    return allLooted;
}

void Loot::LootMoney()
{
    gold = 0;
    _changed = true;
}

LootItem const* Loot::GetItemInSlot(uint32 lootListId) const
{
    if (lootListId < items.size())
        return &items[lootListId];

    return nullptr;
}

LootItem* Loot::LootItemInSlot(uint32 lootListId, Player const* player, NotNormalLootItem** ffaItem)
{
    if (lootListId >= items.size())
        return nullptr;

    LootItem* item = &items[lootListId];
    bool is_looted = item->is_looted;

    if (item->freeforall)
    {
        auto itr = PlayerFFAItems.find(player->GetGUID());
        if (itr != PlayerFFAItems.end())
        {
            for (NotNormalLootItem& notNormalLootItem : *itr->second)
            {
                if (notNormalLootItem.LootListId == lootListId)
                {
                    is_looted = notNormalLootItem.is_looted;
                    if (ffaItem)
                        *ffaItem = &notNormalLootItem;

                    break;
                }
            }
        }
    }

    if (is_looted)
        return nullptr;

    _changed = true;
    return item;
}

// return true if there is any item that is lootable for any player (not quest item, FFA or conditional)
bool Loot::hasItemForAll() const
{
    // Gold is always lootable
    if (gold)
        return true;

    for (LootItem const& item : items)
        if (!item.is_looted && item.follow_loot_rules && !item.freeforall && item.conditions.empty())
            return true;
    return false;
}

// return true if there is any FFA, quest or conditional item for the player.
bool Loot::hasItemFor(Player const* player) const
{
    // quest items
    for (LootItem const& lootItem : items)
        if (!lootItem.is_looted && !lootItem.follow_loot_rules && lootItem.GetAllowedLooters().find(player->GetGUID()) != lootItem.GetAllowedLooters().end())
            return true;

    if (std::unique_ptr<NotNormalLootItemList> const* ffaItems = Trinity::Containers::MapGetValuePtr(GetPlayerFFAItems(), player->GetGUID()))
    {
        bool hasFfaItem = std::any_of(ffaItems->get()->begin(), ffaItems->get()->end(), [&](NotNormalLootItem const& ffaItem)
        {
            return !ffaItem.is_looted;
        });
        if (hasFfaItem)
            return true;
    }

    return false;
}

// return true if there is any item over the group threshold (i.e. not underthreshold).
bool Loot::hasOverThresholdItem() const
{
    for (uint8 i = 0; i < items.size(); ++i)
    {
        if (!items[i].is_looted && !items[i].is_underthreshold && !items[i].freeforall)
            return true;
    }

    return false;
}

void Loot::BuildLootResponse(WorldPackets::Loot::LootResponse& packet, Player const* viewer) const
{
    packet.Coins = gold;

    for (LootItem const& item : items)
    {
        Optional<LootSlotType> uiType = item.GetUiTypeForPlayer(viewer, *this);
        if (!uiType)
            continue;

        WorldPackets::Loot::LootItemData& lootItem = packet.Items.emplace_back();
        lootItem.LootListID = item.LootListId;
        lootItem.UIType = *uiType;
        lootItem.Quantity = item.count;
        lootItem.Loot.Initialize(item);
    }
}

void Loot::Update()
{
    for (auto itr = _rolls.begin(); itr != _rolls.end(); )
    {
        if (itr->second.UpdateRoll())
            itr = _rolls.erase(itr);
        else
            ++itr;
    }
}

void Loot::FillNotNormalLootFor(Player const* player)
{
    ObjectGuid plguid = player->GetGUID();
    _allowedLooters.insert(plguid);

    std::unique_ptr<NotNormalLootItemList> ffaItems = std::make_unique<NotNormalLootItemList>();

    for (LootItem& item : items)
    {
        if (!item.AllowedForPlayer(player, this))
            continue;

        item.AddAllowedLooter(player);

        if (item.freeforall)
        {
            ffaItems->emplace_back(item.LootListId);
            ++unlootedCount;
        }
        else if (!item.is_counted)
        {
            item.is_counted = true;
            ++unlootedCount;
        }
    }

    if (!ffaItems->empty())
        PlayerFFAItems[player->GetGUID()] = std::move(ffaItems);
}

//
// --------- AELootResult ---------
//

void AELootResult::Add(Item* item, uint8 count, LootType lootType, uint32 dungeonEncounterId)
{
    auto itr = _byItem.find(item);
    if (itr != _byItem.end())
        _byOrder[itr->second].count += count;
    else
    {
        _byItem[item] = _byOrder.size();
        ResultValue value;
        value.item = item;
        value.count = count;
        value.lootType = lootType;
        value.dungeonEncounterId = dungeonEncounterId;
        _byOrder.push_back(value);
    }
}

AELootResult::OrderedStorage::const_iterator AELootResult::begin() const
{
    return _byOrder.begin();
}

AELootResult::OrderedStorage::const_iterator AELootResult::end() const
{
    return _byOrder.end();
}
