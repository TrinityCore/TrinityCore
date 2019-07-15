--
-- Table structure for table `achievement`
--
ALTER TABLE `achievement`
  MODIFY `Description` text FIRST,
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Reward`,
  MODIFY `Faction` tinyint(4) NOT NULL DEFAULT 0 AFTER `InstanceID`,
  MODIFY `MinimumCriteria` tinyint(4) NOT NULL DEFAULT 0 AFTER `Category`,
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `Points`,
  MODIFY `UiOrder` smallint(6) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `SharesCriteria` smallint(6) NOT NULL DEFAULT 0 AFTER `CriteriaTree`;

--
-- Table structure for table `achievement_locale`
--
ALTER TABLE `achievement_locale` MODIFY `Description_lang` text  AFTER `locale`;

--
-- Table structure for table `area_table`
--
ALTER TABLE `area_table`
  MODIFY `SoundProviderPref` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `AreaBit`,
  MODIFY `SoundProviderPrefUnderwater` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SoundProviderPref`,
  MODIFY `UwAmbience` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `AmbienceID`,
  MODIFY `ExplorationLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `UwZoneMusic`,
  MODIFY `IntroSound` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ExplorationLevel`,
  MODIFY `UwIntroSound` int(10) unsigned NOT NULL DEFAULT 0 AFTER `IntroSound`,
  MODIFY `AmbientMultiplier` float NOT NULL DEFAULT 0 AFTER `FactionGroupMask`,
  MODIFY `MountFlags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `AmbientMultiplier`,
  MODIFY `PvpCombatWorldStateID` smallint(6) NOT NULL DEFAULT 0 AFTER `MountFlags`,
  MODIFY `WildBattlePetLevelMax` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `WildBattlePetLevelMin`,
  MODIFY `WindSettingsID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `WildBattlePetLevelMax`,
  MODIFY `Flags1` int(11) NOT NULL DEFAULT 0 AFTER `WindSettingsID`,
  MODIFY `Flags2` int(11) NOT NULL DEFAULT 0 AFTER `Flags1`,
  MODIFY `LiquidTypeID1` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Flags2`,
  MODIFY `LiquidTypeID2` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `LiquidTypeID1`,
  MODIFY `LiquidTypeID3` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `LiquidTypeID2`,
  MODIFY `LiquidTypeID4` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `LiquidTypeID3`;

--
-- Table structure for table `area_trigger`
--
ALTER TABLE `area_trigger`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `PosZ`,
  MODIFY `ContinentID` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `PhaseUseFlags` tinyint(4) NOT NULL DEFAULT 0 AFTER `ContinentID`,
  MODIFY `PhaseID` smallint(6) NOT NULL DEFAULT 0 AFTER `PhaseUseFlags`,
  MODIFY `PhaseGroupID` smallint(6) NOT NULL DEFAULT 0 AFTER `PhaseID`,
  MODIFY `Radius` float NOT NULL DEFAULT 0 AFTER `PhaseGroupID`,
  MODIFY `ShapeType` tinyint(4) NOT NULL DEFAULT 0 AFTER `BoxYaw`;

--
-- Table structure for table `artifact`
--
ALTER TABLE `artifact`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `UiTextureKitID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `UiNameColor` int(11) NOT NULL DEFAULT 0 AFTER `UiTextureKitID`,
  MODIFY `ArtifactCategoryID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Flags`;

--
-- Table structure for table `artifact_appearance`
--
ALTER TABLE `artifact_appearance`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `ArtifactAppearanceSetID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `DisplayIndex` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ArtifactAppearanceSetID`,
  MODIFY `UnlockPlayerConditionID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `DisplayIndex`,
  MODIFY `ItemAppearanceModifierID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `UnlockPlayerConditionID`,
  MODIFY `UiSwatchColor` int(11) NOT NULL DEFAULT 0 AFTER `ItemAppearanceModifierID`,
  MODIFY `UiModelSaturation` float NOT NULL DEFAULT 0 AFTER `UiSwatchColor`,
  MODIFY `OverrideShapeshiftDisplayID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `OverrideShapeshiftFormID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `UiAltItemAppearanceID`,
  MODIFY `UiCameraID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Flags`;

--
-- Table structure for table `artifact_appearance_set`
--
ALTER TABLE `artifact_appearance_set`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `DisplayIndex` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `artifact_power`
--
ALTER TABLE `artifact_power`
  CHANGE `PosX` `DisplayPosX` float NOT NULL DEFAULT 0 FIRST,
  CHANGE `PosY` `DisplayPosY` float NOT NULL DEFAULT 0 AFTER `DisplayPosX`,
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `DisplayPosY`,
  MODIFY `Label` int(11) NOT NULL DEFAULT 0 AFTER `MaxPurchasableRank`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Label`;

--
-- Table structure for table `artifact_power_rank`
--
ALTER TABLE `artifact_power_rank`
  MODIFY `RankIndex` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `AuraPointsOverride` float NOT NULL DEFAULT 0 AFTER `ItemBonusListID`;

--
-- Table structure for table `artifact_unlock`
--
ALTER TABLE `artifact_unlock`
  MODIFY `PowerID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ItemBonusListID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `PowerRank`;

--
-- Table structure for table `barber_shop_style`
--
ALTER TABLE `barber_shop_style`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `CostModifier` float NOT NULL DEFAULT 0 AFTER `Type`;

--
-- Table structure for table `battle_pet_breed_state`
--
ALTER TABLE `battle_pet_breed_state` MODIFY `BattlePetStateID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `battle_pet_species`
--
ALTER TABLE `battle_pet_species`
  MODIFY `Description` text FIRST,
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SourceText`,
  MODIFY `IconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `SummonSpellID`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `PetTypeEnum`;

--
-- Table structure for table `battle_pet_species_locale`
--
ALTER TABLE `battle_pet_species_locale` MODIFY `Description_lang` text AFTER `locale`;

--
-- Table structure for table `battle_pet_species_state`
--
ALTER TABLE `battle_pet_species_state` MODIFY `BattlePetStateID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `battlemaster_list`
--
ALTER TABLE `battlemaster_list`
  MODIFY `InstanceType` tinyint(4) NOT NULL DEFAULT 0 AFTER `LongDescription`,
  MODIFY `MinLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `InstanceType`,
  MODIFY `MaxLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `MinLevel`,
  MODIFY `RatedPlayers` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaxLevel`,
  MODIFY `MinPlayers` tinyint(4) NOT NULL DEFAULT 0 AFTER `RatedPlayers`,
  MODIFY `MaxPlayers` tinyint(4) NOT NULL DEFAULT 0 AFTER `MinPlayers`,
  MODIFY `GroupsAllowed` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaxPlayers`,
  MODIFY `MaxGroupSize` tinyint(4) NOT NULL DEFAULT 0 AFTER `GroupsAllowed`,
  MODIFY `HolidayWorldState` smallint(6) NOT NULL DEFAULT 0 AFTER `MaxGroupSize`,
  MODIFY `Flags` tinyint(4) NOT NULL DEFAULT 0 AFTER `HolidayWorldState`,
  MODIFY `IconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `RequiredPlayerConditionID` smallint(6) NOT NULL DEFAULT 0 AFTER `IconFileDataID`,
  MODIFY `MapID1` smallint(6) NOT NULL DEFAULT 0 AFTER `RequiredPlayerConditionID`;

--
-- Table structure for table `broadcast_text`
--
ALTER TABLE `broadcast_text`
  ADD `ChatBubbleDurationMs` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Text1`,
  MODIFY `LanguageID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ConditionID` int(11) NOT NULL DEFAULT 0 AFTER `LanguageID`,
  MODIFY `EmotesID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ConditionID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `EmotesID`,
  MODIFY `SoundEntriesID1` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ChatBubbleDurationMs`,
  MODIFY `SoundEntriesID2` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SoundEntriesID1`,
  MODIFY `EmoteID1` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `SoundEntriesID2`;

--
-- Table structure for table `cfg_regions`
--
ALTER TABLE `cfg_regions`
  MODIFY `Raidorigin` int(10) unsigned NOT NULL DEFAULT 0 AFTER `RegionID`,
  MODIFY `ChallengeOrigin` int(10) unsigned NOT NULL DEFAULT 0 AFTER `RegionGroupMask`;

--
-- Table structure for table `char_base_section`
--
ALTER TABLE `char_base_section` MODIFY `LayoutResType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `char_sections`
--
ALTER TABLE `char_sections`
  MODIFY `ColorIndex` tinyint(4) NOT NULL DEFAULT 0 AFTER `VariationIndex`,
  MODIFY `Flags` smallint(6) NOT NULL DEFAULT 0 AFTER `ColorIndex`,
  MODIFY `MaterialResourcesID1` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `MaterialResourcesID2` int(11) NOT NULL DEFAULT 0 AFTER `MaterialResourcesID1`,
  MODIFY `MaterialResourcesID3` int(11) NOT NULL DEFAULT 0 AFTER `MaterialResourcesID2`;

