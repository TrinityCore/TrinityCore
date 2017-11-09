--
-- Table structure for table `achievement`
--
ALTER TABLE `achievement`
  ADD `IconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`,
  DROP `IconID`;

--
-- Table structure for table `artifact`
--
ALTER TABLE `artifact`
  ADD `UiModelSceneID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Flags`,
  ADD `SpellVisualKitID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `UiModelSceneID`;

--
-- Table structure for table `artifact_appearance`
--
ALTER TABLE `artifact_appearance` MODIFY `PlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`;

--
-- Table structure for table `artifact_power`
--
ALTER TABLE `artifact_power` ADD `ArtifactTier` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `MaxRank`;

--
-- Table structure for table `battlemaster_list`
--
ALTER TABLE `battlemaster_list`
  ADD `ShortDescription` text NULL AFTER `GameType`,
  ADD `LongDescription` text NULL AFTER `ShortDescription`;

--
-- Table structure for table `battlemaster_list_locale`
--
ALTER TABLE `battlemaster_list_locale`
  ADD `ShortDescription_lang` text NULL AFTER `GameType_lang`,
  ADD `LongDescription_lang` text NULL AFTER `ShortDescription_lang`;

--
-- Table structure for table `battle_pet_species`
--
ALTER TABLE `battle_pet_species`
  ADD `CardModelSceneID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`,
  ADD `LoadoutModelSceneID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CardModelSceneID`;

--
-- Table structure for table `chr_races`
--
ALTER TABLE `chr_races`
  DROP `ExplorationSoundID`,
  DROP `UAMaleCreatureSoundDataID`,
  DROP `UAFemaleCreatureSoundDataID`;

--
-- Table structure for table `chr_specialization`
--
ALTER TABLE `chr_specialization`
  ADD `IconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`,
  DROP `SpellIconID`;

--
-- Table structure for table `cinematic_camera`
--
ALTER TABLE `cinematic_camera`
  MODIFY `SoundID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`,
  ADD `ModelFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `OriginFacing`,
  DROP `Model`;

--
-- Table structure for table `cinematic_sequences`
--
ALTER TABLE `cinematic_sequences` MODIFY `SoundID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`;

--
-- Table structure for table `creature_display_info`
--
ALTER TABLE `creature_display_info`
  MODIFY `CreatureModelScale` float NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `ModelID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CreatureModelScale`,
  MODIFY `NPCSoundID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ModelID`,
  MODIFY `SizeClass` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `NPCSoundID`,
  MODIFY `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `SizeClass`,
  MODIFY `Gender` tinyint(4) NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `TextureVariation1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ExtendedDisplayInfoID`,
  MODIFY `TextureVariation2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `TextureVariation1`,
  MODIFY `TextureVariation3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `TextureVariation2`,
  ADD `PortraitTextureFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `TextureVariation3`,
  MODIFY `CreatureModelAlpha` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `PortraitTextureFileDataID`,
  MODIFY `SoundID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CreatureModelAlpha`,
  MODIFY `BloodID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `PortraitCreatureDisplayInfoID`,
  MODIFY `ParticleColorID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `BloodID`,
  MODIFY `ObjectEffectPackageID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CreatureGeosetData`,
  MODIFY `AnimReplacementSetID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ObjectEffectPackageID`,
  CHANGE `Unk700` `UnarmedWeaponSubclass` tinyint(4) NOT NULL DEFAULT '0' AFTER `AnimReplacementSetID`,
  ADD `MountSpellVisualKitID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `InstanceOtherPlayerPetScale`,
  DROP `PortraitTextureName`;

--
-- Table structure for table `creature_family`
--
ALTER TABLE `creature_family`
  ADD `IconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Name`,
  DROP `IconFile`;

--
-- Table structure for table `criteria_tree`
--
ALTER TABLE `criteria_tree` MODIFY `CriteriaID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Operator`;

--
-- Table structure for table `difficulty`
--
ALTER TABLE `difficulty`
  MODIFY `GroupSizeHealthCurveID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Name`,
  MODIFY `GroupSizeDmgCurveID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `GroupSizeHealthCurveID`,
  MODIFY `GroupSizeSpellPointsCurveID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `GroupSizeDmgCurveID`;

--
-- Table structure for table `dungeon_encounter`
--
ALTER TABLE `dungeon_encounter`
  DROP `SpellIconID`,
  MODIFY `ID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Flags`,
  ADD `TextureFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `OrderIndex`;

