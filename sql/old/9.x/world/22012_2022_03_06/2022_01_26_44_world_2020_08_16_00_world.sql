-- 
INSERT IGNORE INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) SELECT 1,1,`guid` FROM `gameobject` WHERE `spawntimesecs` < 0;
