-- 
SET @ID := 1429; -- Need 4 change it for 4.3.4 and master
DELETE FROM `game_tele` WHERE `id` BETWEEN @ID AND @ID+3;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(@ID  , 3670.24, 6784.35, 170.181, 1.4044, 571, "Coldarra"),
(@ID+1, 3606.76, 5944.54, 136.216, 2.84247, 571, "AmberLedge"),
(@ID+2, 2967.29, 6788.09, 7.05211, 5.86967, 571, "Garrosh'sLanding"),
(@ID+3, 3543.21, 271.834, 342.721, 3.15239, 571, "WyrmrestTemple");
