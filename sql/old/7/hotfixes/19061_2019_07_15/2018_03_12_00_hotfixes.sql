ALTER TABLE `achievement`
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `Reward`,
  CHANGE `MapID` `InstanceID` smallint(6) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `Supercedes` smallint(6) NOT NULL DEFAULT 0 AFTER `InstanceID`,
  MODIFY `Category` smallint(6) NOT NULL DEFAULT 0 AFTER `Supercedes`,
  CHANGE `UIOrder` `UiOrder` smallint(6) NOT NULL DEFAULT 0 AFTER `Category`,
  MODIFY `SharesCriteria` smallint(6) NOT NULL DEFAULT 0 AFTER `UiOrder`,
  MODIFY `Points` tinyint(4) NOT NULL DEFAULT 0 AFTER `Faction`,
  MODIFY `MinimumCriteria` tinyint(4) NOT NULL DEFAULT 0 AFTER `Points`,
  CHANGE `IconFileDataID` `IconFileID` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `area_table`
  MODIFY `Flags1` int(11) NOT NULL DEFAULT 0 AFTER `AreaName`,
  MODIFY `Flags2` int(11) NOT NULL DEFAULT 0 AFTER `Flags1`,
  CHANGE `MapID` `ContinentID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `AmbientMultiplier`,
  CHANGE `UWZoneMusic` `UwZoneMusic` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `LiquidTypeID4`,
  CHANGE `UWAmbience` `UwAmbience` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UwZoneMusic`,
  CHANGE `PvPCombatWorldStateID` `PvpCombatWorldStateID` smallint(6) NOT NULL DEFAULT 0 AFTER `UwAmbience`,
  MODIFY `ExplorationLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `SoundProviderPrefUnderwater`,
  CHANGE `UWIntroSound` `UwIntroSound` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `WindSettingsID`;

ALTER TABLE `area_trigger`
  CHANGE `MapID` `ContinentID` smallint(6) NOT NULL DEFAULT 0 AFTER `BoxYaw`,
  MODIFY `PhaseID` smallint(6) NOT NULL DEFAULT 0 AFTER `ContinentID`,
  MODIFY `PhaseGroupID` smallint(6) NOT NULL DEFAULT 0 AFTER `PhaseID`,
  MODIFY `ShapeID` smallint(6) NOT NULL DEFAULT 0 AFTER `PhaseGroupID`,
  MODIFY `AreaTriggerActionSetID` smallint(6) NOT NULL DEFAULT 0 AFTER `ShapeID`,
  MODIFY `PhaseUseFlags` tinyint(4) NOT NULL DEFAULT 0 AFTER `AreaTriggerActionSetID`,
  MODIFY `ShapeType` tinyint(4) NOT NULL DEFAULT 0 AFTER `PhaseUseFlags`,
  CHANGE `Flag` `Flags` tinyint(4) NOT NULL DEFAULT 0 AFTER `ShapeType`;

ALTER TABLE `armor_location`
  CHANGE `Modifier1` `Clothmodifier` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Modifier2` `Leathermodifier` float NOT NULL DEFAULT 0 AFTER `Clothmodifier`,
  CHANGE `Modifier3` `Chainmodifier` float NOT NULL DEFAULT 0 AFTER `Leathermodifier`,
  CHANGE `Modifier4` `Platemodifier` float NOT NULL DEFAULT 0 AFTER `Chainmodifier`,
  CHANGE `Modifier5` `Modifier` float NOT NULL DEFAULT 0 AFTER `Platemodifier`;

ALTER TABLE `artifact`
  CHANGE `BarConnectedColor` `UiBarOverlayColor` int(11) NOT NULL DEFAULT 0 AFTER `Name`,
  CHANGE `BarDisconnectedColor` `UiBarBackgroundColor` int(11) NOT NULL DEFAULT 0 AFTER `UiBarOverlayColor`,
  CHANGE `TitleColor` `UiNameColor` int(11) NOT NULL DEFAULT 0 AFTER `UiBarBackgroundColor`,
  CHANGE `ClassUiTextureKitID` `UiTextureKitID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UiNameColor`,
  CHANGE `SpecID` `ChrSpecializationID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UiTextureKitID`;

ALTER TABLE `artifact_appearance`
  CHANGE `SwatchColor` `UiSwatchColor` int(11) NOT NULL DEFAULT 0 AFTER `Name`,
  CHANGE `ModelDesaturation` `UiModelSaturation` float NOT NULL DEFAULT 0 AFTER `UiSwatchColor`,
  CHANGE `ModelAlpha` `UiModelOpacity` float NOT NULL DEFAULT 0 AFTER `UiModelSaturation`,
  CHANGE `ShapeshiftDisplayID` `OverrideShapeshiftDisplayID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `UiModelOpacity`,
  CHANGE `Unknown` `UiCameraID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ArtifactAppearanceSetID`,
  CHANGE `AppearanceModID` `ItemAppearanceModifierID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `DisplayIndex`,
  CHANGE `ModifiesShapeshiftFormDisplay` `OverrideShapeshiftFormID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `PlayerConditionID` `UnlockPlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `ItemAppearanceID` `UiItemAppearanceID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `UnlockPlayerConditionID`,
  CHANGE `AltItemAppearanceID` `UiAltItemAppearanceID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `UiItemAppearanceID`;

ALTER TABLE `artifact_appearance_set`
  CHANGE `Name2` `Description` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Name`,
  CHANGE `AttachmentPoint` `ForgeAttachmentOverride` tinyint(4) NOT NULL DEFAULT 0 AFTER `DisplayIndex`;

ALTER TABLE `artifact_appearance_set_locale` CHANGE `Name2_lang` `Description_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Name_lang`;

ALTER TABLE `artifact_category`
  CHANGE `ArtifactKnowledgeCurrencyID` `XpMultCurrencyID` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `ArtifactKnowledgeMultiplierCurveID` `XpMultCurveID` smallint(6) NOT NULL DEFAULT 0 AFTER `XpMultCurrencyID`;

ALTER TABLE `artifact_power`
  CHANGE `MaxRank` `MaxPurchasableRank` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `ArtifactTier` `Tier` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `MaxPurchasableRank`,
  CHANGE `RelicType` `Label` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `artifact_power_link`
  CHANGE `FromArtifactPowerID` `PowerA` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `ToArtifactPowerID` `PowerB` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `PowerA`;

ALTER TABLE `artifact_power_rank`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Value` `AuraPointsOverride` float NOT NULL DEFAULT 0 AFTER `SpellID`,
  CHANGE `Unknown` `ItemBonusListID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `AuraPointsOverride`,
  CHANGE `Rank` `RankIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemBonusListID`;

ALTER TABLE `artifact_quest_xp`
  CHANGE `Exp1` `Difficulty1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Exp2` `Difficulty2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty1`,
  CHANGE `Exp3` `Difficulty3` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty2`,
  CHANGE `Exp4` `Difficulty4` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty3`,
  CHANGE `Exp5` `Difficulty5` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty4`,
  CHANGE `Exp6` `Difficulty6` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty5`,
  CHANGE `Exp7` `Difficulty7` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty6`,
  CHANGE `Exp8` `Difficulty8` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty7`,
  CHANGE `Exp9` `Difficulty9` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty8`,
  CHANGE `Exp10` `Difficulty10` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty9`;

ALTER TABLE `battlemaster_list`
  MODIFY `IconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `LongDescription`,
  MODIFY `HolidayWorldState` smallint(6) NOT NULL DEFAULT 0 AFTER `MapID16`,
  CHANGE `PlayerConditionID` `RequiredPlayerConditionID` smallint(6) NOT NULL DEFAULT 0 AFTER `HolidayWorldState`,
  MODIFY `InstanceType` tinyint(4) NOT NULL DEFAULT 0 AFTER `RequiredPlayerConditionID`,
  MODIFY `GroupsAllowed` tinyint(4) NOT NULL DEFAULT 0 AFTER `InstanceType`,
  MODIFY `MaxGroupSize` tinyint(4) NOT NULL DEFAULT 0 AFTER `GroupsAllowed`,
  MODIFY `MinLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaxGroupSize`,
  MODIFY `MaxLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `MinLevel`,
  MODIFY `RatedPlayers` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaxLevel`,
  MODIFY `MinPlayers` tinyint(4) NOT NULL DEFAULT 0 AFTER `RatedPlayers`,
  MODIFY `MaxPlayers` tinyint(4) NOT NULL DEFAULT 0 AFTER `MinPlayers`,
  MODIFY `Flags` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaxPlayers`;

ALTER TABLE `battle_pet_breed_quality`
  CHANGE `Modifier` `StateMultiplier` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Quality` `QualityEnum` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `StateMultiplier`;

ALTER TABLE `battle_pet_breed_state`
  MODIFY `Value` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `State` `BattlePetStateID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Value`,
  CHANGE `BreedID` `BattlePetBreedID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `BattlePetStateID`;

ALTER TABLE `battle_pet_species`
  MODIFY `CreatureID` int(11) NOT NULL DEFAULT 0 AFTER `Description`,
  CHANGE `IconFileID` `IconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `CreatureID`,
  MODIFY `SummonSpellID` int(11) NOT NULL DEFAULT 0 AFTER `IconFileDataID`,
  CHANGE `PetType` `PetTypeEnum` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `Source` `SourceTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `PetTypeEnum`,
  CHANGE `CardModelSceneID` `CardUIModelSceneID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `LoadoutModelSceneID` `LoadoutUIModelSceneID` int(11) NOT NULL DEFAULT 0 AFTER `CardUIModelSceneID`;

ALTER TABLE `battle_pet_species_state`
  CHANGE `State` `BattlePetStateID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Value`,
  CHANGE `SpeciesID` `BattlePetSpeciesID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `BattlePetStateID`;

ALTER TABLE `broadcast_text`
  CHANGE `MaleText` `Text` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `ID`,
  CHANGE `FemaleText` `Text1` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Text`,
  CHANGE `UnkEmoteID` `EmotesID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `EmoteDelay3`,
  CHANGE `Language` `LanguageID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `EmotesID`,
  CHANGE `Type` `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `LanguageID`,
  CHANGE `PlayerConditionID` `ConditionID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `SoundID1` `SoundEntriesID1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ConditionID`,
  CHANGE `SoundID2` `SoundEntriesID2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `SoundEntriesID1`;

ALTER TABLE `broadcast_text_locale`
  CHANGE `MaleText_lang` `Text_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `locale`,
  CHANGE `FemaleText_lang` `Text1_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Text_lang`;

ALTER TABLE `character_facial_hair_styles`
  MODIFY `Geoset1` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Geoset2` int(11) NOT NULL DEFAULT 0 AFTER `Geoset1`,
  MODIFY `Geoset3` int(11) NOT NULL DEFAULT 0 AFTER `Geoset2`,
  MODIFY `Geoset4` int(11) NOT NULL DEFAULT 0 AFTER `Geoset3`,
  MODIFY `Geoset5` int(11) NOT NULL DEFAULT 0 AFTER `Geoset4`;

ALTER TABLE `char_base_section`
  CHANGE `Variation` `VariationEnum` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `ResolutionVariation` `ResolutionVariationEnum` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `VariationEnum`,
  CHANGE `Resolution` `LayoutResType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ResolutionVariationEnum`;

ALTER TABLE `char_sections`
  CHANGE `TextureFileDataID1` `MaterialResourcesID1` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `TextureFileDataID2` `MaterialResourcesID2` int(11) NOT NULL DEFAULT 0 AFTER `MaterialResourcesID1`,
  CHANGE `TextureFileDataID3` `MaterialResourcesID3` int(11) NOT NULL DEFAULT 0 AFTER `MaterialResourcesID2`,
  MODIFY `Flags` smallint(6) NOT NULL DEFAULT 0 AFTER `MaterialResourcesID3`,
  MODIFY `RaceID` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `SexID` tinyint(4) NOT NULL DEFAULT 0 AFTER `RaceID`,
  MODIFY `BaseSection` tinyint(4) NOT NULL DEFAULT 0 AFTER `SexID`,
  MODIFY `VariationIndex` tinyint(4) NOT NULL DEFAULT 0 AFTER `BaseSection`,
  MODIFY `ColorIndex` tinyint(4) NOT NULL DEFAULT 0 AFTER `VariationIndex`;

ALTER TABLE `char_start_outfit` CHANGE `GenderID` `SexID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ClassID`;

ALTER TABLE `char_titles`
  CHANGE `NameMale` `Name` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `ID`,
  CHANGE `NameFemale` `Name1` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Name`,
  MODIFY `MaskID` smallint(6) NOT NULL DEFAULT 0 AFTER `Name1`,
  MODIFY `Flags` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaskID`;

ALTER TABLE `char_titles_locale`
  CHANGE `NameMale_lang` `Name_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `locale`,
  CHANGE `NameFemale_lang` `Name1_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Name_lang`;

ALTER TABLE `chat_channels`
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `Shortcut`,
  MODIFY `FactionGroup` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `chr_classes`
  MODIFY `LowResScreenFileDataID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `SelectScreenFileDataID`,
  MODIFY `StartingLevel` int(11) NOT NULL DEFAULT 0 AFTER `IconFileDataID`,
  CHANGE `PowerType` `DisplayPower` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `DefaultSpec`,
  CHANGE `Unk1` `PrimaryStatPriority` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RangedAttackPowerPerAgility`;

