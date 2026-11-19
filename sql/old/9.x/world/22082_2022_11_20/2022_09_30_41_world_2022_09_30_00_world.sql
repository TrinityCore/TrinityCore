DELETE FROM `spawn_group_template` WHERE `groupId` IN (323,324);
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(323,'Naxxramas - Sapphiron',4),
(324,'Naxxramas - Kel''Thuzad',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` IN (323,324);
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(533,13,23,323,1),
(533,14,23,324,1);

DELETE FROM `spawn_group` WHERE `groupId` IN (323,324);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(323,0,133932),
(323,1,5517),
(324,0,133933);
