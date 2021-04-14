DELETE FROM `spell_target_position` WHERE `id` IN (88341, 96177, 44089, 17334, 102864, 94564, 94565, 103582);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(88341, 732, -603.724, 1387.62, 22.0498, 0.4696437), -- Portal Effect: Tol Barad (Horde)
(96177, 1, 2032.8, -4335.14, 95.4723, 5.033966), -- Portal Effect: Orgrimmar
(44089, 0, -4613.71, -915.287, 501.062, 0), -- Portal Effect: Ironforge
(17334, 0, -8998.14, 861.254, 29.6206, 2.25), -- Portal Effect: Stormwind
(102864, 974, -3618.67, 6315.67, 113.19, 3.204424), -- To the Faire!
(94564, 1, -9443.31, -958.365, 111.012, 5.390484), -- Teleport to Uldum [INTERNAl]
(94565, 1, 5534.08, -3624.69, 1567.04, 5.390484), -- Teleport to Hyjal [INTERNAl]
(103582, 1, -1444.41, 215.34, -7.75, 3.763803); -- To the Staging Area! - Mulgore
