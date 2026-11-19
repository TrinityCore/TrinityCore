SET @CGUID := 1251790;
SET @OGUID := 700155;

SET @NPCTEXTID := 590026;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+227;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 187160, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5051.90625, 1176.828125, 594.26898193359375, 2.384143829345703125, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+1, 187159, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5083.685546875, 1044.1966552734375, 594.7354736328125, 0.532994985580444335, 7200, 0, 0, 286218, 0, 0, 0, 0, 0, 46879), -- Shrieking Whelp (Area: The Azure Vault - Difficulty: Mythic) (Auras: 370756 - Whelp Cosmetic, 370223 - Revealing Gaze) (possible waypoints or random movement)
(@CGUID+2, 187160, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5095.60595703125, 1069.5208740234375, 593.47540283203125, 2.530750751495361328, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+3, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5063.001953125, 1172.8385009765625, 594.26898193359375, 1.780307769775390625, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+4, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5072.3994140625, 1088.0972900390625, 594.3238525390625, 2.33391880989074707, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+5, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5121.6318359375, 1076.0052490234375, 594.32647705078125, 2.377986669540405273, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+6, 196115, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5092.42724609375, 1144.986083984375, 594.5350341796875, 4.745289802551269531, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Arcane Tender (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+7, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5093.671875, 1128.546875, 594.5350341796875, 3.776418924331665039, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+8, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5114.4775390625, 1086.267333984375, 594.32293701171875, 0.731600165367126464, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+9, 187160, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5088.080078125, 1068.095458984375, 593.47540283203125, 0.206737995147705078, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+10, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5065.736328125, 1077.1666259765625, 594.32940673828125, 3.980304956436157226, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+11, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5084.408203125, 1135.0347900390625, 594.5350341796875, 6.110337734222412109, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+12, 187160, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5068.91650390625, 1161.8055419921875, 594.26898193359375, 1.880502820014953613, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+13, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5073.48779296875, 1173.7586669921875, 594.26898193359375, 4.083187103271484375, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+14, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5099.46337890625, 1135.1614990234375, 594.5350341796875, 1.473538160324096679, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+15, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5118.03125, 1081.69970703125, 594.30303955078125, 4.680866718292236328, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+16, 171322, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5049.63525390625, 1037.40283203125, 594.5350341796875, 5.167956829071044921, 7200, 0, 0, 262306, 0, 0, 0, 0, 0, 46879), -- Global Affix Stalker (Area: The Azure Vault - Difficulty: Mythic)
(@CGUID+17, 187160, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5092.955078125, 1063.4617919921875, 593.47540283203125, 4.657943248748779296, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+18, 187159, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5061.9921875, 1174.405517578125, 594.331787109375, 0.810280263423919677, 7200, 0, 0, 286218, 0, 0, 0, 0, 0, 46879), -- Shrieking Whelp (Area: The Azure Vault - Difficulty: Mythic) (Auras: 370756 - Whelp Cosmetic, 370223 - Revealing Gaze)
(@CGUID+19, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5065.9462890625, 1081.607666015625, 594.32940673828125, 0, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+20, 186644, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5129.3994140625, 1253.3021240234375, 555.587646484375, 0.716250777244567871, 7200, 0, 0, 5008815, 0, 0, 0, 0, 0, 46879), -- Leymor (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375729 - Stasis) (possible waypoints or random movement)
(@CGUID+21, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5052.9912109375, 1197.3992919921875, 594.26898193359375, 1.473538160324096679, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+22, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5279.44287109375, 1043.9149169921875, 508.08270263671875, 2.355446100234985351, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+23, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5123.431640625, 1228.979248046875, 555.892333984375, 0.429089635610580444, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+24, 188100, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5185.892578125, 1205.1458740234375, 510.537445068359375, 5.647762298583984375, 7200, 0, 0, 286218, 0, 0, 0, 0, 0, 46879), -- Shrieking Whelp (Area: The Azure Vault - Difficulty: Mythic) (Auras: 370756 - Whelp Cosmetic, 371042 - Revealing Gaze, 397215 - Revealing Gaze)
(@CGUID+25, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5077.8505859375, 1192.4930419921875, 595.196044921875, 4.976578235626220703, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+26, 191164, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5088.8125, 1253.65625, 555.6099853515625, 3.370214700698852539, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Arcane Tender (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+27, 186741, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5276.22314453125, 1064.1661376953125, 508.12860107421875, 4.718413829803466796, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Arcane Elemental (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+28, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5047.11962890625, 1191.779541015625, 594.26898193359375, 3.776418924331665039, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+29, 186741, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5273.3369140625, 1077.265625, 508.500762939453125, 3.890326499938964843, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Arcane Elemental (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+30, 187159, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5056.31884765625, 1193.8570556640625, 594.33331298828125, 3.997847795486450195, 7200, 0, 0, 286218, 0, 0, 0, 0, 0, 46879), -- Shrieking Whelp (Area: The Azure Vault - Difficulty: Mythic) (Auras: 370756 - Whelp Cosmetic, 370223 - Revealing Gaze)
(@CGUID+31, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5090.95751953125, 1220.3267822265625, 555.534912109375, 4.72898721694946289, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+32, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5070.56591796875, 1200.0833740234375, 595.197509765625, 2.673698663711547851, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+33, 191164, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5148.29150390625, 1218.98095703125, 555.6099853515625, 0.927235424518585205, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Arcane Tender (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+34, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5117.25146484375, 1229.1455078125, 555.92578125, 3.449914455413818359, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+35, 196115, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5044.3994140625, 1200.63720703125, 594.26898193359375, 3.91925215721130371, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Arcane Tender (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+36, 187139, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5068.001953125, 1189.8853759765625, 594.26898193359375, 5.763859272003173828, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Crystal Thrasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+37, 196102, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5040.60595703125, 1195.345458984375, 594.26898193359375, 6.110337734222412109, 7200, 0, 0, 643991, 0, 0, 0, 0, 0, 46879), -- Conjured Lasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 177645 - Submerged)
(@CGUID+38, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5123.40673828125, 1199.7403564453125, 555.534912109375, 3.350706815719604492, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+39, 187154, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5267.1337890625, 1085.63720703125, 508.08270263671875, 3.126855850219726562, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Unstable Curator (Area: The Azure Vault - Difficulty: Mythic) (Auras: 387789 - Errant Pages, 18950 - Invisibility and Stealth Detection)
(@CGUID+40, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5302.72216796875, 1118.2135009765625, 508.08270263671875, 3.522249460220336914, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+41, 186741, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5289.93701171875, 1063.2427978515625, 508.12860107421875, 4.632890224456787109, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Arcane Elemental (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+42, 187160, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5224.9287109375, 1224.045166015625, 510.537445068359375, 5.515480995178222656, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+43, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5157.94140625, 1248.062255859375, 555.534912109375, 2.521958827972412109, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+44, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5292.955078125, 1098.3055419921875, 508.08270263671875, 2.355446100234985351, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+45, 187155, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5282.69775390625, 1063.9296875, 508.128631591796875, 4.582587718963623046, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Rune Seal Keeper (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+46, 188100, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5204.640625, 1196.8177490234375, 510.537445068359375, 5.527161121368408203, 7200, 0, 0, 286218, 0, 0, 0, 0, 0, 46879), -- Shrieking Whelp (Area: The Azure Vault - Difficulty: Mythic) (Auras: 370756 - Whelp Cosmetic, 371042 - Revealing Gaze, 397215 - Revealing Gaze)
(@CGUID+47, 196205, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5302.84912109375, 1075.888916015625, 509.56103515625, 0.325835078954696655, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Errant Pages (Area: The Azure Vault - Difficulty: Mythic) (Auras: 387789 - Errant Pages)
(@CGUID+48, 186741, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5275.69970703125, 1042.9774169921875, 425.66119384765625, 2.213513374328613281, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Arcane Elemental (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+49, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5156.25830078125, 1255.720703125, 555.8529052734375, 4.732130050659179687, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+50, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5082.85595703125, 1296.352294921875, 555.53778076171875, 1.11910247802734375, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+51, 188714, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5285.580078125, 1015.27081298828125, 510.3712158203125, 0, 7200, 0, 0, 27, 0, 0, 0, 0, 0, 46879), -- Small Arcane Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 371537 - -Unknown-)
(@CGUID+52, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5174.42529296875, 1241.3145751953125, 555.534912109375, 3.251723051071166992, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+53, 188100, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5208.234375, 1219.404541015625, 510.537445068359375, 5.647762298583984375, 7200, 0, 0, 286218, 0, 0, 0, 0, 0, 46879), -- Shrieking Whelp (Area: The Azure Vault - Difficulty: Mythic) (Auras: 370756 - Whelp Cosmetic, 371042 - Revealing Gaze, 397215 - Revealing Gaze)
(@CGUID+54, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5103.97509765625, 1291.8065185546875, 555.534912109375, 2.843318939208984375, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+55, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5272.8349609375, 1075.9930419921875, 425.2484130859375, 0.296596258878707885, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+56, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5165.07373046875, 1273.3433837890625, 555.534912109375, 0.668797731399536132, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+57, 186741, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5277.3369140625, 1089.592041015625, 508.5006103515625, 2.87725377082824707, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Arcane Elemental (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+58, 188714, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5273.3994140625, 1103.2569580078125, 427.319183349609375, 0, 7200, 0, 0, 27, 0, 0, 0, 0, 0, 46879), -- Small Arcane Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 371537 - -Unknown-)
(@CGUID+59, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5280.59912109375, 1065.7413330078125, 425.2484130859375, 5.159622669219970703, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+60, 188714, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5318.27587890625, 1137.1180419921875, 510.332763671875, 0, 7200, 0, 0, 27, 0, 0, 0, 0, 0, 46879), -- Small Arcane Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 371537 - -Unknown-)
(@CGUID+61, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5103.66796875, 1301.785888671875, 555.66363525390625, 3.278785228729248046, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+62, 187160, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5239.8193359375, 1235.9566650390625, 510.537445068359375, 5.515480995178222656, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+63, 191313, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5089.740234375, 1303.68408203125, 555.75872802734375, 3.822187185287475585, 7200, 3, 0, 71555, 0, 1, 0, 0, 0, 46879), -- Bubbling Sapling (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+64, 187160, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5215.640625, 1239.7847900390625, 510.537445068359375, 0.146091431379318237, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+65, 188714, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5407.33837890625, 1047.986083984375, 510.42236328125, 0, 7200, 0, 0, 27, 0, 0, 0, 0, 0, 46879), -- Small Arcane Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 371537 - -Unknown-)
(@CGUID+66, 191164, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5149.99853515625, 1290.4600830078125, 555.6099853515625, 5.31850433349609375, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Arcane Tender (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+67, 188714, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5336.80908203125, 993.98785400390625, 427.63958740234375, 0, 7200, 0, 0, 27, 0, 0, 0, 0, 0, 46879), -- Small Arcane Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 371537 - -Unknown-)
(@CGUID+68, 188714, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5400.02978515625, 1103.4410400390625, 427.426910400390625, 0, 7200, 0, 0, 27, 0, 0, 0, 0, 0, 46879), -- Small Arcane Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 371537 - -Unknown-)
(@CGUID+69, 186740, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5283.97900390625, 1036.4149169921875, 425.67315673828125, 2.590687513351440429, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Arcane Construct (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+70, 186741, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5285.13525390625, 1027.2117919921875, 425.66339111328125, 3.115178346633911132, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Arcane Elemental (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+71, 187139, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5226.6005859375, 1236.82470703125, 510.537445068359375, 5.769658565521240234, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Crystal Thrasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+72, 186741, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5295.6689453125, 1029.89013671875, 425.332183837890625, 0.644179105758666992, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Arcane Elemental (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+73, 187155, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5294.25, 1035.9586181640625, 425.332244873046875, 0.644257545471191406, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Rune Seal Keeper (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+74, 189555, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5292.384765625, 1047.83349609375, 425.44134521484375, 1.078150153160095214, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Astral Attendant (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+75, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5307.2119140625, 1107.1441650390625, 425.2484130859375, 5.159622669219970703, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+76, 186741, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5347.64404296875, 1003.671875, 508.5010986328125, 0.87211012840270996, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Arcane Elemental (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+77, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5291.2431640625, 1081.8333740234375, 425.2484130859375, 3.522249460220336914, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+78, 194602, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5304.111328125, 1189.5972900390625, 511.08416748046875, 1.285688996315002441, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+79, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5343.2255859375, 1125.798583984375, 508.08270263671875, 5.917020797729492187, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+80, 194618, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5322.26025390625, 1122.748291015625, 508.08270263671875, 4.370800495147705078, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+81, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5306.9443359375, 1021.38201904296875, 425.2484130859375, 0.683617472648620605, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+82, 186740, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5286.7880859375, 1104.857666015625, 425.2484130859375, 1.789503216743469238, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Arcane Construct (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+83, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5299.44775390625, 1117.3958740234375, 425.2484130859375, 0.296596258878707885, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+84, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5310.265625, 1008.9600830078125, 425.2484130859375, 5.546643257141113281, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+85, 187160, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5231.47412109375, 1250.453125, 510.537445068359375, 0.146091431379318237, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: 375407 - Ready Defense)
(@CGUID+86, 196205, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5346.4130859375, 1032.1475830078125, 509.413055419921875, 4.383180141448974609, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Errant Pages (Area: The Azure Vault - Difficulty: Mythic)
(@CGUID+87, 186740, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5299.95166015625, 1097.064208984375, 425.2484130859375, 2.627021551132202148, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Arcane Construct (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+88, 196116, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5386.249, 1093.043, 508.2291, 5.906778812408447265, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+89, 186741, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5281.23291015625, 1247.8646240234375, 510.537445068359375, 0.977106332778930664, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Arcane Elemental (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+90, 186741, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5297.07666015625, 1251.59033203125, 510.537445068359375, 1.709560275077819824, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Arcane Elemental (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+91, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5317.85595703125, 1123.236083984375, 425.2484130859375, 3.522249460220336914, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+92, 196116, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5377.9619140625, 1116.798583984375, 508.500762939453125, 6.184972763061523437, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+93, 196205, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5361.986328125, 1091.9097900390625, 509.214691162109375, 2.275400638580322265, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Errant Pages (Area: The Azure Vault - Difficulty: Mythic) (Auras: 387789 - Errant Pages)
(@CGUID+94, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5353.0244140625, 1117.579833984375, 508.08270263671875, 2.355446100234985351, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+95, 198422, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5318.90478515625, 1244.1875, 510.959442138671875, 1.383311867713928222, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Tome of Transmogrification (Area: The Azure Vault - Difficulty: Mythic)
(@CGUID+96, 195434, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5336.61474609375, 1113.1944580078125, 426.34124755859375, 1.655280351638793945, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+97, 196116, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5360.41162109375, 1005.90277099609375, 508.500335693359375, 2.008769512176513671, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+98, 187154, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5388.54345703125, 1118.282958984375, 508.08270263671875, 5.200312614440917968, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Unstable Curator (Area: The Azure Vault - Difficulty: Mythic) (Auras: 387789 - Errant Pages)
(@CGUID+99, 196116, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5387.7587890625, 1106.88720703125, 508.499298095703125, 4.917675495147705078, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+100, 196117, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5380.47802734375, 1098.2264404296875, 508.228271484375, 0.731830060482025146, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Crystal Thrasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+101, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5364.4287109375, 1120.046875, 425.2484130859375, 1.090770602226257324, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+102, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5362.55712890625, 1107.3194580078125, 425.2484130859375, 5.953796863555908203, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+103, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5381.49658203125, 1111.0086669921875, 425.2484130859375, 4.316423892974853515, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+104, 186740, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5386.37353515625, 1105.6944580078125, 425.2484130859375, 1.353922367095947265, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Arcane Construct (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+105, 186740, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5374.25341796875, 1098.107666015625, 425.2484130859375, 0.759004652500152587, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Arcane Construct (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+106, 197643, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5311.923828125, 1110.2396240234375, 342.511871337890625, 4.1597900390625, 7200, 0, 0, 143109, 100, 0, 0, 0, 0, 46879), -- Icy Crystal (Area: The Azure Vault - Difficulty: Mythic)
(@CGUID+107, 196211, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5337.921875, 1067.60595703125, 416.6376953125, 0, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Cosmetic Barrier Stalker (Area: The Azure Vault - Difficulty: Mythic) (Auras: 387834 - Barrier Cosmetic)
(@CGUID+108, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5395.765625, 1071.498291015625, 508.08270263671875, 2.355446100234985351, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+109, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5326.19775390625, 1019.84381103515625, 425.2484130859375, 3.909270048141479492, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+110, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5389.126953125, 1084.482666015625, 425.2484130859375, 2.305613517761230468, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+111, 197204, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5294.21875, 1066.748291015625, 339.631805419921875, 0, 7200, 0, 0, 143109, 100, 0, 0, 0, 0, 46879), -- Vault Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 388065 - Vault Rune)
(@CGUID+112, 187154, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5356.68603515625, 996.47918701171875, 508.08270263671875, 1.059728264808654785, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Unstable Curator (Area: The Azure Vault - Difficulty: Mythic) (Auras: 387789 - Errant Pages, 18950 - Invisibility and Stealth Detection)
(@CGUID+113, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5388.22216796875, 1065.1927490234375, 425.2484130859375, 5.363145828247070312, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+114, 197081, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5060.5224609375, 1025.545166015625, 594.5350341796875, 5.741816997528076171, 7200, 0, 0, 14310900, 0, 0, 0, 0, 0, 46879), -- Sindragosa (Area: The Azure Vault - Difficulty: Mythic) (Auras: 389786 - Shortcut Portal)
(@CGUID+115, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5352.3056640625, 1017.60418701171875, 425.2484130859375, 0.296596258878707885, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+116, 194713, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5336.90478515625, 1004.5850830078125, 425.673309326171875, 1.593087553977966308, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+117, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5370.71533203125, 1023.44451904296875, 425.2484130859375, 3.522249460220336914, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+118, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5360.0693359375, 1007.3524169921875, 425.2484130859375, 5.159622669219970703, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+119, 196116, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5388, 1027.0989990234375, 425.662872314453125, 0.258195608854293823, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+120, 186737, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5358.65283203125, 1106.4722900390625, 339.631805419921875, 5.106944561004638671, 7200, 0, 0, 5008815, 100, 0, 0, 0, 0, 46879), -- Telash Greywing (Area: The Azure Vault - Difficulty: Mythic) (Auras: 389454 - Ice Power [DNT]) (possible waypoints or random movement)
(@CGUID+121, 197204, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5358.1162109375, 1103.3333740234375, 339.631805419921875, 0, 7200, 0, 0, 143109, 100, 0, 0, 0, 0, 46879), -- Vault Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 388065 - Vault Rune)
(@CGUID+122, 196211, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5336.376953125, 1066.55908203125, 334.308868408203125, 0, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Cosmetic Barrier Stalker (Area: The Azure Vault - Difficulty: Mythic) (Auras: 387835 - Barrier Cosmetic Small)
(@CGUID+123, 196117, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5389.611328125, 1036.626708984375, 425.6728515625, 0.635369539260864257, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Crystal Thrasher (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+124, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5400.53125, 1068.91845703125, 425.2484130859375, 3.942986488342285156, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+125, 195432, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5336.71875, 952.3836669921875, 426.685943603515625, 4.658632278442382812, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+126, 196116, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5397.671875, 1042.201416015625, 425.2484130859375, 1.159860968589782714, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Crystal Fury (Area: The Azure Vault - Difficulty: Mythic) (Auras: 389686 - Arcane Fury)
(@CGUID+127, 197204, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5358.70654296875, 1030.1475830078125, 339.631805419921875, 0, 7200, 0, 0, 143109, 100, 0, 0, 0, 0, 46879), -- Vault Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 388065 - Vault Rune)
(@CGUID+128, 194714, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5407.39599609375, 996.43402099609375, 344.5535888671875, 3.91884469985961914, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+129, 187240, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5418.171875, 995.02777099609375, 344.553680419921875, 4.3137664794921875, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Drakonid Breaker (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+130, 187240, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5408.798828125, 986.72052001953125, 344.553680419921875, 3.867421627044677734, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Drakonid Breaker (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+131, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5313.24658203125, 892.76190185546875, 383.09710693359375, 0.044344991445541381, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+132, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5313.189453125, 898.4212646484375, 383.20172119140625, 0.044400103390216827, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+133, 190510, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5329.31591796875, 880.76739501953125, 427.778900146484375, 1.492361903190612792, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Vault Guard (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+134, 187240, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5297.0888671875, 896.36566162109375, 388.40191650390625, 0.08653019368648529, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Drakonid Breaker (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+135, 190510, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5344.06591796875, 880.6492919921875, 427.778900146484375, 1.630583763122558593, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Vault Guard (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+136, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5294.18603515625, 861.4600830078125, 388.69317626953125, 4.66408538818359375, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+137, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5289.51171875, 855.090087890625, 388.07342529296875, 0.488212674856185913, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+138, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5253.54345703125, 867.47052001953125, 388.694549560546875, 4.66408538818359375, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+139, 187246, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5366.46728515625, 907.420166015625, 355.938751220703125, 0.78841179609298706, 7200, 0, 0, 715545, 3155, 0, 0, 0, 0, 46879), -- Nullmagic Hornswog (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+140, 199614, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5271.53662109375, 877.2569580078125, 388.892578125, 4.652996063232421875, 7200, 0, 0, 5008815, 100, 0, 0, 0, 0, 46879), -- Telash Greywing (Area: The Azure Vault - Difficulty: Mythic)
(@CGUID+141, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5270.46728515625, 861.24481201171875, 387.901580810546875, 1.905259013175964355, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+142, 187246, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5324.21533203125, 889.81597900390625, 378.084320068359375, 4.393908977508544921, 7200, 0, 0, 715545, 3155, 0, 0, 0, 0, 46879), -- Nullmagic Hornswog (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+143, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5420.9150390625, 889.73089599609375, 343.283294677734375, 4.66408538818359375, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+144, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5291.04541015625, 845.40625, 387.901580810546875, 3.169997930526733398, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+145, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5421.845703125, 899.16839599609375, 343.283294677734375, 2.188178300857543945, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+146, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5486.62841796875, 935.92535400390625, 343.72705078125, 4.325377941131591796, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+147, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5263.66162109375, 851.404541015625, 387.901580810546875, 0.455315321683883666, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+148, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5467.455078125, 916.326416015625, 343.560333251953125, 5.412412643432617187, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+149, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5413.361328125, 895.41143798828125, 343.283294677734375, 0.595290005207061767, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+150, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5278.923828125, 850.74481201171875, 387.901580810546875, 2.145312070846557617, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+151, 187246, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5246.6787109375, 854.6776123046875, 393.317840576171875, 2.003531932830810546, 7200, 0, 0, 715545, 3155, 0, 0, 0, 0, 46879), -- Nullmagic Hornswog (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+152, 187246, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5467.03857421875, 912.01556396484375, 343.5595703125, 1.489329814910888671, 7200, 0, 0, 715545, 3155, 0, 0, 0, 0, 46879), -- Nullmagic Hornswog (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+153, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5435.40625, 892.28125, 343.283294677734375, 2.420986413955688476, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+154, 187155, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5362.28173828125, 833.4693603515625, 427.840545654296875, 0.403247565031051635, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Rune Seal Keeper (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+155, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5498.54345703125, 936.982666015625, 343.534912109375, 4.176020622253417968, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+156, 187246, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5509.3974609375, 935.4617919921875, 343.33306884765625, 3.621724843978881835, 7200, 0, 0, 715545, 3155, 0, 0, 0, 0, 46879), -- Nullmagic Hornswog (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+157, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5511.64599609375, 933.94964599609375, 343.5814208984375, 5.412412643432617187, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+158, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5486.60791015625, 913.15802001953125, 342.495849609375, 0.446979641914367675, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+159, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5498.642578125, 917.96356201171875, 342.495849609375, 2.145312070846557617, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+160, 187246, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5440.56591796875, 888.078125, 343.283294677734375, 1.850537300109863281, 7200, 0, 0, 715545, 3155, 0, 0, 0, 0, 46879), -- Nullmagic Hornswog (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+161, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5467.84716796875, 903.93927001953125, 343.628173828125, 5.412412643432617187, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+162, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5521.43408203125, 924.06768798828125, 343.62322998046875, 5.412412643432617187, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+163, 190510, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5362.17822265625, 829.164794921875, 427.8505859375, 0.403255254030227661, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Vault Guard (Area: The Azure Vault - Difficulty: Mythic) (Auras: 378065 - Mage Hunter's Fervor) (possible waypoints or random movement)
(@CGUID+164, 189555, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5355.96240234375, 827.465576171875, 427.845611572265625, 0.40368470549583435, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Astral Attendant (Area: The Azure Vault - Difficulty: Mythic) (Auras: 378065 - Mage Hunter's Fervor) (possible waypoints or random movement)
(@CGUID+165, 187246, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5302.75, 837.9149169921875, 388.7183837890625, 3.602447032928466796, 7200, 0, 0, 715545, 3155, 0, 0, 0, 0, 46879), -- Nullmagic Hornswog (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+166, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5254.55908203125, 844.1007080078125, 387.901580810546875, 5.984919548034667968, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+167, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5299.0380859375, 837.97918701171875, 388.67303466796875, 5.577459335327148437, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+168, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5272.1474609375, 837.25518798828125, 387.901580810546875, 1.392969012260437011, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+169, 187246, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5267.8349609375, 843.560791015625, 387.901580810546875, 3.849182367324829101, 7200, 0, 0, 715545, 3155, 0, 0, 0, 0, 46879), -- Nullmagic Hornswog (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+170, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5274.96337890625, 843.9288330078125, 387.901580810546875, 5.858245849609375, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+171, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5265.267578125, 835.74481201171875, 387.901580810546875, 4.688315868377685546, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+172, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5279.75537109375, 836.935791015625, 387.901580810546875, 3.742505073547363281, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+173, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5271.90966796875, 826.5694580078125, 387.901580810546875, 4.6490478515625, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+174, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5279.91064453125, 828.79364013671875, 387.962432861328125, 0.353156030178070068, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+175, 187246, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5245.0244140625, 830.8211669921875, 388.67962646484375, 0, 7200, 0, 0, 715545, 3155, 0, 0, 0, 0, 46879), -- Nullmagic Hornswog (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+176, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5297.63037109375, 827.5069580078125, 388.6995849609375, 4.503396987915039062, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+177, 191739, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5354.81689453125, 819.8310546875, 427.8397216796875, 0.478282094001770019, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Scalebane Lieutenant (Area: The Azure Vault - Difficulty: Mythic) (Auras: 377980 - Mage Hunter's Fervor, 378065 - Mage Hunter's Fervor, 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+178, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5247.1025390625, 824.76739501953125, 389.100341796875, 4.66408538818359375, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+179, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5254.53466796875, 817.2569580078125, 388.7049560546875, 3.590023040771484375, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+180, 189555, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5294.16162109375, 797.39239501953125, 427.739013671875, 5.736506462097167968, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Astral Attendant (Area: The Azure Vault - Difficulty: Mythic) (Auras: 378065 - Mage Hunter's Fervor)
(@CGUID+181, 187155, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5282.7275390625, 794.45831298828125, 427.739013671875, 3.213186264038085937, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Rune Seal Keeper (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+182, 190517, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5290.5224609375, 793.8992919921875, 426.739013671875, 6.274743556976318359, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Azure Vaults Crystal (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+183, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5436.783203125, 880.66668701171875, 343.283294677734375, 1.048436999320983886, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+184, 189555, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5292.6162109375, 788.54168701171875, 427.739013671875, 1.235319018363952636, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Astral Attendant (Area: The Azure Vault - Difficulty: Mythic) (Auras: 378065 - Mage Hunter's Fervor)
(@CGUID+185, 186739, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5337.0625, 792.25, 428.078857421875, 4.666826725006103515, 7200, 0, 0, 3577725, 100, 0, 0, 0, 0, 46879), -- Azureblade (Area: The Azure Vault - Difficulty: Mythic) (Auras: 377039 - 10.0 Dungeon - Azure Vault - Boss 2 - Draconic Illusion Rune 04 Boss Visual, 389340 - Arcane Mana [DNT])
(@CGUID+186, 198422, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5282.60791015625, 792.670166015625, 389.155059814453125, 0, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Tome of Transmogrification (Area: The Azure Vault - Difficulty: Mythic)
(@CGUID+187, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5446.41162109375, 883.91668701171875, 343.283294677734375, 1.398239970207214355, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+188, 187240, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5273.609375, 790.2413330078125, 389.155059814453125, 5.377368927001953125, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Drakonid Breaker (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+189, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5484.283203125, 902.7882080078125, 342.495849609375, 5.728959083557128906, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+190, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5465.4462890625, 894.76043701171875, 343.633392333984375, 5.412412643432617187, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+191, 187155, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5380.04541015625, 789.81427001953125, 427.739013671875, 0.789803028106689453, 7200, 0, 0, 715545, 0, 0, 0, 0, 0, 46879), -- Rune Seal Keeper (Area: The Azure Vault - Difficulty: Mythic) (Auras: 378065 - Mage Hunter's Fervor)
(@CGUID+192, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5484.85595703125, 894.328125, 342.495849609375, 5.420483112335205078, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+193, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5441.81787109375, 872.76214599609375, 343.283294677734375, 5.11723184585571289, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+194, 189555, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5378.40625, 785.68927001953125, 427.739013671875, 0.789803028106689453, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Astral Attendant (Area: The Azure Vault - Difficulty: Mythic) (Auras: 378065 - Mage Hunter's Fervor)
(@CGUID+195, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5476.01220703125, 885.92535400390625, 343.59033203125, 5.412412643432617187, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+196, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5457.4599609375, 857.95489501953125, 343.283294677734375, 0.595290005207061767, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+197, 190510, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5311.07275390625, 751.8524169921875, 428.040985107421875, 2.120760917663574218, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Vault Guard (Area: The Azure Vault - Difficulty: Mythic) (Auras: 378065 - Mage Hunter's Fervor)
(@CGUID+198, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5447.87841796875, 879.4774169921875, 343.283294677734375, 2.641324758529663085, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+199, 189555, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5383.45166015625, 790.55206298828125, 427.739013671875, 0.789803028106689453, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Astral Attendant (Area: The Azure Vault - Difficulty: Mythic) (Auras: 378065 - Mage Hunter's Fervor)
(@CGUID+200, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5506.50341796875, 901.77777099609375, 342.495849609375, 3.742505073547363281, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+201, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5507.095703125, 913.14581298828125, 342.495849609375, 2.650505304336547851, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+202, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5467.19775390625, 862.560791015625, 343.449554443359375, 1.729497790336608886, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+203, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5468.4130859375, 858.5538330078125, 343.283294677734375, 2.188178300857543945, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+204, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5492.75, 896.1632080078125, 342.495849609375, 4.688315868377685546, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+205, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5461.29345703125, 850.60589599609375, 343.283294677734375, 4.66408538818359375, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+206, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5466.68212890625, 850.00518798828125, 343.283294677734375, 4.852331161499023437, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: ) (possible waypoints or random movement)
(@CGUID+207, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5496.33349609375, 905.46356201171875, 342.495849609375, 4.071735382080078125, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+208, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5491.01904296875, 889.1649169921875, 342.495849609375, 5.420483112335205078, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+209, 187240, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5485.91845703125, 890.05902099609375, 342.495849609375, 5.420483112335205078, 7200, 0, 0, 1144872, 0, 0, 0, 0, 0, 46879), -- Drakonid Breaker (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+210, 187242, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5498.07275390625, 875.0242919921875, 343.332305908203125, 5.420483112335205078, 7200, 0, 0, 429327, 0, 0, 0, 0, 0, 46879), -- Tarasek Looter (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+211, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5504.35595703125, 877.07293701171875, 343.624908447265625, 4.88421487808227539, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+212, 187246, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5527.02587890625, 906.27606201171875, 343.334808349609375, 2.659481763839721679, 7200, 0, 0, 715545, 3155, 0, 0, 0, 0, 46879), -- Nullmagic Hornswog (Area: The Azure Vault - Difficulty: Mythic) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+213, 190510, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5393.1630859375, 739.67535400390625, 432.062103271484375, 0.724837899208068847, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Vault Guard (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+214, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5522.6025390625, 892.248291015625, 343.625885009765625, 5.412412643432617187, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+215, 195638, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5514.595703125, 883.05206298828125, 343.624755859375, 5.412412643432617187, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Polymorphic Rune (Area: The Azure Vault - Difficulty: Mythic) (Auras: 386362 - Polymorphic Encyclopedia Cosmetic)
(@CGUID+216, 190510, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 1, -5374.65087890625, 724.88714599609375, 432.100982666015625, 1.032665252685546875, 7200, 0, 0, 787100, 0, 0, 0, 0, 0, 46879), -- Vault Guard (Area: The Azure Vault - Difficulty: Mythic) (Auras: )
(@CGUID+217, 194712, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5303.22412109375, 1075.576416015625, 509.261688232421875, 0.24352903664112091, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+218, 194712, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5362.24462890625, 1091.8802490234375, 509.384033203125, 2.36682748794555664, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+219, 194712, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5346.28466796875, 1032.3004150390625, 509.41748046875, 4.470751285552978515, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+220, 196693, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5289.25537109375, 1051.8055419921875, 157.7996826171875, 4.204859733581542968, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Shimmering Geode (Area: The Azure Vault - Difficulty: Mythic)
(@CGUID+221, 196693, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5371.26416015625, 1030.0382080078125, 157.7996978759765625, 0, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Shimmering Geode (Area: The Azure Vault - Difficulty: Mythic)
(@CGUID+222, 196693, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5368.53662109375, 1099.6927490234375, 157.7996978759765625, 0, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Shimmering Geode (Area: The Azure Vault - Difficulty: Mythic)
(@CGUID+223, 199545, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5373.30712890625, 1032.07470703125, 339.6318359375, 0.761273086071014404, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+224, 194715, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5349.04150390625, 1045.7117919921875, 340.5087890625, 4.146480083465576171, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+225, 194715, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5312.375, 1066.5833740234375, 340.525634765625, 0.077714234590530395, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+226, 194715, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5349.0087890625, 1088.1788330078125, 340.51678466796875, 2.083407402038574218, 7200, 0, 0, 143109, 0, 0, 0, 0, 0, 46879), -- Book of Translocation (Area: The Azure Vault - Difficulty: Mythic) (Auras: 384094 - Translocation Book Cosmetic)
(@CGUID+227, 186738, 2515, 13954, 13954, '2,8,23,1', 0, 0, 0, 0, -5344.81591796875, 1082.263916015625, 157.799713134765625, 5.106944561004638671, 7200, 0, 0, 6010578, 100, 0, 0, 0, 0, 46879); -- Umbrelskul (Area: The Azure Vault - Difficulty: Mythic) (Auras: 394104 - Override Display Power, 385656 - Dragon Sleeps)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+227;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Fury - 375407 - Ready Defense
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, 0, '370756 370223'), -- Shrieking Whelp - 370756 - Whelp Cosmetic, 370223 - Revealing Gaze
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Fury - 375407 - Ready Defense
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Fury - 375407 - Ready Defense
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Fury - 375407 - Ready Defense
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Fury - 375407 - Ready Defense
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, 0, '370756 370223'), -- Shrieking Whelp - 370756 - Whelp Cosmetic, 370223 - Revealing Gaze
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, 0, '370756 371042 397215'), -- Shrieking Whelp - 370756 - Whelp Cosmetic, 371042 - Revealing Gaze, 397215 - Revealing Gaze
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, 0, '370756 370223'), -- Shrieking Whelp - 370756 - Whelp Cosmetic, 370223 - Revealing Gaze
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Thrasher - 375407 - Ready Defense
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, 0, '387789 18950'), -- Unstable Curator - 387789 - Errant Pages, 18950 - Invisibility and Stealth Detection
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Fury - 375407 - Ready Defense
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, 0, '370756 371042 397215'), -- Shrieking Whelp - 370756 - Whelp Cosmetic, 371042 - Revealing Gaze, 397215 - Revealing Gaze
(@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, 5, '371537'), -- Small Arcane Rune - 371537 - -Unknown-
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, 0, '370756 371042 397215'), -- Shrieking Whelp - 370756 - Whelp Cosmetic, 371042 - Revealing Gaze, 397215 - Revealing Gaze
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, 5, '371537'), -- Small Arcane Rune - 371537 - -Unknown-
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, 5, '371537'), -- Small Arcane Rune - 371537 - -Unknown-
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Fury - 375407 - Ready Defense
(@CGUID+64, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Fury - 375407 - Ready Defense
(@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, 5, '371537'), -- Small Arcane Rune - 371537 - -Unknown-
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, 5, '371537'), -- Small Arcane Rune - 371537 - -Unknown-
(@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, 5, '371537'), -- Small Arcane Rune - 371537 - -Unknown-
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Thrasher - 375407 - Ready Defense
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, 0, '375407'), -- Crystal Fury - 375407 - Ready Defense
(@CGUID+98, 0, 0, 0, 1, 0, 0, 0, 0, 0, '387789'), -- Unstable Curator - 387789 - Errant Pages
(@CGUID+104, 0, 0, 0, 1, 601, 0, 0, 0, 0, ''), -- Arcane Construct
(@CGUID+105, 0, 0, 0, 1, 601, 0, 0, 0, 0, ''), -- Arcane Construct
(@CGUID+106, 0, 0, 33554432, 1, 0, 0, 0, 0, 0, ''), -- Icy Crystal
(@CGUID+107, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '387834'), -- Cosmetic Barrier Stalker - 387834 - Barrier Cosmetic
(@CGUID+111, 0, 0, 0, 1, 0, 0, 0, 0, 0, '388065'), -- Vault Rune - 388065 - Vault Rune
(@CGUID+112, 0, 0, 0, 1, 0, 0, 0, 0, 0, '387789 18950'), -- Unstable Curator - 387789 - Errant Pages, 18950 - Invisibility and Stealth Detection
(@CGUID+121, 0, 0, 0, 1, 0, 0, 0, 0, 0, '388065'), -- Vault Rune - 388065 - Vault Rune
(@CGUID+122, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '387835'), -- Cosmetic Barrier Stalker - 387835 - Barrier Cosmetic Small
(@CGUID+126, 0, 0, 0, 1, 0, 0, 0, 0, 0, '389686'), -- Crystal Fury - 389686 - Arcane Fury
(@CGUID+127, 0, 0, 0, 1, 0, 0, 0, 0, 0, '388065'), -- Vault Rune - 388065 - Vault Rune
(@CGUID+140, 0, 0, 0, 1, 27, 0, 0, 0, 0, ''), -- Telash Greywing
(@CGUID+182, 0, 0, 33554432, 1, 0, 0, 0, 0, 0, ''), -- Azure Vaults Crystal
(@CGUID+210, 0, 0, 0, 1, 438, 0, 0, 0, 0, ''), -- Tarasek Looter
(@CGUID+208, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Tarasek Looter
(@CGUID+192, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Tarasek Looter
(@CGUID+209, 0, 0, 0, 1, 333, 0, 0, 0, 0, '18950'); -- Drakonid Breaker - 18950 - Invisibility and Stealth Detection

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+17;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 385528, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5127.8974609375, 1069.3228759765625, 595.3614501953125, 5.34709787368774414, 0, 0, -0.451141357421875, 0.892452478408813476, 7200, 255, 1, 46879), -- Archival Parchment (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+1, 252248, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5040.02099609375, 1013.90631103515625, 597.4891357421875, 2.442746877670288085, 0, 0, 0.939570426940917968, 0.342355668544769287, 7200, 255, 1, 46879), -- Instance Portal (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+2, 377951, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5074.041015625, 1196.540771484375, 555.845947265625, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 1, 46879), -- 10DU_ArcaneVaults_Door01 (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+3, 319264, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5053.73779296875, 1253.52783203125, 560.83734130859375, 0, 0, 0, 0, 1, 7200, 255, 1, 46879), -- [DNT] Collision - Box (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+4, 245606, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5067.064453125, 1218.3507080078125, 556.27423095703125, 0, 0, 0, 0, 1, 7200, 255, 1, 46879), -- Cylinder Collision (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+5, 245606, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5096.24462890625, 1190.142333984375, 556.25738525390625, 0, 0, 0, 0, 1, 7200, 255, 1, 46879), -- Cylinder Collision (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+6, 247008, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5065.83349609375, 1290.2725830078125, 556.2742919921875, 0, 0, 0, 0, 1, 7200, 255, 1, 46879), -- Cylinder Collision (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+7, 343701, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5417.8818359375, 969.06597900390625, 344.470367431640625, 0, 0, 0, 0, 1, 7200, 255, 1, 46879), -- Collision Cylinder (1.1) (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+8, 247008, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5095.87158203125, 1318.4879150390625, 556.27423095703125, 0, 0, 0, 0, 1, 7200, 255, 1, 46879), -- Cylinder Collision (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+9, 380536, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5074.5947265625, 1310.5635986328125, 556.0296630859375, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 7200, 255, 0, 46879), -- 10DU_ArcaneVaults_Door01 (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+10, 380537, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5270.39990234375, 740.0396728515625, 431.3189697265625, 2.507381439208984375, 0, 0, 0.95014190673828125, 0.311817854642868041, 7200, 255, 1, 46879), -- 10FX_Generic_Dragon_Blue_Door02 (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+11, 343701, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5434.8974609375, 985.86285400390625, 344.470367431640625, 0, 0, 0, 0, 1, 7200, 255, 1, 46879), -- Collision Cylinder (1.1) (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+12, 377952, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5336.5419921875, 870.466796875, 427.63433837890625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 0, 46879), -- 10DU_ArcaneVaults_Door01 (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+13, 385529, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5333.36279296875, 1278.7413330078125, 511.47711181640625, 5.34709787368774414, 0, 0, -0.451141357421875, 0.892452478408813476, 7200, 255, 1, 46879), -- Archival Parchment (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+14, 385531, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5244.66845703125, 865.498291015625, 389.623443603515625, 6.044476985931396484, 0, 0, -0.11907100677490234, 0.992885708808898925, 7200, 255, 1, 46879), -- Archival Parchment (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+15, 385530, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5387.69775390625, 843.59722900390625, 429.095550537109375, 6.044476985931396484, 0, 0, -0.11907100677490234, 0.992885708808898925, 7200, 255, 1, 46879), -- Archival Parchment (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+16, 385532, 2515, 13954, 13954, '2,8,23,1', 0, 0, -5519.3369140625, 936.14581298828125, 344.50579833984375, 6.044476985931396484, 0, 0, -0.11907100677490234, 0.992885708808898925, 7200, 255, 1, 46879), -- Archival Parchment (Area: The Azure Vault - Difficulty: Mythic)
(@OGUID+17, 246779, 2515, 13954, 13954, '8,23', 0, 0, -5051.85400390625, 1033.0850830078125, 594.45172119140625, 0.072365336120128631, 0, 0, 0.036174774169921875, 0.999345481395721435, 7200, 255, 1, 47213); -- Font of Power (Area: The Azure Vault - Difficulty: Mythic)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+16;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10DU_ArcaneVaults_Door01
(@OGUID+9, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10DU_ArcaneVaults_Door01
(@OGUID+10, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10FX_Generic_Dragon_Blue_Door02
(@OGUID+12, 0, 0, 1, -0.00000004371138828, 0, 0); -- 10DU_ArcaneVaults_Door01

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (186644,186738,186739,186737,191739,187246,187240,197081,190509,196205,187154,188100,195638,196102,194715,199545,194712,194714,195432,194713,195434,194618,194602);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(186644, 0, 0, 0, 1, 0, 0, 0, 0, 3, '375729'), -- 186644 (Leymor) - Stasis
(186738, 0, 0, 0, 1, 0, 0, 0, 0, 0, '394104 385656'), -- 186738 (Umbrelskul) - Override Display Power, Dragon Sleeps
(186739, 0, 0, 0, 1, 0, 0, 0, 0, 0, '377039 389340'), -- 186739 (Azureblade) - 10.0 Dungeon - Azure Vault - Boss 2 - Draconic Illusion Rune 04 Boss Visual, Arcane Mana [DNT]
(186737, 0, 0, 0, 1, 0, 0, 0, 0, 0, '389454'), -- 186737 (Telash Greywing) - Ice Power [DNT]
(191739, 0, 0, 0, 1, 0, 0, 0, 0, 0, '377980 378065 18950'), -- 191739 (Scalebane Lieutenant) - Mage Hunter's Fervor, Mage Hunter's Fervor, Invisibility and Stealth Detection
(187246, 0, 0, 0, 1, 0, 0, 0, 0, 0, '18950'), -- 187246 (Nullmagic Hornswog) - Invisibility and Stealth Detection
(187240, 0, 0, 0, 1, 0, 0, 0, 0, 0, '18950'), -- 187240 (Drakonid Breaker) - Invisibility and Stealth Detection
(197081, 0, 0, 0, 1, 0, 0, 0, 0, 0, '389786'), -- 197081 (Sindragosa) - Shortcut Portal
(190509, 0, 0, 0, 1, 0, 0, 0, 0, 0, '374161'), -- 190509 (Ley-Line Sprout) - Ley-Line Sprout
(196205, 0, 0, 0, 1, 0, 0, 0, 0, 0, '387789'), -- 196205 (Errant Pages) - Errant Pages
(195638, 0, 0, 0, 1, 0, 0, 0, 0, 0, '386362'), -- 195638 (Polymorphic Rune) - Polymorphic Encyclopedia Cosmetic
(196102, 0, 0, 0, 1, 0, 0, 0, 0, 0, '177645'), -- 196102 (Conjured Lasher) - Submerged
(194715, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '384094'), -- 194715 (Book of Translocation) - Translocation Book Cosmetic
(199545, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '384094'), -- 199545 (Book of Translocation) - Translocation Book Cosmetic
(194712, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '384094'), -- 194712 (Book of Translocation) - Translocation Book Cosmetic
(194714, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '384094'), -- 194714 (Book of Translocation) - Translocation Book Cosmetic
(195432, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '384094'), -- 195432 (Book of Translocation) - Translocation Book Cosmetic
(194713, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '384094'), -- 194713 (Book of Translocation) - Translocation Book Cosmetic
(195434, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '384094'), -- 195434 (Book of Translocation) - Translocation Book Cosmetic
(194618, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '384094'), -- 194618 (Book of Translocation) - Translocation Book Cosmetic
(194602, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '384094'); -- 194602 (Book of Translocation) - Translocation Book Cosmetic

-- Creature Template
UPDATE `creature_template` SET `minlevel`=72, `maxlevel`=72, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry` IN (188046, 197081); -- Sindragosa
UPDATE `creature_template` SET `minlevel`=71, `maxlevel`=71, `faction`=14, `speed_walk`=1.20000004768371582, `speed_run`=0.428571432828903198, `BaseAttackTime`=2000, `unit_flags`=33587200, `unit_flags3`=19398656 WHERE `entry`=194806; -- Crackling Vortex
UPDATE `creature_template` SET `minlevel`=73, `maxlevel`=73, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=25690113 WHERE `entry`=194978; -- Arcane Eruption
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=33554464, `unit_flags3`=8912897 WHERE `entry`=195138; -- Detonating Crystal
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=33554464, `unit_flags3`=8912897 WHERE `entry`=199368; -- Hardened Crystal
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=33556480, `unit_flags3`=25690113 WHERE `entry`=194826; -- Ping Stalker
UPDATE `creature_template` SET `minlevel`=72, `maxlevel`=72, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `HoverHeight`=16.5 WHERE `entry`=186738; -- Umbrelskul
UPDATE `creature_template` SET `gossip_menu_id`=29013, `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=16777217 WHERE `entry`=194715; -- Book of Translocation
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=16777217 WHERE `entry` IN (199545, 195432, 195434, 194618); -- Book of Translocation
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=524289 WHERE `entry`=192955; -- Draconic Illusion
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=190187; -- Draconic Image
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=16777217 WHERE `entry`=196693; -- Shimmering Geode
UPDATE `creature_template` SET `gossip_menu_id`=29009, `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=16777217 WHERE `entry`=194712; -- Book of Translocation
UPDATE `creature_template` SET `minlevel`=72, `maxlevel`=72, `faction`=16, `speed_walk`=2.799999952316284179, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=186739; -- Azureblade
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=16777217 WHERE `entry`=190517; -- Azure Vaults Crystal
UPDATE `creature_template` SET `minlevel`=72, `maxlevel`=72, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=191739; -- Scalebane Lieutenant
UPDATE `creature_template` SET `minlevel`=72, `maxlevel`=72, `faction`=16, `speed_walk`=3.20000004768371582, `speed_run`=1.857142806053161621, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags3`=1 WHERE `entry`=199614; -- Telash Greywing
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=67141696, `unit_flags2`=2048, `unit_flags3`=131072 WHERE `entry`=187246; -- Nullmagic Hornswog
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=190510; -- Vault Guard
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187242; -- Tarasek Looter
UPDATE `creature_template` SET `minlevel`=71, `maxlevel`=71, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187240; -- Drakonid Breaker
UPDATE `creature_template` SET `gossip_menu_id`=29012, `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=16777217 WHERE `entry`=194714; -- Book of Translocation
UPDATE `creature_template` SET `minlevel`=72, `maxlevel`=72, `faction`=16, `speed_walk`=3.20000004768371582, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=186737; -- Telash Greywing
UPDATE `creature_template` SET `gossip_menu_id`=29011, `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=16777217 WHERE `entry`=194713; -- Book of Translocation
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=14, `speed_walk`=2, `speed_run`=2.142857074737548828, `BaseAttackTime`=1809 WHERE `entry`=189988; -- Thing From Beyond
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=14, `speed_walk`=2.40000009536743164, `speed_run`=1.571428537368774414, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2080, `unit_flags3`=524288 WHERE `entry`=196559; -- Volatile Sapling
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67160064, `unit_flags3`=21495808, `HoverHeight`=3 WHERE `entry`=190509; -- Ley-Line Sprout
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `speed_walk`=2, `speed_run`=1.285714268684387207, `BaseAttackTime`=835, `unit_flags2`=2048 WHERE `entry`=62982; -- Mindbender
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=32768, `unit_flags3`=16809985 WHERE `entry`=197204; -- Vault Rune
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=33556480, `unit_flags3`=25165825 WHERE `entry`=196211; -- Cosmetic Barrier Stalker
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67141632, `unit_flags3`=16809985 WHERE `entry`=197643; -- Icy Crystal
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=335546368 WHERE `entry`=189085; -- Past Self
UPDATE `creature_template` SET `minlevel`=71, `maxlevel`=71, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=196117; -- Crystal Thrasher
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=16777217, `HoverHeight`=4 WHERE `entry`=198422; -- Tome of Transmogrification
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `speed_walk`=4.800000190734863281, `speed_run`=1.714285731315612792, `BaseAttackTime`=1712, `unit_flags2`=2048 WHERE `entry`=110063; -- Beast
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=14, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33849920, `unit_flags2`=2048 WHERE `entry`=187160; -- Crystal Fury
UPDATE `creature_template` SET `gossip_menu_id`=28961, `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=16777217 WHERE `entry`=194602; -- Book of Translocation
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048, `unit_flags3`=524289 WHERE `entry`=187999; -- Shrieking Whelp
UPDATE `creature_template` SET `minlevel`=72, `maxlevel`=72, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187482; -- Sindragosa
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=1798, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=165189; -- Generic Hunter Pet
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=189555; -- Astral Attendant
UPDATE `creature_template` SET `minlevel`=71, `maxlevel`=71, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=186740; -- Arcane Construct
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=33556480, `unit_flags3`=25165825 WHERE `entry`=196441; -- Cosmetic Taxi Path Stalker
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=1140852736, `unit_flags3`=16777216 WHERE `entry`=188714; -- Small Arcane Rune
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=33556480, `unit_flags3`=25165825 WHERE `entry`=196205; -- Errant Pages
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187155; -- Rune Seal Keeper
UPDATE `creature_template` SET `minlevel`=71, `maxlevel`=71, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187154; -- Unstable Curator
UPDATE `creature_template` SET `minlevel`=71, `maxlevel`=71, `faction`=14, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187139; -- Crystal Thrasher
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=186741; -- Arcane Elemental
UPDATE `creature_template` SET `minlevel`=71, `maxlevel`=71, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=67141696, `unit_flags2`=2048 WHERE `entry` IN (191164, 196115); -- Arcane Tender
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=14, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry` IN (188100, 187159); -- Shrieking Whelp
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `speed_walk`=2.40000009536743164, `speed_run`=1.571428537368774414, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=191313; -- Bubbling Sapling
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=33554464, `unit_flags3`=25165825 WHERE `entry`=195638; -- Polymorphic Rune
UPDATE `creature_template` SET `minlevel`=72, `maxlevel`=72, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2097152 WHERE `entry`=186644; -- Leymor
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=67141696, `unit_flags2`=2048 WHERE `entry`=196102; -- Conjured Lasher
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=14, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187160; -- Crystal Fury
UPDATE `creature_template` SET `gossip_menu_id`=27896 WHERE `entry`=188046; -- Sindragosa
UPDATE `creature_template` SET `gossip_menu_id`=29759 WHERE `entry`=197081; -- Sindragosa

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (191739,190510,187240));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(191739, 1, 191714, 0, 0, 193843, 0, 0, 0, 0, 0, 46879), -- Scalebane Lieutenant
(190510, 1, 191571, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Vault Guard
(187240, 1, 200724, 0, 0, 0, 0, 0, 0, 0, 0, 46879); -- Drakonid Breaker

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureID` IN (196211);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(196211, 0, 0, 1, 1, 0, 0, NULL);

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+6;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 228162, 0, 0, 0, 0, 0, 0, 0, 46879), -- 194602 (Book of Translocation)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 228160, 0, 0, 0, 0, 0, 0, 0, 46879), -- 194712 (Book of Translocation)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 228350, 0, 0, 0, 0, 0, 0, 0, 46879), -- 194713 (Book of Translocation)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 228351, 0, 0, 0, 0, 0, 0, 0, 46879), -- 194714 (Book of Translocation)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 228354, 0, 0, 0, 0, 0, 0, 0, 46879), -- 194715 (Book of Translocation)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 217381, 0, 0, 0, 0, 0, 0, 0, 47213), -- 188046 (Sindragosa)
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 230969, 0, 0, 0, 0, 0, 0, 0, 47213); -- 197081 (Sindragosa)

DELETE FROM `gossip_menu` WHERE (`MenuID`=28961 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=29009 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=29011 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=29012 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=29013 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=27896 AND `TextID`=@NPCTEXTID+5) OR (`MenuID`=29759 AND `TextID`=@NPCTEXTID+6);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(28961, @NPCTEXTID+0, 46879), -- 194602 (Book of Translocation)
(29009, @NPCTEXTID+1, 46879), -- 194712 (Book of Translocation)
(29011, @NPCTEXTID+2, 46879), -- 194713 (Book of Translocation)
(29012, @NPCTEXTID+3, 46879), -- 194714 (Book of Translocation)
(29013, @NPCTEXTID+4, 46879), -- 194715 (Book of Translocation)
(27896, @NPCTEXTID+5, 47213), -- 188046 (Sindragosa)
(29759, @NPCTEXTID+6, 47213); -- 197081 (Sindragosa)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (29012,29011,28961,29009,29013,27896)) OR (`MenuID`=29759 AND `OptionID` IN (2,1,0));
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(56250, 29012, 0, 0, 'Proceed onward.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 46879),
(56248, 29011, 0, 0, 'Proceed onward.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 46879),
(56056, 28961, 0, 0, 'Proceed onward.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 46879),
(56247, 29009, 0, 0, 'Proceed onward.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 46879),
(56251, 29013, 0, 0, 'Proceed onward.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 46879),
(54920, 27896, 0, 0, 'I\'m ready.', 27602, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 47213),
(107093, 29759, 2, 0, 'Take me to the Crystal Chambers.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 47213),
(107092, 29759, 1, 0, 'Take me to the Mausoleum of Legends.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 47213),
(107451, 29759, 0, 0, 'Take me to the Arcane Conservatory.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 47213);

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=23 AND `Entry` IN (188046,194978,195138,194826,186738,194715,199545,190187,194712,186739,190517,191739,199614,187246,190510,187242,187240,194714,195432,186737,194713,197081,190509,62982,197204,196211,197643,196117,195434,198422,196116,194618,194602,187999,187482));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(188046, 23, 2, 2, 2157, 46879),
(194978, 23, 3, 3, 2157, 46879),
(195138, 23, 0, 0, 2157, 46879),
(194826, 23, 0, 0, 2157, 46879),
(186738, 23, 2, 2, 2157, 46879),
(194715, 23, 0, 0, 2157, 46879),
(199545, 23, 0, 0, 2157, 46879),
(190187, 23, 0, 0, 2157, 46879),
(194712, 23, 0, 0, 2157, 46879),
(186739, 23, 2, 2, 2157, 46879),
(190517, 23, 0, 0, 2157, 46879),
(191739, 23, 2, 2, 2157, 46879),
(199614, 23, 2, 2, 2157, 46879),
(187246, 23, 0, 0, 2157, 46879),
(190510, 23, 0, 0, 2157, 46879),
(187242, 23, 0, 0, 2157, 46879),
(187240, 23, 1, 1, 2157, 46879),
(194714, 23, 0, 0, 2157, 46879),
(195432, 23, 0, 0, 2157, 46879),
(186737, 23, 2, 2, 2157, 46879),
(194713, 23, 0, 0, 2157, 46879),
(197081, 23, 2, 2, 2157, 46879),
(190509, 23, 0, 0, 2157, 46879),
(62982, 23, 0, 0, 482, 46879),
(197204, 23, 0, 0, 2157, 46879),
(196211, 23, 0, 0, 2157, 46879),
(197643, 23, 0, 0, 2157, 46879),
(196117, 23, 1, 1, 2157, 46879),
(195434, 23, 0, 0, 2157, 46879),
(198422, 23, 0, 0, 2157, 46879),
(196116, 23, 0, 0, 2157, 46879),
(194618, 23, 0, 0, 2157, 46879),
(194602, 23, 0, 0, 2157, 46879),
(187999, 23, 0, 0, 2157, 46879),
(187482, 23, 2, 2, 2157, 46879);

-- Waypoints for CGUID+1
SET @PATH := (@CGUID+1) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -5084.969, 1090.668, 594.6889, NULL, 0),
(@PATH, 1, -5090.412, 1091.979, 594.8563, NULL, 0),
(@PATH, 2, -5095.897, 1091.672, 594.7381, NULL, 0),
(@PATH, 3, -5100.052, 1090.776, 594.738, NULL, 0),
(@PATH, 4, -5105.644, 1088.609, 594.4575, NULL, 0),
(@PATH, 5, -5108.438, 1086.561, 594.455, NULL, 0),
(@PATH, 6, -5111.912, 1082.656, 594.4991, NULL, 0),
(@PATH, 7, -5114.643, 1078.247, 594.496, NULL, 0),
(@PATH, 8, -5116.757, 1073.738, 594.738, NULL, 0),
(@PATH, 9, -5117.915, 1068.349, 594.9324, NULL, 0),
(@PATH, 10, -5117.588, 1062.727, 594.9255, NULL, 0),
(@PATH, 11, -5114.958, 1054.814, 594.7914, NULL, 0),
(@PATH, 12, -5111.893, 1050.427, 594.4543, NULL, 0),
(@PATH, 13, -5107.374, 1046.634, 594.6328, NULL, 0),
(@PATH, 14, -5101.537, 1043.38, 594.6736, NULL, 0),
(@PATH, 15, -5095.476, 1041.788, 594.5441, NULL, 0),
(@PATH, 16, -5088.979, 1042.383, 594.5934, NULL, 0),
(@PATH, 17, -5084.413, 1043.767, 594.7261, NULL, 0),
(@PATH, 18, -5078.88, 1047.031, 594.6031, NULL, 0),
(@PATH, 19, -5073.03, 1052.765, 594.6672, NULL, 0),
(@PATH, 20, -5069.399, 1059.12, 594.6553, NULL, 0),
(@PATH, 21, -5067.768, 1065.816, 594.6733, NULL, 0),
(@PATH, 22, -5069.325, 1074.198, 594.5251, NULL, 0),
(@PATH, 23, -5072.257, 1080.686, 594.5455, NULL, 0),
(@PATH, 24, -5078.097, 1086.898, 594.6928, NULL, 0);

UPDATE `creature` SET `position_x`= -5084.969, `position_y`= 1090.668, `position_z`= 594.6889, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID+1, @PATH, 1, '370756 370223');

-- Waypoints for CGUID+30
SET @PATH := (@CGUID+30) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -5062.425, 1186.818, 594.3318, NULL, 0),
(@PATH, 1, -5075.549, 1173.948, 594.3318, NULL, 0),
(@PATH, 2, -5062.425, 1186.818, 594.3318, NULL, 0),
(@PATH, 3, -5048.849, 1202.469, 594.3318, NULL, 0);

UPDATE `creature` SET `position_x`= -5062.425, `position_y`= 1186.818, `position_z`= 594.3318, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+30;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+30;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID+30, @PATH, 1, '370756 370223');

-- Waypoints for CGUID+18
SET @PATH := (@CGUID+18) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -5056.688, 1179.981, 594.3318, NULL, 0),
(@PATH, 1, -5042.717, 1196.458, 594.2975, NULL, 0),
(@PATH, 2, -5056.688, 1179.981, 594.3318, NULL, 0),
(@PATH, 3, -5068.59, 1167.47, 594.3318, NULL, 0);

UPDATE `creature` SET `position_x`= -5056.688, `position_y`= 1179.981, `position_z`= 594.3318, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+18;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID+18, @PATH, 1, '370756 370223');

-- Waypoints for CGUID+45
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+45;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+45, @CGUID+45, 0, 0, 515, 0, 0),
(@CGUID+45, @CGUID+41, 6, 90, 515, 0, 0),
(@CGUID+45, @CGUID+27, 6, 270, 515, 0, 0);

SET @PATH := (@CGUID+45) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -5284.068, 1053.436, 508.1577, NULL, 0),
(@PATH, 1, -5282.549, 1065.071, 508.1286, NULL, 0),
(@PATH, 2, -5285.865, 1076.391, 508.1287, NULL, 5457),
(@PATH, 3, -5282.549, 1065.071, 508.1286, NULL, 0),
(@PATH, 4, -5284.068, 1053.436, 508.1577, NULL, 0),
(@PATH, 5, -5289, 1038.382, 508.1651, NULL, 0),
(@PATH, 6, -5299.188, 1026.884, 508.1286, NULL, 0),
(@PATH, 7, -5313.726, 1014.839, 508.2696, NULL, 0),
(@PATH, 8, -5330.155, 1011.533, 508.1492, NULL, 0),
(@PATH, 9, -5343.51, 1014.877, 508.1287, NULL, 5435),
(@PATH, 10, -5330.155, 1011.533, 508.1492, NULL, 0),
(@PATH, 11, -5313.726, 1014.839, 508.2696, NULL, 0),
(@PATH, 12, -5299.188, 1026.884, 508.1286, NULL, 0),
(@PATH, 13, -5289, 1038.382, 508.1651, NULL, 0),
(@PATH, 14, -5284.068, 1053.436, 508.1577, NULL, 0),
(@PATH, 15, -5282.549, 1065.071, 508.1286, NULL, 0);

UPDATE `creature` SET `position_x`= -5284.068, `position_y`= 1053.436, `position_z`= 508.1577, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+45;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+45;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+45, @PATH, 1);

-- Waypoints for CGUID+100
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+100;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+100, @CGUID+100, 0, 0, 515, 0, 0),
(@CGUID+100, @CGUID+88, 6, 270, 515, 0, 0);

SET @PATH := (@CGUID+100) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -5386.249, 1093.043, 508.2291, NULL, 5918),
(@PATH, 1, -5390.624, 1083.365, 508.1287, NULL, 0),
(@PATH, 2, -5392.252, 1063.304, 508.1286, NULL, 0),
(@PATH, 3, -5388.712, 1046.87, 508.1287, NULL, 0),
(@PATH, 4, -5384.101, 1037.212, 508.1287, NULL, 0),
(@PATH, 5, -5370.165, 1021.696, 508.2078, NULL, 0),
(@PATH, 6, -5358.96, 1017.267, 508.1286, NULL, 5884),
(@PATH, 7, -5370.165, 1021.696, 508.2078, NULL, 0),
(@PATH, 8, -5384.101, 1037.212, 508.1287, NULL, 0),
(@PATH, 9, -5388.712, 1046.87, 508.1287, NULL, 0),
(@PATH, 10, -5392.252, 1063.304, 508.1286, NULL, 0),
(@PATH, 11, -5390.624, 1083.365, 508.1287, NULL, 0);

UPDATE `creature` SET `position_x`= -5386.249, `position_y`= 1093.043, `position_z`= 508.2291, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+100;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+100;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+100, @PATH, 1);

-- Waypoints for CGUID+73
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+73;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+73, @CGUID+73, 0, 0, 515, 0, 0),
(@CGUID+73, @CGUID+74, 6, 90, 515, 0, 0),
(@CGUID+73, @CGUID+72, 6, 270, 515, 0, 0);

SET @PATH := (@CGUID+73) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -5336.948, 1011.005, 425.3318, NULL, 0),
(@PATH, 1, -5321.103, 1015.786, 425.4664, NULL, 0),
(@PATH, 2, -5294.158, 1036.083, 425.3329, NULL, 0),
(@PATH, 3, -5282.436, 1057.899, 425.4006, NULL, 0),
(@PATH, 4, -5281.37, 1079.247, 425.3318, NULL, 0),
(@PATH, 5, -5290.037, 1093.908, 425.3317, NULL, 5878),
(@PATH, 6, -5281.37, 1079.247, 425.3318, NULL, 0),
(@PATH, 7, -5282.436, 1057.899, 425.4006, NULL, 0),
(@PATH, 8, -5294.158, 1036.083, 425.3329, NULL, 0),
(@PATH, 9, -5321.103, 1015.786, 425.4664, NULL, 0),
(@PATH, 10, -5336.948, 1011.005, 425.3318, NULL, 0),
(@PATH, 11, -5362.375, 1016.54, 425.3317, NULL, 0),
(@PATH, 12, -5380.521, 1038.097, 425.4003, NULL, 0),
(@PATH, 13, -5392.17, 1059.262, 425.3318, NULL, 0),
(@PATH, 14, -5391.674, 1077.174, 425.3318, NULL, 0),
(@PATH, 15, -5384.912, 1093.793, 425.3318, NULL, 5988),
(@PATH, 16, -5391.674, 1077.174, 425.3318, NULL, 0),
(@PATH, 17, -5392.17, 1059.262, 425.3318, NULL, 0),
(@PATH, 18, -5380.521, 1038.097, 425.4003, NULL, 0),
(@PATH, 19, -5362.375, 1016.54, 425.3317, NULL, 0);

UPDATE `creature` SET `position_x`= -5336.948, `position_y`= 1011.005, `position_z`= 425.3318, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+73;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+73;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+73, @PATH, 1);

-- Waypoints for CGUID+177
SET @PATH := (@CGUID+177) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -5370.667, 800.0278, 427.7422, NULL, 0),
(@PATH, 1, -5366.304, 810.0677, 427.843, NULL, 0),
(@PATH, 2, -5360.606, 816.8299, 427.8607, NULL, 0),
(@PATH, 3, -5352.311, 821.1302, 427.8307, NULL, 0),
(@PATH, 4, -5342.165, 822.3559, 427.772, NULL, 0),
(@PATH, 5, -5330.979, 821.7621, 427.7501, NULL, 0),
(@PATH, 6, -5321.753, 819.8229, 427.8124, NULL, 0),
(@PATH, 7, -5312.49, 815.6875, 427.86, NULL, 0),
(@PATH, 8, -5304.439, 806.5903, 427.7993, NULL, 0),
(@PATH, 9, -5300.097, 795.2969, 427.738, NULL, 0),
(@PATH, 10, -5298.927, 786.5417, 427.738, NULL, 0),
(@PATH, 11, -5300.552, 777.6996, 427.7496, NULL, 0),
(@PATH, 12, -5306.344, 768.0434, 427.738, NULL, 0),
(@PATH, 13, -5314.731, 762.3785, 427.7696, NULL, 0),
(@PATH, 14, -5322.597, 732.1493, 432.1287, NULL, 0),
(@PATH, 15, -5336.396, 727.6042, 432.6013, NULL, 0),
(@PATH, 16, -5350.78, 732.0955, 432.1286, NULL, 0),
(@PATH, 17, -5352.113, 760.0035, 427.8692, NULL, 0),
(@PATH, 18, -5361.5, 765.3524, 427.8928, NULL, 0),
(@PATH, 19, -5369.866, 775.9271, 427.738, NULL, 0),
(@PATH, 20, -5372.194, 788.8611, 427.738, NULL, 0);

UPDATE `creature` SET `position_x`= -5370.667, `position_y`= 800.0278, `position_z`= 427.7422, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+177;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+177;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID+177, @PATH, 1, '377980 378065 18950');

-- Waypoints for CGUID+163
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+163;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+163, @CGUID+163, 0, 0, 515, 0, 0),
(@CGUID+163, @CGUID+154, 6, 90, 515, 0, 0),
(@CGUID+163, @CGUID+164, 6, 270, 515, 0, 0);

SET @PATH := (@CGUID+163) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -5352.257, 833.3976, 427.81, NULL, 0),
(@PATH, 1, -5363.675, 828.5261, 427.8567, NULL, 11810),
(@PATH, 2, -5352.257, 833.3976, 427.81, NULL, 0),
(@PATH, 3, -5337.918, 833.7257, 427.7785, NULL, 0),
(@PATH, 4, -5321.722, 833.7205, 427.8018, NULL, 0),
(@PATH, 5, -5311.012, 828.8264, 427.8866, NULL, 11778),
(@PATH, 6, -5321.722, 833.7205, 427.8018, NULL, 0),
(@PATH, 7, -5337.918, 833.7257, 427.7785, NULL, 0);

UPDATE `creature` SET `position_x`= -5352.257, `position_y`= 833.3976, `position_z`= 427.81, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+163;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+163;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+163, @PATH, 1);

-- Waypoints for CGUID+134
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+134;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+134, @CGUID+134, 0, 0, 515, 0, 0),
(@CGUID+134, @CGUID+132, 4, 90, 515, 0, 0),
(@CGUID+134, @CGUID+131, 4, 270, 515, 0, 0);

SET @PATH := (@CGUID+134) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -5306.203, 895.5643, 385.7921, NULL, 0),
(@PATH, 1, -5295.641, 896.4913, 388.6919, NULL, 0),
(@PATH, 2, -5306.203, 895.5643, 385.7921, NULL, 0),
(@PATH, 3, -5333.334, 894.8699, 375.3292, NULL, 0),
(@PATH, 4, -5364.387, 899.2418, 359.92, NULL, 0),
(@PATH, 5, -5397.365, 908.0313, 345.3228, NULL, 0),
(@PATH, 6, -5413.002, 913.4739, 343.3318, NULL, 0),
(@PATH, 7, -5397.365, 908.0313, 345.3228, NULL, 0),
(@PATH, 8, -5364.507, 899.2587, 359.8522, NULL, 0),
(@PATH, 9, -5333.476, 894.8663, 375.2502, NULL, 0),
(@PATH, 10, -5306.203, 895.5643, 385.7921, NULL, 0),
(@PATH, 11, -5295.641, 896.4913, 388.6919, NULL, 0),
(@PATH, 12, -5306.203, 895.5643, 385.7921, NULL, 0);

UPDATE `creature` SET `position_x`= -5306.203, `position_y`= 895.5643, `position_z`= 385.7921, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+134;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+134;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+134, @PATH, 1);

-- Waypoints for CGUID+174
SET @PATH := (@CGUID+174) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, -5281.743, 828.118, 387.9681, NULL, 0, 1),
(@PATH, 1, -5294.483, 820.7239, 388.8017, NULL, 0, 1),
(@PATH, 2, -5281.743, 828.118, 387.9681, NULL, 0, 1),
(@PATH, 3, -5272.097, 831.6736, 387.9381, NULL, 0, 1),
(@PATH, 4, -5262.897, 828.8125, 387.9255, NULL, 0, 1),
(@PATH, 5, -5249.408, 821.1684, 388.738, NULL, 0, 1),
(@PATH, 6, -5262.897, 828.8125, 387.9255, NULL, 0, 1),
(@PATH, 7, -5272.097, 831.6736, 387.9381, NULL, 0, 1);

UPDATE `creature` SET `position_x`= -5281.743, `position_y`= 828.118, `position_z`= 387.9681, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+174;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+174;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+174, @PATH, 1);

-- Waypoints for CGUID+155
SET @PATH := (@CGUID+155) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, -5507.957, 921.1493, 342.5349, NULL, 0, 1),
(@PATH, 1, -5514.847, 913.0035, 342.5349, NULL, 0, 1),
(@PATH, 2, -5516.09, 903.3333, 342.5349, NULL, 0, 1),
(@PATH, 3, -5511.128, 893.368, 342.5349, NULL, 0, 1),
(@PATH, 4, -5518.932, 885.9844, 343.5879, NULL, 0, 1),
(@PATH, 5, -5516.09, 903.3333, 342.5349, NULL, 0, 1),
(@PATH, 6, -5514.847, 913.0035, 342.5349, NULL, 0, 1),
(@PATH, 7, -5507.957, 921.1493, 342.5349, NULL, 0, 1),
(@PATH, 8, -5498.543, 936.9827, 343.5349, NULL, 0, 1);

UPDATE `creature` SET `position_x`= -5507.957, `position_y`= 921.1493, `position_z`= 342.5349, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+155;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+155;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+155, @PATH, 1);

-- Waypoints for CGUID+137
SET @PATH := (@CGUID+137) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, -5282.026, 861.0434, 387.9218, NULL, 0, 1),
(@PATH, 1, -5288.321, 855.7222, 387.9923, NULL, 0, 1),
(@PATH, 2, -5294.463, 852.4601, 388.8914, NULL, 0, 1),
(@PATH, 3, -5304.245, 847.6996, 388.738, NULL, 0, 1),
(@PATH, 4, -5288.321, 855.7222, 387.9923, NULL, 0, 1),
(@PATH, 5, -5282.026, 861.0434, 387.9218, NULL, 0, 1),
(@PATH, 6, -5277.604, 865.3976, 388.7098, NULL, 0, 1),
(@PATH, 7, -5273.783, 871.6632, 388.7771, NULL, 0, 1),
(@PATH, 8, -5269.88, 873.1646, 388.7516, NULL, 0, 1),
(@PATH, 9, -5263.374, 866.8524, 388.9681, NULL, 0, 1),
(@PATH, 10, -5258.264, 858.9653, 387.9255, NULL, 0, 1),
(@PATH, 11, -5251.495, 852.7813, 388.041, NULL, 0, 1),
(@PATH, 12, -5247.521, 846.4716, 388.9266, NULL, 0, 1),
(@PATH, 13, -5269.78, 873.1727, 388.7166, NULL, 0, 1),
(@PATH, 14, -5277.604, 865.3976, 388.7098, NULL, 0, 1),
(@PATH, 15, -5282.026, 861.0434, 387.9218, NULL, 0, 1);

UPDATE `creature` SET `position_x`= -5282.026, `position_y`= 861.0434, `position_z`= 387.9218, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+137;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+137;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+137, @PATH, 1);
