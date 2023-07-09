SET @TELEID := 1964;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TELEID+0 AND @TELEID+1;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES 
(@TELEID+0, 2212.78, 2481.39, 711.777, 0.019635128, 2569, 'AberrusRaid'),
(@TELEID+1, 100.62, 2523.3, -113.503, 6.09232, 2454, 'ZaralekCavern');
