SET @CGUID := 4000158;
SET @OGUID := 4000090;
SET @SPAWNGROUP := 1259;
SET @ATPROPERTIESID := 86;
SET @ATID := 97;
SET @ATSPAWNID := 100;

DELETE FROM `battleground_template` WHERE `ID`=699;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `Weight`, `Comment`) VALUES
(699, 4059, 4060, 1, 'Temple of Kotmogu');

DELETE FROM `battleground_scripts` WHERE `MapId`=998;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(998, 0, 'battleground_temple_of_kotmogu');

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (20901)) OR (`Id` BETWEEN @ATID+0 AND @ATID+1 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(20901, 0, 0, 56008),
(@ATID+0, 1, 0x1, 0),
(@ATID+1, 1, 0x1, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=1 AND `Id` BETWEEN @ATPROPERTIESID+0 AND @ATPROPERTIESID+2);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `SpellForVisuals`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATPROPERTIESID+0, 1, 20901, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 294534, 'at_bg_temple_of_kotmogu_healing_buff', 0), -- 294534 (PvP Rune Rejuv Visual) (Area: Temple of Kotmogu - Difficulty: 0)
(@ATPROPERTIESID+1, 1, @ATID+0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 33, 47, 5, 33, 47, 5, 0, 0, 0, 'at_bg_temple_of_kotmogu_small_area', 0),
(@ATPROPERTIESID+2, 1, @ATID+1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 50, 50, 0, 0, 0, 0, 0, 0, 0, 'at_bg_temple_of_kotmogu_medium_area', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID+0, @ATPROPERTIESID+1, 1, 998, 1783.4149, 1333.5591, 6, 0, 0, '0', 0, '', 0),
(@ATSPAWNID+1, @ATPROPERTIESID+2, 1, 998, 1783.4149, 1333.5591, 6, 0, 0, '0', 0, '', 0);

DELETE FROM `areatrigger_create_properties_polygon_vertex` WHERE `AreaTriggerCreatePropertiesId`=@ATPROPERTIESID+2 AND `IsCustom` = 1;
INSERT INTO `areatrigger_create_properties_polygon_vertex` (`AreaTriggerCreatePropertiesId`, `IsCustom`, `Idx`, `VerticeX`, `VerticeY`, `VerticeTargetX`, `VerticeTargetY`, `VerifiedBuild`) VALUES
(@ATPROPERTIESID+2, 1, 0, 92.1179, 69.4085, 92.1179, 69.4085, 0),
(@ATPROPERTIESID+2, 1, 1, 73.9366, 69.0472, 73.9366, 69.0472, 0),
(@ATPROPERTIESID+2, 1, 2, 73.8413, 17.3184, 73.8413, 17.3184, 0),
(@ATPROPERTIESID+2, 1, 3, 92.0045, 17.3876, 92.0045, 17.3876, 0),
(@ATPROPERTIESID+2, 1, 4, 92.0495, -17.7164, 92.0495, -17.7164, 0),
(@ATPROPERTIESID+2, 1, 5, 74.4268, -17.853, 74.4268, -17.853, 0),
(@ATPROPERTIESID+2, 1, 6, 74.6484, -69.7833, 74.6484, -69.7833, 0),
(@ATPROPERTIESID+2, 1, 7, 91.9716, -69.4006, 91.9716, -69.4006, 0),
(@ATPROPERTIESID+2, 1, 8, 90.6273, -105.1708, 90.6273, -105.1708, 0),
(@ATPROPERTIESID+2, 1, 9, 46.786, -106.5246, 46.786, -106.5246, 0),
(@ATPROPERTIESID+2, 1, 10, 47.1578, -88.5275, 47.1578, -88.5275, 0),
(@ATPROPERTIESID+2, 1, 11, -48.3885, -86.9149, -48.3885, -86.9149, 0),
(@ATPROPERTIESID+2, 1, 12, -48.1667, -105.1384, -48.1667, -105.1384, 0),
(@ATPROPERTIESID+2, 1, 13, -75.5219, -104.5731, -75.5219, -104.5731, 0),
(@ATPROPERTIESID+2, 1, 14, -90.6104, -88.1041, -90.6104, -88.1041, 0),
(@ATPROPERTIESID+2, 1, 15, -91.9497, -69.7092, -91.9497, -69.7092, 0),
(@ATPROPERTIESID+2, 1, 16, -73.4599, -70.2874, -73.4599, -70.2874, 0),
(@ATPROPERTIESID+2, 1, 17, -73.8389, -17.9033, -73.8389, -17.9033, 0),
(@ATPROPERTIESID+2, 1, 18, -91.0432, -16.3382, -91.0432, -16.3382, 0),
(@ATPROPERTIESID+2, 1, 19, -92.5972, 17.5794, -92.5972, 17.5794, 0),
(@ATPROPERTIESID+2, 1, 20, -74.4894, 17.0945, -74.4894, 17.0945, 0),
(@ATPROPERTIESID+2, 1, 21, -75.2437, 68.0682, -75.2437, 68.0682, 0),
(@ATPROPERTIESID+2, 1, 22, -92.579, 69.0204, -92.579, 69.0204, 0),
(@ATPROPERTIESID+2, 1, 23, -91.5159, 95.6335, -91.5159, 95.6335, 0),
(@ATPROPERTIESID+2, 1, 24, -74.3566, 105.4943, -74.3566, 105.4943, 0),
(@ATPROPERTIESID+2, 1, 25, -45.0121, 105.7158, -45.0121, 105.7158, 0),
(@ATPROPERTIESID+2, 1, 26, -46.5645, 87.2858, -46.5645, 87.2858, 0),
(@ATPROPERTIESID+2, 1, 27, 46.1816, 88.1086, 46.1816, 88.1086, 0),
(@ATPROPERTIESID+2, 1, 28, 46.5614, 106.2678, 46.5614, 106.2678, 0),
(@ATPROPERTIESID+2, 1, 29, 88.2872, 102.5001, 88.2872, 102.5001, 0);

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (7777, 7778);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(7777, 'at_battleground_buffs'),
(7778, 'at_battleground_buffs');

