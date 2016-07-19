ALTER TABLE `achievement`
  MODIFY `Title` text NULL FIRST,
  MODIFY `Description` text NULL AFTER `Title`,
  MODIFY `Flags` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Description`,
  MODIFY `Reward` text NULL AFTER `Flags`,
  MODIFY `MapID` smallint(6) NOT NULL DEFAULT '0' AFTER `Reward`,
  MODIFY `Supercedes` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MapID`,
  MODIFY `Category` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Supercedes`,
  MODIFY `UIOrder` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Category`,
  MODIFY `IconID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `UIOrder`,
  MODIFY `SharesCriteria` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `IconID`,
  MODIFY `CriteriaTree` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SharesCriteria`,
  MODIFY `Faction` tinyint(4) NOT NULL DEFAULT '0' AFTER `CriteriaTree`,
  MODIFY `Points` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Faction`,
  MODIFY `MinimumCriteria` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Points`;

ALTER TABLE `area_table`
  CHANGE `PvPCombastWorldStateID` `PvPCombatWorldStateID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `UWAmbience`,
  CHANGE `UWIntroMusic` `UWIntroSound` int(10) unsigned NOT NULL DEFAULT '0' AFTER `WindSettingsID`;

ALTER TABLE `area_trigger`
  MODIFY `PosX` float NOT NULL DEFAULT '0' FIRST,
  MODIFY `PosY` float NOT NULL DEFAULT '0' AFTER `PosX`,
  MODIFY `PosZ` float NOT NULL DEFAULT '0' AFTER `PosY`,
  MODIFY `Radius` float NOT NULL DEFAULT '0' AFTER `PosZ`,
  MODIFY `BoxLength` float NOT NULL DEFAULT '0' AFTER `Radius`,
  MODIFY `BoxWidth` float NOT NULL DEFAULT '0' AFTER `BoxLength`,
  MODIFY `BoxHeight` float NOT NULL DEFAULT '0' AFTER `BoxWidth`,
  MODIFY `BoxYaw` float NOT NULL DEFAULT '0' AFTER `BoxHeight`,
  MODIFY `MapID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `BoxYaw`,
  MODIFY `PhaseID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MapID`,
  MODIFY `PhaseGroupID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PhaseID`,
  MODIFY `ShapeID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PhaseGroupID`,
  MODIFY `AreaTriggerActionSetID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ShapeID`,
  MODIFY `PhaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AreaTriggerActionSetID`,
  MODIFY `ShapeType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PhaseUseFlags`,
  MODIFY `Flag` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ShapeType`;

ALTER TABLE `barber_shop_style`
  MODIFY `DisplayName` text NULL FIRST,
  MODIFY `Description` text NULL AFTER `DisplayName`,
  MODIFY `CostModifier` float NOT NULL DEFAULT '0' AFTER `Description`,
  MODIFY `Type` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CostModifier`,
  MODIFY `Race` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Type`,
  MODIFY `Sex` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Race`,
  MODIFY `Data` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Sex`;

ALTER TABLE `battle_pet_species`
  MODIFY `CreatureID` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `IconFileID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CreatureID`,
  MODIFY `SummonSpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `IconFileID`,
  MODIFY `SourceText` text NULL AFTER `SummonSpellID`,
  MODIFY `Description` text NULL AFTER `SourceText`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Description`,
  MODIFY `PetType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `Source` tinyint(4) NOT NULL DEFAULT '0' AFTER `PetType`;

ALTER TABLE `broadcast_text`
  CHANGE `SoundID` `SoundID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Type`,
  ADD `SoundID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SoundID1`,
  ADD `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SoundID2`;

