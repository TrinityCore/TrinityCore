DELETE FROM `areatrigger_teleport` WHERE `id` IN (5926, 6073);
INSERT INTO `areatrigger_teleport` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `name`) VALUES
(5926, 659, 1172.59, 1094.79, 119.232, 1.5708, 'The Lost Isles - Volcanoth''s Lair - Teleport Target - Phase 8+'),
(6073, 0, -5592.83, 5408.36, -1798.57, 2.44346, 'Vashj''ir - Throne of Tides Exit Target');

UPDATE `areatrigger_teleport` SET `name`='Scholomance - Entrance target', `target_position_x`=199.876, `target_position_y`=125.346, `target_position_z`=138.43, `target_orientation`=4.67748 WHERE `id`=2567;
UPDATE `areatrigger_teleport` SET `name`='Scholomance - Stairs Exit Target 001', `target_position_x`=1273.91, `target_position_y`=-2553.09, `target_position_z`=91.8393, `target_orientation`=3.57792 WHERE `id`=2568;
