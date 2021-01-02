-- Sewer Beast
SET @POOL := 350;
DELETE FROM `pool_template` WHERE `entry` = @POOL;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES 
(@POOL, 1, 'Sewer Beast');
DELETE FROM `pool_members` WHERE `poolSpawnId` = @POOL;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, 86300, @POOL, 0, "Sewer Beast - Spawn 1"),
(0, 86301, @POOL, 0, "Sewer Beast - Spawn 2");
