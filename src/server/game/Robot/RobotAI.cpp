#include "RobotAI.h"

#include "Item.h"
#include "Bag.h"
#include "ObjectAccessor.h"
#include "RobotManager.h"
#include "Spell.h"
#include "Chat.h"
#include "SpellInfo.h"
#include "SpellHistory.h"
#include "Pet.h"
#include "SpellMgr.h"
#include "Player.h"
#include "Map.h"
#include "MapManager.h"
#include "Group.h"
#include "MotionMaster.h"
#include "AccountMgr.h"
#include "CharacterCache.h"
#include "PlayerAI.h"

#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ChaseMovementGenerator.h"

#include "RobotManager.h"
#include "Strategy_Group_Normal.h"
#include "Strategy_Solo_Normal.h"
#include "Script_Base.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"

#include "RobotConfig.h"

RobotAI::RobotAI(uint32 pmTargetLevel, uint32 pmTargetClass, uint32 pmTargetRace)
{
    realPrevTime = 0;
    strategiesMap.clear();
    strategiesMap["solo_normal"] = true;
    strategiesMap["group_normal"] = false;
    characterTalentTab = 0;


    realPrevTime = 0;

    targetLevel = pmTargetLevel;
    targetClass = pmTargetClass;
    targetRace = pmTargetRace;

    std::ostringstream accountNameStream;
    accountNameStream << sRobotConfig->RobotAccountNamePrefix << "l" << std::to_string(targetLevel) << "r" << std::to_string(targetRace) << "c" << std::to_string(targetClass);
    accountName = accountNameStream.str();

    accountID = 0;
    characterGUID = ObjectGuid::Empty;
    masterGUID = ObjectGuid::Empty;
    characterType = 0;

    checkDelay = urand(TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);

    // EJ debug 
    //checkDelay = 30 * TimeConstants::IN_MILLISECONDS;

    onlineDelay = 0;
    offlineDelay = 0;
    restDelay = 0;

    robotState = RobotState::RobotState_OffLine;

    spellIDMap.clear();
    spellLevelMap.clear();
    interestMap.clear();

    st_Solo_Normal = new Strategy_Solo_Normal(this);
    st_Group_Normal = new Strategy_Group_Normal(this);

    switch (targetClass)
    {
    case Classes::CLASS_WARRIOR:
    {
        s_base = new Script_Warrior(this);
        break;
    }
    case Classes::CLASS_HUNTER:
    {
        s_base = new Script_Hunter(this);
        break;
    }
    case Classes::CLASS_SHAMAN:
    {
        s_base = new Script_Shaman(this);
        break;
    }
    case Classes::CLASS_PALADIN:
    {
        s_base = new Script_Paladin(this);
        break;
    }
    case Classes::CLASS_WARLOCK:
    {
        s_base = new Script_Warlock(this);
        break;
    }
    case Classes::CLASS_PRIEST:
    {
        s_base = new Script_Priest(this);
        break;
    }
    case Classes::CLASS_ROGUE:
    {
        s_base = new Script_Rogue(this);
        break;
    }
    case Classes::CLASS_MAGE:
    {
        s_base = new Script_Mage(this);
        break;
    }
    case Classes::CLASS_DRUID:
    {
        s_base = new Script_Druid(this);
        break;
    }
    }

    staying = false;
    holding = false;
}

RobotAI::~RobotAI()
{

}

void RobotAI::SetStrategy(std::string pmStrategyName, bool pmEnable)
{
    if (strategiesMap.find(pmStrategyName) != strategiesMap.end())
    {
        strategiesMap[pmStrategyName] = pmEnable;
    }
}

void RobotAI::ResetStrategy()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return;
    }
    me->GetMotionMaster()->Clear();
    me->StopMoving();
    strategiesMap["solo_normal"] = true;
    st_Solo_Normal->soloDuration = 0;
    strategiesMap["group_normal"] = false;
    staying = false;
    holding = false;
    masterGUID = ObjectGuid::Empty;
    me->Say("Strategy reset", Language::LANG_UNIVERSAL);
    Prepare();
}

void RobotAI::InitialEquipment(Player* pmTarget, uint32 pmWeaponType, bool pmDual, uint32 pmArmorType, bool pmHasRange, uint32 pmRangeType, bool pmHasShield)
{
    int levelRange = pmTarget->GetLevel() / 10;
    int checkLevelRange = levelRange;
    bool validEquip = false;
    int maxTryTimes = 5;

    while (checkLevelRange >= 0)
    {
        if (sRobotManager->meleeWeaponMap[pmWeaponType][checkLevelRange].size() > 0)
        {
            // use one hand sword
            for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
            {
                uint32 entry = urand(0, sRobotManager->meleeWeaponMap[pmWeaponType][checkLevelRange].size() - 1);
                entry = sRobotManager->meleeWeaponMap[pmWeaponType][checkLevelRange][entry];
                if (EquipNewItem(entry))
                {
                    validEquip = true;
                    break;
                }
            }
            if (validEquip)
            {
                break;
            }
        }
        checkLevelRange--;
    }

    if (pmDual)
    {
        checkLevelRange = levelRange;
        validEquip = false;
        while (checkLevelRange >= 0)
        {
            if (sRobotManager->meleeWeaponMap[pmWeaponType][checkLevelRange].size() > 0)
            {
                // use one hand sword
                for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                {
                    uint32 entry = urand(0, sRobotManager->meleeWeaponMap[pmWeaponType][checkLevelRange].size() - 1);
                    entry = sRobotManager->meleeWeaponMap[pmWeaponType][checkLevelRange][entry];
                    if (EquipNewItem(entry))
                    {
                        validEquip = true;
                        break;
                    }
                }
                if (validEquip)
                {
                    break;
                }
            }
            checkLevelRange--;
        }
    }

    if (pmHasRange)
    {
        checkLevelRange = levelRange;
        validEquip = false;
        while (checkLevelRange >= 0)
        {
            if (sRobotManager->rangeWeaponMap[pmRangeType][checkLevelRange].size() > 0)
            {
                // use one hand sword
                for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                {
                    uint32 entry = urand(0, sRobotManager->rangeWeaponMap[pmRangeType][checkLevelRange].size() - 1);
                    entry = sRobotManager->rangeWeaponMap[pmRangeType][checkLevelRange][entry];
                    if (EquipNewItem(entry))
                    {
                        validEquip = true;
                        break;
                    }
                }
                if (validEquip)
                {
                    break;
                }
            }
            checkLevelRange--;
        }
    }

    for (std::set<uint8>::iterator inventoryTypeIT = sRobotManager->armorInventorySet.begin(); inventoryTypeIT != sRobotManager->armorInventorySet.end(); inventoryTypeIT++)
    {
        checkLevelRange = levelRange;
        validEquip = false;
        while (checkLevelRange >= 0)
        {
            if (sRobotManager->armorMap[pmArmorType][(*inventoryTypeIT)][checkLevelRange].size() > 0)
            {
                for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                {
                    uint32 entry = urand(0, sRobotManager->armorMap[pmArmorType][(*inventoryTypeIT)][checkLevelRange].size() - 1);
                    entry = sRobotManager->armorMap[pmArmorType][(*inventoryTypeIT)][checkLevelRange][entry];
                    if (EquipNewItem(entry))
                    {
                        validEquip = true;
                        break;
                    }
                }
                if (validEquip)
                {
                    break;
                }
            }
            checkLevelRange--;
        }
    }

    // misc equip        
    for (std::unordered_map<uint8, uint8>::iterator inventoryTypeIT = sRobotManager->miscInventoryMap.begin(); inventoryTypeIT != sRobotManager->miscInventoryMap.end(); inventoryTypeIT++)
    {
        checkLevelRange = levelRange;
        validEquip = false;
        while (checkLevelRange >= 0)
        {
            if (sRobotManager->miscMap[inventoryTypeIT->second][checkLevelRange].size() > 0)
            {
                for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                {
                    uint32 entry = urand(0, sRobotManager->miscMap[inventoryTypeIT->second][checkLevelRange].size() - 1);
                    entry = sRobotManager->miscMap[inventoryTypeIT->second][checkLevelRange][entry];
                    if (EquipNewItem(entry))
                    {
                        validEquip = true;
                        break;
                    }
                }
                if (validEquip)
                {
                    break;
                }
            }
            checkLevelRange--;
        }
    }

    if (pmHasShield)
    {
        checkLevelRange = levelRange;
        validEquip = false;
        while (checkLevelRange >= 0)
        {
            if (sRobotManager->meleeWeaponMap[7][checkLevelRange].size() > 0)
            {
                // use shield
                for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                {
                    uint32 entry = urand(0, sRobotManager->meleeWeaponMap[7][checkLevelRange].size() - 1);
                    entry = sRobotManager->meleeWeaponMap[7][checkLevelRange][entry];
                    if (EquipNewItem(entry))
                    {
                        validEquip = true;
                        break;
                    }
                }
                if (validEquip)
                {
                    break;
                }
            }
            checkLevelRange--;
        }
    }
}

