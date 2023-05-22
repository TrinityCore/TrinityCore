DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 204 AND 205;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(204,'Auchindoun: Auchenai Crypts - Shirrak the Dead Watcher',4),
(205,'Auchindoun: Auchenai Crypts - Exarch Maladaar',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 204 AND 205;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(556,0,23,204,1),
(556,1,23,205,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 204 AND 205;
INSERT INTO `spawn_group` SELECT 204, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=83388 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 205, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=83453 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(204,0,83388),
(205,0,83453);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (83388,83453);
