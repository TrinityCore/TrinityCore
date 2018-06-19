--
-- Table structure for table `achievement`
--
ALTER TABLE `achievement` CHANGE `Reward` `Reward` text AFTER `Description`;

--
-- Table structure for table `area_group_member`
--
ALTER TABLE `area_group_member` CHANGE `AreaGroupID` `AreaGroupID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AreaID`;

--
-- Table structure for table `area_table`
--
ALTER TABLE `area_table`
  CHANGE `ZoneName` `ZoneName` text AFTER `ID`,
  CHANGE `AreaName` `AreaName` text AFTER `ZoneName`;

--
-- Table structure for table `artifact_appearance_set`
--
ALTER TABLE `artifact_appearance_set` CHANGE `ArtifactID` `ArtifactID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ID`;

--
-- Table structure for table `artifact_power_rank`
--
ALTER TABLE `artifact_power_rank` CHANGE `ArtifactPowerID` `ArtifactPowerID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Rank`;

--
-- Table structure for table `battle_pet_breed_state`
--
ALTER TABLE `battle_pet_breed_state` CHANGE `BreedID` `BreedID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `State`;

--
-- Table structure for table `battle_pet_species`
--
ALTER TABLE `battle_pet_species`
  CHANGE `SourceText` `SourceText` text FIRST,
  CHANGE `Description` `Description` text AFTER `SourceText`;

--
-- Table structure for table `battle_pet_species_state`
--
ALTER TABLE `battle_pet_species_state` CHANGE `SpeciesID` `SpeciesID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `State`;

--
-- Table structure for table `battlemaster_list`
--
ALTER TABLE `battlemaster_list`
  CHANGE `GameType` `GameType` text AFTER `Name`,
  CHANGE `ShortDescription` `ShortDescription` text AFTER `GameType`,
  CHANGE `LongDescription` `LongDescription` text AFTER `ShortDescription`;

--
-- Table structure for table `broadcast_text`
--
ALTER TABLE `broadcast_text`
  CHANGE `SoundID1` `SoundID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PlayerConditionID`,
  CHANGE `SoundID2` `SoundID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SoundID1`;

--
-- Table structure for table `char_start_outfit`
--
ALTER TABLE `char_start_outfit` CHANGE `RaceID` `RaceID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PetFamilyID`;

--
-- Table structure for table `chat_channels`
--
ALTER TABLE `chat_channels`
  CHANGE `Name` `Name` text AFTER `ID`,
  CHANGE `Shortcut` `Shortcut` text AFTER `Name`;

--
-- Table structure for table `chr_classes`
--
ALTER TABLE `chr_classes` ADD `StartingLevel` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LowResScreenFileDataID`;

--
--
-- Table structure for table `chr_classes_x_power_types`
--
ALTER TABLE `chr_classes_x_power_types` CHANGE `ClassID` `ClassID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PowerType`;

-- Table structure for table `chr_races`
--
ALTER TABLE `chr_races`
  CHANGE `ClientPrefix` `ClientPrefix` text FIRST,
  CHANGE `ClientFileString` `ClientFileString` text AFTER `ClientPrefix`,
  CHANGE `Name` `Name` text AFTER `ClientFileString`,
  CHANGE `NameFemale` `NameFemale` text AFTER `Name`,
  DROP `NameMale`,
  DROP `FacialHairCustomization1`,
  DROP `FacialHairCustomization2`,
  DROP `HairCustomization`,
  ADD `LowercaseName` text AFTER `NameFemale`,
  ADD `LowercaseNameFemale` text AFTER `LowercaseName`,
  ADD `StartingLevel` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LowResScreenFileDataID`,
  ADD `UIDisplayOrder` int(10) unsigned NOT NULL DEFAULT '0' AFTER `StartingLevel`,
  CHANGE `ID` `ID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CharComponentTexLayoutHiResID`,
  ADD `HeritageArmorAchievementID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HighResFemaleDisplayID`,
  ADD `MaleCorpseBonesModelFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HeritageArmorAchievementID`,
  ADD `FemaleCorpseBonesModelFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MaleCorpseBonesModelFileDataID`;

