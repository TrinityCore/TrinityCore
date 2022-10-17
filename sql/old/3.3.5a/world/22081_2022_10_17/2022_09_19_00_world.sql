DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 130 AND 136;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(130,'Deadmines - Edwin VanCleef',4),
(131,'Deadmines - Captain Greenskin',4),
(132,'Deadmines - Cookie',4),
(133,'Deadmines - Mr. Smite',4),
(134,'Deadmines - Gilnid',4),
(135,'Deadmines - Sneed',4),
(136,'Deadmines - Rhahk''Zor',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 130 AND 136;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(36,5,23,130,1),
(36,4,23,131,1),
(36,6,23,132,1),
(36,3,23,133,1),
(36,2,23,134,1),
(36,1,23,135,1),
(36,0,23,136,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 130 AND 136;
INSERT INTO `spawn_group` SELECT 130, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79336 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 131, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79333 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 132, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79344 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 133, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79337 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 134, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79206 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 135, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79223 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 136, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79168 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(130,0,79336),
(131,0,79333),
(132,0,79344),
(133,0,79337),
(134,0,79206),
(135,0,79223),
(136,0,79168);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (79336,79333,79344,79337,79206,79223,79168);