ALTER TABLE `chr_races`
  CHANGE `LowercaseName` `NameLowercase` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `NameFemale`,
  CHANGE `LowercaseNameFemale` `NameFemaleLowercase` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `NameLowercase`,
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `NameFemaleLowercase`,
  CHANGE `MaleDisplayID` `MaleDisplayId` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `FemaleDisplayID` `FemaleDisplayId` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `MaleDisplayId`,
  MODIFY `CreateScreenFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `FemaleDisplayId`,
  MODIFY `SelectScreenFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `CreateScreenFileDataID`,
  MODIFY `LowResScreenFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `FemaleCustomizeOffset3`,
  MODIFY `StartingLevel` int(11) NOT NULL DEFAULT 0 AFTER `LowResScreenFileDataID`,
  CHANGE `UIDisplayOrder` `UiDisplayOrder` int(11) NOT NULL DEFAULT 0 AFTER `StartingLevel`,
  MODIFY `FactionID` smallint(6) NOT NULL DEFAULT 0 AFTER `UiDisplayOrder`,
  MODIFY `ResSicknessSpellID` smallint(6) NOT NULL DEFAULT 0 AFTER `FactionID`,
  MODIFY `SplashSoundID` smallint(6) NOT NULL DEFAULT 0 AFTER `ResSicknessSpellID`,
  MODIFY `CinematicSequenceID` smallint(6) NOT NULL DEFAULT 0 AFTER `SplashSoundID`,
  MODIFY `BaseLanguage` tinyint(4) NOT NULL DEFAULT 0 AFTER `CinematicSequenceID`,
  MODIFY `CreatureType` tinyint(4) NOT NULL DEFAULT 0 AFTER `BaseLanguage`,
  CHANGE `TeamID` `Alliance` tinyint(4) NOT NULL DEFAULT 0 AFTER `CreatureType`,
  MODIFY `RaceRelated` tinyint(4) NOT NULL DEFAULT 0 AFTER `Alliance`,
  MODIFY `UnalteredVisualRaceID` tinyint(4) NOT NULL DEFAULT 0 AFTER `RaceRelated`,
  MODIFY `CharComponentTextureLayoutID` tinyint(4) NOT NULL DEFAULT 0 AFTER `UnalteredVisualRaceID`,
  MODIFY `DefaultClassID` tinyint(4) NOT NULL DEFAULT 0 AFTER `CharComponentTextureLayoutID`,
  MODIFY `NeutralRaceID` tinyint(4) NOT NULL DEFAULT 0 AFTER `DefaultClassID`,
  CHANGE `ItemAppearanceFrameRaceID` `DisplayRaceID` tinyint(4) NOT NULL DEFAULT 0 AFTER `NeutralRaceID`,
  MODIFY `CharComponentTexLayoutHiResID` tinyint(4) NOT NULL DEFAULT 0 AFTER `DisplayRaceID`,
  CHANGE `HighResMaleDisplayID` `HighResMaleDisplayId` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `HighResFemaleDisplayID` `HighResFemaleDisplayId` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `HighResMaleDisplayId`,
  MODIFY `HeritageArmorAchievementID` int(11) NOT NULL DEFAULT 0 AFTER `HighResFemaleDisplayId`,
  CHANGE `MaleCorpseBonesModelFileDataID` `MaleSkeletonFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `HeritageArmorAchievementID`,
  CHANGE `FemaleCorpseBonesModelFileDataID` `FemaleSkeletonFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `MaleSkeletonFileDataID`,
  CHANGE `AlteredFormTransitionSpellVisualID1` `AlteredFormStartVisualKitID1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `FemaleSkeletonFileDataID`,
  CHANGE `AlteredFormTransitionSpellVisualID2` `AlteredFormStartVisualKitID2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `AlteredFormStartVisualKitID1`,
  CHANGE `AlteredFormTransitionSpellVisualID3` `AlteredFormStartVisualKitID3` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `AlteredFormStartVisualKitID2`,
  CHANGE `AlteredFormTransitionSpellVisualKitID1` `AlteredFormFinishVisualKitID1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `AlteredFormStartVisualKitID3`,
  CHANGE `AlteredFormTransitionSpellVisualKitID2` `AlteredFormFinishVisualKitID2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `AlteredFormFinishVisualKitID1`,
  CHANGE `AlteredFormTransitionSpellVisualKitID3` `AlteredFormFinishVisualKitID3` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `AlteredFormFinishVisualKitID2`;

ALTER TABLE `chr_races_locale`
  CHANGE `LowercaseName_lang` `NameLowercase_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `NameFemale_lang`,
  CHANGE `LowercaseNameFemale_lang` `NameFemaleLowercase_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `NameLowercase_lang`;

ALTER TABLE `chr_specialization`
  CHANGE `Name2` `FemaleName` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Name`,
  MODIFY `MasterySpellID1` int(11) NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `MasterySpellID2` int(11) NOT NULL DEFAULT 0 AFTER `MasterySpellID1`,
  MODIFY `ClassID` tinyint(4) NOT NULL DEFAULT 0 AFTER `MasterySpellID2`,
  MODIFY `OrderIndex` tinyint(4) NOT NULL DEFAULT 0 AFTER `ClassID`,
  MODIFY `PetTalentType` tinyint(4) NOT NULL DEFAULT 0 AFTER `OrderIndex`,
  MODIFY `Role` tinyint(4) NOT NULL DEFAULT 0 AFTER `PetTalentType`,
  CHANGE `PrimaryStatOrder` `PrimaryStatPriority` tinyint(4) NOT NULL DEFAULT 0 AFTER `Role`,
  CHANGE `IconFileDataID` `SpellIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `AnimReplacementSetID` `AnimReplacements` int(11) NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `chr_specialization_locale` CHANGE `Name2_lang` `FemaleName_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Name_lang`;

ALTER TABLE `cinematic_camera` CHANGE `ModelFileDataID` `FileDataID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `OriginFacing`;

ALTER TABLE `conversation_line`
  CHANGE `Duration` `AdditionalDuration` int(11) NOT NULL DEFAULT 0 AFTER `SpellVisualKitID`,
  CHANGE `NextLineID` `NextConversationLineID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `AdditionalDuration`,
  CHANGE `Unk1` `AnimKitID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `NextConversationLineID`,
  CHANGE `Yell` `SpeechType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `AnimKitID`,
  CHANGE `Unk2` `StartAnimation` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SpeechType`,
  CHANGE `Unk3` `EndAnimation` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `StartAnimation`;

ALTER TABLE `creature_display_info`
  MODIFY `SizeClass` tinyint(4) NOT NULL DEFAULT 0 AFTER `NPCSoundID`,
  MODIFY `ExtendedDisplayInfoID` int(11) NOT NULL DEFAULT 0 AFTER `Gender`,
  MODIFY `PortraitTextureFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `ExtendedDisplayInfoID`,
  CHANGE `PlayerModelScale` `PlayerOverrideScale` float NOT NULL DEFAULT 0 AFTER `SoundID`,
  MODIFY `PortraitCreatureDisplayInfoID` int(11) NOT NULL DEFAULT 0 AFTER `PlayerOverrideScale`,
  CHANGE `UnarmedWeaponSubclass` `UnarmedWeaponType` tinyint(4) NOT NULL DEFAULT 0 AFTER `AnimReplacementSetID`,
  MODIFY `StateSpellVisualKitID` int(11) NOT NULL DEFAULT 0 AFTER `UnarmedWeaponType`,
  CHANGE `InstanceOtherPlayerPetScale` `PetInstanceScale` float NOT NULL DEFAULT 0 AFTER `StateSpellVisualKitID`,
  CHANGE `MountSpellVisualKitID` `MountPoofSpellVisualKitID` int(11) NOT NULL DEFAULT 0 AFTER `PetInstanceScale`,
  CHANGE `TextureVariation1` `TextureVariationFileDataID1` int(11) NOT NULL DEFAULT 0 AFTER `MountPoofSpellVisualKitID`,
  CHANGE `TextureVariation2` `TextureVariationFileDataID2` int(11) NOT NULL DEFAULT 0 AFTER `TextureVariationFileDataID1`,
  CHANGE `TextureVariation3` `TextureVariationFileDataID3` int(11) NOT NULL DEFAULT 0 AFTER `TextureVariationFileDataID2`;

ALTER TABLE `creature_display_info_extra`
  CHANGE `FileDataID` `BakeMaterialResourcesID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `HDFileDataID` `HDBakeMaterialResourcesID` int(11) NOT NULL DEFAULT 0 AFTER `BakeMaterialResourcesID`,
  MODIFY `DisplayRaceID` tinyint(4) NOT NULL DEFAULT 0 AFTER `HDBakeMaterialResourcesID`,
  MODIFY `DisplaySexID` tinyint(4) NOT NULL DEFAULT 0 AFTER `DisplayRaceID`,
  MODIFY `DisplayClassID` tinyint(4) NOT NULL DEFAULT 0 AFTER `DisplaySexID`,
  MODIFY `SkinID` tinyint(4) NOT NULL DEFAULT 0 AFTER `DisplayClassID`,
  MODIFY `FaceID` tinyint(4) NOT NULL DEFAULT 0 AFTER `SkinID`,
  MODIFY `HairStyleID` tinyint(4) NOT NULL DEFAULT 0 AFTER `FaceID`,
  MODIFY `HairColorID` tinyint(4) NOT NULL DEFAULT 0 AFTER `HairStyleID`,
  MODIFY `FacialHairID` tinyint(4) NOT NULL DEFAULT 0 AFTER `HairColorID`,
  MODIFY `Flags` tinyint(4) NOT NULL DEFAULT 0 AFTER `CustomDisplayOption3`;

ALTER TABLE `creature_family`
  CHANGE `IconFileDataID` `IconFileID` int(11) NOT NULL DEFAULT 0 AFTER `MaxScale`,
  MODIFY `SkillLine1` smallint(6) NOT NULL DEFAULT 0 AFTER `IconFileID`,
  MODIFY `SkillLine2` smallint(6) NOT NULL DEFAULT 0 AFTER `SkillLine1`,
  MODIFY `PetFoodMask` smallint(6) NOT NULL DEFAULT 0 AFTER `SkillLine2`,
  MODIFY `MinScaleLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `PetFoodMask`,
  MODIFY `MaxScaleLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `MinScaleLevel`,
  MODIFY `PetTalentType` tinyint(4) NOT NULL DEFAULT 0 AFTER `MaxScaleLevel`;

ALTER TABLE `creature_model_data`
  CHANGE `GeoBoxMin1` `GeoBox1` float NOT NULL DEFAULT 0 AFTER `MountHeight`,
  CHANGE `GeoBoxMin2` `GeoBox2` float NOT NULL DEFAULT 0 AFTER `GeoBox1`,
  CHANGE `GeoBoxMin3` `GeoBox3` float NOT NULL DEFAULT 0 AFTER `GeoBox2`,
  CHANGE `GeoBoxMax1` `GeoBox4` float NOT NULL DEFAULT 0 AFTER `GeoBox3`,
  CHANGE `GeoBoxMax2` `GeoBox5` float NOT NULL DEFAULT 0 AFTER `GeoBox4`,
  CHANGE `GeoBoxMax3` `GeoBox6` float NOT NULL DEFAULT 0 AFTER `GeoBox5`,
  CHANGE `FootstepEffectID` `FootstepCameraEffectID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `FoleyMaterialID`,
  CHANGE `DeathThudEffectID` `DeathThudCameraEffectID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `FootstepCameraEffectID`;

ALTER TABLE `criteria`
  MODIFY `StartAsset` int(11) NOT NULL DEFAULT 0 AFTER `Asset`,
  MODIFY `FailAsset` int(11) NOT NULL DEFAULT 0 AFTER `StartAsset`,
  MODIFY `EligibilityWorldStateID` smallint(6) NOT NULL DEFAULT 0 AFTER `StartTimer`,
  MODIFY `EligibilityWorldStateValue` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `criteria_tree`
  MODIFY `Amount` int(11) NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `Flags` smallint(6) NOT NULL DEFAULT 0 AFTER `Amount`,
  MODIFY `Operator` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `currency_types` CHANGE `InventoryIconFileDataID` `InventoryIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `Quality`;

ALTER TABLE `curve` CHANGE `Unused` `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Type`;

ALTER TABLE `curve_point`
  CHANGE `X` `PosX` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Y` `PosY` float NOT NULL DEFAULT 0 AFTER `PosX`,
  CHANGE `Index` `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurveID`;

ALTER TABLE `destructible_model_data`
  CHANGE `StateDamagedDisplayID` `State0Wmo` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `StateDestroyedDisplayID` `State1Wmo` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `State0Wmo`,
  CHANGE `StateRebuildingDisplayID` `State2Wmo` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `State1Wmo`,
  CHANGE `StateSmokeDisplayID` `State3Wmo` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `State2Wmo`,
  CHANGE `StateDamagedImpactEffectDoodadSet` `State0ImpactEffectDoodadSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `HealEffectSpeed`,
  CHANGE `StateDamagedAmbientDoodadSet` `State0AmbientDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `State0ImpactEffectDoodadSet`,
  CHANGE `StateDamagedNameSet` `State0NameSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State0AmbientDoodadSet`,
  CHANGE `StateDestroyedDestructionDoodadSet` `State1DestructionDoodadSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State0NameSet`,
  CHANGE `StateDestroyedImpactEffectDoodadSet` `State1ImpactEffectDoodadSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State1DestructionDoodadSet`,
  CHANGE `StateDestroyedAmbientDoodadSet` `State1AmbientDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `State1ImpactEffectDoodadSet`,
  CHANGE `StateDestroyedNameSet` `State1NameSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State1AmbientDoodadSet`,
  CHANGE `StateRebuildingDestructionDoodadSet` `State2DestructionDoodadSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State1NameSet`,
  CHANGE `StateRebuildingImpactEffectDoodadSet` `State2ImpactEffectDoodadSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State2DestructionDoodadSet`,
  CHANGE `StateRebuildingAmbientDoodadSet` `State2AmbientDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `State2ImpactEffectDoodadSet`,
  CHANGE `StateRebuildingNameSet` `State2NameSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State2AmbientDoodadSet`,
  CHANGE `StateSmokeInitDoodadSet` `State3InitDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `State2NameSet`,
  CHANGE `StateSmokeAmbientDoodadSet` `State3AmbientDoodadSet` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `State3InitDoodadSet`,
  CHANGE `StateSmokeNameSet` `State3NameSet` tinyint(4) NOT NULL DEFAULT 0 AFTER `State3AmbientDoodadSet`;

ALTER TABLE `difficulty` CHANGE `ItemBonusTreeModID` `ItemContext` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ToggleDifficultyID`;

ALTER TABLE `dungeon_encounter`
  MODIFY `CreatureDisplayID` int(11) NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `MapID` smallint(6) NOT NULL DEFAULT 0 AFTER `CreatureDisplayID`,
  MODIFY `DifficultyID` tinyint(4) NOT NULL DEFAULT 0 AFTER `MapID`,
  MODIFY `Bit` tinyint(4) NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  CHANGE `TextureFileDataID` `SpellIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `OrderIndex`;

ALTER TABLE `durability_quality` CHANGE `QualityMod` `Data` float NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `emotes`
  MODIFY `EmoteFlags` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `EmoteSlashCommand`,
  MODIFY `AnimID` smallint(6) NOT NULL DEFAULT 0 AFTER `SpellVisualKitID`,
  MODIFY `ClassMask` int(11) NOT NULL DEFAULT 0 AFTER `EmoteSpecProc`,
  CHANGE `EmoteSoundID` `EventSoundID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `EmoteSpecProcParam`;

