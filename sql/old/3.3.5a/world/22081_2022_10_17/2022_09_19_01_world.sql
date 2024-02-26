DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 137 AND 144;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(137,'Molten Core - Magmadar',4),
(138,'Molten Core - Lucifron',4),
(139,'Molten Core - Gehennas',4),
(140,'Molten Core - Garr',4),
(141,'Molten Core - Shazzrah',4),
(142,'Molten Core - Baron Geddon',4),
(143,'Molten Core - Sulfuron Harbinger',4),
(144,'Molten Core - Golemagg the Incinerator',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 137 AND 144;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(409,1,23,137,1),
(409,0,23,138,1),
(409,2,23,139,1),
(409,3,23,140,1),
(409,4,23,141,1),
(409,5,23,142,1),
(409,6,23,143,1),
(409,7,23,144,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 137 AND 144;
INSERT INTO `spawn_group` SELECT 137, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=56683 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 138, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=56605 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 139, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=56737 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 140, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=56609 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 141, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=56608 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 142, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=56655 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 143, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=56677 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 144, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=56684 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(137,0,56683),
(138,0,56605),
(139,0,56737),
(140,0,56609),
(141,0,56608),
(142,0,56655),
(143,0,56677),
(144,0,56684);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (56683,56605,56737,56609,56608,56655,56677,56684);