void RobotAI::InitializeCharacter()
{
    bool newCharacter = false;
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return;
    }
    if (me->GetLevel() != targetLevel)
    {
        newCharacter = true;
    }

    if (newCharacter)
    {
        me->GiveLevel(targetLevel);
        me->LearnDefaultSkills();
    }

    if (me->GetFreeTalentPoints() > 0)
    {
        me->ResetTalents(true);
        uint8 specialty = urand(0, 2);
        // EJ fixed specialty
        if (me->GetClass() == Classes::CLASS_MAGE)
        {
            specialty = 2;
        }
        else if (me->GetClass() == Classes::CLASS_ROGUE)
        {
            specialty = 1;
        }
        else if (me->GetClass() == Classes::CLASS_WARRIOR)
        {
            specialty = 0;
        }
        else if (me->GetClass() == Classes::CLASS_SHAMAN)
        {
            specialty = 2;
        }
        else if (me->GetClass() == Classes::CLASS_PRIEST)
        {
            specialty = 1;
        }
        else if (me->GetClass() == Classes::CLASS_WARLOCK)
        {
            specialty = 2;
        }
        else if (me->GetClass() == Classes::CLASS_PALADIN)
        {
            specialty = 2;
        }
        else if (me->GetClass() == Classes::CLASS_DRUID)
        {
            specialty = 1;
        }
        else if (me->GetClass() == Classes::CLASS_HUNTER)
        {
            specialty = 1;
        }

        uint32 classMask = me->GetClassMask();
        std::map<uint32, std::vector<TalentEntry const*> > talentsMap;
        for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
        {
            TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);
            if (!talentInfo)
                continue;

            TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);
            if (!talentTabInfo || talentTabInfo->tabpage != specialty)
                continue;

            if ((classMask & talentTabInfo->ClassMask) == 0)
                continue;

            talentsMap[talentInfo->Row].push_back(talentInfo);
        }
        for (std::map<uint32, std::vector<TalentEntry const*> >::iterator i = talentsMap.begin(); i != talentsMap.end(); ++i)
        {
            std::vector<TalentEntry const*> eachRowTalents = i->second;
            if (eachRowTalents.empty())
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "%s: No spells for talent row %d", me->GetName(), i->first);
                continue;
            }
            for (std::vector<TalentEntry const*>::iterator it = eachRowTalents.begin(); it != eachRowTalents.end(); it++)
            {
                uint8 maxRank = 4;
                if ((*it)->RankID[4] > 0)
                {
                    maxRank = 4;
                }
                else if ((*it)->RankID[3] > 0)
                {
                    maxRank = 3;
                }
                else if ((*it)->RankID[2] > 0)
                {
                    maxRank = 2;
                }
                else if ((*it)->RankID[1] > 0)
                {
                    maxRank = 1;
                }
                else
                {
                    maxRank = 0;
                }
                me->LearnTalent((*it)->TalentID, maxRank);
            }
        }
        me->SaveToDB();
    }

    if (newCharacter)
    {
        for (std::set<uint32>::iterator questIT = sRobotManager->spellRewardClassQuestIDSet.begin(); questIT != sRobotManager->spellRewardClassQuestIDSet.end(); questIT++)
        {
            const Quest* eachQuest = sObjectMgr->GetQuestTemplate((*questIT));
            if (me->SatisfyQuestLevel(eachQuest, false) && me->SatisfyQuestClass(eachQuest, false) && me->SatisfyQuestRace(eachQuest, false))
            {
                const SpellInfo* pSTCast = sSpellMgr->GetSpellInfo(eachQuest->GetRewSpellCast());
                if (pSTCast)
                {
                    std::set<uint32> spellToLearnIDSet;
                    spellToLearnIDSet.clear();
                    for (size_t effectCount = 0; effectCount < MAX_SPELL_EFFECTS; effectCount++)
                    {
                        if (pSTCast->Effects[effectCount].Effect == SpellEffects::SPELL_EFFECT_LEARN_SPELL)
                        {
                            spellToLearnIDSet.insert(pSTCast->Effects[effectCount].TriggerSpell);
                        }
                    }
                    if (spellToLearnIDSet.size() == 0)
                    {
                        spellToLearnIDSet.insert(pSTCast->Id);
                    }
                    for (std::set<uint32>::iterator toLearnIT = spellToLearnIDSet.begin(); toLearnIT != spellToLearnIDSet.end(); toLearnIT++)
                    {
                        me->LearnSpell((*toLearnIT), false);
                    }
                }
                const SpellInfo* pST = sSpellMgr->GetSpellInfo(eachQuest->GetRewSpell());
                if (pST)
                {
                    std::set<uint32> spellToLearnIDSet;
                    spellToLearnIDSet.clear();
                    for (size_t effectCount = 0; effectCount < MAX_SPELL_EFFECTS; effectCount++)
                    {
                        if (pST->Effects[effectCount].Effect == SpellEffects::SPELL_EFFECT_LEARN_SPELL)
                        {
                            spellToLearnIDSet.insert(pST->Effects[effectCount].TriggerSpell);
                        }
                    }
                    if (spellToLearnIDSet.size() == 0)
                    {
                        spellToLearnIDSet.insert(pST->Id);
                    }
                    for (std::set<uint32>::iterator toLearnIT = spellToLearnIDSet.begin(); toLearnIT != spellToLearnIDSet.end(); toLearnIT++)
                    {
                        me->LearnSpell((*toLearnIT), false);
                    }
                }
            }
        }

        std::unordered_map<uint32, Trainer::Trainer> allTrainers = sObjectMgr->GetTrainers();
        for (auto const& eachTrainer : allTrainers)
        {
            const Trainer::Trainer* tInfo = &eachTrainer.second;
            if (!tInfo)
            {
                continue;
            }
            if (tInfo->GetTrainerType() != Trainer::Type::Class)
            {
                continue;
            }
            if (!tInfo->IsTrainerValidForPlayer(me))
            {
                continue;
            }
            std::unordered_set<uint32> trainerSpellIDs = tInfo->GetAllSpellsID();

            for (std::unordered_set<uint32>::const_iterator itr = trainerSpellIDs.begin(); itr != trainerSpellIDs.end(); ++itr)
            {
                uint32 eachSpellID = *itr;
                if (!me->IsSpellFitByClassAndRace(eachSpellID))
                {
                    continue;
                }
                if (!tInfo->SpellRequireLevelValid(me, eachSpellID))
                {
                    continue;
                }
                uint32 checkSpellID = eachSpellID;
                while (true)
                {
                    const SpellInfo* pSpell = sSpellMgr->GetSpellInfo(checkSpellID);
                    if (!pSpell)
                    {
                        break;
                    }
                    if (pSpell->Effects[0].Effect == SPELL_EFFECT_LEARN_SPELL)
                    {
                        checkSpellID = pSpell->Effects[0].TriggerSpell;
                    }
                    else
                    {
                        break;
                    }
                }
                me->LearnSpell(checkSpellID, false);
            }
        }
        me->SaveToDB();
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Player %s basic info initialized", me->GetName());
    }

    spellLevelMap.clear();
    bool typeChecked = false;
    characterType = 0;
    me->groupRole = 0;
    for (PlayerSpellMap::iterator it = me->GetSpellMap().begin(); it != me->GetSpellMap().end(); it++)
    {
        const SpellInfo* pST = sSpellMgr->GetSpellInfo(it->first);
        if (pST)
        {
            std::string checkNameStr = std::string(pST->SpellName[0]);
            if (!typeChecked)
            {
                switch (me->GetClass())
                {
                case Classes::CLASS_WARRIOR:
                {
                    if (checkNameStr == "Improved Heroic Strike")
                    {
                        characterTalentTab = 0;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Booming Voice")
                    {
                        characterTalentTab = 1;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Shield Specialization")
                    {
                        characterTalentTab = 2;
                        characterType = 1;
                        me->groupRole = 1;
                        typeChecked = true;
                    }
                    break;
                }
                case Classes::CLASS_HUNTER:
                {
                    if (checkNameStr == "Improved Aspect of the Hawk")
                    {
                        characterTalentTab = 0;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Improved Concussive Shot")
                    {
                        characterTalentTab = 1;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Improved Tracking")
                    {
                        characterTalentTab = 2;
                        typeChecked = true;
                    }
                    break;
                }
                case Classes::CLASS_SHAMAN:
                {
                    if (checkNameStr == "Convection")
                    {
                        characterTalentTab = 0;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Ancestral Knowledge")
                    {
                        characterTalentTab = 1;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Improved Healing Wave")
                    {
                        characterTalentTab = 2;
                        characterType = 2;
                        me->groupRole = 2;
                        typeChecked = true;
                    }
                    break;
                }
                case Classes::CLASS_PALADIN:
                {
                    if (checkNameStr == "Spiritual Focus")
                    {
                        characterTalentTab = 0;
                        characterType = 2;
                        me->groupRole = 2;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Divinity")
                    {
                        characterTalentTab = 1;
                        characterType = 1;
                        me->groupRole = 1;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Deflection")
                    {
                        characterTalentTab = 2;
                        typeChecked = true;
                    }
                    break;
                }
                case Classes::CLASS_WARLOCK:
                {
                    if (checkNameStr == "Suppression")
                    {
                        characterTalentTab = 0;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Improved Healthstone")
                    {
                        characterTalentTab = 1;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Improved Shadow Bolt")
                    {
                        characterTalentTab = 2;
                        typeChecked = true;
                    }
                    break;
                }
                case Classes::CLASS_PRIEST:
                {
                    if (checkNameStr == "Unbreakable Will")
                    {
                        characterTalentTab = 0;
                        characterType = 2;
                        me->groupRole = 2;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Healing Focus")
                    {
                        characterTalentTab = 1;
                        characterType = 2;
                        me->groupRole = 2;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Spirit Tap")
                    {
                        characterTalentTab = 2;
                        typeChecked = true;
                    }
                    break;
                }
                case Classes::CLASS_ROGUE:
                {
                    if (checkNameStr == "Improved Eviscerate")
                    {
                        characterTalentTab = 0;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Improved Gouge")
                    {
                        characterTalentTab = 1;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Master of Deception")
                    {
                        characterTalentTab = 2;
                        typeChecked = true;
                    }
                    break;
                }
                case Classes::CLASS_MAGE:
                {
                    if (checkNameStr == "Arcane Subtlety")
                    {
                        characterTalentTab = 0;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Improved Fireball")
                    {
                        characterTalentTab = 1;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Frost Warding")
                    {
                        characterTalentTab = 2;
                        typeChecked = true;
                    }
                    break;
                }
                case Classes::CLASS_DRUID:
                {
                    if (checkNameStr == "Genesis")
                    {
                        characterTalentTab = 0;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Ferocity")
                    {
                        characterTalentTab = 1;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Furor")
                    {
                        characterTalentTab = 2;
                        characterType = 2;
                        me->groupRole = 2;
                        typeChecked = true;
                    }
                    break;
                }
                default:
                {
                    break;
                }
                }
            }
            if (spellLevelMap.find(checkNameStr) == spellLevelMap.end())
            {
                spellLevelMap[checkNameStr] = pST->BaseLevel;
                spellIDMap[checkNameStr] = it->first;
            }
            else
            {
                if (pST->BaseLevel > spellLevelMap[checkNameStr])
                {
                    spellLevelMap[checkNameStr] = pST->BaseLevel;
                    spellIDMap[checkNameStr] = it->first;
                }
            }
        }
    }

    if (newCharacter)
    {
        for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; i++)
        {
            if (Item* pItem = me->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            {
                me->DestroyItem(INVENTORY_SLOT_BAG_0, i, true);
            }
        }
        uint32 weaponType = 0;
        bool dual = false;
        uint32 armorType = 0;
        bool hasShield = false;
        bool hasRange = false;
        uint32 rangeType = 0;
        switch (me->GetClass())
        {
        case Classes::CLASS_WARRIOR:
        {
            if (me->GetLevel() < 40)
            {
                // use mail armor
                armorType = 2;
            }
            else
            {
                // use plate armor
                armorType = 3;
            }
            hasRange = false;
            dual = false;
            if (characterType == 1)
            {
                weaponType = 1;
                hasShield = true;
            }
            else
            {
                weaponType = 2;
                hasShield = false;
            }
            break;
        }
        case Classes::CLASS_HUNTER:
        {
            me->LearnSpell(264, false); // bow 
            me->LearnSpell(266, false); // gun 
            me->LearnSpell(5011, false); // crossbow

            // quiver and ammo pouch
            Item* weapon = me->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
            if (weapon)
            {
                uint32 subClass = weapon->GetTemplate()->SubClass;
                if (subClass == ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_BOW || subClass == ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_CROSSBOW)
                {
                    me->StoreNewItemInBestSlots(2101, 1);
                }
                else if (subClass == ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_GUN)
                {
                    me->StoreNewItemInBestSlots(2102, 1);
                }
            }

            if (me->GetLevel() < 40)
            {
                armorType = 1;
            }
            else
            {
                armorType = 2;
            }
            dual = false;
            hasRange = true;
            rangeType = 0;
            weaponType = 5;
            hasShield = false;
            break;
        }
        case Classes::CLASS_SHAMAN:
        {
            if (me->GetLevel() < 40)
            {
                armorType = 1;
            }
            else
            {
                armorType = 2;
            }
            hasRange = false;
            weaponType = 6;
            dual = true;
            hasShield = false;
            break;
        }
        case Classes::CLASS_PALADIN:
        {
            if (me->GetLevel() < 40)
            {
                // use mail armor
                armorType = 2;
            }
            else
            {
                // use plate armor
                armorType = 3;
            }
            hasRange = false;
            dual = false;
            if (characterType == 1)
            {
                weaponType = 4;
                hasShield = false;
            }
            else if (characterType == 1)
            {
                weaponType = 3;
                hasShield = true;
            }
            else if (characterType == 2)
            {
                weaponType = 3;
                hasShield = true;
            }
            break;
        }
        case Classes::CLASS_WARLOCK:
        {
            armorType = 0;
            hasRange = true;
            rangeType = 1;
            dual = false;
            weaponType = 0;
            hasShield = false;
            break;
        }
        case Classes::CLASS_PRIEST:
        {
            armorType = 0;
            hasRange = true;
            rangeType = 1;
            dual = false;
            weaponType = 0;
            hasShield = false;
            break;
        }
        case Classes::CLASS_ROGUE:
        {
            armorType = 1;
            hasRange = true;
            rangeType = 2;
            weaponType = 6;
            dual = true;
            hasShield = false;
            break;
        }
        case Classes::CLASS_MAGE:
        {
            armorType = 0;
            hasRange = true;
            rangeType = 1;
            dual = false;
            weaponType = 0;
            hasShield = false;
            break;
        }
        case Classes::CLASS_DRUID:
        {
            armorType = 1;
            hasRange = false;
            dual = false;
            weaponType = 0;
            hasShield = false;
            break;
        }
        default:
        {
            break;
        }
        }
        InitialEquipment(me, weaponType, dual, armorType, hasRange, rangeType, hasShield);
        me->SaveToDB();
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Player %s equip info initialized", me->GetName());
    }

    if (me->GetClass() == Classes::CLASS_WARLOCK)
    {
        switch (characterTalentTab)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            break;
        }
        case 2:
        {
            uint32 g0 = me->GetGlyph(0);
            if (g0 == 0)
            {
                me->CastSpell(me, 56270);
            }
            break;
        }
        default:
        {
            break;
        }
        }
    }

    if (me->GetClass() == Classes::CLASS_HUNTER)
    {
        Pet* loadPet = new Pet(me, PetType::HUNTER_PET);
        if (!loadPet->LoadPetFromDB(me))
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Create hunter pet for %s", me->GetName());
            bool petCreated = false;
            uint32 beastEntry = urand(0, sRobotManager->tamableBeastEntryMap.size() - 1);
            beastEntry = sRobotManager->tamableBeastEntryMap[beastEntry];
            CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(beastEntry);
            if (cinfo)
            {
                Pet* createPet = new Pet(me, HUNTER_PET);

                if (createPet->CreateBaseAtCreatureInfo(cinfo, me))
                {
                    if (me->InitTamedPet(createPet, me->GetLevel(), 1515))
                    {
                        createPet->GivePetLevel(me->GetLevel());
                        createPet->GetMap()->AddToMap(createPet->ToCreature());
                        me->SetMinion(createPet, true);
                        createPet->InitTalentForLevel();
                        createPet->SavePetToDB(PET_SAVE_AS_CURRENT);
                        me->PetSpellInitialize();
                        createPet->SetPower(POWER_HAPPINESS, HAPPINESS_LEVEL_SIZE * 3);
                        petCreated = true;
                    }
                }
            }
            if (petCreated)
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Hunter pet for %s created", me->GetName());
            }
            else
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "Hunter pet for %s create failed", me->GetName());
            }
        }
    }

    me->UpdateSkillsForLevel();
    me->UpdateWeaponsSkillsToMaxSkillsForLevel();
    if (!me->IsPvP())
    {
        me->SetPvP(true);
    }

    me->SaveToDB();

    RandomTeleport();

    std::ostringstream msgStream;
    msgStream << me->GetName() << " initialized";
    sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, msgStream.str().c_str());
}

void RobotAI::Prepare()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return;
    }
    me->DurabilityRepairAll(false, 0, false);
    if (me->GetClass() == Classes::CLASS_HUNTER)
    {
        uint32 ammoEntry = 0;
        Item* weapon = me->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
        if (weapon)
        {
            uint32 subClass = weapon->GetTemplate()->SubClass;
            uint8 playerLevel = me->GetLevel();
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
                if (!me->HasItemCount(ammoEntry, 100))
                {
                    me->StoreNewItemInBestSlots(ammoEntry, 1000);
                    me->SetAmmo(ammoEntry);
                }
            }
        }
    }
    Pet* checkPet = me->GetPet();
    if (checkPet)
    {
        checkPet->GivePetLevel(me->GetLevel() - 1);
        checkPet->GivePetLevel(me->GetLevel());
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
                    else if (checkNameStr == "Growl")
                    {
                        if (me->GetGroup())
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
}

void RobotAI::Refresh()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return;
    }
    if (!me->IsAlive())
    {
        me->ResurrectPlayer(100);
    }
    me->SetFullHealth();
    me->ClearInCombat();
    me->GetThreatManager().ClearAllThreat();
    me->GetMotionMaster()->Clear();
}

void RobotAI::RandomTeleport()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return;
    }
    if (me->IsBeingTeleported())
    {
        return;
    }
    uint8 levelRange = me->GetLevel() / 10;
    uint32 destIndex = urand(0, sRobotManager->teleportCacheMap[levelRange].size() - 1);
    WorldLocation destWL = sRobotManager->teleportCacheMap[levelRange][destIndex];
    Map* targetMap = sMapMgr->FindBaseNonInstanceMap(destWL.m_mapId);
    if (targetMap)
    {
        me->TeleportTo(destWL);
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Teleport robot %s (level %d)", me->GetName(), me->GetLevel());
    }
}

bool RobotAI::HasAura(Unit* pmTarget, std::string pmSpellName, bool pmOnlyMyAura)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }
    Unit* target = pmTarget;
    if (!pmTarget)
    {
        target = me;
    }
    std::set<uint32> spellIDSet = sRobotManager->spellNameEntryMap[pmSpellName];
    for (std::set<uint32>::iterator it = spellIDSet.begin(); it != spellIDSet.end(); it++)
    {
        if (pmOnlyMyAura)
        {
            if (target->HasAura((*it), me->GetGUID()))
            {
                return true;
            }
        }
        else
        {
            if (target->HasAura(*it))
            {
                return true;
            }
        }
    }

    return false;
}

bool RobotAI::CastSpell(Unit* pmTarget, std::string pmSpellName, float pmDistance, bool pmCheckAura, bool pmOnlyMyAura, bool pmClearShapeshift)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }
    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
    {
        return true;
    }
    if (me->IsNonMeleeSpellCast(true, false, true))
    {
        return true;
    }
    if (me->HasUnitState(UnitState::UNIT_STATE_ROAMING_MOVE))
    {
        return true;
    }
    if (pmCheckAura)
    {
        if (HasAura(pmTarget, pmSpellName, pmOnlyMyAura))
        {
            return false;
        }
    }
    uint32 spellID = FindSpellID(pmSpellName);
    if (!SpellValid(spellID))
    {
        return false;
    }
    Unit* target = pmTarget;
    if (!target)
    {
        target = me;
    }
    me->SetSelection(target->GetGUID());
    if (target->GetGUID() != me->GetGUID())
    {
        if (me->GetDistance(target) > pmDistance)
        {
            return false;
        }
    }
    if (pmClearShapeshift)
    {
        ClearShapeshift();
    }
    const SpellInfo* pST = sSpellMgr->GetSpellInfo(spellID);
    if (!pST)
    {
        return false;
    }
    if (target->IsImmunedToSpell(pST, me))
    {
        return false;
    }
    for (size_t i = 0; i < MAX_SPELL_REAGENTS; i++)
    {
        if (pST->Reagent[i] > 0)
        {
            if (!me->HasItemCount(pST->Reagent[i], pST->ReagentCount[i]))
            {
                me->StoreNewItemInBestSlots(pST->Reagent[i], pST->ReagentCount[i] * 10);
            }
        }
    }
    if (me->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
    {
        me->SetStandState(UNIT_STAND_STATE_STAND);
    }
    if (pST->CalcCastTime() > 0)
    {
        me->StopMoving();
    }
    me->CastSpell(target, spellID, TriggerCastFlags::TRIGGERED_NONE);

    return true;
}

void RobotAI::BaseMove(Unit* pmTarget, float pmMaxDistance, bool pmAttack, float pmMinDistance)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return;
    }
    if (me->HasUnitState(UnitState::UNIT_STATE_NOT_MOVE))
    {
        return;
    }
    if (me->HasUnitState(UnitState::UNIT_STATE_ROAMING_MOVE))
    {
        return;
    }
    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
    {
        return;
    }
    if (me->IsNonMeleeSpellCast(true, false, true))
    {
        return;
    }
    if (!me->IsInMap(pmTarget))
    {
        return;
    }
    if (me->GetDistance(pmTarget) > 200)
    {
        return;
    }
    // Can't attack if owner is pacified
    if (me->HasAuraType(SPELL_AURA_MOD_PACIFY))
    {
        //pet->SendPetCastFail(spellid, SPELL_FAILED_PACIFIED);
        /// @todo Send proper error message to client
        return;
    }
    if (me->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
    {
        me->SetStandState(UNIT_STAND_STATE_STAND);
    }
    if (me->IsWalking())
    {
        me->SetWalk(false);
    }

    if (pmAttack)
    {
        if (!me->GetVictim())
        {
            me->Attack(pmTarget, true);
        }
        else if (me->GetVictim()->GetGUID() != pmTarget->GetGUID())
        {
            me->Attack(pmTarget, true);
        }
    }

    bool chasing = false;
    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == MovementGeneratorType::CHASE_MOTION_TYPE)
    {
        ChaseMovementGenerator* cmg = (ChaseMovementGenerator*)me->GetMotionMaster()->GetCurrentMovementGenerator();
        if (cmg)
        {
            if (cmg->GetTarget()->GetGUID() == pmTarget->GetGUID())
            {
                if (cmg->GetMinRange() == pmMinDistance && cmg->GetMaxRange() == pmMaxDistance)
                {
                    chasing = true;
                }
            }
        }
    }
    if (chasing)
    {
        if (holding)
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
        }
    }
    else
    {
        if (holding)
        {
            if (!me->isInFront(pmTarget))
            {
                me->SetFacingToObject(pmTarget);
            }
        }
        else
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            me->SetSelection(ObjectGuid::Empty);
            me->GetMotionMaster()->MoveChase(pmTarget, ChaseRange(pmMinDistance, pmMaxDistance));
        }
    }
}