DROP TABLE IF EXISTS `emotes_text_locale`;

ALTER TABLE `emotes_text_sound`
  CHANGE `RaceId` `RaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `SexId` `SexID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RaceID`,
  CHANGE `ClassId` `ClassID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SexID`,
  CHANGE `SoundId` `SoundID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ClassID`,
  CHANGE `EmotesTextId` `EmotesTextID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `SoundID`;

ALTER TABLE `faction`
  MODIFY `ReputationRaceMask1` bigint(20) NOT NULL DEFAULT 0 FIRST ,
  MODIFY `ReputationRaceMask2` bigint(20) NOT NULL DEFAULT 0 AFTER `ReputationRaceMask1`,
  MODIFY `ReputationRaceMask3` bigint(20) NOT NULL DEFAULT 0 AFTER `ReputationRaceMask2`,
  MODIFY `ReputationRaceMask4` bigint(20) NOT NULL DEFAULT 0 AFTER `ReputationRaceMask3`,
  CHANGE `ParentFactionModIn` `ParentFactionMod1` float NOT NULL DEFAULT 0 AFTER `ReputationBase4`,
  CHANGE `ParentFactionModOut` `ParentFactionMod2` float NOT NULL DEFAULT 0 AFTER `ParentFactionMod1`,
  MODIFY `ReputationMax1` int(11) NOT NULL DEFAULT 0 AFTER `ParentFactionMod2`,
  MODIFY `ReputationMax2` int(11) NOT NULL DEFAULT 0 AFTER `ReputationMax1`,
  MODIFY `ReputationMax3` int(11) NOT NULL DEFAULT 0 AFTER `ReputationMax2`,
  MODIFY `ReputationMax4` int(11) NOT NULL DEFAULT 0 AFTER `ReputationMax3`,
  MODIFY `ReputationClassMask1` smallint(6) NOT NULL DEFAULT 0 AFTER `ReputationIndex`,
  MODIFY `ReputationClassMask2` smallint(6) NOT NULL DEFAULT 0 AFTER `ReputationClassMask1`,
  MODIFY `ReputationClassMask3` smallint(6) NOT NULL DEFAULT 0 AFTER `ReputationClassMask2`,
  MODIFY `ReputationClassMask4` smallint(6) NOT NULL DEFAULT 0 AFTER `ReputationClassMask3`,
  CHANGE `ParentFactionCapIn` `ParentFactionCap1` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ParagonFactionID`,
  CHANGE `ParentFactionCapOut` `ParentFactionCap2` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ParentFactionCap1`;

ALTER TABLE `faction_template`
  CHANGE `Friends1` `Friend1` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Enemies4`,
  CHANGE `Friends2` `Friend2` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Friend1`,
  CHANGE `Friends3` `Friend3` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Friend2`,
  CHANGE `Friends4` `Friend4` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Friend3`,
  CHANGE `Mask` `FactionGroup` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Friend4`,
  CHANGE `FriendMask` `FriendGroup` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FactionGroup`,
  CHANGE `EnemyMask` `EnemyGroup` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FriendGroup`;

ALTER TABLE `gameobjects`
  CHANGE `PositionX` `PosX` float NOT NULL DEFAULT 0 AFTER `Name`,
  CHANGE `PositionY` `PosY` float NOT NULL DEFAULT 0 AFTER `PosX`,
  CHANGE `PositionZ` `PosZ` float NOT NULL DEFAULT 0 AFTER `PosY`,
  CHANGE `RotationX` `Rot1` float NOT NULL DEFAULT 0 AFTER `PosZ`,
  CHANGE `RotationY` `Rot2` float NOT NULL DEFAULT 0 AFTER `Rot1`,
  CHANGE `RotationZ` `Rot3` float NOT NULL DEFAULT 0 AFTER `Rot2`,
  CHANGE `RotationW` `Rot4` float NOT NULL DEFAULT 0 AFTER `Rot3`,
  CHANGE `Size` `Scale` float NOT NULL DEFAULT 0 AFTER `Rot4`,
  CHANGE `Data1` `PropValue1` int(11) NOT NULL DEFAULT 0 AFTER `Scale`,
  CHANGE `Data2` `PropValue2` int(11) NOT NULL DEFAULT 0 AFTER `PropValue1`,
  CHANGE `Data3` `PropValue3` int(11) NOT NULL DEFAULT 0 AFTER `PropValue2`,
  CHANGE `Data4` `PropValue4` int(11) NOT NULL DEFAULT 0 AFTER `PropValue3`,
  CHANGE `Data5` `PropValue5` int(11) NOT NULL DEFAULT 0 AFTER `PropValue4`,
  CHANGE `Data6` `PropValue6` int(11) NOT NULL DEFAULT 0 AFTER `PropValue5`,
  CHANGE `Data7` `PropValue7` int(11) NOT NULL DEFAULT 0 AFTER `PropValue6`,
  CHANGE `Data8` `PropValue8` int(11) NOT NULL DEFAULT 0 AFTER `PropValue7`,
  CHANGE `MapID` `OwnerID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `PropValue8`,
  CHANGE `Type` `TypeID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `PhaseUseFlags`;

ALTER TABLE `gameobject_display_info`
  MODIFY `FileDataID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ObjectEffectPackageID` smallint(6) NOT NULL DEFAULT 0 AFTER `OverrideNameScale`;

ALTER TABLE `garr_ability`
  MODIFY `IconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `Description`,
  CHANGE `OtherFactionGarrAbilityID` `FactionChangeGarrAbilityID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `FollowerTypeID` `GarrFollowerTypeID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrAbilityCategoryID`;

ALTER TABLE `garr_building`
  CHANGE `NameAlliance` `AllianceName` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `ID`,
  CHANGE `NameHorde` `HordeName` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `AllianceName`,
  MODIFY `HordeGameObjectID` int(11) NOT NULL DEFAULT 0 AFTER `Tooltip`,
  MODIFY `AllianceGameObjectID` int(11) NOT NULL DEFAULT 0 AFTER `HordeGameObjectID`,
  MODIFY `IconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `AllianceGameObjectID`,
  CHANGE `CostCurrencyID` `CurrencyTypeID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `IconFileDataID`,
  CHANGE `HordeTexPrefixKitID` `HordeUiTextureKitID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyTypeID`,
  CHANGE `AllianceTexPrefixKitID` `AllianceUiTextureKitID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `HordeUiTextureKitID`,
  CHANGE `AllianceActivationScenePackageID` `AllianceSceneScriptPackageID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `AllianceUiTextureKitID`,
  CHANGE `HordeActivationScenePackageID` `HordeSceneScriptPackageID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `AllianceSceneScriptPackageID`,
  CHANGE `FollowerRequiredGarrAbilityID` `GarrAbilityID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `HordeSceneScriptPackageID`,
  CHANGE `FollowerGarrAbilityEffectID` `BonusGarrAbilityID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrAbilityID`,
  CHANGE `CostMoney` `GoldCost` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `BonusGarrAbilityID`,
  CHANGE `Unknown` `GarrSiteID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `GoldCost`,
  CHANGE `Type` `BuildingType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrSiteID`,
  CHANGE `Level` `UpgradeLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `BuildingType`,
  CHANGE `MaxShipments` `ShipmentCapacity` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `BuildDuration` `BuildSeconds` int(11) NOT NULL DEFAULT 0 AFTER `GarrTypeID`,
  CHANGE `CostCurrencyAmount` `CurrencyQty` int(11) NOT NULL DEFAULT 0 AFTER `BuildSeconds`,
  CHANGE `BonusAmount` `MaxAssignments` int(11) NOT NULL DEFAULT 0 AFTER `CurrencyQty`;

ALTER TABLE `garr_building_locale`
  CHANGE `NameAlliance_lang` `AllianceName_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `locale`,
  CHANGE `NameHorde_lang` `HordeName_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `AllianceName_lang`;

ALTER TABLE `garr_building_plot_inst`
  CHANGE `LandmarkOffsetX` `MapOffsetX` float NOT NULL DEFAULT 0 FIRST,
  CHANGE `LandmarkOffsetY` `MapOffsetY` float NOT NULL DEFAULT 0 AFTER `MapOffsetX`;

ALTER TABLE `garr_class_spec`
  CHANGE `NameMale` `ClassSpec` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL FIRST,
  CHANGE `NameFemale` `ClassSpecMale` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `ClassSpec`,
  CHANGE `NameGenderless` `ClassSpecFemale` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `ClassSpecMale`,
  CHANGE `ClassAtlasID` `UiTextureAtlasMemberID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ClassSpecFemale`,
  CHANGE `Limit` `FollowerClassLimit` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrFollItemSetID`;

ALTER TABLE `garr_class_spec_locale`
  CHANGE `NameMale_lang` `ClassSpec_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `locale`,
  CHANGE `NameFemale_lang` `ClassSpecMale_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `ClassSpec_lang`,
  CHANGE `NameGenderless_lang` `ClassSpecFemale_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `ClassSpecMale_lang`;

ALTER TABLE `garr_follower`
  CHANGE `Name` `TitleName` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `AllianceSourceText`,
  MODIFY `HordeCreatureID` int(11) NOT NULL DEFAULT 0 AFTER `TitleName`,
  MODIFY `AllianceCreatureID` int(11) NOT NULL DEFAULT 0 AFTER `HordeCreatureID`,
  CHANGE `HordePortraitIconID` `HordeIconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `AllianceCreatureID`,
  CHANGE `AlliancePortraitIconID` `AllianceIconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `HordeIconFileDataID`,
  CHANGE `HordeAddedBroadcastTextID` `HordeSlottingBroadcastTextID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `AllianceIconFileDataID`,
  CHANGE `AllianceAddedBroadcastTextID` `AllySlottingBroadcastTextID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `HordeSlottingBroadcastTextID`,
  CHANGE `HordeListPortraitTextureKitID` `HordeUITextureKitID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemLevelArmor`,
  CHANGE `AllianceListPortraitTextureKitID` `AllianceUITextureKitID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `HordeUITextureKitID`,
  CHANGE `FollowerTypeID` `GarrFollowerTypeID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `AllianceUITextureKitID`,
  CHANGE `HordeUiAnimRaceInfoID` `HordeGarrFollRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrFollowerTypeID`,
  CHANGE `AllianceUiAnimRaceInfoID` `AllianceGarrFollRaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `HordeGarrFollRaceID`,
  CHANGE `Level` `FollowerLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `AllianceGarrClassSpecID`,
  CHANGE `Unknown1` `Gender` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FollowerLevel`,
  CHANGE `Unknown2` `HordeSourceTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `Unknown3` `AllianceSourceTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `HordeSourceTypeEnum`,
  CHANGE `MaxDurability` `Vitality` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrTypeID`,
  CHANGE `Class` `ChrClassID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Vitality`,
  CHANGE `HordeFlavorTextGarrStringID` `HordeFlavorGarrStringID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChrClassID`,
  CHANGE `AllianceFlavorTextGarrStringID` `AllianceFlavorGarrStringID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `HordeFlavorGarrStringID`;

ALTER TABLE `garr_follower_locale` CHANGE `Name_lang` `TitleName_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `AllianceSourceText_lang`;

ALTER TABLE `garr_plot`
  CHANGE `AllianceConstructionGameObjectID` `AllianceConstructObjID` int(11) NOT NULL DEFAULT 0 AFTER `Name`,
  CHANGE `HordeConstructionGameObjectID` `HordeConstructObjID` int(11) NOT NULL DEFAULT 0 AFTER `AllianceConstructObjID`,
  CHANGE `GarrPlotUICategoryID` `UiCategoryID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `HordeConstructObjID`,
  CHANGE `MinCount` `UpgradeRequirement1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `MaxCount` `UpgradeRequirement2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `UpgradeRequirement1`;

DROP TABLE IF EXISTS `garr_plot_instance_locale`;

ALTER TABLE `garr_site_level`
  CHANGE `TownHallX` `TownHallUiPosX` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `TownHallY` `TownHallUiPosY` float NOT NULL DEFAULT 0 AFTER `TownHallUiPosX`,
  CHANGE `SiteID` `UiTextureKitID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `MapID`,
  CHANGE `MovieID` `UpgradeMovieID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UiTextureKitID`,
  CHANGE `UpgradeResourceCost` `UpgradeCost` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UpgradeMovieID`,
  CHANGE `UpgradeMoneyCost` `UpgradeGoldCost` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UpgradeCost`,
  CHANGE `Level` `GarrLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `UpgradeGoldCost`,
  CHANGE `UITextureKitID` `GarrSiteID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrLevel`,
  CHANGE `Level2` `MaxBuildingLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrSiteID`;

ALTER TABLE `garr_site_level_plot_inst`
  CHANGE `LandmarkX` `UiMarkerPosX` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `LandmarkY` `UiMarkerPosY` float NOT NULL DEFAULT 0 AFTER `UiMarkerPosX`,
  CHANGE `Unknown` `UiMarkerSize` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrPlotInstanceID`;

ALTER TABLE `gem_properties` CHANGE `EnchantID` `EnchantId` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Type`;

ALTER TABLE `glyph_bindable_spell`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `GlyphPropertiesID` smallint(6) NOT NULL DEFAULT 0 AFTER `SpellID`;

ALTER TABLE `glyph_properties` CHANGE `Type` `GlyphType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SpellIconID`;

ALTER TABLE `guild_perk_spells` MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `heirloom`
  MODIFY `ItemID` int(11) NOT NULL DEFAULT 0 AFTER `SourceText`,
  CHANGE `OldItem1` `LegacyItemID` int(11) NOT NULL DEFAULT 0 AFTER `ItemID`,
  CHANGE `OldItem2` `LegacyUpgradedItemID` int(11) NOT NULL DEFAULT 0 AFTER `LegacyItemID`,
  CHANGE `NextDifficultyItemID` `StaticUpgradedItemID` int(11) NOT NULL DEFAULT 0 AFTER `LegacyUpgradedItemID`,
  MODIFY `UpgradeItemID1` int(11) NOT NULL DEFAULT 0 AFTER `StaticUpgradedItemID`,
  MODIFY `UpgradeItemID2` int(11) NOT NULL DEFAULT 0 AFTER `UpgradeItemID1`,
  MODIFY `UpgradeItemID3` int(11) NOT NULL DEFAULT 0 AFTER `UpgradeItemID2`,
  CHANGE `ItemBonusListID1` `UpgradeItemBonusListID1` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UpgradeItemID3`,
  CHANGE `ItemBonusListID2` `UpgradeItemBonusListID2` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UpgradeItemBonusListID1`,
  CHANGE `ItemBonusListID3` `UpgradeItemBonusListID3` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UpgradeItemBonusListID2`,
  CHANGE `Source` `SourceTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `import_price_armor`
  CHANGE `ClothFactor` `ClothModifier` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `LeatherFactor` `LeatherModifier` float NOT NULL DEFAULT 0 AFTER `ClothModifier`,
  CHANGE `MailFactor` `ChainModifier` float NOT NULL DEFAULT 0 AFTER `LeatherModifier`,
  CHANGE `PlateFactor` `PlateModifier` float NOT NULL DEFAULT 0 AFTER `ChainModifier`;