--
-- Table structure for table `chr_races_locale`
--
ALTER TABLE `chr_races_locale`
  ADD `LowercaseName_lang` text AFTER `NameFemale_lang`,
  ADD `LowercaseNameFemale_lang` text AFTER `LowercaseName_lang`,
  DROP `NameMale_lang`;

--
-- Table structure for table `chr_specialization`
--
ALTER TABLE `chr_specialization`
  CHANGE `Name` `Name` text FIRST,
  CHANGE `Name2` `Name2` text AFTER `Name`,
  CHANGE `Description` `Description` text AFTER `Name2`;

--
-- Table structure for table `creature_display_info`
--
ALTER TABLE `creature_display_info`
  CHANGE `TextureVariation1` `TextureVariation1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MountSpellVisualKitID`,
  CHANGE `TextureVariation2` `TextureVariation2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `TextureVariation1`,
  CHANGE `TextureVariation3` `TextureVariation3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `TextureVariation2`;

--
-- Table structure for table `creature_family`
--
ALTER TABLE `creature_family` CHANGE `Name` `Name` text AFTER `ID`;

--
-- Table structure for table `criteria_tree`
--
ALTER TABLE `criteria_tree` CHANGE `Description` `Description` text AFTER `ID`;

--
-- Table structure for table `currency_types`
--
ALTER TABLE `currency_types` CHANGE `Description` `Description` text AFTER `Name`;

--
-- Table structure for table `emotes`
--
ALTER TABLE `emotes` CHANGE `RaceMask` `RaceMask` bigint(20) NOT NULL DEFAULT '0' AFTER `ID`;

--
-- Table structure for table `emotes_text_sound`
--
ALTER TABLE `emotes_text_sound` CHANGE `EmotesTextId` `EmotesTextId` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SoundId`;

--
-- Table structure for table `faction`
--
ALTER TABLE `faction`
  CHANGE `ReputationRaceMask1` `ReputationRaceMask1` bigint(20) unsigned NOT NULL DEFAULT '0' FIRST,
  CHANGE `ReputationRaceMask2` `ReputationRaceMask2` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `ReputationRaceMask1`,
  CHANGE `ReputationRaceMask3` `ReputationRaceMask3` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `ReputationRaceMask2`,
  CHANGE `ReputationRaceMask4` `ReputationRaceMask4` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `ReputationRaceMask3`,
  CHANGE `Name` `Name` text AFTER `ReputationRaceMask4`,
  CHANGE `Description` `Description` text AFTER `Name`;

--
-- Table structure for table `gameobjects`
--
ALTER TABLE `gameobjects` CHANGE `Name` `Name` text FIRST;

--
-- Table structure for table `garr_building`
--
ALTER TABLE `garr_building`
  CHANGE `NameAlliance` `NameAlliance` text AFTER `ID`,
  CHANGE `NameHorde` `NameHorde` text AFTER `NameAlliance`,
  CHANGE `Description` `Description` text AFTER `NameHorde`,
  CHANGE `Tooltip` `Tooltip` text AFTER `Description`;

--
-- Table structure for table `garr_follower`
--
ALTER TABLE `garr_follower`
  CHANGE `HordeSourceText` `HordeSourceText` text FIRST,
  CHANGE `AllianceSourceText` `AllianceSourceText` text AFTER `HordeSourceText`,
  CHANGE `Name` `Name` text AFTER `AllianceSourceText`;

--
-- Table structure for table `garr_follower_x_ability`
--
ALTER TABLE `garr_follower_x_ability` CHANGE `GarrFollowerID` `GarrFollowerID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `FactionIndex`;

--
-- Table structure for table `glyph_required_spec`
--
ALTER TABLE `glyph_required_spec` CHANGE `GlyphPropertiesID` `GlyphPropertiesID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ChrSpecializationID`;

--
-- Table structure for table `heirloom`
--
ALTER TABLE `heirloom` CHANGE `SourceText` `SourceText` text FIRST;

--
-- Table structure for table `item_bonus`
--
ALTER TABLE `item_bonus` ADD `Value3` int(11) NOT NULL DEFAULT '0' AFTER `Value2`;

