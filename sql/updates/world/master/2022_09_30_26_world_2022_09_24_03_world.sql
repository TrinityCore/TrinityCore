DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 253 AND 256;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(253,'Halls of Lightning - General Bjarngrim',4),
(254,'Halls of Lightning - Volkhan',4),
(255,'Halls of Lightning - Ionar',4),
(256,'Halls of Lightning - Loken',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 253 AND 256;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(602,0,23,253,1),
(602,1,23,254,1),
(602,2,23,255,1),
(602,3,23,256,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 253 AND 256;
INSERT INTO `spawn_group` SELECT 253, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=126981 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 254, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=126982 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 255, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=126873 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 256, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=126985 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(253,0,126981),
(254,0,126982),
(255,0,126873),
(256,0,126985);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (126981,126982,126873,126985);
