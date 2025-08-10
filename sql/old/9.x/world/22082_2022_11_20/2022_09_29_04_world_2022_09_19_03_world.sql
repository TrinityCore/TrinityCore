DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 149 AND 156;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(149,'Karazhan - Attumen the Huntsman',4),
(150,'Karazhan - Moroes',4),
(151,'Karazhan - Maiden of Virtue',4),
(152,'Karazhan - The Curator',4),
(153,'Karazhan - Shade of Aran',4),
(154,'Karazhan - Terestian Illhoof',4),
(155,'Karazhan - Netherspite',4),
(156,'Karazhan - Prince Malchezaar',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 149 AND 156;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(532,0,23,149,1),
(532,1,23,150,1),
(532,2,23,151,1),
(532,5,23,152,1),
(532,6,23,153,1),
(532,7,23,154,1),
(532,8,23,155,1),
(532,10,23,156,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 149 AND 156;
INSERT INTO `spawn_group` SELECT 149, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=135159 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 150, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=135472 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 151, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=135474 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 152, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=135489 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 153, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=135692 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 154, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=135473 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 155, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=135476 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 156, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=135477 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(149,0,135159),
(150,0,135472),
(151,0,135474),
(152,0,135489),
(153,0,135692),
(154,0,135473),
(155,0,135476),
(156,0,135477);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (135159,135472,135474,135489,135692,135473,135476,135477);