ALTER TABLE `chr_classes`
  MODIFY `PetNameToken` text NULL FIRST,
  MODIFY `Name` text NULL AFTER `PetNameToken`,
  MODIFY `NameFemale` text NULL AFTER `Name`,
  MODIFY `NameMale` text NULL AFTER `NameFemale`,
  MODIFY `Filename` text NULL AFTER `NameMale`,
  MODIFY `CreateScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Filename`,
  MODIFY `SelectScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CreateScreenFileDataID`,
  MODIFY `LowResScreenFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SelectScreenFileDataID`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `LowResScreenFileDataID`,
  MODIFY `CinematicSequenceID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `DefaultSpec` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CinematicSequenceID`,
  MODIFY `PowerType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DefaultSpec`,
  MODIFY `SpellClassSet` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PowerType`,
  MODIFY `AttackPowerPerStrength` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SpellClassSet`,
  MODIFY `AttackPowerPerAgility` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AttackPowerPerStrength`,
  MODIFY `RangedAttackPowerPerAgility` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AttackPowerPerAgility`,
  MODIFY `IconFileDataID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RangedAttackPowerPerAgility`,
  MODIFY `Unk1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `IconFileDataID`;

ALTER TABLE `chr_races`
  MODIFY `Unk` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `UAFemaleCreatureSoundDataID`,
  MODIFY `BaseLanguage` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Unk`,
  MODIFY `CreatureType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `BaseLanguage`,
  MODIFY `TeamID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CreatureType`,
  MODIFY `RaceRelated` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `TeamID`,
  MODIFY `UnalteredVisualRaceID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RaceRelated`,
  MODIFY `CharComponentTextureLayoutID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `UnalteredVisualRaceID`,
  MODIFY `DefaultClassID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CharComponentTextureLayoutID`,
  MODIFY `NeutralRaceID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DefaultClassID`,
  MODIFY `ItemAppearanceFrameRaceID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `NeutralRaceID`,
  MODIFY `CharComponentTexLayoutHiResID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ItemAppearanceFrameRaceID`,
  MODIFY `HighResMaleDisplayID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CharComponentTexLayoutHiResID`,
  MODIFY `HighResFemaleDisplayID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HighResMaleDisplayID`;

ALTER TABLE `chr_specialization`
  MODIFY `MasterySpellID1` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `MasterySpellID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MasterySpellID1`,
  MODIFY `Name` text NULL AFTER `MasterySpellID2`,
  MODIFY `Name2` text NULL AFTER `Name`,
  MODIFY `Description` text NULL AFTER `Name2`,
  MODIFY `BackgroundFile` text NULL AFTER `Description`,
  MODIFY `SpellIconID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `BackgroundFile`,
  MODIFY `ClassID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SpellIconID`,
  MODIFY `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ClassID`,
  MODIFY `PetTalentType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `OrderIndex`,
  MODIFY `Role` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PetTalentType`,
  MODIFY `PrimaryStatOrder` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Role`;

ALTER TABLE `creature_model_data`
  MODIFY `ModelScale` float NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `FootprintTextureLength` float NOT NULL DEFAULT '0' AFTER `ModelScale`,
  MODIFY `FootprintTextureWidth` float NOT NULL DEFAULT '0' AFTER `FootprintTextureLength`,
  MODIFY `FootprintParticleScale` float NOT NULL DEFAULT '0' AFTER `FootprintTextureWidth`,
  MODIFY `CollisionWidth` float NOT NULL DEFAULT '0' AFTER `FootprintParticleScale`,
  MODIFY `CollisionHeight` float NOT NULL DEFAULT '0' AFTER `CollisionWidth`,
  MODIFY `MountHeight` float NOT NULL DEFAULT '0' AFTER `CollisionHeight`,
  MODIFY `GeoBoxMin1` float NOT NULL DEFAULT '0' AFTER `MountHeight`,
  MODIFY `GeoBoxMin2` float NOT NULL DEFAULT '0' AFTER `GeoBoxMin1`,
  MODIFY `GeoBoxMin3` float NOT NULL DEFAULT '0' AFTER `GeoBoxMin2`,
  MODIFY `GeoBoxMax1` float NOT NULL DEFAULT '0' AFTER `GeoBoxMin3`,
  MODIFY `GeoBoxMax2` float NOT NULL DEFAULT '0' AFTER `GeoBoxMax1`,
  MODIFY `GeoBoxMax3` float NOT NULL DEFAULT '0' AFTER `GeoBoxMax2`,
  MODIFY `WorldEffectScale` float NOT NULL DEFAULT '0' AFTER `GeoBoxMax3`,
  MODIFY `AttachedEffectScale` float NOT NULL DEFAULT '0' AFTER `WorldEffectScale`,
  MODIFY `MissileCollisionRadius` float NOT NULL DEFAULT '0' AFTER `AttachedEffectScale`,
  MODIFY `MissileCollisionPush` float NOT NULL DEFAULT '0' AFTER `MissileCollisionRadius`,
  MODIFY `MissileCollisionRaise` float NOT NULL DEFAULT '0' AFTER `MissileCollisionPush`,
  MODIFY `OverrideLootEffectScale` float NOT NULL DEFAULT '0' AFTER `MissileCollisionRaise`,
  MODIFY `OverrideNameScale` float NOT NULL DEFAULT '0' AFTER `OverrideLootEffectScale`,
  MODIFY `OverrideSelectionRadius` float NOT NULL DEFAULT '0' AFTER `OverrideNameScale`,
  MODIFY `TamedPetBaseScale` float NOT NULL DEFAULT '0' AFTER `OverrideSelectionRadius`,
  MODIFY `HoverHeight` float NOT NULL DEFAULT '0' AFTER `TamedPetBaseScale`,
  MODIFY `SizeClass` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FileDataID`,
  MODIFY `BloodID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SizeClass`,
  MODIFY `FootprintTextureID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `BloodID`,
  MODIFY `FoleyMaterialID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FootprintTextureID`,
  CHANGE `Unk700_1` `FootstepEffectID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FoleyMaterialID`,
  CHANGE `Unk700_2` `DeathThudEffectID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FootstepEffectID`,
  MODIFY `FootstepShakeSize` int(10) unsigned NOT NULL DEFAULT '0' AFTER `DeathThudEffectID`,
  MODIFY `DeathThudShakeSize` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FootstepShakeSize`,
  MODIFY `SoundID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `DeathThudShakeSize`,
  MODIFY `CreatureGeosetDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SoundID`;

ALTER TABLE `criteria_tree`
  MODIFY `CriteriaID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `Operator` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `OrderIndex` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Operator`;

ALTER TABLE `currency_types`
  MODIFY `SpellCategory` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CategoryID`,
  MODIFY `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SpellCategory`,
  MODIFY `SpellWeight` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Quality`;

ALTER TABLE `dungeon_encounter`
  MODIFY `SpellIconID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MapID`,
  MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SpellIconID`,
  MODIFY `Bit` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DifficultyID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Bit`,
  MODIFY `OrderIndex` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Flags`;

ALTER TABLE `emotes`
  MODIFY `EmoteSpecProc` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AnimID`,
  MODIFY `EmoteSpecProcParam` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EmoteSpecProc`,
  MODIFY `EmoteSoundID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EmoteSpecProcParam`,
  CHANGE `Unk703_1` `ClassMask` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EmoteSoundID`,
  CHANGE `Unk703_2` `RaceMask` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ClassMask`;

ALTER TABLE `emotes_text_sound`
  MODIFY `RaceId` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `EmotesTextId`,
  MODIFY `SexId` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RaceId`,
  MODIFY `ClassId` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SexId`,
  MODIFY `SoundId` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ClassId`;

ALTER TABLE `faction`
  ADD `ReputationMax1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Description`,
  ADD `ReputationMax2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ReputationMax1`,
  ADD `ReputationMax3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ReputationMax2`,
  ADD `ReputationMax4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ReputationMax3`;

ALTER TABLE `gameobjects`
  MODIFY `PositionX` float NOT NULL DEFAULT '0' FIRST,
  MODIFY `PositionY` float NOT NULL DEFAULT '0' AFTER `PositionX`,
  MODIFY `PositionZ` float NOT NULL DEFAULT '0' AFTER `PositionY`,
  MODIFY `RotationX` float NOT NULL DEFAULT '0' AFTER `PositionZ`,
  MODIFY `RotationY` float NOT NULL DEFAULT '0' AFTER `RotationX`,
  MODIFY `RotationZ` float NOT NULL DEFAULT '0' AFTER `RotationY`,
  MODIFY `RotationW` float NOT NULL DEFAULT '0' AFTER `RotationZ`,
  MODIFY `Size` float NOT NULL DEFAULT '0' AFTER `RotationW`,
  MODIFY `Data1` int(11) NOT NULL DEFAULT '0' AFTER `Size`,
  MODIFY `Data2` int(11) NOT NULL DEFAULT '0' AFTER `Data1`,
  MODIFY `Data3` int(11) NOT NULL DEFAULT '0' AFTER `Data2`,
  MODIFY `Data4` int(11) NOT NULL DEFAULT '0' AFTER `Data3`,
  MODIFY `Data5` int(11) NOT NULL DEFAULT '0' AFTER `Data4`,
  MODIFY `Data6` int(11) NOT NULL DEFAULT '0' AFTER `Data5`,
  MODIFY `Data7` int(11) NOT NULL DEFAULT '0' AFTER `Data6`,
  MODIFY `Data8` int(11) NOT NULL DEFAULT '0' AFTER `Data7`,
  MODIFY `Name` text NULL AFTER `Data8`,
  MODIFY `MapID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Name`,
  MODIFY `DisplayID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MapID`,
  MODIFY `PhaseID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `DisplayID`,
  MODIFY `PhaseGroupID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PhaseID`,
  MODIFY `PhaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PhaseGroupID`,
  MODIFY `Type` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PhaseUseFlags`;

ALTER TABLE `garr_ability`
  MODIFY `Name` text NULL FIRST,
  MODIFY `Description` text NULL AFTER `Name`,
  MODIFY `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Description`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `IconFileDataID`,
  MODIFY `OtherFactionGarrAbilityID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `GarrAbilityCategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `OtherFactionGarrAbilityID`,
  MODIFY `FollowerTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `GarrAbilityCategoryID`;

