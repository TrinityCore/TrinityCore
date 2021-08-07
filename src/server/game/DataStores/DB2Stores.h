/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_DB2STORES_H
#define TRINITY_DB2STORES_H

#include "DB2Store.h"
#include "DB2Structure.h"
#include <Optional.h>
#include "SharedDefines.h"
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

 // temporary hack until includes are sorted out (don't want to pull in Windows.h)
#ifdef GetClassName
#undef GetClassName
#endif

class DB2HotfixGeneratorBase;

TC_GAME_API extern DB2Storage<AchievementEntry>                     sAchievementStore;
TC_GAME_API extern DB2Storage<Achievement_CategoryEntry>            sAchievementCategoryStore;
TC_GAME_API extern DB2Storage<AdventureJournalEntry>                sAdventureJournalStore;
TC_GAME_API extern DB2Storage<AdventureMapPOIEntry>                 sAdventureMapPOIStore;
TC_GAME_API extern DB2Storage<AnimationDataEntry>                   sAnimationDataStore;
TC_GAME_API extern DB2Storage<AnimKitEntry>                         sAnimKitStore;
TC_GAME_API extern DB2Storage<AreaTableEntry>                       sAreaTableStore;
TC_GAME_API extern DB2Storage<AreaTriggerEntry>                     sAreaTriggerStore;
TC_GAME_API extern DB2Storage<ArmorLocationEntry>                   sArmorLocationStore;
TC_GAME_API extern DB2Storage<ArtifactEntry>                        sArtifactStore;
TC_GAME_API extern DB2Storage<ArtifactCategoryEntry>                sArtifactCategoryStore;
TC_GAME_API extern DB2Storage<ArtifactAppearanceEntry>              sArtifactAppearanceStore;
TC_GAME_API extern DB2Storage<ArtifactAppearanceSetEntry>           sArtifactAppearanceSetStore;
TC_GAME_API extern DB2Storage<ArtifactPowerEntry>                   sArtifactPowerStore;
TC_GAME_API extern DB2Storage<ArtifactPowerPickerEntry>             sArtifactPowerPickerStore;
TC_GAME_API extern DB2Storage<ArtifactTierEntry>                    sArtifactTierStore;
TC_GAME_API extern DB2Storage<ArtifactUnlockEntry>                  sArtifactUnlockStore;
TC_GAME_API extern DB2Storage<AuctionHouseEntry>                    sAuctionHouseStore;
TC_GAME_API extern DB2Storage<AzeriteEssenceEntry>                  sAzeriteEssenceStore;
TC_GAME_API extern DB2Storage<AzeriteKnowledgeMultiplierEntry>      sAzeriteKnowledgeMultiplierStore;
TC_GAME_API extern DB2Storage<AzeriteItemMilestonePowerEntry>       sAzeriteItemMilestonePowerStore;
TC_GAME_API extern DB2Storage<AzeriteLevelInfoEntry>                sAzeriteLevelInfoStore;
TC_GAME_API extern DB2Storage<AzeritePowerEntry>                    sAzeritePowerStore;
TC_GAME_API extern DB2Storage<BankBagSlotPricesEntry>               sBankBagSlotPricesStore;
TC_GAME_API extern DB2Storage<BannedAddonsEntry>                    sBannedAddonsStore;
TC_GAME_API extern DB2Storage<BarberShopStyleEntry>                 sBarberShopStyleStore;
TC_GAME_API extern DB2Storage<BattlePetBreedQualityEntry>           sBattlePetBreedQualityStore;
TC_GAME_API extern DB2Storage<BattlePetBreedStateEntry>             sBattlePetBreedStateStore;
TC_GAME_API extern DB2Storage<BattlePetSpeciesEntry>                sBattlePetSpeciesStore;
TC_GAME_API extern DB2Storage<BattlePetSpeciesStateEntry>           sBattlePetSpeciesStateStore;
TC_GAME_API extern DB2Storage<BattlemasterListEntry>                sBattlemasterListStore;
TC_GAME_API extern DB2Storage<BroadcastTextEntry>                   sBroadcastTextStore;
TC_GAME_API extern DB2Storage<Cfg_RegionsEntry>                     sCfgRegionsStore;
TC_GAME_API extern DB2Storage<CharTitlesEntry>                      sCharTitlesStore;
TC_GAME_API extern DB2Storage<CharacterLoadoutEntry>                sCharacterLoadoutStore;
TC_GAME_API extern DB2Storage<CharacterLoadoutItemEntry>            sCharacterLoadoutItemStore;
TC_GAME_API extern DB2Storage<ChatChannelsEntry>                    sChatChannelsStore;
TC_GAME_API extern DB2Storage<ChrClassesEntry>                      sChrClassesStore;
TC_GAME_API extern DB2Storage<ChrCustomizationReqEntry>             sChrCustomizationReqStore;
TC_GAME_API extern DB2Storage<ChrCustomizationOptionEntry>          sChrCustomizationOptionStore;
TC_GAME_API extern DB2Storage<ChrRacesEntry>                        sChrRacesStore;
TC_GAME_API extern DB2Storage<ChrSpecializationEntry>               sChrSpecializationStore;
TC_GAME_API extern DB2Storage<CinematicCameraEntry>                 sCinematicCameraStore;
TC_GAME_API extern DB2Storage<CinematicSequencesEntry>              sCinematicSequencesStore;
TC_GAME_API extern DB2Storage<ContentTuningEntry>                   sContentTuningStore;
TC_GAME_API extern DB2Storage<ConversationLineEntry>                sConversationLineStore;
TC_GAME_API extern DB2Storage<CorruptionEffectsEntry>               sCorruptionEffectsStore;
TC_GAME_API extern DB2Storage<CreatureDisplayInfoEntry>             sCreatureDisplayInfoStore;
TC_GAME_API extern DB2Storage<CreatureDisplayInfoExtraEntry>        sCreatureDisplayInfoExtraStore;
TC_GAME_API extern DB2Storage<CreatureFamilyEntry>                  sCreatureFamilyStore;
TC_GAME_API extern DB2Storage<CreatureModelDataEntry>               sCreatureModelDataStore;
TC_GAME_API extern DB2Storage<CreatureTypeEntry>                    sCreatureTypeStore;
TC_GAME_API extern DB2Storage<CriteriaEntry>                        sCriteriaStore;
TC_GAME_API extern DB2Storage<CriteriaTreeEntry>                    sCriteriaTreeStore;
TC_GAME_API extern DB2Storage<CurrencyTypesEntry>                   sCurrencyTypesStore;
TC_GAME_API extern DB2Storage<CurveEntry>                           sCurveStore;
TC_GAME_API extern DB2Storage<DestructibleModelDataEntry>           sDestructibleModelDataStore;
TC_GAME_API extern DB2Storage<DifficultyEntry>                      sDifficultyStore;
TC_GAME_API extern DB2Storage<DungeonEncounterEntry>                sDungeonEncounterStore;
TC_GAME_API extern DB2Storage<DurabilityCostsEntry>                 sDurabilityCostsStore;
TC_GAME_API extern DB2Storage<DurabilityQualityEntry>               sDurabilityQualityStore;
TC_GAME_API extern DB2Storage<EmotesEntry>                          sEmotesStore;
TC_GAME_API extern DB2Storage<EmotesTextEntry>                      sEmotesTextStore;
TC_GAME_API extern DB2Storage<FactionEntry>                         sFactionStore;
TC_GAME_API extern DB2Storage<FactionTemplateEntry>                 sFactionTemplateStore;
TC_GAME_API extern DB2Storage<FriendshipRepReactionEntry>           sFriendshipRepReactionStore;
TC_GAME_API extern DB2Storage<FriendshipReputationEntry>            sFriendshipReputationStore;
TC_GAME_API extern DB2Storage<GameObjectDisplayInfoEntry>           sGameObjectDisplayInfoStore;
TC_GAME_API extern DB2Storage<GameObjectsEntry>                     sGameObjectsStore;
TC_GAME_API extern DB2Storage<GarrAbilityEntry>                     sGarrAbilityStore;
TC_GAME_API extern DB2Storage<GarrBuildingEntry>                    sGarrBuildingStore;
TC_GAME_API extern DB2Storage<GarrBuildingPlotInstEntry>            sGarrBuildingPlotInstStore;
TC_GAME_API extern DB2Storage<GarrClassSpecEntry>                   sGarrClassSpecStore;
TC_GAME_API extern DB2Storage<GarrFollowerEntry>                    sGarrFollowerStore;
TC_GAME_API extern DB2Storage<GarrFollowerXAbilityEntry>            sGarrFollowerXAbilityStore;
TC_GAME_API extern DB2Storage<GarrPlotEntry>                        sGarrPlotStore;
TC_GAME_API extern DB2Storage<GarrPlotBuildingEntry>                sGarrPlotBuildingStore;
TC_GAME_API extern DB2Storage<GarrPlotInstanceEntry>                sGarrPlotInstanceStore;
TC_GAME_API extern DB2Storage<GarrSiteLevelEntry>                   sGarrSiteLevelStore;
TC_GAME_API extern DB2Storage<GarrSiteLevelPlotInstEntry>           sGarrSiteLevelPlotInstStore;
TC_GAME_API extern DB2Storage<GemPropertiesEntry>                   sGemPropertiesStore;
TC_GAME_API extern DB2Storage<GlyphPropertiesEntry>                 sGlyphPropertiesStore;
TC_GAME_API extern DB2Storage<GuildColorBackgroundEntry>            sGuildColorBackgroundStore;
TC_GAME_API extern DB2Storage<GuildColorBorderEntry>                sGuildColorBorderStore;
TC_GAME_API extern DB2Storage<GuildColorEmblemEntry>                sGuildColorEmblemStore;
TC_GAME_API extern DB2Storage<GuildPerkSpellsEntry>                 sGuildPerkSpellsStore;
TC_GAME_API extern DB2Storage<HolidaysEntry>                        sHolidaysStore;
TC_GAME_API extern DB2Storage<ImportPriceArmorEntry>                sImportPriceArmorStore;
TC_GAME_API extern DB2Storage<ImportPriceQualityEntry>              sImportPriceQualityStore;
TC_GAME_API extern DB2Storage<ImportPriceShieldEntry>               sImportPriceShieldStore;
TC_GAME_API extern DB2Storage<ImportPriceWeaponEntry>               sImportPriceWeaponStore;
TC_GAME_API extern DB2Storage<ItemAppearanceEntry>                  sItemAppearanceStore;
TC_GAME_API extern DB2Storage<ItemArmorQualityEntry>                sItemArmorQualityStore;
TC_GAME_API extern DB2Storage<ItemArmorShieldEntry>                 sItemArmorShieldStore;
TC_GAME_API extern DB2Storage<ItemArmorTotalEntry>                  sItemArmorTotalStore;
TC_GAME_API extern DB2Storage<ItemBagFamilyEntry>                   sItemBagFamilyStore;
TC_GAME_API extern DB2Storage<ItemDamageAmmoEntry>                  sItemDamageAmmoStore;
TC_GAME_API extern DB2Storage<ItemDamageOneHandEntry>               sItemDamageOneHandStore;
TC_GAME_API extern DB2Storage<ItemDamageOneHandCasterEntry>         sItemDamageOneHandCasterStore;
TC_GAME_API extern DB2Storage<ItemDamageTwoHandEntry>               sItemDamageTwoHandStore;
TC_GAME_API extern DB2Storage<ItemDamageTwoHandCasterEntry>         sItemDamageTwoHandCasterStore;
TC_GAME_API extern DB2Storage<ItemDisenchantLootEntry>              sItemDisenchantLootStore;
TC_GAME_API extern DB2Storage<ItemEffectEntry>                      sItemEffectStore;
TC_GAME_API extern DB2Storage<ItemNameDescriptionEntry>             sItemNameDescriptionStore;
TC_GAME_API extern DB2Storage<ItemEntry>                            sItemStore;
TC_GAME_API extern DB2Storage<ItemExtendedCostEntry>                sItemExtendedCostStore;
TC_GAME_API extern DB2Storage<ItemLimitCategoryEntry>               sItemLimitCategoryStore;
TC_GAME_API extern DB2Storage<ItemModifiedAppearanceEntry>          sItemModifiedAppearanceStore;
TC_GAME_API extern DB2Storage<ItemModifiedAppearanceExtraEntry>     sItemModifiedAppearanceExtraStore;
TC_GAME_API extern DB2Storage<ItemPriceBaseEntry>                   sItemPriceBaseStore;
TC_GAME_API extern DB2Storage<ItemSearchNameEntry>                  sItemSearchNameStore;
TC_GAME_API extern DB2Storage<ItemSetEntry>                         sItemSetStore;
TC_GAME_API extern DB2Storage<ItemSetSpellEntry>                    sItemSetSpellStore;
TC_GAME_API extern DB2Storage<ItemSparseEntry>                      sItemSparseStore;
TC_GAME_API extern DB2Storage<ItemSpecEntry>                        sItemSpecStore;
TC_GAME_API extern DB2Storage<ItemSpecOverrideEntry>                sItemSpecOverrideStore;
TC_GAME_API extern DB2Storage<ItemXItemEffectEntry>                 sItemXItemEffectStore;
TC_GAME_API extern DB2Storage<LanguageWordsEntry>                   sLanguageWordsStore;
TC_GAME_API extern DB2Storage<LanguagesEntry>                       sLanguagesStore;
TC_GAME_API extern DB2Storage<LFGDungeonsEntry>                     sLFGDungeonsStore;
TC_GAME_API extern DB2Storage<LiquidTypeEntry>                      sLiquidTypeStore;
TC_GAME_API extern DB2Storage<LockEntry>                            sLockStore;
TC_GAME_API extern DB2Storage<MailTemplateEntry>                    sMailTemplateStore;
TC_GAME_API extern DB2Storage<MapEntry>                             sMapStore;
TC_GAME_API extern DB2Storage<ModifierTreeEntry>                    sModifierTreeStore;
TC_GAME_API extern DB2Storage<MountCapabilityEntry>                 sMountCapabilityStore;
TC_GAME_API extern DB2Storage<MountEntry>                           sMountStore;
TC_GAME_API extern DB2Storage<MovieEntry>                           sMovieStore;
TC_GAME_API extern DB2Storage<OverrideSpellDataEntry>               sOverrideSpellDataStore;
TC_GAME_API extern DB2Storage<ParagonReputationEntry>               sParagonReputationStore;
TC_GAME_API extern DB2Storage<PhaseEntry>                           sPhaseStore;
TC_GAME_API extern DB2Storage<PlayerConditionEntry>                 sPlayerConditionStore;
TC_GAME_API extern DB2Storage<PowerDisplayEntry>                    sPowerDisplayStore;
TC_GAME_API extern DB2Storage<PvpTalentEntry>                       sPvpTalentStore;
TC_GAME_API extern DB2Storage<PvpTalentCategoryEntry>               sPvpTalentCategoryStore;
TC_GAME_API extern DB2Storage<PvpTalentSlotUnlockEntry>             sPvpTalentSlotUnlockStore;
TC_GAME_API extern DB2Storage<PvpTierEntry>                         sPvpTierStore;
TC_GAME_API extern DB2Storage<QuestFactionRewardEntry>              sQuestFactionRewardStore;
TC_GAME_API extern DB2Storage<QuestInfoEntry>                       sQuestInfoStore;
TC_GAME_API extern DB2Storage<QuestMoneyRewardEntry>                sQuestMoneyRewardStore;
TC_GAME_API extern DB2Storage<QuestSortEntry>                       sQuestSortStore;
TC_GAME_API extern DB2Storage<QuestXPEntry>                         sQuestXPStore;
TC_GAME_API extern DB2Storage<RandPropPointsEntry>                  sRandPropPointsStore;
TC_GAME_API extern DB2Storage<RewardPackEntry>                      sRewardPackStore;
TC_GAME_API extern DB2Storage<ScenarioEntry>                        sScenarioStore;
TC_GAME_API extern DB2Storage<ScenarioStepEntry>                    sScenarioStepStore;
TC_GAME_API extern DB2Storage<SkillLineEntry>                       sSkillLineStore;
TC_GAME_API extern DB2Storage<SceneScriptPackageEntry>              sSceneScriptPackageStore;
TC_GAME_API extern DB2Storage<SkillLineAbilityEntry>                sSkillLineAbilityStore;
TC_GAME_API extern DB2Storage<SkillRaceClassInfoEntry>              sSkillRaceClassInfoStore;
TC_GAME_API extern DB2Storage<SoundKitEntry>                        sSoundKitStore;
TC_GAME_API extern DB2Storage<SpellAuraOptionsEntry>                sSpellAuraOptionsStore;
TC_GAME_API extern DB2Storage<SpellAuraRestrictionsEntry>           sSpellAuraRestrictionsStore;
TC_GAME_API extern DB2Storage<SpellCastTimesEntry>                  sSpellCastTimesStore;
TC_GAME_API extern DB2Storage<SpellCastingRequirementsEntry>        sSpellCastingRequirementsStore;
TC_GAME_API extern DB2Storage<SpellCategoriesEntry>                 sSpellCategoriesStore;
TC_GAME_API extern DB2Storage<SpellCategoryEntry>                   sSpellCategoryStore;
TC_GAME_API extern DB2Storage<SpellClassOptionsEntry>               sSpellClassOptionsStore;
TC_GAME_API extern DB2Storage<SpellCooldownsEntry>                  sSpellCooldownsStore;
TC_GAME_API extern DB2Storage<SpellDurationEntry>                   sSpellDurationStore;
TC_GAME_API extern DB2Storage<SpellEffectEntry>                     sSpellEffectStore;
TC_GAME_API extern DB2Storage<SpellEquippedItemsEntry>              sSpellEquippedItemsStore;
TC_GAME_API extern DB2Storage<SpellFocusObjectEntry>                sSpellFocusObjectStore;
TC_GAME_API extern DB2Storage<SpellInterruptsEntry>                 sSpellInterruptsStore;
TC_GAME_API extern DB2Storage<SpellItemEnchantmentEntry>            sSpellItemEnchantmentStore;
TC_GAME_API extern DB2Storage<SpellItemEnchantmentConditionEntry>   sSpellItemEnchantmentConditionStore;
TC_GAME_API extern DB2Storage<SpellLabelEntry>                      sSpellLabelStore;
TC_GAME_API extern DB2Storage<SpellLearnSpellEntry>                 sSpellLearnSpellStore;
TC_GAME_API extern DB2Storage<SpellLevelsEntry>                     sSpellLevelsStore;
TC_GAME_API extern DB2Storage<SpellMiscEntry>                       sSpellMiscStore;
TC_GAME_API extern DB2Storage<SpellNameEntry>                       sSpellNameStore;
TC_GAME_API extern DB2Storage<SpellPowerEntry>                      sSpellPowerStore;
TC_GAME_API extern DB2Storage<SpellPowerDifficultyEntry>            sSpellPowerDifficultyStore;
TC_GAME_API extern DB2Storage<SpellProcsPerMinuteEntry>             sSpellProcsPerMinuteStore;
TC_GAME_API extern DB2Storage<SpellRadiusEntry>                     sSpellRadiusStore;
TC_GAME_API extern DB2Storage<SpellRangeEntry>                      sSpellRangeStore;
TC_GAME_API extern DB2Storage<SpellReagentsEntry>                   sSpellReagentsStore;
TC_GAME_API extern DB2Storage<SpellScalingEntry>                    sSpellScalingStore;
TC_GAME_API extern DB2Storage<SpellShapeshiftEntry>                 sSpellShapeshiftStore;
TC_GAME_API extern DB2Storage<SpellShapeshiftFormEntry>             sSpellShapeshiftFormStore;
TC_GAME_API extern DB2Storage<SpellTargetRestrictionsEntry>         sSpellTargetRestrictionsStore;
TC_GAME_API extern DB2Storage<SpellTotemsEntry>                     sSpellTotemsStore;
TC_GAME_API extern DB2Storage<SpellVisualKitEntry>                  sSpellVisualKitStore;
TC_GAME_API extern DB2Storage<SpellXSpellVisualEntry>               sSpellXSpellVisualStore;
TC_GAME_API extern DB2Storage<SummonPropertiesEntry>                sSummonPropertiesStore;
TC_GAME_API extern DB2Storage<TalentEntry>                          sTalentStore;
TC_GAME_API extern DB2Storage<TaxiNodesEntry>                       sTaxiNodesStore;
TC_GAME_API extern DB2Storage<TaxiPathEntry>                        sTaxiPathStore;
TC_GAME_API extern DB2Storage<TransmogHolidayEntry>                 sTransmogHolidayStore;
TC_GAME_API extern DB2Storage<TransmogSetEntry>                     sTransmogSetStore;
TC_GAME_API extern DB2Storage<TransmogSetGroupEntry>                sTransmogSetGroupStore;
TC_GAME_API extern DB2Storage<TransmogSetItemEntry>                 sTransmogSetItemStore;
TC_GAME_API extern DB2Storage<TransportAnimationEntry>              sTransportAnimationStore;
TC_GAME_API extern DB2Storage<TransportRotationEntry>               sTransportRotationStore;
TC_GAME_API extern DB2Storage<UnitPowerBarEntry>                    sUnitPowerBarStore;
TC_GAME_API extern DB2Storage<VehicleEntry>                         sVehicleStore;
TC_GAME_API extern DB2Storage<VehicleSeatEntry>                     sVehicleSeatStore;
TC_GAME_API extern DB2Storage<WorldEffectEntry>                     sWorldEffectStore;
TC_GAME_API extern DB2Storage<WorldMapOverlayEntry>                 sWorldMapOverlayStore;
TC_GAME_API extern DB2Storage<WorldStateExpressionEntry>            sWorldStateExpressionStore;

