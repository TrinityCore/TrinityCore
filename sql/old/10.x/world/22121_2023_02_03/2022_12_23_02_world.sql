-- 
SET @TELEID := 1959;
DELETE FROM `game_tele` WHERE `id` BETWEEN @TELEID+0 AND @TELEID+5;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES 
(@TELEID+0, -1365.67, -2966.95, 1174.7, 0.677586, 2444, 'Thaldraszus'),
(@TELEID+1, 6510.56, -3318.14, 162.985, 5.60205, 2444, 'ForbiddenReach'),
(@TELEID+2, -3817.34, 505.7, 647.829, 5.60991, 2444, 'AzureSpan'),
(@TELEID+3, -620.498, 2198.33, 436.668, 1.7104, 2444, 'OhnahranPlains'),
(@TELEID+4, 2934.35, 188.591, 498.596, 3.25371, 2444, 'WakingShores'),
(@TELEID+5, 115.639, -939.723, 836.586, 1.60829, 2444, 'Valdrakken');