void RobotAI::WhisperTo(std::string pmContent, Language pmLanguage, Player* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return;
    }
    me->Whisper(pmContent, pmLanguage, pmTarget);
}

void RobotAI::HandlePacket(WorldPacket const* pmDestPacket)
{
    if (pmDestPacket)
    {
        Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
        if (!me)
        {
            return;
        }
        switch (pmDestPacket->GetOpcode())
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
            bool acceptInvite = true;
            if (inviter->GetLevel() < me->GetLevel())
            {
                uint32 lowGUID = inviter->GetGUID().GetCounter();
                if (interestMap.find(lowGUID) == interestMap.end())
                {
                    uint8 levelGap = me->GetLevel() - inviter->GetLevel();
                    if (urand(0, levelGap) > 0)
                    {
                        acceptInvite = false;
                    }
                    interestMap[lowGUID] = acceptInvite;
                }
                else
                {
                    acceptInvite = interestMap[lowGUID];
                }
                if (st_Solo_Normal->interestsDelay <= 0)
                {
                    st_Solo_Normal->interestsDelay = 300 * TimeConstants::IN_MILLISECONDS;
                }
            }
            if (acceptInvite)
            {
                masterGUID = inviter->GetGUID();
                WorldPacket p;
                uint32 roles_mask = 0;
                p << roles_mask;
                me->GetSession()->HandleGroupAcceptOpcode(p);
                WhisperTo("Strategy set to group", Language::LANG_UNIVERSAL, inviter);
                WhisperTo("You are my master", Language::LANG_UNIVERSAL, inviter);
                std::ostringstream replyStream_Talent;
                replyStream_Talent << "My talent category is " << sRobotManager->characterTalentTabNameMap[me->GetClass()][characterTalentTab];
                WhisperTo(replyStream_Talent.str(), Language::LANG_UNIVERSAL, inviter);
                std::ostringstream replyStream_GroupRole;
                replyStream_GroupRole << "My group role is ";
                switch (me->groupRole)
                {
                case 0:
                {
                    replyStream_GroupRole << "dps";
                    break;
                }
                case 1:
                {
                    replyStream_GroupRole << "tank";
                    break;
                }
                case 2:
                {
                    replyStream_GroupRole << "healer";
                    break;
                }
                default:
                {
                    replyStream_GroupRole << "dps";
                    break;
                }
                }
                WhisperTo(replyStream_GroupRole.str(), Language::LANG_UNIVERSAL, inviter);
                me->GetMotionMaster()->Clear();
                Prepare();
                SetStrategy("solo_normal", false);
                SetStrategy("group_normal", true);
                st_Group_Normal->Set();
                break;
            }
            else
            {
                WorldPacket p;
                me->GetSession()->HandleGroupDeclineOpcode(p);
                std::ostringstream timeLeftStream;
                timeLeftStream << "Not interested.";
                WhisperTo(timeLeftStream.str(), Language::LANG_UNIVERSAL, inviter);
                break;
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
            if (!me->IsAlive())
            {
                st_Solo_Normal->deathDuration = 0;
            }
            if (me->IsResurrectRequested())
            {
                me->ResurrectUsingRequestData();
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
            WhisperTo("Not interested", Language::LANG_UNIVERSAL, me->duel->Opponent);
            break;
        }
        default:
        {
            break;
        }
        }
    }
}