DELETE FROM `graveyard_zone` WHERE `ID` IN (3552, 3553, 4057, 4058);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(3552, 6051, 'Temple of Kotmogu - Alliance Rectangle'),
(3553, 6051, 'Temple of Kotmogu - Horde Rectangle'),
(4057, 6051, 'Temple of Kotmogu - Horde Rectangle 2 (East)'),
(4058, 6051, 'Temple of Kotmogu - Alliance Rectangle 2 (East)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (3552, 3553, 4057, 4058);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `NegativeCondition`, `Comment`) VALUES
(27, 3552, 6051, 0, 6, 469, 0, 0, 'Graveyard - Temple of Kotmogu - Rectangle - Team Alliance'),
(27, 3552, 6051, 0, 23, 6136, 0, 1, 'Graveyard - Temple of Kotmogu - Rectangle - Not in western area'),
(27, 3553, 6051, 0, 6, 67, 0, 0, 'Graveyard - Temple of Kotmogu - Rectangle - Team Horde'),
(27, 3553, 6051, 0, 23, 6136, 0, 1, 'Graveyard - Temple of Kotmogu - Rectangle - Not in western area'),
(27, 4058, 6051, 0, 6, 469, 0, 0, 'Graveyard - Temple of Kotmogu - Rectangle 2 - Team Alliance'),
(27, 4058, 6051, 0, 23, 6061, 0, 1, 'Graveyard - Temple of Kotmogu - Rectangle - Not in eastern area'),
(27, 4057, 6051, 0, 6, 67, 0, 0, 'Graveyard - Temple of Kotmogu - Rectangle 2 - Team Horde'),
(27, 4057, 6051, 0, 23, 6061, 0, 1, 'Graveyard - Temple of Kotmogu - Rectangle - Not in eastern area');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 34 AND `SourceEntry` IN (19442, 18135);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `NegativeCondition`, `Comment`) VALUES
(34, 19442, 0, 0, 1, 116524, 0, 1, 'Satisfy player condition when aura 116524 effect 0 is not present'),
(34, 18135, 0, 0, 6, 469, 0, 0, 'Satisfy player condition when player is alliance'),
(34, 18135, 0, 0, 11, 6964, 1, 0, 'Satisfy player condition when world state 6964 is 1'),
(34, 18135, 0, 0, 11, 6966, 1, 0, 'Satisfy player condition when world state 6966 is 1'),
(34, 18135, 0, 0, 11, 6968, 1, 0, 'Satisfy player condition when world state 6968 is 1'),
(34, 18135, 0, 0, 11, 6970, 1, 0, 'Satisfy player condition when world state 6970 is 1');

