/*
-- Molok the Crusher
SET @GUID := 43465;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,2604,0,0,0,1,1,0,1,-2056.97,-2785.61,68.571,5.47225,54000,0,0,1678,0,0,0,0,0,"",0);

-- Foulbelly
SET @GUID := 84200;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,2601,0,0,0,1,1,0,1,-1777.47,-1568.15,53.0089,3.82291,172800,0,0,6605,1381,0,0,0,0,"",0);

-- Ruul Onestone
SET @GUID := 84227;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,2602,0,0,0,1,1,0,1,-1797.35,-1507.83,99.3938,6.12074,180000,0,0,3540,3708,0,0,0,0,"",0);

UPDATE `creature_template` SET `ManaModifier`=3 WHERE `entry`=2602;

-- Darbel Montrose
SET @GUID := 84258;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,2598,0,0,0,1,1,0,1,-1590.25,-1889.45,68.5119,1.52227,57600,0,0,2360,2472,0,0,0,0,"",0),
(@GUID+1,2598,0,0,0,1,1,0,1,-1631.82,-1875.26,81.3837,2.99489,57600,5,0,2360,2472,1,0,0,0,"",0),
(@GUID+2,2598,0,0,0,1,1,0,1,-1622.46,-1775.05,81.3642,3.78814,57600,0,0,2360,2472,0,0,0,0,"",0),
(@GUID+3,2598,0,0,0,1,1,0,1,-1683.51,-1853.98,86,3.05772,57600,0,0,2360,2472,0,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=1114;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(1114,1,"Darbel Montrose");

DELETE FROM `pool_creature` WHERE `pool_entry`=1114;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID,1114,0,"Darbel Montrose (2598) - Spawn 1"),
(@GUID+1,1114,0,"Darbel Montrose (2598) - Spawn 2"),
(@GUID+2,1114,0,"Darbel Montrose (2598) - Spawn 3"),
(@GUID+3,1114,0,"Darbel Montrose (2598) - Spawn 4");

-- Kovork
SET @GUID := 84230;
DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,2603,0,0,0,1,1,0,1,-1190.7,-2055.29,42.9287,3.88181,27000,0,0,1469,0,0,0,0,0,"",0),
(@GUID+1,2603,0,0,0,1,1,0,1,-1185.5,-1959.2,24.088,2.65659,27000,3,0,1469,0,1,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=1115;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(1115,1,"Kovork");

DELETE FROM `pool_creature` WHERE `pool_entry`=1115;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID,1115,0,"Kovork (2603) - Spawn 1"),
(@GUID+1,1115,0,"Kovork (2603) - Spawn 2");

-- Zalas Witherbark
SET @GUID := 84293;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,2605,0,0,0,1,1,0,0,-2019.19,-3306.55,54.216,5.47616,252000,0,0,1410,2566,0,0,0,0,"",0),
(@GUID+1,2605,0,0,0,1,1,0,0,-2057.33,-3274,49.8653,4.51998,252000,0,0,1410,2566,2,0,0,0,"",0),
(@GUID+2,2605,0,0,0,1,1,0,0,-2042.3,-3364.3,60.2045,0.712735,252000,0,0,1410,2566,0,0,0,0,"",0),
(@GUID+3,2605,0,0,0,1,1,0,0,-2072.1,-3297.35,67.0706,1.54131,252000,0,0,1410,2566,0,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=1116;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(1116,1,"Zalas Witherbark");

DELETE FROM `pool_creature` WHERE `pool_entry`=1116;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID,1116,0,"Zalas Witherbark (2605) - Spawn 1"),
(@GUID+1,1116,0,"Zalas Witherbark (2605) - Spawn 2"),
(@GUID+2,1116,0,"Zalas Witherbark (2605) - Spawn 3"),
(@GUID+3,1116,0,"Zalas Witherbark (2605) - Spawn 4");

DELETE FROM `creature_template_addon` WHERE `entry`=2605;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(2605,0,0,8,1,0,""); -- Standstate Kneel for Zalas Witherbark

DELETE FROM `creature_addon` WHERE `guid`=@GUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@GUID+1,(@GUID+1)*10,0,0,1,0,""); -- Pathing for Zalas Witherbark (Spawn 2)

DELETE FROM `waypoint_data` WHERE `id`=(@GUID+1)*10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
((@GUID+1)*10,1,-2056.85,-3271.49,49.4426,0,0,0,0,100,0),
((@GUID+1)*10,2,-2061.19,-3271.54,50.2861,0,0,0,0,100,0),
((@GUID+1)*10,3,-2083.62,-3276.01,51.4356,0,0,0,0,100,0),
((@GUID+1)*10,4,-2098.75,-3286.29,51.7022,0,0,0,0,100,0),
((@GUID+1)*10,5,-2106.52,-3322.71,56.8964,0,0,0,0,100,0),
((@GUID+1)*10,6,-2115.63,-3344.91,58.7511,0,0,0,0,100,0),
((@GUID+1)*10,7,-2109.39,-3369.78,61.0127,0,0,0,0,100,0),
((@GUID+1)*10,8,-2091.81,-3381.89,59.4361,0,0,0,0,100,0),
((@GUID+1)*10,9,-2095.79,-3366.71,59.3,0,0,0,0,100,0),
((@GUID+1)*10,10,-2093.88,-3364.27,59.1176,0,0,0,0,100,0),
((@GUID+1)*10,11,-2099.47,-3360.35,59.2716,0,0,0,0,100,0),
((@GUID+1)*10,12,-2102.05,-3333.13,58.104,0,0,0,0,100,0),
((@GUID+1)*10,13,-2095.42,-3295.27,52.4655,0,0,0,0,100,0),
((@GUID+1)*10,14,-2078.4,-3272.51,51.7336,0,0,0,0,100,0),
((@GUID+1)*10,15,-2055.61,-3271.22,49.3672,0,0,0,0,100,0);

-- Nimar the Slayer
SET @GUID := 84402;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,2606,0,0,0,1,1,0,0,-1902.16,-3193.09,56.5808,5.63212,27000,0,0,1537,0,0,0,0,0,"",0),
(@GUID+1,2606,0,0,0,1,1,0,0,-1672.56,-3246.93,25.7297,4.51998,27000,0,0,1537,0,2,0,0,0,"",0),
(@GUID+2,2606,0,0,0,1,1,0,0,-1701.21,-3509.16,60.2556,6.26748,27000,0,0,1537,0,0,0,0,0,"",0),
(@GUID+3,2606,0,0,0,1,1,0,0,-1810.14,-3417.2,45.4232,0.985671,27000,0,0,1537,0,0,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=1113;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(1113,1,"Nimar the Slayer");

DELETE FROM `pool_creature` WHERE `pool_entry`=1113;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID,1113,0,"Nimar the Slayer (2606) - Spawn 1"),
(@GUID+1,1113,0,"Nimar the Slayer (2606) - Spawn 2"),
(@GUID+2,1113,0,"Nimar the Slayer (2606) - Spawn 3"),
(@GUID+3,1113,0,"Nimar the Slayer (2606) - Spawn 4");

DELETE FROM `creature_addon` WHERE `guid`=@GUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@GUID+1,(@GUID+1)*10,0,0,1,0,""); -- Pathing for Nimar the Slayer (Spawn 2)

DELETE FROM `waypoint_data` WHERE `id`=(@GUID+1)*10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
((@GUID+1)*10,1,-1672.56,-3246.93,25.7297,0,0,0,0,100,213867),
((@GUID+1)*10,2,-1673.33,-3252.4,25.7306,0,60000,0,0,100,213868),
((@GUID+1)*10,3,-1679.78,-3257.49,25.5371,0,0,0,0,100,213869),
((@GUID+1)*10,4,-1678.29,-3264.48,24.3447,0,0,0,0,100,213870),
((@GUID+1)*10,5,-1650.41,-3263.6,26.8072,0,0,0,0,100,213871),
((@GUID+1)*10,6,-1642.67,-3252.82,31.5431,0,0,0,0,100,213872),
((@GUID+1)*10,7,-1645.48,-3241.07,33.4071,0,0,0,0,100,213873),
((@GUID+1)*10,8,-1654.84,-3232.66,33.5165,0,0,0,0,100,213874),
((@GUID+1)*10,9,-1670.32,-3228.45,34.6906,0,0,0,0,100,213875),
((@GUID+1)*10,10,-1693.22,-3231.79,29.2882,0,0,0,0,100,213876),
((@GUID+1)*10,11,-1693.78,-3246.29,26.4924,0,0,0,0,100,213877),
((@GUID+1)*10,12,-1672.47,-3263.53,25.0571,0,0,0,0,100,213878),
((@GUID+1)*10,13,-1668.16,-3255.58,25.73,0,0,0,0,100,213879),
((@GUID+1)*10,14,-1673.27,-3253.71,25.7309,0,0,0,0,100,213880);
*/
