DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 250 AND 252;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(250,'Azjol-Nerub - Krik''thir the Gatewatcher',4),
(251,'Azjol-Nerub - Hadronox',4),
(252,'Azjol-Nerub - Anub''arak',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 250 AND 252;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(601,0,23,250,1),
(601,1,23,251,1),
(601,2,23,252,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 250 AND 252;
INSERT INTO `spawn_group` SELECT 250, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=127214 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 251, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=127401 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 252, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=132273 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(250,0,127214),
(251,0,127401),
(252,0,132273);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (127214,127401,132273);
