#include "project.h"
#include "project_db2.h"
#include "project_util_placeholder.h"
#include "Log.h"

typedef std::vector<std::string> DB2StoreProblemList;
uint32 DB2FilesCount = 0;

namespace PROJECT {
namespace DataStores {

DB2Storage<Structs::AdventureJournal>                AdventureJournal("AdventureJournal.db2", LoadInfo::AdventureJournal::Instance());
DB2Storage<Structs::AdventureMapPOI>                 AdventureMapPOI("AdventureMapPOI.db2", LoadInfo::AdventureMapPOI::Instance());
DB2Storage<Structs::AzeriteItemEntry>                sAzeriteItemStore("AzeriteItem.db2", LoadInfo::AzeriteItemLoadInfo::Instance());
DB2Storage<Structs::AzeriteEmpoweredItemEntry>       sAzeriteEmpoweredItemStore("AzeriteEmpoweredItem.db2", LoadInfo::AzeriteEmpoweredItemLoadInfo::Instance());
DB2Storage<Structs::AzeriteTierUnlockEntry>          sAzeriteTierUnlockStore("AzeriteTierUnlock.db2", LoadInfo::AzeriteTierUnlockLoadInfo::Instance());
DB2Storage<Structs::AzeritePowerEntry>               sAzeritePowerStore("AzeritePower.db2", LoadInfo::AzeritePowerLoadInfo::Instance());
DB2Storage<Structs::AzeritePowerSetMemberEntry>      sAzeritePowerSetMember("AzeritePowerSetMember.db2", LoadInfo::AzeritePowerSetMemberLoadInfo::Instance());
DB2Storage<Structs::BattlePetAbility>                BattlePetAbility("BattlePetAbility.db2", LoadInfo::BattlePetAbility::Instance());
DB2Storage<Structs::BattlePetAbilityState>           BattlePetAbilityState("BattlePetAbilityState.db2", LoadInfo::BattlePetAbilityState::Instance());
DB2Storage<Structs::BattlePetAbilityEffect>          BattlePetAbilityEffect("BattlePetAbilityEffect.db2", LoadInfo::BattlePetAbilityEffect::Instance());
DB2Storage<Structs::BattlePetAbilityTurn>            BattlePetAbilityTurn("BattlePetAbilityTurn.db2", LoadInfo::BattlePetAbilityTurn::Instance());
DB2Storage<Structs::BattlePetSpeciesXAbility>        BattlePetSpeciesXAbility("BattlePetSpeciesXAbility.db2", LoadInfo::BattlePetSpeciesXAbility::Instance());
DB2Storage<Structs::BattlePetEffectProperties>       BattlePetEffectProperties("BattlePetEffectProperties.db2", LoadInfo::BattlePetEffectProperties::Instance());
DB2Storage<Structs::CharShipment>                    CharShipment("CharShipment.db2", LoadInfo::CharShipment::Instance());
DB2Storage<Structs::CharShipmentContainer>           CharShipmentContainer("CharShipmentContainer.db2", LoadInfo::CharShipmentContainer::Instance());
DB2Storage<Structs::GarrAbilityEffect>               GarrAbilityEffect("GarrAbilityEffect.db2", LoadInfo::GarrAbilityEffect::Instance());
DB2Storage<Structs::GarrClassSpecPlayerCond>         GarrClassSpecPlayerCond("GarrClassSpecPlayerCond.db2", LoadInfo::GarrClassSpecPlayerCond::Instance());
DB2Storage<Structs::GarrEncounterXMechanic>          GarrEncounterXMechanic("GarrEncounterXMechanic.db2", LoadInfo::GarrEncounterXMechanic::Instance());
DB2Storage<Structs::GarrFollowerLevelXP>             GarrFollowerLevelXP("GarrFollowerLevelXP.db2", LoadInfo::GarrFollowerLevelXP::Instance());
DB2Storage<Structs::GarrFollowerType>                GarrFollowerType("GarrFollowerType.db2", LoadInfo::GarrFollowerType::Instance());
DB2Storage<Structs::GarrFollowerXAbility>            GarrFollowerXAbility("GarrFollowerXAbility.db2", LoadInfo::GarrFollowerXAbility::Instance());
DB2Storage<Structs::GarrFollSupportSpell>            GarrFollSupportSpell("GarrFollSupportSpell.db2", LoadInfo::GarrFollSupportSpell::Instance());
DB2Storage<Structs::GarrMechanic>                    GarrMechanic("GarrMechanic.db2", LoadInfo::GarrMechanic::Instance());
DB2Storage<Structs::GarrMechanicType>                GarrMechanicType("GarrMechanicType.db2", LoadInfo::GarrMechanicType::Instance());
DB2Storage<Structs::GarrMission>                     GarrMission("GarrMission.db2", LoadInfo::GarrMission::Instance());
DB2Storage<Structs::GarrMissionXEncounter>           GarrMissionXEncounter("GarrMissionXEncounter.db2", LoadInfo::GarrMissionXEncounter::Instance());
DB2Storage<Structs::GarrTalent>                      GarrTalent("GarrTalent.db2", LoadInfo::GarrTalent::Instance());
DB2Storage<Structs::GarrTalentTree>                  GarrTalentTree("GarrTalentTree.db2", LoadInfo::GarrTalentTree::Instance());
DB2Storage<Structs::GarrType>                        GarrType("GarrType.db2", LoadInfo::GarrType::Instance());
DB2Storage<Structs::GroupFinderActivityEntry>        sGroupFinderActivityStore("GroupFinderActivity.db2", LoadInfo::GroupFinderActivity::Instance());
DB2Storage<Structs::GroupFinderCategoryEntry>        sGroupFinderCategoryStore("GroupFinderCategory.db2", LoadInfo::GroupFinderCategory::Instance());
DB2Storage<Structs::ItemNameDescription>             ItemNameDescription("ItemNameDescription.db2", LoadInfo::ItemNameDescription::Instance());
DB2Storage<Structs::SpellKeyboundOverride>           SpellKeyboundOverride("SpellKeyboundOverride.db2", LoadInfo::SpellKeyboundOverride::Instance());
DB2Storage<Structs::MapChallengeMode>                MapChallengeMode("MapChallengeMode.db2", LoadInfo::MapChallengeMode::Instance());
DB2Storage<Structs::QuestPOIBlob>                    QuestPOIBlob("QuestPOIBlob.db2", LoadInfo::QuestPOIBlob::Instance());
DB2Storage<Structs::QuestPOIPoint>                   QuestPOIPoint("QuestPOIPoint.db2", LoadInfo::QuestPOIPoint::Instance());
DB2Storage<Structs::QuestV2CliTaskEntry>             sQuestV2CliTaskStore("QuestV2CliTask.db2", LoadInfo::QuestV2CliTask::Instance());
DB2Storage<Structs::ResearchBranch>                  ResearchBranch("ResearchBranch.db2", LoadInfo::ResearchBranch::Instance());
DB2Storage<Structs::ResearchSite>                    ResearchSite("ResearchSite.db2", LoadInfo::ResearchSite::Instance());
DB2Storage<Structs::ResearchProject>                 ResearchProject("ResearchProject.db2", LoadInfo::ResearchProject::Instance());
DB2Storage<Structs::SceneScriptPackageMember>        SceneScriptPackageMember("SceneScriptPackageMember.db2", LoadInfo::SceneScriptPackageMember::Instance());
DB2Storage<Structs::SpecSetMemberEntry>              sSpecSetMemberStore("SpecSetMember.db2", LoadInfo::SpecSetMemberLoadInfo::Instance());
DB2Storage<Structs::SpellReagentsCurrency>           SpellReagentsCurrency("SpellReagentsCurrency.db2", LoadInfo::SpellReagentsCurrency::Instance());
DB2Storage<Structs::UiCamera>                        UiCamera("UiCamera.db2", LoadInfo::UiCamera::Instance());
DB2Storage<Structs::VignetteEntry>                   VignetteStore("Vignette.db2", LoadInfo::Vignette::Instance());
DB2Storage<Structs::WorldStateUI>                    WorldStateUI("WorldStateUI.db2", LoadInfo::WorldStateUI::Instance());

template<class T, template<class> class DB2>
inline void LoadDB2(uint32& availableDb2Locales, std::vector<std::string>& errlist, DB2Manager::StorageMap& stores, DB2StorageBase* storage, std::string const& db2Path, uint32 defaultLocale, DB2<T> const& /*hint*/)
{
    // validate structure
    DB2LoadInfo const* loadInfo = storage->GetLoadInfo();
    {
        std::string clientMetaString, ourMetaString;
        for (std::size_t i = 0; i < loadInfo->Meta->FieldCount; ++i)
            for (std::size_t j = 0; j < loadInfo->Meta->Fields[i].ArraySize; ++j)
                clientMetaString += loadInfo->Meta->Fields[i].Type;

        for (std::size_t i = loadInfo->Meta->HasIndexFieldInData() ? 0 : 1; i < loadInfo->FieldCount; ++i)
            ourMetaString += loadInfo->Fields[i].Type;

        ASSERT(clientMetaString == ourMetaString, "C++ structure fields %s do not match generated types from the client %s", ourMetaString.c_str(), clientMetaString.c_str());

        // compatibility format and C++ structure sizes
        ASSERT(loadInfo->Meta->GetRecordSize() == sizeof(T),
            "Size of '%s' set by format string (%u) not equal size of C++ structure (" SZFMTD ").",
            storage->GetFileName().c_str(), loadInfo->Meta->GetRecordSize(), sizeof(T));
    }

    ++DB2FilesCount;

    if (storage->Load(db2Path + localeNames[defaultLocale] + '/', defaultLocale))
    {
        storage->LoadFromDB();
        // LoadFromDB() always loads strings into enUS locale, other locales are expected to have data in corresponding _locale tables
        // so we need to make additional call to load that data in case said locale is set as default by worldserver.conf (and we do not want to load all this data from .db2 file again)
        if (defaultLocale != LOCALE_enUS)
            storage->LoadStringsFromDB(defaultLocale);

        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (defaultLocale == i || i == LOCALE_none)
                continue;

            if (availableDb2Locales & (1 << i))
                if (!storage->LoadStringsFrom((db2Path + localeNames[i] + '/'), i))
                    availableDb2Locales &= ~(1 << i);             // mark as not available for speedup next checks

            storage->LoadStringsFromDB(i);
        }
    }
    else
    {
        // sort problematic db2 to (1) non compatible and (2) nonexistent
        if (FILE* f = fopen((db2Path + localeNames[defaultLocale] + '/' + storage->GetFileName()).c_str(), "rb"))
        {
            std::ostringstream stream;
            stream << storage->GetFileName() << " exists, and has " << storage->GetFieldCount() << " field(s) (expected " << loadInfo->Meta->FieldCount
                << "). Extracted file might be from wrong client version.";
            std::string buf = stream.str();
            errlist.push_back(buf);
            fclose(f);
        }
        else
            errlist.push_back(storage->GetFileName());
    }

