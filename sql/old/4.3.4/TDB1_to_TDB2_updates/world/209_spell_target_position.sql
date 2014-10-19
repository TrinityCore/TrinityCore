DELETE FROM `spell_target_position` WHERE `id` IN (89597, 96178, 88339);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(89597, 732, -337.673, 1058.18, 21.8901, 1.747511), -- Teleport: Tol Barad
(96178, 0, -8207.63, 447.785, 117.651, 4.985708), -- Portal Effect: Stormwind
(88339, 732, -369.208, 1058.73, 21.7719, 0.6345773); -- Portal Effect: Tol Barad
