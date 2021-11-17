DELETE FROM `achievement` WHERE `VerifiedBuild`>0 AND `ID` IN (14775, 14752, 14682, 14351);
INSERT INTO `achievement` (`Description`, `Title`, `Reward`, `ID`, `InstanceID`, `Faction`, `Supercedes`, `Category`, `MinimumCriteria`, `Points`, `Flags`, `UiOrder`, `IconFileID`, `RewardItemID`, `CriteriaTree`, `SharesCriteria`, `CovenantID`, `VerifiedBuild`) VALUES
('Earn Exalted status with Marasmius.', 'Mush Appreciated', 'Title Reward: Fun Guy / Fun Gal', 14775, -1, -1, 0, 15441, 0, 5, 0, 93, 464342, 0, 88298, 0, 0, 40944),
('Complete the Abominable Stitching achievements listed below.', 'Things To Do When You\'re Dead', 'Title Reward: Abominable & Reward: Armored Chosen Tauralus Mount', 14752, -1, -1, 0, 15441, 0, 15, 0, 72, 3752259, 181820, 88178, 0, 0, 40944),
('Complete the Ember Court achievements listed below.', 'The Party Herald', 'Title Reward: The Party Herald', 14682, -1, -1, 0, 15441, 0, 5, 131072, 92, 3257751, 0, 87741, 0, 0, 40944),
('Defeat 39 bosses in the Path of Ascension.', 'The Path Towards Ascension 39', 'Unlock more challenges in the Path of Ascension.', 14351, -1, -1, 14349, 15441, 0, 0, 1048576, 46, 3257748, 0, 86360, 0, 0, 40944);


DELETE FROM `area_table` WHERE `VerifiedBuild`>0 AND `ID`=13316;
INSERT INTO `area_table` (`ID`, `ZoneName`, `AreaName`, `ContinentID`, `ParentAreaID`, `AreaBit`, `SoundProviderPref`, `SoundProviderPrefUnderwater`, `AmbienceID`, `UwAmbience`, `ZoneMusic`, `UwZoneMusic`, `IntroSound`, `UwIntroSound`, `FactionGroupMask`, `AmbientMultiplier`, `MountFlags`, `PvpCombatWorldStateID`, `WildBattlePetLevelMin`, `WildBattlePetLevelMax`, `WindSettingsID`, `ContentTuningID`, `Flags1`, `Flags2`, `LiquidTypeID1`, `LiquidTypeID2`, `LiquidTypeID3`, `LiquidTypeID4`, `VerifiedBuild`) VALUES
(13316, 'HouseofTaamCovenantFinaleScenario', 'House of Rituals', 2362, 13313, 11938, 0, 0, 2368, 0, 2446, 0, 0, 0, 0, 0.150000005960464477, 13, -1, 0, 0, 0, 0, 1073741888, 0, 0, 0, 0, 0, 40944);


DELETE FROM `battle_pet_species` WHERE `VerifiedBuild`>0 AND `ID`=3188;
INSERT INTO `battle_pet_species` (`Description`, `SourceText`, `ID`, `CreatureID`, `SummonSpellID`, `IconFileDataID`, `PetTypeEnum`, `Flags`, `SourceTypeEnum`, `CardUIModelSceneID`, `LoadoutUIModelSceneID`, `CovenantID`, `VerifiedBuild`) VALUES
('', '', 3188, 182140, 360567, 134176, 7, 16466, -1, 6, 7, 0, 40944);


DELETE FROM `broadcast_text` WHERE `VerifiedBuild`>0 AND `ID` IN (215513, 215512, 215511);
INSERT INTO `broadcast_text` (`Text`, `Text1`, `ID`, `LanguageID`, `ConditionID`, `EmotesID`, `Flags`, `ChatBubbleDurationMs`, `SoundKitID1`, `SoundKitID2`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `VerifiedBuild`) VALUES
('', 'It would be unwise to venture into the Maw unprepared. Return to me when you are ready.', 215513, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
('It would be unwise to venture into the Maw unprepared. Return to me when you are ready.', '', 215512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
('', 'We\'re so close. Fight by my side and we will get through this together.', 215511, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944);


DELETE FROM `char_titles` WHERE `VerifiedBuild`>0 AND `ID`=693;
INSERT INTO `char_titles` (`ID`, `Name`, `Name1`, `MaskID`, `Flags`, `VerifiedBuild`) VALUES
(693, '%s the Ascended', '%s the Ascended', 439, 0, 40944);


UPDATE `char_titles` SET `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=683;
DELETE FROM `chr_customization_option` WHERE `VerifiedBuild`>0 AND `ID` IN (1523, 689);
INSERT INTO `chr_customization_option` (`Name`, `ID`, `SecondaryID`, `Flags`, `ChrModelID`, `SortIndex`, `ChrCustomizationCategoryID`, `OptionType`, `BarberShopCostModifier`, `ChrCustomizationID`, `ChrCustomizationReqID`, `UiOrderIndex`, `AddedInPatch`, `VerifiedBuild`) VALUES
('Tail', 1523, 670, 8, 60, 16, 1, 0, 2, 1, 0, 31, 90105, 40944),
('Tail', 689, 463, 8, 22, 20, 1, 0, 2, 1, 0, 20, 90001, 40944);


DELETE FROM `creature_model_data` WHERE `VerifiedBuild`>0 AND `ID`=13134;
INSERT INTO `creature_model_data` (`ID`, `GeoBox1`, `GeoBox2`, `GeoBox3`, `GeoBox4`, `GeoBox5`, `GeoBox6`, `Flags`, `FileDataID`, `BloodID`, `FootprintTextureID`, `FootprintTextureLength`, `FootprintTextureWidth`, `FootprintParticleScale`, `FoleyMaterialID`, `FootstepCameraEffectID`, `DeathThudCameraEffectID`, `SoundID`, `SizeClass`, `CollisionWidth`, `CollisionHeight`, `WorldEffectScale`, `CreatureGeosetDataID`, `HoverHeight`, `AttachedEffectScale`, `ModelScale`, `MissileCollisionRadius`, `MissileCollisionPush`, `MissileCollisionRaise`, `MountHeight`, `OverrideLootEffectScale`, `OverrideNameScale`, `OverrideSelectionRadius`, `TamedPetBaseScale`, `Unknown820_1`, `Unknown820_2`, `Unknown820_31`, `Unknown820_32`, `VerifiedBuild`) VALUES
(13134, -1.43289768695831298, -1.153053879737854, -0.03059528395533561, 1.742188453674316406, 1.163056492805480957, 3.186100959777832031, 12288, 4069485, 1, 6, 14, 10, 1, 0, 0, 0, 7475, 1, 0.611111104488372802, 2.031277894973754882, 1, 0, 0, 1.5, 1, 0, 0, 0, 2.185385942459106445, 0, 0, 0, 1, 0, 1, 1, 1, 40944);


DELETE FROM `criteria` WHERE `VerifiedBuild`>0 AND `ID`=49421;
INSERT INTO `criteria` (`ID`, `Type`, `Asset`, `ModifierTreeId`, `StartEvent`, `StartAsset`, `StartTimer`, `FailEvent`, `FailAsset`, `Flags`, `EligibilityWorldStateID`, `EligibilityWorldStateValue`, `VerifiedBuild`) VALUES
(49421, 12, 1822, 0, 0, 0, 0, 0, 0, 32, 0, 0, 40944);


DELETE FROM `criteria_tree` WHERE `VerifiedBuild`>0 AND `ID` IN (94390, 94389, 94388, 93811, 93810, 94331, 94330);
INSERT INTO `criteria_tree` (`ID`, `Description`, `Parent`, `Amount`, `Operator`, `CriteriaID`, `OrderIndex`, `Flags`, `VerifiedBuild`) VALUES
(94390, '', 93810, 1, 0, 52691, 3, 0, 40944),
(94389, '', 93810, 1, 0, 52690, 2, 0, 40944),
(94388, '', 93810, 1, 0, 52689, 1, 0, 40944),
(93811, '', 93810, 1, 0, 52688, 0, 0, 40944),
(93810, 'Renown Level 80', 0, 1, 8, 0, 0, 0, 40944),
(94331, '', 94330, 1, 0, 52688, 0, 0, 40944),
(94330, 'Renown Level 80 - Kyrian', 0, 0, 4, 0, 0, 0, 40944);


DELETE FROM `item` WHERE `VerifiedBuild`>0 AND `ID` IN (176922, 176921, 176832, 187935, 188152, 151806, 151804, 151792, 151790, 34685, 34683, 34087, 34085, 33969, 33968, 33967, 33966, 33868, 33864, 33863, 33862, 23324, 21525, 21524, 19028, 6835, 6833, 181321, 188220, 187900, 187899, 187898, 187897, 187896, 187895, 187875, 187869, 150746, 150745, 150744, 150743, 116401);
INSERT INTO `item` (`ID`, `ClassID`, `SubclassID`, `Material`, `InventoryType`, `SheatheType`, `SoundOverrideSubclassID`, `IconFileDataID`, `ItemGroupSoundsID`, `ContentTuningID`, `ModifiedCraftingReagentItemID`, `VerifiedBuild`) VALUES
(176922, 0, 8, 0, 0, 0, -1, 514019, 23, 0, 0, 40944),
(176921, 0, 8, 0, 0, 0, -1, 959793, 23, 0, 0, 40944),
(176832, 0, 8, 0, 0, 0, -1, 960671, 23, 0, 0, 40944),
(187935, 9, 11, 0, 0, 0, -1, 134939, 20, 0, 0, 40944),
(188152, 15, 4, 0, 0, 0, -1, 607513, 24, 0, 0, 40944),
(151806, 4, 5, 7, 20, 0, -1, 132645, 7, 0, 0, 40944),
(151804, 4, 5, 7, 7, 0, -1, 134581, 7, 0, 0, 40944),
(151792, 4, 5, 7, 20, 0, -1, 132640, 7, 0, 0, 40944),
(151790, 4, 5, 7, 20, 0, -1, 132641, 7, 0, 0, 40944),
(34685, 4, 5, 7, 20, 0, -1, 132713, 7, 0, 0, 40944),
(34683, 4, 5, 7, 8, 0, -1, 132577, 7, 0, 0, 40944),
(34087, 4, 0, 7, 20, 0, -1, 132640, 7, 0, 0, 40944),
(34085, 4, 0, 7, 20, 0, -1, 132641, 7, 0, 0, 40944),
(33969, 4, 5, 7, 1, 0, -1, 133100, 7, 0, 0, 40944),
(33968, 4, 5, 7, 1, 0, -1, 133102, 7, 0, 0, 40944),
(33967, 4, 5, 7, 1, 0, -1, 133098, 7, 0, 0, 40944),
(33966, 4, 5, 7, 8, 0, -1, 132575, 7, 0, 0, 40944),
(33868, 4, 5, 7, 8, 0, -1, 132574, 7, 0, 0, 40944),
(33864, 4, 5, 7, 1, 0, -1, 133099, 7, 0, 0, 40944),
(33863, 4, 5, 7, 20, 0, -1, 132711, 7, 0, 0, 40944),
(33862, 4, 5, 7, 20, 0, -1, 132710, 7, 0, 0, 40944),
(23324, 4, 5, 4, 3, 0, -1, 135054, 7, 0, 0, 40944),
(21525, 4, 5, 7, 1, 0, -1, 133170, 7, 0, 0, 40944),
(21524, 4, 5, 7, 1, 0, -1, 133169, 7, 0, 0, 40944),
(19028, 4, 0, 7, 20, 0, -1, 132645, 7, 0, 0, 40944),
(6835, 4, 0, 7, 7, 0, -1, 134581, 7, 0, 0, 40944),
(6833, 4, 5, 7, 4, 0, -1, 135012, 7, 0, 0, 40944),
(181321, 2, 19, 1, 26, 3, -1, 0, 21, 0, 0, 40944),
(188220, 15, 4, 5, 0, 0, -1, 4037125, 8, 0, 0, 40944),
(187900, 15, 0, 0, 0, 0, -1, 1064187, 20, 0, 0, 40944),
(187899, 15, 0, 0, 0, 0, -1, 237386, 20, 0, 0, 40944),
(187898, 15, 0, 0, 0, 0, -1, 237387, 20, 0, 0, 40944),
(187897, 15, 0, 0, 0, 0, -1, 237388, 20, 0, 0, 40944),
(187896, 15, 0, 0, 0, 0, -1, 237382, 20, 0, 0, 40944),
(187895, 15, 0, 0, 0, 0, -1, 237384, 20, 0, 0, 40944),
(187875, 15, 0, 0, 0, 0, -1, 237385, 20, 0, 0, 40944),
(187869, 15, 0, 0, 0, 0, -1, 237383, 20, 0, 0, 40944),
(150746, 15, 0, 0, 0, 0, -1, 237388, 20, 0, 0, 40944),
(150745, 15, 0, 0, 0, 0, -1, 237388, 20, 0, 0, 40944),
(150744, 15, 0, 0, 0, 0, -1, 237388, 20, 0, 0, 40944),
(150743, 15, 0, 0, 0, 0, -1, 237388, 20, 0, 0, 40944),
(116401, 4, 5, 4, 1, 0, -1, 133167, 7, 0, 0, 40944);


UPDATE `item` SET `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID` IN (185950, 185947, 185946);
DELETE FROM `item_appearance` WHERE `VerifiedBuild`>0 AND `ID` IN (34460, 24312, 11769, 11768);
INSERT INTO `item_appearance` (`ID`, `DisplayType`, `ItemDisplayInfoID`, `DefaultIconFileDataID`, `UiOrder`, `PlayerConditionID`, `VerifiedBuild`) VALUES
(34460, 0, 655515, 357813, 3446000, 0, 40944),
(24312, 0, 655516, 357813, 2431200, 0, 40944),
(11769, 0, 655518, 135142, 1176900, 0, 40944),
(11768, 0, 655517, 133149, 1176800, 0, 40944);


UPDATE `item_appearance` SET `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID` IN (43167, 42756, 42671, 42533);
DELETE FROM `item_search_name` WHERE `VerifiedBuild`>0 AND `ID` IN (151806, 151804, 151792, 151790, 34685, 34683, 34087, 34085, 33969, 33968, 33967, 33966, 33868, 33864, 33863, 33862, 23324, 21525, 21524, 19028, 6835, 6833, 181321, 116401);
INSERT INTO `item_search_name` (`ID`, `AllowableRace`, `Display`, `OverallQualityID`, `ExpansionID`, `MinFactionID`, `MinReputation`, `AllowableClass`, `RequiredLevel`, `RequiredSkill`, `RequiredSkillRank`, `RequiredAbility`, `ItemLevel`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `VerifiedBuild`) VALUES
(151806, -1, 'Elegant Dress', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 32768, 16801792, 0, 262144, 40944),
(151804, -1, 'Black Tuxedo Pants', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 32768, 16801792, 0, 262144, 40944),
(151792, -1, 'Green Winter Clothes', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 8192, 0, 262144, 40944),
(151790, -1, 'Red Winter Clothes', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 8192, 0, 262144, 40944),
(34685, -1, 'Vestment of Summer', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 37056, 16801792, 0, 262144, 40944),
(34683, -1, 'Sandals of Summer', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 37056, 16801792, 0, 262144, 40944),
(34087, -1, 'Green Winter Clothes', 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 16785408, 0, 262144, 40944),
(34085, -1, 'Red Winter Clothes', 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 16785408, 0, 262144, 40944),
(33969, -1, 'Purple Brewfest Hat', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 36864, 16801792, 0, 262144, 40944),
(33968, -1, 'Blue Brewfest Hat', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 36864, 16801792, 0, 262144, 40944),
(33967, -1, 'Green Brewfest Hat', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 36864, 16801792, 0, 262144, 40944),
(33966, -1, 'Brewfest Slippers', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 36864, 16801792, 0, 262144, 40944),
(33868, -1, 'Brewfest Boots', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 36864, 16801792, 0, 262144, 40944),
(33864, -1, 'Brown Brewfest Hat', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 36864, 16801792, 0, 262144, 40944),
(33863, -1, 'Brewfest Dress', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 36864, 16801792, 0, 262144, 40944),
(33862, -1, 'Brewfest Regalia', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 36864, 16801792, 0, 262144, 40944),
(23324, -1, 'Mantle of the Fire Festival', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 36864, 16801792, 0, 262144, 40944),
(21525, -1, 'Green Winter Hat', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 32768, 16785408, 0, 262144, 40944),
(21524, -1, 'Red Winter Hat', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 32768, 16785408, 0, 262144, 40944),
(19028, -1, 'Elegant Dress', 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 16801792, 0, 262144, 40944),
(6835, -1, 'Black Tuxedo Pants', 1, 0, 0, 0, -1, 0, 0, 0, 0, 14, 0, 16801792, 0, 262144, 40944),
(6833, -1, 'White Tuxedo Shirt', 2, 0, 0, 0, -1, 0, 0, 0, 0, 1, 32768, 8192, 0, 262144, 40944),
(181321, -1, 'Gem-Crowned Wand', 2, 8, 0, 0, -1, 60, 0, 0, 0, 1, 4096, 8704, 0, 65536, 40944),
(116401, -1, 'Fine Pilgrim\'s Hat', 3, 0, 0, 0, -1, 0, 0, 0, 0, 1, 36864, 24576, 0, 262144, 40944);


DELETE FROM `item_sparse` WHERE `VerifiedBuild`>0 AND `ID` IN (176922, 176921, 176832, 187935, 188152, 151806, 151804, 151792, 151790, 34685, 34683, 34087, 34085, 33969, 33968, 33967, 33966, 33868, 33864, 33863, 33862, 23324, 21525, 21524, 19028, 6835, 6833, 181321, 188220, 187900, 187899, 187898, 187897, 187896, 187895, 187875, 187869, 150746, 150745, 150744, 150743, 116401);
INSERT INTO `item_sparse` (`ID`, `AllowableRace`, `Description`, `Display3`, `Display2`, `Display1`, `Display`, `ExpansionID`, `DmgVariance`, `LimitCategory`, `DurationInInventory`, `QualityModifier`, `BagFamily`, `ItemRange`, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`, `StatPercentEditor1`, `StatPercentEditor2`, `StatPercentEditor3`, `StatPercentEditor4`, `StatPercentEditor5`, `StatPercentEditor6`, `StatPercentEditor7`, `StatPercentEditor8`, `StatPercentEditor9`, `StatPercentEditor10`, `Stackable`, `MaxCount`, `RequiredAbility`, `SellPrice`, `BuyPrice`, `VendorStackCount`, `PriceVariance`, `PriceRandomValue`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `FactionRelated`, `ModifiedCraftingReagentItemID`, `ContentTuningID`, `PlayerLevelToItemLevelCurveID`, `ItemNameDescriptionID`, `RequiredTransmogHoliday`, `RequiredHoliday`, `GemProperties`, `SocketMatchEnchantmentId`, `TotemCategoryID`, `InstanceBound`, `ZoneBound1`, `ZoneBound2`, `ItemSet`, `LockID`, `StartQuestID`, `PageID`, `ItemDelay`, `MinFactionID`, `RequiredSkillRank`, `RequiredSkill`, `ItemLevel`, `AllowableClass`, `ArtifactID`, `SpellWeight`, `SpellWeightCategory`, `SocketType1`, `SocketType2`, `SocketType3`, `SheatheType`, `Material`, `PageMaterialID`, `LanguageID`, `Bonding`, `DamageDamageType`, `StatModifierBonusStat1`, `StatModifierBonusStat2`, `StatModifierBonusStat3`, `StatModifierBonusStat4`, `StatModifierBonusStat5`, `StatModifierBonusStat6`, `StatModifierBonusStat7`, `StatModifierBonusStat8`, `StatModifierBonusStat9`, `StatModifierBonusStat10`, `ContainerSlots`, `MinReputation`, `RequiredPVPMedal`, `RequiredPVPRank`, `RequiredLevel`, `InventoryType`, `OverallQualityID`, `VerifiedBuild`) VALUES
(176922, -1, 'This magical bloom increases the yield of crafting materials offered by reborn spirits and catalysts grown from catalyst seeds by 100%.', '', '', '', 'Wild Nightbloom', 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 1, 1, 1, 1, 1.01139998435974121, 66624, 8192, 0, 0, 0, 0, 0, 0, 13556, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 3, 40944),
(176921, -1, 'These enchanted leaves reduce the Wildseed of Regrowth process by 1 day.', '', '', '', 'Temporal Leaves', 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 1, 1, 1, 1, 1.007799983024597167, 66624, 8192, 0, 0, 0, 0, 0, 0, 13556, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 2, 40944),
(176832, -1, 'This special root increases the quality of rewards offered by a spirit upon rebirth.', '', '', '', 'Wildseed Root Grain', 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 1, 1, 1, 1, 1.022300004959106445, 66624, 8192, 0, 0, 0, 0, 0, 0, 13556, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 4, 40944),
(187935, -1, 'Teaches you how to craft a Mark of the Midnight Runestag.', '', '', '', 'Technique: Mark of the Midnight Runestag', 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 250, 90000, 1, 1, 0.960900008678436279, 33624128, 24576, 0, 16384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 2756, 50, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 10, 0, 1, 40944),
(188152, -1, 'The shard\'s magic is searing to the touch.', '', '', '', 'Gateway Control Shard', 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1500000, 1, 1, 1.02799999713897705, 0, 12288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 3, 40944),
(151806, -1, '', '', '', '', 'Elegant Dress', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0.963299989700317382, 32768, 16801792, 0, 262144, 0, 0, 0, 0, 0, 181, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 20, 2, 40944),
(151804, -1, '', '', '', '', 'Black Tuxedo Pants', 0, 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0.955900013446807861, 32768, 16801792, 0, 262144, 0, 0, 0, 0, 0, 181, 0, 0, 0, 0, 0, 0, 0, 812, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 7, 2, 40944),
(151792, -1, '', '', '', '', 'Green Winter Clothes', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 7, 37, 1, 1, 1.011899948120117187, 0, 8192, 0, 262144, 0, 0, 0, 0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 761, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 20, 2, 40944),
(151790, -1, '', '', '', '', 'Red Winter Clothes', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 7, 36, 1, 1, 0.978100001811981201, 0, 8192, 0, 262144, 0, 0, 0, 0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 761, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 20, 2, 40944),
(34685, -1, '', '', '', '', 'Vestment of Summer', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0.969799995422363281, 37056, 16801792, 0, 262144, 0, 0, 0, 0, 0, 341, 0, 0, 0, 0, 0, 0, 0, 785, 0, 0, 0, 500, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 20, 2, 40944),
(34683, -1, '', '', '', '', 'Sandals of Summer', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1.036000013351440429, 37056, 16801792, 0, 262144, 0, 0, 0, 0, 0, 341, 0, 0, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 8, 2, 40944),
(34087, -1, '', '', '', '', 'Green Winter Clothes', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 7, 38, 1, 1, 0.969200015068054199, 0, 16785408, 0, 262144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 20, 1, 40944),
(34085, -1, '', '', '', '', 'Red Winter Clothes', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 7, 37, 1, 1, 0.961899995803833007, 0, 16785408, 0, 262144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 20, 1, 40944),
(33969, -1, '', '', '', '', 'Purple Brewfest Hat', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0.950900018215179443, 36864, 16801792, 0, 262144, 0, 0, 0, 0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 762, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 2, 40944),
(33968, -1, '', '', '', '', 'Blue Brewfest Hat', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1.047299981117248535, 36864, 16801792, 0, 262144, 0, 0, 0, 0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 762, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 2, 40944),
(33967, -1, '', '', '', '', 'Green Brewfest Hat', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1.043599963188171386, 36864, 16801792, 0, 262144, 0, 0, 0, 0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 762, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 2, 40944),
(33966, -1, '', '', '', '', 'Brewfest Slippers', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1.039899945259094238, 36864, 16801792, 0, 262144, 0, 0, 0, 0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 762, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 8, 2, 40944),
(33868, -1, '', '', '', '', 'Brewfest Boots', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1.021399974822998046, 36864, 16801792, 0, 262144, 0, 0, 0, 0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 762, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 8, 2, 40944),
(33864, -1, '', '', '', '', 'Brown Brewfest Hat', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0.980300009250640869, 36864, 16801792, 0, 262144, 0, 0, 0, 0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 762, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 2, 40944),
(33863, -1, '', '', '', '', 'Brewfest Dress', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0.97659999132156372, 36864, 16801792, 0, 262144, 0, 0, 0, 0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 762, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 20, 2, 40944),
(33862, -1, '', '', '', '', 'Brewfest Regalia', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0.972899973392486572, 36864, 16801792, 0, 262144, 0, 0, 0, 0, 0, 372, 0, 0, 0, 0, 0, 0, 0, 762, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 20, 2, 40944),
(23324, -1, '', '', '', '', 'Mantle of the Fire Festival', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0.960699975490570068, 36864, 16801792, 0, 262144, 0, 0, 0, 0, 0, 341, 0, 0, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 3, 2, 40944),
(21525, -1, '', '', '', '', 'Green Winter Hat', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 7, 37, 1, 1, 0.993799984455108642, 32768, 16785408, 0, 262144, 0, 0, 0, 0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 761, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 2, 40944),
(21524, -1, '', '', '', '', 'Red Winter Hat', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 7, 37, 1, 1, 0.990100026130676269, 32768, 16785408, 0, 262144, 0, 0, 0, 0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 761, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 2, 40944),
(19028, -1, '', '', '', '', 'Elegant Dress', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1.000499963760375976, 0, 16801792, 0, 262144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 20, 1, 40944),
(6835, -1, '', '', '', '', 'Black Tuxedo Pants', 0, 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0.987999975681304931, 0, 16801792, 0, 262144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 7, 1, 40944),
(6833, -1, '', '', '', '', 'White Tuxedo Shirt', 0, 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0.98059999942779541, 32768, 8192, 0, 262144, 0, 0, 0, 0, 0, 181, 0, 0, 0, 0, 0, 0, 0, 812, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 4, 2, 40944),
(181321, -1, '', '', '', '', 'Gem-Crowned Wand', 8, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 23, 118, 1, 1, 1.008499979972839355, 4096, 8704, 0, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0, 1, 5, 5, -1, -1, -1, -1, 5, -1, -1, -1, -1, 0, 0, 0, 0, 60, 26, 2, 40944),
(188220, -1, 'Has the words \"I Survived the Tower\" on the bottom.', '', '', '', 'Torghast Ash Globe', 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 4, 1, 1, 0.98339998722076416, 64, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 40944),
(187900, -1, 'A goblin and gnome duo describe their many discoveries across the two islands.', '', '', '', 'Scouting Map: The Wonders of Kul Tiras and Zandalar', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0.979600012302398681, 134221888, 139264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(187899, -1, 'An adventurous alchemist\'s description of the disparate biomes and incredible flora of Outland.', '', '', '', 'Scouting Map: The Many Curiosities of Outland', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0.975899994373321533, 134221888, 139264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(187898, -1, 'An Argent Crusader\'s detailed report of all military operations made in pursuit of the Lich King.', '', '', '', 'Scouting Map: True Cost of the Northrend Campaign', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0.972199976444244384, 134221888, 139264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(187897, -1, 'A rare joint-faction report, compiling the countless consequences of Deathwing\'s shattering of Azeroth.', '', '', '', 'Scouting Map: Cataclysm\'s Consequences', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0.968599975109100341, 134221888, 139264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(187896, -1, 'A lighthearted tale of Li Li\'s latest adventures across Pandaria, with food recommendations from her uncle Chen.', '', '', '', 'Scouting Map: A Stormstout\'s Guide to Pandaria', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0.964900016784667968, 134221888, 139264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(187895, -1, 'A concise list of the few safe havens across Draenor, and the local customs you\'d be wise to observe in each.', '', '', '', 'Scouting Map: The Dangers of Draenor', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0.96119999885559082, 134221888, 139264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(187875, -1, 'Large collection of reports and correspondence of disparate military units combating the Legion.', '', '', '', 'Scouting Map: United Fronts of the Broken Isles', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0.961300015449523925, 134221888, 139264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(187869, -1, 'A detailed tale of one maw walker\'s journey through four realms of the Shadowlands.', '', '', '', 'Scouting Map: Into the Shadowlands', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1.012899994850158691, 134221888, 139264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(150746, -1, 'A modest proposal to effectuate just-in-time supply furnishment for outposts of the Eastern Kingdoms.', '', '', '', 'Scouting Map: Modern Provisioning of the Eastern Kingdoms', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0.952499985694885253, 134221888, 139266, 0, 0, 150745, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(150745, -1, 'A comprehensive strategy to swiftly cripple Eastern Kingdoms forces of the Alliance in the event of the Fourth War.', '', '', '', 'Scouting Map: The Eastern Kingdoms Campaign', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1.02240002155303955, 134221888, 139265, 0, 0, 150746, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(150744, -1, 'Mending the scars of the land left by the wicked, corrupt, and unnatural.', '', '', '', 'Scouting Map: Walking Kalimdor with the Earthmother', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1.018800020217895507, 134221888, 139265, 0, 0, 150743, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(150743, -1, 'An exhaustive compilation of fanged, clawed, venomous, and Horde-aligned beasts.', '', '', '', 'Scouting Map: Surviving Kalimdor', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1.015100002288818359, 134221888, 139266, 0, 0, 150744, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 0, 7, 40944),
(116401, -1, '', '', '', '', 'Fine Pilgrim\'s Hat', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1.04030001163482666, 36864, 24576, 0, 262144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 3, 40944);

UPDATE `item_sparse` SET `Flags3`=2048, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=185950;
UPDATE `item_sparse` SET `Flags3`=2048, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=185947;
UPDATE `item_sparse` SET `MaxCount`=4, `VendorStackCount`=1, `Flags3`=2048, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=185946;

DELETE FROM `item_spec_override` WHERE `VerifiedBuild`>0 AND `ID` IN (133055, 133054, 133053, 133052);
INSERT INTO `item_spec_override` (`ID`, `SpecID`, `ItemID`, `VerifiedBuild`) VALUES
(133055, 105, 183486, 40944),
(133054, 104, 183486, 40944),
(133053, 103, 183486, 40944),
(133052, 102, 183486, 40944);


DELETE FROM `lfg_dungeons` WHERE `VerifiedBuild`>0 AND `ID`=1445;
INSERT INTO `lfg_dungeons` (`ID`, `Name`, `Description`, `TypeID`, `Subtype`, `Faction`, `IconTextureFileID`, `RewardsBgTextureFileID`, `PopupBgTextureFileID`, `ExpansionLevel`, `MapID`, `DifficultyID`, `MinGear`, `GroupID`, `OrderIndex`, `RequiredPlayerConditionId`, `RandomID`, `ScenarioID`, `FinalEncounterID`, `CountTank`, `CountHealer`, `CountDamage`, `MinCountTank`, `MinCountHealer`, `MinCountDamage`, `BonusReputationAmount`, `MentorItemLevel`, `MentorCharLevel`, `ContentTuningID`, `Flags1`, `Flags2`, `VerifiedBuild`) VALUES
(1445, 'Feltotem\'s Fall', 'Stop Tugar Bloodtotem and his Fel Worms from bringing down the mountain.', 1, 3, -1, 136349, 615223, 615222, 0, 1702, 12, 0, 38, 10, 94517, 0, 1266, 0, 0, 0, 1, 0, 0, 1, 0, 50, 45, 617, 344228866, 0, 40944);


DELETE FROM `map` WHERE `VerifiedBuild`>0 AND `ID`=1756;
INSERT INTO `map` (`ID`, `Directory`, `MapName`, `MapDescription0`, `MapDescription1`, `PvpShortDescription`, `PvpLongDescription`, `CorpseX`, `CorpseY`, `MapType`, `InstanceType`, `ExpansionID`, `AreaTableID`, `LoadingScreenID`, `TimeOfDayOverride`, `ParentMapID`, `CosmeticParentMapID`, `TimeOffset`, `MinimapIconScale`, `CorpseMapID`, `MaxPlayers`, `WindSettingsID`, `ZmpFileDataID`, `WdtFileDataID`, `Flags1`, `Flags2`, `VerifiedBuild`) VALUES
(1756, 'ChromieScenario', 'The Deaths of Chromie', '', '', '', '', 0, 0, 1, 5, 6, 0, 428, -1, -1, -1, 0, 1, -1, 0, 0, 0, 1619285, 7773, 134479920, 40944);


DELETE FROM `modifier_tree` WHERE `VerifiedBuild`>0 AND `ID` IN (178500, 178499, 178498, 178497, 178496, 178495, 178494, 178493, 178492, 178491, 178490, 178489, 178488, 178487, 176083, 176082, 174511, 174279, 174278, 178369, 153266, 178172, 178171, 178170, 178169, 178168, 178167, 178166, 178165, 178164, 178163, 178162, 178161, 178122, 166497, 162879, 178072, 177911, 177905, 177895, 177890, 177888, 177760, 177759, 177754, 177753, 177748, 177747, 177742, 177741, 178079, 178078, 178077, 178076, 178075, 178074, 178073, 178070, 178069, 175034, 175027, 175021, 175015, 175008, 175002, 174997);
INSERT INTO `modifier_tree` (`ID`, `Parent`, `Operator`, `Amount`, `Type`, `Asset`, `SecondaryAsset`, `TertiaryAsset`, `VerifiedBuild`) VALUES
(178500, 178498, 2, 1, 110, 64983, 0, 0, 40944),
(178499, 178498, 2, 1, 86, 15226, 0, 0, 40944),
(178498, 178488, 8, 1, 0, 0, 0, 0, 40944),
(178497, 178491, 2, 1, 110, 61874, 0, 0, 40944),
(178496, 178491, 2, 1, 110, 60545, 0, 0, 40944),
(178495, 178491, 2, 1, 111, 61874, 0, 0, 40944),
(178494, 178491, 2, 1, 111, 60545, 0, 0, 40944),
(178493, 178491, 2, 1, 84, 60545, 0, 0, 40944),
(178492, 178491, 2, 1, 84, 61874, 0, 0, 40944),
(178491, 178488, 8, 1, 0, 0, 0, 0, 40944),
(178490, 178488, 3, 1, 110, 59770, 0, 0, 40944),
(178489, 178488, 2, 1, 71, 49, 0, 0, 40944),
(178488, 0, 4, 1, 0, 0, 0, 0, 40944),
(178487, 174275, 2, 1, 69, 50, 0, 0, 40944),
(176083, 176080, 2, 1, 17, 13344, 0, 0, 40944),
(176082, 176080, 2, 1, 110, 59755, 0, 0, 40944),
(174511, 174275, 8, 1, 0, 0, 0, 0, 40944),
(174279, 174275, 8, 1, 0, 0, 0, 0, 40944),
(174278, 174275, 3, 1, 110, 59770, 0, 0, 40944),
(178369, 173118, 2, 1, 2, 86994, 0, 0, 40944),
(153266, 153264, 2, 1, 86, 14752, 0, 0, 40944),
(178172, 178170, 2, 1, 288, 2, 0, 0, 40944),
(178171, 178170, 2, 1, 119, 1830, 79, 0, 40944),
(178170, 0, 8, 1, 0, 0, 0, 0, 40944),
(178169, 178167, 2, 1, 288, 4, 0, 0, 40944),
(178168, 178167, 2, 1, 119, 1832, 79, 0, 40944),
(178167, 0, 8, 1, 0, 0, 0, 0, 40944),
(178166, 178164, 2, 1, 288, 3, 0, 0, 40944),
(178165, 178164, 2, 1, 119, 1831, 79, 0, 40944),
(178164, 0, 8, 1, 0, 0, 0, 0, 40944),
(178163, 178161, 2, 1, 288, 1, 0, 0, 40944),
(178162, 178161, 2, 1, 119, 1829, 79, 0, 40944),
(178161, 0, 8, 1, 0, 0, 0, 0, 40944),
(178122, 162876, 8, 1, 0, 0, 0, 0, 40944),
(166497, 178122, 3, 1, 112, 419721, 0, 0, 40944),
(162879, 178122, 3, 1, 112, 419702, 0, 0, 40944),
(178072, 177888, 2, 1, 119, 1829, 79, 0, 40944),
(177911, 177906, 2, 1, 119, 1832, 79, 0, 40944),
(177905, 177900, 2, 1, 119, 1831, 79, 0, 40944),
(177895, 177894, 2, 1, 119, 1830, 79, 0, 40944),
(177890, 177888, 4, 1, 0, 0, 0, 0, 40944),
(177888, 0, 8, 1, 0, 0, 0, 0, 40944),
(177760, 177759, 2, 1, 119, 1830, 79, 0, 40944),
(177759, 0, 4, 1, 0, 0, 0, 0, 40944),
(177754, 177753, 2, 1, 119, 1831, 79, 0, 40944),
(177753, 0, 4, 1, 0, 0, 0, 0, 40944),
(177748, 177747, 2, 1, 119, 1829, 79, 0, 40944),
(177747, 0, 4, 1, 0, 0, 0, 0, 40944),
(177742, 177741, 2, 1, 119, 1832, 79, 0, 40944),
(177741, 0, 4, 1, 0, 0, 0, 0, 40944),
(178079, 175002, 2, 1, 69, 45, 0, 0, 40944),
(178078, 175008, 2, 1, 69, 45, 0, 0, 40944),
(178077, 175015, 2, 1, 69, 45, 0, 0, 40944),
(178076, 175021, 2, 1, 69, 45, 0, 0, 40944),
(178075, 175027, 2, 1, 69, 45, 0, 0, 40944),
(178074, 175034, 2, 1, 69, 45, 0, 0, 40944),
(178073, 174997, 2, 1, 69, 45, 0, 0, 40944),
(178070, 178069, 2, 1, 69, 45, 0, 0, 40944),
(178069, 0, 4, 1, 0, 0, 0, 0, 40944),
(175034, 0, 8, 2, 0, 0, 0, 0, 40944),
(175027, 0, 8, 2, 0, 0, 0, 0, 40944),
(175021, 0, 8, 2, 0, 0, 0, 0, 40944),
(175015, 0, 8, 2, 0, 0, 0, 0, 40944),
(175008, 0, 8, 2, 0, 0, 0, 0, 40944),
(175002, 0, 8, 2, 0, 0, 0, 0, 40944),
(174997, 0, 8, 2, 0, 0, 0, 0, 40944);


DELETE FROM `player_condition` WHERE `VerifiedBuild`>0 AND `ID` IN (85644, 73006, 73005, 87365, 85912, 85910, 85909, 85692, 94517, 94516, 94515, 94514, 94513, 94512, 94511);
INSERT INTO `player_condition` (`ID`, `RaceMask`, `FailureDescription`, `ClassMask`, `SkillLogic`, `LanguageID`, `MinLanguage`, `MaxLanguage`, `MaxFactionID`, `MaxReputation`, `ReputationLogic`, `CurrentPvpFaction`, `PvpMedal`, `PrevQuestLogic`, `CurrQuestLogic`, `CurrentCompletedQuestLogic`, `SpellLogic`, `ItemLogic`, `ItemFlags`, `AuraSpellLogic`, `WorldStateExpressionID`, `WeatherID`, `PartyStatus`, `LifetimeMaxPVPRank`, `AchievementLogic`, `Gender`, `NativeGender`, `AreaLogic`, `LfgLogic`, `CurrencyLogic`, `QuestKillID`, `QuestKillLogic`, `MinExpansionLevel`, `MaxExpansionLevel`, `MinAvgItemLevel`, `MaxAvgItemLevel`, `MinAvgEquippedItemLevel`, `MaxAvgEquippedItemLevel`, `PhaseUseFlags`, `PhaseID`, `PhaseGroupID`, `Flags`, `ChrSpecializationIndex`, `ChrSpecializationRole`, `ModifierTreeID`, `PowerType`, `PowerTypeComp`, `PowerTypeValue`, `WeaponSubclassMask`, `MaxGuildLevel`, `MinGuildLevel`, `MaxExpansionTier`, `MinExpansionTier`, `MinPVPRank`, `MaxPVPRank`, `ContentTuningID`, `CovenantID`, `SkillID1`, `SkillID2`, `SkillID3`, `SkillID4`, `MinSkill1`, `MinSkill2`, `MinSkill3`, `MinSkill4`, `MaxSkill1`, `MaxSkill2`, `MaxSkill3`, `MaxSkill4`, `MinFactionID1`, `MinFactionID2`, `MinFactionID3`, `MinReputation1`, `MinReputation2`, `MinReputation3`, `PrevQuestID1`, `PrevQuestID2`, `PrevQuestID3`, `PrevQuestID4`, `CurrQuestID1`, `CurrQuestID2`, `CurrQuestID3`, `CurrQuestID4`, `CurrentCompletedQuestID1`, `CurrentCompletedQuestID2`, `CurrentCompletedQuestID3`, `CurrentCompletedQuestID4`, `SpellID1`, `SpellID2`, `SpellID3`, `SpellID4`, `ItemID1`, `ItemID2`, `ItemID3`, `ItemID4`, `ItemCount1`, `ItemCount2`, `ItemCount3`, `ItemCount4`, `Explored1`, `Explored2`, `Time1`, `Time2`, `AuraSpellID1`, `AuraSpellID2`, `AuraSpellID3`, `AuraSpellID4`, `AuraStacks1`, `AuraStacks2`, `AuraStacks3`, `AuraStacks4`, `Achievement1`, `Achievement2`, `Achievement3`, `Achievement4`, `AreaID1`, `AreaID2`, `AreaID3`, `AreaID4`, `LfgStatus1`, `LfgStatus2`, `LfgStatus3`, `LfgStatus4`, `LfgCompare1`, `LfgCompare2`, `LfgCompare3`, `LfgCompare4`, `LfgValue1`, `LfgValue2`, `LfgValue3`, `LfgValue4`, `CurrencyID1`, `CurrencyID2`, `CurrencyID3`, `CurrencyID4`, `CurrencyCount1`, `CurrencyCount2`, `CurrencyCount3`, `CurrencyCount4`, `QuestKillMonster1`, `QuestKillMonster2`, `QuestKillMonster3`, `QuestKillMonster4`, `QuestKillMonster5`, `QuestKillMonster6`, `MovementFlags1`, `MovementFlags2`, `VerifiedBuild`) VALUES
(85644, 0, 'Must reach level $pcMinLevel to continue.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 0, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 2060, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(73006, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 196609, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 1, -1, -1, 0, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 307479, 307926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(73005, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 1, -1, -1, 0, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 307479, 307926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(87365, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 35, -1, -1, 0, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14752, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(85912, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178164, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62397, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(85910, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178167, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(85909, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178170, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62398, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(85692, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178161, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62395, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(94517, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35872, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178069, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(94516, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35871, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178069, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(94515, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35870, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178069, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(94514, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35869, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178069, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(94513, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35868, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178069, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(94512, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35867, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178069, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944),
(94511, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35866, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 33, -1, -1, 178069, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40944);


DELETE FROM `quest_v2` WHERE `VerifiedBuild`>0 AND `ID` IN (60399, 60396, 60392, 60381, 62694, 62693, 62692, 62691, 65169, 65168, 65165, 65157, 65147, 61058, 61057, 60111, 60110, 59919, 59325, 58797, 64850);
INSERT INTO `quest_v2` (`ID`, `UniqueBitFlag`, `VerifiedBuild`) VALUES
(60399, 39740, 40944),
(60396, 39741, 40944),
(60392, 39742, 40944),
(60381, 39739, 40944),
(62694, 44338, 40944),
(62693, 44337, 40944),
(62692, 44339, 40944),
(62691, 44340, 40944),
(65169, 38764, 40944),
(65168, 44106, 40944),
(65165, 44100, 40944),
(65157, 44097, 40944),
(65147, 44088, 40944),
(61058, 40289, 40944),
(61057, 40288, 40944),
(60111, 39515, 40944),
(60110, 39514, 40944),
(59919, 39351, 40944),
(59325, 38764, 40944),
(58797, 38271, 40944),
(64850, 43827, 40944);


DELETE FROM `spell_aura_options` WHERE `VerifiedBuild`>0 AND `ID` IN (186908, 9518, 186896);
INSERT INTO `spell_aura_options` (`ID`, `DifficultyID`, `CumulativeAura`, `ProcCategoryRecovery`, `ProcChance`, `ProcCharges`, `SpellProcsPerMinuteID`, `ProcTypeMask1`, `ProcTypeMask2`, `SpellID`, `VerifiedBuild`) VALUES
(186908, 0, 2, 0, 101, 0, 0, 0, 0, 365080, 40944),
(9518, 0, 0, 0, 101, 0, 0, 0, 0, 117526, 40944),
(186896, 0, 1, 0, 101, 0, 0, 0, 0, 364944, 40944);


DELETE FROM `spell_casting_requirements` WHERE `VerifiedBuild`>0 AND `ID` IN (213674, 213673, 213672, 213671, 213670, 213669, 213668, 213667, 213666, 213665, 213664, 213663, 213642);
INSERT INTO `spell_casting_requirements` (`ID`, `SpellID`, `FacingCasterFlags`, `MinFactionID`, `MinReputation`, `RequiredAreasID`, `RequiredAuraVision`, `RequiresSpellFocus`, `VerifiedBuild`) VALUES
(213674, 247692, 0, 0, 0, 5303, 0, 0, 40944),
(213673, 247111, 0, 0, 0, 5303, 0, 0, 40944),
(213672, 247099, 0, 0, 0, 5303, 0, 0, 40944),
(213671, 247096, 0, 0, 0, 5303, 0, 0, 40944),
(213670, 247104, 0, 0, 0, 5303, 0, 0, 40944),
(213669, 247089, 0, 0, 0, 5303, 0, 0, 40944),
(213668, 247110, 0, 0, 0, 5303, 0, 0, 40944),
(213667, 247094, 0, 0, 0, 5303, 0, 0, 40944),
(213666, 247088, 0, 0, 0, 5303, 0, 0, 40944),
(213665, 247093, 0, 0, 0, 5303, 0, 0, 40944),
(213664, 247092, 0, 0, 0, 5303, 0, 0, 40944),
(213663, 247103, 0, 0, 0, 5303, 0, 0, 40944),
(213642, 307934, 0, 0, 0, 6668, 0, 0, 40944);


DELETE FROM `spell_categories` WHERE `VerifiedBuild`>0 AND `ID` IN (1791, 1741, 62, 54233);
INSERT INTO `spell_categories` (`ID`, `DifficultyID`, `Category`, `DefenseType`, `DispelType`, `Mechanic`, `PreventionType`, `StartRecoveryCategory`, `ChargeCategory`, `SpellID`, `VerifiedBuild`) VALUES
(1791, 0, 0, 1, 0, 0, 1, 0, 0, 12472, 40944),
(1741, 0, 0, 1, 0, 0, 1, 0, 0, 12042, 40944),
(62, 0, 0, 1, 0, 0, 1, 133, 0, 136, 40944),
(54233, 0, 0, 1, 1, 0, 0, 0, 0, 211464, 40944);


DELETE FROM `spell_category` WHERE `VerifiedBuild`>0 AND `ID`=1186;
INSERT INTO `spell_category` (`ID`, `Name`, `Flags`, `UsesPerWeek`, `MaxCharges`, `ChargeRecoveryTime`, `TypeMask`, `VerifiedBuild`) VALUES
(1186, 'Class - Paladin - Hand of Sacrifice', 16, 0, 1, 120000, 1, 40944);


DELETE FROM `spell_class_options` WHERE `VerifiedBuild`>0 AND `ID` IN (61714, 61709);
INSERT INTO `spell_class_options` (`ID`, `SpellID`, `ModalNextSpell`, `SpellClassSet`, `SpellClassMask1`, `SpellClassMask2`, `SpellClassMask3`, `SpellClassMask4`, `VerifiedBuild`) VALUES
(61714, 365080, 0, 53, 0, 0, 0, 0, 40944),
(61709, 364944, 0, 53, 0, 0, 0, 0, 40944);


DELETE FROM `spell_effect` WHERE `VerifiedBuild`>0 AND `ID` IN (793985, 882432, 882392, 369676, 905674, 845047, 906096, 897551, 897550, 839924, 905972, 875244, 869248, 867891, 834692, 834688, 823342, 786826, 786825, 786824, 786815, 786808, 786807, 786806, 905876, 905875, 905872, 891440, 891438, 882994, 882993, 874876, 818347, 905418, 905417, 815761, 331347, 281049, 60368, 39872, 288833, 815370, 905295, 892984, 343764, 479792, 10779);
INSERT INTO `spell_effect` (`ID`, `EffectAura`, `DifficultyID`, `EffectIndex`, `Effect`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `ScalingClass`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`, `SpellID`, `VerifiedBuild`) VALUES
(793985, 4, 0, 2, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 312202, 40944),
(882432, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 66.7790679931640625, 0, 0, 1, 0, -9, 0, 0, 0, 14, 0, 0, 0, 0, 22, 15, 351867, 40944),
(882392, 0, 0, 0, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 351850, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 351847, 40944),
(369676, 103, 0, 0, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, -90000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 243328, 40944),
(905674, 129, 0, 0, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 10, 0, 0, 0, 0, 13, 0, 0, 0, 0, 22, 30, 365080, 40944),
(845047, 0, 0, 0, 139, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 62844, 0, 0, 0, 0, 0, 0, 0, 1, 0, 343346, 40944),
(906096, 0, 0, 2, 64, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 328172, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 360421, 40944),
(897551, 0, 0, 1, 283, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 160, 0, 0, 0, 0, 0, 0, 0, 1, 0, 360421, 40944),
(897550, 0, 0, 0, 140, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 344122, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 360421, 40944),
(839924, 108, 0, 0, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 0, 0, 1, 100, 0, 0, 0, 0, 0, 0, 0, 0, 134217728, 1, 0, 340192, 40944),
(905972, 483, 0, 7, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 307926, 40944),
(875244, 23, 0, 6, 6, 0, 0, 1000, 0, 1, 0, 0, 0, 0, 0, 0, 301744, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92, 0, 307926, 40944),
(869248, 0, 0, 2, 167, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 307480, 40944),
(867891, 226, 0, 5, 6, 0, 0, 1000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 307926, 40944),
(834692, 0, 0, 4, 140, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 61286, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 307926, 40944),
(834688, 0, 0, 3, 167, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92, 0, 307926, 40944),
(823342, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 329902, 40944),
(786826, 296, 0, 1, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 6878, 0, 0, 0, 0, 0, 0, 0, 1, 0, 307934, 40944),
(786825, 428, 0, 0, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 307933, 0, 1, 0, 0, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 307934, 40944),
(786824, 0, 0, 0, 28, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 157891, 4717, 13, 0, 0, 0, 0, 0, 142, 0, 307933, 40944),
(786815, 0, 0, 1, 164, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 307481, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 307480, 40944),
(786808, 4, 0, 2, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 307926, 40944),
(786807, 293, 0, 1, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1493, 60, 0, 0, 0, 0, 0, 0, 25, 0, 307926, 40944),
(786806, 236, 0, 0, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 307926, 40944),
(905876, 3, 15, 0, 6, 0, 0, 1000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 3.799999952316284179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 349458, 40944),
(905875, 3, 16, 0, 6, 0, 0, 1000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 4.499358177185058593, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 349458, 40944),
(905872, 3, 16, 0, 6, 0, 0, 500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 351870, 40944),
(891440, 0, 15, 1, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 350777, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 87, 16, 352225, 40944),
(891438, 0, 15, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 347704, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 87, 16, 352225, 40944),
(882994, 0, 0, 1, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 350777, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 87, 16, 352225, 40944),
(882993, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 347704, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 87, 16, 352225, 40944),
(874876, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 347548, 40944),
(818347, 81, 0, 0, 6, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 40, 0, 127, 1, 0, 0, 0, 0, 0, 0, 21, 0, 327037, 40944),
(905418, 0, 0, 1, 142, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 364944, 0, 1, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 327004, 40944),
(905417, 129, 0, 0, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 5, 0, 0, 0, 0, 9, 0, 0, 0, 0, 22, 30, 364944, 40944),
(815761, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0.490999996662139892, 1.299999952316284179, 0, 0.050000000745058059, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 325464, 40944),
(331347, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0.331699997186660766, 1.299999952316284179, 0, 0.050000000745058059, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 222026, 40944),
(281049, 3, 0, 0, 6, 0, 2048, 3000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0.125, 1.299999952316284179, 0, 0, 0, 1, 0, 0, 127, 0, 0, 13, 0, 0, 0, 0, 63, 16, 191587, 40944),
(60368, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0.331699997186660766, 1.299999952316284179, 0, 0.050000000745058059, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 66196, 40944),
(39872, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0.50300002098083496, 1.299999952316284179, 0, 0.050000000745058059, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 47632, 40944),
(288833, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0.655200004577636718, 1, 0, 0.050000000745058059, 0, 1, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 87, 16, 196733, 40944),
(815370, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0.666666984558105468, 0, 0.050000000745058059, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 325217, 40944),
(905295, 0, 0, 1, 252, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 17, 357999, 40944),
(892984, 0, 0, 0, 90, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 177638, 0, 0, 0, 0, 0, 0, 0, 1, 0, 357999, 40944),
(343764, 0, 23, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0.099667772650718688, 0, 1, 36, 0, 0, 0, 0, 48, 0, 0, 0, 0, 22, 15, 211464, 40944),
(479792, 108, 0, 3, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0.800000011920928955, 0, 0, 0, 1, 25, 0, 22, 0, 0, 0, 1, 0, 0, 1024, 1, 0, 19574, 40944),
(10779, 108, 0, 0, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0.800000011920928955, 0, 0, 0, 1, 25, 0, 0, 0, 0, 0, 1, 0, 0, 1024, 1, 0, 19574, 40944);

UPDATE `spell_effect` SET `EffectBasePoints`=3.349999904632568359, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=895695;
UPDATE `spell_effect` SET `PvpMultiplier`=1.10000002384185791, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=479998;
UPDATE `spell_effect` SET `PvpMultiplier`=1.299999952316284179, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=269119;
UPDATE `spell_effect` SET `PvpMultiplier`=1.149999976158142089, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=10651;
UPDATE `spell_effect` SET `EffectBasePoints`=42.59933853149414062, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=895844;

DELETE FROM `spell_interrupts` WHERE `VerifiedBuild`>0 AND `ID` IN (171381, 171288, 171235, 61222);
INSERT INTO `spell_interrupts` (`ID`, `DifficultyID`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `SpellID`, `VerifiedBuild`) VALUES
(171381, 0, 9, 0, 0, 0, 0, 361952, 40944),
(171288, 0, 0, 524288, 0, 0, 0, 365080, 40944),
(171235, 0, 0, 524288, 0, 0, 0, 364944, 40944),
(61222, 0, 45, 0, 0, 0, 0, 211464, 40944);


DELETE FROM `spell_label` WHERE `VerifiedBuild`>0 AND `ID` IN (84469, 84468, 84467, 84466, 84465, 84464, 84463, 84462, 84461, 84460, 84459, 84458, 84457, 84456, 84455, 84454, 84453, 84452, 84451, 84450, 84449, 84448, 84443, 84442, 84441, 84346, 84345, 84344, 84323, 84322, 84321);
INSERT INTO `spell_label` (`ID`, `LabelID`, `SpellID`, `VerifiedBuild`) VALUES
(84469, 1379, 187613, 40944),
(84468, 1379, 256817, 40944),
(84467, 1379, 317860, 40944),
(84466, 1379, 318378, 40944),
(84465, 1379, 353511, 40944),
(84464, 1379, 187614, 40944),
(84463, 1379, 187612, 40944),
(84462, 1379, 187611, 40944),
(84461, 1379, 187615, 40944),
(84460, 1379, 146195, 40944),
(84459, 1379, 146199, 40944),
(84458, 1379, 146197, 40944),
(84457, 1379, 146193, 40944),
(84456, 1379, 101641, 40944),
(84455, 1379, 101056, 40944),
(84454, 1379, 71903, 40944),
(84453, 1379, 64415, 40944),
(84452, 1379, 41433, 40944),
(84451, 1379, 41434, 40944),
(84450, 1379, 21992, 40944),
(84449, 1379, 21142, 40944),
(84448, 1379, 21162, 40944),
(84443, 1379, 325335, 40944),
(84442, 1379, 325492, 40944),
(84441, 1379, 323436, 40944),
(84346, 292, 365080, 40944),
(84345, 16, 365080, 40944),
(84344, 22, 365080, 40944),
(84323, 292, 364944, 40944),
(84322, 16, 364944, 40944),
(84321, 22, 364944, 40944);


DELETE FROM `spell_levels` WHERE `VerifiedBuild`>0 AND `ID` IN (125560, 125558, 21773);
INSERT INTO `spell_levels` (`ID`, `DifficultyID`, `MaxLevel`, `MaxPassiveAuraLevel`, `BaseLevel`, `SpellLevel`, `SpellID`, `VerifiedBuild`) VALUES
(125560, 0, 0, 0, 1, 1, 365080, 40944),
(125558, 0, 0, 0, 1, 1, 364944, 40944),
(21773, 0, 0, 0, 0, 0, 119607, 40944);


DELETE FROM `spell_misc` WHERE `VerifiedBuild`>0 AND `ID` IN (476604, 220895, 220894, 220890, 220887, 220884, 220883, 386747, 470710, 469819, 466278, 443445, 443195, 442539, 442283, 441981, 440946, 439981, 436996, 434017, 433894, 433252, 433196, 428505, 404479, 466256, 466253, 399210, 398349, 387476, 361592, 347465, 338383, 244146, 240717, 239468, 206447, 176741, 158326, 129003, 103578, 90408, 82262, 59320, 49191, 49011, 40524, 39830, 32568, 18143, 18141, 14100, 11746, 8941, 8922, 2380, 479781, 87092, 404541, 382485, 382484, 474186, 392545, 221469, 157418, 137, 471340, 472345, 444258, 479643, 266, 165949, 91552, 91549, 172492, 199147, 185484);
INSERT INTO `spell_misc` (`ID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `Attributes15`, `DifficultyID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `Speed`, `LaunchDelay`, `MinDuration`, `SpellIconFileDataID`, `ActiveIconFileDataID`, `ContentTuningID`, `ShowFutureSpellPlayerConditionID`, `SpellVisualScript`, `ActiveSpellVisualScript`, `SpellID`, `VerifiedBuild`) VALUES
(476604, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 1, 1, 0, 0, 0, 136243, 0, 0, 0, 0, 0, 361952, 40944),
(220895, -1610612544, 301989888, 0, 1074790400, 3145728, 1024, 1024, 0, 0, 32768, 0, 0, 0, 33554432, 0, 0, 1, 0, 1, 1, 0, 0, 0, 136243, 0, 0, 0, 0, 0, 247104, 40944),
(220894, -1610612544, 301989888, 0, 1074790400, 3145728, 1024, 1024, 0, 0, 32768, 0, 0, 0, 33554432, 0, 0, 1, 0, 1, 1, 0, 0, 0, 136243, 0, 0, 0, 0, 0, 247103, 40944),
(220890, -1610612544, 301989888, 0, 1074790400, 3145728, 1024, 1024, 0, 0, 32768, 0, 0, 0, 33554432, 0, 0, 1, 0, 1, 1, 0, 0, 0, 136243, 0, 0, 0, 0, 0, 247099, 40944),
(220887, -1610612544, 301989888, 0, 1074790400, 3145728, 1024, 1024, 0, 0, 32768, 0, 0, 0, 33554432, 0, 0, 1, 0, 1, 1, 0, 0, 0, 136243, 0, 0, 0, 0, 0, 247096, 40944),
(220884, -1610612544, 301989888, 0, 1074790400, 3145728, 1024, 1024, 0, 0, 32768, 0, 0, 0, 33554432, 0, 0, 1, 0, 1, 1, 0, 0, 0, 136243, 0, 0, 0, 0, 0, 247093, 40944),
(220883, -1610612544, 301989888, 0, 1074790400, 3145728, 1024, 1024, 0, 0, 32768, 0, 0, 0, 33554432, 0, 0, 1, 0, 1, 1, 0, 0, 0, 136243, 0, 0, 0, 0, 0, 247092, 40944),
(386747, -2147221488, 0, 524288, 67108864, 64, 134226432, 0, 0, 12800, 0, 0, 0, 0, 129, 0, 0, 1, 305, 4, 64, 0, 0, 0, 3565442, 0, 0, 0, 0, 0, 312202, 40944),
(470710, 0, 0, 1, 0, 65536, 0, 2, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 5, 0, 5, 32, 0, 0, 0, 136187, 0, 0, 0, 0, 0, 356212, 40944),
(469819, 0, 536870980, 536870912, 65536, 0, 0, 536870912, 0, 0, 0, 8192, 4, 0, 0, 0, 0, 1, 39, 1, 32, 0, 0, 0, 3528304, 0, 0, 0, 0, 0, 355321, 40944),
(466278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 4, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 237488, 0, 0, 0, 0, 0, 351867, 40944),
(443445, 0, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 8192, 4, 0, 0, 0, 0, 1, 18, 5, 32, 0, 0, 0, 133250, 0, 0, 0, 0, 0, 345801, 40944),
(443195, 0, 4, 0, 8320, 0, 513, 0, 0, 4608, 16, 270336, 68, 0, 0, 0, 0, 1, 1, 137, 1, 0.5, 0, 0, 1379246, 0, 0, 0, 0, 0, 345548, 40944),
(442539, 0, 0, 0, 128, 0, 0, 4194304, 0, 0, 0, 8192, 4, 0, 1, 0, 0, 1, 32, 37, 4, 0, 0, 0, 2103819, 0, 0, 0, 0, 0, 344916, 40944),
(442283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 4, 0, 0, 0, 0, 1, 9, 1, 32, 0, 0, 0, 1357803, 0, 0, 0, 0, 0, 344662, 40944),
(441981, 0, 0, 0, 384, 0, 0, 0, 0, 4096, 0, 8192, 4, 0, 0, 0, 0, 1, 9, 5, 32, 0, 0, 0, 1392562, 0, 0, 0, 0, 0, 344384, 40944),
(440946, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 8192, 4, 0, 0, 0, 0, 1, 8, 5, 1, 0.5, 0.5, 0, 3536206, 0, 0, 0, 0, 0, 343385, 40944),
(439981, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 29, 5, 2, 0, 0, 0, 132842, 0, 0, 0, 0, 0, 342432, 40944),
(436996, 0, 0, 0, 0, 0, 8192, 0, 0, 4608, 0, 8192, 4, 0, 0, 0, 0, 1, 4, 37, 8, 0, 0, 0, 3528274, 0, 0, 0, 0, 0, 339517, 40944),
(434017, 0, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 8192, 4, 0, 0, 0, 0, 1, 29, 1, 8, 0, 0, 0, 3536178, 0, 0, 0, 0, 0, 336588, 40944),
(433894, -2147483648, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 8192, 4, 0, 0, 0, 0, 1, 29, 1, 2, 0, 0, 0, 1586383, 0, 0, 0, 0, 0, 336465, 40944),
(433252, 0, 0, 0, 128, 0, 512, 0, 0, 4608, 0, 8192, 4, 0, 0, 0, 0, 1, 63, 5, 32, 42, 0, 0, 651083, 0, 0, 0, 0, 0, 336182, 40944),
(433196, 536870928, 268468224, 0, 0, 0, 393224, 0, 0, 32, 0, 8192, 8, 0, 1, 0, 0, 1, 407, 1, 1, 0, 0, 0, 1322720, 0, 0, 0, 0, 0, 336126, 40944),
(428505, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 8, 1, 32, 0, 0, 0, 3159929, 0, 0, 0, 0, 0, 331523, 40944),
(404479, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 4, 0, 0, 0, 0, 1, 0, 1, 32, 0, 0, 0, 1526632, 0, 0, 0, 0, 0, 329840, 40944),
(466256, 612368384, 33554432, 0, 0, 128, 0, 0, 0, 0, 1048576, 0, 0, 0, 1024, 0, 0, 1, 21, 6, 1, 0, 0, 0, 3860391, 0, 0, 0, 0, 0, 351850, 40944),
(466253, 256, 0, 0, 0, 0, 0, 0, 0, 4096, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 1, 15, 0, 0.25, 3860391, 0, 0, 0, 0, 0, 351847, 40944),
(399210, 65536, 536870980, 524288, 1073741824, 0, 0, 0, 0, 12288, 0, 270336, 0, 0, 0, 0, 0, 1, 27, 7, 32, 0, 0, 0, 3586267, 0, 0, 0, 0, 0, 324631, 40944),
(398349, 65536, 68, 524288, 0, 0, 0, 0, 0, 8192, 0, 270336, 0, 0, 0, 0, 0, 1, 35, 1, 8, 0, 0, 0, 3636839, 0, 0, 0, 0, 0, 323764, 40944),
(387476, 65552, 131072, 0, 1073741824, 0, 0, 0, 0, 0, 0, 8396800, 0, 0, 1, 0, 0, 1, 8, 12, 1, 0, 0, 0, 3192686, 0, 0, 0, 0, 0, 312924, 40944),
(361592, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 4, 27, 140, 1, 0, 0, 0, 2447782, 0, 0, 0, 0, 0, 287712, 40944),
(347465, 16, 268436512, 147456, 0, 0, 0, 1024, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 8, 1, 1, 0, 0, 0, 2021574, 0, 0, 0, 0, 0, 274738, 40944),
(338383, 262400, 268435488, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1786406, 0, 0, 0, 0, 0, 265221, 40944),
(244146, 0, 268435456, 0, 0, 0, 0, 1024, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 64, 0, 0, 0, 1851463, 0, 0, 0, 0, 0, 260364, 40944),
(240717, 0, 0, 0, 0, 0, 0, 0, 0, 4096, 8388608, 8192, 0, 0, 0, 0, 0, 1, 32, 4, 1, 0, 0, 0, 1724004, 0, 0, 0, 0, 0, 256948, 40944),
(239468, 0, 268435456, 0, 1073741824, 0, 0, 0, 0, 0, 1024, 8192, 0, 0, 0, 0, 0, 1, 36, 140, 1, 0, 0, 0, 1723987, 0, 0, 0, 0, 0, 255654, 40944),
(206447, 0, 136, 0, 1073741824, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 64, 0, 0, 0, 136222, 0, 0, 0, 0, 0, 232633, 40944),
(176741, 0, 136, 0, 1073741824, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 64, 0, 0, 0, 136222, 0, 0, 0, 0, 0, 202719, 40944),
(158326, 327696, 98304, 536870912, 65536, 0, 8, 134217728, 0, 12288, 0, 8192, 0, 0, 68157441, 0, 0, 1, 31, 1, 1, 0, 0, 0, 132345, 0, 0, 0, 0, 0, 184364, 40944),
(129003, 0, 136, 0, 1073741824, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 64, 0, 0, 0, 136222, 0, 0, 0, 0, 0, 155145, 40944),
(103578, 0, 136, 0, 1073741824, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 64, 0, 0, 0, 136222, 0, 0, 0, 0, 0, 129597, 40944),
(90408, 327696, 1040, 0, 0, 0, 0, 0, 0, 4096, 0, 8192, 0, 0, 1, 0, 0, 1, 31, 1, 1, 0, 0, 0, 132336, 0, 0, 0, 0, 0, 118038, 40944),
(82262, 1116176, 262144, 0, 67108874, 8388608, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 35, 2, 1, 0, 0, 0, 572035, 0, 0, 0, 0, 0, 107079, 40944),
(59320, 0, 136, 0, 1073741824, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 64, 0, 0, 0, 136222, 0, 0, 0, 0, 0, 80483, 40944),
(49191, 0, 136, 0, 1073741824, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 64, 0, 0, 0, 136222, 0, 0, 0, 0, 0, 69179, 40944),
(49011, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 366937, 0, 0, 0, 0, 0, 68992, 40944),
(40524, 536870912, 163840, 0, 0, 0, 0, 0, 0, 4096, 0, 8192, 67108864, 0, 0, 0, 0, 1, 407, 1, 1, 0, 0, 0, 136129, 0, 0, 0, 0, 0, 59752, 40944),
(39830, 1310736, 132112, 2097156, 67108864, 524288, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 21, 1, 1, 0, 0, 0, 132089, 0, 0, 0, 0, 0, 58984, 40944),
(32568, 0, 136, 0, 1073741824, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 64, 0, 0, 0, 136222, 0, 0, 0, 0, 0, 50613, 40944),
(18143, 16, 1056, 147456, 0, 0, 0, 0, 0, 4096, 0, 8192, 0, 0, 0, 0, 0, 1, 8, 1, 1, 0, 0, 0, 135726, 0, 0, 0, 0, 0, 33702, 40944),
(18141, 65552, 1056, 147456, 0, 0, 0, 0, 0, 4096, 0, 8192, 0, 0, 0, 0, 0, 1, 8, 1, 1, 0, 0, 0, 135726, 0, 0, 0, 0, 0, 33697, 40944),
(14100, 0, 136, 0, 1073741824, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 64, 0, 0, 0, 136222, 0, 0, 0, 0, 0, 28730, 40944),
(11746, 0, 136, 0, 1073741824, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 64, 0, 0, 0, 136222, 0, 0, 0, 0, 0, 25046, 40944),
(8941, 262400, 268435488, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 136225, 0, 0, 0, 0, 0, 20594, 40944),
(8922, 16, 1056, 147456, 0, 0, 0, 0, 0, 4096, 0, 8192, 0, 0, 0, 0, 0, 1, 8, 1, 1, 0, 0, 0, 135726, 0, 0, 0, 0, 0, 20572, 40944),
(2380, 16, 163840, 0, 262144, 0, 0, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 0, 1, 407, 1, 1, 0, 0, 0, 136187, 0, 0, 0, 0, 0, 7744, 40944),
(479781, -1459355632, 132128, 268976385, 68354048, 3145857, 393224, 5124, 1073741824, 4096, 1048584, 4194305, 201326592, 0, 3, 0, 0, 1, 1, 6, 1, 0, 0, 0, 611420, 0, 0, 0, 0, 0, 365080, 40944),
(87092, 687874176, 1024, 0, 197120, 8388736, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7, 1, 0, 0, 0, 255348, 0, 0, 0, 0, 0, 113902, 40944),
(404541, 536871296, 1024, 272646148, 268632576, 8388736, 393224, 512, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 3, 1, 0, 0, 0, 136243, 0, 0, 0, 0, 0, 329902, 40944),
(382485, 687866112, 268438560, 273170436, 268632576, 8388608, 393224, 12804, 0, 0, 0, 1, 0, 0, 0, 0, 0, 16, 21, 12, 1, 0, 0, 0, 136225, 0, 0, 0, 0, 0, 307934, 40944),
(382484, 679477632, 1056, 273170437, 269681152, 8388736, 393224, 12800, 0, 0, 1048576, 1, 0, 0, 0, 0, 0, 1, 21, 6, 1, 0, 0, 0, 136243, 0, 0, 0, 0, 0, 307933, 40944),
(474186, 696254848, 1056, 273170437, 269681152, 8388736, 393224, 70144, 0, 32, 1048576, 0, 0, 0, 0, 0, 0, 1, 35, 6, 1, 0, 0, 0, 136243, 0, 0, 0, 0, 0, 359581, 40944),
(392545, 151322624, 0, 16, 1048576, 2097152, 0, 67112960, 0, 4096, 0, 0, 0, 32, 0, 0, 0, 1, 21, 1, 2, 0, 0, 0, 135933, 136116, 0, 0, 0, 0, 317920, 40944),
(221469, 64, 268435456, 0, 67108864, 2097152, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1, 0, 5, 2, 0, 0, 0, 135882, 0, 0, 0, 0, 0, 247675, 40944),
(157418, 151322880, 0, 16, 1048576, 2097152, 268435456, 4096, 0, 4096, 0, 0, 0, 32, 1, 0, 0, 1, 21, 1, 1, 0, 0, 0, 135889, 136116, 0, 0, 0, 0, 183435, 40944),
(137, 151322624, 0, 16, 1048576, 2097152, 0, 67112960, 0, 4096, 0, 0, 0, 32, 0, 0, 0, 1, 21, 1, 2, 0, 0, 0, 135893, 136116, 0, 0, 0, 0, 465, 40944),
(471340, -2139095040, 1024, 268435457, 1245184, 8388608, 512, 4096, 4, 0, 0, 0, 0, 1048576, 33554432, 0, 0, 1, 21, 6, 32, 0, 0, 0, 627687, 0, 0, 0, 0, 0, 356827, 40944),
(472345, 687865856, 2088, 805322752, 65536, 8321, 394248, 536870912, 536870912, 32, 1074792448, 4194304, 67108864, 1048576, 2, 0, 0, 1, 21, 1, 1, 0, 0, 0, 1519431, 0, 0, 0, 0, 0, 357816, 40944),
(444258, 262160, 0, 131072, 1024, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 1, 0, 0, 1, 0, 2, 1, 0, 0, 0, 606551, 0, 0, 0, 0, 0, 346602, 40944),
(479643, -1459355632, 132128, 268976385, 68354048, 3145857, 393224, 5124, 1073741824, 4096, 1048584, 4194305, 201326592, 0, 3, 0, 0, 1, 1, 6, 1, 0, 0, 0, 611420, 0, 0, 0, 0, 0, 364944, 40944),
(266, -2147418096, 132096, 4, 0, 0, 134217728, 0, 0, 0, 0, 131072, 0, 0, 1, 0, 0, 475, 27, 1, 8, 0, 0, 0, 132163, 0, 0, 83446, 0, 0, 982, 40944),
(165949, 0, 0, 131072, 1073741824, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 6, 8, 0, 0, 0, 988198, 0, 0, 0, 0, 0, 191894, 40944),
(91552, 151257088, 0, 131332, 1140851200, 32768, 8192, 33554432, 0, 16781824, 8, 0, 0, 0, 1048593, 0, 0, 1, 18, 13, 8, 0, 0, 0, 627487, 0, 0, 0, 0, 0, 119611, 40944),
(91549, 134283264, 1056, 269090820, 1140850688, 1572864, 0, 67108864, 1073741824, 4096, 0, 0, 0, 0, 1, 0, 0, 1, 0, 13, 8, 0, 0, 0, 627487, 0, 0, 0, 0, 0, 119607, 40944),
(172492, 218103808, 172, 16388, 0, 129, 917512, 0, 0, 32, 16, 0, 0, 0, 0, 0, 0, 1, 18, 6, 1, 0.5, 0, 0, 841383, 0, 0, 0, 0, 0, 198477, 40944),
(199147, 0, 0, 0, 0, 0, 33024, 0, 0, 0, 0, 0, 1, 8388608, 0, 0, 2, 5, 29, 1, 4, 0, 0, 0, 1117883, 0, 0, 0, 0, 0, 211464, 40944),
(185484, 0, 0, 0, 0, 0, 33024, 0, 0, 0, 0, 0, 1, 8388608, 0, 0, 0, 15, 29, 1, 4, 0, 0, 0, 1117883, 0, 0, 0, 0, 0, 211464, 40944);

UPDATE `spell_misc` SET `Attributes11`=8192, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=442853;

DELETE FROM `spell_name` WHERE `VerifiedBuild`>0 AND `ID` IN (361952, 256817, 247692, 247111, 247110, 247104, 247103, 247099, 247096, 247094, 247093, 247092, 247089, 247088, 228844, 227799, 227780, 362986, 243328, 53385, 329902, 307934, 307480, 365080, 317920, 465, 357407, 357406, 357405, 356631, 328923, 101546, 364944, 228462, 119611, 119607, 347944, 347943, 1714);
INSERT INTO `spell_name` (`ID`, `Name`, `VerifiedBuild`) VALUES
(361952, '1000 Anima', 40944),
(256817, 'Mark of Aman\'thul', 40944),
(247692, 'Keepsake Continuum', 40944),
(247111, 'Blessing of the Bronze Dragonflight Passive', 40944),
(247110, 'Infinite Velocity', 40944),
(247104, 'Acceleration Passive', 40944),
(247103, 'Time Stop Passive', 40944),
(247099, 'Chrono Charisma Passive', 40944),
(247096, 'Rapid Recovery Passive', 40944),
(247094, 'Fortuitous', 40944),
(247093, 'Dragon\'s Determination Passive', 40944),
(247092, 'Accelerated Aggression Passive', 40944),
(247089, 'Dragon Crash Passive', 40944),
(247088, 'Insight', 40944),
(228844, 'Burning Bones', 40944),
(227799, 'Wash Away', 40944),
(227780, 'Thunder Ritual', 40944),
(362986, 'Experience', 40944),
(243328, 'Fade', 40944),
(53385, 'Divine Storm', 40944),
(329902, 'Dredging', 40944),
(307934, 'Dredging', 40944),
(307480, 'Throw Dredger', 40944),
(365080, 'Windwalking', 40944),
(317920, 'Concentration Aura', 40944),
(465, 'Devotion Aura', 40944),
(357407, 'Summon Havac', 40944),
(357406, 'Summon Battle Trak', 40944),
(357405, 'Summon Dirt Devil', 40944),
(356631, 'Summon Air Blade', 40944),
(328923, 'Fae Transfusion', 40944),
(101546, 'Spinning Crane Kick', 40944),
(364944, 'Windwalking', 40944),
(228462, 'Signet of Melandrus', 40944),
(119611, 'Renewing Mist', 40944),
(119607, 'Renewing Mist', 40944),
(347944, 'Obleron Spikes', 40944),
(347943, 'Obleron Endurance', 40944),
(1714, 'Curse of Tongues', 40944);


DELETE FROM `spell_scaling` WHERE `VerifiedBuild`>0 AND `ID` IN (12823, 12503);
INSERT INTO `spell_scaling` (`ID`, `SpellID`, `MinScalingLevel`, `MaxScalingLevel`, `ScalesFromItemLevel`, `VerifiedBuild`) VALUES
(12823, 355321, 0, 0, 0, 40944),
(12503, 336588, 0, 0, 0, 40944);


DELETE FROM `spell_x_spell_visual` WHERE `VerifiedBuild`>0 AND `ID` IN (337514, 337512, 277583);
INSERT INTO `spell_x_spell_visual` (`ID`, `DifficultyID`, `SpellVisualID`, `Probability`, `Priority`, `SpellIconFileID`, `ActiveIconFileID`, `ViewerUnitConditionID`, `ViewerPlayerConditionID`, `CasterUnitConditionID`, `CasterPlayerConditionID`, `SpellID`, `VerifiedBuild`) VALUES
(337514, 0, 105935, 1, 0, 0, 0, 0, 0, 0, 0, 307926, 40944),
(337512, 0, 90461, 1, 0, 0, 0, 0, 0, 0, 73005, 307934, 40944),
(277583, 0, 98678, 1, 1, 0, 0, 0, 0, 0, 73006, 307934, 40944);


DELETE FROM `tact_key` WHERE `VerifiedBuild`>0 AND `ID` IN (354, 285);
INSERT INTO `tact_key` (`ID`, `Key1`, `Key2`, `Key3`, `Key4`, `Key5`, `Key6`, `Key7`, `Key8`, `Key9`, `Key10`, `Key11`, `Key12`, `Key13`, `Key14`, `Key15`, `Key16`, `VerifiedBuild`) VALUES
(354, 50, 129, 172, 49, 33, 0, 196, 15, 226, 146, 50, 104, 225, 249, 0, 251, 40944),
(285, 206, 130, 175, 131, 243, 154, 10, 243, 73, 200, 94, 198, 161, 83, 178, 191, 40944);


DELETE FROM `transmog_holiday` WHERE `VerifiedBuild`>0 AND `ID` IN (151806, 151804, 151792, 151790, 146306, 34685, 34683, 33969, 33968, 33967, 33966, 33868, 33864, 33863, 33862, 23324, 21525, 21524, 6833);
INSERT INTO `transmog_holiday` (`ID`, `RequiredTransmogHoliday`, `VerifiedBuild`) VALUES
(151806, 181, 40944),
(151804, 181, 40944),
(151792, 141, 40944),
(151790, 141, 40944),
(146306, 141, 40944),
(34685, 341, 40944),
(34683, 341, 40944),
(33969, 372, 40944),
(33968, 372, 40944),
(33967, 372, 40944),
(33966, 372, 40944),
(33868, 372, 40944),
(33864, 372, 40944),
(33863, 372, 40944),
(33862, 372, 40944),
(23324, 341, 40944),
(21525, 141, 40944),
(21524, 141, 40944),
(6833, 181, 40944);


DELETE FROM `transmog_set` WHERE `VerifiedBuild`>0 AND `ID` IN (2289, 2287, 2283, 2281, 2277, 2275, 2271, 2269, 2178);
INSERT INTO `transmog_set` (`Name`, `ID`, `ClassMask`, `TrackingQuestID`, `Flags`, `TransmogSetGroupID`, `ItemNameDescriptionID`, `ParentTransmogSetID`, `Unknown810`, `ExpansionID`, `PatchID`, `UiOrder`, `PlayerConditionID`, `VerifiedBuild`) VALUES
('Unchained Gladiator\'s Plate', 2289, 35, 0, 19, 0, 0, 0, 1, 8, 90100, 2000, 0, 40944),
('Unchained Gladiator\'s Plate', 2287, 35, 0, 19, 0, 0, 0, 1, 8, 90100, 2000, 0, 40944),
('Unchained Gladiator\'s Chain', 2283, 68, 0, 19, 0, 0, 0, 1, 8, 90100, 2000, 0, 40944),
('Unchained Gladiator\'s Chain', 2281, 68, 0, 19, 0, 0, 0, 1, 8, 90100, 2000, 0, 40944),
('Unchained Gladiator\'s Leathers', 2277, 3592, 0, 19, 0, 0, 0, 1, 8, 90100, 2000, 0, 40944),
('Unchained Gladiator\'s Leathers', 2275, 3592, 0, 19, 0, 0, 0, 1, 8, 90100, 2000, 0, 40944),
('Unchained Gladiator\'s Vestment', 2271, 400, 0, 19, 0, 0, 0, 1, 8, 90100, 2000, 0, 40944),
('Unchained Gladiator\'s Vestment', 2269, 400, 0, 19, 0, 0, 0, 1, 8, 90100, 2000, 0, 40944),
('Stitchmasters\' Weapons', 2178, 0, 62901, 1, 0, 0, 0, 1, 8, 90002, 1670, 93648, 40944);

UPDATE `transmog_set` SET `PlayerConditionID`=93650, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2221;
UPDATE `transmog_set` SET `PlayerConditionID`=93650, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2220;
UPDATE `transmog_set` SET `PlayerConditionID`=93650, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2219;
UPDATE `transmog_set` SET `PlayerConditionID`=93650, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2218;
UPDATE `transmog_set` SET `PlayerConditionID`=93650, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2217;
UPDATE `transmog_set` SET `PlayerConditionID`=93650, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2216;
UPDATE `transmog_set` SET `PlayerConditionID`=93650, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2215;
UPDATE `transmog_set` SET `PlayerConditionID`=93650, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2214;
UPDATE `transmog_set` SET `PlayerConditionID`=93648, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2213;
UPDATE `transmog_set` SET `PlayerConditionID`=93648, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2212;
UPDATE `transmog_set` SET `PlayerConditionID`=93648, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2211;
UPDATE `transmog_set` SET `PlayerConditionID`=93648, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2210;
UPDATE `transmog_set` SET `PlayerConditionID`=93647, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2209;
UPDATE `transmog_set` SET `PlayerConditionID`=93647, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2208;
UPDATE `transmog_set` SET `Name`='Forsworn Aspirant\'s Regalia', `PlayerConditionID`=93647, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2207;
UPDATE `transmog_set` SET `PlayerConditionID`=93647, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2206;
UPDATE `transmog_set` SET `PlayerConditionID`=93649, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2205;
UPDATE `transmog_set` SET `PlayerConditionID`=93649, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2204;
UPDATE `transmog_set` SET `PlayerConditionID`=93649, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2203;
UPDATE `transmog_set` SET `PlayerConditionID`=93649, `VerifiedBuild`=40944 WHERE `VerifiedBuild`>0 AND `ID`=2202;

DELETE FROM `transmog_set_item` WHERE `VerifiedBuild`>0 AND `ID` IN (49086, 49085, 49084, 49083, 49082, 49081, 49080, 49079, 49078, 49077, 49076, 49075, 49074, 49073, 49072, 49071);
INSERT INTO `transmog_set_item` (`ID`, `TransmogSetID`, `ItemModifiedAppearanceID`, `Flags`, `VerifiedBuild`) VALUES
(49086, 2289, 116253, 0, 40944),
(49085, 2289, 116144, 1, 40944),
(49084, 2287, 116265, 0, 40944),
(49083, 2287, 116156, 1, 40944),
(49082, 2283, 116283, 0, 40944),
(49081, 2283, 116174, 1, 40944),
(49080, 2281, 116269, 0, 40944),
(49079, 2281, 116160, 1, 40944),
(49078, 2277, 116285, 0, 40944),
(49077, 2277, 116176, 1, 40944),
(49076, 2275, 116271, 0, 40944),
(49075, 2275, 116162, 1, 40944),
(49074, 2271, 116281, 0, 40944),
(49073, 2271, 116172, 1, 40944),
(49072, 2269, 116267, 0, 40944),
(49071, 2269, 116158, 1, 40944);


DELETE FROM `world_effect` WHERE `VerifiedBuild`>0 AND `ID`=18167;
INSERT INTO `world_effect` (`ID`, `QuestFeedbackEffectID`, `WhenToDisplay`, `TargetType`, `TargetAsset`, `PlayerConditionID`, `CombatConditionID`, `VerifiedBuild`) VALUES
(18167, 104, 17, 1, 157891, 73006, 0, 40944);


DELETE FROM `world_state_expression` WHERE `VerifiedBuild`>0 AND `ID`=21677;
INSERT INTO `world_state_expression` (`ID`, `Expression`, `VerifiedBuild`) VALUES
(21677, '0102AA33000000010102000000000202AA33000000010103000000000202475200000001010100000000', 40944);


DELETE FROM `achievement` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `anim_kit` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `animation_data` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_group_member` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_trigger` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `armor_location` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_category` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_power` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_power_link` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_power_picker` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_power_rank` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_quest_xp` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_tier` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_unlock` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_empowered_item` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_item` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_item_milestone_power` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_knowledge_multiplier` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_level_info` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_power` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_power_set_member` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_tier_unlock` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_tier_unlock_set` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_unlock_mapping` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `bank_bag_slot_prices` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `banned_addons` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_breed_quality` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_breed_state` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_state` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `cfg_regions` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `character_loadout` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `character_loadout_item` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_class_ui_display` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_x_power_types` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_display_info` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_element` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_req` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_req_choice` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_model` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_race_x_chr_model` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `cinematic_camera` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `cinematic_sequences` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `content_tuning` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `content_tuning_x_expected` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `conversation_line` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `corruption_effects` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_display_info` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_display_info_extra` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_model_data` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `curve` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `curve_point` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `destructible_model_data` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `durability_costs` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `durability_quality` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `emotes` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `emotes_text` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `emotes_text_sound` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `expected_stat` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `expected_stat_mod` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_template` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobject_display_info` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_plot_inst` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_x_ability` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_plot` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_plot_building` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_plot_instance` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_site_level` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_site_level_plot_inst` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gem_properties` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `global_curve` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `glyph_bindable_spell` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `glyph_properties` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `glyph_required_spec` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `guild_color_background` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `guild_color_border` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `guild_color_emblem` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `guild_perk_spells` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `holidays` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `import_price_armor` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `import_price_quality` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `import_price_shield` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `import_price_weapon` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_appearance` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_armor_quality` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_armor_shield` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_armor_total` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bonus` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bonus_list_level_delta` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bonus_tree_node` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_child_equipment` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_currency_cost` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_damage_ammo` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_damage_one_hand` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_damage_one_hand_caster` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_damage_two_hand` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_damage_two_hand_caster` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_disenchant_loot` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_effect` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_extended_cost` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_level_selector` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_level_selector_quality` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_level_selector_quality_set` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_condition` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_modified_appearance` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_modified_appearance_extra` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_price_base` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_spell` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_spec` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_spec_override` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_x_bonus_tree` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_x_item_effect` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `language_words` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `light` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `liquid_type` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lock` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_x_condition` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `maw_power` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `modifier_tree` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_capability` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_type_x_capability` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_x_display` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `movie` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `name_gen` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `names_profanity` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `names_reserved` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `names_reserved_locale` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `num_talents_at_level` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `override_spell_data` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_difficulty` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_item` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `paragon_reputation` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `phase` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `phase_x_phase_group` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `power_display` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `power_type` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_category` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_slot_unlock` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_faction_reward` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_info` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_line_x_quest` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_money_reward` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_package_item` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_v2` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_xp` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `rand_prop_points` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `reward_pack` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `reward_pack_x_currency_type` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `reward_pack_x_item` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scene_script` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scene_script_global_text` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scene_script_package` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scene_script_text` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_ability` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_race_class_info` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `soulbind_conduit_rank` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `sound_kit` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spec_set_member` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_aura_options` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_aura_restrictions` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_cast_times` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_casting_requirements` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_categories` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_class_options` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_cooldowns` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_duration` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_effect` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_equipped_items` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_interrupts` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_condition` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_label` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_learn_spell` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_levels` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_misc` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_power` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_power_difficulty` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_procs_per_minute` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_procs_per_minute_mod` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_radius` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_reagents` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_reagents_currency` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_scaling` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_target_restrictions` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_totems` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_visual_kit` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_x_spell_visual` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `summon_properties` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_path` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_path_node` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_holiday` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_illusion` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_item` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transport_animation` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transport_rotation` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_assignment` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_link` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_x_map_art` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `vehicle` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `vehicle_seat` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `world_effect` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `world_map_overlay` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `world_state_expression` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_data` WHERE (`Id`=66164 AND `TableHash`=1163127287 AND `RecordId`=71980) OR (`Id`=66164 AND `TableHash`=3322146344 AND `RecordId`=476604) OR (`Id`=66164 AND `TableHash`=1720692227 AND `RecordId`=171381) OR (`Id`=66164 AND `TableHash`=1187407512 AND `RecordId`=361952) OR (`Id`=66164 AND `TableHash`=3776013982 AND `RecordId`=361952) OR (`Id`=66163 AND `TableHash`=1163127287 AND `RecordId`=41339) OR (`Id`=66160 AND `TableHash`=1089023333 AND `RecordId`=8590) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84469) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84468) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84467) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84466) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84465) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84464) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84463) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84462) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84461) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84460) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84459) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84458) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84457) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84456) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84455) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84454) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84453) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84452) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84451) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84450) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84449) OR (`Id`=66160 AND `TableHash`=813076512 AND `RecordId`=84448) OR (`Id`=66160 AND `TableHash`=1187407512 AND `RecordId`=256817) OR (`Id`=66160 AND `TableHash`=3776013982 AND `RecordId`=256817) OR (`Id`=66159 AND `TableHash`=3322146344 AND `RecordId`=220895) OR (`Id`=66159 AND `TableHash`=3322146344 AND `RecordId`=220894) OR (`Id`=66159 AND `TableHash`=3322146344 AND `RecordId`=220890) OR (`Id`=66159 AND `TableHash`=3322146344 AND `RecordId`=220887) OR (`Id`=66159 AND `TableHash`=3322146344 AND `RecordId`=220884) OR (`Id`=66159 AND `TableHash`=3322146344 AND `RecordId`=220883) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213674) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213673) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213672) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213671) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213670) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213669) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213668) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213667) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213666) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213665) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213664) OR (`Id`=66159 AND `TableHash`=1627543382 AND `RecordId`=213663) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247692) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247692) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247111) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247111) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247110) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247110) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247104) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247104) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247103) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247103) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247099) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247099) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247096) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247096) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247094) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247094) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247093) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247093) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247092) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247092) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247089) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247089) OR (`Id`=66159 AND `TableHash`=1187407512 AND `RecordId`=247088) OR (`Id`=66159 AND `TableHash`=3776013982 AND `RecordId`=247088) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9040) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9039) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9038) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9037) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9036) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9035) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9034) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9033) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9032) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9031) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9030) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9029) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9028) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9027) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9026) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9025) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9024) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9023) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9022) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9021) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9020) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9019) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9018) OR (`Id`=66159 AND `TableHash`=3479059991 AND `RecordId`=9017) OR (`Id`=66157 AND `TableHash`=1163127287 AND `RecordId`=57736) OR (`Id`=66157 AND `TableHash`=1163127287 AND `RecordId`=57345) OR (`Id`=66157 AND `TableHash`=3322146344 AND `RecordId`=386747) OR (`Id`=66157 AND `TableHash`=4030871717 AND `RecordId`=793985) OR (`Id`=66154 AND `TableHash`=3322146344 AND `RecordId`=480160) OR (`Id`=66154 AND `TableHash`=4030871717 AND `RecordId`=906380) OR (`Id`=66154 AND `TableHash`=1187407512 AND `RecordId`=365452) OR (`Id`=66154 AND `TableHash`=3776013982 AND `RecordId`=365452) OR (`Id`=66153 AND `TableHash`=1187407512 AND `RecordId`=228844) OR (`Id`=66153 AND `TableHash`=3776013982 AND `RecordId`=228844) OR (`Id`=66153 AND `TableHash`=1187407512 AND `RecordId`=227799) OR (`Id`=66153 AND `TableHash`=3776013982 AND `RecordId`=227799) OR (`Id`=66153 AND `TableHash`=1187407512 AND `RecordId`=227780) OR (`Id`=66153 AND `TableHash`=3776013982 AND `RecordId`=227780) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=120249) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=119322) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=119299) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=119267) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118939) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118773) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118751) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118574) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118450) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118418) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118415) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118407) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118318) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118299) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118118) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118111) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118110) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118109) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118108) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=118009) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117978) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117977) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117976) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117974) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117973) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117967) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117847) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117672) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117654) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117586) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=117585) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=13134) OR (`Id`=66153 AND `TableHash`=3386943305 AND `RecordId`=13133) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=117578) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116865) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116864) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116804) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116802) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116573) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116563) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116562) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116561) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116495) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116494) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116491) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116447) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116418) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116259) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116124) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116003) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=116002) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115986) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115984) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115983) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115982) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115981) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115976) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115967) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115789) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115746) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115743) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115734) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115725) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115694) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115510) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115501) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115497) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115496) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115493) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115491) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115490) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115489) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115487) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115427) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115426) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115386) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115274) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115234) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115213) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115212) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115124) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115123) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115118) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115113) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115105) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115103) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115101) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115063) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115062) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115061) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115059) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115057) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115038) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115034) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115033) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115032) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115030) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115022) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115016) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115013) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=115007) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114947) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114940) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114938) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114913) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114906) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114903) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114895) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114844) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114843) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114842) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114839) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114835) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114834) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114833) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114815) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114800) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114799) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114653) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114649) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114648) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114647) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114646) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114616) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114583) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114556) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114555) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114554) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114552) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114551) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114545) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114520) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114486) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114471) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114463) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114462) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114408) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114339) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114335) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114327) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114315) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114273) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=114272) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=17652) OR (`Id`=66153 AND `TableHash`=3386291891 AND `RecordId`=17651) OR (`Id`=66152 AND `TableHash`=1163127287 AND `RecordId`=71974) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20839) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20838) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20780) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20768) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20732) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20730) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20694) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20689) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20688) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20666) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20665) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20660) OR (`Id`=66151 AND `TableHash`=312611497 AND `RecordId`=20659) OR (`Id`=66149 AND `TableHash`=3386943305 AND `RecordId`=195106) OR (`Id`=66148 AND `TableHash`=20077728 AND `RecordId`=421940) OR (`Id`=66147 AND `TableHash`=1187407512 AND `RecordId`=362986) OR (`Id`=66147 AND `TableHash`=3776013982 AND `RecordId`=362986) OR (`Id`=66145 AND `TableHash`=356071576 AND `RecordId`=2291) OR (`Id`=66143 AND `TableHash`=1163127287 AND `RecordId`=67010) OR (`Id`=66142 AND `TableHash`=1163127287 AND `RecordId`=69080) OR (`Id`=66141 AND `TableHash`=1089023333 AND `RecordId`=12823) OR (`Id`=66141 AND `TableHash`=1089023333 AND `RecordId`=12503) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=470710) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=469819) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=466278) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=443445) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=443195) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=442853) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=442539) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=442283) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=441981) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=440946) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=439981) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=436996) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=434017) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=433894) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=433252) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=433196) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=428505) OR (`Id`=66141 AND `TableHash`=3322146344 AND `RecordId`=404479) OR (`Id`=66141 AND `TableHash`=4030871717 AND `RecordId`=882432) OR (`Id`=66137 AND `TableHash`=3386943305 AND `RecordId`=120066) OR (`Id`=66136 AND `TableHash`=1163127287 AND `RecordId`=71965) OR (`Id`=66136 AND `TableHash`=1163127287 AND `RecordId`=71964) OR (`Id`=66136 AND `TableHash`=1163127287 AND `RecordId`=67566) OR (`Id`=66136 AND `TableHash`=3322146344 AND `RecordId`=466256) OR (`Id`=66136 AND `TableHash`=3322146344 AND `RecordId`=466253) OR (`Id`=66136 AND `TableHash`=4030871717 AND `RecordId`=882392) OR (`Id`=66134 AND `TableHash`=261693969 AND `RecordId`=60399) OR (`Id`=66134 AND `TableHash`=986198281 AND `RecordId`=60399) OR (`Id`=66134 AND `TableHash`=261693969 AND `RecordId`=60396) OR (`Id`=66134 AND `TableHash`=986198281 AND `RecordId`=60396) OR (`Id`=66134 AND `TableHash`=261693969 AND `RecordId`=60392) OR (`Id`=66134 AND `TableHash`=986198281 AND `RecordId`=60392) OR (`Id`=66134 AND `TableHash`=261693969 AND `RecordId`=60381) OR (`Id`=66134 AND `TableHash`=986198281 AND `RecordId`=60381) OR (`Id`=66133 AND `TableHash`=2202435563 AND `RecordId`=1022281) OR (`Id`=66133 AND `TableHash`=2202435563 AND `RecordId`=1016248) OR (`Id`=66133 AND `TableHash`=2921112328 AND `RecordId`=474530) OR (`Id`=66133 AND `TableHash`=2921112328 AND `RecordId`=472639) OR (`Id`=66131 AND `TableHash`=3108775943 AND `RecordId`=85644) OR (`Id`=66131 AND `TableHash`=69094805 AND `RecordId`=161) OR (`Id`=66129 AND `TableHash`=1344507586 AND `RecordId`=176922) OR (`Id`=66129 AND `TableHash`=428746933 AND `RecordId`=176922) OR (`Id`=66129 AND `TableHash`=2442913102 AND `RecordId`=176922) OR (`Id`=66129 AND `TableHash`=3865974254 AND `RecordId`=176922) OR (`Id`=66129 AND `TableHash`=3037505077 AND `RecordId`=176922) OR (`Id`=66129 AND `TableHash`=1417785224 AND `RecordId`=176922) OR (`Id`=66129 AND `TableHash`=1344507586 AND `RecordId`=176921) OR (`Id`=66129 AND `TableHash`=428746933 AND `RecordId`=176921) OR (`Id`=66129 AND `TableHash`=2442913102 AND `RecordId`=176921) OR (`Id`=66129 AND `TableHash`=3865974254 AND `RecordId`=176921) OR (`Id`=66129 AND `TableHash`=3037505077 AND `RecordId`=176921) OR (`Id`=66129 AND `TableHash`=1417785224 AND `RecordId`=176921) OR (`Id`=66129 AND `TableHash`=1344507586 AND `RecordId`=176832) OR (`Id`=66129 AND `TableHash`=428746933 AND `RecordId`=176832) OR (`Id`=66129 AND `TableHash`=2442913102 AND `RecordId`=176832) OR (`Id`=66129 AND `TableHash`=3865974254 AND `RecordId`=176832) OR (`Id`=66129 AND `TableHash`=3037505077 AND `RecordId`=176832) OR (`Id`=66129 AND `TableHash`=1417785224 AND `RecordId`=176832) OR (`Id`=66128 AND `TableHash`=1344507586 AND `RecordId`=185950) OR (`Id`=66128 AND `TableHash`=428746933 AND `RecordId`=185950) OR (`Id`=66128 AND `TableHash`=2442913102 AND `RecordId`=185950) OR (`Id`=66128 AND `TableHash`=3865974254 AND `RecordId`=185950) OR (`Id`=66128 AND `TableHash`=3037505077 AND `RecordId`=185950) OR (`Id`=66128 AND `TableHash`=1417785224 AND `RecordId`=185950) OR (`Id`=66128 AND `TableHash`=1344507586 AND `RecordId`=185947) OR (`Id`=66128 AND `TableHash`=428746933 AND `RecordId`=185947) OR (`Id`=66128 AND `TableHash`=2442913102 AND `RecordId`=185947) OR (`Id`=66128 AND `TableHash`=3865974254 AND `RecordId`=185947) OR (`Id`=66128 AND `TableHash`=3037505077 AND `RecordId`=185947) OR (`Id`=66128 AND `TableHash`=1417785224 AND `RecordId`=185947) OR (`Id`=66128 AND `TableHash`=1344507586 AND `RecordId`=185946) OR (`Id`=66128 AND `TableHash`=428746933 AND `RecordId`=185946) OR (`Id`=66128 AND `TableHash`=2442913102 AND `RecordId`=185946) OR (`Id`=66128 AND `TableHash`=3865974254 AND `RecordId`=185946) OR (`Id`=66128 AND `TableHash`=3037505077 AND `RecordId`=185946) OR (`Id`=66128 AND `TableHash`=1417785224 AND `RecordId`=185946) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=21052) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=21051) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=21050) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=21049) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=20654) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=20407) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=20373) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=20319) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=20230) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=20221) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=19850) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=19768) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=19589) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=19527) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=19515) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=19514) OR (`Id`=66126 AND `TableHash`=312611497 AND `RecordId`=19491) OR (`Id`=66126 AND `TableHash`=1163127287 AND `RecordId`=71962) OR (`Id`=66126 AND `TableHash`=1163127287 AND `RecordId`=59746) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=399210) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=398349) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=387476) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=361592) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=347465) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=338383) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=244146) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=240717) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=239468) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=206447) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=176741) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=158326) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=129003) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=103578) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=90408) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=82262) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=59320) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=49191) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=49011) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=40524) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=39830) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=32568) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=18143) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=18141) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=14100) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=11746) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=8941) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=8922) OR (`Id`=66124 AND `TableHash`=3322146344 AND `RecordId`=2380) OR (`Id`=66124 AND `TableHash`=3502494094 AND `RecordId`=1186) OR (`Id`=66121 AND `TableHash`=813076512 AND `RecordId`=84443) OR (`Id`=66121 AND `TableHash`=813076512 AND `RecordId`=84442) OR (`Id`=66118 AND `TableHash`=813076512 AND `RecordId`=84441) OR (`Id`=66115 AND `TableHash`=3108775943 AND `RecordId`=94796) OR (`Id`=66115 AND `TableHash`=2246024846 AND `RecordId`=683) OR (`Id`=66113 AND `TableHash`=4030871717 AND `RecordId`=369676) OR (`Id`=66113 AND `TableHash`=680438657 AND `RecordId`=29443) OR (`Id`=66113 AND `TableHash`=1187407512 AND `RecordId`=243328) OR (`Id`=66113 AND `TableHash`=3776013982 AND `RecordId`=243328) OR (`Id`=66112 AND `TableHash`=1163127287 AND `RecordId`=71952) OR (`Id`=66112 AND `TableHash`=1163127287 AND `RecordId`=69409) OR (`Id`=66112 AND `TableHash`=3322146344 AND `RecordId`=479781) OR (`Id`=66112 AND `TableHash`=4030871717 AND `RecordId`=905674) OR (`Id`=66111 AND `TableHash`=331613093 AND `RecordId`=369145) OR (`Id`=66109 AND `TableHash`=3108775943 AND `RecordId`=94998) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178500) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178499) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178498) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178497) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178496) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178495) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178494) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178493) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178492) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178491) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178490) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178489) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178488) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178487) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=178475) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=176083) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=176082) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=174511) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=174279) OR (`Id`=66109 AND `TableHash`=2120822102 AND `RecordId`=174278) OR (`Id`=66109 AND `TableHash`=35137211 AND `RecordId`=215514) OR (`Id`=66109 AND `TableHash`=35137211 AND `RecordId`=215513) OR (`Id`=66109 AND `TableHash`=35137211 AND `RecordId`=215512) OR (`Id`=66109 AND `TableHash`=35137211 AND `RecordId`=215511) OR (`Id`=66108 AND `TableHash`=1163127287 AND `RecordId`=49170) OR (`Id`=66105 AND `TableHash`=1344507586 AND `RecordId`=187935) OR (`Id`=66105 AND `TableHash`=428746933 AND `RecordId`=187935) OR (`Id`=66105 AND `TableHash`=2442913102 AND `RecordId`=187935) OR (`Id`=66105 AND `TableHash`=3865974254 AND `RecordId`=187935) OR (`Id`=66105 AND `TableHash`=3037505077 AND `RecordId`=187935) OR (`Id`=66105 AND `TableHash`=1417785224 AND `RecordId`=187935) OR (`Id`=66102 AND `TableHash`=312611497 AND `RecordId`=20180) OR (`Id`=66102 AND `TableHash`=1163127287 AND `RecordId`=65231) OR (`Id`=66102 AND `TableHash`=4030871717 AND `RecordId`=880680) OR (`Id`=66102 AND `TableHash`=4030871717 AND `RecordId`=845047) OR (`Id`=66099 AND `TableHash`=3386291891 AND `RecordId`=177398) OR (`Id`=66098 AND `TableHash`=3205218938 AND `RecordId`=44300) OR (`Id`=66098 AND `TableHash`=3205218938 AND `RecordId`=44299) OR (`Id`=66098 AND `TableHash`=3205218938 AND `RecordId`=44284) OR (`Id`=66098 AND `TableHash`=3205218938 AND `RecordId`=44283) OR (`Id`=66097 AND `TableHash`=1821637041 AND `RecordId`=3188) OR (`Id`=66095 AND `TableHash`=4030871717 AND `RecordId`=906096) OR (`Id`=66095 AND `TableHash`=4030871717 AND `RecordId`=897551) OR (`Id`=66095 AND `TableHash`=4030871717 AND `RecordId`=897550) OR (`Id`=66094 AND `TableHash`=3322146344 AND `RecordId`=87092) OR (`Id`=66094 AND `TableHash`=1344507586 AND `RecordId`=188152) OR (`Id`=66094 AND `TableHash`=428746933 AND `RecordId`=188152) OR (`Id`=66094 AND `TableHash`=2442913102 AND `RecordId`=188152) OR (`Id`=66094 AND `TableHash`=3865974254 AND `RecordId`=188152) OR (`Id`=66094 AND `TableHash`=3037505077 AND `RecordId`=188152) OR (`Id`=66094 AND `TableHash`=1417785224 AND `RecordId`=188152) OR (`Id`=66093 AND `TableHash`=3764692828 AND `RecordId`=272691) OR (`Id`=66093 AND `TableHash`=1187407512 AND `RecordId`=53385) OR (`Id`=66093 AND `TableHash`=3776013982 AND `RecordId`=53385) OR (`Id`=66092 AND `TableHash`=4030871717 AND `RecordId`=839924) OR (`Id`=66091 AND `TableHash`=261693969 AND `RecordId`=62694) OR (`Id`=66091 AND `TableHash`=986198281 AND `RecordId`=62694) OR (`Id`=66091 AND `TableHash`=261693969 AND `RecordId`=62693) OR (`Id`=66091 AND `TableHash`=986198281 AND `RecordId`=62693) OR (`Id`=66091 AND `TableHash`=261693969 AND `RecordId`=62692) OR (`Id`=66091 AND `TableHash`=986198281 AND `RecordId`=62692) OR (`Id`=66091 AND `TableHash`=261693969 AND `RecordId`=62691) OR (`Id`=66091 AND `TableHash`=986198281 AND `RecordId`=62691) OR (`Id`=66088 AND `TableHash`=1163127287 AND `RecordId`=71781) OR (`Id`=66088 AND `TableHash`=1163127287 AND `RecordId`=65085) OR (`Id`=66088 AND `TableHash`=1163127287 AND `RecordId`=37795) OR (`Id`=66087 AND `TableHash`=3108775943 AND `RecordId`=94798) OR (`Id`=66087 AND `TableHash`=3108775943 AND `RecordId`=94797) OR (`Id`=66087 AND `TableHash`=3108775943 AND `RecordId`=94795) OR (`Id`=66086 AND `TableHash`=331613093 AND `RecordId`=346046) OR (`Id`=66086 AND `TableHash`=331613093 AND `RecordId`=346045) OR (`Id`=66086 AND `TableHash`=3571931810 AND `RecordId`=24353) OR (`Id`=66086 AND `TableHash`=3571931810 AND `RecordId`=17863) OR (`Id`=66086 AND `TableHash`=1225579890 AND `RecordId`=2591) OR (`Id`=66086 AND `TableHash`=1225579890 AND `RecordId`=2590) OR (`Id`=66086 AND `TableHash`=1548466975 AND `RecordId`=22040) OR (`Id`=66085 AND `TableHash`=345681529 AND `RecordId`=133055) OR (`Id`=66085 AND `TableHash`=345681529 AND `RecordId`=133054) OR (`Id`=66085 AND `TableHash`=345681529 AND `RecordId`=133053) OR (`Id`=66085 AND `TableHash`=345681529 AND `RecordId`=133052) OR (`Id`=66083 AND `TableHash`=1163127287 AND `RecordId`=71757) OR (`Id`=66083 AND `TableHash`=1163127287 AND `RecordId`=10352) OR (`Id`=66080 AND `TableHash`=331613093 AND `RecordId`=369216) OR (`Id`=66077 AND `TableHash`=1163127287 AND `RecordId`=71898) OR (`Id`=66077 AND `TableHash`=1163127287 AND `RecordId`=67364) OR (`Id`=66075 AND `TableHash`=3664936999 AND `RecordId`=18167) OR (`Id`=66075 AND `TableHash`=666345498 AND `RecordId`=337514) OR (`Id`=66075 AND `TableHash`=666345498 AND `RecordId`=337512) OR (`Id`=66075 AND `TableHash`=666345498 AND `RecordId`=277583) OR (`Id`=66075 AND `TableHash`=3425193231 AND `RecordId`=290351) OR (`Id`=66075 AND `TableHash`=4146370265 AND `RecordId`=98678) OR (`Id`=66075 AND `TableHash`=3322146344 AND `RecordId`=404541) OR (`Id`=66075 AND `TableHash`=3322146344 AND `RecordId`=382485) OR (`Id`=66075 AND `TableHash`=3322146344 AND `RecordId`=382484) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=905972) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=875244) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=869249) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=869248) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=867891) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=834692) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=834688) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=823351) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=823344) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=823342) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=786826) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=786825) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=786824) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=786815) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=786808) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=786807) OR (`Id`=66075 AND `TableHash`=4030871717 AND `RecordId`=786806) OR (`Id`=66075 AND `TableHash`=1627543382 AND `RecordId`=213643) OR (`Id`=66075 AND `TableHash`=1627543382 AND `RecordId`=213642) OR (`Id`=66075 AND `TableHash`=1187407512 AND `RecordId`=329902) OR (`Id`=66075 AND `TableHash`=3776013982 AND `RecordId`=329902) OR (`Id`=66075 AND `TableHash`=1187407512 AND `RecordId`=307934) OR (`Id`=66075 AND `TableHash`=3776013982 AND `RecordId`=307934) OR (`Id`=66075 AND `TableHash`=1187407512 AND `RecordId`=307480) OR (`Id`=66075 AND `TableHash`=3776013982 AND `RecordId`=307480) OR (`Id`=66075 AND `TableHash`=3108775943 AND `RecordId`=73006) OR (`Id`=66075 AND `TableHash`=3108775943 AND `RecordId`=73005) OR (`Id`=66075 AND `TableHash`=3386943305 AND `RecordId`=175271) OR (`Id`=66075 AND `TableHash`=3386291891 AND `RecordId`=157891) OR (`Id`=66075 AND `TableHash`=3386291891 AND `RecordId`=157884) OR (`Id`=66073 AND `TableHash`=1163127287 AND `RecordId`=71894) OR (`Id`=66073 AND `TableHash`=3322146344 AND `RecordId`=474186) OR (`Id`=66073 AND `TableHash`=2120822102 AND `RecordId`=178369) OR (`Id`=66073 AND `TableHash`=2120822102 AND `RecordId`=178368) OR (`Id`=66073 AND `TableHash`=2120822102 AND `RecordId`=178367) OR (`Id`=66072 AND `TableHash`=2948698321 AND `RecordId`=354) OR (`Id`=66072 AND `TableHash`=3744420815 AND `RecordId`=354) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=65169) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=65169) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=65168) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=65168) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=65165) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=65165) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=65157) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=65157) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=65147) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=65147) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=61058) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=61058) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=61057) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=61057) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=60111) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=60111) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=60110) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=60110) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=59919) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=59919) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=59325) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=59325) OR (`Id`=66071 AND `TableHash`=261693969 AND `RecordId`=58797) OR (`Id`=66071 AND `TableHash`=986198281 AND `RecordId`=58797) OR (`Id`=66066 AND `TableHash`=4033975491 AND `RecordId`=439711) OR (`Id`=66066 AND `TableHash`=4033975491 AND `RecordId`=439689) OR (`Id`=66066 AND `TableHash`=4033975491 AND `RecordId`=439644) OR (`Id`=66066 AND `TableHash`=4030871717 AND `RecordId`=905876) OR (`Id`=66066 AND `TableHash`=4030871717 AND `RecordId`=905875) OR (`Id`=66066 AND `TableHash`=4030871717 AND `RecordId`=905872) OR (`Id`=66066 AND `TableHash`=4030871717 AND `RecordId`=895695) OR (`Id`=66066 AND `TableHash`=4030871717 AND `RecordId`=891440) OR (`Id`=66066 AND `TableHash`=4030871717 AND `RecordId`=891438) OR (`Id`=66066 AND `TableHash`=4030871717 AND `RecordId`=882994) OR (`Id`=66066 AND `TableHash`=4030871717 AND `RecordId`=882993) OR (`Id`=66066 AND `TableHash`=4030871717 AND `RecordId`=874876) OR (`Id`=66059 AND `TableHash`=1255424668 AND `RecordId`=94390) OR (`Id`=66059 AND `TableHash`=1255424668 AND `RecordId`=94389) OR (`Id`=66059 AND `TableHash`=1255424668 AND `RecordId`=94388) OR (`Id`=66059 AND `TableHash`=1255424668 AND `RecordId`=93811) OR (`Id`=66059 AND `TableHash`=1255424668 AND `RecordId`=93810) OR (`Id`=66059 AND `TableHash`=4012104832 AND `RecordId`=52681) OR (`Id`=66059 AND `TableHash`=4012104832 AND `RecordId`=49421) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=151806) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=151806) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=151806) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=151806) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=151806) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=151806) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=151804) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=151804) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=151804) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=151804) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=151804) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=151804) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=151792) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=151792) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=151792) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=151792) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=151792) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=151792) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=151790) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=151790) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=151790) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=151790) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=151790) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=151790) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=146306) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=146306) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=146306) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=146306) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=146306) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=146306) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=34685) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=34685) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=34685) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=34685) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=34685) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=34685) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=34683) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=34683) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=34683) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=34683) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=34683) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=34683) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=34087) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=34087) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=34087) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=34087) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=34087) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=34087) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=34085) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=34085) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=34085) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=34085) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=34085) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=34085) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=33969) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=33969) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=33969) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=33969) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=33969) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=33969) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=33968) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=33968) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=33968) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=33968) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=33968) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=33968) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=33967) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=33967) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=33967) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=33967) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=33967) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=33967) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=33966) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=33966) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=33966) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=33966) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=33966) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=33966) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=33868) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=33868) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=33868) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=33868) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=33868) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=33868) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=33864) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=33864) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=33864) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=33864) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=33864) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=33864) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=33863) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=33863) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=33863) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=33863) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=33863) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=33863) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=33862) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=33862) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=33862) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=33862) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=33862) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=33862) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=23324) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=23324) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=23324) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=23324) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=23324) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=23324) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=21525) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=21525) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=21525) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=21525) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=21525) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=21525) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=21524) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=21524) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=21524) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=21524) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=21524) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=21524) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=19028) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=19028) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=19028) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=19028) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=19028) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=19028) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=6835) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=6835) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=6835) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=6835) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=6835) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=6835) OR (`Id`=66052 AND `TableHash`=1344507586 AND `RecordId`=6833) OR (`Id`=66052 AND `TableHash`=428746933 AND `RecordId`=6833) OR (`Id`=66052 AND `TableHash`=2442913102 AND `RecordId`=6833) OR (`Id`=66052 AND `TableHash`=3865974254 AND `RecordId`=6833) OR (`Id`=66052 AND `TableHash`=3037505077 AND `RecordId`=6833) OR (`Id`=66052 AND `TableHash`=1417785224 AND `RecordId`=6833) OR (`Id`=66049 AND `TableHash`=1344507586 AND `RecordId`=181321) OR (`Id`=66049 AND `TableHash`=428746933 AND `RecordId`=181321) OR (`Id`=66049 AND `TableHash`=2442913102 AND `RecordId`=181321) OR (`Id`=66049 AND `TableHash`=3865974254 AND `RecordId`=181321) OR (`Id`=66049 AND `TableHash`=3037505077 AND `RecordId`=181321) OR (`Id`=66049 AND `TableHash`=1417785224 AND `RecordId`=181321) OR (`Id`=66048 AND `TableHash`=1109793673 AND `RecordId`=43167) OR (`Id`=66048 AND `TableHash`=1109793673 AND `RecordId`=42756) OR (`Id`=66048 AND `TableHash`=1109793673 AND `RecordId`=42671) OR (`Id`=66048 AND `TableHash`=1109793673 AND `RecordId`=42533) OR (`Id`=66045 AND `TableHash`=1548466975 AND `RecordId`=27672) OR (`Id`=66044 AND `TableHash`=501138918 AND `RecordId`=125560) OR (`Id`=66044 AND `TableHash`=813076512 AND `RecordId`=84346) OR (`Id`=66044 AND `TableHash`=813076512 AND `RecordId`=84345) OR (`Id`=66044 AND `TableHash`=813076512 AND `RecordId`=84344) OR (`Id`=66044 AND `TableHash`=1720692227 AND `RecordId`=171288) OR (`Id`=66044 AND `TableHash`=680438657 AND `RecordId`=61714) OR (`Id`=66044 AND `TableHash`=3689412649 AND `RecordId`=123263) OR (`Id`=66044 AND `TableHash`=4096770149 AND `RecordId`=186908) OR (`Id`=66044 AND `TableHash`=1187407512 AND `RecordId`=365080) OR (`Id`=66044 AND `TableHash`=3776013982 AND `RecordId`=365080) OR (`Id`=66043 AND `TableHash`=1163127287 AND `RecordId`=17506) OR (`Id`=66038 AND `TableHash`=4030871717 AND `RecordId`=818347) OR (`Id`=66036 AND `TableHash`=1163127287 AND `RecordId`=60186) OR (`Id`=66034 AND `TableHash`=1089023333 AND `RecordId`=12157) OR (`Id`=66034 AND `TableHash`=1089023333 AND `RecordId`=168) OR (`Id`=66034 AND `TableHash`=3322146344 AND `RecordId`=392545) OR (`Id`=66034 AND `TableHash`=3322146344 AND `RecordId`=221469) OR (`Id`=66034 AND `TableHash`=3322146344 AND `RecordId`=157418) OR (`Id`=66034 AND `TableHash`=3322146344 AND `RecordId`=137) OR (`Id`=66034 AND `TableHash`=1187407512 AND `RecordId`=317920) OR (`Id`=66034 AND `TableHash`=3776013982 AND `RecordId`=317920) OR (`Id`=66034 AND `TableHash`=1187407512 AND `RecordId`=465) OR (`Id`=66034 AND `TableHash`=3776013982 AND `RecordId`=465) OR (`Id`=66031 AND `TableHash`=2137612197 AND `RecordId`=13134) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2221) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2220) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2219) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2218) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2217) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2216) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2215) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2214) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2213) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2212) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2211) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2210) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2209) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2208) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2207) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2206) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2205) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2204) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2203) OR (`Id`=66030 AND `TableHash`=356071576 AND `RecordId`=2202) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49086) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49085) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49084) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49083) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49082) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49081) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49080) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49079) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49078) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49077) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49076) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49075) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49074) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49073) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49072) OR (`Id`=66028 AND `TableHash`=505524148 AND `RecordId`=49071) OR (`Id`=66028 AND `TableHash`=356071576 AND `RecordId`=2289) OR (`Id`=66028 AND `TableHash`=356071576 AND `RecordId`=2287) OR (`Id`=66028 AND `TableHash`=356071576 AND `RecordId`=2283) OR (`Id`=66028 AND `TableHash`=356071576 AND `RecordId`=2281) OR (`Id`=66028 AND `TableHash`=356071576 AND `RecordId`=2277) OR (`Id`=66028 AND `TableHash`=356071576 AND `RecordId`=2275) OR (`Id`=66028 AND `TableHash`=356071576 AND `RecordId`=2271) OR (`Id`=66028 AND `TableHash`=356071576 AND `RecordId`=2269) OR (`Id`=66028 AND `TableHash`=3205218938 AND `RecordId`=44172) OR (`Id`=66028 AND `TableHash`=3205218938 AND `RecordId`=40887) OR (`Id`=66028 AND `TableHash`=3205218938 AND `RecordId`=40885) OR (`Id`=66026 AND `TableHash`=1187407512 AND `RecordId`=357407) OR (`Id`=66026 AND `TableHash`=3776013982 AND `RecordId`=357407) OR (`Id`=66026 AND `TableHash`=1187407512 AND `RecordId`=357406) OR (`Id`=66026 AND `TableHash`=3776013982 AND `RecordId`=357406) OR (`Id`=66026 AND `TableHash`=1187407512 AND `RecordId`=357405) OR (`Id`=66026 AND `TableHash`=3776013982 AND `RecordId`=357405) OR (`Id`=66026 AND `TableHash`=1187407512 AND `RecordId`=356631) OR (`Id`=66026 AND `TableHash`=3776013982 AND `RecordId`=356631) OR (`Id`=66026 AND `TableHash`=1187407512 AND `RecordId`=328923) OR (`Id`=66026 AND `TableHash`=3776013982 AND `RecordId`=328923) OR (`Id`=66026 AND `TableHash`=1187407512 AND `RecordId`=101546) OR (`Id`=66026 AND `TableHash`=3776013982 AND `RecordId`=101546) OR (`Id`=66026 AND `TableHash`=1344507586 AND `RecordId`=188220) OR (`Id`=66026 AND `TableHash`=428746933 AND `RecordId`=188220) OR (`Id`=66026 AND `TableHash`=2442913102 AND `RecordId`=188220) OR (`Id`=66026 AND `TableHash`=3865974254 AND `RecordId`=188220) OR (`Id`=66026 AND `TableHash`=3037505077 AND `RecordId`=188220) OR (`Id`=66026 AND `TableHash`=1417785224 AND `RecordId`=188220) OR (`Id`=66024 AND `TableHash`=3108775943 AND `RecordId`=94883) OR (`Id`=66024 AND `TableHash`=3108775943 AND `RecordId`=87365) OR (`Id`=66024 AND `TableHash`=3108775943 AND `RecordId`=86416) OR (`Id`=66024 AND `TableHash`=2120822102 AND `RecordId`=153266) OR (`Id`=66024 AND `TableHash`=2120822102 AND `RecordId`=153265) OR (`Id`=66024 AND `TableHash`=2246024846 AND `RecordId`=693) OR (`Id`=66024 AND `TableHash`=3538824359 AND `RecordId`=14775) OR (`Id`=66024 AND `TableHash`=3538824359 AND `RecordId`=14752) OR (`Id`=66024 AND `TableHash`=3538824359 AND `RecordId`=14682) OR (`Id`=66024 AND `TableHash`=3538824359 AND `RecordId`=14351) OR (`Id`=66023 AND `TableHash`=1163127287 AND `RecordId`=69274) OR (`Id`=66023 AND `TableHash`=1163127287 AND `RecordId`=69002) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=187900) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=187900) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=187900) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=187900) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=187900) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=187900) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=187899) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=187899) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=187899) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=187899) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=187899) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=187899) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=187898) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=187898) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=187898) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=187898) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=187898) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=187898) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=187897) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=187897) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=187897) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=187897) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=187897) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=187897) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=187896) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=187896) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=187896) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=187896) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=187896) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=187896) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=187895) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=187895) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=187895) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=187895) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=187895) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=187895) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=187875) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=187875) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=187875) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=187875) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=187875) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=187875) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=187869) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=187869) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=187869) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=187869) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=187869) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=187869) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=150746) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=150746) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=150746) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=150746) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=150746) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=150746) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=150745) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=150745) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=150745) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=150745) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=150745) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=150745) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=150744) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=150744) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=150744) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=150744) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=150744) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=150744) OR (`Id`=66012 AND `TableHash`=1344507586 AND `RecordId`=150743) OR (`Id`=66012 AND `TableHash`=428746933 AND `RecordId`=150743) OR (`Id`=66012 AND `TableHash`=2442913102 AND `RecordId`=150743) OR (`Id`=66012 AND `TableHash`=3865974254 AND `RecordId`=150743) OR (`Id`=66012 AND `TableHash`=3037505077 AND `RecordId`=150743) OR (`Id`=66012 AND `TableHash`=1417785224 AND `RecordId`=150743) OR (`Id`=66011 AND `TableHash`=356071576 AND `RecordId`=2178) OR (`Id`=66011 AND `TableHash`=3108775943 AND `RecordId`=85912) OR (`Id`=66011 AND `TableHash`=3108775943 AND `RecordId`=85910) OR (`Id`=66011 AND `TableHash`=3108775943 AND `RecordId`=85909) OR (`Id`=66011 AND `TableHash`=3108775943 AND `RecordId`=85692) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178172) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178171) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178170) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178169) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178168) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178167) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178166) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178165) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178164) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178163) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178162) OR (`Id`=66011 AND `TableHash`=2120822102 AND `RecordId`=178161) OR (`Id`=66005 AND `TableHash`=1163127287 AND `RecordId`=69843) OR (`Id`=66005 AND `TableHash`=3322146344 AND `RecordId`=471340) OR (`Id`=66005 AND `TableHash`=4030871717 AND `RecordId`=905454) OR (`Id`=66005 AND `TableHash`=4030871717 AND `RecordId`=898199) OR (`Id`=66003 AND `TableHash`=3179597154 AND `RecordId`=1756) OR (`Id`=66002 AND `TableHash`=4096770149 AND `RecordId`=9518) OR (`Id`=66000 AND `TableHash`=1163127287 AND `RecordId`=69881) OR (`Id`=66000 AND `TableHash`=3322146344 AND `RecordId`=472345) OR (`Id`=65999 AND `TableHash`=1163127287 AND `RecordId`=71780) OR (`Id`=65999 AND `TableHash`=3322146344 AND `RecordId`=444258) OR (`Id`=65998 AND `TableHash`=3322146344 AND `RecordId`=479643) OR (`Id`=65998 AND `TableHash`=501138918 AND `RecordId`=125558) OR (`Id`=65998 AND `TableHash`=813076512 AND `RecordId`=84323) OR (`Id`=65998 AND `TableHash`=813076512 AND `RecordId`=84322) OR (`Id`=65998 AND `TableHash`=813076512 AND `RecordId`=84321) OR (`Id`=65998 AND `TableHash`=1720692227 AND `RecordId`=171235) OR (`Id`=65998 AND `TableHash`=4030871717 AND `RecordId`=905418) OR (`Id`=65998 AND `TableHash`=4030871717 AND `RecordId`=905417) OR (`Id`=65998 AND `TableHash`=680438657 AND `RecordId`=61709) OR (`Id`=65998 AND `TableHash`=3689412649 AND `RecordId`=123205) OR (`Id`=65998 AND `TableHash`=4096770149 AND `RecordId`=186896) OR (`Id`=65998 AND `TableHash`=1187407512 AND `RecordId`=364944) OR (`Id`=65998 AND `TableHash`=3776013982 AND `RecordId`=364944) OR (`Id`=65997 AND `TableHash`=800559195 AND `RecordId`=1523) OR (`Id`=65997 AND `TableHash`=800559195 AND `RecordId`=689) OR (`Id`=65996 AND `TableHash`=3689412649 AND `RecordId`=1791) OR (`Id`=65996 AND `TableHash`=3689412649 AND `RecordId`=1741) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16884) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16881) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16879) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16877) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16875) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16873) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16871) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16869) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16867) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16865) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16864) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16861) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16859) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16857) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16855) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16853) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16851) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16849) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16847) OR (`Id`=65994 AND `TableHash`=3603976684 AND `RecordId`=16845) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=550) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=547) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=545) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=543) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=541) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=539) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=537) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=535) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=533) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=531) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=530) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=527) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=525) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=523) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=521) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=519) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=517) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=515) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=513) OR (`Id`=65994 AND `TableHash`=3204974385 AND `RecordId`=511) OR (`Id`=65993 AND `TableHash`=4030871717 AND `RecordId`=815761) OR (`Id`=65993 AND `TableHash`=4030871717 AND `RecordId`=331347) OR (`Id`=65993 AND `TableHash`=4030871717 AND `RecordId`=281049) OR (`Id`=65993 AND `TableHash`=4030871717 AND `RecordId`=60368) OR (`Id`=65993 AND `TableHash`=4030871717 AND `RecordId`=39872) OR (`Id`=65992 AND `TableHash`=4030871717 AND `RecordId`=288833) OR (`Id`=65991 AND `TableHash`=3322146344 AND `RecordId`=266) OR (`Id`=65991 AND `TableHash`=4030871717 AND `RecordId`=815370) OR (`Id`=65991 AND `TableHash`=4030871717 AND `RecordId`=479998) OR (`Id`=65991 AND `TableHash`=4030871717 AND `RecordId`=269119) OR (`Id`=65991 AND `TableHash`=4030871717 AND `RecordId`=10651) OR (`Id`=65991 AND `TableHash`=3689412649 AND `RecordId`=62) OR (`Id`=65989 AND `TableHash`=1163127287 AND `RecordId`=46568) OR (`Id`=65988 AND `TableHash`=3386943305 AND `RecordId`=123339) OR (`Id`=65988 AND `TableHash`=3386291891 AND `RecordId`=119305) OR (`Id`=65983 AND `TableHash`=1187407512 AND `RecordId`=228462) OR (`Id`=65983 AND `TableHash`=3776013982 AND `RecordId`=228462) OR (`Id`=65981 AND `TableHash`=1163127287 AND `RecordId`=71764) OR (`Id`=65981 AND `TableHash`=1163127287 AND `RecordId`=39991) OR (`Id`=65980 AND `TableHash`=4030871717 AND `RecordId`=905295) OR (`Id`=65980 AND `TableHash`=4030871717 AND `RecordId`=892984) OR (`Id`=65980 AND `TableHash`=2120822102 AND `RecordId`=178122) OR (`Id`=65980 AND `TableHash`=2120822102 AND `RecordId`=166497) OR (`Id`=65980 AND `TableHash`=2120822102 AND `RecordId`=162879) OR (`Id`=65979 AND `TableHash`=1163127287 AND `RecordId`=41169) OR (`Id`=65979 AND `TableHash`=1163127287 AND `RecordId`=33852) OR (`Id`=65979 AND `TableHash`=1163127287 AND `RecordId`=21568) OR (`Id`=65979 AND `TableHash`=3322146344 AND `RecordId`=165949) OR (`Id`=65979 AND `TableHash`=3322146344 AND `RecordId`=91552) OR (`Id`=65979 AND `TableHash`=3322146344 AND `RecordId`=91549) OR (`Id`=65979 AND `TableHash`=501138918 AND `RecordId`=21773) OR (`Id`=65979 AND `TableHash`=1720692227 AND `RecordId`=27521) OR (`Id`=65979 AND `TableHash`=3689412649 AND `RecordId`=27961) OR (`Id`=65979 AND `TableHash`=4096770149 AND `RecordId`=20096) OR (`Id`=65979 AND `TableHash`=1187407512 AND `RecordId`=119611) OR (`Id`=65979 AND `TableHash`=3776013982 AND `RecordId`=119611) OR (`Id`=65979 AND `TableHash`=1187407512 AND `RecordId`=119607) OR (`Id`=65979 AND `TableHash`=3776013982 AND `RecordId`=119607) OR (`Id`=65978 AND `TableHash`=1344507586 AND `RecordId`=116401) OR (`Id`=65978 AND `TableHash`=428746933 AND `RecordId`=116401) OR (`Id`=65978 AND `TableHash`=2442913102 AND `RecordId`=116401) OR (`Id`=65978 AND `TableHash`=3865974254 AND `RecordId`=116401) OR (`Id`=65978 AND `TableHash`=3037505077 AND `RecordId`=116401) OR (`Id`=65978 AND `TableHash`=1417785224 AND `RecordId`=116401) OR (`Id`=65976 AND `TableHash`=1163127287 AND `RecordId`=71448) OR (`Id`=65975 AND `TableHash`=312611497 AND `RecordId`=20726) OR (`Id`=65975 AND `TableHash`=312611497 AND `RecordId`=20721) OR (`Id`=65975 AND `TableHash`=312611497 AND `RecordId`=20720) OR (`Id`=65973 AND `TableHash`=1181150530 AND `RecordId`=403396) OR (`Id`=65973 AND `TableHash`=859088734 AND `RecordId`=384877) OR (`Id`=65972 AND `TableHash`=4030871717 AND `RecordId`=895844) OR (`Id`=65972 AND `TableHash`=3386943305 AND `RecordId`=202696) OR (`Id`=65972 AND `TableHash`=3386943305 AND `RecordId`=201728) OR (`Id`=65971 AND `TableHash`=1163127287 AND `RecordId`=48768) OR (`Id`=65970 AND `TableHash`=2202435563 AND `RecordId`=1021176) OR (`Id`=65970 AND `TableHash`=2921112328 AND `RecordId`=474214) OR (`Id`=65970 AND `TableHash`=3108775943 AND `RecordId`=91167) OR (`Id`=65970 AND `TableHash`=3108775943 AND `RecordId`=91136) OR (`Id`=65970 AND `TableHash`=3108775943 AND `RecordId`=91103) OR (`Id`=65970 AND `TableHash`=3108775943 AND `RecordId`=91053) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=178072) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=178071) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177911) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177907) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177905) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177901) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177899) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177895) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177893) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177890) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177889) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177888) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177764) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177763) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177762) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177761) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177760) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177759) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177758) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177757) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177756) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177755) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177754) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177753) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177752) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177751) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177750) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177749) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177748) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177747) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177746) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177745) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177744) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177743) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177742) OR (`Id`=65970 AND `TableHash`=2120822102 AND `RecordId`=177741) OR (`Id`=65970 AND `TableHash`=1255424668 AND `RecordId`=94331) OR (`Id`=65970 AND `TableHash`=1255424668 AND `RecordId`=94330) OR (`Id`=65969 AND `TableHash`=492039028 AND `RecordId`=21677) OR (`Id`=65969 AND `TableHash`=600565378 AND `RecordId`=181149) OR (`Id`=65969 AND `TableHash`=3386943305 AND `RecordId`=121848) OR (`Id`=65968 AND `TableHash`=3386943305 AND `RecordId`=114065) OR (`Id`=65968 AND `TableHash`=3386943305 AND `RecordId`=114062) OR (`Id`=65968 AND `TableHash`=3386943305 AND `RecordId`=102930) OR (`Id`=65968 AND `TableHash`=3386943305 AND `RecordId`=100117) OR (`Id`=65966 AND `TableHash`=1163127287 AND `RecordId`=37549) OR (`Id`=65965 AND `TableHash`=1163127287 AND `RecordId`=14436) OR (`Id`=65964 AND `TableHash`=3386943305 AND `RecordId`=115434) OR (`Id`=65964 AND `TableHash`=3386943305 AND `RecordId`=111230) OR (`Id`=65964 AND `TableHash`=3386943305 AND `RecordId`=109965) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=112699) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=112697) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=110960) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=110959) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=110958) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=108406) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=108154) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=108151) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107486) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107472) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107470) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107442) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107435) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107424) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107422) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107419) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107418) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107417) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107416) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107414) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107413) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107412) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107411) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107410) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107409) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107408) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107406) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107404) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=107393) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=106468) OR (`Id`=65964 AND `TableHash`=3386291891 AND `RecordId`=105410) OR (`Id`=65964 AND `TableHash`=1548466975 AND `RecordId`=12827) OR (`Id`=65962 AND `TableHash`=3322146344 AND `RecordId`=172492) OR (`Id`=65960 AND `TableHash`=1163127287 AND `RecordId`=44317) OR (`Id`=65959 AND `TableHash`=3322146344 AND `RecordId`=199147) OR (`Id`=65959 AND `TableHash`=3322146344 AND `RecordId`=185484) OR (`Id`=65959 AND `TableHash`=1720692227 AND `RecordId`=61222) OR (`Id`=65959 AND `TableHash`=4030871717 AND `RecordId`=343764) OR (`Id`=65959 AND `TableHash`=3689412649 AND `RecordId`=54233) OR (`Id`=65959 AND `TableHash`=3386943305 AND `RecordId`=115452) OR (`Id`=65959 AND `TableHash`=3386943305 AND `RecordId`=111215) OR (`Id`=65959 AND `TableHash`=3386943305 AND `RecordId`=105381) OR (`Id`=65958 AND `TableHash`=1369604944 AND `RecordId`=5712) OR (`Id`=65957 AND `TableHash`=4030871717 AND `RecordId`=479792) OR (`Id`=65957 AND `TableHash`=4030871717 AND `RecordId`=10779) OR (`Id`=65956 AND `TableHash`=3359787322 AND `RecordId`=21412) OR (`Id`=65956 AND `TableHash`=3359787322 AND `RecordId`=21411) OR (`Id`=65956 AND `TableHash`=3359787322 AND `RecordId`=21410) OR (`Id`=65956 AND `TableHash`=3359787322 AND `RecordId`=21409) OR (`Id`=65956 AND `TableHash`=3359787322 AND `RecordId`=21408) OR (`Id`=65956 AND `TableHash`=3359787322 AND `RecordId`=21407) OR (`Id`=65956 AND `TableHash`=3359787322 AND `RecordId`=21406) OR (`Id`=65956 AND `TableHash`=3108775943 AND `RecordId`=94517) OR (`Id`=65956 AND `TableHash`=3108775943 AND `RecordId`=94516) OR (`Id`=65956 AND `TableHash`=3108775943 AND `RecordId`=94515) OR (`Id`=65956 AND `TableHash`=3108775943 AND `RecordId`=94514) OR (`Id`=65956 AND `TableHash`=3108775943 AND `RecordId`=94513) OR (`Id`=65956 AND `TableHash`=3108775943 AND `RecordId`=94512) OR (`Id`=65956 AND `TableHash`=3108775943 AND `RecordId`=94511) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=178079) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=178078) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=178077) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=178076) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=178075) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=178074) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=178073) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=178070) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=178069) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=175034) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=175027) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=175021) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=175015) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=175008) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=175002) OR (`Id`=65956 AND `TableHash`=2120822102 AND `RecordId`=174997) OR (`Id`=65956 AND `TableHash`=2577119682 AND `RecordId`=1445) OR (`Id`=65955 AND `TableHash`=3386943305 AND `RecordId`=201502) OR (`Id`=65955 AND `TableHash`=3386943305 AND `RecordId`=201498) OR (`Id`=65954 AND `TableHash`=2557447376 AND `RecordId`=655518) OR (`Id`=65954 AND `TableHash`=2557447376 AND `RecordId`=655517) OR (`Id`=65954 AND `TableHash`=2557447376 AND `RecordId`=655516) OR (`Id`=65954 AND `TableHash`=2557447376 AND `RecordId`=655515) OR (`Id`=65954 AND `TableHash`=1109793673 AND `RecordId`=34460) OR (`Id`=65954 AND `TableHash`=1109793673 AND `RecordId`=24312) OR (`Id`=65954 AND `TableHash`=1109793673 AND `RecordId`=11769) OR (`Id`=65954 AND `TableHash`=1109793673 AND `RecordId`=11768) OR (`Id`=65954 AND `TableHash`=604774165 AND `RecordId`=29725) OR (`Id`=65951 AND `TableHash`=3205218938 AND `RecordId`=48675) OR (`Id`=65947 AND `TableHash`=1187407512 AND `RecordId`=347944) OR (`Id`=65947 AND `TableHash`=3776013982 AND `RecordId`=347944) OR (`Id`=65947 AND `TableHash`=1187407512 AND `RecordId`=347943) OR (`Id`=65947 AND `TableHash`=3776013982 AND `RecordId`=347943) OR (`Id`=65947 AND `TableHash`=1187407512 AND `RecordId`=1714) OR (`Id`=65947 AND `TableHash`=3776013982 AND `RecordId`=1714) OR (`Id`=65947 AND `TableHash`=3205218938 AND `RecordId`=41865) OR (`Id`=65946 AND `TableHash`=2411028436 AND `RecordId`=8412) OR (`Id`=65946 AND `TableHash`=2411028436 AND `RecordId`=8031) OR (`Id`=65946 AND `TableHash`=1918102339 AND `RecordId`=13316) OR (`Id`=65945 AND `TableHash`=261693969 AND `RecordId`=64850) OR (`Id`=65945 AND `TableHash`=986198281 AND `RecordId`=64850) OR (`Id`=65945 AND `TableHash`=20077728 AND `RecordId`=421530) OR (`Id`=65941 AND `TableHash`=2948698321 AND `RecordId`=285) OR (`Id`=65941 AND `TableHash`=3744420815 AND `RecordId`=285) OR (`Id`=65914 AND `TableHash`=331613093 AND `RecordId`=335621) OR (`Id`=65914 AND `TableHash`=331613093 AND `RecordId`=335620);
INSERT INTO `hotfix_data` (`Id`, `UniqueID`, `TableHash`, `RecordId`, `Status`, `VerifiedBuild`) VALUES
(66164, 3937254089, 1163127287, 71980, 3, 40944),
(66164, 3937254089, 3322146344, 476604, 1, 40944),
(66164, 3937254089, 1720692227, 171381, 1, 40944),
(66164, 3937254089, 1187407512, 361952, 1, 40944),
(66164, 3937254089, 3776013982, 361952, 1, 40944),
(66163, 1864052001, 1163127287, 41339, 3, 40944),
(66160, 177056447, 1089023333, 8590, 2, 40944),
(66160, 177056447, 813076512, 84469, 1, 40944),
(66160, 177056447, 813076512, 84468, 1, 40944),
(66160, 177056447, 813076512, 84467, 1, 40944),
(66160, 177056447, 813076512, 84466, 1, 40944),
(66160, 177056447, 813076512, 84465, 1, 40944),
(66160, 177056447, 813076512, 84464, 1, 40944),
(66160, 177056447, 813076512, 84463, 1, 40944),
(66160, 177056447, 813076512, 84462, 1, 40944),
(66160, 177056447, 813076512, 84461, 1, 40944),
(66160, 177056447, 813076512, 84460, 1, 40944),
(66160, 177056447, 813076512, 84459, 1, 40944),
(66160, 177056447, 813076512, 84458, 1, 40944),
(66160, 177056447, 813076512, 84457, 1, 40944),
(66160, 177056447, 813076512, 84456, 1, 40944),
(66160, 177056447, 813076512, 84455, 1, 40944),
(66160, 177056447, 813076512, 84454, 1, 40944),
(66160, 177056447, 813076512, 84453, 1, 40944),
(66160, 177056447, 813076512, 84452, 1, 40944),
(66160, 177056447, 813076512, 84451, 1, 40944),
(66160, 177056447, 813076512, 84450, 1, 40944),
(66160, 177056447, 813076512, 84449, 1, 40944),
(66160, 177056447, 813076512, 84448, 1, 40944),
(66160, 177056447, 1187407512, 256817, 1, 40944),
(66160, 177056447, 3776013982, 256817, 1, 40944),
(66159, 2162182619, 3322146344, 220895, 1, 40944),
(66159, 2162182619, 3322146344, 220894, 1, 40944),
(66159, 2162182619, 3322146344, 220890, 1, 40944),
(66159, 2162182619, 3322146344, 220887, 1, 40944),
(66159, 2162182619, 3322146344, 220884, 1, 40944),
(66159, 2162182619, 3322146344, 220883, 1, 40944),
(66159, 2162182619, 1627543382, 213674, 1, 40944),
(66159, 2162182619, 1627543382, 213673, 1, 40944),
(66159, 2162182619, 1627543382, 213672, 1, 40944),
(66159, 2162182619, 1627543382, 213671, 1, 40944),
(66159, 2162182619, 1627543382, 213670, 1, 40944),
(66159, 2162182619, 1627543382, 213669, 1, 40944),
(66159, 2162182619, 1627543382, 213668, 1, 40944),
(66159, 2162182619, 1627543382, 213667, 1, 40944),
(66159, 2162182619, 1627543382, 213666, 1, 40944),
(66159, 2162182619, 1627543382, 213665, 1, 40944),
(66159, 2162182619, 1627543382, 213664, 1, 40944),
(66159, 2162182619, 1627543382, 213663, 1, 40944),
(66159, 2162182619, 1187407512, 247692, 1, 40944),
(66159, 2162182619, 3776013982, 247692, 1, 40944),
(66159, 2162182619, 1187407512, 247111, 1, 40944),
(66159, 2162182619, 3776013982, 247111, 1, 40944),
(66159, 2162182619, 1187407512, 247110, 1, 40944),
(66159, 2162182619, 3776013982, 247110, 1, 40944),
(66159, 2162182619, 1187407512, 247104, 1, 40944),
(66159, 2162182619, 3776013982, 247104, 1, 40944),
(66159, 2162182619, 1187407512, 247103, 1, 40944),
(66159, 2162182619, 3776013982, 247103, 1, 40944),
(66159, 2162182619, 1187407512, 247099, 1, 40944),
(66159, 2162182619, 3776013982, 247099, 1, 40944),
(66159, 2162182619, 1187407512, 247096, 1, 40944),
(66159, 2162182619, 3776013982, 247096, 1, 40944),
(66159, 2162182619, 1187407512, 247094, 1, 40944),
(66159, 2162182619, 3776013982, 247094, 1, 40944),
(66159, 2162182619, 1187407512, 247093, 1, 40944),
(66159, 2162182619, 3776013982, 247093, 1, 40944),
(66159, 2162182619, 1187407512, 247092, 1, 40944),
(66159, 2162182619, 3776013982, 247092, 1, 40944),
(66159, 2162182619, 1187407512, 247089, 1, 40944),
(66159, 2162182619, 3776013982, 247089, 1, 40944),
(66159, 2162182619, 1187407512, 247088, 1, 40944),
(66159, 2162182619, 3776013982, 247088, 1, 40944),
(66159, 2162182619, 3479059991, 9040, 1, 40944),
(66159, 2162182619, 3479059991, 9039, 1, 40944),
(66159, 2162182619, 3479059991, 9038, 1, 40944),
(66159, 2162182619, 3479059991, 9037, 1, 40944),
(66159, 2162182619, 3479059991, 9036, 1, 40944),
(66159, 2162182619, 3479059991, 9035, 1, 40944),
(66159, 2162182619, 3479059991, 9034, 1, 40944),
(66159, 2162182619, 3479059991, 9033, 1, 40944),
(66159, 2162182619, 3479059991, 9032, 1, 40944),
(66159, 2162182619, 3479059991, 9031, 1, 40944),
(66159, 2162182619, 3479059991, 9030, 1, 40944),
(66159, 2162182619, 3479059991, 9029, 1, 40944),
(66159, 2162182619, 3479059991, 9028, 1, 40944),
(66159, 2162182619, 3479059991, 9027, 1, 40944),
(66159, 2162182619, 3479059991, 9026, 1, 40944),
(66159, 2162182619, 3479059991, 9025, 1, 40944),
(66159, 2162182619, 3479059991, 9024, 1, 40944),
(66159, 2162182619, 3479059991, 9023, 1, 40944),
(66159, 2162182619, 3479059991, 9022, 1, 40944),
(66159, 2162182619, 3479059991, 9021, 1, 40944),
(66159, 2162182619, 3479059991, 9020, 1, 40944),
(66159, 2162182619, 3479059991, 9019, 1, 40944),
(66159, 2162182619, 3479059991, 9018, 1, 40944),
(66159, 2162182619, 3479059991, 9017, 1, 40944),
(66157, 1266099197, 1163127287, 57736, 3, 40944),
(66157, 1266099197, 1163127287, 57345, 3, 40944),
(66157, 1266099197, 3322146344, 386747, 1, 40944),
(66157, 1266099197, 4030871717, 793985, 1, 40944),
(66154, 2232284312, 3322146344, 480160, 3, 40944),
(66154, 2232284312, 4030871717, 906380, 3, 40944),
(66154, 2232284312, 1187407512, 365452, 3, 40944),
(66154, 2232284312, 3776013982, 365452, 3, 40944),
(66153, 551923662, 1187407512, 228844, 1, 40944),
(66153, 551923662, 3776013982, 228844, 1, 40944),
(66153, 551923662, 1187407512, 227799, 1, 40944),
(66153, 551923662, 3776013982, 227799, 1, 40944),
(66153, 551923662, 1187407512, 227780, 1, 40944),
(66153, 551923662, 3776013982, 227780, 1, 40944),
(66153, 551923662, 3386943305, 120249, 3, 40944),
(66153, 551923662, 3386943305, 119322, 3, 40944),
(66153, 551923662, 3386943305, 119299, 3, 40944),
(66153, 551923662, 3386943305, 119267, 3, 40944),
(66153, 551923662, 3386943305, 118939, 3, 40944),
(66153, 551923662, 3386943305, 118773, 3, 40944),
(66153, 551923662, 3386943305, 118751, 3, 40944),
(66153, 551923662, 3386943305, 118574, 3, 40944),
(66153, 551923662, 3386943305, 118450, 3, 40944),
(66153, 551923662, 3386943305, 118418, 3, 40944),
(66153, 551923662, 3386943305, 118415, 3, 40944),
(66153, 551923662, 3386943305, 118407, 3, 40944),
(66153, 551923662, 3386943305, 118318, 3, 40944),
(66153, 551923662, 3386943305, 118299, 3, 40944),
(66153, 551923662, 3386943305, 118118, 3, 40944),
(66153, 551923662, 3386943305, 118111, 3, 40944),
(66153, 551923662, 3386943305, 118110, 3, 40944),
(66153, 551923662, 3386943305, 118109, 3, 40944),
(66153, 551923662, 3386943305, 118108, 3, 40944),
(66153, 551923662, 3386943305, 118009, 3, 40944),
(66153, 551923662, 3386943305, 117978, 3, 40944),
(66153, 551923662, 3386943305, 117977, 3, 40944),
(66153, 551923662, 3386943305, 117976, 3, 40944),
(66153, 551923662, 3386943305, 117974, 3, 40944),
(66153, 551923662, 3386943305, 117973, 3, 40944),
(66153, 551923662, 3386943305, 117967, 3, 40944),
(66153, 551923662, 3386943305, 117847, 3, 40944),
(66153, 551923662, 3386943305, 117672, 3, 40944),
(66153, 551923662, 3386943305, 117654, 3, 40944),
(66153, 551923662, 3386943305, 117586, 3, 40944),
(66153, 551923662, 3386943305, 117585, 3, 40944),
(66153, 551923662, 3386943305, 13134, 3, 40944),
(66153, 551923662, 3386943305, 13133, 3, 40944),
(66153, 551923662, 3386291891, 117578, 3, 40944),
(66153, 551923662, 3386291891, 116865, 3, 40944),
(66153, 551923662, 3386291891, 116864, 3, 40944),
(66153, 551923662, 3386291891, 116804, 1, 40944),
(66153, 551923662, 3386291891, 116802, 3, 40944),
(66153, 551923662, 3386291891, 116573, 3, 40944),
(66153, 551923662, 3386291891, 116563, 3, 40944),
(66153, 551923662, 3386291891, 116562, 3, 40944),
(66153, 551923662, 3386291891, 116561, 3, 40944),
(66153, 551923662, 3386291891, 116495, 3, 40944),
(66153, 551923662, 3386291891, 116494, 3, 40944),
(66153, 551923662, 3386291891, 116491, 3, 40944),
(66153, 551923662, 3386291891, 116447, 3, 40944),
(66153, 551923662, 3386291891, 116418, 3, 40944),
(66153, 551923662, 3386291891, 116259, 3, 40944),
(66153, 551923662, 3386291891, 116124, 3, 40944),
(66153, 551923662, 3386291891, 116003, 3, 40944),
(66153, 551923662, 3386291891, 116002, 3, 40944),
(66153, 551923662, 3386291891, 115986, 3, 40944),
(66153, 551923662, 3386291891, 115984, 3, 40944),
(66153, 551923662, 3386291891, 115983, 3, 40944),
(66153, 551923662, 3386291891, 115982, 3, 40944),
(66153, 551923662, 3386291891, 115981, 3, 40944),
(66153, 551923662, 3386291891, 115976, 3, 40944),
(66153, 551923662, 3386291891, 115967, 3, 40944),
(66153, 551923662, 3386291891, 115789, 3, 40944),
(66153, 551923662, 3386291891, 115746, 3, 40944),
(66153, 551923662, 3386291891, 115743, 3, 40944),
(66153, 551923662, 3386291891, 115734, 3, 40944),
(66153, 551923662, 3386291891, 115725, 3, 40944),
(66153, 551923662, 3386291891, 115694, 3, 40944),
(66153, 551923662, 3386291891, 115510, 1, 40944),
(66153, 551923662, 3386291891, 115501, 3, 40944),
(66153, 551923662, 3386291891, 115497, 3, 40944),
(66153, 551923662, 3386291891, 115496, 3, 40944),
(66153, 551923662, 3386291891, 115493, 3, 40944),
(66153, 551923662, 3386291891, 115491, 1, 40944),
(66153, 551923662, 3386291891, 115490, 3, 40944),
(66153, 551923662, 3386291891, 115489, 3, 40944),
(66153, 551923662, 3386291891, 115487, 3, 40944),
(66153, 551923662, 3386291891, 115427, 1, 40944),
(66153, 551923662, 3386291891, 115426, 1, 40944),
(66153, 551923662, 3386291891, 115386, 3, 40944),
(66153, 551923662, 3386291891, 115274, 3, 40944),
(66153, 551923662, 3386291891, 115234, 3, 40944),
(66153, 551923662, 3386291891, 115213, 3, 40944),
(66153, 551923662, 3386291891, 115212, 3, 40944),
(66153, 551923662, 3386291891, 115124, 3, 40944),
(66153, 551923662, 3386291891, 115123, 3, 40944),
(66153, 551923662, 3386291891, 115118, 3, 40944),
(66153, 551923662, 3386291891, 115113, 3, 40944),
(66153, 551923662, 3386291891, 115105, 3, 40944),
(66153, 551923662, 3386291891, 115103, 3, 40944),
(66153, 551923662, 3386291891, 115101, 3, 40944),
(66153, 551923662, 3386291891, 115063, 3, 40944),
(66153, 551923662, 3386291891, 115062, 3, 40944),
(66153, 551923662, 3386291891, 115061, 3, 40944),
(66153, 551923662, 3386291891, 115059, 3, 40944),
(66153, 551923662, 3386291891, 115057, 3, 40944),
(66153, 551923662, 3386291891, 115038, 3, 40944),
(66153, 551923662, 3386291891, 115034, 3, 40944),
(66153, 551923662, 3386291891, 115033, 3, 40944),
(66153, 551923662, 3386291891, 115032, 3, 40944),
(66153, 551923662, 3386291891, 115030, 3, 40944),
(66153, 551923662, 3386291891, 115022, 3, 40944),
(66153, 551923662, 3386291891, 115016, 3, 40944),
(66153, 551923662, 3386291891, 115013, 3, 40944),
(66153, 551923662, 3386291891, 115007, 3, 40944),
(66153, 551923662, 3386291891, 114947, 3, 40944),
(66153, 551923662, 3386291891, 114940, 3, 40944),
(66153, 551923662, 3386291891, 114938, 3, 40944),
(66153, 551923662, 3386291891, 114913, 3, 40944),
(66153, 551923662, 3386291891, 114906, 3, 40944),
(66153, 551923662, 3386291891, 114903, 3, 40944),
(66153, 551923662, 3386291891, 114895, 3, 40944),
(66153, 551923662, 3386291891, 114844, 3, 40944),
(66153, 551923662, 3386291891, 114843, 3, 40944),
(66153, 551923662, 3386291891, 114842, 3, 40944),
(66153, 551923662, 3386291891, 114839, 3, 40944),
(66153, 551923662, 3386291891, 114835, 3, 40944),
(66153, 551923662, 3386291891, 114834, 3, 40944),
(66153, 551923662, 3386291891, 114833, 3, 40944),
(66153, 551923662, 3386291891, 114815, 3, 40944),
(66153, 551923662, 3386291891, 114800, 3, 40944),
(66153, 551923662, 3386291891, 114799, 3, 40944),
(66153, 551923662, 3386291891, 114653, 3, 40944),
(66153, 551923662, 3386291891, 114649, 3, 40944),
(66153, 551923662, 3386291891, 114648, 3, 40944),
(66153, 551923662, 3386291891, 114647, 3, 40944),
(66153, 551923662, 3386291891, 114646, 3, 40944),
(66153, 551923662, 3386291891, 114616, 3, 40944),
(66153, 551923662, 3386291891, 114583, 3, 40944),
(66153, 551923662, 3386291891, 114556, 3, 40944),
(66153, 551923662, 3386291891, 114555, 3, 40944),
(66153, 551923662, 3386291891, 114554, 3, 40944),
(66153, 551923662, 3386291891, 114552, 3, 40944),
(66153, 551923662, 3386291891, 114551, 3, 40944),
(66153, 551923662, 3386291891, 114545, 3, 40944),
(66153, 551923662, 3386291891, 114520, 3, 40944),
(66153, 551923662, 3386291891, 114486, 3, 40944),
(66153, 551923662, 3386291891, 114471, 3, 40944),
(66153, 551923662, 3386291891, 114463, 3, 40944),
(66153, 551923662, 3386291891, 114462, 1, 40944),
(66153, 551923662, 3386291891, 114408, 3, 40944),
(66153, 551923662, 3386291891, 114339, 3, 40944),
(66153, 551923662, 3386291891, 114335, 3, 40944);

INSERT INTO `hotfix_data` (`Id`, `UniqueID`, `TableHash`, `RecordId`, `Status`, `VerifiedBuild`) VALUES
(66153, 551923662, 3386291891, 114327, 3, 40944),
(66153, 551923662, 3386291891, 114315, 3, 40944),
(66153, 551923662, 3386291891, 114273, 3, 40944),
(66153, 551923662, 3386291891, 114272, 3, 40944),
(66153, 551923662, 3386291891, 17652, 3, 40944),
(66153, 551923662, 3386291891, 17651, 3, 40944),
(66152, 401777594, 1163127287, 71974, 3, 40944),
(66151, 3809611070, 312611497, 20839, 3, 40944),
(66151, 3809611070, 312611497, 20838, 3, 40944),
(66151, 3809611070, 312611497, 20780, 3, 40944),
(66151, 3809611070, 312611497, 20768, 3, 40944),
(66151, 3809611070, 312611497, 20732, 3, 40944),
(66151, 3809611070, 312611497, 20730, 3, 40944),
(66151, 3809611070, 312611497, 20694, 3, 40944),
(66151, 3809611070, 312611497, 20689, 3, 40944),
(66151, 3809611070, 312611497, 20688, 3, 40944),
(66151, 3809611070, 312611497, 20666, 3, 40944),
(66151, 3809611070, 312611497, 20665, 3, 40944),
(66151, 3809611070, 312611497, 20660, 3, 40944),
(66151, 3809611070, 312611497, 20659, 3, 40944),
(66149, 1523326352, 3386943305, 195106, 3, 40944),
(66148, 3198141673, 20077728, 421940, 3, 40944),
(66147, 2752522391, 1187407512, 362986, 1, 40944),
(66147, 2752522391, 3776013982, 362986, 1, 40944),
(66145, 141474754, 356071576, 2291, 4, 40944),
(66143, 1873012945, 1163127287, 67010, 3, 40944),
(66142, 1501022431, 1163127287, 69080, 3, 40944),
(66141, 2185694015, 1089023333, 12823, 1, 40944),
(66141, 2185694015, 1089023333, 12503, 1, 40944),
(66141, 2185694015, 3322146344, 470710, 1, 40944),
(66141, 2185694015, 3322146344, 469819, 1, 40944),
(66141, 2185694015, 3322146344, 466278, 1, 40944),
(66141, 2185694015, 3322146344, 443445, 1, 40944),
(66141, 2185694015, 3322146344, 443195, 1, 40944),
(66141, 2185694015, 3322146344, 442853, 1, 40944),
(66141, 2185694015, 3322146344, 442539, 1, 40944),
(66141, 2185694015, 3322146344, 442283, 1, 40944),
(66141, 2185694015, 3322146344, 441981, 1, 40944),
(66141, 2185694015, 3322146344, 440946, 1, 40944),
(66141, 2185694015, 3322146344, 439981, 1, 40944),
(66141, 2185694015, 3322146344, 436996, 1, 40944),
(66141, 2185694015, 3322146344, 434017, 1, 40944),
(66141, 2185694015, 3322146344, 433894, 1, 40944),
(66141, 2185694015, 3322146344, 433252, 1, 40944),
(66141, 2185694015, 3322146344, 433196, 1, 40944),
(66141, 2185694015, 3322146344, 428505, 1, 40944),
(66141, 2185694015, 3322146344, 404479, 1, 40944),
(66141, 2185694015, 4030871717, 882432, 1, 40944),
(66137, 1953569626, 3386943305, 120066, 3, 40944),
(66136, 1573195706, 1163127287, 71965, 3, 40944),
(66136, 1573195706, 1163127287, 71964, 3, 40944),
(66136, 1573195706, 1163127287, 67566, 3, 40944),
(66136, 1573195706, 3322146344, 466256, 1, 40944),
(66136, 1573195706, 3322146344, 466253, 1, 40944),
(66136, 1573195706, 4030871717, 882392, 1, 40944),
(66134, 2493775687, 261693969, 60399, 1, 40944),
(66134, 2493775687, 986198281, 60399, 1, 40944),
(66134, 2493775687, 261693969, 60396, 1, 40944),
(66134, 2493775687, 986198281, 60396, 1, 40944),
(66134, 2493775687, 261693969, 60392, 1, 40944),
(66134, 2493775687, 986198281, 60392, 1, 40944),
(66134, 2493775687, 261693969, 60381, 1, 40944),
(66134, 2493775687, 986198281, 60381, 1, 40944),
(66133, 2393824976, 2202435563, 1022281, 1, 40944),
(66133, 2393824976, 2202435563, 1016248, 1, 40944),
(66133, 2393824976, 2921112328, 474530, 1, 40944),
(66133, 2393824976, 2921112328, 472639, 1, 40944),
(66131, 2254506427, 3108775943, 85644, 1, 40944),
(66131, 2254506427, 69094805, 161, 1, 40944),
(66129, 82878197, 1344507586, 176922, 1, 40944),
(66129, 82878197, 428746933, 176922, 3, 40944),
(66129, 82878197, 2442913102, 176922, 1, 40944),
(66129, 82878197, 3865974254, 176922, 1, 40944),
(66129, 82878197, 3037505077, 176922, 3, 40944),
(66129, 82878197, 1417785224, 176922, 3, 40944),
(66129, 82878197, 1344507586, 176921, 1, 40944),
(66129, 82878197, 428746933, 176921, 3, 40944),
(66129, 82878197, 2442913102, 176921, 1, 40944),
(66129, 82878197, 3865974254, 176921, 1, 40944),
(66129, 82878197, 3037505077, 176921, 3, 40944),
(66129, 82878197, 1417785224, 176921, 3, 40944),
(66129, 82878197, 1344507586, 176832, 1, 40944),
(66129, 82878197, 428746933, 176832, 3, 40944),
(66129, 82878197, 2442913102, 176832, 1, 40944),
(66129, 82878197, 3865974254, 176832, 1, 40944),
(66129, 82878197, 3037505077, 176832, 3, 40944),
(66129, 82878197, 1417785224, 176832, 3, 40944),
(66128, 2826577129, 1344507586, 185950, 1, 40944),
(66128, 2826577129, 428746933, 185950, 3, 40944),
(66128, 2826577129, 2442913102, 185950, 1, 40944),
(66128, 2826577129, 3865974254, 185950, 1, 40944),
(66128, 2826577129, 3037505077, 185950, 3, 40944),
(66128, 2826577129, 1417785224, 185950, 3, 40944),
(66128, 2826577129, 1344507586, 185947, 1, 40944),
(66128, 2826577129, 428746933, 185947, 3, 40944),
(66128, 2826577129, 2442913102, 185947, 1, 40944),
(66128, 2826577129, 3865974254, 185947, 1, 40944),
(66128, 2826577129, 3037505077, 185947, 3, 40944),
(66128, 2826577129, 1417785224, 185947, 3, 40944),
(66128, 2826577129, 1344507586, 185946, 1, 40944),
(66128, 2826577129, 428746933, 185946, 3, 40944),
(66128, 2826577129, 2442913102, 185946, 1, 40944),
(66128, 2826577129, 3865974254, 185946, 1, 40944),
(66128, 2826577129, 3037505077, 185946, 3, 40944),
(66128, 2826577129, 1417785224, 185946, 3, 40944),
(66126, 710480731, 312611497, 21052, 3, 40944),
(66126, 710480731, 312611497, 21051, 3, 40944),
(66126, 710480731, 312611497, 21050, 3, 40944),
(66126, 710480731, 312611497, 21049, 3, 40944),
(66126, 710480731, 312611497, 20654, 2, 40944),
(66126, 710480731, 312611497, 20407, 3, 40944),
(66126, 710480731, 312611497, 20373, 3, 40944),
(66126, 710480731, 312611497, 20319, 3, 40944),
(66126, 710480731, 312611497, 20230, 3, 40944),
(66126, 710480731, 312611497, 20221, 3, 40944),
(66126, 710480731, 312611497, 19850, 3, 40944),
(66126, 710480731, 312611497, 19768, 2, 40944),
(66126, 710480731, 312611497, 19589, 3, 40944),
(66126, 710480731, 312611497, 19527, 3, 40944),
(66126, 710480731, 312611497, 19515, 2, 40944),
(66126, 710480731, 312611497, 19514, 2, 40944),
(66126, 710480731, 312611497, 19491, 3, 40944),
(66126, 710480731, 1163127287, 71962, 3, 40944),
(66126, 710480731, 1163127287, 59746, 3, 40944),
(66124, 2555569290, 3322146344, 399210, 1, 40944),
(66124, 2555569290, 3322146344, 398349, 1, 40944),
(66124, 2555569290, 3322146344, 387476, 1, 40944),
(66124, 2555569290, 3322146344, 361592, 1, 40944),
(66124, 2555569290, 3322146344, 347465, 1, 40944),
(66124, 2555569290, 3322146344, 338383, 1, 40944),
(66124, 2555569290, 3322146344, 244146, 1, 40944),
(66124, 2555569290, 3322146344, 240717, 1, 40944),
(66124, 2555569290, 3322146344, 239468, 1, 40944),
(66124, 2555569290, 3322146344, 206447, 1, 40944),
(66124, 2555569290, 3322146344, 176741, 1, 40944),
(66124, 2555569290, 3322146344, 158326, 1, 40944),
(66124, 2555569290, 3322146344, 129003, 1, 40944),
(66124, 2555569290, 3322146344, 103578, 1, 40944),
(66124, 2555569290, 3322146344, 90408, 1, 40944),
(66124, 2555569290, 3322146344, 82262, 1, 40944),
(66124, 2555569290, 3322146344, 59320, 1, 40944),
(66124, 2555569290, 3322146344, 49191, 1, 40944),
(66124, 2555569290, 3322146344, 49011, 1, 40944),
(66124, 2555569290, 3322146344, 40524, 1, 40944),
(66124, 2555569290, 3322146344, 39830, 1, 40944),
(66124, 2555569290, 3322146344, 32568, 1, 40944),
(66124, 2555569290, 3322146344, 18143, 1, 40944),
(66124, 2555569290, 3322146344, 18141, 1, 40944),
(66124, 2555569290, 3322146344, 14100, 1, 40944),
(66124, 2555569290, 3322146344, 11746, 1, 40944),
(66124, 2555569290, 3322146344, 8941, 1, 40944),
(66124, 2555569290, 3322146344, 8922, 1, 40944),
(66124, 2555569290, 3322146344, 2380, 1, 40944),
(66124, 2555569290, 3502494094, 1186, 1, 40944),
(66121, 2519253612, 813076512, 84443, 1, 40944),
(66121, 2519253612, 813076512, 84442, 1, 40944),
(66118, 1294728212, 813076512, 84441, 1, 40944),
(66115, 2749017511, 3108775943, 94796, 3, 40944),
(66115, 2749017511, 2246024846, 683, 1, 40944),
(66113, 8960084, 4030871717, 369676, 1, 40944),
(66113, 8960084, 680438657, 29443, 2, 40944),
(66113, 8960084, 1187407512, 243328, 1, 40944),
(66113, 8960084, 3776013982, 243328, 1, 40944),
(66112, 1497136483, 1163127287, 71952, 3, 40944),
(66112, 1497136483, 1163127287, 69409, 3, 40944),
(66112, 1497136483, 3322146344, 479781, 1, 40944),
(66112, 1497136483, 4030871717, 905674, 1, 40944),
(66111, 841871639, 331613093, 369145, 3, 40944),
(66109, 2416328880, 3108775943, 94998, 3, 40944),
(66109, 2416328880, 2120822102, 178500, 1, 40944),
(66109, 2416328880, 2120822102, 178499, 1, 40944),
(66109, 2416328880, 2120822102, 178498, 1, 40944),
(66109, 2416328880, 2120822102, 178497, 1, 40944),
(66109, 2416328880, 2120822102, 178496, 1, 40944),
(66109, 2416328880, 2120822102, 178495, 1, 40944),
(66109, 2416328880, 2120822102, 178494, 1, 40944),
(66109, 2416328880, 2120822102, 178493, 1, 40944),
(66109, 2416328880, 2120822102, 178492, 1, 40944),
(66109, 2416328880, 2120822102, 178491, 1, 40944),
(66109, 2416328880, 2120822102, 178490, 1, 40944),
(66109, 2416328880, 2120822102, 178489, 1, 40944),
(66109, 2416328880, 2120822102, 178488, 1, 40944),
(66109, 2416328880, 2120822102, 178487, 1, 40944),
(66109, 2416328880, 2120822102, 178475, 2, 40944),
(66109, 2416328880, 2120822102, 176083, 1, 40944),
(66109, 2416328880, 2120822102, 176082, 1, 40944),
(66109, 2416328880, 2120822102, 174511, 1, 40944),
(66109, 2416328880, 2120822102, 174279, 1, 40944),
(66109, 2416328880, 2120822102, 174278, 1, 40944),
(66109, 2416328880, 35137211, 215514, 3, 40944),
(66109, 2416328880, 35137211, 215513, 1, 40944),
(66109, 2416328880, 35137211, 215512, 1, 40944),
(66109, 2416328880, 35137211, 215511, 1, 40944),
(66108, 2461928303, 1163127287, 49170, 3, 40944),
(66105, 77629041, 1344507586, 187935, 1, 40944),
(66105, 77629041, 428746933, 187935, 3, 40944),
(66105, 77629041, 2442913102, 187935, 1, 40944),
(66105, 77629041, 3865974254, 187935, 1, 40944),
(66105, 77629041, 3037505077, 187935, 3, 40944),
(66105, 77629041, 1417785224, 187935, 3, 40944),
(66102, 2855320955, 312611497, 20180, 3, 40944),
(66102, 2855320955, 1163127287, 65231, 3, 40944),
(66102, 2855320955, 4030871717, 880680, 2, 40944),
(66102, 2855320955, 4030871717, 845047, 1, 40944),
(66099, 4165447115, 3386291891, 177398, 3, 40944),
(66098, 4250023985, 3205218938, 44300, 1, 40944),
(66098, 4250023985, 3205218938, 44299, 1, 40944),
(66098, 4250023985, 3205218938, 44284, 1, 40944),
(66098, 4250023985, 3205218938, 44283, 1, 40944),
(66097, 3301293240, 1821637041, 3188, 1, 40944),
(66095, 401422367, 4030871717, 906096, 1, 40944),
(66095, 401422367, 4030871717, 897551, 1, 40944),
(66095, 401422367, 4030871717, 897550, 1, 40944),
(66094, 3796749020, 3322146344, 87092, 1, 40944),
(66094, 3796749020, 1344507586, 188152, 1, 40944),
(66094, 3796749020, 428746933, 188152, 3, 40944),
(66094, 3796749020, 2442913102, 188152, 1, 40944),
(66094, 3796749020, 3865974254, 188152, 1, 40944),
(66094, 3796749020, 3037505077, 188152, 3, 40944),
(66094, 3796749020, 1417785224, 188152, 3, 40944),
(66093, 3631042235, 3764692828, 272691, 2, 40944),
(66093, 3631042235, 1187407512, 53385, 1, 40944),
(66093, 3631042235, 3776013982, 53385, 1, 40944),
(66092, 2375838530, 4030871717, 839924, 1, 40944),
(66091, 3563028400, 261693969, 62694, 1, 40944),
(66091, 3563028400, 986198281, 62694, 1, 40944),
(66091, 3563028400, 261693969, 62693, 1, 40944),
(66091, 3563028400, 986198281, 62693, 1, 40944),
(66091, 3563028400, 261693969, 62692, 1, 40944),
(66091, 3563028400, 986198281, 62692, 1, 40944),
(66091, 3563028400, 261693969, 62691, 1, 40944),
(66091, 3563028400, 986198281, 62691, 1, 40944),
(66088, 1139088392, 1163127287, 71781, 3, 40944),
(66088, 1139088392, 1163127287, 65085, 3, 40944),
(66088, 1139088392, 1163127287, 37795, 3, 40944),
(66087, 3922816566, 3108775943, 94798, 3, 40944),
(66087, 3922816566, 3108775943, 94797, 3, 40944),
(66087, 3922816566, 3108775943, 94795, 3, 40944),
(66086, 327956863, 331613093, 346046, 3, 40944),
(66086, 327956863, 331613093, 346045, 3, 40944),
(66086, 327956863, 3571931810, 24353, 3, 40944),
(66086, 327956863, 3571931810, 17863, 3, 40944),
(66086, 327956863, 1225579890, 2591, 3, 40944),
(66086, 327956863, 1225579890, 2590, 3, 40944),
(66086, 327956863, 1548466975, 22040, 3, 40944),
(66085, 1759100649, 345681529, 133055, 1, 40944),
(66085, 1759100649, 345681529, 133054, 1, 40944),
(66085, 1759100649, 345681529, 133053, 1, 40944),
(66085, 1759100649, 345681529, 133052, 1, 40944),
(66083, 1624867121, 1163127287, 71757, 3, 40944);

INSERT INTO `hotfix_data` (`Id`, `UniqueID`, `TableHash`, `RecordId`, `Status`, `VerifiedBuild`) VALUES
(66083, 1624867121, 1163127287, 10352, 3, 40944),
(66080, 3660436127, 331613093, 369216, 3, 40944),
(66077, 4126785387, 1163127287, 71898, 3, 40944),
(66077, 4126785387, 1163127287, 67364, 3, 40944),
(66075, 229599810, 3664936999, 18167, 1, 40944),
(66075, 229599810, 666345498, 337514, 1, 40944),
(66075, 229599810, 666345498, 337512, 1, 40944),
(66075, 229599810, 666345498, 277583, 1, 40944),
(66075, 229599810, 3425193231, 290351, 2, 40944),
(66075, 229599810, 4146370265, 98678, 1, 40944),
(66075, 229599810, 3322146344, 404541, 1, 40944),
(66075, 229599810, 3322146344, 382485, 1, 40944),
(66075, 229599810, 3322146344, 382484, 1, 40944),
(66075, 229599810, 4030871717, 905972, 1, 40944),
(66075, 229599810, 4030871717, 875244, 1, 40944),
(66075, 229599810, 4030871717, 869249, 2, 40944),
(66075, 229599810, 4030871717, 869248, 1, 40944),
(66075, 229599810, 4030871717, 867891, 1, 40944),
(66075, 229599810, 4030871717, 834692, 1, 40944),
(66075, 229599810, 4030871717, 834688, 1, 40944),
(66075, 229599810, 4030871717, 823351, 2, 40944),
(66075, 229599810, 4030871717, 823344, 2, 40944),
(66075, 229599810, 4030871717, 823342, 1, 40944),
(66075, 229599810, 4030871717, 786826, 1, 40944),
(66075, 229599810, 4030871717, 786825, 1, 40944),
(66075, 229599810, 4030871717, 786824, 1, 40944),
(66075, 229599810, 4030871717, 786815, 1, 40944),
(66075, 229599810, 4030871717, 786808, 1, 40944),
(66075, 229599810, 4030871717, 786807, 1, 40944),
(66075, 229599810, 4030871717, 786806, 1, 40944),
(66075, 229599810, 1627543382, 213643, 2, 40944),
(66075, 229599810, 1627543382, 213642, 1, 40944),
(66075, 229599810, 1187407512, 329902, 1, 40944),
(66075, 229599810, 3776013982, 329902, 1, 40944),
(66075, 229599810, 1187407512, 307934, 1, 40944),
(66075, 229599810, 3776013982, 307934, 1, 40944),
(66075, 229599810, 1187407512, 307480, 1, 40944),
(66075, 229599810, 3776013982, 307480, 1, 40944),
(66075, 229599810, 3108775943, 73006, 1, 40944),
(66075, 229599810, 3108775943, 73005, 1, 40944),
(66075, 229599810, 3386943305, 175271, 3, 40944),
(66075, 229599810, 3386291891, 157891, 3, 40944),
(66075, 229599810, 3386291891, 157884, 3, 40944),
(66073, 2746501151, 1163127287, 71894, 3, 40944),
(66073, 2746501151, 3322146344, 474186, 1, 40944),
(66073, 2746501151, 2120822102, 178369, 1, 40944),
(66073, 2746501151, 2120822102, 178368, 2, 40944),
(66073, 2746501151, 2120822102, 178367, 2, 40944),
(66072, 3557229364, 2948698321, 354, 1, 40944),
(66072, 3557229364, 3744420815, 354, 1, 40944),
(66071, 2784769868, 261693969, 65169, 3, 40944),
(66071, 2784769868, 986198281, 65169, 1, 40944),
(66071, 2784769868, 261693969, 65168, 3, 40944),
(66071, 2784769868, 986198281, 65168, 1, 40944),
(66071, 2784769868, 261693969, 65165, 1, 40944),
(66071, 2784769868, 986198281, 65165, 1, 40944),
(66071, 2784769868, 261693969, 65157, 3, 40944),
(66071, 2784769868, 986198281, 65157, 1, 40944),
(66071, 2784769868, 261693969, 65147, 3, 40944),
(66071, 2784769868, 986198281, 65147, 1, 40944),
(66071, 2784769868, 261693969, 61058, 3, 40944),
(66071, 2784769868, 986198281, 61058, 1, 40944),
(66071, 2784769868, 261693969, 61057, 3, 40944),
(66071, 2784769868, 986198281, 61057, 1, 40944),
(66071, 2784769868, 261693969, 60111, 1, 40944),
(66071, 2784769868, 986198281, 60111, 1, 40944),
(66071, 2784769868, 261693969, 60110, 1, 40944),
(66071, 2784769868, 986198281, 60110, 1, 40944),
(66071, 2784769868, 261693969, 59919, 3, 40944),
(66071, 2784769868, 986198281, 59919, 1, 40944),
(66071, 2784769868, 261693969, 59325, 3, 40944),
(66071, 2784769868, 986198281, 59325, 1, 40944),
(66071, 2784769868, 261693969, 58797, 3, 40944),
(66071, 2784769868, 986198281, 58797, 1, 40944),
(66066, 1591687524, 4033975491, 439711, 1, 40944),
(66066, 1591687524, 4033975491, 439689, 1, 40944),
(66066, 1591687524, 4033975491, 439644, 1, 40944),
(66066, 1591687524, 4030871717, 905876, 1, 40944),
(66066, 1591687524, 4030871717, 905875, 1, 40944),
(66066, 1591687524, 4030871717, 905872, 1, 40944),
(66066, 1591687524, 4030871717, 895695, 1, 40944),
(66066, 1591687524, 4030871717, 891440, 1, 40944),
(66066, 1591687524, 4030871717, 891438, 1, 40944),
(66066, 1591687524, 4030871717, 882994, 1, 40944),
(66066, 1591687524, 4030871717, 882993, 1, 40944),
(66066, 1591687524, 4030871717, 874876, 1, 40944),
(66059, 1718821330, 1255424668, 94390, 1, 40944),
(66059, 1718821330, 1255424668, 94389, 1, 40944),
(66059, 1718821330, 1255424668, 94388, 1, 40944),
(66059, 1718821330, 1255424668, 93811, 1, 40944),
(66059, 1718821330, 1255424668, 93810, 1, 40944),
(66059, 1718821330, 4012104832, 52681, 2, 40944),
(66059, 1718821330, 4012104832, 49421, 1, 40944),
(66052, 613629638, 1344507586, 151806, 1, 40944),
(66052, 613629638, 428746933, 151806, 1, 40944),
(66052, 613629638, 2442913102, 151806, 1, 40944),
(66052, 613629638, 3865974254, 151806, 1, 40944),
(66052, 613629638, 3037505077, 151806, 3, 40944),
(66052, 613629638, 1417785224, 151806, 1, 40944),
(66052, 613629638, 1344507586, 151804, 1, 40944),
(66052, 613629638, 428746933, 151804, 1, 40944),
(66052, 613629638, 2442913102, 151804, 1, 40944),
(66052, 613629638, 3865974254, 151804, 1, 40944),
(66052, 613629638, 3037505077, 151804, 3, 40944),
(66052, 613629638, 1417785224, 151804, 1, 40944),
(66052, 613629638, 1344507586, 151792, 1, 40944),
(66052, 613629638, 428746933, 151792, 1, 40944),
(66052, 613629638, 2442913102, 151792, 1, 40944),
(66052, 613629638, 3865974254, 151792, 1, 40944),
(66052, 613629638, 3037505077, 151792, 1, 40944),
(66052, 613629638, 1417785224, 151792, 1, 40944),
(66052, 613629638, 1344507586, 151790, 1, 40944),
(66052, 613629638, 428746933, 151790, 1, 40944),
(66052, 613629638, 2442913102, 151790, 1, 40944),
(66052, 613629638, 3865974254, 151790, 1, 40944),
(66052, 613629638, 3037505077, 151790, 1, 40944),
(66052, 613629638, 1417785224, 151790, 1, 40944),
(66052, 613629638, 1344507586, 146306, 3, 40944),
(66052, 613629638, 428746933, 146306, 3, 40944),
(66052, 613629638, 2442913102, 146306, 3, 40944),
(66052, 613629638, 3865974254, 146306, 1, 40944),
(66052, 613629638, 3037505077, 146306, 3, 40944),
(66052, 613629638, 1417785224, 146306, 1, 40944),
(66052, 613629638, 1344507586, 34685, 1, 40944),
(66052, 613629638, 428746933, 34685, 1, 40944),
(66052, 613629638, 2442913102, 34685, 1, 40944),
(66052, 613629638, 3865974254, 34685, 1, 40944),
(66052, 613629638, 3037505077, 34685, 3, 40944),
(66052, 613629638, 1417785224, 34685, 1, 40944),
(66052, 613629638, 1344507586, 34683, 1, 40944),
(66052, 613629638, 428746933, 34683, 1, 40944),
(66052, 613629638, 2442913102, 34683, 1, 40944),
(66052, 613629638, 3865974254, 34683, 1, 40944),
(66052, 613629638, 3037505077, 34683, 3, 40944),
(66052, 613629638, 1417785224, 34683, 1, 40944),
(66052, 613629638, 1344507586, 34087, 1, 40944),
(66052, 613629638, 428746933, 34087, 1, 40944),
(66052, 613629638, 2442913102, 34087, 1, 40944),
(66052, 613629638, 3865974254, 34087, 1, 40944),
(66052, 613629638, 3037505077, 34087, 3, 40944),
(66052, 613629638, 1417785224, 34087, 3, 40944),
(66052, 613629638, 1344507586, 34085, 1, 40944),
(66052, 613629638, 428746933, 34085, 1, 40944),
(66052, 613629638, 2442913102, 34085, 1, 40944),
(66052, 613629638, 3865974254, 34085, 1, 40944),
(66052, 613629638, 3037505077, 34085, 3, 40944),
(66052, 613629638, 1417785224, 34085, 3, 40944),
(66052, 613629638, 1344507586, 33969, 1, 40944),
(66052, 613629638, 428746933, 33969, 1, 40944),
(66052, 613629638, 2442913102, 33969, 1, 40944),
(66052, 613629638, 3865974254, 33969, 1, 40944),
(66052, 613629638, 3037505077, 33969, 3, 40944),
(66052, 613629638, 1417785224, 33969, 1, 40944),
(66052, 613629638, 1344507586, 33968, 1, 40944),
(66052, 613629638, 428746933, 33968, 1, 40944),
(66052, 613629638, 2442913102, 33968, 1, 40944),
(66052, 613629638, 3865974254, 33968, 1, 40944),
(66052, 613629638, 3037505077, 33968, 3, 40944),
(66052, 613629638, 1417785224, 33968, 1, 40944),
(66052, 613629638, 1344507586, 33967, 1, 40944),
(66052, 613629638, 428746933, 33967, 1, 40944),
(66052, 613629638, 2442913102, 33967, 1, 40944),
(66052, 613629638, 3865974254, 33967, 1, 40944),
(66052, 613629638, 3037505077, 33967, 3, 40944),
(66052, 613629638, 1417785224, 33967, 1, 40944),
(66052, 613629638, 1344507586, 33966, 1, 40944),
(66052, 613629638, 428746933, 33966, 1, 40944),
(66052, 613629638, 2442913102, 33966, 1, 40944),
(66052, 613629638, 3865974254, 33966, 1, 40944),
(66052, 613629638, 3037505077, 33966, 3, 40944),
(66052, 613629638, 1417785224, 33966, 1, 40944),
(66052, 613629638, 1344507586, 33868, 1, 40944),
(66052, 613629638, 428746933, 33868, 1, 40944),
(66052, 613629638, 2442913102, 33868, 1, 40944),
(66052, 613629638, 3865974254, 33868, 1, 40944),
(66052, 613629638, 3037505077, 33868, 3, 40944),
(66052, 613629638, 1417785224, 33868, 1, 40944),
(66052, 613629638, 1344507586, 33864, 1, 40944),
(66052, 613629638, 428746933, 33864, 1, 40944),
(66052, 613629638, 2442913102, 33864, 1, 40944),
(66052, 613629638, 3865974254, 33864, 1, 40944),
(66052, 613629638, 3037505077, 33864, 3, 40944),
(66052, 613629638, 1417785224, 33864, 1, 40944),
(66052, 613629638, 1344507586, 33863, 1, 40944),
(66052, 613629638, 428746933, 33863, 1, 40944),
(66052, 613629638, 2442913102, 33863, 1, 40944),
(66052, 613629638, 3865974254, 33863, 1, 40944),
(66052, 613629638, 3037505077, 33863, 3, 40944),
(66052, 613629638, 1417785224, 33863, 1, 40944),
(66052, 613629638, 1344507586, 33862, 1, 40944),
(66052, 613629638, 428746933, 33862, 1, 40944),
(66052, 613629638, 2442913102, 33862, 1, 40944),
(66052, 613629638, 3865974254, 33862, 1, 40944),
(66052, 613629638, 3037505077, 33862, 3, 40944),
(66052, 613629638, 1417785224, 33862, 1, 40944),
(66052, 613629638, 1344507586, 23324, 1, 40944),
(66052, 613629638, 428746933, 23324, 1, 40944),
(66052, 613629638, 2442913102, 23324, 1, 40944),
(66052, 613629638, 3865974254, 23324, 1, 40944),
(66052, 613629638, 3037505077, 23324, 3, 40944),
(66052, 613629638, 1417785224, 23324, 1, 40944),
(66052, 613629638, 1344507586, 21525, 1, 40944),
(66052, 613629638, 428746933, 21525, 1, 40944),
(66052, 613629638, 2442913102, 21525, 1, 40944),
(66052, 613629638, 3865974254, 21525, 1, 40944),
(66052, 613629638, 3037505077, 21525, 3, 40944),
(66052, 613629638, 1417785224, 21525, 1, 40944),
(66052, 613629638, 1344507586, 21524, 1, 40944),
(66052, 613629638, 428746933, 21524, 1, 40944),
(66052, 613629638, 2442913102, 21524, 1, 40944),
(66052, 613629638, 3865974254, 21524, 1, 40944),
(66052, 613629638, 3037505077, 21524, 3, 40944),
(66052, 613629638, 1417785224, 21524, 1, 40944),
(66052, 613629638, 1344507586, 19028, 1, 40944),
(66052, 613629638, 428746933, 19028, 1, 40944),
(66052, 613629638, 2442913102, 19028, 1, 40944),
(66052, 613629638, 3865974254, 19028, 1, 40944),
(66052, 613629638, 3037505077, 19028, 3, 40944),
(66052, 613629638, 1417785224, 19028, 3, 40944),
(66052, 613629638, 1344507586, 6835, 1, 40944),
(66052, 613629638, 428746933, 6835, 1, 40944),
(66052, 613629638, 2442913102, 6835, 1, 40944),
(66052, 613629638, 3865974254, 6835, 1, 40944),
(66052, 613629638, 3037505077, 6835, 3, 40944),
(66052, 613629638, 1417785224, 6835, 3, 40944),
(66052, 613629638, 1344507586, 6833, 1, 40944),
(66052, 613629638, 428746933, 6833, 1, 40944),
(66052, 613629638, 2442913102, 6833, 1, 40944),
(66052, 613629638, 3865974254, 6833, 1, 40944),
(66052, 613629638, 3037505077, 6833, 3, 40944),
(66052, 613629638, 1417785224, 6833, 1, 40944),
(66049, 3783361893, 1344507586, 181321, 1, 40944),
(66049, 3783361893, 428746933, 181321, 1, 40944),
(66049, 3783361893, 2442913102, 181321, 1, 40944),
(66049, 3783361893, 3865974254, 181321, 1, 40944),
(66049, 3783361893, 3037505077, 181321, 3, 40944),
(66049, 3783361893, 1417785224, 181321, 3, 40944),
(66048, 2812578165, 1109793673, 43167, 1, 40944),
(66048, 2812578165, 1109793673, 42756, 1, 40944),
(66048, 2812578165, 1109793673, 42671, 1, 40944),
(66048, 2812578165, 1109793673, 42533, 1, 40944),
(66045, 3041636892, 1548466975, 27672, 1, 40944),
(66044, 3428410731, 501138918, 125560, 1, 40944),
(66044, 3428410731, 813076512, 84346, 1, 40944),
(66044, 3428410731, 813076512, 84345, 1, 40944),
(66044, 3428410731, 813076512, 84344, 1, 40944),
(66044, 3428410731, 1720692227, 171288, 1, 40944),
(66044, 3428410731, 680438657, 61714, 1, 40944),
(66044, 3428410731, 3689412649, 123263, 3, 40944),
(66044, 3428410731, 4096770149, 186908, 1, 40944);

INSERT INTO `hotfix_data` (`Id`, `UniqueID`, `TableHash`, `RecordId`, `Status`, `VerifiedBuild`) VALUES
(66044, 3428410731, 1187407512, 365080, 1, 40944),
(66044, 3428410731, 3776013982, 365080, 1, 40944),
(66043, 3006522451, 1163127287, 17506, 3, 40944),
(66038, 642343737, 4030871717, 818347, 1, 40944),
(66036, 1033600746, 1163127287, 60186, 3, 40944),
(66034, 3951883569, 1089023333, 12157, 2, 40944),
(66034, 3951883569, 1089023333, 168, 2, 40944),
(66034, 3951883569, 3322146344, 392545, 1, 40944),
(66034, 3951883569, 3322146344, 221469, 1, 40944),
(66034, 3951883569, 3322146344, 157418, 1, 40944),
(66034, 3951883569, 3322146344, 137, 1, 40944),
(66034, 3951883569, 1187407512, 317920, 1, 40944),
(66034, 3951883569, 3776013982, 317920, 1, 40944),
(66034, 3951883569, 1187407512, 465, 1, 40944),
(66034, 3951883569, 3776013982, 465, 1, 40944),
(66031, 462382416, 2137612197, 13134, 1, 40944),
(66030, 1690243177, 356071576, 2221, 1, 40944),
(66030, 1690243177, 356071576, 2220, 1, 40944),
(66030, 1690243177, 356071576, 2219, 1, 40944),
(66030, 1690243177, 356071576, 2218, 1, 40944),
(66030, 1690243177, 356071576, 2217, 1, 40944),
(66030, 1690243177, 356071576, 2216, 1, 40944),
(66030, 1690243177, 356071576, 2215, 1, 40944),
(66030, 1690243177, 356071576, 2214, 1, 40944),
(66030, 1690243177, 356071576, 2213, 1, 40944),
(66030, 1690243177, 356071576, 2212, 1, 40944),
(66030, 1690243177, 356071576, 2211, 1, 40944),
(66030, 1690243177, 356071576, 2210, 1, 40944),
(66030, 1690243177, 356071576, 2209, 1, 40944),
(66030, 1690243177, 356071576, 2208, 1, 40944),
(66030, 1690243177, 356071576, 2207, 1, 40944),
(66030, 1690243177, 356071576, 2206, 1, 40944),
(66030, 1690243177, 356071576, 2205, 1, 40944),
(66030, 1690243177, 356071576, 2204, 1, 40944),
(66030, 1690243177, 356071576, 2203, 1, 40944),
(66030, 1690243177, 356071576, 2202, 1, 40944),
(66028, 75023069, 505524148, 49086, 1, 40944),
(66028, 75023069, 505524148, 49085, 1, 40944),
(66028, 75023069, 505524148, 49084, 1, 40944),
(66028, 75023069, 505524148, 49083, 1, 40944),
(66028, 75023069, 505524148, 49082, 1, 40944),
(66028, 75023069, 505524148, 49081, 1, 40944),
(66028, 75023069, 505524148, 49080, 1, 40944),
(66028, 75023069, 505524148, 49079, 1, 40944),
(66028, 75023069, 505524148, 49078, 1, 40944),
(66028, 75023069, 505524148, 49077, 1, 40944),
(66028, 75023069, 505524148, 49076, 1, 40944),
(66028, 75023069, 505524148, 49075, 1, 40944),
(66028, 75023069, 505524148, 49074, 1, 40944),
(66028, 75023069, 505524148, 49073, 1, 40944),
(66028, 75023069, 505524148, 49072, 1, 40944),
(66028, 75023069, 505524148, 49071, 1, 40944),
(66028, 75023069, 356071576, 2289, 1, 40944),
(66028, 75023069, 356071576, 2287, 1, 40944),
(66028, 75023069, 356071576, 2283, 1, 40944),
(66028, 75023069, 356071576, 2281, 1, 40944),
(66028, 75023069, 356071576, 2277, 1, 40944),
(66028, 75023069, 356071576, 2275, 1, 40944),
(66028, 75023069, 356071576, 2271, 1, 40944),
(66028, 75023069, 356071576, 2269, 1, 40944),
(66028, 75023069, 3205218938, 44172, 1, 40944),
(66028, 75023069, 3205218938, 40887, 1, 40944),
(66028, 75023069, 3205218938, 40885, 1, 40944),
(66026, 2130087415, 1187407512, 357407, 1, 40944),
(66026, 2130087415, 3776013982, 357407, 1, 40944),
(66026, 2130087415, 1187407512, 357406, 1, 40944),
(66026, 2130087415, 3776013982, 357406, 1, 40944),
(66026, 2130087415, 1187407512, 357405, 1, 40944),
(66026, 2130087415, 3776013982, 357405, 1, 40944),
(66026, 2130087415, 1187407512, 356631, 1, 40944),
(66026, 2130087415, 3776013982, 356631, 1, 40944),
(66026, 2130087415, 1187407512, 328923, 1, 40944),
(66026, 2130087415, 3776013982, 328923, 1, 40944),
(66026, 2130087415, 1187407512, 101546, 1, 40944),
(66026, 2130087415, 3776013982, 101546, 1, 40944),
(66026, 2130087415, 1344507586, 188220, 1, 40944),
(66026, 2130087415, 428746933, 188220, 3, 40944),
(66026, 2130087415, 2442913102, 188220, 1, 40944),
(66026, 2130087415, 3865974254, 188220, 1, 40944),
(66026, 2130087415, 3037505077, 188220, 3, 40944),
(66026, 2130087415, 1417785224, 188220, 3, 40944),
(66024, 4088474189, 3108775943, 94883, 3, 40944),
(66024, 4088474189, 3108775943, 87365, 1, 40944),
(66024, 4088474189, 3108775943, 86416, 3, 40944),
(66024, 4088474189, 2120822102, 153266, 1, 40944),
(66024, 4088474189, 2120822102, 153265, 2, 40944),
(66024, 4088474189, 2246024846, 693, 1, 40944),
(66024, 4088474189, 3538824359, 14775, 1, 40944),
(66024, 4088474189, 3538824359, 14752, 1, 40944),
(66024, 4088474189, 3538824359, 14682, 1, 40944),
(66024, 4088474189, 3538824359, 14351, 1, 40944),
(66023, 1349619636, 1163127287, 69274, 3, 40944),
(66023, 1349619636, 1163127287, 69002, 3, 40944),
(66012, 3874179664, 1344507586, 187900, 1, 40944),
(66012, 3874179664, 428746933, 187900, 3, 40944),
(66012, 3874179664, 2442913102, 187900, 1, 40944),
(66012, 3874179664, 3865974254, 187900, 1, 40944),
(66012, 3874179664, 3037505077, 187900, 3, 40944),
(66012, 3874179664, 1417785224, 187900, 3, 40944),
(66012, 3874179664, 1344507586, 187899, 1, 40944),
(66012, 3874179664, 428746933, 187899, 3, 40944),
(66012, 3874179664, 2442913102, 187899, 1, 40944),
(66012, 3874179664, 3865974254, 187899, 1, 40944),
(66012, 3874179664, 3037505077, 187899, 3, 40944),
(66012, 3874179664, 1417785224, 187899, 3, 40944),
(66012, 3874179664, 1344507586, 187898, 1, 40944),
(66012, 3874179664, 428746933, 187898, 3, 40944),
(66012, 3874179664, 2442913102, 187898, 1, 40944),
(66012, 3874179664, 3865974254, 187898, 1, 40944),
(66012, 3874179664, 3037505077, 187898, 3, 40944),
(66012, 3874179664, 1417785224, 187898, 3, 40944),
(66012, 3874179664, 1344507586, 187897, 1, 40944),
(66012, 3874179664, 428746933, 187897, 3, 40944),
(66012, 3874179664, 2442913102, 187897, 1, 40944),
(66012, 3874179664, 3865974254, 187897, 1, 40944),
(66012, 3874179664, 3037505077, 187897, 3, 40944),
(66012, 3874179664, 1417785224, 187897, 3, 40944),
(66012, 3874179664, 1344507586, 187896, 1, 40944),
(66012, 3874179664, 428746933, 187896, 3, 40944),
(66012, 3874179664, 2442913102, 187896, 1, 40944),
(66012, 3874179664, 3865974254, 187896, 1, 40944),
(66012, 3874179664, 3037505077, 187896, 3, 40944),
(66012, 3874179664, 1417785224, 187896, 3, 40944),
(66012, 3874179664, 1344507586, 187895, 1, 40944),
(66012, 3874179664, 428746933, 187895, 3, 40944),
(66012, 3874179664, 2442913102, 187895, 1, 40944),
(66012, 3874179664, 3865974254, 187895, 1, 40944),
(66012, 3874179664, 3037505077, 187895, 3, 40944),
(66012, 3874179664, 1417785224, 187895, 3, 40944),
(66012, 3874179664, 1344507586, 187875, 1, 40944),
(66012, 3874179664, 428746933, 187875, 3, 40944),
(66012, 3874179664, 2442913102, 187875, 1, 40944),
(66012, 3874179664, 3865974254, 187875, 1, 40944),
(66012, 3874179664, 3037505077, 187875, 3, 40944),
(66012, 3874179664, 1417785224, 187875, 3, 40944),
(66012, 3874179664, 1344507586, 187869, 1, 40944),
(66012, 3874179664, 428746933, 187869, 3, 40944),
(66012, 3874179664, 2442913102, 187869, 1, 40944),
(66012, 3874179664, 3865974254, 187869, 1, 40944),
(66012, 3874179664, 3037505077, 187869, 3, 40944),
(66012, 3874179664, 1417785224, 187869, 3, 40944),
(66012, 3874179664, 1344507586, 150746, 1, 40944),
(66012, 3874179664, 428746933, 150746, 3, 40944),
(66012, 3874179664, 2442913102, 150746, 1, 40944),
(66012, 3874179664, 3865974254, 150746, 1, 40944),
(66012, 3874179664, 3037505077, 150746, 3, 40944),
(66012, 3874179664, 1417785224, 150746, 3, 40944),
(66012, 3874179664, 1344507586, 150745, 1, 40944),
(66012, 3874179664, 428746933, 150745, 3, 40944),
(66012, 3874179664, 2442913102, 150745, 1, 40944),
(66012, 3874179664, 3865974254, 150745, 1, 40944),
(66012, 3874179664, 3037505077, 150745, 3, 40944),
(66012, 3874179664, 1417785224, 150745, 3, 40944),
(66012, 3874179664, 1344507586, 150744, 1, 40944),
(66012, 3874179664, 428746933, 150744, 3, 40944),
(66012, 3874179664, 2442913102, 150744, 1, 40944),
(66012, 3874179664, 3865974254, 150744, 1, 40944),
(66012, 3874179664, 3037505077, 150744, 3, 40944),
(66012, 3874179664, 1417785224, 150744, 3, 40944),
(66012, 3874179664, 1344507586, 150743, 1, 40944),
(66012, 3874179664, 428746933, 150743, 3, 40944),
(66012, 3874179664, 2442913102, 150743, 1, 40944),
(66012, 3874179664, 3865974254, 150743, 1, 40944),
(66012, 3874179664, 3037505077, 150743, 3, 40944),
(66012, 3874179664, 1417785224, 150743, 3, 40944),
(66011, 754416993, 356071576, 2178, 1, 40944),
(66011, 754416993, 3108775943, 85912, 1, 40944),
(66011, 754416993, 3108775943, 85910, 1, 40944),
(66011, 754416993, 3108775943, 85909, 1, 40944),
(66011, 754416993, 3108775943, 85692, 1, 40944),
(66011, 754416993, 2120822102, 178172, 1, 40944),
(66011, 754416993, 2120822102, 178171, 1, 40944),
(66011, 754416993, 2120822102, 178170, 1, 40944),
(66011, 754416993, 2120822102, 178169, 1, 40944),
(66011, 754416993, 2120822102, 178168, 1, 40944),
(66011, 754416993, 2120822102, 178167, 1, 40944),
(66011, 754416993, 2120822102, 178166, 1, 40944),
(66011, 754416993, 2120822102, 178165, 1, 40944),
(66011, 754416993, 2120822102, 178164, 1, 40944),
(66011, 754416993, 2120822102, 178163, 1, 40944),
(66011, 754416993, 2120822102, 178162, 1, 40944),
(66011, 754416993, 2120822102, 178161, 1, 40944),
(66005, 3722349725, 1163127287, 69843, 3, 40944),
(66005, 3722349725, 3322146344, 471340, 1, 40944),
(66005, 3722349725, 4030871717, 905454, 2, 40944),
(66005, 3722349725, 4030871717, 898199, 2, 40944),
(66003, 2089756497, 3179597154, 1756, 1, 40944),
(66002, 2093930003, 4096770149, 9518, 1, 40944),
(66000, 4294238832, 1163127287, 69881, 3, 40944),
(66000, 4294238832, 3322146344, 472345, 1, 40944),
(65999, 469002763, 1163127287, 71780, 3, 40944),
(65999, 469002763, 3322146344, 444258, 1, 40944),
(65998, 2828302837, 3322146344, 479643, 1, 40944),
(65998, 2828302837, 501138918, 125558, 1, 40944),
(65998, 2828302837, 813076512, 84323, 1, 40944),
(65998, 2828302837, 813076512, 84322, 1, 40944),
(65998, 2828302837, 813076512, 84321, 1, 40944),
(65998, 2828302837, 1720692227, 171235, 1, 40944),
(65998, 2828302837, 4030871717, 905418, 1, 40944),
(65998, 2828302837, 4030871717, 905417, 1, 40944),
(65998, 2828302837, 680438657, 61709, 1, 40944),
(65998, 2828302837, 3689412649, 123205, 3, 40944),
(65998, 2828302837, 4096770149, 186896, 1, 40944),
(65998, 2828302837, 1187407512, 364944, 1, 40944),
(65998, 2828302837, 3776013982, 364944, 1, 40944),
(65997, 500714938, 800559195, 1523, 1, 40944),
(65997, 500714938, 800559195, 689, 1, 40944),
(65996, 3964207959, 3689412649, 1791, 1, 40944),
(65996, 3964207959, 3689412649, 1741, 1, 40944),
(65994, 968868000, 3603976684, 16884, 2, 40944),
(65994, 968868000, 3603976684, 16881, 2, 40944),
(65994, 968868000, 3603976684, 16879, 2, 40944),
(65994, 968868000, 3603976684, 16877, 2, 40944),
(65994, 968868000, 3603976684, 16875, 2, 40944),
(65994, 968868000, 3603976684, 16873, 2, 40944),
(65994, 968868000, 3603976684, 16871, 2, 40944),
(65994, 968868000, 3603976684, 16869, 2, 40944),
(65994, 968868000, 3603976684, 16867, 2, 40944),
(65994, 968868000, 3603976684, 16865, 2, 40944),
(65994, 968868000, 3603976684, 16864, 2, 40944),
(65994, 968868000, 3603976684, 16861, 2, 40944),
(65994, 968868000, 3603976684, 16859, 2, 40944),
(65994, 968868000, 3603976684, 16857, 2, 40944),
(65994, 968868000, 3603976684, 16855, 2, 40944),
(65994, 968868000, 3603976684, 16853, 2, 40944),
(65994, 968868000, 3603976684, 16851, 2, 40944),
(65994, 968868000, 3603976684, 16849, 2, 40944),
(65994, 968868000, 3603976684, 16847, 2, 40944),
(65994, 968868000, 3603976684, 16845, 2, 40944),
(65994, 968868000, 3204974385, 550, 2, 40944),
(65994, 968868000, 3204974385, 547, 2, 40944),
(65994, 968868000, 3204974385, 545, 2, 40944),
(65994, 968868000, 3204974385, 543, 2, 40944),
(65994, 968868000, 3204974385, 541, 2, 40944),
(65994, 968868000, 3204974385, 539, 2, 40944),
(65994, 968868000, 3204974385, 537, 2, 40944),
(65994, 968868000, 3204974385, 535, 2, 40944),
(65994, 968868000, 3204974385, 533, 2, 40944),
(65994, 968868000, 3204974385, 531, 2, 40944),
(65994, 968868000, 3204974385, 530, 2, 40944),
(65994, 968868000, 3204974385, 527, 2, 40944),
(65994, 968868000, 3204974385, 525, 2, 40944),
(65994, 968868000, 3204974385, 523, 2, 40944),
(65994, 968868000, 3204974385, 521, 2, 40944),
(65994, 968868000, 3204974385, 519, 2, 40944),
(65994, 968868000, 3204974385, 517, 2, 40944),
(65994, 968868000, 3204974385, 515, 2, 40944),
(65994, 968868000, 3204974385, 513, 2, 40944),
(65994, 968868000, 3204974385, 511, 2, 40944),
(65993, 3388316683, 4030871717, 815761, 1, 40944);

INSERT INTO `hotfix_data` (`Id`, `UniqueID`, `TableHash`, `RecordId`, `Status`, `VerifiedBuild`) VALUES
(65993, 3388316683, 4030871717, 331347, 1, 40944),
(65993, 3388316683, 4030871717, 281049, 1, 40944),
(65993, 3388316683, 4030871717, 60368, 1, 40944),
(65993, 3388316683, 4030871717, 39872, 1, 40944),
(65992, 3130517079, 4030871717, 288833, 1, 40944),
(65991, 2345210970, 3322146344, 266, 1, 40944),
(65991, 2345210970, 4030871717, 815370, 1, 40944),
(65991, 2345210970, 4030871717, 479998, 1, 40944),
(65991, 2345210970, 4030871717, 269119, 1, 40944),
(65991, 2345210970, 4030871717, 10651, 1, 40944),
(65991, 2345210970, 3689412649, 62, 1, 40944),
(65989, 2216947662, 1163127287, 46568, 3, 40944),
(65988, 3706898688, 3386943305, 123339, 3, 40944),
(65988, 3706898688, 3386291891, 119305, 3, 40944),
(65983, 634596678, 1187407512, 228462, 1, 40944),
(65983, 634596678, 3776013982, 228462, 1, 40944),
(65981, 535941449, 1163127287, 71764, 3, 40944),
(65981, 535941449, 1163127287, 39991, 3, 40944),
(65980, 624957419, 4030871717, 905295, 1, 40944),
(65980, 624957419, 4030871717, 892984, 1, 40944),
(65980, 624957419, 2120822102, 178122, 1, 40944),
(65980, 624957419, 2120822102, 166497, 1, 40944),
(65980, 624957419, 2120822102, 162879, 1, 40944),
(65979, 1795938750, 1163127287, 41169, 3, 40944),
(65979, 1795938750, 1163127287, 33852, 3, 40944),
(65979, 1795938750, 1163127287, 21568, 3, 40944),
(65979, 1795938750, 3322146344, 165949, 1, 40944),
(65979, 1795938750, 3322146344, 91552, 1, 40944),
(65979, 1795938750, 3322146344, 91549, 1, 40944),
(65979, 1795938750, 501138918, 21773, 1, 40944),
(65979, 1795938750, 1720692227, 27521, 2, 40944),
(65979, 1795938750, 3689412649, 27961, 2, 40944),
(65979, 1795938750, 4096770149, 20096, 2, 40944),
(65979, 1795938750, 1187407512, 119611, 1, 40944),
(65979, 1795938750, 3776013982, 119611, 1, 40944),
(65979, 1795938750, 1187407512, 119607, 1, 40944),
(65979, 1795938750, 3776013982, 119607, 1, 40944),
(65978, 2604421420, 1344507586, 116401, 1, 40944),
(65978, 2604421420, 428746933, 116401, 1, 40944),
(65978, 2604421420, 2442913102, 116401, 1, 40944),
(65978, 2604421420, 3865974254, 116401, 1, 40944),
(65978, 2604421420, 3037505077, 116401, 3, 40944),
(65978, 2604421420, 1417785224, 116401, 3, 40944),
(65976, 3171660677, 1163127287, 71448, 3, 40944),
(65975, 175853057, 312611497, 20726, 3, 40944),
(65975, 175853057, 312611497, 20721, 3, 40944),
(65975, 175853057, 312611497, 20720, 3, 40944),
(65973, 1081351660, 1181150530, 403396, 1, 40944),
(65973, 1081351660, 859088734, 384877, 1, 40944),
(65972, 2495618835, 4030871717, 895844, 1, 40944),
(65972, 2495618835, 3386943305, 202696, 3, 40944),
(65972, 2495618835, 3386943305, 201728, 3, 40944),
(65971, 3092049219, 1163127287, 48768, 3, 40944),
(65970, 1320973528, 2202435563, 1021176, 1, 40944),
(65970, 1320973528, 2921112328, 474214, 1, 40944),
(65970, 1320973528, 3108775943, 91167, 3, 40944),
(65970, 1320973528, 3108775943, 91136, 3, 40944),
(65970, 1320973528, 3108775943, 91103, 3, 40944),
(65970, 1320973528, 3108775943, 91053, 3, 40944),
(65970, 1320973528, 2120822102, 178072, 1, 40944),
(65970, 1320973528, 2120822102, 178071, 2, 40944),
(65970, 1320973528, 2120822102, 177911, 1, 40944),
(65970, 1320973528, 2120822102, 177907, 2, 40944),
(65970, 1320973528, 2120822102, 177905, 1, 40944),
(65970, 1320973528, 2120822102, 177901, 2, 40944),
(65970, 1320973528, 2120822102, 177899, 2, 40944),
(65970, 1320973528, 2120822102, 177895, 1, 40944),
(65970, 1320973528, 2120822102, 177893, 2, 40944),
(65970, 1320973528, 2120822102, 177890, 1, 40944),
(65970, 1320973528, 2120822102, 177889, 2, 40944),
(65970, 1320973528, 2120822102, 177888, 1, 40944),
(65970, 1320973528, 2120822102, 177764, 2, 40944),
(65970, 1320973528, 2120822102, 177763, 2, 40944),
(65970, 1320973528, 2120822102, 177762, 2, 40944),
(65970, 1320973528, 2120822102, 177761, 2, 40944),
(65970, 1320973528, 2120822102, 177760, 1, 40944),
(65970, 1320973528, 2120822102, 177759, 1, 40944),
(65970, 1320973528, 2120822102, 177758, 2, 40944),
(65970, 1320973528, 2120822102, 177757, 2, 40944),
(65970, 1320973528, 2120822102, 177756, 2, 40944),
(65970, 1320973528, 2120822102, 177755, 2, 40944),
(65970, 1320973528, 2120822102, 177754, 1, 40944),
(65970, 1320973528, 2120822102, 177753, 1, 40944),
(65970, 1320973528, 2120822102, 177752, 2, 40944),
(65970, 1320973528, 2120822102, 177751, 2, 40944),
(65970, 1320973528, 2120822102, 177750, 2, 40944),
(65970, 1320973528, 2120822102, 177749, 2, 40944),
(65970, 1320973528, 2120822102, 177748, 1, 40944),
(65970, 1320973528, 2120822102, 177747, 1, 40944),
(65970, 1320973528, 2120822102, 177746, 2, 40944),
(65970, 1320973528, 2120822102, 177745, 2, 40944),
(65970, 1320973528, 2120822102, 177744, 2, 40944),
(65970, 1320973528, 2120822102, 177743, 2, 40944),
(65970, 1320973528, 2120822102, 177742, 1, 40944),
(65970, 1320973528, 2120822102, 177741, 1, 40944),
(65970, 1320973528, 1255424668, 94331, 1, 40944),
(65970, 1320973528, 1255424668, 94330, 1, 40944),
(65969, 3623881551, 492039028, 21677, 1, 40944),
(65969, 3623881551, 600565378, 181149, 1, 40944),
(65969, 3623881551, 3386943305, 121848, 1, 40944),
(65968, 3982648318, 3386943305, 114065, 3, 40944),
(65968, 3982648318, 3386943305, 114062, 3, 40944),
(65968, 3982648318, 3386943305, 102930, 3, 40944),
(65968, 3982648318, 3386943305, 100117, 3, 40944),
(65966, 3117583430, 1163127287, 37549, 3, 40944),
(65965, 2714843857, 1163127287, 14436, 3, 40944),
(65964, 2196969506, 3386943305, 115434, 3, 40944),
(65964, 2196969506, 3386943305, 111230, 3, 40944),
(65964, 2196969506, 3386943305, 109965, 3, 40944),
(65964, 2196969506, 3386291891, 112699, 3, 40944),
(65964, 2196969506, 3386291891, 112697, 3, 40944),
(65964, 2196969506, 3386291891, 110960, 3, 40944),
(65964, 2196969506, 3386291891, 110959, 3, 40944),
(65964, 2196969506, 3386291891, 110958, 3, 40944),
(65964, 2196969506, 3386291891, 108406, 3, 40944),
(65964, 2196969506, 3386291891, 108154, 3, 40944),
(65964, 2196969506, 3386291891, 108151, 3, 40944),
(65964, 2196969506, 3386291891, 107486, 3, 40944),
(65964, 2196969506, 3386291891, 107472, 3, 40944),
(65964, 2196969506, 3386291891, 107470, 3, 40944),
(65964, 2196969506, 3386291891, 107442, 3, 40944),
(65964, 2196969506, 3386291891, 107435, 3, 40944),
(65964, 2196969506, 3386291891, 107424, 3, 40944),
(65964, 2196969506, 3386291891, 107422, 3, 40944),
(65964, 2196969506, 3386291891, 107419, 3, 40944),
(65964, 2196969506, 3386291891, 107418, 3, 40944),
(65964, 2196969506, 3386291891, 107417, 3, 40944),
(65964, 2196969506, 3386291891, 107416, 3, 40944),
(65964, 2196969506, 3386291891, 107414, 3, 40944),
(65964, 2196969506, 3386291891, 107413, 3, 40944),
(65964, 2196969506, 3386291891, 107412, 3, 40944),
(65964, 2196969506, 3386291891, 107411, 3, 40944),
(65964, 2196969506, 3386291891, 107410, 3, 40944),
(65964, 2196969506, 3386291891, 107409, 3, 40944),
(65964, 2196969506, 3386291891, 107408, 3, 40944),
(65964, 2196969506, 3386291891, 107406, 3, 40944),
(65964, 2196969506, 3386291891, 107404, 3, 40944),
(65964, 2196969506, 3386291891, 107393, 3, 40944),
(65964, 2196969506, 3386291891, 106468, 3, 40944),
(65964, 2196969506, 3386291891, 105410, 3, 40944),
(65964, 2196969506, 1548466975, 12827, 3, 40944),
(65962, 1438137987, 3322146344, 172492, 1, 40944),
(65960, 1314111455, 1163127287, 44317, 3, 40944),
(65959, 4012089821, 3322146344, 199147, 1, 40944),
(65959, 4012089821, 3322146344, 185484, 1, 40944),
(65959, 4012089821, 1720692227, 61222, 1, 40944),
(65959, 4012089821, 4030871717, 343764, 1, 40944),
(65959, 4012089821, 3689412649, 54233, 1, 40944),
(65959, 4012089821, 3386943305, 115452, 3, 40944),
(65959, 4012089821, 3386943305, 111215, 3, 40944),
(65959, 4012089821, 3386943305, 105381, 3, 40944),
(65958, 2034998623, 1369604944, 5712, 1, 40944),
(65957, 1031969533, 4030871717, 479792, 1, 40944),
(65957, 1031969533, 4030871717, 10779, 1, 40944),
(65956, 1555869970, 3359787322, 21412, 1, 40944),
(65956, 1555869970, 3359787322, 21411, 1, 40944),
(65956, 1555869970, 3359787322, 21410, 1, 40944),
(65956, 1555869970, 3359787322, 21409, 1, 40944),
(65956, 1555869970, 3359787322, 21408, 1, 40944),
(65956, 1555869970, 3359787322, 21407, 1, 40944),
(65956, 1555869970, 3359787322, 21406, 1, 40944),
(65956, 1555869970, 3108775943, 94517, 1, 40944),
(65956, 1555869970, 3108775943, 94516, 1, 40944),
(65956, 1555869970, 3108775943, 94515, 1, 40944),
(65956, 1555869970, 3108775943, 94514, 1, 40944),
(65956, 1555869970, 3108775943, 94513, 1, 40944),
(65956, 1555869970, 3108775943, 94512, 1, 40944),
(65956, 1555869970, 3108775943, 94511, 1, 40944),
(65956, 1555869970, 2120822102, 178079, 1, 40944),
(65956, 1555869970, 2120822102, 178078, 1, 40944),
(65956, 1555869970, 2120822102, 178077, 1, 40944),
(65956, 1555869970, 2120822102, 178076, 1, 40944),
(65956, 1555869970, 2120822102, 178075, 1, 40944),
(65956, 1555869970, 2120822102, 178074, 1, 40944),
(65956, 1555869970, 2120822102, 178073, 1, 40944),
(65956, 1555869970, 2120822102, 178070, 1, 40944),
(65956, 1555869970, 2120822102, 178069, 1, 40944),
(65956, 1555869970, 2120822102, 175034, 1, 40944),
(65956, 1555869970, 2120822102, 175027, 1, 40944),
(65956, 1555869970, 2120822102, 175021, 1, 40944),
(65956, 1555869970, 2120822102, 175015, 1, 40944),
(65956, 1555869970, 2120822102, 175008, 1, 40944),
(65956, 1555869970, 2120822102, 175002, 1, 40944),
(65956, 1555869970, 2120822102, 174997, 1, 40944),
(65956, 1555869970, 2577119682, 1445, 1, 40944),
(65955, 80309961, 3386943305, 201502, 3, 40944),
(65955, 80309961, 3386943305, 201498, 3, 40944),
(65954, 3935302881, 2557447376, 655518, 1, 40944),
(65954, 3935302881, 2557447376, 655517, 1, 40944),
(65954, 3935302881, 2557447376, 655516, 1, 40944),
(65954, 3935302881, 2557447376, 655515, 1, 40944),
(65954, 3935302881, 1109793673, 34460, 1, 40944),
(65954, 3935302881, 1109793673, 24312, 1, 40944),
(65954, 3935302881, 1109793673, 11769, 1, 40944),
(65954, 3935302881, 1109793673, 11768, 1, 40944),
(65954, 3935302881, 604774165, 29725, 1, 40944),
(65951, 196598854, 3205218938, 48675, 1, 40944),
(65947, 1471056202, 1187407512, 347944, 1, 40944),
(65947, 1471056202, 3776013982, 347944, 1, 40944),
(65947, 1471056202, 1187407512, 347943, 1, 40944),
(65947, 1471056202, 3776013982, 347943, 1, 40944),
(65947, 1471056202, 1187407512, 1714, 1, 40944),
(65947, 1471056202, 3776013982, 1714, 1, 40944),
(65947, 1471056202, 3205218938, 41865, 1, 40944),
(65946, 1920747064, 2411028436, 8412, 3, 40944),
(65946, 1920747064, 2411028436, 8031, 3, 40944),
(65946, 1920747064, 1918102339, 13316, 1, 40944),
(65945, 645917719, 261693969, 64850, 1, 40944),
(65945, 645917719, 986198281, 64850, 1, 40944),
(65945, 645917719, 20077728, 421530, 3, 40944),
(65941, 2996326203, 2948698321, 285, 1, 40944),
(65941, 2996326203, 3744420815, 285, 1, 40944),
(65914, 3035223428, 331613093, 335621, 3, 40944),
(65914, 3035223428, 331613093, 335620, 3, 40944);


DELETE FROM `hotfix_data` WHERE `VerifiedBuild`>0 AND `VerifiedBuild`<40944;

DELETE FROM `hotfix_blob` WHERE (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='enUS') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='enUS') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='enUS') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='enUS') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='enUS') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='enUS') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='enUS') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='enUS') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='enUS') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='enUS') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='enUS') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='enUS') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='enUS') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='enUS') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='enUS') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='enUS') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='enUS') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='enUS') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='enUS') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='enUS') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='enUS') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='enUS') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='enUS') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='enUS') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='enUS') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='enUS') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='enUS') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='enUS') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='enUS') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='enUS') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='enUS') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='enUS') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='enUS') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='enUS') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='enUS') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='enUS') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='enUS') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='enUS') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='enUS') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='enUS') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='enUS') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='enUS') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='enUS') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='enUS') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='enUS') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='enUS') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='enUS') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='enUS') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='enUS') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='enUS') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='enUS') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='enUS');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(3776013982, 361952, 'enUS', 0x004164642024733120616E696D6120746F20796F75722063757272656E7420636F76656E616E742773207265736572766F69722E0000, 40944),
(3776013982, 256817, 'enUS', 0x00596F7572207370656C6C7320616E64206162696C697469657320686176652061206368616E636520746F206772616E7420796F75202432353638313873312053706565642C2041766F6964616E63652C20616E64204C6565636820666F722024323536383138642E0D0A0D0A7C634646464646464646416D616E275468756C2773204772616E646575727C720D0A5768656E20656D706F7765726564206279207468652050616E7468656F6E2C20796F757220243F28613133373030357C613133373034377C613133373032387C61313337303237295B537472656E6774685D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295B4167696C6974795D5B496E74656C6C6563745D20697320696E637265617365642062792024323536383332733120666F722024323536383332642E0000, 40944),
(3776013982, 247692, 'enUS', 0x00596F75206861766520612067726561746572206368616E636520746F206561726E2061204B65657073616B6520426F782066726F6D2053616E6473206F662054696D652E204B65657073616B6520426F78657320636F6E7461696E20706F77657266756C206974656D732074686174207369676E69666963616E746C79207265647563652074686520646966666963756C7479206F66204368726F6E6F706F7274616C206368616C6C656E6765732E0D0A0D0A7C634646303046463030426F6E75733A7C72204D6F76656D656E7420616E64206D6F756E74656420737065656420696E6372656173656420627920247332252E00596F75206861766520612067726561746572206368616E636520746F206561726E2061204B65657073616B6520426F782066726F6D2053616E6473206F662054696D652E204B65657073616B6520426F78657320636F6E7461696E20706F77657266756C206974656D732074686174207369676E69666963616E746C79207265647563652074686520646966666963756C7479206F66204368726F6E6F706F7274616C206368616C6C656E6765732E0D0A0D0A7C634646303046463030426F6E75733A7C72204D6F76656D656E7420616E64206D6F756E74656420737065656420696E6372656173656420627920247332252E00, 40944),
(3776013982, 247111, 'enUS', 0x00596F75206861766520612067726561746572206368616E636520746F206561726E20612042726F6E7A65204472616B652066726F6D2053616E6473206F662054696D652E2054686973206472616B652077696C6C20696E7374616E746C7920636C656172206120647261676F6E736872696E6520666F7220796F752E0D0A0D0A7C634646303046463030426F6E75733A7C722044616D61676520616E64206865616C696E6720696E6372656173656420627920247332252E00596F75206861766520612067726561746572206368616E636520746F206561726E20612042726F6E7A65204472616B652066726F6D2053616E6473206F662054696D652E2054686973206472616B652077696C6C20696E7374616E746C7920636C656172206120647261676F6E736872696E6520666F7220796F752E0D0A0D0A7C634646303046463030426F6E75733A7C722044616D61676520616E64206865616C696E6720696E6372656173656420627920247332252E00, 40944),
(3776013982, 247110, 'enUS', 0x00556E6C6F636B20706F7274616C732066726F6D205779726D7265737420746F2065616368206F662074686520647261676F6E736872696E65732E0D0A0D0A7C634646303046463030426F6E75733A7C72204D6F76656D656E7420616E64206D6F756E74656420737065656420696E6372656173656420627920247332252E00556E6C6F636B20706F7274616C732066726F6D205779726D7265737420746F2065616368206F662074686520647261676F6E736872696E65732E0D0A0D0A7C634646303046463030426F6E75733A7C72204D6F76656D656E7420616E64206D6F756E74656420737065656420696E6372656173656420627920247332252E00, 40944),
(3776013982, 247104, 'enUS', 0x004D6F76656D656E7420616E64206D6F756E74656420737065656420697320696E6372656173656420627920247331252E0D0A0D0A7C634646303046463030426F6E75733A7C722044616D61676520616E64206865616C696E6720696E6372656173656420627920247332252E004D6F76656D656E7420616E64206D6F756E74656420737065656420697320696E6372656173656420627920247331252E0D0A0D0A7C634646303046463030426F6E75733A7C722044616D61676520616E64206865616C696E6720696E6372656173656420627920247332252E00, 40944),
(3776013982, 247103, 'enUS', 0x0024407370656C6C646573633234343935390D0A0D0A7C634646303046463030426F6E75733A7C722044616D61676520616E64206865616C696E6720696E637265617365642062792035252E0000, 40944),
(3776013982, 247099, 'enUS', 0x00596F75722072657075746174696F6E206761696E2066726F6D206B696C6C732077697468204368726F6D696520697320696E63726561736564206279202432343737363973312520647572696E67207468652066696E616C20243234373736396420616E64206279202432343737373073312520647572696E67207468652066696E616C2024323437373730642E0D0A0D0A7C634646303046463030426F6E75733A7C72204D6F76656D656E7420616E64206D6F756E74656420737065656420696E6372656173656420627920247332252E0000, 40944),
(3776013982, 247096, 'enUS', 0x000000, 40944),
(3776013982, 247094, 'enUS', 0x00596F7572206368616E636520746F2066696E642053616E6473206F662054696D6520697320696E6372656173656420627920247331252E0D0A0D0A7C634646303046463030426F6E75733A7C72204865616C746820696E6372656173656420627920247332252E00596F7572206368616E636520746F2066696E642053616E6473206F662054696D6520697320696E6372656173656420627920247331252E0D0A0D0A7C634646303046463030426F6E75733A7C72204865616C746820696E6372656173656420627920247332252E00, 40944),
(3776013982, 247093, 'enUS', 0x000000, 40944),
(3776013982, 247092, 'enUS', 0x000000, 40944),
(3776013982, 247089, 'enUS', 0x0024407370656C6C646573633234353530330D0A0D0A7C634646303046463030426F6E75733A7C722044616D6167652C206865616C696E672C206865616C74682C206D6F76656D656E742C20616E64206D6F756E74656420737065656420616C6C20696E6372656173656420627920247332252E0000, 40944),
(3776013982, 247088, 'enUS', 0x004368726F6D69652072657665616C73206E6561726279207472656173757265206368657374732E0D0A0D0A7C634646303046463030426F6E75733A7C722044616D61676520616E64206865616C696E6720696E6372656173656420627920247332252E004368726F6D69652072657665616C73206E6561726279207472656173757265206368657374732E0D0A0D0A7C634646303046463030426F6E75733A7C722044616D61676520616E64206865616C696E6720696E6372656173656420627920247332252E00, 40944),
(3479059991, 9040, 'enUS', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'enUS', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'enUS', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'enUS', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'enUS', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'enUS', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'enUS', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'enUS', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'enUS', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'enUS', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'enUS', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'enUS', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'enUS', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'enUS', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'enUS', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'enUS', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'enUS', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'enUS', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'enUS', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'enUS', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'enUS', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'enUS', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'enUS', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'enUS', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'enUS', 0x0024407370656C6C646573633232383832390024733120466972652064616D61676520696E666C696374656420657665727920243232383832397431207365632E00, 40944),
(3776013982, 227799, 'enUS', 0x005761766573206F6620776174657220737765657020696E2066726F6D20746865206564676573206F662074686520726F6F6D2C20696E666C696374696E67202473312046726F73742064616D61676520746F20706C6179657273207468657920636F6C6C69646520776974682E0000, 40944),
(3776013982, 227780, 'enUS', 0x004D61726B7320616C6C20706C6179657273207769746820612024407370656C6C6E616D653232373738302E2055706F6E2065787069726174696F6E2C20696E666C6963747320247331204E61747572652064616D61676520746F20616C6C20706C61796572732077697468696E20244131207964732E0055706F6E2065787069726174696F6E2C20696E666C6963747320247331204E61747572652064616D61676520746F20616C6C20706C61796572732077697468696E20244131207964732E00, 40944),
(3386291891, 116804, 'enUS', 0x5363656E65204163746F7200000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'enUS', 0x417263686D616765204B686164676172000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'enUS', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'enUS', 0x4E69656C6173204172616E0000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'enUS', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'enUS', 0x5468652043757261746F72000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'enUS', 0x004F70656E20796F757220436F6D70616E696F6E73207061676520616E642073656C656374206120636F6D70616E696F6E20746F207261697365207468656972206C6576656C20746F202473312E0000, 40944),
(261693969, 60399, 'enUS', 0xFFFFFFFFFFFFFFFF416964696E6720526576656E647265746800003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'enUS', 0xFFFFFFFFFFFFFFFF416964696E67204D616C6472617878757300003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'enUS', 0xFFFFFFFFFFFFFFFF416964696E672042617374696F6E00003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'enUS', 0xFFFFFFFFFFFFFFFF416964696E6720417264656E7765616C6400003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'enUS', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'enUS', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'enUS', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'enUS', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'enUS', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'enUS', 0x00000000, 40944),
(3865974254, 176921, 'enUS', 0x00000000, 40944),
(3865974254, 176832, 'enUS', 0x00000000, 40944),
(3776013982, 243328, 'enUS', 0x00005265647563656420746872656174206C6576656C2E00, 40944),
(3865974254, 187935, 'enUS', 0x00000000, 40944),
(3205218938, 44300, 'enUS', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F580041747461636820616E2041757468656E74696361746F7220616E6420534D532050726F7465637420746F20796F7572206163636F756E7420746F20756E6C6F636B2074686973206669656C640001, 40944),
(3205218938, 44299, 'enUS', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C636666666630303030596F752063616E277420706F73742061204D79746869632B2067726F757020776974686F75742061206B657973746F6E6520756E74696C20796F752073656375726520796F7572206163636F756E7420776974682074686520426174746C652E6E65742041757468656E74696361746F7220616E6420534D532050726F746563747C727C6E7C6366663165666630303C436C69636B20666F72206D6F726520696E666F3E7C720001, 40944),
(3205218938, 44284, 'enUS', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C636666666630303030596F752063616E277420656469742074686973206669656C6420756E74696C20796F752073656375726520796F7572206163636F756E7420776974682074686520426174746C652E6E65742041757468656E74696361746F7220616E6420534D532050726F746563747C727C6E7C6366663165666630303C436C69636B20666F72206D6F726520696E666F3E7C720001, 40944),
(3205218938, 44283, 'enUS', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F4445534300556E6C6F636B2066756C6C2061636365737320746F207468652067726F75702066696E64657220627920617474616368696E6720616E2041757468656E74696361746F7220616E6420534D532050726F7465637420746F20796F7572206163636F756E742E7C6E7C6E54686520426174746C652E6E65742041757468656E74696361746F72206973206120667265652C20656173792D746F2D757365207365727669636520746861742070726F746563747320796F7572206163636F756E742066726F6D20696E747275646572732C20616E6420534D532050726F74656374206E6F74696669657320796F75207768656E20696D706F7274616E74206368616E67657320617265206D61646520746F20796F7572206163636F756E742E7C6E7C6E436C69636B202241637469766174652220746F206C61756E6368207468652041757468656E74696361746F7220736574757020776562736974652E0001, 40944),
(3865974254, 188152, 'enUS', 0x00000000, 40944),
(3776013982, 53385, 'enUS', 0x00556E6C656173686573206120776869726C206F6620646976696E6520656E657267792C206465616C696E672024733120486F6C792064616D61676520746F20616C6C206E656172627920656E656D6965732E204465616C7320726564756365642064616D616765206265796F6E642024733220746172676574732E0000, 40944),
(261693969, 62694, 'enUS', 0xFFFFFFFFFFFFFFFF412043616C6C696E6720696E204D616C64726178787573000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'enUS', 0xFFFFFFFFFFFFFFFF412043616C6C696E6720696E20417264656E7765616C64000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'enUS', 0xFFFFFFFFFFFFFFFF412043616C6C696E6720696E2042617374696F6E000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'enUS', 0xFFFFFFFFFFFFFFFF412043616C6C696E6720696E20526576656E6472657468000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'enUS', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'enUS', 0x000000, 40944),
(3776013982, 307934, 'enUS', 0x000000, 40944),
(3776013982, 307480, 'enUS', 0x005468726F7720796F757220526970656E656420447265646765722E0000, 40944),
(2948698321, 354, 'enUS', 0x64DF8D9146629CB2, 40944),
(261693969, 65165, 'enUS', 0xFFFFFFFFFFFFFFFF536F756C20537570706F7274000044AC546F010000000000FFFF05000600000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000030E10000, 40944),
(261693969, 60111, 'enUS', 0xFFFFFFFFFFFFFFFF466F7267696E67204120467269656E647368697000005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'enUS', 0xFFFFFFFFFFFFFFFF4E6576657220486164206120467269656E64204C696B65204D6500005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'enUS', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'enUS', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'enUS', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'enUS', 0x00000000, 40944),
(3865974254, 151804, 'enUS', 0x00000000, 40944),
(3865974254, 151792, 'enUS', 0x00000000, 40944),
(3037505077, 151792, 'enUS', 0x0100, 40944),
(3865974254, 151790, 'enUS', 0x00000000, 40944),
(3037505077, 151790, 'enUS', 0x0100, 40944),
(3865974254, 146306, 'enUS', 0x00000000, 40944),
(3865974254, 34685, 'enUS', 0x00000000, 40944),
(3865974254, 34683, 'enUS', 0x00000000, 40944),
(3865974254, 34087, 'enUS', 0x00000000, 40944),
(3865974254, 34085, 'enUS', 0x00000000, 40944),
(3865974254, 33969, 'enUS', 0x00000000, 40944),
(3865974254, 33968, 'enUS', 0x00000000, 40944),
(3865974254, 33967, 'enUS', 0x00000000, 40944),
(3865974254, 33966, 'enUS', 0x00000000, 40944),
(3865974254, 33868, 'enUS', 0x00000000, 40944),
(3865974254, 33864, 'enUS', 0x00000000, 40944),
(3865974254, 33863, 'enUS', 0x00000000, 40944),
(3865974254, 33862, 'enUS', 0x00000000, 40944),
(3865974254, 23324, 'enUS', 0x00000000, 40944),
(3865974254, 21525, 'enUS', 0x00000000, 40944),
(3865974254, 21524, 'enUS', 0x00000000, 40944),
(3865974254, 19028, 'enUS', 0x00000000, 40944),
(3865974254, 6835, 'enUS', 0x00000000, 40944),
(3865974254, 6833, 'enUS', 0x00000000, 40944),
(3865974254, 181321, 'enUS', 0x00000000, 40944),
(1548466975, 27672, 'enUS', 0x10040000, 40944),
(3776013982, 365080, 'enUS', 0x00004D6F76656D656E7420737065656420696E6372656173656420627920247331252E00, 40944),
(3776013982, 317920, 'enUS', 0x00496E7465727275707420616E642053696C656E63652065666665637473206F6E20706172747920616E642072616964206D656D626572732077697468696E202461312079617264732061726520247331252073686F727465722E20243F733333393132345B4665617220656666656374732061726520616C736F20726564756365642E5D5B5D00496E7465727275707420616E642053696C656E63652065666665637473207265647563656420627920247731252E20243F733333393132345B46656172206566666563747320617265207265647563656420627920247734252E5D5B5D00, 40944),
(3776013982, 465, 'enUS', 0x00506172747920616E642072616964206D656D626572732077697468696E202461312079617264732061726520626F6C737465726564206279207468656972206465766F74696F6E2C207265647563696E672064616D6167652074616B656E20627920247331252E0044616D6167652074616B656E207265647563656420627920247731252E00, 40944),
(3205218938, 44172, 'enUS', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F444553430041636869657665206120726174696E67206F662031393530206F722068696768657220746F206561726E3A7C6E2D20507650204974656D20557067726164652052616E6B0001, 40944),
(3205218938, 40887, 'enUS', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F444553430041636869657665206120726174696E67206F662031383030206F722068696768657220746F206561726E3A7C6E2D20526976616C205469746C657C6E2D20456C69746520507650204974656D2053657420417070656172616E63653A2048656C6D7C6E2D20456C69746520507650204974656D2053657420417070656172616E63653A2053686F756C6465720001, 40944),
(3205218938, 40885, 'enUS', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F444553430041636869657665206120726174696E67206F662031343030206F722068696768657220746F206561726E3A7C6E2D204368616C6C656E676572205469746C657C6E2D20456C69746520507650204974656D2053657420417070656172616E63653A20476C6F7665737C6E2D20456C69746520507650204974656D2053657420417070656172616E63653A20426F6F74730001, 40944),
(3776013982, 357407, 'enUS', 0x0053756D6D6F6E20616E6420636F6E74726F6C20796F757220526F636B696E2720526F6C6C696E272052616365722C204D617261756465722E0055736520796F757220616374696F6E2062617220746F2061747461636B206F746865722072656D6F746520636F6E74726F6C20746F79732E00, 40944),
(3776013982, 357406, 'enUS', 0x0053756D6D6F6E20616E6420636F6E74726F6C20796F757220526F636B696E2720526F6C6C696E272052616365722C204D617261756465722E0055736520796F757220616374696F6E2062617220746F2061747461636B206F746865722072656D6F746520636F6E74726F6C20746F79732E00, 40944),
(3776013982, 357405, 'enUS', 0x0053756D6D6F6E20616E6420636F6E74726F6C20796F757220526F636B696E2720526F6C6C696E272052616365722C204D617261756465722E0055736520796F757220616374696F6E2062617220746F2061747461636B206F746865722072656D6F746520636F6E74726F6C20746F79732E00, 40944),
(3776013982, 356631, 'enUS', 0x0053756D6D6F6E20616E6420636F6E74726F6C20796F757220526F636B696E2720526F6C6C696E272052616365722C2041697220426C6164652E0055736520796F757220616374696F6E2062617220746F2061747461636B206F746865722072656D6F746520636F6E74726F6C20746F79732E00, 40944),
(3776013982, 328923, 'enUS', 0x4E6967687420466165005472616E7366657220746865206C69666520666F726365206F6620757020746F20243332383932384920656E656D69657320696E2074686520746172676574656420617265612C206465616C696E6720247B282433323839323873312A24642F24743229202B202433323839323873317D204E61747572652064616D616765206576656E6C792073706C697420746F206561636820656E656D7920746172676574206F7665722024642E20243F613133373034315B0D0A0D0A46756C6C79206368616E6E656C696E6720466165205472616E73667573696F6E2067656E6572617465732024733420244C737461636B3A737461636B733B206F66204D61656C7374726F6D20576561706F6E2E5D5B5D0D0A0D0A5072657373696E6720466165205472616E73667573696F6E20616761696E2077697468696E2024333238393333642077696C6C2072656C656173652024733125206F6620616C6C2064616D6167652066726F6D20466165205472616E73667573696F6E2C206865616C696E6720757020746F2024333238393330733220616C6C6965732077697468696E20243332383933304131207964732E0000, 40944),
(3776013982, 101546, 'enUS', 0x005370696E207768696C65206B69636B696E6720696E20746865206169722C206465616C696E6720243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5D20506879736963616C2064616D616765206F76657220246420746F20616C6C20656E656D6965732077697468696E20243130373237304131207964732E204465616C7320726564756365642064616D616765206265796F6E642024733120746172676574732E243F63335B0D0A0D0A5370696E6E696E67204372616E65204B69636B27732064616D61676520697320696E63726561736564206279202432323033353873312520666F72206561636820756E697175652074617267657420796F752776652073747275636B20696E20746865206C61737420243232303335386420776974682054696765722050616C6D2C20426C61636B6F7574204B69636B2C206F7220526973696E672053756E204B69636B2E20537461636B7320757020746F2024323238323837692074696D65732E5D5B5D0041747461636B696E67206E656172627920656E656D69657320666F7220506879736963616C2064616D61676520657665727920243130313534367431207365632E00, 40944),
(3865974254, 188220, 'enUS', 0x00000000, 40944),
(3865974254, 187900, 'enUS', 0x00000000, 40944),
(3865974254, 187899, 'enUS', 0x00000000, 40944),
(3865974254, 187898, 'enUS', 0x00000000, 40944),
(3865974254, 187897, 'enUS', 0x00000000, 40944),
(3865974254, 187896, 'enUS', 0x00000000, 40944),
(3865974254, 187895, 'enUS', 0x00000000, 40944),
(3865974254, 187875, 'enUS', 0x00000000, 40944),
(3865974254, 187869, 'enUS', 0x00000000, 40944),
(3865974254, 150746, 'enUS', 0x00000000, 40944),
(3865974254, 150745, 'enUS', 0x00000000, 40944),
(3865974254, 150744, 'enUS', 0x00000000, 40944),
(3865974254, 150743, 'enUS', 0x00000000, 40944),
(3776013982, 364944, 'enUS', 0x00004D6F76656D656E7420737065656420696E6372656173656420627920247331252E00, 40944),
(3776013982, 228462, 'enUS', 0x00496E6372656173657320796F7572206175746F61747461636B2064616D616765206279202473312E0000, 40944),
(3776013982, 119611, 'enUS', 0x0024407370656C6C6465736331313531353100526573746F72657320247731206865616C746820657665727920247431207365632E00, 40944),
(3776013982, 119607, 'enUS', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'enUS', 0x00000000, 40944),
(1181150530, 403396, 'enUS', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'enUS', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'enUS', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'enUS', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'enUS', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'enUS', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'enUS', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'enUS', 0xA4530000, 40944),
(3359787322, 21411, 'enUS', 0xA3530000, 40944),
(3359787322, 21410, 'enUS', 0xA2530000, 40944),
(3359787322, 21409, 'enUS', 0xA1530000, 40944),
(3359787322, 21408, 'enUS', 0xA0530000, 40944),
(3359787322, 21407, 'enUS', 0x9F530000, 40944),
(3359787322, 21406, 'enUS', 0x9E530000, 40944),
(2557447376, 655518, 'enUS', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'enUS', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'enUS', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'enUS', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'enUS', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'enUS', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F454646454354004C6567616379206C6F6F742072756C657320617265206E6F206C6F6E67657220696E206566666563742E0001, 40944),
(3776013982, 347944, 'enUS', 0x00437269746963616C20737472696B65206368616E636520696E6372656173656420627920247331252E0D0A00437269746963616C20737472696B65206368616E636520696E6372656173656420627920247331252E00, 40944),
(3776013982, 347943, 'enUS', 0x004D6178696D756D206865616C746820696E6372656173656420627920247331252E0D0A004D6178696D756D206865616C746820696E6372656173656420627920247331252E00, 40944),
(3776013982, 1714, 'enUS', 0x00466F72636573207468652074617267657420746F20737065616B20696E2044656D6F6E69632C20696E6372656173696E67207468652063617374696E672074696D65206F6620616C6C207370656C6C73206279202473312520666F722024642E243F733130333131325B0D0A0D0A7C434646453535424230536F756C6275726E3A20596F7572204375727365206F6620546F6E677565732077696C6C2061666665637420616C6C20656E656D69657320696E20612024313034323234412079617264207261646975732061726F756E6420796F7572207461726765742E7C525D5B5D0D0A0D0A7C6346463832383246464375727365733A2041207761726C6F636B2063616E206F6E6C792068617665206F6E652043757273652061637469766520706572207461726765742E7C7200537065616B696E672044656D6F6E696320696E6372656173696E672063617374696E672074696D6520627920247731252E00, 40944),
(3205218938, 41865, 'enUS', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E5300596F7520646F206E6F742068617665207065726D697373696F6E20746F20656469742074686520726563727569746D656E7420696E666F2E0001, 40944),
(261693969, 64850, 'enUS', 0xFFFFFFFFFFFFFFFF54726176657273696E6720546F726768617374000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'enUS', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='enUS') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='enUS');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'enUS' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `achievement_locale` WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (14775,14752,14682,14351));
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14775, 'deDE', 'Erreicht bei Marasmius den Status ehrfürchtig.', 'Volle Schwammerkennung', 'Titelbelohnung: Mykologe/Mykologin', 40944),
(14752, 'deDE', 'Schließt die unten aufgelisteten Erfolge der Monstrositätenflickerei ab.', 'Abhakliste für Tote', 'Bonustitel: der/die Monströse & Reittierbelohnung: Gepanzerter auserwählter Tauralus', 40944),
(14682, 'deDE', 'Schließt die unten aufgelisteten Gluthoferfolge ab.', 'Der Festherold', 'Bonustitel: Festherold(in)', 40944),
(14351, 'deDE', 'Besiegt 39 Bosse auf dem Pfad des Aufstiegs.', 'Der Pfad zum Aufstieg 39', 'Schaltet weitere Herausforderungen auf dem Pfad des Aufstiegs frei.', 40944);


DELETE FROM `area_table_locale` WHERE (`VerifiedBuild`>0 AND `ID`=13316 AND `locale`='deDE');
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(13316, 'deDE', 'Haus der Rituale', 40944);


DELETE FROM `battle_pet_species_locale` WHERE (`VerifiedBuild`>0 AND `ID`=3188 AND `locale`='deDE');
INSERT INTO `battle_pet_species_locale` (`ID`, `locale`, `Description_lang`, `SourceText_lang`, `VerifiedBuild`) VALUES
(3188, 'deDE', '', '', 40944);


DELETE FROM `broadcast_text_locale` WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (215513,215512,215511));
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(215513, 'deDE', '', 'Es wäre nicht sehr weise, unvorbereitet in den Schlund vorzudringen. Kehrt zu mir zurück, wenn Ihr bereit seid.', 40944),
(215512, 'deDE', 'Es wäre nicht sehr weise, unvorbereitet in den Schlund vorzudringen. Kehrt zu mir zurück, wenn Ihr bereit seid.', '', 40944),
(215511, 'deDE', '', 'Wir sind so nah dran. Kämpft an meiner Seite und wir stehen das gemeinsam durch.', 40944);


DELETE FROM `char_titles_locale` WHERE (`VerifiedBuild`>0 AND `ID`=693 AND `locale`='deDE');
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(693, 'deDE', '%s der Aufgestiegene', '%s die Aufgestiegene', 40944);


UPDATE `char_titles_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=683 AND `locale`='deDE');
DELETE FROM `chr_customization_option_locale` WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (1523,689));
INSERT INTO `chr_customization_option_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1523, 'deDE', 'Schwanz', 40944),
(689, 'deDE', 'Schwanz', 40944);


DELETE FROM `criteria_tree_locale` WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (91730,94390,94389,94388,93811,93810,94331,94330));
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91730, 'deDE', '9.1 Metaerfolg', 40944),
(94390, 'deDE', '', 40944),
(94389, 'deDE', '', 40944),
(94388, 'deDE', '', 40944),
(93811, 'deDE', '', 40944),
(93810, 'deDE', 'Ruhmstufe 80', 40944),
(94331, 'deDE', '', 40944),
(94330, 'deDE', 'Renown Level 80 - Kyrian', 40944);


DELETE FROM `item_search_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,116401));
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(151806, 'deDE', 'Elegantes Kleid', 40944),
(151804, 'deDE', 'Schwarze Smokinghose', 40944),
(151792, 'deDE', 'Grüne Winterkleidung', 40944),
(151790, 'deDE', 'Rote Winterkleidung', 40944),
(34685, 'deDE', 'Sommerliche Tracht', 40944),
(34683, 'deDE', 'Sommerliche Sandalen', 40944),
(34087, 'deDE', 'Grüne Winterkleidung', 40944),
(34085, 'deDE', 'Rote Winterkleidung', 40944),
(33969, 'deDE', 'Lila Braufesthut', 40944),
(33968, 'deDE', 'Blauer Braufesthut', 40944),
(33967, 'deDE', 'Grüner Braufesthut', 40944),
(33966, 'deDE', 'Braufestschuhe', 40944),
(33868, 'deDE', 'Braufeststiefel', 40944),
(33864, 'deDE', 'Brauner Braufesthut', 40944),
(33863, 'deDE', 'Braufestdirndl', 40944),
(33862, 'deDE', 'Braufesttracht', 40944),
(23324, 'deDE', 'Mantelung des Sonnenwendfests', 40944),
(21525, 'deDE', 'Grüne Wintermütze', 40944),
(21524, 'deDE', 'Rote Wintermütze', 40944),
(19028, 'deDE', 'Elegantes Kleid', 40944),
(6835, 'deDE', 'Schwarze Smokinghose', 40944),
(6833, 'deDE', 'Weißes Smokinghemd', 40944),
(181321, 'deDE', 'Edelsteingekrönter Zauberstab', 40944),
(116401, 'deDE', 'Feiner Pilgerhut', 40944);


DELETE FROM `item_sparse_locale` WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (176922,176921,176832,187935,188152,151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,188220,187900,187899,187898,187897,187896,187895,187875,187869,150746,150745,150744,150743,116401));
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(176922, 'deDE', 'Diese magische Blüte erhöht sowohl den Ertrag an Handwerksmaterialien, die von einem wiedergeborenen Geist angeboten werden, als auch an Katalysatoren aus Katalysatorsamen um 100%.', '', '', '', 'Wilde Nachtblüte', 40944),
(176921, 'deDE', 'Diese verzauberten Blätter verkürzen den Prozess des Wildsamens des Nachwachsens um 1 Tag.', '', '', '', 'Temporalblätter', 40944),
(176832, 'deDE', 'Diese besondere Wurzel erhöht die Qualität der Belohnungen, die von einem Geist bei der Wiedergeburt angeboten werden.', '', '', '', 'Wildsamenwurzelfaser', 40944),
(187935, 'deDE', 'Lehrt Euch, wie man ein Mal des Mitternachtsrunenhirschs herstellt.', '', '', '', 'Technik: Mal des Mitternachtsrunenhirschs', 40944),
(188152, 'deDE', 'Die Magie des Splitters fühlt sich sengend heiß an.', '', '', '', 'Torsteuerungssplitter', 40944),
(151806, 'deDE', '', '', '', '', 'Elegantes Kleid', 40944),
(151804, 'deDE', '', '', '', '', 'Schwarze Smokinghose', 40944),
(151792, 'deDE', '', '', '', '', 'Grüne Winterkleidung', 40944),
(151790, 'deDE', '', '', '', '', 'Rote Winterkleidung', 40944),
(34685, 'deDE', '', '', '', '', 'Sommerliche Tracht', 40944),
(34683, 'deDE', '', '', '', '', 'Sommerliche Sandalen', 40944),
(34087, 'deDE', '', '', '', '', 'Grüne Winterkleidung', 40944),
(34085, 'deDE', '', '', '', '', 'Rote Winterkleidung', 40944),
(33969, 'deDE', '', '', '', '', 'Lila Braufesthut', 40944),
(33968, 'deDE', '', '', '', '', 'Blauer Braufesthut', 40944),
(33967, 'deDE', '', '', '', '', 'Grüner Braufesthut', 40944),
(33966, 'deDE', '', '', '', '', 'Braufestschuhe', 40944),
(33868, 'deDE', '', '', '', '', 'Braufeststiefel', 40944),
(33864, 'deDE', '', '', '', '', 'Brauner Braufesthut', 40944),
(33863, 'deDE', '', '', '', '', 'Braufestdirndl', 40944),
(33862, 'deDE', '', '', '', '', 'Braufesttracht', 40944),
(23324, 'deDE', '', '', '', '', 'Mantelung des Sonnenwendfests', 40944),
(21525, 'deDE', '', '', '', '', 'Grüne Wintermütze', 40944),
(21524, 'deDE', '', '', '', '', 'Rote Wintermütze', 40944),
(19028, 'deDE', '', '', '', '', 'Elegantes Kleid', 40944),
(6835, 'deDE', '', '', '', '', 'Schwarze Smokinghose', 40944),
(6833, 'deDE', '', '', '', '', 'Weißes Smokinghemd', 40944),
(181321, 'deDE', '', '', '', '', 'Edelsteingekrönter Zauberstab', 40944),
(188220, 'deDE', 'Unten steht \"Ich habe den Turm überlebt.\"', '', '', '', 'Aschekugel von Torghast', 40944),
(187900, 'deDE', 'Ein Duo aus einem Goblin und einer Gnomin beschreibt seine vielen Entdeckungen auf den zwei Inseln.', '', '', '', 'Späherkarte: Die Wunder von Kul Tiras und Zandalar', 40944),
(187899, 'deDE', 'Eine Beschreibung der verschiedenen Biome und der unglaublichen Flora der Scherbenwelt, aus der Feder eines abenteuerlustigen Alchemisten.', '', '', '', 'Späherkarte: Die vielen Kuriositäten der Scherbenwelt', 40944),
(187898, 'deDE', 'Ein detaillierter Bericht einer Argentumkreuzfahrerin über alle militärischen Operationen, die zur Verfolgung des Lichkönigs unternommen wurden.', '', '', '', 'Späherkarte: Der wahre Preis des Nordendfeldzugs', 40944),
(187897, 'deDE', 'Ein seltener fraktionsübergreifender Bericht, der die unzähligen Folgen des von Todesschwinge ausgelösten Weltenbebens von Azeroth zusammenträgt.', '', '', '', 'Späherkarte: Die Konsequenzen des Kataklysmus', 40944),
(187896, 'deDE', 'Eine heitere Geschichte über Li Lis jüngste Abenteuer in Pandaria, samt kulinarischer Empfehlungen ihres Onkels Chen.', '', '', '', 'Späherkarte: Der Sturmbräuführer für Pandaria', 40944),
(187895, 'deDE', 'Eine kurze Liste der wenigen sicheren Zufluchtsorte, die man in Draenor findet. Die Liste enthält außerdem die örtlichen Bräuche, die man an jedem dieser Orte beachten sollte.', '', '', '', 'Späherkarte: Die Gefahren Draenors', 40944),
(187875, 'deDE', 'Eine große Sammlung aus Berichten und Korrespondenzen verschiedener Militäreinheiten, die gegen die Legion kämpfen.', '', '', '', 'Späherkarte: Vereinte Fronten der Verheerten Inseln', 40944),
(187869, 'deDE', 'Eine detaillierte Schilderung der Reise eines Schlundgängers durch die vier Reiche der Schattenlande.', '', '', '', 'Späherkarte: In die Schattenlande', 40944),
(150746, 'deDE', 'Eine proaktive Machbarkeitsstudie zur Umsetzung einer bedarfsorientierten Nachschubprozessstruktur für die Interesseneigner etwaiger Repräsentanzen in den Außenposten der Östlichen Königreiche.', '', '', '', 'Späherkarte: Modernisierung der Nachschublinien in den Östlichen Königreichen', 40944),
(150745, 'deDE', 'Eine umfassende Strategie, wie man die Streitkräfte der Allianz in den Östlichen Königreichen im Falle eines vierten Krieges schnell unschädlich macht.', '', '', '', 'Späherkarte: Feldzug in den Östlichen Königreichen', 40944),
(150744, 'deDE', 'Wie man das Land wieder heilt, nachdem es von den Wahnsinnigen, den Verderbten oder den Unnatürlichen heimgesucht wurde.', '', '', '', 'Späherkarte: Kalimdor, auf den Spuren der Erdenmutter', 40944),
(150743, 'deDE', 'Ein umfassendes Sammelwerk über scharfzahnige, krallige, giftige und Horde-zugehörige Bestien.', '', '', '', 'Späherkarte: Überlebenshelfer für Kalimdor', 40944),
(116401, 'deDE', '', '', '', '', 'Feiner Pilgerhut', 40944);


UPDATE `item_sparse_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (185950,185947,185946));
DELETE FROM `lfg_dungeons_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1445 AND `locale`='deDE');
INSERT INTO `lfg_dungeons_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1445, 'deDE', 'Sturz der Teufelstotems', 'Haltet Tugar Bluttotem und seine Teufelswürmer davon ab, den Berg zu zerstören.', 40944);


DELETE FROM `map_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1756 AND `locale`='deDE');
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(1756, 'deDE', 'Die Tode von Chromie', '', '', '', '', 40944);


DELETE FROM `player_condition_locale` WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (95078,95077,95076,85644,73006,73005,87365,85912,85910,85909,85692,94517,94516,94515,94514,94513,94512,94511));
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(95078, 'deDE', '', 40944),
(95077, 'deDE', '', 40944),
(95076, 'deDE', '', 40944),
(85644, 'deDE', 'Ihr müsst Stufe $pcMinLevel erreichen, um fortzufahren.', 40944),
(73006, 'deDE', '', 40944),
(73005, 'deDE', '', 40944),
(87365, 'deDE', '', 40944),
(85912, 'deDE', '', 40944),
(85910, 'deDE', '', 40944),
(85909, 'deDE', '', 40944),
(85692, 'deDE', '', 40944),
(94517, 'deDE', '', 40944),
(94516, 'deDE', '', 40944),
(94515, 'deDE', '', 40944),
(94514, 'deDE', '', 40944),
(94513, 'deDE', '', 40944),
(94512, 'deDE', '', 40944),
(94511, 'deDE', '', 40944);


DELETE FROM `spell_category_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1186 AND `locale`='deDE');
INSERT INTO `spell_category_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1186, 'deDE', 'Class - Paladin - Hand of Sacrifice', 40944);


DELETE FROM `spell_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (361952,256817,247692,247111,247110,247104,247103,247099,247096,247094,247093,247092,247089,247088,228844,227799,227780,362986,243328,358927,53385,329902,307934,307480,365080,317920,465,357407,357406,357405,356631,328923,101546,364944,228462,119611,119607,347944,347943,1714));
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(361952, 'deDE', '1.000 Anima', 40944),
(256817, 'deDE', 'Mal von Aman\'thul', 40944),
(247692, 'deDE', 'Andenkenkontinuum', 40944),
(247111, 'deDE', 'Blessing of the Bronze Dragonflight Passive', 40944),
(247110, 'deDE', 'Unendliche Geschwindigkeit', 40944),
(247104, 'deDE', 'Acceleration Passive', 40944),
(247103, 'deDE', 'Zeit anhalten - Passiv', 40944),
(247099, 'deDE', 'Chrono Charisma Passive', 40944),
(247096, 'deDE', 'Rapid Recovery Passive', 40944),
(247094, 'deDE', 'Vom Glück begünstigt', 40944),
(247093, 'deDE', 'Dragon\'s Determination Passive', 40944),
(247092, 'deDE', 'Accelerated Aggression Passive', 40944),
(247089, 'deDE', 'Dragon Crash Passive', 40944),
(247088, 'deDE', 'Einsicht', 40944),
(228844, 'deDE', 'Brennende Knochen', 40944),
(227799, 'deDE', 'Wegspülen', 40944),
(227780, 'deDE', 'Donnerritual', 40944),
(362986, 'deDE', 'Erfahrung', 40944),
(243328, 'deDE', 'Verblassen', 40944),
(358927, 'deDE', 'Wachsamkeit der Nachtgeborenenwache', 40944),
(53385, 'deDE', 'Göttlicher Sturm', 40944),
(329902, 'deDE', 'Graben', 40944),
(307934, 'deDE', 'Graben', 40944),
(307480, 'deDE', 'Gräber werfen', 40944),
(365080, 'deDE', 'Windlaufen', 40944),
(317920, 'deDE', 'Aura der Konzentration', 40944),
(465, 'deDE', 'Aura der Hingabe', 40944),
(357407, 'deDE', 'Havac beschwören', 40944),
(357406, 'deDE', 'Battle Trak beschwören', 40944),
(357405, 'deDE', 'Dirt Devil beschwören', 40944),
(356631, 'deDE', 'Air Blade beschwören', 40944),
(328923, 'deDE', 'Faetransfusion', 40944),
(101546, 'deDE', 'Wirbelnder Kranichtritt', 40944),
(364944, 'deDE', 'Windlaufen', 40944),
(228462, 'deDE', 'Melandrus\' Signet', 40944),
(119611, 'deDE', 'Erneuernder Nebel', 40944),
(119607, 'deDE', 'Erneuernder Nebel', 40944),
(347944, 'deDE', 'Obleronstacheln', 40944),
(347943, 'deDE', 'Obleronausdauer', 40944),
(1714, 'deDE', 'Fluch der Sprachen', 40944);


DELETE FROM `transmog_set_locale` WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (2289,2287,2283,2281,2277,2275,2271,2269,2178));
INSERT INTO `transmog_set_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(2289, 'deDE', 'Plattenrüstung des entfesselten Gladiators', 40944),
(2287, 'deDE', 'Plattenrüstung des entfesselten Gladiators', 40944),
(2283, 'deDE', 'Kettenrüstung des entfesselten Gladiators', 40944),
(2281, 'deDE', 'Kettenrüstung des entfesselten Gladiators', 40944),
(2277, 'deDE', 'Lederrüstung des entfesselten Gladiators', 40944),
(2275, 'deDE', 'Lederrüstung des entfesselten Gladiators', 40944),
(2271, 'deDE', 'Gewänder des entfesselten Gladiators', 40944),
(2269, 'deDE', 'Gewänder des entfesselten Gladiators', 40944),
(2178, 'deDE', 'Waffen des Flickmeisters', 40944);


UPDATE `transmog_set_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='deDE' AND `ID` IN (2221,2220,2219,2218,2217,2216,2215,2214,2213,2212,2211,2210,2209,2208,2207,2206,2205,2204,2203,2202));
DELETE FROM `achievement_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table_locale` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_blob` WHERE (`TableHash`=2948698321 AND `RecordId`=340 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='deDE') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='deDE') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='deDE') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='deDE') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='deDE') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='deDE') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='deDE') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='deDE') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='deDE') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='deDE') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='deDE') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='deDE') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='deDE') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='deDE') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='deDE') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='deDE') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=358927 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='deDE') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='deDE') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='deDE') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='deDE') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='deDE') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='deDE') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='deDE') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='deDE') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='deDE') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='deDE') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='deDE') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='deDE') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='deDE') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='deDE') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='deDE') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='deDE') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='deDE') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='deDE') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='deDE') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='deDE') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='deDE') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='deDE') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='deDE') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='deDE') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='deDE') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='deDE') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='deDE') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='deDE') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='deDE') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='deDE') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='deDE') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='deDE') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='deDE') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='deDE') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='deDE') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='deDE');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(2948698321, 340, 'deDE', 0xA53E23C86B3D8F59, 40944),
(261693969, 65165, 'deDE', 0xFFFFFFFFFFFFFFFF5365656C697363686520556E7465727374C3BC747A756E67000044AC546F010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000000000000, 40944),
(3776013982, 361952, 'deDE', 0x0046C3BC67742064656D20416E696D617265736572766F697220457572657320616B7475656C6C656E2050616B74732024733120416E696D612068696E7A752E0000, 40944),
(3776013982, 256817, 'deDE', 0x0045757265205A617562657220756E642046C3A46869676B656974656E20686162656E2065696E65204368616E63652C204575726520476573636877696E6469676B6569742C2045757265205665726D656964756E6720756E6420457572656E204C6562656E7372617562202432353638313864206C616E6720756D20243235363831387331207A7520657268C3B668656E2E0D0A0D0A7C634646464646464646416D616E277468756C73205072616368747C720D0A57656E6E2045756368206461732050616E7468656F6E204D61636874207665726C656968742C2077697264204575726520243F28613133373030357C613133373034377C613133373032387C61313337303237295B5374C3A4726B655D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295B42657765676C6963686B6569745D5B496E74656C6C6967656E7A5D202432353638333264206C616E6720756D2024323536383332733120657268C3B668742E0000, 40944),
(3776013982, 247692, 'deDE', 0x00457268C3B668742045757265204368616E63652C2065696E6520416E64656E6B656E73636861636874656C206175732053616E64656E20646572205A656974207A7520657262657574656E2E20416E64656E6B656E73636861636874656C6E20656E7468616C74656E206DC3A463687469676520476567656E7374C3A46E64652C206469652064656E205363687769657269676B656974736772616420766F6E204368726F6E6F706F7274616C686572617573666F72646572756E67656E20737461726B2076657272696E6765726E2E0D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B6687420646965204265776567756E67732D20756E642052656974676573636877696E6469676B65697420756D20247332252E004368616E636520657268C3B668742C2065696E6520416E64656E6B656E73636861636874656C206175732053616E64656E20646572205A656974207A7520657262657574656E2E20416E64656E6B656E73636861636874656C6E20656E68616C74656E206DC3A463687469676520476567656E7374C3A46E64652C206469652064656E205363687769657269676B656974736772616420766F6E204368726F6E6F706F7274616C686572617573666F72646572756E67656E20737461726B2076657272696E6765726E2E0D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B6687420646965204265776567756E67732D20756E642052656974676573636877696E6469676B65697420756D20247332252E00, 40944),
(3776013982, 247111, 'deDE', 0x00457268C3B668742045757265204368616E63652C2065696E656E2042726F6E7A656472616368656E206175732053616E64656E20646572205A656974207A7520676577696E6E656E2E20446965736572204472616368652073C3A4756265727420736F666F72742065696E656E204472616368656E7363687265696E2066C3BC7220457563682E0D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B66874205363686164656E20756E64204865696C756E6720756D20247332252E004368616E636520657268C3B668742C2065696E656E2042726F6E7A656472616368656E206175732053616E64656E20646572205A656974207A7520676577696E6E656E2E20446965736572204472616368652073C3A4756265727420736F666F72742065696E656E204472616368656E7363687265696E2066C3BC7220457563682E0D0A0D0A7C634646303046463030426F6E75733A7C72205363686164656E20756E64204865696C756E6720756D202473322520657268C3B668742E00, 40944),
(3776013982, 247110, 'deDE', 0x00536368616C74657420506F7274616C6520766F6D205779726D72756874656D70656C207A7520616C6C656E204472616368656E7363687265696E656E20667265692E0D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B6687420646965204265776567756E67732D20756E642052656974676573636877696E6469676B65697420756D20247332252E00536368616C74657420506F7274616C6520766F6D205779726D72756874656D70656C207A7520616C6C656E204472616368656E7363687265696E656E20667265692E0D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B6687420646965204265776567756E67732D20756E642052656974676573636877696E6469676B65697420756D20247332252E00, 40944),
(3776013982, 247104, 'deDE', 0x00457268C3B6687420646965204265776567756E67732D20756E642052656974676573636877696E6469676B65697420756D20247331252E0D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B66874205363686164656E20756E64204865696C756E6720756D20247332252E004265776567756E67732D20756E642052656974676573636877696E6469676B65697420756D202473312520657268C3B668742E0D0A0D0A7C634646303046463030426F6E75733A7C72205363686164656E20756E64204865696C756E6720756D202473322520657268C3B668742E00, 40944),
(3776013982, 247103, 'deDE', 0x0024407370656C6C646573633234343935390D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B66874205363686164656E20756E64204865696C756E6720756D2035252E0000, 40944),
(3776013982, 247099, 'deDE', 0x00457268C3B6687420457572656E205275667A7577616368732064757263682067656D65696E73616D206D6974204368726F6D696520676574C3B674657465204765676E657220696E2064656E206C65747A74656E20243234373736396420756D202432343737363973312520756E6420696E2064656E206C65747A74656E20243234373737306420756D20243234373737307331252E0D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B6687420646965204265776567756E67732D20756E642052656974676573636877696E6469676B65697420756D20247332252E0000, 40944),
(3776013982, 247096, 'deDE', 0x000000, 40944),
(3776013982, 247094, 'deDE', 0x00457268C3B668742045757265204368616E63652C2053616E646520646572205A656974207A752066696E64656E2C20756D20247331252E0D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B668742064696520476573756E646865697420756D20247332252E004368616E63652C2053616E646520646572205A656974207A752066696E64656E2C20756D202473312520657268C3B668742E0D0A0D0A7C634646303046463030426F6E75733A7C72204865696C756E6720756D202473322520657268C3B668742E00, 40944),
(3776013982, 247093, 'deDE', 0x000000, 40944),
(3776013982, 247092, 'deDE', 0x000000, 40944),
(3776013982, 247089, 'deDE', 0x0024407370656C6C646573633234353530330D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B66874205363686164656E2C204865696C756E6720756E6420476573756E646865697420736F77696520646965204265776567756E67732D20756E642052656974676573636877696E6469676B65697420756D20247332252E0000, 40944),
(3776013982, 247088, 'deDE', 0x004368726F6D696520656E7468C3BC6C6C742053636861747A6B697374656E20696E20646572204EC3A468652E0D0A0D0A7C634646303046463030426F6E75733A7C7220457268C3B66874205363686164656E20756E64204865696C756E6720756D20247332252E004368726F6D696520656E7468C3BC6C6C742053636861747A6B697374656E20696E20646572204EC3A468652E0D0A0D0A7C634646303046463030426F6E75733A7C72205363686164656E20756E64204865696C756E6720756D202473322520657268C3B668742E00, 40944),
(3479059991, 9040, 'deDE', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'deDE', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'deDE', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'deDE', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'deDE', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'deDE', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'deDE', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'deDE', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'deDE', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'deDE', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'deDE', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'deDE', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'deDE', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'deDE', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'deDE', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'deDE', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'deDE', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'deDE', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'deDE', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'deDE', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'deDE', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'deDE', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'deDE', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'deDE', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'deDE', 0x0024407370656C6C64657363323238383239005665727572736163687420616C6C65202432323838323974312053656B2E202473312046657565727363686164656E2E00, 40944),
(3776013982, 227799, 'deDE', 0x00576173736572776F67656E20726175736368656E20766F6E2064656E2053656974656E20646573205261756D657320686572616E20756E642066C3BC67656E20616C6C656E20766F6E2069686E656E20676574726F6666656E656E20537069656C657263686172616B746572656E202473312046726F73747363686164656E207A752E0000, 40944),
(3776013982, 227780, 'deDE', 0x004D61726B6965727420616C6C6520537069656C657263686172616B74657265206D6974202724407370656C6C6E616D65323237373830272E2046C3BC6774206265692041626C61756620616C6C656E20537069656C657263686172616B746572656E20696E6E657268616C6220766F6E20244131204D657465726E20247331204E617475727363686164656E207A752E0046C3BC6774206265692041626C61756620616C6C656E20537069656C657263686172616B746572656E20696E6E657268616C6220766F6E20244131204D657465726E20247331204E617475727363686164656E207A752E00, 40944),
(3386291891, 116804, 'deDE', 0x537A656E656E616B7465757200000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'deDE', 0x45727A6D6167696572204B686164676172000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'deDE', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'deDE', 0x4E69656C6173204172616E0000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'deDE', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'deDE', 0x446572204B757261746F72000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'deDE', 0x00C39666666E6574204575726520416E68C3A46E676572C3BC626572736963687420756E642077C3A4686C742065696E656E20416E68C3A46E676572206175732C20756D207365696E652053747566652061756620247331207A75207365747A656E2E0000, 40944),
(261693969, 60399, 'deDE', 0xFFFFFFFFFFFFFFFF48696C66652066C3BC7220526576656E647265746800003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'deDE', 0xFFFFFFFFFFFFFFFF48696C66652066C3BC72204D616C6472617878757300003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'deDE', 0xFFFFFFFFFFFFFFFF48696C66652066C3BC72206469652042617374696F6E00003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'deDE', 0xFFFFFFFFFFFFFFFF48696C66652066C3BC722064656E20417264656E77616C6400003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'deDE', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'deDE', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'deDE', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'deDE', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'deDE', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'deDE', 0x00000000, 40944),
(3865974254, 176921, 'deDE', 0x00000000, 40944),
(3865974254, 176832, 'deDE', 0x00000000, 40944),
(3776013982, 243328, 'deDE', 0x000056657272696E676572746520426564726F68756E672E00, 40944),
(3865974254, 187935, 'deDE', 0x00000000, 40944),
(3205218938, 44300, 'deDE', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F580041757468656E74696361746F7220756E6420534D532D4163636F756E7473636875747A207A756D204163636F756E742068696E7A7566C3BC67656E2C20756D206469657365732046656C64207A7520656E747370657272656E0001, 40944),
(3205218938, 44299, 'deDE', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C636666666630303030446572204163636F756E74206D757373206D69742064656D20426174746C652E6E65742041757468656E74696361746F7220756E642064656D20534D532D4163636F756E7473636875747A20676573696368657274207365696E2C20756D2065696E6520477275707065206F686E65205363686CC3BC7373656C737465696E2066C3BC72204D797468697363682B20616E7A756D656C64656E2E7C727C6E7C6366663165666630303C46C3BC72207765697465726520496E666F726D6174696F6E656E206B6C69636B656E3E7C720001, 40944),
(3205218938, 44284, 'deDE', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C636666666630303030446572204163636F756E74206D757373206D69742064656D20426174746C652E6E65742041757468656E74696361746F7220756E642064656D20534D532D4163636F756E7473636875747A20676573696368657274207365696E2C20756D206469657365732046656C64206265617262656974656E207A75206BC3B66E6E656E2E7C727C6E7C6366663165666630303C46C3BC72207765697465726520496E666F726D6174696F6E656E206B6C69636B656E3E7C720001, 40944),
(3205218938, 44283, 'deDE', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F4445534300457268616C74657420766F6C6C7374C3A46E646967656E205A7567726966662061756620646965204772757070656E737563686520696D2044756E67656F6E62726F777365722C20696E64656D2049687220457572656E204163636F756E74206D69742064656D20426174746C652E6E65742041757468656E74696361746F7220756E642064656D20534D532D4163636F756E7473636875747A20736963686572742E7C6E7C6E44657220426174746C652E6E65742041757468656E74696361746F72206973742065696E206B6F7374656E6C6F73657220756E6420756E6B6F6D706C697A69657274657220536572766963652C2064657220457572656E204163636F756E7420766F72204672656D64656E20736368C3BC747A742C20756E642064657220534D532D4163636F756E7473636875747A207465696C742045756368206D69742C2077656E6E20616E20457572656D204163636F756E7420776963687469676520C3846E646572756E67656E20766F7267656E6F6D6D656E2077657264656E2E7C6E7C6E4B6C69636B74206175662022416B746976696572656E222C20756D20646965205765627365697465207A75722045696E7269636874756E67206465732041757468656E74696361746F7273207A7520C3B666666E656E2E0001, 40944),
(3776013982, 358927, 'deDE', 0x00576572646574206D697373747261756973636820676567656EC3BC62657220616C6C656E20696E20457572657220556D676562756E672E2056657272696E67657274652041626B6C696E677A6569742066C3BC72204E616368746765626F72656E652E004D697373747261757420616C6C656E20696E20457572657220556D676562756E672E00, 40944),
(3865974254, 188152, 'deDE', 0x00000000, 40944),
(3776013982, 53385, 'deDE', 0x00456E7466657373656C742065696E656E2057697262656C2067C3B674746C696368657220456E65726769652C2064657220616C6C656E204765676E65726E20696E20646572204EC3A4686520247331204865696C69677363686164656E207A7566C3BC67742E2046C3BC6774205A69656C656E20C3BC62657220247332205A69656C652068696E6175732076657272696E67657274656E205363686164656E207A752E0000, 40944),
(261693969, 62694, 'deDE', 0xFFFFFFFFFFFFFFFF45696E2052756620617573204D616C64726178787573000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'deDE', 0xFFFFFFFFFFFFFFFF45696E20527566206175732064656D20417264656E77616C64000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'deDE', 0xFFFFFFFFFFFFFFFF45696E2052756620617573206465722042617374696F6E000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'deDE', 0xFFFFFFFFFFFFFFFF45696E205275662061757320526576656E6472657468000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'deDE', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'deDE', 0x000000, 40944),
(3776013982, 307934, 'deDE', 0x000000, 40944),
(3776013982, 307480, 'deDE', 0x00576972667420457572656E2067657265696674656E204772C3A46265722E0000, 40944),
(2948698321, 354, 'deDE', 0x64DF8D9146629CB2, 40944),
(261693969, 60111, 'deDE', 0xFFFFFFFFFFFFFFFF45696E6520467265756E64736368616674207363686D696564656E00005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'deDE', 0xFFFFFFFFFFFFFFFF4E75722065696E206B6C65696E657220467265756E64736368616674736469656E737420766F6E206D697200005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'deDE', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'deDE', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'deDE', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'deDE', 0x00000000, 40944),
(3865974254, 151804, 'deDE', 0x00000000, 40944),
(3865974254, 151792, 'deDE', 0x00000000, 40944),
(3037505077, 151792, 'deDE', 0x0100, 40944),
(3865974254, 151790, 'deDE', 0x00000000, 40944),
(3037505077, 151790, 'deDE', 0x0100, 40944),
(3865974254, 146306, 'deDE', 0x00000000, 40944),
(3865974254, 34685, 'deDE', 0x00000000, 40944),
(3865974254, 34683, 'deDE', 0x00000000, 40944),
(3865974254, 34087, 'deDE', 0x00000000, 40944),
(3865974254, 34085, 'deDE', 0x00000000, 40944),
(3865974254, 33969, 'deDE', 0x00000000, 40944),
(3865974254, 33968, 'deDE', 0x00000000, 40944),
(3865974254, 33967, 'deDE', 0x00000000, 40944),
(3865974254, 33966, 'deDE', 0x00000000, 40944),
(3865974254, 33868, 'deDE', 0x00000000, 40944),
(3865974254, 33864, 'deDE', 0x00000000, 40944),
(3865974254, 33863, 'deDE', 0x00000000, 40944),
(3865974254, 33862, 'deDE', 0x00000000, 40944),
(3865974254, 23324, 'deDE', 0x00000000, 40944),
(3865974254, 21525, 'deDE', 0x00000000, 40944),
(3865974254, 21524, 'deDE', 0x00000000, 40944),
(3865974254, 19028, 'deDE', 0x00000000, 40944),
(3865974254, 6835, 'deDE', 0x00000000, 40944),
(3865974254, 6833, 'deDE', 0x00000000, 40944),
(3865974254, 181321, 'deDE', 0x00000000, 40944),
(1548466975, 27672, 'deDE', 0x10040000, 40944),
(3776013982, 365080, 'deDE', 0x00004265776567756E6773676573636877696E6469676B65697420756D202473312520657268C3B668742E00, 40944),
(3776013982, 317920, 'deDE', 0x0044696520446175657220766F6E20556E7465726272656368756E67732D20756E64205374696C6C65656666656B74656E20626569204772757070656E2D20756E64205363686C616368747A7567736D6974676C69656465726E20696E6E657268616C6220766F6E20246131204D657465726E2069737420756D20247331252076657272696E676572742E243F733333393132345B2044696520446175657220766F6E20467572636874656666656B74656E20697374206562656E66616C6C732076657272696E676572742E5D5B5D00446175657220766F6E20556E7465726272656368756E67732D20756E64205374696C6C65656666656B74656E20756D20247731252076657272696E676572742E243F733333393132345B20446175657220766F6E20467572636874656666656B74656E20756D20247734252076657272696E676572742E5D5B5D00, 40944),
(3776013982, 465, 'deDE', 0x004772757070656E2D20756E64205363686C616368747A7567736D6974676C696564657220696E6E657268616C6220766F6E20246131204D657465726E2077657264656E20647572636820696872652048696E676162652067657374C3A4726B742C20776F64757263682073696368206968722065726C697474656E6572205363686164656E20756D20247331252076657272696E676572742E0045726C697474656E6572205363686164656E20756D20247731252076657272696E676572742E00, 40944),
(3205218938, 44172, 'deDE', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F444553430045727265696368742065696E652057657274756E6720766F6E20312E393530206F6465722068C3B668657220756E6420657268616C7465743A7C6E2D205076502D476567656E7374616E647361756677657274756E677372616E670001, 40944),
(3205218938, 40887, 'deDE', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F444553430045727265696368742065696E652057657274756E6720766F6E2031383030206F6465722068C3B668657220756E6420657268616C7465743A7C6E2D20546974656C3A20526976616C657C6E2D20456C6974652D5076502D536574766F726C6167653A2048656C6D7C6E2D20456C6974652D5076502D536574766F726C6167653A20536368756C74657273636875747A0001, 40944),
(3205218938, 40885, 'deDE', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F444553430045727265696368742065696E652057657274756E6720766F6E2031343030206F6465722068C3B668657220756E6420657268616C7465743A7C6E2D20546974656C3A20486572617573666F7264657265727C6E2D20456C6974652D5076502D536574766F726C6167653A2048616E647363687568657C6E2D20456C6974652D5076502D536574766F726C6167653A205374696566656C0001, 40944),
(3776013982, 357407, 'deDE', 0x00426573636877C3B6727420756E64207374657565727420457572656E20726F636B656E64656E2052656E6E7261736572204D617261756465722E0042656E75747A742064696520416B74696F6E736C65697374652C20756D20616E64657265206665726E6765737465756572746520537069656C7A6575676520616E7A756772656966656E2E00, 40944),
(3776013982, 357406, 'deDE', 0x00426573636877C3B6727420756E64207374657565727420457572656E20726F636B656E64656E2052656E6E7261736572204D617261756465722E0042656E75747A742064696520416B74696F6E736C65697374652C20756D20616E64657265206665726E6765737465756572746520537069656C7A6575676520616E7A756772656966656E2E00, 40944),
(3776013982, 357405, 'deDE', 0x00426573636877C3B6727420756E64207374657565727420457572656E20726F636B656E64656E2052656E6E7261736572204D617261756465722E0042656E75747A742064696520416B74696F6E736C65697374652C20756D20616E64657265206665726E6765737465756572746520537069656C7A6575676520616E7A756772656966656E2E00, 40944),
(3776013982, 356631, 'deDE', 0x00426573636877C3B6727420756E64207374657565727420457572656E20726F636B656E64656E2052656E6E72617365722041697220426C6164652E0042656E75747A742064696520416B74696F6E736C65697374652C20756D20616E64657265206665726E6765737465756572746520537069656C7A6575676520616E7A756772656966656E2E00, 40944),
(3776013982, 328923, 'deDE', 0x4E6163687466616500C39C6265727472C3A4677420646965204C6562656E736B7261667420766F6E20626973207A75202433323839323849204765676E65726E20696D205A69656C6265726569636820756E64207665727572736163687420696D205665726C61756620766F6E20246420247B282433323839323873312A24642F24743229202B202433323839323873317D204E617475727363686164656E2C2064696520676C656963686DC3A4C39F69672061756620616C6C65206765676E657269736368656E205A69656C652061756667657465696C742077657264656E2E243F613133373034315B0D0A0D0A57656E6E20274661657472616E73667573696F6E2720766F6C6C7374C3A46E646967206B616E616C69736965727420776972642C2065727A6575677420496872202473342053746170656C20766F6E2027576166666520646573204D61686C7374726F6D73272E5D5B5D0D0A0D0A57656E6E2049687220274661657472616E73667573696F6E2720696E6E657268616C6220766F6E2024333238393333642065726E6575742065696E7365747A742C2077657264656E20247331252064657320676573616D74656E205363686164656E7320766F6E20274661657472616E73667573696F6E27206672656967657365747A7420756E64206865696C656E20626973207A75202433323839333073322056657262C3BC6E6465746520696E6E657268616C6220766F6E20243332383933304131204D657465726E2E0000, 40944),
(3776013982, 101546, 'deDE', 0x00496872206472656874204575636820696E20646572204C7566742C2077C3A46872656E6420496872205472697474652061757366C3BC6872742C2064696520616C6C656E204765676E65726E20696E6E657268616C6220766F6E20243130373237304131204D657465726E20696D205665726C61756620766F6E20246420243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5D206BC3B6727065726C696368656E205363686164656E207A7566C3BC67656E2E2046C3BC6774205A69656C656E20C3BC62657220247331205A69656C652068696E6175732076657272696E67657274656E205363686164656E207A752E243F63335B0D0A0D0A446572205363686164656E20766F6E202757697262656C6E646572204B72616E69636874726974742720776972642066C3BC72206A656465732065696E7A656C6E65205A69656C2C206461732049687220696E6E657268616C6220646572206C65747A74656E202432323033353864206D6974202754696765726B6C617565272C2027426C61636B6F75742D547269747427206F646572202754726974742064657220617566676568656E64656E20536F6E6E652720676574726F6666656E20686162742C20756D202432323033353873312520657268C3B668742E20426973207A752024323238323837692D6D616C2073746170656C6261722E5D5B5D00477265696674204765676E657220696E20646572204EC3A4686520616E20756E642066C3BC67742069686E656E20616C6C65202431303135343674312053656B2E206BC3B6727065726C696368656E205363686164656E207A752E00, 40944),
(3865974254, 188220, 'deDE', 0x00000000, 40944),
(3865974254, 187900, 'deDE', 0x00000000, 40944),
(3865974254, 187899, 'deDE', 0x00000000, 40944),
(3865974254, 187898, 'deDE', 0x00000000, 40944),
(3865974254, 187897, 'deDE', 0x00000000, 40944),
(3865974254, 187896, 'deDE', 0x00000000, 40944),
(3865974254, 187895, 'deDE', 0x00000000, 40944),
(3865974254, 187875, 'deDE', 0x00000000, 40944),
(3865974254, 187869, 'deDE', 0x00000000, 40944),
(3865974254, 150746, 'deDE', 0x00000000, 40944),
(3865974254, 150745, 'deDE', 0x00000000, 40944),
(3865974254, 150744, 'deDE', 0x00000000, 40944),
(3865974254, 150743, 'deDE', 0x00000000, 40944),
(3776013982, 364944, 'deDE', 0x00004265776567756E6773676573636877696E6469676B65697420756D202473312520657268C3B668742E00, 40944),
(3776013982, 228462, 'deDE', 0x00457268C3B668742064656E205363686164656E204575726572206175746F6D617469736368656E20416E67726966666520756D202473312E0000, 40944),
(3776013982, 119611, 'deDE', 0x0024407370656C6C6465736331313531353100526567656E65726965727420616C6C65202474312053656B2E2024773120476573756E64686569742E00, 40944),
(3776013982, 119607, 'deDE', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'deDE', 0x00000000, 40944),
(1181150530, 403396, 'deDE', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'deDE', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'deDE', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'deDE', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'deDE', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'deDE', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'deDE', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'deDE', 0xA4530000, 40944),
(3359787322, 21411, 'deDE', 0xA3530000, 40944),
(3359787322, 21410, 'deDE', 0xA2530000, 40944),
(3359787322, 21409, 'deDE', 0xA1530000, 40944),
(3359787322, 21408, 'deDE', 0xA0530000, 40944),
(3359787322, 21407, 'deDE', 0x9F530000, 40944),
(3359787322, 21406, 'deDE', 0x9E530000, 40944),
(2557447376, 655518, 'deDE', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'deDE', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'deDE', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'deDE', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'deDE', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'deDE', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F45464645435400547261646974696F6E656C6C65204265757465726567656C6E2067656C74656E206E69636874206CC3A46E6765722E0001, 40944),
(3776013982, 347944, 'deDE', 0x00457268C3B6687420646965206B726974697363686520547265666665726368616E636520756D20247331252E0D0A004B726974697363686520547265666665726368616E636520756D202473312520657268C3B668742E00, 40944),
(3776013982, 347943, 'deDE', 0x00457268C3B6687420646965206D6178696D616C6520476573756E646865697420756D20247331252E0D0A004D6178696D616C6520476573756E646865697420756D202473312520657268C3B668742E00, 40944),
(3776013982, 1714, 'deDE', 0x005A77696E677420646173205A69656C2C2044C3A46D6F6E69736368207A7520737072656368656E2C20776F647572636820646965205A61756265727A65697420616C6C6572205A61756265722066C3BC7220246420756D202473312520657268C3B6687420776972642E243F733130333131325B0D0A0D0A7C4346464535354242305365656C656E6272616E643A20457565722027466C7563682064657220537072616368656E2720626574726966667420616C6C65204765676E657220696E6E657268616C6220766F6E202431303432323441204D657465726E20766F6E20457572656D205A69656C2E7C525D5B5D0D0A0D0A7C634646383238324646466CC3BC6368653A2045696E20486578656E6D656973746572206B616E6E20617566206A6564656D205A69656C206E75722065696E656E20466C75636820616B74697620686162656E2E7C720044617320537072656368656E206465722064C3A46D6F6E69736368656E205370726163686520657268C3B6687420646965205A61756265727A65697420756D20247731252E00, 40944),
(3205218938, 41865, 'deDE', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E530045756368206665686C74206469652045726C6175626E69732C206469652052656B727574696572756E6773696E666F726D6174696F6E656E207A752065646974696572656E2E0001, 40944),
(261693969, 64850, 'deDE', 0xFFFFFFFFFFFFFFFF54616B74696B656E20766F6E20546F726768617374000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'deDE', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='deDE') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='deDE');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'deDE' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `achievement_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (14775,14752,14682,14351));
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14775, 'esES', 'Alcanza la reputación Exaltado con Marasmius.', 'Te aprecio un champiñón', 'Título de recompensa: El Divertido / La Divertida', 40944),
(14752, 'esES', 'Completa los siguientes logros de costura abominable.', 'Qué hacer cuando has muerto', 'Título de recompensa: Abominable y recompensa: montura tauralus elegido acorazado', 40944),
(14682, 'esES', 'Completa los siguientes logros de la Corte de Ascuas.', 'Heraldo de la fiesta', 'Título de recompensa: Heraldo de la fiesta', 40944),
(14351, 'esES', 'Derrota a 39 jefes en el camino de la ascensión.', 'El camino hacia la ascensión 39', 'Desbloquea más desafíos en el camino de la ascensión.', 40944);


DELETE FROM `area_table_locale` WHERE (`VerifiedBuild`>0 AND `ID`=13316 AND `locale`='esES');
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(13316, 'esES', 'Casa de los Rituales', 40944);


DELETE FROM `battle_pet_species_locale` WHERE (`VerifiedBuild`>0 AND `ID`=3188 AND `locale`='esES');
INSERT INTO `battle_pet_species_locale` (`ID`, `locale`, `Description_lang`, `SourceText_lang`, `VerifiedBuild`) VALUES
(3188, 'esES', '', '', 40944);


DELETE FROM `broadcast_text_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (215513,215512,215511));
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(215513, 'esES', '', 'No es buena idea aventurarse en Las Fauces sin preparación. Vuelve cuando estés lista.', 40944),
(215512, 'esES', 'No es buena idea aventurarse en Las Fauces sin preparación. Vuelve cuando estés listo.', '', 40944),
(215511, 'esES', '', 'Estamos muy cerca. Lucha a mi lado y saldremos de esta.', 40944);


DELETE FROM `char_titles_locale` WHERE (`VerifiedBuild`>0 AND `ID`=693 AND `locale`='esES');
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(693, 'esES', '%s el Ascendido', '%s la Ascendida', 40944);


UPDATE `char_titles_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=683 AND `locale`='esES');
DELETE FROM `chr_customization_option_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (1523,689));
INSERT INTO `chr_customization_option_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1523, 'esES', 'Cola', 40944),
(689, 'esES', 'Cola', 40944);


DELETE FROM `criteria_tree_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (91730,94390,94389,94388,93811,93810,94331,94330));
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91730, 'esES', '9.1 Logro meta', 40944),
(94390, 'esES', '', 40944),
(94389, 'esES', '', 40944),
(94388, 'esES', '', 40944),
(93811, 'esES', '', 40944),
(93810, 'esES', 'Nivel de renombre 80', 40944),
(94331, 'esES', '', 40944),
(94330, 'esES', 'Renown Level 80 - Kyrian', 40944);


DELETE FROM `item_search_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,116401));
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(151806, 'esES', 'Vestido elegante', 40944),
(151804, 'esES', 'Pantalones de esmoquin negro', 40944),
(151792, 'esES', 'Ropa de invierno verde', 40944),
(151790, 'esES', 'Ropa de invierno roja', 40944),
(34685, 'esES', 'Vestimentas estivales', 40944),
(34683, 'esES', 'Sandalias estivales', 40944),
(34087, 'esES', 'Ropa de invierno verde', 40944),
(34085, 'esES', 'Ropa de invierno roja', 40944),
(33969, 'esES', 'Sombrero de la Fiesta de la Cerveza morado', 40944),
(33968, 'esES', 'Sombrero de la Fiesta de la Cerveza azul', 40944),
(33967, 'esES', 'Sombrero de la Fiesta de la Cerveza verde', 40944),
(33966, 'esES', 'Zapatillas de la Fiesta de la Cerveza', 40944),
(33868, 'esES', 'Botas de la Fiesta de la Cerveza', 40944),
(33864, 'esES', 'Sombrero de la Fiesta de la Cerveza marrón', 40944),
(33863, 'esES', 'Traje de la Fiesta de la Cerveza', 40944),
(33862, 'esES', 'Atavío de la Fiesta de la Cerveza', 40944),
(23324, 'esES', 'Manto del Festival del Fuego', 40944),
(21525, 'esES', 'Sombrero de invierno verde', 40944),
(21524, 'esES', 'Sombrero de invierno rojo', 40944),
(19028, 'esES', 'Vestido elegante', 40944),
(6835, 'esES', 'Pantalones de esmoquin negro', 40944),
(6833, 'esES', 'Camisa de esmoquin blanca', 40944),
(181321, 'esES', 'Varita coronada con gemas', 40944),
(116401, 'esES', 'Sombrero de peregrino excelente', 40944);


DELETE FROM `item_sparse_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (176922,176921,176832,187935,188152,151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,188220,187900,187899,187898,187897,187896,187895,187875,187869,150746,150745,150744,150743,116401));
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(176922, 'esES', 'Esta flor mágica aumenta un 100% tanto la producción de materiales de los espíritus renacidos como la cantidad de catalizadores que brotan de las semillas catalizadoras.', '', '', '', 'Flor nocturna silvestre', 40944),
(176921, 'esES', 'Estas hojas encantadas reducen 1 día la duración del proceso de la semilla silvestre de recrecimiento.', '', '', '', 'Hojas temporales', 40944),
(176832, 'esES', 'Esta raíz especial aumenta la calidad de las recompensas que un espíritu ofrece al renacer.', '', '', '', 'Grano de raíz de semilla silvestre', 40944),
(187935, 'esES', 'Te enseña a fabricar una marca del venado rúnico de medianoche.', '', '', '', 'Técnica: Marca del venado rúnico de medianoche', 40944),
(188152, 'esES', 'La magia del fragmento quema al tacto.', '', '', '', 'Fragmento de control de portal', 40944),
(151806, 'esES', '', '', '', '', 'Vestido elegante', 40944),
(151804, 'esES', '', '', '', '', 'Pantalones de esmoquin negro', 40944),
(151792, 'esES', '', '', '', '', 'Ropa de invierno verde', 40944),
(151790, 'esES', '', '', '', '', 'Ropa de invierno roja', 40944),
(34685, 'esES', '', '', '', '', 'Vestimentas estivales', 40944),
(34683, 'esES', '', '', '', '', 'Sandalias estivales', 40944),
(34087, 'esES', '', '', '', '', 'Ropa de invierno verde', 40944),
(34085, 'esES', '', '', '', '', 'Ropa de invierno roja', 40944),
(33969, 'esES', '', '', '', '', 'Sombrero de la Fiesta de la Cerveza morado', 40944),
(33968, 'esES', '', '', '', '', 'Sombrero de la Fiesta de la Cerveza azul', 40944),
(33967, 'esES', '', '', '', '', 'Sombrero de la Fiesta de la Cerveza verde', 40944),
(33966, 'esES', '', '', '', '', 'Zapatillas de la Fiesta de la Cerveza', 40944),
(33868, 'esES', '', '', '', '', 'Botas de la Fiesta de la Cerveza', 40944),
(33864, 'esES', '', '', '', '', 'Sombrero de la Fiesta de la Cerveza marrón', 40944),
(33863, 'esES', '', '', '', '', 'Traje de la Fiesta de la Cerveza', 40944),
(33862, 'esES', '', '', '', '', 'Atavío de la Fiesta de la Cerveza', 40944),
(23324, 'esES', '', '', '', '', 'Manto del Festival del Fuego', 40944),
(21525, 'esES', '', '', '', '', 'Sombrero de invierno verde', 40944),
(21524, 'esES', '', '', '', '', 'Sombrero de invierno rojo', 40944),
(19028, 'esES', '', '', '', '', 'Vestido elegante', 40944),
(6835, 'esES', '', '', '', '', 'Pantalones de esmoquin negro', 40944),
(6833, 'esES', '', '', '', '', 'Camisa de esmoquin blanca', 40944),
(181321, 'esES', '', '', '', '', 'Varita coronada con gemas', 40944),
(188220, 'esES', 'Tiene inhcritah lah palabrah \"He sobrevivido a la torre\" debajo.', '', '', '', 'Esfera de ceniza de Torghast', 40944),
(187900, 'esES', 'Un goblin y un gnomo describen sus múltiples descubrimientos por las dos islas.', '', '', '', 'Mapa de exploración: Las maravillas de Kul Tiras y Zandalar', 40944),
(187899, 'esES', 'Descripción de los diversos biomas y la increíble flora de Terrallende realizada por un intrépido alquimista.', '', '', '', 'Mapa de exploración: Las muchas curiosidades de Terrallende', 40944),
(187898, 'esES', 'Informe detallado de un cruzado Argenta sobre todas las operaciones militares realizadas en pos del Rey Exánime.', '', '', '', 'Mapa de exploración: El verdadero coste de la campaña de Rasganorte', 40944),
(187897, 'esES', 'Un peculiar informe de varias facciones que recopila las incontables consecuencias del ataque de Alamuerte contra Azeroth.', '', '', '', 'Mapa de exploración: Consecuencias del Cataclismo', 40944),
(187896, 'esES', 'La alegre historia de las últimas aventuras de Li Li por Pandaria. Incluye recomendaciones gastronómicas de su tío Chen.', '', '', '', 'Mapa de exploración: Guía de Pandaria de los Cerveza de Trueno', 40944),
(187895, 'esES', 'Una lista de los pocos lugares seguros que hay en Draenor y de las costumbres locales que harías bien en observar en cada uno de ellos.', '', '', '', 'Mapa de exploración: Los peligros de Draenor', 40944),
(187875, 'esES', 'Una gran colección de informes y correspondencia de las diversas unidades militares que luchan contra la Legión.', '', '', '', 'Mapa de exploración: Frentes unidos de las Islas Abruptas', 40944),
(187869, 'esES', 'La historia detallada del viaje de un Caminante de Las Fauces a través de cuatro reinos de las Tierras Sombrías.', '', '', '', 'Mapa de exploración: Hacia las Tierras Sombrías', 40944),
(150746, 'esES', 'Una modesta propuesta para proveer de suministros a tiempo a las avanzadas de los Reinos del Este.', '', '', '', 'Mapa de exploración: Aprovisionamiento moderno de los Reinos del Este', 40944),
(150745, 'esES', 'Una estrategia detallada para mermar rápidamente las tropas de la Alianza en los Reinos del Este si se produjera la Cuarta Guerra.', '', '', '', 'Mapa de exploración: La campaña de los Reinos del Este', 40944),
(150744, 'esES', 'Cómo sanar las cicatrices de la tierra causadas por la maldad, la corrupción y lo antinatural.', '', '', '', 'Mapa de exploración: Recorrer Kalimdor con la Madre Tierra', 40944),
(150743, 'esES', 'Una recopilación exhaustiva de bestias con colmillos, garras y veneno que están de parte de la Horda.', '', '', '', 'Mapa de exploración: Cómo sobrevivir en Kalimdor', 40944),
(116401, 'esES', '', '', '', '', 'Sombrero de peregrino excelente', 40944);


UPDATE `item_sparse_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (185950,185947,185946));
DELETE FROM `lfg_dungeons_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1445 AND `locale`='esES');
INSERT INTO `lfg_dungeons_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1445, 'esES', 'La caída de los Tótem Vil', 'Impide que Tugar Tótem Sangriento y sus gusanos viles desmoronen la montaña.', 40944);


DELETE FROM `map_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1756 AND `locale`='esES');
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(1756, 'esES', 'Las Muertes de Cromi', '', '', '', '', 40944);


DELETE FROM `player_condition_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (95078,95077,95076,85644,73006,73005,87365,85912,85910,85909,85692,94517,94516,94515,94514,94513,94512,94511));
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(95078, 'esES', '', 40944),
(95077, 'esES', '', 40944),
(95076, 'esES', '', 40944),
(85644, 'esES', 'Debes alcanzar el nivel $pcMinLevel para continuar.', 40944),
(73006, 'esES', '', 40944),
(73005, 'esES', '', 40944),
(87365, 'esES', '', 40944),
(85912, 'esES', '', 40944),
(85910, 'esES', '', 40944),
(85909, 'esES', '', 40944),
(85692, 'esES', '', 40944),
(94517, 'esES', '', 40944),
(94516, 'esES', '', 40944),
(94515, 'esES', '', 40944),
(94514, 'esES', '', 40944),
(94513, 'esES', '', 40944),
(94512, 'esES', '', 40944),
(94511, 'esES', '', 40944);


DELETE FROM `spell_category_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1186 AND `locale`='esES');
INSERT INTO `spell_category_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1186, 'esES', 'Class - Paladin - Hand of Sacrifice', 40944);


DELETE FROM `spell_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (361952,256817,247692,247111,247110,247104,247103,247099,247096,247094,247093,247092,247089,247088,228844,227799,227780,362986,243328,358927,53385,329902,307934,307480,365080,317920,465,357407,357406,357405,356631,328923,101546,364944,228462,119611,119607,347944,347943,1714));
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(361952, 'esES', '1000 p. de ánima', 40944),
(256817, 'esES', 'Marca de Aman\'thul', 40944),
(247692, 'esES', 'Continuo de recuerdos', 40944),
(247111, 'esES', 'Pasiva de Bendición del Vuelo Bronce', 40944),
(247110, 'esES', 'Rapidez infinita', 40944),
(247104, 'esES', 'Pasiva de Aceleración', 40944),
(247103, 'esES', 'Pasiva de Detener tiempo', 40944),
(247099, 'esES', 'Pasiva de Cronocarisma', 40944),
(247096, 'esES', 'Pasiva de Recuperación acelerada', 40944),
(247094, 'esES', 'Fortuito', 40944),
(247093, 'esES', 'Pasiva de Determinación de dragón', 40944),
(247092, 'esES', 'Pasiva de Agresión acelerada', 40944),
(247089, 'esES', 'Pasiva de Colisión de dragón', 40944),
(247088, 'esES', 'Perspicacia', 40944),
(228844, 'esES', 'Huesos ardientes', 40944),
(227799, 'esES', 'Arrastrar', 40944),
(227780, 'esES', 'Ritual del trueno', 40944),
(362986, 'esES', 'Experiencia', 40944),
(243328, 'esES', 'Desvanecerse', 40944),
(358927, 'esES', 'Vigilancia de guardia Nocheterna', 40944),
(53385, 'esES', 'Tormenta divina', 40944),
(329902, 'esES', 'Dragar', 40944),
(307934, 'esES', 'Dragar', 40944),
(307480, 'esES', 'Lanzar dragador', 40944),
(365080, 'esES', 'Caminavientos', 40944),
(317920, 'esES', 'Aura de concentración', 40944),
(465, 'esES', 'Aura de devoción', 40944),
(357407, 'esES', 'Invocar Havac', 40944),
(357406, 'esES', 'Invocar Battle Trak', 40944),
(357405, 'esES', 'Invocar Dirt Devil', 40944),
(356631, 'esES', 'Invocar Air Blade', 40944),
(328923, 'esES', 'Transfusión de sílfide', 40944),
(101546, 'esES', 'Patada giratoria de la grulla', 40944),
(364944, 'esES', 'Caminavientos', 40944),
(228462, 'esES', 'Sello de Melandrus', 40944),
(119611, 'esES', 'Niebla renovadora', 40944),
(119607, 'esES', 'Niebla renovadora', 40944),
(347944, 'esES', 'Púas de Obleron', 40944),
(347943, 'esES', 'Robustez de Obleron', 40944),
(1714, 'esES', 'Maldición de las lenguas', 40944);


DELETE FROM `transmog_set_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (2289,2287,2283,2281,2277,2275,2271,2269,2178));
INSERT INTO `transmog_set_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(2289, 'esES', 'Placas de Gladiador desencadenado', 40944),
(2287, 'esES', 'Placas de Gladiador desencadenado', 40944),
(2283, 'esES', 'Anillas de Gladiador desencadenado', 40944),
(2281, 'esES', 'Anillas de Gladiador desencadenado', 40944),
(2277, 'esES', 'Cuero de Gladiador desencadenado', 40944),
(2275, 'esES', 'Cuero de Gladiador desencadenado', 40944),
(2271, 'esES', 'Vestimenta de Gladiador desencadenado', 40944),
(2269, 'esES', 'Vestimenta de Gladiador desencadenado', 40944),
(2178, 'esES', 'Armas de los Maestros de costura', 40944);


UPDATE `transmog_set_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='esES' AND `ID` IN (2221,2220,2219,2218,2217,2216,2215,2214,2213,2212,2211,2210,2209,2208,2207,2206,2205,2204,2203,2202));
DELETE FROM `achievement_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table_locale` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_blob` WHERE (`TableHash`=2948698321 AND `RecordId`=340 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='esES') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='esES') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='esES') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='esES') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='esES') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='esES') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='esES') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='esES') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='esES') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='esES') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='esES') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='esES') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='esES') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='esES') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='esES') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='esES') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=358927 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='esES') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='esES') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='esES') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='esES') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='esES') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='esES') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='esES') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='esES') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='esES') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='esES') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='esES') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='esES') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='esES') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='esES') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='esES') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='esES') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='esES') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='esES') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='esES') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='esES') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='esES') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='esES') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='esES') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='esES') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='esES') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='esES') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='esES') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='esES') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='esES') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='esES') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='esES') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='esES') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='esES') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='esES') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='esES') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='esES');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(2948698321, 340, 'esES', 0xA53E23C86B3D8F59, 40944),
(261693969, 65165, 'esES', 0xFFFFFFFFFFFFFFFF41706F796F20646573646520656C20616C6D61000044AC546F010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000000000000, 40944),
(3776013982, 361952, 'esES', 0x0041C3B16164652024733120702E20646520C3A16E696D612061206C6120726573657276612064652074752063757269612061637475616C2E0000, 40944),
(3776013982, 256817, 'esES', 0x005475732068656368697A6F73207920666163756C7461646573207469656E656E20756E612070726F626162696C69646164206465206F746F7267617274652024323536383138733120702E2064652076656C6F63696461642C206576617369C3B36E207920726573746974756369C3B36E20647572616E74652024323536383138642E0D0A0D0A7C6346464646464646464772616E64657A6120646520416D616E277468756C7C720D0A4D69656E7472617320657374C3A17320706F74656E636961646F20706F7220656C2050616E7465C3B36E2C20747520243F28613133373030357C613133373034377C613133373032387C61313337303237295B667565727A615D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295B6167696C696461645D5B696E74656C6563746F5D2061756D656E74612024323536383332733120702E20647572616E74652024323536383332642E0000, 40944),
(3776013982, 247692, 'esES', 0x005469656E657320756E61206D61796F722070726F626162696C69646164206465206F6274656E657220756E612063616A6120646520726563756572646F73207065726469646120656E20656C207469656D706F2E204C61732063616A617320646520726563756572646F7320706572646964617320656E20656C207469656D706F20636F6E7469656E656E206F626A65746F7320706F6465726F736F7320717565207265647563656E207369676E6966696361746976616D656E7465206C61206469666963756C746164206465206C6F73206465736166C3AD6F73206465206C6F732043726F6E6F706F7274616C65732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722056656C6F6369646164206465206D6F6E747572612079206D6F76696D69656E746F2061756D656E746164617320756E20247332252E005469656E657320756E61206D61796F722070726F626162696C69646164206465206F6274656E657220756E612063616A6120646520726563756572646F73207065726469646120656E20656C207469656D706F2E204C61732063616A617320646520726563756572646F7320706572646964617320656E20656C207469656D706F20636F6E7469656E656E206F626A65746F7320706F6465726F736F7320717565207265647563656E207369676E6966696361746976616D656E7465206C61206469666963756C746164206465206C6F73206465736166C3AD6F73206465206C6F732043726F6E6F706F7274616C65732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722056656C6F6369646164206465206D6F6E747572612079206D6F76696D69656E746F2061756D656E746164617320756E20247332252E00, 40944),
(3776013982, 247111, 'esES', 0x005469656E657320756E61206D61796F722070726F626162696C69646164206465206F6274656E657220756E20647261636F2042726F6E6365206465206C6173206172656E61732064656C207469656D706F2E20456C20647261636F206C696D70696172C3A120616C20696E7374616E746520756E6F206465206C6F732053616E74756172696F7320646520447261676F6E65732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C72204461C3B16F20792073616E616369C3B36E2061756D656E7461646F7320756E20247332252E005469656E657320756E61206D61796F722070726F626162696C69646164206465206F6274656E657220756E20647261636F2042726F6E6365206465206C6173206172656E61732064656C207469656D706F2E20456C20647261636F206C696D70696172C3A120616C20696E7374616E746520756E6F206465206C6F732053616E74756172696F7320646520447261676F6E65732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C72204461C3B16F20792073616E616369C3B36E2061756D656E7461646F7320756E20247332252E00, 40944),
(3776013982, 247110, 'esES', 0x00446573626C6F7175656120706F7274616C65732064656C2054656D706C6F2064656C205265706F736F2064656C2044726167C3B36E2061206361646120756E6F206465206C6F732053616E74756172696F7320646520447261676F6E65732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722056656C6F6369646164206465206D6F6E747572612079206D6F76696D69656E746F2061756D656E746164617320756E20247332252E00446573626C6F7175656120706F7274616C65732064656C2054656D706C6F2064656C205265706F736F2064656C2044726167C3B36E2061206361646120756E6F206465206C6F732053616E74756172696F7320646520447261676F6E65732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722056656C6F6369646164206465206D6F6E747572612079206D6F76696D69656E746F2061756D656E746164617320756E20247332252E00, 40944),
(3776013982, 247104, 'esES', 0x004C61732076656C6F63696461646573206465206D6F6E747572612079206D6F76696D69656E746F2061756D656E74616E20756E20247331252E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C72204461C3B16F20792073616E616369C3B36E2061756D656E7461646F7320756E20247332252E004C61732076656C6F63696461646573206465206D6F6E747572612079206D6F76696D69656E746F2061756D656E74616E20756E20247331252E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C72204461C3B16F20792073616E616369C3B36E2061756D656E7461646F7320756E20247332252E00, 40944),
(3776013982, 247103, 'esES', 0x0024407370656C6C646573633234343935390D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C72204461C3B16F20792073616E616369C3B36E2061756D656E7461646F7320756E2035252E0000, 40944),
(3776013982, 247099, 'esES', 0x0041756D656E7461206C61207265707574616369C3B36E206F6274656E69646120706F72206D75657274657320636F6E2043726F6D6920756E2024323437373639733125206375616E646F2071756564616E202432343737363964207920756E2024323437373730733125206375616E646F2071756564612024323437373730642E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722056656C6F6369646164206465206D6F6E747572612079206D6F76696D69656E746F2061756D656E746164617320756E20247332252E0000, 40944),
(3776013982, 247096, 'esES', 0x000000, 40944),
(3776013982, 247094, 'esES', 0x0041756D656E746120756E20247331252074752070726F626162696C6964616420646520656E636F6E74726172206172656E61732064656C207469656D706F2E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722053616C75642061756D656E7461646120756E20247332252E0041756D656E746120756E20247331252074752070726F626162696C6964616420646520656E636F6E74726172206172656E61732064656C207469656D706F2E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722053616C75642061756D656E7461646120756E20247332252E00, 40944),
(3776013982, 247093, 'esES', 0x000000, 40944),
(3776013982, 247092, 'esES', 0x000000, 40944),
(3776013982, 247089, 'esES', 0x0024407370656C6C646573633234353530330D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C72204461C3B16F2C2073616E616369C3B36E2C2073616C756420792076656C6F6369646164206465206D6F76696D69656E746F2079206D6F6E747572612061756D656E7461646F7320756E20247332252E0000, 40944),
(3776013982, 247088, 'esES', 0x0043726F6D6920726576656C612061727175657461732063657263616E61732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C72204461C3B16F20792073616E616369C3B36E2061756D656E7461646F7320756E20247332252E0043726F6D6920726576656C612061727175657461732063657263616E61732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C72204461C3B16F20792073616E616369C3B36E2061756D656E7461646F7320756E20247332252E00, 40944),
(3479059991, 9040, 'esES', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'esES', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'esES', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'esES', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'esES', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'esES', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'esES', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'esES', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'esES', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'esES', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'esES', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'esES', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'esES', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'esES', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'esES', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'esES', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'esES', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'esES', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'esES', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'esES', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'esES', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'esES', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'esES', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'esES', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'esES', 0x0024407370656C6C646573633232383832390024733120702E206465206461C3B16F20646520467565676F20696E666C696769646F7320636164612024323238383239743120732E00, 40944),
(3776013982, 227799, 'esES', 0x004F6C656164617320646520616775612073757267656E206465206C6F732065787472656D6F73206465206C612073616C61206520696E666C6967656E2024733120702E206465206461C3B16F2064652045736361726368612061206C6F73206A756761646F7265732061206C6F732071756520676F6C7065616E2E0000, 40944),
(3776013982, 227780, 'esES', 0x004D61726361206120746F646F73206C6F73206A756761646F72657320636F6E2024407370656C6C6E616D653232373738302E20416C2061676F74617273652C20696E666C6967652024733120702E206465206461C3B16F206465204E61747572616C657A61206120746F646F73206C6F73206A756761646F72657320656E20756E20726164696F20646520244131206D2E00416C2061676F74617273652C20696E666C6967652024733120702E206465206461C3B16F206465204E61747572616C657A61206120746F646F73206C6F73206A756761646F72657320656E20756E20726164696F20646520244131206D2E00, 40944),
(3386291891, 116804, 'esES', 0x4163746F7220646520657363656E6100000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'esES', 0x41726368696D61676F204B686164676172000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'esES', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'esES', 0x4E69656C6173204172616E0000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'esES', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'esES', 0x43757261746F72000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'esES', 0x00416272652074752070C3A167696E6120646520636F6D7061C3B165726F7320792073656C656363696F6E6120756E6F20706172612073756269726C6F20686173746120656C206E6976656C202473312E0000, 40944),
(261693969, 60399, 'esES', 0xFFFFFFFFFFFFFFFF417975646172206120526576656E647265746800003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'esES', 0xFFFFFFFFFFFFFFFF4179756461722061204D616C6472617878757300003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'esES', 0xFFFFFFFFFFFFFFFF4179756461722061204261737469C3B36E00003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'esES', 0xFFFFFFFFFFFFFFFF417975646172206120417264656E7765616C6400003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'esES', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'esES', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'esES', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'esES', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'esES', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'esES', 0x00000000, 40944),
(3865974254, 176921, 'esES', 0x00000000, 40944),
(3865974254, 176832, 'esES', 0x00000000, 40944),
(3776013982, 243328, 'esES', 0x00004E6976656C20646520616D656E617A6120726564756369646F2E00, 40944),
(3865974254, 187935, 'esES', 0x00000000, 40944),
(3205218938, 44300, 'esES', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F580041C3B161646520756E2041757468656E74696361746F72207920534D532050726F746563742061207475206375656E7461207061726120646573626C6F717565617220657374652063616D706F0001, 40944),
(3205218938, 44299, 'esES', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C6366666666303030304E6F20707565646573207075626C6963617220756E20677275706F206465206DC3AD746963612B2073696E20756E612070696564726120616E67756C617220686173746120717565206173656775726573207475206375656E746120636F6E20656C2041757468656E74696361746F7220646520426174746C652E6E6574207920534D532050726F746563747C727C6E7C6366663165666630303C48617A20636C69632070617261206F6274656E6572206DC3A17320696E666F726D616369C3B36E3E7C720001, 40944),
(3205218938, 44284, 'esES', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C6366666666303030304E6F207075656465732065646974617220657374652063616D706F20686173746120717565206173656775726573207475206375656E746120636F6E20656C2041757468656E74696361746F7220646520426174746C652E6E6574207920534D532050726F746563747C727C6E7C6366663165666630303C48617A20636C69632070617261206F6274656E6572206DC3A17320696E666F726D616369C3B36E3E7C720001, 40944),
(3205218938, 44283, 'esES', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F4445534300446573626C6F7175656120656C2061636365736F20636F6D706C65746F20616C206275736361646F7220646520677275706F732061C3B1616469656E646F20756E2041757468656E74696361746F72207920534D532050726F746563742061207475206375656E74612E7C6E7C6E456C2041757468656E74696361746F7220646520426174746C652E6E657420657320756E20736572766963696F20677261747569746F20792066C3A163696C2064652075736172207175652070726F74656765207475206375656E746120636F6E7472612061636365736F73206E6F206175746F72697A61646F732C206D69656E747261732071756520534D532050726F7465637420746520656E76C3AD61206E6F74696669636163696F6E6573206375616E646F207365207265616C697A6120616C67C3BA6E2063616D62696F20696D706F7274616E746520656E207475206375656E74612E7C6E7C6E48617A20636C696320656E202241637469766172222070617261206162726972206C612070C3A167696E6120646520636F6E6669677572616369C3B36E2064656C2041757468656E74696361746F722E0001, 40944),
(3776013982, 358927, 'esES', 0x00536F7370656368617320646520747520656E746F726E6F2E2052656475636520656C207469656D706F2064652072657574696C697A616369C3B36E206465206C6F73204E6F6368657465726E612E00536F73706563686173206465206C6F732071756520746520726F6465616E2E00, 40944),
(3865974254, 188152, 'esES', 0x00000000, 40944),
(3776013982, 53385, 'esES', 0x004C696265726120756E20746F7262656C6C696E6F20646520656E657267C3AD6120646976696E612071756520696E666C6967652024733120702E206465206461C3B16F205361677261646F206120746F646F73206C6F7320656E656D69676F732063657263616E6F732E20496E666C696765206461C3B16F20726564756369646F20736920676F6C7065612061206DC3A17320646520247332206F626A657469766F732E0000, 40944),
(261693969, 62694, 'esES', 0xFFFFFFFFFFFFFFFF4C61206C6C616D616461206465204D616C64726178787573000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'esES', 0xFFFFFFFFFFFFFFFF4C61206C6C616D61646120646520417264656E7765616C64000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'esES', 0xFFFFFFFFFFFFFFFF4C61206C6C616D616461206465204261737469C3B36E000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'esES', 0xFFFFFFFFFFFFFFFF4C61206C6C616D61646120646520526576656E6472657468000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'esES', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'esES', 0x000000, 40944),
(3776013982, 307934, 'esES', 0x000000, 40944),
(3776013982, 307480, 'esES', 0x004C616E7A6173207475206472616761646F72206D616475726F2E0000, 40944),
(2948698321, 354, 'esES', 0x64DF8D9146629CB2, 40944),
(261693969, 60111, 'esES', 0xFFFFFFFFFFFFFFFF4C6120666F726A6120646520756E6120616D697374616400005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'esES', 0xFFFFFFFFFFFFFFFF4E756E6361206861732074656E69646F20756E20616D69676F20636F6D6F20796F00005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'esES', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'esES', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'esES', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'esES', 0x00000000, 40944),
(3865974254, 151804, 'esES', 0x00000000, 40944),
(3865974254, 151792, 'esES', 0x00000000, 40944),
(3037505077, 151792, 'esES', 0x0100, 40944),
(3865974254, 151790, 'esES', 0x00000000, 40944),
(3037505077, 151790, 'esES', 0x0100, 40944),
(3865974254, 146306, 'esES', 0x00000000, 40944),
(3865974254, 34685, 'esES', 0x00000000, 40944),
(3865974254, 34683, 'esES', 0x00000000, 40944),
(3865974254, 34087, 'esES', 0x00000000, 40944),
(3865974254, 34085, 'esES', 0x00000000, 40944),
(3865974254, 33969, 'esES', 0x00000000, 40944),
(3865974254, 33968, 'esES', 0x00000000, 40944),
(3865974254, 33967, 'esES', 0x00000000, 40944),
(3865974254, 33966, 'esES', 0x00000000, 40944),
(3865974254, 33868, 'esES', 0x00000000, 40944),
(3865974254, 33864, 'esES', 0x00000000, 40944),
(3865974254, 33863, 'esES', 0x00000000, 40944),
(3865974254, 33862, 'esES', 0x00000000, 40944),
(3865974254, 23324, 'esES', 0x00000000, 40944),
(3865974254, 21525, 'esES', 0x00000000, 40944),
(3865974254, 21524, 'esES', 0x00000000, 40944),
(3865974254, 19028, 'esES', 0x00000000, 40944),
(3865974254, 6835, 'esES', 0x00000000, 40944),
(3865974254, 6833, 'esES', 0x00000000, 40944),
(3865974254, 181321, 'esES', 0x00000000, 40944),
(1548466975, 27672, 'esES', 0x10040000, 40944),
(3776013982, 365080, 'esES', 0x000056656C6F6369646164206465206D6F76696D69656E746F2061756D656E7461646120756E20247331252E00, 40944),
(3776013982, 317920, 'esES', 0x004C6F732065666563746F7320646520696E7465727275706369C3B36E20792073696C656E63696F20736F627265206C6F73206D69656D62726F732064656C20677275706F206F2062616E646120656E20756E20726164696F20646520246131206D20736F6E20756E2024733125206DC3A17320636F72746F732E20243F733333393132345B4C6F732065666563746F73206465206D6965646F2074616D6269C3A96E207365207265647563656E2E5D5B5D0045666563746F7320646520696E7465727275706369C3B36E20792073696C656E63696F20726564756369646F7320756E20247731252E20243F733333393132345B4C6F732065666563746F73206465206D6965646F207365207265647563656E20756E20247734252E5D5B5D00, 40944),
(3776013982, 465, 'esES', 0x004C6F73206D69656D62726F732064656C20677275706F206F2062616E646120656E20756E20726164696F20646520246131206D207365207369656E74656E207265616669726D61646F7320706F72207375206465766F6369C3B36E2C206C6F207175652072656475636520656C206461C3B16F20726563696269646F20756E20247331252E004461C3B16F20726563696269646F20726564756369646F20756E20247731252E00, 40944),
(3205218938, 44172, 'esES', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F4445534300436F6E736967756520756E20C3AD6E646963652064652031393530206F207375706572696F722070617261206F6274656E65723A7C6E2D2052616E676F206465206D656A6F7261206465206F626A65746F73204A634A0001, 40944),
(3205218938, 40887, 'esES', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F4445534300436F6E736967756520756E20C3AD6E646963652064652031383030206F207375706572696F722070617261206F6274656E65723A7C6E2D20456C2074C3AD74756C6F20526976616C7C6E2D204C61206170617269656E636961207061726120656C2079656C6D6F2064656C20636F6E6A756E746F206465204A634A20646520C3A96C6974657C6E2D204C61206170617269656E6369612070617261206C617320686F6D6272657261732064656C20636F6E6A756E746F206465204A634A20646520C3A96C6974650001, 40944),
(3205218938, 40885, 'esES', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F4445534300436F6E736967756520756E20C3AD6E646963652064652031343030206F207375706572696F722070617261206F6274656E65723A7C6E2D20456C2074C3AD74756C6F20436F6E74656E6469656E74657C6E2D204C61206170617269656E6369612070617261206C6F73206775616E7465732064656C20636F6E6A756E746F206465204A634A20646520C3A96C6974657C6E2D204C61206170617269656E6369612070617261206C617320626F7461732064656C20636F6E6A756E746F206465204A634A20646520C3A96C6974650001, 40944),
(3776013982, 357407, 'esES', 0x00496E766F6361207920636F6E74726F6C612074752062C3B36C69646F20646520526F636B696E2720526F6C6C696E272052616365722C20656C204D617261756465722E005574696C697A61206C612062617272612064652061636369C3B36E2070617261206174616361722061206F74726F73206A756775657465732074656C65646972696769646F732E00, 40944),
(3776013982, 357406, 'esES', 0x00496E766F6361207920636F6E74726F6C612074752062C3B36C69646F20646520526F636B696E2720526F6C6C696E272052616365722C20656C204D617261756465722E005574696C697A61206C612062617272612064652061636369C3B36E2070617261206174616361722061206F74726F73206A756775657465732074656C65646972696769646F732E00, 40944),
(3776013982, 357405, 'esES', 0x00496E766F6361207920636F6E74726F6C612074752062C3B36C69646F20646520526F636B696E2720526F6C6C696E272052616365722C20656C204D617261756465722E005574696C697A61206C612062617272612064652061636369C3B36E2070617261206174616361722061206F74726F73206A756775657465732074656C65646972696769646F732E00, 40944),
(3776013982, 356631, 'esES', 0x00496E766F6361207920636F6E74726F6C6120747520526F636B696E2720526F6C6C696E272052616365722C2041697220426C6164652E005574696C697A61206C612062617272612064652061636369C3B36E2070617261206174616361722061206F74726F73206A7567756574657320646520636F6E74726F6C2072656D6F746F2E00, 40944),
(3776013982, 328923, 'esES', 0x53C3AD6C66696465206E6F637475726E61005472616E736669657265206C6120667565727A6120766974616C20646520756E206DC3A178696D6F20646520243332383932384920656E656D69676F732064656C20C3A17265612073656C656363696F6E616461206520696E666C69676520247B282433323839323873312A24642F24743229202B202433323839323873317D20702E206465206461C3B16F206465204E61747572616C657A6120646976696469646F7320657175697461746976616D656E746520612063616461206F626A657469766F20656E656D69676F20647572616E74652024642E243F613133373034315B0D0A0D0A43616E616C697A6172205472616E7366757369C3B36E2064652073C3AD6C6669646520706F7220636F6D706C65746F2067656E6572612024733420244C6163756D756C616369C3B36E3A6163756D756C6163696F6E65733B2064652041726D6120766F72C3A167696E652E5D5B5D0D0A0D0A53692073652070756C7361205472616E7366757369C3B36E2064652073C3AD6C66696465206F7472612076657A20656E206D656E6F732064652024333238393333642C207365206C696265726172C3A120756E202473312520646520746F646F20656C206461C3B16F206465205472616E7366757369C3B36E2064652073C3AD6C666964652C206C6F207175652073616E6172C3A1206120756E206DC3A178696D6F2064652024333238393330733220616C6961646F7320656E20756E20726164696F20646520243332383933304131206D2E0000, 40944),
(3776013982, 101546, 'esES', 0x004769726173206D69656E747261732064617320706174616461732C206C6F2071756520696E666C69676520243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5D20702E206465206461C3B16F2066C3AD7369636F20647572616E7465202464206120746F646F73206C6F7320656E656D69676F7320656E20756E20726164696F20646520243130373237304131206D2E20496E666C696765206461C3B16F20726564756369646F20736920676F6C7065612061206DC3A17320646520247331206F626A657469766F732E243F63335B0D0A0D0A456C206461C3B16F206465205061746164612067697261746F726961206465206C61206772756C6C612061756D656E746120756E202432323033353873312520706F722063616461206F626A657469766F20C3BA6E69636F20616C2071756520686179617320676F6C706561646F20656E206C6F7320C3BA6C74696D6F7320243232303335386420636F6E2050616C6D612064656C2074696772652C20506174616461206F7363757261206F205061746164612064656C20736F6C206E616369656E74652E205365206163756D756C612068617374612024323238323837692076656365732E5D5B5D0041746163616E646F206120656E656D69676F732063657263616E6F73206520696E666C696769656E646F206461C3B16F2066C3AD7369636F20636164612024313031353436743120732E00, 40944),
(3865974254, 188220, 'esES', 0x00000000, 40944),
(3865974254, 187900, 'esES', 0x00000000, 40944),
(3865974254, 187899, 'esES', 0x00000000, 40944),
(3865974254, 187898, 'esES', 0x00000000, 40944),
(3865974254, 187897, 'esES', 0x00000000, 40944),
(3865974254, 187896, 'esES', 0x00000000, 40944),
(3865974254, 187895, 'esES', 0x00000000, 40944),
(3865974254, 187875, 'esES', 0x00000000, 40944),
(3865974254, 187869, 'esES', 0x00000000, 40944),
(3865974254, 150746, 'esES', 0x00000000, 40944),
(3865974254, 150745, 'esES', 0x00000000, 40944),
(3865974254, 150744, 'esES', 0x00000000, 40944),
(3865974254, 150743, 'esES', 0x00000000, 40944),
(3776013982, 364944, 'esES', 0x000056656C6F6369646164206465206D6F76696D69656E746F2061756D656E7461646120756E20247331252E00, 40944),
(3776013982, 228462, 'esES', 0x0041756D656E74612024733120702E20656C206461C3B16F206465207475732061746171756573206175746F6DC3A17469636F732E0000, 40944),
(3776013982, 119611, 'esES', 0x0024407370656C6C646573633131353135310052657374617572612024773120702E2064652073616C756420636164612024743120732E00, 40944),
(3776013982, 119607, 'esES', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'esES', 0x00000000, 40944),
(1181150530, 403396, 'esES', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'esES', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'esES', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'esES', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'esES', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'esES', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'esES', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'esES', 0xA4530000, 40944),
(3359787322, 21411, 'esES', 0xA3530000, 40944),
(3359787322, 21410, 'esES', 0xA2530000, 40944),
(3359787322, 21409, 'esES', 0xA1530000, 40944),
(3359787322, 21408, 'esES', 0xA0530000, 40944),
(3359787322, 21407, 'esES', 0x9F530000, 40944),
(3359787322, 21406, 'esES', 0x9E530000, 40944),
(2557447376, 655518, 'esES', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'esES', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'esES', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'esES', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'esES', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'esES', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F454646454354005961206E6F20657374C3A16E20686162696C697461646173206C6173206E6F726D617320646520626F74C3AD6E20616E7469677561732E0001, 40944),
(3776013982, 347944, 'esES', 0x0050726F626162696C6964616420646520676F6C7065206372C3AD7469636F2061756D656E7461646120756E20247331252E0D0A0050726F626162696C6964616420646520676F6C7065206372C3AD7469636F2061756D656E7461646120756E20247331252E00, 40944),
(3776013982, 347943, 'esES', 0x0053616C7564206DC3A178696D612061756D656E7461646120756E20247331252E0D0A0053616C7564206DC3A178696D612061756D656E7461646120756E20247331252E00, 40944),
(3776013982, 1714, 'esES', 0x004F626C69676120616C206F626A657469766F2061206861626C617220656E2064656D6F6EC3AD61636F2C206C6F207175652061756D656E746120756E202473312520656C207469656D706F206465206C616E7A616D69656E746F20646520746F646F73206C6F732068656368697A6F7320647572616E74652024642E243F733130333131325B0D0A0D0A7C4346464535354242305175656D617220616C6D613A205475204D616C64696369C3B36E206465206C6173206C656E677561732061666563746172C3A1206120746F646F73206C6F7320656E656D69676F7320656E20756E20726164696F206465202431303432323441206D20616C72656465646F72206465207475206F626A657469766F2E7C525D5B5D0D0A0D0A7C6346463832383246464D616C646963696F6E65733A20556E206272756A6F20736F6C6F2070756564652074656E657220756E61206D616C64696369C3B36E2061637469766120706F72206F626A657469766F2E7C72004861626C617220656E2064656D6F6EC3AD61636F2061756D656E746120656C207469656D706F206465206C616E7A616D69656E746F20756E20247731252E00, 40944),
(3205218938, 41865, 'esES', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E53004E6F207469656E6573207065726D69736F207061726120656469746172206C6120696E666F726D616369C3B36E206465207265636C7574616D69656E746F2E0001, 40944),
(261693969, 64850, 'esES', 0xFFFFFFFFFFFFFFFF546F726768617374206465206C61646F2061206C61646F000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'esES', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='esES') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='esES');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'esES' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `achievement_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (14775,14752,14682,14351));
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14775, 'esMX', 'Alcanza la reputación Exaltado con Marasmius.', 'Felicitaciones fúngicas', 'Título de recompensa: Tipo divertido / Chica divertida', 40944),
(14752, 'esMX', 'Completa los siguientes logros de costura abominable.', 'Cosas para hacer en la muerte', 'Título de recompensa: Abominable. Recompensa: Montura Tauralus de los Elegidos acorazado', 40944),
(14682, 'esMX', 'Completa los siguientes logros de la Corte de Brasas.', 'El heraldo de la fiesta', 'Título de recompensa: El Heraldo de la fiesta', 40944),
(14351, 'esMX', 'Derrota a 39 jefes en la Senda de Ascensión.', 'La Senda hacia la Ascensión 39', 'Desbloquea más desafíos en la Senda de Ascensión.', 40944);


DELETE FROM `area_table_locale` WHERE (`VerifiedBuild`>0 AND `ID`=13316 AND `locale`='esMX');
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(13316, 'esMX', 'Casa de Rituales', 40944);


DELETE FROM `battle_pet_species_locale` WHERE (`VerifiedBuild`>0 AND `ID`=3188 AND `locale`='esMX');
INSERT INTO `battle_pet_species_locale` (`ID`, `locale`, `Description_lang`, `SourceText_lang`, `VerifiedBuild`) VALUES
(3188, 'esMX', '', '', 40944);


DELETE FROM `broadcast_text_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (215513,215512,215511));
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(215513, 'esMX', '', 'No sería prudente aventurarse en las Fauces sin prepararse antes. Vuelve cuando tengas todo listo.', 40944),
(215512, 'esMX', 'No sería prudente aventurarse en las Fauces sin prepararse antes. Vuelve cuando tengas todo listo.', '', 40944),
(215511, 'esMX', '', 'Estamos muy cerca. Lucha a mi lado y lograremos superar esta situación.', 40944);


DELETE FROM `char_titles_locale` WHERE (`VerifiedBuild`>0 AND `ID`=693 AND `locale`='esMX');
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(693, 'esMX', '%s, el Ascendido', '%s, el Ascendido', 40944);


UPDATE `char_titles_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=683 AND `locale`='esMX');
DELETE FROM `chr_customization_option_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (1523,689));
INSERT INTO `chr_customization_option_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1523, 'esMX', 'Cola', 40944),
(689, 'esMX', 'Cola', 40944);


DELETE FROM `criteria_tree_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (91730,94390,94389,94388,93811,93810,94331,94330));
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91730, 'esMX', '9.1 Meta Achievement', 40944),
(94390, 'esMX', '', 40944),
(94389, 'esMX', '', 40944),
(94388, 'esMX', '', 40944),
(93811, 'esMX', '', 40944),
(93810, 'esMX', 'Nivel de reconocimiento 80', 40944),
(94331, 'esMX', '', 40944),
(94330, 'esMX', 'Renown Level 80 - Kyrian', 40944);


DELETE FROM `item_search_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,116401));
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(151806, 'esMX', 'Vestido elegante', 40944),
(151804, 'esMX', 'Pantalones de esmoquin negro', 40944),
(151792, 'esMX', 'Ropa de invierno verde', 40944),
(151790, 'esMX', 'Ropa de invierno roja', 40944),
(34685, 'esMX', 'Vestimentas estivales', 40944),
(34683, 'esMX', 'Sandalias estivales', 40944),
(34087, 'esMX', 'Ropa de invierno verde', 40944),
(34085, 'esMX', 'Ropa de invierno roja', 40944),
(33969, 'esMX', 'Sombrero de la Fiesta de la Cerveza morado', 40944),
(33968, 'esMX', 'Sombrero de la Fiesta de la Cerveza azul', 40944),
(33967, 'esMX', 'Sombrero de la Fiesta de la Cerveza verde', 40944),
(33966, 'esMX', 'Zapatillas de la Fiesta de la Cerveza', 40944),
(33868, 'esMX', 'Botas de la Fiesta de la Cerveza', 40944),
(33864, 'esMX', 'Sombrero de la Fiesta de la Cerveza marrón', 40944),
(33863, 'esMX', 'Traje de la Fiesta de la Cerveza', 40944),
(33862, 'esMX', 'Atavío de la Fiesta de la Cerveza', 40944),
(23324, 'esMX', 'Manto del Festival del Fuego', 40944),
(21525, 'esMX', 'Sombrero de invierno verde', 40944),
(21524, 'esMX', 'Sombrero de invierno rojo', 40944),
(19028, 'esMX', 'Vestido elegante', 40944),
(6835, 'esMX', 'Pantalones de esmoquin negro', 40944),
(6833, 'esMX', 'Camisa de esmoquin blanca', 40944),
(181321, 'esMX', 'Varita coronada con gema', 40944),
(116401, 'esMX', 'Sombrero de peregrino fino', 40944);


DELETE FROM `item_sparse_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (176922,176921,176832,187935,188152,151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,188220,187900,187899,187898,187897,187896,187895,187875,187869,150746,150745,150744,150743,116401));
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(176922, 'esMX', 'Esta flor mágica aumenta un 100% la cantidad de materiales de fabricación que ofrecen los espíritus renacidos y catalizadores que han crecido de semillas catalizadoras.', '', '', '', 'Flor nocturna silvestre', 40944),
(176921, 'esMX', 'Estas hojas encantadas reducen 1 día el proceso de las semillas silvestres de recrecimiento.', '', '', '', 'Hojas temporales', 40944),
(176832, 'esMX', 'Esta raíz especial aumenta la calidad de las recompensas que ofrece un espíritu al renacer.', '', '', '', 'Grano de raíz de semilla silvestre', 40944),
(187935, 'esMX', 'Te enseña a fabricar una marca del venado rúnico nocturno.', '', '', '', 'Técnica: Marca del venado rúnico nocturno', 40944),
(188152, 'esMX', 'La magia del fragmento quema al tacto.', '', '', '', 'Fragmento de control de portal', 40944),
(151806, 'esMX', '', '', '', '', 'Vestido elegante', 40944),
(151804, 'esMX', '', '', '', '', 'Pantalones de esmoquin negro', 40944),
(151792, 'esMX', '', '', '', '', 'Ropa de invierno verde', 40944),
(151790, 'esMX', '', '', '', '', 'Ropa de invierno roja', 40944),
(34685, 'esMX', '', '', '', '', 'Vestimentas estivales', 40944),
(34683, 'esMX', '', '', '', '', 'Sandalias estivales', 40944),
(34087, 'esMX', '', '', '', '', 'Ropa de invierno verde', 40944),
(34085, 'esMX', '', '', '', '', 'Ropa de invierno roja', 40944),
(33969, 'esMX', '', '', '', '', 'Sombrero de la Fiesta de la Cerveza morado', 40944),
(33968, 'esMX', '', '', '', '', 'Sombrero de la Fiesta de la Cerveza azul', 40944),
(33967, 'esMX', '', '', '', '', 'Sombrero de la Fiesta de la Cerveza verde', 40944),
(33966, 'esMX', '', '', '', '', 'Zapatillas de la Fiesta de la Cerveza', 40944),
(33868, 'esMX', '', '', '', '', 'Botas de la Fiesta de la Cerveza', 40944),
(33864, 'esMX', '', '', '', '', 'Sombrero de la Fiesta de la Cerveza marrón', 40944),
(33863, 'esMX', '', '', '', '', 'Traje de la Fiesta de la Cerveza', 40944),
(33862, 'esMX', '', '', '', '', 'Atavío de la Fiesta de la Cerveza', 40944),
(23324, 'esMX', '', '', '', '', 'Manto del Festival del Fuego', 40944),
(21525, 'esMX', '', '', '', '', 'Sombrero de invierno verde', 40944),
(21524, 'esMX', '', '', '', '', 'Sombrero de invierno rojo', 40944),
(19028, 'esMX', '', '', '', '', 'Vestido elegante', 40944),
(6835, 'esMX', '', '', '', '', 'Pantalones de esmoquin negro', 40944),
(6833, 'esMX', '', '', '', '', 'Camisa de esmoquin blanca', 40944),
(181321, 'esMX', '', '', '', '', 'Varita coronada con gema', 40944),
(188220, 'esMX', 'Tiene escritas las palabras \"Sobreviví a la Torre\" en la parte inferior.', '', '', '', 'Globo de cenizas de Torghast', 40944),
(187900, 'esMX', 'Un goblin y un gnomo describen sus numerosos descubrimientos en las dos islas.', '', '', '', 'Mapa de exploración: Las maravillas de Kul Tiras y Zandalar', 40944),
(187899, 'esMX', 'La descripción de un alquimista aventurero sobre los dispares biomas y la increíble flora que pueblan Terrallende.', '', '', '', 'Mapa de exploración: Las numerosas curiosidades de Terrallende', 40944),
(187898, 'esMX', 'El informe detallado de un miembro de la Cruzada Argenta sobre todas las operaciones militares puestas en marcha para enfrentar al Rey Exánime.', '', '', '', 'Mapa de exploración: El verdadero costo de la campaña de Rasganorte', 40944),
(187897, 'esMX', 'Un inusual informe realizado por ambas facciones donde se detallan las numerosas consecuencias de los destrozos causados por Alamuerte en Azeroth.', '', '', '', 'Mapa de exploración: Consecuencias del Cataclismo', 40944),
(187896, 'esMX', 'Un relato casual de las últimas aventuras de Li Li por Pandaria, con recomendaciones culinarias de su tío Chen.', '', '', '', 'Mapa de exploración: Guía de una Cerveza de Trueno para Pandaria', 40944),
(187895, 'esMX', 'Una lista concisa de los pocos refugios que hay en Draenor, junto con las costumbres locales que es aconsejable respetar en cada sitio.', '', '', '', 'Mapa de exploración: Los peligros de Draenor', 40944),
(187875, 'esMX', 'Una extensa colección de informes y correspondencia relacionados a diferentes unidades militares que combatieron a la Legión.', '', '', '', 'Mapa de exploración: Los frentes unidos de las Islas Quebradas', 40944),
(187869, 'esMX', 'Un relato detallado del viaje de un surcafauces a través de los cuatro reinos de las Tierras de las Sombras.', '', '', '', 'Mapa de exploración: A las Tierras de las sombras', 40944),
(150746, 'esMX', 'Una propuesta sencilla para abastecer efectivamente a los puestos de avanzada de los Reinos del Este.', '', '', '', 'Mapa de exploración: Aprovisionamiento moderno de los Reinos del Este', 40944),
(150745, 'esMX', 'Una estrategia exhaustiva para deshabilitar rápidamente a las fuerzas de la Alianza en los Reinos del Este en caso de que se produzca una Cuarta Guerra.', '', '', '', 'Mapa de exploración: La campaña de los Reinos del Este', 40944),
(150744, 'esMX', 'Cura las heridas que causaron en la tierra los perversos, corruptos y antinaturales.', '', '', '', 'Mapa de exploración: Un paseo por Kalimdor con la Madre Tierra', 40944),
(150743, 'esMX', 'Una compilación exhaustiva de bestias de garras afiladas, colmillos peligrosos y venenos letales de la Horda.', '', '', '', 'Mapa de exploración: Cómo sobrevivir en Kalimdor', 40944),
(116401, 'esMX', '', '', '', '', 'Sombrero de peregrino fino', 40944);


UPDATE `item_sparse_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (185950,185947,185946));
DELETE FROM `lfg_dungeons_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1445 AND `locale`='esMX');
INSERT INTO `lfg_dungeons_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1445, 'esMX', 'La caída de Viltótem', 'Detén a Tugar Tótem de sangre y sus Gusanos viles antes de que derriben la montaña.', 40944);


DELETE FROM `map_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1756 AND `locale`='esMX');
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(1756, 'esMX', 'Las muertes de Cromi', '', '', '', '', 40944);


DELETE FROM `player_condition_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (95078,95077,95076,85644,73006,73005,87365,85912,85910,85909,85692,94517,94516,94515,94514,94513,94512,94511));
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(95078, 'esMX', '', 40944),
(95077, 'esMX', '', 40944),
(95076, 'esMX', '', 40944),
(85644, 'esMX', 'Debes alcanzar el nivel $pcMinLevel para continuar.', 40944),
(73006, 'esMX', '', 40944),
(73005, 'esMX', '', 40944),
(87365, 'esMX', '', 40944),
(85912, 'esMX', '', 40944),
(85910, 'esMX', '', 40944),
(85909, 'esMX', '', 40944),
(85692, 'esMX', '', 40944),
(94517, 'esMX', '', 40944),
(94516, 'esMX', '', 40944),
(94515, 'esMX', '', 40944),
(94514, 'esMX', '', 40944),
(94513, 'esMX', '', 40944),
(94512, 'esMX', '', 40944),
(94511, 'esMX', '', 40944);


DELETE FROM `spell_category_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1186 AND `locale`='esMX');
INSERT INTO `spell_category_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1186, 'esMX', 'Class - Paladin - Hand of Sacrifice', 40944);


DELETE FROM `spell_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (361952,256817,247692,247111,247110,247104,247103,247099,247096,247094,247093,247092,247089,247088,228844,227799,227780,362986,243328,358927,53385,329902,307934,307480,365080,317920,465,357407,357406,357405,356631,328923,101546,364944,228462,119611,119607,347944,347943,1714));
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(361952, 'esMX', '1000 de ánima', 40944),
(256817, 'esMX', 'Marca de Aman\'thul', 40944),
(247692, 'esMX', 'Continuo de recuerdos', 40944),
(247111, 'esMX', 'Blessing of the Bronze Dragonflight Passive', 40944),
(247110, 'esMX', 'Velocidad infinita', 40944),
(247104, 'esMX', 'Acceleration Passive', 40944),
(247103, 'esMX', 'Detener tiempo - Pasivo', 40944),
(247099, 'esMX', 'Chrono Charisma Passive', 40944),
(247096, 'esMX', 'Rapid Recovery Passive', 40944),
(247094, 'esMX', 'Fortuito', 40944),
(247093, 'esMX', 'Dragon\'s Determination Passive', 40944),
(247092, 'esMX', 'Accelerated Aggression Passive', 40944),
(247089, 'esMX', 'Dragon Crash Passive', 40944),
(247088, 'esMX', 'Perspicacia', 40944),
(228844, 'esMX', 'Huesos ardientes', 40944),
(227799, 'esMX', 'Arrastrar', 40944),
(227780, 'esMX', 'Ritual del trueno', 40944),
(362986, 'esMX', 'Experiencia', 40944),
(243328, 'esMX', 'Desvanecerse', 40944),
(358927, 'esMX', 'Vigilancia de la guardia de los Natonocturno', 40944),
(53385, 'esMX', 'Tormenta divina', 40944),
(329902, 'esMX', 'Dragando', 40944),
(307934, 'esMX', 'Dragando', 40944),
(307480, 'esMX', 'Arrojar dragador', 40944),
(365080, 'esMX', 'Caminavientos', 40944),
(317920, 'esMX', 'Aura de concentración', 40944),
(465, 'esMX', 'Aura de devoción', 40944),
(357407, 'esMX', 'Invocar Deslizador Frenético', 40944),
(357406, 'esMX', 'Invocar Tanque de Carrera', 40944),
(357405, 'esMX', 'Invocar Demonio de Polvo', 40944),
(356631, 'esMX', 'Invocar Cuchilla Aérea', 40944),
(328923, 'esMX', 'Transfusión feérica', 40944),
(101546, 'esMX', 'Patada giratoria de la grulla', 40944),
(364944, 'esMX', 'Caminavientos', 40944),
(228462, 'esMX', 'Sello de Melandrus', 40944),
(119611, 'esMX', 'Niebla renovadora', 40944),
(119607, 'esMX', 'Niebla renovadora', 40944),
(347944, 'esMX', 'Púas de Obleron', 40944),
(347943, 'esMX', 'Robustez de Obleron', 40944),
(1714, 'esMX', 'Maldición de las lenguas', 40944);


DELETE FROM `transmog_set_locale` WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (2289,2287,2283,2281,2277,2275,2271,2269,2178));
INSERT INTO `transmog_set_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(2289, 'esMX', 'Placa de Gladiador desencadenado', 40944),
(2287, 'esMX', 'Placa de Gladiador desencadenado', 40944),
(2283, 'esMX', 'Anillas de Gladiador desencadenado', 40944),
(2281, 'esMX', 'Anillas de Gladiador desencadenado', 40944),
(2277, 'esMX', 'Cueros de Gladiador desencadenado', 40944),
(2275, 'esMX', 'Cueros de Gladiador desencadenado', 40944),
(2271, 'esMX', 'Vestimenta de Gladiador desencadenado', 40944),
(2269, 'esMX', 'Vestimenta de Gladiador desencadenado', 40944),
(2178, 'esMX', 'Armas de los maestros de puntadas', 40944);


UPDATE `transmog_set_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='esMX' AND `ID` IN (2221,2220,2219,2218,2217,2216,2215,2214,2213,2212,2211,2210,2209,2208,2207,2206,2205,2204,2203,2202));
DELETE FROM `achievement_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table_locale` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_blob` WHERE (`TableHash`=2948698321 AND `RecordId`=340 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='esMX') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='esMX') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='esMX') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='esMX') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='esMX') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='esMX') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='esMX') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='esMX') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='esMX') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='esMX') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='esMX') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='esMX') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='esMX') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='esMX') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='esMX') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='esMX') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=358927 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='esMX') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='esMX') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='esMX') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='esMX') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='esMX') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='esMX') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='esMX') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='esMX') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='esMX') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='esMX') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='esMX') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='esMX') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='esMX') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='esMX') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='esMX') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='esMX') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='esMX') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='esMX') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='esMX') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='esMX') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='esMX') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='esMX') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='esMX') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='esMX') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='esMX') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='esMX') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='esMX') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='esMX') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='esMX') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='esMX') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='esMX') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='esMX') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='esMX') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='esMX') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='esMX') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='esMX');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(2948698321, 340, 'esMX', 0xA53E23C86B3D8F59, 40944),
(261693969, 65165, 'esMX', 0xFFFFFFFFFFFFFFFF436F6E73656A6F732064656C20616C6D61000044AC546F010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000000000000, 40944),
(3776013982, 361952, 'esMX', 0x004167726567612024733120646520C3A16E696D612061206C61207265736572766120646520747520706163746F2061637475616C2E0000, 40944),
(3776013982, 256817, 'esMX', 0x005475732068656368697A6F73207920686162696C696461646573207469656E656E20756E612070726F626162696C69646164206465206F746F7267617274652024323536383138733120702E2064652076656C6F63696461642C206576617369C3B36E207920726F626F206465207669646120647572616E74652024323536383138642E0D0A0D0A7C6346464646464646464772616E64657A6120646520416D616E275468756C7C720D0A5369206375656E74617320636F6E206C6120706F74656E6369616369C3B36E2064656C2050616E7465C3B36E2C20747520243F28613133373030357C613133373034377C613133373032387C61313337303237295B667565727A615D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295B6167696C696461645D5B696E74656C6563746F5D2061756D656E74612024323536383332733120702E20647572616E74652024323536383332642E0000, 40944),
(3776013982, 247692, 'esMX', 0x005469656E657320756E612070726F626162696C69646164206D61796F72206465206F6274656E657220756E20436F66726520646520726563756572646F73206465204172656E61732064656C207469656D706F2E204C6F7320436F6672657320646520726563756572646F7320636F6E7469656E656E206F626A65746F7320706F6465726F736F7320717565207265647563656E206E6F7461626C656D656E7465206C61206469666963756C746164206465206C6F73206465736166C3AD6F732064652043726F6E6F706F7274616C65732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E2024733225206C612076656C6F6369646164206465206D6F76696D69656E746F2079206465206D6F6E747572612E005469656E657320756E612070726F626162696C69646164206D61796F72206465206F6274656E657220756E20436F66726520646520726563756572646F73206465204172656E61732064656C207469656D706F2E204C6F7320436F6672657320646520726563756572646F7320636F6E7469656E656E206F626A65746F7320706F6465726F736F7320717565207265647563656E206E6F7461626C656D656E7465206C61206469666963756C746164206465206C6F73206465736166C3AD6F732064652043726F6E6F706F7274616C65732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E2024733225206C612076656C6F6369646164206465206D6F76696D69656E746F2079206465206D6F6E747572612E00, 40944),
(3776013982, 247111, 'esMX', 0x005469656E657320756E61206D61796F722070726F626162696C69646164206465206F6274656E657220756E20447261636F2062726F6E6365206465204172656E61732064656C207469656D706F2E204573746520647261636F2064657370656A6172C3A120756E2053616E74756172696F20646520447261676F6E657320696E6D6564696174616D656E746520706F722074692E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E202473322520656C206461C3B16F2079206C612073616E616369C3B36E2E005469656E657320756E61206D61796F722070726F626162696C69646164206465206F6274656E657220756E20447261636F2062726F6E6365206465204172656E61732064656C207469656D706F2E204573746520647261636F2064657370656A6172C3A120756E2053616E74756172696F20646520447261676F6E657320696E6D6564696174616D656E746520706F722074692E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E202473322520656C206461C3B16F2079206C612073616E616369C3B36E2E00, 40944),
(3776013982, 247110, 'esMX', 0x00446573626C6F7175656120706F7274616C6573206465205265706F736F2064656C2044726167C3B36E2070617261206361646120756E6F206465206C6F732053616E74756172696F7320646520447261676F6E65732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E2024733225206C612076656C6F6369646164206465206D6F76696D69656E746F2079206465206D6F6E747572612E00446573626C6F7175656120706F7274616C6573206465205265706F736F2064656C2044726167C3B36E2070617261206361646120756E6F206465206C6F732053616E74756172696F7320646520447261676F6E65732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E2024733225206C612076656C6F6369646164206465206D6F76696D69656E746F2079206465206D6F6E747572612E00, 40944),
(3776013982, 247104, 'esMX', 0x0041756D656E746120756E2024733125206C612076656C6F6369646164206465206D6F76696D69656E746F2079206465206D6F6E747572612E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E202473322520656C206461C3B16F2079206C612073616E616369C3B36E2E0041756D656E746120756E2024733125206C612076656C6F6369646164206465206D6F76696D69656E746F2079206465206D6F6E747572612E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E202473322520656C206461C3B16F2079206C612073616E616369C3B36E2E00, 40944),
(3776013982, 247103, 'esMX', 0x0024407370656C6C646573633234343935390D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E20352520656C206461C3B16F2079206C612073616E616369C3B36E2E0000, 40944),
(3776013982, 247099, 'esMX', 0x004C61207265707574616369C3B36E207175652067616E617320706F72206C6173206D75657274657320636F6E2043726F6D692061756D656E746120756E202432343737363973312520647572616E7465206C6F7320C3BA6C74696D6F73202432343737363964207920756E202432343737373073312520647572616E746520656C20C3BA6C74696D6F2024323437373730642E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E2024733225206C612076656C6F6369646164206465206D6F76696D69656E746F2079206D6F6E747572612E0000, 40944),
(3776013982, 247096, 'esMX', 0x000000, 40944),
(3776013982, 247094, 'esMX', 0x0054752070726F626162696C6964616420646520656E636F6E74726172204172656E61732064656C207469656D706F2061756D656E746120756E20247331252E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E2024733225206C612073616C75642E0054752070726F626162696C6964616420646520656E636F6E74726172204172656E61732064656C207469656D706F2061756D656E746120756E20247331252E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E2024733225206C612073616C75642E00, 40944),
(3776013982, 247093, 'esMX', 0x000000, 40944),
(3776013982, 247092, 'esMX', 0x000000, 40944),
(3776013982, 247089, 'esMX', 0x0024407370656C6C646573633234353530330D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E202473322520656C206461C3B16F2C206C612073616E616369C3B36E2C206C612073616C75642C206C612076656C6F6369646164206465206D6F76696D69656E746F2079206C612076656C6F6369646164206465206D6F6E747572612E0000, 40944),
(3776013982, 247088, 'esMX', 0x0043726F6D6920726576656C6120746F646F73206C6F7320636F667265732064656C207465736F726F2063657263616E6F732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E202473322520656C206461C3B16F2079206C612073616E616369C3B36E2E0043726F6D6920726576656C6120746F646F73206C6F7320636F667265732064656C207465736F726F2063657263616E6F732E0D0A0D0A7C634646303046463030426F6E69666963616369C3B36E3A7C722041756D656E746120756E202473322520656C206461C3B16F2079206C612073616E616369C3B36E2E00, 40944),
(3479059991, 9040, 'esMX', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'esMX', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'esMX', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'esMX', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'esMX', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'esMX', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'esMX', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'esMX', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'esMX', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'esMX', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'esMX', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'esMX', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'esMX', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'esMX', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'esMX', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'esMX', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'esMX', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'esMX', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'esMX', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'esMX', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'esMX', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'esMX', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'esMX', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'esMX', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'esMX', 0x0024407370656C6C646573633232383832390024733120702E206465206461C3B16F20646520467565676F20696E666C696769646F7320636164612024323238383239743120732E00, 40944),
(3776013982, 227799, 'esMX', 0x004F6C656164617320646520616775612062617272656E206465736465206C6F732065787472656D6F73206465206C61206861626974616369C3B36E2C20696E666C696769656E646F2024733120702E206465206461C3B16F2064652045736361726368612061206C6F73206A756761646F72657320636F6E20717569656E65732063686F63616E2E0000, 40944),
(3776013982, 227780, 'esMX', 0x004D61726361206120746F646F73206C6F73206A756761646F72657320636F6E2024407370656C6C6E616D653232373738302E20416C20657870697261722C206C657320696E666C6967652024733120702E206465206461C3B16F206465204E61747572616C657A61206120746F646F73206C6F73206A756761646F72657320656E20756E20726164696F20646520244131206D2E00416C20657870697261722C20696E666C6967652024733120702E206465206461C3B16F206465204E61747572616C657A61206120746F646F73206C6F73206A756761646F72657320656E20756E20726164696F20646520244131206D2E00, 40944),
(3386291891, 116804, 'esMX', 0x4163746F7220646520657363656E6100000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'esMX', 0x41726368696D61676F204B686164676172000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'esMX', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'esMX', 0x4E69656C6173204172616E0000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'esMX', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'esMX', 0x43757261746F72000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'esMX', 0x00416272652074752070C3A167696E6120646520636F6D7061C3B165726F7320792073656C656363696F6E6120756E6F2070617261207375626972207375206E6976656C2061202473312E0000, 40944),
(261693969, 60399, 'esMX', 0xFFFFFFFFFFFFFFFF4179756461207061726120526576656E647265746800003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'esMX', 0xFFFFFFFFFFFFFFFF41797564612070617261204D616C6472617878757300003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'esMX', 0xFFFFFFFFFFFFFFFF41797564612070617261204261737469C3B36E00003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'esMX', 0xFFFFFFFFFFFFFFFF4179756461207061726120417264656E7765616C6400003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'esMX', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'esMX', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'esMX', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'esMX', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'esMX', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'esMX', 0x00000000, 40944),
(3865974254, 176921, 'esMX', 0x00000000, 40944),
(3865974254, 176832, 'esMX', 0x00000000, 40944),
(3776013982, 243328, 'esMX', 0x00004E6976656C20646520616D656E617A6120726564756369646F2E00, 40944),
(3865974254, 187935, 'esMX', 0x00000000, 40944),
(3205218938, 44300, 'esMX', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F580056696E63756C6120756E2041757468656E74696361746F72207920534D532050726F7465637420636F6E207475206375656E7461207061726120646573626C6F717565617220657374652063616D706F0001, 40944),
(3205218938, 44299, 'esMX', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C6366666666303030304E6F20707565646573207075626C6963617220756E20677275706F206465206469666963756C746164206DC3AD746963612B2073696E20756E612070696564726120616E67756C6172207369207475206375656E7461206E6F20657374C3A12070726F74656769646120636F6E20656C2041757468656E74696361746F72207920534D532050726F7465637420646520426174746C652E6E65747C727C6E7C6366663165666630303C48617A20636C69632070617261206F6274656E6572206DC3A17320696E666F726D616369C3B36E3E7C720001, 40944),
(3205218938, 44284, 'esMX', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C6366666666303030304E6F207075656465732065646974617220657374652063616D706F207369207475206375656E7461206E6F20657374C3A12070726F74656769646120636F6E20656C2041757468656E74696361746F72207920534D532050726F7465637420646520426174746C652E6E65747C727C6E7C6366663165666630303C48617A20636C69632070617261206F6274656E6572206DC3A17320696E666F726D616369C3B36E3E7C720001, 40944),
(3205218938, 44283, 'esMX', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F444553430056696E63756C6120756E2041757468656E74696361746F72207920534D532050726F7465637420636F6E207475206375656E7461207920646573626C6F7175656120656C2061636365736F20636F6D706C65746F20616C206275736361646F7220646520677275706F732E7C6E7C6E456C2041757468656E74696361746F7220646520426174746C652E6E657420657320756E20736572766963696F20677261747569746F20792066C3A163696C2064652075736172207175652070726F74656765207475206375656E74612064652061636365736F73206E6F206175746F72697A61646F732C207920534D532050726F74656374207465206E6F746966696361206375616E646F207365207265616C697A616E2063616D62696F7320696D706F7274616E74657320656E207475206375656E74612E7C6E7C6E48617A20636C696320656E202241637469766172222070617261206162726972206C612070C3A167696E6120646520636F6E6669677572616369C3B36E2064656C2041757468656E74696361746F722E0001, 40944),
(3776013982, 358927, 'esMX', 0x00436F6D69656E7A6173206120657374617220616C657274612064652074757320616C72656465646F7265732E204D656E6F73207469656D706F2064652072657574696C697A616369C3B36E2070617261206C6F73204E61746F6E6F637475726E6F2E00416C657274612064652074757320616C72656465646F7265732E00, 40944),
(3865974254, 188152, 'esMX', 0x00000000, 40944),
(3776013982, 53385, 'esMX', 0x0044657361746120756E20746F7262656C6C696E6F20646520656E657267C3AD6120646976696E612071756520696E666C6967652024733120702E206465206461C3B16F207361677261646F206120746F646F73206C6F7320656E656D69676F732063657263616E6F732E20496E666C696765206D656E6F73206461C3B16F206375616E646F20676F6C7065612061206DC3A17320646520247332206F626A657469766F732E0000, 40944),
(261693969, 62694, 'esMX', 0xFFFFFFFFFFFFFFFF556E206C6C616D61646F20656E204D616C64726178787573000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'esMX', 0xFFFFFFFFFFFFFFFF556E206C6C616D61646F20656E20417264656E7765616C64000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'esMX', 0xFFFFFFFFFFFFFFFF556E206C6C616D61646F20656E204261737469C3B36E000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'esMX', 0xFFFFFFFFFFFFFFFF556E206C6C616D61646F20656E20526576656E6472657468000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'esMX', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'esMX', 0x000000, 40944),
(3776013982, 307934, 'esMX', 0x000000, 40944),
(3776013982, 307480, 'esMX', 0x004172726F6A61207475206472616761646F72206D616475726F0000, 40944),
(2948698321, 354, 'esMX', 0x64DF8D9146629CB2, 40944),
(261693969, 60111, 'esMX', 0xFFFFFFFFFFFFFFFF43C3B36D6F20736520666F726A6120756E6120616D697374616400005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'esMX', 0xFFFFFFFFFFFFFFFF556E207061722073696E20696775616C00005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'esMX', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'esMX', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'esMX', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'esMX', 0x00000000, 40944),
(3865974254, 151804, 'esMX', 0x00000000, 40944),
(3865974254, 151792, 'esMX', 0x00000000, 40944),
(3037505077, 151792, 'esMX', 0x0100, 40944),
(3865974254, 151790, 'esMX', 0x00000000, 40944),
(3037505077, 151790, 'esMX', 0x0100, 40944),
(3865974254, 146306, 'esMX', 0x00000000, 40944),
(3865974254, 34685, 'esMX', 0x00000000, 40944),
(3865974254, 34683, 'esMX', 0x00000000, 40944),
(3865974254, 34087, 'esMX', 0x00000000, 40944),
(3865974254, 34085, 'esMX', 0x00000000, 40944),
(3865974254, 33969, 'esMX', 0x00000000, 40944),
(3865974254, 33968, 'esMX', 0x00000000, 40944),
(3865974254, 33967, 'esMX', 0x00000000, 40944),
(3865974254, 33966, 'esMX', 0x00000000, 40944),
(3865974254, 33868, 'esMX', 0x00000000, 40944),
(3865974254, 33864, 'esMX', 0x00000000, 40944),
(3865974254, 33863, 'esMX', 0x00000000, 40944),
(3865974254, 33862, 'esMX', 0x00000000, 40944),
(3865974254, 23324, 'esMX', 0x00000000, 40944),
(3865974254, 21525, 'esMX', 0x00000000, 40944),
(3865974254, 21524, 'esMX', 0x00000000, 40944),
(3865974254, 19028, 'esMX', 0x00000000, 40944),
(3865974254, 6835, 'esMX', 0x00000000, 40944),
(3865974254, 6833, 'esMX', 0x00000000, 40944),
(3865974254, 181321, 'esMX', 0x00000000, 40944),
(1548466975, 27672, 'esMX', 0x10040000, 40944),
(3776013982, 365080, 'esMX', 0x000056656C6F6369646164206465206D6F76696D69656E746F2061756D656E7461646120756E20247331252E00, 40944),
(3776013982, 317920, 'esMX', 0x004C6F732065666563746F7320646520696E7465727275706369C3B36E20792073696C656E63696F20656E206C6F73206D69656D62726F732064656C20677275706F206F2062616E646120656E20756E20726164696F20646520246131206D20647572616E20756E2024733125206D656E6F732E20243F733333393132345B54616D6269C3A96E207365207265647563656E206C6F732065666563746F73206465206D6965646F2E5D5B5D004C6F732065666563746F7320646520696E7465727275706369C3B36E20792073696C656E63696F207365207265647563656E20756E20247731252E20243F733333393132345B54616D6269C3A96E207365207265647563656E206C6F732065666563746F73206465206D6965646F20756E20247734252E5D5B5D00, 40944),
(3776013982, 465, 'esMX', 0x004C61206465766F6369C3B36E2064656C207461756D61747572676F20706F74656E6369612061206C6F73206D69656D62726F73206465206C612062616E646120792064656C20677275706F2071756520657374C3A96E20656E20756E20726164696F20646520246131206D20792072656475636520756E202473312520656C206461C3B16F20726563696269646F2E00456C206461C3B16F20726563696269646F2073652072656475636520756E20247731252E00, 40944),
(3205218938, 44172, 'esMX', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F4445534300436F6E736967756520756E20C3AD6E646963652064652031393530206F207375706572696F722070617261206F6274656E65723A7C6E2D204D656A6F72612064652072616E676F206465206F626A65746F206465204A634A0001, 40944),
(3205218938, 40887, 'esMX', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F4445534300436F6E736967756520756E20C3AD6E646963652064652031383030206F207375706572696F722070617261206F6274656E65723A7C6E2D2054C3AD74756C6F20646520526976616C7C6E2D204170617269656E6369612064656C20636F6E6A756E746F206465204A634A20646520C3A96C6974653A2079656C6D6F7C6E2D204170617269656E6369612064656C20636F6E6A756E746F206465204A634A20646520C3A96C6974653A20686F6D62726F0001, 40944),
(3205218938, 40885, 'esMX', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F4445534300436F6E736967756520756E20C3AD6E646963652064652031343030206F207375706572696F722070617261206F6274656E65723A7C6E2D2054C3AD74756C6F20646520436F6E74656E6469656E74657C6E2D204170617269656E6369612064656C20636F6E6A756E746F206465204A634A20646520C3A96C6974653A206775616E7465737C6E2D204170617269656E6369612064656C20636F6E6A756E746F206465204A634A20646520C3A96C6974653A20626F7461730001, 40944),
(3776013982, 357407, 'esMX', 0x00496E766F6361207920636F6E74726F6C6120747520526F636B696E2720526F6C6C696E27205261636572204D65726F646561646F722E005573612074752062617272612064652061636369C3B36E2070617261206174616361722061206F74726F73206A75677565746573206120726164696F636F6E74726F6C2E00, 40944),
(3776013982, 357406, 'esMX', 0x00496E766F6361207920636F6E74726F6C6120747520526F636B696E2720526F6C6C696E27205261636572204D65726F646561646F722E005573612074752062617272612064652061636369C3B36E2070617261206174616361722061206F74726F73206A75677565746573206120726164696F636F6E74726F6C2E00, 40944),
(3776013982, 357405, 'esMX', 0x00496E766F6361207920636F6E74726F6C6120747520526F636B696E2720526F6C6C696E27205261636572204D65726F646561646F722E005573612074752062617272612064652061636369C3B36E2070617261206174616361722061206F74726F73206A75677565746573206120726164696F636F6E74726F6C2E00, 40944),
(3776013982, 356631, 'esMX', 0x00496E766F6361207920636F6E74726F6C6120747520526F636B696E2720526F6C6C696E272052616365722043756368696C6C612041C3A97265612E005573612074752062617272612064652061636369C3B36E2070617261206174616361722061206F74726F73206A75677565746573206120726164696F636F6E74726F6C2E00, 40944),
(3776013982, 328923, 'esMX', 0x4E6F6374696665C3A97269636F73005472616E736669657265206C6120667565727A6120766974616C20646520756E206DC3A178696D6F20646520243332383932384920656E656D69676F732064656C20C3A17265612073656C656363696F6E6164612C206C6F2071756520696E666C69676520247B282433323839323873312A24642F24743229202B202433323839323873317D20702E206465206461C3B16F206465206E61747572616C657A612C2072657061727469646F7320657175697461746976616D656E746520656E74726520746F646F73206C6F73206F626A657469766F7320656E656D69676F7320647572616E74652024642E20243F613133373034315B0D0A0D0A436F6D706C65746172206C612063616E616C697A616369C3B36E206465205472616E7366757369C3B36E206665C3A9726963612067656E6572612024733420246C6163756D756C616369C3B36E3A6163756D756C6163696F6E65733B2064652041726D6120766F72C3A167696E652E5D5B5D0D0A0D0A566F6C76657220612070726573696F6E6172205472616E7366757369C3B36E206665C3A97269636120656E206C6F73207072C3B378696D6F73202433323839333364206C696265726172C3A120756E202473312520646520746F646F20656C206461C3B16F206465205472616E7366757369C3B36E206665C3A97269636120792073616E6172C3A1206120756E206DC3A178696D6F2064652024333238393330733220616C6961646F7320656E20756E20726164696F20646520243332383933304131206D2E0000, 40944),
(3776013982, 101546, 'esMX', 0x004769726173206D69656E7472617320646173207061746164617320656E20656C2061697265206520696E666C6967657320243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5D20702E206465206461C3B16F2066C3AD7369636F20647572616E7465202464206120746F646F73206C6F7320656E656D69676F7320656E20756E20726164696F20646520243130373237304131206D2E20496E666C696765206D656E6F73206461C3B16F206375616E646F20676F6C7065612061206DC3A17320646520247331206F626A657469766F732E243F63335B0D0A0D0A456C206461C3B16F206465205061746164612067697261746F726961206465206C61206772756C6C612061756D656E746120756E202432323033353873312520706F722063616461206F626A657469766F20696E646976696475616C2071756520686179617320676F6C706561646F20656E206C6F7320C3BA6C74696D6F7320243232303335386420636F6E2050616C6D612064656C2074696772652C20506174616461206F7363757261206F205061746164612064656C20736F6C206E616369656E74652E205365206163756D756C612068617374612024323238323837692076656365732E5D5B5D00496E666C696769656E646F206461C3B16F2066C3AD7369636F206120746F646F73206C6F7320656E656D69676F732063657263616E6F7320636164612024313031353436743120732E00, 40944),
(3865974254, 188220, 'esMX', 0x00000000, 40944),
(3865974254, 187900, 'esMX', 0x00000000, 40944),
(3865974254, 187899, 'esMX', 0x00000000, 40944),
(3865974254, 187898, 'esMX', 0x00000000, 40944),
(3865974254, 187897, 'esMX', 0x00000000, 40944),
(3865974254, 187896, 'esMX', 0x00000000, 40944),
(3865974254, 187895, 'esMX', 0x00000000, 40944),
(3865974254, 187875, 'esMX', 0x00000000, 40944),
(3865974254, 187869, 'esMX', 0x00000000, 40944),
(3865974254, 150746, 'esMX', 0x00000000, 40944),
(3865974254, 150745, 'esMX', 0x00000000, 40944),
(3865974254, 150744, 'esMX', 0x00000000, 40944),
(3865974254, 150743, 'esMX', 0x00000000, 40944),
(3776013982, 364944, 'esMX', 0x000056656C6F6369646164206465206D6F76696D69656E746F2061756D656E7461646120756E20247331252E00, 40944),
(3776013982, 228462, 'esMX', 0x0041756D656E746120756E202473312520656C206461C3B16F206465207475732061746171756573206175746F6DC3A17469636F732E0000, 40944),
(3776013982, 119611, 'esMX', 0x0024407370656C6C646573633131353135310052657374617572612024773120702E2064652073616C756420636164612024743120732E00, 40944),
(3776013982, 119607, 'esMX', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'esMX', 0x00000000, 40944),
(1181150530, 403396, 'esMX', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'esMX', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'esMX', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'esMX', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'esMX', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'esMX', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'esMX', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'esMX', 0xA4530000, 40944),
(3359787322, 21411, 'esMX', 0xA3530000, 40944),
(3359787322, 21410, 'esMX', 0xA2530000, 40944),
(3359787322, 21409, 'esMX', 0xA1530000, 40944),
(3359787322, 21408, 'esMX', 0xA0530000, 40944),
(3359787322, 21407, 'esMX', 0x9F530000, 40944),
(3359787322, 21406, 'esMX', 0x9E530000, 40944),
(2557447376, 655518, 'esMX', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'esMX', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'esMX', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'esMX', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'esMX', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'esMX', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F454646454354004C6173207265676C617320646520626F74C3AD6E206465206C656761646F20657374C3A16E206465736163746976616461732E0001, 40944),
(3776013982, 347944, 'esMX', 0x004C612070726F626162696C6964616420646520676F6C7065206372C3AD7469636F2061756D656E746120756E20247331252E0D0A004C612070726F626162696C6964616420646520676F6C7065206372C3AD7469636F2061756D656E746120756E20247331252E00, 40944),
(3776013982, 347943, 'esMX', 0x004C612073616C7564206DC3A178696D612061756D656E746120756E20247331252E0D0A004C612073616C7564206DC3A178696D612061756D656E746120756E20247331252E00, 40944),
(3776013982, 1714, 'esMX', 0x004F626C69676120616C20656E656D69676F2061206861626C617220656E2064656D6F6EC3AD61636F2C206C6F207175652061756D656E746120656C207469656D706F206465206C616E7A616D69656E746F20646520746F646F73206C6F732068656368697A6F7320756E202473312520647572616E74652024642E243F733130333131325B0D0A0D0A7C4346464535354242305175656D617220616C6D613A205475204D616C64696369C3B36E206465206C6173206C656E677561732061666563746172C3A1206120746F646F73206C6F7320656E656D69676F7320656E20756E20726164696F206465202431303432323441206D20616C72656465646F72206465207475206F626A657469766F2E7C525D5B5D0D0A0D0A7C6346463832383246464D616C646963696F6E65733A20556E206272756A6F20736F6C6F2070756564652074656E657220756E61204D616C64696369C3B36E2061637469766120706F72206F626A657469766F2E7C72004861626C616E646F20656E2064656D6F6EC3AD61636F2C206C6F207175652061756D656E746120656C207469656D706F206465206C616E7A616D69656E746F20756E20247731252E00, 40944),
(3205218938, 41865, 'esMX', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E53004E6F207469656E6573207065726D69736F73207061726120656469746172206C6120696E666F726D616369C3B36E206465207265636C7574616D69656E746F2E0001, 40944),
(261693969, 64850, 'esMX', 0xFFFFFFFFFFFFFFFF412074726176C3A97320646520546F726768617374000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'esMX', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='esMX') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='esMX');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'esMX' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `achievement_locale` WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (14775,14752,14682,14351));
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14775, 'frFR', 'Être exalté auprès de Marasmius.', 'Fongiquement vôtre', 'Titre : le/la fongique', 40944),
(14752, 'frFR', 'Accomplir les hauts faits de Suture abominable listés ci-dessous.', 'S\’occuper quand on est mort', 'Titre : abominable - Récompense : monture tauralus élu cuirassé', 40944),
(14682, 'frFR', 'Accomplir les hauts faits de la cour des Braises listés ci-dessous.', 'Le héraut des festivités', 'Titre : Héraut des festivités', 40944),
(14351, 'frFR', 'Vaincre 39 boss sur la voie de l\’Ascension.', 'La voie vers l\’Ascension 39', 'Débloquer de nouveaux défis sur la voie de l\’Ascension.', 40944);


DELETE FROM `area_table_locale` WHERE (`VerifiedBuild`>0 AND `ID`=13316 AND `locale`='frFR');
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(13316, 'frFR', 'Maison des Rituels', 40944);


DELETE FROM `battle_pet_species_locale` WHERE (`VerifiedBuild`>0 AND `ID`=3188 AND `locale`='frFR');
INSERT INTO `battle_pet_species_locale` (`ID`, `locale`, `Description_lang`, `SourceText_lang`, `VerifiedBuild`) VALUES
(3188, 'frFR', '', '', 40944);


DELETE FROM `broadcast_text_locale` WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (215513,215512,215511));
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(215513, 'frFR', '', 'Il serait imprudent de s\’aventurer dans l\’Antre sans avoir fait les préparatifs nécessaires. Revenez me voir quand ce sera bon.', 40944),
(215512, 'frFR', 'Il serait imprudent de s\’aventurer dans l\’Antre sans avoir fait les préparatifs nécessaires. Revenez me voir quand ce sera bon.', '', 40944),
(215511, 'frFR', '', 'Nous sommes si près du but. Combattez à mes côtés et nous verrons la fin de cette histoire.', 40944);


DELETE FROM `char_titles_locale` WHERE (`VerifiedBuild`>0 AND `ID`=693 AND `locale`='frFR');
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(693, 'frFR', '%s le transcendé', '%s la transcendée', 40944);


UPDATE `char_titles_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=683 AND `locale`='frFR');
DELETE FROM `chr_customization_option_locale` WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (1523,689));
INSERT INTO `chr_customization_option_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1523, 'frFR', 'Queue', 40944),
(689, 'frFR', 'Queue', 40944);


DELETE FROM `criteria_tree_locale` WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (91730,94390,94389,94388,93811,93810,94331,94330));
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91730, 'frFR', '9.1 Haut fait (méta)', 40944),
(94390, 'frFR', '', 40944),
(94389, 'frFR', '', 40944),
(94388, 'frFR', '', 40944),
(93811, 'frFR', '', 40944),
(93810, 'frFR', 'Niveau de renom 80', 40944),
(94331, 'frFR', '', 40944),
(94330, 'frFR', 'Renown Level 80 - Kyrian', 40944);


DELETE FROM `item_search_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,116401));
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(151806, 'frFR', 'Robe de soirée', 40944),
(151804, 'frFR', 'Pantalon de smoking noir', 40944),
(151792, 'frFR', 'Vêtements d\'hiver verts', 40944),
(151790, 'frFR', 'Vêtements d\'hiver rouges', 40944),
(34685, 'frFR', 'Habits d\'été', 40944),
(34683, 'frFR', 'Sandales de l\'été', 40944),
(34087, 'frFR', 'Vêtements d\'hiver verts', 40944),
(34085, 'frFR', 'Vêtements d\'hiver rouges', 40944),
(33969, 'frFR', 'Chapeau violet de la fête des Brasseurs', 40944),
(33968, 'frFR', 'Chapeau bleu de la fête des Brasseurs', 40944),
(33967, 'frFR', 'Chapeau vert de la fête des Brasseurs', 40944),
(33966, 'frFR', 'Mules de la fête des Brasseurs', 40944),
(33868, 'frFR', 'Bottes de la fête des Brasseurs', 40944),
(33864, 'frFR', 'Chapeau brun de la fête des Brasseurs', 40944),
(33863, 'frFR', 'Robe de la fête des Brasseurs', 40944),
(33862, 'frFR', 'Tenue de parade de la fête des Brasseurs', 40944),
(23324, 'frFR', 'Mantelet de la fête du Feu', 40944),
(21525, 'frFR', 'Chapeau d\'hiver vert', 40944),
(21524, 'frFR', 'Chapeau d\'hiver rouge', 40944),
(19028, 'frFR', 'Robe de soirée', 40944),
(6835, 'frFR', 'Pantalon de smoking noir', 40944),
(6833, 'frFR', 'Chemise blanche de smoking', 40944),
(181321, 'frFR', 'Baguette couronnée de gemmes', 40944),
(116401, 'frFR', 'Chapeau de pèlerin raffiné', 40944);


DELETE FROM `item_sparse_locale` WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (176922,176921,176832,187935,188152,151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,188220,187900,187899,187898,187897,187896,187895,187875,187869,150746,150745,150744,150743,116401));
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(176922, 'frFR', 'Cette fleur magique augmente de 100% le nombre de composants d\’artisanat offerts par les esprits lors de leur renaissance, ainsi que le nombre de catalyseurs produits par les graines de catalyse.', '', '', '', 'Fleur-de-nuit sauvage', 40944),
(176921, 'frFR', 'Ces feuilles enchantées réduisent de 1 jour le temps nécessaire à la maturation des graines sauvages de rétablissement.', '', '', '', 'Feuilles temporelles', 40944),
(176832, 'frFR', 'Cette racine spéciale améliore la qualité des récompenses offertes par un esprit lors de sa renaissance.', '', '', '', 'Grain de racine sauvage', 40944),
(187935, 'frFR', 'Vous apprend à fabriquer une Marque du cerf runique de minuit.', '', '', '', 'Technique : Marque du cerf runique de minuit', 40944),
(188152, 'frFR', 'La magie de l\’éclat inflige une brûlure cuisante au moindre contact.', '', '', '', 'Éclat de contrôle du portail', 40944),
(151806, 'frFR', '', '', '', '', 'Robe de soirée', 40944),
(151804, 'frFR', '', '', '', '', 'Pantalon de smoking noir', 40944),
(151792, 'frFR', '', '', '', '', 'Vêtements d\'hiver verts', 40944),
(151790, 'frFR', '', '', '', '', 'Vêtements d\'hiver rouges', 40944),
(34685, 'frFR', '', '', '', '', 'Habits d\'été', 40944),
(34683, 'frFR', '', '', '', '', 'Sandales de l\'été', 40944),
(34087, 'frFR', '', '', '', '', 'Vêtements d\'hiver verts', 40944),
(34085, 'frFR', '', '', '', '', 'Vêtements d\'hiver rouges', 40944),
(33969, 'frFR', '', '', '', '', 'Chapeau violet de la fête des Brasseurs', 40944),
(33968, 'frFR', '', '', '', '', 'Chapeau bleu de la fête des Brasseurs', 40944),
(33967, 'frFR', '', '', '', '', 'Chapeau vert de la fête des Brasseurs', 40944),
(33966, 'frFR', '', '', '', '', 'Mules de la fête des Brasseurs', 40944),
(33868, 'frFR', '', '', '', '', 'Bottes de la fête des Brasseurs', 40944),
(33864, 'frFR', '', '', '', '', 'Chapeau brun de la fête des Brasseurs', 40944),
(33863, 'frFR', '', '', '', '', 'Robe de la fête des Brasseurs', 40944),
(33862, 'frFR', '', '', '', '', 'Tenue de parade de la fête des Brasseurs', 40944),
(23324, 'frFR', '', '', '', '', 'Mantelet de la fête du Feu', 40944),
(21525, 'frFR', '', '', '', '', 'Chapeau d\'hiver vert', 40944),
(21524, 'frFR', '', '', '', '', 'Chapeau d\'hiver rouge', 40944),
(19028, 'frFR', '', '', '', '', 'Robe de soirée', 40944),
(6835, 'frFR', '', '', '', '', 'Pantalon de smoking noir', 40944),
(6833, 'frFR', '', '', '', '', 'Chemise blanche de smoking', 40944),
(181321, 'frFR', '', '', '', '', 'Baguette couronnée de gemmes', 40944),
(188220, 'frFR', 'Les mots « J\’ai survécu à la Tour » sont inscrits à sa base.', '', '', '', 'Globe cendreux de Tourment', 40944),
(187900, 'frFR', 'Un Gnome et un Gobelin se sont associés pour décrire leurs innombrables découvertes sur ces deux îles.', '', '', '', 'Carte de reconnaissance : Les merveilles de Kul Tiras et Zandalar', 40944),
(187899, 'frFR', 'La description des différents biomes de l\’Outreterre et de leur flore stupéfiante, par une alchimiste aventureuse.', '', '', '', 'Carte de reconnaissance : Les maintes curiosités de l\’Outreterre', 40944),
(187898, 'frFR', 'La liste détaillée, rédigée par un croisé d\’argent, de toutes les opérations militaires entreprises à la recherche du roi-liche.', '', '', '', 'Carte de reconnaissance : Le véritable prix de la campagne du Norfendre', 40944),
(187897, 'frFR', 'Un rapport rare, rédigé conjointement par l\’Alliance et la Horde, dressant la liste des innombrables conséquences de l\’arrivée d\’Aile de mort en Azeroth.', '', '', '', 'Carte de reconnaissance : Les conséquences du Cataclysme', 40944),
(187896, 'frFR', 'Un récit au ton léger des dernières aventures de Li Li en Pandarie, comprenant notamment les recommandations culinaires de son oncle Chen.', '', '', '', 'Carte de reconnaissance : Guide de la Pandarie, par les Brune d\’Orage', 40944),
(187895, 'frFR', 'Une liste concise des rares endroits accueillants en Draenor et les coutumes locales qu\’il est conseillé de suivre.', '', '', '', 'Carte de reconnaissance : Les dangers de Draenor', 40944),
(187875, 'frFR', 'Épais recueil de rapports et de correspondances provenant de différentes unités militaires ayant affronté la Légion.', '', '', '', 'Carte de reconnaissance : Les fronts unis des îles Brisées', 40944),
(187869, 'frFR', 'Le récit minutieux de l\’épopée d\’une âme sans-entraves à travers les quatre royaumes de l\’Ombreterre.', '', '', '', 'Carte de reconnaissance : Vers l\’Ombreterre', 40944),
(150746, 'frFR', 'Une proposition modeste visant à ravitailler à temps les avant-postes des royaumes de l\’Est.', '', '', '', 'Carte de reconnaissance : Modernisation des chaînes logistiques des royaumes de l\’Est', 40944),
(150745, 'frFR', 'Une étude stratégique détaillée sur la manière de porter un coup fatal et rapide aux armées de l\’Alliance des royaumes de l\’Est dans le cadre d\’une Quatrième guerre.', '', '', '', 'Carte de reconnaissance : La campagne des royaumes de l\’Est', 40944),
(150744, 'frFR', 'Pour guérir les plaies infligées à la terre par le mal, la corruption et le surnaturel.', '', '', '', 'Carte de reconnaissance : Visite de Kalimdor aux côtés de la Terre-Mère', 40944),
(150743, 'frFR', 'Une compilation exhaustive des bêtes sauvages, griffues, venimeuses ou au service de la Horde.', '', '', '', 'Carte de reconnaissance : De l\’art de la survie en Kalimdor', 40944),
(116401, 'frFR', '', '', '', '', 'Chapeau de pèlerin raffiné', 40944);


UPDATE `item_sparse_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (185950,185947,185946));
DELETE FROM `lfg_dungeons_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1445 AND `locale`='frFR');
INSERT INTO `lfg_dungeons_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1445, 'frFR', 'La chute des Totems-Fétides', 'Empêchez Tugar Totem-de-Sang et ses vers gangrenés de détruire la montagne.', 40944);


DELETE FROM `map_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1756 AND `locale`='frFR');
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(1756, 'frFR', 'Les morts de Chromie', '', '', '', '', 40944);


DELETE FROM `player_condition_locale` WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (95078,95077,95076,85644,73006,73005,87365,85912,85910,85909,85692,94517,94516,94515,94514,94513,94512,94511));
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(95078, 'frFR', '', 40944),
(95077, 'frFR', '', 40944),
(95076, 'frFR', '', 40944),
(85644, 'frFR', 'Niveau $pcMinLevel nécessaire pour continuer.', 40944),
(73006, 'frFR', '', 40944),
(73005, 'frFR', '', 40944),
(87365, 'frFR', '', 40944),
(85912, 'frFR', '', 40944),
(85910, 'frFR', '', 40944),
(85909, 'frFR', '', 40944),
(85692, 'frFR', '', 40944),
(94517, 'frFR', '', 40944),
(94516, 'frFR', '', 40944),
(94515, 'frFR', '', 40944),
(94514, 'frFR', '', 40944),
(94513, 'frFR', '', 40944),
(94512, 'frFR', '', 40944),
(94511, 'frFR', '', 40944);


DELETE FROM `spell_category_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1186 AND `locale`='frFR');
INSERT INTO `spell_category_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1186, 'frFR', 'Class - Paladin - Hand of Sacrifice', 40944);


DELETE FROM `spell_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (361952,256817,247692,247111,247110,247104,247103,247099,247096,247094,247093,247092,247089,247088,228844,227799,227780,362986,243328,358927,53385,329902,307934,307480,365080,317920,465,357407,357406,357405,356631,328923,101546,364944,228462,119611,119607,347944,347943,1714));
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(361952, 'frFR', '1000 unités d\’anima', 40944),
(256817, 'frFR', 'Marque d\’Aman\’Thul', 40944),
(247692, 'frFR', 'Continuum du souvenir', 40944),
(247111, 'frFR', 'Blessing of the Bronze Dragonflight Passive', 40944),
(247110, 'frFR', 'Vélocité infinie', 40944),
(247104, 'frFR', 'Acceleration Passive', 40944),
(247103, 'frFR', 'Time Stop Passive', 40944),
(247099, 'frFR', 'Chrono Charisma Passive', 40944),
(247096, 'frFR', 'Rapid Recovery Passive', 40944),
(247094, 'frFR', 'Fortuité', 40944),
(247093, 'frFR', 'Dragon\'s Determination Passive', 40944),
(247092, 'frFR', 'Accelerated Aggression Passive', 40944),
(247089, 'frFR', 'Dragon Crash Passive', 40944),
(247088, 'frFR', 'Clairvoyance', 40944),
(228844, 'frFR', 'Os ardents', 40944),
(227799, 'frFR', 'Lessivage', 40944),
(227780, 'frFR', 'Rituel du tonnerre', 40944),
(362986, 'frFR', 'Expérience', 40944),
(243328, 'frFR', 'Disparition', 40944),
(358927, 'frFR', 'Vigilance de garde sacrenuit', 40944),
(53385, 'frFR', 'Tempête divine', 40944),
(329902, 'frFR', 'Invocation de purotin', 40944),
(307934, 'frFR', 'Invocation de purotin', 40944),
(307480, 'frFR', 'Lancer de purotin', 40944),
(365080, 'frFR', 'Marche-vent', 40944),
(317920, 'frFR', 'Aura de concentration', 40944),
(465, 'frFR', 'Aura de dévotion', 40944),
(357407, 'frFR', 'Invocation de Havac', 40944),
(357406, 'frFR', 'Invocation de Battle Trak', 40944),
(357405, 'frFR', 'Invocation de Dirt Devil', 40944),
(356631, 'frFR', 'Invocation d\’Air Blade', 40944),
(328923, 'frFR', 'Transfusion faërique', 40944),
(101546, 'frFR', 'Coup tournoyant de la grue', 40944),
(364944, 'frFR', 'Marche-vent', 40944),
(228462, 'frFR', 'Chevalière de Melandrus', 40944),
(119611, 'frFR', 'Brume de rénovation', 40944),
(119607, 'frFR', 'Brume de rénovation', 40944),
(347944, 'frFR', 'Pointes d\’Obléron', 40944),
(347943, 'frFR', 'Endurance d\’Obléron', 40944),
(1714, 'frFR', 'Malédiction des langages', 40944);


DELETE FROM `transmog_set_locale` WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (2289,2287,2283,2281,2277,2275,2271,2269,2178));
INSERT INTO `transmog_set_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(2289, 'frFR', 'Armure de plaques du gladiateur déchaîné', 40944),
(2287, 'frFR', 'Armure de plaques du gladiateur déchaîné', 40944),
(2283, 'frFR', 'Cotte d\’anneaux du gladiateur déchaîné', 40944),
(2281, 'frFR', 'Cotte d\’anneaux du gladiateur déchaîné', 40944),
(2277, 'frFR', 'Armure du gladiateur déchaîné en cuir', 40944),
(2275, 'frFR', 'Armure du gladiateur déchaîné en cuir', 40944),
(2271, 'frFR', 'Habit du gladiateur déchaîné', 40944),
(2269, 'frFR', 'Habit du gladiateur déchaîné', 40944),
(2178, 'frFR', 'Armes des maîtres des sutures', 40944);


UPDATE `transmog_set_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='frFR' AND `ID` IN (2221,2220,2219,2218,2217,2216,2215,2214,2213,2212,2211,2210,2209,2208,2207,2206,2205,2204,2203,2202));
DELETE FROM `achievement_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table_locale` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_blob` WHERE (`TableHash`=2948698321 AND `RecordId`=340 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='frFR') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='frFR') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='frFR') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='frFR') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='frFR') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='frFR') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='frFR') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='frFR') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='frFR') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='frFR') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='frFR') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='frFR') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='frFR') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='frFR') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='frFR') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='frFR') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=358927 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='frFR') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='frFR') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='frFR') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='frFR') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='frFR') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='frFR') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='frFR') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='frFR') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='frFR') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='frFR') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='frFR') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='frFR') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='frFR') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='frFR') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='frFR') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='frFR') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='frFR') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='frFR') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='frFR') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='frFR') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='frFR') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='frFR') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='frFR') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='frFR') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='frFR') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='frFR') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='frFR') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='frFR') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='frFR') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='frFR') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='frFR') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='frFR') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='frFR') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='frFR') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='frFR') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='frFR');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(2948698321, 340, 'frFR', 0xA53E23C86B3D8F59, 40944),
(261693969, 65165, 'frFR', 0xFFFFFFFFFFFFFFFF556E6520C3A26D65207365636F757261626C65000044AC546F010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000000000000, 40944),
(3776013982, 361952, 'frFR', 0x00416A6F75746520247331C2A0756E6974C3A9732064E28099616E696D612061752072C3A9736572766F697220646520766F74726520636F6E6772C3A9676174696F6E2061637475656C6C652E0000, 40944),
(3776013982, 256817, 'frFR', 0x00566F7320736F72747320657420746563686E6971756573206F6E7420756E65206368616E636520646520766F7573206F6374726F79657220756E20626F6E75732064652024323536383138733120C3A0206C6120766974657373652C206CE28099C389766974656D656E74206574206C6120506F6E6374696F6E2070656E64616E742024323536383138642E0D0A0D0A7C6346464646464646464772616E646575722064E28099416D616EE280995468756C7C720D0A4C6F7273717565206C652050616E7468C3A96F6E20766F75732072656E666F7263652C20766F74726520243F28613133373030357C613133373034377C613133373032387C61313337303237295B466F7263655D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295B4167696C6974C3A95D5B496E74656C6C6967656E63655D20657374206175676D656E74C3A965206465202432353638333273312070656E64616E742024323536383332642E0000, 40944),
(3776013982, 247692, 'frFR', 0x00566F73206368616E6365732064E280996F6274656E697220756E6520626FC3AE746520C3A020736F7576656E69727320706172206C6520626961697320646573207361626C65732064752074656D707320736F6E74206175676D656E74C3A965732E204C657320626FC3AE7465732072656E6665726D656E74206465207075697373616E7473206F626A657473207175692072C3A964756973656E74206772616E64656D656E74206C6120646966666963756C74C3A9206465732064C3A9666973204368726F6E6F706F727461696C2E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722076697465737365732064652064C3A9706C6163656D656E742065742064652064C3A9706C6163656D656E74206D6F6E74C3A9206175676D656E74C3A9657320646520247332252E00566F73206368616E6365732064E280996F6274656E697220756E6520626FC3AE746520C3A020736F7576656E69727320706172206C6520626961697320646573207361626C65732064752074656D707320736F6E74206175676D656E74C3A965732E204C657320626FC3AE7465732072656E6665726D656E74206465207075697373616E7473206F626A657473207175692072C3A964756973656E74206772616E64656D656E74206C6120646966666963756C74C3A9206465732064C3A9666973204368726F6E6F706F727461696C2E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722076697465737365732064652064C3A9706C6163656D656E742065742064652064C3A9706C6163656D656E74206D6F6E74C3A9206175676D656E74C3A9657320646520247332252E00, 40944),
(3776013982, 247111, 'frFR', 0x00566F73206368616E6365732064E280996F6274656E697220756E206472616B652062726F6E7A6520706172206C6520626961697320646573207361626C65732064752074656D707320736F6E74206175676D656E74C3A965732E204C65206472616B6520707572676520696E7374616E74616EC3A96D656E7420756E2073616E6374756169726520647261636F6E697175652E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722064C3A967C3A2747320657420736F696E73206175676D656E74C3A97320646520247332252E00566F73206368616E6365732064E280996F6274656E697220756E206472616B652062726F6E7A6520706172206C6520626961697320646573207361626C65732064752074656D707320736F6E74206175676D656E74C3A965732E204C65206472616B6520707572676520696E7374616E74616EC3A96D656E7420756E2073616E6374756169726520647261636F6E697175652E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722064C3A967C3A2747320657420736F696E73206175676D656E74C3A97320646520247332252E00, 40944),
(3776013982, 247110, 'frFR', 0x0044C3A9626C6F717565206C657320706F727461696C732076657273206C65732064696666C3A972656E74732073616E637475616972657320647261636F6E6971756573206175205265706F73206475207665722E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722076697465737365732064652064C3A9706C6163656D656E742065742064652064C3A9706C6163656D656E74206D6F6E74C3A9206175676D656E74C3A9657320646520247332252E0044C3A9626C6F717565206C657320706F727461696C732076657273206C65732064696666C3A972656E74732073616E637475616972657320647261636F6E6971756573206175205265706F73206475207665722E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722076697465737365732064652064C3A9706C6163656D656E742065742064652064C3A9706C6163656D656E74206D6F6E74C3A9206175676D656E74C3A9657320646520247332252E00, 40944),
(3776013982, 247104, 'frFR', 0x004C65732076697465737365732064652064C3A9706C6163656D656E742065742064652064C3A9706C6163656D656E74206D6F6E74C3A920736F6E74206175676D656E74C3A9657320646520247331252E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722064C3A967C3A2747320657420736F696E73206175676D656E74C3A97320646520247332252E004C65732076697465737365732064652064C3A9706C6163656D656E742065742064652064C3A9706C6163656D656E74206D6F6E74C3A920736F6E74206175676D656E74C3A9657320646520247331252E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722064C3A967C3A2747320657420736F696E73206175676D656E74C3A97320646520247332252E00, 40944),
(3776013982, 247103, 'frFR', 0x0024407370656C6C646573633234343935390D0A0D0A7C634646303046463030426F6E7573C2A03A7C722064C3A967C3A2747320657420736F696E73206175676D656E74C3A9732064652035252E0000, 40944),
(3776013982, 247099, 'frFR', 0x004C612072C3A97075746174696F6E2071756520766F7573206761676E657A2061757072C3A873206465204368726F6D696520656E2066616973616E74206465732076696374696D657320657374206175676D656E74C3A965206465202432343737363973312520647572616E74206C6573206465726E69C3A8726573202432343737363964206574206465202432343737373073312520647572616E74206C6573206465726E69C3A87265732024323437373730642E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722076697465737365732064652064C3A9706C6163656D656E742065742064652064C3A9706C6163656D656E74206D6F6E74C3A9206175676D656E74C3A9657320646520247332252E0000, 40944),
(3776013982, 247096, 'frFR', 0x000000, 40944),
(3776013982, 247094, 'frFR', 0x00566F73206368616E6365732064652074726F7576657220646573207361626C65732064752074656D707320736F6E74206175676D656E74C3A9657320646520247331252E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C7220706F696E747320646520766965206175676D656E74C3A97320646520247332252E00566F73206368616E6365732064652074726F7576657220646573207361626C65732064752074656D707320736F6E74206175676D656E74C3A9657320646520247331252E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C7220706F696E747320646520766965206175676D656E74C3A97320646520247332252E00, 40944),
(3776013982, 247093, 'frFR', 0x000000, 40944),
(3776013982, 247092, 'frFR', 0x000000, 40944),
(3776013982, 247089, 'frFR', 0x0024407370656C6C646573633234353530330D0A0D0A7C634646303046463030426F6E7573C2A03A7C722064C3A967C3A274732C20736F696E732C20706F696E7473206465207669652C20766974657373652064652064C3A9706C6163656D656E7420657420766974657373652064652064C3A9706C6163656D656E74206D6F6E74C3A920736F6E74206175676D656E74C3A97320646520247332252E0000, 40944),
(3776013982, 247088, 'frFR', 0x004368726F6D69652072C3A976C3A86C65206C657320636F66667265732070726F636865732E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722064C3A967C3A2747320657420736F696E73206175676D656E74C3A97320646520247332252E004368726F6D69652072C3A976C3A86C65206C657320636F66667265732070726F636865732E0D0A0D0A7C634646303046463030426F6E7573C2A03A7C722064C3A967C3A2747320657420736F696E73206175676D656E74C3A97320646520247332252E00, 40944),
(3479059991, 9040, 'frFR', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'frFR', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'frFR', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'frFR', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'frFR', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'frFR', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'frFR', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'frFR', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'frFR', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'frFR', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'frFR', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'frFR', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'frFR', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'frFR', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'frFR', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'frFR', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'frFR', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'frFR', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'frFR', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'frFR', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'frFR', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'frFR', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'frFR', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'frFR', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'frFR', 0x0024407370656C6C6465736332323838323900247331C2A0706F696E74732064652064C3A967C3A274732064652046657520696E666C6967C3A97320746F75746573206C657320243232383832397431C2A0732E00, 40944),
(3776013982, 227799, 'frFR', 0x00446573207661677565732064E280996561752064C3A96665726C656E7420646570756973206C657320626F726473206465206C612073616C6C652C20696E666C696765616E7420247331C2A0706F696E74732064652064C3A967C3A274732064652047697672652061757820706572736F6E6E616765732D6A6F7565757273207175E28099656C6C657320706572637574656E742E0000, 40944),
(3776013982, 227780, 'frFR', 0x004D617271756520746F7573206C657320706572736F6E6E616765732D6A6F756575727320617665632024407370656C6C6E616D653232373738302E20C3802065787069726174696F6E2C20696E666C69676520247331C2A0706F696E74732064652064C3A967C3A27473206465204E61747572652061757820706572736F6E6E616765732D6A6F756575727320C3A0206D6F696E7320646520244131C2A06DC3A8747265732E00C3802065787069726174696F6E2C20696E666C69676520247331C2A0706F696E74732064652064C3A967C3A27473206465204E61747572652061757820706572736F6E6E616765732D6A6F756575727320C3A0206D6F696E7320646520244131C2A06DC3A8747265732E00, 40944),
(3386291891, 116804, 'frFR', 0x416374657572206465207363C3A86E6500000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'frFR', 0x41726368696D616765204B686164676172000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'frFR', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'frFR', 0x4E69656C6173204172616E0000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'frFR', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'frFR', 0x4C6520436F6E736572766174657572000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'frFR', 0x004F757672657A20766F747265207061676520646520636F6D7061676E6F6E732065742073C3A96C656374696F6E6E657A20756E20636F6D7061676E6F6E20706F75722066616972652070617373657220736F6E206E697665617520C3A0202473312E0000, 40944),
(261693969, 60399, 'frFR', 0xFFFFFFFFFFFFFFFF4175207365636F75727320646520526576656E647265746800003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'frFR', 0xFFFFFFFFFFFFFFFF4175207365636F757273206465204D616C6472617878757300003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'frFR', 0xFFFFFFFFFFFFFFFF4175207365636F7572732064752042617374696F6E00003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'frFR', 0xFFFFFFFFFFFFFFFF4175207365636F7572732064652053796C76617264656E00003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'frFR', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'frFR', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'frFR', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'frFR', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'frFR', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'frFR', 0x00000000, 40944),
(3865974254, 176921, 'frFR', 0x00000000, 40944),
(3865974254, 176832, 'frFR', 0x00000000, 40944),
(3776013982, 243328, 'frFR', 0x00004E6976656175206465206D656E6163652072C3A9647569742E00, 40944),
(3865974254, 187935, 'frFR', 0x00000000, 40944),
(3205218938, 44300, 'frFR', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F58004C69657A20756E2041757468656E74696361746F7220657420534D532050726F7465637420C3A020766F74726520636F6D70746520706F75722064C3A9626C6F71756572206365206368616D702E0001, 40944),
(3205218938, 44299, 'frFR', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C636666666630303030566F7573206E6520706F7576657A207061732070726F706F7365722064652067726F757065206D79746869717565C2A02B2073616E7320636CC3A9206D79746869717565206176616E742064E2809961766F69722073C3A96375726973C3A920766F74726520636F6D70746520C3A0206CE2809961696465206465206CE2809941757468656E74696361746F7220426174746C652E6E657420657420534D532050726F746563742E7C727C6E7C6366663165666630303C436C697175657A20706F757220706C75732064E28099696E666F726D6174696F6E732E3E7C720001, 40944),
(3205218938, 44284, 'frFR', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C636666666630303030566F7573206E6520706F7576657A20706173206D6F646966696572206365206368616D70206176616E742064E2809961766F69722073C3A96375726973C3A920766F74726520636F6D70746520C3A0206CE2809961696465206465206CE2809941757468656E74696361746F7220426174746C652E6E657420657420534D532050726F74656374202E7C727C6E7C6366663165666630303C436C697175657A20706F757220706C75732064E28099696E666F726D6174696F6E732E3E7C720001, 40944),
(3205218938, 44283, 'frFR', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F444553430044C3A9626C6F7175657A206CE28099616363C3A87320636F6D706C657420C3A0206CE280996F7574696C206465207265636865726368652064652067726F75706520656E206C69616E7420756E2041757468656E74696361746F7220657420534D532050726F7465637420C3A020766F74726520636F6D7074652E7C6E7C6E4CE2809941757468656E74696361746F7220426174746C652E6E65742065737420756E207365727669636520677261747569742065742073696D706C652064E280997574696C69736174696F6E2C207175692070726F74C3A8676520766F74726520636F6D7074652064657320616363C3A873206E6F6E206175746F726973C3A9732C20657420534D532050726F7465637420766F7573207369676E616C6520746F7574206368616E67656D656E7420696D706F7274616E74206170706F7274C3A920C3A020766F74726520636F6D7074652E7C6E7C6E436C697175657A20737572204163746976657220706F757220616363C3A9646572206175207369746520496E7465726E65742064E28099696E7374616C6C6174696F6E206465206CE2809941757468656E74696361746F722E0001, 40944),
(3776013982, 358927, 'frFR', 0x00456E20C3A97461742064E28099616C657274652C20766F757320766F7573206DC3A96669657A20646520746F75742063652071756920766F757320656E746F7572652E2054656D70732064652072656368617267652072C3A96475697420706F7572206C65732053616372656E7569742E005365206DC3A9666965206465206365757820717569206CE28099656E746F7572656E742E00, 40944),
(3865974254, 188152, 'frFR', 0x00000000, 40944),
(3776013982, 53385, 'frFR', 0x004C6962C3A8726520756E20746F757262696C6C6F6E2064E28099C3A96E657267696520646976696E652071756920696E666C69676520247331C2A0706F696E74732064652064C3A967C3A274732064752053616372C3A92061757820656E6E656D69732070726F636865732E204C65732064C3A967C3A2747320736F6E742072C3A964756974732061752D64656CC3A020646520247332C2A06369626C65732E0000, 40944),
(261693969, 62694, 'frFR', 0xFFFFFFFFFFFFFFFF556E20617070656C206465204D616C64726178787573000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'frFR', 0xFFFFFFFFFFFFFFFF556E20617070656C2064652053796C76617264656E000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'frFR', 0xFFFFFFFFFFFFFFFF556E20617070656C2064752042617374696F6E000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'frFR', 0xFFFFFFFFFFFFFFFF556E20617070656C20646520526576656E6472657468000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'frFR', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'frFR', 0x000000, 40944),
(3776013982, 307934, 'frFR', 0x000000, 40944),
(3776013982, 307480, 'frFR', 0x00566F7573206C616E63657A20766F747265207075726F74696E206DC3BB722E0000, 40944),
(2948698321, 354, 'frFR', 0x64DF8D9146629CB2, 40944),
(261693969, 60111, 'frFR', 0xFFFFFFFFFFFFFFFF4E6F75657220756E6520616D697469C3A900005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'frFR', 0xFFFFFFFFFFFFFFFF556E6520616D697469C3A920686F727320647520636F6D6D756E00005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'frFR', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'frFR', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'frFR', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'frFR', 0x00000000, 40944),
(3865974254, 151804, 'frFR', 0x00000000, 40944),
(3865974254, 151792, 'frFR', 0x00000000, 40944),
(3037505077, 151792, 'frFR', 0x0100, 40944),
(3865974254, 151790, 'frFR', 0x00000000, 40944),
(3037505077, 151790, 'frFR', 0x0100, 40944),
(3865974254, 146306, 'frFR', 0x00000000, 40944),
(3865974254, 34685, 'frFR', 0x00000000, 40944),
(3865974254, 34683, 'frFR', 0x00000000, 40944),
(3865974254, 34087, 'frFR', 0x00000000, 40944),
(3865974254, 34085, 'frFR', 0x00000000, 40944),
(3865974254, 33969, 'frFR', 0x00000000, 40944),
(3865974254, 33968, 'frFR', 0x00000000, 40944),
(3865974254, 33967, 'frFR', 0x00000000, 40944),
(3865974254, 33966, 'frFR', 0x00000000, 40944),
(3865974254, 33868, 'frFR', 0x00000000, 40944),
(3865974254, 33864, 'frFR', 0x00000000, 40944),
(3865974254, 33863, 'frFR', 0x00000000, 40944),
(3865974254, 33862, 'frFR', 0x00000000, 40944),
(3865974254, 23324, 'frFR', 0x00000000, 40944),
(3865974254, 21525, 'frFR', 0x00000000, 40944),
(3865974254, 21524, 'frFR', 0x00000000, 40944),
(3865974254, 19028, 'frFR', 0x00000000, 40944),
(3865974254, 6835, 'frFR', 0x00000000, 40944),
(3865974254, 6833, 'frFR', 0x00000000, 40944),
(3865974254, 181321, 'frFR', 0x00000000, 40944),
(1548466975, 27672, 'frFR', 0x10040000, 40944),
(3776013982, 365080, 'frFR', 0x0000566974657373652064652064C3A9706C6163656D656E74206175676D656E74C3A96520646520247331252E00, 40944),
(3776013982, 317920, 'frFR', 0x004C6120647572C3A96520646573206566666574732064E28099696E74657272757074696F6E2065742064652073696C656E6365206170706C697175C3A97320617578206D656D627265732064752067726F757065206F75207261696420C3A0206D6F696E7320646520246131C2A06DC3A874726573206573742072C3A9647569746520646520247331252E20243F733333393132345B4C657320656666657473206465207065757220736F6E7420C3A967616C656D656E742072C3A964756974732E5D5B5D004566666574732064E28099696E74657272757074696F6E2065742064652073696C656E63652072C3A9647569747320646520247731252E20243F733333393132345B45666665747320646520706575722072C3A9647569747320646520247734252E5D5B5D00, 40944),
(3776013982, 465, 'frFR', 0x004C6573206D656D627265732064752067726F757065206F75207261696420C3A0206D6F696E7320646520246131C2A06DC3A87472657320736F6E742067616C76616E6973C3A97320706172206C6575722064C3A9766F74696F6E2C206365207175692072C3A964756974206C65732064C3A967C3A27473207175E28099696C7320737562697373656E7420646520247331252E0044C3A967C3A274732073756269732072C3A9647569747320646520247731252E00, 40944),
(3205218938, 44172, 'frFR', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F44455343004F6274656E697220756E6520636F74652064652031393530206F7520737570C3A972696575726520706F7572206761676E6572C2A03A7C6E2D2052616E672064E28099616DC3A96C696F726174696F6E2064E280996F626A6574204A634A0001, 40944),
(3205218938, 40887, 'frFR', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F44455343004F6274656E697220756E6520636F74652064652031383030206F7520737570C3A972696575726520706F7572206761676E6572C2A03A7C6E2D20546974726520646520726976616C7C6E2D204170706172656E6365206465206CE28099656E73656D626C65204A634A2064E28099C3A96C697465C2A03A20686561756D657C6E2D204170706172656E6365206465206CE28099656E73656D626C65204A634A2064E28099C3A96C697465C2A03A20C3A97061756C65730001, 40944),
(3205218938, 40885, 'frFR', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F44455343004F6274656E697220756E6520636F74652064652031343030206F7520737570C3A972696575726520706F7572206761676E6572C2A03A7C6E2D20546974726520646520636F6D70C3A97469746575727C6E2D204170706172656E6365206465206CE28099656E73656D626C65204A634A2064E28099C3A96C697465C2A03A2067616E74737C6E2D204170706172656E6365206465206CE28099656E73656D626C65204A634A2064E28099C3A96C697465C2A03A20626F747465730001, 40944),
(3776013982, 357407, 'frFR', 0x00566F757320696E766F7175657A20657420636F6E7472C3B46C657A20766F74726520526F636B696EE2809920526F6C6C696EE280992052616365722C206C65204D61726175646575722E005574696C6973657A206C612062617272652064E28099616374696F6E7320706F75722061747461717565722064E28099617574726573206A6F756574732074C3A96CC3A9636F6D6D616E64C3A9732E00, 40944),
(3776013982, 357406, 'frFR', 0x00566F757320696E766F7175657A20657420636F6E7472C3B46C657A20766F74726520526F636B696EE2809920526F6C6C696EE280992052616365722C206C65204D61726175646575722E005574696C6973657A206C612062617272652064E28099616374696F6E7320706F75722061747461717565722064E28099617574726573206A6F756574732074C3A96CC3A9636F6D6D616E64C3A9732E00, 40944),
(3776013982, 357405, 'frFR', 0x00566F757320696E766F7175657A20657420636F6E7472C3B46C657A20766F74726520526F636B696EE2809920526F6C6C696EE280992052616365722C206C65204D61726175646575722E005574696C6973657A206C612062617272652064E28099616374696F6E7320706F75722061747461717565722064E28099617574726573206A6F756574732074C3A96CC3A9636F6D6D616E64C3A9732E00, 40944),
(3776013982, 356631, 'frFR', 0x00566F757320696E766F7175657A20657420636F6E7472C3B46C657A20766F74726520526F636B696EE2809920526F6C6C696EE280992052616365722C206CE2809941697220426C6164652E005574696C69736572206C612062617272652064E28099616374696F6E7320706F75722061747461717565722064E28099617574726573206A6F756574732074C3A96CC3A9636F6D6D616E64C3A9732E00, 40944),
(3776013982, 328923, 'frFR', 0x4661C3AB206E6F637475726E657300566F7573207472616E73667573657A206C6120666F72636520766974616C652064E28099756E206D6178696D756D206465202433323839323849C2A0656E6E656D69732064616E73206C61207A6F6E65206369626CC3A9652C20636520717569206C65757220696E666C69676520756E20746F74616C20646520247B282433323839323873312A24642F24743229202B202433323839323873317DC2A0706F696E74732064652064C3A967C3A27473206465204E61747572652072C3A970617274697320C3A97175697461626C656D656E7420656E2024642E243F613133373034315B0D0A0D0A43616E616C69736572205472616E73667573696F6E206661C3AB7269717565206A75737175E28099617520626F75742067C3A96EC3A8726520247334C2A0246C6368617267653A636861726765733B2064E2809941726D65206475204D61656C737472C3B66D2E5D5B5D0D0A0D0A5574696C6973657A20C3A0206E6F7576656175205472616E73667573696F6E206661C3AB72697175652064616E73206C657320243332383933336420706F7572206C6962C3A97265722024733125206465207365732064C3A967C3A2747320657420736F69676E6572206A75737175E28099C3A020243332383933307332C2A0616C6C69C3A97320C3A0206D6F696E7320646520243332383933304131C2A06DC3A8747265732E0000, 40944),
(3776013982, 101546, 'frFR', 0x00566F757320746F75726E6F79657A2064616E73206C6573206169727320656E20617373C3A96E616E742064657320636F75707320646520706965642071756920696E666C6967656E7420243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5DC2A0706F696E74732064652064C3A967C3A274732070687973697175657320656E2024642061757820656E6E656D697320C3A0206D6F696E7320646520243130373237304131C2A06DC3A8747265732E204C65732064C3A967C3A2747320736F6E742072C3A964756974732061752D64656CC3A020646520247331C2A06369626C65732E243F63335B0D0A0D0A4C65732064C3A967C3A2747320646520436F757020746F75726E6F79616E74206465206C61206772756520736F6E74206175676D656E74C3A973206465202432323033353873312520706172206369626C6520756E6971756520746F756368C3A96520617520636F75727320646573202432323033353864207072C3A963C3A964656E7465732061766563205061756D652064752054696772652C2046726170706520647520766F696C65206E6F6972206F7520436F7570206465207069656420647520736F6C65696C206C6576616E742E2043756D756C61626C65206A75737175E28099C3A0202432323832383769C2A0666F69732E5D5B5D0041747461717565206C657320656E6E656D69732070726F63686573206574206C65757220696E666C696765206465732064C3A967C3A274732070687973697175657320746F75746573206C657320243130313534367431C2A0732E00, 40944),
(3865974254, 188220, 'frFR', 0x00000000, 40944),
(3865974254, 187900, 'frFR', 0x00000000, 40944),
(3865974254, 187899, 'frFR', 0x00000000, 40944),
(3865974254, 187898, 'frFR', 0x00000000, 40944),
(3865974254, 187897, 'frFR', 0x00000000, 40944),
(3865974254, 187896, 'frFR', 0x00000000, 40944),
(3865974254, 187895, 'frFR', 0x00000000, 40944),
(3865974254, 187875, 'frFR', 0x00000000, 40944),
(3865974254, 187869, 'frFR', 0x00000000, 40944),
(3865974254, 150746, 'frFR', 0x00000000, 40944),
(3865974254, 150745, 'frFR', 0x00000000, 40944),
(3865974254, 150744, 'frFR', 0x00000000, 40944),
(3865974254, 150743, 'frFR', 0x00000000, 40944),
(3776013982, 364944, 'frFR', 0x0000566974657373652064652064C3A9706C6163656D656E74206175676D656E74C3A96520646520247331252E00, 40944),
(3776013982, 228462, 'frFR', 0x004175676D656E7465206C65732064C3A967C3A2747320646520766F7472652061747461717565206175746F6D617469717565206465202473312E0000, 40944),
(3776013982, 119611, 'frFR', 0x0024407370656C6C646573633131353135310052656E642024773120706F696E74732064652076696520746F75746573206C65732024743120732E00, 40944),
(3776013982, 119607, 'frFR', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'frFR', 0x00000000, 40944),
(1181150530, 403396, 'frFR', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'frFR', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'frFR', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'frFR', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'frFR', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'frFR', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'frFR', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'frFR', 0xA4530000, 40944),
(3359787322, 21411, 'frFR', 0xA3530000, 40944),
(3359787322, 21410, 'frFR', 0xA2530000, 40944),
(3359787322, 21409, 'frFR', 0xA1530000, 40944),
(3359787322, 21408, 'frFR', 0xA0530000, 40944),
(3359787322, 21407, 'frFR', 0x9F530000, 40944),
(3359787322, 21406, 'frFR', 0x9E530000, 40944),
(2557447376, 655518, 'frFR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'frFR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'frFR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'frFR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'frFR', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'frFR', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F454646454354004C65732072C3A8676C657320646520627574696E20686973746F726971756573206E6520736F6E7420706C7573206163746976C3A965732E0001, 40944),
(3776013982, 347944, 'frFR', 0x004368616E63657320646520636F7570206372697469717565206175676D656E74C3A9657320646520247331252E0D0A004368616E63657320646520636F7570206372697469717565206175676D656E74C3A9657320646520247331252E00, 40944),
(3776013982, 347943, 'frFR', 0x004D6178696D756D20646520706F696E747320646520766965206175676D656E74C3A920646520247331252E004D6178696D756D20646520706F696E747320646520766965206175676D656E74C3A920646520247331252E00, 40944),
(3776013982, 1714, 'frFR', 0x004F626C696765206C61206369626C6520C3A0207061726C657220656E206C616E6775652064C3A96D6F6E6961717565206574206175676D656E7465206C652074656D70732064E28099696E63616E746174696F6E2064657320736F72747320646520247331252070656E64616E742024642E243F733130333131325B0D0A0D0A7C4346464535354242306346464646464646464272C3BB6C7572652064E28099C3A26D65203A20766F747265204D616CC3A964696374696F6E20646573206C616E6761676573206166666563746520746F7573206C657320656E6E656D697320C3A0206D6F696E73206465202431303432323441206DC3A87472657320646520766F747265206369626C652E7C525D5B5D0D0A0D0A7C6346463832383246464D616CC3A964696374696F6E73203A20756E65207365756C65206D616CC3A964696374696F6E207061722064C3A96D6F6E69737465207065757420C3AA747265206163746976652073757220756E65206369626C652E7C72005061726C65206C652064C3A96D6F6E69617175652C20636520717569206175676D656E74652064652024773125206C652074656D70732064E28099696E63616E746174696F6E2064657320736F7274732E00, 40944),
(3205218938, 41865, 'frFR', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E5300566F7573206EE280996176657A20706173206CE280996175746F7269736174696F6E206465206D6F646966696572206C657320696E666F7320646520726563727574656D656E742E0001, 40944),
(261693969, 64850, 'frFR', 0xFFFFFFFFFFFFFFFF54726176657273C3A96520646520546F75726D656E74000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'frFR', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='frFR') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='frFR');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'frFR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `achievement_locale` WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (14775,14752,14682,14351));
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14775, 'itIT', 'Diventa Osannato da Marasmio.', 'Che marasma', 'Ricompensa: titolo \"Amiceto / Amiceta\"', 40944),
(14752, 'itIT', 'Compi le imprese delle Cuciture Abominevoli elencate qui sotto.', 'Cose da fare da morti', 'Ricompensa: titolo \" Abominevole\" e Ricompensa: cavalcatura \"Tauralus Prescelto Corazzato\"', 40944),
(14682, 'itIT', 'Compi le imprese della Corte delle Braci elencate qui sotto.', 'L\'Alfiere della Festa', 'Ricompensa: titolo \"l\'Alfiere della Festa\"', 40944),
(14351, 'itIT', 'Sconfiggi 39 boss nella Via dell\'Ascensione.', 'La Via Verso l\'Ascensione 39', 'Sblocca altre sfide nella Via dell\'Ascensione.', 40944);


DELETE FROM `area_table_locale` WHERE (`VerifiedBuild`>0 AND `ID`=13316 AND `locale`='itIT');
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(13316, 'itIT', 'Casata dei Rituali', 40944);


DELETE FROM `battle_pet_species_locale` WHERE (`VerifiedBuild`>0 AND `ID`=3188 AND `locale`='itIT');
INSERT INTO `battle_pet_species_locale` (`ID`, `locale`, `Description_lang`, `SourceText_lang`, `VerifiedBuild`) VALUES
(3188, 'itIT', '', '', 40944);


DELETE FROM `broadcast_text_locale` WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (215513,215512,215511));
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(215513, 'itIT', '', 'Sarebbe poco saggio avventurarsi nella Fauce impreparati. Torna da me quando sarai $gpronto:pronta;.', 40944),
(215512, 'itIT', 'Sarebbe poco saggio avventurarsi nella Fauce impreparati. Torna da me quando sarai $gpronto:pronta;.', '', 40944),
(215511, 'itIT', '', 'Manca così poco. Combatti al mio fianco e supereremo tutto questo insieme.', 40944);


DELETE FROM `char_titles_locale` WHERE (`VerifiedBuild`>0 AND `ID`=693 AND `locale`='itIT');
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(693, 'itIT', '%s l\'Asceso', '%s l\'Ascesa', 40944);


UPDATE `char_titles_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=683 AND `locale`='itIT');
DELETE FROM `chr_customization_option_locale` WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (1523,689));
INSERT INTO `chr_customization_option_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1523, 'itIT', 'Coda', 40944),
(689, 'itIT', 'Coda', 40944);


DELETE FROM `criteria_tree_locale` WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (91730,94390,94389,94388,93811,93810,94331,94330));
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91730, 'itIT', '9.1 Meta Impresa', 40944),
(94390, 'itIT', '', 40944),
(94389, 'itIT', '', 40944),
(94388, 'itIT', '', 40944),
(93811, 'itIT', '', 40944),
(93810, 'itIT', 'Livello di Fama 80', 40944),
(94331, 'itIT', '', 40944),
(94330, 'itIT', 'Renown Level 80 - Kyrian', 40944);


DELETE FROM `item_search_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,116401));
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(151806, 'itIT', 'Vestito Elegante', 40944),
(151804, 'itIT', 'Pantaloni Neri da Smoking', 40944),
(151792, 'itIT', 'Giacca di Grande Inverno Verde', 40944),
(151790, 'itIT', 'Giacca di Grande Inverno Rossa', 40944),
(34685, 'itIT', 'Tunica dell\'Estate', 40944),
(34683, 'itIT', 'Grancalzari dell\'Estate', 40944),
(34087, 'itIT', 'Giacca di Grande Inverno Verde', 40944),
(34085, 'itIT', 'Giacca di Grande Inverno Rossa', 40944),
(33969, 'itIT', 'Cappello Viola della Festa della Birra', 40944),
(33968, 'itIT', 'Cappello Blu della Festa della Birra', 40944),
(33967, 'itIT', 'Cappello Verde della Festa della Birra', 40944),
(33966, 'itIT', 'Pianelle della Festa della Birra', 40944),
(33868, 'itIT', 'Stivali della Festa della Birra', 40944),
(33864, 'itIT', 'Cappello Marrone della Festa della Birra', 40944),
(33863, 'itIT', 'Vestito della Festa della Birra', 40944),
(33862, 'itIT', 'Completo della Festa della Birra', 40944),
(23324, 'itIT', 'Coprispalle dei Fuochi di Mezza Estate', 40944),
(21525, 'itIT', 'Berretto di Grande Inverno Verde', 40944),
(21524, 'itIT', 'Berretto di Grande Inverno Rosso', 40944),
(19028, 'itIT', 'Vestito Elegante', 40944),
(6835, 'itIT', 'Pantaloni Neri da Smoking', 40944),
(6833, 'itIT', 'Camicia Bianca da Smoking', 40944),
(181321, 'itIT', 'Bacchetta Incoronata di Gemme', 40944),
(116401, 'itIT', 'Cappello Elegante del Pellegrino', 40944);


DELETE FROM `item_sparse_locale` WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (176922,176921,176832,187935,188152,151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,188220,187900,187899,187898,187897,187896,187895,187875,187869,150746,150745,150744,150743,116401));
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(176922, 'itIT', 'Quantità di materiali d\'artigianato offerta dagli Spiriti Rinati e dei Catalizzatori generati dai Semi Catalizzatori aumentata del 100%.', '', '', '', 'Bocciolo Notturno Selvaggio', 40944),
(176921, 'itIT', 'Queste foglie magiche riducono la durata del processo dei Semebrado della Ricrescita di 1 giorno.', '', '', '', 'Foglie Temporali', 40944),
(176832, 'itIT', 'Questa radice speciale aumenta la qualità delle ricompense offerte da uno spirito alla rinascita.', '', '', '', 'Grano di Radice di Semebrado', 40944),
(187935, 'itIT', 'Ti insegna a creare un Marchio del Cervo delle Rune di Mezzanotte.', '', '', '', 'Tecnica: Marchio della Cervo delle Rune di Mezzanotte', 40944),
(188152, 'itIT', 'La magia della scheggia brucia al tatto.', '', '', '', 'Scheggia di Controllo del Varco', 40944),
(151806, 'itIT', '', '', '', '', 'Vestito Elegante', 40944),
(151804, 'itIT', '', '', '', '', 'Pantaloni Neri da Smoking', 40944),
(151792, 'itIT', '', '', '', '', 'Giacca di Grande Inverno Verde', 40944),
(151790, 'itIT', '', '', '', '', 'Giacca di Grande Inverno Rossa', 40944),
(34685, 'itIT', '', '', '', '', 'Tunica dell\'Estate', 40944),
(34683, 'itIT', '', '', '', '', 'Grancalzari dell\'Estate', 40944),
(34087, 'itIT', '', '', '', '', 'Giacca di Grande Inverno Verde', 40944),
(34085, 'itIT', '', '', '', '', 'Giacca di Grande Inverno Rossa', 40944),
(33969, 'itIT', '', '', '', '', 'Cappello Viola della Festa della Birra', 40944),
(33968, 'itIT', '', '', '', '', 'Cappello Blu della Festa della Birra', 40944),
(33967, 'itIT', '', '', '', '', 'Cappello Verde della Festa della Birra', 40944),
(33966, 'itIT', '', '', '', '', 'Pianelle della Festa della Birra', 40944),
(33868, 'itIT', '', '', '', '', 'Stivali della Festa della Birra', 40944),
(33864, 'itIT', '', '', '', '', 'Cappello Marrone della Festa della Birra', 40944),
(33863, 'itIT', '', '', '', '', 'Vestito della Festa della Birra', 40944),
(33862, 'itIT', '', '', '', '', 'Completo della Festa della Birra', 40944),
(23324, 'itIT', '', '', '', '', 'Coprispalle dei Fuochi di Mezza Estate', 40944),
(21525, 'itIT', '', '', '', '', 'Berretto di Grande Inverno Verde', 40944),
(21524, 'itIT', '', '', '', '', 'Berretto di Grande Inverno Rosso', 40944),
(19028, 'itIT', '', '', '', '', 'Vestito Elegante', 40944),
(6835, 'itIT', '', '', '', '', 'Pantaloni Neri da Smoking', 40944),
(6833, 'itIT', '', '', '', '', 'Camicia Bianca da Smoking', 40944),
(181321, 'itIT', '', '', '', '', 'Bacchetta Incoronata di Gemme', 40944),
(188220, 'itIT', 'Sul fondo sono presenti le parole \"Sono sopravvissuto alla Torre\".', '', '', '', 'Globo di Cenere di Torgast', 40944),
(187900, 'itIT', 'Un Goblin e uno Gnomo descrivono le loro numerose scoperte nelle due isole.', '', '', '', 'Mappa d\'Esplorazione: Le Meraviglie di Kul Tiras e Zandalar', 40944),
(187899, 'itIT', 'Una guida avventurosa di un alchimista sugli incredibili biomi e sulla flora delle Terre Esterne.', '', '', '', 'Mappa d\'Esplorazione: Le Molte Curiosità delle Terre Esterne', 40944),
(187898, 'itIT', 'Un rapporto dettagliato di un Crociato d\'Argento su tutte le operazioni militari della caccia al Re dei Lich.', '', '', '', 'Mappa d\'Esplorazione: Il Vero Costo della Campagna di Nordania', 40944),
(187897, 'itIT', 'Un raro rapporto di fazione, che comprende le innumerevoli conseguenze della distruzione di Azeroth a opera di Alamorte.', '', '', '', 'Mappa d\'Esplorazione: Conseguenze del Cataclisma', 40944),
(187896, 'itIT', 'Una divertente storia delle ultime avventure di Li Li su Pandaria, con alcuni consigli sul cibo da parte di suo zio Chen.', '', '', '', 'Mappa d\'Esplorazione: Guida dei Triplo Malto di Pandaria', 40944),
(187895, 'itIT', 'Una lista dei pochi rifugi sicuri su Draenor e delle usanze locali che sarebbe meglio osservare in ognuno di essi.', '', '', '', 'Mappa d\'Esplorazione: I Pericoli di Draenor', 40944),
(187875, 'itIT', 'Una grande raccolta di rapporti e corrispondenza di diverse unità militari in combattimento contro la Legione.', '', '', '', 'Mappa d\'Esplorazione: Fronti Uniti delle Isole Disperse', 40944),
(187869, 'itIT', 'Una storia dettagliata sul viaggio di un Calcafauce attraverso i quattro regni delle Terretetre.', '', '', '', 'Mappa d\'Esplorazione: Nelle Terretetre', 40944),
(150746, 'itIT', 'Un\'umile proposta per migliorare le tempistiche dei rifornimenti per gli avamposti nei Regni Orientali.', '', '', '', 'Mappa d\'Esplorazione: Approvvigionamenti Moderni dei Regni Orientali', 40944),
(150745, 'itIT', 'Una guida completa all\'indebolimento delle forze dell\'Alleanza nei Regni Orientali in caso dovesse scoppiare una Quarta Guerra.', '', '', '', 'Mappa d\'Esplorazione: Campagna dei Regni Orientali', 40944),
(150744, 'itIT', 'Una cura per le cicatrici lasciate sulla terra dai malvagi, dai corrotti e dagli innaturali.', '', '', '', 'Mappa d\'Esplorazione: Passeggiare per Kalimdor con la Madre Terra', 40944),
(150743, 'itIT', 'Una guida esaustiva di tutte le bestie zannute, artigliate, velenose e affiliate dell\'Orda.', '', '', '', 'Mappa d\'Esplorazione: Sopravvivere a Kalimdor', 40944),
(116401, 'itIT', '', '', '', '', 'Cappello Elegante del Pellegrino', 40944);


UPDATE `item_sparse_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (185950,185947,185946));
DELETE FROM `lfg_dungeons_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1445 AND `locale`='itIT');
INSERT INTO `lfg_dungeons_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1445, 'itIT', 'Caduta dei Totem Vile', 'Impedisci a Tugar Totem Sanguinario e ai suoi vilvermi di far collassare la montagna.', 40944);


DELETE FROM `map_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1756 AND `locale`='itIT');
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(1756, 'itIT', 'Morti di Cromie', '', '', '', '', 40944);


DELETE FROM `player_condition_locale` WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (95078,95077,95076,85644,73006,73005,87365,85912,85910,85909,85692,94517,94516,94515,94514,94513,94512,94511));
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(95078, 'itIT', '', 40944),
(95077, 'itIT', '', 40944),
(95076, 'itIT', '', 40944),
(85644, 'itIT', 'Per continuare, devi aver raggiunto il livello $pcMinLevel.', 40944),
(73006, 'itIT', '', 40944),
(73005, 'itIT', '', 40944),
(87365, 'itIT', '', 40944),
(85912, 'itIT', '', 40944),
(85910, 'itIT', '', 40944),
(85909, 'itIT', '', 40944),
(85692, 'itIT', '', 40944),
(94517, 'itIT', '', 40944),
(94516, 'itIT', '', 40944),
(94515, 'itIT', '', 40944),
(94514, 'itIT', '', 40944),
(94513, 'itIT', '', 40944),
(94512, 'itIT', '', 40944),
(94511, 'itIT', '', 40944);


DELETE FROM `spell_category_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1186 AND `locale`='itIT');
INSERT INTO `spell_category_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1186, 'itIT', 'Class - Paladin - Hand of Sacrifice', 40944);


DELETE FROM `spell_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (361952,256817,247692,247111,247110,247104,247103,247099,247096,247094,247093,247092,247089,247088,228844,227799,227780,362986,243328,358927,53385,329902,307934,307480,365080,317920,465,357407,357406,357405,356631,328923,101546,364944,228462,119611,119607,347944,347943,1714));
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(361952, 'itIT', '1.000 Animum', 40944),
(256817, 'itIT', 'Marchio di Aman\'thul', 40944),
(247692, 'itIT', 'Continuum della Scatola Ricordo', 40944),
(247111, 'itIT', 'Blessing of the Bronze Dragonflight Passive', 40944),
(247110, 'itIT', 'Velocità Infinita', 40944),
(247104, 'itIT', 'Acceleration Passive', 40944),
(247103, 'itIT', 'Time Stop Passive', 40944),
(247099, 'itIT', 'Chrono Charisma Passive', 40944),
(247096, 'itIT', 'Rapid Recovery Passive', 40944),
(247094, 'itIT', 'Fortuito', 40944),
(247093, 'itIT', 'Determinazione del Drago Passiva', 40944),
(247092, 'itIT', 'Aggressione Accelerata Passiva', 40944),
(247089, 'itIT', 'Potere del Drago Passivo', 40944),
(247088, 'itIT', 'Consapevolezza', 40944),
(228844, 'itIT', 'Ossa Infuocate', 40944),
(227799, 'itIT', 'Lava Via', 40944),
(227780, 'itIT', 'Rituale del Tuono', 40944),
(362986, 'itIT', 'Esperienza', 40944),
(243328, 'itIT', 'Trasparenza', 40944),
(358927, 'itIT', 'Veglia della Guardia Nobile Oscura', 40944),
(53385, 'itIT', 'Tempesta Divina', 40944),
(329902, 'itIT', 'Dragaggio', 40944),
(307934, 'itIT', 'Dragaggio', 40944),
(307480, 'itIT', 'Lancio Draga', 40944),
(365080, 'itIT', 'Impeto', 40944),
(317920, 'itIT', 'Aura della Concentrazione', 40944),
(465, 'itIT', 'Aura della Devozione', 40944),
(357407, 'itIT', 'Evocazione: Havac', 40944),
(357406, 'itIT', 'Evocazione: Battle Trak', 40944),
(357405, 'itIT', 'Evocazione: Dirt Devil', 40944),
(356631, 'itIT', 'Evocazione: Air Blade', 40944),
(328923, 'itIT', 'Trasfusione dei Silfi', 40944),
(101546, 'itIT', 'Calcio Rotante della Gru', 40944),
(364944, 'itIT', 'Impeto', 40944),
(228462, 'itIT', 'Anello con Sigillo di Melandrus', 40944),
(119611, 'itIT', 'Nebbia Curativa', 40944),
(119607, 'itIT', 'Nebbia Curativa', 40944),
(347944, 'itIT', 'Aculei di Obleron', 40944),
(347943, 'itIT', 'Resistenza di Obleron', 40944),
(1714, 'itIT', 'Maledizione delle Lingue', 40944);


DELETE FROM `transmog_set_locale` WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (2289,2287,2283,2281,2277,2275,2271,2269,2178));
INSERT INTO `transmog_set_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(2289, 'itIT', 'Piastre del Gladiatore Liberato', 40944),
(2287, 'itIT', 'Piastre del Gladiatore Liberato', 40944),
(2283, 'itIT', 'Maglia del Gladiatore Liberato', 40944),
(2281, 'itIT', 'Maglia del Gladiatore Liberato', 40944),
(2277, 'itIT', 'Cuoio del Gladiatore Liberato', 40944),
(2275, 'itIT', 'Cuoio del Gladiatore Liberato', 40944),
(2271, 'itIT', 'Stoffa del Gladiatore Liberato', 40944),
(2269, 'itIT', 'Stoffa del Gladiatore Liberato', 40944),
(2178, 'itIT', 'Armi dei Maestri delle Suture', 40944);


UPDATE `transmog_set_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='itIT' AND `ID` IN (2221,2220,2219,2218,2217,2216,2215,2214,2213,2212,2211,2210,2209,2208,2207,2206,2205,2204,2203,2202));
DELETE FROM `achievement_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table_locale` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_blob` WHERE (`TableHash`=2948698321 AND `RecordId`=340 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='itIT') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='itIT') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='itIT') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='itIT') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='itIT') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='itIT') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='itIT') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='itIT') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='itIT') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='itIT') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='itIT') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='itIT') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='itIT') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='itIT') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='itIT') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='itIT') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=358927 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='itIT') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='itIT') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='itIT') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='itIT') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='itIT') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='itIT') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='itIT') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='itIT') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='itIT') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='itIT') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='itIT') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='itIT') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='itIT') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='itIT') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='itIT') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='itIT') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='itIT') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='itIT') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='itIT') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='itIT') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='itIT') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='itIT') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='itIT') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='itIT') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='itIT') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='itIT') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='itIT') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='itIT') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='itIT') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='itIT') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='itIT') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='itIT') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='itIT') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='itIT') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='itIT') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='itIT');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(2948698321, 340, 'itIT', 0xA53E23C86B3D8F59, 40944),
(261693969, 65165, 'itIT', 0xFFFFFFFFFFFFFFFF537570706F72746F20646120756E27616E696D61000044AC546F010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000000000000, 40944),
(3776013982, 361952, 'itIT', 0x0041676769756E67652024733120416E696D756D206E656C20426163696E6F2064656C6C612074756120436F6E67726567612061747475616C652E0000, 40944),
(3776013982, 256817, 'itIT', 0x00476C6920696E63616E746573696D692065206C65206162696C6974C3A02068616E6E6F20756E612070726F626162696C6974C3A02064692061756D656E74617265206C612076656C6F636974C3A02C206C27696E64696365206427656C7573696F6E652065206C27696E64696365206469207269746F726E6F20766974616C6520646920243235363831387331207065722024323536383138642E0D0A0D0A7C6346464646464646464772616E64657A7A6120646920416D616E277468756C7C720D0A496C20706F74656E7A69616D656E746F2064656C2050616E7468656F6E2061756D656E746120243F28613133373030357C613133373034377C613133373032387C61313337303237295B6C6120466F727A615D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295B6C274167696C6974C3A05D5B6C27496E74656C6C6574746F5D20646920243235363833327331207065722024323536383332642E0000, 40944),
(3776013982, 247692, 'itIT', 0x0041756D656E7461206C612070726F626162696C6974C3A0206469206F7474656E65726520756E6120536361746F6C61205269636F72646F2064616C6C65205361626269652064656C2054656D706F2E204C6520536361746F6C65205269636F72646F20636F6E74656E676F6E6F206F67676574746920706F74656E7469206368652072696475636F6E6F2073656E736962696C6D656E7465206C61206469666669636F6C74C3A02064656C6C65207366696465206465692043726F6E6F706F7274616C692E0D0A0D0A7C634646303046463030426F6E75733A7C722076656C6F636974C3A0206469206D6F76696D656E746F206520737520636176616C6361747572612061756D656E746174652064656C20247332252E0050726F626162696C6974C3A0206469206F7474656E65726520756E6120536361746F6C61205269636F72646F2064616C6C65205361626269652064656C2054656D706F2061756D656E746174612E204C6520536361746F6C65205269636F72646F20636F6E74656E676F6E6F206F67676574746920706F74656E7469206368652072696475636F6E6F2073656E736962696C6D656E7465206C61206469666669636F6C74C3A02064656C6C65207366696465206465692043726F6E6F706F7274616C692E0D0A0D0A7C634646303046463030426F6E75733A7C722076656C6F636974C3A0206469206D6F76696D656E746F206520737520636176616C6361747572612061756D656E746174652064656C20247332252E00, 40944),
(3776013982, 247111, 'itIT', 0x0041756D656E7461206C612070726F626162696C6974C3A0206469206F7474656E65726520756E20447261636F2042726F6E7A656F2064616C6C65205361626269652064656C2054656D706F2E20496C20647261636F20656C696D696E61206C61206D696E61636369612070726F76656E69656E746520646120756E2053616E74756172696F2064656920447261676869207065722074652E0D0A0D0A7C634646303046463030426F6E75733A7C722064616E6E6920696E666C697474692065206375726520666F726E6974652061756D656E746174692064656C20247332252E0050726F626162696C6974C3A0206469206F7474656E65726520756E20447261636F2042726F6E7A656F2064616C6C65205361626269652064656C2054656D706F2061756D656E746174612E20496C20647261636F20656C696D696E61206C61206D696E61636369612070726F76656E69656E746520646120756E2053616E74756172696F2064656920447261676869207065722074652E0D0A0D0A7C634646303046463030426F6E75733A7C722064616E6E6920696E666C697474692065206375726520666F726E6974652061756D656E746174692064656C20247332252E00, 40944),
(3776013982, 247110, 'itIT', 0x0053626C6F636361206920706F7274616C692064616C6C61204C656761206465692044726167686920696E206F676E756E6F206465692053616E747561726920646569204472616768692E0D0A0D0A7C634646303046463030426F6E75733A7C722076656C6F636974C3A0206469206D6F76696D656E746F206520737520636176616C6361747572612061756D656E746174652064656C20247332252E00506F7274616C692073626C6F63636174692064616C6C61204C656761206465692044726167686920696E206F676E756E6F206465692053616E747561726920646569204472616768692E0D0A0D0A7C634646303046463030426F6E75733A7C722076656C6F636974C3A0206469206D6F76696D656E746F206520737520636176616C6361747572612061756D656E746174652064656C20247332252E00, 40944),
(3776013982, 247104, 'itIT', 0x0041756D656E7461206C612076656C6F636974C3A0206469206D6F76696D656E746F206520737520636176616C6361747572612064656C20247331252E0D0A0D0A7C634646303046463030426F6E75733A7C722064616E6E6920696E666C697474692065206375726520666F726E6974652061756D656E746174692064656C20247332252E0056656C6F636974C3A0206469206D6F76696D656E746F206520737520636176616C6361747572612061756D656E7461746F2064656C20247331252E0D0A0D0A7C634646303046463030426F6E75733A7C722064616E6E6920696E666C697474692065206375726520666F726E6974652061756D656E746174692064656C20247332252E00, 40944),
(3776013982, 247103, 'itIT', 0x0024407370656C6C646573633234343935390D0A0D0A7C634646303046463030426F6E75733A7C722064616E6E6920696E666C697474692065206375726520666F726E6974652061756D656E746174692064656C2035252E0000, 40944),
(3776013982, 247099, 'itIT', 0x0041756D656E7461206C61207265707574617A696F6E65206775616461676E6174612064616C6C65207563636973696F6E6920636F6E2043726F6D69652064656C202432343737363973312520647572616E746520676C6920756C74696D6920243234373736396420652064656C202432343737373073312520647572616E746520676C6920756C74696D692024323437373730642E0D0A0D0A7C634646303046463030426F6E75733A7C722076656C6F636974C3A0206469206D6F76696D656E746F206520737520636176616C6361747572612061756D656E746174652064656C20247332252E0000, 40944),
(3776013982, 247096, 'itIT', 0x000000, 40944),
(3776013982, 247094, 'itIT', 0x0041756D656E7461206C612070726F626162696C6974C3A02064692074726F76617265205361626269652064656C2054656D706F2064656C20247331252E0D0A0D0A7C634646303046463030426F6E75733A7C722073616C7574652061756D656E746174612064656C20247332252E0050726F626162696C6974C3A02064692074726F76617265205361626269652064656C2054656D706F2061756D656E746174612064656C20247331252E0D0A0D0A7C634646303046463030426F6E75733A7C722073616C7574652061756D656E746174612064656C20247332252E00, 40944),
(3776013982, 247093, 'itIT', 0x000000, 40944),
(3776013982, 247092, 'itIT', 0x000000, 40944),
(3776013982, 247089, 'itIT', 0x0024407370656C6C646573633234353530330D0A0D0A7C634646303046463030426F6E75733A7C722064616E6E6920696E666C697474692C206375726520666F726E6974652C2073616C7574652C2076656C6F636974C3A0206469206D6F76696D656E746F20652076656C6F636974C3A020737520636176616C6361747572612061756D656E746174692064656C20247332252E0000, 40944),
(3776013982, 247088, 'itIT', 0x0043726F6D696520726976656C61206C65206361737365206469207465736F726920766963696E652E0D0A0D0A7C634646303046463030426F6E75733A7C722064616E6E6920696E666C697474692065206375726520666F726E6974652061756D656E746174692064656C20247332252E0043726F6D696520726976656C61206C65206361737365206469207465736F726920766963696E652E0D0A0D0A7C634646303046463030426F6E75733A7C722064616E6E6920696E666C697474692065206375726520666F726E6974652061756D656E746174692064656C20247332252E00, 40944),
(3479059991, 9040, 'itIT', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'itIT', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'itIT', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'itIT', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'itIT', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'itIT', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'itIT', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'itIT', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'itIT', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'itIT', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'itIT', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'itIT', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'itIT', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'itIT', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'itIT', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'itIT', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'itIT', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'itIT', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'itIT', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'itIT', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'itIT', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'itIT', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'itIT', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'itIT', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'itIT', 0x0024407370656C6C64657363323238383239002473312064616E6E692064612066756F636F20696E666C69747469206F676E692024323238383239743120732E00, 40944),
(3776013982, 227799, 'itIT', 0x004F6E64617465206427616371756120736920736F6C6C6576616E6F2064616920626F7264692064656C6C61207374616E7A612C20696E666C696767656E646F202473312064616E6E692064612067656C6F20616920706572736F6E6167676920747261766F6C74692E0000, 40944),
(3776013982, 227780, 'itIT', 0x004D617263686961207475747469206920706572736F6E6167676920636F6E2024407370656C6C6E616D653232373738302E20416C207465726D696E652C20696E666C69676765202473312064616E6E69206461206E61747572612061207475747469206920706572736F6E6167676920656E74726F20244131206D2E00416C207465726D696E652C202473312064616E6E69206461206E617475726120696E666C697474692061207475747469206920706572736F6E6167676920656E74726F20244131206D2E00, 40944),
(3386291891, 116804, 'itIT', 0x4174746F7265206469207363656E6100000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'itIT', 0x417263696D61676F204B686164676172000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'itIT', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'itIT', 0x4E69656C6173204172616E0000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'itIT', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'itIT', 0x43757261746F7265000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'itIT', 0x0041707269206C6120706167696E61206465676C6920617676656E7475726965726920652073656C657A696F6E616E6520756E6F20612063756920616C7A61726520696C206C6976656C6C6F2061202473312E0000, 40944),
(261693969, 60399, 'itIT', 0xFFFFFFFFFFFFFFFF496E20616975746F20646920526576656E647265746800003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'itIT', 0xFFFFFFFFFFFFFFFF496E20616975746F206469204D616C6472617878757300003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'itIT', 0xFFFFFFFFFFFFFFFF496E20616975746F2064656C2042617374696F6E6500003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'itIT', 0xFFFFFFFFFFFFFFFF496E20616975746F2064692053656C76617264656E00003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'itIT', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'itIT', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'itIT', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'itIT', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'itIT', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'itIT', 0x00000000, 40944),
(3865974254, 176921, 'itIT', 0x00000000, 40944),
(3865974254, 176832, 'itIT', 0x00000000, 40944),
(3776013982, 243328, 'itIT', 0x00005175616E746974C3A0206469206D696E6163636961207269646F7474612E00, 40944),
(3865974254, 187935, 'itIT', 0x00000000, 40944),
(3205218938, 44300, 'itIT', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F5800436F6C6C65676120756E2041757468656E74696361746F7220616C2074756F206163636F756E7420652061747469766120676C69206176766973692073756C2063656C6C756C617265207065722073626C6F63636172652071756573746F2063616D706F0001, 40944),
(3205218938, 44299, 'itIT', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C6366666666303030304E6F6E20706F7472616920707562626C696361726520756E2067727570706F204D69746963612B2073656E7A6120756E61204368696176652064656C20506F746572652066696E6368C3A9206E6F6E206176726169206D6573736F20616C2073696375726F20696C2074756F206163636F756E7420636F6E20696C20426174746C652E6E65742041757468656E74696361746F72206520617474697661746F20676C69206176766973692073756C2063656C6C756C6172657C727C6E7C6366663165666630303C436C696363612070657220756C746572696F726920696E666F726D617A696F6E693E7C720001, 40944),
(3205218938, 44284, 'itIT', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C6366666666303030304E6F6E20706F74726169206D6F64696669636172652071756573746F2063616D706F2066696E6368C3A9206E6F6E206176726169206D6573736F20616C2073696375726F20696C2074756F206163636F756E7420636F6E20696C20426174746C652E6E65742041757468656E74696361746F72206520617474697661746F20676C69206176766973692073756C2063656C6C756C6172657C727C6E7C6366663165666630303C436C696363612070657220756C746572696F726920696E666F726D617A696F6E693E7C720001, 40944),
(3205218938, 44283, 'itIT', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F444553430053626C6F636361206C276163636573736F20636F6D706C65746F20616C6C6120526963657263612067727570706920636F6C6C6567616E646F20756E2041757468656E74696361746F7220616C2074756F206163636F756E742065206174746976616E646F20676C69206176766973692073756C2063656C6C756C6172652E7C6E7C6E496C20426174746C652E6E65742041757468656E74696361746F7220C3A820756E2073657276697A696F20677261747569746F206520666163696C65206461207574696C697A7A617265206368652070726F746567676520696C2074756F206163636F756E74206461206163636573736920696E646573696465726174692C206D656E74726520676C69206176766973692073756C2063656C6C756C61726520696E7669616E6F20756E61206E6F746966696361207175616E646F2076656E676F6E6F2066617474692063616D6269616D656E746920696D706F7274616E746920616C2074756F206163636F756E747C6E7C6E436C69636361207375202241747469766122207065722061707269726520696C207369746F207765622064656C6C6520696D706F7374617A696F6E692064656C6C2741757468656E74696361746F722E0001, 40944),
(3776013982, 358927, 'itIT', 0x0052656E646520646966666964656E746920766572736F206C27616D6269656E746520636972636F7374616E74652E2054656D706F20646920726563757065726F207269646F74746F207065722069204E6F62696C69204F73637572692E00446966666964656E746520766572736F20636F6C6F726F2063686520746920636972636F6E64616E6F2E00, 40944),
(3865974254, 188152, 'itIT', 0x00000000, 40944),
(3776013982, 53385, 'itIT', 0x0053636174656E6120756E2074757262696E696F20646920656E657267696120646976696E612C20696E666C696767656E646F202473312064616E6E6920646120736163726F20612074757474692069206E656D69636920766963696E692E20496E666C696767652064616E6E69207269646F747469206F6C747265206920247332206265727361676C692E0000, 40944),
(261693969, 62694, 'itIT', 0xFFFFFFFFFFFFFFFF436F6E766F63617A696F6E652061204D616C64726178787573000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'itIT', 0xFFFFFFFFFFFFFFFF436F6E766F63617A696F6E6520612053656C76617264656E000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'itIT', 0xFFFFFFFFFFFFFFFF436F6E766F63617A696F6E6520616C2042617374696F6E65000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'itIT', 0xFFFFFFFFFFFFFFFF436F6E766F63617A696F6E65206120526576656E6472657468000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'itIT', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'itIT', 0x000000, 40944),
(3776013982, 307934, 'itIT', 0x000000, 40944),
(3776013982, 307480, 'itIT', 0x004C616E63696120696C2074756F204472616761746F7265204D617475726F2E0000, 40944),
(2948698321, 354, 'itIT', 0x64DF8D9146629CB2, 40944),
(261693969, 60111, 'itIT', 0xFFFFFFFFFFFFFFFF466F72676961726520756E27616D6963697A696100005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'itIT', 0xFFFFFFFFFFFFFFFF4D616920617675746120756E27616D69636120636F73C3AC00005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'itIT', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'itIT', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'itIT', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'itIT', 0x00000000, 40944),
(3865974254, 151804, 'itIT', 0x00000000, 40944),
(3865974254, 151792, 'itIT', 0x00000000, 40944),
(3037505077, 151792, 'itIT', 0x0100, 40944),
(3865974254, 151790, 'itIT', 0x00000000, 40944),
(3037505077, 151790, 'itIT', 0x0100, 40944),
(3865974254, 146306, 'itIT', 0x00000000, 40944),
(3865974254, 34685, 'itIT', 0x00000000, 40944),
(3865974254, 34683, 'itIT', 0x00000000, 40944),
(3865974254, 34087, 'itIT', 0x00000000, 40944),
(3865974254, 34085, 'itIT', 0x00000000, 40944),
(3865974254, 33969, 'itIT', 0x00000000, 40944),
(3865974254, 33968, 'itIT', 0x00000000, 40944),
(3865974254, 33967, 'itIT', 0x00000000, 40944),
(3865974254, 33966, 'itIT', 0x00000000, 40944),
(3865974254, 33868, 'itIT', 0x00000000, 40944),
(3865974254, 33864, 'itIT', 0x00000000, 40944),
(3865974254, 33863, 'itIT', 0x00000000, 40944),
(3865974254, 33862, 'itIT', 0x00000000, 40944),
(3865974254, 23324, 'itIT', 0x00000000, 40944),
(3865974254, 21525, 'itIT', 0x00000000, 40944),
(3865974254, 21524, 'itIT', 0x00000000, 40944),
(3865974254, 19028, 'itIT', 0x00000000, 40944),
(3865974254, 6835, 'itIT', 0x00000000, 40944),
(3865974254, 6833, 'itIT', 0x00000000, 40944),
(3865974254, 181321, 'itIT', 0x00000000, 40944),
(1548466975, 27672, 'itIT', 0x10040000, 40944),
(3776013982, 365080, 'itIT', 0x000056656C6F636974C3A0206469206D6F76696D656E746F2061756D656E746174612064656C20247331252E00, 40944),
(3776013982, 317920, 'itIT', 0x00526964756365206C6120647572617461206465676C69206566666574746920646920696E74657272757A696F6E6520652073696C656E7A69616D656E746F20737569206D656D6272692064656C2067727570706F206F2064656C6C27696E63757273696F6E6520656E74726F20246131206D2064656C20247331252E20243F733333393132345B52696475636520616E63686520676C6920656666657474692064692070617572612E5D5B5D0045666665747469206427696E74657272757A696F6E6520652073696C656E7A69616D656E746F207269646F7474692064656C20247731252E20243F733333393132345B45666665747469206469207061757261207269646F7474692064656C20247734252E5D5B5D00, 40944),
(3776013982, 465, 'itIT', 0x004C61206465766F7A696F6E6520696E636F7261676769612069206D656D6272692064656C2067727570706F206F2064656C6C27696E63757273696F6E6520656E74726F20246131206D2C207269647563656E646F6E6520692064616E6E69207375626974692064656C20247331252E0044616E6E6920737562697469207269646F7474692064656C20247731252E00, 40944),
(3205218938, 44172, 'itIT', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F44455343004F747469656E6920756E20696E6469636520646920312E393530206F207375706572696F726520706572206F7474656E6572653A7C6E2D2041756D656E746F20677261646F206F67676574746F205076500001, 40944),
(3205218938, 40887, 'itIT', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F44455343004F747469656E6920756E20696E6469636520646920312E383030206F207375706572696F726520706572206F7474656E6572653A7C6E2D205469746F6C6F20526976616C657C6E2D204173706574746F205365742050765020C3896C6974653A2054657374617C6E2D204173706574746F205365742050765020C3896C6974653A205370616C6C650001, 40944),
(3205218938, 40885, 'itIT', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F44455343004F747469656E6920756E20696E6469636520646920312E343030206F207375706572696F726520706572206F7474656E6572653A7C6E2D205469746F6C6F2053666964616E74657C6E2D204173706574746F205365742050765020C3896C6974653A204D616E697C6E2D204173706574746F205365742050765020C3896C6974653A2050696564690001, 40944),
(3776013982, 357407, 'itIT', 0x005065726D657474652064692065766F63617265206520636F6E74726F6C6C61726520696C2050696C6F746120646920526F636B204E20526F6C6C20526163696E673A204D617261756465722E00436F6E206C612062617272612064656C6C6520617A696F6E6920C3A820706F73736962696C652061747461636361726520676C6920616C7472692067696F636174746F6C6920726164696F636F6D616E646174692E00, 40944),
(3776013982, 357406, 'itIT', 0x005065726D657474652064692065766F63617265206520636F6E74726F6C6C61726520696C2050696C6F746120646920526F636B204E20526F6C6C20526163696E673A204D617261756465722E00436F6E206C612062617272612064656C6C6520617A696F6E6920C3A820706F73736962696C652061747461636361726520676C6920616C7472692067696F636174746F6C6920726164696F636F6D616E646174692E00, 40944),
(3776013982, 357405, 'itIT', 0x005065726D657474652064692065766F63617265206520636F6E74726F6C6C61726520696C2050696C6F746120646920526F636B204E20526F6C6C20526163696E673A204D617261756465722E00436F6E206C612062617272612064656C6C6520617A696F6E6920C3A820706F73736962696C652061747461636361726520676C6920616C7472692067696F636174746F6C6920726164696F636F6D616E646174692E00, 40944),
(3776013982, 356631, 'itIT', 0x005065726D657474652064692065766F63617265206520636F6E74726F6C6C61726520696C2050696C6F746120646920526F636B204E20526F6C6C20526163696E673A2041697220426C6164652E00436F6E206C612062617272612064656C6C6520617A696F6E6920C3A820706F73736962696C652061747461636361726520676C6920616C7472692067696F636174746F6C6920726164696F636F6D616E646174692E00, 40944),
(3776013982, 328923, 'itIT', 0x53696C66692064656C6C61204E6F747465005472617366657269736365206C6120666F727A6120766974616C65206469206D617373696D6F202433323839323849206E656D696369206E656C6C2761726561206265727361676C696F2C20696E666C696767656E646F20247B282433323839323873312A24642F24743229202B202433323839323873317D2064616E6E69206461206E61747572612073756464697669736920657175616D656E7465207472612074757474692069206265727361676C69206E656D69636920696E2024642E243F613133373034315B0D0A0D0A556E612063616E616C697A7A617A696F6E6520636F6D706C6574612064692054726173667573696F6E65206465692053696C666920666F726E697363652024733420244C616363756D756C6F3A616363756D756C693B2064692041726D612064656C204D61656C7374726F6D2E5D5B5D0D0A0D0A4C616E6369617265206E756F76616D656E74652054726173667573696F6E65206465692053696C666920656E74726F2024333238393333642073636174656E6120696C202473312520646920747574746920692064616E6E6920696E666C697474692064612054726173667573696F6E65206465692053696C66692C20637572616E646F2066696E6F20612024333238393330733220616C6C6561746920656E74726F20243332383933304131206D2E0000, 40944),
(3776013982, 101546, 'itIT', 0x00556E2063616C63696F20726F74616E74652063686520696E666C6967676520243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5D2064616E6E692066697369636920696E20246420612074757474692069206E656D69636920656E74726F20243130373237304131206D2E20496E666C696767652064616E6E69207269646F747469206F6C747265206920247331206265727361676C692E243F63335B0D0A0D0A492064616E6E6920696E666C697474692064612043616C63696F20526F74616E74652064656C6C61204772752061756D656E74616E6F2064656C202432323033353873312520706572206F676E69206265727361676C696F2064697374696E746F20636F6C7069746F206E65676C6920756C74696D6920243232303335386420636F6E2050616C6D6F2064656C6C612054696772652C2043616C63696F2064656C6C274F73637572616D656E746F206F2043616C63696F2064656C20536F6C65204E617363656E74652E20536920616363756D756C612066696E6F206120243232383238376920766F6C74652E5D5B5D0044616E6E692066697369636920696E666C69747469206169206E656D69636920766963696E69206F676E692024313031353436743120732E00, 40944),
(3865974254, 188220, 'itIT', 0x00000000, 40944),
(3865974254, 187900, 'itIT', 0x00000000, 40944),
(3865974254, 187899, 'itIT', 0x00000000, 40944),
(3865974254, 187898, 'itIT', 0x00000000, 40944),
(3865974254, 187897, 'itIT', 0x00000000, 40944),
(3865974254, 187896, 'itIT', 0x00000000, 40944),
(3865974254, 187895, 'itIT', 0x00000000, 40944),
(3865974254, 187875, 'itIT', 0x00000000, 40944),
(3865974254, 187869, 'itIT', 0x00000000, 40944),
(3865974254, 150746, 'itIT', 0x00000000, 40944),
(3865974254, 150745, 'itIT', 0x00000000, 40944),
(3865974254, 150744, 'itIT', 0x00000000, 40944),
(3865974254, 150743, 'itIT', 0x00000000, 40944),
(3776013982, 364944, 'itIT', 0x000056656C6F636974C3A0206469206D6F76696D656E746F2061756D656E746174612064656C20247331252E00, 40944),
(3776013982, 228462, 'itIT', 0x0041756D656E746120692064616E6E6920696E666C69747469206461676C69206174746163636869206175746F6D6174696369206469202473312E0000, 40944),
(3776013982, 119611, 'itIT', 0x0024407370656C6C64657363313135313531002477312073616C75746520726967656E6572617461206F676E692024743120732E00, 40944),
(3776013982, 119607, 'itIT', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'itIT', 0x00000000, 40944),
(1181150530, 403396, 'itIT', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'itIT', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'itIT', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'itIT', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'itIT', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'itIT', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'itIT', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'itIT', 0xA4530000, 40944),
(3359787322, 21411, 'itIT', 0xA3530000, 40944),
(3359787322, 21410, 'itIT', 0xA2530000, 40944),
(3359787322, 21409, 'itIT', 0xA1530000, 40944),
(3359787322, 21408, 'itIT', 0xA0530000, 40944),
(3359787322, 21407, 'itIT', 0x9F530000, 40944),
(3359787322, 21406, 'itIT', 0x9E530000, 40944),
(2557447376, 655518, 'itIT', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'itIT', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'itIT', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'itIT', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'itIT', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'itIT', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F454646454354005265676F6C652064656C20626F7474696E6F20636C61737369636865206E6F6E207069C3B9206162696C69746174652E0001, 40944),
(3776013982, 347944, 'itIT', 0x0041756D656E7461206C612070726F626162696C6974C3A0206469206372697469636F2064656C20247331252E0D0A0050726F626162696C6974C3A0206469206372697469636F2061756D656E746174612064656C20247331252E00, 40944),
(3776013982, 347943, 'itIT', 0x0041756D656E7461206C612073616C757465206D617373696D612064656C20247331252E0D0A0053616C757465206D617373696D612061756D656E746174612064656C20247331252E00, 40944),
(3776013982, 1714, 'itIT', 0x00436F737472696E676520696C206265727361676C696F2061207061726C61726520696E2064656D6F6E6961636F2C2061756D656E74616E646F206C612076656C6F636974C3A0206469206C616E63696F20646920747574746920676C6920696E63616E746573696D692064656C2024733125207065722024642E243F733130333131325B0D0A0D0A7C434646453535424230436F6E73756D6F206427416E696D613A204D616C6564697A696F6E652064656C6C65204C696E677565206166666C696767652074757474692069206E656D69636920696E20756E2072616767696F206469202431303432323441206D20696E746F726E6F20616C206265727361676C696F2E7C525D5B5D0D0A0D0A7C6346463832383246464D616C6564697A696F6E693A20756E6F2053747265676F6E65207075C3B220617665726520736F6C6F20756E61206D616C6564697A696F6E6520617474697661207375206F676E69206265727361676C696F2E7C72005061726C61726520696E2064656D6F6E6961636F2061756D656E746120696C2074656D706F206469206C616E63696F2064656C20247731252E00, 40944),
(3205218938, 41865, 'itIT', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E53004E6F6E2068616920696C207065726D6573736F206469206D6F6469666963617265206C6520696E666F726D617A696F6E69206469207265636C7574616D656E746F2E0001, 40944),
(261693969, 64850, 'itIT', 0xFFFFFFFFFFFFFFFF5669616767696F2064692070696163657265206120546F7267617374000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'itIT', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='itIT') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='itIT');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'itIT' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `achievement_locale` WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (14775,14752,14682,14351));
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14775, 'koKR', '마라스미우스 확고한 동맹', '버섯 공경', '칭호: 버섯 애호가', 40944),
(14752, 'koKR', '아래 나열된 누더기 봉합술 업적 완료', '죽어서 해야 하는 일', '칭호: 첨탑배회자 및 보상: 무장한 선택받은 타우랄러스 탈것', 40944),
(14682, 'koKR', '아래 나열된 잿불 궁정 업적 완료', '연회의 전령', '칭호: 연회의 전령', 40944),
(14351, 'koKR', '승천의 길에서 우두머리 39명 처치', '승천을 향한 길 39', '승천의 길에서 더 많은 도전 잠금 해제', 40944);


DELETE FROM `area_table_locale` WHERE (`VerifiedBuild`>0 AND `ID`=13316 AND `locale`='koKR');
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(13316, 'koKR', '의식의 의회', 40944);


DELETE FROM `battle_pet_species_locale` WHERE (`VerifiedBuild`>0 AND `ID`=3188 AND `locale`='koKR');
INSERT INTO `battle_pet_species_locale` (`ID`, `locale`, `Description_lang`, `SourceText_lang`, `VerifiedBuild`) VALUES
(3188, 'koKR', '', '', 40944);


DELETE FROM `broadcast_text_locale` WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (215513,215512,215511));
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(215513, 'koKR', '', '준비도 없이 나락으로 뛰어드는 건 현명하지 못한 일입니다. 준비가 되면 다시 절 찾아오십시오.', 40944),
(215512, 'koKR', '준비도 없이 나락으로 뛰어드는 건 현명치 못한 일일세. 준비가 되면 다시 날 찾아오게나.', '', 40944),
(215511, 'koKR', '', '끝이 보입니다. 제 옆에서 함께 싸우시죠. 그럼 여길 빠져나갈 수 있을 겁니다.', 40944);


DELETE FROM `char_titles_locale` WHERE (`VerifiedBuild`>0 AND `ID`=693 AND `locale`='koKR');
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(693, 'koKR', '승천자 %s', '승천자 %s', 40944);


UPDATE `char_titles_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=683 AND `locale`='koKR');
DELETE FROM `chr_customization_option_locale` WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (1523,689));
INSERT INTO `chr_customization_option_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1523, 'koKR', '꼬리', 40944),
(689, 'koKR', '꼬리', 40944);


DELETE FROM `criteria_tree_locale` WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (91730,94390,94389,94388,93811,93810,94331,94330));
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91730, 'koKR', '9.1 메타 업적', 40944),
(94390, 'koKR', '', 40944),
(94389, 'koKR', '', 40944),
(94388, 'koKR', '', 40944),
(93811, 'koKR', '', 40944),
(93810, 'koKR', '영예 80 레벨', 40944),
(94331, 'koKR', '', 40944),
(94330, 'koKR', 'Renown Level 80 - Kyrian', 40944);


DELETE FROM `item_search_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,116401));
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(151806, 'koKR', '우아한 드레스', 40944),
(151804, 'koKR', '검은색 턱시도 바지', 40944),
(151792, 'koKR', '초록색 겨울 의복', 40944),
(151790, 'koKR', '붉은색 겨울 의복', 40944),
(34685, 'koKR', '여름 예복', 40944),
(34683, 'koKR', '여름 덧신', 40944),
(34087, 'koKR', '초록색 겨울 의복', 40944),
(34085, 'koKR', '붉은색 겨울 의복', 40944),
(33969, 'koKR', '보라색 가을 축제 모자', 40944),
(33968, 'koKR', '파란색 가을 축제 모자', 40944),
(33967, 'koKR', '초록색 가을 축제 모자', 40944),
(33966, 'koKR', '가을 축제 끌신', 40944),
(33868, 'koKR', '가을 축제 장화', 40944),
(33864, 'koKR', '갈색 가을 축제 모자', 40944),
(33863, 'koKR', '가을 축제 드레스', 40944),
(33862, 'koKR', '가을 축제 의복', 40944),
(23324, 'koKR', '불꽃축제 어깨덧옷', 40944),
(21525, 'koKR', '초록색 겨울 모자', 40944),
(21524, 'koKR', '붉은색 겨울 모자', 40944),
(19028, 'koKR', '우아한 드레스', 40944),
(6835, 'koKR', '검은색 턱시도 바지', 40944),
(6833, 'koKR', '흰색 턱시도 셔츠', 40944),
(181321, 'koKR', '왕관보석 마법봉', 40944),
(116401, 'koKR', '고급 순례자 모자', 40944);


DELETE FROM `item_sparse_locale` WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (176922,176921,176832,187935,188152,151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,188220,187900,187899,187898,187897,187896,187895,187875,187869,150746,150745,150744,150743,116401));
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(176922, 'koKR', '이 마법 꽃은 환생한 영혼이 제공하는 제작 재료의 양과 촉매 씨앗에서 자라나는 촉매의 수를 100%만큼 증가시킵니다.', '', '', '', '야생 밤만개꽃', 40944),
(176921, 'koKR', '이 마력 깃든 잎사귀는 재생의 야생씨앗의 성장 과정을 하루만큼 촉진합니다.', '', '', '', '시간의 잎사귀', 40944),
(176832, 'koKR', '이 특별한 뿌리는 영혼이 환생할 때 제공하는 보상의 품질을 증가시킵니다.', '', '', '', '야생씨앗 뿌리 곡식', 40944),
(187935, 'koKR', '한밤 룬수사슴의 징표 만드는 법을 배웁니다.', '', '', '', '각인 기법: 한밤 룬수사슴의 징표', 40944),
(188152, 'koKR', '파편에서 타는 듯한 마력이 느껴집니다.', '', '', '', '관문 제어 파편', 40944),
(151806, 'koKR', '', '', '', '', '우아한 드레스', 40944),
(151804, 'koKR', '', '', '', '', '검은색 턱시도 바지', 40944),
(151792, 'koKR', '', '', '', '', '초록색 겨울 의복', 40944),
(151790, 'koKR', '', '', '', '', '붉은색 겨울 의복', 40944),
(34685, 'koKR', '', '', '', '', '여름 예복', 40944),
(34683, 'koKR', '', '', '', '', '여름 덧신', 40944),
(34087, 'koKR', '', '', '', '', '초록색 겨울 의복', 40944),
(34085, 'koKR', '', '', '', '', '붉은색 겨울 의복', 40944),
(33969, 'koKR', '', '', '', '', '보라색 가을 축제 모자', 40944),
(33968, 'koKR', '', '', '', '', '파란색 가을 축제 모자', 40944),
(33967, 'koKR', '', '', '', '', '초록색 가을 축제 모자', 40944),
(33966, 'koKR', '', '', '', '', '가을 축제 끌신', 40944),
(33868, 'koKR', '', '', '', '', '가을 축제 장화', 40944),
(33864, 'koKR', '', '', '', '', '갈색 가을 축제 모자', 40944),
(33863, 'koKR', '', '', '', '', '가을 축제 드레스', 40944),
(33862, 'koKR', '', '', '', '', '가을 축제 의복', 40944),
(23324, 'koKR', '', '', '', '', '불꽃축제 어깨덧옷', 40944),
(21525, 'koKR', '', '', '', '', '초록색 겨울 모자', 40944),
(21524, 'koKR', '', '', '', '', '붉은색 겨울 모자', 40944),
(19028, 'koKR', '', '', '', '', '우아한 드레스', 40944),
(6835, 'koKR', '', '', '', '', '검은색 턱시도 바지', 40944),
(6833, 'koKR', '', '', '', '', '흰색 턱시도 셔츠', 40944),
(181321, 'koKR', '', '', '', '', '왕관보석 마법봉', 40944),
(188220, 'koKR', '바닥에 \"나는 토르가스트에서 살아남았노라\" 라고 적혀 있습니다.', '', '', '', '토르가스트 재 보주', 40944),
(187900, 'koKR', '고블린과 노움 2인조가 두 섬에서 발견한 많은 것을 기록해 두었습니다.', '', '', '', '정찰 지도: 쿨 티라스와 잔달라 지역의 경이로움', 40944),
(187899, 'koKR', '한 모험심 넘치는 연금술사가 아웃랜드의 이질적인 생물과 놀라운 식물들에 대해 기록해 두었습니다.', '', '', '', '정찰 지도: 아웃랜드의 다양한 신비', 40944),
(187898, 'koKR', '은빛십자군이 리치 왕 추격 시 수행한 모든 군사 작전에 대한 상세한 보고서입니다.', '', '', '', '정찰 지도: 동부 왕국 대장정의 대가', 40944),
(187897, 'koKR', '데스윙이 아제로스를 산산조각 냄으로써 발생한 수많은 결과가 집계된 희귀한 진영 공동 보고서입니다.', '', '', '', '정찰 지도: 대격변의 영향', 40944),
(187896, 'koKR', '리 리의 판다리아 모험 이야기와 첸 삼촌의 추천 음식이 함께 적혀 있습니다.', '', '', '', '정찰 지도: 스톰스타우트의 판다리아 안내서', 40944),
(187895, 'koKR', '드레노어 전역에서 몇 안 되는 안식처의 간결한 목록과, 각 지역에서 지키면 좋을 듯한 현지 관습이 적혀 있습니다.', '', '', '', '정찰 지도: 드레노어에 도사리는 위험', 40944),
(187875, 'koKR', '군단에 맞서 전투 중인 서로 다른 군부대간에 주고받은 수많은 보고서와 서신 묶음입니다.', '', '', '', '정찰 지도: 부서진 섬의 연합 전선', 40944),
(187869, 'koKR', '어둠땅의 네 영역을 넘나드는 한 나락 방랑자의 여정에 대한 자세한 이야기가 담겨 있습니다.', '', '', '', '정찰 지도: 어둠땅으로', 40944),
(150746, 'koKR', '동부 왕국 전초기지에 때맞춰 보급품을 제공하는 방법을 적은 겸손한 제안서입니다.', '', '', '', '정찰 지도: 동부 왕국의 현대적인 보급품 공급법', 40944),
(150745, 'koKR', '4차 대전쟁이 일어날 시 동부왕국의 얼라이언스 세력을 신속하게 무너뜨릴 수 있는 자세한 전략을 담았습니다.', '', '', '', '정찰 지도: 동부 왕국 대장정', 40944),
(150744, 'koKR', '사악하고, 타락하고, 기이한 존재들이 남긴 상처를 치유합니다.', '', '', '', '정찰 지도: 대지모신과 함께 걷는 칼림도어', 40944),
(150743, 'koKR', '칼림도어에 사는 송곳니가 있거나, 발톱이 있거나, 독이 있거나, 호드 진영인 야수를 모조리 담았습니다.', '', '', '', '정찰 지도: 칼림도어에서 살아남기', 40944),
(116401, 'koKR', '', '', '', '', '고급 순례자 모자', 40944);


UPDATE `item_sparse_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (185950,185947,185946));
DELETE FROM `lfg_dungeons_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1445 AND `locale`='koKR');
INSERT INTO `lfg_dungeons_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1445, 'koKR', '지옥토템의 몰락', '투가르 블러드토템과 지옥 벌레들이 산을 무너뜨리지 못하도록 막아야 합니다.', 40944);


DELETE FROM `map_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1756 AND `locale`='koKR');
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(1756, 'koKR', '크로미의 죽음', '', '', '', '', 40944);


DELETE FROM `player_condition_locale` WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (95078,95077,95076,85644,73006,73005,87365,85912,85910,85909,85692,94517,94516,94515,94514,94513,94512,94511));
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(95078, 'koKR', '', 40944),
(95077, 'koKR', '', 40944),
(95076, 'koKR', '', 40944),
(85644, 'koKR', '계속하려면 $pcMinLevel 레벨이 되어야 합니다.', 40944),
(73006, 'koKR', '', 40944),
(73005, 'koKR', '', 40944),
(87365, 'koKR', '', 40944),
(85912, 'koKR', '', 40944),
(85910, 'koKR', '', 40944),
(85909, 'koKR', '', 40944),
(85692, 'koKR', '', 40944),
(94517, 'koKR', '', 40944),
(94516, 'koKR', '', 40944),
(94515, 'koKR', '', 40944),
(94514, 'koKR', '', 40944),
(94513, 'koKR', '', 40944),
(94512, 'koKR', '', 40944),
(94511, 'koKR', '', 40944);


DELETE FROM `spell_category_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1186 AND `locale`='koKR');
INSERT INTO `spell_category_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1186, 'koKR', 'Class - Paladin - Hand of Sacrifice', 40944);


DELETE FROM `spell_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (361952,256817,247692,247111,247110,247104,247103,247099,247096,247094,247093,247092,247089,247088,228844,227799,227780,362986,243328,358927,53385,329902,307934,307480,365080,317920,465,357407,357406,357405,356631,328923,101546,364944,228462,119611,119607,347944,347943,1714));
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(361952, 'koKR', '1000 령', 40944),
(256817, 'koKR', '아만툴의 징표', 40944),
(247692, 'koKR', '유물 영속성', 40944),
(247111, 'koKR', 'Blessing of the Bronze Dragonflight Passive', 40944),
(247110, 'koKR', '무한한 속력', 40944),
(247104, 'koKR', 'Acceleration Passive', 40944),
(247103, 'koKR', 'Time Stop Passive', 40944),
(247099, 'koKR', 'Chrono Charisma Passive', 40944),
(247096, 'koKR', 'Rapid Recovery Passive', 40944),
(247094, 'koKR', '횡재', 40944),
(247093, 'koKR', 'Dragon\'s Determination Passive', 40944),
(247092, 'koKR', 'Accelerated Aggression Passive', 40944),
(247089, 'koKR', 'Dragon Crash Passive', 40944),
(247088, 'koKR', '통찰', 40944),
(228844, 'koKR', '불타는 뼈', 40944),
(227799, 'koKR', '휩쓸기', 40944),
(227780, 'koKR', '천둥 의식', 40944),
(362986, 'koKR', '경험치', 40944),
(243328, 'koKR', '소실', 40944),
(358927, 'koKR', '나이트본 경비병의 경계', 40944),
(53385, 'koKR', '천상의 폭풍', 40944),
(329902, 'koKR', '허드렛일', 40944),
(307934, 'koKR', '허드렛일', 40944),
(307480, 'koKR', '허드레꾼 던지기', 40944),
(365080, 'koKR', '바람걸음', 40944),
(317920, 'koKR', '집중의 오라', 40944),
(465, 'koKR', '헌신의 오라', 40944),
(357407, 'koKR', '파괴왕 소환', 40944),
(357406, 'koKR', '전투바퀴 소환', 40944),
(357405, 'koKR', '진흙악마 소환', 40944),
(356631, 'koKR', '공중 칼날 소환', 40944),
(328923, 'koKR', '페이 수혈', 40944),
(101546, 'koKR', '회전 학다리차기', 40944),
(364944, 'koKR', '바람걸음', 40944),
(228462, 'koKR', '멜란드루스의 인장', 40944),
(119611, 'koKR', '소생의 안개', 40944),
(119607, 'koKR', '소생의 안개', 40944),
(347944, 'koKR', '오블레론 가시', 40944),
(347943, 'koKR', '오블레론 인내', 40944),
(1714, 'koKR', '언어의 저주', 40944);


DELETE FROM `transmog_set_locale` WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (2289,2287,2283,2281,2277,2275,2271,2269,2178));
INSERT INTO `transmog_set_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(2289, 'koKR', '속박을 벗어던진 검투사의 판금 방어구', 40944),
(2287, 'koKR', '속박을 벗어던진 검투사의 판금 방어구', 40944),
(2283, 'koKR', '속박을 벗어던진 검투사의 사슬 방어구', 40944),
(2281, 'koKR', '속박을 벗어던진 검투사의 사슬 방어구', 40944),
(2277, 'koKR', '속박을 벗어던진 검투사의 가죽 방어구', 40944),
(2275, 'koKR', '속박을 벗어던진 검투사의 가죽 방어구', 40944),
(2271, 'koKR', '속박을 벗어던진 검투사의 예복', 40944),
(2269, 'koKR', '속박을 벗어던진 검투사의 예복', 40944),
(2178, 'koKR', '바느질 대가의 무기', 40944);


UPDATE `transmog_set_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='koKR' AND `ID` IN (2221,2220,2219,2218,2217,2216,2215,2214,2213,2212,2211,2210,2209,2208,2207,2206,2205,2204,2203,2202));
DELETE FROM `achievement_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table_locale` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_blob` WHERE (`TableHash`=2948698321 AND `RecordId`=340 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='koKR') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='koKR') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='koKR') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='koKR') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='koKR') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='koKR') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='koKR') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='koKR') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='koKR') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='koKR') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='koKR') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='koKR') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='koKR') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='koKR') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='koKR') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='koKR') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=358927 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='koKR') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='koKR') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='koKR') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='koKR') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='koKR') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='koKR') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='koKR') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='koKR') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='koKR') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='koKR') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='koKR') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='koKR') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='koKR') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='koKR') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='koKR') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='koKR') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='koKR') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='koKR') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='koKR') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='koKR') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='koKR') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='koKR') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='koKR') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='koKR') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='koKR') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='koKR') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='koKR') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='koKR') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='koKR') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='koKR') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='koKR') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='koKR') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='koKR') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='koKR') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='koKR') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='koKR');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(2948698321, 340, 'koKR', 0xA53E23C86B3D8F59, 40944),
(261693969, 65165, 'koKR', 0xFFFFFFFFFFFFFFFFEC9881ED98BCEC9D9820ECA780ECA780000044AC546F010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000000000000, 40944),
(3776013982, 361952, 'koKR', 0x00ED9884EC9EAC20EC84B1EC95BDEC9D9820EB8BA820ECA080EC9EA5EC868CEC979020247331EC9D9820EBA0B9EC9D8420EB8D94ED95A9EB8B88EB8BA42E0000, 40944),
(3776013982, 256817, 'koKR', 0x00ECA3BCEBACB820EBB08F20EB8AA5EBA0A520EC82ACEC9AA920EC8B9C20EC9DBCECA09520ED9995EBA5A0EBA19C20243235363831386420EB8F99EC958820EC868DEB8F842C20EAB491EC97ADED9A8CED94BC2C20EC839DEAB8B0ED9DA1EC8898EAB08020243235363831387331EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0D0A0D0A7C634646464646464646EC9584EBA78CED88B4EC9D9820EC9C84EC97847C720D0AED8C90ED858CEC98A8EC9D9820ED9E98EC9CBCEBA19C20EAB095ED9994EB9098EBA9B420243235363833326420EB8F99EC958820243F28613133373030357C613133373034377C613133373032387C61313337303237295BED9E985D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295BEBAFBCECB2A9EC84B15D5BECA780EB8AA55DEC9DB420243235363833327331EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0000, 40944),
(3776013982, 247692, 'koKR', 0x00EC8B9CEAB084EC9D9820EBAAA8EB9E98EC9790EC849C20EC9CA0EBACBC20EC8381EC9E90EBA5BC20ED9A8DEB939DED95A020EAB080EB8AA5EC84B1EC9DB420ECA69DEAB080ED95A9EB8B88EB8BA42E20EC9CA0EBACBC20EC8381EC9E9020EC9588EC9790EB8A9420EC8B9CEAB084EC9DB4EB8F9920ECB0A8EC9B90EBACB8EC9D8420ED86B5ED9598EC97AC20EC8898ED9689ED95B4EC95BC20ED9598EB8A9420EC9E84EBACB4EC9D9820EB829CEC9DB4EB8F84EBA5BC20ED81ACEAB28C20EAB090EC868CEC8B9CED82AC20EAB095EBA0A5ED959C20EC9584EC9DB4ED859CEC9DB420EB93A4EC96B420EC9E88EC8AB5EB8B88EB8BA42E0D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EC9DB4EB8F9920EC868DEB8F84EC998020ED8388EAB283EC9D9820EC9DB4EB8F9920EC868DEB8F84EAB0802024733225EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E00EC8B9CEAB084EC9D9820EBAAA8EB9E98EC9790EC849C20EC9CA0EBACBC20EC8381EC9E90EBA5BC20ED9A8DEB939DED95A020EAB080EB8AA5EC84B120ECA69DEAB0800D0AEC9CA0EBACBC20EC8381EC9E90EC9790EB8A9420EC8B9CEAB084EC9DB4EB8F9920ECB0A8EC9B90EBACB8EC9D8420ED86B5ED9598EC97AC20EC8898ED9689ED95B4EC95BC20ED9598EB8A9420EC9E84EBACB4EC9D9820EB829CEC9DB4EB8F84EBA5BC20ED81ACEAB28C20EAB090EC868CEC8B9CED82AC20EAB095EBA0A5ED959C20EC9584EC9DB4ED859CEC9DB420EB93A4EC96B420EC9E88EC9D8C0D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EC9DB4EB8F9920EC868DEB8F84EC998020ED8388EAB283EC9D9820EC9DB4EB8F9920EC868DEB8F842024733225EBA78CED81BC20ECA69DEAB08000, 40944),
(3776013982, 247111, 'koKR', 0x00EC8B9CEAB084EC9D9820EBAAA8EB9E98EC9790EC849C20ECB2ADEB8F9920EBB984EBA3A1EC9D8420ED9A8DEB939DED95A020ED9995EBA5A0EC9DB420ECA69DEAB080ED95A9EB8B88EB8BA42E20EC9DB420EBB984EBA3A1EC9D8020ECA689EC8B9C20EC9AA9ECA09CEB8BA8EC9D8420ECA095EBA6ACED95A9EB8B88EB8BA42E0D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EAB3B5EAB2A9EBA0A5EAB3BC20ECB998EC9CA0EB9F89EC9DB42024733225EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E00EC8B9CEAB084EC9D9820EBAAA8EB9E98EC9790EC849C20ECB2ADEB8F9920EBB984EBA3A1EC9D8420ED9A8DEB939DED95A020ED9995EBA5A020ECA69DEAB0800D0AEBB984EBA3A1EC9D8020ECA689EC8B9C20EC9AA9ECA09CEB8BA8EC9D8420ECA095EBA6AC0D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EAB3B5EAB2A9EBA0A5EAB3BC20ECB998EC9CA0EB9F892024733225EBA78CED81BC20ECA69DEAB08000, 40944),
(3776013982, 247110, 'koKR', 0x00EAB3A0EBA3A1EC89BCED84B020EC82ACEC9B90EC9790EC849C20EAB08120EC9AA9ECA09CEB8BA8EC9CBCEBA19C20ED86B5ED9598EB8A9420ECB0A8EC9B90EBACB8EC9D8420EC9EA0EAB88820ED95B4ECA09CED95A9EB8B88EB8BA42E0D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EC9DB4EB8F9920EC868DEB8F84EC998020ED8388EAB283EC9D9820EC9DB4EB8F9920EC868DEB8F84EAB0802024733225EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E00EAB3A0EBA3A1EC89BCED84B020EC82ACEC9B90EC9790EC849C20EAB08120EC9AA9ECA09CEB8BA8EC9CBCEBA19C20ED86B5ED9598EB8A9420ECB0A8EC9B90EBACB820EC9EA0EAB88820ED95B4ECA09C0D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EC9DB4EB8F9920EC868DEB8F84EC998020ED8388EAB283EC9D9820EC9DB4EB8F9920EC868DEB8F842024733225EBA78CED81BC20ECA69DEAB08000, 40944),
(3776013982, 247104, 'koKR', 0x00EC9DB4EB8F9920EC868DEB8F84EC998020ED8388EAB283EC9D9820EC9DB4EB8F9920EC868DEB8F84EAB0802024733125EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EAB3B5EAB2A9EBA0A5EAB3BC20ECB998EC9CA0EB9F89EC9DB42024733225EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E00EC9DB4EB8F9920EC868DEB8F84EC998020ED8388EAB283EC9D9820EC9DB4EB8F9920EC868DEB8F842024733125EBA78CED81BC20ECA69DEAB0800D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EAB3B5EAB2A9EBA0A5EAB3BC20ECB998EC9CA0EB9F892024733225EBA78CED81BC20ECA69DEAB08000, 40944),
(3776013982, 247103, 'koKR', 0x0024407370656C6C646573633234343935390D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EAB3B5EAB2A9EBA0A5EAB3BC20ECB998EC9CA0EB9F89EC9DB4203525EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0000, 40944),
(3776013982, 247099, 'koKR', 0x00ECA081EC9D8420ECB298ECB998ED9598EAB3A020ED9A8DEB939DED9598EB8A9420ED81ACEBA19CEBAFB8EC979020EB8C80ED959C20ED8F89ED8C90EC9DB420EBA788ECA780EBA78920243234373736396420EB8F99EC95882024323437373639733125EBA78CED81BC2C20EBA788ECA780EBA78920243234373737306420EB8F99EC95882024323437373730733125EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EC9DB4EB8F9920EC868DEB8F84EC998020ED8388EAB283EC9D9820EC9DB4EB8F9920EC868DEB8F84EAB0802024733225EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0000, 40944),
(3776013982, 247096, 'koKR', 0x000000, 40944),
(3776013982, 247094, 'koKR', 0x00EC8B9CEAB084EC9D9820EBAAA8EB9E98EBA5BC20ED9A8DEB939DED95A020ED9995EBA5A0EC9DB42024733125EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EC839DEBAA85EBA0A5EC9DB42024733225EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E00EC8B9CEAB084EC9D9820EBAAA8EB9E9820ED9A8DEB939D20ED9995EBA5A02024733125EBA78CED81BC20ECA69DEAB0800D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EC839DEBAA85EBA0A52024733225EBA78CED81BC20ECA69DEAB08000, 40944),
(3776013982, 247093, 'koKR', 0x000000, 40944),
(3776013982, 247092, 'koKR', 0x000000, 40944),
(3776013982, 247089, 'koKR', 0x0024407370656C6C646573633234353530330D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EAB3B5EAB2A9EBA0A52C20ECB998EC9CA0EB9F892C20EC839DEBAA85EBA0A52C20EC9DB4EB8F9920EC868DEB8F842C20ED8388EAB283EC9D9820EC9DB4EB8F9920EC868DEB8F84EAB0802024733225EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0000, 40944),
(3776013982, 247088, 'koKR', 0x00ED81ACEBA19CEBAFB8EAB08020ECA3BCEC9C84EC9D9820EBB3B4EBACBC20EC8381EC9E90EBA5BC20EB939CEB9FACEB8385EB8B88EB8BA42E0D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EAB3B5EAB2A9EBA0A5EAB3BC20ECB998EC9CA0EB9F89EC9DB42024733225EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E00ED81ACEBA19CEBAFB8EAB08020ECA3BCEC9C8420EBB3B4EBACBC20EC8381EC9E90EBA5BC20EB939CEB9FACEB83840D0A0D0A7C634646303046463030EBB3B4EB8488EC8AA43A7C7220EAB3B5EAB2A9EBA0A5EAB3BC20ECB998EC9CA0EB9F892024733225EBA78CED81BC20ECA69DEAB08000, 40944),
(3479059991, 9040, 'koKR', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'koKR', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'koKR', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'koKR', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'koKR', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'koKR', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'koKR', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'koKR', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'koKR', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'koKR', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'koKR', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'koKR', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'koKR', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'koKR', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'koKR', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'koKR', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'koKR', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'koKR', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'koKR', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'koKR', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'koKR', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'koKR', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'koKR', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'koKR', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'koKR', 0x0024407370656C6C6465736332323838323900243232383832397431ECB488EBA788EB8BA420247331EC9D9820ED9994EC97BC20ED94BCED95B400, 40944),
(3776013982, 227799, 'koKR', 0x00EBB0A9EC9D9820EAB080EC9EA5EC9E90EBA6ACEC9790EC849CEBB680ED84B020EBACBCEAB2B0EC9DB420EBB080EBA0A4EC99802C20ECB6A9EB8F8CED9598EB8A9420ED948CEBA088EC9DB4EC96B4EC9790EAB28C20247331EC9D9820EB8389EAB8B020ED94BCED95B4EBA5BC20EC9E85ED9E99EB8B88EB8BA42E0000, 40944),
(3776013982, 227780, 'koKR', 0x00EBAAA8EB93A020ED948CEBA088EC9DB4EC96B4EC9790EAB28C2024407370656C6C6E616D65323237373830EC9D9820ECA795ED919CEBA5BC20ECB08DEC96B42C20ED9AA8EAB3BCEAB08020EC82ACEB9DBCECA78820EB958C20244131EBAFB8ED84B020EB82B4EC9D9820EBAAA8EB93A020ED948CEBA088EC9DB4EC96B4EC9790EAB28C20247331EC9D9820EC9E90EC97B020ED94BCED95B4EBA5BC20EC9E85ED9E99EB8B88EB8BA42E00ED9AA8EAB3BCEAB08020EC82ACEB9DBCECA78820EB958C20244131EBAFB8ED84B020EB82B4EC9D9820EBAAA8EB93A020ED948CEBA088EC9DB4EC96B4EC9790EAB28C20247331EC9D9820EC9E90EC97B020ED94BCED95B400, 40944),
(3386291891, 116804, 'koKR', 0xEC9EA5EBA9B420ED9689EC9C84EC9E9000000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'koKR', 0xEB8C80EBA788EBB295EC82AC20ECB9B4EB939CEAB080000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'koKR', 0xEBA994EB9494EBB88C0000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'koKR', 0xEB8B88EC9798EB9DBCEC8AA420EC9584EB9E800000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'koKR', 0xEBA994EB9494EBB88C0000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'koKR', 0xECA084EC8B9C20EAB480EBA6ACEC9DB8000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'koKR', 0x00EB8F99EBA38C20ECB0BDEC9D8420EC97B4EAB3A020EB8F99EBA38CEBA5BC20EC84A0ED839DED95B420EBA088EBB2A8EC9D84202473317C31EC9CBCEBA19C3BEBA19C3B20EC98ACEBA6BDEB8B88EB8BA42E0000, 40944),
(261693969, 60399, 'koKR', 0xFFFFFFFFFFFFFFFFEBA088EBB2A4EB939CEBA088EC8AA420ECA780EC9B9000003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'koKR', 0xFFFFFFFFFFFFFFFFEBA790EB939CEB9DBDEC849CEC8AA420ECA780EC9B9000003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'koKR', 0xFFFFFFFFFFFFFFFFEC8AB9ECB29CEC9D9820EBB3B4EBA3A820ECA780EC9B9000003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'koKR', 0xFFFFFFFFFFFFFFFFEBAABDED9998EC88B220ECA780EC9B9000003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'koKR', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'koKR', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'koKR', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'koKR', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'koKR', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'koKR', 0x00000000, 40944),
(3865974254, 176921, 'koKR', 0x00000000, 40944),
(3865974254, 176832, 'koKR', 0x00000000, 40944),
(3776013982, 243328, 'koKR', 0x0000EC9C84ED989120EC8898ECA48020EAB090EC868C00, 40944),
(3865974254, 187935, 'koKR', 0x00000000, 40944),
(3205218938, 44300, 'koKR', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F5800EC9DB420ED95ADEBAAA9EC9D8420EC9EA0EAB88820ED95B4ECA09CED9598EBA0A4EBA9B420EAB384ECA095EC979020EC9DB8ECA69DEAB8B0EC998020534D5320EC958CEBA6BCEC9DB4EBA5BC20EC97B0EAB2B0ED95B4EC95BC20ED95A9EB8B88EB8BA40001, 40944),
(3205218938, 44299, 'koKR', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C636666666630303030EC9090EAB8B0EB8F8C20EC9786EC9DB420EC8BA0ED99942B20ED8C8CED8BB0EBA5BC20EBAAA8ECA791ED9598EBA0A4EBA9B420426174746C652E6E657420EC9DB8ECA69DEAB8B0EC998020534D5320EC958CEBA6BCEC9DB4EBA19C20EAB384ECA095EC9D9820EBB3B4EC9588EC9D8420EAB095ED9994ED95B4EC95BC20ED95A9EB8B88EB8BA47C727C6E7C6366663165666630303CEC9E90EC84B8ED9E8820EC958CEC9584EBB3B4EAB8B03E7C720001, 40944),
(3205218938, 44284, 'koKR', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C636666666630303030EC9DB420ED95ADEBAAA9EC9D8420EC8898ECA095ED9598EBA0A4EBA9B420426174746C652E6E657420EC9DB8ECA69DEAB8B0EC998020534D5320EC958CEBA6BCEC9DB4EBA19C20EAB384ECA095EC9D9820EBB3B4EC9588EC9D8420EAB095ED9994ED95B4EC95BC20ED95A9EB8B88EB8BA42E7C727C6E7C6366663165666630303CEC9E90EC84B8ED9E8820EC958CEC9584EBB3B4EAB8B03E7C720001, 40944),
(3205218938, 44283, 'koKR', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F4445534300EAB384ECA095EC979020EC9DB8ECA69DEAB8B0EC998020534D5320EC958CEBA6BCEC9DB4EBA5BC20EC97B0EAB2B0ED9598EAB3A020ED8C8CED8BB020ECB0BEEAB8B020EAB8B0EB8AA5EC9D8420ECA09CEC95BD20EC9786EC9DB420EC82ACEC9AA9ED95B4EBB3B4EC84B8EC9A942E7C6E7C6E426174746C652E6E657420EC9DB8ECA69DEAB8B0EB8A9420EAB084ED8EB8ED9598EAB28C20EC82ACEC9AA9ED95A020EC889820EC9E88EB8A9420EBACB4EBA38C20EC849CEBB984EC8AA4EBA19CEC849C20EC97ACEB9FACEBB684EC9D9820EAB384ECA095EC9D8420EC9588ECA084ED9598EAB28C20ECA780ECBC9CECA48DEB8B88EB8BA42E20EB9890ED959C2C20534D5320EC958CEBA6BCEC9DB4EB8A9420EAB384ECA09520ECA095EBB3B4EC9D9820EBB380EAB2BDEC9DB420EC9E88EB8A9420EAB2BDEC9AB020EC9588EB82B420EBA994EC8B9CECA780EBA5BC20ECA084EC86A1ED95B420ECA48DEB8B88EB8BA42E7C6E7C6E22ED999CEC84B1ED999422EBA5BC20ED81B4EBA6ADED9598EBA9B420EAB384ECA09520EBB3B4EC958820EC84A4ECA09520EC9BB9EC82ACEC9DB4ED8AB8EBA5BC20EC8BA4ED9689ED95A9EB8B88EB8BA42E0001, 40944),
(3776013982, 358927, 'koKR', 0x00ECA3BCEC9C84EC9D9820EBAAA8EB93A020EAB283EC9D8420EC9D98EC8BACED95A9EB8B88EB8BA42E20EB8298EC9DB4ED8AB8EBB3B8EC9790EAB28CEB8A9420EC9EACEC82ACEC9AA920EB8C80EAB8B0EC8B9CEAB084EC9DB420EAB090EC868CED95A9EB8B88EB8BA42E00ECA3BCEC9C84EC9D9820EBAAA8EB93A020EAB283EC9D8420EC9D98EC8BACED95A800, 40944),
(3865974254, 188152, 'koKR', 0x00000000, 40944),
(3776013982, 53385, 'koKR', 0x00ECB29CEC8381EC9D9820ED9E98EC9D9820EC868CEC9AA9EB8F8CEC9DB4EBA5BC20EB82B4EBBF9CEC96B420ECA3BCEC9C84EC979020EC9E88EB8A9420EBAAA8EB93A020ECA081EC9790EAB28C20247331EC9D9820EC8BA0EC84B120ED94BCED95B4EBA5BC20EC9E85ED9E99EB8B88EB8BA42E20EB8C80EC8381EC9DB420247332EBAA85EC9D8420ECB488EAB3BCED9598EBA9B420EAB090EC868CEB909C20ED94BCED95B4EBA5BC20EC9E85ED9E99EB8B88EB8BA42E0000, 40944),
(261693969, 62694, 'koKR', 0xFFFFFFFFFFFFFFFFEBA790EB939CEB9DBDEC849CEC8AA4EC9D9820EBB680EBA684000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'koKR', 0xFFFFFFFFFFFFFFFFEBAABDED9998EC88B2EC9D9820EBB680EBA684000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'koKR', 0xFFFFFFFFFFFFFFFFEC8AB9ECB29CEC9D9820EBB3B4EBA3A8EC9D9820EBB680EBA684000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'koKR', 0xFFFFFFFFFFFFFFFFEBA088EBB2A4EB939CEBA088EC8AA4EC9D9820EBB680EBA684000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'koKR', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'koKR', 0x000000, 40944),
(3776013982, 307934, 'koKR', 0x000000, 40944),
(3776013982, 307480, 'koKR', 0x00EB8AA5EC8899ED959C20ED9788EB939CEBA088EABEBCEC9D8420EB8D98ECA791EB8B88EB8BA42E0000, 40944),
(2948698321, 354, 'koKR', 0x64DF8D9146629CB2, 40944),
(261693969, 60111, 'koKR', 0xFFFFFFFFFFFFFFFFECB99CEBB68420EB8BA4ECA780EAB8B000005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'koKR', 0xFFFFFFFFFFFFFFFFEC84B8EC8381EC979020EB829820EAB099EC9D8020ECB99CEAB5ACEAB08020EC96B4EB94A8EB8BA4EAB3A000005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'koKR', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'koKR', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'koKR', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'koKR', 0x00000000, 40944),
(3865974254, 151804, 'koKR', 0x00000000, 40944),
(3865974254, 151792, 'koKR', 0x00000000, 40944),
(3037505077, 151792, 'koKR', 0x0100, 40944),
(3865974254, 151790, 'koKR', 0x00000000, 40944),
(3037505077, 151790, 'koKR', 0x0100, 40944),
(3865974254, 146306, 'koKR', 0x00000000, 40944),
(3865974254, 34685, 'koKR', 0x00000000, 40944),
(3865974254, 34683, 'koKR', 0x00000000, 40944),
(3865974254, 34087, 'koKR', 0x00000000, 40944),
(3865974254, 34085, 'koKR', 0x00000000, 40944),
(3865974254, 33969, 'koKR', 0x00000000, 40944),
(3865974254, 33968, 'koKR', 0x00000000, 40944),
(3865974254, 33967, 'koKR', 0x00000000, 40944),
(3865974254, 33966, 'koKR', 0x00000000, 40944),
(3865974254, 33868, 'koKR', 0x00000000, 40944),
(3865974254, 33864, 'koKR', 0x00000000, 40944),
(3865974254, 33863, 'koKR', 0x00000000, 40944),
(3865974254, 33862, 'koKR', 0x00000000, 40944),
(3865974254, 23324, 'koKR', 0x00000000, 40944),
(3865974254, 21525, 'koKR', 0x00000000, 40944),
(3865974254, 21524, 'koKR', 0x00000000, 40944),
(3865974254, 19028, 'koKR', 0x00000000, 40944),
(3865974254, 6835, 'koKR', 0x00000000, 40944),
(3865974254, 6833, 'koKR', 0x00000000, 40944),
(3865974254, 181321, 'koKR', 0x00000000, 40944),
(1548466975, 27672, 'koKR', 0x10040000, 40944),
(3776013982, 365080, 'koKR', 0x0000EC9DB4EB8F9920EC868DEB8F842024733125EBA78CED81BC20ECA69DEAB08000, 40944),
(3776013982, 317920, 'koKR', 0x00246131EBAFB8ED84B020EB82B4EC9D9820ED8C8CED8BB0EC9B90EAB3BC20EAB3B5EAB2A9EB8C80EC9B90EC9790EAB28C20EC8B9CECA084EB9098EB8A9420ECA3BCEBACB820EBB0A9ED95B420EBB08F20ECB9A8EBACB520ED9AA8EAB3BCEC9D9820ECA780EC868DEC8B9CEAB084EC9DB42024733125EBA78CED81BC20EAB090EC868CED95A9EB8B88EB8BA42E243F733333393132345B20EAB3B5ED8FAC20ED9AA8EAB3BCEC9D9820ECA780EC868DEC8B9CEAB084EB8F8420EAB090EC868CED95A9EB8B88EB8BA42E5D5B5D00ECA3BCEBACB820EBB0A9ED95B420EBB08F20ECB9A8EBACB520ED9AA8EAB3BC2024773125EBA78CED81BC20EAB090EC868C243F733333393132345B0D0AEAB3B5ED8FAC20ED9AA8EAB3BC2024773425EBA78CED81BC20EAB090EC868C5D5B5D00, 40944),
(3776013982, 465, 'koKR', 0x00ECA3BCEC9C8420246131EBAFB8ED84B020EBB098EAB2BDEC979020EC9E88EB8A9420ED8C8CED8BB0EC9B90EAB3BC20EAB3B5EAB2A9EB8C80EC9B90EC9DB420EAB2BDEAB1B4ED95A8EC9CBCEBA19C20EAB3A0EBACB4EB9098EC96B420EBB09BEB8A9420ED94BCED95B4EAB0802024733125EBA78CED81BC20EAB090EC868CED95A9EB8B88EB8BA42E00EBB09BEB8A9420ED94BCED95B42024773125EBA78CED81BC20EAB090EC868C00, 40944),
(3205218938, 44172, 'koKR', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F4445534300ED8F89ECA0902031393530ECA09020EC9DB4EC838120EB8BACEC84B13A7C6E2D20ED948CEBA088EC9DB4EC96B420EAB08420ECA084ED88AC20EC9584EC9DB4ED859C20EAB095ED999420EB93B1EAB8890001, 40944),
(3205218938, 40887, 'koKR', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F4445534300ED8F89ECA0902031383030ECA09020EC9DB4EC838120EB8BACEC84B13A7C6E2D20EC8AB9EBB680EC82AC20ECB9ADED98B87C6E2D20ECA095EC988820ED948CEBA088EC9DB4EC96B420EAB08420ECA084ED88AC20EC9584EC9DB4ED859C20EC84B8ED8AB820EC99B8ED98953A20ED88ACEAB5AC7C6E2D20ECA095EC988820ED948CEBA088EC9DB4EC96B420EAB08420ECA084ED88AC20EC9584EC9DB4ED859C20EC84B8ED8AB820EC99B8ED98953A20EC96B4EAB9A80001, 40944),
(3205218938, 40885, 'koKR', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F4445534300ED8F89ECA0902031343030ECA09020EC9DB4EC838120EB8BACEC84B13A7C6E2D20EB8F84ECA084EC9E9020ECB9ADED98B87C6E2D20ECA095EC988820ED948CEBA088EC9DB4EC96B420EAB08420ECA084ED88AC20EC9584EC9DB4ED859C20EC84B8ED8AB820EC99B8ED98953A20EC9EA5EAB0917C6E2D20ECA095EC988820ED948CEBA088EC9DB4EC96B420EAB08420ECA084ED88AC20EC9584EC9DB4ED859C20EC84B8ED8AB820EC99B8ED98953A20EC9EA5ED99940001, 40944),
(3776013982, 357407, 'koKR', 0x00EBA19CED81B0EBA1A420EC9E90EB8F99ECB0A820EC95BDED8388EC9E90EBA5BC20EC868CED9998ED9598EC97AC20ECA1B0ECA285ED95A9EB8B88EB8BA42E00ED9689EB8F9920EB8BA8ECB695EBB094EBA5BC20EC82ACEC9AA9ED9598EC97AC20EB8BA4EBA5B820EC9B90EAB2A920ECA1B0ECA28520EC9EA5EB829CEAB09020EAB3B5EAB2A900, 40944),
(3776013982, 357406, 'koKR', 0x00EBA19CED81B0EBA1A420EC9E90EB8F99ECB0A820EC95BDED8388EC9E90EBA5BC20EC868CED9998ED9598EC97AC20ECA1B0ECA285ED95A9EB8B88EB8BA42E00ED9689EB8F9920EB8BA8ECB695EBB094EBA5BC20EC82ACEC9AA9ED9598EC97AC20EB8BA4EBA5B820EC9B90EAB2A920ECA1B0ECA28520EC9EA5EB829CEAB09020EAB3B5EAB2A900, 40944),
(3776013982, 357405, 'koKR', 0x00EBA19CED81B0EBA1A420EC9E90EB8F99ECB0A820EC95BDED8388EC9E90EBA5BC20EC868CED9998ED9598EC97AC20ECA1B0ECA285ED95A9EB8B88EB8BA42E00ED9689EB8F9920EB8BA8ECB695EBB094EBA5BC20EC82ACEC9AA9ED9598EC97AC20EB8BA4EBA5B820EC9B90EAB2A920ECA1B0ECA28520EC9EA5EB829CEAB09020EAB3B5EAB2A900, 40944),
(3776013982, 356631, 'koKR', 0x00EBA19CED81B0EBA1A420EC9E90EB8F99ECB0A820EAB3B5ECA49120ECB9BCEB82A0EC9D8420EC868CED9998ED9598EC97AC20ECA1B0ECA285ED95A9EB8B88EB8BA42E00ED9689EB8F9920EB8BA8ECB695EBB094EBA5BC20EC82ACEC9AA9ED9598EC97AC20EB8BA4EBA5B820EC9B90EAB2A920ECA1B0ECA28520EC9EA5EB829CEAB09020EAB3B5EAB2A900, 40944),
(3776013982, 328923, 'koKR', 0xEB8298EC9DB4ED8AB820ED8E98EC9DB400EB8C80EC838120ECA780EC97AD20EB82B4EC979020EC9E88EB8A9420ECA08120ECB59CEB8C80202433323839323849EBAA85EC9D9820EC839DEBAA85EBA0A5EC9D8420EC9DB4ECA084EC8B9CECBC9C202464EC979020EAB1B8ECB39020247B282433323839323873312A24642F24743229202B202433323839323873317DEC9D9820EC9E90EC97B020ED94BCED95B4EBA5BC20ECA08120EB8C80EC8381EC9790EAB28C20EB8298EB8884EC96B420EC9E85ED9E99EB8B88EB8BA42E20243F613133373034315B0D0A0D0AED8E98EC9DB420EC8898ED988820EC8B9CECA084EC9D8420EB819DEAB98CECA78020EBA788ECB998EBA9B420EC868CEC9AA9EB8F8CEC9DB4ECB998EB8A9420EBACB4EAB8B020247334ECA491ECB2A9EC9D8420EC839DEC84B1ED95A9EB8B88EB8BA42E5D5B5D0D0A0D0A243332383933336420EC9588EC979020ED8E98EC9DB420EC8898ED9888EC9D8420EB8BA4EC8B9C20EC82ACEC9AA9ED9598EBA9B420EC9E85ED9E8C20EBAAA8EB93A020ED94BCED95B4EC9D982024733125EBA5BC20EBB0A9ECB69CED95B420243332383933304131EBAFB8ED84B020EB82B4EC979020EC9E88EB8A9420ECB59CEB8C8020243332383933307332EBAA85EC9D9820EC9584EAB5B0EC9D8420ECB998EC9CA0ED95A9EB8B88EB8BA42E0000, 40944),
(3776013982, 101546, 'koKR', 0x00EAB3B5ECA49120ED9A8CECA08420EBB09CECB0A8EAB8B0EBA19C202464EC979020EAB1B8ECB39020EBB098EAB2BD20243130373237304131EBAFB8ED84B020EB82B4EC979020EC9E88EB8A9420EBAAA8EB93A020ECA081EC9790EAB28C20243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5DEC9D9820EBACBCEBA6AC20ED94BCED95B4EBA5BC20EC9E85ED9E99EB8B88EB8BA42E20EB8C80EC8381EC9DB420247331EBAA85EC9D8420ECB488EAB3BCED9598EBA9B420EAB090EC868CEB909C20ED94BCED95B4EBA5BC20EC9E85ED9E99EB8B88EB8BA42E243F63335B0D0A0D0AECA780EB829C20243232303335386420EB8F99EC958820EBB294EC9D9820EC9EA5ED928D2C20ED9B84EBA0A4ECB0A8EAB8B02C20ED95B4EC98A4EBA684ECB0A8EAB8B0EBA19C20EAB3B5EAB2A9ED959C20ECA08120EAB09CECB2B420ED9598EB8298EB8BB920ED9A8CECA08420ED9599EB8BA4EBA6ACECB0A8EAB8B0EC9D9820EAB3B5EAB2A9EBA0A5EC9DB42024323230333538733125EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E20ECB59CEB8C80202432323832383769EBB288EAB98CECA78020ECA491ECB2A9EB90A9EB8B88EB8BA42E5D5B5D00ECA3BCEC9C8420ECA081EC9790EAB28C20243130313534367431ECB488EBA788EB8BA420EBACBCEBA6AC20ED94BCED95B400, 40944),
(3865974254, 188220, 'koKR', 0x00000000, 40944),
(3865974254, 187900, 'koKR', 0x00000000, 40944),
(3865974254, 187899, 'koKR', 0x00000000, 40944),
(3865974254, 187898, 'koKR', 0x00000000, 40944),
(3865974254, 187897, 'koKR', 0x00000000, 40944),
(3865974254, 187896, 'koKR', 0x00000000, 40944),
(3865974254, 187895, 'koKR', 0x00000000, 40944),
(3865974254, 187875, 'koKR', 0x00000000, 40944),
(3865974254, 187869, 'koKR', 0x00000000, 40944),
(3865974254, 150746, 'koKR', 0x00000000, 40944),
(3865974254, 150745, 'koKR', 0x00000000, 40944),
(3865974254, 150744, 'koKR', 0x00000000, 40944),
(3865974254, 150743, 'koKR', 0x00000000, 40944),
(3776013982, 364944, 'koKR', 0x0000EC9DB4EB8F9920EC868DEB8F842024733125EBA78CED81BC20ECA69DEAB08000, 40944),
(3776013982, 228462, 'koKR', 0x00EC9E90EB8F9920EAB3B5EAB2A9EC9D9820EAB3B5EAB2A9EBA0A5EC9DB420247331EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0000, 40944),
(3776013982, 119611, 'koKR', 0x0024407370656C6C6465736331313531353100247431ECB488EBA788EB8BA420247731EC9D9820EC839DEBAA85EBA0A520ED9A8CEBB3B500, 40944),
(3776013982, 119607, 'koKR', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'koKR', 0x00000000, 40944),
(1181150530, 403396, 'koKR', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'koKR', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'koKR', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'koKR', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'koKR', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'koKR', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'koKR', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'koKR', 0xA4530000, 40944),
(3359787322, 21411, 'koKR', 0xA3530000, 40944),
(3359787322, 21410, 'koKR', 0xA2530000, 40944),
(3359787322, 21409, 'koKR', 0xA1530000, 40944),
(3359787322, 21408, 'koKR', 0xA0530000, 40944),
(3359787322, 21407, 'koKR', 0x9F530000, 40944),
(3359787322, 21406, 'koKR', 0x9E530000, 40944),
(2557447376, 655518, 'koKR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'koKR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'koKR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'koKR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'koKR', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'koKR', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F45464645435400EC989B20ECA084EBA6ACED928820ED9A8DEB939D20EAB79CECB999EC9DB420EBB984ED999CEC84B1ED9994EB9098EC9788EC8AB5EB8B88EB8BA42E0001, 40944),
(3776013982, 347944, 'koKR', 0x00ECB998EBAA85ED838020EBB08F20EAB7B9EB8C80ED9994EC9CA8EC9DB42024733125EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0D0A00ECB998EBAA85ED838020EBB08F20EAB7B9EB8C80ED9994EC9CA82024733125EBA78CED81BC20ECA69DEAB08000, 40944),
(3776013982, 347943, 'koKR', 0x00ECB59CEB8C8020EC839DEBAA85EBA0A5EC9DB42024733125EBA78CED81BC20ECA69DEAB080ED95A9EB8B88EB8BA42E0D0A00ECB59CEB8C8020EC839DEBAA85EBA0A52024733125EBA78CED81BC20ECA69DEAB08000, 40944),
(3776013982, 1714, 'koKR', 0x00EC9585EBA788EC96B4EBA19C20EBA790ED9598EB8F84EBA19D20EB8C80EC8381EC9D8420EAB095ECA09CED9598EC97AC20ECA3BCEBACB8EC9D9820EC8B9CECA08420EC8B9CEAB084EC9D842024733125EBA78CED81BC20ECA780EC97B0EC8B9CED82B5EB8B88EB8BA42E20246420EB8F99EC958820ECA780EC868DEB90A9EB8B88EB8BA42E243F733130333131325B0D0A0D0A7C434646453535424230EC9881ED98BC20EBB688EC82ACEBA5B4EAB8B03A20EB8C80EC8381EC9CBCEBA19CEBB680ED84B0202431303432323441EBAFB8ED84B020EC9588EC979020EC9E88EB8A9420EBAAA8EB93A020ECA081EC9790EAB28C20EC96B8EC96B4EC9D9820ECA080ECA3BCEAB08020EAB1B8EBA6BDEB8B88EB8BA42E7C525D5B5D0D0A0D0A7C634646383238324646ECA080ECA3BC3A20ED9D91EBA788EBB295EC82ACEBA788EB8BA420ED959C20EB8C80EC8381EC979020EB8F99EC8B9CEC979020ED9598EB8298EC9D9820ECA080ECA3BCEBA78C20EAB1B820EC889820EC9E88EC8AB5EB8B88EB8BA42E7C7200ECA3BCEBACB820EC8B9CECA08420EC8B9CEAB0842024773125EBA78CED81BC20ECA780EC97B000, 40944),
(3205218938, 41865, 'koKR', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E5300EBAAA8ECA79120ECA095EBB3B4EBA5BC20ED8EB8ECA791ED95A020EAB68CED959CEC9DB420EC9786EC8AB5EB8B88EB8BA42E0001, 40944),
(261693969, 64850, 'koKR', 0xFFFFFFFFFFFFFFFFED86A0EBA5B4EAB080EC8AA4ED8AB820ED8390ED9798000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'koKR', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='koKR') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='koKR');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'koKR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `achievement_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (14775,14752,14682,14351));
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14775, 'ptBR', 'Tornar-se exaltado por Marasmius.', 'Cogumuito obrigado', 'Título: Gente Fina', 40944),
(14752, 'ptBR', 'Obter as conquistas de Sutura de Abominação listadas abaixo.', 'Coisas para fazer quando se está morto', 'Título: Abominável e montaria: Tauralus Escolhido Couraçado', 40944),
(14682, 'ptBR', 'Obter as conquistas de Corte das Brasas listadas abaixo.', 'O Arauto da Festa', 'Título: Arauto da Festa', 40944),
(14351, 'ptBR', 'Derrotar 39 chefes no Caminho da Ascensão.', 'O caminho para a ascensão 39', 'Desbloquear mais desafios no Caminho da Ascensão.', 40944);


DELETE FROM `area_table_locale` WHERE (`VerifiedBuild`>0 AND `ID`=13316 AND `locale`='ptBR');
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(13316, 'ptBR', 'Casa dos Rituais', 40944);


DELETE FROM `battle_pet_species_locale` WHERE (`VerifiedBuild`>0 AND `ID`=3188 AND `locale`='ptBR');
INSERT INTO `battle_pet_species_locale` (`ID`, `locale`, `Description_lang`, `SourceText_lang`, `VerifiedBuild`) VALUES
(3188, 'ptBR', '', '', 40944);


DELETE FROM `broadcast_text_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (215513,215512,215511));
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(215513, 'ptBR', '', 'Não é prudente aventurar-se pela Gorja sem a devida preparação. Fale comigo quando estiver pronta.', 40944),
(215512, 'ptBR', 'Não é prudente aventurar-se pela Gorja sem a devida preparação. Fale comigo quando estiver pronto.', '', 40944),
(215511, 'ptBR', '', 'Estamos muito perto. Lute ao meu lado, e passaremos por tudo isso juntos.', 40944);


DELETE FROM `char_titles_locale` WHERE (`VerifiedBuild`>0 AND `ID`=693 AND `locale`='ptBR');
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(693, 'ptBR', '%s, o Ascendido', '%s, a Ascendida', 40944);


UPDATE `char_titles_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=683 AND `locale`='ptBR');
DELETE FROM `chr_customization_option_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (1523,689));
INSERT INTO `chr_customization_option_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1523, 'ptBR', 'Cauda', 40944),
(689, 'ptBR', 'Cauda', 40944);


DELETE FROM `criteria_tree_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (91730,94390,94389,94388,93811,93810,94331,94330));
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91730, 'ptBR', '9.1 Metaconquista', 40944),
(94390, 'ptBR', '', 40944),
(94389, 'ptBR', '', 40944),
(94388, 'ptBR', '', 40944),
(93811, 'ptBR', '', 40944),
(93810, 'ptBR', 'Nível de Renome 80', 40944),
(94331, 'ptBR', '', 40944),
(94330, 'ptBR', 'Renown Level 80 - Kyrian', 40944);


DELETE FROM `item_search_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,116401));
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(151806, 'ptBR', 'Vestido Elegante', 40944),
(151804, 'ptBR', 'Calça Preta de Smoking', 40944),
(151792, 'ptBR', 'Roupas Verdes de Inverno', 40944),
(151790, 'ptBR', 'Roupas Vermelhas de Inverno', 40944),
(34685, 'ptBR', 'Traje de Verão', 40944),
(34683, 'ptBR', 'Sandálias de Verão', 40944),
(34087, 'ptBR', 'Roupas Verdes de Inverno', 40944),
(34085, 'ptBR', 'Roupas Vermelhas de Inverno', 40944),
(33969, 'ptBR', 'Chapéu Roxo da CervaFest', 40944),
(33968, 'ptBR', 'Chapéu Azul da CervaFest', 40944),
(33967, 'ptBR', 'Chapéu Verde da CervaFest', 40944),
(33966, 'ptBR', 'Sapatilhas da CervaFest', 40944),
(33868, 'ptBR', 'Botas da CervaFest', 40944),
(33864, 'ptBR', 'Chapéu Marrom da CervaFest', 40944),
(33863, 'ptBR', 'Vestido da CervaFest', 40944),
(33862, 'ptBR', 'Paramentos da CervaFest', 40944),
(23324, 'ptBR', 'Dragonas do Festival do Fogo', 40944),
(21525, 'ptBR', 'Chapéu Verde de Inverno', 40944),
(21524, 'ptBR', 'Chapéu Vermelho de Inverno', 40944),
(19028, 'ptBR', 'Vestido Elegante', 40944),
(6835, 'ptBR', 'Calça Preta de Smoking', 40944),
(6833, 'ptBR', 'Camisa Branca de Smoking', 40944),
(181321, 'ptBR', 'Varinha Coroada em Gemas', 40944),
(116401, 'ptBR', 'Chapéu do Peregrino Fino', 40944);


DELETE FROM `item_sparse_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (176922,176921,176832,187935,188152,151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,188220,187900,187899,187898,187897,187896,187895,187875,187869,150746,150745,150744,150743,116401));
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(176922, 'ptBR', 'Esta flor mágica aumenta em 100% a quantidade de matérias-primas oferecida pelos espíritos renascidos e de catalisadores gerados pelas sementes de catalisador.', '', '', '', 'Botão-da-noite Selvagem', 40944),
(176921, 'ptBR', 'As folhas encantadas encurtam em 1 dia o processo da Semente Selvagem do Recrescimento.', '', '', '', 'Folhas Temporais', 40944),
(176832, 'ptBR', 'Essa raiz especial aumenta a qualidade das recompensas oferecidas por um espírito ao renascer.', '', '', '', 'Farinha de Raiz de Semente Selvagem', 40944),
(187935, 'ptBR', 'Ensina a fazer uma Marca do Runicervo da Meia-noite.', '', '', '', 'Técnica: Marca do Runicervo da Meia-noite', 40944),
(188152, 'ptBR', 'A magia do estilhaço é calcinante ao toque.', '', '', '', 'Estilhaço de Controle do Portal', 40944),
(151806, 'ptBR', '', '', '', '', 'Vestido Elegante', 40944),
(151804, 'ptBR', '', '', '', '', 'Calça Preta de Smoking', 40944),
(151792, 'ptBR', '', '', '', '', 'Roupas Verdes de Inverno', 40944),
(151790, 'ptBR', '', '', '', '', 'Roupas Vermelhas de Inverno', 40944),
(34685, 'ptBR', '', '', '', '', 'Traje de Verão', 40944),
(34683, 'ptBR', '', '', '', '', 'Sandálias de Verão', 40944),
(34087, 'ptBR', '', '', '', '', 'Roupas Verdes de Inverno', 40944),
(34085, 'ptBR', '', '', '', '', 'Roupas Vermelhas de Inverno', 40944),
(33969, 'ptBR', '', '', '', '', 'Chapéu Roxo da CervaFest', 40944),
(33968, 'ptBR', '', '', '', '', 'Chapéu Azul da CervaFest', 40944),
(33967, 'ptBR', '', '', '', '', 'Chapéu Verde da CervaFest', 40944),
(33966, 'ptBR', '', '', '', '', 'Sapatilhas da CervaFest', 40944),
(33868, 'ptBR', '', '', '', '', 'Botas da CervaFest', 40944),
(33864, 'ptBR', '', '', '', '', 'Chapéu Marrom da CervaFest', 40944),
(33863, 'ptBR', '', '', '', '', 'Vestido da CervaFest', 40944),
(33862, 'ptBR', '', '', '', '', 'Paramentos da CervaFest', 40944),
(23324, 'ptBR', '', '', '', '', 'Dragonas do Festival do Fogo', 40944),
(21525, 'ptBR', '', '', '', '', 'Chapéu Verde de Inverno', 40944),
(21524, 'ptBR', '', '', '', '', 'Chapéu Vermelho de Inverno', 40944),
(19028, 'ptBR', '', '', '', '', 'Vestido Elegante', 40944),
(6835, 'ptBR', '', '', '', '', 'Calça Preta de Smoking', 40944),
(6833, 'ptBR', '', '', '', '', 'Camisa Branca de Smoking', 40944),
(181321, 'ptBR', '', '', '', '', 'Varinha Coroada em Gemas', 40944),
(188220, 'ptBR', 'Traz a frase \"Eu sobrevivi à Torre\".', '', '', '', 'Globo de Cinzas da Thanator', 40944),
(187900, 'ptBR', 'Um goblin e um gnomo contam suas descobertas nas duas ilhas.', '', '', '', 'Mapa de Patrulha: As Maravilhas de Kul Tiraz e Zandalar', 40944),
(187899, 'ptBR', 'A descrição que um alquimista fez dos diversos biomas e da incrível flora de Terralém.', '', '', '', 'Mapa de Patrulha: As Idiossincrasias de Terralém', 40944),
(187898, 'ptBR', 'O relatório minucioso de um Cruzado Argênteo sobre todas as operações militares realizadas na busca do Lich Rei.', '', '', '', 'Mapa de Patrulha: O Custo por Trás da Campanha em Nortúndria', 40944),
(187897, 'ptBR', 'Um raro relatório de facções unidas que relata as inúmeras consequências da destruição provocada por Asa da Morte em Azeroth.', '', '', '', 'Mapa de Patrulha: Consequências do Cataclismo', 40944),
(187896, 'ptBR', 'Um divertido conto sobre as últimas aventuras de Li Li em Pandária, com dicas culinárias do seu tio Chen.', '', '', '', 'Mapa de Patrulha: Guia Malte do Trovão - Pandária', 40944),
(187895, 'ptBR', 'Uma lista concisa dos poucos refúgios de Draenor e dos costumes locais de cada um deles.', '', '', '', 'Mapa de Patrulha: Os Perigos de Draenor', 40944),
(187875, 'ptBR', 'Uma vasta coleção de relatórios e correspondências de unidades militares díspares na luta contra a Legião.', '', '', '', 'Mapa de Patrulha: Frentes Unidas das Ilhas Partidas', 40944),
(187869, 'ptBR', 'Um rico conto sobre a jornada de um Caminhante da Gorja pelas Terras Sombrias.', '', '', '', 'Mapa de Patrulha: Rumo às Terras Sombrias', 40944),
(150746, 'ptBR', 'Uma proposta singela de como guarnecer prontamente os postos avançados dos Reinos do Leste.', '', '', '', 'Mapa de Patrulha: Modernização do Provisionamento nos Reinos do Leste', 40944),
(150745, 'ptBR', 'Táticas avançadas de como aniquilar as forças da Aliança nos Reinos do Leste durante os eventos da Quarta Guerra.', '', '', '', 'Mapa de Patrulha: Campanha nos Reinos do Leste', 40944),
(150744, 'ptBR', 'Como curar as cicatrizes na terra causadas por seres corrompidos, perversos e sobrenaturais.', '', '', '', 'Mapa de Patrulha: Caminhada por Kalimdor com a Mãe Terra', 40944),
(150743, 'ptBR', 'Uma enorme compilação de feras venenosas, com garras e dentes, aliadas à Horda.', '', '', '', 'Mapa de Patrulha: Sobrevivência em Kalimdor', 40944),
(116401, 'ptBR', '', '', '', '', 'Chapéu do Peregrino Fino', 40944);


UPDATE `item_sparse_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (185950,185947,185946));
DELETE FROM `lfg_dungeons_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1445 AND `locale`='ptBR');
INSERT INTO `lfg_dungeons_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1445, 'ptBR', 'Queda do Totem Vil', 'Impedir Tugar Totem de Sangue e seus Vermes Vis de trazer a montanha abaixo.', 40944);


DELETE FROM `map_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1756 AND `locale`='ptBR');
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(1756, 'ptBR', 'As Mortes de Crona', '', '', '', '', 40944);


DELETE FROM `player_condition_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (95078,95077,95076,85644,73006,73005,87365,85912,85910,85909,85692,94517,94516,94515,94514,94513,94512,94511));
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(95078, 'ptBR', '', 40944),
(95077, 'ptBR', '', 40944),
(95076, 'ptBR', '', 40944),
(85644, 'ptBR', 'Nível $pcMinLevel necessário para prosseguir.', 40944),
(73006, 'ptBR', '', 40944),
(73005, 'ptBR', '', 40944),
(87365, 'ptBR', '', 40944),
(85912, 'ptBR', '', 40944),
(85910, 'ptBR', '', 40944),
(85909, 'ptBR', '', 40944),
(85692, 'ptBR', '', 40944),
(94517, 'ptBR', '', 40944),
(94516, 'ptBR', '', 40944),
(94515, 'ptBR', '', 40944),
(94514, 'ptBR', '', 40944),
(94513, 'ptBR', '', 40944),
(94512, 'ptBR', '', 40944),
(94511, 'ptBR', '', 40944);


DELETE FROM `spell_category_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1186 AND `locale`='ptBR');
INSERT INTO `spell_category_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1186, 'ptBR', 'Class - Paladin - Hand of Sacrifice', 40944);


DELETE FROM `spell_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (361952,256817,247692,247111,247110,247104,247103,247099,247096,247094,247093,247092,247089,247088,228844,227799,227780,362986,243328,358927,53385,329902,307934,307480,365080,317920,465,357407,357406,357405,356631,328923,101546,364944,228462,119611,119607,347944,347943,1714));
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(361952, 'ptBR', '1000 de Ânima', 40944),
(256817, 'ptBR', 'Marca de Aman\'Thul', 40944),
(247692, 'ptBR', 'Continuidade de Lembrança', 40944),
(247111, 'ptBR', 'Blessing of the Bronze Dragonflight Passive', 40944),
(247110, 'ptBR', 'Velocidade Infinita', 40944),
(247104, 'ptBR', 'Acceleration Passive', 40944),
(247103, 'ptBR', 'Passiva de Parar o Tempo', 40944),
(247099, 'ptBR', 'Chrono Charisma Passive', 40944),
(247096, 'ptBR', 'Rapid Recovery Passive', 40944),
(247094, 'ptBR', 'Fortuitidade', 40944),
(247093, 'ptBR', 'Dragon\'s Determination Passive', 40944),
(247092, 'ptBR', 'Accelerated Aggression Passive', 40944),
(247089, 'ptBR', 'Dragon Crash Passive', 40944),
(247088, 'ptBR', 'Percepção', 40944),
(228844, 'ptBR', 'Ossos Ardentes', 40944),
(227799, 'ptBR', 'Poder das Ondas', 40944),
(227780, 'ptBR', 'Ritual do Trovão', 40944),
(362986, 'ptBR', 'Experiência', 40944),
(243328, 'ptBR', 'Desvanecer', 40944),
(358927, 'ptBR', 'Vigilância da Guarda dos Filhos da Noite', 40944),
(53385, 'ptBR', 'Tempestade Divina', 40944),
(329902, 'ptBR', 'Dragando', 40944),
(307934, 'ptBR', 'Dragando', 40944),
(307480, 'ptBR', 'Arremessar Dragador', 40944),
(365080, 'ptBR', 'Andando sobre o vento', 40944),
(317920, 'ptBR', 'Aura de Concentração', 40944),
(465, 'ptBR', 'Aura de Devoção', 40944),
(357407, 'ptBR', 'Evocar Havac', 40944),
(357406, 'ptBR', 'Evocar Tankudo', 40944),
(357405, 'ptBR', 'Evocar Demônio Pútrido', 40944),
(356631, 'ptBR', 'Evocar Laminaérea', 40944),
(328923, 'ptBR', 'Transfusão Feéria', 40944),
(101546, 'ptBR', 'Chute Giratório da Garça', 40944),
(364944, 'ptBR', 'Andando sobre o vento', 40944),
(228462, 'ptBR', 'Sinete de Melandrus', 40944),
(119611, 'ptBR', 'Brumas da Renovação', 40944),
(119607, 'ptBR', 'Brumas da Renovação', 40944),
(347944, 'ptBR', 'Espetos de Obleron', 40944),
(347943, 'ptBR', 'Resistência de Obleron', 40944),
(1714, 'ptBR', 'Maldição de Línguas', 40944);


DELETE FROM `transmog_set_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (2289,2287,2283,2281,2277,2275,2271,2269,2178));
INSERT INTO `transmog_set_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(2289, 'ptBR', 'Placa do Gladiador Desacorrentado', 40944),
(2287, 'ptBR', 'Placa do Gladiador Desacorrentado', 40944),
(2283, 'ptBR', 'Corrente do Gladiador Desacorrentado', 40944),
(2281, 'ptBR', 'Corrente do Gladiador Desacorrentado', 40944),
(2277, 'ptBR', 'Couros do Gladiador Desacorrentado', 40944),
(2275, 'ptBR', 'Couros do Gladiador Desacorrentado', 40944),
(2271, 'ptBR', 'Vestimenta do Gladiador Desacorrentado', 40944),
(2269, 'ptBR', 'Vestimenta do Gladiador Desacorrentado', 40944),
(2178, 'ptBR', 'Armas dos Mestres-das-suturas', 40944);

UPDATE `transmog_set_locale` SET `Name_lang`='Paramentos do Aspirante Perjuro', `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=2207 AND `locale`='ptBR');

UPDATE `transmog_set_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='ptBR' AND `ID` IN (2221,2220,2219,2218,2217,2216,2215,2214,2213,2212,2211,2210,2209,2208,2206,2205,2204,2203,2202));
DELETE FROM `achievement_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table_locale` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_blob` WHERE (`TableHash`=2948698321 AND `RecordId`=340 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='ptBR') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='ptBR') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='ptBR') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='ptBR') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='ptBR') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='ptBR') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='ptBR') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='ptBR') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='ptBR') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='ptBR') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='ptBR') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='ptBR') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='ptBR') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='ptBR') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='ptBR') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='ptBR') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=358927 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='ptBR') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='ptBR') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='ptBR') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='ptBR') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='ptBR') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='ptBR') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='ptBR') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='ptBR') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='ptBR') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='ptBR') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='ptBR') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='ptBR') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='ptBR') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='ptBR') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='ptBR') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='ptBR') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='ptBR') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='ptBR') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='ptBR') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='ptBR') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='ptBR') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='ptBR') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='ptBR') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='ptBR') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='ptBR') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='ptBR') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='ptBR') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='ptBR') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='ptBR') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='ptBR') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='ptBR') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='ptBR') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='ptBR') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='ptBR') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='ptBR') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='ptBR');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(2948698321, 340, 'ptBR', 0xA53E23C86B3D8F59, 40944),
(261693969, 65165, 'ptBR', 0xFFFFFFFFFFFFFFFF41706F696F20646120616C6D61000044AC546F010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000000000000, 40944),
(3776013982, 361952, 'ptBR', 0x0041646963696F6E612024733120646520C3A26E696D6120616F20736575207265736572766174C3B372696F20646520506163746F20617475616C2E0000, 40944),
(3776013982, 256817, 'ptBR', 0x0053657573206665697469C3A76F73206520686162696C6964616465732074C3AA6D206368616E636520646520636F6E6365646572202432353638313873312064652056656C6F6369646164652C2045766173C3A36F206520536F7276657220706F722024323536383138642E0D0A0D0A7C6346464646464646464772616E64657A6120646520416D616E275468756C7C720D0A5175616E646F20706F74656E6369616C697A61646F2070656C6F2050616E7465C3A36F2C20243F28613133373030357C613133373034377C613133373032387C61313337303237295B73756120466F72C3A7615D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295B737561204167696C69646164655D5B73657520496E74656C6563746F5D20C3A92061756D656E7461646F20656D2024323536383332733120706F722024323536383332642E0000, 40944),
(3776013982, 247692, 'ptBR', 0x00566F63C3AA2074656D206D616973206368616E6365206465206F6274657220756D61204361697861206465204C656D6272616EC3A761206461732041726569617320646F2054656D706F2E20417320436169786173206465204C656D6272616EC3A7617320636F6E74C3AA6D206974656E7320706F6465726F736F732071756520726564757A656D20636F6E73696465726176656C6D656E7465206F73206465736166696F7320646F2043726F6E6F706F7274616C2E0D0A0D0A7C63464630304646303042C3B46E75733A7C722056656C6F63696461646573206465206D6F76696D656E746F2065206465206D6F6E74617269612061756D656E746164617320656D20247332252E00566F63C3AA2074656D206D616973206368616E6365206465206F6274657220756D61204361697861206465204C656D6272616EC3A761206461732041726569617320646F2054656D706F2E20417320436169786173206465204C656D6272616EC3A7617320636F6E74C3AA6D206974656E7320706F6465726F736F732071756520726564757A656D20636F6E73696465726176656C6D656E7465206F73206465736166696F7320646F2043726F6E6F706F7274616C2E0D0A0D0A7C63464630304646303042C3B46E75733A7C722056656C6F63696461646573206465206D6F76696D656E746F2065206465206D6F6E74617269612061756D656E746164617320656D20247332252E00, 40944),
(3776013982, 247111, 'ptBR', 0x00566F63C3AA2074656D206D616973206368616E6365206465206F6274657220756D20447261636F2042726F6E7A65206461732041726569617320646F2054656D706F2E204F20647261636F20657376617A696120696E7374616E74616E65616D656E746520756D2073616E7475C3A172696F2064726167C3B46E69636F207061726120766F63C3AA2E0D0A0D0A7C63464630304646303042C3B46E75733A7C722044616E6F206520637572612061756D656E7461646F7320656D20247332252E00566F63C3AA2074656D206D616973206368616E6365206465206F6274657220756D20447261636F2042726F6E7A65206461732041726569617320646F2054656D706F2E204F20647261636F20657376617A696120696E7374616E74616E65616D656E746520756D2073616E7475C3A172696F2064726167C3B46E69636F207061726120766F63C3AA2E0D0A0D0A7C63464630304646303042C3B46E75733A7C722044616E6F206520637572612061756D656E7461646F7320656D20247332252E00, 40944),
(3776013982, 247110, 'ptBR', 0x00446573626C6F717565696120706F727461697320646F205265706F75736F20646173205365727065732070617261206361646120756D20646F732073616E7475C3A172696F732064726167C3B46E69636F732E0D0A0D0A7C63464630304646303042C3B46E75733A7C722056656C6F63696461646573206465206D6F76696D656E746F2065206465206D6F6E74617269612061756D656E746164617320656D20247332252E00446573626C6F717565696120706F727461697320646F205265706F75736F20646173205365727065732070617261206361646120756D20646F732073616E7475C3A172696F732064726167C3B46E69636F732E0D0A0D0A7C63464630304646303042C3B46E75733A7C722056656C6F63696461646573206465206D6F76696D656E746F2065206465206D6F6E74617269612061756D656E746164617320656D20247332252E00, 40944),
(3776013982, 247104, 'ptBR', 0x0056656C6F63696461646573206465206D6F76696D656E746F2065206465206D6F6E74617269612061756D656E746164617320656D20247331252E0D0A0D0A7C63464630304646303042C3B46E75733A7C722044616E6F206520637572612061756D656E7461646F7320656D20247332252E0056656C6F63696461646573206465206D6F76696D656E746F2065206465206D6F6E74617269612061756D656E746164617320656D20247331252E0D0A0D0A7C63464630304646303042C3B46E75733A7C722044616E6F206520637572612061756D656E7461646F7320656D20247332252E00, 40944),
(3776013982, 247103, 'ptBR', 0x0024407370656C6C646573633234343935390D0A0D0A7C63464630304646303042C3B46E75733A7C722044616E6F206520637572612061756D656E7461646F7320656D2035252E0000, 40944),
(3776013982, 247099, 'ptBR', 0x004120726570757461C3A7C3A36F20636F6D2043726F6E612071756520766F63C3AA2067616E686120706F72206D65696F2064652061626174657320C3A92061756D656E7461646120656D20243234373736397331252068C3A120243234373736396420646F2066696D206520656D20243234373737307331252068C3A120243234373737306420646F2066696D2E0D0A0D0A7C63464630304646303042C3B46E75733A7C722056656C6F63696461646573206465206D6F76696D656E746F2065206465206D6F6E74617269612061756D656E746164617320656D20247332252E0000, 40944),
(3776013982, 247096, 'ptBR', 0x000000, 40944),
(3776013982, 247094, 'ptBR', 0x0041756D656E746120656D2024733125206120737561206368616E636520646520656E636F6E747261722041726569617320646F2054656D706F2E0D0A0D0A7C63464630304646303042C3B46E75733A7C7220566964612061756D656E7461646120656D20247332252E0041756D656E746120656D2024733125206120737561206368616E636520646520656E636F6E747261722041726569617320646F2054656D706F2E0D0A0D0A7C63464630304646303042C3B46E75733A7C7220566964612061756D656E7461646120656D20247332252E00, 40944),
(3776013982, 247093, 'ptBR', 0x000000, 40944),
(3776013982, 247092, 'ptBR', 0x000000, 40944),
(3776013982, 247089, 'ptBR', 0x0024407370656C6C646573633234353530330D0A0D0A7C63464630304646303042C3B46E75733A7C722044616E6F2C20637572612C20706F6E746F7320646520766964612C2076656C6F63696461646573206465206D6F76696D656E746F2065206465206D6F6E74617269612061756D656E7461646F7320656D20247332252E0000, 40944),
(3776013982, 247088, 'ptBR', 0x0043726F6E6120726576656C61206261C3BA7320646F207465736F75726F207072C3B378696D6F732E0D0A0D0A7C63464630304646303042C3B46E75733A7C722044616E6F206520637572612061756D656E7461646F7320656D20247332252E0043726F6E6120726576656C61206261C3BA7320646F207465736F75726F207072C3B378696D6F732E0D0A0D0A7C63464630304646303042C3B46E75733A7C722044616E6F206520637572612061756D656E7461646F7320656D20247332252E00, 40944),
(3479059991, 9040, 'ptBR', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'ptBR', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'ptBR', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'ptBR', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'ptBR', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'ptBR', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'ptBR', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'ptBR', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'ptBR', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'ptBR', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'ptBR', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'ptBR', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'ptBR', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'ptBR', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'ptBR', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'ptBR', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'ptBR', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'ptBR', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'ptBR', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'ptBR', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'ptBR', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'ptBR', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'ptBR', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'ptBR', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'ptBR', 0x0024407370656C6C64657363323238383239002473312064652064616E6F20646520466F676F206361757361646F206120636164612024323238383239743120732E00, 40944),
(3776013982, 227799, 'ptBR', 0x004F6E64617320646520C3A16775612076617272656D206F732063616E746F732064612073616C612C2063617573616E646F202473312064652064616E6F2064652047656C6F20616F73206A6F6761646F7265732071756520636F6C69646972656D20636F6D20656C61732E0000, 40944),
(3776013982, 227780, 'ptBR', 0x004D6172636120746F646F73206F73206A6F6761646F72657320636F6D2024407370656C6C6E616D653232373738302E20416F20657870697261722C206361757361202473312064652064616E6F206465204E61747572657A61206120746F646F73206F73206F7574726F73206A6F6761646F726573206E756D207261696F20646520244131206D2E00416F20657870697261722C206361757361202473312064652064616E6F206465204E61747572657A61206120746F646F73206F73206A6F6761646F726573206E756D207261696F20646520244131206D2E00, 40944),
(3386291891, 116804, 'ptBR', 0x41746F722064612043656E6100000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'ptBR', 0x41727175696D61676F2048616467676172000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'ptBR', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'ptBR', 0x4E69656C6173204172616E0000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'ptBR', 0x4D65646976680000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'ptBR', 0x4F2043757261646F72000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'ptBR', 0x0041627261207375612070C3A167696E6120646520436F6D70616E686569726F7320652061756D656E7465206F206EC3AD76656C20646520756D2064656C65732070617261202473312E0000, 40944),
(261693969, 60399, 'ptBR', 0xFFFFFFFFFFFFFFFF416A756461206120526576656E647265746800003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'ptBR', 0xFFFFFFFFFFFFFFFF416A7564612061204D616C6472617878757300003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'ptBR', 0xFFFFFFFFFFFFFFFF416A75646120616F204261737469C3A36F00003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'ptBR', 0xFFFFFFFFFFFFFFFF416A756461206120417264656E6100003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'ptBR', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'ptBR', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'ptBR', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'ptBR', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'ptBR', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'ptBR', 0x00000000, 40944),
(3865974254, 176921, 'ptBR', 0x00000000, 40944),
(3865974254, 176832, 'ptBR', 0x00000000, 40944),
(3776013982, 243328, 'ptBR', 0x00004EC3AD76656C20646520616D6561C3A76120726564757A69646F2E00, 40944),
(3865974254, 187935, 'ptBR', 0x00000000, 40944),
(3205218938, 44300, 'ptBR', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F580056696E63756C65206F20417574656E74696361646F722065206F20416C6572746120534D5320C3A02073756120636F6E7461207061726120646573626C6F717565617220657374652063616D706F0001, 40944),
(3205218938, 44299, 'ptBR', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C636666666630303030566F63C3AA2073C3B320706F6465207075626C6963617220756D20677275706F206465204DC3AD746963612B2073656D20756D612050656472612D6368617665207175616E646F2070726F74656765722073756120636F6E746120636F6D206F20417574656E74696361646F7220426174746C652E6E65742065206F20416C6572746120534D537C727C6E7C6366663165666630303C436C69636B20666F72206D6F726520696E666F3E7C720001, 40944),
(3205218938, 44284, 'ptBR', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C636666666630303030566F63C3AA2073C3B320706F64652065646974617220657374652063616D706F207175616E646F2070726F74656765722073756120636F6E746120636F6D206F20417574656E74696361646F7220426174746C652E6E65742065206F20416C6572746120534D537C727C6E7C6366663165666630303C436C69636B20666F72206D6F726520696E666F3E7C720001, 40944),
(3205218938, 44283, 'ptBR', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F444553430047616E68652061636573736F20746F74616C20616F206C6F63616C697A61646F7220646520677275706F732076696E63756C616E646F206F20417574656E74696361646F722065206F20416C6572746120534D5320C3A02073756120636F6E74612E7C6E7C6E4F20417574656E74696361646F7220426174746C652E6E657420C3A920756D207365727669C3A76F2073696D706C6573206520677261747569746F207175652070726F7465676520612073756120636F6E746120636F6E74726120696E766173C3B565732C2065206F20416C6572746120534D5320656E76696120756D61206E6F746966696361C3A7C3A36F2061206361646120616C74657261C3A7C3A36F207369676E69666963617469766120666569746120C3A020636F6E74612E7C6E7C6E436C6971756520656D2022417469766172222070617261206162726972206F207369746520646520696E7374616C61C3A7C3A36F20646F20417574656E74696361646F722E0001, 40944),
(3776013982, 358927, 'ptBR', 0x00446573636F6E666961206465207175656D20657374C3A120616F20736575207265646F722E205265636172676120726564757A69646120706172612046696C686F73206461204E6F6974652E00446573636F6E6669616E646F206465207175656D20657374C3A120616F20736575207265646F722E00, 40944),
(3865974254, 188152, 'ptBR', 0x00000000, 40944),
(3776013982, 53385, 'ptBR', 0x004C696265726120756D20726564656D6F696E686F20646520656E657267696120646976696E6120717565206361757361202473312064652064616E6F205361677261646F206120746F646F73206F7320696E696D69676F73207072C3B378696D6F732E2044616E6F20726564757A69646F206163696D612064652024733220616C766F732E0000, 40944),
(261693969, 62694, 'ptBR', 0xFFFFFFFFFFFFFFFF4368616D61646F20656D204D616C64726178787573000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'ptBR', 0xFFFFFFFFFFFFFFFF4368616D61646F20656D20417264656E61000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'ptBR', 0xFFFFFFFFFFFFFFFF4368616D61646F206E6F204261737469C3A36F000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'ptBR', 0xFFFFFFFFFFFFFFFF4368616D61646F20656D20526576656E6472657468000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'ptBR', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'ptBR', 0x000000, 40944),
(3776013982, 307934, 'ptBR', 0x000000, 40944),
(3776013982, 307480, 'ptBR', 0x00417272656D6573736120736575204472616761646F7220416D61647572656369646F2E0000, 40944),
(2948698321, 354, 'ptBR', 0x64DF8D9146629CB2, 40944),
(261693969, 60111, 'ptBR', 0xFFFFFFFFFFFFFFFF436F6D6F20666F726A617220756D6120616D697A61646500005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'ptBR', 0xFFFFFFFFFFFFFFFF416D69676F20636572746F206E617320686F72617320696E63657274617300005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'ptBR', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'ptBR', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'ptBR', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'ptBR', 0x00000000, 40944),
(3865974254, 151804, 'ptBR', 0x00000000, 40944),
(3865974254, 151792, 'ptBR', 0x00000000, 40944),
(3037505077, 151792, 'ptBR', 0x0100, 40944),
(3865974254, 151790, 'ptBR', 0x00000000, 40944),
(3037505077, 151790, 'ptBR', 0x0100, 40944),
(3865974254, 146306, 'ptBR', 0x00000000, 40944),
(3865974254, 34685, 'ptBR', 0x00000000, 40944),
(3865974254, 34683, 'ptBR', 0x00000000, 40944),
(3865974254, 34087, 'ptBR', 0x00000000, 40944),
(3865974254, 34085, 'ptBR', 0x00000000, 40944),
(3865974254, 33969, 'ptBR', 0x00000000, 40944),
(3865974254, 33968, 'ptBR', 0x00000000, 40944),
(3865974254, 33967, 'ptBR', 0x00000000, 40944),
(3865974254, 33966, 'ptBR', 0x00000000, 40944),
(3865974254, 33868, 'ptBR', 0x00000000, 40944),
(3865974254, 33864, 'ptBR', 0x00000000, 40944),
(3865974254, 33863, 'ptBR', 0x00000000, 40944),
(3865974254, 33862, 'ptBR', 0x00000000, 40944),
(3865974254, 23324, 'ptBR', 0x00000000, 40944),
(3865974254, 21525, 'ptBR', 0x00000000, 40944),
(3865974254, 21524, 'ptBR', 0x00000000, 40944),
(3865974254, 19028, 'ptBR', 0x00000000, 40944),
(3865974254, 6835, 'ptBR', 0x00000000, 40944),
(3865974254, 6833, 'ptBR', 0x00000000, 40944),
(3865974254, 181321, 'ptBR', 0x00000000, 40944),
(1548466975, 27672, 'ptBR', 0x10040000, 40944),
(3776013982, 365080, 'ptBR', 0x000056656C6F636964616465206465206D6F76696D656E746F2061756D656E7461646120656D20247331252E00, 40944),
(3776013982, 317920, 'ptBR', 0x0045666569746F732064652053696CC3AA6E63696F206520496E746572727570C3A7C3A36F20656D206D656D62726F7320646F207261696465206520646F20677275706F20656D20756D207261696F20646520246131206D2073C3A36F2024733125206D61697320637572746F732E20243F733333393132345B4F732065666569746F73206465206D65646F2074616D62C3A96D2073C3A36F20726564757A69646F732E5D5B5D0045666569746F732064652073696CC3AA6E63696F206520696E746572727570C3A7C3A36F20726564757A69646F7320656D20247731252E20243F733333393132345B45666569746F73206465206D65646F20726564757A69646F7320656D20247734252E5D5B5D00, 40944),
(3776013982, 465, 'ptBR', 0x004D656D62726F7320646F20677275706F206520646F20726169646520656D20756D207261696F20646520246131206D2073C3A36F20666F7274616C656369646F732070656C61206465766FC3A7C3A36F2C206F2071756520726564757A20656D2024733125206F2064616E6F20726563656269646F2E0044616E6F20726563656269646F20726564757A69646F20656D20247731252E00, 40944),
(3205218938, 44172, 'ptBR', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F44455343004F6274656E68612070656C6F206D656E6F7320313935302064652072616E71756520706172612067616E6861723A7C6E2D2052616E71756520646520417072696D6F72616D656E746F206465204974656E73204A784A0001, 40944),
(3205218938, 40887, 'ptBR', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F44455343004F6274656E68612070656C6F206D656E6F7320313830302064652072616E71756520706172612067616E6861723A7C6E2D2054C3AD74756C6F20646520526976616C7C6E2D2041706172C3AA6E63696120646F20436F6E6A756E746F206465204974656E73204A784A20646520456C6974653A20456C6D6F7C6E2D2041706172C3AA6E63696120646F20436F6E6A756E746F206465204974656E73204A784A20646520456C6974653A204F6D62726F730001, 40944),
(3205218938, 40885, 'ptBR', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F44455343004F6274656E68612070656C6F206D656E6F7320313430302064652072616E71756520706172612067616E6861723A7C6E2D2054C3AD74756C6F20646520446573616669616E74657C6E2D2041706172C3AA6E63696120646F20436F6E6A756E746F206465204974656E73204A784A20646520456C6974653A204C757661737C6E2D2041706172C3AA6E63696120646F20436F6E6A756E746F206465204974656E73204A784A20646520456C6974653A20426F7461730001, 40944),
(3776013982, 357407, 'ptBR', 0x0045766F6361206520636F6E74726F6C61206F20526F7175656E726F75205261636572204573706F6C6961646F722E0055736520612062617272612064652061C3A7C3B56573207061726120617461636172206F7574726F73206272696E717565646F7320646520636F6E74726F6C652072656D6F746F2E00, 40944),
(3776013982, 357406, 'ptBR', 0x0045766F6361206520636F6E74726F6C61206F20526F7175656E726F75205261636572204573706F6C6961646F722E0055736520612062617272612064652061C3A7C3B56573207061726120617461636172206F7574726F73206272696E717565646F7320646520636F6E74726F6C652072656D6F746F2E00, 40944),
(3776013982, 357405, 'ptBR', 0x0045766F6361206520636F6E74726F6C61206F20526F7175656E726F75205261636572204573706F6C6961646F722E0055736520612062617272612064652061C3A7C3B56573207061726120617461636172206F7574726F73206272696E717565646F7320646520636F6E74726F6C652072656D6F746F2E00, 40944),
(3776013982, 356631, 'ptBR', 0x0045766F6361206520636F6E74726F6C61206F20526F7175656E726F75205261636572204C616D696E61C3A97265612E0055736520612062617272612064652061C3A7C3B56573207061726120617461636172206F7574726F73206272696E717565646F7320646520636F6E74726F6C652072656D6F746F2E00, 40944),
(3776013982, 328923, 'ptBR', 0x4665C3A972696F73204E6F7475726E6F73005472616E7366657265206120666F72C3A76120766974616C206465206174C3A920243332383932384920696E696D69676F73206E6120C3A17265612073656C6563696F6E6164612C2063617573616E646F20247B282433323839323873312A24642F24743229202B202433323839323873317D2064652064616E6F206465204E61747572657A6120646976696469646F20656E74726520746F646F73206F7320616C766F7320696E696D69676F7320616F206C6F6E676F2064652024642E20243F613133373034315B0D0A0D0A43616E616C697A617220746F74616C6D656E74652061205472616E73667573C3A36F204665C3A972696120676572612024733420244C61706C696361C3A7C3A36F3A61706C696361C3A7C3B565733B2064652041726D6120646120566F726167656D2E5D5B5D0D0A0D0A4174697661722061205472616E73667573C3A36F204665C3A9726961206E6F76616D656E746520656D206174C3A9202433323839333364206C6962657261202473312520646520746F646F206F2064616E6F2064656C612C20637572616E646F206174C3A92024333238393330733220616C6961646F7320656D20756D207261696F20646520243332383933304131206D2E0000, 40944),
(3776013982, 101546, 'ptBR', 0x0044C3A120756D206368757465206769726174C3B372696F206E6F2061722C2063617573616E646F20243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5D2064652064616E6F2046C3AD7369636F20616F206C6F6E676F206465202464206120746F646F73206F7320696E696D69676F7320656D20756D207261696F20646520243130373237304131206D2E2044616E6F20726564757A69646F206163696D612064652024733120616C766F732E243F63335B0D0A0D0A4F2064616E6F20646F204368757465204769726174C3B372696F20646120476172C3A76120C3A92061756D656E7461646F20656D20243232303335387331252070617261206361646120616C766F20C3BA6E69636F2071756520766F63C3AA207469766572206174696E6769646F206E6F7320C3BA6C74696D6F7320243232303335386420636F6D2050616C6D6120646F2054696772652C20436875746520426C656361757465206F7520436875746520646F20536F6C204E617363656E74652E204163756D756C61206174C3A92024323238323837692076657A65732E5D5B5D0041746163616E646F20696E696D69676F73207072C3B378696D6F732C2063617573616E646F2064616E6F2046C3AD7369636F206120636164612024313031353436743120732E00, 40944),
(3865974254, 188220, 'ptBR', 0x00000000, 40944),
(3865974254, 187900, 'ptBR', 0x00000000, 40944),
(3865974254, 187899, 'ptBR', 0x00000000, 40944),
(3865974254, 187898, 'ptBR', 0x00000000, 40944),
(3865974254, 187897, 'ptBR', 0x00000000, 40944),
(3865974254, 187896, 'ptBR', 0x00000000, 40944),
(3865974254, 187895, 'ptBR', 0x00000000, 40944),
(3865974254, 187875, 'ptBR', 0x00000000, 40944),
(3865974254, 187869, 'ptBR', 0x00000000, 40944),
(3865974254, 150746, 'ptBR', 0x00000000, 40944),
(3865974254, 150745, 'ptBR', 0x00000000, 40944),
(3865974254, 150744, 'ptBR', 0x00000000, 40944),
(3865974254, 150743, 'ptBR', 0x00000000, 40944),
(3776013982, 364944, 'ptBR', 0x000056656C6F636964616465206465206D6F76696D656E746F2061756D656E7461646120656D20247331252E00, 40944),
(3776013982, 228462, 'ptBR', 0x0041756D656E746120656D20247331206F2064616E6F20646F2073657520617461717565206175746F6DC3A17469636F2E0000, 40944),
(3776013982, 119611, 'ptBR', 0x0024407370656C6C646573633131353135310052657374617572612024773120706F6E746F732064652076696461206120636164612024743120732E00, 40944),
(3776013982, 119607, 'ptBR', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'ptBR', 0x00000000, 40944),
(1181150530, 403396, 'ptBR', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'ptBR', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'ptBR', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'ptBR', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'ptBR', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'ptBR', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'ptBR', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'ptBR', 0xA4530000, 40944),
(3359787322, 21411, 'ptBR', 0xA3530000, 40944),
(3359787322, 21410, 'ptBR', 0xA2530000, 40944),
(3359787322, 21409, 'ptBR', 0xA1530000, 40944),
(3359787322, 21408, 'ptBR', 0xA0530000, 40944),
(3359787322, 21407, 'ptBR', 0x9F530000, 40944),
(3359787322, 21406, 'ptBR', 0x9E530000, 40944),
(2557447376, 655518, 'ptBR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'ptBR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'ptBR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'ptBR', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'ptBR', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'ptBR', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F4546464543540041732072656772617320646520736171756520616E7469676173206EC3A36F2076616C656D206D6169732E0001, 40944),
(3776013982, 347944, 'ptBR', 0x004368616E63652064652061636572746F206372C3AD7469636F2061756D656E7461646120656D20247331252E0D0A004368616E63652064652061636572746F206372C3AD7469636F2061756D656E7461646120656D20247331252E00, 40944),
(3776013982, 347943, 'ptBR', 0x004DC3A178696D6F20646520706F6E746F7320646520766964612061756D656E7461646F20656D20247331252E0D0A004DC3A178696D6F20646520706F6E746F7320646520766964612061756D656E7461646F20656D20247331252E00, 40944),
(3776013982, 1714, 'ptBR', 0x00466F72C3A761206F20616C766F20612066616C617220656D2064656D6F6EC3AD61636F2C2061756D656E74616E646F20656D2024733125206F2074656D706F206465206C616EC3A7616D656E746F20646F73206665697469C3A76F7320706F722024642E243F733130333131325B0D0A0D0A7C434646453535424230517565696D616475726120416EC3AD6D6963613A20737561204D616C6469C3A7C3A36F206465204CC3AD6E6775617320616665746172C3A120746F646F73206F7320696E696D69676F7320656D20756D207261696F206465202431303432323441206D20616F207265646F7220646F2073657520616C766F2E7C525D5B5D0D0A0D0A7C6346463832383246464D616C6469C3A7C3B565733A20756D20627275786F2073C3B320706F64652074657220756D61206D616C6469C3A7C3A36F20617469766120706F7220616C766F2E7C720046616C617220656D2044656D6F6EC3AA732061756D656E746120656D2024773125206F2074656D706F206465206C616EC3A7616D656E746F206465206665697469C3A76F732E00, 40944),
(3205218938, 41865, 'ptBR', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E5300566F63C3AA206EC3A36F2074656D207065726D697373C3A36F207061726120656469746172206120696E666F726D61C3A7C3A36F20646520726563727574616D656E746F2E0001, 40944),
(261693969, 64850, 'ptBR', 0xFFFFFFFFFFFFFFFF547261766573736961206461205468616E61746F72000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'ptBR', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='ptBR') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='ptBR');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'ptBR' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `achievement_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (14775,14752,14682,14351));
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14775, 'ruRU', 'Добейтесь превознесения Чесночника.', 'Дружба с грибами', 'Наградное звание: смешной парень / смешная девчонка', 40944),
(14752, 'ruRU', 'Заработайте перечисленные ниже достижения, связанные со сшиванием поганищ.', 'Чем заняться после смерти', 'Наградное звание \"Мастер поганищ\" и награда – бронированный таурал дома Избранных', 40944),
(14682, 'ruRU', 'Заработайте перечисленные ниже достижения Пепельного двора.', 'Глашатай вечеринки', 'Наградное звание: Глашатай вечеринки', 40944),
(14351, 'ruRU', 'Победите 39 боссов на Пути Перерождения.', 'На Пути Перерождения 39', 'Откройте дополнительные испытания на Пути Перерождения.', 40944);


DELETE FROM `area_table_locale` WHERE (`VerifiedBuild`>0 AND `ID`=13316 AND `locale`='ruRU');
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(13316, 'ruRU', 'Дом Ритуалов', 40944);


DELETE FROM `battle_pet_species_locale` WHERE (`VerifiedBuild`>0 AND `ID`=3188 AND `locale`='ruRU');
INSERT INTO `battle_pet_species_locale` (`ID`, `locale`, `Description_lang`, `SourceText_lang`, `VerifiedBuild`) VALUES
(3188, 'ruRU', '', '', 40944);


DELETE FROM `broadcast_text_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (215513,215512,215511));
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(215513, 'ruRU', '', 'Не стоит соваться в Утробу бездумно. Возвращайся ко мне, как подготовишься.', 40944),
(215512, 'ruRU', 'Не стоит соваться в Утробу бездумно. Возвращайся ко мне, как подготовишься.', '', 40944),
(215511, 'ruRU', '', 'Мы близки к цели. Мы прорвемся, если будем сражаться вместе.', 40944);


DELETE FROM `char_titles_locale` WHERE (`VerifiedBuild`>0 AND `ID`=693 AND `locale`='ruRU');
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(693, 'ruRU', '%s Перерожденный', '%s Перерожденная', 40944);


UPDATE `char_titles_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=683 AND `locale`='ruRU');
DELETE FROM `chr_customization_option_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (1523,689));
INSERT INTO `chr_customization_option_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1523, 'ruRU', 'Хвост', 40944),
(689, 'ruRU', 'Хвост', 40944);


DELETE FROM `criteria_tree_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (91730,94390,94389,94388,93811,93810,94331,94330));
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91730, 'ruRU', '9.1 мета-достижение', 40944),
(94390, 'ruRU', '', 40944),
(94389, 'ruRU', '', 40944),
(94388, 'ruRU', '', 40944),
(93811, 'ruRU', '', 40944),
(93810, 'ruRU', 'Получите 80-й уровень известности', 40944),
(94331, 'ruRU', '', 40944),
(94330, 'ruRU', 'Renown Level 80 - Kyrian', 40944);


DELETE FROM `item_search_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,116401));
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(151806, 'ruRU', 'Элегантное платье', 40944),
(151804, 'ruRU', 'Черные брюки под смокинг', 40944),
(151792, 'ruRU', 'Зеленые зимние одежды', 40944),
(151790, 'ruRU', 'Красные зимние одежды', 40944),
(34685, 'ruRU', 'Одеяния лета', 40944),
(34683, 'ruRU', 'Сандалии лета', 40944),
(34087, 'ruRU', 'Зеленые зимние одежды', 40944),
(34085, 'ruRU', 'Красные зимние одежды', 40944),
(33969, 'ruRU', 'Лиловая шляпа Хмельного фестиваля', 40944),
(33968, 'ruRU', 'Синяя шляпа Хмельного фестиваля', 40944),
(33967, 'ruRU', 'Зеленая шляпа Хмельного фестиваля', 40944),
(33966, 'ruRU', 'Туфли Хмельного фестиваля', 40944),
(33868, 'ruRU', 'Сапоги Хмельного фестиваля', 40944),
(33864, 'ruRU', 'Коричневая шляпа Хмельного фестиваля', 40944),
(33863, 'ruRU', 'Платье Хмельного фестиваля', 40944),
(33862, 'ruRU', 'Регалии Хмельного фестиваля', 40944),
(23324, 'ruRU', 'Оплечье Огненного Солнцеворота', 40944),
(21525, 'ruRU', 'Зеленый новогодний колпак', 40944),
(21524, 'ruRU', 'Красный новогодний колпак', 40944),
(19028, 'ruRU', 'Элегантное платье', 40944),
(6835, 'ruRU', 'Черные брюки под смокинг', 40944),
(6833, 'ruRU', 'Белая рубашка под смокинг', 40944),
(181321, 'ruRU', 'Инкрустированный самоцветами жезл', 40944),
(116401, 'ruRU', 'Отличная шляпа странника', 40944);


DELETE FROM `item_sparse_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (176922,176921,176832,187935,188152,151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,188220,187900,187899,187898,187897,187896,187895,187875,187869,150746,150745,150744,150743,116401));
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(176922, 'ruRU', 'Этот магический цветок на 100% увеличивает количество материалов, которые дух предложит вам после перерождения, и количество катализаторов, вырастающих из семян.', '', '', '', 'Дикий ночноцвет', 40944),
(176921, 'ruRU', 'Эти зачарованные листья ускоряют процесс инкубации в диком семени восстановления на 1 день.', '', '', '', 'Хронолист', 40944),
(176832, 'ruRU', 'Особый корень, повышающий качество наград, которые дух предложит вам после перерождения.', '', '', '', 'Зерно дикого корня', 40944),
(187935, 'ruRU', 'Обучает изготовлению метки полуночного рунического оленя.', '', '', '', 'Техника: метка полуночного рунического оленя', 40944),
(188152, 'ruRU', 'Осколок заряжен магической энергией, обжигающей при прикосновении.', '', '', '', 'Осколок управления вратами', 40944),
(151806, 'ruRU', '', '', '', '', 'Элегантное платье', 40944),
(151804, 'ruRU', '', '', '', '', 'Черные брюки под смокинг', 40944),
(151792, 'ruRU', '', '', '', '', 'Зеленые зимние одежды', 40944),
(151790, 'ruRU', '', '', '', '', 'Красные зимние одежды', 40944),
(34685, 'ruRU', '', '', '', '', 'Одеяния лета', 40944),
(34683, 'ruRU', '', '', '', '', 'Сандалии лета', 40944),
(34087, 'ruRU', '', '', '', '', 'Зеленые зимние одежды', 40944),
(34085, 'ruRU', '', '', '', '', 'Красные зимние одежды', 40944),
(33969, 'ruRU', '', '', '', '', 'Лиловая шляпа Хмельного фестиваля', 40944),
(33968, 'ruRU', '', '', '', '', 'Синяя шляпа Хмельного фестиваля', 40944),
(33967, 'ruRU', '', '', '', '', 'Зеленая шляпа Хмельного фестиваля', 40944),
(33966, 'ruRU', '', '', '', '', 'Туфли Хмельного фестиваля', 40944),
(33868, 'ruRU', '', '', '', '', 'Сапоги Хмельного фестиваля', 40944),
(33864, 'ruRU', '', '', '', '', 'Коричневая шляпа Хмельного фестиваля', 40944),
(33863, 'ruRU', '', '', '', '', 'Платье Хмельного фестиваля', 40944),
(33862, 'ruRU', '', '', '', '', 'Регалии Хмельного фестиваля', 40944),
(23324, 'ruRU', '', '', '', '', 'Оплечье Огненного Солнцеворота', 40944),
(21525, 'ruRU', '', '', '', '', 'Зеленый новогодний колпак', 40944),
(21524, 'ruRU', '', '', '', '', 'Красный новогодний колпак', 40944),
(19028, 'ruRU', '', '', '', '', 'Элегантное платье', 40944),
(6835, 'ruRU', '', '', '', '', 'Черные брюки под смокинг', 40944),
(6833, 'ruRU', '', '', '', '', 'Белая рубашка под смокинг', 40944),
(181321, 'ruRU', '', '', '', '', 'Инкрустированный самоцветами жезл', 40944),
(188220, 'ruRU', 'Внизу выведена надпись: \"Покоритель Башни\".', '', '', '', 'Сфера с прахом из Торгаста', 40944),
(187900, 'ruRU', 'Описание различных находок, сделанных гоблином и гномом на двух островах.', '', '', '', 'Тактическая карта: чудеса Кул-Тираса и Зандалара', 40944),
(187899, 'ruRU', 'Описание различных экосистем и невероятной флоры Запределья, сделанное отважным алхимиком.', '', '', '', 'Тактическая карта: удивительное Запределье', 40944),
(187898, 'ruRU', 'Доклад рыцаря Серебряного Авангарда, в котором подробно описаны военные действия против Короля-лича.', '', '', '', 'Тактическая карта: Настоящая цена нордскольской кампании', 40944),
(187897, 'ruRU', 'Уникальный доклад обеих фракций, описывающий многочисленные последствия Раскола Азерота, вызванного Смертокрылом.', '', '', '', 'Тактическая карта: последствия Катаклизма', 40944),
(187896, 'ruRU', 'Веселая история о недавних приключениях Ли Ли в Пандарии, сопровожденная гастрономическими советами ее дядюшки Чэня.', '', '', '', 'Тактическая карта: путеводитель Буйного Портера по Пандарии', 40944),
(187895, 'ruRU', 'Краткий список безопасных мест Дренора с местными обычаями, которые стоит соблюдать в каждом из них.', '', '', '', 'Тактическая карта: опасности Дренора', 40944),
(187875, 'ruRU', 'Большая подборка докладов и сообщений разрозненных боевых отрядов, сражающихся с Легионом.', '', '', '', 'Тактическая карта: объединенные фронты Расколотых островов', 40944),
(187869, 'ruRU', 'Подробная повесть о приключениях одного пилигрима Утробы в четырех царствах Темных Земель.', '', '', '', 'Тактическая карта: в Темные Земли', 40944),
(150746, 'ruRU', 'Скромное предложение, позволяющее обеспечить эффективное и своевременное снабжение аванпостов Восточных королевств.', '', '', '', 'Тактическая карта: снабжение Восточных королевств', 40944),
(150745, 'ruRU', 'Подробная стратегия по быстрому уничтожению сил Восточных королевств Альянса в случае начала Четвертой войны.', '', '', '', 'Тактическая карта: кампания Восточных королевств', 40944),
(150744, 'ruRU', 'Мать-земля все еще залечивает раны, оставленные на ней злом, заражением и порчей.', '', '', '', 'Тактическая карта: прогулки по Калимдору с Матерью-землей', 40944),
(150743, 'ruRU', 'Клыкастые, когтистые, ядовитые и верные Орде твари, а также места их обитания.', '', '', '', 'Тактическая карта: выживание на Калимдоре', 40944),
(116401, 'ruRU', '', '', '', '', 'Отличная шляпа странника', 40944);


UPDATE `item_sparse_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (185950,185947,185946));
DELETE FROM `lfg_dungeons_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1445 AND `locale`='ruRU');
INSERT INTO `lfg_dungeons_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1445, 'ruRU', 'Падение Тотема Скверны', 'Не дайте Тугару Кровавому Тотему и его червям Скверны разрушить гору.', 40944);


DELETE FROM `map_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1756 AND `locale`='ruRU');
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(1756, 'ruRU', 'Смерти Хроми', '', '', '', '', 40944);


DELETE FROM `player_condition_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (95078,95077,95076,85644,73006,73005,87365,85912,85910,85909,85692,94517,94516,94515,94514,94513,94512,94511));
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(95078, 'ruRU', '', 40944),
(95077, 'ruRU', '', 40944),
(95076, 'ruRU', '', 40944),
(85644, 'ruRU', 'Требуется $pcMinLevel-й уровень.', 40944),
(73006, 'ruRU', '', 40944),
(73005, 'ruRU', '', 40944),
(87365, 'ruRU', '', 40944),
(85912, 'ruRU', '', 40944),
(85910, 'ruRU', '', 40944),
(85909, 'ruRU', '', 40944),
(85692, 'ruRU', '', 40944),
(94517, 'ruRU', '', 40944),
(94516, 'ruRU', '', 40944),
(94515, 'ruRU', '', 40944),
(94514, 'ruRU', '', 40944),
(94513, 'ruRU', '', 40944),
(94512, 'ruRU', '', 40944),
(94511, 'ruRU', '', 40944);


DELETE FROM `spell_category_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1186 AND `locale`='ruRU');
INSERT INTO `spell_category_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1186, 'ruRU', 'Class - Paladin - Hand of Sacrifice', 40944);


DELETE FROM `spell_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (361952,256817,247692,247111,247110,247104,247103,247099,247096,247094,247093,247092,247089,247088,228844,227799,227780,362986,243328,358927,53385,329902,307934,307480,365080,317920,465,357407,357406,357405,356631,328923,101546,364944,228462,119611,119607,347944,347943,1714));
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(361952, 'ruRU', '1000 ед. анимы', 40944),
(256817, 'ruRU', 'Знак Аман\'тула', 40944),
(247692, 'ruRU', 'Несчетные сундуки', 40944),
(247111, 'ruRU', 'Blessing of the Bronze Dragonflight Passive', 40944),
(247110, 'ruRU', 'Беспредельная скорость', 40944),
(247104, 'ruRU', 'Acceleration Passive', 40944),
(247103, 'ruRU', 'Time Stop Passive', 40944),
(247099, 'ruRU', 'Chrono Charisma Passive', 40944),
(247096, 'ruRU', 'Rapid Recovery Passive', 40944),
(247094, 'ruRU', 'Удачливость', 40944),
(247093, 'ruRU', 'Dragon\'s Determination Passive', 40944),
(247092, 'ruRU', 'Accelerated Aggression Passive', 40944),
(247089, 'ruRU', 'Dragon Crash Passive', 40944),
(247088, 'ruRU', 'Проницательность', 40944),
(228844, 'ruRU', 'Горящие кости', 40944),
(227799, 'ruRU', 'Ураганная волна', 40944),
(227780, 'ruRU', 'Ритуал грома', 40944),
(362986, 'ruRU', 'Опыт', 40944),
(243328, 'ruRU', 'Уход в тень', 40944),
(358927, 'ruRU', 'Бдительность стража ночнорожденных', 40944),
(53385, 'ruRU', 'Божественная буря', 40944),
(329902, 'ruRU', 'Вытаскивание', 40944),
(307934, 'ruRU', 'Вытаскивание', 40944),
(307480, 'ruRU', 'Бросок землероя', 40944),
(365080, 'ruRU', 'Стремительность', 40944),
(317920, 'ruRU', 'Аура сосредоточенности', 40944),
(465, 'ruRU', 'Аура благочестия', 40944),
(357407, 'ruRU', 'Призыв Ховеркара', 40944),
(357406, 'ruRU', 'Призыв Гусеничного танка', 40944),
(357405, 'ruRU', 'Призыв Пустынного дьявола', 40944),
(356631, 'ruRU', 'Призыв Ветрореза', 40944),
(328923, 'ruRU', 'Волшебное переливание', 40944),
(101546, 'ruRU', 'Танцующий журавль', 40944),
(364944, 'ruRU', 'Стремительность', 40944),
(228462, 'ruRU', 'Знак Меландра', 40944),
(119611, 'ruRU', 'Заживляющий туман', 40944),
(119607, 'ruRU', 'Заживляющий туман', 40944),
(347944, 'ruRU', 'Облероновые шипы', 40944),
(347943, 'ruRU', 'Облероновая выносливость', 40944),
(1714, 'ruRU', 'Проклятие косноязычия', 40944);


DELETE FROM `transmog_set_locale` WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (2289,2287,2283,2281,2277,2275,2271,2269,2178));
INSERT INTO `transmog_set_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(2289, 'ruRU', 'Латы освобожденного гладиатора', 40944),
(2287, 'ruRU', 'Латы освобожденного гладиатора', 40944),
(2283, 'ruRU', 'Кольчужный доспех освобожденного гладиатора', 40944),
(2281, 'ruRU', 'Кольчужный доспех освобожденного гладиатора', 40944),
(2277, 'ruRU', 'Кожаный доспех освобожденного гладиатора', 40944),
(2275, 'ruRU', 'Кожаный доспех освобожденного гладиатора', 40944),
(2271, 'ruRU', 'Облачение освобожденного гладиатора', 40944),
(2269, 'ruRU', 'Облачение освобожденного гладиатора', 40944),
(2178, 'ruRU', 'Оружие Штопальщиков', 40944);


UPDATE `transmog_set_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='ruRU' AND `ID` IN (2221,2220,2219,2218,2217,2216,2215,2214,2213,2212,2211,2210,2209,2208,2207,2206,2205,2204,2203,2202));
DELETE FROM `achievement_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table_locale` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_blob` WHERE (`TableHash`=2948698321 AND `RecordId`=340 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='ruRU') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='ruRU') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='ruRU') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='ruRU') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='ruRU') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='ruRU') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='ruRU') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='ruRU') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='ruRU') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='ruRU') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='ruRU') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='ruRU') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='ruRU') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='ruRU') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='ruRU') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='ruRU') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=358927 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='ruRU') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='ruRU') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='ruRU') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='ruRU') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='ruRU') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='ruRU') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='ruRU') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='ruRU') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='ruRU') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='ruRU') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='ruRU') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='ruRU') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='ruRU') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='ruRU') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='ruRU') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='ruRU') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='ruRU') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='ruRU') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='ruRU') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='ruRU') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='ruRU') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='ruRU') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='ruRU') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='ruRU') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='ruRU') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='ruRU') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='ruRU') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='ruRU') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='ruRU') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='ruRU') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='ruRU') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='ruRU') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='ruRU') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='ruRU') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='ruRU') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='ruRU');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(2948698321, 340, 'ruRU', 0xA53E23C86B3D8F59, 40944),
(261693969, 65165, 'ruRU', 0xFFFFFFFFFFFFFFFFD09FD0BED0BCD0BED189D18C20D0B4D183D188D0B8000044AC546F010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000000000000, 40944),
(3776013982, 361952, 'ruRU', 0x00D092D0BDD0B5D181D182D0B82024733120D0B5D0B42E20D0B0D0BDD0B8D0BCD18B20D0B220D180D0B5D0B7D0B5D180D0B2D183D0B0D18020D0B2D0B0D188D0B5D0B3D0BE20D182D0B5D0BAD183D189D0B5D0B3D0BE20D0BAD0BED0B2D0B5D0BDD0B0D0BDD182D0B02E0000, 40944),
(3776013982, 256817, 'ruRU', 0x00D097D0B0D0BAD0BBD0B8D0BDD0B0D0BDD0B8D18F20D0B820D181D0BFD0BED181D0BED0B1D0BDD0BED181D182D0B820D0BCD0BED0B3D183D18220D0BFD0BED0B2D18BD181D0B8D182D18C20D181D0BAD0BED180D0BED181D182D18C2C20D0B2D0B5D180D0BED18FD182D0BDD0BED181D182D18C20D183D0BAD0BBD0BED0BDD0B5D0BDD0B8D18F20D0B820D18DD184D184D0B5D0BAD182D0B8D0B2D0BDD0BED181D182D18C20D181D0B0D0BCD0BED0B8D181D186D0B5D0BBD0B5D0BDD0B8D18F20D0BDD0B02024323536383138733120D0BDD0B02024323536383138642E0D0A0D0A7C634646464646464646D092D0B5D0BBD0B8D187D0B8D0B520D090D0BCD0B0D0BD27D182D183D0BBD0B07C720D0AD0A1D0B8D0BBD0B02C20D0B4D0B0D180D0BED0B2D0B0D0BDD0BDD0B0D18F20D09FD0B0D0BDD182D0B5D0BED0BDD0BED0BC2C20D0BFD0BED0B2D18BD188D0B0D0B5D18220243F28613133373030357C613133373034377C613133373032387C61313337303237295BD181D0B8D0BBD1835D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295BD0BBD0BED0B2D0BAD0BED181D182D18C5D5BD0B8D0BDD182D0B5D0BBD0BBD0B5D0BAD1825D20D0BDD0B02024323536383332733120D0BDD0B02024323536383332642E0000, 40944),
(3776013982, 247692, 'ruRU', 0x00D09FD0BED0B2D18BD188D0B0D0B5D18220D0B2D0B5D180D0BED18FD182D0BDD0BED181D182D18C20D0BFD0BED0BBD183D187D0B8D182D18C20D181D183D0BDD0B4D183D0BA20D18120D0BFD0B0D0BCD18FD182D0BDD18BD0BCD0B820D0B2D0B5D189D0B0D0BCD0B820D0B7D0B020D0BFD0B5D181D0BAD0B820D0B2D180D0B5D0BCD0B5D0BDD0B82E20D0ADD182D0B820D181D183D0BDD0B4D183D0BAD0B820D181D0BED0B4D0B5D180D0B6D0B0D18220D0BCD0BED189D0BDD18BD0B520D180D0B5D0BBD0B8D0BAD0B2D0B8D0B82C20D0B7D0BDD0B0D187D0B8D182D0B5D0BBD18CD0BDD0BE20D181D0BDD0B8D0B6D0B0D18ED189D0B8D0B520D181D0BBD0BED0B6D0BDD0BED181D182D18C20D0B2D180D0B5D0BCD0B5D0BDD0BDD18BD18520D0BFD0BED180D182D0B0D0BBD0BED0B22E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D0BFD0BED0B2D18BD188D0B0D0B5D18220D181D0BAD0BED180D0BED181D182D18C20D0BFD0B5D180D0B5D0B4D0B2D0B8D0B6D0B5D0BDD0B8D18F20D0BFD0B5D188D0BAD0BED0BC20D0B820D0BDD0B020D182D180D0B0D0BDD181D0BFD0BED180D182D0B520D0BDD0B020247332252E00D092D0B5D180D0BED18FD182D0BDD0BED181D182D18C20D0BFD0BED0BBD183D187D0B8D182D18C20D181D183D0BDD0B4D183D0BA20D18120D0BFD0B0D0BCD18FD182D0BDD18BD0BCD0B820D0B2D0B5D189D0B0D0BCD0B820D0B7D0B020D0BFD0B5D181D0BAD0B820D0B2D180D0B5D0BCD0B5D0BDD0B820D0BFD0BED0B2D18BD188D0B5D0BDD0B02E20D0ADD182D0B820D181D183D0BDD0B4D183D0BAD0B820D181D0BED0B4D0B5D180D0B6D0B0D18220D0BCD0BED189D0BDD18BD0B520D180D0B5D0BBD0B8D0BAD0B2D0B8D0B82C20D0B7D0BDD0B0D187D0B8D182D0B5D0BBD18CD0BDD0BE20D181D0BDD0B8D0B6D0B0D18ED189D0B8D0B520D181D0BBD0BED0B6D0BDD0BED181D182D18C20D0B2D180D0B5D0BCD0B5D0BDD0BDD18BD18520D0BFD0BED180D182D0B0D0BBD0BED0B22E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D181D0BAD0BED180D0BED181D182D18C20D0BFD0B5D180D0B5D0B4D0B2D0B8D0B6D0B5D0BDD0B8D18F20D0BFD0B5D188D0BAD0BED0BC20D0B820D0BDD0B020D182D180D0B0D0BDD181D0BFD0BED180D182D0B520D0BFD0BED0B2D18BD188D0B5D0BDD0B020D0BDD0B020247332252E00, 40944),
(3776013982, 247111, 'ruRU', 0x00D092D0B5D180D0BED18FD182D0BDD0BED181D182D18C20D0BFD180D0B8D0B7D0B2D0B0D182D18C20D0B1D180D0BED0BDD0B7D0BED0B2D0BED0B3D0BE20D0B4D180D0B0D0BAD0BED0BDD0B020D0B7D0B020D0BFD0B5D181D0BAD0B820D0B2D180D0B5D0BCD0B5D0BDD0B820D0BFD0BED0B2D18BD188D0B5D0BDD0B02E20D09FD180D0B820D0BFD0BED18FD0B2D0BBD0B5D0BDD0B8D0B820D0B4D180D0B0D0BAD0BED0BD20D0BCD0B3D0BDD0BED0B2D0B5D0BDD0BDD0BE20D0B7D0B0D187D0B8D181D182D0B8D18220D0B7D0B020D0B2D0B0D18120D0BBD18ED0B1D0BED0B520D181D0B2D18FD182D0B8D0BBD0B8D189D0B52E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D183D180D0BED0BD20D0B820D0BED0B1D18AD0B5D0BC20D0B8D181D186D0B5D0BBD0B5D0BDD0B8D18F20D183D0B2D0B5D0BBD0B8D187D0B5D0BDD18B20D0BDD0B020247332252E00D092D0B5D180D0BED18FD182D0BDD0BED181D182D18C20D0BFD180D0B8D0B7D18BD0B2D0B020D0B1D180D0BED0BDD0B7D0BED0B2D0BED0B3D0BE20D0B4D180D0B0D0BAD0BED0BDD0B020D0B7D0B020D0BFD0B5D181D0BAD0B820D0B2D180D0B5D0BCD0B5D0BDD0B820D0BFD0BED0B2D18BD188D0B5D0BDD0B02E20D09FD180D0B820D0BFD0BED18FD0B2D0BBD0B5D0BDD0B8D0B820D0B4D180D0B0D0BAD0BED0BD20D0BCD0B3D0BDD0BED0B2D0B5D0BDD0BDD0BE20D0B7D0B0D187D0B8D181D182D0B8D18220D0B7D0B020D0B2D0B0D18120D0BBD18ED0B1D0BED0B520D181D0B2D18FD182D0B8D0BBD0B8D189D0B52E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D183D180D0BED0BD20D0B820D0BED0B1D18AD0B5D0BC20D0B8D181D186D0B5D0BBD0B5D0BDD0B8D18F20D183D0B2D0B5D0BBD0B8D187D0B5D0BDD18B20D0BDD0B020247332252E00, 40944),
(3776013982, 247110, 'ruRU', 0x00D094D0B0D0B5D18220D0B4D0BED181D182D183D0BF20D0BA20D0BFD0BED180D182D0B0D0BBD0B0D0BC20D0B8D0B720D094D180D0B0D0BAD0BED0BDD18CD0B5D0B3D0BE20D09FD0BED0BAD0BED18F20D0B220D0BAD0B0D0B6D0B4D0BED0B520D0B8D0B720D0B4D180D0B0D0BAD0BED0BDD18CD0B8D18520D181D0B2D18FD182D0B8D0BBD0B8D1892E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D0BFD0BED0B2D18BD188D0B0D0B5D18220D181D0BAD0BED180D0BED181D182D18C20D0BFD0B5D180D0B5D0B4D0B2D0B8D0B6D0B5D0BDD0B8D18F20D0BFD0B5D188D0BAD0BED0BC20D0B820D0BDD0B020D182D180D0B0D0BDD181D0BFD0BED180D182D0B520D0BDD0B020247332252E00D094D0B0D0B5D18220D0B4D0BED181D182D183D0BF20D0BA20D0BFD0BED180D182D0B0D0BBD0B0D0BC20D0B8D0B720D094D180D0B0D0BAD0BED0BDD18CD0B5D0B3D0BE20D09FD0BED0BAD0BED18F20D0B220D0BAD0B0D0B6D0B4D0BED0B520D0B8D0B720D0B4D180D0B0D0BAD0BED0BDD18CD0B8D18520D181D0B2D18FD182D0B8D0BBD0B8D1892E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D181D0BAD0BED180D0BED181D182D18C20D0BFD0B5D180D0B5D0B4D0B2D0B8D0B6D0B5D0BDD0B8D18F20D0BFD0B5D188D0BAD0BED0BC20D0B820D0BDD0B020D182D180D0B0D0BDD181D0BFD0BED180D182D0B520D0BFD0BED0B2D18BD188D0B5D0BDD0B020D0BDD0B020247332252E00, 40944),
(3776013982, 247104, 'ruRU', 0x00D0A1D0BAD0BED180D0BED181D182D18C20D0BFD0B5D180D0B5D0B4D0B2D0B8D0B6D0B5D0BDD0B8D18F20D0BFD0B5D188D0BAD0BED0BC20D0B820D0BDD0B020D182D180D0B0D0BDD181D0BFD0BED180D182D0B520D0BFD0BED0B2D18BD188D0B5D0BDD0B020D0BDD0B020247331252E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D183D180D0BED0BD20D0B820D0BED0B1D18AD0B5D0BC20D0B8D181D186D0B5D0BBD0B5D0BDD0B8D18F20D183D0B2D0B5D0BBD0B8D187D0B5D0BDD18B20D0BDD0B020247332252E00D0A1D0BAD0BED180D0BED181D182D18C20D0BFD0B5D180D0B5D0B4D0B2D0B8D0B6D0B5D0BDD0B8D18F20D0BFD0B5D188D0BAD0BED0BC20D0B820D0BDD0B020D182D180D0B0D0BDD181D0BFD0BED180D182D0B520D0BFD0BED0B2D18BD188D0B5D0BDD0B020D0BDD0B020247331252E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D183D180D0BED0BD20D0B820D0BED0B1D18AD0B5D0BC20D0B8D181D186D0B5D0BBD0B5D0BDD0B8D18F20D183D0B2D0B5D0BBD0B8D187D0B5D0BDD18B20D0BDD0B020247332252E00, 40944),
(3776013982, 247103, 'ruRU', 0x0024407370656C6C646573633234343935390D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D183D180D0BED0BD20D0B820D0BED0B1D18AD0B5D0BC20D0B8D181D186D0B5D0BBD0B5D0BDD0B8D18F20D183D0B2D0B5D0BBD0B8D187D0B5D0BDD18B20D0BDD0B02035252E0000, 40944),
(3776013982, 247099, 'ruRU', 0x00D09FD0BED0B2D18BD188D0B0D0B5D18220D0BFD0BED0BBD183D187D0B5D0BDD0BDD183D18E20D0B7D0B020D181D187D0B5D18220D183D0B1D0B8D0B9D181D182D0B220D180D0B5D0BFD183D182D0B0D186D0B8D18E20D18320D0A5D180D0BED0BCD0B820D0BDD0B0202432343737363973312520D0B220D182D0B5D187D0B5D0BDD0B8D0B520243234373736396420D0B820D0BDD0B0202432343737373073312520D0B220D182D0B5D187D0B5D0BDD0B8D0B520243234373737306420D0B4D0BE20D0BAD0BED0BDD186D0B020D181D186D0B5D0BDD0B0D180D0B8D18F2E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D0BFD0BED0B2D18BD188D0B0D0B5D18220D181D0BAD0BED180D0BED181D182D18C20D0BFD0B5D180D0B5D0B4D0B2D0B8D0B6D0B5D0BDD0B8D18F20D0BFD0B5D188D0BAD0BED0BC20D0B820D0BDD0B020D182D180D0B0D0BDD181D0BFD0BED180D182D0B520D0BDD0B020247332252E0000, 40944),
(3776013982, 247096, 'ruRU', 0x000000, 40944),
(3776013982, 247094, 'ruRU', 0x00D092D0B5D180D0BED18FD182D0BDD0BED181D182D18C20D0BDD0B0D185D0BED0B6D0B4D0B5D0BDD0B8D18F20D0BFD0B5D181D0BAD0BED0B220D0B2D180D0B5D0BCD0B5D0BDD0B820D0BFD0BED0B2D18BD188D0B5D0BDD0B020D0BDD0B020247331252E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D0B7D0B0D0BFD0B0D18120D0B7D0B4D0BED180D0BED0B2D18CD18F20D183D0B2D0B5D0BBD0B8D187D0B5D0BD20D0BDD0B020247332252E00D092D0B5D180D0BED18FD182D0BDD0BED181D182D18C20D0BDD0B0D185D0BED0B6D0B4D0B5D0BDD0B8D18F20D0BFD0B5D181D0BAD0BED0B220D0B2D180D0B5D0BCD0B5D0BDD0B820D0BFD0BED0B2D18BD188D0B5D0BDD0B020D0BDD0B020247331252E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D0B7D0B0D0BFD0B0D18120D0B7D0B4D0BED180D0BED0B2D18CD18F20D183D0B2D0B5D0BBD0B8D187D0B5D0BD20D0BDD0B020247332252E00, 40944),
(3776013982, 247093, 'ruRU', 0x000000, 40944),
(3776013982, 247092, 'ruRU', 0x000000, 40944),
(3776013982, 247089, 'ruRU', 0x0024407370656C6C646573633234353530330D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D183D180D0BED0BD2C20D18DD184D184D0B5D0BAD182D0B8D0B2D0BDD0BED181D182D18C20D0B8D181D186D0B5D0BBD0B5D0BDD0B8D18F2C20D0B7D0B0D0BFD0B0D18120D0B7D0B4D0BED180D0BED0B2D18CD18F2C20D0B020D182D0B0D0BAD0B6D0B520D181D0BAD0BED180D0BED181D182D18C20D0BFD0B5D180D0B5D0B4D0B2D0B8D0B6D0B5D0BDD0B8D18F20D0BFD0B5D188D0BAD0BED0BC20D0B820D0BDD0B020D182D180D0B0D0BDD181D0BFD0BED180D182D0B520D0BFD0BED0B2D18BD188D0B5D0BDD18B20D0BDD0B020247332252E0000, 40944),
(3776013982, 247088, 'ruRU', 0x00D0A5D180D0BED0BCD0B820D180D0B0D181D0BAD180D18BD0B2D0B0D0B5D18220D0BCD0B5D181D182D0BED0BFD0BED0BBD0BED0B6D0B5D0BDD0B8D0B520D0BDD0B0D185D0BED0B4D18FD189D0B8D185D181D18F20D180D18FD0B4D0BED0BC20D181D183D0BDD0B4D183D0BAD0BED0B220D18120D181D0BED0BAD180D0BED0B2D0B8D189D0B0D0BCD0B82E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D183D180D0BED0BD20D0B820D0BED0B1D18AD0B5D0BC20D0B8D181D186D0B5D0BBD0B5D0BDD0B8D18F20D183D0B2D0B5D0BBD0B8D187D0B5D0BDD18B20D0BDD0B020247332252E00D0A5D180D0BED0BCD0B820D180D0B0D181D0BAD180D18BD0B2D0B0D0B5D18220D0BCD0B5D181D182D0BED0BFD0BED0BBD0BED0B6D0B5D0BDD0B8D0B520D0BDD0B0D185D0BED0B4D18FD189D0B8D185D181D18F20D180D18FD0B4D0BED0BC20D181D183D0BDD0B4D183D0BAD0BED0B220D18120D181D0BED0BAD180D0BED0B2D0B8D189D0B0D0BCD0B82E0D0A0D0A7C634646303046463030D091D0BED0BDD183D1813A7C7220D183D180D0BED0BD20D0B820D0BED0B1D18AD0B5D0BC20D0B8D181D186D0B5D0BBD0B5D0BDD0B8D18F20D183D0B2D0B5D0BBD0B8D187D0B5D0BDD18B20D0BDD0B020247332252E00, 40944),
(3479059991, 9040, 'ruRU', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'ruRU', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'ruRU', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'ruRU', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'ruRU', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'ruRU', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'ruRU', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'ruRU', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'ruRU', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'ruRU', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'ruRU', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'ruRU', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'ruRU', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'ruRU', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'ruRU', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'ruRU', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'ruRU', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'ruRU', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'ruRU', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'ruRU', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'ruRU', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'ruRU', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'ruRU', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'ruRU', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'ruRU', 0x0024407370656C6C646573633232383832390024733120D0B5D0B42E20D183D180D0BED0BDD0B020D0BED18220D0BED0B3D0BDD18F20D180D0B0D0B720D0B22024323238383239743120D181D0B5D0BA2E00, 40944),
(3776013982, 227799, 'ruRU', 0x00D09FD0BE20D0BFD0BED0BBD18E20D0B1D0BED18F20D0BFD180D0BED0BAD0B0D182D18BD0B2D0B0D18ED182D181D18F20D0B2D0BED0BBD0BDD18B2C20D0BDD0B0D0BDD0BED181D18FD189D0B8D0B52024733120D0B5D0B42E20D183D180D0BED0BDD0B020D0BED18220D0BCD0B0D0B3D0B8D0B820D0BBD18CD0B4D0B020D0B8D0B3D180D0BED0BAD0B0D0BC2C20D0BED0BAD0B0D0B7D0B0D0B2D188D0B8D0BCD181D18F20D0BDD0B020D0B8D18520D0BFD183D182D0B82E0000, 40944),
(3776013982, 227780, 'ruRU', 0x00D09FD0BED0BCD0B5D187D0B0D0B5D18220D0B8D0B3D180D0BED0BAD0BED0B220D18DD184D184D0B5D0BAD182D0BED0BC202224407370656C6C6E616D653232373738302220D0B820D0BDD0B0D0BDD0BED181D0B8D18220D0B8D0B3D180D0BED0BAD0B0D0BC20D0B220D180D0B0D0B4D0B8D183D181D0B52024413120D0BC2024733120D0B5D0B42E20D183D180D0BED0BDD0B020D0BED18220D181D0B8D0BB20D0BFD180D0B8D180D0BED0B4D18B20D0BFD0BE20D0B8D181D182D0B5D187D0B5D0BDD0B8D0B820D0B2D180D0B5D0BCD0B5D0BDD0B820D0B5D0B3D0BE20D0B4D0B5D0B9D181D182D0B2D0B8D18F2E00D09DD0B0D0BDD0BED181D0B8D18220D0B8D0B3D180D0BED0BAD0B0D0BC20D0B220D180D0B0D0B4D0B8D183D181D0B52024413120D0BC2024733120D0B5D0B42E20D183D180D0BED0BDD0B020D0BED18220D181D0B8D0BB20D0BFD180D0B8D180D0BED0B4D18B20D0BFD0BE20D0B8D181D182D0B5D187D0B5D0BDD0B8D0B820D0B2D180D0B5D0BCD0B5D0BDD0B820D0B4D0B5D0B9D181D182D0B2D0B8D18F2E00, 40944),
(3386291891, 116804, 'ruRU', 0xD090D0B3D0B5D0BDD18220D181D186D0B5D0BDD18B00000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'ruRU', 0xD092D0B5D180D185D0BED0B2D0BDD18BD0B920D0BCD0B0D0B320D09AD0B0D0B4D0B3D0B0D180000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'ruRU', 0xD09CD0B5D0B4D0B8D0B20000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'ruRU', 0xD09DD0B8D0B5D0BBD0B0D18120D090D180D0B0D0BD0000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'ruRU', 0xD09CD0B5D0B4D0B8D0B20000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'ruRU', 0xD0A1D0BCD0BED182D180D0B8D182D0B5D0BBD18C000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'ruRU', 0x00D09ED182D0BAD180D0BED0B9D182D0B520D181D182D180D0B0D0BDD0B8D186D18320D181D0BFD183D182D0BDD0B8D0BAD0BED0B220D0B820D0B8D181D0BFD0BED0BBD18CD0B7D183D0B9D182D0B520D18DD182D0BED18220D0BFD180D0B5D0B4D0BCD0B5D1822C20D187D182D0BED0B1D18B20D183D0B2D0B5D0BBD0B8D187D0B8D182D18C20D0BED0BFD18BD18220D181D0BFD183D182D0BDD0B8D0BAD0B020D0BDD0B02024733120D0B5D0B42E0000, 40944),
(261693969, 60399, 'ruRU', 0xFFFFFFFFFFFFFFFFD09FD0BED0BCD0BED189D18C20D0A0D0B5D0B2D0B5D0BDD0B4D180D0B5D182D18300003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'ruRU', 0xFFFFFFFFFFFFFFFFD09FD0BED0BCD0BED189D18C20D09CD0B0D0BBD0B4D180D0B0D0BAD181D183D181D18300003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'ruRU', 0xFFFFFFFFFFFFFFFFD09FD0BED0BCD0BED189D18C20D091D0B0D181D182D0B8D0BED0BDD18300003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'ruRU', 0xFFFFFFFFFFFFFFFFD09FD0BED0BCD0BED189D18C20D090D180D0B4D0B5D0BDD0B2D0B5D0BBD18CD0B4D18300003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'ruRU', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'ruRU', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'ruRU', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'ruRU', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'ruRU', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'ruRU', 0x00000000, 40944),
(3865974254, 176921, 'ruRU', 0x00000000, 40944),
(3865974254, 176832, 'ruRU', 0x00000000, 40944),
(3776013982, 243328, 'ruRU', 0x0000D0A3D180D0BED0B2D0B5D0BDD18C20D183D0B3D180D0BED0B7D18B20D181D0BDD0B8D0B6D0B5D0BD2E00, 40944),
(3865974254, 187935, 'ruRU', 0x00000000, 40944),
(3205218938, 44300, 'ruRU', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F5800D0A7D182D0BED0B1D18B20D180D0B0D0B7D0B1D0BBD0BED0BAD0B8D180D0BED0B2D0B0D182D18C20D18DD182D0BE20D0BFD0BED0BBD0B52C20D0BFD180D0B8D0BAD180D0B5D0BFD0B8D182D0B520D0BA20D183D187D0B5D182D0BDD0BED0B920D0B7D0B0D0BFD0B8D181D0B820D0B0D183D182D0B5D0BDD182D0B8D184D0B8D0BAD0B0D182D0BED18020426C697A7A61726420D0B820534D532DD183D0B2D0B5D0B4D0BED0BCD0BBD0B5D0BDD0B8D18F0001, 40944),
(3205218938, 44299, 'ruRU', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C636666666630303030D0A7D182D0BED0B1D18B20D181D0BED0B7D0B4D0B0D182D18C20D0B3D180D183D0BFD0BFD18320D0B1D0B5D0B720D18DD0BFD0BED185D0B0D0BBD18CD0BDD0BED0B3D0BE20D0BAD0BBD18ED187D0B02C20D181D0BDD0B0D187D0B0D0BBD0B020D0B7D0B0D189D0B8D182D0B8D182D0B520D183D187D0B5D182D0BDD183D18E20D0B7D0B0D0BFD0B8D181D18C20D0B0D183D182D0B5D0BDD182D0B8D184D0B8D0BAD0B0D182D0BED180D0BED0BC20426174746C652E6E657420D0B820D183D181D0BBD183D0B3D0BED0B920534D532DD183D0B2D0B5D0B4D0BED0BCD0BBD0B5D0BDD0B8D0B92E7C727C6E7C6366663165666630303CD09FD0BED0B4D180D0BED0B1D0BDD0BED181D182D0B83E7C720001, 40944),
(3205218938, 44284, 'ruRU', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C636666666630303030D0A7D182D0BED0B1D18B20D0B7D0B0D0BFD0BED0BBD0BDD0B8D182D18C20D18DD182D0BE20D0BFD0BED0BBD0B52C20D181D0BDD0B0D187D0B0D0BBD0B020D0B7D0B0D189D0B8D182D0B8D182D0B520D183D187D0B5D182D0BDD183D18E20D0B7D0B0D0BFD0B8D181D18C20D0B0D183D182D0B5D0BDD182D0B8D184D0B8D0BAD0B0D182D0BED180D0BED0BC20426174746C652E6E657420D0B820D183D181D0BBD183D0B3D0BED0B920534D532DD183D0B2D0B5D0B4D0BED0BCD0BBD0B5D0BDD0B8D0B92E7C727C6E7C6366663165666630303CD09FD0BED0B4D180D0BED0B1D0BDD0BED181D182D0B83E7C720001, 40944),
(3205218938, 44283, 'ruRU', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F4445534300D09FD180D0B8D0BAD180D0B5D0BFD0B8D182D0B520D0B0D183D182D0B5D0BDD182D0B8D184D0B8D0BAD0B0D182D0BED18020D0B820D183D181D0BBD183D0B3D18320534D532DD183D0B2D0B5D0B4D0BED0BCD0BBD0B5D0BDD0B8D0B920D0BA20D183D187D0B5D182D0BDD0BED0B920D0B7D0B0D0BFD0B8D181D0B820D0B820D0BED182D0BAD180D0BED0B9D182D0B520D0B4D0BED181D182D183D0BF20D0BAD0BE20D0B2D181D0B5D0BC20D184D183D0BDD0BAD186D0B8D18FD0BC20D0BFD0BED0B8D181D0BAD0B020D0B3D180D183D0BFD0BFD18B2E7C6E7C6ED090D183D182D0B5D0BDD182D0B8D184D0B8D0BAD0B0D182D0BED18020426174746C652E6E657420E2809320D18DD182D0BE20D0B1D0B5D181D0BFD0BBD0B0D182D0BDD18BD0B920D0B820D0BFD180D0BED181D182D0BED0B920D181D0BFD0BED181D0BED0B120D0B7D0B0D189D0B8D182D0B8D182D18C20D183D187D0B5D182D0BDD183D18E20D0B7D0B0D0BFD0B8D181D18C20D0BED18220D0B2D0B7D0BBD0BED0BCD0B02C20D0B020534D532DD183D0B2D0B5D0B4D0BED0BCD0BBD0B5D0BDD0B8D18F20D0BED0BFD0BED0B2D0B5D189D0B0D18ED18220D0B2D0B0D18120D0BE20D0B2D0B0D0B6D0BDD18BD18520D0B8D0B7D0BCD0B5D0BDD0B5D0BDD0B8D18FD18520D0B220D0B2D0B0D188D0B5D0B920D183D187D0B5D182D0BDD0BED0B920D0B7D0B0D0BFD0B8D181D0B82E7C6E7C6ED09DD0B0D0B6D0BCD0B8D182D0B52022D090D0BAD182D0B8D0B2D0B8D180D0BED0B2D0B0D182D18C222C20D187D182D0BED0B1D18B20D0BFD0B5D180D0B5D0B9D182D0B820D0BDD0B020D181D0B0D0B9D18220D0BFD0BED0B4D0BAD0BBD18ED187D0B5D0BDD0B8D18F20D0B0D183D182D0B5D0BDD182D0B8D184D0B8D0BAD0B0D182D0BED180D0B02E0001, 40944),
(3776013982, 358927, 'ruRU', 0x00D097D0B0D181D182D0B0D0B2D0BBD18FD0B5D18220D0B2D0B0D18120D0BFD0BED0B4D0BED0B7D180D0B8D182D0B5D0BBD18CD0BDD0BE20D0BED182D0BDD0BED181D0B8D182D18CD181D18F20D0BA20D0BED0BAD180D183D0B6D0B0D18ED189D0B8D0BC2E20D092D180D0B5D0BCD18F20D0B2D0BED181D181D182D0B0D0BDD0BED0B2D0BBD0B5D0BDD0B8D18F20D0B4D0BBD18F20D0BDD0BED187D0BDD0BED180D0BED0B6D0B4D0B5D0BDD0BDD18BD18520D183D0BCD0B5D0BDD18CD188D0B5D0BDD0BE2E00D09FD0BED0B4D0BED0B7D180D0B8D182D0B5D0BBD18CD0BDD0BED181D182D18C20D0BFD0BE20D0BED182D0BDD0BED188D0B5D0BDD0B8D18E20D0BA20D0BED0BAD180D183D0B6D0B0D18ED189D0B8D0BC2E00, 40944),
(3865974254, 188152, 'ruRU', 0x00000000, 40944),
(3776013982, 53385, 'ruRU', 0x00D0A1D0BED0B7D0B4D0B0D0B5D18220D0B2D0B8D185D180D18C20D0B1D0BED0B6D0B5D181D182D0B2D0B5D0BDD0BDD0BED0B920D18DD0BDD0B5D180D0B3D0B8D0B82C20D0BDD0B0D0BDD0BED181D18F2024733120D0B5D0B42E20D183D180D0BED0BDD0B020D0BED18220D181D0B2D0B5D182D0BBD0BED0B920D0BCD0B0D0B3D0B8D0B820D0BDD0B0D185D0BED0B4D18FD189D0B8D0BCD181D18F20D180D18FD0B4D0BED0BC20D0BFD180D0BED182D0B8D0B2D0BDD0B8D0BAD0B0D0BC2E20D0A6D0B5D0BBD0B820D0BFD0BED181D0BBD0B5202473322DD0B920D0BFD0BED0BBD183D187D0B0D18ED18220D183D0BCD0B5D0BDD18CD188D0B5D0BDD0BDD18BD0B920D183D180D0BED0BD2E0000, 40944),
(261693969, 62694, 'ruRU', 0xFFFFFFFFFFFFFFFFD09FD180D0B8D0B7D18BD0B220D0B220D09CD0B0D0BBD0B4D180D0B0D0BAD181D183D181D0B5000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'ruRU', 0xFFFFFFFFFFFFFFFFD09FD180D0B8D0B7D18BD0B220D0B220D090D180D0B4D0B5D0BDD0B2D0B5D0BBD18CD0B4D0B5000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'ruRU', 0xFFFFFFFFFFFFFFFFD09FD180D0B8D0B7D18BD0B220D0B220D091D0B0D181D182D0B8D0BED0BDD0B5000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'ruRU', 0xFFFFFFFFFFFFFFFFD09FD180D0B8D0B7D18BD0B220D0B220D0A0D0B5D0B2D0B5D0BDD0B4D180D0B5D182D0B5000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'ruRU', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'ruRU', 0x000000, 40944),
(3776013982, 307934, 'ruRU', 0x000000, 40944),
(3776013982, 307480, 'ruRU', 0x00D091D180D0BED181D0B0D0B5D18220D0B3D0BED182D0BED0B2D0BED0B3D0BE20D0BA20D180D0B0D0B1D0BED182D0B520D0B7D0B5D0BCD0BBD0B5D180D0BED18F2E0000, 40944),
(2948698321, 354, 'ruRU', 0x64DF8D9146629CB2, 40944),
(261693969, 60111, 'ruRU', 0xFFFFFFFFFFFFFFFFD097D0B0D0B2D18FD0B7D0B0D182D18C20D0B4D180D183D0B6D0B1D18300005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'ruRU', 0xFFFFFFFFFFFFFFFFD0A1D0B0D0BCD18BD0B920D0BBD183D187D188D0B8D0B920D0B4D180D183D0B320D0B220D0BCD0B8D180D0B500005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'ruRU', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'ruRU', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'ruRU', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'ruRU', 0x00000000, 40944),
(3865974254, 151804, 'ruRU', 0x00000000, 40944),
(3865974254, 151792, 'ruRU', 0x00000000, 40944),
(3037505077, 151792, 'ruRU', 0x0100, 40944),
(3865974254, 151790, 'ruRU', 0x00000000, 40944),
(3037505077, 151790, 'ruRU', 0x0100, 40944),
(3865974254, 146306, 'ruRU', 0x00000000, 40944),
(3865974254, 34685, 'ruRU', 0x00000000, 40944),
(3865974254, 34683, 'ruRU', 0x00000000, 40944),
(3865974254, 34087, 'ruRU', 0x00000000, 40944),
(3865974254, 34085, 'ruRU', 0x00000000, 40944),
(3865974254, 33969, 'ruRU', 0x00000000, 40944),
(3865974254, 33968, 'ruRU', 0x00000000, 40944),
(3865974254, 33967, 'ruRU', 0x00000000, 40944),
(3865974254, 33966, 'ruRU', 0x00000000, 40944),
(3865974254, 33868, 'ruRU', 0x00000000, 40944),
(3865974254, 33864, 'ruRU', 0x00000000, 40944),
(3865974254, 33863, 'ruRU', 0x00000000, 40944),
(3865974254, 33862, 'ruRU', 0x00000000, 40944),
(3865974254, 23324, 'ruRU', 0x00000000, 40944),
(3865974254, 21525, 'ruRU', 0x00000000, 40944),
(3865974254, 21524, 'ruRU', 0x00000000, 40944),
(3865974254, 19028, 'ruRU', 0x00000000, 40944),
(3865974254, 6835, 'ruRU', 0x00000000, 40944),
(3865974254, 6833, 'ruRU', 0x00000000, 40944),
(3865974254, 181321, 'ruRU', 0x00000000, 40944),
(1548466975, 27672, 'ruRU', 0x10040000, 40944),
(3776013982, 365080, 'ruRU', 0x0000D0A1D0BAD0BED180D0BED181D182D18C20D0BFD0B5D180D0B5D0B4D0B2D0B8D0B6D0B5D0BDD0B8D18F20D0BFD0BED0B2D18BD188D0B5D0BDD0B020D0BDD0B020247331252E00, 40944),
(3776013982, 317920, 'ruRU', 0x00D0A1D0BED0BAD180D0B0D189D0B0D0B5D18220D0B2D180D0B5D0BCD18F20D0B4D0B5D0B9D181D182D0B2D0B8D18F20D18DD184D184D0B5D0BAD182D0BED0B220D0BFD180D0B5D180D18BD0B2D0B0D0BDD0B8D18F20D0B820D0BDD0B5D0BCD0BED182D18B2C20D0BFD180D0B8D0BCD0B5D0BDD0B5D0BDD0BDD18BD18520D0BA20D183D187D0B0D181D182D0BDD0B8D0BAD0B0D0BC20D180D0B5D0B9D0B4D0B020D0B8D0BBD0B820D0B3D180D183D0BFD0BFD18B20D0B220D180D0B0D0B4D0B8D183D181D0B52024613120D0BC2C20D0BDD0B020247331252E20243F733333393132345BD0A2D0B0D0BAD0B6D0B520D0BED181D0BBD0B0D0B1D0BBD18FD0B5D18220D18DD184D184D0B5D0BAD182D18B20D181D182D180D0B0D185D0B02E5D5B5D00D0ADD184D184D0B5D0BAD182D0B8D0B2D0BDD0BED181D182D18C20D0BDD0B5D0BCD0BED182D18B20D0B820D0BFD180D0B5D180D18BD0B2D0B0D0BDD0B8D0B920D181D0BDD0B8D0B6D0B5D0BDD0B020D0BDD0B020247731252E243F733333393132345B20D0ADD184D184D0B5D0BAD182D0B8D0B2D0BDD0BED181D182D18C20D181D182D180D0B0D185D0B020D181D0BDD0B8D0B6D0B5D0BDD0B020D0BDD0B020247734252E5D5B5D00, 40944),
(3776013982, 465, 'ruRU', 0x00D091D0BBD0B0D0B3D0BED187D0B5D181D182D0B8D0B520D183D181D0B8D0BBD0B8D0B2D0B0D0B5D18220D183D187D0B0D181D182D0BDD0B8D0BAD0BED0B220D0B3D180D183D0BFD0BFD18B20D0B8D0BBD0B820D180D0B5D0B9D0B4D0B020D0B220D180D0B0D0B4D0B8D183D181D0B52024613120D0BC2C20D0B220D180D0B5D0B7D183D0BBD18CD182D0B0D182D0B520D187D0B5D0B3D0BE20D0BED0BDD0B820D0BFD0BED0BBD183D187D0B0D18ED18220D0BDD0B0202473312520D0BCD0B5D0BDD18CD188D0B520D183D180D0BED0BDD0B02E00D09FD0BED0BBD183D187D0B0D0B5D0BCD18BD0B920D183D180D0BED0BD20D183D0BCD0B5D0BDD18CD188D0B5D0BD20D0BDD0B020247731252E00, 40944),
(3205218938, 44172, 'ruRU', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F4445534300D094D0BED181D182D0B8D0B3D0BDD0B8D182D0B520D180D0B5D0B9D182D0B8D0BDD0B3D0B020313935302C20D187D182D0BED0B1D18B20D0BFD0BED0BBD183D187D0B8D182D18C3A7C6E2D20D0BDD0BED0B2D18BD0B920D180D0B0D0BDD0B320D183D0BBD183D187D188D0B5D0BDD0B8D18F20D18DD0BAD0B8D0BFD0B8D180D0BED0B2D0BAD0B820D0B4D0BBD18F205076500001, 40944),
(3205218938, 40887, 'ruRU', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F4445534300D094D0BED181D182D0B8D0B3D0BDD0B8D182D0B520D180D0B5D0B9D182D0B8D0BDD0B3D0B020313830302C20D187D182D0BED0B1D18B20D0BFD0BED0BBD183D187D0B8D182D18C3A7C6E2D20D0B7D0B2D0B0D0BDD0B8D0B520D184D0B0D0B2D0BED180D0B8D182D0B07C6E2D20D0B2D0BDD0B5D188D0BDD0B8D0B920D0B2D0B8D0B420D0BFD180D0B5D0B4D0BCD0B5D182D0B020D0B8D0B720D18DD0BBD0B8D182D0BDD0BED0B3D0BE20D0BAD0BED0BCD0BFD0BBD0B5D0BAD182D0B020D18DD0BAD0B8D0BFD0B8D180D0BED0B2D0BAD0B820D0B4D0BBD18F205076503A20D188D0BBD0B5D0BC7C6E2D20D0B2D0BDD0B5D188D0BDD0B8D0B920D0B2D0B8D0B420D0BFD180D0B5D0B4D0BCD0B5D182D0B020D0B8D0B720D18DD0BBD0B8D182D0BDD0BED0B3D0BE20D0BAD0BED0BCD0BFD0BBD0B5D0BAD182D0B020D18DD0BAD0B8D0BFD0B8D180D0BED0B2D0BAD0B820D0B4D0BBD18F205076503A20D0BDD0B0D0BFD0BBD0B5D187D0BDD0B8D0BAD0B80001, 40944),
(3205218938, 40885, 'ruRU', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F4445534300D094D0BED181D182D0B8D0B3D0BDD0B8D182D0B520D180D0B5D0B9D182D0B8D0BDD0B3D0B020313430302C20D187D182D0BED0B1D18B20D0BFD0BED0BBD183D187D0B8D182D18C3A7C6E2D20D0B7D0B2D0B0D0BDD0B8D0B520D0BFD180D0B5D182D0B5D0BDD0B4D0B5D0BDD182D0B07C6E2D20D0B2D0BDD0B5D188D0BDD0B8D0B920D0B2D0B8D0B420D0BFD180D0B5D0B4D0BCD0B5D182D0B020D0B8D0B720D18DD0BBD0B8D182D0BDD0BED0B3D0BE20D0BAD0BED0BCD0BFD0BBD0B5D0BAD182D0B020D18DD0BAD0B8D0BFD0B8D180D0BED0B2D0BAD0B820D0B4D0BBD18F205076503A20D0BFD0B5D180D187D0B0D182D0BAD0B87C6E2D20D0B2D0BDD0B5D188D0BDD0B8D0B920D0B2D0B8D0B420D0BFD180D0B5D0B4D0BCD0B5D182D0B020D0B8D0B720D18DD0BBD0B8D182D0BDD0BED0B3D0BE20D0BAD0BED0BCD0BFD0BBD0B5D0BAD182D0B020D18DD0BAD0B8D0BFD0B8D180D0BED0B2D0BAD0B820D0B4D0BBD18F205076503A20D0BED0B1D183D0B2D18C0001, 40944),
(3776013982, 357407, 'ruRU', 0x00D09FD180D0B8D0B7D18BD0B2D0B0D0B5D18220D180D0BED0BA2DD0BD2DD180D0BED0BBD0BB20D0BCD0BED0B1D0B8D0BBD18C2022D09CD0B0D180D0BED0B4D0B5D1802220D0B820D0BFD0BED0B7D0B2D0BED0BBD18FD0B5D18220D183D0BFD180D0B0D0B2D0BBD18FD182D18C20D0B8D0BC2E00D098D181D0BFD0BED0BBD18CD0B7D183D0B9D182D0B520D0BFD0B0D0BDD0B5D0BBD18C20D183D0BFD180D0B0D0B2D0BBD0B5D0BDD0B8D18F2C20D187D182D0BED0B1D18B20D0B0D182D0B0D0BAD0BED0B2D0B0D182D18C20D0B4D180D183D0B3D0B8D0B520D0B4D0B8D181D182D0B0D0BDD186D0B8D0BED0BDD0BDD0BE20D183D0BFD180D0B0D0B2D0BBD18FD0B5D0BCD18BD0B520D0B8D0B3D180D183D188D0BAD0B82E00, 40944),
(3776013982, 357406, 'ruRU', 0x00D09FD180D0B8D0B7D18BD0B2D0B0D0B5D18220D180D0BED0BA2DD0BD2DD180D0BED0BBD0BB20D0BCD0BED0B1D0B8D0BBD18C2022D09CD0B0D180D0BED0B4D0B5D1802220D0B820D0BFD0BED0B7D0B2D0BED0BBD18FD0B5D18220D183D0BFD180D0B0D0B2D0BBD18FD182D18C20D0B8D0BC2E00D098D181D0BFD0BED0BBD18CD0B7D183D0B9D182D0B520D0BFD0B0D0BDD0B5D0BBD18C20D183D0BFD180D0B0D0B2D0BBD0B5D0BDD0B8D18F2C20D187D182D0BED0B1D18B20D0B0D182D0B0D0BAD0BED0B2D0B0D182D18C20D0B4D180D183D0B3D0B8D0B520D0B4D0B8D181D182D0B0D0BDD186D0B8D0BED0BDD0BDD0BE20D183D0BFD180D0B0D0B2D0BBD18FD0B5D0BCD18BD0B520D0B8D0B3D180D183D188D0BAD0B82E00, 40944),
(3776013982, 357405, 'ruRU', 0x00D09FD180D0B8D0B7D18BD0B2D0B0D0B5D18220D180D0BED0BA2DD0BD2DD180D0BED0BBD0BB20D0BCD0BED0B1D0B8D0BBD18C2022D09CD0B0D180D0BED0B4D0B5D1802220D0B820D0BFD0BED0B7D0B2D0BED0BBD18FD0B5D18220D183D0BFD180D0B0D0B2D0BBD18FD182D18C20D0B8D0BC2E00D098D181D0BFD0BED0BBD18CD0B7D183D0B9D182D0B520D0BFD0B0D0BDD0B5D0BBD18C20D183D0BFD180D0B0D0B2D0BBD0B5D0BDD0B8D18F2C20D187D182D0BED0B1D18B20D0B0D182D0B0D0BAD0BED0B2D0B0D182D18C20D0B4D180D183D0B3D0B8D0B520D0B4D0B8D181D182D0B0D0BDD186D0B8D0BED0BDD0BDD0BE20D183D0BFD180D0B0D0B2D0BBD18FD0B5D0BCD18BD0B520D0B8D0B3D180D183D188D0BAD0B82E00, 40944),
(3776013982, 356631, 'ruRU', 0x00D09FD180D0B8D0B7D18BD0B2D0B0D0B5D18220D180D0BED0BA2DD0BD2DD180D0BED0BBD0BB20D0BCD0BED0B1D0B8D0BBD18C2022D092D0B5D182D180D0BED180D0B5D0B72220D0B820D0BFD0BED0B7D0B2D0BED0BBD18FD0B5D18220D183D0BFD180D0B0D0B2D0BBD18FD182D18C20D0B8D0BC2E00D098D181D0BFD0BED0BBD18CD0B7D183D0B9D182D0B520D0BFD0B0D0BDD0B5D0BBD18C20D183D0BFD180D0B0D0B2D0BBD0B5D0BDD0B8D18F2C20D187D182D0BED0B1D18B20D0B0D182D0B0D0BAD0BED0B2D0B0D182D18C20D0B4D180D183D0B3D0B8D0B520D0B4D0B8D181D182D0B0D0BDD186D0B8D0BED0BDD0BDD0BE20D183D0BFD180D0B0D0B2D0BBD18FD0B5D0BCD18BD0B520D0B8D0B3D180D183D188D0BAD0B82E00, 40944),
(3776013982, 328923, 'ruRU', 0xD09DD0BED187D0BDD0BED0B920D0BDD0B0D180D0BED0B4D0B5D18600D09FD0B5D180D0B5D0BDD0B0D0BFD180D0B0D0B2D0BBD18FD0B5D18220D0B6D0B8D0B7D0BDD0B5D0BDD0BDD183D18E20D181D0B8D0BBD18320D0BCD0B0D0BAD181D0B8D0BCD183D0BC20243332383932384920D0BFD180D0BED182D0B8D0B2D0BDD0B8D0BAD0BED0B220D0B8D0B720D183D0BAD0B0D0B7D0B0D0BDD0BDD0BED0B920D0BED0B1D0BBD0B0D181D182D0B82C20D0BDD0B0D0BDD0BED181D18F20247B282433323839323873312A24642F24743229202B202433323839323873317D20D0B5D0B42E20D183D180D0BED0BDD0B020D0BED18220D181D0B8D0BB20D0BFD180D0B8D180D0BED0B4D18B20D0B7D0B020246420D0ADD182D0BED18220D183D180D0BED0BD20D180D0B0D181D0BFD180D0B5D0B4D0B5D0BBD18FD0B5D182D181D18F20D0BCD0B5D0B6D0B4D18320D0B2D181D0B5D0BCD0B820D0BFD0BED180D0B0D0B6D0B5D0BDD0BDD18BD0BCD0B820D0BFD180D0BED182D0B8D0B2D0BDD0B8D0BAD0B0D0BCD0B82E20243F613133373034315B0D0A0D0AD09FD0BE20D0BED0BAD0BED0BDD187D0B0D0BDD0B8D0B820D0BFD0BED0B4D0B4D0B5D180D0B6D0B0D0BDD0B8D18F2022D092D0BED0BBD188D0B5D0B1D0BDD0BED0B520D0BFD0B5D180D0B5D0BBD0B8D0B2D0B0D0BDD0B8D0B52220D0B4D0B0D0B5D1822024733420244CD18DD184D184D0B5D0BAD1823AD18DD184D184D0B5D0BAD182D0B03AD18DD184D184D0B5D0BAD182D0BED0B23B2022D09ED180D183D0B6D0B8D18F20D092D0BED0B4D0BED0B2D0BED180D0BED182D0B0222E5D5B5D0D0A0D0AD09FD0BED0B2D182D0BED180D0BDD0BED0B520D0BFD180D0B8D0BCD0B5D0BDD0B5D0BDD0B8D0B52022D092D0BED0BBD188D0B5D0B1D0BDD0BED0B3D0BE20D0BFD0B5D180D0B5D0BBD0B8D0B2D0B0D0BDD0B8D18F2220D0B220D182D0B5D187D0B5D0BDD0B8D0B52024333238393333642E20D0B2D18BD181D0B2D0BED0B1D0BED0B6D0B4D0B0D0B5D182202473312520D183D180D0BED0BDD0B020D0BED1822022D092D0BED0BBD188D0B5D0B1D0BDD0BED0B3D0BE20D0BFD0B5D180D0B5D0BBD0B8D0B2D0B0D0BDD0B8D18F222C20D0B8D181D186D0B5D0BBD18FD18F20D0BCD0B0D0BAD181D0B8D0BCD183D0BC2024333238393330733220D181D0BED18ED0B7D0BDD0B8D0BAD0BED0B220D0B220D180D0B0D0B4D0B8D183D181D0B52024333238393330413120D0BC2E0000, 40944),
(3776013982, 101546, 'ruRU', 0x00D092D18B20D0BAD180D183D0B6D0B8D182D0B5D181D18C20D0B220D0B2D0BED0B7D0B4D183D185D0B52C20D0B220D182D0B5D187D0B5D0BDD0B8D0B520246420D0BDD0B0D0BDD0BED181D18F20D0BFD180D0BED182D0B8D0B2D0BDD0B8D0BAD0B0D0BC20D0B220D180D0B0D0B4D0B8D183D181D0B52024313037323730413120D0BC20243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5D20D0B5D0B42E20D184D0B8D0B7D0B8D187D0B5D181D0BAD0BED0B3D0BE20D183D180D0BED0BDD0B02E20D0A6D0B5D0BBD0B820D0BFD0BED181D0BBD0B5202473312DD0B920D0BFD0BED0BBD183D187D0B0D18ED18220D183D0BCD0B5D0BDD18CD188D0B5D0BDD0BDD18BD0B920D183D180D0BED0BD2E243F63335B0D0A0D0AD0A3D180D0BED0BD20D0BED1822022D0A2D0B0D0BDD186D183D18ED189D0B5D0B3D0BE20D0B6D183D180D0B0D0B2D0BBD18F2220D183D0B2D0B5D0BBD0B8D187D0B8D0B2D0B0D0B5D182D181D18F20D0BDD0B0202432323033353873312520D0B7D0B020D0BAD0B0D0B6D0B4D183D18E20D0BED182D0B4D0B5D0BBD18CD0BDD183D18E20D186D0B5D0BBD18C2C20D0BAD0BED182D0BED180D0BED0B920D0B2D18B20D0BDD0B0D0BDD0B5D181D0BBD0B820D183D180D0BED0BD2022D09BD0B0D0BFD0BED0B920D182D0B8D0B3D180D0B0222C2022D09DD0BED0BAD0B0D183D182D0B8D180D183D18ED189D0B8D0BC20D183D0B4D0B0D180D0BED0BC2220D0B8D0BBD0B82022D0A3D0B4D0B0D180D0BED0BC20D0B2D0BED181D185D0BED0B4D18FD189D0B5D0B3D0BE20D181D0BED0BBD0BDD186D0B02220D0B220D182D0B5D187D0B5D0BDD0B8D0B520D0BFD0BED181D0BBD0B5D0B4D0BDD0B8D1852024323230333538642E20D0A1D183D0BCD0BCD0B8D180D183D0B5D182D181D18F20D0B4D0BE20243232383238376920246CD180D0B0D0B7D0B03AD180D0B0D0B73AD180D0B0D0B73B2E5D5B5D00D09DD0B0D185D0BED0B4D18FD189D0B8D0B5D181D18F20D180D18FD0B4D0BED0BC20D0BFD180D0BED182D0B8D0B2D0BDD0B8D0BAD0B820D180D0B0D0B720D0B22024313031353436743120D181D0B5D0BA2E20D0BFD0BED0BBD183D187D0B0D18ED18220D184D0B8D0B7D0B8D187D0B5D181D0BAD0B8D0B920D183D180D0BED0BD2E00, 40944),
(3865974254, 188220, 'ruRU', 0x00000000, 40944),
(3865974254, 187900, 'ruRU', 0x00000000, 40944),
(3865974254, 187899, 'ruRU', 0x00000000, 40944),
(3865974254, 187898, 'ruRU', 0x00000000, 40944),
(3865974254, 187897, 'ruRU', 0x00000000, 40944),
(3865974254, 187896, 'ruRU', 0x00000000, 40944),
(3865974254, 187895, 'ruRU', 0x00000000, 40944),
(3865974254, 187875, 'ruRU', 0x00000000, 40944),
(3865974254, 187869, 'ruRU', 0x00000000, 40944),
(3865974254, 150746, 'ruRU', 0x00000000, 40944),
(3865974254, 150745, 'ruRU', 0x00000000, 40944),
(3865974254, 150744, 'ruRU', 0x00000000, 40944),
(3865974254, 150743, 'ruRU', 0x00000000, 40944),
(3776013982, 364944, 'ruRU', 0x0000D0A1D0BAD0BED180D0BED181D182D18C20D0BFD0B5D180D0B5D0B4D0B2D0B8D0B6D0B5D0BDD0B8D18F20D0BFD0BED0B2D18BD188D0B5D0BDD0B020D0BDD0B020247331252E00, 40944),
(3776013982, 228462, 'ruRU', 0x00D0A3D0B2D0B5D0BBD0B8D187D0B8D0B2D0B0D0B5D18220D183D180D0BED0BD20D0BED18220D0B0D0B2D182D0BED0B0D182D0B0D0BA20D0BDD0B020247331C2A0D0B5D0B42E0000, 40944),
(3776013982, 119611, 'ruRU', 0x0024407370656C6C6465736331313531353100D092D0BED181D0BFD0BED0BBD0BDD0B5D0BDD0B8D0B52024773120D0B5D0B42E20D0B7D0B4D0BED180D0BED0B2D18CD18F20D180D0B0D0B720D0B22024743120D181D0B5D0BA2E00, 40944),
(3776013982, 119607, 'ruRU', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'ruRU', 0x00000000, 40944),
(1181150530, 403396, 'ruRU', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'ruRU', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'ruRU', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'ruRU', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'ruRU', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'ruRU', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'ruRU', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'ruRU', 0xA4530000, 40944),
(3359787322, 21411, 'ruRU', 0xA3530000, 40944),
(3359787322, 21410, 'ruRU', 0xA2530000, 40944),
(3359787322, 21409, 'ruRU', 0xA1530000, 40944),
(3359787322, 21408, 'ruRU', 0xA0530000, 40944),
(3359787322, 21407, 'ruRU', 0x9F530000, 40944),
(3359787322, 21406, 'ruRU', 0x9E530000, 40944),
(2557447376, 655518, 'ruRU', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'ruRU', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'ruRU', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'ruRU', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'ruRU', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'ruRU', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F45464645435400D09AD0BBD0B0D181D181D0B8D187D0B5D181D0BAD0B8D0B520D0BFD180D0B0D0B2D0B8D0BBD0B020D180D0B0D181D0BFD180D0B5D0B4D0B5D0BBD0B5D0BDD0B8D18F20D0B4D0BED0B1D18BD187D0B820D0B1D0BED0BBD18CD188D0B520D0BDD0B520D0B4D0B5D0B9D181D182D0B2D183D18ED1822E0001, 40944),
(3776013982, 347944, 'ruRU', 0x00D09FD0BED0B2D18BD188D0B0D0B5D18220D0B2D0B5D180D0BED18FD182D0BDD0BED181D182D18C20D0BAD180D0B8D182D0B8D187D0B5D181D0BAD0BED0B3D0BE20D183D0B4D0B0D180D0B020D0BDD0B020247331252E0D0A00D092D0B5D180D0BED18FD182D0BDD0BED181D182D18C20D0BAD180D0B8D182D0B8D187D0B5D181D0BAD0BED0B3D0BE20D183D0B4D0B0D180D0B020D0BFD0BED0B2D18BD188D0B5D0BDD0B020D0BDD0B020247331252E00, 40944),
(3776013982, 347943, 'ruRU', 0x00D0A3D0B2D0B5D0BBD0B8D187D0B8D0B2D0B0D0B5D18220D0BCD0B0D0BAD181D0B8D0BCD0B0D0BBD18CD0BDD18BD0B920D0B7D0B0D0BFD0B0D18120D0B7D0B4D0BED180D0BED0B2D18CD18F20D0BDD0B020247331252E0D0A00D09CD0B0D0BAD181D0B8D0BCD0B0D0BBD18CD0BDD18BD0B920D0B7D0B0D0BFD0B0D18120D0B7D0B4D0BED180D0BED0B2D18CD18F20D183D0B2D0B5D0BBD0B8D187D0B5D0BD20D0BDD0B020247331252E00, 40944),
(3776013982, 1714, 'ruRU', 0x00D097D0B0D181D182D0B0D0B2D0BBD18FD0B5D18220D186D0B5D0BBD18C20D0B3D0BED0B2D0BED180D0B8D182D18C20D0BDD0B020D18FD0B7D18BD0BAD0B520D0B4D0B5D0BCD0BED0BDD0BED0B22C20D0BFD180D0BED0B4D0BBD0B5D0B2D0B0D18F20D0B2D180D0B5D0BCD18F20D0BFD180D0B8D0BCD0B5D0BDD0B5D0BDD0B8D18F20D0B7D0B0D0BAD0BBD0B8D0BDD0B0D0BDD0B8D0B920D0BDD0B0202473312520D0BDD0B02024642E243F733130333131325B0D0A0D0A7C434646453535424230D093D0BED180D18FD189D0B0D18F20D0B4D183D188D0B03A2022D09FD180D0BED0BAD0BBD18FD182D0B8D0B520D0BAD0BED181D0BDD0BED18FD0B7D18BD187D0B8D18F2220D0B4D0B5D0B9D181D182D0B2D183D0B5D18220D0BDD0B020D0BFD180D0BED182D0B8D0B2D0BDD0B8D0BAD0BED0B220D0B220D180D0B0D0B4D0B8D183D181D0B520243130343232344120D0BC20D0B2D0BED0BAD180D183D0B320D186D0B5D0BBD0B82E7C525D5B5D0D0A0D0A7C634646383238324646D09FD180D0BED0BAD0BBD18FD182D0B8D18F3A20D0B5D0B4D0B8D0BDD0BED0B2D180D0B5D0BCD0B5D0BDD0BDD0BE20D0BDD0B020D0BAD0B0D0B6D0B4D183D18E20D186D0B5D0BBD18C20D187D0B5D180D0BDD0BED0BAD0BDD0B8D0B6D0BDD0B8D0BAD0B020D0BCD0BED0B6D0B5D18220D0B4D0B5D0B9D181D182D0B2D0BED0B2D0B0D182D18C20D182D0BED0BBD18CD0BAD0BE20D0BED0B4D0BDD0BE20D0B5D0B3D0BE20D0BFD180D0BED0BAD0BBD18FD182D0B8D0B52E7C7200D094D0B5D0BCD0BED0BDD0B8D187D0B5D181D0BAD0B8D0B920D18FD0B7D18BD0BA20D183D0B2D0B5D0BBD0B8D187D0B8D0B2D0B0D0B5D18220D0B2D180D0B5D0BCD18F20D0BFD180D0B8D0BCD0B5D0BDD0B5D0BDD0B8D18F20D0B7D0B0D0BAD0BBD0B8D0BDD0B0D0BDD0B8D0B920D0BDD0B020247731252E00, 40944),
(3205218938, 41865, 'ruRU', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E5300D092D18B20D0BDD0B520D0BCD0BED0B6D0B5D182D0B520D0B8D0B7D0BCD0B5D0BDD18FD182D18C20D0B4D0B0D0BDD0BDD18BD0B520D0BE20D0BDD0B0D0B1D0BED180D0B520D0B8D0B3D180D0BED0BAD0BED0B22E0001, 40944),
(261693969, 64850, 'ruRU', 0xFFFFFFFFFFFFFFFFD09FD180D0B5D0BED0B4D0BED0BBD0B5D0B2D0B0D18F20D091D0B0D188D0BDD18E20D09FD180D0BED0BAD0BBD18FD182D18BD185000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'ruRU', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='ruRU') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='ruRU');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'ruRU' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `achievement_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (14775,14752,14682,14351));
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14775, 'zhCN', '在玛拉斯缪斯阵营中达到崇拜声望。', '玛拉斯缪赞', '头衔奖励：真君子/魔姑娘', 40944),
(14752, 'zhCN', '完成下列憎恶缝合成就。', '亡者消遣', '头衔奖励：可憎的 和 坐骑奖励：重装魂选荒牛', 40944),
(14682, 'zhCN', '完成下列灰烬王庭成就。', '聚会通报官', '头衔奖励：聚会通报官', 40944),
(14351, 'zhCN', '在晋升之路中击败39名首领。', '晋升之路39', '在晋升之路中解锁更多挑战。', 40944);


DELETE FROM `area_table_locale` WHERE (`VerifiedBuild`>0 AND `ID`=13316 AND `locale`='zhCN');
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(13316, 'zhCN', '祭仪密院', 40944);


DELETE FROM `battle_pet_species_locale` WHERE (`VerifiedBuild`>0 AND `ID`=3188 AND `locale`='zhCN');
INSERT INTO `battle_pet_species_locale` (`ID`, `locale`, `Description_lang`, `SourceText_lang`, `VerifiedBuild`) VALUES
(3188, 'zhCN', '', '', 40944);


DELETE FROM `broadcast_text_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (215513,215512,215511));
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(215513, 'zhCN', '', '不做好准备就贸然进入噬渊是非常不明智的。等你准备好了再来找我吧。', 40944),
(215512, 'zhCN', '不做好准备就贸然进入噬渊是非常不明智的。等你准备好了再来找我吧。', '', 40944),
(215511, 'zhCN', '', '我们就快成功了。只要我们并肩作战，就能度过这场难关。', 40944);


DELETE FROM `char_titles_locale` WHERE (`VerifiedBuild`>0 AND `ID`=693 AND `locale`='zhCN');
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(693, 'zhCN', '晋升者 %s', '晋升者 %s', 40944);


UPDATE `char_titles_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=683 AND `locale`='zhCN');
DELETE FROM `chr_customization_option_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (1523,689));
INSERT INTO `chr_customization_option_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1523, 'zhCN', '尾巴', 40944),
(689, 'zhCN', '尾巴', 40944);


DELETE FROM `criteria_tree_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (91730,94390,94389,94388,93811,93810,94331,94330));
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91730, 'zhCN', '9.1 Meta Achievement', 40944),
(94390, 'zhCN', '', 40944),
(94389, 'zhCN', '', 40944),
(94388, 'zhCN', '', 40944),
(93811, 'zhCN', '', 40944),
(93810, 'zhCN', '名望等级80级', 40944),
(94331, 'zhCN', '', 40944),
(94330, 'zhCN', 'Renown Level 80 - Kyrian', 40944);


DELETE FROM `item_search_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,116401));
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(151806, 'zhCN', '端庄的裙子', 40944),
(151804, 'zhCN', '黑色礼服短裤', 40944),
(151792, 'zhCN', '绿色冬衣', 40944),
(151790, 'zhCN', '红色冬衣', 40944),
(34685, 'zhCN', '夏日外衣', 40944),
(34683, 'zhCN', '夏日拖鞋', 40944),
(34087, 'zhCN', '绿色冬衣', 40944),
(34085, 'zhCN', '红色冬衣', 40944),
(33969, 'zhCN', '紫色美酒帽', 40944),
(33968, 'zhCN', '蓝色美酒帽', 40944),
(33967, 'zhCN', '绿色美酒帽', 40944),
(33966, 'zhCN', '美酒节便鞋', 40944),
(33868, 'zhCN', '美酒节长靴', 40944),
(33864, 'zhCN', '棕色美酒帽', 40944),
(33863, 'zhCN', '美酒节长裙', 40944),
(33862, 'zhCN', '美酒节礼服', 40944),
(23324, 'zhCN', '火焰节衬肩', 40944),
(21525, 'zhCN', '绿色冬帽', 40944),
(21524, 'zhCN', '红色冬帽', 40944),
(19028, 'zhCN', '端庄的裙子', 40944),
(6835, 'zhCN', '黑色礼服短裤', 40944),
(6833, 'zhCN', '白色礼服衬衣', 40944),
(181321, 'zhCN', '宝顶魔杖', 40944),
(116401, 'zhCN', '精致感恩者的礼帽', 40944);


DELETE FROM `item_sparse_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (176922,176921,176832,187935,188152,151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,188220,187900,187899,187898,187897,187896,187895,187875,187869,150746,150745,150744,150743,116401));
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(176922, 'zhCN', '这种魔法花朵可以使重生的灵魂提供的制作材料的数量和触媒之种中长出的触媒数量提高100%。', '', '', '', '荒野魅夜花', 40944),
(176921, 'zhCN', '这种魔化叶片可以使再生灵种的生长过程缩短1天。', '', '', '', '时空之叶', 40944),
(176832, 'zhCN', '这种特殊的根粒可以使灵魂重生时提供的奖励品质获得提升。', '', '', '', '灵种根粒', 40944),
(187935, 'zhCN', '教你学会制作午夜符文牡鹿印记。', '', '', '', '工艺图：午夜符文牡鹿印记', 40944),
(188152, 'zhCN', '碎片上还有魔法，摸着非常热。', '', '', '', '传送门控制碎片', 40944),
(151806, 'zhCN', '', '', '', '', '端庄的裙子', 40944),
(151804, 'zhCN', '', '', '', '', '黑色礼服短裤', 40944),
(151792, 'zhCN', '', '', '', '', '绿色冬衣', 40944),
(151790, 'zhCN', '', '', '', '', '红色冬衣', 40944),
(34685, 'zhCN', '', '', '', '', '夏日外衣', 40944),
(34683, 'zhCN', '', '', '', '', '夏日拖鞋', 40944),
(34087, 'zhCN', '', '', '', '', '绿色冬衣', 40944),
(34085, 'zhCN', '', '', '', '', '红色冬衣', 40944),
(33969, 'zhCN', '', '', '', '', '紫色美酒帽', 40944),
(33968, 'zhCN', '', '', '', '', '蓝色美酒帽', 40944),
(33967, 'zhCN', '', '', '', '', '绿色美酒帽', 40944),
(33966, 'zhCN', '', '', '', '', '美酒节便鞋', 40944),
(33868, 'zhCN', '', '', '', '', '美酒节长靴', 40944),
(33864, 'zhCN', '', '', '', '', '棕色美酒帽', 40944),
(33863, 'zhCN', '', '', '', '', '美酒节长裙', 40944),
(33862, 'zhCN', '', '', '', '', '美酒节礼服', 40944),
(23324, 'zhCN', '', '', '', '', '火焰节衬肩', 40944),
(21525, 'zhCN', '', '', '', '', '绿色冬帽', 40944),
(21524, 'zhCN', '', '', '', '', '红色冬帽', 40944),
(19028, 'zhCN', '', '', '', '', '端庄的裙子', 40944),
(6835, 'zhCN', '', '', '', '', '黑色礼服短裤', 40944),
(6833, 'zhCN', '', '', '', '', '白色礼服衬衣', 40944),
(181321, 'zhCN', '', '', '', '', '宝顶魔杖', 40944),
(188220, 'zhCN', '球的底部写着“我从塔里活下来了”。', '', '', '', '托加斯特灰烬之球', 40944),
(187900, 'zhCN', '一位地精和一位侏儒结成的二人组介绍了他们在两座岛屿上的许多发现。', '', '', '', '侦察地图：库尔提拉斯和赞达拉的奇景', 40944),
(187899, 'zhCN', '一位富于冒险精神的炼金师描述了外域多元的生物群落和令人难以置信的植物。', '', '', '', '侦察地图：壮美的外域', 40944),
(187898, 'zhCN', '一位银色北伐军战士详尽地报告了为了追击巫妖王而进行的所有军事行动。', '', '', '', '侦察地图：诺森德战役的代价', 40944),
(187897, 'zhCN', '罕见的双阵营联合报告，整合介绍了死亡之翼对艾泽拉斯造成的无数破坏性后果。', '', '', '', '侦察地图：大灾变的后果', 40944),
(187896, 'zhCN', '轻松的故事集，讲述了丽丽最近在潘达利亚的冒险，当中还有她的陈叔提供的饮食推介。', '', '', '', '侦察地图：丽丽·风暴烈酒的潘达利亚旅行指南', 40944),
(187895, 'zhCN', '德拉诺的少数安全地点的简要列表，以及你需要了解的当地风俗。', '', '', '', '侦察地图：德拉诺的威胁', 40944),
(187875, 'zhCN', '与燃烧军团正面交战的各类军事单位发出的大量的报告以及信件。', '', '', '', '侦察地图：破碎群岛的联合战线', 40944),
(187869, 'zhCN', '事无巨细地介绍了一位噬渊行者在暗影界四个国度的旅程。', '', '', '', '侦察地图：深入暗影界', 40944),
(150746, 'zhCN', '关于如何为位于东部王国的岗哨及时提供补给的几点建议。', '', '', '', '侦察地图：现代东部王国后勤制度', 40944),
(150745, 'zhCN', '关于如何在第四次大战中迅速打残联盟位于东部王国部队的详细战略手册。', '', '', '', '侦察地图：东部王国战役', 40944),
(150744, 'zhCN', '修复一切邪恶、堕落以及反自然之力留给大地的伤痕。', '', '', '', '侦察地图：卡利姆多：与大地母亲同行', 40944),
(150743, 'zhCN', '详细收录了所有带獠牙的、利爪的、剧毒的以及跟部落结盟的野兽。', '', '', '', '侦察地图：卡利姆多生存指南', 40944),
(116401, 'zhCN', '', '', '', '', '精致感恩者的礼帽', 40944);


UPDATE `item_sparse_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (185950,185947,185946));
DELETE FROM `lfg_dungeons_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1445 AND `locale`='zhCN');
INSERT INTO `lfg_dungeons_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1445, 'zhCN', '邪能图腾之陨', '阻止图加·鲜血图腾和他的邪能蠕虫震塌至高岭的企图。', 40944);


DELETE FROM `map_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1756 AND `locale`='zhCN');
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(1756, 'zhCN', '克罗米之死', '', '', '', '', 40944);


DELETE FROM `player_condition_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (95078,95077,95076,85644,73006,73005,87365,85912,85910,85909,85692,94517,94516,94515,94514,94513,94512,94511));
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(95078, 'zhCN', '', 40944),
(95077, 'zhCN', '', 40944),
(95076, 'zhCN', '', 40944),
(85644, 'zhCN', '必须达到$pcMinLevel级才能继续。', 40944),
(73006, 'zhCN', '', 40944),
(73005, 'zhCN', '', 40944),
(87365, 'zhCN', '', 40944),
(85912, 'zhCN', '', 40944),
(85910, 'zhCN', '', 40944),
(85909, 'zhCN', '', 40944),
(85692, 'zhCN', '', 40944),
(94517, 'zhCN', '', 40944),
(94516, 'zhCN', '', 40944),
(94515, 'zhCN', '', 40944),
(94514, 'zhCN', '', 40944),
(94513, 'zhCN', '', 40944),
(94512, 'zhCN', '', 40944),
(94511, 'zhCN', '', 40944);


DELETE FROM `spell_category_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1186 AND `locale`='zhCN');
INSERT INTO `spell_category_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1186, 'zhCN', 'Class - Paladin - Hand of Sacrifice', 40944);


DELETE FROM `spell_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (361952,256817,247692,247111,247110,247104,247103,247099,247096,247094,247093,247092,247089,247088,228844,227799,227780,362986,243328,358927,53385,329902,307934,307480,365080,317920,465,357407,357406,357405,356631,328923,101546,364944,228462,119611,119607,347944,347943,1714));
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(361952, 'zhCN', '1000份心能', 40944),
(256817, 'zhCN', '阿曼苏尔的印记', 40944),
(247692, 'zhCN', '好运连连', 40944),
(247111, 'zhCN', 'Blessing of the Bronze Dragonflight Passive', 40944),
(247110, 'zhCN', '无限速率', 40944),
(247104, 'zhCN', 'Acceleration Passive', 40944),
(247103, 'zhCN', 'Time Stop Passive', 40944),
(247099, 'zhCN', 'Chrono Charisma Passive', 40944),
(247096, 'zhCN', 'Rapid Recovery Passive', 40944),
(247094, 'zhCN', '偶遇', 40944),
(247093, 'zhCN', 'Dragon\'s Determination Passive', 40944),
(247092, 'zhCN', 'Accelerated Aggression Passive', 40944),
(247089, 'zhCN', 'Dragon Crash Passive', 40944),
(247088, 'zhCN', '洞察', 40944),
(228844, 'zhCN', '炽燃之骨', 40944),
(227799, 'zhCN', '冲刷', 40944),
(227780, 'zhCN', '雷霆仪式', 40944),
(362986, 'zhCN', '经验值', 40944),
(243328, 'zhCN', '渐隐术', 40944),
(358927, 'zhCN', '夜之子卫士的警戒', 40944),
(53385, 'zhCN', '神圣风暴', 40944),
(329902, 'zhCN', '挖掘中', 40944),
(307934, 'zhCN', '挖掘中', 40944),
(307480, 'zhCN', '投掷泥仆', 40944),
(365080, 'zhCN', '疾风步', 40944),
(317920, 'zhCN', '专注光环', 40944),
(465, 'zhCN', '虔诚光环', 40944),
(357407, 'zhCN', '召唤浩劫战车', 40944),
(357406, 'zhCN', '召唤履带斗士', 40944),
(357405, 'zhCN', '召唤飞尘恶魔', 40944),
(356631, 'zhCN', '召唤气动锋刃', 40944),
(328923, 'zhCN', '法夜输灵', 40944),
(101546, 'zhCN', '神鹤引项踢', 40944),
(364944, 'zhCN', '疾风步', 40944),
(228462, 'zhCN', '麦兰杜斯的玺戒', 40944),
(119611, 'zhCN', '复苏之雾', 40944),
(119607, 'zhCN', '复苏之雾', 40944),
(347944, 'zhCN', '奥伯勒隆尖刺', 40944),
(347943, 'zhCN', '奥伯勒隆之耐', 40944),
(1714, 'zhCN', '语言诅咒', 40944);


DELETE FROM `transmog_set_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (2289,2287,2283,2281,2277,2275,2271,2269,2178));
INSERT INTO `transmog_set_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(2289, 'zhCN', '不羁角斗士的板甲', 40944),
(2287, 'zhCN', '不羁角斗士的板甲', 40944),
(2283, 'zhCN', '不羁角斗士的链甲', 40944),
(2281, 'zhCN', '不羁角斗士的链甲', 40944),
(2277, 'zhCN', '不羁角斗士的皮甲', 40944),
(2275, 'zhCN', '不羁角斗士的皮甲', 40944),
(2271, 'zhCN', '不羁角斗士的法衣', 40944),
(2269, 'zhCN', '不羁角斗士的法衣', 40944),
(2178, 'zhCN', '缝合大师的武器', 40944);


UPDATE `transmog_set_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='zhCN' AND `ID` IN (2221,2220,2219,2218,2217,2216,2215,2214,2213,2212,2211,2210,2209,2208,2207,2206,2205,2204,2203,2202));
DELETE FROM `achievement_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table_locale` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_blob` WHERE (`TableHash`=2948698321 AND `RecordId`=340 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='zhCN') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='zhCN') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='zhCN') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='zhCN') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='zhCN') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='zhCN') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='zhCN') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='zhCN') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='zhCN') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='zhCN') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='zhCN') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='zhCN') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='zhCN') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='zhCN') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='zhCN') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='zhCN') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=358927 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='zhCN') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='zhCN') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='zhCN') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='zhCN') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='zhCN') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='zhCN') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='zhCN') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='zhCN') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='zhCN') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='zhCN') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='zhCN') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='zhCN') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='zhCN') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='zhCN') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='zhCN') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='zhCN') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='zhCN') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='zhCN') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='zhCN') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='zhCN') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='zhCN') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='zhCN') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='zhCN') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='zhCN') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='zhCN') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='zhCN') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='zhCN') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='zhCN') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='zhCN') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='zhCN') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='zhCN') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='zhCN') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='zhCN') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='zhCN') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='zhCN') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='zhCN');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(2948698321, 340, 'zhCN', 0xA53E23C86B3D8F59, 40944),
(261693969, 65165, 'zhCN', 0xFFFFFFFFFFFFFFFFE781B5E9AD82E694AFE68C81000044AC546F010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000000000000, 40944),
(3776013982, 361952, 'zhCN', 0x00E4B8BAE4BDA0E5BD93E5898DE79B9FE7BAA6E79A84E5BF83E883BDE8B4AEE8978FE6B7BBE58AA0247331E4BBBDE5BF83E883BDE380820000, 40944),
(3776013982, 256817, 'zhCN', 0x00E4BDA0E79A84E6B395E69CAFE5928CE68A80E883BDE69C89E4B880E5AE9AE587A0E78E87E4BDBFE4BDA0E88EB7E5BE97243235363831387331E9809FE5BAA6E38081E997AAE981BFE5928CE590B8E8A180EFBC8CE68C81E7BBAD2432353638313864E380820D0A0D0A7C634646464646464646E998BFE69BBCE88B8FE5B094E79A84E5A881E4B8A57C720D0AE59CA8E58F97E588B0E4B887E7A59EE6AEBFE79A84E5BCBAE58C96E697B6EFBC8CE4BDA0E79A84243F28613133373030357C613133373034377C613133373032387C61313337303237295BE58A9BE9878F5D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295BE6958FE68DB75D5BE699BAE58A9B5DE68F90E9AB98243235363833327331E782B9EFBC8CE68C81E7BBAD2432353638333264E380820000, 40944),
(3776013982, 247692, 'zhCN', 0x00E4BDA0E4BB8EE697B6E997B4E4B98BE6B299E4B8ADE88EB7E5BE97E7BAAAE5BFB5E59381E7AEB1E5AD90E79A84E587A0E78E87E68F90E9AB98E38082E7BAAAE5BFB5E59381E7AEB1E5AD90E58685E590ABE69C89E5BCBAE5A4A7E79A84E789A9E59381EFBC8CE883BDE5A49FE5A4A7E5A4A7E9998DE4BD8EE697B6E7A9BAE4BCA0E98081E997A8E68C91E68898E79A84E99ABEE5BAA6E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E7A7BBE58AA8E9809FE5BAA6E5928CE59D90E9AA91E9809FE5BAA6E68F90E9AB9824733225E3808200E4BDA0E4BB8EE697B6E997B4E4B98BE6B299E4B8ADE88EB7E5BE97E7BAAAE5BFB5E59381E7AEB1E5AD90E79A84E587A0E78E87E68F90E9AB98E38082E7BAAAE5BFB5E59381E7AEB1E5AD90E58685E590ABE69C89E5BCBAE5A4A7E79A84E789A9E59381EFBC8CE883BDE5A49FE5A4A7E5A4A7E9998DE4BD8EE697B6E7A9BAE4BCA0E98081E997A8E68C91E68898E79A84E99ABEE5BAA6E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E7A7BBE58AA8E9809FE5BAA6E5928CE59D90E9AA91E9809FE5BAA6E68F90E9AB9824733225E3808200, 40944),
(3776013982, 247111, 'zhCN', 0x00E4BDA0E4BB8EE697B6E997B4E4B98BE6B299E4B8ADE58FACE594A4E587BAE99D92E9939CE5B9BCE9BE99E79A84E587A0E78E87E68F90E9AB98E38082E6ADA4E5B9BCE9BE99E58FAFE4BBA5E7AB8BE58DB3E4B8BAE4BDA0E88283E6B885E4B880E5BAA7E5B7A8E9BE99E59CA3E59CB0E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E4BCA4E5AEB3E4B88EE6B2BBE79697E9878FE68F90E9AB9824733225E3808200E4BDA0E4BB8EE697B6E997B4E4B98BE6B299E4B8ADE58FACE594A4E587BAE99D92E9939CE5B9BCE9BE99E79A84E587A0E78E87E68F90E9AB98E38082E6ADA4E5B9BCE9BE99E58FAFE4BBA5E7AB8BE58DB3E4B8BAE4BDA0E88283E6B885E4B880E5BAA7E5B7A8E9BE99E59CA3E59CB0E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E4BCA4E5AEB3E4B88EE6B2BBE79697E9878FE68F90E9AB9824733225E3808200, 40944),
(3776013982, 247110, 'zhCN', 0x00E8A7A3E99481E4BB8EE9BE99E79CA0E7A59EE6AEBFE5898DE5BE80E59084E4B8AAE5B7A8E9BE99E59CA3E59CB0E79A84E4BCA0E98081E997A8E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E7A7BBE58AA8E9809FE5BAA6E5928CE59D90E9AA91E9809FE5BAA6E68F90E9AB9824733225E3808200E8A7A3E99481E4BB8EE9BE99E79CA0E7A59EE6AEBFE5898DE5BE80E59084E4B8AAE5B7A8E9BE99E59CA3E59CB0E79A84E4BCA0E98081E997A8E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E7A7BBE58AA8E9809FE5BAA6E5928CE59D90E9AA91E9809FE5BAA6E68F90E9AB9824733225E3808200, 40944),
(3776013982, 247104, 'zhCN', 0x00E7A7BBE58AA8E9809FE5BAA6E5928CE59D90E9AA91E9809FE5BAA6E68F90E9AB9824733125E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E4BCA4E5AEB3E4B88EE6B2BBE79697E9878FE68F90E9AB9824733225E3808200E7A7BBE58AA8E9809FE5BAA6E5928CE59D90E9AA91E9809FE5BAA6E68F90E9AB9824733125E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E4BCA4E5AEB3E4B88EE6B2BBE79697E9878FE68F90E9AB9824733225E3808200, 40944),
(3776013982, 247103, 'zhCN', 0x0024407370656C6C646573633234343935390D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E4BCA4E5AEB3E4B88EE6B2BBE79697E9878FE68F90E9AB983525E380820000, 40944),
(3776013982, 247099, 'zhCN', 0x00E69C80E5908E2432343737363964E58685EFBC8CE4BDA0E587BBE69D80E6958CE4BABAE697B6E59CA8E5858BE7BD97E7B1B3E5A484E79A84E5A3B0E69C9BE88EB7E58F96E9809FE5BAA6E68F90E9AB9824323437373639733125E38082E69C80E5908E2432343737373064E58685EFBC8CE88EB7E58F96E9809FE5BAA6E58899E5B086E68F90E9AB98E887B324323437373730733125E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E7A7BBE58AA8E9809FE5BAA6E5928CE59D90E9AA91E9809FE5BAA6E68F90E9AB9824733225E380820000, 40944),
(3776013982, 247096, 'zhCN', 0x000000, 40944),
(3776013982, 247094, 'zhCN', 0x00E4BDA0E58F91E78EB0E697B6E997B4E4B98BE6B299E79A84E587A0E78E87E68F90E9AB9824733125E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E7949FE591BDE580BCE68F90E9AB9824733225E3808200E4BDA0E58F91E78EB0E697B6E997B4E4B98BE6B299E79A84E587A0E78E87E68F90E9AB9824733125E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E7949FE591BDE580BCE68F90E9AB9824733225E3808200, 40944),
(3776013982, 247093, 'zhCN', 0x000000, 40944),
(3776013982, 247092, 'zhCN', 0x000000, 40944),
(3776013982, 247089, 'zhCN', 0x0024407370656C6C646573633234353530330D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E4BCA4E5AEB3E38081E6B2BBE79697E9878FE38081E7949FE591BDE580BCE38081E7A7BBE58AA8E9809FE5BAA6E5928CE59D90E9AA91E9809FE5BAA6E585A8E983A8E68F90E9AB9824733225E380820000, 40944),
(3776013982, 247088, 'zhCN', 0x00E5858BE7BD97E7B1B3E4BC9AE698BEE7A4BAE99984E8BF91E79A84E5AE9DE7AEB1E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E4BCA4E5AEB3E5928CE6B2BBE79697E9878FE68F90E9AB9824733225E3808200E5858BE7BD97E7B1B3E4BC9AE698BEE7A4BAE99984E8BF91E79A84E5AE9DE7AEB1E380820D0A0D0A7C634646303046463030E58AA0E68890EFBC9A7C72E4BCA4E5AEB3E5928CE6B2BBE79697E9878FE68F90E9AB9824733225E3808200, 40944),
(3479059991, 9040, 'zhCN', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'zhCN', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'zhCN', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'zhCN', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'zhCN', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'zhCN', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'zhCN', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'zhCN', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'zhCN', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'zhCN', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'zhCN', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'zhCN', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'zhCN', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'zhCN', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'zhCN', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'zhCN', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'zhCN', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'zhCN', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'zhCN', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'zhCN', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'zhCN', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'zhCN', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'zhCN', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'zhCN', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'zhCN', 0x0024407370656C6C6465736332323838323900E6AF8F243232383832397431E7A792E980A0E68890247331E782B9E781ABE784B0E4BCA4E5AEB3E3808200, 40944),
(3776013982, 227799, 'zhCN', 0x00E688BFE997B4E79A84E8BEB9E7BC98E6B68CE587BAE6B581E6B0B4E79A84E6B3A2E6B5AAEFBC8CE6A8AAE689ABE688BFE997B4EFBC8CE5AFB9E68EA5E8A7A6E588B0E79A84E78EA9E5AEB6E980A0E68890247331E782B9E586B0E99C9CE4BCA4E5AEB3E380820000, 40944),
(3776013982, 227780, 'zhCN', 0x00E794A824407370656C6C6E616D65323237373830E6A087E8AEB0E68980E69C89E78EA9E5AEB6E38082E68C81E7BBADE697B6E997B4E7BB93E69D9FE697B6EFBC8CE5AFB9244131E7A081E58685E79A84E68980E69C89E78EA9E5AEB6E980A0E68890247331E782B9E887AAE784B6E4BCA4E5AEB3E3808200E68C81E7BBADE697B6E997B4E7BB93E69D9FE697B6EFBC8CE5AFB9244131E7A081E58685E79A84E68980E69C89E78EA9E5AEB6E980A0E68890247331E782B9E887AAE784B6E4BCA4E5AEB3E3808200, 40944),
(3386291891, 116804, 'zhCN', 0xE59CBAE699AFE6BC94E7AE97E4BD9300000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'zhCN', 0xE5A4A7E6B395E5B888E58DA1E5BEB7E58AA0000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'zhCN', 0xE9BAA6E8BFAAE696870000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'zhCN', 0xE88182E68B89E696AFC2B7E59F83E585B00000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'zhCN', 0xE9BAA6E8BFAAE696870000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'zhCN', 0xE9A686E995BF000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'zhCN', 0x00E68993E5BC80E4BDA0E79A84E4BC99E4BCB4E9A1B5E99DA2EFBC8CE98089E68BA9E4B880E5908DE4BC99E4BCB4EFBC8CE4BDBFE585B6E7AD89E7BAA7E68F90E58D87E887B3247331E7BAA7E380820000, 40944),
(261693969, 60399, 'zhCN', 0xFFFFFFFFFFFFFFFFE58D8FE58AA9E99BB7E69687E5BEB7E696AF00003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'zhCN', 0xFFFFFFFFFFFFFFFFE58D8FE58AA9E78E9BE58D93E5858BE890A8E696AF00003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'zhCN', 0xFFFFFFFFFFFFFFFFE58D8FE58AA9E6998BE58D87E5A0A1E59E9200003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'zhCN', 0xFFFFFFFFFFFFFFFFE58D8FE58AA9E782BDE8939DE4BB99E9878E00003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'zhCN', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'zhCN', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'zhCN', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'zhCN', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'zhCN', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'zhCN', 0x00000000, 40944),
(3865974254, 176921, 'zhCN', 0x00000000, 40944),
(3865974254, 176832, 'zhCN', 0x00000000, 40944),
(3776013982, 243328, 'zhCN', 0x0000E5A881E88381E7AD89E7BAA7E9998DE4BD8EE3808200, 40944),
(3865974254, 187935, 'zhCN', 0x00000000, 40944),
(3205218938, 44300, 'zhCN', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F5800E7BB99E887AAE5B7B1E79A84E8B4A6E58FB7E6B7BBE58AA0E5AE89E585A8E4BBA4E5928CE5928CE79FADE4BFA1E5AE89E585A8E4BF9DE68AA4E58A9FE883BDE5908EE6898DE883BDE8A7A3E99481E6ADA4E6A08F0001, 40944),
(3205218938, 44299, 'zhCN', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C636666666630303030E4BDA0E58FAAE69C89E7BB99E887AAE5B7B1E79A84E8B4A6E58FB7E6B7BBE58AA0E68898E7BD91E5AE89E585A8E4BBA4E5928CE79FADE4BFA1E5AE89E585A8E4BF9DE68AA4E58A9FE883BDE5908EE6898DE883BDE59CA8E6B2A1E69C89E992A5E79FB3E697B6E58F91E5B883E4B880E4B8AAE58FB2E8AF97E992A5E79FB3E9989FE4BC8D7C727C6E7C6366663165666630303CE782B9E587BBE698BEE7A4BAE69BB4E5A49AE4BFA1E681AF3E7C720001, 40944),
(3205218938, 44284, 'zhCN', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C636666666630303030E4BDA0E58FAAE69C89E7BB99E887AAE5B7B1E79A84E8B4A6E58FB7E6B7BBE58AA0E68898E7BD91E5AE89E585A8E4BBA4E5928CE79FADE4BFA1E5AE89E585A8E4BF9DE68AA4E58A9FE883BDE5908EE6898DE883BDE7BC96E8BE91E6ADA4E6A08F7C727C6E7C6366663165666630303CE782B9E587BBE698BEE7A4BAE69BB4E5A49AE4BFA1E681AF3E7C720001, 40944),
(3205218938, 44283, 'zhCN', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F4445534300E4B8BAE4BDA0E79A84E8B4A6E58FB7E6B7BBE58AA0E5AE89E585A8E4BBA4E5928CE79FADE4BFA1E5AE89E585A8E4BF9DE68AA4E58A9FE883BDE5908EE5B0B1E883BDE4BDBFE794A8E9989FE4BC8DE69FA5E689BEE599A8E79A84E585A8E983A8E58A9FE883BDE380827C6E7C6EE68898E7BD91E5AE89E585A8E4BBA4E5AE8CE585A8E5858DE8B4B9EFBC8CE8808CE4B894E4BDBFE794A8E696B9E4BEBFEFBC8CE58FAFE4BBA5E69C89E69588E59CB0E4BF9DE68AA4E682A8E79A84E8B4A6E58FB7EFBC8CE79FADE4BFA1E5AE89E585A8E4BF9DE68AA4E58A9FE883BDE58FAFE4BBA5E59CA8E8B4A6E58FB7E69C89E9878DE8A681E694B9E58AA8E697B6E4B8BAE682A8E9809AE79FA5E68F90E98692E380827C6E7C6EE782B9E587BBE2809CE590AFE794A8E2809DE58DB3E58FAFE68993E5BC80E5AE89E585A8E4BBA4E8AEBEE7BDAEE7BD91E7AB99E380820001, 40944),
(3776013982, 358927, 'zhCN', 0x00E5AFB9E4BDA0E591A8E59BB4E79A84E78EAFE5A283E8B5B7E79691E5BF83E380820D0AE5A49CE4B98BE5AD90E4BDBFE794A8E697B6E586B7E58DB4E697B6E997B4E9998DE4BD8EE3808200E5AFB9E4BDA0E591A8E59BB4E79A84E4BABAE8B5B7E79691E5BF83E3808200, 40944),
(3865974254, 188152, 'zhCN', 0x00000000, 40944),
(3776013982, 53385, 'zhCN', 0x00E9878AE694BEE7A59EE59CA3E883BDE9878FE79A84E6978BE9A38EEFBC8CE5AFB9E99984E8BF91E68980E69C89E6958CE4BABAE980A0E68890247331E782B9E7A59EE59CA3E4BCA4E5AEB3E38082E79BAEE6A087E695B0E9878FE8B685E8BF87247332E4B8AAE5908EE980A0E68890E79A84E4BCA4E5AEB3E9998DE4BD8EE380820000, 40944),
(261693969, 62694, 'zhCN', 0xFFFFFFFFFFFFFFFFE4BDBFE591BDEFBC9AE78E9BE58D93E5858BE890A8E696AF000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'zhCN', 0xFFFFFFFFFFFFFFFFE4BDBFE591BDEFBC9AE782BDE8939DE4BB99E9878E000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'zhCN', 0xFFFFFFFFFFFFFFFFE4BDBFE591BDEFBC9AE6998BE58D87E5A0A1E59E92000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'zhCN', 0xFFFFFFFFFFFFFFFFE4BDBFE591BDEFBC9AE99BB7E69687E5BEB7E696AF000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'zhCN', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'zhCN', 0x000000, 40944),
(3776013982, 307934, 'zhCN', 0x000000, 40944),
(3776013982, 307480, 'zhCN', 0x00E68A95E587BAE4BDA0E79A84E68890E7869FE79A84E6B3A5E4BB860000, 40944),
(2948698321, 354, 'zhCN', 0x64DF8D9146629CB2, 40944),
(261693969, 60111, 'zhCN', 0xFFFFFFFFFFFFFFFFE993B8E980A0E58F8BE8B08A00005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'zhCN', 0xFFFFFFFFFFFFFFFFE78BACE6ADA4E4B880E4BBBDE79A84E69C8BE58F8B00005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'zhCN', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'zhCN', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'zhCN', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'zhCN', 0x00000000, 40944),
(3865974254, 151804, 'zhCN', 0x00000000, 40944),
(3865974254, 151792, 'zhCN', 0x00000000, 40944),
(3037505077, 151792, 'zhCN', 0x0100, 40944),
(3865974254, 151790, 'zhCN', 0x00000000, 40944),
(3037505077, 151790, 'zhCN', 0x0100, 40944),
(3865974254, 146306, 'zhCN', 0x00000000, 40944),
(3865974254, 34685, 'zhCN', 0x00000000, 40944),
(3865974254, 34683, 'zhCN', 0x00000000, 40944),
(3865974254, 34087, 'zhCN', 0x00000000, 40944),
(3865974254, 34085, 'zhCN', 0x00000000, 40944),
(3865974254, 33969, 'zhCN', 0x00000000, 40944),
(3865974254, 33968, 'zhCN', 0x00000000, 40944),
(3865974254, 33967, 'zhCN', 0x00000000, 40944),
(3865974254, 33966, 'zhCN', 0x00000000, 40944),
(3865974254, 33868, 'zhCN', 0x00000000, 40944),
(3865974254, 33864, 'zhCN', 0x00000000, 40944),
(3865974254, 33863, 'zhCN', 0x00000000, 40944),
(3865974254, 33862, 'zhCN', 0x00000000, 40944),
(3865974254, 23324, 'zhCN', 0x00000000, 40944),
(3865974254, 21525, 'zhCN', 0x00000000, 40944),
(3865974254, 21524, 'zhCN', 0x00000000, 40944),
(3865974254, 19028, 'zhCN', 0x00000000, 40944),
(3865974254, 6835, 'zhCN', 0x00000000, 40944),
(3865974254, 6833, 'zhCN', 0x00000000, 40944),
(3865974254, 181321, 'zhCN', 0x00000000, 40944),
(1548466975, 27672, 'zhCN', 0x10040000, 40944),
(3776013982, 365080, 'zhCN', 0x0000E7A7BBE58AA8E9809FE5BAA6E68F90E9AB9824733125E3808200, 40944),
(3776013982, 317920, 'zhCN', 0x00246131E7A081E88C83E59BB4E58685E79A84E5B08FE9989FE58F8AE59BA2E9989FE68890E59198E58F97E588B0E68993E696ADE5928CE6B289E9BB98E69588E69E9CE79A84E68C81E7BBADE697B6E997B4E7BCA9E79FAD24733125E38082243F733333393132345BE68190E683A7E69588E69E9CE4B99FE4BC9AE7BCA9E79FADE380825D5B5D00E68993E696ADE5928CE6B289E9BB98E69588E69E9CE68C81E7BBADE697B6E997B4E7BCA9E79FAD24773125E38082243F733333393132345BE68190E683A7E69588E69E9CE68C81E7BBADE697B6E997B4E7BCA9E79FAD24773425E380825D5B5D00, 40944),
(3776013982, 465, 'zhCN', 0x00E4BDBF246131E7A081E88C83E59BB4E58685E79A84E5B08FE9989FE5928CE59BA2E9989FE68890E59198E58F97E588B0E887AAE8BAABE89994E8AF9AE79A84E6BF80E58AB1EFBC8CE58F97E588B0E79A84E4BCA4E5AEB3E9998DE4BD8E24733125E3808200E58F97E588B0E79A84E4BCA4E5AEB3E9998DE4BD8E24773125E3808200, 40944),
(3205218938, 44172, 'zhCN', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F4445534300E8BEBEE588B031393530E68896E4BBA5E4B88AE79A84E8AF84E7BAA7E7AD89E7BAA7E5908EE58DB3E58FAFE88EB7E5BE97EFBC9A7C6E2D20507650E789A9E59381E58D87E7BAA7E7AD89E7BAA70001, 40944),
(3205218938, 40887, 'zhCN', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F4445534300E8BEBEE588B031383030E68896E4BBA5E4B88AE79A84E8AF84E7BAA7E7AD89E7BAA7E5908EE58DB3E58FAFE88EB7E5BE973A7C6E2D20E7AB9EE4BA89E88085E5A4B4E8A1947C6E2D20E7B2BEE88BB1507650E789A9E59381E5A597E8A385E5A496E8A782EFBC9AE5A4B4E79B947C6E2D20E7B2BEE88BB1507650E789A9E59381E5A597E8A385E5A496E8A782EFBC9AE882A9E886800001, 40944),
(3205218938, 40885, 'zhCN', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F4445534300E8BEBEE588B031343030E68896E4BBA5E4B88AE79A84E8AF84E7BAA7E7AD89E7BAA7E5908EE58DB3E58FAFE88EB7E5BE973A7C6E2D20E68C91E68898E88085E5A4B4E8A1947C6E2D20E7B2BEE88BB1507650E789A9E59381E5A597E8A385E5A496E8A782EFBC9AE6898BE5A5977C6E2D20E7B2BEE88BB1507650E789A9E59381E5A597E8A385E5A496E8A782EFBC9AE99E8BE5AD900001, 40944),
(3776013982, 357407, 'zhCN', 0x00E58FACE594A4E5B9B6E68EA7E588B6E4BDA0E79A84E69187E6BB9AE8B59BE8BDA6E28094E28094E6B5A9E58AABE68898E8BDA6E3808200E4BDBFE794A8E58AA8E4BD9CE69DA1E4B88AE79A84E68A80E883BDE69DA5E694BBE587BBE585B6E5AE83E981A5E68EA7E78EA9E585B7E3808200, 40944),
(3776013982, 357406, 'zhCN', 0x00E58FACE594A4E5B9B6E68EA7E588B6E4BDA0E79A84E69187E6BB9AE8B59BE8BDA6E28094E28094E5B1A5E5B8A6E69697E5A3ABE3808200E4BDBFE794A8E58AA8E4BD9CE69DA1E4B88AE79A84E68A80E883BDE69DA5E694BBE587BBE585B6E5AE83E981A5E68EA7E78EA9E585B7E3808200, 40944),
(3776013982, 357405, 'zhCN', 0x00E58FACE594A4E5B9B6E68EA7E588B6E4BDA0E79A84E69187E6BB9AE8B59BE8BDA6E28094E28094E9A39EE5B098E681B6E9AD94E3808200E4BDBFE794A8E58AA8E4BD9CE69DA1E4B88AE79A84E68A80E883BDE69DA5E694BBE587BBE585B6E5AE83E981A5E68EA7E78EA9E585B7E3808200, 40944),
(3776013982, 356631, 'zhCN', 0x00E58FACE594A4E5B9B6E68EA7E588B6E4BDA0E79A84E69187E6BB9AE8B59BE8BDA6E28094E28094E6B094E58AA8E9948BE58883E3808200E4BDBFE794A8E58AA8E4BD9CE69DA1E4B88AE79A84E68A80E883BDE69DA5E694BBE587BBE585B6E5AE83E981A5E68EA7E78EA9E585B7E3808200, 40944),
(3776013982, 328923, 'zhCN', 0xE6B395E5A49C00E8BDACE7A7BBE79BAEE6A087E58CBAE59F9FE58685E887B3E5A49A2433323839323849E4B8AAE6958CE4BABAE79A84E7949FE591BDE4B98BE58A9BEFBC8CE59CA82464E58685E980A0E68890247B282433323839323873312A24642F24743229202B202433323839323873317DE782B9E887AAE784B6E4BCA4E5AEB3EFBC8CE794B1E58CBAE59F9FE58685E79A84E6958CE4BABAE59D87E6918AE38082243F613133373034315B0D0A0D0AE5AE8CE695B4E696BDE694BEE6B395E5A49CE8BE93E781B5E5908EEFBC8CE4BAA7E7949F247334E5B182E6BCA9E6B6A1E6ADA6E599A8E380825D5B5D0D0A0D0AE59CA82433323839333364E58685E5868DE6ACA1E68C89E4B88BE6B395E5A49CE8BE93E781B5E4BC9AE9878AE694BEE6B395E5A49CE8BE93E781B5E980A0E68890E79A84E68980E69C89E4BCA4E5AEB3E79A8424733125EFBC8CE4B8BA243332383933304131E7A081E58685E887B3E5A49A243332383933307332E5908DE79B9FE58F8BE681A2E5A48DE7949FE591BDE580BCE380820000, 40944),
(3776013982, 101546, 'zhCN', 0x00E59CA8E7A9BAE4B8ADE696BDE5B195E59B9EE6978BE8B8A2EFBC8CE59CA82464E58685E5AFB9243130373237304131E7A081E88C83E59BB4E58685E79A84E68980E69C89E6958CE4BABAE980A0E68890243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5DE782B9E789A9E79086E4BCA4E5AEB3E38082E79BAEE6A087E695B0E9878FE8B685E8BF87247331E4B8AAE5908EE980A0E68890E79A84E4BCA4E5AEB3E9998DE4BD8EE38082243F63335B0D0A0D0AE59CA8E4B98BE5898DE79A842432323033353864E58685EFBC8CE4BDA0E6AF8FE794A8E78C9BE8998EE68E8CE38081E5B9BBE781ADE8B8A2E68896E697ADE697A5E4B89CE58D87E8B8A2E587BBE4B8ADE4B880E4B8AAE4B88DE5908CE79A84E79BAEE6A087EFBC8CE5B0B1E4BC9AE4BDBFE7A59EE9B9A4E5BC95E9A1B9E8B8A2E79A84E4BCA4E5AEB3E68F90E9AB9824323230333538733125E38082E58FAFE4BBA5E58FA0E58AA02432323832383769E6ACA1E380825D5B5D00E6AF8F243130313534367431E7A792E5AFB9E99984E8BF91E6958CE4BABAE980A0E68890E4B880E6ACA1E789A9E79086E4BCA4E5AEB3E3808200, 40944),
(3865974254, 188220, 'zhCN', 0x00000000, 40944),
(3865974254, 187900, 'zhCN', 0x00000000, 40944),
(3865974254, 187899, 'zhCN', 0x00000000, 40944),
(3865974254, 187898, 'zhCN', 0x00000000, 40944),
(3865974254, 187897, 'zhCN', 0x00000000, 40944),
(3865974254, 187896, 'zhCN', 0x00000000, 40944),
(3865974254, 187895, 'zhCN', 0x00000000, 40944),
(3865974254, 187875, 'zhCN', 0x00000000, 40944),
(3865974254, 187869, 'zhCN', 0x00000000, 40944),
(3865974254, 150746, 'zhCN', 0x00000000, 40944),
(3865974254, 150745, 'zhCN', 0x00000000, 40944),
(3865974254, 150744, 'zhCN', 0x00000000, 40944),
(3865974254, 150743, 'zhCN', 0x00000000, 40944),
(3776013982, 364944, 'zhCN', 0x0000E7A7BBE58AA8E9809FE5BAA6E68F90E9AB9824733125E3808200, 40944),
(3776013982, 228462, 'zhCN', 0x00E4BDBFE4BDA0E79A84E887AAE58AA8E694BBE587BBE4BCA4E5AEB3E68F90E9AB98247331E782B9E380820000, 40944),
(3776013982, 119611, 'zhCN', 0x0024407370656C6C6465736331313531353100E6AF8F247431E7A792E681A2E5A48D247731E782B9E7949FE591BDE580BCE3808200, 40944),
(3776013982, 119607, 'zhCN', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'zhCN', 0x00000000, 40944),
(1181150530, 403396, 'zhCN', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'zhCN', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'zhCN', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'zhCN', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'zhCN', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'zhCN', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'zhCN', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'zhCN', 0xA4530000, 40944),
(3359787322, 21411, 'zhCN', 0xA3530000, 40944),
(3359787322, 21410, 'zhCN', 0xA2530000, 40944),
(3359787322, 21409, 'zhCN', 0xA1530000, 40944),
(3359787322, 21408, 'zhCN', 0xA0530000, 40944),
(3359787322, 21407, 'zhCN', 0x9F530000, 40944),
(3359787322, 21406, 'zhCN', 0x9E530000, 40944),
(2557447376, 655518, 'zhCN', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'zhCN', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'zhCN', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'zhCN', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'zhCN', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'zhCN', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F45464645435400E7BB8FE585B8E58886E9858DE8A784E58899E4B88DE5868DE7949FE69588E380820001, 40944),
(3776013982, 347944, 'zhCN', 0x00E78886E587BBE587A0E78E87E68F90E9AB9824733125E380820D0A00E78886E587BBE587A0E78E87E68F90E9AB9824733125E3808200, 40944),
(3776013982, 347943, 'zhCN', 0x00E69C80E5A4A7E7949FE591BDE580BCE68F90E9AB9824733125E380820D0A00E69C80E5A4A7E7949FE591BDE580BCE68F90E9AB9824733125E3808200, 40944),
(3776013982, 1714, 'zhCN', 0x00E5BCBAE8BFABE79BAEE6A087E4BDBFE794A8E681B6E9AD94E8AFADEFBC8CE4BDBFE585B6E68980E69C89E6B395E69CAFE79A84E696BDE694BEE697B6E997B4E5BBB6E995BF24733125EFBC8CE68C81E7BBAD2464E38082243F733130333131325B0D0A0D0A7C434646453535424230E781B5E9AD82E78783E783A7EFBC9AE4BDA0E79A84E8AFADE8A880E8AF85E59292E4BC9AE5BDB1E5938DE4BDA0E79BAEE6A087E591A8E59BB4E58D8AE5BE842431303432323441E7A081E88C83E59BB4E58685E79A84E68980E69C89E6958CE4BABAE380827C525D5B5D0D0A0D0A7C634646383238324646E8AF85E59292EFBC9AE5AFB9E4BA8EE4B880E4B8AAE79BAEE6A087EFBC8CE6AF8FE4B8AAE69CAFE5A3ABE58FAAE883BDE696BDE58AA0E4B880E7A78DE8AF85E59292E380827C7200E4BBA5E681B6E9AD94E8AFADE5BFB5E587BAE59292E8AFADEFBC8CE4BDBFE696BDE6B395E697B6E997B4E5BBB6E995BF24773125E3808200, 40944),
(3205218938, 41865, 'zhCN', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E5300E4BDA0E6B2A1E69C89E7BC96E8BE91E68B9BE58B9FE4BFA1E681AFE79A84E69D83E99990E380820001, 40944),
(261693969, 64850, 'zhCN', 0xFFFFFFFFFFFFFFFFE7BAB5E8B4AFE68998E58AA0E696AFE789B9000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'zhCN', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='zhCN') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='zhCN');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'zhCN' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `achievement_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (14775,14752,14682,14351));
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14775, 'zhTW', '取得瑪拉茲莫斯的聲望崇拜。', '備受青睞', '頭銜獎勵：有趣的小夥子/有趣的小姑娘', 40944),
(14752, 'zhTW', '完成下列憎惡縫合術成就。', '死後必做清單', '頭銜獎勵：令人憎惡，獎勵：裝甲天選者牛獸坐騎', 40944),
(14682, 'zhTW', '完成下列的餘燼宴會成就。', '派對使者', '頭銜獎勵：派對使者', 40944),
(14351, 'zhTW', '擊敗39個晉升之路的首領。', '通往晉升的道路39', '在晉升之路解鎖更多挑戰。', 40944);


DELETE FROM `area_table_locale` WHERE (`VerifiedBuild`>0 AND `ID`=13316 AND `locale`='zhTW');
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(13316, 'zhTW', '祭儀家族', 40944);


DELETE FROM `battle_pet_species_locale` WHERE (`VerifiedBuild`>0 AND `ID`=3188 AND `locale`='zhTW');
INSERT INTO `battle_pet_species_locale` (`ID`, `locale`, `Description_lang`, `SourceText_lang`, `VerifiedBuild`) VALUES
(3188, 'zhTW', '', '', 40944);


DELETE FROM `broadcast_text_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (215513,215512,215511));
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(215513, 'zhTW', '', '未做好事前準備就深入淵喉實非明智之舉，等你準備就緒再來找我。', 40944),
(215512, 'zhTW', '未做好事前準備就深入淵喉實非明智之舉，等你準備就緒再來找我。', '', 40944),
(215511, 'zhTW', '', '目標就在眼前，和我並肩作戰，我們一定能辦到。', 40944);


DELETE FROM `char_titles_locale` WHERE (`VerifiedBuild`>0 AND `ID`=693 AND `locale`='zhTW');
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(693, 'zhTW', '『晉升者』%s', '『晉升者』%s', 40944);


UPDATE `char_titles_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `ID`=683 AND `locale`='zhTW');
DELETE FROM `chr_customization_option_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (1523,689));
INSERT INTO `chr_customization_option_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1523, 'zhTW', '尾巴', 40944),
(689, 'zhTW', '尾巴', 40944);


DELETE FROM `criteria_tree_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (91730,94390,94389,94388,93811,93810,94331,94330));
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91730, 'zhTW', '9.1總成就', 40944),
(94390, 'zhTW', '', 40944),
(94389, 'zhTW', '', 40944),
(94388, 'zhTW', '', 40944),
(93811, 'zhTW', '', 40944),
(93810, 'zhTW', '名望等級80', 40944),
(94331, 'zhTW', '', 40944),
(94330, 'zhTW', 'Renown Level 80 - Kyrian', 40944);


DELETE FROM `item_search_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,116401));
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(151806, 'zhTW', '端莊的晚禮服', 40944),
(151804, 'zhTW', '黑色禮服束褲', 40944),
(151792, 'zhTW', '綠色冬裝', 40944),
(151790, 'zhTW', '紅色冬裝', 40944),
(34685, 'zhTW', '夏日法衣', 40944),
(34683, 'zhTW', '夏日便鞋', 40944),
(34087, 'zhTW', '綠色冬裝', 40944),
(34085, 'zhTW', '紅色冬裝', 40944),
(33969, 'zhTW', '紫色啤酒節紀念帽', 40944),
(33968, 'zhTW', '藍色啤酒節紀念帽', 40944),
(33967, 'zhTW', '綠色啤酒節紀念帽', 40944),
(33966, 'zhTW', '啤酒節軟靴', 40944),
(33868, 'zhTW', '啤酒節靴子', 40944),
(33864, 'zhTW', '棕色啤酒節紀念帽', 40944),
(33863, 'zhTW', '啤酒節裙裝', 40944),
(33862, 'zhTW', '啤酒節華服', 40944),
(23324, 'zhTW', '火焰節慶披肩', 40944),
(21525, 'zhTW', '綠色冬帽', 40944),
(21524, 'zhTW', '紅色冬帽', 40944),
(19028, 'zhTW', '端莊的晚禮服', 40944),
(6835, 'zhTW', '黑色禮服束褲', 40944),
(6833, 'zhTW', '白色禮服襯衣', 40944),
(181321, 'zhTW', '鑲嵌寶石的魔杖', 40944),
(116401, 'zhTW', '精美旅人帽', 40944);


DELETE FROM `item_sparse_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (176922,176921,176832,187935,188152,151806,151804,151792,151790,34685,34683,34087,34085,33969,33968,33967,33966,33868,33864,33863,33862,23324,21525,21524,19028,6835,6833,181321,188220,187900,187899,187898,187897,187896,187895,187875,187869,150746,150745,150744,150743,116401));
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(176922, 'zhTW', '這種魔法花朵會使靈魂重生時提供的製作材料，以及催化種子長出的催化物質數量提高100%。', '', '', '', '野生夜綻花', 40944),
(176921, 'zhTW', '這些魔法樹葉會使重生的野性種子需要的培育時間降低1天。', '', '', '', '時光之葉', 40944),
(176832, 'zhTW', '這種特殊樹根會提高靈魂重生時提供的獎勵品質。', '', '', '', '野性種子根粒', 40944),
(187935, 'zhTW', '教你學會如何銘刻午夜符文雄鹿印記。', '', '', '', '技藝：午夜符文雄鹿印記', 40944),
(188152, 'zhTW', '裂片的魔法摸起來很燙。', '', '', '', '傳送門控制裂片', 40944),
(151806, 'zhTW', '', '', '', '', '端莊的晚禮服', 40944),
(151804, 'zhTW', '', '', '', '', '黑色禮服束褲', 40944),
(151792, 'zhTW', '', '', '', '', '綠色冬裝', 40944),
(151790, 'zhTW', '', '', '', '', '紅色冬裝', 40944),
(34685, 'zhTW', '', '', '', '', '夏日法衣', 40944),
(34683, 'zhTW', '', '', '', '', '夏日便鞋', 40944),
(34087, 'zhTW', '', '', '', '', '綠色冬裝', 40944),
(34085, 'zhTW', '', '', '', '', '紅色冬裝', 40944),
(33969, 'zhTW', '', '', '', '', '紫色啤酒節紀念帽', 40944),
(33968, 'zhTW', '', '', '', '', '藍色啤酒節紀念帽', 40944),
(33967, 'zhTW', '', '', '', '', '綠色啤酒節紀念帽', 40944),
(33966, 'zhTW', '', '', '', '', '啤酒節軟靴', 40944),
(33868, 'zhTW', '', '', '', '', '啤酒節靴子', 40944),
(33864, 'zhTW', '', '', '', '', '棕色啤酒節紀念帽', 40944),
(33863, 'zhTW', '', '', '', '', '啤酒節裙裝', 40944),
(33862, 'zhTW', '', '', '', '', '啤酒節華服', 40944),
(23324, 'zhTW', '', '', '', '', '火焰節慶披肩', 40944),
(21525, 'zhTW', '', '', '', '', '綠色冬帽', 40944),
(21524, 'zhTW', '', '', '', '', '紅色冬帽', 40944),
(19028, 'zhTW', '', '', '', '', '端莊的晚禮服', 40944),
(6835, 'zhTW', '', '', '', '', '黑色禮服束褲', 40944),
(6833, 'zhTW', '', '', '', '', '白色禮服襯衣', 40944),
(181321, 'zhTW', '', '', '', '', '鑲嵌寶石的魔杖', 40944),
(188220, 'zhTW', '底下有「高塔倖存者」的字樣。', '', '', '', '托迦司灰燼晶球', 40944),
(187900, 'zhTW', '一對哥布林和地精搭檔，記下了他們在這兩座島嶼上的許多發現。', '', '', '', '偵察地圖：庫爾提拉斯和贊達拉的奇觀', 40944),
(187899, 'zhTW', '一位充滿冒險精神的煉金師，記下了外域各種獨特且奇妙的動植物生態筆記。', '', '', '', '偵察地圖：多采多姿的外域', 40944),
(187898, 'zhTW', '一份銀白十字軍的詳細報告，列出了對巫妖王展開的種種軍事行動。', '', '', '', '偵察地圖：北裂境戰役的真實代價', 40944),
(187897, 'zhTW', '一份相當難得的跨陣營報告，羅列著無數死亡之翼破壞艾澤拉斯後，所帶來的後果。', '', '', '', '偵察地圖：大災變的後果', 40944),
(187896, 'zhTW', '一個莉莉遊遍潘達利亞的輕鬆冒險故事，還附有老陳叔叔的推薦美食。', '', '', '', '偵察地圖：風暴烈酒的潘達利亞指引', 40944),
(187895, 'zhTW', '一份簡潔的清單，其中包括了德拉諾各地的避難處，還有必須注意的當地風俗。', '', '', '', '偵察地圖：驚險德拉諾', 40944),
(187875, 'zhTW', '在與燃燒軍團作戰期間，來自不同軍事單位的一大批報告與通訊紀錄。', '', '', '', '偵察地圖：破碎群島聯合戰線', 40944),
(187869, 'zhTW', '一位淵喉行者走遍暗影之境四大界域的詳細故事。', '', '', '', '偵察地圖：深入暗影之境', 40944),
(150746, 'zhTW', '即時支援與補給東部王國哨站的謙卑提案。', '', '', '', '偵察地圖：東部王國現代化部屬報告', 40944),
(150745, 'zhTW', '在發生第四次大戰的情況下，快速癱瘓聯盟手下東部王國部隊的綜合策略。', '', '', '', '偵察地圖：東部王國戰役計畫', 40944),
(150744, 'zhTW', '療養邪惡、腐化，還有畸變之徒在大地上造成的瘡疤。', '', '', '', '偵察地圖：與大地之母一起走遍卡林多', 40944),
(150743, 'zhTW', '各種長著獠牙、揮舞利爪、藏有劇毒，還有效忠部落的兇蠻野獸資訊全集。', '', '', '', '偵察地圖：卡林多生存指南', 40944),
(116401, 'zhTW', '', '', '', '', '精美旅人帽', 40944);


UPDATE `item_sparse_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (185950,185947,185946));
DELETE FROM `lfg_dungeons_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1445 AND `locale`='zhTW');
INSERT INTO `lfg_dungeons_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1445, 'zhTW', '魔化圖騰的落敗', '阻止圖加‧血圖騰和他手下的魔化蟲毀滅整座山。', 40944);


DELETE FROM `map_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1756 AND `locale`='zhTW');
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(1756, 'zhTW', '克羅米之死', '', '', '', '', 40944);


DELETE FROM `player_condition_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (95078,95077,95076,85644,73006,73005,87365,85912,85910,85909,85692,94517,94516,94515,94514,94513,94512,94511));
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(95078, 'zhTW', '', 40944),
(95077, 'zhTW', '', 40944),
(95076, 'zhTW', '', 40944),
(85644, 'zhTW', '必須達到$pcMinLevel級才能繼續。', 40944),
(73006, 'zhTW', '', 40944),
(73005, 'zhTW', '', 40944),
(87365, 'zhTW', '', 40944),
(85912, 'zhTW', '', 40944),
(85910, 'zhTW', '', 40944),
(85909, 'zhTW', '', 40944),
(85692, 'zhTW', '', 40944),
(94517, 'zhTW', '', 40944),
(94516, 'zhTW', '', 40944),
(94515, 'zhTW', '', 40944),
(94514, 'zhTW', '', 40944),
(94513, 'zhTW', '', 40944),
(94512, 'zhTW', '', 40944),
(94511, 'zhTW', '', 40944);


DELETE FROM `spell_category_locale` WHERE (`VerifiedBuild`>0 AND `ID`=1186 AND `locale`='zhTW');
INSERT INTO `spell_category_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1186, 'zhTW', 'Class - Paladin - Hand of Sacrifice', 40944);


DELETE FROM `spell_name_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (361952,256817,247692,247111,247110,247104,247103,247099,247096,247094,247093,247092,247089,247088,228844,227799,227780,362986,243328,358927,53385,329902,307934,307480,365080,317920,465,357407,357406,357405,356631,328923,101546,364944,228462,119611,119607,347944,347943,1714));
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(361952, 'zhTW', '1000個靈魄', 40944),
(256817, 'zhTW', '阿曼蘇爾印記', 40944),
(247692, 'zhTW', '時空物品連續性', 40944),
(247111, 'zhTW', 'Blessing of the Bronze Dragonflight Passive', 40944),
(247110, 'zhTW', '無限疾速', 40944),
(247104, 'zhTW', 'Acceleration Passive', 40944),
(247103, 'zhTW', 'Time Stop Passive', 40944),
(247099, 'zhTW', 'Chrono Charisma Passive', 40944),
(247096, 'zhTW', 'Rapid Recovery Passive', 40944),
(247094, 'zhTW', '幸運', 40944),
(247093, 'zhTW', 'Dragon\'s Determination Passive', 40944),
(247092, 'zhTW', 'Accelerated Aggression Passive', 40944),
(247089, 'zhTW', 'Dragon Crash Passive', 40944),
(247088, 'zhTW', '洞察', 40944),
(228844, 'zhTW', '燃燒的骸骨', 40944),
(227799, 'zhTW', '洗淨一切', 40944),
(227780, 'zhTW', '雷霆儀式', 40944),
(362986, 'zhTW', '經驗值', 40944),
(243328, 'zhTW', '漸隱術', 40944),
(358927, 'zhTW', '夜裔守衛的警戒', 40944),
(53385, 'zhTW', '神性風暴', 40944),
(329902, 'zhTW', '挖掘', 40944),
(307934, 'zhTW', '挖掘', 40944),
(307480, 'zhTW', '投擲泥掘者', 40944),
(365080, 'zhTW', '御風而行', 40944),
(317920, 'zhTW', '專注光環', 40944),
(465, 'zhTW', '虔誠光環', 40944),
(357407, 'zhTW', '召喚哈瓦剋', 40944),
(357406, 'zhTW', '召喚戰履車', 40944),
(357405, 'zhTW', '召喚沙塵魔', 40944),
(356631, 'zhTW', '召喚破空刃', 40944),
(328923, 'zhTW', '妖精汲血', 40944),
(101546, 'zhTW', '鶴旋踢', 40944),
(364944, 'zhTW', '御風而行', 40944),
(228462, 'zhTW', '梅朗卓斯的璽戒', 40944),
(119611, 'zhTW', '回生迷霧', 40944),
(119607, 'zhTW', '回生迷霧', 40944),
(347944, 'zhTW', '奧伯隆尖刺', 40944),
(347943, 'zhTW', '奧伯隆耐力', 40944),
(1714, 'zhTW', '語言詛咒', 40944);


DELETE FROM `transmog_set_locale` WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (2289,2287,2283,2281,2277,2275,2271,2269,2178));
INSERT INTO `transmog_set_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(2289, 'zhTW', '無束鬥士鎧甲', 40944),
(2287, 'zhTW', '無束鬥士鎧甲', 40944),
(2283, 'zhTW', '無束鬥士鍊甲', 40944),
(2281, 'zhTW', '無束鬥士鍊甲', 40944),
(2277, 'zhTW', '無束鬥士皮甲', 40944),
(2275, 'zhTW', '無束鬥士皮甲', 40944),
(2271, 'zhTW', '無束鬥士法衣', 40944),
(2269, 'zhTW', '無束鬥士法衣', 40944),
(2178, 'zhTW', '縫合大師的武器', 40944);


UPDATE `transmog_set_locale` SET `VerifiedBuild`=40944 WHERE (`VerifiedBuild`>0 AND `locale`='zhTW' AND `ID` IN (2221,2220,2219,2218,2217,2216,2215,2214,2213,2212,2211,2210,2209,2208,2207,2206,2205,2204,2203,2202));
DELETE FROM `achievement_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `achievement_category_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_journal_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `adventure_map_poi_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `area_table_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `artifact_appearance_set_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `auction_house_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `azerite_essence_power_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `barber_shop_style_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battle_pet_species_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `battlemaster_list_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `char_titles_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chat_channels_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_classes_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_choice_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_customization_option_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_races_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `chr_specialization_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_family_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `creature_type_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `criteria_tree_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_types_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `currency_container_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `difficulty_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `dungeon_encounter_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `faction_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_rep_reaction_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `friendship_reputation_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `gameobjects_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_ability_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_building_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_class_spec_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_follower_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `garr_mission_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `heirloom_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_bag_family_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_class_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_limit_category_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_name_description_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_search_name_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_set_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `item_sparse_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_encounter_section_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_instance_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `journal_tier_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `keystone_affix_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `languages_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `lfg_dungeons_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mail_template_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_challenge_mode_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `map_difficulty_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `mount_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `prestige_level_info_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_talent_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `pvp_tier_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `quest_sort_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `scenario_step_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `skill_line_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `specialization_spells_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_category_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_focus_object_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_item_enchantment_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_name_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_range_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `spell_shapeshift_form_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `talent_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `taxi_nodes_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `totem_category_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `toy_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `transmog_set_group_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `ui_map_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `unit_power_bar_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
DELETE FROM `wmo_area_table_locale` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);

DELETE FROM `hotfix_blob` WHERE (`TableHash`=2948698321 AND `RecordId`=340 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=65165 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=361952 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=256817 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247692 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247111 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247110 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247104 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247103 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247099 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247096 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247094 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247093 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247092 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247089 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=247088 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9040 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9039 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9038 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9037 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9036 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9035 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9034 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9033 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9032 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9031 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9030 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9029 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9028 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9027 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9026 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9025 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9024 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9023 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9022 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9021 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9020 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9019 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9018 AND `locale`='zhTW') OR (`TableHash`=3479059991 AND `RecordId`=9017 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=228844 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=227799 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=227780 AND `locale`='zhTW') OR (`TableHash`=3386291891 AND `RecordId`=116804 AND `locale`='zhTW') OR (`TableHash`=3386291891 AND `RecordId`=115510 AND `locale`='zhTW') OR (`TableHash`=3386291891 AND `RecordId`=115491 AND `locale`='zhTW') OR (`TableHash`=3386291891 AND `RecordId`=115427 AND `locale`='zhTW') OR (`TableHash`=3386291891 AND `RecordId`=115426 AND `locale`='zhTW') OR (`TableHash`=3386291891 AND `RecordId`=114462 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=362986 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=60399 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=60396 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=60392 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=60381 AND `locale`='zhTW') OR (`TableHash`=2202435563 AND `RecordId`=1022281 AND `locale`='zhTW') OR (`TableHash`=2202435563 AND `RecordId`=1016248 AND `locale`='zhTW') OR (`TableHash`=2921112328 AND `RecordId`=474530 AND `locale`='zhTW') OR (`TableHash`=2921112328 AND `RecordId`=472639 AND `locale`='zhTW') OR (`TableHash`=69094805 AND `RecordId`=161 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=176922 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=176921 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=176832 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=243328 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=187935 AND `locale`='zhTW') OR (`TableHash`=3205218938 AND `RecordId`=44300 AND `locale`='zhTW') OR (`TableHash`=3205218938 AND `RecordId`=44299 AND `locale`='zhTW') OR (`TableHash`=3205218938 AND `RecordId`=44284 AND `locale`='zhTW') OR (`TableHash`=3205218938 AND `RecordId`=44283 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=358927 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=188152 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=53385 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=62694 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=62693 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=62692 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=62691 AND `locale`='zhTW') OR (`TableHash`=4146370265 AND `RecordId`=98678 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=329902 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=307934 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=307480 AND `locale`='zhTW') OR (`TableHash`=2948698321 AND `RecordId`=354 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=60111 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=60110 AND `locale`='zhTW') OR (`TableHash`=4033975491 AND `RecordId`=439711 AND `locale`='zhTW') OR (`TableHash`=4033975491 AND `RecordId`=439689 AND `locale`='zhTW') OR (`TableHash`=4033975491 AND `RecordId`=439644 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=151806 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=151804 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=151792 AND `locale`='zhTW') OR (`TableHash`=3037505077 AND `RecordId`=151792 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=151790 AND `locale`='zhTW') OR (`TableHash`=3037505077 AND `RecordId`=151790 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=146306 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=34685 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=34683 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=34087 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=34085 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=33969 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=33968 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=33967 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=33966 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=33868 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=33864 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=33863 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=33862 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=23324 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=21525 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=21524 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=19028 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=6835 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=6833 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=181321 AND `locale`='zhTW') OR (`TableHash`=1548466975 AND `RecordId`=27672 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=365080 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=317920 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=465 AND `locale`='zhTW') OR (`TableHash`=3205218938 AND `RecordId`=44172 AND `locale`='zhTW') OR (`TableHash`=3205218938 AND `RecordId`=40887 AND `locale`='zhTW') OR (`TableHash`=3205218938 AND `RecordId`=40885 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=357407 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=357406 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=357405 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=356631 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=328923 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=101546 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=188220 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=187900 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=187899 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=187898 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=187897 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=187896 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=187895 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=187875 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=187869 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=150746 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=150745 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=150744 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=150743 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=364944 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=228462 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=119611 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=119607 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=116401 AND `locale`='zhTW') OR (`TableHash`=1181150530 AND `RecordId`=403396 AND `locale`='zhTW') OR (`TableHash`=859088734 AND `RecordId`=384877 AND `locale`='zhTW') OR (`TableHash`=2202435563 AND `RecordId`=1021176 AND `locale`='zhTW') OR (`TableHash`=2921112328 AND `RecordId`=474214 AND `locale`='zhTW') OR (`TableHash`=600565378 AND `RecordId`=181149 AND `locale`='zhTW') OR (`TableHash`=3386943305 AND `RecordId`=121848 AND `locale`='zhTW') OR (`TableHash`=1369604944 AND `RecordId`=5712 AND `locale`='zhTW') OR (`TableHash`=3359787322 AND `RecordId`=21412 AND `locale`='zhTW') OR (`TableHash`=3359787322 AND `RecordId`=21411 AND `locale`='zhTW') OR (`TableHash`=3359787322 AND `RecordId`=21410 AND `locale`='zhTW') OR (`TableHash`=3359787322 AND `RecordId`=21409 AND `locale`='zhTW') OR (`TableHash`=3359787322 AND `RecordId`=21408 AND `locale`='zhTW') OR (`TableHash`=3359787322 AND `RecordId`=21407 AND `locale`='zhTW') OR (`TableHash`=3359787322 AND `RecordId`=21406 AND `locale`='zhTW') OR (`TableHash`=2557447376 AND `RecordId`=655518 AND `locale`='zhTW') OR (`TableHash`=2557447376 AND `RecordId`=655517 AND `locale`='zhTW') OR (`TableHash`=2557447376 AND `RecordId`=655516 AND `locale`='zhTW') OR (`TableHash`=2557447376 AND `RecordId`=655515 AND `locale`='zhTW') OR (`TableHash`=604774165 AND `RecordId`=29725 AND `locale`='zhTW') OR (`TableHash`=3205218938 AND `RecordId`=48675 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=347944 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=347943 AND `locale`='zhTW') OR (`TableHash`=3776013982 AND `RecordId`=1714 AND `locale`='zhTW') OR (`TableHash`=3205218938 AND `RecordId`=41865 AND `locale`='zhTW') OR (`TableHash`=261693969 AND `RecordId`=64850 AND `locale`='zhTW') OR (`TableHash`=2948698321 AND `RecordId`=285 AND `locale`='zhTW');
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(2948698321, 340, 'zhTW', 0xA53E23C86B3D8F59, 40944),
(261693969, 65165, 'zhTW', 0xFFFFFFFFFFFFFFFFE99D88E9AD82E694AFE68FB4000044AC546F010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000000000008006002002000000002000080F5000091EA000000000000, 40944),
(3776013982, 361952, 'zhTW', 0x00E696B0E5A29E247331E5808BE99D88E9AD84E588B0E4BDA0E79BAEE5898DE8AA93E79B9FE79A84E99D88E9AD84E5BAABE380820000, 40944),
(3776013982, 256817, 'zhTW', 0x00E4BDA0E79A84E6B395E8A193E5928CE68A80E883BDE69C89E4B880E5AE9AE6A99FE78E87E4BDBFE4BDA0E79A84E9809FE5BAA6E38081E8BFB4E981BFE5928CE6B1B2E58F96E68F90E9AB98243235363831387331E9BB9EEFBC8CE68C81E7BA8C2432353638313864E380820D0A0D0A7C634646464646464646E998BFE69BBCE89887E788BEE79A84E5B08AE6A6AE7C720D0AE58F97E588B0E890ACE7A59EE6AEBFE79A84E5BCB7E58C96E69982EFBC8CE4BDA0E79A84243F28613133373030357C613133373034377C613133373032387C61313337303237295BE58A9BE9878F5D3F28613231323631317C613133373031317C613133373031307C613133373031347C613133373032337C613133373032357C613133373033347C61313337303431295BE6958FE68DB75D5BE699BAE58A9B5DE68F90E9AB98243235363833327331E9BB9EEFBC8CE68C81E7BA8C2432353638333264E380820000, 40944),
(3776013982, 247692, 'zhTW', 0x00E4BDA0E69C89E8BC83E9AB98E79A84E6A99FE78E87E5BE9EE69982E99693E4B98BE6B299E78DB2E5BE97E69982E58589E6B581E9809DE789A9E59381E7AEB1E38082E69982E58589E6B581E9809DE789A9E59381E7AEB1E590ABE69C89E5BCB7E5A4A7E79A84E789A9E59381EFBC8CE58FAFE4BBA5E9A1AFE89197E9998DE4BD8EE69982E7A9BAE68C91E688B0E79A84E99BA3E5BAA6E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E7A7BBE58B95E9809FE5BAA6E5928CE59D90E9A88EE9809FE5BAA6E68F90E9AB9824733225E3808200E4BDA0E69C89E8BC83E9AB98E79A84E6A99FE78E87E5BE9EE69982E99693E4B98BE6B299E78DB2E5BE97E69982E58589E6B581E9809DE789A9E59381E7AEB1E38082E69982E58589E6B581E9809DE789A9E59381E7AEB1E590ABE69C89E5BCB7E5A4A7E79A84E789A9E59381EFBC8CE58FAFE4BBA5E9A1AFE89197E9998DE4BD8EE69982E7A9BAE68C91E688B0E79A84E99BA3E5BAA6E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E7A7BBE58B95E9809FE5BAA6E5928CE59D90E9A88EE9809FE5BAA6E68F90E9AB9824733225E3808200, 40944),
(3776013982, 247111, 'zhTW', 0x00E4BDA0E69C89E8BC83E9AB98E79A84E6A99FE78E87E5BE9EE69982E99693E4B98BE6B299E78DB2E5BE97E99D92E98A85E9BE8DE38082E98099E6A29DE9BE8DE69C83E7AB8BE58DB3E782BAE4BDA0E6B885E79086E4B880E5BAA7E9BE8DE6AEBFE380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E582B7E5AEB3E5928CE7949FE591BDE58A9BE68F90E9AB9824733225E3808200E4BDA0E69C89E8BC83E9AB98E79A84E6A99FE78E87E5BE9EE69982E99693E4B98BE6B299E78DB2E5BE97E99D92E98A85E9BE8DE38082E98099E6A29DE9BE8DE69C83E7AB8BE58DB3E782BAE4BDA0E6B885E79086E4B880E5BAA7E9BE8DE6AEBFE380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E582B7E5AEB3E5928CE7949FE591BDE58A9BE68F90E9AB9824733225E3808200, 40944),
(3776013982, 247110, 'zhTW', 0x00E8A7A3E98E96E5BE9EE9BE8DE79CA0E7A59EE6AEBFE9809AE5BE80E68980E69C89E9BE8DE6AEBFE79A84E582B3E98081E99680E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E7A7BBE58B95E9809FE5BAA6E5928CE59D90E9A88EE9809FE5BAA6E68F90E9AB9824733225E3808200E8A7A3E98E96E5BE9EE9BE8DE79CA0E7A59EE6AEBFE9809AE5BE80E68980E69C89E9BE8DE6AEBFE79A84E582B3E98081E99680E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E7A7BBE58B95E9809FE5BAA6E5928CE59D90E9A88EE9809FE5BAA6E68F90E9AB9824733225E3808200, 40944),
(3776013982, 247104, 'zhTW', 0x00E7A7BBE58B95E9809FE5BAA6E5928CE59D90E9A88EE9809FE5BAA6E68F90E9AB9824733125E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E582B7E5AEB3E5928CE7949FE591BDE58A9BE68F90E9AB9824733225E3808200E7A7BBE58B95E9809FE5BAA6E5928CE59D90E9A88EE9809FE5BAA6E68F90E9AB9824733125E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E582B7E5AEB3E5928CE7949FE591BDE58A9BE68F90E9AB9824733225E3808200, 40944),
(3776013982, 247103, 'zhTW', 0x0024407370656C6C646573633234343935390D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E980A0E68890E79A84E582B7E5AEB3E5928CE6B2BBE79982E69588E69E9CE68F90E9AB983525E380820000, 40944),
(3776013982, 247099, 'zhTW', 0x00E4BDA0E5BE9EE6AEBAE6ADBBE695B5E4BABAE78DB2E5BE97E79A84E5858BE7BE85E7B1B3E881B2E69C9BE59CA8E69C80E5BE8C2432343737363964E68F90E9AB9824323437373639733125EFBC8CE59CA8E69C80E5BE8C2432343737373064E68F90E9AB9824323437373730733125E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E7A7BBE58B95E9809FE5BAA6E5928CE59D90E9A88EE9809FE5BAA6E68F90E9AB9824733225E380820000, 40944),
(3776013982, 247096, 'zhTW', 0x000000, 40944),
(3776013982, 247094, 'zhTW', 0x00E5B08BE5BE97E69982E99693E4B98BE6B299E79A84E6A99FE78E87E68F90E9AB9824733125E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E7949FE591BDE58A9BE68F90E9AB9824733225E3808200E4BDA0E5B08BE5BE97E69982E99693E4B98BE6B299E79A84E6A99FE78E87E68F90E9AB9824733125E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E7949FE591BDE58A9BE68F90E9AB9824733225E3808200, 40944),
(3776013982, 247093, 'zhTW', 0x000000, 40944),
(3776013982, 247092, 'zhTW', 0x000000, 40944),
(3776013982, 247089, 'zhTW', 0x0024407370656C6C646573633234353530330D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E582B7E5AEB3E38081E6B2BBE79982E69588E69E9CE38081E7949FE591BDE58A9BE38081E7A7BBE58B95E9809FE5BAA6E5928CE59D90E9A88EE9809FE5BAA6E983BDE68F90E9AB9824733225E380820000, 40944),
(3776013982, 247088, 'zhTW', 0x00E5858BE7BE85E7B1B3E69C83E9A1AFE7A4BAE99984E8BF91E79A84E5AFB6E7AEB1E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E582B7E5AEB3E5928CE6B2BBE79982E69588E69E9CE68F90E9AB9824733225E3808200E5858BE7BE85E7B1B3E69C83E9A1AFE7A4BAE99984E8BF91E79A84E5AFB6E7AEB1E380820D0A0D0A7C634646303046463030E9A18DE5A496E78D8EE58BB5EFBC9A7C72E582B7E5AEB3E5928CE6B2BBE79982E69588E69E9CE68F90E9AB9824733225E3808200, 40944),
(3479059991, 9040, 'zhTW', 0x000000000000000050230000970000001602000000000000B5020000020000000000000000000000, 40944),
(3479059991, 9039, 'zhTW', 0x00000000000000004F230000970000001602000000000000B5020000010000000000000000000000, 40944),
(3479059991, 9038, 'zhTW', 0x00000000000000004E230000970000001F02000000000000BD020000020000000000000000000000, 40944),
(3479059991, 9037, 'zhTW', 0x00000000000000004D230000970000001F02000000000000BD020000010000000000000000000000, 40944),
(3479059991, 9036, 'zhTW', 0x00000000000000004C230000970000002002000000000000BE020000020000000000000000000000, 40944),
(3479059991, 9035, 'zhTW', 0x00000000000000004B230000970000002002000000000000BE020000010000000000000000000000, 40944),
(3479059991, 9034, 'zhTW', 0x00000000000000004A230000970000002102000000000000BF020000020000000000000000000000, 40944),
(3479059991, 9033, 'zhTW', 0x000000000000000049230000970000002102000000000000BF020000010000000000000000000000, 40944),
(3479059991, 9032, 'zhTW', 0x000000000000000048230000970000001C02000000000000BA020000020000000000000000000000, 40944),
(3479059991, 9031, 'zhTW', 0x000000000000000047230000970000001C02000000000000BA020000010000000000000000000000, 40944),
(3479059991, 9030, 'zhTW', 0x000000000000000046230000970000002202000000000000C0020000020000000000000000000000, 40944),
(3479059991, 9029, 'zhTW', 0x000000000000000045230000970000002202000000000000C0020000010000000000000000000000, 40944),
(3479059991, 9028, 'zhTW', 0x000000000000000044230000970000001A02000000000000B9020000020000000000000000000000, 40944),
(3479059991, 9027, 'zhTW', 0x000000000000000043230000970000001A02000000000000B9020000010000000000000000000000, 40944),
(3479059991, 9026, 'zhTW', 0x000000000000000042230000970000001902000000000000B8020000020000000000000000000000, 40944),
(3479059991, 9025, 'zhTW', 0x000000000000000041230000970000001902000000000000B8020000010000000000000000000000, 40944),
(3479059991, 9024, 'zhTW', 0x000000000000000040230000970000001802000000000000B7020000020000000000000000000000, 40944),
(3479059991, 9023, 'zhTW', 0x00000000000000003F230000970000001802000000000000B7020000010000000000000000000000, 40944),
(3479059991, 9022, 'zhTW', 0x00000000000000003E230000970000001702000000000000B6020000020000000000000000000000, 40944),
(3479059991, 9021, 'zhTW', 0x00000000000000003D230000970000001702000000000000B6020000010000000000000000000000, 40944),
(3479059991, 9020, 'zhTW', 0x00000000000000003C230000970000001E02000000000000BC020000020000000000000000000000, 40944),
(3479059991, 9019, 'zhTW', 0x00000000000000003B230000970000001E02000000000000BC020000010000000000000000000000, 40944),
(3479059991, 9018, 'zhTW', 0x00000000000000003A230000970000001D02000000000000BB020000020000000000000000000000, 40944),
(3479059991, 9017, 'zhTW', 0x000000000000000039230000970000001D02000000000000BB020000010000000000000000000000, 40944),
(3776013982, 228844, 'zhTW', 0x0024407370656C6C6465736332323838323900E6AF8F243232383832397431E7A792E58F97E588B0247331E9BB9EE781ABE784B0E582B7E5AEB3E3808200, 40944),
(3776013982, 227799, 'zhTW', 0x00E6B581E6B0B4E6B5AAE6BDAEE5BE9EE688BFE99693E59B9BE591A8E8A5B2E68DB2E8808CE4BE86EFBC8CE5B08DE7A2B0E6929EE588B0E79A84E78EA9E5AEB6E980A0E68890247331E9BB9EE586B0E99C9CE582B7E5AEB3E380820000, 40944),
(3776013982, 227780, 'zhTW', 0x00E4BBA524407370656C6C6E616D65323237373830E6A899E8A898E68980E69C89E78EA9E5AEB6E38082E69588E69E9CE7B590E69D9FE5BE8CE5B08DE99984E8BF91244131E7A2BCE7AF84E59C8DE585A7E68980E69C89E78EA9E5AEB6E980A0E68890247331E9BB9EE887AAE784B6E582B7E5AEB3E3808200E69588E69E9CE7B590E69D9FE5BE8CE5B08DE99984E8BF91244131E7A2BCE7AF84E59C8DE585A7E79A84E68980E69C89E78EA9E5AEB6E980A0E68890247331E9BB9EE887AAE784B6E582B7E5AEB3E3808200, 40944),
(3386291891, 116804, 'zhTW', 0xE5A0B4E699AFE6BC94E593A100000000000A00000066040000A62D00000000000000000000000000000000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115510, 'zhTW', 0xE5A4A7E6B395E5B8ABE58DA1E5BEB7E58AA0000000000008000003227F00000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115491, 'zhTW', 0xE9BAA5E8BFAAE696870000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115427, 'zhTW', 0xE881B6E68B89E696AFE280A7E59F83E898AD0000000001070000004C2001000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 115426, 'zhTW', 0xE9BAA5E8BFAAE696870000000001070000001E4900000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3386291891, 114462, 'zhTW', 0xE9A4A8E995B7000000000109000000C94100000000000000000000000000000000803F0000803F0000803F0000803F000000000000000000000000, 40944),
(3776013982, 362986, 'zhTW', 0x00E68993E9968BE4BDA0E79A84E5A4A5E4BCB4E9A081E99DA2EFBC8CE981B8E69387E4B880E4BD8DE5A4A5E4BCB4E4B8A6E5B087E585B6E58D87E887B3E7AD89E7B49A247331E380820000, 40944),
(261693969, 60399, 'zhTW', 0xFFFFFFFFFFFFFFFFE68FB4E58AA9E7919EE69687E5B494E696AF00003C9BFD4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000497C00000F0100000C0800000000000002000000000108060000000000000000E3F400000000000000000000, 40944),
(261693969, 60396, 'zhTW', 0xFFFFFFFFFFFFFFFFE68FB4E58AA9E791AAE58D93E896A9E696AF00003D9BFC4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000487C00000F0100000C0800000000000002000000000108060000000000000000E6F400000000000000000000, 40944),
(261693969, 60392, 'zhTW', 0xFFFFFFFFFFFFFFFFE68FB4E58AA9E69887E99D88E5A0A100003E9BFB4B010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000477C00000F0100000C0800000000000002000000000108060000000000000000E4F400000000000000000000, 40944),
(261693969, 60381, 'zhTW', 0xFFFFFFFFFFFFFFFFE68FB4E58AA9E4BA9EE799BBE69BA0E9878E00003B9BFE4B010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000004A7C00000F0100000C0800000000000002000000000108060000000000000000E5F400000000000000000000, 40944),
(2202435563, 1022281, 'zhTW', 0x49990F00B4F892059314A23D0700, 40944),
(2202435563, 1016248, 'zhTW', 0xB8810F00B7F8950593143F360700, 40944),
(2921112328, 474530, 'zhTW', 0xA23D0700AE08860600000109FE000020000000000000000000000000000000, 40944),
(2921112328, 472639, 'zhTW', 0x3F360700AE08860600000109FE0000FFFFFFFF000000000000000000000000, 40944),
(69094805, 161, 'zhTW', 0x00A960010000000000000000007E000000, 40944),
(3865974254, 176922, 'zhTW', 0x00000000, 40944),
(3865974254, 176921, 'zhTW', 0x00000000, 40944),
(3865974254, 176832, 'zhTW', 0x00000000, 40944),
(3776013982, 243328, 'zhTW', 0x0000E9998DE4BD8EE5A881E88485E580BCE3808200, 40944),
(3865974254, 187935, 'zhTW', 0x00000000, 40944),
(3205218938, 44300, 'zhTW', 0x4C46475F41555448454E54494341544F525F4445534352495054494F4E5F424F5800E782BAE4BDA0E79A84E5B8B3E8999FE58AA0E4B88AE9A997E8AD89E599A8E5928C534D53E7B0A1E8A88AE5AE89E585A8E9809AE79FA5E4BBA5E8A7A3E98E96E6ADA4E6AC84E4BD8D0001, 40944),
(3205218938, 44299, 'zhTW', 0x4C46475F41555448454E54494341544F525F425554544F4E5F4D59544849435F504C55535F544F4F4C544950007C636666666630303030E999A4E99D9EE4BDA0E4BDBFE794A8426174746C652E6E6574E9A997E8AD89E599A8E5928C534D53E7B0A1E8A88AE5AE89E585A8E9809AE79FA5E4BE86E4BF9DE8ADB7E5B8B3E8999FEFBC8CE590A6E58987E4BDA0E784A1E6B395E59CA8E6B292E69C89E991B0E79FB3E79A84E78B80E6B381E4B88BEFBC8CE799BCE5B883E582B3E5A587E991B0E79FB3E99BA3E5BAA6E99A8AE4BC8D7C727C6E7C6366663165666630303CE9BB9EE6938AE6ADA4E89995E4BA86E8A7A3E69BB4E5A49AE8A9B3E7B4B0E8B387E8A88A3E7C720001, 40944),
(3205218938, 44284, 'zhTW', 0x4C46475F41555448454E54494341544F525F425554544F4E5F544F4F4C544950007C636666666630303030E999A4E99D9EE4BDA0E4BDBFE794A8426174746C652E6E6574E9A997E8AD89E599A8E5928C534D53E7B0A1E8A88AE5AE89E585A8E9809AE79FA5E4BE86E4BF9DE8ADB7E5B8B3E8999FEFBC8CE590A6E58987E4BDA0E784A1E6B395E7B7A8E8BCAFE6ADA4E6AC84E4BD8D7C727C6E7C6366663165666630303CE9BB9EE6938AE6ADA4E89995E4BA86E8A7A3E69BB4E5A49AE8A9B3E7B4B0E8B387E8A88A3E7C720001, 40944),
(3205218938, 44283, 'zhTW', 0x47524F55505F46494E4445525F41555448454E54494341544F525F504F5055505F4445534300E782BAE4BDA0E79A84E5B8B3E8999FE58AA0E4B88AE9A997E8AD89E599A8E5928C534D53E7B0A1E8A88AE5AE89E585A8E9809AE79FA5EFBC8CE8A7A3E98E96E99A8AE4BC8DE6909CE5B08BE599A8E79A84E5AE8CE695B4E58A9FE883BDE380827C6E426174746C652E6E6574E9A997E8AD89E599A8E698AFE4B880E5808BE5858DE8B2BBE38081E5A5BDE794A8E79A84E69C8DE58B99EFBC8CE58FAFE4BBA5E4BF9DE8ADB7E4BDA0E79A84E5B8B3E8999FE4B88DE8A2ABE585A5E4BEB5EFBC8CE8808CE4B894E59CA8E5B8B3E8999FE696B9E99DA2E980B2E8A18CE9878DE8A681E69BB4E696B0E69982EFBC8CE4BDA0E69C83E694B6E588B0534D53E7B0A1E8A88AE5AE89E585A8E9809AE79FA5E380827C6E7C6EE9BB9EE6938AE3808CE5959FE58B95E3808DE4BBA5E9968BE5959FE9A997E8AD89E599A8E8A8ADE5AE9AE7B6B2E7AB99E380820001, 40944),
(3776013982, 358927, 'zhTW', 0x00E4BDA0E5B08DE591A8E59C8DE79A84E792B0E5A283E8AE8AE5BE97E9A18DE5A496E8ADA6E68892E38082E5A49CE8A394E7B2BEE99D88E4BDBFE794A8E69982E586B7E58DBBE69982E99693E9998DE4BD8EE3808200E687B7E79691E4BDA0E8BAABE9828AE585B6E4BB96E4BABAE79A84E8BAABE4BBBDE3808200, 40944),
(3865974254, 188152, 'zhTW', 0x00000000, 40944),
(3776013982, 53385, 'zhTW', 0x00E9878BE694BEE4B880E999A3E6978BE9A2A8E888ACE79A84E7A59EE88196E883BDE9878FEFBC8CE5B08DE99984E8BF91E68980E69C89E695B5E4BABAE980A0E68890247331E9BB9EE7A59EE88196E582B7E5AEB3E38082E8B685E9818E247332E5808BE79BAEE6A899E69982EFBC8CE980A0E68890E79A84E582B7E5AEB3E9998DE4BD8EE380820000, 40944),
(261693969, 62694, 'zhTW', 0xFFFFFFFFFFFFFFFFE791AAE58D93E896A9E696AFE79A84E591BCE5969A000032ADD811010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C080000000000000200000000013006000000000000000073F50000EBF4000000000000, 40944),
(261693969, 62693, 'zhTW', 0xFFFFFFFFFFFFFFFFE4BA9EE799BBE69BA0E9878EE79A84E591BCE5969A000031ADD711010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000000000000E9F40000EBF4000000000000, 40944),
(261693969, 62692, 'zhTW', 0xFFFFFFFFFFFFFFFFE69887E99D88E5A0A1E79A84E591BCE5969A000033ADD511010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000EAF40000EBF4000000000000, 40944),
(261693969, 62691, 'zhTW', 0xFFFFFFFFFFFFFFFFE7919EE69687E5B494E696AFE79A84E591BCE5969A000034ADD611010000000000FFFF01000200000000000000000000000000000000000000000000000000000000000000000000000000000000000F0100000C0800000000000002000000000130060000000008000000E7F40000EBF4000000000000, 40944),
(4146370265, 98678, 'zhTW', 0x0000000000000000000000000000000000000000000000000000000000000000FF14000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(3776013982, 329902, 'zhTW', 0x000000, 40944),
(3776013982, 307934, 'zhTW', 0x000000, 40944),
(3776013982, 307480, 'zhTW', 0x00E68B8BE587BAE5B0B1E7B792E79A84E6B3A5E68E98E88085E380820000, 40944),
(2948698321, 354, 'zhTW', 0x64DF8D9146629CB2, 40944),
(261693969, 60111, 'zhTW', 0xFFFFFFFFFFFFFFFFE5BBBAE7AB8BE58F8BE8AABC00005B9AD811010000000000FFFF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000450300000000000002000000000060020020000000020000C6F300000000000000000000, 40944),
(261693969, 60110, 'zhTW', 0xFFFFFFFFFFFFFFFFE5898DE68980E69CAAE69C89E79A84E79FA5E5BF83E5A5BDE58F8B00005A9AD811010000000000FFFF01000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000045030000000000000200000000006002002000000002000091EA000030E1000000000000, 40944),
(4033975491, 439711, 'zhTW', 0x0000000000000000000000000000000000000000000000006A960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(4033975491, 439689, 'zhTW', 0x00000000000000000000000000000000000000000000000026950000FFFFFFFF00000000000000000000000000000000000000000000000000000000CDCC8C3E00000000FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000CB2A0200, 40944),
(4033975491, 439644, 'zhTW', 0x00000000000000000000000000000000000000000000000068960000FFFFFFFF0000000000000000000000000000000000000000000000000000000085EB513F00000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000057320200, 40944),
(3865974254, 151806, 'zhTW', 0x00000000, 40944),
(3865974254, 151804, 'zhTW', 0x00000000, 40944),
(3865974254, 151792, 'zhTW', 0x00000000, 40944),
(3037505077, 151792, 'zhTW', 0x0100, 40944),
(3865974254, 151790, 'zhTW', 0x00000000, 40944),
(3037505077, 151790, 'zhTW', 0x0100, 40944),
(3865974254, 146306, 'zhTW', 0x00000000, 40944),
(3865974254, 34685, 'zhTW', 0x00000000, 40944),
(3865974254, 34683, 'zhTW', 0x00000000, 40944),
(3865974254, 34087, 'zhTW', 0x00000000, 40944),
(3865974254, 34085, 'zhTW', 0x00000000, 40944),
(3865974254, 33969, 'zhTW', 0x00000000, 40944),
(3865974254, 33968, 'zhTW', 0x00000000, 40944),
(3865974254, 33967, 'zhTW', 0x00000000, 40944),
(3865974254, 33966, 'zhTW', 0x00000000, 40944),
(3865974254, 33868, 'zhTW', 0x00000000, 40944),
(3865974254, 33864, 'zhTW', 0x00000000, 40944),
(3865974254, 33863, 'zhTW', 0x00000000, 40944),
(3865974254, 33862, 'zhTW', 0x00000000, 40944),
(3865974254, 23324, 'zhTW', 0x00000000, 40944),
(3865974254, 21525, 'zhTW', 0x00000000, 40944),
(3865974254, 21524, 'zhTW', 0x00000000, 40944),
(3865974254, 19028, 'zhTW', 0x00000000, 40944),
(3865974254, 6835, 'zhTW', 0x00000000, 40944),
(3865974254, 6833, 'zhTW', 0x00000000, 40944),
(3865974254, 181321, 'zhTW', 0x00000000, 40944),
(1548466975, 27672, 'zhTW', 0x10040000, 40944),
(3776013982, 365080, 'zhTW', 0x0000E7A7BBE58B95E9809FE5BAA6E68F90E9AB9824733125E3808200, 40944),
(3776013982, 317920, 'zhTW', 0x00246131E7A2BCE7AF84E59C8DE585A7E99A8AE4BC8DE88887E59C98E99A8AE68890E593A1E58F97E588B0E79A84E4B8ADE696B7E5928CE6B289E9BB98E69588E69E9CE7B8AEE79FAD24733125E38082243F733333393132345BE58F97E588B0E79A84E68190E687BCE69588E69E9CE4B99FE69C83E7B8AEE79FADE380825D5B5D00E4B8ADE696B7E5928CE6B289E9BB98E69588E69E9CE7B8AEE79FAD24773125E38082243F733333393132345BE68190E687BCE69588E69E9CE7B8AEE79FAD24773425E380825D5B5D00, 40944),
(3776013982, 465, 'zhTW', 0x00246131E7A2BCE7AF84E59C8DE585A7E79A84E99A8AE4BC8DE88887E59C98E99A8AE68890E593A1E58F97E588B0E89994E8AAA0E79A84E6BF80E58BB5EFBC8CE4BDBFE585B6E58F97E588B0E79A84E582B7E5AEB3E9998DE4BD8E24733125E3808200E58F97E588B0E79A84E582B7E5AEB3E9998DE4BD8E24773125E3808200, 40944),
(3205218938, 44172, 'zhTW', 0x5056505F52414E4B5F385F4E4558545F52414E4B5F4445534300E98194E588B031393530E4BBA5E4B88AE7A98DE58886E58FAFE78DB2E5BE97EFBC9A7C6E2D507650E789A9E59381E58D87E7B49AE7AD89E7B49A0001, 40944),
(3205218938, 40887, 'zhTW', 0x5056505F52414E4B5F335F4E4558545F52414E4B5F4445534300E98194E588B031383030E4BBA5E4B88AE7A98DE58886E58FAFE78DB2E5BE97EFBC9A7C6E2DE7ABB6E788ADE88085E7A8B1E8999F7C6E2DE7B2BEE88BB1507650E5A597E8A39DE5A496E8A780EFBC9AE9A0ADE983A87C6E2DE7B2BEE88BB1507650E5A597E8A39DE5A496E8A780EFBC9AE882A9E983A80001, 40944),
(3205218938, 40885, 'zhTW', 0x5056505F52414E4B5F325F4E4558545F52414E4B5F4445534300E98194E588B031343030E4BBA5E4B88AE7A98DE58886E58FAFE78DB2E5BE97EFBC9A7C6E2DE68C91E688B0E88085E7A8B1E8999F7C6E2DE7B2BEE88BB1507650E5A597E8A39DE5A496E8A780EFBC9AE6898BE5A5977C6E2DE7B2BEE88BB1507650E5A597E8A39DE5A496E8A780EFBC9AE885B3E983A80001, 40944),
(3776013982, 357407, 'zhTW', 0x00E58FACE5969AE4B8A6E68EA7E588B6E4BDA0E79A84E69096E6BBBEE8B3BDE8BB8AEFBC9AE68EA0E5A5AAE88085E3808200E4BDBFE794A8E4BDA0E79A84E5BFABE68DB7E58897E4BE86E694BBE6938AE585B6E4BB96E78EA9E585B7E3808200, 40944),
(3776013982, 357406, 'zhTW', 0x00E58FACE5969AE4B8A6E68EA7E588B6E4BDA0E79A84E69096E6BBBEE8B3BDE8BB8AEFBC9AE68EA0E5A5AAE88085E3808200E4BDBFE794A8E4BDA0E79A84E5BFABE68DB7E58897E4BE86E694BBE6938AE585B6E4BB96E78EA9E585B7E3808200, 40944),
(3776013982, 357405, 'zhTW', 0x00E58FACE5969AE4B8A6E68EA7E588B6E4BDA0E79A84E69096E6BBBEE8B3BDE8BB8AEFBC9AE68EA0E5A5AAE88085E3808200E4BDBFE794A8E4BDA0E79A84E5BFABE68DB7E58897E4BE86E694BBE6938AE585B6E4BB96E78EA9E585B7E3808200, 40944),
(3776013982, 356631, 'zhTW', 0x00E58FACE5969AE4B8A6E68EA7E588B6E4BDA0E79A84E69096E6BBBEE8B3BDE8BB8AEFBC9AE7A0B4E7A9BAE58883E3808200E4BDBFE794A8E4BDA0E79A84E5BFABE68DB7E58897E4BE86E694BBE6938AE585B6E4BB96E78EA9E585B7E3808200, 40944),
(3776013982, 328923, 'zhTW', 0xE69A97E5A49CE5A696E7B2BE00E8BD89E7A7BBE79BAEE6A899E58D80E59F9FE585A7E69C80E5A49A2433323839323849E5908DE695B5E4BABAE79A84E7949FE591BDE4B98BE58A9BEFBC8CE59CA82464E585A7E980A0E68890247B282433323839323873312A24642F24743229202B202433323839323873317DE9BB9EE887AAE784B6E582B7E5AEB3EFBC8CE794B1E6AF8FE5908DE695B5E696B9E79BAEE6A899E5B9B3E59D87E58886E694A4E38082243F613133373034315B0D0A0D0AE5A696E7B2BEE6B1B2E8A180E79A84E5BC95E5B08EE5AE8CE585A8E7B590E69D9FE5BE8CEFBC8CE794A2E7949F247334E5B1A4E6B0A3E6BCA9E6ADA6E599A8E380825D5B5D0D0A0D0AE59CA82433323839333364E585A7E5868DE6ACA1E68C89E4B88BE5A696E7B2BEE6B1B2E8A180EFBC8CE5B0B1E69C83E9878BE694BEE5A696E7B2BEE6B1B2E8A180E68980E69C89E582B7E5AEB3E79A8424733125EFBC8CE6B2BBE79982243332383933304131E7A2BCE7AF84E59C8DE585A7E69C80E5A49A243332383933307332E5908DE79B9FE58F8BE380820000, 40944),
(3776013982, 101546, 'zhTW', 0x00E9A8B0E7A9BAE8BFB4E8BAABE8B8A2E6938AEFBC8CE59CA82464E585A7EFBC8CE5B08D243130373237304131E7A2BCE7AF84E59C8DE585A7E79A84E68980E69C89E695B5E4BABAE980A0E68890243F733133373032355B247B342A2431303732373073312A243C4341503E2F2441507D5D5B247B342A2431303732373073317D5DE9BB9EE789A9E79086E582B7E5AEB3E38082E8B685E9818E247331E5808BE79BAEE6A899E69982EFBC8CE980A0E68890E79A84E582B7E5AEB3E9998DE4BD8EE38082243F63335B0D0A0D0AE59CA8E9818EE58EBBE79A842432323033353864E585A7EFBC8CE4BBA5E8998EE68E8CE38081E6BB85E5AF82E885BFE68896E698AFE7BF94E999BDE885B3E6AF8FE6938AE4B8ADE4B880E5808BE79BAEE6A899EFBC8CE9B6B4E6978BE8B8A2E980A0E68890E79A84E582B7E5AEB3E5B0B1E68F90E9AB9824323230333538733125E38082E69C80E5A49AE58FAFE5A086E7968A2432323832383769E6ACA1E380825D5B5D00E694BBE6938AE99984E8BF91E79A84E695B5E4BABAEFBC8CE6AF8F243130313534367431E7A792E980A0E68890E789A9E79086E582B7E5AEB3E3808200, 40944),
(3865974254, 188220, 'zhTW', 0x00000000, 40944),
(3865974254, 187900, 'zhTW', 0x00000000, 40944),
(3865974254, 187899, 'zhTW', 0x00000000, 40944),
(3865974254, 187898, 'zhTW', 0x00000000, 40944),
(3865974254, 187897, 'zhTW', 0x00000000, 40944),
(3865974254, 187896, 'zhTW', 0x00000000, 40944),
(3865974254, 187895, 'zhTW', 0x00000000, 40944),
(3865974254, 187875, 'zhTW', 0x00000000, 40944),
(3865974254, 187869, 'zhTW', 0x00000000, 40944),
(3865974254, 150746, 'zhTW', 0x00000000, 40944),
(3865974254, 150745, 'zhTW', 0x00000000, 40944),
(3865974254, 150744, 'zhTW', 0x00000000, 40944),
(3865974254, 150743, 'zhTW', 0x00000000, 40944),
(3776013982, 364944, 'zhTW', 0x0000E7A7BBE58B95E9809FE5BAA6E68F90E9AB9824733125E3808200, 40944),
(3776013982, 228462, 'zhTW', 0x00E4BDA0E79A84E887AAE58B95E694BBE6938AE582B7E5AEB3E68F90E9AB98E68F90E9AB9824733125E380820000, 40944),
(3776013982, 119611, 'zhTW', 0x0024407370656C6C6465736331313531353100E6AF8F247431E7A792E681A2E5BEA9247731E9BB9EE7949FE591BDE58A9BE3808200, 40944),
(3776013982, 119607, 'zhTW', 0x0024407370656C6C646573633131353135310000, 40944),
(3865974254, 116401, 'zhTW', 0x00000000, 40944),
(1181150530, 403396, 'zhTW', 0x060000006DDF0500374B0200, 40944),
(859088734, 384877, 'zhTW', 0xFFFFFFFF7B0000000000, 40944),
(2202435563, 1021176, 'zhTW', 0xF8940F00FA0038011F01663C0700, 40944),
(2921112328, 474214, 'zhTW', 0x663C07003B097E060000010000000000000000000000000000000000000000, 40944),
(600565378, 181149, 'zhTW', 0x7D2301000000803F0000C03F006FCC0100, 40944),
(3386943305, 121848, 'zhTW', 0x00000000000000002300FF04000060000810000000000000000000000000000000010000000001000000000000006FCC0100, 40944),
(1369604944, 5712, 'zhTW', 0x0000003F0000000000000000000000000000000000000000501600002A1C00000000012200000000000000002C010000EE0204020000000000000000000000000061140000, 40944),
(3359787322, 21412, 'zhTW', 0xA4530000, 40944),
(3359787322, 21411, 'zhTW', 0xA3530000, 40944),
(3359787322, 21410, 'zhTW', 0xA2530000, 40944),
(3359787322, 21409, 'zhTW', 0xA1530000, 40944),
(3359787322, 21408, 'zhTW', 0xA0530000, 40944),
(3359787322, 21407, 'zhTW', 0x9F530000, 40944),
(3359787322, 21406, 'zhTW', 0x9E530000, 40944),
(2557447376, 655518, 'zhTW', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004E0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655517, 'zhTW', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 40944),
(2557447376, 655516, 'zhTW', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004D0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(2557447376, 655515, 'zhTW', 0x000000000000000000000000000000000000000000000000000000000000000000000000F6040000000000004F0901000000000000000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006D0100006D010000, 40944),
(604774165, 29725, 'zhTW', 0x1C00000000006D010000, 40944),
(3205218938, 48675, 'zhTW', 0x4C45474143595F4C4F4F545F52554C45535F4E4F545F494E5F45464645435400E7B693E585B8E68BBEE58F96E8A68FE58987E4B88DE981A9E794A8E380820001, 40944),
(3776013982, 347944, 'zhTW', 0x00E887B4E591BDE4B880E6938AE6A99FE78E87E68F90E9AB9824733125E3808200E887B4E591BDE4B880E6938AE6A99FE78E87E68F90E9AB9824733125E3808200, 40944),
(3776013982, 347943, 'zhTW', 0x00E7949FE591BDE58A9BE4B88AE99990E68F90E9AB9824733125E3808200E7949FE591BDE58A9BE4B88AE99990E68F90E9AB9824733125E3808200, 40944),
(3776013982, 1714, 'zhTW', 0x00E5BCB7E8BFABE79BAEE6A899E4BDBFE794A8E683A1E9AD94E8AA9EEFBC8CE4BDBFE585B6E68980E69C89E6B395E8A193E79A84E696BDE6B395E69982E99693E5BBB6E995B724733125EFBC8CE68C81E7BA8C2464E38082243F733130333131325B0D0A0D0A7C434646453535424230E99D88E9AD82E78299E78783EFBC9AE4BDA0E79A84E8AA9EE8A880E8A99BE59292E69C83E5BDB1E99FBFE4BDA0E79BAEE6A899E591A8E59C8D2431303432323441E7A2BCE7AF84E59C8DE585A7E79A84E68980E69C89E695B5E4BABAE380827C525D5B5D0D0A0D0A7C634646383238324646E8A99BE59292EFBC9AE6AF8FE5808BE8A193E5A3ABE58FAAE883BDE5B08DE4B880E5808BE79BAEE6A899E696BDE58AA0E4B880E7A8AEE8A99BE59292E380827C7200E4BBA5E683A1E9AD94E8AA9EE696BDE5B195E6B395E8A193EFBC8CE696BDE6B395E69982E99693E5BBB6E995B724773125E3808200, 40944),
(3205218938, 41865, 'zhTW', 0x434C55425F46494E4445525F4E4F5F52454352554954494E475F5045524D495353494F4E5300E4BDA0E6B292E69C89E7B7A8E8BCAFE68B9BE58B9FE8B387E8A88AE79A84E6AC8AE99990E380820001, 40944),
(261693969, 64850, 'zhTW', 0xFFFFFFFFFFFFFFFFE69AA2E9818AE68998E8BFA6E58FB8000033ABD253010000000000FFFF010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000AB0600000000000002000000001170020000000008020000000000000000000000000000, 40944),
(2948698321, 285, 'zhTW', 0xB6D04A691282734A, 40944);


UPDATE `hotfix_blob` SET `VerifiedBuild`=40944 WHERE (`TableHash`=3865974254 AND `RecordId`=185950 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=185947 AND `locale`='zhTW') OR (`TableHash`=3865974254 AND `RecordId`=185946 AND `locale`='zhTW');
DELETE FROM `hotfix_blob` WHERE (`locale`= 'zhTW' AND `VerifiedBuild`>0 AND `VerifiedBuild`<40944);
