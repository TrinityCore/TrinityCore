SET @CGUID := 651483;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 90336, 1220, 7334, 7359, '0', 4474, 0, 0, 0, 1090.1904296875, 6602.11865234375, 140.746002197265625, 6.075543880462646484, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+1, 90336, 1220, 7334, 7359, '0', 4474, 0, 0, 0, 1092.2633056640625, 6584.92724609375, 140.410858154296875, 3.011837005615234375, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+2, 90336, 1220, 7334, 7359, '0', 4474, 0, 0, 0, 1082.335205078125, 6578.35546875, 140.66424560546875, 5.498481273651123046, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+3, 90336, 1220, 7334, 7359, '0', 4474, 0, 0, 0, 1097.880615234375, 6582.60009765625, 140.57403564453125, 4.104146480560302734, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+4, 90336, 1220, 7334, 7359, '0', 4474, 0, 0, 0, 1082.4034423828125, 6580.08203125, 140.701812744140625, 6.158801078796386718, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+5, 90336, 1220, 7334, 7359, '0', 4474, 0, 0, 0, 1084.17236328125, 6575.916015625, 140.640167236328125, 5.378767967224121093, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+6, 90336, 1220, 7334, 7359, '0', 4474, 0, 0, 0, 1092.649658203125, 6605.85107421875, 139.625701904296875, 5.0538330078125, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+7, 90336, 1220, 7334, 7359, '0', 4474, 0, 0, 0, 1086.8924560546875, 6576.50634765625, 140.49066162109375, 3.367164373397827148, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+8, 90336, 1220, 7334, 7359, '0', 4474, 0, 0, 0, 1092.7081298828125, 6602.7666015625, 140.7464752197265625, 0.093156047165393829, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455), -- Azurewing Whelpling
(@CGUID+9, 90336, 1220, 7334, 7359, '0', 4474, 0, 0, 0, 1088.6865234375, 6588.60302734375, 140.54058837890625, 2.17026829719543457, 120, 9, 0, 3138, 3801, 1, 0, 0, 0, 46455); -- Azurewing Whelpling

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

UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0, `VerifiedBuild`=46455 WHERE `entry`=90336; -- Azurewing Whelpling

DELETE FROM `phase_name` WHERE `ID` = 4474;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4474, 'Cosmetic - See Azurewing Whelpling revived');

DELETE FROM `phase_area` WHERE `AreaId` IN (7359, 7338) AND `PhaseId` = 4474;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7338, 4474, 'Cosmetic - See Azurewing Whelpling revived in Azurewing Whelplands'), -- Runas's Hovel
(7359, 4474, 'Cosmetic - See Azurewing Whelpling revived in Azurewing Whelplands'); -- Azurewing Whelplands Zone

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 4474 AND `SourceEntry` IN (7338, 7359));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4474, 7359, 0, 0, 47, 0, 37859, 2 | 64, 0, 0, 'Apply Phase 4464 if Quest 37859 is completed | rewarded'),
(26, 4474, 7359, 0, 0, 47, 0, 37857, 2 | 64, 0, 1, 'Apply Phase 4464 if Quest 37857 is not completed | rewarded'),
(26, 4474, 7338, 0, 0, 47, 0, 37957, 2 | 64, 0, 0, 'Apply Phase 4464 if Quest 37957 is completed | rewarded'),
(26, 4474, 7338, 0, 0, 47, 0, 37857, 2 | 64, 0, 1, 'Apply Phase 4464 if Quest 37857 is not completed | rewarded');
