DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 279 AND 282;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(279,'Coilfang: The Underbog - Hungarfen',4),
(280,'Coilfang: The Underbog - Ghaz''an',4),
(281,'Coilfang: The Underbog - Swamplord Musel''ek',4),
(282,'Coilfang: The Underbog - The Black Stalker',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 279 AND 282;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(546,0,23,279,1),
(546,1,23,280,1),
(546,2,23,281,1),
(546,3,23,282,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 279 AND 282;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(279,0,56111),
(280,0,101722),
(281,0,103431),
(281,0,103246),
(282,0,54337);