--
-- Table structure for table `item_bonus_tree_node`
--
ALTER TABLE `item_bonus_tree_node` CHANGE `BonusTreeID` `BonusTreeID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `BonusTreeModID`;

--
-- Table structure for table `item_child_equipment`
--
ALTER TABLE `item_child_equipment` CHANGE `ItemID` `ItemID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AltEquipmentSlot`;

--
-- Table structure for table `item_class`
--
ALTER TABLE `item_class` CHANGE `Name` `Name` text AFTER `ID`;

--
-- Table structure for table `item_disenchant_loot`
--
ALTER TABLE `item_disenchant_loot`
  ADD `Expansion` tinyint(4) NOT NULL DEFAULT '0' AFTER `ItemQuality`,
  CHANGE `ItemClass` `ItemClass` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Expansion`;

--
-- Table structure for table `item_effect`
--
ALTER TABLE `item_effect` CHANGE `ItemID` `ItemID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Trigger`;

--
-- Table structure for table `item_level_selector_quality`
--
ALTER TABLE `item_level_selector_quality` CHANGE `ItemLevelSelectorQualitySetID` `ItemLevelSelectorQualitySetID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Quality`;

--
-- Table structure for table `item_modified_appearance`
--
ALTER TABLE `item_modified_appearance`
  CHANGE `ID` `ID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemID`,
  CHANGE `AppearanceModID` `AppearanceModID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ID`;

--
-- Table structure for table `item_search_name`
--
ALTER TABLE `item_search_name`
  CHANGE `AllowableRace` `AllowableRace` bigint(20) unsigned NOT NULL DEFAULT '0' FIRST,
  CHANGE `Name` `Name` text AFTER `AllowableRace`,
  CHANGE `AllowableClass` `AllowableClass` int(11) NOT NULL DEFAULT '0' AFTER `RequiredReputationRank`;

--
-- Table structure for table `item_set_spell`
--
ALTER TABLE `item_set_spell` CHANGE `ItemSetID` `ItemSetID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Threshold`;

--
-- Table structure for table `item_sparse`
--
ALTER TABLE `item_sparse`
  CHANGE `AllowableRace` `AllowableRace` bigint(20) NOT NULL DEFAULT '0' AFTER `ID`,
  CHANGE `Name` `Name` text AFTER `AllowableRace`,
  CHANGE `Name2` `Name2` text AFTER `Name`,
  CHANGE `Name3` `Name3` text AFTER `Name2`,
  CHANGE `Name4` `Name4` text AFTER `Name3`,
  CHANGE `Description` `Description` text AFTER `Name4`;

--
-- Table structure for table `item_spec_override`
--
ALTER TABLE `item_spec_override` CHANGE `ItemID` `ItemID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SpecID`;