    stores[storage->GetTableHash()] = storage;
}

void LoadDB2(LocaleConstant locale)
{
    uint32 oldMSTime = getMSTime();
    std::string db2Path = sWorld->m_dataPath + "dbc/";

    DB2StoreProblemList bad_db2_files;
    uint32 availableDb2Locales = 0xFF;

    #define LOAD_DB2(store) LoadDB2(availableDb2Locales, bad_db2_files, sDB2Manager._stores, &store, db2Path, locale, store)

    LOAD_DB2(sAzeriteItemStore);
    LOAD_DB2(sAzeriteEmpoweredItemStore);
    LOAD_DB2(sAzeriteTierUnlockStore);
    LOAD_DB2(sAzeritePowerSetMember);
    LOAD_DB2(sAzeritePowerStore);
    LOAD_DB2(sSpecSetMemberStore);
    //LOAD_DB2(AdventureJournal); wait for bfa
    //LOAD_DB2(AdventureMapPOI); wait for bfa
    //LOAD_DB2(ResearchSite); wait for bfa
    //LOAD_DB2(ResearchProject); wait for bfa
    //LOAD_DB2(ResearchBranch); wait for bfa
    //LOAD_DB2(QuestPOIPoint); wait for bfa
    //LOAD_DB2(QuestPOIBlob); wait for bfa
    //LOAD_DB2(ItemNameDescription);
    //LOAD_DB2(BattlePetAbility); wait for bfa
    //LOAD_DB2(BattlePetAbilityState); wait for bfa
    //LOAD_DB2(BattlePetAbilityTurn); wait for bfa
    //LOAD_DB2(BattlePetAbilityEffect); wait for bfa
    //LOAD_DB2(BattlePetEffectProperties); wait for bfa
    //LOAD_DB2(BattlePetSpeciesXAbility); wait for bfa
    //LOAD_DB2(MapChallengeMode); wait for bfa
    //LOAD_DB2(CharShipment); wait for bfa
    //LOAD_DB2(CharShipmentContainer); wait for bfa
    //LOAD_DB2(GarrClassSpecPlayerCond); wait for bfa
    //LOAD_DB2(GarrAbilityEffect); wait for bfa
    //LOAD_DB2(GarrEncounterXMechanic); wait for bfa
    //LOAD_DB2(GarrFollowerLevelXP); wait for bfa
    //LOAD_DB2(GarrFollowerType); wait for bfa
    //LOAD_DB2(GarrFollSupportSpell); wait for bfa
    //LOAD_DB2(GarrFollowerXAbility); wait for bfa
    //LOAD_DB2(GarrMechanic); wait for bfa
    //LOAD_DB2(GarrMechanicType); wait for bfa
    //LOAD_DB2(GarrMission); wait for bfa
    //LOAD_DB2(GarrMissionXEncounter); wait for bfa
    //LOAD_DB2(GarrTalent); wait for bfa
    //LOAD_DB2(GarrTalentTree); wait for bfa
    //LOAD_DB2(GarrType); wait for bfa
    //LOAD_DB2(sGroupFinderActivityStore);
    //LOAD_DB2(sGroupFinderCategoryStore);
    //LOAD_DB2(sQuestV2CliTaskStore);
    //LOAD_DB2(SceneScriptPackageMember);
    //LOAD_DB2(SpellKeyboundOverride);
    //LOAD_DB2(SpellReagentsCurrency);
    //LOAD_DB2(UiCamera);
    //LOAD_DB2(VignetteStore);
    //LOAD_DB2(WorldStateUI);

    #undef LOAD_DB2

    for (uint32 i = 0; i < GarrClassSpecPlayerCond.GetNumRows(); ++i)
    {
        if (Structs::GarrClassSpecPlayerCond const* spec = GarrClassSpecPlayerCond.LookupEntry(i))
            sDB2Manager._garrSpecPlayer[spec->ClassSpec].push_back(spec);
    }

    for (uint32 i = 0; i < GarrTalentTree.GetNumRows(); ++i)
    {
        if (Structs::GarrTalentTree const* tree = GarrTalentTree.LookupEntry(i))
            sDB2Manager._garrTalentTree[tree->ClassID] = tree;
    }

    for (uint32 i = 0; i < sAzeriteEmpoweredItemStore.GetNumRows(); ++i)
    {
        if (Structs::AzeriteEmpoweredItemEntry const* azerite = sAzeriteEmpoweredItemStore.LookupEntry(i))
            sDB2Manager._empoweredItem[azerite->ItemID] = azerite;
    }

    for (uint32 i = 0; i < sAzeriteTierUnlockStore.GetNumRows(); ++i)
    {
        if (Structs::AzeriteTierUnlockEntry const* azerite = sAzeriteTierUnlockStore.LookupEntry(i))
            sDB2Manager._azeriteTierUnlock[azerite->AzeriteTierUnlockSetId].push_back(azerite);
    }

    for (uint32 i = 0; i < sAzeritePowerSetMember.GetNumRows(); ++i)
    {
        if (Structs::AzeritePowerSetMemberEntry const* azerite = sAzeritePowerSetMember.LookupEntry(i))
            sDB2Manager._azeritePowerSetMember[azerite->AzeritePowerSetID] = azerite;
    }

    for (uint32 i = 0; i < sSpecSetMemberStore.GetNumRows(); ++i)
    {
        if (Structs::SpecSetMemberEntry const* spec = sSpecSetMemberStore.LookupEntry(i))
            sDB2Manager._specSetMember[spec->SpecSetMemberID].push_back(spec->CharSpecialization);
    }

    TC_LOG_INFO("server.loading", ">> Initialized %d PROJECT DB2 data stores in %u ms", DB2FilesCount, GetMSTimeDiffToNow(oldMSTime));
}

void AfterLoadDatastores()
{
    // spells related
    for (uint32 i = 0; i < sSpellNameStore.GetNumRows(); ++i)
    {
        if (SpellInfo * spellInfo = GET_SPELL(i))
        {
            // force send to client for spells with SPELL_EFFECT_LOOT, fixes bonus roll / toast interface
            if (spellInfo->HasEffect(SPELL_EFFECT_LOOT)) // SPELL_EFFECT_LOOT
            {
                spellInfo->AttributesCuF |= PROJECT::Spells::Attributes::SEND_TO_CLIENT;
                spellInfo->AttributesCuF |= PROJECT::Spells::Attributes::SEND_SPELL_START_EVEN_IF_TRIGGERED;
                // and to have delay so rolling animation @ toast interface lasts longer
                spellInfo->Speed = 1; // actual speed set in PROJECT::Hooks::Spells::prepare()
            }
        }
    }

    for (DBStorageIterator<ArtifactPowerRankEntry> itr = sArtifactPowerRankStore.begin(); itr != sArtifactPowerRankStore.end(); ++itr)
        if (SpellInfo* spellInfo = GET_SPELL(itr->SpellID))
            spellInfo->Variables.Set("IsArtifactSpell", true);
}

} // DataStores
} // PROJECT