--
-- Table structure for table `char_start_outfit`
--
ALTER TABLE `char_start_outfit`
  MODIFY `ClassID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `SexID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ClassID`,
  MODIFY `OutfitID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SexID`,
  MODIFY `PetDisplayID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `OutfitID`,
  MODIFY `PetFamilyID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `PetDisplayID`,
  MODIFY `ItemID1` int(11) NOT NULL DEFAULT 0 AFTER `PetFamilyID`;

--
-- Table structure for table `chr_classes`
--
ALTER TABLE `chr_classes`
  MODIFY `Filename` text AFTER `Name`,
  MODIFY `NameFemale` text AFTER `NameMale`,
  MODIFY `PetNameToken` text AFTER `NameFemale`,
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `PetNameToken`,
  MODIFY `IconFileDataID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SelectScreenFileDataID`,
  MODIFY `PrimaryStatPriority` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `DefaultSpec`,
  MODIFY `RangedAttackPowerPerAgility` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `DisplayPower`,
  MODIFY `AttackPowerPerAgility` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `RangedAttackPowerPerAgility`,
  MODIFY `AttackPowerPerStrength` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `AttackPowerPerAgility`;

--
-- Table structure for table `chr_classes_locale`
--
ALTER TABLE `chr_classes_locale` MODIFY `NameFemale_lang` text AFTER `NameMale_lang`;

--
-- Table structure for table `chr_classes_x_power_types`
--
ALTER TABLE `chr_classes_x_power_types` MODIFY `PowerType` tinyint(4) NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `chr_races`
--
ALTER TABLE `chr_races`
  CHANGE `DisplayRaceID` `HelmVisFallbackRaceID` int(11) NOT NULL DEFAULT 0 AFTER `MaleSkeletonFileDataID`,
  ADD `MaleModelFallbackRaceID` tinyint(4) NOT NULL DEFAULT 0 AFTER `NeutralRaceID`,
  ADD `MaleModelFallbackSex` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaleModelFallbackRaceID`,
  ADD `FemaleModelFallbackRaceID` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaleModelFallbackSex`,
  ADD `FemaleModelFallbackSex` tinyint(4) NOT NULL DEFAULT 0 AFTER `FemaleModelFallbackRaceID`,
  ADD `MaleTextureFallbackRaceID` tinyint(4) NOT NULL DEFAULT 0 AFTER `FemaleModelFallbackSex`,
  ADD `MaleTextureFallbackSex` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaleTextureFallbackRaceID`,
  ADD `FemaleTextureFallbackRaceID` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaleTextureFallbackSex`,
  ADD `FemaleTextureFallbackSex` tinyint(4) NOT NULL DEFAULT 0 AFTER `FemaleTextureFallbackRaceID`,
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `NameFemaleLowercase`,
  MODIFY `HighResMaleDisplayId` int(10) unsigned NOT NULL DEFAULT 0 AFTER `FemaleDisplayId`,
  MODIFY `HighResFemaleDisplayId` int(10) unsigned NOT NULL DEFAULT 0 AFTER `HighResMaleDisplayId`,
  MODIFY `CreateScreenFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `HighResFemaleDisplayId`,
  MODIFY `AlteredFormStartVisualKitID1` int(10) unsigned NOT NULL DEFAULT 0 AFTER `LowResScreenFileDataID`,
  MODIFY `AlteredFormStartVisualKitID2` int(10) unsigned NOT NULL DEFAULT 0 AFTER `AlteredFormStartVisualKitID1`,
  MODIFY `AlteredFormStartVisualKitID3` int(10) unsigned NOT NULL DEFAULT 0 AFTER `AlteredFormStartVisualKitID2`,
  MODIFY `AlteredFormFinishVisualKitID1` int(10) unsigned NOT NULL DEFAULT 0 AFTER `AlteredFormStartVisualKitID3`,
  MODIFY `AlteredFormFinishVisualKitID2` int(10) unsigned NOT NULL DEFAULT 0 AFTER `AlteredFormFinishVisualKitID1`,
  MODIFY `AlteredFormFinishVisualKitID3` int(10) unsigned NOT NULL DEFAULT 0 AFTER `AlteredFormFinishVisualKitID2`,
  MODIFY `HeritageArmorAchievementID` int(11) NOT NULL DEFAULT 0 AFTER `AlteredFormFinishVisualKitID3`,
  MODIFY `StartingLevel` int(11) NOT NULL DEFAULT 0 AFTER `HeritageArmorAchievementID`,
  MODIFY `FemaleSkeletonFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `UiDisplayOrder`,
  MODIFY `MaleSkeletonFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `FemaleSkeletonFileDataID`,
  MODIFY `FactionID` smallint(6) NOT NULL DEFAULT 0 AFTER `HelmVisFallbackRaceID`,
  MODIFY `CinematicSequenceID` smallint(6) NOT NULL DEFAULT 0 AFTER `FactionID`,
  MODIFY `CharComponentTexLayoutHiResID` tinyint(4) NOT NULL DEFAULT 0 AFTER `CharComponentTextureLayoutID`;

--
-- Table structure for table `chr_specialization`
--
ALTER TABLE `chr_specialization`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `Flags` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Role`,
  MODIFY `PrimaryStatPriority` tinyint(4) NOT NULL DEFAULT 0 AFTER `SpellIconFileID`,
  MODIFY `AnimReplacements` int(11) NOT NULL DEFAULT 0 AFTER `PrimaryStatPriority`,
  MODIFY `MasterySpellID1` int(11) NOT NULL DEFAULT 0 AFTER `AnimReplacements`,
  MODIFY `MasterySpellID2` int(11) NOT NULL DEFAULT 0 AFTER `MasterySpellID1`;

--
-- Table structure for table `cinematic_camera`
--
ALTER TABLE `cinematic_camera` MODIFY `SoundID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `OriginZ`;

--
-- Table structure for table `content_tuning`
--
DROP TABLE IF EXISTS `content_tuning`;
CREATE TABLE `content_tuning` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinLevel` int(11) NOT NULL DEFAULT '0',
  `MaxLevel` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `ExpectedStatModID` int(11) NOT NULL DEFAULT '0',
  `DifficultyESMID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `creature_display_info`
--
ALTER TABLE `creature_display_info`
  ADD `DissolveEffectID` int(11) NOT NULL DEFAULT 0 AFTER `MountPoofSpellVisualKitID`,
  ADD `DissolveOutEffectID` int(11) NOT NULL DEFAULT 0 AFTER `Gender`,
  ADD `CreatureModelMinLod` tinyint(4) NOT NULL DEFAULT 0 AFTER `DissolveOutEffectID`,
  MODIFY `ModelID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `SoundID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ModelID`,
  MODIFY `CreatureModelScale` float NOT NULL DEFAULT 0 AFTER `SizeClass`,
  MODIFY `CreatureModelAlpha` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `CreatureModelScale`,
  MODIFY `BloodID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `CreatureModelAlpha`,
  MODIFY `NPCSoundID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ExtendedDisplayInfoID`,
  MODIFY `ParticleColorID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `NPCSoundID`,
  MODIFY `PortraitCreatureDisplayInfoID` int(11) NOT NULL DEFAULT 0 AFTER `ParticleColorID`,
  MODIFY `AnimReplacementSetID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ObjectEffectPackageID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `AnimReplacementSetID`,
  MODIFY `PlayerOverrideScale` float NOT NULL DEFAULT 0 AFTER `StateSpellVisualKitID`,
  MODIFY `UnarmedWeaponType` tinyint(4) NOT NULL DEFAULT 0 AFTER `PetInstanceScale`,
  MODIFY `Gender` tinyint(4) NOT NULL DEFAULT 0 AFTER `DissolveEffectID`,
  DROP `CreatureGeosetData`;

--
-- Table structure for table `creature_display_info_extra`
--
ALTER TABLE `creature_display_info_extra`
  MODIFY `Flags` tinyint(4) NOT NULL DEFAULT 0 AFTER `FacialHairID`,
  MODIFY `BakeMaterialResourcesID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `HDBakeMaterialResourcesID` int(11) NOT NULL DEFAULT 0 AFTER `BakeMaterialResourcesID`,
  MODIFY `CustomDisplayOption1` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `HDBakeMaterialResourcesID`;

--
-- Table structure for table `creature_family`
--
ALTER TABLE `creature_family`
  MODIFY `MinScaleLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `MinScale`,
  MODIFY `MaxScaleLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaxScale`,
  MODIFY `PetFoodMask` smallint(6) NOT NULL DEFAULT 0 AFTER `MaxScaleLevel`,
  MODIFY `PetTalentType` tinyint(4) NOT NULL DEFAULT 0 AFTER `PetFoodMask`;

--
-- Table structure for table `creature_model_data`
--
ALTER TABLE `creature_model_data`
  MODIFY `GeoBox5` float NOT NULL DEFAULT 0 AFTER `GeoBox4`,
  MODIFY `GeoBox6` float NOT NULL DEFAULT 0 AFTER `GeoBox5`,
  MODIFY `Flags` int(10) unsigned NOT NULL DEFAULT 0 AFTER `GeoBox6`,
  MODIFY `FileDataID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `BloodID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `FileDataID`,
  MODIFY `FootprintTextureID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `BloodID`,
  MODIFY `FootprintTextureLength` float NOT NULL DEFAULT 0 AFTER `FootprintTextureID`,
  MODIFY `FootprintTextureWidth` float NOT NULL DEFAULT 0 AFTER `FootprintTextureLength`,
  MODIFY `FootprintParticleScale` float NOT NULL DEFAULT 0 AFTER `FootprintTextureWidth`,
  MODIFY `FoleyMaterialID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `FootprintParticleScale`,
  MODIFY `FootstepCameraEffectID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `FoleyMaterialID`,
  MODIFY `DeathThudCameraEffectID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `FootstepCameraEffectID`,
  MODIFY `SoundID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `DeathThudCameraEffectID`,
  MODIFY `SizeClass` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SoundID`,
  MODIFY `CollisionWidth` float NOT NULL DEFAULT 0 AFTER `SizeClass`,
  MODIFY `CollisionHeight` float NOT NULL DEFAULT 0 AFTER `CollisionWidth`,
  MODIFY `WorldEffectScale` float NOT NULL DEFAULT 0 AFTER `CollisionHeight`,
  MODIFY `CreatureGeosetDataID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `WorldEffectScale`,
  MODIFY `HoverHeight` float NOT NULL DEFAULT 0 AFTER `CreatureGeosetDataID`,
  MODIFY `AttachedEffectScale` float NOT NULL DEFAULT 0 AFTER `HoverHeight`,
  MODIFY `ModelScale` float NOT NULL DEFAULT 0 AFTER `AttachedEffectScale`,
  MODIFY `MissileCollisionRadius` float NOT NULL DEFAULT 0 AFTER `ModelScale`,
  MODIFY `MountHeight` float NOT NULL DEFAULT 0 AFTER `MissileCollisionRaise`;

--
-- Table structure for table `criteria`
--
ALTER TABLE `criteria`
  MODIFY `Type` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Asset` int(10) NOT NULL DEFAULT 0 AFTER `Type`,
  MODIFY `StartEvent` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ModifierTreeId`,
  MODIFY `StartAsset` int(11) NOT NULL DEFAULT 0 AFTER `StartEvent`,
  MODIFY `FailAsset` int(11) NOT NULL DEFAULT 0 AFTER `FailEvent`,
  MODIFY `EligibilityWorldStateID` smallint(6) NOT NULL DEFAULT 0 AFTER `Flags`;

--
-- Table structure for table `criteria_tree`
--
ALTER TABLE `criteria_tree`
  MODIFY `Parent` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `Amount` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Parent`,
  MODIFY `Flags` smallint(6) NOT NULL DEFAULT 0 AFTER `OrderIndex`;

