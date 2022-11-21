DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 257 AND 261;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(257,'Ahn''kahet: The Old Kingdom - Elder Nadox',4),
(258,'Ahn''kahet: The Old Kingdom - Prince Taldaram',4),
(259,'Ahn''kahet: The Old Kingdom - Jedoga Shadowseeker',4),
(260,'Ahn''kahet: The Old Kingdom - Amanitar',4),
(261,'Ahn''kahet: The Old Kingdom - Herald Volazj',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 257 AND 261;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(619,0,23,257,1),
(619,1,23,258,1),
(619,2,23,259,1),
(619,3,23,260,1),
(619,4,23,261,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 257 AND 261;
INSERT INTO `spawn_group` SELECT 257, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=131952 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 258, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=131951 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 259, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=131953 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 260, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=202410 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 261, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=132298 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(257,0,131952),
(258,0,131951),
(259,0,131953),
(260,0,202410),
(261,0,132298);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (131952,131951,131953,202410,132298);