ALTER TABLE `import_price_quality` CHANGE `Factor` `Data` float NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `import_price_shield` CHANGE `Factor` `Data` float NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `import_price_weapon` CHANGE `Factor` `Data` float NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item`
  CHANGE `FileDataID` `IconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Class` `ClassID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `IconFileDataID`,
  CHANGE `SubClass` `SubclassID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ClassID`,
  CHANGE `SoundOverrideSubclass` `SoundOverrideSubclassID` tinyint(4) NOT NULL DEFAULT 0 AFTER `SubclassID`,
  MODIFY `Material` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SoundOverrideSubclassID`,
  CHANGE `Sheath` `SheatheType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `InventoryType`,
  CHANGE `GroupSoundsID` `ItemGroupSoundsID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SheatheType`;

ALTER TABLE `item_appearance`
  CHANGE `DisplayID` `ItemDisplayInfoID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `IconFileDataID` `DefaultIconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `ItemDisplayInfoID`,
  CHANGE `UIOrder` `UiOrder` int(11) NOT NULL DEFAULT 0 AFTER `DefaultIconFileDataID`,
  CHANGE `ObjectComponentSlot` `DisplayType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `UiOrder`;

ALTER TABLE `item_armor_quality`
  CHANGE `QualityMod1` `Qualitymod1` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `QualityMod2` `Qualitymod2` float NOT NULL DEFAULT 0 AFTER `Qualitymod1`,
  CHANGE `QualityMod3` `Qualitymod3` float NOT NULL DEFAULT 0 AFTER `Qualitymod2`,
  CHANGE `QualityMod4` `Qualitymod4` float NOT NULL DEFAULT 0 AFTER `Qualitymod3`,
  CHANGE `QualityMod5` `Qualitymod5` float NOT NULL DEFAULT 0 AFTER `Qualitymod4`,
  CHANGE `QualityMod6` `Qualitymod6` float NOT NULL DEFAULT 0 AFTER `Qualitymod5`,
  CHANGE `QualityMod7` `Qualitymod7` float NOT NULL DEFAULT 0 AFTER `Qualitymod6`,
  MODIFY `ItemLevel` smallint(6) NOT NULL DEFAULT 0 AFTER `Qualitymod7`;

ALTER TABLE `item_armor_total`
  CHANGE `Value1` `Cloth` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Value2` `Leather` float NOT NULL DEFAULT 0 AFTER `Cloth`,
  CHANGE `Value3` `Mail` float NOT NULL DEFAULT 0 AFTER `Leather`,
  CHANGE `Value4` `Plate` float NOT NULL DEFAULT 0 AFTER `Mail`,
  MODIFY `ItemLevel` smallint(6) NOT NULL DEFAULT 0 AFTER `Plate`;

ALTER TABLE `item_bonus`
  CHANGE `BonusListID` `ParentItemBonusListID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Value3`,
  CHANGE `Index` `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Type`;

ALTER TABLE `item_bonus_list_level_delta` CHANGE `Delta` `ItemLevelDelta` smallint(6) NOT NULL DEFAULT 0 FIRST;

ALTER TABLE `item_bonus_tree_node`
  CHANGE `SubTreeID` `ChildItemBonusTreeID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `BonusListID` `ChildItemBonusListID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChildItemBonusTreeID`,
  CHANGE `ItemLevelSelectorID` `ChildItemLevelSelectorID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChildItemBonusListID`,
  CHANGE `BonusTreeModID` `ItemContext` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChildItemLevelSelectorID`,
  CHANGE `BonusTreeID` `ParentItemBonusTreeID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemContext`;

ALTER TABLE `item_child_equipment`
  CHANGE `AltItemID` `ChildItemID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `AltEquipmentSlot` `ChildItemEquipSlot` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChildItemID`,
  CHANGE `ItemID` `ParentItemID` int(11) NOT NULL DEFAULT 0 AFTER `ChildItemEquipSlot`;

ALTER TABLE `item_class`
  CHANGE `Name` `ClassName` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `ID`,
  CHANGE `PriceMod` `PriceModifier` float NOT NULL DEFAULT 0 AFTER `ClassName`,
  CHANGE `OldEnumValue` `ClassID` tinyint(4) NOT NULL DEFAULT 0 AFTER `PriceModifier`;

ALTER TABLE `item_class_locale` CHANGE `Name_lang` `ClassName_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `locale`;

ALTER TABLE `item_currency_cost` CHANGE `ItemId` `ItemID` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_damage_ammo`
  CHANGE `DPS1` `Quality1` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `DPS2` `Quality2` float NOT NULL DEFAULT 0 AFTER `Quality1`,
  CHANGE `DPS3` `Quality3` float NOT NULL DEFAULT 0 AFTER `Quality2`,
  CHANGE `DPS4` `Quality4` float NOT NULL DEFAULT 0 AFTER `Quality3`,
  CHANGE `DPS5` `Quality5` float NOT NULL DEFAULT 0 AFTER `Quality4`,
  CHANGE `DPS6` `Quality6` float NOT NULL DEFAULT 0 AFTER `Quality5`,
  CHANGE `DPS7` `Quality7` float NOT NULL DEFAULT 0 AFTER `Quality6`;

ALTER TABLE `item_damage_one_hand`
  CHANGE `DPS1` `Quality1` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `DPS2` `Quality2` float NOT NULL DEFAULT 0 AFTER `Quality1`,
  CHANGE `DPS3` `Quality3` float NOT NULL DEFAULT 0 AFTER `Quality2`,
  CHANGE `DPS4` `Quality4` float NOT NULL DEFAULT 0 AFTER `Quality3`,
  CHANGE `DPS5` `Quality5` float NOT NULL DEFAULT 0 AFTER `Quality4`,
  CHANGE `DPS6` `Quality6` float NOT NULL DEFAULT 0 AFTER `Quality5`,
  CHANGE `DPS7` `Quality7` float NOT NULL DEFAULT 0 AFTER `Quality6`;

ALTER TABLE `item_damage_one_hand_caster`
  CHANGE `DPS1` `Quality1` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `DPS2` `Quality2` float NOT NULL DEFAULT 0 AFTER `Quality1`,
  CHANGE `DPS3` `Quality3` float NOT NULL DEFAULT 0 AFTER `Quality2`,
  CHANGE `DPS4` `Quality4` float NOT NULL DEFAULT 0 AFTER `Quality3`,
  CHANGE `DPS5` `Quality5` float NOT NULL DEFAULT 0 AFTER `Quality4`,
  CHANGE `DPS6` `Quality6` float NOT NULL DEFAULT 0 AFTER `Quality5`,
  CHANGE `DPS7` `Quality7` float NOT NULL DEFAULT 0 AFTER `Quality6`;

ALTER TABLE `item_damage_two_hand`
  CHANGE `DPS1` `Quality1` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `DPS2` `Quality2` float NOT NULL DEFAULT 0 AFTER `Quality1`,
  CHANGE `DPS3` `Quality3` float NOT NULL DEFAULT 0 AFTER `Quality2`,
  CHANGE `DPS4` `Quality4` float NOT NULL DEFAULT 0 AFTER `Quality3`,
  CHANGE `DPS5` `Quality5` float NOT NULL DEFAULT 0 AFTER `Quality4`,
  CHANGE `DPS6` `Quality6` float NOT NULL DEFAULT 0 AFTER `Quality5`,
  CHANGE `DPS7` `Quality7` float NOT NULL DEFAULT 0 AFTER `Quality6`;

ALTER TABLE `item_damage_two_hand_caster`
  CHANGE `DPS1` `Quality1` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `DPS2` `Quality2` float NOT NULL DEFAULT 0 AFTER `Quality1`,
  CHANGE `DPS3` `Quality3` float NOT NULL DEFAULT 0 AFTER `Quality2`,
  CHANGE `DPS4` `Quality4` float NOT NULL DEFAULT 0 AFTER `Quality3`,
  CHANGE `DPS5` `Quality5` float NOT NULL DEFAULT 0 AFTER `Quality4`,
  CHANGE `DPS6` `Quality6` float NOT NULL DEFAULT 0 AFTER `Quality5`,
  CHANGE `DPS7` `Quality7` float NOT NULL DEFAULT 0 AFTER `Quality6`;

ALTER TABLE `item_disenchant_loot`
  CHANGE `MinItemLevel` `MinLevel` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `MaxItemLevel` `MaxLevel` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `MinLevel`,
  CHANGE `RequiredDisenchantSkill` `SkillRequired` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `MaxLevel`,
  CHANGE `ItemSubClass` `Subclass` tinyint(4) NOT NULL DEFAULT 0 AFTER `SkillRequired`,
  CHANGE `ItemQuality` `Quality` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Subclass`,
  CHANGE `Expansion` `ExpansionID` tinyint(4) NOT NULL DEFAULT 0 AFTER `Quality`,
  CHANGE `ItemClass` `Class` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ExpansionID`;

ALTER TABLE `item_effect`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Cooldown` `CoolDownMSec` int(11) NOT NULL DEFAULT 0 AFTER `SpellID`,
  CHANGE `CategoryCooldown` `CategoryCoolDownMSec` int(11) NOT NULL DEFAULT 0 AFTER `CoolDownMSec`,
  CHANGE `Category` `SpellCategoryID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Charges`,
  CHANGE `OrderIndex` `LegacySlotIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChrSpecializationID`,
  CHANGE `Trigger` `TriggerType` tinyint(4) NOT NULL DEFAULT 0 AFTER `LegacySlotIndex`,
  CHANGE `ItemID` `ParentItemID` int(11) NOT NULL DEFAULT 0 AFTER `TriggerType`;

ALTER TABLE `item_extended_cost`
  CHANGE `RequiredItem1` `ItemID1` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `RequiredItem2` `ItemID2` int(11) NOT NULL DEFAULT 0 AFTER `ItemID1`,
  CHANGE `RequiredItem3` `ItemID3` int(11) NOT NULL DEFAULT 0 AFTER `ItemID2`,
  CHANGE `RequiredItem4` `ItemID4` int(11) NOT NULL DEFAULT 0 AFTER `ItemID3`,
  CHANGE `RequiredItem5` `ItemID5` int(11) NOT NULL DEFAULT 0 AFTER `ItemID4`,
  CHANGE `RequiredCurrencyCount1` `CurrencyCount1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemID5`,
  CHANGE `RequiredCurrencyCount2` `CurrencyCount2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyCount1`,
  CHANGE `RequiredCurrencyCount3` `CurrencyCount3` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyCount2`,
  CHANGE `RequiredCurrencyCount4` `CurrencyCount4` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyCount3`,
  CHANGE `RequiredCurrencyCount5` `CurrencyCount5` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyCount4`,
  CHANGE `RequiredItemCount1` `ItemCount1` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyCount5`,
  CHANGE `RequiredItemCount2` `ItemCount2` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemCount1`,
  CHANGE `RequiredItemCount3` `ItemCount3` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemCount2`,
  CHANGE `RequiredItemCount4` `ItemCount4` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemCount3`,
  CHANGE `RequiredItemCount5` `ItemCount5` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemCount4`,
  CHANGE `RequiredPersonalArenaRating` `RequiredArenaRating` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemCount5`,
  CHANGE `RequiredCurrency1` `CurrencyID1` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredArenaRating`,
  CHANGE `RequiredCurrency2` `CurrencyID2` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyID1`,
  CHANGE `RequiredCurrency3` `CurrencyID3` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyID2`,
  CHANGE `RequiredCurrency4` `CurrencyID4` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyID3`,
  CHANGE `RequiredCurrency5` `CurrencyID5` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyID4`,
  CHANGE `RequiredArenaSlot` `ArenaBracket` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyID5`,
  CHANGE `RequiredFactionId` `MinFactionID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ArenaBracket`,
  CHANGE `RequiredFactionStanding` `MinReputation` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `MinFactionID`,
  CHANGE `RequirementFlags` `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `MinReputation`;

ALTER TABLE `item_level_selector` CHANGE `ItemLevel` `MinItemLevel` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_level_selector_quality`
  CHANGE `ItemBonusListID` `QualityItemBonusListID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Quality` tinyint(4) NOT NULL DEFAULT 0 AFTER `QualityItemBonusListID`,
  CHANGE `ItemLevelSelectorQualitySetID` `ParentILSQualitySetID` smallint(6) NOT NULL DEFAULT 0 AFTER `Quality`;

ALTER TABLE `item_level_selector_quality_set`
  CHANGE `ItemLevelMin` `IlvlRare` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `ItemLevelMax` `IlvlEpic` smallint(6) NOT NULL DEFAULT 0 AFTER `IlvlRare`;

ALTER TABLE `item_modified_appearance`
  MODIFY `ItemID` int(11) NOT NULL DEFAULT 0 FIRST,
  CHANGE `AppearanceModID` `ItemAppearanceModifierID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `AppearanceID` `ItemAppearanceID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemAppearanceModifierID`,
  CHANGE `Index` `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemAppearanceID`,
  CHANGE `SourceType` `TransmogSourceTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `OrderIndex`;

ALTER TABLE `item_price_base`
  CHANGE `ArmorFactor` `Armor` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `WeaponFactor` `Weapon` float NOT NULL DEFAULT 0 AFTER `Armor`;

