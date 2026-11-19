DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 293 AND 298;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(293,'Ruins of Ahn''Qiraj - Kurinnaxx',4),
(294,'Ruins of Ahn''Qiraj - General Rajaxx',4),
(295,'Ruins of Ahn''Qiraj - Moam',4),
(296,'Ruins of Ahn''Qiraj - Buru the Gorger',4),
(297,'Ruins of Ahn''Qiraj - Ayamiss the Hunter',4),
(298,'Ruins of Ahn''Qiraj - Ossirian the Unscarred',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 293 AND 298;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(509,0,23,293,1),
(509,1,23,294,1),
(509,2,23,295,1),
(509,4,23,296,1),
(509,5,23,297,1),
(509,6,23,298,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 293 AND 298;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(293,0,144632),
(294,0,144603),
(295,0,144602),
(296,0,144642),
(297,0,144641),
(298,0,144601);
