-- 
SET @CGUID := 651534;
SET @OGUID := 400467;
SET @POOL := 645018;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+85;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 102279, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4636.86181640625, 3963.9150390625, 87.057403564453125, 1.675516128540039062, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Area: Violet Hold - Difficulty: 0) (Auras: )
(@CGUID+1, 102267, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4623.08349609375, 4059.59716796875, 82.72406005859375, 4.78220224380493164, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Intro) (Area: Violet Hold - Difficulty: 0) (Auras: 201859 - Teleportation Portal Visual)
(@CGUID+2, 102266, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 1, 4595.74853515625, 4011.828125, 83.40316009521484375, 0, 7200, 0, 0, 17040, 0, 0, 0, 0, 0, 46597), -- Violet Hold Guard (Area: Violet Hold - Difficulty: 0)
(@CGUID+3, 53488, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4586.45556640625, 4015.295166015625, 83.551513671875, 0, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- Summon Enabler Stalker (Area: Violet Hold - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+4, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4645.15283203125, 4066.197998046875, 95.06452178955078125, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: 0)
(@CGUID+5, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4621.81787109375, 4060.1875, 91.01959228515625, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: 0)
(@CGUID+6, 102489, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4638.4287109375, 3989.895751953125, 135.4737396240234375, 0, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Web Invisible Stalker (Area: Violet Hold - Difficulty: 0)
(@CGUID+7, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4603.48291015625, 4040.1650390625, 78.03725433349609375, 2.216568231582641601, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: 0)
(@CGUID+8, 102279, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4604.43212890625, 3980.732666015625, 78.04087066650390625, 0.907571196556091308, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Area: Violet Hold - Difficulty: 0)
(@CGUID+9, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4602.7412109375, 4062.913330078125, 91.01959228515625, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: 0)
(@CGUID+10, 102281, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4667.37060546875, 4058.247314453125, 86.5398712158203125, 3.96189737319946289, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Area: Violet Hold - Difficulty: 0)
(@CGUID+11, 2110, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4585.65087890625, 4053.270751953125, 78.03722381591796875, 0.698131680488586425, 7200, 0, 0, 1, 0, 0, 0, 0, 0, 46597), -- Black Rat (Area: Violet Hold - Difficulty: 0)
(@CGUID+12, 102671, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4654.43603515625, 4053.846435546875, 78.0273590087890625, 0.640317916870117187, 7200, 0, 0, 392300, 1534, 0, 0, 0, 0, 46597), -- Prison Cell (Area: Violet Hold - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+13, 174272, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4600.18310546875, 4010.10498046875, 83.39923858642578125, 1.208429574966430664, 7200, 0, 0, 59, 0, 0, 0, 0, 0, 46597), -- Violet Hold Guard (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+14, 14881, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4581.17431640625, 3997.00341796875, 83.6361541748046875, 0.244346097111701965, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 46597), -- Spider (Area: Violet Hold - Difficulty: 0)
(@CGUID+15, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4671.20068359375, 3976.02783203125, 97.45294189453125, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: 0)
(@CGUID+16, 102489, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4602.6962890625, 3990.90966796875, 136.336700439453125, 0, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Web Invisible Stalker (Area: Violet Hold - Difficulty: 0)
(@CGUID+17, 30883, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4602.009765625, 4015.8515625, 83.39333343505859375, 2.111848354339599609, 7200, 0, 0, 1706, 852, 0, 0, 0, 0, 46597), -- Dalaran Prison Event Controller (Area: Violet Hold - Difficulty: 0)
(@CGUID+18, 102281, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4667.05224609375, 3981.968017578125, 70.01569366455078125, 2.251474618911743164, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Area: Violet Hold - Difficulty: 0)
(@CGUID+19, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4587.04931640625, 4024.19091796875, 83.5317840576171875, 5.98647928237915039, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: 0)
(@CGUID+20, 102279, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4682.27587890625, 4013.682373046875, 91.80926513671875, 3.054326057434082031, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Area: Violet Hold - Difficulty: 0)
(@CGUID+21, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4640.01025390625, 4041.88720703125, 78.03973388671875, 1.675516128540039062, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: 0)
(@CGUID+22, 102278, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 1, 4577.13525390625, 4009.958251953125, 83.6949615478515625, 2.39110112190246582, 7200, 0, 0, 15692, 1534, 0, 0, 0, 0, 46597), -- Lieutenant Sinclari (Area: Violet Hold - Difficulty: 0)
(@CGUID+23, 53488, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4561.28369140625, 4013.854248046875, 83.75522613525390625, 0, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- Summon Enabler Stalker (Area: Violet Hold - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+24, 102671, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4621.337890625, 4079.56591796875, 82.72406005859375, 0.900292038917541503, 7200, 0, 0, 392300, 1534, 0, 0, 0, 0, 46597), -- Prison Cell (Area: Violet Hold - Difficulty: 0)
(@CGUID+25, 14881, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4581.67041015625, 4043.748291015625, 83.42809295654296875, 0.689188063144683837, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 46597), -- Spider (Area: Violet Hold - Difficulty: 0)
(@CGUID+26, 102279, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4653.47119140625, 4041.60595703125, 78.08148193359375, 3.560471534729003906, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Area: Violet Hold - Difficulty: 0)
(@CGUID+27, 174272, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4591.5322265625, 4002.098876953125, 83.45534515380859375, 3.735004663467407226, 7200, 0, 0, 59, 0, 0, 0, 0, 0, 46597), -- Violet Hold Guard (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+28, 102246, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4693.13916015625, 3957.834228515625, 70.253570556640625, 2.367903947830200195, 7200, 0, 0, 145888, 0, 0, 0, 0, 0, 46597), -- Anub'esset (Area: Violet Hold - Difficulty: 0)
(@CGUID+29, 102266, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 1, 4596.71337890625, 4008.546875, 83.39502716064453125, 0.471238881349563598, 7200, 0, 0, 17040, 0, 0, 0, 0, 0, 46597), -- Violet Hold Guard (Area: Violet Hold - Difficulty: 0) (Auras: )
(@CGUID+30, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4622.45166015625, 3995.241455078125, 78.34393310546875, 0.698131680488586425, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: 0)
(@CGUID+31, 101976, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 1, 4652.85400390625, 4057.385498046875, 78.0272216796875, 4.254158973693847656, 7200, 0, 0, 140417, 0, 0, 0, 0, 0, 46597), -- Millificent Manastorm (Area: Violet Hold - Difficulty: 0)
(@CGUID+32, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4596.07470703125, 4015.25439453125, 92.01548004150390625, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: 0)
(@CGUID+33, 102281, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4663.5849609375, 4014.958251953125, 82.72406768798828125, 3.019419670104980468, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Area: Violet Hold - Difficulty: 0)
(@CGUID+34, 102431, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4616.37158203125, 4082.21875, 82.720733642578125, 4.981614112854003906, 7200, 0, 0, 205155, 1640, 0, 0, 0, 0, 46597), -- Blood-Princess Thal'ena (Area: Violet Hold - Difficulty: 0) (Auras: 203456 - Congealed Blood Trigger)
(@CGUID+35, 102671, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4632.2666015625, 3948.780517578125, 87.057403564453125, 3.734773159027099609, 7200, 0, 0, 392300, 1534, 0, 0, 0, 0, 46597), -- Prison Cell (Area: Violet Hold - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+36, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4604.32275390625, 3979.53466796875, 78.0414581298828125, 4.363323211669921875, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: 0)
(@CGUID+37, 174272, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4599.85791015625, 3993.451416015625, 78.0371856689453125, 2.408554315567016601, 7200, 0, 0, 59, 0, 0, 0, 0, 0, 46597), -- Violet Hold Guard (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+38, 32204, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4673.90478515625, 4011.444580078125, 91.8008880615234375, 5.009094715118408203, 7200, 0, 0, 6824, 852, 0, 0, 0, 0, 46597), -- Lieutenant Sinclari (Area: Violet Hold - Difficulty: 0)
(@CGUID+39, 101950, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4639.02685546875, 3933.318603515625, 87.057403564453125, 1.611536860466003417, 7200, 0, 0, 127652, 1640, 0, 0, 0, 0, 46597), -- Mindflayer Kaahrj (Area: Violet Hold - Difficulty: 0)
(@CGUID+40, 102267, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4685.84130859375, 4013.803955078125, 91.818603515625, 3.124139308929443359, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Intro) (Area: Violet Hold - Difficulty: 0) (Auras: 201859 - Teleportation Portal Visual)
(@CGUID+41, 102266, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 1, 4595.27587890625, 4016.592041015625, 83.4134368896484375, 0.139626339077949523, 7200, 0, 0, 17040, 0, 0, 0, 0, 0, 46597), -- Violet Hold Guard (Area: Violet Hold - Difficulty: 0)
(@CGUID+42, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4631.13916015625, 4023.36279296875, 77.85162353515625, 5.969026088714599609, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: 0)
(@CGUID+43, 4075, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4671.87353515625, 4017.282958984375, 78.05077362060546875, 4.363323211669921875, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 46597), -- Rat (Area: Violet Hold - Difficulty: 0)
(@CGUID+44, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4584.236328125, 4003.26904296875, 91.01959228515625, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: 0)
(@CGUID+45, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4677.80224609375, 4030.20751953125, 97.45294189453125, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: 0)
(@CGUID+46, 102489, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4647.46630859375, 4045.389892578125, 134.9365692138671875, 0, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Web Invisible Stalker (Area: Violet Hold - Difficulty: 0)
(@CGUID+47, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4651.77978515625, 4015.51220703125, 78.0357208251953125, 2.740166902542114257, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: 0)
(@CGUID+48, 102279, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4623.70556640625, 4060.673583984375, 82.72406768798828125, 4.345870018005371093, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Area: Violet Hold - Difficulty: 0)
(@CGUID+49, 102267, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4638.1552734375, 3962.079833984375, 87.057403564453125, 1.710422635078430175, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Teleportation Portal (Intro) (Area: Violet Hold - Difficulty: 0) (Auras: 201859 - Teleportation Portal Visual)
(@CGUID+50, 174272, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4614.96337890625, 4024.397705078125, 78.036407470703125, 4.78220224380493164, 7200, 0, 0, 59, 0, 0, 0, 0, 0, 46597), -- Violet Hold Guard (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+51, 102266, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 1, 4596.67431640625, 4020.19091796875, 83.3965301513671875, 0.157079637050628662, 7200, 0, 0, 17040, 0, 0, 0, 0, 0, 46597), -- Violet Hold Guard (Area: Violet Hold - Difficulty: 0)
(@CGUID+52, 102671, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4675.4599609375, 3962.05908203125, 70.0167999267578125, 4.826772689819335937, 7200, 0, 0, 392300, 1534, 0, 0, 0, 0, 46597), -- Prison Cell (Area: Violet Hold - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+53, 30896, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4568.7041015625, 4015.2666015625, 91.495941162109375, 0, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Prison Door Seal (Area: Violet Hold - Difficulty: 0)
(@CGUID+54, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4621.81787109375, 4060.1875, 91.01959228515625, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: 0)
(@CGUID+55, 101995, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4682.17724609375, 4076.763916015625, 86.59468841552734375, 4.129471778869628906, 7200, 0, 0, 145888, 100, 0, 0, 0, 0, 46597), -- Festerface (Area: Violet Hold - Difficulty: 0)
(@CGUID+56, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4638.59228515625, 3961.345458984375, 95.35567474365234375, 0, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: 0)
(@CGUID+57, 174272, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4592.48291015625, 4021.944580078125, 83.4507598876953125, 4.363323211669921875, 7200, 0, 0, 59, 0, 0, 0, 0, 0, 46597), -- Violet Hold Guard (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+58, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4601.93212890625, 4060.710205078125, 82.72406768798828125, 3.089232683181762695, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: 0)
(@CGUID+59, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4654.890625, 3966.881103515625, 97.45294189453125, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: 0)
(@CGUID+60, 102489, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4602.2900390625, 4045.389892578125, 134.9365692138671875, 0, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Web Invisible Stalker (Area: Violet Hold - Difficulty: 0)
(@CGUID+61, 102671, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4583.369140625, 3975.39501953125, 81.448089599609375, 2.918343067169189453, 7200, 0, 0, 392300, 1534, 0, 0, 0, 0, 46597), -- Prison Cell (Area: Violet Hold - Difficulty: 0)
(@CGUID+62, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4660.69189453125, 4058.830810546875, 95.06452178955078125, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+63, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4639.02978515625, 3961.151123046875, 87.057403564453125, 0.628318548202514648, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+64, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4675.49462890625, 4010.005126953125, 96.41754150390625, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+65, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4682.44970703125, 3993.684814453125, 97.45294189453125, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+66, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4632.609375, 4070.142333984375, 91.01959228515625, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+67, 101951, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4584.24658203125, 3953.358642578125, 78.0545654296875, 0.867478907108306884, 7200, 0, 0, 159565, 0, 0, 0, 0, 0, 46597), -- Shivermaw (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+68, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4584.6630859375, 4025.52685546875, 91.01959228515625, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+69, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4627.93603515625, 4068.65625, 82.72406768798828125, 0.418879032135009765, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+70, 92879, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4673.43408203125, 4046.756103515625, 95.06452178955078125, 4.662285327911376953, 7200, 0, 0, 18771, 0, 0, 0, 0, 0, 46597), -- SLG Generic Stalker (Gigantic AOI) (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+71, 4075, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4668.9912109375, 4052.669921875, 78.1994781494140625, 3.540973663330078125, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 46597), -- Rat (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+72, 104529, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4667.38525390625, 4050.752685546875, 78.16600799560546875, 3.988003730773925781, 7200, 0, 0, 19615, 0, 0, 0, 0, 0, 46597), -- Lyndras (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+73, 4075, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4671.09619140625, 4048.875, 86.6663818359375, 0.073929935693740844, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 46597), -- Rat (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+74, 30857, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4673.92041015625, 4034.69091796875, 76.7999420166015625, 3.351032257080078125, 7200, 0, 0, 1706, 0, 0, 0, 0, 0, 46597), -- Defense Dummy Target (Area: Violet Hold - Difficulty: Mythic)
(@CGUID+75, 30837, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4634.33056640625, 4013.876708984375, 123.175048828125, 3.071779489517211914, 7200, 0, 0, 1889, 0, 0, 0, 0, 0, 46597), -- Defense System (Area: Violet Hold - Difficulty: Mythic) (Auras: 57886 - Defense System Spawn Effect)
(@CGUID+76, 102620, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4708.05908203125, 4013.868896484375, 91.75376129150390625, 3.013336896896362304, 7200, 0, 0, 78450, 38010, 0, 0, 0, 0, 46597), -- Taldath the Destroyer (Area: Violet Hold - Difficulty: Mythic)
-- pool 1
(@CGUID+77, 102270, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4609.90478515625, 4030.73779296875, 78.0367431640625, 4.084070205688476562, 7200, 0, 0, 4260, 3068, 0, 0, 0, 0, 46597), -- Eredar Invader (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+78, 102272, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4609.90478515625, 4030.73779296875, 78.0367431640625, 4.084070205688476562, 7200, 0, 0, 4260, 3068, 0, 0, 0, 0, 46597), -- Felguard Destroyer (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+79, 102273, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4609.90478515625, 4030.73779296875, 78.0367431640625, 4.084070205688476562, 7200, 0, 0, 4260, 3068, 0, 0, 0, 0, 46597), -- Doomguard Infiltrator (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
-- pool 2
(@CGUID+80, 102270, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4601.62353515625, 4033.984375, 78.0372161865234375, 2.35619449615478515, 7200, 0, 0, 4260, 3068, 0, 0, 0, 0, 46597), -- Eredar Invader (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+81, 102272, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4601.62353515625, 4033.984375, 78.0372161865234375, 2.35619449615478515, 7200, 0, 0, 4260, 3068, 0, 0, 0, 0, 46597), -- Felguard Destroyer (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+82, 102273, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4601.62353515625, 4033.984375, 78.0372161865234375, 2.35619449615478515, 7200, 0, 0, 4260, 3068, 0, 0, 0, 0, 46597), -- Doomguard Infiltrator (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
-- pool 3
(@CGUID+83, 102270, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4604.60791015625, 3994.34033203125, 78.03719329833984375, 2.39110112190246582, 7200, 0, 0, 4260, 3068, 0, 0, 0, 0, 46597), -- Eredar Invader (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+84, 102272, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4604.60791015625, 3994.34033203125, 78.03719329833984375, 2.39110112190246582, 7200, 0, 0, 4260, 3068, 0, 0, 0, 0, 46597), -- Felguard Destroyer (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+85, 102273, 1544, 7996, 7996, '1,2,23', '0', 0, 0, 0, 4604.60791015625, 3994.34033203125, 78.03719329833984375, 2.39110112190246582, 7200, 0, 0, 4260, 3068, 0, 0, 0, 0, 46597); -- Doomguard Infiltrator (Area: Violet Hold - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOL+0 AND @POOL+2;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL+0, 1, 'Violet Hold Broken Isles - Feign Death Demon'),
(@POOL+1, 1, 'Violet Hold Broken Isles - Feign Death Demon'),
(@POOL+2, 1, 'Violet Hold Broken Isles - Feign Death Demon');

DELETE FROM `pool_members` WHERE `type`=0 AND (`poolSpawnId` BETWEEN @POOL+0 AND @POOL+2);
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, @CGUID+77, @POOL+0, 0, 'Violet Hold Broken Isles - Feign Death Demon - Eredar Invader'),
(0, @CGUID+78, @POOL+0, 0, 'Violet Hold Broken Isles - Feign Death Demon - Felguard Destroyer'),
(0, @CGUID+79, @POOL+0, 0, 'Violet Hold Broken Isles - Feign Death Demon - Doomguard Infiltrator'),
(0, @CGUID+80, @POOL+1, 0, 'Violet Hold Broken Isles - Feign Death Demon - Eredar Invader'),
(0, @CGUID+81, @POOL+1, 0, 'Violet Hold Broken Isles - Feign Death Demon - Felguard Destroyer'),
(0, @CGUID+82, @POOL+1, 0, 'Violet Hold Broken Isles - Feign Death Demon - Doomguard Infiltrator'),
(0, @CGUID+83, @POOL+2, 0, 'Violet Hold Broken Isles - Feign Death Demon - Eredar Invader'),
(0, @CGUID+84, @POOL+2, 0, 'Violet Hold Broken Isles - Feign Death Demon - Felguard Destroyer'),
(0, @CGUID+85, @POOL+2, 0, 'Violet Hold Broken Isles - Feign Death Demon - Doomguard Infiltrator');

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+85;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'), -- 102273 (Doomguard Infiltrator) - Permanent Feign Death
(@CGUID+78, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'), -- 102273 (Doomguard Infiltrator) - Permanent Feign Death
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'), -- 102273 (Doomguard Infiltrator) - Permanent Feign Death
(@CGUID+80, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'), -- 102273 (Doomguard Infiltrator) - Permanent Feign Death
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'), -- 102273 (Doomguard Infiltrator) - Permanent Feign Death
(@CGUID+82, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'), -- 102273 (Doomguard Infiltrator) - Permanent Feign Death
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'), -- 102273 (Doomguard Infiltrator) - Permanent Feign Death
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'), -- 102273 (Doomguard Infiltrator) - Permanent Feign Death
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'); -- 102273 (Doomguard Infiltrator) - Permanent Feign Death

DELETE FROM `creature_template_addon` WHERE `entry` IN (102282 /*102282 (Lord Malgath) - Fel Shield*/, 101951 /*101951 (Shivermaw)*/, 101995 /*101995 (Festerface)*/, 101950 /*101950 (Mindflayer Kaahrj)*/, 102431 /*102431 (Blood-Princess Thal'ena) - Congealed Blood Trigger*/, 101976 /*101976 (Millificent Manastorm)*/, 102246 /*102246 (Anub'esset)*/, 102273 /*102273 (Doomguard Infiltrator) - Permanent Feign Death*/, 174272 /*174272 (Violet Hold Guard) - Permanent Feign Death*/, 102671 /*102671 (Prison Cell)*/, 102269 /*102269 (Felstalker Ravener) - Arcane Empowerment*/, 102281 /*102281 (Teleportation Portal)*/, 92879 /*92879 (SLG Generic Stalker (Gigantic AOI))*/, 102267 /*102267 (Teleportation Portal (Intro)) - Teleportation Portal Visual*/, 102279 /*102279 (Teleportation Portal)*/, 113813 /*113813 (Lieutenant Sinclari)*/, 102266 /*102266 (Violet Hold Guard) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 118524 /*118524 (Dalaran Crystal)*/, 101436 /*101436 (Wormhole)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(102282, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '202311'), -- 102282 (Lord Malgath) - Fel Shield
(101951, 0, 0, 0, 1, 0, 0, 0, 0, 4, ''), -- 101951 (Shivermaw)
(101995, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''), -- 101995 (Festerface)
(101950, 0, 0, 0, 1, 0, 0, 0, 0, 4, ''), -- 101950 (Mindflayer Kaahrj)
(102431, 0, 0, 0, 1, 0, 0, 0, 0, 0, '203456'), -- 102431 (Blood-Princess Thal'ena) - Congealed Blood Trigger
(101976, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''), -- 101976 (Millificent Manastorm)
(102246, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''), -- 102246 (Anub'esset)
(174272, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266'), -- 174272 (Violet Hold Guard) - Permanent Feign Death
(102671, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- 102671 (Prison Cell)
(102269, 0, 0, 0, 1, 0, 0, 0, 0, 0, '58469'), -- 102269 (Felstalker Ravener) - Arcane Empowerment
(102281, 0, 0, 50331648, 1, 0, 0, 0, 0, 4, ''), -- 102281 (Teleportation Portal)
(92879, 0, 0, 0, 1, 0, 0, 0, 0, 5, ''), -- 92879 (SLG Generic Stalker (Gigantic AOI))
(102267, 0, 0, 50331648, 1, 0, 0, 0, 0, 4, '201859'), -- 102267 (Teleportation Portal (Intro)) - Teleportation Portal Visual
(102279, 0, 0, 50331648, 1, 0, 0, 0, 0, 4, ''), -- 102279 (Teleportation Portal)
(113813, 0, 0, 0, 1, 0, 11848, 0, 0, 3, ''), -- 113813 (Lieutenant Sinclari)
(118524, 0, 0, 50331648, 1, 0, 5517, 0, 0, 4, ''), -- 118524 (Dalaran Crystal)
(101436, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''); -- 101436 (Wormhole)

UPDATE `creature_template_addon` SET `auras`='57886' WHERE `entry`=30837; -- 30837 (Defense System) - Defense System Spawn Effect
UPDATE `creature_template_addon` SET `auras`='223113' WHERE `entry`=35845; -- 35845 (Dave's Industrial Light and Magic Bunny (Small)(Sessile)) - Void Bunny

UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry` IN(102270, 102272, 102273);
UPDATE `creature` SET `unit_flags`=570688256, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `guid` BETWEEN @CGUID+77 AND @CGUID+85;
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x80 WHERE `entry`=102671; -- Prison Cell

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+51;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 246993, 1544, 7996, 7996, '1,2,23', '0', 0, 4701.841796875, 4014.676025390625, 96.7199859619140625, 4.67504119873046875, 0, 0, -0.72018718719482421, 0.69377976655960083, 7200, 255, 1, 46597), -- Cell (Area: Violet Hold - Difficulty: 0)
(@OGUID+1, 193611, 1544, 7996, 7996, '1,2,23', '0', 0, 4608.369140625, 3959.9072265625, 79.4605560302734375, 1.865028858184814453, 0, 0, 0.803120613098144531, 0.595816493034362792, 7200, 255, 1, 46597), -- Activation Crystal (Area: Violet Hold - Difficulty: 0)
(@OGUID+2, 246992, 1544, 7996, 7996, '1,2,23', '0', 0, 4699.0615234375, 4033.985107421875, 96.71999359130859375, 5.016513824462890625, 0, 0, -0.59183692932128906, 0.806057691574096679, 7200, 255, 1, 46597), -- Cell (Area: Violet Hold - Difficulty: 0)
(@OGUID+3, 246999, 1544, 7996, 7996, '1,2,23', '0', 0, 4591.7646484375, 3963.48193359375, 88.60955047607421875, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 7200, 255, 1, 46597), -- Cell (Area: Violet Hold - Difficulty: 0)
(@OGUID+4, 246998, 1544, 7996, 7996, '1,2,23', '0', 0, 4675.86962890625, 4070.06494140625, 94.230194091796875, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 7200, 255, 1, 46597), -- Cell (Area: Violet Hold - Difficulty: 0)
(@OGUID+5, 246997, 1544, 7996, 7996, '1,2,23', '0', 0, 4616.7353515625, 4080.392822265625, 86.94776153564453125, 0.289968609809875488, 0, 0, 0.144476890563964843, 0.989508211612701416, 7200, 255, 1, 46597), -- Cell (Area: Violet Hold - Difficulty: 0)
(@OGUID+6, 246996, 1544, 7996, 7996, '1,2,23', '0', 0, 4636.2998046875, 4082.633544921875, 86.94776153564453125, 6.225835323333740234, 0, 0, -0.0286712646484375, 0.99958890676498413, 7200, 255, 1, 46597), -- Cell (Area: Violet Hold - Difficulty: 0)
(@OGUID+7, 247002, 1544, 7996, 7996, '1,2,23', '0', 0, 4566.87353515625, 4015.322265625, 83.67188262939453125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 46597), -- Prison Seal (Area: Violet Hold - Difficulty: 0)
(@OGUID+8, 193611, 1544, 7996, 7996, '1,2,23', '0', 0, 4591.994140625, 3992.018310546875, 79.78208160400390625, 5.616818428039550781, 0, 0, -0.32705307006835937, 0.945005953311920166, 7200, 255, 1, 46597), -- Activation Crystal (Area: Violet Hold - Difficulty: 0)
(@OGUID+9, 247385, 1544, 7996, 7996, '1,2,23', '0', 0, 4681.1748046875, 3967.490478515625, 76.2686004638671875, 3.979842185974121093, 0, 0, -0.91344547271728515, 0.406961113214492797, 7200, 255, 1, 46597), -- Cell (Area: Violet Hold - Difficulty: 0)
(@OGUID+10, 247000, 1544, 7996, 7996, '1,2,23', '0', 0, 4639.353515625, 3945.333740234375, 96.978729248046875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 46597), -- Cell (Area: Violet Hold - Difficulty: 0)
(@OGUID+11, 247005, 1544, 7996, 7996, '1,2,23', '0', 0, 4664.908203125, 4048.2421875, 80.44493865966796875, 5.636052131652832031, 0, 0, -0.31795024871826171, 0.948107421398162841, 7200, 255, 1, 46597), -- Prison Barrier (Area: Violet Hold - Difficulty: 0)
(@OGUID+12, 193611, 1544, 7996, 7996, '1,2,23', '0', 0, 4592.17626953125, 4036.607666015625, 79.69947052001953125, 0.653663218021392822, 0, 0, 0.321043968200683593, 0.94706428050994873, 7200, 255, 1, 46597), -- Activation Crystal (Area: Violet Hold - Difficulty: 0)
(@OGUID+13, 252248, 1544, 7996, 7996, '1,2,23', '0', 0, 4546.60595703125, 4014.895751953125, 87.03781890869140625, 0, 0, 0, 0, 1, 7200, 255, 1, 46597), -- Instance Portal (Area: Violet Hold - Difficulty: 0)
(@OGUID+14, 193611, 1544, 7996, 7996, '1,2,23', '0', 0, 4599.2568359375, 4055.4228515625, 79.55013275146484375, 5.07584238052368164, 0, 0, -0.56766891479492187, 0.823256969451904296, 7200, 255, 1, 46597), -- Activation Crystal (Area: Violet Hold - Difficulty: 0)
(@OGUID+15, 193615, 1544, 7996, 7996, '1,2,23', '0', 0, 4572.60595703125, 4008.77783203125, 84.98152923583984375, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 7200, 255, 1, 46597), -- Intro Activation Crystal (Area: Violet Hold - Difficulty: 0)
(@OGUID+16, 247544, 1544, 7996, 7996, '1,2,23', '0', 0, 4646.22314453125, 4038.94873046875, 77.64992523193359375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 46597), -- Doodad_7DU_VioletHold_trapdoor001 (Area: Violet Hold - Difficulty: 0)
(@OGUID+17, 246990, 1544, 7996, 7996, '1,2,23', '0', 0, 4652.23828125, 4056.06201171875, 80.44493865966796875, 5.838570594787597656, 0, 0, -0.22048091888427734, 0.975391268730163574, 7200, 255, 1, 46597), -- Cell (Area: Violet Hold - Difficulty: 0)
(@OGUID+18, 246995, 1544, 7996, 7996, '1,2,23', '0', 0, 4598.8564453125, 4072.354248046875, 86.94776153564453125, 0.546741485595703125, 0, 0, 0.269978523254394531, 0.962866365909576416, 7200, 255, 1, 46597), -- Cell (Area: Violet Hold - Difficulty: 0)
(@OGUID+19, 246994, 1544, 7996, 7996, '1,2,23', '0', 0, 4698.599609375, 3996.1171875, 96.7199859619140625, 4.372541427612304687, 0, 0, -0.81649971008300781, 0.577345848083496093, 7200, 255, 1, 46597); -- Cell (Area: Violet Hold - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+51;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cell
(@OGUID+1, 0, 0, 0, 1, 3661, 0), -- Activation Crystal
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cell
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cell
(@OGUID+4, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cell
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cell
(@OGUID+6, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cell
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 0), -- Prison Seal
(@OGUID+8, 0, 0, 0, 1, 3661, 0), -- Activation Crystal
(@OGUID+9, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cell
(@OGUID+10, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cell
(@OGUID+11, 0, 0, 1, -0.00000004371138828, 0, 0), -- Prison Barrier
(@OGUID+12, 0, 0, 0, 1, 3661, 0), -- Activation Crystal
(@OGUID+14, 0, 0, 0, 1, 3661, 0), -- Activation Crystal
(@OGUID+16, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_VioletHold_trapdoor001
(@OGUID+17, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cell
(@OGUID+18, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cell
(@OGUID+19, 0, 0, 1, -0.00000004371138828, 0, 0); -- Cell

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=23 AND `Entry` IN (2110,4075,14881,30857,30883,30896,32204,53488,92879,101950,101951,101976,101995,102246,102266,102267,102269,102270,102272,102273,102278,102279,102281,102431,102489,102671));
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=1 AND `Entry` IN (103672,102446,103561,112741,112739,102398,102372,103312,102373,102335,102659,102336,103146,102397,102400,102395,103450,43499,102302,102273,102246,32204,101995,102269,102281,101976,102431,101950,4075,102267,102270,53488,102278,30896,102279,102272,30883,101951,174272,14881,102671,102266,92879,102489,30857));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(103672, 1, 0, 0, 446, 46366),
(102446, 1, 0, 0, 485, 46366),
(103561, 1, 0, 0, 485, 46366),
(112741, 1, 0, 0, 485, 46366),
(112739, 1, 0, 0, 485, 46366),
(102398, 1, 0, 0, 485, 46366),
(102372, 1, 0, 0, 485, 46366),
(103312, 1, 0, 0, 446, 46366),
(102373, 1, 0, 0, 485, 46366),
(102335, 1, 0, 0, 485, 46366),
(102659, 1, 0, 0, 446, 46366),
(102336, 1, 0, 0, 485, 46366),
(103146, 1, 0, 0, 446, 46366),
(102397, 1, 0, 0, 485, 46366),
(102400, 1, 0, 0, 485, 46366),
(102395, 1, 0, 0, 485, 46366),
(103450, 1, 0, 0, 446, 46366),
(43499, 1, 0, 0, 482, 46366),
(102302, 1, 0, 0, 485, 46366),
(102273, 1, 0, 0, 485, 46366),
(102246, 1, 0, 0, 485, 46366),
(32204, 1, 0, 0, 247, 46366),
(101995, 1, 0, 0, 485, 46366),
(102269, 1, 0, 0, 485, 46366),
(102281, 1, 0, 0, 446, 46366),
(101976, 1, 0, 0, 485, 46366),
(102431, 1, 0, 0, 485, 46366),
(101950, 1, 0, 0, 485, 46366),
(4075, 1, 0, 0, 81, 46366),
(102267, 1, 0, 0, 446, 46366),
(102270, 1, 0, 0, 485, 46366),
(53488, 1, 0, 0, 181, 46366),
(102278, 1, 2, 2, 446, 46366),
(30896, 1, 0, 0, 247, 46366),
(102279, 1, 0, 0, 446, 46366),
(102272, 1, 0, 0, 485, 46366),
(30883, 1, 0, 0, 247, 46366),
(101951, 1, 0, 0, 485, 46366),
(174272, 1, 0, 0, 446, 46366),
(14881, 1, 0, 0, 81, 46366),
(102671, 1, 0, 0, 446, 46366),
(102266, 1, 0, 0, 485, 46366),
(92879, 1, 0, 0, 181, 46366),
(102489, 1, 0, 0, 446, 46366),
(30857, 1, 0, 0, 247, 46366),
(2110, 23, 0, 0, 81, 46597),
(4075, 23, 0, 0, 81, 46597),
(14881, 23, 0, 0, 81, 46597),
(30857, 23, 0, 0, 247, 46597),
(30883, 23, 0, 0, 247, 46597),
(30896, 23, 0, 0, 247, 46597),
(32204, 23, 0, 0, 1092, 46597),
(53488, 23, 0, 0, 181, 46597),
(92879, 23, 0, 0, 181, 46597),
(101950, 23, 2, 2, 629, 46597),
(101951, 23, 2, 2, 629, 46597),
(101976, 23, 2, 2, 629, 46597),
(101995, 23, 2, 2, 629, 46597),
(102246, 23, 2, 2, 629, 46597),
(102266, 23, 0, 0, 629, 46597),
(102267, 23, 0, 0, 446, 46597),
(102269, 23, 0, 0, 629, 46597),
(102270, 23, 0, 0, 629, 46597),
(102272, 23, 0, 0, 629, 46597),
(102273, 23, 0, 0, 629, 46597),
(102278, 23, 2, 2, 446, 46597),
(102279, 23, 0, 0, 446, 46597),
(102281, 23, 0, 0, 446, 46597),
(102431, 23, 2, 2, 629, 46597),
(102489, 23, 0, 0, 446, 46597),
(102671, 23, 0, 0, 446, 46597);

UPDATE `creature_template_scaling` SET `ContentTuningID`=485, `VerifiedBuild`=46366 WHERE (`DifficultyID`=1 AND `Entry` IN (102368,102337,102369,102282));

UPDATE `creature_model_info` SET `BoundingRadius`=5, `CombatReach`=25, `VerifiedBuild`=46366 WHERE `DisplayID`=68336;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=2.25, `VerifiedBuild`=46366 WHERE `DisplayID`=67736;
UPDATE `creature_model_info` SET `BoundingRadius`=3.312217235565185546, `CombatReach`=3, `VerifiedBuild`=46366 WHERE `DisplayID`=72249;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `VerifiedBuild`=46597 WHERE `DisplayID`=39353;

UPDATE `gossip_menu` SET `VerifiedBuild`=46597 WHERE (`MenuID`=19230 AND `TextID`=28226) OR (`MenuID`=19229 AND `TextID`=28225);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=31401, `ActionMenuID`=19230, `VerifiedBuild`=46597 WHERE (`MenuID`=19229 AND `OptionID`=0); -- OptionBroadcastTextID: 31401 - 104541
UPDATE `gossip_menu_option` SET `BoxText`='Do you want to start the encounter?', `BoxBroadcastTextID`=57303, `VerifiedBuild`=46597 WHERE (`MenuID`=19230 AND `OptionID`=0);

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=14, `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=67160064, `unit_flags3`=18350080 WHERE `entry`=103672; -- Stasis Crystal
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=14, `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `BaseAttackTime`=1500, `unit_flags`=64, `unit_flags2`=4196352 WHERE `entry`=102446; -- Fel Lord Betrug
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=14, `BaseAttackTime`=1000, `unit_flags`=32768, `unit_flags3`=524288 WHERE `entry`=103561; -- Shadow Beast
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1720, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=112741; -- Wrathguard Decimator
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1720, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=112739; -- Shadowy Overfiend
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1720, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=4196352, `unit_flags3`=524288 WHERE `entry`=102398; -- Blazing Infernal
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_walk`=0.5, `speed_run`=0.571428596973419189, `unit_flags`=32768 WHERE `entry`=102372; -- Felhound Mage Slayer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33587200, `unit_flags3`=17301505 WHERE `entry`=103312; -- Soul Vortex
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags`=32768 WHERE `entry`=102373; -- Corrosive Felhound
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry` IN (102335, 102337); -- Portal Guardian
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=16, `BaseAttackTime`=1500, `unit_flags`=33554496, `unit_flags2`=2048, `unit_flags3`=25690113 WHERE `entry`=102659; -- Blood-Princess Thal'ena
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry` IN (102336, 102302); -- Portal Keeper
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=102368; -- Felguard Destroyer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33587200, `unit_flags3`=17301504 WHERE `entry`=103146; -- Eyebomb
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry` IN (113610, 102282); -- Lord Malgath
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1720, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=4196352, `unit_flags3`=524288 WHERE `entry`=102397; -- Wrathlord Bulwark
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1720, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=4196352, `unit_flags3`=524288 WHERE `entry`=102400; -- Eredar Shadow Mender
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1720, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=4196352, `unit_flags3`=524288 WHERE `entry`=102395; -- Infiltrator Assassin
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=102369; -- Felstalker Ravener
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67143680, `unit_flags3`=17301505 WHERE `entry`=103450; -- Fel Axe
UPDATE `creature_template` SET `minlevel`=51, `maxlevel`=51, `npcflag`=16777216, `BaseAttackTime`=1000000, `unit_flags`=33554432, `unit_flags2`=32, `unit_flags3`=1 WHERE `entry`=43499; -- Consecration
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=102620; -- Taldath the Destroyer
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33 WHERE `entry`=30837; -- Defense System
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags`=0, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=102273; -- Doomguard Infiltrator
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=104529; -- Lyndras
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=113610; -- Lord Malgath
UPDATE `creature_template` SET `minlevel`=47, `maxlevel`=47 WHERE `entry`=101995; -- Festerface
UPDATE `creature_template` SET `minlevel`=47, `maxlevel`=47 WHERE `entry`=101950; -- Mindflayer Kaahrj
UPDATE `creature_template` SET `minlevel`=47, `maxlevel`=47, `unit_flags`=33600, `unit_flags3`=1 WHERE `entry`=101951; -- Shivermaw
UPDATE `creature_template` SET `minlevel`=47, `maxlevel`=47, `unit_flags`=33600, `unit_flags3`=1 WHERE `entry`=102431; -- Blood-Princess Thal'ena
UPDATE `creature_template` SET `minlevel`=47, `maxlevel`=47 WHERE `entry`=101976; -- Millificent Manastorm
UPDATE `creature_template` SET `minlevel`=47, `maxlevel`=47, `unit_flags`=33600 WHERE `entry`=102246; -- Anub'esset
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=32204; -- Lieutenant Sinclari
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags`=0, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=102269; -- Felstalker Ravener
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry` IN (102281, 102279); -- Teleportation Portal
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=102267; -- Teleportation Portal (Intro)
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags`=570688256, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=102270; -- Eredar Invader
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=53488; -- Summon Enabler Stalker
UPDATE `creature_template` SET `gossip_menu_id`=19229, `minlevel`=47, `maxlevel`=47, `npcflag`=1 WHERE `entry`=102278; -- Lieutenant Sinclari
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=30896; -- Prison Door Seal
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags`=570688256, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=102272; -- Felguard Destroyer
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags2`=2097152 WHERE `entry`=30883; -- Dalaran Prison Event Controller
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1718, `BaseAttackTime`=2000, `unit_flags`=570688320, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=174272; -- Violet Hold Guard
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=14881; -- Spider
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags3`=16777216 WHERE `entry`=102671; -- Prison Cell
UPDATE `creature_template` SET `unit_flags`=80, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=102266; -- Violet Hold Guard
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777217 WHERE `entry`=92879; -- SLG Generic Stalker (Gigantic AOI)
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags3`=16777217 WHERE `entry`=102489; -- Web Invisible Stalker
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=30857; -- Defense Dummy Target

UPDATE `creature_template` SET `VerifiedBuild`=46597 WHERE `entry` IN (111941, 174626, 152253, 107489, 152290, 152291, 170218, 152323, 67263, 67264, 67266, 58321, 174733, 134442, 152359, 152360, 80728, 152361, 49392, 156842, 147895, 147896, 165805, 152397, 138967, 94197, 156884, 121071, 152414, 152415, 152416, 152448, 98725, 49485, 161414, 152464, 152465, 107698, 107699, 45057, 116691, 156987, 152512, 62983, 179392, 152542, 152545, 152548, 152552, 152553, 152555, 152556, 71979, 152566, 152567, 152568, 71983, 71984, 31698, 183928, 183937, 54105, 116802, 161573, 63091, 67569, 94471, 85517, 18363, 18364, 18365, 148201, 152681, 152682, 157161, 54191, 18378, 18379, 18380, 90018, 125837, 152712, 45268, 90049, 139300, 36330, 99009, 63194, 157231, 99031, 152756, 58739, 99035, 85622, 85624, 85625, 85626, 85627, 85629, 85630, 85632, 85634, 152794, 58777, 152795, 99077, 58787, 166246, 166266, 121498, 67779, 63313, 99150, 90199, 157354, 166313, 63342, 117072, 99182, 67844, 152910, 99210, 67879, 67883, 161901, 103725, 90296, 179850, 157475, 103758, 94808, 27657, 27658, 27659, 72436, 67966, 130646, 81403, 175422, 135129, 72451, 67977, 72455, 72490, 72496, 32207, 175474, 68057, 94923, 157602, 68065, 72545, 63591, 126312, 171094, 171095, 94996, 166644, 32336, 175616, 171146, 77149, 77153, 144324, 77182, 14507, 59303, 175725, 50376, 90675, 45906, 108600, 86219, 59368, 68336, 86250, 153415, 184759, 135513, 68376, 108682, 54969, 81834, 122135, 72889, 184823, 113204, 104262, 149043, 28165, 171456, 144596, 64017, 158041, 171474, 126712, 184915, 55087, 104341, 144637, 144644, 64061, 99878, 73033, 135713, 135725, 144680, 144683, 153658, 68599, 185005, 91014, 91015, 91016, 91017, 91026, 122366, 82074, 149240, 149244, 185074, 32857, 140315, 117934, 144807, 162719, 108996, 149289, 117950, 117951, 104528, 104529, 73195, 185128, 185129, 185130, 185131, 59779, 180658, 104553, 55308, 32927, 55312, 32930, 122477, 55334, 180690, 158327, 73265, 28514, 64330, 122532, 28517, 64346, 140461, 153898, 55419, 91241, 77814, 153928, 153941, 55466, 68904, 68905, 162933, 91305, 33113, 33118, 180860, 33121, 64471, 64479, 91349, 91361, 91362, 91363, 91364, 60040, 91387, 33186, 64526, 154074, 86928, 185423, 185427, 82457, 64556, 185438, 185439, 118289, 113813, 185456, 33241, 33244, 185479, 185480, 154148, 181012, 149684, 176583, 73626, 28860, 104970, 109450, 73638, 78121, 69181, 69212, 118524, 105093, 105097, 37949, 181224, 51405, 29023, 96223, 60410, 33552, 154431, 64900, 109674, 149995, 15687, 172386, 69427, 150017, 105250, 78430, 105299, 105301, 150081, 33686, 105323, 136683, 105352, 60583, 60585, 60586, 87451, 91938, 105386, 105387, 154638, 96444, 56165, 127809, 42753, 181546, 105455, 42778, 181579, 60709, 60710, 154735, 118924, 114462, 105512, 60776, 154817, 69756, 123503, 78736, 145898, 145903, 123531, 33993, 92208, 105674, 60913, 65407, 105721, 146016, 105742, 105743, 105744, 132609, 114709, 105779, 159514, 78948, 150583, 146107, 137158, 172992, 172995, 70025, 70027, 164076, 155126, 155144, 65614, 101436, 114895, 65648, 65651, 65655, 65656, 177584, 173129, 173130, 173131, 155242, 155243, 155245, 155247, 155273, 155275, 155277, 29932, 70250, 70251, 70252, 43404, 56839, 56843, 173257, 173263, 173267, 56897, 43468, 173315, 110642, 155413, 155414, 173324, 173331, 34564, 146495, 173372, 173377, 150995, 88334, 164451, 110732, 124164, 124166, 164461, 164463, 164475, 173430, 142096, 110758, 168962, 70468, 142114, 101823, 164532, 142148, 115287, 164557, 70544, 75029, 164578, 52675, 155648, 142234, 66126, 66135, 66136, 66137, 146750, 178095, 106476, 61707, 61709, 119938, 173675, 124436, 173685, 106542, 160271, 106552, 102088, 160291, 93145, 30472, 173767, 173768, 173769, 173770, 66352, 35013, 52936, 66372, 155919, 66412, 66422, 66436, 164934, 66442, 102267, 66452, 102278, 102279, 102281, 97804, 66466, 111243, 111246, 66478, 169458, 124691, 111263, 156034, 173945, 173951, 66512, 66515, 66518, 66520, 66522, 115795, 66550, 66551, 66552, 88938, 66553, 174018, 165066, 102396, 169554, 115844, 102423, 169594, 174073, 124828, 66636, 66638, 66639, 183042, 62164, 30837, 115902, 151719, 102489, 30857, 66675, 53258, 30883, 53270, 30896, 66734, 66738, 66739, 66741, 178684, 129440, 151870, 66815, 111587, 66819, 66822, 66824, 111595, 178763, 142949, 120564, 160859, 102671, 178783, 107194, 44530, 53494, 98270, 53501, 31125, 62465, 71440, 156523, 71466, 44606, 183406, 165512, 156575, 129722, 71529, 138705, 116329, 138718, 138719, 111861, 111864, 183501, 138740, 156650, 111882, 80551, 80557, 71603, 53696, 102950, 98489);
UPDATE `creature_template` SET `type_flags2`=128, `CreatureDifficultyID`=114022, `VerifiedBuild`=46597 WHERE `entry`=98542; -- Amalgam of Souls
UPDATE `creature_template` SET `HealthModifier`=0.75, `CreatureDifficultyID`=61308, `VerifiedBuild`=46597 WHERE `entry`=67231; -- Trial of the King
UPDATE `creature_template` SET `CreatureDifficultyID`=195461, `VerifiedBuild`=46597 WHERE `entry`=165737; -- Sinstone Statue
UPDATE `creature_template` SET `CreatureDifficultyID`=93844, `VerifiedBuild`=46597 WHERE `entry`=76227; -- Solar Flare
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=76283; -- Malefic Defender
UPDATE `creature_template` SET `type_flags2`=128, `CreatureDifficultyID`=114037, `VerifiedBuild`=46597 WHERE `entry`=98696; -- Illysanna Ravencrest
UPDATE `creature_template` SET `HealthModifier`=5, `CreatureDifficultyID`=181381, `VerifiedBuild`=46597 WHERE `entry`=161375; -- Promising Specimen
UPDATE `creature_template` SET `movementId`=84, `CreatureDifficultyID`=115333, `VerifiedBuild`=46597 WHERE `entry`=98761; -- Soul Fragment
UPDATE `creature_template` SET `HealthModifier`=7.5, `ManaModifier`=8.348600387573242187, `CreatureDifficultyID`=52003, `VerifiedBuild`=46597 WHERE `entry`=40634; -- Naz'jar Tempest Witch
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `HealthModifier`=6, `CreatureDifficultyID`=25011, `VerifiedBuild`=46597 WHERE `entry`=58605; -- Scarlet Judicator
UPDATE `creature_template` SET `type_flags2`=128, `CreatureDifficultyID`=114053, `VerifiedBuild`=46597 WHERE `entry`=98949; -- Smashspite the Hateful
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=24855, `VerifiedBuild`=46597 WHERE `entry`=58676; -- Scarlet Defender
UPDATE `creature_template` SET `CreatureDifficultyID`=93816, `VerifiedBuild`=46597 WHERE `entry`=76585; -- Ragewing the Untamed
UPDATE `creature_template` SET `CreatureDifficultyID`=169312, `VerifiedBuild`=46597 WHERE `entry`=152703; -- Walkie Shockie X1
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=76598; -- Ritual of Bones
UPDATE `creature_template` SET `CreatureDifficultyID`=146105, `VerifiedBuild`=46597 WHERE `entry`=139304; -- Solid Snake
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `CreatureDifficultyID`=136095, `VerifiedBuild`=46597 WHERE `entry`=130437; -- Mine Rat
UPDATE `creature_template` SET `HealthModifier`=1.5, `CreatureDifficultyID`=39021, `VerifiedBuild`=46597 WHERE `entry`=49864; -- Twilight Fiend
UPDATE `creature_template` SET `HealthModifier`=32, `CreatureDifficultyID`=28084, `VerifiedBuild`=46597 WHERE `entry`=27483; -- King Dred
UPDATE `creature_template` SET `CreatureDifficultyID`=93806, `VerifiedBuild`=46597 WHERE `entry`=76801; -- Ragewing Whelp
UPDATE `creature_template` SET `HealthModifier`=32, `CreatureDifficultyID`=114742, `VerifiedBuild`=46597 WHERE `entry`=99200; -- Dresaron
UPDATE `creature_template` SET `HealthModifier`=4.5, `movementId`=79, `CreatureDifficultyID`=44700, `VerifiedBuild`=46597 WHERE `entry`=36535; -- Corrupted Soul Fragment
UPDATE `creature_template` SET `CreatureDifficultyID`=93721, `VerifiedBuild`=46597 WHERE `entry`=81305; -- Fleshrender Nok'gar
UPDATE `creature_template` SET `CreatureDifficultyID`=192194, `VerifiedBuild`=46597 WHERE `entry`=170851; -- Volatile Plague Bomb
UPDATE `creature_template` SET `HealthModifier`=30, `CreatureDifficultyID`=28478, `VerifiedBuild`=46597 WHERE `entry`=27654; -- Drakos the Interrogator
UPDATE `creature_template` SET `HealthModifier`=250, `ManaModifier`=25, `movementId`=221, `CreatureDifficultyID`=28491, `VerifiedBuild`=46597 WHERE `entry`=27656; -- Ley-Guardian Eregos
UPDATE `creature_template` SET `CreatureDifficultyID`=36738, `VerifiedBuild`=46597 WHERE `entry`=32204; -- Lieutenant Sinclari
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=24078, `VerifiedBuild`=46597 WHERE `entry`=59080; -- Darkmaster Gandling
UPDATE `creature_template` SET `CreatureDifficultyID`=195367, `VerifiedBuild`=46597 WHERE `entry`=27756; -- Ruby Drake
UPDATE `creature_template` SET `CreatureDifficultyID`=93802, `VerifiedBuild`=46597 WHERE `entry`=77006; -- Corpse Skitterling
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=24048, `VerifiedBuild`=46597 WHERE `entry`=59100; -- Expired Test Subject
UPDATE `creature_template` SET `HealthModifier`=17.0859375, `CreatureDifficultyID`=131598, `VerifiedBuild`=46597 WHERE `entry`=126283; -- Urjad
UPDATE `creature_template` SET `CreatureDifficultyID`=182223, `VerifiedBuild`=46597 WHERE `entry`=162102; -- Grand Proctor Beryllia
UPDATE `creature_template` SET `HealthModifier`=31, `CreatureDifficultyID`=36884, `VerifiedBuild`=46597 WHERE `entry`=32273; -- Infinite Corruptor
UPDATE `creature_template` SET `type_flags2`=128, `CreatureDifficultyID`=110820, `VerifiedBuild`=46597 WHERE `entry`=94960; -- Hymdall
UPDATE `creature_template` SET `ManaModifier`=55.340301513671875, `CreatureDifficultyID`=146574, `VerifiedBuild`=46597 WHERE `entry`=139737; -- Lord Stormsong
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=23945, `VerifiedBuild`=46597 WHERE `entry`=59153; -- Rattlegore
UPDATE `creature_template` SET `CreatureDifficultyID`=169796, `VerifiedBuild`=46597 WHERE `entry`=153172; -- Stolen Scrapbot
UPDATE `creature_template` SET `HealthModifier`=50, `CreatureDifficultyID`=173009, `VerifiedBuild`=46597 WHERE `entry`=144246; -- K.U.-J.0.
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=153202; -- Piston Smasher
UPDATE `creature_template` SET `CreatureDifficultyID`=93717, `VerifiedBuild`=46597 WHERE `entry`=81603; -- Champion Druna
UPDATE `creature_template` SET `CreatureDifficultyID`=169886, `VerifiedBuild`=46597 WHERE `entry`=153245; -- Stolen Shock Coil
UPDATE `creature_template` SET `HealthModifier`=5, `CreatureDifficultyID`=38422, `VerifiedBuild`=46597 WHERE `entry`=50284; -- Twilight Zealot
UPDATE `creature_template` SET `HealthModifier`=1200, `ManaModifier`=140.399993896484375, `CreatureDifficultyID`=45462, `VerifiedBuild`=46597 WHERE `entry`=36855; -- Lady Deathwhisper
UPDATE `creature_template` SET `CreatureDifficultyID`=157012, `VerifiedBuild`=46597 WHERE `entry`=144311; -- Orb Guardian
UPDATE `creature_template` SET `CreatureDifficultyID`=29216, `VerifiedBuild`=46597 WHERE `entry`=27981; -- Malformed Ooze
UPDATE `creature_template` SET `CreatureDifficultyID`=191748, `VerifiedBuild`=46597 WHERE `entry`=162317; -- Gorechop
UPDATE `creature_template` SET `HealthModifier`=10, `CreatureDifficultyID`=54120, `VerifiedBuild`=46597 WHERE `entry`=41440; -- Aberration
UPDATE `creature_template` SET `CreatureDifficultyID`=115029, `VerifiedBuild`=46597 WHERE `entry`=99646; -- Gastropod
UPDATE `creature_template` SET `CreatureDifficultyID`=114023, `VerifiedBuild`=46597 WHERE `entry`=99663; -- Frustrated Soul
UPDATE `creature_template` SET `CreatureDifficultyID`=114024, `VerifiedBuild`=46597 WHERE `entry`=99664; -- Restless Soul
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `CreatureDifficultyID`=136849, `VerifiedBuild`=46597 WHERE `entry`=131009; -- Spirit of Gold
UPDATE `creature_template` SET `family`=303, `VerifiedBuild`=46597 WHERE `entry`=175780; -- Mistwing
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=86251; -- Commander Tharbek
UPDATE `creature_template` SET `HealthModifier`=55, `ManaModifier`=50, `CreatureDifficultyID`=20039, `VerifiedBuild`=46597 WHERE `entry`=23574; -- Akil'zon
UPDATE `creature_template` SET `HealthModifier`=912, `CreatureDifficultyID`=46387, `VerifiedBuild`=46597 WHERE `entry`=45992; -- Valiona
UPDATE `creature_template` SET `HealthModifier`=912, `CreatureDifficultyID`=46376, `VerifiedBuild`=46597 WHERE `entry`=45993; -- Theralion
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=135552; -- Deathtouched Slaver
UPDATE `creature_template` SET `type_flags2`=128, `HealthModifier`=25, `CreatureDifficultyID`=115425, `VerifiedBuild`=46597 WHERE `entry`=104217; -- Talixae Flamewreath
UPDATE `creature_template` SET `HealthModifier`=0.375, `CreatureDifficultyID`=23321, `VerifiedBuild`=46597 WHERE `entry`=59458; -- Hopling
UPDATE `creature_template` SET `HealthModifier`=50, `CreatureDifficultyID`=23269, `VerifiedBuild`=46597 WHERE `entry`=59479; -- Yan-Zhu the Uncasked
UPDATE `creature_template` SET `HealthModifier`=1.447499990463256835, `CreatureDifficultyID`=115443, `VerifiedBuild`=46597 WHERE `entry`=104251; -- Duskwatch Sentry
UPDATE `creature_template` SET `CreatureDifficultyID`=136990, `VerifiedBuild`=46597 WHERE `entry`=131140; -- Fatal Corruption
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `HealthModifier`=0.144589006900787353, `CreatureDifficultyID`=37876, `VerifiedBuild`=46597 WHERE `entry`=50561; -- Bloodthirsty Ghoul
UPDATE `creature_template` SET `type_flags2`=128, `CreatureDifficultyID`=110833, `VerifiedBuild`=46597 WHERE `entry`=99868; -- Fenryr
UPDATE `creature_template` SET `CreatureDifficultyID`=110872, `VerifiedBuild`=46597 WHERE `entry`=99891; -- Storm Drake
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=122313; -- Zuraal the Ascended
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=122314; -- L'ura
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=122316; -- Saprish
UPDATE `creature_template` SET `HealthModifier`=54.6750030517578125, `CreatureDifficultyID`=128681, `VerifiedBuild`=46597 WHERE `entry`=122319; -- Darkfang
UPDATE `creature_template` SET `CreatureDifficultyID`=140912, `VerifiedBuild`=46597 WHERE `entry`=131318; -- Elder Leaxa
UPDATE `creature_template` SET `HealthModifier`=246.153839111328125, `CreatureDifficultyID`=38081, `VerifiedBuild`=46597 WHERE `entry`=32913; -- Elder Ironbranch
UPDATE `creature_template` SET `HealthModifier`=246.153839111328125, `CreatureDifficultyID`=38086, `VerifiedBuild`=46597 WHERE `entry`=32914; -- Elder Stonebark
UPDATE `creature_template` SET `HealthModifier`=323.076934814453125, `CreatureDifficultyID`=38092, `VerifiedBuild`=46597 WHERE `entry`=32915; -- Elder Brightleaf
UPDATE `creature_template` SET `HealthModifier`=46.15384674072265625, `movementId`=121, `CreatureDifficultyID`=38107, `VerifiedBuild`=46597 WHERE `entry`=32919; -- Storm Lasher
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `HealthModifier`=30, `CreatureDifficultyID`=22580, `VerifiedBuild`=46597 WHERE `entry`=59789; -- Thalnos the Soulrender
UPDATE `creature_template` SET `CreatureDifficultyID`=143584, `VerifiedBuild`=46597 WHERE `entry`=135903; -- Manifestation of the Deep
UPDATE `creature_template` SET `HealthModifier`=0.75, `CreatureDifficultyID`=22503, `VerifiedBuild`=46597 WHERE `entry`=59822; -- Auntie Stormstout
UPDATE `creature_template` SET `HealthModifier`=0.075000002980232238, `CreatureDifficultyID`=22493, `VerifiedBuild`=46597 WHERE `entry`=59824; -- Golden Hopling
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=77816; -- Borka the Brute
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `HealthModifier`=50, `CreatureDifficultyID`=22282, `VerifiedBuild`=46597 WHERE `entry`=59930; -- Empowered Zombie
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=131595; -- Governess Tabitha
UPDATE `creature_template` SET `CreatureDifficultyID`=138965, `VerifiedBuild`=46597 WHERE `entry`=131615; -- Head Vintner Justin
UPDATE `creature_template` SET `CreatureDifficultyID`=138963, `VerifiedBuild`=46597 WHERE `entry`=131617; -- Groundskeeper Lilith
UPDATE `creature_template` SET `CreatureDifficultyID`=138961, `VerifiedBuild`=46597 WHERE `entry`=131619; -- Seamstress Johanna
UPDATE `creature_template` SET `CreatureDifficultyID`=38547, `VerifiedBuild`=46597 WHERE `entry`=33134; -- Sara
UPDATE `creature_template` SET `HealthModifier`=53.35146331787109375, `CreatureDifficultyID`=38555, `VerifiedBuild`=46597 WHERE `entry`=33136; -- Guardian of Yogg-Saron
UPDATE `creature_template` SET `type_flags2`=128, `CreatureDifficultyID`=110831, `VerifiedBuild`=46597 WHERE `entry`=95833; -- Hyrja
UPDATE `creature_template` SET `CreatureDifficultyID`=93774, `VerifiedBuild`=46597 WHERE `entry`=77927; -- Son of the Beast
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=95843; -- King Haldor
UPDATE `creature_template` SET `CreatureDifficultyID`=138059, `VerifiedBuild`=46597 WHERE `entry`=131667; -- Soulbound Goliath
UPDATE `creature_template` SET `CreatureDifficultyID`=80527, `VerifiedBuild`=46597 WHERE `entry`=82428; -- Emberscale Ironflight
UPDATE `creature_template` SET `CreatureDifficultyID`=147441, `VerifiedBuild`=46597 WHERE `entry`=136160; -- King Dazar
UPDATE `creature_template` SET `CreatureDifficultyID`=93631, `VerifiedBuild`=46597 WHERE `entry`=86918; -- Uncharged Construct
UPDATE `creature_template` SET `HealthModifier`=38.46154022216796875, `CreatureDifficultyID`=38654, `VerifiedBuild`=46597 WHERE `entry`=33202; -- Ancient Water Spirit
UPDATE `creature_template` SET `HealthModifier`=32, `CreatureDifficultyID`=115049, `VerifiedBuild`=46597 WHERE `entry`=95886; -- Ash'Golm
UPDATE `creature_template` SET `CreatureDifficultyID`=115053, `VerifiedBuild`=46597 WHERE `entry`=95888; -- Cordana Felsong
UPDATE `creature_template` SET `HealthModifier`=35, `CreatureDifficultyID`=173013, `VerifiedBuild`=46597 WHERE `entry`=145185; -- Gnomercy 4.U.
UPDATE `creature_template` SET `CreatureDifficultyID`=114036, `VerifiedBuild`=46597 WHERE `entry`=100436; -- Illysanna Ravencrest
UPDATE `creature_template` SET `CreatureDifficultyID`=193596, `VerifiedBuild`=46597 WHERE `entry`=172093; -- Hearty Haunch
UPDATE `creature_template` SET `CreatureDifficultyID`=193599, `VerifiedBuild`=46597 WHERE `entry`=172094; -- Dissectible Dessert
UPDATE `creature_template` SET `HealthModifier`=980, `CreatureDifficultyID`=44915, `VerifiedBuild`=46597 WHERE `entry`=46753; -- Al'Akir
UPDATE `creature_template` SET `CreatureDifficultyID`=138959, `VerifiedBuild`=46597 WHERE `entry`=131853; -- Huntmaster Grath
UPDATE `creature_template` SET `HealthModifier`=35, `CreatureDifficultyID`=123773, `VerifiedBuild`=46597 WHERE `entry`=113971; -- Maiden of Virtue
UPDATE `creature_template` SET `HealthModifier`=15, `CreatureDifficultyID`=47350, `VerifiedBuild`=46597 WHERE `entry`=37890; -- Cult Fanatic
UPDATE `creature_template` SET `HealthModifier`=0.75, `CreatureDifficultyID`=21653, `VerifiedBuild`=46597 WHERE `entry`=60276; -- Hozen Clinger
UPDATE `creature_template` SET `CreatureDifficultyID`=130113, `VerifiedBuild`=46597 WHERE `entry`=122969; -- Zanchuli Witch-Doctor
UPDATE `creature_template` SET `HealthModifier`=0.300000011920928955, `CreatureDifficultyID`=53195, `VerifiedBuild`=46597 WHERE `entry`=42428; -- Devout Follower
UPDATE `creature_template` SET `CreatureDifficultyID`=137462, `VerifiedBuild`=46597 WHERE `entry`=127503; -- Overseer Korgus
UPDATE `creature_template` SET `HealthModifier`=519.23077392578125, `CreatureDifficultyID`=39319, `VerifiedBuild`=46597 WHERE `entry`=33524; -- Saronite Animus
UPDATE `creature_template` SET `CreatureDifficultyID`=193829, `VerifiedBuild`=46597 WHERE `entry`=172312; -- Spinemaw Gorger
UPDATE `creature_template` SET `HealthModifier`=15, `CreatureDifficultyID`=47641, `VerifiedBuild`=46597 WHERE `entry`=38009; -- Reanimated Fanatic
UPDATE `creature_template` SET `HealthModifier`=15, `ManaModifier`=20, `CreatureDifficultyID`=47650, `VerifiedBuild`=46597 WHERE `entry`=38010; -- Reanimated Adherent
UPDATE `creature_template` SET `HealthModifier`=1.923076868057250976, `CreatureDifficultyID`=39430, `VerifiedBuild`=46597 WHERE `entry`=33572; -- Steelforged Defender
UPDATE `creature_template` SET `HealthModifier`=15, `CreatureDifficultyID`=47800, `VerifiedBuild`=46597 WHERE `entry`=38135; -- Deformed Fanatic
UPDATE `creature_template` SET `HealthModifier`=50, `CreatureDifficultyID`=165124, `VerifiedBuild`=46597 WHERE `entry`=150159; -- King Gobbamak
UPDATE `creature_template` SET `HealthModifier`=7.692307472229003906, `CreatureDifficultyID`=39781, `VerifiedBuild`=46597 WHERE `entry`=33768; -- Rubble
UPDATE `creature_template` SET `CreatureDifficultyID`=93696, `VerifiedBuild`=46597 WHERE `entry`=83026; -- Siegemaster Olugar
UPDATE `creature_template` SET `HealthModifier`=48, `CreatureDifficultyID`=32232, `VerifiedBuild`=46597 WHERE `entry`=29305; -- Moorabi
UPDATE `creature_template` SET `HealthModifier`=65, `CreatureDifficultyID`=165169, `VerifiedBuild`=46597 WHERE `entry`=150190; -- HK-8 Aerial Oppression Unit
UPDATE `creature_template` SET `CreatureDifficultyID`=171552, `VerifiedBuild`=46597 WHERE `entry`=154741; -- Squirt Bot
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `HealthModifier`=40, `CreatureDifficultyID`=43699, `VerifiedBuild`=46597 WHERE `entry`=47297; -- Lumbering Oaf
UPDATE `creature_template` SET `HealthModifier`=16, `CreatureDifficultyID`=165308, `VerifiedBuild`=46597 WHERE `entry`=150295; -- Tank Buster MK1
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=96609; -- Gildedfur Stag
UPDATE `creature_template` SET `HealthModifier`=33.84615325927734375, `CreatureDifficultyID`=40283, `VerifiedBuild`=46597 WHERE `entry`=34035; -- Feral Defender
UPDATE `creature_template` SET `HealthModifier`=38.46154022216796875, `CreatureDifficultyID`=40334, `VerifiedBuild`=46597 WHERE `entry`=34057; -- Assault Bot
UPDATE `creature_template` SET `CreatureDifficultyID`=158854, `VerifiedBuild`=46597 WHERE `entry`=137036; -- Awoken Void
UPDATE `creature_template` SET `CreatureDifficultyID`=115314, `VerifiedBuild`=46597 WHERE `entry`=96754; -- Harbaron
UPDATE `creature_template` SET `ManaModifier`=0.000350554008036851, `CreatureDifficultyID`=115318, `VerifiedBuild`=46597 WHERE `entry`=96756; -- Ymiron, the Fallen King
UPDATE `creature_template` SET `CreatureDifficultyID`=177524, `VerifiedBuild`=46597 WHERE `entry`=155056; -- Robo-Waste
UPDATE `creature_template` SET `CreatureDifficultyID`=93924, `VerifiedBuild`=46597 WHERE `entry`=74475; -- Magmolatus
UPDATE `creature_template` SET `HealthModifier`=100, `CreatureDifficultyID`=35136, `VerifiedBuild`=46597 WHERE `entry`=52148; -- Jin'do the Godbreaker
UPDATE `creature_template` SET `HealthModifier`=45, `CreatureDifficultyID`=66550, `VerifiedBuild`=46597 WHERE `entry`=56636; -- Commander Ri'mok
UPDATE `creature_template` SET `HealthModifier`=57.5, `CreatureDifficultyID`=27626, `VerifiedBuild`=46597 WHERE `entry`=56637; -- Ook-Ook
UPDATE `creature_template` SET `CreatureDifficultyID`=143701, `VerifiedBuild`=46597 WHERE `entry`=137233; -- Plague Toad
UPDATE `creature_template` SET `CreatureDifficultyID`=93923, `VerifiedBuild`=46597 WHERE `entry`=74570; -- Ruination
UPDATE `creature_template` SET `CreatureDifficultyID`=93922, `VerifiedBuild`=46597 WHERE `entry`=74571; -- Calamity
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `HealthModifier`=50, `CreatureDifficultyID`=42808, `VerifiedBuild`=46597 WHERE `entry`=47739; -- "Captain" Cookie
UPDATE `creature_template` SET `HealthModifier`=45, `CreatureDifficultyID`=27441, `VerifiedBuild`=46597 WHERE `entry`=56717; -- Hoptallus
UPDATE `creature_template` SET `CreatureDifficultyID`=148969, `VerifiedBuild`=46597 WHERE `entry`=141792; -- Liz Vilepot
UPDATE `creature_template` SET `HealthModifier`=37.5, `CreatureDifficultyID`=27389, `VerifiedBuild`=46597 WHERE `entry`=56732; -- Liu Flameheart
UPDATE `creature_template` SET `HealthModifier`=9, `CreatureDifficultyID`=66552, `VerifiedBuild`=46597 WHERE `entry`=61213; -- Krik'thik Conscript
UPDATE `creature_template` SET `CreatureDifficultyID`=148979, `VerifiedBuild`=46597 WHERE `entry`=141800; -- Brutik Blackanvil
UPDATE `creature_template` SET `CreatureDifficultyID`=148986, `VerifiedBuild`=46597 WHERE `entry`=141805; -- Threshanator 3000
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=56747; -- Gu Cloudstrike
UPDATE `creature_template` SET `HealthModifier`=45, `CreatureDifficultyID`=56173, `VerifiedBuild`=46597 WHERE `entry`=61243; -- Gekkan
UPDATE `creature_template` SET `CreatureDifficultyID`=189635, `VerifiedBuild`=46597 WHERE `entry`=164218; -- Lord Chamberlain
UPDATE `creature_template` SET `CreatureDifficultyID`=110846, `VerifiedBuild`=46597 WHERE `entry`=97081; -- King Bjorn
UPDATE `creature_template` SET `CreatureDifficultyID`=110848, `VerifiedBuild`=46597 WHERE `entry`=97083; -- King Ranulf
UPDATE `creature_template` SET `CreatureDifficultyID`=110849, `VerifiedBuild`=46597 WHERE `entry`=97084; -- King Tor
UPDATE `creature_template` SET `HealthModifier`=28.35000038146972656, `CreatureDifficultyID`=184653, `VerifiedBuild`=46597 WHERE `entry`=164255; -- Globgrog
UPDATE `creature_template` SET `HealthModifier`=10, `CreatureDifficultyID`=34604, `VerifiedBuild`=46597 WHERE `entry`=52392; -- Gurubashi Master Chef
UPDATE `creature_template` SET `CreatureDifficultyID`=93919, `VerifiedBuild`=46597 WHERE `entry`=74787; -- Slave Watcher Crushto
UPDATE `creature_template` SET `HealthModifier`=20, `CreatureDifficultyID`=34586, `VerifiedBuild`=46597 WHERE `entry`=52405; -- Mor'Lek the Dismantler
UPDATE `creature_template` SET `HealthModifier`=20, `CreatureDifficultyID`=34552, `VerifiedBuild`=46597 WHERE `entry`=52414; -- Tor-Tun
UPDATE `creature_template` SET `HealthModifier`=20, `CreatureDifficultyID`=34539, `VerifiedBuild`=46597 WHERE `entry`=52418; -- Lost Offspring of Gahz'ranka
UPDATE `creature_template` SET `HealthModifier`=20, `CreatureDifficultyID`=34527, `VerifiedBuild`=46597 WHERE `entry`=52422; -- Kaulema the Mover
UPDATE `creature_template` SET `CreatureDifficultyID`=115332, `VerifiedBuild`=46597 WHERE `entry`=97200; -- Seacursed Soulkeeper
UPDATE `creature_template` SET `CreatureDifficultyID`=93674, `VerifiedBuild`=46597 WHERE `entry`=83775; -- Ogron Laborer
UPDATE `creature_template` SET `HealthModifier`=20, `CreatureDifficultyID`=34487, `VerifiedBuild`=46597 WHERE `entry`=52438; -- Mortaxx
UPDATE `creature_template` SET `HealthModifier`=1, `CreatureDifficultyID`=190458, `VerifiedBuild`=46597 WHERE `entry`=164363; -- Undying Stonefiend
UPDATE `creature_template` SET `HealthModifier`=16, `CreatureDifficultyID`=34478, `VerifiedBuild`=46597 WHERE `entry`=52440; -- Gub
UPDATE `creature_template` SET `HealthModifier`=20, `CreatureDifficultyID`=34470, `VerifiedBuild`=46597 WHERE `entry`=52442; -- Florawing Hive Queen
UPDATE `creature_template` SET `HealthModifier`=4.5, `CreatureDifficultyID`=66555, `VerifiedBuild`=46597 WHERE `entry`=56930; -- Krik'thik Swarm Bringer
UPDATE `creature_template` SET `HealthModifier`=200, `CreatureDifficultyID`=19706, `VerifiedBuild`=46597 WHERE `entry`=61427; -- Subetai the Swift
UPDATE `creature_template` SET `HealthModifier`=0.75, `CreatureDifficultyID`=56164, `VerifiedBuild`=46597 WHERE `entry`=61431; -- Glintrok Scout
UPDATE `creature_template` SET `HealthModifier`=30, `CreatureDifficultyID`=55832, `VerifiedBuild`=46597 WHERE `entry`=61442; -- Kuai the Brute
UPDATE `creature_template` SET `HealthModifier`=9, `CreatureDifficultyID`=41596, `VerifiedBuild`=46597 WHERE `entry`=34605; -- Swarm Scarab
UPDATE `creature_template` SET `HealthModifier`=4.875, `CreatureDifficultyID`=144084, `VerifiedBuild`=46597 WHERE `entry`=137588; -- Gasping Flounder
UPDATE `creature_template` SET `CreatureDifficultyID`=195397, `VerifiedBuild`=46597 WHERE `entry`=164450; -- Dealer Xy'exa
UPDATE `creature_template` SET `CreatureDifficultyID`=134778, `VerifiedBuild`=46597 WHERE `entry`=128652; -- Viq'Goth
UPDATE `creature_template` SET `HealthModifier`=1559, `CreatureDifficultyID`=34219, `VerifiedBuild`=46597 WHERE `entry`=52571; -- Majordomo Staghelm
UPDATE `creature_template` SET `CreatureDifficultyID`=172472, `VerifiedBuild`=46597 WHERE `entry`=155543; -- Helpless Critter
UPDATE `creature_template` SET `CreatureDifficultyID`=191489, `VerifiedBuild`=46597 WHERE `entry`=164501; -- Mistcaller
UPDATE `creature_template` SET `CreatureDifficultyID`=191525, `VerifiedBuild`=46597 WHERE `entry`=164517; -- Tred'ova
UPDATE `creature_template` SET `HealthModifier`=0.75, `CreatureDifficultyID`=51289, `VerifiedBuild`=46597 WHERE `entry`=43658; -- Frenzied Crocolisk
UPDATE `creature_template` SET `HealthModifier`=45, `CreatureDifficultyID`=66562, `VerifiedBuild`=46597 WHERE `entry`=61567; -- Vizier Jin'bak
UPDATE `creature_template` SET `CreatureDifficultyID`=177465, `VerifiedBuild`=46597 WHERE `entry`=155595; -- Sacred Gear
UPDATE `creature_template` SET `CreatureDifficultyID`=172605, `VerifiedBuild`=46597 WHERE `entry`=155645; -- Walkie Shockie X2
UPDATE `creature_template` SET `CreatureDifficultyID`=177135, `VerifiedBuild`=46597 WHERE `entry`=151168; -- Annihilo-tron 5000
UPDATE `creature_template` SET `CreatureDifficultyID`=116564, `VerifiedBuild`=46597 WHERE `entry`=101950; -- Mindflayer Kaahrj
UPDATE `creature_template` SET `CreatureDifficultyID`=116571, `VerifiedBuild`=46597 WHERE `entry`=101951; -- Shivermaw
UPDATE `creature_template` SET `HealthModifier`=541.4100341796875, `CreatureDifficultyID`=115429, `VerifiedBuild`=46597 WHERE `entry`=110907; -- Star Augur Etraeus
UPDATE `creature_template` SET `CreatureDifficultyID`=116576, `VerifiedBuild`=46597 WHERE `entry`=101976; -- Millificent Manastorm
UPDATE `creature_template` SET `HealthModifier`=70, `CreatureDifficultyID`=42157, `VerifiedBuild`=46597 WHERE `entry`=34826; -- Mistress of Pain
UPDATE `creature_template` SET `HealthModifier`=18.75, `CreatureDifficultyID`=66570, `VerifiedBuild`=46597 WHERE `entry`=61699; -- Sik'thik Amberwing
UPDATE `creature_template` SET `CreatureDifficultyID`=116569, `VerifiedBuild`=46597 WHERE `entry`=101995; -- Festerface
UPDATE `creature_template` SET `CreatureDifficultyID`=172766, `VerifiedBuild`=46597 WHERE `entry`=155760; -- Tank Buster MK2
UPDATE `creature_template` SET `HealthModifier`=12.82999992370605468, `CreatureDifficultyID`=114640, `VerifiedBuild`=46597 WHERE `entry`=111008; -- Hatespawn Abomination
UPDATE `creature_template` SET `CreatureDifficultyID`=126299, `VerifiedBuild`=46597 WHERE `entry`=102169; -- Black Bile
UPDATE `creature_template` SET `HealthModifier`=75, `CreatureDifficultyID`=55843, `VerifiedBuild`=46597 WHERE `entry`=61884; -- Xin the Weaponmaster
UPDATE `creature_template` SET `CreatureDifficultyID`=116561, `VerifiedBuild`=46597 WHERE `entry`=102246; -- Anub'esset
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=102266; -- Violet Hold Guard
UPDATE `creature_template` SET `CreatureDifficultyID`=116586, `VerifiedBuild`=46597 WHERE `entry`=102269; -- Felstalker Ravener
UPDATE `creature_template` SET `CreatureDifficultyID`=116587, `VerifiedBuild`=46597 WHERE `entry`=102270; -- Eredar Invader
UPDATE `creature_template` SET `CreatureDifficultyID`=116588, `VerifiedBuild`=46597 WHERE `entry`=102272; -- Felguard Destroyer
UPDATE `creature_template` SET `CreatureDifficultyID`=116589, `VerifiedBuild`=46597 WHERE `entry`=102273; -- Doomguard Infiltrator
UPDATE `creature_template` SET `CreatureDifficultyID`=116590, `VerifiedBuild`=46597 WHERE `entry`=102282; -- Lord Malgath
UPDATE `creature_template` SET `CreatureDifficultyID`=185482, `VerifiedBuild`=46597 WHERE `entry`=164967; -- Doctor Ickus
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=75452; -- Bonemaw
UPDATE `creature_template` SET `CreatureDifficultyID`=153880, `VerifiedBuild`=46597 WHERE `entry`=142625; -- Ledley the Bold
UPDATE `creature_template` SET `HealthModifier`=55, `CreatureDifficultyID`=50125, `VerifiedBuild`=46597 WHERE `entry`=39665; -- Rom'ogg Bonecrusher
UPDATE `creature_template` SET `CreatureDifficultyID`=134780, `VerifiedBuild`=46597 WHERE `entry`=129208; -- Dread Captain Lockwood
UPDATE `creature_template` SET `CreatureDifficultyID`=185608, `VerifiedBuild`=46597 WHERE `entry`=165073; -- Forlorn Captive
UPDATE `creature_template` SET `HealthModifier`=5, `CreatureDifficultyID`=123699, `VerifiedBuild`=46597 WHERE `entry`=115831; -- Mana Devourer
UPDATE `creature_template` SET `CreatureDifficultyID`=177487, `VerifiedBuild`=46597 WHERE `entry`=151654; -- Deuce Mecha-Buffer
UPDATE `creature_template` SET `CreatureDifficultyID`=93655, `VerifiedBuild`=46597 WHERE `entry`=84520; -- Pitwarden Gwarnok
UPDATE `creature_template` SET `CreatureDifficultyID`=116559, `VerifiedBuild`=46597 WHERE `entry`=102431; -- Blood-Princess Thal'ena
UPDATE `creature_template` SET `CreatureDifficultyID`=190801, `VerifiedBuild`=46597 WHERE `entry`=169617; -- Duraka the Unbreakable
UPDATE `creature_template` SET `CreatureDifficultyID`=149040, `VerifiedBuild`=46597 WHERE `entry`=138314; -- Patches
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `HealthModifier`=2.20000004768371582, `CreatureDifficultyID`=196041, `VerifiedBuild`=46597 WHERE `entry`=174272; -- Violet Hold Guard
UPDATE `creature_template` SET `HealthModifier`=1.125, `CreatureDifficultyID`=50768, `VerifiedBuild`=46597 WHERE `entry`=39984; -- Malignant Trogg
UPDATE `creature_template` SET `HealthModifier`=14, `ManaModifier`=20, `CreatureDifficultyID`=50779, `VerifiedBuild`=46597 WHERE `entry`=39987; -- Evolved Twilight Zealot
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=46597 WHERE `entry`=75829; -- Nhallish
UPDATE `creature_template` SET `CreatureDifficultyID`=117106, `VerifiedBuild`=46597 WHERE `entry`=98246; -- Risen Warrior
UPDATE `creature_template` SET `type_flags`=2097768, `CreatureDifficultyID`=186237, `VerifiedBuild`=46597 WHERE `entry`=165408; -- Halkias
UPDATE `creature_template` SET `CreatureDifficultyID`=143582, `VerifiedBuild`=46597 WHERE `entry`=134069; -- Vol'zith the Whisperer
UPDATE `creature_template` SET `HealthModifier`=4, `ManaModifier`=1, `CreatureDifficultyID`=26160, `VerifiedBuild`=46597 WHERE `entry`=26627; -- Crystal Handler
UPDATE `creature_template` SET `HealthModifier`=5, `CreatureDifficultyID`=26168, `VerifiedBuild`=46597 WHERE `entry`=26628; -- Drakkari Scytheclaw
UPDATE `creature_template` SET `HealthModifier`=5, `CreatureDifficultyID`=26218, `VerifiedBuild`=46597 WHERE `entry`=26641; -- Drakkari Gutripper
UPDATE `creature_template` SET `CreatureDifficultyID`=114279, `VerifiedBuild`=46597 WHERE `entry`=98293; -- Saltsea Globule
UPDATE `creature_template` SET `HealthModifier`=2, `CreatureDifficultyID`=186553, `VerifiedBuild`=46597 WHERE `entry`=165556; -- Fleeting Manifestation
UPDATE `creature_template` SET `HealthModifier`=333.20001220703125, `CreatureDifficultyID`=32132, `VerifiedBuild`=46597 WHERE `entry`=53694; -- Riplimb
UPDATE `creature_template` SET `HealthModifier`=333.20001220703125, `CreatureDifficultyID`=32123, `VerifiedBuild`=46597 WHERE `entry`=53695; -- Rageface

UPDATE `creature_template_model` SET `VerifiedBuild`=46597 WHERE (`Idx`=1 AND `CreatureID` IN (30837,105742,111864,65407,90018,59779,33768,49485,33552,50284,173769,165073,73033,110732,55334,99031,56165,115143,111882,105744,156884,105743,175474,173768,173770,173767,118924,164934,120564,155595,166266,71979,70252,52936,71984,115902,70250,135129,184823,59100,157161,43658,137036,53696,77149,146750,98246,68065,113204,111861,59479,99009,104251,102396,99646,78736,68376,58676,144807,171146,71440,173951,102270,102267,4075,92879,102671,102489,30857,53488,30896,174272,102272,102269,102279,102281,102273,14881,44606,103725,122969,173685,124436,42428,72451,33572,77816,91305,91241,164578,55466,69756,86251,35845,94197,96444,118524,102266,43359,97709,154916,150918,155267,152795,152794)) OR (`Idx`=0 AND `CreatureID` IN (30837,102282,127503,131853,107699,145903,108600,105742,171094,111864,61699,74570,161375,155144,32927,38010,78121,104529,155056,155760,144246,127809,138740,65407,98696,45906,99868,162933,104217,156575,124164,137588,68905,151654,53258,96223,148201,178763,102169,59822,56897,33118,150081,56843,58605,99664,145898,61431,38009,160859,67231,62465,64479,105301,141805,61567,80557,61213,154074,64556,61709,28514,29023,131318,90018,102423,56637,44530,61442,34035,59779,33768,49485,84520,33552,33202,52414,52422,52438,50284,52392,76585,68599,81834,105299,176583,158041,67779,154741,55308,55312,173769,150995,141800,69086,165073,73033,33136,122135,71603,33244,58787,129722,55419,164363,73265,170851,38135,142949,136683,63091,110732,59458,55334,32273,26628,29305,27654,99031,56165,86250,86918,115143,86928,146016,111882,72436,119938,64061,105744,164967,164557,171474,69427,172094,156884,95833,174018,165408,164450,162317,105743,129208,164218,104528,172995,165737,36855,171456,184759,153941,80551,172386,122366,117072,36535,175474,141792,165066,115844,173768,173770,67571,109450,153172,67966,175422,173767,94808,172992,166644,172093,147430,164501,162102,108682,116802,39987,23574,26627,123531,126712,74475,118924,164934,165512,120564,104341,103758,138719,77814,56930,77927,41440,67569,100436,33241,138718,68336,114462,33113,136160,73195,15687,50376,114895,169554,108996,32857,68655,91349,135903,94996,93145,152910,64346,83775,155595,166266,60709,49864,71979,15363,158190,78948,111941,72889,185005,61884,139737,53694,144596,70252,52675,53494,87451,99663,52571,52936,88938,53501,39665,185131,40634,72496,71466,72490,105097,70251,71984,185130,138967,71983,180690,115902,157475,90199,166246,185129,179850,71529,177584,135513,91938,70250,135129,153415,180860,113971,149995,32919,178095,180658,39984,175616,73638,181012,185423,33686,95888,61243,167169,185128,90049,51405,67883,178783,185427,185439,27659,64017,88334,43468,183501,43404,181546,102950,181579,59080,184915,77153,138705,53695,154817,56839,74787,26641,64471,104262,45993,102088,95886,179392,183937,184823,59100,157161,68904,143045,154431,165556,78430,152512,164532,52418,156987,82074,60410,131667,45992,82457,98761,33524,67879,43658,59930,137036,152253,53696,138314,144324,81305,77149,115831,72545,94923,123503,165805,142148,110907,146495,80728,56732,146750,56636,174626,32915,137158,98246,166313,98949,121071,146107,29932,58777,50561,122477,157231,147896,32914,147895,68065,126312,94471,149684,83026,164517,107194,113204,101823,149043,111861,32913,59479,131140,144311,157354,99009,156842,161573,62164,27981,99200,104251,28860,150190,105721,172312,102396,160291,164255,69212,99646,86219,162719,185480,129440,47297,75029,185479,157602,61427,60276,63313,34605,149289,54969,46753,78736,33134,27756,144683,134069,174733,122532,54105,68057,169617,107698,159514,36330,97084,68376,144680,116329,58676,183042,52442,144807,64526,45057,97083,153245,77006,60913,135725,58739,171146,139304,111595,34826,97081,63342,155543,145185,27483,68820,30472,134442,52440,142625,139300,124828,183928,160271,71440,130646,59153,42753,178684,109674,98293,150295,70544,59824,99891,173951,34057,33993,91387,27658,58321,102270,101951,74571,2110,102267,4075,101976,92879,102431,102671,32204,102489,30857,102246,102278,30883,53488,30896,174272,102272,102269,102279,102281,102273,14881,101950,155919,168962,185074,47739,44606,135713,81603,185456,154638,96756,155277,103725,110758,161414,131619,174073,173945,155275,122969,150159,131617,121498,183406,96754,155273,52405,90296,111587,27657,169594,131615,173430,173685,97200,59789,101995,61707,35013,98542,65614,37890,164475,52148,72455,124436,31125,76227,150024,156034,124691,94960,181224,82428,111008,175725,155648,76801,27656,169458,111263,137233,34564,67977,42428,155645,81403,173675,60586,63591,152703,92208,151168,150017,72451,128652,185438,55087,33572,77182,14507,62983,158327,70468,56717,60585,170218,125837,164463,54191,51090,42778,149244,164461,155126,64900,60776,122319,126283,67844,164076,131595,75452,161901,76283,60040,144637,114709,116691,149240,56747,33186,118289,130437,60583,32930,115795,37949,77816,59368,153202,67266,122316,155247,28517,154735,33121,60710,155245,135552,91305,91241,156523,28165,164451,59303,67264,156650,122314,164578,155243,132609,71803,131009,155242,76598,67263,95843,98725,115287,180899,69181,122313,49392,45268,55466,69820,69756,96609,124166,86251,171095,75829,111246,111243,113813,35845,110642,94197,96444,118524,101436,102266,43359,66126,66137,66442,66352,66372,66452,66436,66412,66135,66422,66136,66466,63194,65648,65651,66515,64330,66518,65655,66520,66512,66478,65656,66522,85519,67370,66551,66553,66550,66552,66557,66638,66636,66639,66635,66675,66815,66824,66819,66822,68464,68465,68462,68463,66739,66918,66733,66730,66734,66738,66741,68562,68559,68558,68566,68561,68560,68565,68564,68563,68555,73626,85627,85626,85625,85624,85659,85517,85622,79179,85634,85685,85632,85650,85630,85629,79751,89131,89130,85420,91364,91363,91362,91361,91026,91017,91016,91015,91014,90675,87123,87110,87125,87122,83837,87124,94646,94641,94649,94648,94643,94601,94640,94647,94642,94650,94644,94639,94637,94638,94645,104970,97559,97547,97511,105009,104992,105093,99035,105352,105779,97709,105674,105323,105250,105386,105387,105512,98270,99878,105455,105842,98572,104553,105841,104782,99150,99077,97804,105840,105241,99182,99742,99210,107489,106542,106417,106552,106476,97323,97283,97294,105898,117951,117950,117934,128014,128016,128018,128015,128017,128013,128007,128010,128012,128008,128011,128009,128019,128022,128024,128023,128021,128020,115307,115286,124617,142234,142114,142096,142151,141969,141945,142054,141879,141529,141814,141799,141588,141077,141292,141215,141479,141046,141002,140315,139987,140880,140813,140461,139489,154921,154919,154917,154915,154913,154911,154920,154918,154916,154914,154912,154910,154929,154927,154925,154923,154928,154926,154924,154922,162471,162470,162469,162468,162466,162465,162461,162458,175780,175779,175778,173381,173377,173376,173372,175782,175781,173331,173324,173315,173303,175786,175784,173274,173267,173263,173257,175785,175783,175777,173129,173130,173133,173131,176655,72290,72291,72009,72285,71930,71933,71932,71924,71927,71931,71929,71934,71926,116795,116794,116793,116790,116791,116792,116789,116787,116788,116786,119407,119344,119345,119343,119408,119341,119342,119346,119409,145988,146002,146003,146004,146005,145968,145971,146932,146181,146183,146182,146001,155413,155414,150858,150917,150918,150929,155267,155145,150925,150914,150911,150922,150923,160205,160210,160208,160206,161663,161657,161662,161656,161658,161661,160207,161651,161649,161650,160209,151719,152568,152360,154148,153928,153898,152290,152359,153658,152552,152542,152545,152548,152795,151870,150583,152682,152681,152397,152465,144644,152323,152567,152448,152553,152555,152414,152291,152756,152556,152464,152712,152361,152566,152794,152416,152415,66151,76084,64977,14744,35362,31698,39209,7690,73060,64993,33030,21354,73780,20220,65011,29929,305,70027,70025,63766,54741,51195,47841,25064,32944,32640,32336,32207,32158,31852,29582,27707,28302,24368,20029,20030,18379,18380,18378,18377,18365,18364,18363,15714,15666,14539,14505,7708,7707,6075,4271,53270,304,144961)) OR (`Idx`=3 AND `CreatureID` IN (105742,111864,33768,49485,50284,165073,111882,105744,105743,175474,166266,71979,115902,43658,113204,111861,99646,144807,171146,102272,44606,42428,72451,91241,164578,155267,152795)) OR (`Idx`=2 AND `CreatureID` IN (105742,111864,59779,33768,49485,50284,165073,111882,105744,105743,175474,166266,71979,70252,115902,70250,43658,77149,113204,111861,59479,99646,144807,171146,4075,174272,102272,102269,102273,44606,122969,124436,42428,72451,91241,164578,94197,96444,102266,154916,150918,155267,152795)) OR (`Idx`=4 AND `CreatureID`=152795);
UPDATE `creature_template_model` SET `CreatureDisplayID`=714, `VerifiedBuild`=46597 WHERE (`CreatureID`=98489 AND `Idx`=0); -- Shipwrecked Captive

UPDATE `creature_questitem` SET `VerifiedBuild`=46597 WHERE (`Idx`=0 AND `CreatureEntry` IN (102282,127503,99868,95833,164218,116802,95888,115831,164517,59479,157354,99200,28860,46753,97084,97083,97081,27483,99891,154638,98542,52148,122316,95843,96609,152359,152548,152556)) OR (`Idx`=5 AND `CreatureEntry` IN (99868,95888)) OR (`Idx`=4 AND `CreatureEntry` IN (99868,95888)) OR (`Idx`=3 AND `CreatureEntry` IN (99868,95888,99200)) OR (`Idx`=2 AND `CreatureEntry` IN (99868,164218,95888,157354,99200,99891,96609)) OR (`Idx`=1 AND `CreatureEntry` IN (99868,95833,164218,116802,95888,115831,164517,157354,99200,99891,96609,152359)) OR (`Idx`=6 AND `CreatureEntry`=95888);

UPDATE `gameobject_template` SET `VerifiedBuild`=46597 WHERE `entry` IN (246999, 252248, 246996, 246993, 193615, 246990, 247000, 247544, 246997, 246994, 247385, 246998, 246995, 246992, 247005, 193611, 247002, 251033, 259267, 259264, 242176, 259268, 259265, 242177, 242174, 251579, 224813, 245249, 251883, 252245, 246520, 244536, 148502, 244537, 244534, 270855, 259266, 242175);

UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=46366 WHERE `entry`=249733; -- Plasmatic Laser Bolt