struct ContentTuningLevels
{
    int16 MinLevel = 0;
    int16 MaxLevel = 0;
    int16 MinLevelWithDelta = 0;
    int16 MaxLevelWithDelta = 0;
    int16 TargetLevelMin = 0;
    int16 TargetLevelMax = 0;
};

struct ShapeshiftFormModelData
{
    uint32 OptionID;
    std::vector<ChrCustomizationChoiceEntry const*> const* Choices;
    std::vector<ChrCustomizationDisplayInfoEntry const*> Displays;
};

struct TaxiPathBySourceAndDestination
{
    TaxiPathBySourceAndDestination() : ID(0), price(0) { }
    TaxiPathBySourceAndDestination(uint32 _id, uint32 _price) : ID(_id), price(_price) { }

    uint32 ID;
    uint32 price;
};

using TaxiPathSetForSource = std::map<uint32, TaxiPathBySourceAndDestination>;
using TaxiPathSetBySource = std::map<uint32, TaxiPathSetForSource>;

using TaxiPathNodeList = std::vector<TaxiPathNodeEntry const*>;
using TaxiPathNodesByPath = std::vector<TaxiPathNodeList>;

TC_GAME_API extern TaxiMask                                         sTaxiNodesMask;
TC_GAME_API extern TaxiMask                                         sOldContinentsNodesMask;
TC_GAME_API extern TaxiMask                                         sHordeTaxiNodesMask;
TC_GAME_API extern TaxiMask                                         sAllianceTaxiNodesMask;
TC_GAME_API extern TaxiPathSetBySource                              sTaxiPathSetBySource;
TC_GAME_API extern TaxiPathNodesByPath                              sTaxiPathNodesByPath;

