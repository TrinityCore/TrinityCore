DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 157 AND 168;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(157,'Naxxramas - Anub''Rekhan',4),
(158,'Naxxramas - Grand Widow Faerlina',4),
(159,'Naxxramas - Maexxna',4),
(160,'Naxxramas - Noth the Plaguebringer',4),
(161,'Naxxramas - Heigan the Unclean',4),
(162,'Naxxramas - Loatheb',4),
(163,'Naxxramas - Patchwerk',4),
(164,'Naxxramas - Grobbulus',4),
(165,'Naxxramas - Thaddius',4),
(166,'Naxxramas - Instructor Razuvious',4),
(167,'Naxxramas - Gothik the Harvester',4),
(168,'Naxxramas - The Four Horsemen',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 157 AND 168;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(533,0,23,157,1),
(533,1,23,158,1),
(533,2,23,159,1),
(533,3,23,160,1),
(533,4,23,161,1),
(533,5,23,162,1),
(533,6,23,163,1),
(533,7,23,164,1),
(533,9,23,165,1),
(533,10,23,166,1),
(533,11,23,167,1),
(533,12,23,168,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 157 AND 168;
INSERT INTO `spawn_group` SELECT 157, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=127814 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 158, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=127800 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 159, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=130960 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 160, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=127801 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 161, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=127789 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 162, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=128066 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 163, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=128135 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 164, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=127781 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 165, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=130957 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 166, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=128312 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 167, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=128311 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 168, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=130963 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(157,0,127814),
(158,0,127800),
(159,0,130960),
(160,0,127801),
(161,0,127789),
(162,0,128066),
(163,0,128135),
(164,0,127781),
(165,0,130957),
(166,0,128312),
(167,0,128311),
(168,0,130961),
(168,0,130962),
(168,0,130963),
(168,0,130964);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (127814,127800,130960,127801,127789,128066,128135,127781,130957,128312,128311,130963);
