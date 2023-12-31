SET @TEL_ID := 2116;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+9;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,4278.48,5853.6,4786.76,1.47456,2222,'Desmotaeron'),
(@TEL_ID+1,5152.46,6913.03,4734.33,2.00863,2222,'GorgoaRiverOfSouls'),
(@TEL_ID+2,5215.91,7504.09,4895.5,0.71115,2222,'TheTremaculum'),
(@TEL_ID+3,4901.99,7416.4,4776.32,5.50208,2222,'PlanesOfTorment'),
(@TEL_ID+4,4137.64,7879.74,4971.68,5.51228,2222,'CrucibleOfTheDamned'),
(@TEL_ID+5,4837.19,7777.55,4840.77,2.63381,2222,'Calcis'),
(@TEL_ID+6,3924.32,6546.86,4787.98,2.45551,2222,'TheBeastwarrens'),
(@TEL_ID+7,4006.65,7468.58,4818.85,2.26468,2222,'PerditionHold'),
(@TEL_ID+8,4414.25,6806.36,4878.59,0.623191,2222,'Cocyrus'),
(@TEL_ID+9,4591.67,6761.2,4850.94,4.97665,2222,'VenarisRefuge');