--
-- Table structure for table `item_x_bonus_tree`
--
ALTER TABLE `item_x_bonus_tree` CHANGE `ItemID` `ItemID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `BonusTreeID`;

--
-- Table structure for table `lfg_dungeons`
--
ALTER TABLE `lfg_dungeons` CHANGE `Description` `Description` text AFTER `Name`;

--
-- Table structure for table `liquid_type`
--
ALTER TABLE `liquid_type`
  CHANGE `Texture1` `Texture1` text AFTER `Name`,
  CHANGE `Texture2` `Texture2` text AFTER `Texture1`,
  CHANGE `Texture3` `Texture3` text AFTER `Texture2`,
  CHANGE `Texture4` `Texture4` text AFTER `Texture3`,
  CHANGE `Texture5` `Texture5` text AFTER `Texture4`,
  CHANGE `Texture6` `Texture6` text AFTER `Texture5`;

--
-- Table structure for table `map`
--
ALTER TABLE `map`
  CHANGE `MapName` `MapName` text AFTER `Directory`,
  CHANGE `MapDescription0` `MapDescription0` text AFTER `MapName`,
  CHANGE `MapDescription1` `MapDescription1` text AFTER `MapDescription0`,
  CHANGE `ShortDescription` `ShortDescription` text AFTER `MapDescription1`,
  CHANGE `LongDescription` `LongDescription` text AFTER `ShortDescription`;

--
-- Table structure for table `map_difficulty`
--
ALTER TABLE `map_difficulty` CHANGE `MapID` `MapID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Context`;

--
-- Table structure for table `mount`
--
ALTER TABLE `mount`
  CHANGE `Name` `Name` text FIRST,
  CHANGE `Description` `Description` text AFTER `Name`,
  CHANGE `SourceDescription` `SourceDescription` text AFTER `Description`;

--
-- Table structure for table `mount_x_display`
--
ALTER TABLE `mount_x_display` CHANGE `MountID` `MountID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PlayerConditionID`;

--
-- Table structure for table `player_condition`
--
ALTER TABLE `player_condition`
  CHANGE `RaceMask` `RaceMask` bigint(20) NOT NULL DEFAULT '0' FIRST ,
  CHANGE `FailureDescription` `FailureDescription` text AFTER `RaceMask`,
  CHANGE `Flags` `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  CHANGE `MinLevel` `MinLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  CHANGE `MaxLevel` `MaxLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinLevel`,
  CHANGE `ClassMask` `ClassMask` int(11) NOT NULL DEFAULT '0' AFTER `MaxLevel`,
  CHANGE `Gender` `Gender` tinyint(4) NOT NULL DEFAULT '0' AFTER `ClassMask`,
  CHANGE `NativeGender` `NativeGender` tinyint(4) NOT NULL DEFAULT '0' AFTER `Gender`,
  CHANGE `SkillLogic` `SkillLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `NativeGender`,
  CHANGE `LanguageID` `LanguageID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SkillLogic`,
  CHANGE `MinLanguage` `MinLanguage` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LanguageID`,
  CHANGE `MaxLanguage` `MaxLanguage` int(11) NOT NULL DEFAULT '0' AFTER `MinLanguage`,
  CHANGE `MaxFactionID` `MaxFactionID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxLanguage`,
  CHANGE `MaxReputation` `MaxReputation` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxFactionID`,
  CHANGE `ReputationLogic` `ReputationLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MaxReputation`,
  CHANGE `Unknown1` `Unknown1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ReputationLogic`,
  CHANGE `MinPVPRank` `MinPVPRank` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Unknown1`,
  CHANGE `MaxPVPRank` `MaxPVPRank` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinPVPRank`,
  CHANGE `PvpMedal` `PvpMedal` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxPVPRank`,
  CHANGE `PrevQuestLogic` `PrevQuestLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PvpMedal`,
  CHANGE `CurrQuestLogic` `CurrQuestLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PrevQuestLogic`,
  CHANGE `CurrentCompletedQuestLogic` `CurrentCompletedQuestLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrQuestLogic`,
  CHANGE `SpellLogic` `SpellLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestLogic`,
  CHANGE `ItemLogic` `ItemLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SpellLogic`,
  CHANGE `ItemFlags` `ItemFlags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ItemLogic`,
  CHANGE `AuraSpellLogic` `AuraSpellLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemFlags`,
  CHANGE `WorldStateExpressionID` `WorldStateExpressionID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AuraSpellLogic`,
  CHANGE `WeatherID` `WeatherID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `WorldStateExpressionID`,
  CHANGE `PartyStatus` `PartyStatus` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `WeatherID`,
  CHANGE `LifetimeMaxPVPRank` `LifetimeMaxPVPRank` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PartyStatus`,
  CHANGE `AchievementLogic` `AchievementLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LifetimeMaxPVPRank`,
  CHANGE `LfgLogic` `LfgLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AchievementLogic`,
  CHANGE `AreaLogic` `AreaLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LfgLogic`,
  CHANGE `CurrencyLogic` `CurrencyLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AreaLogic`,
  CHANGE `QuestKillID` `QuestKillID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyLogic`,
  CHANGE `QuestKillLogic` `QuestKillLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `QuestKillID`,
  CHANGE `MinExpansionLevel` `MinExpansionLevel` tinyint(4) NOT NULL DEFAULT '0' AFTER `QuestKillLogic`,
  CHANGE `MaxExpansionLevel` `MaxExpansionLevel` tinyint(4) NOT NULL DEFAULT '0' AFTER `MinExpansionLevel`,
  CHANGE `MinExpansionTier` `MinExpansionTier` tinyint(4) NOT NULL DEFAULT '0' AFTER `MaxExpansionLevel`,
  CHANGE `MaxExpansionTier` `MaxExpansionTier` tinyint(4) NOT NULL DEFAULT '0' AFTER `MinExpansionTier`,
  CHANGE `MinGuildLevel` `MinGuildLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxExpansionTier`,
  CHANGE `MaxGuildLevel` `MaxGuildLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinGuildLevel`,
  CHANGE `PhaseUseFlags` `PhaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxGuildLevel`,
  CHANGE `PhaseID` `PhaseID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PhaseUseFlags`,
  CHANGE `PhaseGroupID` `PhaseGroupID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PhaseID`,
  CHANGE `MinAvgItemLevel` `MinAvgItemLevel` int(11) NOT NULL DEFAULT '0' AFTER `PhaseGroupID`,
  CHANGE `MaxAvgItemLevel` `MaxAvgItemLevel` int(11) NOT NULL DEFAULT '0' AFTER `MinAvgItemLevel`,
  CHANGE `MinAvgEquippedItemLevel` `MinAvgEquippedItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxAvgItemLevel`,
  CHANGE `MaxAvgEquippedItemLevel` `MaxAvgEquippedItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinAvgEquippedItemLevel`,
  CHANGE `ChrSpecializationIndex` `ChrSpecializationIndex` tinyint(4) NOT NULL DEFAULT '0' AFTER `MaxAvgEquippedItemLevel`,
  CHANGE `ChrSpecializationRole` `ChrSpecializationRole` tinyint(4) NOT NULL DEFAULT '0' AFTER `ChrSpecializationIndex`,
  CHANGE `PowerType` `PowerType` tinyint(4) NOT NULL DEFAULT '0' AFTER `ChrSpecializationRole`,
  CHANGE `PowerTypeComp` `PowerTypeComp` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PowerType`,
  CHANGE `PowerTypeValue` `PowerTypeValue` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PowerTypeComp`,
  CHANGE `ModifierTreeID` `ModifierTreeID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PowerTypeValue`,
  CHANGE `MainHandItemSubclassMask` `MainHandItemSubclassMask` int(11) NOT NULL DEFAULT '0' AFTER `ModifierTreeID`,
  CHANGE `SkillID1` `SkillID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MainHandItemSubclassMask`,
  CHANGE `SkillID2` `SkillID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SkillID1`,
  CHANGE `SkillID3` `SkillID3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SkillID2`,
  CHANGE `SkillID4` `SkillID4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SkillID3`,
  CHANGE `MinSkill1` `MinSkill1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SkillID4`,
  CHANGE `MinSkill2` `MinSkill2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinSkill1`,
  CHANGE `MinSkill3` `MinSkill3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinSkill2`,
  CHANGE `MinSkill4` `MinSkill4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinSkill3`,
  CHANGE `MaxSkill1` `MaxSkill1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinSkill4`,
  CHANGE `MaxSkill2` `MaxSkill2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxSkill1`,
  CHANGE `MaxSkill3` `MaxSkill3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxSkill2`,
  CHANGE `MaxSkill4` `MaxSkill4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxSkill3`,
  CHANGE `MinFactionID1` `MinFactionID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MaxSkill4`,
  CHANGE `MinFactionID2` `MinFactionID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MinFactionID1`,
  CHANGE `MinFactionID3` `MinFactionID3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MinFactionID2`,
  CHANGE `MinReputation1` `MinReputation1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinFactionID3`,
  CHANGE `MinReputation2` `MinReputation2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinReputation1`,
  CHANGE `MinReputation3` `MinReputation3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinReputation2`,
  CHANGE `PrevQuestID1` `PrevQuestID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinReputation3`,
  CHANGE `PrevQuestID2` `PrevQuestID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PrevQuestID1`,
  CHANGE `PrevQuestID3` `PrevQuestID3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PrevQuestID2`,
  CHANGE `PrevQuestID4` `PrevQuestID4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PrevQuestID3`,
  CHANGE `CurrQuestID1` `CurrQuestID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PrevQuestID4`,
  CHANGE `CurrQuestID2` `CurrQuestID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrQuestID1`,
  CHANGE `CurrQuestID3` `CurrQuestID3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrQuestID2`,
  CHANGE `CurrQuestID4` `CurrQuestID4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrQuestID3`,
  CHANGE `CurrentCompletedQuestID1` `CurrentCompletedQuestID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrQuestID4`,
  CHANGE `CurrentCompletedQuestID2` `CurrentCompletedQuestID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID1`,
  CHANGE `CurrentCompletedQuestID3` `CurrentCompletedQuestID3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID2`,
  CHANGE `CurrentCompletedQuestID4` `CurrentCompletedQuestID4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID3`,
  CHANGE `SpellID1` `SpellID1` int(11) NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID4`,
  CHANGE `SpellID2` `SpellID2` int(11) NOT NULL DEFAULT '0' AFTER `SpellID1`,
  CHANGE `SpellID3` `SpellID3` int(11) NOT NULL DEFAULT '0' AFTER `SpellID2`,
  CHANGE `SpellID4` `SpellID4` int(11) NOT NULL DEFAULT '0' AFTER `SpellID3`,
  CHANGE `ItemID1` `ItemID1` int(11) NOT NULL DEFAULT '0' AFTER `SpellID4`,
  CHANGE `ItemID2` `ItemID2` int(11) NOT NULL DEFAULT '0' AFTER `ItemID1`,
  CHANGE `ItemID3` `ItemID3` int(11) NOT NULL DEFAULT '0' AFTER `ItemID2`,
  CHANGE `ItemID4` `ItemID4` int(11) NOT NULL DEFAULT '0' AFTER `ItemID3`,
  CHANGE `ItemCount1` `ItemCount1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemID4`,
  CHANGE `ItemCount2` `ItemCount2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemCount1`,
  CHANGE `ItemCount3` `ItemCount3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemCount2`,
  CHANGE `ItemCount4` `ItemCount4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemCount3`,
  CHANGE `Explored1` `Explored1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ItemCount4`,
  CHANGE `Explored2` `Explored2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Explored1`,
  CHANGE `AuraCount1` `AuraCount1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AuraSpellID4`,
  CHANGE `AuraCount2` `AuraCount2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AuraCount1`,
  CHANGE `AuraCount3` `AuraCount3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AuraCount2`,
  CHANGE `AuraCount4` `AuraCount4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AuraCount3`,
  CHANGE `LfgStatus1` `LfgStatus1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Achievement4`,
  CHANGE `LfgStatus2` `LfgStatus2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgStatus1`,
  CHANGE `LfgStatus3` `LfgStatus3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgStatus2`,
  CHANGE `LfgStatus4` `LfgStatus4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgStatus3`,
  CHANGE `LfgCompare1` `LfgCompare1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgStatus4`,
  CHANGE `LfgCompare2` `LfgCompare2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgCompare1`,
  CHANGE `LfgCompare3` `LfgCompare3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgCompare2`,
  CHANGE `LfgCompare4` `LfgCompare4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgCompare3`,
  CHANGE `LfgValue1` `LfgValue1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LfgCompare4`,
  CHANGE `LfgValue2` `LfgValue2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LfgValue1`,
  CHANGE `LfgValue3` `LfgValue3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LfgValue2`,
  CHANGE `LfgValue4` `LfgValue4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LfgValue3`,
  CHANGE `CurrencyID1` `CurrencyID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AreaID4`,
  CHANGE `CurrencyID2` `CurrencyID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyID1`,
  CHANGE `CurrencyID3` `CurrencyID3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyID2`,
  CHANGE `CurrencyID4` `CurrencyID4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyID3`,
  CHANGE `CurrencyCount1` `CurrencyCount1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyID4`,
  CHANGE `CurrencyCount2` `CurrencyCount2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyCount1`,
  CHANGE `CurrencyCount3` `CurrencyCount3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyCount2`,
  CHANGE `CurrencyCount4` `CurrencyCount4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyCount3`;

--
-- Table structure for table `prestige_level_info`
--
ALTER TABLE `prestige_level_info` CHANGE `PrestigeText` `PrestigeText` text AFTER `ID`;

--
-- Table structure for table `pvp_difficulty`
--
ALTER TABLE `pvp_difficulty` CHANGE `MapID` `MapID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxLevel`;

--
-- Table structure for table `reward_pack_x_item`
--
ALTER TABLE `reward_pack_x_item` CHANGE `RewardPackID` `RewardPackID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Amount`;

--
-- Table structure for table `sandbox_scaling`
--
DROP TABLE IF EXISTS `sandbox_scaling`;
CREATE TABLE `sandbox_scaling` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `scene_script`
--
ALTER TABLE `scene_script`
  DROP `Name`,
  DROP `Script`;

--
-- Table structure for table `scene_script_global_text`
--
DROP TABLE IF EXISTS `scene_script_global_text`;
CREATE TABLE `scene_script_global_text` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Script` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `scene_script_text`
--
DROP TABLE IF EXISTS `scene_script_text`;
CREATE TABLE `scene_script_text` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Script` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `skill_line_ability`
--
ALTER TABLE `skill_line_ability`
 CHANGE `RaceMask` `RaceMask` bigint(20) unsigned NOT NULL DEFAULT '0' FIRST,
  CHANGE `MinSkillLineRank` `MinSkillLineRank` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ClassMask`,
  CHANGE `AcquireMethod` `AcquireMethod` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinSkillLineRank`,
  CHANGE `Unknown703` `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AcquireMethod`;

--
-- Table structure for table `skill_race_class_info`
--
ALTER TABLE `skill_race_class_info` CHANGE `RaceMask` `RaceMask` bigint(20) NOT NULL DEFAULT '0' AFTER `ID`;

--
-- Table structure for table `specialization_spells`
--
ALTER TABLE `specialization_spells` CHANGE `Description` `Description` text FIRST ;

--
-- Table structure for table `spell`
--
ALTER TABLE `spell`
  CHANGE `ID` `ID` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  DROP `MiscID`,
  DROP `DescriptionVariablesID`;

--
-- Table structure for table `spell_aura_options`
--
ALTER TABLE `spell_aura_options` CHANGE `SpellID` `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ProcChance`;

--
-- Table structure for table `spell_aura_restrictions`
--
ALTER TABLE `spell_aura_restrictions` CHANGE `SpellID` `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ExcludeTargetAuraState`;

--
-- Table structure for table `spell_categories`
--
ALTER TABLE `spell_categories` CHANGE `SpellID` `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PreventionType`;

--
-- Table structure for table `spell_cooldowns`
--
ALTER TABLE `spell_cooldowns` CHANGE `SpellID` `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `DifficultyID`;

