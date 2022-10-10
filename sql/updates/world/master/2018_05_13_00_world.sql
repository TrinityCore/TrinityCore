-- 
-- Delete duplicate Armory and Cathedral doors
DELETE FROM `gameobject` WHERE `guid` IN (200966,203104,212814,216444,220549,200965,203103,212815,216443,220550);

-- UPDATE SAI target
UPDATE `smart_scripts` SET `target_param1`=200252 WHERE `entryorguid` IN (101852) AND `source_type`=1 AND `id`=0;
UPDATE `smart_scripts` SET `target_param1`=200251 WHERE `entryorguid` IN (101853) AND `source_type`=1 AND `id`=0;

-- Update Armory, Cathedral doors and respective levers faction id
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry` IN (101850,101851,101852,101853);

-- Add missing instance portals for Scarlet Halls and Scarlet Monastery
SET @OGUID := 301206;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 211640, 0, 85, 5511, 1, 0, 0, 2918.078, -800.5555, 160.3323, 3.536494, 0, 0, -0.9805698, 0.1961703, 120, 255, 1, 22996), -- 211640 (Area: 5511 - Difficulty: 0)
(@OGUID+1, 211640, 0, 85, 5511, 1, 0, 0, 2866.038, -822.257, 160.3323, 0.4067206, 0, 0, 0.2019615, 0.9793934, 120, 255, 1, 22996), -- 211640 (Area: 5511 - Difficulty: 0)
(@OGUID+2, 214508, 1001, 0, 0, 262, 0, 0, 820.5886, 615.0452, 13.49034, 4.715349, 0, 0, -0.7060595, 0.7081525, 7200, 255, 1, 0),
(@OGUID+3, 214508, 1004, 0, 0, 262, 0, 0, 1124.557, 504.3333, 0.9891995, 1.561401, 0, 0, 0.7037773, 0.7104207, 7200, 255, 1, 0);

-- Redirect existing trigger target locations to new instance entrances
UPDATE `areatrigger_teleport` SET `PortLocID`=4077, `Name`='Scarlet Halls Entrance Target' WHERE `ID`=614;
UPDATE `areatrigger_teleport` SET `PortLocID`=4078, `Name`='Scarlet Monastery Entrance Target' WHERE `ID`=45;

-- Add exit triggers for new Scarlet Halls and Scarlet Monastery instances
DELETE FROM `areatrigger_teleport` WHERE `ID` IN(7801,7802);
INSERT INTO `areatrigger_teleport`(`ID`, `PortLocID`, `Name`) VALUES
(7801, 3626, 'Scarlet Halls Exit Target'),
(7802, 3623, 'Scarlet Monastery Exit Target');

-- Remove entrance triggers for old instances
DELETE FROM `areatrigger_teleport` WHERE `ID` IN(610,612);

DELETE FROM `instance_template` WHERE `map` IN (1001,1004);
INSERT INTO `instance_template` (`map`, `parent`, `allowMount`) VALUES (1001,0,0),(1004,0,0);
