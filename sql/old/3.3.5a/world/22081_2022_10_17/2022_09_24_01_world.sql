DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 246 AND 249;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(246,'Drak''Tharon Keep - Trollgore',4),
(247,'Drak''Tharon Keep - Novos the Summoner',4),
(248,'Drak''Tharon Keep - King Dred',4),
(249,'Drak''Tharon Keep - The Prophet Tharon''ja',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 246 AND 249;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(600,0,23,246,1),
(600,1,23,247,1),
(600,2,23,248,1),
(600,3,23,249,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 246 AND 249;
INSERT INTO `spawn_group` SELECT 246, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=127422 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 247, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=127424 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 248, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=127507 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 249, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=200143 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(246,0,127422),
(247,0,127424),
(248,0,127507),
(249,0,200143);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (127422,127424,127507,200143);
