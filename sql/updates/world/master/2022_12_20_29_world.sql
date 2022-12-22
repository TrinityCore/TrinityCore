-- Dragonflight 5-man dungeons: Add missing portals
SET @OGUID := 700000; -- Need 11
SET @ATID := 7;
SET @ATSPAWNID := 7;
SET @TELEID := 1951;
SET @WORLDSAFELOCID := 100001;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+10;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 252248, 2444, 13647, 14064, '0', 1, 0, 0, 127.8038177490234375, -2866.427001953125, 1222.2061767578125, 3.825214862823486328, 0, 0, -0.94214916229248046, 0.335193872451782226, 7200, 255, 1, 47187), -- Halls of Infusion (Entrance)
(@OGUID+1, 252247, 2527, 14082, 14082, '1,2,8,23', 1, 0, 0, -0.40625, 247.0399322509765625, 24.41917991638183593, 4.695271492004394531, 0, 0, -0.71313285827636718, 0.701028943061828613, 7200, 255, 1, 47187), -- Halls of Infusion (Exit)
(@OGUID+2, 252248, 2515, 13954, 13954, '1,2,8,23', 1, 0, 0, -5040.02099609375, 1013.90631103515625, 597.4891357421875, 2.442746877670288085, 0, 0, 0.939570426940917968, 0.342355668544769287, 7200, 255, 1, 47187), -- The Azure Vault (Exit)
(@OGUID+3, 324067, 2444, 13645, 0, '0', 1, 0, 0, -547.32989501953125, 2211.6337890625, 432.716583251953125, 0.806146681308746337, 0, 0, 0.392247200012207031, 0.919859826564788818, 7200, 255, 1, 47187), -- The Nokhud Offensive (Entrance)
(@OGUID+4, 324067, 2516, 13982, 14476, '1,2,8,23', 1, 0, 0, -546.8819580078125, 2211.632080078125, 432.554412841796875, 3.736283540725708007, 0, 0, -0.95611763000488281, 0.292983084917068481, 7200, 255, 1, 47187), -- The Nokhud Offensive (Exit)
(@OGUID+5, 252247, 2444, 13644, 13720, '0', 1, 0, 0, 2350.178955078125, 2627.861083984375, 236.6214752197265625, 4.143707275390625, 0, 0, -0.8770751953125, 0.480353116989135742, 7200, 255, 1, 47187), -- Neltharus (Entrance)
(@OGUID+6, 252248, 2519, 14011, 14011, '1,2,8,23', 1, 0, 0, 99.04340362548828125, -776.045166015625, 77.96817779541015625, 0, 0, 0, 0, 1, 7200, 255, 1, 47187), -- Neltharus (Exit)
(@OGUID+7, 252248, 2444, 13644, 13730, '0', 1, 0, 0, 1351.2847900390625, -146.732635498046875, 140.8897247314453125, 5.499916553497314453, 0, 0, -0.3816995620727539, 0.924286425113677978, 7200, 255, 1, 47187), -- Ruby Life Pools (Entrance)
(@OGUID+8, 252248, 2521, 14063, 14449, '1,2,8,23', 1, 0, 0, 1365.8697509765625, -157.385421752929687, 140.8253936767578125, 5.818788051605224609, 0, 0, -0.2301177978515625, 0.973162770271301269, 7200, 255, 1, 47187), -- Ruby Life Pools (Exit)
(@OGUID+9, 252245, 0, 3, 1897, '0', 1, 0, 0, -6063.658203125, -3158.8369140625, 282.86016845703125, 4.716867446899414062, 0, 0, -0.7055215835571289, 0.708688437938690185, 120, 255, 1, 47187), -- Uldaman: Legacy of Tyr (Entrance)
(@OGUID+10, 252245, 2451, 13968, 14143, '1,2,8,23', 1, 0, 0, 207.0746612548828125, -994.03302001953125, 226.3066864013671875, 4.702479362487792968, 0, 0, -0.710601806640625, 0.703594386577606201, 7200, 255, 1, 46879); -- Uldaman: Legacy of Tyr (Exit)

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEn @WORLDSAFELOCID+0 AND @WORLDSAFELOCID+15;
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

