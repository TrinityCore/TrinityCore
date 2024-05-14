SET @CGUID := 4000000;
SET @OGUID := 4000000;

DELETE FROM `creature` WHERE `map` = 389;
DELETE FROM `gameobject` WHERE `map` = 389;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+129;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 61724, 389, 2437, 2437, '1', '0', 0, 0, 1, -20.5821952819824218, -51.1100807189941406, -21.7212467193603515, 2.745470762252807617, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Commander Bagran (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+1, 61657, 389, 2437, 2437, '1', '0', 0, 0, 0, -62.6194534301757812, -32.0748672485351562, -18.3341884613037109, 5.016366958618164062, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Adolescent Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+2, 53488, 389, 2437, 2437, '1', '0', 0, 0, 0, -18.6087303161621093, -63.83367919921875, -21.2950592041015625, 4.590215682983398437, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Summon Enabler Stalker (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 99201 - Summon Enabler)
(@CGUID+3, 61657, 389, 2437, 2437, '1', '0', 0, 0, 0, -59.5037841796875, -35.4129867553710937, -18.9467296600341796, 2.765716314315795898, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Adolescent Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+4, 61658, 389, 2437, 2437, '1', '0', 0, 0, 0, -95.0029220581054687, -34.2260818481445312, -27.8864288330078125, 3.166848659515380859, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Mature Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+5, 61560, 389, 2437, 2437, '1', '0', 0, 0, 0, -98.9559402465820312, -50.4501762390136718, -32.2286338806152343, 1.643412232398986816, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Lava (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 119436 - Raise Lava (Splash))
(@CGUID+6, 53488, 389, 2437, 2437, '1', '0', 0, 0, 0, 0.903475463390350341, -14.5965547561645507, -17.4777889251708984, 4.590215682983398437, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Summon Enabler Stalker (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 99201 - Summon Enabler)
(@CGUID+7, 61657, 389, 2437, 2437, '1', '0', 0, 0, 0, -61.6939353942871093, -37.0140342712402343, -18.4916858673095703, 1.682236790657043457, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Adolescent Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+8, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -99.4745025634765625, -38.7639884948730468, -29.2049179077148437, 3.395897865295410156, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death, 119897 - Trogg On Fire)
(@CGUID+9, 61657, 389, 2437, 2437, '1', '0', 0, 0, 0, -75.0639877319335937, -37.5734405517578125, -18.7147445678710937, 6.040735244750976562, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Adolescent Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+10, 61716, 389, 2437, 2437, '1', '0', 0, 0, 1, -16.5847759246826171, -47.4531288146972656, -21.780374526977539, 1.117187023162841796, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Invoker Xorenth (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+11, 53488, 389, 2437, 2437, '1', '0', 0, 0, 0, -5.25880289077758789, -39.7717170715332031, -21.7566337585449218, 4.590215682983398437, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Summon Enabler Stalker (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 99201 - Summon Enabler)
(@CGUID+12, 61657, 389, 2437, 2437, '1', '0', 0, 0, 0, -78.229034423828125, -30.6828136444091796, -19.1403923034667968, 6.281239032745361328, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Adolescent Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+13, 61658, 389, 2437, 2437, '1', '0', 0, 0, 0, -127.022041320800781, -40.4365043640136718, -32.6677894592285156, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Mature Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+14, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -61.5377197265625, -32.6011428833007812, -18.4476375579833984, 3.007720947265625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+15, 61404, 389, 2437, 2437, '1', '0', 0, 0, 1, -26.0675258636474609, -57.8227806091308593, -21.2881736755371093, 2.620827674865722656, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Elite (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+16, 61657, 389, 2437, 2437, '1', '0', 0, 0, 0, -74.9759063720703125, -32.3497276306152343, -18.9411678314208984, 6.280265331268310546, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Adolescent Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+17, 61680, 389, 2437, 2437, '1', '0', 0, 0, 0, -15.9521608352661132, -44.8339500427246093, -21.6942329406738281, 6.076798915863037109, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Scout (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 114371 - Permanent Feign Death)
(@CGUID+18, 61658, 389, 2437, 2437, '1', '0', 0, 0, 0, -127.890327453613281, -30.7097110748291015, -32.7364921569824218, 6.260376930236816406, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Mature Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+19, 61404, 389, 2437, 2437, '1', '0', 0, 0, 1, -22.3918399810791015, -42.5714797973632812, -21.6952705383300781, 2.922248363494873046, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Elite (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+20, 61657, 389, 2437, 2437, '1', '0', 0, 0, 0, -78.1840591430664062, -35.1548042297363281, -19.5920143127441406, 6.121375560760498046, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Adolescent Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+21, 61672, 389, 2437, 2437, '1', '0', 0, 0, 1, -146.052520751953125, 12.47431564331054687, -22.0800380706787109, 2.899011611938476562, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Acolyte (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+22, 61672, 389, 2437, 2437, '1', '0', 0, 0, 1, -105.082252502441406, 41.41724777221679687, -17.9890079498291015, 1.799525022506713867, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Acolyte (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+23, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -140.490432739257812, -17.800058364868164, -54.661163330078125, 4.049035549163818359, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death, 119897 - Trogg On Fire)
(@CGUID+24, 61680, 389, 2437, 2437, '1', '0', 0, 0, 0, -88.8939590454101562, 68.73284912109375, -18.5693340301513671, 3.619823932647705078, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Scout (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+25, 61658, 389, 2437, 2437, '1', '0', 0, 0, 0, -151.033889770507812, -29.7282447814941406, -35.6130752563476562, 4.122201442718505859, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Mature Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+26, 61657, 389, 2437, 2437, '1', '0', 0, 0, 0, -153.818527221679687, -33.349090576171875, -36.7905044555664062, 0.495184987783432006, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Adolescent Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+27, 61672, 389, 2437, 2437, '1', '0', 0, 0, 1, -96.2438430786132812, 47.40497970581054687, -17.4780654907226562, 2.669122219085693359, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Acolyte (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+28, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -132.79766845703125, 11.9237222671508789, -20.6849327087402343, 3.00788283348083496, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+29, 61790, 389, 2437, 2437, '1', '0', 0, 0, 0, -88.9256973266601562, 68.8180694580078125, -17.734039306640625, 3.789035797119140625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Inconspicuous Crate (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+30, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -145.333099365234375, -61.9615402221679687, -58.935028076171875, 2.29627227783203125, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+31, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -99.6469192504882812, 42.68917083740234375, -17.4792060852050781, 2.142660140991210937, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+32, 61672, 389, 2437, 2437, '1', '0', 0, 0, 1, -134.239547729492187, 3.847588062286376953, -20.6103973388671875, 3.00788283348083496, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Acolyte (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+33, 61657, 389, 2437, 2437, '1', '0', 0, 0, 0, -149.702346801757812, -33.9838752746582031, -35.3103981018066406, 2.881952524185180664, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Adolescent Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+34, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -147.012954711914062, 8.534029960632324218, -22.532541275024414, 2.880395174026489257, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+35, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -150.899154663085937, -32.5604438781738281, -35.6334381103515625, 1.903555512428283691, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+36, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -150.554397583007812, 0.980217814445495605, -39.5867881774902343, 2.29627227783203125, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+37, 61795, 389, 2437, 2437, '1', '0', 0, 0, 0, -163.858779907226562, -6.70620059967041015, -63.4371910095214843, 4.835338115692138671, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dancing Flames (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+38, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -149.863235473632812, 23.81163215637207031, -38.505401611328125, 0.41613703966140747, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death, 119897 - Trogg On Fire)
(@CGUID+39, 61666, 389, 2437, 2437, '1', '0', 0, 0, 1, -275.042694091796875, -63.9594879150390625, -60.3566360473632812, 2.27193307876586914, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Houndmaster (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+40, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -287.344879150390625, -77.7270660400390625, -60.5109405517578125, 1.5842362642288208, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+41, 61658, 389, 2437, 2437, '1', '0', 0, 0, 0, -216.080169677734375, -33.6876907348632812, -53.6354827880859375, 3.30042576789855957, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Mature Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+42, 61680, 389, 2437, 2437, '1', '0', 0, 0, 0, -172.466445922851562, 1.87796485424041748, -33.0117301940917968, 1.645429253578186035, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Scout (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+43, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -294.35943603515625, 5.152032375335693359, -47.2411880493164062, 0.525527775287628173, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+44, 61795, 389, 2437, 2437, '1', '0', 0, 0, 0, -178.007186889648437, -54.5244979858398437, -63.4445610046386718, 4.773592948913574218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dancing Flames (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+45, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -191.724594116210937, 146.2300567626953125, -25.1365604400634765, 2.761220693588256835, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+46, 61705, 389, 2437, 2437, '1', '0', 0, 0, 1, -265.40777587890625, 99.22902679443359375, -24.9407920837402343, 1.388207912445068359, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Flamecaller (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 120264 - Fire Channeling)
(@CGUID+47, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -146.190689086914062, 24.20841407775878906, -38.754425048828125, 4.872707366943359375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+48, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -286.828887939453125, -77.580596923828125, -60.5104331970214843, 4.290942668914794921, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+49, 61795, 389, 2437, 2437, '1', '0', 0, 0, 0, -172.788528442382812, -8.29690742492675781, -63.0921783447265625, 4.835338115692138671, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dancing Flames (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+50, 61412, 389, 2437, 2437, '1', '0', 0, 0, 1, -117.043693542480468, 71.07047271728515625, -20.7203025817871093, 5.343509197235107421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Koranthal (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 119928 - Shadow Vortex)
(@CGUID+51, 61601, 389, 2437, 2437, '1', '0', 0, 0, 0, -276.396759033203125, 11.52048587799072265, -47.3142623901367187, 6.251702308654785156, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Lava (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 119896 - Raise Lava (No Splash))
(@CGUID+52, 61666, 389, 2437, 2437, '1', '0', 0, 0, 1, -273.028106689453125, -50.9456291198730468, -60.7310523986816406, 3.38415074348449707, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Houndmaster (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+53, 61413, 389, 2437, 2437, '1', '0', 0, 0, 0, -117.043998718261718, 71.07050323486328125, 1.375769615173339843, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Flame Visual (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+54, 61463, 389, 2437, 2437, '1', '0', 0, 0, 0, -257.177459716796875, 172.4151153564453125, -19.63763427734375, 5.57793283462524414, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slagmaw (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+55, 61795, 389, 2437, 2437, '1', '0', 0, 0, 0, -204.258132934570312, -58.2133255004882812, -63.7112846374511718, 4.773592948913574218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dancing Flames (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+56, 61630, 389, 2437, 2437, '1', '0', 0, 0, 0, -117.043998718261718, 71.07050323486328125, -20.7202663421630859, 5.351353645324707031, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Ground Runes (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 119627 - Ground Runes)
(@CGUID+57, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -181.100616455078125, 4.53391885757446289, -55.7473258972167968, 3.236798524856567382, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death, 119897 - Trogg On Fire)
(@CGUID+58, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -272.643218994140625, 101.7028579711914062, -24.9311504364013671, 0.921120822429656982, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+59, 61825, 389, 2437, 2437, '1', '0', 0, 0, 0, -14.5403680801391601, -63.1118965148925781, -21.2900638580322265, 4.290363788604736328, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Stormwind Portal (Area: Ragefire Chasm - Difficulty: 0) CreateObject1
(@CGUID+60, 61680, 389, 2437, 2437, '1', '0', 0, 0, 0, -310.909088134765625, -24.321136474609375, -58.851043701171875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Scout (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+61, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -175.254150390625, -65.86981201171875, -57.7781448364257812, 4.202850818634033203, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+62, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -253.731201171875, -62.3930549621582031, -61.9606132507324218, 2.80023503303527832, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+63, 61795, 389, 2437, 2437, '1', '0', 0, 0, 0, -179.942306518554687, -9.48245143890380859, -63.16351318359375, 4.835338115692138671, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dancing Flames (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+64, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -190.944046020507812, 162.391448974609375, -25.1365604400634765, 3.501852273941040039, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+65, 61705, 389, 2437, 2437, '1', '0', 0, 0, 1, -189.287155151367187, 154.578521728515625, -25.1365604400634765, 3.179543733596801757, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Flamecaller (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 120264 - Fire Channeling)
(@CGUID+66, 61672, 389, 2437, 2437, '1', '0', 0, 0, 1, -206.7435302734375, 90.8302154541015625, -25.2988910675048828, 2.359599113464355468, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Acolyte (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+67, 61795, 389, 2437, 2437, '1', '0', 0, 0, 0, -198.761856079101562, -13.5985441207885742, -63.32586669921875, 4.835338115692138671, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dancing Flames (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+68, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -202.531280517578125, -0.91308933496475219, -61.8754158020019531, 2.031862258911132812, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+69, 61666, 389, 2437, 2437, '1', '0', 0, 0, 1, -280.78851318359375, -40.1979560852050781, -60.6164779663085937, 4.424197196960449218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Houndmaster (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+70, 61658, 389, 2437, 2437, '1', '0', 0, 0, 0, -214.95477294921875, -40.6686325073242187, -53.3408279418945312, 3.300426959991455078, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Mature Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+71, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -288.37841796875, -79.4172515869140625, -60.51690673828125, 5.157424449920654296, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+72, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -227.945388793945312, -64.4666519165039062, -60.9303665161132812, 2.29627227783203125, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+73, 61795, 389, 2437, 2437, '1', '0', 0, 0, 0, -190.235488891601562, -11.5225496292114257, -63.5619659423828125, 4.835338115692138671, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dancing Flames (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+74, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -257.836822509765625, 97.82950592041015625, -24.9345703125, 1.635761976242065429, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+75, 61672, 389, 2437, 2437, '1', '0', 0, 0, 1, -223.386001586914062, 9.908562660217285156, -43.4950332641601562, 3.19938206672668457, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Acolyte (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+76, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -253.561691284179687, -6.7516489028930664, -62.9746665954589843, 2.341398954391479492, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+77, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -203.312713623046875, -71.1200103759765625, -63.0215263366699218, 3.395897865295410156, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death, 119897 - Trogg On Fire)
(@CGUID+78, 61680, 389, 2437, 2437, '1', '0', 0, 0, 0, -257.035003662109375, -49.3293266296386718, -60.6822929382324218, 3.412533998489379882, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Scout (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+79, 61672, 389, 2437, 2437, '1', '0', 0, 0, 1, -202.755264282226562, 94.84171295166015625, -25.5048561096191406, 2.359531402587890625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Acolyte (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+80, 61669, 389, 2437, 2437, '1', '0', 0, 0, 0, -276.682373046875, -34.6181182861328125, -60.6084671020507812, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Oggleflint (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+81, 61666, 389, 2437, 2437, '1', '0', 0, 0, 1, -241.533859252929687, -37.5543708801269531, -57.5347251892089843, 0.047805339097976684, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Houndmaster (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+82, 61795, 389, 2437, 2437, '1', '0', 0, 0, 0, -168.996246337890625, -53.4878425598144531, -63.7740440368652343, 4.773592948913574218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dancing Flames (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+83, 61658, 389, 2437, 2437, '1', '0', 0, 0, 0, -243.8291015625, -42.8094444274902343, -58.073394775390625, 0.094867125153541564, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Mature Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+84, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -286.217559814453125, -79.0773544311523437, -60.5157470703125, 3.007720947265625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+85, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -222.492019653320312, -10.768010139465332, -61.7210235595703125, 3.66176605224609375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+86, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -263.848419189453125, -93.3509292602539062, -61.7371788024902343, 4.834143638610839843, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death, 119897 - Trogg On Fire)
(@CGUID+87, 61666, 389, 2437, 2437, '1', '0', 0, 0, 1, -214.054306030273437, -36.9438323974609375, -53.1630363464355468, 0.158816784620285034, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Houndmaster (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+88, 61795, 389, 2437, 2437, '1', '0', 0, 0, 0, -195.619949340820312, -56.66741943359375, -63.498382568359375, 4.773592948913574218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dancing Flames (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+89, 61658, 389, 2437, 2437, '1', '0', 0, 0, 0, -258.19317626953125, -49.7012443542480468, -60.6388893127441406, 0.425607234239578247, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Mature Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+90, 61780, 389, 2437, 2437, '1', '0', 0, 0, 0, -311.0406494140625, -24.0794010162353515, -59.348602294921875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Suspicious Rock (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+91, 61408, 389, 2437, 2437, '1', '0', 0, 0, 0, -284.638092041015625, -53.8252983093261718, -60.7344245910644531, 0.321085065603256225, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Adarogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+92, 61672, 389, 2437, 2437, '1', '0', 0, 0, 1, -223.375747680664062, 5.908548355102539062, -43.42791748046875, 3.203055381774902343, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Acolyte (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+93, 61795, 389, 2437, 2437, '1', '0', 0, 0, 0, -185.220474243164062, -55.2663650512695312, -63.8084259033203125, 4.773592948913574218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dancing Flames (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+94, 61658, 389, 2437, 2437, '1', '0', 0, 0, 0, -244.688507080078125, -32.9989776611328125, -58.1243629455566406, 0.047805339097976684, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Mature Flame Hound (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+95, 61659, 389, 2437, 2437, '1', '0', 0, 0, 0, -161.739151000976562, -30.8161697387695312, -58.2288436889648437, 2.312207460403442382, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Slain Trogg (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+96, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -206.679550170898437, 94.7536163330078125, -25.4557037353515625, 2.358986854553222656, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+97, 61528, 389, 2437, 2437, '1', '0', 0, 0, 0, -369.5009765625, 166.2117462158203125, -18.520233154296875, 1.312978386878967285, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Lava Guard Gordoth (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+98, 61680, 389, 2437, 2437, '1', '0', 0, 0, 0, -286.979156494140625, 134.4914093017578125, -27.0196571350097656, 1.858569502830505371, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Scout (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+99, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -222.388870239257812, 205.345123291015625, -24.9082794189453125, 4.255483150482177734, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+100, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -294.763671875, 139.5491943359375, -25.047159194946289, 0.311637789011001586, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+101, 61705, 389, 2437, 2437, '1', '0', 0, 0, 1, -231.04302978515625, 206.9251251220703125, -24.7876014709472656, 4.398036003112792968, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Flamecaller (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 120264 - Fire Channeling)
(@CGUID+102, 61705, 389, 2437, 2437, '1', '0', 0, 0, 1, -296.531402587890625, 146.731292724609375, -24.9419841766357421, 6.237174510955810546, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Flamecaller (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 120264 - Fire Channeling)
(@CGUID+103, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -296.17578125, 154.1418914794921875, -25.0448169708251953, 6.056548118591308593, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+104, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -238.91119384765625, 207.3594970703125, -24.811929702758789, 4.711674213409423828, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+105, 61705, 389, 2437, 2437, '1', '0', 0, 0, 1, -288.647003173828125, 205.4743804931640625, -25.7272491455078125, 5.534626007080078125, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Flamecaller (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+106, 61672, 389, 2437, 2437, '1', '0', 0, 0, 1, -284.8271484375, 209.64697265625, -25.3874111175537109, 5.534630775451660156, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Acolyte (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+107, 61678, 389, 2437, 2437, '1', '0', 0, 0, 1, -301.978973388671875, 219.9210357666015625, -25.1960506439208984, 2.665938615798950195, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Corrupted Reaver (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+108, 61680, 389, 2437, 2437, '1', '0', 0, 0, 0, -375.999603271484375, 181.5575714111328125, -20.8818187713623046, 0.462225705385208129, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Scout (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+109, 61680, 389, 2437, 2437, '1', '0', 0, 0, 0, -377.136138916015625, 185.1432342529296875, -20.9594631195068359, 0.462225705385208129, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Scout (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+110, 61644, 389, 2437, 2437, '1', '0', 0, 0, 0, -364.913726806640625, 191.71240234375, -22.2707500457763671, 1.35503387451171875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Researcher (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 51835 - Cosmetic - Channel Omni)
(@CGUID+111, 61644, 389, 2437, 2437, '1', '0', 0, 0, 0, -351.528564453125, 203.4578857421875, -22.1447582244873046, 3.033090114593505859, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Researcher (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 51835 - Cosmetic - Channel Omni)
(@CGUID+112, 61680, 389, 2437, 2437, '1', '0', 0, 0, 0, -378.609283447265625, 188.419342041015625, -20.8019371032714843, 0.462225705385208129, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Kor'kron Scout (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+113, 61644, 389, 2437, 2437, '1', '0', 0, 0, 0, -381.4127197265625, 197.913238525390625, -21.7808914184570312, 3.033090114593505859, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Researcher (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 120022 - Bloody Suicide)
(@CGUID+114, 61644, 389, 2437, 2437, '1', '0', 0, 0, 0, -375.02716064453125, 203.0890350341796875, -21.8010158538818359, 0.021282918751239776, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Researcher (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 51835 - Cosmetic - Channel Omni)
(@CGUID+115, 61644, 389, 2437, 2437, '1', '0', 0, 0, 0, -362.57110595703125, 215.7284393310546875, -21.5527229309082031, 4.725623130798339843, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Researcher (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 51835 - Cosmetic - Channel Omni)
(@CGUID+116, 61644, 389, 2437, 2437, '1', '0', 0, 0, 0, -377.921844482421875, 209.6007843017578125, -21.8010158538818359, 2.879298925399780273, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Researcher (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 120022 - Bloody Suicide)
(@CGUID+117, 61644, 389, 2437, 2437, '1', '0', 0, 0, 1, -370.877166748046875, 217.5922393798828125, -21.8010158538818359, 1.452374100685119628, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- Dark Shaman Researcher (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1 (Auras: 120022 - Bloody Suicide)
(@CGUID+118, 61821, 389, 2437, 2437, '1', '0', 0, 0, 1, -23.8016738891601562, -42.9664192199707031, -21.7354469299316406, 2.703596353530883789, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- SI:7 Commando (Area: Ragefire Chasm - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+119, 61822, 389, 2437, 2437, '1', '0', 0, 0, 1, -23.4554901123046875, -52.0436363220214843, -21.5553131103515625, 2.71608138084411621, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- SI:7 Field Commander Dirken (Area: Ragefire Chasm - Difficulty: 0) CreateObject1
(@CGUID+120, 61823, 389, 2437, 2437, '1', '0', 0, 0, 1, -14.3153553009033203, -59.7260208129882812, -21.2881736755371093, 4.612118721008300781, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- High Sorceress Aryna (Area: Ragefire Chasm - Difficulty: 0) CreateObject1 (Auras: 32783 - Arcane Channeling)
(@CGUID+121, 61788, 389, 2437, 2437, '1', '0', 0, 0, 0, -88.8939590454101562, 68.73284912109375, -18.5693340301513671, 3.619823932647705078, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- SI:7 Ranger (Area: Ragefire Chasm - Difficulty: 0) CreateObject1
(@CGUID+122, 61788, 389, 2437, 2437, '1', '0', 0, 0, 0, -172.404190063476562, 1.685063481330871582, -33.0251502990722656, 1.645429253578186035, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- SI:7 Ranger (Area: Ragefire Chasm - Difficulty: 0) CreateObject1
(@CGUID+123, 61788, 389, 2437, 2437, '1', '0', 0, 0, 0, -257.035003662109375, -49.3293266296386718, -60.6822929382324218, 3.412533998489379882, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- SI:7 Ranger (Area: Ragefire Chasm - Difficulty: 0) CreateObject1
(@CGUID+124, 61821, 389, 2437, 2437, '1', '0', 0, 0, 1, -27.8330326080322265, -57.7237091064453125, -21.2881736755371093, 2.703596353530883789, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- SI:7 Commando (Area: Ragefire Chasm - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+125, 61788, 389, 2437, 2437, '1', '0', 0, 0, 0, -310.909088134765625, -24.321136474609375, -58.851043701171875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- SI:7 Ranger (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+126, 61788, 389, 2437, 2437, '1', '0', 0, 0, 0, -286.979156494140625, 134.4914093017578125, -27.0196571350097656, 1.858569502830505371, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- SI:7 Ranger (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+127, 61788, 389, 2437, 2437, '1', '0', 0, 0, 0, -375.999603271484375, 181.5575714111328125, -20.8818187713623046, 0.462225705385208129, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- SI:7 Ranger (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+128, 61788, 389, 2437, 2437, '1', '0', 0, 0, 0, -378.609283447265625, 188.419342041015625, -20.8019371032714843, 0.462225705385208129, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358), -- SI:7 Ranger (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@CGUID+129, 61788, 389, 2437, 2437, '1', '0', 0, 0, 0, -377.136138916015625, 185.1432342529296875, -20.9594631195068359, 0.462225705385208129, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54358); -- SI:7 Ranger (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+129;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '35356 119897'), -- Slain Trogg - 35356 - Spawn Feign Death, 119897 - Trogg On Fire
(@CGUID+10, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Invoker Xorenth
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '114371'), -- Kor'kron Scout - 114371 - Permanent Feign Death
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '35356 119897'), -- Slain Trogg - 35356 - Spawn Feign Death, 119897 - Trogg On Fire
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Kor'kron Elite
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Dark Shaman Acolyte
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '35356 119897'), -- Slain Trogg - 35356 - Spawn Feign Death, 119897 - Trogg On Fire
(@CGUID+42, 0, 0, 0, 3, 0, 1, 0, 0, 2286, 0, 0, 0, ''), -- Kor'kron Scout
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Corrupted Reaver
(@CGUID+53, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Flame Visual
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Slagmaw
(@CGUID+57, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '35356 119897'), -- Slain Trogg - 35356 - Spawn Feign Death, 119897 - Trogg On Fire
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Corrupted Reaver
(@CGUID+64, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Corrupted Reaver
(@CGUID+74, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Corrupted Reaver
(@CGUID+77, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '35356 119897'), -- Slain Trogg - 35356 - Spawn Feign Death, 119897 - Trogg On Fire
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 0, 2281, 0, 0, 0, ''), -- Kor'kron Scout
(@CGUID+86, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '35356 119897'), -- Slain Trogg - 35356 - Spawn Feign Death, 119897 - Trogg On Fire
(@CGUID+89, 0, 0, 0, 0, 0, 1, 0, 0, 1735, 0, 0, 0, ''), -- Mature Flame Hound
(@CGUID+90, 0, 0, 0, 0, 0, 1, 0, 0, 1443, 0, 0, 0, ''), -- Suspicious Rock
(@CGUID+97, 0, 0, 0, 0, 0, 1, 0, 0, 947, 0, 0, 3, ''), -- Lava Guard Gordoth
(@CGUID+98, 0, 0, 0, 3, 0, 1, 0, 0, 2286, 0, 0, 0, ''), -- Kor'kron Scout
(@CGUID+99, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Corrupted Reaver
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Corrupted Reaver
(@CGUID+104, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Corrupted Reaver
(@CGUID+103, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Corrupted Reaver
(@CGUID+110, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Dark Shaman Researcher - 51835 - Cosmetic - Channel Omni
(@CGUID+111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Dark Shaman Researcher - 51835 - Cosmetic - Channel Omni
(@CGUID+113, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Dark Shaman Researcher - 120022 - Bloody Suicide
(@CGUID+114, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Dark Shaman Researcher - 51835 - Cosmetic - Channel Omni
(@CGUID+115, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Dark Shaman Researcher - 51835 - Cosmetic - Channel Omni
(@CGUID+116, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Dark Shaman Researcher - 120022 - Bloody Suicide
(@CGUID+117, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Dark Shaman Researcher - 120022 - Bloody Suicide
(@CGUID+122, 0, 0, 0, 3, 0, 1, 0, 0, 2297, 0, 0, 0, ''), -- SI:7 Ranger
(@CGUID+123, 0, 0, 0, 0, 0, 1, 0, 0, 2281, 0, 0, 0, ''); -- SI:7 Ranger

-- Gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+59;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 175289, 389, 2437, 2437, '1', '0', 0, 42.16175079345703125, 8.731289863586425781, 10.95489311218261718, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+1, 175290, 389, 2437, 2437, '1', '0', 0, 25.43651771545410156, 6.905048370361328125, 11.09283161163330078, 2.870561838150024414, 0.023352622985839843, 0.002361297607421875, 0.990575790405273437, 0.134939551353454589, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+2, 175293, 389, 2437, 2437, '1', '0', 0, 1.820737123489379882, 32.22469329833984375, -11.4590320587158203, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+3, 175308, 389, 2437, 2437, '1', '0', 0, 5.655314922332763671, 68.33867645263671875, -9.77679443359375, 5.672319889068603515, 0, 0, -0.3007059097290039, 0.953716933727264404, 7200, 255, 1, 54358), -- Dark Earth Fungus and Mushrooms (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+4, 175294, 389, 2437, 2437, '1', '0', 0, 51.6565399169921875, 38.07189178466796875, -8.68831253051757812, 2.364918231964111328, 0, 0, 0.925539970397949218, 0.378649920225143432, 7200, 255, 1, 54358), -- Darkfire Enclave (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+5, 175287, 389, 2437, 2437, '1', '0', 0, 66.61365509033203125, 34.3891448974609375, -8.68421077728271484, 2.783795118331909179, 0, 0, 0.984040260314941406, 0.177946031093597412, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+6, 175288, 389, 2437, 2437, '1', '0', 0, 17.93456077575683593, 52.2161102294921875, -11.1567792892456054, 2.783795118331909179, 0, 0, 0.984040260314941406, 0.177946031093597412, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+7, 175305, 389, 2437, 2437, '1', '0', 0, 2.431438207626342773, 65.43672943115234375, -9.98579216003417968, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+8, 175291, 389, 2437, 2437, '1', '0', 0, 59.62629318237304687, 56.40472412109375, -8.9676513671875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+9, 175306, 389, 2437, 2437, '1', '0', 0, 66.9001312255859375, 75.5443572998046875, -9.23550796508789062, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+10, 175292, 389, 2437, 2437, '1', '0', 0, 39.16888046264648437, 52.85946273803710937, -3.46940898895263671, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+11, 175307, 389, 2437, 2437, '1', '0', 0, 62.39905166625976562, 61.42024993896484375, -9.25620841979980468, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Shadowdeep Reagents (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+12, 175309, 389, 2437, 2437, '1', '0', 0, 56.76680374145507812, 101.443359375, -5.37527799606323242, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+13, 175295, 389, 2437, 2437, '1', '0', 0, 39.55092620849609375, 173.858642578125, 33.711578369140625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+14, 211874, 389, 2437, 2437, '1', '0', 0, -275.3785400390625, -32.0627098083496093, -60.6917991638183593, 5.399146080017089843, 0, 0, -0.4277658462524414, 0.903889596462249755, 7200, 255, 1, 54358), -- Fresh Carcass (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+15, 175310, 389, 2437, 2437, '1', '0', 0, 13.76981449127197265, 100.6888580322265625, -1.96313798427581787, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+16, 175296, 389, 2437, 2437, '1', '0', 0, 10.57739830017089843, 161.32891845703125, 23.05486679077148437, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+17, 175311, 389, 2437, 2437, '1', '0', 0, 63.90713119506835937, 88.0039520263671875, -5.47026681900024414, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 7200, 255, 1, 54358), -- Ironwood Staves and Wands (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+18, 175297, 389, 2437, 2437, '1', '0', 0, 50.52103424072265625, 143.6693267822265625, 14.13112354278564453, 2.103119850158691406, 0, 0, 0.868198394775390625, 0.496217250823974609, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+19, 175298, 389, 2437, 2437, '1', '0', 0, -4.4208073616027832, 120.71875, 12.24668407440185546, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+20, 175299, 389, 2437, 2437, '1', '0', 0, 64.38864898681640625, 114.0154953002929687, 12.10890865325927734, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+21, 175300, 389, 2437, 2437, '1', '0', 0, 24.81655120849609375, 132.47576904296875, 13.33210277557373046, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+22, 175301, 389, 2437, 2437, '1', '0', 0, 52.0177764892578125, 113.447601318359375, 10.73921394348144531, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 7200, 255, 1, 54358), -- Brazier (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+23, 175302, 389, 2437, 2437, '1', '0', 0, 17.95473670959472656, 117.037933349609375, 12.55860424041748046, 6.257006168365478515, 0, 0, -0.01308917999267578, 0.999914348125457763, 7200, 255, 1, 54358), -- The Slow Blade (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+24, 175303, 389, 2437, 2437, '1', '0', 0, 69.48308563232421875, 115.5179290771484375, 12.08853530883789062, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 54358), -- Rekkul's Poisons (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+25, 175304, 389, 2437, 2437, '1', '0', 0, 36.35284805297851562, 133.0380401611328125, 13.02516365051269531, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 7200, 255, 1, 54358), -- Shadowswift Brotherhood (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+26, 211874, 389, 2437, 2437, '1', '0', 0, -267.80450439453125, -65.6171951293945312, -60.4399681091308593, 5.399146080017089843, 0, 0, -0.4277658462524414, 0.903889596462249755, 7200, 255, 1, 54358), -- Fresh Carcass (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+27, 211874, 389, 2437, 2437, '1', '0', 0, -271.967681884765625, -68.3712539672851562, -60.4399681091308593, 3.547429084777832031, 0, 0, -0.97948265075683593, 0.201528429985046386, 7200, 255, 1, 54358), -- Fresh Carcass (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+28, 211788, 389, 2437, 2437, '1', '0', 0, -381.400787353515625, 215.40411376953125, -21.8843498229980468, 5.474973201751708984, 0, 0, -0.39319705963134765, 0.919454216957092285, 7200, 255, 1, 54358), -- Horde Crate (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+29, 211788, 389, 2437, 2437, '1', '0', 0, -377.785064697265625, 219.061767578125, -21.8843498229980468, 5.474973201751708984, 0, 0, -0.39319705963134765, 0.919454216957092285, 7200, 255, 1, 54358), -- Horde Crate (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+30, 211788, 389, 2437, 2437, '1', '0', 0, -372.995513916015625, 222.741180419921875, -21.7960376739501953, 4.858319282531738281, 0, 0, -0.65367698669433593, 0.756773650646209716, 7200, 255, 1, 54358), -- Horde Crate (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+31, 211788, 389, 2437, 2437, '1', '0', 0, -379.771148681640625, 217.4134063720703125, -21.8843498229980468, 5.474973201751708984, 0, 0, -0.39319705963134765, 0.919454216957092285, 7200, 255, 1, 54358), -- Horde Crate (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+32, 211792, 389, 2437, 2437, '1', '0', 0, -369.570220947265625, 166.3546600341796875, -21.4520740509033203, 1.455002784729003906, 0, 0, 0.665005683898925781, 0.746838331222534179, 7200, 255, 1, 54358), -- Gordoth Cage (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+33, 211883, 389, 2437, 2437, '1', '0', 0, -375.851837158203125, 181.5803375244140625, -21.7554359436035156, 0.462224155664443969, 0, 0, 0.229060173034667968, 0.973412275314331054, 7200, 255, 1, 54358), -- Scout Cage (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+34, 211884, 389, 2437, 2437, '1', '0', 0, -376.98834228515625, 185.1659698486328125, -21.6588211059570312, 0.462224155664443969, 0, 0, 0.229060173034667968, 0.973412275314331054, 7200, 255, 1, 54358), -- Scout Cage (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+35, 211885, 389, 2437, 2437, '1', '0', 0, -378.46148681640625, 188.442108154296875, -21.5763893127441406, 0.462224155664443969, 0, 0, 0.229060173034667968, 0.973412275314331054, 7200, 255, 1, 54358), -- Scout Cage (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+36, 211791, 389, 2437, 2437, '1', '0', 0, -363.688079833984375, 203.4561767578125, -22.0807552337646484, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Ground Rune (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+37, 211781, 389, 2437, 2437, '1', '0', 0, -385.601531982421875, 201.9926910400390625, -20.0377197265625, 6.000252723693847656, 0, 0, -0.14099502563476562, 0.990010321140289306, 7200, 255, 1, 54358), -- Lab Table (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+38, 211785, 389, 2437, 2437, '1', '0', 0, -384.918701171875, 201.4041900634765625, -21.8372344970703125, 5.904479026794433593, 0, 0, -0.18822383880615234, 0.982126176357269287, 7200, 255, 1, 54358), -- Lab Table (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+39, 211787, 389, 2437, 2437, '1', '0', 0, -381.986297607421875, 208.889404296875, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Plague Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+40, 211789, 389, 2437, 2437, '1', '0', 0, -378.20660400390625, 214.1094512939453125, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Generic Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+41, 211789, 389, 2437, 2437, '1', '0', 0, -372.3662109375, 220.2500762939453125, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Generic Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+42, 211787, 389, 2437, 2437, '1', '0', 0, -382.7774658203125, 213.0112152099609375, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Plague Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+43, 211789, 389, 2437, 2437, '1', '0', 0, -376.686798095703125, 214.9898834228515625, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Generic Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+44, 211787, 389, 2437, 2437, '1', '0', 0, -383.328826904296875, 209.8941497802734375, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Plague Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+45, 211789, 389, 2437, 2437, '1', '0', 0, -378.242095947265625, 215.8182373046875, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Generic Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+46, 211787, 389, 2437, 2437, '1', '0', 0, -384.661773681640625, 210.6073455810546875, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Plague Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+47, 211786, 389, 2437, 2437, '1', '0', 0, -380.627410888671875, 211.1078338623046875, -21.9803314208984375, 5.810708999633789062, 0, 0, -0.23404693603515625, 0.972225308418273925, 7200, 255, 1, 54358), -- Chemistry Set (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+48, 211789, 389, 2437, 2437, '1', '0', 0, -379.656646728515625, 214.3125457763671875, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Generic Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+49, 211789, 389, 2437, 2437, '1', '0', 0, -376.983795166015625, 215.7892913818359375, -19.791208267211914, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Generic Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+50, 211787, 389, 2437, 2437, '1', '0', 0, -383.28753662109375, 211.62921142578125, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Plague Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+51, 211789, 389, 2437, 2437, '1', '0', 0, -376.744659423828125, 216.979034423828125, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Generic Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+52, 211789, 389, 2437, 2437, '1', '0', 0, -378.4923095703125, 214.8982086181640625, -19.7978801727294921, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Generic Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+53, 211790, 389, 2437, 2437, '1', '0', 0, -368.91705322265625, 222.1090850830078125, -21.6345653533935546, 1.791203260421752929, 0, 0, 0.780585289001464843, 0.625049293041229248, 7200, 255, 1, 54358), -- Surgical Table (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+54, 211784, 389, 2437, 2437, '1', '0', 0, -373.425872802734375, 222.881805419921875, -21.7808685302734375, 5.458774566650390625, 0, 0, -0.40063095092773437, 0.916239500045776367, 7200, 255, 2, 54358), -- Lab Vial (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+55, 211784, 389, 2437, 2437, '1', '0', 0, -377.456573486328125, 219.8531341552734375, -21.8843498229980468, 5.458774566650390625, 0, 0, -0.40063095092773437, 0.916239500045776367, 7200, 255, 2, 54358), -- Lab Vial (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+56, 211787, 389, 2437, 2437, '1', '0', 0, -374.8526611328125, 220.5328826904296875, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Plague Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+57, 211784, 389, 2437, 2437, '1', '0', 0, -381.208251953125, 216.6232452392578125, -21.8843498229980468, 5.458774566650390625, 0, 0, -0.40063095092773437, 0.916239500045776367, 7200, 255, 2, 54358), -- Lab Vial (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+58, 211787, 389, 2437, 2437, '1', '0', 0, -376.47503662109375, 221.328033447265625, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358), -- Plague Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
(@OGUID+59, 211787, 389, 2437, 2437, '1', '0', 0, -375.178253173828125, 222.289642333984375, -21.8843498229980468, 0, 0, 0, 0, 1, 7200, 255, 1, 54358); -- Plague Barrel (Area: Ragefire Chasm - Difficulty: Normal) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+59;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0), -- Dark Earth Fungus and Mushrooms
(@OGUID+4, 0, 0, 1, -0.00000004371138828, 0, 0), -- Darkfire Enclave
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+6, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+8, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+9, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+10, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+11, 0, 0, 1, -0.00000004371138828, 0, 0), -- Shadowdeep Reagents
(@OGUID+12, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+13, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+15, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+16, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+17, 0, 0, 1, -0.00000004371138828, 0, 0), -- Ironwood Staves and Wands
(@OGUID+18, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+19, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+21, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+22, 0, 0, 1, -0.00000004371138828, 0, 0), -- Brazier
(@OGUID+23, 0, 0, 1, -0.00000004371138828, 0, 0), -- The Slow Blade
(@OGUID+24, 0, 0, 1, -0.00000004371138828, 0, 0), -- Rekkul's Poisons
(@OGUID+25, 0, 0, 1, -0.00000004371138828, 0, 0); -- Shadowswift Brotherhood

-- Template
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=61528; -- Lava Guard Gordoth
UPDATE `creature_template` SET `npcflag`=1, `unit_flags3`=16777217 WHERE `entry`=61780; -- Suspicious Rock
UPDATE `creature_template` SET `faction`=3341, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=198497; -- Nathenaseth
UPDATE `creature_template` SET `faction`=3341, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=198541; -- Zurenoth
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=61463; -- Slagmaw
UPDATE `creature_template` SET `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=61669; -- Oggleflint
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry` IN (61601, 61560); -- Lava
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=61630; -- Ground Runes
UPDATE `creature_template` SET `unit_flags2`=67110912 WHERE `entry`=61800; -- Magnaw's Head
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=61413; -- Flame Visual
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=61412; -- Dark Shaman Koranthal
UPDATE `creature_template` SET `unit_flags3`=335544320 WHERE `entry`=61408; -- Adarogg
UPDATE `creature_template` SET `unit_flags2`=0, `unit_flags3`=25165825 WHERE `entry`=61795; -- Dancing Flames
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=61790; -- Inconspicuous Crate
UPDATE `creature_template` SET `unit_flags3`=67108864, `AIName`='SmartAI' WHERE `entry`=61657; -- Adolescent Flame Hound
UPDATE `creature_template` SET `unit_flags3`=67108864 WHERE `entry`=61658; -- Mature Flame Hound
UPDATE `creature_template` SET `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=61659; -- Slain Trogg
UPDATE `creature_template` SET `unit_flags`=33555264, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=61680; -- Kor'kron Scout
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=61788; -- SI:7 Ranger
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=16777217 WHERE `entry`=61825; -- Stormwind Portal
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=2048, `AIName`='SmartAI' WHERE `entry`=61823; -- High Sorceress Aryna
UPDATE `creature_template` SET `npcflag`=3, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=61822; -- SI:7 Field Commander Dirken
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=61821; -- SI:7 Commando
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2099200, `unit_flags3`=524289 WHERE `entry`=61409; -- Demonic Leap

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (61659, 61795, 61790, 61601, 61412, 61669, 61630, 61821);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(61659, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '35356'), -- Slain Trogg - 35356 - Spawn Feign Death
(61795, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Dancing Flames
(61790, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Inconspicuous Crate
(61601, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '119896'), -- Lava - 119896 - Raise Lava (No Splash)
(61412, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Dark Shaman Koranthal - 119928 - Shadow Vortex
(61669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '35356'), -- 61669 (Oggleflint) - Spawn Feign Death
(61630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '119627'), -- 61630 (Ground Runes) - Ground Runes
(61821, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''); -- SI:7 Commando

-- Spawn groups
DELETE FROM `spawn_group_template` WHERE `groupId` IN (69, 70);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(69, 'RFC - Alliance spawns', 32),
(70, 'RFC - Horde spawns', 32);

DELETE FROM `spawn_group` WHERE `groupId` IN (69,70) AND `spawnType`=0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(69, 0, @CGUID+59),		-- Alliance
(69, 0, @CGUID+118),
(69, 0, @CGUID+119),
(69, 0, @CGUID+120),
(69, 0, @CGUID+121),
(69, 0, @CGUID+122),
(69, 0, @CGUID+123),
(69, 0, @CGUID+124),
(69, 0, @CGUID+125),
(69, 0, @CGUID+126),
(69, 0, @CGUID+127),
(69, 0, @CGUID+128),
(69, 0, @CGUID+129),
(70, 0, @CGUID+0),		-- Horde
(70, 0, @CGUID+10),
(70, 0, @CGUID+15),
(70, 0, @CGUID+17),
(70, 0, @CGUID+19),
(70, 0, @CGUID+24),
(70, 0, @CGUID+42),
(70, 0, @CGUID+60),
(70, 0, @CGUID+78),
(70, 0, @CGUID+98),
(70, 0, @CGUID+108),
(70, 0, @CGUID+109),
(70, 0, @CGUID+112);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceGroup` = 0 AND `SourceEntry` IN (69, 70);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, 69, 0, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'RFC - Spawn Alliance NPCs if you are Alliance Player'),
(33, 0, 70, 0, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'RFC - Spawn Horde NPCs if you are Horde Player');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=61724 AND `MenuID`=13816);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(61724, 13816, 54358); -- Commander Bagran

DELETE FROM `gossip_menu` WHERE (`MenuID`=13816 AND `TextID`=61284);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(13816, 61284, 54358); -- 61724 (Commander Bagran)

DELETE FROM `gossip_menu` WHERE (`MenuID`=13816 AND `TextID`=61284);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(13816, 61284, 54358); -- 61724 (Commander Bagran)

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=61463 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(61463, 61800, 0, 1, 'Slagmaw - Magnaw\'s Head', 7, 0); -- Slagmaw - Magnaw's Head

-- NPC SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=61463 AND `spell_id`=46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(61463, 46598, 0, 0);

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61528 AND `DifficultyID`=1); -- Lava Guard Gordoth
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=61780 AND `DifficultyID`=1); -- Suspicious Rock
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=198497 AND `DifficultyID`=1); -- Nathenaseth
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54205 WHERE (`DifficultyID`=1 AND `Entry` IN (46741,3369)) OR (`DifficultyID`=0 AND `Entry` IN (53488,20489,9564,44948,62822,62821,20486,20492,20491,20488,32520,130911,20493,12136,44918,50477,50323,62114,61369,42506,11066,49131,14881,44919,46742,62115,199275,49737,49743,50488,44158,15476,3310,63626,1420,46709,42548,3335,3368,143622,47253,49837,46708,3372,3371,11017,3413,14498,7010,3412,3216,2857,88706,88705,88704,141310,5639,5909,47254,47247,47246,3329,199264,47248,5875,3296));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=198541 AND `DifficultyID`=1); -- Zurenoth
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=805306624, `VerifiedBuild`=54205 WHERE (`Entry`=61463 AND `DifficultyID`=1); -- Slagmaw
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=805306624, `VerifiedBuild`=54205 WHERE (`Entry`=61716 AND `DifficultyID`=1); -- Invoker Xorenth
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61669 AND `DifficultyID`=1); -- Oggleflint
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=207, `StaticFlags1`=536870912, `VerifiedBuild`=54205 WHERE (`DifficultyID`=1 AND `Entry` IN (61601,61560)); -- Lava
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=61630 AND `DifficultyID`=1); -- Ground Runes
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=805306624, `VerifiedBuild`=54205 WHERE (`Entry`=61800 AND `DifficultyID`=1); -- Magnaw's Head
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=61413 AND `DifficultyID`=1); -- Flame Visual
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61412 AND `DifficultyID`=1); -- Dark Shaman Koranthal
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61408 AND `DifficultyID`=1); -- Adarogg
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61666 AND `DifficultyID`=1); -- Corrupted Houndmaster
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61724 AND `DifficultyID`=1); -- Commander Bagran
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=805306368, `VerifiedBuild`=54205 WHERE (`Entry`=61795 AND `DifficultyID`=1); -- Dancing Flames
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61705 AND `DifficultyID`=1); -- Corrupted Flamecaller
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=536871168, `VerifiedBuild`=54205 WHERE (`Entry`=61790 AND `DifficultyID`=1); -- Inconspicuous Crate
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61657 AND `DifficultyID`=1); -- Adolescent Flame Hound
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61658 AND `DifficultyID`=1); -- Mature Flame Hound
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61678 AND `DifficultyID`=1); -- Corrupted Reaver
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61659 AND `DifficultyID`=1); -- Slain Trogg
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61672 AND `DifficultyID`=1); -- Dark Shaman Acolyte
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=61404 AND `DifficultyID`=1); -- Kor'kron Elite
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=805306624, `VerifiedBuild`=54205 WHERE (`Entry`=61680 AND `DifficultyID`=1); -- Kor'kron Scout
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54358 WHERE (`Entry`=61409 AND `DifficultyID`=1); -- Demonic Leap
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=805306624, `VerifiedBuild`=54358 WHERE (`Entry`=61788 AND `DifficultyID`=1); -- SI:7 Ranger
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `VerifiedBuild`=54358 WHERE (`Entry`=61825 AND `DifficultyID`=1); -- Stormwind Portal
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=54358 WHERE (`Entry`=61823 AND `DifficultyID`=1); -- High Sorceress Aryna
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54358 WHERE (`Entry`=61822 AND `DifficultyID`=1); -- SI:7 Field Commander Dirken
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268435456, `VerifiedBuild`=54358 WHERE (`Entry`=61821 AND `DifficultyID`=1); -- SI:7 Commando

-- Corrupted Flamecaller smart ai
SET @ENTRY := 61705;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+65), -(@CGUID+101), -(@CGUID+102), -(@CGUID+46));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+65), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 120264, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Reset - Self: Cast spell 120264 on self'),
(-(@CGUID+101), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 120264, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Reset - Self: Cast spell 120264 on self'),
(-(@CGUID+102), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 120264, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Reset - Self: Cast spell 120264 on self'),
(-(@CGUID+46), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 120264, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Reset - Self: Cast spell 120264 on self');

-- Dark Shaman Researcher smart ai
SET @ENTRY := 61644;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+110), -(@CGUID+114), -(@CGUID+115), -(@CGUID+111));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+110), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 51835, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Reset - Self: Cast spell 51835 on self'),
(-(@CGUID+114), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 51835, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Reset - Self: Cast spell 51835 on self'),
(-(@CGUID+115), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 51835, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Reset - Self: Cast spell 51835 on self'),
(-(@CGUID+111), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 51835, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Reset - Self: Cast spell 51835 on self');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=61657 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61657, 0, 0, 0, '', 1, 0, 100, 0, 2000, 8000, 2000, 8000, 0, '', 11, 120064, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Adolescent Flame Hound (OOC) - Self: Cast spell 120064 on Self');

DELETE FROM `smart_scripts` WHERE `entryorguid`=61823 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61823, 0, 0, 0, '', 11, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 32783, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'High Sorceress Aryna - On Spawn - Self: Cast spell 32783 on Self');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (120064, 119405, 119298);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 120064, 0, 1, 51, 0, 5, 61659, 0, '', 0, 0, 0, '', 'Spell \'Eat Trog\' can only hit \'Slain Trogg\''),
(13, 1, 119405, 0, 1, 51, 0, 5, 61409, 0, '', 0, 0, 0, '', 'Spell \'Inferno Charge\' can only hit \'Demonic Leap\''),
(13, 1, 119298, 0, 1, 51, 0, 5, 61409, 0, '', 0, 0, 0, '', 'Spell \'Inferno Charge\' can only hit \'Demonic Leap\'');

-- Waypoints for CGUID+5
SET @ENTRY := 61560;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Lava trigger - Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -98.95594, -50.45018, -33.71426, 1.6434122, 6495),
(@PATH, 1, -98.95594, -50.45018, -30.71426, 1.6434122, 8074);

UPDATE `creature` SET `position_x`= -98.95594, `position_y`= -50.45018, `position_z`= -33.71426, `orientation`= 1.6434122, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+5, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '119436'); -- Lava - 119436 - Raise Lava (Splash)

-- Waypoints for CGUID+51
SET @ENTRY := 61601;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Lava - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -276.3968, 11.52049, -45.29239, NULL, 7282),
(@PATH, 1, -276.3968, 11.52049, -49.29239, NULL, 4481);

UPDATE `creature` SET `position_x`= -276.3968, `position_y`= 11.52049, `position_z`= -45.29239, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+51;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+51;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+51, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '119896'); -- Lava - 119896 - Raise Lava (Splash)

-- Waypoints for CGUID+4
SET @ENTRY := 61658;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Mature Flame Hound - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -78.4044, -34.64462, -19.77855, NULL, 11915),
(@PATH, 1, -83.74062, -33.94158, -21.59258, NULL, 0),
(@PATH, 2, -95.00292, -34.22608, -27.88643, NULL, 15513),
(@PATH, 3, -78.4044, -34.64462, -19.77855, NULL, 0);

UPDATE `creature` SET `position_x`= -78.4044, `position_y`= -34.64462, `position_z`= -19.77855, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+4;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+4, @PATH, 1);

-- Waypoints for CGUID+87
DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+87;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+87, @CGUID+87, 0, 0, 515, 1, 0),
(@CGUID+87, @CGUID+70, 4, 45, 515, 1, 0),
(@CGUID+87, @CGUID+41, 4, 315, 515, 1, 0);

SET @ENTRY := 61666;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Corrupted Houndmaster - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -202.6897, -35.12362, -49.1017, NULL, 0),
(@PATH, 1, -189.0811, -32.44863, -45.24224, NULL, 0),
(@PATH, 2, -179.2873, -31.2225, -44.20398, NULL, 282),
(@PATH, 3, -189.0811, -32.44863, -45.24224, NULL, 0),
(@PATH, 4, -202.6897, -35.12362, -49.1017, NULL, 0),
(@PATH, 5, -216.9245, -37.40353, -53.99065, NULL, 276);

UPDATE `creature` SET `position_x`= -202.6897, `position_y`= -35.12362, `position_z`= -49.1017, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+87;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+87;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+87, @PATH, 1);

-- Waypoints for CGUID+34
DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+34;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+34, @CGUID+34, 0, 0, 515, 1, 5),
(@CGUID+34, @CGUID+21, 6, 90, 515, 1, 5);

SET @ENTRY := 61678;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Corrupted Reaver - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -167.9434, 11.88338, -29.58279, NULL, 0),
(@PATH, 1, -176.2875, 11.19989, -31.5366, NULL, 0),
(@PATH, 2, -167.9434, 11.88338, -29.58279, NULL, 0),
(@PATH, 3, -156.9619, 11.19344, -25.92064, NULL, 0),
(@PATH, 4, -146.3743, 8.363324, -22.36292, NULL, 0),
(@PATH, 5, -140.1916, 7.301822, -21.20467, NULL, 2),
(@PATH, 6, -146.3743, 8.363324, -22.36292, NULL, 0),
(@PATH, 7, -156.9619, 11.19344, -25.92064, NULL, 0);

UPDATE `creature` SET `position_x`= -167.9434, `position_y`= 11.88338, `position_z`= -29.58279, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+34;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+34;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+34, @PATH, 1);

-- Waypoints for CGUID+43
SET @ENTRY := 61678;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Corrupted Reaver - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -286.815, 9.523731, -46.22304, NULL, 0),
(@PATH, 1, -295.8708, 4.275546, -47.43079, NULL, 0),
(@PATH, 2, -301.8253, 0.9729784, -48.87049, NULL, 0),
(@PATH, 3, -304.7638, -12.84443, -55.02773, NULL, 0),
(@PATH, 4, -301.8253, 0.9729784, -48.87049, NULL, 0),
(@PATH, 5, -295.8708, 4.275546, -47.43079, NULL, 0),
(@PATH, 6, -290.5378, 7.368289, -46.62738, NULL, 0);

UPDATE `creature` SET `position_x`= -286.815, `position_y`= 9.523731, `position_z`= -46.22304, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+43;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+43;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+43, @PATH, 1);

-- Waypoints for CGUID+92
DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+92;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+92, @CGUID+92, 0, 0, 515, 3, 0),
(@CGUID+92, @CGUID+75, 4, 90, 515, 3, 0);

SET @ENTRY := 61672;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Dark Shaman Acolyte - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -195.6893, 6.817014, -34.50617, NULL, 0),
(@PATH, 1, -206.778, 5.820297, -38.56978, NULL, 0),
(@PATH, 2, -217.1026, 6.294598, -41.97107, NULL, 0),
(@PATH, 3, -225.0182, 5.807473, -43.71304, NULL, 0),
(@PATH, 4, -217.1026, 6.294598, -41.97107, NULL, 0),
(@PATH, 5, -206.8081, 5.82168, -38.59869, NULL, 0);

UPDATE `creature` SET `position_x`= -195.6893, `position_y`= 6.817014, `position_z`= -34.50617, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+92;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+92;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+92, @PATH, 1);

-- Waypoints for CGUID+107
DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+107;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+107, @CGUID+107, 0, 0, 515, 4, 0),
(@CGUID+107, @CGUID+105, 4, 50, 515, 4, 0),
(@CGUID+107, @CGUID+106, 4, 310, 515, 4, 0);

SET @ENTRY := 61678;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Corrupted Reaver - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -285.7378, 206.6325, -25.65966, NULL, 0),
(@PATH, 1, -297.6342, 217.6831, -25.5011, NULL, 0),
(@PATH, 2, -305.792, 221.8851, -24.65573, NULL, 0),
(@PATH, 3, -314.3361, 223.61, -22.53464, NULL, 0),
(@PATH, 4, -323.7476, 222.8282, -21.03048, NULL, 0),
(@PATH, 5, -314.3361, 223.61, -22.53464, NULL, 0),
(@PATH, 6, -305.792, 221.8851, -24.65573, NULL, 0),
(@PATH, 7, -297.6342, 217.6831, -25.5011, NULL, 0);

UPDATE `creature` SET `position_x`= -285.7378, `position_y`= 206.6325, `position_z`= -25.65966, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+107;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+107;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+107, @PATH, 1);

-- Waypoints for CGUID+96
DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+96;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+96, @CGUID+96, 0, 0, 515, 1, 4),
(@CGUID+96, @CGUID+66, 4, 50, 515, 1, 4),
(@CGUID+96, @CGUID+79, 4, 310, 515, 1, 4);

SET @ENTRY := 61678;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Corrupted Reaver - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -183.8714, 77.94512, -22.27524, NULL, 0),
(@PATH, 1, -174.4853, 76.08389, -21.82619, NULL, 0),
(@PATH, 2, -183.8714, 77.94512, -22.27524, NULL, 0),
(@PATH, 3, -197.3098, 85.43606, -24.40988, NULL, 0),
(@PATH, 4, -209.0257, 97.08672, -25.40297, NULL, 0),
(@PATH, 5, -197.3098, 85.43606, -24.40988, NULL, 0);

UPDATE `creature` SET `position_x`= -183.8714, `position_y`= 77.94512, `position_z`= -22.27524, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+96;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+96;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+96, @PATH, 1);
