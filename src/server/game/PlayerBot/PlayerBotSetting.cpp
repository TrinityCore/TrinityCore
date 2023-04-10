
#include "PlayerBotSetting.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "WorldSession.h"
#include "PlayerBotSession.h"
#include "MapManager.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "Containers.h"

std::vector<InvLevelItems*> PlayerBotSetting::InvLevelItemsBySpec = { std::vector<InvLevelItems*>() };
std::vector<uint32> PlayerBotSetting::beastCreatureEntrys = std::vector<uint32>();
std::vector<uint32> PlayerBotSetting::exoticCreatureEntrys = std::vector<uint32>();

bool PlayerBotSetting::MatchEquipmentSlot(uint8 pos, const ItemTemplate* itemTemplate)
{
    EquipmentSlots slot = EquipmentSlots(pos);
    InventoryType type = InventoryType(itemTemplate->GetInventoryType());
    switch (type)
    {
    case InventoryType::INVTYPE_HEAD:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_HEAD)
            return true;
        break;
    case InventoryType::INVTYPE_NECK:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_NECK)
            return true;
        break;
    case InventoryType::INVTYPE_SHOULDERS:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_SHOULDERS)
            return true;
        break;
    case InventoryType::INVTYPE_CHEST:
    case InventoryType::INVTYPE_ROBE:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_CHEST)
            return true;
        break;
    case InventoryType::INVTYPE_WAIST:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_WAIST)
            return true;
        break;
    case InventoryType::INVTYPE_LEGS:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_LEGS)
            return true;
        break;
    case InventoryType::INVTYPE_FEET:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_FEET)
            return true;
        break;
    case InventoryType::INVTYPE_WRISTS:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_WRISTS)
            return true;
        break;
    case InventoryType::INVTYPE_HANDS:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_HANDS)
            return true;
        break;
    case InventoryType::INVTYPE_FINGER:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_FINGER1 || slot == EquipmentSlots::EQUIPMENT_SLOT_FINGER2)
            return true;
        break;
    case InventoryType::INVTYPE_TRINKET:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_TRINKET1 || slot == EquipmentSlots::EQUIPMENT_SLOT_TRINKET2)
            return true;
        break;
    case InventoryType::INVTYPE_CLOAK:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_BACK)
            return true;
        break;
    case InventoryType::INVTYPE_WEAPON:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_MAINHAND || slot == EquipmentSlots::EQUIPMENT_SLOT_OFFHAND)
            return true;
        break;
    case InventoryType::INVTYPE_2HWEAPON:
    case InventoryType::INVTYPE_WEAPONMAINHAND:
    case InventoryType::INVTYPE_RANGED:
    case InventoryType::INVTYPE_RANGEDRIGHT:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_MAINHAND)
            return true;
        break;
    case InventoryType::INVTYPE_SHIELD:
    case InventoryType::INVTYPE_WEAPONOFFHAND:
    case INVTYPE_HOLDABLE:
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_OFFHAND)
            return true;
        break;
    }

    return false;
}

uint32 PlayerBotSetting::GetItemLevelByAI(const ItemTemplate* item)
{
    if (!item)
        return 0;
    uint32 level = item->GetBaseItemLevel();
    uint32 quality = item->GetQuality();
    if (quality <= 1)
        return level;
    if (quality == ITEM_QUALITY_HEIRLOOM)
        return 999;
    level += uint32(float(level) * (float(quality) * 0.3f));
    return level;
}

bool PlayerBotSetting::IsBetterEquip(Player* player, const ItemTemplate* itemTemplate, int32 /*rndPropID*/)
{
    if (!itemTemplate || itemTemplate->GetBaseRequiredLevel() > player->getLevel())
        return false;

    if (!itemTemplate->IsUsableByLootSpecialization(player, true))
        return false;
    uint16 eDest;
    InventoryResult msg = player->CanEquipNewItem(NULL_SLOT, eDest, itemTemplate->GetId(), true);
    if (msg != EQUIP_ERR_OK)
        return false;
    bool mainhandIsTwo = false;
    for (uint8 slot = EquipmentSlots::EQUIPMENT_SLOT_HEAD; slot < EquipmentSlots::EQUIPMENT_SLOT_END; slot++)
    {
        if (!MatchEquipmentSlot(slot, itemTemplate))
            continue;

        Item* pItem = player->GetItemByPos(255, slot);
        if (!pItem)
        {
            if (slot == EquipmentSlots::EQUIPMENT_SLOT_OFFHAND && mainhandIsTwo)
                return false;
            return true;
        }
        const ItemTemplate* selfTemplate = pItem->GetTemplate();
        if (!selfTemplate)
            continue;
        if (slot == EquipmentSlots::EQUIPMENT_SLOT_MAINHAND)
        {
            if (selfTemplate->GetClass() == ItemClass::ITEM_CLASS_WEAPON && selfTemplate->GetInventoryType() == INVTYPE_2HWEAPON)
                mainhandIsTwo = true;
            else
                mainhandIsTwo = false;
        }
        if (selfTemplate->GetClass() != itemTemplate->GetClass())
            continue;
        if (selfTemplate->GetSubClass() != itemTemplate->GetSubClass())
        {
            if (selfTemplate->GetClass() != ItemClass::ITEM_CLASS_WEAPON || itemTemplate->GetClass() != ItemClass::ITEM_CLASS_WEAPON)
                continue;
            if ((selfTemplate->GetInventoryType() != INVTYPE_2HWEAPON && selfTemplate->GetInventoryType() != INVTYPE_WEAPON && selfTemplate->GetInventoryType() != INVTYPE_WEAPONMAINHAND) ||
                (itemTemplate->GetInventoryType() != INVTYPE_2HWEAPON && itemTemplate->GetInventoryType() != INVTYPE_WEAPON && itemTemplate->GetInventoryType() != INVTYPE_WEAPONMAINHAND))
                continue;
        }
        if (GetItemLevelByAI(selfTemplate) >= GetItemLevelByAI(itemTemplate))
        {
            return false;
        }
        return true;
    }

    return false;
}

void PlayerBotSetting::ClearUnknowMount(Player* player)
{
    if (player->IsMounted())// && AURA_EFFECT_HANDLE_REAL
    {
        player->Dismount();
        player->RemoveAurasByType(SPELL_AURA_MOUNTED);
    }
}

uint32 PlayerBotSetting::CheckMaxLevel(uint32 level)
{
    uint32 worldMaxLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
    if (level > worldMaxLevel)
    {
        level = worldMaxLevel;
    }
    if (level == 0)
        level = 1;
    return level;
}

