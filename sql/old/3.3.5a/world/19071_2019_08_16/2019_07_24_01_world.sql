DROP TABLE IF EXISTS `player_totem_model`;
CREATE TABLE `player_totem_model` (
  `TotemSlot` TINYINT(3) UNSIGNED NOT NULL,
  `RaceId` TINYINT(3) UNSIGNED NOT NULL,
  `DisplayId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`TotemSlot`,`RaceID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `player_totem_model` (`TotemSlot`, `RaceId`, `DisplayId`) VALUES
-- Orc
(1, 2, 30758),
(2, 2, 30757),
(3, 2, 30759),
(4, 2, 30756),
-- Dwarf
(1, 3, 30754),
(2, 3, 30753),
(3, 3, 30755),
(4, 3, 30736),
-- Tauren
(1, 6, 4589),
(2, 6, 4588),
(3, 6, 4587),
(4, 6, 4590),
-- Troll
(1, 8, 30762),
(2, 8, 30761),
(3, 8, 30763),
(4, 8, 30760),
-- Draenei
(1, 11, 19074),
(2, 11, 19073),
(3, 11, 19075),
(4, 11, 19071);
