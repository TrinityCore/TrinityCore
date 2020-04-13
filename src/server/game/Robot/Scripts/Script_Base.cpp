#include "Script_Base.h"
#include "RobotConfig.h"
#include "RobotManager.h"
#include "MapManager.h"
#include "Pet.h"
#include "PetAI.h"
#include "Bag.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"
#include "MotionMaster.h"
#include "ChaseMovementGenerator.h"
#include "FollowMovementGenerator.h"
#include "SpellHistory.h"
#include "GridNotifiers.h"
#include "SpellPackets.h"

Script_Base::Script_Base(Player* pmMe)
{
    me = pmMe;
}

bool Script_Base::DPS(Unit* pmTarget, bool pmChase, bool pmAOE)
{
    return false;
}

bool Script_Base::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Base::Heal(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Base::Attack(Unit* pmTarget)
{
    return false;
}

bool Script_Base::Buff(Unit* pmTarget, bool pmCure)
{
    return false;
}

void Script_Base::InitializeValues()
{
    if (!me)
    {
        return;
    }
    spellLevelMap.clear();
    bool typeChecked = false;
    characterType = 0;
    characterTalentTab = me->GetMaxTalentCountTab();
    switch (me->GetClass())
    {
    case Classes::CLASS_WARRIOR:
    {
        if (characterTalentTab == 2)
        {
            characterType = 1;
        }
        break;
    }
    case Classes::CLASS_SHAMAN:
    {
        if (characterTalentTab == 2)
        {
            characterType = 2;
        }
        break;
    }
    case Classes::CLASS_PALADIN:
    {
        if (characterTalentTab == 0)
        {
            characterType = 2;
        }
        else if (characterTalentTab == 1)
        {
            characterType = 1;
        }
        break;
    }
    case Classes::CLASS_PRIEST:
    {
        if (characterTalentTab == 0)
        {
            characterType = 2;
        }
        else if (characterTalentTab == 1)
        {
            characterType = 2;
        }
        break;
    }
    case Classes::CLASS_DRUID:
    {
        if (characterTalentTab == 1)
        {
            characterType = 1;
        }
        else  if (characterTalentTab == 2)
        {
            characterType = 2;
        }
        break;
    }
    default:
    {
        break;
    }
    }
    for (PlayerSpellMap::iterator it = me->GetSpellMap().begin(); it != me->GetSpellMap().end(); it++)
    {
        const SpellInfo* pST = sSpellMgr->GetSpellInfo(it->first);
        if (pST)
        {
            std::string checkNameStr = std::string(pST->SpellName[0]);
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
}

void Script_Base::InitializeCharacter(uint32 pmTargetLevel)
{
    if (!me)
    {
        return;
    }
    bool newCharacter = false;
    if (me->GetLevel() != pmTargetLevel)
    {
        newCharacter = true;
    }

    if (newCharacter)
    {
        me->GiveLevel(pmTargetLevel);
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
            specialty = 2;
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
            specialty = 2;
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
        for (std::unordered_set<uint32>::iterator questIT = sRobotManager->spellRewardClassQuestIDSet.begin(); questIT != sRobotManager->spellRewardClassQuestIDSet.end(); questIT++)
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

    InitializeValues();

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
            me->LearnDefaultSkill(45, me->GetLevel() * 5); // bow 
            me->LearnDefaultSkill(46, me->GetLevel() * 5); // gun 
            me->LearnDefaultSkill(226, me->GetLevel() * 5); // crossbow 

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
            me->LearnDefaultSkill(160, me->GetLevel() * 5); // mace 2 
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
            if (characterType == 0)
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
        InitialEquipment(weaponType, dual, armorType, hasRange, rangeType, hasShield);
        me->SaveToDB();
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Player %s equip info initialized", me->GetName());
    }

    switch (me->GetClass())
    {
    case Classes::CLASS_WARLOCK:
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
        break;
    }
    case Classes::CLASS_PALADIN:
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
            // Glyph of Exorcism
            ApplyGlyph(55118, 0);
            // Glyph of Hammer of Wrath 
            ApplyGlyph(55112, 3);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    default:
    {
        break;
    }
    }

    me->UpdateSkillsForLevel();
    me->UpdateWeaponsSkillsToMaxSkillsForLevel();
    me->SetPvP(true);

    me->SaveToDB();

    std::ostringstream msgStream;
    msgStream << me->GetName() << " initialized";
    sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, msgStream.str().c_str());
}

void Script_Base::InitialEquipment(uint32 pmWeaponType, bool pmDual, uint32 pmArmorType, bool pmHasRange, uint32 pmRangeType, bool pmHasShield)
{
    if (!me)
    {
        return;
    }

    int levelRange = me->GetLevel() / 10;
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

bool Script_Base::EquipNewItem(uint32 pmEntry)
{
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
            //CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
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

bool Script_Base::EquipNewItem(uint32 pmEntry, uint8 pmEquipSlot)
{
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

bool Script_Base::ApplyGlyph(uint32 pmGlyphSpellID, uint32 pmSlot)
{
    if (!me)
    {
        return false;
    }

    uint32 g = me->GetGlyph(pmSlot);
    if (g == 0)
    {
        if (const SpellInfo* pSI = sSpellMgr->GetSpellInfo(pmGlyphSpellID))
        {
            if (uint32 glyph = pSI->Effects[0].MiscValue)
            {
                if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyph))
                {
                    if (GlyphSlotEntry const* gs = sGlyphSlotStore.LookupEntry(me->GetGlyphSlot(pmSlot)))
                    {
                        if (gp->TypeFlags != gs->TypeFlags)
                        {
                            return false;
                        }
                    }

                    // remove old glyph
                    if (uint32 oldglyph = me->GetGlyph(pmSlot))
                    {
                        if (GlyphPropertiesEntry const* old_gp = sGlyphPropertiesStore.LookupEntry(oldglyph))
                        {
                            me->RemoveAurasDueToSpell(old_gp->SpellId);
                            me->SetGlyph(pmSlot, 0);
                        }
                    }

                    me->CastSpell(me, gp->SpellId, true);
                    me->SetGlyph(pmSlot, glyph);
                    me->SendTalentsInfoData(false);

                    return true;
                }
            }
        }
    }

    return false;
}

void Script_Base::RandomTeleport()
{
    if (!me)
    {
        return;
    }
    if (me->IsBeingTeleported())
    {
        return;
    }
    if (!me->IsAlive())
    {
        return;
    }
    if (sRobotManager->onlinePlayerIDMap.size() > 0)
    {
        uint32 playerIndex = urand(0, sRobotManager->onlinePlayerIDMap.size() - 1);
        uint32 cid = sRobotManager->onlinePlayerIDMap[playerIndex];
        ObjectGuid og = ObjectGuid(HighGuid::Player, cid);
        if (Player* targetP = ObjectAccessor::FindConnectedPlayer(og))
        {
            if (targetP->IsBeingTeleported())
            {
                return;
            }
            if (Map* checkMap = targetP->GetMap())
            {
                if (!checkMap->Instanceable())
                {
                    float destX = 0.0f;
                    float destY = 0.0f;
                    float destZ = 0.0f;
                    float distance = frand(sRobotConfig->TeleportMinRange, sRobotConfig->TeleportMaxRange);
                    float angle = frand(0, 2 * M_PI);
                    targetP->GetNearPoint(targetP, destX, destY, destZ, distance, angle);

                    me->StopMoving();
                    me->GetMotionMaster()->Clear();

                    me->TeleportTo(targetP->GetMapId(), destX, destY, destZ, 0.0f);
                    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Teleport robot %s (level %d)", me->GetName(), me->GetLevel());
                }
            }
        }
    }
}

void Script_Base::Prepare()
{
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
    me->Say("Prepared", Language::LANG_UNIVERSAL);
}

Item* Script_Base::GetItemInInventory(uint32 pmEntry)
{
    if (!me)
    {
        return NULL;
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

bool Script_Base::UseItem(Item* pmItem, Unit* pmTarget)
{
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

    if (const ItemTemplate* proto = pmItem->GetTemplate())
    {
        // item spells cast at use
        for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
        {
            _Spell const& spellData = proto->Spells[i];
            if (spellData.SpellId <= 0)
            {
                continue;
            }
            if (spellData.SpellTrigger != ITEM_SPELLTRIGGER_ON_USE)
            {
                continue;
            }
            if (me->GetSpellHistory()->HasCooldown(spellData.SpellId))
            {
                continue;
            }
            SpellCastTargets targets;
            targets.Update(pmTarget);
            me->CastItemUseSpell(pmItem, targets, 0, 0);

            std::ostringstream useRemarksStream;
            useRemarksStream << "Prepare to use item " << pmItem->GetTemplate()->Name1;

            me->Say(useRemarksStream.str(), Language::LANG_UNIVERSAL);
            return true;
        }        
    }

    return false;
}

bool Script_Base::Follow(Unit* pmTarget, float pmDistance)
{
    if (!me)
    {
        return false;
    }
    if (me->HasAuraType(SPELL_AURA_MOD_PACIFY))
    {
        return false;
    }
    if (me->HasUnitState(UnitState::UNIT_STATE_NOT_MOVE))
    {
        return false;
    }
    if (me->HasUnitState(UnitState::UNIT_STATE_ROAMING_MOVE))
    {
        return false;
    }
    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
    {
        return false;
    }
    if (me->IsNonMeleeSpellCast(true, false, true))
    {
        return false;
    }
    if (me->GetDistance(pmTarget) > 200)
    {
        return false;
    }
    if (me->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
    {
        me->SetStandState(UNIT_STAND_STATE_STAND);
    }
    if (me->IsWalking())
    {
        me->SetWalk(false);
    }

    bool following = false;
    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == MovementGeneratorType::CHASE_MOTION_TYPE)
    {
        ChaseMovementGenerator* mg = (ChaseMovementGenerator*)me->GetMotionMaster()->GetCurrentMovementGenerator();
        if (mg)
        {
            if (mg->GetTarget())
            {
                if (mg->GetTarget()->GetGUID() == pmTarget->GetGUID())
                {
                    following = true;
                }
            }
        }
    }
    if (!following)
    {
        me->StopMoving();
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveChase(pmTarget, ChaseRange(0.0f, pmDistance));
    }

    return true;
}

bool Script_Base::Chase(Unit* pmTarget, float pmMaxDistance, float pmMinDistance)
{
    if (!me)
    {
        return false;
    }
    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
    {
        return false;
    }
    if (me->IsNonMeleeSpellCast(false, false, true))
    {
        return false;
    }
    if (me->GetDistance(pmTarget) > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == MovementGeneratorType::CHASE_MOTION_TYPE)
    {
        if (ChaseMovementGenerator* mg = (ChaseMovementGenerator*)me->GetMotionMaster()->GetCurrentMovementGenerator())
        {
            if (Unit* mgTarget = mg->GetTarget())
            {
                if (mgTarget->GetGUID() == pmTarget->GetGUID())
                {
                    return true;
                }
            }
        }
    }
    if (me->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
    {
        me->SetStandState(UNIT_STAND_STATE_STAND);
    }
    if (me->IsWalking())
    {
        me->SetWalk(false);
    }
    me->GetMotionMaster()->MoveChase(pmTarget, ChaseRange(pmMinDistance, pmMaxDistance));
    return true;
}

uint32 Script_Base::FindSpellID(std::string pmSpellName)
{
    if (spellIDMap.find(pmSpellName) != spellIDMap.end())
    {
        return spellIDMap[pmSpellName];
    }

    return 0;
}

bool Script_Base::SpellValid(uint32 pmSpellID)
{
    if (pmSpellID == 0)
    {
        return false;
    }
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

bool Script_Base::CastSpell(Unit* pmTarget, std::string pmSpellName, float pmDistance, bool pmCheckAura, bool pmOnlyMyAura)
{
    if (!pmTarget)
    {
        return false;
    }
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
    const SpellInfo* pST = sSpellMgr->GetSpellInfo(spellID);
    if (pmTarget->GetGUID() != me->GetGUID())
    {
        if (me->GetDistance(pmTarget) > pmDistance)
        {
            return false;
        }
    }
    if (!me->IsWithinLOSInMap(pmTarget))
    {
        return false;
    }
    if (!pST)
    {
        return false;
    }
    if (pmTarget->IsImmunedToSpell(pST, me))
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
    if (!me->isInFront(pmTarget))
    {
        me->SetFacingToObject(pmTarget);
    }
    if (me->GetTarget() != pmTarget->GetGUID())
    {
        me->SetSelection(pmTarget->GetGUID());
    }
    SpellCastResult scr = me->CastSpell(pmTarget, spellID, TriggerCastFlags::TRIGGERED_NONE);
    if (scr == SpellCastResult::SPELL_CAST_OK)
    {
        return true;
    }
    else
    {
        //std::ostringstream scrStream;
        //scrStream << enum_to_string(scr);
        //me->Say(scrStream.str(), Language::LANG_UNIVERSAL);
    }

    return false;
}

bool Script_Base::HasAura(Unit* pmTarget, std::string pmSpellName, bool pmOnlyMyAura)
{
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

void Script_Base::ClearShapeshift()
{
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

bool Script_Base::CancelAura(std::string pmSpellName)
{
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

void Script_Base::CancelAura(uint32 pmSpellID)
{
    if (pmSpellID == 0)
    {
        return;
    }
    if (!me)
    {
        return;
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(pmSpellID);
    if (!spellInfo)
        return;

    // not allow remove spells with attr SPELL_ATTR0_CANT_CANCEL
    if (spellInfo->HasAttribute(SPELL_ATTR0_CANT_CANCEL))
        return;

    // channeled spell case (it currently cast then)
    if (spellInfo->IsChanneled())
    {
        if (Spell* curSpell = me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            if (curSpell->m_spellInfo->Id == pmSpellID)
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
        return;
    }

    // non channeled case:
    // don't allow remove non positive spells
    // don't allow cancelling passive auras (some of them are visible)
    if (!spellInfo->IsPositive() || spellInfo->IsPassive())
        return;

    // maybe should only remove one buff when there are multiple?
    me->RemoveOwnedAura(pmSpellID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);

    // If spell being removed is a resource tracker, see if player was tracking both (herbs / minerals) and remove the other
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TRACK_BOTH_RESOURCES) && spellInfo->HasAura(SPELL_AURA_TRACK_RESOURCES))
    {
        Unit::AuraEffectList const& auraEffects = me->GetAuraEffectsByType(SPELL_AURA_TRACK_RESOURCES);
        if (!auraEffects.empty())
        {
            // Build list of spell IDs to cancel. Trying to cancel the aura while iterating
            //  over AuraEffectList caused "incompatible iterator" errors on second pass
            std::list<uint32> spellIDs;

            for (Unit::AuraEffectList::const_iterator auraEffect = auraEffects.begin(); auraEffect != auraEffects.end(); ++auraEffect)
                spellIDs.push_back((*auraEffect)->GetId());

            // Remove all auras related to resource tracking (only Herbs and Minerals in 3.3.5a)
            for (std::list<uint32>::iterator it = spellIDs.begin(); it != spellIDs.end(); ++it)
                me->RemoveOwnedAura(*it, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
        }
    }
}

void Script_Base::WhisperTo(std::string pmContent, Language pmLanguage, Player* pmTarget)
{
    if (!me)
    {
        return;
    }
    me->Whisper(pmContent, pmLanguage, pmTarget);
}

bool Script_Base::Rest()
{
    bool result = false;

    if (!me)
    {
        return false;
    }
    if (me->IsInCombat())
    {
        return false;
    }
    uint32 foodEntry = 0;
    if (me->GetLevel() >= 75)
    {
        foodEntry = 35950;
    }
    else if (me->GetLevel() >= 65)
    {
        foodEntry = 33449;
    }
    else if (me->GetLevel() >= 55)
    {
        foodEntry = 21023;
    }
    else if (me->GetLevel() >= 45)
    {
        foodEntry = 8932;
    }
    else if (me->GetLevel() >= 35)
    {
        foodEntry = 3927;
    }
    else if (me->GetLevel() >= 25)
    {
        foodEntry = 1707;
    }
    else if (me->GetLevel() >= 15)
    {
        foodEntry = 422;
    }
    else
    {
        return false;
    }
    uint32 drinkEntry = 0;
    if (me->GetLevel() >= 75)
    {
        drinkEntry = 33445;
    }
    else if (me->GetLevel() >= 65)
    {
        drinkEntry = 35954;
    }
    else if (me->GetLevel() >= 55)
    {
        drinkEntry = 18300;
    }
    else if (me->GetLevel() >= 45)
    {
        drinkEntry = 8766;
    }
    else if (me->GetLevel() >= 45)
    {
        drinkEntry = 8766;
    }
    else if (me->GetLevel() >= 35)
    {
        drinkEntry = 1645;
    }
    else if (me->GetLevel() >= 25)
    {
        drinkEntry = 1708;
    }
    else if (me->GetLevel() >= 15)
    {
        drinkEntry = 1205;
    }

    if (!me->HasItemCount(foodEntry, 1))
    {
        me->StoreNewItemInBestSlots(foodEntry, 20);
    }
    if (!me->HasItemCount(drinkEntry, 1))
    {
        me->StoreNewItemInBestSlots(drinkEntry, 20);
    }

    me->CombatStop(true);
    me->GetMotionMaster()->Clear();
    me->StopMoving();
    me->SetSelection(ObjectGuid());

    Item* pFood = GetItemInInventory(foodEntry);
    if (pFood && !pFood->IsInTrade())
    {
        if (UseItem(pFood, me))
        {
            result = true;
        }
    }
    Item* pDrink = GetItemInInventory(drinkEntry);
    if (pDrink && !pDrink->IsInTrade())
    {
        if (UseItem(pDrink, me))
        {
            result = true;
        }
    }

    return result;
}

void Script_Base::PetAttack(Unit* pmTarget)
{
    if (me)
    {
        if (Pet* myPet = me->GetPet())
        {
            if (CharmInfo* pci = myPet->GetCharmInfo())
            {
                if (!pci->IsCommandAttack())
                {
                    pci->SetIsCommandAttack(true);
                    CreatureAI* AI = myPet->ToCreature()->AI();
                    if (PetAI* petAI = dynamic_cast<PetAI*>(AI))
                    {
                        petAI->_AttackStart(pmTarget);
                    }
                    else
                    {
                        AI->AttackStart(pmTarget);
                    }
                }
            }
        }
    }
}

void Script_Base::PetStop()
{
    if (me)
    {
        if (Pet* myPet = me->GetPet())
        {
            myPet->AttackStop();
            if (CharmInfo* pci = myPet->GetCharmInfo())
            {
                if (pci->IsCommandAttack())
                {
                    pci->SetIsCommandAttack(false);
                }
                if (!pci->IsCommandFollow())
                {
                    pci->SetIsCommandFollow(true);
                }
            }
        }
    }
}

bool Script_Base::UseManaPotion()
{
    bool result = false;

    if (!me)
    {
        return false;
    }
    if (me->IsInCombat())
    {
        return false;
    }
    uint32 itemEntry = 0;
    if (me->GetLevel() >= 70)
    {
        itemEntry = 33448;
    }
    else if (me->GetLevel() >= 65)
    {
        itemEntry = 40067;
    }
    else if (me->GetLevel() >= 55)
    {
        itemEntry = 22832;
    }
    else if (me->GetLevel() >= 49)
    {
        itemEntry = 13444;
    }
    else if (me->GetLevel() >= 41)
    {
        itemEntry = 13443;
    }
    else if (me->GetLevel() >= 31)
    {
        itemEntry = 6149;
    }
    else if (me->GetLevel() >= 22)
    {
        itemEntry = 3827;
    }
    else if (me->GetLevel() >= 14)
    {
        itemEntry = 3385;
    }
    if (!me->HasItemCount(itemEntry, 1))
    {
        me->StoreNewItemInBestSlots(itemEntry, 20);
    }
    Item* pItem = GetItemInInventory(itemEntry);
    if (pItem && !pItem->IsInTrade())
    {
        if (UseItem(pItem, me))
        {
            result = true;
        }
    }

    return result;
}
