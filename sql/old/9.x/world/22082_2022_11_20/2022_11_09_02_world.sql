SET @CGUID := 651494;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 90336, 1220, 7334, 7361, '0', 4512, 0, 0, 0, 1095.927490234375, 6327.451171875, 125.7473297119140625, 2.676634788513183593, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+1, 90336, 1220, 7334, 7361, '0', 4512, 0, 0, 0, 1088.77099609375, 6326.06591796875, 123.259735107421875, 4.100066184997558593, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+2, 90336, 1220, 7334, 7361, '0', 4512, 0, 0, 0, 1094.2476806640625, 6326.732421875, 125.2869644165039062, 1.881223082542419433, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+3, 90336, 1220, 7334, 7361, '0', 4512, 0, 0, 0, 1083.4805908203125, 6333.52880859375, 125.7073822021484375, 0.805408716201782226, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+4, 90336, 1220, 7334, 7361, '0', 4512, 0, 0, 0, 1088.086181640625, 6309.45166015625, 121.0783462524414062, 4.815438270568847656, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+5, 90336, 1220, 7334, 7361, '0', 4512, 0, 0, 0, 1073.802978515625, 6326.64892578125, 122.466217041015625, 1.904032707214355468, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+6, 90336, 1220, 7334, 7361, '0', 4512, 0, 0, 0, 1102.1324462890625, 6322.12548828125, 124.907958984375, 3.752389430999755859, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+7, 90336, 1220, 7334, 7361, '0', 4512, 0, 0, 0, 1100.4820556640625, 6302.70751953125, 120.3372268676757812, 5.468790054321289062, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+8, 90336, 1220, 7334, 7361, '0', 4512, 0, 0, 0, 1097.8271484375, 6306.5361328125, 121.3778762817382812, 2.264909267425537109, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+9, 90336, 1220, 7334, 7361, '0', 4512, 0, 0, 0, 1097.76904296875, 6322.08642578125, 124.5944671630859375, 4.856227397918701171, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455); -- Azurewing Whelpling

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Azurewing Whelpling
(@CGUID+1, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Azurewing Whelpling
(@CGUID+2, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Azurewing Whelpling
(@CGUID+3, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Azurewing Whelpling
(@CGUID+4, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Azurewing Whelpling
(@CGUID+5, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Azurewing Whelpling
(@CGUID+6, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Azurewing Whelpling
(@CGUID+7, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Azurewing Whelpling
(@CGUID+8, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Azurewing Whelpling
(@CGUID+9, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''); -- Azurewing Whelpling

DELETE FROM `phase_name` WHERE `ID` = 4512;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4512, 'Cosmetic - See Azurewing Whelpling in Ley-Ruins of Zarkhenar');

DELETE FROM `phase_area` WHERE `AreaId` = 7361 AND `PhaseId` = 4512;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7361, 4512, 'Cosmetic - See Azurewing Whelpling in Ley-Ruins of Zarkhenar'); -- Ley-Ruins of Zarkhenar Zone

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 4512 AND `SourceEntry` = 7361);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4512, 7361, 0, 0, 47, 0, 37857, 2 | 64, 0, 0, 'Apply Phase 4512 if Quest 37857 is completed | rewarded'),
(26, 4512, 7361, 0, 0, 47, 0, 37860, 8 | 2 | 64, 0, 1, 'Apply Phase 4512 if Quest 37860 is not in progress | completed | rewarded');
