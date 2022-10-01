DELETE FROM `spawn_group_template` WHERE `groupId`=304;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(304,'Coilfang: Serpentshrine Cavern - Lady Vashj',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`=304;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(548,5,23,304,1);

DELETE FROM `spawn_group` WHERE `groupId`=304;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(304,0,93814);
