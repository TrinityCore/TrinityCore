SET @TEL_ID := 1848;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+3;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,774.066,-201.828,401.792,0.574256,870,'TavernInTheMists'),
(@TEL_ID+1,947.759,-66.526,504.538,0.951248,870,'TerraceOfEndlessSpring'),
(@TEL_ID+2,1159.76,-122.609,475.871,0.00483759,870,'TheAncientPassage'),
(@TEL_ID+3,894.76,-166.987,422.929,0.701487,870,'TheSpringRoad');
