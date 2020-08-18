-- 
DELETE FROM `spawn_group` WHERE `spawnType` = 1 AND `spawnId` IN (86751,86010);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(4,1,86751),
(4,1,86010);
