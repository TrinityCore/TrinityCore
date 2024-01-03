SET @TEL_ID := 2042;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+4;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,5245.02,9825.38,-92.383,4.37643,1669,'AzurelightSquare'),
(@TEL_ID+1,5837.74,10642.8,10.5573,3.10172,1669,'ShadowguardIncursion'),
(@TEL_ID+2,5066,10094.8,-72.6842,5.10527,1669,'RuinsOfOronaar'),
(@TEL_ID+3,5527.87,9422.66,-61.7522,4.76912,1669,'ConservatoryOfTheArcane'),
(@TEL_ID+4,5680.95,9918.03,-72.6467,0.787935,1669,'Eredath');
