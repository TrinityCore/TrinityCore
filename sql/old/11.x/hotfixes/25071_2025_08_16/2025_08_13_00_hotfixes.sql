
ALTER TABLE `animation_data` MODIFY COLUMN `BehaviorTier` tinyint NOT NULL DEFAULT 0 AFTER `Fallback`;

DROP TABLE IF EXISTS `bank_bag_slot_prices`;

--
-- Table structure for table `bank_tab`
--
DROP TABLE IF EXISTS `bank_tab`;
CREATE TABLE `bank_tab` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Cost` bigint unsigned NOT NULL DEFAULT '0',
  `BankType` tinyint unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint NOT NULL DEFAULT '0',
  `PlayerConditionID` int NOT NULL DEFAULT '0',
  `PurchasePromptTitle` int NOT NULL DEFAULT '0',
  `PurchasePromptBody` int NOT NULL DEFAULT '0',
  `PurchasePromptConfirmation` int NOT NULL DEFAULT '0',
  `TabCleanupConfirmation` int NOT NULL DEFAULT '0',
  `TabNameEditBoxHeader` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `banned_addons` MODIFY COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `Version`;

ALTER TABLE `cfg_regions` ADD COLUMN `TimeEventRegionGroupID` int NOT NULL DEFAULT 0 AFTER `ChallengeOrigin`;

ALTER TABLE `char_titles` MODIFY COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `MaskID`;

ALTER TABLE `chr_classes`
  ADD COLUMN `StartingLevel` int NOT NULL DEFAULT 0 AFTER `Flags`,
  ADD COLUMN `HasStrengthBonus` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  ADD COLUMN `DamageBonusStat` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `RolesMask`,
  ADD COLUMN `HasRelicSlot` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `DamageBonusStat`;

ALTER TABLE `creature_family` ADD COLUMN `CategoryEnumID` int NOT NULL DEFAULT 0 AFTER `PetTalentType`;

ALTER TABLE `expected_stat` ADD COLUMN `ContentSetID` int NOT NULL DEFAULT 0 AFTER `CreatureSpellDamage`;

ALTER TABLE `item` MODIFY COLUMN `ClassID` int NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_set_spell` ADD COLUMN `TraitSubTreeID` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `SpellID`;

ALTER TABLE `map_challenge_mode`
  ADD COLUMN `FirstRewardQuestID1` int NOT NULL DEFAULT 0 AFTER `CriteriaCount3`,
  ADD COLUMN `FirstRewardQuestID2` int NOT NULL DEFAULT 0 AFTER `FirstRewardQuestID1`,
  ADD COLUMN `FirstRewardQuestID3` int NOT NULL DEFAULT 0 AFTER `FirstRewardQuestID2`,
  ADD COLUMN `FirstRewardQuestID4` int NOT NULL DEFAULT 0 AFTER `FirstRewardQuestID3`,
  ADD COLUMN `FirstRewardQuestID5` int NOT NULL DEFAULT 0 AFTER `FirstRewardQuestID4`,
  ADD COLUMN `FirstRewardQuestID6` int NOT NULL DEFAULT 0 AFTER `FirstRewardQuestID5`,
  ADD COLUMN `RewardQuestID1` int NOT NULL DEFAULT 0 AFTER `FirstRewardQuestID6`,
  ADD COLUMN `RewardQuestID2` int NOT NULL DEFAULT 0 AFTER `RewardQuestID1`,
  ADD COLUMN `RewardQuestID3` int NOT NULL DEFAULT 0 AFTER `RewardQuestID2`,
  ADD COLUMN `RewardQuestID4` int NOT NULL DEFAULT 0 AFTER `RewardQuestID3`,
  ADD COLUMN `RewardQuestID5` int NOT NULL DEFAULT 0 AFTER `RewardQuestID4`,
  ADD COLUMN `RewardQuestID6` int NOT NULL DEFAULT 0 AFTER `RewardQuestID5`;

ALTER TABLE `map_challenge_mode` MODIFY COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `MapID`;

ALTER TABLE `spell_category`
  MODIFY COLUMN `UsesPerWeek` int NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY COLUMN `MaxCharges` int NOT NULL DEFAULT 0 AFTER `UsesPerWeek`;

