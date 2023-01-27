DELETE FROM `areatrigger_teleport` WHERE `id` IN (2567,2568,7539);
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(2567, 'Scholomance - (Entrance)', 1007, 197.753, 120.94, 138.429, 4.64721),
(7539, 'Scholomance - (Exit)', 0, 1267.55, -2556.8, 94.126, 3.61441);

UPDATE `instance_template` SET `script` = 'instance_scholomance', `allowMount` = '0' WHERE `map` =1007;

DELETE FROM `instance_template` WHERE `map` = 289;
