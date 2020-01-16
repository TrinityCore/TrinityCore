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
    prevUpdate = time(NULL);
    sourcePlayer = NULL;
    sourceSession = NULL;
    masterPlayer = NULL;
    strategiesMap.clear();
    strategiesMap["solo_normal"] = true;
    strategiesMap["group_normal"] = false;
    characterTalentTab = 0;

    targetLevel = pmTargetLevel;
    targetClass = pmTargetClass;
    targetRace = pmTargetRace;

    std::ostringstream accountNameStream;
    accountNameStream << sRobotConfig->robotAccountNamePrefix << "l" << std::to_string(targetLevel) << "r" << std::to_string(targetRace) << "c" << std::to_string(targetClass);
    accountName = accountNameStream.str();

    accountID = 0;
    characterID = 0;
    characterType = 0;

    checkDelay = urand(TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS);
    onlineDelay = 0;
    offlineDelay = 0;

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
    strategiesMap["solo_normal"] = true;
    st_Solo_Normal->soloDuration = 0;
    strategiesMap["group_normal"] = false;
    st_Group_Normal->staying = false;
    sourcePlayer->Say("Strategy reset", Language::LANG_UNIVERSAL);

    if (sourcePlayer->GetClass() == Classes::CLASS_HUNTER)
    {
        Pet* checkPet = sourcePlayer->GetPet();
        if (checkPet)
        {
            std::unordered_map<uint32, PetSpell> petSpellMap = checkPet->m_spells;
            for (std::unordered_map<uint32, PetSpell>::iterator it = petSpellMap.begin(); it != petSpellMap.end(); it++)
            {
                if (it->second.active == ACT_DISABLED)
                {
                    const SpellInfo* pST = sSpellMgr->GetSpellInfo(it->first);
                    if (pST)
                    {
                        std::string checkNameStr = std::string(pST->SpellName[0]);
                        if (checkNameStr == "Prowl")
                        {
                            continue;
                        }
                        checkPet->ToggleAutocast(pST, true);
                    }
                }
            }
        }
    }
}

