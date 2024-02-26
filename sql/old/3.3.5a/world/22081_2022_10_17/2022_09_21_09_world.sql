DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 226 AND 227;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(226,'Utgarde Pinnacle - Gortok Palehoof',4),
(227,'Utgarde Pinnacle - Skadi the Ruthless',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 226 AND 227;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(575,2,23,226,1),
(575,2,23,227,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 226 AND 227;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(226,0,126102),
(227,0,126103);
