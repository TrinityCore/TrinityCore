SET @CGUID := 1051213;

SET @SPAWNGROUP_ALLIANCE := 128;
SET @SPAWNGROUP_HORDE    := 129;

-- Spawn group template
DELETE FROM `spawn_group_template` WHERE `groupId` IN ((@SPAWNGROUP_ALLIANCE), (@SPAWNGROUP_HORDE));
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP_ALLIANCE, 'NPE - Alliance spawn Group', 0x20),
(@SPAWNGROUP_HORDE, 'NPE - Horde spawn Group', 0x20);

-- Spawn Group
DELETE FROM `spawn_group` WHERE `spawnId` IN ((@CGUID+15), (@CGUID+16)) AND `spawnType`=0;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(@SPAWNGROUP_ALLIANCE, 0, @CGUID+15),
(@SPAWNGROUP_HORDE, 0, @CGUID+16);

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 33 AND `SourceEntry` = (@SPAWNGROUP_ALLIANCE)) OR (`SourceTypeOrReferenceId` = 33 AND `SourceEntry` = (@SPAWNGROUP_HORDE));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(33, 0, (@SPAWNGROUP_ALLIANCE), 0, 0, 11, 0, 4485, 1, 0, 0, 'NPE - Spawn Alliance NPCs if you are Alliance Player'),
(33, 0, (@SPAWNGROUP_HORDE), 0, 0, 11, 0, 4486, 1, 0, 0, 'NPE - Spawn Horde NPCs if you are Horde Player');

