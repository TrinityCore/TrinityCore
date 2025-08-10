DELETE FROM `spawn_group_template` WHERE `groupId`=322;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(322,'Trial of the Crusader - Anub''arak',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`=322;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(649,5,23,322,1);

DELETE FROM `spawn_group` WHERE `groupId`=322;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(322,0,79370);