-- Algeth'ar Academy - Serverside Areatrigger Templates
DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @ATID+0 AND @ATID+15;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 4, 0, 3, 3, 5, 5, 0, 0, 0, 0, 0), -- Entrance
(@ATID+1, 1, 4, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0), -- Exit
(@ATID+2, 1, 4, 0, 4, 4, 7, 7, 0, 0, 0, 0, 0), -- Entrance
(@ATID+3, 1, 4, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0), -- Exit
(@ATID+4, 1, 4, 0, 4, 4, 15, 15, 0, 0, 0, 0, 0), -- Entrance
(@ATID+5, 1, 4, 0, 4, 4, 5, 5, 0, 0, 0, 0, 0), -- Exit
(@ATID+6, 1, 4, 0, 4, 4, 5, 5, 0, 0, 0, 0, 0), -- Entrance
(@ATID+7, 1, 4, 0, 4, 4, 5, 5, 0, 0, 0, 0, 0), -- Exit
(@ATID+8, 1, 4, 0, 4, 4, 5, 5, 0, 0, 0, 0, 0), -- Entrance
(@ATID+9, 1, 4, 0, 4, 4, 5, 5, 0, 0, 0, 0, 0), -- Exit
(@ATID+10, 1, 4, 0, 5, 5, 8, 8, 0, 0, 0, 0, 0), -- Entrance
(@ATID+11, 1, 4, 0, 5, 5, 8, 8, 0, 0, 0, 0, 0), -- Exit
(@ATID+12, 1, 4, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0), -- Entrance
(@ATID+13, 1, 4, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0), -- Exit
(@ATID+14, 1, 4, 0, 4, 4, 5, 5, 0, 0, 0, 0, 0), -- Entrance
(@ATID+15, 1, 4, 0, 4, 4, 5, 5, 0, 0, 0, 0, 0); -- Exit