ALTER TABLE `item_search_name`
  MODIFY `AllowableRace` bigint(20) NOT NULL DEFAULT 0 FIRST,
  CHANGE `Name` `Display` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `AllowableRace`,
  MODIFY `Flags1` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Flags2` int(11) NOT NULL DEFAULT 0 AFTER `Flags1`,
  MODIFY `Flags3` int(11) NOT NULL DEFAULT 0 AFTER `Flags2`,
  CHANGE `Quality` `OverallQualityID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemLevel`,
  CHANGE `RequiredExpansion` `ExpansionID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `OverallQualityID`,
  MODIFY `RequiredLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `ExpansionID`,
  CHANGE `RequiredReputationFaction` `MinFactionID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredLevel`,
  CHANGE `RequiredReputationRank` `MinReputation` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `MinFactionID`,
  CHANGE `RequiredSpell` `RequiredAbility` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredSkillRank`;

ALTER TABLE `item_search_name_locale` CHANGE `Name_lang` `Display_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `locale`;

ALTER TABLE `item_set` CHANGE `Flags` `SetFlags` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredSkill`;

ALTER TABLE `item_sparse`
  CHANGE `Name` `Display` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `AllowableRace`,
  CHANGE `Name2` `Display1` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Display`,
  CHANGE `Name3` `Display2` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Display1`,
  CHANGE `Name4` `Display3` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Display2`,
  MODIFY `Flags1` int(11) NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `Flags2` int(11) NOT NULL DEFAULT 0 AFTER `Flags1`,
  MODIFY `Flags3` int(11) NOT NULL DEFAULT 0 AFTER `Flags2`,
  MODIFY `Flags4` int(11) NOT NULL DEFAULT 0 AFTER `Flags3`,
  CHANGE `Unk1` `PriceRandomValue` float NOT NULL DEFAULT 0 AFTER `Flags4`,
  CHANGE `Unk2` `PriceVariance` float NOT NULL DEFAULT 0 AFTER `PriceRandomValue`,
  CHANGE `BuyCount` `VendorStackCount` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `PriceVariance`,
  CHANGE `RequiredSpell` `RequiredAbility` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `SellPrice`,
  MODIFY `MaxCount` int(11) NOT NULL DEFAULT 0 AFTER `RequiredAbility`,
  MODIFY `Stackable` int(11) NOT NULL DEFAULT 0 AFTER `MaxCount`,
  CHANGE `ItemStatAllocation1` `StatPercentEditor1` int(11) NOT NULL DEFAULT 0 AFTER `Stackable`,
  CHANGE `ItemStatAllocation2` `StatPercentEditor2` int(11) NOT NULL DEFAULT 0 AFTER `StatPercentEditor1`,
  CHANGE `ItemStatAllocation3` `StatPercentEditor3` int(11) NOT NULL DEFAULT 0 AFTER `StatPercentEditor2`,
  CHANGE `ItemStatAllocation4` `StatPercentEditor4` int(11) NOT NULL DEFAULT 0 AFTER `StatPercentEditor3`,
  CHANGE `ItemStatAllocation5` `StatPercentEditor5` int(11) NOT NULL DEFAULT 0 AFTER `StatPercentEditor4`,
  CHANGE `ItemStatAllocation6` `StatPercentEditor6` int(11) NOT NULL DEFAULT 0 AFTER `StatPercentEditor5`,
  CHANGE `ItemStatAllocation7` `StatPercentEditor7` int(11) NOT NULL DEFAULT 0 AFTER `StatPercentEditor6`,
  CHANGE `ItemStatAllocation8` `StatPercentEditor8` int(11) NOT NULL DEFAULT 0 AFTER `StatPercentEditor7`,
  CHANGE `ItemStatAllocation9` `StatPercentEditor9` int(11) NOT NULL DEFAULT 0 AFTER `StatPercentEditor8`,
  CHANGE `ItemStatAllocation10` `StatPercentEditor10` int(11) NOT NULL DEFAULT 0 AFTER `StatPercentEditor9`,
  CHANGE `ItemStatSocketCostMultiplier1` `StatPercentageOfSocket1` float NOT NULL DEFAULT 0 AFTER `StatPercentEditor10`,
  CHANGE `ItemStatSocketCostMultiplier2` `StatPercentageOfSocket2` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket1`,
  CHANGE `ItemStatSocketCostMultiplier3` `StatPercentageOfSocket3` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket2`,
  CHANGE `ItemStatSocketCostMultiplier4` `StatPercentageOfSocket4` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket3`,
  CHANGE `ItemStatSocketCostMultiplier5` `StatPercentageOfSocket5` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket4`,
  CHANGE `ItemStatSocketCostMultiplier6` `StatPercentageOfSocket6` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket5`,
  CHANGE `ItemStatSocketCostMultiplier7` `StatPercentageOfSocket7` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket6`,
  CHANGE `ItemStatSocketCostMultiplier8` `StatPercentageOfSocket8` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket7`,
  CHANGE `ItemStatSocketCostMultiplier9` `StatPercentageOfSocket9` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket8`,
  CHANGE `ItemStatSocketCostMultiplier10` `StatPercentageOfSocket10` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket9`,
  CHANGE `RangedModRange` `ItemRange` float NOT NULL DEFAULT 0 AFTER `StatPercentageOfSocket10`,
  CHANGE `ArmorDamageModifier` `QualityModifier` float NOT NULL DEFAULT 0 AFTER `BagFamily`,
  CHANGE `Duration` `DurationInInventory` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `QualityModifier`,
  CHANGE `StatScalingFactor` `DmgVariance` float NOT NULL DEFAULT 0 AFTER `DurationInInventory`,
  CHANGE `RequiredReputationFaction` `MinFactionID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredSkillRank`,
  CHANGE `ScalingStatDistribution` `ScalingStatDistributionID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemStatValue10`,
  CHANGE `Delay` `ItemDelay` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ScalingStatDistributionID`,
  CHANGE `PageText` `PageID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemDelay`,
  CHANGE `StartQuest` `StartQuestID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `PageID`,
  CHANGE `RandomProperty` `RandomSelect` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `LockID`,
  CHANGE `RandomSuffix` `ItemRandomSuffixGroupID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `RandomSelect`,
  CHANGE `Area` `ZoneBound` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemSet`,
  CHANGE `Map` `InstanceBound` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ZoneBound`,
  CHANGE `TotemCategory` `TotemCategoryID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `InstanceBound`,
  CHANGE `SocketBonus` `SocketMatchEnchantmentId` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `TotemCategoryID`,
  CHANGE `ItemLimitCategory` `LimitCategory` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `GemProperties`,
  CHANGE `HolidayID` `RequiredHoliday` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `LimitCategory`,
  CHANGE `RequiredTransmogHolidayID` `RequiredTransmogHoliday` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredHoliday`,
  CHANGE `Quality` `OverallQualityID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemNameDescriptionID`,
  CHANGE `RequiredHonorRank` `RequiredPVPRank` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredLevel`,
  CHANGE `RequiredCityRank` `RequiredPVPMedal` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredPVPRank`,
  CHANGE `RequiredReputationRank` `MinReputation` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredPVPMedal`,
  CHANGE `ItemStatType1` `StatModifierBonusStat1` tinyint(4) NOT NULL DEFAULT 0 AFTER `ContainerSlots`,
  CHANGE `ItemStatType2` `StatModifierBonusStat2` tinyint(4) NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat1`,
  CHANGE `ItemStatType3` `StatModifierBonusStat3` tinyint(4) NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat2`,
  CHANGE `ItemStatType4` `StatModifierBonusStat4` tinyint(4) NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat3`,
  CHANGE `ItemStatType5` `StatModifierBonusStat5` tinyint(4) NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat4`,
  CHANGE `ItemStatType6` `StatModifierBonusStat6` tinyint(4) NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat5`,
  CHANGE `ItemStatType7` `StatModifierBonusStat7` tinyint(4) NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat6`,
  CHANGE `ItemStatType8` `StatModifierBonusStat8` tinyint(4) NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat7`,
  CHANGE `ItemStatType9` `StatModifierBonusStat9` tinyint(4) NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat8`,
  CHANGE `ItemStatType10` `StatModifierBonusStat10` tinyint(4) NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat9`,
  CHANGE `DamageType` `DamageDamageType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat10`,
  CHANGE `PageMaterial` `PageMaterialID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `LanguageID`,
  MODIFY `Material` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `PageMaterialID`,
  CHANGE `Sheath` `SheatheType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Material`,
  CHANGE `SocketColor1` `SocketType1` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SheatheType`,
  CHANGE `SocketColor2` `SocketType2` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SocketType1`,
  CHANGE `SocketColor3` `SocketType3` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SocketType2`,
  CHANGE `CurrencySubstitutionID` `SpellWeightCategory` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SocketType3`,
  CHANGE `CurrencySubstitutionCount` `SpellWeight` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SpellWeightCategory`,
  CHANGE `RequiredExpansion` `ExpansionID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ArtifactID`;

ALTER TABLE `item_sparse_locale`
  CHANGE `Name_lang` `Display_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `locale`,
  CHANGE `Name2_lang` `Display1_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Display_lang`,
  CHANGE `Name3_lang` `Display2_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Display1_lang`,
  CHANGE `Name4_lang` `Display3_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Display2_lang`;

ALTER TABLE `item_spec` CHANGE `SpecID` `SpecializationID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_spec_override` MODIFY `ItemID` int(11) NOT NULL DEFAULT 0 AFTER `SpecID`;

ALTER TABLE `item_upgrade`
  CHANGE `CurrencyCost` `CurrencyAmount` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `PrevItemUpgradeID` `PrerequisiteID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `CurrencyAmount`,
  CHANGE `CurrencyID` `CurrencyType` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `PrerequisiteID`,
  CHANGE `ItemLevelBonus` `ItemLevelIncrement` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemUpgradePathID`;

ALTER TABLE `item_x_bonus_tree`
  CHANGE `BonusTreeID` `ItemBonusTreeID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ItemID` int(11) NOT NULL DEFAULT 0 AFTER `ItemBonusTreeID`;

ALTER TABLE `lfg_dungeons`
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `Description`,
  CHANGE `MinItemLevel` `MinGear` float NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `LastBossJournalEncounterID` `FinalEncounterID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ScenarioID`,
  CHANGE `PlayerConditionID` `RequiredPlayerConditionId` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `MentorItemLevel`,
  CHANGE `Type` `TypeID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `Faction` tinyint(4) NOT NULL DEFAULT 0 AFTER `TypeID`,
  CHANGE `Expansion` `ExpansionLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Faction`,
  CHANGE `SubType` `Subtype` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `MinCountDamage`,
  CHANGE `TextureFileDataID` `IconTextureFileID` int(11) NOT NULL DEFAULT 0 AFTER `MentorCharLevel`,
  CHANGE `RewardIconFileDataID` `RewardsBgTextureFileID` int(11) NOT NULL DEFAULT 0 AFTER `IconTextureFileID`,
  CHANGE `ProposalTextureFileDataID` `PopupBgTextureFileID` int(11) NOT NULL DEFAULT 0 AFTER `RewardsBgTextureFileID`;

ALTER TABLE `light`
  CHANGE `PosX` `GameCoordsX` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `PosY` `GameCoordsY` float NOT NULL DEFAULT 0 AFTER `GameCoordsX`,
  CHANGE `PosZ` `GameCoordsZ` float NOT NULL DEFAULT 0 AFTER `GameCoordsY`,
  CHANGE `FalloffStart` `GameFalloffStart` float NOT NULL DEFAULT 0 AFTER `GameCoordsZ`,
  CHANGE `FalloffEnd` `GameFalloffEnd` float NOT NULL DEFAULT 0 AFTER `GameFalloffStart`,
  CHANGE `MapID` `ContinentID` smallint(6) NOT NULL DEFAULT 0 AFTER `GameFalloffEnd`;

ALTER TABLE `liquid_type`
  MODIFY `Color1` int(11) NOT NULL DEFAULT 0 AFTER `ParticleScale`,
  MODIFY `Color2` int(11) NOT NULL DEFAULT 0 AFTER `Color1`,
  CHANGE `Type` `SoundBank` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `LightID`,
  CHANGE `DepthTexCount1` `FrameCountTexture1` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `MaterialID`,
  CHANGE `DepthTexCount2` `FrameCountTexture2` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FrameCountTexture1`,
  CHANGE `DepthTexCount3` `FrameCountTexture3` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FrameCountTexture2`,
  CHANGE `DepthTexCount4` `FrameCountTexture4` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FrameCountTexture3`,
  CHANGE `DepthTexCount5` `FrameCountTexture5` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FrameCountTexture4`,
  CHANGE `DepthTexCount6` `FrameCountTexture6` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FrameCountTexture5`;

DROP TABLE IF EXISTS `liquid_type_locale`;

ALTER TABLE `lock`
  MODIFY `Index1` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Index2` int(11) NOT NULL DEFAULT 0 AFTER `Index1`,
  MODIFY `Index3` int(11) NOT NULL DEFAULT 0 AFTER `Index2`,
  MODIFY `Index4` int(11) NOT NULL DEFAULT 0 AFTER `Index3`,
  MODIFY `Index5` int(11) NOT NULL DEFAULT 0 AFTER `Index4`,
  MODIFY `Index6` int(11) NOT NULL DEFAULT 0 AFTER `Index5`,
  MODIFY `Index7` int(11) NOT NULL DEFAULT 0 AFTER `Index6`,
  MODIFY `Index8` int(11) NOT NULL DEFAULT 0 AFTER `Index7`;

ALTER TABLE `map`
  CHANGE `ShortDescription` `PvpShortDescription` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `MapDescription1`,
  CHANGE `LongDescription` `PvpLongDescription` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `PvpShortDescription`,
  MODIFY `Flags1` int(11) NOT NULL DEFAULT 0 AFTER `PvpLongDescription`,
  MODIFY `Flags2` int(11) NOT NULL DEFAULT 0 AFTER `Flags1`,
  CHANGE `CorpsePosX` `CorpseX` float NOT NULL DEFAULT 0 AFTER `MinimapIconScale`,
  CHANGE `CorpsePosY` `CorpseY` float NOT NULL DEFAULT 0 AFTER `CorpseX`,
  MODIFY `LoadingScreenID` smallint(6) NOT NULL DEFAULT 0 AFTER `AreaTableID`,
  MODIFY `TimeOfDayOverride` smallint(6) NOT NULL DEFAULT 0 AFTER `CorpseMapID`,
  MODIFY `WindSettingsID` smallint(6) NOT NULL DEFAULT 0 AFTER `CosmeticParentMapID`,
  CHANGE `unk5` `MapType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `InstanceType`;

