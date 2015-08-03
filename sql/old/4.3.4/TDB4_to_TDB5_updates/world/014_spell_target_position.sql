DELETE FROM `spell_target_position` WHERE `id` IN (94689, 3561, 84073);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(94689, 730, 529.838, 842.595, 36.1126, 1.570796), -- Teleport Player
(3561, 0, -8998.14, 861.254, 29.6206, 2.249991), -- Teleport: Stormwind
(84073, 646, 1040.91, 544.689, 681.86, 3.97935); -- Deepholm Intro Teleport