--
-- Table structure for table `currency_types`
--
ALTER TABLE `currency_types`
  ADD `FactionID` int(11) NOT NULL DEFAULT 0 AFTER `Quality`,
  MODIFY `CategoryID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `InventoryIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `CategoryID`,
  MODIFY `SpellWeight` int(10) unsigned NOT NULL DEFAULT 0 AFTER `InventoryIconFileID`,
  MODIFY `SpellCategory` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SpellWeight`,
  MODIFY `MaxQty` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpellCategory`,
  MODIFY `MaxEarnablePerWeek` int(10) unsigned NOT NULL DEFAULT 0 AFTER `MaxQty`,
  MODIFY `Quality` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`;

--
-- Table structure for table `destructible_model_data`
--
ALTER TABLE `destructible_model_data`
  MODIFY `State1Wmo` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `State0AmbientDoodadSet`,
  MODIFY `State2Wmo` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `State1AmbientDoodadSet`,
  MODIFY `State3Wmo` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `State2AmbientDoodadSet`,
  MODIFY `EjectDirection` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `State3AmbientDoodadSet`,
  MODIFY `DoNotHighlight` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `EjectDirection`,
  MODIFY `State0Wmo` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `DoNotHighlight`,
  MODIFY `HealEffect` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `State0Wmo`,
  MODIFY `HealEffectSpeed` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `HealEffect`,
  MODIFY `State0NameSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `HealEffectSpeed`,
  MODIFY `State1NameSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State0NameSet`,
  MODIFY `State2NameSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State1NameSet`,
  MODIFY `State3NameSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State2NameSet`;

--
-- Table structure for table `difficulty`
--
ALTER TABLE `difficulty`
  MODIFY `InstanceType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `InstanceType`,
  MODIFY `OldEnumValue` tinyint(4) NOT NULL DEFAULT 0 AFTER `OrderIndex`,
  MODIFY `FallbackDifficultyID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `OldEnumValue`,
  MODIFY `ItemContext` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `GroupSizeHealthCurveID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ToggleDifficultyID`,
  MODIFY `GroupSizeDmgCurveID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `GroupSizeHealthCurveID`,
  MODIFY `GroupSizeSpellPointsCurveID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `GroupSizeDmgCurveID`;

--
-- Table structure for table `dungeon_encounter`
--
ALTER TABLE `dungeon_encounter`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `OrderIndex` int(11) NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `CreatureDisplayID` int(11) NOT NULL DEFAULT 0 AFTER `Bit`;

--
-- Table structure for table `emotes`
--
ALTER TABLE `emotes`
  MODIFY `AnimID` int(11) NOT NULL DEFAULT 0 AFTER `EmoteSlashCommand`,
  MODIFY `EventSoundID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `EmoteSpecProcParam`,
  MODIFY `SpellVisualKitID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `EventSoundID`,
  MODIFY `ClassMask` int(11) NOT NULL DEFAULT 0 AFTER `SpellVisualKitID`;

--
-- Table structure for table `emotes_text_sound`
--
ALTER TABLE `emotes_text_sound` MODIFY `ClassID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `RaceID`;

--
-- Table structure for table `expected_stat`
--
DROP TABLE IF EXISTS `expected_stat`;
CREATE TABLE `expected_stat` (
  `ID` int(10) unsigned NOT NULL DEFAULT 0,
  `ExpansionID` int(11) NOT NULL DEFAULT 0,
  `CreatureHealth` float NOT NULL DEFAULT 0,
  `PlayerHealth` float NOT NULL DEFAULT 0,
  `CreatureAutoAttackDps` float NOT NULL DEFAULT 0,
  `CreatureArmor` float NOT NULL DEFAULT 0,
  `PlayerMana` float NOT NULL DEFAULT 0,
  `PlayerPrimaryStat` float NOT NULL DEFAULT 0,
  `PlayerSecondaryStat` float NOT NULL DEFAULT 0,
  `ArmorConstant` float NOT NULL DEFAULT 0,
  `CreatureSpellDamage` float NOT NULL DEFAULT 0,
  `Lvl` int(11) NOT NULL DEFAULT 0,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `expected_stat_mod`
--
DROP TABLE IF EXISTS `expected_stat_mod`;
CREATE TABLE `expected_stat_mod` (
  `ID` int(10) unsigned NOT NULL DEFAULT 0,
  `CreatureHealthMod` float NOT NULL DEFAULT 0,
  `PlayerHealthMod` float NOT NULL DEFAULT 0,
  `CreatureAutoAttackDPSMod` float NOT NULL DEFAULT 0,
  `CreatureArmorMod` float NOT NULL DEFAULT 0,
  `PlayerManaMod` float NOT NULL DEFAULT 0,
  `PlayerPrimaryStatMod` float NOT NULL DEFAULT 0,
  `PlayerSecondaryStatMod` float NOT NULL DEFAULT 0,
  `ArmorConstantMod` float NOT NULL DEFAULT 0,
  `CreatureSpellDamageMod` float NOT NULL DEFAULT 0,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `faction`
--
ALTER TABLE `faction`
  MODIFY `ReputationIndex` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ParentFactionID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ReputationIndex`,
  MODIFY `Expansion` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ParentFactionID`,
  MODIFY `FriendshipRepID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Expansion`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `FriendshipRepID`,
  MODIFY `ParagonFactionID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `ReputationFlags1` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ReputationClassMask4`,
  MODIFY `ReputationFlags2` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ReputationFlags1`,
  MODIFY `ReputationFlags3` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ReputationFlags2`,
  MODIFY `ReputationFlags4` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ReputationFlags3`,
  MODIFY `ReputationBase1` int(11) NOT NULL DEFAULT 0 AFTER `ReputationFlags4`,
  MODIFY `ReputationBase2` int(11) NOT NULL DEFAULT 0 AFTER `ReputationBase1`,
  MODIFY `ReputationBase3` int(11) NOT NULL DEFAULT 0 AFTER `ReputationBase2`,
  MODIFY `ReputationBase4` int(11) NOT NULL DEFAULT 0 AFTER `ReputationBase3`,
  MODIFY `ReputationMax1` int(11) NOT NULL DEFAULT 0 AFTER `ReputationBase4`,
  MODIFY `ReputationMax2` int(11) NOT NULL DEFAULT 0 AFTER `ReputationMax1`,
  MODIFY `ReputationMax3` int(11) NOT NULL DEFAULT 0 AFTER `ReputationMax2`,
  MODIFY `ReputationMax4` int(11) NOT NULL DEFAULT 0 AFTER `ReputationMax3`,
  MODIFY `ParentFactionMod1` float NOT NULL DEFAULT 0 AFTER `ReputationMax4`,
  MODIFY `ParentFactionMod2` float NOT NULL DEFAULT 0 AFTER `ParentFactionMod1`;

--
-- Table structure for table `faction_locale`
--
ALTER TABLE `faction_template`
  MODIFY `FactionGroup` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `FriendGroup` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `FactionGroup`,
  MODIFY `EnemyGroup` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `FriendGroup`;

--
-- Table structure for table `gameobject_display_info`
--
ALTER TABLE `gameobject_display_info`
 MODIFY `FileDataID` int(11) NOT NULL DEFAULT 0 AFTER `GeoBoxMaxZ`,
 MODIFY `ObjectEffectPackageID` smallint(6) NOT NULL DEFAULT 0 AFTER `FileDataID`;

--
-- Table structure for table `gameobjects`
--
ALTER TABLE `gameobjects`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Rot4`,
  MODIFY `OwnerID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `DisplayID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `OwnerID`,
  MODIFY `TypeID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Scale`,
  MODIFY `PhaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `TypeID`,
  MODIFY `PhaseID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `PhaseUseFlags`,
  MODIFY `PhaseGroupID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `PhaseID`,
  MODIFY `PropValue1` int(11) NOT NULL DEFAULT 0 AFTER `PhaseGroupID`;

--
-- Table structure for table `garr_ability`
--
ALTER TABLE `garr_ability`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `IconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `GarrFollowerTypeID`,
  MODIFY `FactionChangeGarrAbilityID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `IconFileDataID`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `FactionChangeGarrAbilityID`;

--
-- Table structure for table `garr_building`
--
ALTER TABLE `garr_building`
  MODIFY `AllianceName` text AFTER `HordeName`,
  MODIFY `GarrTypeID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Tooltip`,
  MODIFY `BuildingType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `GarrTypeID`,
  MODIFY `GarrSiteID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `AllianceGameObjectID`,
  MODIFY `UpgradeLevel` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `GarrSiteID`,
  MODIFY `BuildSeconds` int(11) NOT NULL DEFAULT 0 AFTER `UpgradeLevel`,
  MODIFY `CurrencyQty` int(11) NOT NULL DEFAULT 0 AFTER `CurrencyTypeID`,
  MODIFY `IconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `AllianceUiTextureKitID`,
  MODIFY `MaxAssignments` int(11) NOT NULL DEFAULT 0 AFTER `HordeSceneScriptPackageID`,
  MODIFY `ShipmentCapacity` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MaxAssignments`;

--
-- Table structure for table `garr_building_locale`
--
ALTER TABLE `garr_building_locale` MODIFY `AllianceName_lang` text AFTER `HordeName_lang`;

--
-- Table structure for table `garr_building_plot_inst`
--
ALTER TABLE `garr_building_plot_inst`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `MapOffsetY`,
  MODIFY `GarrBuildingID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `GarrSiteLevelPlotInstID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `GarrBuildingID`;

--
-- Table structure for table `garr_class_spec`
--
ALTER TABLE `garr_class_spec` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ClassSpecFemale`;

--
-- Table structure for table `garr_follower`
--
ALTER TABLE `garr_follower`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `TitleName`,
  MODIFY `GarrTypeID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `GarrFollowerTypeID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `GarrTypeID`,
  MODIFY `Quality` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `AllianceGarrClassSpecID`,
  MODIFY `FollowerLevel` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Quality`,
  MODIFY `ItemLevelWeapon` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `FollowerLevel`,
  MODIFY `ItemLevelArmor` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ItemLevelWeapon`,
  MODIFY `HordeSourceTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `ItemLevelArmor`,
  MODIFY `AllianceSourceTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `HordeSourceTypeEnum`,
  MODIFY `HordeIconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `AllianceSourceTypeEnum`,
  MODIFY `AllianceIconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `HordeIconFileDataID`,
  MODIFY `HordeGarrFollItemSetID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `AllianceIconFileDataID`,
  MODIFY `AllianceGarrFollItemSetID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `HordeGarrFollItemSetID`,
  MODIFY `HordeUITextureKitID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `AllianceGarrFollItemSetID`,
  MODIFY `AllianceUITextureKitID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `HordeUITextureKitID`,
  MODIFY `HordeFlavorGarrStringID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Vitality`,
  MODIFY `AllianceFlavorGarrStringID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `HordeFlavorGarrStringID`,
  MODIFY `HordeSlottingBroadcastTextID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `AllianceFlavorGarrStringID`,
  MODIFY `AllySlottingBroadcastTextID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `HordeSlottingBroadcastTextID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ChrClassID`,
  MODIFY `Gender` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Flags`;

--
-- Table structure for table `garr_follower_x_ability`
--
ALTER TABLE `garr_follower_x_ability`
  ADD `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `FactionIndex` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `OrderIndex`;

--
-- Table structure for table `garr_plot`
--
ALTER TABLE `garr_plot`
  MODIFY `PlotType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `AllianceConstructObjID` int(11) NOT NULL DEFAULT 0 AFTER `HordeConstructObjID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `AllianceConstructObjID`;

