-- 
-- Oozeworm
SET @GUID := 81136;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,14237,1,0,0,1,1,0,0,-4408.82,-2861.63,28.7375,2.12787,300,15,0,1675,0,1,0,0,0,"",0),
(@GUID+1,14237,1,0,0,1,1,0,0,-4231.72,-3010.83,47.2353,0.5217,300,5,0,1675,0,1,0,0,0,"",0),
(@GUID+2,14237,1,0,0,1,1,0,0,-4240.73,-2866.63,37.1291,5.23801,300,10,0,1675,0,1,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=1108;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(1108,1,"Oozeworm");

DELETE FROM `pool_creature` WHERE `pool_entry`=1108;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID,1108,0,"Oozeworm (14237) - Spawn 1"),
(@GUID+1,1108,0,"Oozeworm (14237) - Spawn 2"),
(@GUID+2,1108,0,"Oozeworm (14237) - Spawn 3");

-- Ripscale
SET @GUID := 81139;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,14233,1,0,0,1,1,0,0,-4453.28,-3973.02,29.4314,2.39624,300,10,0,1604,0,1,0,0,0,"",0),
(@GUID+1,14233,1,0,0,1,1,0,0,-4040.52,-3550.72,28.7875,5.86375,300,10,0,1604,0,1,0,0,0,"",0),
(@GUID+2,14233,1,0,0,1,1,0,0,-3789.5,-3245.67,29.9413,0.829341,300,10,0,1604,0,1,0,0,0,"",0),
(@GUID+3,14233,1,0,0,1,1,0,0,-3972.33,-3146.19,31.2817,4.54427,300,10,0,1604,0,1,0,0,0,"",0),
(@GUID+4,14233,1,0,0,1,1,0,0,-3793.2,-2982.42,28.583,5.0116,300,10,0,1604,0,1,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=1109;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(1109,1,"Ripscale");

DELETE FROM `pool_creature` WHERE `pool_entry`=1109;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID,1109,0,"Ripscale (14233) - Spawn 1"),
(@GUID+1,1109,0,"Ripscale (14233) - Spawn 2"),
(@GUID+2,1109,0,"Ripscale (14233) - Spawn 3"),
(@GUID+3,1109,0,"Ripscale (14233) - Spawn 4"),
(@GUID+4,1109,0,"Ripscale (14233) - Spawn 5");

-- Drogoth the Roamer
SET @GUID := 81132;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,14231,1,0,0,1,1,0,0,-2800.88,-3121.34,28.9155,2.29019,300,8,0,1537,0,1,0,0,0,"",0);

-- Lord Angler
SET @GUID := 81133;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,14236,1,0,0,1,1,0,0,-4252.79,-3854.69,-7.13676,3.38975,300,8,0,1604,0,1,0,0,0,"",0);

-- The Rot
SET @GUID := 81134;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,14235,1,0,0,1,1,0,0,-3985.36,-3723.25,41.8631,4.24192,300,5,0,1829,0,1,0,0,0,"",0);