#define DEFINE_DB2_SET_COMPARATOR(structure) \
    struct structure ## Comparator \
    { \
        bool operator()(structure const* left, structure const* right) const { return Compare(left, right); } \
        static bool Compare(structure const* left, structure const* right); \
    };

class TC_GAME_API DB2Manager
{
public:
    DEFINE_DB2_SET_COMPARATOR(FriendshipRepReactionEntry)
    DEFINE_DB2_SET_COMPARATOR(MountTypeXCapabilityEntry)

    struct HotfixRecord
    {
        enum class Status : uint8
        {
            NotSet          = 0,
            Valid           = 1,
            RecordRemoved   = 2,
            Invalid         = 3,
            NotPublic       = 4
        };

        uint32 TableHash = 0;
        int32 RecordID = 0;
        int32 HotfixID = 0;
        Status HotfixStatus = Status::Invalid;

        friend bool operator<(HotfixRecord const& left, HotfixRecord const& right)
        {
            return std::tie(left.HotfixID, left.TableHash, left.RecordID) < std::tie(right.HotfixID, right.TableHash, right.RecordID);
        }
    };

    struct HotfixOptionalData
    {
        uint32 Key;
        std::vector<uint8> Data;
    };

    using HotfixContainer = std::unordered_map<int32, std::vector<HotfixRecord>>;

