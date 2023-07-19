DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 169 AND 172;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(169,'Hellfire Citadel: The Shattered Halls - Grand Warlock Nethekurse',4),
(170,'Hellfire Citadel: The Shattered Halls - Blood Guard Porung',4),
(171,'Hellfire Citadel: The Shattered Halls - Warbringer O''mrogg',4),
(172,'Hellfire Citadel: The Shattered Halls - Warchief Kargath Bladefist',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 169 AND 172;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(540,0,23,169,1),
(540,1,23,170,1),
(540,2,23,171,1),
(540,3,23,172,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 169 AND 172;
INSERT INTO `spawn_group` SELECT 169, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=57853 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 170, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=34038 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 171, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=57855 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 172, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=57854 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(169,0,57853),
(170,0,34038),
(171,0,57855),
(172,0,57854);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (57853,34038,57855,57854);
