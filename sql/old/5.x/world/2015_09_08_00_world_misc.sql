DELETE FROM `areatrigger_teleport` WHERE `id` IN (45,8077,6338,614,7801,7802);
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(45, 'Scarlet Monastery (Entrance)', 1004, 1124.55, 511.649, 0.98954, 3.50405),
(614, 'Scarlet Halls (Entrance)', 1001, 821.387, 607.73, 13.623, 0.069143),
(7801, 'Scarlet Halls (Exit)', 0, 2873.77, -818.876, 160.332, 0.34207),
(7802, 'Scarlet Monastery (Exit)', 0, 2904.94, -805.904, 160.332, 3.45513);

DELETE FROM `instance_template` WHERE `map` IN (189,1001,1004);
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES
(1001, 0, 'instance_scarlet_halls', 0),
(1004, 0, 'instance_scarlet_monastery', 0);