ALTER TABLE `garr_building`
  MODIFY `CostCurrencyID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `IconFileDataID`,
  MODIFY `HordeTexPrefixKitID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CostCurrencyID`,
  MODIFY `AllianceTexPrefixKitID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `HordeTexPrefixKitID`,
  MODIFY `AllianceActivationScenePackageID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AllianceTexPrefixKitID`,
  MODIFY `HordeActivationScenePackageID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AllianceActivationScenePackageID`,
  MODIFY `FollowerRequiredGarrAbilityID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `HordeActivationScenePackageID`,
  MODIFY `FollowerGarrAbilityEffectID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `FollowerRequiredGarrAbilityID`,
  MODIFY `CostMoney` smallint(6) NOT NULL DEFAULT '0' AFTER `FollowerGarrAbilityEffectID`,
  MODIFY `Unknown` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CostMoney`,
  MODIFY `Type` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Unknown`,
  MODIFY `Level` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Type`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Level`,
  MODIFY `MaxShipments` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `GarrTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxShipments`,
  MODIFY `BuildDuration` int(10) unsigned NOT NULL DEFAULT '0' AFTER `GarrTypeID`,
  MODIFY `CostCurrencyAmount` int(11) NOT NULL DEFAULT '0' AFTER `BuildDuration`,
  MODIFY `BonusAmount` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CostCurrencyAmount`;

ALTER TABLE `garr_building_plot_inst`
  MODIFY `LandmarkOffsetX` float NOT NULL DEFAULT '0' FIRST,
  MODIFY `LandmarkOffsetY` float NOT NULL DEFAULT '0' AFTER `LandmarkOffsetX`,
  MODIFY `UiTextureAtlasMemberID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `LandmarkOffsetY`,
  MODIFY `GarrSiteLevelPlotInstID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `UiTextureAtlasMemberID`,
  MODIFY `GarrBuildingID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `GarrSiteLevelPlotInstID`;

ALTER TABLE `garr_class_spec`
  MODIFY `NameMale` text NULL FIRST,
  MODIFY `NameFemale` text NULL AFTER `NameMale`,
  MODIFY `NameGenderless` text NULL AFTER `NameFemale`,
  MODIFY `ClassAtlasID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `NameGenderless`,
  MODIFY `GarrFollItemSetID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ClassAtlasID`,
  MODIFY `Limit` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `GarrFollItemSetID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Limit`;

ALTER TABLE `garr_follower`
  MODIFY `HordeCreatureID` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `AllianceCreatureID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HordeCreatureID`,
  MODIFY `HordeSourceText` text NULL AFTER `AllianceCreatureID`,
  MODIFY `AllianceSourceText` text NULL AFTER `HordeSourceText`,
  MODIFY `HordePortraitIconID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AllianceSourceText`,
  MODIFY `AlliancePortraitIconID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HordePortraitIconID`,
  ADD `HordeAddedBroadcastTextID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AlliancePortraitIconID`,
  ADD `AllianceAddedBroadcastTextID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HordeAddedBroadcastTextID`,
  MODIFY `HordeGarrFollItemSetID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AllianceAddedBroadcastTextID`,
  MODIFY `AllianceGarrFollItemSetID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `HordeGarrFollItemSetID`,
  MODIFY `ItemLevelWeapon` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AllianceGarrFollItemSetID`,
  MODIFY `ItemLevelArmor` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ItemLevelWeapon`,
  MODIFY `HordeListPortraitTextureKitID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ItemLevelArmor`,
  MODIFY `AllianceListPortraitTextureKitID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `HordeListPortraitTextureKitID`,
  MODIFY `FollowerTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AllianceListPortraitTextureKitID`,
  MODIFY `HordeUiAnimRaceInfoID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `FollowerTypeID`,
  MODIFY `AllianceUiAnimRaceInfoID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `HordeUiAnimRaceInfoID`,
  MODIFY `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AllianceUiAnimRaceInfoID`,
  MODIFY `HordeGarrClassSpecID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Quality`,
  MODIFY `AllianceGarrClassSpecID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `HordeGarrClassSpecID`,
  MODIFY `Level` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AllianceGarrClassSpecID`,
  MODIFY `Unknown1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Level`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Unknown1`,
  MODIFY `Unknown2` tinyint(4) NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `Unknown3` tinyint(4) NOT NULL DEFAULT '0' AFTER `Unknown2`,
  MODIFY `GarrTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Unknown3`,
  MODIFY `MaxDurability` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `GarrTypeID`,
  MODIFY `Class` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxDurability`,
  ADD `HordeFlavorTextGarrStringID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Class`,
  ADD `AllianceFlavorTextGarrStringID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `HordeFlavorTextGarrStringID`;

ALTER TABLE `garr_plot`
  MODIFY `GarrPlotUICategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `HordeConstructionGameObjectID`,
  MODIFY `PlotType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `GarrPlotUICategoryID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PlotType`,
  MODIFY `MinCount` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `MaxCount` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MinCount`;

ALTER TABLE `garr_site_level` MODIFY `SiteID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MapID`;

ALTER TABLE `heirloom`
  MODIFY `ItemID` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `SourceText` text NULL AFTER `ItemID`,
  MODIFY `OldItem1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SourceText`,
  MODIFY `OldItem2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `OldItem1`,
  MODIFY `NextDifficultyItemID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `OldItem2`,
  MODIFY `UpgradeItemID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `NextDifficultyItemID`,
  MODIFY `UpgradeItemID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `UpgradeItemID1`,
  MODIFY `ItemBonusListID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `UpgradeItemID2`,
  MODIFY `ItemBonusListID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ItemBonusListID1`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ItemBonusListID2`,
  MODIFY `Source` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Flags`;

ALTER TABLE `item_extended_cost` DROP `RequiredMoney`;

