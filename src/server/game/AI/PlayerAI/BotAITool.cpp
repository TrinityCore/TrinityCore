#include "World.h"
#include "WorldPacket.h"
#include "DB2Structure.h"
#include "BotAITool.h"
#include "Pet.h"
#include "PlayerBotSession.h"
#include "Map.h"
#include "Group.h"
#include "BotBGAIMovement.h"
#include "Language.h"
#include "Guild.h"
#include "SpellAuras.h"
#include "WorldSession.h"

#include "Cell.h"
#include "CellImpl.h"
#include "GridDefines.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "MiscPackets.h"
#include "Packets/AllPackets.h"
#include <Battleground.h>
#include "SpellInfo.h"
#include "g3d/Vector3.h"

float BotUtility::BattlegroundScoreRate = 1.0f;
float BotUtility::DungeonBotDamageModify = 1.0f;
float BotUtility::DungeonBotEndureModify = 1.0f;
bool BotUtility::BotCanForceRevive = false;
bool BotUtility::BotCanSettingToMaster = true;
int32 BotUtility::BotCritTakenAddion = 1;
bool BotUtility::ControllSpellDiminishing = true;
bool BotUtility::ControllSpellFromDmgBreak = true;
bool BotUtility::DownBotArenaTeam = false;
bool BotUtility::ArenaIsHell = false;
uint32 BotUtility::BotArenaTeamTactics = 1;
bool BotUtility::DisableDKQuest = false;


void BotUtility::AddArenaBotSpellsByPlayer(Player* player)
{
    if (!player)
        return;

    //   ObjectGuid castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, GetMapId(), spellInfo->Id, GetMap()->GenerateLowGuid<HighGuid::Cast>());
    //   //todo47
       //if (!player->HasAura(ARENA_PLAYER_BOT_AURA))
       //{
       //	if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ARENA_PLAYER_BOT_AURA))
       //		Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, player, player);
       //}
       //if (!BotUtility::ArenaIsHell)
       //	return;
       //switch (player->getClass())
       //{
       //case Classes::CLASS_WARRIOR:
       //	if (!player->HasAura(ARENA_WARRIOR_BOT_AURA))
       //	{
       //		if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ARENA_WARRIOR_BOT_AURA))
       //			Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, player, player);
       //	}
       //	break;
       //case Classes::CLASS_PALADIN:
       //	if (!player->HasAura(ARENA_PALADIN_BOT_AURA))
       //	{
       //		if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ARENA_PALADIN_BOT_AURA))
       //			Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, player, player);
       //	}
       //	break;
       //case Classes::CLASS_ROGUE:
       //	if (!player->HasAura(ARENA_ROGUE_BOT_AURA))
       //	{
       //		if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ARENA_ROGUE_BOT_AURA))
       //			Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, player, player);
       //	}
       //	break;
       //case Classes::CLASS_DRUID:
       //	if (!player->HasAura(ARENA_DRUID_BOT_AURA))
       //	{
       //		if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ARENA_DRUID_BOT_AURA))
       //			Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, player, player);
       //	}
       //	break;
       //case Classes::CLASS_HUNTER:
       //	if (!player->HasAura(ARENA_HUNTER_BOT_AURA))
       //	{
       //		if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ARENA_HUNTER_BOT_AURA))
       //			Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, player, player);
       //	}
       //	break;
       //case Classes::CLASS_SHAMAN:
       //	if (!player->HasAura(ARENA_SHAMAN_BOT_AURA))
       //	{
       //		if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ARENA_SHAMAN_BOT_AURA))
       //			Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, player, player);
       //	}
       //	break;
       //case Classes::CLASS_MAGE:
       //	if (!player->HasAura(ARENA_MAGE_BOT_AURA))
       //	{
       //		if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ARENA_MAGE_BOT_AURA))
       //			Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, player, player);
       //	}
       //	break;
       //case Classes::CLASS_WARLOCK:
       //	if (!player->HasAura(ARENA_WARLOCK_BOT_AURA))
       //	{
       //		if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ARENA_WARLOCK_BOT_AURA))
       //			Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, player, player);
       //	}
       //	break;
       //case Classes::CLASS_PRIEST:
       //	if (!player->HasAura(ARENA_PRIEST_BOT_AURA))
       //	{
       //		if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ARENA_PRIEST_BOT_AURA))
       //			Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, player, player);
       //	}
       //	break;
       //}

}

