DELETE FROM `spell_target_position` WHERE `id` IN (49363, 84464, 49358);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(49363, 0, -10469, -3331.54, 25.4716, 0.98606), -- Portal Effect: Stonard
(84464, 646, 854.924, 1080.96, -12.5196, 4.54772), -- Portal to the Maelstrom
(49358, 0, -10469, -3331.54, 25.4716, 0.98606); -- Teleport: Stonard
