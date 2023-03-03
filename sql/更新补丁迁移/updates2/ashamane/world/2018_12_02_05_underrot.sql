DELETE FROM `instance_template` WHERE `map` = 1841;
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`, `insideResurrection`) VALUES (1841, 0, 'instance_the_underrot', 0, 0);

DELETE FROM `game_tele` WHERE `id` = 1872;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES (1872, 625.044, 1253.41, 99.8346, 6.27532, 1841, 'theunderrot');
