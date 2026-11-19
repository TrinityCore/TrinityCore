DELETE FROM `spawn_group_template` WHERE `groupId`=321;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(321,'Coilfang: Serpentshrine Cavern - Lady Vashj',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`=321;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(548,5,23,321,1);

DELETE FROM `spawn_group` WHERE `groupId`=321;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(321,0,93814);
