-- Mist Howler
SET @POOL := 348;
DELETE FROM `pool_template` WHERE `entry` = @POOL;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES 
(@POOL, 1, 'Mist Howler');
DELETE FROM `pool_members` WHERE `poolSpawnId` = 348;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, 32884, 348, 0, "Mist Howler - Spawn 1"),
(0, 51885, 348, 0, "Mist Howler - Spawn 2");
