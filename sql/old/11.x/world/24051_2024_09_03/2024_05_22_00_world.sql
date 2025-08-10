SET @OGUID := 7000167;

DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 320950, 1643, 9042, 9579, '0', 12812, 0, 3523.903564453125, -476.6163330078125, -3.33042573928833007, 1.7016984224319458, 0, 0, 0.751840591430664062, 0.659344911575317382, 120, 255, 1, 54762); -- The Abyssal Melody (Area: Tidecross - Difficulty: 0) CreateObject1

DELETE FROM `phase_name` WHERE `ID`=12812;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12812, 'Cosmetic - The Abyssal Melody in Port Fogtide');

DELETE FROM `phase_area` WHERE `PhaseId`=12812;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9042, 12812, 'Cosmetic - The Abyssal Melody in Port Fogtide');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12812));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12812, 9042, 0, 0, 9, 0, 54721, 0, 0, '', 1, 'Player doesn\'t have quest I\'m Too Old for This Ship (54721) active');
