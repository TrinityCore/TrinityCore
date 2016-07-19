--
-- Table structure for table `area_table`
--
ALTER TABLE `area_table` CHANGE `UWIntroMusic` `UWIntroMusic` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `LiquidTypeID4`;

--
-- Table structure for table `banned_addons`
--
DROP TABLE IF EXISTS `banned_addons`;
CREATE TABLE `banned_addons` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Version` text,
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `battlemaster_list`
--
DROP TABLE IF EXISTS `battlemaster_list`;
CREATE TABLE `battlemaster_list` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `GameType` text,
  `MapID1` smallint(6) NOT NULL DEFAULT '0',
  `MapID2` smallint(6) NOT NULL DEFAULT '0',
  `MapID3` smallint(6) NOT NULL DEFAULT '0',
  `MapID4` smallint(6) NOT NULL DEFAULT '0',
  `MapID5` smallint(6) NOT NULL DEFAULT '0',
  `MapID6` smallint(6) NOT NULL DEFAULT '0',
  `MapID7` smallint(6) NOT NULL DEFAULT '0',
  `MapID8` smallint(6) NOT NULL DEFAULT '0',
  `MapID9` smallint(6) NOT NULL DEFAULT '0',
  `MapID10` smallint(6) NOT NULL DEFAULT '0',
  `MapID11` smallint(6) NOT NULL DEFAULT '0',
  `MapID12` smallint(6) NOT NULL DEFAULT '0',
  `MapID13` smallint(6) NOT NULL DEFAULT '0',
  `MapID14` smallint(6) NOT NULL DEFAULT '0',
  `MapID15` smallint(6) NOT NULL DEFAULT '0',
  `MapID16` smallint(6) NOT NULL DEFAULT '0',
  `HolidayWorldState` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `InstanceType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GroupsAllowed` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxGroupSize` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RatedPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `battlemaster_list_locale`
