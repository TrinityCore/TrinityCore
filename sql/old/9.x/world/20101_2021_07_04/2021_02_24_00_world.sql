-- Add SL maps to tele locations
SET @TELE_START_ID = 1683;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TELE_START_ID+0 AND @TELE_START_ID+5;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TELE_START_ID+0,2583,-2521,3308,0,2222,'Maldraxxus'),
(@TELE_START_ID+1,-2943,-4871,6705,0,2222,'Bastion'),
(@TELE_START_ID+2,-6926,883,5669,0,2222,'Ardenweald'),
(@TELE_START_ID+3,-2628,6036,4116,0,2222,'Revendreth'),
(@TELE_START_ID+4,4611,6796,4869,2,2222,'TheMaw'),
(@TELE_START_ID+5,-1834,1542,5275,4.712388,2222,'Oribos');
