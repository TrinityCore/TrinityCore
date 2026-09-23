SET @TEL_ID := 2308; -- Need 6

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+5;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0, 6391.470703, -4297.713867, 77.154976, 5.925344, 0, 'EversongWoodsMidnight'),
(@TEL_ID+1, 8315.890625, -4616.469727, 18.666515, 6.274837, 0, 'SilvermoonCityMidnight'),
(@TEL_ID+2, 4887.920898, -6569.641602, 207.599823, 0.024978, 0, 'ZulamanMidnight'),
(@TEL_ID+3, 130.340652, -297.814728, 1489.653931, 4.760504, 2694, 'Harandar'),
(@TEL_ID+4, 1914.971924, 595.520386, -180.044312, 4.725320, 2771, 'Voidstorm'),
(@TEL_ID+5, 16.510880, 53.987453, -0.006534, 0.048404, 2195, 'Arcantina');
