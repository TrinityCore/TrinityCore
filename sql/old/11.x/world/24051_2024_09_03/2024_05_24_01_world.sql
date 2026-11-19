SET @CGUID := 7000528;

DELETE FROM `phase_name` WHERE `ID`=12615;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12615, 'Cosmetic: Lumberjack Queue in Algerson Lumberyard Office');

DELETE FROM `phase_area` WHERE `PhaseId`=12615;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9334, 12615, 'Cosmetic: Lumberjack Queue in Algerson Lumberyard Office');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12615));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12615, 0, 0, 0, 47, 0, 54726, 74, 0, '', 1, 'Player doesn\'t have Frame Work (54726) in state complete, incomplete, rewarded');

UPDATE `creature_equip_template` SET `VerifiedBuild`=54762 WHERE (`CreatureID`=129627 AND `ID`=1);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 129627, 1643, 8567, 9334, '0', 12615, 0, 80752, 1, 1300.78125, -120.265632629394531, 10.92565155029296875, 4.596895217895507812, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Algerson Lumber Yard - Difficulty: 0) CreateObject1
(@CGUID+1, 129627, 1643, 8567, 9334, '0', 12615, 0, 80752, 1, 1300.579833984375, -124.720489501953125, 11.46352577209472656, 4.483132839202880859, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Algerson Lumber Yard - Difficulty: 0) CreateObject1
(@CGUID+2, 129627, 1643, 8567, 9334, '0', 12615, 0, 80751, 1, 1295.6927490234375, -127.276039123535156, 11.46352577209472656, 2.59120345115661621, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Algerson Lumber Yard - Difficulty: 0) CreateObject1
(@CGUID+3, 129627, 1643, 8567, 9334, '0', 12615, 0, 80752, 1, 1299.0504150390625, -127.0625, 11.46352577209472656, 3.303844690322875976, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Algerson Lumber Yard - Difficulty: 0) CreateObject1
(@CGUID+4, 129627, 1643, 8567, 9334, '0', 12615, 0, 80752, 1, 1300.2222900390625, -117.357643127441406, 10.85943508148193359, 4.828445911407470703, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762); -- Algerson Lumberjack (Area: Algerson Lumber Yard - Difficulty: 0) CreateObject1

UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=129627 AND `DifficultyID`=0); -- 129627 (Algerson Lumberjack) - CanSwim

UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=129627; -- Algerson Lumberjack
