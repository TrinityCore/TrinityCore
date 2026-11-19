DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 206 AND 214;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(206,'Black Temple - High Warlord Naj''entus',4),
(207,'Black Temple - Supremus',4),
(208,'Black Temple - Shade of Akama',4),
(209,'Black Temple - Teron Gorefiend',4),
(210,'Black Temple - Gurtogg Bloodboil',4),
(211,'Black Temple - Reliquary of Souls',4),
(212,'Black Temple - Mother Shahraz',4),
(213,'Black Temple - The Illidari Council',4),
(214,'Black Temple - Illidan Stormrage',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 206 AND 214;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(564,0,23,206,1),
(564,1,23,207,1),
(564,2,23,208,1),
(564,3,23,209,1),
(564,4,23,210,1),
(564,5,23,211,1),
(564,6,23,212,1),
(564,7,23,213,1),
(564,8,23,214,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 206 AND 214;
INSERT INTO `spawn_group` SELECT 206, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=40527 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 207, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=52458 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 208, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=12777 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 209, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=12843 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 210, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=52761 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 211, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=12828 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 212, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=52760 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 213, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=52479 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 214, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=52484 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(206,0,40527),
(207,0,52458),
(208,0,12777),
(209,0,12843),
(210,0,52761),
(211,0,12828),
(212,0,52760),
(213,0,52479),
(214,0,52484);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (40527,52458,12777,12843,52761,12828,52760,52479,52484);