ALTER TABLE `item_modified_appearance`
  MODIFY `ItemID` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `AppearanceID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ItemID`,
  MODIFY `AppearanceModID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AppearanceID`,
  MODIFY `Index` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AppearanceModID`,
  MODIFY `SourceType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Index`;

ALTER TABLE `item_set`
  MODIFY `RequiredSkill` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RequiredSkillRank`,
  CHANGE `Unknown703` `Flags` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RequiredSkill`;

ALTER TABLE `lfg_dungeons`
  MODIFY `Name` text NULL FIRST,
  MODIFY `Flags` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Name`,
  MODIFY `TextureFilename` text NULL AFTER `Flags`,
  MODIFY `Description` text NULL AFTER `TextureFilename`,
  MODIFY `MaxLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Description`,
  MODIFY `TargetLevelMax` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxLevel`,
  MODIFY `MapID` smallint(6) NOT NULL DEFAULT '0' AFTER `TargetLevelMax`,
  MODIFY `RandomID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MapID`,
  MODIFY `ScenarioID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `RandomID`,
  MODIFY `LastBossJournalEncounterID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ScenarioID`,
  MODIFY `BonusReputationAmount` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `LastBossJournalEncounterID`,
  MODIFY `MentorItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `BonusReputationAmount`,
  MODIFY `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MentorItemLevel`,
  MODIFY `TargetLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinLevel`,
  MODIFY `TargetLevelMin` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `TargetLevel`,
  MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `TargetLevelMin`,
  MODIFY `Type` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DifficultyID`,
  MODIFY `Faction` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Type`,
  MODIFY `Expansion` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Faction`,
  MODIFY `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Expansion`,
  MODIFY `GroupID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `OrderIndex`,
  MODIFY `CountTank` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `GroupID`,
  MODIFY `CountHealer` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CountTank`,
  MODIFY `CountDamage` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CountHealer`,
  MODIFY `MinCountTank` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CountDamage`,
  MODIFY `MinCountHealer` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinCountTank`,
  MODIFY `MinCountDamage` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinCountHealer`,
  MODIFY `SubType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinCountDamage`,
  MODIFY `MentorCharLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SubType`;

ALTER TABLE `liquid_type`
  MODIFY `LightID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `Type` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LightID`,
  MODIFY `ParticleMovement` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Type`,
  MODIFY `ParticleTexSlots` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ParticleMovement`,
  MODIFY `MaterialID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ParticleTexSlots`,
  MODIFY `DepthTexCount1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaterialID`,
  MODIFY `DepthTexCount2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DepthTexCount1`,
  MODIFY `DepthTexCount3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DepthTexCount2`,
  MODIFY `DepthTexCount4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DepthTexCount3`,
  MODIFY `DepthTexCount5` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DepthTexCount4`,
  MODIFY `DepthTexCount6` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DepthTexCount5`,
  MODIFY `SoundID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `DepthTexCount6`;

ALTER TABLE `map_difficulty`
  MODIFY `MapID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Message`,
  MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MapID`,
  MODIFY `RaidDurationType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DifficultyID`,
  MODIFY `MaxPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RaidDurationType`,
  MODIFY `LockID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxPlayers`,
  MODIFY `ItemBonusTreeModID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LockID`;

ALTER TABLE `mount`
  MODIFY `SpellId` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `DisplayId` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SpellId`,
  MODIFY `Name` text NULL AFTER `DisplayId`,
  MODIFY `Description` text NULL AFTER `Name`,
  MODIFY `SourceDescription` text NULL AFTER `Description`,
  ADD `CameraPivotMultiplier` float NOT NULL DEFAULT '0' AFTER `SourceDescription`,
  MODIFY `MountTypeId` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CameraPivotMultiplier`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MountTypeId`,
  MODIFY `PlayerConditionId` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `Source` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PlayerConditionId`;

