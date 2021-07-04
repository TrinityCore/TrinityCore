ALTER TABLE `achievement` ADD `CovenantID` int(11) NOT NULL DEFAULT '0' AFTER `SharesCriteria`;

ALTER TABLE `area_table` ADD `ContentTuningID` int(11) NOT NULL DEFAULT '0' AFTER `WindSettingsID`;
ALTER TABLE `area_table` DROP `ExplorationLevel`;

ALTER TABLE `battle_pet_breed_state` MODIFY `BattlePetStateID` int(11) NOT NULL DEFAULT '0' AFTER `ID`;

ALTER TABLE `battle_pet_species` ADD `CovenantID` int(11) NOT NULL DEFAULT '0' AFTER `LoadoutUIModelSceneID`;

ALTER TABLE `battlemaster_list` MODIFY `Flags` int(11) NOT NULL DEFAULT '0' AFTER `HolidayWorldState`;
ALTER TABLE `battlemaster_list` MODIFY `RequiredPlayerConditionID` int(11) NOT NULL DEFAULT '0' AFTER `IconFileDataID`;

ALTER TABLE `broadcast_text` MODIFY `LanguageID` int(11) NOT NULL DEFAULT '0' AFTER `ID`;

--
-- Table structure for table `character_loadout`
--
DROP TABLE IF EXISTS `character_loadout`;
CREATE TABLE `character_loadout` (
  `RaceMask` bigint(20) NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ChrClassID` tinyint(4) NOT NULL DEFAULT '0',
  `Purpose` tinyint(4) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `character_loadout_item`
--
DROP TABLE IF EXISTS `character_loadout_item`;
CREATE TABLE `character_loadout_item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CharacterLoadoutID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `chat_channels` ADD `Ruleset` int(11) NOT NULL DEFAULT '0' AFTER `FactionGroup`;
ALTER TABLE `chat_channels` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Shortcut`;

ALTER TABLE `chr_classes`
  ADD `Description` text AFTER `PetNameToken`,
  ADD `RoleInfoString` text AFTER `Description`,
  ADD `DisabledString` text AFTER `RoleInfoString`,
  ADD `HyphenatedNameMale` text AFTER `DisabledString`,
  ADD `HyphenatedNameFemale` text AFTER `HyphenatedNameMale`,
  ADD `RolesMask` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SpellTextureBlobFileDataID`,
  ADD `ArmorTypeMask` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RolesMask`,
  ADD `CharStartKitUnknown901` int(11) NOT NULL DEFAULT '0' AFTER `ArmorTypeMask`,
  ADD `MaleCharacterCreationVisualFallback` int(11) NOT NULL DEFAULT '0' AFTER `CharStartKitUnknown901`,
  ADD `MaleCharacterCreationIdleVisualFallback` int(11) NOT NULL DEFAULT '0' AFTER `MaleCharacterCreationVisualFallback`,
  ADD `FemaleCharacterCreationVisualFallback` int(11) NOT NULL DEFAULT '0' AFTER `MaleCharacterCreationIdleVisualFallback`,
  ADD `FemaleCharacterCreationIdleVisualFallback` int(11) NOT NULL DEFAULT '0' AFTER `FemaleCharacterCreationVisualFallback`,
  ADD `CharacterCreationIdleGroundVisualFallback` int(11) NOT NULL DEFAULT '0' AFTER `FemaleCharacterCreationIdleVisualFallback`,
  ADD `CharacterCreationGroundVisualFallback` int(11) NOT NULL DEFAULT '0' AFTER `CharacterCreationIdleGroundVisualFallback`,
  ADD `AlteredFormCharacterCreationIdleVisualFallback` int(11) NOT NULL DEFAULT '0' AFTER `CharacterCreationGroundVisualFallback`,
  ADD `CharacterCreationAnimLoopWaitTimeMsFallback` int(11) NOT NULL DEFAULT '0' AFTER `AlteredFormCharacterCreationIdleVisualFallback`,
  ADD `ChatColorR` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SpellClassSet`,
  ADD `ChatColorG` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ChatColorR`,
  ADD `ChatColorB` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ChatColorG`;

ALTER TABLE `chr_classes` MODIFY `Flags` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LowResScreenFileDataID`;
ALTER TABLE `chr_classes` DROP `StartingLevel`;

ALTER TABLE `chr_classes_locale`
  ADD `Description_lang` text AFTER `NameFemale_lang`,
  ADD `RoleInfoString_lang` text AFTER `Description_lang`,
  ADD `DisabledString_lang` text AFTER `RoleInfoString_lang`,
  ADD `HyphenatedNameMale_lang` text AFTER `DisabledString_lang`,
  ADD `HyphenatedNameFemale_lang` text AFTER `HyphenatedNameMale_lang`;

--
-- Table structure for table `chr_customization_choice`
--
DROP TABLE IF EXISTS `chr_customization_choice`;
CREATE TABLE `chr_customization_choice` (
  `Name` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ChrCustomizationOptionID` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationReqID` int(11) NOT NULL DEFAULT '0',
  `SortOrder` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SwatchColor1` int(11) NOT NULL DEFAULT '0',
  `SwatchColor2` int(11) NOT NULL DEFAULT '0',
  `UiOrderIndex` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `chr_customization_choice_locale`
--
DROP TABLE IF EXISTS `chr_customization_choice_locale`;
CREATE TABLE `chr_customization_choice_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
/*!50500 PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB) */;

--
-- Table structure for table `chr_customization_display_info`
--
DROP TABLE IF EXISTS `chr_customization_display_info`;
CREATE TABLE `chr_customization_display_info` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ShapeshiftFormID` int(11) NOT NULL DEFAULT '0',
  `DisplayID` int(11) NOT NULL DEFAULT '0',
  `BarberShopMinCameraDistance` float NOT NULL DEFAULT '0',
  `BarberShopHeightOffset` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `chr_customization_element`
--
DROP TABLE IF EXISTS `chr_customization_element`;
CREATE TABLE `chr_customization_element` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ChrCustomizationChoiceID` int(11) NOT NULL DEFAULT '0',
  `RelatedChrCustomizationChoiceID` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationGeosetID` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationSkinnedModelID` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationMaterialID` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationBoneSetID` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationCondModelID` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationDisplayInfoID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `chr_customization_option`
--
DROP TABLE IF EXISTS `chr_customization_option`;
CREATE TABLE `chr_customization_option` (
  `Name` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SecondaryID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `ChrModelID` int(11) NOT NULL DEFAULT '0',
  `SortIndex` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationCategoryID` int(11) NOT NULL DEFAULT '0',
  `OptionType` int(11) NOT NULL DEFAULT '0',
  `BarberShopCostModifier` float NOT NULL DEFAULT '0',
  `ChrCustomizationID` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationReqID` int(11) NOT NULL DEFAULT '0',
  `UiOrderIndex` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `chr_customization_option_locale`
--
DROP TABLE IF EXISTS `chr_customization_option_locale`;
CREATE TABLE `chr_customization_option_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
/*!50500 PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB) */;

--
-- Table structure for table `chr_customization_req`
--
DROP TABLE IF EXISTS `chr_customization_req`;
CREATE TABLE `chr_customization_req` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `ClassMask` int(11) NOT NULL DEFAULT '0',
  `AchievementID` int(11) NOT NULL DEFAULT '0',
  `OverrideArchive` int(11) NOT NULL DEFAULT '0',
  `ItemModifiedAppearanceID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `chr_customization_req_choice`
--
DROP TABLE IF EXISTS `chr_customization_req_choice`;
CREATE TABLE `chr_customization_req_choice` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ChrCustomizationChoiceID` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationReqID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `chr_model`
--
DROP TABLE IF EXISTS `chr_model`;
CREATE TABLE `chr_model` (
  `FaceCustomizationOffset1` float NOT NULL DEFAULT '0',
  `FaceCustomizationOffset2` float NOT NULL DEFAULT '0',
  `FaceCustomizationOffset3` float NOT NULL DEFAULT '0',
  `CustomizeOffset1` float NOT NULL DEFAULT '0',
  `CustomizeOffset2` float NOT NULL DEFAULT '0',
  `CustomizeOffset3` float NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Sex` int(11) NOT NULL DEFAULT '0',
  `DisplayID` int(11) NOT NULL DEFAULT '0',
  `CharComponentTextureLayoutID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `SkeletonFileDataID` int(11) NOT NULL DEFAULT '0',
  `ModelFallbackChrModelID` int(11) NOT NULL DEFAULT '0',
  `TextureFallbackChrModelID` int(11) NOT NULL DEFAULT '0',
  `HelmVisFallbackChrModelID` int(11) NOT NULL DEFAULT '0',
  `CustomizeScale` float NOT NULL DEFAULT '0',
  `CustomizeFacing` float NOT NULL DEFAULT '0',
  `CameraDistanceOffset` float NOT NULL DEFAULT '0',
  `BarberShopCameraOffsetScale` float NOT NULL DEFAULT '0',
  `BarberShopCameraRotationOffset` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `chr_race_x_chr_model`
--
DROP TABLE IF EXISTS `chr_race_x_chr_model`;
CREATE TABLE `chr_race_x_chr_model` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ChrRacesID` int(11) NOT NULL DEFAULT '0',
  `ChrModelID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `chr_races`
  ADD `NameS` text AFTER `NameFemaleLowercase`,
  ADD `NameFemaleS` text AFTER `NameS`,
  ADD `NameLowercaseS` text AFTER `NameFemaleS`,
  ADD `NameFemaleLowercaseS` text AFTER `NameLowercaseS`,
  ADD `RaceFantasyDescription` text AFTER `NameFemaleLowercaseS`,
  ADD `NameL` text AFTER `RaceFantasyDescription`,
  ADD `NameFemaleL` text AFTER `NameL`,
  ADD `NameLowercaseL` text AFTER `NameFemaleL`,
  ADD `NameFemaleLowercaseL` text AFTER `NameLowercaseL`,
  ADD `PlayableRaceBit` int(11) NOT NULL DEFAULT '0' AFTER `UiDisplayOrder`,
  ADD `HelmetAnimScalingRaceID` int(11) NOT NULL DEFAULT '0' AFTER `PlayableRaceBit`,
  ADD `AlteredFormCustomizeOffsetFallback1` float NOT NULL DEFAULT '0' AFTER `TransmogrifyDisabledSlotMask`,
  ADD `AlteredFormCustomizeOffsetFallback2` float NOT NULL DEFAULT '0' AFTER `AlteredFormCustomizeOffsetFallback1`,
  ADD `AlteredFormCustomizeOffsetFallback3` float NOT NULL DEFAULT '0' AFTER `AlteredFormCustomizeOffsetFallback2`,
  ADD `AlteredFormCustomizeRotationFallback` float NOT NULL DEFAULT '0' AFTER `AlteredFormCustomizeOffsetFallback3`,
  ADD `UnalteredVisualCustomizationRaceID` tinyint(3) NOT NULL DEFAULT '0' AFTER `FemaleTextureFallbackSex`;

ALTER TABLE `chr_races`
  MODIFY `BaseLanguage` int(11) NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `ResSicknessSpellID` int(11) NOT NULL DEFAULT '0' AFTER `BaseLanguage`,
  MODIFY `SplashSoundID` int(11) NOT NULL DEFAULT '0' AFTER `ResSicknessSpellID`;

ALTER TABLE `chr_races`
  DROP `MaleDisplayId`,
  DROP `FemaleDisplayId`,
  DROP `HighResMaleDisplayId`,
  DROP `HighResFemaleDisplayId`,
  DROP `MaleCustomizeOffset1`,
  DROP `MaleCustomizeOffset2`,
  DROP `MaleCustomizeOffset3`,
  DROP `FemaleCustomizeOffset1`,
  DROP `FemaleCustomizeOffset2`,
  DROP `FemaleCustomizeOffset3`,
  DROP `FemaleSkeletonFileDataID`,
  DROP `MaleSkeletonFileDataID`,
  DROP `HelmVisFallbackRaceID`,
  DROP `CharComponentTextureLayoutID`,
  DROP `CharComponentTexLayoutHiResID`;

ALTER TABLE `chr_races_locale`
  ADD `NameS_lang` text AFTER `NameFemaleLowercase_lang`,
  ADD `NameFemaleS_lang` text AFTER `NameS_lang`,
  ADD `NameLowercaseS_lang` text AFTER `NameFemaleS_lang`,
  ADD `NameFemaleLowercaseS_lang` text AFTER `NameLowercaseS_lang`,
  ADD `RaceFantasyDescription_lang` text AFTER `NameFemaleLowercaseS_lang`,
  ADD `NameL_lang` text AFTER `RaceFantasyDescription_lang`,
  ADD `NameFemaleL_lang` text AFTER `NameL_lang`,
  ADD `NameLowercaseL_lang` text AFTER `NameFemaleL_lang`,
  ADD `NameFemaleLowercaseL_lang` text AFTER `NameLowercaseL_lang`;

ALTER TABLE `content_tuning`
  ADD `MinLevelType` int(11) NOT NULL DEFAULT '0' AFTER `MaxLevel`,
  ADD `MaxLevelType` int(11) NOT NULL DEFAULT '0' AFTER `MinLevelType`,
  ADD `TargetLevelDelta` int(11) NOT NULL DEFAULT '0' AFTER `MaxLevelType`,
  ADD `TargetLevelMaxDelta` int(11) NOT NULL DEFAULT '0' AFTER `TargetLevelDelta`,
  ADD `TargetLevelMin` int(11) NOT NULL DEFAULT '0' AFTER `TargetLevelMaxDelta`,
  ADD `TargetLevelMax` int(11) NOT NULL DEFAULT '0' AFTER `TargetLevelMin`,
  ADD `MinItemLevel` int(11) NOT NULL DEFAULT '0' AFTER `TargetLevelMax`;

ALTER TABLE `content_tuning`
  MODIFY `Flags` int(11) NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `ExpansionID` int(11) NOT NULL DEFAULT '0' AFTER `Flags`;

ALTER TABLE `creature_display_info_extra`
  DROP `SkinID`,
  DROP `FaceID`,
  DROP `HairStyleID`,
  DROP `HairColorID`,
  DROP `FacialHairID`,
  DROP `CustomDisplayOption1`,
  DROP `CustomDisplayOption2`,
  DROP `CustomDisplayOption3`;

ALTER TABLE `currency_types` CHANGE `ConvertToPlayerExperience` `XpQuestDifficulty` int(11) NOT NULL DEFAULT '0' AFTER `ItemGroupSoundsID`;
ALTER TABLE `currency_types` CHANGE `PlayerConditionID` `AwardConditionID` int(11) NOT NULL DEFAULT '0' AFTER `XpQuestDifficulty`;
ALTER TABLE `currency_types` ADD `MaxQtyWorldStateID` int(11) NOT NULL DEFAULT '0' AFTER `AwardConditionID`;
ALTER TABLE `currency_types` CHANGE `Flags` `Flags1` int(11) NOT NULL DEFAULT '0' AFTER `MaxQtyWorldStateID`;
ALTER TABLE `currency_types` ADD `Flags2` int(11) NOT NULL DEFAULT '0' AFTER `Flags1`;
ALTER TABLE `currency_types` MODIFY `CategoryID` int(11) NOT NULL DEFAULT '0' AFTER `Description`;

ALTER TABLE `curve_point`
  ADD `PosPreSquishX` float NOT NULL DEFAULT '0' AFTER `PosY`,
  ADD `PosPreSquishY` float NOT NULL DEFAULT '0' AFTER `PosPreSquishX`;

ALTER TABLE `destructible_model_data`
  MODIFY `State1Wmo` int(11) NOT NULL DEFAULT '0' AFTER `State0AmbientDoodadSet`,
  MODIFY `State2Wmo` int(11) NOT NULL DEFAULT '0' AFTER `State1AmbientDoodadSet`,
  MODIFY `State3Wmo` int(11) NOT NULL DEFAULT '0' AFTER `State2AmbientDoodadSet`,
  MODIFY `State0Wmo` int(11) NOT NULL DEFAULT '0' AFTER `DoNotHighlight`;

ALTER TABLE `dungeon_encounter` MODIFY `DifficultyID` int(11) NOT NULL DEFAULT '0' AFTER `MapID`;

ALTER TABLE `gameobjects`
  MODIFY `OwnerID` int(11) NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `DisplayID` int(11) NOT NULL DEFAULT '0' AFTER `OwnerID`,
  MODIFY `TypeID` int(11) NOT NULL DEFAULT '0' AFTER `Scale`,
  MODIFY `PhaseUseFlags` int(11) NOT NULL DEFAULT '0' AFTER `TypeID`,
  MODIFY `PhaseID` int(11) NOT NULL DEFAULT '0' AFTER `PhaseUseFlags`,
  MODIFY `PhaseGroupID` int(11) NOT NULL DEFAULT '0' AFTER `PhaseID`;

ALTER TABLE `garr_building` MODIFY `GarrSiteID` int(11) NOT NULL DEFAULT '0' AFTER `AllianceGameObjectID`;

ALTER TABLE `garr_follower`
  ADD `AutoCombatantID` int(11) NOT NULL DEFAULT '0' AFTER `Gender`,
  ADD `CovenantID` int(11) NOT NULL DEFAULT '0' AFTER `AutoCombatantID`;

ALTER TABLE `gem_properties` DROP `MinItemLevel`;

ALTER TABLE `item` ADD `ModifiedCraftingReagentItemID` int(11) NOT NULL DEFAULT '0' AFTER `ItemGroupSoundsID`;

ALTER TABLE `item_appearance` ADD `PlayerConditionID` int(11) NOT NULL DEFAULT '0' AFTER `UiOrder`;

ALTER TABLE `item_bonus` ADD `Value4` int(11) NOT NULL DEFAULT '0' AFTER `Value3`;

ALTER TABLE `item_sparse`
  ADD `ModifiedCraftingReagentItemID` int(11) NOT NULL DEFAULT '0' AFTER `FactionRelated`,
  ADD `ContentTuningID` int(11) NOT NULL DEFAULT '0' AFTER `ModifiedCraftingReagentItemID`,
  ADD `PlayerLevelToItemLevelCurveID` int(11) NOT NULL DEFAULT '0' AFTER `ContentTuningID`;

ALTER TABLE `item_sparse` DROP `ScalingStatDistributionID`;

ALTER TABLE `lfg_dungeons` ADD `ContentTuningID` int(11) NOT NULL DEFAULT '0' AFTER `MentorCharLevel`;

ALTER TABLE `lfg_dungeons`
  DROP `MinLevel`,
  DROP `MaxLevel`,
  DROP `TargetLevel`,
  DROP `TargetLevelMin`,
  DROP `TargetLevelMax`;

ALTER TABLE `lock` ADD `Flags` int(11) NOT NULL DEFAULT '0' AFTER `ID`;

ALTER TABLE `map` ADD `InternalName` text AFTER `MapName`;

ALTER TABLE `player_condition`
  ADD `ContentTuningID` int(11) NOT NULL DEFAULT '0' AFTER `MaxPVPRank`,
  ADD `CovenantID` int(11) NOT NULL DEFAULT '0' AFTER `ContentTuningID`;

ALTER TABLE `player_condition`
  MODIFY `LanguageID` int(11) NOT NULL DEFAULT '0' AFTER `SkillLogic`,
  MODIFY `WeatherID` int(11) NOT NULL DEFAULT '0' AFTER `WorldStateExpressionID`,
  MODIFY `QuestKillID` int(11) NOT NULL DEFAULT '0' AFTER `CurrencyLogic`,
  MODIFY `Flags` int(11) NOT NULL DEFAULT '0' AFTER `PhaseGroupID`,
  MODIFY `PrevQuestID1` int(11) NOT NULL DEFAULT '0' AFTER `MinReputation3`,
  MODIFY `PrevQuestID2` int(11) NOT NULL DEFAULT '0' AFTER `PrevQuestID1`,
  MODIFY `PrevQuestID3` int(11) NOT NULL DEFAULT '0' AFTER `PrevQuestID2`,
  MODIFY `PrevQuestID4` int(11) NOT NULL DEFAULT '0' AFTER `PrevQuestID3`,
  MODIFY `CurrQuestID1` int(11) NOT NULL DEFAULT '0' AFTER `PrevQuestID4`,
  MODIFY `CurrQuestID2` int(11) NOT NULL DEFAULT '0' AFTER `CurrQuestID1`,
  MODIFY `CurrQuestID3` int(11) NOT NULL DEFAULT '0' AFTER `CurrQuestID2`,
  MODIFY `CurrQuestID4` int(11) NOT NULL DEFAULT '0' AFTER `CurrQuestID3`,
  MODIFY `CurrentCompletedQuestID1` int(11) NOT NULL DEFAULT '0' AFTER `CurrQuestID4`,
  MODIFY `CurrentCompletedQuestID2` int(11) NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID1`,
  MODIFY `CurrentCompletedQuestID3` int(11) NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID2`,
  MODIFY `CurrentCompletedQuestID4` int(11) NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID3`;

ALTER TABLE `player_condition`
  DROP `MinLevel`,
  DROP `MaxLevel`;

ALTER TABLE `scenario_step` MODIFY `RewardQuestID` int(11) NOT NULL DEFAULT '0' AFTER `Criteriatreeid`;

ALTER TABLE `skill_line_ability` MODIFY `Flags` int(11) NOT NULL DEFAULT '0' AFTER `TrivialSkillLineRankLow`;

ALTER TABLE `spell_cast_times` DROP `PerLevel`;

ALTER TABLE `spell_duration` DROP `DurationPerLevel`;

ALTER TABLE `spell_effect` MODIFY `Effect` int(11) NOT NULL DEFAULT '0' AFTER `EffectIndex`;

ALTER TABLE `spell_item_enchantment`
  ADD `MinItemLevel` int(11) NOT NULL DEFAULT '0' AFTER `IconFileDataID`,
  ADD `MaxItemLevel` int(11) NOT NULL DEFAULT '0' AFTER `MinItemLevel`,
  ADD `TransmogUseConditionID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MaxItemLevel`;

ALTER TABLE `spell_item_enchantment`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HordeName`,
  MODIFY `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectScalingPoints3`;

ALTER TABLE `spell_item_enchantment` DROP `TransmogPlayerConditionID`;

ALTER TABLE `spell_levels`
  MODIFY `MaxPassiveAuraLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxLevel`,
  MODIFY `BaseLevel` int(11) NOT NULL DEFAULT '0' AFTER `MaxPassiveAuraLevel`,
  MODIFY `SpellLevel` int(11) NOT NULL DEFAULT '0' AFTER `BaseLevel`;

ALTER TABLE `spell_misc`
  ADD `Attributes15` int(11) NOT NULL DEFAULT '0' AFTER `Attributes14`,
  ADD `ShowFutureSpellPlayerConditionID` int(11) NOT NULL DEFAULT '0' AFTER `ContentTuningID`,
  ADD `SpellVisualScript` int(11) NOT NULL DEFAULT '0' AFTER `ShowFutureSpellPlayerConditionID`,
  ADD `ActiveSpellVisualScript` int(11) NOT NULL DEFAULT '0' AFTER `SpellVisualScript`;

ALTER TABLE `spell_procs_per_minute_mod` MODIFY `Param` int(11) NOT NULL DEFAULT '0' AFTER `Type`;

ALTER TABLE `spell_x_spell_visual` DROP `Flags`;

--
-- Table structure for table `transmog_illusion`
--
DROP TABLE IF EXISTS `transmog_illusion`;
CREATE TABLE `transmog_illusion` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `UnlockConditionID` int(11) NOT NULL DEFAULT '0',
  `TransmogCost` int(11) NOT NULL DEFAULT '0',
  `SpellItemEnchantmentID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `ui_map` ADD `ContentTuningID` int(11) NOT NULL DEFAULT '0' AFTER `AlternateUiMapGroup`;

ALTER TABLE `ui_map`
  DROP `LevelRangeMin`,
  DROP `LevelRangeMax`;

ALTER TABLE `ui_map_link` ADD `Flags` int(11) NOT NULL DEFAULT '0' AFTER `OverrideHighlightAtlasID`;

ALTER TABLE `vehicle` ADD `VehiclePOITypeID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MissileTargetingID`;
ALTER TABLE `vehicle` DROP `UiLocomotionType`;

DROP TABLE `char_base_section`;

DROP TABLE `char_sections`;

DROP TABLE `char_start_outfit`;

DROP TABLE `character_facial_hair_styles`;

DROP TABLE `scaling_stat_distribution`;
