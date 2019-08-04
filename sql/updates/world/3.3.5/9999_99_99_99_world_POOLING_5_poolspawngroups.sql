-- 
RENAME TABLE `spawn_group` TO `spawn_group_old`;
CREATE TABLE `spawn_group` LIKE `spawn_group_old`;

INSERT INTO `spawn_group` (`spawnType`,`spawnId`,`groupId`)
SELECT DISTINCT
    if(pm1.`poolSpawnId` is not null, 2, sg.`spawnType`) as `spawnType`,
    ifnull(ifnull(pm2.`poolSpawnId`,pm1.`poolSpawnId`),sg.`spawnId`) as `spawnId`,
    sg.`groupId` as `groupId`
FROM `spawn_group_old` sg
LEFT JOIN `pool_members` pm1 ON (pm1.`type`=sg.`spawnType`) AND (pm1.`spawnId`=sg.`spawnId`)
LEFT JOIN `pool_members` pm2 ON (pm1.`poolSpawnId` is not null) AND (pm2.`type`=2) AND (pm2.`spawnId`=pm1.`poolSpawnId`);

DROP TABLE `spawn_group_old`;