void RobotAI::Update()
{
    uint32 realCurrTime = getMSTime();
    uint32 diff = getMSTimeDiff(realPrevTime, realCurrTime);

    realPrevTime = realCurrTime;
    switch (robotState)
    {
    case RobotState_None:
    {
        break;
    }
    case RobotState_OffLine:
    {
        if (onlineDelay > 0)
        {
            onlineDelay -= diff;
            if (onlineDelay <= 0)
            {
                onlineDelay = 0;
                robotState = RobotState::RobotState_CheckAccount;
                allDelay = 5 * TimeConstants::IN_MILLISECONDS;
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %s is ready to go online.", accountName);
            }
        }
        else if (checkDelay > 0)
        {
            checkDelay -= diff;
            if (checkDelay <= 0)
            {
                checkDelay = urand(TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
                bool levelPlayerOnline = false;
                if (sRobotConfig->OnlineLevel == targetLevel)
                {
                    levelPlayerOnline = true;
                    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %s is at online level.", accountName);
                }
                if (!levelPlayerOnline)
                {
                    std::unordered_map<uint32, WorldSession*> allSessionMap = sWorld->GetAllSessions();
                    for (std::unordered_map<uint32, WorldSession*>::iterator it = allSessionMap.begin(); it != allSessionMap.end(); it++)
                    {
                        if (!sRobotManager->IsRobot(it->first))
                        {
                            Player* eachPlayer = it->second->GetPlayer();
                            if (eachPlayer)
                            {
                                if (eachPlayer->IsInWorld())
                                {
                                    uint32 eachPlayerLevel = eachPlayer->GetLevel();
                                    if (eachPlayerLevel > 10)
                                    {
                                        if (eachPlayerLevel == targetLevel)
                                        {
                                            levelPlayerOnline = true;
                                            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %s is same level as active player.", accountName);
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (levelPlayerOnline)
                {
                    onlineDelay = urand(sRobotConfig->OnlineMinDelay, sRobotConfig->OnlineMaxDelay);
                    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %s online delay is set to %d.", accountName, onlineDelay);
                }
            }
        }
        break;
    }
    case RobotState_CheckAccount:
    {
        allDelay -= diff;
        if (allDelay <= 0)
        {
            allDelay = 5 * TimeConstants::IN_MILLISECONDS;
            accountID = sRobotManager->CheckRobotAccount(accountName);
            if (accountID > 0)
            {
                sRobotManager->robotAICache[accountID] = this;
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %s account ready.", accountName);
                robotState = RobotState::RobotState_CheckCharacter;
            }
            else
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %s account not ready.", accountName);
                robotState = RobotState::RobotState_CreateAccount;
            }
        }
        break;
    }
    case RobotState_CreateAccount:
    {
        allDelay -= diff;
        if (allDelay <= 0)
        {
            allDelay = 5 * TimeConstants::IN_MILLISECONDS;
            if (sRobotManager->CreateRobotAccount(accountName))
            {
                robotState = RobotState::RobotState_CheckAccount;
            }
            else
            {
                robotState = RobotState::RobotState_None;
            }
        }
        break;
    }
    case RobotState_CheckCharacter:
    {
        allDelay -= diff;
        if (allDelay <= 0)
        {
            allDelay = 5 * TimeConstants::IN_MILLISECONDS;
            characterGUID = sRobotManager->CheckAccountCharacter(accountID);
            if (!characterGUID.IsEmpty())
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %s character ready.", accountName);
                robotState = RobotState::RobotState_DoLogin;
            }
            else
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %s character not ready.", accountName);
                robotState = RobotState::RobotState_CreateCharacter;
            }
        }
        break;
    }
    case RobotState_CreateCharacter:
    {
        allDelay -= diff;
        if (allDelay <= 0)
        {
            allDelay = 5 * TimeConstants::IN_MILLISECONDS;
            if (sRobotManager->CreateRobotCharacter(accountID, targetClass, targetRace))
            {
                robotState = RobotState::RobotState_CheckCharacter;
            }
            else
            {
                robotState = RobotState::RobotState_None;
            }
        }
        break;
    }
    case RobotState_CheckLogin:
    {
        allDelay -= diff;
        if (allDelay <= 0)
        {
            allDelay = 10 * TimeConstants::IN_MILLISECONDS;
            Player* me = sRobotManager->CheckLogin(accountID, characterGUID);
            if (me)
            {
                WorldSession* mySession = me->GetSession();
                InitializeCharacter();
                me->SetPvP(true);
                Prepare();
                robotState = RobotState::RobotState_Online;
                checkDelay = urand(TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
            }
            else
            {
                robotState = RobotState::RobotState_DoLogin;
                allDelay = 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS;
            }
        }
        break;
    }
    case RobotState_DoLogin:
    {
        allDelay -= diff;
        if (allDelay <= 0)
        {
            allDelay = 10 * TimeConstants::IN_MILLISECONDS;
            sRobotManager->LoginRobot(accountID, characterGUID);
            robotState = RobotState::RobotState_CheckLogin;
        }
        break;
    }
    case RobotState_Online:
    {
        Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
        if (!me)
        {
            break;
        }
        if (strategiesMap["solo_normal"])
        {
            st_Solo_Normal->Update(diff);
        }
        if (strategiesMap["group_normal"])
        {
            st_Group_Normal->Update(diff);
        }
        if (offlineDelay > 0)
        {
            offlineDelay -= diff;
            if (offlineDelay <= 0)
            {
                offlineDelay = 0;
                robotState = RobotState::RobotState_DoLogoff;
                allDelay = 5 * TimeConstants::IN_MILLISECONDS;
            }
        }
        else if (checkDelay > 0)
        {
            checkDelay -= diff;
            if (checkDelay <= 0)
            {
                Prepare();
                checkDelay = urand(TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
                bool levelPlayerOnline = false;
                if (sRobotConfig->OnlineLevel == targetLevel)
                {
                    levelPlayerOnline = true;
                }
                if (!levelPlayerOnline)
                {
                    if (me->GetGroup())
                    {
                        Player* master = ObjectAccessor::FindConnectedPlayer(masterGUID);
                        if (master)
                        {
                            if (master->IsInWorld())
                            {
                                if (me->IsInSameRaidWith(master))
                                {
                                    levelPlayerOnline = true;
                                }
                            }
                        }

                        if (!levelPlayerOnline)
                        {
                            me->RemoveFromGroup();
                            ResetStrategy();
                            RandomTeleport();
                        }
                    }
                }
                if (!levelPlayerOnline)
                {
                    std::unordered_map<uint32, WorldSession*> allSessionMap = sWorld->GetAllSessions();
                    for (std::unordered_map<uint32, WorldSession*>::iterator it = allSessionMap.begin(); it != allSessionMap.end(); it++)
                    {
                        if (!sRobotManager->IsRobot(it->first))
                        {
                            Player* eachPlayer = it->second->GetPlayer();
                            if (eachPlayer)
                            {
                                if (eachPlayer->IsInWorld())
                                {
                                    uint32 eachPlayerLevel = eachPlayer->GetLevel();
                                    if (eachPlayerLevel > 10)
                                    {
                                        if (eachPlayerLevel == targetLevel)
                                        {
                                            levelPlayerOnline = true;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                // EJ debug
                //levelPlayerOnline = false;

                if (!levelPlayerOnline)
                {
                    offlineDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);

                    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %s offline delay is set to %d.", accountName, offlineDelay);
                }
            }
        }
        break;
    }
    case RobotState_CheckLogoff:
    {
        allDelay -= diff;
        if (allDelay <= 0)
        {
            allDelay = 5 * TimeConstants::IN_MILLISECONDS;
            Player* checkP = ObjectAccessor::FindConnectedPlayer(characterGUID);
            if (checkP)
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "Log out robot %s failed", checkP->GetName());
                robotState = RobotState::RobotState_None;
                break;
            }
            //sRobotManager->robotAICache.erase(accountID);

            robotState = RobotState::RobotState_OffLine;
        }
        break;
    }
    case RobotState_DoLogoff:
    {
        allDelay -= diff;
        if (allDelay <= 0)
        {
            allDelay = 0;
            Logout();
            robotState = RobotState::RobotState_CheckLogoff;
            allDelay = 10 * TimeConstants::IN_MILLISECONDS;
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

Item* RobotAI::GetItemInInventory(uint32 pmEntry)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        NULL;
    }
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
    {
        Item* pItem = me->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem)
        {
            if (pItem->GetEntry() == pmEntry)
            {
                return pItem;
            }
        }
    }

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
    {
        if (Bag* pBag = (Bag*)me->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                Item* pItem = me->GetItemByPos(i, j);
                if (pItem)
                {
                    if (pItem->GetEntry() == pmEntry)
                    {
                        return pItem;
                    }
                }
            }
        }
    }

    return NULL;
}

bool RobotAI::UseItem(Item* pmItem, Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }
    if (me->CanUseItem(pmItem) != EQUIP_ERR_OK)
    {
        return false;
    }

    if (me->IsNonMeleeSpellCast(true))
    {
        return false;
    }
    SpellCastTargets targets;
    targets.Update(pmTarget);
    me->CastItemUseSpell(pmItem, targets, 0, 0);

    std::ostringstream useRemarksStream;
    useRemarksStream << "Prepare to use item " << pmItem->GetTemplate()->Name1;

    me->Say(useRemarksStream.str(), Language::LANG_UNIVERSAL);
    return true;
}

bool RobotAI::EquipNewItem(uint32 pmEntry)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }

    uint16 eDest;
    InventoryResult tryEquipResult = me->CanEquipNewItem(NULL_SLOT, eDest, pmEntry, false);
    if (tryEquipResult == EQUIP_ERR_OK)
    {
        Item* pItem = Item::CreateItem(pmEntry, 1, me);
        if (pItem)
        {
            if (int32 randomPropertyId = GenerateItemRandomPropertyId(pmEntry))
            {
                pItem->SetItemRandomProperties(randomPropertyId);
            }
            //SQLTransaction trans = CharacterDatabase.BeginTransaction();
            //pItem->SaveToDB(trans);
            //CharacterDatabase.CommitTransaction(trans);
            InventoryResult equipResult = me->CanEquipItem(NULL_SLOT, eDest, pItem, false);
            if (equipResult == EQUIP_ERR_OK)
            {
                me->EquipItem(eDest, pItem, true);
                return true;
            }
            else
            {
                pItem->DestroyForPlayer(me);
            }
        }
    }

    return false;
}

bool RobotAI::EquipNewItem(uint32 pmEntry, uint8 pmEquipSlot)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }

    uint16 eDest;
    InventoryResult tryEquipResult = me->CanEquipNewItem(NULL_SLOT, eDest, pmEntry, false);
    if (tryEquipResult == EQUIP_ERR_OK)
    {
        ItemPosCountVec sDest;
        InventoryResult storeResult = me->CanStoreNewItem(INVENTORY_SLOT_BAG_0, NULL_SLOT, sDest, pmEntry, 1);
        if (storeResult == EQUIP_ERR_OK)
        {
            Item* pItem = me->StoreNewItem(sDest, pmEntry, true, GenerateItemRandomPropertyId(pmEntry));
            if (pItem)
            {
                InventoryResult equipResult = me->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                if (equipResult == EQUIP_ERR_OK)
                {
                    me->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                    me->EquipItem(pmEquipSlot, pItem, true);
                    return true;
                }
                else
                {
                    pItem->DestroyForPlayer(me);
                }
            }
        }
    }

    return false;
}

bool RobotAI::UnequipAll()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }

    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
    {
        if (Item* pItem = me->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            uint8 bagIndex = pItem->GetBagSlot();
            uint8 slot = pItem->GetSlot();
            uint8 dstBag = NULL_BAG;
            WorldPacket data(CMSG_AUTOSTORE_BAG_ITEM, 3);
            data << bagIndex << slot << dstBag;
            me->GetSession()->HandleAutoStoreBagItemOpcode(data);
        }
    }
    me->UpdateAllStats();
    return true;
}

bool RobotAI::EquipAll()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }

    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        if (Item* pItem = me->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (pItem)
            {
                uint16 eDest;
                InventoryResult equipResult = me->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                if (equipResult == EQUIP_ERR_OK)
                {
                    me->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                    me->EquipItem(eDest, pItem, true);
                }
            }
        }
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = (Bag*)me->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                if (Item* pItem = pBag->GetItemByPos(j))
                {
                    if (pItem)
                    {
                        uint16 eDest;
                        InventoryResult equipResult = me->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                        if (equipResult == EQUIP_ERR_OK)
                        {
                            me->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                            me->EquipItem(eDest, pItem, true);
                        }
                    }
                }
            }
        }
    }
    me->UpdateAllStats();

    return true;
}

