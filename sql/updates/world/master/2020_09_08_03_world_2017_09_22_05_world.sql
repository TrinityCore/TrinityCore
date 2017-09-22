-- 
SET @ID := 1429;
DELETE FROM `game_tele` WHERE (`id` BETWEEN @ID AND @ID+3) OR (`id` BETWEEN 1679 AND 1682);
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(@ID  , 3670.24, 6784.35, 170.181, 1.4044, 571, "Coldarra"),
(@ID+1, 3606.76, 5944.54, 136.216, 2.84247, 571, "AmberLedge"),
(@ID+2, 2967.29, 6788.09, 7.05211, 5.86967, 571, "Garrosh'sLanding"),
(@ID+3, 3543.21, 271.834, 342.721, 3.15239, 571, "WyrmrestTemple"),
(1679, -3265.45, -2754.5, 12.6062, 0.280862, 0, 'GreenwardensGrove'),
(1680, -4121.85, -2762.32, 17.9311, 4.48274, 0, 'SlabchiselsSurvey'),
(1681, -3209, -4997.95, 119.817, 1.53891, 0, 'Thundermar'),
(1682, -2808.37, -5380.95, 173.717, 0.34903, 0, 'Kirthaven');