ALTER TABLE `mount_capability`
  MODIFY `RequiredSpell` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `SpeedModSpell` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RequiredSpell`,
  MODIFY `RequiredRidingSkill` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SpeedModSpell`,
  MODIFY `RequiredArea` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `RequiredRidingSkill`,
  MODIFY `RequiredMap` smallint(6) NOT NULL DEFAULT '0' AFTER `RequiredArea`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RequiredMap`;

ALTER TABLE `player_condition`
  MODIFY `ItemLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SpellLogic`,
  MODIFY `Time1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemLogic`,
  MODIFY `Time2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Time1`,
  MODIFY `AuraSpellLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Time2`,
  MODIFY `AuraSpellID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AuraSpellLogic`,
  MODIFY `AuraSpellID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AuraSpellID1`,
  MODIFY `AuraSpellID3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AuraSpellID2`,
  MODIFY `AuraSpellID4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AuraSpellID3`,
  MODIFY `AchievementLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AuraSpellID4`,
  MODIFY `AreaLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AchievementLogic`,
  MODIFY `QuestKillLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AreaLogic`,
  MODIFY `FailureDescription` text NULL AFTER `QuestKillLogic`,
  MODIFY `MinLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `FailureDescription`,
  MODIFY `MaxLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinLevel`,
  MODIFY `SkillID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxLevel`,
  MODIFY `SkillID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SkillID1`,
  MODIFY `SkillID3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SkillID2`,
  MODIFY `SkillID4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SkillID3`,
  MODIFY `MinSkill1` smallint(6) NOT NULL DEFAULT '0' AFTER `SkillID4`,
  MODIFY `MinSkill2` smallint(6) NOT NULL DEFAULT '0' AFTER `MinSkill1`,
  MODIFY `MinSkill3` smallint(6) NOT NULL DEFAULT '0' AFTER `MinSkill2`,
  MODIFY `MinSkill4` smallint(6) NOT NULL DEFAULT '0' AFTER `MinSkill3`,
  MODIFY `MaxSkill1` smallint(6) NOT NULL DEFAULT '0' AFTER `MinSkill4`,
  MODIFY `MaxSkill2` smallint(6) NOT NULL DEFAULT '0' AFTER `MaxSkill1`,
  MODIFY `MaxSkill3` smallint(6) NOT NULL DEFAULT '0' AFTER `MaxSkill2`,
  MODIFY `MaxSkill4` smallint(6) NOT NULL DEFAULT '0' AFTER `MaxSkill3`,
  MODIFY `MaxFactionID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxSkill4`,
  MODIFY `PrevQuestID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxFactionID`,
  MODIFY `PrevQuestID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PrevQuestID1`,
  MODIFY `PrevQuestID3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PrevQuestID2`,
  MODIFY `PrevQuestID4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PrevQuestID3`,
  MODIFY `CurrQuestID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PrevQuestID4`,
  MODIFY `CurrQuestID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrQuestID1`,
  MODIFY `CurrQuestID3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrQuestID2`,
  MODIFY `CurrQuestID4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrQuestID3`,
  MODIFY `CurrentCompletedQuestID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrQuestID4`,
  MODIFY `CurrentCompletedQuestID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID1`,
  MODIFY `CurrentCompletedQuestID3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID2`,
  MODIFY `CurrentCompletedQuestID4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID3`,
  MODIFY `Explored1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID4`,
  MODIFY `Explored2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Explored1`,
  MODIFY `WorldStateExpressionID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Explored2`,
  MODIFY `Achievement1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `WorldStateExpressionID`,
  MODIFY `Achievement2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Achievement1`,
  MODIFY `Achievement3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Achievement2`,
  MODIFY `Achievement4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Achievement3`,
  MODIFY `AreaID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Achievement4`,
  MODIFY `AreaID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AreaID1`,
  MODIFY `AreaID3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AreaID2`,
  MODIFY `AreaID4` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AreaID3`,
  MODIFY `QuestKillID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AreaID4`,
  MODIFY `PhaseID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `QuestKillID`,
  MODIFY `MinAvgEquippedItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PhaseID`,
  MODIFY `MaxAvgEquippedItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinAvgEquippedItemLevel`,
  MODIFY `ModifierTreeID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MaxAvgEquippedItemLevel`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ModifierTreeID`,
  MODIFY `Gender` tinyint(4) NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `NativeGender` tinyint(4) NOT NULL DEFAULT '0' AFTER `Gender`,
  MODIFY `MinLanguage` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `NativeGender`,
  MODIFY `MaxLanguage` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinLanguage`,
  MODIFY `MinReputation1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxLanguage`,
  MODIFY `MinReputation2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinReputation1`,
  MODIFY `MinReputation3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinReputation2`,
  MODIFY `MaxReputation` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinReputation3`,
  MODIFY `Unknown1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxReputation`,
  MODIFY `MinPVPRank` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Unknown1`,
  MODIFY `MaxPVPRank` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinPVPRank`,
  MODIFY `PvpMedal` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxPVPRank`,
  MODIFY `ItemFlags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PvpMedal`,
  MODIFY `AuraCount1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ItemFlags`,
  MODIFY `AuraCount2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AuraCount1`,
  MODIFY `AuraCount3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AuraCount2`,
  MODIFY `AuraCount4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AuraCount3`,
  MODIFY `WeatherID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AuraCount4`,
  MODIFY `PartyStatus` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `WeatherID`,
  MODIFY `LifetimeMaxPVPRank` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PartyStatus`,
  MODIFY `LfgStatus1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LifetimeMaxPVPRank`,
  MODIFY `LfgStatus2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgStatus1`,
  MODIFY `LfgStatus3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgStatus2`,
  MODIFY `LfgStatus4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgStatus3`,
  MODIFY `LfgCompare1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgStatus4`,
  MODIFY `LfgCompare2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgCompare1`,
  MODIFY `LfgCompare3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgCompare2`,
  MODIFY `LfgCompare4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgCompare3`,
  MODIFY `CurrencyCount1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LfgCompare4`,
  MODIFY `CurrencyCount2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyCount1`,
  MODIFY `CurrencyCount3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyCount2`,
  MODIFY `CurrencyCount4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyCount3`,
  MODIFY `MinExpansionLevel` tinyint(4) NOT NULL DEFAULT '0' AFTER `CurrencyCount4`,
  MODIFY `MaxExpansionLevel` tinyint(4) NOT NULL DEFAULT '0' AFTER `MinExpansionLevel`,
  MODIFY `MinExpansionTier` tinyint(4) NOT NULL DEFAULT '0' AFTER `MaxExpansionLevel`,
  MODIFY `MaxExpansionTier` tinyint(4) NOT NULL DEFAULT '0' AFTER `MinExpansionTier`,
  MODIFY `MinGuildLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxExpansionTier`,
  MODIFY `MaxGuildLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinGuildLevel`,
  MODIFY `PhaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MaxGuildLevel`,
  MODIFY `ChrSpecializationIndex` tinyint(4) NOT NULL DEFAULT '0' AFTER `PhaseUseFlags`,
  MODIFY `ChrSpecializationRole` tinyint(4) NOT NULL DEFAULT '0' AFTER `ChrSpecializationIndex`,
  MODIFY `PowerType` tinyint(4) NOT NULL DEFAULT '0' AFTER `ChrSpecializationRole`,
  MODIFY `PowerTypeComp` tinyint(4) NOT NULL DEFAULT '0' AFTER `PowerType`,
  MODIFY `PowerTypeValue` tinyint(4) NOT NULL DEFAULT '0' AFTER `PowerTypeComp`,
  MODIFY `ClassMask` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PowerTypeValue`,
  MODIFY `LanguageID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ClassMask`,
  MODIFY `MinFactionID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LanguageID`,
  MODIFY `MinFactionID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MinFactionID1`,
  MODIFY `MinFactionID3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MinFactionID2`,
  MODIFY `ItemCount1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemID4`,
  MODIFY `ItemCount2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemCount1`,
  MODIFY `ItemCount3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemCount2`,
  MODIFY `ItemCount4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemCount3`,
  MODIFY `LfgLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemCount4`,
  MODIFY `LfgValue1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LfgLogic`,
  MODIFY `LfgValue2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LfgValue1`,
  MODIFY `LfgValue3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LfgValue2`,
  MODIFY `LfgValue4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LfgValue3`,
  MODIFY `CurrencyLogic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LfgValue4`,
  MODIFY `CurrencyID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyLogic`,
  MODIFY `CurrencyID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyID1`,
  MODIFY `CurrencyID3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyID2`,
  MODIFY `CurrencyID4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyID3`,
  MODIFY `PhaseGroupID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `QuestKillMonster6`,
  MODIFY `MinAvgItemLevel` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PhaseGroupID`,
  MODIFY `MaxAvgItemLevel` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MinAvgItemLevel`,
  MODIFY `Unknown700_1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MaxAvgItemLevel`,
  MODIFY `Unknown700_2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Unknown700_1`;

ALTER TABLE `scaling_stat_distribution`
  MODIFY `MinLevel` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ItemLevelCurveID`,
  MODIFY `MaxLevel` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MinLevel`;

ALTER TABLE `skill_line` MODIFY `ParentSkillLineID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CanLink`;

ALTER TABLE `skill_line_ability`
  MODIFY `SupercedesSpell` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RaceMask`,
  ADD `Unknown703` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SupercedesSpell`,
  MODIFY `SkillLine` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Unknown703`,
  MODIFY `MinSkillLineRank` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SkillLine`,
  MODIFY `TrivialSkillLineRankHigh` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MinSkillLineRank`,
  MODIFY `TrivialSkillLineRankLow` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `TrivialSkillLineRankHigh`,
  MODIFY `UniqueBit` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `TrivialSkillLineRankLow`,
  MODIFY `TradeSkillCategoryID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `UniqueBit`,
  MODIFY `AquireMethod` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `TradeSkillCategoryID`,
  MODIFY `NumSkillUps` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `AquireMethod`;

ALTER TABLE `skill_race_class_info`
  MODIFY `SkillID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `RaceMask`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SkillID`,
  MODIFY `SkillTierID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `Availability` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SkillTierID`,
  MODIFY `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Availability`;

