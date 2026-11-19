DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 173 AND 175;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(173,'Coilfang: The Steamvault - Hydromancer Thespia',4),
(174,'Coilfang: The Steamvault - Mekgineer Steamrigger',4),
(175,'Coilfang: The Steamvault - Warchief Kargath Bladefist',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 173 AND 175;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(545,0,23,173,1),
(545,1,23,174,1),
(545,2,23,175,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 173 AND 175;
INSERT INTO `spawn_group` SELECT 173, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=3453 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 174, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=12597 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 175, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=12613 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(173,0,3453),
(174,0,12597),
(175,0,12613);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (3453,12597,12613);
