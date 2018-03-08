DELETE FROM `instance_template` WHERE `map` = 1712;
INSERT INTO `instance_template` (`map`, `parent`, `allowMount`) VALUES
(1712, 1220, 1);

DELETE FROM `game_tele` WHERE `id` = 1784;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) values
(1784, 2866.45, -4567.44, 291.949, 0.0926814, 1712, "LegionAntorustheBurningThroneSeatofthePantheon");