void RobotAI::InitializeCharacter()
{
    bool initialEquip = false;
    if (sourcePlayer->GetLevel() != targetLevel)
    {
        initialEquip = true;
        sourcePlayer->GiveLevel(targetLevel);
        sourcePlayer->LearnDefaultSkills();
        for (std::set<uint32>::iterator questIT = sRobotManager->spellRewardClassQuestIDSet.begin(); questIT != sRobotManager->spellRewardClassQuestIDSet.end(); questIT++)
        {
            const Quest* eachQuest = sObjectMgr->GetQuestTemplate((*questIT));
            if (sourcePlayer->SatisfyQuestLevel(eachQuest, false) && sourcePlayer->SatisfyQuestClass(eachQuest, false) && sourcePlayer->SatisfyQuestRace(eachQuest, false))
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
                        sourcePlayer->LearnSpell((*toLearnIT), false);
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
                        sourcePlayer->LearnSpell((*toLearnIT), false);
                    }
                }
            }
        }
        uint8 specialty = urand(0, 2);
        uint32 classMask = sourcePlayer->GetClassMask();
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
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "%s: No spells for talent row %d", sourcePlayer->GetName(), i->first);
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
                sourcePlayer->LearnTalent((*it)->TalentID, maxRank);
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
            if (!tInfo->IsTrainerValidForPlayer(sourcePlayer))
                continue;
            std::unordered_set<uint32> trainerSpellIDs = tInfo->GetAllSpellsID();

            for (std::unordered_set<uint32>::const_iterator itr = trainerSpellIDs.begin(); itr != trainerSpellIDs.end(); ++itr)
            {
                uint32 eachSpellID = *itr;
                if (!sourcePlayer->IsSpellFitByClassAndRace(eachSpellID))
                {
                    continue;
                }
                if (!tInfo->SpellValidToTrain(sourcePlayer, eachSpellID))
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
                sourcePlayer->LearnSpell(checkSpellID, false);
            }
        }
        sourcePlayer->UpdateSkillsForLevel();

        if (sourcePlayer->GetClass() == Classes::CLASS_HUNTER)
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Create pet for player %s", sourcePlayer->GetName());
            uint32 beastEntry = urand(0, sRobotManager->tamableBeastEntryMap.size() - 1);
            beastEntry = sRobotManager->tamableBeastEntryMap[beastEntry];
            CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(beastEntry);
            if (!cinfo)
            {
                return;
            }

            Pet* pet = new Pet(sourcePlayer, HUNTER_PET);
            uint32 guid = sourcePlayer->GetMap()->GenerateLowGuid<HighGuid::Pet>();
            uint32 pet_number = sObjectMgr->GeneratePetNumber();
            if (!pet->Create(guid, sourcePlayer->GetMap(), 0, cinfo->Entry, pet_number))
            {
                delete pet;
                return;
            }
            pet->SetReactState(REACT_DEFENSIVE);
            pet->SetFaction(sourcePlayer->GetFaction());
            pet->SetUInt32Value(UNIT_CREATED_BY_SPELL, 1515);
            if (sourcePlayer->IsPvP())
            {
                pet->SetPvP(true);
            }
            pet->InitStatsForLevel(sourcePlayer->GetLevel());
            pet->GetCharmInfo()->SetPetNumber(sObjectMgr->GeneratePetNumber(), true);
            // this enables pet details window (Shift+P)
            pet->AIM_Initialize();
            pet->InitPetCreateSpells();
            pet->SetHealth(pet->GetMaxHealth());
            // prepare visual effect for levelup
            pet->SetUInt32Value(UNIT_FIELD_LEVEL, sourcePlayer->GetLevel());
            // add to world
            pet->GetMap()->AddToMap((Creature*)pet);

            // caster have pet now
            sourcePlayer->SetPetGUID(pet->GetGUID());

            pet->SavePetToDB(PET_SAVE_AS_CURRENT);
            sourcePlayer->PetSpellInitialize();
        }
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Player %s basic info initialized", sourcePlayer->GetName());

        std::ostringstream msgStream;
        msgStream << sourcePlayer->GetName() << " initialized";
        sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, msgStream.str().c_str());
    }

    spellLevelMap.clear();
    bool typeChecked = false;
    characterType = 0;
    sourcePlayer->groupRole = 0;
    for (PlayerSpellMap::iterator it = sourcePlayer->GetSpellMap().begin(); it != sourcePlayer->GetSpellMap().end(); it++)
    {
        const SpellInfo* pST = sSpellMgr->GetSpellInfo(it->first);
        if (pST)
        {
            std::string checkNameStr = std::string(pST->SpellName[0]);
            if (!typeChecked)
            {
                switch (sourcePlayer->GetClass())
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
                        sourcePlayer->groupRole = 1;
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
                    if (checkNameStr == "Monster Slaying")
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
                        sourcePlayer->groupRole = 2;
                        typeChecked = true;
                    }
                    break;
                }
                case Classes::CLASS_PALADIN:
                {
                    if (checkNameStr == "Divine Strength")
                    {
                        characterTalentTab = 0;
                        characterType = 2;
                        sourcePlayer->groupRole = 2;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Improved Devotion Aura")
                    {
                        characterTalentTab = 1;
                        characterType = 1;
                        sourcePlayer->groupRole = 1;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Improved Blessing of Might")
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
                        sourcePlayer->groupRole = 2;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Healing Focus")
                    {
                        characterTalentTab = 1;
                        characterType = 2;
                        sourcePlayer->groupRole = 2;
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
                    if (checkNameStr == "Improved Wrath")
                    {
                        characterTalentTab = 0;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Ferocity")
                    {
                        characterTalentTab = 1;
                        characterType = 1;
                        sourcePlayer->groupRole = 1;
                        typeChecked = true;
                    }
                    if (checkNameStr == "Improved Mark of the Wild")
                    {
                        characterTalentTab = 2;
                        characterType = 2;
                        sourcePlayer->groupRole = 2;
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

    if (initialEquip)
    {
        for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; i++)
        {
            if (Item * pItem = sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            {
                sourcePlayer->DestroyItem(INVENTORY_SLOT_BAG_0, i, true);
            }
        }

        switch (sourcePlayer->GetClass())
        {
        case Classes::CLASS_WARRIOR:
        {
            int levelRange = sourcePlayer->GetLevel() / 10;
            int checkLevelRange = levelRange;
            bool validEquip = false;
            int maxTryTimes = 5;

            if (characterType == 1)
            {
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->meleeWeaponMap[1][checkLevelRange].size() > 0)
                    {
                        // use one hand sword
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->meleeWeaponMap[1][checkLevelRange].size() - 1);
                            entry = sRobotManager->meleeWeaponMap[1][checkLevelRange][entry];
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

                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->meleeWeaponMap[4][checkLevelRange].size() > 0)
                    {
                        // use shield
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->meleeWeaponMap[4][checkLevelRange].size() - 1);
                            entry = sRobotManager->meleeWeaponMap[4][checkLevelRange][entry];
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
            else
            {
                int levelRange = sourcePlayer->GetLevel() / 10;
                int checkLevelRange = levelRange;
                bool validEquip = false;
                int maxTryTimes = 5;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->meleeWeaponMap[2][checkLevelRange].size() > 0)
                    {
                        // use two hand sword
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->meleeWeaponMap[2][checkLevelRange].size() - 1);
                            entry = sRobotManager->meleeWeaponMap[2][checkLevelRange][entry];
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

            int armorType = 2;
            if (sourcePlayer->GetLevel() < 40)
            {
                // use mail armor
                armorType = 2;
            }
            else
            {
                // use plate armor
                armorType = 3;
            }
            for (std::set<uint8>::iterator inventoryTypeIT = sRobotManager->armorInventorySet.begin(); inventoryTypeIT != sRobotManager->armorInventorySet.end(); inventoryTypeIT++)
            {
                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange].size() > 0)
                    {
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange].size() - 1);
                            entry = sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange][entry];
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
            break;
        }
        case Classes::CLASS_HUNTER:
        {
            // set two hand axe, two hand sword, polearms		
            int levelRange = sourcePlayer->GetLevel() / 10;
            int checkLevelRange = levelRange;
            bool validEquip = false;
            int maxTryTimes = 5;
            while (checkLevelRange >= 0)
            {
                int weaponType = 0;
                if (urand(0, 2) == 0)
                {
                    weaponType = 6;
                    if (sRobotManager->meleeWeaponMap[weaponType][checkLevelRange].size() > 0)
                    {
                        // use polearms
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            if (sRobotManager->meleeWeaponMap[weaponType][checkLevelRange].size() == 0)
                            {
                                break;
                            }
                            uint32 entry = urand(0, sRobotManager->meleeWeaponMap[weaponType][checkLevelRange].size() - 1);
                            entry = sRobotManager->meleeWeaponMap[weaponType][checkLevelRange][entry];
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
                }
                if (urand(0, 1) == 0)
                {
                    weaponType = 2;
                    if (sRobotManager->meleeWeaponMap[weaponType][checkLevelRange].size() > 0)
                    {
                        // use two hand sword
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->meleeWeaponMap[weaponType][checkLevelRange].size() - 1);
                            entry = sRobotManager->meleeWeaponMap[weaponType][checkLevelRange][entry];
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
                }
                weaponType = 5;
                if (sRobotManager->meleeWeaponMap[weaponType][checkLevelRange].size() > 0)
                {
                    // use two hand axe
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->meleeWeaponMap[weaponType][checkLevelRange].size() - 1);
                        entry = sRobotManager->meleeWeaponMap[weaponType][checkLevelRange][entry];
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
            checkLevelRange = levelRange;
            validEquip = false;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->rangeWeaponMap[0][checkLevelRange].size() > 0)
                {
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->rangeWeaponMap[0][checkLevelRange].size() - 1);
                        entry = sRobotManager->rangeWeaponMap[0][checkLevelRange][entry];
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
            int armorType = 1;
            if (sourcePlayer->GetLevel() < 40)
            {
                // use leather armor
                armorType = 1;
            }
            else
            {
                // use mail armor
                armorType = 2;
            }
            for (std::set<uint8>::iterator inventoryTypeIT = sRobotManager->armorInventorySet.begin(); inventoryTypeIT != sRobotManager->armorInventorySet.end(); inventoryTypeIT++)
            {
                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange].size() > 0)
                    {
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange].size() - 1);
                            entry = sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange][entry];
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

            // quiver and ammo pouch
            Item* weapon = sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
            if (weapon)
            {
                uint32 subClass = weapon->GetTemplate()->SubClass;
                if (subClass == ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_BOW || subClass == ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_CROSSBOW)
                {
                    sourcePlayer->StoreNewItemInBestSlots(2101, 1);
                }
                else if (subClass == ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_GUN)
                {
                    sourcePlayer->StoreNewItemInBestSlots(2102, 1);
                }
            }
            break;
        }
        case Classes::CLASS_SHAMAN:
        {
            // set staff		
            int levelRange = sourcePlayer->GetLevel() / 10;
            int checkLevelRange = levelRange;
            bool validEquip = false;
            int maxTryTimes = 5;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->meleeWeaponMap[0][checkLevelRange].size() > 0)
                {
                    // use staff
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->meleeWeaponMap[0][checkLevelRange].size() - 1);
                        entry = sRobotManager->meleeWeaponMap[0][checkLevelRange][entry];
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

            int armorType = 1;
            if (sourcePlayer->GetLevel() < 40)
            {
                // use leather armor
                armorType = 1;
            }
            else
            {
                // use mail armor
                armorType = 2;
            }
            for (std::set<uint8>::iterator inventoryTypeIT = sRobotManager->armorInventorySet.begin(); inventoryTypeIT != sRobotManager->armorInventorySet.end(); inventoryTypeIT++)
            {
                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange].size() > 0)
                    {
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange].size() - 1);
                            entry = sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange][entry];
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
            break;
        }
        case Classes::CLASS_PALADIN:
        {
            int levelRange = sourcePlayer->GetLevel() / 10;
            int checkLevelRange = levelRange;
            bool validEquip = false;
            int maxTryTimes = 5;

            if (characterType == 1)
            {
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->meleeWeaponMap[1][checkLevelRange].size() > 0)
                    {
                        // use two hand sword
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->meleeWeaponMap[1][checkLevelRange].size() - 1);
                            entry = sRobotManager->meleeWeaponMap[1][checkLevelRange][entry];
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

                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->meleeWeaponMap[4][checkLevelRange].size() > 0)
                    {
                        // use shield
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->meleeWeaponMap[4][checkLevelRange].size() - 1);
                            entry = sRobotManager->meleeWeaponMap[4][checkLevelRange][entry];
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
            else
            {
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->meleeWeaponMap[2][checkLevelRange].size() > 0)
                    {
                        // use two hand sword
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->meleeWeaponMap[2][checkLevelRange].size() - 1);
                            entry = sRobotManager->meleeWeaponMap[2][checkLevelRange][entry];
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

            int armorType = 2;
            if (sourcePlayer->GetLevel() < 40)
            {
                // use mail armor
                armorType = 2;
            }
            else
            {
                // use plate armor
                armorType = 3;
            }
            for (std::set<uint8>::iterator inventoryTypeIT = sRobotManager->armorInventorySet.begin(); inventoryTypeIT != sRobotManager->armorInventorySet.end(); inventoryTypeIT++)
            {
                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange].size() > 0)
                    {
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange].size() - 1);
                            entry = sRobotManager->armorMap[armorType][(*inventoryTypeIT)][checkLevelRange][entry];
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
            break;
        }
        case Classes::CLASS_WARLOCK:
        {
            // set staff		
            int levelRange = sourcePlayer->GetLevel() / 10;
            int checkLevelRange = levelRange;
            bool validEquip = false;
            int maxTryTimes = 5;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->meleeWeaponMap[0][checkLevelRange].size() > 0)
                {
                    // use staff
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->meleeWeaponMap[0][checkLevelRange].size() - 1);
                        entry = sRobotManager->meleeWeaponMap[0][checkLevelRange][entry];
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

            // set wand
            checkLevelRange = levelRange;
            validEquip = false;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->rangeWeaponMap[1][checkLevelRange].size() > 0)
                {
                    // use wand
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->rangeWeaponMap[1][checkLevelRange].size() - 1);
                        entry = sRobotManager->rangeWeaponMap[1][checkLevelRange][entry];
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

            // use cloth armor
            for (std::set<uint8>::iterator inventoryTypeIT = sRobotManager->armorInventorySet.begin(); inventoryTypeIT != sRobotManager->armorInventorySet.end(); inventoryTypeIT++)
            {
                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->armorMap[0][(*inventoryTypeIT)][checkLevelRange].size() > 0)
                    {
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->armorMap[0][(*inventoryTypeIT)][checkLevelRange].size() - 1);
                            entry = sRobotManager->armorMap[0][(*inventoryTypeIT)][checkLevelRange][entry];
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
            break;
        }
        case Classes::CLASS_PRIEST:
        {
            // set staff		
            int levelRange = sourcePlayer->GetLevel() / 10;
            int checkLevelRange = levelRange;
            bool validEquip = false;
            int maxTryTimes = 5;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->meleeWeaponMap[0][checkLevelRange].size() > 0)
                {
                    // use staff
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->meleeWeaponMap[0][checkLevelRange].size() - 1);
                        entry = sRobotManager->meleeWeaponMap[0][checkLevelRange][entry];
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

            // set wand
            checkLevelRange = levelRange;
            validEquip = false;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->rangeWeaponMap[1][checkLevelRange].size() > 0)
                {
                    // use wand
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->rangeWeaponMap[1][checkLevelRange].size() - 1);
                        entry = sRobotManager->rangeWeaponMap[1][checkLevelRange][entry];
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

            // use cloth armor
            for (std::set<uint8>::iterator inventoryTypeIT = sRobotManager->armorInventorySet.begin(); inventoryTypeIT != sRobotManager->armorInventorySet.end(); inventoryTypeIT++)
            {
                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->armorMap[0][(*inventoryTypeIT)][checkLevelRange].size() > 0)
                    {
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->armorMap[0][(*inventoryTypeIT)][checkLevelRange].size() - 1);
                            entry = sRobotManager->armorMap[0][(*inventoryTypeIT)][checkLevelRange][entry];
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
            break;
        }
        case Classes::CLASS_ROGUE:
        {
            // set dagger		
            int levelRange = sourcePlayer->GetLevel() / 10;
            int checkLevelRange = levelRange;
            bool validEquip = false;
            int maxTryTimes = 5;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->meleeWeaponMap[3][checkLevelRange].size() > 0)
                {
                    // use double dagger
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->meleeWeaponMap[3][checkLevelRange].size() - 1);
                        entry = sRobotManager->meleeWeaponMap[3][checkLevelRange][entry];
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
            checkLevelRange = levelRange;
            validEquip = false;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->meleeWeaponMap[3][checkLevelRange].size() > 0)
                {
                    // use double dagger
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->meleeWeaponMap[3][checkLevelRange].size() - 1);
                        entry = sRobotManager->meleeWeaponMap[3][checkLevelRange][entry];
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
            // use leather armor
            for (std::set<uint8>::iterator inventoryTypeIT = sRobotManager->armorInventorySet.begin(); inventoryTypeIT != sRobotManager->armorInventorySet.end(); inventoryTypeIT++)
            {
                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->armorMap[1][(*inventoryTypeIT)][checkLevelRange].size() > 0)
                    {
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->armorMap[1][(*inventoryTypeIT)][checkLevelRange].size() - 1);
                            entry = sRobotManager->armorMap[1][(*inventoryTypeIT)][checkLevelRange][entry];
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
            break;
        }
        case Classes::CLASS_MAGE:
        {
            // set staff		
            int levelRange = sourcePlayer->GetLevel() / 10;
            int checkLevelRange = levelRange;
            bool validEquip = false;
            int maxTryTimes = 5;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->meleeWeaponMap[0][checkLevelRange].size() > 0)
                {
                    // use staff
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->meleeWeaponMap[0][checkLevelRange].size() - 1);
                        entry = sRobotManager->meleeWeaponMap[0][checkLevelRange][entry];
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

            // set wand
            checkLevelRange = levelRange;
            validEquip = false;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->rangeWeaponMap[1][checkLevelRange].size() > 0)
                {
                    // use wand
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->rangeWeaponMap[1][checkLevelRange].size() - 1);
                        entry = sRobotManager->rangeWeaponMap[1][checkLevelRange][entry];
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

            // use cloth armor
            for (std::set<uint8>::iterator inventoryTypeIT = sRobotManager->armorInventorySet.begin(); inventoryTypeIT != sRobotManager->armorInventorySet.end(); inventoryTypeIT++)
            {
                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->armorMap[0][(*inventoryTypeIT)][checkLevelRange].size() > 0)
                    {
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->armorMap[0][(*inventoryTypeIT)][checkLevelRange].size() - 1);
                            entry = sRobotManager->armorMap[0][(*inventoryTypeIT)][checkLevelRange][entry];
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
            break;
        }
        case Classes::CLASS_DRUID:
        {
            // set staff		
            int levelRange = sourcePlayer->GetLevel() / 10;
            int checkLevelRange = levelRange;
            bool validEquip = false;
            int maxTryTimes = 5;
            while (checkLevelRange >= 0)
            {
                if (sRobotManager->meleeWeaponMap[0][checkLevelRange].size() > 0)
                {
                    // use staff
                    for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                    {
                        uint32 entry = urand(0, sRobotManager->meleeWeaponMap[0][checkLevelRange].size() - 1);
                        entry = sRobotManager->meleeWeaponMap[0][checkLevelRange][entry];
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

            // use leather armor
            for (std::set<uint8>::iterator inventoryTypeIT = sRobotManager->armorInventorySet.begin(); inventoryTypeIT != sRobotManager->armorInventorySet.end(); inventoryTypeIT++)
            {
                checkLevelRange = levelRange;
                validEquip = false;
                while (checkLevelRange >= 0)
                {
                    if (sRobotManager->armorMap[1][(*inventoryTypeIT)][checkLevelRange].size() > 0)
                    {
                        for (int checkCount = 0; checkCount < maxTryTimes; checkCount++)
                        {
                            uint32 entry = urand(0, sRobotManager->armorMap[1][(*inventoryTypeIT)][checkLevelRange].size() - 1);
                            entry = sRobotManager->armorMap[1][(*inventoryTypeIT)][checkLevelRange][entry];
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
            break;
        }
        default:
        {
            break;
        }
        }

        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Player %s equip info initialized", sourcePlayer->GetName());
    }
}

void RobotAI::Prepare()
{
    sourcePlayer->DurabilityRepairAll(false, 0, false);
    if (sourcePlayer->GetClass() == Classes::CLASS_HUNTER)
    {
        uint32 ammoEntry = 0;
        Item* weapon = sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
        if (weapon)
        {
            uint32 subClass = weapon->GetTemplate()->SubClass;
            uint8 playerLevel = sourcePlayer->GetLevel();
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
                if (!sourcePlayer->HasItemCount(ammoEntry, 100))
                {
                    sourcePlayer->StoreNewItemInBestSlots(ammoEntry, 1000);
                    sourcePlayer->SetAmmo(ammoEntry);
                }
            }
        }
    }
    Pet* checkPet = sourcePlayer->GetPet();
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
            if (it->second.active == ACT_DISABLED)
            {
                const SpellInfo* pST = sSpellMgr->GetSpellInfo(it->first);
                if (pST)
                {
                    std::string checkNameStr = std::string(pST->SpellName[0]);
                    if (checkNameStr == "Prowl")
                    {
                        continue;
                    }
                    checkPet->ToggleAutocast(pST, true);
                }
            }
        }
    }
}

void RobotAI::Refresh()
{
    if (!sourcePlayer->IsAlive())
    {
        sourcePlayer->ResurrectPlayer(100);
    }
    sourcePlayer->SetFullHealth();
    sourcePlayer->ClearInCombat();
    sourcePlayer->GetThreatManager().ClearAllThreat();
    sourcePlayer->GetMotionMaster()->Clear();
}

void RobotAI::RandomTeleport()
{
    if (sourcePlayer->IsBeingTeleported())
    {
        return;
    }
    uint8 levelRange = sourcePlayer->GetLevel() / 10;
    uint32 destIndex = urand(0, sRobotManager->teleportCacheMap[levelRange].size() - 1);
    WorldLocation destWL = sRobotManager->teleportCacheMap[levelRange][destIndex];
    Map * targetMap = sMapMgr->FindBaseNonInstanceMap(destWL.m_mapId);
    if (targetMap)
    {
        sourcePlayer->TeleportTo(destWL);
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Teleport robot %s (level %d)", sourcePlayer->GetName(), sourcePlayer->GetLevel());
    }
}

bool RobotAI::HasAura(Unit * pmTarget, std::string pmSpellName, bool pmOnlyMyAura)
{
    Unit* target = pmTarget;
    if (!pmTarget)
    {
        target = sourcePlayer;
    }
    std::set<uint32> spellIDSet = sRobotManager->spellNameEntryMap[pmSpellName];
    for (std::set<uint32>::iterator it = spellIDSet.begin(); it != spellIDSet.end(); it++)
    {
        if (pmOnlyMyAura)
        {
            if (target->HasAura((*it), sourcePlayer->GetGUID()))
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

bool RobotAI::CastSpell(Unit * pmTarget, std::string pmSpellName, float pmDistance, bool pmCheckAura, bool pmOnlyMyAura, bool pmClearShapeshift)
{
    if (sourcePlayer->IsNonMeleeSpellCast(true))
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
        target = sourcePlayer;
    }
    if (target->GetGUID() != sourcePlayer->GetGUID())
    {
        float currentDistance = sourcePlayer->GetDistance(target);
        if (currentDistance > pmDistance)
        {
            return false;
        }
        else
        {
            if (!sourcePlayer->IsWithinLOSInMap(target))
            {
                return false;
            }
            if (!sourcePlayer->isInFront(target, pmDistance))
            {
                sourcePlayer->SetInFront(target);
            }
            sourcePlayer->SetSelection(target->GetGUID());
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
    if (target->IsImmunedToSpell(pST, sourcePlayer))
    {
        return false;
    }
    if (pST->IsChanneled())
    {
        sourcePlayer->StopMoving();
    }
    else
    {
        if (pST->CalcCastTime() > 0)
        {
            sourcePlayer->GetMotionMaster()->MoveIdle();
        }
    }
    for (size_t i = 0; i < MAX_SPELL_REAGENTS; i++)
    {
        if (pST->Reagent[i] > 0)
        {
            if (!sourcePlayer->HasItemCount(pST->Reagent[i], pST->ReagentCount[i]))
            {
                sourcePlayer->StoreNewItemInBestSlots(pST->Reagent[i], pST->ReagentCount[i] * 10);
            }
        }
    }
    if (sourcePlayer->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
    {
        sourcePlayer->SetStandState(UNIT_STAND_STATE_STAND);
    }
    sourcePlayer->CastSpell(target, spellID, TriggerCastFlags::TRIGGERED_NONE);

    return true;
}

void RobotAI::BaseMove(Unit * pmTarget, float pmDistance, bool pmMelee, bool pmAttack)
{
    if (sourcePlayer->HasUnitState(UnitState::UNIT_STATE_NOT_MOVE))
    {
        return;
    }
    if (sourcePlayer->HasUnitState(UnitState::UNIT_STATE_ROAMING_MOVE))
    {
        return;
    }
    // Can't attack if owner is pacified
    if (sourcePlayer->HasAuraType(SPELL_AURA_MOD_PACIFY))
    {
        //pet->SendPetCastFail(spellid, SPELL_FAILED_PACIFIED);
        /// @todo Send proper error message to client
        return;
    }
    if (sourcePlayer->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
    {
        sourcePlayer->SetStandState(UNIT_STAND_STATE_STAND);
    }
    if (sourcePlayer->IsWalking())
    {
        sourcePlayer->SetWalk(false);
    }
    sourcePlayer->SetSelection(pmTarget->GetGUID());
    if (pmMelee)
    {
        MoveMelee(pmTarget);
        if (pmAttack)
        {
            sourcePlayer->Attack(pmTarget, pmMelee);
        }
    }
    else
    {
        MoveCLose(pmTarget, pmDistance);
    }
    Pet* myPet = sourcePlayer->GetPet();
    if (myPet)
    {
        CharmInfo* charmInfo = myPet->GetCharmInfo();
        charmInfo->SetCommandState(CommandStates::COMMAND_FOLLOW);

        myPet->SetReactState(ReactStates::REACT_DEFENSIVE);

        //10% chance to play special pet attack talk, else growl
        if (myPet->IsPet() && ((Pet*)myPet)->getPetType() == SUMMON_PET && myPet != pmTarget && urand(0, 100) < 10)
        {
            myPet->SendPetTalk((uint32)PET_TALK_ATTACK);
        }
        else
        {
            // 90% chance for pet and 100% chance for charmed creature
            myPet->SendPetAIReaction(myPet->GetGUID());
        }
    }
}

void RobotAI::MoveMelee(Unit * pmTarget)
{
    if (sourcePlayer->GetDistance(pmTarget) > MELEE_MAX_DISTANCE)
    {
        float targetX = 0;
        float targetY = 0;
        float targetZ = 0;
        pmTarget->GetClosePoint(targetX, targetY, targetZ, sourcePlayer->GetCombatReach(), MELEE_COMBAT_DISTANCE);
        sourcePlayer->GetMotionMaster()->MovePoint(0, targetX, targetY, targetZ);
    }
    else
    {
        if (!sourcePlayer->isInFront(pmTarget, M_PI / 4))
        {
            sourcePlayer->SetInFront(pmTarget);
        }
        else if (sourcePlayer->isMoving())
        {
            sourcePlayer->StopMoving();
        }
    }
}

void RobotAI::MoveCLose(Unit * pmTarget, float pmDistance)
{
    float currentDistance = sourcePlayer->GetDistance(pmTarget);
    if (currentDistance > pmDistance + MELEE_MAX_DISTANCE)
    {
        float targetX = 0;
        float targetY = 0;
        float targetZ = 0;
        pmTarget->GetClosePoint(targetX, targetY, targetZ, sourcePlayer->GetCombatReach(), pmDistance);
        sourcePlayer->GetMotionMaster()->MovePoint(0, targetX, targetY, targetZ);
    }
    else if (!sourcePlayer->IsWithinLOSInMap(pmTarget))
    {
        sourcePlayer->GetMotionMaster()->MovePoint(0, pmTarget->GetPositionX(), pmTarget->GetPositionY(), pmTarget->GetPositionZ(), true);
    }
    else
    {
        if (!sourcePlayer->isInFront(pmTarget, M_PI / 4))
        {
            sourcePlayer->SetInFront(pmTarget);
        }
        else if (sourcePlayer->isMoving())
        {
            sourcePlayer->StopMoving();
        }
    }
}

void RobotAI::WhisperTo(std::string pmContent, Language pmLanguage, Player * pmTarget)
{
    sourcePlayer->Whisper(pmContent, pmLanguage, pmTarget);
}

bool RobotAI::HandlePacket()
{
    if (sourceSession)
    {
        for (std::set<const WorldPacket*>::iterator wpIT = sourceSession->robotPacketSet.begin(); wpIT != sourceSession->robotPacketSet.end(); wpIT++)
        {
            const WorldPacket* destPacket = *wpIT;

            if (destPacket)
            {
                switch (destPacket->GetOpcode())
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
                    Group* grp = sourcePlayer->GetGroupInvite();
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
                    if (inviter->GetLevel() < sourcePlayer->GetLevel())
                    {
                        uint32 lowGUID = inviter->GetGUID().GetCounter();
                        if (interestMap.find(lowGUID) == interestMap.end())
                        {
                            uint8 levelGap = sourcePlayer->GetLevel() - inviter->GetLevel();
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
                        WorldPacket p;
                        uint32 roles_mask = 0;
                        p << roles_mask;
                        sourcePlayer->GetSession()->HandleGroupAcceptOpcode(p);
                        SetStrategy("solo_normal", false);
                        SetStrategy("group_normal", true);
                        WhisperTo("Strategy set to group", Language::LANG_UNIVERSAL, inviter);
                        masterPlayer = inviter;
                        WhisperTo("You are my master", Language::LANG_UNIVERSAL, inviter);
                        std::ostringstream replyStream_Talent;
                        replyStream_Talent << "My talent category is " << sRobotManager->characterTalentTabNameMap[sourcePlayer->GetClass()][characterTalentTab];
                        WhisperTo(replyStream_Talent.str(), Language::LANG_UNIVERSAL, inviter);
                        std::ostringstream replyStream_GroupRole;
                        replyStream_GroupRole << "My group role is ";
                        switch (sourcePlayer->groupRole)
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
                        sourcePlayer->GetMotionMaster()->Clear();
                        break;
                    }
                    else
                    {
                        WorldPacket p;
                        sourcePlayer->GetSession()->HandleGroupDeclineOpcode(p);
                        std::ostringstream timeLeftStream;
                        timeLeftStream << "Not interested. I will reconsider in " << st_Solo_Normal->interestsDelay << " seconds";
                        WhisperTo(timeLeftStream.str(), Language::LANG_UNIVERSAL, inviter);
                        break;
                    }
                }
                case SMSG_GROUP_UNINVITE:
                {
                    //masterPlayer = NULL;
                    //ResetStrategy();
                    //sourcePlayer->Say("Strategy set to solo", Language::LANG_UNIVERSAL);
                    //sRobotManager->RefreshRobot(sourcePlayer);
                    break;
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
                    //    if (newLeader->GetGUID() == sourcePlayer->GetGUID())
                    //    {
                    //        WorldPacket data(CMSG_GROUP_SET_LEADER, 8);
                    //        data << masterPlayer->GetGUID().WriteAsPacked();
                    //        sourcePlayer->GetSession()->HandleGroupSetLeaderOpcode(data);
                    //    }
                    //    else
                    //    {
                    //        if (!newLeader->isRobot)
                    //        {
                    //            masterPlayer = newLeader;
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
                    if (!sourcePlayer->IsAlive())
                    {
                        st_Solo_Normal->deathDuration = 0;
                    }
                    sourcePlayer->ResurrectUsingRequestData();
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
                    if (!sourcePlayer->duel)
                    {
                        break;
                    }
                    sourcePlayer->DuelComplete(DuelCompleteType::DUEL_INTERRUPTED);
                    WhisperTo("Not interested", Language::LANG_UNIVERSAL, sourcePlayer->duel->Opponent);
                    break;
                }
                default:
                {
                    break;
                }
                }
            }
        }
        sourceSession->robotPacketSet.clear();
    }
    return false;
}

void RobotAI::Update(uint32 pmDiff)
{
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
            onlineDelay -= pmDiff;
            if (onlineDelay <= 0)
            {
                onlineDelay = 0;
                robotState = RobotState::RobotState_CheckAccount;
            }
            break;
        }
        else if (checkDelay > 0)
        {
            checkDelay -= pmDiff;
            if (checkDelay <= 0)
            {
                checkDelay = urand(TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS);
                bool levelPlayerOnline = false;
                std::unordered_map<uint32, WorldSession*> allSessionMap = sWorld->GetAllSessions();
                for (std::unordered_map<uint32, WorldSession*>::iterator it = allSessionMap.begin(); it != allSessionMap.end(); it++)
                {
                    if (!it->second->isRobot)
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

                // EJ debug
                if (targetLevel == 22)
                {
                    levelPlayerOnline = true;
                }

                if (levelPlayerOnline)
                {
                    onlineDelay = urand(5 * TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS);
                    break;
                }
            }
        }
        break;
    }
    case RobotState_CheckAccount:
    {
        allDelay -= pmDiff;
        if (allDelay <= 0)
        {
            allDelay = 0;
            accountID = sRobotManager->CheckRobotAccount(accountName);
            if (accountID > 0)
            {
                robotState = RobotState::RobotState_CheckCharacter;
            }
            else
            {
                robotState = RobotState::RobotState_CreateAccount;
            }
        }
        break;
    }
    case RobotState_CreateAccount:
    {
        if (sRobotManager->CreateRobotAccount(accountName))
        {
            robotState = RobotState::RobotState_CheckAccount;
            allDelay = 5 * TimeConstants::IN_MILLISECONDS;
        }
        else
        {
            robotState = RobotState::RobotState_None;
        }
        break;
    }
    case RobotState_CheckCharacter:
    {
        allDelay -= pmDiff;
        if (allDelay <= 0)
        {
            allDelay = 0;
            characterID = sRobotManager->CheckAccountCharacter(accountID);
            if (characterID > 0)
            {
                robotState = RobotState::RobotState_DoLogin;
                allDelay = 5 * TimeConstants::IN_MILLISECONDS;
            }
            else
            {
                robotState = RobotState::RobotState_CreateCharacter;
            }
        }
        break;
    }
    case RobotState_CreateCharacter:
    {
        if (sRobotManager->CreateRobotCharacter(accountID, targetClass, targetRace))
        {
            robotState = RobotState::RobotState_CheckCharacter;
            allDelay = 5 * TimeConstants::IN_MILLISECONDS;
        }
        else
        {
            robotState = RobotState::RobotState_None;
        }
        break;
    }
    case RobotState_CheckLogin:
    {
        sourcePlayer = sRobotManager->CheckLogin(accountID, characterID);
        if (sourcePlayer)
        {
            sourceSession = sourcePlayer->GetSession();
            InitializeCharacter();
            robotState = RobotState::RobotState_Online;
            checkDelay = urand(TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS);
            allDelay = 0;
        }
        else
        {
            robotState = RobotState::RobotState_DoLogin;
            allDelay = 10 * TimeConstants::MINUTE* TimeConstants::IN_MILLISECONDS;
        }
        break;
    }
    case RobotState_DoLogin:
    {
        allDelay -= pmDiff;
        if (allDelay <= 0)
        {
            allDelay = 0;
            sRobotManager->LoginRobot(accountID, characterID);
            robotState = RobotState::RobotState_CheckLogin;
            allDelay = 10 * TimeConstants::IN_MILLISECONDS;
        }
        break;
    }
    case RobotState_Online:
    {
        HandlePacket();
        if (sourcePlayer)
        {
            if (sourcePlayer->IsBeingTeleportedNear())
            {
                WorldPacket data(MSG_MOVE_TELEPORT_ACK, 10);
                data << sourcePlayer->GetGUID().WriteAsPacked();
                data << uint32(0) << uint32(0);
                sourcePlayer->GetSession()->HandleMoveTeleportAck(data);
                break;
            }
            else if (sourcePlayer->IsBeingTeleportedFar())
            {
                sourcePlayer->GetSession()->HandleMoveWorldportAck();
                break;
            }
            else
            {
                if (strategiesMap["solo_normal"])
                {
                    st_Solo_Normal->Update(pmDiff);
                    break;
                }
                if (strategiesMap["group_normal"])
                {
                    st_Group_Normal->Update(pmDiff);
                    break;
                }
            }
        }
        if (offlineDelay > 0)
        {
            offlineDelay -= pmDiff;
            if (offlineDelay <= 0)
            {
                offlineDelay = 0;
                robotState = RobotState::RobotState_DoLogoff;
                allDelay = 5 * TimeConstants::IN_MILLISECONDS;
            }
            break;
        }
        else if (checkDelay > 0)
        {
            checkDelay -= pmDiff;
            if (checkDelay <= 0)
            {
                checkDelay = urand(TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS);
                bool levelPlayerOnline = false;
                std::unordered_map<uint32, WorldSession*> allSessionMap = sWorld->GetAllSessions();
                for (std::unordered_map<uint32, WorldSession*>::iterator it = allSessionMap.begin(); it != allSessionMap.end(); it++)
                {
                    if (!it->second->isRobot)
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

                // EJ debug
                if (targetLevel == 22)
                {
                    levelPlayerOnline = true;
                }

                if (!levelPlayerOnline)
                {
                    offlineDelay = urand(5 * TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE*TimeConstants::IN_MILLISECONDS);
                    break;
                }
            }
        }
        break;
    }
    case RobotState_CheckLogoff:
    {
        allDelay -= pmDiff;
        if (allDelay <= 0)
        {
            allDelay = 0;
            if (sourcePlayer)
            {
                if (sourcePlayer->IsInWorld())
                {
                    robotState = RobotState::RobotState_DoLogoff;
                    allDelay = 10 * TimeConstants::MINUTE* TimeConstants::IN_MILLISECONDS;
                    break;
                }
            }
            robotState = RobotState::RobotState_OffLine;
        }
        break;
    }
    case RobotState_DoLogoff:
    {
        allDelay -= pmDiff;
        if (allDelay <= 0)
        {
            allDelay = 0;
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
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
    {
        Item* pItem = sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
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
        if (Bag * pBag = (Bag*)sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                Item* pItem = sourcePlayer->GetItemByPos(i, j);
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

bool RobotAI::UseItem(Item * pmItem, Unit * pmTarget)
{
    if (sourcePlayer->CanUseItem(pmItem) != EQUIP_ERR_OK)
    {
        return false;
    }

    if (sourcePlayer->IsNonMeleeSpellCast(true))
    {
        return false;
    }
    SpellCastTargets targets;
    targets.Update(pmTarget);
    sourcePlayer->CastItemUseSpell(pmItem, targets, 0, 0);

    std::ostringstream useRemarksStream;
    useRemarksStream << "Prepare to use item " << pmItem->GetTemplate()->Name1;

    sourcePlayer->Say(useRemarksStream.str(), Language::LANG_UNIVERSAL);
    return true;
}

bool RobotAI::EquipNewItem(uint32 pmEntry)
{
    uint16 eDest;
    InventoryResult tryEquipResult = sourcePlayer->CanEquipNewItem(NULL_SLOT, eDest, pmEntry, false);
    if (tryEquipResult == EQUIP_ERR_OK)
    {
        ItemPosCountVec sDest;
        InventoryResult storeResult = sourcePlayer->CanStoreNewItem(INVENTORY_SLOT_BAG_0, NULL_SLOT, sDest, pmEntry, 1);
        if (storeResult == EQUIP_ERR_OK)
        {
            Item* pItem = sourcePlayer->StoreNewItem(sDest, pmEntry, true, GenerateItemRandomPropertyId(pmEntry));
            if (pItem)
            {
                InventoryResult equipResult = sourcePlayer->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                if (equipResult == EQUIP_ERR_OK)
                {
                    sourcePlayer->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                    sourcePlayer->EquipItem(eDest, pItem, true);
                    return true;
                }
                else
                {
                    pItem->DestroyForPlayer(sourcePlayer);
                }
            }
        }
    }

    return false;
}

bool RobotAI::EquipNewItem(uint32 pmEntry, uint8 pmEquipSlot)
{
    uint16 eDest;
    InventoryResult tryEquipResult = sourcePlayer->CanEquipNewItem(NULL_SLOT, eDest, pmEntry, false);
    if (tryEquipResult == EQUIP_ERR_OK)
    {
        ItemPosCountVec sDest;
        InventoryResult storeResult = sourcePlayer->CanStoreNewItem(INVENTORY_SLOT_BAG_0, NULL_SLOT, sDest, pmEntry, 1);
        if (storeResult == EQUIP_ERR_OK)
        {
            Item* pItem = sourcePlayer->StoreNewItem(sDest, pmEntry, true, GenerateItemRandomPropertyId(pmEntry));
            if (pItem)
            {
                InventoryResult equipResult = sourcePlayer->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                if (equipResult == EQUIP_ERR_OK)
                {
                    sourcePlayer->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                    sourcePlayer->EquipItem(pmEquipSlot, pItem, true);
                    return true;
                }
                else
                {
                    pItem->DestroyForPlayer(sourcePlayer);
                }
            }
        }
    }

    return false;
}

bool RobotAI::UnequipAll()
{
    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
    {
        if (Item * pItem = sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            uint8 bagIndex = pItem->GetBagSlot();
            uint8 slot = pItem->GetSlot();
            uint8 dstBag = NULL_BAG;
            WorldPacket data(CMSG_AUTOSTORE_BAG_ITEM, 3);
            data << bagIndex << slot << dstBag;
            sourcePlayer->GetSession()->HandleAutoStoreBagItemOpcode(data);
        }
    }
    sourcePlayer->UpdateAllStats();
    return true;
}

bool RobotAI::EquipAll()
{
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        if (Item * pItem = sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (pItem)
            {
                uint16 eDest;
                InventoryResult equipResult = sourcePlayer->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                if (equipResult == EQUIP_ERR_OK)
                {
                    sourcePlayer->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                    sourcePlayer->EquipItem(eDest, pItem, true);
                }
            }
        }
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag * pBag = (Bag*)sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                if (Item * pItem = pBag->GetItemByPos(j))
                {
                    if (pItem)
                    {
                        uint16 eDest;
                        InventoryResult equipResult = sourcePlayer->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                        if (equipResult == EQUIP_ERR_OK)
                        {
                            sourcePlayer->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                            sourcePlayer->EquipItem(eDest, pItem, true);
                        }
                    }
                }
            }
        }
    }
    sourcePlayer->UpdateAllStats();

    return true;
}

bool RobotAI::EquipItem(std::string pmEquipName)
{
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        if (Item * pItem = sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (pItem)
            {
                if (pItem->GetTemplate()->Name1 == pmEquipName)
                {
                    uint16 eDest;
                    InventoryResult equipResult = sourcePlayer->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                    if (equipResult == EQUIP_ERR_OK)
                    {
                        sourcePlayer->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                        sourcePlayer->EquipItem(eDest, pItem, true);
                        sourcePlayer->UpdateAllStats();
                    }
                    return true;
                }
            }
        }
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag * pBag = (Bag*)sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                if (Item * pItem = pBag->GetItemByPos(j))
                {
                    if (pItem)
                    {
                        if (pItem->GetTemplate()->Name1 == pmEquipName)
                        {
                            uint16 eDest;
                            InventoryResult equipResult = sourcePlayer->CanEquipItem(NULL_SLOT, eDest, pItem, false);
                            if (equipResult == EQUIP_ERR_OK)
                            {
                                sourcePlayer->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                                sourcePlayer->EquipItem(eDest, pItem, true);
                                sourcePlayer->UpdateAllStats();
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
    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
    {
        if (Item * pItem = sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (pItem->GetTemplate()->Name1 == pmEquipName)
            {
                uint8 bagIndex = pItem->GetBagSlot();
                uint8 slot = pItem->GetSlot();
                uint8 dstBag = NULL_BAG;
                WorldPacket data(CMSG_AUTOSTORE_BAG_ITEM, 3);
                data << bagIndex << slot << dstBag;
                sourcePlayer->GetSession()->HandleAutoStoreBagItemOpcode(data);

                return true;
            }
        }
        sourcePlayer->UpdateAllStats();
    }

    return true;
}

void RobotAI::HandleChatCommand()
{
    if (sourceSession)
    {
        for (std::set<const RobotChatCommand*>::iterator rccIT = sourceSession->robotChatCommandSet.begin(); rccIT != sourceSession->robotChatCommandSet.end(); rccIT++)
        {
            const RobotChatCommand* destRCC = *rccIT;

            std::vector<std::string> commandVector = sRobotManager->SplitString(destRCC->chatCommandContent, " ", true);
            std::string commandName = commandVector.at(0);
            if (commandName == "role")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }

                std::ostringstream replyStream;
                if (commandVector.size() > 1)
                {
                    std::string newRole = commandVector.at(1);
                    if (newRole == "dps")
                    {
                        sourcePlayer->groupRole = 0;
                    }
                    else if (newRole == "tank")
                    {
                        sourcePlayer->groupRole = 1;
                    }
                    else if (newRole == "healer")
                    {
                        sourcePlayer->groupRole = 2;
                    }
                }

                replyStream << "My group role is ";
                switch (sourcePlayer->groupRole)
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
                WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, destRCC->sender);
            }
            else if (commandName == "follow")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (st_Group_Normal->Follow())
                {
                    st_Group_Normal->staying = false;
                    WhisperTo("Following", Language::LANG_UNIVERSAL, destRCC->sender);
                }
                else
                {
                    WhisperTo("I will not follow you", Language::LANG_UNIVERSAL, destRCC->sender);
                }
            }
            else if (commandName == "stay")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (st_Group_Normal->Stay())
                {
                    st_Group_Normal->staying = true;
                    WhisperTo("Staying", Language::LANG_UNIVERSAL, destRCC->sender);
                }
                else
                {
                    WhisperTo("I will not stay", Language::LANG_UNIVERSAL, destRCC->sender);
                }
            }
            else if (commandName == "attack")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                Unit* senderTarget = destRCC->sender->GetSelectedUnit();
                if (st_Group_Normal->Attack(senderTarget))
                {
                    st_Group_Normal->instruction = Group_Instruction::Group_Instruction_Battle;
                    st_Group_Normal->staying = false;
                    sourcePlayer->SetSelection(senderTarget->GetGUID());
                    WhisperTo("Attack your target", Language::LANG_UNIVERSAL, destRCC->sender);
                }
                else
                {
                    WhisperTo("Can not attack your target", Language::LANG_UNIVERSAL, destRCC->sender);
                }
            }
            else if (commandName == "rest")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (st_Group_Normal->Rest(true))
                {
                    st_Group_Normal->staying = false;
                    WhisperTo("Resting", Language::LANG_UNIVERSAL, destRCC->sender);
                }
                else
                {
                    WhisperTo("Do not rest", Language::LANG_UNIVERSAL, destRCC->sender);
                }
            }
            else if (commandName == "eat")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (st_Group_Normal->Eat(true))
                {
                    st_Group_Normal->staying = false;
                    WhisperTo("Eating", Language::LANG_UNIVERSAL, destRCC->sender);
                }
                else
                {
                    WhisperTo("Do not eat", Language::LANG_UNIVERSAL, destRCC->sender);
                }
            }
            else if (commandName == "drink")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (st_Group_Normal->Drink(true))
                {
                    st_Group_Normal->staying = false;
                    WhisperTo("Drinking", Language::LANG_UNIVERSAL, destRCC->sender);
                }
                else
                {
                    WhisperTo("Do not drink", Language::LANG_UNIVERSAL, destRCC->sender);
                }
            }
            else if (commandName == "who")
            {
                WhisperTo(sRobotManager->characterTalentTabNameMap[sourcePlayer->GetClass()][characterTalentTab], Language::LANG_UNIVERSAL, destRCC->sender);
            }
            else if (commandName == "assemble")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (st_Group_Normal->assembleDelay > 0)
                {
                    WhisperTo("I am coming", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (sourcePlayer->IsAlive())
                {
                    if (sourcePlayer->GetDistance(destRCC->sender) < 40)
                    {
                        st_Group_Normal->assembleDelay = 5 * TimeConstants::IN_MILLISECONDS;
                        WhisperTo("We are close, I will be ready in 5 seconds", Language::LANG_UNIVERSAL, destRCC->sender);
                    }
                    else
                    {
                        st_Group_Normal->assembleDelay = 30 * TimeConstants::IN_MILLISECONDS;
                        WhisperTo("I will come to you in 30 seconds", Language::LANG_UNIVERSAL, destRCC->sender);
                    }
                }
                else
                {
                    st_Group_Normal->assembleDelay = 60 * TimeConstants::IN_MILLISECONDS;
                    WhisperTo("I will revive and come to you in 60 seconds", Language::LANG_UNIVERSAL, destRCC->sender);
                }
            }
            else if (commandName == "tank")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (sourcePlayer->groupRole == 1)
                {
                    Unit* senderTarget = destRCC->sender->GetSelectedUnit();
                    if (st_Group_Normal->Tank(senderTarget))
                    {
                        st_Group_Normal->staying = false;
                        st_Group_Normal->instruction = Group_Instruction::Group_Instruction_Battle;
                        sourcePlayer->SetSelection(senderTarget->GetGUID());
                        WhisperTo("Tank your target", Language::LANG_UNIVERSAL, destRCC->sender);
                    }
                    else
                    {
                        WhisperTo("Can not tank your target", Language::LANG_UNIVERSAL, destRCC->sender);
                    }
                }
            }
            else if (commandName == "prepare")
            {
                Prepare();
                sourcePlayer->Say("I am prepared", Language::LANG_UNIVERSAL);
            }
            else if (commandName == "growl")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (commandVector.size() > 1)
                {
                    if (sourcePlayer->GetClass() != Classes::CLASS_HUNTER)
                    {
                        WhisperTo("I am not hunter", Language::LANG_UNIVERSAL, destRCC->sender);
                        return;
                    }
                    std::string growlState = commandVector.at(1);
                    if (growlState == "on")
                    {
                        Pet* checkPet = sourcePlayer->GetPet();
                        if (!checkPet)
                        {
                            WhisperTo("I do not have an active pet", Language::LANG_UNIVERSAL, destRCC->sender);
                            return;
                        }
                        std::unordered_map<uint32, PetSpell> petSpellMap = checkPet->m_spells;
                        for (std::unordered_map<uint32, PetSpell>::iterator it = petSpellMap.begin(); it != petSpellMap.end(); it++)
                        {
                            if (it->second.active == ACT_DISABLED)
                            {
                                const SpellInfo* pST = sSpellMgr->GetSpellInfo(it->first);
                                if (pST)
                                {
                                    std::string checkNameStr = std::string(pST->SpellName[0]);
                                    if (checkNameStr == "Growl")
                                    {
                                        continue;
                                    }
                                    checkPet->ToggleAutocast(pST, true);
                                }
                            }
                        }
                        WhisperTo("Switched", Language::LANG_UNIVERSAL, destRCC->sender);
                        return;
                    }
                    else if (growlState == "off")
                    {
                        Pet* checkPet = sourcePlayer->GetPet();
                        if (!checkPet)
                        {
                            WhisperTo("I do not have an active pet", Language::LANG_UNIVERSAL, destRCC->sender);
                            return;
                        }
                        std::unordered_map<uint32, PetSpell> petSpellMap = checkPet->m_spells;
                        for (std::unordered_map<uint32, PetSpell>::iterator it = petSpellMap.begin(); it != petSpellMap.end(); it++)
                        {
                            if (it->second.active == ACT_DISABLED)
                            {
                                const SpellInfo* pST = sSpellMgr->GetSpellInfo(it->first);
                                if (pST)
                                {
                                    std::string checkNameStr = std::string(pST->SpellName[0]);
                                    if (checkNameStr == "Growl")
                                    {
                                        continue;
                                    }
                                    checkPet->ToggleAutocast(pST, false);
                                }
                            }
                        }
                        WhisperTo("Switched", Language::LANG_UNIVERSAL, destRCC->sender);
                        return;
                    }
                    else
                    {
                        WhisperTo("Unknown command", Language::LANG_UNIVERSAL, destRCC->sender);
                        return;
                    }
                }
                else
                {
                    WhisperTo("Unknown command", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
            }
            else if (commandName == "strip")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                UnequipAll();
                WhisperTo("Stripped", Language::LANG_UNIVERSAL, destRCC->sender);
            }
            else if (commandName == "unequip")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
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
                    std::string unequipTarget = sRobotManager->TrimString(targetStream.str());
                    if (unequipTarget == "all")
                    {
                        UnequipAll();
                    }
                    else
                    {
                        UnequipItem(unequipTarget);
                    }
                }
                WhisperTo("Unequiped", Language::LANG_UNIVERSAL, destRCC->sender);
            }
            else if (commandName == "equip")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
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
                    std::string equipTarget = sRobotManager->TrimString(targetStream.str());
                    if (equipTarget == "all")
                    {
                        EquipAll();
                    }
                    else
                    {
                        EquipItem(equipTarget);
                    }
                }
                WhisperTo("Equiped", Language::LANG_UNIVERSAL, destRCC->sender);
            }
            else if (commandName == "cast")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                Unit* senderTarget = destRCC->sender->GetSelectedUnit();
                if (!senderTarget)
                {
                    WhisperTo("You do not have a target", Language::LANG_UNIVERSAL, destRCC->sender);
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
                    WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, destRCC->sender);
                }
            }
            else if (commandName == "cancel")
            {
                if (!masterPlayer)
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (destRCC->sender->GetGUID() != masterPlayer->GetGUID())
                {
                    WhisperTo("You are not my master", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                if (!sourcePlayer->IsAlive())
                {
                    WhisperTo("I am dead", Language::LANG_UNIVERSAL, destRCC->sender);
                    return;
                }
                Unit* senderTarget = destRCC->sender->GetSelectedUnit();
                if (!senderTarget)
                {
                    WhisperTo("You do not have a target", Language::LANG_UNIVERSAL, destRCC->sender);
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
                    WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, destRCC->sender);
                }
            }
        }
        sourceSession->robotChatCommandSet.clear();
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
    if (sourcePlayer->GetSpellHistory()->HasCooldown(pmSpellID))
    {
        return false;
    }
    return true;
}

bool RobotAI::CancelAura(std::string pmSpellName)
{
    std::set<uint32> spellIDSet = sRobotManager->spellNameEntryMap[pmSpellName];
    for (std::set<uint32>::iterator it = spellIDSet.begin(); it != spellIDSet.end(); it++)
    {
        if (sourcePlayer->HasAura((*it)))
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
    WorldPacket data(CMSG_CANCEL_AURA, 4);
    data << pmSpellID;
    sourcePlayer->GetSession()->HandleCancelAuraOpcode(data);
}

void RobotAI::ClearShapeshift()
{
    uint32 spellID = 0;
    switch (sourcePlayer->GetShapeshiftForm())
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

void RobotAI::DoAttack(Unit * pmTarget, bool pmMelee)
{

}

void RobotAI::Logout()
{
    if (sourcePlayer)
    {
        if (sourcePlayer->IsInWorld())
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Log out robot %s", sourcePlayer->GetName());
            std::ostringstream msgStream;
            msgStream << sourcePlayer->GetName() << " logged out";
            sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, msgStream.str().c_str());
            sourceSession->LogoutPlayer(true);
        }
    }
}
