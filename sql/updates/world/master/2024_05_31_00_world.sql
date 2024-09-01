SET @CGUID := 7000965;
SET @OGUID := 7000255;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+193;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -944.03472900390625, 2531.718017578125, 833.1600341796875, 2.822783470153808593, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+1, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -941.84375, 2558.669189453125, 833.98089599609375, 2.369542837142944335, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+2, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -944.8125, 2540.700439453125, 833.1351318359375, 3.442508220672607421, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+3, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -945.43231201171875, 2543.790771484375, 833.1351318359375, 1.694045782089233398, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+4, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -946.6319580078125, 2540.90185546875, 833.1351318359375, 6.210959434509277343, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+5, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -945.982666015625, 2531.24560546875, 833.1600341796875, 0.845595180988311767, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+6, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -940.44097900390625, 2560.201416015625, 833.978759765625, 3.021476507186889648, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+7, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -945.37152099609375, 2533.37841796875, 833.1600341796875, 5.025929450988769531, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+8, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -958.40802001953125, 2562.046875, 833.13507080078125, 2.737042427062988281, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+9, 137651, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -965.94268798828125, 2563.241455078125, 833.6182861328125, 0.240288496017456054, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Priest Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+10, 137651, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -937.4749755859375, 2575.660888671875, 833.15191650390625, 2.888591527938842773, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Priest Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+11, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -945.5399169921875, 2536.921142578125, 833.1351318359375, 1.694045782089233398, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+12, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -957.9757080078125, 2564.71875, 833.13507080078125, 3.704741954803466796, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+13, 137651, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -923.623291015625, 2562.640625, 833.618408203125, 3.230046272277832031, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Priest Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+14, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -943.2882080078125, 2570.9853515625, 833.66754150390625, 4.634091854095458984, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+15, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -962.56768798828125, 2568.46435546875, 833.13507080078125, 4.877518177032470703, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+16, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -945.27777099609375, 2547.682373046875, 833.1351318359375, 1.694045782089233398, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+17, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -930.53125, 2559.717041015625, 833.13507080078125, 0.729537844657897949, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+18, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -948.826416015625, 2565.846435546875, 833.9796142578125, 1.855781197547912597, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+19, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1045.2552490234375, 2584.71533203125, 812.562255859375, 1.592185258865356445, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+20, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -941.1805419921875, 2582.115478515625, 833.13507080078125, 4.559704780578613281, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+21, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1042.1475830078125, 2619.1484375, 810.1707763671875, 2.734555006027221679, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+22, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1048.767333984375, 2594.791748046875, 812.56231689453125, 4.22749948501586914, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+23, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1044.0694580078125, 2589.889892578125, 812.562255859375, 3.503414392471313476, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+24, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -941.45660400390625, 2587.901123046875, 833.13507080078125, 4.590793609619140625, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+25, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -948.359375, 2590.585205078125, 833.1351318359375, 4.773194789886474609, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+26, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1045.9461669921875, 2588.56689453125, 812.562255859375, 3.427168607711791992, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+27, 137651, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1053.07470703125, 2586.951416015625, 812.562255859375, 1.890555620193481445, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Priest Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+28, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -948.3819580078125, 2582.579833984375, 833.1351318359375, 4.789310932159423828, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+29, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1044.439208984375, 2592.107666015625, 812.56231689453125, 3.71709299087524414, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+30, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1048.1614990234375, 2589.35498046875, 812.562255859375, 3.668090343475341796, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+31, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1058.734375, 2581.150146484375, 812.562255859375, 2.477441310882568359, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+32, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -948.484375, 2587.991455078125, 833.13507080078125, 4.780829429626464843, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+33, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -941.47052001953125, 2584.79248046875, 833.13507080078125, 4.580109596252441406, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+34, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1044.65283203125, 2615.025146484375, 810.1707763671875, 2.808823108673095703, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+35, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1042.8663330078125, 2594.329833984375, 812.56231689453125, 3.794920921325683593, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+36, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -948.47918701171875, 2585.302001953125, 833.1351318359375, 4.786039352416992187, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+37, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -941.59552001953125, 2589.9609375, 833.1351318359375, 4.60070657730102539, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+38, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1043.3507080078125, 2617.225830078125, 810.1707763671875, 2.629465103149414062, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+39, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1047.19970703125, 2592.157958984375, 812.56231689453125, 3.90528106689453125, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+40, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1053.5399169921875, 2612.453125, 810.1707763671875, 4.801647663116455078, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+41, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1060.4930419921875, 2584.0791015625, 812.562255859375, 0.331103354692459106, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+42, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1050.4097900390625, 2610.184814453125, 810.1707763671875, 4.696378707885742187, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+43, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1042.2447509765625, 2626.5791015625, 810.1707763671875, 4.602987289428710937, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+44, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1040.9114990234375, 2621.361083984375, 810.1707763671875, 2.926496505737304687, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+45, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1042.0885009765625, 2629.94189453125, 810.1707763671875, 4.509044170379638671, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+46, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1045.5833740234375, 2626.889892578125, 810.1707763671875, 4.688610076904296875, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+47, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1049.921875, 2621.631103515625, 810.1707763671875, 4.688610076904296875, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+48, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1063.7864990234375, 2583.436767578125, 812.562255859375, 0.291409462690353393, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+49, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1037.8785400390625, 2627.396728515625, 810.1707763671875, 2.614302635192871093, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+50, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1039.21533203125, 2625.216064453125, 810.1707763671875, 2.793661355972290039, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+51, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1052.7239990234375, 2619.052978515625, 810.1707763671875, 4.763421058654785156, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+52, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1058.8160400390625, 2588.392333984375, 812.56231689453125, 6.030618667602539062, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+53, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1054.6805419921875, 2616.3447265625, 810.1707763671875, 4.824779987335205078, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+54, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1046.5833740234375, 2621.3212890625, 810.1707763671875, 4.602987289428710937, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+55, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1047.607666015625, 2612.763916015625, 810.1707763671875, 4.605737209320068359, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+56, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1045.2430419921875, 2630.51123046875, 810.1707763671875, 4.682677745819091796, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+57, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1061.1041259765625, 2591.83935546875, 812.56231689453125, 5.74700784683227539, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+58, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1050.954833984375, 2615.434814453125, 810.1707763671875, 4.715447425842285156, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+59, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1048.7691650390625, 2617.515625, 810.1707763671875, 4.653018474578857421, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+60, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1035.376708984375, 2631.493896484375, 810.1707763671875, 2.911333560943603515, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+61, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1045.1597900390625, 2624.1806640625, 810.1707763671875, 4.581586360931396484, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+62, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1036.6475830078125, 2629.30029296875, 810.1707763671875, 2.719393253326416015, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+63, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1063.015625, 2588.708251953125, 812.56231689453125, 6.100924015045166015, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+64, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1050.779541015625, 2612.40283203125, 810.1707763671875, 4.709904670715332031, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+65, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1048.1597900390625, 2629.19970703125, 810.1707763671875, 4.562702178955078125, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+66, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1068.1875, 2611.651123046875, 810.1357421875, 5.113024234771728515, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+67, 133943, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -990.677734375, 2691.999267578125, 809.94561767578125, 5.017427444458007812, 86400, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Minion of Zul (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 269935 - Bound by Shadow, 276032 - Minion of Zul Autoattack Override)
(@CGUID+68, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1049.5816650390625, 2625.252685546875, 810.1707763671875, 4.682677745819091796, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+69, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1053.2691650390625, 2624.302978515625, 810.1707763671875, 4.77001810073852539, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+70, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1050.720458984375, 2629.14501953125, 810.1707763671875, 4.709531307220458984, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+71, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1067.048583984375, 2607.7587890625, 810.12921142578125, 5.013617515563964843, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+72, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1063.9166259765625, 2605.491455078125, 810.13983154296875, 4.868524551391601562, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+73, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1064.2882080078125, 2607.708251953125, 810.14520263671875, 4.869642257690429687, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+74, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1065.8992919921875, 2615.377685546875, 810.16180419921875, 4.695498943328857421, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+75, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1068.48095703125, 2614.647705078125, 810.1441650390625, 4.868524551391601562, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+76, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1054.96875, 2628.37841796875, 810.1707763671875, 4.898334026336669921, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+77, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1056.9947509765625, 2625.212646484375, 810.1707763671875, 4.854987144470214843, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+78, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1068.8524169921875, 2616.864501953125, 810.1495361328125, 4.869642257690429687, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+79, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1043.388916015625, 2632.9609375, 810.1707763671875, 4.548925399780273437, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+80, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1053.8802490234375, 2631.337646484375, 810.1707763671875, 4.958815574645996093, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+81, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1070.888916015625, 2607.677978515625, 810.1251220703125, 1.52931380271911621, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+82, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1055.85595703125, 2621.3203125, 810.1707763671875, 4.84033966064453125, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+83, 133943, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -985.54949951171875, 2688.4140625, 809.945556640625, 5.233925819396972656, 86400, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Minion of Zul (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 269935 - Bound by Shadow, 276032 - Minion of Zul Autoattack Override)
(@CGUID+84, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1049.7413330078125, 2632.40283203125, 810.1707763671875, 4.797552108764648437, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+85, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1053.095458984375, 2621.27001953125, 810.1707763671875, 4.770053386688232421, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+86, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1064.4617919921875, 2610.741455078125, 810.15447998046875, 4.855473995208740234, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+87, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1058.1927490234375, 2629.587646484375, 810.1707763671875, 4.962352275848388671, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+88, 133943, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -980.76177978515625, 2686.755859375, 809.99066162109375, 4.843727588653564453, 86400, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Minion of Zul (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 269935 - Bound by Shadow, 276032 - Minion of Zul Autoattack Override)
(@CGUID+89, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1067.8125, 2624.052978515625, 810.1707763671875, 5.131470203399658203, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+90, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1078.9896240234375, 2612.887939453125, 810.13983154296875, 0.989469826221466064, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+91, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1071.375, 2612.32373046875, 810.134765625, 5.407551765441894531, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+92, 133935, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -959.6875, 2706.197021484375, 809.716064453125, 4.668361663818359375, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Animated Guardian (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+93, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1071.6129150390625, 2616.9150390625, 810.1441650390625, 5.013617515563964843, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+94, 133943, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -996.12457275390625, 2698.301513671875, 809.94561767578125, 0.661960780620574951, 86400, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Minion of Zul (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 269935 - Bound by Shadow, 276032 - Minion of Zul Autoattack Override)
(@CGUID+95, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1072.85595703125, 2624.037353515625, 810.1593017578125, 5.287476539611816406, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+96, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1069.0260009765625, 2619.897705078125, 810.1588134765625, 4.855473995208740234, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+97, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1068.0850830078125, 2627.798583984375, 810.1707763671875, 5.130417823791503906, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+98, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1074.2864990234375, 2619.04248046875, 810.14990234375, 5.33966827392578125, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+99, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1071.1129150390625, 2619.403564453125, 810.14898681640625, 5.25122690200805664, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+100, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1076.34033203125, 2621.123291015625, 810.1551513671875, 5.382352828979492187, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+101, 133943, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -982.6531982421875, 2699.805419921875, 809.9462890625, 3.351772546768188476, 86400, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Minion of Zul (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 269935 - Bound by Shadow, 276032 - Minion of Zul Autoattack Override)
(@CGUID+102, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1073.8350830078125, 2609.559814453125, 810.1304931640625, 1.077456355094909667, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+103, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1069.939208984375, 2625.348876953125, 810.1707763671875, 5.20259857177734375, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+104, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1066.9410400390625, 2621.416748046875, 810.1707763671875, 5.178107261657714843, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+105, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1077.6978759765625, 2617.202392578125, 810.14788818359375, 5.459810256958007812, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+106, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1072.751708984375, 2620.807373046875, 810.15264892578125, 5.113024234771728515, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+107, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1073.62158203125, 2613.8291015625, 810.13897705078125, 5.428458213806152343, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+108, 133935, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -930.68927001953125, 2706.22314453125, 809.71917724609375, 4.775103092193603515, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Animated Guardian (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+109, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1073.9149169921875, 2616.825439453125, 810.1451416015625, 5.372008800506591796, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+110, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1076.3992919921875, 2611.17626953125, 810.135009765625, 0.983282744884490966, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+111, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1070.279541015625, 2621.7275390625, 810.15771484375, 5.261078834533691406, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+112, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1077.96533203125, 2619.140625, 810.1519775390625, 5.476634979248046875, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+113, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1074.4375, 2627.240478515625, 810.16656494140625, 5.277400493621826171, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+114, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1081.6910400390625, 2620.05029296875, 810.15570068359375, 5.527834892272949218, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+115, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1035.935791015625, 2679.197021484375, 813.8499755859375, 2.568140029907226562, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+116, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1078.576416015625, 2626.17529296875, 810.16650390625, 5.37277078628540039, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+117, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1048.732666015625, 2663.185791015625, 810.1707763671875, 4.253280162811279296, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+118, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1030.7882080078125, 2684.45751953125, 813.849609375, 2.685811758041381835, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+119, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1079.6649169921875, 2623.216064453125, 810.16107177734375, 5.437875747680664062, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+120, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1043.810791015625, 2664.329833984375, 810.1707763671875, 4.025574207305908203, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+121, 133935, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1012.76739501953125, 2698.08154296875, 809.99530029296875, 0.675892174243927001, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Animated Guardian (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+122, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1090.8941650390625, 2619.819580078125, 810.1607666015625, 0.881225109100341796, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+123, 133943, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -981.3590087890625, 2704.012451171875, 809.945556640625, 5.3167724609375, 86400, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Minion of Zul (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 269935 - Bound by Shadow, 276032 - Minion of Zul Autoattack Override)
(@CGUID+124, 133943, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -988.8885498046875, 2712.16015625, 809.94561767578125, 6.269046783447265625, 86400, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Minion of Zul (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 269935 - Bound by Shadow, 276032 - Minion of Zul Autoattack Override)
(@CGUID+125, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1082.888916015625, 2624.42529296875, 810.1646728515625, 5.474312782287597656, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+126, 133943, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -982.7510986328125, 2705.015380859375, 809.945556640625, 5.443915367126464843, 86400, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Minion of Zul (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 269935 - Bound by Shadow, 276032 - Minion of Zul Autoattack Override)
(@CGUID+127, 137650, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1075.4166259765625, 2623.982666015625, 810.160400390625, 5.343303680419921875, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+128, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1086.96533203125, 2617.16845703125, 810.152587890625, 1.086696505546569824, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+129, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1034.142333984375, 2681.0234375, 813.84979248046875, 2.388781547546386718, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+130, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1057.857666015625, 2668.030517578125, 810.1707763671875, 4.501191139221191406, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+131, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1084.579833984375, 2615.798583984375, 810.1485595703125, 1.064578890800476074, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+132, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1088.890625, 2618.568603515625, 810.1563720703125, 0.983282744884490966, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+133, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1032.517333984375, 2682.604248046875, 813.849609375, 2.493871450424194335, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+134, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1059.4879150390625, 2672.38720703125, 810.1707763671875, 4.501191139221191406, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+135, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1048.0711669921875, 2687.78125, 813.8497314453125, 6.047887325286865234, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+136, 133935, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1023.50872802734375, 2710.885498046875, 810.002197265625, 0.675892174243927001, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Animated Guardian (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+137, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1095.185791015625, 2650.875, 810.1707763671875, 5.962779521942138671, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+138, 137478, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1107.46875, 2734.8603515625, 813.489013671875, 1.989097952842712402, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Queen Wasi (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+139, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1045.5885009765625, 2690.5087890625, 813.8497314453125, 5.596029281616210937, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+140, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1043.1597900390625, 2693.3046875, 813.849609375, 5.501855850219726562, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+141, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1084.8663330078125, 2660.564208984375, 810.1707763671875, 5.714869022369384765, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+142, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1085.467041015625, 2665.579833984375, 810.1707763671875, 5.487162590026855468, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+143, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1040.657958984375, 2696.155517578125, 813.849609375, 5.508043289184570312, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+144, 137652, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1090.6754150390625, 2652.01904296875, 810.1707763671875, 5.962779521942138671, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Untainted Guard Spirit (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 270691 - Friendly Troll Spirit Spawn)
(@CGUID+145, 137474, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1107.2708740234375, 2737.362060546875, 813.489013671875, 5.126218795776367187, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- King Timalji (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+146, 137473, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1133.84375, 2732.0546875, 813.489013671875, 0.037781734019517898, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Guard Captain Atu (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+147, 136256, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -832.484375, 2786.694580078125, 773.6920166015625, 3.79013681411743164, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Coffin (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+148, 137485, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1135.638916015625, 2756.014892578125, 813.489013671875, 3.07689070701599121, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Bloodsworn Agent (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+149, 137969, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -831.6475830078125, 2789.74658203125, 773.35711669921875, 4.836662769317626953, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Interment Construct (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+150, 136256, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -850.29864501953125, 2786.013916015625, 773.6920166015625, 3.433708667755126953, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Coffin (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+151, 134251, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1134.0399169921875, 2739.694580078125, 813.48974609375, 0.210642188787460327, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Seneschal M'bara (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+152, 79417, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1121.7379150390625, 2746.440185546875, 813.3909912109375, 0, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Invisible Stalker (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+153, 137485, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1135.7083740234375, 2757.5703125, 813.489013671875, 3.435297727584838867, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Bloodsworn Agent (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+154, 137487, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1106.170166015625, 2756.119873046875, 813.489013671875, 0, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Skeletal Hunting Raptor (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+155, 137486, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1105.890625, 2757.17626953125, 813.489013671875, 3.291857719421386718, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Queen Patlaa (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+156, 134739, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -969.03643798828125, 2823.564208984375, 775.95745849609375, 3.145365715026855468, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Purification Construct (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+157, 137485, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1135.6302490234375, 2755.234375, 813.489013671875, 2.877234458923339843, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Bloodsworn Agent (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+158, 134331, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1134.84033203125, 2735.80029296875, 813.489013671875, 0.055697351694107055, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- King Rahu'ai (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+159, 137484, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1135.298583984375, 2757.078125, 813.489013671875, 0.186452701687812805, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- King A'akul (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+160, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -840.194580078125, 2833.947998046875, 773.3519287109375, 3.968789100646972656, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+161, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -840.245849609375, 2852.3310546875, 773.351806640625, 5.877839565277099609, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+162, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -798.74822998046875, 2855.63037109375, 773.35186767578125, 5.542315483093261718, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+163, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -837.2315673828125, 2839.42236328125, 773.351806640625, 2.067578077316284179, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+164, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -848.604248046875, 2820.932861328125, 773.38458251953125, 1.384819626808166503, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+165, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -841.31048583984375, 2836.343017578125, 773.351806640625, 3.925760984420776367, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+166, 136256, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -783.3992919921875, 2833.880126953125, 773.6920166015625, 5.810433864593505859, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Coffin (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+167, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -823.399169921875, 2848.107177734375, 773.351806640625, 5.356040000915527343, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+168, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -788.11651611328125, 2829.005615234375, 773.35186767578125, 2.262636661529541015, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+169, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -793.96710205078125, 2847.607421875, 773.35186767578125, 1.952226042747497558, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+170, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -813.794677734375, 2853.243408203125, 773.351806640625, 3.403700113296508789, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+171, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -833.9298095703125, 2844.968505859375, 773.351806640625, 1.35204780101776123, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+172, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -845.09417724609375, 2820.61474609375, 773.37005615234375, 0.397684454917907714, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+173, 134993, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -813.09552001953125, 2816.1650390625, 775.0115966796875, 2.351068973541259765, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Mchimba the Embalmer (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+174, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -796.16656494140625, 2839.987548828125, 773.35186767578125, 4.995737552642822265, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+175, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -843.216796875, 2854.85546875, 775.1488037109375, 5.572754859924316406, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+176, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -833.654541015625, 2837.346435546875, 773.351806640625, 2.40901041030883789, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+177, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -815.9873046875, 2849.459716796875, 773.351806640625, 6.068692684173583984, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+178, 137989, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -800.8822021484375, 2827.01416015625, 773.3519287109375, 3.89269256591796875, 86400, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54847), -- Embalming Fluid (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+179, 137485, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -1135.85595703125, 2759.15625, 813.489013671875, 3.582254648208618164, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Bloodsworn Agent (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+180, 135167, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -799.28302001953125, 2912.8203125, 796.24676513671875, 0.20116773247718811, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Spectral Berserker (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 271570 - Transform: Invisible Stalker)
(@CGUID+181, 135192, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -857.09027099609375, 2916.545166015625, 795.95050048828125, 4.771107196807861328, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Honored Raptor (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 271570 - Transform: Invisible Stalker)
(@CGUID+182, 135204, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -801.34893798828125, 2905.7822265625, 796.24688720703125, 0.37156262993812561, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Spectral Hex Priest (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 271570 - Transform: Invisible Stalker)
(@CGUID+183, 135239, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -837.640625, 2915.842041015625, 795.950439453125, 0, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Spectral Witch Doctor (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 271570 - Transform: Invisible Stalker)
(@CGUID+184, 136256, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -783.12677001953125, 2852.502685546875, 773.6920166015625, 3.348135948181152343, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Coffin (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+185, 135192, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -856.20660400390625, 2907.78466796875, 795.950439453125, 1.642197251319885253, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Honored Raptor (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 271570 - Transform: Invisible Stalker)
(@CGUID+186, 135475, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1123.092041015625, 2889.876708984375, 775.63800048828125, 1.096770644187927246, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Kula the Butcher (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 271570 - Transform: Invisible Stalker, 42459 - Dual Wield)
(@CGUID+187, 135204, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -801.72393798828125, 2918.80029296875, 796.24688720703125, 6.206296443939208984, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Spectral Hex Priest (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 271570 - Transform: Invisible Stalker)
(@CGUID+188, 135470, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1124.21533203125, 2935.11376953125, 775.6282958984375, 5.472095966339111328, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Aka'ali the Conqueror (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+189, 137969, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -784.08856201171875, 2853.459228515625, 773.35711669921875, 6.217722415924072265, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Interment Construct (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@CGUID+190, 135167, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -837.82464599609375, 2907.77001953125, 795.950439453125, 0.865029871463775634, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Spectral Berserker (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 271570 - Transform: Invisible Stalker)
(@CGUID+191, 135235, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -860.0242919921875, 2916.411376953125, 796.54095458984375, 0.297151237726211547, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Spectral Beastmaster (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 271570 - Transform: Invisible Stalker)
(@CGUID+192, 135472, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 0, -1135.079833984375, 2911.82373046875, 775.660888671875, 6.269727706909179687, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Zanazal the Wise (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 271570 - Transform: Invisible Stalker)
(@CGUID+193, 136160, 1762, 9526, 9526, '23,8,2', '0', 0, 0, 1, -945.482666015625, 3164.830810546875, 780.2994384765625, 4.704408168792724609, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- King Dazar (Area: Kings' Rest - Difficulty: Heroic) CreateObject1 (Auras: 269055 - Dazar Pre-fight Visual)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+193;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+8, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+12, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+14, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+22, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+23, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+26, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+29, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+30, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+35, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+39, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+40, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+41, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+42, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+43, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+45, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+46, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+47, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+48, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+51, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+52, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+53, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+54, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+55, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+56, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+57, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+58, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+59, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+61, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+63, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+64, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+65, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+66, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+68, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+69, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+70, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+71, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+72, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+73, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+74, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+75, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+76, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+77, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+78, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+79, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+80, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+81, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+82, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+84, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+85, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+86, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+87, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+89, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+90, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+91, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+93, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+95, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+96, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+97, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+98, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+99, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+100, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+102, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+103, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+104, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+105, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+106, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+107, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+109, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+110, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+111, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+112, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+113, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+114, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+115, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+116, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+117, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+118, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+119, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+120, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+122, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+125, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+127, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'), -- Untainted Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+128, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+129, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+130, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+131, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+132, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+133, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+134, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+135, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+137, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+139, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+140, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+141, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+142, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+143, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, '270691'), -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn
(@CGUID+144, 0, 0, 0, 0, 0, 1, 0, 718, 0, 0, 0, 0, '270691'); -- Untainted Guard Spirit - 270691 - Friendly Troll Spirit Spawn

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+60;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 296959, 1762, 9526, 9526, '23,8,2', '0', 0, -948.50177001953125, 2567.953125, 834.15966796875, 4.895322322845458984, 0.189019680023193359, 0.037981986999511718, -0.64168548583984375, 0.742339968681335449, 86400, 255, 1, 54847), -- Ancient Trinket (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+1, 290700, 1762, 9526, 9526, '23,8,2', '0', 0, -962.42022705078125, 2561.0556640625, 835.08978271484375, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 86400, 255, 1, 54847), -- Worn Prayer Book (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+2, 290699, 1762, 9526, 9526, '23,8,2', '0', 0, -943.9571533203125, 2568.87353515625, 833.90069580078125, 1.22955632209777832, -0.1042485237121582, 0.066698074340820312, 0.576740264892578125, 0.807498812675476074, 86400, 255, 1, 54847), -- Doodad_Zandalari_FlavorDoodads_017 (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+3, 290698, 1762, 9526, 9526, '23,8,2', '0', 0, -943.26739501953125, 2560.68896484375, 834.45745849609375, 5.410523891448974609, 0.159891605377197265, 0.434438705444335937, -0.35625553131103515, 0.811652421951293945, 86400, 255, 1, 54847), -- Tablet (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+4, 252247, 1762, 9526, 9526, '23,8,2', '0', 0, -945.795166015625, 2522.8203125, 835.39044189453125, 1.516869664192199707, 0, 0, 0.687786102294921875, 0.725913405418395996, 86400, 255, 1, 54847), -- Instance Portal (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+5, 288466, 1762, 9526, 9526, '23,8,2', '0', 0, -1049.499755859375, 2573.83056640625, 814.9539794921875, 1.812696337699890136, 0, 0, 0.787257194519042968, 0.616624772548675537, 86400, 255, 1, 54847), -- Serpentine Seal (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+6, 290690, 1762, 9526, 9526, '23,8,2', '0', 0, -1043.58837890625, 2585.045654296875, 812.416259765625, 4.938657760620117187, 0, 0, -0.62275886535644531, 0.782413840293884277, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+7, 292840, 1762, 9526, 9526, '23,8,2', '0', 0, -1059.8748779296875, 2581.077880859375, 812.416259765625, 4.938657760620117187, 0, 0, -0.62275886535644531, 0.782413840293884277, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+8, 282652, 1762, 9526, 9526, '23,8,2', '0', 0, -945.00933837890625, 2667.2353515625, 812.4388427734375, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 54847), -- Kings' Rest - Entryway Door (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+9, 287391, 1762, 9526, 9526, '23,8,2', '0', 0, -1047.99755859375, 2675.12255859375, 813.6484375, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 86400, 255, 0, 54847), -- Boss 1 Door 1 (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+10, 287390, 1762, 9526, 9526, '23,8,2', '0', 0, -1028.04443359375, 2697.00048828125, 813.676025390625, 0.663225173950195312, 0, 0, 0.325568199157714843, 0.945518553256988525, 86400, 255, 0, 54847), -- Tomb Door (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+11, 290688, 1762, 9526, 9526, '23,8,2', '0', 0, -1016.22265625, 2699.9453125, 809.81292724609375, 3.804197072982788085, 0, 0, -0.94561958312988281, 0.325274676084518432, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+12, 289347, 1762, 9526, 9526, '23,8,2', '0', 0, -1066.8729248046875, 2642.761474609375, 810.79876708984375, 1.823868632316589355, 0, 0, 0.790689468383789062, 0.612217426300048828, 86400, 255, 1, 54847), -- Liquid Gold Pool (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+13, 290687, 1762, 9526, 9526, '23,8,2', '0', 0, -889.922119140625, 2702.498291015625, 809.81292724609375, 0, 0, 0, 0, 1, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+14, 296960, 1762, 9526, 9526, '23,8,2', '0', 0, -1046.94970703125, 2733.6875, 810.88067626953125, 5.651650428771972656, -0.0247507095336914, 0.052821159362792968, -0.30840015411376953, 0.949466526508331298, 86400, 255, 1, 54847), -- Ancient Trinket (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+15, 297157, 1762, 9526, 9526, '23,8,2', '0', 0, -1108.09619140625, 2695.991455078125, 820.1597900390625, 3.118540048599243164, 0.09043741226196289, -0.00111103057861328, 0.995835304260253906, 0.011484993621706962, 86400, 255, 1, 54847), -- Vault (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+16, 278814, 1762, 9526, 9526, '23,8,2', '0', 0, -847.7703857421875, 2415.89013671875, 678.25006103515625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 1, 54847), -- Doodad_8DU_CityofGold_WaterfallStairs01 (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+17, 293693, 1762, 9526, 9526, '23,8,2', '0', 0, -889.922119140625, 2712.2353515625, 809.81292724609375, 0, 0, 0, 0, 1, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+18, 297156, 1762, 9526, 9526, '23,8,2', '0', 0, -1132.8414306640625, 2695.42626953125, 820.5330810546875, 0.034154761582612991, 0.001474380493164062, -0.09043216705322265, 0.017000198364257812, 0.995756387710571289, 86400, 255, 1, 54847), -- Vault (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+19, 290689, 1762, 9526, 9526, '23,8,2', '0', 0, -1043.4267578125, 2734.840576171875, 809.81292724609375, 3.804197072982788085, 0, 0, -0.94561958312988281, 0.325274676084518432, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+20, 297155, 1762, 9526, 9526, '23,8,2', '0', 0, -1133.0750732421875, 2704.33544921875, 820.3310546875, 0.027649985626339912, 0.001180171966552734, -0.09043598175048828, 0.013761520385742187, 0.995806455612182617, 86400, 255, 1, 54847), -- Vault (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+21, 290684, 1762, 9526, 9526, '23,8,2', '0', 0, -1098.56103515625, 2735.51904296875, 814.64862060546875, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 54847), -- Doodad_8DU_CityofGold_Sarcophagus006 (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+22, 297154, 1762, 9526, 9526, '23,8,2', '0', 0, -1107.964111328125, 2704.528076171875, 820.1728515625, 3.128493547439575195, 0.090441703796386718, -0.00065326690673828, 0.995880126953125, 0.006528194528073072, 86400, 255, 1, 54847), -- Vault (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+23, 292839, 1762, 9526, 9526, '23,8,2', '0', 0, -1049.6185302734375, 2742.776123046875, 809.81292724609375, 3.804197072982788085, 0, 0, -0.94561958312988281, 0.325274676084518432, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+24, 287393, 1762, 9526, 9526, '23,8,2', '0', 0, -1120.573974609375, 2715.253173828125, 815.07647705078125, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 54847), -- Doodad_8DU_CityofGold_Gate001 (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+25, 297153, 1762, 9526, 9526, '23,8,2', '0', 0, -1133.37109375, 2695.50341796875, 817.924072265625, 0.05874967947602272, 0.0050811767578125, -0.17292213439941406, 0.028927803039550781, 0.984497487545013427, 86400, 255, 1, 54847), -- Tiki Pepe (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+26, 292838, 1762, 9526, 9526, '23,8,2', '0', 0, -1022.3153076171875, 2707.753662109375, 809.81292724609375, 3.804197072982788085, 0, 0, -0.94561958312988281, 0.325274676084518432, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+27, 287392, 1762, 9526, 9526, '23,8,2', '0', 0, -1097.36376953125, 2662.560302734375, 813.6572265625, 5.705415725708007812, 0, 0, -0.28488349914550781, 0.958562135696411132, 86400, 255, 1, 54847), -- Kings' Rest - Boss 1 - Post Door (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+28, 289643, 1762, 9526, 9526, '23,8,2', '0', 0, -850.652587890625, 2781.932861328125, 774.33135986328125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 54847), -- Coffin (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+29, 289642, 1762, 9526, 9526, '23,8,2', '0', 0, -832.06097412109375, 2781.932861328125, 774.33135986328125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 54847), -- Coffin (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+30, 292841, 1762, 9526, 9526, '23,8,2', '0', 0, -963.7064208984375, 2818.81884765625, 775.84954833984375, 6.277570247650146484, 0, 0, -0.0028076171875, 0.999996066093444824, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+31, 290683, 1762, 9526, 9526, '23,8,2', '0', 0, -1098.56103515625, 2756.8388671875, 814.64862060546875, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 54847), -- Doodad_8DU_CityofGold_Sarcophagus005 (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+32, 290682, 1762, 9526, 9526, '23,8,2', '0', 0, -1135.70263671875, 2742.336669921875, 813.3485107421875, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+33, 290681, 1762, 9526, 9526, '23,8,2', '0', 0, -1105.5498046875, 2749.875244140625, 813.3485107421875, 0, 0, 0, 0, 1, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+34, 290693, 1762, 9526, 9526, '23,8,2', '0', 0, -1135.70263671875, 2749.896240234375, 813.3485107421875, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+35, 290685, 1762, 9526, 9526, '23,8,2', '0', 0, -1142.72802734375, 2735.521728515625, 814.64862060546875, 0, 0, 0, 0, 1, 86400, 255, 1, 54847), -- Doodad_8DU_CityofGold_Sarcophagus007 (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+36, 287395, 1762, 9526, 9526, '23,8,2', '0', 0, -865.35614013671875, 2823.8193359375, 773.23809814453125, 0, 0, 0, 0, 1, 86400, 255, 0, 54847), -- Gate (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+37, 290692, 1762, 9526, 9526, '23,8,2', '0', 0, -1105.5498046875, 2742.480712890625, 813.3485107421875, 0, 0, 0, 0, 1, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+38, 287394, 1762, 9526, 9526, '23,8,2', '0', 0, -1120.8062744140625, 2777.142578125, 815.39202880859375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 1, 54847), -- Gate (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+39, 288467, 1762, 9526, 9526, '23,8,2', '0', 0, -843.0262451171875, 2845.6689453125, 772.914794921875, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 86400, 255, 0, 54847), -- Doodad_8DU_CityofGold_GoldLiquid001 (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+40, 287396, 1762, 9526, 9526, '23,8,2', '0', 0, -821.2733154296875, 2867.095458984375, 773.50262451171875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 54847), -- Gate (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+41, 290691, 1762, 9526, 9526, '23,8,2', '0', 0, -963.64990234375, 2828.87939453125, 775.84954833984375, 6.277570247650146484, 0, 0, -0.0028076171875, 0.999996066093444824, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+42, 289640, 1762, 9526, 9526, '23,8,2', '0', 0, -779.310302734375, 2834.558837890625, 774.33135986328125, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 54847), -- Coffin (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+43, 290686, 1762, 9526, 9526, '23,8,2', '0', 0, -1142.72802734375, 2756.841552734375, 814.64862060546875, 0, 0, 0, 0, 1, 86400, 255, 1, 54847), -- Doodad_8DU_CityofGold_Sarcophagus008 (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+44, 287503, 1762, 9526, 9526, '23,8,2', '0', 0, -1069.628662109375, 2911.192626953125, 775.6812744140625, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 0, 54847), -- Gate (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+45, 287397, 1762, 9526, 9526, '23,8,2', '0', 0, -945.02783203125, 3111.5546875, 779.56878662109375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 54847), -- Gate (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+46, 290701, 1762, 9526, 9526, '23,8,2', '0', 0, -821.2193603515625, 2891.329345703125, 776.56640625, 1.551803946495056152, -0.1033024787902832, 0.101439476013183593, 0.693262100219726562, 0.705993115901947021, 86400, 255, 1, 54847), -- Tablet (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+47, 289641, 1762, 9526, 9526, '23,8,2', '0', 0, -779.310302734375, 2853.150634765625, 774.33135986328125, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 54847), -- Coffin (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+48, 282651, 1762, 9526, 9526, '23,8,2', '0', 0, -890.413818359375, 2911.51953125, 798.2532958984375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 1, 54847), -- Door (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+49, 282650, 1762, 9526, 9526, '23,8,2', '0', 0, -999.647705078125, 2911.51953125, 798.2532958984375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 54847), -- Doodad_8DU_CityofGold_Door001 (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+50, 296961, 1762, 9526, 9526, '23,8,2', '0', 0, -876.52081298828125, 2895.6103515625, 828.03106689453125, 1.668980598449707031, -0.66526031494140625, 0.066414833068847656, 0.711600303649902343, 0.215969398617744445, 86400, 255, 1, 54847), -- Ancient Trinket (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+51, 290695, 1762, 9526, 9526, '23,8,2', '0', 0, -1126.51318359375, 2884.5390625, 775.625732421875, 4.183174610137939453, 0, 0, -0.86742591857910156, 0.497566372156143188, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+52, 289644, 1762, 9526, 9526, '23,8,2', '0', 0, -945.02783203125, 3152.648193359375, 781.33306884765625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 0, 54847), -- Kings' Rest - Boss 4 - Dazar Gate (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+53, 287118, 1762, 9526, 9526, '23,8,2', '0', 0, -945.039306640625, 2925.853759765625, 794.63360595703125, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 54847), -- Bridge (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+54, 287117, 1762, 9526, 9526, '23,8,2', '0', 0, -945.111083984375, 2995.37841796875, 841.71942138671875, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 0, 54847), -- Waterfall (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+55, 289527, 1762, 9526, 9526, '23,8,2', '0', 0, -944.9449462890625, 2921.4736328125, 797.9287109375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 1, 54847), -- Gate (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+56, 290694, 1762, 9526, 9526, '23,8,2', '0', 0, -1142.5347900390625, 2911.3408203125, 775.625732421875, 3.135416269302368164, 0, 0, 0.999995231628417968, 0.003088161814957857, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+57, 290696, 1762, 9526, 9526, '23,8,2', '0', 0, -1126.418212890625, 2938.157958984375, 775.625732421875, 2.088776588439941406, 0, 0, 0.864617347717285156, 0.502430915832519531, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+58, 296962, 1762, 9526, 9526, '23,8,2', '0', 0, -937.94097900390625, 3083.7275390625, 791.98583984375, 1.020166754722595214, -0.0773324966430664, 0.104043006896972656, 0.486017227172851562, 0.864281177520751953, 86400, 255, 1, 54847), -- Ancient Trinket (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+59, 292842, 1762, 9526, 9526, '23,8,2', '0', 0, -939.44317626953125, 3098.534912109375, 780.1424560546875, 1.56517958641052246, 0, 0, 0.705118179321289062, 0.709089815616607666, 86400, 255, 1, 54847), -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
(@OGUID+60, 290697, 1762, 9526, 9526, '23,8,2', '0', 0, -950.8167724609375, 3098.598876953125, 780.1424560546875, 1.56517958641052246, 0, 0, 0.705118179321289062, 0.709089815616607666, 86400, 255, 1, 54847); -- Placard (Area: Kings' Rest - Difficulty: Heroic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+60;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Worn Prayer Book
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_Zandalari_FlavorDoodads_017
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0), -- Tablet
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 2100, 0), -- Serpentine Seal
(@OGUID+6, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+8, 0, 0, 1, -0.00000004371138828, 0, 0), -- Kings' Rest - Entryway Door
(@OGUID+9, 0, 0, 1, -0.00000004371138828, 0, 0), -- Boss 1 Door 1
(@OGUID+10, 0, 0, 1, -0.00000004371138828, 0, 0), -- Tomb Door
(@OGUID+11, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+12, 0, 0, 1, -0.00000004371138828, 0, 0), -- Liquid Gold Pool
(@OGUID+13, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+15, 0, 0, 1, -0.00000004371138828, 0, 0), -- Vault
(@OGUID+16, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_WaterfallStairs01
(@OGUID+17, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+18, 0, 0, 1, -0.00000004371138828, 0, 0), -- Vault
(@OGUID+19, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 0), -- Vault
(@OGUID+21, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Sarcophagus006
(@OGUID+22, 0, 0, 1, -0.00000004371138828, 0, 0), -- Vault
(@OGUID+23, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+24, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Gate001
(@OGUID+25, 0, 0, 1, -0.00000004371138828, 0, 0), -- Tiki Pepe
(@OGUID+26, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+27, 0, 0, 1, -0.00000004371138828, 0, 0), -- Kings' Rest - Boss 1 - Post Door
(@OGUID+28, 0, 0, 1, -0.00000004371138828, 0, 0), -- Coffin
(@OGUID+29, 0, 0, 1, -0.00000004371138828, 0, 0), -- Coffin
(@OGUID+30, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+31, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Sarcophagus005
(@OGUID+32, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+33, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+34, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+35, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Sarcophagus007
(@OGUID+36, 0, 0, 1, -0.00000004371138828, 0, 0), -- Gate
(@OGUID+37, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+38, 0, 0, 1, -0.00000004371138828, 0, 0), -- Gate
(@OGUID+39, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_GoldLiquid001
(@OGUID+40, 0, 0, 1, -0.00000004371138828, 0, 0), -- Gate
(@OGUID+41, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+42, 0, 0, 1, -0.00000004371138828, 0, 0), -- Coffin
(@OGUID+43, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Sarcophagus008
(@OGUID+44, 0, 0, 1, -0.00000004371138828, 0, 0), -- Gate
(@OGUID+45, 0, 0, 1, -0.00000004371138828, 0, 0), -- Gate
(@OGUID+46, 0, 0, 1, -0.00000004371138828, 0, 0), -- Tablet
(@OGUID+47, 0, 0, 1, -0.00000004371138828, 0, 0), -- Coffin
(@OGUID+48, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+49, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Door001
(@OGUID+51, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+52, 0, 0, 1, -0.00000004371138828, 0, 0), -- Kings' Rest - Boss 4 - Dazar Gate
(@OGUID+53, 0, 0, 1, -0.00000004371138828, 0, 0), -- Bridge
(@OGUID+54, 0, 0, 1, -0.00000004371138828, 0, 13792), -- Waterfall
(@OGUID+55, 0, 0, 1, -0.00000004371138828, 0, 0), -- Gate
(@OGUID+56, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+57, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+59, 0, 0, 1, -0.00000004371138828, 0, 0), -- Placard
(@OGUID+60, 0, 0, 1, -0.00000004371138828, 0, 0); -- Placard

-- Template
UPDATE `creature_template` SET `unit_flags`=33554496, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=136160; -- King Dazar
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=135472; -- Zanazal the Wise
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=135470; -- Aka'ali the Conqueror
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=134993; -- Mchimba the Embalmer
UPDATE `creature_template` SET `unit_flags3`=67108865 WHERE `entry`=137487; -- Skeletal Hunting Raptor
UPDATE `creature_template` SET `unit_flags3`=16777216, `flags_extra` = 128 WHERE `entry`=79417; -- Invisible Stalker
UPDATE `creature_template` SET `unit_flags3`=16777217, `flags_extra` = 128 WHERE `entry`=136256; -- Coffin
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=133943; -- Minion of Zul
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=137650; -- Untainted Spirit

UPDATE `gameobject_template` SET `VerifiedBuild`=54847 WHERE `entry` IN (292842, 290697, 290696, 290694, 287117, 290701, 282650, 289527, 290695, 287118, 282651, 287397, 287503, 289644, 290691, 290686, 288467, 287396, 290693, 292841, 287395, 287394, 290682, 290685, 290681, 290683, 290692, 297155, 290684, 297156, 287393, 297154, 292839, 297157, 290689, 278814, 292838, 293693, 287392, 290688, 290687, 289347, 287390, 287391, 292840, 288466, 290690, 282652, 252247, 290700, 290699, 290698);
UPDATE `gameobject_template` SET `ContentTuningId`=1242, `VerifiedBuild`=54847 WHERE `entry` IN (296962, 296961, 296960, 296959); -- Ancient Trinket
UPDATE `gameobject_template` SET `ContentTuningId`=1252, `VerifiedBuild`=54847 WHERE `entry` IN (289641, 289640, 289642, 289643); -- Coffin
UPDATE `gameobject_template` SET `ContentTuningId`=1252, `VerifiedBuild`=54847 WHERE `entry`=297153; -- Tiki Pepe

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (136160 /*136160 (King Dazar) - Dazar Pre-fight Visual*/, 135472 /*135472 (Zanazal the Wise) - Transform: Invisible Stalker*/, 135235 /*135235 (Spectral Beastmaster) - Transform: Invisible Stalker*/, 135470 /*135470 (Aka'ali the Conqueror)*/, 135475 /*135475 (Kula the Butcher) - Transform: Invisible Stalker, Dual Wield*/, 135239 /*135239 (Spectral Witch Doctor) - Transform: Invisible Stalker*/, 135204 /*135204 (Spectral Hex Priest) - Transform: Invisible Stalker*/, 135192 /*135192 (Honored Raptor) - Transform: Invisible Stalker*/, 135167 /*135167 (Spectral Berserker) - Transform: Invisible Stalker*/, 134993 /*134993 (Mchimba the Embalmer)*/, 137484 /*137484 (King A'akul)*/, 134331 /*134331 (King Rahu'ai)*/, 137486 /*137486 (Queen Patlaa)*/, 137487 /*137487 (Skeletal Hunting Raptor)*/, 134251 /*134251 (Seneschal M'bara)*/, 137485 /*137485 (Bloodsworn Agent) - Dual Wield*/, 137473 /*137473 (Guard Captain Atu) - Dual Wield*/, 137474 /*137474 (King Timalji)*/, 137478 /*137478 (Queen Wasi)*/, 133943 /*133943 (Minion of Zul) - Bound by Shadow, Minion of Zul Autoattack Override*/, 137652 /*137652 (Untainted Guard Spirit) - Friendly Troll Spirit Spawn*/, 137651 /*137651 (Untainted Priest Spirit) - Friendly Troll Spirit Spawn*/, 137650 /*137650 (Untainted Spirit) - Friendly Troll Spirit Spawn*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(136160, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '269055'), -- 136160 (King Dazar) - Dazar Pre-fight Visual
(135472, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '271570'), -- 135472 (Zanazal the Wise) - Transform: Invisible Stalker
(135235, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '271570'), -- 135235 (Spectral Beastmaster) - Transform: Invisible Stalker
(135470, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 135470 (Aka'ali the Conqueror)
(135475, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '271570 42459'), -- 135475 (Kula the Butcher) - Transform: Invisible Stalker, Dual Wield
(135239, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '271570'), -- 135239 (Spectral Witch Doctor) - Transform: Invisible Stalker
(135204, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '271570'), -- 135204 (Spectral Hex Priest) - Transform: Invisible Stalker
(135192, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '271570'), -- 135192 (Honored Raptor) - Transform: Invisible Stalker
(135167, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '271570'), -- 135167 (Spectral Berserker) - Transform: Invisible Stalker
(137484, 0, 0, 0, 0, 0, 1, 0, 0, 15151, 0, 0, 0, ''), -- 137484 (King A'akul)
(134331, 0, 0, 0, 0, 0, 1, 0, 0, 15151, 0, 0, 0, ''), -- 134331 (King Rahu'ai)
(137486, 0, 0, 0, 0, 0, 1, 0, 0, 15151, 0, 0, 0, ''), -- 137486 (Queen Patlaa)
(137487, 0, 0, 0, 0, 0, 1, 0, 0, 15649, 0, 0, 0, ''), -- 137487 (Skeletal Hunting Raptor)
(134251, 0, 0, 0, 0, 0, 1, 0, 0, 15148, 0, 0, 0, ''), -- 134251 (Seneschal M'bara)
(137485, 0, 0, 0, 0, 0, 1, 0, 0, 3998, 0, 0, 0, '42459'), -- 137485 (Bloodsworn Agent) - Dual Wield
(137473, 0, 0, 0, 0, 0, 1, 0, 0, 15151, 0, 0, 0, '42459'), -- 137473 (Guard Captain Atu) - Dual Wield
(137474, 0, 0, 0, 0, 0, 1, 0, 0, 3998, 0, 0, 0, ''), -- 137474 (King Timalji)
(137478, 0, 0, 0, 0, 0, 1, 0, 0, 15148, 0, 0, 0, ''), -- 137478 (Queen Wasi)
(133943, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '269935 276032'), -- 133943 (Minion of Zul) - Bound by Shadow, Minion of Zul Autoattack Override
(137652, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '270691'), -- 137652 (Untainted Guard Spirit) - Friendly Troll Spirit Spawn
(137651, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '270691'), -- 137651 (Untainted Priest Spirit) - Friendly Troll Spirit Spawn
(137650, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '270691'); -- 137650 (Untainted Spirit) - Friendly Troll Spirit Spawn

UPDATE `gameobject_template_addon` SET `AIAnimKitID`=13792 WHERE `entry`=287117; -- Waterfall
UPDATE `gameobject_template_addon` SET `flags`=32, `WorldEffectID`=2100 WHERE `entry`=288466; -- Serpentine Seal

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (79417,198489));

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (135239,133935,134174,135167,137989,137478,135475,137969,134994,135235,134251,135192,134739,137473,135322,134157,136160,135470,137487,135472,135231,134158,137485,137486,135204,134331,133943,137484,137474,134993));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(135239, 2, 7, 5, 1, 164836, 2097224, 0), -- Spectral Witch Doctor
(133935, 2, 7, 8.5, 1, 164820, 2097768, 0), -- Animated Guardian
(134174, 2, 7, 7.5, 1, 164824, 2097256, 0), -- Shadow-Borne Witch Doctor
(135167, 2, 7, 6, 1, 164831, 2097256, 0), -- Spectral Berserker
(137989, 2, 7, 3, 1, 164860, 2097256, 0), -- Embalming Fluid
(137478, 2, 7, 8, 1, 164852, 32, 0), -- Queen Wasi
(135475, 2, 7, 18, 1, 164841, 2097256, 128), -- Kula the Butcher
(137969, 2, 7, 10, 1, 164859, 2097768, 0), -- Interment Construct
(134994, 2, 7, 1, 1, 164830, 2097224, 0), -- Spectral Headhunter
(135235, 2, 7, 4.75, 1, 164835, 2097256, 0), -- Spectral Beastmaster
(134251, 2, 7, 5, 1, 164825, 2097224, 0), -- Seneschal M'bara
(135192, 2, 7, 5, 1, 164832, 2097224, 0), -- Honored Raptor
(134739, 2, 7, 12, 1, 164828, 2097768, 0), -- Purification Construct
(137473, 2, 7, 5, 1, 164850, 2097224, 0), -- Guard Captain Atu
(135322, 2, 7, 35, 1, 164838, 2097257, 128), -- The Golden Serpent
(134157, 2, 7, 5, 1, 164822, 2097256, 0), -- Shadow-Borne Warrior
(136160, 2, 7, 39, 1, 164846, 2097256, 128), -- King Dazar
(135470, 2, 7, 18, 1, 164839, 2097256, 128), -- Aka'ali the Conqueror
(137487, 2, 7, 5, 1, 164856, 2097225, 0), -- Skeletal Hunting Raptor
(135472, 2, 7, 18, 1, 164840, 2097256, 128), -- Zanazal the Wise
(135231, 2, 7, 10, 1, 164834, 2097256, 0), -- Spectral Brute
(134158, 2, 7, 8, 1, 164823, 2097256, 0), -- Shadow-Borne Champion
(137485, 2, 7, 5, 1, 164854, 2097256, 0), -- Bloodsworn Agent
(137486, 2, 7, 8, 1, 164855, 32, 0), -- Queen Patlaa
(135204, 2, 7, 4.5, 1, 164833, 2097256, 0), -- Spectral Hex Priest
(134331, 2, 7, 8, 1, 164826, 2097224, 0), -- King Rahu'ai
(133943, 2, 7, 1, 1, 164821, 2097224, 0), -- Minion of Zul
(137484, 2, 7, 13, 1, 164853, 32, 0), -- King A'akul
(137474, 2, 7, 8, 1, 164851, 2097256, 0), -- King Timalji
(134993, 2, 7, 35, 1, 164829, 2097256, 128); -- Mchimba the Embalmer

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (141086,143486,136795,137020,136256,137652,137651,137650));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(141086, 2, 0, 0, 501, 0, 0, 0, 0, 0, 0, 0, 0, 54847), -- 141086 (Untainted Spirit Guide) - 
(143486, 2, 0, 0, 501, 536871168, 0, 0, 0, 0, 0, 0, 0, 54847), -- 143486 (Light) - Sessile, Floating
(136795, 2, 0, 0, 501, 536871168, 0, 0, 0, 0, 0, 0, 0, 54847), -- 136795 (Spear Stalker) - Sessile, Floating
(137020, 2, 2, 2, 501, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 137020 (Shadow of Zul) - Floating
(136256, 2, 0, 0, 501, 536871168, 0, 33554432, 0, 0, 0, 0, 0, 54847), -- 136256 (Coffin) - Sessile, Floating - CannotTurn
(137652, 2, 0, 0, 501, 0, 0, 0, 0, 0, 0, 0, 0, 54847), -- 137652 (Untainted Guard Spirit) - 
(137651, 2, 0, 0, 501, 0, 0, 0, 0, 0, 0, 0, 0, 54847), -- 137651 (Untainted Priest Spirit) - 
(137650, 2, 0, 0, 501, 0, 0, 0, 0, 0, 0, 0, 0, 54847); -- 137650 (Untainted Spirit) - 

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=137020 AND `DifficultyID`=0); -- Shadow of Zul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=141086 AND `DifficultyID`=0); -- Untainted Spirit Guide
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=69204 AND `DifficultyID`=0); -- Spawn of Horridon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=143486 AND `DifficultyID`=0); -- Light
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=136795 AND `DifficultyID`=0); -- Spear Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=137652 AND `DifficultyID`=0); -- Untainted Guard Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=136256 AND `DifficultyID`=0); -- Coffin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=137650 AND `DifficultyID`=0); -- Untainted Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=137651 AND `DifficultyID`=0); -- Untainted Priest Spirit
UPDATE `creature_template_difficulty` SET `ContentTuningID`=482, `StaticFlags3`=262144, `VerifiedBuild`=54847 WHERE (`Entry`=198489 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=0 WHERE (`Entry`=141086 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=0 WHERE (`Entry`=137652 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=0 WHERE (`Entry`=137651 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=0 WHERE (`Entry`=137650 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=0, `StaticFlags1`=536871168 WHERE (`Entry`=143486 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=0, `StaticFlags1`=536871168 WHERE (`Entry`=136795 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=0, `StaticFlags1`=536871168, `StaticFlags3`=33554432 WHERE (`Entry`=136256 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=0, `StaticFlags1`=536870912 WHERE (`Entry`=137020 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=328, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=79417 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134994 AND `DifficultyID`=2); -- 134994 (Spectral Headhunter) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135231 AND `DifficultyID`=2); -- 135231 (Spectral Brute) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135322 AND `DifficultyID`=2); -- 135322 (The Golden Serpent) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134174 AND `DifficultyID`=2); -- 134174 (Shadow-Borne Witch Doctor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134157 AND `DifficultyID`=2); -- 134157 (Shadow-Borne Warrior) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134158 AND `DifficultyID`=2); -- 134158 (Shadow-Borne Champion) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136160 AND `DifficultyID`=2); -- 136160 (King Dazar) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135472 AND `DifficultyID`=2); -- 135472 (Zanazal the Wise) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135470 AND `DifficultyID`=2); -- 135470 (Aka'ali the Conqueror) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135204 AND `DifficultyID`=2); -- 135204 (Spectral Hex Priest) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135475 AND `DifficultyID`=2); -- 135475 (Kula the Butcher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135167 AND `DifficultyID`=2); -- 135167 (Spectral Berserker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135239 AND `DifficultyID`=2); -- 135239 (Spectral Witch Doctor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135235 AND `DifficultyID`=2); -- 135235 (Spectral Beastmaster) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135192 AND `DifficultyID`=2); -- 135192 (Honored Raptor) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134993 AND `DifficultyID`=2); -- 134993 (Mchimba the Embalmer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137989 AND `DifficultyID`=2); -- 137989 (Embalming Fluid) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137487 AND `DifficultyID`=2); -- 137487 (Skeletal Hunting Raptor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134251 AND `DifficultyID`=2); -- 134251 (Seneschal M'bara) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137473 AND `DifficultyID`=2); -- 137473 (Guard Captain Atu) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `VerifiedBuild`=54847 WHERE (`Entry`=137486 AND `DifficultyID`=2); -- 137486 (Queen Patlaa) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137969 AND `DifficultyID`=2); -- 137969 (Interment Construct) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134739 AND `DifficultyID`=2); -- 134739 (Purification Construct) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134331 AND `DifficultyID`=2); -- 134331 (King Rahu'ai) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `VerifiedBuild`=54847 WHERE (`Entry`=137484 AND `DifficultyID`=2); -- 137484 (King A'akul) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137485 AND `DifficultyID`=2); -- 137485 (Bloodsworn Agent) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `VerifiedBuild`=54847 WHERE (`Entry`=137478 AND `DifficultyID`=2); -- 137478 (Queen Wasi) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137474 AND `DifficultyID`=2); -- 137474 (King Timalji) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=133935 AND `DifficultyID`=2); -- 133935 (Animated Guardian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=133943 AND `DifficultyID`=2); -- 133943 (Minion of Zul) - CanSwim
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `HealthModifier`=17, `ManaModifier`=50, `CreatureDifficultyID`=143459, `TypeFlags`=36 WHERE (`Entry`=137020 AND `DifficultyID`=2); -- Shadow of Zul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143232 WHERE (`Entry`=136795 AND `DifficultyID`=2); -- Spear Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=154784 WHERE (`Entry`=143486 AND `DifficultyID`=2); -- Light
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=148089 WHERE (`Entry`=141086 AND `DifficultyID`=2); -- Untainted Spirit Guide
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `HealthModifier`=15, `CreatureDifficultyID`=144155 WHERE (`Entry`=137652 AND `DifficultyID`=2); -- Untainted Guard Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144154 WHERE (`Entry`=137651 AND `DifficultyID`=2); -- Untainted Priest Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144153 WHERE (`Entry`=137650 AND `DifficultyID`=2); -- Untainted Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142542 WHERE (`Entry`=136256 AND `DifficultyID`=2); -- Coffin

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (137473,134994,135204,134251,137484,137486,133935,134174,135475,135231,134157,135192,137487,133943,135470,134158,135472,134739,136160,137474,135322,135235,134993,137478,135239,137485,134331,135167,137989,137969));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(137473, 23, 7, 8.125, 1, 147437, 2097224, 0), -- Guard Captain Atu
(134994, 23, 7, 1.625, 1, 147459, 2097224, 0), -- Spectral Headhunter
(135204, 23, 7, 4.5, 1, 147456, 2097256, 0), -- Spectral Hex Priest
(134251, 23, 7, 5, 1, 147464, 2097224, 0), -- Seneschal M'bara
(137484, 23, 7, 13, 1, 147434, 32, 0), -- King A'akul
(137486, 23, 7, 8, 1, 147432, 32, 0), -- Queen Patlaa
(133935, 23, 7, 8.5, 1, 147469, 2097768, 0), -- Animated Guardian
(134174, 23, 7, 7.5, 1, 147465, 2097256, 0), -- Shadow-Borne Witch Doctor
(135475, 23, 7, 18, 1, 147447, 2097256, 128), -- Kula the Butcher
(135231, 23, 7, 10, 1, 147455, 2097256, 0), -- Spectral Brute
(134157, 23, 7, 5, 1, 147467, 2097256, 0), -- Shadow-Borne Warrior
(135192, 23, 7, 5, 1, 147457, 2097224, 0), -- Honored Raptor
(137487, 23, 7, 5, 1, 147431, 2097225, 0), -- Skeletal Hunting Raptor
(133943, 23, 7, 1, 1, 147468, 2097224, 0), -- Minion of Zul
(135470, 23, 7, 18, 1, 147449, 2097256, 128), -- Aka'ali the Conqueror
(134158, 23, 7, 8, 1, 147466, 2097256, 0), -- Shadow-Borne Champion
(135472, 23, 7, 18, 1, 147448, 2097256, 128), -- Zanazal the Wise
(134739, 23, 7, 12, 1, 147461, 2097768, 0), -- Purification Construct
(136160, 23, 7, 39, 1, 147441, 2097256, 128), -- King Dazar
(137474, 23, 7, 8, 1, 147436, 2097256, 0), -- King Timalji
(135322, 23, 7, 35, 1, 147451, 2097257, 128), -- The Golden Serpent
(135235, 23, 7, 4.75, 1, 147454, 2097256, 0), -- Spectral Beastmaster
(134993, 23, 7, 35, 1, 147460, 2097256, 128), -- Mchimba the Embalmer
(137478, 23, 7, 8, 1, 147435, 32, 0), -- Queen Wasi
(135239, 23, 7, 5, 1, 147453, 2097224, 0), -- Spectral Witch Doctor
(137485, 23, 7, 5, 1, 147433, 2097256, 0), -- Bloodsworn Agent
(134331, 23, 7, 8, 1, 147463, 2097224, 0), -- King Rahu'ai
(135167, 23, 7, 6, 1, 147458, 2097256, 0), -- Spectral Berserker
(137989, 23, 7, 3, 1, 147427, 2097256, 0), -- Embalming Fluid
(137969, 23, 7, 10, 1, 147428, 2097768, 0); -- Interment Construct

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (143486,136795,137020,136256,137652,137651,137650));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(143486, 23, 0, 0, 502, 536871168, 0, 0, 0, 0, 0, 0, 0, 54847), -- 143486 (Light) - Sessile, Floating
(136795, 23, 0, 0, 502, 536871168, 0, 0, 0, 0, 0, 0, 0, 54847), -- 136795 (Spear Stalker) - Sessile, Floating
(137020, 23, 2, 2, 502, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 137020 (Shadow of Zul) - Floating
(136256, 23, 0, 0, 502, 536871168, 0, 33554432, 0, 0, 0, 0, 0, 54847), -- 136256 (Coffin) - Sessile, Floating - CannotTurn
(137652, 23, 0, 0, 502, 0, 0, 0, 0, 0, 0, 0, 0, 54847), -- 137652 (Untainted Guard Spirit) - 
(137651, 23, 0, 0, 502, 0, 0, 0, 0, 0, 0, 0, 0, 54847), -- 137651 (Untainted Priest Spirit) - 
(137650, 23, 0, 0, 502, 0, 0, 0, 0, 0, 0, 0, 0, 54847); -- 137650 (Untainted Spirit) - 

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135231 AND `DifficultyID`=23); -- 135231 (Spectral Brute) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134994 AND `DifficultyID`=23); -- 134994 (Spectral Headhunter) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135322 AND `DifficultyID`=23); -- 135322 (The Golden Serpent) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134174 AND `DifficultyID`=23); -- 134174 (Shadow-Borne Witch Doctor) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134158 AND `DifficultyID`=23); -- 134158 (Shadow-Borne Champion) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134157 AND `DifficultyID`=23); -- 134157 (Shadow-Borne Warrior) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136160 AND `DifficultyID`=23); -- 136160 (King Dazar) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135472 AND `DifficultyID`=23); -- 135472 (Zanazal the Wise) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135475 AND `DifficultyID`=23); -- 135475 (Kula the Butcher) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135470 AND `DifficultyID`=23); -- 135470 (Aka'ali the Conqueror) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135192 AND `DifficultyID`=23); -- 135192 (Honored Raptor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135167 AND `DifficultyID`=23); -- 135167 (Spectral Berserker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135204 AND `DifficultyID`=23); -- 135204 (Spectral Hex Priest) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135239 AND `DifficultyID`=23); -- 135239 (Spectral Witch Doctor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=135235 AND `DifficultyID`=23); -- 135235 (Spectral Beastmaster) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134993 AND `DifficultyID`=23); -- 134993 (Mchimba the Embalmer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137989 AND `DifficultyID`=23); -- 137989 (Embalming Fluid) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137969 AND `DifficultyID`=23); -- 137969 (Interment Construct) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `VerifiedBuild`=54847 WHERE (`Entry`=137484 AND `DifficultyID`=23); -- 137484 (King A'akul) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134739 AND `DifficultyID`=23); -- 134739 (Purification Construct) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134331 AND `DifficultyID`=23); -- 134331 (King Rahu'ai) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134251 AND `DifficultyID`=23); -- 134251 (Seneschal M'bara) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `VerifiedBuild`=54847 WHERE (`Entry`=137486 AND `DifficultyID`=23); -- 137486 (Queen Patlaa) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137487 AND `DifficultyID`=23); -- 137487 (Skeletal Hunting Raptor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137473 AND `DifficultyID`=23); -- 137473 (Guard Captain Atu) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137485 AND `DifficultyID`=23); -- 137485 (Bloodsworn Agent) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=137474 AND `DifficultyID`=23); -- 137474 (King Timalji) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `VerifiedBuild`=54847 WHERE (`Entry`=137478 AND `DifficultyID`=23); -- 137478 (Queen Wasi) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=133935 AND `DifficultyID`=23); -- 133935 (Animated Guardian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=133943 AND `DifficultyID`=23); -- 133943 (Minion of Zul) - CanSwim
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `HealthModifier`=17, `ManaModifier`=50, `CreatureDifficultyID`=143459, `TypeFlags`=36 WHERE (`Entry`=137020 AND `DifficultyID`=23); -- Shadow of Zul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=154784 WHERE (`Entry`=143486 AND `DifficultyID`=23); -- Light
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143232 WHERE (`Entry`=136795 AND `DifficultyID`=23); -- Spear Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `HealthModifier`=15, `CreatureDifficultyID`=144155 WHERE (`Entry`=137652 AND `DifficultyID`=23); -- Untainted Guard Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142542 WHERE (`Entry`=136256 AND `DifficultyID`=23); -- Coffin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144153 WHERE (`Entry`=137650 AND `DifficultyID`=23); -- Untainted Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144154 WHERE (`Entry`=137651 AND `DifficultyID`=23); -- Untainted Priest Spirit

-- Waypoints for CGUID+10
SET @ENTRY := 137651;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Untainted Priest Spirit - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -950.0295, 2577.075, 833.1519, NULL, 0),
(@PATH, 1, -955.2518, 2572.451, 833.1519, NULL, 0),
(@PATH, 2, -956.1302, 2550.737, 833.152, NULL, 0),
(@PATH, 3, -945.3281, 2550.104, 833.1519, NULL, 0),
(@PATH, 4, -937.493, 2552.74, 833.1519, NULL, 0),
(@PATH, 5, -935.8733, 2563.595, 833.1929, NULL, 0),
(@PATH, 6, -934.5261, 2574.898, 833.1519, NULL, 0),
(@PATH, 7, -941.3143, 2576.654, 833.2446, NULL, 0);

UPDATE `creature` SET `position_x`= -950.0295, `position_y`= 2577.075, `position_z`= 833.1519, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+10;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+10;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@CGUID+10, @PATH, 1, '270691');
