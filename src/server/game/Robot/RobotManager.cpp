#include "RobotManager.h"
#include "GroupMgr.h"
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
#include "GridNotifiers.h"
#include "PathGenerator.h"
#include "RobotStrategy.h"
#include "Script_Paladin.h"

RobotManager::RobotManager()
{
    nameIndex = 0;
    // EJ debug
    checkDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
    //checkDelay = 10 * TimeConstants::IN_MILLISECONDS;

    robotEntityMap.clear();
    deleteRobotAccountSet.clear();
    meleeWeaponMap.clear();
    rangeWeaponMap.clear();
    armorMap.clear();
    miscMap.clear();
    onlinePlayerIDMap.clear();
    tamableBeastEntryMap.clear();
    spellRewardClassQuestIDSet.clear();
    spellNameEntryMap.clear();
    lightwellRenewSpellIDSet.clear();
    lightwellUnitEntrySet.clear();
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
            sRobotConfig->Enable = 0;
            sWorld->ShutdownServ(30, SHUTDOWN_MASK_RESTART | SHUTDOWN_MASK_IDLE, RESTART_EXIT_CODE);
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
    uint8 levelRange = 0;
    ItemTemplateContainer const& its = sObjectMgr->GetItemTemplateStore();
    for (auto const& itemTemplatePair : its)
    {
        levelRange = 0;
        if (rlSet.find(itemTemplatePair.first) == rlSet.end())
        {
            continue;
        }
        const ItemTemplate* proto = &itemTemplatePair.second;
        if (!proto)
        {
            continue;
        }
        if (proto->Quality < 2)
        {
            continue;
        }
        if (proto->RequiredLevel < 10)
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

    QueryResult worldRobotQR = CharacterDatabase.Query("SELECT robot_id, account_id, character_id, target_level, robot_type FROM robot order by rand()");
    if (worldRobotQR)
    {
        do
        {
            Field* fields = worldRobotQR->Fetch();
            uint32 robot_id = fields[0].GetUInt32();
            uint32 account_id = fields[1].GetUInt32();
            uint32 character_id = fields[2].GetUInt32();
            uint32 target_level = fields[3].GetUInt32();
            uint32 robot_type = fields[4].GetUInt32();
            RobotEntity* re = new RobotEntity(robot_id);
            re->account_id = account_id;
            re->character_id = character_id;
            re->target_level = target_level;
            re->robot_type = robot_type;
            robotEntityMap[robot_type].insert(re);
        } while (worldRobotQR->NextRow());
    }

    lightwellRenewSpellIDSet.insert(7001);
    lightwellRenewSpellIDSet.insert(27873);
    lightwellRenewSpellIDSet.insert(27874);
    lightwellRenewSpellIDSet.insert(28276);
    lightwellRenewSpellIDSet.insert(48084);
    lightwellRenewSpellIDSet.insert(48085);

    lightwellUnitEntrySet.insert(31897);
    lightwellUnitEntrySet.insert(31896);
    lightwellUnitEntrySet.insert(31895);
    lightwellUnitEntrySet.insert(31894);
    lightwellUnitEntrySet.insert(31893);
    lightwellUnitEntrySet.insert(31883);

    QueryResult orgrimmar_gruntQR = WorldDatabase.Query("SELECT guid FROM creature where id = 3296");
    if (orgrimmar_gruntQR)
    {
        do
        {
            Field* fields = orgrimmar_gruntQR->Fetch();
            uint32 spawnID = fields[0].GetUInt32();
            orgrimmar_gruntSpawnIDMap[orgrimmar_gruntSpawnIDMap.size()] = spawnID;
        } while (orgrimmar_gruntQR->NextRow());
    }

    QueryResult ironforge_guardQR = WorldDatabase.Query("SELECT guid FROM creature where id = 5595");
    if (ironforge_guardQR)
    {
        do
        {
            Field* fields = ironforge_guardQR->Fetch();
            uint32 spawnID = fields[0].GetUInt32();
            ironforge_guardSpawnIDMap[ironforge_guardSpawnIDMap.size()] = spawnID;
        } while (ironforge_guardQR->NextRow());
    }

    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot system ready");
}

RobotManager* RobotManager::instance()
{
    static RobotManager instance;
    return &instance;
}

void RobotManager::CheckLevelRobotEntities(uint32 pmLevel, uint32 pmRobotType, uint32 pmTotalCount)
{
    int toOnline = pmTotalCount;
    for (std::unordered_set<RobotEntity*>::iterator reIT = robotEntityMap[pmRobotType].begin(); reIT != robotEntityMap[pmRobotType].end(); reIT++)
    {
        if (RobotEntity* eachRE = *reIT)
        {
            if (eachRE->target_level == pmLevel)
            {
                if (eachRE->entityState == RobotEntityState::RobotEntityState_OffLine)
                {
                    eachRE->entityState = RobotEntityState::RobotEntityState_Enter;
                    eachRE->checkDelay = urand(sRobotConfig->OnlineMinDelay, sRobotConfig->OnlineMaxDelay);
                }
                toOnline--;
                if (toOnline <= 0)
                {
                    break;
                }
            }
        }
    }
    while (toOnline > 0)
    {
        // add to DB
        uint32 maxRID = 0;
        QueryResult maxRIDQR = CharacterDatabase.PQuery("SELECT robot_id FROM robot where robot_type = %d order by robot_id desc limit 1", pmRobotType);
        if (maxRIDQR)
        {
            Field* fields = maxRIDQR->Fetch();
            maxRID = fields[0].GetUInt32();
        }
        maxRID++;

        std::ostringstream sqlStream;
        sqlStream << "INSERT INTO robot (robot_id, account_id, character_id, target_level, robot_type) VALUES (" << maxRID << ", 0, 0, " << pmLevel << ", " << pmRobotType << ")";
        std::string sql = sqlStream.str();
        CharacterDatabase.DirectExecute(sql.c_str());

        RobotEntity* re = new RobotEntity(maxRID);
        re->account_id = 0;
        re->character_id = 0;
        re->target_level = pmLevel;
        re->robot_type = pmRobotType;
        robotEntityMap[pmRobotType].insert(re);

        toOnline--;
    }
}

void RobotManager::UpdateRobotManager(uint32 pmDiff)
{
    if (sRobotConfig->Enable == 0)
    {
        return;
    }

    checkDelay -= pmDiff;
    if (checkDelay < 0)
    {
        checkDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
        onlinePlayerIDMap.clear();
        std::unordered_set<uint32> onlinePlayerLevelSet;
        for (std::unordered_map<uint32, WorldSession*>::const_iterator wsIT = sWorld->GetAllSessions().begin(); wsIT != sWorld->GetAllSessions().end(); wsIT++)
        {
            if (!wsIT->second->isRobotSession)
            {
                if (Player* eachPlayer = wsIT->second->GetPlayer())
                {
                    if (!eachPlayer->IsInWorld())
                    {
                        continue;
                    }
                    if (eachPlayer->GetLevel() < 20)
                    {
                        continue;
                    }
                    onlinePlayerIDMap[onlinePlayerIDMap.size()] = eachPlayer->GetGUID().GetCounter();
                    if (onlinePlayerLevelSet.find(eachPlayer->GetLevel()) == onlinePlayerLevelSet.end())
                    {
                        onlinePlayerLevelSet.insert(eachPlayer->GetLevel());
                    }
                }
            }
        }
        if (sRobotConfig->OnlineLevel >= 20)
        {
            if (onlinePlayerLevelSet.find(sRobotConfig->OnlineLevel) == onlinePlayerLevelSet.end())
            {
                onlinePlayerLevelSet.insert(sRobotConfig->OnlineLevel);
            }
        }

        for (std::unordered_set<uint32>::iterator levelIT = onlinePlayerLevelSet.begin(); levelIT != onlinePlayerLevelSet.end(); levelIT++)
        {
            uint32 eachLevel = *levelIT;
            int toOnline = sRobotConfig->CountEachLevel;
            CheckLevelRobotEntities(eachLevel, RobotType::RobotType_World, toOnline);
        }

        for (std::unordered_set<RobotEntity*>::iterator reIT = robotEntityMap[RobotType::RobotType_World].begin(); reIT != robotEntityMap[RobotType::RobotType_World].end(); reIT++)
        {
            if (RobotEntity* eachRE = *reIT)
            {
                if (eachRE->entityState == RobotEntityState::RobotEntityState_Online)
                {
                    if (onlinePlayerLevelSet.find(eachRE->target_level) == onlinePlayerLevelSet.end())
                    {
                        eachRE->entityState = RobotEntityState::RobotEntityState_Exit;
                        eachRE->checkDelay = urand(sRobotConfig->OnlineMinDelay, sRobotConfig->OnlineMaxDelay);
                    }
                }
            }
        }

        uint32 raidLevel = 60;
        int toOnline = sRobotConfig->RaidRobotCount_60;
        if (toOnline > 0)
        {
            CheckLevelRobotEntities(raidLevel, RobotType::RobotType_Raid, toOnline);
        }
        raidLevel = 70;
        toOnline = sRobotConfig->RaidRobotCount_70;
        if (toOnline > 0)
        {
            CheckLevelRobotEntities(raidLevel, RobotType::RobotType_Raid, toOnline);
        }
        raidLevel = 80;
        toOnline = sRobotConfig->RaidRobotCount_80;
        if (toOnline > 0)
        {
            CheckLevelRobotEntities(raidLevel, RobotType::RobotType_Raid, toOnline);
        }
    }

    for (std::unordered_set<RobotEntity*>::iterator reIT = robotEntityMap[RobotType::RobotType_World].begin(); reIT != robotEntityMap[RobotType::RobotType_World].end(); reIT++)
    {
        if (RobotEntity* eachRE = *reIT)
        {
            eachRE->Update(pmDiff);
        }
    }
    for (std::unordered_set<RobotEntity*>::iterator reIT = robotEntityMap[RobotType::RobotType_Raid].begin(); reIT != robotEntityMap[RobotType::RobotType_Raid].end(); reIT++)
    {
        if (RobotEntity* eachRE = *reIT)
        {
            eachRE->Update(pmDiff);
        }
    }
}

bool RobotManager::DeleteRobots()
{
    std::ostringstream sqlStream;
    sqlStream << "delete from robot";
    std::string sql = sqlStream.str();
    CharacterDatabase.Execute(sql.c_str());

    QueryResult accountQR = LoginDatabase.PQuery("SELECT id, username FROM account where username like '%s%%'", sRobotConfig->AccountNamePrefix.c_str());

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
        accountNameStream << sRobotConfig->AccountNamePrefix << checkIndex;
        AccountOpResult aor = sAccountMgr->CreateAccount(accountNameStream.str(), ROBOT_PASSWORD);
        if (aor == AccountOpResult::AOR_NAME_ALREADY_EXIST)
        {
            checkIndex++;
        }
        else if (aor == AccountOpResult::AOR_OK)
        {
            result = CheckRobotAccount(accountNameStream.str());
            break;
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

uint32 RobotManager::CreateRobotCharacter(uint32 pmAccountID)
{
    uint32  targetClass = Classes::CLASS_WARRIOR;
    while (true)
    {
        targetClass = urand(Classes::CLASS_WARRIOR, Classes::CLASS_DRUID);
        if (targetClass == Classes::CLASS_WARRIOR || targetClass == Classes::CLASS_DEATH_KNIGHT || targetClass == Classes::CLASS_SHAMAN || targetClass == Classes::CLASS_MAGE || targetClass == Classes::CLASS_UNK)
        {
            continue;
        }
        break;
    }    
    uint32 raceIndex = urand(0, availableRaces[targetClass].size() - 1);
    uint32 targetRace = availableRaces[targetClass][raceIndex];

    return CreateRobotCharacter(pmAccountID, targetClass, targetRace);
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
        newPlayer->SaveToDB(true);
        result = newPlayer->GetGUID().GetRawValue();
        eachSession->isRobotSession = true;
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
    ObjectGuid playerGuid = ObjectGuid(HighGuid::Player, pmCharacterID);
    if (Player* currentPlayer = ObjectAccessor::FindConnectedPlayer(playerGuid))
    {
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot %d %s is already in world", pmCharacterID, currentPlayer->GetName());
        return false;
    }
    WorldSession* loginSession = sWorld->FindSession(pmAccountID);
    if (!loginSession)
    {
        loginSession = new WorldSession(pmAccountID, "robot", NULL, SEC_PLAYER, 2, 0, LOCALE_enUS, 0, false);
        sWorld->AddSession(loginSession);
    }
    loginSession->isRobotSession = true;
    loginSession->HandlePlayerLogin_Simple(playerGuid);
    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Log in character %d %d", pmAccountID, pmCharacterID);

    return true;
}

void RobotManager::LogoutRobot(uint32 pmCharacterID)
{
    ObjectGuid guid = ObjectGuid(HighGuid::Player, pmCharacterID);
    Player* checkP = ObjectAccessor::FindConnectedPlayer(guid);
    if (checkP)
    {
        if (!checkP->IsAlive())
        {
            checkP->ResurrectPlayer(1.0f);
            checkP->SpawnCorpseBones();
        }
        checkP->ClearInCombat();
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Log out robot %s", checkP->GetName());
        std::ostringstream msgStream;
        msgStream << checkP->GetName() << " logged out";
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, msgStream.str().c_str());
        if (WorldSession* checkWS = checkP->GetSession())
        {
            checkWS->LogoutPlayer(true);
        }
    }
}

void RobotManager::LogoutRobots()
{
    for (std::unordered_set<RobotEntity*>::iterator reIT = robotEntityMap[RobotType::RobotType_World].begin(); reIT != robotEntityMap[RobotType::RobotType_World].end(); reIT++)
    {
        RobotEntity* eachRE = *reIT;
        LogoutRobot(eachRE->character_id);
        eachRE->entityState = RobotEntityState::RobotEntityState_CheckLogoff;
    }
    for (std::unordered_set<RobotEntity*>::iterator reIT = robotEntityMap[RobotType::RobotType_Raid].begin(); reIT != robotEntityMap[RobotType::RobotType_Raid].end(); reIT++)
    {
        RobotEntity* eachRE = *reIT;
        LogoutRobot(eachRE->character_id);
        eachRE->entityState = RobotEntityState::RobotEntityState_CheckLogoff;
    }
}

bool RobotManager::PrepareRobot(Player* pmRobot)
{
    if (!pmRobot)
    {
        return false;
    }

    uint32 weaponType = 0;
    bool dual = false;
    bool hasShield = false;
    bool hasRange = false;
    uint32 rangeType = 0;

    pmRobot->DurabilityRepairAll(false, 0, false);
    if (pmRobot->GetClass() == Classes::CLASS_HUNTER)
    {
        uint32 ammoEntry = 0;
        Item* weapon = pmRobot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
        if (weapon)
        {
            uint32 subClass = weapon->GetTemplate()->SubClass;
            uint8 playerLevel = pmRobot->GetLevel();
            if (subClass == ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_BOW || subClass == ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_CROSSBOW)
            {
                if (playerLevel >= 40)
                {
                    ammoEntry = 11285;
                }
                else if (playerLevel >= 25)
                {
                    ammoEntry = 3030;
                }
                else
                {
                    ammoEntry = 2515;
                }
            }
            else if (subClass == ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_GUN)
            {
                if (playerLevel >= 40)
                {
                    ammoEntry = 11284;
                }
                else if (playerLevel >= 25)
                {
                    ammoEntry = 3033;
                }
                else
                {
                    ammoEntry = 2519;
                }
            }
            if (ammoEntry > 0)
            {
                if (!pmRobot->HasItemCount(ammoEntry, 100))
                {
                    pmRobot->StoreNewItemInBestSlots(ammoEntry, 1000);
                    pmRobot->SetAmmo(ammoEntry);
                }
            }
        }
    }
    Pet* checkPet = pmRobot->GetPet();
    if (checkPet)
    {
        checkPet->SetReactState(REACT_DEFENSIVE);
        if (checkPet->getPetType() == PetType::HUNTER_PET)
        {
            checkPet->SetPower(POWER_HAPPINESS, HAPPINESS_LEVEL_SIZE * 3);
        }
        std::unordered_map<uint32, PetSpell> petSpellMap = checkPet->m_spells;
        for (std::unordered_map<uint32, PetSpell>::iterator it = petSpellMap.begin(); it != petSpellMap.end(); it++)
        {
            if (it->second.active == ACT_DISABLED || it->second.active == ACT_ENABLED)
            {
                const SpellInfo* pST = sSpellMgr->GetSpellInfo(it->first);
                if (pST)
                {
                    std::string checkNameStr = std::string(pST->SpellName[0]);
                    if (checkNameStr == "Prowl")
                    {
                        checkPet->ToggleAutocast(pST, false);
                    }
                    else if (checkNameStr == "Phase Shift")
                    {
                        checkPet->ToggleAutocast(pST, false);
                    }
                    else if (checkNameStr == "Cower")
                    {
                        checkPet->ToggleAutocast(pST, false);
                    }
                    else if (checkNameStr == "Growl")
                    {
                        if (pmRobot->GetGroup())
                        {
                            checkPet->ToggleAutocast(pST, false);
                        }
                        else
                        {
                            checkPet->ToggleAutocast(pST, true);
                        }
                    }
                    else
                    {
                        checkPet->ToggleAutocast(pST, true);
                    }
                }
            }
        }
    }
    pmRobot->Say("Ready", Language::LANG_UNIVERSAL);
}

std::unordered_set<uint32> RobotManager::GetUsableEquipSlot(const ItemTemplate* pmIT)
{
    std::unordered_set<uint32> resultSet;

    switch (pmIT->InventoryType)
    {
    case INVTYPE_HEAD:
    {
        resultSet.insert(EQUIPMENT_SLOT_HEAD);
        break;
    }
    case INVTYPE_NECK:
    {
        resultSet.insert(EQUIPMENT_SLOT_NECK);
        break;
    }
    case INVTYPE_SHOULDERS:
    {
        resultSet.insert(EQUIPMENT_SLOT_SHOULDERS);
        break;
    }
    case INVTYPE_BODY:
    {
        resultSet.insert(EQUIPMENT_SLOT_BODY);
        break;
    }
    case INVTYPE_CHEST:
    {
        resultSet.insert(EQUIPMENT_SLOT_CHEST);
        break;
    }
    case INVTYPE_ROBE:
    {
        resultSet.insert(EQUIPMENT_SLOT_CHEST);
        break;
    }
    case INVTYPE_WAIST:
    {
        resultSet.insert(EQUIPMENT_SLOT_WAIST);
        break;
    }
    case INVTYPE_LEGS:
    {
        resultSet.insert(EQUIPMENT_SLOT_LEGS);
        break;
    }
    case INVTYPE_FEET:
    {
        resultSet.insert(EQUIPMENT_SLOT_FEET);
        break;
    }
    case INVTYPE_WRISTS:
    {
        resultSet.insert(EQUIPMENT_SLOT_WRISTS);
        break;
    }
    case INVTYPE_HANDS:
    {
        resultSet.insert(EQUIPMENT_SLOT_HANDS);
        break;
    }
    case INVTYPE_FINGER:
    {
        resultSet.insert(EQUIPMENT_SLOT_FINGER1);
        resultSet.insert(EQUIPMENT_SLOT_FINGER2);
        break;
    }
    case INVTYPE_TRINKET:
    {
        resultSet.insert(EQUIPMENT_SLOT_TRINKET1);
        resultSet.insert(EQUIPMENT_SLOT_TRINKET2);
        break;
    }
    case INVTYPE_CLOAK:
    {
        resultSet.insert(EQUIPMENT_SLOT_BACK);
        break;
    }
    case INVTYPE_WEAPON:
    {
        resultSet.insert(EQUIPMENT_SLOT_MAINHAND);
        resultSet.insert(EQUIPMENT_SLOT_OFFHAND);
        break;
    }
    case INVTYPE_SHIELD:
    {
        resultSet.insert(EQUIPMENT_SLOT_OFFHAND);
        break;
    }
    case INVTYPE_RANGED:
    {
        resultSet.insert(EQUIPMENT_SLOT_RANGED);
        break;
    }
    case INVTYPE_2HWEAPON:
    {
        resultSet.insert(EQUIPMENT_SLOT_MAINHAND);
        break;
    }
    case INVTYPE_TABARD:
    {
        resultSet.insert(EQUIPMENT_SLOT_TABARD);
        break;
    }
    case INVTYPE_WEAPONMAINHAND:
    {
        resultSet.insert(EQUIPMENT_SLOT_MAINHAND);
        break;
    }
    case INVTYPE_WEAPONOFFHAND:
    {
        resultSet.insert(EQUIPMENT_SLOT_OFFHAND);
        break;
    }
    case INVTYPE_HOLDABLE:
    {
        resultSet.insert(EQUIPMENT_SLOT_OFFHAND);
        break;
    }
    case INVTYPE_THROWN:
    {
        resultSet.insert(EQUIPMENT_SLOT_RANGED);
        break;
    }
    case INVTYPE_RANGEDRIGHT:
    {
        resultSet.insert(EQUIPMENT_SLOT_RANGED);
        break;
    }
    case INVTYPE_BAG:
    {
        resultSet.insert(INVENTORY_SLOT_BAG_START);
        break;
    }
    case INVTYPE_RELIC:
    {
        break;
    }
    default:
    {
        break;
    }
    }

    return resultSet;
}

void RobotManager::HandlePlayerSay(Player* pmPlayer, std::string pmContent)
{
    if (!pmPlayer)
    {
        return;
    }
    std::vector<std::string> commandVector = SplitString(pmContent, " ", true);
    std::string commandName = commandVector.at(0);
    if (commandName == "role")
    {
        std::ostringstream replyStream;
        if (RobotStrategy_Group* rsg = (RobotStrategy_Group*)pmPlayer->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
        {
            if (commandVector.size() > 1)
            {
                std::string newRole = commandVector.at(1);
                rsg->SetGroupRole(newRole);
            }
            replyStream << "Your group role is ";
            replyStream << rsg->GetGroupRoleName();
        }
        else
        {
            replyStream << "Incorrect strategy";
        }
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "strategy")
    {
        std::ostringstream replyStream;
        if (commandVector.size() > 1)
        {
            std::ostringstream targetStream;
            uint8 arrayCount = 0;
            for (std::vector<std::string>::iterator it = commandVector.begin(); it != commandVector.end(); it++)
            {
                if (arrayCount > 0)
                {
                    targetStream << (*it) << " ";
                }
                arrayCount++;
            }
            std::string strategyName = sRobotManager->TrimString(targetStream.str());
            if (strategyName == "solo")
            {
                pmPlayer->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Solo;
                replyStream << "Strategy set to solo";
            }
            else if (strategyName == "group")
            {
                pmPlayer->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Group;
                replyStream << "Strategy set to group";
            }
            else if (strategyName == "blackrock spire")
            {
                pmPlayer->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Group_Blackrock_Spire;
                replyStream << "Strategy set to blackrock spire";
            }
            else if (strategyName == "alcaz island")
            {
                pmPlayer->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Group_Alcaz_Island;
                replyStream << "Strategy set to alcaz island";
            }
            else if (strategyName == "shadow labyrinth")
            {
                pmPlayer->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Group_Shadow_Labyrinth;
                replyStream << "Strategy set to shadow labyrinth";
            }
            else if (strategyName == "ysondre")
            {
                pmPlayer->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Group_Ysondre;
                replyStream << "Strategy set to ysondre";
            }
            else
            {
                replyStream << "Unknown strategy";
            }
        }
        else
        {
            switch (pmPlayer->rai->activeStrategyIndex)
            {
            case Strategy_Index::Strategy_Index_Solo:
            {
                replyStream << "Strategy is solo";
                break;
            }
            case Strategy_Index::Strategy_Index_Group:
            {
                replyStream << "Strategy is group";
                break;
            }
            case Strategy_Index::Strategy_Index_Group_Blackrock_Spire:
            {
                replyStream << "Strategy is blackrock spire";
                break;
            }
            case Strategy_Index::Strategy_Index_Group_Alcaz_Island:
            {
                replyStream << "Strategy is alcaz island";
                break;
            }
            case Strategy_Index::Strategy_Index_Group_Shadow_Labyrinth:
            {
                replyStream << "Strategy is shadow labyrinth";
                break;
            }
            case Strategy_Index::Strategy_Index_Group_Ysondre:
            {
                replyStream << "Strategy is ysondre";
                break;
            }
            default:
            {
                replyStream << "Strategy is unknown";
                break;
            }
            }
        }
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "arrangement")
    {
        std::ostringstream replyStream;
        if (Group* myGroup = pmPlayer->GetGroup())
        {
            if (myGroup->GetLeaderGUID() == pmPlayer->GetGUID())
            {
                switch (pmPlayer->rai->activeStrategyIndex)
                {
                case Strategy_Index::Strategy_Index_Group:
                {
                    bool paladinAura_concentration = false;
                    bool paladinAura_devotion = false;
                    bool paladinAura_retribution = false;
                    bool paladinBlessing_kings = false;
                    bool paladinBlessing_might = false;
                    bool paladinBlessing_wisdom = false;
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        Player* member = groupRef->GetSource();
                        if (member)
                        {
                            if (!member->GetSession()->isRobotSession)
                            {
                                member->groupRole = GroupRole::GroupRole_DPS;
                                continue;
                            }
                            if (member->GetClass() == Classes::CLASS_PALADIN)
                            {
                                if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                                {
                                    if (Script_Paladin* sp = (Script_Paladin*)rs->sb)
                                    {
                                        switch (sp->blessingType)
                                        {
                                        case PaladinBlessingType::PaladinBlessingType_Kings:
                                        {
                                            if (paladinBlessing_kings)
                                            {
                                                if (!paladinBlessing_might)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Might;
                                                    paladinBlessing_might = true;
                                                }
                                                else if (!paladinBlessing_wisdom)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Wisdom;
                                                    paladinBlessing_wisdom = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinBlessing_kings = true;
                                            }
                                            break;
                                        }
                                        case PaladinBlessingType::PaladinBlessingType_Might:
                                        {
                                            if (paladinBlessing_might)
                                            {
                                                if (!paladinBlessing_kings)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Kings;
                                                    paladinBlessing_kings = true;
                                                }
                                                else if (!paladinBlessing_wisdom)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Wisdom;
                                                    paladinBlessing_wisdom = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinBlessing_might = true;
                                            }
                                            break;
                                        }
                                        case PaladinBlessingType::PaladinBlessingType_Wisdom:
                                        {
                                            if (paladinBlessing_wisdom)
                                            {
                                                if (!paladinBlessing_kings)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Kings;
                                                    paladinBlessing_kings = true;
                                                }
                                                else if (!paladinBlessing_might)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Might;
                                                    paladinBlessing_might = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinBlessing_wisdom = true;
                                            }
                                            break;
                                        }
                                        default:
                                        {
                                            break;
                                        }
                                        }
                                        switch (sp->auraType)
                                        {
                                        case PaladinAuraType::PaladinAuraType_Concentration:
                                        {
                                            if (paladinAura_concentration)
                                            {
                                                if (!paladinAura_devotion)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Devotion;
                                                    paladinAura_devotion = true;
                                                }
                                                else if (!paladinAura_retribution)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Retribution;
                                                    paladinAura_retribution = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinAura_concentration = true;
                                            }
                                            break;
                                        }
                                        case PaladinAuraType::PaladinAuraType_Devotion:
                                        {
                                            if (paladinAura_devotion)
                                            {
                                                if (!paladinAura_concentration)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Concentration;
                                                    paladinAura_concentration = true;
                                                }
                                                else if (!paladinAura_retribution)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Retribution;
                                                    paladinAura_retribution = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinAura_devotion = true;
                                            }
                                            break;
                                        }
                                        case PaladinAuraType::PaladinAuraType_Retribution:
                                        {
                                            if (paladinAura_retribution)
                                            {
                                                if (!paladinAura_concentration)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Concentration;
                                                    paladinAura_concentration = true;
                                                }
                                                else if (!paladinAura_devotion)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Devotion;
                                                    paladinAura_devotion = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinAura_retribution = true;
                                            }
                                            break;
                                        }
                                        default:
                                        {
                                            break;
                                        }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    replyStream << "Arranged";
                    break;
                }
                case Strategy_Index::Strategy_Index_Group_Blackrock_Spire:
                {
                    bool tank1Set = false;
                    bool tank2Set = false;
                    bool tank3Set = false;
                    bool healer1Set = false;

                    bool paladinAura_concentration = false;
                    bool paladinAura_devotion = false;
                    bool paladinAura_retribution = false;
                    bool paladinBlessing_kings = false;
                    bool paladinBlessing_might = false;
                    bool paladinBlessing_wisdom = false;
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        Player* member = groupRef->GetSource();
                        if (member)
                        {
                            if (!member->GetSession()->isRobotSession)
                            {
                                member->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS;
                                continue;
                            }
                            if (RobotStrategy_Group_Blackrock_Spire* rs = (RobotStrategy_Group_Blackrock_Spire*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                            {
                                rs->dpsDelay = 5000;
                                rs->aoeDelay = 10000;
                                rs->followDistance = MELEE_MIN_DISTANCE;
                                switch (member->GetClass())
                                {
                                case Classes::CLASS_WARRIOR:
                                {
                                    break;
                                }
                                case Classes::CLASS_HUNTER:
                                {
                                    rs->followDistance = RANGED_NORMAL_DISTANCE;
                                    break;
                                }
                                case Classes::CLASS_SHAMAN:
                                {
                                    rs->followDistance = RANGED_NORMAL_DISTANCE;
                                    break;
                                }
                                case Classes::CLASS_PALADIN:
                                {
                                    if (Script_Paladin* sp = (Script_Paladin*)rs->sb)
                                    {
                                        switch (sp->blessingType)
                                        {
                                        case PaladinBlessingType::PaladinBlessingType_Kings:
                                        {
                                            if (paladinBlessing_kings)
                                            {
                                                if (!paladinBlessing_might)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Might;
                                                    paladinBlessing_might = true;
                                                }
                                                else if (!paladinBlessing_wisdom)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Wisdom;
                                                    paladinBlessing_wisdom = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinBlessing_kings = true;
                                            }
                                            break;
                                        }
                                        case PaladinBlessingType::PaladinBlessingType_Might:
                                        {
                                            if (paladinBlessing_might)
                                            {
                                                if (!paladinBlessing_kings)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Kings;
                                                    paladinBlessing_kings = true;
                                                }
                                                else if (!paladinBlessing_wisdom)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Wisdom;
                                                    paladinBlessing_wisdom = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinBlessing_might = true;
                                            }
                                            break;
                                        }
                                        case PaladinBlessingType::PaladinBlessingType_Wisdom:
                                        {
                                            if (paladinBlessing_wisdom)
                                            {
                                                if (!paladinBlessing_kings)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Kings;
                                                    paladinBlessing_kings = true;
                                                }
                                                else if (!paladinBlessing_might)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Might;
                                                    paladinBlessing_might = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinBlessing_wisdom = true;
                                            }
                                            break;
                                        }
                                        default:
                                        {
                                            break;
                                        }
                                        }
                                        switch (sp->auraType)
                                        {
                                        case PaladinAuraType::PaladinAuraType_Concentration:
                                        {
                                            if (paladinAura_concentration)
                                            {
                                                if (!paladinAura_devotion)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Devotion;
                                                    paladinAura_devotion = true;
                                                }
                                                else if (!paladinAura_retribution)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Retribution;
                                                    paladinAura_retribution = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinAura_concentration = true;
                                            }
                                            break;
                                        }
                                        case PaladinAuraType::PaladinAuraType_Devotion:
                                        {
                                            if (paladinAura_devotion)
                                            {
                                                if (!paladinAura_concentration)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Concentration;
                                                    paladinAura_concentration = true;
                                                }
                                                else if (!paladinAura_retribution)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Retribution;
                                                    paladinAura_retribution = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinAura_devotion = true;
                                            }
                                            break;
                                        }
                                        case PaladinAuraType::PaladinAuraType_Retribution:
                                        {
                                            if (paladinAura_retribution)
                                            {
                                                if (!paladinAura_concentration)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Concentration;
                                                    paladinAura_concentration = true;
                                                }
                                                else if (!paladinAura_devotion)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Devotion;
                                                    paladinAura_devotion = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinAura_retribution = true;
                                            }
                                            break;
                                        }
                                        default:
                                        {
                                            break;
                                        }
                                        }
                                    }
                                    break;
                                }
                                case Classes::CLASS_WARLOCK:
                                {
                                    rs->followDistance = RANGED_NORMAL_DISTANCE;
                                    break;
                                }
                                case Classes::CLASS_PRIEST:
                                {
                                    rs->followDistance = RANGED_NORMAL_DISTANCE;
                                    break;
                                }
                                case Classes::CLASS_ROGUE:
                                {
                                    break;
                                }
                                case Classes::CLASS_MAGE:
                                {
                                    rs->followDistance = RANGED_NORMAL_DISTANCE;
                                    break;
                                }
                                case Classes::CLASS_DRUID:
                                {
                                    break;
                                }
                                default:
                                {
                                    break;
                                }
                                }
                                if (rs->sb->characterType == RobotCharacterType::RobotCharacterType_TANK)
                                {
                                    if (!tank1Set)
                                    {
                                        member->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1;
                                        tank1Set = true;
                                        continue;
                                    }
                                    else if (!tank2Set)
                                    {
                                        member->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2;
                                        tank2Set = true;
                                        continue;
                                    }
                                    else if (!tank3Set)
                                    {
                                        member->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3;
                                        tank3Set = true;
                                        continue;
                                    }
                                }
                                else if (rs->sb->characterType == RobotCharacterType::RobotCharacterType_HEALER)
                                {
                                    if (!healer1Set)
                                    {
                                        member->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1;
                                        healer1Set = true;
                                        continue;
                                    }
                                    else
                                    {
                                        member->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2;
                                        continue;
                                    }
                                }
                                member->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS;
                            }
                        }
                    }
                    replyStream << "Arranged";
                    break;
                }
                case Strategy_Index::Strategy_Index_Group_Shadow_Labyrinth:
                {
                    replyStream << "Arranged";
                    break;
                }

                case Strategy_Index::Strategy_Index_Group_Ysondre:
                {
                    bool tank1Set = false;
                    bool tank2Set = false;
                    uint32 healer1Count = 0;
                    uint32 healer2Count = 0;

                    bool paladinAura_concentration = false;
                    bool paladinAura_devotion = false;
                    bool paladinAura_retribution = false;
                    bool paladinBlessing_kings = false;
                    bool paladinBlessing_might = false;
                    bool paladinBlessing_wisdom = false;
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        Player* member = groupRef->GetSource();
                        if (member)
                        {
                            if (!member->GetSession()->isRobotSession)
                            {
                                member->groupRole = GroupRole_Ysondre::GroupRole_Ysondre_DPS_Range;
                                continue;
                            }
                            if (RobotStrategy_Group_Ysondre* rs = (RobotStrategy_Group_Ysondre*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                            {
                                rs->dpsDelay = 5000;
                                rs->aoeDelay = 10000;
                                rs->followDistance = MELEE_MIN_DISTANCE;
                                switch (member->GetClass())
                                {
                                case Classes::CLASS_WARRIOR:
                                {
                                    break;
                                }
                                case Classes::CLASS_HUNTER:
                                {
                                    rs->followDistance = RANGED_NORMAL_DISTANCE;
                                    break;
                                }
                                case Classes::CLASS_SHAMAN:
                                {
                                    rs->followDistance = RANGED_NORMAL_DISTANCE;
                                    break;
                                }
                                case Classes::CLASS_PALADIN:
                                {
                                    if (Script_Paladin* sp = (Script_Paladin*)rs->sb)
                                    {
                                        switch (sp->blessingType)
                                        {
                                        case PaladinBlessingType::PaladinBlessingType_Kings:
                                        {
                                            if (paladinBlessing_kings)
                                            {
                                                if (!paladinBlessing_might)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Might;
                                                    paladinBlessing_might = true;
                                                }
                                                else if (!paladinBlessing_wisdom)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Wisdom;
                                                    paladinBlessing_wisdom = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinBlessing_kings = true;
                                            }
                                            break;
                                        }
                                        case PaladinBlessingType::PaladinBlessingType_Might:
                                        {
                                            if (paladinBlessing_might)
                                            {
                                                if (!paladinBlessing_kings)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Kings;
                                                    paladinBlessing_kings = true;
                                                }
                                                else if (!paladinBlessing_wisdom)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Wisdom;
                                                    paladinBlessing_wisdom = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinBlessing_might = true;
                                            }
                                            break;
                                        }
                                        case PaladinBlessingType::PaladinBlessingType_Wisdom:
                                        {
                                            if (paladinBlessing_wisdom)
                                            {
                                                if (!paladinBlessing_kings)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Kings;
                                                    paladinBlessing_kings = true;
                                                }
                                                else if (!paladinBlessing_might)
                                                {
                                                    sp->blessingType = PaladinBlessingType::PaladinBlessingType_Might;
                                                    paladinBlessing_might = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinBlessing_wisdom = true;
                                            }
                                            break;
                                        }
                                        default:
                                        {
                                            break;
                                        }
                                        }
                                        switch (sp->auraType)
                                        {
                                        case PaladinAuraType::PaladinAuraType_Concentration:
                                        {
                                            if (paladinAura_concentration)
                                            {
                                                if (!paladinAura_devotion)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Devotion;
                                                    paladinAura_devotion = true;
                                                }
                                                else if (!paladinAura_retribution)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Retribution;
                                                    paladinAura_retribution = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinAura_concentration = true;
                                            }
                                            break;
                                        }
                                        case PaladinAuraType::PaladinAuraType_Devotion:
                                        {
                                            if (paladinAura_devotion)
                                            {
                                                if (!paladinAura_concentration)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Concentration;
                                                    paladinAura_concentration = true;
                                                }
                                                else if (!paladinAura_retribution)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Retribution;
                                                    paladinAura_retribution = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinAura_devotion = true;
                                            }
                                            break;
                                        }
                                        case PaladinAuraType::PaladinAuraType_Retribution:
                                        {
                                            if (paladinAura_retribution)
                                            {
                                                if (!paladinAura_concentration)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Concentration;
                                                    paladinAura_concentration = true;
                                                }
                                                else if (!paladinAura_devotion)
                                                {
                                                    sp->auraType = PaladinAuraType::PaladinAuraType_Devotion;
                                                    paladinAura_devotion = true;
                                                }
                                            }
                                            else
                                            {
                                                paladinAura_retribution = true;
                                            }
                                            break;
                                        }
                                        default:
                                        {
                                            break;
                                        }
                                        }
                                    }
                                    break;
                                }
                                case Classes::CLASS_WARLOCK:
                                {
                                    rs->followDistance = RANGED_NORMAL_DISTANCE;
                                    break;
                                }
                                case Classes::CLASS_PRIEST:
                                {
                                    rs->followDistance = RANGED_NORMAL_DISTANCE;
                                    break;
                                }
                                case Classes::CLASS_ROGUE:
                                {
                                    break;
                                }
                                case Classes::CLASS_MAGE:
                                {
                                    rs->followDistance = RANGED_NORMAL_DISTANCE;
                                    break;
                                }
                                case Classes::CLASS_DRUID:
                                {
                                    break;
                                }
                                default:
                                {
                                    break;
                                }
                                }
                                if (rs->sb->characterType == RobotCharacterType::RobotCharacterType_TANK)
                                {
                                    if (!tank1Set)
                                    {
                                        member->groupRole = GroupRole_Ysondre::GroupRole_Ysondre_Tank1;
                                        tank1Set = true;
                                        continue;
                                    }
                                    else if (!tank2Set)
                                    {
                                        member->groupRole = GroupRole_Ysondre::GroupRole_Ysondre_Tank2;
                                        tank2Set = true;
                                        continue;
                                    }
                                }
                                else if (rs->sb->characterType == RobotCharacterType::RobotCharacterType_HEALER)
                                {
                                    if (healer1Count < 2)
                                    {
                                        member->groupRole = GroupRole_Ysondre::GroupRole_Ysondre_Healer1;
                                        healer1Count++;
                                        continue;
                                    }
                                    else if (healer2Count < 2)
                                    {
                                        member->groupRole = GroupRole_Ysondre::GroupRole_Ysondre_Healer2;
                                        healer2Count++;
                                        continue;
                                    }
                                }
                                member->groupRole = GroupRole_Ysondre::GroupRole_Ysondre_DPS_Range;
                            }
                        }
                    }
                    replyStream << "Arranged";
                    break;
                }
                default:
                {
                    replyStream << "Unknown strategy";
                    break;
                }
                }
            }
            else
            {
                replyStream << "You are not leader";
            }
        }
        else
        {
            replyStream << "Not in a group";
        }
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "position")
    {
        std::ostringstream replyStream;
        if (Group* myGroup = pmPlayer->GetGroup())
        {
            if (myGroup->GetLeaderGUID() == pmPlayer->GetGUID())
            {
                switch (pmPlayer->rai->activeStrategyIndex)
                {
                case Strategy_Index::Strategy_Index_Group:
                {
                    replyStream << "No position";
                    break;
                }
                case Strategy_Index::Strategy_Index_Group_Blackrock_Spire:
                {
                    replyStream << "No position";
                    break;
                }
                case Strategy_Index::Strategy_Index_Group_Shadow_Labyrinth:
                {
                    replyStream << "No position";
                    break;
                }
                case Strategy_Index::Strategy_Index_Group_Ysondre:
                {
                    Position tank1Pos;
                    Position tank2Pos;
                    Position memberPos1;
                    Position memberPos2;
                    std::unordered_map<uint32, Position> memberPosMap;

                    float checkX = 0.0f;
                    float checkY = 0.0f;
                    float checkZ = 0.0f;
                    pmPlayer->GetNearPoint(pmPlayer, checkX, checkY, checkZ, 3.0f, pmPlayer->GetOrientation());
                    tank1Pos.m_positionX = checkX;
                    tank1Pos.m_positionY = checkY;
                    tank1Pos.m_positionZ = checkZ;

                    pmPlayer->GetNearPoint(pmPlayer, checkX, checkY, checkZ, 3.0f, pmPlayer->GetOrientation() + M_PI);
                    tank2Pos.m_positionX = checkX;
                    tank2Pos.m_positionY = checkY;
                    tank2Pos.m_positionZ = checkZ;

                    pmPlayer->GetNearPoint(pmPlayer, checkX, checkY, checkZ, 20.0f, pmPlayer->GetOrientation());
                    memberPos1.m_positionX = checkX;
                    memberPos1.m_positionY = checkY;
                    memberPos1.m_positionZ = checkZ;

                    pmPlayer->GetNearPoint(pmPlayer, checkX, checkY, checkZ, 20.0f, pmPlayer->GetOrientation() + M_PI);
                    memberPos2.m_positionX = checkX;
                    memberPos2.m_positionY = checkY;
                    memberPos2.m_positionZ = checkZ;

                    uint32 member1Count = 0;
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        Player* member = groupRef->GetSource();
                        if (member)
                        {
                            if (!member->GetSession()->isRobotSession)
                            {
                                continue;
                            }
                            if (RobotStrategy_Group_Ysondre* rs = (RobotStrategy_Group_Ysondre*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                            {
                                switch (member->groupRole)
                                {
                                case GroupRole_Ysondre::GroupRole_Ysondre_Tank1:
                                {
                                    rs->engagePos = tank1Pos;
                                    break;
                                }
                                case GroupRole_Ysondre::GroupRole_Ysondre_Tank2:
                                {
                                    rs->engagePos = tank2Pos;
                                    break;
                                }
                                default:
                                {
                                    if (member1Count < 18)
                                    {
                                        rs->engagePos = memberPos1;
                                        member1Count++;
                                    }
                                    else
                                    {
                                        rs->engagePos = memberPos2;
                                    }
                                    break;
                                }
                                }
                                rs->positioned = true;
                            }
                        }
                    }
                    replyStream << "positioned";
                    break;
                }
                default:
                {
                    replyStream << "Unknown strategy";
                    break;
                }
                }
            }
            else
            {
                replyStream << "You are not leader";
            }
        }
        else
        {
            replyStream << "Not in a group";
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
            float minDistance = 5.0f;
            float maxDistance = 10.0f;
            if (commandVector.size() > 1)
            {
                minDistance = std::atof(commandVector.at(1).c_str());
                if (commandVector.size() > 2)
                {
                    maxDistance = std::atof(commandVector.at(2).c_str());
                }
            }
            pmPlayer->GetMotionMaster()->MoveChase(targetUnit, ChaseRange(minDistance, maxDistance));
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
        if (Unit* targetUnit = pmPlayer->GetSelectedUnit())
        {
            if (commandVector.size() > 1)
            {
                std::string auraCheckType = commandVector.at(1);
                if (commandVector.size() > 2)
                {
                    uint32 spellID = std::stoi(commandVector.at(2));
                    if (auraCheckType == "has")
                    {
                        if (targetUnit->HasAura(spellID))
                        {
                            replyStream << "Has aura : " << spellID;
                        }
                        else
                        {
                            replyStream << "No aura : " << spellID;
                        }
                    }
                    else if (auraCheckType == "add")
                    {
                        targetUnit->AddAura(spellID, targetUnit);
                        replyStream << "Aura added : " << spellID;
                    }
                    else if (auraCheckType == "remove")
                    {
                        targetUnit->RemoveAura(spellID);
                        replyStream << "Aura removed : " << spellID;
                    }
                    else
                    {
                        replyStream << "Unknown check type";
                    }
                }
                else
                {
                    replyStream << "No spell id";
                }
            }
            else
            {
                replyStream << "No type";
            }
        }
        else
        {
            replyStream << "No target";
        }
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, replyStream.str().c_str(), pmPlayer);
    }
    else if (commandName == "side")
    {
        if (Unit* targetUnit = pmPlayer->GetSelectedUnit())
        {
            pmPlayer->GetMotionMaster()->Clear();
            pmPlayer->StopMoving();
            if (pmPlayer->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
            {
                pmPlayer->SetStandState(UNIT_STAND_STATE_STAND);
            }
            if (pmPlayer->IsWalking())
            {
                pmPlayer->SetWalk(false);
            }
            float distance = pmPlayer->GetDistance(targetUnit);
            float destX = 0;
            float destY = 0;
            float destZ = 0;
            targetUnit->GetNearPoint(pmPlayer, destX, destY, destZ, distance, M_PI / 4 + targetUnit->GetAbsoluteAngle(pmPlayer->GetPosition()));
            pmPlayer->GetMotionMaster()->MovePoint(1, destX, destY, destZ, true, pmPlayer->GetAbsoluteAngle(targetUnit->GetPosition()));
            sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, "Move side", pmPlayer);
        }
    }
    else if (commandName == "lightwell")
    {
        std::ostringstream replyStream;
        bool canUse = true;
        for (std::unordered_set<uint32>::iterator lightwellIT = sRobotManager->lightwellRenewSpellIDSet.begin(); lightwellIT != sRobotManager->lightwellRenewSpellIDSet.end(); lightwellIT++)
        {
            uint32 eachLightwellID = *lightwellIT;
            if (pmPlayer->HasAura(eachLightwellID))
            {
                replyStream << "Already used";
                canUse = false;
                break;
            }
        }
        if (canUse)
        {
            std::list<Unit*> meleeRangeUnits;
            Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(pmPlayer, pmPlayer, NOMINAL_MELEE_RANGE);
            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(pmPlayer, meleeRangeUnits, u_check);
            Cell::VisitAllObjects(pmPlayer, searcher, NOMINAL_MELEE_RANGE);
            bool hasLightwell = false;
            for (std::list<Unit*>::iterator it = meleeRangeUnits.begin(); it != meleeRangeUnits.end(); it++)
            {
                if (Unit* eachU = *it)
                {
                    if (sRobotManager->lightwellUnitEntrySet.find(eachU->GetEntry()) != sRobotManager->lightwellUnitEntrySet.end())
                    {
                        hasLightwell = true;
                        eachU->HandleSpellClick(pmPlayer);
                        replyStream << "Using lightwell";
                        break;
                    }
                }
            }
            if (!hasLightwell)
            {
                replyStream << "No lightwell in range";
            }
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

void RobotManager::HandlePacket(WorldSession* pmSession, WorldPacket pmPacket)
{
    if (pmSession)
    {
        if (!pmSession->isRobotSession)
        {
            return;
        }
        if (Player* me = pmSession->GetPlayer())
        {
            if (!me->rai)
            {
                return;
            }
            switch (pmPacket.GetOpcode())
            {
            case SMSG_SPELL_FAILURE:
            {
                break;
            }
            case SMSG_SPELL_DELAYED:
            {
                break;
            }
            case SMSG_GROUP_INVITE:
            {
                Group* grp = me->GetGroupInvite();
                if (!grp)
                {
                    break;
                }
                Player* inviter = ObjectAccessor::FindPlayer(grp->GetLeaderGUID());
                if (!inviter)
                {
                    break;
                }
                if (RobotStrategy_Solo* rs = (RobotStrategy_Solo*)me->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Solo))
                {
                    if (rs->interestsDelay > 0)
                    {
                        WorldPacket p;
                        me->GetSession()->HandleGroupDeclineOpcode(p);
                        std::ostringstream timeLeftStream;
                        timeLeftStream << "Not interested. I will reconsider in " << rs->interestsDelay / 1000 << " seconds";
                        WhisperTo(me, timeLeftStream.str(), Language::LANG_UNIVERSAL, inviter);
                    }
                    else
                    {
                        if (inviter->GetLevel() < me->GetLevel())
                        {
                            WorldPacket p;
                            me->GetSession()->HandleGroupDeclineOpcode(p);
                            std::ostringstream timeLeftStream;
                            timeLeftStream << "Your level is low.";
                            WhisperTo(me, timeLeftStream.str(), Language::LANG_UNIVERSAL, inviter);
                        }
                        else
                        {
                            uint32 acceptInvite = urand(0, 3);
                            if (sRobotConfig->GroupInterest == 0)
                            {
                                acceptInvite = 0;
                            }
                            if (me->rai->robotType == RobotType::RobotType_Raid)
                            {
                                acceptInvite = 0;
                            }
                            if (acceptInvite == 0)
                            {
                                WorldPacket p;
                                uint32 roles_mask = 0;
                                p << roles_mask;
                                me->GetSession()->HandleGroupAcceptOpcode(p);
                                std::ostringstream replyStream_Talent;
                                replyStream_Talent << "My talent category is " << sRobotManager->characterTalentTabNameMap[me->GetClass()][rs->sb->characterTalentTab];
                                WhisperTo(me, replyStream_Talent.str(), Language::LANG_UNIVERSAL, inviter);
                                break;
                            }
                            else
                            {
                                rs->interestsDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
                                WorldPacket p;
                                me->GetSession()->HandleGroupDeclineOpcode(p);
                                std::ostringstream timeLeftStream;
                                timeLeftStream << "Not interested. I will reconsider in " << rs->interestsDelay / 1000 << " seconds";
                                WhisperTo(me, timeLeftStream.str(), Language::LANG_UNIVERSAL, inviter);
                                break;
                            }
                        }
                    }
                }
            }
            case BUY_ERR_NOT_ENOUGHT_MONEY:
            {
                break;
            }
            case BUY_ERR_REPUTATION_REQUIRE:
            {
                break;
            }
            case MSG_RAID_READY_CHECK:
            {
                if (RobotStrategy_Group* rs = (RobotStrategy_Group*)me->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                {
                    rs->readyCheckDelay = urand(2000, 6000);
                }
                break;
            }
            case SMSG_GROUP_SET_LEADER:
            {
                //std::string leaderName = "";
                //pmPacket >> leaderName;
                //Player* newLeader = ObjectAccessor::FindPlayerByName(leaderName);
                //if (newLeader)
                //{
                //    if (newLeader->GetGUID() == me->GetGUID())
                //    {
                //        WorldPacket data(CMSG_GROUP_SET_LEADER, 8);
                //        data << master->GetGUID().WriteAsPacked();
                //        me->GetSession()->HandleGroupSetLeaderOpcode(data);
                //    }
                //    else
                //    {
                //        if (!newLeader->isRobot)
                //        {
                //            master = newLeader;
                //        }
                //    }
                //}
                break;
            }
            case SMSG_FORCE_RUN_SPEED_CHANGE:
            {
                break;
            }
            case SMSG_RESURRECT_REQUEST:
            {
                if (me->IsResurrectRequested())
                {
                    me->ResurrectUsingRequestData();
                    if (RobotStrategy_Solo* rs = (RobotStrategy_Solo*)me->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Solo))
                    {
                        rs->deathDelay = 0;
                    }
                }
                break;
            }
            case SMSG_INVENTORY_CHANGE_FAILURE:
            {
                break;
            }
            case SMSG_TRADE_STATUS:
            {
                break;
            }
            case SMSG_LOOT_RESPONSE:
            {
                break;
            }
            case SMSG_QUESTUPDATE_ADD_KILL:
            {
                break;
            }
            case SMSG_ITEM_PUSH_RESULT:
            {
                break;
            }
            case SMSG_PARTY_COMMAND_RESULT:
            {
                break;
            }
            case SMSG_DUEL_REQUESTED:
            {
                if (!me->duel)
                {
                    break;
                }
                me->DuelComplete(DuelCompleteType::DUEL_INTERRUPTED);
                WhisperTo(me, "Not interested", Language::LANG_UNIVERSAL, me->duel->Opponent);
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
}

void RobotManager::WhisperTo(Player* pmSender, std::string pmContent, Language pmLanguage, Player* pmTarget)
{
    if (pmSender && pmTarget)
    {
        pmSender->Whisper(pmContent, pmLanguage, pmTarget);
    }
}

void RobotManager::HandleChatCommand(Player* pmSender, std::string pmCMD, Player* pmReceiver)
{
    if (!pmSender)
    {
        return;
    }
    if (pmReceiver)
    {
        if (!pmReceiver->GetSession()->isRobotSession)
        {
            return;
        }
    }
    std::vector<std::string> commandVector = sRobotManager->SplitString(pmCMD, " ", true);
    std::string commandName = commandVector.at(0);
    if (commandName == "role")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                Player* member = groupRef->GetSource();
                if (member)
                {
                    if (!member->GetSession()->isRobotSession)
                    {
                        continue;
                    }
                    if (pmReceiver)
                    {
                        if (pmReceiver->GetGUID() != member->GetGUID())
                        {
                            continue;
                        }
                    }
                    std::ostringstream replyStream;
                    if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                    {
                        if (commandVector.size() > 1)
                        {
                            std::string newRole = commandVector.at(1);
                            rs->SetGroupRole(newRole);
                        }
                        replyStream << "My group role is ";
                        replyStream << rs->GetGroupRoleName();
                    }
                    WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "follow")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            if (commandVector.size() > 1)
                            {
                                std::string cmdDistanceStr = commandVector.at(1);
                                float cmdDistance = atof(cmdDistanceStr.c_str());
                                if (cmdDistance == 0.0f)
                                {
                                    rs->following = false;
                                    continue;
                                }
                                else if (cmdDistance >= FOLLOW_MIN_DISTANCE && cmdDistance <= FOLLOW_MAX_DISTANCE)
                                {
                                    if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                                    {
                                        rs->followDistance = cmdDistance;
                                    }
                                }
                                else
                                {
                                    replyStream << "Distance is not valid";
                                }
                            }
                            if (member->IsAlive())
                            {
                                member->AttackStop();
                                member->StopMoving();
                                member->GetMotionMaster()->Clear();
                                if (member->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
                                {
                                    member->SetStandState(UNIT_STAND_STATE_STAND);
                                }
                                if (member->IsWalking())
                                {
                                    member->SetWalk(false);
                                }
                                rs->sb->ClearTarget();
                                rs->restDelay = 0;
                                rs->staying = false;
                                rs->holding = false;
                                rs->marking = false;
                                rs->following = true;
                                rs->sb->ChooseTarget(pmSender);
                                member->GetMotionMaster()->MoveChase(pmSender, ChaseRange(0.0f, rs->followDistance));
                                replyStream << "Following " << rs->followDistance;
                            }
                            else
                            {
                                replyStream << "I am dead";
                            }
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "stay")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (member->IsAlive())
                        {
                            member->StopMoving();
                            member->GetMotionMaster()->Clear();
                            member->AttackStop();
                            member->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
                            if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                            {
                                rs->sb->PetStop();
                                rs->staying = true;
                            }
                            replyStream << "Staying";
                        }
                        else
                        {
                            replyStream << "I am dead";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "hold")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (member->IsAlive())
                        {
                            member->StopMoving();
                            member->GetMotionMaster()->Clear();
                            if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                            {
                                rs->marking = false;
                                rs->staying = false;
                                rs->holding = true;
                            }
                            replyStream << "Holding";
                        }
                        else
                        {
                            replyStream << "I am dead";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "engage")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                if (Unit* target = pmSender->GetSelectedUnit())
                {
                    if (target->IsAlive())
                    {
                        for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                        {
                            Player* member = groupRef->GetSource();
                            if (member)
                            {
                                if (!member->GetSession()->isRobotSession)
                                {
                                    continue;
                                }
                                if (pmReceiver)
                                {
                                    if (pmReceiver->GetGUID() != member->GetGUID())
                                    {
                                        continue;
                                    }
                                }
                                if (member->IsAlive())
                                {
                                    if (member->IsValidAttackTarget(target))
                                    {
                                        if (member->GetDistance(target) < ATTACK_RANGE_LIMIT)
                                        {
                                            member->AttackStop();
                                            member->StopMoving();
                                            member->GetMotionMaster()->Clear();
                                            if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                                            {
                                                rs->staying = false;
                                                rs->sb->ClearTarget();
                                                rs->sb->ChooseTarget(target);
                                                if (rs->Engage(target))
                                                {
                                                    rs->engageTarget = target;
                                                    int engageDelay = 5000;
                                                    if (commandVector.size() > 1)
                                                    {
                                                        std::string checkStr = commandVector.at(1);
                                                        engageDelay = atoi(checkStr.c_str());
                                                    }
                                                    rs->engageDelay = engageDelay;
                                                    std::ostringstream replyStream;
                                                    replyStream << "Try to engage " << target->GetName();
                                                    WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (commandName == "rest")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (member->IsAlive())
                        {
                            if (RobotStrategy* rs = member->rai->GetActiveStrategy())
                            {
                                if (rs->sb->Rest())
                                {
                                    int checkDelay = DEFAULT_REST_DELAY;
                                    if (commandVector.size() > 1)
                                    {
                                        std::string checkStr = commandVector.at(1);
                                        checkDelay = atoi(checkStr.c_str());
                                    }
                                    rs->restDelay = checkDelay;
                                    replyStream << "Resting";
                                }
                                else
                                {
                                    replyStream << "Can not rest";
                                }
                            }
                        }
                        else
                        {
                            replyStream << "I am dead";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "who")
    {
        if (pmReceiver)
        {
            if (RobotStrategy* rs = pmReceiver->rai->GetActiveStrategy())
            {
                WhisperTo(pmReceiver, sRobotManager->characterTalentTabNameMap[pmReceiver->GetClass()][rs->sb->characterTalentTab], Language::LANG_UNIVERSAL, pmSender);
            }
        }
        else
        {
            if (Group* checkGroup = pmSender->GetGroup())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (RobotStrategy* rs = member->rai->GetActiveStrategy())
                        {
                            WhisperTo(member, sRobotManager->characterTalentTabNameMap[member->GetClass()][rs->sb->characterTalentTab], Language::LANG_UNIVERSAL, pmSender);
                        }
                    }
                }
            }
        }
    }
    else if (commandName == "assemble")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                std::string memberType = "all";
                if (commandVector.size() > 1)
                {
                    memberType = commandVector.at(1);
                }
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        if (memberType == "melee")
                        {
                            if (member->GetClass() != Classes::CLASS_DRUID && member->GetClass() != Classes::CLASS_PALADIN && member->GetClass() != Classes::CLASS_ROGUE && member->GetClass() != Classes::CLASS_WARRIOR)
                            {
                                continue;
                            }
                        }
                        else if (memberType == "range")
                        {
                            if (member->GetClass() != Classes::CLASS_HUNTER && member->GetClass() != Classes::CLASS_MAGE && member->GetClass() != Classes::CLASS_PRIEST && member->GetClass() != Classes::CLASS_SHAMAN && member->GetClass() != Classes::CLASS_WARLOCK)
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            if (rs->moveDelay > 0 || rs->teleportAssembleDelay > 0)
                            {
                                replyStream << "I am on the way";
                            }
                            else
                            {
                                if (member->IsAlive())
                                {
                                    if (member->GetDistance(pmSender) < sRobotConfig->AssembleTeleportMinRange)
                                    {
                                        rs->moveDelay = 5000;
                                        replyStream << "We are close, I will move to you";
                                        member->GetMotionMaster()->Clear();
                                        member->StopMoving();
                                        if (member->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
                                        {
                                            member->SetStandState(UNIT_STAND_STATE_STAND);
                                        }
                                        if (member->IsWalking())
                                        {
                                            member->SetWalk(false);
                                        }
                                        rs->restDelay = 0;
                                        member->GetMotionMaster()->MovePoint(1, pmSender->GetPosition(), true, pmSender->GetOrientation());
                                    }
                                    else
                                    {
                                        rs->teleportAssembleDelay = 1 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS;
                                        replyStream << "I will join you in 1 minute";
                                    }
                                }
                                else
                                {
                                    rs->teleportAssembleDelay = 2 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS;
                                    replyStream << "I will revive and join you in 2 minutes";
                                }
                            }
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "tank")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                if (Unit* target = pmSender->GetSelectedUnit())
                {
                    if (target->IsAlive())
                    {
                        for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                        {
                            Player* member = groupRef->GetSource();
                            if (member)
                            {
                                if (!member->GetSession()->isRobotSession)
                                {
                                    continue;
                                }
                                if (pmReceiver)
                                {
                                    if (pmReceiver->GetGUID() != member->GetGUID())
                                    {
                                        continue;
                                    }
                                }
                                if (member->IsAlive())
                                {
                                    if (member->IsValidAttackTarget(target))
                                    {
                                        if (member->GetDistance(target) < ATTACK_RANGE_LIMIT)
                                        {
                                            member->AttackStop();
                                            member->StopMoving();
                                            member->GetMotionMaster()->Clear();
                                            if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                                            {
                                                if (rs->Tank(target))
                                                {
                                                    rs->staying = false;
                                                    rs->engageTarget = target;
                                                    int engageDelay = 5000;
                                                    if (commandVector.size() > 1)
                                                    {
                                                        std::string checkStr = commandVector.at(1);
                                                        engageDelay = atoi(checkStr.c_str());
                                                    }
                                                    rs->engageDelay = engageDelay;
                                                    std::ostringstream replyStream;
                                                    replyStream << "Try to tank " << target->GetName();
                                                    WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (commandName == "switch")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (member->GetClass() == Classes::CLASS_WARLOCK || member->GetClass() == Classes::CLASS_HUNTER)
                        {
                            if (Pet* checkPet = member->GetPet())
                            {
                                if (commandVector.size() > 1)
                                {
                                    std::string autoState = commandVector.at(1);
                                    if (commandVector.size() > 2)
                                    {
                                        std::ostringstream spellNameStream;
                                        uint32 checkPos = 2;
                                        while (checkPos < commandVector.size())
                                        {
                                            spellNameStream << commandVector.at(checkPos) << " ";
                                            checkPos++;
                                        }
                                        std::string spellName = sRobotManager->TrimString(spellNameStream.str());
                                        std::unordered_map<uint32, PetSpell> petSpellMap = checkPet->m_spells;
                                        for (std::unordered_map<uint32, PetSpell>::iterator it = petSpellMap.begin(); it != petSpellMap.end(); it++)
                                        {
                                            if (it->second.active == ACT_DISABLED || it->second.active == ACT_ENABLED)
                                            {
                                                const SpellInfo* pST = sSpellMgr->GetSpellInfo(it->first);
                                                if (pST)
                                                {
                                                    std::string checkNameStr = std::string(pST->SpellName[0]);
                                                    if (checkNameStr == spellName)
                                                    {
                                                        std::ostringstream replyStream;
                                                        if (autoState == "on")
                                                        {
                                                            checkPet->ToggleAutocast(pST, true);
                                                            replyStream << "Switched " << spellName << " on";
                                                        }
                                                        else if (autoState == "off")
                                                        {
                                                            checkPet->ToggleAutocast(pST, false);
                                                            replyStream << "Switched " << spellName << " off";
                                                        }
                                                        else
                                                        {
                                                            replyStream << "Wrong auto state";
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        replyStream << "Spell not found";
                                    }
                                    else
                                    {
                                        replyStream << "Spell name missing";
                                    }
                                }
                                else
                                {
                                    replyStream << "No auto state";
                                }
                            }
                            else
                            {
                                replyStream << "I do not have an active pet";
                            }
                        }
                        else
                        {
                            replyStream << "I am not a hunter or a warlock";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "cast")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (member->IsAlive())
                        {
                            if (commandVector.size() > 1)
                            {
                                std::ostringstream targetStream;
                                uint8 arrayCount = 0;
                                for (std::vector<std::string>::iterator it = commandVector.begin(); it != commandVector.end(); it++)
                                {
                                    if (arrayCount > 0)
                                    {
                                        targetStream << (*it) << " ";
                                    }
                                    arrayCount++;
                                }
                                std::string spellName = sRobotManager->TrimString(targetStream.str());
                                if (Unit* senderTarget = pmSender->GetSelectedUnit())
                                {
                                    if (RobotStrategy* rs = member->rai->GetActiveStrategy())
                                    {
                                        if (rs->sb->CastSpell(senderTarget, spellName))
                                        {
                                            replyStream << "Cast spell " << spellName << " on " << senderTarget->GetName();
                                        }
                                        else
                                        {
                                            replyStream << "Can not cast spell " << spellName << " on " << senderTarget->GetName();
                                        }
                                    }
                                }
                                else
                                {
                                    replyStream << "No target";
                                }
                            }
                        }
                        else
                        {
                            replyStream << "I am dead";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "cancel")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (member->IsAlive())
                        {
                            if (commandVector.size() > 1)
                            {
                                std::ostringstream targetStream;
                                uint8 arrayCount = 0;
                                for (std::vector<std::string>::iterator it = commandVector.begin(); it != commandVector.end(); it++)
                                {
                                    if (arrayCount > 0)
                                    {
                                        targetStream << (*it) << " ";
                                    }
                                    arrayCount++;
                                }
                                std::string spellName = sRobotManager->TrimString(targetStream.str());
                                if (RobotStrategy* rs = member->rai->GetActiveStrategy())
                                {
                                    if (rs->sb->CancelAura(spellName))
                                    {
                                        replyStream << "Aura canceled " << spellName;
                                    }
                                    else
                                    {
                                        replyStream << "Can not cancel aura " << spellName;
                                    }
                                }
                            }
                        }
                        else
                        {
                            replyStream << "I am dead";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "use")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (member->IsAlive())
                        {
                            if (commandVector.size() > 1)
                            {
                                std::string useType = commandVector.at(1);
                                if (useType == "go")
                                {
                                    if (commandVector.size() > 2)
                                    {
                                        std::ostringstream goNameStream;
                                        uint32 checkPos = 2;
                                        while (checkPos < commandVector.size())
                                        {
                                            goNameStream << commandVector.at(checkPos) << " ";
                                            checkPos++;
                                        }
                                        std::string goName = sRobotManager->TrimString(goNameStream.str());
                                        bool validToUse = false;
                                        std::list<GameObject*> nearGOList;
                                        Trinity::GameObjectInRangeCheck check(member->GetPositionX(), member->GetPositionY(), member->GetPositionZ(), MELEE_MAX_DISTANCE);
                                        Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(member, nearGOList, check);
                                        Cell::VisitGridObjects(member, searcher, SIZE_OF_GRIDS);
                                        for (std::list<GameObject*>::iterator it = nearGOList.begin(); it != nearGOList.end(); it++)
                                        {
                                            if ((*it)->GetName() == goName)
                                            {
                                                member->SetFacingToObject((*it));
                                                member->StopMoving();
                                                member->GetMotionMaster()->Clear();
                                                (*it)->Use(member);
                                                replyStream << "Use game object : " << goName;
                                                validToUse = true;
                                                break;
                                            }
                                        }
                                        if (!validToUse)
                                        {
                                            replyStream << "No go with name " << goName << " nearby";
                                        }
                                    }
                                    else
                                    {
                                        replyStream << "No go name";
                                    }
                                }
                                else if (useType == "item")
                                {

                                }
                                else
                                {
                                    replyStream << "Unknown type";
                                }
                            }
                            else
                            {
                                replyStream << "Use what?";
                            }
                        }
                        else
                        {
                            replyStream << "I am dead";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "stop")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (member->IsAlive())
                        {
                            member->StopMoving();
                            member->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                            member->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                            member->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                            member->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                            replyStream << "Stopped";
                        }
                        else
                        {
                            replyStream << "I am dead";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "delay")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (commandVector.size() > 1)
                        {
                            std::string delayType = commandVector.at(1);
                            if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                            {
                                if (commandVector.size() > 2)
                                {
                                    int delayMS = std::stoi(commandVector.at(2));
                                    if (delayType == "dps")
                                    {
                                        rs->dpsDelay = delayMS;
                                        replyStream << "DPS delay set to : " << delayMS;
                                    }
                                    else if (delayType == "aoe")
                                    {
                                        rs->aoeDelay = delayMS;
                                        replyStream << "AOE delay set to : " << delayMS;
                                    }
                                    else
                                    {
                                        replyStream << "Unknown type";
                                    }
                                }
                                else
                                {
                                    if (delayType == "dps")
                                    {
                                        replyStream << "DPS delay is : " << rs->dpsDelay;
                                    }
                                    else if (delayType == "aoe")
                                    {
                                        replyStream << "AOE delay is : " << rs->aoeDelay;
                                    }
                                    else
                                    {
                                        replyStream << "Unknown type";
                                    }
                                }
                            }
                        }
                        else
                        {
                            replyStream << "Missing type";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "threat")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (member->IsAlive())
                        {
                            replyStream << "Threat list : ";
                            for (auto& pair : member->GetThreatManager().GetThreatenedByMeList())
                            {
                                replyStream << pair.second->GetOwner()->GetName() << ", ";
                            }
                        }
                        else
                        {
                            replyStream << "I am dead";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "revive")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                std::unordered_map<uint32, Player*> deadMap;
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    if (Player* member = groupRef->GetSource())
                    {
                        if (!member->IsAlive())
                        {
                            deadMap[deadMap.size()] = member;
                        }
                    }
                }
                if (deadMap.size() > 0)
                {
                    uint32 reviveIndex = 0;
                    for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        Player* member = groupRef->GetSource();
                        if (member)
                        {
                            if (!member->GetSession()->isRobotSession)
                            {
                                continue;
                            }
                            if (pmReceiver)
                            {
                                if (pmReceiver->GetGUID() != member->GetGUID())
                                {
                                    continue;
                                }
                            }
                            std::ostringstream replyStream;
                            if (member->IsAlive())
                            {
                                std::ostringstream reviveSpellName;
                                if (member->GetClass() == Classes::CLASS_DRUID || member->GetClass() == Classes::CLASS_PRIEST || member->GetClass() == Classes::CLASS_PALADIN)
                                {
                                    if (member->GetClass() == Classes::CLASS_DRUID)
                                    {
                                        reviveSpellName << "Revive";
                                    }
                                    else if (member->GetClass() == Classes::CLASS_PRIEST)
                                    {
                                        reviveSpellName << "Resurrection";
                                    }
                                    else if (member->GetClass() == Classes::CLASS_PALADIN)
                                    {
                                        reviveSpellName << "Redemption";
                                    }
                                    if (deadMap.find(reviveIndex) == deadMap.end())
                                    {
                                        break;
                                    }
                                    if (RobotStrategy* rs = member->rai->GetActiveStrategy())
                                    {
                                        if (rs->sb->CastSpell(deadMap[reviveIndex], reviveSpellName.str(), RANGED_MAX_DISTANCE, false, false, true))
                                        {
                                            replyStream << "Reviving " << deadMap[reviveIndex]->GetName();
                                            reviveIndex++;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                replyStream << "I am dead";
                            }
                            WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                        }
                    }
                }
            }
        }
    }
    else if (commandName == "cure")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            if (commandVector.size() > 1)
                            {
                                std::string cureCMD = commandVector.at(1);
                                if (cureCMD == "on")
                                {
                                    rs->cure = true;
                                }
                                else if (cureCMD == "off")
                                {
                                    rs->cure = false;
                                }
                                else
                                {
                                    replyStream << "Unknown state";
                                }
                            }
                            if (rs->cure)
                            {
                                replyStream << "Auto cure is on";
                            }
                            else
                            {
                                replyStream << "Auto cure is off";
                            }
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "emote")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (member->IsAlive())
                        {
                            if (commandVector.size() > 1)
                            {
                                int emoteCMD = std::stoi(commandVector.at(1));
                                member->HandleEmoteCommand(emoteCMD);
                            }
                            else
                            {
                                member->AttackStop();
                                member->CombatStop();
                            }
                        }
                        else
                        {
                            replyStream << "I am dead";
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "strategy")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;

                        if (commandVector.size() > 1)
                        {
                            std::ostringstream targetStream;
                            uint8 arrayCount = 0;
                            for (std::vector<std::string>::iterator it = commandVector.begin(); it != commandVector.end(); it++)
                            {
                                if (arrayCount > 0)
                                {
                                    targetStream << (*it) << " ";
                                }
                                arrayCount++;
                            }
                            std::string strategyName = sRobotManager->TrimString(targetStream.str());
                            if (strategyName == "group")
                            {
                                member->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Group;
                                replyStream << "Strategy set to group";
                            }
                            else if (strategyName == "blackrock spire")
                            {
                                member->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Group_Blackrock_Spire;
                                replyStream << "Strategy set to blackrock spire";
                            }
                            else if (strategyName == "shadow labyrinth")
                            {
                                member->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Group_Shadow_Labyrinth;
                                replyStream << "Strategy set to shadow labyrinth";
                            }
                            else if (strategyName == "ysondre")
                            {
                                member->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Group_Ysondre;
                                replyStream << "Strategy set to ysondre";
                            }
                            else
                            {
                                replyStream << "Unknown strategy";
                            }
                        }
                        else
                        {
                            switch (member->rai->activeStrategyIndex)
                            {
                            case Strategy_Index::Strategy_Index_Group:
                            {
                                replyStream << "Strategy is group";
                                break;
                            }
                            case Strategy_Index::Strategy_Index_Group_Blackrock_Spire:
                            {
                                replyStream << "Strategy is blackrock spire";
                                break;
                            }
                            case Strategy_Index::Strategy_Index_Group_Shadow_Labyrinth:
                            {
                                replyStream << "Strategy is shadow labyrinth";
                                break;
                            }
                            case Strategy_Index::Strategy_Index_Group_Ysondre:
                            {
                                replyStream << "Strategy is ysondre";
                                break;
                            }
                            default:
                            {
                                replyStream << "Strategy is unknown";
                                break;
                            }
                            }
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "side")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                if (Unit* target = pmSender->GetSelectedUnit())
                {
                    std::string memberType = "all";
                    if (commandVector.size() > 1)
                    {
                        memberType = commandVector.at(1);
                    }
                    for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        Player* member = groupRef->GetSource();
                        if (member)
                        {
                            if (!member->GetSession()->isRobotSession)
                            {
                                continue;
                            }
                            if (pmReceiver)
                            {
                                if (pmReceiver->GetGUID() != member->GetGUID())
                                {
                                    continue;
                                }
                            }
                            if (memberType == "melee")
                            {
                                if (member->GetClass() != Classes::CLASS_DRUID && member->GetClass() != Classes::CLASS_PALADIN && member->GetClass() != Classes::CLASS_ROGUE && member->GetClass() != Classes::CLASS_WARRIOR)
                                {
                                    continue;
                                }
                            }
                            else if (memberType == "range")
                            {
                                if (member->GetClass() != Classes::CLASS_HUNTER && member->GetClass() != Classes::CLASS_MAGE && member->GetClass() != Classes::CLASS_PRIEST && member->GetClass() != Classes::CLASS_SHAMAN && member->GetClass() != Classes::CLASS_WARLOCK)
                                {
                                    continue;
                                }
                            }
                            std::ostringstream replyStream;
                            if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                            {
                                if (rs->moveDelay > 0 || rs->teleportAssembleDelay > 0)
                                {
                                    replyStream << "I am on the way";
                                }
                                else
                                {
                                    if (member->IsAlive())
                                    {
                                        rs->moveDelay = 1000;
                                        replyStream << "Move side";
                                        member->GetMotionMaster()->Clear();
                                        member->StopMoving();
                                        float distance = member->GetDistance(target);
                                        float destX = 0;
                                        float destY = 0;
                                        float destZ = 0;
                                        target->GetNearPoint(member, destX, destY, destZ, distance, M_PI / 4 + target->GetAbsoluteAngle(member->GetPosition()));
                                        if (member->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
                                        {
                                            member->SetStandState(UNIT_STAND_STATE_STAND);
                                        }
                                        if (member->IsWalking())
                                        {
                                            member->SetWalk(false);
                                        }
                                        member->GetMotionMaster()->MovePoint(1, destX, destY, destZ, true, member->GetAbsoluteAngle(target->GetPosition()));
                                    }
                                    else
                                    {
                                        replyStream << "I am dead";
                                    }
                                }
                            }
                            WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                        }
                    }
                }
            }
        }
    }
    else if (commandName == "forward")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                std::string memberType = "all";
                if (commandVector.size() > 1)
                {
                    memberType = commandVector.at(1);
                }
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        if (memberType == "melee")
                        {
                            if (member->GetClass() != Classes::CLASS_DRUID && member->GetClass() != Classes::CLASS_PALADIN && member->GetClass() != Classes::CLASS_ROGUE && member->GetClass() != Classes::CLASS_WARRIOR)
                            {
                                continue;
                            }
                        }
                        else if (memberType == "range")
                        {
                            if (member->GetClass() != Classes::CLASS_HUNTER && member->GetClass() != Classes::CLASS_MAGE && member->GetClass() != Classes::CLASS_PRIEST && member->GetClass() != Classes::CLASS_SHAMAN && member->GetClass() != Classes::CLASS_WARLOCK)
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            if (rs->moveDelay > 0 || rs->teleportAssembleDelay > 0)
                            {
                                replyStream << "I am on the way";
                            }
                            else
                            {
                                if (member->IsAlive())
                                {
                                    rs->moveDelay = 1000;
                                    replyStream << "Move forward";
                                    member->GetMotionMaster()->Clear();
                                    member->StopMoving();
                                    float distance = 10.0f;
                                    float destX = 0;
                                    float destY = 0;
                                    float destZ = 0;
                                    member->GetNearPoint(member, destX, destY, destZ, distance, pmSender->GetOrientation());
                                    if (member->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
                                    {
                                        member->SetStandState(UNIT_STAND_STATE_STAND);
                                    }
                                    if (member->IsWalking())
                                    {
                                        member->SetWalk(false);
                                    }
                                    member->GetMotionMaster()->MovePoint(1, destX, destY, destZ, true, member->GetOrientation());
                                }
                                else
                                {
                                    replyStream << "I am dead";
                                }
                            }
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "back")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                std::string memberType = "all";
                if (commandVector.size() > 1)
                {
                    memberType = commandVector.at(1);
                }
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        if (memberType == "melee")
                        {
                            if (member->GetClass() != Classes::CLASS_DRUID && member->GetClass() != Classes::CLASS_PALADIN && member->GetClass() != Classes::CLASS_ROGUE && member->GetClass() != Classes::CLASS_WARRIOR)
                            {
                                continue;
                            }
                        }
                        else if (memberType == "range")
                        {
                            if (member->GetClass() != Classes::CLASS_HUNTER && member->GetClass() != Classes::CLASS_MAGE && member->GetClass() != Classes::CLASS_PRIEST && member->GetClass() != Classes::CLASS_SHAMAN && member->GetClass() != Classes::CLASS_WARLOCK)
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            if (rs->moveDelay > 0 || rs->teleportAssembleDelay > 0)
                            {
                                replyStream << "I am on the way";
                            }
                            else
                            {
                                if (member->IsAlive())
                                {
                                    rs->moveDelay = 1000;
                                    replyStream << "Move back";
                                    member->GetMotionMaster()->Clear();
                                    member->StopMoving();
                                    float distance = 10.0f;
                                    float destX = 0;
                                    float destY = 0;
                                    float destZ = 0;
                                    member->GetNearPoint(member, destX, destY, destZ, distance, pmSender->GetOrientation() + M_PI);
                                    if (member->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
                                    {
                                        member->SetStandState(UNIT_STAND_STATE_STAND);
                                    }
                                    if (member->IsWalking())
                                    {
                                        member->SetWalk(false);
                                    }
                                    member->GetMotionMaster()->MovePoint(1, destX, destY, destZ, true, member->GetOrientation());
                                }
                                else
                                {
                                    replyStream << "I am dead";
                                }
                            }
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "lightwell")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        if (member->GetClass() == Classes::CLASS_PRIEST)
                        {
                            if (member->rai->GetActiveStrategy()->sb->CastSpell(member, "Lightwell", NOMINAL_MELEE_RANGE))
                            {
                                continue;
                            }
                        }
                        std::ostringstream replyStream;
                        bool canUse = true;
                        for (std::unordered_set<uint32>::iterator lightwellIT = sRobotManager->lightwellRenewSpellIDSet.begin(); lightwellIT != sRobotManager->lightwellRenewSpellIDSet.end(); lightwellIT++)
                        {
                            uint32 eachLightwellID = *lightwellIT;
                            if (member->HasAura(eachLightwellID))
                            {
                                replyStream << "Already used";
                                canUse = false;
                                break;
                            }
                        }
                        if (canUse)
                        {
                            std::list<Unit*> meleeRangeUnits;
                            Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(member, member, NOMINAL_MELEE_RANGE);
                            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(member, meleeRangeUnits, u_check);
                            Cell::VisitAllObjects(member, searcher, NOMINAL_MELEE_RANGE);
                            bool hasLightwell = false;
                            for (std::list<Unit*>::iterator it = meleeRangeUnits.begin(); it != meleeRangeUnits.end(); it++)
                            {
                                if (Unit* eachU = *it)
                                {
                                    if (sRobotManager->lightwellUnitEntrySet.find(eachU->GetEntry()) != sRobotManager->lightwellUnitEntrySet.end())
                                    {
                                        hasLightwell = true;
                                        eachU->HandleSpellClick(member);
                                        replyStream << "Using lightwell";
                                        break;
                                    }
                                }
                            }
                            if (!hasLightwell)
                            {
                                replyStream << "No lightwell in range";
                            }
                        }
                        WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                    }
                }
            }
        }
    }
    else if (commandName == "pa")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        if (member->GetClass() == Classes::CLASS_PALADIN)
                        {
                            std::ostringstream replyStream;
                            if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                            {
                                if (Script_Paladin* sp = (Script_Paladin*)rs->sb)
                                {
                                    if (commandVector.size() > 1)
                                    {
                                        std::string auratypeName = commandVector.at(1);
                                        if (auratypeName == "concentration")
                                        {
                                            sp->auraType = PaladinAuraType::PaladinAuraType_Concentration;
                                        }
                                        else if (auratypeName == "devotion")
                                        {
                                            sp->auraType = PaladinAuraType::PaladinAuraType_Devotion;
                                        }
                                        else if (auratypeName == "retribution")
                                        {
                                            sp->auraType = PaladinAuraType::PaladinAuraType_Retribution;
                                        }
                                        else
                                        {
                                            replyStream << "Unknown type";
                                        }
                                    }
                                    switch (sp->auraType)
                                    {
                                    case PaladinAuraType::PaladinAuraType_Concentration:
                                    {
                                        replyStream << "concentration";
                                        break;
                                    }
                                    case PaladinAuraType::PaladinAuraType_Devotion:
                                    {
                                        replyStream << "devotion";
                                        break;
                                    }
                                    case PaladinAuraType::PaladinAuraType_Retribution:
                                    {
                                        replyStream << "retribution";
                                        break;
                                    }
                                    default:
                                    {
                                        break;
                                    }
                                    }
                                }
                            }
                            WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                        }
                    }
                }
            }
        }
    }
    else if (commandName == "pb")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        if (member->GetClass() == Classes::CLASS_PALADIN)
                        {
                            std::ostringstream replyStream;
                            if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                            {
                                if (Script_Paladin* sp = (Script_Paladin*)rs->sb)
                                {
                                    if (commandVector.size() > 1)
                                    {
                                        std::string blessingtypeName = commandVector.at(1);
                                        if (blessingtypeName == "kings")
                                        {
                                            sp->blessingType = PaladinBlessingType::PaladinBlessingType_Kings;
                                        }
                                        else if (blessingtypeName == "might")
                                        {
                                            sp->blessingType = PaladinBlessingType::PaladinBlessingType_Might;
                                        }
                                        else if (blessingtypeName == "wisdom")
                                        {
                                            sp->blessingType = PaladinBlessingType::PaladinBlessingType_Wisdom;
                                        }
                                        else
                                        {
                                            replyStream << "Unknown type";
                                        }
                                    }
                                    switch (sp->blessingType)
                                    {
                                    case PaladinBlessingType::PaladinBlessingType_Kings:
                                    {
                                        replyStream << "kings";
                                        break;
                                    }
                                    case PaladinBlessingType::PaladinBlessingType_Might:
                                    {
                                        replyStream << "might";
                                        break;
                                    }
                                    case PaladinBlessingType::PaladinBlessingType_Wisdom:
                                    {
                                        replyStream << "wisdom";
                                        break;
                                    }
                                    default:
                                    {
                                        break;
                                    }
                                    }
                                }
                            }
                            WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                        }
                    }
                }
            }
        }
    }
    else if (commandName == "marks")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        if (RobotStrategy_Group_Ysondre* rs = (RobotStrategy_Group_Ysondre*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            if (rs->positioned)
                            {
                                member->GetMotionMaster()->Clear();
                                member->StopMoving();
                                if (member->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
                                {
                                    member->SetStandState(UNIT_STAND_STATE_STAND);
                                }
                                if (member->IsWalking())
                                {
                                    member->SetWalk(false);
                                }
                                rs->restDelay = 0;
                                rs->marking = true;
                                member->GetMotionMaster()->MovePoint(1, rs->engagePos, true, member->GetRelativeAngle(pmSender->GetPosition()));
                            }
                            else
                            {
                                std::ostringstream replyStream;
                                replyStream << "Not positioned";
                                WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (commandName == "petting")
    {
        if (Group* checkGroup = pmSender->GetGroup())
        {
            if (checkGroup->GetLeaderGUID() == pmSender->GetGUID())
            {
                for (GroupReference* groupRef = checkGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member)
                    {
                        if (!member->GetSession()->isRobotSession)
                        {
                            continue;
                        }
                        if (pmReceiver)
                        {
                            if (pmReceiver->GetGUID() != member->GetGUID())
                            {
                                continue;
                            }
                        }
                        if (RobotStrategy_Group* rs = (RobotStrategy_Group*)member->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            if (commandVector.size() > 1)
                            {
                                std::string pettingStatus = commandVector.at(1);
                                if (pettingStatus == "on")
                                {
                                    rs->sb->petting = true;
                                }
                                else if (pettingStatus == "off")
                                {
                                    rs->sb->petting = false;
                                }
                            }
                            std::ostringstream replyStream;
                            if (rs->sb->petting)
                            {
                                replyStream << "petting is on";
                            }
                            else
                            {
                                replyStream << "petting is off";
                            }
                            WhisperTo(member, replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                        }
                    }
                }
            }
        }
    }
}

bool RobotManager::UnitTargetReachable(Player* pmCheckPlayer, Unit* pmTarget)
{
    PathGenerator path(pmCheckPlayer);
    bool pathResult = path.CalculatePath(pmTarget->GetPositionX(), pmTarget->GetPositionY(), pmTarget->GetPositionZ());
    if (!pathResult)
    {
        return false;
    }
    else if (path.GetPathType() & PATHFIND_NOPATH)
    {
        return false;
    }
    return true;
}