ALTER TABLE `sound_kit`
  MODIFY `Name` text NULL FIRST,
  MODIFY `VolumeFloat` float NOT NULL DEFAULT '0' AFTER `Name`,
  MODIFY `MinDistance` float NOT NULL DEFAULT '0' AFTER `VolumeFloat`,
  MODIFY `DistanceCutoff` float NOT NULL DEFAULT '0' AFTER `MinDistance`,
  MODIFY `VolumeVariationPlus` float NOT NULL DEFAULT '0' AFTER `DistanceCutoff`,
  MODIFY `VolumeVariationMinus` float NOT NULL DEFAULT '0' AFTER `VolumeVariationPlus`,
  MODIFY `PitchVariationPlus` float NOT NULL DEFAULT '0' AFTER `VolumeVariationMinus`,
  MODIFY `PitchVariationMinus` float NOT NULL DEFAULT '0' AFTER `PitchVariationPlus`,
  MODIFY `PitchAdjust` float NOT NULL DEFAULT '0' AFTER `PitchVariationMinus`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PitchAdjust`,
  MODIFY `SoundEntriesAdvancedID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `BusOverwriteID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SoundEntriesAdvancedID`,
  MODIFY `SoundType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `BusOverwriteID`,
  MODIFY `EAXDef` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SoundType`,
  MODIFY `DialogType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `EAXDef`,
  MODIFY `Unk700` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DialogType`;

ALTER TABLE `specialization_spells`
  MODIFY `SpellID` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `OverridesSpellID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SpellID`,
  MODIFY `Description` text NULL AFTER `OverridesSpellID`,
  MODIFY `SpecID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Description`,
  MODIFY `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SpecID`;

ALTER TABLE `spell`
  MODIFY `Name` text NULL FIRST,
  MODIFY `NameSubtext` text NULL AFTER `Name`,
  MODIFY `Description` text NULL AFTER `NameSubtext`,
  MODIFY `AuraDescription` text NULL AFTER `Description`,
  MODIFY `MiscID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AuraDescription`,
  MODIFY `DescriptionVariablesID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`;

ALTER TABLE `spell_category`
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ChargeRecoveryTime`,
  MODIFY `UsesPerWeek` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `MaxCharges` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `UsesPerWeek`;

ALTER TABLE `spell_class_options`
  MODIFY `SpellClassSet` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SpellClassMask4`,
  MODIFY `ModalNextSpell` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SpellClassSet`;

ALTER TABLE `spell_effect`
  MODIFY `EffectAmplitude` float NOT NULL DEFAULT '0' FIRST,
  MODIFY `EffectBonusCoefficient` float NOT NULL DEFAULT '0' AFTER `EffectAmplitude`,
  MODIFY `EffectChainAmplitude` float NOT NULL DEFAULT '0' AFTER `EffectBonusCoefficient`,
  MODIFY `EffectPointsPerResource` float NOT NULL DEFAULT '0' AFTER `EffectChainAmplitude`,
  MODIFY `EffectRealPointsPerLevel` float NOT NULL DEFAULT '0' AFTER `EffectPointsPerResource`,
  MODIFY `EffectSpellClassMask1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectRealPointsPerLevel`,
  MODIFY `EffectSpellClassMask2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask1`,
  MODIFY `EffectSpellClassMask3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask2`,
  MODIFY `EffectSpellClassMask4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask3`,
  MODIFY `EffectPosFacing` float NOT NULL DEFAULT '0' AFTER `EffectSpellClassMask4`,
  MODIFY `BonusCoefficientFromAP` float NOT NULL DEFAULT '0' AFTER `EffectPosFacing`,
  MODIFY `DifficultyID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `Effect` int(10) unsigned NOT NULL DEFAULT '0' AFTER `DifficultyID`,
  MODIFY `EffectAura` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Effect`,
  MODIFY `EffectChainTargets` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectBasePoints`,
  MODIFY `EffectMechanic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectItemType`,
  MODIFY `EffectRadiusIndex` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectMiscValueB`,
  MODIFY `EffectRadiusMaxIndex` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectRadiusIndex`,
  MODIFY `ImplicitTarget1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectTriggerSpell`,
  MODIFY `ImplicitTarget2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ImplicitTarget1`,
  MODIFY `EffectIndex` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SpellID`;

ALTER TABLE `spell_item_enchantment`
  MODIFY `TransmogCost` int(10) unsigned NOT NULL DEFAULT '0' AFTER `EffectScalingPoints3`,
  MODIFY `TextureFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `TransmogCost`,
  MODIFY `EffectPointsMin1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `TextureFileDataID`,
  MODIFY `EffectPointsMin2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `EffectPointsMin1`,
  MODIFY `EffectPointsMin3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `EffectPointsMin2`,
  MODIFY `ItemVisual` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `EffectPointsMin3`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ItemVisual`,
  MODIFY `RequiredSkillID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `RequiredSkillID`,
  MODIFY `ItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `RequiredSkillRank`,
  MODIFY `Charges` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ItemLevel`,
  MODIFY `Effect1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Charges`,
  MODIFY `Effect2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Effect1`,
  MODIFY `Effect3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Effect2`,
  MODIFY `ConditionID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Effect3`,
  MODIFY `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ConditionID`,
  MODIFY `MaxLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinLevel`,
  MODIFY `ScalingClass` tinyint(4) NOT NULL DEFAULT '0' AFTER `MaxLevel`,
  MODIFY `ScalingClassRestricted` tinyint(4) NOT NULL DEFAULT '0' AFTER `ScalingClass`;

ALTER TABLE `spell_item_enchantment_condition`
  MODIFY `Operator1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LTOperandType5`,
  MODIFY `Operator2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Operator1`,
  MODIFY `Operator3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Operator2`,
  MODIFY `Operator4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Operator3`,
  MODIFY `Operator5` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Operator4`,
  MODIFY `RTOperandType1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Operator5`,
  MODIFY `RTOperandType2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RTOperandType1`,
  MODIFY `RTOperandType3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RTOperandType2`,
  MODIFY `RTOperandType4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RTOperandType3`,
  MODIFY `RTOperandType5` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RTOperandType4`,
  MODIFY `RTOperand1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RTOperandType5`,
  MODIFY `RTOperand2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RTOperand1`,
  MODIFY `RTOperand3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RTOperand2`,
  MODIFY `RTOperand4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RTOperand3`,
  MODIFY `RTOperand5` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RTOperand4`,
  MODIFY `Logic1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `RTOperand5`,
  MODIFY `Logic2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Logic1`,
  MODIFY `Logic3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Logic2`,
  MODIFY `Logic4` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Logic3`,
  MODIFY `Logic5` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Logic4`,
  MODIFY `LTOperand1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Logic5`,
  MODIFY `LTOperand2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LTOperand1`,
  MODIFY `LTOperand3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LTOperand2`,
  MODIFY `LTOperand4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LTOperand3`,
  MODIFY `LTOperand5` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LTOperand4`;

