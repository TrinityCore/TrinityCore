SET @TEL_ID := 2006;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+5;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,969.152,1615.3,535.568,1.38247,1669,'KrokulHovel'),
(@TEL_ID+1,890.549,2562.48,389.29,5.56236,1669,'ShatteredFields'),
(@TEL_ID+2,1240.26,2363,451.079,0.282137,1669,'TheXenedar'),
(@TEL_ID+3,1069.35,1126.49,490.827,6.08936,1669,'PetrifiedForest'),
(@TEL_ID+4,1246.06,1712.26,515.311,6.26608,1669,'AnnihilanPits'),
(@TEL_ID+5,1949.59,1653.62,353.151,0.732167,1669,'NathraxasHold');
