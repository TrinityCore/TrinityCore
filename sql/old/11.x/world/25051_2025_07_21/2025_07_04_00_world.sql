-- Shadowlands Dungeons
SET @WORLDSAFELOCID := 100076;
SET @TELEID := 2291;
SET @OGUID := 8000027;
SET @ATID := 138;
SET @ATCREATEID := 133;
SET @ATSPAWNID := 232;

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLDSAFELOCID+0 AND @WORLDSAFELOCID+21;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `COMMENT`) VALUES
(@WORLDSAFELOCID+0, 2293, 2676.6624, -2545.9949, 3292.856, 6.2178426/(2 * PI() / 360), '9.x Dungeon - Theater of Pain - Entrance'),
(@WORLDSAFELOCID+1, 2222, 2571.7778, -2736.1702, 3286.5872, 3.772423/(2 * PI() / 360), '9.x Dungeon - Theater of Pain - Exit'),
(@WORLDSAFELOCID+2, 2289, 1984.64, -3206.59, 3261.41, 3.9776053/(2 * PI() / 360), '9.x Dungeon - Plaguefall - Entrance'),
(@WORLDSAFELOCID+3, 2222, 2093.29, -3108.78, 3273.81, 0.7268773/(2 * PI() / 360), '9.x Dungeon - Plaguefall - Exit'),
(@WORLDSAFELOCID+4, 2285, -1318.37, -6134.11, 7067.01, 5.5086603/(2 * PI() / 360), '9.x Dungeon - Spires of Ascension - Entrance'),
(@WORLDSAFELOCID+5, 2222, -2138.42, -5320.01, 6543.06, 2.4207716/(2 * PI() / 360), '9.x Dungeon - Spires of Ascension - Exit'),
(@WORLDSAFELOCID+6, 2286, -3317.21, -3819.34, 6604.09, 1.6026242/(2 * PI() / 360), '9.x Dungeon - The Necrotic Wake - Entrance'),
(@WORLDSAFELOCID+7, 2222, -3316.94, -4125.14, 6599.55, 4.7093697/(2 * PI() / 360), '9.x Dungeon - The Necrotic Wake - Exit'),
(@WORLDSAFELOCID+8, 2290, -6887.047, 1835.7743, 5545.674, 2.092174/(2 * PI() / 360), '9.x Dungeon - Mists of Tirna Scithe - Entrance'),
(@WORLDSAFELOCID+9, 2222, -6939.007, 1768.9757, 5552.2764, 4.5459723/(2 * PI() / 360), '9.x Dungeon - Mists of Tirna Scithe - Exit'),
(@WORLDSAFELOCID+10, 2291, 3014.16, -2221.66, 5.33118, 3.1534958/(2 * PI() / 360), '9.x Dungeon - De Other Side - Entrance'),
(@WORLDSAFELOCID+11, 2222, -7512.3716, -583.25696, 5446.857, 0/(2 * PI() / 360), '9.x Dungeon - De Other Side - Exit'),
(@WORLDSAFELOCID+12, 2287, -2209.5, 5027.13, 4140.39, 1.5676478/(2 * PI() / 360), '9.x Dungeon - Halls of Atonement - Entrance'),
(@WORLDSAFELOCID+13, 2222, -2172.94, 5012.84, 4074.79, 0.7853999/(2 * PI() / 360), '9.x Dungeon - Halls of Atonement - Exit'),
(@WORLDSAFELOCID+14, 2284, -1401.37, 6559.17, 4114.8, 4.1332536/(2 * PI() / 360), '9.x Dungeon - Sanguine Depths - Entrance'),
(@WORLDSAFELOCID+15, 2222, -1454.7535, 6542.76, 4183.935, 6.257681/(2 * PI() / 360), '9.x Dungeon - Sanguine Depths - Exit'),
(@WORLDSAFELOCID+16, 2453, 1646.35, 2310.9, 380.96, 4.707502/(2 * PI() / 360), '9.x Dungeon - Torghast - Entrance'),
(@WORLDSAFELOCID+17, 2222, 4640.97, 6673.89, 4840.12, 2.6253242/(2 * PI() / 360), '9.x Dungeon - Torghast - Exit'),
(@WORLDSAFELOCID+18, 2441, 3638.65, -1816.79, 92.4729, 2.1244671/(2 * PI() / 360), '9.x Dungeon - Tazavesh, the Veiled Market - Entrance'),
(@WORLDSAFELOCID+19, 2222, -5918.4756, 4853.355, 4789.934, 3.619207/(2 * PI() / 360), '9.x Dungeon - Tazavesh, the Veiled Market - Exit'),
(@WORLDSAFELOCID+20, 2236, 911.1528, -1765.6423, 181.19034, 3.6743245/(2 * PI() / 360), '9.x Dungeon - Darkmaul Citadel - Entrance'),
(@WORLDSAFELOCID+21, 2175, 721.7, -1838.4, 186.5, 4.326671/(2 * PI() / 360), '9.x Dungeon - Darkmaul Citadel - Exit');