-- Algeth'ar Academy - Areatrigger spawns
DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+15;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `Comment`) VALUES
(@ATSPAWNID+0, @ATID+0, 1, 2444, 1352.642090, -2781.378174, 731.538269, 3.196450, 1, 0, 0, 4, 3, 3, 5, 5, 0, 0, 0, 0, '', '10.x Dungeon - Algeth''ar Academy - Entrance'),
(@ATSPAWNID+1, @ATID+1, 1, 2526, 1400.045654, -2757.464600, 955.632202, 5.246456, 1, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, '', '10.x Dungeon - Algeth''ar Academy - Exit'),
(@ATSPAWNID+2, @ATID+2, 1, 2444, 127.8038177490234375, -2866.427001953125, 1222.2061767578125, 3.888434, 1, 0, 0, 4, 4, 4, 7, 7, 0, 0, 0, 0, '', '10.x Dungeon - Halls of Infusion - Entrance'),
(@ATSPAWNID+3, @ATID+3, 1, 2527, -0.40625, 247.0399322509765625, 24.41917991638183593, 4.665325, 1, 0, 0, 4, 5, 5, 5, 5, 0, 0, 0, 0, '', '10.x Dungeon - Halls of Infusion - Exit'),
(@ATSPAWNID+4, @ATID+4, 1, 2444, -5635.067871, 1262.294800, 809.337158, 5.881793, 1, 0, 0, 4, 4, 4, 15, 15, 0, 0, 0, 0, '', '10.x Dungeon - The Azure Vault - Entrance'),
(@ATSPAWNID+5, @ATID+5, 1, 2515, -5040.02099609375, 1013.90631103515625, 597.4891357421875, 2.442746877670288085, 1, 0, 0, 4, 4, 4, 5, 5, 0, 0, 0, 0, '', '10.x Dungeon - The Azure Vault - Exit'),
(@ATSPAWNID+6, @ATID+6, 1, 2444, -4477.467285, 4244.594727, 2.759280, 5.469460, 1, 0, 0, 4, 4, 4, 5, 5, 0, 0, 0, 0, '', '10.x Dungeon - Brackenhide Hollow - Entrance'),
(@ATSPAWNID+7, @ATID+7, 1, 2520, -3305.119385, 4692.831543, 0.084408, 5.136525, 1, 0, 0, 4, 4, 4, 5, 5, 0, 0, 0, 0, '', '10.x Dungeon - Brackenhide Hollow - Exit'),
(@ATSPAWNID+8, @ATID+8, 1, 2444, -547.32989501953125, 2211.6337890625, 432.716583251953125, 0.806146681308746337, 1, 0, 0, 4, 4, 4, 5, 5, 0, 0, 0, 0, '', '10.x Dungeon - The Nokhud Offensive - Entrance'),
(@ATSPAWNID+9, @ATID+9, 1, 2516, -546.8819580078125, 2211.632080078125, 432.554412841796875, 3.736283540725708007, 1, 0, 0, 4, 4, 4, 5, 5, 0, 0, 0, 0, '', '10.x Dungeon - The Nokhud Offensive - Exit'),
(@ATSPAWNID+10, @ATID+10, 1, 2444, 2350.178955078125, 2627.861083984375, 236.6214752197265625, 4.143707275390625, 1, 0, 0, 4, 5, 5, 8, 8, 0, 0, 0, 0, '', '10.x Dungeon - Neltharus - Entrance'),
(@ATSPAWNID+11, @ATID+11, 1, 2519, 99.04340362548828125, -776.045166015625, 77.96817779541015625, 0, 1, 0, 0, 4, 5, 5, 8, 8, 0, 0, 0, 0, '', '10.x Dungeon - Neltharus - Exit'),
(@ATSPAWNID+12, @ATID+12, 1, 2444, 1351.2847900390625, -146.732635498046875, 140.8897247314453125, 5.499916553497314453, 1, 0, 0, 4, 5, 5, 9, 9, 0, 0, 0, 0, '', '10.x Dungeon - Ruby Life Pools - Entrance'),
(@ATSPAWNID+13, @ATID+13, 1, 2521, 1365.8697509765625, -157.385421752929687, 140.8253936767578125, 5.818788051605224609, 1, 0, 0, 6, 5, 5, 8, 8, 0, 0, 0, 0, '', '10.x Dungeon - Ruby Life Pools - Exit'),
(@ATSPAWNID+14, @ATID+14, 1, 0, -6063.658203125, -3158.8369140625, 282.86016845703125, 4.716867446899414062, 1, 0, 0, 4, 5, 5, 6, 6, 0, 0, 0, 0, '', '10.x Dungeon - Uldaman: Legacy of Tyr - Entrance'),
(@ATSPAWNID+15, @ATID+15, 1, 2451, 207.0746612548828125, -994.03302001953125, 226.3066864013671875, 4.702479362487792968, 1, 0, 0, 4, 5, 5, 8, 8, 0, 0, 0, 0, '', '10.x Dungeon - Uldaman: Legacy of Tyr - Exit');

-- Algeth'ar Academy - Areatrigger actions
DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` BETWEEN @ATID+0 AND @ATID+15;
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

DELETE FROM `game_tele` WHERE `id` BETWEEN @TELEID+0 AND @TELEID+7;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(@TELEID+0, 1410.2153, -2771.7136, 955.63715, 5.191572, 2526, 'AlgetharAcademyDungeon'),
(@TELEID+1, -0.370431, 228.269, 20.8162, 4.720243, 2527, 'HallsOfInfusionDungeon'),
(@TELEID+2, -5050.48, 1024.56, 594.216, 2.3592837, 2515, 'TheAzureVaultDungeon'),
(@TELEID+3, -3300.65, 4681.51, 0.129981, 5.388442, 2520, 'BrackenhideHollowDungeon'),
(@TELEID+4, -570.405, 2189.37, 431.296, 3.9492435, 2516, 'TheNokhudOffensiveDungeon'),
(@TELEID+5, 70.6448, -779.064, 72.6027, 3.1415927, 2519, 'NeltharusDungeon'),
(@TELEID+6, 1386.2, -169.719, 131, 5.9807897, 2521, 'RubyLifePoolsDungeon'),
(@TELEID+7, 204.89, -1017.31, 219.656, 4.3109455, 2451, 'UldamanLegacyOfTyrDungeon');
