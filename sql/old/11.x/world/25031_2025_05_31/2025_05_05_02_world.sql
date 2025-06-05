SET @CGUID := 7002663;
SET @OGUID := 7000559;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+96;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 61169, 1643, 8721, 9224, '0', 0, 0, 0, 0, 391.442718505859375, 2269.13720703125, 107.4170761108398437, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+1, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 357.05035400390625, 2255.35595703125, 105.2476730346679687, 6.164214611053466796, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+2, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 349.213531494140625, 2259.295166015625, 104.2045822143554687, 2.253811120986938476, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+3, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 373.48089599609375, 2273.526123046875, 105.9839324951171875, 3.848378181457519531, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 362.498260498046875, 2270.078125, 106.7664947509765625, 6.237759113311767578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 257545 - Cosmetic - Boar Eating)
(@CGUID+5, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 385.352447509765625, 2266.960205078125, 106.68914794921875, 0.407776445150375366, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+6, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 269.9444580078125, 2227.901123046875, 89.9731292724609375, 5.702755451202392578, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+7, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 276.921875, 2242.58154296875, 91.0220489501953125, 6.141379356384277343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+8, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 372.265625, 2234.87841796875, 105.5271530151367187, 3.334487438201904296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 253518 - Trogg Sleep)
(@CGUID+9, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 284.96875, 2238.8681640625, 91.67546844482421875, 0.725062847137451171, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+10, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 407.979156494140625, 2262.567626953125, 106.751434326171875, 1.956143021583557128, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 253518 - Trogg Sleep)
(@CGUID+11, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 288.704864501953125, 2253.564208984375, 92.0781707763671875, 5.406569480895996093, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+12, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 364.3125, 2292.470458984375, 106.2022628784179687, 4.964478015899658203, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+13, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 411.446197509765625, 2265.958251953125, 106.9102859497070312, 3.334487438201904296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 253518 - Trogg Sleep)
(@CGUID+14, 127127, 1643, 8721, 9224, '0', 0, 0, 0, 0, 377.201385498046875, 2288.548583984375, 106.0498123168945312, 2.272700309753417968, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Earthcaller (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+15, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 369.802093505859375, 2232.579833984375, 105.2280349731445312, 0.071830905973911285, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+16, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 281.60589599609375, 2231.56591796875, 91.64772796630859375, 4.92475748062133789, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+17, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 365.229156494140625, 2265.3369140625, 106.4428024291992187, 2.676343441009521484, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+18, 127127, 1643, 8721, 9224, '0', 0, 0, 0, 0, 367.626739501953125, 2256.907958984375, 105.6716690063476562, 4.573298931121826171, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Earthcaller (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+19, 128389, 1643, 8721, 9224, '0', 0, 0, 0, 0, 242.701385498046875, 2205.89404296875, 99.16839599609375, 2.985975503921508789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vale Falcon (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+20, 127125, 1643, 8721, 9224, '0', 0, 0, 0, 1, 364.633697509765625, 2454.013916015625, 122.9622955322265625, 6.152285575866699218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Cragg the Stoneshaker (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+21, 127127, 1643, 8721, 9224, '0', 0, 0, 0, 0, 326.97222900390625, 2356.609375, 105.2478485107421875, 0.096523873507976531, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Earthcaller (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+22, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 337.545135498046875, 2407.89404296875, 129.17425537109375, 1.673258781433105468, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+23, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 341.836822509765625, 2330.614501953125, 106.4063034057617187, 2.020832300186157226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+24, 127822, 1643, 8721, 9224, '0', 0, 0, 0, 0, 274.0538330078125, 2376.505126953125, 108.5680770874023437, 2.701892375946044921, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Alpine Goat (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+25, 128389, 1643, 8721, 9224, '0', 0, 0, 0, 0, 281.407989501953125, 2362.52783203125, 117.164703369140625, 0.333355724811553955, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vale Falcon (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+26, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 363.65972900390625, 2438.046875, 125.39410400390625, 2.394583463668823242, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+27, 128389, 1643, 8721, 9224, '0', 0, 0, 0, 0, 335.6788330078125, 2426.00341796875, 152.844024658203125, 5.8390350341796875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vale Falcon (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+28, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 332.546875, 2336.741455078125, 105.6859893798828125, 2.62561202049255371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+29, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 367.3194580078125, 2442.95654296875, 124.3978424072265625, 2.564402341842651367, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+30, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 343.501739501953125, 2343.7119140625, 106.9490127563476562, 5.241635799407958984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 257545 - Cosmetic - Boar Eating)
(@CGUID+31, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 353.364593505859375, 2446.8212890625, 125.4465789794921875, 6.152285575866699218, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+32, 61169, 1643, 8721, 9224, '0', 0, 0, 0, 0, 454.345489501953125, 2411.595458984375, 133.59918212890625, 6.243777751922607421, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+33, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 431.305572509765625, 2356.484375, 121.4927520751953125, 6.273431777954101562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 257545 - Cosmetic - Boar Eating)
(@CGUID+34, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 463.82464599609375, 2330.55029296875, 120.412384033203125, 4.16760110855102539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 257545 - Cosmetic - Boar Eating)
(@CGUID+35, 127129, 1643, 8721, 9224, '0', 0, 0, 0, 1, 475.19097900390625, 2415.75, 133.216766357421875, 1.499485373497009277, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Grozgore (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+36, 61169, 1643, 8721, 9224, '0', 0, 0, 0, 0, 386.390625, 2285.7587890625, 106.9093093872070312, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+37, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 407.078125, 2361.869873046875, 121.6177749633789062, 0.064570903778076171, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+38, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 380.286468505859375, 2324.3125, 119.6390151977539062, 6.108628273010253906, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+39, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 414.21527099609375, 2393.833251953125, 121.941925048828125, 3.20683145523071289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+40, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 418.3350830078125, 2351.067626953125, 121.1899185180664062, 0.839277625083923339, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+41, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 434, 2378.229248046875, 120.1144638061523437, 3.20683145523071289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+42, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 373.842010498046875, 2340.28466796875, 121.5666656494140625, 4.902834892272949218, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+43, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 444.13714599609375, 2376.0625, 121.1314468383789062, 4.7057952880859375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+44, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 430.072906494140625, 2306.45654296875, 122.6851730346679687, 1.161684989929199218, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+45, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 422.151031494140625, 2310.848876953125, 121.1915054321289062, 0.563427627086639404, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+46, 127127, 1643, 8721, 9224, '0', 0, 0, 0, 0, 423.916656494140625, 2312.260498046875, 121.0427169799804687, 6.265868663787841796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Earthcaller (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+47, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 424.970489501953125, 2365.36279296875, 121.6403579711914062, 4.896539688110351562, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+48, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 444.26214599609375, 2361.178955078125, 121.4310760498046875, 1.087086319923400878, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 253518 - Trogg Sleep)
(@CGUID+49, 127127, 1643, 8721, 9224, '0', 0, 0, 0, 0, 426.055572509765625, 2346.291748046875, 121.38421630859375, 3.20683145523071289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Earthcaller (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+50, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 434.388885498046875, 2302.90283203125, 122.8074722290039062, 0.963643550872802734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 253518 - Trogg Sleep)
(@CGUID+51, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 414.376739501953125, 2379.75, 121.509185791015625, 1.229805588722229003, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+52, 128389, 1643, 8721, 9224, '0', 0, 0, 0, 0, 415.7413330078125, 2408.5556640625, 133.859649658203125, 5.855517864227294921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vale Falcon (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+53, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 454.4132080078125, 2357.423583984375, 121.35693359375, 1.956143021583557128, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 253518 - Trogg Sleep)
(@CGUID+54, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 451.3663330078125, 2304.21533203125, 122.5927658081054687, 1.385763287544250488, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+55, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 452.427093505859375, 2360.600830078125, 121.4307632446289062, 0.777033150196075439, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+56, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 454.345489501953125, 2411.595458984375, 133.59918212890625, 6.248808860778808593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+57, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 472.723968505859375, 2348.640625, 121.6574478149414062, 0.663515627384185791, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+58, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 474.657989501953125, 2350.71533203125, 121.3279953002929687, 2.303951740264892578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+59, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 444.62152099609375, 2363.388916015625, 121.4310760498046875, 2.453795909881591796, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+60, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 488.380218505859375, 2423.404541015625, 133.7907257080078125, 3.966281652450561523, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+61, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 404.708343505859375, 2373.2275390625, 122.4451828002929687, 0.963643550872802734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 253518 - Trogg Sleep)
(@CGUID+62, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 435.88714599609375, 2327.375, 122.2760391235351562, 0.933042824268341064, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+63, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 443.614593505859375, 2337.15625, 121.3116531372070312, 1.840433001518249511, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+64, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 396.305572509765625, 2315.835205078125, 121.0241470336914062, 5.900308609008789062, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+65, 127127, 1643, 8721, 9224, '0', 0, 0, 0, 0, 446.5069580078125, 2338.87841796875, 121.2719650268554687, 2.570128440856933593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Earthcaller (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+66, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 422.463531494140625, 2326.578125, 120.3679885864257812, 3.753959417343139648, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 257545 - Cosmetic - Boar Eating)
(@CGUID+67, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 460.90277099609375, 2293.782958984375, 121.17584228515625, 2.216945171356201171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+68, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 424.614593505859375, 2338.5556640625, 121.0251922607421875, 0.869092226028442382, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+69, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 454.453125, 2340.73095703125, 120.8060073852539062, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+70, 128389, 1643, 8721, 9224, '0', 0, 0, 0, 0, 462.729156494140625, 2284.40625, 133.9301300048828125, 2.55626082420349121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vale Falcon (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+71, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 413.423614501953125, 2358.15966796875, 120.51513671875, 4.21267557144165039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 257545 - Cosmetic - Boar Eating)
(@CGUID+72, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 491.08160400390625, 2393.954833984375, 132.5946502685546875, 4.327677249908447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+73, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 407.5225830078125, 2336.255126953125, 120.1376571655273437, 0.751999855041503906, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+74, 127092, 1643, 8721, 9224, '0', 0, 0, 0, 0, 418.04339599609375, 2406.364501953125, 122.2613143920898437, 4.850778579711914062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bonegnasher Skullcrusher (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 253518 - Trogg Sleep)
(@CGUID+75, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 492.857635498046875, 2415.552001953125, 132.441741943359375, 1.804983019828796386, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 257545 - Cosmetic - Boar Eating)
(@CGUID+76, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 463.20660400390625, 2411.81591796875, 136.6624908447265625, 2.369090557098388671, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+77, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 493.414947509765625, 2389.66845703125, 132.1191864013671875, 4.024404525756835937, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+78, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 400.524322509765625, 2340.319580078125, 120.4952621459960937, 5.00078439712524414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 257545 - Cosmetic - Boar Eating)
(@CGUID+79, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 423.442718505859375, 2354.08154296875, 122.00604248046875, 3.671585798263549804, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2
(@CGUID+80, 127699, 1643, 8721, 9224, '0', 0, 0, 0, 0, 493.810760498046875, 2392.873291015625, 132.19805908203125, 3.758102655410766601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tamed Boar (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (Auras: 257545 - Cosmetic - Boar Eating)
(@CGUID+81, 4076, 1643, 8721, 9224, '0', 0, 0, 0, 0, 442.62847900390625, 2315.345458984375, 120.6244354248046875, 3.803846597671508789, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Roach (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+82, 127822, 1643, 8721, 9224, '0', 0, 0, 0, 0, 465.211822509765625, 2263.796875, 146.7468414306640625, 1.029627799987792968, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Alpine Goat (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+83, 128389, 1643, 8721, 9224, '0', 0, 0, 0, 0, 497.307281494140625, 2417.223876953125, 168.6127777099609375, 4.681622982025146484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vale Falcon (Area: North Pass Caverns - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+84, 143929, 1643, 8721, 0, '0', 0, 0, 0, 0, 467.414947509765625, 2172.609375, 169.3559722900390625, 6.224902153015136718, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Hexed Craghopper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+85, 143929, 1643, 8721, 0, '0', 0, 0, 0, 0, 496.057281494140625, 2259.053955078125, 153.826690673828125, 1.085771083831787109, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Hexed Craghopper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+86, 143929, 1643, 8721, 0, '0', 0, 0, 0, 0, 492.939239501953125, 2181.526123046875, 163.463897705078125, 1.539915323257446289, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Hexed Craghopper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+87, 143929, 1643, 8721, 0, '0', 0, 0, 0, 0, 374.083343505859375, 2143.82470703125, 215.8865203857421875, 2.555014848709106445, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Hexed Craghopper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+88, 143929, 1643, 8721, 0, '0', 0, 0, 0, 0, 452.03472900390625, 2223.916748046875, 165.987274169921875, 2.521463871002197265, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Hexed Craghopper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+89, 143929, 1643, 8721, 0, '0', 0, 0, 0, 0, 425.817718505859375, 2168.710205078125, 189.887359619140625, 2.939795255661010742, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Hexed Craghopper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+90, 127822, 1643, 8721, 0, '0', 0, 0, 0, 0, 609.44097900390625, 2437.859375, 192.080810546875, 0.810693800449371337, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Alpine Goat (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+91, 127822, 1643, 8721, 0, '0', 0, 0, 0, 0, 550.92706298828125, 2307.092041015625, 153.233917236328125, 1.636580824851989746, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Alpine Goat (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+92, 143929, 1643, 8721, 0, '0', 0, 0, 0, 0, 360.907989501953125, 2127.345458984375, 217.3874359130859375, 3.856368064880371093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Hexed Craghopper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+93, 143929, 1643, 8721, 0, '0', 0, 0, 0, 0, 442.73089599609375, 2110.951416015625, 167.123565673828125, 1.30035257339477539, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Hexed Craghopper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+94, 143929, 1643, 8721, 0, '0', 0, 0, 0, 0, 390.611114501953125, 2098.72216796875, 177.1239776611328125, 3.397961139678955078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Hexed Craghopper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+95, 127157, 1643, 8721, 9224, '0', 0, 0, 0, 0, 374.5694580078125, 2356.882080078125, 124.5085372924804687, 5.040409564971923828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Marcus Howlingdale (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@CGUID+96, 127015, 1643, 8721, 9224, '0', 0, 0, 0, 0, 232.4756927490234375, 2210.104248046875, 84.0278778076171875, 3.522664785385131835, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568); -- Thaddeus "Gramps" Rifthold (Area: North Pass Caverns - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+96;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '257545'), -- Tamed Boar - 257545 - Cosmetic - Boar Eating
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 438, 0, 0, 0, 0, ''), -- Bonegnasher Skullcrusher
(@CGUID+19, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Vale Falcon
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 638, 0, 0, 0, 0, ''), -- Bonegnasher Skullcrusher
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 638, 0, 0, 0, 0, ''), -- Bonegnasher Skullcrusher
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '257545'), -- Tamed Boar - 257545 - Cosmetic - Boar Eating
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '257545'), -- Tamed Boar - 257545 - Cosmetic - Boar Eating
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '257545'), -- Tamed Boar - 257545 - Cosmetic - Boar Eating
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 438, 0, 0, 0, 0, ''), -- Bonegnasher Skullcrusher
(@CGUID+52, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Vale Falcon
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 638, 0, 0, 0, 0, ''), -- Bonegnasher Skullcrusher
(@CGUID+65, 0, 0, 0, 0, 0, 1, 0, 638, 0, 0, 0, 0, ''), -- Bonegnasher Earthcaller
(@CGUID+66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '257545'), -- Tamed Boar - 257545 - Cosmetic - Boar Eating
(@CGUID+70, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Vale Falcon
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '257545'), -- Tamed Boar - 257545 - Cosmetic - Boar Eating
(@CGUID+72, 0, 0, 0, 0, 0, 1, 0, 638, 0, 0, 0, 0, ''), -- Bonegnasher Skullcrusher
(@CGUID+75, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '257545'), -- Tamed Boar - 257545 - Cosmetic - Boar Eating
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '257545'), -- Tamed Boar - 257545 - Cosmetic - Boar Eating
(@CGUID+80, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '257545'), -- Tamed Boar - 257545 - Cosmetic - Boar Eating
(@CGUID+96, 0, 0, 0, 0, 0, 1, 0, 0, 1260, 0, 0, 3, ''); -- Thaddeus "Gramps" Rifthold

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+15;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 297136, 1643, 8721, 9224, '0', 0, 0, 409.72772216796875, 2413.6357421875, 120.524810791015625, 5.262166023254394531, -0.0285649299621582, -0.05100631713867187, -0.48778629302978515, 0.871003448963165283, 120, 255, 1, 60568), -- Campfire (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+1, 296271, 1643, 8721, 9224, '0', 0, 0, 364.623504638671875, 2472.365966796875, 120.931182861328125, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, 60568), -- Campfire (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+2, 297136, 1643, 8721, 9224, '0', 0, 0, 374.257904052734375, 2230.288818359375, 104.7861251831054687, 1.788960695266723632, 0.04559183120727539, -0.0365915298461914, 0.778550148010253906, 0.624853670597076416, 120, 255, 1, 60568), -- Campfire (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+3, 277595, 1643, 8721, 9224, '0', 0, 0, 412.697906494140625, 2263.73095703125, 105.9218063354492187, 4.700621604919433593, 0, 0, -0.71125507354736328, 0.702934026718139648, 120, 255, 1, 60568), -- Trogg Junkpile 1 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+4, 277596, 1643, 8721, 9224, '0', 0, 0, 410.7257080078125, 2260.501708984375, 105.9556198120117187, 1.856410503387451171, 0, 0, 0.800545692443847656, 0.599271714687347412, 120, 255, 1, 60568), -- Trogg Junkpile 2 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+5, 277596, 1643, 8721, 9224, '0', 0, 0, 373.649322509765625, 2230.63720703125, 104.8480606079101562, 0, 0, 0, 0, 1, 120, 255, 1, 60568), -- Trogg Junkpile 2 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+6, 277595, 1643, 8721, 9224, '0', 0, 0, 492.064239501953125, 2391.708251953125, 132.015960693359375, 2.104400634765625, 0, 0, 0.868515968322753906, 0.49566119909286499, 120, 255, 1, 60568), -- Trogg Junkpile 1 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+7, 277596, 1643, 8721, 9224, '0', 0, 0, 489.901031494140625, 2392.49658203125, 131.8674468994140625, 2.440077543258666992, 0, 0, 0.939112663269042968, 0.343609333038330078, 120, 255, 1, 60568), -- Trogg Junkpile 2 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+8, 277596, 1643, 8721, 9224, '0', 0, 0, 372.34722900390625, 2230.72216796875, 104.8694686889648437, 2.440077543258666992, 0, 0, 0.939112663269042968, 0.343609333038330078, 120, 255, 1, 60568), -- Trogg Junkpile 2 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+9, 277595, 1643, 8721, 9224, '0', 0, 0, 406.11285400390625, 2259.734375, 106.458251953125, 0.698421716690063476, 0, 0, 0.342156410217285156, 0.939643025398254394, 120, 255, 1, 60568), -- Trogg Junkpile 1 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+10, 277595, 1643, 8721, 9224, '0', 0, 0, 375.524322509765625, 2233.63720703125, 105.2740097045898437, 0, 0, 0, 0, 1, 120, 255, 1, 60568), -- Trogg Junkpile 1 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+11, 277596, 1643, 8721, 9224, '0', 0, 0, 412.2413330078125, 2260.732666015625, 105.8067092895507812, 4.837197780609130859, 0, 0, -0.66163253784179687, 0.749828219413757324, 120, 255, 1, 60568), -- Trogg Junkpile 2 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+12, 277595, 1643, 8721, 9224, '0', 0, 0, 490.40972900390625, 2391.354248046875, 131.8973541259765625, 4.700621604919433593, 0, 0, -0.71125507354736328, 0.702934026718139648, 120, 255, 1, 60568), -- Trogg Junkpile 1 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+13, 277596, 1643, 8721, 9224, '0', 0, 0, 367.4132080078125, 2235, 105.7074737548828125, 3.095042705535888671, 0, 0, 0.999729156494140625, 0.023272890597581863, 120, 255, 1, 60568), -- Trogg Junkpile 2 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+14, 276733, 1643, 8721, 9224, '0', 0, 0, 370.7257080078125, 2470.78125, 120.6363296508789062, 6.152286052703857421, 0, 0, -0.06540298461914062, 0.997858941555023193, 120, 255, 1, 60568), -- Trogg Campfire (Area: North Pass Caverns - Difficulty: 0) CreateObject1
(@OGUID+15, 277595, 1643, 8721, 9224, '0', 0, 0, 374.4757080078125, 2232.151123046875, 105.0270919799804687, 2.969487190246582031, 0, 0, 0.99629974365234375, 0.085946515202522277, 120, 255, 1, 60568); -- Trogg Junkpile 1 (Area: North Pass Caverns - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+15;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.48862215876579284, 0.872495472431182861, 0, 0), -- Campfire
(@OGUID+1, 0, 0, -0.7688416838645935, 0.639439225196838378, 0, 0), -- Campfire
(@OGUID+2, 0, 0, 0.77988433837890625, 0.625923633575439453, 0, 0); -- Campfire

-- Template
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=60568 WHERE `entry`=276259; -- "Relic of the Makers"
UPDATE `gameobject_template` SET `ContentTuningId`=492, `VerifiedBuild`=60568 WHERE `entry`=278295; -- Crypt Door
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=60568 WHERE `entry`=290611; -- Azerite Chunk

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (127129,127125,143929,127156,127522,127157,127822,127127,127699,127015,127092,128389) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127129 AND `DifficultyID`=0); -- 127129 (Grozgore) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127125 AND `DifficultyID`=0); -- 127125 (Cragg the Stoneshaker) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=143929 AND `DifficultyID`=0); -- 143929 (Hexed Craghopper) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60568 WHERE (`Entry`=127156 AND `DifficultyID`=0); -- 127156 (Nigel Rifthold) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60568 WHERE (`Entry`=127522 AND `DifficultyID`=0); -- 127522 (Roasting Spit) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127157 AND `DifficultyID`=0); -- 127157 (Marcus Howlingdale) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127822 AND `DifficultyID`=0); -- 127822 (Alpine Goat) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127127 AND `DifficultyID`=0); -- 127127 (Bonegnasher Earthcaller) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127699 AND `DifficultyID`=0); -- 127699 (Tamed Boar) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127015 AND `DifficultyID`=0); -- 127015 (Thaddeus "Gramps" Rifthold) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127092 AND `DifficultyID`=0); -- 127092 (Bonegnasher Skullcrusher) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60568 WHERE (`Entry`=128389 AND `DifficultyID`=0); -- 128389 (Vale Falcon) - CanSwim, Floating