ALTER TABLE `map_locale`
  CHANGE `ShortDescription_lang` `PvpShortDescription_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `MapDescription1_lang`,
  CHANGE `LongDescription_lang` `PvpLongDescription_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `PvpShortDescription_lang`;

ALTER TABLE `map_difficulty`
  CHANGE `RaidDurationType` `ResetInterval` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  CHANGE `ItemBonusTreeModID` `ItemContext` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `Context` `ItemContextPickerID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemContext`;

ALTER TABLE `modifier_tree`
  CHANGE `Asset1` `Asset` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Asset2` `SecondaryAsset` int(11) NOT NULL DEFAULT 0 AFTER `Asset`,
  CHANGE `Unk700` `TertiaryAsset` tinyint(4) NOT NULL DEFAULT 0 AFTER `Type`,
  MODIFY `Operator` tinyint(4) NOT NULL DEFAULT 0 AFTER `TertiaryAsset`,
  MODIFY `Amount` tinyint(4) NOT NULL DEFAULT 0 AFTER `Operator`;

ALTER TABLE `mount`
  CHANGE `SourceDescription` `SourceText` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Description`,
  CHANGE `SpellId` `SourceSpellID` int(11) NOT NULL DEFAULT 0 AFTER `SourceText`,
  CHANGE `CameraPivotMultiplier` `MountFlyRideHeight` float NOT NULL DEFAULT 0 AFTER `SourceSpellID`,
  CHANGE `MountTypeId` `MountTypeID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `MountFlyRideHeight`,
  CHANGE `Source` `SourceTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `PlayerConditionId` `PlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `mount_locale` CHANGE `SourceDescription_lang` `SourceText_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Description_lang`;

ALTER TABLE `mount_capability`
  CHANGE `RequiredSpell` `ReqSpellKnownID` int(11) NOT NULL DEFAULT 0 FIRST,
  CHANGE `SpeedModSpell` `ModSpellAuraID` int(11) NOT NULL DEFAULT 0 AFTER `ReqSpellKnownID`,
  CHANGE `RequiredRidingSkill` `ReqRidingSkill` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ModSpellAuraID`,
  CHANGE `RequiredArea` `ReqAreaID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ReqRidingSkill`,
  CHANGE `RequiredMap` `ReqMapID` smallint(6) NOT NULL DEFAULT 0 AFTER `ReqAreaID`,
  CHANGE `RequiredAura` `ReqSpellAuraID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `mount_x_display`
  CHANGE `DisplayID` `CreatureDisplayInfoID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `PlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `CreatureDisplayInfoID`,
  MODIFY `MountID` int(11) NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

ALTER TABLE `name_gen` CHANGE `Race` `RaceID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Name`;

DROP TABLE IF EXISTS `name_gen_locale`;

ALTER TABLE `override_spell_data`
  CHANGE `SpellID1` `Spells1` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `SpellID2` `Spells2` int(11) NOT NULL DEFAULT 0 AFTER `Spells1`,
  CHANGE `SpellID3` `Spells3` int(11) NOT NULL DEFAULT 0 AFTER `Spells2`,
  CHANGE `SpellID4` `Spells4` int(11) NOT NULL DEFAULT 0 AFTER `Spells3`,
  CHANGE `SpellID5` `Spells5` int(11) NOT NULL DEFAULT 0 AFTER `Spells4`,
  CHANGE `SpellID6` `Spells6` int(11) NOT NULL DEFAULT 0 AFTER `Spells5`,
  CHANGE `SpellID7` `Spells7` int(11) NOT NULL DEFAULT 0 AFTER `Spells6`,
  CHANGE `SpellID8` `Spells8` int(11) NOT NULL DEFAULT 0 AFTER `Spells7`,
  CHANGE `SpellID9` `Spells9` int(11) NOT NULL DEFAULT 0 AFTER `Spells8`,
  CHANGE `SpellID10` `Spells10` int(11) NOT NULL DEFAULT 0 AFTER `Spells9`,
  CHANGE `PlayerActionbarFileDataID` `PlayerActionBarFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `Spells10`;

ALTER TABLE `player_condition`
  CHANGE `Unknown1` `CurrentPvpFaction` tinyint(4) NOT NULL DEFAULT 0 AFTER `ReputationLogic`,
  CHANGE `MainHandItemSubclassMask` `WeaponSubclassMask` int(11) NOT NULL DEFAULT 0 AFTER `ModifierTreeID`,
  MODIFY `AuraSpellID1` int(11) NOT NULL DEFAULT 0 AFTER `Time2`,
  MODIFY `AuraSpellID2` int(11) NOT NULL DEFAULT 0 AFTER `AuraSpellID1`,
  MODIFY `AuraSpellID3` int(11) NOT NULL DEFAULT 0 AFTER `AuraSpellID2`,
  MODIFY `AuraSpellID4` int(11) NOT NULL DEFAULT 0 AFTER `AuraSpellID3`,
  CHANGE `AuraCount1` `AuraStacks1` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `AuraSpellID4`,
  CHANGE `AuraCount2` `AuraStacks2` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `AuraStacks1`,
  CHANGE `AuraCount3` `AuraStacks3` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `AuraStacks2`,
  CHANGE `AuraCount4` `AuraStacks4` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `AuraStacks3`;

ALTER TABLE `power_display` CHANGE `PowerType` `ActualType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `GlobalStringBaseTag`;

ALTER TABLE `power_type`
  CHANGE `PowerTypeToken` `NameGlobalStringTag` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `ID`,
  CHANGE `PowerCostToken` `CostGlobalStringTag` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `NameGlobalStringTag`,
  CHANGE `RegenerationPeace` `RegenPeace` float NOT NULL DEFAULT 0 AFTER `CostGlobalStringTag`,
  CHANGE `RegenerationCombat` `RegenCombat` float NOT NULL DEFAULT 0 AFTER `RegenPeace`,
  CHANGE `MaxPower` `MaxBasePower` smallint(6) NOT NULL DEFAULT 0 AFTER `RegenCombat`,
  CHANGE `RegenerationDelay` `RegenInterruptTimeMS` smallint(6) NOT NULL DEFAULT 0 AFTER `MaxBasePower`,
  MODIFY `Flags` smallint(6) NOT NULL DEFAULT 0 AFTER `RegenInterruptTimeMS`,
  MODIFY `PowerTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `RegenerationMin` `MinPower` tinyint(4) NOT NULL DEFAULT 0 AFTER `PowerTypeEnum`,
  CHANGE `RegenerationCenter` `CenterPower` tinyint(4) NOT NULL DEFAULT 0 AFTER `MinPower`,
  CHANGE `RegenerationMax` `DefaultPower` tinyint(4) NOT NULL DEFAULT 0 AFTER `CenterPower`,
  CHANGE `UIModifier` `DisplayModifier` tinyint(4) NOT NULL DEFAULT 0 AFTER `DefaultPower`;

ALTER TABLE `prestige_level_info`
 CHANGE `PrestigeText` `Name` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `ID`,
  CHANGE `IconID` `BadgeTextureFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `prestige_level_info_locale` CHANGE `PrestigeText_lang` `Name_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `locale`;

ALTER TABLE `pvp_difficulty` CHANGE `BracketID` `RangeIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `pvp_item`
  MODIFY `ItemID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `ItemLevelBonus` `ItemLevelDelta` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemID`;

ALTER TABLE `pvp_reward`
  MODIFY `HonorLevel` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Prestige` `PrestigeLevel` int(11) NOT NULL DEFAULT 0 AFTER `HonorLevel`,
  MODIFY `RewardPackID` int(11) NOT NULL DEFAULT 0 AFTER `PrestigeLevel`;

ALTER TABLE `pvp_talent`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `OverridesSpellID` int(11) NOT NULL DEFAULT 0 AFTER `SpellID`,
  CHANGE `ExtraSpellID` `ActionBarSpellID` int(11) NOT NULL DEFAULT 0 AFTER `OverridesSpellID`,
  MODIFY `TierID` int(11) NOT NULL DEFAULT 0 AFTER `ActionBarSpellID`,
  MODIFY `ColumnIndex` int(11) NOT NULL DEFAULT 0 AFTER `TierID`,
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `ColumnIndex`,
  MODIFY `ClassID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `SpecID` int(11) NOT NULL DEFAULT 0 AFTER `ClassID`,
  MODIFY `Role` int(11) NOT NULL DEFAULT 0 AFTER `SpecID`;

ALTER TABLE `pvp_talent_unlock`
  MODIFY `TierID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ColumnIndex` int(11) NOT NULL DEFAULT 0 AFTER `TierID`,
  MODIFY `HonorLevel` int(11) NOT NULL DEFAULT 0 AFTER `ColumnIndex`;

ALTER TABLE `quest_faction_reward`
  CHANGE `QuestRewFactionValue1` `Difficulty1` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `QuestRewFactionValue2` `Difficulty2` smallint(6) NOT NULL DEFAULT 0 AFTER `Difficulty1`,
  CHANGE `QuestRewFactionValue3` `Difficulty3` smallint(6) NOT NULL DEFAULT 0 AFTER `Difficulty2`,
  CHANGE `QuestRewFactionValue4` `Difficulty4` smallint(6) NOT NULL DEFAULT 0 AFTER `Difficulty3`,
  CHANGE `QuestRewFactionValue5` `Difficulty5` smallint(6) NOT NULL DEFAULT 0 AFTER `Difficulty4`,
  CHANGE `QuestRewFactionValue6` `Difficulty6` smallint(6) NOT NULL DEFAULT 0 AFTER `Difficulty5`,
  CHANGE `QuestRewFactionValue7` `Difficulty7` smallint(6) NOT NULL DEFAULT 0 AFTER `Difficulty6`,
  CHANGE `QuestRewFactionValue8` `Difficulty8` smallint(6) NOT NULL DEFAULT 0 AFTER `Difficulty7`,
  CHANGE `QuestRewFactionValue9` `Difficulty9` smallint(6) NOT NULL DEFAULT 0 AFTER `Difficulty8`,
  CHANGE `QuestRewFactionValue10` `Difficulty10` smallint(6) NOT NULL DEFAULT 0 AFTER `Difficulty9`;

ALTER TABLE `quest_money_reward`
  CHANGE `Money1` `Difficulty1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Money2` `Difficulty2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty1`,
  CHANGE `Money3` `Difficulty3` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty2`,
  CHANGE `Money4` `Difficulty4` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty3`,
  CHANGE `Money5` `Difficulty5` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty4`,
  CHANGE `Money6` `Difficulty6` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty5`,
  CHANGE `Money7` `Difficulty7` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty6`,
  CHANGE `Money8` `Difficulty8` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty7`,
  CHANGE `Money9` `Difficulty9` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty8`,
  CHANGE `Money10` `Difficulty10` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty9`;

ALTER TABLE `quest_package_item`
  MODIFY `ItemID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `QuestPackageID` `PackageID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemID`,
  CHANGE `FilterType` `DisplayType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `PackageID`,
  CHANGE `ItemCount` `ItemQuantity` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `DisplayType`;

ALTER TABLE `quest_sort` CHANGE `SortOrder` `UiOrderIndex` tinyint(4) NOT NULL DEFAULT 0 AFTER `SortName`;

ALTER TABLE `quest_xp`
  CHANGE `Exp1` `Difficulty1` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Exp2` `Difficulty2` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty1`,
  CHANGE `Exp3` `Difficulty3` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty2`,
  CHANGE `Exp4` `Difficulty4` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty3`,
  CHANGE `Exp5` `Difficulty5` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty4`,
  CHANGE `Exp6` `Difficulty6` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty5`,
  CHANGE `Exp7` `Difficulty7` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty6`,
  CHANGE `Exp8` `Difficulty8` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty7`,
  CHANGE `Exp9` `Difficulty9` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty8`,
  CHANGE `Exp10` `Difficulty10` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Difficulty9`;

ALTER TABLE `rand_prop_points`
  CHANGE `EpicPropertiesPoints1` `Epic1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `EpicPropertiesPoints2` `Epic2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Epic1`,
  CHANGE `EpicPropertiesPoints3` `Epic3` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Epic2`,
  CHANGE `EpicPropertiesPoints4` `Epic4` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Epic3`,
  CHANGE `EpicPropertiesPoints5` `Epic5` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Epic4`,
  CHANGE `RarePropertiesPoints1` `Superior1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Epic5`,
  CHANGE `RarePropertiesPoints2` `Superior2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Superior1`,
  CHANGE `RarePropertiesPoints3` `Superior3` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Superior2`,
  CHANGE `RarePropertiesPoints4` `Superior4` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Superior3`,
  CHANGE `RarePropertiesPoints5` `Superior5` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Superior4`,
  CHANGE `UncommonPropertiesPoints1` `Good1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Superior5`,
  CHANGE `UncommonPropertiesPoints2` `Good2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Good1`,
  CHANGE `UncommonPropertiesPoints3` `Good3` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Good2`,
  CHANGE `UncommonPropertiesPoints4` `Good4` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Good3`,
  CHANGE `UncommonPropertiesPoints5` `Good5` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Good4`;

ALTER TABLE `reward_pack`
  MODIFY `ArtifactXPDifficulty` tinyint(4) NOT NULL DEFAULT 0 AFTER `ArtifactXPMultiplier`,
  CHANGE `ArtifactCategoryID` `ArtifactXPCategoryID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ArtifactXPDifficulty`,
  CHANGE `TitleID` `CharTitleID` int(11) NOT NULL DEFAULT 0 AFTER `ArtifactXPCategoryID`,
  CHANGE `Unused` `TreasurePickerID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `CharTitleID`;

ALTER TABLE `reward_pack_x_item`
  MODIFY `ItemID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Amount` `ItemQuantity` int(11) NOT NULL DEFAULT 0 AFTER `ItemID`,
  MODIFY `RewardPackID` int(11) NOT NULL DEFAULT 0 AFTER `ItemQuantity`;

ALTER TABLE `ruleset_item_upgrade` MODIFY `ItemID` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `sandbox_scaling`
  MODIFY `MinLevel` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `MaxLevel` int(11) NOT NULL DEFAULT 0 AFTER `MinLevel`,
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `MaxLevel`;

