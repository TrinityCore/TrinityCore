SET @CGUID := 10004221;
SET @OGUID := 10001042;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+69;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1955.2742919921875, -3066.689208984375, 154.8338623046875, 1.17106485366821289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+1, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1935.2222900390625, -3060.39404296875, 154.8338623046875, 5.996160507202148437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1 (Auras: 369706 - Conversation Aura: Talk/Question/Exclamation [DNT])
(@CGUID+2, 224566, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1959.326416015625, -3055.833251953125, 154.8338623046875, 0.897775053977966308, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Bondaz (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+3, 219437, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1962.763916015625, -3068.38720703125, 154.8338623046875, 0.824869394302368164, 120, 0, 0, 0, 0x2, NULL, NULL, NULL, 57388), -- Dornogal Citizen (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+4, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1944.0560302734375, -3061.875732421875, 154.7505340576171875, 0.008726147934794425, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1 (Auras: 449464 - Cosmetic - Reading Book [DNT])
(@CGUID+5, 226750, 2552, 14717, 15178, '0', 0, 0, 0, 1, 1957.451416015625, -3081.65283203125, 154.8338623046875, 1.587696194648742675, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Freysworn Etterca (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+6, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1937.0711669921875, -3059.928955078125, 154.8338623046875, 3.773742914199829101, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+7, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1953.75, -3056.267333984375, 154.8338623046875, 5.523071765899658203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+8, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1945.5694580078125, -3099.3369140625, 154.825714111328125, 3.78041243553161621, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+9, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1943.3125, -3097.838623046875, 154.825714111328125, 4.320653438568115234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+10, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1936.2864990234375, -3061.9150390625, 154.8338623046875, 1.726907610893249511, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+11, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1928.81298828125, -3086.1806640625, 154.74688720703125, 5.458032608032226562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+12, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1952.6788330078125, -3057.744873046875, 154.8338623046875, 5.955614089965820312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+13, 219437, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1964.51220703125, -3066.67529296875, 154.8338623046875, 4.031608104705810546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Dornogal Citizen (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+14, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1940.69970703125, -3097.232666015625, 154.825714111328125, 4.850566864013671875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+15, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1989.60595703125, -3061.998291015625, 154.834136962890625, 1.512082457542419433, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1 (Auras: 369706 - Conversation Aura: Talk/Question/Exclamation [DNT])
(@CGUID+16, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1916.7535400390625, -3051.97216796875, 154.8338623046875, 3.216318368911743164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+17, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1949.954833984375, -3120.9150390625, 154.72320556640625, 3.365251779556274414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+18, 217450, 2552, 14717, 15178, '0', 0, 0, 0, 3, 1966.8697509765625, -3107.882080078125, 154.9704437255859375, 4.532902717590332031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Protector (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+19, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1911.685791015625, -3057.053955078125, 154.75341796875, 3.191220998764038085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+20, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1916.6475830078125, -3048.632080078125, 154.8338623046875, 3.703105449676513671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+21, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1977.2882080078125, -3100.29345703125, 154.833892822265625, 4.221271991729736328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+22, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1920.5521240234375, -3040.845458984375, 154.8338623046875, 0.915189981460571289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+23, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1921.8836669921875, -3039.53125, 154.8338623046875, 3.984132051467895507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+24, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1948.720458984375, -3039.508544921875, 154.750457763671875, 3.181093215942382812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1 (Auras: 369706 - Conversation Aura: Talk/Question/Exclamation [DNT])
(@CGUID+25, 217450, 2552, 14717, 15178, '0', 0, 0, 0, 1, 1953.201416015625, -3107.7431640625, 154.69805908203125, 4.640353679656982421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Protector (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+26, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1948.515625, -3118.869873046875, 154.723724365234375, 4.14684915542602539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+27, 230537, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1955.6300048828125, -3030.1748046875, 154.7505340576171875, 6.233962535858154296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Annoyed Rancher (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+28, 217450, 2552, 14717, 15178, '0', 0, 0, 0, 5, 1919.2847900390625, -3085.717041015625, 154.82763671875, 3.803666114807128906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Protector (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+29, 230538, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1960.439453125, -3029.560302734375, 154.7505340576171875, 0.055885303765535354, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Playful Mosswool (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+30, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1915.625, -3047.239501953125, 154.7505340576171875, 3.944444179534912109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+31, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1989.6961669921875, -3060.463623046875, 154.834869384765625, 4.756098747253417968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+32, 230539, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1984.230712890625, -3086.364501953125, 154.7505340576171875, 5.649892330169677734, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Lost Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1 (Auras: 452224 - Cosmetic - Reading Book - All Races [DNT])
(@CGUID+33, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1909.8680419921875, -3050.776123046875, 154.6595611572265625, 2.493005275726318359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+34, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1974.3646240234375, -3099.598876953125, 154.8338623046875, 5.186998844146728515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1 (Auras: 369706 - Conversation Aura: Talk/Question/Exclamation [DNT])
(@CGUID+35, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1915.642333984375, -3069.869873046875, 154.833770751953125, 3.287769317626953125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+36, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1916.12158203125, -3049.864501953125, 154.8204498291015625, 3.230538845062255859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+37, 217450, 2552, 14717, 15178, '0', 0, 0, 0, 2, 1929.5728759765625, -3096.916748046875, 154.907928466796875, 3.803666353225708007, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Protector (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+38, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1913.6197509765625, -3046.951416015625, 154.7455596923828125, 5.692821025848388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+39, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1910.3541259765625, -3053.375, 154.660919189453125, 2.290118217468261718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+40, 230535, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1910.1041259765625, -3070.850830078125, 154.83001708984375, 6.222067832946777343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Cloth Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+41, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1911.12158203125, -3059.319580078125, 154.7337188720703125, 2.547425508499145507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+42, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1915.9566650390625, -3052.911376953125, 154.8062591552734375, 3.344275951385498046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+43, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1975.07470703125, -3100.98095703125, 154.8345794677734375, 2.157732486724853515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+44, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1910.46533203125, -3046.71875, 154.643280029296875, 4.548687458038330078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+45, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1910.015625, -3074.685791015625, 154.831085205078125, 2.237369537353515625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+46, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1948.901611328125, -3041.503173828125, 154.7505340576171875, 3.181024074554443359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+47, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1961.689208984375, -3043.614501953125, 154.8338623046875, 6.171694755554199218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+48, 230536, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1913.654541015625, -3055.366455078125, 154.759246826171875, 0.345320910215377807, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Gem Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+49, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1916.111083984375, -3051.06591796875, 154.812255859375, 2.75079512596130371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+50, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1996.0069580078125, -3070.802001953125, 154.836944580078125, 6.247013568878173828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1 (Auras: 369706 - Conversation Aura: Talk/Question/Exclamation [DNT])
(@CGUID+51, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1998.7822265625, -3057.198974609375, 154.7536163330078125, 3.124123096466064453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+52, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1997.545166015625, -3070.857666015625, 154.836944580078125, 3.217226982116699218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+53, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1960.521484375, -3019.502685546875, 154.7453155517578125, 4.694936752319335937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+54, 217450, 2552, 14717, 15178, '0', 0, 0, 0, 3, 1930.6041259765625, -3021.420166015625, 154.611907958984375, 2.319023609161376953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Protector (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+55, 230532, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1989.34033203125, -3044.342041015625, 154.8338623046875, 0.006238188594579696, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Oathsworn Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+56, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1998.759521484375, -3058.498779296875, 154.7536163330078125, 3.124123096466064453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1 (Auras: 449464 - Cosmetic - Reading Book [DNT])
(@CGUID+57, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1948.3021240234375, -3125.869873046875, 154.7254180908203125, 2.42737746238708496, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+58, 230531, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1934.7552490234375, -3020.87158203125, 154.7764129638671875, 5.616672515869140625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+59, 217450, 2552, 14717, 15178, '0', 0, 0, 0, 5, 1918.94970703125, -3032.546875, 154.452178955078125, 2.25238966941833496, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Unbound Protector (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+60, 214838, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1990.88720703125, -3046.814208984375, 154.834014892578125, 3.907140731811523437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Earthen Wagon (Area: Crossroads Plaza - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+61, 221355, 2552, 14717, 15178, '0', 23314, 0, 0, 0, 1947.9288330078125, -3102.09375, 154.825714111328125, 1.238968610763549804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Urtago (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+62, 230533, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1944.34375, -3118.848876953125, 154.7232513427734375, 3.104095220565795898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Traveling Mosswool (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+63, 230529, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1941.4410400390625, -3102.515625, 154.825714111328125, 1.101247429847717285, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Mead Trader (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+64, 230533, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1949.2718505859375, -3111.276611328125, 155.3238372802734375, 1.012755513191223144, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Traveling Mosswool (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+65, 230533, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1944.38720703125, -3120.569580078125, 154.7232513427734375, 3.20324873924255371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Traveling Mosswool (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+66, 230534, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1947.7222900390625, -3121.092041015625, 154.7234649658203125, 0.397461861371994018, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Mosswool Rancher (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+67, 230533, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1947.154541015625, -3125.069580078125, 154.7254791259765625, 3.547904729843139648, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Traveling Mosswool (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+68, 230533, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1949.319091796875, -3127.067626953125, 154.636444091796875, 1.742675304412841796, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Traveling Mosswool (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@CGUID+69, 230533, 2552, 14717, 15178, '0', 0, 0, 0, 0, 1945.482666015625, -3123.45654296875, 154.7405548095703125, 4.306085586547851562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388); -- Traveling Mosswool (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+69;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369706'), -- Oathsworn Trader - 369706 - Conversation Aura: Talk/Question/Exclamation [DNT]
(@CGUID+4, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449464'), -- Oathsworn Trader - 449464 - Cosmetic - Reading Book [DNT]
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 1029, 0, 0, 0, 0, ''), -- Freysworn Etterca
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369706'), -- Oathsworn Trader - 369706 - Conversation Aura: Talk/Question/Exclamation [DNT]
(@CGUID+18, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Unbound Protector
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 4760, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+21, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Oathsworn Trader
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 0, 24314, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369706'), -- Oathsworn Trader - 369706 - Conversation Aura: Talk/Question/Exclamation [DNT]
(@CGUID+25, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Unbound Protector
(@CGUID+28, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Unbound Protector
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '452224'), -- Lost Trader - 452224 - Cosmetic - Reading Book - All Races [DNT]
(@CGUID+33, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Oathsworn Trader
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369706'), -- Unbound Trader - 369706 - Conversation Aura: Talk/Question/Exclamation [DNT]
(@CGUID+37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Unbound Protector
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 0, 4760, 0, 0, 0, ''), -- Oathsworn Trader
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 0, 4760, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+44, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Oathsworn Trader
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369706'), -- Unbound Trader - 369706 - Conversation Aura: Talk/Question/Exclamation [DNT]
(@CGUID+51, 0, 0, 5, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Oathsworn Trader
(@CGUID+53, 0, 0, 5, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+54, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Unbound Protector
(@CGUID+55, 0, 0, 0, 0, 0, 1, 0, 0, 4760, 0, 0, 0, ''), -- Oathsworn Trader
(@CGUID+56, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449464'), -- Unbound Trader - 449464 - Cosmetic - Reading Book [DNT]
(@CGUID+57, 0, 0, 0, 0, 0, 1, 0, 0, 4760, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''); -- Unbound Protector

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+15;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 429568, 2552, 14717, 15178, '0', 0, 0, 1957.748291015625, -3075.036376953125, 154.7505340576171875, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 57388), -- Bench (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+1, 429586, 2552, 14717, 15178, '0', 0, 0, 1957.7882080078125, -3047.51220703125, 154.7505340576171875, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 57388), -- Bench (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+2, 429587, 2552, 14717, 15178, '0', 0, 0, 1971.5, -3061.328125, 154.7505340576171875, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 57388), -- Bench (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+3, 455716, 2552, 14717, 15178, '0', 0, 0, 1956.5989990234375, -3063.142333984375, 158.696441650390625, 0.811416327953338623, 0, 0, 0.394669532775878906, 0.918823122978210449, 120, 255, 1, 57388), -- DELVER'S CALL: Fungal Folly (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+4, 454463, 2552, 14717, 15178, '0', 0, 0, 1956.3385009765625, -3059.15966796875, 158.3144378662109375, 5.417534351348876953, 0, 0, -0.41943740844726562, 0.907784223556518554, 120, 255, 1, 57388), -- Wanted: The Boroughbreaker (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+5, 429573, 2552, 14717, 15178, '0', 0, 0, 1944.0504150390625, -3061.225830078125, 154.7505340576171875, 0.008726147934794425, 0, 0, 0.004363059997558593, 0.999990463256835937, 120, 255, 1, 57388), -- Bench (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+6, 423987, 2552, 14717, 15178, '0', 22903, 0, 1922.361083984375, -3084.282958984375, 154.7505340576171875, 0, 0, 0, 0, 1, 120, 255, 1, 57388), -- Dropped Package (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+7, 453153, 2552, 14717, 15178, '0', 0, 0, 1830.3603515625, -3233.7890625, 78.050994873046875, 4.721118450164794921, 0, 0, -0.70401382446289062, 0.710186243057250976, 120, 255, 1, 57388), -- Chair (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+8, 429569, 2552, 14717, 15178, '0', 0, 0, 1959.87158203125, -3019.491455078125, 154.7453155517578125, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 57388), -- Bench (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+9, 413020, 2552, 14717, 15178, '0', 0, 0, 2707.4296875, -3651.25, 196.5749969482421875, 1.572204232215881347, 0, 0, 0.707604408264160156, 0.706608831882476806, 120, 255, 1, 57388), -- Door (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+10, 453155, 2552, 14717, 15178, '0', 0, 0, 1832.44921875, -3235.3828125, 78.050994873046875, 3.132858037948608398, 0, 0, 0.999990463256835937, 0.004367320332676172, 120, 255, 1, 57388), -- Chair (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+11, 429592, 2552, 14717, 15178, '0', 0, 0, 2046.9271240234375, -3208.788330078125, 146.5104217529296875, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 57388), -- Stool (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+12, 413017, 2552, 14717, 15178, '0', 0, 0, 1410.2603759765625, -2765.88720703125, 51.60283660888671875, 4.085401535034179687, 0, 0, -0.89070415496826171, 0.454583406448364257, 120, 255, 1, 57388), -- Door (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+13, 429578, 2552, 14717, 15178, '0', 0, 0, 1949.626708984375, -3019.642333984375, 154.7453155517578125, 4.721118450164794921, 0, 0, -0.70401382446289062, 0.710186243057250976, 120, 255, 1, 57388), -- Bench (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+14, 429572, 2552, 14717, 15178, '0', 0, 0, 1998.7708740234375, -3057.848876953125, 154.7536163330078125, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 57388), -- Bench (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
(@OGUID+15, 429579, 2552, 14717, 15178, '0', 0, 0, 1998.673583984375, -3067.288330078125, 154.75347900390625, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 57388); -- Bench (Area: Crossroads Plaza - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+15;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+7, 0, 0, 0.000000087422776573, 1, 0, 0), -- Chair
(@OGUID+10, 0, 0, 0.000000087422776573, 1, 0, 0); -- Chair

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (413020 /*Door*/, 413017 /*Door*/, 455716 /*DELVER'S CALL*/, 429572 /*Bench*/, 454463 /*Wanted: The Boroughbreaker*/, 429569 /*Bench*/, 429573 /*Bench*/, 423987 /*Dropped Package*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(413020, 0, 0x30, 0, 0), -- Door
(413017, 0, 0x30, 0, 0), -- Door
(455716, 0, 0x4, 0, 0), -- DELVER'S CALL
(429572, 114, 0x0, 0, 0), -- Bench
(454463, 0, 0x4, 0, 0), -- Wanted: The Boroughbreaker
(429569, 114, 0x0, 0, 0), -- Bench
(429573, 114, 0x0, 0, 0), -- Bench
(423987, 0, 0x4, 0, 0); -- Dropped Package

-- Template
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=230536; -- Gem Trader
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=230535; -- Cloth Trader
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=230534; -- Mosswool Rancher
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=230539; -- Lost Trader
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=230529; -- Mead Trader
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=230538; -- Playful Mosswool
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=230533; -- Traveling Mosswool
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=230537; -- Annoyed Rancher
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=230531; -- Unbound Trader
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=221355; -- Urtago
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=226750; -- Freysworn Etterca
UPDATE `creature_template` SET `faction`=3407, `npcflag`=0, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=219437; -- Dornogal Citizen
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=224566; -- Bondaz
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=230532; -- Oathsworn Trader

UPDATE `gameobject_template` SET `VerifiedBuild`=57388 WHERE `entry` IN (419696, 413877, 453159, 453154, 454063, 422531, 413020, 413017, 453157, 453161, 453150, 453160, 453158, 453156, 453155, 453153, 453152, 453151, 429592, 429579, 429572, 429569, 429578, 429587, 454463, 429586, 429568, 429573, 423987, 441170, 441166, 441164, 441163, 441162);
UPDATE `gameobject_template` SET `name`='DELVER\'S CALL', `VerifiedBuild`=57388 WHERE `entry`=455716; -- DELVER'S CALL: Fungal Folly

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=214838 AND `seat_id` IN (7,6,5,4,3,2,0,1));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(214838, 227389, 7, 0, 'Earthen Wagon - Earthen Crate', 8, 0), -- Earthen Wagon - Earthen Crate
(214838, 227389, 6, 0, 'Earthen Wagon - Earthen Crate', 8, 0), -- Earthen Wagon - Earthen Crate
(214838, 227389, 5, 0, 'Earthen Wagon - Earthen Crate', 8, 0), -- Earthen Wagon - Earthen Crate
(214838, 227389, 4, 0, 'Earthen Wagon - Earthen Crate', 8, 0), -- Earthen Wagon - Earthen Crate
(214838, 227389, 3, 0, 'Earthen Wagon - Earthen Crate', 8, 0), -- Earthen Wagon - Earthen Crate
(214838, 230031, 2, 0, 'Earthen Wagon - Oathsworn Worker', 8, 0), -- Earthen Wagon - Oathsworn Worker
(214838, 214824, 0, 0, 'Earthen Wagon - Cart Hauler', 8, 0), -- Earthen Wagon - Cart Hauler
(214838, 214824, 1, 0, 'Earthen Wagon - Cart Hauler', 8, 0); -- Earthen Wagon - Cart Hauler

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (214838, 230533);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(214838, 46598, 1, 0),
(230533, 427686, 1, 0);

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (23314, 22903);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(23314, 'Cosmetic - See Urtago at Crossroads Plaza'),
(22903, 'Cosmetic - See Dropped Package at Crossroads Plaza');

DELETE FROM `phase_area` WHERE `PhaseId` IN (23314, 22903);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14717, 23314, 'Cosmetic - See Urtago at Crossroads Plaza'),
(14717, 22903, 'Cosmetic - See Dropped Package at Crossroads Plaza');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23314 AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 22903 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23314, 0, 0, 0, 47, 0, 81661, 2|8|64, 0, 1, 'Apply Phase 22642 if Quest 81661 is taken | complete | rewarded'),
(26, 22903, 0, 0, 0, 47, 0, 78754, 2|8|64, 0, 1, 'Apply Phase 22642 if Quest 78754 is taken | complete | rewarded');

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=85648;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(85648, 5, 1, 1, 0, 0, 0, 0, 0, 57388); -- Delver's Call: Earthcrawl Mines

DELETE FROM `creature_queststarter` WHERE (`id`=221355 AND `quest`=81661) OR (`id`=226750 AND `quest`=83336) OR (`id`=219437 AND `quest`=80456);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(221355, 81661, 57388), -- To Mourning Rise offered by Urtago
(226750, 83336, 57388), -- The Earthwound offered by Freysworn Etterca
(219437, 80456, 57388); -- A Sassy Arathi offered by Dornogal Citizen

DELETE FROM `gameobject_queststarter` WHERE (`id`=423987 AND `quest`=78754) OR (`id`=455716 AND `quest` IN (83758,83759,85648)) OR (`id`=454463 AND `quest`=83335);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(423987, 78754, 57388), -- Lost Delivery offered by Dropped Package
(455716, 83758, 57388), -- Delver's Call: Fungal Folly offered by DELVER'S CALL: Fungal Folly
(455716, 83759, 57388), -- Delver's Call: Kriegval's Rest offered by DELVER'S CALL: Fungal Folly
(455716, 85648, 57388), -- Delver's Call: Earthcrawl Mines offered by DELVER'S CALL: Fungal Folly
(454463, 83335, 57388); -- Wanted: The Boroughbreaker offered by Wanted: The Boroughbreaker

-- POI
DELETE FROM `quest_poi` WHERE (`QuestID`=81661 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=85664 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=85664 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=84367 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=84367 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=84367 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=82672 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=82672 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=82672 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=82672 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=82672 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(81661, 0, 0, -1, 0, 0, 2552, 2248, 0, 0, 0, 0, 0, 2397364, 0, 57388), -- To Mourning Rise
(85664, 0, 1, 0, 455323, 169115, 2601, 2215, 0, 2, 0, 0, 0, 0, 0, 57388), -- Delver's Call: Nightfall Sanctum
(85664, 0, 0, -1, 0, 0, 2601, 2215, 0, 0, 0, 0, 0, 2408551, 0, 57388), -- Delver's Call: Nightfall Sanctum
(84367, 0, 2, 32, 0, 0, 2552, 2339, 0, 0, 0, 0, 0, 2347280, 0, 57388), -- A Time to Come Together
(84367, 0, 1, 0, 452445, 216149, 2552, 2339, 0, 0, 0, 0, 0, 2433249, 0, 57388), -- A Time to Come Together
(84367, 0, 0, -1, 0, 0, 2552, 2339, 0, 0, 0, 0, 0, 2433249, 0, 57388), -- A Time to Come Together
(82672, 3, 4, 32, 0, 0, 2552, 2339, 0, 0, 0, 0, 0, 2511347, 0, 57388), -- Another Timely Invitation
(82672, 2, 3, 32, 0, 0, 2444, 2112, 0, 0, 0, 0, 0, 2512193, 0, 57388), -- Another Timely Invitation
(82672, 1, 2, 32, 0, 0, 1, 85, 0, 0, 0, 0, 0, 2511167, 0, 57388), -- Another Timely Invitation
(82672, 0, 1, 32, 0, 0, 0, 84, 0, 0, 0, 0, 0, 2510426, 0, 57388), -- Another Timely Invitation
(82672, 0, 0, -1, 0, 0, 1, 71, 0, 0, 0, 0, 0, 2535480, 0, 57388); -- Another Timely Invitation

UPDATE `quest_poi` SET `VerifiedBuild`=57388 WHERE (`QuestID`=80456 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=80456 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50605 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50604 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50604 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50600 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48642 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48642 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48642 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48639 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48639 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42234 AND `BlobIndex`=0 AND `Idx1`=0);
DELETE FROM `quest_poi_points` WHERE (`QuestID`=81661 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=85664 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=85664 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=84367 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=84367 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=84367 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=82672 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=82672 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=82672 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=82672 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=82672 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(81661, 0, 0, 2695, -3249, 178, 57388), -- To Mourning Rise
(85664, 1, 0, 2324, 1551, -160, 57388), -- Delver's Call: Nightfall Sanctum
(85664, 0, 0, 1819, 805, 125, 57388), -- Delver's Call: Nightfall Sanctum
(84367, 2, 0, 2678, -2529, 221, 57388), -- A Time to Come Together
(84367, 1, 0, 2175, -2292, 198, 57388), -- A Time to Come Together
(84367, 0, 0, 2175, -2292, 198, 57388), -- A Time to Come Together
(82672, 4, 0, 2522, -2489, 200, 57388), -- Another Timely Invitation
(82672, 3, 0, 61, -975, 836, 57388), -- Another Timely Invitation
(82672, 2, 0, 1581, -4336, 22, 57388), -- Another Timely Invitation
(82672, 1, 0, -8818, 859, 99, 57388), -- Another Timely Invitation
(82672, 0, 0, -8207, -4597, 11, 57388); -- Another Timely Invitation

UPDATE `quest_poi_points` SET `VerifiedBuild`=57388 WHERE (`QuestID`=80456 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=80456 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=53436 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=53436 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50605 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50604 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50604 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50600 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48642 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48642 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48642 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42234 AND `Idx1`=0 AND `Idx2`=0);

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=230536 AND `DifficultyID`=0); -- 230536 (Gem Trader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=230535 AND `DifficultyID`=0); -- 230535 (Cloth Trader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=230534 AND `DifficultyID`=0); -- 230534 (Mosswool Rancher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=230539 AND `DifficultyID`=0); -- 230539 (Lost Trader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=230529 AND `DifficultyID`=0); -- 230529 (Mead Trader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=230538 AND `DifficultyID`=0); -- 230538 (Playful Mosswool) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=230533 AND `DifficultyID`=0); -- 230533 (Traveling Mosswool) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=230537 AND `DifficultyID`=0); -- 230537 (Annoyed Rancher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x20000000, `VerifiedBuild`=57388 WHERE (`Entry`=220570 AND `DifficultyID`=0); -- 220570 ([DNT] Spell Target Bunny) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=230531 AND `DifficultyID`=0); -- 230531 (Unbound Trader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=221355 AND `DifficultyID`=0); -- 221355 (Urtago) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=226750 AND `DifficultyID`=0); -- 226750 (Freysworn Etterca) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=219437 AND `DifficultyID`=0); -- 219437 (Dornogal Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=224566 AND `DifficultyID`=0); -- 224566 (Bondaz) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=230532 AND `DifficultyID`=0); -- 230532 (Oathsworn Trader) - CanSwim

-- Path for Playful Mosswool
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+29;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+29, @CGUID+29, 0, 0, 515, 0, 0),
(@CGUID+29, @CGUID+27, 6, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+29;
SET @ENTRY := 230538;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Playful Mosswool - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1943.9749, -3030.4814, 154.75053, NULL, 0),
(@PATH, 1, 1954.2522, -3029.9065, 154.75053, NULL, 0),
(@PATH, 2, 1964.5295, -3029.3315, 154.75053, NULL, 0),
(@PATH, 3, 1977.1459, -3020.7917, 154.90335, NULL, 0),
(@PATH, 4, 1977.1459, -3020.7917, 154.90335, NULL, 0),
(@PATH, 5, 1982.3629, -3010.8628, 155.87643, NULL, 0),
(@PATH, 6, 1969.3142, -3004.3628, 157.27672, NULL, 0),
(@PATH, 7, 1945.0435, -3004.2102, 155.67548, NULL, 0),
(@PATH, 8, 1927.092, -3017.0244, 154.20584, NULL, 0),
(@PATH, 9, 1930.7413, -3029.9446, 154.67796, NULL, 0);

UPDATE `creature` SET `position_x`=1943.9749, `position_y`=-3030.4814, `position_z`=154.75053, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Trader
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+46;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+46, @CGUID+46, 0, 0, 515, 0, 0),
(@CGUID+46, @CGUID+24, 2, 90, 515, 0, 0);

SET @MOVERGUID := @CGUID+46;
SET @ENTRY := 230532;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Oathsworn Trader - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1966.4889, -3041.535, 154.75075, NULL, 0),
(@PATH, 1, 1965.2028, -3040.2214, 154.75064, NULL, 0),
(@PATH, 2, 1963.9166, -3038.908, 154.75053, NULL, 0),
(@PATH, 3, 1942.1285, -3039.769, 154.75043, NULL, 0),
(@PATH, 4, 1942.1285, -3039.769, 154.75043, NULL, 0),
(@PATH, 5, 1927.3629, -3054.25, 154.75053, NULL, 0),
(@PATH, 6, 1931.9219, -3073.5676, 154.75053, NULL, 0),
(@PATH, 7, 1950.0764, -3089.5244, 154.7467, NULL, 0),
(@PATH, 8, 1968.6823, -3088.3682, 154.75053, NULL, 0),
(@PATH, 9, 1980.7466, -3075.2673, 154.75053, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Trader
SET @MOVERGUID := @CGUID+11;
SET @ENTRY := 230531;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Unbound Trader - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1939.2952, -3099.606, 154.74239, NULL, 8990),
(@PATH, 1, 1924.4618, -3077.2222, 154.75052, NULL, 0),
(@PATH, 2, 1915.658, -3071.9358, 154.75053, NULL, 8039),
(@PATH, 3, 1936.9271, -3094.967, 154.74463, NULL, 0);

UPDATE `creature` SET `position_x`=1939.2952, `position_y`=-3099.606, `position_z`=154.74239, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