bool PlayerBotSetting::CheckHunterPet(Player* player)
{
    if (!player || player->getClass() != Classes::CLASS_HUNTER)
        return false;
    if (player->GetPet() == NULL)
    {
        uint32 rndEntry = beastCreatureEntrys[urand(0, beastCreatureEntrys.size() - 1)];
        if (player->GetSpecializationId() == TALENT_SPEC_HUNTER_BEASTMASTER)
            rndEntry = exoticCreatureEntrys[urand(0, exoticCreatureEntrys.size() - 1)];

        if (!rndEntry)
            rndEntry = beastCreatureEntrys[urand(0, beastCreatureEntrys.size() - 1)];

        Pet* pet = player->CreateTamedPetFrom(rndEntry, 1515);
        if (pet)
        {
            player->GetMap()->AddToMap(pet->ToCreature());
            player->SetMinion(pet, true);
            pet->InitPetCreateSpells();
            uint32 spec[] = { 74,79,81 };
            pet->SetSpecialization(spec[urand(0, 2)]);
            pet->InitStatsForLevel(player->getLevel());
            pet->ToCreature()->SetReactState(REACT_ASSIST);
            //pet->SettingAllSpellAutocast(true);
            pet->SavePetToDB(PET_SAVE_AS_CURRENT);
            player->PetSpellInitialize();
            return true;
        }
    }
    else if (Pet* pet = player->GetPet())
    {
        pet->SetLevel(player->getLevel());
        pet->InitStatsForLevel(player->getLevel());
        pet->InitPetCreateSpells();
        uint32 spec[] = { 74,79,81 };
        pet->SetSpecialization(spec[urand(0, 2)]);
        pet->ToCreature()->SetReactState(REACT_ASSIST);
        //pet->SettingAllSpellAutocast(true);
        player->PetSpellInitialize();
        return true;
    }
    return false;
}

uint32 PlayerBotSetting::FindPlayerTalentType(Player* player)
{
    return player->FindTalentType();
}

uint32 PlayerBotSetting::RandomMountByLevel(uint32 /*level*/)
{
    for (MountEntry const* mount : sMountStore)
    {
        if (roll_chance_i(4))
            return mount->SourceSpellID;
    }

    return 142073;
}

bool PlayerBotSetting::BindingPlayerHomePosition(Player* player)
{
    if (!player || !player->IsInWorld() || player->GetMap()->IsDungeon())
        return false;
    if (!MapManager::IsValidMapCoord(player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation()))
        return false;

    uint32 bindspell = 3286;

    // send spell for homebinding (3286)
    player->CastSpell(player, bindspell, true);
    return true;
}

void PlayerBotSetting::Initialize()
{
    for (auto ivi : InvLevelItemsBySpec)
    {
        if (ivi)
        {
            for (uint8 l = 0; l < MAX_LEVEL; l++)
                for (uint8 i = 0; i < INVTYPE_QUIVER; i++)
                    ivi->items[l][i].clear();
            delete ivi;
        }
    }
    InvLevelItemsBySpec.clear();

    InvLevelItemsBySpec.resize(TALENT_SPEC_DEMON_HUNTER_VENGEANCE + 1);
    //for (uint16 i = 0; i <= TALENT_SPEC_DEMON_HUNTER_VENGEANCE; i++)
    //    InvLevelItemsBySpec[i] = nullptr;

    //ivi->items[lvl][inv].push_back(itemid);
    for (ChrSpecializationEntry const* chrSpec : sChrSpecializationStore)
        InvLevelItemsBySpec[chrSpec->ID] = new InvLevelItems;

    //ItemTemplateContainer const its = sObjectMgr->GetItemTemplateStore();
    //for (ItemTemplateContainer::const_iterator itr = its->begin(); itr != its->end(); ++itr)
    //{
    //    const ItemTemplate& item = itr->second;
    //    if (item.GetInventoryType() <= INVTYPE_NON_EQUIP || item.GetInventoryType() > INVTYPE_RANGEDRIGHT)
    //        continue;

    //    if (item.GetQuality() <= 1)
    //        continue;

    //    if (item.GetRequiredSkill() > 0 || item.GetRequiredSpell() > 0 || item.GetRequiredReputationFaction() != 0/* || item.GetArea() != 0 */ || item.GetMap() != 0)
    //        continue;

    //    int16 RequiredLevel = item.GetBaseRequiredLevel();
    //    if (RequiredLevel > MAX_LEVEL)
    //        continue;

    //    for (ChrSpecializationEntry const* chrSpec : sChrSpecializationStore)
    //    {
    //        if (!chrSpec->IsPetSpecialization())
    //            //  if (item.IsUsableBySpecialization(chrSpec->ID, RequiredLevel, false))
    //            InvLevelItemsBySpec[chrSpec->ID]->items[RequiredLevel][item.GetInventoryType()].push_back(item.GetId());
    //    }
    //}

    beastCreatureEntrys.clear();
    exoticCreatureEntrys.clear();
   /* CreatureTemplateContainer const ctc = sObjectMgr->GetCreatureTemplates();
    for (CreatureTemplateContainer::const_iterator itr = ctc->begin(); itr != ctc->end(); ++itr)
    {
        if (itr->second.IsTameable(false))
            beastCreatureEntrys.push_back(itr->second.Entry);

        if (itr->second.IsTameable(true))
            exoticCreatureEntrys.push_back(itr->second.Entry);
    }*/

    TC_LOG_INFO("server.loading", "Initialize all classes trainer talent and spell and equip.");
}

PlayerBotSetting::PlayerBotSetting(Player* player) :
    m_Finish(true),
    m_ResetStep(0),
    m_Player(player),
    m_UpdateEquip(true)
{
}

PlayerBotSetting::~PlayerBotSetting()
{
}

bool PlayerBotSetting::ResetPlayerToLevel(uint32 level, uint32 /*spec*/)
{
    if (!m_Player)
        return false;

    TC_LOG_INFO("server.reset", ">> Reset player level to %d !", level);
    m_Player->GiveLevel(level);
    if (m_Player->GetMaxHealth() == 1)
        m_Player->GiveLevel(CheckMaxLevel(level + 1));
    //  m_Player->SetUInt32Value(PLAYER_XP, 0);
    //  m_Player->SwitchTalent(spec);
    m_ResetStep = 1;
    m_Finish = false;
    return true;
}

uint32 PlayerBotSetting::SwitchPlayerSpec(uint32 specID)
{
    if (ChrSpecializationEntry const* spec = sChrSpecializationStore.AssertEntry(specID))
        if (!spec->IsPetSpecialization())
            m_Player->ActivateTalentGroup(spec);

    return m_Player->GetActiveTalentGroup();
}

void PlayerBotSetting::UpdateReset()
{
    if (m_Finish)
        return;

    if (m_Player->IsInCombat())
        m_Player->CombatStop(true);

    switch (m_ResetStep)
    {
    case 1:
        //m_Player->ResetTalents(true);
        m_Player->RemoveAurasDueToSpell(73523);
        m_Player->RemoveAurasDueToSpell(80653);
        ++m_ResetStep;
        break;
    case 2:
        LearnTalents();
        ++m_ResetStep;
        break;
    case 3:
        if (m_UpdateEquip)
            UnEquipAll();
        ++m_ResetStep;
        break;
    case 4:
        CheckInventroy();
        ++m_ResetStep;
        break;
    case 5:
        if (m_UpdateEquip)
            AddEquip();
        ++m_ResetStep;
        break;
    case 6:
        if (m_UpdateEquip)
            EquipAll();
        ++m_ResetStep;
        break;
    case 7:
        CheckHunterPet(m_Player);
        ++m_ResetStep;
        break;
    case 8:
        m_Player->UpdateMaxHealth();
        m_Player->SetFullHealth();
        //	m_Player->UpdateSkillsToMaxSkillsForLevel();
        m_Player->UpdateAllStats();
        m_Player->SaveToDB();
        ++m_ResetStep;
        break;
    }

    m_Finish = (m_ResetStep >= 9);
    if (m_Finish && m_Player->IsPlayerBot())
    {
        BotGlobleSchedule schedule(BotGlobleScheduleType::BGSType_DelayLevelup, m_Player->GetGUID());
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(m_Player->GetSession());
        if (pSession)
            pSession->PushScheduleToQueue(schedule);

        m_UpdateEquip = true;
    }
}

