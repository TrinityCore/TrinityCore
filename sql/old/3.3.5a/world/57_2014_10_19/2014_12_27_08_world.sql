--
SET @GUID  := 75088;
DELETE FROM `creature` WHERE id IN (33630,33639,33642,33645);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@GUID+0, 33630, 530, 0, 0, 1, 1, 0, 1, -2091.979, 5634.983, 50.31123, 2.844887, 300, 0, 0, 2266, 6015, 0, 0, 0, 0, 0),
(@GUID+1, 33639, 530, 0, 0, 1, 1, 0, 1, -2093.764, 5632.878, 50.31123, 2.513274, 300, 0, 0, 3237, 0, 0, 0, 0, 0, 0),
(@GUID+2, 33642, 530, 0, 0, 1, 1, 0, 1, -2254.972, 5560.913, 67.10059, 5.951573, 300, 0, 0, 2835, 7196, 0, 0, 0, 0, 0),
(@GUID+3, 33645, 571, 0, 0, 1, 1, 0, 1, 8579.87, 749.8559, 547.376, 6.08289, 300, 0, 0, 10635, 0, 0, 0, 0, 0, 0);
