DELETE FROM `waypoint_path_node` WHERE `PathId` = 4437300;
DELETE FROM `waypoint_path` WHERE `PathId` = 4437300;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(4437300, 1, 2, 21, 'Whirlpool Vehicle - Fly Under Whirlpool');
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Delay`) VALUES
(4437300, 0, -5680, 5380, -1400, 0),
(4437300, 1, -5646.94, 5464.66, -1552.3, 0),
(4437300, 2, -5620, 5450, -1650, 0),
(4437300, 3, -5600, 5450, -1730, 0),
(4437300, 4, -5584, 5448, -1798, 0);