void PlayerBotSetting::LearnTalents()
{
    //todo47
    LearnSpells();

    if (m_Player->getLevel() < 10)
        return;
    if (m_Player->getClass() == CLASS_WARLOCK && m_Player->HasAura(137027))
        m_Player->RemoveAurasDueToSpell(137027);

    uint32 _spec = m_Player->GetSpecializationId();
    switch (_spec)
    {
    case TALENT_SPEC_MAGE_ARCANE:
        LearnRandomTalentSpell(15, 205022, 236628, 205035);
        LearnRandomTalentSpell(30, 212653, 236457, 235463);
        LearnRandomTalentSpell(45, 55342, 116011, 1463);
        LearnRandomTalentSpell(60, 157980, 205032, 205028);
        LearnRandomTalentSpell(75, 235711, 113724, 205036);
        LearnRandomTalentSpell(90, 114923, 157976, 205039);
        LearnRandomTalentSpell(100, 155147, 234302, 153626);
        break;
    case TALENT_SPEC_MAGE_FIRE:
        LearnRandomTalentSpell(15, 205020, 205023, 205026);
        LearnRandomTalentSpell(30, 212653, 157981, 235365);
        LearnRandomTalentSpell(45, 55342, 116011, 1463);
        LearnRandomTalentSpell(60, 235870, 205029, 205033);
        LearnRandomTalentSpell(75, 236058, 113724, 205036);
        LearnRandomTalentSpell(90, 44457, 157976, 205037);
        LearnRandomTalentSpell(100, 155148, 198929, 153561);
        break;
    case TALENT_SPEC_MAGE_FROST:
        LearnRandomTalentSpell(15, 205021, 205024, 205027);
        LearnRandomTalentSpell(30, 212653, 108839, 235297);
        LearnRandomTalentSpell(45, 55342, 116011, 1463);
        LearnRandomTalentSpell(60, 157997, 205030, 56377);
        LearnRandomTalentSpell(75, 235224, 113724, 205036);
        LearnRandomTalentSpell(90, 112948, 157976, 205038);
        LearnRandomTalentSpell(100, 155149, 199786, 153595);
        break;
    case TALENT_SPEC_PALADIN_HOLY:
        LearnRandomTalentSpell(15, 223306, 114158, 196926);
        LearnRandomTalentSpell(30, 230332, 114154, 214202);
        LearnRandomTalentSpell(45, 198054, 20066, 115750);
        LearnRandomTalentSpell(60, 183425, 183416, 183415);
        LearnRandomTalentSpell(75, 197646, 105809, 114165);
        LearnRandomTalentSpell(90, 196923, 53376, 183778);
        LearnRandomTalentSpell(100, 156910, 197446, 200025);
        break;
    case TALENT_SPEC_PALADIN_PROTECTION:
        LearnRandomTalentSpell(15, 152261, 204019, 203785);
        LearnRandomTalentSpell(30, 203776, 204035, 204023);
        LearnRandomTalentSpell(45, 198054, 20066, 115750);
        LearnRandomTalentSpell(60, 204018, 230332, 203797);
        LearnRandomTalentSpell(75, 213652, 204139, 204077);
        LearnRandomTalentSpell(90, 204150, 204054, 183778);
        LearnRandomTalentSpell(100, 204074, 152262, 203791);
        break;
    case TALENT_SPEC_PALADIN_RETRIBUTION:
        LearnRandomTalentSpell(15, 198038, 213757, 205228);
        LearnRandomTalentSpell(30, 203316, 217020, 218178);
        LearnRandomTalentSpell(45, 198054, 20066, 115750);
        LearnRandomTalentSpell(60, 202271, 231832, 198034);
        LearnRandomTalentSpell(75, 215661, 205191, 21091);
        LearnRandomTalentSpell(90, 213313, 230332, 183778);
        LearnRandomTalentSpell(100, 223817, 231895, 210220);
        break;
    case TALENT_SPEC_WARRIOR_ARMS:
        LearnRandomTalentSpell(15, 202297, 7384, 202161);
        LearnRandomTalentSpell(30, 46968, 107570, 103827);
        LearnRandomTalentSpell(45, 215538, 772, 107574);
        LearnRandomTalentSpell(60, 29838, 202163, 197690);
        LearnRandomTalentSpell(75, 202316, 202593, 202612);
        LearnRandomTalentSpell(90, 227266, 248621, 207982);
        LearnRandomTalentSpell(100, 152278, 203179, 152277);
        break;
    case TALENT_SPEC_WARRIOR_FURY:
        LearnRandomTalentSpell(15, 215556, 202296, 215568);
        LearnRandomTalentSpell(30, 46968, 107570, 103827);
        LearnRandomTalentSpell(45, 215569, 206320, 107574);
        LearnRandomTalentSpell(60, 202224, 202163, 208154);
        LearnRandomTalentSpell(75, 206315, 215571, 202922);
        LearnRandomTalentSpell(90, 12292, 206313, 215573);
        LearnRandomTalentSpell(100, 46924, 202751, 118000);
        break;
    case TALENT_SPEC_WARRIOR_PROTECTION:
        LearnRandomTalentSpell(15, 46968, 107570, 103828);
        LearnRandomTalentSpell(30, 202168, 205484, 223657);
        LearnRandomTalentSpell(45, 202288, 202560, 107574);
        LearnRandomTalentSpell(60, 223662, 202163, 203201);
        LearnRandomTalentSpell(75, 236279, 202561, 202095);
        LearnRandomTalentSpell(90, 202572, 202603, 202743);
        LearnRandomTalentSpell(100, 152278, 203177, 228920);
        break;
    case TALENT_SPEC_DRUID_BALANCE:
        LearnRandomTalentSpell(15, 205636, 202425, 202345);
        LearnRandomTalentSpell(30, 108238, 102280, 102401);
        LearnRandomTalentSpell(45, 202157, 197491, 197492);
        LearnRandomTalentSpell(60, 5211, 102359, 132469);
        LearnRandomTalentSpell(75, 114107, 102560, 202347);
        LearnRandomTalentSpell(90, 202342, 202359, 202360);
        LearnRandomTalentSpell(100, 202770, 202354, 202430);
        break;
    case TALENT_SPEC_DRUID_CAT:
        LearnRandomTalentSpell(15, 202021, 202022, 155580);
        LearnRandomTalentSpell(30, 108238, 102280, 102401);
        LearnRandomTalentSpell(45, 197488, 217615, 197492);
        LearnRandomTalentSpell(60, 5211, 102359, 132469);
        LearnRandomTalentSpell(75, 158476, 102543, 202032);
        LearnRandomTalentSpell(90, 202031, 202028, 52610);
        LearnRandomTalentSpell(100, 236068, 155672, 202060);
        break;
    case TALENT_SPEC_DRUID_BEAR:
        LearnRandomTalentSpell(15, 203953, 155835, 203962);
        LearnRandomTalentSpell(30, 204012, 236748, 102401);
        LearnRandomTalentSpell(45, 197488, 202155, 197492);
        LearnRandomTalentSpell(60, 5211, 102359, 132469);
        LearnRandomTalentSpell(75, 158477, 102359, 132469);
        LearnRandomTalentSpell(90, 203974, 155578, 203965);
        LearnRandomTalentSpell(100, 204053, 204066, 80313);
        break;
    case TALENT_SPEC_DRUID_RESTORATION:
        LearnRandomTalentSpell(15, 200383, 102351, 207383);
        LearnRandomTalentSpell(30, 108238, 102280, 102401);
        LearnRandomTalentSpell(45, 197632, 197490, 197491);
        LearnRandomTalentSpell(60, 5211, 102359, 132469);
        LearnRandomTalentSpell(75, 158478, 33891, 200390);
        LearnRandomTalentSpell(90, 207385, 197073, 155675);
        LearnRandomTalentSpell(100, 155577, 197061, 197721);
        break;
    case TALENT_SPEC_DEATHKNIGHT_BLOOD:
        LearnRandomTalentSpell(56, 195679, 221536, 206931);
        LearnRandomTalentSpell(57, 194662, 246426, 211078);
        LearnRandomTalentSpell(58, 219786, 221699, 205727);
        LearnRandomTalentSpell(60, 206940, 205723, 219809);
        LearnRandomTalentSpell(75, 206970, 206960, 219779);
        LearnRandomTalentSpell(90, 206967, 194679, 206974);
        LearnRandomTalentSpell(100, 194844, 206977, 114556);
        break;
    case TALENT_SPEC_DEATHKNIGHT_FROST:
        LearnRandomTalentSpell(56, 207057, 194878, 207104);
        LearnRandomTalentSpell(57, 207060, 207061, 57330);
        LearnRandomTalentSpell(58, 207126, 194913, 207142);
        LearnRandomTalentSpell(60, 207161, 207167, 207170);
        LearnRandomTalentSpell(75, 207188, 207200, 253593);
        LearnRandomTalentSpell(90, 207230, 194909, 194912);
        LearnRandomTalentSpell(100, 207256, 152279, 207127);
        break;
    case TALENT_SPEC_DEATHKNIGHT_UNHOLY:
        LearnRandomTalentSpell(56, 194916, 207264, 207269);
        LearnRandomTalentSpell(57, 207317, 194917, 194918);
        LearnRandomTalentSpell(58, 207289, 207305, 207311);
        LearnRandomTalentSpell(60, 207313, 108194, 207316);
        LearnRandomTalentSpell(75, 207321, 207319, 212763);
        LearnRandomTalentSpell(90, 198943, 207346, 207272);
        LearnRandomTalentSpell(100, 207349, 152280, 130736);
        break;
    case TALENT_SPEC_HUNTER_BEASTMASTER:
        LearnRandomTalentSpell(15, 204308, 194397, 193532);
        LearnRandomTalentSpell(30, 199530, 217200, 53209);
        LearnRandomTalentSpell(45, 109215, 199523, 199921);
        LearnRandomTalentSpell(60, 199528, 194306, 130392);
        LearnRandomTalentSpell(75, 109248, 19386, 19577);
        LearnRandomTalentSpell(90, 131894, 120360, 194386);
        LearnRandomTalentSpell(100, 201430, 199532, 191384);
        break;
    case TALENT_SPEC_HUNTER_MARKSMAN:
        LearnRandomTalentSpell(15, 155228, 193533, 53238);
        LearnRandomTalentSpell(30, 194595, 194599, 199527);
        LearnRandomTalentSpell(45, 109215, 199523, 199921);
        LearnRandomTalentSpell(60, 212431, 206817, 234588);
        LearnRandomTalentSpell(75, 109248, 19386, 199483);
        LearnRandomTalentSpell(90, 131894, 120360, 194386);
        LearnRandomTalentSpell(100, 214579, 198670, 199522);
        break;
    case TALENT_SPEC_HUNTER_SURVIVAL:
        LearnRandomTalentSpell(15, 204315, 200163, 201082);
        LearnRandomTalentSpell(30, 206505, 201075, 201078);
        LearnRandomTalentSpell(45, 109215, 781, 199921);
        LearnRandomTalentSpell(60, 194277, 236698, 162488);
        LearnRandomTalentSpell(75, 191241, 200108, 199483);
        LearnRandomTalentSpell(90, 212436, 194855, 87935);
        LearnRandomTalentSpell(100, 194407, 199543, 191384);
        break;
    case TALENT_SPEC_PRIEST_DISCIPLINE:
        LearnRandomTalentSpell(15, 109142, 193134, 214621);
        LearnRandomTalentSpell(30, 121536, 64129, 193063);
        LearnRandomTalentSpell(45, 204263, 196704, 205367);
        LearnRandomTalentSpell(60, 129250, 197045, 123040);
        LearnRandomTalentSpell(75, 246393, 152118, 204065);
        LearnRandomTalentSpell(90, 204197, 110744, 120517);
        LearnRandomTalentSpell(100, 10060, 200309, 246287);
        break;
    case TALENT_SPEC_PRIEST_HOLY:
        LearnRandomTalentSpell(15, 200128, 200153, 193155);
        LearnRandomTalentSpell(30, 121536, 214121, 235189);
        LearnRandomTalentSpell(45, 204263, 200199, 196707);
        LearnRandomTalentSpell(60, 196985, 200209, 64901);
        LearnRandomTalentSpell(75, 109186, 32546, 197034);
        LearnRandomTalentSpell(90, 197031, 110744, 120517);
        LearnRandomTalentSpell(100, 200183, 193157, 204883);
        break;
    case TALENT_SPEC_PRIEST_SHADOW:
        LearnRandomTalentSpell(15, 109142, 193195, 205351);
        LearnRandomTalentSpell(30, 193173, 64129, 193063);
        LearnRandomTalentSpell(45, 205369, 196704, 205367);
        LearnRandomTalentSpell(60, 199849, 199853, 205371);
        LearnRandomTalentSpell(75, 199855, 155271, 162452);
        LearnRandomTalentSpell(90, 10060, 238558, 200174);
        LearnRandomTalentSpell(100, 193225, 205385, 193223);
        break;
    case TALENT_SPEC_ROGUE_ASSASSINATION:
        LearnRandomTalentSpell(15, 196864, 193640, 16511);
        LearnRandomTalentSpell(30, 14062, 108208, 108209);
        LearnRandomTalentSpell(45, 193531, 114015, 14983);
        LearnRandomTalentSpell(60, 108211, 79008, 31230);
        LearnRandomTalentSpell(75, 196861, 131511, 154904);
        LearnRandomTalentSpell(90, 245388, 193539, 200806);
        LearnRandomTalentSpell(100, 152152, 137619, 152150);
        break;
    case TALENT_SPEC_ROGUE_COMBAT:
        LearnRandomTalentSpell(15, 196937, 200733, 196938);
        LearnRandomTalentSpell(30, 195457, 196924, 196922);
        LearnRandomTalentSpell(45, 193531, 114015, 14983);
        LearnRandomTalentSpell(60, 193546, 79008, 31230);
        LearnRandomTalentSpell(75, 199743, 131511, 108216);
        LearnRandomTalentSpell(90, 185767, 193539, 51690);
        LearnRandomTalentSpell(100, 5171, 137619, 152150);
        break;
    case TALENT_SPEC_ROGUE_SUBTLETY:
        LearnRandomTalentSpell(15, 31233, 193537, 200758);
        LearnRandomTalentSpell(30, 14062, 108208, 108209);
        LearnRandomTalentSpell(45, 193531, 114015, 14983);
        LearnRandomTalentSpell(60, 200759, 79008, 31230);
        LearnRandomTalentSpell(75, 196951, 131511, 200778);
        LearnRandomTalentSpell(90, 245687, 193539, 238104);
        LearnRandomTalentSpell(100, 196976, 137619, 152150);
        break;
    case TALENT_SPEC_SHAMAN_ELEMENTAL:
        LearnRandomTalentSpell(15, 201909, 170374, 210643);
        LearnRandomTalentSpell(30, 192063, 108281, 192077);
        LearnRandomTalentSpell(45, 192058, 51485, 196932);
        LearnRandomTalentSpell(60, 210707, 192087, 16166);
        LearnRandomTalentSpell(75, 192235, 117013, 117014);
        LearnRandomTalentSpell(90, 192222, 192249, 108283);
        LearnRandomTalentSpell(100, 114050, 210689, 210714);
        break;
    case TALENT_SPEC_SHAMAN_ENHANCEMENT:
        LearnRandomTalentSpell(15, 201898, 201900, 197992);
        LearnRandomTalentSpell(30, 215864, 196884, 192077);
        LearnRandomTalentSpell(45, 192058, 51485, 196932);
        LearnRandomTalentSpell(60, 192106, 192087, 210853);
        LearnRandomTalentSpell(75, 192234, 210727, 210731);
        LearnRandomTalentSpell(90, 192246, 197211, 197214);
        LearnRandomTalentSpell(100, 114051, 246035, 188089);
        break;
    case TALENT_SPEC_SHAMAN_RESTORATION:
        LearnRandomTalentSpell(15, 200071, 73685, 200072);
        LearnRandomTalentSpell(30, 192063, 192088, 192077);
        LearnRandomTalentSpell(45, 192058, 51485, 196932);
        LearnRandomTalentSpell(60, 197464, 108281, 200076);
        LearnRandomTalentSpell(75, 207399, 198838, 207401);
        LearnRandomTalentSpell(90, 197467, 157153, 108283);
        LearnRandomTalentSpell(100, 114052, 197995, 157154);
        break;
    case TALENT_SPEC_WARLOCK_AFFLICTION:
        LearnRandomTalentSpell(15, 48181, 196102, 235155);
        LearnRandomTalentSpell(30, 196105, 196103, 235157);
        LearnRandomTalentSpell(45, 48018, 6789, 5484);
        LearnRandomTalentSpell(60, 205179, 196226, 196098);
        LearnRandomTalentSpell(75, 219272, 111400, 108416);
        LearnRandomTalentSpell(90, 152107, 108501, 108503);
        LearnRandomTalentSpell(100, 234876, 63106, 215941);
        break;
    case TALENT_SPEC_WARLOCK_DEMONOLOGY:
        LearnRandomTalentSpell(15, 196269, 205181, 205145);
        LearnRandomTalentSpell(30, 196270, 196272, 196277);
        LearnRandomTalentSpell(45, 48018, 6789, 30283);
        LearnRandomTalentSpell(60, 196283, 196605, 196098);
        LearnRandomTalentSpell(75, 219272, 111400, 108416);
        LearnRandomTalentSpell(90, 152107, 108501, 171975);
        LearnRandomTalentSpell(100, 205180, 157695, 215491);
        break;
    case TALENT_SPEC_WARLOCK_DESTRUCTION:
        LearnRandomTalentSpell(15, 196406, 205184, 17877);
        LearnRandomTalentSpell(30, 205148, 196412, 235157);
        LearnRandomTalentSpell(45, 48018, 6789, 30283);
        LearnRandomTalentSpell(60, 152108, 196408, 196098);
        LearnRandomTalentSpell(75, 1219272, 111400, 108416);
        LearnRandomTalentSpell(90, 152107, 108501, 108503);
        LearnRandomTalentSpell(100, 196410, 196447, 215941);
        break;
    case TALENT_SPEC_MONK_BREWMASTER:
        LearnRandomTalentSpell(15, 123986, 196607, 115098);
        LearnRandomTalentSpell(30, 115008, 116841, 115173);
        LearnRandomTalentSpell(45, 196721, 115399, 196719);
        LearnRandomTalentSpell(60, 116844, 115315, 119381);
        LearnRandomTalentSpell(75, 122281, 237076, 122278);
        LearnRandomTalentSpell(90, 116847, 132578, 196730);
        LearnRandomTalentSpell(100, 196738, 196736, 196737);
        break;
    case TALENT_SPEC_MONK_BATTLEDANCER:
        LearnRandomTalentSpell(15, 123986, 124081, 115098);
        LearnRandomTalentSpell(30, 115008, 116841, 115173);
        LearnRandomTalentSpell(45, 197915, 210802, 197900);
        LearnRandomTalentSpell(60, 116844, 198898, 119381);
        LearnRandomTalentSpell(75, 122281, 122783, 122278);
        LearnRandomTalentSpell(90, 196725, 198664, 115313);
        LearnRandomTalentSpell(100, 197908, 197895, 210804);
        break;
    case TALENT_SPEC_MONK_MISTWEAVER:
        LearnRandomTalentSpell(15, 123986, 196607, 115098);
        LearnRandomTalentSpell(30, 115008, 116841, 115173);
        LearnRandomTalentSpell(45, 115288, 115396, 121817);
        LearnRandomTalentSpell(60, 116844, 115315, 119381);
        LearnRandomTalentSpell(75, 122281, 122783, 122278);
        LearnRandomTalentSpell(90, 116847, 123904, 196740);
        LearnRandomTalentSpell(100, 196743, 152175, 152173);
        break;
    case TALENT_SPEC_DEMON_HUNTER_HAVOC:
        LearnRandomTalentSpell(98, 192939, 232893, 203550);
        LearnRandomTalentSpell(100, 203551, 203555, 206478);
        LearnRandomTalentSpell(102, 206475, 206416, 206473);
        LearnRandomTalentSpell(104, 196555, 205411, 204909);
        LearnRandomTalentSpell(106, 206476, 211881, 206491);
        LearnRandomTalentSpell(108, 203556, 206477, 193897);
        LearnRandomTalentSpell(110, 247938, 211053, 213410);
        break;
    case TALENT_SPEC_DEMON_HUNTER_VENGEANCE:
        LearnRandomTalentSpell(98, 207550, 207548, 209400);
        LearnRandomTalentSpell(100, 207697, 227174, 207739);
        LearnRandomTalentSpell(102, 232893, 227322, 211881);
        LearnRandomTalentSpell(104, 218612, 209795, 217996);
        LearnRandomTalentSpell(106, 207666, 202138, 209281);
        LearnRandomTalentSpell(108, 212084, 247254, 247454);
        LearnRandomTalentSpell(110, 209258, 236189, 227225);
        break;
    }

    m_Player->SendTalentsInfoData();
}

