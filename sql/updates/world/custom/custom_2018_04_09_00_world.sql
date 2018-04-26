-- Update Deadmines teleport to be outside of the instance
UPDATE `game_tele` SET `position_x`= -11208.16, `position_y`= 1672.81, `position_z`= 24.65, `orientation`= 1.528916, `map`= 0 WHERE `id`= 260;

-- Update Firelands teleport to be outside of the instance
UPDATE `game_tele` SET `position_x`= 3991.27, `position_y`= -2952.46, `position_z`= 1002.55, `orientation`= 1.962241, `map`= 1 WHERE `id`= 1520;

-- Rename VortexPinnacle to VortexSummit to reflect the actual location name
UPDATE `game_tele` SET `name`= 'VortexSummit' WHERE `id`= 1301;

DELETE FROM `game_tele` WHERE `id` BETWEEN 1524 AND 1532;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(1524, -10194.8, -1837.65, 20.1282, 3.13903, 1, 'HallsOfOrigination'),
(1525, -10667.5, -1303.97, 15.3534, 3.39428, 1, 'LostCityOfTheTolvir'),
(1526, -11506.6, -2304.29, 608.394, 3.83882, 1, 'TheVortexPinnacle'),
(1527, -11351.8, 49.8219, 723.885, 1.94915, 1, 'ThroneOfTheFourWinds'),
(1528, -4887.03, -4245.4, 827.764, 2.08397, 0, 'BastionOfTwilight'),
(1529, -7537.35, -1199.88, 477.721, 1.93083, 0, 'BlackwingDescent'),
(1530, 1024.46, 641.61, 156.673, 4.91323, 646, 'TheStoneCore'),
(1531, -5598.9, 5411.9, -1798.71, 5.63353, 0, 'ThroneOfTheTides'),
(1532, -8284.39, -4521.57, -219.041, 0.338499, 1, 'DragonSoul');