DELETE FROM `world_state` WHERE `ID` IN (17388, 6304, 6303, 6714, 6969, 6970, 6717, 6963, 6964, 6715, 6967, 6968, 6716, 6965, 6966);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `Comment`) VALUES
(17388, 1500, '998', 'Temple of Kotmogu - Max Points'),
(6304, 0, '998', 'Temple of Kotmogu - Horde Points'),
(6303, 0, '998', 'Temple of Kotmogu - Alliance Points'),
(6714, 1, '998', 'Temple of Kotmogu - Blue Orb In Base'),
(6969, 0, '998', 'Temple of Kotmogu - Blue Orb Horde'),
(6970, 0, '998', 'Temple of Kotmogu - Blue Orb Alliance'),
(6717, 1, '998', 'Temple of Kotmogu - Orange Orb In Base'),
(6963, 0, '998', 'Temple of Kotmogu - Orange Orb Horde'),
(6964, 0, '998', 'Temple of Kotmogu - Orange Orb Alliance'),
(6715, 1, '998', 'Temple of Kotmogu - Purple Orb In Base'),
(6967, 0, '998', 'Temple of Kotmogu - Purple Orb Horde'),
(6968, 0, '998', 'Temple of Kotmogu - Purple Orb Alliance'),
(6716, 1, '998', 'Temple of Kotmogu - Green Orb In Base'),
(6965, 0, '998', 'Temple of Kotmogu - Green Orb Horde'),
(6966, 0, '998', 'Temple of Kotmogu - Green Orb Alliance');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+3;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP+0, 'Temple of Kotmogu - Green Orb in base', 0x20),
(@SPAWNGROUP+1, 'Temple of Kotmogu - Purple Orb in base', 0x20),
(@SPAWNGROUP+2, 'Temple of Kotmogu - Orange Orb in base', 0x20),
(@SPAWNGROUP+3, 'Temple of Kotmogu - Blue Orb in base', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+3;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP+0, 0, @CGUID+48),
(@SPAWNGROUP+1, 0, @CGUID+49),
(@SPAWNGROUP+2, 0, @CGUID+46),
(@SPAWNGROUP+3, 0, @CGUID+47);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceEntry` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, @SPAWNGROUP+0, 0, 0, 11, 0, 6716, 1, 0, 0, 0, 0, '', 'Temple of Kotmogu - Green Orb - In Base'),
(33, 0, @SPAWNGROUP+1, 0, 0, 11, 0, 6715, 1, 0, 0, 0, 0, '', 'Temple of Kotmogu - Purple Orb - In Base'),
(33, 0, @SPAWNGROUP+2, 0, 0, 11, 0, 6717, 4, 0, 0, 0, 0, '', 'Temple of Kotmogu - Orange Orb - In Base'),
(33, 0, @SPAWNGROUP+3, 0, 0, 11, 0, 6714, 5, 0, 0, 0, 0, '', 'Temple of Kotmogu - Blue Orb - In Base');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_bg_temple_of_kotmogu_orb_of_power_periodic', 'spell_bg_temple_of_kotmogu_power_orb_scale_periodic', 'spell_bg_temple_of_kotmogu_victory_points_periodic_2_points', 'spell_bg_temple_of_kotmogu_victory_points_periodic_4_points', 'spell_bg_temple_of_kotmogu_victory_points_periodic_6_points', 'spell_bg_temple_of_kotmogu_victory_points_kill');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(127163, 'spell_bg_temple_of_kotmogu_power_orb_scale_periodic'),
(112912, 'spell_bg_temple_of_kotmogu_victory_points_periodic_2_points'),
(112913, 'spell_bg_temple_of_kotmogu_victory_points_periodic_4_points'),
(112914, 'spell_bg_temple_of_kotmogu_victory_points_periodic_6_points'),
(112910, 'spell_bg_temple_of_kotmogu_victory_points_kill'),
(121164, 'spell_bg_temple_of_kotmogu_orb_of_power_periodic'),
(121175, 'spell_bg_temple_of_kotmogu_orb_of_power_periodic'),
(121176, 'spell_bg_temple_of_kotmogu_orb_of_power_periodic'),
(121177, 'spell_bg_temple_of_kotmogu_orb_of_power_periodic');

DELETE FROM `spell_area` WHERE `spell` IN (112907, 112054);
INSERT INTO `spell_area` (`spell`, `area`, `gender`, `flags`) VALUES
(112907, 6051, 2, 0x3),
(112054, 6051, 2, 0x3);

DELETE FROM `serverside_spell` WHERE `Id` IN (128768);
DELETE FROM `serverside_spell_effect` WHERE `SpellId` IN (128768);
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(128768, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Powerball Achievement Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(128768, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+53;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1789.7452392578125, 1326.7279052734375, 23.32601547241210937, 3.65703439712524414, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+1, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1763.518310546875, 1323.9095458984375, 18.56777191162109375, 3.577862501144409179, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+2, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1620.6214599609375, 1141.0804443359375, 34.46206283569335937, 3.661552906036376953, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+3, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1773.1240234375, 1277.4849853515625, 33.94271469116210937, 1.26128387451171875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+4, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1828.9891357421875, 1571.6427001953125, 25.85111236572265625, 3.816943883895874023, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+5, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1754.0760498046875, 1316.247802734375, 27.90841102600097656, 3.956035375595092773, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1951.52587890625, 1195.732666015625, 25.29047584533691406, 2.145257949829101562, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1660.266357421875, 1337.1173095703125, 30.370269775390625, 5.643963813781738281, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1650.521484375, 1204.099853515625, 18.99119186401367187, 4.712388992309570312, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 65207, 998, 6051, 6136, '0', '0', 0, 0, 0, 1967.4873046875, 1466.973876953125, 31.45277214050292968, 1.943491697311401367, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+10, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1783.841796875, 1375.753173828125, 23.81683921813964843, 2.95611882209777832, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+11, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1719.7777099609375, 1117.5045166015625, 20.07037734985351562, 5.198012351989746093, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 65207, 998, 6051, 6136, '0', '0', 0, 0, 0, 1623.3663330078125, 1142.5416259765625, 33.99567413330078125, 3.548183679580688476, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+13, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1852.099609375, 1207.2767333984375, 14.74231433868408203, 4.9661102294921875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 65209, 998, 6051, 6136, '0', '0', 0, 0, 0, 1669.6246337890625, 1338.887451171875, 10.44999980926513671, 4.184916496276855468, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+15, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1754.8876953125, 1316.431640625, 29.88301658630371093, 0.73880934715270996, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+16, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1663.8798828125, 1336.5657958984375, 31.68233489990234375, 2.759795904159545898, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1719.1326904296875, 1117.7626953125, 20.08334541320800781, 5.868938922882080078, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 65207, 998, 6051, 6136, '0', '0', 0, 0, 0, 1966.9879150390625, 1468.189697265625, 31.32956314086914062, 2.140692710876464843, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+19, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1783.3472900390625, 1382.4683837890625, 25.10213661193847656, 3.829726457595825195, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1850.5567626953125, 1207.0440673828125, 14.39219284057617187, 4.671327114105224609, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 65207, 998, 6051, 6136, '0', '0', 0, 0, 0, 1623.279541015625, 1142.045166015625, 33.9403533935546875, 3.663904666900634765, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1657.7625732421875, 1489.508056640625, 16.70968246459960937, 4.300419330596923828, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 65209, 998, 6051, 6136, '0', '0', 0, 0, 0, 1639.6875, 1326.4461669921875, 12.25523948669433593, 1.689028263092041015, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+24, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1616.1865234375, 1341.3101806640625, 32.34295654296875, 2.626653909683227539, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1965.7755126953125, 1470.5006103515625, 31.07440185546875, 2.022632122039794921, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1925.7301025390625, 1422.075927734375, 12.36990070343017578, 2.341855525970458984, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 58951, 998, 6051, 6136, '0', '0', 0, 0, 0, 1783.4149169921875, 1333.55908203125, 6.384816169738769531, 1.588249564170837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Trigger (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+28, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1805.071044921875, 1332.92822265625, 23.6486053466796875, 4.87811279296875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+29, 65209, 998, 6051, 6136, '0', '0', 0, 0, 0, 1626.9881591796875, 1325.9010009765625, 10.44999980926513671, 3.896676301956176757, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+30, 65207, 998, 6051, 6136, '0', '0', 0, 0, 0, 1931.859375, 1129.1302490234375, 28.97992706298828125, 5.740293025970458984, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+31, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1933.678466796875, 1127.43994140625, 28.92253494262695312, 5.573817729949951171, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+32, 65209, 998, 6051, 6136, '0', '0', 0, 0, 0, 1628.6978759765625, 1345.28125, 12.37590217590332031, 2.18117690086364746, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+33, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1617.9903564453125, 1336.9093017578125, 32.34294509887695312, 4.434304714202880859, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+34, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1830.947021484375, 1120.5450439453125, 20.47720146179199218, 1.9561082124710083, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+35, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1785.673095703125, 1327.003662109375, 23.33595466613769531, 1.357039451599121093, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1928.0096435546875, 1416.96484375, 12.55990982055664062, 4.348969936370849609, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+37, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1754.17626953125, 1354.6884765625, 24.7605438232421875, 5.592080116271972656, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+38, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1830.4091796875, 1571.0565185546875, 25.71176338195800781, 5.293349742889404296, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1767.5631103515625, 1273.6688232421875, 36.67034530639648437, 5.0028533935546875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+40, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1949.05615234375, 1195.2598876953125, 25.30850028991699218, 3.043081283569335937, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 65206, 998, 6051, 6136, '0', '0', 0, 0, 0, 1696.5380859375, 1557.7576904296875, 22.785614013671875, 2.481467485427856445, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+42, 65205, 998, 6051, 6136, '0', '0', 0, 0, 0, 1793.47412109375, 1334.873046875, 19.48966789245605468, 2.649313926696777343, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 65209, 998, 6051, 6136, '0', '0', 0, 0, 0, 1660.6875, 1336.4583740234375, 11.32715511322021484, 1.695375800132751464, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+44, 65207, 998, 6051, 6136, '0', '0', 0, 0, 0, 1931.438232421875, 1129.7901611328125, 28.80927658081054687, 2.830842971801757812, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+45, 65209, 998, 6051, 6136, '0', '0', 0, 0, 0, 1622.8958740234375, 1317.854736328125, 10.44999980926513671, 6.107137680053710937, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+46, 62240, 998, 6051, 6136, '0', '0', 0, 0, 0, 1850.3055419921875, 1249.9930419921875, 13.49555587768554687, 1.588249564170837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Red Beam (Area: Temple of Kotmogu - Difficulty: 0) CreateObject2 (Auras: 121221 - Orange Ball Aura)
(@CGUID+47, 62237, 998, 6051, 6136, '0', '0', 0, 0, 0, 1716.8211669921875, 1249.6788330078125, 13.36339282989501953, 1.588249564170837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Yellow Beam (Area: Temple of Kotmogu - Difficulty: 0) CreateObject2 (Auras: 121217 - Yellow Ball Aura)
(@CGUID+48, 62239, 998, 6051, 6136, '0', '0', 0, 0, 0, 1716.8853759765625, 1416.7899169921875, 13.28889942169189453, 1.588249564170837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Green Beam (Area: Temple of Kotmogu - Difficulty: 0) CreateObject2 (Auras: 121220 - Green Ball Aura)
(@CGUID+49, 62238, 998, 6051, 6136, '0', '0', 0, 0, 0, 1850.0208740234375, 1416.689208984375, 13.39783096313476562, 1.588249564170837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Blue Beam (Area: Temple of Kotmogu - Difficulty: 0) CreateObject2 (Auras: 121219 - Purple Ball Aura)
(@CGUID+50, 13117, 998, 6051, 6136, '0', '0', 0, 0, 1, 1675.2899169921875, 1523.85595703125, 16.86186981201171875, 5.576955795288085937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Horde Spirit Guide (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+51, 13116, 998, 6051, 6136, '0', '0', 0, 0, 1, 1895.3350830078125, 1522.0972900390625, 16.29700660705566406, 3.56899261474609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Alliance Spirit Guide (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+52, 13117, 998, 6051, 6136, '0', '0', 0, 0, 1, 1678.185791015625, 1146.751708984375, 17.45750236511230468, 0.850761175155639648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Horde Spirit Guide (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+53, 13116, 998, 6051, 6136, '0', '0', 0, 0, 1, 1892.0867919921875, 1153.8941650390625, 15.00300025939941406, 2.315886497497558593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008); -- Alliance Spirit Guide (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)

DELETE FROM `creature_template_addon` WHERE `entry` IN (62238, 62239, 62237, 62240, 58951, 65205, 65209);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(65205, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 65205 (Gilded Moth)
(65209, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '113160'), -- Dancing Water Skimmer - 113160 - Water Walking)
(62238, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, '121219'), -- 62238 (Blue Beam) - Purple Ball Aura
(62239, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, '121220'), -- 62239 (Green Beam) - Green Ball Aura
(62237, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, '121217'), -- 62237 (Yellow Beam) - Yellow Ball Aura
(62240, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, '121221'), -- 62240 (Red Beam) - Orange Ball Aura
(58951, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 58951 (Trigger)

UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56008 WHERE (`Entry`=62238 AND `DifficultyID`=0); -- 62238 (Blue Beam) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56008 WHERE (`Entry`=62239 AND `DifficultyID`=0); -- 62239 (Green Beam) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56008 WHERE (`Entry`=62237 AND `DifficultyID`=0); -- 62237 (Yellow Beam) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56008 WHERE (`Entry`=62240 AND `DifficultyID`=0); -- 62240 (Red Beam) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56008 WHERE (`Entry`=58951 AND `DifficultyID`=0); -- 58951 (Trigger) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56008 WHERE (`Entry`=65209 AND `DifficultyID`=0); -- 65209 (Dancing Water Skimmer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=56008 WHERE (`Entry`=65205 AND `DifficultyID`=0); -- 65205 (Gilded Moth) - Floating

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+16;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 271002, 998, 6051, 6136, '0', '0', 0, 1716.888916015625, 1249.90283203125, 10.66335582733154296, 0, 0, 0, 0, 1, 7200, 255, 1, 56008), -- Pedestal (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+1, 271002, 998, 6051, 6136, '0', '0', 0, 1850.2447509765625, 1250.27783203125, 10.68205833435058593, 0, 0, 0, 0, 1, 7200, 255, 1, 56008), -- Pedestal (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+2, 228513, 998, 6051, 6136, '0', '0', 0, 1662.078125, 1565.0242919921875, 33.93070220947265625, 5.704944133758544921, 0, 0, -0.28510951995849609, 0.958494961261749267, 7200, 255, 1, 56008), -- Collision Large (KMS) (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+3, 271013, 998, 6051, 6136, '0', '0', 0, 1849.532958984375, 1250.12158203125, 11.2691497802734375, 0, 0, 0, 0, 1, 7200, 255, 1, 56008), -- Mogu Runes (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+4, 271012, 998, 6051, 6136, '0', '0', 0, 1716.7900390625, 1416.739990234375, 10.63140010833740234, 0, 0, 0, 0, 1, 7200, 255, 1, 56008), -- Mogu Runes (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+5, 215787, 998, 6051, 6136, '0', '0', 0, 1783.7391357421875, 1104.9503173828125, 19.50258636474609375, 1.596973419189453125, 0, 0, 0.71630096435546875, 0.697791457176208496, 7200, 255, 1, 56008), -- Collision (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+6, 271002, 998, 6051, 6136, '0', '0', 0, 1716.79345703125, 1416.7379150390625, 10.63142967224121093, 0, 0, 0, 0, 1, 7200, 255, 1, 56008), -- Pedestal (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+7, 271002, 998, 6051, 6136, '0', '0', 0, 1850.2603759765625, 1416.84375, 10.66736316680908203, 0, 0, 0, 0, 1, 7200, 255, 1, 56008), -- Pedestal (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+8, 215760, 998, 6051, 6136, '0', '0', 0, 1783.7391357421875, 1104.9503173828125, 19.50257492065429687, 1.596973419189453125, 0, 0, 0.71630096435546875, 0.697791457176208496, 7200, 255, 1, 56008), -- Great Wall (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+9, 271089, 998, 6051, 6136, '0', '0', 0, 1716.467041015625, 1249.5347900390625, 10.6067047119140625, 0, 0, 0, 0, 1, 7200, 255, 1, 56008), -- Mogu Runes (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+10, 271090, 998, 6051, 6136, '0', '0', 0, 1849.6875, 1416.685791015625, 10.66314697265625, 0, 0, 0, 0, 1, 7200, 255, 1, 56008), -- Mogu Runes (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+11, 215787, 998, 6051, 6136, '0', '0', 0, 1780.1724853515625, 1565.326416015625, 23.18830490112304687, 4.703663349151611328, 0, 0, -0.71018505096435546, 0.704015016555786132, 7200, 255, 1, 56008), -- Collision (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+12, 179905, 998, 6051, 6136, '0', '0', 0, 1710.954833984375, 1333.4739990234375, 10.55555534362792968, 0.018688473850488662, 0, 0, 0.009344100952148437, 0.999956309795379638, 90, 255, 1, 56008), -- Berserk Buff (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+13, 179907, 998, 6051, 6136, '0', '0', 0, 1855.3663330078125, 1333.4271240234375, 10.55555534362792968, 3.150753736495971679, 0, 0, -0.99998950958251953, 0.004580484237521886, 90, 255, 1, 56008), -- Berserk Buff (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+14, 215760, 998, 6051, 6136, '0', '0', 0, 1780.1724853515625, 1565.326416015625, 23.18829345703125, 4.703663349151611328, 0, 0, -0.71018505096435546, 0.704015016555786132, 7200, 255, 1, 56008), -- Great Wall (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+15, 213172, 998, 6051, 6136, '0', '0', 0, 1785.0347900390625, 1055.43603515625, 30.44949722290039062, 4.738570213317871093, 0, 0, -0.69779014587402343, 0.716302275657653808, 7200, 255, 1, 56008), -- Great Door (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1
(@OGUID+16, 213172, 998, 6051, 6136, '0', '0', 0, 1780.6055908203125, 1614.855712890625, 34.13521575927734375, 1.562067151069641113, 0, 0, 0.704013824462890625, 0.710186243057250976, 7200, 255, 1, 56008); -- Great Door (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+16;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+5, 0, 0, 0.71630185842514038, 0.697790563106536865, 0, 0), -- Collision
(@OGUID+8, 0, 0, 0.71630185842514038, 0.697790563106536865, 0, 0), -- Great Wall
(@OGUID+11, 0, 0, -0.71018534898757934, 0.704014718532562255, 0, 0), -- Collision
(@OGUID+14, 0, 0, -0.71018534898757934, 0.704014718532562255, 0, 0), -- Great Wall
(@OGUID+15, 0, 0, 0.71630185842514038, 0.697790563106536865, 0, 0), -- Great Door
(@OGUID+16, 0, 0, -0.71018534898757934, 0.704014718532562255, 0, 0); -- Great Door

UPDATE `gameobject_template_addon` SET `faction`=2059, `flags`=32 WHERE `entry` IN (212092, 212093, 212091, 212094); -- Orb of Power
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=213172; -- Great Door
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=215760; -- Great Wall
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=215787; -- Collision

SET @GROUP_ID := 0;
DELETE FROM `creature_text` WHERE `CreatureID`=58951;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(58951, @GROUP_ID+0, 0, 'The |cFFFF8000Orange|r orb has been returned!', 41, 0, 100, 0, 0, 0, 62285, 0, 'Trigger to Player'),
(58951, @GROUP_ID+1, 0, 'The |cFF01DFD7Blue|r orb has been returned!', 41, 0, 100, 0, 0, 0, 62283, 0, 'Trigger to Player'),
(58951, @GROUP_ID+2, 0, 'The |cFFBF00FFPurple|r orb has been returned!', 41, 0, 100, 0, 0, 0, 62284, 0, 'Trigger to Player'),
(58951, @GROUP_ID+3, 0, 'The |cFF01DF01Green|r orb has been returned!', 41, 0, 100, 0, 0, 0, 62286, 0, 'Trigger to Player');