void PlayerBotSetting::LearnSpells()
{
    if (m_Player->IsPlayerBot())
    {
        //CheckBotLearnSpell(200749); //
        if (m_Player->getClass() == CLASS_DEMON_HUNTER)
        {
            if (m_Player->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_HAVOC)
            {
                CheckBotLearnSpell(188499);
                CheckBotLearnSpell(198793);
                CheckBotLearnSpell(198589);
                CheckBotLearnSpell(179057);
            }
            else
            {
                CheckBotLearnSpell(204596);
                CheckBotLearnSpell(203720);
                CheckBotLearnSpell(204021);
                CheckBotLearnSpell(185245);
            }
            CheckBotLearnSpell(191427);
            CheckBotLearnSpell(183752);
            CheckBotLearnSpell(185123);
            CheckBotLearnSpell(196718);
            CheckBotLearnSpell(198013);
            CheckBotLearnSpell(217832);
        }
    }
}

void PlayerBotSetting::CheckBotLearnSpell(uint32 spell)
{
    if (!m_Player->HasSpell(spell))
        m_Player->LearnSpell(spell, false);
}

void PlayerBotSetting::CheckInventroy()
{
    for (uint8 bag = INVENTORY_SLOT_BAG_START; bag < INVENTORY_SLOT_BAG_END; bag++)
    {
        if (!m_Player->GetItemByPos(INVENTORY_SLOT_BAG_0, bag))
        {
            ItemPosCountVec dest;
            if (m_Player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 54444, 1) == EQUIP_ERR_OK)
                if (Item* item = m_Player->StoreNewItem(dest, 54444, true))
                    EquipItem(item);
        }
    }
}

