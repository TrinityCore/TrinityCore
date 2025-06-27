--
DELETE FROM `creature` WHERE `guid` IN (131089,131090) AND `id` = 32544;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(131089, 32544, 571, 1, 1, 0, 3393.9279, 5087.1079, 13.07991, 5.077986, 300, 15, 1, 11723),
(131090, 32544, 571, 1, 1, 0, 3862.7878, 5240.6787, 13.16521, 2.596991, 300, 15, 1, 11723);
DELETE FROM `pool_members` WHERE `spawnId` IN (131089,131090) AND `type` = 0;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0,131089,4998,0,"Steam Cloud - Borean Tundra"),
(0,131090,4998,0,"Steam Cloud - Borean Tundra");
