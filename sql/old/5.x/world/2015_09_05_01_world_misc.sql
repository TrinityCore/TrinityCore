DELETE FROM `areatrigger_teleport` WHERE `id` IN (9244,9245);
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(9244, 'Siege Of Orgrimmar (Exit)', 870, 1238.35, 605.357, 317.472, 2.24623),
(9245, 'Siege Of Orgrimmar (Entrance - Vale of Eternal Sorrows)', 1136, 1441.21, 262.59, 283.559, 1.56356);

DELETE FROM `instance_template` WHERE `map` = 1136;
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES
(1136, 0, 'instance_siege_of_orgrimmar', 0);