void PlayerBotSetting::UnEquipAll()
{
    //uint32 Artifact[] = { 127857, 128820, 128862, 128823, 128866, 120978, 128910, 128908, 128289, 128858, 128860, 128821, 128306, 128402, 128292, 128403, 128861, 128826, 128808, 128868, 128825, 128827, 128870, 128872, 128476, 128935, 128819, 128911, 128942, 128943, 128941, 128938, 128940, 128937, 127829, 128832 };
    std::set<uint32> Artifact = { 127857, 128820, 128862, 128823, 128866, 120978, 128910, 128908, 128289, 128858, 128860, 128821, 128306, 128402, 128292, 128403, 128861, 128826, 128808, 128868, 128825, 128827, 128870, 128872, 128476, 128935, 128819, 128911, 128942, 128943, 128941, 128938, 128940, 128937, 127829, 128832 };

    bool isBot = m_Player->IsPlayerBot();
    for (uint8 slot = EQUIPMENT_SLOT_HEAD; slot < EQUIPMENT_SLOT_END; slot++)
    {
        if (Item* pItem = m_Player->GetItemByPos(255, slot))
        {

           /* if (Artifact.find(pItem->GetEntry()) != Artifact.end())
            {
                m_Player->AutoUnequip(pItem);
                continue;
            }*/

            if (!isBot && pItem->GetEntry() == 6948)
                continue;

            uint16 pos = (255 << 8) | slot;
            if (m_Player->CanUnequipItem(pos, false) != EQUIP_ERR_OK)
                continue;

            m_Player->DestroyItem(255, slot, true);
        }
    }

    for (uint8 packslot = INVENTORY_SLOT_ITEM_START; packslot < INVENTORY_SLOT_ITEM_END; packslot++)
    {
        if (Item* pItem = m_Player->GetItemByPos(255, packslot))
        {
            if (Artifact.find(pItem->GetEntry()) != Artifact.end())
                continue;

            if (!isBot && pItem->GetEntry() == 6948)
                continue;

            m_Player->DestroyItem(255, packslot, true);
        }
    }

    for (uint8 bagslot = INVENTORY_SLOT_BAG_START; bagslot < INVENTORY_SLOT_BAG_END; bagslot++)
    {
        if (Bag* pBag = m_Player->GetBagByPos(bagslot))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                if (Item* pItem = pBag->GetItemByPos(uint8(j)))
                {
                    if (Artifact.find(pItem->GetEntry()) != Artifact.end())
                        continue;

                    if (!isBot && pItem->GetEntry() == 6948)
                        continue;

                    m_Player->DestroyItem(bagslot, uint8(j), true);
                }
            }
        }
    }
}

