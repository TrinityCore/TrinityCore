-- Twilight Zealot from Heroic Blackrock Caverns is missing
SET @GUID := 250021;
DELETE FROM `creature` WHERE `guid` = @GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnDifficulties`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID, 50284,645,"2",169,573.484,978.585,155.4369,1.570796,7200,0,0); -- Twilight Zealot Heroic