ALTER TABLE `spell_power`
  MODIFY `SpellID` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `ManaCost` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SpellID`,
  MODIFY `ManaCostPercentage` float NOT NULL DEFAULT '0' AFTER `ManaCost`,
  MODIFY `ManaCostPercentagePerSecond` float NOT NULL DEFAULT '0' AFTER `ManaCostPercentage`,
  MODIFY `RequiredAura` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ManaCostPercentagePerSecond`,
  MODIFY `HealthCostPercentage` float NOT NULL DEFAULT '0' AFTER `RequiredAura`,
  MODIFY `PowerIndex` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `HealthCostPercentage`,
  MODIFY `PowerType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PowerIndex`,
  MODIFY `ManaCostPerLevel` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `ManaCostPerSecond` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ManaCostPerLevel`,
  MODIFY `ManaCostAdditional` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ManaCostPerSecond`,
  MODIFY `PowerDisplayID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ManaCostAdditional`,
  MODIFY `UnitPowerBarID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PowerDisplayID`;

ALTER TABLE `spell_power_difficulty` CHANGE `SpellPowerID` `ID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PowerIndex`;

ALTER TABLE `spell_scaling`
  MODIFY `MinScalingLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ScalesFromItemLevel`,
  MODIFY `MaxScalingLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `MinScalingLevel`,
  MODIFY `ScalingClass` int(11) NOT NULL DEFAULT '0' AFTER `MaxScalingLevel`;

ALTER TABLE `spell_shapeshift_form` MODIFY `MountTypeID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PresetSpellID8`;

ALTER TABLE `spell_target_restrictions`
  MODIFY `TargetCreatureType` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Targets`,
  MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `TargetCreatureType`,
  MODIFY `MaxAffectedTargets` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DifficultyID`,
  MODIFY `MaxTargetLevel` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MaxAffectedTargets`;

ALTER TABLE `spell_totems`
  MODIFY `RequiredTotemCategoryID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Totem2`,
  MODIFY `RequiredTotemCategoryID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `RequiredTotemCategoryID1`;

ALTER TABLE `spell_x_spell_visual`
  MODIFY `SpellID` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `Unk620` float NOT NULL DEFAULT '0' AFTER `SpellID`,
  MODIFY `SpellVisualID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Unk620`,
  MODIFY `SpellVisualID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SpellVisualID1`,
  MODIFY `PlayerConditionID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `SpellVisualID2`,
  MODIFY `DifficultyID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PlayerConditionID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DifficultyID`;

ALTER TABLE `taxi_nodes`
  MODIFY `PosX` float NOT NULL DEFAULT '0' FIRST,
  MODIFY `PosY` float NOT NULL DEFAULT '0' AFTER `PosX`,
  MODIFY `PosZ` float NOT NULL DEFAULT '0' AFTER `PosY`,
  MODIFY `Name` text NULL AFTER `PosZ`,
  MODIFY `MountCreatureID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Name`,
  MODIFY `MountCreatureID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MountCreatureID1`,
  MODIFY `MapOffsetX` float NOT NULL DEFAULT '0' AFTER `MountCreatureID2`,
  MODIFY `MapOffsetY` float NOT NULL DEFAULT '0' AFTER `MapOffsetX`,
  MODIFY `MapID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MapOffsetY`,
  MODIFY `ConditionID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MapID`,
  MODIFY `LearnableIndex` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ConditionID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LearnableIndex`;

ALTER TABLE `taxi_path`
  MODIFY `From` smallint(5) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `To` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `From`,
  MODIFY `Cost` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`;

