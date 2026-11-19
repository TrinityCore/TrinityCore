DELETE FROM `spell_target_position` WHERE `id` IN (84699, 84700);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(84699, 646, 2338.16, 143.69, 179.19, 1.13103), -- Teleport to Therazane's Throne
(84700, 646, 1076.78, 537.665, -44.5984, 3.31836); -- Teleport to Temple of Earth
