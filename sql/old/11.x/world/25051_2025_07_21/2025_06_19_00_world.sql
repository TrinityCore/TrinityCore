SET @CGUID := 6003599;
SET @OGUID := 6002449;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+621;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3878.7900390625, 4519.5615234375, 82.5928497314453125, 3.418033599853515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+1, 95861, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3849.0869140625, 4430.9775390625, 69.19271087646484375, 6.221851825714111328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Oracle (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+2, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3882.7744140625, 4532.587890625, 81.298248291015625, 2.214102029800415039, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+3, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3833.80029296875, 4528.04150390625, 61.52602005004882812, 1.611756801605224609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+4, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3835.30078125, 4486.720703125, 60.6080169677734375, 2.608037233352661132, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+5, 100216, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3848.380126953125, 4424.6943359375, 69.923614501953125, 0.099522329866886138, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wrangler (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+6, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3833.796875, 4549.3349609375, 61.1943206787109375, 4.630161762237548828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+7, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3846.710205078125, 4443.56494140625, 64.937957763671875, 5.898068904876708984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+8, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3888.382080078125, 4503.23486328125, 85.23966217041015625, 5.701409339904785156, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+9, 100216, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3814.583251953125, 4506.30029296875, 56.93160247802734375, 2.828289747238159179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wrangler (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+10, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3899.20556640625, 4516.791015625, 85.441619873046875, 2.313639163970947265, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+11, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3846.185791015625, 4436.04345703125, 67.00783538818359375, 6.080896854400634765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+12, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3851.62158203125, 4493.7255859375, 68.052825927734375, 5.776490688323974609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+13, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3884.86279296875, 4509.0478515625, 81.7899322509765625, 2.507887125015258789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+14, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3845.98779296875, 4495.85595703125, 65.2881927490234375, 4.809277057647705078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+15, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3843.6923828125, 4517.38232421875, 64.0774078369140625, 3.403137922286987304, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+16, 100216, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3873.185791015625, 4495.28125, 78.28261566162109375, 2.413151979446411132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wrangler (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+17, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3806.4931640625, 4518.99169921875, 55.65805435180664062, 4.794336318969726562, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+18, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3822.870849609375, 4466.72998046875, 57.67865753173828125, 4.347475051879882812, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+19, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3872.3505859375, 4523.78076171875, 81.09311676025390625, 0.361284941434860229, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+20, 111639, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3888.788330078125, 4502.0146484375, 85.759735107421875, 0.959654629230499267, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Aluneth (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+21, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3808.209228515625, 4499.93017578125, 55.49030303955078125, 4.531626701354980468, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+22, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3919.910400390625, 4517.291015625, 90.26438140869140625, 5.021638393402099609, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+23, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3827.6962890625, 4412.619140625, 66.4618072509765625, 5.153449535369873046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+24, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3784.903076171875, 4481.86279296875, 50.04810714721679687, 5.401906967163085937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+25, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3799.900390625, 4488.01123046875, 52.64513778686523437, 3.434954404830932617, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+26, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3840.3837890625, 4384.9990234375, 73.265625, 1.897439360618591308, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+27, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3756.954833984375, 4431.99658203125, 42.39996719360351562, 3.143988847732543945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+28, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3769.8935546875, 4454.81298828125, 44.549957275390625, 1.870300889015197753, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+29, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3733.57666015625, 4497.9111328125, 43.70977020263671875, 5.311148643493652343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+30, 100216, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3800.63232421875, 4463.45751953125, 54.46221923828125, 0.860467851161956787, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wrangler (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+31, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3781.952880859375, 4418.22216796875, 44.64946746826171875, 6.095557689666748046, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+32, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3794.165283203125, 4464.69970703125, 52.22652435302734375, 3.121928930282592773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+33, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3763.558837890625, 4463.72900390625, 44.63003921508789062, 5.866112709045410156, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+34, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3755.57763671875, 4563.98388671875, 42.10085296630859375, 4.283255577087402343, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+35, 95861, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3781.458740234375, 4477.2998046875, 48.79967117309570312, 1.939900875091552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Oracle (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+36, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3742.391845703125, 4523.529296875, 41.91967010498046875, 5.176469326019287109, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+37, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3780.989501953125, 4531.9443359375, 51.76877593994140625, 2.235050439834594726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+38, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3783.97216796875, 4544.1728515625, 52.990386962890625, 4.556290626525878906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+39, 95861, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3804.625, 4467.744140625, 55.33065032958984375, 5.817455768585205078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Oracle (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+40, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3791.901123046875, 4400.00634765625, 46.5398712158203125, 1.664425134658813476, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+41, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3843.460205078125, 4390.251953125, 72.80382537841796875, 5.426136493682861328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+42, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3807.15869140625, 4470.71240234375, 56.41782379150390625, 4.777108192443847656, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+43, 100216, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3787.9931640625, 4505.81591796875, 52.0936279296875, 3.294533014297485351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wrangler (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+44, 91782, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3749.29150390625, 4515.03369140625, 42.83304595947265625, 4.808778762817382812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Crusher (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+45, 95861, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3736.434326171875, 4491.4541015625, 43.5284423828125, 0.148413702845573425, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Oracle (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+46, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3798.970458984375, 4470.78662109375, 53.7200469970703125, 4.594561576843261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+47, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3826.151123046875, 4406.7265625, 66.1553955078125, 1.624754071235656738, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+48, 91782, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3788.859619140625, 4325.57470703125, 33.109375, 0.618104755878448486, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Crusher (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+49, 95861, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3759.331787109375, 4419.4091796875, 43.75778961181640625, 2.650062084197998046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Oracle (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+50, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3790.822998046875, 4374.35400390625, 45.50296783447265625, 5.491576194763183593, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+51, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3692.175048828125, 4620.51171875, 27.58209609985351562, 0.438792824745178222, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+52, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3751.9248046875, 4434.82763671875, 39.66992950439453125, 1.521959304809570312, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+53, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3721.23291015625, 4438.388671875, 34.12245941162109375, 3.141300678253173828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+54, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3778.29931640625, 4402.40673828125, 44.21673965454101562, 1.716001749038696289, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+55, 95861, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3726.943115234375, 4435.109375, 34.916473388671875, 1.024570226669311523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Oracle (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+56, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3728.989013671875, 4514.615234375, 43.31279373168945312, 4.150453567504882812, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+57, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3757.29638671875, 4377.14404296875, 43.65871429443359375, 5.216328620910644531, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+58, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3704.1748046875, 4557.6767578125, -1.41169774532318115, 1.00315713882446289, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+59, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3756.430908203125, 4424.474609375, 42.46479034423828125, 2.78543853759765625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+60, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3784.501953125, 4341.5537109375, 36.26909637451171875, 4.528143882751464843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+61, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3810.322998046875, 4367.9453125, 45.5225677490234375, 4.884997844696044921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+62, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3748.17529296875, 4384.48193359375, 46.40155792236328125, 5.513045310974121093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+63, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3736.009765625, 4476.9560546875, 43.12687301635742187, 2.297438621520996093, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+64, 100216, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3758.625244140625, 4413.1259765625, 44.1168365478515625, 2.61729288101196289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wrangler (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+65, 91787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3779.681640625, 4343.47021484375, 70.738800048828125, 0.104161843657493591, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+66, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3744.651123046875, 4379.509765625, 46.47742843627929687, 1.98435068130493164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+67, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3728.144287109375, 4440.5234375, 35.77597427368164062, 5.69454050064086914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+68, 100216, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3782.220703125, 4328.3037109375, 32.57986068725585937, 2.044229745864868164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wrangler (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+69, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3763.323974609375, 4409.919921875, 44.64513397216796875, 4.012024402618408203, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+70, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3779.762451171875, 4334.50341796875, 33.99703216552734375, 3.016713857650756835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+71, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3810.390625, 4361.85693359375, 44.66529083251953125, 1.356301546096801757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+72, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3757.20849609375, 4354.66064453125, 38.7586212158203125, 2.789301395416259765, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+73, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3557.52001953125, 4642.18115234375, 3.640993833541870117, 3.028466224670410156, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+74, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3799.243896484375, 4255.37158203125, 20.58610153198242187, 4.152323246002197265, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+75, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3744.734375, 4346.8349609375, 39.07638931274414062, 2.042952299118041992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+76, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3773.689208984375, 4204.9072265625, 22.96354293823242187, 1.421278953552246093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+77, 91786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3810.4716796875, 4258.47216796875, 19.90001678466796875, 4.767595767974853515, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+78, 91786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3591.98046875, 4604.5830078125, 11.01216602325439453, 0.740507841110229492, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+79, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3553.992919921875, 4635.00390625, 1.414200305938720703, 5.564171791076660156, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+80, 91786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3672.76171875, 4602.77099609375, 23.92668914794921875, 5.947525501251220703, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+81, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3646.4326171875, 4601.96533203125, 17.897705078125, 0, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+82, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3650.556640625, 4652.5625, 16.98646163940429687, 3.565959453582763671, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+83, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3804.70166015625, 4298.1923828125, 25.61674690246582031, 2.328229665756225585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+84, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3654.10888671875, 4632.81640625, 15.94731330871582031, 3.81282663345336914, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+85, 98173, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3511.6962890625, 4479.8349609375, 1.610608100891113281, 5.007443904876708984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Mystic Ssa'veh (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193491 - Tempest Attunement)
(@CGUID+86, 100216, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3754.026123046875, 4339.9599609375, 36.16840362548828125, 1.874806761741638183, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wrangler (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+87, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3808.349365234375, 4315.19970703125, 33.01387405395507812, 4.737774372100830078, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+88, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3644.172119140625, 4636.07275390625, 12.29444026947021484, 5.631941795349121093, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+89, 97171, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3555.4462890625, 4740.42724609375, 4.846404552459716796, 5.243534564971923828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Arcanist (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 199865 - Arcane Fortification, 197115 - Arcane Alignment, 161837 - Arcane Channeling)
(@CGUID+90, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3547.746826171875, 4624.14453125, -0.718392014503479, 4.935414314270019531, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+91, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3769.8857421875, 4323.23291015625, 30.392791748046875, 4.14768218994140625, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+92, 99901, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3562.450927734375, 4785.2431640625, 49.7552490234375, 0.290774941444396972, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+93, 97173, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3575.147705078125, 4640.947265625, 6.062633514404296875, 2.414390802383422851, 7200, 8, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Restless Tides (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+94, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3641.850341796875, 4636.828125, 11.71295928955078125, 6.027174949645996093, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+95, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3787.8583984375, 4295.017578125, 25.67551040649414062, 5.407877922058105468, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+96, 91782, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3768.166748046875, 4210.84912109375, 23.19097328186035156, 3.625387907028198242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Crusher (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+97, 91783, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3775.2744140625, 4215.7255859375, 22.55361557006835937, 5.497423648834228515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Stormweaver (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196786 - Lightning Hands)
(@CGUID+98, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3540.15966796875, 4626.2060546875, -0.45365571975708007, 0.719748675823211669, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+99, 99901, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3518.284423828125, 4586.36865234375, 41.547210693359375, 6.272902965545654296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+100, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3762.5, 4288.541015625, 21.61223411560058593, 1.099055290222167968, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+101, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3777.89404296875, 4209.5390625, 22.094024658203125, 0.488087117671966552, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+102, 95861, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3750.298583984375, 4345.0634765625, 37.72742843627929687, 1.907575964927673339, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Oracle (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+103, 91784, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3682.653076171875, 4417.0244140625, 32.44473648071289062, 5.828130722045898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Warlord Parjesh (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 202146 - Empty Energy [DNT], 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+104, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3663.638427734375, 4623.35546875, 19.18062591552734375, 3.814807415008544921, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+105, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3809.693115234375, 4301.6826171875, 26.56597328186035156, 5.856925010681152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+106, 91782, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3771.9189453125, 4330.64306640625, 32.3904266357421875, 4.690907955169677734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Crusher (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+107, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3640.20751953125, 4650.15478515625, 12.8022928237915039, 2.878597974777221679, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+108, 91785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3795.833984375, 4218.75, 20.76647377014160156, 3.141592741012573242, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Wandering Shellback (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+109, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3538.0830078125, 4639.84375, 1.641874074935913085, 4.200265884399414062, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+110, 99901, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3592.10009765625, 4707.458984375, 45.413421630859375, 1.724867224693298339, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+111, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3779.863037109375, 4285.63330078125, 22.5544586181640625, 0.586385548114776611, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+112, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3660.324951171875, 4631.41943359375, 18.66846466064453125, 3.947001934051513671, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+113, 97171, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3637.939697265625, 4633.42333984375, 10.77494239807128906, 0.497710466384887695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Arcanist (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 199865 - Arcane Fortification, 197115 - Arcane Alignment) (possible waypoints or random movement)
(@CGUID+114, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3720.978515625, 4334.91357421875, 53.88800430297851562, 6.159032821655273437, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+115, 91787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3549.708984375, 4643.25830078125, 36.38895416259765625, 5.105390548706054687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+116, 91781, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3740.038330078125, 4352.72998046875, 41.42013931274414062, 2.401502847671508789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Warrior (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+117, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3697.984375, 4408.82861328125, 32.54071807861328125, 1.093826174736022949, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+118, 97713, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3486.739990234375, 4386.1884765625, -3.58772110939025878, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Lightning Stalker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 192732 - Lightning Strikes, 192737 - Lightning Strikes, 192736 - Lightning Strikes)
(@CGUID+119, 97171, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3457.630126953125, 4760.1962890625, 4.3648223876953125, 3.508651256561279296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Arcanist (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 161837 - Arcane Channeling)
(@CGUID+120, 91797, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3432.059326171875, 4199.8369140625, 29.26819229125976562, 3.78382277488708496, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- King Deepbeard (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+121, 97171, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3402.727783203125, 4685.5712890625, 4.352533340454101562, 5.784617424011230468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Arcanist (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 199865 - Arcane Fortification, 197115 - Arcane Alignment) (possible waypoints or random movement)
(@CGUID+122, 100250, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3415.2294921875, 4442.796875, 1.090063095092773437, 3.79659438133239746, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Binder Ashioi (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193491 - Tempest Attunement)
(@CGUID+123, 100248, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3474.942626953125, 4281.45654296875, 1.896027684211730957, 1.654032826423645019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Ritualist Lesha (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193491 - Tempest Attunement)
(@CGUID+124, 100249, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3382.7119140625, 4354.0693359375, 1.395864009857177734, 2.832154512405395507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Channeler Varisz (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193491 - Tempest Attunement)
(@CGUID+125, 91789, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3436.21044921875, 4573.15283203125, 14.75381088256835937, 5.208305835723876953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Lady Hatecoil (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 197868 - Arcane Shielding)
(@CGUID+126, 97063, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3486.26416015625, 4386.8701171875, -3.58041644096374511, 0.008037952706217765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Weatherman (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 191792 - Violent Winds)
(@CGUID+127, 99901, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3386.03173828125, 4422.33935546875, 70.70855712890625, 6.024390697479248046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+128, 99901, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -4118.4287109375, 4461.70849609375, 290.7003173828125, 0.346497267484664916, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+129, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3537.70556640625, 4645.41943359375, 2.518985271453857421, 2.409358024597167968, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+130, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3645.36376953125, 4653.06103515625, 15.19158077239990234, 3.729595422744750976, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+131, 91796, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3724.798583984375, 4186.07373046875, 28.48850059509277343, 2.333246469497680664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Wavecrasher (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+132, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3614.0126953125, 4504.4677734375, 0.8821258544921875, 2.069831371307373046, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+133, 91786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3526.98681640625, 4654.86767578125, 4.6852569580078125, 2.531666040420532226, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+134, 106786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3674.028076171875, 4180.638671875, 26.33859443664550781, 0.981641709804534912, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+135, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3605.00830078125, 4563.98388671875, -4.83761167526245117, 4.181853771209716796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+136, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3600.3408203125, 4580.03662109375, -6.9639596939086914, 4.246558189392089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+137, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3595.001953125, 4527.2705078125, 0.651824235916137695, 2.23852086067199707, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+138, 97173, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3508.35546875, 4641.60693359375, 2.849774122238159179, 4.396948814392089843, 7200, 8, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Restless Tides (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+139, 99901, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -4237.814453125, 4519.57373046875, 394.66265869140625, 0.005368033424019813, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+140, 106786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3669.955078125, 4176.705078125, 24.66907119750976562, 0.071115985512733459, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+141, 99901, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -4049.072998046875, 4524.8369140625, 314.4984130859375, 6.209977149963378906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+142, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3587.91650390625, 4587.79541015625, -6.2309579849243164, 3.384202957153320312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+143, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3471.262451171875, 4568.861328125, -0.35463121533393859, 4.72933053970336914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+144, 106787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3664.184326171875, 4166.4765625, 24.46100807189941406, 1.544655203819274902, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+145, 106785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3667.840576171875, 4170.75439453125, 23.8691558837890625, 5.922028541564941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+146, 97173, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3487.510498046875, 4637.91748046875, 2.457844018936157226, 2.298601627349853515, 7200, 8, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Restless Tides (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+147, 91786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3668.34716796875, 4164.22412109375, 24.00116920471191406, 4.938945293426513671, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+148, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3584.714111328125, 4585.5224609375, -6.63826942443847656, 2.165841102600097656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+149, 106787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3669.17041015625, 4172.9111328125, 24.15917205810546875, 0.023542344570159912, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+150, 97173, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3504.17041015625, 4687.2607421875, 4.925557136535644531, 0, 7200, 8, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Restless Tides (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+151, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3478.828369140625, 4596.3642578125, -0.35463121533393859, 4.72933053970336914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+152, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3569.14111328125, 4487.82177734375, 1.808709383010864257, 5.56968545913696289, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+153, 91787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3489.443115234375, 4638.533203125, 26.49169921875, 4.0016632080078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+154, 95920, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3538.559326171875, 4744.3251953125, 2.555608987808227539, 2.580512523651123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Animated Storm (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+155, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3465.96044921875, 4582.650390625, -0.35463121533393859, 2.598540544509887695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+156, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3566.133544921875, 4449.27734375, 1.784824371337890625, 4.519782066345214843, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+157, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3462.63916015625, 4552.48876953125, -0.354621022939682, 6.21154642105102539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+158, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3463.750244140625, 4596.3779296875, -0.35463121533393859, 3.916661977767944335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+159, 97170, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3568.380126953125, 4789.1962890625, 5.626736164093017578, 5.076960563659667968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wavebinder (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+160, 106785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3660.95166015625, 4167.44873046875, 24.7101593017578125, 2.059580564498901367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+161, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3730.707763671875, 4241.8759765625, 8.7012481689453125, 0.245022058486938476, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+162, 97170, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3537.3857421875, 4748.6044921875, 2.457346916198730468, 2.938291072845458984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wavebinder (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+163, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3452.925537109375, 4569.1240234375, -0.354621022939682, 1.652570247650146484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+164, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3450.298828125, 4579.591796875, -0.35463121533393859, 0.630552411079406738, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+165, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3599.75146484375, 4353.63916015625, -3.01657819747924804, 2.345145225524902343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+166, 97170, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3479.041748046875, 4662.353515625, 3.767857313156127929, 2.525701522827148437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wavebinder (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+167, 95920, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3480.21533203125, 4658.07470703125, 2.118855953216552734, 2.169840812683105468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Animated Storm (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+168, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3598.943359375, 4339.70654296875, -3.4785308837890625, 2.405520200729370117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+169, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3464.78857421875, 4614.2861328125, -0.35463121533393859, 2.285687923431396484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+170, 95920, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3564.140625, 4790.51025390625, 6.098958492279052734, 4.719182491302490234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Animated Storm (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+171, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3564.161376953125, 4590.328125, -5.89814949035644531, 5.43351602554321289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+172, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3615.359375, 4333.5498046875, -3.98679256439208984, 3.513118743896484375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+173, 91808, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3250.66259765625, 4429.40966796875, -2.76800203323364257, 3.253530025482177734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Serpentrix (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+174, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3596.587646484375, 4323.90966796875, -3.48239398002624511, 1.101797342300415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+175, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3443.343994140625, 4590.6513671875, -0.35463121533393859, 5.586636543273925781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+176, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3447.142578125, 4603.74658203125, -0.35463121533393859, 5.993109703063964843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+177, 99901, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -4291.8662109375, 4743.0751953125, 322.166290283203125, 5.738913536071777343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+178, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3440.318115234375, 4553.8623046875, -0.3546142578125, 0.473326802253723144, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+179, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3440.593994140625, 4620.1728515625, -0.35463106632232666, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+180, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3426.300537109375, 4560.1943359375, -0.3546142578125, 1.275967359542846679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+181, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3439.689697265625, 4599.548828125, -0.43796455860137939, 3.707772493362426757, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+182, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3528.35888671875, 4495.81884765625, 1.36535799503326416, 5.742013931274414062, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+183, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3441.408935546875, 4607.06640625, -0.43796455860137939, 2.412502765655517578, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+184, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3546.751220703125, 4602.90576171875, -5.95135450363159179, 1.978509306907653808, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+185, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3434.3544921875, 4619.0458984375, -0.43795779347419738, 1.180869340896606445, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+186, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3425.965576171875, 4586.5673828125, -0.35462650656700134, 2.285687923431396484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+187, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3758.23388671875, 4195.8876953125, 23.131683349609375, 1.068416714668273925, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+188, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3431.621337890625, 4610.84228515625, -0.43795764446258544, 3.968129396438598632, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+189, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3662.314453125, 4108.7314453125, 26.08896255493164062, 1.268143653869628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+190, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3426.57568359375, 4623.837890625, -0.40176627039909362, 2.151756763458251953, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+191, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3425.114990234375, 4604.109375, -0.3546278178691864, 4.43544626235961914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+192, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3724.8388671875, 4195.4365234375, 26.38649177551269531, 0.148352980613708496, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+193, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3529.3154296875, 4604.83740234375, -5.54505062103271484, 0.968710124492645263, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+194, 106786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3675.810791015625, 4100.43310546875, 26.83897590637207031, 2.916850566864013671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+195, 106785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3667.873291015625, 4109.45556640625, 26.2303466796875, 3.724520206451416015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+196, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3567.17529296875, 4306.12255859375, -2.39360427856445312, 0.245506137609481811, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+197, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3415.41357421875, 4570.51904296875, -0.35461422801017761, 2.578939199447631835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+198, 106786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3676.4462890625, 4107.291015625, 27.033935546875, 4.159023284912109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+199, 106787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3670.154541015625, 4104.1552734375, 25.8924102783203125, 3.411583423614501953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+200, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3423.27294921875, 4603.4716796875, -0.43796035647392272, 4.508795738220214843, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+201, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3660.936767578125, 4107.71484375, 25.93685340881347656, 1.466145277023315429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+202, 101414, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3656.369140625, 4109.18017578125, 26.04052543640136718, 1.445123910903930664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Skulker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196107 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+203, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3659.391357421875, 4109.52978515625, 26.08922767639160156, 1.448670625686645507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+204, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3658.05322265625, 4109.830078125, 26.08409881591796875, 1.442970871925354003, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+205, 106787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3668.151123046875, 4100.97900390625, 25.4906158447265625, 3.314257621765136718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+206, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3656.95458984375, 4108.978515625, 26.03501129150390625, 1.446085453033447265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+207, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3660.1630859375, 4108.818359375, 26.02767753601074218, 1.456511616706848144, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+208, 106785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3671.994873046875, 4095.6640625, 25.2960205078125, 3.001131057739257812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+209, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3420.625244140625, 4616.91064453125, -0.3546244204044342, 1.652570247650146484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+210, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3657.484130859375, 4109.68994140625, 26.07252120971679687, 1.443462610244750976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+211, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3730.274658203125, 4172.1103515625, 30.41823387145996093, 0.148352980613708496, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+212, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3598.7197265625, 4099.89306640625, 26.47145271301269531, 2.05395674705505371, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+213, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3593.5, 4099.53857421875, 27.89961814880371093, 6.005088329315185546, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+214, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3602.692626953125, 4101.2158203125, 26.2350311279296875, 1.472236156463623046, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+215, 99901, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3946.995361328125, 4577.90185546875, 230.2591400146484375, 4.901588916778564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+216, 100688, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3551.988037109375, 4275.0673828125, -2.51113319396972656, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+217, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3590.94775390625, 4098.888671875, 28.00550079345703125, 0.850510597229003906, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+218, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3600.36669921875, 4100.361328125, 26.36891937255859375, 2.327950716018676757, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+219, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3599.8623046875, 4098.38232421875, 26.2526397705078125, 4.606205940246582031, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+220, 101414, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3596.2724609375, 4104.49609375, 27.66608047485351562, 0.348518848419189453, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Skulker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196107 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+221, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3667.2763671875, 4167.439453125, 22.27693748474121093, 0.148352980613708496, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+222, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3595.726806640625, 4092.217041015625, 26.43720626831054687, 3.021156072616577148, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+223, 91787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3455.2333984375, 4179.55419921875, 62.04016876220703125, 0.707708895206451416, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+224, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3665.58544921875, 4103.5380859375, 23.51858329772949218, 0.148352980613708496, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+225, 106786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3552.65966796875, 4032.265625, 28.59006118774414062, 0.949515998363494873, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+226, 91796, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3590.80029296875, 4013.85498046875, 29.95814132690429687, 5.444530487060546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Wavecrasher (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+227, 91787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3490.2578125, 4072.0703125, 49.15579986572265625, 1.816137194633483886, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+228, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3660.144287109375, 4080.20654296875, 24.30280685424804687, 0.148352980613708496, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+229, 106787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3541.51220703125, 4026.940185546875, 26.57369232177734375, 1.193463683128356933, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+230, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3614.651123046875, 3976.142822265625, 26.44581794738769531, 2.715531110763549804, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+231, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3606.979248046875, 3977.109375, 25.43308639526367187, 2.643707275390625, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+232, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3637.714599609375, 3968.775146484375, 29.11952972412109375, 5.260818958282470703, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+233, 106785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3540.666748046875, 4021.00341796875, 24.573455810546875, 6.150302886962890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+234, 91787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3591.116455078125, 3985.15771484375, 56.57271194458007812, 1.116581082344055175, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+235, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3621.374755859375, 3971.952880859375, 27.7655029296875, 4.910838127136230468, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+236, 106787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3531.677001953125, 4017.013916015625, 20.9542236328125, 2.399114608764648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+237, 91796, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3459.0712890625, 4084.907958984375, 20.0093994140625, 4.959829330444335937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Wavecrasher (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+238, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3611.897216796875, 3967.624755859375, 25.72297859191894531, 4.228907108306884765, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+239, 106786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3528.848876953125, 4021.30908203125, 21.395050048828125, 0.055973254144191741, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+240, 99901, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -4103.451171875, 4722.87744140625, 324.12200927734375, 5.485919952392578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+241, 101414, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3622.649169921875, 3964.482666015625, 28.20181846618652343, 2.506571054458618164, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Skulker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196107 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+242, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3612.888427734375, 3961.0634765625, 25.160888671875, 3.927681207656860351, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+243, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3622.012451171875, 3957.03466796875, 25.87067794799804687, 2.831499099731445312, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+244, 106785, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3524.619873046875, 4015.740478515625, 18.41521453857421875, 0.524307191371917724, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+245, 95939, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3573.653076171875, 3971.1806640625, 19.2339324951171875, 5.678757190704345703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Tidestomper (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+246, 101414, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3480.57470703125, 4033.088623046875, 8.546875, 2.907809972763061523, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Skulker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196107 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+247, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3487.4931640625, 4027.35595703125, 7.777714252471923828, 4.675804615020751953, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+248, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3482.62158203125, 4028.796875, 7.690995216369628906, 2.663520336151123046, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+249, 95939, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3442.75341796875, 4082.733642578125, 18.75268745422363281, 4.450808048248291015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Tidestomper (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+250, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3492.475830078125, 4028.18408203125, 8.53125, 3.463420629501342773, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+251, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3488.74658203125, 4031.3994140625, 8.576388359069824218, 0.591701149940490722, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+252, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3482.71875, 4036.244873046875, 9.328125, 1.819296002388000488, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+253, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3484.670166015625, 4032.05029296875, 8.402777671813964843, 3.949906349182128906, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+254, 91794, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3486.092041015625, 4035.385498046875, 9.190972328186035156, 5.621885299682617187, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+255, 91787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3543.7666015625, 4748.28076171875, 30.72567939758300781, 4.34410858154296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+256, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3402.368408203125, 4589.10595703125, -0.35460779070854187, 5.488472461700439453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+257, 97853, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3408.968994140625, 4608.91845703125, -0.3546074628829956, 0.256104469299316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sand Dune (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 193060 - Sand Dune, 193064 - Sand Dune)
(@CGUID+258, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3433.782958984375, 4662.45849609375, 3.029950141906738281, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+259, 111936, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3477.291748046875, 4389.30712890625, -2.79731392860412597, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Thal'kiel (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+260, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3430.882080078125, 4675.5302734375, 2.790008306503295898, 1.948764681816101074, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+261, 111374, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3477.291748046875, 4389.30712890625, -2.79731392860412597, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Xal'atath (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+262, 91787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3415.438720703125, 4649.1669921875, 32.1780242919921875, 1.767543673515319824, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+263, 91787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3436.236572265625, 4681.4326171875, 24.03380393981933593, 1.767497420310974121, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+264, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3425.425537109375, 4666.98583984375, 2.85117340087890625, 5.638924121856689453, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+265, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3425.997802734375, 4661.14990234375, 2.928825855255126953, 0.588002622127532958, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+266, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3427.104736328125, 4676.46728515625, 2.826894521713256835, 3.362907171249389648, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+267, 91787, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3390.259765625, 4621.5703125, 30.07792472839355468, 4.734229087829589843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+268, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3475.4609375, 4744.2607421875, 1.96200263500213623, 4.059907436370849609, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+269, 91786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3516.761962890625, 4781.0732421875, 3.546297550201416015, 1.493572831153869628, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+270, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3420.815185546875, 4664.63818359375, 2.806516170501708984, 3.597383737564086914, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+271, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3470.142822265625, 4739.91357421875, 1.85527956485748291, 4.193243026733398437, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+272, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3466.19287109375, 4749.55615234375, 2.04634857177734375, 5.281035423278808593, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+273, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3556.29296875, 4691.89111328125, 4.958025932312011718, 6.235277175903320312, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+274, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3454.4677734375, 4743.462890625, 4.280048370361328125, 5.315028667449951171, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+275, 91786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3432.2080078125, 4711.1376953125, 5.142304897308349609, 5.695995807647705078, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+276, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3474.27587890625, 4763.13916015625, 3.271763324737548828, 2.114900827407836914, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+277, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3494.3935546875, 4620.8017578125, 3.201495170593261718, 3.135300159454345703, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+278, 91786, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3391.14794921875, 4657.78125, 2.083861827850341796, 3.878619194030761718, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+279, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3449.03173828125, 4761.1767578125, 4.30003976821899414, 4.616511344909667968, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+280, 97173, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3413.310302734375, 4716.34912109375, 4.681903839111328125, 5.43364572525024414, 7200, 8, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Restless Tides (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+281, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3362.832275390625, 4565.365234375, -0.43619453907012939, 4.735286712646484375, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+282, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3535.91748046875, 4748.1533203125, 1.958094120025634765, 5.304723262786865234, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+283, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3462.197998046875, 4813.6708984375, 3.713826417922973632, 3.965645790100097656, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+284, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3453.77392578125, 4811.43994140625, 3.580910205841064453, 3.76768803596496582, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+285, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3451.64599609375, 4819.16015625, 2.894360065460205078, 5.325160503387451171, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+286, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3458.60009765625, 4824.98486328125, 3.331391811370849609, 3.926645517349243164, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+287, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3359.8779296875, 4579.51513671875, -0.47142094373703002, 2.024270057678222656, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+288, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3456.00537109375, 4578.326171875, -0.43796455860137939, 0.788698494434356689, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+289, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3449.3876953125, 4819.63330078125, 2.523581743240356445, 3.365242719650268554, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+290, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3360.690185546875, 4566.98583984375, -0.45296236872673034, 2.842899322509765625, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+291, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3466.333251953125, 4637.126953125, 0.485124856233596801, 3.541487932205200195, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+292, 97170, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 1, -3436.413330078125, 4811.16650390625, 3.269346952438354492, 2.430081844329833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Hatecoil Wavebinder (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+293, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3457.87890625, 4475.62451171875, 2.923498868942260742, 0.782635688781738281, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+294, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3345.789794921875, 4574.91162109375, -1.0035172700881958, 5.176411628723144531, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+295, 111221, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3463.479736328125, 4610.623046875, -0.43796455860137939, 3.882560253143310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Xal'atath (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+296, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3440.375, 4826.50146484375, 2.495294570922851562, 5.295517921447753906, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+297, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3348.492431640625, 4566.01318359375, -0.9113045334815979, 4.358073711395263671, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+298, 95920, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3433.064208984375, 4815.60693359375, 2.907986164093017578, 2.862430572509765625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Animated Storm (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@CGUID+299, 97172, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3349.307861328125, 4567.7353515625, -0.91886788606643676, 5.710908412933349609, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltsea Droplet (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+300, 99908, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, 0, 0, -3527.291015625, 4781.353515625, 3.122327566146850585, 5.819538116455078125, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+301, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3329.380615234375, 4549.6337890625, -1.69378829002380371, 3.5447235107421875, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+302, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3453.259033203125, 4766.86376953125, 4.282325267791748046, 0.889063596725463867, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+303, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3450.206787109375, 4485.2939453125, 3.909032583236694335, 5.023951530456542968, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+304, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3327.240234375, 4542.732421875, -1.43147754669189453, 6.041523456573486328, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+305, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3316.328125, 4537.69580078125, -0.06231038272380828, 2.295058250427246093, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+306, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3318.41015625, 4548.3740234375, -0.35624182224273681, 1.056012272834777832, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+307, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3337.786376953125, 4756.19287109375, -0.1927083134651184, 1.200172662734985351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+308, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3325.107666015625, 4537.537109375, -0.28154098987579345, 5.475779533386230468, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+309, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3408.90673828125, 4671.052734375, 2.599517822265625, 1.08467268943786621, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+310, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3307.198974609375, 4629.25, 0.781997263431549072, 3.892038345336914062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 55701 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+311, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3334.0244140625, 4756.087890625, -0.6268470287322998, 2.312863826751708984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+312, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3307.0712890625, 4615.20654296875, 0.881064414978027343, 3.911238670349121093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 55701 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+313, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3334.204833984375, 4760.0537109375, -0.65234231948852539, 2.926417827606201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+314, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3335.02783203125, 4764.27783203125, -0.5106738805770874, 3.158624172210693359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+315, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3308.22216796875, 4623.484375, 0.779680550098419189, 3.214982986450195312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 55701 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+316, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3303.116455078125, 4613.609375, 0.880949139595031738, 5.084109783172607421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 55701 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+317, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3325.157958984375, 4763.40185546875, -0.99290937185287475, 1.152025938034057617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+318, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3326.850830078125, 4766.61376953125, -0.85216379165649414, 0.583856523036956787, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+319, 95947, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3331.857421875, 4458.43994140625, 1.793772578239440917, 3.006329059600830078, 7200, 8, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Mak'rana Hardshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 196201 - Clobbering Claws) (possible waypoints or random movement)
(@CGUID+320, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3297.2119140625, 4617.97216796875, 0.589456677436828613, 5.296845436096191406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 55701 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+321, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3421.5458984375, 4490.33935546875, 3.981945991516113281, 5.056989192962646484, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+322, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3292.944580078125, 4621.74853515625, 0.880010724067687988, 3.828546047210693359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 55701 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+323, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3281.835205078125, 4734.6005859375, 2.140068769454956054, 0.317137748003005981, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+324, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3276.170166015625, 4721.1630859375, 1.776169300079345703, 2.656085491180419921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+325, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3279.960205078125, 4729.93212890625, 2.144608736038208007, 0.05241313949227333, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+326, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3279.328125, 4726.26416015625, 2.209354162216186523, 0.313860446214675903, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+327, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3283.958251953125, 4742.94189453125, 2.023091554641723632, 0.365802228450775146, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+328, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3278.267333984375, 4750.5087890625, 1.793425559997558593, 4.412449359893798828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+329, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3249.111083984375, 4655.20068359375, 13.36304378509521484, 2.705385923385620117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+330, 97263, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3294.204345703125, 4460.5244140625, -0.63378405570983886, 3.928018808364868164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sinkhole (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+331, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3246.979248046875, 4659.916015625, 8.437593460083007812, 4.608414649963378906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+332, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3249.357666015625, 4664.775390625, 9.22074127197265625, 4.019757270812988281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+333, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3245.88720703125, 4651.29443359375, 12.38432788848876953, 5.281933784484863281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+334, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3240.13720703125, 4655.73291015625, 6.749810218811035156, 2.818599224090576171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+335, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3238.244873046875, 4665.40869140625, 7.172440052032470703, 0.63779616355895996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+336, 95947, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3255.476318359375, 4536.73046875, 1.007407903671264648, 5.850001811981201171, 7200, 8, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Mak'rana Hardshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 196201 - Clobbering Claws) (possible waypoints or random movement)
(@CGUID+337, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3222.92529296875, 4671.67041015625, 1.402180075645446777, 0.13882206380367279, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+338, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3222.97216796875, 4677.23291015625, 2.349409818649291992, 0.994754552841186523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+339, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3216.828125, 4670.142578125, 1.234164357185363769, 2.247277021408081054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+340, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3215.94091796875, 4675.673828125, 6.754994392395019531, 5.886783123016357421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+341, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3210.5625, 4677.77783203125, 1.919625639915466308, 2.413219690322875976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+342, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3315.2587890625, 4700.421875, 1.985651016235351562, 0, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+343, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3213.439208984375, 4672.08056640625, 1.557942986488342285, 2.452884197235107421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+344, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3371.922119140625, 4483.443359375, 0.72061699628829956, 2.495405435562133789, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+345, 97263, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3304.172119140625, 4405.5302734375, 0.087278194725513458, 3.246477603912353515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sinkhole (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+346, 97263, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3246.706787109375, 4479.6494140625, 0.266675144433975219, 3.287955284118652343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sinkhole (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+347, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3289.32861328125, 4639.13916015625, 2.173336744308471679, 4.106336116790771484, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+348, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3189.962158203125, 4611.0791015625, 2.665327787399291992, 0.188725441694259643, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+349, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3190.06982421875, 4622.37060546875, 3.302070379257202148, 5.647363662719726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+350, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3369.138916015625, 4472.82666015625, 1.873877763748168945, 1.281417131423950195, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+351, 91792, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3228.44970703125, 4496.6611328125, 1.943579554557800292, 2.105689048767089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Stormwake Hydra (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 202314 - Vile Blood) (possible waypoints or random movement)
(@CGUID+352, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3179.831787109375, 4624.40966796875, 2.296846866607666015, 4.886385917663574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+353, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3180.4462890625, 4606.5712890625, 2.513917446136474609, 5.407036304473876953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+354, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3181.64013671875, 4602.248046875, 2.180274724960327148, 1.246277332305908203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+355, 91787, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3200.72265625, 4539.14013671875, 21.35262107849121093, 4.846299171447753906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+356, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3212.4091796875, 4476.41015625, 1.018820166587829589, 1.903654694557189941, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+357, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3168.255615234375, 4617.4560546875, 0.890886127948760986, 3.541301727294921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+358, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3294.19384765625, 4540.04638671875, 1.232572555541992187, 3.814807415008544921, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+359, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3208.086669921875, 4467.693359375, 1.090576052665710449, 1.952156424522399902, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+360, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3210.409423828125, 4470.74755859375, 1.018372535705566406, 1.785583853721618652, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+361, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3188.322021484375, 4488.9794921875, 1.015298843383789062, 2.029438495635986328, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+362, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3212.1904296875, 4461.53369140625, 1.052972078323364257, 1.394957780838012695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+363, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3189.9990234375, 4492.66943359375, 1.015296101570129394, 5.0250244140625, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+364, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3181.47412109375, 4484.9384765625, 1.01533210277557373, 3.866854429244995117, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+365, 91790, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3253.398681640625, 4393.04345703125, 2.764190673828125, 0.082167528569698333, 7200, 8, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Mak'rana Siltwalker (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+366, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3181.84814453125, 4491.28955078125, 1.015299439430236816, 3.93876051902770996, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+367, 91792, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3243.757080078125, 4398.91357421875, 1.238774061203002929, 0.00585930747911334, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Stormwake Hydra (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 202314 - Vile Blood) (possible waypoints or random movement)
(@CGUID+368, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3182.28515625, 4484.59716796875, 1.015299439430236816, 4.577154159545898437, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+369, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3301.84033203125, 4491.5400390625, 1.002175807952880859, 0.565611600875854492, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+370, 91787, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3254.8623046875, 4447.73193359375, 25.82147979736328125, 2.480941295623779296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+371, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3237.56103515625, 4778.60986328125, -8.7878885269165039, 2.276667594909667968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+372, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3252.379638671875, 4805.16943359375, -6.43835735321044921, 2.049726486206054687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+373, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3215.11669921875, 4747.71826171875, -5.79726123809814453, 4.417191982269287109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+374, 91787, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3166.0673828125, 4526.97802734375, 36.70028305053710937, 6.139642715454101562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+375, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3198.1171875, 4784.72607421875, -9.26674938201904296, 3.471027135848999023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+376, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3206.171630859375, 4615.01904296875, 2.180108308792114257, 0.97575157880783081, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+377, 97263, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3192.2431640625, 4440.1787109375, -0.64834195375442504, 3.349827289581298828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sinkhole (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+378, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3193.4267578125, 4631.5419921875, 2.640823602676391601, 5.580699443817138671, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+379, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3182.291015625, 4659.8955078125, 3.25593113899230957, 5.300103187561035156, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+380, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3116.8876953125, 4516.875, -0.18129621446132659, 2.74455881118774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+381, 97263, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3256.363037109375, 4370.3857421875, 0.374848425388336181, 2.72139906883239746, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sinkhole (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+382, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3112.450927734375, 4520.5, -0.17370286583900451, 4.762970447540283203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+383, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3120.218505859375, 4521.23828125, -0.13564030826091766, 4.378950119018554687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+384, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3114.538818359375, 4510.9990234375, -0.22271488606929779, 2.58479619026184082, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+385, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3346.77099609375, 4420.96923828125, 2.596593618392944335, 0.907954096794128417, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+386, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3159.107177734375, 4436.90283203125, 3.362847089767456054, 1.173432230949401855, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+387, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3106.83544921875, 4516.13671875, -0.21046683192253112, 0.697786152362823486, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+388, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3147.710693359375, 4433.16064453125, 5.643816947937011718, 6.133136272430419921, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+389, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3159.341064453125, 4426.12109375, 3.824751853942871093, 1.8954240083694458, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+390, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3154.12646484375, 4430.3203125, 4.157142162322998046, 0.261612117290496826, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+391, 97263, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3199.404052734375, 4384.951171875, 0.161309659481048583, 3.025057077407836914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Sinkhole (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+392, 91787, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3211.970947265625, 4376.73779296875, 19.94741249084472656, 5.897916793823242187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+393, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3152.017578125, 4423.5673828125, 5.212732791900634765, 4.84020233154296875, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+394, 95947, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3283.699951171875, 4325.9453125, 1.178809285163879394, 2.585140705108642578, 7200, 8, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Mak'rana Hardshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 196201 - Clobbering Claws) (possible waypoints or random movement)
(@CGUID+395, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3057.239990234375, 4562.84716796875, 2.772485256195068359, 0.188725441694259643, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+396, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3057.347412109375, 4574.138671875, 3.718151807785034179, 5.647363662719726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+397, 95940, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3047.109619140625, 4576.1787109375, 3.96745157241821289, 4.886385917663574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+398, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3224.861083984375, 4333.0517578125, 3.317789316177368164, 4.895037651062011718, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+399, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3045.097412109375, 4560.265625, 2.632425785064697265, 1.585958242416381835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+400, 99629, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3048.918701171875, 4554.017578125, 2.100989580154418945, 1.246277332305908203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+401, 91787, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3144.21533203125, 4404.9111328125, 24.73698997497558593, 5.186081886291503906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+402, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3233.833984375, 4342.14501953125, 1.642935872077941894, 3.158192873001098632, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+403, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3131.23681640625, 4709.89599609375, -4.53386688232421875, 0.186348691582679748, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+404, 99630, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 1, -3043.875244140625, 4567.1591796875, 3.214764356613159179, 3.541301727294921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Scavenger (Area: Whispering Willows - Difficulty: Normal) CreateObject1
(@CGUID+405, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3224.247802734375, 4339.9658203125, 1.299927949905395507, 6.101651668548583984, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+406, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3219.83544921875, 4327.47509765625, 1.491340994834899902, 2.205905675888061523, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+407, 91792, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3092.6943359375, 4451.251953125, 4.347273826599121093, 3.780785799026489257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Stormwake Hydra (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 202314 - Vile Blood) (possible waypoints or random movement)
(@CGUID+408, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3115.411376953125, 4419.583984375, 8.470083236694335937, 5.782697200775146484, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+409, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3217.385498046875, 4332.00732421875, 1.042782187461853027, 6.015800952911376953, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+410, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3069.8974609375, 4471.3642578125, 6.195079326629638671, 2.721040964126586914, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+411, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3066.172119140625, 4456.21728515625, 5.953661918640136718, 2.93597722053527832, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+412, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3103.527099609375, 4410.20263671875, 9.287243843078613281, 0.394599467515945434, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+413, 91786, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3344.194091796875, 4255.88671875, -0.39835515618324279, 2.160965204238891601, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+414, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3071.367919921875, 4461.30615234375, 5.528322219848632812, 3.171171903610229492, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+415, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3109.23046875, 4421.00390625, 8.439008712768554687, 1.286944985389709472, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+416, 91787, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3219.212646484375, 4317.50244140625, 22.08173370361328125, 1.686628580093383789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+417, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3064.2861328125, 4463.298828125, 5.885148048400878906, 2.217568397521972656, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+418, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3191.0068359375, 4457.83349609375, 1.612521171569824218, 1.584467291831970214, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+419, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3110.809814453125, 4406.92431640625, 9.41464996337890625, 2.362414360046386718, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+420, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3073.356201171875, 4465.19873046875, 5.734923839569091796, 4.824975967407226562, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+421, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3112.548828125, 4410.9970703125, 9.129987716674804687, 4.209068775177001953, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+422, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3365.44140625, 4351.07373046875, 2.345423698425292968, 4.542905330657958984, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+423, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3133.310546875, 4341.21875, 7.179100990295410156, 0.436238080263137817, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+424, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3130.6181640625, 4332.77294921875, 6.287842750549316406, 2.875819683074951171, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+425, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3135.519287109375, 4340.853515625, 7.047010421752929687, 3.008886575698852539, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+426, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3274.986083984375, 4356.9443359375, 2.210096120834350585, 0.273873716592788696, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+427, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3099.8681640625, 4604.08349609375, -3.31519293785095214, 2.488100290298461914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+428, 91787, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3178.4013671875, 4317.63427734375, 32.6956329345703125, 1.316872596740722656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+429, 91790, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3244.25634765625, 4271.333984375, 2.766541242599487304, 4.936991691589355468, 7200, 8, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Mak'rana Siltwalker (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+430, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3133.2958984375, 4328.63671875, 6.285531997680664062, 2.222921609878540039, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+431, 99908, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3303.215087890625, 4352.8896484375, 2.608944177627563476, 0.932956993579864501, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+432, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3130.0341796875, 4330.61865234375, 6.205507278442382812, 5.845380306243896484, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+433, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3175.328125, 4289.26904296875, 4.375746726989746093, 4.353275775909423828, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+434, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3091.240478515625, 4692.01220703125, -3.2411046028137207, 0.851782500743865966, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+435, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3175.62890625, 4278.6357421875, 3.252178907394409179, 2.356194496154785156, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+436, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3116.1328125, 4770.03759765625, -8.92969036102294921, 4.561373710632324218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+437, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3084.5556640625, 4550.37841796875, -0.27262169122695922, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+438, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3134.118408203125, 4799.482421875, -9.23242378234863281, 0.407861530780792236, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+439, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3180.53857421875, 4283.30517578125, 3.102488994598388671, 3.588064908981323242, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+440, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3180.67333984375, 4288.4453125, 3.576187372207641601, 4.917784690856933593, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+441, 91793, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3165.782470703125, 4285.25537109375, 4.406301498413085937, 0.524295210838317871, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Seaspray Crab (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+442, 100688, 1456, 8040, 8084, '1,2,8,23,24', 0, 0, 0, 0, -3083.84228515625, 4650.4091796875, -3.33221101760864257, 2.815433502197265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Whispering Willows - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+443, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3180.677490234375, 4254.5068359375, 3.897961139678955078, 0.930872738361358642, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+444, 101414, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3180.677490234375, 4254.5068359375, 3.897961139678955078, 0.930872738361358642, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Skulker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196107 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+445, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3381.241943359375, 4319.51171875, 2.57170414924621582, 3.83172607421875, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+446, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3014.299560546875, 4657.14453125, -9.023956298828125, 0.545764803886413574, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+447, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3015.957275390625, 4672.80126953125, -8.45808696746826171, 3.471071243286132812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+448, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3016.487060546875, 4628.26123046875, -8.76298046112060546, 0.142238765954971313, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+449, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3007.82421875, 4582.2744140625, -5.64058780670166015, 1.975047230720520019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+450, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -2989.086669921875, 4645.9931640625, -9.26704883575439453, 0.240794330835342407, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+451, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -2991.896728515625, 4600.14111328125, -8.39650630950927734, 5.228219985961914062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+452, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3023.137451171875, 4787.31640625, -8.74599170684814453, 1.303693890571594238, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+453, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -2995.328857421875, 4582.96533203125, -5.57481193542480468, 2.253599882125854492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+454, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -2982.422607421875, 4620.79541015625, -9.01709842681884765, 1.893075823783874511, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+455, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3113.979248046875, 4403.10546875, 9.158390045166015625, 0.517814099788665771, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+456, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -2977.153076171875, 4672.04248046875, -9.26797008514404296, 1.89346623420715332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+457, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -2992.84521484375, 4747.66357421875, -6.51538324356079101, 6.196299076080322265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+458, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -2984.71630859375, 4725.05126953125, -8.23727798461914062, 3.043346643447875976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+459, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -2986.99462890625, 4760.8837890625, -8.38907432556152343, 5.200664520263671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+460, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3104.446533203125, 4352.71337890625, 8.607477188110351562, 2.291278839111328125, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+461, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3172.18798828125, 4309.8515625, 5.459452629089355468, 0.432934880256652832, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+462, 91796, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3224.7900390625, 4183.4150390625, 6.508302688598632812, 1.35138702392578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Wavecrasher (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+463, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3283.28857421875, 4273.3359375, 1.672098636627197265, 3.907017230987548828, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+464, 91786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3266.1455078125, 4172.072265625, 5.500998973846435546, 1.444046497344970703, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+465, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3346.9072265625, 4253.68359375, 0.131143152713775634, 0.839287877082824707, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+466, 106785, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3200.26904296875, 4141.4912109375, 5.645267963409423828, 0.415741801261901855, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+467, 106786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3197.05029296875, 4134.15380859375, 7.380984306335449218, 0.768881261348724365, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+468, 91786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3384.887451171875, 4146.6396484375, 28.66955375671386718, 3.708511114120483398, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+469, 106786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3199.23095703125, 4137.6474609375, 6.305386066436767578, 0.306480824947357177, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+470, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3217.592041015625, 4224.9775390625, 6.753133296966552734, 0, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+471, 106785, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3201.486083984375, 4122.56787109375, 6.95211029052734375, 5.919156074523925781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+472, 100688, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3428.904296875, 4264.3984375, -2.08572077751159667, 2.092122554779052734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Brightscale Darters (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+473, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3462.7890625, 4278.39404296875, 0.50815749168395996, 0.431316226720809936, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+474, 106787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3219.630126953125, 4107.37158203125, 5.081668853759765625, 4.56280374526977539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+475, 106787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3217.350830078125, 4110.1572265625, 5.4366607666015625, 5.565156459808349609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+476, 106785, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3294.092041015625, 4075.4072265625, 3.237128496170043945, 3.253065109252929687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+477, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3187.275390625, 4196.705078125, 6.182871341705322265, 5.09970855712890625, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+478, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3379.438232421875, 4186.359375, 28.58620834350585937, 0.436359703540802001, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+479, 106786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3286.432373046875, 4072.236083984375, 3.995487689971923828, 4.040921688079833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+480, 106785, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3272.407958984375, 4069.177978515625, 3.080481290817260742, 1.220619440078735351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+481, 106786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3274.3212890625, 4072.38720703125, 2.660865545272827148, 0.567930281162261962, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+482, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3430.548583984375, 4195.92041015625, 30.18483161926269531, 1.988868236541748046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+483, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3439.9384765625, 4210.23779296875, 30.18380355834960937, 2.716063976287841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+484, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3441.550048828125, 4203.7109375, 29.18482780456542968, 4.541939258575439453, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+485, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3372.16015625, 4177.83349609375, 28.58608627319335937, 2.464536905288696289, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+486, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3420.785888671875, 4184.4375, 30.18483734130859375, 2.039546966552734375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+487, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3440.140869140625, 4195.85498046875, 30.18481826782226562, 2.287674665451049804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+488, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3437.3740234375, 4186.7421875, 29.18482208251953125, 4.833046913146972656, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+489, 106787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3276.814208984375, 4047.803955078125, 4.691112995147705078, 3.347945213317871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+490, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3462.83349609375, 4203.0458984375, 29.19532966613769531, 0.585553288459777832, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+491, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3458.684326171875, 4205.6630859375, 30.20577621459960937, 1.266253471374511718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+492, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3446.85791015625, 4195.51904296875, 29.18481826782226562, 0.923935294151306152, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+493, 106787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3289.885498046875, 4049.569580078125, 6.288845062255859375, 5.822946071624755859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+494, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3426.687744140625, 4178.9482421875, 30.18482208251953125, 1.899170279502868652, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+495, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3454.599853515625, 4188.21875, 30.18482780456542968, 1.630012273788452148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+496, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3431.5341796875, 4177.3232421875, 29.18482589721679687, 0.482335239648818969, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+497, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3445.140625, 4185.63623046875, 29.18482589721679687, 2.78457808494567871, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+498, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3473.631103515625, 4199.7373046875, 30.22464942932128906, 0.362295120954513549, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+499, 91786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3262.41259765625, 4038.190673828125, 5.785771369934082031, 3.350866317749023437, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+500, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3423.48095703125, 4165.3173828125, 30.18481826782226562, 1.266231298446655273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+501, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3414.576416015625, 4169.44580078125, 29.20569610595703125, 2.471050262451171875, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+502, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3412.954345703125, 4157.69482421875, 29.53468704223632812, 1.001219749450683593, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+503, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3441.93359375, 4186.78173828125, 30.18482208251953125, 0.87052464485168457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+504, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3388.1650390625, 4153.3076171875, 28.58596038818359375, 3.92158818244934082, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+505, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3440.81982421875, 4163.84228515625, 29.18481826782226562, 4.456305503845214843, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+506, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3450.0546875, 4173.89599609375, 29.18482208251953125, 4.769413948059082031, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+507, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3458.1865234375, 4181.15185546875, 29.18482017517089843, 1.618116974830627441, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+508, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3429.84814453125, 4161.0927734375, 30.18481826782226562, 6.18912363052368164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+509, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3434.586181640625, 4166.142578125, 30.18482208251953125, 5.899340629577636718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+510, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3477.601318359375, 4188.18310546875, 30.18478012084960937, 0.591779828071594238, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+511, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3419.19287109375, 4155.0634765625, 30.18491935729980468, 0.875067412853240966, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+512, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3256.45703125, 4031.797607421875, 7.067810535430908203, 2.30319976806640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+513, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3480.233642578125, 4186.7001953125, 29.18482589721679687, 3.968238115310668945, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+514, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3443.95068359375, 4163.47607421875, 29.18482208251953125, 0.969074606895446777, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+515, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3468.47705078125, 4180.54150390625, 30.18482208251953125, 0.419610857963562011, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+516, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3470.082275390625, 4178.22119140625, 29.18482208251953125, 3.94877791404724121, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+517, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3429.06201171875, 4154.52978515625, 29.18482208251953125, 6.215602397918701171, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+518, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3441.65576171875, 4150.86669921875, 30.18497657775878906, 0.271941721439361572, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+519, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3481.563720703125, 4172.48046875, 29.18482208251953125, 1.968804717063903808, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+520, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3462.043701171875, 4167.47705078125, 30.18482208251953125, 1.695146083831787109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+521, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3455.302001953125, 4164.05712890625, 29.18482398986816406, 4.456004142761230468, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+522, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3431.709228515625, 4160.33154296875, 30.184814453125, 1.155398130416870117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+523, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3456.638671875, 4167.64453125, 30.18482589721679687, 0.207548633217811584, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+524, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3467.582275390625, 4168.9560546875, 29.18482589721679687, 1.401896476745605468, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+525, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3419.458984375, 4132.90185546875, 30.18557929992675781, 4.501825809478759765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+526, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3470.8427734375, 4160.86474609375, 30.18483924865722656, 6.046123981475830078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+527, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3462.66259765625, 4154.96435546875, 29.18483924865722656, 3.329100608825683593, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+528, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3240.614990234375, 4119.26416015625, 4.783512592315673828, 6.139348506927490234, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+529, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3430.696533203125, 4135.59326171875, 29.18483543395996093, 0.413602709770202636, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+530, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3478.45849609375, 4163.53466796875, 30.18482780456542968, 1.33274388313293457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+531, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3456.46875, 4149.3291015625, 29.18482780456542968, 2.614176750183105468, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+532, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3413.385009765625, 4129.4833984375, 30.18343734741210937, 0.46486172080039978, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+533, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3485.5283203125, 4169.60498046875, 30.20572280883789062, 1.011958241462707519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+534, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3483.373046875, 4169.1591796875, 30.18482017517089843, 1.528078675270080566, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+535, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3449.117431640625, 4145.578125, 30.18482398986816406, 0.33570072054862976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+536, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3435.16552734375, 4138.99267578125, 30.18503570556640625, 1.48698890209197998, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+537, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3483.27392578125, 4171.123046875, 30.18482208251953125, 1.054703235626220703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+538, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3439.88427734375, 4142.435546875, 30.18482208251953125, 1.976809263229370117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+539, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3442.134765625, 4143.5087890625, 30.18482589721679687, 6.233796119689941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+540, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3449.605712890625, 4146.93603515625, 30.18482208251953125, 0.484635233879089355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+541, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3448.91259765625, 4148.7001953125, 30.18482017517089843, 1.382779717445373535, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+542, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3454.11767578125, 4144.52880859375, 30.18482208251953125, 6.189679622650146484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+543, 91787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3478.8818359375, 4044.818115234375, 46.86083221435546875, 6.032802104949951171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+544, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3445.59130859375, 4136.10986328125, 30.18506050109863281, 5.632901668548583984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+545, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3472.427490234375, 4147.81103515625, 29.18482398986816406, 3.661856889724731445, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+546, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3483.333984375, 4156.25, 29.18482208251953125, 0.918233990669250488, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+547, 106786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3361.908203125, 3993.010498046875, 8.821019172668457031, 2.862891674041748046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+548, 106785, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3360.344970703125, 3998.02783203125, 14.62426090240478515, 3.196066856384277343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+549, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3451.450927734375, 4130.12255859375, 29.18387413024902343, 3.77071237564086914, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+550, 95939, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3379.121826171875, 4000.00341796875, 6.719095706939697265, 5.613141059875488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Tidestomper (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+551, 97844, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3466.114501953125, 4140.9541015625, 30.18482398986816406, 0.40690779685974121, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Call the Seas (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+552, 106787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3365.731201171875, 3982.600830078125, 3.88733839988708496, 2.20269632339477539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+553, 106785, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3366.77294921875, 3987.994873046875, 5.240522384643554687, 2.380314111709594726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+554, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3331.25927734375, 3975.980712890625, 1.893538236618041992, 4.273379325866699218, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+555, 106786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3360.629638671875, 3987.8681640625, 5.304277896881103515, 2.60903024673461914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+556, 106787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3372.3857421875, 3981.232666015625, 3.912815093994140625, 1.816847920417785644, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+557, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3329.166015625, 3979.1669921875, 2.096773147583007812, 3.948411464691162109, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+558, 101414, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3332.560302734375, 3979.318603515625, 2.068711519241333007, 4.767321586608886718, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Skulker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196107 - Mrrglrr!)
(@CGUID+559, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3332.9658203125, 3977.05029296875, 1.93293309211730957, 2.639527797698974609, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+560, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3345.833984375, 3979.1669921875, 2.380189895629882812, 5.4977874755859375, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+561, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3333.06787109375, 3979.487060546875, 2.088620185852050781, 1.923959016799926757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+562, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3276.366943359375, 4073.935302734375, 2.825688600540161132, 6.100086688995361328, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+563, 91796, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3272.4091796875, 3975.513916015625, 3.313720226287841796, 4.280910968780517578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Wavecrasher (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+564, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3333.333984375, 3970.833984375, 1.823034524917602539, 2.517010211944580078, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+565, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3336.424560546875, 3973.718505859375, 1.837928414344787597, 3.021463394165039062, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+566, 91786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3453.990478515625, 3995.38623046875, 2.380541086196899414, 4.259658336639404296, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+567, 91786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3392.053955078125, 3961.31494140625, 6.385232925415039062, 4.348931789398193359, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+568, 91787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3326.72216796875, 3943.926025390625, 35.8412322998046875, 1.394323110580444335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+569, 91787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3245.437255859375, 3935.031005859375, 33.53747940063476562, 1.760100245475769042, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Cove Seagull (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+570, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3421.934814453125, 4080.53564453125, 16.06594467163085937, 0.958768308162689208, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+571, 91786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3335.488037109375, 3939.826416015625, 2.113157033920288085, 0.78884899616241455, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+572, 101414, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3245.5087890625, 3919.721435546875, 2.814236164093017578, 6.105403900146484375, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Skulker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196107 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+573, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3243.49755859375, 3920.565185546875, 3.167960882186889648, 1.642026901245117187, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+574, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3240.680419921875, 3914.193603515625, 3.953558921813964843, 3.124992609024047851, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+575, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3234.464111328125, 3920.45166015625, 4.167500495910644531, 3.778153419494628906, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+576, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3250.914306640625, 3914.15576171875, 2.568304300308227539, 2.017400026321411132, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+577, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3240.638671875, 3913.5986328125, 4.045114517211914062, 0.97575157880783081, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+578, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3253.2998046875, 3911.026123046875, 2.541420698165893554, 4.038073539733886718, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+579, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3245.515625, 3911.6923828125, 3.450839042663574218, 3.292608261108398437, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+580, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3360.804443359375, 3881.748291015625, 0.264050543308258056, 1.330508232116699218, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+581, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3367.15771484375, 3887.641845703125, 1.204268336296081542, 2.640996932983398437, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+582, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3353.8994140625, 3878.83935546875, 0.399305582046508789, 4.299768447875976562, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+583, 99908, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3465.8466796875, 4099.25244140625, 25.50641822814941406, 4.274936676025390625, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+584, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3358.81494140625, 3891.137451171875, 1.199307084083557128, 0.725012242794036865, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+585, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3356.25, 3887.5, 0.750762104988098144, 0.898201704025268554, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+586, 101414, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3358.98291015625, 3876.90673828125, 0.293737649917602539, 2.016469478607177734, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Skulker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196107 - Mrrglrr!)
(@CGUID+587, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3359.49267578125, 3879.9111328125, 0.266675233840942382, 1.748436331748962402, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+588, 106786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3294.08544921875, 3847.819580078125, 0.548017084598541259, 3.972518682479858398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+589, 106787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3283.484619140625, 3856.22216796875, 0.216080635786056518, 5.830033302307128906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+590, 106785, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3295.930908203125, 3840.657958984375, 2.179853677749633789, 2.100641250610351562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+591, 91786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3481.755859375, 3932.99755859375, 0.420325726270675659, 5.44941568374633789, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+592, 91794, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3356.296875, 3877.830078125, 0.325684726238250732, 0.946900546550750732, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!)
(@CGUID+593, 91796, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3438.064453125, 3899.994873046875, 8.846744537353515625, 4.572855949401855468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Wavecrasher (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+594, 106786, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3269.680908203125, 3837.354248046875, 2.388796091079711914, 0.639028668403625488, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+595, 106787, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3283.111328125, 3843.538330078125, 1.305859327316284179, 3.721310138702392578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+596, 106785, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 1, -3271.808349609375, 3844.651123046875, 2.34275984764099121, 6.110020160675048828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Bitterbrine Slave (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1
(@CGUID+597, 95939, 1456, 8040, 8082, '1,2,8,23,24', 0, 0, 0, 0, -3325.989013671875, 3865.130126953125, 0.476971626281738281, 4.058307170867919921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Tidestomper (Area: Shipwreck Shoals - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+598, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3522.821044921875, 3949.680419921875, 8.479575157165527343, 3.260128974914550781, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+599, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3517.59765625, 3948.18798828125, 7.875925540924072265, 0.828828632831573486, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+600, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3520.795654296875, 3942.5595703125, 7.633748054504394531, 6.096562862396240234, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+601, 101414, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3525.993408203125, 3947.665283203125, 8.326935768127441406, 1.516056537628173828, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Skulker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196107 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+602, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3530.322021484375, 3948.958984375, 8.624209403991699218, 2.89471745491027832, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+603, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3524.90478515625, 3944.963623046875, 8.077130317687988281, 2.606201648712158203, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+604, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3520.784423828125, 3934.3857421875, 6.628186225891113281, 4.651798248291015625, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+605, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3524.622802734375, 3940.027587890625, 7.636222362518310546, 0.97575157880783081, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+606, 95939, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3524.142578125, 3913.17529296875, 3.151563167572021484, 4.712474346160888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Tidestomper (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 55701 - Cosmetic - Sleep Zzz Breakable, 18950 - Invisibility and Stealth Detection)
(@CGUID+607, 99908, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3352.5771484375, 3913.442138671875, 5.274806976318359375, 5.678382396697998046, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+608, 91786, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3581.31884765625, 3938.060791015625, 13.12565422058105468, 0.492485791444778442, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Gritslime Snail (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196285 - Mod Scale 85-100%) (possible waypoints or random movement)
(@CGUID+609, 95939, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3260.42041015625, 3770.616455078125, 3.988496065139770507, 3.924815893173217773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Tidestomper (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+610, 91796, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3267.42822265625, 3753.282958984375, 5.747958183288574218, 1.936007261276245117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Skrog Wavecrasher (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+611, 99908, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3505.309814453125, 3956.43994140625, 7.634232521057128906, 5.209241390228271484, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+612, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3600.81689453125, 3905.22509765625, 17.91711044311523437, 5.784617424011230468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+613, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3606.628173828125, 3909.664794921875, 16.2591552734375, 5.845454216003417968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+614, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3607.883056640625, 3899.97119140625, 15.28792762756347656, 2.925996303558349609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+615, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3610.7138671875, 3894.830322265625, 14.2202615737915039, 4.674463272094726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+616, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3605.43408203125, 3903.1025390625, 17.15945243835449218, 0.070681758224964141, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+617, 101414, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3612.544921875, 3900.08203125, 15.07757568359375, 0.49599313735961914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Skulker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196107 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+618, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3620.93994140625, 3894.862548828125, 12.50473403930664062, 1.387720704078674316, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+619, 91794, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3625.091796875, 3903.6796875, 9.41246795654296875, 4.14768218994140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61559), -- Saltscale Lurker (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 196108 - Mrrglrr!) (possible waypoints or random movement)
(@CGUID+620, 99908, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3572.610595703125, 3956.209716796875, 16.69121360778808593, 4.359447002410888671, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559), -- Skittering Softshell (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+621, 99908, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, 0, 0, -3593.646728515625, 3936.426513671875, 14.28423595428466796, 1.755586862564086914, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61559); -- Skittering Softshell (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+621;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 3, ''), -- Hatecoil Warrior
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 3, ''), -- Hatecoil Warrior
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 3, ''), -- Hatecoil Warrior
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 3, ''), -- Hatecoil Warrior
(@CGUID+125, 0, 0, 0, 3, 0, 1, 0, 468, 0, 0, 0, 4, '197868'), -- Lady Hatecoil - 197868 - Arcane Shielding
(@CGUID+131, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 3, '18950'), -- Skrog Wavecrasher - 18950 - Invisibility and Stealth Detection
(@CGUID+134, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+140, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+144, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+145, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+149, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+160, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+225, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+229, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+233, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+236, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+237, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 3, '18950'), -- Skrog Wavecrasher - 18950 - Invisibility and Stealth Detection
(@CGUID+239, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+244, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+249, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 3, '18950'), -- Skrog Tidestomper - 18950 - Invisibility and Stealth Detection
(@CGUID+307, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+310, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 3, '55701'), -- Bitterbrine Scavenger - 55701 - Cosmetic - Sleep Zzz Breakable
(@CGUID+311, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+312, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 3, '55701'), -- Bitterbrine Scavenger - 55701 - Cosmetic - Sleep Zzz Breakable
(@CGUID+313, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+314, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+315, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 3, '55701'), -- Bitterbrine Scavenger - 55701 - Cosmetic - Sleep Zzz Breakable
(@CGUID+316, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 3, '55701'), -- Bitterbrine Scavenger - 55701 - Cosmetic - Sleep Zzz Breakable
(@CGUID+317, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+318, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+320, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 3, '55701'), -- Bitterbrine Scavenger - 55701 - Cosmetic - Sleep Zzz Breakable
(@CGUID+322, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 3, '55701'), -- Bitterbrine Scavenger - 55701 - Cosmetic - Sleep Zzz Breakable
(@CGUID+323, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+324, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+325, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+326, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+327, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+328, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+329, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+331, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+332, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+333, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+334, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+335, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+337, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+338, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+339, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+340, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+341, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+343, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+348, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+349, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+352, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+353, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+354, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+357, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Bitterbrine Scavenger
(@CGUID+462, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- Skrog Wavecrasher - 18950 - Invisibility and Stealth Detection
(@CGUID+466, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+467, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+469, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+471, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+474, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+475, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+476, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+479, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+480, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+481, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+489, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+493, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+547, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+548, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+550, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 3, '18950'), -- Skrog Tidestomper - 18950 - Invisibility and Stealth Detection
(@CGUID+552, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+553, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+555, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+556, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+588, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+589, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+590, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+594, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+595, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+596, 0, 0, 0, 0, 0, 1, 0, 648, 0, 0, 0, 3, ''), -- Bitterbrine Slave
(@CGUID+606, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 3, '55701 18950'); -- Skrog Tidestomper - 55701 - Cosmetic - Sleep Zzz Breakable, 18950 - Invisibility and Stealth Detection

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+27;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 240788, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, -3484.81982421875, 4387.015625, -3.66374969482421875, 0, 0, 0, 0, 1, 7200, 255, 1, 61559), -- Bubble (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@OGUID+1, 246982, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, -3452.142333984375, 4106.525390625, 26.02242660522460937, 1.710421442985534667, 0.002494335174560546, 0.003579139709472656, 0.754700660705566406, 0.656054794788360595, 7200, 255, 0, 61559), -- Water Door (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@OGUID+2, 246983, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, -3401.8056640625, 4143.1396484375, 28.45384025573730468, 0.253071129322052001, 0.004244804382324218, 0.001008987426757812, 0.126194953918457031, 0.991995871067047119, 7200, 255, 0, 61559), -- Water Door (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@OGUID+3, 248930, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, -3534.15625, 4269.91162109375, 0.664044916629791259, 6.045989990234375, 0.14969635009765625, -0.10422420501708984, -0.10237598419189453, 0.977879047393798828, 7200, 255, 1, 61559), -- Crate of Corks (Area: Hatecoil Encampment - Difficulty: Normal) CreateObject1
(@OGUID+4, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3082.303955078125, 3945.57470703125, 43.20197296142578125, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+5, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3079.27783203125, 3946.036376953125, 43.81144332885742187, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+6, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3082.90625, 3941.9453125, 43.01678085327148437, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+7, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3077.989501953125, 3948.81689453125, 45.13946151733398437, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+8, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3081.522705078125, 3943.701416015625, 43.07720565795898437, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+9, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3085.703125, 3944.9453125, 43.16038894653320312, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+10, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3074.677001953125, 3950.2041015625, 45.20882415771484375, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+11, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3082.09716796875, 3942.643310546875, 43.02989578247070312, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+12, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3084.25, 3942.9609375, 43.06989288330078125, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+13, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3075.1494140625, 3951.249267578125, 45.37612152099609375, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+14, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3079.895751953125, 3946.896728515625, 43.88468551635742187, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+15, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3074.310791015625, 3948.907958984375, 45.08861923217773437, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+16, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3085.194580078125, 3942.2421875, 42.99645614624023437, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+17, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3084.388916015625, 3946.173583984375, 43.24829864501953125, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+18, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3083.177001953125, 3946.01123046875, 43.24242019653320312, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+19, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3080.53125, 3947.872314453125, 43.9690093994140625, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+20, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3085.335205078125, 3945.7744140625, 43.20630645751953125, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+21, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3083.944580078125, 3941.869873046875, 43.02843856811523437, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+22, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3074.310791015625, 3947.587646484375, 44.97399520874023437, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+23, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3075.583251953125, 3948.0390625, 45.03176116943359375, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+24, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3076.776123046875, 3948.309814453125, 45.07494735717773437, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+25, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3081.670166015625, 3944.84814453125, 43.14765167236328125, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+26, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3078.74658203125, 3945.193603515625, 43.7419586181640625, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559), -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
(@OGUID+27, 218990, 1456, 8040, 8083, '1,2,8,23,24', 0, 0, -3084.69970703125, 3942.522705078125, 43.05750274658203125, 2.452037811279296875, 0, 0, 0.941150665283203125, 0.337987273931503295, 7200, 255, 1, 61559); -- Sparkle (Area: Deepbeard's Cove - Difficulty: Normal) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+27;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (97844 /*97844 (Call the Seas)*/, 91790 /*91790 (Mak'rana Siltwalker)*/, 91792 /*91792 (Stormwake Hydra) - Vile Blood*/, 97263 /*97263 (Sinkhole)*/, 95947 /*95947 (Mak'rana Hardshell) - Clobbering Claws*/, 99630 /*99630 (Bitterbrine Scavenger)*/, 95940 /*95940 (Bitterbrine Scavenger) - Cosmetic - Sleep Zzz Breakable*/, 99629 /*99629 (Bitterbrine Scavenger)*/, 91793 /*91793 (Seaspray Crab) - Mod Scale 115-120%*/, 95939 /*95939 (Skrog Tidestomper) - Invisibility and Stealth Detection*/, 101414 /*101414 (Saltscale Skulker) - Mrrglrr!*/, 91794 /*91794 (Saltscale Lurker) - Mrrglrr!*/, 91808 /*91808 (Serpentrix)*/, 97170 /*97170 (Hatecoil Wavebinder)*/, 95920 /*95920 (Animated Storm)*/, 106785 /*106785 (Bitterbrine Slave)*/, 106787 /*106787 (Bitterbrine Slave)*/, 97853 /*97853 (Sand Dune) - Sand Dune, Sand Dune*/, 100688 /*100688 (Brightscale Darters) - Mod Scale 115-120%*/, 106786 /*106786 (Bitterbrine Slave)*/, 91796 /*91796 (Skrog Wavecrasher) - Invisibility and Stealth Detection*/, 97063 /*97063 (Weatherman) - Violent Winds*/, 91789 /*91789 (Lady Hatecoil) - Arcane Shielding*/, 100249 /*100249 (Channeler Varisz) - Tempest Attunement*/, 100248 /*100248 (Ritualist Lesha) - Tempest Attunement*/, 100250 /*100250 (Binder Ashioi) - Tempest Attunement*/, 91797 /*91797 (King Deepbeard) - [DNT] Send Event <Points> On Enter Combat*/, 97713 /*97713 (Lightning Stalker) - Lightning Strikes, Lightning Strikes, Lightning Strikes*/, 91784 /*91784 (Warlord Parjesh) - Empty Energy [DNT], [DNT] Send Event <Points> On Enter Combat*/, 97173 /*97173 (Restless Tides)*/, 99901 /*99901 (Cove Seagull)*/, 97171 /*97171 (Hatecoil Arcanist) - Arcane Fortification, Arcane Alignment, Arcane Channeling*/, 98173 /*98173 (Mystic Ssa'veh) - Tempest Attunement*/, 91786 /*91786 (Gritslime Snail) - Mod Scale 85-100%*/, 97172 /*97172 (Saltsea Droplet)*/, 91787 /*91787 (Cove Seagull)*/, 91782 /*91782 (Hatecoil Crusher)*/, 91783 /*91783 (Hatecoil Stormweaver) - Lightning Hands*/, 100216 /*100216 (Hatecoil Wrangler)*/, 99908 /*99908 (Skittering Softshell) - Mod Scale 115-120%*/, 91785 /*91785 (Wandering Shellback) - Mod Scale 85-100%*/, 95861 /*95861 (Hatecoil Oracle)*/, 91781 /*91781 (Hatecoil Warrior)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(97844, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 97844 (Call the Seas)
(91790, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 91790 (Mak'rana Siltwalker)
(91792, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '202314'), -- 91792 (Stormwake Hydra) - Vile Blood
(97263, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 97263 (Sinkhole)
(95947, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196201'), -- 95947 (Mak'rana Hardshell) - Clobbering Claws
(99630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 99630 (Bitterbrine Scavenger)
(95940, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 3, '55701'), -- 95940 (Bitterbrine Scavenger) - Cosmetic - Sleep Zzz Breakable
(99629, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 99629 (Bitterbrine Scavenger)
(91793, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '123168'), -- 91793 (Seaspray Crab) - Mod Scale 115-120%
(95939, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- 95939 (Skrog Tidestomper) - Invisibility and Stealth Detection
(101414, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196107'), -- 101414 (Saltscale Skulker) - Mrrglrr!
(91794, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196108'), -- 91794 (Saltscale Lurker) - Mrrglrr!
(91808, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 91808 (Serpentrix)
(97170, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 97170 (Hatecoil Wavebinder)
(95920, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 95920 (Animated Storm)
(106785, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 106785 (Bitterbrine Slave)
(106787, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 106787 (Bitterbrine Slave)
(97853, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '193060 193064'), -- 97853 (Sand Dune) - Sand Dune, Sand Dune
(100688, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123168'), -- 100688 (Brightscale Darters) - Mod Scale 115-120%
(106786, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 106786 (Bitterbrine Slave)
(91796, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- 91796 (Skrog Wavecrasher) - Invisibility and Stealth Detection
(97063, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 5, '191792'), -- 97063 (Weatherman) - Violent Winds
(91789, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, '197868'), -- 91789 (Lady Hatecoil) - Arcane Shielding
(100249, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '193491'), -- 100249 (Channeler Varisz) - Tempest Attunement
(100248, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '193491'), -- 100248 (Ritualist Lesha) - Tempest Attunement
(100250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '193491'), -- 100250 (Binder Ashioi) - Tempest Attunement
(91797, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '355784'), -- 91797 (King Deepbeard) - [DNT] Send Event <Points> On Enter Combat
(97713, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 5, '192732 192737 192736'), -- 97713 (Lightning Stalker) - Lightning Strikes, Lightning Strikes, Lightning Strikes
(91784, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '202146 355784'), -- 91784 (Warlord Parjesh) - Empty Energy [DNT], [DNT] Send Event <Points> On Enter Combat
(97173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 97173 (Restless Tides)
(99901, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 99901 (Cove Seagull)
(97171, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '199865 197115 161837'), -- 97171 (Hatecoil Arcanist) - Arcane Fortification, Arcane Alignment, Arcane Channeling
(98173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '193491'), -- 98173 (Mystic Ssa'veh) - Tempest Attunement
(91786, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285'), -- 91786 (Gritslime Snail) - Mod Scale 85-100%
(97172, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 97172 (Saltsea Droplet)
(91787, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 91787 (Cove Seagull)
(91782, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 91782 (Hatecoil Crusher)
(91783, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196786'), -- 91783 (Hatecoil Stormweaver) - Lightning Hands
(100216, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 100216 (Hatecoil Wrangler)
(99908, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123168'), -- 99908 (Skittering Softshell) - Mod Scale 115-120%
(91785, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285'), -- 91785 (Wandering Shellback) - Mod Scale 85-100%
(95861, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 95861 (Hatecoil Oracle)
(91781, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 91781 (Hatecoil Warrior)

-- Template
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 97844;
UPDATE `creature_template` SET `unit_flags2`=0x800, `unit_flags3`=0x40000001, `flags_extra` = 128 WHERE `entry`=97263; -- Sinkhole
UPDATE `creature_template` SET `unit_flags2`=0x4000800, `unit_flags3`=0x41000001, `flags_extra` = 128 WHERE `entry`=97853; -- Sand Dune
UPDATE `creature_template` SET `unit_flags2`=0x800, `unit_flags3`=0x41000001, `flags_extra` = 128 WHERE `entry`=97063; -- Weatherman
UPDATE `creature_template` SET `unit_flags2`=0x800, `unit_flags3`=0x41000001, `flags_extra` = 128 WHERE `entry`=97713; -- Lightning Stalker
UPDATE `creature_template` SET `unit_flags3`=0x41000001, `flags_extra` = 128 WHERE `entry`=111639; -- Aluneth

-- Difficulty (Normal)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000000, `VerifiedBuild`=61559 WHERE (`Entry`=97844 AND `DifficultyID`=1); -- 97844 (Call the Seas) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91790 AND `DifficultyID`=1); -- 91790 (Mak'rana Siltwalker) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91792 AND `DifficultyID`=1); -- 91792 (Stormwake Hydra) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=97263 AND `DifficultyID`=1); -- 97263 (Sinkhole) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95947 AND `DifficultyID`=1); -- 95947 (Mak'rana Hardshell) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=99630 AND `DifficultyID`=1); -- 99630 (Bitterbrine Scavenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95940 AND `DifficultyID`=1); -- 95940 (Bitterbrine Scavenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=99629 AND `DifficultyID`=1); -- 99629 (Bitterbrine Scavenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91793 AND `DifficultyID`=1); -- 91793 (Seaspray Crab) - CanSwim
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=61559 WHERE (`DifficultyID`=1 AND `Entry` IN (111221,111374,111936,100688,99908));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `VerifiedBuild`=61559 WHERE (`Entry`=95939 AND `DifficultyID`=1); -- 95939 (Skrog Tidestomper) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=101414 AND `DifficultyID`=1); -- 101414 (Saltscale Skulker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91794 AND `DifficultyID`=1); -- 91794 (Saltscale Lurker) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=91808 AND `DifficultyID`=1); -- 91808 (Serpentrix) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97170 AND `DifficultyID`=1); -- 97170 (Hatecoil Wavebinder) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95920 AND `DifficultyID`=1); -- 95920 (Animated Storm) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=106785 AND `DifficultyID`=1); -- 106785 (Bitterbrine Slave) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=106787 AND `DifficultyID`=1); -- 106787 (Bitterbrine Slave) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000100, `VerifiedBuild`=61559 WHERE (`Entry`=97853 AND `DifficultyID`=1); -- 97853 (Sand Dune) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=106786 AND `DifficultyID`=1); -- 106786 (Bitterbrine Slave) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `VerifiedBuild`=61559 WHERE (`Entry`=91796 AND `DifficultyID`=1); -- 91796 (Skrog Wavecrasher) - 
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=97063 AND `DifficultyID`=1); -- 97063 (Weatherman) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x30000000, `VerifiedBuild`=61559 WHERE (`Entry`=91789 AND `DifficultyID`=1); -- 91789 (Lady Hatecoil) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100249 AND `DifficultyID`=1); -- 100249 (Channeler Varisz) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100248 AND `DifficultyID`=1); -- 100248 (Ritualist Lesha) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100250 AND `DifficultyID`=1); -- 100250 (Binder Ashioi) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91797 AND `DifficultyID`=1); -- 91797 (King Deepbeard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=97713 AND `DifficultyID`=1); -- 97713 (Lightning Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91784 AND `DifficultyID`=1); -- 91784 (Warlord Parjesh) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97173 AND `DifficultyID`=1); -- 97173 (Restless Tides) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=61559 WHERE (`Entry`=99901 AND `DifficultyID`=1); -- 99901 (Cove Seagull) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97171 AND `DifficultyID`=1); -- 97171 (Hatecoil Arcanist) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=98173 AND `DifficultyID`=1); -- 98173 (Mystic Ssa'veh) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91786 AND `DifficultyID`=1); -- 91786 (Gritslime Snail) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97172 AND `DifficultyID`=1); -- 97172 (Saltsea Droplet) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000000, `VerifiedBuild`=61559 WHERE (`Entry`=91787 AND `DifficultyID`=1); -- 91787 (Cove Seagull) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91782 AND `DifficultyID`=1); -- 91782 (Hatecoil Crusher) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=111639 AND `DifficultyID`=1); -- 111639 (Aluneth) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91783 AND `DifficultyID`=1); -- 91783 (Hatecoil Stormweaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100216 AND `DifficultyID`=1); -- 100216 (Hatecoil Wrangler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91785 AND `DifficultyID`=1); -- 91785 (Wandering Shellback) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95861 AND `DifficultyID`=1); -- 95861 (Hatecoil Oracle) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91781 AND `DifficultyID`=1); -- 91781 (Hatecoil Warrior) - CanSwim

-- Difficulty (Heroic)
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=99901 AND `DifficultyID`=2);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(99901, 2, 0, 0, 484, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61559); -- 99901 (Cove Seagull) - CanSwim, Floating

UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `VerifiedBuild`=61559 WHERE (`Entry`=95939 AND `DifficultyID`=2); -- 95939 (Skrog Tidestomper) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x20000000, `VerifiedBuild`=61559 WHERE (`Entry`=97844 AND `DifficultyID`=2); -- 97844 (Call the Seas) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=101414 AND `DifficultyID`=2); -- 101414 (Saltscale Skulker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91794 AND `DifficultyID`=2); -- 91794 (Saltscale Lurker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91790 AND `DifficultyID`=2); -- 91790 (Mak'rana Siltwalker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91792 AND `DifficultyID`=2); -- 91792 (Stormwake Hydra) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=97263 AND `DifficultyID`=2); -- 97263 (Sinkhole) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=61559 WHERE (`DifficultyID`=2 AND `Entry` IN (111374,111936,111221,100688,111639,99908));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95947 AND `DifficultyID`=2); -- 95947 (Mak'rana Hardshell) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=99629 AND `DifficultyID`=2); -- 99629 (Bitterbrine Scavenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=99630 AND `DifficultyID`=2); -- 99630 (Bitterbrine Scavenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95940 AND `DifficultyID`=2); -- 95940 (Bitterbrine Scavenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91793 AND `DifficultyID`=2); -- 91793 (Seaspray Crab) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=91808 AND `DifficultyID`=2); -- 91808 (Serpentrix) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=106787 AND `DifficultyID`=2); -- 106787 (Bitterbrine Slave) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97170 AND `DifficultyID`=2); -- 97170 (Hatecoil Wavebinder) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=106785 AND `DifficultyID`=2); -- 106785 (Bitterbrine Slave) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95920 AND `DifficultyID`=2); -- 95920 (Animated Storm) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61559 WHERE (`Entry`=97853 AND `DifficultyID`=2); -- 97853 (Sand Dune) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=106786 AND `DifficultyID`=2); -- 106786 (Bitterbrine Slave) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `VerifiedBuild`=61559 WHERE (`Entry`=91796 AND `DifficultyID`=2); -- 91796 (Skrog Wavecrasher) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91797 AND `DifficultyID`=2); -- 91797 (King Deepbeard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=97063 AND `DifficultyID`=2); -- 97063 (Weatherman) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=97713 AND `DifficultyID`=2); -- 97713 (Lightning Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100249 AND `DifficultyID`=2); -- 100249 (Channeler Varisz) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100248 AND `DifficultyID`=2); -- 100248 (Ritualist Lesha) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100250 AND `DifficultyID`=2); -- 100250 (Binder Ashioi) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x30000000, `VerifiedBuild`=61559 WHERE (`Entry`=91789 AND `DifficultyID`=2); -- 91789 (Lady Hatecoil) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97173 AND `DifficultyID`=2); -- 97173 (Restless Tides) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=98173 AND `DifficultyID`=2); -- 98173 (Mystic Ssa'veh) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97171 AND `DifficultyID`=2); -- 97171 (Hatecoil Arcanist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91786 AND `DifficultyID`=2); -- 91786 (Gritslime Snail) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000000, `VerifiedBuild`=61559 WHERE (`Entry`=91787 AND `DifficultyID`=2); -- 91787 (Cove Seagull) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91784 AND `DifficultyID`=2); -- 91784 (Warlord Parjesh) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97172 AND `DifficultyID`=2); -- 97172 (Saltsea Droplet) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91782 AND `DifficultyID`=2); -- 91782 (Hatecoil Crusher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95861 AND `DifficultyID`=2); -- 95861 (Hatecoil Oracle) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91781 AND `DifficultyID`=2); -- 91781 (Hatecoil Warrior) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91783 AND `DifficultyID`=2); -- 91783 (Hatecoil Stormweaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91785 AND `DifficultyID`=2); -- 91785 (Wandering Shellback) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100216 AND `DifficultyID`=2); -- 100216 (Hatecoil Wrangler) - CanSwim

-- Difficulty (Mythic)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=101414 AND `DifficultyID`=23); -- 101414 (Saltscale Skulker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91794 AND `DifficultyID`=23); -- 91794 (Saltscale Lurker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=61559 WHERE (`Entry`=95939 AND `DifficultyID`=23); -- 95939 (Skrog Tidestomper) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x20000000, `VerifiedBuild`=61559 WHERE (`Entry`=97844 AND `DifficultyID`=23); -- 97844 (Call the Seas) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91790 AND `DifficultyID`=23); -- 91790 (Mak'rana Siltwalker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91792 AND `DifficultyID`=23); -- 91792 (Stormwake Hydra) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=97263 AND `DifficultyID`=23); -- 97263 (Sinkhole) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=61559 WHERE (`DifficultyID`=23 AND `Entry` IN (111374,111936,111221,100688,111639,120652,99908));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95947 AND `DifficultyID`=23); -- 95947 (Mak'rana Hardshell) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95940 AND `DifficultyID`=23); -- 95940 (Bitterbrine Scavenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=99630 AND `DifficultyID`=23); -- 99630 (Bitterbrine Scavenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=99629 AND `DifficultyID`=23); -- 99629 (Bitterbrine Scavenger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91793 AND `DifficultyID`=23); -- 91793 (Seaspray Crab) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=91808 AND `DifficultyID`=23); -- 91808 (Serpentrix) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=106785 AND `DifficultyID`=23); -- 106785 (Bitterbrine Slave) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=106787 AND `DifficultyID`=23); -- 106787 (Bitterbrine Slave) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97170 AND `DifficultyID`=23); -- 97170 (Hatecoil Wavebinder) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95920 AND `DifficultyID`=23); -- 95920 (Animated Storm) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61559 WHERE (`Entry`=97853 AND `DifficultyID`=23); -- 97853 (Sand Dune) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=106786 AND `DifficultyID`=23); -- 106786 (Bitterbrine Slave) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=61559 WHERE (`Entry`=91796 AND `DifficultyID`=23); -- 91796 (Skrog Wavecrasher) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91797 AND `DifficultyID`=23); -- 91797 (King Deepbeard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100249 AND `DifficultyID`=23); -- 100249 (Channeler Varisz) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100248 AND `DifficultyID`=23); -- 100248 (Ritualist Lesha) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=97063 AND `DifficultyID`=23); -- 97063 (Weatherman) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100250 AND `DifficultyID`=23); -- 100250 (Binder Ashioi) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61559 WHERE (`Entry`=97713 AND `DifficultyID`=23); -- 97713 (Lightning Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=61559 WHERE (`Entry`=91789 AND `DifficultyID`=23); -- 91789 (Lady Hatecoil) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97173 AND `DifficultyID`=23); -- 97173 (Restless Tides) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=98173 AND `DifficultyID`=23); -- 98173 (Mystic Ssa'veh) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=61559 WHERE (`Entry`=99901 AND `DifficultyID`=23); -- 99901 (Cove Seagull) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97171 AND `DifficultyID`=23); -- 97171 (Hatecoil Arcanist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91786 AND `DifficultyID`=23); -- 91786 (Gritslime Snail) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=61559 WHERE (`Entry`=91787 AND `DifficultyID`=23); -- 91787 (Cove Seagull) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=97172 AND `DifficultyID`=23); -- 97172 (Saltsea Droplet) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91784 AND `DifficultyID`=23); -- 91784 (Warlord Parjesh) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91782 AND `DifficultyID`=23); -- 91782 (Hatecoil Crusher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=95861 AND `DifficultyID`=23); -- 95861 (Hatecoil Oracle) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91783 AND `DifficultyID`=23); -- 91783 (Hatecoil Stormweaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=100216 AND `DifficultyID`=23); -- 100216 (Hatecoil Wrangler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91781 AND `DifficultyID`=23); -- 91781 (Hatecoil Warrior) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61559 WHERE (`Entry`=91785 AND `DifficultyID`=23); -- 91785 (Wandering Shellback) - CanSwim

-- Model 
UPDATE `creature_model_info` SET `VerifiedBuild`=61559 WHERE `DisplayID` IN (61620, 55460, 42978, 67001, 66820, 1995, 1763, 664, 65110, 5561, 66508, 66509, 31183, 4878, 66510, 66819, 66397, 67254, 11686, 65114, 36212, 51409, 51219, 25675, 39490, 66813, 32063, 69708, 45060, 18393, 45568, 51124, 66499);
UPDATE `creature_model_info` SET `BoundingRadius`=3.612187385559082031, `VerifiedBuild`=61559 WHERE `DisplayID`=66063;
UPDATE `creature_model_info` SET `BoundingRadius`=1.675587058067321777, `VerifiedBuild`=61559 WHERE `DisplayID` IN (19365, 66153);
UPDATE `creature_model_info` SET `BoundingRadius`=3.449738025665283203, `VerifiedBuild`=61559 WHERE `DisplayID` IN (66535, 66534, 66536, 29934);
UPDATE `creature_model_info` SET `BoundingRadius`=2.956918239593505859, `VerifiedBuild`=61559 WHERE `DisplayID`=66163;
UPDATE `creature_model_info` SET `BoundingRadius`=1.774150967597961425, `VerifiedBuild`=61559 WHERE `DisplayID`=66152;

-- Template Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (91793,91794,101414);
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(91793, NULL, 0, 2, NULL),
(91794, NULL, 0, 2, NULL),
(101414, NULL, 0, 2, NULL);

-- Path for Hatecoil Crusher
SET @MOVERGUID := @CGUID+106;
SET @ENTRY := 91782;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Hatecoil Crusher - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3773.0051, 4408.4253, 44.4307, NULL, 0),
(@PATH, 1, -3773.3628, 4392.0815, 43.531723, NULL, 0),
(@PATH, 2, -3769.5747, 4365.0728, 39.984844, NULL, 0),
(@PATH, 3, -3771.5312, 4348.69, 36.14402, NULL, 0),
(@PATH, 4, -3772.0383, 4325.191, 30.902063, NULL, 0),
(@PATH, 5, -3771.5312, 4348.69, 36.14402, NULL, 0),
(@PATH, 6, -3769.5747, 4365.0728, 39.984844, NULL, 0),
(@PATH, 7, -3773.3628, 4392.0815, 43.531723, NULL, 0);

UPDATE `creature` SET `position_x`=-3773.0051, `position_y`=4408.4253, `position_z`=44.4307, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Hatecoil Crusher
SET @MOVERGUID := @CGUID+44;
SET @ENTRY := 91782;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Hatecoil Crusher - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3749.7727, 4534.186, 42.425285, NULL, 0),
(@PATH, 1, -3749.9966, 4522.347, 42.72033, NULL, 0),
(@PATH, 2, -3749.1597, 4513.6704, 42.853992, NULL, 10808),
(@PATH, 3, -3749.9966, 4522.347, 42.72033, NULL, 0),
(@PATH, 4, -3749.7727, 4534.186, 42.425285, NULL, 0),
(@PATH, 5, -3750.3994, 4549.0537, 42.18789, NULL, 10941);

UPDATE `creature` SET `position_x`=-3749.7727, `position_y`=4534.186, `position_z`=42.425285, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Hatecoil Arcanist
SET @MOVERGUID := @CGUID+113;
SET @ENTRY := 97171;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Hatecoil Arcanist - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3631.184, 4649.432, 10.002867, NULL, 0),
(@PATH, 1, -3636.337, 4634.2935, 10.435562, NULL, 0),
(@PATH, 2, -3654.9463, 4624.1973, 16.207378, NULL, 0),
(@PATH, 3, -3669.019, 4618.1895, 21.288733, NULL, 0),
(@PATH, 4, -3686.632, 4616.69, 26.144176, NULL, 0),
(@PATH, 5, -3695.8733, 4609.3003, 29.535606, NULL, 0),
(@PATH, 6, -3707.4932, 4607.405, 34.52856, NULL, 0),
(@PATH, 7, -3715.375, 4610.309, 36.129333, NULL, 0),
(@PATH, 8, -3727.2432, 4610.663, 38.15661, NULL, 0),
(@PATH, 9, -3736, 4605.501, 39.762924, NULL, 0),
(@PATH, 10, -3727.3867, 4610.579, 38.16496, NULL, 0),
(@PATH, 11, -3715.375, 4610.309, 36.129333, NULL, 0),
(@PATH, 12, -3707.4932, 4607.405, 34.52856, NULL, 0),
(@PATH, 13, -3695.8733, 4609.3003, 29.535606, NULL, 0),
(@PATH, 14, -3686.666, 4616.6904, 26.171122, NULL, 0),
(@PATH, 15, -3669.019, 4618.1895, 21.288733, NULL, 0),
(@PATH, 16, -3654.9463, 4624.1973, 16.207378, NULL, 0),
(@PATH, 17, -3636.337, 4634.2935, 10.435562, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 4, '199865 197115 161837');

-- Path for Hatecoil Arcanist
SET @MOVERGUID := @CGUID+121;
SET @ENTRY := 97171;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Hatecoil Arcanist - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3385.125, 4674.811, 1.8439277, NULL, 0),
(@PATH, 1, -3372.5747, 4663.6597, 1.3583565, NULL, 0),
(@PATH, 2, -3367.1338, 4652.6865, 0.46096492, NULL, 0),
(@PATH, 3, -3358.2136, 4634.5254, 0.45194158, NULL, 0),
(@PATH, 4, -3338.0105, 4631.4062, -0.5661626, NULL, 0),
(@PATH, 5, -3358.2136, 4634.5254, 0.45194158, NULL, 0),
(@PATH, 6, -3367.1338, 4652.6865, 0.46096492, NULL, 0),
(@PATH, 7, -3372.5747, 4663.6597, 1.3583565, NULL, 0),
(@PATH, 8, -3385.125, 4674.811, 1.8439277, NULL, 0),
(@PATH, 9, -3399.2292, 4683.663, 3.6555152, NULL, 0),
(@PATH, 10, -3410.6543, 4689.884, 4.451671, NULL, 0),
(@PATH, 11, -3399.2292, 4683.663, 3.6555152, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 4, '199865 197115 161837');

-- Path for Stormwake Hydra
SET @MOVERGUID := @CGUID+351;
SET @ENTRY := 91792;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Stormwake Hydra - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3248.08, 4518.386, 1.0152581, NULL, 0),
(@PATH, 1, -3284.1687, 4536.973, 1.0152994, NULL, 0),
(@PATH, 2, -3303.6235, 4538.9707, 0.96938133, NULL, 0),
(@PATH, 3, -3314.7468, 4523.1953, 0.9885518, NULL, 0),
(@PATH, 4, -3315.8328, 4498.27, 0.97704184, NULL, 0),
(@PATH, 5, -3283.9622, 4486.1514, 1.0156323, NULL, 0),
(@PATH, 6, -3270.3406, 4458.5938, 1.0152735, NULL, 0),
(@PATH, 7, -3248.3206, 4453.6514, 1.0231068, NULL, 0),
(@PATH, 8, -3225.402, 4454.713, 1.0790936, NULL, 0),
(@PATH, 9, -3220.2625, 4482.842, 1.0160979, NULL, 0),
(@PATH, 10, -3234.0247, 4506.125, 1.0152636, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '202314');

-- Path for Stormwake Hydra
SET @MOVERGUID := @CGUID+367;
SET @ENTRY := 91792;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Stormwake Hydra - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3230.779, 4387.777, 1.0827532, NULL, 0),
(@PATH, 1, -3228.6296, 4375.163, 1.0556632, NULL, 0),
(@PATH, 2, -3227.4683, 4360.6035, 1.0292447, NULL, 0),
(@PATH, 3, -3240.101, 4354.153, 1.0440806, NULL, 0),
(@PATH, 4, -3251.1877, 4342.742, 3.2445414, NULL, 0),
(@PATH, 5, -3253.976, 4331.749, 2.9679036, NULL, 0),
(@PATH, 6, -3254.6714, 4320.2847, 2.9244716, NULL, 0),
(@PATH, 7, -3259.7556, 4316.4043, 1.5764251, NULL, 0),
(@PATH, 8, -3274.5576, 4320.126, 1.0189375, NULL, 0),
(@PATH, 9, -3289.884, 4340.409, 2.171223, NULL, 0),
(@PATH, 10, -3283.825, 4379.4395, 1.0472533, NULL, 0),
(@PATH, 11, -3272.4768, 4393.009, 1.0398698, NULL, 0),
(@PATH, 12, -3260.0073, 4398.8184, 1.7005529, NULL, 0),
(@PATH, 13, -3241.6062, 4398.927, 1.5015247, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '202314');

-- Path for Stormwake Hydra
SET @MOVERGUID := @CGUID+407;
SET @ENTRY := 91792;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Stormwake Hydra - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3112.1528, 4428.942, 7.5969186, NULL, 0),
(@PATH, 1, -3112.0955, 4412.3613, 9.04333, NULL, 0),
(@PATH, 2, -3124.9739, 4401.171, 7.629993, NULL, 0),
(@PATH, 3, -3138.4324, 4382.2754, 4.522406, NULL, 0),
(@PATH, 4, -3127.8184, 4366.5225, 8.6894865, NULL, 0),
(@PATH, 5, -3114.4966, 4344.508, 7.945648, NULL, 10325),
(@PATH, 6, -3127.7952, 4366.4956, 8.672966, NULL, 0),
(@PATH, 7, -3138.4324, 4382.2754, 4.522406, NULL, 0),
(@PATH, 8, -3124.9739, 4401.171, 7.629993, NULL, 0),
(@PATH, 9, -3112.0955, 4412.3613, 9.04333, NULL, 0),
(@PATH, 10, -3112.1528, 4428.942, 7.5969186, NULL, 0),
(@PATH, 11, -3097.7327, 4447.5034, 3.8497558, NULL, 0),
(@PATH, 12, -3084.5798, 4457.283, 4.537353, NULL, 0),
(@PATH, 13, -3068.7258, 4463.233, 5.725063, NULL, 0),
(@PATH, 14, -3056.4688, 4469.7954, 6.280521, NULL, 0),
(@PATH, 15, -3044.9966, 4483.501, 5.820753, NULL, 10618),
(@PATH, 16, -3056.4688, 4469.7954, 6.280521, NULL, 0),
(@PATH, 17, -3068.7258, 4463.233, 5.725063, NULL, 0),
(@PATH, 18, -3084.5798, 4457.283, 4.537353, NULL, 0),
(@PATH, 19, -3097.7327, 4447.5034, 3.8497558, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '202314');

-- Path for Seaspray Crab
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+356;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+356, @CGUID+356, 0, 0, 515, 0, 0),
(@CGUID+356, @CGUID+360, 6, 0, 515, 0, 0),
(@CGUID+356, @CGUID+359, 4, 30, 515, 0, 0),
(@CGUID+356, @CGUID+362, 4, 330, 515, 0, 0);

SET @MOVERGUID := @CGUID+356;
SET @ENTRY := 91793;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Seaspray Crab - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3207.9011, 4463.3706, 1.0902265, NULL, 0),
(@PATH, 1, -3213.6753, 4453.174, 1.1081592, NULL, 0),
(@PATH, 2, -3221.3542, 4442.936, 1.0651999, NULL, 0),
(@PATH, 3, -3234.2205, 4438.1084, 1.6149426, NULL, 0),
(@PATH, 4, -3252.1545, 4447.288, 2.8221204, NULL, 0),
(@PATH, 5, -3262.007, 4452.0254, 0.99442744, NULL, 0),
(@PATH, 6, -3275.7136, 4443.9443, 2.1159334, NULL, 0),
(@PATH, 7, -3290.1948, 4431.7812, 1.4219835, NULL, 0),
(@PATH, 8, -3287.7932, 4417.347, 1.5056318, NULL, 0),
(@PATH, 9, -3290.1948, 4431.7812, 1.4219835, NULL, 0),
(@PATH, 10, -3275.7136, 4443.9443, 2.1159334, NULL, 0),
(@PATH, 11, -3262.007, 4452.0254, 0.99442744, NULL, 0),
(@PATH, 12, -3252.1545, 4447.288, 2.8221204, NULL, 0),
(@PATH, 13, -3234.3418, 4438.167, 1.6920266, NULL, 0),
(@PATH, 14, -3221.3542, 4442.936, 1.0651999, NULL, 0),
(@PATH, 15, -3213.6753, 4453.174, 1.1081592, NULL, 0),
(@PATH, 16, -3207.9011, 4463.3706, 1.0902265, NULL, 0),
(@PATH, 17, -3212.634, 4477.0605, 1.0152588, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '123168');

-- Path for Saltscale Lurker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+512;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+512, @CGUID+512, 0, 0, 515, 0, 0),
(@CGUID+512, @CGUID+444, 4, 330, 515, 0, 0),
(@CGUID+512, @CGUID+443, 4, 30, 515, 0, 0);

SET @MOVERGUID := @CGUID+512;
SET @ENTRY := 91794;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Saltscale Lurker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3206.8057, 4139.7466, 5.2086444, NULL, 0),
(@PATH, 1, -3236.0955, 4117.5635, 4.6388097, NULL, 0),
(@PATH, 2, -3264.6892, 4101.0537, 4.0427136, NULL, 0),
(@PATH, 3, -3281.191, 4079.1165, 3.1527815, NULL, 0),
(@PATH, 4, -3274.5383, 4051.9062, 3.8336887, NULL, 0),
(@PATH, 5, -3256.4531, 4031.9307, 7.1045146, NULL, 0),
(@PATH, 6, -3257.0764, 4011.3125, 8.792908, NULL, 0),
(@PATH, 7, -3266.1528, 3981.4739, 5.0605707, NULL, 0),
(@PATH, 8, -3259.8142, 3949.5173, 2.2332187, NULL, 0),
(@PATH, 9, -3266.1528, 3981.4739, 5.0605707, NULL, 0),
(@PATH, 10, -3257.0764, 4011.3125, 8.792908, NULL, 0),
(@PATH, 11, -3256.457, 4031.7976, 7.0678105, NULL, 0),
(@PATH, 12, -3274.5383, 4051.9062, 3.8336887, NULL, 0),
(@PATH, 13, -3281.191, 4079.1165, 3.1527815, NULL, 0),
(@PATH, 14, -3236.0955, 4117.5635, 4.6388097, NULL, 0),
(@PATH, 15, -3206.8057, 4139.7466, 5.2086444, NULL, 0),
(@PATH, 16, -3212.1284, 4206.729, 7.658963, NULL, 0),
(@PATH, 17, -3197.382, 4223.8506, 7.7251954, NULL, 0),
(@PATH, 18, -3187.4844, 4245.8516, 5.6701665, NULL, 0),
(@PATH, 19, -3197.382, 4223.8506, 7.7251954, NULL, 0),
(@PATH, 20, -3212.1284, 4206.729, 7.658963, NULL, 0),
(@PATH, 21, -3213.0486, 4178.193, 6.8879733, NULL, 0);

UPDATE `creature` SET `position_x`=-3206.8057, `position_y`=4139.7466, `position_z`=5.2086444 WHERE `guid` IN (@CGUID+444, @CGUID+443);
UPDATE `creature` SET `position_x`=-3206.8057, `position_y`=4139.7466, `position_z`=5.2086444, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '196108');

-- Path for Saltscale Lurker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+203;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+203, @CGUID+203, 0, 0, 515, 0, 0),
(@CGUID+203, @CGUID+207, 4, 0, 515, 0, 0),
(@CGUID+203, @CGUID+201, 4, 0, 515, 0, 0),
(@CGUID+203, @CGUID+189, 4, 0, 515, 0, 0),
(@CGUID+203, @CGUID+204, 4, 0, 515, 0, 0),
(@CGUID+203, @CGUID+206, 4, 0, 515, 0, 0),
(@CGUID+203, @CGUID+210, 4, 0, 515, 0, 0),
(@CGUID+203, @CGUID+202, 4, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+203;
SET @ENTRY := 91794;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Saltscale Lurker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3624.2554, 4045.1648, 27.595533, NULL, 0),
(@PATH, 1, -3633.528, 4054.077, 28.686546, NULL, 0),
(@PATH, 2, -3643.3428, 4060.3982, 26.481426, NULL, 0),
(@PATH, 3, -3651.3042, 4067.218, 25.833073, NULL, 0),
(@PATH, 4, -3655.9456, 4078.4402, 26.049515, NULL, 0),
(@PATH, 5, -3660.4468, 4089.324, 25.580883, NULL, 0),
(@PATH, 6, -3663.2449, 4098.6343, 25.548527, NULL, 0),
(@PATH, 7, -3659.5415, 4110.495, 26.100882, NULL, 0),
(@PATH, 8, -3655.9375, 4122.038, 26.049107, NULL, 0),
(@PATH, 9, -3652.132, 4133.007, 25.165888, NULL, 0),
(@PATH, 10, -3647.7847, 4144.1855, 23.900114, NULL, 0),
(@PATH, 11, -3653.7637, 4155.6904, 23.277264, NULL, 0),
(@PATH, 12, -3663.677, 4163.1147, 24.172474, NULL, 0),
(@PATH, 13, -3675.3064, 4167.055, 24.222462, NULL, 0),
(@PATH, 14, -3685.0776, 4171.932, 24.845114, NULL, 0),
(@PATH, 15, -3686.2986, 4173.3633, 25.172, NULL, 0),
(@PATH, 16, -3688.2515, 4174.659, 25.291641, NULL, 0),
(@PATH, 17, -3688.7954, 4175.02, 25.36094, NULL, 0),
(@PATH, 18, -3689.784, 4175.6763, 25.661293, NULL, 0),
(@PATH, 19, -3690.059, 4175.859, 25.667181, NULL, 0),
(@PATH, 20, -3692.4058, 4177.416, 25.716728, NULL, 0),
(@PATH, 21, -3693.2905, 4178.0034, 25.66482, NULL, 0),
(@PATH, 22, -3693.2905, 4178.0034, 25.66482, NULL, 0),
(@PATH, 23, -3683.3547, 4170.658, 24.620867, NULL, 0),
(@PATH, 24, -3677.111, 4167.6665, 24.282085, NULL, 0),
(@PATH, 25, -3665.3792, 4163.6914, 24.180265, NULL, 0),
(@PATH, 26, -3655.2014, 4156.9043, 23.611565, NULL, 0),
(@PATH, 27, -3647.1152, 4145.9067, 23.905575, NULL, 0),
(@PATH, 28, -3651.4656, 4134.7207, 24.773733, NULL, 0),
(@PATH, 29, -3655.4814, 4123.471, 25.994722, NULL, 0),
(@PATH, 30, -3659.0635, 4112.0107, 26.173244, NULL, 0),
(@PATH, 31, -3662.6785, 4100.4443, 25.330587, NULL, 0),
(@PATH, 32, -3661.201, 4091.1484, 25.439795, NULL, 0),
(@PATH, 33, -3656.5596, 4079.9255, 26.049515, NULL, 0),
(@PATH, 34, -3651.8235, 4068.473, 25.733232, NULL, 0),
(@PATH, 35, -3646.6106, 4063.7454, 26.053871, NULL, 0),
(@PATH, 36, -3645.1204, 4061.798, 26.37152, NULL, 0),
(@PATH, 37, -3634.9753, 4055.0388, 28.224815, NULL, 0);

UPDATE `creature` SET `position_x`=-3624.2554, `position_y`=4045.1648, `position_z`=27.595533 WHERE `guid` IN (@CGUID+207, @CGUID+201, @CGUID+189, @CGUID+204, @CGUID+206, @CGUID+210, @CGUID+202);
UPDATE `creature` SET `position_x`=-3624.2554, `position_y`=4045.1648, `position_z`=27.595533, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '196108');

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+65;
SET @ENTRY := 91787;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6706, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3808.7407, 4257.115, 70.7388, NULL, 0),
(@PATH, 1, -3820.16, 4272.933, 70.7388, NULL, 0),
(@PATH, 2, -3824.657, 4291.917, 70.7388, NULL, 0),
(@PATH, 3, -3821.5466, 4311.1763, 70.7388, NULL, 0),
(@PATH, 4, -3811.303, 4327.78, 70.7388, NULL, 0),
(@PATH, 5, -3795.485, 4339.1987, 70.7388, NULL, 0),
(@PATH, 6, -3776.5015, 4343.696, 70.7388, NULL, 0),
(@PATH, 7, -3757.242, 4340.5854, 70.7388, NULL, 0),
(@PATH, 8, -3740.6387, 4330.342, 70.7388, NULL, 0),
(@PATH, 9, -3729.2195, 4314.524, 70.7388, NULL, 0),
(@PATH, 10, -3724.7227, 4295.5405, 70.7388, NULL, 0),
(@PATH, 11, -3727.8328, 4276.281, 70.7388, NULL, 0),
(@PATH, 12, -3738.0764, 4259.6777, 70.7388, NULL, 0),
(@PATH, 13, -3753.8943, 4248.2583, 70.7388, NULL, 0),
(@PATH, 14, -3772.878, 4243.761, 70.7388, NULL, 0),
(@PATH, 15, -3792.1375, 4246.8716, 70.7388, NULL, 0),
(@PATH, 16, -3808.7407, 4257.115, 70.7388, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+115;
SET @ENTRY := 91787;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6706, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3642.092, 4643.2466, 36.388958, NULL, 0),
(@PATH, 1, -3631.2534, 4659.468, 36.388958, NULL, 0),
(@PATH, 2, -3615.0322, 4670.306, 36.388958, NULL, 0),
(@PATH, 3, -3595.898, 4674.1123, 36.388958, NULL, 0),
(@PATH, 4, -3576.7637, 4670.306, 36.388958, NULL, 0),
(@PATH, 5, -3560.5427, 4659.468, 36.388958, NULL, 0),
(@PATH, 6, -3549.704, 4643.2466, 36.388958, NULL, 0),
(@PATH, 7, -3545.898, 4624.1123, 36.388958, NULL, 0),
(@PATH, 8, -3549.7039, 4604.978, 36.388958, NULL, 0),
(@PATH, 9, -3560.5425, 4588.757, 36.388958, NULL, 0),
(@PATH, 10, -3576.7637, 4577.9185, 36.388958, NULL, 0),
(@PATH, 11, -3595.898, 4574.1123, 36.388958, NULL, 0),
(@PATH, 12, -3615.0322, 4577.9185, 36.388958, NULL, 0),
(@PATH, 13, -3631.2532, 4588.757, 36.388958, NULL, 0),
(@PATH, 14, -3642.092, 4604.978, 36.388958, NULL, 0),
(@PATH, 15, -3645.898, 4624.1123, 36.388958, NULL, 0),
(@PATH, 16, -3642.092, 4643.2466, 36.388958, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+255;
SET @ENTRY := 91787;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6706, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3573.3853, 4690.441, 26.4917, NULL, 0),
(@PATH, 1, -3562.5464, 4706.662, 26.4917, NULL, 0),
(@PATH, 2, -3546.3254, 4717.5005, 26.4917, NULL, 0),
(@PATH, 3, -3527.1912, 4721.3066, 26.4917, NULL, 0),
(@PATH, 4, -3508.057, 4717.5005, 26.4917, NULL, 0),
(@PATH, 5, -3491.836, 4706.662, 26.4917, NULL, 0),
(@PATH, 6, -3480.997, 4690.441, 26.4917, NULL, 0),
(@PATH, 7, -3477.1912, 4671.3066, 26.4917, NULL, 0),
(@PATH, 8, -3480.997, 4652.1724, 26.4917, NULL, 0),
(@PATH, 9, -3491.836, 4635.951, 26.4917, NULL, 0),
(@PATH, 10, -3508.057, 4625.113, 26.4917, NULL, 0),
(@PATH, 11, -3527.1912, 4621.3066, 26.4917, NULL, 0),
(@PATH, 12, -3546.3254, 4625.113, 26.4917, NULL, 0),
(@PATH, 13, -3562.5464, 4635.951, 26.4917, NULL, 0),
(@PATH, 14, -3573.3853, 4652.1724, 26.4917, NULL, 0),
(@PATH, 15, -3577.1912, 4671.3066, 26.4917, NULL, 0),
(@PATH, 16, -3573.3853, 4690.441, 26.4917, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+223;
SET @ENTRY := 91787;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6706, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3374.7961, 4155.328, 62.04017, NULL, 0),
(@PATH, 1, -3373.1506, 4135.8887, 62.04017, NULL, 0),
(@PATH, 2, -3379.0696, 4117.2993, 62.04017, NULL, 0),
(@PATH, 3, -3391.6519, 4102.3896, 62.04017, NULL, 0),
(@PATH, 4, -3408.982, 4093.4304, 62.04017, NULL, 0),
(@PATH, 5, -3428.4214, 4091.785, 62.04017, NULL, 0),
(@PATH, 6, -3447.011, 4097.7036, 62.04017, NULL, 0),
(@PATH, 7, -3461.9202, 4110.286, 62.04017, NULL, 0),
(@PATH, 8, -3470.8796, 4127.616, 62.04017, NULL, 0),
(@PATH, 9, -3472.5251, 4147.0557, 62.04017, NULL, 0),
(@PATH, 10, -3466.6062, 4165.645, 62.04017, NULL, 0),
(@PATH, 11, -3454.024, 4180.554, 62.04017, NULL, 0),
(@PATH, 12, -3436.6938, 4189.5137, 62.04017, NULL, 0),
(@PATH, 13, -3417.2544, 4191.159, 62.04017, NULL, 0),
(@PATH, 14, -3398.665, 4185.24, 62.04017, NULL, 0),
(@PATH, 15, -3383.7556, 4172.658, 62.04017, NULL, 0),
(@PATH, 16, -3374.7961, 4155.328, 62.04017, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+227;
SET @ENTRY := 91787;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6706, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3448.8132, 4133.501, 49.155796, NULL, 0),
(@PATH, 1, -3429.3325, 4132.448, 49.155796, NULL, 0),
(@PATH, 2, -3411.7378, 4124.0205, 49.155796, NULL, 0),
(@PATH, 3, -3398.7075, 4109.501, 49.155796, NULL, 0),
(@PATH, 4, -3392.2253, 4091.1006, 49.155796, NULL, 0),
(@PATH, 5, -3393.2783, 4071.6199, 49.155796, NULL, 0),
(@PATH, 6, -3401.706, 4054.0251, 49.155796, NULL, 0),
(@PATH, 7, -3416.2253, 4040.9949, 49.155796, NULL, 0),
(@PATH, 8, -3434.626, 4034.5127, 49.155796, NULL, 0),
(@PATH, 9, -3454.1067, 4035.5657, 49.155796, NULL, 0),
(@PATH, 10, -3471.7014, 4043.9932, 49.155796, NULL, 0),
(@PATH, 11, -3484.7317, 4058.5127, 49.155796, NULL, 0),
(@PATH, 12, -3491.2139, 4076.9133, 49.155796, NULL, 0),
(@PATH, 13, -3490.161, 4096.394, 49.155796, NULL, 0),
(@PATH, 14, -3481.7332, 4113.989, 49.155796, NULL, 0),
(@PATH, 15, -3467.2139, 4127.019, 49.155796, NULL, 0),
(@PATH, 16, -3448.8132, 4133.501, 49.155796, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+234;
SET @ENTRY := 91787;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6706, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3521.7188, 4006.5972, 56.572712, NULL, 0),
(@PATH, 1, -3506.9216, 3993.883, 56.572712, NULL, 0),
(@PATH, 2, -3498.1162, 3976.474, 56.572712, NULL, 0),
(@PATH, 3, -3496.6433, 3957.0208, 56.572712, NULL, 0),
(@PATH, 4, -3502.7268, 3938.4846, 56.572712, NULL, 0),
(@PATH, 5, -3515.441, 3923.6875, 56.572712, NULL, 0),
(@PATH, 6, -3532.8499, 3914.882, 56.572712, NULL, 0),
(@PATH, 7, -3552.3032, 3913.4092, 56.572712, NULL, 0),
(@PATH, 8, -3570.8394, 3919.4927, 56.572712, NULL, 0),
(@PATH, 9, -3585.6365, 3932.2068, 56.572712, NULL, 0),
(@PATH, 10, -3594.442, 3949.6155, 56.572712, NULL, 0),
(@PATH, 11, -3595.9148, 3969.0688, 56.572712, NULL, 0),
(@PATH, 12, -3589.8313, 3987.6052, 56.572712, NULL, 0),
(@PATH, 13, -3577.1172, 4002.4023, 56.572712, NULL, 0),
(@PATH, 14, -3559.7085, 4011.2078, 56.572712, NULL, 0),
(@PATH, 15, -3540.2551, 4012.6807, 56.572712, NULL, 0),
(@PATH, 16, -3521.7188, 4006.5972, 56.572712, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+99;
SET @ENTRY := 91787;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6707, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3543.354, 4711.0444, 30.725677, NULL, 0),
(@PATH, 1, -3532.5151, 4694.823, 30.725677, NULL, 0),
(@PATH, 2, -3516.2942, 4683.985, 30.725677, NULL, 0),
(@PATH, 3, -3497.16, 4680.1787, 30.725677, NULL, 0),
(@PATH, 4, -3478.0256, 4683.985, 30.725677, NULL, 0),
(@PATH, 5, -3461.8047, 4694.823, 30.725677, NULL, 0),
(@PATH, 6, -3450.9658, 4711.0444, 30.725677, NULL, 0),
(@PATH, 7, -3447.16, 4730.1787, 30.725677, NULL, 0),
(@PATH, 8, -3450.9658, 4749.313, 30.725677, NULL, 0),
(@PATH, 9, -3461.8047, 4765.534, 30.725677, NULL, 0),
(@PATH, 10, -3478.026, 4776.3726, 30.725677, NULL, 0),
(@PATH, 11, -3497.16, 4780.1787, 30.725677, NULL, 0),
(@PATH, 12, -3516.2942, 4776.3726, 30.725677, NULL, 0),
(@PATH, 13, -3532.5154, 4765.534, 30.725677, NULL, 0),
(@PATH, 14, -3543.354, 4749.313, 30.725677, NULL, 0),
(@PATH, 15, -3547.16, 4730.1787, 30.725677, NULL, 0),
(@PATH, 16, -3543.354, 4711.0444, 30.725677, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+263;
SET @ENTRY := 91787;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6707, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3433.4216, 4710.334, 24.033804, NULL, 0),
(@PATH, 1, -3422.583, 4726.555, 24.033804, NULL, 0),
(@PATH, 2, -3406.3618, 4737.3936, 24.033804, NULL, 0),
(@PATH, 3, -3387.2275, 4741.1997, 24.033804, NULL, 0),
(@PATH, 4, -3368.0933, 4737.3936, 24.033804, NULL, 0),
(@PATH, 5, -3351.8723, 4726.555, 24.033804, NULL, 0),
(@PATH, 6, -3341.0337, 4710.334, 24.033804, NULL, 0),
(@PATH, 7, -3337.2275, 4691.1997, 24.033804, NULL, 0),
(@PATH, 8, -3341.0334, 4672.0654, 24.033804, NULL, 0),
(@PATH, 9, -3351.872, 4655.844, 24.033804, NULL, 0),
(@PATH, 10, -3368.0933, 4645.006, 24.033804, NULL, 0),
(@PATH, 11, -3387.2275, 4641.1997, 24.033804, NULL, 0),
(@PATH, 12, -3406.3618, 4645.006, 24.033804, NULL, 0),
(@PATH, 13, -3422.5828, 4655.844, 24.033804, NULL, 0),
(@PATH, 14, -3433.4216, 4672.0654, 24.033804, NULL, 0),
(@PATH, 15, -3437.2275, 4691.1997, 24.033804, NULL, 0),
(@PATH, 16, -3433.4216, 4710.334, 24.033804, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+262;
SET @ENTRY := 91787;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6706, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3412.6248, 4678.071, 32.178024, NULL, 0),
(@PATH, 1, -3401.7861, 4694.292, 32.178024, NULL, 0),
(@PATH, 2, -3385.565, 4705.1304, 32.178024, NULL, 0),
(@PATH, 3, -3366.4307, 4708.9365, 32.178024, NULL, 0),
(@PATH, 4, -3347.2964, 4705.1304, 32.178024, NULL, 0),
(@PATH, 5, -3331.0754, 4694.292, 32.178024, NULL, 0),
(@PATH, 6, -3320.2368, 4678.071, 32.178024, NULL, 0),
(@PATH, 7, -3316.4307, 4658.9365, 32.178024, NULL, 0),
(@PATH, 8, -3320.2366, 4639.8022, 32.178024, NULL, 0),
(@PATH, 9, -3331.0752, 4623.581, 32.178024, NULL, 0),
(@PATH, 10, -3347.2964, 4612.7427, 32.178024, NULL, 0),
(@PATH, 11, -3366.4307, 4608.9365, 32.178024, NULL, 0),
(@PATH, 12, -3385.565, 4612.7427, 32.178024, NULL, 0),
(@PATH, 13, -3401.786, 4623.581, 32.178024, NULL, 0),
(@PATH, 14, -3412.6248, 4639.8022, 32.178024, NULL, 0),
(@PATH, 15, -3416.4307, 4658.9365, 32.178024, NULL, 0),
(@PATH, 16, -3412.6248, 4678.071, 32.178024, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+267;
SET @ENTRY := 91787;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6706, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3386.4648, 4603.428, 30.077923, NULL, 0),
(@PATH, 1, -3375.626, 4587.207, 30.077923, NULL, 0),
(@PATH, 2, -3359.405, 4576.3687, 30.077923, NULL, 0),
(@PATH, 3, -3340.2708, 4572.5625, 30.077923, NULL, 0),
(@PATH, 4, -3321.1365, 4576.3687, 30.077923, NULL, 0),
(@PATH, 5, -3304.9155, 4587.207, 30.077923, NULL, 0),
(@PATH, 6, -3294.0767, 4603.428, 30.077923, NULL, 0),
(@PATH, 7, -3290.2708, 4622.5625, 30.077923, NULL, 0),
(@PATH, 8, -3294.0767, 4641.697, 30.077923, NULL, 0),
(@PATH, 9, -3304.9155, 4657.918, 30.077923, NULL, 0),
(@PATH, 10, -3321.1367, 4668.7563, 30.077923, NULL, 0),
(@PATH, 11, -3340.2708, 4672.5625, 30.077923, NULL, 0),
(@PATH, 12, -3359.405, 4668.7563, 30.077923, NULL, 0),
(@PATH, 13, -3375.6262, 4657.918, 30.077923, NULL, 0),
(@PATH, 14, -3386.4648, 4641.697, 30.077923, NULL, 0),
(@PATH, 15, -3390.2708, 4622.5625, 30.077923, NULL, 0),
(@PATH, 16, -3386.4648, 4603.428, 30.077923, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+355;
SET @ENTRY := 91787;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.4491, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3285.6309, 4567.9863, 21.352621, NULL, 0),
(@PATH, 1, -3269.4097, 4578.8247, 21.352621, NULL, 0),
(@PATH, 2, -3250.2754, 4582.631, 21.352621, NULL, 0),
(@PATH, 3, -3231.141, 4578.8247, 21.352621, NULL, 0),
(@PATH, 4, -3214.9202, 4567.9863, 21.352621, NULL, 0),
(@PATH, 5, -3204.0815, 4551.765, 21.352621, NULL, 0),
(@PATH, 6, -3200.2754, 4532.631, 21.352621, NULL, 0),
(@PATH, 7, -3204.0813, 4513.4966, 21.352621, NULL, 0),
(@PATH, 8, -3214.92, 4497.2754, 21.352621, NULL, 0),
(@PATH, 9, -3231.141, 4486.437, 21.352621, NULL, 0),
(@PATH, 10, -3250.2754, 4482.631, 21.352621, NULL, 0),
(@PATH, 11, -3269.4097, 4486.437, 21.352621, NULL, 0),
(@PATH, 12, -3285.6306, 4497.2754, 21.352621, NULL, 0),
(@PATH, 13, -3296.4695, 4513.4966, 21.352621, NULL, 0),
(@PATH, 14, -3300.2754, 4532.631, 21.352621, NULL, 0),
(@PATH, 15, -3296.4695, 4551.765, 21.352621, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+370;
SET @ENTRY := 91787;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.4491, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3259.4053, 4522.4395, 25.821482, NULL, 0),
(@PATH, 1, -3243.184, 4533.278, 25.821482, NULL, 0),
(@PATH, 2, -3224.0498, 4537.084, 25.821482, NULL, 0),
(@PATH, 3, -3204.9155, 4533.278, 25.821482, NULL, 0),
(@PATH, 4, -3188.6946, 4522.4395, 25.821482, NULL, 0),
(@PATH, 5, -3177.856, 4506.2183, 25.821482, NULL, 0),
(@PATH, 6, -3174.0498, 4487.084, 25.821482, NULL, 0),
(@PATH, 7, -3177.8557, 4467.9497, 25.821482, NULL, 0),
(@PATH, 8, -3188.6943, 4451.7285, 25.821482, NULL, 0),
(@PATH, 9, -3204.9155, 4440.89, 25.821482, NULL, 0),
(@PATH, 10, -3224.0498, 4437.084, 25.821482, NULL, 0),
(@PATH, 11, -3243.184, 4440.89, 25.821482, NULL, 0),
(@PATH, 12, -3259.405, 4451.7285, 25.821482, NULL, 0),
(@PATH, 13, -3270.244, 4467.9497, 25.821482, NULL, 0),
(@PATH, 14, -3274.0498, 4487.084, 25.821482, NULL, 0),
(@PATH, 15, -3270.244, 4506.2183, 25.821482, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+374;
SET @ENTRY := 91787;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.4491, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3221.5586, 4490.9478, 36.70028, NULL, 0),
(@PATH, 1, -3212.7603, 4508.36, 36.70028, NULL, 0),
(@PATH, 2, -3197.9683, 4521.08, 36.70028, NULL, 0),
(@PATH, 3, -3179.4346, 4527.1714, 36.70028, NULL, 0),
(@PATH, 4, -3159.9807, 4525.706, 36.70028, NULL, 0),
(@PATH, 5, -3142.5684, 4516.9077, 36.70028, NULL, 0),
(@PATH, 6, -3129.8481, 4502.1157, 36.70028, NULL, 0),
(@PATH, 7, -3123.757, 4483.582, 36.70028, NULL, 0),
(@PATH, 8, -3125.2222, 4464.1284, 36.70028, NULL, 0),
(@PATH, 9, -3134.0205, 4446.716, 36.70028, NULL, 0),
(@PATH, 10, -3148.8125, 4433.9956, 36.70028, NULL, 0),
(@PATH, 11, -3167.3462, 4427.905, 36.70028, NULL, 0),
(@PATH, 12, -3186.8, 4429.3696, 36.70028, NULL, 0),
(@PATH, 13, -3204.2126, 4438.168, 36.70028, NULL, 0),
(@PATH, 14, -3216.9326, 4452.96, 36.70028, NULL, 0),
(@PATH, 15, -3223.0237, 4471.4937, 36.70028, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+416;
SET @ENTRY := 91787;
SET @PATHOFFSET := 13;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.4490, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3280.0403, 4339.0913, 19.947412, NULL, 0),
(@PATH, 1, -3272.9827, 4357.2793, 19.947412, NULL, 0),
(@PATH, 2, -3259.5022, 4371.382, 19.947412, NULL, 0),
(@PATH, 3, -3241.6511, 4379.252, 19.947412, NULL, 0),
(@PATH, 4, -3222.147, 4379.692, 19.947412, NULL, 0),
(@PATH, 5, -3203.9592, 4372.6343, 19.947412, NULL, 0),
(@PATH, 6, -3189.857, 4359.154, 19.947412, NULL, 0),
(@PATH, 7, -3181.9866, 4341.3027, 19.947412, NULL, 0),
(@PATH, 8, -3181.5469, 4321.7983, 19.947412, NULL, 0),
(@PATH, 9, -3188.6045, 4303.611, 19.947412, NULL, 0),
(@PATH, 10, -3202.085, 4289.5083, 19.947412, NULL, 0),
(@PATH, 11, -3219.936, 4281.638, 19.947412, NULL, 0),
(@PATH, 12, -3239.44, 4281.198, 19.947412, NULL, 0),
(@PATH, 13, -3257.6277, 4288.256, 19.947412, NULL, 0),
(@PATH, 14, -3271.7302, 4301.7363, 19.947412, NULL, 0),
(@PATH, 15, -3279.6003, 4319.5874, 19.947412, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+392;
SET @ENTRY := 91787;
SET @PATHOFFSET := 14;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.4491, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3224.63, 4417.9834, 24.508219, NULL, 0),
(@PATH, 1, -3208.409, 4428.822, 24.508219, NULL, 0),
(@PATH, 2, -3189.2747, 4432.628, 24.508219, NULL, 0),
(@PATH, 3, -3170.1404, 4428.822, 24.508219, NULL, 0),
(@PATH, 4, -3153.9194, 4417.9834, 24.508219, NULL, 0),
(@PATH, 5, -3142.8313, 4401.9263, 24.752895, NULL, 0),
(@PATH, 6, -3139.2747, 4382.628, 24.508219, NULL, 0),
(@PATH, 7, -3143.0806, 4363.4937, 24.508219, NULL, 0),
(@PATH, 8, -3153.9194, 4347.2725, 24.508219, NULL, 0),
(@PATH, 9, -3170.1404, 4336.434, 24.508219, NULL, 0),
(@PATH, 10, -3189.2747, 4332.628, 24.508219, NULL, 0),
(@PATH, 11, -3208.409, 4336.434, 24.508219, NULL, 0),
(@PATH, 12, -3224.63, 4347.2725, 24.508219, NULL, 0),
(@PATH, 13, -3235.4688, 4363.4937, 24.508219, NULL, 0),
(@PATH, 14, -3239.2747, 4382.628, 24.508219, NULL, 0),
(@PATH, 15, -3235.4688, 4401.762, 24.508219, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+401;
SET @ENTRY := 91787;
SET @PATHOFFSET := 15;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.4491, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3286.3875, 4265.1006, 22.081734, NULL, 0),
(@PATH, 1, -3267.1313, 4261.97, 22.081734, NULL, 0),
(@PATH, 2, -3248.1428, 4266.4473, 22.081734, NULL, 0),
(@PATH, 3, -3232.3132, 4277.85, 22.081734, NULL, 0),
(@PATH, 4, -3222.0522, 4294.443, 22.081734, NULL, 0),
(@PATH, 5, -3218.922, 4313.699, 22.081734, NULL, 0),
(@PATH, 6, -3223.3994, 4332.6875, 22.081734, NULL, 0),
(@PATH, 7, -3234.8022, 4348.517, 22.081734, NULL, 0),
(@PATH, 8, -3251.3948, 4358.778, 22.081734, NULL, 0),
(@PATH, 9, -3270.6511, 4361.908, 22.081734, NULL, 0),
(@PATH, 10, -3289.6396, 4357.431, 22.081734, NULL, 0),
(@PATH, 11, -3305.4692, 4346.0283, 22.081734, NULL, 0),
(@PATH, 12, -3315.73, 4329.4355, 22.081734, NULL, 0),
(@PATH, 13, -3318.86, 4310.179, 22.081734, NULL, 0),
(@PATH, 14, -3314.383, 4291.191, 22.081734, NULL, 0),
(@PATH, 15, -3302.9802, 4275.3613, 22.081734, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+428;
SET @ENTRY := 91787;
SET @PATHOFFSET := 16;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.4491, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3262.0925, 4294.984, 32.695633, NULL, 0),
(@PATH, 1, -3245.8716, 4284.1455, 32.695633, NULL, 0),
(@PATH, 2, -3226.7373, 4280.3394, 32.695633, NULL, 0),
(@PATH, 3, -3207.603, 4284.1455, 32.695633, NULL, 0),
(@PATH, 4, -3191.3818, 4294.984, 32.695633, NULL, 0),
(@PATH, 5, -3180.5432, 4311.205, 32.695633, NULL, 0),
(@PATH, 6, -3176.7373, 4330.3394, 32.695633, NULL, 0),
(@PATH, 7, -3180.5435, 4349.4736, 32.695633, NULL, 0),
(@PATH, 8, -3191.382, 4365.695, 32.695633, NULL, 0),
(@PATH, 9, -3207.6033, 4376.533, 32.695633, NULL, 0),
(@PATH, 10, -3226.7373, 4380.3394, 32.695633, NULL, 0),
(@PATH, 11, -3245.8716, 4376.533, 32.695633, NULL, 0),
(@PATH, 12, -3262.0928, 4365.695, 32.695633, NULL, 0),
(@PATH, 13, -3272.9314, 4349.4736, 32.695633, NULL, 0),
(@PATH, 14, -3276.7373, 4330.3394, 32.695633, NULL, 0),
(@PATH, 15, -3272.9314, 4311.205, 32.695633, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+543;
SET @ENTRY := 91787;
SET @PATHOFFSET := 17;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.4490, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3526.7632, 4031.791, 46.860832, NULL, 0),
(@PATH, 1, -3510.5422, 4042.63, 46.860832, NULL, 0),
(@PATH, 2, -3491.408, 4046.4358, 46.860832, NULL, 0),
(@PATH, 3, -3472.2737, 4042.63, 46.860832, NULL, 0),
(@PATH, 4, -3456.0527, 4031.791, 46.860832, NULL, 0),
(@PATH, 5, -3445.2139, 4015.57, 46.860832, NULL, 0),
(@PATH, 6, -3441.408, 3996.4358, 46.860832, NULL, 0),
(@PATH, 7, -3445.2139, 3977.3015, 46.860832, NULL, 0),
(@PATH, 8, -3456.0527, 3961.0806, 46.860832, NULL, 0),
(@PATH, 9, -3472.2737, 3950.2417, 46.860832, NULL, 0),
(@PATH, 10, -3491.408, 3946.4358, 46.860832, NULL, 0),
(@PATH, 11, -3510.5422, 3950.2417, 46.860832, NULL, 0),
(@PATH, 12, -3526.7632, 3961.0806, 46.860832, NULL, 0),
(@PATH, 13, -3537.602, 3977.3015, 46.860832, NULL, 0),
(@PATH, 14, -3541.408, 3996.4358, 46.860832, NULL, 0),
(@PATH, 15, -3537.602, 4015.57, 46.860832, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+568;
SET @ENTRY := 91787;
SET @PATHOFFSET := 18;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.4490, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3418.9468, 3927.4792, 35.841232, NULL, 0),
(@PATH, 1, -3405.9373, 3912.9412, 35.841232, NULL, 0),
(@PATH, 2, -3388.3545, 3904.488, 35.841232, NULL, 0),
(@PATH, 3, -3368.8755, 3903.4072, 35.841232, NULL, 0),
(@PATH, 4, -3350.4656, 3909.8628, 35.841232, NULL, 0),
(@PATH, 5, -3335.9275, 3922.8723, 35.841232, NULL, 0),
(@PATH, 6, -3327.4746, 3940.455, 35.841232, NULL, 0),
(@PATH, 7, -3326.3936, 3959.934, 35.841232, NULL, 0),
(@PATH, 8, -3332.8494, 3978.344, 35.841232, NULL, 0),
(@PATH, 9, -3345.859, 3992.882, 35.841232, NULL, 0),
(@PATH, 10, -3363.4414, 4001.3352, 35.841232, NULL, 0),
(@PATH, 11, -3382.9207, 4002.416, 35.841232, NULL, 0),
(@PATH, 12, -3401.3306, 3995.9602, 35.841232, NULL, 0),
(@PATH, 13, -3415.8687, 3982.9507, 35.841232, NULL, 0),
(@PATH, 14, -3424.3215, 3965.3682, 35.841232, NULL, 0),
(@PATH, 15, -3425.4023, 3945.8892, 35.841232, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Cove Seagull
SET @MOVERGUID := @CGUID+569;
SET @ENTRY := 91787;
SET @PATHOFFSET := 19;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.4491, 'Cove Seagull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3343.88, 3917.4915, 33.537476, NULL, 0),
(@PATH, 1, -3336.9739, 3899.2456, 33.537476, NULL, 0),
(@PATH, 2, -3323.6113, 3885.0312, 33.537476, NULL, 0),
(@PATH, 3, -3305.8264, 3877.0127, 33.537476, NULL, 0),
(@PATH, 4, -3286.3267, 3876.4106, 33.537476, NULL, 0),
(@PATH, 5, -3268.0808, 3883.3164, 33.537476, NULL, 0),
(@PATH, 6, -3253.8665, 3896.679, 33.537476, NULL, 0),
(@PATH, 7, -3245.848, 3914.464, 33.537476, NULL, 0),
(@PATH, 8, -3245.2458, 3933.9639, 33.537476, NULL, 0),
(@PATH, 9, -3252.1516, 3952.2097, 33.537476, NULL, 0),
(@PATH, 10, -3265.5144, 3966.4238, 33.537476, NULL, 0),
(@PATH, 11, -3283.2993, 3974.4424, 33.537476, NULL, 0),
(@PATH, 12, -3302.799, 3975.0447, 33.537476, NULL, 0),
(@PATH, 13, -3321.045, 3968.1387, 33.537476, NULL, 0),
(@PATH, 14, -3335.259, 3954.7761, 33.537476, NULL, 0),
(@PATH, 15, -3343.2776, 3936.9912, 33.537476, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+482;
SET @ENTRY := 97844;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0228, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3453.0352, 4210.842, 30.318731, NULL, 0),
(@PATH, 1, -3462.6309, 4209.089, 30.543495, NULL, 0),
(@PATH, 2, -3470.8254, 4203.7974, 30.11018, NULL, 0),
(@PATH, 3, -3476.371, 4195.7725, 30.187319, NULL, 0),
(@PATH, 4, -3478.4238, 4186.2363, 30.184826, NULL, 0),
(@PATH, 5, -3476.671, 4176.6406, 30.184822, NULL, 0),
(@PATH, 6, -3471.3794, 4168.4463, 30.184813, NULL, 0),
(@PATH, 7, -3463.3547, 4162.9004, 30.18484, NULL, 0),
(@PATH, 8, -3453.8186, 4160.8477, 30.184822, NULL, 0),
(@PATH, 9, -3444.223, 4162.6006, 30.184822, NULL, 0),
(@PATH, 10, -3436.0283, 4167.892, 30.184822, NULL, 0),
(@PATH, 11, -3430.4827, 4175.917, 30.184824, NULL, 0),
(@PATH, 12, -3428.43, 4185.453, 30.184818, NULL, 0),
(@PATH, 13, -3430.1829, 4195.049, 30.184832, NULL, 0),
(@PATH, 14, -3435.4744, 4203.243, 30.18484, NULL, 0),
(@PATH, 15, -3443.499, 4208.789, 30.18484, NULL, 0);

UPDATE `creature` SET `position_x`=-3453.0352, `position_y`=4210.842, `position_z`=30.318731, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+483;
SET @ENTRY := 97844;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0226, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3467.8164, 4205.183, 30.455984, NULL, 0),
(@PATH, 1, -3473.2644, 4197.092, 30.184835, NULL, 0),
(@PATH, 2, -3475.2012, 4187.5317, 30.184824, NULL, 0),
(@PATH, 3, -3473.3323, 4177.958, 30.184822, NULL, 0),
(@PATH, 4, -3467.9417, 4169.828, 30.184822, NULL, 0),
(@PATH, 5, -3459.8503, 4164.38, 30.184834, NULL, 0),
(@PATH, 6, -3450.29, 4162.4434, 30.184822, NULL, 0),
(@PATH, 7, -3440.7163, 4164.3125, 30.184818, NULL, 0),
(@PATH, 8, -3432.5867, 4169.7026, 30.184822, NULL, 0),
(@PATH, 9, -3427.1384, 4177.794, 30.184822, NULL, 0),
(@PATH, 10, -3425.2017, 4187.3545, 30.184835, NULL, 0),
(@PATH, 11, -3427.0708, 4196.928, 30.184837, NULL, 0),
(@PATH, 12, -3432.4612, 4205.058, 30.184837, NULL, 0),
(@PATH, 13, -3440.5525, 4210.506, 30.184841, NULL, 0),
(@PATH, 14, -3450.1128, 4212.443, 30.21917, NULL, 0),
(@PATH, 15, -3459.6865, 4210.5737, 30.376904, NULL, 0);

UPDATE `creature` SET `position_x`=-3467.8164, `position_y`=4205.183, `position_z`=30.455984, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+486;
SET @ENTRY := 97844;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0229, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3438.9756, 4197.7603, 30.184818, NULL, 0),
(@PATH, 1, -3448.7249, 4197.442, 30.184818, NULL, 0),
(@PATH, 2, -3457.6104, 4193.417, 30.18482, NULL, 0),
(@PATH, 3, -3464.279, 4186.2983, 30.184822, NULL, 0),
(@PATH, 4, -3467.716, 4177.1694, 30.184822, NULL, 0),
(@PATH, 5, -3467.398, 4167.42, 30.184824, NULL, 0),
(@PATH, 6, -3463.373, 4158.5347, 30.18484, NULL, 0),
(@PATH, 7, -3456.2542, 4151.8657, 30.184837, NULL, 0),
(@PATH, 8, -3447.1252, 4148.4287, 30.184824, NULL, 0),
(@PATH, 9, -3437.376, 4148.747, 30.184816, NULL, 0),
(@PATH, 10, -3428.4905, 4152.772, 30.183882, NULL, 0),
(@PATH, 11, -3421.8215, 4159.8906, 30.184822, NULL, 0),
(@PATH, 12, -3418.3848, 4169.0195, 30.184818, NULL, 0),
(@PATH, 13, -3418.703, 4178.769, 30.184835, NULL, 0),
(@PATH, 14, -3422.7278, 4187.6543, 30.18484, NULL, 0),
(@PATH, 15, -3429.8467, 4194.323, 30.18483, NULL, 0);

UPDATE `creature` SET `position_x`=-3438.9756, `position_y`=4197.7603, `position_z`=30.184818, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+487;
SET @ENTRY := 97844;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0196, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3454.4, 4200.7563, 30.184818, NULL, 0),
(@PATH, 1, -3459.8079, 4198.5186, 30.184818, NULL, 0),
(@PATH, 2, -3463.948, 4194.382, 30.184822, NULL, 0),
(@PATH, 3, -3466.19, 4188.9756, 30.184824, NULL, 0),
(@PATH, 4, -3466.1924, 4183.123, 30.184824, NULL, 0),
(@PATH, 5, -3463.9546, 4177.715, 30.184824, NULL, 0),
(@PATH, 6, -3459.8179, 4173.5747, 30.184822, NULL, 0),
(@PATH, 7, -3454.4114, 4171.333, 30.184822, NULL, 0),
(@PATH, 8, -3448.5588, 4171.3306, 30.18482, NULL, 0),
(@PATH, 9, -3443.1506, 4173.5684, 30.184818, NULL, 0),
(@PATH, 10, -3439.0105, 4177.705, 30.184822, NULL, 0),
(@PATH, 11, -3436.7688, 4183.1113, 30.184824, NULL, 0),
(@PATH, 12, -3436.7664, 4188.964, 30.18482, NULL, 0),
(@PATH, 13, -3439.004, 4194.372, 30.184818, NULL, 0),
(@PATH, 14, -3443.1409, 4198.512, 30.184818, NULL, 0),
(@PATH, 15, -3448.547, 4200.754, 30.184818, NULL, 0);

UPDATE `creature` SET `position_x`=-3454.4, `position_y`=4200.7563, `position_z`=30.184818, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+491;
SET @ENTRY := 97844;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0181, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3451.395, 4214.428, 30.427036, NULL, 0),
(@PATH, 1, -3445.788, 4216.107, 30.184834, NULL, 0),
(@PATH, 2, -3439.9658, 4215.512, 30.14658, NULL, 0),
(@PATH, 3, -3434.8142, 4212.7344, 30.12414, NULL, 0),
(@PATH, 4, -3431.1177, 4208.197, 30.166397, NULL, 0),
(@PATH, 5, -3429.439, 4202.5903, 30.184837, NULL, 0),
(@PATH, 6, -3430.0337, 4196.7676, 30.18484, NULL, 0),
(@PATH, 7, -3432.8113, 4191.616, 30.184818, NULL, 0),
(@PATH, 8, -3437.3489, 4187.9194, 30.184822, NULL, 0),
(@PATH, 9, -3442.9558, 4186.2407, 30.184826, NULL, 0),
(@PATH, 10, -3448.778, 4186.8354, 30.184826, NULL, 0),
(@PATH, 11, -3453.9297, 4189.6133, 30.184824, NULL, 0),
(@PATH, 12, -3457.6262, 4194.151, 30.184822, NULL, 0),
(@PATH, 13, -3459.305, 4199.758, 30.184818, NULL, 0),
(@PATH, 14, -3458.7102, 4205.58, 30.203585, NULL, 0),
(@PATH, 15, -3455.9326, 4210.7314, 30.463842, NULL, 0);

UPDATE `creature` SET `position_x`=-3451.395, `position_y`=4214.428, `position_z`=30.427036, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+494;
SET @ENTRY := 97844;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0193, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3433.5327, 4187.2305, 30.184818, NULL, 0),
(@PATH, 1, -3439.0933, 4189.0566, 30.184818, NULL, 0),
(@PATH, 2, -3444.9292, 4188.6157, 30.184822, NULL, 0),
(@PATH, 3, -3450.1523, 4185.9746, 30.184822, NULL, 0),
(@PATH, 4, -3453.9673, 4181.536, 30.184818, NULL, 0),
(@PATH, 5, -3455.7932, 4175.9756, 30.184818, NULL, 0),
(@PATH, 6, -3455.3523, 4170.1396, 30.184822, NULL, 0),
(@PATH, 7, -3452.7117, 4164.9165, 30.184822, NULL, 0),
(@PATH, 8, -3448.2732, 4161.1016, 30.184822, NULL, 0),
(@PATH, 9, -3442.7126, 4159.2754, 30.184824, NULL, 0),
(@PATH, 10, -3436.8765, 4159.7163, 30.184818, NULL, 0),
(@PATH, 11, -3431.6533, 4162.3574, 30.184818, NULL, 0),
(@PATH, 12, -3427.8384, 4166.796, 30.184824, NULL, 0),
(@PATH, 13, -3426.0125, 4172.3564, 30.184824, NULL, 0),
(@PATH, 14, -3426.4534, 4178.1924, 30.184822, NULL, 0),
(@PATH, 15, -3429.094, 4183.4155, 30.184818, NULL, 0);

UPDATE `creature` SET `position_x`=-3433.5327, `position_y`=4187.2305, `position_z`=30.184818, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+495;
SET @ENTRY := 97844;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0201, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3454.8918, 4190.411, 30.184826, NULL, 0),
(@PATH, 1, -3457.2017, 4195.7886, 30.184818, NULL, 0),
(@PATH, 2, -3461.3938, 4199.873, 30.184818, NULL, 0),
(@PATH, 3, -3466.8296, 4202.042, 30.191427, NULL, 0),
(@PATH, 4, -3472.682, 4201.966, 30.122963, NULL, 0),
(@PATH, 5, -3478.0596, 4199.656, 30.733536, NULL, 0),
(@PATH, 6, -3482.1438, 4195.464, 30.894157, NULL, 0),
(@PATH, 7, -3484.3127, 4190.028, 30.186893, NULL, 0),
(@PATH, 8, -3484.2366, 4184.176, 30.184822, NULL, 0),
(@PATH, 9, -3481.9265, 4178.7983, 30.184822, NULL, 0),
(@PATH, 10, -3477.7346, 4174.714, 30.184822, NULL, 0),
(@PATH, 11, -3472.2986, 4172.545, 30.184822, NULL, 0),
(@PATH, 12, -3466.4463, 4172.621, 30.184824, NULL, 0),
(@PATH, 13, -3461.0688, 4174.931, 30.184822, NULL, 0),
(@PATH, 14, -3456.9846, 4179.123, 30.184818, NULL, 0),
(@PATH, 15, -3454.8154, 4184.559, 30.184826, NULL, 0);

UPDATE `creature` SET `position_x`=-3454.8918, `position_y`=4190.411, `position_z`=30.184826, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+498;
SET @ENTRY := 97844;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0230, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3422.2983, 4172.317, 30.184818, NULL, 0),
(@PATH, 1, -3423.9744, 4181.9263, 30.184834, NULL, 0),
(@PATH, 2, -3429.2002, 4190.1626, 30.184822, NULL, 0),
(@PATH, 3, -3437.1802, 4195.7725, 30.184818, NULL, 0),
(@PATH, 4, -3446.6995, 4197.9014, 30.184818, NULL, 0),
(@PATH, 5, -3456.309, 4196.2256, 30.184818, NULL, 0),
(@PATH, 6, -3464.5457, 4190.9995, 30.184824, NULL, 0),
(@PATH, 7, -3470.1553, 4183.0195, 30.184822, NULL, 0),
(@PATH, 8, -3472.2842, 4173.5, 30.184822, NULL, 0),
(@PATH, 9, -3470.6082, 4163.8906, 30.184837, NULL, 0),
(@PATH, 10, -3465.3823, 4155.6543, 30.184837, NULL, 0),
(@PATH, 11, -3457.4023, 4150.0444, 30.184826, NULL, 0),
(@PATH, 12, -3447.8828, 4147.9155, 30.184824, NULL, 0),
(@PATH, 13, -3438.2734, 4149.5913, 30.184824, NULL, 0),
(@PATH, 14, -3430.0369, 4154.8174, 30.184822, NULL, 0),
(@PATH, 15, -3424.427, 4162.7974, 30.184818, NULL, 0);

UPDATE `creature` SET `position_x`=-3422.2983, `position_y`=4172.317, `position_z`=30.184818, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+500;
SET @ENTRY := 97844;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0198, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3441.174, 4187.765, 30.184822, NULL, 0),
(@PATH, 1, -3438.8052, 4193.117, 30.184818, NULL, 0),
(@PATH, 2, -3438.6646, 4198.9683, 30.184818, NULL, 0),
(@PATH, 3, -3440.774, 4204.4277, 30.184828, NULL, 0),
(@PATH, 4, -3444.8118, 4208.6646, 30.18484, NULL, 0),
(@PATH, 5, -3450.1636, 4211.033, 30.20554, NULL, 0),
(@PATH, 6, -3456.0146, 4211.174, 30.50032, NULL, 0),
(@PATH, 7, -3461.474, 4209.0645, 30.404879, NULL, 0),
(@PATH, 8, -3465.7107, 4205.0264, 30.238335, NULL, 0),
(@PATH, 9, -3468.0796, 4199.675, 30.184828, NULL, 0),
(@PATH, 10, -3468.2202, 4193.8237, 30.184822, NULL, 0),
(@PATH, 11, -3466.1108, 4188.3643, 30.184824, NULL, 0),
(@PATH, 12, -3462.073, 4184.1274, 30.184822, NULL, 0),
(@PATH, 13, -3456.7212, 4181.759, 30.184822, NULL, 0),
(@PATH, 14, -3450.87, 4181.618, 30.184803, NULL, 0),
(@PATH, 15, -3445.4106, 4183.7275, 30.184822, NULL, 0);

UPDATE `creature` SET `position_x`=-3441.174, `position_y`=4187.765, `position_z`=30.184822, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+503;
SET @ENTRY := 97844;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0233, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3467.8364, 4201.1973, 30.185493, NULL, 0),
(@PATH, 1, -3458.1067, 4200.5015, 30.184818, NULL, 0),
(@PATH, 2, -3449.384, 4196.135, 30.184818, NULL, 0),
(@PATH, 3, -3442.9963, 4188.7627, 30.18482, NULL, 0),
(@PATH, 4, -3439.916, 4179.5073, 30.184824, NULL, 0),
(@PATH, 5, -3440.6123, 4169.778, 30.184818, NULL, 0),
(@PATH, 6, -3444.9788, 4161.055, 30.184822, NULL, 0),
(@PATH, 7, -3452.3508, 4154.6675, 30.184826, NULL, 0),
(@PATH, 8, -3461.6062, 4151.587, 30.184837, NULL, 0),
(@PATH, 9, -3471.336, 4152.283, 30.184834, NULL, 0),
(@PATH, 10, -3480.0586, 4156.65, 30.184822, NULL, 0),
(@PATH, 11, -3486.4463, 4164.022, 30.184822, NULL, 0),
(@PATH, 12, -3489.5264, 4173.2773, 30.961046, NULL, 0),
(@PATH, 13, -3488.8303, 4183.007, 30.184822, NULL, 0),
(@PATH, 14, -3484.4639, 4191.7295, 30.330887, NULL, 0),
(@PATH, 15, -3477.0918, 4198.117, 30.255707, NULL, 0);

UPDATE `creature` SET `position_x`=-3467.8364, `position_y`=4201.1973, `position_z`=30.185493, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+508;
SET @ENTRY := 97844;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0197, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3430.359, 4161.132, 30.184818, NULL, 0),
(@PATH, 1, -3424.6929, 4159.6655, 30.184822, NULL, 0),
(@PATH, 2, -3420.019, 4156.1426, 30.18483, NULL, 0),
(@PATH, 3, -3417.0493, 4151.099, 30.184809, NULL, 0),
(@PATH, 4, -3416.2356, 4145.3037, 30.184875, NULL, 0),
(@PATH, 5, -3417.7017, 4139.637, 30.184963, NULL, 0),
(@PATH, 6, -3421.2246, 4134.964, 30.184826, NULL, 0),
(@PATH, 7, -3426.2678, 4131.994, 30.184822, NULL, 0),
(@PATH, 8, -3432.0637, 4131.18, 30.184809, NULL, 0),
(@PATH, 9, -3437.7297, 4132.6465, 30.184677, NULL, 0),
(@PATH, 10, -3442.4036, 4136.1694, 30.184837, NULL, 0),
(@PATH, 11, -3445.3733, 4141.2124, 30.184826, NULL, 0),
(@PATH, 12, -3446.187, 4147.0083, 30.184826, NULL, 0),
(@PATH, 13, -3444.721, 4152.6743, 30.184822, NULL, 0),
(@PATH, 14, -3441.198, 4157.348, 30.184824, NULL, 0),
(@PATH, 15, -3436.1548, 4160.318, 30.184818, NULL, 0);

UPDATE `creature` SET `position_x`=-3430.359, `position_y`=4161.132, `position_z`=30.184818, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+509;
SET @ENTRY := 97844;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0195, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3436.458, 4167.0537, 30.184822, NULL, 0),
(@PATH, 1, -3430.9202, 4165.1606, 30.184822, NULL, 0),
(@PATH, 2, -3425.079, 4165.5303, 30.184818, NULL, 0),
(@PATH, 3, -3419.8242, 4168.1074, 30.184818, NULL, 0),
(@PATH, 4, -3415.9558, 4172.4995, 30.18483, NULL, 0),
(@PATH, 5, -3414.0623, 4178.0376, 30.184862, NULL, 0),
(@PATH, 6, -3414.4324, 4183.8784, 30.184841, NULL, 0),
(@PATH, 7, -3417.0095, 4189.1333, 30.184841, NULL, 0),
(@PATH, 8, -3421.4014, 4193.002, 30.18484, NULL, 0),
(@PATH, 9, -3426.9392, 4194.895, 30.18484, NULL, 0),
(@PATH, 10, -3432.7803, 4194.5254, 30.184822, NULL, 0),
(@PATH, 11, -3438.035, 4191.948, 30.184818, NULL, 0),
(@PATH, 12, -3441.9036, 4187.556, 30.184824, NULL, 0),
(@PATH, 13, -3443.797, 4182.018, 30.184824, NULL, 0),
(@PATH, 14, -3443.427, 4176.1772, 30.184822, NULL, 0),
(@PATH, 15, -3440.8499, 4170.9224, 30.184818, NULL, 0);

UPDATE `creature` SET `position_x`=-3436.458, `position_y`=4167.0537, `position_z`=30.184822, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+510;
SET @ENTRY := 97844;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0197, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3426.2974, 4150.339, 30.183582, NULL, 0),
(@PATH, 1, -3421.1438, 4153.113, 30.184834, NULL, 0),
(@PATH, 2, -3417.444, 4157.648, 30.184835, NULL, 0),
(@PATH, 3, -3415.7615, 4163.2534, 30.18483, NULL, 0),
(@PATH, 4, -3416.352, 4169.076, 30.184826, NULL, 0),
(@PATH, 5, -3419.1262, 4174.23, 30.184822, NULL, 0),
(@PATH, 6, -3423.6611, 4177.9297, 30.184822, NULL, 0),
(@PATH, 7, -3429.2668, 4179.612, 30.184824, NULL, 0),
(@PATH, 8, -3435.0896, 4179.0215, 30.184824, NULL, 0),
(@PATH, 9, -3440.2432, 4176.2476, 30.184824, NULL, 0),
(@PATH, 10, -3443.9429, 4171.7124, 30.184818, NULL, 0),
(@PATH, 11, -3445.6255, 4166.107, 30.184818, NULL, 0),
(@PATH, 12, -3445.035, 4160.2837, 30.184824, NULL, 0),
(@PATH, 13, -3442.2607, 4155.1304, 30.184824, NULL, 0),
(@PATH, 14, -3437.7258, 4151.4307, 30.184824, NULL, 0),
(@PATH, 15, -3432.12, 4149.748, 30.179571, NULL, 0);

UPDATE `creature` SET `position_x`=-3426.2974, `position_y`=4150.339, `position_z`=30.183582, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+511;
SET @ENTRY := 97844;
SET @PATHOFFSET := 13;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0236, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3481.9712, 4184.4834, 30.184822, NULL, 0),
(@PATH, 1, -3474.0503, 4190.1763, 30.184824, NULL, 0),
(@PATH, 2, -3464.5537, 4192.4043, 30.184824, NULL, 0),
(@PATH, 3, -3454.9272, 4190.829, 30.184824, NULL, 0),
(@PATH, 4, -3446.6365, 4185.6895, 30.184826, NULL, 0),
(@PATH, 5, -3440.9436, 4177.7686, 30.184824, NULL, 0),
(@PATH, 6, -3438.715, 4168.272, 30.184818, NULL, 0),
(@PATH, 7, -3440.2905, 4158.6455, 30.184822, NULL, 0),
(@PATH, 8, -3445.43, 4150.355, 30.184824, NULL, 0),
(@PATH, 9, -3453.3508, 4144.662, 30.184822, NULL, 0),
(@PATH, 10, -3462.8474, 4142.4336, 30.184824, NULL, 0),
(@PATH, 11, -3472.4739, 4144.009, 30.184824, NULL, 0),
(@PATH, 12, -3480.7646, 4149.1484, 30.184822, NULL, 0),
(@PATH, 13, -3486.4578, 4157.0693, 30.184822, NULL, 0),
(@PATH, 14, -3488.686, 4166.566, 30.838383, NULL, 0),
(@PATH, 15, -3487.1106, 4176.1924, 30.185658, NULL, 0);

UPDATE `creature` SET `position_x`=-3481.9712, `position_y`=4184.4834, `position_z`=30.184822, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+515;
SET @ENTRY := 97844;
SET @PATHOFFSET := 14;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0196, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3477.2478, 4168.919, 30.184849, NULL, 0),
(@PATH, 1, -3475.3213, 4174.4453, 30.184822, NULL, 0),
(@PATH, 2, -3471.4268, 4178.814, 30.184822, NULL, 0),
(@PATH, 3, -3466.1567, 4181.36, 30.184824, NULL, 0),
(@PATH, 4, -3460.3135, 4181.6953, 30.184818, NULL, 0),
(@PATH, 5, -3454.7869, 4179.769, 30.18482, NULL, 0),
(@PATH, 6, -3450.4182, 4175.874, 30.184818, NULL, 0),
(@PATH, 7, -3447.8726, 4170.604, 30.18482, NULL, 0),
(@PATH, 8, -3447.537, 4164.761, 30.18482, NULL, 0),
(@PATH, 9, -3449.4636, 4159.2344, 30.184822, NULL, 0),
(@PATH, 10, -3453.3582, 4154.8657, 30.184826, NULL, 0),
(@PATH, 11, -3458.6282, 4152.32, 30.184835, NULL, 0),
(@PATH, 12, -3464.4714, 4151.985, 30.18484, NULL, 0),
(@PATH, 13, -3469.998, 4153.911, 30.184837, NULL, 0),
(@PATH, 14, -3474.3667, 4157.8057, 30.18484, NULL, 0),
(@PATH, 15, -3476.9124, 4163.0757, 30.184834, NULL, 0);

UPDATE `creature` SET `position_x`=-3477.2478, `position_y`=4168.919, `position_z`=30.184849, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+518;
SET @ENTRY := 97844;
SET @PATHOFFSET := 15;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0228, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3443.4697, 4147.945, 30.184826, NULL, 0),
(@PATH, 1, -3435.7556, 4153.9146, 30.184822, NULL, 0),
(@PATH, 2, -3430.9133, 4162.3823, 30.184818, NULL, 0),
(@PATH, 3, -3429.68, 4172.0586, 30.184826, NULL, 0),
(@PATH, 4, -3432.2437, 4181.47, 30.184824, NULL, 0),
(@PATH, 5, -3438.2139, 4189.1846, 30.184822, NULL, 0),
(@PATH, 6, -3446.6814, 4194.027, 30.184818, NULL, 0),
(@PATH, 7, -3456.3577, 4195.2603, 30.18482, NULL, 0),
(@PATH, 8, -3465.7693, 4192.6963, 30.184824, NULL, 0),
(@PATH, 9, -3473.4836, 4186.7266, 30.184822, NULL, 0),
(@PATH, 10, -3478.326, 4178.259, 30.184822, NULL, 0),
(@PATH, 11, -3479.559, 4168.5825, 30.184822, NULL, 0),
(@PATH, 12, -3476.9954, 4159.171, 30.184834, NULL, 0),
(@PATH, 13, -3471.0254, 4151.4565, 30.18483, NULL, 0),
(@PATH, 14, -3462.5576, 4146.6143, 30.184826, NULL, 0),
(@PATH, 15, -3452.8813, 4145.381, 30.184824, NULL, 0);

UPDATE `creature` SET `position_x`=-3443.4697, `position_y`=4147.945, `position_z`=30.184826, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+520;
SET @ENTRY := 97844;
SET @PATHOFFSET := 16;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0194, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3452.581, 4136.205, 30.184835, NULL, 0),
(@PATH, 1, -3451.528, 4141.962, 30.184822, NULL, 0),
(@PATH, 2, -3448.352, 4146.878, 30.184824, NULL, 0),
(@PATH, 3, -3443.5366, 4150.2046, 30.184826, NULL, 0),
(@PATH, 4, -3437.8147, 4151.435, 30.184822, NULL, 0),
(@PATH, 5, -3432.0574, 4150.382, 30.180794, NULL, 0),
(@PATH, 6, -3427.1414, 4147.206, 30.184835, NULL, 0),
(@PATH, 7, -3423.8152, 4142.39, 30.184834, NULL, 0),
(@PATH, 8, -3422.5847, 4136.6685, 30.18483, NULL, 0),
(@PATH, 9, -3423.6377, 4130.911, 30.184746, NULL, 0),
(@PATH, 10, -3426.8137, 4125.995, 30.178913, NULL, 0),
(@PATH, 11, -3431.6294, 4122.669, 30.040516, NULL, 0),
(@PATH, 12, -3437.3513, 4121.4385, 29.763027, NULL, 0),
(@PATH, 13, -3443.1084, 4122.4917, 29.79485, NULL, 0),
(@PATH, 14, -3448.0244, 4125.6675, 30.106972, NULL, 0),
(@PATH, 15, -3451.3508, 4130.483, 30.184467, NULL, 0);

UPDATE `creature` SET `position_x`=-3452.581, `position_y`=4136.205, `position_z`=30.184835, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+522;
SET @ENTRY := 97844;
SET @PATHOFFSET := 17;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0197, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3445.5269, 4154.404, 30.184824, NULL, 0),
(@PATH, 1, -3451.3572, 4154.915, 30.18482, NULL, 0),
(@PATH, 2, -3456.548, 4157.6187, 30.184828, NULL, 0),
(@PATH, 3, -3460.309, 4162.1025, 30.184832, NULL, 0),
(@PATH, 4, -3462.068, 4167.685, 30.184822, NULL, 0),
(@PATH, 5, -3461.557, 4173.515, 30.184824, NULL, 0),
(@PATH, 6, -3458.8533, 4178.706, 30.18482, NULL, 0),
(@PATH, 7, -3454.3691, 4182.4673, 30.184826, NULL, 0),
(@PATH, 8, -3448.7869, 4184.226, 30.184822, NULL, 0),
(@PATH, 9, -3442.9565, 4183.715, 30.184822, NULL, 0),
(@PATH, 10, -3437.7656, 4181.011, 30.184822, NULL, 0),
(@PATH, 11, -3434.0046, 4176.5273, 30.184822, NULL, 0),
(@PATH, 12, -3432.2456, 4170.945, 30.184824, NULL, 0),
(@PATH, 13, -3432.7568, 4165.1147, 30.184822, NULL, 0),
(@PATH, 14, -3435.4604, 4159.924, 30.184818, NULL, 0),
(@PATH, 15, -3439.9446, 4156.1626, 30.184826, NULL, 0);

UPDATE `creature` SET `position_x`=-3445.5269, `position_y`=4154.404, `position_z`=30.184824, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+523;
SET @ENTRY := 97844;
SET @PATHOFFSET := 18;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0194, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3473.9397, 4177.3584, 30.184822, NULL, 0),
(@PATH, 1, -3470.9685, 4172.3154, 30.184822, NULL, 0),
(@PATH, 2, -3466.294, 4168.794, 30.184826, NULL, 0),
(@PATH, 3, -3460.6277, 4167.329, 30.184824, NULL, 0),
(@PATH, 4, -3454.832, 4168.1445, 30.184822, NULL, 0),
(@PATH, 5, -3449.7893, 4171.115, 30.184822, NULL, 0),
(@PATH, 6, -3446.2676, 4175.79, 30.184822, NULL, 0),
(@PATH, 7, -3444.803, 4181.4565, 30.184826, NULL, 0),
(@PATH, 8, -3445.6182, 4187.252, 30.184824, NULL, 0),
(@PATH, 9, -3448.589, 4192.2944, 30.18482, NULL, 0),
(@PATH, 10, -3453.2637, 4195.8164, 30.184818, NULL, 0),
(@PATH, 11, -3458.9302, 4197.2812, 30.184818, NULL, 0),
(@PATH, 12, -3464.7258, 4196.466, 30.18482, NULL, 0),
(@PATH, 13, -3469.7683, 4193.4946, 30.184824, NULL, 0),
(@PATH, 14, -3473.29, 4188.8203, 30.184822, NULL, 0),
(@PATH, 15, -3474.755, 4183.154, 30.184822, NULL, 0);

UPDATE `creature` SET `position_x`=-3473.9397, `position_y`=4177.3584, `position_z`=30.184822, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+525;
SET @ENTRY := 97844;
SET @PATHOFFSET := 19;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0196, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3489.159, 4148.353, 30.184822, NULL, 0),
(@PATH, 1, -3487.2324, 4153.8794, 30.184822, NULL, 0),
(@PATH, 2, -3483.338, 4158.248, 30.184822, NULL, 0),
(@PATH, 3, -3478.0679, 4160.794, 30.18483, NULL, 0),
(@PATH, 4, -3472.2246, 4161.1294, 30.18484, NULL, 0),
(@PATH, 5, -3466.698, 4159.203, 30.18484, NULL, 0),
(@PATH, 6, -3462.3293, 4155.308, 30.184837, NULL, 0),
(@PATH, 7, -3459.7837, 4150.038, 30.184834, NULL, 0),
(@PATH, 8, -3459.4482, 4144.1953, 30.184822, NULL, 0),
(@PATH, 9, -3461.3748, 4138.6685, 30.184824, NULL, 0),
(@PATH, 10, -3465.2693, 4134.3, 30.184893, NULL, 0),
(@PATH, 11, -3470.5393, 4131.754, 30.18256, NULL, 0),
(@PATH, 12, -3476.3826, 4131.419, 30.184786, NULL, 0),
(@PATH, 13, -3481.9092, 4133.345, 30.184822, NULL, 0),
(@PATH, 14, -3486.2778, 4137.2397, 30.184822, NULL, 0),
(@PATH, 15, -3488.8235, 4142.51, 30.184822, NULL, 0);

UPDATE `creature` SET `position_x`=-3489.159, `position_y`=4148.353, `position_z`=30.184822, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+526;
SET @ENTRY := 97844;
SET @PATHOFFSET := 20;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0202, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3433.2754, 4150.9766, 30.181475, NULL, 0),
(@PATH, 1, -3427.6094, 4149.5103, 30.182087, NULL, 0),
(@PATH, 2, -3422.9355, 4145.9873, 30.184835, NULL, 0),
(@PATH, 3, -3419.9658, 4140.944, 30.184835, NULL, 0),
(@PATH, 4, -3419.152, 4135.1484, 30.184828, NULL, 0),
(@PATH, 5, -3420.6182, 4129.482, 30.184828, NULL, 0),
(@PATH, 6, -3424.141, 4124.8086, 30.168438, NULL, 0),
(@PATH, 7, -3429.1843, 4121.839, 29.492294, NULL, 0),
(@PATH, 8, -3434.9802, 4121.025, 29.808344, NULL, 0),
(@PATH, 9, -3440.6462, 4122.491, 29.80838, NULL, 0),
(@PATH, 10, -3445.32, 4126.014, 30.12708, NULL, 0),
(@PATH, 11, -3448.2898, 4131.057, 30.18472, NULL, 0),
(@PATH, 12, -3449.1035, 4136.853, 30.184834, NULL, 0),
(@PATH, 13, -3447.6375, 4142.519, 30.184822, NULL, 0),
(@PATH, 14, -3444.1145, 4147.193, 30.184824, NULL, 0),
(@PATH, 15, -3439.0713, 4150.1626, 30.184826, NULL, 0);

UPDATE `creature` SET `position_x`=-3433.2754, `position_y`=4150.9766, `position_z`=30.181475, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+530;
SET @ENTRY := 97844;
SET @PATHOFFSET := 21;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0230, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3470.7568, 4138.8076, 30.184822, NULL, 0),
(@PATH, 1, -3476.663, 4146.571, 30.184826, NULL, 0),
(@PATH, 2, -3479.149, 4156.003, 30.184822, NULL, 0),
(@PATH, 3, -3477.8362, 4165.669, 30.18483, NULL, 0),
(@PATH, 4, -3472.924, 4174.096, 30.184822, NULL, 0),
(@PATH, 5, -3465.161, 4180.0024, 30.184824, NULL, 0),
(@PATH, 6, -3455.7285, 4182.4883, 30.184822, NULL, 0),
(@PATH, 7, -3446.0627, 4181.1753, 30.184822, NULL, 0),
(@PATH, 8, -3437.6353, 4176.2637, 30.184822, NULL, 0),
(@PATH, 9, -3431.729, 4168.5005, 30.184826, NULL, 0),
(@PATH, 10, -3429.2432, 4159.068, 30.184818, NULL, 0),
(@PATH, 11, -3430.5562, 4149.4023, 30.178442, NULL, 0),
(@PATH, 12, -3435.468, 4140.9746, 30.184633, NULL, 0),
(@PATH, 13, -3443.2312, 4135.0684, 30.184837, NULL, 0),
(@PATH, 14, -3452.6636, 4132.5825, 30.184832, NULL, 0),
(@PATH, 15, -3462.3293, 4133.8955, 30.185404, NULL, 0);

UPDATE `creature` SET `position_x`=-3470.7568, `position_y`=4138.8076, `position_z`=30.184822, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+532;
SET @ENTRY := 97844;
SET @PATHOFFSET := 22;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0200, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3435.036, 4143.7617, 30.184324, NULL, 0),
(@PATH, 1, -3434.2222, 4137.966, 30.184761, NULL, 0),
(@PATH, 2, -3431.2524, 4132.923, 30.184834, NULL, 0),
(@PATH, 3, -3426.5786, 4129.4, 30.18453, NULL, 0),
(@PATH, 4, -3420.9126, 4127.9336, 30.1847, NULL, 0),
(@PATH, 5, -3415.1167, 4128.7476, 30.14727, NULL, 0),
(@PATH, 6, -3410.0735, 4131.7173, 30.301373, NULL, 0),
(@PATH, 7, -3406.5505, 4136.3906, 30.433783, NULL, 0),
(@PATH, 8, -3405.0845, 4142.057, 30.032148, NULL, 0),
(@PATH, 9, -3405.8982, 4147.853, 30.085854, NULL, 0),
(@PATH, 10, -3408.868, 4152.896, 30.180813, NULL, 0),
(@PATH, 11, -3413.5417, 4156.419, 30.184832, NULL, 0),
(@PATH, 12, -3419.2078, 4157.8853, 30.18483, NULL, 0),
(@PATH, 13, -3425.0037, 4157.0713, 30.184822, NULL, 0),
(@PATH, 14, -3430.0469, 4154.1016, 30.184786, NULL, 0),
(@PATH, 15, -3433.5698, 4149.4277, 30.18121, NULL, 0);

UPDATE `creature` SET `position_x`=-3435.036, `position_y`=4143.7617, `position_z`=30.184324, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+533;
SET @ENTRY := 97844;
SET @PATHOFFSET := 23;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0229, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3486.747, 4145.16, 30.184822, NULL, 0),
(@PATH, 1, -3489.3108, 4154.572, 30.184837, NULL, 0),
(@PATH, 2, -3488.0776, 4164.248, 30.234852, NULL, 0),
(@PATH, 3, -3483.235, 4172.716, 30.184822, NULL, 0),
(@PATH, 4, -3475.521, 4178.6855, 30.184822, NULL, 0),
(@PATH, 5, -3466.1094, 4181.2495, 30.184824, NULL, 0),
(@PATH, 6, -3456.433, 4180.016, 30.18482, NULL, 0),
(@PATH, 7, -3447.9653, 4175.174, 30.184822, NULL, 0),
(@PATH, 8, -3441.9954, 4167.4595, 30.184818, NULL, 0),
(@PATH, 9, -3439.4316, 4158.048, 30.18482, NULL, 0),
(@PATH, 10, -3440.665, 4148.3716, 30.184822, NULL, 0),
(@PATH, 11, -3445.5073, 4139.904, 30.18483, NULL, 0),
(@PATH, 12, -3453.2214, 4133.934, 30.18484, NULL, 0),
(@PATH, 13, -3462.633, 4131.37, 30.178333, NULL, 0),
(@PATH, 14, -3472.3093, 4132.6035, 30.184835, NULL, 0),
(@PATH, 15, -3480.777, 4137.446, 30.184822, NULL, 0);

UPDATE `creature` SET `position_x`=-3486.747, `position_y`=4145.16, `position_z`=30.184822, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+534;
SET @ENTRY := 97844;
SET @PATHOFFSET := 24;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0229, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3463.3796, 4143.537, 30.184824, NULL, 0),
(@PATH, 1, -3472.3777, 4147.303, 30.184824, NULL, 0),
(@PATH, 2, -3479.2493, 4154.2266, 30.184822, NULL, 0),
(@PATH, 3, -3482.9487, 4163.2524, 30.184822, NULL, 0),
(@PATH, 4, -3482.912, 4173.007, 30.184822, NULL, 0),
(@PATH, 5, -3479.1458, 4182.005, 30.184822, NULL, 0),
(@PATH, 6, -3472.2227, 4188.8765, 30.184824, NULL, 0),
(@PATH, 7, -3463.1968, 4192.5757, 30.184822, NULL, 0),
(@PATH, 8, -3453.4421, 4192.5396, 30.18482, NULL, 0),
(@PATH, 9, -3444.4443, 4188.773, 30.184822, NULL, 0),
(@PATH, 10, -3437.5725, 4181.8496, 30.184822, NULL, 0),
(@PATH, 11, -3433.8733, 4172.8237, 30.184826, NULL, 0),
(@PATH, 12, -3433.9097, 4163.0693, 30.184818, NULL, 0),
(@PATH, 13, -3437.6763, 4154.0713, 30.184824, NULL, 0),
(@PATH, 14, -3444.5994, 4147.1997, 30.184824, NULL, 0),
(@PATH, 15, -3453.6252, 4143.5005, 30.184824, NULL, 0);

UPDATE `creature` SET `position_x`=-3463.3796, `position_y`=4143.537, `position_z`=30.184824, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+535;
SET @ENTRY := 97844;
SET @PATHOFFSET := 25;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0195, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3466.155, 4168.5884, 30.184826, NULL, 0),
(@PATH, 1, -3468.62, 4163.28, 30.18484, NULL, 0),
(@PATH, 2, -3468.8665, 4157.4326, 30.184837, NULL, 0),
(@PATH, 3, -3466.8562, 4151.936, 30.184837, NULL, 0),
(@PATH, 4, -3462.8955, 4147.627, 30.18483, NULL, 0),
(@PATH, 5, -3457.5874, 4145.1616, 30.184824, NULL, 0),
(@PATH, 6, -3451.7397, 4144.9155, 30.184826, NULL, 0),
(@PATH, 7, -3446.2432, 4146.926, 30.184824, NULL, 0),
(@PATH, 8, -3441.9343, 4150.886, 30.184824, NULL, 0),
(@PATH, 9, -3439.469, 4156.1943, 30.184824, NULL, 0),
(@PATH, 10, -3439.2227, 4162.042, 30.184818, NULL, 0),
(@PATH, 11, -3441.233, 4167.5386, 30.184818, NULL, 0),
(@PATH, 12, -3445.1936, 4171.8477, 30.184818, NULL, 0),
(@PATH, 13, -3450.502, 4174.313, 30.184822, NULL, 0),
(@PATH, 14, -3456.3494, 4174.559, 30.18482, NULL, 0),
(@PATH, 15, -3461.846, 4172.549, 30.184826, NULL, 0);

UPDATE `creature` SET `position_x`=-3466.155, `position_y`=4168.5884, `position_z`=30.184826, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+536;
SET @ENTRY := 97844;
SET @PATHOFFSET := 26;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0185, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3409.0562, 4127.7676, 30.86384, NULL, 0),
(@PATH, 1, -3413.7393, 4124.2573, 29.537167, NULL, 0),
(@PATH, 2, -3419.4094, 4122.806, 30.094742, NULL, 0),
(@PATH, 3, -3425.2031, 4123.6357, 30.003986, NULL, 0),
(@PATH, 4, -3430.2383, 4126.619, 30.177155, NULL, 0),
(@PATH, 5, -3433.7483, 4131.3027, 30.184788, NULL, 0),
(@PATH, 6, -3435.1992, 4136.9727, 30.184822, NULL, 0),
(@PATH, 7, -3434.3696, 4142.766, 30.18443, NULL, 0),
(@PATH, 8, -3431.3862, 4147.8013, 30.175888, NULL, 0),
(@PATH, 9, -3426.7031, 4151.3115, 30.1843, NULL, 0),
(@PATH, 10, -3421.033, 4152.762, 30.184834, NULL, 0),
(@PATH, 11, -3415.2393, 4151.933, 30.184784, NULL, 0),
(@PATH, 12, -3410.204, 4148.9497, 30.17265, NULL, 0),
(@PATH, 13, -3406.6938, 4144.266, 30.092161, NULL, 0),
(@PATH, 14, -3405.2432, 4138.596, 30.266127, NULL, 0),
(@PATH, 15, -3406.0725, 4132.8027, 30.641373, NULL, 0);

UPDATE `creature` SET `position_x`=-3409.0562, `position_y`=4127.7676, `position_z`=30.86384, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+537;
SET @ENTRY := 97844;
SET @PATHOFFSET := 27;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0200, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3468.6626, 4137.4214, 30.184824, NULL, 0),
(@PATH, 1, -3467.8489, 4131.6255, 30.18277, NULL, 0),
(@PATH, 2, -3464.8792, 4126.5825, 30.050247, NULL, 0),
(@PATH, 3, -3460.2053, 4123.0596, 29.655228, NULL, 0),
(@PATH, 4, -3454.5393, 4121.5933, 29.622692, NULL, 0),
(@PATH, 5, -3448.7434, 4122.407, 29.759499, NULL, 0),
(@PATH, 6, -3443.7002, 4125.377, 30.105673, NULL, 0),
(@PATH, 7, -3440.1772, 4130.0503, 30.183094, NULL, 0),
(@PATH, 8, -3438.7112, 4135.717, 30.184824, NULL, 0),
(@PATH, 9, -3439.525, 4141.5127, 30.18482, NULL, 0),
(@PATH, 10, -3442.4946, 4146.5557, 30.184824, NULL, 0),
(@PATH, 11, -3447.1685, 4150.0786, 30.184822, NULL, 0),
(@PATH, 12, -3452.8345, 4151.545, 30.18483, NULL, 0),
(@PATH, 13, -3458.6304, 4150.731, 30.18483, NULL, 0),
(@PATH, 14, -3463.6736, 4147.761, 30.184826, NULL, 0),
(@PATH, 15, -3467.1965, 4143.0874, 30.184826, NULL, 0);

UPDATE `creature` SET `position_x`=-3468.6626, `position_y`=4137.4214, `position_z`=30.184824, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+538;
SET @ENTRY := 97844;
SET @PATHOFFSET := 28;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0194, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3455.2756, 4164.8315, 30.184822, NULL, 0),
(@PATH, 1, -3455.9907, 4159.0225, 30.184824, NULL, 0),
(@PATH, 2, -3458.8745, 4153.9297, 30.18484, NULL, 0),
(@PATH, 3, -3463.4878, 4150.3276, 30.184837, NULL, 0),
(@PATH, 4, -3469.1282, 4148.7656, 30.184826, NULL, 0),
(@PATH, 5, -3474.937, 4149.481, 30.184824, NULL, 0),
(@PATH, 6, -3480.03, 4152.3647, 30.184822, NULL, 0),
(@PATH, 7, -3483.6316, 4156.978, 30.184822, NULL, 0),
(@PATH, 8, -3485.1938, 4162.618, 30.184822, NULL, 0),
(@PATH, 9, -3484.4785, 4168.4272, 30.184822, NULL, 0),
(@PATH, 10, -3481.595, 4173.52, 30.184822, NULL, 0),
(@PATH, 11, -3476.9817, 4177.1216, 30.184822, NULL, 0),
(@PATH, 12, -3471.3413, 4178.684, 30.184822, NULL, 0),
(@PATH, 13, -3465.5325, 4177.9688, 30.184826, NULL, 0),
(@PATH, 14, -3460.4395, 4175.085, 30.184822, NULL, 0),
(@PATH, 15, -3456.8376, 4170.4717, 30.184822, NULL, 0);

UPDATE `creature` SET `position_x`=-3455.2756, `position_y`=4164.8315, `position_z`=30.184822, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+539;
SET @ENTRY := 97844;
SET @PATHOFFSET := 29;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0239, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3431.65, 4118.5127, 29.938631, NULL, 0),
(@PATH, 1, -3436.333, 4115.0024, 31.197945, NULL, 0),
(@PATH, 2, -3442.0032, 4113.5513, 29.267843, NULL, 0),
(@PATH, 3, -3447.7969, 4114.381, 29.267843, NULL, 0),
(@PATH, 4, -3452.832, 4117.3643, 29.267843, NULL, 0),
(@PATH, 5, -3456.342, 4122.048, 29.63112, NULL, 0),
(@PATH, 6, -3457.793, 4127.718, 30.086647, NULL, 0),
(@PATH, 7, -3456.9634, 4133.511, 30.18484, NULL, 0),
(@PATH, 8, -3453.98, 4138.5464, 30.184826, NULL, 0),
(@PATH, 9, -3449.2969, 4142.0566, 30.184824, NULL, 0),
(@PATH, 10, -3443.6267, 4143.5073, 30.184824, NULL, 0),
(@PATH, 11, -3437.833, 4142.678, 30.184818, NULL, 0),
(@PATH, 12, -3432.7979, 4139.695, 30.184723, NULL, 0),
(@PATH, 13, -3429.2876, 4135.011, 30.184835, NULL, 0),
(@PATH, 14, -3427.837, 4129.3413, 30.18451, NULL, 0),
(@PATH, 15, -3428.6663, 4123.548, 29.947884, NULL, 0);

UPDATE `creature` SET `position_x`=-3431.65, `position_y`=4118.5127, `position_z`=29.938631, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+540;
SET @ENTRY := 97844;
SET @PATHOFFSET := 30;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0202, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3441.8015, 4148.6284, 30.184826, NULL, 0),
(@PATH, 1, -3436.1355, 4147.162, 30.184734, NULL, 0),
(@PATH, 2, -3431.4617, 4143.639, 30.184795, NULL, 0),
(@PATH, 3, -3428.492, 4138.5957, 30.184835, NULL, 0),
(@PATH, 4, -3427.6782, 4132.8003, 30.184834, NULL, 0),
(@PATH, 5, -3429.1443, 4127.134, 30.176758, NULL, 0),
(@PATH, 6, -3432.6672, 4122.4604, 29.987488, NULL, 0),
(@PATH, 7, -3437.7104, 4119.4907, 29.428677, NULL, 0),
(@PATH, 8, -3443.5063, 4118.677, 29.268158, NULL, 0),
(@PATH, 9, -3449.1724, 4120.143, 29.357605, NULL, 0),
(@PATH, 10, -3453.8462, 4123.666, 29.84185, NULL, 0),
(@PATH, 11, -3456.816, 4128.709, 30.151978, NULL, 0),
(@PATH, 12, -3457.6296, 4134.505, 30.184837, NULL, 0),
(@PATH, 13, -3456.1636, 4140.171, 30.184826, NULL, 0),
(@PATH, 14, -3452.6406, 4144.8447, 30.184824, NULL, 0),
(@PATH, 15, -3447.5974, 4147.8145, 30.184824, NULL, 0);

UPDATE `creature` SET `position_x`=-3441.8015, `position_y`=4148.6284, `position_z`=30.184826, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+541;
SET @ENTRY := 97844;
SET @PATHOFFSET := 31;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0386, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3490.5164, 4135.137, 30.283058, NULL, 0),
(@PATH, 1, -3482.2256, 4129.9976, 30.184822, NULL, 0),
(@PATH, 2, -3472.599, 4128.4224, 30.1717, NULL, 0),
(@PATH, 3, -3463.1025, 4130.651, 30.177216, NULL, 0),
(@PATH, 4, -3455.1816, 4136.3438, 30.184834, NULL, 0),
(@PATH, 5, -3450.0422, 4144.6343, 30.184822, NULL, 0),
(@PATH, 6, -3448.4668, 4154.2607, 30.184822, NULL, 0),
(@PATH, 7, -3450.6953, 4163.7573, 30.184822, NULL, 0),
(@PATH, 8, -3456.3882, 4171.678, 30.184822, NULL, 0),
(@PATH, 9, -3464.679, 4176.818, 30.184822, NULL, 0),
(@PATH, 10, -3474.3054, 4178.393, 30.184822, NULL, 0),
(@PATH, 11, -3483.802, 4176.165, 30.184822, NULL, 0),
(@PATH, 12, -3491.723, 4170.4717, 34.261574, NULL, 0),
(@PATH, 13, -3496.8623, 4162.181, 29.282732, NULL, 0),
(@PATH, 14, -3498.4377, 4152.5547, 35.94615, NULL, 0),
(@PATH, 15, -3496.2095, 4143.058, 32.612835, NULL, 0);

UPDATE `creature` SET `position_x`=-3490.5164, `position_y`=4135.137, `position_z`=30.283058, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+542;
SET @ENTRY := 97844;
SET @PATHOFFSET := 32;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0201, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3454.621, 4144.567, 30.184822, NULL, 0),
(@PATH, 1, -3448.955, 4143.1006, 30.184824, NULL, 0),
(@PATH, 2, -3444.2812, 4139.5776, 30.184828, NULL, 0),
(@PATH, 3, -3441.3115, 4134.534, 30.184835, NULL, 0),
(@PATH, 4, -3440.4978, 4128.739, 30.176489, NULL, 0),
(@PATH, 5, -3441.9639, 4123.0723, 29.841034, NULL, 0),
(@PATH, 6, -3445.4868, 4118.399, 29.268158, NULL, 0),
(@PATH, 7, -3450.53, 4115.429, 29.268158, NULL, 0),
(@PATH, 8, -3456.326, 4114.615, 29.268158, NULL, 0),
(@PATH, 9, -3461.992, 4116.0815, 29.268158, NULL, 0),
(@PATH, 10, -3466.6658, 4119.6045, 29.268158, NULL, 0),
(@PATH, 11, -3469.6355, 4124.6475, 29.98072, NULL, 0),
(@PATH, 12, -3470.4492, 4130.4434, 30.180405, NULL, 0),
(@PATH, 13, -3468.9832, 4136.1094, 30.184832, NULL, 0),
(@PATH, 14, -3465.4602, 4140.783, 30.184824, NULL, 0),
(@PATH, 15, -3460.417, 4143.753, 30.184824, NULL, 0);

UPDATE `creature` SET `position_x`=-3454.621, `position_y`=4144.567, `position_z`=30.184822, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+544;
SET @ENTRY := 97844;
SET @PATHOFFSET := 33;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0201, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3453.8171, 4139.1553, 30.184826, NULL, 0),
(@PATH, 1, -3448.1511, 4137.689, 30.184832, NULL, 0),
(@PATH, 2, -3443.4773, 4134.166, 30.184837, NULL, 0),
(@PATH, 3, -3440.5076, 4129.1226, 30.181318, NULL, 0),
(@PATH, 4, -3439.6938, 4123.327, 29.95104, NULL, 0),
(@PATH, 5, -3441.16, 4117.6606, 29.26817, NULL, 0),
(@PATH, 6, -3444.6829, 4112.9873, 29.26817, NULL, 0),
(@PATH, 7, -3449.726, 4110.0176, 29.26817, NULL, 0),
(@PATH, 8, -3455.522, 4109.2036, 29.26817, NULL, 0),
(@PATH, 9, -3461.188, 4110.67, 29.26817, NULL, 0),
(@PATH, 10, -3465.8618, 4114.193, 29.26817, NULL, 0),
(@PATH, 11, -3468.8315, 4119.236, 29.26817, NULL, 0),
(@PATH, 12, -3469.6453, 4125.0317, 30.02641, NULL, 0),
(@PATH, 13, -3468.1792, 4130.6978, 30.180454, NULL, 0),
(@PATH, 14, -3464.6562, 4135.3716, 30.184835, NULL, 0),
(@PATH, 15, -3459.613, 4138.3413, 30.184826, NULL, 0);

UPDATE `creature` SET `position_x`=-3453.8171, `position_y`=4139.1553, `position_z`=30.184826, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Call the Seas
SET @MOVERGUID := @CGUID+551;
SET @ENTRY := 97844;
SET @PATHOFFSET := 34;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.0162, 'Call the Seas - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -3475.1748, 4126.948, 30.156826, NULL, 0),
(@PATH, 1, -3474.1218, 4132.705, 30.184828, NULL, 0),
(@PATH, 2, -3470.9458, 4137.621, 30.184824, NULL, 0),
(@PATH, 3, -3466.1304, 4140.9478, 30.184824, NULL, 0),
(@PATH, 4, -3460.4084, 4142.178, 30.184824, NULL, 0),
(@PATH, 5, -3454.6511, 4141.125, 30.184824, NULL, 0),
(@PATH, 6, -3449.735, 4137.949, 30.184832, NULL, 0),
(@PATH, 7, -3446.409, 4133.1333, 30.18484, NULL, 0),
(@PATH, 8, -3445.1785, 4127.4116, 30.155113, NULL, 0),
(@PATH, 9, -3446.2314, 4121.6543, 29.622755, NULL, 0),
(@PATH, 10, -3449.4075, 4116.7383, 28.65263, NULL, 0),
(@PATH, 11, -3454.2231, 4113.412, 28.37797, NULL, 0),
(@PATH, 12, -3459.945, 4112.1816, 28.274307, NULL, 0),
(@PATH, 13, -3465.7021, 4113.235, 28.763248, NULL, 0),
(@PATH, 14, -3470.6182, 4116.4106, 29.19281, NULL, 0),
(@PATH, 15, -3473.9446, 4121.226, 29.777798, NULL, 0);

UPDATE `creature` SET `position_x`=-3475.1748, `position_y`=4126.948, `position_z`=30.156826, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
