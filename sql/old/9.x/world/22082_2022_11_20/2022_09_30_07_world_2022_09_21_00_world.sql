DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 192 AND 194;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(192,'Tempest Keep: The Mechanar - Mechano-Lord Capacitus',4),
(193,'Tempest Keep: The Mechanar - Nethermancer Sepethrea',4),
(194,'Tempest Keep: The Mechanar - Pathaleon the Calculator',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 192 AND 194;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(554,2,23,192,1),
(554,3,23,193,1),
(554,4,23,194,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 192 AND 194;
INSERT INTO `spawn_group` SELECT 192, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=83160 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 193, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=83230 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 194, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=83241 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(192,0,83160),
(193,0,83230),
(194,0,83241);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (83160,83230,83241);