uint32 GetArtifactID(uint32 spec)
{
    switch (spec)
    {
    case TALENT_SPEC_MAGE_ARCANE:
        return 127857;
    case TALENT_SPEC_MAGE_FIRE:
        return 128820;
    case TALENT_SPEC_MAGE_FROST:
        return 128862;
    case TALENT_SPEC_PALADIN_HOLY:
        return 128823;
    case TALENT_SPEC_PALADIN_PROTECTION:
        return 128866;
    case TALENT_SPEC_PALADIN_RETRIBUTION:
        return 120978;
    case TALENT_SPEC_WARRIOR_ARMS:
        return 128910;
    case TALENT_SPEC_WARRIOR_FURY:
        return 128908;
    case TALENT_SPEC_WARRIOR_PROTECTION:
        return 128289;
    case TALENT_SPEC_DRUID_BALANCE:
        return 128858;
    case TALENT_SPEC_DRUID_CAT:
        return 128860;
    case TALENT_SPEC_DRUID_BEAR:
        return 128821;
    case TALENT_SPEC_DRUID_RESTORATION:
        return 128306;
    case TALENT_SPEC_DEATHKNIGHT_BLOOD:
        return 128402;
    case TALENT_SPEC_DEATHKNIGHT_FROST:
        return 128292;
    case TALENT_SPEC_DEATHKNIGHT_UNHOLY:
        return 128403;
    case TALENT_SPEC_HUNTER_BEASTMASTER:
        return 128861;
    case TALENT_SPEC_HUNTER_MARKSMAN:
        return 128826;
    case TALENT_SPEC_HUNTER_SURVIVAL:
        return 128808;
    case TALENT_SPEC_PRIEST_DISCIPLINE:
        return 128868;
    case TALENT_SPEC_PRIEST_HOLY:
        return 128825;
    case TALENT_SPEC_PRIEST_SHADOW:
        return 128827;
    case TALENT_SPEC_ROGUE_ASSASSINATION:
        return 128870;
    case TALENT_SPEC_ROGUE_COMBAT:
        return 128872;
    case TALENT_SPEC_ROGUE_SUBTLETY:
        return 128476;
    case TALENT_SPEC_SHAMAN_ELEMENTAL:
        return 128935;
    case TALENT_SPEC_SHAMAN_ENHANCEMENT:
        return 128819;
    case TALENT_SPEC_SHAMAN_RESTORATION:
        return 128911;
    case TALENT_SPEC_WARLOCK_AFFLICTION:
        return 128942;
    case TALENT_SPEC_WARLOCK_DEMONOLOGY:
        return 128943;
    case TALENT_SPEC_WARLOCK_DESTRUCTION:
        return 128941;
    case TALENT_SPEC_MONK_BREWMASTER:
        return 128938;
    case TALENT_SPEC_MONK_BATTLEDANCER:
        return 128940;
    case TALENT_SPEC_MONK_MISTWEAVER:
        return 128937;
    case TALENT_SPEC_DEMON_HUNTER_HAVOC:
        return 127829;
    case TALENT_SPEC_DEMON_HUNTER_VENGEANCE:
        return 128832;
    }
    return 0;
}

