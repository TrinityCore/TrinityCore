--
SET @POOL=594;
DELETE FROM `pool_template` WHERE `entry`=@POOL;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL, 1, "Water Barrel and Food Crate7");

DELETE FROM `pool_members` WHERE `type`=1 AND `poolSpawnId`=@POOL;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, 32287, @POOL, 0, "Water Barrel and Food Crate - Spawn 7"),
(1, 32742, @POOL, 0, "Water Barrel and Food Crate - Spawn 7");
