DELETE FROM `item` WHERE `ID` = 87487;
INSERT INTO `item` (`ID`, `ClassID`, `SubclassID`, `Material`, `InventoryType`, `SheatheType`, `SoundOverrideSubclassID`, `IconFileDataID`, `ItemGroupSoundsID`, `VerifiedBuild`) VALUES
(87487, 4, 6, 6, 14, 4, -1, 642581, 9, 34769);

DELETE FROM `hotfix_blob` WHERE `TableHash` = 3359787322 AND `RecordId` = 19748;
DELETE FROM `hotfix_blob` WHERE `TableHash` = 600565378 AND `RecordId` = 263696;
DELETE FROM `hotfix_blob` WHERE `TableHash` = 600565378 AND `RecordId` = 263695;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `Blob`, `VerifiedBuild`) VALUES
(3359787322, 19748, 0x244D0000, 34769),
(600565378, 263696, 0xE4FA00000000803F0000803F0140A00200, 34769),
(600565378, 263695, 0xA9000000000000000000803F0040A00200, 34769);

DELETE FROM `dungeon_encounter` WHERE `ID` = 609;
INSERT INTO `dungeon_encounter` (`Name`, `ID`, `MapID`, `DifficultyID`, `OrderIndex`, `CompleteWorldStateID`, `Bit`, `CreatureDisplayID`, `Flags`, `SpellIconFileID`, `Faction`, `VerifiedBuild`) VALUES
('Illidan Stormrage', 609, 564, 0, 8000, 4794, 8, 21135, 7, 0, -1, 34769);

DELETE FROM `hotfix_data` WHERE `Id` = 56309 AND `TableHash` = 3037505077 AND `RecordId` = 175062;
DELETE FROM `hotfix_data` WHERE `Id` = 56309 AND `TableHash` = 2442913102 AND `RecordId` = 175062;
DELETE FROM `hotfix_data` WHERE `Id` = 56309 AND `TableHash` = 1417785224 AND `RecordId` = 175062;
DELETE FROM `hotfix_data` WHERE `Id` = 56309 AND `TableHash` = 1344507586 AND `RecordId` = 175062;
DELETE FROM `hotfix_data` WHERE `Id` = 56309 AND `TableHash` = 428746933 AND `RecordId` = 175062;

DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 159307;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 159299;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 159296;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 159279;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 159222;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 159029;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 159027;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 158745;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 158731;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 158557;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 158553;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 158010;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 157805;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 157653;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 157629;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 157622;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 157510;
DELETE FROM `hotfix_data` WHERE `Id` = 56749 AND `TableHash` = 3386943305 AND `RecordId` = 157506;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 4030871717 AND `RecordId` = 833250;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 4030871717 AND `RecordId` = 833249;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 3776013982 AND `RecordId` = 336170;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 3776013982 AND `RecordId` = 336169;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 3322146344 AND `RecordId` = 433240;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 3322146344 AND `RecordId` = 433239;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 3146089301 AND `RecordId` = 6833;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 3108775943 AND `RecordId` = 83150;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 3037505077 AND `RecordId` = 175062;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 2442913102 AND `RecordId` = 175062;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 1876974313 AND `RecordId` = 61131;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 1417785224 AND `RecordId` = 175062;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 1344507586 AND `RecordId` = 175062;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 1187407512 AND `RecordId` = 336170;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 1187407512 AND `RecordId` = 336169;
DELETE FROM `hotfix_data` WHERE `Id` = 56748 AND `TableHash` = 428746933 AND `RecordId` = 175062;
DELETE FROM `hotfix_data` WHERE `Id` = 56747 AND `TableHash` = 2712461791 AND `RecordId` = 11678;
DELETE FROM `hotfix_data` WHERE `Id` = 56747 AND `TableHash` = 2712461791 AND `RecordId` = 1154;
DELETE FROM `hotfix_data` WHERE `Id` = 56747 AND `TableHash` = 2124448848 AND `RecordId` = 11678;
DELETE FROM `hotfix_data` WHERE `Id` = 56747 AND `TableHash` = 2124448848 AND `RecordId` = 1154;
DELETE FROM `hotfix_data` WHERE `Id` = 56742 AND `TableHash` = 1255424668 AND `RecordId` = 39910;
DELETE FROM `hotfix_data` WHERE `Id` = 56742 AND `TableHash` = 1255424668 AND `RecordId` = 39909;
DELETE FROM `hotfix_data` WHERE `Id` = 56742 AND `TableHash` = 1255424668 AND `RecordId` = 39908;
DELETE FROM `hotfix_data` WHERE `Id` = 56742 AND `TableHash` = 1255424668 AND `RecordId` = 39907;
DELETE FROM `hotfix_data` WHERE `Id` = 56742 AND `TableHash` = 1255424668 AND `RecordId` = 39906;
DELETE FROM `hotfix_data` WHERE `Id` = 56742 AND `TableHash` = 1255424668 AND `RecordId` = 39905;
DELETE FROM `hotfix_data` WHERE `Id` = 56741 AND `TableHash` = 4218319612 AND `RecordId` = 609;
DELETE FROM `hotfix_data` WHERE `Id` = 56741 AND `TableHash` = 3386943305 AND `RecordId` = 193601;
DELETE FROM `hotfix_data` WHERE `Id` = 56741 AND `TableHash` = 3386291891 AND `RecordId` = 172096;
DELETE FROM `hotfix_data` WHERE `Id` = 56741 AND `TableHash` = 3359787322 AND `RecordId` = 19748;
DELETE FROM `hotfix_data` WHERE `Id` = 56741 AND `TableHash` = 600565378 AND `RecordId` = 263696;
DELETE FROM `hotfix_data` WHERE `Id` = 56741 AND `TableHash` = 600565378 AND `RecordId` = 263695;
DELETE FROM `hotfix_data` WHERE `Id` = 56741 AND `TableHash` = 492039028 AND `RecordId` = 32737;
DELETE FROM `hotfix_data` WHERE `Id` = 56716 AND `TableHash` = 3834752085 AND `RecordId` = 45208;
DELETE FROM `hotfix_data` WHERE `Id` = 56716 AND `TableHash` = 3645674820 AND `RecordId` = 45208;
DELETE FROM `hotfix_data` WHERE `Id` = 56716 AND `TableHash` = 3037505077 AND `RecordId` = 87487;
DELETE FROM `hotfix_data` WHERE `Id` = 56716 AND `TableHash` = 2442913102 AND `RecordId` = 87487;
DELETE FROM `hotfix_data` WHERE `Id` = 56716 AND `TableHash` = 1417785224 AND `RecordId` = 87487;
DELETE FROM `hotfix_data` WHERE `Id` = 56716 AND `TableHash` = 1344507586 AND `RecordId` = 87487;
DELETE FROM `hotfix_data` WHERE `Id` = 56716 AND `TableHash` = 428746933 AND `RecordId` = 87487;
DELETE FROM `hotfix_data` WHERE `Id` = 56710 AND `TableHash` = 4030871717 AND `RecordId` = 737563;
INSERT INTO `hotfix_data` (`Id`, `TableHash`, `RecordId`, `Deleted`, `VerifiedBuild`) VALUES 
(56749, 3386943305, 159307, 1, 34769),
(56749, 3386943305, 159299, 1, 34769),
(56749, 3386943305, 159296, 1, 34769),
(56749, 3386943305, 159279, 1, 34769),
(56749, 3386943305, 159222, 1, 34769),
(56749, 3386943305, 159029, 1, 34769),
(56749, 3386943305, 159027, 1, 34769),
(56749, 3386943305, 158745, 1, 34769),
(56749, 3386943305, 158731, 1, 34769),
(56749, 3386943305, 158557, 1, 34769),
(56749, 3386943305, 158553, 1, 34769),
(56749, 3386943305, 158010, 1, 34769),
(56749, 3386943305, 157805, 1, 34769),
(56749, 3386943305, 157653, 1, 34769),
(56749, 3386943305, 157629, 1, 34769),
(56749, 3386943305, 157622, 1, 34769),
(56749, 3386943305, 157510, 1, 34769),
(56749, 3386943305, 157506, 1, 34769),
(56748, 4030871717, 833250, 1, 34769),
(56748, 4030871717, 833249, 1, 34769),
(56748, 3776013982, 336170, 1, 34769),
(56748, 3776013982, 336169, 1, 34769),
(56748, 3322146344, 433240, 1, 34769),
(56748, 3322146344, 433239, 1, 34769),
(56748, 3146089301, 6833, 0, 34769),
(56748, 3108775943, 83150, 1, 34769),
(56748, 3037505077, 175062, 1, 34769),
(56748, 2442913102, 175062, 0, 34769),
(56748, 1876974313, 61131, 0, 34769),
(56748, 1417785224, 175062, 1, 34769),
(56748, 1344507586, 175062, 0, 34769),
(56748, 1187407512, 336170, 1, 34769),
(56748, 1187407512, 336169, 1, 34769),
(56748, 428746933, 175062, 1, 34769),
(56747, 2712461791, 11678, 0, 34769),
(56747, 2712461791, 1154, 0, 34769),
(56747, 2124448848, 11678, 1, 34769),
(56747, 2124448848, 1154, 1, 34769),
(56742, 1255424668, 39910, 0, 34769),
(56742, 1255424668, 39909, 0, 34769),
(56742, 1255424668, 39908, 0, 34769),
(56742, 1255424668, 39907, 0, 34769),
(56742, 1255424668, 39906, 0, 34769),
(56742, 1255424668, 39905, 1, 34769),
(56741, 4218319612, 609, 0, 34769),
(56741, 3386943305, 193601, 1, 34769),
(56741, 3386291891, 172096, 1, 34769),
(56741, 3359787322, 19748, 0, 34769),
(56741, 600565378, 263696, 0, 34769),
(56741, 600565378, 263695, 0, 34769),
(56741, 492039028, 32737, 0, 34769),
(56716, 3834752085, 45208, 0, 34769),
(56716, 3645674820, 45208, 1, 34769),
(56716, 3037505077, 87487, 1, 34769),
(56716, 2442913102, 87487, 0, 34769),
(56716, 1417785224, 87487, 1, 34769),
(56716, 1344507586, 87487, 0, 34769),
(56716, 428746933, 87487, 0, 34769),
(56710, 4030871717, 737563, 0, 34769);