ALTER TABLE `scaling_stat_distribution`
  CHANGE `ItemLevelCurveID` `PlayerLevelToItemLevelCurveID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `MinLevel` int(11) NOT NULL DEFAULT 0 AFTER `PlayerLevelToItemLevelCurveID`,
  MODIFY `MaxLevel` int(11) NOT NULL DEFAULT 0 AFTER `MinLevel`;

ALTER TABLE `scenario` ADD `AreaTableID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Name`;
ALTER TABLE `scenario` DROP `Data`;

ALTER TABLE `scenario_step`
  CHANGE `Name` `Title` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Description`,
  CHANGE `PreviousStepID` `Supersedes` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ScenarioID`,
  CHANGE `QuestRewardID` `RewardQuestID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Supersedes`,
  CHANGE `Step` `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RewardQuestID`,
  CHANGE `CriteriaTreeID` `Criteriatreeid` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `BonusRequiredStepID` `RelatedStep` int(11) NOT NULL DEFAULT 0 AFTER `Criteriatreeid`;

ALTER TABLE `scenario_step_locale` CHANGE `Name_lang` `Title_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `Description_lang`;

ALTER TABLE `scene_script`
  CHANGE `PrevScriptId` `FirstSceneScriptID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `NextScriptId` `NextSceneScriptID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `FirstSceneScriptID`;

ALTER TABLE `skill_line`
  MODIFY `CategoryID` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `CanLink` tinyint(4) NOT NULL DEFAULT 0 AFTER `CategoryID`,
  CHANGE `IconFileDataID` `SpellIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `CanLink`;

ALTER TABLE `skill_line_ability`
  MODIFY `RaceMask` bigint(20) NOT NULL DEFAULT 0 FIRST,
  CHANGE `SpellID` `Spell` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `SupercedesSpell` int(11) NOT NULL DEFAULT 0 AFTER `Spell`,
  MODIFY `SkillLine` smallint(6) NOT NULL DEFAULT 0 AFTER `SupercedesSpell`,
  MODIFY `TrivialSkillLineRankHigh` smallint(6) NOT NULL DEFAULT 0 AFTER `SkillLine`,
  MODIFY `TrivialSkillLineRankLow` smallint(6) NOT NULL DEFAULT 0 AFTER `TrivialSkillLineRankHigh`,
  MODIFY `UniqueBit` smallint(6) NOT NULL DEFAULT 0 AFTER `TrivialSkillLineRankLow`,
  MODIFY `TradeSkillCategoryID` smallint(6) NOT NULL DEFAULT 0 AFTER `UniqueBit`,
  MODIFY `NumSkillUps` tinyint(4) NOT NULL DEFAULT 0 AFTER `TradeSkillCategoryID`,
  MODIFY `MinSkillLineRank` smallint(6) NOT NULL DEFAULT 0 AFTER `ClassMask`,
  MODIFY `AcquireMethod` tinyint(4) NOT NULL DEFAULT 0 AFTER `MinSkillLineRank`,
  MODIFY `Flags` tinyint(4) NOT NULL DEFAULT 0 AFTER `AcquireMethod`;

ALTER TABLE `skill_race_class_info`
  MODIFY `SkillID` smallint(6) NOT NULL DEFAULT 0 AFTER `RaceMask`,
  MODIFY `SkillTierID` smallint(6) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `Availability` tinyint(4) NOT NULL DEFAULT 0 AFTER `SkillTierID`,
  MODIFY `MinLevel` tinyint(4) NOT NULL DEFAULT 0 AFTER `Availability`;

ALTER TABLE `sound_kit` CHANGE `Unk700` `MaxInstances` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `BusOverwriteID`;

ALTER TABLE `specialization_spells`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `Description`,
  MODIFY `OverridesSpellID` int(11) NOT NULL DEFAULT 0 AFTER `SpellID`,
  CHANGE `OrderIndex` `DisplayOrder` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `SpecID`;

ALTER TABLE `spell_aura_options`
  MODIFY `ProcCharges` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ProcTypeMask` int(11) NOT NULL DEFAULT 0 AFTER `ProcCharges`,
  MODIFY `ProcCategoryRecovery` int(11) NOT NULL DEFAULT 0 AFTER `ProcTypeMask`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ProcChance`;

ALTER TABLE `spell_aura_restrictions`
  MODIFY `CasterAuraSpell` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `TargetAuraSpell` int(11) NOT NULL DEFAULT 0 AFTER `CasterAuraSpell`,
  MODIFY `ExcludeCasterAuraSpell` int(11) NOT NULL DEFAULT 0 AFTER `TargetAuraSpell`,
  MODIFY `ExcludeTargetAuraSpell` int(11) NOT NULL DEFAULT 0 AFTER `ExcludeCasterAuraSpell`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ExcludeTargetAuraState`;

ALTER TABLE `spell_casting_requirements`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `MinReputation` tinyint(4) NOT NULL DEFAULT 0 AFTER `FacingCasterFlags`;

ALTER TABLE `spell_cast_times`
  CHANGE `CastTime` `Base` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `MinCastTime` `Minimum` int(11) NOT NULL DEFAULT 0 AFTER `Base`,
  CHANGE `CastTimePerLevel` `PerLevel` smallint(6) NOT NULL DEFAULT 0 AFTER `Minimum`;

ALTER TABLE `spell_categories`
  MODIFY `Category` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `StartRecoveryCategory` smallint(6) NOT NULL DEFAULT 0 AFTER `Category`,
  MODIFY `ChargeCategory` smallint(6) NOT NULL DEFAULT 0 AFTER `StartRecoveryCategory`,
  MODIFY `DefenseType` tinyint(4) NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `DispelType` tinyint(4) NOT NULL DEFAULT 0 AFTER `DefenseType`,
  MODIFY `Mechanic` tinyint(4) NOT NULL DEFAULT 0 AFTER `DispelType`,
  MODIFY `PreventionType` tinyint(4) NOT NULL DEFAULT 0 AFTER `Mechanic`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `PreventionType`;

ALTER TABLE `spell_category`
  MODIFY `Flags` tinyint(4) NOT NULL DEFAULT 0 AFTER `ChargeRecoveryTime`,
  MODIFY `MaxCharges` tinyint(4) NOT NULL DEFAULT 0 AFTER `UsesPerWeek`,
  CHANGE `ChargeCategoryType` `TypeMask` int(11) NOT NULL DEFAULT 0 AFTER `MaxCharges`;

ALTER TABLE `spell_class_options` MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_cooldowns`
  MODIFY `CategoryRecoveryTime` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `RecoveryTime` int(11) NOT NULL DEFAULT 0 AFTER `CategoryRecoveryTime`,
  MODIFY `StartRecoveryTime` int(11) NOT NULL DEFAULT 0 AFTER `RecoveryTime`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `DifficultyID`;

ALTER TABLE `spell_duration` MODIFY `DurationPerLevel` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `MaxDuration`;

ALTER TABLE `spell_effect`
  MODIFY `EffectIndex` int(11) NOT NULL DEFAULT 0 AFTER `EffectBasePoints`,
  MODIFY `EffectAura` int(11) NOT NULL DEFAULT 0 AFTER `EffectIndex`,
  MODIFY `DifficultyID` int(11) NOT NULL DEFAULT 0 AFTER `EffectAura`,
  MODIFY `EffectAuraPeriod` int(11) NOT NULL DEFAULT 0 AFTER `EffectAmplitude`,
  MODIFY `EffectChainTargets` int(11) NOT NULL DEFAULT 0 AFTER `EffectChainAmplitude`,
  MODIFY `EffectItemType` int(11) NOT NULL DEFAULT 0 AFTER `EffectDieSides`,
  MODIFY `EffectMechanic` int(11) NOT NULL DEFAULT 0 AFTER `EffectItemType`,
  MODIFY `EffectTriggerSpell` int(11) NOT NULL DEFAULT 0 AFTER `EffectRealPointsPerLevel`,
  MODIFY `EffectAttributes` int(11) NOT NULL DEFAULT 0 AFTER `EffectPosFacing`,
  CHANGE `PvPMultiplier` `PvpMultiplier` float NOT NULL DEFAULT 0 AFTER `BonusCoefficientFromAP`,
  CHANGE `GroupSizeCoefficient` `GroupSizeBasePointsCoefficient` float NOT NULL DEFAULT 0 AFTER `ResourceCoefficient`,
  CHANGE `EffectMiscValue` `EffectMiscValue1` int(11) NOT NULL DEFAULT 0 AFTER `EffectSpellClassMask4`,
  CHANGE `EffectMiscValueB` `EffectMiscValue2` int(11) NOT NULL DEFAULT 0 AFTER `EffectMiscValue1`,
  CHANGE `EffectRadiusIndex` `EffectRadiusIndex1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `EffectMiscValue2`,
  CHANGE `EffectRadiusMaxIndex` `EffectRadiusIndex2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `EffectRadiusIndex1`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ImplicitTarget2`;

ALTER TABLE `spell_equipped_items`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `EquippedItemInventoryTypeMask` `EquippedItemInvTypes` int(11) NOT NULL DEFAULT 0 AFTER `SpellID`,
  CHANGE `EquippedItemSubClassMask` `EquippedItemSubclass` int(11) NOT NULL DEFAULT 0 AFTER `EquippedItemInvTypes`;

ALTER TABLE `spell_interrupts`
  MODIFY `InterruptFlags` smallint(6) NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `AuraInterruptFlags1` int(11) NOT NULL DEFAULT 0 AFTER `InterruptFlags`,
  MODIFY `AuraInterruptFlags2` int(11) NOT NULL DEFAULT 0 AFTER `AuraInterruptFlags1`,
  MODIFY `ChannelInterruptFlags1` int(11) NOT NULL DEFAULT 0 AFTER `AuraInterruptFlags2`,
  MODIFY `ChannelInterruptFlags2` int(11) NOT NULL DEFAULT 0 AFTER `ChannelInterruptFlags1`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ChannelInterruptFlags2`;

ALTER TABLE `spell_item_enchantment`
  CHANGE `EffectSpellID1` `EffectArg1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Name`,
  CHANGE `EffectSpellID2` `EffectArg2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `EffectArg1`,
  CHANGE `EffectSpellID3` `EffectArg3` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `EffectArg2`,
  CHANGE `TextureFileDataID` `IconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `TransmogCost`,
  MODIFY `EffectPointsMin1` smallint(6) NOT NULL DEFAULT 0 AFTER `IconFileDataID`,
  MODIFY `EffectPointsMin2` smallint(6) NOT NULL DEFAULT 0 AFTER `EffectPointsMin1`,
  MODIFY `EffectPointsMin3` smallint(6) NOT NULL DEFAULT 0 AFTER `EffectPointsMin2`,
  CHANGE `PlayerConditionID` `TransmogPlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ScalingClassRestricted`;

ALTER TABLE `spell_item_enchantment_condition`
  CHANGE `LTOperand1` `LtOperand1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `LTOperand2` `LtOperand2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `LtOperand1`,
  CHANGE `LTOperand3` `LtOperand3` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `LtOperand2`,
  CHANGE `LTOperand4` `LtOperand4` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `LtOperand3`,
  CHANGE `LTOperand5` `LtOperand5` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `LtOperand4`,
  CHANGE `LTOperandType1` `LtOperandType1` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `LtOperand5`,
  CHANGE `LTOperandType2` `LtOperandType2` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `LtOperandType1`,
  CHANGE `LTOperandType3` `LtOperandType3` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `LtOperandType2`,
  CHANGE `LTOperandType4` `LtOperandType4` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `LtOperandType3`,
  CHANGE `LTOperandType5` `LtOperandType5` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `LtOperandType4`,
  CHANGE `RTOperandType1` `RtOperandType1` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `Operator5`,
  CHANGE `RTOperandType2` `RtOperandType2` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RtOperandType1`,
  CHANGE `RTOperandType3` `RtOperandType3` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RtOperandType2`,
  CHANGE `RTOperandType4` `RtOperandType4` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RtOperandType3`,
  CHANGE `RTOperandType5` `RtOperandType5` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RtOperandType4`,
  CHANGE `RTOperand1` `RtOperand1` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RtOperandType5`,
  CHANGE `RTOperand2` `RtOperand2` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RtOperand1`,
  CHANGE `RTOperand3` `RtOperand3` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RtOperand2`,
  CHANGE `RTOperand4` `RtOperand4` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RtOperand3`,
  CHANGE `RTOperand5` `RtOperand5` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `RtOperand4`;

ALTER TABLE `spell_learn_spell`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `LearnSpellID` int(11) NOT NULL DEFAULT 0 AFTER `SpellID`,
  MODIFY `OverridesSpellID` int(11) NOT NULL DEFAULT 0 AFTER `LearnSpellID`;

ALTER TABLE `spell_levels`
  MODIFY `BaseLevel` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `MaxLevel` smallint(6) NOT NULL DEFAULT 0 AFTER `BaseLevel`,
  MODIFY `SpellLevel` smallint(6) NOT NULL DEFAULT 0 AFTER `MaxLevel`,
  CHANGE `MaxUsableLevel` `MaxPassiveAuraLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `MaxPassiveAuraLevel`;

ALTER TABLE `spell_misc`
  CHANGE `IconFileDataID` `SpellIconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `SchoolMask`,
  MODIFY `ActiveIconFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `Speed`,
  CHANGE `MultistrikeSpeedMod` `LaunchDelay` float NOT NULL DEFAULT 0 AFTER `ActiveIconFileDataID`,
  CHANGE `Attributes` `Attributes1` int(11) NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  CHANGE `AttributesEx` `Attributes2` int(11) NOT NULL DEFAULT 0 AFTER `Attributes1`,
  CHANGE `AttributesExB` `Attributes3` int(11) NOT NULL DEFAULT 0 AFTER `Attributes2`,
  CHANGE `AttributesExC` `Attributes4` int(11) NOT NULL DEFAULT 0 AFTER `Attributes3`,
  CHANGE `AttributesExD` `Attributes5` int(11) NOT NULL DEFAULT 0 AFTER `Attributes4`,
  CHANGE `AttributesExE` `Attributes6` int(11) NOT NULL DEFAULT 0 AFTER `Attributes5`,
  CHANGE `AttributesExF` `Attributes7` int(11) NOT NULL DEFAULT 0 AFTER `Attributes6`,
  CHANGE `AttributesExG` `Attributes8` int(11) NOT NULL DEFAULT 0 AFTER `Attributes7`,
  CHANGE `AttributesExH` `Attributes9` int(11) NOT NULL DEFAULT 0 AFTER `Attributes8`,
  CHANGE `AttributesExI` `Attributes10` int(11) NOT NULL DEFAULT 0 AFTER `Attributes9`,
  CHANGE `AttributesExJ` `Attributes11` int(11) NOT NULL DEFAULT 0 AFTER `Attributes10`,
  CHANGE `AttributesExK` `Attributes12` int(11) NOT NULL DEFAULT 0 AFTER `Attributes11`,
  CHANGE `AttributesExL` `Attributes13` int(11) NOT NULL DEFAULT 0 AFTER `Attributes12`,
  CHANGE `AttributesExM` `Attributes14` int(11) NOT NULL DEFAULT 0 AFTER `Attributes13`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `Attributes14`;