void PlayerBotSetting::AddEquip()
{
    m_NeedEquips.clear();
    uint32 level = m_Player->getLevel();
    uint16 spec = m_Player->GetSpecializationId();

    //??    EQUIPMENT_SLOT_HEAD         = 0
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_HEAD, level, 0))
        AddOnceEquip(item);
    //??    EQUIPMENT_SLOT_NECK         = 1
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_NECK, level, 0))
        AddOnceEquip(item);
    //??    EQUIPMENT_SLOT_SHOULDERS = 2
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_SHOULDERS, level, 0))
        AddOnceEquip(item);
    //??    EQUIPMENT_SLOT_BACK         = 14
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_CLOAK, level, 0))
        AddOnceEquip(item);
    //??    EQUIPMENT_SLOT_CHEST        = 4
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_CHEST, level, 0))
        AddOnceEquip(item);
    else if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_ROBE, level, 0))
        AddOnceEquip(item);
    //??    EQUIPMENT_SLOT_BODY         = 3
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_BODY, level, 0))
        AddOnceEquip(item);
    //??    EQUIPMENT_SLOT_TABARD       = 18
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_TABARD, level, 0))
        AddOnceEquip(item);
    //??    EQUIPMENT_SLOT_WRISTS       = 8
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_WRISTS, level, 0))
        AddOnceEquip(item);
    //?    EQUIPMENT_SLOT_HANDS        = 9
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_HANDS, level, 0))
        AddOnceEquip(item);
    //??    EQUIPMENT_SLOT_WAIST        = 5
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_WAIST, level, 0))
        AddOnceEquip(item);
    //??    EQUIPMENT_SLOT_LEGS         = 6
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_LEGS, level, 0))
        AddOnceEquip(item);
    //?    EQUIPMENT_SLOT_FEET         = 7
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_FEET, level, 0))
        AddOnceEquip(item);
    //??1    EQUIPMENT_SLOT_FINGER1      = 10
    uint32 Finger1 = GetRandomItemFromLoopLV(spec, INVTYPE_FINGER, level, 0);
    if (Finger1)
        AddOnceEquip(Finger1);
    //??2    EQUIPMENT_SLOT_FINGER2      = 11
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_FINGER, level, Finger1))
        AddOnceEquip(item);
    //??1    EQUIPMENT_SLOT_TRINKET1     = 12
    uint32 Trinket1 = GetRandomItemFromLoopLV(spec, INVTYPE_TRINKET, level, 0);
    if (Trinket1)
        AddOnceEquip(Trinket1);
    //??2    EQUIPMENT_SLOT_TRINKET2     = 13
    if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_TRINKET, level, Trinket1))
        AddOnceEquip(item);

    if (level < 100)
    {
        switch (spec)
        {
            //??????
        case 251:
        case 263:
        case 260:
        case 269:
        case 577:
        case 581:
        case 259:
        case 261:
        {
            //?? EQUIPMENT_SLOT_MAINHAND     = 15,
            InventoryType inventoryType = INVTYPE_WEAPON;
            if (roll_chance_i(30))//30???????????
                inventoryType = INVTYPE_WEAPONMAINHAND;

            uint32 MainHand = GetRandomItemFromLoopLV(spec, inventoryType, level, 0);
            if (MainHand)
                AddOnceEquip(MainHand);
            else
            {
                if (MainHand = GetRandomItemFromLoopLV(spec, INVTYPE_WEAPON, level, 0))
                    AddOnceEquip(MainHand);
            }

            //?? EQUIPMENT_SLOT_OFFHAND      = 16,
            inventoryType = INVTYPE_WEAPON;
            if (roll_chance_i(30))//30???????????
                inventoryType = INVTYPE_WEAPONOFFHAND;

            uint32 OffHand = GetRandomItemFromLoopLV(spec, inventoryType, level, 0);
            if (OffHand)
                AddOnceEquip(OffHand);
            else
            {
                if (OffHand = GetRandomItemFromLoopLV(spec, INVTYPE_WEAPON, level, 0))
                    AddOnceEquip(OffHand);
            }
            break;
        }
        //?? ????+??
        case 62:
        case 63:
        case 64:
        case 265:
        case 266:
        case 267:
        case 256:
        case 257:
        case 258:
        case 102:
        case 105:
        case 270:
        {
            bool twohand = roll_chance_i(50);
            if (twohand)//??+??
            {
                //?? EQUIPMENT_SLOT_MAINHAND     = 15,
                InventoryType inventoryType = INVTYPE_WEAPON;
                if (roll_chance_i(30))//30???????????
                    inventoryType = INVTYPE_WEAPONMAINHAND;
                else if (roll_chance_i(10))//10???????????
                    inventoryType = INVTYPE_RANGEDRIGHT;

                uint32 MainHand = GetRandomItemFromLoopLV(spec, inventoryType, level, 0);
                if (MainHand)
                    AddOnceEquip(MainHand);
                else
                {
                    if (MainHand = GetRandomItemFromLoopLV(spec, INVTYPE_WEAPON, level, 0))
                        AddOnceEquip(MainHand);
                }

                if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_HOLDABLE, level, 0))
                    AddOnceEquip(item);
            }
            else
            {
                if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_2HWEAPON, level, 0))
                    AddOnceEquip(item);
            }
            break;
        }
        //??
        case 262:
        case 264:
        case 73:
        case 66:
        case 65:
        {
            //?? EQUIPMENT_SLOT_MAINHAND     = 15,
            InventoryType inventoryType = INVTYPE_WEAPON;
            if (roll_chance_i(30))//30???????????
                inventoryType = INVTYPE_WEAPONMAINHAND;

            uint32 MainHand = GetRandomItemFromLoopLV(spec, inventoryType, level, 0);
            if (MainHand)
                AddOnceEquip(MainHand);
            else
            {
                if (MainHand = GetRandomItemFromLoopLV(spec, INVTYPE_WEAPON, level, 0))
                    AddOnceEquip(MainHand);
            }

            //?? EQUIPMENT_SLOT_OFFHAND      = 16,
            if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_SHIELD, level, 0))
                AddOnceEquip(item);
            break;
        }
        //???? ?? ????  ???, ?, ?  ????+??
        case 70:
        case 71:
        case 250:
        case 252:
        case 103:
        case 104:
        case 268:
        case 255:
        {
            if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_2HWEAPON, level, 0))
                AddOnceEquip(item);
            break;
        }
        //?, ?, ?
        case 253:
        case 254:
        {
            InventoryType inventoryType = INVTYPE_RANGED;
            if (roll_chance_i(50))
                inventoryType = INVTYPE_RANGEDRIGHT;
            if (uint32 item = GetRandomItemFromLoopLV(spec, inventoryType, level, 0))
                AddOnceEquip(item);
            break;
        }
        //?????, ?, ?	
        case 72:
        {
            //?? EQUIPMENT_SLOT_MAINHAND     = 15,
            uint32 MainHand = GetRandomItemFromLoopLV(spec, INVTYPE_2HWEAPON, level, 0);
            if (MainHand)
                AddOnceEquip(MainHand);

            //?? EQUIPMENT_SLOT_OFFHAND      = 16,
            if (uint32 item = GetRandomItemFromLoopLV(spec, INVTYPE_2HWEAPON, level, MainHand))
                AddOnceEquip(item);
            break;
        }
        }
    }
    else//??100 ???
        AddOnceEquip(GetArtifactID(spec));
}

void PlayerBotSetting::EquipAll()
{
    for (auto item : m_NeedEquips)
        EquipItem(item);

    m_NeedEquips.clear();
}

