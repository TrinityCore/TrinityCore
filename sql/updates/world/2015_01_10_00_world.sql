-- add spellsummon support for Mindless Skeleton-Summon in Stratholme
DELETE FROM `spell_target_position` WHERE `id` IN (17475, 17476, 17477, 17478, 17479, 17480);
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `VerifiedBuild`) VALUES 
(17475, 0, 329, 4017.40, -3339.70, 115.05, 5.48, 0),
(17476, 0, 329, 4013.18, -3351.80, 115.05, 0.13, 0),
(17477, 0, 329, 4017.73, -3363.47, 115.05, 0.72, 0),
(17478, 0, 329, 4048.87, -3363.22, 115.05, 3.62, 0),
(17479, 0, 329, 4051.77, -3350.89, 115.05, 3.06, 0),
(17480, 0, 329, 4048.37, -3339.96, 115.05, 2.45, 0);
