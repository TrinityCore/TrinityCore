SET @CGUID := 10004756;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+143;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1239.8228759765625, -2841.494873046875, 57.04843521118164062, 4.257831096649169921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+1, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1167.87158203125, -2719.072998046875, 51.10944747924804687, 1.706510066986083984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+2, 212702, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1186.7117919921875, -2697.694580078125, 51.795166015625, 4.524261951446533203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Mycotic Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+3, 222736, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1146.921875, -2730.33154296875, 52.37296676635742187, 0, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Subterranean Dartswog (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1166.6163330078125, -2793.217041015625, 55.9013824462890625, 0.703969895839691162, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+5, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1171.295166015625, -2719.647705078125, 52.18393707275390625, 2.45048689842224121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+6, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1176.1285400390625, -2711.795166015625, 52.45928573608398437, 4.171092510223388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+7, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1169.9722900390625, -2716.427001953125, 51.10944747924804687, 5.220950603485107421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+8, 212702, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1148.0242919921875, -2700.376708984375, 51.49885177612304687, 5.729362964630126953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Mycotic Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+9, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1420.095458984375, -2919.208251953125, 54.80518722534179687, 2.659436941146850585, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+10, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1190.935791015625, -2983.73779296875, 64.68753814697265625, 1.983599781990051269, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+11, 217648, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1214.07470703125, -3009.09375, 63.5645751953125, 0.143497511744499206, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 258096 - Submerged)
(@CGUID+12, 217719, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1284.3316650390625, -3003.911376953125, 67.72381591796875, 2.958301067352294921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Murmuring Trapcap (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+13, 222182, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1199.8211669921875, -3060.59375, 53.8375396728515625, 2.662606239318847656, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Basin Ferret (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+14, 212702, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1139.736083984375, -2705.984375, 51.666534423828125, 5.729362964630126953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Mycotic Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+15, 212704, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1173.5086669921875, -2745.944580078125, 51.581817626953125, 2.994345426559448242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Mycotic Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+16, 222875, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1256.5035400390625, -2820.25341796875, 58.8545379638671875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Meek Bloodlasher (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+17, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1244.38720703125, -2729.46533203125, 57.078125, 3.773160219192504882, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+18, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1239.1163330078125, -2732.796875, 56.70436477661132812, 0.733746707439422607, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+19, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1239.65625, -2728.786376953125, 56.89342880249023437, 5.27411508560180664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+20, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1243.3629150390625, -2734.24658203125, 56.934844970703125, 2.595615863800048828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+21, 217648, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1294.71533203125, -2770.53466796875, 63.37302398681640625, 2.90033578872680664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 258096 - Submerged)
(@CGUID+22, 217719, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1230.8629150390625, -2733.4306640625, 63.84696197509765625, 4.087262630462646484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Murmuring Trapcap (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+23, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1256.2447509765625, -2814.7119140625, 59.40597152709960937, 4.480247020721435546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+24, 217648, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1280.9566650390625, -2750.302001953125, 60.34749984741210937, 5.347936153411865234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 258096 - Submerged)
(@CGUID+25, 217648, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1227.953125, -2773.94970703125, 57.103759765625, 2.253621339797973632, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 258096 - Submerged)
(@CGUID+26, 217786, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1237.38720703125, -2741.536376953125, 56.67256546020507812, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Frightfilled Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+27, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1202.4149169921875, -2775.694580078125, 56.23784637451171875, 0.733746707439422607, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+28, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1207.685791015625, -2772.361083984375, 54.78513336181640625, 3.773160219192504882, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+29, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1202.953125, -2771.68408203125, 55.20507049560546875, 5.27411508560180664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+30, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1206.6614990234375, -2777.142333984375, 56.32291412353515625, 2.595615863800048828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+31, 212704, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1309.84375, -2801.407958984375, 62.97132110595703125, 3.102633953094482421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Mycotic Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+32, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1284.2864990234375, -2814.69970703125, 59.30193328857421875, 5.818171977996826171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+33, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1260.204833984375, -2783.5, 59.62102508544921875, 1.67141270637512207, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+34, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1301.875, -2729.70654296875, 73.6922760009765625, 5.149139881134033203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+35, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1291.8021240234375, -2818.682373046875, 61.18476486206054687, 2.627605199813842773, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+36, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1232.8316650390625, -2807.59716796875, 57.4600677490234375, 1.49635779857635498, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+37, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1230.5711669921875, -2804.236083984375, 57.1788177490234375, 0.477525025606155395, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+38, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1236.0504150390625, -2803.885498046875, 55.88898468017578125, 2.805752992630004882, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+39, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1234.560791015625, -2801.607666015625, 56.65972137451171875, 3.889036417007446289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+40, 217786, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1282.01220703125, -2760.782958984375, 59.377685546875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Frightfilled Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+41, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1283.9461669921875, -2721.210205078125, 67.0956268310546875, 3.76311492919921875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+42, 222754, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1423.9288330078125, -2910.84033203125, 61.88177490234375, 4.006092071533203125, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Fallowspark Glowfly (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+43, 212704, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1343.435791015625, -2908.58154296875, 51.58687210083007812, 2.994345426559448242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Mycotic Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+44, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1387.501708984375, -2872.413330078125, 54.93228912353515625, 5.656238079071044921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+45, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1386.3385009765625, -2875.083251953125, 53.9017791748046875, 0.339780181646347045, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+46, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1336.49658203125, -2856.6875, 56.42724609375, 0.249870553612709045, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+47, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1434.5660400390625, -2896.239501953125, 61.88034439086914062, 2.975973844528198242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+48, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1430.375, -2894.791748046875, 60.87384796142578125, 6.219745635986328125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+49, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1433.2222900390625, -2893.46533203125, 61.69904327392578125, 4.47692728042602539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+50, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1431.9617919921875, -2897.767333984375, 61.20425796508789062, 1.798431038856506347, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+51, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1306.717041015625, -2833.15625, 62.78596115112304687, 4.667924404144287109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+52, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1375.986083984375, -2900.5, 51.64350128173828125, 4.222446441650390625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+53, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1341.1492919921875, -2778.897705078125, 79.88239288330078125, 3.788589000701904296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+54, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1325.2691650390625, -2772.2900390625, 71.0123291015625, 2.858417749404907226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+55, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1325.4010009765625, -2768.5, 71.4464874267578125, 3.75092172622680664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+56, 212701, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1418.6597900390625, -2837.0712890625, 67.93359375, 2.298696756362915039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Elder Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+57, 217648, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1254.435791015625, -2871.276123046875, 59.32584381103515625, 5.99341583251953125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 258096 - Submerged)
(@CGUID+58, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1292.91845703125, -2854.4462890625, 59.30435562133789062, 1.271166682243347167, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+59, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1247.782958984375, -2846.6025390625, 57.08385467529296875, 4.257831096649169921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+60, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1276.9444580078125, -2841.338623046875, 60.04265594482421875, 5.177037239074707031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+61, 222182, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1216.8004150390625, -3047.65625, 56.31250762939453125, 1.802324175834655761, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Basin Ferret (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+62, 217755, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1150.267333984375, -2859.779541015625, 61.24078369140625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Explosive Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+63, 222613, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1289.5538330078125, -2849.94970703125, 64.91119384765625, 0, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Fallowspark Glowfly (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+64, 217755, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1193.0399169921875, -2938.171875, 64.0301971435546875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Explosive Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+65, 217762, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1236.060791015625, -2841.439208984375, 57.68088150024414062, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Toxic Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+66, 212704, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1143.15625, -2814.322998046875, 58.6951141357421875, 1.341232061386108398, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Mycotic Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+67, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1205.3819580078125, -2801.5, 55.14727783203125, 5.519799232482910156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+68, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1125.0399169921875, -2824.451416015625, 62.96900558471679687, 5.791490554809570312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+69, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1203.37158203125, -2869.001708984375, 63.7287445068359375, 3.84857344627380371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+70, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1134.8802490234375, -2863.092041015625, 60.79780197143554687, 1.798927903175354003, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+71, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1131.3663330078125, -2848.75, 62.469482421875, 4.965372085571289062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+72, 217755, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1169.345458984375, -2806.532958984375, 56.32537841796875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Explosive Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+73, 217648, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1209.7135009765625, -2847.78466796875, 61.45867156982421875, 2.581925153732299804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 258096 - Submerged)
(@CGUID+74, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1162.21533203125, -2878.8212890625, 62.02247238159179687, 4.999767303466796875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+75, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1203.0052490234375, -2806.491455078125, 55.1430206298828125, 1.231681585311889648, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+76, 217762, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1165.767333984375, -2811.71875, 57.90987014770507812, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Toxic Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+77, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1164.154541015625, -2810.7587890625, 58.29166412353515625, 5.887297630310058593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+78, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1166.82470703125, -2809.87158203125, 57.2162322998046875, 4.397244930267333984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+79, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1165.6163330078125, -2813.803955078125, 58.15798568725585937, 1.499893903732299804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+80, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1167.8975830078125, -2812.770751953125, 57.44612503051757812, 2.967411279678344726, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+81, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1179.2413330078125, -2883.08154296875, 66.26263427734375, 4.954971790313720703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+82, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1157.796875, -2853.15625, 59.86511993408203125, 0.807469367980957031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+83, 217755, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1176.0850830078125, -2863.46533203125, 61.23463821411132812, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Explosive Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+84, 217648, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1220.1336669921875, -2878.022705078125, 63.30936050415039062, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 258096 - Submerged)
(@CGUID+85, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1164.15625, -2789.282958984375, 55.42000961303710937, 4.033303260803222656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+86, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1103.09375, -2849.194580078125, 64.73477935791015625, 4.388986587524414062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+87, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1166.6163330078125, -2793.217041015625, 55.9013824462890625, 0.703969895839691162, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+88, 212702, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1113.7396240234375, -2856.882080078125, 66.07952880859375, 4.560435771942138671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Mycotic Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+89, 217670, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1174.66845703125, -2848.536376953125, 57.4674530029296875, 5.974049568176269531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Rotbark the Unfelled (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 435239 - Rot Frenzy)
(@CGUID+90, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1294.0728759765625, -2899.116455078125, 55.95810699462890625, 2.023295164108276367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+91, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1294.3524169921875, -2894.435791015625, 56.2376861572265625, 5.179575443267822265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+92, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1232.1353759765625, -2922.59033203125, 61.56177902221679687, 0.875000715255737304, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+93, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1258.9478759765625, -2940.7275390625, 56.9693756103515625, 0.374469727277755737, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+94, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1265.4896240234375, -2937.37841796875, 57.35542678833007812, 4.67316293716430664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+95, 217786, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1256.8333740234375, -2970.45654296875, 57.74687957763671875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Frightfilled Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+96, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1238.545166015625, -2966.473876953125, 58.0879974365234375, 3.581763029098510742, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+97, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1242.8524169921875, -2962.119873046875, 57.58303451538085937, 4.257831096649169921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+98, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1309.5538330078125, -2947.40283203125, 55.85774612426757812, 5.46673440933227539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+99, 217648, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1311.4478759765625, -2951.03466796875, 56.79969024658203125, 1.891943216323852539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 258096 - Submerged)
(@CGUID+100, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1118.592041015625, -2786.045166015625, 61.2765960693359375, 0.661073803901672363, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+101, 218208, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1273.8125, -2768.4775390625, 60.70111846923828125, 0.218211978673934936, 120, 0, 0, 0, NULL, 33536, 2049, 2214600704, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject1
(@CGUID+102, 218208, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1176.373291015625, -2865.50341796875, 61.77138900756835937, 1.330514192581176757, 120, 0, 0, 0, NULL, 33536, 2049, 2214600704, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject1
(@CGUID+103, 220617, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1158.0260009765625, -2793.9462890625, 60.06580352783203125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- [DNT] Spell Target Bunny (Area: Boskroot Basin - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+104, 220617, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1258.44970703125, -2777.178955078125, 63.46347427368164062, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- [DNT] Spell Target Bunny (Area: Boskroot Basin - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+105, 220617, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1233.670166015625, -2849.479248046875, 58.71561050415039062, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- [DNT] Spell Target Bunny (Area: Boskroot Basin - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+106, 220617, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1243.359375, -2852.140625, 59.14216232299804687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- [DNT] Spell Target Bunny (Area: Boskroot Basin - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+107, 220617, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1295.0504150390625, -2847.67529296875, 59.14777755737304687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- [DNT] Spell Target Bunny (Area: Boskroot Basin - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+108, 220617, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1344.001708984375, -2857.46533203125, 57.0793914794921875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- [DNT] Spell Target Bunny (Area: Boskroot Basin - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+109, 218208, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1264.2725830078125, -2945.720458984375, 57.04334259033203125, 1.431133747100830078, 120, 0, 0, 0, NULL, 33536, 2049, 2214600704, 57689), -- Boskroot Lashbane (Area: Boskroot Basin - Difficulty: 0) CreateObject1
(@CGUID+110, 220617, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1365.7603759765625, -2905.84716796875, 55.17882919311523437, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- [DNT] Spell Target Bunny (Area: Boskroot Basin - Difficulty: 0) CreateObject1
(@CGUID+111, 220617, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1371.6754150390625, -2909.001708984375, 58.10681915283203125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- [DNT] Spell Target Bunny (Area: Boskroot Basin - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+112, 220617, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1369.329833984375, -2915.654541015625, 59.86534881591796875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- [DNT] Spell Target Bunny (Area: Boskroot Basin - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+113, 220617, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1264.3021240234375, -2945.7587890625, 55.77312088012695312, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- [DNT] Spell Target Bunny (Area: Boskroot Basin - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+114, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1365.3333740234375, -2931.288330078125, 51.51715850830078125, 4.851099014282226562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+115, 212702, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1374.6441650390625, -2997.875, 59.36910629272460937, 1.638732433319091796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Mycotic Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+116, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1350.6597900390625, -3006.380126953125, 58.42831802368164062, 3.321513652801513671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+117, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1370.2396240234375, -2928.1650390625, 52.03076171875, 1.60898447036743164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+118, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1352.4930419921875, -3012.366455078125, 59.06040191650390625, 1.231681585311889648, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+119, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1351.092041015625, -2988.772705078125, 57.5641326904296875, 0.919037699699401855, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+120, 213099, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1331.15625, -2943.388916015625, 52.62958526611328125, 5.506109237670898437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+121, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1320.4288330078125, -2979.282958984375, 57.644287109375, 0.41055077314376831, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+122, 212698, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1322.8211669921875, -2977.63720703125, 57.6475677490234375, 3.926585912704467773, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Mycomancer (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+123, 217755, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1203.9305419921875, -2958.87841796875, 61.32225799560546875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Explosive Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+124, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1282.9375, -2954.39404296875, 58.03693771362304687, 0.821037650108337402, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+125, 212701, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1336.4271240234375, -3032.342041015625, 64.860809326171875, 0.001635180902667343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Elder Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+126, 217762, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1330.7413330078125, -2980.328125, 56.186279296875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Toxic Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+127, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1312.001708984375, -3006.666748046875, 58.4932708740234375, 6.221838951110839843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+128, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1323.4444580078125, -3005.23095703125, 59.3403778076171875, 3.443812131881713867, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+129, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1311.3697509765625, -3012.744873046875, 59.58391571044921875, 0.73434537649154663, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+130, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1324.1910400390625, -3008.729248046875, 59.49477005004882812, 2.88323831558227539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+131, 217762, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1255.2899169921875, -3006.130126953125, 59.4122161865234375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Toxic Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+132, 212697, 2552, 14717, 14777, '0', 0, 0, 0, 1, 1230.185791015625, -3019.875, 61.26647186279296875, 2.500542640686035156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Guardener (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+133, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1252.3038330078125, -3006.6806640625, 59.70659637451171875, 0.333793163299560546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+134, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1256.7135009765625, -3008.335205078125, 58.89893722534179687, 2.022196769714355468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+135, 212766, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1255.5972900390625, -3003.927001953125, 59.640625, 4.210222244262695312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Boskroot Button (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+136, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1272.2447509765625, -3028.861083984375, 54.31548309326171875, 0.663182497024536132, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+137, 222182, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1255.359375, -3036.03125, 54.73421859741210937, 0.801971256732940673, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Basin Ferret (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+138, 217719, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1272.1510009765625, -2969.06591796875, 67.87097930908203125, 2.617185831069946289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Murmuring Trapcap (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+139, 222182, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1210.9166259765625, -2994.861083984375, 61.60638427734375, 0.611436069011688232, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Basin Ferret (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+140, 217786, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1334.1771240234375, -3013.78466796875, 59.79359817504882812, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Frightfilled Mineshroom (Area: Boskroot Basin - Difficulty: 0) CreateObject2
(@CGUID+141, 212704, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1207.3646240234375, -2967.489501953125, 60.21010208129882812, 2.145387649536132812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Mycotic Shalehorn (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+142, 212710, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1314.6163330078125, -3017.8837890625, 59.96353912353515625, 4.082981586456298828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Infected Peafowl (Area: Boskroot Basin - Difficulty: 0) CreateObject2 (Auras: 427172 - Fungal Infected)
(@CGUID+143, 222877, 2552, 14717, 14777, '0', 0, 0, 0, 0, 1229.0572509765625, -2947.791748046875, 60.59115982055664062, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Ghostcap Menace (Area: Boskroot Basin - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+143;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 423, 0, 0, 0, 0, '427172'), -- Mycotic Shalehorn - 427172 - Fungal Infected
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 423, 0, 0, 0, 0, '427172'), -- Mycotic Shalehorn - 427172 - Fungal Infected
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '427172'), -- Infected Peafowl - 427172 - Fungal Infected
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 423, 0, 0, 0, 0, '427172'), -- Mycotic Shalehorn - 427172 - Fungal Infected
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 423, 0, 0, 0, 0, '427172'), -- Mycotic Shalehorn - 427172 - Fungal Infected
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, '123169'), -- Boskroot Guardener - 123169 - Mod Scale 105-110%
(@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, '123169'), -- Boskroot Guardener - 123169 - Mod Scale 105-110%
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '427172'), -- Infected Peafowl - 427172 - Fungal Infected
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '427172'), -- Infected Peafowl - 427172 - Fungal Infected
(@CGUID+55, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '427172'), -- Infected Peafowl - 427172 - Fungal Infected
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '427172'), -- Infected Peafowl - 427172 - Fungal Infected
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, '123169'), -- Boskroot Guardener - 123169 - Mod Scale 105-110%
(@CGUID+92, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, '123169'), -- Boskroot Guardener - 123169 - Mod Scale 105-110%
(@CGUID+96, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '427172'), -- Infected Peafowl - 427172 - Fungal Infected
(@CGUID+113, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Boskroot Mycomancer - 123169 - Mod Scale 105-110%
(@CGUID+114, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427172'), -- Mycotic Shalehorn - 427172 - Fungal Infected
(@CGUID+125, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427172'), -- Elder Shalehorn - 427172 - Fungal Infected
(@CGUID+136, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '427172'), -- Infected Peafowl - 427172 - Fungal Infected
(@CGUID+142, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '427172'); -- Infected Peafowl - 427172 - Fungal Infected

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (213099,222754,222613,212701,217670,212697,225270,218219,220617,217719,217648,218208,212704,212698,212766,212736,212702,212710);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(213099, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- 213099 (Boskroot Mycomancer) - Mod Scale 105-110%
(222754, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222754 (Fallowspark Glowfly)
(222613, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222613 (Fallowspark Glowfly)
(212701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427172'), -- 212701 (Elder Shalehorn) - Fungal Infected
(217670, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '435239 442266'), -- 217670 (Rotbark the Unfelled) - Rot Frenzy, Mineshroom Eruption
(212697, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- 212697 (Boskroot Guardener) - Mod Scale 105-110%
(225270, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 225270 (Crested Shalehorn)
(218219, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 218219 (Long-Forgotten Earthen)
(220617, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 220617 ([DNT] Spell Target Bunny)
(217719, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 217719 (Murmuring Trapcap)
(217648, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '258096 135252'), -- 217648 (Boskroot Lashbane) - Submerged, Spawn Feign Death
(218208, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 218208 (Boskroot Lashbane)
(212704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427172'), -- 212704 (Mycotic Shalehorn) - Fungal Infected
(212698, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- 212698 (Boskroot Mycomancer) - Mod Scale 105-110%
(212766, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- 212766 (Boskroot Button) - Mod Scale 105-110%
(212736, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 212736 (Boskroot Brute)
(212702, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427172'), -- 212702 (Mycotic Shalehorn) - Fungal Infected
(212710, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427172'); -- 212710 (Infected Peafowl) - Fungal Infected

-- Template
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry` IN (213099, 212698); -- Boskroot Mycomancer
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=222754; -- Fallowspark Glowfly
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=222613; -- Fallowspark Glowfly
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=212701; -- Elder Shalehorn
UPDATE `creature_template` SET `faction`=190, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=222736; -- Subterranean Dartswog
UPDATE `creature_template` SET `BaseAttackTime`=2000 WHERE `entry`=217670; -- Rotbark the Unfelled
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=212697; -- Boskroot Guardener
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=225268; -- Plainswalker Shalehorn
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x80000000 WHERE `entry`=218219; -- Long-Forgotten Earthen
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x800, `unit_flags3`=0x1000001, `flags_extra` = 128 WHERE `entry`=220617; -- [DNT] Spell Target Bunny
UPDATE `creature_template` SET `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=217719; -- Murmuring Trapcap
UPDATE `creature_template` SET `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41000000 WHERE `entry`=217786; -- Frightfilled Mineshroom
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x14000000 WHERE `entry`=219267; -- Plaguehart
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=217648; -- Boskroot Lashbane
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=222877; -- Ghostcap Menace
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800, `unit_flags3`=0x80000000 WHERE `entry`=218208; -- Boskroot Lashbane
UPDATE `creature_template` SET `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41000000 WHERE `entry`=217762; -- Toxic Mineshroom
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=212766; -- Boskroot Button
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=212702; -- Mycotic Shalehorn
UPDATE `creature_template` SET `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41080000 WHERE `entry`=217755; -- Explosive Mineshroom
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=212710; -- Infected Peafowl
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=222875; -- Meek Bloodlasher

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=213099 AND `DifficultyID`=0); -- 213099 (Boskroot Mycomancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x30000000, `VerifiedBuild`=57689 WHERE (`Entry`=222754 AND `DifficultyID`=0); -- 222754 (Fallowspark Glowfly) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x30000000, `VerifiedBuild`=57689 WHERE (`Entry`=222613 AND `DifficultyID`=0); -- 222613 (Fallowspark Glowfly) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=212701 AND `DifficultyID`=0); -- 212701 (Elder Shalehorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222736 AND `DifficultyID`=0); -- 222736 (Subterranean Dartswog) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=217670 AND `DifficultyID`=0); -- 217670 (Rotbark the Unfelled) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=212697 AND `DifficultyID`=0); -- 212697 (Boskroot Guardener) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=225268 AND `DifficultyID`=0); -- 225268 (Plainswalker Shalehorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=218219 AND `DifficultyID`=0); -- 218219 (Long-Forgotten Earthen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x20000000, `VerifiedBuild`=57689 WHERE (`Entry`=220617 AND `DifficultyID`=0); -- 220617 ([DNT] Spell Target Bunny) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=57689 WHERE (`Entry`=217719 AND `DifficultyID`=0); -- 217719 (Murmuring Trapcap) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x20000100, `VerifiedBuild`=57689 WHERE (`Entry`=217786 AND `DifficultyID`=0); -- 217786 (Frightfilled Mineshroom) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2860, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=219267 AND `DifficultyID`=0); -- 219267 (Plaguehart) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000100, `VerifiedBuild`=57689 WHERE (`Entry`=217648 AND `DifficultyID`=0); -- 217648 (Boskroot Lashbane) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222877 AND `DifficultyID`=0); -- 222877 (Ghostcap Menace) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=218208 AND `DifficultyID`=0); -- 218208 (Boskroot Lashbane) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x20000100, `VerifiedBuild`=57689 WHERE (`Entry`=217762 AND `DifficultyID`=0); -- 217762 (Toxic Mineshroom) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=212698 AND `DifficultyID`=0); -- 212698 (Boskroot Mycomancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=212766 AND `DifficultyID`=0); -- 212766 (Boskroot Button) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=212702 AND `DifficultyID`=0); -- 212702 (Mycotic Shalehorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x20000100, `VerifiedBuild`=57689 WHERE (`Entry`=217755 AND `DifficultyID`=0); -- 217755 (Explosive Mineshroom) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=212710 AND `DifficultyID`=0); -- 212710 (Infected Peafowl) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=225311 AND `DifficultyID`=0); -- 225311 (Plainswalker Shalehorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=212700 AND `DifficultyID`=0); -- 212700 (Woldtender Igris) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=57689 WHERE (`Entry`=213199 AND `DifficultyID`=0); -- 213199 (Woldkeeper Freydrin) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222875 AND `DifficultyID`=0); -- 222875 (Meek Bloodlasher) - CanSwim

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 212704;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(212704, 46598, 1, 0);

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=212704 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(212704, 212736, 0, 0, 'Mycotic Shalehorn - Boskroot Brute', 8, 0); -- Mycotic Shalehorn - Boskroot Brute

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=117607;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(117607, 0.347000002861022949, 1.5, 0, 57689);

-- Boskroot Mycomancer smart ai
SET @ENTRY := 212698;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 5000, 8000, 14000, 0, 11, 442146, 0, 0, 0, 0, 0, 0, 19, 220617, 20, 0, 0, 0, 0, 0, 'Every 8 - 14 seconds (1 - 5s initially) (OOC) - Self: Cast spell  442146 on Closest alive creature  Spell Target Bunny (220617) in 10 yards', ''),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 1000, 5000, 8000, 14000, 0, 11, 442146, 0, 0, 0, 0, 0, 0, 19, 212710, 20, 0, 0, 0, 0, 0, 'Every 8 - 14 seconds (1 - 5s initially) (OOC) - Self: Cast spell  442146 on Closest alive creature  Infested Peafowl (212710) in 10 yards', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` IN (1,2) AND `SourceEntry` = @ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, @ENTRY, 0, 0, 58, 1, 0, 0, 0, 'ChannelSpellTargetBunny', 0, 'Scripted creature has StringId ''ChannelSpellTargetBunny'''),
(22, 2, @ENTRY, 0, 0, 58, 1, 0, 0, 0, 'ChannelInfectedPeafowl', 0, 'Scripted creature has StringId ''ChannelInfectedPeafowl''');

UPDATE `creature` SET `StringId`='ChannelSpellTargetBunny' WHERE `guid` IN (@CGUID+117, @CGUID+52, @CGUID+46, @CGUID+58, @CGUID+59, @CGUID+33, @CGUID+85, @CGUID+0);
UPDATE `creature` SET `StringId`='ChannelInfectedPeafowl' WHERE `guid` IN (@CGUID+75, @CGUID+97, @CGUID+118);

-- Path for Rotbark the Unfelled
SET @MOVERGUID := @CGUID+89;
SET @ENTRY := 217670;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Rotbark the Unfelled - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1193.0365, -2868.9949, 61.795208, NULL, 0),
(@PATH, 1, 1202.2361, -2892.2656, 63.90406, NULL, 0),
(@PATH, 2, 1213.0555, -2904.191, 61.381676, NULL, 0),
(@PATH, 3, 1248.1598, -2906.9827, 57.80954, NULL, 0),
(@PATH, 4, 1268.7639, -2922.809, 58.317223, NULL, 0),
(@PATH, 5, 1277.6841, -2935.2222, 57.83355, NULL, 0),
(@PATH, 6, 1292.2673, -2962.9878, 56.524967, NULL, 0),
(@PATH, 7, 1297.5348, -2976.8994, 54.89545, NULL, 0),
(@PATH, 8, 1311.7379, -2984.7065, 56.278366, NULL, 0),
(@PATH, 9, 1341.6598, -2976.106, 54.663918, NULL, 0),
(@PATH, 10, 1355.1598, -2979.007, 55.497063, NULL, 0),
(@PATH, 11, 1364.9254, -2994.823, 56.612473, NULL, 0),
(@PATH, 12, 1366.6702, -3003.9827, 59.621742, NULL, 0),
(@PATH, 13, 1353.632, -3016.9844, 58.93936, NULL, 0),
(@PATH, 14, 1325.6771, -3017.3247, 59.90291, NULL, 0),
(@PATH, 15, 1315.7882, -3028.967, 58.33902, NULL, 0),
(@PATH, 16, 1304.6805, -3046.9653, 53.388462, NULL, 0),
(@PATH, 17, 1287.2535, -3052.217, 51.589058, NULL, 0),
(@PATH, 18, 1273.1685, -3045.4775, 53.878426, NULL, 0),
(@PATH, 19, 1261.7709, -3031.7588, 54.59417, NULL, 0),
(@PATH, 20, 1257.5049, -3011.211, 58.220943, NULL, 0),
(@PATH, 21, 1236.3663, -3002.087, 58.472683, NULL, 0),
(@PATH, 22, 1224.1493, -2992.1406, 59.746685, NULL, 0),
(@PATH, 23, 1215.3872, -2980.1145, 59.266647, NULL, 0),
(@PATH, 24, 1229.0642, -2963.7065, 58.67093, NULL, 0),
(@PATH, 25, 1243.0781, -2947.448, 57.182655, NULL, 0),
(@PATH, 26, 1248.7969, -2924.1504, 58.600277, NULL, 0),
(@PATH, 27, 1229.7969, -2899.8281, 59.979713, NULL, 0),
(@PATH, 28, 1205.5764, -2882.0713, 63.154667, NULL, 0),
(@PATH, 29, 1196.1233, -2861.269, 62.24581, NULL, 0),
(@PATH, 30, 1184.7778, -2838.7952, 57.829243, NULL, 0),
(@PATH, 31, 1179.1562, -2794.2883, 54.51288, NULL, 0),
(@PATH, 32, 1177.882, -2768.6301, 51.74694, NULL, 0),
(@PATH, 33, 1203.3021, -2760.7952, 53.22638, NULL, 0),
(@PATH, 34, 1234.1198, -2767.7449, 56.69653, NULL, 0),
(@PATH, 35, 1241.6041, -2791.9514, 56.561676, NULL, 0),
(@PATH, 36, 1249.1719, -2795.5747, 57.36889, NULL, 0),
(@PATH, 37, 1285.0087, -2790.5747, 61.186577, NULL, 0),
(@PATH, 38, 1286.481, -2769.059, 61.319267, NULL, 0),
(@PATH, 39, 1267.1598, -2755.4045, 58.941566, NULL, 0),
(@PATH, 40, 1250.7692, -2749.9775, 59.041653, NULL, 0),
(@PATH, 41, 1235.3942, -2760.9583, 57.47912, NULL, 0),
(@PATH, 42, 1240.1875, -2807.9202, 55.62447, NULL, 0),
(@PATH, 43, 1235.1111, -2815.6736, 58.10808, NULL, 0),
(@PATH, 44, 1221.2379, -2820.861, 58.8575, NULL, 0),
(@PATH, 45, 1200.0452, -2823.5713, 56.426582, NULL, 0),
(@PATH, 46, 1186.9757, -2833.4185, 57.35785, NULL, 0),
(@PATH, 47, 1172.8105, -2838.3691, 58.71023, NULL, 0),
(@PATH, 48, 1157.9584, -2843.9133, 58.548782, NULL, 0),
(@PATH, 49, 1152.1111, -2849.6685, 59.61781, NULL, 0),
(@PATH, 50, 1157.1129, -2855.889, 60.22108, NULL, 0),
(@PATH, 51, 1167.3959, -2861.5173, 60.280262, NULL, 0),
(@PATH, 52, 1175.2899, -2858.0017, 59.842644, NULL, 0),
(@PATH, 53, 1179.8733, -2850.9932, 58.11549, NULL, 0),
(@PATH, 54, 1175.5518, -2848.4746, 57.31778, NULL, 3667),
(@PATH, 55, 1179.8733, -2850.9932, 58.11549, NULL, 0),
(@PATH, 56, 1175.2899, -2858.0017, 59.842644, NULL, 0),
(@PATH, 57, 1167.3959, -2861.5173, 60.280262, NULL, 0),
(@PATH, 58, 1157.1129, -2855.889, 60.22108, NULL, 0),
(@PATH, 59, 1152.1111, -2849.6685, 59.61781, NULL, 0),
(@PATH, 60, 1157.9584, -2843.9133, 58.548782, NULL, 0),
(@PATH, 61, 1172.7084, -2838.3994, 58.635662, NULL, 0),
(@PATH, 62, 1186.873, -2833.4492, 57.39261, NULL, 0),
(@PATH, 63, 1200.0452, -2823.5713, 56.426582, NULL, 0),
(@PATH, 64, 1221.2379, -2820.861, 58.8575, NULL, 0),
(@PATH, 65, 1235.1111, -2815.6736, 58.10808, NULL, 0),
(@PATH, 66, 1240.1875, -2807.9202, 55.62447, NULL, 0),
(@PATH, 67, 1235.3942, -2760.9583, 57.47912, NULL, 0),
(@PATH, 68, 1250.7692, -2749.9775, 59.041653, NULL, 0),
(@PATH, 69, 1267.1598, -2755.4045, 58.941566, NULL, 0),
(@PATH, 70, 1286.481, -2769.059, 61.319267, NULL, 0),
(@PATH, 71, 1285.0087, -2790.5747, 61.186577, NULL, 0),
(@PATH, 72, 1249.1719, -2795.5747, 57.36889, NULL, 0),
(@PATH, 73, 1241.6041, -2791.9514, 56.561676, NULL, 0),
(@PATH, 74, 1234.1198, -2767.7449, 56.69653, NULL, 0),
(@PATH, 75, 1203.3021, -2760.7952, 53.22638, NULL, 0),
(@PATH, 76, 1177.882, -2768.6301, 51.74694, NULL, 0),
(@PATH, 77, 1179.1562, -2794.2883, 54.51288, NULL, 0),
(@PATH, 78, 1184.7778, -2838.7952, 57.829243, NULL, 0),
(@PATH, 79, 1196.1233, -2861.269, 62.24581, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '435239 442266');

-- Path for Mycotic Shalehorn
SET @MOVERGUID := @CGUID+66;
SET @ENTRY := 212704;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Mycotic Shalehorn - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1138.8184, -2790.3281, 55.69154, NULL, 0),
(@PATH, 1, 1145.356, -2784.2656, 54.671036, NULL, 0),
(@PATH, 2, 1151.0017, -2777.2275, 53.88556, NULL, 5770),
(@PATH, 3, 1138.8906, -2790.2449, 55.743187, NULL, 0),
(@PATH, 4, 1132.6768, -2796.748, 58.094482, NULL, 0),
(@PATH, 5, 1132.6875, -2804.7415, 58.88276, NULL, 0),
(@PATH, 6, 1143.2865, -2813.7656, 58.541843, NULL, 0),
(@PATH, 7, 1146.4305, -2815.4514, 58.64122, NULL, 7821),
(@PATH, 8, 1132.6875, -2804.7415, 58.88276, NULL, 0),
(@PATH, 9, 1132.6041, -2796.8315, 58.203, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '427172');

-- Path for Mycotic Shalehorn
SET @MOVERGUID := @CGUID+31;
SET @ENTRY := 212704;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Mycotic Shalehorn - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1290.7084, -2803.394, 59.59399, NULL, 0),
(@PATH, 1, 1288.9757, -2811.7744, 59.10456, NULL, 5331),
(@PATH, 2, 1290.7084, -2803.394, 59.59399, NULL, 0),
(@PATH, 3, 1298.5817, -2800.9739, 61.998363, NULL, 0),
(@PATH, 4, 1311.7118, -2801.3403, 63.065372, NULL, 6019),
(@PATH, 5, 1298.7119, -2800.9844, 61.990986, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '427172');

-- Path for Mycotic Shalehorn
SET @MOVERGUID := @CGUID+141;
SET @ENTRY := 212704;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Mycotic Shalehorn - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1222.9427, -2989.967, 59.57086, NULL, 0),
(@PATH, 1, 1228.7153, -2998.1736, 59.57307, NULL, 0),
(@PATH, 2, 1230.2743, -3000.5364, 59.375015, NULL, 6860),
(@PATH, 3, 1222.9427, -2989.967, 59.57086, NULL, 0),
(@PATH, 4, 1215.6337, -2977.7258, 59.187843, NULL, 0),
(@PATH, 5, 1206.4427, -2966.4792, 60.42137, NULL, 9427),
(@PATH, 6, 1215.6337, -2977.7258, 59.187843, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '427172');

-- Path for Boskroot Mycomancer
SET @MOVERGUID := @CGUID+120;
SET @ENTRY := 213099;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Boskroot Mycomancer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1375.0642, -2954.6753, 53.26848, NULL, 0),
(@PATH, 1, 1381.6632, -2954.658, 53.664833, NULL, 0),
(@PATH, 2, 1384.7291, -2955.2153, 53.839375, NULL, 4665),
(@PATH, 3, 1375.0642, -2954.6753, 53.26848, NULL, 0),
(@PATH, 4, 1356.3802, -2956.342, 52.449448, NULL, 0),
(@PATH, 5, 1343.4879, -2955.519, 52.239513, NULL, 0),
(@PATH, 6, 1330.0695, -2943.6511, 52.577374, NULL, 5447),
(@PATH, 7, 1343.4879, -2955.519, 52.239513, NULL, 0),
(@PATH, 8, 1356.3802, -2956.342, 52.449448, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '123169');

-- Path for Boskroot Guardener
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+44;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+44, @CGUID+44, 0, 0, 515, 0, 0),
(@CGUID+44, @CGUID+45, 3, 90, 515, 3, 8);

SET @MOVERGUID := @CGUID+44;
SET @ENTRY := 212697;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Boskroot Guardener - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1406.1285, -2890.1926, 53.309895, NULL, 0),
(@PATH, 1, 1409.6719, -2899.356, 52.510178, NULL, 0),
(@PATH, 2, 1410.5938, -2910.1702, 52.47042, NULL, 0),
(@PATH, 3, 1409.8281, -2918.462, 52.77205, NULL, 5594),
(@PATH, 4, 1410.5938, -2910.1702, 52.47042, NULL, 0),
(@PATH, 5, 1409.6719, -2899.356, 52.510178, NULL, 0),
(@PATH, 6, 1406.1285, -2890.1926, 53.309895, NULL, 0),
(@PATH, 7, 1398.5729, -2880.434, 53.1118, NULL, 0),
(@PATH, 8, 1387.3663, -2873.4045, 54.395424, NULL, 4457),
(@PATH, 9, 1398.5729, -2880.434, 53.1118, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '123169');