bool PlayerBotSetting::EquipItem(Item* pItem)
{
    uint16 dest;
    InventoryResult msg = m_Player->CanEquipItem(NULL_SLOT, dest, pItem, !pItem->IsBag());
    if (msg != EQUIP_ERR_OK)
    {
        return false;
    }

    uint16 src = pItem->GetPos();
    if (dest == src)                                           // prevent equip in same slot, only at cheat
        return false;

    Item* pDstItem = m_Player->GetItemByPos(dest);

    if (!pDstItem)                                         // empty slot, simple case
    {
        m_Player->RemoveItem(pItem->GetBagSlot(), pItem->GetSlot(), true);

        if (pItem->GetTemplate()->GetArtifactID())
        {
            uint32 noSpaceForCount = 0;
            ItemPosCountVec dest1;
            InventoryResult msg1;

            if (pItem->GetEntry() == 128943)//pItem->GetTemplate()->GetInventoryType() == INVTYPE_WEAPONOFFHAND && 
            {
                msg1 = m_Player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest1, 137246, 1, &noSpaceForCount);

                //   if (Item* _Item = m_Player->StoreNewItem(dest1, 137246, true, GenerateItemRandomPropertyId(137246)))
                   //    m_Player->QuickEquipItem(EQUIPMENT_SLOT_MAINHAND, _Item);

                m_Player->EquipItem(dest, pItem, true);
                return true;
            }
            if (pItem->GetEntry() == 128289)//pItem->GetTemplate()->GetInventoryType() == INVTYPE_SHIELD && 
            {
                msg1 = m_Player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest1, 128288, 1, &noSpaceForCount);

                //  if (Item* _Item = m_Player->StoreNewItem(dest1, 128288, true, GenerateItemRandomPropertyId(128288)))
                   //   m_Player->QuickEquipItem(EQUIPMENT_SLOT_MAINHAND, _Item);

                m_Player->EquipItem(dest, pItem, true);
                return true;
            }
        }

        m_Player->EquipItem(dest, pItem, true);
        m_Player->EquipChildItem(pItem->GetBagSlot(), pItem->GetSlot(), pItem);
        m_Player->AutoUnequipOffhandIfNeed();
    }
    else                                                    // have currently equipped item, not simple case
    {
        uint8 dstbag = pDstItem->GetBagSlot();
        uint8 dstslot = pDstItem->GetSlot();

        msg = m_Player->CanUnequipItem(dest, !pItem->IsBag());
        if (msg != EQUIP_ERR_OK)
        {
            return false;
        }

        // check dest->src move possibility
        ItemPosCountVec sSrc;
        uint16 eSrc = 0;
        if (m_Player->IsInventoryPos(src))
        {
            msg = m_Player->CanStoreItem(pItem->GetBagSlot(), pItem->GetSlot(), sSrc, pDstItem, true);
            if (msg != EQUIP_ERR_OK)
                msg = m_Player->CanStoreItem(pItem->GetBagSlot(), NULL_SLOT, sSrc, pDstItem, true);
            if (msg != EQUIP_ERR_OK)
                msg = m_Player->CanStoreItem(NULL_BAG, NULL_SLOT, sSrc, pDstItem, true);
        }
        else if (m_Player->IsBankPos(src))
        {
            msg = m_Player->CanBankItem(pItem->GetBagSlot(), pItem->GetSlot(), sSrc, pDstItem, true);
            if (msg != EQUIP_ERR_OK)
                msg = m_Player->CanBankItem(pItem->GetBagSlot(), NULL_SLOT, sSrc, pDstItem, true);
            if (msg != EQUIP_ERR_OK)
                msg = m_Player->CanBankItem(NULL_BAG, NULL_SLOT, sSrc, pDstItem, true);
        }
        else if (m_Player->IsEquipmentPos(src))
        {
            msg = m_Player->CanEquipItem(pItem->GetSlot(), eSrc, pDstItem, true);
            if (msg == EQUIP_ERR_OK)
                msg = m_Player->CanUnequipItem(eSrc, true);
        }

        if (msg != EQUIP_ERR_OK)
        {
            return false;
        }

        // now do moves, remove...
        m_Player->RemoveItem(dstbag, dstslot, false);
        m_Player->RemoveItem(pItem->GetBagSlot(), pItem->GetSlot(), false);



        // add to dest
        m_Player->EquipItem(dest, pItem, true);
        m_Player->EquipChildItem(pItem->GetBagSlot(), pItem->GetSlot(), pItem);

        // add to src
        if (m_Player->IsInventoryPos(src))
            m_Player->StoreItem(sSrc, pDstItem, true);
        else if (m_Player->IsBankPos(src))
            m_Player->BankItem(sSrc, pDstItem, true);
        else if (m_Player->IsEquipmentPos(src))
            m_Player->EquipItem(eSrc, pDstItem, true);

        m_Player->AutoUnequipOffhandIfNeed();
    }
    return true;
}

void PlayerBotSetting::LearnRandomTalentSpell(uint32 level, uint32 spell1, uint32 spell2, uint32 spell3)
{
    if (m_Player->getLevel() < level)
        return;

    std::vector<uint32> triggeredSpells = { spell1, spell2, spell3 };
    uint32 spellId = Trinity::Containers::SelectRandomContainerElement(triggeredSpells);

    if (spellId == 0)
        return;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
    if (!spellInfo || spellInfo->SpellLevel > m_Player->getLevel())
        return;

    for (auto _spell : triggeredSpells)
        m_Player->RemoveSpell(_spell, true);

    if (!m_Player->HasSpell(spellId))
        m_Player->LearnSpell(spellId, false);
}

uint32 PlayerBotSetting::GetRandomItemFromLoopLV(uint32 spec, InventoryType iType, uint32 startLV, uint32 filter)
{
    auto ivi = InvLevelItemsBySpec[spec];
    if (!ivi)
        return 0;

    for (int i = startLV; i > 0; i--)
    {
        if (ivi->items[i][iType].empty())
            continue;

        auto items = ivi->items[i][iType];
        for (int j = 0; j < items.size(); j++)
        {
            uint32 item = items[urand(0, items.size() - 1)];
            if (item && item != filter && m_Player && item < 280000)
            {
                if (startLV <= 20)
                    if (auto proto = sObjectMgr->GetItemTemplate(item))
                        if (proto->GetBaseItemLevel() > 30 && proto->GetQuality() > 1)
                            continue;

                //uint16 eDest;
                // Item* pItem = Item::CreateItem(item, 1, m_Player);
               //  if (pItem)
                // {
                 //    if (m_Player->CanEquipItem(NULL_SLOT, eDest, pItem, false, false) == EQUIP_ERR_OK)
                  //   {
                   //      delete pItem;
                    //     return item;
                   //  }
                  //   delete pItem;
               //  }
            }
        }
    }

    //printf("spec=%u, itype=%u, startlv=%u, filter=%u\n", spec, iType, startLV, filter);
    return 0;
}

bool PlayerBotSetting::EquipIsTidiness()
{
    uint8 level = m_Player->getLevel();
    uint32 noMatchEquipCount = 0;
    for (uint8 slot = EQUIPMENT_SLOT_HEAD; slot < EQUIPMENT_SLOT_END; slot++)
    {
        Item* pItem = m_Player->GetItemByPos(255, slot);
        if (!pItem)
        {
            ++noMatchEquipCount;
            if (level <= 20)
            {
                if (noMatchEquipCount > 10)
                    return false;
            }
            else if (noMatchEquipCount >= 5)
                return false;
            continue;
        }
    }
    return true;
}

void PlayerBotSetting::AddOnceEquip(uint32 id)
{
    if (!id)
        return;

    Item* item = nullptr;
    if (item = m_Player->GetItemByEntry(id))
    {
        if (!item->IsEquipped())
            m_NeedEquips.push_back(item);
        return;
    }

    uint32 count = 1;
    uint32 noSpaceForCount = 0;
    ItemPosCountVec dest;
    InventoryResult msg = m_Player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, id, count, &noSpaceForCount);
    if (msg != EQUIP_ERR_OK)
        count -= noSpaceForCount;
    if (count <= 0 || dest.empty())
        return;

    //  if (item = m_Player->StoreNewItem(dest, id, true, GenerateItemRandomPropertyId(id)))
      //    m_NeedEquips.push_back(item);		
}

