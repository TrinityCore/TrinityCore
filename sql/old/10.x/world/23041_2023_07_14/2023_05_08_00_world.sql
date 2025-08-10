SET @CGUID := 9003524;

SET @NPCTEXTID := 590072;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+326;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 200489, 2454, 14022, 14711, '0', 0, 0, 0, 0, 76.13889312744140625, 924.5711669921875, 102.8847274780273437, 0.751686811447143554, 120, 0, 0, 790433, 0, 0, 0, 0, 0, 49444), -- Crystal Terror (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+1, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -15.7209358215332031, 787.7603759765625, 119.9045028686523437, 2.907687664031982421, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 398627 - Startled!) (possible waypoints or random movement)
(@CGUID+2, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -38.9997787475585937, 782.3360595703125, 123.2649383544921875, 2.212232112884521484, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+3, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -42.5782089233398437, 766.45941162109375, 120.6356201171875, 5.141930580139160156, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 398627 - Startled!) (possible waypoints or random movement)
(@CGUID+4, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -17.7467041015625, 765.4024658203125, 146.3067474365234375, 2.372972488403320312, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 398627 - Startled!) (possible waypoints or random movement)
(@CGUID+5, 200477, 2454, 14022, 14711, '0', 0, 0, 0, 0, 1.410702705383300781, 885.71160888671875, 105.2301864624023437, 2.579885482788085937, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Frilled Gemtooth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -27.3940982818603515, 761.65106201171875, 151.3666839599609375, 1.691483259201049804, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 200477, 2454, 14022, 14711, '0', 0, 0, 0, 0, -6.458984375, 746.2255859375, 90.730743408203125, 2.469708442687988281, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Frilled Gemtooth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 200121, 2454, 14022, 14644, '0', 0, 0, 0, 0, -324.484375, 1406.782958984375, -94.1211776733398437, 1.040601968765258789, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+9, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -77.6331329345703125, 812.6148681640625, 119.9045028686523437, 2.172441482543945312, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 398627 - Startled!) (possible waypoints or random movement)
(@CGUID+10, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -85.8331680297851562, 789.0948486328125, 119.5619430541992187, 5.499911785125732421, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 398627 - Startled!) (possible waypoints or random movement)
(@CGUID+11, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -14.083632469177246, 771.92388916015625, 117.1322021484375, 1.059682965278625488, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 398627 - Startled!) (possible waypoints or random movement)
(@CGUID+12, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -37.912261962890625, 776.53997802734375, 146.1793670654296875, 0.097912311553955078, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 398627 - Startled!) (possible waypoints or random movement)
(@CGUID+13, 200489, 2454, 14022, 14711, '0', 0, 0, 0, 0, -118.144096374511718, 829.1475830078125, 74.84656524658203125, 4.770660877227783203, 120, 0, 0, 790433, 0, 0, 0, 0, 0, 49444), -- Crystal Terror (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+14, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -36.8854179382324218, 764.0225830078125, 150.7573089599609375, 0.343537509441375732, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+15, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -30.7951393127441406, 761.4305419921875, 147.8632659912109375, 1.063859343528747558, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+16, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -29.9068756103515625, 755.5970458984375, 149.863677978515625, 1.691483259201049804, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -32.5034713745117187, 765.13714599609375, 150.6356048583984375, 0.289450466632843017, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+18, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -87.7896957397460937, 812.2113037109375, 106.8594512939453125, 3.926990985870361328, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 398627 - Startled!) (possible waypoints or random movement)
(@CGUID+19, 200498, 2454, 14022, 14711, '0', 0, 0, 0, 0, -53.8576240539550781, 846.852783203125, 78.59561920166015625, 5.962194442749023437, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Gemtooth Neonate (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -77.1631011962890625, 819.58062744140625, 115.405792236328125, 3.136304855346679687, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 398627 - Startled!) (possible waypoints or random movement)
(@CGUID+21, 200121, 2454, 14022, 14644, '0', 0, 0, 0, 0, -272.270843505859375, 1462.09033203125, -92.6138763427734375, 0, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+22, 200489, 2454, 14022, 14711, '0', 0, 0, 0, 0, -99.1663742065429687, 1006.69720458984375, 48.06095123291015625, 1.334340214729309082, 120, 0, 0, 790433, 0, 0, 0, 0, 0, 49444), -- Crystal Terror (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+23, 200489, 2454, 14022, 14711, '0', 0, 0, 0, 0, 49.03298568725585937, 1017.03472900390625, 100.7639541625976562, 1.628037214279174804, 120, 0, 0, 790433, 0, 0, 0, 0, 0, 49444), -- Crystal Terror (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+24, 200498, 2454, 14022, 14711, '0', 0, 0, 0, 0, -68.8079376220703125, 858.17535400390625, 73.44794464111328125, 4.063051700592041015, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Gemtooth Neonate (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, 74.693328857421875, 811.93603515625, 131.129302978515625, 2.568153858184814453, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -53.6649322509765625, 902.6319580078125, 140.8960418701171875, 5.198512077331542968, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+27, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -49.6440963745117187, 902.015625, 143.66839599609375, 4.424102306365966796, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+28, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -55.3454856872558593, 899.65625, 144.3994598388671875, 5.826136589050292968, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+29, 200477, 2454, 14022, 14711, '0', 0, 0, 0, 0, 49.48611068725585937, 881.3680419921875, 100.75390625, 6.026151657104492187, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Frilled Gemtooth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+30, 200498, 2454, 14022, 14711, '0', 0, 0, 0, 0, 46.75516891479492187, 884.43914794921875, 101.0189361572265625, 4.129260540008544921, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Gemtooth Neonate (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+31, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, 48.14334487915039062, 878.52734375, 101.5705718994140625, 3.222077369689941406, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+32, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, 46.37651443481445312, 878.4786376953125, 102.5309982299804687, 2.779797554016113281, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+33, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, 90.5874481201171875, 881.97747802734375, 141.972503662109375, 2.143124341964721679, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+34, 200498, 2454, 14022, 14711, '0', 0, 0, 0, 0, 47.76523590087890625, 881.837890625, 102.5751800537109375, 6.016654014587402343, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Gemtooth Neonate (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+35, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, 44.13356399536132812, 879.46160888671875, 101.408233642578125, 2.150188922882080078, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+36, 200477, 2454, 14022, 14711, '0', 0, 0, 0, 0, 116.9913177490234375, 864.85418701171875, 100.7768325805664062, 4.374689102172851562, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Frilled Gemtooth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+37, 200498, 2454, 14022, 14711, '0', 0, 0, 0, 0, 119.894287109375, 864.102294921875, 100.8182449340820312, 6.029750347137451171, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Gemtooth Neonate (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+38, 200477, 2454, 14022, 14711, '0', 0, 0, 0, 0, 150.6961822509765625, 925.295166015625, 100.704559326171875, 1.73146212100982666, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Frilled Gemtooth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+39, 200477, 2454, 14022, 14711, '0', 0, 0, 0, 0, 19.00694465637207031, 979.30035400390625, 100.0467910766601562, 2.337865591049194335, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Frilled Gemtooth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+40, 200498, 2454, 14022, 14711, '0', 0, 0, 0, 0, 149.168121337890625, 922.6785888671875, 100.5712890625, 4.184033393859863281, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Gemtooth Neonate (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+41, 200498, 2454, 14022, 14711, '0', 0, 0, 0, 0, 149.7678375244140625, 922.41497802734375, 100.4677734375, 4.400826454162597656, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Gemtooth Neonate (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+42, 200489, 2454, 14022, 14711, '0', 0, 0, 0, 0, -106.026039123535156, 1100.8125, 41.50966262817382812, 1.85770881175994873, 120, 0, 0, 790433, 0, 0, 0, 0, 0, 49444), -- Crystal Terror (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+43, 200477, 2454, 14022, 14711, '0', 0, 0, 0, 0, 80.29514312744140625, 1009.296875, 100.1911849975585937, 0.97515958547592163, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Frilled Gemtooth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+44, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -52.1069793701171875, 951.8079833984375, 125.1107330322265625, 4.620948314666748046, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+45, 200498, 2454, 14022, 14711, '0', 0, 0, 0, 0, 23.93834114074707031, 971.750244140625, 99.9958038330078125, 5.290812492370605468, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Gemtooth Neonate (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+46, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, 43.858001708984375, 1034.59765625, 124.1531448364257812, 5.033066749572753906, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 200498, 2454, 14022, 14711, '0', 0, 0, 0, 0, 79.64669036865234375, 1006.3511962890625, 100.1380844116210937, 4.495777130126953125, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Gemtooth Neonate (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+48, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -14.0102701187133789, 1064.8643798828125, 101.520782470703125, 6.187424182891845703, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+49, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, 6.641357421875, 1079.5660400390625, 84.77346038818359375, 5.398793697357177734, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+50, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -77.9935302734375, 961.0963134765625, 66.2465057373046875, 0.497547775506973266, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+51, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, 73.858489990234375, 1095.3668212890625, 78.974273681640625, 0.34063035249710083, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+52, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, -41.949127197265625, 1053.2393798828125, 53.44139862060546875, 1.32818615436553955, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+53, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -76.9134902954101562, 1038.697509765625, 91.77162933349609375, 2.750178098678588867, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+54, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, 52.22569656372070312, 1104.6041259765625, 56.95672225952148437, 6.21304178237915039, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+55, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, 15.607452392578125, 1103.6826171875, 58.06044387817382812, 2.967771291732788085, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+56, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -48.1788215637207031, 906.30902099609375, 143.66839599609375, 4.424102306365966796, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+57, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, -93.9538803100585937, 1046.9224853515625, 118.1329345703125, 4.543187618255615234, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+58, 200477, 2454, 14022, 14711, '0', 0, 0, 0, 0, -118.986106872558593, 1007.09027099609375, 50.5131988525390625, 2.157790899276733398, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Frilled Gemtooth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+59, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -51.6024322509765625, 904.71356201171875, 139.16961669921875, 4.422686576843261718, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+60, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -59.2899322509765625, 905.11456298828125, 143.32586669921875, 5.826136589050292968, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+61, 200570, 2454, 14022, 14711, '0', 0, 0, 0, 0, -57.8602790832519531, 904.7401123046875, 139.2562103271484375, 5.013448238372802734, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flutterer (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+62, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, -14.3683948516845703, 1106.033935546875, 68.7995147705078125, 3.61827707290649414, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+63, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, -121.870613098144531, 1050.24951171875, 43.09929275512695312, 3.237377166748046875, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+64, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, -124.194442749023437, 1079.357666015625, 44.16148757934570312, 4.05571603775024414, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+65, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, 29.09679412841796875, 1133.154052734375, 64.481292724609375, 2.548143386840820312, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+66, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, 35.07638931274414062, 1164.454833984375, 56.12188720703125, 5.609613418579101562, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+67, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, -69.7657089233398437, 1204.9544677734375, 30.59257316589355468, 5.180576801300048828, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+68, 200120, 2454, 14022, 14711, '0', 0, 0, 0, 0, 15.01397037506103515, 1151.721923828125, 103.3113174438476562, 3.966427803039550781, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+69, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, -45.833984375, 1213.541015625, 28.77889442443847656, 4.181853771209716796, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+70, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, -61.1233253479003906, 1177.7674560546875, 33.00667190551757812, 1.040260910987854003, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+71, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 6.949652671813964843, 1148.8646240234375, 54.07814788818359375, 4.00322580337524414, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+72, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, 51.16473770141601562, 1080.7589111328125, 61.11008071899414062, 3.348283052444458007, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+73, 205078, 2454, 14022, 14711, '0', 0, 0, 0, 0, 49.34931182861328125, 1192.9443359375, 55.74987411499023437, 4.250702857971191406, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Crystal Snapper Matriarch (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+74, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, -0.521484375, 1175.68798828125, 45.57250595092773437, 4.712388992309570312, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+75, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, 97.54697418212890625, 1113.898193359375, 59.67631912231445312, 4.667453765869140625, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+76, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, 0.522569179534912109, 1222.0035400390625, 35.05677032470703125, 6.213041305541992187, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+77, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 43.77777862548828125, 1158.12158203125, 55.1248626708984375, 3.936384201049804687, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+78, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 76.41146087646484375, 1068.6007080078125, 62.57546615600585937, 3.005506277084350585, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+79, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 25.55555534362792968, 1180.5885009765625, 55.83828353881835937, 1.528963327407836914, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 403021 - Inoculated)
(@CGUID+80, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 78.93576812744140625, 1066.375, 62.78083038330078125, 4.319735050201416015, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+81, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 60.84375, 1163.78125, 58.687744140625, 0.246039867401123046, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+82, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, 26.74083328247070312, 1229.6103515625, 59.51294708251953125, 5.971883773803710937, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+83, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 79.2881927490234375, 1139.638916015625, 62.36854171752929687, 1.401195526123046875, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+84, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, 22.72641944885253906, 1240.133056640625, 40.80953598022460937, 1.019276618957519531, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+85, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 93.05902862548828125, 1070.5416259765625, 59.96407699584960937, 4.299775123596191406, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+86, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, 23.36458396911621093, 1256.2135009765625, 32.31597900390625, 0.541071236133575439, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+87, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 43.33333206176757812, 1239.0382080078125, 39.07309722900390625, 0.162843778729438781, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+88, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, -4.90765094757080078, 1283.752197265625, 31.86132431030273437, 1.26914381980895996, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+89, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, -38.7881965637207031, 1232.7274169921875, 26.47628211975097656, 2.60151076316833496, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+90, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, -20.2465286254882812, 1288.21875, 22.59617805480957031, 2.896807670593261718, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 403021 - Inoculated)
(@CGUID+91, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, -77.7395553588867187, 1281.4998779296875, 42.638214111328125, 5.462140083312988281, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+92, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, -0.8333333134651184, 1306.7239990234375, 25.26618766784667968, 0.022908510640263557, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+93, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, -115.940605163574218, 1259.638916015625, 72.099365234375, 5.051777362823486328, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+94, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, -103.316513061523437, 1223.5341796875, 23.73666954040527343, 5.819538116455078125, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+95, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, -98.9512176513671875, 1288.6865234375, 20.77772903442382812, 4.495839118957519531, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+96, 204926, 2454, 14022, 14711, '0', 0, 0, 0, 0, -73.4670181274414062, 1320.236083984375, 21.70709800720214843, 0, 120, 0, 0, 5, 0, 0, 0, 0, 0, 49444), -- Delver Mardei (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+97, 204930, 2454, 14022, 14711, '0', 0, 0, 0, 0, -73.7447891235351562, 1322.0538330078125, 21.61764144897460937, 0, 120, 0, 0, 5, 0, 0, 0, 0, 0, 49444), -- Tempe (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+98, 204929, 2454, 14022, 14711, '0', 0, 0, 0, 0, -73.71875, 1318.1597900390625, 21.3320770263671875, 0, 120, 0, 0, 5, 0, 0, 0, 0, 0, 49444), -- Dustie (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+99, 204933, 2454, 14022, 14711, '0', 0, 0, 0, 0, -73.7638931274414062, 1319.1632080078125, 21.77054405212402343, 0, 120, 0, 0, 5, 0, 0, 0, 0, 0, 49444), -- Swoggy (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+100, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, -73.7246246337890625, 1333.3330078125, 21.45333480834960937, 3.141592741012573242, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+101, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, -18.6634254455566406, 1352.09765625, 23.1968841552734375, 2.59030318260192871, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+102, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, 13.56617450714111328, 1313.55322265625, 28.2170867919921875, 5.684497356414794921, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+103, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, 12.06451034545898437, 1367.6448974609375, 38.75590133666992187, 0.922881722450256347, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+104, 205078, 2454, 14022, 14711, '0', 0, 0, 0, 0, -67.2112274169921875, 1371.9658203125, 20.02865028381347656, 3.596558809280395507, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Crystal Snapper Matriarch (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+105, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, -25.296875, 1313.842041015625, 21.288909912109375, 3.512310266494750976, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+106, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, -37.8836822509765625, 1284.388916015625, 21.4942779541015625, 0.356879025697708129, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 403021 - Inoculated)
(@CGUID+107, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 10.91145801544189453, 1243.704833984375, 31.91591453552246093, 0.890315532684326171, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+108, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, -19.0659732818603515, 1290.9791259765625, 22.7478790283203125, 4.655829429626464843, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1 (Auras: 403021 - Inoculated)
(@CGUID+109, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, -32.15625, 1314.0816650390625, 20.9341888427734375, 5.669567584991455078, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+110, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, -37.0555572509765625, 1282.8663330078125, 21.68285751342773437, 1.167921781539916992, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+111, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, 120.4387283325195312, 1075.9737548828125, 59.37535858154296875, 5.097958564758300781, 120, 6, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+112, 205061, 2454, 14022, 14711, '0', 0, 0, 0, 0, 119.6319427490234375, 1083.7916259765625, 59.14679718017578125, 0.356879025697708129, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Awaken Crystal (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+113, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, -122.546493530273437, 1234.3157958984375, 23.12812423706054687, 5.762172222137451171, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+114, 205082, 2454, 14022, 14711, '0', 0, 0, 0, 0, -122.981712341308593, 1249.9881591796875, 18.55944252014160156, 1.421858072280883789, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Crystalfur Murine (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+115, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, -204.765167236328125, 1315.0302734375, 2.3844757080078125, 5.839343070983886718, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+116, 205065, 2454, 14022, 14711, '0', 0, 0, 0, 0, -230.458786010742187, 1332.787109375, 1.825215578079223632, 0.944179356098175048, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Praying Stingray (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+117, 205079, 2454, 14022, 14711, '0', 0, 0, 0, 0, -165.340835571289062, 1263.140380859375, 14.80889606475830078, 2.439392566680908203, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Crystal Snapper (Area: The Throughway - Difficulty: 0) CreateObject1
(@CGUID+118, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, -43.8679847717285156, 1546.9815673828125, -63.119720458984375, 1.931729912757873535, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+119, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, -1.918046236038208, 1505.76171875, -54.5854072570800781, 5.633439540863037109, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+120, 200113, 2454, 14022, 14022, '0', 0, 0, 0, 0, 20.25543212890625, 1568.8973388671875, -61.2096481323242187, 4.652097225189208984, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+121, 200113, 2454, 14022, 14022, '0', 0, 0, 0, 0, -263.005615234375, 1427.923828125, -92.6578445434570312, 4.600869655609130859, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+122, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, 9.269097328186035156, 1474.41845703125, -50.6368331909179687, 0, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+123, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, 25.91947746276855468, 1533.4212646484375, -57.9373588562011718, 2.769364356994628906, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+124, 200120, 2454, 14022, 14022, '0', 0, 0, 0, 0, -208.942703247070312, 1494.0208740234375, -53.5996246337890625, 0, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+125, 205445, 2454, 14022, 14022, '0', 0, 0, 0, 0, 49.12326431274414062, 1484.79345703125, -49.5379867553710937, 4.106362819671630859, 120, 0, 0, 5, 0, 0, 0, 0, 0, 49444), -- Lickable Snail (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+126, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, 11.1724557876586914, 1570.1484375, -60.9429550170898437, 0.859056591987609863, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+127, 200120, 2454, 14022, 14022, '0', 0, 0, 0, 0, 11.86979198455810546, 1479.204833984375, -32.7578697204589843, 2.730523109436035156, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+128, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, -68.0260391235351562, 1509.32470703125, -56.3554725646972656, 0, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+129, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, -50.7629051208496093, 1586.67529296875, -66.9705734252929687, 6.006494045257568359, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+130, 199809, 2454, 14022, 14022, '0', 0, 0, 0, 0, 34.17827224731445312, 1525.077880859375, -41.2029304504394531, 5.412187576293945312, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+131, 200113, 2454, 14022, 14022, '0', 0, 0, 0, 0, -202.068756103515625, 1567.763427734375, -93.1447982788085937, 4.717390060424804687, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+132, 200113, 2454, 14022, 14022, '0', 0, 0, 0, 0, -180.738922119140625, 1530.7806396484375, -93.8781356811523437, 3.867586612701416015, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+133, 200120, 2454, 14022, 14022, '0', 0, 0, 0, 0, 11.86979198455810546, 1565.170166015625, -32.6710891723632812, 0.98153090476989746, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+134, 200113, 2454, 14022, 14022, '0', 0, 0, 0, 0, 1.744941949844360351, 1447.838623046875, -49.5439910888671875, 3.789883136749267578, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+135, 200120, 2454, 14022, 14022, '0', 0, 0, 0, 0, -148.451385498046875, 1415.9010009765625, -1.6805046796798706, 0.953691840171813964, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+136, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, -26.0776538848876953, 1499.7943115234375, -54.1201667785644531, 0.01074177399277687, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+137, 200121, 2454, 14022, 14022, '0', 0, 0, 0, 0, -45.3177070617675781, 1424.3489990234375, -38.655426025390625, 1.815496087074279785, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+138, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, -27.5510063171386718, 1599.117431640625, -64.3587722778320312, 3.634078502655029296, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+139, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, 16.666015625, 1579.166015625, -62.1292037963867187, 3.66125655174255371, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+140, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, -2.21875, 1598.09033203125, -63.3093223571777343, 2.266144990921020507, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@CGUID+141, 200113, 2454, 14022, 14022, '0', 0, 0, 0, 0, 45.7260284423828125, 1601.1275634765625, -60.3609161376953125, 4.835774898529052734, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+142, 200113, 2454, 14022, 14022, '0', 0, 0, 0, 0, 108.5129165649414062, 1559.8834228515625, -66.6575241088867187, 5.981280326843261718, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+143, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, 37.34231185913085937, 1615.9539794921875, -59.8023796081542968, 2.714391469955444335, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+144, 200113, 2454, 14022, 14022, '0', 0, 0, 0, 0, 38.77528762817382812, 1646.025146484375, -56.68365478515625, 0.629442334175109863, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+145, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, 82.0999908447265625, 1547.9619140625, -63.982330322265625, 2.589340448379516601, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+146, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, 84.79116058349609375, 1528.8021240234375, -60.1542892456054687, 2.107866764068603515, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+147, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, 33.468902587890625, 1606.704345703125, -60.01287841796875, 1.868146419525146484, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+148, 201081, 2454, 14022, 14022, '0', 0, 0, 0, 0, 6.490457534790039062, 1631.89453125, -63.3093833923339843, 0.718486547470092773, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Zaralek Cavern - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+149, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, -111.959442138671875, 1630.787353515625, -73.7893600463867187, 4.124386787414550781, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+150, 200120, 2454, 14022, 14683, '0', 0, 0, 0, 0, -57.3680572509765625, 1647.454833984375, -32.5696983337402343, 0.915592670440673828, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+151, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 85.46868896484375, 1585.4132080078125, -65.8897171020507812, 3.97326064109802246, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+152, 199809, 2454, 14022, 14683, '0', 0, 0, 0, 0, 88.2391815185546875, 1600.4161376953125, -53.7018852233886718, 2.180788040161132812, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+153, 200120, 2454, 14022, 14683, '0', 0, 0, 0, 0, 22.97048568725585937, 1647.454833984375, -30.1403121948242187, 3.108266830444335937, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+154, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, -22.3830947875976562, 1659.9007568359375, -67.47076416015625, 0.53974926471710205, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+155, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 40.9453125, 1650.5927734375, -55.88153076171875, 3.743160963058471679, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+156, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, -15.474771499633789, 1667.172607421875, -66.335205078125, 2.935137033462524414, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+157, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 10.93343067169189453, 1665.7459716796875, -64.247955322265625, 2.401416778564453125, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+158, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, -62.9501914978027343, 1657.8179931640625, -72.3266372680664062, 1.878341555595397949, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+159, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 51.65972137451171875, 1675.9896240234375, -64.9668121337890625, 0, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+160, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, -74.7195968627929687, 1666.18701171875, -74.8685379028320312, 3.841328620910644531, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+161, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 127.7162322998046875, 1598.609375, -67.9852066040039062, 5.790699958801269531, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+162, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 89.51731109619140625, 1664.21630859375, -66.5229721069335937, 0.520479142665863037, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+163, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 89.69271087646484375, 1655.0867919921875, -62.5873489379882812, 2.742056608200073242, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+164, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 125.3264694213867187, 1616.5648193359375, -71.7986984252929687, 2.594803810119628906, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+165, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 55.85763931274414062, 1685.0867919921875, -68.0953369140625, 0, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+166, 200113, 2454, 14022, 14683, '0', 0, 0, 0, 0, 132.5732421875, 1701.2579345703125, -84.938201904296875, 6.041523456573486328, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+167, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 127.4357528686523437, 1649.91162109375, -76.4033660888671875, 2.566976785659790039, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+168, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 147.2274322509765625, 1611.6007080078125, -69.5226593017578125, 0, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+169, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 100, 1683.3330078125, -82.1875457763671875, 2.452837944030761718, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+170, 200120, 2454, 14022, 14683, '0', 0, 0, 0, 0, 91.6475677490234375, 1704.217041015625, -53.6155891418457031, 0.973894596099853515, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+171, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 65.87277984619140625, 1711.9517822265625, -75.2301254272460937, 0.411179393529891967, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+172, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 66.6255340576171875, 1711.88525390625, -75.15118408203125, 2.175701141357421875, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+173, 199809, 2454, 14022, 14683, '0', 0, 0, 0, 0, 43.25561904907226562, 1718.13671875, -61.0842781066894531, 6.260081291198730468, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+174, 199809, 2454, 14022, 14683, '0', 0, 0, 0, 0, 172.0263519287109375, 1680.786865234375, -76.320831298828125, 1.742000699043273925, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+175, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 41.39130783081054687, 1727.3306884765625, -76.49212646484375, 4.685052394866943359, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+176, 200120, 2454, 14022, 14683, '0', 0, 0, 0, 0, 194.8645782470703125, 1672.9410400390625, -51.5878486633300781, 1.0471879243850708, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+177, 205445, 2454, 14022, 14683, '0', 0, 0, 0, 0, 188.0729217529296875, 1689.85595703125, -83.5583648681640625, 1.182236909866333007, 120, 0, 0, 5, 0, 0, 0, 0, 0, 49444), -- Lickable Snail (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+178, 200113, 2454, 14022, 14683, '0', 0, 0, 0, 0, 229.9544525146484375, 1710.54638671875, -98.2523269653320312, 3.940258502960205078, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+179, 200113, 2454, 14022, 14683, '0', 0, 0, 0, 0, 267.258544921875, 1609.4786376953125, -93.8663864135742187, 1.109187841415405273, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+180, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 200.1805572509765625, 1688.71875, -90.461334228515625, 0, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+181, 200113, 2454, 14022, 14683, '0', 0, 0, 0, 0, 134.242431640625, 1797.200927734375, -82.1975631713867187, 2.695045948028564453, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+182, 200113, 2454, 14022, 14683, '0', 0, 0, 0, 0, 173.4172210693359375, 1807.0052490234375, -79.127471923828125, 1.334090709686279296, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+183, 200120, 2454, 14022, 14683, '0', 0, 0, 0, 0, 116.8819427490234375, 1772.467041015625, -52.5963096618652343, 3.349797487258911132, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+184, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, 252.70660400390625, 1698.9114990234375, -97.1392593383789062, 0, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+185, 199809, 2454, 14022, 14683, '0', 0, 0, 0, 0, 278.762115478515625, 1694.6119384765625, -92.2447128295898437, 0.920354664325714111, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+186, 200121, 2454, 14022, 14683, '0', 0, 0, 0, 0, 101.7760391235351562, 1761.328125, -85.5208740234375, 3.208853006362915039, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+187, 200113, 2454, 14022, 14683, '0', 0, 0, 0, 0, 100.136932373046875, 1845.60400390625, -82.8413467407226562, 2.743648290634155273, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+188, 200898, 2454, 14022, 14683, '0', 0, 0, 0, 0, 88.17453765869140625, 1806.1375732421875, -85.53350830078125, 0.895445168018341064, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Redolent Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+189, 200120, 2454, 14022, 14683, '0', 0, 0, 0, 0, 221.1614532470703125, 1795.9635009765625, -70.99176025390625, 1.01707768440246582, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+190, 199809, 2454, 14022, 14683, '0', 0, 0, 0, 0, 140.091949462890625, 1818.1409912109375, -62.4125289916992187, 5.434158802032470703, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+191, 200120, 2454, 14022, 14683, '0', 0, 0, 0, 0, 258.397216796875, 1756.7572021484375, -99.5602569580078125, 5.601494789123535156, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+192, 200120, 2454, 14022, 14683, '0', 0, 0, 0, 0, 285.088531494140625, 1745.3021240234375, -71.53741455078125, 3.26168060302734375, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+193, 200120, 2454, 14022, 14683, '0', 0, 0, 0, 0, 288.111114501953125, 1631.0625, -75.1653594970703125, 0, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+194, 200121, 2454, 14022, 14683, '0', 0, 0, 0, 0, 184.90972900390625, 1810.751708984375, -80.0578765869140625, 3.347127676010131835, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+195, 200121, 2454, 14022, 14683, '0', 0, 0, 0, 0, 272.758697509765625, 1729.390625, -107.984077453613281, 3.090852022171020507, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+196, 200113, 2454, 14022, 14683, '0', 0, 0, 0, 0, 315.985382080078125, 1584.15869140625, -93.0373687744140625, 1.184489727020263671, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+197, 199809, 2454, 14022, 14683, '0', 0, 0, 0, 0, 275.196533203125, 1595.978759765625, -85.4749984741210937, 3.612870216369628906, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+198, 199809, 2454, 14022, 14683, '0', 0, 0, 0, 0, 335.586639404296875, 1672.0491943359375, -116.333450317382812, 2.033136367797851562, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+199, 200113, 2454, 14022, 14645, '0', 0, 0, 0, 0, 304.14727783203125, 1527.364990234375, -95.234405517578125, 5.497121810913085937, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Deepflayer Nest - Difficulty: 0) CreateObject1
(@CGUID+200, 199809, 2454, 14022, 14645, '0', 0, 0, 0, 0, 295.373199462890625, 1547.4554443359375, -93.89788818359375, 3.959325313568115234, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Swooping Flayer (Area: Deepflayer Nest - Difficulty: 0) CreateObject1
(@CGUID+201, 205122, 2454, 14022, 14683, '0', 0, 0, 0, 0, 81.40734100341796875, 1815.7237548828125, -84.2114028930664062, 1.492739319801330566, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Underlight Flickerwing (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+202, 200120, 2454, 14022, 14683, '0', 0, 0, 0, 0, 84.40103912353515625, 1866.8055419921875, -55.3894538879394531, 0.899344146251678466, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+203, 200898, 2454, 14022, 14683, '0', 0, 0, 0, 0, 4.020284652709960937, 1787.3807373046875, -82.0731582641601562, 5.916642665863037109, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Redolent Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+204, 200898, 2454, 14022, 14683, '0', 0, 0, 0, 0, -11.5020618438720703, 1858.723876953125, -79.1926956176757812, 2.346797943115234375, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Redolent Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+205, 205445, 2454, 14022, 14683, '0', 0, 0, 0, 0, -38.6822929382324218, 1810.986083984375, -82.8294830322265625, 5.439356327056884765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 49444), -- Lickable Snail (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+206, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, -17.5046672821044921, 1718.851806640625, -75.6417999267578125, 2.148825645446777343, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+207, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, -17.3865222930908203, 1700.837646484375, -69.7494125366210937, 4.681033611297607421, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+208, 200898, 2454, 14022, 14683, '0', 0, 0, 0, 0, -66.4775238037109375, 1759.6673583984375, -79.3830032348632812, 1.596181511878967285, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Redolent Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+209, 200898, 2454, 14022, 14683, '0', 0, 0, 0, 0, -74.698486328125, 1834.77197265625, -81.1642913818359375, 0.875905215740203857, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Redolent Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+210, 200898, 2454, 14022, 14683, '0', 0, 0, 0, 0, -75.024932861328125, 1972.7166748046875, -91.253662109375, 2.374825954437255859, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Redolent Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+211, 201081, 2454, 14022, 14683, '0', 0, 0, 0, 0, -37.9262542724609375, 1684.839599609375, -67.570404052734375, 4.076446533203125, 120, 8, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Slimy Whelk (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+212, 200113, 2454, 14022, 14683, '0', 0, 0, 0, 0, -181.687850952148437, 1660.7144775390625, -93.8497695922851562, 2.15054631233215332, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+213, 202930, 2454, 14022, 14683, '0', 0, 0, 0, 0, -205.826034545898437, 1646.4163818359375, -100.162483215332031, 0.577577412128448486, 120, 6, 0, 101627, 0, 1, 0, 0, 0, 49444), -- Deepdrifter Megrim (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+214, 200121, 2454, 14022, 14683, '0', 0, 0, 0, 0, -147.123260498046875, 1685.5382080078125, -83.2164688110351562, 1.229400873184204101, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+215, 200121, 2454, 14022, 14683, '0', 0, 0, 0, 0, -161.730911254882812, 1685.7569580078125, -86.16546630859375, 0, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+216, 199809, 2454, 14022, 0, '0', 0, 0, 0, 0, -201.091110229492187, 1600.3687744140625, -76.0275115966796875, 2.864270925521850585, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: 0 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+217, 202930, 2454, 14022, 0, '0', 0, 0, 0, 0, -258.463409423828125, 1621.3734130859375, -107.875663757324218, 1.427001714706420898, 120, 6, 0, 101627, 0, 1, 0, 0, 0, 49444), -- Deepdrifter Megrim (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+218, 202930, 2454, 14022, 0, '0', 0, 0, 0, 0, -251.491317749023437, 1564.623291015625, -101.104949951171875, 4.105816364288330078, 120, 6, 0, 101627, 0, 1, 0, 0, 0, 49444), -- Deepdrifter Megrim (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+219, 200113, 2454, 14022, 0, '0', 0, 0, 0, 0, -335.64984130859375, 1686.38720703125, -88.7795791625976562, 6.114998817443847656, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+220, 199809, 2454, 14022, 0, '0', 0, 0, 0, 0, -244.565750122070312, 1619.3206787109375, -76.9232559204101562, 5.442818641662597656, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+221, 202930, 2454, 14022, 0, '0', 0, 0, 0, 0, -275.394866943359375, 1575.4122314453125, -138.477859497070312, 3.646549463272094726, 120, 6, 0, 101627, 0, 1, 0, 0, 0, 49444), -- Deepdrifter Megrim (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+222, 200120, 2454, 14022, 14644, '0', 0, 0, 0, 0, -253.869796752929687, 1574.15283203125, -81.297149658203125, 2.62177443504333496, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+223, 199809, 2454, 14022, 14644, '0', 0, 0, 0, 0, -295.87420654296875, 1612.568603515625, -59.3974494934082031, 0.941985785961151123, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+224, 200898, 2454, 14022, 14644, '0', 0, 0, 0, 0, -311.13751220703125, 1617.4168701171875, -92.452545166015625, 0.28996133804321289, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Redolent Whelk (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+225, 199809, 2454, 14022, 14644, '0', 0, 0, 0, 0, -243.83233642578125, 1527.2508544921875, -81.8252792358398437, 5.260669231414794921, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Swooping Flayer (Area: Deephollow Lake - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+226, 200121, 2454, 14022, 14644, '0', 0, 0, 0, 0, -311.4375, 1621.4166259765625, -92.142120361328125, 0, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+227, 200120, 2454, 14022, 14644, '0', 0, 0, 0, 0, -339.21875, 1565.9427490234375, -96.4166793823242187, 0.819535613059997558, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+228, 200898, 2454, 14022, 14644, '0', 0, 0, 0, 0, -358.94677734375, 1736.463623046875, -83.7947235107421875, 5.681904792785644531, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Redolent Whelk (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+229, 202930, 2454, 14022, 14644, '0', 0, 0, 0, 0, -352.6024169921875, 1515.574951171875, -100.090469360351562, 2.42332005500793457, 120, 6, 0, 101627, 0, 1, 0, 0, 0, 49444), -- Deepdrifter Megrim (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+230, 200113, 2454, 14022, 14644, '0', 0, 0, 0, 0, -373.4375, 1525.5205078125, -92.8875885009765625, 5.961622238159179687, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+231, 200113, 2454, 14022, 14644, '0', 0, 0, 0, 0, -375.683013916015625, 1525.0054931640625, -92.4770050048828125, 0.429036974906921386, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+232, 201001, 2454, 14022, 14644, '0', 0, 0, 0, 0, -328.128265380859375, 1732.834716796875, -84.5873565673828125, 3.830821990966796875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 49444), -- Cobbleshell (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+233, 205445, 2454, 14022, 14644, '0', 0, 0, 0, 0, -303.75, 1523.05908203125, -90.7095184326171875, 1.331570386886596679, 120, 0, 0, 5, 0, 0, 0, 0, 0, 49444), -- Lickable Snail (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+234, 200120, 2454, 14022, 14644, '0', 0, 0, 0, 0, -405.076385498046875, 1649.9410400390625, -54.3330078125, 1.7313157320022583, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+235, 200120, 2454, 14022, 14644, '0', 0, 0, 0, 0, -408.451385498046875, 1642.28125, -54.8484039306640625, 0.762660086154937744, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+236, 200898, 2454, 14022, 14644, '0', 0, 0, 0, 0, -431.208770751953125, 1715.497314453125, -85.3161163330078125, 5.701775550842285156, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Redolent Whelk (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+237, 200120, 2454, 14022, 14644, '0', 0, 0, 0, 0, -328.515625, 1451.4947509765625, -59.396881103515625, 1.927976131439208984, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Underlight Moth (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+238, 200113, 2454, 14022, 14644, '0', 0, 0, 0, 0, -358.064453125, 1412.166015625, -92.4622116088867187, 2.003885746002197265, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+239, 200121, 2454, 14022, 14644, '0', 0, 0, 0, 0, -357.295135498046875, 1484.8819580078125, -95.1014328002929687, 0, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+240, 200113, 2454, 14022, 14644, '0', 0, 0, 0, 0, -321.148345947265625, 1401.5902099609375, -93.5710830688476562, 5.520438194274902343, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Scavenging Flayer (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+241, 200121, 2454, 14022, 14644, '0', 0, 0, 0, 0, -264.564239501953125, 1465.1163330078125, -91.77764892578125, 0, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: Deephollow Lake - Difficulty: 0) CreateObject1
(@CGUID+242, 203126, 2454, 14022, 14713, '0', 0, 0, 0, 0, 186.0377044677734375, 2143.1455078125, -125.169692993164062, 5.478075027465820312, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Mudslick Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+243, 203238, 2454, 14022, 14713, '0', 0, 0, 0, 0, 191.7823486328125, 2066.219482421875, -116.32080078125, 4.366263866424560546, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Temporal Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+244, 203237, 2454, 14022, 14713, '0', 0, 0, 0, 0, 196.0620269775390625, 2147.07177734375, -126.148796081542968, 5.551676750183105468, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Crimson Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+245, 203238, 2454, 14022, 14713, '0', 0, 0, 0, 0, 255.8980712890625, 2162.97265625, -130.333282470703125, 2.877654314041137695, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Temporal Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+246, 200898, 2454, 14022, 14713, '0', 0, 0, 0, 0, 130.1948089599609375, 1975.3779296875, -99.3611297607421875, 6.20393991470336914, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Redolent Whelk (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+247, 203222, 2454, 14022, 14713, '0', 0, 0, 0, 0, 234.8130645751953125, 2119.3681640625, -123.412612915039062, 1.794545650482177734, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Emerald Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+248, 203240, 2454, 14022, 14713, '0', 0, 0, 0, 0, 188.7454681396484375, 2098.83447265625, -119.722358703613281, 0.999048054218292236, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Prismatic Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+249, 203104, 2454, 14022, 14713, '0', 0, 0, 0, 0, 290.451568603515625, 2151.43017578125, -135.520553588867187, 1.259828686714172363, 120, 4, 0, 101627, 0, 1, 0, 0, 0, 49444), -- Shimmerfin Lurker (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+250, 203239, 2454, 14022, 14713, '0', 0, 0, 0, 0, 176.0443115234375, 2034.939453125, -108.550529479980468, 3.400308132171630859, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Primordial Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+251, 203241, 2454, 14022, 14713, '0', 0, 0, 0, 0, 181.6307830810546875, 2101.87255859375, -119.550491333007812, 4.510147571563720703, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Stone Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+252, 203126, 2454, 14022, 14713, '0', 0, 0, 0, 0, 265.268890380859375, 2157.144775390625, -131.497360229492187, 4.211172103881835937, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Mudslick Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+253, 203237, 2454, 14022, 14713, '0', 0, 0, 0, 0, 243.50689697265625, 2057.9990234375, -109.5228271484375, 3.796812057495117187, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Crimson Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+254, 203241, 2454, 14022, 14713, '0', 0, 0, 0, 0, 232.37579345703125, 2178.572021484375, -133.505401611328125, 1.332212686538696289, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Stone Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+255, 203239, 2454, 14022, 14713, '0', 0, 0, 0, 0, 258.48931884765625, 2065.349365234375, -108.15484619140625, 5.637746810913085937, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Primordial Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+256, 203240, 2454, 14022, 14713, '0', 0, 0, 0, 0, 342.370361328125, 2068.909423828125, -110.991065979003906, 1.923738479614257812, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Prismatic Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+257, 203104, 2454, 14022, 14713, '0', 0, 0, 0, 0, 307.03277587890625, 2122.68701171875, -135.811599731445312, 6.2812347412109375, 120, 4, 0, 101627, 0, 1, 0, 0, 0, 49444), -- Shimmerfin Lurker (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+258, 203241, 2454, 14022, 14713, '0', 0, 0, 0, 0, 216.600738525390625, 2116.793701171875, -122.744010925292968, 4.31401824951171875, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Stone Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+259, 203105, 2454, 14022, 14713, '0', 0, 0, 0, 0, 279.032989501953125, 2172.729248046875, -131.50726318359375, 5.416669368743896484, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Sharpspine Pincher (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+260, 203596, 2454, 14022, 14713, '0', 0, 0, 0, 0, 353.7213134765625, 2058.905029296875, -97.7426681518554687, 3.194971323013305664, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Blistering Shalewing (Area: Glitterspore Lake - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+261, 203104, 2454, 14022, 14713, '0', 0, 0, 0, 0, 328.9222412109375, 2133.817138671875, -135.513626098632812, 5.047057151794433593, 120, 4, 0, 101627, 0, 1, 0, 0, 0, 49444), -- Shimmerfin Lurker (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+262, 203105, 2454, 14022, 14713, '0', 0, 0, 0, 0, 266.711822509765625, 2202.51904296875, -130.1220703125, 3.421311855316162109, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Sharpspine Pincher (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+263, 203222, 2454, 14022, 14713, '0', 0, 0, 0, 0, 292.7449951171875, 2220.19384765625, -126.409133911132812, 6.13870859146118164, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Emerald Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+264, 203237, 2454, 14022, 14713, '0', 0, 0, 0, 0, 303.235321044921875, 2215.53955078125, -125.827804565429687, 0.942010045051574707, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Crimson Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+265, 203105, 2454, 14022, 14713, '0', 0, 0, 0, 0, 329.05157470703125, 2200.341064453125, -128.419601440429687, 3.359169483184814453, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Sharpspine Pincher (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+266, 203241, 2454, 14022, 14713, '0', 0, 0, 0, 0, 348.0909423828125, 2178.446044921875, -129.265533447265625, 5.059886455535888671, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Stone Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+267, 203240, 2454, 14022, 14713, '0', 0, 0, 0, 0, 357.556976318359375, 2158.97998046875, -128.41619873046875, 3.178685188293457031, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Prismatic Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+268, 203222, 2454, 14022, 14713, '0', 0, 0, 0, 0, 377.027740478515625, 2059.280517578125, -111.946929931640625, 0.857296168804168701, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Emerald Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+269, 203238, 2454, 14022, 14713, '0', 0, 0, 0, 0, 366.9617919921875, 2128.337646484375, -128.368972778320312, 4.666888713836669921, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Temporal Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+270, 203105, 2454, 14022, 14713, '0', 0, 0, 0, 0, 362.176971435546875, 2141.7626953125, -128.95587158203125, 4.926071643829345703, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Sharpspine Pincher (Area: Glitterspore Lake - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+271, 203237, 2454, 14022, 14713, '0', 0, 0, 0, 0, 385.3887939453125, 2079.503662109375, -118.371421813964843, 2.192636728286743164, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Crimson Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+272, 203240, 2454, 14022, 14713, '0', 0, 0, 0, 0, 380.728515625, 2135.799072265625, -128.378021240234375, 6.028277397155761718, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Prismatic Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+273, 203238, 2454, 14022, 14713, '0', 0, 0, 0, 0, 310.646636962890625, 2248.273193359375, -124.394477844238281, 3.917657375335693359, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Temporal Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+274, 203239, 2454, 14022, 14713, '0', 0, 0, 0, 0, 341.666015625, 2229.6875, -125.017227172851562, 0.57896578311920166, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Primordial Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+275, 203238, 2454, 14022, 14713, '0', 0, 0, 0, 0, 397.13018798828125, 2145.23583984375, -129.716156005859375, 2.030076980590820312, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Temporal Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+276, 203126, 2454, 14022, 14713, '0', 0, 0, 0, 0, 403.84906005859375, 2150.900146484375, -131.269287109375, 1.633258342742919921, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Mudslick Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+277, 203239, 2454, 14022, 14713, '0', 0, 0, 0, 0, 416.124237060546875, 2127.398193359375, -128.319046020507812, 0.763302326202392578, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Primordial Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+278, 203240, 2454, 14022, 14713, '0', 0, 0, 0, 0, 434.458648681640625, 2175.8740234375, -133.41595458984375, 4.473805427551269531, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Prismatic Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+279, 203237, 2454, 14022, 14713, '0', 0, 0, 0, 0, 404.615447998046875, 2036.103271484375, -108.488945007324218, 5.457890987396240234, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Crimson Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+280, 203596, 2454, 14022, 14713, '0', 0, 0, 0, 0, 415.715606689453125, 2035.47705078125, -104.970329284667968, 2.571427106857299804, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Blistering Shalewing (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+281, 203239, 2454, 14022, 14713, '0', 0, 0, 0, 0, 457.499053955078125, 2072.396240234375, -122.695693969726562, 0.05083678662776947, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Primordial Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+282, 203222, 2454, 14022, 14713, '0', 0, 0, 0, 0, 464.373016357421875, 2101.98193359375, -129.655670166015625, 2.985493898391723632, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Emerald Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+283, 203240, 2454, 14022, 14713, '0', 0, 0, 0, 0, 474.599029541015625, 2062.138427734375, -116.923446655273437, 3.886623859405517578, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Prismatic Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+284, 203241, 2454, 14022, 14713, '0', 0, 0, 0, 0, 484.148223876953125, 2036.9498291015625, -112.570999145507812, 5.688950061798095703, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Stone Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+285, 203222, 2454, 14022, 14713, '0', 0, 0, 0, 0, 513.22265625, 2081.206298828125, -120.761466979980468, 5.779314517974853515, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Emerald Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+286, 203222, 2454, 14022, 14713, '0', 0, 0, 0, 0, 513.01898193359375, 2151.276123046875, -148.52587890625, 0.455790966749191284, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Emerald Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+287, 203241, 2454, 14022, 14713, '0', 0, 0, 0, 0, 530.8924560546875, 2168.361083984375, -154.888153076171875, 5.322074413299560546, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Stone Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+288, 203238, 2454, 14022, 14713, '0', 0, 0, 0, 0, 451.456268310546875, 1966.993408203125, -101.998039245605468, 1.083135843276977539, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Temporal Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+289, 203237, 2454, 14022, 14713, '0', 0, 0, 0, 0, 551.99169921875, 2141.9462890625, -151.899673461914062, 2.734949588775634765, 120, 6, 0, 225838, 0, 1, 0, 0, 0, 49444), -- Crimson Infused Rock Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+290, 205169, 2454, 14022, 14713, '0', 0, 0, 0, 0, 590.93890380859375, 2135.154296875, -154.52435302734375, 5.465317726135253906, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 49444), -- Dirt Shell Snail (Area: Glitterspore Lake - Difficulty: 0) CreateObject1
(@CGUID+291, 205203, 2454, 14022, 0, '0', 0, 0, 0, 0, -132.45660400390625, 2266.6181640625, -118.384147644042968, 3.060044527053833007, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Azured Dawdler (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+292, 205202, 2454, 14022, 0, '0', 0, 0, 0, 0, -116.327285766601562, 2222.633544921875, -104.250022888183593, 0.507623374462127685, 120, 10, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: 0 - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+293, 205203, 2454, 14022, 0, '0', 0, 0, 0, 0, -69.4171600341796875, 2243.582275390625, -108.8011474609375, 0.581563353538513183, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Azured Dawdler (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+294, 205202, 2454, 14022, 0, '0', 0, 0, 0, 0, -212.306289672851562, 2170.039306640625, -100.811805725097656, 1.221568107604980468, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Brightwing Moth (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+295, 205202, 2454, 14022, 0, '0', 0, 0, 0, 0, -177.310867309570312, 2189.531982421875, -113.185340881347656, 5.09295511245727539, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+296, 205202, 2454, 14022, 0, '0', 0, 0, 0, 0, -65.1204910278320312, 2226.2451171875, -106.992958068847656, 2.285939216613769531, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+297, 205202, 2454, 14022, 0, '0', 0, 0, 0, 0, -46.3663215637207031, 2239.2744140625, -105.616317749023437, 5.784954547882080078, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Brightwing Moth (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+298, 200121, 2454, 14022, 0, '0', 0, 0, 0, 0, 447.59375, 1890.4722900390625, -97.325225830078125, 3.388467073440551757, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Prismatic Snailette (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+299, 205203, 2454, 14022, 14683, '0', 0, 0, 0, 0, -28.1770839691162109, 1987.3177490234375, -91.266021728515625, 5.531154155731201171, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Azured Dawdler (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+300, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, -1.01231205463409423, 1971.2174072265625, -79.4823989868164062, 1.709499359130859375, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+301, 205203, 2454, 14022, 14683, '0', 0, 0, 0, 0, -51.4635429382324218, 1998.236083984375, -89.6219024658203125, 3.455618619918823242, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Azured Dawdler (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+302, 205203, 2454, 14022, 14683, '0', 0, 0, 0, 0, -7.47714567184448242, 1996.604248046875, -94.1710586547851562, 5.260846138000488281, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Azured Dawdler (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+303, 205203, 2454, 14022, 14683, '0', 0, 0, 0, 0, 2.690972328186035156, 1962.3802490234375, -88.3211898803710937, 5.531154155731201171, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Azured Dawdler (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+304, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, -19.173095703125, 1999.0782470703125, -76.7110214233398437, 6.133948326110839843, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+305, 203225, 2454, 14022, 14683, '0', 0, 0, 0, 0, -60.4266471862792968, 1950.4459228515625, -90.6967315673828125, 5.312312126159667968, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Struggling Mothling (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (Auras: 405376 - [DNT] Ground Shadow Aura)
(@CGUID+306, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, -74.4867477416992187, 1993.412109375, -83.826812744140625, 6.197036266326904296, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+307, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, 15.318695068359375, 1961.8046875, -63.9003486633300781, 5.706989288330078125, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+308, 205203, 2454, 14022, 14683, '0', 0, 0, 0, 0, -92.234375, 1938.25, -91.1990203857421875, 3.979038000106811523, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Azured Dawdler (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+309, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, 15.04513931274414062, 1988.5972900390625, -93.8584823608398437, 3.984617233276367187, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+310, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, -60.0509986877441406, 1993.591064453125, -78.4397430419921875, 1.291469931602478027, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+311, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, 8.286458015441894531, 1984.126708984375, -92.31353759765625, 2.165853023529052734, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+312, 205203, 2454, 14022, 14683, '0', 0, 0, 0, 0, -58.4420127868652343, 2014.10986328125, -89.5025558471679687, 5.673258781433105468, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Azured Dawdler (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+313, 205203, 2454, 14022, 14683, '0', 0, 0, 0, 0, -54.8003463745117187, 2088.34375, -99.7205047607421875, 3.286528348922729492, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Azured Dawdler (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+314, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, -141.760360717773437, 2020.560546875, -82.100372314453125, 0.273226171731948852, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+315, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, -90.0126190185546875, 2065.71875, -87.5098190307617187, 3.965625762939453125, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+316, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, -122.628807067871093, 2071.869140625, -82.9504241943359375, 2.429430484771728515, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+317, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, -147.184356689453125, 2047.2882080078125, -86.088623046875, 5.272946834564208984, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+318, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, -95.954864501953125, 2116.59716796875, -95.9465789794921875, 3.026580333709716796, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+319, 205202, 2454, 14022, 14683, '0', 0, 0, 0, 0, -114.078460693359375, 2099.200927734375, -93.9449996948242187, 1.606200337409973144, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: Shimmering Towers - Difficulty: 0) CreateObject1
(@CGUID+320, 205202, 2454, 14022, 0, '0', 0, 0, 0, 0, -83.11273193359375, 2150.977294921875, -103.802909851074218, 6.106476783752441406, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+321, 205202, 2454, 14022, 0, '0', 0, 0, 0, 0, -147.85882568359375, 2129.197509765625, -68.677398681640625, 4.248561859130859375, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444), -- Brightwing Moth (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+322, 205203, 2454, 14022, 0, '0', 0, 0, 0, 0, -60.861968994140625, 2201.443359375, -107.413978576660156, 5.838766098022460937, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49444), -- Azured Dawdler (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+323, 205202, 2454, 14022, 0, '0', 0, 0, 0, 0, -212.583602905273437, 2155.48681640625, -102.808006286621093, 3.615905523300170898, 120, 4, 0, 33876, 0, 1, 0, 0, 0, 49444), -- Brightwing Moth (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+324, 205203, 2454, 14022, 0, '0', 0, 0, 0, 0, -183.244796752929687, 2190.994873046875, -114.027748107910156, 3.431637763977050781, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Azured Dawdler (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+325, 205203, 2454, 14022, 0, '0', 0, 0, 0, 0, -88.845489501953125, 2220.453125, -108.216087341308593, 3.669988393783569335, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49444), -- Azured Dawdler (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+326, 205202, 2454, 14022, 0, '0', 0, 0, 0, 0, -191.421875, 2175.560791015625, -109.357025146484375, 2.334579229354858398, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 49444); -- Brightwing Moth (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+326;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 438, 0, 0, 0, 3, ''), -- Crystal Terror
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Frilled Gemtooth
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Frilled Gemtooth
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Frilled Gemtooth
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Frilled Gemtooth
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 438, 0, 0, 0, 3, ''), -- Crystal Terror
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Frilled Gemtooth
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Crystal Snapper
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Frilled Gemtooth
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Crystalfur Murine
(@CGUID+66, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Crystal Snapper
(@CGUID+76, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Crystal Snapper
(@CGUID+86, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Crystal Snapper
(@CGUID+94, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Crystalfur Murine
(@CGUID+291, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Azured Dawdler
(@CGUID+297, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Brightwing Moth
(@CGUID+299, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Azured Dawdler
(@CGUID+301, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Azured Dawdler
(@CGUID+303, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Azured Dawdler
(@CGUID+305, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '405376'), -- Struggling Mothling - 405376 - [DNT] Ground Shadow Aura
(@CGUID+308, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Azured Dawdler
(@CGUID+309, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Brightwing Moth
(@CGUID+311, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Brightwing Moth
(@CGUID+313, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Azured Dawdler
(@CGUID+318, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Brightwing Moth
(@CGUID+324, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Azured Dawdler
(@CGUID+325, 0, 0, 0, 0, 0, 1, 0, 429, 0, 0, 0, 0, ''), -- Azured Dawdler
(@CGUID+326, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Brightwing Moth

-- Creature Template
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=204930; -- Tempe
UPDATE `creature_template` SET `faction`=3270, `npcflag`=129, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=204926; -- Delver Mardei
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=204929; -- Dustie
UPDATE `creature_template` SET `faction`=35, `speed_walk`=0.86666804552078247, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=204933; -- Swoggy
UPDATE `creature_template` SET `faction`=2125, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=205078; -- Crystal Snapper Matriarch
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=205061; -- Awaken Crystal
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=205082; -- Crystalfur Murine
UPDATE `creature_template` SET `faction`=2125, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=205079; -- Crystal Snapper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=205065; -- Praying Stingray
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=200498; -- Gemtooth Neonate
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=200477; -- Frilled Gemtooth
UPDATE `creature_template` SET `faction`=190, `speed_run`=3.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=200570; -- Underlight Flutterer
UPDATE `creature_template` SET `faction`=190, `speed_run`=3.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=200120; -- Underlight Moth
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=200489; -- Crystal Terror
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=201081; -- Slimy Whelk
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=200113; -- Scavenging Flayer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=199809; -- Swooping Flayer
UPDATE `creature_template` SET `faction`=188, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=205445; -- Lickable Snail
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=200121; -- Prismatic Snailette
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=16779264 WHERE `entry`=200898; -- Redolent Whelk
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=205122; -- Underlight Flickerwing
UPDATE `creature_template` SET `faction`=188, `speed_walk`=0.159999996423721313, `speed_run`=0.057142857462167739, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=201001; -- Cobbleshell
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_walk`=0.159999996423721313, `speed_run`=0.057142857462167739, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=203310; -- Cobbleshell
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=16779264 WHERE `entry`=203240; -- Prismatic Infused Rock Snail
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=16779264 WHERE `entry`=203222; -- Emerald Infused Rock Snail
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=16779264 WHERE `entry`=203237; -- Crimson Infused Rock Snail
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=16779264 WHERE `entry`=203238; -- Temporal Infused Rock Snail
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=16779264 WHERE `entry`=203241; -- Stone Infused Rock Snail
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=16779264 WHERE `entry`=203239; -- Primordial Infused Rock Snail
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=16779264 WHERE `entry`=203126; -- Mudslick Snail
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=203104; -- Shimmerfin Lurker
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=16779264 WHERE `entry`=203105; -- Sharpspine Pincher
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=203596; -- Blistering Shalewing
UPDATE `creature_template` SET `faction`=35, `speed_walk`=0.400000005960464477, `speed_run`=0.142857149243354797, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=203225; -- Struggling Mothling
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=205202; -- Brightwing Moth
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=16779264 WHERE `entry`=205203; -- Azured Dawdler
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=202930; -- Deepdrifter Megrim

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (204929, 205061, 200489, 200120, 205065, 205122, 199809, 201093, 203596);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(204929, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 204929 (Dustie)
(205061, 0, 0, 0, 0, 0, 1, 0, 468, 0, 0, 0, 0, ''), -- 205061 (Awaken Crystal)
(200489, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 200489 (Crystal Terror)
(200120, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 200120 (Underlight Moth)
(205065, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 205065 (Praying Stingray)
(205122, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 205122 (Underlight Flickerwing)
(199809, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 199809 (Swooping Flayer)
(201093, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 201093 (Chittering Acidclaw)
(203596, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 203596 (Blistering Shalewing)

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (200120, 200570, 205065, 204929, 199809, 202930, 203596, 203104, 205202);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(200120, 0, 0, 1, 0, 0, 0, NULL), -- Underlight Moth
(200570, 0, 0, 1, 0, 0, 0, NULL), -- Underlight Flutterer
(205065, 0, 0, 1, 0, 0, 0, NULL), -- Praying Stingray
(204929, 2, 0, 0, 0, 0, 0, NULL), -- Dustie
(199809, 0, 0, 1, 0, 0, 0, NULL), -- Swooping Flayer
(202930, 0, 1, 0, 0, 0, 0, NULL), -- Deepdrifter Megrim
(203596, 0, 0, 1, 0, 0, 0, NULL), -- Blistering Shalewing
(203104, 0, 1, 0, 0, 0, 0, NULL), -- Shimmerfin Lurker
(205202, 0, 0, 1, 0, 0, 0, NULL); -- Brightwing Moth

-- NPC Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 205445;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(205445, 411409, 1, 0);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=204926 AND `MenuID`=31415);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(204926, 31415, 49444); -- Delver Mardei

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 241396, 0, 0, 0, 0, 0, 0, 0, 49444); -- 204926 (Delver Mardei)

DELETE FROM `gossip_menu` WHERE (`MenuID`=31415 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(31415, @NPCTEXTID+0, 49444); -- 204926 (Delver Mardei)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=31415 AND `OptionID` IN (0,1));
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(109413, 31415, 0, 1, 'Want to trade some pet charms?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49444),
(109412, 31415, 1, 0, 'Begin pet battle.', 74459, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49444);

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=204926 AND `item`=122457 AND `ExtendedCost`=7237 AND `type`=1) OR (`entry`=204926 AND `item`=98715 AND `ExtendedCost`=6433 AND `type`=1) OR (`entry`=204926 AND `item`=86143 AND `ExtendedCost`=6435 AND `type`=1) OR (`entry`=204926 AND `item`=116429 AND `ExtendedCost`=6436 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(204926, 4, 122457, 0, 7237, 1, 0, 0, 49444), -- Ultimate Battle-Training Stone
(204926, 3, 98715, 0, 6433, 1, 0, 0, 49444), -- Marked Flawless Battle-Stone
(204926, 2, 86143, 0, 6435, 1, 0, 0, 49444), -- Battle Pet Bandage
(204926, 1, 116429, 0, 6436, 1, 0, 0, 49444); -- Flawless Battle-Training Stone

-- Scaling & Model
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (205078,205061,205082,205079,205065,203097,200498,203122,200477,200570,200120,200489,204930,204926,204929,200113,204933,205595,203295,201001,203310,202850,203041,202930,204291,203225,205202,205203,205313,203093,203115,205122,203001,204112,203384,200898,202772,200121,199809,205445,201081,200115,203101,203132,203118,203095,205169,201093,203596,203105,203241,203239,203104,203240,203222,203237,203238,203126,205052,204443,205011,205009));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(205078, 0, 0, 0, 2625, 49444),
(205061, 0, 0, 0, 2625, 49444),
(205082, 0, 0, 0, 2625, 49444),
(205079, 0, 0, 0, 2625, 49444),
(205065, 0, 0, 0, 2625, 49444),
(203097, 0, 0, 0, 2078, 49444),
(200498, 0, 0, 0, 2625, 49444),
(203122, 0, 0, 0, 2078, 49444),
(200477, 0, 0, 0, 2625, 49444),
(200570, 0, 0, 0, 2618, 49444),
(200120, 0, 0, 0, 2618, 49444),
(200489, 0, 0, 0, 2625, 49444),
(204930, 0, 0, 0, 371, 49444),
(204926, 0, 0, 0, 371, 49444),
(204929, 0, 0, 0, 371, 49444),
(200113, 0, 0, 0, 2650, 49444),
(204933, 0, 0, 0, 371, 49444),
(205595, 0, 0, 0, 2627, 49444),
(203295, 0, 0, 0, 2627, 49444),
(201001, 0, 0, 0, 371, 49444),
(203310, 0, 0, 0, 371, 49444),
(202850, 0, 0, 0, 2628, 49444),
(203041, 0, 0, 0, 2627, 49444),
(202930, 0, 0, 0, 2628, 49444),
(204291, 0, 0, 0, 2615, 49444),
(203225, 0, 0, 0, 2623, 49444),
(205202, 0, 0, 0, 2622, 49444),
(205203, 0, 0, 0, 2474, 49444),
(205313, 0, 0, 0, 2057, 49444),
(203093, 0, 0, 0, 2078, 49444),
(203115, 0, 0, 0, 2078, 49444),
(205122, 0, 0, 0, 2631, 49444),
(203001, 0, 0, 0, 2078, 49444),
(204112, 0, 0, 0, 2631, 49444),
(203384, 0, 0, 0, 2618, 49444),
(200898, 0, 0, 0, 2623, 49444),
(202772, 0, 0, 0, 2078, 49444),
(200121, 0, 0, 0, 2618, 49444),
(199809, 0, 0, 0, 2618, 49444),
(205445, 0, 0, 0, 81, 49444),
(201081, 0, 0, 0, 2622, 49444),
(200115, 0, 0, 0, 2650, 49444),
(203101, 0, 0, 0, 2078, 49444),
(203132, 0, 0, 0, 2078, 49444),
(203118, 0, 0, 0, 2078, 49444),
(203095, 0, 0, 0, 2078, 49444),
(205169, 0, 0, 0, 2618, 49444),
(201093, 0, 0, 0, 2617, 49444),
(203596, 0, 0, 0, 2617, 49444),
(203105, 0, 0, 0, 2622, 49444),
(203241, 0, 0, 0, 2622, 49444),
(203239, 0, 0, 0, 2622, 49444),
(203104, 0, 0, 0, 2628, 49444),
(203240, 0, 0, 0, 2622, 49444),
(203222, 0, 0, 0, 2622, 49444),
(203237, 0, 0, 0, 2622, 49444),
(203238, 0, 0, 0, 2622, 49444),
(203126, 0, 0, 0, 2474, 49444),
(205052, 0, 0, 0, 2627, 49444),
(204443, 0, 0, 0, 2627, 49444),
(205011, 0, 0, 0, 2627, 49444),
(205009, 0, 0, 0, 2649, 49444);

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (109352, 109350, 109360, 109505, 112217, 111688, 108088, 109343, 112142, 112363, 112196, 110441, 111300, 111893, 110438, 107724, 107721, 109361, 110436, 107723, 110072, 107719, 110450, 111516, 110437, 110442, 107718, 110449, 110067, 112710, 108573, 108572, 103334, 111717, 111857, 110321, 107720, 107722, 111856, 111687, 109359, 111689, 107716);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(109352, 0.318646520376205444, 0.400000005960464477, 0, 49444),
(109350, 0.318646520376205444, 0.400000005960464477, 0, 49444),
(109360, 0.629892349243164062, 1, 0, 49444),
(109505, 2.334234952926635742, 1, 0, 49444),
(112217, 0.420000016689300537, 1.20000004768371582, 0, 49444),
(111688, 0.244999989867210388, 0.699999988079071044, 0, 49444),
(108088, 0.420000016689300537, 1.20000004768371582, 0, 49444),
(109343, 3.186465263366699218, 4, 0, 49444),
(112142, 0.368032127618789672, 0.82500004768371582, 0, 49444),
(112363, 0.347222000360488891, 1.5, 0, 49444),
(112196, 0.122499994933605194, 0.349999994039535522, 0, 49444),
(110441, 4.897859573364257812, 6, 0, 49444),
(111300, 0.24810868501663208, 0, 0, 49444),
(111893, 0.255529731512069702, 0.5, 0, 49444),
(110438, 2.448929786682128906, 3, 0, 49444),
(107724, 1.277648568153381347, 2.5, 0, 49444),
(107721, 1.277648568153381347, 2.5, 0, 49444),
(109361, 0.244999989867210388, 0.699999988079071044, 0, 49444),
(110436, 2.448929786682128906, 3, 0, 49444),
(107723, 1.277648568153381347, 2.5, 0, 49444),
(110072, 4.897859573364257812, 6, 0, 49444),
(107719, 1.277648568153381347, 2.5, 0, 49444),
(110450, 2.448929786682128906, 3, 0, 49444),
(111516, 0.511059463024139404, 1, 0, 49444),
(110437, 4.897859573364257812, 6, 0, 49444),
(110442, 2.448929786682128906, 3, 0, 49444),
(107718, 1.277648568153381347, 2.5, 0, 49444),
(110449, 4.897859573364257812, 6, 0, 49444),
(110067, 1.597060680389404296, 3.124999761581420898, 0, 49444),
(112710, 4.081549644470214843, 5, 0, 49444),
(108573, 2.099038124084472656, 1.25, 0, 49444),
(108572, 2.099038124084472656, 1.25, 0, 49444),
(103334, 1.664229273796081542, 2.5, 0, 49444),
(111717, 2.334234952926635742, 1, 0, 49444),
(111857, 1.277648568153381347, 2.5, 0, 49444),
(110321, 0.124000005424022674, 1.20000004768371582, 0, 49444),
(107720, 1.277648568153381347, 2.5, 0, 49444),
(107722, 1.277648568153381347, 2.5, 0, 49444),
(111856, 1.277648568153381347, 2.5, 0, 49444),
(111687, 0.244999989867210388, 0.699999988079071044, 0, 49444),
(109359, 0.244999989867210388, 0.699999988079071044, 0, 49444),
(111689, 0.244999989867210388, 0.699999988079071044, 0, 49444),
(107716, 1.022118926048278808, 2, 0, 49444);

UPDATE `creature_model_info` SET `BoundingRadius`=1.535885334014892578, `CombatReach`=1, `VerifiedBuild`=49444 WHERE `DisplayID`=104633;
UPDATE `creature_model_info` SET `VerifiedBuild`=49444 WHERE `DisplayID` IN (104634, 103366, 104626, 104629, 104625, 23767, 103367, 103370);

-- Waypoints for CGUID+104
SET @PATH := ((@CGUID+104) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -68.64584, 1371.264, 19.92466, NULL, 0),
(@PATH, 1, -79.09028, 1379.563, 18.59168, NULL, 5773),
(@PATH, 2, -55.94445, 1376.149, 20.37203, NULL, 0),
(@PATH, 3, -44.38021, 1383.135, 20.73289, NULL, 5851);

UPDATE `creature` SET `position_x`= -68.64584, `position_y`= 1371.264, `position_z`= 19.92466, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+104;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+104;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+104, @PATH, 1);

-- Waypoints for CGUID+89
SET @PATH := ((@CGUID+89) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -42.77257, 1258.762, 23.29083, NULL, 0),
(@PATH, 1, -41.43576, 1261.455, 22.87823, NULL, 0),
(@PATH, 2, -40.21528, 1260.278, 23.16607, NULL, 6503),
(@PATH, 3, -28.47396, 1240.807, 25.76556, NULL, 0),
(@PATH, 4, -22.94444, 1235.3, 26.86053, NULL, 0),
(@PATH, 5, -19.73958, 1231.248, 28.17237, NULL, 21),
(@PATH, 6, -16.9184, 1224.938, 30.88404, NULL, 6349),
(@PATH, 7, -28.10069, 1226.314, 28.05226, NULL, 0),
(@PATH, 8, -38.7882, 1232.727, 26.47628, NULL, 6506),
(@PATH, 9, -42.46354, 1247.063, 24.60711, NULL, 0),
(@PATH, 10, -43.70833, 1253.207, 23.90265, NULL, 0);

UPDATE `creature` SET `position_x`= -42.77257, `position_y`= 1258.762, `position_z`= 23.29083, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+89;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+89;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+89, @PATH, 1);

-- Waypoints for CGUID+67
SET @PATH := ((@CGUID+67) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -59.30903, 1168.349, 39.37441, NULL, 0),
(@PATH, 1, -61.06076, 1154.314, 43.25159, NULL, 0),
(@PATH, 2, -61.10764, 1138, 43.00323, NULL, 4340),
(@PATH, 3, -61.06076, 1154.314, 43.25159, NULL, 0),
(@PATH, 4, -59.30903, 1168.349, 39.37441, NULL, 0),
(@PATH, 5, -63.4132, 1192.392, 33.30051, NULL, 0),
(@PATH, 6, -71.82118, 1209.019, 29.71637, NULL, 0),
(@PATH, 7, -89.28819, 1216.661, 27.1808, NULL, 4246),
(@PATH, 8, -71.82118, 1209.019, 29.71637, NULL, 0),
(@PATH, 9, -63.4132, 1192.392, 33.30051, NULL, 0);

UPDATE `creature` SET `position_x`= -59.30903, `position_y`= 1168.349, `position_z`= 39.37441, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+67;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+67;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+67, @PATH, 1);

-- Waypoints for CGUID+5
SET @PATH := ((@CGUID+5) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -19.46354, 898.6302, 102.8056, NULL, 0),
(@PATH, 1, -24.92188, 893.2066, 102.0411, NULL, 11312),
(@PATH, 2, -0.546875, 887.757, 105.6476, NULL, 0),
(@PATH, 3, 9.720487, 882.4184, 103.5157, NULL, 0),
(@PATH, 4, 20.37674, 877.0712, 101.4793, NULL, 0),
(@PATH, 5, 26.50347, 873.0555, 100.7518, NULL, 0),
(@PATH, 6, 34.17535, 868.1268, 99.3291, NULL, 0),
(@PATH, 7, 43.81945, 860.7882, 99.24747, NULL, 0),
(@PATH, 8, 50.15278, 855.2239, 98.9429, NULL, 16087),
(@PATH, 9, 23.15799, 872.4028, 101.3118, NULL, 0),
(@PATH, 10, 4.696181, 883.6441, 104.5179, NULL, 0),
(@PATH, 11, -5.519097, 890.0677, 105.8724, NULL, 0),
(@PATH, 12, -16.74479, 899.2083, 103.5366, NULL, 0),
(@PATH, 13, -22.07813, 910.4288, 101.5274, NULL, 0),
(@PATH, 14, -23.44965, 918.1771, 100.5962, NULL, 0),
(@PATH, 15, -27.22569, 931.5452, 99.71635, NULL, 0),
(@PATH, 16, -27.02431, 941.6146, 99.36228, NULL, 0),
(@PATH, 17, -19.77083, 955.1979, 98.48215, NULL, 0),
(@PATH, 18, -9.41493, 966.6371, 98.6013, NULL, 0),
(@PATH, 19, -4.940972, 973.6024, 99.43821, NULL, 0),
(@PATH, 20, -0.1979167, 978.5278, 100.0349, NULL, 0),
(@PATH, 21, 4.633681, 983.0608, 100.5778, NULL, 12383),
(@PATH, 22, -11.38889, 966.6893, 98.36423, NULL, 0),
(@PATH, 23, -18.57639, 959.7188, 98.98069, NULL, 0),
(@PATH, 24, -24.91146, 954.993, 99.06443, NULL, 0),
(@PATH, 25, -28.47049, 934.9305, 99.41843, NULL, 0),
(@PATH, 26, -26.07639, 921.5781, 100.0914, NULL, 0),
(@PATH, 27, -21.25521, 905.2899, 101.8648, NULL, 0);

UPDATE `creature` SET `position_x`= -19.46354, `position_y`= 898.6302, `position_z`= 102.8056, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+5, @PATH, 1);

-- Waypoints for CGUID+73
SET @PATH := ((@CGUID+73) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 49.77778, 1193.806, 55.51151, NULL, 0),
(@PATH, 1, 44.68576, 1183.547, 56.76871, NULL, 6019),
(@PATH, 2, 52.07813, 1206.269, 54.44387, NULL, 0),
(@PATH, 3, 38.14583, 1223.063, 43.04519, NULL, 5981),
(@PATH, 4, 49.1007, 1207.243, 53.61269, NULL, 0);

UPDATE `creature` SET `position_x`= 49.77778, `position_y`= 1193.806, `position_z`= 55.51151, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+73;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+73;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+73, @PATH, 1);

-- Waypoints for CGUID+22
SET @PATH := ((@CGUID+22) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -84.82291, 872.7934, 67.55579, NULL, 0),
(@PATH, 1, -88.57986, 903.4323, 59.06818, NULL, 0),
(@PATH, 2, -99.41146, 918.7239, 58.1756, NULL, 0),
(@PATH, 3, -100.5521, 943.6268, 55.36639, NULL, 0),
(@PATH, 4, -100.3691, 966.3018, 53.11249, NULL, 0),
(@PATH, 5, -100.1753, 1000.606, 48.5756, NULL, 0),
(@PATH, 6, -86.52778, 1038.059, 45.50145, NULL, 0),
(@PATH, 7, -73.63672, 1065.129, 44.37645, NULL, 0),
(@PATH, 8, -57.17708, 1075.255, 47.41564, NULL, 0),
(@PATH, 9, -30.86806, 1088.014, 54.54613, NULL, 0),
(@PATH, 10, 0.1510417, 1086.616, 55.32458, NULL, 0),
(@PATH, 11, 26.59549, 1089.53, 54.67419, NULL, 0),
(@PATH, 12, 41.2793, 1095.903, 56.10441, NULL, 0),
(@PATH, 13, 54.10417, 1095.418, 58.28678, NULL, 0),
(@PATH, 14, 68.09375, 1092.281, 57.92632, NULL, 0),
(@PATH, 15, 92.13541, 1094.622, 57.92632, NULL, 0),
(@PATH, 16, 103.0521, 1100.219, 58.13367, NULL, 10090),
(@PATH, 17, 75.39236, 1093.375, 57.92632, NULL, 0),
(@PATH, 18, 57.21875, 1094.842, 57.91373, NULL, 0),
(@PATH, 19, 39.28472, 1098.512, 55.53288, NULL, 0),
(@PATH, 20, 18.77257, 1092.024, 55.30285, NULL, 0),
(@PATH, 21, -5.012153, 1093.693, 56.90306, NULL, 0),
(@PATH, 22, -25.45313, 1087.816, 55.74535, NULL, 0),
(@PATH, 23, -54.33398, 1076.555, 48.01329, NULL, 0),
(@PATH, 24, -75.12153, 1063.608, 44.1743, NULL, 0),
(@PATH, 25, -90.88194, 1037.5, 45.50145, NULL, 0),
(@PATH, 26, -93.69965, 1011.552, 48.7537, NULL, 0),
(@PATH, 27, -101.3924, 976.4063, 51.79059, NULL, 0),
(@PATH, 28, -103.0332, 948.4609, 55.11249, NULL, 0),
(@PATH, 29, -102.3108, 926.6406, 57.80455, NULL, 0),
(@PATH, 30, -95.48611, 895.0295, 60.28919, NULL, 0),
(@PATH, 31, -87.07986, 873.6371, 67.21595, NULL, 0),
(@PATH, 32, -80.71354, 843.8854, 70.74006, NULL, 0),
(@PATH, 33, -71.2691, 816.7795, 72.50064, NULL, 0),
(@PATH, 34, -49.47396, 796.882, 74.58189, NULL, 0),
(@PATH, 35, -32.03993, 795.4879, 82.91679, NULL, 0),
(@PATH, 36, -12.45313, 783.9531, 89.88969, NULL, 0),
(@PATH, 37, 13.97569, 786.368, 96.06464, NULL, 0),
(@PATH, 38, 31.36979, 790.6823, 99.48554, NULL, 0),
(@PATH, 39, 58.75174, 806.3507, 99.43848, NULL, 0),
(@PATH, 40, 66.07118, 831.7934, 96.12305, NULL, 0),
(@PATH, 41, 68.79166, 839.6302, 95.9642, NULL, 0),
(@PATH, 42, 78.28299, 846.7552, 96.17062, NULL, 0),
(@PATH, 43, 92.31597, 846.5208, 96.3392, NULL, 0),
(@PATH, 44, 109.3212, 841.7396, 98.05506, NULL, 0),
(@PATH, 45, 124.2743, 834.467, 101.3446, NULL, 0),
(@PATH, 46, 133.7361, 830.7413, 104.5381, NULL, 33864),
(@PATH, 47, -20.28472, 778.8264, 86.66276, NULL, 0),
(@PATH, 48, -41.25695, 784.7743, 77.88242, NULL, 0),
(@PATH, 49, -54.78472, 793.4896, 74.64475, NULL, 0),
(@PATH, 50, -64.10764, 808.9757, 73.34483, NULL, 0),
(@PATH, 51, -77.72461, 824.9717, 71.87564, NULL, 0),
(@PATH, 52, -81.77778, 835.533, 71.11311, NULL, 0),
(@PATH, 53, -83.65972, 852.8507, 70.02814, NULL, 0);

UPDATE `creature` SET `position_x`= -84.82291, `position_y`= 872.7934, `position_z`= 67.55579, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+22;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+22;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+22, @PATH, 1);

-- Waypoints for CGUID+312
SET @PATH := ((@CGUID+312) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -91.48785, 2002.936, -90.64495, NULL, 0),
(@PATH, 1, -83.17535, 2015.688, -89.78521, NULL, 0),
(@PATH, 2, -70.93229, 2018.556, -89.37859, NULL, 0),
(@PATH, 3, -62.125, 2016.684, -89.29911, NULL, 0),
(@PATH, 4, -50.22396, 2008.363, -89.8704, NULL, 0),
(@PATH, 5, -45.76215, 2000.174, -89.60795, NULL, 0),
(@PATH, 6, -46.32292, 1989.677, -90.01189, NULL, 0),
(@PATH, 7, -58.66493, 1979.365, -90.09417, NULL, 0),
(@PATH, 8, -68.77257, 1978.583, -89.5498, NULL, 0),
(@PATH, 9, -79.16493, 1977.194, -91.35449, NULL, 0),
(@PATH, 10, -89.22743, 1984.549, -91.58386, NULL, 0);

UPDATE `creature` SET `position_x`= -91.48785, `position_y`= 2002.936, `position_z`= -90.64495, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+312;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+312;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+312, @PATH, 1);

-- Waypoints for CGUID+302
SET @PATH := ((@CGUID+302) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -26.31944, 1999.708, -92.87035, NULL, 0),
(@PATH, 1, -10.41406, 2001.411, -93.97831, NULL, 0),
(@PATH, 2, -0.05902778, 1984.429, -93.96789, NULL, 0),
(@PATH, 3, -1.387153, 1972.681, -90.80724, NULL, 0),
(@PATH, 4, -7.236111, 1959.323, -88.19722, NULL, 0),
(@PATH, 5, -14.27778, 1951.363, -88.21199, NULL, 0),
(@PATH, 6, -25.51215, 1951.707, -88.10237, NULL, 0),
(@PATH, 7, -38.48438, 1954.965, -88.34487, NULL, 0),
(@PATH, 8, -42.9375, 1970.993, -89.58624, NULL, 0),
(@PATH, 9, -37.88889, 1985.845, -90.747, NULL, 0);

UPDATE `creature` SET `position_x`= -26.31944, `position_y`= 1999.708, `position_z`= -92.87035, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+302;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+302;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+302, @PATH, 1);
