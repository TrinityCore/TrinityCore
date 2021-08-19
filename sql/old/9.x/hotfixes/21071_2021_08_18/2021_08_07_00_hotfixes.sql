ALTER TABLE `azerite_essence` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `barber_shop_style` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `battle_pet_breed_quality` MODIFY `QualityEnum` tinyint(11) NOT NULL DEFAULT '0' AFTER `StateMultiplier`;

ALTER TABLE `battle_pet_species` MODIFY `PetTypeEnum` tinyint(11) NOT NULL DEFAULT '0' AFTER `IconFileDataID`;

ALTER TABLE `character_loadout` ADD `Unused910` tinyint(11) NOT NULL DEFAULT '0' AFTER `Purpose`;
ALTER TABLE `character_loadout` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `chat_channels` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `chr_customization_choice` MODIFY `SwatchColor1` int(11) NOT NULL DEFAULT '0' AFTER `Flags`;
ALTER TABLE `chr_customization_choice` MODIFY `SwatchColor2` int(11) NOT NULL DEFAULT '0' AFTER `SwatchColor1`;

ALTER TABLE `chr_model` ADD `BarberShopCameraHeightOffsetScale` float NOT NULL DEFAULT '0' AFTER `BarberShopCameraOffsetScale`;

ALTER TABLE `chr_races` ADD `Unknown910_11` float NOT NULL DEFAULT '0' AFTER `AlteredFormCustomizeRotationFallback`;
ALTER TABLE `chr_races` ADD `Unknown910_12` float NOT NULL DEFAULT '0' AFTER `Unknown910_11`;
ALTER TABLE `chr_races` ADD `Unknown910_13` float NOT NULL DEFAULT '0' AFTER `Unknown910_12`;
ALTER TABLE `chr_races` ADD `Unknown910_21` float NOT NULL DEFAULT '0' AFTER `Unknown910_13`;
ALTER TABLE `chr_races` ADD `Unknown910_22` float NOT NULL DEFAULT '0' AFTER `Unknown910_21`;
ALTER TABLE `chr_races` ADD `Unknown910_23` float NOT NULL DEFAULT '0' AFTER `Unknown910_22`;
ALTER TABLE `chr_races` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;
ALTER TABLE `chr_races` MODIFY `FactionID` int(11) NOT NULL DEFAULT '0' AFTER `Flags`;
ALTER TABLE `chr_races` MODIFY `CinematicSequenceID` int(11) NOT NULL DEFAULT '0' AFTER `FactionID`;
ALTER TABLE `chr_races` MODIFY `Alliance` int(11) NOT NULL DEFAULT '0' AFTER `SplashSoundID`;
ALTER TABLE `chr_races` MODIFY `RaceRelated` int(11) NOT NULL DEFAULT '0' AFTER `Alliance`;
ALTER TABLE `chr_races` MODIFY `UnalteredVisualRaceID` int(11) NOT NULL DEFAULT '0' AFTER `RaceRelated`;
ALTER TABLE `chr_races` MODIFY `DefaultClassID` int(11) NOT NULL DEFAULT '0' AFTER `UnalteredVisualRaceID`;
ALTER TABLE `chr_races` MODIFY `NeutralRaceID` int(11) NOT NULL DEFAULT '0' AFTER `SelectScreenFileDataID`;
ALTER TABLE `chr_races` MODIFY `AlteredFormStartVisualKitID1` int(11) NOT NULL DEFAULT '0' AFTER `LowResScreenFileDataID`;
ALTER TABLE `chr_races` MODIFY `AlteredFormStartVisualKitID2` int(11) NOT NULL DEFAULT '0' AFTER `AlteredFormStartVisualKitID1`;
ALTER TABLE `chr_races` MODIFY `AlteredFormStartVisualKitID3` int(11) NOT NULL DEFAULT '0' AFTER `AlteredFormStartVisualKitID2`;
ALTER TABLE `chr_races` MODIFY `AlteredFormFinishVisualKitID1` int(11) NOT NULL DEFAULT '0' AFTER `AlteredFormStartVisualKitID3`;
ALTER TABLE `chr_races` MODIFY `AlteredFormFinishVisualKitID2` int(11) NOT NULL DEFAULT '0' AFTER `AlteredFormFinishVisualKitID1`;
ALTER TABLE `chr_races` MODIFY `AlteredFormFinishVisualKitID3` int(11) NOT NULL DEFAULT '0' AFTER `AlteredFormFinishVisualKitID2`;
ALTER TABLE `chr_races` MODIFY `MaleModelFallbackRaceID` int(11) NOT NULL DEFAULT '0' AFTER `UiDisplayOrder`;
ALTER TABLE `chr_races` MODIFY `FemaleModelFallbackRaceID` int(11) NOT NULL DEFAULT '0' AFTER `MaleModelFallbackRaceID`;
ALTER TABLE `chr_races` MODIFY `MaleTextureFallbackRaceID` int(11) NOT NULL DEFAULT '0' AFTER `FemaleModelFallbackRaceID`;
ALTER TABLE `chr_races` MODIFY `FemaleTextureFallbackRaceID` int(11) NOT NULL DEFAULT '0' AFTER `MaleTextureFallbackRaceID`;
ALTER TABLE `chr_races` MODIFY `PlayableRaceBit` int(11) NOT NULL DEFAULT '0' AFTER `FemaleTextureFallbackRaceID`;
ALTER TABLE `chr_races` MODIFY `UnalteredVisualCustomizationRaceID` int(11) NOT NULL DEFAULT '0' AFTER `TransmogrifyDisabledSlotMask`;
ALTER TABLE `chr_races` MODIFY `BaseLanguage` tinyint(11) NOT NULL DEFAULT '0' AFTER `Unknown910_23`;

