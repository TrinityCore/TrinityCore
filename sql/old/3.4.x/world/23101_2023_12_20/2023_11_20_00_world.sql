DROP TABLE IF EXISTS `player_racestats`;
CREATE TABLE IF NOT EXISTS `player_racestats` (
`race` tinyint unsigned NOT NULL,
`str` smallint NOT NULL COMMENT 'strength',
`agi` smallint NOT NULL COMMENT 'agility',
`sta` smallint NOT NULL COMMENT 'stamina',
`inte` smallint NOT NULL COMMENT 'intellect',
`spi` smallint NOT NULL COMMENT 'spirit',
`comment` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
PRIMARY KEY (`race`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Stores race stats.';

DELETE FROM `player_racestats`;
INSERT INTO `player_racestats` (`race`, `str`, `agi`, `sta`, `inte`, `spi`, `comment`) VALUES
(1, 0, 0, 0, 0, 0, 'Human'),
(2, 3, -3, 1, -3, -2, 'Orc'),
(3, 5, -4, 1, -1, -1, 'Dwarf'),
(4, -4, 4, 0, 0, 0, 'Night Elf'),
(5, -1, -2, 0, -2, 5, 'Undead'),
(6, 5, -4, 1, -4, 2, 'Tauren'),
(7, -5, 2, 0, 3, 0, 'Gnome'),
(8, 1, -2, 0, -4, 1, 'Troll'),
(10, -3, 2, 0, 3, -2, 'Blood Elf'),
(11, 1, -3, 0, 0, 2, 'Draenei');