DELETE FROM `item_search_name` WHERE `ID` = 87487;
INSERT INTO `item_search_name` (`AllowableRace`, `Display`, `ID`, `OverallQualityID`, `ExpansionID`, `MinFactionID`, `MinReputation`, `AllowableClass`, `RequiredLevel`, `RequiredSkill`, `RequiredSkillRank`, `RequiredAbility`, `ItemLevel`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `VerifiedBuild`) VALUES
(-1, 'Shield of Sonorous Resonation', 87487, 3, 4, 0, 0, -1, 85, 0, 0, 0, 116, 0, 8192, 0, 0, 34769);

DELETE FROM `item_sparse` WHERE `ID` = 136605;

UPDATE `item_sparse` SET `Flags1` = 69728 WHERE (`ID` = 175062);

DELETE FROM `item_sparse` WHERE `ID` = 87487;
INSERT INTO `item_sparse` (`ID`, `AllowableRace`, `Description`, `Display3`, `Display2`, `Display1`, `Display`, `DmgVariance`, `DurationInInventory`, `QualityModifier`, `BagFamily`, `ItemRange`, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`, `StatPercentEditor1`, `StatPercentEditor2`, `StatPercentEditor3`, `StatPercentEditor4`, `StatPercentEditor5`, `StatPercentEditor6`, `StatPercentEditor7`, `StatPercentEditor8`, `StatPercentEditor9`, `StatPercentEditor10`, `Stackable`, `MaxCount`, `RequiredAbility`, `SellPrice`, `BuyPrice`, `VendorStackCount`, `PriceVariance`, `PriceRandomValue`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `FactionRelated`, `ItemNameDescriptionID`, `RequiredTransmogHoliday`, `RequiredHoliday`, `LimitCategory`, `GemProperties`, `SocketMatchEnchantmentId`, `TotemCategoryID`, `InstanceBound`, `ZoneBound1`, `ZoneBound2`, `ItemSet`, `LockID`, `StartQuestID`, `PageID`, `ItemDelay`, `ScalingStatDistributionID`, `MinFactionID`, `RequiredSkillRank`, `RequiredSkill`, `ItemLevel`, `AllowableClass`, `ExpansionID`, `ArtifactID`, `SpellWeight`, `SpellWeightCategory`, `SocketType1`, `SocketType2`, `SocketType3`, `SheatheType`, `Material`, `PageMaterialID`, `LanguageID`, `Bonding`, `DamageDamageType`, `StatModifierBonusStat1`, `StatModifierBonusStat2`, `StatModifierBonusStat3`, `StatModifierBonusStat4`, `StatModifierBonusStat5`, `StatModifierBonusStat6`, `StatModifierBonusStat7`, `StatModifierBonusStat8`, `StatModifierBonusStat9`, `StatModifierBonusStat10`, `ContainerSlots`, `MinReputation`, `RequiredPVPMedal`, `RequiredPVPRank`, `RequiredLevel`, `InventoryType`, `OverallQualityID`, `VerifiedBuild`) VALUES
(87487, -1, NULL, NULL, NULL, NULL, 'Shield of Sonorous Resonation', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5259, 7889, 3610, 3332, 0, 16132, 0, 0, 0, 0, 1, 0, 0, 174742, 873710, 1, 1, 1.0371, 0, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 116, -1, 4, 0, 0, 0, 0, 0, 0, 4, 6, 0, 0, 2, 0, 4, 7, 49, 36, -1, 5, -1, -1, -1, -1, 0, 0, 0, 0, 85, 14, 3, 34769);

DELETE FROM `item_currency_cost` WHERE `ID` = 61131;
INSERT INTO `item_currency_cost` (`ID`, `ItemID`, `VerifiedBuild`) VALUES
(61131, 175062, 34769);

DELETE FROM `spell_effect` WHERE `ID` = 737563;
INSERT INTO `spell_effect` (`ID`, `EffectAura`, `DifficultyID`, `EffectIndex`, `Effect`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`, `SpellID`, `VerifiedBuild`) VALUES
(737563, 33, 0, 0, 6, 0, 0, 0, 0, 1, 0, 0, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, -50, 0, 0, 0, 8, 0, 0, 0, 0, 22, 15, 280184, 34769);

