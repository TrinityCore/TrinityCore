DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 176 AND 178;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(176,'Coilfang: The Slave Pens - Mennu the Betrayer',4),
(177,'Coilfang: The Slave Pens - Rokmar the Crackler',4),
(178,'Coilfang: The Slave Pens - Quagmirran',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 176 AND 178;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(547,0,23,176,1),
(547,1,23,177,1),
(547,2,23,178,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 176 AND 178;
INSERT INTO `spawn_group` SELECT 176, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79362 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 177, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79339 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 178, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=80260 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(176,0,79362),
(177,0,79339),
(178,0,80260);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (79362,79339,80260);
