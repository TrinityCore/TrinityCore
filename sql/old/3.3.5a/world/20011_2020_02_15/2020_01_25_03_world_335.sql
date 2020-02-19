-- Pridewing Patriarch
SET @POOL := 349;
DELETE FROM `pool_template` WHERE `entry` = @POOL;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES 
(@POOL, 1, 'Pridewing Patriarch');
DELETE FROM `pool_members` WHERE `poolSpawnId` = 349;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, 29981, 349, 0, "Pridewing Patriarch - Spawn 1"),
(0, 29982, 349, 0, "Pridewing Patriarch - Spawn 2");