DELETE FROM `item_modified_appearance` WHERE `ID` = 45208;
INSERT INTO `item_modified_appearance` (`ID`, `ItemID`, `ItemAppearanceModifierID`, `ItemAppearanceID`, `OrderIndex`, `TransmogSourceTypeEnum`, `VerifiedBuild`) VALUES
(45208, 87487, 0, 19136, 0, 4, 34769);

DELETE FROM `spell_power` WHERE `ID` IN (11678, 1154);
INSERT INTO `spell_power` (`ID`, `OrderIndex`, `ManaCost`, `ManaCostPerLevel`, `ManaPerSecond`, `PowerDisplayID`, `AltPowerBarID`, `PowerCostPct`, `PowerCostMaxPct`, `PowerPctPerSecond`, `PowerType`, `RequiredAuraSpellID`, `OptionalCost`, `SpellID`, `VerifiedBuild`) VALUES
(11678, 0, 0, 0, 0, 0, 0, 1.5, 0, 0, 0, 0, 0, 232670, 34769),
(1154, 0, 0, 0, 0, 0, 0, 1.5, 0, 0, 0, 0, 0, 29722, 34769);

DELETE FROM `tact_key` WHERE `ID` IN (243, 232);

DELETE FROM `world_state_expression` WHERE `ID` = 32737;
INSERT INTO `world_state_expression` (`ID`, `Expression`, `VerifiedBuild`) VALUES
(32737, '0102244D0000000101010000000000', 34769);

DELETE FROM `item_extended_cost` WHERE `ID` = 6833;
INSERT INTO `item_extended_cost` (`ID`, `RequiredArenaRating`, `ArenaBracket`, `Flags`, `MinFactionID`, `MinReputation`, `RequiredAchievement`, `ItemID1`, `ItemID2`, `ItemID3`, `ItemID4`, `ItemID5`, `ItemCount1`, `ItemCount2`, `ItemCount3`, `ItemCount4`, `ItemCount5`, `CurrencyID1`, `CurrencyID2`, `CurrencyID3`, `CurrencyID4`, `CurrencyID5`, `CurrencyCount1`, `CurrencyCount2`, `CurrencyCount3`, `CurrencyCount4`, `CurrencyCount5`, `VerifiedBuild`) VALUES
(6833, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1803, 0, 0, 0, 0, 2000, 0, 0, 0, 0, 34769);

DELETE FROM `criteria_tree` WHERE `ID` IN (39910, 39909, 39908, 39907, 39906);
INSERT INTO `criteria_tree` (`ID`, `Description`, `Parent`, `Amount`, `Operator`, `CriteriaID`, `OrderIndex`, `Flags`, `VerifiedBuild`) VALUES
(39910, 'Defeat Tosan Galaxyfist', 39897, 1, 0, 26301, 10, 0, 34769),
(39909, 'Defeat Taylor Dewland', 39897, 1, 0, 26300, 9, 0, 34769),
(39908, 'Defeat Shani Freezewind', 39897, 1, 0, 26299, 8, 0, 34769),
(39907, 'Defeat Mathias Zunn', 39897, 1, 0, 26298, 7, 0, 34769),
(39906, 'Defeat Malda Brewbelly', 39897, 1, 0, 26297, 6, 0, 34769);
