-- because OF COURSE the names had to be wrong. OF. COURSE.
UPDATE `pool_template` SET `description` = 'Noblegarden Eggs - Khanaros' WHERE `entry`=5699;
UPDATE `pool_template` SET `description` = 'Noblegarden Eggs - Goldshire' WHERE `entry`=5700;
UPDATE `pool_template` SET `description` = 'Noblegarden Eggs - Brill' WHERE `entry`=5701;
UPDATE `pool_template` SET `description` = 'Noblegarden Eggs - Falconwing Square' WHERE `entry`=5702;
UPDATE `pool_template` SET `description` = 'Noblegarden Eggs - Azure Watch' WHERE `entry`=5703;
UPDATE `pool_template` SET `description` = 'Noblegarden Eggs - Dolanaar' WHERE `entry`=5704;
UPDATE `pool_template` SET `description` = 'Noblegarden Eggs - Razor Hill' WHERE `entry`=5705;
UPDATE `pool_template` SET `description` = 'Noblegarden Eggs - Bloodhoof Village' WHERE `entry`=5706;

DROP TABLE IF EXISTS `game_event_pool`;

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 57 AND 60;
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 57 AND 60;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(57, 'Noblegarden Eggs - Kalimdor', 4),
(58, 'Noblegarden Eggs - Eastern Kingdoms', 4),
(59, 'Noblegarden Eggs - BC Starter Areas', 4),
(60, 'At night - Eastern Kingdoms', 4);

INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(57,2,5704),
(57,2,5705),
(57,2,5706),
(58,2,5699),
(58,2,5700),
(58,2,5701),
(59,2,5702),
(59,2,5703),
(60,2,1004);

DROP TABLE IF EXISTS `game_event_spawn_group`;
CREATE TABLE `game_event_spawn_group` (
  `event` tinyint(4) NOT NULL COMMENT 'game_event entry - negative entry to only spawn if event is not active',
  `groupId` int(10) UNSIGNED NOT NULL,
  PRIMARY KEY (`groupId`)
) ENGINE = MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `game_event_spawn_group` (`event`,`groupId`) VALUES
(9,57),
(9,58),
(9,59),
(25,60);