--
-- Table structure for table `garr_site_level`
--
ALTER TABLE `garr_site_level`
  MODIFY `GarrSiteID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `TownHallUiPosY`,
  MODIFY `GarrLevel` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `GarrSiteID`,
  MODIFY `UiTextureKitID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `UpgradeMovieID`,
  MODIFY `MaxBuildingLevel` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `UiTextureKitID`;

--
-- Table structure for table `gem_properties`
--
ALTER TABLE `gem_properties`
  MODIFY `EnchantId` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Type` int(11) NOT NULL DEFAULT 0 AFTER `EnchantId`;

--
-- Table structure for table `guild_color_background`
--
ALTER TABLE `guild_color_background` MODIFY `Blue` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Red`;

--
-- Table structure for table `guild_color_border`
--
ALTER TABLE `guild_color_border` MODIFY `Blue` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Red`;

--
-- Table structure for table `guild_color_emblem`
--
ALTER TABLE `guild_color_emblem` MODIFY `Blue` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Red`;

--
-- Table structure for table `heirloom`
--
ALTER TABLE `heirloom`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SourceText`,
  MODIFY `StaticUpgradedItemID` int(11) NOT NULL DEFAULT 0 AFTER `LegacyUpgradedItemID`,
  MODIFY `SourceTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `StaticUpgradedItemID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SourceTypeEnum`,
  MODIFY `LegacyItemID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`;

--
-- Table structure for table `holidays`
--
ALTER TABLE `holidays`
  MODIFY `Region` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Looping` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Region`,
  MODIFY `HolidayNameID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Looping`,
  MODIFY `HolidayDescriptionID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `HolidayNameID`,
  MODIFY `Priority` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `HolidayDescriptionID`,
  MODIFY `CalendarFilterType` tinyint(4) NOT NULL DEFAULT 0 AFTER `Priority`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `CalendarFilterType`,
  MODIFY `Duration1` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `Duration2` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Duration1`,
  MODIFY `Duration3` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Duration2`,
  MODIFY `Duration4` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Duration3`,
  MODIFY `Duration5` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Duration4`,
  MODIFY `Duration6` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Duration5`,
  MODIFY `Duration7` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Duration6`,
  MODIFY `Duration8` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Duration7`,
  MODIFY `Duration9` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Duration8`,
  MODIFY `Duration10` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Duration9`,
  MODIFY `Date1` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Duration10`,
  MODIFY `Date2` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Date1`,
  MODIFY `Date3` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Date2`,
  MODIFY `Date4` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Date3`;

--
-- Table structure for table `item`
--
ALTER TABLE `item`
  MODIFY `InventoryType` tinyint(4) NOT NULL DEFAULT 0 AFTER `Material`,
  MODIFY `SoundOverrideSubclassID` tinyint(4) NOT NULL DEFAULT 0 AFTER `SheatheType`,
  MODIFY `IconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `SoundOverrideSubclassID`;

--
-- Table structure for table `item_appearance`
--
ALTER TABLE `item_appearance` MODIFY `DisplayType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `item_armor_quality`
--
ALTER TABLE `item_armor_quality` DROP `ItemLevel`;

--
-- Table structure for table `item_armor_total`
--
ALTER TABLE `item_armor_total` MODIFY `ItemLevel` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `item_bonus_tree_node`
--
ALTER TABLE `item_bonus_tree_node` MODIFY `ItemContext` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `item_class`
--
ALTER TABLE `item_class` MODIFY `ClassID` tinyint(4) NOT NULL DEFAULT 0 AFTER `ClassName`;

--
-- Table structure for table `item_damage_ammo`
--
ALTER TABLE `item_damage_ammo` MODIFY `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `item_damage_one_hand`
--
ALTER TABLE `item_damage_one_hand` MODIFY `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `item_damage_one_hand_caster`
--
ALTER TABLE `item_damage_one_hand_caster` MODIFY `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `item_damage_two_hand`
--
ALTER TABLE `item_damage_two_hand` MODIFY `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `item_damage_two_hand_caster`
--
ALTER TABLE `item_damage_two_hand_caster` MODIFY `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `item_disenchant_loot`
--
ALTER TABLE `item_disenchant_loot`
  MODIFY `Subclass` tinyint(4) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Quality` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Subclass`,
  MODIFY `MinLevel` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Quality`;

--
-- Table structure for table `item_effect`
--
ALTER TABLE `item_effect`
  MODIFY `LegacySlotIndex` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `TriggerType` tinyint(4) NOT NULL DEFAULT 0 AFTER `LegacySlotIndex`,
  MODIFY `Charges` smallint(6) NOT NULL DEFAULT 0 AFTER `TriggerType`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `SpellCategoryID`;

--
-- Table structure for table `item_extended_cost`
--
ALTER TABLE `item_extended_cost`
  MODIFY `RequiredArenaRating` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ArenaBracket` tinyint(4) NOT NULL DEFAULT 0 AFTER `RequiredArenaRating`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ArenaBracket`,
  MODIFY `MinFactionID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `MinReputation` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MinFactionID`,
  MODIFY `RequiredAchievement` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MinReputation`,
  MODIFY `ItemID1` int(11) NOT NULL DEFAULT 0 AFTER `RequiredAchievement`,
  MODIFY `ItemID2` int(11) NOT NULL DEFAULT 0 AFTER `ItemID1`,
  MODIFY `CurrencyID4` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `CurrencyID3`,
  MODIFY `CurrencyID5` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `CurrencyID4`,
  MODIFY `CurrencyCount1` int(10) unsigned NOT NULL DEFAULT 0 AFTER `CurrencyID5`,
  MODIFY `CurrencyCount2` int(10) unsigned NOT NULL DEFAULT 0 AFTER `CurrencyCount1`,
  MODIFY `CurrencyCount3` int(10) unsigned NOT NULL DEFAULT 0 AFTER `CurrencyCount2`,
  MODIFY `CurrencyCount4` int(10) unsigned NOT NULL DEFAULT 0 AFTER `CurrencyCount3`,
  MODIFY `CurrencyCount5` int(10) unsigned NOT NULL DEFAULT 0 AFTER `CurrencyCount4`;

--
-- Table structure for table `item_limit_category_condition`
--
ALTER TABLE `item_limit_category_condition`
  MODIFY `AddQuantity` tinyint(4) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ParentItemLimitCategoryID` int(11) NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

--
-- Table structure for table `item_modified_appearance`
--
ALTER TABLE `item_modified_appearance` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 FIRST;

--
-- Table structure for table `item_price_base`
--
ALTER TABLE `item_price_base` MODIFY `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `item_search_name`
--
ALTER TABLE `item_search_name`
  ADD `Flags4` int(11) NOT NULL DEFAULT 0 AFTER `Flags3`,
  MODIFY `RequiredLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `AllowableClass`,
  MODIFY `RequiredAbility` int(10) unsigned NOT NULL DEFAULT 0 AFTER `RequiredSkillRank`,
  MODIFY `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `RequiredAbility`,
  MODIFY `Flags1` int(11) NOT NULL DEFAULT 0 AFTER `ItemLevel`,
  MODIFY `Flags2` int(11) NOT NULL DEFAULT 0 AFTER `Flags1`,
  MODIFY `Flags3` int(11) NOT NULL DEFAULT 0 AFTER `Flags2`;

--
-- Table structure for table `item_set`
--
ALTER TABLE `item_set`
  MODIFY `SetFlags` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `RequiredSkill` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SetFlags`,
  MODIFY `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `RequiredSkill`;

--
-- Table structure for table `item_set_spell`
--
ALTER TABLE `item_set_spell` MODIFY `ChrSpecID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `item_sparse`
--
ALTER TABLE `item_sparse`
  ADD `FactionRelated` int(11) NOT NULL DEFAULT 0 AFTER `Flags4`,
  MODIFY `Description` text AFTER `AllowableRace`,
  MODIFY `Display2` text AFTER `Display3`,
  MODIFY `Display1` text AFTER `Display2`,
  MODIFY `Display` text AFTER `Display1`,
  MODIFY `DmgVariance` float NOT NULL DEFAULT 0 AFTER `Display`,
  MODIFY `DurationInInventory` int(10) unsigned NOT NULL DEFAULT 0 AFTER `DmgVariance`,
  MODIFY `QualityModifier` float NOT NULL DEFAULT 0 AFTER `DurationInInventory`,
  MODIFY `BagFamily` int(10) unsigned NOT NULL DEFAULT 0 AFTER `QualityModifier`,
  MODIFY `ItemRange` float NOT NULL DEFAULT 0 AFTER `BagFamily`,
  MODIFY `StatPercentageOfSocket1` float NOT NULL DEFAULT 0 AFTER `ItemRange`,
  MODIFY `StatPercentageOfSocket2` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket1`,
  MODIFY `StatPercentageOfSocket3` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket2`,
  MODIFY `StatPercentageOfSocket4` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket3`,
  MODIFY `StatPercentageOfSocket5` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket4`,
  MODIFY `StatPercentageOfSocket6` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket5`,
  MODIFY `StatPercentageOfSocket7` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket6`,
  MODIFY `StatPercentageOfSocket8` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket7`,
  MODIFY `StatPercentageOfSocket9` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket8`,
  MODIFY `StatPercentageOfSocket10` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket9`,
  MODIFY `Stackable` int(11) NOT NULL DEFAULT 0 AFTER `StatPercentEditor10`,
  MODIFY `MaxCount` int(11) NOT NULL DEFAULT 0 AFTER `Stackable`,
  MODIFY `RequiredAbility` int(10) unsigned NOT NULL DEFAULT 0 AFTER `MaxCount`,
  MODIFY `SellPrice` int(10) unsigned NOT NULL DEFAULT 0 AFTER `RequiredAbility`,
  MODIFY `BuyPrice` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SellPrice`,
  MODIFY `VendorStackCount` int(10) unsigned NOT NULL DEFAULT 0 AFTER `BuyPrice`,
  MODIFY `PriceVariance` float NOT NULL DEFAULT 0 AFTER `VendorStackCount`,
  MODIFY `PriceRandomValue` float NOT NULL DEFAULT 0 AFTER `PriceVariance`,
  MODIFY `Flags1` int(11) NOT NULL DEFAULT 0 AFTER `PriceRandomValue`,
  MODIFY `Flags2` int(11) NOT NULL DEFAULT 0 AFTER `Flags1`,
  MODIFY `Flags3` int(11) NOT NULL DEFAULT 0 AFTER `Flags2`,
  MODIFY `Flags4` int(11) NOT NULL DEFAULT 0 AFTER `Flags3`,
  MODIFY `ItemNameDescriptionID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `FactionRelated`,
  MODIFY `RequiredTransmogHoliday` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ItemNameDescriptionID`,
  MODIFY `RequiredHoliday` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `RequiredTransmogHoliday`,
  MODIFY `LimitCategory` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `RequiredHoliday`,
  MODIFY `GemProperties` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `LimitCategory`,
  MODIFY `SocketMatchEnchantmentId` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `GemProperties`,
  MODIFY `TotemCategoryID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `SocketMatchEnchantmentId`,
  MODIFY `InstanceBound` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `TotemCategoryID`,
  MODIFY `ItemSet` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ZoneBound`,
  MODIFY `ItemRandomSuffixGroupID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ItemSet`,
  MODIFY `RandomSelect` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ItemRandomSuffixGroupID`,
  MODIFY `LockID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `RandomSelect`,
  MODIFY `StartQuestID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `LockID`,
  MODIFY `PageID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `StartQuestID`,
  MODIFY `ItemDelay` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `PageID`,
  MODIFY `ScalingStatDistributionID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ItemDelay`,
  MODIFY `MinFactionID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ScalingStatDistributionID`,
  MODIFY `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `MinFactionID`,
  MODIFY `RequiredSkill` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `RequiredSkillRank`,
  MODIFY `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `RequiredSkill`,
  MODIFY `AllowableClass` smallint(6) NOT NULL DEFAULT 0 AFTER `ItemLevel`,
  MODIFY `ExpansionID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `AllowableClass`,
  MODIFY `ArtifactID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ExpansionID`,
  MODIFY `SpellWeight` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ArtifactID`,
  MODIFY `SpellWeightCategory` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SpellWeight`,
  MODIFY `SocketType1` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SpellWeightCategory`,
  MODIFY `SocketType2` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SocketType1`,
  MODIFY `SocketType3` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SocketType2`,
  MODIFY `SheatheType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SocketType3`,
  MODIFY `Material` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SheatheType`,
  MODIFY `PageMaterialID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Material`,
  MODIFY `LanguageID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `PageMaterialID`,
  MODIFY `Bonding` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `LanguageID`,
  MODIFY `DamageDamageType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Bonding`,
  MODIFY `ContainerSlots` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat10`,
  MODIFY `MinReputation` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ContainerSlots`,
  MODIFY `RequiredPVPMedal` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MinReputation`,
  MODIFY `RequiredPVPRank` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `RequiredPVPMedal`,
  MODIFY `RequiredLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `RequiredPVPRank`,
  MODIFY `InventoryType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `RequiredLevel`,
  MODIFY `OverallQualityID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `InventoryType`,
  DROP `ItemStatValue1`,
  DROP `ItemStatValue2`,
  DROP `ItemStatValue3`,
  DROP `ItemStatValue4`,
  DROP `ItemStatValue5`,
  DROP `ItemStatValue6`,
  DROP `ItemStatValue7`,
  DROP `ItemStatValue8`,
  DROP `ItemStatValue9`,
  DROP `ItemStatValue10`;