DELETE FROM `game_tele` WHERE `id` BETWEEN @TELEID+0 AND @TELEID+13;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(@TELEID+0, -2138.42, -5320.01, 6543.06, 5.4818, 2222, 'SpiresOfAscension'),
(@TELEID+1, -1318.37, -6134.11, 7067.01, 5.5086603, 2285, 'SpiresOfAscensionDungeon'),
(@TELEID+2, -3316.94, -4125.14, 6599.55, 1.5727, 2222, 'TheNecroticWake'),
(@TELEID+3, -3317.21, -3819.34, 6604.09, 1.6026242, 2286, 'TheNecroticWakeDungeon'),
(@TELEID+4, -2172.94, 5012.84, 4074.79, 3.9425, 2222, 'HallsOfAtonement'),
(@TELEID+5, -2209.5, 5027.13, 4140.50, 1.5676478, 2287, 'HallsOfAtonementDungeon'),
(@TELEID+6, -1454.7535, 6542.76, 4183.935, 3.1324, 2222, 'SanguineDepths'),
(@TELEID+7, -1401.37, 6559.17, 4114.8, 4.1332536, 2284, 'SanguineDepthsDungeon'),
(@TELEID+8, 4640.97, 6673.89, 4840.12, 2.6253242, 2222, 'Torghast'),
(@TELEID+9, 1646.35, 2310.9, 380.96, 4.707502, 2453, 'TorghastDungeon'),
(@TELEID+10, -5918.4756, 4853.355, 4789.934, 0.5849, 2222, 'TazaveshTheVeiledMarket'),
(@TELEID+11, 3638.65, -1816.79, 92.4729, 2.1244671, 2441, 'TazaveshTheVeiledMarketDungeon'),
(@TELEID+12, 721.7, -1838.4, 186.5, 1.1437, 2175, 'DarkmaulCitadel'),
(@TELEID+13, 911.1528, -1765.6423, 181.19034, 3.6743245, 2236, 'DarkmaulCitadelDungeon');

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+19;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 252145, 2222, 11462, 11465, '0', '0', 0, 2595.97216796875, -2718.4375, 3291.812744140625, 3.797177553176879882, 0, 0, -0.94675540924072265, 0.321953743696212768, 120, 255, 1, 61559), -- Instance Portal (Area: Theater of Pain - Difficulty: 0) CreateObject1
(@OGUID+1, 252145, 2293, 12841, 12841, '1,2,23,8', '0', 0, 2651.153564453125, -2546.973876953125, 3308.091064453125, 6.253239154815673828, 0, 0, -0.01497268676757812, 0.99988788366317749, 7200, 255, 1, 61559), -- Instance Portal (Area: Theater of Pain - Difficulty: 0) CreateObject1
(@OGUID+2, 252245, 2222, 11462, 11465, '0', '0', 0, 2081.96875, -3118.607666015625, 3274.980712890625, 0.747357308864593505, 0, 0, 0.365042686462402343, 0.930990755558013916, 120, 255, 1, 61559), -- Instance Portal (Area: Theater of Pain - Difficulty: 0) CreateObject1
(@OGUID+3, 252247, 2289, 13228, 13228, '1,2,8,23', '0', 0, 1030.7066650390625, -3639.951416015625, 3079.683837890625, 4.688984394073486328, 0, 0, -0.7153329849243164, 0.698783755302429199, 7200, 255, 1, 61559), -- Instance Portal (Area: Plaguefall - Difficulty: 0) CreateObject1
(@OGUID+4, 252247, 2289, 13228, 13228, '1,2,8,23', '0', 0, 2030.9757080078125, -3169.517333984375, 3274.312744140625, 3.835698843002319335, 0, 0, -0.94037914276123046, 0.340128034353256225, 7200, 255, 1, 61559), -- Instance Portal (Area: Plaguefall - Difficulty: 0) CreateObject1
(@OGUID+5, 252247, 2222, 10534, 11381, '0', '0', 0, -2131.13720703125, -5327.78125, 6546.26123046875, 5.550161361694335937, 0, 0, -0.35836124420166015, 0.933583021163940429, 120, 255, 1, 61559), -- Instance Portal (Area: Hero's Rest - Difficulty: 0) CreateObject1
(@OGUID+6, 252248, 2222, 10534, 11381, '0', '0', 0, -3316.757080078125, -4096.59228515625, 6599.923828125, 4.714056015014648437, 0, 0, -0.70651721954345703, 0.707695841789245605, 120, 255, 1, 61559), -- Instance Portal (Area: Hero's Rest - Difficulty: 0) CreateObject1
(@OGUID+7, 252247, 2285, 12837, 12837, '1,2,23,8', '0', 0, -1328.359375, -6122.705078125, 7070.50341796875, 5.491545677185058593, 0, 0, -0.38556480407714843, 0.922680795192718505, 7200, 255, 1, 61559), -- Instance Portal (Area: Spires of Ascension - Difficulty: 0) CreateObject1
(@OGUID+8, 252248, 2286, 12916, 13471, '1,2,23,8', '0', 0, -3317.319580078125, -3828.0625, 6606.60546875, 1.592514872550964355, 0, 0, 0.714743614196777343, 0.6993865966796875, 7200, 255, 1, 61559), -- Instance Portal (Area: The Grim Harvest - Difficulty: 0) CreateObject1
(@OGUID+9, 252248, 2222, 11510, 13231, '0', '0', 0, -6936.57275390625, 1782.6510009765625, 5552.30712890625, 4.548412799835205078, 0, 0, -0.76264095306396484, 0.646822035312652587, 120, 255, 1, 61559), -- Instance Portal (Area: Root-Home - Difficulty: 0) CreateObject1
(@OGUID+10, 252248, 2290, 13334, 13429, '1,2,23,8', '0', 0, -6907.7900390625, 1810.84375, 5548.353515625, 0.818111658096313476, 0, 0, 0.39774322509765625, 0.917496800422668457, 7200, 255, 1, 61559), -- Instance Portal (Area: Oaken Assembly - Difficulty: 0) CreateObject1
(@OGUID+11, 252248, 2290, 13334, 13429, '1,2,23,8', '0', 0, -7478.53662109375, 2866.038330078125, 5349.6572265625, 5.947156906127929687, 0, 0, -0.16722488403320312, 0.985918760299682617, 7200, 255, 1, 61559), -- Instance Portal (Area: Oaken Assembly - Difficulty: 0) CreateObject1
(@OGUID+12, 252248, 2222, 11510, 12902, '0', '0', 0, -7531.09033203125, -583.31427001953125, 5449.68994140625, 0, 0, 0, 0, 1, 120, 255, 1, 61559), -- Instance Portal (Area: Grove of Awakening - Difficulty: 0) CreateObject1
(@OGUID+13, 252248, 2291, 13309, 13309, '1,2,23,8', '0', 0, 3035.85595703125, -2222.1025390625, 9.370679855346679687, 0, 0, 0, 0, 1, 7200, 255, 1, 61559), -- Instance Portal (Area: De Other Side - Difficulty: 0) CreateObject1
(@OGUID+14, 272724, 2222, 10413, 12782, '0', '0', 0, -1479.0399169921875, 6543.19091796875, 4186.92822265625, 6.276032924652099609, 0, 0, -0.00357627868652343, 0.999993562698364257, 120, 255, 1, 61559), -- Instance Portal (Area: Absolution Crypt - Difficulty: 0) CreateObject1
(@OGUID+15, 272724, 2222, 10413, 12782, '0', '0', 0, -2187.0556640625, 4998.578125, 4076.02001953125, 0.776558458805084228, 0, 0, 0.378596305847167968, 0.925561904907226562, 120, 255, 1, 61559), -- Instance Portal (Area: Absolution Crypt - Difficulty: 0) CreateObject1
(@OGUID+16, 252245, 2287, 12831, 12831, '1,2,23,8', '0', 0, -2209.36279296875, 4991.7275390625, 4150.0224609375, 1.538609027862548828, 0, 0, 0.695635795593261718, 0.718394637107849121, 7200, 255, 1, 61559), -- Instance Portal (Area: Halls of Atonement - Difficulty: 0) CreateObject1
(@OGUID+17, 272724, 2284, 12842, 12842, '1,2,23,8', '0', 0, -1390.873291015625, 6574.28125, 4117.09619140625, 4.19525909423828125, 0, 0, -0.86440372467041015, 0.502798378467559814, 7200, 255, 1, 61559), -- Instance Portal (Area: Sanguine Depths - Difficulty: 0) CreateObject1
(@OGUID+18, 252248, 2441, 13577, 13577, '23,2,8', '0', 0, 3657.471435546875, -1849.0364990234375, 94.71509552001953125, 2.277918338775634765, 0, 0, 0.908198356628417968, 0.418540000915527343, 86400, 255, 1, 61559), -- Instance Portal (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject2
(@OGUID+19, 252247, 2175, 10424, 10530, '0', '0', 0, 733.1788330078125, -1802.6875, 191.6061553955078125, 4.42183685302734375, 0, 0, -0.80202293395996093, 0.597293198108673095, 120, 255, 1, 61559); -- Instance Portal (Area: Darkmaul Citadel - Difficulty: 0) CreateObject1

DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @ATID+0 AND @ATID+20;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 0, 0), -- Theater of Pain - Enter
(@ATID+1, 1, 1, 0, 0, 0), -- Theater of Pain - Exit
(@ATID+2, 1, 1, 0, 0, 0), -- Plaguefall - Enter
(@ATID+3, 1, 1, 0, 0, 0), -- Plaguefall - Exit
(@ATID+4, 1, 1, 0, 0, 0), -- Plaguefall - Rear Exit
(@ATID+5, 1, 1, 0, 0, 0), -- Spires of Ascension - Enter
(@ATID+6, 1, 1, 0, 0, 0), -- Spires of Ascension - Exit
(@ATID+7, 1, 1, 0, 0, 0), -- The Necrotic Wake - Enter
(@ATID+8, 1, 1, 0, 0, 0), -- The Necrotic Wake - Exit
(@ATID+9, 1, 1, 0, 0, 0), -- Mists of Tirna Scithe - Enter
(@ATID+10, 1, 1, 0, 0, 0), -- Mists of Tirna Scithe - Exit
(@ATID+11, 1, 1, 0, 0, 0), -- Mists of Tirna Scithe - Rear Exit
(@ATID+12, 1, 1, 0, 0, 0), -- De Other Side - Enter
(@ATID+13, 1, 1, 0, 0, 0), -- De Other Side - Exit
(@ATID+14, 1, 1, 0, 0, 0), -- Halls of Atonement - Enter
(@ATID+15, 1, 1, 0, 0, 0), -- Halls of Atonement - Exit
(@ATID+16, 1, 1, 0, 0, 0), -- Sanguine Depths - Enter
(@ATID+17, 1, 1, 0, 0, 0), -- Sanguine Depths - Exit
(@ATID+18, 1, 1, 0, 0, 0), -- Tazavesh, the Veiled Market - Enter
(@ATID+19, 1, 1, 0, 0, 0), -- Tazavesh, the Veiled Market - Exit
(@ATID+20, 1, 1, 0, 0, 0); -- Darkmaul Citadel - Exit

DELETE FROM `areatrigger_create_properties` WHERE `Id` BETWEEN @ATCREATEID+0 AND @ATCREATEID+20;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCREATEID+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 12, 45, 3, 12, 45, 0, 0, '', 0), -- Theater of Pain - Enter
(@ATCREATEID+1, 1, @ATID+1, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 14, 15, 3, 14, 15, 0, 0, '', 0), -- Theater of Pain - Exit
(@ATCREATEID+2, 1, @ATID+2, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 5, 10, 3, 5, 10, 0, 0, '', 0), -- Plaguefall - Enter
(@ATCREATEID+3, 1, @ATID+3, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 7, 12, 3, 7, 12, 0, 0, '', 0), -- Plaguefall - Exit
(@ATCREATEID+4, 1, @ATID+4, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 7, 10, 3, 7, 10, 0, 0, '', 0), -- Plaguefall - Rear Exit
(@ATCREATEID+5, 1, @ATID+5, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 9, 25, 3, 9, 25, 0, 0, '', 0), -- Spires of Ascension - Enter
(@ATCREATEID+6, 1, @ATID+6, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 11, 10, 3, 11, 10, 0, 0, '', 0), -- Spires of Ascension - Exit
(@ATCREATEID+7, 1, @ATID+7, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 4, 5, 15, 4, 5, 15, 0, 0, '', 0), -- The Necrotic Wake - Enter
(@ATCREATEID+8, 1, @ATID+8, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 5, 10, 3, 5, 10, 0, 0, '', 0), -- The Necrotic Wake - Exit
(@ATCREATEID+9, 1, @ATID+9, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 9, 15, 3, 9, 15, 0, 0, '', 0), -- Mists of Tirna Scithe - Enter
(@ATCREATEID+10, 1, @ATID+10, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 9, 10, 3, 9, 10, 0, 0, '', 0), -- Mists of Tirna Scithe - Exit
(@ATCREATEID+11, 1, @ATID+11, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 6, 10, 3, 6, 10, 0, 0, '', 0), -- Mists of Tirna Scithe - Rear Exit
(@ATCREATEID+12, 1, @ATID+12, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 4, 5, 30, 4, 5, 30, 0, 0, '', 0), -- De Other Side - Enter
(@ATCREATEID+13, 1, @ATID+13, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 7, 10, 3, 7, 10, 0, 0, '', 0), -- De Other Side - Exit
(@ATCREATEID+14, 1, @ATID+14, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 5, 30, 3, 5, 30, 0, 0, '', 0), -- Halls of Atonement - Enter
(@ATCREATEID+15, 1, @ATID+15, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 4, 5, 10, 4, 5, 10, 0, 0, '', 0), -- Halls of Atonement - Exit
(@ATCREATEID+16, 1, @ATID+16, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 5, 20, 3, 5, 20, 0, 0, '', 0), -- Sanguine Depths - Enter
(@ATCREATEID+17, 1, @ATID+17, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 5, 10, 3, 5, 10, 0, 0, '', 0), -- Sanguine Depths - Exit
(@ATCREATEID+18, 1, @ATID+18, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 5, 10, 3, 5, 10, 0, 0, '', 0), -- Tazavesh, the Veiled Market - Enter
(@ATCREATEID+19, 1, @ATID+19, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 8, 10, 3, 8, 10, 0, 0, '', 0), -- Tazavesh, the Veiled Market - Exit
(@ATCREATEID+20, 1, @ATID+20, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 6, 10, 3, 6, 10, 0, 0, '', 0); -- Darkmaul Citadel - Exit

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+20;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `Comment`) VALUES
(@ATSPAWNID+0, @ATCREATEID+0, 1, 2222, '0', 2595.9721, -2718.4375, 3291.8127, 3.7971, 0, 'Theater of Pain - Enter'),
(@ATSPAWNID+1, @ATCREATEID+1, 1, 2293, '1,2,23,8', 2651.1535, -2546.9738, 3308.0910, 6.2532, 0, 'Theater of Pain - Exit'),
(@ATSPAWNID+2, @ATCREATEID+2, 1, 2222, '0', 2081.9687, -3118.6076, 3274.9807, 0.7473, 0, 'Plaguefall - Enter'),
(@ATSPAWNID+3, @ATCREATEID+3, 1, 2289, '1,2,8,23', 2030.9757, -3169.5173, 3274.3127, 3.8356, 0, 'Plaguefall - Exit'),
(@ATSPAWNID+4, @ATCREATEID+4, 1, 2289, '1,2,8,23', 1030.7066, -3639.9514, 3079.6838, 4.6889, 0, 'Plaguefall - Rear Exit'),
(@ATSPAWNID+5, @ATCREATEID+5, 1, 2222, '0', -2131.1372, -5327.7812, 6546.2612, 5.488, 0, 'Spires of Ascension - Enter'),
(@ATSPAWNID+6, @ATCREATEID+6, 1, 2285, '1,2,23,8', -1328.3593, -6122.7050, 7070.5034, 5.4915, 0, 'Spires of Ascension - Exit'),
(@ATSPAWNID+7, @ATCREATEID+7, 1, 2222, '0', -3316.7570, -4096.5922, 6599.9238, 4.7140, 0, 'The Necrotic Wake - Enter'),
(@ATSPAWNID+8, @ATCREATEID+8, 1, 2286, '1,2,23,8', -3317.3195, -3828.0625, 6606.6054, 1.5925, 0, 'The Necrotic Wake - Exit'),
(@ATSPAWNID+9, @ATCREATEID+9, 1, 2222, '0', -6936.5727, 1782.651, 5552.3071, 4.5484, 0, 'Mists of Tirna Scithe - Enter'),
(@ATSPAWNID+10, @ATCREATEID+10, 1, 2290, '1,2,23,8', -6907.79, 1810.8437, 5548.3535, 0.8181, 0, 'Mists of Tirna Scithe - Exit'),
(@ATSPAWNID+11, @ATCREATEID+11, 1, 2290, '1,2,23,8', -7478.5366, 2866.0383, 5349.6572, 5.9471, 0, 'Mists of Tirna Scithe - Rear Exit'),
(@ATSPAWNID+12, @ATCREATEID+12, 1, 2222, '0', -7531.0903, -583.3142, 5449.6899, 0, 0, 'De Other Side - Enter'),
(@ATSPAWNID+13, @ATCREATEID+13, 1, 2291, '1,2,23,8', 3035.8559, -2222.1025, 9.3706, 0, 0, 'De Other Side - Exit'),
(@ATSPAWNID+14, @ATCREATEID+14, 1, 2222, '0', -2187.0556, 4998.5781, 4076.02, 0.7765, 0, 'Halls of Atonement - Enter'),
(@ATSPAWNID+15, @ATCREATEID+15, 1, 2287, '1,2,23,8', -2209.3627, 4991.7275, 4150.0224, 1.5386, 0, 'Halls of Atonement - Exit'),
(@ATSPAWNID+16, @ATCREATEID+16, 1, 2222, '0', -1479.0399, 6543.1909, 4186.9282, 6.2760, 0, 'Sanguine Depths - Enter'),
(@ATSPAWNID+17, @ATCREATEID+17, 1, 2284, '1,2,23,8', -1390.8732, 6574.2812, 4117.0961, 4.1952, 0, 'Sanguine Depths - Exit'),
(@ATSPAWNID+18, @ATCREATEID+18, 1, 2222, '0', -5909.7138, 4860.0068, 4789.998, 3.6106, 0, 'Tazavesh, the Veiled Market - Enter'),
(@ATSPAWNID+19, @ATCREATEID+19, 1, 2441, '23,2,8', 3657.4714, -1849.0364, 94.715, 2.2779, 0, 'Tazavesh, the Veiled Market - Exit'),
(@ATSPAWNID+20, @ATCREATEID+20, 1, 2236, '150', 914.8038, -1762.1961, 184.3816, 3.6327, 0, 'Darkmaul Citadel - Exit');

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` BETWEEN @ATID+0 AND @ATID+20;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID+0, 1, 2, @WORLDSAFELOCID+0, 5), -- Theater of Pain - Enter
(@ATID+1, 1, 2, @WORLDSAFELOCID+1, 5), -- Theater of Pain - Exit
(@ATID+2, 1, 2, @WORLDSAFELOCID+2, 5), -- Plaguefall - Enter
(@ATID+3, 1, 2, @WORLDSAFELOCID+3, 5), -- Plaguefall - Exit
(@ATID+4, 1, 2, @WORLDSAFELOCID+3, 5), -- Plaguefall - Rear Exit
(@ATID+5, 1, 2, @WORLDSAFELOCID+4, 5), -- Spires of Ascension - Enter
(@ATID+6, 1, 2, @WORLDSAFELOCID+5, 5), -- Spires of Ascension - Exit
(@ATID+7, 1, 2, @WORLDSAFELOCID+6, 5), -- The Necrotic Wake - Enter
(@ATID+8, 1, 2, @WORLDSAFELOCID+7, 5), -- The Necrotic Wake - Exit
(@ATID+9, 1, 2, @WORLDSAFELOCID+8, 5), -- Mists of Tirna Scithe - Enter
(@ATID+10, 1, 2, @WORLDSAFELOCID+9, 5), -- Mists of Tirna Scithe - Exit
(@ATID+11, 1, 2, @WORLDSAFELOCID+9, 5), -- Mists of Tirna Scithe - Rear Exit
(@ATID+12, 1, 2, @WORLDSAFELOCID+10, 5), -- De Other Side - Enter
(@ATID+13, 1, 2, @WORLDSAFELOCID+11, 5), -- De Other Side - Exit
(@ATID+14, 1, 2, @WORLDSAFELOCID+12, 5), -- Halls of Atonement - Enter
(@ATID+15, 1, 2, @WORLDSAFELOCID+13, 5), -- Halls of Atonement - Exit
(@ATID+16, 1, 2, @WORLDSAFELOCID+14, 5), -- Sanguine Depths - Enter
(@ATID+17, 1, 2, @WORLDSAFELOCID+15, 5), -- Sanguine Depths - Exit
(@ATID+18, 1, 2, @WORLDSAFELOCID+18, 5), -- Tazavesh, the Veiled Market - Enter
(@ATID+19, 1, 2, @WORLDSAFELOCID+19, 5), -- Tazavesh, the Veiled Market - Exit
(@ATID+20, 1, 2, @WORLDSAFELOCID+21, 5); -- Darkmaul Citadel - Exit
