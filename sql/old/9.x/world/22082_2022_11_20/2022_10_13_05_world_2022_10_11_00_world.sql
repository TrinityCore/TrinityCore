DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 296 AND 298;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(509,3,23,296,1),
(509,4,23,297,1),
(509,5,23,298,1);