    using FriendshipRepReactionSet = std::set<FriendshipRepReactionEntry const*, FriendshipRepReactionEntryComparator>;
    using ItemBonusList = std::vector<ItemBonusEntry const*>;
    using MapDifficultyContainer = std::unordered_map<uint32, std::unordered_map<uint32, MapDifficultyEntry const*>>;
    using MapDifficultyConditionsContainer = std::vector<std::pair<uint32, PlayerConditionEntry const*>>;
    using MountTypeXCapabilitySet = std::set<MountTypeXCapabilityEntry const*, MountTypeXCapabilityEntryComparator>;
    using MountXDisplayContainer = std::vector<MountXDisplayEntry const*>;

    static DB2Manager& Instance();

    uint32 LoadStores(std::string const& dataPath, LocaleConstant defaultLocale);
    DB2StorageBase const* GetStorage(uint32 type) const;

    void LoadHotfixData();
    void LoadHotfixBlob(uint32 localeMask);
    void LoadHotfixOptionalData(uint32 localeMask);
    uint32 GetHotfixCount() const;
    HotfixContainer const& GetHotfixData() const;
    std::vector<uint8> const* GetHotfixBlobData(uint32 tableHash, int32 recordId, LocaleConstant locale) const;
    std::vector<HotfixOptionalData> const* GetHotfixOptionalData(uint32 tableHash, int32 recordId, LocaleConstant locale) const;

