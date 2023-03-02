-- stuff for SoO

-- instance template
INSERT INTO `instance_template` (`map`, `parent`, `script`,  `allowMount`) VALUES ('1136', '870', 'instance_SiegeOfOrgrimmar', '0');

-- AreaTrigger_teleport (the instance door trigger)
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('9245', 'Siege of Orgrimmar (Entrance)', '1136', '1440.84', '306.528', '289.199', '0');

INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('9244', 'Siege of Orgrimmar (EXIT)', '870', '1238.59', '605.595', '317.472', '0');

-- TODO: Spawn a instance portal gameobject and add spawns into soo, hopfully I can find a sql for this that someone already did.. spawning raids is a pain.