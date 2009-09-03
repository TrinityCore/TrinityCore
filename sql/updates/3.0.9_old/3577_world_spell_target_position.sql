-- positions for teleports in acherus
DELETE FROM `spell_target_position` WHERE `id` IN (54744,54746);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(54744, 0, 2418.67, -5621.41, 420.644, 3.89597),
(54746, 0, 2402.15, -5633.74, 377.021, 3.65249);