    uint32 GetEmptyAnimStateID() const;
    std::vector<uint32> GetAreasForGroup(uint32 areaGroupId) const;
    static bool IsInArea(uint32 objectAreaId, uint32 areaId);
    std::vector<ArtifactPowerEntry const*> GetArtifactPowers(uint8 artifactId) const;
    std::unordered_set<uint32> const* GetArtifactPowerLinks(uint32 artifactPowerId) const;
    ArtifactPowerRankEntry const* GetArtifactPowerRank(uint32 artifactPowerId, uint8 rank) const;
    AzeriteEmpoweredItemEntry const* GetAzeriteEmpoweredItem(uint32 itemId) const;
    bool IsAzeriteItem(uint32 itemId) const;
    AzeriteEssencePowerEntry const* GetAzeriteEssencePower(uint32 azeriteEssenceId, uint32 rank) const;
    std::vector<AzeriteItemMilestonePowerEntry const*> const& GetAzeriteItemMilestonePowers() const;
    AzeriteItemMilestonePowerEntry const* GetAzeriteItemMilestonePower(uint8 slot) const;
    std::vector<AzeritePowerSetMemberEntry const*> const* GetAzeritePowers(uint32 itemId) const;
    uint32 GetRequiredAzeriteLevelForAzeritePowerTier(uint32 azeriteUnlockSetId, ItemContext context, uint32 tier) const;
    static char const* GetBroadcastTextValue(BroadcastTextEntry const* broadcastText, LocaleConstant locale = DEFAULT_LOCALE, uint8 gender = GENDER_MALE, bool forceGender = false);
    ChrClassUIDisplayEntry const* GetUiDisplayForClass(Classes unitClass) const;
    static char const* GetClassName(uint8 class_, LocaleConstant locale = DEFAULT_LOCALE);
    uint32 GetPowerIndexByClass(Powers power, uint32 classId) const;
    std::vector<ChrCustomizationChoiceEntry const*> const* GetCustomiztionChoices(uint32 chrCustomizationOptionId) const;
    std::vector<ChrCustomizationOptionEntry const*> const* GetCustomiztionOptions(uint8 race, uint8 gender) const;
    std::unordered_map<uint32, std::vector<uint32>> const* GetRequiredCustomizationChoices(uint32 chrCustomizationReqId) const;
    ChrModelEntry const* GetChrModel(uint8 race, uint8 gender) const;
    static char const* GetChrRaceName(uint8 race, LocaleConstant locale = DEFAULT_LOCALE);
    ChrSpecializationEntry const* GetChrSpecializationByIndex(uint32 class_, uint32 index) const;
    ChrSpecializationEntry const* GetDefaultChrSpecializationForClass(uint32 class_) const;
    Optional<ContentTuningLevels> GetContentTuningData(uint32 contentTuningId, uint32 replacementConditionMask, bool forItem = false) const;
    static char const* GetCreatureFamilyPetName(uint32 petfamily, LocaleConstant locale);
    float GetCurveValueAt(uint32 curveId, float x) const;
    EmotesTextSoundEntry const* GetTextSoundEmoteFor(uint32 emote, uint8 race, uint8 gender, uint8 class_) const;
    float EvaluateExpectedStat(ExpectedStatType stat, uint32 level, int32 expansion, uint32 contentTuningId, Classes unitClass) const;
    std::vector<uint32> const* GetFactionTeamList(uint32 faction) const;
    FriendshipRepReactionSet const* GetFriendshipRepReactions(uint32 friendshipRepID) const;
    uint32 GetGlobalCurveId(GlobalCurve globalCurveType) const;
    std::vector<uint32> const* GetGlyphBindableSpells(uint32 glyphPropertiesId) const;
    std::vector<uint32> const* GetGlyphRequiredSpecs(uint32 glyphPropertiesId) const;
    HeirloomEntry const* GetHeirloomByItemId(uint32 itemId) const;
    ItemBonusList const* GetItemBonusList(uint32 bonusListId) const;
    uint32 GetItemBonusListForItemLevelDelta(int16 delta) const;
    std::set<uint32> GetDefaultItemBonusTree(uint32 itemId, ItemContext itemContext) const;
    std::set<uint32> GetAllItemBonusTreeBonuses(uint32 itemBonusTreeId) const;
    ItemChildEquipmentEntry const* GetItemChildEquipment(uint32 itemId) const;
    ItemClassEntry const* GetItemClassByOldEnum(uint32 itemClass) const;
    bool HasItemCurrencyCost(uint32 itemId) const;
    std::vector<ItemLimitCategoryConditionEntry const*> const* GetItemLimitCategoryConditions(uint32 categoryId) const;
    uint32 GetItemDisplayId(uint32 itemId, uint32 appearanceModId) const;
    ItemModifiedAppearanceEntry const* GetItemModifiedAppearance(uint32 itemId, uint32 appearanceModId) const;
    ItemModifiedAppearanceEntry const* GetDefaultItemModifiedAppearance(uint32 itemId) const;
    std::vector<ItemSetSpellEntry const*> const* GetItemSetSpells(uint32 itemSetId) const;
    std::vector<ItemSpecOverrideEntry const*> const* GetItemSpecOverrides(uint32 itemId) const;
    static LFGDungeonsEntry const* GetLfgDungeon(uint32 mapId, Difficulty difficulty);
    static uint32 GetDefaultMapLight(uint32 mapId);
    static uint32 GetLiquidFlags(uint32 liquidType);
    MapDifficultyContainer const& GetMapDifficulties() const;
    MapDifficultyEntry const* GetDefaultMapDifficulty(uint32 mapId, Difficulty* difficulty = nullptr) const;
    MapDifficultyEntry const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty) const;
    MapDifficultyEntry const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty) const;
    MapDifficultyConditionsContainer const* GetMapDifficultyConditions(uint32 mapDifficultyId) const;
    MountEntry const* GetMount(uint32 spellId) const;
    MountEntry const* GetMountById(uint32 id) const;
    MountTypeXCapabilitySet const* GetMountCapabilities(uint32 mountType) const;
    MountXDisplayContainer const* GetMountDisplays(uint32 mountId) const;
    std::string GetNameGenEntry(uint8 race, uint8 gender) const;
    ResponseCodes ValidateName(std::wstring const& name, LocaleConstant locale) const;
    static int32 GetNumTalentsAtLevel(uint32 level, Classes playerClass);
    ParagonReputationEntry const* GetParagonReputation(uint32 factionId) const;
    std::vector<uint32> const* GetPhasesForGroup(uint32 group) const;
    PowerTypeEntry const* GetPowerTypeEntry(Powers power) const;
    PowerTypeEntry const* GetPowerTypeByName(std::string const& name) const;
    uint8 GetPvpItemLevelBonus(uint32 itemId) const;
    static PVPDifficultyEntry const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level);
    static PVPDifficultyEntry const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id);
    uint32 GetRequiredLevelForPvpTalentSlot(uint8 slot, Classes class_) const;
    int32 GetPvpTalentNumSlotsAtLevel(uint32 level, Classes class_) const;
    std::unordered_set<QuestLineXQuestEntry const*> const* GetQuestsForQuestLine(uint32 questLineId) const;
    std::vector<QuestPackageItemEntry const*> const* GetQuestPackageItems(uint32 questPackageID) const;
    std::vector<QuestPackageItemEntry const*> const* GetQuestPackageItemsFallback(uint32 questPackageID) const;
    uint32 GetQuestUniqueBitFlag(uint32 questId);
    std::vector<RewardPackXCurrencyTypeEntry const*> const* GetRewardPackCurrencyTypesByRewardID(uint32 rewardPackID) const;
    std::vector<RewardPackXItemEntry const*> const* GetRewardPackItemsByRewardID(uint32 rewardPackID) const;
    ShapeshiftFormModelData const* GetShapeshiftFormModelData(uint8 race, uint8 gender, uint8 form) const;
    std::vector<SkillLineEntry const*> const* GetSkillLinesForParentSkill(uint32 parentSkillId) const;
    std::vector<SkillLineAbilityEntry const*> const* GetSkillLineAbilitiesBySkill(uint32 skillId) const;
    SkillRaceClassInfoEntry const* GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_);
    std::vector<SpecializationSpellsEntry const*> const* GetSpecializationSpells(uint32 specId) const;
    bool IsSpecSetMember(int32 specSetId, uint32 specId) const;
    static bool IsValidSpellFamiliyName(SpellFamilyNames family);
    std::vector<SpellProcsPerMinuteModEntry const*> GetSpellProcsPerMinuteMods(uint32 spellprocsPerMinuteId) const;
    std::vector<TalentEntry const*> const& GetTalentsByPosition(uint32 class_, uint32 tier, uint32 column) const;
    static bool IsTotemCategoryCompatibleWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId);
    bool IsToyItem(uint32 toy) const;
    std::vector<TransmogSetEntry const*> const* GetTransmogSetsForItemModifiedAppearance(uint32 itemModifiedAppearanceId) const;
    std::vector<TransmogSetItemEntry const*> const* GetTransmogSetItems(uint32 transmogSetId) const;
    static bool GetUiMapPosition(float x, float y, float z, int32 mapId, int32 areaId, int32 wmoDoodadPlacementId, int32 wmoGroupId, UiMapSystem system, bool local,
        int32* uiMapId = nullptr, DBCPosition2D* newPos = nullptr);
    void Zone2MapCoordinates(uint32 areaId, float& x, float& y) const;
    void Map2ZoneCoordinates(uint32 areaId, float& x, float& y) const;
    bool IsUiMapPhase(uint32 phaseId) const;
    WMOAreaTableEntry const* GetWMOAreaTable(int32 rootId, int32 adtId, int32 groupId) const;

private:
    friend class DB2HotfixGeneratorBase;
    void InsertNewHotfix(uint32 tableHash, uint32 recordId);
    int32 _maxHotfixId = 0;
};

#define sDB2Manager DB2Manager::Instance()

#endif