--
-- Table structure for table `item_sparse_locale`
--
ALTER TABLE `item_sparse_locale`
  MODIFY `Description_lang` text AFTER `locale`,
  MODIFY `Display3_lang` text AFTER `Description_lang`,
  MODIFY `Display2_lang` text AFTER `Display3_lang`,
  MODIFY `Display1_lang` text AFTER `Display2_lang`;

--
-- Table structure for table `item_spec`
--
ALTER TABLE `item_spec` MODIFY `SpecializationID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `SecondaryStat`;

--
-- Table structure for table `item_upgrade`
--
ALTER TABLE `item_upgrade`
  MODIFY `PrerequisiteID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ItemLevelIncrement`,
  MODIFY `CurrencyType` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `PrerequisiteID`,
  MODIFY `CurrencyAmount` int(10) unsigned NOT NULL DEFAULT 0 AFTER `CurrencyType`;

--
-- Table structure for table `lfg_dungeons`
--
ALTER TABLE `lfg_dungeons`
  CHANGE `Flags` `Flags1` int(11) NOT NULL DEFAULT 0 AFTER `MentorCharLevel`,
  ADD `Flags2` int(11) NOT NULL DEFAULT 0 AFTER `Flags1`,
  MODIFY `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `TypeID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MaxLevel`,
  MODIFY `Subtype` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `TypeID`,
  MODIFY `Faction` tinyint(4) NOT NULL DEFAULT 0 AFTER `Subtype`,
  MODIFY `IconTextureFileID` int(11) NOT NULL DEFAULT 0 AFTER `Faction`,
  MODIFY `RewardsBgTextureFileID` int(11) NOT NULL DEFAULT 0 AFTER `IconTextureFileID`,
  MODIFY `PopupBgTextureFileID` int(11) NOT NULL DEFAULT 0 AFTER `RewardsBgTextureFileID`,
  MODIFY `ExpansionLevel` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `PopupBgTextureFileID`,
  MODIFY `MapID` smallint(6) NOT NULL DEFAULT 0 AFTER `ExpansionLevel`,
  MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MapID`,
  MODIFY `MinGear` float NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `GroupID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MinGear`,
  MODIFY `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `GroupID`,
  MODIFY `RequiredPlayerConditionId` int(10) unsigned NOT NULL DEFAULT 0 AFTER `OrderIndex`,
  MODIFY `TargetLevelMax` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `TargetLevelMin`,
  MODIFY `RandomID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `TargetLevelMax`,
  MODIFY `ScenarioID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `RandomID`,
  MODIFY `FinalEncounterID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ScenarioID`,
  MODIFY `BonusReputationAmount` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `MinCountDamage`,
  MODIFY `MentorItemLevel` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `BonusReputationAmount`;

--
-- Table structure for table `liquid_type`
--
ALTER TABLE `liquid_type`
  ADD `MinimapStaticCol` int(11) NOT NULL DEFAULT 0 AFTER `MaterialID`,
  ADD `Coefficient1` float NOT NULL DEFAULT 0 AFTER `Int4`,
  ADD `Coefficient2` float NOT NULL DEFAULT 0 AFTER `Coefficient1`,
  ADD `Coefficient3` float NOT NULL DEFAULT 0 AFTER `Coefficient2`,
  ADD `Coefficient4` float NOT NULL DEFAULT 0 AFTER `Coefficient3`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Texture6`,
  MODIFY `SoundBank` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `SoundID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SoundBank`,
  MODIFY `LightID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `DirDarkenIntensity`,
  MODIFY `ParticleMovement` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ParticleScale`,
  MODIFY `ParticleTexSlots` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ParticleMovement`,
  MODIFY `MaterialID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ParticleTexSlots`,
  MODIFY `FrameCountTexture1` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MinimapStaticCol`,
  MODIFY `FrameCountTexture2` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `FrameCountTexture1`,
  MODIFY `FrameCountTexture3` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `FrameCountTexture2`,
  MODIFY `FrameCountTexture4` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `FrameCountTexture3`,
  MODIFY `FrameCountTexture5` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `FrameCountTexture4`,
  MODIFY `FrameCountTexture6` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `FrameCountTexture5`,
  MODIFY `Color1` int(11) NOT NULL DEFAULT 0 AFTER `FrameCountTexture6`,
  MODIFY `Color2` int(11) NOT NULL DEFAULT 0 AFTER `Color1`;

--
-- Table structure for table `map`
--
ALTER TABLE `map`
  ADD `ZmpFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `WindSettingsID`,
  MODIFY `MapType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `CorpseY`,
  MODIFY `InstanceType` tinyint(4) NOT NULL DEFAULT 0 AFTER `MapType`,
  MODIFY `ExpansionID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `InstanceType`,
  MODIFY `TimeOffset` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `CosmeticParentMapID`,
  MODIFY `MinimapIconScale` float NOT NULL DEFAULT 0 AFTER `TimeOffset`,
  MODIFY `CorpseMapID` smallint(6) NOT NULL DEFAULT 0 AFTER `MinimapIconScale`,
  MODIFY `WindSettingsID` smallint(6) NOT NULL DEFAULT 0 AFTER `MaxPlayers`,
  MODIFY `Flags1` int(11) NOT NULL DEFAULT 0 AFTER `ZmpFileDataID`,
  MODIFY `Flags2` int(11) NOT NULL DEFAULT 0 AFTER `Flags1`;

--
-- Table structure for table `map_difficulty`
--
ALTER TABLE `map_difficulty`
  ADD `ContentTuningID` int(11) NOT NULL DEFAULT 0 AFTER `ItemContextPickerID`,
  MODIFY `ItemContextPickerID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Message`,
  MODIFY `LockID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ItemContext`;

--
-- Table structure for table `modifier_tree`
--
ALTER TABLE `modifier_tree`
  MODIFY `Parent` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Operator` tinyint(4) NOT NULL DEFAULT 0 AFTER `Parent`,
  MODIFY `Amount` tinyint(4) NOT NULL DEFAULT 0 AFTER `Operator`,
  MODIFY `Asset` int(11) NOT NULL DEFAULT 0 AFTER `Type`,
  MODIFY `SecondaryAsset` int(11) NOT NULL DEFAULT 0 AFTER `Asset`;

--
-- Table structure for table `mount`
--
ALTER TABLE `mount`
  MODIFY `Description` text AFTER `SourceText`,
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `SourceSpellID` int(11) NOT NULL DEFAULT 0 AFTER `SourceTypeEnum`,
  MODIFY `MountFlyRideHeight` float NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

--
-- Dumping data for table `mount_locale`
--
ALTER TABLE `mount_locale` MODIFY `Description_lang` text AFTER `SourceText_lang`;

--
-- Table structure for table `mount_capability`
--
ALTER TABLE `mount_capability`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 FIRST,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ReqAreaID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ReqRidingSkill`,
  MODIFY `ReqSpellAuraID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ReqAreaID`,
  MODIFY `ReqSpellKnownID` int(11) NOT NULL DEFAULT 0 AFTER `ReqSpellAuraID`,
  MODIFY `ModSpellAuraID` int(11) NOT NULL DEFAULT 0 AFTER `ReqSpellKnownID`;

--
-- Table structure for table `movie`
--
ALTER TABLE `movie`
  MODIFY `AudioFileDataID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `KeyID`,
  MODIFY `SubtitleFileDataID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `AudioFileDataID`;

