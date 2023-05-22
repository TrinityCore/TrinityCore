DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 262 AND 275;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(262,'Icecrown Citadel - Lord Marrowgar',4),
(263,'Icecrown Citadel - Lady Deathwhisper',4),
(264,'Icecrown Citadel - Deathbringer Saurfang',4),
(265,'Icecrown Citadel - Rotface',4),
(266,'Icecrown Citadel - Festergut',4),
(267,'Icecrown Citadel - Professor Putricide',4),
(268,'Icecrown Citadel - Blood Council',4),
(269,'Icecrown Citadel - Queen Lana''thel',4),
(270,'Icecrown Citadel - Valithria Dreamwalker',4),
(271,'Icecrown Citadel - The Lich King',4),
(272,'Icecrown Citadel - Sister Svalna',4),
(273,'Icecrown Citadel - Rimefang',4),
(274,'Icecrown Citadel - Spinestalker',4),
(275,'Icecrown Citadel - The Damned RP Event at entrance',0);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 262 AND 275;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(631, 0,23,262,1),
(631, 1,23,263,1),
(631, 3,23,264,1),
(631, 5,23,265,1),
(631, 4,23,266,1),
(631, 6,23,267,1),
(631, 7,23,268,1),
(631, 8,23,269,1),
(631, 9,23,270,1),
(631,11,23,271,1),
(631, 9,23,272,1),
(631,10,23,273,1),
(631,10,23,274,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 262 AND 275;
INSERT INTO `spawn_group` SELECT 262, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=200992 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 263, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=201129 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 264, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=201122 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 265, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=201433 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 266, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=201255 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 267, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=201294 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 268, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=201369 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 269, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=201246 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 270, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=137752 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 271, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=150211 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 272, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=137753 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 273, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=207210 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 274, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=207211 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` SELECT 275, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=200984 AND `linkType` IN (0,3) AND `guid`<>`linkedGuid`;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(262,0,200992),
(263,0,201129),
(264,0,201122),
(264,0,200982),
(264,0,200907),
(264,0,200944),
(264,0,201069),
(264,0,201034),
(264,0,201184),
(264,1,151165),
(264,1,151166),
(264,1,151167),
(264,1,151168),
(265,0,201433),
(266,0,201255),
(267,0,201294),
(268,0,201369),
(269,0,201246),
(270,0,137752),
(271,0,150211),
(272,0,137753),
(273,0,207210),
(274,0,207211),
(275,0,200984);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (200992,201129,201122,201433,201255,201294,201369,201246,137752,150211,137753,207210,207211,200984);
