DELETE FROM `spawn_group_template` WHERE `groupId`=283;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(283,'Tempest Keep: The Arcatraz - Dalliah the Doomsayer',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`=283;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(552,1,23,283,1);

DELETE FROM `spawn_group` WHERE `groupId`=283;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(283,0,79394);
