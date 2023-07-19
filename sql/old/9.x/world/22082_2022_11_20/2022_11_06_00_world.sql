SET @CGUID := 651468;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 90880, 1220, 7334, 7340, '0', 4476, 0, 0, 0, 649.0069580078125, 6614.7109375, 60.30034637451171875, 2.096465349197387695, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46366), -- Mana-Drained Whelpling
(@CGUID+1, 90880, 1220, 7334, 7340, '0', 4476, 0, 0, 0, 645.763916015625, 6615.47314453125, 60.22843170166015625, 2.426905155181884765, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46366), -- Mana-Drained Whelpling
(@CGUID+2, 90880, 1220, 7334, 7340, '0', 4476, 0, 0, 0, 641.78302001953125, 6612.52685546875, 60.2725677490234375, 2.556946277618408203, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46366), -- Mana-Drained Whelpling
(@CGUID+3, 89943, 1220, 7334, 7340, '0', 4476, 0, 0, 1, 647.7725830078125, 6593.8369140625, 60.28992843627929687, 2.211899995803833007, 120, 0, 0, 58845, 0, 0, 0, 0, 0, 46366), -- Azurewing Keeper
(@CGUID+4, 90543, 1220, 7334, 7340, '0', 4476, 0, 0, 0, 647.03302001953125, 6607.345703125, 60.27102279663085937, 2.152879714965820312, 120, 0, 0, 9808, 0, 0, 0, 0, 0, 46366), -- Agapanthus (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 90880, 1220, 7334, 7340, '0', 4476, 0, 0, 0, 640.82293701171875, 6608.140625, 60.24652862548828125, 4.5151824951171875, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46366), -- Mana-Drained Whelpling
(@CGUID+6, 89943, 1220, 7334, 7340, '0', 4476, 0, 0, 1, 657.63543701171875, 6602.52783203125, 60.32757568359375, 2.06743788719177246, 120, 0, 0, 58845, 0, 0, 0, 0, 0, 46366); -- Azurewing Keeper

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 7, 1, 0, 0, 0, 0, 0, ''), -- Mana-Drained Whelpling
(@CGUID+1, 0, 0, 7, 1, 0, 0, 0, 0, 0, ''), -- Mana-Drained Whelpling
(@CGUID+2, 0, 0, 7, 1, 0, 0, 0, 0, 0, ''), -- Mana-Drained Whelpling
(@CGUID+3, 0, 0, 0, 257, 0, 0, 0, 0, 0, '18950'), -- Azurewing Keeper - 18950 - Invisibility and Stealth Detection
(@CGUID+4, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- Agapanthus
(@CGUID+5, 0, 0, 7, 1, 0, 0, 0, 0, 0, ''), -- Mana-Drained Whelpling
(@CGUID+6, 0, 0, 0, 257, 0, 0, 0, 0, 0, '18950'); -- Azurewing Keeper - 18950 - Invisibility and Stealth Detection

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=32768, `dynamicflags`=128, `VerifiedBuild`=46366 WHERE `entry`=90880; -- Mana-Drained Whelpling
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `unit_flags3`=8388608, `VerifiedBuild`=46366 WHERE `entry`=90543; -- Agapanthus

DELETE FROM `phase_name` WHERE `ID` = 4476;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4476, 'Cosmetic - See Agapanthus and wounded whelplings');

DELETE FROM `phase_area` WHERE `AreaId` = 7340 AND `PhaseId` = 4476;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7340, 4476, 'Cosmetic - See Agapanthus and wounded whelplings in Azurewing Repose');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4476  AND `SourceEntry` = 7340);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4476, 7340, 0, 0, 47, 0, 37853, 2 | 64, 0, 0, 'Apply Phase 4476 if Quest 38857 is completed | rewarded'),
(26, 4476, 7340, 0, 1, 48, 0, 277011, 0, 6, 0, 'Apply Phase 4476 if player has quest objective done: Crackling Leyworm Core'),
(26, 4476, 7340, 0, 0, 47, 0, 42271, 2 | 64, 0, 1, 'Apply Phase 4476 if Quest 42271 is not completed | rewarded');
