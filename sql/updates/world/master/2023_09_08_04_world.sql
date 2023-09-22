SET @TEL_ID := 1998;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+2;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,5970.37,1084.75,55.5392,0.483188,870,'IsleOfGiants'),
(@TEL_ID+1,5749,1256.48,0.930707,5.76892,870,'BeeblesWreck'),
(@TEL_ID+2,5793.35,1075.69,0.740553,0.479262,870,'BozzlesWreck');
