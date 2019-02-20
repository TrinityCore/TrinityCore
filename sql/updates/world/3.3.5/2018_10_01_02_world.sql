--
DELETE FROM `pool_template` WHERE `entry`=491;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(491,1,"Reagent Pouch");

DELETE FROM `pool_gameobject` WHERE `pool_entry`=491;
INSERT INTO `pool_gameobject` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(6517,491,0,"Reagent Pouch - Spawn 1"),
(6522,491,0,"Reagent Pouch - Spawn 2"),
(56732,491,0,"Reagent Pouch - Spawn 3");

DELETE FROM `gameobject` WHERE `guid` IN (6517,6522);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(6517,186662,571,0,0,1,1,724.839, -5169.79, -73.795, 5.38533, -0, -0, -0.434001, 0.900912, 300,100,1,"",0),
(6522,186662,571,0,0,1,1,792.927, -5149.68, -82.2494, 1.69253, -0, -0, -0.74881, -0.662785, 300,100,1,"",0);

UPDATE `gameobject` SET `spawntimesecs`=5 WHERE `id`=186662;