--
-- Table structure for table `spell_effect`
--
ALTER TABLE `spell_effect`
  CHANGE `EffectAura` `EffectAura` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectIndex`,
  ADD `Coefficient` float NOT NULL DEFAULT '0' AFTER `PvPMultiplier`,
  ADD `Variance` float NOT NULL DEFAULT '0' AFTER `Coefficient`,
  ADD `ResourceCoefficient` float NOT NULL DEFAULT '0' AFTER `Variance`,
  ADD `GroupSizeCoefficient` float NOT NULL DEFAULT '0' AFTER `ResourceCoefficient`,
  CHANGE `EffectSpellClassMask1` `EffectSpellClassMask1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `GroupSizeCoefficient`,
  CHANGE `EffectSpellClassMask2` `EffectSpellClassMask2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask1`,
  CHANGE `EffectSpellClassMask3` `EffectSpellClassMask3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask2`,
  CHANGE `EffectSpellClassMask4` `EffectSpellClassMask4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask3`,
  CHANGE `EffectMiscValue` `EffectMiscValue` int(11) NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask4`,
  CHANGE `EffectMiscValueB` `EffectMiscValueB` int(11) NOT NULL DEFAULT '0' AFTER `EffectMiscValue`,
  CHANGE `EffectRadiusIndex` `EffectRadiusIndex` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectMiscValueB`,
  CHANGE `EffectRadiusMaxIndex` `EffectRadiusMaxIndex` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectRadiusIndex`,
  CHANGE `ImplicitTarget1` `ImplicitTarget1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectRadiusMaxIndex`,
  CHANGE `ImplicitTarget2` `ImplicitTarget2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ImplicitTarget1`,
  CHANGE `SpellID` `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ImplicitTarget2`;

--
-- Table structure for table `spell_effect_scaling`
--
DROP TABLE `spell_effect_scaling`;

--
-- Table structure for table `spell_interrupts`
--
ALTER TABLE `spell_interrupts`
  CHANGE `DifficultyID` `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  CHANGE `InterruptFlags` `InterruptFlags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `DifficultyID`,
  CHANGE `SpellID` `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ChannelInterruptFlags2`;

--
-- Table structure for table `spell_item_enchantment`
--
ALTER TABLE `spell_item_enchantment` CHANGE `Name` `Name` text AFTER `ID`;

--
-- Table structure for table `spell_item_enchantment_condition`
--
ALTER TABLE `spell_item_enchantment_condition`
  CHANGE `LTOperand1` `LTOperand1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  CHANGE `LTOperand2` `LTOperand2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LTOperand1`,
  CHANGE `LTOperand3` `LTOperand3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LTOperand2`,
  CHANGE `LTOperand4` `LTOperand4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LTOperand3`,
  CHANGE `LTOperand5` `LTOperand5` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LTOperand4`;

--
-- Table structure for table `spell_levels`
--
ALTER TABLE `spell_levels` CHANGE `SpellID` `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MaxUsableLevel`;

--
-- Table structure for table `spell_misc`
--
ALTER TABLE `spell_misc`
  CHANGE `CastingTimeIndex` `CastingTimeIndex` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  CHANGE `DurationIndex` `DurationIndex` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CastingTimeIndex`,
  CHANGE `RangeIndex` `RangeIndex` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `DurationIndex`,
  CHANGE `SchoolMask` `SchoolMask` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RangeIndex`,
  CHANGE `IconFileDataID` `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SchoolMask`,
  CHANGE `Speed` `Speed` float NOT NULL DEFAULT '0' AFTER `IconFileDataID`,
  CHANGE `ActiveIconFileDataID` `ActiveIconFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Speed`,
  CHANGE `MultistrikeSpeedMod` `MultistrikeSpeedMod` float NOT NULL DEFAULT '0' AFTER `ActiveIconFileDataID`,
  ADD `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MultistrikeSpeedMod`,
  ADD `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AttributesExM`;

--
-- Table structure for table `spell_power`
--
ALTER TABLE `spell_power` CHANGE `SpellID` `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `UnitPowerBarID`;