ALTER TABLE `content_tuning_x_expected` ADD `MinMythicPlusSeasonID` int(11) NOT NULL DEFAULT '0' AFTER `ExpectedStatModID`;
ALTER TABLE `content_tuning_x_expected` ADD `MaxMythicPlusSeasonID` int(11) NOT NULL DEFAULT '0' AFTER `MinMythicPlusSeasonID`;
ALTER TABLE `content_tuning_x_expected` DROP `MythicPlusSeasonID`;

ALTER TABLE `dungeon_encounter` MODIFY `Flags` int(11) NOT NULL DEFAULT '0' AFTER `CreatureDisplayID`;

ALTER TABLE `faction` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `garr_ability` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `garr_class_spec` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `garr_follower` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `item_effect` DROP `ParentItemID`;

ALTER TABLE `item_search_name` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;
ALTER TABLE `item_search_name` MODIFY `ExpansionID` int(11) NOT NULL DEFAULT '0' AFTER `OverallQualityID`;

ALTER TABLE `item_sparse` MODIFY `ExpansionID` int(11) NOT NULL DEFAULT '0' AFTER `Display`;
ALTER TABLE `item_sparse` MODIFY `InstanceBound` int(11) NOT NULL DEFAULT '0' AFTER `DmgVariance`;

CREATE TABLE `item_x_item_effect`  (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemEffectID` int(11) NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`, `VerifiedBuild`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

ALTER TABLE `languages` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `map` DROP `InternalName`;

ALTER TABLE `modifier_tree` MODIFY `TertiaryAsset` int(11) NOT NULL DEFAULT '0' AFTER `SecondaryAsset`;

ALTER TABLE `paragon_reputation` MODIFY `FactionID` int(11) NOT NULL DEFAULT '0' AFTER `ID`;

ALTER TABLE `player_condition` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `rand_prop_points` MODIFY `GoodF4` float NOT NULL DEFAULT '0' AFTER `GoodF3`;
ALTER TABLE `rand_prop_points` MODIFY `GoodF5` float NOT NULL DEFAULT '0' AFTER `GoodF4`;
ALTER TABLE `rand_prop_points` MODIFY `Epic1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `GoodF5`;
ALTER TABLE `rand_prop_points` MODIFY `Epic2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Epic1`;
ALTER TABLE `rand_prop_points` MODIFY `Epic3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Epic2`;
ALTER TABLE `rand_prop_points` MODIFY `Epic4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Epic3`;
ALTER TABLE `rand_prop_points` MODIFY `Epic5` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Epic4`;

ALTER TABLE `spell_effect` ADD `ScalingClass` int(11) NOT NULL DEFAULT '0' AFTER `EffectBasePoints`;

ALTER TABLE `spell_item_enchantment` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;
ALTER TABLE `spell_item_enchantment` MODIFY `TransmogCost` int(10) unsigned NOT NULL DEFAULT '0' AFTER `TransmogUseConditionID`;

ALTER TABLE `spell_scaling` DROP `Class`;

ALTER TABLE `spell_x_spell_visual` MODIFY `Priority` int(11) NOT NULL DEFAULT '0' AFTER `Probability`;

ALTER TABLE `transmog_set_group` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST;
