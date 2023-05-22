DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 221 AND 223;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(221,'Utgarde Keep - Prince Keleseth',4),
(222,'Utgarde Keep - Skarvold & Dalronn',4),
(223,'Utgarde Keep - Ingvar the Plunderer',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 221 AND 223;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(574,0,23,221,1),
(574,1,23,222,1),
(574,2,23,223,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 221 AND 223;
INSERT INTO `spawn_group` SELECT 221, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=126025 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 222, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=126023 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 223, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=126026 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(221,0,126025),
(222,0,126023),
(223,0,126026);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (126025,126023,126026);