--
-- Table structure for table `player_condition`
--
ALTER TABLE `player_condition`
  MODIFY `AchievementLogic` int(10) unsigned NOT NULL DEFAULT 0 AFTER `LifetimeMaxPVPRank`,
  MODIFY `Gender` tinyint(4) NOT NULL DEFAULT 0 AFTER `AchievementLogic`,
  MODIFY `NativeGender` tinyint(4) NOT NULL DEFAULT 0 AFTER `Gender`,
  MODIFY `AreaLogic` int(10) unsigned NOT NULL DEFAULT 0 AFTER `NativeGender`,
  MODIFY `PhaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MaxAvgEquippedItemLevel`,
  MODIFY `PhaseID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `PhaseUseFlags`,
  MODIFY `PhaseGroupID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `PhaseID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `PhaseGroupID`,
  MODIFY `ModifierTreeID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ChrSpecializationRole`,
  MODIFY `MaxGuildLevel` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `WeaponSubclassMask`,
  MODIFY `MinGuildLevel` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MaxGuildLevel`,
  MODIFY `MaxExpansionTier` tinyint(4) NOT NULL DEFAULT 0 AFTER `MinGuildLevel`,
  MODIFY `MinExpansionTier` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaxExpansionTier`,
  MODIFY `MinPVPRank` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MinExpansionTier`,
  MODIFY `MaxPVPRank` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `MinPVPRank`,
  MODIFY `AreaID1` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Achievement4`,
  MODIFY `AreaID2` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `AreaID1`,
  MODIFY `AreaID3` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `AreaID2`,
  MODIFY `AreaID4` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `AreaID3`;

--
-- Table structure for table `power_type`
--
ALTER TABLE `power_type`
  MODIFY `MaxBasePower` smallint(6) NOT NULL DEFAULT 0 AFTER `MinPower`,
  MODIFY `DisplayModifier` tinyint(4) NOT NULL DEFAULT 0 AFTER `DefaultPower`,
  MODIFY `RegenInterruptTimeMS` smallint(6) NOT NULL DEFAULT 0 AFTER `DisplayModifier`,
  MODIFY `RegenPeace` float NOT NULL DEFAULT 0 AFTER `RegenInterruptTimeMS`,
  MODIFY `RegenCombat` float NOT NULL DEFAULT 0 AFTER `RegenPeace`,
  MODIFY `Flags` smallint(6) NOT NULL DEFAULT 0 AFTER `RegenCombat`;

--
-- Table structure for table `prestige_level_info`
--
ALTER TABLE `prestige_level_info`
  ADD `AwardedAchievementID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `PrestigeLevel` int(11) NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `BadgeTextureFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `PrestigeLevel`;

--
-- Table structure for table `pvp_talent`
--
ALTER TABLE `pvp_talent`
  ADD `PvpTalentCategoryID` int(11) NOT NULL DEFAULT 0 AFTER `ActionBarSpellID`,
  ADD `LevelRequired` int(11) NOT NULL DEFAULT 0 AFTER `PvpTalentCategoryID`,
  MODIFY `Description` text FIRST,
  MODIFY `SpecID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ActionBarSpellID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  DROP `TierID`,
  DROP `ColumnIndex`,
  DROP `ClassID`,
  DROP `Role`;
  
