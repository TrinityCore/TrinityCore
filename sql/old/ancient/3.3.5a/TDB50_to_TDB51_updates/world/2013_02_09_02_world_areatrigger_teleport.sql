DELETE FROM `areatrigger_teleport` WHERE `id` IN (4233, 4267);
INSERT INTO `areatrigger_teleport` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `name`) VALUES
(4233, 530, 9331.49, -7812.27, 136.569, 5.23599, 'Eversong Woods - Duskwither UP Target'),
(4267, 530, 9334.03, -7880.02, 74.9095, 2.35619, 'Eversong Woods - Duskwither DOWN Target');
