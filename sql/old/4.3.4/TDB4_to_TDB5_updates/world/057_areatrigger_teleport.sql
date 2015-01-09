DELETE FROM `areatrigger_teleport` WHERE `id` IN (5893, 5895);
INSERT INTO `areatrigger_teleport` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `name`) VALUES
(5893, 1, 3948.62, -2818.22, 618.747, 0, 'Hyjal - Teleport from Seat of the Prophets'),
(5895, 1, 4316.05, -3282.51, 1035.53, 0, 'Hyjal - Teleport From Sulfuron Spire');
