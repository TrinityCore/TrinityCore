DELETE FROM `spell_target_position` WHERE `id` IN (110966, 109977, 109976, 109972, 109984, 108449);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(110966, 974, -4008.5, 6270.1, 11.68, 0.746128), -- Stay Out!
(109977, 974, -4008.5, 6270.1, 11.68, 0.746128), -- Stay Out!
(109976, 974, -4122.7, 6338.68, 10.64, 4.35512), -- Stay Out!
(109972, 974, -4285.47, 6319, 12.95, 4.31184), -- Stay Out!
(109984, 967, -13855, -13655.7, 265.754, 1.5708), -- Anti-Exploit LOS Check
(108449, 967, -12094.6, 12164.3, -2.7352, 5.75959); -- Teleport Single - To Maelstrom
