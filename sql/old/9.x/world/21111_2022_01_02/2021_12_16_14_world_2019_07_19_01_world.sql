-- 
DELETE FROM `pool_template` WHERE `entry`=11389;
DELETE FROM `pool_members` WHERE `spawnId`=11389 AND `type`=2 AND `poolSpawnId`=9907;
UPDATE `pool_members` SET `poolSpawnId`=11212 WHERE `spawnId`  IN (162689,162939) AND `poolSpawnId`=11389;