void BotUtility::RemoveArenaBotSpellsByPlayer(Player* player)
{
    if (!player)
        return;
    if (player->HasAura(ARENA_PLAYER_BOT_AURA))
        player->RemoveOwnedAura(ARENA_PLAYER_BOT_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (player->HasAura(ARENA_WARRIOR_BOT_AURA))
        player->RemoveOwnedAura(ARENA_WARRIOR_BOT_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (player->HasAura(ARENA_PALADIN_BOT_AURA))
        player->RemoveOwnedAura(ARENA_PALADIN_BOT_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (player->HasAura(ARENA_ROGUE_BOT_AURA))
        player->RemoveOwnedAura(ARENA_ROGUE_BOT_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (player->HasAura(ARENA_DRUID_BOT_AURA))
        player->RemoveOwnedAura(ARENA_DRUID_BOT_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (player->HasAura(ARENA_HUNTER_BOT_AURA))
        player->RemoveOwnedAura(ARENA_HUNTER_BOT_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (player->HasAura(ARENA_SHAMAN_BOT_AURA))
        player->RemoveOwnedAura(ARENA_SHAMAN_BOT_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (player->HasAura(ARENA_MAGE_BOT_AURA))
        player->RemoveOwnedAura(ARENA_MAGE_BOT_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (player->HasAura(ARENA_WARLOCK_BOT_AURA))
        player->RemoveOwnedAura(ARENA_WARLOCK_BOT_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (player->HasAura(ARENA_PRIEST_BOT_AURA))
        player->RemoveOwnedAura(ARENA_PRIEST_BOT_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
}

void BotUtility::TryCancelDuel(Player* player)
{
    if (!player || !player->duel)
        return;
    player->DuelComplete(DUEL_INTERRUPTED);
}

bool BotUtility::SpellHasReady(Player* player, uint32 spellID)
{
    if (!player || spellID == 0)
        return false;
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_NONE);
    if (!spellInfo || spellInfo->IsPassive())
        return false;
    if (player->GetSpellHistory()->HasGlobalCooldown(spellInfo))
        return false;
    if (player->GetSpellHistory()->IsReady(spellInfo))
        return true;
    return false;
}

uint32 BotUtility::GetFirstNumberByString(std::string& text)
{
    char numStr[21] = { 0 };
    char* pCur = numStr;
    const char* pText = text.c_str();
    int count = text.size();
    bool start = false;
    for (int i = 0; i < count; ++i)
    {
        char c = pText[i];
        if (c >= '0' && c <= '9')
        {
            start = true;
            *pCur = c;
            ++pCur;
        }
        else if (start)
            break;
    }
    return (uint32)atoi(numStr);
}

//std::string BotUtility::BuildItemLinkText(const ItemTemplate* pItemTemplate)
//{
//	if (!pItemTemplate)
//		return "";
//	std::string text = sObjectMgr->GetTrinityStringForDBCLocale(TrinityStrings::LANG_ITEM_LIST_CHAT);// , LocaleConstant::LOCALE_zhTW);
//	//return Trinity::StringFormat(text.c_str(), pItemTemplate->GetId(), pItemTemplate->GetId(), pItemTemplate->GetName(LOCALE_zhCN));//todo47
//}

void BotUtility::UpdatePlayerBotRoll(Player* player)
{
    if (!player)
        return;
    Group* pGroup = player->GetGroup();
    if (!pGroup)
        return;
    //tmp	Rolls& rolls = pGroup->GetAllRolls();
    //for (Rolls::iterator iter = rolls.begin(); iter != rolls.end(); ++iter)
    //{
    //	Roll* roll = (*iter);
    //	if (!roll->isValid())
    //		continue;
    //	if (roll->rolledPlayers.find(player->GetGUID()) != roll->rolledPlayers.end())
    //		continue;
    //	if (roll->totalPass > 0 || roll->totalNeed > 0 || roll->totalGreed > 0)
    //	{
    //		roll->rolledPlayers.insert(player->GetGUID());
    //		pGroup->PlayerBotRoll(player, *roll);
    //		break;
    //	}
    //}//tmp
}

Item* BotUtility::FindItemFromAllBag(Player* player, uint32 entry, bool destroy)
{
    if (!player || entry == 0)
        return NULL;
    for (uint8 slot = InventoryPackSlots::INVENTORY_SLOT_ITEM_START; slot < InventoryPackSlots::INVENTORY_SLOT_ITEM_END; slot++)
    {
        Item* pItem = player->GetItemByPos(255, slot);
        if (!pItem)
            continue;
        const ItemTemplate* pTemplate = pItem->GetTemplate();
        if (!pTemplate || pTemplate->GetId() != entry)
            continue;
        if (destroy)
        {
            player->DestroyItem(255, slot, true);
            pItem = NULL;
        }
        return pItem;
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = player->GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                Item* pItem = pBag->GetItemByPos(uint8(j));
                if (!pItem)
                    continue;
                const ItemTemplate* pTemplate = pItem->GetTemplate();
                if (!pTemplate || pTemplate->GetId() != entry)
                    continue;
                if (destroy)
                {
                    player->DestroyItem(255, uint8(j), true);
                    pItem = NULL;
                }
                return pItem;
            }
        }
    }
    return NULL;
}

Item* BotUtility::FindItemFromAllBag(Player* player, uint32 entry, uint8& bag, uint8& index)
{
    if (!player || entry == 0)
        return NULL;
    for (uint8 slot = InventoryPackSlots::INVENTORY_SLOT_ITEM_START; slot < InventoryPackSlots::INVENTORY_SLOT_ITEM_END; slot++)
    {
        Item* pItem = player->GetItemByPos(255, slot);
        if (!pItem)
            continue;
        const ItemTemplate* pTemplate = pItem->GetTemplate();
        if (!pTemplate || pTemplate->GetId() != entry)
            continue;
        bag = 255;
        index = slot;
        return pItem;
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = player->GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                Item* pItem = pBag->GetItemByPos(uint8(j));
                if (!pItem)
                    continue;
                const ItemTemplate* pTemplate = pItem->GetTemplate();
                if (!pTemplate || pTemplate->GetId() != entry)
                    continue;
                bag = i;
                index = uint8(j);
                return pItem;
            }
        }
    }
    return NULL;
}

bool BotUtility::DestroyItemFromAllBag(Player* player, Item* pItem)
{
    if (!player || !pItem)
        return false;
    for (uint8 slot = InventoryPackSlots::INVENTORY_SLOT_ITEM_START; slot < InventoryPackSlots::INVENTORY_SLOT_ITEM_END; slot++)
    {
        Item* pBagItem = player->GetItemByPos(255, slot);
        if (!pBagItem || pBagItem != pItem)
            continue;
        player->DestroyItem(255, slot, true);
        return true;
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = player->GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                Item* pBagItem = pBag->GetItemByPos(uint8(j));
                if (!pBagItem || pBagItem != pItem)
                    continue;
                player->DestroyItem(255, uint8(j), true);
                return true;
            }
        }
    }
    return false;
}

//Item* BotUtility::StoreNewItemByEntry(Player* player, uint32 entry, int32 count)
//{
//	if (!player || entry == 0 || count == 0)
//		return NULL;
//	ItemTemplate const* pTemplate = sObjectMgr->GetItemTemplate(entry);
//	if (!pTemplate)
//		return NULL;
//	uint32 noSpaceForCount = 0;
//	ItemPosCountVec dest;
//	InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, pTemplate->GetId(), count, &noSpaceForCount);
//	if (msg != EQUIP_ERR_OK)
//		count -= noSpaceForCount;
//	if (count <= 0 || dest.empty())
//		return nullptr;
//	/*Item* itemInst = player->StoreNewItem(dest, pTemplate->GetId(), true, GenerateItemRandomPropertyId(pTemplate->GetId()));
//	return itemInst;*/
//}

uint32 BotUtility::FindMaxRankSpellByExist(Player* player, uint32 spellID)
{
    if (spellID == 0)
        return 0;
    //return spellID;
    uint32 selectSpell = sSpellMgr->GetLastSpellInChain(spellID);
    if (selectSpell == 0)
    {
        if (player->HasSpell(spellID))
            return spellID;
        return 0;
    }
    while (!player->HasSpell(selectSpell))
    {
        selectSpell = sSpellMgr->GetPrevSpellInChain(selectSpell);
        if (selectSpell == 0)
            return 0;
    }
    TC_LOG_ERROR("sql.sql", "BotUtility::FindMaxRankSpellByExist( spellid %d GetLastSpellInChain %d )", spellID, selectSpell);
    return selectSpell;
}

void BotUtility::PlayerBotTogglePVP(Player* player, bool /*pvp*/)
{
    if (!player || !player->IsPlayerBot())
        return;

    WorldPacket packet;
    WorldPackets::Misc::TogglePvP Packets(std::move(packet));
    player->GetSession()->HandleTogglePvP(Packets);
}

//void BotUtility::TryTeleportHome(BotFieldAI* pAI)
//{
//	if (!pAI || pAI->HasTeleport())
//		return;
//	Player* player = pAI->GetAIPayer();
//	if (player->GetMapId() == player->m_homebindMapId)
//	{
//		if (player->GetDistance(player->m_homebindX, player->m_homebindY, player->m_homebindZ) < 80)
//			return;
//	}
//	Position homePosition = Position(player->m_homebindX, player->m_homebindY, player->m_homebindZ, player->GetOrientation());
//	pAI->SetTeleport(player->m_homebindMapId, homePosition);
//}

uint32 BotUtility::FindPetMaxRankSpellByExist(Player* player, uint32 spellID)
{
    if (spellID == 0)
        return 0;
    Pet* pPet = player->GetPet();
    if (!pPet)
        return 0;
    uint32 selectSpell = sSpellMgr->GetLastSpellInChain(spellID);
    if (selectSpell == 0)
    {
        if (pPet->HasSpell(spellID))
            return spellID;
        return 0;
    }
    while (!pPet->HasSpell(selectSpell))
    {
        selectSpell = sSpellMgr->GetPrevSpellInChain(selectSpell);
        if (selectSpell == 0)
            return 0;
    }
    return selectSpell;
}

//Position BotUtility::GetPositionFromGroup(Player* pCenterPlayer, ObjectGuid /*self*/, Group* pGroup)
//{
//	if (!pCenterPlayer || !pGroup || !pCenterPlayer->IsInWorld())
//		return Position();
//	Position centerPos = pCenterPlayer->GetPosition();
//	uint32 index = 0;
//	uint32 count = 0;
//	/*if (!pGroup->GiveAtGroupPos(self, index, count))
//		return centerPos;*/
//	if (count > 1)
//		--count;
//	float distance = 4.0f;
//	if (count <= 10)
//		distance = 8.0f;
//	else if (count > 10 && count <= 25)
//		distance = 10.0f;
//	else if (count > 25)
//		distance = 12.0f;
//    if (count != 0)
//    {
//        float onceAngle = (M_PI * 2) / float(count);
//    }
//	float angle = pCenterPlayer->GetOrientation() + onceAngle * float(index);
//	float distX = centerPos.GetPositionX() + distance * std::cosf(angle);
//	float distY = centerPos.GetPositionY() + distance * std::sinf(angle);
//	float distZ = centerPos.GetPositionZ();
//	if (!pCenterPlayer->IsFlying())
//		distZ = pCenterPlayer->GetMap()->GetHeight(pCenterPlayer->GetPhaseShift(), distX, distY, distZ);
//	Position resultPos(distX, distY, distZ, pCenterPlayer->GetOrientation());
//	Position pos = pCenterPlayer->GetFirstCollisionPosition(pCenterPlayer->GetDistance(resultPos), pCenterPlayer->GetRelativeAngle(&resultPos));
//	return pos;
//}

void BotUtility::ProcessGroupTankPullTargets(Player* player)
{
    if (!player || !player->IsInWorld())
        return;
    Group* pGroup = player->GetGroup();
    if (!pGroup || pGroup->isBFGroup() || pGroup->isBGGroup())
        return;
    std::set<Creature*> allCreature;
    std::vector<BotGroupAI*> allTanks;
    Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
    for (Group::MemberSlot const& slot : memList)
    {
        Player* player = ObjectAccessor::FindPlayer(slot.guid);
        if (!player || !player->IsAlive() || !player->IsPlayerBot())
            continue;
        BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(player->GetAI());
        if (!pAI)
            continue;
        NearCreatureVec searchCreatures;
        pAI->SearchCreatureListFromRange(player, searchCreatures, BOTAI_SEARCH_RANGE, false);
        for (Creature* pCreature : searchCreatures)
        {
            if (pGroup->IsMember(pCreature->GetTarget()))
                allCreature.insert(pCreature);
        }
        if (!pAI->IsTankBotAI())
            continue;
        allTanks.push_back(pAI);
        pAI->ClearTankTarget();
    }
    if (allTanks.size() <= 1 || allCreature.size() <= 1)
        return;
    std::queue<Creature*> creatureQueue;
    for (Creature* pc : allCreature)
        creatureQueue.push(pc);
    while (!creatureQueue.empty())
    {
        for (BotGroupAI* pGroupAI : allTanks)
        {
            Creature* pCreature = creatureQueue.front();
            pGroupAI->AddTankTarget(pCreature);
            creatureQueue.pop();
            if (creatureQueue.empty())
                break;
        }
    }
    Player* lastTankPlayer = NULL;
    for (BotGroupAI* pGroupAI : allTanks)
    {
        if (!pGroupAI->ExistPullTarget())
            continue;
        if (!lastTankPlayer)
        {
            lastTankPlayer = pGroupAI->GetAIPayer();
            //pGroupAI->SetTankPosition(lastTankPlayer->GetPosition());
        }
        else
        {
            Player* thisPlayer = pGroupAI->GetAIPayer();
            float fleeDistance = BOTAI_RANGESPELL_DISTANCE;
            float onceAngle = float(M_PI) * 2.0f / 8.0f;
            Position targetPos;
            float maxDist = 0.0f;
            for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
            {
                Position collPos = thisPlayer->GetFirstCollisionPosition(fleeDistance, angle);
                float dist = lastTankPlayer->GetDistance(collPos);
                if (maxDist == 0 || dist > maxDist)
                {
                    maxDist = dist;
                    targetPos = collPos;
                }
            }
            lastTankPlayer = thisPlayer;
            pGroupAI->SetTankPosition(targetPos);
        }
    }
}

void BotUtility::ProcessGroupRingMovement(Player* pCenterPlayer, BOTAI_WORKTYPE aiType)
{
    if (!pCenterPlayer || !pCenterPlayer->IsInWorld())
        return;
    Group* pGroup = pCenterPlayer->GetGroup();
    if (!pGroup || pGroup->isBFGroup() || pGroup->isBGGroup())
        return;
    NearPlayerVec meleePlayers;
    NearPlayerVec rangePlayers;
    Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
    for (Group::MemberSlot const& slot : memList)
    {
        Player* player = ObjectAccessor::FindPlayer(slot.guid);
        if (!player || !player->IsAlive() || !player->IsPlayerBot())
            continue;
        BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(player->GetAI());
        if (!pAI)
            continue;
        if (pAI->IsTankBotAI() || pAI->IsMeleeBotAI())
        {
            if (aiType == AIWT_ALL || aiType == AIWT_TANK || aiType == AIWT_MELEE)
                meleePlayers.push_back(player);
        }
        else
        {
            if (aiType == AIWT_ALL || aiType == AIWT_RANGE || aiType == AIWT_HEAL)
                rangePlayers.push_back(player);
        }
    }
    Unit* pCenterUnit = (pCenterPlayer->GetSelectedUnit()) ? pCenterPlayer->GetSelectedUnit() : pCenterPlayer;
    float meleeDistance = pCenterUnit->GetObjectSize() + 5.0f;
    for (uint32 i = 0; i < meleePlayers.size(); i++)
    {
        Player* pGroupPlayer = meleePlayers[i];
        BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(pGroupPlayer->GetAI());
        if (!pAI)
            continue;
        Position centerPos = pCenterUnit->GetPosition();
        float onceAngle = (M_PI * 2) / float(meleePlayers.size());
        float angle = pCenterUnit->GetOrientation() + onceAngle * float(i);
        float distX = centerPos.GetPositionX() + meleeDistance * std::cosf(angle);
        float distY = centerPos.GetPositionY() + meleeDistance * std::sinf(angle);
        float distZ = centerPos.GetPositionZ();
        distZ = pCenterUnit->GetMap()->GetHeight(pCenterUnit->GetPhaseShift(), distX, distY, distZ);
        Position resultPos(distX, distY, distZ, pCenterUnit->GetOrientation());
        Position pos = pCenterUnit->GetFirstCollisionPosition(pCenterUnit->GetDistance(resultPos), pCenterUnit->GetRelativeAngle(&resultPos));
        pAI->SetCruxMovement(pos);
        pGroupPlayer->SetSelection(ObjectGuid::Empty);
        pAI->ClearTankTarget();
    }
    float rangeDistance = pCenterUnit->GetObjectSize() + BOTAI_FLEE_JUDGE + NEEDFLEE_CHECKRANGE;
    for (uint32 i = 0; i < rangePlayers.size(); i++)
    {
        Player* pGroupPlayer = rangePlayers[i];
        BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(pGroupPlayer->GetAI());
        if (!pAI)
            continue;
        Position centerPos = pCenterUnit->GetPosition();
        float onceAngle = (M_PI * 2) / float(rangePlayers.size());
        float angle = pCenterUnit->GetOrientation() + onceAngle * float(i);
        float distX = centerPos.GetPositionX() + rangeDistance * std::cosf(angle);
        float distY = centerPos.GetPositionY() + rangeDistance * std::sinf(angle);
        float distZ = centerPos.GetPositionZ();
        distZ = pCenterUnit->GetMap()->GetHeight(pCenterUnit->GetPhaseShift(), distX, distY, distZ);
        Position resultPos(distX, distY, distZ, pCenterUnit->GetOrientation());
        Position pos = pCenterUnit->GetFirstCollisionPosition(pCenterUnit->GetDistance(resultPos), pCenterUnit->GetRelativeAngle(&resultPos));
        pAI->SetCruxMovement(pos);
        pGroupPlayer->SetSelection(ObjectGuid::Empty);
        pAI->ClearTankTarget();
    }
}

void BotUtility::ProcessGroupCombatMovement(Player* pCenterPlayer, BOTAI_WORKTYPE aiType)
{
    if (!pCenterPlayer || !pCenterPlayer->IsInWorld())
        return;
    Group* pGroup = pCenterPlayer->GetGroup();
    if (!pGroup || pGroup->isBFGroup() || pGroup->isBGGroup())
        return;
    NearPlayerVec tankPlayers;
    NearPlayerVec meleePlayers;
    NearPlayerVec rangePlayers;
    Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
    for (Group::MemberSlot const& slot : memList)
    {
        Player* player = ObjectAccessor::FindPlayer(slot.guid);
        if (!player || !player->IsAlive() || !player->IsPlayerBot())
            continue;
        BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(player->GetAI());
        if (!pAI)
            continue;
        if (pAI->IsTankBotAI())
        {
            if (aiType == AIWT_ALL || aiType == AIWT_TANK)
                tankPlayers.push_back(player);
        }
        if (pAI->IsMeleeBotAI())
        {
            if (aiType == AIWT_ALL || aiType == AIWT_MELEE)
                meleePlayers.push_back(player);
        }
        else
        {
            if (aiType == AIWT_ALL || aiType == AIWT_RANGE || aiType == AIWT_HEAL)
                rangePlayers.push_back(player);
        }
    }
    /*Unit* pCenterUnit = (pCenterPlayer->GetSelectedUnit()) ? pCenterPlayer->GetSelectedUnit() : pCenterPlayer;
    G3D::Vector3 relativePos = (pCenterUnit->GetVector3() - pCenterPlayer->GetVector3()) + pCenterUnit->GetVector3();
    float relativeAngle = pCenterUnit->GetAngle(relativePos.x, relativePos.y);
    Position centerPos = pCenterUnit->GetPosition();
    float baseAngle = Position::NormalizeOrientation(relativeAngle) - ((M_PI * 0.25) * 0.5);
    float meleeDistance = pCenterUnit->GetObjectSize() + 5.0f;
    for (uint32 i = 0; i < tankPlayers.size(); i++)
    {
        Player* pGroupPlayer = tankPlayers[i];
        BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(pGroupPlayer->GetAI());
        if (!pAI)
            continue;
        float onceAngle = (M_PI * 0.25) / float(tankPlayers.size());
        float angle = baseAngle + (onceAngle * float(i)) + onceAngle * 0.5;
        float distX = centerPos.GetPositionX() + meleeDistance * std::cosf(angle);
        float distY = centerPos.GetPositionY() + meleeDistance * std::sinf(angle);
        float distZ = centerPos.GetPositionZ();
        distZ = pCenterUnit->GetMap()->GetHeight(pCenterUnit->GetPhaseShift(), distX, distY, distZ);
        Position resultPos(distX, distY, distZ, pCenterUnit->GetOrientation());
        Position pos = pCenterUnit->GetFirstCollisionPosition(pCenterUnit->GetDistance(resultPos), pCenterUnit->GetRelativeAngle(&resultPos));
        pAI->SetCruxMovement(pos);
        pGroupPlayer->SetSelection(ObjectGuid::Empty);
        pAI->ClearTankTarget();
    }
    meleeDistance += 3.0f;
    baseAngle = Position::NormalizeOrientation(relativeAngle + M_PI) - ((M_PI * 0.6) * 0.5);*/
    /*for (uint32 i = 0; i < meleePlayers.size(); i++)
    {
        Player* pGroupPlayer = meleePlayers[i];
        BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(pGroupPlayer->GetAI());
        if (!pAI)
            continue;
        float onceAngle = (M_PI * 0.6) / float(meleePlayers.size());
        float angle = baseAngle + (onceAngle * float(i)) + onceAngle * 0.5;
        float distX = centerPos.GetPositionX() + meleeDistance * std::cosf(angle);
        float distY = centerPos.GetPositionY() + meleeDistance * std::sinf(angle);
        float distZ = centerPos.GetPositionZ();
        distZ = pCenterUnit->GetMap()->GetHeight(pCenterUnit->GetPhaseShift(), distX, distY, distZ);
        Position resultPos(distX, distY, distZ, pCenterUnit->GetOrientation());
        Position pos = pCenterUnit->GetFirstCollisionPosition(pCenterUnit->GetDistance(resultPos), pCenterUnit->GetRelativeAngle(&resultPos));
        pAI->SetCruxMovement(pos);
        pGroupPlayer->SetSelection(ObjectGuid::Empty);
        pAI->ClearTankTarget();
    }
    float rangeDistance = pCenterUnit->GetObjectSize() + BOTAI_FLEE_JUDGE + NEEDFLEE_CHECKRANGE;
    baseAngle = Position::NormalizeOrientation(relativeAngle + M_PI) - ((M_PI * 0.6) * 0.5);
    for (uint32 i = 0; i < rangePlayers.size(); i++)
    {
        Player* pGroupPlayer = rangePlayers[i];
        BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(pGroupPlayer->GetAI());
        if (!pAI)
            continue;
        float onceAngle = (M_PI * 0.6) / float(rangePlayers.size());
        float angle = baseAngle + (onceAngle * float(i)) + onceAngle * 0.5;
        float distX = centerPos.GetPositionX() + rangeDistance * std::cosf(angle);
        float distY = centerPos.GetPositionY() + rangeDistance * std::sinf(angle);
        float distZ = centerPos.GetPositionZ();
        distZ = pCenterUnit->GetMap()->GetHeight(pCenterUnit->GetPhaseShift(), distX, distY, distZ);
        Position resultPos(distX, distY, distZ, pCenterUnit->GetOrientation());
        Position pos = pCenterUnit->GetFirstCollisionPosition(pCenterUnit->GetDistance(resultPos), pCenterUnit->GetRelativeAngle(&resultPos));
        pAI->SetCruxMovement(pos);
        pGroupPlayer->SetSelection(ObjectGuid::Empty);
        pAI->ClearTankTarget();
    }*/
}

Position BotUtility::FindRadiusByNearDistance(Unit* pTargetUnit, float range, Unit* pRefUnit)
{
    float onceAngle = float(M_PI) * 2.0f / 8.0f;
    Position targetPos;
    //float selectAngle = pTargetUnit->GetOrientation() * (-1);
    float minDist = 999999.0f;
    std::list<Position> allPosition;
    for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
    {
        Position pos = pRefUnit->GetFirstCollisionPosition(range, angle);
        //float dist = pRefUnit->GetDistance(pos);
        if (!pTargetUnit->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
            continue;
        allPosition.push_back(pos);
    }
    if (allPosition.empty())
        return pTargetUnit->GetPosition();
    for (Position pos : allPosition)
    {
        float dist = pTargetUnit->GetDistance(pos);
        if (dist < minDist)
        {
            minDist = dist;
            targetPos = pos;
        }
    }
    return targetPos;
}

Position BotUtility::FindRadiusByFarDistance(Unit* pTargetUnit, float range, Unit* pRefUnit)
{
    float onceAngle = float(M_PI) * 2.0f / 8.0f;
    Position targetPos = pTargetUnit->GetPosition();
    //float selectAngle = pTargetUnit->GetOrientation() * (-1);
    float maxDist = 0.0f;
    std::list<Position> allPosition;
    for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
    {
        Position pos = pRefUnit->GetFirstCollisionPosition(range, angle);
        //float dist = pRefUnit->GetDistance(pos);
        if (!pTargetUnit->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
            continue;
        allPosition.push_back(pos);
    }
    if (allPosition.empty())
        return targetPos;
    for (Position pos : allPosition)
    {
        float dist = pTargetUnit->GetDistance(pos);
        if (dist > maxDist)
        {
            maxDist = dist;
            targetPos = pos;
        }
    }
    return targetPos;
}

bool BotUtility::FindFirstCollisionPosition(Unit* pTargetUnit, float range, Unit* pRefUnit, Position& outPos)
{
    if (range < 3.0f || range <= pRefUnit->GetObjectSize() || pRefUnit->GetDistance(pTargetUnit->GetPosition()) >= range)
        return false;
    Map* pMap = pRefUnit->GetMap();
    if (pTargetUnit->GetMap() != pMap)
        return false;
    //G3D::Vector3 refUnitV3 = pRefUnit->GetVector3();
    //G3D::Vector3 tarUnitV3 = pTargetUnit->GetVector3();
    //G3D::Vector3 distV3 = tarUnitV3 - refUnitV3;
    //if (distV3.length() < 1.0f)
    //	return false;
    //G3D::Vector3 dir = distV3.directionOrZero();
    //G3D::Vector3 target = refUnitV3 + dir * range;
    //target.z = pMap->GetHeight(pTargetUnit->GetPhaseShift(), target.x, target.y, target.z);

    //G3D::Vector3 searchPos = target;
    //float once = range * 0.1f;
    //while (!pTargetUnit->IsWithinLOS(searchPos.x, searchPos.y, searchPos.z))
    //{
    //	if (range <= once)
    //		return false;
    //	range -= once;
    //	searchPos = refUnitV3 + dir * range;
    //	searchPos.z = pMap->GetHeight(pTargetUnit->GetPhaseShift(), searchPos.x, searchPos.y, searchPos.z);
    //}

    float once = range * 0.2f;
    std::vector<Position> canPoss;
    for (float angle = 0; angle < (float(M_PI) * 2.0f); angle += float(M_PI_4))
    {
        float calcRange = range;
        float distX = pRefUnit->GetPositionX() + calcRange * std::cosf(angle);
        float distY = pRefUnit->GetPositionY() + calcRange * std::sinf(angle);
        float distZ = pMap->GetHeight(pTargetUnit->GetPhaseShift(), distX, distY, pRefUnit->GetPositionZ());
        while (!pTargetUnit->IsWithinLOS(distX, distY, distZ))
        {
            if (calcRange <= once)
                break;
            calcRange -= once;
            distX = pRefUnit->GetPositionX() + calcRange * std::cosf(angle);
            distY = pRefUnit->GetPositionY() + calcRange * std::sinf(angle);
            distZ = pMap->GetHeight(pTargetUnit->GetPhaseShift(), distX, distY, pRefUnit->GetPositionZ());
        }
        if (calcRange >= range * 0.75f)
            canPoss.push_back(Position(distX, distY, distZ, pTargetUnit->GetOrientation()));
    }
    Position calcPos;
    if (!canPoss.empty())
    {
        calcPos = canPoss[urand(0, canPoss.size() - 1)];
        float minDist = 0;
        for (Position pos : canPoss)
        {
            float dist = pTargetUnit->GetDistance(pos);
            if (dist < minDist)
            {
                calcPos = pos;
                minDist = dist;
            }
        }
    }
    else
        return false;

    outPos.m_positionX = calcPos.GetPositionX();
    outPos.m_positionY = calcPos.GetPositionY();
    outPos.m_positionZ = calcPos.GetPositionZ();
    return true;
}

void BotUtility::TryTeleportPlayerPet(Player* player, bool force)
{
    if (!player)
        return;
    Pet* pet = player->GetPet();
    if (!pet)
        return;
    if (!player->IsInWorld() || !pet->IsInWorld() || player->GetMap() != pet->GetMap())
        return;
    if (!force && player->GetDistance(pet->GetPosition()) < (BOTAI_SEARCH_RANGE * 2))
        return;

    if (pet->IsAlive() && pet->IsInCombat())
        pet->CombatStop(true);
    pet->NearTeleportTo(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation());
}

void BotAIGuild::UpdateGuildProcess()
{//todo47
    //if (me->GetArenaTeamIdInvited())
    //	me->GetSession()->HandleArenaTeamAcceptOpcode(WorldPacket(1));
    uint32 inviteGuild = me->GetGuildIdInvited();
    if (inviteGuild != 0)
    {
        if (WorldSession* pSession = me->GetSession())
        {
            WorldPacket packet;
            WorldPackets::Guild::AcceptGuildInvite sPacket(std::move(packet));
            pSession->HandleGuildAcceptInvite(sPacket);
        }
    }
    else if (Guild* pGuild = me->GetGuild())
    {
        if (pGuild->GetLeaderGUID() == me->GetGUID())
        {
        }
    }
}

void BotAITeleport::SetTeleport(Position* /*telePos*/, float offset)
{
    if (m_Teleporting)
        return;
    UpdateMapID();

    if (master)
    {
        Position pos = master->GetPosition();
        float x = pos.GetPositionX() + ((offset != 0) ? frand(offset * (-1), offset) : 0);
        float y = pos.GetPositionY() + ((offset != 0) ? frand(offset * (-1), offset) : 0);
        float z = pos.GetPositionZ();
        m_TeleportPositon = Position(x, y, z, pos.GetOrientation());
    }
    me->CombatStop(true);
    m_Teleporting = true;
    m_TeleportStep = 1;
}

void BotAITeleport::SetTeleport(Position& telePos)
{
    if (m_Teleporting)
        return;
    UpdateMapID();
    m_TeleportPositon = telePos;
    m_Teleporting = true;
    m_TeleportStep = 1;
}

void BotAITeleport::SetTeleport(uint32 mapID, Position& telePos)
{
    if (m_Teleporting)
        return;
    m_MapId = mapID;
    m_TeleportPositon = telePos;
    m_Teleporting = true;
    m_TeleportStep = 1;
}

void BotAITeleport::SetTeleport(Player* pTarget, float offset)
{
    if (m_Teleporting)
        return;
    if (!pTarget || !pTarget->GetMap() || !pTarget->IsInWorld() || me->InBattlegroundQueue() || me->InBattleground())
        return;
    master = pTarget;
    Position pos = pTarget->GetPosition();
    float x = pos.GetPositionX() + ((offset != 0) ? frand(offset * (-1), offset) : 0);
    float y = pos.GetPositionY() + ((offset != 0) ? frand(offset * (-1), offset) : 0);
    float z = pos.GetPositionZ();
    pTarget->GetMap()->GetHeight(pTarget->GetPhaseShift(), x, y, z);

    me->CombatStop(true);
    m_TeleportPositon = Position(x, y, z, pos.GetOrientation());
    m_MapId = pTarget->GetMapId();
    m_Teleporting = true;
    m_TeleportStep = 1;
}

void BotAITeleport::ClearTeleport()
{
    m_TeleportPositon.m_positionX = m_TeleportPositon.m_positionY = m_TeleportPositon.m_positionZ = 0;
    m_Teleporting = false;
    UpdateMapID();
    m_TeleportStep = 0;
}

void BotAITeleport::Update(uint32 /*diff*/, BotBGAIMovement* pMovement)
{
    if (!m_Teleporting || !pMovement)
        return;
    if (me->isMoving())
    {
        pMovement->ClearMovement();
        me->GetMotionMaster()->Clear();
        me->StopMoving();
        return;
    }
    if (me->IsCanDelayTeleport() || me->IsHasDelayedTeleport())
        return;
    if (m_TeleportStep > 0)//m_TeleportPositon.m_positionZ != 0)
    {
        if (m_TeleportStep == 1)
        {
            float x = m_TeleportPositon.GetPositionX();
            float y = m_TeleportPositon.GetPositionY();
            float z = m_TeleportPositon.GetPositionZ();
            if (!me->TeleportTo(m_MapId, x, y, z, me->GetOrientation()))
            {
                ClearTeleport();
                return;
            }

            m_TeleportStep = 2;
            if (me->GetMapId() != m_MapId)
            {
                WorldSession* pSession = me->GetSession();
                if (pSession)
                    pSession->HandleMoveWorldportAck();
                m_TeleportStep = 3;
            }
        }
        else if (m_TeleportStep == 2)
        {
            me->UpdatePosition(m_TeleportPositon, true);
            if (WorldSession* pSession = me->GetSession())
            {
                WorldPacket packet;
                WorldPackets::Movement::MoveTeleportAck sPacket(std::move(packet));
                sPacket.MoverGUID = me->GetGUID();
                sPacket.AckIndex = 0;
                sPacket.MoveTime = 100;
                pSession->HandleMoveTeleportAck(sPacket);
            }
            m_TeleportStep = 3;
        }
        else if (m_TeleportStep == 3)
        {
            MovementInfo movementInfo;
            movementInfo.pos = m_TeleportPositon;
            movementInfo.time = getMSTime();
            movementInfo.guid = me->GetGUID();
            movementInfo.flags = 0;
            //WorldPacket data(MSG_MOVE_FALL_LAND);// MSG_MOVE_STOP);todo47
            //pSession->WriteMovementInfo(&data, &movementInfo);
            //me->SendMessageToSet(&data, me);
            me->CombatStop(true);
            me->SetSelection(ObjectGuid::Empty);
            m_TeleportPositon.m_positionX = m_TeleportPositon.m_positionY = m_TeleportPositon.m_positionZ = 0;
            m_TeleportStep = 0;
        }
    }
    else
        m_Teleporting = false;
}

void BotAIStoped::UpdatePosition(uint32 diff)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    Position currentPos = me->GetPosition();
    if (HasDifference(m_lastPosition, currentPos))
    {
        //SyncPosition(currentPos, MSG_MOVE_START_FORWARD);
        me->UpdatePosition(currentPos);
        m_lastPosition = currentPos;
        m_updateTick = 0;
    }
    else
    {
        m_updateTick += diff;
        if (m_updateTick >= BOTAI_UPDATE_TICK * 2)
        {
            //SyncPosition(currentPos, MSG_MOVE_STOP);
            m_updateTick = 0;
            m_lastPosition = currentPos;
            me->StopMoving();
        }
    }
}

//bool BotAIStoped::HasDifference(Position& pos1, Position& pos2)
//{
//	float posGap = 0.2f;
//	if ((pos1.GetVector3() - pos2.GetVector3()).length() > posGap)
//		return true;
//	if (fabsf(pos1.GetOrientation() - pos2.GetOrientation()) > posGap)
//		return true;
//	return false;
//}

void BotAIStoped::SyncPosition(Position& /*pos*/, uint32 /*opcode*/)
{
    if (m_SyncTick < 3)
    {
        ++m_SyncTick;
        return;
    }
    m_SyncTick = 0;
    if (me->IsFlying())
        return;

    //WorldSession* pSession = me->GetSession();
    MovementInfo movementInfo;
    //movementInfo.flags = MOVEMENTFLAG_SPLINE_ENABLED;
    //movementInfo.pos = pos;
    //movementInfo.time = getMSTime();// +(opcode == MSG_MOVE_START_FORWARD) ? BOTAI_UPDATE_TICK : 0;
    //movementInfo.guid = me->GetGUID();
    //movementInfo.fallTime = me->m_movementInfo.fallTime;
    //WorldPacket data(opcode);
    //data << me->GetGUID();
    //pSession->WriteMovementInfo(&data, &movementInfo);
    //me->SendMessageToSet(&data, me);
}

//void BotAIHorrorState::UpdateHorror(uint32 diff, BotBGAIMovement* movement)
//{
//	if (!me)
//		return;
//	//if (me->IsStopped())
//	//{
//	//	float rndOffset = 40.0f;
//	//	float x = me->GetPositionX() + frand(-rndOffset, rndOffset);
//	//	float y = me->GetPositionY() + frand(-rndOffset, rndOffset);
//	//	float z = me->GetPositionZ();
//	//	me->GetMap()->GetHeight(me->GetPhaseShift(), x, y, z);
//	//	me->GetMotionMaster()->MoveCharge(x, y, z, me->GetSpeed(UnitMoveType::MOVE_RUN));
//	//}
//	if (me->GetDistance(m_CurHorrorPos) < 3.0f)
//	{
//		if (movement && sWorld->getFloatConfig(CONFIG_SPECIAL_FEAR_DISTANCE) > 0)
//			m_CurHorrorPos = FindNewHorrorPos(movement);
//		else
//			m_CurHorrorPos = GetNewHorrorPos();
//	}
//	me->GetMotionMaster()->Clear();
//	me->GetMotionMaster()->MovePoint(1, m_CurHorrorPos);
//}

Position BotAIHorrorState::GetNewHorrorPos()
{
    std::vector<float> angles;
    float onceAngle = float(M_PI) * 2.0f / 8.0f;
    Position targetPos = me->GetPosition();
    float maxDist = 0.0f;
    std::list<Position> allPosition;
    for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
        angles.push_back(angle);
    Trinity::Containers::RandomShuffle(angles);
    for (float angle : angles)
    {
        Position pos = me->GetFirstCollisionPosition(BOTAI_SEARCH_RANGE, angle);
        pos.m_positionZ = me->GetMap()->GetHeight(me->GetPhaseShift(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
        if (me->GetDistance(pos) > (BOTAI_SEARCH_RANGE * 0.8f))
            return pos;
        allPosition.push_back(pos);
    }
    if (allPosition.empty())
        return targetPos;
    for (Position pos : allPosition)
    {
        float dist = me->GetDistance(pos);
        if (dist > maxDist)
        {
            maxDist = dist;
            targetPos = pos;
        }
    }
    return targetPos;
}

Position BotAIHorrorState::GetNewHorrorPosByRange(Player* player, float distance)
{
    if (!player)
        return Position();
    std::vector<float> angles;
    float onceAngle = float(M_PI) * 2.0f / 8.0f;
    Position targetPos = player->GetPosition();
    //float maxDist = 0.0f;
    std::vector<Position> allPosition;
    for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
        angles.push_back(angle);
    Trinity::Containers::RandomShuffle(angles);
    for (float angle : angles)
    {
        Position pos = player->GetFirstCollisionPosition(distance, angle);
        pos.m_positionZ = player->GetMap()->GetHeight(player->GetPhaseShift(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
        if (player->GetDistance(pos) > (distance * 0.5f))
            allPosition.push_back(pos);
    }
    if (allPosition.empty())
        return targetPos;
    return allPosition[urand(0, allPosition.size() - 1)];
}

Position BotAIHorrorState::FindNewHorrorPos(BotBGAIMovement* movement)
{
    float moveMaxDistance = sWorld->getFloatConfig(CONFIG_SPECIAL_FEAR_DISTANCE);
    float onceAngle = float(M_PI) * 2.0f / 8.0f;
    Position targetPos = me->GetPosition();
    float maxDist = 0.0f;
    std::list<Position> allPosition;
    for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
    {
        for (float dist = 0.1f; dist <= 1.0f; dist += 0.1f)
        {
            float distX = me->GetPositionX() + (moveMaxDistance * dist) * std::cosf(angle);
            float distY = me->GetPositionY() + (moveMaxDistance * dist) * std::sinf(angle);
            float distZ = me->GetPositionZ();
            distZ = me->GetMap()->GetHeight(me->GetPhaseShift(), distX, distY, distZ);
            Position pos = me->GetPosition();
            if (!movement->SimulationMovementTo(distX, distY, distZ, pos))
                break;
            allPosition.push_back(pos);
        }
    }
    if (allPosition.empty())
        return GetNewHorrorPos();
    for (Position pos : allPosition)
    {
        float dist = me->GetDistance(pos);
        if (dist > maxDist)
        {
            maxDist = dist;
            targetPos = pos;
        }
    }
    return targetPos;
}

BotAIUseFood::BotAIUseFood(Player* self) :
    me(self),
    m_HasMana(false),
    m_LastFoodAura(0),
    m_LastWaterAura(0)
{
    m_FoodInfos.push_back(FoodInfo(110, 126934, 185703, 133980, 192128));
    m_FoodInfos.push_back(FoodInfo(100, 133893, 191876, 133980, 192128));
    m_FoodInfos.push_back(FoodInfo(90, 113099, 160598, 117475, 172786));
    m_FoodInfos.push_back(FoodInfo(85, 82450, 104235, 68140, 80167));
    m_FoodInfos.push_back(FoodInfo(75, 35948, 45548, 33445, 43183));
    m_FoodInfos.push_back(FoodInfo(65, 33449, 43180, 35954, 27089));
    m_FoodInfos.push_back(FoodInfo(60, 27855, 27094, 28399, 34291));
    m_FoodInfos.push_back(FoodInfo(45, 8950, 1131, 8766, 1137));
    m_FoodInfos.push_back(FoodInfo(35, 4601, 1129, 1645, 1135));
    m_FoodInfos.push_back(FoodInfo(25, 4544, 1127, 1708, 1133));
    m_FoodInfos.push_back(FoodInfo(15, 4542, 435, 1205, 432));
    m_FoodInfos.push_back(FoodInfo(5, 4541, 434, 1179, 431));
    m_FoodInfos.push_back(FoodInfo(0, 0, 0, 0, 0));

    switch (me->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
    case CLASS_DEATH_KNIGHT:
    case CLASS_DEMON_HUNTER:
    case CLASS_HUNTER:
        m_HasMana = false;
        break;
    case CLASS_PALADIN:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PRIEST:
    case CLASS_MONK:
        m_HasMana = true;
        break;
    }
}

bool BotAIUseFood::UpdateBotFood(uint32 /*diff*/, uint32 downMountID)
{
    static const float readyPct = 95;
    if (me->IsInCombat())
    {
        ClearFoodState();
        return false;
    }
    //if (Group* pGroup = me->GetGroup())
    //{
    //	if (!pGroup->AllGroupNotCombat())
    //		return false;
    //}
    float lifePct = me->GetHealthPct();
    float manaPct = (m_HasMana) ? ((float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA) * 100.0f) : 100.0f;
    if (lifePct >= readyPct && manaPct >= readyPct)
    {
        ClearFoodState();
        return false;
    }
    FoodInfo* pInfo = GetFoodInfoByLevel(me->getLevel());
    if (!pInfo || pInfo->level == 0)
        return false;
    if (lifePct < readyPct && !me->HasAura(pInfo->foodBuff))
    {
        Item* pItem = BotUtility::FindItemFromAllBag(me, pInfo->foodEntry);
        if (!pItem)
            pItem = BotUtility::StoreNewItemByEntry(me, pInfo->foodEntry, 10);
        if (pItem)
        {
            me->StopMoving();
            if (downMountID && me->IsMounted() && me->HasAura(downMountID))
                me->RemoveOwnedAura(downMountID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
            SpellCastTargets targets;
            targets.SetTargetMask(0);
            me->CastItemUseSpell(pItem, targets, ObjectGuid::Empty, 0);// == SpellCastResult::SPELL_CAST_OK)
            m_LastFoodAura = pInfo->foodBuff;
        }
    }
    if (manaPct < readyPct && !me->HasAura(pInfo->waterBuff))
    {
        Item* pItem = BotUtility::FindItemFromAllBag(me, pInfo->waterEntry);
        if (!pItem)
            pItem = BotUtility::StoreNewItemByEntry(me, pInfo->waterEntry, 10);
        if (pItem)
        {
            me->StopMoving();
            if (downMountID && me->IsMounted() && me->HasAura(downMountID))
                me->RemoveOwnedAura(downMountID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
            SpellCastTargets targets;
            targets.SetTargetMask(0);
            me->CastItemUseSpell(pItem, targets, ObjectGuid::Empty, 0);// == SpellCastResult::SPELL_CAST_OK)
            m_LastWaterAura = pInfo->waterBuff;
        }
    }
    return true;
}

BotAIUsePotion::BotAIUsePotion(Player* self) :me(self),m_NeedMana(true)
{
    uint8 cls = me->getClass();
    if (cls == 1 || cls == 4)
        m_NeedMana = false;

    m_LifeVials.push_back(PotionInfo(100, 127834));
    m_LifeVials.push_back(PotionInfo(91, 109223));
    m_LifeVials.push_back(PotionInfo(85, 76097));
    m_LifeVials.push_back(PotionInfo(70, 33447));
    m_LifeVials.push_back(PotionInfo(55, 22829));
    m_LifeVials.push_back(PotionInfo(45, 13446));
    m_LifeVials.push_back(PotionInfo(35, 3928));
    m_LifeVials.push_back(PotionInfo(21, 1710));
    m_LifeVials.push_back(PotionInfo(12, 929));
    m_LifeVials.push_back(PotionInfo(3, 858));
    m_LifeVials.push_back(PotionInfo(1, 118));

    m_ManaVials.push_back(PotionInfo(100, 127835));
    m_ManaVials.push_back(PotionInfo(90, 109222));
    m_ManaVials.push_back(PotionInfo(85, 76098));
    m_ManaVials.push_back(PotionInfo(70, 33448));
    m_ManaVials.push_back(PotionInfo(55, 22832));
    m_ManaVials.push_back(PotionInfo(49, 13444));
    m_ManaVials.push_back(PotionInfo(41, 13443));
    m_ManaVials.push_back(PotionInfo(31, 6149));
    m_ManaVials.push_back(PotionInfo(22, 3827));
    m_ManaVials.push_back(PotionInfo(14, 3385));
    m_ManaVials.push_back(PotionInfo(5, 2455));
}

bool BotAIUsePotion::TryUsePotion()
{
	if (!me->IsInCombat() || me->IsMounted() || me->HasUnitState(UNIT_STATE_CASTING))
		return false;
	if (!m_NeedMana)
	{
		float healPct = me->GetHealthPct();
		if (healPct < 65)
		{
			return TryUseLifeVial();
		}
	}
	else if (me->InBattleground())
	{
		float manaPer = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
		if (manaPer * 100 < 15)
		{
			return TryUseManaVial();
		}
		else if (me->GetHealthPct() < 60)
		{
			return TryUseLifeVial();
		}
	}
	else
	{
		float healPct = me->GetHealthPct();
		if (healPct < 30)
		{
			return TryUseLifeVial();
		}
		else
		{
			float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
			float manaPct = per * 100;
			if (manaPct < 75)
				return TryUseManaVial();
		}
	}
	return false;
}

bool BotAIUsePotion::TryUseLifeVial()
{
	Item* pItem = FindLifeVial();
	if (!pItem)
		return false;
	SpellCastTargets targets;
	targets.SetTargetMask(0);
	/*if (me->CastItemUseSpell(pItem, targets, 0, 0) == SpellCastResult::SPELL_CAST_OK)
		return true;*/
	return false;
}

//bool BotAIUsePotion::TryUseManaVial()
//{
//	Item* pItem = FindManaVial();
//	if (!pItem)
//		return false;
//	SpellCastTargets targets;
//	targets.SetTargetMask(0);
//	if (me->CastItemUseSpell(pItem, targets, 0, 0) == SpellCastResult::SPELL_CAST_OK)
//		return true;
//	return false;
//}
//
//Item* BotAIUsePotion::FindLifeVial()
//{
//	uint32 level = me->getLevel();
//	uint32 entry = 0;
//	for (PotionInfo& info : m_LifeVials)
//	{
//		if (info.level <= level)
//		{
//			entry = info.potionEntry;
//			break;
//		}
//	}
//	if (entry == 0)
//		return NULL;
//	Item* pItem = BotUtility::FindItemFromAllBag(me, entry);
//	if (!pItem)
//		pItem = BotUtility::StoreNewItemByEntry(me, entry, 5);
//	return pItem;
//}
//
//Item* BotAIUsePotion::FindManaVial()
//{
//	uint32 level = me->getLevel();
//	uint32 entry = 0;
//	for (PotionInfo& info : m_ManaVials)
//	{
//		if (info.level <= level)
//		{
//			entry = info.potionEntry;
//			break;
//		}
//	}
//	if (entry == 0)
//		return NULL;
//	Item* pItem = BotUtility::FindItemFromAllBag(me, entry);
//	if (!pItem)
//		pItem = BotUtility::StoreNewItemByEntry(me, entry, 5);
//	return pItem;
//}
//
//BotAIFastAid::BotAIFastAid(Player* self) :
//me(self),
//m_NoAidBuff(11196)
//{
//    m_FastAids.push_back(PotionInfo(101, 202852));
//    m_FastAids.push_back(PotionInfo(100, 170401));
//    m_FastAids.push_back(PotionInfo(91, 161255));
//    m_FastAids.push_back(PotionInfo(85, 74554));
//    m_FastAids.push_back(PotionInfo(81, 102694));
//	m_FastAids.push_back(PotionInfo(71, 45544));
//	m_FastAids.push_back(PotionInfo(61, 45543));
//	m_FastAids.push_back(PotionInfo(51, 27030));
//	m_FastAids.push_back(PotionInfo(41, 18608));
//	m_FastAids.push_back(PotionInfo(31, 10838));
//	m_FastAids.push_back(PotionInfo(21, 7926));
//	m_FastAids.push_back(PotionInfo(11, 3267));
//	m_FastAids.push_back(PotionInfo(1, 746));
//}
//
//void BotAIFastAid::CheckPlayerFastAid()
//{
//	uint8 level = me->getLevel();
//	for (PotionInfo& info : m_FastAids)
//	{
//		if (level >= info.level)
//		{
//			if (!me->HasSpell(info.potionEntry))
//				me->LearnSpell(info.potionEntry, false);
//		}
//		else
//		{
//			if (me->HasSpell(info.potionEntry))
//				me->RemoveSpell(info.potionEntry, false, false);
//		}
//	}
//}
//
//bool BotAIFastAid::TryDoingFastAidForMe()
//{
//	if (!CanFastAidByTarget(me))
//		return false;
//	uint32 fastAidSpellID = GetFastAidSpell();
//	if (fastAidSpellID == 0)
//		return false;
//	SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(fastAidSpellID, DIFFICULTY_NONE);
//	if (!spellInfo)
//		return false;
//	me->StopMoving();
//	me->GetMotionMaster()->Clear();
//	Spell* spell = new Spell(me, spellInfo, TriggerCastFlags::TRIGGERED_NONE, ObjectGuid::Empty);
//	spell->m_CastItem = NULL;
//	SpellCastTargets targets;
//	targets.SetUnitTarget(me);
//	//SpellCastResult castResult = spell->prepare(&targets, NULL);
//	//if (castResult != SpellCastResult::SPELL_CAST_OK)
//	//	return false;
//	return true;
//}
//
//uint32 BotAIFastAid::GetFastAidSpell()
//{
//	uint8 level = me->getLevel();
//	for (PotionInfo& info : m_FastAids)
//	{
//		if (level >= info.level)
//		{
//			if (me->HasSpell(info.potionEntry))
//				return info.potionEntry;
//		}
//	}
//	return 0;
//}
//
//bool BotAIFastAid::CanFastAidByTarget(Player* target)
//{
//	if (!target || !target->IsInWorld() || !target->IsAlive() || target->IsMounted() || target->HasAura(m_NoAidBuff))
//		return false;
//	if (me != target && me->IsValidAttackTarget(target))
//		return false;
//	if (!me->IsAlive() || me->HasUnitState(UNIT_STATE_CASTING) || target->GetHealthPct() > 75)
//		return false;
//	if ((me->HasAuraWithMechanic(1 << Mechanics::MECHANIC_CHARM)) || (me->HasAuraWithMechanic(1 << Mechanics::MECHANIC_FEAR)) ||
//		(me->HasAuraWithMechanic(1 << Mechanics::MECHANIC_HORROR)) || (me->HasAuraWithMechanic(1 << Mechanics::MECHANIC_POLYMORPH)))
//		return false;
//
//	std::list<Player*> nearPlayer;
//	target->GetPlayerListInGrid(nearPlayer, BOTAI_RANGESPELL_DISTANCE);
//	for (Player* player : nearPlayer)
//	{
//		if (player->GetTeamId() == target->GetTeamId())
//			continue;
//		if (!player->IsValidAttackTarget(target))
//			continue;
//		if (player->GetTarget() != target->GetGUID())
//			continue;
//		return false;
//	}
//	NearCreatureList nearCreature;
//	Trinity::AllWorldObjectsInRange checker(target, BOTAI_RANGESPELL_DISTANCE);
//	Trinity::CreatureListSearcher<Trinity::AllWorldObjectsInRange> searcher(target, nearCreature, checker);
//    Cell::VisitGridObjects(target, searcher, BOTAI_RANGESPELL_DISTANCE);
//	for (Creature* pCreature : nearCreature)
//	{
//		if (pCreature->IsTotem())
//			continue;
//		if (!pCreature->IsValidAttackTarget(target))
//			continue;
//		if (pCreature->GetTarget() != target->GetGUID())
//			continue;
//		return false;
//	}
//	return true;
//}
//
//void BotAIUseFood::ClearFoodState()
//{
//	if (!me->IsStandState())
//		me->SetStandState(UNIT_STAND_STATE_STAND);
//	if (m_LastFoodAura > 0)
//	{
//		if (me->HasAura(m_LastFoodAura))
//			me->RemoveOwnedAura(m_LastFoodAura, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
//		m_LastFoodAura = 0;
//	}
//	if (m_LastWaterAura > 0)
//	{
//		if (me->HasAura(m_LastWaterAura))
//			me->RemoveOwnedAura(m_LastWaterAura, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
//		m_LastWaterAura = 0;
//	}
//}
//
//FoodInfo* BotAIUseFood::GetFoodInfoByLevel(uint32 level)
//{
//	for (FoodInfo& info : m_FoodInfos)
//	{
//		if (info.level <= level)
//			return &info;
//	}
//	return NULL;
//}
//
//bool BotAIFindNearLoot::DoFindLoot(uint32 diff, BotBGAIMovement* movement, uint32 downMountID)
//{
//	if (m_LootingTick > 0)
//	{
//		m_LootingTick -= int32(diff);
//		if (m_LootingTick < 0)
//			m_LootingTick = 0;
//		return true;
//	}
//	if (!me->GetLootGUID().IsEmpty())
//		me->GetSession()->DoLootRelease(me->GetLootGUID());
//
//	Group* pGroup = me->GetGroup();
//	if (!pGroup || pGroup->isBGGroup() || !pGroup->AllGroupNotCombat())
//	{
//		if (!me->IsStandState())
//			me->SetStandState(UNIT_STAND_STATE_STAND);
//		m_HasLoot = false;
//		return false;
//	}
//	Creature* pCreature = FindLootCreature(BOTAI_RANGESPELL_DISTANCE);
//	if (!pCreature)
//	{
//		if (!me->IsStandState())
//			me->SetStandState(UNIT_STAND_STATE_STAND);
//		m_HasLoot = false;
//		return false;
//	}
//	Loot* pLoot = &pCreature->loot;
//	float dist = me->GetDistance(pCreature->GetPosition());
//	if (dist > 5)
//	{
//		movement->MovementTo(pCreature->GetPositionX(), pCreature->GetPositionY(), pCreature->GetPositionZ(), 0);
//		if (!me->IsStandState())
//			me->SetStandState(UNIT_STAND_STATE_STAND);
//		m_HasLoot = true;
//		return true;
//	}
//	movement->ClearMovement();
//	if (downMountID && me->IsMounted() && me->HasAura(downMountID))
//		me->RemoveOwnedAura(downMountID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
//	me->SendLoot(pCreature->GetGUID(), LOOT_CORPSE);
//	if (pLoot->gold > 0)
//	{
//        WorldPacket packet;
//        WorldPackets::Loot::LootMoney  sPacket(std::move(packet));
//		me->GetSession()->HandleLootMoneyOpcode(sPacket);
//	}
//	m_LootingTick = 500;
//	m_HasLoot = true;
//	return true;
//}
//
//Creature* BotAIFindNearLoot::FindLootCreature(float range)
//{
//	std::list<Creature*> nearCreature;
//	Trinity::AllWorldObjectsInRange checker(me, range);
//	Trinity::CreatureListSearcher<Trinity::AllWorldObjectsInRange> searcher(me, nearCreature, checker);
//    Cell::VisitGridObjects(me, searcher, range);
//
//	float nearDistance = 9999;
//	Creature* pNearCreature = NULL;
//	for (Creature* pCreature : nearCreature)
//	{
//		if (pCreature->IsAlive() || pCreature->IsPet() || pCreature->IsTotem() || pCreature->IsSummon())
//			continue;
//		Loot* pLoot = &pCreature->loot;
//		if (pLoot->empty() || pLoot->isLooted())
//			continue;
//		if (pCreature->GetLootRecipient() != me)
//			continue;
//		//if (!pLoot->PlayerBotCanLoot(me->GetGUID()))
//			//continue;
//		float dist = me->GetDistance(pCreature->GetPosition());
//		if (!pNearCreature || dist < nearDistance)
//		{
//			nearDistance = dist;
//			pNearCreature = pCreature;
//		}
//	}
//	return pNearCreature;
//}
//
//void BotAILootedItems::LookupLootedItems(uint32 diff)
//{
//	if (items.empty() || me->IsInCombat())
//		return;
//	uint32 entry = (*items.begin());
//	items.erase(items.begin());
//
//	uint8 bag = 255;
//	uint8 index = 0;
//	Item* pItem = BotUtility::FindItemFromAllBag(me, entry, bag, index);
//	if (!pItem)
//		return;
//	uint16 eDest;
//	InventoryResult msg = me->CanEquipItem(NULL_SLOT, eDest, pItem, !pItem->IsBag());
//	if (msg != EQUIP_ERR_OK)
//	{
//		BotUtility::FindItemFromAllBag(me, entry, true);
//		return;
//	}
//
//    WorldPacket packet;
//    WorldPackets::Item::AutoEquipItem sPacket(std::move(packet));
//    sPacket.Inv.Items.resize(1);
//    sPacket.PackSlot = bag;
//    sPacket.Slot = index;
//    me->GetSession()->HandleAutoEquipItemOpcode(sPacket);
//}
//
//bool BotAITrade::ProcessTrade()
//{
//	TradeData* pTrade = me->GetTradeData();
//	if (!pTrade)
//		return false;
//	Player* pTradePlayer = pTrade->GetTrader();
//	if (!pTradePlayer)
//		return false;
//	TradeData* pTraderData = pTradePlayer->GetTradeData();
//	if (!pTraderData)
//	{
//		me->TradeCancel(false);
//		return true;
//	}
//	if (pTraderData->IsAccepted())
//	{
//        WorldPacket packet;
//        WorldPackets::Trade::AcceptTrade sPacket(std::move(packet));
//		me->GetSession()->HandleAcceptTradeOpcode(sPacket);
//	}
//	else
//	{
//		if (me->IsInCombat())
//		{
//			me->TradeCancel(false);
//			std::string outString;
//			consoleToUtf8(std::string("???,????."), outString);
//			me->Whisper(outString, Language::LANG_COMMON, pTradePlayer);
//		}
//	}
//
//	return true;
//}
//
//void BotAIGiveXP::ProcessGiveXP(uint32 masterLV)
//{
//	if (m_AddXP == 0)
//		return;
//
//	uint32 level = me->getLevel();
//	if ((level > masterLV + 1) || level >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
//	{
//		m_AddXP = 0;
//		return;
//	}
//	if (level > masterLV)
//		m_AddXP = uint32(float(m_AddXP) * 0.7f);
//	else if (level < masterLV)
//		m_AddXP = uint32(float(m_AddXP) * 1.4f);
//	if (m_AddXP > 0)
//		me->GiveXP(m_AddXP, NULL);
//	m_AddXP = 0;
//}
//
//void BotAIRevive::UpdateRevive(uint32 diff)
//{
//	if (me->IsAlive() || me->InBattleground())
//	{
//		m_ReviveTick = 0;
//		return;
//	}
//	Group* pGroup = me->GetGroup();
//	if (pGroup)
//	{
//		//if (!pGroup->AllGroupNotCombat())
//		//{
//		//	m_ReviveTick = 0;
//		//	return;
//		//}
//		uint32 reviveTick = BotUtility::BotCanForceRevive ? (c_MaxReviveWaitTick / 2) : c_MaxReviveWaitTick;
//		m_ReviveTick += diff;
//		if (m_ReviveTick >= reviveTick)
//		{
//			ReviveMe();
//			return;
//		}
//	}
//	else
//	{
//		ReviveMe();
//	}
//}
//
//void BotAIRevive::ReviveMe()
//{
//	me->ResurrectPlayer(1.0f);
//	me->SpawnCorpseBones();
//	me->SaveToDB();
//	me->SetSelection(ObjectGuid::Empty);
//	me->DurabilityRepairAll(false, 1.0f, false);
//	m_ReviveTick = 0;
//}
//
//void BotAIFieldRevive::UpdateRevive(uint32 diff, BotAITeleport& teleport)
//{
//	if (me->IsAlive() || me->InBattleground() || !me->IsInWorld())
//	{
//		m_ReviveTick = 0;
//		return;
//	}
//	m_ReviveTick += diff;
//	if (m_ReviveTick >= c_MaxReviveWaitTick)
//	{
//		if (!m_TickOvered)
//		{
//			if (Corpse* corpse = me->CreateCorpse())
//			{
//				me->GetMap()->AddToMap(corpse);
//				corpse->ResetGhostTime();
//			}
//		}
//		if (!m_TickOvered && teleport.CanMovement())
//			TeleportToAround(teleport);
//		m_TickOvered = true;
//		//if (!teleport.CanMovement())
//		//	return;
//		ReviveMe();
//	}
//}
//
//void BotAIFieldRevive::TeleportToAround(BotAITeleport& teleport)
//{
//	float onceAngle = float(M_PI) * 2.0f / 16.0f;
//	Position targetPos = me->GetPosition();
//	float maxDist = 0.0f;
//	for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
//	{
//		Position& pos = me->GetFirstCollisionPosition(BOTAI_SEARCH_RANGE * 1.6f, angle);
//		float dist = me->GetDistance(pos);
//		if (dist > maxDist)
//		{
//			maxDist = dist;
//			targetPos = pos;
//		}
//	}
//	if (maxDist == 0)
//		return;
//	teleport.SetTeleport(targetPos);
//}
//
//void BotAIFieldRevive::ReviveMe()
//{
//	me->ResurrectPlayer(1.0f);
//	me->SpawnCorpseBones();
//	me->SaveToDB();
//	me->SetSelection(ObjectGuid::Empty);
//	me->DurabilityRepairAll(false, 1.0f, false);
//	m_TickOvered = false;
//	m_ReviveTick = 0;
//}
//
//ObjectGuid BotAIRevivePlayer::SearchNeedRevive(uint32 diff)
//{
//	if (!me->IsAlive() || !CanRevivePlayer() || me->IsInCombat() || me->HasUnitState(UNIT_STATE_CASTING))
//		return ObjectGuid::Empty;
//	Group* pGroup = me->GetGroup();
//	if (!pGroup)
//		return ObjectGuid::Empty;
//	std::vector<ObjectGuid>& needPlayers = pGroup->GetGroupMemberFromNeedRevivePlayer(me->GetMapId());
//	if (needPlayers.empty())
//		return ObjectGuid::Empty;
//	return needPlayers[urand(0, needPlayers.size() - 1)];
//}
//
//bool BotAIRevivePlayer::CanRevivePlayer()
//{
//	uint8 cls = me->getClass();
//	if (cls == CLASS_PALADIN || cls == CLASS_PRIEST || cls == CLASS_SHAMAN || cls == CLASS_DRUID || cls == CLASS_MONK)
//		return true;
//	return false;
//}
//
//void BotAIFlee::UpdateFleeMovementByPVE(Unit* pMaster, Unit* pRefUnit, BotBGAIMovement* pMovement)
//{
//	if (!pMovement || !pRefUnit)
//		return;
//	if (m_FleeTick > 16 || me->IsFlying())
//	{
//		Clear();
//		return;
//	}
//	if (m_cruxTime > 0)
//	{
//		uint32 curTick = getMSTime();
//		if (!Fleeing() || m_cruxTime < curTick)
//		{
//			Clear();
//			return;
//		}
//		pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//	}
//	else if (Fleeing())
//	{
//		float fleeDistance = (m_FleeTarget->GetVector3() - me->GetVector3()).length();
//		if (fleeDistance < 2.0f || fleeDistance > BOTAI_RANGESPELL_DISTANCE)
//		{
//			Clear();
//			float fleeDistance = me->GetDistance(pRefUnit->GetPosition());
//			if (fleeDistance < CalcMaxFleeDistance(pRefUnit))
//			{
//				Position targetPos;
//				if (!SearchPVEFleePosition(pMaster, pRefUnit, targetPos))
//				{
//					Clear();
//					return;
//				}
//				m_FleeTarget = new Position(targetPos);
//				pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//				++m_FleeTick;
//			}
//		}
//		else
//		{
//			pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//			++m_FleeTick;
//		}
//	}
//	else if (pRefUnit)
//	{
//		Position targetPos;
//		if(!SearchPVEFleePosition(pMaster, pRefUnit, targetPos))
//		{
//			Clear();
//			return;
//		}
//		m_FleeTarget = new Position(targetPos);
//		pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//		++m_FleeTick;
//	}
//}
//
//void BotAIFlee::UpdateFleeMovementByPVP(Unit* pRefUnit, BotBGAIMovement* pMovement)
//{
//	if (!pMovement)
//		return;
//	if (m_FleeTick > 16 || me->IsFlying())
//	{
//		Clear();
//		return;
//	}
//	if (m_cruxTime > 0)
//	{
//		uint32 curTick = getMSTime();
//		if (!Fleeing() || m_cruxTime < curTick)
//		{
//			Clear();
//			return;
//		}
//		pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//	}
//	else if (Fleeing())
//	{
//		float fleeDistance = (m_FleeTarget->GetVector3() - me->GetVector3()).length();
//		if (fleeDistance < 2.0f || fleeDistance > BOTAI_RANGESPELL_DISTANCE)
//		{
//			Clear();
//			float fleeDistance = me->GetDistance(pRefUnit->GetPosition());
//			if (fleeDistance < CalcMaxFleeDistance(pRefUnit))
//			{
//				fleeDistance = BOTAI_RANGESPELL_DISTANCE;// -fleeDistance;
//				float onceAngle = float(M_PI) * 2.0f / 8.0f;
//				Position targetPos;
//				float selectAngle = me->GetOrientation() * (-1);
//				float maxDist = 0.0f;
//				for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
//				{
//					float dist = 0;
//					Position& pos = CalculateFlee(fleeDistance, angle, pRefUnit, dist);
//					if (!pRefUnit->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
//						continue;
//					if (dist > maxDist)
//					{
//						maxDist = dist;
//						targetPos = pos;
//					}
//				}
//				if (maxDist == 0)
//					return;
//				m_FleeTarget = new Position(targetPos);
//				pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//				++m_FleeTick;
//			}
//		}
//		else
//		{
//			pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//			++m_FleeTick;
//		}
//	}
//	else if (pRefUnit)
//	{
//		float fleeDistance = me->GetDistance(pRefUnit->GetPosition());
//		if (fleeDistance >= BOTAI_RANGESPELL_DISTANCE)
//		{
//			Clear();
//			return;
//		}
//		fleeDistance = BOTAI_RANGESPELL_DISTANCE;// -fleeDistance;
//		float onceAngle = float(M_PI) * 2.0f / 8.0f;
//		Position targetPos;
//		float selectAngle = me->GetOrientation() * (-1);
//		float maxDist = 0.0f;
//		for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
//		{
//			float dist = 0;
//			Position& pos = CalculateFlee(fleeDistance, angle, pRefUnit, dist);
//			if(!pRefUnit->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
//				continue;
//			if (dist > maxDist)
//			{
//				maxDist = dist;
//				targetPos = pos;
//			}
//		}
//		if (maxDist == 0)
//		{
//			Clear();
//			return;
//		}
//		m_FleeTarget = new Position(targetPos);
//		pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//		++m_FleeTick;
//	}
//}
//
//void BotAIFlee::UpdateFleeMovementByPosition(Unit* pRefUnit, Position centerPos, float maxPosDist, BotBGAIMovement* pMovement)
//{
//	if (!pMovement)
//		return;
//	if (m_FleeTick > 16 || me->IsFlying())
//	{
//		Clear();
//		return;
//	}
//	if (m_cruxTime > 0)
//	{
//		uint32 curTick = getMSTime();
//		if (!Fleeing() || m_cruxTime < curTick)
//		{
//			Clear();
//			return;
//		}
//		pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//	}
//	else if (Fleeing())
//	{
//		float fleeDistance = (m_FleeTarget->GetVector3() - me->GetVector3()).length();
//		if (fleeDistance < 2.0f || fleeDistance > BOTAI_RANGESPELL_DISTANCE)
//		{
//			Clear();
//			float fleeDistance = me->GetDistance(pRefUnit->GetPosition());
//			if (fleeDistance < CalcMaxFleeDistance(pRefUnit))
//			{
//				fleeDistance = BOTAI_RANGESPELL_DISTANCE;// -fleeDistance;
//				float onceAngle = float(M_PI) * 2.0f / 8.0f;
//				Position targetPos;
//				float selectAngle = me->GetOrientation() * (-1);
//				float maxDist = 0.0f;
//				for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
//				{
//					float dist = 0;
//					Position& pos = CalculateFlee(fleeDistance, angle, pRefUnit, dist);
//					if (!pRefUnit->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
//						continue;
//					if (centerPos.GetExactDist(&pos) >= maxPosDist)
//						continue;
//					if (dist > maxDist)
//					{
//						maxDist = dist;
//						targetPos = pos;
//					}
//				}
//				if (maxDist == 0)
//					return;
//				m_FleeTarget = new Position(targetPos);
//				pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//				++m_FleeTick;
//			}
//		}
//		else
//		{
//			pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//			++m_FleeTick;
//		}
//	}
//	else if (pRefUnit)
//	{
//		float fleeDistance = me->GetDistance(pRefUnit->GetPosition());
//		if (fleeDistance >= BOTAI_RANGESPELL_DISTANCE)
//		{
//			Clear();
//			return;
//		}
//		fleeDistance = BOTAI_RANGESPELL_DISTANCE;// -fleeDistance;
//		float onceAngle = float(M_PI) * 2.0f / 8.0f;
//		Position targetPos;
//		float selectAngle = me->GetOrientation() * (-1);
//		float maxDist = 0.0f;
//		for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
//		{
//			float dist = 0;
//			Position& pos = CalculateFlee(fleeDistance, angle, pRefUnit, dist);
//			if (!pRefUnit->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
//				continue;
//			if (centerPos.GetExactDist(&pos) >= maxPosDist)
//				continue;
//			if (dist > maxDist)
//			{
//				maxDist = dist;
//				targetPos = pos;
//			}
//		}
//		if (maxDist == 0)
//		{
//			Clear();
//			return;
//		}
//		m_FleeTarget = new Position(targetPos);
//		pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//		++m_FleeTick;
//	}
//}
//
//void BotAIFlee::AddCruxFlee(uint32 durTime, Unit* pRefUnit, BotBGAIMovement* pMovement)
//{
//	if (!pMovement || !pRefUnit || !durTime)
//		return;
//	float fleeDistance = pRefUnit->GetObjectSize() + BOTAI_RANGESPELL_DISTANCE;
//	float onceAngle = float(M_PI) * 2.0f / 8.0f;
//	Position targetPos;
//	float selectAngle = me->GetOrientation() * (-1);
//	float maxDist = 0.0f;
//	for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
//	{
//		float dist = 0;
//		Position& pos = CalculateFlee(fleeDistance, angle, pRefUnit, dist);
//		if (!pRefUnit->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
//			continue;
//		if (dist > maxDist)
//		{
//			maxDist = dist;
//			targetPos = pos;
//		}
//	}
//	if (maxDist == 0)
//	{
//		return;
//	}
//	m_FleeTarget = new Position(targetPos);
//	pMovement->MovementTo(m_FleeTarget->GetPositionX(), m_FleeTarget->GetPositionY(), m_FleeTarget->GetPositionZ());
//	m_cruxTime = getMSTime() + durTime;
//}
//
//bool BotAIFlee::CanFleeToTargetPlayer(Player* player)
//{
//	if (!player)
//		return false;
//	switch (player->getClass())
//	{
//	case CLASS_WARRIOR:
//	case CLASS_ROGUE:
//	case CLASS_DEATH_KNIGHT:
//		return false;
//	case CLASS_PALADIN:
//		return player->FindTalentType() == 0;
//	case CLASS_MAGE:
//	case CLASS_WARLOCK:
//	case CLASS_HUNTER:
//	case CLASS_PRIEST:
//		return true;
//	case CLASS_SHAMAN:
//	case CLASS_DRUID:
//		return player->FindTalentType() != 1;
//    case CLASS_MONK:
//        return player->FindTalentType() == 2;
//	}
//	return false;
//}
//
//bool BotAIFlee::SearchPVEFleePosition(Unit* pMaster, Unit* pRefUnit, Position& fleePos)
//{
//	if (!pMaster || !pRefUnit)
//		return false;
//	float fleeDistance = me->GetDistance(pRefUnit->GetPosition());
//	if (fleeDistance >= BOTAI_RANGESPELL_DISTANCE)
//	{
//		Clear();
//		return false;
//	}
//	if (pRefUnit->GetTarget() != me->GetGUID() && CanFleeToTargetPlayer(pMaster->ToPlayer()))
//	{
//		float offsetDist = frand(1.0f, 4.0f);
//		float angle = frand(0, float(M_PI * 2) - 0.1f);
//		Position& targetPos = pMaster->GetFirstCollisionPosition(offsetDist, angle);
//		if (pRefUnit->GetDistance(targetPos) > NEEDFLEE_CHECKRANGE)
//		{
//			fleePos = targetPos;
//			return true;
//		}
//	}
//
//	fleeDistance = BOTAI_RANGESPELL_DISTANCE;// -fleeDistance;
//	uint32 minCount = 100;
//	float onceAngle = float(M_PI) * 2.0f / 16.0f;
//	std::list<PVEFleePosition> pveFleePoss;
//	float maxDist = 0.0f;
//	for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
//	{
//		float dist = 0;
//		Position& pos = CalculateFlee(fleeDistance, angle, pRefUnit, dist);
//		if (dist <= NEEDFLEE_CHECKRANGE)
//			continue;
//		if (!pRefUnit->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
//			continue;
//		std::list<Creature*> creatures;
//		SearchCreatureListFromRange(pos, creatures, BOTAI_RANGESPELL_DISTANCE);
//		uint32 enemys = creatures.size();
//		if (enemys > minCount)
//			continue;
//		minCount = enemys;
//		PVEFleePosition pfPos;
//		pfPos.fleePosition = pos;
//		pfPos.enemyCount = enemys;
//		pfPos.byMeDist = dist;
//		pfPos.byMasterDist = pMaster->GetDistance(pos);
//		pveFleePoss.push_back(pfPos);
//	}
//	if (pveFleePoss.empty())
//	{
//		float offsetDist = frand(1.0f, 4.0f);
//		float angle = frand(0, float(M_PI * 2) - 0.1f);
//		fleePos = pMaster->GetFirstCollisionPosition(offsetDist, angle);
//		return true;
//	}
//
//	if (minCount > 0 && CanFleeToTargetPlayer(pMaster->ToPlayer()))
//	{
//		float offsetDist = frand(1.0f, 4.0f);
//		float angle = frand(0, float(M_PI * 2) - 0.1f);
//		Position& targetPos = pMaster->GetFirstCollisionPosition(offsetDist, angle);
//		if (pRefUnit->GetDistance(targetPos) > NEEDFLEE_CHECKRANGE)
//		{
//			fleePos = targetPos;
//			return true;
//		}
//	}
//
//	std::list<PVEFleePosition> minEnemyPoss;
//	for (PVEFleePosition& poss : pveFleePoss)
//	{
//		if (poss.enemyCount > minCount)
//			continue;
//		minEnemyPoss.push_back(poss);
//		if (minEnemyPoss.empty())
//			fleePos = poss.fleePosition;
//	}
//	if (minEnemyPoss.size() == 1)
//		return true;
//	minEnemyPoss.sort();
//	std::vector<PVEFleePosition> smallDistPoss;
//	std::vector<PVEFleePosition> bigDistPoss;
//	int32 bigCount = int32(float(minEnemyPoss.size()) * 0.4f);
//	for (PVEFleePosition& poss : minEnemyPoss)
//	{
//		if (bigCount > 0)
//		{
//			bigDistPoss.push_back(poss);
//			--bigCount;
//		}
//		else
//			smallDistPoss.push_back(poss);
//	}
//	std::vector<PVEFleePosition>& useFleePoss = bigDistPoss.empty() ? smallDistPoss : bigDistPoss;
//	float nearDist = 999.0f;
//	for (PVEFleePosition& poss : useFleePoss)
//	{
//		if (poss.byMasterDist < nearDist)
//		{
//			fleePos = poss.fleePosition;
//			nearDist = poss.byMasterDist;
//		}
//	}
//	return true;
//}
//
//void BotAIFlee::SearchCreatureListFromRange(Position centerPos, std::list<Creature*>& nearCreatures, float range)
//{
//	std::list<Creature*> nearCreature;
//	Trinity::AllWorldObjectsInRange checker(me, BOTAI_RANGESPELL_DISTANCE + range);
//	Trinity::CreatureListSearcher<Trinity::AllWorldObjectsInRange> searcher(me, nearCreature, checker);
//    Cell::VisitGridObjects(me, searcher, range);
//	for (Creature* pCreature : nearCreature)
//	{
//		if (pCreature->IsPet() || pCreature->IsTotem() || pCreature->getLevel() <= 1)
//			continue;
//		if (pCreature->GetDistance(centerPos) > range)
//			continue;
//		if (!me->IsValidAttackTarget(pCreature))
//			continue;
//		nearCreatures.push_back(pCreature);
//	}
//}
//
//float BotAIFlee::CalcMaxFleeDistance(Unit* pRefUnit)
//{
//	return NEEDFLEE_CHECKRANGE - 1;
//	//float fleeDistance = me->GetDistance(pRefUnit->GetPosition());
//	//if (fleeDistance >= NEEDFLEE_CHECKRANGE)
//	//	return NEEDFLEE_CHECKRANGE;
//	//fleeDistance = NEEDFLEE_CHECKRANGE;
//	//float onceAngle = float(M_PI) * 2.0f / 8.0f;
//	//float selectAngle = me->GetOrientation() * (-1);
//	//float maxDist = 0.0f;
//	//for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
//	//{
//	//	float dist = 0;
//	//	Position& pos = CalculateFlee(fleeDistance, angle, pRefUnit, dist);
//	//	if (!pRefUnit->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
//	//		continue;
//	//	if (dist > maxDist)
//	//	{
//	//		maxDist = dist;
//	//	}
//	//}
//	//if (maxDist >= NEEDFLEE_CHECKRANGE)
//	//	return NEEDFLEE_CHECKRANGE;
//	//return maxDist;
//}
//
//Position BotAIFlee::CalculateFlee(float dist, float angle, Unit* pRefUnit, float& outDistance)
//{
//	Position& targetPos = me->GetFirstCollisionPosition(dist, angle);
//	outDistance = pRefUnit->GetDistance(targetPos);
//	return targetPos;
//}
//
//void BotAIIDLEMovement::UpdateIDLEMovement(BotBGAIMovement* pMovement)
//{
//	if (!pMovement)
//		return;
//	if (m_IDLETick > 20 || me->IsFlying())
//	{
//		Clear();
//		return;
//	}
//	if (Moveing())
//	{
//		float idleDistance = (m_IDLETarget->GetVector3() - me->GetVector3()).length();
//		if (idleDistance < 3.0f)
//		{
//			Clear();
//		}
//		else
//		{
//			pMovement->MovementTo(m_IDLETarget->GetPositionX(), m_IDLETarget->GetPositionY(), m_IDLETarget->GetPositionZ());
//			++m_IDLETick;
//		}
//	}
//	else
//	{
//		float idleDistance = BOTAI_FIELDTELEPORT_DISTANCE;
//		float onceAngle = float(M_PI) * 2.0f / 16.0f;
//		Position targetPos;
//		float selectAngle = me->GetOrientation() * (-1);
//		float maxDist = 0.0f;
//		for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
//		{
//			float dist = 0;
//			Position& pos = CalculateIDLE(idleDistance, angle, dist);
//			uint32 rate = urand(0, 99);
//			if (rate < 8)
//			{
//				maxDist = dist;
//				targetPos = pos;
//				break;
//			}
//			if (dist > maxDist)
//			{
//				maxDist = dist;
//				targetPos = pos;
//			}
//		}
//		if (maxDist == 0)
//		{
//			Clear();
//			return;
//		}
//		m_IDLETarget = new Position(targetPos);
//		pMovement->MovementTo(m_IDLETarget->GetPositionX(), m_IDLETarget->GetPositionY(), m_IDLETarget->GetPositionZ());
//		++m_IDLETick;
//	}
//}
//
//Position BotAIIDLEMovement::CalculateIDLE(float dist, float angle, float& outDistance)
//{
//	Position& targetPos = me->GetFirstCollisionPosition(dist, angle);
//	outDistance = me->GetDistance(targetPos);
//	return targetPos;
//}
//
//void BotAICruxMovement::SetMovement(Position& pos)
//{
//	if (HasCruxMovement())
//		return;
//	m_LastFleeDistance = 0;
//	m_MovementTarget = new Position(pos);
//}
//
//void BotAICruxMovement::RandomMovement(float range)
//{
//	if (HasCruxMovement())
//		return;
//	float onceAngle = float(M_PI) * 2.0f / 8.0f;
//	float rndAngle = frand(0, 359);
//	Position& targetPos = me->GetFirstCollisionPosition(range, rndAngle);
//	SetMovement(targetPos);
//}
//
//void BotAICruxMovement::UpdateCruxMovement(BotBGAIMovement* pMovement)
//{
//	if (!HasCruxMovement() || !pMovement)
//		return;
//	float fleeDistance = me->GetDistance(*m_MovementTarget);
//	if (fleeDistance <= 1.0f || me->IsFlying())
//	{
//		ClearMovement();
//		pMovement->ClearMovement();
//		return;
//	}
//	if (m_LastFleeDistance > 0)
//	{
//		if (m_LastFleeDistance < fleeDistance + 0.2f)
//		{
//			ClearMovement();
//			pMovement->ClearMovement();
//			return;
//		}
//	}
//	m_LastFleeDistance = fleeDistance;
//	pMovement->MovementTo(m_MovementTarget->GetPositionX(), m_MovementTarget->GetPositionY(), m_MovementTarget->GetPositionZ());
//}
//
//void BotAITankTarget::ClearTarget()
//{
//	if (m_MovementTarget)
//	{
//		delete m_MovementTarget;
//		m_MovementTarget = NULL;
//	}
//	m_Targets.clear();
//	m_MovementTick = 0;
//}
//
//void BotAITankTarget::SetMovement(Position& pos)
//{
//	m_MovementTick = 0;
//	if (m_MovementTarget)
//	{
//		delete m_MovementTarget;
//		m_MovementTarget = NULL;
//	}
//	m_MovementTarget = new Position(pos);
//}
//
//void BotAITankTarget::AddTarget(Creature* pCreature)
//{
//	if (!pCreature)
//		return;
//	for (ObjectGuid guid : m_Targets)
//	{
//		if (guid == pCreature->GetGUID())
//			return;
//	}
//	m_Targets.push_back(pCreature->GetGUID());
//}
//
//bool BotAITankTarget::IsSelfTarget(ObjectGuid target)
//{
//	if (target.IsEmpty())
//		return false;
//	for (ObjectGuid& guid : m_Targets)
//	{
//		if (guid == target)
//			return true;
//	}
//	return false;
//}
//
//bool BotAITankTarget::AllTargetPullMe()
//{
//	for (ObjectGuid& guid : m_Targets)
//	{
//		Creature* pCreature = me->GetMap()->GetCreature(guid);
//		if (!pCreature || !pCreature->IsAlive() || !me->IsValidAttackTarget(pCreature))
//			continue;
//		if (pCreature->GetTarget() != me->GetGUID())
//			return false;
//	}
//	return true;
//}
//
//bool BotAITankTarget::ExistPullTarget()
//{
//	for (ObjectGuid& guid : m_Targets)
//	{
//		Creature* pCreature = me->GetMap()->GetCreature(guid);
//		if (!pCreature || !pCreature->IsAlive() || !me->IsValidAttackTarget(pCreature))
//			continue;
//		return true;
//	}
//	ClearTarget();
//	return false;
//}
//
//Creature* BotAITankTarget::GetNeedPullTarget()
//{
//	for (ObjectGuid& guid : m_Targets)
//	{
//		Creature* pCreature = me->GetMap()->GetCreature(guid);
//		if (!pCreature || !pCreature->IsAlive() || !me->IsValidAttackTarget(pCreature))
//			continue;
//		if (pCreature->GetTarget() != me->GetGUID())
//			return pCreature;
//	}
//	return NULL;
//}
//
//bool BotAITankTarget::UpdateTankTarget(BotBGAIMovement* pMovement)
//{
//	if (!pMovement)
//		return false;
//	if (!me->IsInCombat() || me->IsFlying())
//	{
//		ClearTarget();
//		return false;
//	}
//	if (!m_MovementTarget)
//		return false;
//	if (!ExistPullTarget())
//		return false;
//	if (!AllTargetPullMe())
//	{
//		m_MovementTick = 0;
//		return false;
//	}
//	++m_MovementTick;
//	float distance = me->GetDistance(*m_MovementTarget);
//	if (distance < 1.0f)
//		return false;
//	if (m_MovementTick < 15)
//		pMovement->MovementTo(m_MovementTarget->GetPositionX(), m_MovementTarget->GetPositionY(), m_MovementTarget->GetPositionZ());
//	else
//	{
//		m_MovementTick = 0;
//		if (m_MovementTarget)
//		{
//			delete m_MovementTarget;
//			m_MovementTarget = NULL;
//		}
//	}
//	return true;
//}
//
//bool BotAIFly::HasFlying()
//{
//	if (m_FlyMountID == 0)
//		return false;
//	return me->HasAura(m_FlyMountID);
//}
//
//void BotAIFly::CancelFly()
//{
//    me->RemoveAurasDueToSpell(86461);
//    me->SetSpeedRate(MOVE_FLIGHT, 1.0f);
//	if (me->HasAura(m_FlyMountID))
//		me->RemoveOwnedAura(m_FlyMountID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
//    if(me->HasUnitFlag(UNIT_FLAG_MOUNT))
//        me->RemoveAurasByType(SPELL_AURA_MOUNTED);
//    me->SetCanFly(false);
//    me->SetDisableGravity(false);
//    me->RemoveUnitFlag(UNIT_FLAG_MOUNT);
//    me->RemoveAurasByType(SPELL_AURA_FLY);
//    me->RemoveAurasByType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED);
//}
//
//void BotAIFly::RandomFlyMount()
//{
//	CancelFly();
//    std::vector<uint32> flymounts;
//
//    flymounts.push_back(72807);
//    flymounts.push_back(242881);
//    flymounts.push_back(239013);
//    flymounts.push_back(230987);
//    flymounts.push_back(40192);
//    flymounts.push_back(253088);
//    flymounts.push_back(189999);
//    flymounts.push_back(75973);
//    flymounts.push_back(242881);
//    flymounts.push_back(40192);
//    flymounts.push_back(69395);
//    flymounts.push_back(120043);
//    flymounts.push_back(243512);
//    flymounts.push_back(48025);
//    flymounts.push_back(72286);
//    flymounts.push_back(127170);
//    flymounts.push_back(253107);
//    flymounts.push_back(201098);
//    flymounts.push_back(72808);
//    flymounts.push_back(88331);
//    flymounts.push_back(107842);
//    flymounts.push_back(127165);
//    flymounts.push_back(88746);
//    flymounts.push_back(242882);
//    flymounts.push_back(63796);
//    flymounts.push_back(97493);
//    flymounts.push_back(183117);
//    flymounts.push_back(139595);
//    flymounts.push_back(148392);
//    flymounts.push_back(98727);
//    flymounts.push_back(142878);
//    flymounts.push_back(225765);
//    flymounts.push_back(182912);
//    flymounts.push_back(239013);
//    flymounts.push_back(230987);
//    flymounts.push_back(139448);
//    flymounts.push_back(171828);
//    flymounts.push_back(97359);
//    flymounts.push_back(142073);
//    flymounts.push_back(171847);
//    flymounts.push_back(163025);
//    flymounts.push_back(127158);
//    flymounts.push_back(127169);
//    m_FlyMountID = Trinity::Containers::SelectRandomContainerElement(flymounts);
//}
//
//void BotAIFly::FlyToTarget(Player* player, bool offset)
//{
//	Group* pGroup = me->GetGroup();
//	if (!offset || !pGroup || pGroup->isBFGroup() || pGroup->isBGGroup())
//	{
//		me->GetMotionMaster()->Clear();
//		me->GetMotionMaster()->MovePoint(0, player->GetPosition(), false);
//	}
//	else
//	{
//		Position& pos = BotUtility::GetPositionFromGroup(player, me->GetGUID(), pGroup);
//		float dist = pos.GetExactDist(&m_LastFlyPos);
//		if (dist > 4.0f)
//		{
//			me->GetMotionMaster()->Clear();
//			me->GetMotionMaster()->MovePoint(0, pos, false);
//		}
//        else if (me->GetDistance(pos) <= 4.0f)
//            me->StopMoving();
//	}
//	me->SetFallInformation(501, me->GetPositionZ());
//	me->SetCanFly(true);
//}
//
//void BotAIFly::UpdateFly(Player* masterPlayer, uint32 groundMountID, BotBGAIMovement* pMovement)
//{
//	if (m_FlyMountID == 0 || !masterPlayer || !pMovement)
//		return;
//	if (me->GetMap() != masterPlayer->GetMap())
//		return;
//	if (me->HasUnitState(UNIT_STATE_CASTING))
//		return;
//
//	if (masterPlayer->IsFlying())
//	{
//		if (me->IsInCombat())
//			me->CombatStop();
//		if (HasFlying())
//		{
//			FlyToTarget(masterPlayer, true);
//		}
//		else
//		{
//            RandomFlyMount();
//			//if (me->HasAura(groundMountID))
//			//	me->RemoveOwnedAura(groundMountID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
//            me->AddAura(m_FlyMountID, me);
//        
//			//if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(m_FlyMountID))
//			//	Aura::TryRefreshStackOrCreate(spellInfo, me->GetGUID(), MAX_EFFECT_MASK, me, me);
//            if (me->HasAura(m_FlyMountID))
//			{
//				pMovement->ClearMovement();
//				me->SetCanFly(true);
//				m_LastFlyPos = masterPlayer->GetPosition();
//                me->SetDisableGravity(true);
//                me->AddAura(86461, me);
//                me->SetSpeedRate(MOVE_FLIGHT, 3.0f);
//			}
//		}
//	}
//	else
//	{
//		if (HasFlying())
//		{
//			float distance = me->GetDistance(masterPlayer->GetPosition());
//			if (distance > NEEDFLEE_CHECKRANGE)
//				FlyToTarget(masterPlayer, false);
//			else
//				CancelFly();
//		}
//	}
//}
//
//void BotAIWishStore::ClearStores()
//{
//	for (WISH_STORES::iterator itWish = m_WishStores.begin(); itWish != m_WishStores.end(); itWish++)
//	{
//		std::set<ObjectGuid>& wishs = itWish->second;
//		wishs.clear();
//	}
//	m_LastWishTick = 0;
//}
//
//void BotAIWishStore::RegisterWish(uint32 entry)
//{
//	if (entry == 0 || m_WishStores.find(entry) != m_WishStores.end())
//		return;
//	std::set<ObjectGuid>& guids = m_WishStores[entry];
//	m_LastWishTick = 0;
//}
//
//bool BotAIWishStore::CanWishStore(uint32 entry, Unit* pTarget)
//{
//	if (entry == 0 || !pTarget)
//		return true;
//	if (m_WishStores.empty() || m_WishStores.find(entry) == m_WishStores.end())
//		return true;
//	ObjectGuid guid = pTarget->GetGUID();
//	std::set<ObjectGuid>& guids = m_WishStores[entry];
//	if (guids.find(guid) != guids.end())
//		return false;
//	return true;
//}
//
//bool BotAIWishStore::TryWishStore(uint32 entry, Unit* pTarget)
//{
//	if (entry == 0 || !pTarget)
//		return true;
//	if (m_WishStores.empty() || m_WishStores.find(entry) == m_WishStores.end())
//		return true;
//	ObjectGuid guid = pTarget->GetGUID();
//	std::set<ObjectGuid>& guids = m_WishStores[entry];
//	if (guids.find(guid) != guids.end())
//		return false;
//	guids.insert(guid);
//	m_LastWishTick = getMSTime();
//	return true;
//}
//
//void BotAIWishStore::UpdateWishStore()
//{
//	uint32 curTick = getMSTime();
//	if (curTick < m_LastWishTick + (20 * 60000))
//		return;
//	m_LastWishTick = curTick;
//	ClearStores();
//}
//
//void BotAICheckSetting::UpdateCheckSetting()
//{
//	if (me->IsInCombat() || !me->IsPlayerBot())
//		return;
//	WorldSession* pSession = me->GetSession();
//	if (!me->IsInWorld() || !me->IsSettingFinish() || !pSession || pSession->HasSchedules() || pSession->IsAccountBotSession())
//	{
//		m_LastCheckTick = getMSTime();
//		return;
//	}
//
//	uint32 currentTick = getMSTime();
//	if (m_LastCheckTick + 30000 > currentTick)
//		return;
//	m_LastCheckTick = currentTick;
//	if (!NeedResetSetting())
//		return;
//	//PlayerBotSession* pBotSession = dynamic_cast<PlayerBotSession*>(pSession);
//	//if (!pBotSession)
//	//	return;
//	me->ResetPlayerToLevel(me->getLevel(), 3);
//}
//
//bool BotAICheckSetting::NeedResetSetting()
//{
//	if (!CheckEquip())
//		return true;
//	return false;
//}
//
//bool BotAICheckSetting::CheckEquip()
//{
//	bool allSlotNull = true;
//	for (uint8 slot = EquipmentSlots::EQUIPMENT_SLOT_HEAD; slot < EquipmentSlots::EQUIPMENT_SLOT_END; slot++)
//	{
//		uint16 pos = (255 << 8) | slot;
//		if (me->IsEquipmentPos(pos) || me->IsBagPos(pos))
//		{
//			InventoryResult msg = me->CanUnequipItem(pos, false);
//			if (msg != EQUIP_ERR_OK)
//				continue;
//		}
//		Item* pItem = me->GetItemByPos(255, slot);
//		if (!pItem)
//			continue;
//		allSlotNull = false;
//		const ItemTemplate* pTemplate = pItem->GetTemplate();
//		if (!pTemplate)
//			continue;
//		if (pTemplate->GetBaseRequiredLevel() > me->getLevel())
//			return false;
//	}
//	return !allSlotNull;
//}
//
//bool BotAIFliterCreatures::IsFliterCreature(Creature* pCreature)
//{
//	if (!pCreature)
//		return false;
//	std::map<Creature*, uint32>::iterator itFliter = m_Fliters.find(pCreature);
//	if (itFliter == m_Fliters.end())
//		return false;
//	uint32 currentTick = getMSTime();
//	if (itFliter->second + m_FliterTime < currentTick)
//	{
//		m_Fliters.erase(itFliter);
//		return false;
//	}
//	return true;
//}
//
//void BotAIFliterCreatures::UpdateFliterCreature(Creature* pCreature)
//{
//	if (!pCreature)
//		return;
//	m_Fliters[pCreature] = getMSTime();
//}
//
//void BotAIFliterCreatures::RemoveFliterCreature(Creature* pCreature)
//{
//	std::map<Creature*, uint32>::iterator itFliter = m_Fliters.find(pCreature);
//	if (itFliter == m_Fliters.end())
//		return;
//	m_Fliters.erase(itFliter);
//}
//
//void BotAIWaitSpecialAura::AddSpecialAura(uint32 id)
//{
//	if (id == 0)
//		return;
//	if (m_NeedWaitAuras.find(id) == m_NeedWaitAuras.end())
//		m_NeedWaitAuras.insert(id);
//}
//
//bool BotAIWaitSpecialAura::HasNeedWaitAura()
//{
//	for (std::set<uint32>::iterator itAura = m_NeedWaitAuras.begin();
//		itAura != m_NeedWaitAuras.end();
//		itAura++)
//	{
//		uint32 aura = *itAura;
//		if (me->HasAura(aura))
//			return true;
//	}
//	return false;
//}
//
//void BotAINeedFleeAura::AddFleeAura(uint32 aura)
//{
//	if (aura == 0)
//		return;
//	for (uint32 hasAura : m_NeedFleeAuras)
//	{
//		if (aura == hasAura)
//			return;
//	}
//	m_NeedFleeAuras.push_back(aura);
//}
//
//bool BotAINeedFleeAura::TargetHasFleeAura(Unit* pTarget)
//{
//	if (!pTarget || pTarget == me)
//		return false;
//	if (me->GetDistance(pTarget->GetPosition()) > NEEDFLEE_CHECKRANGE)
//		return false;
//	for (uint32 aura : m_NeedFleeAuras)
//	{
//		if (pTarget->HasAura(aura))
//			return true;
//	}
//	return false;
//}
//
//void BotAIRecordCastSpell::RecordCastSpellTick(Unit* pTarget, uint32 spellID)
//{
//	if (!pTarget || !pTarget->IsAlive() || spellID == 0)
//		return;
//	if (m_Records.find(pTarget->GetGUID()) == m_Records.end())
//	{
//		CastedSpell record(pTarget->GetGUID());
//		record.castRecords[spellID] = getMSTime();
//		m_Records[pTarget->GetGUID()] = record;
//	}
//	else
//	{
//		CastedSpell& record = m_Records[pTarget->GetGUID()];
//		record.castRecords[spellID] = getMSTime();
//	}
//}
//
//bool BotAIRecordCastSpell::MatchCastRecord(Unit* pTarget, uint32 spellID, uint32 tickGap)
//{
//	if (!pTarget || !pTarget->IsAlive() || spellID == 0 || tickGap == 0)
//		return false;
//	if (m_Records.find(pTarget->GetGUID()) == m_Records.end())
//		return true;
//
//	CastedSpell& record = m_Records[pTarget->GetGUID()];
//	if (record.castRecords.find(spellID) == record.castRecords.end())
//		return true;
//	uint32 recordTick = record.castRecords[spellID];
//	return (recordTick + tickGap) <= getMSTime();
//}
//
//bool BotAICheckDuel::CheckDuel()
//{
//	if (!me->duel)
//		return false;
//	DuelInfo* duel = me->duel;
//	if (duel->isCompleted || duel->startTime > 0 || duel->startTimer > 0)
//		return false;
//	if (!duel->initiator || duel->initiator->IsPlayerBot())
//	{
//		BotUtility::TryCancelDuel(me);
//		return false;
//	}
//	if (!duel->opponent || duel->opponent == me)
//	{
//		BotUtility::TryCancelDuel(me);
//		return false;
//	}
//	if (me->IsInCombat() || !me->IsInWorld() || !me->IsSettingFinish() ||
//		me->GetMap()->IsDungeon() || me->isUsingLfg() || me->InBattleground() || me->InArena())
//	{
//		BotUtility::TryCancelDuel(me);
//		return false;
//	}
//
//	WorldSession* pSession = me->GetSession();
//	if (!pSession || pSession->HasSchedules())
//	{
//		BotUtility::TryCancelDuel(me);
//		return false;
//	}
//	pSession->HandleDuelAccepted();
//	return true;
//}
//
//void BotAIGroupLeader::ProcessGroupLeader()
//{
//	Group* pGroup = me->GetGroup();
//	if (!pGroup || !pGroup->IsLeader(me->GetGUID()))
//		return;
//	Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
//	for (Group::MemberSlot const& slot : memList)
//	{
//		Player* player = ObjectAccessor::FindConnectedPlayer(slot.guid);
//		if (!player || player->IsPlayerBot())
//			continue;
//		if (!player->IsAlive() || me->GetMap() != player->GetMap() || !me->IsInWorld() || !player->IsInWorld())
//			continue;
//		pGroup->ChangeLeader(player->GetGUID());
//		pGroup->SendUpdate();
//	}
//}
//
//bool BotAIMovetoUseGO::CanCastSummonRite()
//{
//	if (m_RiteSpellID || m_UseGO != ObjectGuid::Empty || me->HasUnitState(UNIT_STATE_CASTING) || !me->IsInWorld())
//		return false;
//	return true;
//}
//
//bool BotAIMovetoUseGO::SetNeedMovetoUseGO(ObjectGuid guid)
//{
//	if (guid != ObjectGuid::Empty)
//	{
//		if (m_RiteSpellID)
//			return false;
//		if (m_UseGO == ObjectGuid::Empty)
//		{
//			m_UseGO = guid;
//			return true;
//		}
//	}
//	else
//	{
//		ClearUseGO();
//		return true;
//	}
//	return false;
//}
//
//void BotAIMovetoUseGO::StartSummonRite(uint32 spellID)
//{
//	if (!spellID || m_RiteSpellID)
//		return;
//	m_RiteSpellID = spellID;
//}
//
//bool BotAIMovetoUseGO::ProcessMovetoUseGO(BotBGAIMovement* pMovement)
//{
//	if (m_RiteSpellID)
//	{
//		if (!me->HasUnitState(UNIT_STATE_CASTING))
//		{
//			ClearUseGO();
//			return false;
//		}
//		if (GameObject* go = me->GetGameObject(m_RiteSpellID))
//		{
//			ClearUseGO();
//			uint32 pickCount = 0;
//			Group* pGroup = me->GetGroup();
//			Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
//			for (Group::MemberSlot const& slot : memList)
//			{
//				Player* player = ObjectAccessor::FindPlayer(slot.guid);
//				if (!player || !player->IsPlayerBot() || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld())
//					continue;
//				if (player == me || player->IsInCombat() || player->HasUnitState(UNIT_STATE_CASTING))
//					continue;
//				if (me->GetDistance(player->GetPosition()) > BOTAI_RANGESPELL_DISTANCE)
//					continue;
//				if (BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(player->GetAI()))
//				{
//					if (pAI->SetMovetoUseGOTarget(go->GetGUID()))
//					{
//						pAI->Dismount();
//						++pickCount;
//						if (pickCount >= 3)
//							return true;
//					}
//				}
//				else if (BotBGAI* pAI = dynamic_cast<BotBGAI*>(player->GetAI()))
//				{
//					if (pAI->SetMovetoUseGOTarget(go->GetGUID()))
//					{
//						pAI->Dismount();
//						++pickCount;
//						if (pickCount >= 3)
//							return true;
//					}
//				}
//			}
//		}
//		return true;
//	}
//
//	if (m_UseGO == ObjectGuid::Empty)
//		return false;
//	if (!pMovement || me->HasUnitState(UNIT_STATE_CASTING) || !me->IsInWorld())
//		return true;
//	Map* pMap = me->GetMap();
//	if (!pMap)
//	{
//		ClearUseGO();
//		return false;
//	}
//	if (GameObject* pGO = pMap->GetGameObject(m_UseGO))
//	{
//		float dist = me->GetDistance(pGO->GetPosition());
//		if (dist < 1.5f)
//		{
//			if (me->m_unitMovedByMe != me)
//			{
//				if (!(me->IsOnVehicle(me->m_unitMovedByMe) || me->IsMounted()) && !pGO->GetGOInfo()->IsUsableMounted())
//				{
//					ClearUseGO();
//					return false;
//				}
//			}
//			pMovement->ClearMovement();
//			pGO->Use(me);
//			ClearUseGO();
//		}
//		//else if (dist > BOTAI_RANGESPELL_DISTANCE)
//		//{
//		//	ClearUseGO();
//		//	return false;
//		//}
//		else
//		{
//			pMovement->MovementTo(m_UseGO, 1.0f);
//		}
//	}
//	else
//	{
//		ClearUseGO();
//		return false;
//	}
//	return true;
//}
//
//bool BotAIMoveToHaltPosition::ProcessMovetoPosition(BotBGAIMovement* pMovement)
//{
//	if (!pMovement || !HasMoveto() || m_MovetoTick == 0)
//		return false;
//	if (m_CurrentTick >= m_MovetoTick)
//	{
//		ClearMoveto();
//		return false;
//	}
//
//	if (me->GetDistance(m_MovetoPos) <= 1.0f)
//	{
//		m_CurrentTick += BOTAI_UPDATE_TICK;
//	}
//	pMovement->MovementTo(m_MovetoPos.GetPositionX(), m_MovetoPos.GetPositionY(), m_MovetoPos.GetPositionZ());
//	return true;
//}
