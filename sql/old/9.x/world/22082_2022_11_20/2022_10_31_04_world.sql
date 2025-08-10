-- 
SET @CGUID := 651343;
SET @OGUID := 400379;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 109825, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2927.71435546875, 7699.83837890625, 4.174652099609375, 4.059299945831298828, 120, 10, 0, 375420, 0, 0, 0, 0, 0, 46366), -- Aria Sorrowheart (Area: Bradensbrook - Difficulty: 0) (Auras: )
(@CGUID+1, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2942.464111328125, 7719.35302734375, 25.02996826171875, 0.82129836082458496, 120, 10, 0, 18771, 0, 1, 0, 0, 0, 46366), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+2, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2950.013916015625, 7713.34912109375, 18.54337310791015625, 3.571464061737060546, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0)
(@CGUID+3, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2923.481689453125, 7710.09619140625, 23.0248870849609375, 2.990211725234985351, 120, 10, 0, 18771, 0, 1, 0, 0, 0, 46366), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+4, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2917.4296875, 7712.92041015625, 26.51630783081054687, 4.414573192596435546, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0)
(@CGUID+5, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2931.49951171875, 7702.32470703125, 23.1578216552734375, 1.69829726219177246, 120, 10, 0, 18771, 0, 1, 0, 0, 0, 46366), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+6, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2921.678955078125, 7713.064453125, 14.75717449188232421, 4.414573192596435546, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0)
(@CGUID+7, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2959.618408203125, 7705.2802734375, 27.13754844665527343, 4.823349952697753906, 120, 10, 0, 18771, 0, 1, 0, 0, 0, 46366), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+8, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2934.327392578125, 7696.11572265625, 25.71790313720703125, 4.198917388916015625, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0)
(@CGUID+9, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2931.9912109375, 7735.87109375, 18.94083023071289062, 6.19074249267578125, 120, 10, 0, 18771, 0, 1, 0, 0, 0, 46366), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+10, 109734, 1220, 7558, 7779, '0', 0, 0, 0, 0, 2906.13720703125, 7677.853515625, 4.001736164093017578, 4.70738077163696289, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Hag of the Crooked Tree (Area: Radcliffe Landing - Difficulty: 0)
(@CGUID+11, 109854, 1220, 7502, 7581, '0', 0, 0, 0, 0, -807.16668701171875, 4483.97216796875, 735.0269775390625, 0.160104453563690185, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366); -- Duroc Ironjaw (Area: Dalaran City - Difficulty: 0)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+12;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 251768, 1220, 7558, 7779, '0', 0, 0, 2894.333251953125, 7673.99658203125, 4.345799922943115234, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Spooky Light Big (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+1, 251826, 1220, 7558, 7779, '0', 0, 0, 2907.647705078125, 7678.7666015625, 5.03698587417602539, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Crooked Tree Candle (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+2, 248860, 1220, 7558, 7779, '0', 0, 0, 2896.405517578125, 7680.525390625, 4.33762979507446289, 3.673851728439331054, 0, 0, -0.96479606628417968, 0.262999176979064941, 120, 255, 1, 46366), -- Books (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+3, 251826, 1220, 7558, 7779, '0', 0, 0, 2904.35498046875, 7678.31005859375, 5.042687416076660156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Crooked Tree Candle (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+4, 248860, 1220, 7558, 7779, '0', 0, 0, 2900.036376953125, 7678.84912109375, 4.01916360855102539, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Books (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+5, 251768, 1220, 7558, 7779, '0', 0, 0, 2900.84375, 7682.70947265625, 4.939099788665771484, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Spooky Light Big (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+6, 251706, 1220, 7558, 7779, '0', 0, 0, 2905.947998046875, 7675.81884765625, 4.686910152435302734, 4.7073822021484375, 0, 0, -0.70887470245361328, 0.705334424972534179, 120, 255, 1, 46366), -- Crooked Tree Cauldron (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+7, 251765, 1220, 7558, 7779, '0', 0, 0, 2896.572998046875, 7678.57568359375, 4.042050361633300781, 4.079247951507568359, 0.025952816009521484, 0.021407127380371093, -0.89148426055908203, 0.451800823211669921, 120, 255, 1, 46366), -- Crooked Tree Tent (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+8, 251824, 1220, 7558, 7779, '0', 0, 0, 2897.671875, 7677.541015625, 3.973532915115356445, 2.426764965057373046, 0.01990365982055664, -0.04411602020263671, 0.935296058654785156, 0.350540876388549804, 120, 255, 1, 46366), -- Crooked Tree Rug (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+9, 180411, 1220, 7558, 7779, '0', 0, 0, 2938.84814453125, 7706.15185546875, 8.826979637145996093, 2.047860622406005859, 0, 0, 0.854158401489257812, 0.520012855529785156, 120, 255, 1, 46366), -- G_Ghost_01 (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+10, 251128, 1220, 7558, 7779, '0', 0, 0, 2867.93408203125, 7739.5703125, 75.02286529541015625, 3.677821636199951171, 0.213648796081542968, 0.0984344482421875, -0.93474769592285156, 0.266292303800582885, 120, 255, 1, 46366), -- A Note (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+11, 251822, 1220, 7558, 7779, '0', 0, 0, 2899.237060546875, 7679.2734375, 4.079217910766601562, 4.515312671661376953, 0, 0, -0.77324104309082031, 0.634112238883972167, 120, 255, 1, 46366), -- Crooked Tree Chair (Area: Radcliffe Landing - Difficulty: 0)
(@OGUID+12, 251823, 1220, 7558, 7779, '0', 0, 0, 2894.14501953125, 7680.35791015625, 4.618403911590576171, 4.110296249389648437, -0.0405592918395996, 0.105701446533203125, -0.87858390808105468, 0.463974654674530029, 120, 255, 1, 46366); -- Crooked Tree Bed (Area: Radcliffe Landing - Difficulty: 0)

DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+10),
(12, @CGUID+11);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+12;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7),
(12, @OGUID+8),
(12, @OGUID+9),
(12, @OGUID+10),
(12, @OGUID+11),
(12, @OGUID+12);

DELETE FROM `gameobject_template` WHERE `entry` IN (251826 /*Crooked Tree Candle*/, 251824 /*Crooked Tree Rug*/, 251823 /*Crooked Tree Bed*/, 251822 /*Crooked Tree Chair*/, 251768 /*Spooky Light Big*/, 251765 /*Crooked Tree Tent*/, 251706 /*Crooked Tree Cauldron*/, 243192 /*Campfire*/, 369301 /*Area of Suspicious Activity*/, 369302 /*Area of Suspicious Activity*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(251826, 5, 35490, 'Crooked Tree Candle', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 46366), -- Crooked Tree Candle
(251824, 5, 35483, 'Crooked Tree Rug', '', '', '', 0.699999988079071044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 46366), -- Crooked Tree Rug
(251823, 5, 26987, 'Crooked Tree Bed', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 46366), -- Crooked Tree Bed
(251822, 5, 14518, 'Crooked Tree Chair', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 46366), -- Crooked Tree Chair
(251768, 5, 35401, 'Spooky Light Big', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 46366), -- Spooky Light Big
(251765, 5, 35474, 'Crooked Tree Tent', '', '', '', 0.699999988079071044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 46366), -- Crooked Tree Tent
(251706, 10, 16741, 'Crooked Tree Cauldron', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 218367, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 41554, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 46366); -- Crooked Tree Cauldron

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (251706 /*Crooked Tree Cauldron*/, 251765 /*Crooked Tree Tent*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(251706, 0, 262145, 0, 0), -- Crooked Tree Cauldron
(251765, 0, 8388608, 0, 0); -- Crooked Tree Tent

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=188, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=109860; -- Crooked Tree Crow
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=14, `BaseAttackTime`=3000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=109825; -- Aria Sorrowheart
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=188, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=109734; -- Hag of the Crooked Tree
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=109854; -- Duroc Ironjaw

DELETE FROM `creature_template_movement` WHERE `CreatureId`=109860;
INSERT INTO `creature_template_movement` (`CreatureId`, `Flight`) VALUES
(109860, 1);

DELETE FROM `creature_template_addon` WHERE `entry` IN (109860 /*109860 (Crooked Tree Crow)*/, 109854 /*109854 (Duroc Ironjaw)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(109860, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- 109860 (Crooked Tree Crow)
(109854, 0, 0, 0, 1, 426, 0, 0, 0, 0, ''); -- 109854 (Duroc Ironjaw)

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (100727, 76701, 110117, 101523, 105955);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(100727, 0.713513493537902832, 1.5, 0, 46366),
(76701, 1.006044268608093261, 0, 0, 46366),
(110117, 0.770981490612030029, 0.800000011920928955, 0, 46366),
(101523, 0.277369260787963867, 1, 0, 46366),
(105955, 0.264983922243118286, 1.5, 0, 46366);

UPDATE `creature_model_info` SET `VerifiedBuild`=46366 WHERE `DisplayID` IN (71448, 71801, 23767, 63999, 60003, 56658, 73035, 40021, 55461, 64050, 47755, 67969, 63892, 63879, 3535, 63849, 43152, 63850, 63836, 58163, 26184, 29331, 63846, 2177, 68720, 38421, 25630, 15147, 42265, 63960, 1141, 63848, 16946, 45139, 16633, 40024, 44169, 66640, 68354, 68172, 68195, 68179, 68193, 68093, 68092, 62284, 62283, 56952, 63334, 63605, 63596, 63597, 63598, 72365, 328, 64330, 51292, 70576, 70451, 68398, 36620, 66678, 63592, 59734, 71578, 43758, 64651, 43759, 63591, 23456, 467, 62734, 63935, 43757, 62512, 60914, 26404, 16178, 2536, 36952, 66620, 9829, 51660, 63631, 69421, 66621, 1160, 30256, 68063, 36956, 68064, 62217, 62638, 28080, 66614, 36944, 40090, 70402, 40089, 36957, 4626, 134, 66481, 64329, 69709, 20641, 61304, 32568, 61102, 67397, 67258, 39553, 31215, 62070, 69860, 70986, 69851, 22590, 60845, 33534, 61099, 61101, 61693, 67421, 60891, 30462, 54644, 61123, 61095, 65790, 31291, 71004, 43100, 61098, 62261, 61097, 46710, 61096, 90318, 1986, 704, 90314, 75972, 90243, 82773, 25436, 89937, 90300, 83764, 90302, 90245, 86333, 89935, 15468, 16238, 90130, 10732, 90303, 90293, 4601, 20985, 36584, 90246, 37330, 37328, 75973, 90252, 92464, 90366, 90242, 37023, 83765, 90253, 90244, 21342, 90133, 37329, 4260, 36585, 37331, 35504, 86332, 16235, 35498, 90129, 92463, 4259, 20988, 99436, 99452, 21072, 70992, 93232, 25420, 94658, 25423, 25375, 104817, 25439, 101418, 96327, 93951, 104818, 96422, 94141, 96332, 93576, 93593, 96712, 73366, 93586, 93579, 94020, 93599, 93589, 24103, 97425, 94471, 93584, 96086, 94665, 94655, 37647, 95258, 93596, 95252, 93577, 94286, 92900, 90260, 92399, 27153, 94491, 94614, 92385, 95081, 98688, 99478, 93151, 98194, 96331, 96591, 96281, 96196, 99205, 97984, 93595, 26064, 95511, 28282, 28111, 94612, 93201, 95948, 95843, 11686, 27823, 104785, 40658, 96637, 86231, 96330, 19283, 74802, 88012, 96614, 95464, 94586, 96423, 40657, 88016, 105361, 96084, 90422, 96325, 99054, 99744, 99048, 93587, 77687, 99450, 94469, 42722, 93597, 42720, 77690, 95325, 92345, 96744, 96510, 93580, 82235, 100265, 96642, 96602, 94613, 96603, 93585, 105325, 105324, 28118, 28120, 97650, 93601, 94472, 96714, 95557, 97651, 92714, 96748, 96624, 94449, 97424, 93590, 93598, 93588, 93592, 95260, 97649, 99382, 93600, 98692, 93582, 99050, 97025, 97347, 95660, 24995, 96625, 31275, 47211, 20923);
UPDATE `creature_model_info` SET `CombatReach`=14, `VerifiedBuild`=46366 WHERE `DisplayID`=71135;
UPDATE `creature_model_info` SET `BoundingRadius`=3.449999809265136718, `VerifiedBuild`=46366 WHERE `DisplayID`=39011;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=46366 WHERE `DisplayID` IN (73135, 71147);
UPDATE `creature_model_info` SET `BoundingRadius`=2.610027790069580078, `VerifiedBuild`=46366 WHERE `DisplayID`=14511;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=1.125, `VerifiedBuild`=46366 WHERE `DisplayID` IN (77402, 77403, 77404);
UPDATE `creature_model_info` SET `BoundingRadius`=0.386561989784240722, `VerifiedBuild`=46366 WHERE `DisplayID` IN (77407, 77406, 77405);
UPDATE `creature_model_info` SET `BoundingRadius`=2.942395210266113281, `CombatReach`=3, `VerifiedBuild`=46366 WHERE `DisplayID`=70772;
UPDATE `creature_model_info` SET `BoundingRadius`=0.248000010848045349, `CombatReach`=0.800000011920928955, `VerifiedBuild`=46366 WHERE `DisplayID`=58128;
UPDATE `creature_model_info` SET `BoundingRadius`=0.779591858386993408, `VerifiedBuild`=46366 WHERE `DisplayID`=63870;
UPDATE `creature_model_info` SET `BoundingRadius`=0.442737370729446411, `VerifiedBuild`=46366 WHERE `DisplayID`=64471;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955, `VerifiedBuild`=46366 WHERE `DisplayID`=71224;
UPDATE `creature_model_info` SET `BoundingRadius`=1.156227827072143554, `CombatReach`=1, `VerifiedBuild`=46366 WHERE `DisplayID`=45092;
UPDATE `creature_model_info` SET `BoundingRadius`=1.328571319580078125, `CombatReach`=1.660714149475097656, `VerifiedBuild`=46366 WHERE `DisplayID`=61702;
UPDATE `creature_model_info` SET `BoundingRadius`=0.474178433418273925, `CombatReach`=1.5, `VerifiedBuild`=46366 WHERE `DisplayID`=69274;
UPDATE `creature_model_info` SET `BoundingRadius`=0.539418935775756835, `CombatReach`=0.5, `VerifiedBuild`=46366 WHERE `DisplayID`=98509;
UPDATE `creature_model_info` SET `BoundingRadius`=2.083333253860473632, `CombatReach`=1, `VerifiedBuild`=46366 WHERE `DisplayID`=94018;
UPDATE `creature_model_info` SET `BoundingRadius`=0.774677395820617675, `CombatReach`=1.70000004768371582, `VerifiedBuild`=46366 WHERE `DisplayID`=92191;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791, `CombatReach`=0.60000002384185791, `VerifiedBuild`=46366 WHERE `DisplayID`=21304;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `VerifiedBuild`=46366 WHERE `DisplayID`=69254;

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (15354,32751,54141,88376,94433,106511,106615,109692,109734,109825,109854,109860,109990,111384,111402,112453,197961,198015));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(15354, 0, 0, 0, 425, 46366),
(32751, 0, 0, 0, 885, 46366),
(54141, 0, 0, 0, 861, 46366),
(88376, 0, 0, 0, 302, 46366),
(94433, 0, 0, 0, 332, 46366),
(106511, 0, 0, 0, 339, 46366),
(106615, 0, 0, 0, 332, 46366),
(109692, 0, 0, 0, 332, 46366),
(109734, 0, 0, 0, 425, 46366),
(109825, 0, 0, 0, 429, 46366),
(109854, 0, 0, 0, 425, 46366),
(109860, 0, 0, 0, 425, 46366),
(109990, 0, 0, 0, 332, 46366),
(111384, 0, 0, 0, 332, 46366),
(111402, 0, 0, 0, 331, 46366),
(112453, 0, 0, 0, 332, 46366),
(197961, 0, 0, 0, 885, 46366),
(198015, 0, 0, 0, 885, 46366);

DELETE FROM `creature_queststarter` WHERE (`id`=109734 AND `quest`=43162) OR (`id`=109854 AND `quest`=43259);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(109734, 43162, 46366), -- Under the Crooked Tree offered Hag of the Crooked Tree
(109854, 43259, 46366); -- Beware of the Crooked Tree offered Duroc Ironjaw

UPDATE `creature_questender` SET `VerifiedBuild`=46366 WHERE (`id`=109734 AND `quest` IN (43162,43259));

DELETE FROM `phase_name` WHERE `ID` = 6944;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(6944, 'Cosmetic - Val''sharah - Hallow''s End - Curse of the Crooked Tree');