-- Model
UPDATE `creature_model_info` SET `BoundingRadius`=0.964008212089538574, `CombatReach`=2.25, `VerifiedBuild`=60568 WHERE `DisplayID`=77268;
UPDATE `creature_model_info` SET `VerifiedBuild`=60568 WHERE `DisplayID` IN (40021, 71224, 70451, 70663, 70443, 62862, 62863, 81005, 22469, 78849, 88290, 77050, 79552, 11686, 40020, 77051, 40025, 160, 53282, 62722, 2543, 79281, 70448, 45494, 80962, 70722, 765, 81082, 70442, 70440, 79806, 21342, 79808, 80955, 79614, 70446, 80953, 80860, 2177, 8014);
UPDATE `creature_model_info` SET `BoundingRadius`=3.124989748001098632, `CombatReach`=2, `VerifiedBuild`=60568 WHERE `DisplayID`=52656;

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (48792 /*Menace to Society*/, 48793 /*The Adventurer's Society*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48792, 1, 0, 0, 0, 0, 0, 0, 0, 60568), -- Menace to Society
(48793, 1, 0, 0, 0, 0, 0, 0, 0, 60568); -- The Adventurer's Society

DELETE FROM `creature_queststarter` WHERE (`id`=127015 AND `quest` IN (48792,48793));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(127015, 48792, 60568), -- Menace to Society offered by Thaddeus "Gramps" Rifthold
(127015, 48793, 60568); -- The Adventurer's Society offered by Thaddeus "Gramps" Rifthold

-- Bonegnasher Skullcrusher smart ai
SET @ENTRY := 127092;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 85, 253518, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 253518 on self', '');

UPDATE `creature` SET `StringID` = 'TroggSleep' WHERE `guid` IN (@CGUID+8,@CGUID+10,@CGUID+13,@CGUID+48,@CGUID+50,@CGUID+53,@CGUID+61,@CGUID+74);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 127092 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 127092, 0, 0, 58, 1, 0, 0, 0, 'TroggSleep', 0, 'Object has StringID TroggSleep');

-- Path for Vale Falcon
SET @MOVERGUID := @CGUID+25;
SET @ENTRY := 128389;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6718, 'Vale Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 296.15604, 2367.6348, 117.1647, NULL, 0),
(@PATH, 1, 311.73578, 2366.7092, 117.1647, NULL, 0),
(@PATH, 2, 325.7754, 2359.8918, 117.1647, NULL, 0),
(@PATH, 3, 336.1374, 2348.2207, 117.1647, NULL, 0),
(@PATH, 4, 341.24432, 2333.4727, 117.1647, NULL, 0),
(@PATH, 5, 340.31866, 2317.8928, 117.1647, NULL, 0),
(@PATH, 6, 333.50137, 2303.8533, 117.1647, NULL, 0),
(@PATH, 7, 321.8303, 2293.4912, 117.1647, NULL, 0),
(@PATH, 8, 307.08224, 2288.3845, 117.1647, NULL, 0),
(@PATH, 9, 291.5025, 2289.31, 117.1647, NULL, 0),
(@PATH, 10, 277.4629, 2296.1274, 117.1647, NULL, 0),
(@PATH, 11, 267.1009, 2307.7983, 117.1647, NULL, 0),
(@PATH, 12, 261.99396, 2322.5464, 117.1647, NULL, 0),
(@PATH, 13, 262.91962, 2338.1262, 117.1647, NULL, 0),
(@PATH, 14, 269.7369, 2352.1658, 117.1647, NULL, 0),
(@PATH, 15, 281.408, 2362.5278, 117.1647, NULL, 0),
(@PATH, 16, 296.15604, 2367.6348, 117.1647, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Vale Falcon
SET @MOVERGUID := @CGUID+27;
SET @ENTRY := 128389;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6718, 'Vale Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 349.77182, 2419.297, 152.84402, NULL, 0),
(@PATH, 1, 360.2257, 2407.7083, 152.84402, NULL, 0),
(@PATH, 2, 365.44894, 2393.001, 152.84402, NULL, 0),
(@PATH, 3, 364.64636, 2377.4146, 152.84402, NULL, 0),
(@PATH, 4, 357.9402, 2363.3215, 152.84402, NULL, 0),
(@PATH, 5, 346.3513, 2352.8677, 152.84402, NULL, 0),
(@PATH, 6, 331.64404, 2347.6443, 152.84402, NULL, 0),
(@PATH, 7, 316.05746, 2348.447, 152.84402, NULL, 0),
(@PATH, 8, 301.96448, 2355.153, 152.84402, NULL, 0),
(@PATH, 9, 291.51062, 2366.742, 152.84402, NULL, 0),
(@PATH, 10, 286.28735, 2381.4492, 152.84402, NULL, 0),
(@PATH, 11, 287.08994, 2397.036, 152.84402, NULL, 0),
(@PATH, 12, 293.79614, 2411.129, 152.84402, NULL, 0),
(@PATH, 13, 305.385, 2421.5828, 152.84402, NULL, 0),
(@PATH, 14, 320.09225, 2426.806, 152.84402, NULL, 0),
(@PATH, 15, 335.67886, 2426.0034, 152.84402, NULL, 0),
(@PATH, 16, 349.77182, 2419.297, 152.84402, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Vale Falcon
SET @MOVERGUID := @CGUID+83;
SET @ENTRY := 128389;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8687, 'Vale Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 496.7187, 2398.0989, 168.61278, NULL, 0),
(@PATH, 1, 482.77902, 2384.9915, 168.61278, NULL, 0),
(@PATH, 2, 463.6539, 2385.58, 168.61278, NULL, 0),
(@PATH, 3, 450.54657, 2399.5198, 168.61278, NULL, 0),
(@PATH, 4, 451.13516, 2418.6448, 168.61278, NULL, 0),
(@PATH, 5, 465.07486, 2431.7522, 168.61278, NULL, 0),
(@PATH, 6, 484.19995, 2431.1636, 168.61278, NULL, 0),
(@PATH, 7, 497.30728, 2417.2239, 168.61278, NULL, 0),
(@PATH, 8, 496.7187, 2398.0989, 168.61278, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Bonegnasher Skullcrusher
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+57;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+57, @CGUID+57, 0, 0, 515, 0, 0),
(@CGUID+57, @CGUID+58, 3, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+57;
SET @ENTRY := 127092;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Bonegnasher Skullcrusher - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 478.3316, 2353.0244, 121.01678, NULL, 0),
(@PATH, 1, 483.0521, 2358.3489, 122.35915, NULL, 0),
(@PATH, 2, 486.2066, 2364.816, 123.48225, NULL, 0),
(@PATH, 3, 485.39758, 2374.0173, 124.74022, NULL, 0),
(@PATH, 4, 482.5955, 2382.4045, 125.88334, NULL, 0),
(@PATH, 5, 477.72397, 2388.184, 127.13243, NULL, 0),
(@PATH, 6, 472.62326, 2391.3542, 128.12042, NULL, 0),
(@PATH, 7, 470.95312, 2387.552, 126.83695, NULL, 0),
(@PATH, 8, 475.7587, 2382.9514, 125.8328, NULL, 0),
(@PATH, 9, 479.4566, 2377.3281, 125.0053, NULL, 0),
(@PATH, 10, 480.56772, 2369.967, 123.64585, NULL, 0),
(@PATH, 11, 476.4045, 2362.6025, 121.79333, NULL, 0),
(@PATH, 12, 472.85764, 2359.198, 121.10754, NULL, 0),
(@PATH, 13, 467.40973, 2352.2048, 120.5091, NULL, 0),
(@PATH, 14, 466.48785, 2348.8682, 120.58156, NULL, 0),
(@PATH, 15, 465.02084, 2341.6667, 120.70326, NULL, 0),
(@PATH, 16, 465.79166, 2337.2014, 120.34497, NULL, 0),
(@PATH, 17, 470.65625, 2335.0938, 120.28849, NULL, 0),
(@PATH, 18, 473.02777, 2337.4758, 121.24229, NULL, 0),
(@PATH, 19, 474.11978, 2345.111, 121.86507, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Bonegnasher Skullcrusher
SET @MOVERGUID := @CGUID+43;
SET @ENTRY := 127092;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Bonegnasher Skullcrusher - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 444.12674, 2374.4844, 121.1406, NULL, 0),
(@PATH, 1, 441.55728, 2371.1042, 121.26386, NULL, 0),
(@PATH, 2, 436.92188, 2368.2395, 121.096, NULL, 0),
(@PATH, 3, 433.45486, 2368.2153, 120.97742, NULL, 0),
(@PATH, 4, 429.01215, 2370.2656, 120.80108, NULL, 0),
(@PATH, 5, 425.0087, 2373.1597, 120.93007, NULL, 0),
(@PATH, 6, 423.26562, 2377.908, 120.85814, NULL, 0),
(@PATH, 7, 426.9045, 2382.9739, 120.85402, NULL, 0),
(@PATH, 8, 429.08508, 2384.962, 121.05303, NULL, 0),
(@PATH, 9, 425.6979, 2387.111, 121.34644, NULL, 0),
(@PATH, 10, 421.01736, 2384.0383, 121.2439, NULL, 0),
(@PATH, 11, 418.55728, 2379.434, 121.18087, NULL, 0),
(@PATH, 12, 420.26215, 2373.8767, 121.33843, NULL, 0),
(@PATH, 13, 423.70312, 2369.769, 121.43743, NULL, 0),
(@PATH, 14, 429.06772, 2367.8386, 121.15487, NULL, 0),
(@PATH, 15, 433.21182, 2366.4949, 121.30807, NULL, 0),
(@PATH, 16, 438.53473, 2367.7795, 121.30807, NULL, 0),
(@PATH, 17, 442.28995, 2370.4565, 121.33161, NULL, 0),
(@PATH, 18, 445.69098, 2373.9202, 121.32955, NULL, 4031);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Bonegnasher Earthcaller
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+46;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+46, @CGUID+46, 0, 0, 515, 0, 0),
(@CGUID+46, @CGUID+45, 3, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+46;
SET @ENTRY := 127127;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Bonegnasher Earthcaller - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 426.62326, 2312.2136, 120.6773, NULL, 0),
(@PATH, 1, 432.39236, 2312.6807, 120.61087, NULL, 0),
(@PATH, 2, 439.39758, 2313.606, 120.69428, NULL, 0),
(@PATH, 3, 446.17535, 2315.507, 120.77486, NULL, 0),
(@PATH, 4, 450.217, 2318.2048, 120.8737, NULL, 0),
(@PATH, 5, 448.5382, 2324.2031, 120.44359, NULL, 0),
(@PATH, 6, 442.86978, 2329.2258, 120.97667, NULL, 0),
(@PATH, 7, 438.54166, 2329.434, 122.02148, NULL, 0),
(@PATH, 8, 428.4462, 2329.415, 120.23177, NULL, 0),
(@PATH, 9, 426.18402, 2325.1199, 120.44279, NULL, 0),
(@PATH, 10, 424.99307, 2319.0938, 120.3713, NULL, 0),
(@PATH, 11, 422.31424, 2317.2744, 120.55219, NULL, 9572);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
