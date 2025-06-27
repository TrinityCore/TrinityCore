DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 238 AND 241;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(238,'Magister''s Terrace - Selin Fireheart',4),
(239,'Magister''s Terrace - Vexallus',4),
(240,'Magister''s Terrace - Priestess Delrissa',4),
(241,'Magister''s Terrace - Kael''thas Sunstrider',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 238 AND 241;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(585,0,23,238,1),
(585,1,23,239,1),
(585,2,23,240,1),
(585,3,23,241,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 238 AND 241;
INSERT INTO `spawn_group` SELECT 238, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=96875 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 239, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=96876 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 240, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=96966 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 241, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=96762 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(238,0,96875),
(239,0,96876),
(240,0,96966),
(241,0,96762);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (96875,96876,96966,96762);
