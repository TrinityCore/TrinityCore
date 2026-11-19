SET @CGUID := 651506;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 90267, 1220, 7334, 7361, '0', 6803, 0, 0, 0, 1251.3038330078125, 6027.025390625, 116.44036865234375, 5.771207332611083984, 120, 0, 0, 23538, 1534, 0, 0, 0, 0, 46455); -- Ael'Yith

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 468, 0, 0, 0, 0, ''); -- Ael'Yith

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags`=32768, `VerifiedBuild`=46455 WHERE `entry`=90267; -- Ael'Yith

UPDATE `creature_questitem` SET `VerifiedBuild`=46455 WHERE (`Idx` IN (0, 1, 2, 3) AND `CreatureEntry` = 90267);

DELETE FROM `phase_name` WHERE `ID` = 6803;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(6803, 'Cosmetic - See Ael\'Yith in Ley-Ruins of Zarkhenar');

DELETE FROM `phase_area` WHERE `AreaId` = 7361 AND `PhaseId` = 6803;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7361, 6803, 'Cosmetic - See Ael\'Yith in Ley-Ruins of Zarkhenar'); -- Ley-Ruins of Zarkhenar Zone

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 6803 AND `SourceEntry` = 7361);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 6803, 7361, 0, 0, 47, 0, 37861, 2 | 64, 0, 1, 'Apply Phase 6803 if Quest 37861 is not completed | rewarded');
