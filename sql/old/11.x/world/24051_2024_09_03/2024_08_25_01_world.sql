SET @CGUID := 10000000;
SET @OGUID := 10000000;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+824;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2050.772216796875, -923.74566650390625, 14.46361732482910156, 4.594936847686767578, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+1, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2045.2327880859375, -781.8082275390625, 1.642765522003173828, 1.533212542533874511, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+2, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2052.1015625, -846.638671875, 2.432475805282592773, 3.929061412811279296, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+3, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2075.4833984375, -900, 13.19590377807617187, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+4, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2092.61181640625, -821.6614990234375, 0.402278780937194824, 0.715615451335906982, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+5, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2094.117431640625, -841.60565185546875, 2.04202437400817871, 3.38892674446105957, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2079.36669921875, -907.588134765625, 16.60424613952636718, 5.177404403686523437, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2082.271484375, -890.875244140625, 11.70680904388427734, 4.814197063446044921, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2087.300048828125, -902.594482421875, 15.06765651702880859, 0.15845547616481781, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2083.075439453125, -905.9541015625, 18.20832252502441406, 2.983257770538330078, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+10, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2054.125, -827.1319580078125, -0.0948515310883522, 0.994167625904083251, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+11, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2112.442138671875, -840.68450927734375, 2.708883047103881835, 6.183473587036132812, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+12, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2008.7193603515625, -883.8282470703125, 11.74861907958984375, 2.072869777679443359, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+13, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1993.505126953125, -853.716552734375, 34.75331497192382812, 3.83356785774230957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2040.471435546875, -821.178466796875, -0.43364840745925903, 1.315850257873535156, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+15, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1996.63623046875, -823.11517333984375, -0.12654480338096618, 5.992280960083007812, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+16, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2020.482666015625, -876.3350830078125, 9.809467315673828125, 2.805332422256469726, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2026.8377685546875, -823.42266845703125, 0.381131559610366821, 3.425537347793579101, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2091.210205078125, -825.64019775390625, 0.820986628532409667, 6.108582496643066406, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+19, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2044.5074462890625, -888.97698974609375, 11.88496685028076171, 0.675608694553375244, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1981.34375, -840.92974853515625, 4.777576446533203125, 3.715511798858642578, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2078.646484375, -902.083984375, 14.18248367309570312, 5.290237903594970703, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2073.171875, -949.73321533203125, 20.00998687744140625, 5.63072061538696289, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2021.84033203125, -933.388916015625, 21.12888336181640625, 1.136422991752624511, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+24, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2085.86181640625, -946.76641845703125, 18.39767265319824218, 0.519357085227966308, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2123.35595703125, -920.478759765625, 12.99973583221435546, 2.964323759078979492, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2145.3837890625, -893.18359375, 9.608137130737304687, 4.748506546020507812, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+27, 223799, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2049.4716796875, -1035.4677734375, 15.1513986587524414, 5.773242473602294921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Shard of Dalaran (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+28, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2104.763916015625, -765.68121337890625, -0.65353614091873168, 2.735127687454223632, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+29, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2045.9959716796875, -952.04071044921875, 22.7464141845703125, 2.503258228302001953, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+30, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2001.338134765625, -952.99371337890625, 53.43711090087890625, 1.662261724472045898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+31, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1956.185791015625, -833.87677001953125, 44.9358978271484375, 5.137273788452148437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+32, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1980.2603759765625, -909.2274169921875, 17.20646286010742187, 1.234221816062927246, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+33, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1964.4793701171875, -877.152587890625, 16.79706573486328125, 6.180964469909667968, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+34, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2102.720458984375, -909.53472900390625, 26.4525604248046875, 5.229258537292480468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+35, 223799, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2119.75048828125, -932.514404296875, 13.60051441192626953, 0.170537143945693969, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Shard of Dalaran (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2079.893798828125, -781.21466064453125, -1.1992199420928955, 0.483289510011672973, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+37, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2145.79345703125, -883.28643798828125, 7.510835647583007812, 3.564621925354003906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+38, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1966.8541259765625, -806.14410400390625, 31.05585479736328125, 5.707386493682861328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+39, 222036, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2074.646484375, -762.71044921875, -1.67314827442169189, 3.986422061920166015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Sea Slug (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+40, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2007.68896484375, -941.90093994140625, 16.72495269775390625, 0.952072501182556152, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2001.4007568359375, -785.83734130859375, -1.60619688034057617, 4.2630462646484375, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+42, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2120.8330078125, -904.166015625, 11.55168342590332031, 4.314944744110107421, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2144.0234375, -834.727783203125, -0.24518673121929168, 0.852351784706115722, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+44, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1992.080810546875, -910.78485107421875, 16.26983833312988281, 2.613259077072143554, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+45, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2153.8466796875, -896.06353759765625, 32.678802490234375, 6.150299549102783203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+46, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1981.1533203125, -814.3671875, 6.72681283950805664, 1.797333002090454101, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 226909, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2187.1494140625, -801.8350830078125, 10.18007755279541015, 4.4111175537109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Frostfire Elemental (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (Auras: 456495 - Elemental (DNT))
(@CGUID+48, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2131.10791015625, -769.987548828125, 0.917581081390380859, 0.46364760398864746, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+49, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2173.423095703125, -843.36431884765625, -0.03073833137750625, 3.934922695159912109, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+50, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2184.65966796875, -844.93231201171875, 0.019976712763309478, 5.890033245086669921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+51, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2175.137451171875, -890.448486328125, 7.627107620239257812, 1.992629408836364746, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+52, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2175.13037109375, -892.7576904296875, 8.025033950805664062, 3.306888580322265625, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+53, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2192.645751953125, -811.54534912109375, 0.680806338787078857, 2.919901609420776367, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+54, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2201.949951171875, -843.09320068359375, -0.00803565979003906, 2.619075775146484375, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+55, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2175, -908.333984375, 8.776072502136230468, 5.250308990478515625, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+56, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2232.3525390625, -858.4774169921875, -0.46270719170570373, 3.011935234069824218, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+57, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2215.5673828125, -886.5390625, -0.062434583902359, 0.952735960483551025, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+58, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2221.980224609375, -894.8192138671875, 0.241596072912216186, 4.134949684143066406, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+59, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2177.927490234375, -935.46087646484375, 8.080964088439941406, 2.481055736541748046, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+60, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2133.953125, -952.17364501953125, 12.51863479614257812, 0.606153488159179687, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+61, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2132.84521484375, -958.688720703125, 10.15993309020996093, 4.951905250549316406, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+62, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2207.06591796875, -937.89202880859375, 5.100639820098876953, 4.475933074951171875, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+63, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2144.80224609375, -955.83135986328125, 6.43251800537109375, 0.838561594486236572, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+64, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2145.738525390625, -962.3232421875, 2.521578311920166015, 5.610579490661621093, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2185.67236328125, -953.75335693359375, 3.197290420532226562, 5.517076492309570312, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+66, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2225.569091796875, -955.78070068359375, -0.65344393253326416, 0.845533192157745361, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+67, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2117.1875, -991.666015625, 9.604529380798339843, 1.570796370506286621, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+68, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2098.395751953125, -1040.3541259765625, 12.92688179016113281, 4.988758087158203125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+69, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2208.734375, -972.1632080078125, 0.064428560435771942, 3.166205644607543945, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+70, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2092.478271484375, -1004.64190673828125, 22.35416603088378906, 0.192830920219421386, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+71, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2197.924072265625, -998.958984375, 0.728902876377105712, 3.141592741012573242, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+72, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2146.947998046875, -1016.1246337890625, 9.972634315490722656, 3.654899358749389648, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+73, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2095.345458984375, -1002.431396484375, 21.05091094970703125, 2.151456594467163085, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+74, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2141.6669921875, -1007.8125, 9.521426200866699218, 6.035524845123291015, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+75, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2148.9580078125, -1011.978515625, 9.889227867126464843, 6.233227252960205078, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+76, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2114.262939453125, -1006.73388671875, 13.06334114074707031, 2.574547767639160156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+77, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2187.6015625, -997.842529296875, 1.716487050056457519, 0.595782160758972167, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+78, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2087.629150390625, -1001.55328369140625, 20.6703338623046875, 0.995887935161590576, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+79, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2095.603759765625, -1053.9158935546875, 41.72589874267578125, 0.343739926815032958, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+80, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2047.9053955078125, -975.26055908203125, 26.17286872863769531, 1.580561637878417968, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+81, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2037.2781982421875, -977.03662109375, 21.9867401123046875, 2.353289127349853515, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+82, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2080.78955078125, -1025, 14.79166603088378906, 3.141592741012573242, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+83, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2074.22509765625, -1019.98333740234375, 16.57762527465820312, 6.163621425628662109, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+84, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2156.762939453125, -1045.5572509765625, 1.467025637626647949, 3.018932342529296875, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+85, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2187.5, -1036.458984375, 0.611044526100158691, 1.789253473281860351, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+86, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2217.76416015625, -1012.749755859375, 3.173408269882202148, 3.264198064804077148, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+87, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2253.623779296875, -920.66357421875, 0.274819254875183105, 5.411516189575195312, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+88, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2257.854736328125, -955.7130126953125, 0.177789121866226196, 6.048627853393554687, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+89, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2251.06103515625, -983.142822265625, -1.3929070234298706, 1.64451909065246582, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+90, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2254.45654296875, -957.5069580078125, 0.038988292217254638, 2.516204595565795898, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+91, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2251.969482421875, -917.82244873046875, 0.114991635084152221, 3.842587232589721679, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+92, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2179.868408203125, -1050.858154296875, 1.198714375495910644, 1.316352725028991699, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+93, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2009.8472900390625, -1027.921875, 19.12415122985839843, 3.564621925354003906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+94, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2030.397705078125, -997.14947509765625, 16.8810272216796875, 5.469460487365722656, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+95, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2032.353515625, -1011.36328125, 17.78091239929199218, 4.893900871276855468, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+96, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2036.4561767578125, -1008.1378173828125, 18.39058494567871093, 4.064408302307128906, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+97, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2125.40673828125, -1060.3526611328125, 1.119220137596130371, 5.153323173522949218, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+98, 222747, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2178.841796875, -1061.7808837890625, 1.410229682922363281, 3.569413661956787109, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mossy Snail (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+99, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2216.6669921875, -1038.541015625, 0.142903491854667663, 1.761847138404846191, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+100, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2199.079833984375, -1052.3646240234375, 0.283213734626770019, 4.107441902160644531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+101, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2026.123291015625, -1078.34033203125, 29.82708740234375, 0.272715151309967041, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+102, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2158.02294921875, -1079.10888671875, 1.543421387672424316, 5.917622089385986328, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+103, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2045.0113525390625, -1054.8677978515625, 15.1960916519165039, 3.81882023811340332, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+104, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2007.3472900390625, -1064.3541259765625, 44.7093658447265625, 1.942358970642089843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+105, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2085.9228515625, -1091.296142578125, 4.012917518615722656, 0.151681795716285705, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+106, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2244.623779296875, -1010.05340576171875, -0.04209190607070922, 4.20244598388671875, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+107, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2116.385009765625, -1116.565185546875, 4.104258537292480468, 3.719103574752807617, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+108, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2259.22216796875, -997.6829833984375, 0.751206755638122558, 5.180780410766601562, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+109, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2264.957763671875, -1002.69775390625, 0.100394189357757568, 5.618203163146972656, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+110, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2150.475830078125, -1117.75634765625, 1.190748929977416992, 2.026587247848510742, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+111, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2243.552734375, -1080.940673828125, -6.73351621627807617, 4.538212299346923828, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+112, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2268.71142578125, -1033.87939453125, -7.68651103973388671, 0.053713817149400711, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+113, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2271.92529296875, -947.30035400390625, -0.00345543771982192, 0.379744917154312133, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+114, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2193.06103515625, -1123.7430419921875, 0.515245437622070312, 3.831944704055786132, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+115, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2146.41796875, -1143.81640625, 8.894498825073242187, 0.631382882595062255, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+116, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2073.273681640625, -1136.37451171875, 0.48957759141921997, 2.564665794372558593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+117, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2037.8743896484375, -1112.179443359375, 14.56194400787353515, 4.081006050109863281, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+118, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2019.2391357421875, -1040.2325439453125, 18.30167388916015625, 0.508435308933258056, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+119, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2129.114501953125, -1157.8284912109375, 2.535274982452392578, 1.128129839897155761, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+120, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2016.9052734375, -1014.55963134765625, 18.41480827331542968, 2.705990791320800781, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+121, 229087, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2058.894287109375, -1147.1934814453125, -1.13573348522186279, 1.064361333847045898, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana-Flecked Crawler (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+122, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1973.6492919921875, -1055.40625, 35.8623504638671875, 1.369404911994934082, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+123, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1995.625, -1042.69921875, 20.588714599609375, 2.631172657012939453, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+124, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1991.6669921875, -1051.041015625, 22.10744094848632812, 2.70419478416442871, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+125, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1953.0711669921875, -982.76043701171875, 27.75693321228027343, 1.450084328651428222, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+126, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1987.4169921875, -1001.041015625, 21.15607833862304687, 3.110352754592895507, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+127, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1991.5799560546875, -991.78375244140625, 17.9709320068359375, 3.913498401641845703, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+128, 223797, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1989.0625, -998.4375, 20.35074996948242187, 1.24379730224609375, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Lingering Spark (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+129, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1989.5830078125, -985.416015625, 18.11905670166015625, 3.141592741012573242, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+130, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1990.809814453125, -984.93414306640625, 17.68517112731933593, 2.59225630760192871, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+131, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1974.292236328125, -978.23822021484375, 21.91910743713378906, 2.222070693969726562, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+132, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1905.6285400390625, -945.4132080078125, 30.35087776184082031, 2.329984664916992187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+133, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1937.6693115234375, -961.50836181640625, 27.2273101806640625, 3.11984109878540039, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+134, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1939.8192138671875, -1037.9775390625, 28.31289863586425781, 1.925909042358398437, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+135, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1926.4791259765625, -1001.776611328125, 30.92720603942871093, 4.384734153747558593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+136, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1944.634033203125, -892.071533203125, 26.00726890563964843, 1.114964008331298828, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+137, 217984, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1929.4461669921875, -921.1024169921875, 24.90635299682617187, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Rumble Stalker [DNT] (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+138, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1889.0728759765625, -893.90802001953125, 45.2599639892578125, 0.301871448755264282, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+139, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1892.076416015625, -862.045166015625, 53.95886993408203125, 5.168189048767089843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+140, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1913.66845703125, -840.0555419921875, 81.275726318359375, 5.598229885101318359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+141, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1916.954833984375, -904.4600830078125, 29.09413528442382812, 1.287135004997253417, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+142, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1911.0906982421875, -868.26220703125, 36.32072830200195312, 4.102596759796142578, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+143, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1893.4876708984375, -939.50531005859375, 32.60367202758789062, 0.869055509567260742, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+144, 223798, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1925.6260986328125, -1009.17724609375, 31.32661819458007812, 0.975953161716461181, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mana Fragment (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+145, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1920.0675048828125, -993.9791259765625, 29.33843612670898437, 5.153323173522949218, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+146, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1865.349609375, -1024.72509765625, 56.50065231323242187, 0.191756337881088256, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+147, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1892.5955810546875, -1019.52789306640625, 31.91640663146972656, 2.862709522247314453, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+148, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1939.78662109375, -1086.7403564453125, 23.34142303466796875, 4.263492584228515625, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+149, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1974.5174560546875, -1106.302978515625, 19.19689178466796875, 2.589648008346557617, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+150, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1899.8790283203125, -1091.516845703125, 24.95331001281738281, 0.374697893857955932, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+151, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 2021.201904296875, -1151.2298583984375, 0.256580501794815063, 5.197319984436035156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+152, 222747, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1981.3448486328125, -1163.7313232421875, 1.991530895233154296, 1.78193819522857666, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mossy Snail (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+153, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1958.118896484375, -1157.9088134765625, 2.790798902511596679, 5.030614376068115234, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+154, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1990.60595703125, -1177.4774169921875, 0.481464207172393798, 4.549715042114257812, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+155, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1877.350830078125, -1066.2215576171875, 28.4507293701171875, 5.952782630920410156, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+156, 223098, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1876.9595947265625, -976.6007080078125, 33.93685150146484375, 3.245785474777221679, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cobalt Ramolith (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+157, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1858.7493896484375, -1026.970947265625, 33.20452117919921875, 5.507819652557373046, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+158, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1824.626708984375, -1077.54345703125, 54.68163299560546875, 0.445936203002929687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+159, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1827.126708984375, -1086.015625, 67.6229248046875, 0.12365376204252243, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+160, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1825.2725830078125, -1083.4149169921875, 67.81295013427734375, 1.306061625480651855, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+161, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1860.4962158203125, -1106.7603759765625, 26.44817924499511718, 2.980486392974853515, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+162, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1846.8153076171875, -1004.9561767578125, 35.02587509155273437, 2.535834550857543945, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+163, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1851.6527099609375, -962.798095703125, 37.77771377563476562, 6.042305946350097656, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+164, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1825.005126953125, -1052.8431396484375, 40.12571334838867187, 5.987988471984863281, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+165, 223852, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1855.4149169921875, -952.7430419921875, 35.30150985717773437, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Babbling Book (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (Auras: 449779 - (DNT) Elemental Aura)
(@CGUID+166, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1810.416015625, -979.166015625, 39.2228546142578125, 3.992222547531127929, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+167, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1888.5546875, -1153.505859375, 3.647252559661865234, 0.244111508131027221, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+168, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1780.8408203125, -1020.417724609375, 39.77384185791015625, 2.386571884155273437, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+169, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1822.9586181640625, -922.8704833984375, 49.4828338623046875, 2.337878942489624023, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+170, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1743.876708984375, -945.529541015625, 60.76974868774414062, 0.324044376611709594, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+171, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1781.747314453125, -948.13482666015625, 50.9229736328125, 4.805690765380859375, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+172, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1741.8975830078125, -939.70489501953125, 75.7264251708984375, 5.665221214294433593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+173, 220067, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1749.51953125, -983.62646484375, 47.50637054443359375, 6.210834026336669921, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salmoncrab (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+174, 215093, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1935.942138671875, -807.51025390625, 53.1054840087890625, 4.648113250732421875, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+175, 229092, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1729.55908203125, -979.58856201171875, 49.580718994140625, 3.853256464004516601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+176, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1815.0572509765625, -845.17535400390625, 94.45771026611328125, 5.003790855407714843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+177, 229088, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1820.5625, -842.66839599609375, 94.3284759521484375, 6.185117721557617187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Scavenging Falcon (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+178, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1756.0074462890625, -912.763916015625, 59.44858932495117187, 0.304906845092773437, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+179, 229092, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1729.486083984375, -988.94793701171875, 47.86046218872070312, 5.874967098236083984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+180, 226885, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1840.6007080078125, -878.32464599609375, 56.49713134765625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Bunny Prime - Empower (DNT) (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+181, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1852.800048828125, -875.66339111328125, 48.42322540283203125, 3.584829568862915039, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+182, 220038, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1830.8052978515625, -860.46923828125, 48.73625564575195312, 5.164320945739746093, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shattered Crystal (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+183, 223093, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1679.0260009765625, -933.1585693359375, 52.52364349365234375, 1.214191675186157226, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Granite Ramolith (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+184, 215093, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1706.295166015625, -843.24761962890625, 64.664306640625, 3.866016626358032226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+185, 215093, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1891.3360595703125, -825.06719970703125, 67.37795257568359375, 0.206590697169303894, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+186, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1670.6822509765625, -1008.99298095703125, 39.10020065307617187, 3.853256464004516601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+187, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1719.263916015625, -981.5225830078125, 49.755767822265625, 0.463711738586425781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+188, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1729.486083984375, -988.94793701171875, 47.86046218872070312, 5.874967098236083984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+189, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1691.2222900390625, -1014.45489501953125, 42.9221649169921875, 3.589206933975219726, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+190, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1664.2291259765625, -1011.3524169921875, 36.30728912353515625, 6.183710098266601562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+191, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1680.8154296875, -1038.1658935546875, 37.29136276245117187, 5.289574623107910156, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+192, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1656.4521484375, -887.70867919921875, 60.02339553833007812, 5.969319343566894531, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+193, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1574.8382568359375, -1008.443359375, 40.85209274291992187, 1.617728590965270996, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+194, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1662.8529052734375, -933.612060546875, 51.14692306518554687, 3.247287750244140625, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+195, 222774, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1715.231201171875, -930.36590576171875, 56.6651153564453125, 0.657958865165710449, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+196, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1613.397705078125, -1082.0673828125, 27.63681411743164062, 3.10641646385192871, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+197, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1573.708984375, -1018.6485595703125, 41.69093704223632812, 6.098683357238769531, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+198, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1736.4364013671875, -1017.3604736328125, 39.31066513061523437, 5.17254495620727539, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+199, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1729.55908203125, -979.58856201171875, 49.580718994140625, 3.853256464004516601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+200, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1735.529541015625, -1020.03472900390625, 38.38643646240234375, 5.187097549438476562, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+201, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1703.704833984375, -965.67364501953125, 50.96085357666015625, 2.960320949554443359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+202, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1608.41455078125, -926.09356689453125, 48.26758193969726562, 0.605677127838134765, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+203, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1683.4461669921875, -941.3055419921875, 52.17428970336914062, 3.853256464004516601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+204, 222780, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1585.8355712890625, -1095.5316162109375, 27.74051856994628906, 1.921593189239501953, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+205, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1581.124267578125, -1093.4884033203125, 30.43331527709960937, 6.075028419494628906, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+206, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1527.224365234375, -1012.16156005859375, 41.12314987182617187, 2.175599575042724609, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+207, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1534.403076171875, -1045.6392822265625, 38.45232009887695312, 1.607888698577880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+208, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1515.3123779296875, -1097.226806640625, 40.93538665771484375, 4.954051017761230468, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+209, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1516.2684326171875, -1120.9033203125, 36.35802841186523437, 4.55847787857055664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+210, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1507.3087158203125, -1118.434814453125, 38.88759231567382812, 2.970795154571533203, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+211, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1568.2684326171875, -911.52142333984375, 48.18936920166015625, 3.713940858840942382, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+212, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1487.336181640625, -964.55389404296875, 41.4413299560546875, 2.119389057159423828, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+213, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1514.6842041015625, -914.66656494140625, 44.0644989013671875, 4.700671195983886718, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+214, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1616.911376953125, -853.879150390625, 50.59568023681640625, 3.635798454284667968, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+215, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1556.7484130859375, -854.69281005859375, 51.54993820190429687, 2.996960401535034179, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+216, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1621.763427734375, -846.35919189453125, 50.9291229248046875, 2.535480022430419921, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+217, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1587.9693603515625, -827.88275146484375, 51.24831771850585937, 4.399553298950195312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+218, 229092, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1744.326416015625, -1063.4913330078125, 39.1319427490234375, 5.41412210464477539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosswool Grazer (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+219, 223057, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1768.3486328125, -1175.380126953125, 3.659795999526977539, 0.415973305702209472, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+220, 223057, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1749.5098876953125, -1149.67529296875, 5.511289119720458984, 4.922342777252197265, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+221, 223057, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1718.785888671875, -1171.8585205078125, 4.003015995025634765, 5.555084705352783203, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+222, 223057, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1823.0533447265625, -1173.13671875, 3.317949771881103515, 5.921900749206542968, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+223, 218118, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1689.0086669921875, -1181.59375, 3.85147261619567871, 3.841231107711791992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+224, 222747, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1872.525146484375, -1167.0115966796875, 1.414920330047607421, 2.433601856231689453, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mossy Snail (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+225, 223057, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1782.327880859375, -1167.6236572265625, 5.123044013977050781, 3.172952651977539062, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+226, 223057, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1737.990234375, -1200.628662109375, 1.705556392669677734, 6.034275054931640625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+227, 218119, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1670.4149169921875, -1183.357666015625, 3.607077360153198242, 4.47727823257446289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+228, 223057, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1693.3446044921875, -1211.0709228515625, 1.363826632499694824, 3.094706296920776367, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+229, 218118, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1672.1441650390625, -1185.3055419921875, 3.496677875518798828, 3.51203322410583496, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+230, 218119, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1670.189208984375, -1170.592041015625, 5.002753257751464843, 2.036690711975097656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+231, 223057, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1654.7742919921875, -1163.09033203125, 5.315018177032470703, 4.296404361724853515, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+232, 218118, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1681.4478759765625, -1220.27783203125, 2.707026481628417968, 2.464673519134521484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+233, 218118, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1664.12158203125, -1228.8350830078125, -0.03197515755891799, 4.991920948028564453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: Tranquil Strand - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+234, 223057, 2552, 14717, 14774, '0', 0, 0, 0, 0, 1649.2410888671875, -1212.75048828125, 1.987231135368347167, 5.642357826232910156, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@CGUID+235, 218119, 2552, 14717, 0, '0', 0, 0, 0, 0, 1635.560791015625, -1216.267333984375, 2.083809375762939453, 6.086262702941894531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+236, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1636.529541015625, -1220.217041015625, 1.416054129600524902, 5.196337699890136718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+237, 218119, 2552, 14717, 0, '0', 0, 0, 0, 0, 1598.732666015625, -1151.296875, 8.117036819458007812, 6.158072948455810546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+238, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1603.786376953125, -1200.9027099609375, 2.197700262069702148, 5.288052558898925781, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+239, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1601.595458984375, -1148.84375, 8.508409500122070312, 5.943904876708984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+240, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1606.7220458984375, -1220.180908203125, 0.863220691680908203, 2.450592756271362304, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+241, 218119, 2552, 14717, 0, '0', 0, 0, 0, 0, 1585.6285400390625, -1174.2569580078125, 1.637926101684570312, 5.875525474548339843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+242, 218119, 2552, 14717, 0, '0', 0, 0, 0, 0, 1586.3385009765625, -1232.375, 1.369015932083129882, 3.669714927673339843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+243, 218119, 2552, 14717, 0, '0', 0, 0, 0, 0, 1587.9461669921875, -1233.7222900390625, 1.420756936073303222, 3.951038122177124023, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+244, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1575.2645263671875, -1216.82373046875, 1.657895684242248535, 4.575496196746826171, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+245, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1577.517333984375, -1266.810791015625, 0.944737672805786132, 6.10564422607421875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+246, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1566.7523193359375, -1246.453369140625, 1.422142624855041503, 4.546201229095458984, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+247, 218119, 2552, 14717, 0, '0', 0, 0, 0, 0, 1545.953125, -1237.2899169921875, 1.36127471923828125, 5.532527923583984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+248, 221519, 2552, 14717, 0, '0', 0, 0, 0, 0, 1547.431884765625, -1206.631591796875, 37.6035308837890625, 1.191201567649841308, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+249, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1563.8646240234375, -1280.654541015625, 7.437695026397705078, 5.998053550720214843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+250, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1540.6944580078125, -1237.704833984375, 2.12902069091796875, 0.107231117784976959, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+251, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1534.201416015625, -1206.154541015625, 10.49720954895019531, 5.943904876708984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+252, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1569.8096923828125, -1288.177001953125, 1.957201957702636718, 2.564971685409545898, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+253, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1521.013916015625, -1235.3004150390625, 16.58633804321289062, 5.892536640167236328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+254, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1580.80908203125, -1316.2603759765625, 0.168324530124664306, 0.096854910254478454, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+255, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1581.0728759765625, -1319.5972900390625, 0.184413939714431762, 0.096854910254478454, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+256, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1537.8759765625, -1307.3770751953125, 7.221850395202636718, 6.126227855682373046, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+257, 221519, 2552, 14717, 0, '0', 0, 0, 0, 0, 1555.6326904296875, -1326.1170654296875, 32.07739639282226562, 0.225763246417045593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+258, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1550.4478759765625, -1325.7421875, 6.51869964599609375, 4.74129343032836914, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+259, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1555.6180419921875, -1333.685791015625, 6.223712921142578125, 2.051967620849609375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+260, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1510.8055419921875, -1335.21533203125, 11.86005973815917968, 2.057012796401977539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+261, 218118, 2552, 14717, 0, '0', 0, 0, 0, 0, 1511.4566650390625, -1335.9774169921875, 11.86629581451416015, 5.336428642272949218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Undisciplined Earthen (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 436397 - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS))
(@CGUID+262, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1499.46533203125, -1374.8824462890625, 5.501478195190429687, 2.91348123550415039, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+263, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1545.8389892578125, -1383.2596435546875, 0.628948390483856201, 0.073284953832626342, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+264, 221519, 2552, 14717, 0, '0', 0, 0, 0, 0, 1507.5771484375, -1361.28759765625, 47.23454666137695312, 3.885413169860839843, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+265, 222747, 2552, 14717, 0, '0', 0, 0, 0, 0, 1483.0386962890625, -1366.9801025390625, 7.545311450958251953, 4.711450576782226562, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mossy Snail (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+266, 222035, 2552, 14717, 0, '0', 0, 0, 0, 0, 1536.5841064453125, -1408.5767822265625, 0.553983628749847412, 6.279810428619384765, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: 0 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+267, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1510.977783203125, -1406.26953125, 1.431883573532104492, 6.004080772399902343, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+268, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1525.3870849609375, -1428.723388671875, 0.94493800401687622, 1.565522193908691406, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+269, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1475.1319580078125, -1466.7374267578125, 3.91114044189453125, 4.020777225494384765, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+270, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1515.6331787109375, -1483.5203857421875, 1.22484755516052246, 5.943659782409667968, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+271, 221519, 2552, 14717, 0, '0', 0, 0, 0, 0, 1452.68896484375, -1450.6343994140625, 48.12268829345703125, 3.020330667495727539, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+272, 222747, 2552, 14717, 0, '0', 0, 0, 0, 0, 1448.022705078125, -1474.836669921875, 6.603061676025390625, 3.728615999221801757, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mossy Snail (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+273, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1485.600341796875, -1522.0457763671875, 0.301281720399856567, 3.842494010925292968, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+274, 223057, 2552, 14717, 0, '0', 0, 0, 0, 0, 1458.754150390625, -1501.9925537109375, 3.892341375350952148, 2.124122858047485351, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Trained Sandsnapper (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+275, 222035, 2552, 14717, 0, '0', 0, 0, 0, 0, 1490.535888671875, -1527.5220947265625, 0.208878099918365478, 0.682192504405975341, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+276, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1447.679931640625, -434.90972900390625, 51.41651153564453125, 2.02579808235168457, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+277, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1455.115966796875, -363.44622802734375, 41.57871627807617187, 5.495024681091308593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+278, 222757, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1462.8953857421875, -433.390228271484375, 66.16397857666015625, 1.323109388351440429, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Shalewing Devourer (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+279, 222329, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1424.26171875, -415.100433349609375, 80.437103271484375, 1.099639773368835449, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Regal Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+280, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1466.4578857421875, -384.579132080078125, 52.25590896606445312, 4.701051712036132812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+281, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1434.858154296875, -502.707611083984375, 25.20897483825683593, 5.037538051605224609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+282, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1435.8502197265625, -366.183990478515625, 37.485687255859375, 3.089758634567260742, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+283, 222329, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1428.2073974609375, -415.61895751953125, 79.4102325439453125, 1.929815053939819335, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Regal Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+284, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1450.2615966796875, -408.9891357421875, 50.1024017333984375, 5.479156017303466796, 120, 4, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+285, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1471.5130615234375, -379.73602294921875, 51.77864456176757812, 4.561254501342773437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+286, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1434.138427734375, -392.1983642578125, 43.72530364990234375, 2.547108173370361328, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+287, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1478.8458251953125, -347.7332763671875, 39.3372344970703125, 3.471679210662841796, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+288, 222329, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1381.7066650390625, -689.4600830078125, 62.26008987426757812, 1.566256165504455566, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Regal Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+289, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1347.789306640625, -638.55291748046875, 34.83388137817382812, 1.682831764221191406, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+290, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1396.8236083984375, -668.22259521484375, 44.2288818359375, 2.370686292648315429, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+291, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1429.426513671875, -730.5015869140625, 58.2193450927734375, 6.107051372528076171, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+292, 221528, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1354.2882080078125, -674.15625, 72.06201934814453125, 0.958495080471038818, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+293, 221528, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1417.0086669921875, -712.6475830078125, 106.14080810546875, 4.940181255340576171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+294, 221528, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1392.7916259765625, -717.53472900390625, 108.031036376953125, 4.940181255340576171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+295, 221528, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1451.0225830078125, -737.123291015625, 77.06005859375, 4.940181255340576171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+296, 221527, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1388.06103515625, -550.21722412109375, 52.48636627197265625, 4.600733280181884765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Regal Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+297, 222322, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1456.2435302734375, -553.1719970703125, 40.4588775634765625, 2.662474393844604492, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+298, 222322, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1464.7332763671875, -672.142822265625, 62.18209457397460937, 1.966372013092041015, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+299, 222322, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1355.6282958984375, -622.2745361328125, 51.3819122314453125, 5.35604095458984375, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+300, 225026, 2552, 14717, 14789, '0', 0, 0, 0, 0, 1337.0711669921875, -539.9375, 24.79419136047363281, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Sandscale Riplisk (Area: Dhar Oztan - Difficulty: 0) CreateObject1
(@CGUID+301, 222332, 2552, 14717, 14789, '0', 0, 0, 0, 0, 1478.2642822265625, -595.06756591796875, 33.17522811889648437, 3.314285516738891601, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Dhar Oztan - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+302, 224972, 2552, 14717, 14789, '0', 0, 0, 0, 0, 1423.04443359375, -650.35211181640625, 38.07583999633789062, 3.143545866012573242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Dire Stormhowl (Area: Dhar Oztan - Difficulty: 0) CreateObject1
(@CGUID+303, 223097, 2552, 14717, 14789, '0', 0, 0, 0, 0, 1505.29736328125, -580.93524169921875, 40.1960601806640625, 1.645023703575134277, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Black Ramolith (Area: Dhar Oztan - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+304, 222332, 2552, 14717, 14789, '0', 0, 0, 0, 0, 1392.067138671875, -533.4737548828125, 23.26590538024902343, 2.806336164474487304, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Dhar Oztan - Difficulty: 0) CreateObject1
(@CGUID+305, 224972, 2552, 14717, 14789, '0', 0, 0, 0, 0, 1336.85595703125, -536.234375, 24.845977783203125, 4.737227916717529296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Dire Stormhowl (Area: Dhar Oztan - Difficulty: 0) CreateObject1
(@CGUID+306, 224972, 2552, 14717, 14789, '0', 0, 0, 0, 0, 1336.4254150390625, -542.78302001953125, 24.54166793823242187, 1.545509099960327148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Dire Stormhowl (Area: Dhar Oztan - Difficulty: 0) CreateObject1
(@CGUID+307, 222332, 2552, 14717, 14789, '0', 0, 0, 0, 0, 1369.165283203125, -568.05377197265625, 24.5433807373046875, 5.311760902404785156, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Dhar Oztan - Difficulty: 0) CreateObject1
(@CGUID+308, 225026, 2552, 14717, 0, '0', 0, 0, 0, 0, 1271.9097900390625, -615.42535400390625, 25.40451431274414062, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Sandscale Riplisk (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+309, 222332, 2552, 14717, 0, '0', 0, 0, 0, 0, 1370.9306640625, -478.251953125, 18.55153465270996093, 3.112905025482177734, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+310, 224972, 2552, 14717, 0, '0', 0, 0, 0, 0, 1271.263916015625, -618.27081298828125, 25.3808441162109375, 1.545509099960327148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Dire Stormhowl (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+311, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1279.1175537109375, -822.798828125, 29.94826698303222656, 3.079051971435546875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+312, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1283.482177734375, -813.05023193359375, 29.68348312377929687, 1.455397725105285644, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+313, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1335.819091796875, -845.47930908203125, 37.4911041259765625, 3.057477951049804687, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+314, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1349.8436279296875, -759.83740234375, 48.08282470703125, 1.550291419029235839, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+315, 222774, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1287.7567138671875, -837.9310302734375, 30.66287612915039062, 4.77419900894165039, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+316, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1388.2701416015625, -725.6658935546875, 62.48183441162109375, 0.260146379470825195, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+317, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1368.92333984375, -724.6900634765625, 59.89818191528320312, 4.654723167419433593, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+318, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1293.5633544921875, -744.5965576171875, 32.63655853271484375, 0.426950782537460327, 120, 8, 0,10, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+319, 225040, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1356.3055419921875, -738.89581298828125, 51.10242843627929687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+320, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1333.103271484375, -885.87249755859375, 35.90960693359375, 2.097325325012207031, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+321, 224972, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1284.5654296875, -788.779296875, 31.28763580322265625, 5.291435718536376953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Dire Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+322, 225040, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1286.111083984375, -789.6632080078125, 31.3583831787109375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+323, 224972, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1255.923583984375, -856.91668701171875, 28.66113090515136718, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Dire Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+324, 222774, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1399.0614013671875, -780.728271484375, 47.99451446533203125, 2.727070093154907226, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+325, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1340.1383056640625, -734.04327392578125, 46.58359909057617187, 0.703117251396179199, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+326, 224972, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1354.7744140625, -737.904296875, 50.75916290283203125, 5.291435718536376953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Dire Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+327, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1428.4273681640625, -848.64105224609375, 39.77758026123046875, 0.679097771644592285, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+328, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1400.904541015625, -913.42535400390625, 41.97834014892578125, 5.969682216644287109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+329, 224972, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1505.3367919921875, -834.36285400390625, 51.6768646240234375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Dire Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+330, 225040, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1508.0728759765625, -833.71875, 52.26850509643554687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+331, 224972, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1485.9881591796875, -901.769287109375, 41.17657089233398437, 1.052982211112976074, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Dire Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+332, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1462.6072998046875, -849.65533447265625, 38.40373611450195312, 0.503964483737945556, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+333, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1462.86181640625, -890.334716796875, 37.69629669189453125, 1.863971948623657226, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+334, 224972, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1365.927001953125, -1017.28466796875, 39.28006744384765625, 2.685267210006713867, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Dire Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+335, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1350.792724609375, -957.24090576171875, 40.93402481079101562, 1.152572035789489746, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+336, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1344.86376953125, -982.60845947265625, 37.81360626220703125, 2.744774580001831054, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+337, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1329.61767578125, -936.5892333984375, 38.08101272583007812, 0.779873311519622802, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+338, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1292.67236328125, -957.57525634765625, 34.82959365844726562, 1.582571029663085937, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+339, 222332, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1249.2354736328125, -929.323974609375, 32.30031585693359375, 4.952153205871582031, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+340, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1430.4774169921875, -1055.618408203125, 43.16931915283203125, 4.160763740539550781, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+341, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1392.89990234375, -1077.099365234375, 56.36736297607421875, 1.659199118614196777, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+342, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1422.6622314453125, -989.5594482421875, 42.5590667724609375, 5.35428619384765625, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+343, 204341, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1393.8779296875, -975.7607421875, 53.83588409423828125, 4.671442985534667968, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ravenous Shalewing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+344, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1327.515869140625, -896.6971435546875, 40.77944183349609375, 5.584260463714599609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+345, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1431.19580078125, -990.550537109375, 41.92880630493164062, 5.819538116455078125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+346, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1448.247314453125, -990.4456787109375, 43.346527099609375, 6.248179912567138671, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+347, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1326.09765625, -889.31207275390625, 34.03243637084960937, 4.317477703094482421, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+348, 221644, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1400.0911865234375, -815.42730712890625, 62.303985595703125, 2.834488630294799804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+349, 222322, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1348.27734375, -754.28680419921875, 64.72237396240234375, 6.019066810607910156, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+350, 221644, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1410.384765625, -919.07025146484375, 61.10880279541015625, 3.844327449798583984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+351, 222322, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1406.3760986328125, -825.0296630859375, 69.62273406982421875, 3.814261913299560546, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+352, 221644, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1499.098876953125, -814.28076171875, 86.4488525390625, 2.999581575393676757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+353, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1276.441650390625, -1009.252197265625, 31.85132980346679687, 5.894618511199951171, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+354, 221672, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1393.5218505859375, -1047.75732421875, 38.9507293701171875, 2.169362068176269531, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+355, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1196.8603515625, -1114.853759765625, 44.989288330078125, 4.707310676574707031, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+356, 221672, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1223.3228759765625, -1114.8753662109375, 43.77724456787109375, 2.898139715194702148, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+357, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1306.5172119140625, -1143.061767578125, 54.20735931396484375, 0.722565710544586181, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+358, 221672, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1330.0069580078125, -1046.623291015625, 34.44942092895507812, 1.143793582916259765, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+359, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1215.3260498046875, -1088.2481689453125, 40.604278564453125, 1.656857728958129882, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+360, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1414.03759765625, -1150.44384765625, 43.96979522705078125, 5.750429153442382812, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+361, 221672, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1334.8736572265625, -1128.134033203125, 50.5470123291015625, 5.608444690704345703, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+362, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1258.3134765625, -1153.30419921875, 50.486175537109375, 6.098197460174560546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+363, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1316.65380859375, -1233.460693359375, 59.21166229248046875, 1.466868519783020019, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+364, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1182.3941650390625, -1091.0103759765625, 39.80247879028320312, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+365, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1167.6827392578125, -1065.7528076171875, 33.07379531860351562, 4.041155338287353515, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+366, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1231.1678466796875, -1142.679931640625, 46.91244888305664062, 0.376152276992797851, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+367, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1184.9140625, -984.20599365234375, 26.00241851806640625, 1.518007874488830566, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+368, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1179.0252685546875, -1087.9940185546875, 38.81829452514648437, 1.925909042358398437, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+369, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1114.801025390625, -1131.101806640625, 51.53420639038085937, 2.112209081649780273, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+370, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1114.4547119140625, -1073.904296875, 42.70456314086914062, 1.291691541671752929, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+371, 221672, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1087.669921875, -1086.125, 52.13654327392578125, 2.16855478286743164, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+372, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1091.4384765625, -1130.681884765625, 53.37799072265625, 1.649067401885986328, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+373, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1149.397216796875, -1169.79833984375, 47.50157546997070312, 1.516056537628173828, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+374, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1186.2725830078125, -1199.4617919921875, 56.25286483764648437, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+375, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1147.9088134765625, -1211.676513671875, 53.186248779296875, 4.1683197021484375, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+376, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1079.8333740234375, -1157.7486572265625, 53.640380859375, 1.670659422874450683, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+377, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1099.5555419921875, -1114.264892578125, 53.532318115234375, 1.597257375717163085, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+378, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1078.9305419921875, -1143.0208740234375, 55.20665740966796875, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+379, 221672, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1023.18017578125, -1137.9632568359375, 57.78379058837890625, 0.377968311309814453, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+390, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1070.4017333984375, -1216.4970703125, 58.44132232666015625, 3.867584228515625, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+391, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1136.1068115234375, -1240.620849609375, 55.17881011962890625, 2.680341958999633789, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+392, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 957.27703857421875, -1109.3974609375, 71.526275634765625, 4.600708961486816406, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+393, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 955.2596435546875, -1173.1905517578125, 71.23641204833984375, 4.888256549835205078, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+394, 221672, 2552, 14717, 14717, '0', 0, 0, 0, 0, 948.19580078125, -1136.9754638671875, 72.7793121337890625, 4.667055130004882812, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+395, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1176.92578125, -1285.75390625, 56.30415725708007812, 1.924450159072875976, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+396, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1228.27880859375, -1243.06640625, 56.50697708129882812, 3.358143091201782226, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+397, 222347, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1172.215087890625, -1326.3858642578125, 57.89365768432617187, 1.364652276039123535, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gnashing Rockwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+398, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1209.98974609375, -1328.70166015625, 51.69223403930664062, 0.566878974437713623, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+399, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1228.6373291015625, -1231.584716796875, 58.22655487060546875, 1.303435206413269042, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+400, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1161.565673828125, -1362.63134765625, 61.22483444213867187, 4.100203990936279296, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+401, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1239.9547119140625, -1262.06201171875, 52.1238861083984375, 3.014331340789794921, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+402, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1232.3323974609375, -1362.0516357421875, 55.2167510986328125, 0.954632163047790527, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+403, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1262.4385986328125, -1222.5960693359375, 54.4304351806640625, 5.441139698028564453, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+404, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1311.9671630859375, -1232.15576171875, 58.88547897338867187, 3.827322244644165039, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+405, 222329, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1293.140625, -1202.6944580078125, 95.6800994873046875, 4.117420196533203125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Regal Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+406, 222759, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1201.3790283203125, -1180.3450927734375, 56.6986236572265625, 0.895507872104644775, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ravenous Shalewing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+407, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1300.8016357421875, -1202.853515625, 77.96207427978515625, 1.288547873497009277, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+408, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1227.70458984375, -1241.3121337890625, 58.1538543701171875, 4.334523200988769531, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+409, 221644, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1342.3541259765625, -1266.219482421875, 89.93439483642578125, 3.432181119918823242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+410, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1349.8299560546875, -1214.0496826171875, 56.4909820556640625, 2.441496133804321289, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+411, 221644, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1366.803955078125, -1187.611328125, 96.07492828369140625, 3.739218473434448242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+412, 221527, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1168.3387451171875, -1279.7506103515625, 85.47552490234375, 1.08723151683807373, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Regal Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+413, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1216.8956298828125, -1109.71484375, 48.93438720703125, 1.198766231536865234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+414, 222759, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1255.8258056640625, -1328.9361572265625, 58.32963180541992187, 0.449902713298797607, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ravenous Shalewing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+415, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1137.0101318359375, -1279.91455078125, 54.828399658203125, 5.981814861297607421, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+416, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1132.9617919921875, -1321.704833984375, 60.260162353515625, 2.705101728439331054, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+417, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1174.877197265625, -1306.18359375, 56.57607650756835937, 4.127767086029052734, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+418, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1111.33642578125, -1262.0350341796875, 58.35229110717773437, 6.034062385559082031, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+419, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1057.365478515625, -1291.20458984375, 68.31056976318359375, 3.467667102813720703, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+420, 222759, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1141.9803466796875, -1360.3077392578125, 68.19918060302734375, 2.110996961593627929, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ravenous Shalewing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+421, 222759, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1065.226318359375, -1276.520263671875, 64.94879150390625, 0.051779251545667648, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ravenous Shalewing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+422, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1028.2630615234375, -1263.404541015625, 61.68072509765625, 5.789547443389892578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+423, 221527, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1113.6142578125, -1379.2496337890625, 158.1340179443359375, 3.992403745651245117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Regal Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+424, 222329, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1050.8125, -1329.201416015625, 158.2825775146484375, 1.566256165504455566, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Regal Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+425, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1232.7083740234375, -377.581878662109375, 14.92403221130371093, 0.096950598061084747, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+426, 222302, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1257.3348388671875, -464.293060302734375, 6.531719207763671875, 5.73958587646484375, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandscale Riplisk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+427, 222302, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1216.6602783203125, -392.91632080078125, 0.079911023378372192, 5.068417549133300781, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandscale Riplisk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+428, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1254.2135009765625, -397.9288330078125, 7.4886627197265625, 1.23749852180480957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+429, 222499, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1339.5799560546875, -393.42742919921875, 13.19894599914550781, 0.726642370223999023, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mossy Snail (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+430, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1226.5660400390625, -433.05035400390625, 6.760509490966796875, 2.130592107772827148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+431, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1254.6510009765625, -395.411468505859375, 6.690402984619140625, 1.23749852180480957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+432, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1229.5069580078125, -434.90972900390625, 7.151535511016845703, 4.947403430938720703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+433, 222302, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1327.00830078125, -428.7852783203125, 12.5562601089477539, 1.642103791236877441, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandscale Riplisk (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+434, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1331.9510498046875, -407.840484619140625, 11.46959114074707031, 5.30743408203125, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+435, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1278.480224609375, -496.386993408203125, 11.5237588882446289, 4.90001678466796875, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+436, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1252.63818359375, -447.72161865234375, 5.384578704833984375, 2.782479286193847656, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+437, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1191.4010009765625, -414.765625, 4.057438373565673828, 0.046243127435445785, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+438, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1190.951416015625, -410.3975830078125, 4.02189493179321289, 1.23749852180480957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+439, 227115, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1231.2122802734375, -379.327362060546875, -0.72589945793151855, 3.314951658248901367, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandy Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+440, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1186.21533203125, -412.19097900390625, 5.102721691131591796, 2.262922048568725585, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+441, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1218.90283203125, -506.885406494140625, 6.964058399200439453, 4.947403430938720703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+442, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1215.9617919921875, -505.02777099609375, 6.580684661865234375, 2.130592107772827148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+443, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1203.320068359375, -454.500396728515625, 2.567209959030151367, 0.261294394731521606, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+444, 222499, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1206.1678466796875, -443.066375732421875, 2.598756790161132812, 1.452135205268859863, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mossy Snail (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+445, 227115, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1196.0089111328125, -482.167022705078125, 0.41105690598487854, 4.050794601440429687, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandy Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+446, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1196.055419921875, -497.89776611328125, 0.241875290870666503, 3.855389595031738281, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+447, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1223.482666015625, -581.17364501953125, 8.905592918395996093, 2.130592107772827148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+448, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1127.43896484375, -469.725830078125, 14.92403125762939453, 3.267480850219726562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+449, 222302, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1191.0968017578125, -615.37933349609375, 1.288239717483520507, 1.863073706626892089, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandscale Riplisk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+450, 227115, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1171.04833984375, -532.25469970703125, -0.60569214820861816, 4.765820026397705078, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandy Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+451, 227115, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1140.75439453125, -445.205810546875, -7.53499364852905273, 2.017304897308349609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandy Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+452, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1222.892822265625, -565.941650390625, 4.254544734954833984, 6.12610626220703125, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+453, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1171.828125, -603.11456298828125, 3.767380952835083007, 1.23749852180480957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+454, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1167.092041015625, -604.90802001953125, 3.78895425796508789, 2.262922048568725585, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+455, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1257.8798828125, -595.29461669921875, 45.47188949584960937, 1.988829612731933593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+456, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1172.27783203125, -607.482666015625, 3.747113943099975585, 0.046243127435445785, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+457, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1212.7930908203125, -637.523681640625, 24.59745025634765625, 0.378947436809539794, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+458, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1140.5096435546875, -622.8824462890625, 14.92403221130371093, 2.826670169830322265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+459, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1171.41845703125, -660.625, 2.893311262130737304, 2.130592107772827148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+460, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1162.66650390625, -625.99798583984375, 0.484554082155227661, 3.803330659866333007, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+461, 222302, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1163.1812744140625, -711.13873291015625, 3.203101158142089843, 6.117365360260009765, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandscale Riplisk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+462, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1192.5694580078125, -697.12677001953125, 7.94116067886352539, 2.130592107772827148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+463, 227115, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1074.4144287109375, -543.2674560546875, -9.29299354553222656, 0.881386160850524902, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Sandy Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+464, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1079.251708984375, -700.72393798828125, 3.416017532348632812, 4.947403430938720703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+465, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1076.310791015625, -698.86456298828125, 4.894139289855957031, 2.130592107772827148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+466, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1139.0887451171875, -692.2818603515625, 2.621566534042358398, 3.032013654708862304, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+467, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1191.0572509765625, -741.50177001953125, 10.29364967346191406, 1.23749852180480957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+468, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1223.0279541015625, -687.9832763671875, 13.27083683013916015, 3.552096843719482421, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+469, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1102.6475830078125, -732.490478515625, 14.92403125762939453, 1.252744793891906738, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+470, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1102.8829345703125, -735.142333984375, 14.92403030395507812, 1.109441637992858886, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+471, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1116.26220703125, -698.08905029296875, 1.31566786766052246, 2.989146947860717773, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+472, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1076.98095703125, -746.2117919921875, 4.211547374725341796, 4.947403430938720703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+473, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1236.81787109375, -750.11968994140625, 42.14228439331054687, 5.849729061126708984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+474, 224800, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1074.0399169921875, -744.35418701171875, 4.409057140350341796, 2.130592107772827148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Salty Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+475, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1172.33837890625, -740.34161376953125, 4.617609024047851562, 2.001224994659423828, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+476, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1141.0616455078125, -794.67437744140625, 22.14445304870605468, 0.451959013938903808, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+477, 227115, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1050.3526611328125, -669.5623779296875, -6.9145522117614746, 1.706240177154541015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandy Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+478, 222301, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1082.3956298828125, -842.66595458984375, 1.569821953773498535, 1.361339330673217773, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Damp Sandcourser (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+479, 222301, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1115.4246826171875, -863.89410400390625, 2.898969173431396484, 0.469579339027404785, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Damp Sandcourser (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+480, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1149.7073974609375, -833.314453125, 5.059821605682373046, 1.224359393119812011, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+481, 222301, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1151.852294921875, -874.61773681640625, 6.058872222900390625, 4.090776443481445312, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Damp Sandcourser (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+482, 222301, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1058.7218017578125, -875.08270263671875, 0.50572901964187622, 6.084059715270996093, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Damp Sandcourser (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+483, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1106.123291015625, -858.6512451171875, 2.440461158752441406, 0.055854741483926773, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+484, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1181.6285400390625, -905.91839599609375, 37.66688156127929687, 3.760425567626953125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+485, 222310, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1023.976318359375, -952.7708740234375, 41.56707000732421875, 0.62014317512512207, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+486, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1053.173583984375, -948.793701171875, 3.168858766555786132, 3.041842937469482421, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+487, 227115, 2552, 14717, 14717, '0', 0, 0, 0, 0, 938.433349609375, -900.9375, -5.92728137969970703, 2.98358321189880371, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandy Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+488, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 917.70654296875, -954.05029296875, 0.629581749439239501, 1.876775622367858886, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+489, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 827.724365234375, -1057.03271484375, 1.063942432403564453, 0.081393904983997344, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+490, 222035, 2552, 14717, 14717, '0', 0, 0, 0, 0, 748.2913818359375, -1097.01025390625, 1.57342994213104248, 5.441769123077392578, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Softshell Pincher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+491, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 972.70166015625, -981.29998779296875, 1.906992316246032714, 0.345834076404571533, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+492, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 911.02593994140625, -1034.7012939453125, 4.843852519989013671, 3.598690271377563476, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+493, 222312, 2552, 14717, 14717, '0', 0, 0, 0, 0, 988.99072265625, -1040.5086669921875, 12.46604347229003906, 5.345347881317138671, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Scavenging Sandsnapper (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+494, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 924.58282470703125, -954.04132080078125, 0.610384106636047363, 4.953887939453125, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+495, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 921.38055419921875, -983.7564697265625, 2.202720165252685546, 3.64043283462524414, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+496, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 882.16619873046875, -958.1055908203125, 1.828208565711975097, 4.144251823425292968, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+497, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 944.300048828125, -1024.8680419921875, 12.07677745819091796, 6.0884552001953125, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+498, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1014.3853759765625, -1018.78472900390625, 4.349182605743408203, 0.202443882822990417, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+499, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 853.41168212890625, -1027.0286865234375, 0.639766335487365722, 0.111974932253360748, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+500, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 808.803466796875, -1026.8155517578125, 0.733527421951293945, 1.216179847717285156, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+501, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 857.7772216796875, -1074.171630859375, 8.058370590209960937, 6.232104301452636718, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+502, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 834.1719970703125, -1058.5341796875, 1.534760117530822753, 5.88692474365234375, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+503, 222312, 2552, 14717, 14717, '0', 0, 0, 0, 0, 866.16546630859375, -1009.49151611328125, 1.469024300575256347, 4.298847198486328125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Scavenging Sandsnapper (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+504, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 836.40679931640625, -1117.120849609375, 19.22034454345703125, 5.777604579925537109, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+505, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 777.156494140625, -1078.6131591796875, 0.978950381278991699, 4.136265754699707031, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+506, 222312, 2552, 14717, 14717, '0', 0, 0, 0, 0, 820.77752685546875, -996.01263427734375, 0.486170947551727294, 0.621612548828125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Scavenging Sandsnapper (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+507, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 762.28643798828125, -1093.3839111328125, 2.002001285552978515, 1.699770569801330566, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+508, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 817.804931640625, -1085.527099609375, 2.563895940780639648, 2.892127275466918945, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+509, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 787.7220458984375, -1124.876708984375, 12.45996379852294921, 1.692870736122131347, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+510, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 739.8306884765625, -1101.309326171875, 2.075582742691040039, 0.473519057035446166, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+511, 223657, 2552, 14717, 14717, '0', 0, 0, 0, 0, 713.90057373046875, -1122.84521484375, 5.587814807891845703, 0.657690763473510742, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Igneous Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+512, 222312, 2552, 14717, 14717, '0', 0, 0, 0, 0, 719.13958740234375, -1117.3994140625, 4.542037010192871093, 6.102738857269287109, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Scavenging Sandsnapper (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+513, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1353.01025390625, -1439.2384033203125, 36.5630035400390625, 5.231050968170166015, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+514, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1431.177978515625, -1384.751220703125, 26.69155311584472656, 2.251787185668945312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+515, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1435.8798828125, -1339.60302734375, 25.6785736083984375, 5.273645401000976562, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+516, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1379.259521484375, -1372.3072509765625, 36.67847442626953125, 0.889945507049560546, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+517, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1387.4556884765625, -1281.577392578125, 43.53310394287109375, 3.178721427917480468, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+518, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1307.0823974609375, -1371.670166015625, 54.40187835693359375, 1.068498492240905761, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+519, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1370.519775390625, -1456.954833984375, 32.87153244018554687, 1.380297660827636718, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+520, 223098, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1378.64599609375, -1344.950439453125, 36.61635208129882812, 0.490712881088256835, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cobalt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+521, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1331.1474609375, -1333.641845703125, 49.43158340454101562, 3.583827733993530273, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+522, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1434.4583740234375, -1412.852783203125, 47.46229171752929687, 4.490712165832519531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+523, 222774, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1358.2447509765625, -1413.292724609375, 38.63523483276367187, 5.931046485900878906, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+524, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1459.7552490234375, -1316.463134765625, 22.43910598754882812, 0.1509103924036026, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+525, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1472.2958984375, -1292.07421875, 23.12879180908203125, 0.567460596561431884, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+526, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1387.17529296875, -1258.0531005859375, 61.22313690185546875, 3.301545143127441406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+527, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1288.043212890625, -1433.4915771484375, 50.0606689453125, 0.151806011795997619, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+528, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1284.8941650390625, -1417.8233642578125, 48.50568771362304687, 0.25066310167312622, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+529, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1394.738037109375, -1504.70458984375, 20.53315353393554687, 2.28510904312133789, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+530, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1275.2950439453125, -1476.2471923828125, 47.78451919555664062, 0.311562538146972656, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+531, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1314.7574462890625, -1514.3267822265625, 43.69849014282226562, 3.442252874374389648, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+532, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1248.27490234375, -1501.5640869140625, 50.264404296875, 0.704391360282897949, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+533, 222780, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1261.3656005859375, -1504.0223388671875, 51.90613937377929687, 0.670258224010467529, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+534, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1299.692138671875, -1538.73046875, 47.68061065673828125, 1.325597167015075683, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+535, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1263.4559326171875, -1577.780029296875, 47.19723129272460937, 5.818813323974609375, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+536, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1332.020751953125, -1603.72998046875, 24.64808273315429687, 1.366163134574890136, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+537, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1285.896728515625, -1624.4696044921875, 37.80502700805664062, 3.829456329345703125, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+538, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1156.8966064453125, -1541.9273681640625, 60.24132156372070312, 3.17406630516052246, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+539, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1203.8499755859375, -1419.9332275390625, 55.2947235107421875, 1.394087433815002441, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+540, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1180.9293212890625, -1602.324462890625, 59.107025146484375, 5.588410854339599609, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+541, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1166.6669921875, -1634.865478515625, 64.660430908203125, 1.570796370506286621, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+542, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1313.007568359375, -1656.0244140625, 29.7790985107421875, 0.464394479990005493, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+543, 222780, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1079.242431640625, -1541.5831298828125, 77.74961090087890625, 1.926980376243591308, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+544, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1081.4166259765625, -1514.73095703125, 74.32696533203125, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+545, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1088.3662109375, -1491.211669921875, 74.0728302001953125, 5.82534027099609375, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+546, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1083.2117919921875, -1489.4896240234375, 73.2727508544921875, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+547, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1162.65234375, -1434.62158203125, 63.29961013793945312, 1.542412042617797851, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+548, 222780, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1119.8651123046875, -1425.9625244140625, 68.680267333984375, 4.216536998748779296, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+549, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1087.345458984375, -1437.3055419921875, 73.28369140625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+550, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1046.6240234375, -1504.6170654296875, 81.29586029052734375, 3.370222330093383789, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+551, 227127, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1047.19775390625, -1602.5814208984375, 86.4489288330078125, 0.599108815193176269, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+552, 222780, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1053.3604736328125, -1656.0003662109375, 83.04357147216796875, 2.70046234130859375, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+553, 227127, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1053.0047607421875, -1661.69384765625, 82.989044189453125, 4.873613357543945312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+554, 227127, 2552, 14717, 14717, '0', 0, 0, 0, 0, 996.6231689453125, -1653.327392578125, 83.565887451171875, 5.637731075286865234, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+555, 227127, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1038.1998291015625, -1700.3056640625, 84.85739898681640625, 6.094598770141601562, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+556, 222780, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1121.177490234375, -1736.3082275390625, 72.95192718505859375, 2.54110121726989746, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+557, 222419, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1499.602294921875, -1135.9771728515625, 35.90489578247070312, 1.057343006134033203, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Sheep (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+558, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1100.01513671875, -1836.3861083984375, 81.83876800537109375, 1.753622293472290039, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+559, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1074.5718994140625, -1849.8836669921875, 83.89666748046875, 5.003846168518066406, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+560, 217561, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1147.7100830078125, -1792.7742919921875, 80.80684661865234375, 5.189431190490722656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+561, 217561, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1143.185791015625, -1776.8697509765625, 76.557525634765625, 6.203567981719970703, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+562, 214946, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1081.359375, -1778.0625, 77.87847900390625, 2.66570591926574707, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+563, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1079.64501953125, -1820.221923828125, 79.7462310791015625, 3.94080209732055664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+564, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1139.818603515625, -1772.7720947265625, 96.78057861328125, 4.13401031494140625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+565, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1106.53125, -1866.5264892578125, 111.4001693725585937, 4.025293350219726562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+566, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1086.762451171875, -1884.990234375, 93.27526092529296875, 0.583128571510314941, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+567, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1132.4073486328125, -1857.9755859375, 79.44097900390625, 4.474025726318359375, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+568, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1066.7655029296875, -1717.466552734375, 104.8499069213867187, 5.815957069396972656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+589, 214946, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1053.9896240234375, -1881.1302490234375, 92.6378326416015625, 5.788118362426757812, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+590, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1155.586669921875, -1717.4959716796875, 69.68981170654296875, 5.864564418792724609, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+591, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1034.6629638671875, -1854.077880859375, 79.89756011962890625, 3.726503610610961914, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+592, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 982.0919189453125, -1779.6676025390625, 115.9974517822265625, 5.153238773345947265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+593, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 999.083251953125, -1854.94140625, 113.7851181030273437, 2.021059989929199218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+594, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1070.3319091796875, -1907.9359130859375, 100.9030227661132812, 3.737185478210449218, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+595, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 978.38153076171875, -1876.7611083984375, 95.40888214111328125, 2.837415218353271484, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+596, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 997.02532958984375, -1908.8990478515625, 100.8424148559570312, 1.868741273880004882, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+597, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1135.4420166015625, -1970.61865234375, 84.8347015380859375, 0.948011279106140136, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+598, 215035, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1083.0626220703125, -1908.111083984375, 100.3860702514648437, 5.527233600616455078, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Freefoot Mouse (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+599, 215035, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1144.8505859375, -1926.7435302734375, 82.21845245361328125, 0.842045724391937255, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Freefoot Mouse (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+600, 215035, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1085.10546875, -1910.26171875, 99.9645843505859375, 5.654532909393310546, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Freefoot Mouse (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+601, 215035, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1144.3018798828125, -1977.191162109375, 84.1971435546875, 6.045212745666503906, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Freefoot Mouse (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+602, 215034, 2552, 14717, 14772, '0', 0, 0, 0, 0, 984.43133544921875, -1817.006591796875, 91.842254638671875, 3.500127792358398437, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+603, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 883.6163330078125, -1719.44970703125, 128.9534912109375, 6.010805606842041015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+604, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 889.156494140625, -1772.479248046875, 113.3647003173828125, 6.185363292694091796, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+605, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 903.07855224609375, -1739.78564453125, 142.7396240234375, 2.591258525848388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+606, 215035, 2552, 14717, 14772, '0', 0, 0, 0, 0, 953.7451171875, -1781.3663330078125, 94.3972625732421875, 4.374104976654052734, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Freefoot Mouse (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+607, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 901.467041015625, -1703.7742919921875, 153.773162841796875, 6.010805606842041015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+608, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 964.67059326171875, -1813.58447265625, 100.1105880737304687, 1.546387076377868652, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+609, 214946, 2552, 14717, 14772, '0', 0, 0, 0, 0, 944.77606201171875, -1861.1475830078125, 93.544219970703125, 0.658870816230773925, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: 382619 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath (Scale 2, Up 1))
(@CGUID+610, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 969.9375, -1719.7100830078125, 83.8243255615234375, 0.323520809412002563, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+611, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 887.532470703125, -1852.70263671875, 117.0622329711914062, 0.932476520538330078, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+612, 215035, 2552, 14717, 14772, '0', 0, 0, 0, 0, 926.0296630859375, -1821.0543212890625, 112.8815383911132812, 5.245089530944824218, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Freefoot Mouse (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+613, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 899.68231201171875, -1765.5972900390625, 111.0490493774414062, 1.596142172813415527, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+614, 215038, 2552, 14717, 14772, '0', 0, 0, 0, 0, 949.3123779296875, -1716.141357421875, 96.49388885498046875, 0.141593188047409057, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Thistlestar (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+615, 215034, 2552, 14717, 14772, '0', 0, 0, 0, 0, 882.7757568359375, -1847.5445556640625, 118.9535903930664062, 0.543368041515350341, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+616, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 886.658203125, -1825.0108642578125, 140.407012939453125, 0.477802604436874389, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+617, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 939.81634521484375, -1750.802734375, 95.71197509765625, 4.735822200775146484, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+618, 215035, 2552, 14717, 14772, '0', 0, 0, 0, 0, 856.84375, -1894.8836669921875, 126.730499267578125, 0, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Freefoot Mouse (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+619, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 901.98291015625, -1833.7254638671875, 116.5375213623046875, 2.94706892967224121, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+620, 215038, 2552, 14717, 14772, '0', 0, 0, 0, 0, 914.375732421875, -1743.4361572265625, 104.7594680786132812, 2.098546743392944335, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Thistlestar (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+621, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 983.23480224609375, -1811.685546875, 91.0386505126953125, 2.729517698287963867, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+622, 215034, 2552, 14717, 14772, '0', 0, 0, 0, 0, 949.6158447265625, -1858.6031494140625, 93.587799072265625, 2.964537858963012695, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+623, 215038, 2552, 14717, 14772, '0', 0, 0, 0, 0, 854.68817138671875, -1822.511474609375, 127.2770767211914062, 1.567378044128417968, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Thistlestar (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+624, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 940.5069580078125, -1795.0208740234375, 103.14410400390625, 1.596142172813415527, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+625, 215038, 2552, 14717, 14772, '0', 0, 0, 0, 0, 912.6527099609375, -1893.078857421875, 94.86334228515625, 5.476972579956054687, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Thistlestar (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+626, 214946, 2552, 14717, 14772, '0', 0, 0, 0, 0, 958.18511962890625, -1787.6827392578125, 92.8354949951171875, 4.732893943786621093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+627, 215034, 2552, 14717, 14772, '0', 0, 0, 0, 0, 891.29052734375, -1779.864501953125, 113.3253326416015625, 2.500330209732055664, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+628, 223090, 2552, 14717, 14717, '0', 0, 0, 0, 0, 607.23956298828125, -1588.123779296875, 247.1432342529296875, 3.939020633697509765, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Bedrock Stonecharger (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+629, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 703.18017578125, -1669.879150390625, 246.6385498046875, 0.375793725252151489, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+630, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 686.30078125, -1723.819091796875, 260.7750244140625, 4.254860401153564453, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+631, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 685.548828125, -1706.392822265625, 257.4949951171875, 2.650988340377807617, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+632, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 662.37591552734375, -1608.9676513671875, 240.4752655029296875, 1.941472768783569335, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+633, 227733, 2552, 14717, 14717, '0', 0, 0, 0, 0, 689.823486328125, -1701.7630615234375, 254.99169921875, 4.6224365234375, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+634, 214945, 2552, 14717, 14717, '0', 0, 0, 0, 0, 791.3394775390625, -1727.4134521484375, 165.1669769287109375, 0.563859164714813232, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+635, 214946, 2552, 14717, 14717, '0', 0, 0, 0, 0, 805.44964599609375, -1728.23095703125, 162.644317626953125, 4.139476776123046875, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+636, 204341, 2552, 14717, 14717, '0', 0, 0, 0, 0, 767.242919921875, -1740.6529541015625, 174.4665374755859375, 1.729285717010498046, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Ravenous Shalewing (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+637, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 781.81292724609375, -1796.5166015625, 188.4033050537109375, 1.236173033714294433, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+638, 221678, 2552, 14717, 14772, '0', 0, 0, 0, 0, 721.38079833984375, -1867.1942138671875, 202.596923828125, 1.256146669387817382, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+639, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 763.89776611328125, -1921.639404296875, 172.6827239990234375, 4.574371337890625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+640, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 730.25164794921875, -1888.10205078125, 218.36846923828125, 4.688945770263671875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+641, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 814.06768798828125, -1979.3507080078125, 168.9742279052734375, 1.000689148902893066, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+642, 223095, 2552, 14717, 14772, '0', 0, 0, 0, 0, 719.7197265625, -1988.61474609375, 192.9796905517578125, 2.615907669067382812, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Bedrock Stonecharger (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+643, 218205, 2552, 14717, 14772, '0', 0, 0, 0, 0, 739.00006103515625, -1987.8280029296875, 186.7839813232421875, 4.732893943786621093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Sparking Sharptooth (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+644, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 752.94989013671875, -1912.4560546875, 177.9243011474609375, 0.422586798667907714, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+645, 223187, 2552, 14717, 14772, '0', 0, 0, 0, 0, 843.13714599609375, -1869.204833984375, 145.40252685546875, 3.08087158203125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+646, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 817.42181396484375, -1974.3890380859375, 147.528717041015625, 5.065669059753417968, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+647, 217561, 2552, 14717, 14772, '0', 0, 0, 0, 0, 710.804931640625, -1915.91015625, 203.8825836181640625, 1.01261138916015625, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+648, 217561, 2552, 14717, 14772, '0', 0, 0, 0, 0, 781.984375, -1827.5972900390625, 166.628570556640625, 6.090119838714599609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+649, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 818.8154296875, -1954.6455078125, 184.686859130859375, 2.935158252716064453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+650, 218205, 2552, 14717, 14772, '0', 0, 0, 0, 0, 787.05902099609375, -2038.7137451171875, 157.23638916015625, 0.195827499032020568, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Sparking Sharptooth (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+651, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 879.467529296875, -1941.76025390625, 146.8992767333984375, 1.166829824447631835, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+652, 217561, 2552, 14717, 14772, '0', 0, 0, 0, 0, 749.20672607421875, -1913.689208984375, 180.036376953125, 0.317773640155792236, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+653, 214946, 2552, 14717, 14772, '0', 0, 0, 0, 0, 813.54864501953125, -1954.30908203125, 144.6876983642578125, 0.078770443797111511, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+654, 219264, 2552, 14717, 14772, '0', 0, 0, 0, 0, 723.07568359375, -1862.0118408203125, 201.5293731689453125, 1.254291057586669921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Bloodmaw (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: 447412 - Ravenous)
(@CGUID+655, 214946, 2552, 14717, 14772, '0', 0, 0, 0, 0, 856.22540283203125, -1945.1536865234375, 125.2297134399414062, 6.224544525146484375, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+656, 214946, 2552, 14717, 14772, '0', 0, 0, 0, 0, 774.43927001953125, -1870.501708984375, 170.9125823974609375, 0.078770443797111511, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+657, 221678, 2552, 14717, 14772, '0', 0, 0, 0, 0, 718.2794189453125, -1860.5977783203125, 205.4570159912109375, 1.255626559257507324, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Wild Stormhowl (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+658, 215034, 2552, 14717, 14772, '0', 0, 0, 0, 0, 850.9600830078125, -1955.386474609375, 128.401092529296875, 3.245473623275756835, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+659, 218187, 2552, 14717, 14772, '0', 0, 0, 0, 0, 976.248291015625, -2152.151123046875, 97.85485076904296875, 2.428959846496582031, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Stomper (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+660, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1033.0662841796875, -2056.953369140625, 93.6287841796875, 4.94562530517578125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+661, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 891.98516845703125, -1932.0234375, 110.4960174560546875, 1.430903792381286621, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+662, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 848.42169189453125, -2003.489013671875, 137.792388916015625, 1.05819404125213623, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+667, 217561, 2552, 14717, 0, '0', 0, 0, 0, 0, 725.46527099609375, -1803.3638916015625, 204.1260223388671875, 3.950926542282104492, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+668, 217561, 2552, 14717, 0, '0', 0, 0, 0, 0, 719.3350830078125, -1811.970458984375, 208.3024749755859375, 0.757884502410888671, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+669, 217561, 2552, 14717, 0, '0', 0, 0, 0, 0, 827.9757080078125, -1864.125, 144.023773193359375, 4.361501693725585937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+670, 214946, 2552, 14717, 14772, '0', 0, 0, 0, 0, 894.37066650390625, -1953.5269775390625, 109.0159225463867187, 0.037209931761026382, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+671, 215035, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1008.1036376953125, -2046.8974609375, 93.7153472900390625, 3.84945988655090332, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Freefoot Mouse (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+672, 218187, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1043.7294921875, -2036.96484375, 91.2570648193359375, 3.636261940002441406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Grazing Stomper (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+673, 215035, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1045.7109375, -2027.0023193359375, 93.7093048095703125, 5.203092575073242187, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Freefoot Mouse (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+674, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1036.4920654296875, -2066.4951171875, 89.87599945068359375, 1.976649880409240722, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+675, 218188, 2552, 14717, 14772, '0', 0, 0, 0, 0, 981.6322021484375, -2147.837890625, 95.312957763671875, 1.421713113784790039, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Meandering Gorger (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+676, 218188, 2552, 14717, 14772, '0', 0, 0, 0, 0, 944.0714111328125, -2057.8798828125, 102.231475830078125, 4.079430580139160156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Meandering Gorger (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+677, 221519, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1038.3890380859375, -2064.408203125, 113.4673538208007812, 3.040147304534912109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Fluttering Sapphire (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+678, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 942.9757080078125, -2047.326416015625, 101.9591293334960937, 3.373076915740966796, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+679, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 966.69671630859375, -2007.3563232421875, 97.12470245361328125, 4.833835601806640625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+680, 218203, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1021.96759033203125, -2098.47705078125, 91.1857452392578125, 4.007216453552246093, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+681, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 897.16949462890625, -2101.481201171875, 118.09661865234375, 0.98360675573348999, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+682, 218194, 2552, 14717, 14772, '0', 0, 0, 0, 0, 920.47369384765625, -2096.1943359375, 108.0545883178710937, 3.944266319274902343, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+683, 218201, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1041.6531982421875, -2111.918212890625, 139.032012939453125, 5.281939983367919921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Circling Sharpbeak (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+684, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1016.392578125, -2083.595703125, 92.68213653564453125, 0.435565114021301269, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+685, 218187, 2552, 14717, 14772, '0', 0, 0, 0, 0, 991.22833251953125, -2141.0439453125, 91.986114501953125, 3.983775138854980468, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Stomper (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+686, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1052.659423828125, -2061.452392578125, 88.53762054443359375, 1.85794997215270996, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+687, 218201, 2552, 14717, 14772, '0', 0, 0, 0, 0, 998.6351318359375, -2138.92138671875, 151.8576812744140625, 2.244956016540527343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Circling Sharpbeak (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+688, 222780, 2552, 14717, 14772, '0', 0, 0, 0, 0, 972.6739501953125, -2083.35986328125, 98.77008819580078125, 2.945409297943115234, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Fragrant Stonelamb (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+689, 215035, 2552, 14717, 14772, '0', 0, 0, 0, 0, 980.5355224609375, -2018.6109619140625, 102.8350296020507812, 3.572300910949707031, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Freefoot Mouse (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+690, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1048.5830078125, -2023.69140625, 93.8221588134765625, 6.046500682830810546, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+691, 218187, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1082.98486328125, -2047.00390625, 86.48438262939453125, 5.955262184143066406, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Stomper (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+692, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 876.2301025390625, -2008.96044921875, 121.436248779296875, 6.014277935028076171, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+693, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 972.75360107421875, -2203.53369140625, 97.7099151611328125, 4.074357032775878906, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+694, 220026, 2552, 14717, 14772, '0', 0, 0, 0, 0, 865.4305419921875, -2092.463623046875, 124.8647384643554687, 0.426135063171386718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Slumbering Mountain Giant (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+695, 223093, 2552, 14717, 14772, '0', 0, 0, 0, 0, 920.289794921875, -2171.415283203125, 107.2810134887695312, 6.174187660217285156, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Granite Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+696, 214946, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1074.8228759765625, -2004.1475830078125, 83.6970672607421875, 1.379054546356201171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+697, 218187, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1073.1676025390625, -2124.521240234375, 86.8581695556640625, 5.739038467407226562, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Stomper (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+698, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1073.637939453125, -2050.058349609375, 87.26099395751953125, 1.270822644233703613, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+699, 218187, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1092.3541259765625, -2086.873046875, 85.78481292724609375, 4.975900650024414062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Grazing Stomper (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+700, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 912.0498046875, -1969.9276123046875, 104.4213714599609375, 1.92248547077178955, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+701, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1005.6209716796875, -2200.412841796875, 98.4847259521484375, 1.03104710578918457, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+702, 218194, 2552, 14717, 14772, '0', 0, 0, 0, 0, 861.36041259765625, -2066.136962890625, 132.8604888916015625, 4.24481058120727539, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+703, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 874.31097412109375, -1986.6534423828125, 120.7724533081054687, 2.227981805801391601, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+704, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 833.00885009765625, -2118.547607421875, 142.4532470703125, 2.18314218521118164, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+705, 223093, 2552, 14717, 14772, '0', 0, 0, 0, 0, 873.234375, -2164.537109375, 124.2407379150390625, 0.880708754062652587, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Granite Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+706, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 853.1611328125, -2187.826904296875, 132.033843994140625, 5.085100173950195312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+707, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 869.27020263671875, -2209.131591796875, 119.39007568359375, 5.380807399749755859, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+708, 218194, 2552, 14717, 14772, '0', 0, 0, 0, 0, 830.614013671875, -2072.674072265625, 146.0311279296875, 1.066069960594177246, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+709, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 977.58331298828125, -1945.9583740234375, 100.0496597290039062, 1.948076248168945312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+710, 215034, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1006.1796875, -1989.4007568359375, 99.64102935791015625, 1.358064532279968261, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+711, 215038, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1092.7825927734375, -2056.143798828125, 88.97833251953125, 4.272653102874755859, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Thistlestar (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+712, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1093.0240478515625, -2074.927490234375, 84.53167724609375, 0.571468651294708251, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+713, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1106.86376953125, -2077.014892578125, 86.87277984619140625, 0.09020678699016571, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+714, 218194, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1097.9935302734375, -2189.260498046875, 86.48699951171875, 5.902452468872070312, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+715, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1103.966796875, -2055.149169921875, 87.1025543212890625, 6.240460872650146484, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+716, 227127, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1104.1953125, -2040.7318115234375, 86.007354736328125, 5.758356094360351562, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+717, 215036, 2552, 14717, 14772, '0', 0, 0, 0, 0, 965.42108154296875, -1946.2149658203125, 112.8838958740234375, 6.019647121429443359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Redwing Falcon (Area: Freywold Village - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+718, 218191, 2552, 14717, 14772, '0', 0, 0, 0, 0, 1055.489013671875, -2217.502197265625, 80.9011993408203125, 0.20312705636024475, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+719, 215038, 2552, 14717, 14772, '0', 0, 0, 0, 0, 942.574462890625, -1980.2305908203125, 102.4669570922851562, 0.509626567363739013, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Thistlestar (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+720, 214945, 2552, 14717, 14772, '0', 0, 0, 0, 0, 918.85589599609375, -1945.9879150390625, 101.7984695434570312, 3.837219953536987304, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+721, 222775, 2552, 14717, 14772, '0', 0, 0, 0, 0, 967.9925537109375, -1970.2322998046875, 100.6750640869140625, 4.520448207855224609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sandstone Mosswool (Area: Freywold Village - Difficulty: 0) CreateObject1
(@CGUID+722, 218205, 2552, 14717, 14717, '0', 0, 0, 0, 0, 777.4940185546875, -2102.104736328125, 165.7244873046875, 5.891911029815673828, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sparking Sharptooth (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+723, 218205, 2552, 14717, 14717, '0', 0, 0, 0, 0, 694.28546142578125, -2191.41552734375, 200.385894775390625, 2.611057281494140625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sparking Sharptooth (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+724, 218203, 2552, 14717, 14717, '0', 0, 0, 0, 0, 736.0155029296875, -2179.1474609375, 166.837615966796875, 6.261704444885253906, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+725, 218191, 2552, 14717, 14717, '0', 0, 0, 0, 0, 883.46905517578125, -2231.511962890625, 110.524993896484375, 1.673708319664001464, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+726, 218203, 2552, 14717, 14717, '0', 0, 0, 0, 0, 783.72918701171875, -2211.51611328125, 142.2262115478515625, 3.82182478904724121, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+727, 218205, 2552, 14717, 14717, '0', 0, 0, 0, 0, 732.097412109375, -2221.449462890625, 171.2394866943359375, 5.803050994873046875, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Sparking Sharptooth (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+728, 218203, 2552, 14717, 14717, '0', 0, 0, 0, 0, 748.51031494140625, -2153.570556640625, 159.779571533203125, 0.853803396224975585, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+729, 218203, 2552, 14717, 14717, '0', 0, 0, 0, 0, 728.3887939453125, -2250.386474609375, 166.2044219970703125, 5.792538642883300781, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+730, 223097, 2552, 14717, 14717, '0', 0, 0, 0, 0, 743.90313720703125, -2210.138916015625, 163.58563232421875, 4.542748451232910156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Black Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+731, 227733, 2552, 14717, 14717, '0', 0, 0, 0, 0, 690.69635009765625, -2198.800537109375, 199.634185791015625, 5.869321823120117187, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+732, 218194, 2552, 14717, 14717, '0', 0, 0, 0, 0, 800.03253173828125, -2205.4462890625, 138.134552001953125, 3.483146905899047851, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+733, 218194, 2552, 14717, 14717, '0', 0, 0, 0, 0, 829.36981201171875, -2225.263916015625, 130.112701416015625, 3.47971653938293457, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Vinechewer Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+734, 218191, 2552, 14717, 14717, '0', 0, 0, 0, 0, 765.6785888671875, -2248.71240234375, 141.175689697265625, 2.396945953369140625, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+735, 218201, 2552, 14717, 14717, '0', 0, 0, 0, 0, 757.8863525390625, -2226.17138671875, 181.342071533203125, 3.536751508712768554, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Circling Sharpbeak (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+736, 218191, 2552, 14717, 14717, '0', 0, 0, 0, 0, 808.0963134765625, -2263.588623046875, 124.4191513061523437, 0.801971256732940673, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Moss-Draped Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+737, 218201, 2552, 14717, 14717, '0', 0, 0, 0, 0, 766.420654296875, -2166.5458984375, 288.5682373046875, 3.946830987930297851, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Circling Sharpbeak (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+738, 218187, 2552, 14717, 14717, '0', 0, 0, 0, 0, 931.3134765625, -2320.265625, 86.95672607421875, 1.727677345275878906, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Stomper (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+739, 218188, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1000.21075439453125, -2241.165771484375, 83.60195159912109375, 1.48960268497467041, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Meandering Gorger (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+740, 218188, 2552, 14717, 14717, '0', 0, 0, 0, 0, 943.5863037109375, -2316.652099609375, 88.10125732421875, 1.530322432518005371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Meandering Gorger (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+741, 218187, 2552, 14717, 14717, '0', 0, 0, 0, 0, 937.691162109375, -2320.6904296875, 87.306671142578125, 3.785578012466430664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Grazing Stomper (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+742, 218187, 2552, 14717, 14717, '0', 0, 0, 0, 0, 914.26641845703125, -2321.56640625, 86.21811676025390625, 1.126636862754821777, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Grazing Stomper (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+743, 218203, 2552, 14717, 14717, '0', 0, 0, 0, 0, 870.49993896484375, -2275.616943359375, 100.8631515502929687, 5.226121902465820312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+744, 218203, 2552, 14717, 14717, '0', 0, 0, 0, 0, 917.7177734375, -2218.68017578125, 104.02813720703125, 0.804732799530029296, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+745, 227733, 2552, 14717, 14717, '0', 0, 0, 0, 0, 872.3604736328125, -2365.5537109375, 60.46341705322265625, 6.210834026336669921, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+746, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 842.48260498046875, -2403.628662109375, 46.79614639282226562, 5.59807443618774414, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+747, 227733, 2552, 14717, 14717, '0', 0, 0, 0, 0, 776.37701416015625, -2352.105712890625, 97.5460662841796875, 4.9617919921875, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+748, 227638, 2552, 14717, 14717, '0', 0, 0, 0, 0, 864.68743896484375, -2409.40478515625, 57.476409912109375, 1.572954416275024414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56110), -- Sharptalon Kestral (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+749, 227733, 2552, 14717, 14717, '0', 0, 0, 0, 0, 876.0057373046875, -2359.07763671875, 64.142120361328125, 4.335474967956542968, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+750, 222331, 2552, 14717, 14717, '0', 0, 0, 0, 0, 789.75811767578125, -2431.653564453125, 44.85131072998046875, 1.413854956626892089, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Cragstep Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+751, 227733, 2552, 14717, 14717, '0', 0, 0, 0, 0, 819.1141357421875, -2456.9765625, 33.39237594604492187, 4.625354766845703125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+752, 223097, 2552, 14717, 14717, '0', 0, 0, 0, 0, 796.13623046875, -2438.048583984375, 43.558837890625, 3.810193300247192382, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Black Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+753, 227733, 2552, 14717, 14717, '0', 0, 0, 0, 0, 765.72406005859375, -2360.45947265625, 95.0740966796875, 2.438475370407104492, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+754, 227733, 2552, 14717, 14717, '0', 0, 0, 0, 0, 785.14208984375, -2441.255126953125, 43.11858749389648437, 1.357109308242797851, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56110), -- Salt-Ear Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+755, 221681, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1273.0611572265625, -2108.804443359375, 80.26462554931640625, 3.49578714370727539, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Slithering Shalescale (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+756, 217561, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1284.24169921875, -2185.41162109375, 82.21886444091796875, 4.481634140014648437, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+757, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1239.146240234375, -2239.23046875, 95.32434844970703125, 5.873396873474121093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+758, 221681, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1202.4532470703125, -2145.843505859375, 84.556488037109375, 2.287789344787597656, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Slithering Shalescale (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+759, 221681, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1268.6500244140625, -2158.125, 85.31110382080078125, 5.586352348327636718, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Slithering Shalescale (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+760, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1245.8309326171875, -2191.55419921875, 92.31926727294921875, 4.282874584197998046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+761, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1309.99755859375, -2150.29833984375, 106.1304244995117187, 5.106109142303466796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+762, 217561, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1237.200439453125, -2215.44140625, 85.44376373291015625, 0.125323981046676635, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+763, 221681, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1225.9468994140625, -2191.327392578125, 86.29448699951171875, 0.692171573638916015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Slithering Shalescale (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+764, 221681, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1213.1845703125, -2086.808837890625, 79.150390625, 0.790229022502899169, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Slithering Shalescale (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+765, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1156.711181640625, -2222.46142578125, 91.2725830078125, 5.829119682312011718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+766, 217561, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1259.09521484375, -2259.433837890625, 86.28430938720703125, 1.462188005447387695, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+767, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1365.947509765625, -2208.8037109375, 89.5406494140625, 2.627224445343017578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+768, 217561, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1302.8504638671875, -2238.206298828125, 80.2893524169921875, 3.816943883895874023, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+769, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1227.6539306640625, -2266.234375, 91.6827545166015625, 1.135538101196289062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+770, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1129.2047119140625, -2249.150146484375, 93.612701416015625, 2.814770698547363281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+771, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1360.9549560546875, -2328.68701171875, 97.96887969970703125, 2.720865249633789062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+772, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1204.4071044921875, -2340.535400390625, 91.3049774169921875, 1.571016192436218261, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+773, 217561, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1272.2679443359375, -2367.923583984375, 90.2757415771484375, 3.037941932678222656, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+774, 221681, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1385.15185546875, -2235.554931640625, 82.0848541259765625, 2.310583114624023437, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Slithering Shalescale (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+775, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1301.5167236328125, -2415.5400390625, 119.5305633544921875, 0.889292716979980468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+776, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1428.08740234375, -2286.345947265625, 98.8887786865234375, 5.105114459991455078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+777, 217561, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1432.1954345703125, -2306.826171875, 87.836334228515625, 4.322175502777099609, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+778, 217561, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1401.07763671875, -2349.7783203125, 89.41535186767578125, 5.236318588256835937, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+779, 217561, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1317.1751708984375, -2408.774658203125, 95.9046783447265625, 2.047543525695800781, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Brushmane Wolf (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+780, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1429.46630859375, -2421.754150390625, 113.5832290649414062, 1.034433841705322265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+781, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1224.8094482421875, -2366.732177734375, 99.3446044921875, 6.099057674407958984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+782, 221646, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1606.1881103515625, -2496.125244140625, 138.5469207763671875, 3.771027326583862304, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+783, 221681, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1509.42529296875, -2348.584716796875, 99.1911773681640625, 3.36331939697265625, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Slithering Shalescale (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+784, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1425.678466796875, -2484.72705078125, 123.1405258178710937, 1.78106081485748291, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+785, 221526, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1466.8441162109375, -2550.312744140625, 108.7364578247070312, 2.856587886810302734, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+786, 221672, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1461.5010986328125, -2444.6943359375, 93.30942535400390625, 3.66945648193359375, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+787, 221681, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1580.882080078125, -2402.164794921875, 86.2566680908203125, 2.241265058517456054, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Slithering Shalescale (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+788, 221528, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1558.0816650390625, -2529.1962890625, 139.0671844482421875, 3.722594261169433593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+789, 221672, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1416.5164794921875, -2335.0390625, 89.22835540771484375, 1.60398721694946289, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+790, 221672, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1400.089599609375, -2412.0986328125, 93.942962646484375, 5.624844551086425781, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+791, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1615.51416015625, -2509.643310546875, 118.67822265625, 3.93311166763305664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+792, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1586.07470703125, -2479.49951171875, 123.4024734497070312, 1.577674031257629394, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+793, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1460.6912841796875, -2508.66455078125, 109.3509445190429687, 4.402728080749511718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+794, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1554.473388671875, -2502.73291015625, 151.24664306640625, 4.554965972900390625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+795, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1535.7423095703125, -2397.396484375, 104.1547393798828125, 1.949232339859008789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+796, 221672, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1478.9686279296875, -2575.1044921875, 113.0619277954101562, 0.44838029146194458, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+797, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1529.4547119140625, -2512.015869140625, 121.6493682861328125, 0.427219271659851074, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+798, 221528, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1612.935791015625, -2488.982666015625, 125.514312744140625, 3.722594261169433593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+799, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1462.0223388671875, -2530.923828125, 124.9605026245117187, 4.599375724792480468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+800, 221526, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1590.6978759765625, -2517.079345703125, 111.63763427734375, 0.044935517013072967, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+801, 221681, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1558.0970458984375, -2438.572998046875, 96.13666534423828125, 3.494534969329833984, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Slithering Shalescale (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+802, 221528, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1654.892333984375, -2459.96875, 162.428253173828125, 3.722594261169433593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+803, 221646, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1695.75830078125, -2674.74560546875, 162.291015625, 4.859683513641357421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+804, 221526, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1715.2303466796875, -2648.982421875, 104.9131240844726562, 5.828271389007568359, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+805, 221646, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1596.9666748046875, -2603.3134765625, 150.090240478515625, 1.522295594215393066, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+806, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1583.164794921875, -2720.638427734375, 147.5994873046875, 0.775986135005950927, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+807, 221528, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1702.689208984375, -2691.1181640625, 151.698760986328125, 2.300800800323486328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+808, 221525, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1669.521484375, -2731.691650390625, 133.690399169921875, 1.016132831573486328, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Prairie Dog (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+809, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1730.9713134765625, -2731.291015625, 163.5696563720703125, 3.733409404754638671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+810, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1666.897705078125, -2637.903564453125, 132.8386077880859375, 3.700503826141357421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+811, 221526, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1580.6702880859375, -2749.03564453125, 128.41412353515625, 1.98030102252960205, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+812, 221641, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1699.749755859375, -2781.6826171875, 139.7539520263671875, 0.125323981046676635, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Ramolith Stonecrusher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+813, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1682.946533203125, -2711.705322265625, 133.6405487060546875, 0.742197811603546142, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+814, 221526, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1612.162353515625, -2660.87255859375, 122.3037033081054687, 1.617728590965270996, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+815, 221672, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1615.2589111328125, -2549.45556640625, 106.90521240234375, 0.17670886218547821, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+816, 221526, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1633.396484375, -2799.9208984375, 130.3262176513671875, 1.67440342903137207, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+817, 221519, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1619.27685546875, -2617.1494140625, 128.8160400390625, 0.597659945487976074, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+818, 221526, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1583.955810546875, -2701.1162109375, 126.7601318359375, 5.112284183502197265, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+819, 221644, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1641.4781494140625, -2633.951904296875, 135.6802825927734375, 3.988091230392456054, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+820, 221672, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1555.2872314453125, -2626.25, 112.0498428344726562, 3.834378957748413085, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Ramolith Curlhorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+821, 221525, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1749.8839111328125, -2628.239013671875, 101.6381301879882812, 4.751400947570800781, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Prairie Dog (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+822, 221526, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1809.5989990234375, -2698.30029296875, 119.03271484375, 4.900724411010742187, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56196), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+823, 221646, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1814.253662109375, -2740.37890625, 133.5594635009765625, 3.545953750610351562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56196), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+824, 221525, 2552, 14717, 14717, '0', '0', 0, 0, 0, 1823.54345703125, -2656.597412109375, 120.5210723876953125, 4.677245140075683593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56196); -- Prairie Dog (Area: Isle of Dorn - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+824;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 438, 0, 0, 0, 0, ''), -- Mana-Flecked Crawler
(@CGUID+13, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+23, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+30, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+31, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+34, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+38, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+45, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 438, 0, 0, 0, 0, ''), -- Mana-Flecked Crawler
(@CGUID+68, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 438, 0, 0, 0, 0, ''), -- Mana-Flecked Crawler
(@CGUID+79, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+93, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 438, 0, 0, 0, 0, ''), -- Mana-Flecked Crawler
(@CGUID+101, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+104, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+113, 0, 0, 0, 0, 0, 1, 0, 438, 0, 0, 0, 0, ''), -- Mana-Flecked Crawler
(@CGUID+122, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+125, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+132, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+138, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+139, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+140, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+146, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+158, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+159, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+160, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+170, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+172, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+176, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+177, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Scavenging Falcon
(@CGUID+279, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Regal Plainshawk
(@CGUID+283, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Regal Plainshawk
(@CGUID+288, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Regal Plainshawk
(@CGUID+292, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Soaring Plainshawk
(@CGUID+293, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Soaring Plainshawk
(@CGUID+294, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Soaring Plainshawk
(@CGUID+295, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Soaring Plainshawk
(@CGUID+300, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Sandscale Riplisk
(@CGUID+305, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Dire Stormhowl
(@CGUID+306, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Dire Stormhowl
(@CGUID+308, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Sandscale Riplisk
(@CGUID+310, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Dire Stormhowl
(@CGUID+311, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '106562'), -- Wild Stormhowl - 106562 - Cosmetic - Sleep Zzz Breakable
(@CGUID+312, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '106562'), -- Wild Stormhowl - 106562 - Cosmetic - Sleep Zzz Breakable
(@CGUID+321, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Dire Stormhowl
(@CGUID+323, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Dire Stormhowl
(@CGUID+326, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Dire Stormhowl
(@CGUID+327, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '106562'), -- Wild Stormhowl - 106562 - Cosmetic - Sleep Zzz Breakable
(@CGUID+328, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '106562'), -- Wild Stormhowl - 106562 - Cosmetic - Sleep Zzz Breakable
(@CGUID+329, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Dire Stormhowl
(@CGUID+335, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '106562'), -- Wild Stormhowl - 106562 - Cosmetic - Sleep Zzz Breakable
(@CGUID+362, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Mosspelt Ramolith
(@CGUID+364, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Mosspelt Ramolith
(@CGUID+376, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Mosspelt Ramoli
(@CGUID+405, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Regal Plainshawk
(@CGUID+424, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Regal Plainshawk
(@CGUID+428, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+430, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+431, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+432, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+437, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+438, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+440, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+441, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+442, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+447, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+453, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+454, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+456, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+459, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+462, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+464, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+465, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+467, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+472, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+474, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+549, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Mosspelt Sheep
(@CGUID+560, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Brushmane Wolf
(@CGUID+603, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Redwing Falcon
(@CGUID+607, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Redwing Falcon
(@CGUID+641, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Redwing Falcon
(@CGUID+740, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '106562'), -- Meandering Gorger - 106562 - Cosmetic - Sleep Zzz Breakable
(@CGUID+741, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '106562'), -- Grazing Stomper - 106562 - Cosmetic - Sleep Zzz Breakable
(@CGUID+788, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Soaring Plainshawk
(@CGUID+798, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Soaring Plainshawk
(@CGUID+802, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Soaring Plainshawk
(@CGUID+807, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Soaring Plainshawk

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 433850, 2552, 14717, 14774, '0', 0, 0, 1502.3316650390625, -1270.5416259765625, 9.650395393371582031, 2.897245407104492187, 0, 0, 0.99254608154296875, 0.121869951486587524, 120, 255, 1, 56110), -- Abandoned Hovel (Area: Tranquil Strand - Difficulty: 0) CreateObject1
(@OGUID+1, 463632, 2552, 14717, 14717, '0', 0, 0, 1426.454833984375, -413.55035400390625, 79.73284912109375, 0, 0, 0, 0, 1, 120, 255, 1, 56110), -- Falcon Nest (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@OGUID+2, 463632, 2552, 14717, 14717, '0', 0, 0, 1404.907958984375, -713.05731201171875, 107.0956802368164062, 0, 0, 0, 0, 1, 120, 255, 1, 56110), -- Falcon Nest (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@OGUID+3, 463632, 2552, 14717, 14717, '0', 0, 0, 1381.49658203125, -705.982666015625, 101.7143325805664062, 0, 0, 0, 0, 1, 120, 255, 1, 56110), -- Falcon Nest (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@OGUID+4, 463632, 2552, 14717, 14717, '0', 0, 0, 1534.4444580078125, -764.623291015625, 76.69876861572265625, 0, 0, 0, 0, 1, 120, 255, 1, 56110), -- Falcon Nest (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@OGUID+5, 463632, 2552, 14717, 14717, '0', 0, 0, 1291.9305419921875, -1194.8697509765625, 96.20166778564453125, 0, 0, 0, 0, 1, 120, 255, 1, 56110); -- Falcon Nest (Area: Isle of Dorn - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (221519 /*221519 (Fluttering Sapphire)*/, 226885 /*226885 (Bunny Prime - Empower (DNT))*/, 223852 /*223852 (Babbling Book) - (DNT) Elemental Aura*/, 226909 /*226909 (Frostfire Elemental) - Elemental (DNT)*/, 229088 /*229088 (Scavenging Falcon)*/,218119 /*218119 (Undisciplined Earthen) - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS)*/, 218118 /*218118 (Undisciplined Earthen) - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS)*/,222329 /*222329 (Regal Plainshawk)*/, 222757 /*222757 (Shalewing Devourer)*/, 222347 /*222347 (Gnashing Rockwing)*/, 222322 /*222322 (Hungry Plainshawk)*/, 221527 /*221527 (Regal Plainshawk)*/, 225026, 225040, 212407);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(221519, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 221519 (Fluttering Sapphire)
(226885, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 226885 (Bunny Prime - Empower (DNT))
(223852, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449779'), -- 223852 (Babbling Book) - (DNT) Elemental Aura
(226909, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '456495'), -- 226909 (Frostfire Elemental) - Elemental (DNT)
(229088, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 229088 (Scavenging Falcon)
(218119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436397'), -- 218119 (Undisciplined Earthen) - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS)
(218118, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436397'), -- 218118 (Undisciplined Earthen) - [DNT] 11.0 Z1 - Max Level - 07A - Trainee Rename (RPS)
(222329, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222329 (Regal Plainshawk)
(222757, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222757 (Shalewing Devourer)
(222347, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222347 (Gnashing Rockwing)
(222322, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222322 (Hungry Plainshawk)
(221527, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 221527 (Regal Plainshawk)
(225026, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 225026 (Sandscale Riplisk)
(225040, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 225040 (Mosspelt Ramolith)
(212407, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- 212407 (Enter Delve)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (433850 /*Abandoned Hovel*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(433850, 0, 1048608, 0, 0); -- Abandoned Hovel

-- Template
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215093; -- Cragstep Mouse
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=223093; -- Granite Ramolith
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=222774; -- Fragrant Stonelamb
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221519; -- Fluttering Sapphire
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1073741824, `flags_extra` = 128 WHERE `entry`=226885; -- Bunny Prime - Empower (DNT)
UPDATE `creature_template` SET `faction`=190, `speed_walk`=0.400000005960464477, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=229092; -- Mosswool Grazer
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1090519040 WHERE `entry`=228149; -- Woldclaimed Freysworn
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=223852; -- Babbling Book
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=223098; -- Cobalt Ramolith
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1090519040, `flags_extra` = 128 WHERE `entry`=217984; -- Rumble Stalker [DNT]
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=222747; -- Mossy Snail
UPDATE `creature_template` SET `faction`=1932, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=226909; -- Frostfire Elemental
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=222036; -- Sea Slug
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=223799; -- Shard of Dalaran
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=229088; -- Scavenging Falcon
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223797; -- Lingering Spark
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223798; -- Mana Fragment
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=220067; -- Salmoncrab
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=229087; -- Mana-Flecked Crawler
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=220038; -- Shattered Crystal
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217735; -- Charged Storm Wolf
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=2214592512 WHERE `entry`=225040; -- Mosspelt Ramolith
UPDATE `creature_template` SET `faction`=2832, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=224972; -- Dire Stormhowl
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry` IN (218118, 218119); -- Undisciplined Earthen
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=222780; -- Fragrant Stonelamb
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=223097; -- Black Ramolith
UPDATE `creature_template` SET `faction`=190, `speed_walk`=0.400000005960464477, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=222419; -- Mosspelt Sheep
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=221524; -- Gemwing
UPDATE `creature_template` SET `faction`=31, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=222331; -- Cragstep Mouse
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16777216, `VehicleId`=8274 WHERE `entry`=212160; -- Cart
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222156; -- Scavenging Sandsnapper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=134217728 WHERE `entry`=222280; -- Voltscale Borer
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=222035; -- Softshell Pincher
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222057; -- Isle Gull
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223059; -- Gizwig
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223063; -- Hagenbran
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=223094; -- Cobalt Ramolith
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223057; -- Trained Sandsnapper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222312; -- Scavenging Sandsnapper
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=224800; -- Salty Gull
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221528; -- Soaring Plainshawk
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222310; -- Isle Gull
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry` IN (221527, 222329); -- Regal Plainshawk
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1090519040 WHERE `entry`=223558; -- Skyriding Glyph
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222302; -- Sandscale Riplisk
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=2214592512 WHERE `entry`=225026; -- Sandscale Riplisk
UPDATE `creature_template` SET `faction`=2106, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222322; -- Hungry Plainshawk
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=222757; -- Shalewing Devourer
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222347; -- Gnashing Rockwing
UPDATE `creature_template` SET `faction`=2832, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222332; -- Wild Stormhowl
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=222301; -- Damp Sandcourser
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=219550; -- Bronze Timekeeper
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221526; -- Mosspelt Ramolith
UPDATE `creature_template` SET `faction`=2832, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221678; -- Wild Stormhowl
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry` IN (204341, 222759); -- Ravenous Shalewing
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `speed_walk`=1.60000002384185791, `speed_run`=0.571428596973419189, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=228070; -- Odarrok
UPDATE `creature_template` SET `faction`=1712, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221672; -- Ramolith Curlhorn
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=228073; -- Wahrvren
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221644; -- Soaring Plainshawk
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1090519040 WHERE `entry`=212407; -- Enter Delve
UPDATE `creature_template` SET `faction`=2136, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221684; -- Crested Shalehorn
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223657; -- Igneous Elemental
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217405; -- Shroom Scavenger
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=3221225472 WHERE `entry`=217420; -- Decomposing Fungarian
UPDATE `creature_template` SET `faction`=2643, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=217404; -- Persistent Forager
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=217428; -- Agitated Rockpercher
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67633152 WHERE `entry` IN (229817, 229816); -- Ambushing Swarmer
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=224730; -- Elemental Targeting
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=227115; -- Sandy Scuttler
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=222499; -- Mossy Snail
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=214946; -- Vinechewer Ramolith
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=215036; -- Redwing Falcon
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=2147483648 WHERE `entry`=222841; -- Dead Abductor
UPDATE `creature_template` SET `faction`=190, `speed_walk`=0.400000005960464477, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=227127; -- Grazing Mosswool
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212578; -- Agaric Spreader
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212579; -- Scarlet Stinkcap
UPDATE `creature_template` SET `faction`=2575, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=214945; -- Moss-Draped Ramolith
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555264, `unit_flags2`=67110912, `unit_flags3`=1090551808 WHERE `entry`=220026; -- Slumbering Mountain Giant
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=134217728 WHERE `entry`=222040; -- Opalooze Mollusc
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223648; -- Betta
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215035; -- Freefoot Mouse
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215038; -- Thistlestar
UPDATE `creature_template` SET `faction`=3407, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=217961; -- Hreka
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=212708; -- Freysworn Cruton
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=222781; -- Sandstone Mosswool
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=212255; -- Zarein
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `VehicleId`=8512 WHERE `entry`=223084; -- Moss-Draped Ramolith
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223238; -- Swift Cloudrook
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=225323; -- Ginger
UPDATE `creature_template` SET `faction`=3407, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=218535; -- Germira
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=218729; -- Yeonin
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223652; -- Kurron
UPDATE `creature_template` SET `faction`=2952, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=217561; -- Brushmane Wolf
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=227790; -- Kothilde
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223244; -- Unbound Miner
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215034; -- Salt-Ear Ferret
UPDATE `creature_template` SET `faction`=2575, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108896 WHERE `entry`=218191; -- Moss-Draped Ramolith
UPDATE `creature_template` SET `faction`=3407, `npcflag`=4226, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=224424; -- Velkura
UPDATE `creature_template` SET `faction`=3407, `npcflag`=81, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217447; -- Gandorhil
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=219264; -- Bloodmaw
UPDATE `creature_template` SET `faction`=3407, `npcflag`=80, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217446; -- Shardgar
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223649; -- Maluc
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=223242; -- Ama
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212928; -- Dalaran Sewer Turtle
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=229379; -- Unbound Villager
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=212925; -- Dalaran Sewer Rat
UPDATE `creature_template` SET `faction`=3408, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=217450; -- Unbound Protector
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=223240; -- Ana
UPDATE `creature_template` SET `faction`=35, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217439; -- Iridi
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=227733; -- Salt-Ear Ferret
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=223343; -- Tiny Cragling
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=223346; -- Ridge
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=223090; -- Bedrock Stonecharger
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=229705; -- Docile Cloudrook
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=223344; -- Stratus
UPDATE `creature_template` SET `faction`=3407, `npcflag`=129, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=223446; -- Collector Dyna
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=222775; -- Sandstone Mosswool
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=134742016 WHERE `entry`=229813; -- Disturbed Krolusk
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=214465; -- Pearl Farmer
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=214464; -- Dorbund
UPDATE `creature_template` SET `faction`=3407, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=214444; -- Aggartha
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=212255; -- Zarein
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1090519040 WHERE `entry`=212407; -- Enter Delve
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1090519040 WHERE `entry`=223558; -- Skyriding Glyph
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16777216, `VehicleId`=8274 WHERE `entry`=212160; -- Cart
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=214946; -- Vinechewer Ramolith
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `VehicleId`=8512 WHERE `entry`=223084; -- Moss-Draped Ramolith
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=223093; -- Granite Ramolith
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555264, `unit_flags2`=67110912, `unit_flags3`=1090551808 WHERE `entry`=220026; -- Slumbering Mountain Giant
UPDATE `creature_template` SET `faction`=2575, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=214945; -- Moss-Draped Ramolith
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=222780; -- Fragrant Stonelamb
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=218201; -- Circling Sharpbeak
UPDATE `creature_template` SET `faction`=190, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=67108896 WHERE `entry`=218194; -- Vinechewer Ramolith
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=228072; -- Gartwin
UPDATE `creature_template` SET `faction`=2952, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108896 WHERE `entry`=218203; -- Brushmane Wolf
UPDATE `creature_template` SET `faction`=190, `speed_walk`=0.400000005960464477, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=227127; -- Grazing Mosswool
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221519; -- Fluttering Sapphire
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=218188; -- Meandering Gorger
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215035; -- Freefoot Mouse
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=218187; -- Grazing Stomper
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1090519040 WHERE `entry`=228149; -- Woldclaimed Freyswor
UPDATE `creature_template` SET `faction`=2952, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=218205; -- Sparking Sharptooth
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=227638; -- Sharptalon Kestral
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=225270; -- Crested Shalehorn
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=134217728 WHERE `entry`=222155; -- Opalooze Mollusc
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=221681; -- Slithering Shalescale
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1090519040, `flags_extra` = 128 WHERE `entry`=229335; -- Electricity Stalker [DNT]
UPDATE `creature_template` SET `faction`=31, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=221525; -- Prairie Dog
UPDATE `creature_template` SET `faction`=31, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=221645; -- Freefoot Mouse
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=219547; -- Bronze Timekeeper
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=224150; -- Nerubian Skirmisher
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222019; -- Shalescale Striker
UPDATE `creature_template` SET `faction`=2106, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221646; -- Hungry Plainshawk
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=224149; -- Nerubian Webspinner
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221642; -- Mosspelt Ramolith
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=221641; -- Ramolith Stonecrusher
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000 WHERE `entry`=229334; -- Kordac

DELETE FROM `gameobject_template` WHERE `entry` IN (414318 /*Blessing Blossom*/, 451669 /*Glimmerpool*/, 444056 /*Earthen Hammers and Shields*/, 444055 /*Earthen Spears*/, 444054 /*Earthen Axes*/, 443649 /*11.0 Z1 - Max Level - Fishing Pole (RPS)*/, 443633 /*Earthen Crossbows*/, 414319 /*Arathor's Spear*/, 441170 /*Dormant Rock Giant*/, 433850 /*Abandoned Hovel*/, 441166 /*Dormant Rock Giant*/, 441162 /*Dormant Rock Giant*/, 441163 /*Dormant Rock Giant*/, 451677 /*Festering Rotpool*/, 451670 /*Calm Surfacing Ripple*/, 413049 /*Ironclaw*/, 451672 /*Stargazer Swarm*/, 454502 /*Radiant Prism Crystal*/, 444197 /*Arcane Crystal*/, 441785 /*441785*/, 433643 /*Cleanse Horrific Poison (DNT)*/, 414325 /*Crystallized Mycobloom*/, 454063 /*Mycobloom*/, 441956 /*Earthen Bottle*/, 413874 /*Rich Bismuth*/, 463632 /*Falcon Nest*/, 422531 /*Disturbed Earth*/, 429692 /*Chair*/, 429691 /*Bench*/, 429689 /*Bench*/, 446249 /*Bench*/, 446253 /*Bench*/, 446193 /*Chair*/, 446233 /*Bench*/, 446154 /*Chair*/, 466677 /*Stool*/, 446241 /*Bench*/, 446261 /*Bench*/, 446238 /*Bench*/, 466209 /*Chair*/, 466213 /*Chair*/, 446259 /*Bench*/, 466210 /*Chair*/, 446246 /*Bench*/, 446243 /*Bench*/, 465869 /*Chair*/, 446194 /*Chair*/, 446258 /*Bench*/, 446235 /*Bench*/, 433036 /*Chair*/, 446158 /*Chair*/, 433037 /*Forge*/, 433035 /*Anvil*/, 446250 /*Bench*/, 446234 /*Bench*/, 433038 /*Mailbox*/, 446247 /*Bench*/, 446254 /*Bench*/, 446190 /*Chair*/, 446257 /*Bench*/, 446156 /*Chair*/, 446195 /*Bench*/, 446255 /*Bench*/, 446205 /*Chair*/, 446252 /*Bench*/, 446187 /*Chair*/, 466211 /*Chair*/, 466212 /*Chair*/, 465705 /*Cooking Fire*/, 446155 /*Chair*/, 433039 /*Chair*/, 466676 /*Stool*/, 446239 /*Bench*/, 466215 /*Chair*/, 446159 /*Chair*/, 446244 /*Bench*/, 446191 /*Chair*/, 446251 /*Bench*/, 446157 /*Chair*/, 446188 /*Chair*/, 446260 /*Bench*/, 446192 /*Chair*/, 466214 /*Chair*/, 446248 /*Bench*/, 446204 /*Chair*/, 446189 /*Chair*/, 439457 /*Elevator Lever*/, 414379 /*Door*/, 464019 /*Stones of the Wolds Part 1*/, 456743 /*Dornogal Pike*/, 459427 /*Healing Bubbles*/, 463992 /*Observational Notes: Stormrooks*/, 422668 /*Bucket of Clay*/, 466229 /*Adelgonn's Journal*/, 446236 /*Bench*/, 466678 /*Stool*/, 446256 /*Bench*/, 446245 /*Bench*/, 446240 /*Bench*/, 466216 /*Chair*/, 446242 /*Bench*/, 446237 /*Bench*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(414318, 50, 93129, 'Blessing Blossom', '', '', '', 1, 3682, 120689, 0, 0, 30, 60, 30, 0, 0, 0, 0, 0, 0, 1, 427986, 0, 0, 0, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Blessing Blossom
(451669, 25, 85928, 'Glimmerpool', '', '', '', 1, 4, 125066, 3, 5, 1628, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Glimmerpool
(444056, 10, 86951, 'Earthen Hammers and Shields', 'questinteract', '', '', 0.800000011920928955, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 448108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Earthen Hammers and Shields
(444055, 10, 86951, 'Earthen Spears', 'questinteract', '', '', 0.800000011920928955, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 448114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Earthen Spears
(444054, 10, 86951, 'Earthen Axes', 'questinteract', '', '', 0.800000011920928955, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 448112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Earthen Axes
(443649, 5, 71370, '11.0 Z1 - Max Level - Fishing Pole (RPS)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- 11.0 Z1 - Max Level - Fishing Pole (RPS)
(443633, 10, 86951, 'Earthen Crossbows', 'questinteract', '', '', 0.800000011920928955, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 448117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Earthen Crossbows
(414319, 50, 87328, 'Arathor\'s Spear', '', '', '', 1, 3682, 120689, 0, 0, 30, 60, 30, 0, 0, 0, 0, 0, 0, 1, 427986, 0, 0, 0, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Arathor's Spear
(441170, 43, 90195, 'Dormant Rock Giant', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Dormant Rock Giant
(433850, 43, 89005, 'Abandoned Hovel', '', '', '', 1, -1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Abandoned Hovel
(441166, 43, 90199, 'Dormant Rock Giant', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Dormant Rock Giant
(441162, 43, 90195, 'Dormant Rock Giant', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Dormant Rock Giant
(441163, 43, 90196, 'Dormant Rock Giant', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Dormant Rock Giant
(451677, 25, 10993, 'Festering Rotpool', '', '', '', 1, 4, 125058, 3, 5, 1628, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Festering Rotpool
(451670, 25, 86062, 'Calm Surfacing Ripple', '', '', '', 1, 4, 125065, 3, 5, 1628, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Calm Surfacing Ripple
(413049, 50, 89948, 'Ironclaw', '', '', '', 0.85000002384185791, 3681, 120476, 0, 0, 60, 70, 30, 0, 0, 0, 0, 0, 0, 1, 427983, 0, 0, 0, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Ironclaw
(451672, 25, 86062, 'Stargazer Swarm', '', '', '', 1, 4, 125063, 3, 5, 1628, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Stargazer Swarm
(454502, 3, 26439, 'Radiant Prism Crystal', 'questinteract', 'Collecting', '', 0.400000005960464477, 2124, 125891, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2462, 56110), -- Radiant Prism Crystal
(444197, 10, 86359, 'Arcane Crystal', 'questinteract', 'Inspecting', '', 2, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 449953, 0, 0, 1, 157298, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2837, 56110), -- Arcane Crystal
(433643, 6, 9510, 'Cleanse Horrific Poison (DNT)', '', '', '', 1, 0, 0, 6, 440896, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Cleanse Horrific Poison (DNT)
(414325, 50, 87199, 'Crystallized Mycobloom', '', '', '', 1, 3682, 120689, 0, 0, 60, 100, 30, 0, 0, 0, 0, 0, 0, 1, 427986, 0, 0, 0, 10, 0, 433643, 0, 0, 1, 0, 25182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Crystallized Mycobloom
(454063, 50, 87197, 'Mycobloom', '', '', '', 1, 3682, 120689, 0, 0, 15, 30, 30, 0, 0, 0, 0, 0, 0, 1, 427986, 0, 0, 0, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Mycobloom
(441956, 10, 90486, 'Earthen Bottle', 'questinteract', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 446524, 0, 0, 0, 0, 0, 0, 0, 0, 34707, 1, 0, 121568, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Earthen Bottle
(413874, 50, 89862, 'Rich Bismuth', '', '', '', 1, 3681, 120476, 0, 0, 45, 55, 30, 0, 0, 0, 0, 0, 0, 1, 427983, 0, 0, 0, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 56110), -- Rich Bismuth
(463632, 5, 74920, 'Falcon Nest', '', '', '', 0.349999994039535522, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2838, 56110), -- Falcon Nest
(422531, 10, 87595, 'Disturbed Earth', 'questinteract', 'Digging', '', 1, 3723, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 431909, 0, 0, 0, 35059, 0, 0, 0, 0, 0, 0, 0, 0, 1, 6221, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Disturbed Earth
(429692, 7, 87468, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(429691, 7, 88281, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(429689, 7, 88281, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446249, 7, 88281, 'Bench', '', '', '', 0.999999463558197021, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446253, 7, 88281, 'Bench', '', '', '', 0.999999701976776123, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446193, 7, 87468, 'Chair', '', '', '', 0.999999523162841796, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446233, 7, 88281, 'Bench', '', '', '', 0.999999463558197021, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446154, 7, 87468, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(466677, 7, 88391, 'Stool', '', '', '', 0.999999582767486572, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Stool
(446241, 7, 88281, 'Bench', '', '', '', 0.999999582767486572, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446261, 7, 88281, 'Bench', '', '', '', 0.999999582767486572, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446238, 7, 88281, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(466209, 7, 88391, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(466213, 7, 88391, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446259, 7, 88281, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(466210, 7, 88391, 'Chair', '', '', '', 0.999999284744262695, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446246, 7, 88281, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446243, 7, 88281, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(465869, 7, 88391, 'Chair', '', '', '', 0.999999582767486572, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446194, 7, 87468, 'Chair', '', '', '', 0.999999403953552246, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446258, 7, 88281, 'Bench', '', '', '', 0.99999934434890747, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446235, 7, 88281, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(433036, 7, 87468, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446158, 7, 87468, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(433037, 8, 88778, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Forge
(433035, 8, 88784, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Anvil
(446250, 7, 88281, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446234, 7, 88281, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(433038, 19, 87471, 'Mailbox', '', '', '', 1, 4383, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Mailbox
(446247, 7, 88281, 'Bench', '', '', '', 0.999999284744262695, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446254, 7, 88281, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446190, 7, 87468, 'Chair', '', '', '', 0.99999934434890747, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446257, 7, 88281, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446156, 7, 87468, 'Chair', '', '', '', 0.999999523162841796, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446195, 7, 88281, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446255, 7, 88281, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446205, 7, 87468, 'Chair', '', '', '', 0.999999284744262695, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446252, 7, 88281, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446187, 7, 87468, 'Chair', '', '', '', 0.999999284744262695, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(466211, 7, 88391, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(466212, 7, 88391, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(465705, 8, 51318, 'Cooking Fire', '', '', '', 1.389513492584228515, 4, 10, 215916, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Cooking Fire
(446155, 7, 87468, 'Chair', '', '', '', 0.99999934434890747, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(433039, 7, 87468, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(466676, 7, 88391, 'Stool', '', '', '', 0.999999642372131347, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Stool
(446239, 7, 88281, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(466215, 7, 88391, 'Chair', '', '', '', 0.999999582767486572, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446159, 7, 87468, 'Chair', '', '', '', 0.999999582767486572, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446244, 7, 88281, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446191, 7, 87468, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446251, 7, 88281, 'Bench', '', '', '', 0.999999284744262695, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446157, 7, 87468, 'Chair', '', '', '', 0.999999523162841796, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446188, 7, 87468, 'Chair', '', '', '', 0.99999934434890747, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446260, 7, 88281, 'Bench', '', '', '', 0.999999463558197021, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446192, 7, 87468, 'Chair', '', '', '', 0.999999284744262695, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(466214, 7, 88391, 'Chair', '', '', '', 0.999999582767486572, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446248, 7, 88281, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446204, 7, 87468, 'Chair', '', '', '', 0.99999934434890747, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446189, 7, 87468, 'Chair', '', '', '', 0.999999403953552246, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(439457, 10, 86851, 'Elevator Lever', 'interact', 'Activating', '', 1, 3772, 0, 0, 1, 0, 0, 0, 0, 0, 0, 443392, 0, 0, 0, 27700, 0, 0, 0, 0, 0, 1, 0, 126312, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2797, 56110), -- Elevator Lever
(414379, 5, 85630, 'Door', '', '', '', 0.899999976158142089, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Door
(464019, 10, 77374, 'Stones of the Wolds Part 1', 'inspect', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 9587, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Stones of the Wolds Part 1
(456743, 5, 93290, 'Dornogal Pike', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Dornogal Pike
(459427, 5, 9355, 'Healing Bubbles', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Healing Bubbles
(463992, 10, 89637, 'Observational Notes: Stormrooks', 'inspect', '', '', 0.25, 0, 0, 0, 3000, 0, 0, 0, 9556, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Observational Notes: Stormrooks
(422668, 5, 87637, 'Bucket of Clay', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bucket of Clay
(466229, 10, 90312, 'Adelgonn\'s Journal', 'inspect', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 9634, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Adelgonn's Journal
(446236, 7, 88281, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(466678, 7, 88391, 'Stool', '', '', '', 0.999999642372131347, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Stool
(446256, 7, 88281, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446245, 7, 88281, 'Bench', '', '', '', 0.999999463558197021, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446240, 7, 88281, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(466216, 7, 88391, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Chair
(446242, 7, 88281, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110), -- Bench
(446237, 7, 88281, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56110); -- Bench

-- Model Info
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (120662, 119083, 119070, 114794, 119086, 119087, 121447, 119764, 120664, 119170, 114102, 115110, 114826, 119068, 119082,114791, 114821, 114827, 114824, 114818, 114828, 114817, 114816, 114800, 112188, 106697, 91387, 117494, 117481, 117487, 114937, 117484, 117497, 114916, 114935, 117491, 114934, 114304, 112187,115109, 113610, 115113, 115111, 115108, 115112, 114819, 119067, 119066, 117496, 117483, 114927, 114932, 117485, 114659, 114928, 120661, 119074, 119162, 119161, 114654, 114302, 121445, 91385, 114789, 112189, 114938, 114914, 114915, 114941);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(120662, 0.497622579336166381, 0.60000002384185791, 0, 56110),
(119083, 0.764442086219787597, 3, 0, 56110),
(119070, 0.509628057479858398, 2, 0, 56110),
(114794, 0.227499991655349731, 0.649999976158142089, 0, 56110),
(119086, 0.764442086219787597, 3, 0, 56110),
(119087, 0.764442086219787597, 3, 0, 56110),
(121447, 0.347000002861022949, 1.5, 0, 56110),
(119764, 0.219570502638816833, 0, 0, 56110),
(120664, 0.497622579336166381, 0.60000002384185791, 0, 56110),
(119170, 0.255529791116714477, 0.5, 0, 56110),
(114102, 0.108170777559280395, 0.450000017881393432, 0, 56110),
(115110, 0.683102548122406005, 0.875, 0, 56110),
(114826, 1.339599251747131347, 1.75, 0, 56110),
(119068, 0.509628057479858398, 2, 0, 56110),
(119082, 0.764442086219787597, 3, 0, 56110),
(114791, 0.227499991655349731, 0.649999976158142089, 0, 56110),
(114821, 1.339599251747131347, 1.75, 0, 56110),
(114827, 1.339599251747131347, 1.75, 0, 56110),
(114824, 1.339599251747131347, 1.75, 0, 56110),
(114818, 1.339599251747131347, 1.75, 0, 56110),
(114828, 1.339599251747131347, 1.75, 0, 56110),
(114817, 1.339599251747131347, 1.75, 0, 56110),
(114816, 1.339599251747131347, 1.75, 0, 56110),
(114800, 1.994137406349182128, 2.40000009536743164, 0, 56110),
(112188, 0.700270593166351318, 0.300000011920928955, 0, 56110),
(106697, 1.661781191825866699, 2, 0, 56110),
(91387, 0.765362918376922607, 0, 0, 56110),
(117494, 1.65874183177947998, 2, 0, 56110),
(117481, 1.65874183177947998, 2, 0, 56110),
(117487, 1.65874183177947998, 2, 0, 56110),
(114937, 1.990490317344665527, 2.40000009536743164, 0, 56110),
(117484, 1.65874183177947998, 2, 0, 56110),
(117497, 1.65874183177947998, 2, 0, 56110),
(114916, 1.990490317344665527, 2.40000009536743164, 0, 56110),
(114935, 1.990490317344665527, 2.40000009536743164, 0, 56110),
(117491, 1.65874183177947998, 2, 0, 56110),
(114934, 1.990490317344665527, 2.40000009536743164, 0, 56110),
(114304, 0.724426746368408203, 0, 0, 56110),
(112187, 0.700270593166351318, 0.300000011920928955, 0, 56110),
(115109, 0.195172175765037536, 0.25, 0, 56110),
(113610, 1.55254065990447998, 1, 0, 56110),
(115113, 0.195172175765037536, 0.25, 0, 56110),
(115111, 0.195172175765037536, 0.25, 0, 56110),
(115108, 0.195172175765037536, 0.25, 0, 56110),
(115112, 0.195172175765037536, 0.25, 0, 56110),
(114819, 1.339599251747131347, 1.75, 0, 56110),
(119067, 0.509628057479858398, 2, 0, 56110),
(119066, 0.509628057479858398, 2, 0, 56110),
(117496, 1.990490198135375976, 2.40000009536743164, 0, 56110),
(117483, 1.990490317344665527, 2.40000009536743164, 0, 56110),
(114927, 1.65874183177947998, 2, 0, 56110),
(114932, 1.65874183177947998, 2, 0, 56110),
(117485, 1.990490198135375976, 2.40000009536743164, 0, 56110),
(114659, 1.990490317344665527, 2.40000009536743164, 0, 56110),
(114928, 1.65874183177947998, 2, 0, 56110),
(120661, 0.497622579336166381, 0.60000002384185791, 0, 56110),
(119074, 0.509628057479858398, 2, 0, 56110),
(119162, 0.347000002861022949, 1.5, 0, 56110),
(119161, 0.347000002861022949, 1.5, 0, 56110),
(114654, 1.086640119552612304, 0, 0, 56110),
(114302, 0.724426746368408203, 0, 0, 56110),
(121445, 0.347000002861022949, 1.5, 0, 56110),
(91385, 0.765362918376922607, 0, 0, 56110),
(114789, 1.661781191825866699, 2, 0, 56110),
(112189, 0.200000002980232238, 0.25, 0, 56196),
(114938, 1.990490317344665527, 2.40000009536743164, 0, 56196),
(114914, 1.990490317344665527, 2.40000009536743164, 0, 56196),
(114915, 1.990490317344665527, 2.40000009536743164, 0, 56196),
(114941, 1.990490317344665527, 2.40000009536743164, 0, 56196);

UPDATE `creature_model_info` SET `VerifiedBuild`=56110 WHERE `DisplayID` IN (4960, 11686, 107538, 106699, 109354, 106700, 106691, 109350);
UPDATE `creature_model_info` SET `BoundingRadius`=1.384275436401367187, `CombatReach`=1.5, `VerifiedBuild`=56110 WHERE `DisplayID`=103218;

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (215093,223093,222774,221519,229092,228149,226885,223852,223098,217984,222747,226909,223799,222036,229088,229087,223798,223797,220067,220038,217735,225040,224972,218119,218118,222780,223097,221524,222419,222331,212160,222156,222280,222035,222057,223094,223063,223059,223057,222312,224800,222310,221528,221527,222322,223558,222347,222757,225026,222329,222332,222302,222301,219550,221526,221678,228070,221672,222759,228073,221644,212407,221684,223657,224730,227115,222499,214946,215036,222841,227127,212579,212578,217420,217405,217428,217404,214945,220026,222040,223459,215765,223648,215035,212255,223084,223238,222781,217961,215038,212708,227790,225323,223652,223244,218729,218535,217561,215034,218191,210759,217447,212928,223240,224424,212925,223649,219264,223242,229379,217450,217446,217439,229705,227733,223446,223346,223344,223343,223090,213115,222775,229813,212577,228226,228101,214465,214464,214444,228072,218203,218201,218194,218188,218187,218205,227638,224150,225270,222155,221681,229335,221525,221645,222019,224149,221646,219547,221641,221642,229334));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(215093, 0, 10, 0.200000002980232238, 1, 264557, 0, 0), -- Cragstep Mouse
(223093, 0, 10, 0.200000002980232238, 1, 273893, 0, 0), -- Granite Ramolith
(222774, 0, 10, 0.200000002980232238, 1, 273571, 0, 0), -- Fragrant Stonelamb
(221519, 0, 10, 0.5, 0, 271328, 1, 0), -- Fluttering Sapphire
(229092, 0, 10, 1, 1, 280327, 0, 0), -- Mosswool Grazer
(228149, 0, 10, 12, 1, 279334, 1073741824, 1024), -- Woldclaimed Freysworn
(226885, 0, 9, 1, 1, 278047, 0, 0), -- Bunny Prime - Empower (DNT)
(223852, 0, 10, 7, 1, 274714, 2147483720, 0), -- Babbling Book
(223098, 0, 10, 0.200000002980232238, 1, 273898, 0, 0), -- Cobalt Ramolith
(217984, 0, 10, 1, 1, 267479, 1610612752, 117440582), -- Rumble Stalker [DNT]
(222747, 0, 10, 0.200000002980232238, 1, 273544, 0, 0), -- Mossy Snail
(226909, 0, 10, 4, 1, 278071, 2147483720, 0), -- Frostfire Elemental
(223799, 0, 10, 2, 1, 274661, 512, 0), -- Shard of Dalaran
(222036, 0, 10, 0.200000002980232238, 1, 271856, 0, 0), -- Sea Slug
(229088, 0, 10, 1, 1, 280323, 1, 0), -- Scavenging Falcon
(229087, 0, 10, 1, 1, 280322, 1, 0), -- Mana-Flecked Crawler
(223798, 0, 10, 1, 1, 274660, 0, 0), -- Mana Fragment
(223797, 0, 10, 0.5, 1, 274659, 0, 0), -- Lingering Spark
(220067, 0, 10, 0.200000002980232238, 1, 269673, 0, 0), -- Salmoncrab
(220038, 0, 10, 0.200000002980232238, 1, 269644, 0, 0), -- Shattered Crystal
(217735, 0, 10, 1, 1, 267228, 0, 0), -- Charged Storm Wolf
(225040, 0, 10, 1, 1, 275981, 1, 0), -- Mosspelt Ramolith
(224972, 0, 10, 2, 1, 275913, 0, 0), -- Dire Stormhowl
(218119, 0, 10, 1, 1, 267614, 0, 0), -- Undisciplined Earthen
(218118, 0, 10, 1, 1, 267613, 0, 0), -- Undisciplined Earthen
(222780, 0, 10, 0.200000002980232238, 1, 273577, 0, 0), -- Fragrant Stonelamb
(223097, 0, 10, 0.200000002980232238, 1, 273897, 0, 0), -- Black Ramolith
(221524, 0, 10, 0.200000002980232238, 0, 271333, 0, 0), -- Gemwing
(222419, 0, 10, 1, 1, 272241, 512, 0), -- Mosspelt Sheep
(222331, 0, 10, 0.200000002980232238, 1, 272153, 0, 0), -- Cragstep Mouse
(212160, 0, 10, 1, 1, 261511, 1073741840, 2), -- Cart
(222156, 0, 10, 1, 1, 271976, 1, 0), -- Scavenging Sandsnapper
(222280, 0, 10, 2, 1, 272102, 65537, 0), -- Voltscale Borer
(222035, 0, 10, 0.200000002980232238, 1, 271855, 0, 0), -- Softshell Pincher
(222057, 0, 10, 1, 1, 271877, 1, 0), -- Isle Gull
(223094, 0, 10, 0.200000002980232238, 1, 273894, 0, 0), -- Cobalt Ramolith
(223063, 0, 10, 1, 1, 273861, 0, 0), -- Hagenbran
(223059, 0, 10, 1, 1, 273857, 0, 0), -- Gizwig
(223057, 0, 10, 1, 1, 273855, 0, 0), -- Trained Sandsnapper
(222312, 0, 10, 1, 1, 272134, 1, 0), -- Scavenging Sandsnapper
(224800, 0, 10, 0.5, 1, 275726, 1, 0), -- Salty Gull
(222310, 0, 10, 1, 1, 272132, 1, 0), -- Isle Gull
(221528, 0, 10, 1, 1, 271337, 1, 0), -- Soaring Plainshawk
(221527, 0, 10, 2, 1, 271336, 1, 0), -- Regal Plainshawk
(222322, 0, 10, 1, 1, 272144, 1, 0), -- Hungry Plainshawk
(223558, 0, 10, 1, 1, 274417, 1610612752, 67108870), -- Skyriding Glyph
(222347, 0, 10, 1, 1, 272169, 1, 0), -- Gnashing Rockwing
(222757, 0, 10, 1, 1, 273554, 0, 0), -- Shalewing Devourer
(225026, 0, 10, 1, 1, 275967, 1, 0), -- Sandscale Riplisk
(222329, 0, 10, 2, 1, 272151, 1, 0), -- Regal Plainshawk
(222332, 0, 10, 1, 1, 272154, 1, 0), -- Wild Stormhowl
(222302, 0, 10, 1, 1, 272124, 1, 0), -- Sandscale Riplisk
(222301, 0, 10, 1, 1, 272123, 0, 0), -- Damp Sandcourser
(219550, 0, 10, 1, 1, 269118, 0, 0), -- Bronze Timekeeper
(221526, 0, 10, 1, 1, 271335, 513, 0), -- Mosspelt Ramolith
(221678, 0, 10, 1, 1, 271488, 1, 0), -- Wild Stormhowl
(228070, 0, 10, 1, 1, 279255, 0, 0), -- Odarrok
(221672, 0, 10, 2, 1, 271482, 513, 0), -- Ramolith Curlhorn
(222759, 0, 10, 1, 1, 273556, 0, 0), -- Ravenous Shalewing
(228073, 0, 10, 1, 1, 279258, 0, 0), -- Wahrvren
(221644, 0, 10, 1, 1, 271453, 1, 0), -- Soaring Plainshawk
(212407, 0, 10, 1, 1, 261762, 1744830480, 6), -- Enter Delve
(221684, 0, 10, 1, 1, 271494, 1, 0), -- Crested Shalehorn
(223657, 0, 10, 1, 1, 274516, 0, 0), -- Igneous Elemental
(224730, 0, 10, 1, 1, 275654, 1073742848, 0), -- Elemental Targeting
(227115, 0, 10, 0.200000002980232238, 1, 278280, 0, 0), -- Sandy Scuttler
(222499, 0, 10, 0.200000002980232238, 1, 272321, 0, 0), -- Mossy Snail
(214946, 0, 10, 2, 1, 264404, 513, 0), -- Vinechewer Ramolith
(215036, 0, 10, 1, 1, 264500, 1, 0), -- Redwing Falcon
(222841, 0, 10, 1, 1, 273638, 0, 0), -- Dead Abductor
(227127, 0, 10, 0.5, 1, 278292, 512, 0), -- Grazing Mosswool
(212579, 0, 10, 1, 1, 261938, 0, 0), -- Scarlet Stinkcap
(212578, 0, 10, 1, 1, 261937, 0, 0), -- Agaric Spreader
(217420, 0, 10, 2, 1, 266913, 0, 0), -- Decomposing Fungarian
(217405, 0, 10, 0.200000002980232238, 1, 266897, 0, 0), -- Shroom Scavenger
(217428, 0, 10, 1, 1, 266921, 1, 0), -- Agitated Rockpercher
(217404, 0, 10, 1, 1, 266896, 513, 0), -- Persistent Forager
(214945, 0, 10, 1, 1, 264403, 513, 0), -- Moss-Draped Ramolith
(220026, 0, 10, 2, 1, 269599, 1610612736, 67108870), -- Slumbering Mountain Giant
(222040, 0, 10, 1, 1, 271860, 66049, 0), -- Opalooze Mollusc
(223459, 0, 10, 1, 1, 274286, 4096, 16384), -- Injured Earthen
(215765, 0, 10, 1, 1, 265245, 4096, 16384), -- Injured Earthen
(223648, 0, 10, 1, 1, 274507, 0, 0), -- Betta
(215035, 0, 10, 0.200000002980232238, 1, 264499, 0, 0), -- Freefoot Mouse
(212255, 0, 10, 10, 1, 261609, 0, 0), -- Zarein
(223084, 0, 10, 1, 1, 273884, 0, 0), -- Moss-Draped Ramolith
(223238, 0, 10, 1, 1, 274041, 0, 0), -- Swift Cloudrook
(222781, 0, 10, 0.200000002980232238, 1, 273578, 0, 0), -- Sandstone Mosswool
(217961, 0, 10, 1, 1, 267456, 0, 0), -- Hreka
(215038, 0, 10, 0.200000002980232238, 0, 264502, 0, 0), -- Thistlestar
(212708, 0, 10, 1, 1, 262075, 268435456, 0), -- Freysworn Cruton
(227790, 0, 10, 1, 1, 278969, 0, 0), -- Kothilde
(225323, 0, 10, 1, 1, 276280, 0, 0), -- Ginger
(223652, 0, 10, 1, 1, 274511, 0, 0), -- Kurron
(223244, 0, 10, 1, 1, 274047, 0, 0), -- Unbound Miner
(218729, 0, 10, 1, 1, 268262, 0, 0), -- Yeonin
(218535, 0, 10, 1, 1, 268041, 0, 0), -- Germira
(217561, 0, 10, 1, 1, 267054, 1, 0), -- Brushmane Wolf
(215034, 0, 10, 0.200000002980232238, 1, 264498, 0, 0), -- Salt-Ear Ferret
(218191, 0, 10, 1, 1, 267690, 513, 0), -- Moss-Draped Ramolith
(210759, 0, 10, 1, 1, 260103, 4128, 53477378), -- Brann Bronzebeard
(217447, 0, 10, 1, 1, 266940, 0, 0), -- Gandorhil
(212928, 0, 10, 1, 1, 262323, 0, 0), -- Dalaran Sewer Turtle
(223240, 0, 10, 1, 1, 274043, 0, 0), -- Ana
(224424, 0, 10, 1, 1, 275344, 0, 0), -- Velkura
(212925, 0, 10, 1, 1, 262320, 0, 0), -- Dalaran Sewer Rat
(223649, 0, 10, 1, 1, 274508, 0, 0), -- Maluc
(219264, 0, 10, 4, 1, 268828, 72, 0), -- Bloodmaw
(223242, 0, 10, 1, 1, 274045, 0, 0), -- Ama
(229379, 0, 10, 1, 1, 280663, 0, 0), -- Unbound Villager
(217450, 0, 10, 15, 1, 266943, 0, 0), -- Unbound Protector
(217446, 0, 10, 1, 1, 266939, 0, 0), -- Shardgar
(217439, 0, 10, 1, 1, 266932, 0, 0), -- Iridi
(229705, 0, 10, 1, 1, 280993, 1, 0), -- Docile Cloudrook
(227733, 0, 10, 0.200000002980232238, 1, 278912, 0, 0), -- Salt-Ear Ferret
(223446, 0, 10, 1, 1, 274271, 0, 0), -- Collector Dyna
(223346, 0, 10, 1, 1, 274169, 0, 0), -- Ridge
(223344, 0, 10, 1, 1, 274167, 0, 0), -- Stratus
(223343, 0, 10, 1, 1, 274166, 0, 0), -- Tiny Cragling
(223090, 0, 10, 0.200000002980232238, 1, 273890, 0, 0), -- Bedrock Stonecharger
(213115, 0, 10, 4, 1, 262512, 72, 0), -- Rustul Titancap
(222775, 0, 10, 0.200000002980232238, 1, 273572, 0, 0), -- Sandstone Mosswool
(229813, 0, 10, 1.20000004768371582, 1, 281102, 65537, 0), -- Disturbed Krolusk
(212577, 0, 10, 0.5, 1, 261936, 0, 0), -- Budling Morel
(228226, 0, 10, 45, 1, 279411, 16780288, 4194304), -- Hati
(228101, 0, 10, 1, 1, 279286, 16786432, 16), -- Beast
(214465, 0, 10, 1, 1, 263907, 0, 0), -- Pearl Farmer
(214464, 0, 10, 1, 1, 263906, 0, 0), -- Dorbund
(214444, 0, 10, 1, 1, 263886, 134217728, 0), -- Aggartha
(228072, 0, 10, 1, 1, 279257, 0, 0), -- Gartwin
(218203, 0, 10, 1, 1, 267702, 1, 0), -- Brushmane Wolf
(218201, 0, 10, 1, 1, 267700, 1, 0), -- Circling Sharpbeak
(218194, 0, 10, 2, 1, 267693, 513, 0), -- Vinechewer Ramolith
(218188, 0, 10, 2, 1, 267687, 1, 0), -- Meandering Gorger
(218187, 0, 10, 1, 1, 267686, 1, 0), -- Grazing Stomper
(218205, 0, 10, 2, 1, 267704, 0, 0), -- Sparking Sharptooth
(227638, 0, 10, 1, 1, 278815, 1, 0), -- Sharptalon Kestral
(224150, 0, 10, 1, 1, 275018, 0, 0), -- Nerubian Skirmisher
(225270, 0, 10, 1, 1, 276224, 1, 0), -- Crested Shalehorn
(222155, 0, 10, 2, 1, 271975, 66049, 0), -- Opalooze Mollusc
(221681, 0, 10, 0.200000002980232238, 1, 271491, 0, 0), -- Slithering Shalescale
(229335, 0, 10, 1, 1, 280615, 1610612752, 117440582), -- Electricity Stalker [DNT]
(221525, 0, 10, 0.200000002980232238, 1, 271334, 0, 0), -- Prairie Dog
(221645, 0, 10, 0.200000002980232238, 1, 271454, 0, 0), -- Freefoot Mouse
(222019, 0, 10, 1, 1, 271835, 1, 0), -- Shalescale Striker
(224149, 0, 10, 1, 1, 275017, 0, 0), -- Nerubian Webspinner
(221646, 0, 10, 1, 1, 271455, 1, 0), -- Hungry Plainshawk
(219547, 0, 10, 1, 1, 269115, 0, 0), -- Bronze Timekeeper
(221641, 0, 10, 2, 1, 271450, 513, 0), -- Ramolith Stonecrusher
(221642, 0, 10, 1, 1, 271451, 513, 0), -- Mosspelt Ramolith
(229334, 0, 10, 300, 1, 280614, 4, 0); -- Kordac

UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=215093 AND `DifficultyID`=0); -- 215093 (Cragstep Mouse) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223093 AND `DifficultyID`=0); -- 223093 (Granite Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222774 AND `DifficultyID`=0); -- 222774 (Fragrant Stonelamb) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=221519 AND `DifficultyID`=0); -- 221519 (Fluttering Sapphire) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2151, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56110 WHERE (`Entry`=226885 AND `DifficultyID`=0); -- 226885 (Bunny Prime - Empower (DNT)) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=229092 AND `DifficultyID`=0); -- 229092 (Mosswool Grazer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=56110 WHERE (`Entry`=228149 AND `DifficultyID`=0); -- 228149 (Woldclaimed Freysworn) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223852 AND `DifficultyID`=0); -- 223852 (Babbling Book) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223098 AND `DifficultyID`=0); -- 223098 (Cobalt Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306624, `VerifiedBuild`=56110 WHERE (`Entry`=217984 AND `DifficultyID`=0); -- 217984 (Rumble Stalker [DNT]) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222747 AND `DifficultyID`=0); -- 222747 (Mossy Snail) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=226909 AND `DifficultyID`=0); -- 226909 (Frostfire Elemental) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222036 AND `DifficultyID`=0); -- 222036 (Sea Slug) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223799 AND `DifficultyID`=0); -- 223799 (Shard of Dalaran) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=229088 AND `DifficultyID`=0); -- 229088 (Scavenging Falcon) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223797 AND `DifficultyID`=0); -- 223797 (Lingering Spark) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223798 AND `DifficultyID`=0); -- 223798 (Mana Fragment) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=220067 AND `DifficultyID`=0); -- 220067 (Salmoncrab) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=229087 AND `DifficultyID`=0); -- 229087 (Mana-Flecked Crawler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=220038 AND `DifficultyID`=0); -- 220038 (Shattered Crystal) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=217735 AND `DifficultyID`=0); -- 217735 (Charged Storm Wolf) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=225040 AND `DifficultyID`=0); -- 225040 (Mosspelt Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=224972 AND `DifficultyID`=0); -- 224972 (Dire Stormhowl) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=218118 AND `DifficultyID`=0); -- 218118 (Undisciplined Earthen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=218119 AND `DifficultyID`=0); -- 218119 (Undisciplined Earthen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222780 AND `DifficultyID`=0); -- 222780 (Fragrant Stonelamb) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223097 AND `DifficultyID`=0); -- 223097 (Black Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222419 AND `DifficultyID`=0); -- 222419 (Mosspelt Sheep) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=221524 AND `DifficultyID`=0); -- 221524 (Gemwing) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222331 AND `DifficultyID`=0); -- 222331 (Cragstep Mouse) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `VerifiedBuild`=56110 WHERE (`Entry`=212160 AND `DifficultyID`=0); -- 212160 (Cart) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222156 AND `DifficultyID`=0); -- 222156 (Scavenging Sandsnapper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222280 AND `DifficultyID`=0); -- 222280 (Voltscale Borer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222035 AND `DifficultyID`=0); -- 222035 (Softshell Pincher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=222057 AND `DifficultyID`=0); -- 222057 (Isle Gull) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223059 AND `DifficultyID`=0); -- 223059 (Gizwig) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223063 AND `DifficultyID`=0); -- 223063 (Hagenbran) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223094 AND `DifficultyID`=0); -- 223094 (Cobalt Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223057 AND `DifficultyID`=0); -- 223057 (Trained Sandsnapper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222312 AND `DifficultyID`=0); -- 222312 (Scavenging Sandsnapper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=224800 AND `DifficultyID`=0); -- 224800 (Salty Gull) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=221528 AND `DifficultyID`=0); -- 221528 (Soaring Plainshawk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=222310 AND `DifficultyID`=0); -- 222310 (Isle Gull) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=221527 AND `DifficultyID`=0); -- 221527 (Regal Plainshawk) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=536871168, `VerifiedBuild`=56110 WHERE (`Entry`=223558 AND `DifficultyID`=0); -- 223558 (Skyriding Glyph) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222302 AND `DifficultyID`=0); -- 222302 (Sandscale Riplisk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=225026 AND `DifficultyID`=0); -- 225026 (Sandscale Riplisk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=222322 AND `DifficultyID`=0); -- 222322 (Hungry Plainshawk) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222329 AND `DifficultyID`=0); -- 222329 (Regal Plainshawk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=222757 AND `DifficultyID`=0); -- 222757 (Shalewing Devourer) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=536870912, `VerifiedBuild`=56110 WHERE (`Entry`=222347 AND `DifficultyID`=0); -- 222347 (Gnashing Rockwing) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222332 AND `DifficultyID`=0); -- 222332 (Wild Stormhowl) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=228073 AND `DifficultyID`=0); -- 228073 (Wahrvren) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=222759 AND `DifficultyID`=0); -- 222759 (Ravenous Shalewing) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=221644 AND `DifficultyID`=0); -- 221644 (Soaring Plainshawk) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2832, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56110 WHERE (`Entry`=212407 AND `DifficultyID`=0); -- 212407 (Enter Delve) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=221684 AND `DifficultyID`=0); -- 221684 (Crested Shalehorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223657 AND `DifficultyID`=0); -- 223657 (Igneous Elemental) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2855, `VerifiedBuild`=56110 WHERE (`Entry`=219550 AND `DifficultyID`=0); -- 219550 (Bronze Timekeeper) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=221672 AND `DifficultyID`=0); -- 221672 (Ramolith Curlhorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=221678 AND `DifficultyID`=0); -- 221678 (Wild Stormhowl) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=221526 AND `DifficultyID`=0); -- 221526 (Mosspelt Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `VerifiedBuild`=56110 WHERE (`Entry`=224730 AND `DifficultyID`=0); -- 224730 (Elemental Targeting) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222301 AND `DifficultyID`=0); -- 222301 (Damp Sandcourser) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=227115 AND `DifficultyID`=0); -- 227115 (Sandy Scuttler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222499 AND `DifficultyID`=0); -- 222499 (Mossy Snail) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=214946 AND `DifficultyID`=0); -- 214946 (Vinechewer Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=215036 AND `DifficultyID`=0); -- 215036 (Redwing Falcon) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222841 AND `DifficultyID`=0); -- 222841 (Dead Abductor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=227127 AND `DifficultyID`=0); -- 227127 (Grazing Mosswool) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=212578 AND `DifficultyID`=0); -- 212578 (Agaric Spreader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=212579 AND `DifficultyID`=0); -- 212579 (Scarlet Stinkcap) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306624, `VerifiedBuild`=56110 WHERE (`Entry`=217420 AND `DifficultyID`=0); -- 217420 (Decomposing Fungarian) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=217405 AND `DifficultyID`=0); -- 217405 (Shroom Scavenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=217428 AND `DifficultyID`=0); -- 217428 (Agitated Rockpercher) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=217404 AND `DifficultyID`=0); -- 217404 (Persistent Forager) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=214945 AND `DifficultyID`=0); -- 214945 (Moss-Draped Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306624, `VerifiedBuild`=56110 WHERE (`Entry`=220026 AND `DifficultyID`=0); -- 220026 (Slumbering Mountain Giant) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222040 AND `DifficultyID`=0); -- 222040 (Opalooze Mollusc) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223648 AND `DifficultyID`=0); -- 223648 (Betta) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=215035 AND `DifficultyID`=0); -- 215035 (Freefoot Mouse) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=215038 AND `DifficultyID`=0); -- 215038 (Thistlestar) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=56110 WHERE (`Entry`=217961 AND `DifficultyID`=0); -- 217961 (Hreka) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=212708 AND `DifficultyID`=0); -- 212708 (Freysworn Cruton) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222781 AND `DifficultyID`=0); -- 222781 (Sandstone Mosswool) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=212255 AND `DifficultyID`=0); -- 212255 (Zarein) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223084 AND `DifficultyID`=0); -- 223084 (Moss-Draped Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223238 AND `DifficultyID`=0); -- 223238 (Swift Cloudrook) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=225323 AND `DifficultyID`=0); -- 225323 (Ginger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=218535 AND `DifficultyID`=0); -- 218535 (Germira) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=218729 AND `DifficultyID`=0); -- 218729 (Yeonin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223652 AND `DifficultyID`=0); -- 223652 (Kurron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=217561 AND `DifficultyID`=0); -- 217561 (Brushmane Wolf) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=227790 AND `DifficultyID`=0); -- 227790 (Kothilde) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223244 AND `DifficultyID`=0); -- 223244 (Unbound Miner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=215034 AND `DifficultyID`=0); -- 215034 (Salt-Ear Ferret) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=218191 AND `DifficultyID`=0); -- 218191 (Moss-Draped Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=224424 AND `DifficultyID`=0); -- 224424 (Velkura) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=217447 AND `DifficultyID`=0); -- 217447 (Gandorhil) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2804, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=219264 AND `DifficultyID`=0); -- 219264 (Bloodmaw) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=56110 WHERE (`Entry`=62822 AND `DifficultyID`=0); -- 62822 (Cousin Slowhands) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=56110 WHERE (`Entry`=217446 AND `DifficultyID`=0); -- 217446 (Shardgar) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=56110 WHERE (`Entry`=62821 AND `DifficultyID`=0); -- 62821 (Mystic Birdhat) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223649 AND `DifficultyID`=0); -- 223649 (Maluc) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223242 AND `DifficultyID`=0); -- 223242 (Ama) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=56110 WHERE (`Entry`=212928 AND `DifficultyID`=0); -- 212928 (Dalaran Sewer Turtle) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=229379 AND `DifficultyID`=0); -- 229379 (Unbound Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=56110 WHERE (`Entry`=212925 AND `DifficultyID`=0); -- 212925 (Dalaran Sewer Rat) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2803, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=217450 AND `DifficultyID`=0); -- 217450 (Unbound Protector) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223240 AND `DifficultyID`=0); -- 223240 (Ana) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=217439 AND `DifficultyID`=0); -- 217439 (Iridi) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=204341 AND `DifficultyID`=0); -- 204341 (Ravenous Shalewing) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=227733 AND `DifficultyID`=0); -- 227733 (Salt-Ear Ferret) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `VerifiedBuild`=56110 WHERE (`Entry`=223343 AND `DifficultyID`=0); -- 223343 (Tiny Cragling) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `VerifiedBuild`=56110 WHERE (`Entry`=223346 AND `DifficultyID`=0); -- 223346 (Ridge) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223090 AND `DifficultyID`=0); -- 223090 (Bedrock Stonecharger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=229705 AND `DifficultyID`=0); -- 229705 (Docile Cloudrook) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223344 AND `DifficultyID`=0); -- 223344 (Stratus) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=373, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=223446 AND `DifficultyID`=0); -- 223446 (Collector Dyna) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=222775 AND `DifficultyID`=0); -- 222775 (Sandstone Mosswool) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=229813 AND `DifficultyID`=0); -- 229813 (Disturbed Krolusk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=214465 AND `DifficultyID`=0); -- 214465 (Pearl Farmer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=214464 AND `DifficultyID`=0); -- 214464 (Dorbund) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=214444 AND `DifficultyID`=0); -- 214444 (Aggartha) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=218201 AND `DifficultyID`=0); -- 218201 (Circling Sharpbeak) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=218194 AND `DifficultyID`=0); -- 218194 (Vinechewer Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=228072 AND `DifficultyID`=0); -- 228072 (Gartwin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=218203 AND `DifficultyID`=0); -- 218203 (Brushmane Wolf) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=218188 AND `DifficultyID`=0); -- 218188 (Meandering Gorger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=218187 AND `DifficultyID`=0); -- 218187 (Grazing Stomper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56110 WHERE (`Entry`=218205 AND `DifficultyID`=0); -- 218205 (Sparking Sharptooth) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56110 WHERE (`Entry`=227638 AND `DifficultyID`=0); -- 227638 (Sharptalon Kestral) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=225270 AND `DifficultyID`=0); -- 225270 (Crested Shalehorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=222155 AND `DifficultyID`=0); -- 222155 (Opalooze Mollusc) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=221681 AND `DifficultyID`=0); -- 221681 (Slithering Shalescale) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306624, `VerifiedBuild`=56196 WHERE (`Entry`=229335 AND `DifficultyID`=0); -- 229335 (Electricity Stalker [DNT]) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=221525 AND `DifficultyID`=0); -- 221525 (Prairie Dog) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=221645 AND `DifficultyID`=0); -- 221645 (Freefoot Mouse) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2855, `VerifiedBuild`=56196 WHERE (`Entry`=219547 AND `DifficultyID`=0); -- 219547 (Bronze Timekeeper) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=224150 AND `DifficultyID`=0); -- 224150 (Nerubian Skirmisher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=222019 AND `DifficultyID`=0); -- 222019 (Shalescale Striker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56196 WHERE (`Entry`=221646 AND `DifficultyID`=0); -- 221646 (Hungry Plainshawk) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=224149 AND `DifficultyID`=0); -- 224149 (Nerubian Webspinner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=221642 AND `DifficultyID`=0); -- 221642 (Mosspelt Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=221641 AND `DifficultyID`=0); -- 221641 (Ramolith Stonecrusher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2863, `StaticFlags1`=268435456, `VerifiedBuild`=56196 WHERE (`Entry`=229334 AND `DifficultyID`=0); -- 229334 (Kordac) - CanSwim

-- Path for Shard of Dalaran
SET @MOVERGUID := @CGUID+35;
SET @ENTRY := 223799;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Shard of Dalaran - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2114.9033, -931.56824, 13.855955, NULL, 0),
(@PATH, 1, 2115.859, -931.7685, 13.877789, NULL, 0),
(@PATH, 2, 2116.8145, -931.96875, 13.899622, NULL, 0),
(@PATH, 3, 2118.7715, -932.3789, 13.635689, NULL, 0),
(@PATH, 4, 2119.5417, -932.55035, 13.617777, NULL, 0),
(@PATH, 5, 2121.5127, -932.21094, 13.454767, NULL, 0),
(@PATH, 6, 2124.4688, -931.7012, 13.268185, NULL, 0),
(@PATH, 7, 2126.4395, -931.3613, 13.085929, NULL, 0),
(@PATH, 8, 2127.4248, -931.1914, 12.880989, NULL, 0),
(@PATH, 9, 2129.3955, -930.85156, 12.453716, NULL, 0),
(@PATH, 10, 2130.3809, -930.68164, 12.244023, NULL, 0),
(@PATH, 11, 2132.3516, -930.3418, 11.843875, NULL, 0),
(@PATH, 12, 2133.337, -930.1719, 11.669837, NULL, 0),
(@PATH, 13, 2150.698, -928.24133, 9.931435, NULL, 0),
(@PATH, 14, 2165.8403, -929.1389, 8.725011, NULL, 0),
(@PATH, 15, 2169.836, -929.334, 8.472441, NULL, 0),
(@PATH, 16, 2172.833, -929.48047, 8.2549095, NULL, 0),
(@PATH, 17, 2174.831, -929.5781, 8.066453, NULL, 0),
(@PATH, 18, 2178.389, -929.7465, 7.933398, NULL, 0),
(@PATH, 19, 2189.3264, -927.94617, 6.376943, NULL, 0),
(@PATH, 20, 2199.111, -926.7934, 6.1258116, NULL, 5058),
(@PATH, 21, 2189.3264, -927.94617, 6.376943, NULL, 0),
(@PATH, 22, 2178.4766, -929.7285, 7.9257874, NULL, 0),
(@PATH, 23, 2165.8403, -929.1389, 8.725011, NULL, 0),
(@PATH, 24, 2150.698, -928.24133, 9.931435, NULL, 0),
(@PATH, 25, 2133.7761, -930.1042, 11.67417, NULL, 0),
(@PATH, 26, 2119.5417, -932.55035, 13.617777, NULL, 0),
(@PATH, 27, 2106.0503, -929.71356, 14.235663, NULL, 0),
(@PATH, 28, 2095.184, -928.809, 15.398083, NULL, 3905),
(@PATH, 29, 2106.0503, -929.71356, 14.235663, NULL, 0);

UPDATE `creature` SET `position_x`=2114.9033, `position_y`=-931.56824, `position_z`=13.855955, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Shard of Dalaran
SET @MOVERGUID := @CGUID+27;
SET @ENTRY := 223799;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Shard of Dalaran - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2012.4761, -1017.9365, 18.767044, NULL, 0),
(@PATH, 1, 2012.6062, -1018.3257, 18.756054, NULL, 0),
(@PATH, 2, 2012.7363, -1018.71484, 18.745064, NULL, 0),
(@PATH, 3, 2013.2622, -1020.2778, 18.584314, NULL, 0),
(@PATH, 4, 2014.9785, -1021.3047, 18.267025, NULL, 0),
(@PATH, 5, 2016.6953, -1022.33203, 18.044987, NULL, 0),
(@PATH, 6, 2019.2705, -1023.87305, 17.874775, NULL, 0),
(@PATH, 7, 2025.2793, -1027.4688, 17.679958, NULL, 0),
(@PATH, 8, 2026.9961, -1028.4961, 17.41861, NULL, 0),
(@PATH, 9, 2036.9062, -1029.5834, 16.327316, NULL, 0),
(@PATH, 10, 2047.3889, -1034.3021, 15.55964, NULL, 0),
(@PATH, 11, 2056.7708, -1039.5469, 14.354166, NULL, 0),
(@PATH, 12, 2067.4775, -1041.5139, 13.954816, NULL, 4548),
(@PATH, 13, 2056.7708, -1039.5469, 14.354166, NULL, 0),
(@PATH, 14, 2047.3889, -1034.3021, 15.55964, NULL, 0),
(@PATH, 15, 2036.9062, -1029.5834, 16.327316, NULL, 0),
(@PATH, 16, 2027.0555, -1028.5243, 17.40748, NULL, 0),
(@PATH, 17, 2013.2622, -1020.2778, 18.584314, NULL, 0),
(@PATH, 18, 2009.5625, -1009.2222, 18.834503, NULL, 0),
(@PATH, 19, 2005.1233, -997.98267, 17.731102, NULL, 0),
(@PATH, 20, 2009.9896, -978.8403, 16.657778, NULL, 0),
(@PATH, 21, 2009.9271, -966.3108, 16.570877, NULL, 4925),
(@PATH, 22, 2009.9896, -978.8403, 16.657778, NULL, 0),
(@PATH, 23, 2005.1233, -997.98267, 17.731102, NULL, 0),
(@PATH, 24, 2005.4902, -998.9121, 17.638498, NULL, 0),
(@PATH, 25, 2006.2246, -1000.7715, 17.884466, NULL, 0),
(@PATH, 26, 2006.959, -1002.63086, 18.070938, NULL, 0),
(@PATH, 27, 2007.6934, -1004.49023, 18.415245, NULL, 0),
(@PATH, 28, 2008.0605, -1005.4199, 18.59016, NULL, 0),
(@PATH, 29, 2009.1621, -1008.209, 18.805374, NULL, 0),
(@PATH, 30, 2009.5625, -1009.2222, 18.834503, NULL, 0);

UPDATE `creature` SET `position_x`=2012.4761, `position_y`=-1017.9365, `position_z`=18.767044, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Mosswool Grazer
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+198;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+198, @CGUID+198, 0, 0, 515, 8, 23),
(@CGUID+198, @CGUID+200, 2, 270, 515, 8, 23);

SET @MOVERGUID := @CGUID+198;
SET @ENTRY := 229092;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Mosswool Grazer - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1733.7793, -1016.4414, 40.092422, NULL, 0),
(@PATH, 1, 1729.4705, -1009.5938, 41.91642, NULL, 0),
(@PATH, 2, 1724.4601, -1002.066, 43.748863, NULL, 0),
(@PATH, 3, 1706.8976, -977.9583, 50.668945, NULL, 0),
(@PATH, 4, 1695.5834, -966.51215, 49.90467, NULL, 0),
(@PATH, 5, 1693.9567, -959.79517, 50.81138, NULL, 0),
(@PATH, 6, 1693.0469, -953.34204, 51.694, NULL, 0),
(@PATH, 7, 1691.6198, -949.1441, 52.09078, NULL, 0),
(@PATH, 8, 1688.1007, -945.52954, 52.07635, NULL, 4430),
(@PATH, 9, 1691.6198, -949.1441, 52.09078, NULL, 0),
(@PATH, 10, 1693.0469, -953.34204, 51.694, NULL, 0),
(@PATH, 11, 1693.9567, -959.79517, 50.81138, NULL, 0),
(@PATH, 12, 1695.5834, -966.51215, 49.90467, NULL, 0),
(@PATH, 13, 1706.8976, -977.9583, 50.668945, NULL, 0),
(@PATH, 14, 1715.368, -986.8507, 49.782257, NULL, 0),
(@PATH, 15, 1721.382, -993.43054, 47.207172, NULL, 0),
(@PATH, 16, 1724.4601, -1002.066, 43.748863, NULL, 0),
(@PATH, 17, 1725.5674, -1003.73047, 43.056458, NULL, 0),
(@PATH, 18, 1726.6748, -1005.39453, 42.495987, NULL, 0),
(@PATH, 19, 1727.7822, -1007.0586, 42.294453, NULL, 0),
(@PATH, 20, 1728.8896, -1008.72266, 42.016254, NULL, 0),
(@PATH, 21, 1729.4705, -1009.5938, 41.91642, NULL, 0),
(@PATH, 22, 1733.7363, -1016.3594, 40.092422, NULL, 0),
(@PATH, 23, 1735.5295, -1020.0347, 38.386436, NULL, 5657);

UPDATE `creature` SET `position_x`=1733.7793, `position_y`=-1016.4414, `position_z`=40.092422, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Gnashing Rockwing
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+280;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+280, @CGUID+280, 0, 0, 515, 5, 13),
(@CGUID+280, @CGUID+285, 4, 270, 515, 5, 13);

SET @MOVERGUID := @CGUID+280;
SET @ENTRY := 222347;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Gnashing Rockwing - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1465.2223, -403.36978, 56.23094, NULL, 0),
(@PATH, 1, 1464.2048, -412.13196, 56.830788, NULL, 0),
(@PATH, 2, 1467.3021, -422.32812, 58.258644, NULL, 0),
(@PATH, 3, 1469.5504, -431.59375, 58.677727, NULL, 0),
(@PATH, 4, 1467.1685, -448.34723, 54.92273, NULL, 0),
(@PATH, 5, 1461.7327, -464.52603, 50.120354, NULL, 15293),
(@PATH, 6, 1467.1685, -448.34723, 54.92273, NULL, 0),
(@PATH, 7, 1469.5504, -431.59375, 58.677727, NULL, 0),
(@PATH, 8, 1467.3021, -422.32812, 58.258644, NULL, 0),
(@PATH, 9, 1464.2048, -412.13196, 56.830788, NULL, 0),
(@PATH, 10, 1465.2223, -403.36978, 56.23094, NULL, 0),
(@PATH, 11, 1466.3976, -389.89584, 53.858887, NULL, 0),
(@PATH, 12, 1466.5139, -379.6354, 50.765392, NULL, 0),
(@PATH, 13, 1467.8177, -370.34897, 47.331924, NULL, 9338),
(@PATH, 14, 1466.5139, -379.6354, 50.765392, NULL, 0),
(@PATH, 15, 1466.3976, -389.89584, 53.858887, NULL, 0);

UPDATE `creature` SET `position_x`=1465.2223, `position_y`=-403.36978, `position_z`=56.23094, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Dire Stormhowl
SET @MOVERGUID := @CGUID+302;
SET @ENTRY := 224972;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Dire Stormhowl - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1390.5591, -639.3177, 35.82751, NULL, 0),
(@PATH, 1, 1367.3108, -624.066, 32.144833, NULL, 0),
(@PATH, 2, 1369.8055, -594.375, 29.612335, NULL, 0),
(@PATH, 3, 1376.1285, -577.7708, 26.831028, NULL, 0),
(@PATH, 4, 1394.9185, -562.434, 27.508575, NULL, 0),
(@PATH, 5, 1411.7692, -554.17883, 27.5715, NULL, 0),
(@PATH, 6, 1420.4531, -551.9514, 26.95693, NULL, 0),
(@PATH, 7, 1434.7466, -550.86804, 27.644245, NULL, 0),
(@PATH, 8, 1443.8959, -551.9184, 29.29916, NULL, 0),
(@PATH, 9, 1443.7979, -576.91797, 28.775288, NULL, 0),
(@PATH, 10, 1452.1649, -584.5434, 29.960836, NULL, 0),
(@PATH, 11, 1462.8385, -597.7205, 31.559782, NULL, 0),
(@PATH, 12, 1468.1348, -613.8906, 33.71493, NULL, 0),
(@PATH, 13, 1468.6528, -615.4531, 34.227448, NULL, 0),
(@PATH, 14, 1468.1328, -616.3086, 34.38149, NULL, 0),
(@PATH, 15, 1467.0938, -618.01953, 34.852146, NULL, 0),
(@PATH, 16, 1465.5352, -620.58594, 35.20426, NULL, 0),
(@PATH, 17, 1465.0156, -621.4414, 35.507355, NULL, 0),
(@PATH, 18, 1464.4961, -622.2969, 35.6793, NULL, 0),
(@PATH, 19, 1463.457, -624.0078, 36.329136, NULL, 0),
(@PATH, 20, 1462.418, -625.71875, 36.634396, NULL, 0),
(@PATH, 21, 1461.3789, -627.4297, 37.265995, NULL, 0),
(@PATH, 22, 1460.8594, -628.28516, 37.529102, NULL, 0),
(@PATH, 23, 1459.8203, -629.9961, 37.71447, NULL, 0),
(@PATH, 24, 1458.7812, -631.70703, 38.003853, NULL, 0),
(@PATH, 25, 1457.7422, -633.41797, 38.230904, NULL, 0),
(@PATH, 26, 1453.382, -640.5903, 38.31404, NULL, 0),
(@PATH, 27, 1432.3229, -650.3333, 38.497166, NULL, 0),
(@PATH, 28, 1430.3232, -650.3379, 38.358845, NULL, 0),
(@PATH, 29, 1428.3232, -650.3418, 38.12662, NULL, 0),
(@PATH, 30, 1425.3232, -650.34766, 37.923145, NULL, 0),
(@PATH, 31, 1422.3232, -650.3535, 38.12417, NULL, 0),
(@PATH, 32, 1420.3232, -650.3574, 38.34794, NULL, 0),
(@PATH, 33, 1418.3232, -650.3613, 38.583576, NULL, 0),
(@PATH, 34, 1416.3232, -650.36523, 38.791393, NULL, 0),
(@PATH, 35, 1412.3232, -650.37305, 38.967823, NULL, 0),
(@PATH, 36, 1410.3646, -650.35767, 38.86133, NULL, 0),
(@PATH, 37, 1399.3698, -644.233, 36.53125, 2.6333551, 0);

UPDATE `creature` SET `position_x`=1390.5591, `position_y`=-639.3177, `position_z`=35.82751, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Dire Stormhowl
SET @MOVERGUID := @CGUID+331;
SET @ENTRY := 224972;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Dire Stormhowl - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1498.7274, -879.42535, 43.748898, NULL, 0),
(@PATH, 1, 1500.6841, -857.2049, 48.64872, NULL, 0),
(@PATH, 2, 1497.9185, -841.21356, 48.722607, NULL, 0),
(@PATH, 3, 1484.0192, -825.15625, 45.911705, NULL, 0),
(@PATH, 4, 1453.2935, -823.75696, 40.12673, NULL, 0),
(@PATH, 5, 1432.658, -822.38367, 42.36628, NULL, 0),
(@PATH, 6, 1415.7882, -831.6268, 40.83904, NULL, 0),
(@PATH, 7, 1410.5382, -841.3889, 40.13781, NULL, 0),
(@PATH, 8, 1403.4445, -859.5139, 39.907417, NULL, 0),
(@PATH, 9, 1403.1406, -873.941, 39.400684, NULL, 0),
(@PATH, 10, 1411.0764, -900.2969, 39.0725, NULL, 0),
(@PATH, 11, 1425.7246, -920.56055, 40.718884, NULL, 0),
(@PATH, 12, 1444.1423, -931.7847, 39.47399, NULL, 0),
(@PATH, 13, 1471.6077, -914.05206, 38.55258, NULL, 0),
(@PATH, 14, 1485.1685, -903.2083, 40.980095, NULL, 0);

UPDATE `creature` SET `position_x`=1498.7274, `position_y`=-879.42535, `position_z`=43.748898, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Dire Stormhowl
SET @MOVERGUID := @CGUID+334;
SET @ENTRY := 224972;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Dire Stormhowl - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1431.9601, -932.46704, 41.475983, NULL, 0),
(@PATH, 1, 1434.3021, -940.7899, 41.412453, NULL, 0),
(@PATH, 2, 1436.0173, -950.28644, 41.317093, NULL, 0),
(@PATH, 3, 1436.1423, -962.1007, 41.53929, NULL, 0),
(@PATH, 4, 1436.9913, -973.6823, 41.709717, NULL, 0),
(@PATH, 5, 1434.7812, -987.8906, 42.08972, NULL, 0),
(@PATH, 6, 1428.4219, -1006.2292, 42.021973, NULL, 0),
(@PATH, 7, 1415.5868, -1023.4809, 39.66628, NULL, 0),
(@PATH, 8, 1397.2118, -1024.9531, 38.890316, NULL, 0),
(@PATH, 9, 1382.6649, -1025.5156, 37.660507, NULL, 0),
(@PATH, 10, 1361.7327, -1015.2257, 39.29916, NULL, 0),
(@PATH, 11, 1358.333, -1015.625, 39.255836, NULL, 0),
(@PATH, 12, 1356.25, -1016.1465, 38.9582, NULL, 0),
(@PATH, 13, 1355.208, -1016.1465, 38.809376, NULL, 0),
(@PATH, 14, 1354.167, -1016.666, 38.655796, NULL, 0),
(@PATH, 15, 1352.167, -1016.666, 38.420807, NULL, 0),
(@PATH, 16, 1350.167, -1016.666, 37.95083, NULL, 0),
(@PATH, 17, 1348.958, -1016.666, 37.62522, NULL, 0),
(@PATH, 18, 1347.917, -1016.666, 37.483738, NULL, 0),
(@PATH, 19, 1345.833, -1016.666, 37.170265, NULL, 0),
(@PATH, 20, 1342.833, -1016.666, 36.856712, NULL, 0),
(@PATH, 21, 1341.667, -1016.666, 36.540234, NULL, 0),
(@PATH, 22, 1308.3473, -1002.0278, 32.336514, NULL, 0),
(@PATH, 23, 1294.1146, -984.25696, 33.851242, NULL, 0),
(@PATH, 24, 1296.7188, -953, 34.22094, NULL, 0),
(@PATH, 25, 1315.6459, -923.6893, 37.32978, NULL, 0),
(@PATH, 26, 1328.9653, -903.8906, 36.210308, NULL, 0),
(@PATH, 27, 1353.3247, -885.36115, 37.50197, NULL, 0),
(@PATH, 28, 1375.9514, -873.3698, 38.150116, NULL, 0),
(@PATH, 29, 1408.6337, -879.48785, 38.993065, NULL, 0),
(@PATH, 30, 1429.9028, -927.9601, 41.53231, NULL, 0);

UPDATE `creature` SET `position_x`=1431.9601, `position_y`=-932.46704, `position_z`=41.475983, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Vinechewer Ramolith
SET @MOVERGUID := @CGUID+626;
SET @ENTRY := 214946;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Vinechewer Ramolith - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 958.2222, -1789.8802, 92.98703, NULL, 0),
(@PATH, 1, 957.79517, -1768.6562, 93.012535, NULL, 0),
(@PATH, 2, 948.88196, -1747.5348, 93.33965, NULL, 0),
(@PATH, 3, 939.6823, -1737.4427, 93.27401, NULL, 6128),
(@PATH, 4, 948.88196, -1747.5348, 93.33965, NULL, 0),
(@PATH, 5, 957.79517, -1768.6562, 93.012535, NULL, 0),
(@PATH, 6, 958.2222, -1789.8802, 92.98703, NULL, 0),
(@PATH, 7, 963.07117, -1800.3038, 96.47118, NULL, 6662);

UPDATE `creature` SET `position_x`=958.2222, `position_y`=-1789.8802, `position_z`=92.98703, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Bloodmaw
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+654;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+654, @CGUID+654, 0, 0, 515, 0, 0),
(@CGUID+654, @CGUID+638, 6, 0, 515, 0, 0),
(@CGUID+654, @CGUID+657, 3, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+654;
SET @ENTRY := 219264;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Bloodmaw - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 738.7118, -1827.7673, 194.9296, NULL, 0),
(@PATH, 1, 758.0226, -1810.4966, 179.81606, NULL, 0),
(@PATH, 2, 801.55554, -1839.3073, 155.49756, NULL, 0),
(@PATH, 3, 811.1493, -1878.3403, 151.69913, NULL, 0),
(@PATH, 4, 803.59204, -1908.0764, 154.16742, NULL, 0),
(@PATH, 5, 788.09375, -1940.1754, 159.29486, NULL, 0),
(@PATH, 6, 768.7205, -1961.9774, 170.0397, NULL, 0),
(@PATH, 7, 739.0191, -1961.9341, 184.34822, NULL, 0),
(@PATH, 8, 726.0903, -1934.8403, 191.91083, NULL, 0),
(@PATH, 9, 726.96094, -1936.668, 191.2648, NULL, 0),
(@PATH, 10, 726.0996, -1934.8633, 191.70479, NULL, 0),
(@PATH, 11, 725.8789, -1933.8633, 192.35625, NULL, 0),
(@PATH, 12, 725.45703, -1931.9102, 192.55959, NULL, 0),
(@PATH, 13, 725.03516, -1929.957, 192.74908, NULL, 0),
(@PATH, 14, 724.8242, -1928.9805, 193.38962, NULL, 0),
(@PATH, 15, 723.76953, -1924.0977, 194.23619, NULL, 0),
(@PATH, 16, 723.1367, -1921.168, 194.52687, NULL, 0),
(@PATH, 17, 722.71484, -1919.2148, 195.59486, NULL, 0),
(@PATH, 18, 722.5039, -1918.2383, 195.78745, NULL, 0),
(@PATH, 19, 722.08203, -1916.2852, 196.13538, NULL, 0),
(@PATH, 20, 721.8711, -1915.3086, 197.12485, NULL, 0),
(@PATH, 21, 721.66016, -1914.332, 197.29733, NULL, 0),
(@PATH, 22, 721.4492, -1913.3555, 197.4698, NULL, 0),
(@PATH, 23, 721.2383, -1912.3789, 197.64114, NULL, 0),
(@PATH, 24, 720.8164, -1910.4258, 198.50803, NULL, 0),
(@PATH, 25, 720.39453, -1908.4727, 198.75017, NULL, 0),
(@PATH, 26, 719.7617, -1905.543, 199.61331, NULL, 0),
(@PATH, 27, 719.11804, -1902.5278, 199.63823, NULL, 0),
(@PATH, 28, 718.4149, -1876.2413, 202.72868, NULL, 0),
(@PATH, 29, 727.2222, -1849.3507, 201.09502, NULL, 0);

UPDATE `creature` SET `position_x`=738.7118, `position_y`=-1827.7673, `position_z`=194.9296, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Brushmane Wolf
SET @MOVERGUID := @CGUID+648;
SET @ENTRY := 217561;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Brushmane Wolf - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 771.8542, -1825.6041, 172.79701, NULL, 0),
(@PATH, 1, 760.0399, -1820.368, 180.14674, NULL, 0),
(@PATH, 2, 747.9167, -1822.5885, 188.30045, NULL, 0),
(@PATH, 3, 742.88196, -1831.1945, 192.65747, NULL, 9156),
(@PATH, 4, 747.9167, -1822.5885, 188.30045, NULL, 0),
(@PATH, 5, 760.0399, -1820.368, 180.14674, NULL, 0),
(@PATH, 6, 771.8542, -1825.6041, 172.79701, NULL, 0),
(@PATH, 7, 781.9844, -1827.5973, 166.62857, NULL, 7881);

UPDATE `creature` SET `position_x`=771.8542, `position_y`=-1825.6041, `position_z`=172.79701, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Brushmane Wolf
SET @MOVERGUID := @CGUID+652;
SET @ENTRY := 217561;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Brushmane Wolf - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 744.5208, -1915.231, 182.75578, 6.070723, 571),
(@PATH, 1, 734.0903, -1913.1024, 189.00131, NULL, 0),
(@PATH, 2, 726.18054, -1899.4723, 194.86572, NULL, 0),
(@PATH, 3, 711.55383, -1892.0209, 204.72714, NULL, 7463),
(@PATH, 4, 726.18054, -1899.4723, 194.86572, NULL, 0),
(@PATH, 5, 734.0903, -1913.1024, 189.00131, NULL, 0);

UPDATE `creature` SET `position_x`=744.5208, `position_y`=-1915.231, `position_z`=182.75578, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Ramolith Curlhorn
SET @MOVERGUID := @CGUID+815;
SET @ENTRY := 221672;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Ramolith Curlhorn - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1670.4635, -2542.1338, 101.29499, NULL, 0),
(@PATH, 1, 1692.6562, -2529.8508, 102.7391, NULL, 0),
(@PATH, 2, 1694.4791, -2507.8594, 107.452805, NULL, 0),
(@PATH, 3, 1719.4966, -2472.8906, 100.13184, NULL, 0),
(@PATH, 4, 1726.1267, -2447.1685, 95.07202, NULL, 0),
(@PATH, 5, 1729.8142, -2432.7344, 93.17877, NULL, 0),
(@PATH, 6, 1746.8854, -2429.8142, 93.26119, NULL, 0),
(@PATH, 7, 1729.8142, -2432.7344, 93.17877, NULL, 0),
(@PATH, 8, 1726.1267, -2447.1685, 95.07202, NULL, 0),
(@PATH, 9, 1719.4966, -2472.8906, 100.13184, NULL, 0),
(@PATH, 10, 1694.4791, -2507.8594, 107.452805, NULL, 0),
(@PATH, 11, 1692.6533, -2529.7734, 102.840126, NULL, 0),
(@PATH, 12, 1670.4635, -2542.1338, 101.29499, NULL, 0),
(@PATH, 13, 1650.2483, -2543.1477, 101.45243, NULL, 0),
(@PATH, 14, 1626.9341, -2547.3542, 103.11825, NULL, 0),
(@PATH, 15, 1604.3577, -2551.4028, 108.732704, NULL, 0),
(@PATH, 16, 1626.9341, -2547.3542, 103.11825, NULL, 0),
(@PATH, 17, 1650.2483, -2543.1477, 101.45243, NULL, 0);

UPDATE `creature` SET `position_x`=1670.4635, `position_y`=-2542.1338, `position_z`=101.29499, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