bool RobotAI::EquipItem(std::string pmEquipName)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }

    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        if (Item* pItem = me->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (pItem)
            {
                if (pItem->GetTemplate()->Name1 == pmEquipName)
                {
                    uint16 eDest;
                    InventoryResult equipResult = me->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                    if (equipResult == EQUIP_ERR_OK)
                    {
                        me->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                        me->EquipItem(eDest, pItem, true);
                        me->UpdateAllStats();
                    }
                    return true;
                }
            }
        }
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = (Bag*)me->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                if (Item* pItem = pBag->GetItemByPos(j))
                {
                    if (pItem)
                    {
                        if (pItem->GetTemplate()->Name1 == pmEquipName)
                        {
                            uint16 eDest;
                            InventoryResult equipResult = me->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                            if (equipResult == EQUIP_ERR_OK)
                            {
                                me->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                                me->EquipItem(eDest, pItem, true);
                                me->UpdateAllStats();
                            }
                            return true;
                        }
                    }
                }
            }
        }
    }

    return true;
}

bool RobotAI::UnequipItem(std::string pmEquipName)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }

    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
    {
        if (Item* pItem = me->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (pItem->GetTemplate()->Name1 == pmEquipName)
            {
                uint8 bagIndex = pItem->GetBagSlot();
                uint8 slot = pItem->GetSlot();
                uint8 dstBag = NULL_BAG;
                WorldPacket data(CMSG_AUTOSTORE_BAG_ITEM, 3);
                data << bagIndex << slot << dstBag;
                me->GetSession()->HandleAutoStoreBagItemOpcode(data);

                return true;
            }
        }
        me->UpdateAllStats();
    }

    return true;
}

