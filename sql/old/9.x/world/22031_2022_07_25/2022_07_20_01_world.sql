SET @CGUID := 460627;
SET @OGUID := 395622;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+49;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 77617, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1863.574462890625, 239.36871337890625, 76.9240264892578125, 1.253607988357543945, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Lunarfall Worker (Area: -Unknown- - Difficulty: 1)
(@CGUID+1, 77376, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1903.1875, 207.1041717529296875, 77.0313568115234375, 2.775068521499633789, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Lunarfall Woodcutter (Area: -Unknown- - Difficulty: 1)
(@CGUID+2, 77370, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1891.2288818359375, 270.200958251953125, 76.68341827392578125, 1.196875929832458496, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44232), -- Lunarfall Footman (Area: -Unknown- - Difficulty: 1) (Auras: 178343 - Garrison Combat Throttle)
(@CGUID+3, 79894, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1764.6614990234375, 214.78472900390625, 73.1560211181640625, 0.582970201969146728, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Dinah (Area: -Unknown- - Difficulty: 1)
(@CGUID+4, 81152, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1843.7691650390625, 227.9739532470703125, 75.750274658203125, 5.611456871032714843, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Scout Valdez (Area: -Unknown- - Difficulty: 1) (Auras: 133464 - Read Scroll)
(@CGUID+5, 82401, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1752.2535400390625, 212.5520782470703125, 73.29390716552734375, 3.912691831588745117, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Grinhilda Quartzhammer (Area: -Unknown- - Difficulty: 1)
(@CGUID+6, 79603, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1913.439208984375, 203.53472900390625, 76.96572113037109375, 5.886557579040527343, 7200, 0, 0, 2463, 1283, 0, 0, 0, 0, 44232), -- Emote Bunny (Area: -Unknown- - Difficulty: 1)
(@CGUID+7, 77370, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1874.1868896484375, 229.013916015625, 76.6002044677734375, 4.278137683868408203, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44232), -- Lunarfall Footman (Area: -Unknown- - Difficulty: 1) (Auras: 178343 - Garrison Combat Throttle)
(@CGUID+8, 77376, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1843.564208984375, 239.529510498046875, 76.6606903076171875, 1.213001728057861328, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Lunarfall Woodcutter (Area: -Unknown- - Difficulty: 1)
(@CGUID+9, 77376, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1852.0831298828125, 229.473876953125, 76.2227020263671875, 0.49644559621810913, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Lunarfall Woodcutter (Area: -Unknown- - Difficulty: 1)
(@CGUID+10, 77617, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1845.015625, 236.9809112548828125, 76.65052032470703125, 6.04756784439086914, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Lunarfall Worker (Area: -Unknown- - Difficulty: 1)
(@CGUID+11, 85312, 1158, 7078, 7085, '1', 2559, 0, 0, 2, 1730.00146484375, 134.2320404052734375, 75.98162078857421875, 2.155446052551269531, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44232), -- Lunarfall Rifleman (Area: -Unknown- - Difficulty: 1) (Auras: 178343 - Garrison Combat Throttle)
(@CGUID+12, 77370, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1873.5172119140625, 238.067657470703125, 76.54178619384765625, 0.773609936237335205, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44232), -- Lunarfall Footman (Area: -Unknown- - Difficulty: 1) (Auras: 178343 - Garrison Combat Throttle)
(@CGUID+13, 79893, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1764.7708740234375, 215.888885498046875, 73.15350341796875, 5.127016544342041015, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Barbar (Area: -Unknown- - Difficulty: 1)
(@CGUID+14, 77376, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1870.8076171875, 236.1163177490234375, 76.614105224609375, 6.2650299072265625, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Lunarfall Woodcutter (Area: -Unknown- - Difficulty: 1)
(@CGUID+15, 82177, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1809.958984375, 209.224365234375, 70.49425506591796875, 3.639954090118408203, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Pippers (Area: -Unknown- - Difficulty: 1) (possible waypoints or random movement)
(@CGUID+16, 77370, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1879.670654296875, 227.8454437255859375, 76.97821044921875, 2.775372028350830078, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44232), -- Lunarfall Footman (Area: -Unknown- - Difficulty: 1) (Auras: 178343 - Garrison Combat Throttle)
(@CGUID+17, 77376, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1845.5989990234375, 240.6197967529296875, 76.6505584716796875, 3.141592741012573242, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Lunarfall Woodcutter (Area: -Unknown- - Difficulty: 1)
(@CGUID+18, 84267, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1804.6947021484375, 207.896759033203125, 70.38645172119140625, 0.318970650434494018, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Jongan Haphurst (Area: -Unknown- - Difficulty: 1) (possible waypoints or random movement)
(@CGUID+19, 77376, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1844.2535400390625, 242.47222900390625, 76.65673065185546875, 4.345870018005371093, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Lunarfall Woodcutter (Area: -Unknown- - Difficulty: 1)
(@CGUID+20, 79891, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1765.5972900390625, 215.1788177490234375, 73.13166046142578125, 3.042136430740356445, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Jenny Larson (Area: -Unknown- - Difficulty: 1)
(@CGUID+21, 77370, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1860.870849609375, 222.1271209716796875, 76.66330718994140625, 0.142052844166755676, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44232), -- Lunarfall Footman (Area: -Unknown- - Difficulty: 1) (Auras: 178343 - Garrison Combat Throttle)
(@CGUID+22, 77376, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1770.808349609375, 183.357940673828125, 72.00939178466796875, 3.099249601364135742, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Lunarfall Woodcutter (Area: -Unknown- - Difficulty: 1)
(@CGUID+23, 85312, 1158, 7078, 7085, '1', 2559, 0, 0, 2, 1881.5758056640625, 273.88836669921875, 76.83173370361328125, 1.397160768508911132, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44232), -- Lunarfall Rifleman (Area: -Unknown- - Difficulty: 1) (Auras: 178343 - Garrison Combat Throttle)
(@CGUID+24, 80026, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1854.1441650390625, 248.1041717529296875, 77.2621917724609375, 5.35130167007446289, 7200, 0, 0, 25, 0, 0, 0, 0, 0, 44232), -- Debug - Garrison - Bunny - Boss Emotes (Area: -Unknown- - Difficulty: 1)
(@CGUID+25, 77376, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1847.5035400390625, 235.484375, 76.65570831298828125, 2.286378860473632812, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Lunarfall Woodcutter (Area: -Unknown- - Difficulty: 1)
(@CGUID+26, 81347, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1848.4232177734375, 225.498565673828125, 75.89154815673828125, 3.775115966796875, 7200, 0, 0, 12315, 0, 0, 0, 0, 0, 44232), -- Sammy Schrimsher (Area: -Unknown- - Difficulty: 1) (possible waypoints or random movement)
(@CGUID+27, 81103, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1864.329833984375, 217.810760498046875, 76.74493408203125, 0.744948446750640869, 7200, 0, 0, 47164, 0, 0, 0, 0, 0, 44232), -- Dungar Longdrink (Area: -Unknown- - Difficulty: 1)
(@CGUID+28, 84455, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1847.3802490234375, 239.7118072509765625, 76.74977874755859375, 3.707327127456665039, 7200, 0, 0, 2463, 1283, 0, 0, 0, 0, 44232), -- Assistant Brightstone (Area: -Unknown- - Difficulty: 1)
(@CGUID+29, 86470, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1837.7100830078125, 257.5069580078125, 86.13414764404296875, 5.813615322113037109, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Pepe (Area: -Unknown- - Difficulty: 1)
(@CGUID+30, 81348, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1872.2603759765625, 206.2256927490234375, 77.152740478515625, 1.729609131813049316, 7200, 0, 0, 12315, 0, 0, 0, 0, 0, 44232), -- Rachelle Black (Area: -Unknown- - Difficulty: 1)
(@CGUID+31, 84776, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1841.57470703125, 252.08160400390625, 77.747314453125, 6.109762191772460937, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Aerun (Area: -Unknown- - Difficulty: 1)
(@CGUID+32, 81346, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1877.8109130859375, 209.3693695068359375, 77.10321044921875, 0.756071746349334716, 7200, 0, 0, 12315, 0, 0, 0, 0, 0, 44232), -- Provisioner Hanfa (Area: -Unknown- - Difficulty: 1) (possible waypoints or random movement)
(@CGUID+33, 81369, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1868.4149169921875, 265.095489501953125, 77.25528717041015625, 4.233183860778808593, 7200, 0, 0, 3325, 0, 0, 0, 0, 0, 44232), -- Architect Table (Area: -Unknown- - Difficulty: 1)
(@CGUID+34, 82386, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1870.91845703125, 264.37152099609375, 77.2551422119140625, 4.611006736755371093, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Elisa Vanning (Area: -Unknown- - Difficulty: 1)
(@CGUID+35, 82466, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1883.939208984375, 220.0885467529296875, 77.14704132080078125, 0.912091672420501708, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 44232), -- Aenir (Area: -Unknown- - Difficulty: 1)
(@CGUID+36, 80163, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1899.013916015625, 211.189239501953125, 77.14711761474609375, 5.213381767272949218, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Ken Loggin (Area: -Unknown- - Difficulty: 1)
(@CGUID+37, 83491, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1899.4427490234375, 203.5625, 77.3191680908203125, 1.650651216506958007, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 44232), -- Eileese Shadowsong (Area: -Unknown- - Difficulty: 1)
(@CGUID+38, 84246, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1902.9722900390625, 205.361114501953125, 77.21971893310546875, 2.593440532684326171, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Ashley Zerep (Area: -Unknown- - Difficulty: 1)
(@CGUID+39, 78564, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1886.2291259765625, 256.329864501953125, 76.6546173095703125, 3.549987316131591796, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Sergeant Crowler (Area: -Unknown- - Difficulty: 1) (Auras: 178343 - Garrison Combat Throttle)
(@CGUID+40, 81546, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1847.421875, 269.993072509765625, 78.397552490234375, 4.957489013671875, 7200, 0, 0, 3325, 0, 0, 0, 0, 0, 44232), -- Command Table (Area: -Unknown- - Difficulty: 1)
(@CGUID+41, 79953, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1847.0728759765625, 270.6632080078125, 78.397552490234375, 5.164353847503662109, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44232), -- Lieutenant Thorn (Area: -Unknown- - Difficulty: 1)
(@CGUID+42, 82776, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1854.30908203125, 258.286468505859375, 78.29833221435546875, 5.053887844085693359, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Deedree (Area: -Unknown- - Difficulty: 1)
(@CGUID+43, 77209, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1866.704833984375, 264.140625, 77.25528717041015625, 0.603618264198303222, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Baros Alexston (Area: -Unknown- - Difficulty: 1)
(@CGUID+44, 80645, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1889.6632080078125, 246.6041717529296875, 76.666259765625, 3.509580850601196289, 7200, 0, 0, 49260, 100, 0, 0, 0, 0, 44232), -- Cordana Felsong (Area: -Unknown- - Difficulty: 1)
(@CGUID+45, 81492, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1941.7257080078125, 330.435760498046875, 89.04918670654296875, 1.760889530181884765, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Bodrick Grey (Area: -Unknown- - Difficulty: 1)
(@CGUID+46, 80159, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1904.376708984375, 211.1813812255859375, 77.13956451416015625, 0.233182504773139953, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Arsenio Zerep (Area: -Unknown- - Difficulty: 1)
(@CGUID+47, 81491, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1942.296875, 332.107635498046875, 89.04918670654296875, 4.148911952972412109, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232), -- Amber Kearnen (Area: -Unknown- - Difficulty: 1)
(@CGUID+48, 81935, 1158, 7078, 7085, '1', 2559, 0, 0, 0, 1948.35400390625, 119.0615615844726562, 81.442291259765625, 3.915964841842651367, 7200, 0, 0, 2463, 1283, 0, 0, 0, 0, 44232), -- Scrap Sparkfuse (Area: -Unknown- - Difficulty: 1) (possible waypoints or random movement)
(@CGUID+49, 77730, 1158, 7078, 7085, '1', 2559, 0, 0, 1, 1892.7569580078125, 97.4774322509765625, 84.222900390625, 0.058659851551055908, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44232); -- Timothy Leens (Area: -Unknown- - Difficulty: 1)

UPDATE `creature` SET `terrainSwapMap` = 1158 WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+49;

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+49;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+25, 0, 0, 5, 1, 0, 0, 0, 0, 4, ''), -- Lunarfall Woodcutter
(@CGUID+10, 0, 0, 5, 1, 0, 0, 0, 0, 4, ''), -- Lunarfall Woodcutter
(@CGUID+8, 0, 0, 5, 1, 0, 0, 0, 0, 4, ''), -- Lunarfall Woodcutter
(@CGUID+17, 0, 0, 5, 1, 0, 0, 0, 0, 4, ''), -- Lunarfall Woodcutter
(@CGUID+19, 0, 0, 5, 1, 0, 0, 0, 0, 4, ''), -- Lunarfall Woodcutter
(@CGUID+1, 0, 0, 5, 1, 0, 0, 0, 0, 4, ''), -- Lunarfall Woodcutter
(@CGUID+46, 0, 0, 0, 257, 69, 0, 0, 0, 0, ''), -- Arsenio Zerep
(@CGUID+41, 0, 0, 0, 257, 415, 0, 0, 0, 0, ''); -- Lieutenant Thorn

-- Creature Addon Template
DELETE FROM `creature_template_addon` WHERE `entry` IN (80159 /*80159 (Arsenio Zerep)*/, 81492 /*81492 (Bodrick Grey)*/, 77209 /*77209 (Baros Alexston)*/, 82776 /*82776 (Deedree)*/, 79953 /*79953 (Lieutenant Thorn)*/, 78564 /*78564 (Sergeant Crowler) - Garrison Combat Throttle*/, 84246 /*84246 (Ashley Zerep)*/, 83491 /*83491 (Eileese Shadowsong)*/, 82386 /*82386 (Elisa Vanning)*/, 81346 /*81346 (Provisioner Hanfa)*/, 84776 /*84776 (Aerun)*/, 81348 /*81348 (Rachelle Black)*/, 86470 /*86470 (Pepe)*/, 81347 /*81347 (Sammy Schrimsher)*/, 80026 /*80026 (Debug - Garrison - Bunny - Boss Emotes)*/, 79891 /*79891 (Jenny Larson)*/, 79893 /*79893 (Barbar)*/, 85312 /*85312 (Lunarfall Rifleman) - Garrison Combat Throttle*/, 79603 /*79603 (Emote Bunny)*/, 82401 /*82401 (Grinhilda Quartzhammer)*/, 81152 /*81152 (Scout Valdez) - Read Scroll*/, 79894 /*79894 (Dinah)*/, 77370 /*77370 (Lunarfall Footman) - Garrison Combat Throttle*/, 77376 /*77376 (Lunarfall Woodcutter)*/, 77617 /*77617 (Lunarfall Worker)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(80159, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 80159 (Arsenio Zerep)
(81492, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''), -- 81492 (Bodrick Grey)
(77209, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 77209 (Baros Alexston)
(82776, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 82776 (Deedree)
(79953, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 79953 (Lieutenant Thorn)
(78564, 0, 0, 0, 0, 0, 0, 0, 0, 0, '178343'), -- 78564 (Sergeant Crowler) - Garrison Combat Throttle
(84246, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 84246 (Ashley Zerep)
(83491, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 83491 (Eileese Shadowsong)
(82386, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 82386 (Elisa Vanning)
(81346, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 81346 (Provisioner Hanfa)
(84776, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 84776 (Aerun)
(81348, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 81348 (Rachelle Black)
(86470, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- 86470 (Pepe)
(81347, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 81347 (Sammy Schrimsher)
(80026, 0, 0, 0, 1, 0, 0, 0, 0, 5, ''), -- 80026 (Debug - Garrison - Bunny - Boss Emotes)
(79891, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 79891 (Jenny Larson)
(79893, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 79893 (Barbar)
(85312, 0, 0, 0, 0, 0, 0, 0, 0, 4, '178343'), -- 85312 (Lunarfall Rifleman) - Garrison Combat Throttle
(79603, 0, 0, 50331648, 1, 0, 0, 0, 0, 4, ''), -- 79603 (Emote Bunny)
(82401, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 82401 (Grinhilda Quartzhammer)
(81152, 0, 0, 0, 1, 0, 0, 0, 0, 0, '133464'), -- 81152 (Scout Valdez) - Read Scroll
(79894, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- 79894 (Dinah)
(77370, 0, 0, 0, 0, 0, 0, 0, 0, 4, '178343'), -- 77370 (Lunarfall Footman) - Garrison Combat Throttle
(77376, 0, 0, 0, 1, 0, 0, 0, 0, 4, ''), -- 77376 (Lunarfall Woodcutter)
(77617, 0, 0, 0, 256, 0, 0, 0, 0, 4, ''); -- 77617 (Lunarfall Worker)

-- Creature Template
UPDATE `creature_template` SET `unit_flags3`=1048608 WHERE `entry`=77730; -- Timothy Leens
UPDATE `creature_template` SET `gossip_menu_id`=16464 WHERE `entry`=80159; -- Arsenio Zerep
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=80645; -- Cordana Felsong
UPDATE `creature_template` SET `gossip_menu_id`=16998 WHERE `entry`=82776; -- Deedree
UPDATE `creature_template` SET `gossip_menu_id`=16811 WHERE `entry`=79953; -- Lieutenant Thorn
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=81546; -- Command Table
UPDATE `creature_template` SET `gossip_menu_id`=16916 WHERE `entry`=78564; -- Sergeant Crowler
UPDATE `creature_template` SET `gossip_menu_id`=16750 WHERE `entry`=83491; -- Eileese Shadowsong
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=81369; -- Architect Table
UPDATE `creature_template` SET `gossip_menu_id`=16905 WHERE `entry`=84776; -- Aerun
UPDATE `creature_template` SET `gossip_menu_id`=17199 WHERE `entry`=81348; -- Rachelle Black
UPDATE `creature_template` SET `npcflag`=17179869185, `unit_flags3`=32, `gossip_menu_id`=16613 WHERE `entry`=84455; -- Assistant Brightstone
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=81103; -- Dungar Longdrink
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=80026; -- Debug - Garrison - Bunny - Boss Emotes
UPDATE `creature_template` SET `unit_flags3`=1048608 WHERE `entry`=85312; -- Lunarfall Rifleman
UPDATE `creature_template` SET `gossip_menu_id`=16670 WHERE `entry`=81152; -- Scout Valdez
UPDATE `creature_template` SET `unit_flags3`=1048608 WHERE `entry`=77370; -- Lunarfall Footman

-- Scaling & ModelInfo
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=1 AND `Entry` IN (81491,80159,81492,80645,77209,82776,79953,81546,78564,84246,83491,80163,82386,81369,81346,84776,81348,84455,81103,81347,82177,85312,81152,77370,77376,77617));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(81491, 1, 0, 0, 302, 44232),
(80159, 1, 0, 0, 63, 44232),
(81492, 1, 0, 0, 302, 44232),
(80645, 1, 0, 0, 63, 44232),
(77209, 1, 0, 0, 63, 44232),
(82776, 1, 0, 0, 63, 44232),
(79953, 1, 0, 0, 302, 44232),
(81546, 1, 0, 0, 63, 44232),
(78564, 1, 0, 0, 302, 44232),
(84246, 1, 0, 0, 302, 44232),
(83491, 1, 0, 0, 302, 44232),
(80163, 1, 0, 0, 63, 44232),
(82386, 1, 0, 0, 302, 44232),
(81369, 1, 0, 0, 63, 44232),
(81346, 1, 0, 0, 63, 44232),
(84776, 1, 0, 0, 302, 44232),
(81348, 1, 0, 0, 63, 44232),
(84455, 1, 0, 0, 302, 44232),
(81103, 1, 0, 0, 881, 44232),
(81347, 1, 0, 0, 63, 44232),
(82177, 1, 0, 0, 63, 44232),
(85312, 1, 0, 0, 302, 44232),
(81152, 1, 0, 0, 302, 44232),
(77370, 1, 0, 0, 302, 44232),
(77376, 1, 0, 0, 302, 44232),
(77617, 1, 0, 0, 302, 44232);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=44232 WHERE (`DifficultyID`=1 AND `Entry` IN (77730,81935,82466,86470,80026,79891,84267,79893,79603,82401,79894));

UPDATE `creature_model_info` SET `VerifiedBuild`=44232 WHERE `DisplayID` IN (54034, 56734, 38876, 55537, 56418, 50650, 1357, 57351, 58063, 56503, 61187, 58224, 57739, 59657, 56648, 53823, 59292, 56600, 58492, 56607, 59624, 58062, 5128, 56606, 23767, 56615, 55321, 33285, 44820, 51407, 61417, 54616, 58226, 53835, 11686, 53826, 56245, 53840, 53841, 54615);
UPDATE `creature_model_info` SET `BoundingRadius`=0.282464146614074707, `CombatReach`=1.018367290496826171, `VerifiedBuild`=44232 WHERE `DisplayID`=51414;

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+48;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 229769, 1158, 7078, 7085, '1', 2559, 0, 1781.18408203125, 178.329864501953125, 71.8646240234375, 2.225293636322021484, 0, 0, 0.896872520446777343, 0.442289173603057861, 7200, 255, 1, 44232), -- Chair (Area: -Unknown- - Difficulty: 1)
(@OGUID+1, 233162, 1158, 7078, 7085, '1', 2559, 0, 1730.43408203125, 133.7135467529296875, 75.9589996337890625, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 7200, 255, 1, 44232), -- Stool (Area: -Unknown- - Difficulty: 1)
(@OGUID+2, 229501, 1158, 7078, 7085, '1', 2559, 0, 1829.8958740234375, 197.55035400390625, 72.02127838134765625, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 7200, 255, 1, 44232), -- Small Plot (Area: -Unknown- - Difficulty: 1)
(@OGUID+3, 229498, 1158, 7078, 7085, '1', 2559, 0, 1797.720458984375, 206.20660400390625, 70.17173004150390625, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 7200, 255, 0, 44232), -- Front Gate (Area: -Unknown- - Difficulty: 1)
(@OGUID+4, 232143, 1158, 7078, 7085, '1', 2559, 0, 1911.5504150390625, 232.9791717529296875, 76.63956451416015625, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 7200, 255, 1, 44232), -- Large Plot (Area: -Unknown- - Difficulty: 1)
(@OGUID+5, 233141, 1158, 7078, 7085, '1', 2559, 0, 1773.9375, 177.095489501953125, 71.88083648681640625, 0, 0, 0, 0, 1, 7200, 255, 1, 44232), -- Garrison - Delivery for Pickup (Area: -Unknown- - Difficulty: 1)
(@OGUID+6, 232252, 1158, 7078, 7085, '1', 2559, 0, 1740.94970703125, 210.09722900390625, 73.3454742431640625, 1.271273255348205566, 0, 0, 0.593689918518066406, 0.804693877696990966, 7200, 255, 1, 44232), -- Pippers' Buried Supplies (Area: -Unknown- - Difficulty: 1)
(@OGUID+7, 232528, 1158, 7078, 7085, '1', 2559, 0, 1751.7396240234375, 211.84722900390625, 73.25347137451171875, 4.379182815551757812, 0, 0, -0.81457805633544921, 0.580053985118865966, 7200, 255, 1, 44232), -- Telescope - Garrison Surveying (Area: -Unknown- - Difficulty: 1)
(@OGUID+8, 232249, 1158, 7078, 7085, '1', 2559, 0, 1740.751708984375, 209.6145782470703125, 73.5001068115234375, 2.809833765029907226, 0.039116859436035156, 0.018984794616699218, 0.985487937927246093, 0.164082303643226623, 7200, 255, 1, 44232), -- Bone (Area: -Unknown- - Difficulty: 1)
(@OGUID+9, 232249, 1158, 7078, 7085, '1', 2559, 0, 1740.7413330078125, 209.5381927490234375, 73.5086822509765625, 3.850808143615722656, 0.031193256378173828, 0.016252517700195312, -0.9371490478515625, 0.347151994705200195, 7200, 255, 1, 44232), -- Bone (Area: -Unknown- - Difficulty: 1)
(@OGUID+10, 232250, 1158, 7078, 7085, '1', 2559, 0, 1870.810791015625, 199.904510498046875, 77.2488861083984375, 1.281599760055541992, -0.03142213821411132, 0.04563140869140625, 0.596825599670410156, 0.800455927848815917, 7200, 255, 1, 44232), -- Pippers' Buried Supplies (Area: -Unknown- - Difficulty: 1)
(@OGUID+11, 232249, 1158, 7078, 7085, '1', 2559, 0, 1843.59033203125, 256.369781494140625, 78.230438232421875, 3.850808143615722656, 0.031193256378173828, 0.016252517700195312, -0.9371490478515625, 0.347151994705200195, 7200, 255, 1, 44232), -- Bone (Area: -Unknown- - Difficulty: 1)
(@OGUID+12, 229755, 1158, 7078, 7085, '1', 2559, 0, 1847.5035400390625, 235.484375, 76.65570831298828125, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 7200, 255, 1, 44232), -- Chair (Area: -Unknown- - Difficulty: 1)
(@OGUID+13, 232248, 1158, 7078, 7085, '1', 2559, 0, 1843.5, 256.102447509765625, 78.0385894775390625, 1.393552780151367187, 0.035747051239013671, -0.04434585571289062, 0.640661239624023437, 0.765708029270172119, 7200, 255, 1, 44232), -- Pippers' Buried Supplies (Area: -Unknown- - Difficulty: 1)
(@OGUID+14, 232249, 1158, 7078, 7085, '1', 2559, 0, 1871.0399169921875, 199.4947967529296875, 77.39774322509765625, 3.850808143615722656, 0.031193256378173828, 0.016252517700195312, -0.9371490478515625, 0.347151994705200195, 7200, 255, 1, 44232), -- Bone (Area: -Unknown- - Difficulty: 1)
(@OGUID+15, 232249, 1158, 7078, 7085, '1', 2559, 0, 1843.6007080078125, 256.447906494140625, 78.23628997802734375, 2.809833765029907226, 0.039116859436035156, 0.018984794616699218, 0.985487937927246093, 0.164082303643226623, 7200, 255, 1, 44232), -- Bone (Area: -Unknown- - Difficulty: 1)
(@OGUID+16, 229760, 1158, 7078, 7085, '1', 2559, 0, 1845.5989990234375, 240.6197967529296875, 76.6505584716796875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 44232), -- Chair (Area: -Unknown- - Difficulty: 1)
(@OGUID+17, 229758, 1158, 7078, 7085, '1', 2559, 0, 1843.564208984375, 239.529510498046875, 76.6606903076171875, 1.213001728057861328, 0, 0, 0.569995880126953125, 0.821647584438323974, 7200, 255, 1, 44232), -- Chair (Area: -Unknown- - Difficulty: 1)
(@OGUID+18, 232249, 1158, 7078, 7085, '1', 2559, 0, 1871.0504150390625, 199.5711822509765625, 77.38889312744140625, 2.809833765029907226, 0.039116859436035156, 0.018984794616699218, 0.985487937927246093, 0.164082303643226623, 7200, 255, 1, 44232), -- Bone (Area: -Unknown- - Difficulty: 1)
(@OGUID+19, 229759, 1158, 7078, 7085, '1', 2559, 0, 1844.2535400390625, 242.47222900390625, 76.65673065185546875, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 7200, 255, 1, 44232), -- Chair (Area: -Unknown- - Difficulty: 1)
(@OGUID+20, 229756, 1158, 7078, 7085, '1', 2559, 0, 1845.015625, 236.9809112548828125, 76.65052032470703125, 6.04756784439086914, 0, 0, -0.11753654479980468, 0.993068516254425048, 7200, 255, 1, 44232), -- Chair (Area: -Unknown- - Difficulty: 1)
(@OGUID+21, 223034, 1158, 7078, 7085, '1', 2559, 0, 1846.29345703125, 236.234375, 77.50846099853515625, 5.794659614562988281, 0, 0, -0.24184131622314453, 0.970315814018249511, 7200, 255, 1, 44232), -- Hearthstone Gameboard (Area: -Unknown- - Difficulty: 1)
(@OGUID+22, 229757, 1158, 7078, 7085, '1', 2559, 0, 1847.0989990234375, 237.6180572509765625, 76.65557861328125, 3.935721635818481445, 0, 0, -0.92220020294189453, 0.386712819337844848, 7200, 255, 1, 44232), -- Chair (Area: -Unknown- - Difficulty: 1)
(@OGUID+23, 207320, 1158, 7078, 7085, '1', 2559, 0, 1889.439208984375, 252.7309112548828125, 76.573150634765625, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 7200, 255, 1, 44232), -- Hero's Call Board (Area: -Unknown- - Difficulty: 1)
(@OGUID+24, 239178, 1158, 7078, 7085, '1', 2559, 0, 1847.421875, 269.993072509765625, 78.31421661376953125, 4.957489967346191406, 0, 0, -0.61536407470703125, 0.788242995738983154, 7200, 255, 1, 44232), -- Command Table Collision (Area: -Unknown- - Difficulty: 1)
(@OGUID+25, 232234, 1158, 7078, 7085, '1', 2559, 0, 1845.1904296875, 264.559234619140625, 78.19712066650390625, 0.310090214014053344, 0, 0, 0.154424667358398437, 0.988004565238952636, 7200, 255, 1, 44232), -- Woodbench (Area: -Unknown- - Difficulty: 1)
(@OGUID+26, 232235, 1158, 7078, 7085, '1', 2559, 0, 1848.7646484375, 267.178924560546875, 78.19712066650390625, 3.354323625564575195, 0, 0, -0.99434852600097656, 0.10616496205329895, 7200, 255, 1, 44232), -- Woodbench (Area: -Unknown- - Difficulty: 1)
(@OGUID+27, 239184, 1158, 7078, 7085, '1', 2559, 0, 1868.4149169921875, 265.095489501953125, 77.1719512939453125, 4.233184814453125, 0, 0, -0.85471439361572265, 0.519098520278930664, 7200, 255, 1, 44232), -- Architect Table Collision (Area: -Unknown- - Difficulty: 1)
(@OGUID+28, 229752, 1158, 7078, 7085, '1', 2559, 0, 1896.8472900390625, 207.421875, 77.0021820068359375, 0.392699003219604492, 0, 0, 0.195090293884277343, 0.980785250663757324, 7200, 255, 1, 44232), -- Chair (Area: -Unknown- - Difficulty: 1)
(@OGUID+29, 232224, 1158, 7078, 7085, '1', 2559, 0, 1850.1099853515625, 262.955780029296875, 78.19712066650390625, 3.40511488914489746, 0, 0, -0.99133205413818359, 0.131380096077919006, 7200, 255, 1, 44232), -- Woodbench (Area: -Unknown- - Difficulty: 1)
(@OGUID+30, 229753, 1158, 7078, 7085, '1', 2559, 0, 1898.5, 205.3958282470703125, 77.02211761474609375, 0.759216904640197753, 0, 0, 0.370556831359863281, 0.928809821605682373, 7200, 255, 1, 44232), -- Chair (Area: -Unknown- - Difficulty: 1)
(@OGUID+31, 236356, 1158, 7078, 7085, '1', 2559, 0, 1853.07470703125, 258.055572509765625, 78.40399169921875, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 7200, 255, 1, 44232), -- Mailbox (Area: -Unknown- - Difficulty: 1)
(@OGUID+32, 232156, 1158, 7078, 7085, '1', 2559, 0, 1901.4461669921875, 204.267364501953125, 76.91858673095703125, 3.516837835311889648, 0, 0, -0.98245048522949218, 0.186523601412773132, 7200, 255, 1, 44232), -- Braddock's Braggot (Area: -Unknown- - Difficulty: 1)
(@OGUID+33, 232225, 1158, 7078, 7085, '1', 2559, 0, 1845.90576171875, 260.8704833984375, 78.19712066650390625, 0.31016746163368225, 0, 0, 0.154462814331054687, 0.987998604774475097, 7200, 255, 1, 44232), -- Woodbench (Area: -Unknown- - Difficulty: 1)
(@OGUID+34, 229750, 1158, 7078, 7085, '1', 2559, 0, 1900.248291015625, 208.203125, 77.056396484375, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 7200, 255, 1, 44232), -- Campfire (Area: -Unknown- - Difficulty: 1)
(@OGUID+35, 232507, 1158, 7078, 7085, '1', 2559, 0, 1892.998291015625, 204.1840362548828125, 78.48502349853515625, 4.484727859497070312, -0.25537300109863281, 0.099481582641601562, -0.77355861663818359, 0.57139754295349121, 7200, 255, 1, 44232), -- Lunarfall Egg (Area: -Unknown- - Difficulty: 1)
(@OGUID+36, 230865, 1158, 7078, 7085, '1', 2559, 0, 1905.140625, 214.46875, 78.4273529052734375, 3.478188514709472656, 0, 0, -0.9858713150024414, 0.167504489421844482, 7200, 255, 1, 44232), -- List of Ingredients (Area: -Unknown- - Difficulty: 1)
(@OGUID+37, 181144, 1158, 7078, 7085, '1', 2559, 0, 1906.4322509765625, 211.2291717529296875, 78.7294158935546875, 4.4648895263671875, 0, 0, -0.78898048400878906, 0.614418268203735351, 7200, 255, 1, 44232), -- Bowl of Fruit (Area: -Unknown- - Difficulty: 1)
(@OGUID+38, 181143, 1158, 7078, 7085, '1', 2559, 0, 1906.078125, 210.5225677490234375, 78.73334503173828125, 1.596973419189453125, 0, 0, 0.71630096435546875, 0.697791457176208496, 7200, 255, 1, 44232), -- Fish of the Day (Area: -Unknown- - Difficulty: 1)
(@OGUID+39, 229751, 1158, 7078, 7085, '1', 2559, 0, 1903.1875, 207.1041717529296875, 77.0313568115234375, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 7200, 255, 1, 44232), -- Chair (Area: -Unknown- - Difficulty: 1)
(@OGUID+40, 236821, 1158, 7078, 7085, '1', 2559, 0, 1906.3646240234375, 212.0989532470703125, 78.68111419677734375, 3.971838951110839843, 0, 0, -0.91506671905517578, 0.403302490711212158, 7200, 255, 1, 44232), -- Crab Pot (Area: -Unknown- - Difficulty: 1)
(@OGUID+41, 233141, 1158, 7078, 7085, '1', 2559, 0, 1892.9566650390625, 272.453125, 76.6080322265625, 0, 0, 0, 0, 1, 7200, 255, 1, 44232), -- Garrison - Delivery for Pickup (Area: -Unknown- - Difficulty: 1)
(@OGUID+42, 233163, 1158, 7078, 7085, '1', 2559, 0, 1895.6788330078125, 271.255218505859375, 76.60886383056640625, 2.766347646713256835, 0, 0, 0.982450485229492187, 0.186523601412773132, 7200, 255, 1, 44232), -- Stool (Area: -Unknown- - Difficulty: 1)
(@OGUID+43, 230298, 1158, 7078, 7085, '1', 2559, 0, 1915.2117919921875, 202.765625, 76.761474609375, 0.91629725694656372, 0, 0, 0.442288398742675781, 0.896872878074645996, 7200, 255, 1, 44232), -- Outhouse (Area: -Unknown- - Difficulty: 1)
(@OGUID+44, 233141, 1158, 7078, 7085, '1', 2559, 0, 1922.1944580078125, 327.102447509765625, 89.6670379638671875, 0, 0, 0, 0, 1, 7200, 255, 1, 44232), -- Garrison - Delivery for Pickup (Area: -Unknown- - Difficulty: 1)
(@OGUID+45, 232249, 1158, 7078, 7085, '1', 2559, 0, 1965.3629150390625, 334.036468505859375, 88.95493316650390625, 2.809833765029907226, 0.039116859436035156, 0.018984794616699218, 0.985487937927246093, 0.164082303643226623, 7200, 255, 1, 44232), -- Bone (Area: -Unknown- - Difficulty: 1)
(@OGUID+46, 232251, 1158, 7078, 7085, '1', 2559, 0, 1965.49658203125, 333.354156494140625, 88.87424468994140625, 1.355357766151428222, 0, 0, 0.626986503601074218, 0.779030144214630126, 7200, 255, 1, 44232), -- Pippers' Buried Supplies (Area: -Unknown- - Difficulty: 1)
(@OGUID+47, 232249, 1158, 7078, 7085, '1', 2559, 0, 1965.3524169921875, 333.9600830078125, 88.95555877685546875, 3.850808143615722656, 0.031193256378173828, 0.016252517700195312, -0.9371490478515625, 0.347151994705200195, 7200, 255, 1, 44232), -- Bone (Area: -Unknown- - Difficulty: 1)
(@OGUID+48, 233141, 1158, 7078, 7085, '1', 2559, 0, 1973.079833984375, 89.84375, 85.37319183349609375, 0, 0, 0, 0, 1, 7200, 255, 1, 44232); -- Garrison - Delivery for Pickup (Area: -Unknown- - Difficulty: 1)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+48;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+6, 0, 0, 0, 1, 2437, 0), -- Pippers' Buried Supplies
(@OGUID+10, 0, 0, 0, 1, 2437, 0), -- Pippers' Buried Supplies
(@OGUID+13, 0, 0, 0, 1, 2437, 0), -- Pippers' Buried Supplies
(@OGUID+23, 0, 0, 0, 1, 8830, 0), -- Hero's Call Board
(@OGUID+25, 0, 0, -0.60181492567062377, 0.798635601997375488, 0, 0), -- Woodbench
(@OGUID+26, 0, 0, -0.60181492567062377, 0.798635601997375488, 0, 0), -- Woodbench
(@OGUID+29, 0, 0, -0.60181492567062377, 0.798635601997375488, 0, 0), -- Woodbench
(@OGUID+33, 0, 0, -0.60181492567062377, 0.798635601997375488, 0, 0), -- Woodbench
(@OGUID+35, 0, 0, 0, 1, 2437, 0), -- Lunarfall Egg
(@OGUID+46, 0, 0, 0, 1, 2437, 0); -- Pippers' Buried Supplies

UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry` IN (232251, 232250, 232252, 232248); -- Pippers' Buried Supplies
UPDATE `gameobject_template_addon` SET `flags`=262144, `WorldEffectID`=8830 WHERE `entry`=207320; -- Hero's Call Board
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=232143; -- Large Plot
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=229501; -- Small Plot
UPDATE `gameobject_template_addon` SET `flags`=48 WHERE `entry`=229498; -- Front Gate
UPDATE `gameobject_template_addon` SET `faction`=12 WHERE `entry`=236356; -- Mailbox
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=232507; -- Lunarfall Egg
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=239184; -- Architect Table Collision

-- Vendor Data
DELETE FROM `npc_vendor` WHERE (`entry`=81347 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=183953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=183954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=183955 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=117445 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=115351 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81347 AND `item`=117452 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=183953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=183954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=183955 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=117445 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=115351 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82386 AND `item`=117452 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82776 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82776 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82776 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82776 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82776 AND `item`=183953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82776 AND `item`=183954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=82776 AND `item`=183955 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81348 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81348 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81348 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81348 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81348 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81348 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81348 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=183953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=183954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=183955 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=117445 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=115351 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81346 AND `item`=117452 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=84246 AND `item`=111556 AND `ExtendedCost`=5498 AND `type`=1) OR (`entry`=84246 AND `item`=110611 AND `ExtendedCost`=5498 AND `type`=1) OR (`entry`=84246 AND `item`=115524 AND `ExtendedCost`=5498 AND `type`=1) OR (`entry`=84246 AND `item`=112377 AND `ExtendedCost`=5498 AND `type`=1) OR (`entry`=84246 AND `item`=111366 AND `ExtendedCost`=5498 AND `type`=1) OR (`entry`=84246 AND `item`=108257 AND `ExtendedCost`=5498 AND `type`=1) OR (`entry`=84246 AND `item`=108996 AND `ExtendedCost`=5498 AND `type`=1) OR (`entry`=84246 AND `item`=127759 AND `ExtendedCost`=5502 AND `type`=1) OR (`entry`=84246 AND `item`=118472 AND `ExtendedCost`=5502 AND `type`=1) OR (`entry`=84246 AND `item`=113262 AND `ExtendedCost`=5500 AND `type`=1) OR (`entry`=84246 AND `item`=113261 AND `ExtendedCost`=5500 AND `type`=1) OR (`entry`=84246 AND `item`=113263 AND `ExtendedCost`=5500 AND `type`=1) OR (`entry`=84246 AND `item`=113264 AND `ExtendedCost`=5500 AND `type`=1) OR (`entry`=80159 AND `item`=115354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=117474 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=117473 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=117472 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=117452 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=122560 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=122555 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=122559 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=122558 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=122557 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80159 AND `item`=122556 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78564 AND `item`=141642 AND `ExtendedCost`=5827 AND `type`=1) OR (`entry`=78564 AND `item`=120349 AND `ExtendedCost`=5488 AND `type`=1) OR (`entry`=78564 AND `item`=120348 AND `ExtendedCost`=5488 AND `type`=1) OR (`entry`=78564 AND `item`=120347 AND `ExtendedCost`=5488 AND `type`=1) OR (`entry`=78564 AND `item`=122406 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122399 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122401 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122404 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122407 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122409 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122410 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122414 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122415 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122417 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122422 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122423 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=133883 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=133878 AND `ExtendedCost`=5809 AND `type`=1) OR (`entry`=78564 AND `item`=122500 AND `ExtendedCost`=5805 AND `type`=1) OR (`entry`=78564 AND `item`=122490 AND `ExtendedCost`=5805 AND `type`=1) OR (`entry`=78564 AND `item`=122487 AND `ExtendedCost`=5805 AND `type`=1) OR (`entry`=78564 AND `item`=122307 AND `ExtendedCost`=5805 AND `type`=1) OR (`entry`=78564 AND `item`=122503 AND `ExtendedCost`=5806 AND `type`=1) OR (`entry`=78564 AND `item`=122497 AND `ExtendedCost`=5806 AND `type`=1) OR (`entry`=78564 AND `item`=128373 AND `ExtendedCost`=5543 AND `type`=1) OR (`entry`=78564 AND `item`=122272 AND `ExtendedCost`=5807 AND `type`=1) OR (`entry`=78564 AND `item`=122273 AND `ExtendedCost`=5808 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(81347, 24, 183950, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81347, 23, 180733, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81347, 22, 183951, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81347, 21, 183952, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81347, 20, 183953, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81347, 19, 183954, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81347, 18, 183955, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81347, 17, 64670, 0, 0, 1, 0, 0, 44232), -- Vanishing Powder
(81347, 16, 39505, 0, 0, 1, 0, 0, 44232), -- Virtuoso Inking Set
(81347, 15, 20815, 0, 0, 1, 0, 0, 44232), -- Jeweler's Kit
(81347, 14, 5956, 0, 0, 1, 0, 0, 44232), -- Blacksmith Hammer
(81347, 13, 6217, 0, 0, 1, 0, 0, 44232), -- Copper Rod
(81347, 12, 6256, 0, 0, 1, 0, 0, 44232), -- Fishing Pole
(81347, 11, 85663, 0, 0, 1, 0, 0, 44232), -- Herbalist's Spade
(81347, 10, 7005, 0, 0, 1, 0, 0, 44232), -- Skinning Knife
(81347, 9, 2901, 0, 0, 1, 0, 0, 44232), -- Mining Pick
(81347, 8, 117445, 0, 0, 1, 0, 0, 44232), -- Clefthoof Hide Satchel
(81347, 7, 90146, 0, 0, 1, 0, 0, 44232), -- Tinker's Kit
(81347, 6, 4470, 0, 0, 1, 0, 0, 44232), -- Simple Wood
(81347, 5, 38682, 0, 0, 1, 0, 0, 44232), -- Enchanting Vellum
(81347, 4, 3371, 0, 0, 1, 0, 0, 44232), -- Crystal Vial
(81347, 3, 39354, 0, 0, 1, 0, 0, 44232), -- Light Parchment
(81347, 2, 115351, 0, 0, 1, 0, 0, 44232), -- "Rylak Claws"
(81347, 1, 117452, 0, 0, 1, 0, 0, 44232), -- Gorgrond Mineral Water
(82386, 24, 183950, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82386, 23, 180733, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82386, 22, 183951, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82386, 21, 183952, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82386, 20, 183953, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82386, 19, 183954, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82386, 18, 183955, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82386, 17, 64670, 0, 0, 1, 0, 0, 44232), -- Vanishing Powder
(82386, 16, 39505, 0, 0, 1, 0, 0, 44232), -- Virtuoso Inking Set
(82386, 15, 20815, 0, 0, 1, 0, 0, 44232), -- Jeweler's Kit
(82386, 14, 5956, 0, 0, 1, 0, 0, 44232), -- Blacksmith Hammer
(82386, 13, 6217, 0, 0, 1, 0, 0, 44232), -- Copper Rod
(82386, 12, 6256, 0, 0, 1, 0, 0, 44232), -- Fishing Pole
(82386, 11, 85663, 0, 0, 1, 0, 0, 44232), -- Herbalist's Spade
(82386, 10, 7005, 0, 0, 1, 0, 0, 44232), -- Skinning Knife
(82386, 9, 2901, 0, 0, 1, 0, 0, 44232), -- Mining Pick
(82386, 8, 117445, 0, 0, 1, 0, 0, 44232), -- Clefthoof Hide Satchel
(82386, 7, 90146, 0, 0, 1, 0, 0, 44232), -- Tinker's Kit
(82386, 6, 4470, 0, 0, 1, 0, 0, 44232), -- Simple Wood
(82386, 5, 38682, 0, 0, 1, 0, 0, 44232), -- Enchanting Vellum
(82386, 4, 3371, 0, 0, 1, 0, 0, 44232), -- Crystal Vial
(82386, 3, 39354, 0, 0, 1, 0, 0, 44232), -- Light Parchment
(82386, 2, 115351, 0, 0, 1, 0, 0, 44232), -- "Rylak Claws"
(82386, 1, 117452, 0, 0, 1, 0, 0, 44232), -- Gorgrond Mineral Water
(82776, 28, 183950, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82776, 27, 180733, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82776, 26, 183951, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82776, 25, 183952, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82776, 24, 183953, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82776, 23, 183954, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(82776, 22, 183955, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81348, 7, 3857, 0, 0, 1, 0, 0, 44232), -- Coal
(81348, 6, 18567, 0, 0, 1, 0, 0, 44232), -- Elemental Flux
(81348, 5, 3466, 0, 0, 1, 0, 0, 44232), -- Strong Flux
(81348, 4, 2880, 0, 0, 1, 0, 0, 44232), -- Weak Flux
(81348, 3, 180733, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81348, 2, 5956, 0, 0, 1, 0, 0, 44232), -- Blacksmith Hammer
(81348, 1, 2901, 0, 0, 1, 0, 0, 44232), -- Mining Pick
(81346, 24, 183950, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81346, 23, 180733, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81346, 22, 183951, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81346, 21, 183952, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81346, 20, 183953, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81346, 19, 183954, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81346, 18, 183955, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(81346, 17, 64670, 0, 0, 1, 0, 0, 44232), -- Vanishing Powder
(81346, 16, 39505, 0, 0, 1, 0, 0, 44232), -- Virtuoso Inking Set
(81346, 15, 20815, 0, 0, 1, 0, 0, 44232), -- Jeweler's Kit
(81346, 14, 5956, 0, 0, 1, 0, 0, 44232), -- Blacksmith Hammer
(81346, 13, 6217, 0, 0, 1, 0, 0, 44232), -- Copper Rod
(81346, 12, 6256, 0, 0, 1, 0, 0, 44232), -- Fishing Pole
(81346, 11, 85663, 0, 0, 1, 0, 0, 44232), -- Herbalist's Spade
(81346, 10, 7005, 0, 0, 1, 0, 0, 44232), -- Skinning Knife
(81346, 9, 2901, 0, 0, 1, 0, 0, 44232), -- Mining Pick
(81346, 8, 117445, 0, 0, 1, 0, 0, 44232), -- Clefthoof Hide Satchel
(81346, 7, 90146, 0, 0, 1, 0, 0, 44232), -- Tinker's Kit
(81346, 6, 4470, 0, 0, 1, 0, 0, 44232), -- Simple Wood
(81346, 5, 38682, 0, 0, 1, 0, 0, 44232), -- Enchanting Vellum
(81346, 4, 3371, 0, 0, 1, 0, 0, 44232), -- Crystal Vial
(81346, 3, 39354, 0, 0, 1, 0, 0, 44232), -- Light Parchment
(81346, 2, 115351, 0, 0, 1, 0, 0, 44232), -- "Rylak Claws"
(81346, 1, 117452, 0, 0, 1, 0, 0, 44232), -- Gorgrond Mineral Water
(84246, 13, 111556, 0, 5498, 1, 0, 0, 44232), -- Hexweave Cloth
(84246, 12, 110611, 0, 5498, 1, 0, 0, 44232), -- Burnished Leather
(84246, 11, 115524, 0, 5498, 1, 0, 0, 44232), -- Taladite Crystal
(84246, 10, 112377, 0, 5498, 1, 0, 0, 44232), -- War Paints
(84246, 9, 111366, 0, 5498, 1, 0, 0, 44232), -- Gearspring Parts
(84246, 8, 108257, 0, 5498, 1, 0, 0, 44232), -- Truesteel Ingot
(84246, 7, 108996, 0, 5498, 1, 0, 0, 44232), -- Alchemical Catalyst
(84246, 6, 127759, 0, 5502, 1, 0, 0, 44232), -- Felblight
(84246, 5, 118472, 0, 5502, 1, 0, 0, 44232), -- Savage Blood
(84246, 4, 113262, 0, 5500, 1, 0, 0, 44232), -- Sorcerous Water
(84246, 3, 113261, 0, 5500, 1, 0, 0, 44232), -- Sorcerous Fire
(84246, 2, 113263, 0, 5500, 1, 0, 0, 44232), -- Sorcerous Earth
(84246, 1, 113264, 0, 5500, 1, 0, 0, 44232), -- Sorcerous Air
(80159, 15, 115354, 0, 0, 1, 0, 0, 44232), -- Sliced Zangar Buttons
(80159, 14, 117474, 0, 0, 1, 0, 0, 44232), -- Rylak Sausages
(80159, 13, 117473, 0, 0, 1, 0, 0, 44232), -- Pickled Elekk Hooves
(80159, 12, 117472, 0, 0, 1, 0, 0, 44232), -- Grilled Gorgrond Surprise
(80159, 11, 117452, 0, 0, 1, 0, 0, 44232), -- Gorgrond Mineral Water
(80159, 9, 2678, 0, 0, 1, 0, 0, 44232), -- Mild Spices
(80159, 8, 30817, 0, 0, 1, 0, 0, 44232), -- Simple Flour
(80159, 7, 159, 0, 0, 1, 0, 0, 44232), -- Refreshing Spring Water
(80159, 6, 122560, 0, 0, 1, 0, 0, 44232), -- Recipe: Whiptail Fillet
(80159, 5, 122555, 0, 0, 1, 0, 0, 44232), -- Recipe: Sleeper Sushi
(80159, 4, 122559, 0, 0, 1, 0, 0, 44232), -- Recipe: Salty Squid Roll
(80159, 3, 122558, 0, 0, 1, 0, 0, 44232), -- Recipe: Pickled Eel
(80159, 2, 122557, 0, 0, 1, 0, 0, 44232), -- Recipe: Jumbo Sea Dog
(80159, 1, 122556, 0, 0, 1, 0, 0, 44232), -- Recipe: Buttered Sturgeon
(78564, 27, 141642, 0, 5827, 1, 0, 0, 44232), -- Technique: Tome of the Clear Mind
(78564, 26, 120349, 0, 5488, 1, 0, 0, 44232), -- Enduring Vial of Swiftness
(78564, 25, 120348, 0, 5488, 1, 0, 0, 44232), -- Enchanted Crystal of Freezing
(78564, 24, 120347, 0, 5488, 1, 0, 0, 44232), -- Enchanted Crystal of Replenishment
(78564, 23, 122406, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Iron Siegeworks
(78564, 22, 122399, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Magnarok
(78564, 21, 122401, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Stonefury Cliffs
(78564, 20, 122404, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Everbloom Wilds
(78564, 19, 122407, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Skettis
(78564, 18, 122409, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Pillars of Fate
(78564, 17, 122410, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Shattrath Harbor
(78564, 16, 122414, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Lost Veil Anzu
(78564, 15, 122415, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Socrethar's Rise
(78564, 14, 122417, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Darktide Roost
(78564, 13, 122422, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Mok'gol Watchpost
(78564, 12, 122423, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: Broken Precipice
(78564, 11, 133883, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: The Heart of Shattrath
(78564, 10, 133878, 0, 5809, 1, 0, 0, 44232), -- Scouting Missive: The Pit
(78564, 9, 122500, 0, 5805, 1, 0, 0, 44232), -- Rush Order: Gnomish Gearworks
(78564, 8, 122490, 0, 5805, 1, 0, 0, 44232), -- Rush Order: Dwarven Bunker
(78564, 7, 122487, 0, 5805, 1, 0, 0, 44232), -- Rush Order: Gladiator's Sanctum
(78564, 6, 122307, 0, 5805, 1, 0, 0, 44232), -- Rush Order: Barn
(78564, 5, 122503, 0, 5806, 1, 0, 0, 44232), -- Rush Order: Mine Shipment
(78564, 4, 122497, 0, 5806, 1, 0, 0, 44232), -- Rush Order: Garden Shipment
(78564, 3, 128373, 0, 5543, 1, 0, 0, 44232), -- Rush Order: Shipyard
(78564, 2, 122272, 0, 5807, 1, 0, 0, 44232), -- Follower Ability Retraining Manual
(78564, 1, 122273, 0, 5808, 1, 0, 0, 44232); -- Follower Trait Retraining Guide

-- Phasing
DELETE FROM `phase_area` WHERE (`AreaId` = 7085 AND `PhaseId` = 2559);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7085, 2559, 'Cosmetic - [PH] SMV - Alliance Garrison V1');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 2559 AND `SourceEntry` = 7085);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 2559, 7085, 0, 0, 47, 0, 34586, 66, 0, 0, 'Apply Phase 2559 If Quest 34586 IS complete/rewarded');
