DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 286 AND 292;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(286,'Zul''gurub - High Priestess Jeklik',4),
(287,'Zul''gurub - High Priest Venoxis',4),
(288,'Zul''gurub - High Priestess Mar''li',4),
(289,'Zul''gurub - High Priest Thekal',4),
(290,'Zul''gurub - Hakkar',4),
(291,'Zul''gurub - Bloodlord Mandokir',4),
(292,'Zul''gurub - Jin''do the Hexxer',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 286 AND 292;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(309,0,23,286,1),
(309,1,23,287,1),
(309,2,23,288,1),
(309,4,23,289,1),
(309,5,23,290,1),
(309,6,23,291,1),
(309,7,23,292,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 286 AND 292;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(286,0,49199),
(287,0,49194),
(288,0,49258),
(289,0,49310),
(290,0,49678),
(291,0,49286),
(292,0,49655);

DELETE FROM `event_scripts` WHERE `id`=9104;