void RobotAI::HandleChatCommand(Player* pmSender, std::string pmCMD)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return;
    }
    Player* master = ObjectAccessor::FindConnectedPlayer(masterGUID);
    std::vector<std::string> commandVector = sRobotManager->SplitString(pmCMD, " ", true);
    std::string commandName = commandVector.at(0);
    if (commandName == "role")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }

        std::ostringstream replyStream;
        if (commandVector.size() > 1)
        {
            std::string newRole = commandVector.at(1);
            if (newRole == "dps")
            {
                me->groupRole = 0;
            }
            else if (newRole == "tank")
            {
                me->groupRole = 1;
            }
            else if (newRole == "healer")
            {
                me->groupRole = 2;
            }
        }

        replyStream << "My group role is ";
        switch (me->groupRole)
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
        WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
    }
    else if (commandName == "follow")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (!me->IsAlive())
        {
            WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
            return;
        }

        restDelay = 0;
        staying = false;
        holding = false;
        if (commandVector.size() > 1)
        {
            std::string followDistanceStr = commandVector.at(1);
            float followDistance = atof(followDistanceStr.c_str());
            if (followDistance > FOLLOW_MIN_DISTANCE&& followDistance < FOLLOW_MAX_DISTANCE)
            {
                if (st_Group_Normal->Follow(followDistance))
                {
                    WhisperTo("Following", Language::LANG_UNIVERSAL, pmSender);
                }
                else
                {
                    WhisperTo("I will not follow you", Language::LANG_UNIVERSAL, pmSender);
                }
            }
            else
            {
                WhisperTo("Follow distance is invalid", Language::LANG_UNIVERSAL, pmSender);
            }
        }
        else
        {
            if (st_Group_Normal->Follow())
            {
                WhisperTo("Following", Language::LANG_UNIVERSAL, pmSender);
            }
            else
            {
                WhisperTo("I will not follow you", Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "stay")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (!me->IsAlive())
        {
            WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (st_Group_Normal->Stay())
        {
            staying = true;
            WhisperTo("Staying", Language::LANG_UNIVERSAL, pmSender);
        }
        else
        {
            WhisperTo("I will not stay", Language::LANG_UNIVERSAL, pmSender);
        }
    }
    else if (commandName == "hold")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (!me->IsAlive())
        {
            WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        staying = false;
        holding = true;
        WhisperTo("Holding", Language::LANG_UNIVERSAL, pmSender);
    }
    else if (commandName == "heal")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (!me->IsAlive())
        {
            WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (me->groupRole == 2)
        {
            staying = false;
            WhisperTo("I am ready to do healing", Language::LANG_UNIVERSAL, pmSender);
        }
        else
        {
            WhisperTo("I am not a healer", Language::LANG_UNIVERSAL, pmSender);
        }
    }
    else if (commandName == "attack")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (!me->IsAlive())
        {
            WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        Unit* senderTarget = pmSender->GetSelectedUnit();
        staying = false;
        if (st_Group_Normal->Attack(senderTarget))
        {
            st_Group_Normal->instruction = Group_Instruction::Group_Instruction_Battle;
            me->SetSelection(senderTarget->GetGUID());
            WhisperTo("Attack your target", Language::LANG_UNIVERSAL, pmSender);
        }
        else
        {
            WhisperTo("Can not attack your target", Language::LANG_UNIVERSAL, pmSender);
        }
    }
    else if (commandName == "rest")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (!me->IsAlive())
        {
            WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        staying = false;
        if (st_Group_Normal->Rest(true))
        {
            WhisperTo("Resting", Language::LANG_UNIVERSAL, pmSender);
        }
        else
        {
            WhisperTo("Do not rest", Language::LANG_UNIVERSAL, pmSender);
        }
    }
    else if (commandName == "who")
    {
        WhisperTo(sRobotManager->characterTalentTabNameMap[me->GetClass()][characterTalentTab], Language::LANG_UNIVERSAL, pmSender);
    }
    else if (commandName == "assemble")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (st_Group_Normal->assembleDelay > 0)
        {
            WhisperTo("I am coming", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (me->IsAlive())
        {
            if (me->GetDistance(pmSender) < 50)
            {
                if (me->HasUnitState(UnitState::UNIT_STATE_NOT_MOVE))
                {
                    WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                    return;
                }
                if (me->HasUnitState(UnitState::UNIT_STATE_ROAMING_MOVE))
                {
                    WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                    return;
                }
                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                {
                    WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                    return;
                }
                if (me->IsNonMeleeSpellCast(false, false, true))
                {
                    WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                    return;
                }
                // Can't attack if owner is pacified
                if (me->HasAuraType(SPELL_AURA_MOD_PACIFY))
                {
                    //pet->SendPetCastFail(spellid, SPELL_FAILED_PACIFIED);
                    /// @todo Send proper error message to client
                    return;
                }
                if (me->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
                {
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                }
                if (me->IsWalking())
                {
                    me->SetWalk(false);
                }

                me->SetSelection(ObjectGuid::Empty);
                me->StopMoving();
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(0, pmSender->GetPosition());
                WhisperTo("We are close, I will be ready in 5 seconds", Language::LANG_UNIVERSAL, pmSender);
            }
            else
            {
                st_Group_Normal->assembleDelay = 30 * TimeConstants::IN_MILLISECONDS;
                WhisperTo("I will come to you in 30 seconds", Language::LANG_UNIVERSAL, pmSender);
            }
        }
        else
        {
            st_Group_Normal->assembleDelay = 60 * TimeConstants::IN_MILLISECONDS;
            WhisperTo("I will revive and come to you in 60 seconds", Language::LANG_UNIVERSAL, pmSender);
        }
    }
    else if (commandName == "tank")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (!me->IsAlive())
        {
            WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (me->groupRole == 1)
        {
            Unit* senderTarget = pmSender->GetSelectedUnit();
            staying = false;
            if (st_Group_Normal->Tank(senderTarget))
            {
                st_Group_Normal->instruction = Group_Instruction::Group_Instruction_Battle;
                me->SetSelection(senderTarget->GetGUID());
                WhisperTo("Tank your target", Language::LANG_UNIVERSAL, pmSender);
            }
            else
            {
                WhisperTo("Can not tank your target", Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "prepare")
    {
        Prepare();
        me->Say("I am prepared", Language::LANG_UNIVERSAL);
    }
    else if (commandName == "switch")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (!me->IsAlive())
        {
            WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
            return;
        }

        if (me->GetClass() == Classes::CLASS_WARLOCK || me->GetClass() == Classes::CLASS_HUNTER)
        {
            Pet* checkPet = me->GetPet();
            if (!checkPet)
            {
                WhisperTo("I do not have an active pet", Language::LANG_UNIVERSAL, pmSender);
                return;
            }
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
                                    WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                                    return;
                                }
                            }
                        }
                    }
                    WhisperTo("Spell not found", Language::LANG_UNIVERSAL, pmSender);
                    return;
                }
                else
                {
                    WhisperTo("No spell name", Language::LANG_UNIVERSAL, pmSender);
                    return;
                }
            }
            else
            {
                WhisperTo("No auto state", Language::LANG_UNIVERSAL, pmSender);
                return;
            }
        }
        else
        {
            WhisperTo("I am not hunter or a warlock", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
    }
    else if (commandName == "cast")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (!me->IsAlive())
        {
            WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        Unit* senderTarget = pmSender->GetSelectedUnit();
        if (!senderTarget)
        {
            WhisperTo("You do not have a target", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
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
            std::ostringstream replyStream;
            if (CastSpell(senderTarget, spellName))
            {
                replyStream << "Cast spell " << spellName << " on " << senderTarget->GetName();
            }
            else
            {
                replyStream << "Can not cast spell " << spellName << " on " << senderTarget->GetName();
            }
            WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
        }
    }
    else if (commandName == "cancel")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (!me->IsAlive())
        {
            WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        Unit* senderTarget = pmSender->GetSelectedUnit();
        if (!senderTarget)
        {
            WhisperTo("You do not have a target", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
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
            std::ostringstream replyStream;
            if (CancelAura(spellName))
            {
                replyStream << "Cancel aura " << spellName;
            }
            else
            {
                replyStream << "Unknown spell " << spellName;
            }
            WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
        }
    }
    else if (commandName == "use")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }

        std::ostringstream replyStream;
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
                    Trinity::GameObjectInRangeCheck check(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), MELEE_MAX_DISTANCE);
                    Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(me, nearGOList, check);
                    Cell::VisitGridObjects(me, searcher, SIZE_OF_GRIDS);
                    for (std::list<GameObject*>::iterator it = nearGOList.begin(); it != nearGOList.end(); it++)
                    {
                        if ((*it)->GetName() == goName)
                        {
                            me->SetFacingToObject((*it));
                            WorldPacket* const packetgouse = new WorldPacket(CMSG_GAMEOBJ_REPORT_USE, 8);
                            *packetgouse << (*it)->GetGUID();
                            me->GetSession()->HandleGameObjectUseOpcode(*packetgouse);
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
        WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
    }
    else if (commandName == "stop")
    {
        if (!master)
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        if (pmSender->GetGUID() != master->GetGUID())
        {
            WhisperTo("You are not my master", Language::LANG_UNIVERSAL, pmSender);
            return;
        }
        me->StopMoving();
        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
        std::ostringstream replyStream;
        replyStream << "Stopped";
        WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
    }
}

uint32 RobotAI::FindSpellID(std::string pmSpellName)
{
    if (spellIDMap.find(pmSpellName) != spellIDMap.end())
    {
        return spellIDMap[pmSpellName];
    }

    return 0;
}

bool RobotAI::SpellValid(uint32 pmSpellID)
{
    if (pmSpellID == 0)
    {
        return false;
    }
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }
    if (me->GetSpellHistory()->HasCooldown(pmSpellID))
    {
        return false;
    }
    return true;
}

bool RobotAI::CancelAura(std::string pmSpellName)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return false;
    }
    std::set<uint32> spellIDSet = sRobotManager->spellNameEntryMap[pmSpellName];
    for (std::set<uint32>::iterator it = spellIDSet.begin(); it != spellIDSet.end(); it++)
    {
        if (me->HasAura((*it)))
        {
            CancelAura((*it));
            return true;
        }
    }

    return false;
}

