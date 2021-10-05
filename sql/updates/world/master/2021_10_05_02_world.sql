-- New Player Experience - Exile's Reach
DELETE FROM `game_tele` WHERE `id`= 1689 AND `map`= 1757;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(1757, -484.445, -2618.382, 4.012, 6.155, 2175, 'ExilesReach');