--
-- Table structure for table `faction`
--
ALTER TABLE `faction` ADD `ParagonFactionID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ParentFactionID`;

--
-- Table structure for table `garr_class_spec`
--
ALTER TABLE `garr_class_spec` MODIFY `GarrFollItemSetID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ClassAtlasID`;

--
-- Table structure for table `garr_follower`
--
ALTER TABLE `garr_follower` ADD `Name` text NULL AFTER `AllianceAddedBroadcastTextID`;

--
-- Table structure for table `garr_follower_locale`
--
ALTER TABLE `garr_follower_locale` ADD `Name_lang` text NULL AFTER `AllianceSourceText_lang`;

--
-- Table structure for table `garr_site_level`
--
ALTER TABLE `garr_site_level` MODIFY `MovieID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `SiteID`;

--
-- Table structure for table `holidays`
--
ALTER TABLE `holidays`
  MODIFY `HolidayNameID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `HolidayDescriptionID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `HolidayNameID`;

--
-- Table structure for table `item_bonus_tree_node`
--
ALTER TABLE `item_bonus_tree_node` ADD `ItemLevelSelectorID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `BonusListID`;

--
-- Table structure for table `item_sparse`
--
ALTER TABLE `item_sparse`
  MODIFY `BuyCount` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Unk2`,
  MODIFY `AllowableClass` smallint(6) NOT NULL DEFAULT '0' AFTER `StatScalingFactor`,
  MODIFY `TotemCategory` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Map`,
  ADD `RequiredTransmogHolidayID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `HolidayID`;

--
-- Table structure for table `lfg_dungeons`
--
ALTER TABLE `lfg_dungeons` MODIFY `PlayerConditionID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `MentorItemLevel`;

--
-- Table structure for table `map`
--
ALTER TABLE `map`
  ADD `ShortDescription` text NULL AFTER `MapDescription1`,
  ADD `LongDescription` text NULL AFTER `ShortDescription`;

--
-- Table structure for table `map_locale`
--
ALTER TABLE `map_locale`
  ADD `ShortDescription_lang` text NULL AFTER `MapDescription1_lang`,
  ADD `LongDescription_lang` text NULL AFTER `ShortDescription_lang`;

--
-- Table structure for table `mount`
--
ALTER TABLE `mount`
  DROP `DisplayId`,
  MODIFY `PlayerConditionId` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`,
  ADD `UiModelSceneID` int(11) NOT NULL DEFAULT '0' AFTER `PlayerConditionId`;

--
-- Table structure for table `mount_x_display`
--
DROP TABLE IF EXISTS `mount_x_display`;
CREATE TABLE `mount_x_display` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MountID` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `player_condition`
--
ALTER TABLE `player_condition`
  CHANGE `Unknown7001` `MovementFlags1` int(11) NOT NULL DEFAULT '0' AFTER `MaxAvgItemLevel`,
  CHANGE `Unknown7002` `MovementFlags2` int(11) NOT NULL DEFAULT '0' AFTER `MovementFlags1`,
  ADD `MainHandItemSubclassMask` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `MovementFlags2`;

--
-- Table structure for table `quest_package_item`
--
ALTER TABLE `quest_package_item` MODIFY `ItemCount` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `FilterType`;

--
-- Table structure for table `skill_line`
--
ALTER TABLE `skill_line`
  ADD `IconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CanLink`,
  DROP `SpellIconID`;

--
-- Table structure for table `skill_line_ability`
--
ALTER TABLE `skill_line_ability` MODIFY `Unknown703` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `NumSkillUps`;

--
-- Table structure for table `spell_duration`
--
ALTER TABLE `spell_duration` MODIFY `DurationPerLevel` int(11) NOT NULL DEFAULT '0' AFTER `MaxDuration`;

