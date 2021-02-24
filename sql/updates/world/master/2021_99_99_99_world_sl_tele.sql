-- Add SL maps to tele locations

SET @TELE_START_ID = 1683; -- Initial highest value of `Id` in game_ele + 1

DELETE FROM `game_tele` WHERE `id` IN (@TELE_START_ID+0, @TELE_START_ID+1, @TELE_START_ID+2, @TELE_START_ID+3, @TELE_START_ID+4, @TELE_START_ID+5);
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(@TELE_START_ID + 0, 2583 , -2521, 3307, 0, 2222, 'Maldraxxus'),
(@TELE_START_ID + 1, -1563, -4842, 6594, 0, 2222, 'Bastion'),
(@TELE_START_ID + 2, -6095, 208  , 5570, 0, 2222, 'Ardenweald'),
(@TELE_START_ID + 3, -2975, 6097 , 4086, 0, 2222, 'Revendreth'),
(@TELE_START_ID + 4, 3990 , 6294 , 4824, 0, 2222, 'TheMaw'),
(@TELE_START_ID + 5, -1637, 1285 , 5275, 0, 2222, 'Oribos');
