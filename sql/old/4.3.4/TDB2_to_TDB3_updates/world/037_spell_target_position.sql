DELETE FROM `spell_target_position` WHERE `id` IN (17608, 17610, 17611);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(17608, 1, 9656.54, 2518.26, 1331.66, 0), -- Portal Effect: Darnassus
(17610, 1, -967.375, 284.82, 110.773, 3.199991), -- Portal Effect: Thunder Bluff
(17611, 0, 1773.42, 61.7391, -46.3215, 0); -- Portal Effect: Undercity