void RobotAI::CancelAura(uint32 pmSpellID)
{
    if (pmSpellID == 0)
    {
        return;
    }
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return;
    }
    WorldPacket data(CMSG_CANCEL_AURA, 4);
    data << pmSpellID;
    me->GetSession()->HandleCancelAuraOpcode(data);
}

void RobotAI::ClearShapeshift()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(characterGUID);
    if (!me)
    {
        return;
    }

    uint32 spellID = 0;
    switch (me->GetShapeshiftForm())
    {
    case ShapeshiftForm::FORM_NONE:
    {
        break;
    }
    case ShapeshiftForm::FORM_CAT:
    {
        spellID = FindSpellID("Cat Form");
        break;
    }
    case ShapeshiftForm::FORM_DIREBEAR:
    {
        spellID = FindSpellID("Dire Bear Form");
        break;
    }
    case ShapeshiftForm::FORM_BEAR:
    {
        spellID = FindSpellID("Bear Form");
        break;
    }
    case ShapeshiftForm::FORM_MOONKIN:
    {
        spellID = FindSpellID("Moonkin Form");
        break;
    }
    default:
    {
        break;
    }
    }
    CancelAura(spellID);
}

void RobotAI::DoAttack(Unit* pmTarget, bool pmMelee)
{

}

void RobotAI::Logout()
{
    Player* checkP = ObjectAccessor::FindConnectedPlayer(characterGUID);
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