ALTER TABLE `spell_power`
  CHANGE `ManaCostPercentage` `PowerCostPct` float NOT NULL DEFAULT 0 AFTER `ManaCost`,
  CHANGE `ManaCostPercentagePerSecond` `PowerPctPerSecond` float NOT NULL DEFAULT 0 AFTER `PowerCostPct`,
  CHANGE `RequiredAura` `RequiredAuraSpellID` int(11) NOT NULL DEFAULT 0 AFTER `PowerPctPerSecond`,
  CHANGE `HealthCostPercentage` `PowerCostMaxPct` float NOT NULL DEFAULT 0 AFTER `RequiredAuraSpellID`,
  CHANGE `PowerIndex` `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `PowerCostMaxPct`,
  MODIFY `PowerType` tinyint(4) NOT NULL DEFAULT 0 AFTER `OrderIndex`,
  CHANGE `ManaCostPerSecond` `ManaPerSecond` int(11) NOT NULL DEFAULT 0 AFTER `ManaCostPerLevel`,
  CHANGE `ManaCostAdditional` `OptionalCost` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ManaPerSecond`,
  CHANGE `UnitPowerBarID` `AltPowerBarID` int(11) NOT NULL DEFAULT 0 AFTER `PowerDisplayID`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `AltPowerBarID`;

ALTER TABLE `spell_power_difficulty` CHANGE `PowerIndex` `OrderIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `DifficultyID`;

ALTER TABLE `spell_procs_per_minute_mod` MODIFY `Param` smallint(6) NOT NULL DEFAULT 0 AFTER `Coeff`;

ALTER TABLE `spell_range`
  CHANGE `MinRangeHostile` `RangeMin1` float NOT NULL DEFAULT 0 AFTER `DisplayNameShort`,
  CHANGE `MinRangeFriend` `RangeMin2` float NOT NULL DEFAULT 0 AFTER `RangeMin1`,
  CHANGE `MaxRangeHostile` `RangeMax1` float NOT NULL DEFAULT 0 AFTER `RangeMin2`,
  CHANGE `MaxRangeFriend` `RangeMax2` float NOT NULL DEFAULT 0 AFTER `RangeMax1`;

ALTER TABLE `spell_reagents`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ReagentCount1` smallint(6) NOT NULL DEFAULT 0 AFTER `Reagent8`,
  MODIFY `ReagentCount2` smallint(6) NOT NULL DEFAULT 0 AFTER `ReagentCount1`,
  MODIFY `ReagentCount3` smallint(6) NOT NULL DEFAULT 0 AFTER `ReagentCount2`,
  MODIFY `ReagentCount4` smallint(6) NOT NULL DEFAULT 0 AFTER `ReagentCount3`,
  MODIFY `ReagentCount5` smallint(6) NOT NULL DEFAULT 0 AFTER `ReagentCount4`,
  MODIFY `ReagentCount6` smallint(6) NOT NULL DEFAULT 0 AFTER `ReagentCount5`,
  MODIFY `ReagentCount7` smallint(6) NOT NULL DEFAULT 0 AFTER `ReagentCount6`,
  MODIFY `ReagentCount8` smallint(6) NOT NULL DEFAULT 0 AFTER `ReagentCount7`;

ALTER TABLE `spell_scaling`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ScalesFromItemLevel` smallint(6) NOT NULL DEFAULT 0 AFTER `SpellID`,
  CHANGE `ScalingClass` `Class` int(11) NOT NULL DEFAULT 0 AFTER `ScalesFromItemLevel`;

ALTER TABLE `spell_shapeshift`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ShapeshiftExclude1` int(11) NOT NULL DEFAULT 0 AFTER `SpellID`,
  MODIFY `ShapeshiftExclude2` int(11) NOT NULL DEFAULT 0 AFTER `ShapeshiftExclude1`,
  MODIFY `ShapeshiftMask1` int(11) NOT NULL DEFAULT 0 AFTER `ShapeshiftExclude2`,
  MODIFY `ShapeshiftMask2` int(11) NOT NULL DEFAULT 0 AFTER `ShapeshiftMask1`,
  MODIFY `StanceBarOrder` tinyint(4) NOT NULL DEFAULT 0 AFTER `ShapeshiftMask2`;

ALTER TABLE `spell_shapeshift_form`
  CHANGE `WeaponDamageVariance` `DamageVariance` float NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `DamageVariance`,
  MODIFY `CombatRoundTime` smallint(6) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `BonusActionBar` tinyint(4) NOT NULL DEFAULT 0 AFTER `CreatureType`,
  CHANGE `AttackIconFileDataID` `AttackIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `BonusActionBar`;

ALTER TABLE `spell_target_restrictions`
  CHANGE `ConeAngle` `ConeDegrees` float NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Targets` int(11) NOT NULL DEFAULT 0 AFTER `Width`,
  MODIFY `TargetCreatureType` smallint(6) NOT NULL DEFAULT 0 AFTER `Targets`,
  CHANGE `MaxAffectedTargets` `MaxTargets` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `MaxTargetLevel`;

ALTER TABLE `spell_totems`
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Totem1` int(11) NOT NULL DEFAULT 0 AFTER `SpellID`,
  MODIFY `Totem2` int(11) NOT NULL DEFAULT 0 AFTER `Totem1`;

ALTER TABLE `spell_x_spell_visual`
  CHANGE `Chance` `Probability` float NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `PlayerConditionID` `ViewerPlayerConditionID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `CasterUnitConditionID`,
  CHANGE `UnitConditionID` `ViewerUnitConditionID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ViewerPlayerConditionID`,
  CHANGE `IconFileDataID` `SpellIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `ViewerUnitConditionID`,
  CHANGE `ActiveIconFileDataID` `ActiveIconFileID` int(11) NOT NULL DEFAULT 0 AFTER `SpellIconFileID`,
  MODIFY `SpellID` int(11) NOT NULL DEFAULT 0 AFTER `Priority`;

ALTER TABLE `summon_properties`
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Category` `Control` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `Faction` int(11) NOT NULL DEFAULT 0 AFTER `Control`,
  CHANGE `Type` `Title` int(11) NOT NULL DEFAULT 0 AFTER `Faction`;

ALTER TABLE `taxi_nodes`
  MODIFY `MountCreatureID1` int(11) NOT NULL DEFAULT 0 AFTER `PosZ`,
  MODIFY `MountCreatureID2` int(11) NOT NULL DEFAULT 0 AFTER `MountCreatureID1`,
  CHANGE `Unk730` `Facing` float NOT NULL DEFAULT 0 AFTER `MapOffsetY`,
  CHANGE `MapID` `ContinentID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `FlightMapOffsetY`,
  CHANGE `LearnableIndex` `CharacterBitNumber` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ConditionID`,
  CHANGE `UiTextureKitPrefixID` `UiTextureKitID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `SpecialAtlasIconPlayerConditionID` `SpecialIconConditionID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `UiTextureKitID`;

ALTER TABLE `taxi_path`
  CHANGE `From` `FromTaxiNode` smallint(5) UNSIGNED NOT NULL DEFAULT 0 FIRST,
  CHANGE `To` `ToTaxiNode` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `FromTaxiNode`;

ALTER TABLE `taxi_path_node` CHANGE `MapID` `ContinentID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `PathID`;

ALTER TABLE `totem_category`
  CHANGE `CategoryMask` `TotemCategoryMask` int(11) NOT NULL DEFAULT 0 AFTER `Name`,
  CHANGE `CategoryType` `TotemCategoryType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `TotemCategoryMask`;

ALTER TABLE `toy`
  CHANGE `Description` `SourceText` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL FIRST,
  MODIFY `ItemID` int(11) NOT NULL DEFAULT 0 AFTER `SourceText`,
  CHANGE `CategoryFilter` `SourceTypeEnum` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `toy_locale` CHANGE `Description_lang` `SourceText_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `locale`;

ALTER TABLE `transmog_holiday` CHANGE `HolidayID` `RequiredTransmogHoliday` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `transmog_set`
  CHANGE `BaseSetID` `ParentTransmogSetID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `Name`,
  CHANGE `UIOrder` `UiOrder` smallint(6) NOT NULL DEFAULT 0 AFTER `ParentTransmogSetID`,
  CHANGE `QuestID` `TrackingQuestID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `transmog_set_group` CHANGE `Label` `Name` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL FIRST;

ALTER TABLE `transmog_set_group_locale` CHANGE `Label_lang` `Name_lang` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `locale`;

ALTER TABLE `transport_animation` MODIFY `TransportID` int(11) NOT NULL DEFAULT 0 AFTER `SequenceID`;

ALTER TABLE `transport_rotation`
  CHANGE `X` `Rot1` float NOT NULL DEFAULT 0 AFTER `TimeIndex`,
  CHANGE `Y` `Rot2` float NOT NULL DEFAULT 0 AFTER `Rot1`,
  CHANGE `Z` `Rot3` float NOT NULL DEFAULT 0 AFTER `Rot2`,
  CHANGE `W` `Rot4` float NOT NULL DEFAULT 0 AFTER `Rot3`,
  CHANGE `TransportID` `GameObjectsID` int(11) NOT NULL DEFAULT 0 AFTER `Rot4`;

ALTER TABLE `unit_power_bar`
  MODIFY `FileDataID1` int(11) NOT NULL DEFAULT 0 AFTER `RegenerationCombat`,
  MODIFY `FileDataID2` int(11) NOT NULL DEFAULT 0 AFTER `FileDataID1`,
  MODIFY `FileDataID3` int(11) NOT NULL DEFAULT 0 AFTER `FileDataID2`,
  MODIFY `FileDataID4` int(11) NOT NULL DEFAULT 0 AFTER `FileDataID3`,
  MODIFY `FileDataID5` int(11) NOT NULL DEFAULT 0 AFTER `FileDataID4`,
  MODIFY `FileDataID6` int(11) NOT NULL DEFAULT 0 AFTER `FileDataID5`,
  MODIFY `Color1` int(11) NOT NULL DEFAULT 0 AFTER `FileDataID6`,
  MODIFY `Color2` int(11) NOT NULL DEFAULT 0 AFTER `Color1`,
  MODIFY `Color3` int(11) NOT NULL DEFAULT 0 AFTER `Color2`,
  MODIFY `Color4` int(11) NOT NULL DEFAULT 0 AFTER `Color3`,
  MODIFY `Color5` int(11) NOT NULL DEFAULT 0 AFTER `Color4`,
  MODIFY `Color6` int(11) NOT NULL DEFAULT 0 AFTER `Color5`;

ALTER TABLE `vehicle`
  MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `UILocomotionType` `UiLocomotionType` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FlagsB`;

ALTER TABLE `vehicle_seat`
  CHANGE `Flags1` `Flags` int(11) NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `Flags2` `FlagsB` int(11) NOT NULL DEFAULT 0 AFTER `Flags`,
  CHANGE `Flags3` `FlagsC` int(11) NOT NULL DEFAULT 0 AFTER `FlagsB`,
  CHANGE `UISkinFileDataID` `UiSkinFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `CameraSeatZoomMax`,
  MODIFY `EnterAnimKitID` smallint(6) NOT NULL DEFAULT 0 AFTER `VehicleRideAnimLoop`,
  MODIFY `RideAnimKitID` smallint(6) NOT NULL DEFAULT 0 AFTER `EnterAnimKitID`,
  MODIFY `ExitAnimKitID` smallint(6) NOT NULL DEFAULT 0 AFTER `RideAnimKitID`,
  MODIFY `VehicleEnterAnimKitID` smallint(6) NOT NULL DEFAULT 0 AFTER `ExitAnimKitID`,
  MODIFY `VehicleRideAnimKitID` smallint(6) NOT NULL DEFAULT 0 AFTER `VehicleEnterAnimKitID`,
  MODIFY `VehicleExitAnimKitID` smallint(6) NOT NULL DEFAULT 0 AFTER `VehicleRideAnimKitID`,
  MODIFY `CameraModeID` smallint(6) NOT NULL DEFAULT 0 AFTER `VehicleExitAnimKitID`,
  MODIFY `VehicleAbilityDisplay` tinyint(4) NOT NULL DEFAULT 0 AFTER `VehicleRideAnimLoopBone`;

ALTER TABLE `wmo_area_table`
  CHANGE `WMOGroupID` `WmoGroupID` int(11) NOT NULL DEFAULT 0 AFTER `AreaName`,
  CHANGE `UWIntroSound` `UwIntroSound` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `AreaTableID`,
  CHANGE `UWAmbience` `UwAmbience` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UwIntroSound`,
  CHANGE `NameSet` `NameSetID` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `UwAmbience`,
  CHANGE `UWZoneMusic` `UwZoneMusic` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  CHANGE `WMOID` `WmoID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UwZoneMusic`;

ALTER TABLE `world_effect` MODIFY `TargetAsset` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `world_map_area`
  MODIFY `MapID` smallint(6) NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `DefaultDungeonFloor` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `DisplayMapID`,
  CHANGE `BountyBoardLocation` `BountyDisplayLocation` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `BountySetID`,
  CHANGE `PlayerConditionID` `VisibilityPlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `world_map_overlay`
  MODIFY `OffsetX` int(11) NOT NULL DEFAULT 0 AFTER `MapAreaID`,
  MODIFY `OffsetY` int(11) NOT NULL DEFAULT 0 AFTER `OffsetX`,
  MODIFY `HitRectTop` int(11) NOT NULL DEFAULT 0 AFTER `OffsetY`,
  MODIFY `HitRectLeft` int(11) NOT NULL DEFAULT 0 AFTER `HitRectTop`,
  MODIFY `HitRectBottom` int(11) NOT NULL DEFAULT 0 AFTER `HitRectLeft`,
  MODIFY `HitRectRight` int(11) NOT NULL DEFAULT 0 AFTER `HitRectBottom`,
  MODIFY `PlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `HitRectRight`,
  MODIFY `Flags` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;
