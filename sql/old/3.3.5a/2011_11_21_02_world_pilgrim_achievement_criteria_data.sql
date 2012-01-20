-- Achievement: Turkey Lurkey
DELETE FROM `achievement_criteria_data` WHERE `type`=2 AND `criteria_id` IN (11158,11159,11160,11161,11162,11163,11164,11165);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`) VALUES
(11158, 2, 4, 1), -- Human Rogue
(11159, 2, 4, 4), -- Night Elf Rogue
(11160, 2, 4, 2), -- Orc Rogue
(11161, 2, 4, 8), -- Troll Rogue
(11162, 2, 4, 5), -- Undead Rogue
(11163, 2, 4, 10), -- Blood Elf Rogue
(11164, 2, 4, 3), -- Dwarf Rogue
(11165, 2, 4, 7); -- Gnome Rogue
