DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 215 AND 220;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(215,'Zul''Aman - Nalorakk',4),
(216,'Zul''Aman - Akil''zon',4),
(217,'Zul''Aman - Jan''alai',4),
(218,'Zul''Aman - Halazzi',4),
(219,'Zul''Aman - Hex Lord Malacrass',4),
(220,'Zul''Aman - Zul''jin',4);


DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 215 AND 220;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(568,0,23,215,1),
(568,1,23,216,1),
(568,2,23,217,1),
(568,3,23,218,1),
(568,4,23,219,1),
(568,5,23,220,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 215 AND 220;
INSERT INTO `spawn_group` SELECT 215, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=86609 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 216, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=86494 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 217, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=89322 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 218, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=86195 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 219, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=89357 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 220, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=89358 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(215,0,86609),
(216,0,86494),
(217,0,89322),
(218,0,86195),
(219,0,89357),
(220,0,89358);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (86609,86494,89322,86195,89357,89358);
