DELETE FROM `player_racestats`;
INSERT INTO `player_racestats` (`race`, `agi`, `str`, `inte`, `spi`, `sta`) VALUES
(1, 0, 0, 0, 0, 0), -- Human
(2, -3, 3, -3, 2, 1), -- Orc
(3, -4, 5, -1, -1, 1), -- Dwarf
(4, 4, 4, -1, -1, 1), -- Night Elf
(5, -2, -1, -2, 5, 0), -- Undead
(6, -4, 5, -4, 3, 1), -- Tauren
(7, 2, -5, 3, 0, 0), -- Gnome
(8, 2, 1, -4, 1, 0), -- Troll
(10, 2, -3, 3, -2, 0), -- Blood Elf
(11, -3, 1, 0, 2, 0), -- Draenei
(9, 2, -3, 3, -2, 0), -- Goblin
(22, 2, 3, -4, -1, 0); -- Worgen
