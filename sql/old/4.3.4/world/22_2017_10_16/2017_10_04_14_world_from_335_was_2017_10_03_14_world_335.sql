/*
-- Add Missing Spawn and Waypoint Movement for Grimmaw
SET @GUID := 27589;
DELETE FROM `creature` WHERE `guid`=@GUID;
DELETE FROM `creature` WHERE `id`=14429;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,14429,1,0,0,1,1,0,0,9132.61,1651.7,1322.14,4.25837,7200,0,0,222,0,2,0,0,0,'',0);

DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@GUID,@GUID*10,0,0,0,0,'');

DELETE FROM `waypoint_data` WHERE `id`=@GUID*10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@GUID*10,1,9132.81,1664.76,1320.77,0,0,0,0,100,0),
(@GUID*10,2,9141.27,1690.01,1320.05,0,0,0,0,100,0),
(@GUID*10,3,9141.58,1727.6,1319.16,0,0,0,0,100,0),
(@GUID*10,4,9137.61,1753.82,1319.01,0,0,0,0,100,0),
(@GUID*10,5,9116,1771.33,1321.66,0,0,0,0,100,0),
(@GUID*10,6,9109.14,1808.41,1325.54,0,0,0,0,100,0),
(@GUID*10,7,9111.24,1823.84,1328.53,0,0,0,0,100,0),
(@GUID*10,8,9108.77,1809.06,1325.75,0,0,0,0,100,0),
(@GUID*10,9,9115.99,1771.94,1321.74,0,0,0,0,100,0),
(@GUID*10,10,9136.82,1754.07,1318.87,0,0,0,0,100,0),
(@GUID*10,11,9141.64,1726.7,1319.16,0,0,0,0,100,0),
(@GUID*10,12,9141.35,1689.69,1320.03,0,0,0,0,100,0),
(@GUID*10,13,9131.44,1665.16,1320.95,0,0,0,0,100,0),
(@GUID*10,14,9132.59,1646.61,1322.61,0,0,0,0,100,0);
*/
