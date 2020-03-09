#include "RobotManager.h"

#include "Log.h"
#include "AccountMgr.h"
#include "Player.h"
#include "Pet.h"
#include "WorldSession.h"
#include "ObjectMgr.h"
#include "MotionMaster.h"
#include "MapManager.h"
#include "Group.h"
#include "Item.h"
#include "World.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "RobotConfig.h"
#include "CharacterCache.h"
#include "CreatureAI.h"
#include "InstanceScript.h"

RobotManager::RobotManager()
{
    nameIndex = 0;
    prepareCheckDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
    prepareStrategyMap.clear();
    soloStrategyMap.clear();
    partyStrategyMap.clear();
    raidStrategyMap.clear();

    deleteRobotAccountSet.clear();
    meleeWeaponMap.clear();
    rangeWeaponMap.clear();
    armorMap.clear();
    miscMap.clear();
    teleportCacheMap.clear();
    tamableBeastEntryMap.clear();
    spellNameEntryMap.clear();
}

void RobotManager::InitializeManager()
{
    if (sRobotConfig->Enable == 0)
    {
        return;
    }

    if (sRobotConfig->ResetRobots == 1)
    {
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Reset robots");
        if (DeleteRobots())
        {
            sWorld->ShutdownServ(10, SHUTDOWN_MASK_RESTART | SHUTDOWN_MASK_IDLE, RESTART_EXIT_CODE);
            return;
        }
    }

    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Initialize robot manager");

    QueryResult robotNamesQR = WorldDatabase.Query("SELECT name FROM robot_names order by rand()");
    if (!robotNamesQR)
    {
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "Found zero robot names");
        sRobotConfig->Enable = false;
        return;
    }
    do
    {
        Field* fields = robotNamesQR->Fetch();
        std::string eachName = fields[0].GetString();
        robotNameMap[robotNameMap.size()] = eachName;
    } while (robotNamesQR->NextRow());

    availableRaces[CLASS_WARRIOR][availableRaces[CLASS_WARRIOR].size()] = RACE_HUMAN;
    availableRaces[CLASS_WARRIOR][availableRaces[CLASS_WARRIOR].size()] = RACE_NIGHTELF;
    availableRaces[CLASS_WARRIOR][availableRaces[CLASS_WARRIOR].size()] = RACE_GNOME;
    availableRaces[CLASS_WARRIOR][availableRaces[CLASS_WARRIOR].size()] = RACE_DWARF;
    availableRaces[CLASS_WARRIOR][availableRaces[CLASS_WARRIOR].size()] = RACE_ORC;
    availableRaces[CLASS_WARRIOR][availableRaces[CLASS_WARRIOR].size()] = RACE_UNDEAD_PLAYER;
    availableRaces[CLASS_WARRIOR][availableRaces[CLASS_WARRIOR].size()] = RACE_TAUREN;
    availableRaces[CLASS_WARRIOR][availableRaces[CLASS_WARRIOR].size()] = RACE_TROLL;
    availableRaces[CLASS_WARRIOR][availableRaces[CLASS_WARRIOR].size()] = Races::RACE_DRAENEI;

    availableRaces[CLASS_PALADIN][availableRaces[CLASS_PALADIN].size()] = RACE_HUMAN;
    availableRaces[CLASS_PALADIN][availableRaces[CLASS_PALADIN].size()] = RACE_DWARF;
    availableRaces[CLASS_PALADIN][availableRaces[CLASS_PALADIN].size()] = Races::RACE_DRAENEI;
    availableRaces[CLASS_PALADIN][availableRaces[CLASS_PALADIN].size()] = Races::RACE_BLOODELF;

    availableRaces[CLASS_ROGUE][availableRaces[CLASS_ROGUE].size()] = RACE_HUMAN;
    availableRaces[CLASS_ROGUE][availableRaces[CLASS_ROGUE].size()] = RACE_DWARF;
    availableRaces[CLASS_ROGUE][availableRaces[CLASS_ROGUE].size()] = RACE_NIGHTELF;
    availableRaces[CLASS_ROGUE][availableRaces[CLASS_ROGUE].size()] = RACE_GNOME;
    availableRaces[CLASS_ROGUE][availableRaces[CLASS_ROGUE].size()] = RACE_ORC;
    availableRaces[CLASS_ROGUE][availableRaces[CLASS_ROGUE].size()] = RACE_TROLL;
    availableRaces[CLASS_ROGUE][availableRaces[CLASS_ROGUE].size()] = Races::RACE_BLOODELF;

    availableRaces[CLASS_PRIEST][availableRaces[CLASS_PRIEST].size()] = RACE_HUMAN;
    availableRaces[CLASS_PRIEST][availableRaces[CLASS_PRIEST].size()] = RACE_DWARF;
    availableRaces[CLASS_PRIEST][availableRaces[CLASS_PRIEST].size()] = RACE_NIGHTELF;
    availableRaces[CLASS_PRIEST][availableRaces[CLASS_PRIEST].size()] = RACE_TROLL;
    availableRaces[CLASS_PRIEST][availableRaces[CLASS_PRIEST].size()] = RACE_UNDEAD_PLAYER;
    availableRaces[CLASS_PRIEST][availableRaces[CLASS_PRIEST].size()] = Races::RACE_DRAENEI;
    availableRaces[CLASS_PRIEST][availableRaces[CLASS_PRIEST].size()] = Races::RACE_BLOODELF;

    availableRaces[CLASS_MAGE][availableRaces[CLASS_MAGE].size()] = RACE_HUMAN;
    availableRaces[CLASS_MAGE][availableRaces[CLASS_MAGE].size()] = RACE_GNOME;
    availableRaces[CLASS_MAGE][availableRaces[CLASS_MAGE].size()] = RACE_UNDEAD_PLAYER;
    availableRaces[CLASS_MAGE][availableRaces[CLASS_MAGE].size()] = RACE_TROLL;
    availableRaces[CLASS_MAGE][availableRaces[CLASS_MAGE].size()] = Races::RACE_DRAENEI;
    availableRaces[CLASS_MAGE][availableRaces[CLASS_MAGE].size()] = Races::RACE_BLOODELF;

    availableRaces[CLASS_WARLOCK][availableRaces[CLASS_WARLOCK].size()] = RACE_HUMAN;
    availableRaces[CLASS_WARLOCK][availableRaces[CLASS_WARLOCK].size()] = RACE_GNOME;
    availableRaces[CLASS_WARLOCK][availableRaces[CLASS_WARLOCK].size()] = RACE_UNDEAD_PLAYER;
    availableRaces[CLASS_WARLOCK][availableRaces[CLASS_WARLOCK].size()] = RACE_ORC;
    availableRaces[CLASS_WARLOCK][availableRaces[CLASS_WARLOCK].size()] = Races::RACE_BLOODELF;

    availableRaces[CLASS_SHAMAN][availableRaces[CLASS_SHAMAN].size()] = RACE_ORC;
    availableRaces[CLASS_SHAMAN][availableRaces[CLASS_SHAMAN].size()] = RACE_TAUREN;
    availableRaces[CLASS_SHAMAN][availableRaces[CLASS_SHAMAN].size()] = RACE_TROLL;
    availableRaces[CLASS_SHAMAN][availableRaces[CLASS_SHAMAN].size()] = Races::RACE_DRAENEI;

    availableRaces[CLASS_HUNTER][availableRaces[CLASS_HUNTER].size()] = RACE_DWARF;
    availableRaces[CLASS_HUNTER][availableRaces[CLASS_HUNTER].size()] = RACE_NIGHTELF;
    availableRaces[CLASS_HUNTER][availableRaces[CLASS_HUNTER].size()] = RACE_ORC;
    availableRaces[CLASS_HUNTER][availableRaces[CLASS_HUNTER].size()] = RACE_TAUREN;
    availableRaces[CLASS_HUNTER][availableRaces[CLASS_HUNTER].size()] = RACE_TROLL;
    availableRaces[CLASS_HUNTER][availableRaces[CLASS_HUNTER].size()] = Races::RACE_DRAENEI;
    availableRaces[CLASS_HUNTER][availableRaces[CLASS_HUNTER].size()] = Races::RACE_BLOODELF;

    availableRaces[CLASS_DRUID][availableRaces[CLASS_DRUID].size()] = RACE_NIGHTELF;
    availableRaces[CLASS_DRUID][availableRaces[CLASS_DRUID].size()] = RACE_TAUREN;


    armorInventorySet.insert(InventoryType::INVTYPE_CHEST);
    armorInventorySet.insert(InventoryType::INVTYPE_FEET);
    armorInventorySet.insert(InventoryType::INVTYPE_HANDS);
    armorInventorySet.insert(InventoryType::INVTYPE_HEAD);
    armorInventorySet.insert(InventoryType::INVTYPE_LEGS);
    armorInventorySet.insert(InventoryType::INVTYPE_SHOULDERS);
    armorInventorySet.insert(InventoryType::INVTYPE_WAIST);
    armorInventorySet.insert(InventoryType::INVTYPE_WRISTS);

    miscInventoryMap[0] = InventoryType::INVTYPE_CLOAK;
    miscInventoryMap[1] = InventoryType::INVTYPE_FINGER;
    miscInventoryMap[2] = InventoryType::INVTYPE_FINGER;
    miscInventoryMap[3] = InventoryType::INVTYPE_NECK;

    characterTalentTabNameMap.clear();
    characterTalentTabNameMap[Classes::CLASS_WARRIOR][0] = "Arms";
    characterTalentTabNameMap[Classes::CLASS_WARRIOR][1] = "Fury";
    characterTalentTabNameMap[Classes::CLASS_WARRIOR][2] = "Protection";

    characterTalentTabNameMap[Classes::CLASS_HUNTER][0] = "Beast Mastery";
    characterTalentTabNameMap[Classes::CLASS_HUNTER][1] = "Marksmanship";
    characterTalentTabNameMap[Classes::CLASS_HUNTER][2] = "Survival";

    characterTalentTabNameMap[Classes::CLASS_SHAMAN][0] = "Elemental";
    characterTalentTabNameMap[Classes::CLASS_SHAMAN][1] = "Enhancement";
    characterTalentTabNameMap[Classes::CLASS_SHAMAN][2] = "Restoration";

    characterTalentTabNameMap[Classes::CLASS_PALADIN][0] = "Holy";
    characterTalentTabNameMap[Classes::CLASS_PALADIN][1] = "Protection";
    characterTalentTabNameMap[Classes::CLASS_PALADIN][2] = "Retribution";

    characterTalentTabNameMap[Classes::CLASS_WARLOCK][0] = "Affliction";
    characterTalentTabNameMap[Classes::CLASS_WARLOCK][1] = "Demonology";
    characterTalentTabNameMap[Classes::CLASS_WARLOCK][2] = "Destruction";

    characterTalentTabNameMap[Classes::CLASS_PRIEST][0] = "Descipline";
    characterTalentTabNameMap[Classes::CLASS_PRIEST][1] = "Holy";
    characterTalentTabNameMap[Classes::CLASS_PRIEST][2] = "Shadow";

    characterTalentTabNameMap[Classes::CLASS_ROGUE][0] = "Assassination";
    characterTalentTabNameMap[Classes::CLASS_ROGUE][1] = "Combat";
    characterTalentTabNameMap[Classes::CLASS_ROGUE][2] = "subtlety";

    characterTalentTabNameMap[Classes::CLASS_MAGE][0] = "Arcane";
    characterTalentTabNameMap[Classes::CLASS_MAGE][1] = "Fire";
    characterTalentTabNameMap[Classes::CLASS_MAGE][2] = "Frost";

    characterTalentTabNameMap[Classes::CLASS_DRUID][0] = "Balance";
    characterTalentTabNameMap[Classes::CLASS_DRUID][1] = "Feral";
    characterTalentTabNameMap[Classes::CLASS_DRUID][2] = "Restoration";

    // equips from loot
    std::unordered_set<uint32> rlSet;
    rlSet.clear();
    QueryResult rlQR = WorldDatabase.Query("SELECT distinct Item FROM reference_loot_template");
    if (rlQR)
    {
        do
        {
            Field* rlField = rlQR->Fetch();
            uint32 eachLootItemEntry = rlField[0].GetUInt32();
            rlSet.insert(eachLootItemEntry);
        } while (rlQR->NextRow());
    }
    // equips from quest
    std::unordered_map<uint32, int32> qrMap;
    qrMap.clear();
    std::unordered_map<uint32, Quest> allQuestMapForEquips = sObjectMgr->GetQuestTemplates();
    for (std::unordered_map<uint32, Quest>::iterator it = allQuestMapForEquips.begin(); it != allQuestMapForEquips.end(); it++)
    {
        if (it->second.GetQuestLevel() < 10)
        {
            continue;
        }
        for (int ciCount = 0; ciCount < 6; ciCount++)
        {
            if (it->second.RewardChoiceItemId[ciCount] > 0)
            {
                qrMap[it->second.RewardChoiceItemId[ciCount]] = it->second.GetQuestLevel();
            }
        }
    }

    uint8 levelRange = 0;
    ItemTemplateContainer const& its = sObjectMgr->GetItemTemplateStore();
    for (auto const& itemTemplatePair : its)
    {
        levelRange = 0;
        if (rlSet.find(itemTemplatePair.first) != rlSet.end())
        {

        }
        else if (qrMap.find(itemTemplatePair.first) != qrMap.end())
        {
            levelRange = qrMap[itemTemplatePair.first] / 10;
        }
        else
        {
            continue;
        }
        const ItemTemplate* proto = &itemTemplatePair.second;
        if (!proto)
        {
            continue;
        }
        if (proto->Quality < 1)
        {
            continue;
        }
        if (proto->RandomSuffix > 0)
        {
            continue;
        }
        if (levelRange == 0)
        {
            levelRange = proto->RequiredLevel / 10;
        }
        if (proto->InventoryType == InventoryType::INVTYPE_CLOAK || proto->InventoryType == InventoryType::INVTYPE_FINGER || proto->InventoryType == InventoryType::INVTYPE_NECK)
        {
            miscMap[proto->InventoryType][levelRange][miscMap[proto->InventoryType][levelRange].size()] = proto->ItemId;
            continue;
        }
        if (proto->Class == ItemClass::ITEM_CLASS_WEAPON)
        {
            switch (proto->SubClass)
            {
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_STAFF:
            {
                meleeWeaponMap[0][levelRange][meleeWeaponMap[0][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_SWORD:
            {
                meleeWeaponMap[1][levelRange][meleeWeaponMap[1][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_SWORD2:
            {
                meleeWeaponMap[2][levelRange][meleeWeaponMap[2][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_MACE:
            {
                meleeWeaponMap[3][levelRange][meleeWeaponMap[3][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_MACE2:
            {
                meleeWeaponMap[4][levelRange][meleeWeaponMap[4][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_AXE2:
            {
                meleeWeaponMap[5][levelRange][meleeWeaponMap[5][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_DAGGER:
            {
                meleeWeaponMap[6][levelRange][meleeWeaponMap[6][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_BOW:
            {
                rangeWeaponMap[0][levelRange][rangeWeaponMap[0][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_CROSSBOW:
            {
                rangeWeaponMap[0][levelRange][rangeWeaponMap[0][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_GUN:
            {
                rangeWeaponMap[0][levelRange][rangeWeaponMap[0][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_WAND:
            {
                rangeWeaponMap[1][levelRange][rangeWeaponMap[1][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_THROWN:
            {
                rangeWeaponMap[2][levelRange][rangeWeaponMap[2][levelRange].size()] = proto->ItemId;
                continue;
            }
            default:
            {
                break;
            }
            }
        }
        else if (proto->Class == ItemClass::ITEM_CLASS_ARMOR)
        {
            switch (proto->SubClass)
            {
            case ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_CLOTH:
            {
                armorMap[0][proto->InventoryType][levelRange][armorMap[0][proto->InventoryType][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_LEATHER:
            {
                armorMap[1][proto->InventoryType][levelRange][armorMap[1][proto->InventoryType][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_MAIL:
            {
                armorMap[2][proto->InventoryType][levelRange][armorMap[2][proto->InventoryType][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_PLATE:
            {
                armorMap[3][proto->InventoryType][levelRange][armorMap[3][proto->InventoryType][levelRange].size()] = proto->ItemId;
                continue;
            }
            case ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_SHIELD:
            {
                meleeWeaponMap[7][levelRange][meleeWeaponMap[7][levelRange].size()] = proto->ItemId;
                continue;
            }
            default:
            {
                break;
            }
            }
        }
    }

    spellRewardClassQuestIDSet.clear();
    std::unordered_map<uint32, Quest> allQuestMap = sObjectMgr->GetQuestTemplates();
    for (std::unordered_map<uint32, Quest>::iterator it = allQuestMap.begin(); it != allQuestMap.end(); it++)
    {
        if (it->second.GetRequiredClasses() > 0)
        {
            if (it->second.GetRewSpellCast() > 0)
            {
                spellRewardClassQuestIDSet.insert(it->first);
            }
        }
    }

    QueryResult normalCreatureQR = WorldDatabase.Query("SELECT CT.maxlevel, C.map, C.position_x, C.position_y, C.position_z FROM creature_template CT join creature C on CT.entry = C.id where CT.rank = 0 and (C.map <> 0 or C.map <> 1 or C.map <> 530 or C.map <> 571)");
    if (normalCreatureQR)
    {
        do
        {
            Field* creatureField = normalCreatureQR->Fetch();
            uint8 level = creatureField[0].GetUInt8();
            level = level / 10;
            int mapID = creatureField[1].GetInt32();
            float x = creatureField[2].GetFloat();
            float y = creatureField[3].GetFloat();
            float z = creatureField[4].GetFloat();
            WorldLocation eachWL = WorldLocation(mapID, x, y, z, 0);
            teleportCacheMap[level][teleportCacheMap[level].size()] = eachWL;
        } while (normalCreatureQR->NextRow());
    }

    CreatureTemplateContainer const& ctc = sObjectMgr->GetCreatureTemplates();
    for (auto const& creatureTemplatePair : ctc)
    {
        const CreatureTemplate* cInfo = &creatureTemplatePair.second;
        if (!cInfo)
        {
            continue;
        }
        if (cInfo->IsTameable(false))
        {
            tamableBeastEntryMap[tamableBeastEntryMap.size()] = cInfo->Entry;
        }
    }

    SpellInfoMap const& sim = sSpellMgr->GetSpellInfoStore();
    for (auto const& eachSI : sim)
    {
        if (eachSI)
        {
            spellNameEntryMap[eachSI->SpellName[0]].insert(eachSI->Id);
        }
    }

    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot system ready");
}

RobotManager* RobotManager::instance()
{
    static RobotManager instance;
    return &instance;
}

void RobotManager::UpdateRobotManager()
{
    if (sRobotConfig->Enable == 0)
    {
        return;
    }

    uint32 realCurrTime = getMSTime();
    uint32 diff = getMSTimeDiff(realPrevTime, realCurrTime);
    realPrevTime = realCurrTime;

    prepareCheckDelay -= diff;
    if (prepareCheckDelay < 0)
    {
        prepareCheckDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
        std::unordered_set<uint32> onlinePlayerLevelSet;
        for (std::unordered_map<uint32, WorldSession*>::const_iterator wsIT = sWorld->GetAllSessions().begin(); wsIT != sWorld->GetAllSessions().end(); wsIT++)
        {
            if (robotMap.find(wsIT->first) == robotMap.end())
            {
                if (Player* eachPlayer = wsIT->second->GetPlayer())
                {
                    if (eachPlayer->GetLevel() < 20)
                    {
                        continue;
                    }
                    if (onlinePlayerLevelSet.find(eachPlayer->GetLevel()) == onlinePlayerLevelSet.end())
                    {
                        onlinePlayerLevelSet.insert(eachPlayer->GetLevel());
                    }
                }
            }
        }

        for (std::unordered_set<uint32>::iterator levelIT = onlinePlayerLevelSet.begin(); levelIT != onlinePlayerLevelSet.end(); levelIT++)
        {
            uint32 prepareCount = 0;
            for (std::unordered_map<uint32, Strategy_Prepare*>::iterator spIT = prepareStrategyMap.begin(); spIT != prepareStrategyMap.end(); spIT++)
            {
                if (spIT->second->targetLevel == *levelIT)
                {
                    if (spIT->second->prepareState == RobotPrepareState::RobotPrepareState_OffLine)
                    {
                        spIT->second->actionDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 15 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
                    }
                    prepareCount++;
                }
            }
            if (sRobotConfig->RobotCountEachLevel > prepareCount)
            {
                uint32 toAdd = sRobotConfig->RobotCountEachLevel - prepareCount;
                uint32 checkCount = 0;
                while (checkCount < toAdd)
                {
                    Strategy_Prepare* sp = new Strategy_Prepare();
                    sp->targetLevel = *levelIT;
                    while (true)
                    {
                        sp->targetClass = urand(Classes::CLASS_WARRIOR, Classes::CLASS_DRUID);
                        if (sp->targetClass != 6 && sp->targetClass != 10 && sp->targetClass != Classes::CLASS_WARRIOR && sp->targetClass != Classes::CLASS_ROGUE && sp->targetClass != Classes::CLASS_SHAMAN && sp->targetClass != Classes::CLASS_MAGE)
                        {
                            break;
                        }
                    }
                    uint32 raceIndex = urand(0, availableRaces[sp->targetClass].size() - 1);
                    sp->targetRace = availableRaces[sp->targetClass][raceIndex];
                }
            }
        }
    }

    for (std::unordered_map<uint32, Strategy_Solo*>::iterator ssIT = soloStrategyMap.begin(); ssIT != soloStrategyMap.end(); ssIT++)
    {
        ssIT->second->Update();
    }

    for (std::unordered_map<uint32, Strategy_Party*>::iterator spIT = partyStrategyMap.begin(); spIT != partyStrategyMap.end(); spIT++)
    {
        spIT->second->Update();
    }

    for (std::unordered_map<uint32, Strategy_Raid*>::iterator srIT = raidStrategyMap.begin(); srIT != raidStrategyMap.end(); srIT++)
    {
        srIT->second->Update();
    }
}

bool RobotManager::DeleteRobots()
{
    QueryResult accountQR = LoginDatabase.PQuery("SELECT id, username FROM account where username like '%s%%'", sRobotConfig->RobotAccountNamePrefix.c_str());

    if (accountQR)
    {
        do
        {
            Field* fields = accountQR->Fetch();
            uint32 id = fields[0].GetUInt32();
            std::string userName = fields[1].GetString();
            deleteRobotAccountSet.insert(id);
            sAccountMgr->DeleteAccount(id);
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Delete robot account %d - %s", id, userName.c_str());
        } while (accountQR->NextRow());
        return true;
    }

    return false;
}

bool RobotManager::RobotsDeleted()
{
    for (std::set<uint32>::iterator it = deleteRobotAccountSet.begin(); it != deleteRobotAccountSet.end(); it++)
    {
        QueryResult accountQR = LoginDatabase.PQuery("SELECT id FROM account where id = '%d'", (*it));
        if (accountQR)
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Account %d is under deleting", (*it));
            return false;
        }
        QueryResult characterQR = CharacterDatabase.PQuery("SELECT count(*) FROM characters where account = '%d'", (*it));
        if (characterQR)
        {
            Field* fields = characterQR->Fetch();
            uint32 count = fields[0].GetUInt32();
            if (count > 0)
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Characters for account %d are under deleting", (*it));
                return false;
            }
        }
    }

    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot accounts are deleted");
    return true;
}

bool RobotManager::CheckRobotAccount(uint32 pmAccountID)
{
    QueryResult accountQR = LoginDatabase.PQuery("SELECT id FROM account where id = '%d'", pmAccountID);
    if (accountQR)
    {
        return true;
    }
    return false;
}

uint32 RobotManager::CheckRobotAccount(std::string pmAccountName)
{
    uint32 accountID = 0;

    QueryResult accountQR = LoginDatabase.PQuery("SELECT id FROM account where username = '%s'", pmAccountName.c_str());
    if (accountQR)
    {
        Field* idFields = accountQR->Fetch();
        accountID = idFields[0].GetUInt32();
    }
    return accountID;
}

uint32 RobotManager::CreateRobotAccount()
{
    uint32 result = 0;

    uint32 checkIndex = 0;
    while (true)
    {
        std::ostringstream accountNameStream;
        accountNameStream << sRobotConfig->RobotAccountNamePrefix << checkIndex;
        AccountOpResult aor = sAccountMgr->CreateAccount(accountNameStream.str(), ROBOT_PASSWORD);
        if (aor == AccountOpResult::AOR_NAME_ALREADY_EXIST)
        {
            checkIndex++;
        }
        else if (aor == AccountOpResult::AOR_OK)
        {
            result = CheckRobotAccount(accountNameStream.str());
        }
        else
        {
            break;
        }
    }

    return result;
}

uint32 RobotManager::CheckAccountCharacter(uint32 pmAccountID)
{
    uint32 result = 0;

    QueryResult characterQR = CharacterDatabase.PQuery("SELECT guid FROM characters where account = '%d'", pmAccountID);
    if (characterQR)
    {
        Field* characterFields = characterQR->Fetch();
        result = characterFields[0].GetUInt32();
    }
    return result;
}

uint32 RobotManager::CreateRobotCharacter(uint32 pmAccountID, uint32 pmCharacterClass, uint32 pmCharacterRace)
{
    uint32 result = 0;

    std::string currentName = "";
    bool nameValid = false;
    while (nameIndex < robotNameMap.size())
    {
        currentName = robotNameMap[nameIndex];
        QueryResult checkNameQR = CharacterDatabase.PQuery("SELECT count(*) FROM characters where name = '%s'", currentName.c_str());

        if (!checkNameQR)
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Name %s is available", currentName.c_str());
            nameValid = true;
        }
        else
        {
            Field* nameCountFields = checkNameQR->Fetch();
            uint32 nameCount = nameCountFields[0].GetUInt32();
            if (nameCount == 0)
            {
                nameValid = true;
            }
        }
        nameIndex++;
        if (nameValid)
        {
            break;
        }
    }
    if (!nameValid)
    {
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "No available names");
        return false;
    }

    uint8 gender = 0, skin = 0, face = 0, hairStyle = 0, hairColor = 0, facialHair = 0;
    while (true)
    {
        gender = urand(0, 1);
        face = urand(0, 5);
        hairStyle = urand(0, 5);
        hairColor = urand(0, 5);
        facialHair = urand(0, 5);

        CharacterCreateInfo* cci = new CharacterCreateInfo();
        cci->Name = currentName;
        cci->Race = pmCharacterRace;
        cci->Class = pmCharacterClass;
        cci->Gender = gender;
        cci->Skin = skin;
        cci->Face = face;
        cci->HairStyle = hairStyle;
        cci->HairColor = hairColor;
        cci->FacialHair = facialHair;
        cci->OutfitId = 0;

        WorldSession* eachSession = new WorldSession(pmAccountID, "robot", NULL, SEC_PLAYER, 2, 0, LOCALE_enUS, 0, false);
        Player* newPlayer = new Player(eachSession);
        if (!newPlayer->Create(sObjectMgr->GetGenerator<HighGuid::Player>().Generate(), cci))
        {
            newPlayer->CleanupsBeforeDelete();
            delete eachSession;
            delete newPlayer;
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "Character create failed, %s %d %d", currentName.c_str(), pmCharacterRace, pmCharacterClass);
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Try again");
            continue;
        }
        newPlayer->GetMotionMaster()->Initialize();
        newPlayer->setCinematic(2);
        newPlayer->SetAtLoginFlag(AT_LOGIN_NONE);
        newPlayer->SetPvP(true);
        newPlayer->SaveToDB(true);
        result = newPlayer->GetGUID().GetRawValue();
        sWorld->AddSession(eachSession);
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Create character %d - %s for account %d", newPlayer->GetGUID().GetCounter(), currentName.c_str(), pmAccountID);
        break;
    }

    return result;
}

Player* RobotManager::CheckLogin(uint32 pmAccountID, uint32 pmCharacterID)
{
    ObjectGuid guid = ObjectGuid(HighGuid::Player, pmCharacterID);
    Player* currentPlayer = ObjectAccessor::FindConnectedPlayer(guid);
    if (currentPlayer)
    {
        return currentPlayer;
    }
    return NULL;
}

bool RobotManager::LoginRobot(uint32 pmAccountID, uint32 pmCharacterID)
{
    Player* currentPlayer = ObjectAccessor::FindPlayerByLowGUID(pmCharacterID);
    if (currentPlayer)
    {
        if (currentPlayer->IsInWorld())
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot %d %s is already in world", pmCharacterID, currentPlayer->GetName());
            return false;
        }
    }
    QueryResult characterQR = CharacterDatabase.PQuery("SELECT name, level FROM characters where guid = '%d'", pmCharacterID);
    if (!characterQR)
    {
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "Found zero robot characters for account %d while processing logging in", pmAccountID);
        return false;
    }
    Field* characterFields = characterQR->Fetch();
    std::string characterName = characterFields[0].GetString();
    uint8 characterLevel = characterFields[1].GetUInt8();
    WorldSession* loginSession = sWorld->FindSession(pmAccountID);
    if (!loginSession)
    {
        loginSession = new WorldSession(pmAccountID, "robot", NULL, SEC_PLAYER, 2, 0, LOCALE_enUS, 0, false);
        sWorld->AddSession(loginSession);
    }

    loginSession->HandlePlayerLogin_Simple(pmCharacterID);
    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Log in character %d %s (level %d)", pmCharacterID, characterName.c_str(), characterLevel);

    return true;
}

void RobotManager::LogoutRobots()
{
    for (std::unordered_map<uint32, RobotEntity*>::iterator reIT = robotMap.begin(); reIT != robotMap.end(); reIT++)
    {
        Player* checkP = ObjectAccessor::FindConnectedPlayer(reIT->second->characterGUID);
        if (checkP)
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Log out robot %s", checkP->GetName());
            std::ostringstream msgStream;
            msgStream << checkP->GetName() << " logged out";
            sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, msgStream.str().c_str());
            WorldSession* checkWS = checkP->GetSession();
            if (checkWS)
            {
                checkWS->LogoutPlayer(true);
            }
        }
    }
}

void RobotManager::HandlePlayerSay(Player* pmPlayer, std::string pmContent)
{
    std::vector<std::string> commandVector = SplitString(pmContent, " ", true);
    std::string commandName = commandVector.at(0);
    if (commandName == "role")
    {
        std::ostringstream replyStream;
        uint32 checkRole = 0;
        if (Group* checkGroup = pmPlayer->GetGroup())
        {
            if (checkGroup->isRaidGroup())
            {
                //if (sRobotManager->raidStrategyMap.find(checkGroup->GetLowGUID()) != sRobotManager->raidStrategyMap.end())
                //{
                //    if (sRobotManager->raidStrategyMap[checkGroup->GetLowGUID()]->memberMap.find(pmPlayer->GetGUID().GetCounter()) != sRobotManager->raidStrategyMap[checkGroup->GetLowGUID()]->memberMap.end())
                //    {
                //        checkRole = sRobotManager->raidStrategyMap[checkGroup->GetLowGUID()]->memberMap[pmPlayer->GetGUID().GetCounter()]->partyRole;
                //    }
                //}
            }
            else
            {
                if (sRobotManager->partyStrategyMap.find(checkGroup->GetLowGUID()) != sRobotManager->partyStrategyMap.end())
                {
                    if (sRobotManager->partyStrategyMap[checkGroup->GetLowGUID()]->memberMap.find(pmPlayer->GetGUID().GetCounter()) != sRobotManager->partyStrategyMap[checkGroup->GetLowGUID()]->memberMap.end())
                    {
                        checkRole = sRobotManager->partyStrategyMap[checkGroup->GetLowGUID()]->memberMap[pmPlayer->GetGUID().GetCounter()]->partyRole;
                    }
                }
            }
        }
        if (commandVector.size() > 1)
        {
            std::string newRole = commandVector.at(1);
            if (newRole == "dps")
            {
                checkRole = PartyRole::PartyRole_DPS;
            }
            else if (newRole == "tank")
            {
                checkRole = PartyRole::PartyRole_Tank;
            }
            else if (newRole == "healer")
            {
                checkRole = PartyRole::PartyRole_Healer;
            }
            if (Group* checkGroup = pmPlayer->GetGroup())
            {
                if (checkGroup->isRaidGroup())
                {
                    //if (sRobotManager->raidStrategyMap.find(checkGroup->GetLowGUID()) != sRobotManager->raidStrategyMap.end())
                    //{
                    //    if (sRobotManager->raidStrategyMap[checkGroup->GetLowGUID()]->memberMap.find(pmPlayer->GetGUID().GetCounter()) != sRobotManager->raidStrategyMap[checkGroup->GetLowGUID()]->memberMap.end())
                    //    {
                    //        checkRole = sRobotManager->raidStrategyMap[checkGroup->GetLowGUID()]->memberMap[pmPlayer->GetGUID().GetCounter()]->partyRole;
                    //    }
                    //}
                }
                else
                {
                    if (sRobotManager->partyStrategyMap.find(checkGroup->GetLowGUID()) != sRobotManager->partyStrategyMap.end())
                    {
                        if (sRobotManager->partyStrategyMap[checkGroup->GetLowGUID()]->memberMap.find(pmPlayer->GetGUID().GetCounter()) != sRobotManager->partyStrategyMap[checkGroup->GetLowGUID()]->memberMap.end())
                        {
                            sRobotManager->partyStrategyMap[checkGroup->GetLowGUID()]->memberMap[pmPlayer->GetGUID().GetCounter()]->partyRole = checkRole;
                        }
                    }
                }
            }
        }

        replyStream << "Your group role is ";
        switch (checkRole)
        {
        case 0:
        {
            replyStream << "dps";
            break;
        }
        case 1:
        {
            replyStream << "tank";
            break;
        }
        case 2:
        {
            replyStream << "healer";
            break;
        }
        default:
        {
            replyStream << "dps";
            break;
        }
        }

        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "join")
    {
        std::ostringstream replyStream;
        Group* myGroup = pmPlayer->GetGroup();
        if (myGroup)
        {
            ObjectGuid targetGUID = pmPlayer->GetTarget();
            if (!targetGUID.IsEmpty())
            {
                bool validTarget = false;
                for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (member->GetGUID() != pmPlayer->GetGUID())
                        {
                            if (member->GetGUID() == targetGUID)
                            {
                                validTarget = true;
                                replyStream << "Joining " << member->GetName();
                                pmPlayer->TeleportTo(member->GetWorldLocation());
                            }
                        }
                    }
                }
                if (!validTarget)
                {
                    replyStream << "Target is no group member";
                }
            }
            else
            {
                replyStream << "You have no target";
            }
        }
        else
        {
            replyStream << "You are not in a group";
        }
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "front1")
    {
        std::ostringstream replyStream;
        Unit* targetUnit = pmPlayer->GetSelectedUnit();
        if (targetUnit)
        {
            if (pmPlayer->isInFront(targetUnit))
            {
                replyStream << "Yes";
            }
            else
            {
                replyStream << "No";
            }
        }
        else
        {
            replyStream << "No target";
        }
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "chase")
    {
        std::ostringstream replyStream;
        Unit* targetUnit = pmPlayer->GetSelectedUnit();
        if (targetUnit)
        {
            pmPlayer->GetMotionMaster()->MoveChase(targetUnit, ChaseRange(4.0f, 8.0f));
            replyStream << "Chasing";
        }
        else
        {
            replyStream << "No target";
        }
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "clear")
    {
        std::ostringstream replyStream;
        pmPlayer->GetMotionMaster()->Clear();
        replyStream << "Motion cleared";
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "stop")
    {
        std::ostringstream replyStream;
        pmPlayer->StopMoving();
        replyStream << "Stopped";
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "angle")
    {
        Unit* targetUnit = pmPlayer->GetSelectedUnit();
        std::ostringstream replyStream;
        if (targetUnit)
        {
            float angle = pmPlayer->GetAbsoluteAngle(targetUnit->GetPosition());
            replyStream << "Angle : " << angle;
        }
        else
        {
            replyStream << "No target";
        }
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "gameobject")
    {
        if (commandVector.size() > 1)
        {
            std::string newState = commandVector.at(1);
            if (commandVector.size() > 2)
            {
                uint32 spawnID = std::stoi(commandVector.at(2));
                GameObject* goTarget = pmPlayer->GetMap()->GetGameObjectBySpawnId(spawnID);
                if (goTarget)
                {
                    if (newState == "active")
                    {
                        goTarget->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    else if (newState == "ready")
                    {
                        goTarget->SetGoState(GOState::GO_STATE_READY);
                    }
                    else if (newState == "destroy")
                    {
                        goTarget->SetGoState(GOState::GO_STATE_DESTROYED);
                    }
                    else if (newState == "use")
                    {
                        if (Unit* playerTarget = pmPlayer->GetSelectedUnit())
                        {
                            goTarget->Use(playerTarget);
                        }
                        else
                        {
                            goTarget->Use(pmPlayer);
                        }
                    }
                    else if (newState == "flag")
                    {
                        if (commandVector.size() > 3)
                        {
                            uint32 flagValue = std::stoi(commandVector.at(3));
                            if (goTarget->HasFlag(GAMEOBJECT_FLAGS, flagValue))
                            {
                                goTarget->RemoveFlag(GAMEOBJECT_FLAGS, flagValue);
                            }
                            else
                            {
                                goTarget->SetFlag(GAMEOBJECT_FLAGS, flagValue);
                            }
                        }
                    }
                    else if (newState == "dflag")
                    {
                        if (commandVector.size() > 3)
                        {
                            uint32 flagValue = std::stoi(commandVector.at(3));
                            if (goTarget->HasFlag(EGameObjectFields::GAMEOBJECT_DYNAMIC, flagValue))
                            {
                                goTarget->RemoveFlag(EGameObjectFields::GAMEOBJECT_DYNAMIC, flagValue);
                            }
                            else
                            {
                                goTarget->SetFlag(EGameObjectFields::GAMEOBJECT_DYNAMIC, flagValue);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (commandName == "emote")
    {
        if (commandVector.size() > 1)
        {
            uint32 emoteID = std::stoi(commandVector.at(1));
            if (Unit* target = pmPlayer->GetSelectedUnit())
            {
                target->HandleEmoteCommand(emoteID);
            }
        }
    }
    else if (commandName == "attack")
    {
        if (commandVector.size() > 1)
        {
            Unit* targetUnit = pmPlayer->GetSelectedUnit();
            std::ostringstream replyStream;
            if (targetUnit)
            {
                int spawnID = std::stoi(commandVector.at(1));
                if (Creature* checkC = targetUnit->GetMap()->GetCreatureBySpawnId(spawnID))
                {
                    if (targetUnit->IsValidAttackTarget(checkC))
                    {
                        replyStream << checkC->GetName() << " is valid attack target to " << targetUnit->GetName();
                    }
                    else
                    {
                        replyStream << checkC->GetName() << " is not valid attack target to " << targetUnit->GetName();
                    }
                }
                else
                {
                    replyStream << "No creature";
                }
            }
            else
            {
                replyStream << "No target";
            }
            sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
        }
    }
    else if (commandName == "talk")
    {
        Unit* targetUnit = pmPlayer->GetSelectedUnit();
        if (Creature* checkC = targetUnit->ToCreature())
        {
            checkC->AI()->Talk(0);
        }
    }
    else if (commandName == "test")
    {
        if (commandVector.size() > 1)
        {
            std::string testPart = commandVector.at(1);
            if (testPart == "immo")
            {
                if (InstanceScript* is = pmPlayer->GetInstanceScript())
                {
                    is->SetData(2, 0);
                }
            }
            else if (testPart == "charger")
            {
                if (Map* currentMap = pmPlayer->GetMap())
                {
                    currentMap->SummonCreature(14516, pmPlayer->GetPosition());
                }
            }
        }
    }
    else if (commandName == "cast")
    {
        if (Unit* targetUnit = pmPlayer->GetSelectedUnit())
        {
            if (commandVector.size() > 1)
            {
                uint32 spellID = std::stoi(commandVector.at(1));
                targetUnit->CastSpell(targetUnit, spellID);
            }
        }
    }
    else if (commandName == "aura")
    {
        std::ostringstream replyStream;
        if (commandVector.size() > 1)
        {
            if (Unit* targetUnit = pmPlayer->GetSelectedUnit())
            {
                uint32 spellID = std::stoi(commandVector.at(1));
                if (targetUnit->HasAura(spellID))
                {
                    replyStream << "Has aura : " << spellID;
                }
                else
                {
                    replyStream << "No aura : " << spellID;
                }
            }
            else
            {
                replyStream << "No target";
            }
        }
        else
        {
            replyStream << "No spell id";
        }
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
}

bool RobotManager::StringEndWith(const std::string& str, const std::string& tail)
{
    return str.compare(str.size() - tail.size(), tail.size(), tail) == 0;
}

bool RobotManager::StringStartWith(const std::string& str, const std::string& head)
{
    return str.compare(0, head.size(), head) == 0;
}

Strategy_Solo* RobotManager::GetSoloStrategy(uint32 pmSessionID)
{
    if (soloStrategyMap.find(pmSessionID) != soloStrategyMap.end())
    {
        return soloStrategyMap[pmSessionID];
    }

    return NULL;
}

bool RobotManager::IsRobot(uint32 pmCharacterID)
{
    if (prepareStrategyMap.find(pmCharacterID) != prepareStrategyMap.end())
    {
        return true;
    }
    return false;
}

std::vector<std::string> RobotManager::SplitString(std::string srcStr, std::string delimStr, bool repeatedCharIgnored)
{
    std::vector<std::string> resultStringVector;
    std::replace_if(srcStr.begin(), srcStr.end(), [&](const char& c) {if (delimStr.find(c) != std::string::npos) { return true; } else { return false; }}/*pred*/, delimStr.at(0));
    size_t pos = srcStr.find(delimStr.at(0));
    std::string addedString = "";
    while (pos != std::string::npos) {
        addedString = srcStr.substr(0, pos);
        if (!addedString.empty() || !repeatedCharIgnored) {
            resultStringVector.push_back(addedString);
        }
        srcStr.erase(srcStr.begin(), srcStr.begin() + pos + 1);
        pos = srcStr.find(delimStr.at(0));
    }
    addedString = srcStr;
    if (!addedString.empty() || !repeatedCharIgnored) {
        resultStringVector.push_back(addedString);
    }
    return resultStringVector;
}

std::string RobotManager::TrimString(std::string srcStr)
{
    std::string result = srcStr;
    if (!result.empty())
    {
        result.erase(0, result.find_first_not_of(" "));
        result.erase(result.find_last_not_of(" ") + 1);
    }

    return result;
}
