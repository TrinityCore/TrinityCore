DELETE FROM `instance_template` WHERE `map` = 1098;
INSERT INTO `instance_template` (`map`, `parent`, `allowMount`) VALUES
(1098, 870 /* Isle of Thunder */, 0); -- Throne of Thunder Raid

DELETE FROM `game_tele` WHERE `id` IN (1566, 1567);
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) values
(1566,5710.84,4094.3,156.463,3.88393,1098, 'LeiShen'),
(1567,5525.29,4654.03,-2.47721,3.1433,1098, 'RadenRoom');