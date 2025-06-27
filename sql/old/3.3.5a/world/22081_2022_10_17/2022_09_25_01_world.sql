DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 276 AND 278;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(276,'Hellfire Citadel: The Blood Furnace - The Maker',4),
(277,'Hellfire Citadel: The Blood Furnace - Broggok',4),
(278,'Hellfire Citadel: The Blood Furnace - Keli''dan the Breaker',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 276 AND 278;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(542,0,23,276,1),
(542,1,23,277,1),
(542,2,23,278,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 276 AND 278;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(276,0,138123),
(277,0,138115),
(278,0,138147);
