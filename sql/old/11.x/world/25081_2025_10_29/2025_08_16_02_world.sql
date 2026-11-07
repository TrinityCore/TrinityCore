SET @TELEID := 2305;

-- Tele names
DELETE FROM `game_tele` WHERE `id` BETWEEN @TELEID+0 AND @TELEID+2;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(@TELEID+0, 791.818, -1053.45, 999.725, 1.62946, 2830, 'EcoDomeAldaniDungeon'),
(@TELEID+1, -703.93, -61.0299, 531.427, 0.386321, 2738, 'Karesh'),
(@TELEID+2, 2362.92, 2745.66, -290.587, 3.14532, 2810, 'ManaforgeOmegaRaid');
