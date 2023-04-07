
//#include "G3D/stringutils.h"
#include "BotGroupAI.h"
#include "MoveSplineInit.h"
#include "BotBGAIMovement.h"
#include "PlayerBotMgr.h"
#include "PlayerBotSession.h"
#include "Group.h"
#include "Spell.h"
#include "Pet.h"
#include "BotGroupClassAI.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridDefines.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ItemTemplate.h"
#include "Item.h"
#include "Bag.h"
#include "TradeData.h"
#include "ItemPackets.h"
#include "Config.h"

//BotGroupAI* BotGroupAI::debugGroupAI = NULL   //Duplicate define
//bool BotGroupAI::PVE_MAX_DUNGEON = false;     //Duplicate define
//bool BotGroupAI::PVE_DRIVING = true;          //Duplicate define
//bool BotGroupAI::PVE_PULL = true              //Duplicate define

//BotGroupAI* BotGroupAI::CreateBotGroupAIByPlayerClass(Player* player)
//{
//    PlayerBotSetting::ClearUnknowMount(player);
//    BotGroupAI* pAI = NULL;
//    switch (player->getClass())
//    {
//    case CLASS_WARRIOR:
//        pAI = new GroupWarriorAI(player);
//        break;
//    case CLASS_MAGE:
//        pAI = new GroupMageAI(player);
//        break;
//    case CLASS_PRIEST:
//        pAI = new GroupPriestAI(player);
//        break;
//    case CLASS_HUNTER:
//        pAI = new GroupHunterAI(player);
//        break;
//    case CLASS_WARLOCK:
//        pAI = new GroupWarlockAI(player);
//        break;
//    case CLASS_PALADIN:
//        pAI = new GroupPaladinAI(player);
//        break;
//    case CLASS_ROGUE:
//        pAI = new GroupRogueAI(player);
//        break;
//    case CLASS_SHAMAN:
//        pAI = new GroupShamanAI(player);
//        break;
//    case CLASS_DRUID:
//        pAI = new GroupDruidAI(player);
//        break;
//    case CLASS_DEATH_KNIGHT:
//        pAI = new GroupDeathknightAI(player);
//        break;
//    case CLASS_DEMON_HUNTER:
//        pAI = new GroupDemonHunterAI(player);
//        break;
//    case CLASS_MONK:
//        pAI = new GroupMonkAI(player);
//        break;
//    }
//    if (!pAI)
//        pAI = new BotGroupAI(player);
//    pAI->ResetBotAI();
//    return pAI;
//}
//
//BotGroupAI::BotGroupAI(Player* player) :
//    PlayerAI(player),
//    m_UpdateTick(BOTAI_UPDATE_TICK),
//    m_DuelEmoteTick(0),
//    m_Movement(new BotBGAIMovement(player, this)),
//    m_VehicleMovement3D(new BotAIVehicleMovement3D(player)),
//    m_UseMountID(PlayerBotSetting::RandomMountByLevel(player->getLevel())),
//    m_Guild(player),
//    pHorrorState(NULL),
//    m_CheckStoped(player),
//    m_Teleporting(player),
//    m_UseFood(player),
//    m_UsePotion(player),
//    m_FindLoot(player),
//    m_LootedItems(player),
//    m_AITrade(player),
//    m_DelayGiveXP(player),
//    m_Revive(player),
//    m_RevivePlayer(player),
//    m_Flee(player),
//    m_CruxMovement(player),
//    m_TankTargets(player),
//    m_Flying(player),
//    m_WishStore(player),
//    m_FliterCreatures(player),
//    m_WaitAuras(player),
//    m_CheckDuel(player),
//    m_FastAid(player),
//    m_MovetoUseGO(player),
//    m_GroupLeader(player),
//    m_MovetoHaltPos(player),
//    m_CruxHealTarget(ObjectGuid::Empty),
//    m_SeduceTarget(ObjectGuid::Empty),
//    m_MasterPlayer(NULL),
//    m_FullDispel(0),
//    m_MeleeFleeTick(0),
//    m_ForceFlee(false),
//    m_StopFollow(false),
//    m_HasReset(false),
//    m_UpdateEquit(false)
//{
//    if (!me->IsPvP())
//    {
//        BotUtility::PlayerBotTogglePVP(player, true);
//    }
//    m_UpdateEquit = sConfigMgr->GetBoolDefault("PBot.UpdateEquip", false);
//}
//
//BotGroupAI::~BotGroupAI()
//{
//    if (m_VehicleMovement3D)
//    {
//        delete m_VehicleMovement3D;
//        m_VehicleMovement3D = NULL;
//    }
//}
//
//bool BotGroupAI::CanReciveCommand(std::string& cmd, std::string& param)
//{
//    if (cmd.empty())
//        return false;
//    if (cmd[0] == '@')
//    {
//        int32 firstEndIndex = cmd.find(' ');
//        if (firstEndIndex <= 1)
//            return false;
//        std::string target = cmd.substr(1, firstEndIndex - 1);
//        std::string realCmd = cmd.substr(firstEndIndex + 1);
//        if (realCmd.empty())
//            return false;
//        if (target == "tank")
//        {
//            if (!IsTankBotAI())
//                return false;
//        }
//        else if (target == "melee")
//        {
//            if (!IsMeleeBotAI() || IsHealerBotAI())
//                return false;
//        }
//        else if (target == "ranged")
//        {
//            if (!IsRangeBotAI() || IsHealerBotAI())
//                return false;
//        }
//        else if (target == "dps")
//        {
//            if (IsTankBotAI() || IsHealerBotAI())
//                return false;
//        }
//        else if (target == "heal")
//        {
//            if (!IsHealerBotAI())
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_WARRIOR)
//        {
//            if (target != "zs")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_PALADIN)
//        {
//            if (target != "qs")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_HUNTER)
//        {
//            if (target != "lr")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_ROGUE)
//        {
//            if (target != "dz")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_PRIEST)
//        {
//            if (target != "ms")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_DEATH_KNIGHT)
//        {
//            if (target != "dk")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_SHAMAN)
//        {
//            if (target != "sm")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_MAGE)
//        {
//            if (target != "fs")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_WARLOCK)
//        {
//            if (target != "ss")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_DRUID)
//        {
//            if (target != "xd")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_DEMON_HUNTER)
//        {
//            if (target != "dh")
//                return false;
//        }
//
//        int32 secondEndIndex = realCmd.find(' ');
//        if (secondEndIndex <= 0)
//            cmd = realCmd;
//        else
//        {
//            cmd = realCmd.substr(0, secondEndIndex);
//            param = realCmd.substr(secondEndIndex + 1);
//        }
//    }
//    else
//    {
//        int32 firstEndIndex = cmd.find(' ');
//        if (firstEndIndex < 0)
//            return true;
//        std::string realCmd = cmd.substr(0, firstEndIndex);
//        param = cmd.substr(firstEndIndex + 1);
//        cmd = realCmd;
//    }
//    return true;
//}
//
//void BotGroupAI::ProcessSummonCommand()
//{
//    if (!m_MasterPlayer)
//        return;
//    m_ForceFlee = false;
//    m_StopFollow = false;
//    m_SeduceTarget = ObjectGuid::Empty;
//    me->SetSelection(ObjectGuid::Empty);
//    if (m_Teleporting.CanMovement() && !m_MasterPlayer->IsFlying())
//        m_Teleporting.SetTeleport(m_MasterPlayer, 0);
//}
//
//void BotGroupAI::ProcessMoveToCommand(float x, float y, float z, float o, float offset)
//{
//    if (!m_MasterPlayer)
//        return;
//    m_StopFollow = true;
//    m_Movement->ClearMovement();
//    m_Movement->MovementTo(x, y, z, offset);
//}
//
//void BotGroupAI::ProcessAttackCommand()
//{
//    Unit* pMasterTarget = m_MasterPlayer->GetSelectedUnit();
//    if (!pMasterTarget || !pMasterTarget->IsAlive())
//        return;
//    if (!me->IsValidAttackTarget(pMasterTarget))
//        return;
//    me->SetSelection(pMasterTarget->GetGUID());
//    m_ForceFlee = false;
//    m_StopFollow = false;
//    m_SeduceTarget = ObjectGuid::Empty;
//}
//
//void BotGroupAI::ProcessFleeCommand()
//{
//    me->SetSelection(ObjectGuid::Empty);
//    m_SeduceTarget = ObjectGuid::Empty;
//    m_ForceFlee = true;
//}
//
//void BotGroupAI::ProcessStopCommand()
//{
//    me->SetSelection(ObjectGuid::Empty);
//    m_SeduceTarget = ObjectGuid::Empty;
//    m_StopFollow = true;
//}
//
//void BotGroupAI::ProcessSetting()
//{
//    if (!m_MasterPlayer || !me->IsInWorld() || !me->IsAlive() || me->IsInCombat() || !m_Teleporting.CanMovement() || m_UseFood.HasFoodState())
//        return;
//    if (me->HasUnitState(UNIT_STATE_CASTING))
//        return;
//    if (!me->IsSettingFinish())
//        return;
//    PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(me->GetSession());
//    if (!pSession)
//        return;
//    if (pSession->HasSchedules())
//        return;
//
//    BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting);
//    schedule2.parameter1 = m_MasterPlayer->getLevel();
//    schedule2.parameter2 = m_MasterPlayer->getLevel();
//    schedule2.parameter3 = PlayerBotSetting::FindPlayerTalentType(me) + 1;
//    schedule2.parameter4 = m_UpdateEquit + 1;
//    pSession->PushScheduleToQueue(schedule2);
//    me->ResetTalents(true);
//    m_HasReset = false;
//}
//
//void BotGroupAI::ProcessListEquip(Player* srcPlayer)
//{
//    std::lock_guard<std::mutex> lock(m_ItemLock);
//    if (!srcPlayer || srcPlayer->IsPlayerBot())
//        return;
//    WorldSession* pSession = srcPlayer->GetSession();
//    std::list<std::string> needSendText;
//    for (uint8 slot = InventoryPackSlots::INVENTORY_SLOT_ITEM_START; slot < InventoryPackSlots::INVENTORY_SLOT_ITEM_END; slot++)
//    {
//        Item* pItem = me->GetItemByPos(255, slot);
//        if (!pItem)
//            continue;
//        const ItemTemplate* pTemplate = pItem->GetTemplate();
//        if (!pTemplate)
//            continue;
//        std::string& itemLink = BotUtility::BuildItemLinkText(pTemplate);
//        char outputText[256] = { 0 };
//        sprintf_s(outputText, 255, "%s x %d", itemLink.c_str(), pItem->GetCount());
//        //me->Whisper(std::string(outputText), Language::LANG_COMMON, srcPlayer);
//        needSendText.push_back(std::string(outputText));
//        //WorldPacket cmd(1);//todo47
//        //cmd << pTemplate->GetId();
//        //pSession->HandleItemQuerySingleOpcode(cmd);
//    }
//    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
//    {
//        if (Bag* pBag = me->GetBagByPos(i))
//        {
//            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
//            {
//                Item* pItem = pBag->GetItemByPos(uint8(j));
//                if (!pItem)
//                    continue;
//                const ItemTemplate* pTemplate = pItem->GetTemplate();
//                if (!pTemplate)
//                    continue;
//                std::string& itemLink = BotUtility::BuildItemLinkText(pTemplate);
//                char outputText[256] = { 0 };
//                sprintf_s(outputText, 255, "%s x %d", itemLink.c_str(), pItem->GetCount());
//                //me->Whisper(std::string(outputText), Language::LANG_COMMON, srcPlayer);
//                needSendText.push_back(std::string(outputText));
//                //WorldPacket cmd(1);
//                //cmd << pTemplate->GetId();
//                //pSession->HandleItemQuerySingleOpcode(cmd);
//            }
//        }
//    }
//
//    for (std::string& sendText : needSendText)
//    {
//        me->Whisper(sendText, Language::LANG_COMMON, srcPlayer);
//    }
//}
//
//void BotGroupAI::ProcessUpequip(Player* srcPlayer, std::string& equipLink)
//{
//    std::lock_guard<std::mutex> lock(m_ItemLock);
//    if (me->IsInCombat())
//        return;
//    if (!srcPlayer || equipLink.empty())
//        return;
//    int firstIndex = equipLink.find(':');
//    uint32 entry = 0;
//    if (firstIndex < 0)
//        entry = atoi(equipLink.c_str());
//    //if (entry == 0)   //tmp
//    //    entry = BotUtility::GetFirstNumberByString(equipLink.substr(firstIndex));
//    if (entry == 0)
//        return;
//
//    uint8 bag = 255;
//    uint8 index = 0;
//    Item* pItem = BotUtility::FindItemFromAllBag(me, entry, bag, index);
//    if (pItem == NULL)
//        return;
//
//    uint16 dest;
//    InventoryResult msg = me->CanEquipItem(NULL_SLOT, dest, pItem, !pItem->IsBag());
//    if (msg != EQUIP_ERR_OK)
//    {
//        std::string outString;
//        consoleToUtf8(std::string("????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//        return;
//    }
//
//    WorldPacket packet;
//    WorldPackets::Item::AutoEquipItem sPacket(std::move(packet));
//    sPacket.Inv.Items.resize(1);
//    sPacket.PackSlot = bag;
//    sPacket.Slot = index;
//    me->GetSession()->HandleAutoEquipItemOpcode(sPacket);
//
//    std::string outString;
//    consoleToUtf8(std::string("????"), outString);
//    me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//}
//
//void BotGroupAI::ProcessUnequip(Player* srcPlayer, std::string& equipLink)
//{
//    std::lock_guard<std::mutex> lock(m_ItemLock);
//    if (me->IsInCombat())
//        return;
//    if (!srcPlayer || equipLink.empty())
//        return;
//    int firstIndex = equipLink.find(':');
//    if (firstIndex < 0)
//        return;
//    //tmp    uint32 entry = BotUtility::GetFirstNumberByString(equipLink.substr(firstIndex));
//    if (entry == 0)
//        return;
//    for (uint8 slot = EquipmentSlots::EQUIPMENT_SLOT_HEAD; slot < EquipmentSlots::EQUIPMENT_SLOT_END; slot++)
//    {
//        uint16 pos = (255 << 8) | slot;
//        if (me->IsEquipmentPos(pos) || me->IsBagPos(pos))
//        {
//            InventoryResult msg = me->CanUnequipItem(pos, false);
//            if (msg != EQUIP_ERR_OK)
//                continue;
//        }
//        Item* pItem = me->GetItemByPos(255, slot);
//        if (!pItem)
//            continue;
//        const ItemTemplate* pTemplate = pItem->GetTemplate();
//        if (!pTemplate || pTemplate->GetId() != entry)
//            continue;
//
//        uint32 noSpaceForCount = 0;
//        ItemPosCountVec dest;
//        InventoryResult msg = me->CanStoreItem(NULL_BAG, NULL_SLOT, dest, pItem);
//        if (msg != EQUIP_ERR_OK)
//        {
//            std::string outString;
//            consoleToUtf8(std::string("????"), outString);
//            me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//            return;
//        }
//        me->RemoveItem(255, slot, true);
//        me->StoreItem(dest, pItem, true);
//        std::string outString;
//        consoleToUtf8(std::string("????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//        return;
//    }
//    std::string outString;
//    consoleToUtf8(std::string("????"), outString);
//    me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//}
//
//void BotGroupAI::ProcessDestroyItem(Player* srcPlayer, std::string& equipLink)
//{
//    std::lock_guard<std::mutex> lock(m_ItemLock);
//    if (me->IsInCombat())
//        return;
//    if (!srcPlayer || equipLink.empty())
//        return;
//    int firstIndex = equipLink.find(':');
//    if (firstIndex < 0)
//        return;
//    //tmp    uint32 entry = BotUtility::GetFirstNumberByString(equipLink.substr(firstIndex));
//    if (entry == 0)
//        return;
//    BotUtility::FindItemFromAllBag(me, entry, true);
//    std::string outString;
//    consoleToUtf8(std::string("????"), outString);
//    me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//}
//
//void BotGroupAI::ProcessTradeItem(Player* srcPlayer, std::string& equipLink)
//{
//    std::lock_guard<std::mutex> lock(m_ItemLock);
//    if (me->IsInCombat())
//        return;
//    if (!srcPlayer || equipLink.empty())
//        return;
//    int firstIndex = equipLink.find(':');
//    if (firstIndex < 0)
//        return;
//    //tmp    uint32 entry = BotUtility::GetFirstNumberByString(equipLink.substr(firstIndex));
//    if (entry == 0)
//    {
//        std::string outString;
//        consoleToUtf8(std::string("???????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//        return;
//    }
//    Item* pItem = BotUtility::FindItemFromAllBag(me, entry, false);
//    if (!pItem)
//    {
//        std::string outString;
//        consoleToUtf8(std::string("??????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//        return;
//    }
//    TradeData* pTrade = me->GetTradeData();
//    if (!pTrade)
//    {
//        std::string outString;
//        consoleToUtf8(std::string("??????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//        return;
//    }
//    Player* pTradePlayer = pTrade->GetTrader();
//    if (!pTradePlayer)
//    {
//        std::string outString;
//        consoleToUtf8(std::string("??????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//        return;
//    }
//    TradeData* pTraderData = pTradePlayer->GetTradeData();
//    if (!pTraderData)
//    {
//        me->TradeCancel(false);
//        return;
//    }
//    if (pTrade->HasItem(pItem->GetGUID()))
//    {
//        std::string outString;
//        consoleToUtf8(std::string("??????????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//        return;
//    }
//    //if (!pItem->CanBeTraded(false, true))
//    //{
//    //	std::string outString;
//    //	consoleToUtf8(std::string("????????"), outString);
//    //	me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//    //	return;
//    //}
// //   if (pTrade->SetItemAtNullSlot(pItem))
//    {
//        std::string outString;
//        consoleToUtf8(std::string("????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//    }
//   /* else
//    {
//        std::string outString;
//        consoleToUtf8(std::string("???????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//    }*/
//}
//
//void BotGroupAI::ProcessUseItem(Player* srcPlayer, std::string& equipLink)
//{
//    std::lock_guard<std::mutex> lock(m_ItemLock);
//    if (!srcPlayer || equipLink.empty())
//        return;
//    int firstIndex = equipLink.find(':');
//    if (firstIndex < 0)
//        return;
//    //tmp    uint32 entry = BotUtility::GetFirstNumberByString(equipLink.substr(firstIndex));
//    if (entry == 0)
//        return;
//    Item* pItem = BotUtility::FindItemFromAllBag(me, entry);
//    if (!pItem)
//        return;
//
//    m_Movement->ClearMovement();
//    SpellCastTargets targets;
//    targets.SetTargetMask(0);
//
//    if (me->CastItemUseSpell(pItem, targets, 0, 0) == SpellCastResult::SPELL_CAST_OK)
//    {
//        std::string outString;
//        consoleToUtf8(std::string("????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//        return;
//    }
//    std::string outString;
//    consoleToUtf8(std::string("????"), outString);
//    me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//}
//
//void BotGroupAI::ProcessTalent(Player* srcPlayer, std::string& talentText)
//{
//    std::lock_guard<std::mutex> lock(m_ItemLock);
//    if (!srcPlayer)
//        return;
//    if (!me->IsInWorld() || me->IsInCombat() || me->HasUnitState(UNIT_STATE_CASTING) || !me->IsSettingFinish())
//        return;
//    uint32 talentType = talentText.empty() ? 3 : uint32(atoi(talentText.c_str()));
//    if (talentType > 3)
//        talentType = 3;
//    //talentType = 0;//
//  //  me->SwitchTalent(talentType);//todo47
//   
//    //GetSpecializationId
//    OnLevelUp(talentType);
//    m_HasReset = false;
//
// //   GetTalentSpell();
//
//    std::string outString;
//    consoleToUtf8(std::string("??????"), outString);
//    me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//}
//
//void BotGroupAI::ProcessTalentTo(Player* srcPlayer, std::string talentText)
//{
//    std::lock_guard<std::mutex> lock(m_ItemLock);
//    if (!srcPlayer)
//        return;
//    if (!me->IsInWorld() || me->IsInCombat() || me->HasUnitState(UNIT_STATE_CASTING) || !me->IsSettingFinish())
//        return;
//    uint32 talentType = 0;
//
//    if (talentText == "health")
//    {
//        switch (me->getClass())
//        {
//        case CLASS_PALADIN:
//            talentType = TALENT_SPEC_PALADIN_HOLY;
//            break;
//        case CLASS_PRIEST:
//            talentType = TALENT_SPEC_PRIEST_HOLY;
//            break;
//        case CLASS_SHAMAN:
//            talentType = TALENT_SPEC_SHAMAN_RESTORATION;
//            break;
//        case CLASS_DRUID:
//            talentType = TALENT_SPEC_DRUID_RESTORATION;
//            break;
//        case CLASS_MONK:
//            talentType = TALENT_SPEC_MONK_MISTWEAVER;
//            break;
//        default:
//            break;
//        }
//    }
//    if (talentText == "tank")
//    {
//        switch (me->getClass())
//        {
//        case CLASS_PALADIN:
//            talentType = TALENT_SPEC_PALADIN_PROTECTION;
//            break;
//        case CLASS_WARRIOR:
//            talentType = TALENT_SPEC_WARRIOR_PROTECTION;
//            break;
//        case CLASS_DEATH_KNIGHT:
//            talentType = TALENT_SPEC_DEATHKNIGHT_BLOOD;
//            break;
//        case CLASS_DRUID:
//            talentType = TALENT_SPEC_DRUID_BEAR;
//            break;
//        case CLASS_MONK:
//            talentType = TALENT_SPEC_MONK_BREWMASTER;
//            break;
//        case CLASS_DEMON_HUNTER:
//            talentType = TALENT_SPEC_DEMON_HUNTER_VENGEANCE;
//            break;
//        default:
//            break;
//        }
//    }
//    if (talentType > 0)
//    {
//        if (ChrSpecializationEntry const* spec = sChrSpecializationStore.AssertEntry(talentType))
//            if (!spec->IsPetSpecialization())
//                me->ActivateTalentGroup(spec);
//        OnLevelUp(talentType);
//
//        //GetTalentSpell();
//
//        m_HasReset = false;
//        std::string outString;
//        if (talentText == "health")
//            consoleToUtf8(std::string("????????"), outString);
//        if (talentText == "tank")
//            consoleToUtf8(std::string("????????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//    }    
//}
//
//void BotGroupAI::ProcessSummonRiteSpell(Player* srcPlayer)
//{
//    if (!srcPlayer || !srcPlayer->IsInWorld() || HasTeleport() || me->GetMap() != srcPlayer->GetMap())
//        return;
//    if (srcPlayer->GetDistance(me->GetPosition()) > BOTAI_RANGESPELL_DISTANCE)
//        return;
//
//    if (!m_MovetoUseGO.CanCastSummonRite())
//    {
//        std::string outString;
//        consoleToUtf8(std::string("??????????"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//        return;
//    }
//    uint32 castSpellID = TryCastSummonRiteSpell();
//    if (castSpellID)
//    {
//        m_MovetoUseGO.StartSummonRite(castSpellID);
//        std::string outString;
//        consoleToUtf8(std::string("??????!"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//    }
//    else
//    {
//        std::string outString;
//        consoleToUtf8(std::string("??????????!"), outString);
//        me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//    }
//}
//
//void BotGroupAI::ProcessBotCommand(Player* srcPlayer, std::string cmd)
//{
//    if (!m_MasterPlayer || !srcPlayer)
//        return;
//    std::string param;
//    if (!CanReciveCommand(cmd, param))
//        return;
//    if (cmd == "999")
//    {
//        if (m_MasterPlayer)
//        {
//            if (!m_MasterPlayer->IsAlive())
//            {
//                m_MasterPlayer->ResurrectPlayer(100.0f);
//                m_MasterPlayer->SpawnCorpseBones();
//                m_MasterPlayer->SaveToDB();
//                m_MasterPlayer->DurabilityRepairAll(false, 1.0f, false);
//                return;
//            }
//
//            ObjectGuid& guid = m_RevivePlayer.SearchNeedRevive(BOTAI_UPDATE_TICK);
//            if (guid.IsEmpty())
//                return;
//            if(Player* pRevive = ObjectAccessor::FindPlayer(guid))
//            {
//                if (!pRevive->IsAlive())
//                {
//                    pRevive->ResurrectPlayer(100.0f);
//                    pRevive->SpawnCorpseBones();
//                    pRevive->SaveToDB();
//                    pRevive->DurabilityRepairAll(false, 1.0f, false);
//                }
//            }              
//        }
//    } else if (cmd == "summon")
//        ProcessSummonCommand();
//    else if (cmd == "attack")
//        ProcessAttackCommand();
//    else if (cmd == "follow")
//    {
//        me->SetSelection(ObjectGuid::Empty);
//        m_ForceFlee = false;
//        m_StopFollow = false;
//    }
//    else if (cmd == "flee")
//        ProcessFleeCommand();
//    else if (cmd == "stop")
//        ProcessStopCommand();
//    else if (cmd == "setting")
//    {
//        m_UpdateEquit = true;
//        ProcessSetting();
//    }
//    else if (cmd == "settinglevel")
//    {
//        m_UpdateEquit = false;
//        ProcessSetting();
//    }
//    else if (cmd == "c")
//        ProcessListEquip(srcPlayer);
//    else if (cmd == "e")
//        ProcessUpequip(srcPlayer, param);
//    else if (cmd == "ue")
//        ProcessUnequip(srcPlayer, param);
//    else if (cmd == "destroy")
//        ProcessDestroyItem(srcPlayer, param);
//    else if (cmd == "s")
//        ProcessTradeItem(srcPlayer, param);
//    else if (cmd == "u")
//        ProcessUseItem(srcPlayer, param);
//    else if (cmd == "talent")
//        ProcessTalent(srcPlayer, param);
//    else if (cmd == "tank")
//        ProcessTalentTo(srcPlayer, cmd);
//    else if (cmd == "health")
//        ProcessTalentTo(srcPlayer, cmd);
//    else if (cmd == "rite")
//        ProcessSummonRiteSpell(srcPlayer);
//}
//
//void BotGroupAI::DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType)
//{
//    if (!victim || !me->IsInWorld() || damage == 0)
//        return;
//    if (!me->GetMap()->IsDungeon() || me->InBattleground())
//        return;
//    Group* pGroup = me->GetGroup();
//    if (!pGroup)// || pGroup->GetMembersCount() <= 5)
//        return;
//    if (IsTankBotAI())
//    {
//        //damage = damage / 2;
//        return;
//    }
//
//    float result = float(damage);
//    switch (damageType)
//    {
//    case DamageEffectType::DIRECT_DAMAGE:
//    case DamageEffectType::SPELL_DIRECT_DAMAGE:
//        if (!victim->ToPlayer())
//        {
//            //float param = 1.2f;
//            float rate = BotUtility::DungeonBotDamageModify;// *param;
//            result *= rate;
//        }
//        break;
//    case DamageEffectType::DOT:
//        if (!victim->ToPlayer())
//        {
//            //float param = 1.1f;
//            float rate = BotUtility::DungeonBotDamageModify;// *param;
//            result *= rate;
//        }
//        break;
//        //case DamageEffectType::HEAL:
//        //	{
//        //		float rate = BotUtility::DungeonBotDamageModify;
//        //		result *= rate;
//        //	}
//        //	break;
//    default:
//        return;
//    }
//    damage = uint32(result);
//}
//
//void BotGroupAI::DamageEndure(Unit* attacker, uint32& damage, DamageEffectType damageType)
//{
//    if (!attacker || !me->IsInWorld() || damage == 0)
//        return;
//    if (!me->GetMap()->IsDungeon() || me->InBattleground())
//        return;
//    Group* pGroup = me->GetGroup();
//    if (!pGroup)// || pGroup->GetMembersCount() <= 5)
//        return;
//
//    float result = float(damage);
//    switch (damageType)
//    {
//    case DamageEffectType::DIRECT_DAMAGE:
//    case DamageEffectType::SPELL_DIRECT_DAMAGE:
//    case DamageEffectType::DOT:
//        if (!attacker->ToPlayer())
//        {
//            float param = (IsTankBotAI()) ? 1.1f : 1.0f;
//            float rate = 1.0f / (BotUtility::DungeonBotEndureModify * param);
//            result *= rate;
//        }
//        break;
//    case DamageEffectType::HEAL:
//        return;
//        //{
//        //	float rate = BotUtility::DungeonBotAnnulModify * 1.8f;
//        //	result *= rate;
//        //}
//        //break;
//    default:
//        return;
//    }
//    damage = uint32(result);
//}
//
//void BotGroupAI::UpdateAI(uint32 diff)
//{
//    m_UpdateTick -= diff;
//    if (m_UpdateTick > 0)
//        return;
//    m_UpdateTick = BOTAI_UPDATE_TICK;
//
//    if (!me->IsSettingFinish())
//        return;
//    UpdateTeleport(BOTAI_UPDATE_TICK);
//    if (!m_Teleporting.CanMovement())
//        return;
//    me->UpdateObjectVisibility(false);
//
//    if (!UpdateMasterPlayer())
//    {
//        m_Flying.CancelFly();
//        me->RemoveFromGroup(RemoveMethod::GROUP_REMOVEMETHOD_LEAVE);
//        return;
//    }
//    if (TrySettingToMaster())
//        return;
//    if (m_MasterPlayer && m_MasterPlayer->GetMap() == me->GetMap() &&
//        m_VehicleMovement3D->UpdateVehicleMovement3D())
//        return;
//    if (TryTeleportToMaster())
//        return;
//    if (m_MasterPlayer && m_MasterPlayer->duel && !m_MasterPlayer->duel->isCompleted)
//    {
//        if (!me->duel)
//        {
//            me->SetInFront(m_MasterPlayer);
//            me->SetFacingToObject(m_MasterPlayer);
//            if (m_DuelEmoteTick == 0)
//                m_DuelEmoteTick = getMSTime();
//            else if (m_DuelEmoteTick + urand(1, 2) * 500 < getMSTime())
//            {
//                m_DuelEmoteTick = getMSTime();
//                //me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_APPLAUD);
//                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_CHEER);
//            }
//            return;
//        }
//    }
//    if (!m_HasReset)
//        ResetBotAI();
//    BotUtility::UpdatePlayerBotRoll(me);
//
//    if (me->IsAlive())
//    {
//        m_CheckStoped.UpdatePosition(diff);
//        ClearMechanicAura();
//        if (!IsNotMovement())
//            ProcessHorror(diff);
//        if (NeedWaitSpecialSpell(BOTAI_UPDATE_TICK))
//            return;
//        if (ExecuteSeduceCommand())
//            return;
//        if (!me->HasUnitState(UNIT_STATE_CASTING) && !IsTankBotAI() && !IsHealerBotAI())
//        {
//            if (m_FastAid.TryDoingFastAidForMe())
//                return;
//        }
//
//        if (NonCombatProcess())
//            return;
//        if (!m_CruxMovement.HasCruxMovement() && me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (!me->IsInCombat())
//        {
//            m_MeleeFleeTick = 0;
//            m_FullDispel = 0;
//            m_MovetoHaltPos.ClearMoveto();
//            if (ProcessNormalSpell())
//                return;
//        }
//        m_Movement->SyncPosition(me->GetPosition());
//        if (TryUpMount())
//            return;
//        if (!me->HasAura(m_UseMountID) && !me->HasUnitState(UNIT_STATE_CASTING))
//            m_UsePotion.TryUsePotion();
//        if (me->IsInCombat())
//            UpEnergy();
//        Unit* pTarget = GetBotAIValidSelectedUnit();
//        if (m_ForceFlee)
//        {
//            me->AttackStop();
//            me->SetSelection(ObjectGuid::Empty);
//            ProcessFollowToMaster();
//            ProcessFullDispel();
//        }
//        else if (m_CruxMovement.HasCruxMovement())
//        {
//            m_CruxMovement.UpdateCruxMovement(m_Movement);
//            ProcessFullDispel();
//        }
//        else if (IsTankBotAI() && ProcessTank(pTarget))
//            return;         
//        else if (pTarget && pTarget->IsAlive() && !IsInvincible(pTarget))
//        {
//            if (ProcessFullDispel())
//                return;
//            float distance = me->GetDistance(pTarget->GetPosition());
//            if (m_MovetoHaltPos.ProcessMovetoPosition(m_Movement))
//            {
//                if (IsHealerBotAI() && me->getLevel() >= 10)
//                    ProcessHealth(false);
//                else
//                    ProcessHalt(pTarget);
//            }
//            else if (distance < BOTAI_SEARCH_RANGE)
//            {
//                if (IsHealerBotAI() && me->getLevel() >= 10)
//                    ProcessHealth(true);
//                else
//                    ProcessCombat(pTarget);
//            }
//            else if (distance > BOTAI_SEARCH_RANGE * 4.0f || me->GetMap() != pTarget->GetMap())
//            {
//                me->AttackStop();
//                //me->StopMoving();
//                me->SetSelection(ObjectGuid::Empty);
//            }
//            else
//            {
//                m_Movement->MovementToTarget();
//            }
//        }
//        else if (pTarget = GetCombatTarget())
//        {
//            me->AttackStop();
//            me->SetSelection(pTarget->GetGUID());
//            ProcessFullDispel();
//        }
//        else
//        {
//            me->SetSelection(ObjectGuid::Empty);
//            ClearTankTarget();
//            if (m_CruxHealTarget != ObjectGuid::Empty)
//            {
//                if (IsHealerBotAI())
//                    ProcessHealth(true);
//                else
//                    m_CruxHealTarget = ObjectGuid::Empty;
//            }
//            else
//            {
//                ProcessFollowToMaster();
//                ProcessFullDispel();
//            }
//        }
//    }
//    else
//    {
//        m_MeleeFleeTick = 0;
//        m_FullDispel = 0;
//        m_CruxHealTarget = ObjectGuid::Empty;
//        m_MovetoUseGO.ClearUseGO();
//        m_MovetoHaltPos.ClearMoveto();
//        if (m_SeduceTarget != ObjectGuid::Empty)
//        {
//            m_SeduceTarget = ObjectGuid::Empty;
//            if (Group* pGroup = me->GetGroup())
//                pGroup->ClearAllGroupForceFleeState();
//        }
//        m_WishStore.ClearStores();
//        ClearCruxMovement();
//        if (!me->IsInCombat())
//            ClearTankTarget();
//        if (Group* pGroup = me->GetGroup())
//        {
//            if (!BotUtility::BotCanForceRevive)
//            {
//                if (!pGroup->AllGroupNotCombat())
//                    return;
//            }
//        }
//        if (me->GetDistance(m_MasterPlayer->GetPosition()) >= NEEDFLEE_CHECKRANGE)
//        {
//            m_Teleporting.SetTeleport(m_MasterPlayer, 2.0f);
//        }
//        else
//        {
//            //m_Teleporting.ClearTeleport();
//            me->SetSelection(ObjectGuid::Empty);
//            m_Revive.UpdateRevive(BOTAI_UPDATE_TICK);
//        }
//    }
//}
//
//void BotGroupAI::ResetBotAI()
//{
//    PlayerBotSetting::ClearUnknowMount(me);
//    m_Movement->ClearMovement();
//    m_Flying.RandomFlyMount();
//    m_FastAid.CheckPlayerFastAid();
//
//    if (m_UseMountID != 0)
//    {
//        if (!me->HasSpell(m_UseMountID))
//            me->LearnSpell(m_UseMountID, false);
//    }
//    m_IsMeleeBot = IsMeleeBotAI();
//    m_IsRangeBot = IsRangeBotAI();
//    m_IsHealerBot = IsHealerBotAI();
//    m_HasReset = true;
//
//    m_CruxHealTarget = ObjectGuid::Empty;
//    m_SeduceTarget = ObjectGuid::Empty;
//    m_Flee.Clear();
//    m_MeleeFleeTick = 0;
//    if (me->HasAura(43625))
//        me->RemoveAurasDueToSpell(43625);
//}
//
//void BotGroupAI::StartFullDispel()
//{
//    if (IsTankBotAI())
//        return;
//    m_FullDispel = getMSTime() + 2000;
//}
//
//void BotGroupAI::ClearCruxMovement()
//{
//    if (m_CruxMovement.HasCruxMovement())
//    {
//        m_CruxMovement.ClearMovement();
//        m_Movement->ClearMovement();
//    }
//}
//
//void BotGroupAI::AddTankTarget(Creature* pCreature)
//{
//    if (!pCreature || !pCreature->IsAlive() || me->GetMap() != pCreature->GetMap() || !me->IsValidAttackTarget(pCreature))
//        return;
//    if (!IsTankBotAI())
//        return;
//    m_TankTargets.AddTarget(pCreature);
//}
//
//bool BotGroupAI::IsNotSelect(Unit* pTarget)
//{
//    if (!pTarget || !pTarget->IsAlive())
//        return true;
//    if (pTarget->HasAura(27827)) // (27827 ???? ?????)
//        return true;
//    if (pTarget->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
//        return true;
//    if (pTarget->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
//        return true;
//    if (pTarget->ToCreature() && pTarget->ToCreature()->IsInEvadeMode())
//        return true;
//    return false;
//}
//
//bool BotGroupAI::IsIDLEBot()
//{
//    if (me->HasUnitState(UNIT_STATE_CASTING))
//        return false;
//    if (me->IsInCombat() || !me->IsAlive())
//        return false;
//    if (!m_Teleporting.CanMovement())
//        return false;
//    if (m_UseFood.HasFoodState())
//        return false;
//    if (m_FindLoot.HasLoot())
//        return false;
//
//    return true;
//}
//
//bool BotGroupAI::CanExecuteSeduce()
//{
//    if (m_SeduceTarget != ObjectGuid::Empty)
//        return false;
//    if (me->HasUnitState(UNIT_STATE_CASTING))
//        return false;
//    if (!me->IsAlive() || me->GetTarget() != ObjectGuid::Empty)
//        return false;
//    if (!m_Teleporting.CanMovement() || me->GetHealthPct() < 75)
//        return false;
//    if (m_UseFood.HasFoodState())
//        return false;
//    if (m_FindLoot.HasLoot())
//        return false;
//    return true;
//}
//
//void BotGroupAI::OnLevelUp(uint32 talentType)
//{
//    m_HasReset = false;
//    m_WishStore.ClearWishs();
//}
//
//void BotGroupAI::OnLootedItem(uint32 entry)
//{
//    m_LootedItems.AddLootedItem(entry);
//}
//
//bool BotGroupAI::TryUpMount()
//{
//    if (me->IsInCombat() || me->GetSelectedUnit() || me->HasAura(m_UseMountID) || me->getLevel() < 20)
//        return false;
//    if (!m_MasterPlayer || !m_MasterPlayer->IsMounted())
//        return false;
//    if (!me->GetMap()->IsOutdoors(me->GetPhaseShift(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
//        return false;
//    if (me->IsMounted())
//        return false;
//    if (me->HasUnitState(UNIT_STATE_CASTING))
//        return false;
//    m_Movement->ClearMovement();
//    return (TryCastSpell(m_UseMountID, me) == SPELL_CAST_OK);
//}
//
//void BotGroupAI::Dismount()
//{
//    if (!me->HasAura(m_UseMountID))
//        return;
//    me->RemoveOwnedAura(m_UseMountID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
//}
//
//void BotGroupAI::SetVehicle3DNextMoveGap(float gap)
//{
//    m_VehicleMovement3D->SetStopMoveGap(gap);
//}
//
//void BotGroupAI::SetVehicle3DMoveTarget(Unit* pTarget, float offset)
//{
//    m_VehicleMovement3D->AddMovement(pTarget, offset);
//}
//
//void BotGroupAI::ProcessHorror(uint32 diff)
//{
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_HORROR) ||
//        HasAuraMechanic(me, Mechanics::MECHANIC_DISORIENTED) ||
//        HasAuraMechanic(me, Mechanics::MECHANIC_FEAR))
//    {
//        if (!pHorrorState)
//        {
//            pHorrorState = new BotAIHorrorState(me);
//            me->GetMotionMaster()->Clear();
//            m_Movement->ClearMovement();
//            me->UpdatePosition(me->GetPosition(), true);
//            m_Movement->SyncPosition(me->GetPosition(), true);
//            me->SetSelection(ObjectGuid::Empty);
//        }
//        pHorrorState->UpdateHorror(diff, m_Movement);
//    }
//    else if (pHorrorState)
//    {
//        delete pHorrorState;
//        pHorrorState = NULL;
//        m_Movement->ClearMovement();
//    }
//}
//
//bool BotGroupAI::TargetIsNotDiminishingByType(Unit* pTarget, DiminishingGroup diType)
//{
//    if (!pTarget)
//        return false;
//    if (diType < 1 || diType > 20)
//        return false;
//    DiminishingLevels diLevel = pTarget->GetDiminishing(diType);
//    return diLevel < 1;
//}
//
//bool BotGroupAI::TargetIsNotDiminishingByType2(Unit* pTarget, DiminishingGroup diType)
//{
//    if (!pTarget)
//        return false;
//    if (diType < 1 || diType > 20)
//        return false;
//    DiminishingLevels diLevel = pTarget->GetDiminishing(diType);
//    return diLevel < 2;
//}
//
//bool BotGroupAI::HasAuraMechanic(Unit* pTarget, Mechanics mask)
//{
//    if (!pTarget)
//        return false;
//    return (pTarget->HasAuraWithMechanic(1 << mask));
//}
//
//bool BotGroupAI::IsNotMovement()
//{
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_ROOT))
//    {
//        me->StopMoving();
//        return true;
//    }
//    if (IsNotSelect(me))
//    {
//        me->StopMoving();
//        return true;
//    }
//    //if (me->IsStopped())
//    return false;
//    //return true;
//}
//
//bool BotGroupAI::IsInvincible(Unit* pTarget)
//{
//    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH))
//    {
//        return true;
//    }
//    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_IMMUNE_SHIELD))
//    {
//        return true;
//    }
//    return false;
//}
//
//bool BotGroupAI::UpdateMasterPlayer()
//{
//    Group* pGroup = me->GetGroup();
//    if (!pGroup)
//    {
//        m_Flying.CancelFly();
//        sLFGMgr->LeaveLfg(me->GetGUID());
//        PlayerBotMgr::SwitchPlayerBotAI(me, PlayerBotAIType::PBAIT_FIELD, true);
//        return false;
//    }
//    if (!pGroup->GroupExistRealPlayer())
//    {
//        m_Flying.CancelFly();
//        sLFGMgr->LeaveLfg(me->GetGUID());
//        PlayerBotMgr::SwitchPlayerBotAI(me, PlayerBotAIType::PBAIT_FIELD, true);
//        return false;
//    }
//
//    m_GroupLeader.ProcessGroupLeader();
//    if (m_MasterPlayer == NULL)
//    {
//        Player* player = ObjectAccessor::FindConnectedPlayer(pGroup->GetLeaderGUID());
//        if (player == NULL || player->IsPlayerBot())
//        {
//            m_Flying.CancelFly();
//            sLFGMgr->LeaveLfg(me->GetGUID());
//            return false;
//        }
//        m_MasterPlayer = player;
//    }
//    else if (Player* player = ObjectAccessor::FindConnectedPlayer(pGroup->GetLeaderGUID()))
//    {
//        m_MasterPlayer = player;
//        if (player == NULL || player->IsPlayerBot())
//        {
//            m_MasterPlayer = NULL;
//            m_Flying.CancelFly();
//            sLFGMgr->LeaveLfg(me->GetGUID());
//            return false;
//        }
//    }
//    else
//    {
//        m_MasterPlayer = NULL;
//        m_Flying.CancelFly();
//        sLFGMgr->LeaveLfg(me->GetGUID());
//        return false;
//    }
//    return true;
//}
//
//bool BotGroupAI::TrySettingToMaster()
//{
//    static int32 gapLV = 2;
//    if (!BotUtility::BotCanSettingToMaster)
//        return false;
//    if (!me->IsAlive() || me->IsInCombat() || m_MasterPlayer == NULL)
//        return false;
//    if (me->HasUnitState(UNIT_STATE_CASTING))
//        return false;
//    if (!me->IsSettingFinish())
//        return true;
//    PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(me->GetSession());
//    if (!pSession)
//        return false;
//    if (pSession->HasSchedules())
//        return true;
//    if (pSession->IsAccountBotSession())
//        return false;
//
//    int32 masterLV = m_MasterPlayer->getLevel();
//    int32 minLV = (masterLV <= gapLV) ? 1 : masterLV - gapLV;
//    int32 maxLV = ((masterLV + gapLV) >= 110) ? 110 : masterLV + gapLV;
//    if (masterLV >= 110)
//        minLV = 110;
//    maxLV = PlayerBotSetting::CheckMaxLevel(maxLV);
//    if (maxLV < minLV)
//        maxLV = minLV;
//    int32 meLV = me->getLevel();
//    if (meLV >= minLV && meLV <= maxLV)
//        return false;
//    if (masterLV == sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
//    {
//        minLV = masterLV;
//        maxLV = masterLV;
//    }
//
//    BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting);
//    schedule2.parameter1 = minLV;
//    schedule2.parameter2 = maxLV;
//    schedule2.parameter3 = PlayerBotSetting::FindPlayerTalentType(me) + 1;
//    pSession->PushScheduleToQueue(schedule2);
//    m_HasReset = false;
//    return true;
//}
//
//bool BotGroupAI::TryTeleportToMaster()
//{
//    if (m_MasterPlayer == NULL)
//        return false;
//    if (!m_MasterPlayer->IsInWorld())
//        return true;
//    if (!m_MasterPlayer->m_taxi.empty())
//        return true;
//    if (m_StopFollow)
//        return true;
//    if (m_MasterPlayer->IsFlying() && !m_Flying.HasFlying())
//        return false;
//    if (m_MasterPlayer->GetMap() != me->GetMap())
//    {
//        if (!m_MasterPlayer->InBattleground())
//            m_Teleporting.SetTeleport(m_MasterPlayer, 0);
//        me->SetSelection(ObjectGuid::Empty);
//        m_Movement->ClearMovement();
//        m_Flee.Clear();
//        return true;
//    }
//    else if (me->GetDistance(m_MasterPlayer->GetPosition()) > BOTAI_SEARCH_RANGE * 5)
//    {
//        m_Teleporting.SetTeleport(m_MasterPlayer, 0);
//        me->SetSelection(ObjectGuid::Empty);
//        m_Movement->ClearMovement();
//        m_Flee.Clear();
//        return true;
//    }
//
//    return false;
//}
//
//Unit* BotGroupAI::GetCombatTarget(float range)
//{
//    Group* pGroup = me->GetGroup();
//    if (!pGroup)
//        return NULL;
//    if (!IsTankBotAI())
//    {
//        Unit* pTankTarget = pGroup->GetGroupTankTarget();
//        if (pTankTarget && pTankTarget->IsAlive() && me->IsValidAttackTarget(pTankTarget) &&
//            pTankTarget->IsVisible() && !m_FliterCreatures.IsFliterCreature(pTankTarget->ToCreature()))
//            return pTankTarget;
//    }
//    NearUnitVec validTarget;
//    NearPlayerList playersNearby;
//    me->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//        {
//            if (!pVisionPlayer->IsPvP())
//                continue;
//            if (TargetIsStealth(pVisionPlayer))
//                continue;
//            if (TargetIsControl(pVisionPlayer))
//                continue;
//            Player* pTarget = pVisionPlayer->GetSelectedPlayer();
//            if (pTarget && pGroup->IsMember(pTarget->GetGUID()))
//                validTarget.push_back(pVisionPlayer);
//        }
//    }
//    NearCreatureVec creatures;
//    SearchCreatureListFromRange(me, creatures, range, false);
//    for (Creature* pCreature : creatures)
//    {
//        if (!pCreature->IsInCombat())
//            continue;
//        if (!pCreature->IsInPhase(me))
//            continue;
//        if (TargetIsControl(pCreature))
//            continue;
//        ObjectGuid& guid = pCreature->GetTarget();
//        if (guid == ObjectGuid::Empty)
//            continue;
//        if (!pGroup->IsMember(guid))
//            continue;
//        validTarget.push_back(pCreature);
//    }
//    if (validTarget.empty())
//        return NULL;
//    return validTarget[urand(0, validTarget.size() - 1)];
//}
//
//void BotGroupAI::ProcessFollowToMaster()
//{
//    if (m_MasterPlayer == NULL)
//        return;
//    if (m_StopFollow || m_MasterPlayer->IsFlying())
//    {
//        m_Movement->ClearMovement();
//        return;
//    }
//    if (m_MasterPlayer->duel && !m_MasterPlayer->duel->isCompleted)
//    {
//        m_Movement->ClearMovement();
//        return;
//    }
//    Position& targetPos = BotUtility::GetPositionFromGroup(m_MasterPlayer, me->GetGUID(), me->GetGroup());
//    m_Movement->MovementTo(targetPos.GetPositionX(), targetPos.GetPositionY(), targetPos.GetPositionZ(), 0);
//    //float distance = me->GetDistance(m_MasterPlayer->GetPosition());
//    //if (distance <= NEEDFLEE_CHECKRANGE && distance > 0.1f)
//    //{
//    //	me->GetMotionMaster()->Clear();
//    //	me->GetMotionMaster()->MoveFollow(m_MasterPlayer, 1.0f, m_MasterPlayer->GetOrientation());
//    //	return;
//    //}
//
//    //if (me->IsWithinLOSInMap(m_MasterPlayer))
//    //{
//    //	me->GetMotionMaster()->Clear();
//    //	me->GetMotionMaster()->MoveFollow(m_MasterPlayer, 1.0f, m_MasterPlayer->GetOrientation());
//    //}
//    //else
//    //	m_Movement->MovementTo(m_MasterPlayer->GetPositionX(), m_MasterPlayer->GetPositionY(), m_MasterPlayer->GetPositionZ(), 1);
//}
//
//bool BotGroupAI::NonCombatProcess()
//{
//    m_DelayGiveXP.ProcessGiveXP(m_MasterPlayer->getLevel());
//    {
//        std::lock_guard<std::mutex> lock(m_ItemLock);
//        if (m_CheckDuel.CheckDuel())
//            sPlayerBotMgr->SwitchPlayerBotAI(me, PlayerBotAIType::PBAIT_DUEL, true);
//        m_Guild.UpdateGuildProcess();
//        if (m_AITrade.ProcessTrade())
//            return true;
//        m_Flying.UpdateFly(m_MasterPlayer, m_UseMountID, m_Movement);
//        if (m_Flying.HasFlying())
//            return true;
//        m_LootedItems.LookupLootedItems(BOTAI_UPDATE_TICK);
//        if (m_UseFood.UpdateBotFood(BOTAI_UPDATE_TICK, m_UseMountID))
//            return true;
//        if (m_FindLoot.DoFindLoot(BOTAI_UPDATE_TICK, m_Movement, m_UseMountID))
//            return true;
//        if (m_MovetoUseGO.ProcessMovetoUseGO(m_Movement))
//            return true;
//        if (ProcessRevivePlayer())
//            return true;
//        m_WishStore.UpdateWishStore();
//        BotUtility::TryTeleportPlayerPet(me);
//    }
//    return false;
//}
//
//bool BotGroupAI::ProcessRevivePlayer()
//{
//    uint32 reviveSpellID = GetReviveSpell();
//    if (reviveSpellID == 0)
//        return false;
//    if (me->HasUnitState(UNIT_STATE_CASTING))
//        return false;
//    ObjectGuid& guid = m_RevivePlayer.SearchNeedRevive(BOTAI_UPDATE_TICK);
//    if (guid.IsEmpty())
//        return false;
//    Player* pRevive = ObjectAccessor::FindPlayer(guid);
//    if (!pRevive || pRevive->IsAlive())
//        return false;
//    if (!me->IsWithinLOSInMap(pRevive) || me->GetDistance(pRevive->GetPosition()) > 15)
//    {
//        m_Movement->MovementTo(pRevive->GetPositionX(), pRevive->GetPositionY(), pRevive->GetPositionZ());
//        return true;
//    }
//    m_Movement->ClearMovement();
//    if (TryCastSpell(reviveSpellID, pRevive) == SpellCastResult::SPELL_CAST_OK)
//        return true;
//    return false;
//}
//
//bool BotGroupAI::DoFaceToTarget(Unit* pTarget)
//{
//    float relative = me->GetRelativeAngle(pTarget->GetPositionX(), pTarget->GetPositionY());
//    if (relative >= M_PI_2 && !IsNotMovement())// (fabsf(selfAngle) > M_PI_4)
//    {
//        //me->SetInFront(pTarget);
//        //me->SetFacingToObject(pTarget);
//        Movement::MoveSplineInit init(me);
//        init.MoveTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZMinusOffset());
//        init.SetFacing(pTarget);
//        init.SetOrientationFixed(true);
//        init.Launch();
//        return true;
//    }
//    return false;
//}
//
//SpellCastResult BotGroupAI::TryCastSpell(uint32 spellID, Unit* pTarget, bool force, bool dismount)
//{
//    if (!spellID || !me->HasSpell(spellID))
//    {
//        if (spellID)
//        {
//            me->LearnSpell(spellID, false);
//            m_HasReset = false;
//        }
//           
//        //printf("BotGroupAI::TryCastSpell %d !hasspell \n", spellID);
//        return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
//    }
//    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_NONE);
//    if (!spellInfo || spellInfo->IsPassive() || m_Flying.HasFlying())
//        return SpellCastResult::SPELL_FAILED_UNKNOWN;
//    if (!m_WishStore.CanWishStore(spellID, pTarget))
//        return SpellCastResult::SPELL_FAILED_UNKNOWN;
//    Spell* spell = new Spell(me, spellInfo,
//        force ? TriggerCastFlags(TriggerCastFlags::TRIGGERED_IGNORE_POWER_AND_REAGENT_COST | TriggerCastFlags::TRIGGERED_IGNORE_CAST_ITEM) : TriggerCastFlags::TRIGGERED_NONE, ObjectGuid::Empty);
//    spell->m_CastItem = NULL;
//    SpellCastTargets targets;
//    targets.SetUnitTarget(pTarget);
//    if (dismount)
//        Dismount();
//    SpellCastResult castResult;// = spell->prepare(&targets, NULL);
//    if (castResult != SpellCastResult::SPELL_CAST_OK)
//    {
//        if (castResult == SpellCastResult::SPELL_FAILED_NOT_MOUNTED)
//            PlayerBotSetting::ClearUnknowMount(me);
//        return castResult;
//    }
//    m_WishStore.TryWishStore(spellID, pTarget);
//    return SpellCastResult::SPELL_CAST_OK;
//}
//
//SpellCastResult BotGroupAI::TryCastSpellByLifePCTInterrupt(uint32 spellID, Unit* pTarget, uint32 interruptByLife)
//{
//    if (!spellID || !me->HasSpell(spellID))
//    {
//        if (spellID)
//        {
//            me->LearnSpell(spellID, false);
//            m_HasReset = false;
//        }
//        return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
//    }
//    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_NONE);
//    if (!spellInfo || spellInfo->IsPassive() || m_Flying.HasFlying())
//        return SpellCastResult::SPELL_FAILED_UNKNOWN;
//    if (interruptByLife < 1 || interruptByLife > 100)
//        return SpellCastResult::SPELL_FAILED_UNKNOWN;
//    if (!m_WishStore.CanWishStore(spellID, pTarget))
//        return SpellCastResult::SPELL_FAILED_UNKNOWN;
//    Spell* spell = new Spell(me, spellInfo, TriggerCastFlags::TRIGGERED_NONE, ObjectGuid::Empty);
//    spell->m_CastItem = NULL;
//    SpellCastTargets targets;
//    targets.SetUnitTarget(pTarget);
//    Dismount();
//    SpellCastResult castResult;// = spell->prepare(&targets, NULL);
//    if (castResult != SpellCastResult::SPELL_CAST_OK)
//    {
//        if (castResult == SpellCastResult::SPELL_FAILED_NOT_MOUNTED)
//            PlayerBotSetting::ClearUnknowMount(me);
//        return castResult;
//    }
//    m_WishStore.TryWishStore(spellID, pTarget);
//    if (pTarget && pTarget->GetGUID() != m_CruxHealTarget)
//        spell->SetInterruptConditionByLifePCT(pTarget->GetGUID(), interruptByLife);
//    return SpellCastResult::SPELL_CAST_OK;
//}
//
//SpellCastResult BotGroupAI::TryCastPullSpell(uint32 spellID, Unit* pTarget)
//{
//    if (!spellID || !me->HasSpell(spellID))
//        return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
//    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_NONE);
//    if (!spellInfo || spellInfo->IsPassive() || m_Flying.HasFlying())
//        return SpellCastResult::SPELL_FAILED_UNKNOWN;
//    Spell* spell = new Spell(me, spellInfo,
//        TriggerCastFlags(TriggerCastFlags::TRIGGERED_IGNORE_POWER_AND_REAGENT_COST | TriggerCastFlags::TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD), ObjectGuid::Empty);
//    spell->m_CastItem = NULL;
//    SpellCastTargets targets;
//    targets.SetUnitTarget(pTarget);
//    //spell->InitExplicitTargets(targets);
//    //SpellCastResult castResult = spell->CheckCast(true);
//    //if (castResult != SpellCastResult::SPELL_CAST_OK)
//    //{
//    //	spell->finish(false);
//    //	delete spell;
//    //	return castResult;
//    //}
//    Dismount();
//    SpellCastResult castResult;// = spell->prepare(&targets, NULL);
//    if (castResult != SpellCastResult::SPELL_CAST_OK)
//    {
//        //spell->finish(false);
//        //delete spell;
//        return castResult;
//    }
//    return SpellCastResult::SPELL_CAST_OK;
//}
//
//SpellCastResult BotGroupAI::PetTryCastSpell(uint32 spellID, Unit* pTarget, bool force)
//{
//    Pet* pPet = me->GetPet();
//    if (!pPet || !pPet->IsAlive())
//        return SpellCastResult::SPELL_FAILED_UNKNOWN;
//    if (!spellID || !pPet->HasSpell(spellID))
//        return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
//    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_NONE);
//    if (!spellInfo || spellInfo->IsPassive())
//        return SpellCastResult::SPELL_FAILED_UNKNOWN;
//    Spell* spell = new Spell(pPet, spellInfo, TRIGGERED_NONE);
//    pTarget = pTarget ? pTarget : pPet;
//    SpellCastResult castResult = spell->CheckPetCast(pTarget);
//    if (castResult == SPELL_FAILED_UNIT_NOT_INFRONT && !pPet->isPossessed() && !pPet->IsVehicle())
//    {
//        if (pTarget && pTarget != pPet)
//        {
//            pPet->SetInFront(pTarget);
//            if (Player* player = pTarget->ToPlayer())
//                pPet->SendUpdateToPlayer(player);
//        }
//        else if (Unit* unit_target2 = spell->m_targets.GetUnitTarget())
//        {
//            pPet->SetInFront(unit_target2);
//            if (Player* player = unit_target2->ToPlayer())
//                pPet->SendUpdateToPlayer(player);
//        }
//
//        if (Unit* powner = pPet->GetCharmerOrOwner())
//            if (Player* player = powner->ToPlayer())
//                pPet->SendUpdateToPlayer(player);
//
//        castResult = SPELL_CAST_OK;
//    }
//    if (castResult == SPELL_CAST_OK)
//    {
//        pTarget = spell->m_targets.GetUnitTarget();
//
//        //10% chance to play special pet attack talk, else growl
//        //actually this only seems to happen on special spells, fire shield for imp, torment for voidwalker, but it's stupid to check every spell
//        if (pPet->IsPet() && (((Pet*)pPet)->getPetType() == SUMMON_PET) && (pPet != pTarget) && (urand(0, 100) < 10))
//            pPet->SendPetTalk((uint32)PET_TALK_SPECIAL_SPELL);
//        else
//        {
//            pPet->SendPetAIReaction(me->GetPetGUID());
//        }
//
//        if (pTarget && !pPet->isPossessed() && !pPet->IsVehicle())
//        {
//            // This is true if pet has no target or has target but targets differs.
//            if (pPet->GetVictim() != pTarget)
//            {
//                if (pPet->GetVictim())
//                    pPet->AttackStop();
//                pPet->GetMotionMaster()->Clear();
//                if (pPet->ToCreature()->IsAIEnabled)
//                    pPet->ToCreature()->AI()->AttackStart(pTarget);
//            }
//        }
//       // spell->prepare(&(spell->m_targets));
//       // return;
//    }
//    else
//    {
//        //if (pPet->isPossessed() || pPet->IsVehicle()) /// @todo: confirm this check
//        //	Spell::SendCastResult(me, spellInfo, 0, castResult);
//        //else
//        spell->SendPetCastResult(castResult);
//
//        if (!pPet->GetSpellHistory()->HasCooldown(spellID))
//            pPet->GetSpellHistory()->ResetCooldown(spellID, true);
//
//        spell->finish(false);
//        delete spell;
//
//        // reset specific flags in case of spell fail. AI will reset other flags
//        if (pPet->GetCharmInfo())
//            pPet->GetCharmInfo()->SetIsCommandAttack(false);
//    }
//
//    return castResult;
//}
//
//void BotGroupAI::SettingPetAutoCastSpell(uint32 spellID, bool autoCast)
//{
//    Pet* pPet = me->GetPet();
//    if (!pPet || !pPet->IsAlive())
//        return;
//    if (!spellID || !pPet->HasSpell(spellID))
//        return;
//    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_NONE);
//    if (!spellInfo || spellInfo->IsPassive() || !spellInfo->IsAutocastable())
//        return;
//    CharmInfo* charmInfo = pPet->GetCharmInfo();
//    if (!charmInfo)
//        return;
//    if (pPet->IsPet())
//        pPet->ToggleAutocast(spellInfo, autoCast);
//    else
//        pPet->GetCharmInfo()->ToggleCreatureAutocast(spellInfo, autoCast);
//
//    charmInfo->SetSpellAutocast(spellInfo, autoCast);
//}
//
//bool BotGroupAI::NeedWaitSpecialSpell(uint32 diff)
//{
//    if (IsNotSelect(me))
//    {
//        me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_CHARM))
//    {
//        me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_DISORIENTED))
//    {
//        me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_FEAR))
//    {
//        //me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_SLEEP))
//    {
//        me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_STUN))
//    {
//        me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_FREEZE))
//    {
//        me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_KNOCKOUT))
//    {
//        me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_POLYMORPH))
//    {
//        me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_BANISH))
//    {
//        me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_HORROR))
//    {
//        //me->StopMoving();
//        return true;
//    }
//    if (HasAuraMechanic(me, Mechanics::MECHANIC_SAPPED))
//    {
//        me->StopMoving();
//        return true;
//    }
//
//    return m_WaitAuras.HasNeedWaitAura();
//}
//
//bool BotGroupAI::NeedFlee()
//{
//    if (m_MeleeFleeTick > 0)
//    {
//        if (m_MeleeFleeTick > getMSTime())
//            return true;
//        else
//        {
//            m_MeleeFleeTick = 0;
//            if (me->GetHealthPct() < 25)
//            {
//                m_MeleeFleeTick = getMSTime() + 2500;
//                return true;
//            }
//            else
//            {
//                m_Flee.Clear();
//                return false;
//            }
//        }
//    }
//    if (m_Flee.Fleeing())
//    {
//        if (me->GetHealthPct() > 25)
//        {
//            m_Flee.Clear();
//            return false;
//        }
//        return true;
//    }
//    if (IsMeleeBotAI())
//    {
//        if (me->GetHealthPct() < 25)
//        {
//            m_MeleeFleeTick = getMSTime() + 2500;
//            return true;
//        }
//    }
//    return false;
//}
//
//void BotGroupAI::FleeMovement()
//{
//    if (/*me->IsStopped() && */!IsNotMovement())
//    {
//        NearUnitVec& enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
//        Unit* selectEnemy = NULL;
//        if (enemys.empty())
//        {
//            selectEnemy = me->GetSelectedUnit();
//            if (!selectEnemy || me->GetDistance(selectEnemy->GetPosition()) > BOTAI_FLEE_JUDGE + 5.0f)
//            {
//                m_Flee.Clear();
//                return;
//            }
//        }
//        if (!selectEnemy && !enemys.empty())
//        {
//            float nearDist = 999999;
//            for (Unit* pEnemy : enemys)
//            {
//                float dist = me->GetDistance(pEnemy->GetPosition());
//                if (dist < nearDist)
//                {
//                    nearDist = dist;
//                    selectEnemy = pEnemy;
//                }
//            }
//            if (!selectEnemy)
//            {
//                m_Flee.Clear();
//                return;
//            }
//        }
//        m_Flee.UpdateFleeMovementByPVE(m_MasterPlayer, selectEnemy, m_Movement);
//    }
//    else
//        m_Flee.Clear();
//}
//
//void BotGroupAI::ProcessFlee()
//{
//    FleeMovement();
//}
//
//bool BotGroupAI::ExecuteSeduceCommand()
//{
//    if (m_MasterPlayer)
//    {
//        if (!m_MasterPlayer->IsAlive() && me->IsInWorld() && IsHealerBotAI())
//            ProcessRevivePlayer();           
//    }
//    if (m_SeduceTarget == ObjectGuid::Empty || !m_MasterPlayer)
//        return false;
//    Group* pGroup = me->GetGroup();
//    Unit* pTarget = ObjectAccessor::GetCreature(*me, m_SeduceTarget);
//    if (!pTarget || !pTarget->IsAlive() || m_MasterPlayer->IsInCombat() ||
//        !pTarget->ToCreature() || pTarget->ToCreature()->IsInEvadeMode() ||
//        !me->IsInWorld() || me->GetMap() != pTarget->GetMap() ||
//        pTarget->ToPlayer() || pTarget->IsTotem())
//    {
//        m_SeduceTarget = ObjectGuid::Empty;
//        if (pGroup)
//            pGroup->ClearAllGroupForceFleeState();
//        return false;
//    }
//    if (m_MasterPlayer)
//    {
//        NearCreatureVec nearCreatures;
//        SearchCreatureListFromRange(m_MasterPlayer, nearCreatures, BOTAI_RANGESPELL_DISTANCE, false);
//        if (!nearCreatures.empty())
//        {
//            for (Creature* pCreature : nearCreatures)
//            {
//                if (m_MasterPlayer->IsWithinLOSInMap(pCreature))
//                {
//                    m_SeduceTarget = ObjectGuid::Empty;
//                    if (pGroup)
//                        pGroup->ClearAllGroupForceFleeState();
//                    return false;
//                }
//            }
//        }
//        if (m_MasterPlayer->IsWithinLOSInMap(pTarget) && m_MasterPlayer->GetDistance(pTarget) <= BOTAI_RANGESPELL_DISTANCE &&
//            pTarget->IsInCombat() && pTarget->GetTarget() != ObjectGuid::Empty)
//        {
//            m_SeduceTarget = ObjectGuid::Empty;
//            if (pGroup)
//                pGroup->ClearAllGroupForceFleeState();
//            return false;
//        }
//    }
//
//    NearCreatureVec nearCreatures;
//    SearchCreatureListFromRange(me, nearCreatures, BOTAI_RANGESPELL_DISTANCE, false);
//    if (!nearCreatures.empty())
//    {
//        float minDist = 9999;
//        Creature* nearCreature = NULL;
//        for (Creature* pCreature : nearCreatures)
//        {
//            if (pCreature->IsInEvadeMode() || pCreature->getLevel() <= 1)
//                continue;
//            if (!pCreature->IsInCombat() || pCreature->GetTarget() == ObjectGuid::Empty || pCreature->IsTotem())
//                continue;
//            float dist = me->GetDistance(pCreature->GetPosition());
//            if (dist < minDist || nearCreature == NULL)
//            {
//                minDist = dist;
//                nearCreature = pCreature;
//            }
//        }
//        if (nearCreature && nearCreature->GetGUID() != m_SeduceTarget)
//        {
//            m_SeduceTarget = nearCreature->GetGUID();
//            me->SetSelection(m_SeduceTarget);
//            return true;
//        }
//    }
//
//    if (Creature* pCreature = pTarget->ToCreature())
//    {
//        if (pCreature->IsPet() || !me->IsValidAttackTarget(pTarget) || pCreature->IsInEvadeMode())
//        {
//            m_SeduceTarget = ObjectGuid::Empty;
//            if (pGroup)
//                pGroup->ClearAllGroupForceFleeState();
//            return false;
//        }
//    }
//    if (/*me->IsWithinLOSInMap(pTarget) && */me->GetDistance(pTarget) <= BOTAI_RANGESPELL_DISTANCE &&
//        pTarget->IsInCombat() && pTarget->GetTarget() != ObjectGuid::Empty)
//    {
//        if (m_IsRangeBot)
//        {
//            Unit* pVictim = me->GetVictim();
//            if (!pVictim || pVictim != pTarget)
//                me->Attack(pTarget, false);
//            DoRangedAttackIfReady();
//        }
//        else
//        {
//            Unit* pVictim = me->GetVictim();
//            if (!pVictim || pVictim != pTarget)
//                me->Attack(pTarget, true);
//        }
//        ProcessFollowToMaster();
//    }
//    else if (!IsNotMovement() && me->IsWithinLOSInMap(pTarget))
//        m_Movement->MovementTo(pTarget->GetGUID(), 2.0f);
//    if (me->IsWithinLOSInMap(pTarget) && me->GetDistance(pTarget) <= BOTAI_RANGESPELL_DISTANCE)
//        ProcessSeduceSpell(pTarget);
//    return true;
//}
//
//void BotGroupAI::ProcessPrepareHealth()
//{
//    if (!me->IsInCombat())
//    {
//        ProcessCombat(me->GetSelectedUnit());
//        return;
//    }
//    std::vector<Unit*> preparaTargets;
//    NearUnitVec& friends = SearchFriend();
//    for (Unit* pUnit : friends)
//    {
//        if (!pUnit->IsInCombat())
//            continue;
//        if (BotGroupAI* pGroupAI = dynamic_cast<BotGroupAI*>(pUnit->GetAI()))
//        {
//            if (pGroupAI->IsTankBotAI())
//                preparaTargets.push_back(pUnit);
//        }
//        else
//            continue;
//    }
//    if (preparaTargets.empty())
//    {
//        ProcessCombat(me->GetSelectedUnit());
//        return;
//    }
//    Unit* prepareUnit = preparaTargets[urand(0, preparaTargets.size() - 1)];
//    if (me->IsWithinLOSInMap(prepareUnit))
//    {
//        if (me->GetDistance(prepareUnit) > BOTAI_RANGESPELL_DISTANCE - 3)
//        {
//            if (!IsNotMovement())
//                m_Movement->MovementTo(prepareUnit->GetGUID());
//            return;
//        }
//        else
//        {
//            m_Movement->ClearMovement();
//            me->SetInFront(prepareUnit);
//            //me->SetFacingToObject(healthPlayer);
//            ProcessPrepareHealthSpell(prepareUnit);
//            return;
//        }
//    }
//    else if (!IsNotMovement())
//    {
//        m_Movement->MovementTo(prepareUnit->GetGUID());
//        return;
//    }
//    ProcessCombat(me->GetSelectedUnit());
//}
//
//void BotGroupAI::ProcessHealth(bool canMove)
//{
//    if (me->HasUnitState(UNIT_STATE_CASTING))
//        return;
//    Unit* cruxHeal = (m_CruxHealTarget != ObjectGuid::Empty) ? ObjectAccessor::GetUnit(*me, m_CruxHealTarget) : NULL;
//    if (!cruxHeal || cruxHeal->IsFullHealth() ||
//        !cruxHeal->IsAlive() || me->GetMap() != cruxHeal->GetMap() ||
//        me->GetDistance(cruxHeal) > BOTAI_SEARCH_RANGE * 2)
//    {
//        m_CruxHealTarget = ObjectGuid::Empty;
//        cruxHeal = NULL;
//    }
//    NearUnitVec& needHealth = SearchNeedHealth(BOTAI_SEARCH_RANGE * 1.6f);
//    if (needHealth.empty() && cruxHeal == NULL)
//    {
//        ProcessPrepareHealth();
//        //ProcessCombat(me->GetSelectedUnit());
//        return;
//    }
//    uint32 cruxRate = (cruxHeal == NULL) ? 0 : urand(0, 99);
//    Unit* healthPlayer = (cruxRate > 60 || needHealth.empty()) ? cruxHeal : NULL;
//    if (needHealth.size() > 0 && (!healthPlayer || cruxRate <= 60))
//        healthPlayer = needHealth[urand(0, needHealth.size() - 1)];
//    if (!healthPlayer)
//    {
//        ProcessPrepareHealth();
//        //ProcessCombat(me->GetSelectedUnit());
//        return;
//    }
//    bool inView = me->IsWithinLOSInMap(healthPlayer);
//    if (inView)
//    {
//        if (me->GetDistance(healthPlayer) > BOTAI_RANGESPELL_DISTANCE - 3)
//        {
//            if (canMove && !IsNotMovement())
//                m_Movement->MovementTo(healthPlayer->GetPositionX(), healthPlayer->GetPositionY(), healthPlayer->GetPositionZ());
//            return;
//        }
//        else
//        {
//            if (canMove)
//            {
//                m_Movement->ClearMovement();
//                me->SetInFront(healthPlayer);
//                //me->SetFacingToObject(healthPlayer);
//            }
//            ProcessHealthSpell(healthPlayer);
//            return;
//        }
//    }
//    else if (canMove && !IsNotMovement())
//    {
//        m_Movement->MovementTo(healthPlayer->GetGUID());
//        return;
//    }
//    if (canMove && NeedFlee())
//    {
//        ProcessFlee();
//        return;
//    }
//}
//
//void BotGroupAI::ProcessCombat(Unit* pTarget)
//{
//    if (!pTarget || !pTarget->IsAlive())
//        return;
//    if (TargetIsStealth(pTarget->ToPlayer()))
//    {
//        me->SetSelection(ObjectGuid::Empty);
//        return;
//    }
//    bool inView = me->IsWithinLOSInMap(pTarget);
//    if (inView)
//    {
//        if (pTarget->ToPlayer() && !me->IsPvP())
//            BotUtility::PlayerBotTogglePVP(me, true);
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//        if (m_IsRangeBot)
//        {
//            if (NeedFlee())
//            {
//                Unit* pVictim = me->GetVictim();
//                if (!pVictim || pVictim != pTarget || !me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
//                    me->Attack(pTarget, true);
//                ProcessFlee();
//                if (!IsNotSelect(pTarget))
//                    ProcessMeleeSpell(pTarget);
//            }
//            else if (me->GetDistance(pTarget) <= BOTAI_RANGESPELL_DISTANCE)
//            {
//                Unit* pVictim = me->GetVictim();
//                if (!pVictim || pVictim != pTarget)
//                    me->Attack(pTarget, false);
//                if (!IsNotSelect(pTarget))// && !DoFaceToTarget(pTarget))
//                {
//                    me->SetInFront(pTarget);
//                    me->SetFacingToObject(pTarget);
//                    if (me->getClass() != Classes::CLASS_HUNTER)
//                        m_Movement->ClearMovement();
//                    ChaseTarget(pTarget, false, BOTAI_RANGESPELL_DISTANCE);
//                    ProcessRangeSpell(pTarget);
//                    if (!me->HasUnitState(UNIT_STATE_CASTING))
//                        DoRangedAttackIfReady();
//                }
//            }
//            else if (!IsNotMovement())
//            {
//                m_Movement->MovementToTarget();
//            }
//        }
//        else
//        {
//            Unit* pVictim = me->GetVictim();
//            if (!pVictim || pVictim != pTarget)
//                me->Attack(pTarget, true);
//            if (NeedFlee())
//            {
//                ProcessFlee();
//                if (!IsNotSelect(pTarget))
//                {
//                    if (IsTankBotAI() || me->IsWithinMeleeRange(pTarget))
//                        ProcessMeleeSpell(pTarget);
//                    else if (me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE)
//                        ProcessRangeSpell(pTarget);
//                }
//            }
//            else if (me->IsWithinMeleeRange(pTarget))
//            {
//                me->SetInFront(pTarget);
//                me->SetFacingToObject(pTarget);
//                //if (!DoFaceToTarget(pTarget))
//                {
//                    if (!IsNotMovement())
//                        ChaseTarget(pTarget, true);
//                    if (!IsNotSelect(pTarget))
//                    {
//                        ProcessMeleeSpell(pTarget);
//                        DoMeleeAttackIfReady();
//                    }
//                }
//            }
//            else
//            {
//                if (!IsNotMovement())
//                    m_Movement->MovementToTarget();
//                if (me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE)
//                {
//                    ProcessRangeSpell(pTarget);
//                }
//            }
//        }
//    }
//    else if (!IsNotMovement() && me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE && me->IsInCombat())
//    {
//        m_Movement->MovementToTarget();
//    }
//      
//}
//
//void BotGroupAI::ProcessHalt(Unit* pTarget)
//{
//    if (!pTarget || !pTarget->IsAlive())
//        return;
//    if (TargetIsStealth(pTarget->ToPlayer()) || IsNotSelect(pTarget))
//    {
//        me->SetSelection(ObjectGuid::Empty);
//        return;
//    }
//    if (me->HasUnitState(UNIT_STATE_CASTING))
//        return;
//    bool inView = me->IsWithinLOSInMap(pTarget);
//    if (inView)
//    {
//        Unit* pVictim = me->GetVictim();
//        if (!pVictim || pVictim != pTarget)
//            me->Attack(pTarget, false);
//        if (m_IsRangeBot)
//        {
//            //ChaseTarget(pTarget, false, me->GetDistance(pTarget->GetPosition()));
//            ProcessRangeSpell(pTarget);
//            DoRangedAttackIfReady();
//        }
//        else if (me->IsWithinMeleeRange(pTarget))
//        {
//            //ChaseTarget(pTarget, false, me->GetDistance(pTarget->GetPosition()));
//            ProcessMeleeSpell(pTarget);
//            DoMeleeAttackIfReady();
//        }
//        else
//        {
//            if (me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE)
//            {
//                ProcessRangeSpell(pTarget);
//            }
//        }
//    }
//}
//
//bool BotGroupAI::ProcessTank(Unit* pTarget)
//{
//    Unit* pUnit = NULL;
//    pUnit = m_TankTargets.GetNeedPullTarget();
//    if (!pUnit)
//        pUnit = SearchTankTargetEnemy();
//    if (!pUnit)
//    {
//        if (pTarget && pTarget->IsAlive())
//            pUnit = pTarget;
//        else
//        {
//            me->SetSelection(ObjectGuid::Empty);
//        }
//    }
//    else
//        me->SetSelection(pUnit->GetGUID());
//    if (!pUnit)
//        return false;
//    if (m_TankTargets.UpdateTankTarget(m_Movement))
//        return true;
//    float distance = me->GetDistance(pUnit->GetPosition());
//    if (distance <= 5.0f)
//    {
//        if (!HasAuraMechanic(pUnit, Mechanics::MECHANIC_FEAR) && !HasAuraMechanic(pUnit, Mechanics::MECHANIC_HORROR) && !HasAuraMechanic(pUnit, Mechanics::MECHANIC_STUN))
//        {
//            ObjectGuid& guid = pUnit->GetTarget();
//            if (guid.IsPlayer())
//            {
//                Player* pUnitTarget = ObjectAccessor::FindPlayer(guid);
//                if (pUnitTarget && me != pUnitTarget)
//                {
//                    if (!pUnitTarget->IsTankPlayer() || pUnitTarget->GetTarget() != pUnit->GetGUID())
//                        ProcessPullSpell(pUnit);
//                }
//            }
//            else
//                ProcessPullSpell(pUnit);
//        }
//        ProcessCombat(pUnit);
//    }
//    else
//    {
//        if (distance >= NEEDFLEE_CHECKRANGE && distance < BOTAI_RANGESPELL_DISTANCE)
//            ProcessRangeSpell(pUnit);
//        m_Movement->MovementToTarget();
//    }
//    return true;
//}
//
//void BotGroupAI::ChaseTarget(Unit* pTarget, bool isMelee, float range)
//{
//    if (IsNotSelect(pTarget))
//        return;
//    if (isMelee && me->InBattleground())
//    {
//        if (me->IsStopped())
//        {
//            Position& targetPos = pTarget->GetPosition();
//            float rndOffset = frand(-float(M_PI_4) * 0.75f, float(M_PI_4) * 0.75f);
//            Position& pos = me->GetFirstCollisionPosition(me->GetDistance(targetPos) + range, me->GetRelativeAngle(&targetPos) + rndOffset);
//            m_Movement->MovementTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
//            //me->GetMotionMaster()->MovePoint(0, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
//        }
//    }
//    else
//    {
//        //if (me->isInBack(pTarget) && !IsNotMovement())// (fabsf(selfAngle) > M_PI_4)
//        //{
//        //	Movement::MoveSplineInit init(me);
//        //	init.MoveTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZMinusOffset());
//        //	init.SetFacing(pTarget);
//        //	init.SetOrientationFixed(true);
//        //	init.Launch();
//        //}
//        //else// if (!IsNotMovement())
//        if (me->GetDistance(pTarget->GetPosition()) > range)
//        {
//            me->GetMotionMaster()->Clear();
//            me->GetMotionMaster()->MoveChase(pTarget, range);
//        }
//        else
//        {
//            m_Movement->ClearMovement();
//        }
//    }
//}
//
//void BotGroupAI::SearchCreatureListFromRange(Unit* center, NearCreatureVec& nearCreatures, float range, bool selfFaction)
//{
//    NearCreatureList nearCreature;
//    Trinity::AllWorldObjectsInRange checker(center, range);
//    Trinity::CreatureListSearcher<Trinity::AllWorldObjectsInRange> searcher(center, nearCreature, checker);
//    Cell::VisitGridObjects(center, searcher, range);
//    for (Creature* pCreature : nearCreature)
//    {
//        if (!pCreature->IsAlive() || !pCreature->IsVisible() || pCreature->getLevel() <= 1 ||
//            m_FliterCreatures.IsFliterCreature(pCreature) || pCreature->IsPet())// || pCreature->IsTotem())
//            continue;
//        if (pCreature->IsInEvadeMode())
//            continue;
//        if (selfFaction && me->IsValidAttackTarget(pCreature))
//            continue;
//        if (!selfFaction && !me->IsValidAttackTarget(pCreature))
//            continue;
//        nearCreatures.push_back(pCreature);
//    }
//}
//
//void BotGroupAI::ToggleFliterCreature(Creature* pCreature, bool fliter)
//{
//    if (!pCreature)
//        return;
//    if (fliter)
//        m_FliterCreatures.UpdateFliterCreature(pCreature);
//    else
//        m_FliterCreatures.RemoveFliterCreature(pCreature);
//}
//
//NearUnitVec BotGroupAI::SearchFriend(float range)
//{
//    NearPlayerList playersNearby;
//    NearUnitVec friendNearby;
//    me->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//        {
//            friendNearby.push_back(pVisionPlayer);
//        }
//    }
//    //NearCreatureVec creatures;
//    //SearchCreatureListFromRange(me, creatures, range, true);
//    //for (Creature* pCreature : creatures)
//    //	friendNearby.push_back(pCreature);
//    return friendNearby;
//}
//
//
//NearUnitVec BotGroupAI::SearchFriendTargetIsTarget(Unit* pTarget, float range)
//{
//    NearPlayerList playersNearby;
//    NearUnitVec friendNearby;
//    pTarget->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!pVisionPlayer->IsPlayerBot())
//            continue;
//        if (pVisionPlayer->GetTarget() != pTarget->GetGUID())
//            continue;
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//        {
//            friendNearby.push_back(pVisionPlayer);
//        }
//    }
//    return friendNearby;
//}
//
//NearPlayerVec BotGroupAI::SearchFarFriend(float minRange, float maxRange, bool isIDLE)
//{
//    NearPlayerList playersNearby;
//    NearPlayerVec friendNearby;
//    me->GetPlayerListInGrid(playersNearby, maxRange);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//        {
//            if (me->GetDistance(pVisionPlayer->GetPosition()) > minRange)
//            {
//                if (isIDLE)
//                {
//                    if (pVisionPlayer->GetSelectedUnit() == NULL || !pVisionPlayer->IsInCombat())
//                        friendNearby.push_back(pVisionPlayer);
//                }
//                else
//                    friendNearby.push_back(pVisionPlayer);
//            }
//        }
//    }
//    return friendNearby;
//}
//
//NearPlayerVec BotGroupAI::ExistFriendAttacker(float range /* = BOTAI_RANGESPELL_DISTANCE */)
//{
//    NearPlayerList playersNearby;
//    NearPlayerVec friendNearby;
//    me->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId() && IsAttacker())
//        {
//            friendNearby.push_back(pVisionPlayer);
//        }
//    }
//
//    return friendNearby;
//}
//
//NearUnitVec BotGroupAI::SearchNeedHealth(float range /* = BOTAI_SEARCH_RANGE */)
//{
//    //NearPlayerList playersNearby;
//    NearUnitVec lifeTo25, life25To55, life55To80;
//    //me->GetPlayerListInGrid(playersNearby, range);
//    Group* pGroup = me->GetGroup();
//    if (!pGroup || pGroup->isBGGroup())
//    {
//        float healthPct = me->GetHealthPct();
//        if (healthPct < 25)
//            lifeTo25.push_back(me);
//        else if (healthPct >= 25 && healthPct < 55)
//            life25To55.push_back(me);
//        else if (healthPct >= 55 && healthPct < 80)
//            life55To80.push_back(me);
//    }
//    else
//    {
//        Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
//        for (Group::MemberSlot const& slot : memList)
//        {
//            Player* player = ObjectAccessor::FindPlayer(slot.guid);
//            if (!player || IsNotSelect(player) || (me->GetMap() != player->GetMap()))
//                continue;
//            if (me->GetDistance(player->GetPosition()) > range)
//                continue;
//            float healthPct = player->GetHealthPct();
//            if (healthPct < 25)
//                lifeTo25.push_back(player);
//            else if (healthPct >= 25 && healthPct < 55)
//                life25To55.push_back(player);
//            else if (healthPct >= 55 && healthPct < 80)
//                life55To80.push_back(player);
//        }
//    }
//    //for (Player* pVisionPlayer : playersNearby)
//    //{
//    //	if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//    //	{
//    //		float healthPct = pVisionPlayer->GetHealthPct();
//    //		if (healthPct < 25)
//    //			lifeTo25.push_back(pVisionPlayer);
//    //		else if (healthPct >= 25 && healthPct < 55)
//    //			life25To55.push_back(pVisionPlayer);
//    //		else if (healthPct >= 55 && healthPct < 80)
//    //			life55To80.push_back(pVisionPlayer);
//    //	}
//    //}
//    //NearCreatureVec creatures;
//    //SearchCreatureListFromRange(me, creatures, range, true);
//    //for (Creature* pCreature : creatures)
//    //{
//    //	float healthPct = pCreature->GetHealthPct();
//    //	if (healthPct < 25)
//    //		lifeTo25.push_back(pCreature);
//    //	else if (healthPct >= 25 && healthPct < 55)
//    //		life25To55.push_back(pCreature);
//    //	else if (healthPct >= 55 && healthPct < 80)
//    //		life55To80.push_back(pCreature);
//    //}
//
//    uint32 rate = urand(0, 99);
//    if (rate >= 85 && life55To80.size() > 0)
//        return life55To80;
//    else if (rate < 85 && rate >= 55 && life25To55.size() > 0)
//        return life25To55;
//    else if (lifeTo25.size() > 0)
//        return lifeTo25;
//    else if (life25To55.size() > 0)
//        return life25To55;
//    return life55To80;
//}
//
//NearUnitVec BotGroupAI::SearchLifePctByFriendRange(Unit* pTarget, float lifePct, float range /* = NEEDFLEE_CHECKRANGE */)
//{
//    NearPlayerList playersNearby;
//    NearUnitVec lifePctPlayers;
//    pTarget->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//        {
//            float healthPct = pVisionPlayer->GetHealthPct();
//            if (healthPct <= lifePct)
//                lifePctPlayers.push_back(pVisionPlayer);
//        }
//    }
//    //NearCreatureVec creatures;
//    //SearchCreatureListFromRange(me, creatures, range, true);
//    //for (Creature* pCreature : creatures)
//    //{
//    //	float healthPct = pCreature->GetHealthPct();
//    //	if (healthPct <= lifePct)
//    //		lifePctPlayers.push_back(pCreature);
//    //}
//
//    return lifePctPlayers;
//}
//
//Unit* BotGroupAI::RandomRangeEnemyByCasting(float range)
//{
//    NearUnitVec enemyPlayers;
//    NearPlayerList playersNearby;
//    me->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//        {
//            if (pVisionPlayer->HasUnitState(UNIT_STATE_CASTING))
//                enemyPlayers.push_back(pVisionPlayer);
//        }
//    }
//    NearCreatureVec creatures;
//    SearchCreatureListFromRange(me, creatures, range, false);
//    for (Creature* pCreature : creatures)
//    {
//        if (pCreature->HasUnitState(UNIT_STATE_CASTING))
//            enemyPlayers.push_back(pCreature);
//    }
//    if (!enemyPlayers.empty())
//    {
//        uint32 index = urand(0, enemyPlayers.size() - 1);
//        return enemyPlayers[index];
//    }
//    return NULL;
//}
//
//Unit* BotGroupAI::SearchTankTargetEnemy(float range)
//{
//    if (!me->IsInWorld())
//        return NULL;
//    NearUnitVec& enemys = RangeEnemyListByHasAura(0, range);
//    if (enemys.empty())
//        return NULL;
//    Group* pGroup = me->GetGroup();
//    if (!pGroup)
//        return NULL;
//    std::map<Player*, std::vector<Unit*> > otherTankPullTargets;
//    float minDistance = 9999;
//    Unit* needUnit = NULL;
//    float targetMeDist = 9999;
//    Unit* targetMeUnit = NULL;
//    for (Unit* pUnit : enemys)
//    {
//        if (!pUnit->IsInCombat())
//            continue;
//        if (TargetIsControl(pUnit))
//            continue;
//        if (TargetIsStealth(pUnit->ToPlayer()))
//            continue;
//        ObjectGuid& guid = pUnit->GetTarget();
//        if (guid == ObjectGuid::Empty)
//            continue;
//        if (guid == me->GetGUID())
//        {
//            float meDist = me->GetDistance(pUnit->GetPosition());
//            if (meDist < targetMeDist)
//            {
//                targetMeDist = meDist;
//                targetMeUnit = pUnit;
//            }
//            continue;
//        }
//        if (guid.IsPlayer())
//        {
//            if (!pGroup->IsMember(guid))
//                continue;
//            Player* player = ObjectAccessor::FindPlayer(guid);
//            if (!player)
//                continue;
//            if (pUnit->GetDistance(player->GetPosition()) > BOTAI_FLEE_JUDGE)
//                continue;
//            BotGroupAI* pGroupAI = dynamic_cast<BotGroupAI*>(player->GetAI());
//            if (pGroupAI && pGroupAI->IsTankBotAI() && !pGroupAI->IsFleeing())
//            {
//                std::vector<Unit*>& targets = otherTankPullTargets[player];
//                targets.push_back(pUnit);
//                continue;
//            }
//            //if (player && player->IsTankPlayer())
//            //	continue;
//        }
//        if (IsNotSelect(pUnit) || IsInvincible(pUnit))
//            continue;
//        float dist = me->GetDistance(pUnit->GetPosition());
//        if (dist < minDistance)
//        {
//            minDistance = dist;
//            needUnit = pUnit;
//        }
//    }
//
//    if (BotGroupAI::PVE_DRIVING && !me->GetMap()->IsDungeon())
//    {
//        if (pGroup->AllGroupIsIDLE())
//        {
//            minDistance = 9999;
//            needUnit = NULL;
//            if (!enemys.empty() && needUnit == NULL && targetMeUnit == NULL)
//            {
//                for (Unit* pUnit : enemys)
//                {
//                    if (IsNotSelect(pUnit) || IsInvincible(pUnit) || TargetIsControl(pUnit))
//                        continue;
//                    ObjectGuid& guid = pUnit->GetTarget();
//                    if (guid != ObjectGuid::Empty && guid.IsPlayer())
//                    {
//                        if (!pGroup->IsMember(guid))
//                            continue;
//                        Player* player = ObjectAccessor::FindPlayer(guid);
//                       /* if (player && player->IsTankPlayer())
//                            continue;*/
//                    }
//                    float dist = me->GetDistance(pUnit->GetPosition());
//                    if (dist < minDistance)
//                    {
//                        minDistance = dist;
//                        needUnit = pUnit;
//                    }
//                }
//            }
//        }
//    }
//    if (needUnit)
//        return needUnit;
//    else if (targetMeUnit)
//        return targetMeUnit;
//    else if (otherTankPullTargets.size() > 0)
//    {
//        uint32 maxTargets = 0;
//        Unit* needTarget = NULL;
//        for (std::map<Player*, std::vector<Unit*> >::iterator itTargets = otherTankPullTargets.begin();
//            itTargets != otherTankPullTargets.end();
//            itTargets++)
//        {
//            std::vector<Unit*>& targets = itTargets->second;
//            uint32 count = targets.size();
//            if (count <= 1)
//                continue;
//            if (count > maxTargets || !needTarget)
//            {
//                maxTargets = count;
//                needTarget = targets[urand(0, count - 1)];
//            }
//        }
//        return needTarget;
//    }
//    return NULL;
//}
//
//NearUnitVec BotGroupAI::RangeEnemyListByHasAura(uint32 aura, float range)
//{
//    NearUnitVec enemyPlayers;
//    NearPlayerList playersNearby;
//    me->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//        {
//            if (TargetIsStealth(pVisionPlayer))
//                continue;
//            if (aura == 0 || pVisionPlayer->HasAura(aura))
//                enemyPlayers.push_back(pVisionPlayer);
//        }
//    }
//    NearCreatureVec creatures;
//    SearchCreatureListFromRange(me, creatures, range, false);
//    for (Creature* pCreature : creatures)
//    {
//        if (aura == 0 || pCreature->HasAura(aura))
//            enemyPlayers.push_back(pCreature);
//    }
//    return enemyPlayers;
//}
//
//NearUnitVec BotGroupAI::RangeEnemyListByNonAura(uint32 aura, float range)
//{
//    NearUnitVec enemyPlayers;
//    if (aura == 0)
//        return enemyPlayers;
//    NearPlayerList playersNearby;
//    me->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//        {
//            if (TargetIsStealth(pVisionPlayer))
//                continue;
//            if (!pVisionPlayer->HasAura(aura))
//                enemyPlayers.push_back(pVisionPlayer);
//        }
//    }
//    NearCreatureVec creatures;
//    SearchCreatureListFromRange(me, creatures, range, false);
//    for (Creature* pCreature : creatures)
//    {
//        if (!pCreature->HasAura(aura))
//            enemyPlayers.push_back(pCreature);
//    }
//    return enemyPlayers;
//}
//
//NearUnitVec BotGroupAI::RangeEnemyListByTargetIsMe(float range)
//{
//    NearUnitVec enemyPlayers;
//    NearPlayerList playersNearby;
//    me->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//        {
//            if (TargetIsStealth(pVisionPlayer))
//                continue;
//            Unit* pUnit = pVisionPlayer->GetSelectedUnit();
//            if (pUnit && pUnit->GetGUID() == me->GetGUID())
//                enemyPlayers.push_back(pVisionPlayer);
//        }
//    }
//    NearCreatureVec creatures;
//    SearchCreatureListFromRange(me, creatures, range, false);
//    for (Creature* pCreature : creatures)
//    {
//        if (pCreature->GetTarget() == me->GetGUID())
//            enemyPlayers.push_back(pCreature);
//    }
//    return enemyPlayers;
//}
//
//NearUnitVec BotGroupAI::RangeListByTargetIsTarget(Unit* pTarget, float range)
//{
//    NearUnitVec enemyPlayers;
//    NearPlayerList playersNearby;
//    pTarget->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//        {
//            if (TargetIsStealth(pVisionPlayer))
//                continue;
//            if (pVisionPlayer->GetSelectedUnit() == pTarget)
//                enemyPlayers.push_back(pVisionPlayer);
//        }
//    }
//    NearCreatureVec creatures;
//    SearchCreatureListFromRange(pTarget, creatures, range, false);
//    for (Creature* pCreature : creatures)
//    {
//        if (pCreature->GetTarget() == pTarget->GetGUID())
//            enemyPlayers.push_back(pCreature);
//    }
//    return enemyPlayers;
//}
//
//NearUnitVec BotGroupAI::RangeEnemyListByTargetRange(Unit* pTarget, float range)
//{
//    NearUnitVec enemyPlayers;
//    NearPlayerList playersNearby;
//    pTarget->GetPlayerListInGrid(playersNearby, range);
//    for (Player* pVisionPlayer : playersNearby)
//    {
//        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//        {
//            if (TargetIsStealth(pVisionPlayer))
//                continue;
//            enemyPlayers.push_back(pVisionPlayer);
//        }
//    }
//    NearCreatureVec creatures;
//    SearchCreatureListFromRange(pTarget, creatures, range, false);
//    for (Creature* pCreature : creatures)
//        enemyPlayers.push_back(pCreature);
//    return enemyPlayers;
//}
//
//NearUnitVec BotGroupAI::SearchFarEnemy(float minRange, float maxRange)
//{
//    NearUnitVec enemyNearby;
//    NearCreatureVec creatures;
//    SearchCreatureListFromRange(me, creatures, maxRange, false);
//    for (Creature* pCreature : creatures)
//    {
//        if (me->GetDistance(pCreature->GetPosition()) > minRange)
//            enemyNearby.push_back(pCreature);
//    }
//    return enemyNearby;
//}
//
//bool BotGroupAI::IsMeleeBotAI()
//{
//    switch (me->getClass())
//    {
//    case CLASS_WARRIOR:
//    case CLASS_PALADIN:
//    case CLASS_ROGUE:
//    case CLASS_DEATH_KNIGHT:
//    case CLASS_SHAMAN:
//    case CLASS_DRUID:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//        return true;
//    case CLASS_MAGE:
//    case CLASS_WARLOCK:
//    case CLASS_PRIEST:
//    case CLASS_HUNTER:
//        return false;
//    }
//    return true;
//}
//
//bool BotGroupAI::IsRangeBotAI()
//{
//    switch (me->getClass())
//    {
//    case CLASS_WARRIOR:
//    case CLASS_PALADIN:
//    case CLASS_ROGUE:
//    case CLASS_DEATH_KNIGHT:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//        return false;
//    case CLASS_MAGE:
//    case CLASS_WARLOCK:
//    case CLASS_PRIEST:
//    case CLASS_HUNTER:
//    case CLASS_SHAMAN:
//    case CLASS_DRUID:
//        return true;
//    }
//    return false;
//}
//
//bool BotGroupAI::IsHealerBotAI()
//{
//    switch (me->getClass())
//    {
//    case CLASS_WARRIOR:
//    case CLASS_ROGUE:
//    case CLASS_DEATH_KNIGHT:
//    case CLASS_MAGE:
//    case CLASS_WARLOCK:
//    case CLASS_HUNTER:
//    case CLASS_DEMON_HUNTER:
//        return false;
//    case CLASS_PALADIN:
//        if (me->GetSpecializationId() == TALENT_SPEC_PALADIN_HOLY)
//            return true;
//    case CLASS_PRIEST:
//        if (me->GetSpecializationId() == TALENT_SPEC_PRIEST_HOLY)
//            return true;
//    case CLASS_SHAMAN:
//        if (me->GetSpecializationId() == TALENT_SPEC_SHAMAN_RESTORATION)
//            return true;
//    case CLASS_DRUID:
//        if (me->GetSpecializationId() == TALENT_SPEC_DRUID_RESTORATION)
//            return true;
//    case CLASS_MONK:
//        if (me->GetSpecializationId() == TALENT_SPEC_MONK_MISTWEAVER)
//            return true;
//    }
//    return false;
//}
//
//Unit* BotGroupAI::GetBotAIValidSelectedUnit()
//{
//    Unit* pTarget = me->GetSelectedUnit();
//    bool isValid = true;
//    if (!pTarget)
//        isValid = false;
//    if (isValid && !pTarget->IsVisible())
//        isValid = false;
//    if (isValid && !me->IsInPhase(pTarget))
//        isValid = false;
//    if (isValid && IsNotSelect(pTarget))
//        isValid = false;
//    if (isValid && TargetIsControl(pTarget))
//        isValid = false;
//    if (isValid && m_FliterCreatures.IsFliterCreature(pTarget->ToCreature()))
//        isValid = false;
//    if (isValid && pTarget->ToCreature())
//    {
//        if (me->GetDistanceZ(pTarget) > 15.0f && !TargetIsRange(me))
//            isValid = false;
//        if (me->GetDistanceZ(pTarget) > 25.0f && TargetIsRange(me))
//            isValid = false;
//    }
//    if (!isValid)
//    {
//        me->AttackStop();
//        me->SetSelection(ObjectGuid::Empty);
//        return NULL;
//    }
//    return pTarget;
//}
//
//bool BotGroupAI::TargetIsControl(Unit* pTarget)
//{
//    if (!pTarget)
//        return false;
//    Creature* pCreature = pTarget->ToCreature();
//    if (pCreature && pCreature->IsInEvadeMode())
//        return true;
//    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM) ||
//        HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISORIENTED) ||
//        HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISTRACT) ||
//        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
//        HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH) ||
//        HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH) ||
//        HasAuraMechanic(pTarget, Mechanics::MECHANIC_IMMUNE_SHIELD))
//        return true;
//    return false;
//}
//
//bool BotGroupAI::TargetIsMelee(Player* pTarget)
//{
//    if (!pTarget)
//        return false;
//    switch (pTarget->getClass())
//    {
//    case CLASS_PALADIN:
//    case CLASS_WARRIOR:
//    case CLASS_ROGUE:
//    case CLASS_DEATH_KNIGHT:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//        return true;
//    case CLASS_MAGE:
//    case CLASS_WARLOCK:
//    case CLASS_HUNTER:
//    case CLASS_PRIEST:
//    case CLASS_DRUID:
//    case CLASS_SHAMAN:
//        return false;
//    }
//    return false;
//}
//
//bool BotGroupAI::TargetIsRange(Player* pTarget)
//{
//    if (!pTarget)
//        return false;
//    switch (pTarget->getClass())
//    {
//    case CLASS_WARRIOR:
//    case CLASS_PALADIN:
//    case CLASS_ROGUE:
//    case CLASS_DEATH_KNIGHT:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//        return false;
//    case CLASS_MAGE:
//    case CLASS_WARLOCK:
//    case CLASS_HUNTER:
//    case CLASS_PRIEST:
//    case CLASS_SHAMAN:
//    case CLASS_DRUID:
//        return true;
//    }
//    return false;
//}
//
//bool BotGroupAI::TargetIsMagic(Player* pTarget)
//{
//    if (!pTarget)
//        return false;
//    switch (pTarget->getClass())
//    {
//    case CLASS_WARRIOR:
//    case CLASS_ROGUE:
//    case CLASS_DEATH_KNIGHT:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//        return false;
//    case CLASS_PALADIN:
//    case CLASS_MAGE:
//    case CLASS_WARLOCK:
//    case CLASS_HUNTER:
//    case CLASS_PRIEST:
//    case CLASS_SHAMAN:
//    case CLASS_DRUID:
//        return true;
//    }
//    return false;
//}
//
//bool BotGroupAI::TargetIsCastMagic(Player* pTarget)
//{
//    if (!pTarget)
//        return false;
//    switch (pTarget->getClass())
//    {
//    case CLASS_WARRIOR:
//    case CLASS_ROGUE:
//    case CLASS_DEATH_KNIGHT:
//    case CLASS_PALADIN:
//    case CLASS_HUNTER:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//        return false;
//    case CLASS_MAGE:
//    case CLASS_WARLOCK:
//    case CLASS_PRIEST:
//    case CLASS_SHAMAN:
//    case CLASS_DRUID:
//        return true;
//    }
//    return false;
//}
//
//bool BotGroupAI::TargetIsStealth(Player* pTarget)
//{
//    if (!pTarget)
//        return false;
//    // (1784 ???? || 5215 ????? || 66 ???? || 58984 ????)
//    if (pTarget->HasAura(1784) || pTarget->HasAura(5215) ||
//        pTarget->HasAura(66) || pTarget->HasAura(58984))
//    {
//        if (!me->CanSeeOrDetect(pTarget, false, true)) // ????
//            return true;
//    }
//    return false;
//}