--
-- Table structure for table `spell_effect`
--
ALTER TABLE `spell_effect`
  MODIFY `EffectSpellClassMask1` int(10) UNSIGNED NOT NULL DEFAULT '0' FIRST,
  MODIFY `EffectSpellClassMask2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask1`,
  MODIFY `EffectSpellClassMask3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask2`,
  MODIFY `EffectSpellClassMask4` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask3`,
  MODIFY `ID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask4`,
  MODIFY `SpellID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `Effect` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `SpellID`,
  MODIFY `EffectAura` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Effect`,
  MODIFY `EffectBasePoints` int(11) NOT NULL DEFAULT '0' AFTER `EffectAura`,
  MODIFY `EffectIndex` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectBasePoints`,
  MODIFY `EffectMiscValue` int(11) NOT NULL DEFAULT '0' AFTER `EffectIndex`,
  MODIFY `EffectMiscValueB` int(11) NOT NULL DEFAULT '0' AFTER `EffectMiscValue`,
  MODIFY `EffectRadiusIndex` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectMiscValueB`,
  MODIFY `EffectRadiusMaxIndex` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectRadiusIndex`,
  MODIFY `ImplicitTarget1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectRadiusMaxIndex`,
  MODIFY `ImplicitTarget2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ImplicitTarget1`,
  MODIFY `DifficultyID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ImplicitTarget2`,
  MODIFY `EffectAuraPeriod` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectAmplitude`,
  MODIFY `EffectChainTargets` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectChainAmplitude`,
  MODIFY `EffectDieSides` int(11) NOT NULL DEFAULT '0' AFTER `EffectChainTargets`,
  MODIFY `EffectItemType` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectDieSides`,
  MODIFY `EffectMechanic` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectItemType`,
  MODIFY `EffectTriggerSpell` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectRealPointsPerLevel`,
  MODIFY `EffectAttributes` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `EffectPosFacing`,
  ADD `PvPMultiplier` float NOT NULL DEFAULT '0' AFTER `BonusCoefficientFromAP`;

--
-- Table structure for table `spell_misc`
--
ALTER TABLE `spell_misc`
  ADD `IconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `SchoolMask`,
  ADD `ActiveIconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `IconFileDataID`,
  DROP `SpellIconID`,
  DROP `ActiveIconID`;

--
-- Table structure for table `spell_shapeshift_form`
--
ALTER TABLE `spell_shapeshift_form`
  ADD `AttackIconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `BonusActionBar`,
  MODIFY `CreatureDisplayID1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AttackIconFileDataID`,
  MODIFY `CreatureDisplayID2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CreatureDisplayID1`,
  MODIFY `CreatureDisplayID3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CreatureDisplayID2`,
  MODIFY `CreatureDisplayID4` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CreatureDisplayID3`,
  MODIFY `PresetSpellID1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CreatureDisplayID4`,
  MODIFY `PresetSpellID2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PresetSpellID1`,
  MODIFY `PresetSpellID3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PresetSpellID2`,
  MODIFY `PresetSpellID4` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PresetSpellID3`,
  MODIFY `PresetSpellID5` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PresetSpellID4`,
  MODIFY `PresetSpellID6` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PresetSpellID5`,
  MODIFY `PresetSpellID7` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PresetSpellID6`,
  MODIFY `PresetSpellID8` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PresetSpellID7`,
  DROP `AttackIconID`;

--
-- Table structure for table `spell_x_spell_visual`
--
ALTER TABLE `spell_x_spell_visual`
  CHANGE `SpellVisualID1` `SpellVisualID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `SpellID`,
  MODIFY `ID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `SpellVisualID`,
  CHANGE `PlayerConditionID` `CasterPlayerConditionID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Chance`,
  ADD `CasterUnitConditionID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CasterPlayerConditionID`,
  ADD `PlayerConditionID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CasterUnitConditionID`,
  ADD `IconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `UnitConditionID`,
  ADD `ActiveIconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `IconFileDataID`,
  DROP `SpellVisualID2`;
