SET @OGUID := 3990009;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 195141, 0, 1519, 5154, '0', '0', 0, -9007.580078125, 871.86981201171875, 129.6921539306640625, 0, 0, 0, 0, 1, 120, 255, 1, 55141), -- Portal to Blasted Lands (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@OGUID+1, 197094, 0, 1519, 5154, '0', '0', 0, -8999.935546875, 877.171630859375, 29.739166259765625, 0.671950340270996093, 0, 0, 0.329689979553222656, 0.944089233875274658, 120, 255, 1, 55141), -- Highback Chair (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@OGUID+2, 197095, 0, 1519, 5154, '0', '0', 0, -9006.4208984375, 859.19580078125, 29.739166259765625, 3.81354522705078125, 0, 0, -0.94408893585205078, 0.329690933227539062, 120, 255, 1, 55141); -- Highback Chair (Area: Mage Quarter - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_template_addon` WHERE `entry` = 195141;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(195141, 1732, 0x0, 0, 0); -- Portal to Blasted Lands

DELETE FROM `areatrigger` WHERE `SpawnId` IN (1, 2, 4);
DELETE FROM `areatrigger_teleport` WHERE `ID` IN (704, 702);
INSERT INTO `areatrigger_teleport` (`ID`, `PortLocID`) VALUES
(704, 3631),
(702, 3630);

UPDATE `world_safe_locs` SET `LocX`= -9014.9404296875, `LocY`= 	873.32598876953, `LocZ`= 148.61599731445, `Facing`= 300 WHERE `ID`= 3630;
UPDATE `world_safe_locs` SET `LocX`= -9016.9697265625, `LocY`= 	885.43597412109, `LocZ`= 29.62070083618, `Facing`= 310 WHERE `ID`= 3631;
