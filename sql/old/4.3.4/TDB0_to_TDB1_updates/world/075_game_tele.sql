UPDATE `game_tele` SET `position_x` = 1569.97, `position_y` = -4397.41, `position_z` = 16.0472, `orientation` = 0.543025 WHERE `name` = 'Orgrimmar';
UPDATE `game_tele` SET `position_x` = -9574.83, `position_y` = -924.954, `position_z` = 100.272, `orientation` = 3.13119 WHERE `name` = 'Uldum';
UPDATE `game_tele` SET `position_x` = 4023.99, `position_y` = -5888.25, `position_z` = 114.119, `orientation` = 2.9839 WHERE `name` = 'Azshara';

DELETE FROM `game_tele` WHERE `id` BETWEEN 1518 AND 1520;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(1518, 915.004, 503.842, -49.23, 0.196921, 646, 'Deepholm'),
(1519, 851.307, 1067.76, -10.0183, 4.50656, 730, 'TheMaelstrom'),
(1520, -537.502, 314.923, 115.499, 5.96777, 720, 'Firelands');