ALTER TABLE `spell_equipped_items` MODIFY COLUMN `EquippedItemClass` int NOT NULL DEFAULT 0 AFTER `SpellID`;

ALTER TABLE `spell_visual_kit`
  ADD COLUMN `MinimumSpellVisualDensityFilterType` int NOT NULL DEFAULT 0 AFTER `DelayMax`,
  ADD COLUMN `MinimumSpellVisualDensityFilterParam` int NOT NULL DEFAULT 0 AFTER `MinimumSpellVisualDensityFilterType`,
  ADD COLUMN `ReducedSpellVisualDensityFilterType` int NOT NULL DEFAULT 0 AFTER `MinimumSpellVisualDensityFilterParam`,
  ADD COLUMN `ReducedSpellVisualDensityFilterParam` int NOT NULL DEFAULT 0 AFTER `ReducedSpellVisualDensityFilterType`;

ALTER TABLE `unit_power_bar` MODIFY COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `BarType`;

ALTER TABLE `warband_scene`
  DROP COLUMN `Source`,
  DROP COLUMN `SourceType`;

ALTER TABLE `warband_scene_locale` DROP COLUMN `Source_lang`;

DELETE FROM `item_sparse` WHERE `ID` IN (208392,242709);
INSERT INTO `item_sparse` (`ID`, `AllowableRace`, `Description`, `Display3`, `Display2`, `Display1`, `Display`, `ExpansionID`, `DmgVariance`, `LimitCategory`, `DurationInInventory`, `QualityModifier`, `BagFamily`, `StartQuestID`, `LanguageID`, `ItemRange`, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`, `StatPercentEditor1`, `StatPercentEditor2`, `StatPercentEditor3`, `StatPercentEditor4`, `StatPercentEditor5`, `StatPercentEditor6`, `StatPercentEditor7`, `StatPercentEditor8`, `StatPercentEditor9`, `StatPercentEditor10`, `StatModifierBonusStat1`, `StatModifierBonusStat2`, `StatModifierBonusStat3`, `StatModifierBonusStat4`, `StatModifierBonusStat5`, `StatModifierBonusStat6`, `StatModifierBonusStat7`, `StatModifierBonusStat8`, `StatModifierBonusStat9`, `StatModifierBonusStat10`, `Stackable`, `MaxCount`, `MinReputation`, `RequiredAbility`, `SellPrice`, `BuyPrice`, `VendorStackCount`, `PriceVariance`, `PriceRandomValue`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `Flags5`, `FactionRelated`, `ModifiedCraftingReagentItemID`, `ContentTuningID`, `PlayerLevelToItemLevelCurveID`, `ItemNameDescriptionID`, `RequiredTransmogHoliday`, `RequiredHoliday`, `GemProperties`, `SocketMatchEnchantmentId`, `TotemCategoryID`, `InstanceBound`, `ZoneBound1`, `ZoneBound2`, `ItemSet`, `LockID`, `PageID`, `ItemDelay`, `MinFactionID`, `RequiredSkillRank`, `RequiredSkill`, `ItemLevel`, `AllowableClass`, `ArtifactID`, `SpellWeight`, `SpellWeightCategory`, `SocketType1`, `SocketType2`, `SocketType3`, `SheatheType`, `Material`, `PageMaterialID`, `Bonding`, `DamageDamageType`, `ContainerSlots`, `RequiredPVPMedal`, `RequiredPVPRank`, `RequiredLevel`, `InventoryType`, `OverallQualityID`, `VerifiedBuild`) VALUES
(208392,-1,'','','','','Account Bank Tab Bag (DNT)',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0,0,0,0,0,1,1,1.034399986267089843,0,0,67375104,268437504,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,-1,0,0,0,0,0,0,0,0,0,0,0,98,0,0,0,18,1,62493),
(242709,-1,'','','','','Character Bank Tab Bag (DNT)',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0,0,0,0,0,1,1,0.990899980068206787,0,0,67375104,268437504,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,-1,0,0,0,0,0,0,0,0,0,0,0,98,0,0,0,18,1,62493);
