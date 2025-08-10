SET @CGUID := 10001067;
SET @OGUID := 10000010;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+356;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 211149, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3024.828125, 991.125, 514.3701171875, 1.972869157791137695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive, 424126 - Bot AI Follow Advert)
(@CGUID+1, 211151, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3016.380126953125, 986.44097900390625, 514.3701171875, 1.972869157791137695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive, 424126 - Bot AI Follow Advert)
(@CGUID+2, 228238, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3011.854248046875, 1080.953125, 522.7052001953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 459757 - Advert)
(@CGUID+3, 211150, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3027.502685546875, 987.6319580078125, 514.3701171875, 1.972869157791137695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive, 424126 - Bot AI Follow Advert)
(@CGUID+4, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3051.71533203125, 988.6492919921875, 514.065673828125, 3.911012887954711914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+5, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3013.748291015625, 984.748291015625, 514.3701171875, 3.930468559265136718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+6, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2928.56298828125, 1017.650390625, 516.274658203125, 5.612379074096679687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore) (possible waypoints or random movement)
(@CGUID+7, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3064.474853515625, 1068.7083740234375, 516.57171630859375, 0.266511023044586181, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+8, 228238, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3006.0556640625, 1140.3385009765625, 522.7052001953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 459757 - Advert)
(@CGUID+9, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3056.896240234375, 1031.7869873046875, 514.152587890625, 0.710844635963439941, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore) (possible waypoints or random movement)
(@CGUID+10, 211152, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3025.471435546875, 984.82464599609375, 514.3701171875, 1.972869157791137695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive, 424126 - Bot AI Follow Advert)
(@CGUID+11, 228238, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3016.309814453125, 1045.2535400390625, 514.16241455078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 459757 - Advert)
(@CGUID+12, 210930, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2990.916748046875, 1172.6458740234375, 523.7921142578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+13, 210930, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3015.483642578125, 1174.640625, 523.7921142578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+14, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3087.518310546875, 1055.626708984375, 515.11474609375, 5.328404426574707031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+15, 211111, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3022.028564453125, 986.97393798828125, 514.3701171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+16, 228534, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3032.618896484375, 988.5069580078125, 514.3701171875, 2.388514041900634765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sister Etna Blayze (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+17, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3109.290283203125, 1040.1668701171875, 516.314697265625, 0.816058695316314697, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore) (possible waypoints or random movement)
(@CGUID+18, 228359, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3007.3359375, 1125.2430419921875, 522.7052001953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 459918 - Advert)
(@CGUID+19, 211137, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3018.059814453125, 989.70831298828125, 514.3701171875, 1.972869157791137695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive, 424126 - Bot AI Follow Advert)
(@CGUID+20, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3070.358642578125, 983.67364501953125, 515.5001220703125, 5.24456644058227539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+21, 212827, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2816.267333984375, 1268.751708984375, 544.94171142578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- High Priest Aemya (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424996 - [DNT]Mellek Power Bar Color, 422355 - Bot AI Follow Advert)
(@CGUID+22, 212831, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3174.86474609375, 1306.46826171875, 553.64605712890625, 4.635531425476074218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Forge Master Damian (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+23, 212826, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2965.2421875, 1190.9501953125, 522.62188720703125, 4.189902305603027343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Guard Captain Suleyman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424652 - [DNT]Akritai Kagan Power Bar Color, 422355 - Bot AI Follow Advert)
(@CGUID+24, 211289, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2981.8046875, 1346.9913330078125, 546.6221923828125, 4.897131919860839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Taener Duelmal (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424628 - Strength in Numbers, 422355 - Bot AI Follow Advert, 424626 - Strength in Numbers)
(@CGUID+25, 211291, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2984.421875, 1344.0538330078125, 546.62213134765625, 4.897131919860839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sergeant Shaynemail (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424628 - Strength in Numbers, 422355 - Bot AI Follow Advert, 424626 - Strength in Numbers)
(@CGUID+26, 211290, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2987.34716796875, 1347.9600830078125, 546.6221923828125, 4.897131919860839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Elaena Emberlanz (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424628 - Strength in Numbers, 422355 - Bot AI Follow Advert, 424626 - Strength in Numbers)
(@CGUID+27, 207946, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2984.30810546875, 1347.4271240234375, 546.6221923828125, 4.897124290466308593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Captain Dailcry (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 444462 - Guard Captain Spawn Spell, 424652 - [DNT]Akritai Kagan Power Bar Color, 422356 - Bot AI Follow Advert)
(@CGUID+28, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3086.922119140625, 1067.975341796875, 514.120361328125, 5.19219207763671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore) (possible waypoints or random movement)
(@CGUID+29, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3014.869873046875, 1104.09375, 522.7052001953125, 4.722708702087402343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+30, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3003.911376953125, 1103.6197509765625, 522.7052001953125, 4.805735588073730468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+31, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2941.525634765625, 1055.94091796875, 514.0740966796875, 5.591228961944580078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore) (possible waypoints or random movement)
(@CGUID+32, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3076.634521484375, 1080.1944580078125, 516.5899658203125, 0.638153076171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+33, 228238, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3000.920166015625, 1206.09375, 522.72906494140625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 459757 - Advert)
(@CGUID+34, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2937.7109375, 1073.2100830078125, 515.8333740234375, 5.328404426574707031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+35, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3012.123291015625, 1106.7100830078125, 522.7052001953125, 4.737881183624267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+36, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2918.80126953125, 1051.579833984375, 516.0809326171875, 1.214002490043640136, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+37, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3007.4072265625, 1106.8785400390625, 522.7052001953125, 4.798428535461425781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+38, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2896.311767578125, 1070.07470703125, 515.63311767578125, 1.427701950073242187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+39, 207940, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2965.533935546875, 1502.15283203125, 574.677001953125, 4.758679866790771484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Prioress Murrpray (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424996 - [DNT]Mellek Power Bar Color, 422362 - Bot AI Follow Advert)
(@CGUID+40, 210930, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2973.041748046875, 1214.0728759765625, 522.7052001953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+41, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2900.496337890625, 1042.318603515625, 515.4281005859375, 5.591048717498779296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+42, 210931, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2972.29248046875, 1215.1492919921875, 522.7052001953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+43, 210932, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2971.865478515625, 1215.9375, 523.22314453125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+44, 210930, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2980.059814453125, 1220.2447509765625, 522.7052001953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+45, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2885.692626953125, 1059.732666015625, 515.3460693359375, 1.925470829010009765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+46, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2960.2900390625, 1138.916748046875, 526.6309814453125, 2.459917545318603515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2958.09423828125, 1139.400390625, 526.6199951171875, 2.468379497528076171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+48, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2961.5771484375, 1140.447998046875, 526.39715576171875, 2.460078716278076171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+49, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2892.525146484375, 1108.5711669921875, 515.8936767578125, 6.173816680908203125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+50, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2931.107666015625, 1145.54345703125, 527.40972900390625, 0.395760655403137207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+51, 210930, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2927.460205078125, 1240.079833984375, 547.53173828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+52, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2957.247802734375, 1145.191162109375, 526.213623046875, 2.485470771789550781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+53, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2933.23779296875, 1143.23095703125, 527.48223876953125, 0.650342881679534912, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+54, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2933.978271484375, 1146.095458984375, 527.017333984375, 3.95349884033203125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+55, 206696, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2955.26953125, 1144.1944580078125, 526.4591064453125, 2.48186349868774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Knight (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 448503 - [DNT]Generic Power Bar Color - Red/Rage) (possible waypoints or random movement)
(@CGUID+56, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2860.749755859375, 1109.9351806640625, 514.06732177734375, 5.932285308837890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+57, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2874.991455078125, 1148.8992919921875, 516.67938232421875, 0.699251830577850341, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+58, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2831.646240234375, 1095.042724609375, 522.72589111328125, 5.523767471313476562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+59, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2868.314208984375, 1171.2569580078125, 516.2640380859375, 0.506681323051452636, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+60, 210932, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2906.309814453125, 1275.49658203125, 546.9951171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+61, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2839.828125, 1150.7447509765625, 516.09295654296875, 1.436964988708496093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+62, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2852.741455078125, 1155.71533203125, 516.0323486328125, 1.661370396614074707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+63, 210930, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2932.30810546875, 1262.0816650390625, 547.58367919921875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+64, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2812.27294921875, 1123.896728515625, 524.82476806640625, 1.665935158729553222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore) (possible waypoints or random movement)
(@CGUID+65, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2836.546875, 1147.185791015625, 516.1669921875, 3.224025487899780273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+66, 210930, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2863.991455078125, 1266.8385009765625, 541.99542236328125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+67, 206696, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3003.065185546875, 1135.55908203125, 522.62188720703125, 4.79436492919921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Knight (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 448503 - [DNT]Generic Power Bar Color - Red/Rage) (possible waypoints or random movement)
(@CGUID+68, 206696, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3010.814453125, 1130.632080078125, 522.62188720703125, 4.786505699157714843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Knight (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 448503 - [DNT]Generic Power Bar Color - Red/Rage) (possible waypoints or random movement)
(@CGUID+69, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3000.5478515625, 1137.62841796875, 522.62188720703125, 4.978139877319335937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+70, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3004.1083984375, 1134.0743408203125, 522.62188720703125, 4.911753177642822265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+71, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3009.381103515625, 1130.843505859375, 522.62188720703125, 4.786432743072509765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+72, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3012.52001953125, 1126.7655029296875, 522.62188720703125, 1.64500582218170166, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+73, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3095.8525390625, 1091.8135986328125, 514.5457763671875, 4.205888748168945312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore) (possible waypoints or random movement)
(@CGUID+74, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3132.279052734375, 1065.412353515625, 515.40228271484375, 3.986813545227050781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore) (possible waypoints or random movement)
(@CGUID+75, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3107.1689453125, 1099.2508544921875, 514.06732177734375, 2.752225399017333984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore, 443738 - 11.0 Carry Crate - Arathi) (possible waypoints or random movement)
(@CGUID+76, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3104.268310546875, 1114.6007080078125, 514.150634765625, 2.35869145393371582, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+77, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3057.331298828125, 1156.577880859375, 526.57196044921875, 3.835248708724975585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+78, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3058.395263671875, 1153.043212890625, 526.64599609375, 4.14315032958984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+79, 206696, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3054.084228515625, 1150.5260009765625, 526.4747314453125, 4.209538936614990234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Knight (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 448503 - [DNT]Generic Power Bar Color - Red/Rage) (possible waypoints or random movement)
(@CGUID+80, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3055.59228515625, 1155.7977294921875, 526.4697265625, 3.889017105102539062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+81, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3058.765625, 1155.2484130859375, 526.5810546875, 4.112866401672363281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+82, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3155.041748046875, 1130.364990234375, 513.92401123046875, 3.466741561889648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+83, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3131.25, 1150, 515.9407958984375, 1.923061609268188476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+84, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3079.116455078125, 1160.6961669921875, 527.04510498046875, 2.693538188934326171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+85, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3159.86083984375, 1130.6326904296875, 514.99908447265625, 5.638265609741210937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+86, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3077.604248046875, 1158.810791015625, 527.0135498046875, 2.047199010848999023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+87, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3161.309814453125, 1131.8876953125, 515.29730224609375, 0.637054622173309326, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+88, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3131.214599609375, 1147.57177734375, 515.6962890625, 3.434920787811279296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+89, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3131.36669921875, 1148.2684326171875, 515.73333740234375, 2.483633756637573242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+90, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3077.036376953125, 1160.9427490234375, 526.97015380859375, 5.588274955749511718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+91, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3149.456298828125, 1168.64208984375, 515.13519287109375, 0.402454972267150878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+92, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3148.09521484375, 1167.6953125, 515.21527099609375, 0.697288811206817626, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+93, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3144.99169921875, 1170.5401611328125, 515.3204345703125, 1.721342444419860839, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+94, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3173.42333984375, 1172.264892578125, 516.92010498046875, 2.181282281875610351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+95, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3173.411376953125, 1170.2747802734375, 516.7305908203125, 2.478462696075439453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+96, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3171.351806640625, 1170.8310546875, 516.39990234375, 3.084902048110961914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+97, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3198.3369140625, 1139.66845703125, 526.40765380859375, 1.122902631759643554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore) (possible waypoints or random movement)
(@CGUID+98, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3132.291015625, 1204.1669921875, 514.86328125, 5.050455093383789062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+99, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3158.458984375, 1189.605224609375, 514.37835693359375, 4.48447275161743164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+100, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3156.9833984375, 1191.445556640625, 514.37103271484375, 2.618575096130371093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+101, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3156.632568359375, 1189.94970703125, 514.197509765625, 4.166108131408691406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+102, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3175.44921875, 1194.4287109375, 519.28289794921875, 3.571614027023315429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+103, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3133.775634765625, 1207.5640869140625, 515.15576171875, 0.143842518329620361, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+104, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3131.38671875, 1209.200439453125, 515.31890869140625, 1.135079026222229003, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+105, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3178.5, 1195.157958984375, 519.864013671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+106, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3197.912353515625, 1166.0875244140625, 522.91558837890625, 4.87174224853515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore) (possible waypoints or random movement)
(@CGUID+107, 222936, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3177.539306640625, 1192.204345703125, 519.4801025390625, 4.318373680114746093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sweet-sting Worker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+108, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3129.412353515625, 1243.3785400390625, 547.0074462890625, 4.683915138244628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+109, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3151.91748046875, 1245.6927490234375, 547.067626953125, 4.683915138244628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+110, 206710, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3147.72216796875, 1274.4461669921875, 547.680419921875, 6.168692588806152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Lightspawn (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+111, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3122.529541015625, 1254.2413330078125, 546.50433349609375, 0.131140440702438354, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+112, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3178.55810546875, 1258.4166259765625, 546.51165771484375, 3.24560713768005371, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+113, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3174.8828125, 1248.1180419921875, 547.13116455078125, 4.683915138244628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+114, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3122.7822265625, 1252.1319580078125, 546.45550537109375, 0.131140440702438354, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+115, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3178.132080078125, 1261.8385009765625, 546.5120849609375, 3.24560713768005371, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+116, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3150.552001953125, 1272.515625, 547.68035888671875, 2.336456298828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+117, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3149.592041015625, 1275.986083984375, 547.6842041015625, 4.936798095703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+118, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3151.6103515625, 1274.5867919921875, 547.6834716796875, 3.27950596809387207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+119, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3126.001708984375, 1282.4298095703125, 547.6090087890625, 4.755825042724609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+120, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3129.996826171875, 1281.144287109375, 547.60894775390625, 4.7733917236328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+121, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3128.02294921875, 1280.7884521484375, 547.60894775390625, 4.771054744720458984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+122, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3124.239501953125, 1276.731689453125, 547.6090087890625, 4.759614944458007812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+123, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3102.0390625, 1273.295166015625, 547.69305419921875, 5.4877471923828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+124, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3088.4541015625, 1271.623291015625, 547.6923828125, 4.116162776947021484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+125, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3075.76904296875, 1252.220458984375, 547.52899169921875, 6.020846843719482421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+126, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3077.376708984375, 1243.513916015625, 547.68975830078125, 5.73646402359008789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+127, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3075.962646484375, 1250.23095703125, 547.50872802734375, 0.60987025499343872, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+128, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3095.2109375, 1270.157958984375, 547.6923828125, 5.1035614013671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+129, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3073.7509765625, 1240.7413330078125, 547.67828369140625, 5.108476638793945312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+130, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3002.263916015625, 1164.5521240234375, 523.792236328125, 4.800030231475830078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+131, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3005.842041015625, 1164.8021240234375, 523.8157958984375, 4.755541324615478515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+132, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3003.999267578125, 1165.28125, 523.792724609375, 4.800030231475830078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+133, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3017.483642578125, 1179.12158203125, 523.79827880859375, 0.224223241209983825, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+134, 221844, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3002.408935546875, 1179.8958740234375, 524.86212158203125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Eternal Flame (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+135, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3017.123291015625, 1183.6492919921875, 523.7437744140625, 0.179734617471694946, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+136, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2987.252685546875, 1179.8992919921875, 523.7921142578125, 3.14440321922302246, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+137, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2987.685791015625, 1175.6285400390625, 523.7921142578125, 3.279421091079711914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+138, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3017.229248046875, 1181.560791015625, 523.9967041015625, 0.224223241209983825, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+139, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2987.95751953125, 1177.57470703125, 524.04132080078125, 2.98426365852355957, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+140, 210931, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2905.564208984375, 1276.2864990234375, 546.9951171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+141, 210930, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2907.0234375, 1276.546875, 546.9951171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+142, 228238, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2887.80126953125, 1276.12158203125, 546.9951171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 459757 - Advert)
(@CGUID+143, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2979.862060546875, 1231.05908203125, 522.7052001953125, 6.079386234283447265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+144, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2979.99658203125, 1232.4271240234375, 522.7052001953125, 5.930760860443115234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+145, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2982.163330078125, 1230.953125, 522.7052001953125, 2.267870187759399414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+146, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3014.57373046875, 1236.37158203125, 522.7052001953125, 3.110996007919311523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+147, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3013.827392578125, 1237.8819580078125, 522.7052001953125, 4.402461528778076171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+148, 210930, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2884.177978515625, 1288.1163330078125, 546.661865234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+149, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2932.862060546875, 1208.6285400390625, 527.0281982421875, 2.000167369842529296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+150, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2995.630126953125, 1241.2083740234375, 522.7052001953125, 1.1755906343460083, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+151, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3012.270751953125, 1238.0035400390625, 522.7052001953125, 5.492358207702636718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+152, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2933.397705078125, 1212.0833740234375, 527.0281982421875, 4.286242485046386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+153, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2993.943603515625, 1244.2708740234375, 522.7052001953125, 5.838038921356201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+154, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2998.546875, 1243.7535400390625, 522.7052001953125, 3.425614595413208007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+155, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2930.401123046875, 1210.2569580078125, 527.0281982421875, 0.175320148468017578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+156, 210930, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2849.23876953125, 1280.71875, 540.64605712890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+157, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2921.45751953125, 1231.6944580078125, 547.693603515625, 3.012269496917724609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+158, 221700, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2913.689208984375, 1231.4930419921875, 546.8299560546875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dummy Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+159, 221700, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2913.880126953125, 1234.7691650390625, 546.60736083984375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dummy Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+160, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2932.95068359375, 1250.223388671875, 547.562255859375, 0.965954482555389404, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+161, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2921.30908203125, 1234.8629150390625, 547.69561767578125, 3.067004919052124023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+162, 221700, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2913.12841796875, 1237.9097900390625, 547.8284912109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dummy Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+163, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2920.897705078125, 1237.90283203125, 547.699951171875, 2.956231355667114257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+164, 221700, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2913.637939453125, 1234.7916259765625, 547.7286376953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dummy Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+165, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2932.333740234375, 1256.006103515625, 547.6466064453125, 0.902553558349609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+166, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2935.8857421875, 1257.44091796875, 547.69854736328125, 0.802201390266418457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+167, 206710, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2856.068603515625, 1263.0833740234375, 540.64605712890625, 4.786341667175292968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Lightspawn (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+168, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2952.440185546875, 1282.251708984375, 551.5074462890625, 2.435910224914550781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+169, 210931, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2981.182373046875, 1380.720458984375, 555.3258056640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+170, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2957.0234375, 1285.6007080078125, 551.5074462890625, 1.651881575584411621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+171, 213991, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2962.067626953125, 1293.4444580078125, 551.66754150390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dummy Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+172, 213991, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2943.510498046875, 1283.7847900390625, 551.6468505859375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dummy Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+173, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3032.8974609375, 1284.516845703125, 551.60345458984375, 2.427249908447265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+174, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3036.29931640625, 1279.1796875, 551.6732177734375, 2.49213409423828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+175, 213991, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2950.310791015625, 1292.439208984375, 551.5074462890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dummy Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+176, 213991, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3020.100830078125, 1299.3680419921875, 551.603271484375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dummy Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+177, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3037.124755859375, 1283.498779296875, 551.64459228515625, 5.568680286407470703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+178, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3029.75439453125, 1289.6007080078125, 551.5074462890625, 0.985338687896728515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+179, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3024.487060546875, 1290.765625, 551.5074462890625, 1.438985824584960937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+180, 213991, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3038.86279296875, 1293.5867919921875, 551.58660888671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dummy Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+181, 213991, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3030.966064453125, 1300.2899169921875, 551.5074462890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dummy Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+182, 207939, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2970.53564453125, 1502.59375, 574.67132568359375, 4.98909759521484375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Baron Braunpyke (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422359 - Bot AI Follow Advert)
(@CGUID+183, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3048.9150390625, 1311.513916015625, 546.90582275390625, 2.410805702209472656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 55474 - Cosmetic - Sleep Zzz)
(@CGUID+184, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3052.903564453125, 1311.1475830078125, 547.1607666015625, 2.536851167678833007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+185, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3051.3828125, 1309.0885009765625, 547.29388427734375, 2.144041776657104492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+186, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3049.588134765625, 1317.177978515625, 546.652099609375, 2.467614412307739257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+187, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3041.7255859375, 1319.360107421875, 547.39666748046875, 5.610579490661621093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+188, 206710, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3046.283935546875, 1374.5850830078125, 546.6148681640625, 2.167018413543701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Lightspawn (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+189, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3083.0556640625, 1343.19970703125, 546.55206298828125, 1.061138629913330078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+190, 206696, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3077.690673828125, 1346.1475830078125, 546.49017333984375, 5.188236713409423828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Knight (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 448503 - [DNT]Generic Power Bar Color - Red/Rage) (possible waypoints or random movement)
(@CGUID+191, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3077.870849609375, 1345.269287109375, 546.4974365234375, 4.815700054168701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+192, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3075.855224609375, 1344.0538330078125, 546.4974365234375, 4.92683267593383789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+193, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3083.9462890625, 1346.09375, 546.6317138671875, 4.930875778198242187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+194, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3097.936767578125, 1358.3316650390625, 520.39666748046875, 2.448990821838378906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+195, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3150.2119140625, 1333.298583984375, 547.69232177734375, 1.593893408775329589, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+196, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3047.388916015625, 1378.326416015625, 546.6578369140625, 3.478334426879882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+197, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3156.549560546875, 1332.4913330078125, 547.69232177734375, 2.207272529602050781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+198, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3046.51904296875, 1377.3021240234375, 546.65777587890625, 2.432312965393066406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+199, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3099.6875, 1360.998291015625, 520.44329833984375, 2.448990821838378906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+200, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3154.1494140625, 1332.484375, 547.69232177734375, 1.76611793041229248, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+201, 210931, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2973.31591796875, 1453.1353759765625, 562.4598388671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+202, 213535, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 3175.493896484375, 1318.513916015625, 521.37335205078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Forge Stalker (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+203, 207940, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2940.544189453125, 1766.2916259765625, 633.024169921875, 4.816413402557373046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Prioress Murrpray (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 424996 - [DNT]Mellek Power Bar Color, 422362 - Bot AI Follow Advert)
(@CGUID+204, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3055.596435546875, 1392.51220703125, 520.3890380859375, 5.506337642669677734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+205, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3057.569580078125, 1395.029541015625, 520.44146728515625, 5.506337642669677734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+206, 210931, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2983.70751953125, 1491.7396240234375, 562.3446044921875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+207, 210931, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2953.934814453125, 1489.9444580078125, 562.25408935546875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+208, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2947.37841796875, 1305.9444580078125, 547.701416015625, 2.179618120193481445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+209, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2944.585205078125, 1310.4879150390625, 547.9913330078125, 4.853983879089355468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+210, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2942.907958984375, 1308.9461669921875, 548.3697509765625, 5.031209945678710937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+211, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2944.96533203125, 1305.6510009765625, 548.22393798828125, 1.519297122955322265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+212, 206699, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2946.6650390625, 1310.076416015625, 547.5555419921875, 4.853983879089355468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- War Lynx (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+213, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2933.747314453125, 1366.498291015625, 547.875, 2.255017757415771484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+214, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2931.32470703125, 1367.8663330078125, 547.8228759765625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+215, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2933.427978515625, 1368.765625, 548.18572998046875, 4.364704608917236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+216, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2913.028564453125, 1354.732666015625, 546.474609375, 0.803243458271026611, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+217, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2915.440185546875, 1354.2882080078125, 546.47515869140625, 1.893138885498046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+218, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2914.16748046875, 1356.1771240234375, 546.474609375, 5.314606189727783203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+219, 206710, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2866.43408203125, 1378.3333740234375, 548.31219482421875, 4.483088016510009765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Lightspawn (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+220, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2884.609375, 1331.9947509765625, 546.5782470703125, 4.502454280853271484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+221, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2886.354248046875, 1332.88720703125, 546.58624267578125, 4.121564865112304687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+222, 210932, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2967.021728515625, 1517.1336669921875, 588.7655029296875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+223, 206710, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2845.889892578125, 1284.3228759765625, 540.64813232421875, 1.825476050376892089, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Lightspawn (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+224, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2886.03466796875, 1330.5538330078125, 546.577880859375, 4.128150463104248046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+225, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2877.400146484375, 1291.126708984375, 547.2947998046875, 0.337922126054763793, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+226, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2879.905517578125, 1290.8785400390625, 547.10980224609375, 2.332555770874023437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+227, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2879.1181640625, 1292.826416015625, 547.29705810546875, 5.032727241516113281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+228, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2864.5546875, 1376.2899169921875, 548.31219482421875, 0.454920113086700439, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+229, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2866.835205078125, 1376.0833740234375, 548.31219482421875, 2.564605951309204101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+230, 207949, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2968.66748046875, 1439.185791015625, 562.18511962890625, 4.78213357925415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Zealous Templar (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+231, 206704, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2972.493896484375, 1438.9947509765625, 562.18511962890625, 4.78213357925415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+232, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2847.353271484375, 1286.4478759765625, 540.65234375, 3.116338491439819335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+233, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2843.94873046875, 1286.123291015625, 540.6494140625, 0.15783064067363739, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+234, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2858.23779296875, 1260.4774169921875, 540.64605712890625, 3.116338491439819335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+235, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2854.833251953125, 1260.15283203125, 540.64605712890625, 0.15783064067363739, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+236, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2832.540771484375, 1276.685791015625, 540.64605712890625, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+237, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2829.848876953125, 1271.9947509765625, 540.64605712890625, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+238, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2827.157958984375, 1267.3055419921875, 540.64599609375, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+239, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2832.842041015625, 1272.1944580078125, 540.64605712890625, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+240, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2862.858642578125, 1232.09375, 546.38909912109375, 1.326023101806640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+241, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2830.151123046875, 1267.5052490234375, 540.64605712890625, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+242, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2833.143310546875, 1267.704833984375, 540.64605712890625, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+243, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2858.974853515625, 1232.0867919921875, 546.39483642578125, 1.446682929992675781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+244, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2830.453125, 1263.015625, 540.64605712890625, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+245, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2833.447998046875, 1263.21533203125, 540.64605712890625, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+246, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2826.552001953125, 1276.2847900390625, 540.644287109375, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+247, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2829.546875, 1276.484375, 540.64581298828125, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+248, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2826.856689453125, 1271.795166015625, 540.64599609375, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+249, 207943, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2827.459228515625, 1262.814208984375, 540.64593505859375, 3.251659631729125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+250, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2865.848876953125, 1216.7257080078125, 547.00604248046875, 4.683915138244628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+251, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2842.493896484375, 1214.1961669921875, 547.06170654296875, 4.683915138244628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+252, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2846.748291015625, 1200.5555419921875, 515.25946044921875, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+253, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2856.837646484375, 1201.09033203125, 515.2586669921875, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+254, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2855.08251953125, 1201.09033203125, 515.26214599609375, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+255, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2858.70751953125, 1201.09033203125, 515.2568359375, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+256, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2856.85498046875, 1198.642333984375, 515.2669677734375, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+257, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2855.0322265625, 1198.642333984375, 515.2705078125, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+258, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2858.778564453125, 1198.642333984375, 515.34027099609375, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+259, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2843.07373046875, 1198.107666015625, 515.26611328125, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+260, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2843.123291015625, 1200.5555419921875, 515.25946044921875, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+261, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2814.794189453125, 1223.140625, 546.51043701171875, 0.131140440702438354, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+262, 206705, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2815.44873046875, 1219.7135009765625, 546.50897216796875, 0.131140440702438354, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Footman (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+263, 206694, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2819.283935546875, 1211.8072509765625, 547.12109375, 4.683915138244628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fervent Sharpshooter (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+264, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2844.87939453125, 1200.5555419921875, 515.25946044921875, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+265, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2846.8203125, 1198.107666015625, 515.26611328125, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+266, 222927, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2844.896728515625, 1198.107666015625, 515.26611328125, 1.637440323829650878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sacred Flame Vintner (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 436736 - Ignore)
(@CGUID+267, 206704, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3003.87060546875, 1482.892333984375, 562.1851806640625, 3.319251060485839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+268, 212838, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2966.587646484375, 1462.1180419921875, 562.248046875, 1.609863877296447753, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+269, 207949, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3005.538330078125, 1470.55908203125, 562.1851806640625, 3.319251060485839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Zealous Templar (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+270, 212838, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2977.755126953125, 1462.717041015625, 562.2496337890625, 1.640576481819152832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+271, 212838, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2977.5869140625, 1466.3489990234375, 562.25439453125, 1.640576481819152832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+272, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3008.521728515625, 1477.80908203125, 562.20880126953125, 3.319251060485839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+273, 207949, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2937.57373046875, 1475.923583984375, 562.1851806640625, 0.128405913710594177, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Zealous Templar (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+274, 212838, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2969.796142578125, 1462.170166015625, 562.27020263671875, 1.640576481819152832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+275, 212838, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2969.626708984375, 1465.8021240234375, 562.25933837890625, 1.640576481819152832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+276, 206704, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2977.143310546875, 1439.3992919921875, 562.18511962890625, 4.78213357925415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+277, 206704, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3001.552001953125, 1476.28125, 562.1851806640625, 3.319251060485839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+278, 212838, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2974.546875, 1462.6649169921875, 562.2728271484375, 1.609863877296447753, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+279, 207949, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2938.79345703125, 1463.19970703125, 562.1851806640625, 0.128405913710594177, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Zealous Templar (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+280, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2935.564208984375, 1469.720458984375, 562.1851806640625, 0.128405913710594177, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+281, 212838, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2966.41845703125, 1465.75, 562.2518310546875, 1.609863877296447753, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+282, 212838, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 0, 2974.37841796875, 1466.296875, 562.25921630859375, 1.609863877296447753, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Arathi Neophyte (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+283, 206704, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2941.0869140625, 1469.8507080078125, 562.1851806640625, 0.128405913710594177, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+284, 207949, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2981.0400390625, 1440.048583984375, 562.18511962890625, 4.78213357925415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Zealous Templar (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+285, 206704, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2933.5478515625, 1498.046875, 574.282958984375, 4.912889957427978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+286, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2998.546875, 1508.3663330078125, 578.1719970703125, 5.220720767974853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@CGUID+287, 206704, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3006.209228515625, 1509.888916015625, 575.0030517578125, 5.220720767974853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+288, 206704, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2929.999267578125, 1500.1336669921875, 574.2083740234375, 4.912889957427978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+289, 207949, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3001.349853515625, 1505.9930419921875, 575.48876953125, 5.220720767974853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Zealous Templar (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+290, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2934.627685546875, 1500.7117919921875, 576.39996337890625, 4.912889957427978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+291, 206698, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 3001.911376953125, 1512.7083740234375, 578.173095703125, 5.220720767974853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Fanatical Conjuror (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+292, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2931.432373046875, 1503.1475830078125, 576.28631591796875, 4.912889957427978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+293, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2959.005126953125, 1554.8055419921875, 588.81402587890625, 4.840570926666259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+294, 206697, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2966.90625, 1555.875, 588.81390380859375, 4.840570926666259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+295, 206704, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2961.4619140625, 1550.0833740234375, 588.81597900390625, 4.840570926666259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+296, 206704, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2965.15283203125, 1550.388916015625, 588.81597900390625, 4.840570926666259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+297, 207949, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2968.815185546875, 1550.68408203125, 588.8160400390625, 4.840570926666259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Zealous Templar (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+298, 207949, 2649, 14954, 15460, '1,2,8,23', '0', 0, 0, 1, 2957.796875, 1549.732666015625, 588.81597900390625, 4.840570926666259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Zealous Templar (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+299, 210932, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2932.09814453125, 1688.3836669921875, 624.07049560546875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+300, 210932, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2965.710205078125, 1691.0191650390625, 624.071044921875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+301, 206710, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2963.4619140625, 1683.8350830078125, 624.12530517578125, 2.116359233856201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Lightspawn (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+302, 210932, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2954.420166015625, 1753.298583984375, 624.07611083984375, 2.042668581008911132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+303, 206710, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2938.118896484375, 1691.361083984375, 624.04669189453125, 1.135558009147644042, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Lightspawn (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+304, 210932, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2930.694580078125, 1751.451416015625, 624.38519287109375, 2.042668581008911132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+305, 206710, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2975.10498046875, 1700.12158203125, 625.22064208984375, 1.336265087127685546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Lightspawn (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+306, 206704, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2954.302978515625, 1669.4757080078125, 623.9544677734375, 4.790984630584716796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+307, 206704, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2947.145751953125, 1668.7291259765625, 623.95501708984375, 4.790984630584716796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+308, 221760, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2940.584228515625, 1692.9635009765625, 624.0826416015625, 2.833019495010375976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Mage (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+309, 206697, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2950.436767578125, 1673.0416259765625, 624.6201171875, 4.790984630584716796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+310, 221760, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2960.540771484375, 1684.9947509765625, 624.12530517578125, 0.34050750732421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Mage (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+311, 206697, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2963.779541015625, 1686.8941650390625, 624.1417236328125, 3.828150033950805664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+312, 212835, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2920.741455078125, 1698.7396240234375, 625.580078125, 3.234839439392089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Footman (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+313, 206697, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2971.572998046875, 1704.4375, 625.22064208984375, 6.277350902557373046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+314, 212835, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2974.279541015625, 1704.4617919921875, 625.22064208984375, 6.277350902557373046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Footman (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+315, 221760, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2920.94189453125, 1702.5242919921875, 625.2205810546875, 4.743204593658447265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Mage (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+316, 206697, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2923.21435546875, 1699.3333740234375, 625.22064208984375, 3.234839439392089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+317, 206697, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2937.341064453125, 1694.3177490234375, 624.09423828125, 5.824481487274169921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+318, 221760, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2972.97314453125, 1701.8021240234375, 625.22064208984375, 1.069597959518432617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Mage (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+319, 206704, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2922.41845703125, 1695.6788330078125, 625.22064208984375, 2.456939697265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ardent Paladin (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+320, 221760, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2965.16064453125, 1728.6346435546875, 624.1295166015625, 0.090141020715236663, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Mage (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+321, 206697, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2954.03125, 1727.625, 624.389404296875, 2.489510297775268554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+322, 206697, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2935.55029296875, 1725.73095703125, 624.37835693359375, 0.817626118659973144, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+323, 217658, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2944.111083984375, 1733.0885009765625, 624.41876220703125, 4.776658058166503906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Sir Braunpyke (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death, 422360 - Bot AI Follow Advert) (possible waypoints or random movement)
(@CGUID+324, 226501, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2936.532958984375, 1824.4149169921875, 652.8065185546875, 3.550872087478637695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 455828 - Advert)
(@CGUID+325, 226510, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2937.34033203125, 1842.5225830078125, 652.98724365234375, 4.721851825714111328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Path Helper (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 455862 - Advert)
(@CGUID+326, 212835, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2962.95654296875, 1759.1007080078125, 625.2205810546875, 4.662896156311035156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Footman (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+327, 212835, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2967.423583984375, 1759.611083984375, 625.2205810546875, 4.765270709991455078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Footman (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+328, 212835, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2958.228271484375, 1758.829833984375, 624.05078125, 4.804168701171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Footman (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+329, 212835, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2920.244873046875, 1753.2222900390625, 625.2205810546875, 4.656404018402099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Footman (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+330, 212835, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2915.71875, 1753.123291015625, 625.2205810546875, 4.920167922973632812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Footman (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+331, 212835, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2924.885498046875, 1753.7117919921875, 624.0601806640625, 4.590886592864990234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Risen Footman (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+332, 211138, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2922.4453125, 1764.1927490234375, 624.0318603515625, 1.487712621688842773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Mellek Zombie Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+333, 206697, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2916.436767578125, 1764.609375, 624.0318603515625, 0.844131529331207275, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+334, 211138, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2960.29248046875, 1767.7396240234375, 624.0318603515625, 1.624181985855102539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Mellek Zombie Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+335, 206697, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 1, 2965.02783203125, 1771.126708984375, 624.1217041015625, 2.176904678344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Devout Priest (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+336, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2939.209228515625, 1776.1875, 632.564208984375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+337, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2904.599853515625, 1785.2430419921875, 639.822509765625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+338, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2970.553955078125, 1791.203125, 638.85662841796875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+339, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2988.374267578125, 1788.5816650390625, 645.7471923828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+340, 228805, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2987.52685546875, 1795.59375, 645.74713134765625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Upper Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+341, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2937.28564453125, 1795.8819580078125, 632.5147705078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+342, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2970.788330078125, 1818.2222900390625, 645.7471923828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+343, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2886.9072265625, 1777.857666015625, 645.7471923828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+344, 228805, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2885.444580078125, 1784.8211669921875, 645.7471923828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Upper Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+345, 210851, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2935.395751953125, 1816.9410400390625, 652.8140869140625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Eternal Flame (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 444548 - Sacred Flame)
(@CGUID+346, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2895.544189453125, 1813.623291015625, 645.7471923828125, 0.310253471136093139, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+347, 228805, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2968.47314453125, 1830.0867919921875, 645.7471923828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Upper Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+348, 228805, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2900.1875, 1822.296875, 645.7471923828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Upper Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+349, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2959.772705078125, 1853.3333740234375, 645.73876953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+350, 228805, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2932.481689453125, 1840.88720703125, 652.8065185546875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Upper Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+351, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2882.60595703125, 1823.640625, 645.84375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+352, 228805, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2973.616455078125, 1862.40625, 645.94915771484375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Upper Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+353, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2982.84814453125, 1856.3941650390625, 645.94140625, 0.310253471136093139, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+354, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2904.764892578125, 1846.513916015625, 645.7381591796875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)
(@CGUID+355, 221737, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2879.382080078125, 1848.9271240234375, 645.9490966796875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+356, 228805, 2649, 14954, 0, '1,2,8,23', '0', 0, 0, 0, 2888.21533203125, 1855.15625, 645.94940185546875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56421); -- Upper Platform Stalker (Area: 0 - Difficulty: Normal) CreateObject1 (Auras: 451855 - [DNT]Holy Cosmetic Missiles)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+356;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+53, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+57, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+59, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+61, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+65, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+76, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+90, 0, 0, 0, 0, 0, 1, 0, 641, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+108, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+109, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+111, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+112, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+113, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+114, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+115, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+123, 0, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+124, 0, 0, 0, 0, 0, 0, 0, 641, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+128, 0, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+130, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+131, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+132, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+133, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+135, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+136, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+137, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+138, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+139, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+143, 0, 0, 0, 0, 0, 0, 0, 461, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+144, 0, 0, 0, 0, 0, 0, 0, 461, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+156, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422354'), -- Path Helper - 422354 - Bot AI Follow Advert
(@CGUID+157, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+161, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+163, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+183, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '55474'), -- War Lynx - 55474 - Cosmetic - Sleep Zzz
(@CGUID+189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+194, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+195, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+198, 0, 0, 0, 0, 0, 0, 0, 641, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+199, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+200, 0, 0, 0, 0, 0, 0, 0, 641, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+204, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+205, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+209, 0, 0, 0, 0, 0, 1, 0, 10, 0, 0, 0, 0, ''), -- War Lynx
(@CGUID+210, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- War Lynx
(@CGUID+212, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- War Lynx
(@CGUID+213, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+220, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+221, 0, 0, 0, 0, 0, 0, 0, 641, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+224, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+226, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+227, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+229, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+230, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Zealous Templar
(@CGUID+231, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '422357'), -- Ardent Paladin - 422357 - Bot AI Follow Advert
(@CGUID+232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+233, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+234, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fanatical Conjuror
(@CGUID+235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Devout Priest
(@CGUID+236, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+237, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+239, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+240, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+241, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+242, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+243, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+244, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+245, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+246, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+247, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+248, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+249, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+250, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+251, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+252, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+253, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+254, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+255, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+256, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+257, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+258, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+259, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+260, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+261, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+262, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Arathi Footman
(@CGUID+263, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Fervent Sharpshooter
(@CGUID+264, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+265, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+266, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- Sacred Flame Vintner - 436736 - Ignore
(@CGUID+268, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+270, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+271, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+274, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+275, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+276, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '422357'), -- Ardent Paladin - 422357 - Bot AI Follow Advert
(@CGUID+278, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+281, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+282, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Neophyte
(@CGUID+284, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''); -- Zealous Templar

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+28;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 423349, 2649, 14954, 15460, '1,2,8,23', '0', 0, 3002.552978515625, 1179.876708984375, 524.7786865234375, 0, 0, 0, 0, 1, 7200, 255, 1, 56421), -- Sacred Flame (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+1, 465811, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2863.4296875, 1104.782958984375, 514.06732177734375, 1.517618536949157714, 0, 0, 0.688057899475097656, 0.725655794143676757, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+2, 465823, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2879.28125, 1123.28125, 514.06695556640625, 3.224509477615356445, 0, 0, -0.99914073944091796, 0.041446421295404434, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+3, 452050, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2940.436279296875, 1766.9017333984375, 633.12872314453125, 1.658262372016906738, 0, 0, 0.737344741821289062, 0.675516664981842041, 7200, 255, 0, 56421), -- 10FX_Generic_Fire_Barrier (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+4, 441669, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2965.2060546875, 1531.89453125, 588.86773681640625, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 7200, 255, 1, 56421), -- 11AT_Arathor_Navigation_Door01 (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+5, 441668, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2975.526123046875, 1433.7069091796875, 562.28009033203125, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 7200, 255, 1, 56421), -- 11AT_Arathor_Navigation_Door01 (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+6, 441671, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2961.770751953125, 1564.5789794921875, 588.8709716796875, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 7200, 255, 1, 56421), -- Priory Door (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+7, 441670, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2952.781005859375, 1650.0657958984375, 624.2435302734375, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 7200, 255, 1, 56421), -- Priory Door (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+8, 442665, 2649, 14954, 15460, '1,2,8,23', '0', 0, 3007.930908203125, 1478.09716796875, 562.28009033203125, 3.246310710906982421, 0, 0, -0.99862957000732421, 0.05233500525355339, 7200, 255, 0, 56421), -- 10FX_Generic_Fire_Barrier (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+9, 442664, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2934.409423828125, 1470.7960205078125, 562.28009033203125, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 7200, 255, 0, 56421), -- 10FX_Generic_Fire_Barrier (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+10, 465814, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2878.93408203125, 1126.8367919921875, 514.06695556640625, 3.2594146728515625, 0, 0, -0.99826526641845703, 0.058876879513263702, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+11, 465772, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2859.708251953125, 1104.9774169921875, 514.06732177734375, 1.522787213325500488, 0, 0, 0.689930915832519531, 0.723875224590301513, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+12, 465742, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2865.32470703125, 1140.2603759765625, 514.06695556640625, 4.52475738525390625, 0, 0, -0.77023792266845703, 0.637756645679473876, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+13, 465769, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2861.565185546875, 1140.9305419921875, 514.06695556640625, 4.559663772583007812, 0, 0, -0.75899028778076171, 0.651101946830749511, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+14, 465796, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2843.751708984375, 1118.40283203125, 514.06695556640625, 0.178884491324424743, 0, 0, 0.089323043823242187, 0.996002674102783203, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+15, 465747, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2846.872314453125, 1134.388916015625, 514.0777587890625, 5.510868072509765625, 0, 0, -0.3766326904296875, 0.926362693309783935, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+16, 465753, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2843.225830078125, 1122.0555419921875, 514.06695556640625, 0.117797277867794036, 0, 0, 0.058864593505859375, 0.998265981674194335, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+17, 465826, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2849.5078125, 1136.96533203125, 514.0791015625, 5.475960254669189453, 0, 0, -0.39274311065673828, 0.919648230075836181, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+18, 465795, 2649, 14954, 15460, '1,2,8,23', '0', 0, 2851.5478515625, 1200.2864990234375, 515.1788330078125, 1.673209071159362792, 0, 0, 0.742372512817382812, 0.669987380504608154, 7200, 255, 1, 56421), -- Bench (Area: Sanctified Grounds - Difficulty: Normal) CreateObject1
(@OGUID+19, 414273, 2649, 14954, 0, '1,2,8,23', '0', 0, 2925.5625, 1758.7274169921875, 623.98541259765625, 3.871746540069580078, 0, 0, -0.93409633636474609, 0.357021093368530273, 86400, 255, 1, 56421), -- [DNT]Covered Body (Area: 0 - Difficulty: Heroic) CreateObject1
(@OGUID+20, 414273, 2649, 14954, 0, '1,2,8,23', '0', 0, 2957.044189453125, 1762.5572509765625, 623.9671630859375, 5.808022975921630859, 0, 0, -0.2353525161743164, 0.971910059452056884, 86400, 255, 1, 56421), -- [DNT]Covered Body (Area: 0 - Difficulty: Heroic) CreateObject1
(@OGUID+21, 414273, 2649, 14954, 0, '1,2,8,23', '0', 0, 2958.24560546875, 1765.21533203125, 623.94854736328125, 5.808022975921630859, 0, 0, -0.2353525161743164, 0.971910059452056884, 86400, 255, 1, 56421), -- [DNT]Covered Body (Area: 0 - Difficulty: Heroic) CreateObject1
(@OGUID+22, 414273, 2649, 14954, 0, '1,2,8,23', '0', 0, 2923.591064453125, 1761.170166015625, 623.94854736328125, 3.871746540069580078, 0, 0, -0.93409633636474609, 0.357021093368530273, 86400, 255, 1, 56421), -- [DNT]Covered Body (Area: 0 - Difficulty: Heroic) CreateObject1
(@OGUID+23, 414273, 2649, 14954, 0, '1,2,8,23', '0', 0, 2921.822021484375, 1763.5833740234375, 623.94854736328125, 3.871746540069580078, 0, 0, -0.93409633636474609, 0.357021093368530273, 86400, 255, 1, 56421), -- [DNT]Covered Body (Area: 0 - Difficulty: Heroic) CreateObject1
(@OGUID+24, 414273, 2649, 14954, 0, '1,2,8,23', '0', 0, 2919.661376953125, 1765.8021240234375, 623.94854736328125, 3.871746540069580078, 0, 0, -0.93409633636474609, 0.357021093368530273, 86400, 255, 1, 56421), -- [DNT]Covered Body (Area: 0 - Difficulty: Heroic) CreateObject1
(@OGUID+25, 414273, 2649, 14954, 0, '1,2,8,23', '0', 0, 2959.6416015625, 1767.842041015625, 623.94854736328125, 5.808022975921630859, 0, 0, -0.2353525161743164, 0.971910059452056884, 86400, 255, 1, 56421), -- [DNT]Covered Body (Area: 0 - Difficulty: Heroic) CreateObject1
(@OGUID+26, 414273, 2649, 14954, 0, '1,2,8,23', '0', 0, 2960.9453125, 1770.6441650390625, 623.94854736328125, 5.808022975921630859, 0, 0, -0.2353525161743164, 0.971910059452056884, 86400, 255, 1, 56421), -- [DNT]Covered Body (Area: 0 - Difficulty: Heroic) CreateObject1
(@OGUID+27, 414273, 2649, 14954, 0, '1,2,8,23', '0', 0, 2917.7119140625, 1768.0416259765625, 623.94854736328125, 3.871746540069580078, 0, 0, -0.93409633636474609, 0.357021093368530273, 86400, 255, 1, 56421), -- [DNT]Covered Body (Area: 0 - Difficulty: Heroic) CreateObject1
(@OGUID+28, 414273, 2649, 14954, 0, '1,2,8,23', '0', 0, 2962.55810546875, 1773.1597900390625, 623.94854736328125, 5.808022975921630859, 0, 0, -0.2353525161743164, 0.971910059452056884, 86400, 255, 1, 56421); -- [DNT]Covered Body (Area: 0 - Difficulty: Heroic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+18;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+3, 0, 0, 0.998629570007324218, -0.05233606696128845, 0, 0), -- 10FX_Generic_Fire_Barrier
(@OGUID+4, 0, 0, 0.998629570007324218, -0.05233606696128845, 0, 0), -- 11AT_Arathor_Navigation_Door01
(@OGUID+5, 0, 0, 0.998629570007324218, -0.05233606696128845, 0, 0), -- 11AT_Arathor_Navigation_Door01
(@OGUID+6, 0, 0, 0.998629570007324218, -0.05233606696128845, 0, 0), -- Priory Door
(@OGUID+7, 0, 0, 0.998629570007324218, -0.05233606696128845, 0, 0), -- Priory Door
(@OGUID+8, 0, 0, 0.998629570007324218, -0.05233606696128845, 0, 0), -- 10FX_Generic_Fire_Barrier
(@OGUID+9, 0, 0, 0.998629570007324218, -0.05233606696128845, 0, 0); -- 10FX_Generic_Fire_Barrier

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (211140 /*211140 (Arathi Neophyte) - Overwhelming Power, Overwhelming Power*/, 210851 /*210851 (Eternal Flame) - Sacred Flame*/, 228805 /*228805 (Upper Platform Stalker) - [DNT]Holy Cosmetic Missiles*/, 221737 /*221737 (Platform Stalker) - [DNT]Holy Cosmetic Missiles*/, 226510 /*226510 (Path Helper) - Advert*/, 226501 /*226501 (Path Helper) - Advert*/, 217658 /*217658 (Sir Braunpyke) - Bot AI Follow Advert*/, 212835 /*212835 (Risen Footman)*/, 196280 /*196280 (Unstable Tear) - Unstable Tear*/, 1860 /*1860 (Voidwalker) - Override Command Demon*/, 198547 /*198547 (Shadowy Tear) - Shadowy Tear*/, 198555 /*198555 (Chaos Tear) - Chaos Tear*/, 31216 /*31216 (Mirror Image) - Avoidance*/, 206704 /*206704 (Ardent Paladin) - Bot AI Follow Advert*/, 206710 /*206710 (Lightspawn)*/, 206698 /*206698 (Fanatical Conjuror)*/, 207939 /*207939 (Baron Braunpyke) - Bot AI Follow Advert*/, 206697 /*206697 (Devout Priest)*/, 206699 /*206699 (War Lynx) - Cosmetic - Sleep Zzz*/, 224762 /*224762 (Silvervein) - Sigil of Algari Concordance*/, 224466 /*224466 (Voidwraith) - Voidwraith*/, 144961 /*144961 (Akaari's Soul)*/, 208441 /*208441 (Water Elemental) - Water Elemental Glyph Transform*/, 217429 /*217429 (Overfiend) - Avoidance*/, 206705 /*206705 (Arathi Footman)*/, 206694 /*206694 (Fervent Sharpshooter)*/, 210932 /*210932 (Path Helper) - Bot AI Follow Advert*/, 210931 /*210931 (Path Helper) - Bot AI Follow Advert*/, 206696 /*206696 (Arathi Knight) - [DNT]Generic Power Bar Color - Red/Rage*/, 207940 /*207940 (Prioress Murrpray) - [DNT]Mellek Power Bar Color, Bot AI Follow Advert*/, 212831 /*212831 (Forge Master Damian)*/, 211290 /*211290 (Elaena Emberlanz) - Strength in Numbers, Bot AI Follow Advert, Strength in Numbers*/, 211291 /*211291 (Sergeant Shaynemail) - Strength in Numbers, Bot AI Follow Advert, Strength in Numbers*/, 211289 /*211289 (Taener Duelmal) - Strength in Numbers, Bot AI Follow Advert, Strength in Numbers*/, 207946 /*207946 (Captain Dailcry) - Guard Captain Spawn Spell, [DNT]Akritai Kagan Power Bar Color, Bot AI Follow Advert*/, 212826 /*212826 (Guard Captain Suleyman) - [DNT]Akritai Kagan Power Bar Color, Bot AI Follow Advert*/, 212827 /*212827 (High Priest Aemya) - [DNT]Mellek Power Bar Color, Bot AI Follow Advert*/, 211150 /*211150 (Path Helper) - Passive, Bot AI Follow Advert*/, 211151 /*211151 (Path Helper) - Passive, Bot AI Follow Advert*/, 211149 /*211149 (Path Helper) - Passive, Bot AI Follow Advert*/, 211137 /*211137 (Path Helper) - Passive, Bot AI Follow Advert*/, 211152 /*211152 (Path Helper) - Passive, Bot AI Follow Advert*/, 228359 /*228359 (Path Helper) - Advert*/, 210930 /*210930 (Path Helper) - Bot AI Follow Advert*/, 222927 /*222927 (Sacred Flame Vintner) - Ignore*/, 228238 /*228238 (Path Helper) - Advert*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(211140, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 211140 (Arathi Neophyte) - Overwhelming Power, Overwhelming Power
(210851, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '444548'), -- 210851 (Eternal Flame) - Sacred Flame
(228805, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 228805 (Upper Platform Stalker) - [DNT]Holy Cosmetic Missiles
(221737, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 221737 (Platform Stalker) - [DNT]Holy Cosmetic Missiles
(226510, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455862'), -- 226510 (Path Helper) - Advert
(226501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455828'), -- 226501 (Path Helper) - Advert
(217658, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422360'), -- 217658 (Sir Braunpyke) - Bot AI Follow Advert
(212835, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 212835 (Risen Footman)
(206704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422357'), -- 206704 (Ardent Paladin) - Bot AI Follow Advert
(206710, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 206710 (Lightspawn)
(206698, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 206698 (Fanatical Conjuror)
(207939, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '422359'), -- 207939 (Baron Braunpyke) - Bot AI Follow Advert
(206697, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 206697 (Devout Priest)
(206699, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 206699 (War Lynx)
(206705, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 206705 (Arathi Footman)
(206694, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 206694 (Fervent Sharpshooter)
(210932, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422360'), -- 210932 (Path Helper) - Bot AI Follow Advert
(210931, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422357'), -- 210931 (Path Helper) - Bot AI Follow Advert
(207940, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '424996 422362'), -- 207940 (Prioress Murrpray) - [DNT]Mellek Power Bar Color, Bot AI Follow Advert
(212831, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, ''), -- 212831 (Forge Master Damian)
(211290, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '424628 422355 424626'), -- 211290 (Elaena Emberlanz) - Strength in Numbers, Bot AI Follow Advert, Strength in Numbers
(211291, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '424628 422355 424626'), -- 211291 (Sergeant Shaynemail) - Strength in Numbers, Bot AI Follow Advert, Strength in Numbers
(211289, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '424628 422355 424626'), -- 211289 (Taener Duelmal) - Strength in Numbers, Bot AI Follow Advert, Strength in Numbers
(207946, 0, 122962, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '444462 424652 422356'), -- 207946 (Captain Dailcry) - Guard Captain Spawn Spell, [DNT]Akritai Kagan Power Bar Color, Bot AI Follow Advert
(212826, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, '424652 422355'), -- 212826 (Guard Captain Suleyman) - [DNT]Akritai Kagan Power Bar Color, Bot AI Follow Advert
(212827, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, '424996 422355'), -- 212827 (High Priest Aemya) - [DNT]Mellek Power Bar Color, Bot AI Follow Advert
(211150, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '424283 424126'), -- 211150 (Path Helper) - Passive, Bot AI Follow Advert
(211151, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '424283 424126'), -- 211151 (Path Helper) - Passive, Bot AI Follow Advert
(211149, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '424283 424126'), -- 211149 (Path Helper) - Passive, Bot AI Follow Advert
(211137, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '424283 424126'), -- 211137 (Path Helper) - Passive, Bot AI Follow Advert
(211152, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '424283 424126'), -- 211152 (Path Helper) - Passive, Bot AI Follow Advert
(228359, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459918'), -- 228359 (Path Helper) - Advert
(210930, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422354'), -- 210930 (Path Helper) - Bot AI Follow Advert
(222927, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436736'), -- 222927 (Sacred Flame Vintner) - Ignore
(228238, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459757'); -- 228238 (Path Helper) - Advert

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (442664 /*10FX_Generic_Fire_Barrier*/, 442665 /*10FX_Generic_Fire_Barrier*/, 441670 /*Priory Door*/, 441671 /*Priory Door*/, 441668 /*11AT_Arathor_Navigation_Door01*/, 441669 /*11AT_Arathor_Navigation_Door01*/, 452050 /*10FX_Generic_Fire_Barrier*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(442664, 0, 48, 0, 0), -- 10FX_Generic_Fire_Barrier
(442665, 0, 48, 0, 0), -- 10FX_Generic_Fire_Barrier
(441670, 0, 32, 0, 0), -- Priory Door
(441671, 0, 32, 0, 0), -- Priory Door
(441668, 0, 48, 0, 0), -- 11AT_Arathor_Navigation_Door01
(441669, 0, 48, 0, 0), -- 11AT_Arathor_Navigation_Door01
(452050, 0, 8388656, 0, 0); -- 10FX_Generic_Fire_Barrier

-- Template
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=207943; -- Arathi Neophyte
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=206704; -- Ardent Paladin
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=3000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=207949; -- Zealous Templar
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=1090551809 WHERE `entry`=213535; -- Forge Stalker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=67108864, `unit_flags3`=8388608, `VehicleId`=8252 WHERE `entry`=207939; -- Baron Braunpyke
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry` IN (213991, 221700); -- Dummy Stalker
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=1090551809 WHERE `entry`=221844; -- Eternal Flame
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=206698; -- Fanatical Conjuror
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=206710; -- Lightspawn
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222936; -- Sweet-sting Worker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=3000, `unit_flags`=64 WHERE `entry`=206696; -- Arathi Knight
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=206697; -- Devout Priest
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=206699; -- War Lynx
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=206694; -- Fervent Sharpshooter
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67108864, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry` IN (210932, 228359, 228238); -- Path Helper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=67108864 WHERE `entry`=207940; -- Prioress Murrpray
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=206705; -- Arathi Footman
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64 WHERE `entry`=207946; -- Captain Dailcry
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=3000, `unit_flags`=64 WHERE `entry`=211290; -- Elaena Emberlanz
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64 WHERE `entry`=211291; -- Sergeant Shaynemail
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64 WHERE `entry`=211289; -- Taener Duelmal
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags`=64 WHERE `entry`=212826; -- Guard Captain Suleyman
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=3000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=212831; -- Forge Master Damian
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64 WHERE `entry`=212827; -- High Priest Aemya
UPDATE `creature_template` SET `faction`=3364, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=228534; -- Sister Etna Blayze
UPDATE `creature_template` SET `faction`=2000, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=222927; -- Sacred Flame Vintner
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=212838; -- Arathi Neophyte
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=211140; -- Arathi Neophyte
UPDATE `creature_template` SET `faction`=14, `speed_walk`=2, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=19431424 WHERE `entry`=210852; -- Mellek Beam Stalker
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=1090551809 WHERE `entry`=210851; -- Eternal Flame
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry`=228805; -- Upper Platform Stalker
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry`=221737; -- Platform Stalker
UPDATE `creature_template` SET `faction`=634, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110944, `unit_flags3`=1094746113, `flags_extra` = 128 WHERE `entry`=211138; -- Mellek Zombie Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67108864, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry` IN (226510, 226501); -- Path Helper
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.799999952316284179, `speed_run`=1, `BaseAttackTime`=3000, `unit_flags`=64 WHERE `entry`=217658; -- Sir Braunpyke
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=212835; -- Risen Footman
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=221760; -- Risen Mage
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67110912, `unit_flags3`=1091043329 WHERE `entry`=213997; -- Mini-Boss Stalker
UPDATE `creature_template` SET `VignetteID`=6647, `VerifiedBuild`=56421 WHERE `entry`=212826; -- Guard Captain Suleyman
UPDATE `creature_template` SET `VignetteID`=6647, `VerifiedBuild`=56421 WHERE `entry`=212827; -- High Priest Aemya
UPDATE `creature_template` SET `VignetteID`=6647, `VerifiedBuild`=56421 WHERE `entry`=212831; -- Forge Master Damian

DELETE FROM `gameobject_template` WHERE `entry` IN (465795 /*Bench*/, 465826 /*Bench*/, 465814 /*Bench*/, 465796 /*Bench*/, 465772 /*Bench*/, 465769 /*Bench*/, 465753 /*Bench*/, 465747 /*Bench*/, 465742 /*Bench*/, 465823 /*Bench*/, 465811 /*Bench*/, 423349 /*Sacred Flame*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(465795, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(465826, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(465814, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(465796, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(465772, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(465769, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(465753, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(465747, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(465742, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(465823, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(465811, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Bench
(423349, 10, 87783, 'Sacred Flame', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33741, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421); -- Sacred Flame

-- Creature Equip template
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (206704,207949,207939,206698,206696,206697,206694,207940,206705,207946,211290,211291,211289,212826,212831,212827,217658,212835,221760)) OR (`ID`=7 AND `CreatureID`=27893);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(206704, 1, 220460, 0, 0, 222986, 0, 0, 0, 0, 0, 56421), -- Ardent Paladin
(207949, 1, 220500, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Zealous Templar
(207939, 1, 220460, 0, 0, 222986, 0, 0, 0, 0, 0, 56421), -- Baron Braunpyke
(206698, 1, 0, 0, 0, 220505, 0, 0, 0, 0, 0, 56421), -- Fanatical Conjuror
(206696, 1, 220490, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Arathi Knight
(206697, 1, 220451, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Devout Priest
(206694, 1, 0, 0, 0, 0, 0, 0, 220456, 0, 0, 56421), -- Fervent Sharpshooter
(207940, 1, 220451, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Prioress Murrpray
(206705, 1, 220468, 0, 0, 222984, 0, 0, 0, 0, 0, 56421), -- Arathi Footman
(207946, 1, 220487, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Captain Dailcry
(211290, 1, 220492, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Elaena Emberlanz
(211291, 1, 220490, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Sergeant Shaynemail
(211289, 1, 220449, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Taener Duelmal
(212826, 1, 220459, 0, 0, 222984, 0, 0, 0, 0, 0, 56421), -- Guard Captain Suleyman
(212831, 1, 220490, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Forge Master Damian
(212827, 1, 220451, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- High Priest Aemya
(217658, 1, 220500, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Sir Braunpyke
(212835, 1, 220470, 0, 0, 222986, 0, 0, 0, 0, 0, 56421), -- Risen Footman
(221760, 1, 220449, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Risen Mage
(27893, 7, 225990, 0, 0, 0, 0, 0, 0, 0, 0, 56421); -- Rune Weapon

-- Creature Difficulty (Normal)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=211140 AND `DifficultyID`=1); -- 211140 (Arathi Neophyte) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `VerifiedBuild`=56421 WHERE (`Entry`=210852 AND `DifficultyID`=0); -- 210852 (Mellek Beam Stalker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=210851 AND `DifficultyID`=0); -- 210851 (Eternal Flame) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=228805 AND `DifficultyID`=0); -- 228805 (Upper Platform Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=221737 AND `DifficultyID`=0); -- 221737 (Platform Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56421 WHERE (`Entry`=211138 AND `DifficultyID`=0); -- 211138 (Mellek Zombie Stalker) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56421 WHERE (`Entry`=226510 AND `DifficultyID`=0); -- 226510 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56421 WHERE (`Entry`=226501 AND `DifficultyID`=0); -- 226501 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=217658 AND `DifficultyID`=0); -- 217658 (Sir Braunpyke) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=212835 AND `DifficultyID`=0); -- 212835 (Risen Footman) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=221760 AND `DifficultyID`=0); -- 221760 (Risen Mage) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=212838 AND `DifficultyID`=0); -- 212838 (Arathi Neophyte) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=206704 AND `DifficultyID`=0); -- 206704 (Ardent Paladin) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=207949 AND `DifficultyID`=0); -- 207949 (Zealous Templar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=207943 AND `DifficultyID`=0); -- 207943 (Arathi Neophyte) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=207939 AND `DifficultyID`=1); -- 207939 (Baron Braunpyke) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=206710 AND `DifficultyID`=0); -- 206710 (Lightspawn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=213991 AND `DifficultyID`=0); -- 213991 (Dummy Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=221700 AND `DifficultyID`=0); -- 221700 (Dummy Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56421 WHERE (`Entry`=213997 AND `DifficultyID`=0); -- 213997 (Mini-Boss Stalker) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=206698 AND `DifficultyID`=0); -- 206698 (Fanatical Conjuror) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=221844 AND `DifficultyID`=0); -- 221844 (Eternal Flame) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=206697 AND `DifficultyID`=0); -- 206697 (Devout Priest) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=206694 AND `DifficultyID`=0); -- 206694 (Fervent Sharpshooter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56421 WHERE (`Entry`=210932 AND `DifficultyID`=0); -- 210932 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=206696 AND `DifficultyID`=0); -- 206696 (Arathi Knight) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=207940 AND `DifficultyID`=1); -- 207940 (Prioress Murrpray) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=206699 AND `DifficultyID`=0); -- 206699 (War Lynx) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=206705 AND `DifficultyID`=1); -- 206705 (Arathi Footman) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=212831 AND `DifficultyID`=0); -- 212831 (Forge Master Damian) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=211290 AND `DifficultyID`=1); -- 211290 (Elaena Emberlanz) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=211291 AND `DifficultyID`=1); -- 211291 (Sergeant Shaynemail) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=211289 AND `DifficultyID`=1); -- 211289 (Taener Duelmal) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=207946 AND `DifficultyID`=1); -- 207946 (Captain Dailcry) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=212826 AND `DifficultyID`=0); -- 212826 (Guard Captain Suleyman) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=212827 AND `DifficultyID`=0); -- 212827 (High Priest Aemya) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56421 WHERE (`Entry`=228359 AND `DifficultyID`=0); -- 228359 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2976, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=228534 AND `DifficultyID`=0); -- 228534 (Sister Etna Blayze) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=222927 AND `DifficultyID`=0); -- 222927 (Sacred Flame Vintner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56421 WHERE (`Entry`=228238 AND `DifficultyID`=0); -- 228238 (Path Helper) - Sessile, CanSwim, Floating

-- Creature Difficulty (Heroic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (210852,210851,228805,221737,211138,226510,226501,217658,212835,221760,212838,206704,207949,226267,224466,226272,228224,207943,206710,213991,213997,226271,198757,228226,221700,228105,223273,206698,221844,206697,206699,206696,206694,210932,212826,212827,212831,228359,228534,228238,222927));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(210852, 2, 0, 0, 2720, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- 210852 (Mellek Beam Stalker) - 
(210851, 2, 0, 0, 2720, 536871168, 0, 0, 0, 0, 0, 0, 0, 56421), -- 210851 (Eternal Flame) - Sessile, Floating
(228805, 2, 0, 0, 2720, 536871168, 0, 0, 0, 0, 0, 0, 0, 56421), -- 228805 (Upper Platform Stalker) - Sessile, Floating
(221737, 2, 0, 0, 2720, 536871168, 0, 0, 0, 0, 0, 0, 0, 56421), -- 221737 (Platform Stalker) - Sessile, Floating
(211138, 2, 0, 0, 2720, 536871168, 0, 33554432, 0, 0, 0, 0, 0, 56421), -- 211138 (Mellek Zombie Stalker) - Sessile, Floating - CannotTurn
(226510, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 56421), -- 226510 (Path Helper) - Sessile, CanSwim, Floating
(226501, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 56421), -- 226501 (Path Helper) - Sessile, CanSwim, Floating
(217658, 2, 1, 1, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 217658 (Sir Braunpyke) - CanSwim
(212835, 2, 0, 0, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 212835 (Risen Footman) - CanSwim
(221760, 2, 0, 0, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 221760 (Risen Mage) - CanSwim
(212838, 2, 0, 0, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 212838 (Arathi Neophyte) - CanSwim
(206704, 2, 1, 1, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 206704 (Ardent Paladin) - CanSwim
(207949, 2, 1, 1, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 207949 (Zealous Templar) - CanSwim
(207943, 2, 0, 0, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 207943 (Arathi Neophyte) - CanSwim
(206710, 2, 0, 0, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 206710 (Lightspawn) - CanSwim
(213991, 2, 0, 0, 2720, 536871168, 0, 0, 0, 0, 0, 0, 0, 56421), -- 213991 (Dummy Stalker) - Sessile, Floating
(213997, 2, 0, 0, 2720, 536871168, 0, 33554432, 0, 0, 0, 0, 0, 56421), -- 213997 (Mini-Boss Stalker) - Sessile, Floating - CannotTurn
(221700, 2, 0, 0, 2720, 536871168, 0, 0, 0, 0, 0, 0, 0, 56421), -- 221700 (Dummy Stalker) - Sessile, Floating
(206698, 2, 0, 0, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 206698 (Fanatical Conjuror) - CanSwim
(221844, 2, 0, 0, 2720, 536871168, 0, 0, 0, 0, 0, 0, 0, 56421), -- 221844 (Eternal Flame) - Sessile, Floating
(206697, 2, 0, 0, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 206697 (Devout Priest) - CanSwim
(206699, 2, 0, 0, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 206699 (War Lynx) - CanSwim
(206696, 2, 1, 1, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 206696 (Arathi Knight) - CanSwim
(206694, 2, 0, 0, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 206694 (Fervent Sharpshooter) - CanSwim
(210932, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 56421), -- 210932 (Path Helper) - Sessile, CanSwim, Floating
(212826, 2, 1, 1, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 212826 (Guard Captain Suleyman) - CanSwim
(212827, 2, 1, 1, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 212827 (High Priest Aemya) - CanSwim
(212831, 2, 1, 1, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 212831 (Forge Master Damian) - CanSwim
(228359, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 56421), -- 228359 (Path Helper) - Sessile, CanSwim, Floating
(228534, 2, 0, 0, 2720, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421), -- 228534 (Sister Etna Blayze) - CanSwim
(228238, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 56421), -- 228238 (Path Helper) - Sessile, CanSwim, Floating
(222927, 2, 0, 0, 2799, 268435456, 0, 0, 0, 0, 0, 0, 0, 56421); -- 222927 (Sacred Flame Vintner) - CanSwim

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2720, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=211140 AND `DifficultyID`=2); -- 211140 (Arathi Neophyte) - CanSwim
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=56421 WHERE (`DifficultyID`=2 AND `Entry` IN (19668,210931,211151,211149,211137,211152,211111,210930,211150));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2720, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=207939 AND `DifficultyID`=2); -- 207939 (Baron Braunpyke) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2720, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=207940 AND `DifficultyID`=2); -- 207940 (Prioress Murrpray) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2720, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=206705 AND `DifficultyID`=2); -- 206705 (Arathi Footman) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2720, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=211290 AND `DifficultyID`=2); -- 211290 (Elaena Emberlanz) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2720, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=211291 AND `DifficultyID`=2); -- 211291 (Sergeant Shaynemail) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2720, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=211289 AND `DifficultyID`=2); -- 211289 (Taener Duelmal) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2720, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=207946 AND `DifficultyID`=2); -- 207946 (Captain Dailcry) - CanSwim
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260197, `TypeFlags2`=128 WHERE (`Entry`=210852 AND `DifficultyID`=2); -- Mellek Beam Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260196, `TypeFlags2`=128 WHERE (`Entry`=210851 AND `DifficultyID`=2); -- Eternal Flame
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=280024, `TypeFlags2`=128 WHERE (`Entry`=228805 AND `DifficultyID`=2); -- Upper Platform Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=271547, `TypeFlags2`=128 WHERE (`Entry`=221737 AND `DifficultyID`=2); -- Platform Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260489, `TypeFlags`=64, `TypeFlags2`=128 WHERE (`Entry`=211138 AND `DifficultyID`=2); -- Mellek Zombie Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=277654, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=226510 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=277639, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=226501 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=15, `CreatureDifficultyID`=267151, `TypeFlags`=2097224 WHERE (`Entry`=217658 AND `DifficultyID`=2); -- Sir Braunpyke
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=6.5, `CreatureDifficultyID`=262224, `TypeFlags`=2097224 WHERE (`Entry`=212835 AND `DifficultyID`=2); -- Risen Footman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=4.5, `CreatureDifficultyID`=271571, `TypeFlags`=2097224 WHERE (`Entry`=221760 AND `DifficultyID`=2); -- Risen Mage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=2.5, `CreatureDifficultyID`=262227, `TypeFlags`=2097224 WHERE (`Entry`=212838 AND `DifficultyID`=2); -- Arathi Neophyte
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=6.5, `CreatureDifficultyID`=237182, `TypeFlags`=270532680 WHERE (`Entry`=207949 AND `DifficultyID`=2); -- Zealous Templar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=9, `CreatureDifficultyID`=235919, `TypeFlags`=270532680 WHERE (`Entry`=206704 AND `DifficultyID`=2); -- Ardent Paladin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=2.5, `CreatureDifficultyID`=237176, `TypeFlags`=2097224 WHERE (`Entry`=207943 AND `DifficultyID`=2); -- Arathi Neophyte
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=263402 WHERE (`Entry`=213991 AND `DifficultyID`=2); -- Dummy Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=6, `CreatureDifficultyID`=235925, `TypeFlags`=2097224 WHERE (`Entry`=206710 AND `DifficultyID`=2); -- Lightspawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=263408, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=213997 AND `DifficultyID`=2); -- Mini-Boss Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=271510 WHERE (`Entry`=221700 AND `DifficultyID`=2); -- Dummy Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=4.5, `CreatureDifficultyID`=235913, `TypeFlags`=2097224 WHERE (`Entry`=206698 AND `DifficultyID`=2); -- Fanatical Conjuror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=271655 WHERE (`Entry`=221844 AND `DifficultyID`=2); -- Eternal Flame
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=4.25, `CreatureDifficultyID`=235912, `TypeFlags`=2097224 WHERE (`Entry`=206697 AND `DifficultyID`=2); -- Devout Priest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=235914, `TypeFlags`=2097224 WHERE (`Entry`=206699 AND `DifficultyID`=2); -- War Lynx
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=8, `CreatureDifficultyID`=235911, `TypeFlags`=270534728 WHERE (`Entry`=206696 AND `DifficultyID`=2); -- Arathi Knight
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=4.5, `CreatureDifficultyID`=235909, `TypeFlags`=2097224 WHERE (`Entry`=206694 AND `DifficultyID`=2); -- Fervent Sharpshooter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260281, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=210932 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=20, `CreatureDifficultyID`=262199, `TypeFlags`=2097224 WHERE (`Entry`=212826 AND `DifficultyID`=2); -- Guard Captain Suleyman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=15, `CreatureDifficultyID`=262200, `TypeFlags`=2097224 WHERE (`Entry`=212827 AND `DifficultyID`=2); -- High Priest Aemya
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=15, `CreatureDifficultyID`=262220, `TypeFlags`=270532680 WHERE (`Entry`=212831 AND `DifficultyID`=2); -- Forge Master Damian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=279547, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=228359 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=279423, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=228238 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=279739, `TypeFlags2`=32768 WHERE (`Entry`=228534 AND `DifficultyID`=2); -- Sister Etna Blayze
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=273724 WHERE (`Entry`=222927 AND `DifficultyID`=2); -- Sacred Flame Vintner

-- Model Info
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (121006, 121010, 121011, 121008, 121007, 121023, 121024, 121014, 121015, 120847, 121005, 120878, 120848, 121013, 121016, 120988, 120849, 121012, 120987, 120023, 118879, 118872, 118870, 118873, 118876, 118874, 118867, 121001, 121002, 121004, 121003, 121021, 121017, 121022, 121020, 116188, 116186, 116189, 116171, 121019, 121018, 120674, 120686, 121009, 120684);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(121006, 0.305999994277954101, 1.5, 0, 56421),
(121010, 0.305999994277954101, 1.5, 0, 56421),
(121011, 0.305999994277954101, 1.5, 0, 56421),
(121008, 0.208000004291534423, 1.5, 0, 56421),
(121007, 0.208000004291534423, 1.5, 0, 56421),
(121023, 0.663779377937316894, 1.424999952316284179, 0, 56421),
(121024, 0.239199995994567871, 1.724999904632568359, 0, 56421),
(121014, 0.349999994039535522, 1.5, 0, 56421),
(121015, 0.349999994039535522, 1.5, 0, 56421),
(120847, 0.305999994277954101, 1.5, 0, 56421),
(121005, 0.239199995994567871, 1.724999904632568359, 0, 56421),
(120878, 1.492568492889404296, 2, 0, 56421),
(120848, 0.305999994277954101, 1.5, 0, 56421),
(121013, 0.349999994039535522, 1.5, 0, 56421),
(121016, 0.349999994039535522, 1.5, 0, 56421),
(120988, 0.239199995994567871, 1.72500002384185791, 0, 56421),
(120849, 0.305999994277954101, 1.5, 0, 56421),
(121012, 0.349999994039535522, 1.5, 0, 56421),
(120987, 0.347222000360488891, 1.5, 0, 56421),
(120023, 0.305999994277954101, 1.5, 0, 56421),
(118879, 0.351899981498718261, 1.724999904632568359, 0, 56421),
(118872, 0.347221970558166503, 1.5, 0, 56421),
(118870, 0.239199981093406677, 1.724999904632568359, 0, 56421),
(118873, 0.305999964475631713, 1.5, 0, 56421),
(118876, 0.698715150356292724, 1.5, 0, 56421),
(118874, 0.305999994277954101, 1.5, 0, 56421),
(118867, 0.228800013661384582, 1.65000009536743164, 0, 56421),
(121001, 0.239199995994567871, 1.724999904632568359, 0, 56421),
(121002, 0.351899981498718261, 1.724999904632568359, 0, 56421),
(121004, 0.593907892704010009, 1.27500009536743164, 0, 56421),
(121003, 0.277777612209320068, 1.20000004768371582, 0, 56421),
(121021, 0.305999994277954101, 1.5, 0, 56421),
(121017, 0.208000004291534423, 1.5, 0, 56421),
(121022, 0.305999994277954101, 1.5, 0, 56421),
(121020, 0.305999994277954101, 1.5, 0, 56421),
(116188, 1.014590740203857421, 1.5625, 0, 56421),
(116186, 1.014590740203857421, 1.5625, 0, 56421),
(116189, 1.014590740203857421, 1.5625, 0, 56421),
(116171, 0.811672568321228027, 1.25, 0, 56421),
(121019, 0.208000004291534423, 1.5, 0, 56421),
(121018, 0.208000004291534423, 1.5, 0, 56421),
(120674, 0.254584968090057373, 0.625, 0, 56421),
(120686, 0.356418937444686889, 0.875, 0, 56421),
(121009, 0.208000004291534423, 1.5, 0, 56421),
(120684, 0.509169936180114746, 1.25, 0, 56421);

UPDATE `creature_model_info` SET `VerifiedBuild`=56421 WHERE `DisplayID` IN (118878, 11686, 115077, 118877, 117092, 23767);
UPDATE `creature_template_model` SET `VerifiedBuild`=56421 WHERE (`Idx`=0 AND `CreatureID` IN (221700,206698,151719,152568,152360,154148,153928,153898,152290,152359,153658,152552,152542,152545,152548,152795,151870,150583,152682,152681,152397,152465,144644,152323,152567,152448,152553,152555,152414,152291,152756,152556,152464,152712,152361,152566,152794,152416,152415,227442,225420,225421,227411,227335,227336,220720,193655,193650,193654,193653,193679,193678,193677,193675,193674,193652,193684,193680,193682,193686,193647,193644,193645,193648,162248,162245,162241,162253,162251,158706,162254,158531,162243,162247,158632,162244,162246,156709,159087,162290,162252,162250,162249,212831,212827,211291,211152,207940,211150,211111,211151,211149,211137,210932,210931,206699,222927,65851,38695,63502,52672,66151,21354,33301,69067,53270,35362,73780,65011,77178,29929,80651,76084,71381,71486,70356,69831,69832,69219,69204,68288,68211,67437,66062,66063,66060,65078,65076,65074,65072,65071,65065,65063,65061,65060,65058,65016,65009,65007,65006,64996,64993,64986,63553,63552,63042,62454,62106,61809,60941,59101,59072,58169,56921,55272,54879,54741,54423,53276,52807,52756,48632,47841,47353,40725,40165,39209,39208,35168,33904,33892,25064,31239,32633,32206,32158,31851,31778,31698,31717,29582,28363,27707,27684,28302,27152,24488,20850,20848,20849,20847,20846,19658,18362,18375,18376,18406,18359,18357,18360,17266,15715,15714,15666,14602,14547,14548,14546,14561,14560,14559,14553,14552,14551,14556,14555,14565,14505,14336,10180,11147,9158,7749,7739,7690,7687,6074,4779,4777,4710,4269,304,307,308,33030,305,284,218977,218646,218647,210930,206697,221844,228238,228359,206694,206705,206696)) OR (`Idx`=4 AND `CreatureID` IN (152795,206699)) OR (`Idx`=3 AND `CreatureID` IN (152795,206699,222927)) OR (`Idx`=2 AND `CreatureID` IN (152795,206699,222927,206697)) OR (`Idx`=1 AND `CreatureID` IN (152795,152794,162253,162251,162252,162250,162249,211152,211150,211111,211151,211149,211137,210932,210931,206699,222927,40725,40165,218646,210930,206697,228238,228359));
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791, `VerifiedBuild`=56421 WHERE (`CreatureID`=211290 AND `Idx`=0); -- Elaena Emberlanz
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791, `VerifiedBuild`=56421 WHERE (`CreatureID`=211289 AND `Idx`=0); -- Taener Duelmal
UPDATE `creature_template_model` SET `DisplayScale`=1.419999957084655761, `VerifiedBuild`=56421 WHERE (`CreatureID`=207946 AND `Idx`=0); -- Captain Dailcry
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791, `VerifiedBuild`=56421 WHERE (`CreatureID`=212826 AND `Idx`=0); -- Guard Captain Suleyman

-- Sacred Flame Vintner smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 222927;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+28), -(@CGUID+73));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+28), 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 80, 22292700, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 0 - Self: Start timed action list id #Sacred Flame Vintner #0 (22292700) (update out of combat)'),
(-(@CGUID+28), 0, 1, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 80, 22292701, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Sacred Flame Vintner #1 (22292701) (update out of combat)'),
(-(@CGUID+73), 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 80, 22292700, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 0 - Self: Start timed action list id #Sacred Flame Vintner #0 (22292700) (update out of combat)'),
(-(@CGUID+73), 0, 1, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 80, 22292701, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Sacred Flame Vintner #1 (22292701) (update out of combat)');

-- Timed list 22292701 smart ai
SET @ENTRY := 22292701;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 443738, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 443738 on self'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Remove stand state KNEEL');

-- Timed list 22292700 smart ai
SET @ENTRY := 22292700;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 443738, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  443738'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Remove stand state KNEEL');

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+56;
SET @ENTRY := 222927;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2866.5842, 1133.9774, 514.0673, NULL, 0),
(@PATH, 1, 2860.1484, 1135.7084, 514.0673, NULL, 0),
(@PATH, 2, 2853.2222, 1133.5573, 514.08154, NULL, 0),
(@PATH, 3, 2849.3394, 1130.3177, 514.08154, NULL, 0),
(@PATH, 4, 2847.4307, 1124.5486, 514.0746, NULL, 0),
(@PATH, 5, 2848.1223, 1119.316, 514.0673, NULL, 0),
(@PATH, 6, 2850.7727, 1115.2656, 514.0673, NULL, 0),
(@PATH, 7, 2856.0051, 1111.6719, 514.0673, NULL, 0),
(@PATH, 8, 2862.0808, 1109.4479, 514.0673, NULL, 0),
(@PATH, 9, 2866.934, 1110.1267, 514.0673, NULL, 0),
(@PATH, 10, 2870.0696, 1112.0973, 514.0673, NULL, 0),
(@PATH, 11, 2872.4436, 1116.4896, 514.0673, NULL, 0),
(@PATH, 12, 2873.7527, 1124.8959, 514.0673, NULL, 0),
(@PATH, 13, 2871.4192, 1130.2552, 514.0673, NULL, 0);

UPDATE `creature` SET `position_x`=2866.5842, `position_y`=1133.9774, `position_z`=514.0673, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+41;
SET @ENTRY := 222927;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2882.8525, 1056.0139, 515.38617, NULL, 0),
(@PATH, 1, 2889.7734, 1050.8004, 515.47723, NULL, 0),
(@PATH, 2, 2898.9185, 1043.6267, 515.3941, NULL, 0),
(@PATH, 3, 2907.0806, 1036.861, 515.5304, NULL, 0),
(@PATH, 4, 2914.968, 1030.2101, 516.2935, NULL, 0),
(@PATH, 5, 2918.1067, 1027.7396, 516.21295, NULL, 0),
(@PATH, 6, 2907.1892, 1036.7709, 515.5169, NULL, 0),
(@PATH, 7, 2898.9185, 1043.6267, 515.3941, NULL, 0),
(@PATH, 8, 2889.7734, 1050.8004, 515.47723, NULL, 0);

UPDATE `creature` SET `position_x`=2882.8525, `position_y`=1056.0139, `position_z`=515.38617, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+58;
SET @ENTRY := 222927;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2835.073, 1091.7935, 522.8182, NULL, 0),
(@PATH, 1, 2828.2048, 1098.3055, 523.64417, NULL, 0),
(@PATH, 2, 2822.677, 1101.2622, 526.45135, NULL, 0),
(@PATH, 3, 2817.5308, 1109.3256, 526.3264, NULL, 0),
(@PATH, 4, 2822.677, 1101.2622, 526.45135, NULL, 0),
(@PATH, 5, 2828.2048, 1098.3055, 523.64417, NULL, 0),
(@PATH, 6, 2835.073, 1091.7935, 522.8182, NULL, 0),
(@PATH, 7, 2851.8906, 1078.4618, 522.74506, NULL, 0),
(@PATH, 8, 2867, 1067.1476, 523.7966, NULL, 0),
(@PATH, 9, 2874.6394, 1060.7966, 523.58923, NULL, 0),
(@PATH, 10, 2867, 1067.1476, 523.7966, NULL, 0),
(@PATH, 11, 2851.8906, 1078.4618, 522.74506, NULL, 0);

UPDATE `creature` SET `position_x`=2835.073, `position_y`=1091.7935, `position_z`=522.8182, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+31;
SET @ENTRY := 222927;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2939.9626, 1057.2361, 514.0702, NULL, 0),
(@PATH, 1, 2954.4905, 1045.1979, 514.1064, NULL, 0),
(@PATH, 2, 2975.2527, 1029.5209, 514.0847, NULL, 0),
(@PATH, 3, 2954.4905, 1045.1979, 514.1064, NULL, 0),
(@PATH, 4, 2939.9626, 1057.2361, 514.0702, NULL, 0),
(@PATH, 5, 2924.2812, 1069.7361, 514.14795, NULL, 0),
(@PATH, 6, 2908.3325, 1082.5834, 514.0936, NULL, 0),
(@PATH, 7, 2877.481, 1108.6649, 514.0673, NULL, 0),
(@PATH, 8, 2908.3325, 1082.5834, 514.0936, NULL, 0),
(@PATH, 9, 2924.2812, 1069.7361, 514.14795, NULL, 0);

UPDATE `creature` SET `position_x`=2939.9626, `position_y`=1057.2361, `position_z`=514.0702, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+6;
SET @ENTRY := 222927;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2933.0842, 1014.0625, 515.3861, NULL, 0),
(@PATH, 1, 2966.802, 986.4583, 515.43884, NULL, 0),
(@PATH, 2, 2933.0842, 1014.0625, 515.3861, NULL, 0),
(@PATH, 3, 2919.9055, 1024.5209, 516.1986, NULL, 0);

UPDATE `creature` SET `position_x`=2933.0842, `position_y`=1014.0625, `position_z`=515.3861, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+75;
SET @ENTRY := 222927;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3097.4758, 1116.5712, 517.49316, NULL, 0),
(@PATH, 1, 3099.7935, 1120.6337, 517.3434, NULL, 0),
(@PATH, 2, 3105.341, 1123.0087, 517.403, NULL, 0),
(@PATH, 3, 3108.4011, 1122.8195, 517.3976, NULL, 0),
(@PATH, 4, 3111.9097, 1121.7709, 517.251, NULL, 0),
(@PATH, 5, 3113.808, 1120.1024, 516.12396, NULL, 0),
(@PATH, 6, 3116.284, 1119.1841, 514.49274, NULL, 0),
(@PATH, 7, 3121.2996, 1115.4445, 514.1249, NULL, 0),
(@PATH, 8, 3123.0564, 1111.7361, 514.29486, NULL, 0),
(@PATH, 9, 3122.7769, 1106.5608, 514.09393, NULL, 0),
(@PATH, 10, 3124.8428, 1103.8334, 514.83887, NULL, 0),
(@PATH, 11, 3125.6167, 1102.9181, 515.69867, NULL, 0),
(@PATH, 12, 3126.6965, 1101.954, 515.5249, NULL, 0),
(@PATH, 13, 3129.0452, 1098.5903, 515.5558, NULL, 0),
(@PATH, 14, 3125.804, 1095.5348, 515.69995, NULL, 0),
(@PATH, 15, 3122.7986, 1092.6302, 515.62024, NULL, 0),
(@PATH, 16, 3119.9138, 1092.0142, 515.63464, NULL, 0),
(@PATH, 17, 3116.5886, 1094.2673, 514.6045, NULL, 0),
(@PATH, 18, 3109.8281, 1098.1598, 514.0673, NULL, 0),
(@PATH, 19, 3106.0034, 1099.7291, 514.0673, NULL, 0),
(@PATH, 20, 3101.111, 1102.5382, 514.0673, NULL, 0),
(@PATH, 21, 3098.3176, 1103.5052, 515.77386, NULL, 0),
(@PATH, 22, 3096.0808, 1106.1875, 517.24335, NULL, 0),
(@PATH, 23, 3095.5234, 1110.5677, 517.38965, NULL, 0);

UPDATE `creature` SET `position_x`=3097.4758, `position_y`=1116.5712, `position_z`=517.49316, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '436736 443738');

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+9;
SET @ENTRY := 222927;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3048.2935, 1027.4827, 514.1465, NULL, 0),
(@PATH, 1, 3052.2378, 1028.2795, 514.1248, NULL, 0),
(@PATH, 2, 3055.23, 1030.3524, 514.1431, NULL, 0),
(@PATH, 3, 3058.8394, 1033.4601, 514.1636, NULL, 0),
(@PATH, 4, 3061.9375, 1036.875, 514.16504, NULL, 0),
(@PATH, 5, 3066.4453, 1041.8923, 514.1432, NULL, 0),
(@PATH, 6, 3078.9453, 1058.0278, 514.178, NULL, 0),
(@PATH, 7, 3084.1494, 1064.3646, 514.1742, NULL, 0),
(@PATH, 8, 3091.7935, 1073.3073, 514.0673, NULL, 0),
(@PATH, 9, 3096.3645, 1079.5973, 514.0673, NULL, 0),
(@PATH, 10, 3100.131, 1084.0348, 514.0673, NULL, 0),
(@PATH, 11, 3103.2969, 1087.7257, 514.0673, NULL, 0),
(@PATH, 12, 3100.131, 1084.0348, 514.0673, NULL, 0),
(@PATH, 13, 3096.3645, 1079.5973, 514.0673, NULL, 0),
(@PATH, 14, 3091.7935, 1073.3073, 514.0673, NULL, 0),
(@PATH, 15, 3084.1494, 1064.3646, 514.1742, NULL, 0),
(@PATH, 16, 3078.9453, 1058.0278, 514.178, NULL, 0),
(@PATH, 17, 3066.4453, 1041.8923, 514.1432, NULL, 0),
(@PATH, 18, 3061.9375, 1036.875, 514.16504, NULL, 0),
(@PATH, 19, 3058.8394, 1033.4601, 514.1636, NULL, 0),
(@PATH, 20, 3055.23, 1030.3524, 514.1431, NULL, 0),
(@PATH, 21, 3052.2378, 1028.2795, 514.1248, NULL, 0),
(@PATH, 22, 3048.2935, 1027.4827, 514.1465, NULL, 0),
(@PATH, 23, 3044.8176, 1026.4688, 514.1958, NULL, 0),
(@PATH, 24, 3041.1362, 1026.9791, 514.292, NULL, 0);

UPDATE `creature` SET `position_x`=3048.2935, `position_y`=1027.4827, `position_z`=514.1465, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+74;
SET @ENTRY := 222927;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3138.751, 1072.4791, 515.3478, NULL, 0),
(@PATH, 1, 3133.5364, 1066.8298, 515.27905, NULL, 0),
(@PATH, 2, 3128.5425, 1061.1997, 515.49493, NULL, 0),
(@PATH, 3, 3124.7595, 1057.0382, 515.4251, NULL, 0),
(@PATH, 4, 3120.5122, 1052.6493, 516.39856, NULL, 0),
(@PATH, 5, 3114.3682, 1045.6666, 516.19196, NULL, 0),
(@PATH, 6, 3120.5122, 1052.6493, 516.39856, NULL, 0),
(@PATH, 7, 3124.7595, 1057.0382, 515.4251, NULL, 0),
(@PATH, 8, 3128.5425, 1061.1997, 515.49493, NULL, 0),
(@PATH, 9, 3133.5364, 1066.8298, 515.27905, NULL, 0),
(@PATH, 10, 3138.751, 1072.4791, 515.3478, NULL, 0),
(@PATH, 11, 3143.8499, 1078.3872, 515.3265, NULL, 0);

UPDATE `creature` SET `position_x`=3138.751, `position_y`=1072.4791, `position_z`=515.3478, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+17;
SET @ENTRY := 222927;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3092.7483, 1018.2917, 515.436, NULL, 0),
(@PATH, 1, 3086.5908, 1009.3719, 515.59314, NULL, 0),
(@PATH, 2, 3079.284, 1001.1268, 515.7631, NULL, 0),
(@PATH, 3, 3072.7883, 993.184, 515.4381, NULL, 0),
(@PATH, 4, 3079.2126, 1001.03973, 515.7864, NULL, 0),
(@PATH, 5, 3086.5486, 1009.3108, 515.59576, NULL, 0),
(@PATH, 6, 3092.7483, 1018.2917, 515.436, NULL, 0),
(@PATH, 7, 3113.2283, 1044.3541, 516.21826, NULL, 0);

UPDATE `creature` SET `position_x`=3092.7483, `position_y`=1018.2917, `position_z`=515.436, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+73;
SET @ENTRY := 222927;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3104.0999, 1105.7067, 514.0673, 2.6897, 3223),
(@PATH, 1, 3084.6545, 1081.9791, 515.4525, NULL, 3182);

UPDATE `creature` SET `position_x`=3104.0999, `position_y`=1105.7067, `position_z`=514.0673, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+28;
SET @ENTRY := 222927;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3112.3135, 1114.9896, 514.0807, NULL, 3386),
(@PATH, 1, 3096.0095, 1058.467, 515.898, NULL, 3093);

UPDATE `creature` SET `position_x`=3112.3135, `position_y`=1114.9896, `position_z`=514.0807, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+97;
SET @ENTRY := 222927;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3188.1455, 1127.0577, 522.71704, NULL, 0),
(@PATH, 1, 3189.552, 1129.1077, 522.71704, NULL, 0),
(@PATH, 2, 3190.9585, 1131.1576, 522.71704, NULL, 0),
(@PATH, 3, 3191.4937, 1131.9379, 523.2773, NULL, 0),
(@PATH, 4, 3191.7725, 1132.3441, 523.7482, NULL, 0),
(@PATH, 5, 3192.4448, 1133.3242, 524.4415, NULL, 0),
(@PATH, 6, 3193.141, 1134.3394, 525.24384, NULL, 0),
(@PATH, 7, 3193.7708, 1135.257, 525.782, NULL, 0),
(@PATH, 8, 3198.337, 1139.6685, 526.40765, NULL, 0),
(@PATH, 9, 3202.7751, 1148.9062, 526.3624, NULL, 0),
(@PATH, 10, 3202.909, 1154.0156, 526.3624, NULL, 0),
(@PATH, 11, 3201.3254, 1161.7379, 526.05853, NULL, 0),
(@PATH, 12, 3201.6216, 1167.9705, 522.8022, NULL, 0),
(@PATH, 13, 3201.2383, 1170.925, 522.8413, NULL, 0),
(@PATH, 14, 3201.0815, 1172.1317, 522.76776, NULL, 0),
(@PATH, 15, 3200.2993, 1178.1598, 522.7687, NULL, 0),
(@PATH, 16, 3196.8352, 1217.408, 522.71704, NULL, 0),
(@PATH, 17, 3200.181, 1179.0819, 522.7687, NULL, 0),
(@PATH, 18, 3201.2385, 1170.9248, 522.8324, NULL, 0),
(@PATH, 19, 3201.6216, 1167.9705, 522.8022, NULL, 0),
(@PATH, 20, 3201.5627, 1166.7303, 522.7792, NULL, 0),
(@PATH, 21, 3201.338, 1162.0021, 525.9312, NULL, 0),
(@PATH, 22, 3202.909, 1154.0156, 526.3624, NULL, 0),
(@PATH, 23, 3202.7751, 1148.9062, 526.3624, NULL, 0),
(@PATH, 24, 3198.337, 1139.6685, 526.40765, NULL, 0),
(@PATH, 25, 3193.7708, 1135.257, 525.782, NULL, 0),
(@PATH, 26, 3189.552, 1129.1077, 522.71704, NULL, 0),
(@PATH, 27, 3183.5686, 1121.4861, 522.71704, NULL, 0),
(@PATH, 28, 3179.8933, 1117.7274, 522.8108, NULL, 0),
(@PATH, 29, 3158.875, 1092.4966, 523.78644, NULL, 0),
(@PATH, 30, 3179.8933, 1117.7274, 522.8108, NULL, 0),
(@PATH, 31, 3183.5686, 1121.4861, 522.71704, NULL, 0);

UPDATE `creature` SET `position_x`=3188.1455, `position_y`=1127.0577, `position_z`=522.71704, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sacred Flame Vintner
SET @MOVERGUID := @CGUID+106;
SET @ENTRY := 222927;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Sacred Flame Vintner - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3192.1982, 1236.1482, 522.71704, NULL, 0),
(@PATH, 1, 3193.5815, 1218.1528, 522.71704, NULL, 0),
(@PATH, 2, 3194.9648, 1200.1575, 522.71704, NULL, 0),
(@PATH, 3, 3195.454, 1193.7926, 522.71704, NULL, 0),
(@PATH, 4, 3195.854, 1188.5901, 522.71704, NULL, 0),
(@PATH, 5, 3196.2556, 1183.3629, 522.71704, NULL, 0),
(@PATH, 6, 3196.575, 1179.2095, 522.71704, NULL, 0),
(@PATH, 7, 3196.8374, 1175.7966, 522.71704, NULL, 0),
(@PATH, 8, 3197.0227, 1173.3842, 522.71704, NULL, 0),
(@PATH, 9, 3197.2822, 1170.0087, 522.717, NULL, 0),
(@PATH, 10, 3198.1338, 1164.7101, 523.9138, NULL, 0),
(@PATH, 11, 3199.8203, 1158.9705, 526.4629, NULL, 0),
(@PATH, 12, 3199.698, 1148.0729, 526.3264, NULL, 0),
(@PATH, 13, 3195.8489, 1142.8906, 526.34644, NULL, 0),
(@PATH, 14, 3189.645, 1132.9723, 522.97, NULL, 0),
(@PATH, 15, 3183.4297, 1125.5817, 522.71704, NULL, 0),
(@PATH, 16, 3173.4114, 1113.8923, 522.8077, NULL, 0),
(@PATH, 17, 3166.9705, 1105.8906, 522.80383, NULL, 0),
(@PATH, 18, 3155.5923, 1093.1528, 523.70593, NULL, 0),
(@PATH, 19, 3151.434, 1088.8195, 523.7449, NULL, 0),
(@PATH, 20, 3150.8633, 1088.223, 523.7759, NULL, 0),
(@PATH, 21, 3151.434, 1088.8195, 523.7449, NULL, 0),
(@PATH, 22, 3152.005, 1089.4159, 523.71387, NULL, 0),
(@PATH, 23, 3155.52, 1093.0885, 523.71704, NULL, 0),
(@PATH, 24, 3166.9705, 1105.8906, 522.80383, NULL, 0),
(@PATH, 25, 3173.4114, 1113.8923, 522.8077, NULL, 0),
(@PATH, 26, 3183.4297, 1125.5817, 522.71704, NULL, 0),
(@PATH, 27, 3189.645, 1132.9723, 522.97, NULL, 0),
(@PATH, 28, 3195.8489, 1142.8906, 526.34644, NULL, 0),
(@PATH, 29, 3199.698, 1148.0729, 526.3264, NULL, 0),
(@PATH, 30, 3199.8203, 1158.9705, 526.4629, NULL, 0),
(@PATH, 31, 3198.1338, 1164.7101, 523.9138, NULL, 0),
(@PATH, 32, 3197.2822, 1170.0087, 522.717, NULL, 0),
(@PATH, 33, 3193.5815, 1218.1528, 522.71704, NULL, 0);

UPDATE `creature` SET `position_x`=3192.1982, `position_y`=1236.1482, `position_z`=522.71704, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Arathi Knight
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+67;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+67, @CGUID+67, 0, 0, 515, 0, 0),
(@CGUID+67, @CGUID+69, 2, 90, 515, 4, 10),
(@CGUID+67, @CGUID+70, 2, 270, 515, 4, 10);

SET @MOVERGUID := @CGUID+67;
SET @ENTRY := 206696;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Arathi Knight - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2993.347, 1149.061, 522.6219, NULL, 0),
(@PATH, 1, 2996.5745, 1147.0696, 522.6219, NULL, 0),
(@PATH, 2, 2999.802, 1145.0781, 522.6219, NULL, 0),
(@PATH, 3, 3003.0652, 1135.5591, 522.6219, NULL, 0),
(@PATH, 4, 3004.23, 1121.382, 522.6219, NULL, 0),
(@PATH, 5, 3003.0652, 1135.5591, 522.6219, NULL, 0),
(@PATH, 6, 2999.802, 1145.0781, 522.6219, NULL, 0),
(@PATH, 7, 2989.0625, 1151.7048, 522.6219, NULL, 0),
(@PATH, 8, 2977.3828, 1159.6302, 522.6219, NULL, 0),
(@PATH, 9, 2970.4019, 1165.7952, 522.6219, NULL, 0),
(@PATH, 10, 2961.2595, 1176.8038, 522.6219, NULL, 0),
(@PATH, 11, 2970.4019, 1165.7952, 522.6219, NULL, 0),
(@PATH, 12, 2977.3828, 1159.6302, 522.6219, NULL, 0),
(@PATH, 13, 2989.0625, 1151.7048, 522.6219, NULL, 0);

UPDATE `creature` SET `position_x`=2993.347, `position_y`=1149.061, `position_z`=522.6219, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 122962, 1, '448503');

-- Path for Arathi Knight
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+68;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+68, @CGUID+68, 0, 0, 515, 0, 0),
(@CGUID+68, @CGUID+71, 2, 90, 515, 0, 7),
(@CGUID+68, @CGUID+72, 2, 270, 515, 0, 7);

SET @MOVERGUID := @CGUID+68;
SET @ENTRY := 206696;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Arathi Knight - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3012.6648, 1105.7136, 522.6219, NULL, 0),
(@PATH, 1, 3011.4019, 1122.7223, 522.6219, NULL, 0),
(@PATH, 2, 3010.139, 1139.731, 522.6219, NULL, 0),
(@PATH, 3, 3015.9497, 1145.9028, 522.6219, NULL, 0),
(@PATH, 4, 3023.803, 1156.3385, 522.6219, NULL, 0),
(@PATH, 5, 3035.3604, 1166.7379, 522.6219, NULL, 0),
(@PATH, 6, 3042.9402, 1175.0642, 522.6219, NULL, 0),
(@PATH, 7, 3030.2317, 1202.6077, 522.6219, NULL, 68),
(@PATH, 8, 3042.9402, 1175.0642, 522.6219, NULL, 0),
(@PATH, 9, 3035.3604, 1166.7379, 522.6219, NULL, 0),
(@PATH, 10, 3023.803, 1156.3385, 522.6219, NULL, 0),
(@PATH, 11, 3015.9497, 1145.9028, 522.6219, NULL, 0),
(@PATH, 12, 3010.139, 1139.731, 522.6219, NULL, 0);

UPDATE `creature` SET `position_x`=3012.6648, `position_y`=1105.7136, `position_z`=522.6219, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 122962, 1, '448503');

-- Path for Arathi Knight
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+55;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+55, @CGUID+55, 0, 0, 515, 0, 0),
(@CGUID+55, @CGUID+47, 2, 90, 515, 0, 14),
(@CGUID+55, @CGUID+52, 2, 270, 515, 0, 14),
(@CGUID+55, @CGUID+46, 3, 20, 515, 0, 14),
(@CGUID+55, @CGUID+48, 3, 340, 515, 0, 14);

SET @MOVERGUID := @CGUID+55;
SET @ENTRY := 206696;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Arathi Knight - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2931.9526, 1194.2954, 526.8498, NULL, 0),
(@PATH, 1, 2931.9055, 1192.2952, 526.584, NULL, 0),
(@PATH, 2, 2931.8584, 1190.2949, 526.3182, NULL, 0),
(@PATH, 3, 2931.611, 1179.7709, 526.24133, NULL, 0),
(@PATH, 4, 2931.1555, 1172.3993, 526.39825, NULL, 0),
(@PATH, 5, 2929.6858, 1166.1372, 526.5737, NULL, 0),
(@PATH, 6, 2932.9558, 1159.7535, 526.5113, NULL, 0),
(@PATH, 7, 2938.8923, 1154.2344, 526.59326, NULL, 0),
(@PATH, 8, 2945.2014, 1151.7726, 526.37506, NULL, 0),
(@PATH, 9, 2952.7517, 1146.1476, 526.42914, NULL, 0),
(@PATH, 10, 2959.2805, 1141.0834, 526.50684, NULL, 0),
(@PATH, 11, 2964.9253, 1136.4219, 526.71204, NULL, 0),
(@PATH, 12, 2968.6614, 1132.8837, 526.7613, NULL, 0),
(@PATH, 13, 2969.0774, 1127.7448, 526.78015, NULL, 0),
(@PATH, 14, 2967.8628, 1122.4791, 526.917, NULL, 0),
(@PATH, 15, 2969.0774, 1127.7448, 526.78015, NULL, 0),
(@PATH, 16, 2968.6614, 1132.8837, 526.7613, NULL, 0),
(@PATH, 17, 2964.9253, 1136.4219, 526.71204, NULL, 0),
(@PATH, 18, 2959.2805, 1141.0834, 526.50684, NULL, 0),
(@PATH, 19, 2952.7517, 1146.1476, 526.42914, NULL, 0),
(@PATH, 20, 2945.2014, 1151.7726, 526.37506, NULL, 0),
(@PATH, 21, 2938.8923, 1154.2344, 526.59326, NULL, 0),
(@PATH, 22, 2932.9558, 1159.7535, 526.5113, NULL, 0),
(@PATH, 23, 2929.6858, 1166.1372, 526.5737, NULL, 0),
(@PATH, 24, 2931.1555, 1172.3993, 526.39825, NULL, 0),
(@PATH, 25, 2931.611, 1179.7709, 526.24133, NULL, 0),
(@PATH, 26, 2931.9055, 1192.2952, 526.584, NULL, 0);

UPDATE `creature` SET `position_x`=2931.9526, `position_y`=1194.2954, `position_z`=526.8498, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 122962, 1, '448503');

-- Path for Arathi Knight
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+79;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+79, @CGUID+79, 0, 0, 515, 0, 0),
(@CGUID+79, @CGUID+78, 2, 90, 515, 10, 21),
(@CGUID+79, @CGUID+80, 2, 270, 515, 10, 21),
(@CGUID+79, @CGUID+81, 3, 20, 515, 10, 21),
(@CGUID+79, @CGUID+77, 3, 340, 515, 10, 21);

SET @MOVERGUID := @CGUID+79;
SET @ENTRY := 206696;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Arathi Knight - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3073.7944, 1185.03, 526.7131, NULL, 0),
(@PATH, 1, 3073.6138, 1183.147, 526.7071, NULL, 0),
(@PATH, 2, 3073.433, 1181.2639, 526.7011, NULL, 0),
(@PATH, 3, 3072.343, 1172.4062, 526.57965, NULL, 0),
(@PATH, 4, 3070.1807, 1165.6198, 526.6147, NULL, 0),
(@PATH, 5, 3066.5703, 1163.3281, 526.64526, NULL, 0),
(@PATH, 6, 3059.2092, 1157.5538, 526.5876, NULL, 0),
(@PATH, 7, 3054.0842, 1150.526, 526.47473, NULL, 0),
(@PATH, 8, 3049.3672, 1141.9497, 526.62616, NULL, 0),
(@PATH, 9, 3045.3447, 1135.9723, 526.78845, NULL, 0),
(@PATH, 10, 3048.6467, 1132.0209, 526.76465, NULL, 0),
(@PATH, 11, 3045.3447, 1135.9723, 526.78845, NULL, 0),
(@PATH, 12, 3049.3672, 1141.9497, 526.62616, NULL, 0),
(@PATH, 13, 3054.0842, 1150.526, 526.47473, NULL, 0),
(@PATH, 14, 3059.2092, 1157.5538, 526.5876, NULL, 0),
(@PATH, 15, 3066.5703, 1163.3281, 526.64526, NULL, 0),
(@PATH, 16, 3070.1807, 1165.6198, 526.6147, NULL, 0),
(@PATH, 17, 3072.343, 1172.4062, 526.57965, NULL, 0),
(@PATH, 18, 3073.433, 1181.2639, 526.7011, NULL, 0),
(@PATH, 19, 3073.9722, 1186.8785, 526.9162, NULL, 0),
(@PATH, 20, 3071.9888, 1195.1041, 526.53296, NULL, 0),
(@PATH, 21, 3068.625, 1202.3698, 526.3023, NULL, 0),
(@PATH, 22, 3071.9888, 1195.1041, 526.53296, NULL, 0),
(@PATH, 23, 3073.9722, 1186.8785, 526.9162, NULL, 0);

UPDATE `creature` SET `position_x`=3073.7944, `position_y`=1185.03, `position_z`=526.7131, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 122962, 1, '448503');

-- Path for Arathi Knight
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+190;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+190, @CGUID+190, 0, 0, 515, 0, 0),
(@CGUID+190, @CGUID+191, 2, 90, 515, 6, 14),
(@CGUID+190, @CGUID+192, 2, 270, 515, 6, 14);

SET @MOVERGUID := @CGUID+190;
SET @ENTRY := 206696;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Arathi Knight - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3072.1733, 1355.8467, 546.46875, NULL, 0),
(@PATH, 1, 3070.0012, 1359.2601, 546.46875, NULL, 0),
(@PATH, 2, 3067.829, 1362.6736, 546.46875, NULL, 0),
(@PATH, 3, 3060.2222, 1368.2969, 546.5175, NULL, 0),
(@PATH, 4, 3048.7292, 1371.7223, 546.5404, NULL, 0),
(@PATH, 5, 3043.2144, 1369.5573, 546.5304, NULL, 0),
(@PATH, 6, 3033.808, 1357.3629, 546.5405, NULL, 5571),
(@PATH, 7, 3043.2144, 1369.5573, 546.5304, NULL, 0),
(@PATH, 8, 3048.7292, 1371.7223, 546.5404, NULL, 0),
(@PATH, 9, 3060.2222, 1368.2969, 546.5175, NULL, 0),
(@PATH, 10, 3067.829, 1362.6736, 546.46875, NULL, 0),
(@PATH, 11, 3074.9028, 1351.5573, 546.46875, NULL, 0),
(@PATH, 12, 3079.0703, 1343.4705, 546.5008, NULL, 0),
(@PATH, 13, 3075.2517, 1339.0591, 546.52765, NULL, 0),
(@PATH, 14, 3067.7795, 1329.316, 546.52765, NULL, 6811),
(@PATH, 15, 3075.2517, 1339.0591, 546.52765, NULL, 0),
(@PATH, 16, 3079.0703, 1343.4705, 546.5008, NULL, 0),
(@PATH, 17, 3074.9028, 1351.5573, 546.46875, NULL, 0);

UPDATE `creature` SET `position_x`=3072.1733, `position_y`=1355.8467, `position_z`=546.46875, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 122962, 1, '448503');

-- Path for Guard Captain Suleyman
SET @MOVERGUID := @CGUID+23;
SET @ENTRY := 212826;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Guard Captain Suleyman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2956.0154, 1190.4253, 522.7265, NULL, 0),
(@PATH, 1, 2959.2942, 1188.1588, 522.6742, NULL, 0),
(@PATH, 2, 2962.573, 1185.8923, 522.6219, NULL, 0),
(@PATH, 3, 2968.111, 1193.5798, 522.6219, NULL, 0),
(@PATH, 4, 2976.5051, 1205.4305, 522.6219, NULL, 0),
(@PATH, 5, 2985.2136, 1214.1337, 522.6219, NULL, 0),
(@PATH, 6, 2994.3906, 1217.1163, 522.6219, NULL, 0),
(@PATH, 7, 3010.4185, 1214.9531, 522.6219, NULL, 0),
(@PATH, 8, 3024.388, 1209.3004, 522.6219, NULL, 0),
(@PATH, 9, 3032.2102, 1203.2916, 522.6219, NULL, 0),
(@PATH, 10, 3037.5486, 1196.7067, 522.6219, NULL, 0),
(@PATH, 11, 3051.0798, 1207.493, 523.8655, NULL, 0),
(@PATH, 12, 3064.619, 1222.8385, 525.32556, NULL, 0),
(@PATH, 13, 3062.554, 1219.7673, 525.32556, NULL, 6508),
(@PATH, 14, 3055.882, 1213.25, 525.0956, NULL, 0),
(@PATH, 15, 3037.4045, 1195.993, 522.6219, NULL, 0),
(@PATH, 16, 3018.3542, 1213.2535, 522.6219, NULL, 0),
(@PATH, 17, 3003.059, 1214.4479, 522.6219, NULL, 0),
(@PATH, 18, 3000.9602, 1196.6685, 523.6136, NULL, 0),
(@PATH, 19, 3001.2744, 1193.0173, 523.7088, NULL, 9761),
(@PATH, 20, 3000, 1212.7188, 522.6219, NULL, 0),
(@PATH, 21, 2999.0017, 1215.6041, 522.6219, NULL, 0),
(@PATH, 22, 2989.4731, 1215.8195, 522.6219, NULL, 0),
(@PATH, 23, 2980.855, 1210.0868, 522.6219, NULL, 0),
(@PATH, 24, 2970.0051, 1199.2205, 522.6219, NULL, 0),
(@PATH, 25, 2964.269, 1189.2604, 522.6219, NULL, 0),
(@PATH, 26, 2957.0034, 1188.4844, 522.6219, NULL, 0),
(@PATH, 27, 2947.6216, 1196.8663, 524.93555, NULL, 0),
(@PATH, 28, 2936.5435, 1206.9635, 526.9449, NULL, 2888),
(@PATH, 29, 2952.0034, 1193.1979, 523.4299, NULL, 0);

UPDATE `creature` SET `position_x`=2956.0154, `position_y`=1190.4253, `position_z`=522.7265, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 4, '424652 422355');

-- Path for Fervent Sharpshooter
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+173;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+173, @CGUID+173, 0, 0, 515, 0, 0),
(@CGUID+173, @CGUID+177, 2, 90, 515, 7, 13),
(@CGUID+173, @CGUID+174, 2, 270, 515, 7, 13);

SET @MOVERGUID := @CGUID+173;
SET @ENTRY := 206694;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Fervent Sharpshooter - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3039.676, 1278.8699, 551.5965, NULL, 0),
(@PATH, 1, 3042.4587, 1276.8864, 549.73804, NULL, 0),
(@PATH, 2, 3045.2415, 1274.9028, 547.8796, NULL, 0),
(@PATH, 3, 3045.7058, 1274.4923, 547.5304, NULL, 0),
(@PATH, 4, 3051.2761, 1269.5677, 547.6869, NULL, 0),
(@PATH, 5, 3057.572, 1264.6493, 547.5292, NULL, 0),
(@PATH, 6, 3063.8845, 1259.4427, 547.66846, NULL, 0),
(@PATH, 7, 3070.0564, 1250.2153, 547.5832, NULL, 0),
(@PATH, 8, 3063.8845, 1259.4427, 547.66846, NULL, 0),
(@PATH, 9, 3057.572, 1264.6493, 547.5292, NULL, 0),
(@PATH, 10, 3051.2761, 1269.5677, 547.6869, NULL, 0),
(@PATH, 11, 3045.2415, 1274.9028, 547.8796, NULL, 0),
(@PATH, 12, 3038.1807, 1279.9358, 551.62, NULL, 0),
(@PATH, 13, 3032.6165, 1284.7604, 551.6195, NULL, 0),
(@PATH, 14, 3038.1807, 1279.9358, 551.62, NULL, 0);

UPDATE `creature` SET `position_x`=3039.676, `position_y`=1278.8699, `position_z`=551.5965, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Fervent Sharpshooter
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+166;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+166, @CGUID+166, 0, 0, 515, 0, 0),
(@CGUID+166, @CGUID+160, 2, 90, 515, 13, 21),
(@CGUID+166, @CGUID+165, 2, 270, 515, 13, 21);

SET @MOVERGUID := @CGUID+166;
SET @ENTRY := 206694;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Fervent Sharpshooter - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2927.6045, 1246.2024, 547.5348, NULL, 0),
(@PATH, 1, 2928.249, 1247.2242, 547.53217, NULL, 0),
(@PATH, 2, 2928.8936, 1248.2461, 547.52954, NULL, 0),
(@PATH, 3, 2929.061, 1248.5117, 547.53827, NULL, 0),
(@PATH, 4, 2930.2014, 1250.3195, 547.5468, NULL, 0),
(@PATH, 5, 2933.3232, 1254.1559, 547.569, NULL, 0),
(@PATH, 6, 2935.245, 1256.7783, 547.7195, NULL, 0),
(@PATH, 7, 2936.5842, 1258.1632, 547.6758, NULL, 0),
(@PATH, 8, 2942.9368, 1266.2048, 548.925, NULL, 0),
(@PATH, 9, 2946.5251, 1268.6875, 551.4197, NULL, 0),
(@PATH, 10, 2948.6736, 1272.5555, 551.6702, NULL, 0),
(@PATH, 11, 2950.5808, 1274.2084, 551.63837, NULL, 0),
(@PATH, 12, 2954.9001, 1276.5868, 551.62274, NULL, 0),
(@PATH, 13, 2958.2708, 1279.2291, 551.59283, NULL, 0),
(@PATH, 14, 2950.5808, 1274.2084, 551.63837, NULL, 0),
(@PATH, 15, 2948.6736, 1272.5555, 551.6702, NULL, 0),
(@PATH, 16, 2946.5251, 1268.6875, 551.4197, NULL, 0),
(@PATH, 17, 2942.9368, 1266.2048, 548.925, NULL, 0),
(@PATH, 18, 2936.5842, 1258.1632, 547.6758, NULL, 0),
(@PATH, 19, 2930.2014, 1250.3195, 547.5468, NULL, 0),
(@PATH, 20, 2926.0894, 1243.8004, 547.68243, NULL, 0),
(@PATH, 21, 2923.093, 1241, 547.60236, NULL, 0);

UPDATE `creature` SET `position_x`=2927.6045, `position_y`=1246.2024, `position_z`=547.5348, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Fanatical Conjuror
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+119;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+119, @CGUID+119, 0, 0, 515, 0, 0),
(@CGUID+119, @CGUID+122, 2, 90, 515, 4, 9),
(@CGUID+119, @CGUID+121, 2, 270, 515, 4, 9),
(@CGUID+119, @CGUID+120, 4, 270, 515, 4, 9);

SET @MOVERGUID := @CGUID+119;
SET @ENTRY := 206698;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Fanatical Conjuror - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3123.2783, 1300.1428, 547.609, NULL, 0),
(@PATH, 1, 3123.7737, 1297.6088, 547.609, NULL, 0),
(@PATH, 2, 3124.269, 1295.0747, 547.609, NULL, 0),
(@PATH, 3, 3125.8254, 1286.4879, 547.609, NULL, 0),
(@PATH, 4, 3126.3386, 1274.6805, 547.609, NULL, 0),
(@PATH, 5, 3125.8254, 1286.4879, 547.609, NULL, 0),
(@PATH, 6, 3124.269, 1295.0747, 547.609, NULL, 0),
(@PATH, 7, 3122.7102, 1303.0486, 547.609, NULL, 0),
(@PATH, 8, 3122.769, 1313.5035, 547.609, NULL, 0),
(@PATH, 9, 3122.4211, 1323.8055, 547.609, NULL, 0),
(@PATH, 10, 3122.769, 1313.5035, 547.609, NULL, 0),
(@PATH, 11, 3122.7102, 1303.0486, 547.609, NULL, 0);

UPDATE `creature` SET `position_x`=3123.2783, `position_y`=1300.1428, `position_z`=547.609, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Forgemaster Damian
SET @MOVERGUID := @CGUID+22;
SET @ENTRY := 212831;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Forge Master Damian - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3185.9817, 1306.033, 553.41846, NULL, 3483),
(@PATH, 1, 3165.506, 1316.9645, 553.32635, NULL, 0),
(@PATH, 2, 3166.034, 1318.3455, 553.7098, NULL, 2999),
(@PATH, 3, 3175.6848, 1317.1163, 553.3264, NULL, 2785),
(@PATH, 4, 3173.4114, 1287.5955, 553.3264, NULL, 8582);

UPDATE `creature` SET `position_x`=3185.9817, `position_y`=1306.033, `position_z`=553.41846, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 4);

-- Path for War Lynx
SET @MOVERGUID := @CGUID+186;
SET @ENTRY := 206699;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0, NULL, 'War Lynx - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3054.4585, 1313.2874, 546.9591, NULL, 0),
(@PATH, 1, 3052.1145, 1315.1598, 546.79956, NULL, 0),
(@PATH, 2, 3049.7705, 1317.0322, 546.64, NULL, 0),
(@PATH, 3, 3046.6455, 1319.5283, 546.84674, NULL, 0),
(@PATH, 4, 3045.083, 1320.7764, 547.0175, NULL, 0),
(@PATH, 5, 3043.5205, 1322.0244, 547.29364, NULL, 0),
(@PATH, 6, 3041.1768, 1323.8965, 547.48694, NULL, 0),
(@PATH, 7, 3034.1455, 1329.5127, 547.18024, NULL, 0),
(@PATH, 8, 3031.8018, 1331.3848, 547.396, NULL, 0),
(@PATH, 9, 3030.119, 1332.7223, 547.47736, NULL, 0),
(@PATH, 10, 3052.1145, 1315.1598, 546.79956, NULL, 0);

UPDATE `creature` SET `position_x`=3054.4585, `position_y`=1313.2874, `position_z`=546.9591, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for War Lynx
SET @MOVERGUID := @CGUID+187;
SET @ENTRY := 206699;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'War Lynx - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3048.9375, 1313.6208, 546.4245, NULL, 0),
(@PATH, 1, 3046.5903, 1315.4896, 546.7068, NULL, 0),
(@PATH, 2, 3044.2432, 1317.3584, 546.9891, NULL, 0),
(@PATH, 3, 3043.461, 1317.9814, 547.162, NULL, 0),
(@PATH, 4, 3042.6787, 1318.6045, 547.36945, NULL, 0),
(@PATH, 5, 3041.1143, 1319.8506, 547.5386, NULL, 0),
(@PATH, 6, 3039.5498, 1321.0967, 547.72015, NULL, 0),
(@PATH, 7, 3034.8564, 1324.835, 547.5426, NULL, 0),
(@PATH, 8, 3030.163, 1328.5732, 547.80707, NULL, 0),
(@PATH, 9, 3026.691, 1331.3351, 547.9348, NULL, 0),
(@PATH, 10, 3046.5903, 1315.4896, 546.7068, NULL, 0);

UPDATE `creature` SET `position_x`=3048.9375, `position_y`=1313.6208, `position_z`=546.4245, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
