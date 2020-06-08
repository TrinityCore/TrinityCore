#include "Script_Base.h"
#include "RobotConfig.h"
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
#include "Group.h"

Script_Base::Script_Base(Player* pmMe)
{
    me = pmMe;
    spellIDMap.clear();
    spellLevelMap.clear();
    characterTalentTab = 0;
    characterType = 0;
    petting = true;

    float chaseDistanceMin = MIN_DISTANCE_GAP;
    float chaseDistanceMax = MELEE_MIN_DISTANCE;
}

void Script_Base::Reset()
{

}

std::set<Unit*> Script_Base::GetAttackersInRange(float pmRangeLimit)
{
    std::set<Unit*> attackers;
    attackers.clear();
    if (me)
    {
        if (Group* myGroup = me->GetGroup())
        {
            std::unordered_set<ObjectGuid> CheckedAttackerOGSet;
            CheckedAttackerOGSet.clear();
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (member->IsAlive())
                    {
                        for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                        {
                            if (Unit* eachAttacker = *attackerIT)
                            {
                                if (CheckedAttackerOGSet.find(eachAttacker->GetGUID()) == CheckedAttackerOGSet.end())
                                {
                                    if (me->GetDistance(eachAttacker) < pmRangeLimit)
                                    {
                                        CheckedAttackerOGSet.insert(eachAttacker->GetGUID());
                                        attackers.insert(eachAttacker);
                                    }
                                }
                            }
                        }
                        if (Pet* memberPet = member->GetPet())
                        {
                            if (memberPet->IsAlive())
                            {
                                for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
                                {
                                    if (Unit* eachAttacker = *attackerIT)
                                    {
                                        if (CheckedAttackerOGSet.find(eachAttacker->GetGUID()) == CheckedAttackerOGSet.end())
                                        {
                                            if (me->GetDistance(eachAttacker) < pmRangeLimit)
                                            {
                                                CheckedAttackerOGSet.insert(eachAttacker->GetGUID());
                                                attackers.insert(eachAttacker);
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
        else
        {
            attackers = me->getAttackers();
        }
    }

    return attackers;
}

void Script_Base::Update(uint32 pmDiff)
{
    return;
}

bool Script_Base::DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank, bool pmInterruptCasting)
{
    return false;
}

bool Script_Base::Tank(Unit* pmTarget, bool pmChase, bool pmSingle)
{
    return false;
}

bool Script_Base::SubTank(Unit* pmTarget, bool pmChase)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    if (me->GetDistance(pmTarget) > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    if (pmChase)
    {
        if (!Chase(pmTarget))
        {
            return false;
        }
    }
    else
    {
        if (!me->isInFront(pmTarget, M_PI / 16))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    if (me->GetHealthPct() < 20.0f)
    {
        UseHealingPotion();
    }
    me->Attack(pmTarget, true);
    return true;
}

bool Script_Base::Taunt(Unit* pmTarget)
{
    return false;
}

bool Script_Base::InterruptCasting(Unit* pmTarget)
{
    return false;
}

bool Script_Base::Heal(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Base::SubHeal(Unit* pmTarget)
{
    return false;
}

bool Script_Base::GroupHeal(float pmMaxHealthPercent)
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

bool Script_Base::InitializeCharacter(uint32 pmTargetLevel)
{
    if (!me)
    {
        return false;
    }
    me->ClearInCombat();
    bool isNew = false;
    if (me->GetLevel() != pmTargetLevel)
    {
        isNew = true;
        me->GiveLevel(pmTargetLevel);
        me->LearnDefaultSkills();
        switch (me->GetClass())
        {
        case Classes::CLASS_WARRIOR:
        {
            break;
        }
        case Classes::CLASS_HUNTER:
        {
            me->LearnDefaultSkill(45, me->GetLevel() * 5); // bow 
            me->LearnDefaultSkill(46, me->GetLevel() * 5); // gun 
            me->LearnDefaultSkill(226, me->GetLevel() * 5); // crossbow 
            break;
        }
        case Classes::CLASS_SHAMAN:
        {
            break;
        }
        case Classes::CLASS_PALADIN:
        {
            me->LearnDefaultSkill(160, me->GetLevel() * 5); // mace 2 
            break;
        }
        case Classes::CLASS_WARLOCK:
        {
            break;
        }
        case Classes::CLASS_PRIEST:
        {
            break;
        }
        case Classes::CLASS_ROGUE:
        {
            break;
        }
        case Classes::CLASS_MAGE:
        {
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
        for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; i++)
        {
            if (Item* pItem = me->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            {
                me->DestroyItem(INVENTORY_SLOT_BAG_0, i, true);
            }
        }
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
                if (const TalentEntry* eachTE = *it)
                {
                    uint8 maxRank = 4;
                    if (eachTE->RankID[4] > 0)
                    {
                        maxRank = 4;
                    }
                    else if (eachTE->RankID[3] > 0)
                    {
                        maxRank = 3;
                    }
                    else if (eachTE->RankID[2] > 0)
                    {
                        maxRank = 2;
                    }
                    else if (eachTE->RankID[1] > 0)
                    {
                        maxRank = 1;
                    }
                    else
                    {
                        maxRank = 0;
                    }
                    me->LearnTalent(eachTE->TalentID, maxRank);
                }
            }
        }        
    }

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

    me->UpdateSkillsForLevel();
    me->UpdateWeaponsSkillsToMaxSkillsForLevel();

    IdentifyCharacter();

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
        switch (me->rai->GetActiveStrategy()->sb->characterTalentTab)
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
            uint32 g0 = me->GetGlyph(0);
            if (g0 == 0)
            {
                ApplyGlyph(55118, 0);
            }
            // Glyph of Hammer of Wrath
            uint32 g3 = me->GetGlyph(3);
            if (g3 == 0)
            {
                ApplyGlyph(55112, 3);
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
    default:
    {
        break;
    }
    }

    if (sRobotConfig->ResetEquipments)
    {
        for (uint8 slot = INVENTORY_SLOT_ITEM_START; slot < INVENTORY_SLOT_ITEM_END; ++slot)
        {
            if (Item* inventoryItem = me->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
            {
                me->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);
            }
        }
        for (uint32 checkEquipSlot = EquipmentSlots::EQUIPMENT_SLOT_HEAD; checkEquipSlot < EquipmentSlots::EQUIPMENT_SLOT_TABARD; checkEquipSlot++)
        {
            if (Item* currentEquip = me->GetItemByPos(INVENTORY_SLOT_BAG_0, checkEquipSlot))
            {
                me->DestroyItem(INVENTORY_SLOT_BAG_0, checkEquipSlot, true);
            }
        }
    }
    for (uint32 checkEquipSlot = EquipmentSlots::EQUIPMENT_SLOT_HEAD; checkEquipSlot < EquipmentSlots::EQUIPMENT_SLOT_TABARD; checkEquipSlot++)
    {
        if (checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_HEAD || checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_SHOULDERS || checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_CHEST || checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_WAIST || checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_LEGS || checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_FEET || checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_WRISTS || checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_HANDS)
        {
            if (Item* currentEquip = me->GetItemByPos(INVENTORY_SLOT_BAG_0, checkEquipSlot))
            {
                if (const ItemTemplate* checkIT = currentEquip->GetTemplate())
                {
                    if (checkIT->Quality > ItemQualities::ITEM_QUALITY_NORMAL)
                    {
                        continue;
                    }
                    else
                    {
                        me->DestroyItem(INVENTORY_SLOT_BAG_0, checkEquipSlot, true);
                    }
                }
            }
            std::unordered_set<uint32> usableItemClass;
            std::unordered_set<uint32> usableItemSubClass;
            usableItemClass.insert(ItemClass::ITEM_CLASS_ARMOR);
            usableItemSubClass.insert(GetUsableArmorSubClass());
            TryEquip(usableItemClass, usableItemSubClass, checkEquipSlot);
        }
        else if (checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_MAINHAND)
        {
            if (Item* currentEquip = me->GetItemByPos(checkEquipSlot))
            {
                if (const ItemTemplate* checkIT = currentEquip->GetTemplate())
                {
                    if (checkIT->Quality > ItemQualities::ITEM_QUALITY_NORMAL)
                    {
                        continue;
                    }
                    else
                    {
                        me->DestroyItem(INVENTORY_SLOT_BAG_0, checkEquipSlot, true);
                    }
                }
            }
            int weaponSubClass_mh = -1;
            int weaponSubClass_oh = -1;
            int weaponSubClass_r = -1;
            switch (me->GetClass())
            {
            case Classes::CLASS_WARRIOR:
            {
                weaponSubClass_mh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_SWORD;
                weaponSubClass_oh = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_SHIELD;
                break;
            }
            case Classes::CLASS_PALADIN:
            {
                weaponSubClass_mh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_MACE2;
                break;
            }
            case Classes::CLASS_HUNTER:
            {
                weaponSubClass_mh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_AXE2;
                uint32 rType = urand(0, 2);
                if (rType == 0)
                {
                    weaponSubClass_r = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_BOW;
                }
                else if (rType == 1)
                {
                    weaponSubClass_r = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_CROSSBOW;
                }
                else
                {
                    weaponSubClass_r = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_GUN;
                }
                break;
            }
            case Classes::CLASS_ROGUE:
            {
                weaponSubClass_mh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_DAGGER;
                weaponSubClass_oh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_DAGGER;
                break;
            }
            case Classes::CLASS_PRIEST:
            {
                weaponSubClass_mh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_STAFF;
                break;
            }
            case Classes::CLASS_DEATH_KNIGHT:
            {
                weaponSubClass_mh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_SWORD2;
                break;
            }
            case Classes::CLASS_SHAMAN:
            {
                weaponSubClass_mh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_MACE;
                weaponSubClass_oh = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_SHIELD;
                break;
            }
            case Classes::CLASS_MAGE:
            {
                weaponSubClass_mh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_STAFF;
                break;
            }
            case Classes::CLASS_WARLOCK:
            {
                weaponSubClass_mh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_STAFF;
                break;
            }
            case Classes::CLASS_DRUID:
            {
                weaponSubClass_mh = ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_STAFF;
                break;
            }
            default:
            {
                continue;
            }
            }
            if (weaponSubClass_mh >= 0)
            {
                std::unordered_set<uint32> usableItemClass;
                std::unordered_set<uint32> usableItemSubClass;
                usableItemClass.insert(ItemClass::ITEM_CLASS_WEAPON);
                usableItemSubClass.insert(weaponSubClass_mh);
                TryEquip(usableItemClass, usableItemSubClass, checkEquipSlot);
            }
            if (weaponSubClass_oh >= 0)
            {
                std::unordered_set<uint32> usableItemClass;
                std::unordered_set<uint32> usableItemSubClass;
                usableItemClass.insert(ItemClass::ITEM_CLASS_WEAPON);
                usableItemClass.insert(ItemClass::ITEM_CLASS_ARMOR);
                usableItemSubClass.insert(weaponSubClass_oh);
                TryEquip(usableItemClass, usableItemSubClass, EquipmentSlots::EQUIPMENT_SLOT_OFFHAND);
            }
            if (weaponSubClass_r >= 0)
            {
                std::unordered_set<uint32> usableItemClass;
                std::unordered_set<uint32> usableItemSubClass;
                usableItemClass.insert(ItemClass::ITEM_CLASS_WEAPON);
                usableItemSubClass.insert(weaponSubClass_r);
                TryEquip(usableItemClass, usableItemSubClass, EquipmentSlots::EQUIPMENT_SLOT_RANGED);
            }
        }
        else if (checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_BACK)
        {
            if (Item* currentEquip = me->GetItemByPos(checkEquipSlot))
            {
                if (const ItemTemplate* checkIT = currentEquip->GetTemplate())
                {
                    if (checkIT->Quality > ItemQualities::ITEM_QUALITY_NORMAL)
                    {
                        continue;
                    }
                    else
                    {
                        me->DestroyItem(INVENTORY_SLOT_BAG_0, checkEquipSlot, true);
                    }
                }
            }
            std::unordered_set<uint32> usableItemClass;
            std::unordered_set<uint32> usableItemSubClass;
            usableItemClass.insert(ItemClass::ITEM_CLASS_ARMOR);
            usableItemSubClass.insert(ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_CLOTH);
            TryEquip(usableItemClass, usableItemSubClass, checkEquipSlot);
        }
        else if (checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_FINGER1)
        {
            if (Item* currentEquip = me->GetItemByPos(checkEquipSlot))
            {
                if (const ItemTemplate* checkIT = currentEquip->GetTemplate())
                {
                    if (checkIT->Quality > ItemQualities::ITEM_QUALITY_NORMAL)
                    {
                        continue;
                    }
                    else
                    {
                        me->DestroyItem(INVENTORY_SLOT_BAG_0, checkEquipSlot, true);
                    }
                }
            }
            std::unordered_set<uint32> usableItemClass;
            std::unordered_set<uint32> usableItemSubClass;
            usableItemClass.insert(ItemClass::ITEM_CLASS_ARMOR);
            usableItemSubClass.insert(ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_MISC);
            TryEquip(usableItemClass, usableItemSubClass, checkEquipSlot);
        }
        else if (checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_FINGER2)
        {
            if (Item* currentEquip = me->GetItemByPos(checkEquipSlot))
            {
                if (const ItemTemplate* checkIT = currentEquip->GetTemplate())
                {
                    if (checkIT->Quality > ItemQualities::ITEM_QUALITY_NORMAL)
                    {
                        continue;
                    }
                    else
                    {
                        me->DestroyItem(INVENTORY_SLOT_BAG_0, checkEquipSlot, true);
                    }
                }
            }
            std::unordered_set<uint32> usableItemClass;
            std::unordered_set<uint32> usableItemSubClass;
            usableItemClass.insert(ItemClass::ITEM_CLASS_ARMOR);
            usableItemSubClass.insert(ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_MISC);
            TryEquip(usableItemClass, usableItemSubClass, checkEquipSlot);
        }
        else if (checkEquipSlot == EquipmentSlots::EQUIPMENT_SLOT_NECK)
        {
            if (Item* currentEquip = me->GetItemByPos(checkEquipSlot))
            {
                if (const ItemTemplate* checkIT = currentEquip->GetTemplate())
                {
                    if (checkIT->Quality > ItemQualities::ITEM_QUALITY_NORMAL)
                    {
                        continue;
                    }
                    else
                    {
                        me->DestroyItem(INVENTORY_SLOT_BAG_0, checkEquipSlot, true);
                    }
                }
            }
            std::unordered_set<uint32> usableItemClass;
            std::unordered_set<uint32> usableItemSubClass;
            usableItemClass.insert(ItemClass::ITEM_CLASS_ARMOR);
            usableItemSubClass.insert(ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_MISC);
            TryEquip(usableItemClass, usableItemSubClass, checkEquipSlot);
        }
    }

    std::ostringstream msgStream;
    msgStream << me->GetName() << " initialized";
    sWorld->SendServerMessage(ServerMessageType::SERVER_MSG_STRING, msgStream.str().c_str());

    return isNew;
}

void Script_Base::IdentifyCharacter()
{
    if (!me)
    {
        return;
    }

    spellLevelMap.clear();
    characterType = 0;
    characterTalentTab = me->GetMaxTalentCountTab();

    bool typeChecked = false;
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

uint32 Script_Base::GetUsableArmorSubClass()
{
    if (!me)
    {
        return false;
    }
    uint32 resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_CLOTH;
    switch (me->GetClass())
    {
    case Classes::CLASS_WARRIOR:
    {
        if (me->GetLevel() < 40)
        {
            // use mail armor
            resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_MAIL;
        }
        else
        {
            // use plate armor
            resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_PLATE;
        }
        break;
    }
    case Classes::CLASS_PALADIN:
    {
        if (me->GetLevel() < 40)
        {
            // use mail armor
            resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_MAIL;
        }
        else
        {
            // use plate armor
            resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_PLATE;
        }
        break;
    }
    case Classes::CLASS_HUNTER:
    {
        if (me->GetLevel() < 40)
        {
            resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_LEATHER;
        }
        else
        {
            resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_MAIL;
        }
        break;
    }
    case Classes::CLASS_ROGUE:
    {
        resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_LEATHER;
        break;
    }
    case Classes::CLASS_PRIEST:
    {
        resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_CLOTH;
        break;
    }
    case Classes::CLASS_DEATH_KNIGHT:
    {
        resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_PLATE;
        break;
    }
    case Classes::CLASS_SHAMAN:
    {
        if (me->GetLevel() < 40)
        {
            resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_LEATHER;
        }
        else
        {
            resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_MAIL;
        }
        break;
    }
    case Classes::CLASS_MAGE:
    {
        resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_CLOTH;
        break;
    }
    case Classes::CLASS_WARLOCK:
    {
        resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_CLOTH;
        break;
    }
    case Classes::CLASS_DRUID:
    {
        resultArmorSubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_LEATHER;
        break;
    }
    default:
    {
        break;
    }
    }

    return resultArmorSubClass;
}

bool Script_Base::EquipNewItem(uint32 pmItemEntry, uint8 pmEquipSlot)
{
    if (!me)
    {
        return false;
    }
    uint16 eDest;
    InventoryResult tryEquipResult = me->CanEquipNewItem(NULL_SLOT, eDest, pmItemEntry, false);
    if (tryEquipResult == EQUIP_ERR_OK)
    {
        ItemPosCountVec sDest;
        InventoryResult storeResult = me->CanStoreNewItem(INVENTORY_SLOT_BAG_0, NULL_SLOT, sDest, pmItemEntry, 1);
        if (storeResult == EQUIP_ERR_OK)
        {
            Item* pItem = me->StoreNewItem(sDest, pmItemEntry, true, GenerateItemRandomPropertyId(pmItemEntry));
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

void Script_Base::TryEquip(std::unordered_set<uint32> pmClassSet, std::unordered_set<uint32> pmSubClassSet, uint32 pmTargetSlot)
{
    if (!me)
    {
        return;
    }
    std::unordered_map<uint32, uint32> validEquipSet;
    ItemTemplateContainer const& its = sObjectMgr->GetItemTemplateStore();
    for (auto const& itemTemplatePair : its)
    {
        const ItemTemplate* proto = &itemTemplatePair.second;
        if (!proto)
        {
            continue;
        }
        if (pmClassSet.find(proto->Class) == pmClassSet.end())
        {
            continue;
        }
        if (pmSubClassSet.find(proto->SubClass) == pmSubClassSet.end())
        {
            continue;
        }
        if (proto->Quality < ItemQualities::ITEM_QUALITY_UNCOMMON)
        {
            continue;
        }
        if (proto->RequiredLevel < 10)
        {
            continue;
        }
        //if (proto->RandomSuffix > 0)
        //{
        //    continue;
        //}
        std::unordered_set<uint32> usableSlotSet = sRobotManager->GetUsableEquipSlot(proto);
        if (usableSlotSet.find(pmTargetSlot) != usableSlotSet.end())
        {
            uint32 checkMinRequiredLevel = me->GetLevel();
            if (checkMinRequiredLevel > 15)
            {
                checkMinRequiredLevel = checkMinRequiredLevel - 10;
            }
            else
            {
                checkMinRequiredLevel = 5;
            }
            if (proto->RequiredLevel <= me->GetLevel() && proto->RequiredLevel > checkMinRequiredLevel)
            {
                validEquipSet[validEquipSet.size()] = proto->ItemId;
            }
        }
    }
    if (validEquipSet.size() > 0)
    {
        int tryTimes = 5;
        while (tryTimes > 0)
        {
            uint32 equipEntry = urand(0, validEquipSet.size() - 1);
            equipEntry = validEquipSet[equipEntry];
            if (EquipNewItem(equipEntry, pmTargetSlot))
            {
                break;
            }
            tryTimes--;
        }
    }
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
        me->ResurrectPlayer(1.0f);
        me->SpawnCorpseBones();
    }
    me->ClearInCombat();
    me->StopMoving();
    me->GetMotionMaster()->Clear();
    if (RobotStrategy_Solo* rs = (RobotStrategy_Solo*)me->rai->strategyMap[Strategy_Index::Strategy_Index_Solo])
    {
        rs->Reset();
    }
    bool validLocation = false;
    int destMapID = 0;
    float destX = 0.0f;
    float destY = 0.0f;
    float destZ = 0.0f;
    float distance = frand(sRobotConfig->TeleportMinRange, sRobotConfig->TeleportMaxRange);
    float angle = frand(0, 2 * M_PI);

    if (me->rai->robotType == RobotType::RobotType_Raid)
    {
        // raid robot will only wonder in main city
        uint32 spawnID = 0;
        if (me->GetRace() == Races::RACE_BLOODELF || me->GetRace() == Races::RACE_ORC || me->GetRace() == Races::RACE_TAUREN || me->GetRace() == Races::RACE_TROLL || me->GetRace() == Races::RACE_UNDEAD_PLAYER)
        {
            spawnID = urand(0, sRobotManager->orgrimmar_gruntSpawnIDMap.size() - 1);
            spawnID = sRobotManager->orgrimmar_gruntSpawnIDMap[spawnID];
        }
        else
        {
            spawnID = urand(0, sRobotManager->ironforge_guardSpawnIDMap.size() - 1);
            spawnID = sRobotManager->ironforge_guardSpawnIDMap[spawnID];
        }
        if (spawnID > 0)
        {
            for (auto const& pair : sObjectMgr->GetAllCreatureData())
            {
                if (pair.second.spawnId == spawnID)
                {
                    me->TeleportTo(pair.second.mapId, pair.second.spawnPoint.m_positionX, pair.second.spawnPoint.m_positionY, pair.second.spawnPoint.m_positionZ, 0.0f);
                    break;
                }
            }
        }
        return;
    }

    if (sRobotManager->onlinePlayerIDMap.size() > 0)
    {
        uint32 playerIndex = urand(0, sRobotManager->onlinePlayerIDMap.size() - 1);
        uint32 cid = sRobotManager->onlinePlayerIDMap[playerIndex];
        ObjectGuid og = ObjectGuid(HighGuid::Player, cid);
        if (Player* targetP = ObjectAccessor::FindConnectedPlayer(og))
        {
            if (!targetP->IsBeingTeleported())
            {
                if (Map* checkMap = targetP->GetMap())
                {
                    if (!checkMap->Instanceable())
                    {
                        targetP->GetNearPoint(targetP, destX, destY, destZ, distance, angle);
                        destMapID = targetP->GetMapId();
                        validLocation = true;
                    }
                }
            }
        }
    }

    if (!validLocation)
    {
        if (Corpse* myC = me->GetCorpse())
        {
            myC->GetNearPoint(myC, destX, destY, destZ, distance, angle);
            destMapID = myC->GetMapId();
            validLocation = true;
        }
    }

    if (!validLocation)
    {
        me->GetNearPoint(me, destX, destY, destZ, distance, angle);
        destMapID = me->GetMapId();
        validLocation = true;
    }

    if (validLocation)
    {
        me->TeleportTo(destMapID, destX, destY, destZ, 0.0f);
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Teleport robot %s (level %d)", me->GetName(), me->GetLevel());
    }
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
        SpellCastTargets targets;
        targets.Update(pmTarget);
        me->CastItemUseSpell(pmItem, targets, 0, 0);
        return true;
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
    float currentDistance = me->GetDistance(pmTarget);
    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == MovementGeneratorType::CHASE_MOTION_TYPE)
    {
        if (ChaseMovementGenerator* mg = (ChaseMovementGenerator*)me->GetMotionMaster()->GetCurrentMovementGenerator())
        {
            if (Unit* mgTarget = mg->GetTarget())
            {
                if (mgTarget->GetGUID() == pmTarget->GetGUID())
                {
                    if (currentDistance > ATTACK_RANGE_LIMIT)
                    {
                        me->AttackStop();
                        me->StopMoving();
                        me->GetMotionMaster()->Clear();
                        ClearTarget();
                        return false;
                    }
                    if (me->GetTarget() != pmTarget->GetGUID())
                    {
                        ChooseTarget(pmTarget);
                    }
                    return true;
                }
            }
        }
    }
    if (currentDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    me->AttackStop();
    me->StopMoving();
    me->GetMotionMaster()->Clear();
    ClearTarget();
    if (me->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
    {
        me->SetStandState(UNIT_STAND_STATE_STAND);
    }
    if (me->IsWalking())
    {
        me->SetWalk(false);
    }
    ChooseTarget(pmTarget);
    me->GetMotionMaster()->MoveChase(pmTarget, ChaseRange(0.0f, pmDistance));

    return true;
}

bool Script_Base::Chase(Unit* pmTarget, float pmMaxDistance, float pmMinDistance)
{
    chaseDistanceMax = pmMaxDistance;
    chaseDistanceMin = pmMinDistance;
    //chaseDistanceMax = pmTarget->GetCombatReach() + chaseDistanceMax;
    //chaseDistanceMin = pmTarget->GetCombatReach() + chaseDistanceMin;
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
    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == MovementGeneratorType::POINT_MOTION_TYPE)
    {
        return true;
    }
    float currentDistance = me->GetExactDist(pmTarget);
    if (chaseDistanceMin > INTERACTION_DISTANCE)
    {
        if (currentDistance < chaseDistanceMin)
        {
            if (pmTarget->GetTarget() != me->GetGUID())
            {
                me->AttackStop();
                me->StopMoving();
                me->GetMotionMaster()->Clear();
                ClearTarget();

                float destX = 0.0f;
                float destY = 0.0f;
                float destZ = 0.0f;
                pmTarget->GetNearPoint(pmTarget, destX, destY, destZ, chaseDistanceMin + MELEE_MIN_DISTANCE, pmTarget->GetAbsoluteAngle(me));
                me->GetMotionMaster()->MovePoint(0, destX, destY, destZ, true, me->GetAbsoluteAngle(pmTarget));
                return true;
            }
        }
    }
    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == MovementGeneratorType::CHASE_MOTION_TYPE)
    {
        if (ChaseMovementGenerator* mg = (ChaseMovementGenerator*)me->GetMotionMaster()->GetCurrentMovementGenerator())
        {
            if (Unit* mgTarget = mg->GetTarget())
            {
                if (mgTarget->GetGUID() == pmTarget->GetGUID())
                {
                    if (currentDistance > ATTACK_RANGE_LIMIT)
                    {
                        me->AttackStop();
                        me->StopMoving();
                        me->GetMotionMaster()->Clear();
                        ClearTarget();
                        return false;
                    }
                    //else if(!sRobotManager->UnitTargetReachable(me,pmTarget))
                    //{
                    //    me->ClearInCombat();
                    //    me->AttackStop();
                    //    me->StopMoving();
                    //    me->GetMotionMaster()->Clear();
                    //    me->SetSelection(ObjectGuid());
                    //    return false;
                    //}
                    if (me->GetTarget() != pmTarget->GetGUID())
                    {
                        ChooseTarget(pmTarget);
                    }
                    return true;
                }
            }
        }
    }
    if (currentDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    //else if (!sRobotManager->UnitTargetReachable(me, pmTarget))
    //{
    //    return false;
    //}
    me->AttackStop();
    me->StopMoving();
    me->GetMotionMaster()->Clear();
    ClearTarget();
    if (me->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
    {
        me->SetStandState(UNIT_STAND_STATE_STAND);
    }
    if (me->IsWalking())
    {
        me->SetWalk(false);
    }
    ChooseTarget(pmTarget);
    me->GetMotionMaster()->MoveChase(pmTarget, ChaseRange(chaseDistanceMin, chaseDistanceMax));
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

bool Script_Base::CastSpell(Unit* pmTarget, std::string pmSpellName, float pmDistance, bool pmCheckAura, bool pmOnlyMyAura, bool pmClearShapeShift)
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
        float actualDistance = me->GetDistance(pmTarget);
        if (actualDistance > pmDistance)
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
    if (me->GetTarget() != pmTarget->GetGUID())
    {
        ChooseTarget(pmTarget);
    }
    if (!me->isInFront(pmTarget, M_PI / 16))
    {
        me->SetFacingToObject(pmTarget);
    }
    if (pmClearShapeShift)
    {
        ClearShapeshift();
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
        uint32 spellID = *it;
        if (pmOnlyMyAura)
        {
            if (target->HasAura(spellID, me->GetGUID()))
            {
                return true;
            }
        }
        else
        {
            if (target->HasAura(spellID))
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
        foodEntry = 27857;
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
    ClearTarget();

    Item* pFood = GetItemInInventory(foodEntry);
    if (pFood && !pFood->IsInTrade())
    {
        if (UseItem(pFood, me))
        {
            //std::ostringstream useRemarksStream;
            //useRemarksStream << "Use item " << pFood->GetTemplate()->Name1;
            //me->Say(useRemarksStream.str(), Language::LANG_UNIVERSAL);
            result = true;
        }
    }
    Item* pDrink = GetItemInInventory(drinkEntry);
    if (pDrink && !pDrink->IsInTrade())
    {
        if (UseItem(pDrink, me))
        {
            //std::ostringstream useRemarksStream;
            //useRemarksStream << "Use item " << pDrink->GetTemplate()->Name1;
            //me->Say(useRemarksStream.str(), Language::LANG_UNIVERSAL);
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
    // EJ debug
    return;
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

bool Script_Base::UseHealingPotion()
{
    bool result = false;

    if (!me)
    {
        return false;
    }
    if (!me->IsInCombat())
    {
        return false;
    }
    uint32 itemEntry = 0;
    if (me->GetLevel() >= 70)
    {
        itemEntry = 33447;
    }
    else if (me->GetLevel() >= 55)
    {
        itemEntry = 22829;
    }
    else if (me->GetLevel() >= 45)
    {
        itemEntry = 13446;
    }
    else if (me->GetLevel() >= 35)
    {
        itemEntry = 3928;
    }
    else if (me->GetLevel() >= 21)
    {
        itemEntry = 1710;
    }
    else if (me->GetLevel() >= 12)
    {
        itemEntry = 929;
    }
    else
    {
        itemEntry = 118;
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

bool Script_Base::UseManaPotion()
{
    bool result = false;

    if (!me)
    {
        return false;
    }
    if (!me->IsInCombat())
    {
        return false;
    }
    uint32 itemEntry = 0;
    if (me->GetLevel() >= 70)
    {
        itemEntry = 33448;
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
    else
    {
        itemEntry = 2455;
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

void Script_Base::ChooseTarget(Unit* pmTarget)
{
    if (pmTarget)
    {
        if (me)
        {
            me->SetSelection(pmTarget->GetGUID());
            me->SetTarget(pmTarget->GetGUID());
        }
    }
}

void Script_Base::ClearTarget()
{
    if (me)
    {
        me->SetSelection(ObjectGuid::Empty);
        me->SetTarget(ObjectGuid::Empty);
    }
}
