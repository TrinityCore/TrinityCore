-- 
SET @ATID := 7;
SET @WORLDSAFELOCID := 100018;

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLDSAFELOCID+0 AND @WORLDSAFELOCID+15;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `COMMENT`) VALUES
(@WORLDSAFELOCID+0, 2526, 1410.2153, -2771.7136, 955.63715, 5.191572/(2 * PI() / 360), '10.x Dungeon - Algeth''ar Academy - Entrance'), 
(@WORLDSAFELOCID+1, 2444, 1340.41, -2780.93, 727.921, 3.14855565/(2 * PI() / 360), '10.x Dungeon - Algeth''ar Academy - Exit'),
(@WORLDSAFELOCID+2, 2527, -0.370431, 228.269, 20.8162, 4.720243/(2 * PI() / 360), '10.x Dungeon - Halls of Infusion - Entrance'), 
(@WORLDSAFELOCID+3, 2444, 117.317, -2876.43, 1219.35, 3.8947196/(2 * PI() / 360), '10.x Dungeon - Halls of Infusion - Exit'),
(@WORLDSAFELOCID+4, 2515, -5050.48, 1024.56, 594.216, 2.3592837/(2 * PI() / 360), '10.x Dungeon - The Azure Vault - Entrance'), 
(@WORLDSAFELOCID+5, 2444, -5615.5, 1258.95, 807.088, 3.3301055/(2 * PI() / 360), '10.x Dungeon - The Azure Vault - Exit'),
(@WORLDSAFELOCID+6, 2520, -3300.65, 4681.51, 0.129981, 5.388442/(2 * PI() / 360), '10.x Dungeon - Brackenhide Hollow - Entrance'), 
(@WORLDSAFELOCID+7, 2444, -4472.92, 4239.95, 2.5823, 5.466127/(2 * PI() / 360), '10.x Dungeon - Brackenhide Hollow - Exit'),
(@WORLDSAFELOCID+8, 2516, -570.405, 2189.37, 431.296, 3.9492435/(2 * PI() / 360), '10.x Dungeon - The Nokhud Offensive - Entrance'), 
(@WORLDSAFELOCID+9, 2444, -570.821, 2187.93, 431.483, 3.7326136/(2 * PI() / 360), '10.x Dungeon - The Nokhud Offensive - Exit'),
(@WORLDSAFELOCID+10, 2519, 70.6448, -779.064, 72.6027, 3.1415927/(2 * PI() / 360), '10.x Dungeon - Neltharus - Entrance'), 
(@WORLDSAFELOCID+11, 2444, 2336.58, 2607.58, 229.869, 4.1429753/(2 * PI() / 360), '10.x Dungeon - Neltharus - Exit'),
(@WORLDSAFELOCID+12, 2521, 1386.2, -169.719, 131, 5.9807897/(2 * PI() / 360), '10.x Dungeon - Ruby Life Pools - Entrance'), 
(@WORLDSAFELOCID+13, 2444, 1341.3, -132.202, 137.45, 2.0879548/(2 * PI() / 360), '10.x Dungeon - Ruby Life Pools - Exit'),
(@WORLDSAFELOCID+14, 2451, 204.89, -1017.31, 219.656, 4.3109455/(2 * PI() / 360), '10.x Dungeon - Uldaman: Legacy of Tyr - Entrance'), 
(@WORLDSAFELOCID+15, 0, -6067.1787, -3170.7605, 281.2232, 5.745588/(2 * PI() / 360), '10.x Dungeon - Uldaman: Legacy of Tyr - Exit');

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` BETWEEN @ATID+0 AND @ATID+15 AND `IsServerSide`=1;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID+0, 1, 2, @WORLDSAFELOCID+0, 5),
(@ATID+1, 1, 2, @WORLDSAFELOCID+1, 5),
(@ATID+2, 1, 2, @WORLDSAFELOCID+2, 5),
(@ATID+3, 1, 2, @WORLDSAFELOCID+3, 5),
(@ATID+4, 1, 2, @WORLDSAFELOCID+4, 5),
(@ATID+5, 1, 2, @WORLDSAFELOCID+5, 5),
(@ATID+6, 1, 2, @WORLDSAFELOCID+6, 5),
(@ATID+7, 1, 2, @WORLDSAFELOCID+7, 5),
(@ATID+8, 1, 2, @WORLDSAFELOCID+8, 5),
(@ATID+9, 1, 2, @WORLDSAFELOCID+9, 5),
(@ATID+10, 1, 2, @WORLDSAFELOCID+10, 5),
(@ATID+11, 1, 2, @WORLDSAFELOCID+11, 5),
(@ATID+12, 1, 2, @WORLDSAFELOCID+12, 5),
(@ATID+13, 1, 2, @WORLDSAFELOCID+13, 5),
(@ATID+14, 1, 2, @WORLDSAFELOCID+14, 5),
(@ATID+15, 1, 2, @WORLDSAFELOCID+15, 5);