-- Creature Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+52;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, 31.68229103088378906, -2492.6025390625, 110.087005615234375, 4.472929000854492187, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 165712, 2175, 10424, 10503, '0', 0, 0, 0, 0, -45.7331619262695312, -2609.944091796875, 53.86749649047851562, 4.774930000305175781, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Cockroach (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 165713, 2175, 10424, 10503, '0', 0, 0, 0, 0, -22.2366809844970703, -2666.016357421875, 61.80840682983398437, 4.972991466522216796, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Scurrying Rat (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, -43.0729179382324218, -2663.921875, 57.29541778564453125, 5.384460926055908203, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, -50.0034713745117187, -2600.10595703125, 55.68202590942382812, 2.87820601463317871, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 164826, 2175, 10424, 10503, '0', 0, 0, 0, 0, -114.581405639648437, -2665.084716796875, 59.16316604614257812, 4.393485069274902343, 7200, 4, 0, 155, 0, 1, 0, 0, 0, 44908), -- Wandering Boar (Area: -Unknown- - Difficulty: 0)
(@CGUID+6, 150238, 2175, 10424, 10503, '0', 0, 0, 0, 0, -36.0592384338378906, -2593.302978515625, 55.58246612548828125, 3.488671779632568359, 7200, 0, 0, 45, 230, 0, 0, 0, 0, 44908), -- Quilboar Geomancer (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 150238, 2175, 10424, 10503, '0', 0, 0, 0, 0, -31.0421829223632812, -2625.13134765625, 53.5910186767578125, 6.226619243621826171, 7200, 0, 0, 45, 230, 0, 0, 0, 0, 44908), -- Quilboar Geomancer (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, -91.5670089721679687, -2673.90185546875, 75.72377777099609375, 5.384068965911865234, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, -15.3125, -2649.703125, 57.02451324462890625, 6.269787311553955078, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0)
(@CGUID+10, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, -80.564239501953125, -2640.189208984375, 57.44630050659179687, 3.18963932991027832, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 164826, 2175, 10424, 10503, '0', 0, 0, 0, 0, -102.059829711914062, -2690.2841796875, 66.0632781982421875, 5.222332477569580078, 7200, 4, 0, 155, 0, 1, 0, 0, 0, 44908), -- Wandering Boar (Area: -Unknown- - Difficulty: 0)
(@CGUID+12, 164826, 2175, 10424, 10503, '0', 0, 0, 0, 0, -121.795478820800781, -2697.271728515625, 64.1490478515625, 0.246875286102294921, 7200, 4, 0, 155, 0, 1, 0, 0, 0, 44908), -- Wandering Boar (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 165712, 2175, 10424, 10503, '0', 0, 0, 0, 0, -44.8458633422851562, -2595.16796875, 56.15691757202148437, 1.520033955574035644, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Cockroach (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+14, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, -108.631942749023437, -2632.421875, 58.3117523193359375, 3.756600141525268554, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+15, 154301, 2175, 10424, 10503, '0', 0, 0, 0, 0, 16.42708396911621093, -2511.819580078125, 78.82154083251953125, 5.663975715637207031, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908), -- Lindie Springstock (Area: -Unknown- - Difficulty: 0) (Auras: 305513 - -Unknown-)
(@CGUID+16, 167008, 2175, 10424, 10503, '0', 0, 0, 0, 0, 16.42708396911621093, -2511.819580078125, 78.80028533935546875, 5.663975715637207031, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908), -- Cork Fizzlepop (Area: -Unknown- - Difficulty: 0) (Auras: 305513 - -Unknown-)
(@CGUID+17, 164826, 2175, 10424, 10503, '0', 0, 0, 0, 0, -150.25726318359375, -2691.28759765625, 62.00418853759765625, 2.933544158935546875, 7200, 4, 0, 155, 0, 1, 0, 0, 0, 44908), -- Wandering Boar (Area: -Unknown- - Difficulty: 0)
(@CGUID+18, 150238, 2175, 10424, 10503, '0', 0, 0, 0, 0, 0.965277791023254394, -2618.072998046875, 56.09575271606445312, 5.635455608367919921, 7200, 0, 0, 45, 230, 0, 0, 0, 0, 44908), -- Quilboar Geomancer (Area: -Unknown- - Difficulty: 0) (Auras: 313261 - -Unknown-)
(@CGUID+19, 165713, 2175, 10424, 10503, '0', 0, 0, 0, 0, -5.13363504409790039, -2604.883544921875, 54.52672576904296875, 2.537898778915405273, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Scurrying Rat (Area: -Unknown- - Difficulty: 0)
(@CGUID+20, 165712, 2175, 10424, 10503, '0', 0, 0, 0, 0, -40.9509773254394531, -2593.725341796875, 55.95753097534179687, 4.121400356292724609, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Cockroach (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+21, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, -29.5868053436279296, -2620.147705078125, 72.95214080810546875, 4.446326255798339843, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+22, 165713, 2175, 10424, 10503, '0', 0, 0, 0, 0, -21.7733116149902343, -2600.57421875, 54.12693023681640625, 2.274249076843261718, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Scurrying Rat (Area: -Unknown- - Difficulty: 0) (Auras: 52391 - Ride Vehicle)
(@CGUID+23, 150238, 2175, 10424, 10503, '0', 0, 0, 0, 0, -8.36284732818603515, -2585.098876953125, 58.76477813720703125, 0.471627712249755859, 7200, 0, 0, 45, 230, 0, 0, 0, 0, 44908), -- Quilboar Geomancer (Area: -Unknown- - Difficulty: 0)
(@CGUID+24, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, 11.15972232818603515, -2604.921875, 82.69051361083984375, 3.012201309204101562, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+25, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, 8.1875, -2600.3369140625, 81.93195343017578125, 4.328756332397460937, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+26, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, 27.5625, -2606.806640625, 64.0489349365234375, 4.653748035430908203, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0)
(@CGUID+27, 165713, 2175, 10424, 10503, '0', 0, 0, 0, 0, 38.71170425415039062, -2604.18603515625, 64.95450592041015625, 3.549305915832519531, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Scurrying Rat (Area: -Unknown- - Difficulty: 0)
(@CGUID+28, 150238, 2175, 10424, 10503, '0', 0, 0, 0, 0, 42.7274322509765625, -2607.38720703125, 65.3719482421875, 0.633620858192443847, 7200, 0, 0, 45, 230, 0, 0, 0, 0, 44908), -- Quilboar Geomancer (Area: -Unknown- - Difficulty: 0) (Auras: 313265 - -Unknown-)
(@CGUID+29, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, 31.296875, -2563.626708984375, 66.454986572265625, 3.228455305099487304, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0)
(@CGUID+30, 165713, 2175, 10424, 10503, '0', 0, 0, 0, 0, 54.47609710693359375, -2577.6455078125, 65.47464752197265625, 4.393154144287109375, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Scurrying Rat (Area: -Unknown- - Difficulty: 0)
(@CGUID+31, 150238, 2175, 10424, 10503, '0', 0, 0, 0, 0, 60.03298568725585937, -2592.104248046875, 65.52142333984375, 4.600577354431152343, 7200, 0, 0, 45, 230, 0, 0, 0, 0, 44908), -- Quilboar Geomancer (Area: -Unknown- - Difficulty: 0) (Auras: 313261 - -Unknown-)
(@CGUID+32, 165712, 2175, 10424, 10503, '0', 0, 0, 0, 0, 2.134475231170654296, -2531.2373046875, 75.92337799072265625, 4.01464080810546875, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Cockroach (Area: -Unknown- - Difficulty: 0)
(@CGUID+33, 165712, 2175, 10424, 10503, '0', 0, 0, 0, 0, 3.290203094482421875, -2527.0517578125, 76.15164947509765625, 0.856812894344329833, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Cockroach (Area: -Unknown- - Difficulty: 0)
(@CGUID+34, 165712, 2175, 10424, 10503, '0', 0, 0, 0, 0, 0, -2525, 72.44144439697265625, 1.570796370506286621, 7200, 4, 0, 3, 0, 1, 0, 0, 0, 44908), -- Cockroach (Area: -Unknown- - Difficulty: 0)
(@CGUID+35, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, 49.984375, -2546.2744140625, 66.516845703125, 6.005198001861572265, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0) (Auras: 313265 - -Unknown-)
(@CGUID+36, 150238, 2175, 10424, 10503, '0', 0, 0, 0, 0, 57.88020706176757812, -2550.33154296875, 66.3349609375, 3.311758041381835937, 7200, 0, 0, 45, 230, 0, 0, 0, 0, 44908), -- Quilboar Geomancer (Area: -Unknown- - Difficulty: 0) (Auras: 313265 - -Unknown-)
(@CGUID+37, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, 31.171875, -2527.435791015625, 105.4509353637695312, 0.533610105514526367, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+38, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, 54.75347137451171875, -2542.62841796875, 66.5119781494140625, 4.053359031677246093, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0) (Auras: 313265 - -Unknown-)
(@CGUID+39, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, 70.38912200927734375, -2561.96240234375, 83.041778564453125, 2.896515369415283203, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+40, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, 84.5830841064453125, -2609.436279296875, 65.0294342041015625, 3.123527050018310546, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0)
(@CGUID+41, 150238, 2175, 10424, 10503, '0', 0, 0, 0, 0, 86.6944427490234375, -2620.166748046875, 65.3642425537109375, 1.28442239761352539, 7200, 0, 0, 45, 230, 0, 0, 0, 0, 44908), -- Quilboar Geomancer (Area: -Unknown- - Difficulty: 0) (Auras: 313265 - -Unknown-)
(@CGUID+42, 156676, 2175, 10424, 10503, '0', 0, 0, 0, 1, 81.0381927490234375, -2561.204833984375, 66.47966766357421875, 5.661624431610107421, 7200, 0, 0, 135, 230, 0, 0, 0, 0, 44908), -- Ogre Overseer (Area: -Unknown- - Difficulty: 0)
(@CGUID+43, 155371, 2175, 10424, 10503, '0', 0, 0, 0, 0, 9.383680343627929687, -2514.885498046875, 75.9253387451171875, 0, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908), -- InvisBunny (Area: -Unknown- - Difficulty: 0)
(@CGUID+44, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, 93.1875, -2609.76904296875, 65.3175048828125, 4.434503078460693359, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0) (Auras: 313265 - -Unknown-)
(@CGUID+45, 151091, 2175, 10424, 10503, '0', 0, 0, 0, 0, 12.55729198455810546, -2508.960205078125, 73.3811187744140625, 5.565240383148193359, 7200, 0, 0, 135, 230, 0, 0, 0, 0, 44908), -- Geolord Grek'og (Area: -Unknown- - Difficulty: 0)
(@CGUID+46, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, -4.09895849227905273, -2510.088623046875, 109.02618408203125, 0.533610105514526367, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+47, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, 98.72396087646484375, -2613.576416015625, 65.1120452880859375, 3.2439117431640625, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0) (Auras: 313265 - -Unknown-)
(@CGUID+48, 150237, 2175, 10424, 10503, '0', 0, 0, 0, 1, 99.30728912353515625, -2575.098876953125, 65.108642578125, 4.068733692169189453, 7200, 0, 0, 57, 0, 0, 0, 0, 0, 44908), -- Quilboar Warrior (Area: -Unknown- - Difficulty: 0)
(@CGUID+49, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, 104.572906494140625, -2565.1962890625, 90.8019561767578125, 4.456551074981689453, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+50, 150238, 2175, 10424, 10503, '0', 0, 0, 0, 0, 102.010406494140625, -2576.5625, 64.214111328125, 3.314525604248046875, 7200, 0, 0, 45, 230, 0, 0, 0, 0, 44908), -- Quilboar Geomancer (Area: -Unknown- - Difficulty: 0)
(@CGUID+51, 164827, 2175, 10424, 10503, '0', 0, 0, 0, 0, 108.0711822509765625, -2564.62158203125, 90.8239593505859375, 4.456551074981689453, 7200, 0, 0, 155, 0, 0, 0, 0, 0, 44908), -- Sharpbeak Hawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+52, 155371, 2175, 10424, 10503, '0', 0, 0, 0, 0, 18.27430534362792968, -2503.74658203125, 76.96187591552734375, 0, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908); -- InvisBunny (Area: -Unknown- - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+52;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sharpbeak Hawk
(@CGUID+14, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sharpbeak Hawk
(@CGUID+25, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sharpbeak Hawk
(@CGUID+24, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sharpbeak Hawk
(@CGUID+49, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sharpbeak Hawk
(@CGUID+51, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sharpbeak Hawk
(@CGUID+37, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sharpbeak Hawk
(@CGUID+46, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sharpbeak Hawk
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313265'), -- Quilboar Warrior - 313265 - -Unknown-
(@CGUID+38, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313265'), -- Quilboar Warrior - 313265 - -Unknown-
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313265'), -- Quilboar Geomancer - 313265 - -Unknown-
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313265'), -- Quilboar Geomancer - 313265 - -Unknown-
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313265'), -- Quilboar Warrior - 313265 - -Unknown-
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313265'), -- Quilboar Warrior - 313265 - -Unknown-
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313265'), -- Quilboar Geomancer - 313265 - -Unknown-
(@CGUID+9, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Quilboar Warrior - 313265 - -Unknown-
(@CGUID+3, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Quilboar Warrior - 313265 - -Unknown-
(@CGUID+4, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Quilboar Warrior - 313265 - -Unknown-
(@CGUID+23, 0, 0, 0, 1, 569, 0, 0, 0, 0, ''), -- Quilboar Geomancer - 313265 - -Unknown-
(@CGUID+29, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Quilboar Warrior - 313265 - -Unknown-
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313261'), -- Quilboar Geomancer - 313261 - -Unknown-
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313261'); -- Quilboar Geomancer - 313261 - -Unknown-

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (154301, 167008, 151091);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(154301, 0, 0, 0, 1, 0, 0, 0, 0, 4, '305513'), -- 154301 (Lindie Springstock) - -Unknown-
(167008, 0, 0, 0, 1, 0, 0, 0, 0, 0, '305513'), -- 167008 (Cork Fizzlepop) - -Unknown-
(151091, 0, 0, 0, 1, 474, 0, 0, 0, 0, ''); -- 151091 (Geolord Grek´gor) -

-- Creature Template
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=4196352 WHERE `entry`=154301; -- Lindie Springstock
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=167008; -- Cork Fizzlepop
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=155371; -- InvisBunny
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=165713; -- Scurrying Rat

-- Creature Template Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (164827, 154301, 167008);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(164827, 0, 0, 1, 0, 0, 0, NULL),
(154301, 0, 0, 1, 0, 0, 0, NULL),
(167008, 0, 0, 1, 0, 0, 0, NULL);

-- Waypoint for CGUID+6
SET @PATH := @CGUID+6 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -45.43403, -2588.728, 56.76222, NULL, 4317),
(@PATH, 1, -38.47049, -2594.175, 55.57692, NULL, 0),
(@PATH, 2, -29.45486, -2590.899, 54.93901, NULL, 0),
(@PATH, 3, -20.32639, -2587.195, 56.92412, NULL, 4145),
(@PATH, 4, -29.45486, -2590.899, 54.93901, NULL, 0),
(@PATH, 5, -38.47049, -2594.175, 55.57692, NULL, 0);

UPDATE `creature` SET `position_x`= -45.43403, `position_y`= -2588.728, `position_z`= 56.76222, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+6;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+6;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+6, @PATH, 1);

-- Waypoint for CGUID+7
SET @PATH := @CGUID+7 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -27.03472, -2618.342, 53.69529, NULL, 0),
(@PATH, 1, -26.55208, -2614.351, 54.33224, NULL, 6656),
(@PATH, 2, -32.65451, -2615.469, 53.58323, NULL, 0),
(@PATH, 3, -39.08854, -2617.306, 53.75193, NULL, 4330),
(@PATH, 4, -40.17014, -2624.231, 53.62693, NULL, 0),
(@PATH, 5, -39.06445, -2627.002, 54.16187, NULL, 6643),
(@PATH, 6, -35.87088, -2622.012, 53.56187, NULL, 4824),
(@PATH, 7, -32.2882, -2625.061, 53.62693, NULL, 0),
(@PATH, 8, -28.91667, -2625.252, 53.52976, NULL, 0),
(@PATH, 9, -27.28646, -2625, 53.85252, NULL, 6745);

UPDATE `creature` SET `position_x`= -27.03472, `position_y`= -2618.342, `position_z`= 53.69529, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+7;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+7, @PATH, 1);

-- Waypoint for CGUID+26
SET @PATH := @CGUID+26 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 28.09028, -2597.825, 63.72087, NULL, 0),
(@PATH, 1, 24.83681, -2589.148, 64.13701, NULL, 4785),
(@PATH, 2, 28.09028, -2597.825, 63.72087, NULL, 0),
(@PATH, 3, 27.5625, -2606.807, 64.04893, NULL, 4846);

UPDATE `creature` SET `position_x`= 28.09028, `position_y`= -2597.825, `position_z`= 63.72087, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+26;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+26;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+26, @PATH, 1);

-- Waypoint for CGUID+40
SET @PATH := @CGUID+40 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 70.40104, -2608.917, 64.79998, NULL, 0),
(@PATH, 1, 61.08854, -2602.07, 65.20451, NULL, 0),
(@PATH, 2, 59.65278, -2597.101, 65.36491, NULL, 4638),
(@PATH, 3, 61.08854, -2602.07, 65.20451, NULL, 0),
(@PATH, 4, 70.40104, -2608.917, 64.79998, NULL, 0),
(@PATH, 5, 79.27604, -2609.34, 64.92498, NULL, 0),
(@PATH, 6, 90.62674, -2609.552, 65.29998, NULL, 4518),
(@PATH, 7, 79.27604, -2609.34, 64.92498, NULL, 0);

UPDATE `creature` SET `position_x`= 70.40104, `position_y`= -2608.917, `position_z`= 64.79998, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+40;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+40;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+40, @PATH, 1);

-- Waypoint for CGUID+42
SET @PATH := @CGUID+42 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 89.90625, -2567.559, 65.98618, NULL, 2916),
(@PATH, 1, 81.03819, -2561.205, 66.47967, NULL, 399);

UPDATE `creature` SET `position_x`= 89.90625, `position_y`= -2567.559, `position_z`= 65.98618, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+42;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+42;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+42, @PATH, 1);

-- SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (150238, 150237);
DELETE FROM `smart_scripts` WHERE (`source_type`=0 AND `entryOrGuid`=-(@CGUID+7)) OR (`source_type`=9 AND `entryOrGuid`=15023800);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+7), 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 15023800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 1 - run ActionList - to self'),
(-(@CGUID+7), 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 15023800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 3 - run ActionList - to self'),
(-(@CGUID+7), 0, 2, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 15023800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 5 - run ActionList - to self'),
(-(@CGUID+7), 0, 3, 0, 34, 0, 100, 0, 2, 6, 0, 0, 80, 15023800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 6 - run ActionList - to self'),
(-(@CGUID+7), 0, 4, 0, 34, 0, 100, 0, 2, 9, 0, 0, 80, 15023800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 9 - run ActionList - to self'),
(15023800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 569, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - set EmoteState to 569 - to self'),
(15023800, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2s - set EmoteState to 0 - to self'),
(15023800, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, 313260, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2s - cast "Necrotic Burst" - to self');
