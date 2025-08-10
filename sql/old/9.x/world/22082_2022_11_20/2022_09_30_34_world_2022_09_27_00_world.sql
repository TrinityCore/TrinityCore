DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 284 AND 285;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(284,'Halls of Reflection - Falric',4),
(285,'Halls of Reflection - Marwyn',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 284 AND 285;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(668,0,23,284,1),
(668,1,23,285,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 284 AND 285;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(284,0,202308),
(285,0,202294);