ALTER TABLE `taxi_path_node`
  MODIFY `LocX` float NOT NULL DEFAULT '0' FIRST,
  MODIFY `LocY` float NOT NULL DEFAULT '0' AFTER `LocX`,
  MODIFY `LocZ` float NOT NULL DEFAULT '0' AFTER `LocY`,
  MODIFY `Delay` int(10) unsigned NOT NULL DEFAULT '0' AFTER `LocZ`,
  MODIFY `PathID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `Delay`,
  MODIFY `MapID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PathID`,
  MODIFY `ArrivalEventID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MapID`,
  MODIFY `DepartureEventID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ArrivalEventID`,
  MODIFY `NodeIndex` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DepartureEventID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `NodeIndex`;

ALTER TABLE `toy`
  MODIFY `ItemID` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  MODIFY `Description` text NULL AFTER `ItemID`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Description`,
  MODIFY `CategoryFilter` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Flags`;

ALTER TABLE `unit_power_bar`
  MODIFY `RegenerationPeace` float NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `RegenerationCombat` float NOT NULL DEFAULT '0' AFTER `RegenerationPeace`,
  MODIFY `FileDataID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RegenerationCombat`,
  MODIFY `FileDataID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FileDataID1`,
  MODIFY `FileDataID3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FileDataID2`,
  MODIFY `FileDataID4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FileDataID3`,
  MODIFY `FileDataID5` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FileDataID4`,
  MODIFY `FileDataID6` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FileDataID5`,
  MODIFY `Color1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `FileDataID6`,
  MODIFY `Color2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Color1`,
  MODIFY `Color3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Color2`,
  MODIFY `Color4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Color3`,
  MODIFY `Color5` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Color4`,
  MODIFY `Color6` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Color5`,
  MODIFY `Name` text NULL AFTER `Color6`,
  MODIFY `Cost` text NULL AFTER `Name`,
  MODIFY `OutOfError` text NULL AFTER `Cost`,
  MODIFY `ToolTip` text NULL AFTER `OutOfError`,
  MODIFY `StartInset` float NOT NULL DEFAULT '0' AFTER `ToolTip`,
  MODIFY `EndInset` float NOT NULL DEFAULT '0' AFTER `StartInset`,
  MODIFY `StartPower` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `EndInset`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `StartPower`,
  MODIFY `CenterPower` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `BarType` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CenterPower`,
  MODIFY `MinPower` int(10) unsigned NOT NULL DEFAULT '0' AFTER `BarType`;

ALTER TABLE `vehicle_seat`
  MODIFY `CameraEnteringDelay` float NOT NULL DEFAULT '0' AFTER `VehicleExitAnimDelay`,
  MODIFY `CameraEnteringDuration` float NOT NULL DEFAULT '0' AFTER `CameraEnteringDelay`,
  MODIFY `CameraExitingDelay` float NOT NULL DEFAULT '0' AFTER `CameraEnteringDuration`,
  MODIFY `CameraExitingDuration` float NOT NULL DEFAULT '0' AFTER `CameraExitingDelay`,
  MODIFY `CameraOffsetX` float NOT NULL DEFAULT '0' AFTER `CameraExitingDuration`,
  MODIFY `CameraOffsetY` float NOT NULL DEFAULT '0' AFTER `CameraOffsetX`,
  MODIFY `CameraOffsetZ` float NOT NULL DEFAULT '0' AFTER `CameraOffsetY`,
  MODIFY `CameraPosChaseRate` float NOT NULL DEFAULT '0' AFTER `CameraOffsetZ`,
  MODIFY `CameraFacingChaseRate` float NOT NULL DEFAULT '0' AFTER `CameraPosChaseRate`,
  MODIFY `CameraEnteringZoom` float NOT NULL DEFAULT '0' AFTER `CameraFacingChaseRate`,
  MODIFY `CameraSeatZoomMin` float NOT NULL DEFAULT '0' AFTER `CameraEnteringZoom`,
  MODIFY `CameraSeatZoomMax` float NOT NULL DEFAULT '0' AFTER `CameraSeatZoomMin`,
  MODIFY `UISkinFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CameraSeatZoomMax`,
  MODIFY `EnterAnimStart` smallint(6) NOT NULL DEFAULT '0' AFTER `UISkinFileDataID`,
  MODIFY `EnterAnimLoop` smallint(6) NOT NULL DEFAULT '0' AFTER `EnterAnimStart`,
  MODIFY `RideAnimStart` smallint(6) NOT NULL DEFAULT '0' AFTER `EnterAnimLoop`,
  MODIFY `RideAnimLoop` smallint(6) NOT NULL DEFAULT '0' AFTER `RideAnimStart`,
  MODIFY `RideUpperAnimStart` smallint(6) NOT NULL DEFAULT '0' AFTER `RideAnimLoop`,
  MODIFY `RideUpperAnimLoop` smallint(6) NOT NULL DEFAULT '0' AFTER `RideUpperAnimStart`,
  MODIFY `ExitAnimStart` smallint(6) NOT NULL DEFAULT '0' AFTER `RideUpperAnimLoop`,
  MODIFY `ExitAnimLoop` smallint(6) NOT NULL DEFAULT '0' AFTER `ExitAnimStart`,
  MODIFY `ExitAnimEnd` smallint(6) NOT NULL DEFAULT '0' AFTER `ExitAnimLoop`,
  MODIFY `VehicleEnterAnim` smallint(6) NOT NULL DEFAULT '0' AFTER `ExitAnimEnd`,
  MODIFY `VehicleExitAnim` smallint(6) NOT NULL DEFAULT '0' AFTER `VehicleEnterAnim`,
  MODIFY `VehicleRideAnimLoop` smallint(6) NOT NULL DEFAULT '0' AFTER `VehicleExitAnim`,
  MODIFY `EnterAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `VehicleRideAnimLoop`,
  MODIFY `RideAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `EnterAnimKitID`,
  MODIFY `ExitAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `RideAnimKitID`,
  MODIFY `VehicleEnterAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ExitAnimKitID`,
  MODIFY `VehicleRideAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `VehicleEnterAnimKitID`,
  MODIFY `VehicleExitAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `VehicleRideAnimKitID`,
  MODIFY `CameraModeID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `VehicleExitAnimKitID`,
  MODIFY `AttachmentID` tinyint(4) NOT NULL DEFAULT '0' AFTER `CameraModeID`,
  MODIFY `PassengerAttachmentID` tinyint(4) NOT NULL DEFAULT '0' AFTER `AttachmentID`,
  MODIFY `VehicleEnterAnimBone` tinyint(4) NOT NULL DEFAULT '0' AFTER `PassengerAttachmentID`,
  MODIFY `VehicleExitAnimBone` tinyint(4) NOT NULL DEFAULT '0' AFTER `VehicleEnterAnimBone`,
  MODIFY `VehicleRideAnimLoopBone` tinyint(4) NOT NULL DEFAULT '0' AFTER `VehicleExitAnimBone`,
  MODIFY `VehicleAbilityDisplay` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `VehicleRideAnimLoopBone`;

ALTER TABLE `wmo_area_table`
  MODIFY `WMOGroupID` int(11) NOT NULL DEFAULT '0' FIRST,
  MODIFY `AreaName` text NULL AFTER `WMOGroupID`,
  MODIFY `WMOID` smallint(6) NOT NULL DEFAULT '0' AFTER `AreaName`,
  MODIFY `AmbienceID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `WMOID`,
  MODIFY `ZoneMusic` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AmbienceID`,
  MODIFY `IntroSound` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ZoneMusic`,
  MODIFY `AreaTableID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `IntroSound`,
  MODIFY `UWIntroSound` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AreaTableID`,
  MODIFY `UWAmbience` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `UWIntroSound`,
  MODIFY `NameSet` tinyint(4) NOT NULL DEFAULT '0' AFTER `UWAmbience`,
  MODIFY `SoundProviderPref` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `NameSet`,
  MODIFY `SoundProviderPrefUnderwater` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SoundProviderPref`,
  MODIFY `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `SoundProviderPrefUnderwater`,
  MODIFY `UWZoneMusic` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`;

ALTER TABLE `world_map_area`
  MODIFY `AreaName` text NULL FIRST,
  MODIFY `LocLeft` float NOT NULL DEFAULT '0' AFTER `AreaName`,
  MODIFY `LocRight` float NOT NULL DEFAULT '0' AFTER `LocLeft`,
  MODIFY `LocTop` float NOT NULL DEFAULT '0' AFTER `LocRight`,
  MODIFY `LocBottom` float NOT NULL DEFAULT '0' AFTER `LocTop`,
  MODIFY `MapID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `LocBottom`,
  MODIFY `AreaID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `MapID`,
  MODIFY `DisplayMapID` smallint(6) NOT NULL DEFAULT '0' AFTER `AreaID`,
  MODIFY `DefaultDungeonFloor` smallint(6) NOT NULL DEFAULT '0' AFTER `DisplayMapID`,
  MODIFY `ParentWorldMapID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `DefaultDungeonFloor`,
  MODIFY `Flags` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ParentWorldMapID`,
  MODIFY `LevelRangeMin` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `LevelRangeMax` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LevelRangeMin`,
  MODIFY `BountySetID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `LevelRangeMax`,
  MODIFY `BountyBoardLocation` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `BountySetID`,
  MODIFY `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`;

ALTER TABLE `world_map_overlay`
  MODIFY `TextureWidth` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `TextureName`,
  MODIFY `TextureHeight` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `TextureWidth`,
  MODIFY `MapAreaID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `TextureHeight`,
  MODIFY `AreaID1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MapAreaID`,
  MODIFY `AreaID2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AreaID1`,
  MODIFY `AreaID3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AreaID2`,
  MODIFY `AreaID4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AreaID3`,
  MODIFY `OffsetX` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AreaID4`,
  MODIFY `OffsetY` int(10) unsigned NOT NULL DEFAULT '0' AFTER `OffsetX`,
  MODIFY `HitRectTop` int(10) unsigned NOT NULL DEFAULT '0' AFTER `OffsetY`,
  MODIFY `HitRectLeft` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HitRectTop`,
  MODIFY `HitRectBottom` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HitRectLeft`,
  MODIFY `HitRectRight` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HitRectBottom`,
  MODIFY `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HitRectRight`,
  MODIFY `Flags` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PlayerConditionID`;

DROP TABLE `glyph_slot`;