--
DROP TABLE IF EXISTS `battlemaster_list_locale`;
CREATE TABLE `battlemaster_list_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `GameType_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `char_sections`
--
DROP TABLE IF EXISTS `char_sections`;
CREATE TABLE `char_sections` (
  `Id` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID1` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID2` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID3` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Race` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Gender` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GenType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Color` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `chr_classes`
--
DROP TABLE IF EXISTS `chr_classes`;
CREATE TABLE `chr_classes` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PetNameToken` text,
  `Name` text,
  `NameFemale` text,
  `NameMale` text,
  `Filename` text,
  `CreateScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `SelectScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `LowResScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CinematicSequenceID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DefaultSpec` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SpellClassSet` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AttackPowerPerStrength` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AttackPowerPerAgility` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RangedAttackPowerPerAgility` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unk1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `chr_classes_locale`
--
DROP TABLE IF EXISTS `chr_classes_locale`;
CREATE TABLE `chr_classes_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `NameFemale_lang` text,
  `NameMale_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `chr_races`
--
ALTER TABLE `chr_races` ADD `ItemAppearanceFrameRaceID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `NeutralRaceID`;

--
-- Table structure for table `creature_display_info`
--
ALTER TABLE `creature_display_info` ADD `InstanceOtherPlayerPetScale` float NOT NULL DEFAULT '0' AFTER `StateSpellVisualKitID`;

--
-- Table structure for table `creature_model_data`
--
DROP TABLE IF EXISTS `creature_model_data`;
CREATE TABLE `creature_model_data` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `ModelScale` float NOT NULL DEFAULT '0',
  `FootprintTextureLength` float NOT NULL DEFAULT '0',
  `FootprintTextureWidth` float NOT NULL DEFAULT '0',
  `FootprintParticleScale` float NOT NULL DEFAULT '0',
  `CollisionWidth` float NOT NULL DEFAULT '0',
  `CollisionHeight` float NOT NULL DEFAULT '0',
  `MountHeight` float NOT NULL DEFAULT '0',
  `GeoBoxMin1` float NOT NULL DEFAULT '0',
  `GeoBoxMin2` float NOT NULL DEFAULT '0',
  `GeoBoxMin3` float NOT NULL DEFAULT '0',
  `GeoBoxMax1` float NOT NULL DEFAULT '0',
  `GeoBoxMax2` float NOT NULL DEFAULT '0',
  `GeoBoxMax3` float NOT NULL DEFAULT '0',
  `WorldEffectScale` float NOT NULL DEFAULT '0',
  `AttachedEffectScale` float NOT NULL DEFAULT '0',
  `MissileCollisionRadius` float NOT NULL DEFAULT '0',
  `MissileCollisionPush` float NOT NULL DEFAULT '0',
  `MissileCollisionRaise` float NOT NULL DEFAULT '0',
  `OverrideLootEffectScale` float NOT NULL DEFAULT '0',
  `OverrideNameScale` float NOT NULL DEFAULT '0',
  `OverrideSelectionRadius` float NOT NULL DEFAULT '0',
  `TamedPetBaseScale` float NOT NULL DEFAULT '0',
  `HoverHeight` float NOT NULL DEFAULT '0',
  `SoundID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CreatureGeosetDataID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SizeClass` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BloodID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FootprintTextureID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FoleyMaterialID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unk700_1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Unk700_2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FootstepShakeSize` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DeathThudShakeSize` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `emotes`
--
ALTER TABLE `emotes`
  ADD `Unk703_1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EmoteFlags`,
  ADD `Unk703_2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Unk703_1`,
  CHANGE `EmoteSpecProcParam` `EmoteSpecProcParam` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AnimID`;

--
-- Table structure for table `faction`
--
DROP TABLE IF EXISTS `faction`;
CREATE TABLE `faction` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ReputationRaceMask1` int(10) unsigned NOT NULL DEFAULT '0',
  `ReputationRaceMask2` int(10) unsigned NOT NULL DEFAULT '0',
  `ReputationRaceMask3` int(10) unsigned NOT NULL DEFAULT '0',
  `ReputationRaceMask4` int(10) unsigned NOT NULL DEFAULT '0',
  `ReputationBase1` int(11) NOT NULL DEFAULT '0',
  `ReputationBase2` int(11) NOT NULL DEFAULT '0',
  `ReputationBase3` int(11) NOT NULL DEFAULT '0',
  `ReputationBase4` int(11) NOT NULL DEFAULT '0',
  `ParentFactionModIn` float NOT NULL DEFAULT '0',
  `ParentFactionModOut` float NOT NULL DEFAULT '0',
  `Name` text,
  `Description` text,
  `ReputationIndex` smallint(6) NOT NULL DEFAULT '0',
  `ReputationClassMask1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationClassMask2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationClassMask3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationClassMask4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationFlags1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationFlags2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationFlags3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ReputationFlags4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ParentFactionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ParentFactionCapIn` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ParentFactionCapOut` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Expansion` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FriendshipRepID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `faction_locale`
--
DROP TABLE IF EXISTS `faction_locale`;
CREATE TABLE `faction_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `faction_template`
--
DROP TABLE IF EXISTS `faction_template`;
CREATE TABLE `faction_template` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Faction` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enemies1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enemies2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enemies3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Enemies4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Friends1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Friends2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Friends3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Friends4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Mask` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `FriendMask` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `EnemyMask` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `garr_ability`
--
ALTER TABLE `garr_ability` CHANGE `Flags` `Flags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `IconFileDataID`;

--
-- Table structure for table `garr_ability`
--
ALTER TABLE `garr_class_spec`
  ADD `Limit` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `GarrFollItemSetID`,
  CHANGE `Unknown700` `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Limit`;

--
-- Table structure for table `garr_follower`
--
ALTER TABLE `garr_follower`
  ADD `MaxDurability` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `GarrTypeID`,
  ADD `Class` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxDurability`;

--
-- Table structure for table `garr_plot`
--
ALTER TABLE `garr_plot` CHANGE `MinCount` `MinCount` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `HordeConstructionGameObjectID`;
ALTER TABLE `garr_plot` CHANGE `MaxCount` `MaxCount` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinCount`;

--
-- Table structure for table `gem_properties`
--
ALTER TABLE `gem_properties`
  DROP `MaxCountInv`,
  DROP COLUMN `MaxCountItem`;

--
-- Table structure for table `glyph_slot`
--
ALTER TABLE `glyph_slot` MODIFY COLUMN `Tooltip` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ID`;

--
-- Table structure for table `guild_perk_spells`
--
ALTER TABLE `guild_perk_spells` DROP COLUMN `GuildLevel`;

--
-- Table structure for table `item_appearance`
--
ALTER TABLE `item_appearance` ADD COLUMN `UIOrder` int(10) unsigned NOT NULL DEFAULT '0' AFTER `IconFileDataID`;

--
-- Table structure for table `item_modified_appearance`
--
ALTER TABLE `item_modified_appearance` ADD COLUMN `SourceType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Index`;

--
-- Table structure for table `item_set`
--
ALTER TABLE `item_set` ADD COLUMN `Unknown703` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemID17`;

--
-- Table structure for table `item_sparse`
--
ALTER TABLE `item_sparse` ADD COLUMN `RequiredExpansion` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ArtifactID`;

--
-- Table structure for table `lfg_dungeons`
--
DROP TABLE IF EXISTS `lfg_dungeons`;
CREATE TABLE `lfg_dungeons` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFilename` text,
  `Description` text,
  `MaxLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TargetLevelMax` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(6) NOT NULL DEFAULT '0',
  `RandomID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ScenarioID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LastBossJournalEncounterID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BonusReputationAmount` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MentorItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TargetLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TargetLevelMin` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Faction` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Expansion` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GroupID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CountTank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CountHealer` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CountDamage` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinCountTank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinCountHealer` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinCountDamage` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SubType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MentorCharLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `lfg_dungeons_locale`
--
DROP TABLE IF EXISTS `lfg_dungeons_locale`;
CREATE TABLE `lfg_dungeons_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `light`
--
DROP TABLE IF EXISTS `light`;
CREATE TABLE `light` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `FalloffStart` float NOT NULL DEFAULT '0',
  `FalloffEnd` float NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LightParamsID8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `liquid_type`
--
DROP TABLE IF EXISTS `liquid_type`;
CREATE TABLE `liquid_type` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxDarkenDepth` float NOT NULL DEFAULT '0',
  `FogDarkenIntensity` float NOT NULL DEFAULT '0',
  `AmbDarkenIntensity` float NOT NULL DEFAULT '0',
  `DirDarkenIntensity` float NOT NULL DEFAULT '0',
  `ParticleScale` float NOT NULL DEFAULT '0',
  `Texture1` text,
  `Texture2` text,
  `Texture3` text,
  `Texture4` text,
  `Texture5` text,
  `Texture6` text,
  `Color1` int(10) unsigned NOT NULL DEFAULT '0',
  `Color2` int(10) unsigned NOT NULL DEFAULT '0',
  `Float1` float NOT NULL DEFAULT '0',
  `Float2` float NOT NULL DEFAULT '0',
  `Float3` float NOT NULL DEFAULT '0',
  `Float4` float NOT NULL DEFAULT '0',
  `Float5` float NOT NULL DEFAULT '0',
  `Float6` float NOT NULL DEFAULT '0',
  `Float7` float NOT NULL DEFAULT '0',
  `Float8` float NOT NULL DEFAULT '0',
  `Float9` float NOT NULL DEFAULT '0',
  `Float10` float NOT NULL DEFAULT '0',
  `Float11` float NOT NULL DEFAULT '0',
  `Float12` float NOT NULL DEFAULT '0',
  `Float13` float NOT NULL DEFAULT '0',
  `Float14` float NOT NULL DEFAULT '0',
  `Float15` float NOT NULL DEFAULT '0',
  `Float16` float NOT NULL DEFAULT '0',
  `Float17` float NOT NULL DEFAULT '0',
  `Float18` float NOT NULL DEFAULT '0',
  `Int1` int(10) unsigned NOT NULL DEFAULT '0',
  `Int2` int(10) unsigned NOT NULL DEFAULT '0',
  `Int3` int(10) unsigned NOT NULL DEFAULT '0',
  `Int4` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SoundID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LightID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ParticleMovement` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ParticleTexSlots` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaterialID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `DepthTexCount6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `liquid_type_locale`
--
DROP TABLE IF EXISTS `liquid_type_locale`;
CREATE TABLE `liquid_type_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `map`
--
ALTER TABLE `map` DROP `RaidOffset`;

--
-- Table structure for table `map_difficulty`
--
DROP TABLE IF EXISTS `map_difficulty`;
CREATE TABLE `map_difficulty` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Message` text,
  `Context` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RaidDurationType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LockID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemBonusTreeModID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `map_difficulty_locale`
--
DROP TABLE IF EXISTS `map_difficulty_locale`;
CREATE TABLE `map_difficulty_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Message_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `mount_capability`
--
ALTER TABLE `mount_capability` MODIFY COLUMN `RequiredAura` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`;

--
-- Table structure for table `quest_sort`
--
ALTER TABLE `quest_sort` ADD COLUMN `SortOrder` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SortName`;

--
-- Table structure for table `rand_prop_points`
--
ALTER TABLE `rand_prop_points`
  CHANGE `EpicPropertiesPoints1` `EpicPropertiesPoints1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  CHANGE `EpicPropertiesPoints2` `EpicPropertiesPoints2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EpicPropertiesPoints1`,
  CHANGE `EpicPropertiesPoints3` `EpicPropertiesPoints3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EpicPropertiesPoints2`,
  CHANGE `EpicPropertiesPoints4` `EpicPropertiesPoints4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EpicPropertiesPoints3`,
  CHANGE `EpicPropertiesPoints5` `EpicPropertiesPoints5` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EpicPropertiesPoints4`,
  CHANGE `RarePropertiesPoints1` `RarePropertiesPoints1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EpicPropertiesPoints5`,
  CHANGE `RarePropertiesPoints2` `RarePropertiesPoints2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RarePropertiesPoints1`,
  CHANGE `RarePropertiesPoints3` `RarePropertiesPoints3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RarePropertiesPoints2`,
  CHANGE `RarePropertiesPoints4` `RarePropertiesPoints4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RarePropertiesPoints3`,
  CHANGE `RarePropertiesPoints5` `RarePropertiesPoints5` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RarePropertiesPoints4`,
  CHANGE `UncommonPropertiesPoints1` `UncommonPropertiesPoints1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RarePropertiesPoints5`,
  CHANGE `UncommonPropertiesPoints2` `UncommonPropertiesPoints2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `UncommonPropertiesPoints1`,
  CHANGE `UncommonPropertiesPoints3` `UncommonPropertiesPoints3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `UncommonPropertiesPoints2`,
  CHANGE `UncommonPropertiesPoints4` `UncommonPropertiesPoints4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `UncommonPropertiesPoints3`,
  CHANGE `UncommonPropertiesPoints5` `UncommonPropertiesPoints5` int(10) unsigned NOT NULL DEFAULT '0' AFTER `UncommonPropertiesPoints4`;

--
-- Table structure for table `skill_race_class_info`
--
ALTER TABLE `skill_race_class_info` MODIFY COLUMN `ClassMask` int(11) NOT NULL DEFAULT '0' AFTER `RaceMask`;

--
-- Table structure for table `sound_kit`
--
ALTER TABLE `sound_kit`
  CHANGE `BusOverwriteID` `BusOverwriteID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SoundEntriesAdvancedID`,
  CHANGE `SoundType` `SoundType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `BusOverwriteID`;

--
-- Table structure for table `spell_category`
--
ALTER TABLE `spell_category` ADD COLUMN `Unk703`  int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ChargeRecoveryTime`;

--
-- Table structure for table `spell_item_enchantment`
--
DROP TABLE IF EXISTS `spell_item_enchantment`;
CREATE TABLE `spell_item_enchantment` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellID1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellID2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellID3` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `EffectScalingPoints1` float NOT NULL DEFAULT '0',
  `EffectScalingPoints2` float NOT NULL DEFAULT '0',
  `EffectScalingPoints3` float NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `TransmogCost` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectPointsMin1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EffectPointsMin2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EffectPointsMin3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemVisual` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Charges` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Effect1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Effect2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Effect3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ConditionID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ScalingClass` tinyint(4) NOT NULL DEFAULT '0',
  `ScalingClassRestricted` tinyint(4) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_item_enchantment_locale`
--
DROP TABLE IF EXISTS `spell_item_enchantment_locale`;
CREATE TABLE `spell_item_enchantment_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_scaling`
--
ALTER TABLE `spell_scaling` ADD COLUMN `MinScalingLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `ScalingClass`;

--
-- Table structure for table `talent`
--
DROP TABLE IF EXISTS `talent`;
CREATE TABLE `talent` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `SpecID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `TierID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ColumnIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CategoryMask1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `CategoryMask2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `talent_locale`
--
DROP TABLE IF EXISTS `talent_locale`;
CREATE TABLE `talent_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `vehicle`
--
DROP TABLE IF EXISTS `vehicle`;
CREATE TABLE `vehicle` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `TurnSpeed` float NOT NULL DEFAULT '0',
  `PitchSpeed` float NOT NULL DEFAULT '0',
  `PitchMin` float NOT NULL DEFAULT '0',
  `PitchMax` float NOT NULL DEFAULT '0',
  `MouseLookOffsetPitch` float NOT NULL DEFAULT '0',
  `CameraFadeDistScalarMin` float NOT NULL DEFAULT '0',
  `CameraFadeDistScalarMax` float NOT NULL DEFAULT '0',
  `CameraPitchOffset` float NOT NULL DEFAULT '0',
  `FacingLimitRight` float NOT NULL DEFAULT '0',
  `FacingLimitLeft` float NOT NULL DEFAULT '0',
  `MsslTrgtTurnLingering` float NOT NULL DEFAULT '0',
  `MsslTrgtPitchLingering` float NOT NULL DEFAULT '0',
  `MsslTrgtMouseLingering` float NOT NULL DEFAULT '0',
  `MsslTrgtEndOpacity` float NOT NULL DEFAULT '0',
  `MsslTrgtArcSpeed` float NOT NULL DEFAULT '0',
  `MsslTrgtArcRepeat` float NOT NULL DEFAULT '0',
  `MsslTrgtArcWidth` float NOT NULL DEFAULT '0',
  `MsslTrgtImpactRadius1` float NOT NULL DEFAULT '0',
  `MsslTrgtImpactRadius2` float NOT NULL DEFAULT '0',
  `MsslTrgtArcTexture` text,
  `MsslTrgtImpactTexture` text,
  `MsslTrgtImpactModel1` text,
  `MsslTrgtImpactModel2` text,
  `CameraYawOffset` float NOT NULL DEFAULT '0',
  `MsslTrgtImpactTexRadius` float NOT NULL DEFAULT '0',
  `SeatID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SeatID8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VehicleUIIndicatorID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PowerDisplayID1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PowerDisplayID2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PowerDisplayID3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FlagsB` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UILocomotionType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `vehicle_seat`
--
ALTER TABLE `vehicle_seat`
  CHANGE `EnterUISoundID` `EnterUISoundID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `VehicleExitAnimDelay`,
  CHANGE `ExitUISoundID` `ExitUISoundID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EnterUISoundID`;

--
-- Table structure for table `wmo_area_table`
--
DROP TABLE IF EXISTS `wmo_area_table`;
CREATE TABLE `wmo_area_table` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `WMOGroupID` int(11) NOT NULL DEFAULT '0',
  `AreaName` text,
  `WMOID` smallint(6) NOT NULL DEFAULT '0',
  `AmbienceID` int(10) unsigned NOT NULL DEFAULT '0',
  `ZoneMusic` int(10) unsigned NOT NULL DEFAULT '0',
  `IntroSound` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaTableID` int(10) unsigned NOT NULL DEFAULT '0',
  `UWIntroSound` int(10) unsigned NOT NULL DEFAULT '0',
  `UWAmbience` int(10) unsigned NOT NULL DEFAULT '0',
  `NameSet` tinyint(4) NOT NULL DEFAULT '0',
  `SoundProviderPref` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `SoundProviderPrefUnderwater` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UWZoneMusic` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `wmo_area_table_locale`
--
DROP TABLE IF EXISTS `wmo_area_table_locale`;
CREATE TABLE `wmo_area_table_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `AreaName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `world_map_area`
--
DROP TABLE IF EXISTS `world_map_area`;
CREATE TABLE `world_map_area` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaName` text,
  `LocLeft` float NOT NULL DEFAULT '0',
  `LocRight` float NOT NULL DEFAULT '0',
  `LocTop` float NOT NULL DEFAULT '0',
  `LocBottom` float NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AreaID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DisplayMapID` smallint(6) NOT NULL DEFAULT '0',
  `DefaultDungeonFloor` smallint(6) NOT NULL DEFAULT '0',
  `ParentWorldMapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LevelRangeMin` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LevelRangeMax` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BountySetID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BountyBoardLocation` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `world_map_overlay`
--
ALTER TABLE `world_map_overlay` ADD `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PlayerConditionID`;

--
-- Table structure for table `world_safe_locs`
--
DROP TABLE IF EXISTS `world_safe_locs`;
CREATE TABLE `world_safe_locs` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `LocX` float NOT NULL DEFAULT '0',
  `LocY` float NOT NULL DEFAULT '0',
  `LocZ` float NOT NULL DEFAULT '0',
  `Facing` float NOT NULL DEFAULT '0',
  `AreaName` text,
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `world_safe_locs_locale`
--
DROP TABLE IF EXISTS `world_safe_locs_locale`;
CREATE TABLE `world_safe_locs_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `AreaName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE `game_tables`;
DROP TABLE `game_tables_locale`;
DROP TABLE `item_to_battle_pet_species`;
