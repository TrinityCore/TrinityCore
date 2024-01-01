SET @TELEID := 1964;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TELEID+0 AND @TELEID+2;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES 
(@TELEID+0, 115.639, -939.723, 836.586, 1.60829, 2444, 'Valdrakken'),
(@TELEID+1, 2212.78, 2481.39, 711.777, 0.019635128, 2569, 'AberrusRaid'),
(@TELEID+2, 100.62, 2523.3, -113.503, 6.09232, 2454, 'ZaralekCavern');