--
-- Table structure for table `pvp_talent_category`
--
DROP TABLE IF EXISTS `pvp_talent_category`;
CREATE TABLE `pvp_talent_category` (
  `ID` int(10) unsigned NOT NULL DEFAULT 0,
  `TalentSlotMask` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `pvp_talent_slot_unlock`
--
DROP TABLE IF EXISTS `pvp_talent_slot_unlock`;
CREATE TABLE `pvp_talent_slot_unlock` (
  `ID` int(10) unsigned NOT NULL DEFAULT 0,
  `Slot` tinyint(4) NOT NULL DEFAULT 0,
  `LevelRequired` int(11) NOT NULL DEFAULT 0,
  `DeathKnightLevelRequired` int(11) NOT NULL DEFAULT 0,
  `DemonHunterLevelRequired` int(11) NOT NULL DEFAULT 0,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `quest_package_item`
--
ALTER TABLE `quest_package_item`
  MODIFY `ItemID` int(11) NOT NULL DEFAULT 0 AFTER `PackageID`,
  MODIFY `DisplayType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ItemQuantity`;

--
-- Table structure for table `rand_prop_points`
--
ALTER TABLE `rand_prop_points` ADD `DamageReplaceStat` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `reward_pack`
--
ALTER TABLE `reward_pack`
  MODIFY `CharTitleID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ArtifactXPDifficulty` tinyint(4) NOT NULL DEFAULT 0 AFTER `Money`;

--
-- Table structure for table `scenario`
--
ALTER TABLE `scenario`
  ADD `UiTextureKitID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Type`;

--
-- Table structure for table `scenario_step`
--
ALTER TABLE `scenario_step`
  ADD `VisibilityPlayerConditionID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  ADD `WidgetSetID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `VisibilityPlayerConditionID`,
  MODIFY `Criteriatreeid` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ScenarioID`,
  MODIFY `RewardQuestID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `Criteriatreeid`,
  MODIFY `RelatedStep` int(11) NOT NULL DEFAULT 0 AFTER `RewardQuestID`;

--
-- Table structure for table `skill_line`
--
ALTER TABLE `skill_line`
  ADD `HordeDisplayName` text AFTER `Description`,
  ADD `OverrideSourceInfoDisplayName` text AFTER `HordeDisplayName`,
  ADD `ParentTierIndex` int(11) NOT NULL DEFAULT 0 AFTER `ParentSkillLineID`,
  ADD `SpellBookSpellID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `AlternateVerb` text AFTER `DisplayName`,
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `OverrideSourceInfoDisplayName`,
  MODIFY `CanLink` tinyint(4) NOT NULL DEFAULT 0 AFTER `SpellIconFileID`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ParentTierIndex`;

--
-- Table structure for table `skill_line_locale`
--
ALTER TABLE `skill_line_locale`
  ADD `HordeDisplayName_lang` text AFTER `Description_lang`,
  MODIFY `AlternateVerb_lang` text AFTER `DisplayName_lang`;

--
-- Table structure for table `skill_line_ability`
--
ALTER TABLE `skill_line_ability`
  ADD `SkillupSkillLineID` smallint(6) NOT NULL DEFAULT 0 AFTER `TradeSkillCategoryID`,
  MODIFY `SkillLine` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `MinSkillLineRank` smallint(6) NOT NULL DEFAULT 0 AFTER `Spell`,
  MODIFY `ClassMask` int(11) NOT NULL DEFAULT 0 AFTER `MinSkillLineRank`,
  MODIFY `SupercedesSpell` int(11) NOT NULL DEFAULT 0 AFTER `ClassMask`,
  MODIFY `AcquireMethod` tinyint(4) NOT NULL DEFAULT 0 AFTER `SupercedesSpell`,
  MODIFY `Flags` tinyint(4) NOT NULL DEFAULT 0 AFTER `TrivialSkillLineRankLow`,
  MODIFY `NumSkillUps` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`;

--
-- Table structure for table `skill_race_class_info`
--
ALTER TABLE `skill_race_class_info`
  MODIFY `ClassMask` int(11) NOT NULL DEFAULT 0 AFTER `SkillID`,
  MODIFY `SkillTierID` smallint(6) NOT NULL DEFAULT 0 AFTER `MinLevel`;

--
-- Table structure for table `sound_kit`
--
ALTER TABLE `sound_kit`
  ADD `SoundKitAdvancedID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `EAXDef`,
  MODIFY `SoundType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `VolumeFloat`,
  MODIFY `DialogType` tinyint(4) NOT NULL DEFAULT 0 AFTER `PitchVariationMinus`,
  DROP `SoundEntriesAdvancedID`;

--
-- Table structure for table `specialization_spells`
--
ALTER TABLE `specialization_spells`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `SpecID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `spell_aura_options`
--
ALTER TABLE `spell_aura_options`
  CHANGE `ProcTypeMask` `ProcTypeMask1` int(11) NOT NULL DEFAULT 0 AFTER `SpellProcsPerMinuteID`,
  ADD `ProcTypeMask2` int(11) NOT NULL DEFAULT 0 AFTER `ProcTypeMask1`,
  MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `CumulativeAura` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `ProcChance` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ProcCategoryRecovery`,
  MODIFY `ProcCharges` int(11) NOT NULL DEFAULT 0 AFTER `ProcChance`;

--
-- Table structure for table `spell_aura_restrictions`
--
ALTER TABLE `spell_aura_restrictions`
  MODIFY `ExcludeTargetAuraState` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ExcludeCasterAuraState`,
  MODIFY `CasterAuraSpell` int(11) NOT NULL DEFAULT 0 AFTER `ExcludeTargetAuraState`,
  MODIFY `TargetAuraSpell` int(11) NOT NULL DEFAULT 0 AFTER `CasterAuraSpell`,
  MODIFY `ExcludeCasterAuraSpell` int(11) NOT NULL DEFAULT 0 AFTER `TargetAuraSpell`,
  MODIFY `ExcludeTargetAuraSpell` int(11) NOT NULL DEFAULT 0 AFTER `ExcludeCasterAuraSpell`;

--
-- Dumping data for table `spell_cast_times`
--
ALTER TABLE `spell_cast_times` MODIFY `Minimum` int(11) NOT NULL DEFAULT 0 AFTER `PerLevel`;

--
-- Table structure for table `spell_casting_requirements`
--
ALTER TABLE `spell_casting_requirements`
  MODIFY `FacingCasterFlags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SpellID`,
  MODIFY `MinReputation` tinyint(4) NOT NULL DEFAULT 0 AFTER `MinFactionID`,
  MODIFY `RequiredAuraVision` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `RequiredAreasID`;

--
-- Table structure for table `spell_categories`
--
ALTER TABLE `spell_categories`
  MODIFY `Category` smallint(6) NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `StartRecoveryCategory` smallint(6) NOT NULL DEFAULT 0 AFTER `PreventionType`,
  MODIFY `ChargeCategory` smallint(6) NOT NULL DEFAULT 0 AFTER `StartRecoveryCategory`;

--
-- Table structure for table `spell_category`
--
ALTER TABLE `spell_category` MODIFY `ChargeRecoveryTime` int(11) NOT NULL DEFAULT 0 AFTER `MaxCharges`;

--
-- Table structure for table `spell_class_options`
--
ALTER TABLE `spell_class_options`
  MODIFY `ModalNextSpell` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpellID`,
  MODIFY `SpellClassSet` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ModalNextSpell`,
  MODIFY `SpellClassMask1` int(11) NOT NULL DEFAULT 0 AFTER `SpellClassSet`,
  MODIFY `SpellClassMask2` int(11) NOT NULL DEFAULT 0 AFTER `SpellClassMask1`,
  MODIFY `SpellClassMask3` int(11) NOT NULL DEFAULT 0 AFTER `SpellClassMask2`,
  MODIFY `SpellClassMask4` int(11) NOT NULL DEFAULT 0 AFTER `SpellClassMask3`;

--
-- Table structure for table `spell_cooldowns`
--
ALTER TABLE `spell_cooldowns` MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `spell_duration`
--
ALTER TABLE `spell_duration` MODIFY `DurationPerLevel` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Duration`;

--
-- Table structure for table `spell_effect`
--
ALTER TABLE `spell_effect`
  MODIFY `DifficultyID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Effect` int(10) unsigned NOT NULL DEFAULT 0 AFTER `EffectIndex`,
  MODIFY `EffectAmplitude` float NOT NULL DEFAULT 0 AFTER `Effect`,
  MODIFY `EffectAttributes` int(11) NOT NULL DEFAULT 0 AFTER `EffectAmplitude`,
  MODIFY `EffectAura` smallint(6) NOT NULL DEFAULT 0 AFTER `EffectAttributes`,
  MODIFY `EffectPosFacing` float NOT NULL DEFAULT 0 AFTER `EffectPointsPerResource`,
  MODIFY `EffectBasePoints` float NOT NULL DEFAULT 0 AFTER `GroupSizeBasePointsCoefficient`,
  MODIFY `EffectMiscValue1` int(11) NOT NULL DEFAULT 0 AFTER `EffectBasePoints`,
  MODIFY `EffectMiscValue2` int(11) NOT NULL DEFAULT 0 AFTER `EffectMiscValue1`,
  MODIFY `EffectRadiusIndex1` int(10) unsigned NOT NULL DEFAULT 0 AFTER `EffectMiscValue2`,
  MODIFY `EffectRadiusIndex2` int(10) unsigned NOT NULL DEFAULT 0 AFTER `EffectRadiusIndex1`,
  MODIFY `EffectSpellClassMask1` int(11) NOT NULL DEFAULT 0 AFTER `EffectRadiusIndex2`,
  MODIFY `EffectSpellClassMask2` int(11) NOT NULL DEFAULT 0 AFTER `EffectSpellClassMask1`,
  MODIFY `EffectSpellClassMask3` int(11) NOT NULL DEFAULT 0 AFTER `EffectSpellClassMask2`,
  MODIFY `EffectSpellClassMask4` int(11) NOT NULL DEFAULT 0 AFTER `EffectSpellClassMask3`,
  MODIFY `ImplicitTarget1` smallint(6) NOT NULL DEFAULT 0 AFTER `EffectSpellClassMask4`,
  MODIFY `ImplicitTarget2` smallint(6) NOT NULL DEFAULT 0 AFTER `ImplicitTarget1`,
  DROP `EffectDieSides`;

--
-- Table structure for table `spell_equipped_items`
--
ALTER TABLE `spell_equipped_items` MODIFY `EquippedItemClass` tinyint(4) NOT NULL DEFAULT 0 AFTER `SpellID`;

--
-- Table structure for table `spell_item_enchantment`
--
ALTER TABLE `spell_item_enchantment`
  ADD `HordeName` text AFTER `Name`,
  MODIFY `TransmogPlayerConditionID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `IconFileDataID`,
  MODIFY `ScalingClass` tinyint(4) NOT NULL DEFAULT 0 AFTER `Effect3`,
  MODIFY `ScalingClassRestricted` tinyint(4) NOT NULL DEFAULT 0 AFTER `ScalingClass`;

--
-- Table structure for table `spell_item_enchantment_locale`
--
ALTER TABLE `spell_item_enchantment_locale` ADD `HordeName_lang` text AFTER `Name_lang`;

--
-- Table structure for table `spell_item_enchantment_condition`
--
ALTER TABLE `spell_item_enchantment_condition`
  MODIFY `LtOperandType4` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `LtOperandType3`,
  MODIFY `LtOperandType5` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `LtOperandType4`,
  MODIFY `LtOperand1` int(10) unsigned NOT NULL DEFAULT 0 AFTER `LtOperandType5`,
  MODIFY `LtOperand2` int(10) unsigned NOT NULL DEFAULT 0 AFTER `LtOperand1`,
  MODIFY `LtOperand3` int(10) unsigned NOT NULL DEFAULT 0 AFTER `LtOperand2`,
  MODIFY `LtOperand4` int(10) unsigned NOT NULL DEFAULT 0 AFTER `LtOperand3`,
  MODIFY `LtOperand5` int(10) unsigned NOT NULL DEFAULT 0 AFTER `LtOperand4`;

--
-- Table structure for table `spell_levels`
--
ALTER TABLE `spell_levels` MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `spell_misc`
--
ALTER TABLE `spell_misc`
  ADD `MinDuration` float NOT NULL DEFAULT 0 AFTER `LaunchDelay`,
  MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Speed` float NOT NULL DEFAULT 0 AFTER `SchoolMask`,
  MODIFY `LaunchDelay` float NOT NULL DEFAULT 0 AFTER `Speed`;

--
-- Table structure for table `spell_name`
--
DROP TABLE IF EXISTS `spell_name`;
CREATE TABLE `spell_name` (
  `ID` int(10) unsigned NOT NULL DEFAULT 0,
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_name_locale`
--
DROP TABLE IF EXISTS `spell_name_locale`;
CREATE TABLE `spell_name_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT 0,
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_power`
--
ALTER TABLE `spell_power`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 FIRST,
  MODIFY `ManaCost` int(11) NOT NULL DEFAULT 0 AFTER `OrderIndex`,
  MODIFY `ManaPerSecond` int(11) NOT NULL DEFAULT 0 AFTER `ManaCostPerLevel`,
  MODIFY `PowerDisplayID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ManaPerSecond`,
  MODIFY `AltPowerBarID` int(11) NOT NULL DEFAULT 0 AFTER `PowerDisplayID`,
  MODIFY `PowerCostPct` float NOT NULL DEFAULT 0 AFTER `AltPowerBarID`,
  MODIFY `PowerCostMaxPct` float NOT NULL DEFAULT 0 AFTER `PowerCostPct`,
  MODIFY `PowerPctPerSecond` float NOT NULL DEFAULT 0 AFTER `PowerCostMaxPct`,
  MODIFY `PowerType` tinyint(4) NOT NULL DEFAULT 0 AFTER `PowerPctPerSecond`,
  MODIFY `RequiredAuraSpellID` int(11) NOT NULL DEFAULT 0 AFTER `PowerType`,
  MODIFY `OptionalCost` int(10) unsigned NOT NULL DEFAULT 0 AFTER `RequiredAuraSpellID`;

--
-- Table structure for table `spell_power_difficulty`
--
ALTER TABLE `spell_power_difficulty` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 FIRST;

--
-- Table structure for table `spell_procs_per_minute_mod`
--
ALTER TABLE `spell_procs_per_minute_mod`
 MODIFY `Param` smallint(6) NOT NULL DEFAULT 0 AFTER `Type`,
 MODIFY `Coeff` float NOT NULL DEFAULT 0 AFTER `Param`;

--
-- Table structure for table `spell_range`
--
ALTER TABLE `spell_range` MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `DisplayNameShort`;

--
-- Table structure for table `spell_scaling`
--
ALTER TABLE `spell_scaling` MODIFY `ScalesFromItemLevel` smallint(6) NOT NULL DEFAULT 0 AFTER `MaxScalingLevel`;

--
-- Table structure for table `spell_shapeshift`
--
ALTER TABLE `spell_shapeshift` MODIFY `StanceBarOrder` tinyint(4) NOT NULL DEFAULT 0 AFTER `SpellID`;

--
-- Table structure for table `spell_shapeshift_form`
--
ALTER TABLE `spell_shapeshift_form`
  MODIFY `CreatureType` tinyint(4) NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `AttackIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `BonusActionBar` tinyint(4) NOT NULL DEFAULT 0 AFTER `AttackIconFileID`,
  MODIFY `DamageVariance` float NOT NULL DEFAULT 0 AFTER `CombatRoundTime`;

--
-- Table structure for table `spell_target_restrictions`
--
ALTER TABLE `spell_target_restrictions`
  MODIFY `ConeDegrees` float NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `TargetCreatureType` smallint(6) NOT NULL DEFAULT 0 AFTER `MaxTargetLevel`,
  MODIFY `Targets` int(11) NOT NULL DEFAULT 0 AFTER `TargetCreatureType`,
  MODIFY `Width` float NOT NULL DEFAULT 0 AFTER `Targets`;

--
-- Table structure for table `spell_totems`
--
ALTER TABLE `spell_totems`
  MODIFY `RequiredTotemCategoryID1` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `SpellID`,
  MODIFY `RequiredTotemCategoryID2` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `RequiredTotemCategoryID1`;

--
-- Table structure for table `spell_x_spell_visual`
--
ALTER TABLE `spell_x_spell_visual`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 FIRST,
  MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `SpellIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `Priority`,
  MODIFY `ActiveIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `SpellIconFileID`,
  MODIFY `ViewerUnitConditionID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ActiveIconFileID`,
  MODIFY `ViewerPlayerConditionID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ViewerUnitConditionID`,
  MODIFY `CasterUnitConditionID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ViewerPlayerConditionID`,
  MODIFY `CasterPlayerConditionID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `CasterUnitConditionID`;

--
-- Table structure for table `summon_properties`
--
ALTER TABLE `summon_properties` MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `Slot`;

--
-- Table structure for table `talent`
--
ALTER TABLE `talent`
  MODIFY `TierID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `TierID`,
  MODIFY `ColumnIndex` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `ClassID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ColumnIndex`,
  MODIFY `SpecID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ClassID`,
  MODIFY `SpellID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpecID`,
  MODIFY `OverridesSpellID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpellID`;

--
-- Table structure for table `taxi_nodes`
--
ALTER TABLE `taxi_nodes`
  ADD `VisibilityConditionID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpecialIconConditionID`,
  MODIFY `FlightMapOffsetY` float NOT NULL DEFAULT 0 AFTER `FlightMapOffsetX`,
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `FlightMapOffsetY`,
  MODIFY `Facing` float NOT NULL DEFAULT 0 AFTER `UiTextureKitID`,
  MODIFY `MountCreatureID1` int(11) NOT NULL DEFAULT 0 AFTER `VisibilityConditionID`,
  MODIFY `MountCreatureID2` int(11) NOT NULL DEFAULT 0 AFTER `MountCreatureID1`;

--
-- Table structure for table `taxi_path`
--
ALTER TABLE `taxi_path` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 FIRST;

--
-- Table structure for table `taxi_path_node`
--
ALTER TABLE `taxi_path_node`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `LocZ`,
  MODIFY `NodeIndex` int(11) NOT NULL DEFAULT 0 AFTER `PathID`,
  MODIFY `ContinentID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `NodeIndex`;

--
-- Table structure for table `totem_category`
--
ALTER TABLE `totem_category` MODIFY `TotemCategoryMask` int(11) NOT NULL DEFAULT 0 AFTER `TotemCategoryType`;

--
-- Table structure for table `toy`
--
ALTER TABLE `toy` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SourceText`;

--
-- Table structure for table `transmog_set`
--
ALTER TABLE `transmog_set`
  MODIFY `ClassMask` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `TrackingQuestID`,
  MODIFY `ItemNameDescriptionID` int(11) NOT NULL DEFAULT 0 AFTER `TransmogSetGroupID`,
  MODIFY `ParentTransmogSetID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ItemNameDescriptionID`,
  MODIFY `ExpansionID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `ParentTransmogSetID`,
  MODIFY `UiOrder` smallint(6) NOT NULL DEFAULT 0 AFTER `ExpansionID`;

--
-- Table structure for table `transport_animation`
--
ALTER TABLE `transport_animation` MODIFY `TimeIndex` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SequenceID`;

--
-- Table structure for table `transport_rotation`
--
ALTER TABLE `transport_rotation` MODIFY `TimeIndex` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Rot4`;

--
-- Table structure for table `ui_map`
--
DROP TABLE IF EXISTS `ui_map`;
CREATE TABLE `ui_map` (
  `Name` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ParentUiMapID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `System` int(11) NOT NULL DEFAULT '0',
  `Type` int(11) NOT NULL DEFAULT '0',
  `LevelRangeMin` int(10) unsigned NOT NULL DEFAULT '0',
  `LevelRangeMax` int(10) unsigned NOT NULL DEFAULT '0',
  `BountySetID` int(11) NOT NULL DEFAULT '0',
  `BountyDisplayLocation` int(10) unsigned NOT NULL DEFAULT '0',
  `VisibilityPlayerConditionID` int(11) NOT NULL DEFAULT '0',
  `HelpTextPosition` tinyint(4) NOT NULL DEFAULT '0',
  `BkgAtlasID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `ui_map_locale`
--
DROP TABLE IF EXISTS `ui_map_locale`;
CREATE TABLE `ui_map_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `ui_map_assignment`
--
DROP TABLE IF EXISTS `ui_map_assignment`;
CREATE TABLE `ui_map_assignment` (
  `UiMinX` float NOT NULL DEFAULT '0',
  `UiMinY` float NOT NULL DEFAULT '0',
  `UiMaxX` float NOT NULL DEFAULT '0',
  `UiMaxY` float NOT NULL DEFAULT '0',
  `Region1X` float NOT NULL DEFAULT '0',
  `Region1Y` float NOT NULL DEFAULT '0',
  `Region1Z` float NOT NULL DEFAULT '0',
  `Region2X` float NOT NULL DEFAULT '0',
  `Region2Y` float NOT NULL DEFAULT '0',
  `Region2Z` float NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `UiMapID` int(11) NOT NULL DEFAULT '0',
  `OrderIndex` int(11) NOT NULL DEFAULT '0',
  `MapID` int(11) NOT NULL DEFAULT '0',
  `AreaID` int(11) NOT NULL DEFAULT '0',
  `WmoDoodadPlacementID` int(11) NOT NULL DEFAULT '0',
  `WmoGroupID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `ui_map_link`
--
DROP TABLE IF EXISTS `ui_map_link`;
CREATE TABLE `ui_map_link` (
  `UiMinX` float NOT NULL DEFAULT '0',
  `UiMinY` float NOT NULL DEFAULT '0',
  `UiMaxX` float NOT NULL DEFAULT '0',
  `UiMaxY` float NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ParentUiMapID` int(11) NOT NULL DEFAULT '0',
  `OrderIndex` int(11) NOT NULL DEFAULT '0',
  `ChildUiMapID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `ui_map_x_map_art`
--
DROP TABLE IF EXISTS `ui_map_x_map_art`;
CREATE TABLE `ui_map_x_map_art` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `PhaseID` int(11) NOT NULL DEFAULT '0',
  `UiMapArtID` int(11) NOT NULL DEFAULT '0',
  `UiMapID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `unit_power_bar`
--
ALTER TABLE `unit_power_bar`
  MODIFY `MinPower` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ToolTip`,
  MODIFY `MaxPower` int(10) unsigned NOT NULL DEFAULT 0 AFTER `MinPower`,
  MODIFY `StartPower` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `MaxPower`,
  MODIFY `CenterPower` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `StartPower`,
  MODIFY `RegenerationPeace` float NOT NULL DEFAULT 0 AFTER `CenterPower`,
  MODIFY `BarType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `RegenerationCombat`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `BarType`,
  MODIFY `StartInset` float NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `EndInset` float NOT NULL DEFAULT 0 AFTER `StartInset`;

--
-- Table structure for table `vehicle`
--
ALTER TABLE `vehicle`
  MODIFY `FlagsB` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `UiLocomotionType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `CameraYawOffset`,
  MODIFY `VehicleUIIndicatorID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `UiLocomotionType`,
  MODIFY `MissileTargetingID` int(11) NOT NULL DEFAULT 0 AFTER `VehicleUIIndicatorID`;

--
-- Table structure for table `vehicle_seat`
--
ALTER TABLE `vehicle_seat`
  MODIFY `AttachmentOffsetX` float NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `AttachmentOffsetY` float NOT NULL DEFAULT 0 AFTER `AttachmentOffsetX`,
  MODIFY `AttachmentOffsetZ` float NOT NULL DEFAULT 0 AFTER `AttachmentOffsetY`,
  MODIFY `CameraOffsetX` float NOT NULL DEFAULT 0 AFTER `AttachmentOffsetZ`,
  MODIFY `CameraOffsetY` float NOT NULL DEFAULT 0 AFTER `CameraOffsetX`,
  MODIFY `CameraOffsetZ` float NOT NULL DEFAULT 0 AFTER `CameraOffsetY`,
  MODIFY `AttachmentID` tinyint(4) NOT NULL DEFAULT 0 AFTER `FlagsC`,
  MODIFY `EnterAnimStart` int(11) NOT NULL DEFAULT 0 AFTER `EnterMaxArcHeight`,
  MODIFY `EnterAnimLoop` int(11) NOT NULL DEFAULT 0 AFTER `EnterAnimStart`,
  MODIFY `RideAnimStart` int(11) NOT NULL DEFAULT 0 AFTER `EnterAnimLoop`,
  MODIFY `RideAnimLoop` int(11) NOT NULL DEFAULT 0 AFTER `RideAnimStart`,
  MODIFY `RideUpperAnimStart` int(11) NOT NULL DEFAULT 0 AFTER `RideAnimLoop`,
  MODIFY `RideUpperAnimLoop` int(11) NOT NULL DEFAULT 0 AFTER `RideUpperAnimStart`,
  MODIFY `ExitPreDelay` float NOT NULL DEFAULT 0 AFTER `RideUpperAnimLoop`,
  MODIFY `ExitAnimStart` int(11) NOT NULL DEFAULT 0 AFTER `ExitMaxArcHeight`,
  MODIFY `ExitAnimLoop` int(11) NOT NULL DEFAULT 0 AFTER `ExitAnimStart`,
  MODIFY `ExitAnimEnd` int(11) NOT NULL DEFAULT 0 AFTER `ExitAnimLoop`,
  MODIFY `VehicleEnterAnim` smallint(6) NOT NULL DEFAULT 0 AFTER `ExitAnimEnd`,
  MODIFY `VehicleEnterAnimBone` tinyint(4) NOT NULL DEFAULT 0 AFTER `VehicleEnterAnim`,
  MODIFY `VehicleExitAnim` smallint(6) NOT NULL DEFAULT 0 AFTER `VehicleEnterAnimBone`,
  MODIFY `VehicleExitAnimBone` tinyint(4) NOT NULL DEFAULT 0 AFTER `VehicleExitAnim`,
  MODIFY `VehicleRideAnimLoop` smallint(6) NOT NULL DEFAULT 0 AFTER `VehicleExitAnimBone`,
  MODIFY `VehicleRideAnimLoopBone` tinyint(4) NOT NULL DEFAULT 0 AFTER `VehicleRideAnimLoop`,
  MODIFY `PassengerAttachmentID` tinyint(4) NOT NULL DEFAULT 0 AFTER `VehicleRideAnimLoopBone`,
  MODIFY `PassengerYaw` float NOT NULL DEFAULT 0 AFTER `PassengerAttachmentID`,
  MODIFY `PassengerPitch` float NOT NULL DEFAULT 0 AFTER `PassengerYaw`,
  MODIFY `PassengerRoll` float NOT NULL DEFAULT 0 AFTER `PassengerPitch`,
  MODIFY `VehicleAbilityDisplay` tinyint(4) NOT NULL DEFAULT 0 AFTER `VehicleExitAnimDelay`,
  MODIFY `EnterUISoundID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `VehicleAbilityDisplay`,
  MODIFY `ExitUISoundID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `EnterUISoundID`,
  MODIFY `UiSkinFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `ExitUISoundID`,
  MODIFY `CameraEnteringDelay` float NOT NULL DEFAULT 0 AFTER `UiSkinFileDataID`;

--
-- Table structure for table `wmo_area_table`
--
ALTER TABLE `wmo_area_table`
  MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `AreaName`,
  MODIFY `WmoID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `NameSetID` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `WmoID`,
  MODIFY `WmoGroupID` int(11) NOT NULL DEFAULT 0 AFTER `NameSetID`,
  MODIFY `SoundProviderPref` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `WmoGroupID`,
  MODIFY `SoundProviderPrefUnderwater` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SoundProviderPref`,
  MODIFY `UwAmbience` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `AmbienceID`,
  MODIFY `UwZoneMusic` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ZoneMusic`,
  MODIFY `AreaTableID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `UwIntroSound`;

--
-- Table structure for table `world_effect`
--
ALTER TABLE `world_effect`
  MODIFY `QuestFeedbackEffectID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `TargetType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `WhenToDisplay`,
  MODIFY `TargetAsset` int(11) NOT NULL DEFAULT 0 AFTER `TargetType`,
  MODIFY `CombatConditionID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

--
-- Table structure for table `world_map_overlay`
--
ALTER TABLE `world_map_overlay`
  ADD `UiMapArtID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `HitRectBottom` int(11) NOT NULL DEFAULT 0 AFTER `HitRectTop`,
  DROP `TextureName`,
  DROP `MapAreaID`;

--
-- Table structure for table `world_safe_locs`
--
ALTER TABLE `world_safe_locs` MODIFY `Facing` float NOT NULL DEFAULT 0 AFTER `MapID`;

DROP TABLE `garr_plot_locale`;
DROP TABLE `pvp_reward`;
DROP TABLE `pvp_talent_unlock`;
DROP TABLE `sandbox_scaling`;
DROP TABLE `spell`;
DROP TABLE `spell_locale`;
DROP TABLE `world_map_area`;
DROP TABLE `world_map_transforms`;
