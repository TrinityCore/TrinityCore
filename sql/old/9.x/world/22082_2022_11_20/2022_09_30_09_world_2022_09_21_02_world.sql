DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 199 AND 200;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(199,'Auchindoun: Sethekk Halls - Darkweaver Syth',4),
(200,'Auchindoun: Sethekk Halls - Talon King Ikiss',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 199 AND 200;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(556,0,23,199,1),
(556,1,23,200,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 199 AND 200;
INSERT INTO `spawn_group` SELECT 199, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=83270 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 200, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=83300 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(199,0,83270),
(200,0,83300);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (83270,83300);
