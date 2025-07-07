SET @TELEID := 2183;

-- Add TWW Zone teleports
DELETE FROM `game_tele` WHERE `id` BETWEEN @TELEID+0 AND @TELEID+5;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(@TELEID+0, 2663.1, -2587.58, 219.653, 3.13936, 2552, 'Dornogal'),
(@TELEID+1, 1934.17, -3084.21, 154.751, 0.787718, 2552, 'IsleOfDorn'),
(@TELEID+2, 2064.52, -120.168, -156.296, 0.359316, 2601, 'Hallowfall'),
(@TELEID+3, 1749.21, -3332.27, 316.996, 3.21586, 2601, 'TheRingingDeeps'),
(@TELEID+4, 103.293, -1396.45, -1063.93, 1.43191, 2601, 'AzjKahet'),
(@TELEID+5, 1944.88, 170.002, 88.6878, 5.36686, 2127, 'SirenIsle');
