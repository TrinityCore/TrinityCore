DELETE FROM `instance_template` WHERE `map` = 1098;
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES
(1098, 0, 'instance_throne_of_thunder', 0);

DELETE FROM `areatrigger_teleport` WHERE `id` IN (8881,8882);
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(8882, 'Throne of Thunder (Entrance', 1098, 5892.46, 6610.36, 106.108, 4.52039),
(8881, 'Throne of Thunder (Exit)', 1064, 7241.19, 5038.32, 76.22, 2.33991);