std::vector<PROJECT::DataStores::Structs::GarrClassSpecPlayerCond const*> DB2Manager::GetGarrisonSpecPlayerCond(uint32 spec) const
{
    auto itr = _garrSpecPlayer.find(spec);
    if (itr != _garrSpecPlayer.end())
        return itr->second;

    return std::vector<PROJECT::DataStores::Structs::GarrClassSpecPlayerCond const*>();
}

PROJECT::DataStores::Structs::GarrTalentTree const* DB2Manager::GetGarrisonTalentTreeByPlayerClass(uint8 _class) const
{
    auto itr = _garrTalentTree.find(_class);
    if (itr != _garrTalentTree.end())
        return itr->second;

    return nullptr;
}

PROJECT::DataStores::Structs::AzeriteEmpoweredItemEntry const* DB2Manager::GetAzeriteEmpoweredItem(uint32 itemID) const
{
    auto itr = _empoweredItem.find(itemID);
    if (itr == _empoweredItem.end())
        return nullptr;

    return itr->second;
}

std::vector<PROJECT::DataStores::Structs::AzeriteTierUnlockEntry const*> DB2Manager::GetAzeriteTierUnlock(uint32 itemID) const
{
    auto item = GetAzeriteEmpoweredItem(itemID);
    if (item)
    {
        auto itr = _azeriteTierUnlock.find(item->AzeriteTierUnlockSetID);
        if (itr == _azeriteTierUnlock.end())
            return {};

        return itr->second;
    }

    return {};
}

uint32 DB2Manager::GetBonusListIDToAddItemLevel(uint32 value)
{
    auto itr = _itemLevelToBonusList.find(value);
    if (itr != _itemLevelToBonusList.end())
        return itr->second;

    return 0;
}
