-- Svala Ritual - Player teleport position
DELETE FROM `spell_target_position` WHERE `id` = 48267;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('48267', '575', '296.632', '-346.075', '90.5474', '4.60767');

-- Svala Ritual - Svala teleport position
DELETE FROM `spell_target_position` WHERE `id` = 48276;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
('48276', '575', '296.651', '-346.293', '108.5474', '1.58');

-- Summon Ritual Channeler positions
DELETE FROM `spell_target_position` WHERE `id` IN (48271, 48274, 48275);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
('48271', '575', '296.42', '-355.01', '90.94', '1.58'),
('48274', '575', '302.36', '-352.01', '90.54', '2.20'),
('48275', '575', '291.39', '-352.01', '90.54', '0.91');
