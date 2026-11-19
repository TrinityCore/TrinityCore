SET @CGUID := 850720;
SET @OGUID := 502182;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+157;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 698.6932373046875, 1220.2138671875, 98.17423248291015625, 2.29954695701599121, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst) (possible waypoints or random movement)
(@CGUID+1, 130217, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 633.68597412109375, 1258.4639892578125, 98.60064697265625, 2.998783111572265625, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966), -- Nazmani Weevil (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+2, 131492, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 772.410888671875, 1205.466064453125, 70.90663909912109375, 6.11704111099243164, 7200, 0, 0, 70780, 1807, 0, 0, 0, 0, 48966), -- Devout Blood Priest (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+3, 133663, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 714.3819580078125, 1264.13720703125, 97.4490966796875, 5.071341991424560546, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fanatical Headhunter (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+4, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 674.4979248046875, 1263.2757568359375, 96.8077392578125, 5.072631359100341796, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst) (possible waypoints or random movement)
(@CGUID+5, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 677.646484375, 1269.3994140625, 97.423919677734375, 4.013452053070068359, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst) (possible waypoints or random movement)
(@CGUID+6, 139630, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 677.5662841796875, 1254.5262451171875, 97.3759765625, 4.465796947479248046, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 131492, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 716.17706298828125, 1255.8785400390625, 97.4490966796875, 3.318543910980224609, 7200, 0, 0, 70780, 1807, 0, 0, 0, 0, 48966), -- Devout Blood Priest (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%, 271577 - Blood Empower)
(@CGUID+8, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 675.521484375, 1272.9169921875, 97.413665771484375, 3.102550029754638671, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst) (possible waypoints or random movement)
(@CGUID+9, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 709.7064208984375, 1222.16162109375, 99.04914093017578125, 5.38204193115234375, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst) (possible waypoints or random movement)
(@CGUID+10, 130909, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 667.73681640625, 1234.5684814453125, 97.57103729248046875, 3.657451868057250976, 7200, 6, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Fetid Maggot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+11, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 707.8201904296875, 1217.1793212890625, 100.1437454223632812, 4.694113731384277343, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst) (possible waypoints or random movement)
(@CGUID+12, 133663, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 771.54638671875, 1199.87548828125, 70.90564727783203125, 6.116643905639648437, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fanatical Headhunter (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+13, 131436, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 775.61114501953125, 1202.064208984375, 69.3397064208984375, 6.118013381958007812, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Chosen Blood Matron (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 148500 - Invisibility and Stealth Detection)
(@CGUID+14, 120652, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 633.546875, 1252.8853759765625, 98.73419189453125, 3.138837814331054687, 7200, 0, 0, 14156, 0, 0, 0, 0, 0, 48966), -- Global Affix Stalker (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+15, 133663, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 714.99652099609375, 1247.529541015625, 97.4490966796875, 1.358727693557739257, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fanatical Headhunter (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+16, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 666.516357421875, 1264.6339111328125, 96.3922882080078125, 3.886670351028442382, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst) (possible waypoints or random movement)
(@CGUID+17, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 666.77020263671875, 1269.2581787109375, 96.01709747314453125, 3.014825105667114257, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst) (possible waypoints or random movement)
(@CGUID+18, 131436, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 673.6607666015625, 1254.7667236328125, 97.557525634765625, 3.23475193977355957, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Chosen Blood Matron (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 148500 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+19, 130217, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 704.10736083984375, 1233.486083984375, 98.17377471923828125, 1.18474578857421875, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966), -- Nazmani Weevil (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 704.03424072265625, 1216.5755615234375, 99.64112091064453125, 0.926966071128845214, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst) (possible waypoints or random movement)
(@CGUID+21, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 705.64874267578125, 1222.7103271484375, 99.10309600830078125, 4.057688236236572265, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst) (possible waypoints or random movement)
(@CGUID+22, 133663, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 726.578125, 1254.1875, 97.4490966796875, 2.954288244247436523, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fanatical Headhunter (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+23, 135219, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 820.69268798828125, 1285.673583984375, 68.3031768798828125, 3.238937139511108398, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Befouled Spirit Stalker (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+24, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 838.369873046875, 1126.9732666015625, 39.59352493286132812, 1.204007625579833984, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst)
(@CGUID+25, 133835, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 788.41278076171875, 1113.6768798828125, 40.9606170654296875, 1.922821879386901855, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+26, 68553, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 868.98089599609375, 1230.0833740234375, 56.30517196655273437, 0, 7200, 0, 0, 2854, 0, 0, 0, 0, 0, 48966), -- SLG Generic MoP (Large AOI) (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+27, 133663, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 811.810791015625, 1282.3333740234375, 67.20257568359375, 0.321743935346603393, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fanatical Headhunter (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+28, 130217, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 806.80853271484375, 1208.934814453125, 68.7495574951171875, 0.299983292818069458, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966), -- Nazmani Weevil (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+29, 131436, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 803.6180419921875, 1283.732666015625, 67.927032470703125, 6.226246356964111328, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Chosen Blood Matron (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 148500 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+30, 131492, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 800.5509033203125, 1286.7413330078125, 69.00562286376953125, 6.224223613739013671, 7200, 0, 0, 70780, 1807, 0, 0, 0, 0, 48966), -- Devout Blood Priest (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%) (possible waypoints or random movement)
(@CGUID+31, 133663, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 782.8992919921875, 1200.7239990234375, 68.865966796875, 6.258143901824951171, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fanatical Headhunter (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+32, 133663, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 798.24652099609375, 1209.6180419921875, 68.865966796875, 4.262096881866455078, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fanatical Headhunter (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+33, 135219, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 794.06768798828125, 1201.43408203125, 70.267242431640625, 3.238937139511108398, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Befouled Spirit Stalker (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+34, 130217, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 824.4761962890625, 1134.6187744140625, 39.55449295043945312, 0.187627628445625305, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966), -- Nazmani Weevil (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+35, 131318, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 869.50177001953125, 1230.201416015625, 56.49785995483398437, 3.187054872512817382, 7200, 0, 0, 339720, 4650, 0, 0, 0, 0, 48966), -- Elder Leaxa (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+36, 133663, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 800.22979736328125, 1281.09375, 69.38422393798828125, 6.224023342132568359, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fanatical Headhunter (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%) (possible waypoints or random movement)
(@CGUID+37, 133835, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 785.25921630859375, 1126.768798828125, 39.36435699462890625, 5.527443408966064453, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+38, 131436, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 816.59552001953125, 1277.5364990234375, 67.20257568359375, 1.196610450744628906, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Chosen Blood Matron (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 148500 - Invisibility and Stealth Detection)
(@CGUID+39, 130909, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 789.06390380859375, 1124.2518310546875, 39.38431167602539062, 2.695383071899414062, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Fetid Maggot (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+40, 133663, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 820.9305419921875, 1294.9149169921875, 67.20257568359375, 4.705288887023925781, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fanatical Headhunter (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+41, 131436, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 812.08856201171875, 1289.282958984375, 67.20257568359375, 5.993048667907714843, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Chosen Blood Matron (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 148500 - Invisibility and Stealth Detection)
(@CGUID+42, 139630, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 776.36395263671875, 1085.24169921875, 39.9749603271484375, 1.063041567802429199, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 131492, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 828.87677001953125, 1279.5208740234375, 67.20257568359375, 2.496401309967041015, 7200, 0, 0, 70780, 1807, 0, 0, 0, 0, 48966), -- Devout Blood Priest (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+44, 139630, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 810.0675048828125, 1284.78271484375, 67.1138153076171875, 3.493728160858154296, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+45, 131492, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 1, 799.40277099609375, 1192.578125, 68.865966796875, 2.152610301971435546, 7200, 0, 0, 70780, 1807, 0, 0, 0, 0, 48966), -- Devout Blood Priest (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 236530 - Mod Scale +25%)
(@CGUID+46, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 845.239013671875, 1122.6583251953125, 40.270355224609375, 4.718248367309570312, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst)
(@CGUID+47, 133852, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 845.82684326171875, 1022.96148681640625, 40.36276626586914062, 2.725759506225585937, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Living Rot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+48, 133852, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 829.80767822265625, 1072.5125732421875, 41.25033950805664062, 5.092510223388671875, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Living Rot (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+49, 133870, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 797.134521484375, 1042.8717041015625, 42.29153823852539062, 0.077433831989765167, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Diseased Lasher (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+50, 133852, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 820.72601318359375, 1070.62939453125, 41.083404541015625, 4.738750457763671875, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Living Rot (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+51, 133870, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 788.16802978515625, 1050.5533447265625, 41.35469436645507812, 2.07548379898071289, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Diseased Lasher (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+52, 130909, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 806.563720703125, 987.823486328125, 42.05197906494140625, 1.81435251235961914, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fetid Maggot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+53, 133852, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 825.120361328125, 1087.7047119140625, 40.33591079711914062, 1.098467350006103515, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Living Rot (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+54, 133870, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 815.15411376953125, 992.2308349609375, 41.7357635498046875, 3.328139781951904296, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Diseased Lasher (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+55, 130217, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 817.5447998046875, 1038.899169921875, 42.014739990234375, 4.736787796020507812, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966), -- Nazmani Weevil (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+56, 133870, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 776.2335205078125, 1048.063720703125, 40.17415237426757812, 4.473482131958007812, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Diseased Lasher (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+57, 139630, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 818.36737060546875, 1092.7083740234375, 40.116302490234375, 3.794138908386230468, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+58, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 844.871826171875, 1115.1240234375, 40.22533416748046875, 1.013219714164733886, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst)
(@CGUID+59, 133870, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 770.404541015625, 1049.486083984375, 39.91707229614257812, 4.473048686981201171, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Diseased Lasher (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+60, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 850.21502685546875, 1123.969970703125, 40.6819610595703125, 1.715449810028076171, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst)
(@CGUID+61, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 838.10125732421875, 1115.1717529296875, 39.84352493286132812, 1.956023454666137695, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst)
(@CGUID+62, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 836.44598388671875, 1120.7066650390625, 39.71852493286132812, 3.373514175415039062, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst)
(@CGUID+63, 133852, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 818.66827392578125, 1010.30987548828125, 41.49860763549804687, 3.717681407928466796, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Living Rot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+64, 133870, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 787.6348876953125, 1038.462158203125, 41.7923736572265625, 3.362168788909912109, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Diseased Lasher (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 133870, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 840.2999267578125, 1033.1395263671875, 40.6867523193359375, 6.075685977935791015, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Diseased Lasher (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+66, 130909, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 843.5582275390625, 1117.9151611328125, 40.18080520629882812, 5.494484901428222656, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Fetid Maggot (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+67, 131402, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 854.51702880859375, 1110.8282470703125, 40.65801239013671875, 4.609994888305664062, 7200, 2, 0, 14156, 0, 1, 0, 0, 0, 48966), -- Underrot Tick (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 278641 - Blood Burst)
(@CGUID+68, 133852, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 880.16986083984375, 998.63604736328125, 40.38259506225585937, 1.944772720336914062, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Living Rot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+69, 133852, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 860.64996337890625, 944.4927978515625, 41.67582321166992187, 5.639118671417236328, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Living Rot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+70, 133870, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 851.937744140625, 953.63372802734375, 40.648681640625, 0.3718014657497406, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Diseased Lasher (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+71, 133835, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 823.0670166015625, 980.67144775390625, 41.26456451416015625, 2.821413040161132812, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+72, 131817, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 862.49652099609375, 982.31597900390625, 39.23170852661132812, 2.852214574813842773, 7200, 0, 0, 495460, 100, 0, 0, 0, 0, 48966), -- Cragmaw the Infested (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 279156 - Crawg Eating)
(@CGUID+73, 130909, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 823.82196044921875, 969.388916015625, 41.71027755737304687, 5.624958992004394531, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fetid Maggot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+74, 138187, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 1012.75347900390625, 1240.829833984375, 12.65874004364013671, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+75, 133835, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 886.48333740234375, 960.09747314453125, 41.19463348388671875, 4.932362556457519531, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+76, 133835, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 860.38494873046875, 1016.34490966796875, 39.69624710083007812, 1.474715709686279296, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+77, 133835, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 873.8834228515625, 949.47283935546875, 41.12395477294921875, 3.258074045181274414, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+78, 133852, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 884.3388671875, 981.62322998046875, 40.64867019653320312, 2.605680704116821289, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Living Rot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+79, 133870, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 872.90020751953125, 1006.772705078125, 40.05278778076171875, 3.800324201583862304, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Diseased Lasher (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+80, 133852, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 844.04681396484375, 953.278564453125, 41.73216629028320312, 1.628462195396423339, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Living Rot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+81, 138187, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 968.88714599609375, 1234.7535400390625, 14.46331405639648437, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+82, 133835, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 829.77178955078125, 997.10076904296875, 40.518585205078125, 3.864098310470581054, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+83, 133912, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 974.310791015625, 1246.7760009765625, 15.00263595581054687, 1.555563092231750488, 7200, 0, 0, 70780, 1864, 0, 0, 0, 0, 48966), -- Bloodsworn Defiler (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 222912 - Mod Scale 175%)
(@CGUID+84, 130909, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 893.63897705078125, 1008.3515625, 42.6126556396484375, 2.100015163421630859, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fetid Maggot (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+85, 133912, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 958.122314453125, 1197.493408203125, 17.25376510620117187, 4.936623573303222656, 7200, 0, 0, 70780, 1864, 0, 0, 0, 0, 48966), -- Bloodsworn Defiler (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 222912 - Mod Scale 175%)
(@CGUID+86, 138187, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 965.0538330078125, 1178.810791015625, 17.420654296875, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+87, 130909, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 857.84722900390625, 984.08160400390625, 39.23116683959960937, 4.681471824645996093, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Fetid Maggot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+88, 138281, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 1001.4932861328125, 1242.4288330078125, 13.21955299377441406, 3.31236124038696289, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Faceless Corruptor (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@CGUID+89, 138187, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 993.1007080078125, 1203.2083740234375, 17.44475364685058593, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: The Underrot - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+90, 133852, 1841, 9391, 9391, '1,2,23,8', 0, 0, 0, 0, 832.43389892578125, 963.40350341796875, 41.44072341918945312, 1.520984172821044921, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Living Rot (Area: The Underrot - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+91, 138187, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1023.95489501953125, 1257.4254150390625, 12.75382518768310546, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+92, 138281, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1033.4097900390625, 1134.6666259765625, 14.69067859649658203, 1.643191695213317871, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Faceless Corruptor (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1
(@CGUID+93, 138187, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1057.15283203125, 1240.8350830078125, 13.59142589569091796, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+94, 138187, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1066.5225830078125, 1266.173583984375, 11.41441535949707031, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+95, 138187, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1071.2708740234375, 1293.7847900390625, 8.326403617858886718, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+96, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1067.314208984375, 1189.8287353515625, 18.05634498596191406, 1.96393740177154541, 7200, 3, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura)
(@CGUID+97, 131383, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1032.9444580078125, 1058.2899169921875, 33.33089447021484375, 4.573857784271240234, 7200, 0, 0, 495460, 100, 0, 0, 0, 0, 48966), -- Sporecaller Zancha (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+98, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1076.4559326171875, 1180.3154296875, 19.12542343139648437, 1.988620638847351074, 7200, 3, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura)
(@CGUID+99, 134284, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1082.013916015625, 1189.4774169921875, 20.28182792663574218, 4.6102142333984375, 7200, 0, 0, 70780, 1807, 0, 0, 0, 0, 48966), -- Fallen Deathspeaker (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 263835 - Deathspeaker Spawn)
(@CGUID+100, 138281, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1093.5299072265625, 1235.026611328125, 14.99462223052978515, 2.746405601501464843, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Faceless Corruptor (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1
(@CGUID+101, 138187, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1069.2291259765625, 1134.2257080078125, 16.16880226135253906, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+102, 138281, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1091.328125, 1333.53125, 5.940267562866210937, 4.30108499526977539, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Faceless Corruptor (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1
(@CGUID+103, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1087.2725830078125, 1183.9237060546875, 20.29243278503417968, 4.105435371398925781, 7200, 3, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura) (possible waypoints or random movement)
(@CGUID+104, 139630, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 803.3516845703125, 988.15814208984375, 42.08780670166015625, 3.381125211715698242, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+105, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 935.843017578125, 929.4710693359375, 47.06266021728515625, 2.139068603515625, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura) (possible waypoints or random movement)
(@CGUID+106, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 935.00518798828125, 935.9461669921875, 46.93221282958984375, 3.569495439529418945, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura) (possible waypoints or random movement)
(@CGUID+107, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 947.36834716796875, 930.52740478515625, 47.31108856201171875, 1.017481446266174316, 7200, 4, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura) (possible waypoints or random movement)
(@CGUID+108, 133912, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1035.064208984375, 1025.1927490234375, 33.69562530517578125, 1.748207569122314453, 7200, 0, 0, 70780, 1864, 0, 0, 0, 0, 48966), -- Bloodsworn Defiler (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 222912 - Mod Scale 175%)
(@CGUID+109, 133912, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1030.15283203125, 1025.5086669921875, 33.70556259155273437, 1.748207569122314453, 7200, 0, 0, 70780, 1864, 0, 0, 0, 0, 48966), -- Bloodsworn Defiler (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 222912 - Mod Scale 175%)
(@CGUID+110, 138281, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1103.6492919921875, 1325.607666015625, 6.032054901123046875, 4.063190937042236328, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Faceless Corruptor (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1
(@CGUID+111, 139630, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1012.12152099609375, 1245.6129150390625, 12.75779247283935546, 0, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+112, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1098.4375, 1178.2833251953125, 17.26056861877441406, 4.712388992309570312, 7200, 3, 0, 70780, 0, 1, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura) (possible waypoints or random movement)
(@CGUID+113, 138187, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1112.8629150390625, 1212.984375, 14.97478580474853515, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+114, 133912, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1087.2857666015625, 1144.7381591796875, 14.95239734649658203, 5.826910972595214843, 7200, 4, 0, 70780, 1864, 1, 0, 0, 0, 48966), -- Bloodsworn Defiler (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 222912 - Mod Scale 175%) (possible waypoints or random movement)
(@CGUID+115, 139630, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 995.26171875, 1194.8443603515625, 17.69634056091308593, 5.688140869140625, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+116, 130217, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 989.20538330078125, 1147.6207275390625, 14.40235233306884765, 0.482305526733398437, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966), -- Nazmani Weevil (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+117, 134284, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 952.640625, 928.3211669921875, 47.440277099609375, 3.088200569152832031, 7200, 0, 0, 70780, 1807, 0, 0, 0, 0, 48966), -- Fallen Deathspeaker (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 263835 - Deathspeaker Spawn)
(@CGUID+118, 138187, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1024.79345703125, 995.87847900390625, 35.035919189453125, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+119, 134284, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1007.626953125, 973.8101806640625, 39.39960479736328125, 1.138669848442077636, 7200, 0, 0, 70780, 1807, 0, 0, 0, 0, 48966), -- Fallen Deathspeaker (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 263835 - Deathspeaker Spawn)
(@CGUID+120, 133912, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1016.7396240234375, 983.76214599609375, 36.86212921142578125, 1.164063930511474609, 7200, 0, 0, 70780, 1864, 0, 0, 0, 0, 48966), -- Bloodsworn Defiler (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 222912 - Mod Scale 175%)
(@CGUID+121, 138187, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1114.3160400390625, 1170.078125, 14.97231388092041015, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+122, 138740, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 987.078125, 1089.8975830078125, 33.25746536254882812, 2.766138076782226562, 7200, 0, 0, 141560, 0, 0, 0, 0, 0, 48966), -- Musashitake (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 272773 - 8.0 Underrot Dungeon - Sporecaller Zancha -  Achievement Add Visual)
(@CGUID+123, 138187, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1100.6353759765625, 1129.986083984375, 14.68400001525878906, 5.911023616790771484, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+124, 138187, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 984.86114501953125, 935.50177001953125, 47.48064041137695312, 3.153665781021118164, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Grotesque Horror (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged, 271955 - Tentacle Base)
(@CGUID+125, 138281, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1113.6016845703125, 1203.0169677734375, 15.00757884979248046, 1.492654681205749511, 7200, 0, 0, 113248, 0, 0, 0, 0, 0, 48966), -- Faceless Corruptor (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1
(@CGUID+126, 130217, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 897.57208251953125, 989.714599609375, 42.29478836059570312, 3.79715728759765625, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966), -- Nazmani Weevil (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+127, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1030.3790283203125, 943.35791015625, 38.03745269775390625, 3.469202041625976562, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura)
(@CGUID+128, 134419, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1031.454833984375, 1175.8524169921875, 12.08784675598144531, 4.736319541931152343, 7200, 0, 0, 1415600, 0, 0, 0, 0, 0, 48966), -- Titan Keeper Hezrel (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 279551 - Shadow Visual State)
(@CGUID+129, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1028.001708984375, 938.59832763671875, 39.38484573364257812, 3.569432258605957031, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura) (possible waypoints or random movement)
(@CGUID+130, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1018.51416015625, 942.22882080078125, 41.07466888427734375, 3.083926677703857421, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura) (possible waypoints or random movement)
(@CGUID+131, 134284, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1024.45068359375, 942.720458984375, 39.20760726928710937, 3.202183961868286132, 7200, 0, 0, 70780, 1807, 0, 0, 0, 0, 48966), -- Fallen Deathspeaker (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 263835 - Deathspeaker Spawn) (possible waypoints or random movement)
(@CGUID+132, 139630, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 862.0224609375, 954.7725830078125, 40.60529327392578125, 5.725517749786376953, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+133, 133836, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 1, 1023.726318359375, 948.69482421875, 39.52112579345703125, 3.212969779968261718, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Reanimated Guardian (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 271872 - Bone Spirit Aura)
(@CGUID+134, 139630, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1016.85980224609375, 1056.7257080078125, 33.11280059814453125, 1.541554450988769531, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1
(@CGUID+135, 144306, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1025.439208984375, 1066.8646240234375, 33.33089447021484375, 5.471001625061035156, 7200, 0, 0, 70780, 1864, 0, 0, 0, 0, 48966), -- Bloodsworn Defiler (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 222912 - Mod Scale 175%)
(@CGUID+136, 133835, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1037.5858154296875, 928.622802734375, 68.098785400390625, 2.621216297149658203, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+137, 144306, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1024.9410400390625, 1050.9879150390625, 33.47074127197265625, 0.834099888801574707, 7200, 0, 0, 70780, 1864, 0, 0, 0, 0, 48966), -- Bloodsworn Defiler (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 222912 - Mod Scale 175%)
(@CGUID+138, 133835, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1118.7921142578125, 1009.1453857421875, 61.59543609619140625, 4.164049148559570312, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+139, 130217, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1073.838623046875, 1237.9398193359375, 14.47161579132080078, 6.052370071411132812, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966), -- Nazmani Weevil (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+140, 144306, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1040.1475830078125, 1066.8697509765625, 33.40680313110351562, 3.993519783020019531, 7200, 0, 0, 70780, 1864, 0, 0, 0, 0, 48966), -- Bloodsworn Defiler (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 222912 - Mod Scale 175%)
(@CGUID+141, 133835, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1058.3001708984375, 922.67626953125, 32.62597274780273437, 1.74248504638671875, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+142, 133835, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1037.778564453125, 907.2071533203125, 54.54974746704101562, 1.919513344764709472, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+143, 144306, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1041.1041259765625, 1051.6285400390625, 33.5359954833984375, 2.443913221359252929, 7200, 0, 0, 70780, 1864, 0, 0, 0, 0, 48966), -- Bloodsworn Defiler (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (Auras: 222912 - Mod Scale 175%)
(@CGUID+144, 133835, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1086.6658935546875, 950.8387451171875, 29.6870880126953125, 2.37820744514465332, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+145, 133835, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1123.8326416015625, 995.958740234375, 72.4276580810546875, 2.568267345428466796, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+146, 133835, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1030.6943359375, 902.805908203125, 23.05453300476074218, 2.248753309249877929, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+147, 133835, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1057.78662109375, 917.18548583984375, 47.87449264526367187, 2.807102918624877929, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+148, 133835, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1115.5068359375, 992.48089599609375, 45.16369247436523437, 3.396327018737792968, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1
(@CGUID+149, 139630, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1086.236328125, 1145.474365234375, 14.95239734649658203, 2.141190528869628906, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+150, 139630, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1009.71307373046875, 975.07879638671875, 39.05723953247070312, 5.13843393325805664, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 48966), -- Blight Recluse (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+151, 133835, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1107.2445068359375, 926.91339111328125, 62.37392425537109375, 3.026115179061889648, 7200, 0, 0, 70780, 0, 0, 0, 0, 0, 48966), -- Feral Bloodswarmer (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+152, 63420, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1105.66845703125, 1338.626708984375, 10.34186267852783203, 4.075899124145507812, 7200, 0, 0, 2854, 0, 0, 0, 0, 0, 48966), -- SLG Generic MoP (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1
(@CGUID+153, 130217, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 1041.4893798828125, 979.85821533203125, 33.62405776977539062, 1.989417433738708496, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966), -- Nazmani Weevil (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+154, 130217, 1841, 9391, 10020, '1,2,23,8', 0, 0, 0, 0, 985.30364990234375, 933.36126708984375, 47.5264892578125, 3.272115707397460937, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966), -- Nazmani Weevil (Area: Sanctuary of Blood - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+155, 133007, 1841, 9391, 10021, '1,2,23,8', 0, 0, 0, 0, 1184.986083984375, 1451.4254150390625, -181.49493408203125, 1.044219017028808593, 7200, 0, 0, 552084, 100, 0, 0, 0, 0, 48966), -- Unbound Abomination (Area: Ruins of Xal'vor - Difficulty: Mythic) CreateObject1 (Auras: 269185 - Blood Barrier)
(@CGUID+156, 134419, 1841, 9391, 10021, '1,2,23,8', 0, 0, 0, 0, 1199.423583984375, 1481.9375, -181.506317138671875, 4.290438652038574218, 7200, 0, 0, 1415600, 0, 0, 0, 0, 0, 48966), -- Titan Keeper Hezrel (Area: Ruins of Xal'vor - Difficulty: Mythic) CreateObject1 (Auras: 279250 - Holy Channel)
(@CGUID+157, 130217, 1841, 9391, 10021, '1,2,23,8', 0, 0, 0, 0, 1222.0159912109375, 1501.2403564453125, -181.464569091796875, 5.326083183288574218, 7200, 8, 0, 5, 0, 1, 0, 0, 0, 48966); -- Nazmani Weevil (Area: Ruins of Xal'vor - Difficulty: Mythic) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+157;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '236530'), -- Devout Blood Priest - 236530 - Mod Scale +25%
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 723, 0, 0, 0, 3, '236530'), -- Fanatical Headhunter - 236530 - Mod Scale +25%
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 13325, 0, 0, 3, '236530 271577'), -- Devout Blood Priest - 236530 - Mod Scale +25%, 271577 - Blood Empower
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '236530'), -- Fanatical Headhunter - 236530 - Mod Scale +25%
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''), -- Global Affix Stalker
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 723, 0, 0, 0, 3, '236530'), -- Fanatical Headhunter - 236530 - Mod Scale +25%
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 723, 0, 0, 0, 3, '236530'), -- Fanatical Headhunter - 236530 - Mod Scale +25%
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- SLG Generic MoP (Large AOI)
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 724, 0, 0, 0, 3, '236530'), -- Fanatical Headhunter - 236530 - Mod Scale +25%
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '236530'), -- Devout Blood Priest - 236530 - Mod Scale +25%
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 723, 0, 0, 0, 3, '236530'), -- Fanatical Headhunter - 236530 - Mod Scale +25%
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 723, 0, 0, 0, 3, '236530'), -- Fanatical Headhunter - 236530 - Mod Scale +25%
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '236530'), -- Fanatical Headhunter - 236530 - Mod Scale +25%
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 724, 0, 0, 0, 3, '236530'), -- Fanatical Headhunter - 236530 - Mod Scale +25%
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 724, 0, 0, 0, 3, '236530'), -- Devout Blood Priest - 236530 - Mod Scale +25%
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 723, 0, 0, 0, 3, '236530'), -- Devout Blood Priest - 236530 - Mod Scale +25%
(@CGUID+87, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 3, '159474'), -- Fetid Maggot - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+136, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Feral Bloodswarmer
(@CGUID+138, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Feral Bloodswarmer
(@CGUID+141, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Feral Bloodswarmer
(@CGUID+142, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Feral Bloodswarmer
(@CGUID+144, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Feral Bloodswarmer
(@CGUID+145, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Feral Bloodswarmer
(@CGUID+146, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Feral Bloodswarmer
(@CGUID+147, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Feral Bloodswarmer
(@CGUID+148, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Feral Bloodswarmer
(@CGUID+151, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Feral Bloodswarmer

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 252248, 1841, 9391, 9391, '1,2,23,8', 0, 0, 616.69097900390625, 1256.9461669921875, 103.8511734008789062, 5.799980640411376953, 0, 0, -0.2392587661743164, 0.970955848693847656, 7200, 255, 1, 48966), -- Instance Portal (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@OGUID+1, 295355, 1841, 9391, 9391, '1,2,23,8', 0, 0, 872.06597900390625, 1149.592041015625, 52.25160598754882812, 4.787228107452392578, 0.622781753540039062, -0.52217578887939453, -0.43625259399414062, 0.386211097240447998, 7200, 255, 1, 48966), -- Web (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@OGUID+2, 295354, 1841, 9391, 9391, '1,2,23,8', 0, 0, 878.357666015625, 1154.123291015625, 52.64917755126953125, 4.317960739135742187, 0.484431266784667968, -0.59184551239013671, -0.58023452758789062, 0.279952138662338256, 7200, 255, 1, 48966), -- Web (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@OGUID+3, 295356, 1841, 9391, 9391, '1,2,23,8', 0, 0, 872.1492919921875, 1153.1024169921875, 42.60771560668945312, 2.242745637893676757, 0, 0, 0.900697708129882812, 0.434446364641189575, 7200, 255, 1, 48966), -- Wall (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@OGUID+4, 296385, 1841, 9391, 9391, '1,2,23,8', 0, 0, 1103.611083984375, 1336.295166015625, 5.103426456451416015, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 48966), -- Pyramid Door (Area: The Underrot - Difficulty: Mythic) CreateObject1
(@OGUID+5, 296384, 1841, 9391, 9391, '1,2,23,8', 0, 0, 1103.638916015625, 1336.4461669921875, 11.77979946136474609, 4.122861862182617187, -0.4680795669555664, 0.867672920227050781, 0.099225044250488281, 0.134905755519866943, 7200, 255, 1, 48966); -- Pyramid Web (Area: The Underrot - Difficulty: Mythic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (133007 /*133007 (Unbound Abomination) - Blood Barrier*/, 144306 /*144306 (Bloodsworn Defiler) - Mod Scale 175%*/, 134419 /*134419 (Titan Keeper Hezrel) - Shadow Visual State*/, 138740 /*138740 (Musashitake) - 8.0 Underrot Dungeon - Sporecaller Zancha -  Achievement Add Visual*/, 134284 /*134284 (Fallen Deathspeaker) - Deathspeaker Spawn*/, 131383 /*131383 (Sporecaller Zancha)*/, 133836 /*133836 (Reanimated Guardian) - Bone Spirit Aura*/, 138281 /*138281 (Faceless Corruptor)*/, 133912 /*133912 (Bloodsworn Defiler) - Mod Scale 175%*/, 132137 /*132137 (Cosmetic Blood Tick) - Ride Vehicle Hardcoded, Mod Scale 90-100%*/, 138187 /*138187 (Grotesque Horror) - Submerged, Tentacle Base*/, 131817 /*131817 (Cragmaw the Infested) - Crawg Eating*/, 133870 /*133870 (Diseased Lasher)*/, 133852 /*133852 (Living Rot)*/, 131318 /*131318 (Elder Leaxa)*/, 133685 /*133685 (Befouled Spirit) - Ride Vehicle Hardcoded*/, 68553 /*68553 (SLG Generic MoP (Large AOI))*/, 133835 /*133835 (Feral Bloodswarmer)*/, 131436 /*131436 (Chosen Blood Matron) - Invisibility and Stealth Detection*/, 130909 /*130909 (Fetid Maggot)*/, 133663 /*133663 (Fanatical Headhunter) - Mod Scale +25%*/, 131492 /*131492 (Devout Blood Priest) - Mod Scale +25%*/, 131402 /*131402 (Underrot Tick) - Blood Burst*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(133007, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '269185'), -- 133007 (Unbound Abomination) - Blood Barrier
(144306, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222912'), -- 144306 (Bloodsworn Defiler) - Mod Scale 175%
(134419, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '279551'), -- 134419 (Titan Keeper Hezrel) - Shadow Visual State
(138740, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '272773'), -- 138740 (Musashitake) - 8.0 Underrot Dungeon - Sporecaller Zancha -  Achievement Add Visual
(134284, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '263835'), -- 134284 (Fallen Deathspeaker) - Deathspeaker Spawn
(131383, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 131383 (Sporecaller Zancha)
(133836, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '271872'), -- 133836 (Reanimated Guardian) - Bone Spirit Aura
(138281, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 138281 (Faceless Corruptor)
(133912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '222912'), -- 133912 (Bloodsworn Defiler) - Mod Scale 175%
(132137, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '237007'), -- 132137 (Cosmetic Blood Tick) - Mod Scale 90-100%
(138187, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645 271955'), -- 138187 (Grotesque Horror) - Submerged, Tentacle Base
(131817, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 3, '279156 271771'), -- 131817 (Cragmaw the Infested) - Crawg Eating
(133870, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 133870 (Diseased Lasher)
(133852, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 133852 (Living Rot)
(131318, 0, 0, 0, 0, 0, 1, 0, 0, 13325, 0, 0, 3, ''), -- 131318 (Elder Leaxa)
(133685, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 133685 (Befouled Spirit)
(68553, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 68553 (SLG Generic MoP (Large AOI))
(133835, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 133835 (Feral Bloodswarmer)
(131436, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '148500'), -- 131436 (Chosen Blood Matron) - Invisibility and Stealth Detection
(130909, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 130909 (Fetid Maggot)
(133663, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '236530'), -- 133663 (Fanatical Headhunter) - Mod Scale +25%
(131402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '278641'); -- 131402 (Underrot Tick) - Blood Burst

-- Creature Template
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=132137; -- Cosmetic Blood Tick
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134419; -- Titan Keeper Hezrel

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (135219);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(135219, 0, 0, 1, 1, 0, 0, NULL); -- Befouled Spirit

-- Creature Movement Override
DELETE FROM `creature_movement_override` WHERE `SpawnId` IN (@CGUID+136, @CGUID+138, @CGUID+141, @CGUID+142, @CGUID+144, @CGUID+145, @CGUID+146, @CGUID+147, @CGUID+148, @CGUID+151);
INSERT INTO `creature_movement_override` (`SpawnId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(@CGUID+136, 0, 0, 1, 0, 0, 0, NULL),
(@CGUID+138, 0, 0, 1, 0, 0, 0, NULL),
(@CGUID+141, 0, 0, 1, 0, 0, 0, NULL),
(@CGUID+142, 0, 0, 1, 0, 0, 0, NULL),
(@CGUID+144, 0, 0, 1, 0, 0, 0, NULL),
(@CGUID+145, 0, 0, 1, 0, 0, 0, NULL),
(@CGUID+146, 0, 0, 1, 0, 0, 0, NULL),
(@CGUID+147, 0, 0, 1, 0, 0, 0, NULL),
(@CGUID+148, 0, 0, 1, 0, 0, 0, NULL),
(@CGUID+151, 0, 0, 1, 0, 0, 0, NULL);

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=135219 AND `seat_id`=0) OR (`entry`=131817 AND `seat_id` IN (7,6,5,4,3,2,1,0));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(135219, 133685, 0, 1, 'Befouled Spirit Stalker - Befouled Spirit', 8, 0), -- Befouled Spirit Stalker - Befouled Spirit
(131817, 132137, 7, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 8, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 6, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 8, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 5, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 8, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 4, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 8, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 3, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 8, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 2, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 8, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 1, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 8, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 0, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 8, 0); -- Cragmaw the Infested - Cosmetic Blood Tick

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (135219, 131817);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(135219, 46598, 0, 0),
(131817, 46598, 0, 0);

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 271578);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 271578, 0, 0, 31, 0, 3, 133663, 0, 0, 0, 0, '', 'Blood Empower - can only Target Fanatical Headhunter (133663)');

-- Scaling (Mythic)
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=23 AND `Entry` IN (133007,63420,144306,134419,138740,134284,131383,133836,138281,133912,132137,138187,131817,133870,133852,131318,133685,68553,133835,135219,131436,130909,139630,133663,131492,130217,131402));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(133007, 23, 2, 2, 502, 48966),
(63420, 23, 0, 0, 657, 48966),
(144306, 23, 1, 1, 502, 48966),
(134419, 23, 0, 0, 502, 48966),
(138740, 23, 0, 0, 502, 48966),
(134284, 23, 0, 0, 502, 48966),
(131383, 23, 2, 2, 502, 48966),
(133836, 23, 0, 0, 502, 48966),
(138281, 23, 1, 1, 502, 48966),
(133912, 23, 1, 1, 502, 48966),
(132137, 23, 0, 0, 502, 48966),
(138187, 23, 0, 0, 502, 48966),
(131817, 23, 2, 2, 502, 48966),
(133870, 23, 0, 0, 502, 48966),
(133852, 23, 0, 0, 502, 48966),
(131318, 23, 2, 2, 502, 48966),
(133685, 23, 1, 1, 502, 48966),
(68553, 23, 0, 0, 657, 48966),
(133835, 23, 0, 0, 502, 48966),
(135219, 23, 0, 0, 502, 48966),
(131436, 23, 1, 1, 502, 48966),
(130909, 23, 0, 0, 502, 48966),
(139630, 23, 0, 0, 81, 48966),
(133663, 23, 0, 0, 502, 48966),
(131492, 23, 0, 0, 502, 48966),
(130217, 23, 0, 0, 81, 48966),
(131402, 23, 0, 0, 502, 48966);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=48966 WHERE (`Entry`=120652 AND `DifficultyID`=23);

-- Model Updates
UPDATE `creature_model_info` SET `VerifiedBuild`=48966 WHERE `DisplayID` IN (86632, 76851, 81977, 79182, 80459, 80467, 83311, 81377, 11686, 76653, 79500, 16925, 80910, 75861, 81380);
UPDATE `creature_model_info` SET `BoundingRadius`=1.075765132904052734, `CombatReach`=3, `VerifiedBuild`=48966 WHERE `DisplayID`=83603;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=48966 WHERE `DisplayID`=85815;
UPDATE `creature_model_info` SET `BoundingRadius`=0.604653477668762207, `CombatReach`=1.5, `VerifiedBuild`=48966 WHERE `DisplayID`=88121;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288985729217529296, `CombatReach`=2, `VerifiedBuild`=48966 WHERE `DisplayID`=84376;
UPDATE `creature_model_info` SET `BoundingRadius`=1.527754187583923339, `CombatReach`=3.75, `VerifiedBuild`=48966 WHERE `DisplayID`=84808;
UPDATE `creature_model_info` SET `BoundingRadius`=1.469839096069335937, `CombatReach`=2.20000004768371582, `VerifiedBuild`=48966 WHERE `DisplayID`=78855;
UPDATE `creature_model_info` SET `BoundingRadius`=0.342625141143798828, `CombatReach`=0.300000011920928955, `VerifiedBuild`=48966 WHERE `DisplayID`=43156;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840022027492523193, `CombatReach`=1.80000007152557373, `VerifiedBuild`=48966 WHERE `DisplayID`=82394;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=48966 WHERE `DisplayID`=80852;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=48966 WHERE `DisplayID` IN (79501, 79502, 79499);
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=48966 WHERE `DisplayID`=84145;
UPDATE `creature_model_info` SET `BoundingRadius`=1.220501065254211425, `CombatReach`=2.699999809265136718, `VerifiedBuild`=48966 WHERE `DisplayID`=85816;
UPDATE `creature_model_info` SET `BoundingRadius`=0.375, `CombatReach`=0.625, `VerifiedBuild`=48966 WHERE `DisplayID`=88361;
UPDATE `creature_model_info` SET `BoundingRadius`=0.150000005960464477, `CombatReach`=0.150000005960464477, `VerifiedBuild`=48966 WHERE `DisplayID`=81808;

-- Waypoints for CGUID+29
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+29;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+29, @CGUID+29, 0, 0, 515, 0, 0),
(@CGUID+29, @CGUID+30, 3, 90, 515, 3, 9),
(@CGUID+29, @CGUID+36, 3, 270, 515, 3, 9);

SET @PATH := (@CGUID+29) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 772.6979, 1290.066, 78.58463, NULL, 0),
(@PATH, 1, 759.5938, 1290.72, 83.01493, NULL, 0),
(@PATH, 2, 749.2535, 1287.257, 86.373, NULL, 0),
(@PATH, 3, 739.9358, 1282.415, 89.86629, NULL, 6228),
(@PATH, 4, 749.2535, 1287.257, 86.373, NULL, 0),
(@PATH, 5, 759.5938, 1290.72, 83.01493, NULL, 0),
(@PATH, 6, 772.6979, 1290.066, 78.58463, NULL, 0),
(@PATH, 7, 781.4011, 1288.002, 75.50561, NULL, 0),
(@PATH, 8, 791.1302, 1284.444, 72.21384, NULL, 0),
(@PATH, 9, 803.618, 1283.733, 67.92703, NULL, 7012),
(@PATH, 10, 791.1302, 1284.444, 72.21384, NULL, 0),
(@PATH, 11, 781.4011, 1288.002, 75.50561, NULL, 0);

UPDATE `creature` SET `position_x`= 772.6979, `position_y`= 1290.066, `position_z`= 78.58463, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+29;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+29;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+29, @PATH, 1, '148500');

-- Waypoints for CGUID+13
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+13;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+13, @CGUID+13, 0, 0, 515, 0, 0),
(@CGUID+13, @CGUID+2, 3, 90, 515, 1, 6),
(@CGUID+13, @CGUID+12, 3, 270, 515, 1, 6);

SET @PATH := (@CGUID+13) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 733.3184, 1228.456, 89.02717, NULL, 0),
(@PATH, 1, 722.2379, 1234.934, 93.59602, NULL, 10829),
(@PATH, 2, 733.1373, 1228.578, 89.14413, NULL, 0),
(@PATH, 3, 741.0695, 1220.5, 85.86668, NULL, 0),
(@PATH, 4, 749.5851, 1211.198, 81.02641, NULL, 0),
(@PATH, 5, 761.9462, 1204.342, 75.16568, NULL, 0),
(@PATH, 6, 775.6111, 1202.064, 69.33971, NULL, 6173),
(@PATH, 7, 761.9462, 1204.342, 75.16568, NULL, 0),
(@PATH, 8, 749.5851, 1211.198, 81.02641, NULL, 0),
(@PATH, 9, 741.0695, 1220.5, 85.86668, NULL, 0);

UPDATE `creature` SET `position_x`= 733.3184, `position_y`= 1228.456, `position_z`= 89.02717, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+13;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+13, @PATH, 1, '148500');

-- Waypoints for CGUID+18
SET @PATH := (@CGUID+18) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 670.7691, 1254.497, 97.57507, NULL, 0),
(@PATH, 1, 662.566, 1252.899, 97.20186, NULL, 6356),
(@PATH, 2, 670.7691, 1254.497, 97.57507, NULL, 0),
(@PATH, 3, 680.0417, 1255.363, 97.5188, NULL, 0),
(@PATH, 4, 700.6458, 1251.748, 97.26582, NULL, 6266),
(@PATH, 5, 680.0417, 1255.363, 97.5188, NULL, 0);

UPDATE `creature` SET `position_x`= 670.7691, `position_y`= 1254.497, `position_z`= 97.57507, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+18;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+18, @PATH, 1, '148500');

-- Waypoints for CGUID+59
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+59;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+59, @CGUID+59, 0, 0, 515, 0, 0),
(@CGUID+59, @CGUID+56, 4, 270, 515, 4, 9);

SET @PATH := (@CGUID+59) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 791.7986, 1091.767, 39.52708, NULL, 0),
(@PATH, 1, 781.6893, 1089.958, 39.97496, NULL, 0),
(@PATH, 2, 773.2309, 1075.156, 39.97496, NULL, 0),
(@PATH, 3, 773.6996, 1062.99, 39.91878, NULL, 0),
(@PATH, 4, 770.4045, 1049.486, 39.91707, NULL, 10647),
(@PATH, 5, 773.6996, 1062.99, 39.91878, NULL, 0),
(@PATH, 6, 773.2309, 1075.156, 39.97496, NULL, 0),
(@PATH, 7, 781.6893, 1089.958, 39.97496, NULL, 0),
(@PATH, 8, 791.7986, 1091.767, 39.52708, NULL, 0),
(@PATH, 9, 808.2864, 1092.793, 40.44687, NULL, 10686);

UPDATE `creature` SET `position_x`= 791.7986, `position_y`= 1091.767, `position_z`= 39.52708, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+59;
UPDATE `creature` SET `position_x`= 791.7986, `position_y`= 1091.767, `position_z`= 39.52708, `orientation`= 0 WHERE `guid` = @CGUID+56;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+59;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+59, @PATH, 1);

-- Waypoints for CGUID+73
SET @PATH := (@CGUID+73) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 823.3976, 969.717, 41.79215, NULL, 0),
(@PATH, 1, 836.1702, 959.8507, 41.5631, NULL, 0),
(@PATH, 2, 853.7969, 947.4601, 41.29772, NULL, 0),
(@PATH, 3, 881.332, 942.3193, 43.94463, NULL, 0),
(@PATH, 4, 897.8073, 942.0399, 44.83733, NULL, 0),
(@PATH, 5, 881.3594, 942.3143, 43.8648, NULL, 0),
(@PATH, 6, 853.7969, 947.4601, 41.29772, NULL, 0),
(@PATH, 7, 836.1702, 959.8507, 41.5631, NULL, 0);

UPDATE `creature` SET `position_x`= 823.3976, `position_y`= 969.717, `position_z`= 41.79215, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+73;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+73;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+73, @PATH, 1);

-- Waypoints for CGUID+84
SET @PATH := (@CGUID+84) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 903.9271, 984.5764, 42.73545, NULL, 0),
(@PATH, 1, 903.5452, 971.467, 44.15049, NULL, 0),
(@PATH, 2, 903.9258, 984.4668, 42.70176, NULL, 0),
(@PATH, 3, 900.3229, 996.2813, 43.05308, NULL, 0),
(@PATH, 4, 894.2639, 1007.283, 42.67657, NULL, 0),
(@PATH, 5, 889.743, 1015.014, 42.35088, NULL, 0),
(@PATH, 6, 894.2639, 1007.283, 42.67657, NULL, 0),
(@PATH, 7, 900.3229, 996.2813, 43.05308, NULL, 0);

UPDATE `creature` SET `position_x`= 903.9271, `position_y`= 984.5764, `position_z`= 42.73545, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+84;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+84;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+84, @PATH, 1);

-- Waypoints for CGUID+52
SET @PATH := (@CGUID+52) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 806.8246, 1004.79, 42.11616, NULL, 0),
(@PATH, 1, 808.0555, 1010.096, 41.89131, NULL, 0),
(@PATH, 2, 806.8246, 1004.79, 42.11616, NULL, 0),
(@PATH, 3, 805.9479, 990.2795, 41.86857, NULL, 0),
(@PATH, 4, 809.7882, 974.8472, 42.35831, NULL, 0),
(@PATH, 5, 817.3386, 960.0469, 43.82864, NULL, 4),
(@PATH, 6, 809.7882, 974.8472, 42.35831, NULL, 0),
(@PATH, 7, 805.9479, 990.2795, 41.86857, NULL, 0);

UPDATE `creature` SET `position_x`= 806.8246, `position_y`= 1004.79, `position_z`= 42.11616, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+52;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+52;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+52, @PATH, 1);

-- Waypoints for CGUID+131
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+131;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+131, @CGUID+131, 0, 0, 515, 0, 0),
(@CGUID+131, @CGUID+133, 4, 90, 515, 4, 0),
(@CGUID+131, @CGUID+129, 4, 270, 515, 4, 0),
(@CGUID+131, @CGUID+130, 4, 180, 515, 4, 0),
(@CGUID+131, @CGUID+127, 4, 360, 515, 4, 0);

SET @PATH := (@CGUID+131) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1019.122, 942.3958, 40.7231, NULL, 0),
(@PATH, 1, 1028.286, 942.9531, 38.42855, NULL, 0),
(@PATH, 2, 1038.868, 949.3055, 35.92035, NULL, 0),
(@PATH, 3, 1039.385, 963.5452, 34.64948, NULL, 0),
(@PATH, 4, 1047.191, 978.2448, 32.76249, NULL, 0),
(@PATH, 5, 1039.385, 963.5452, 34.64948, NULL, 0),
(@PATH, 6, 1038.868, 949.3055, 35.92035, NULL, 0),
(@PATH, 7, 1028.286, 942.9531, 38.42855, NULL, 0);

UPDATE `creature` SET `position_x`= 1019.122, `position_y`= 942.3958, `position_z`= 40.7231, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+131;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+131;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+131, @PATH, 1, '263835');

-- Waypoints for CGUID+85
SET @PATH := (@CGUID+85) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 968.3993, 1211.688, 17.5772, NULL, 0),
(@PATH, 1, 961.0729, 1207.517, 17.34902, NULL, 0),
(@PATH, 2, 957.9097, 1198.425, 17.23327, NULL, 0),
(@PATH, 3, 961.1962, 1184.016, 17.55016, NULL, 0),
(@PATH, 4, 974.0677, 1179.991, 17.49499, NULL, 0),
(@PATH, 5, 985.2674, 1179.983, 17.24499, NULL, 0),
(@PATH, 6, 995.0434, 1186.797, 17.58764, NULL, 0),
(@PATH, 7, 994.6389, 1197.568, 17.36999, NULL, 0),
(@PATH, 8, 982.7136, 1210.476, 17.48723, NULL, 0);

UPDATE `creature` SET `position_x`= 968.3993, `position_y`= 1211.688, `position_z`= 17.5772, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+85;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+85;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+85, @PATH, 1);

-- Waypoints for CGUID+120
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+120;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+120, @CGUID+120, 0, 0, 515, 0, 0),
(@CGUID+120, @CGUID+119, 4, 270, 515, 2, 5);

SET @PATH := (@CGUID+120) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1011.087, 971.7691, 39.10444, NULL, 0),
(@PATH, 1, 1016.74, 983.7621, 36.86213, NULL, 0),
(@PATH, 2, 1022.974, 998.2239, 34.82282, NULL, 0),
(@PATH, 3, 1016.74, 983.7621, 36.86213, NULL, 0),
(@PATH, 4, 1011.087, 971.7691, 39.10444, NULL, 0),
(@PATH, 5, 1005.469, 959.3993, 41.84456, NULL, 0);

UPDATE `creature` SET `position_x`= 1011.087, `position_y`= 971.7691, `position_z`= 39.10444, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+120;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+120;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+120, @PATH, 1);

-- Waypoints for CGUID+88
SET @PATH := (@CGUID+88) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 986.7795, 1240.28, 14.65292, NULL, 0),
(@PATH, 1, 996.2952, 1241.528, 13.73922, NULL, 0),
(@PATH, 2, 1011.471, 1244.149, 12.70725, NULL, 0),
(@PATH, 3, 1021.972, 1250.288, 12.70725, NULL, 0),
(@PATH, 4, 1011.471, 1244.149, 12.70725, NULL, 0),
(@PATH, 5, 996.2952, 1241.528, 13.73922, NULL, 0),
(@PATH, 6, 986.7795, 1240.28, 14.65292, NULL, 0),
(@PATH, 7, 973.2327, 1239.49, 14.65292, NULL, 0),
(@PATH, 8, 963.9566, 1240.326, 14.86794, NULL, 0),
(@PATH, 9, 973.2327, 1239.49, 14.65292, NULL, 0);

UPDATE `creature` SET `position_x`= 986.7795, `position_y`= 1240.28, `position_z`= 14.65292, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+88;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+88;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+88, @PATH, 1);

-- Waypoints for CGUID+125
SET @PATH := (@CGUID+125) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1113.278, 1167.554, 14.8971, NULL, 0),
(@PATH, 1, 1111.417, 1154.887, 15.00158, NULL, 0),
(@PATH, 2, 1113.278, 1167.554, 14.8971, NULL, 0),
(@PATH, 3, 1113.483, 1177.689, 14.8971, NULL, 0),
(@PATH, 4, 1112.736, 1191.962, 15.0221, NULL, 0),
(@PATH, 5, 1113.802, 1205.576, 15.00422, NULL, 0),
(@PATH, 6, 1112.736, 1191.962, 15.0221, NULL, 0),
(@PATH, 7, 1113.483, 1177.689, 14.8971, NULL, 0);

UPDATE `creature` SET `position_x`= 1113.278, `position_y`= 1167.554, `position_z`= 14.8971, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+125;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+125;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+125, @PATH, 1);

-- Waypoints for CGUID+100
SET @PATH := (@CGUID+100) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1086.564, 1237.932, 14.98883, NULL, 0),
(@PATH, 1, 1076.757, 1240.653, 14.43695, NULL, 0),
(@PATH, 2, 1064.466, 1247.338, 13.13039, NULL, 0),
(@PATH, 3, 1051.616, 1247.401, 12.88039, NULL, 0),
(@PATH, 4, 1064.326, 1247.417, 13.12783, NULL, 0),
(@PATH, 5, 1076.757, 1240.653, 14.43695, NULL, 0),
(@PATH, 6, 1086.564, 1237.932, 14.98883, NULL, 0),
(@PATH, 7, 1099.125, 1232.693, 14.99928, NULL, 0);

UPDATE `creature` SET `position_x`= 1086.564, `position_y`= 1237.932, `position_z`= 14.98883, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+100;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+100;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+100, @PATH, 1);