--
-- Table structure for table `spell_procs_per_minute_mod`
--
ALTER TABLE `spell_procs_per_minute_mod` CHANGE `SpellProcsPerMinuteID` `SpellProcsPerMinuteID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Type`;

--
-- Table structure for table `spell_range`
--
ALTER TABLE `spell_range`
  CHANGE `DisplayName` `DisplayName` text AFTER `ID`,
  CHANGE `DisplayNameShort` `DisplayNameShort` text AFTER `DisplayName`;

--
-- Table structure for table `spell_target_restrictions`
--
ALTER TABLE `spell_target_restrictions` CHANGE `SpellID` `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MaxTargetLevel`;

--
-- Table structure for table `spell_x_spell_visual`
--
ALTER TABLE `spell_x_spell_visual` CHANGE `SpellID` `SpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Priority`;

--
-- Table structure for table `talent`
--
ALTER TABLE `talent` CHANGE `Description` `Description` text AFTER `ID`;

--
-- Table structure for table `taxi_nodes`
--
ALTER TABLE `taxi_nodes` CHANGE `Name` `Name` text AFTER `ID`;

--
-- Table structure for table `toy`
--
ALTER TABLE `toy` CHANGE `Description` `Description` text FIRST ;

--
-- Table structure for table `transport_animation`
--
ALTER TABLE `transport_animation` CHANGE `TransportID` `TransportID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SequenceID`;

--
-- Table structure for table `transport_rotation`
--
ALTER TABLE `transport_rotation` CHANGE `TransportID` `TransportID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `W`;

--
-- Table structure for table `unit_power_bar`
--
ALTER TABLE `unit_power_bar`
  CHANGE `Name` `Name` text AFTER `ID`,
  CHANGE `Cost` `Cost` text AFTER `Name`,
  CHANGE `OutOfError` `OutOfError` text AFTER `Cost`,
  CHANGE `ToolTip` `ToolTip` text AFTER `OutOfError`;

--
-- Table structure for table `wmo_area_table`
--
ALTER TABLE `wmo_area_table`
  CHANGE `AreaName` `AreaName` text FIRST,
  CHANGE `WMOID` `WMOID` smallint(6) NOT NULL DEFAULT '0' AFTER `UWZoneMusic`;

--
-- Table structure for table `world_map_overlay`
--
ALTER TABLE `world_map_overlay` CHANGE `TextureName` `TextureName` text FIRST ;

--
-- Table structure for table `world_safe_locs`
--
ALTER TABLE `world_safe_locs` CHANGE `AreaName` `AreaName` text AFTER `ID`;
