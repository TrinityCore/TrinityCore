DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 201 AND 203;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(201,'Auchindoun: Mana-Tombs - Pandemonius',4),
(202,'Auchindoun: Mana-Tombs - Tavarok',4),
(203,'Auchindoun: Mana-Tombs - Nexus-Prince Shaffar',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 201 AND 203;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(557,0,23,201,1),
(557,1,23,202,1),
(557,2,23,203,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 201 AND 203;
INSERT INTO `spawn_group` SELECT 201, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=91163 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 202, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=91161 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 203, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=91162 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(201,0,91163),
(202,0,91161),
(203,0,91162);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (91163,91161,91162);
