SET @CGUID := 4000147;
SET @OGUID := 4000107;
SET @CONDREFID := 40002;

-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=0x41000000 WHERE `entry`=40789; -- Generic Controller Bunny (CSA)
UPDATE `creature_template` SET `unit_flags3`=0x41000001 WHERE `entry`=67032; -- Gunship Turret
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x4000800, `unit_flags3`=0x1000000, `VehicleId`=7269 WHERE `entry`=170866; -- Orgrimmar Wind Rider

DELETE FROM `creature_template_addon` WHERE `entry` IN (170866,67040,67038,67032,61869,61868,61867,61866,61846,61845,61844,55054,54870);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(170866, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 170866 (Orgrimmar Wind Rider)
(67040, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 67040 (Hellscream's Fist Deckswabber)
(67038, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 67038 (Hellscream's Fist Engineer)
(67032, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 67032 (Gunship Turret)
(61869, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 61869 (Snuff)
(61868, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 61868 (Zin'jun)
(61867, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 61867 (Kiryn)
(61866, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 61866 (Shokia)
(61846, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 61846 (Gorrok)
(61845, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 61845 (Hellscream's Vanguard)
(61844, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 61844 (Rivett Clutchpop)
(55054, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 55054 (General Nazgrim)
(54870, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 54870 (General Nazgrim)

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID`=61845);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(61845, 1, 5289, 0, 0, 0, 0, 0, 0, 0, 0, 56819); -- Hellscream's Vanguard

UPDATE `creature_equip_template` SET `VerifiedBuild`=56819 WHERE (`ID`=1 AND `CreatureID` IN (176554,173279,171791,169177,168459,139093,133271,114066,89830,88703,88702,88701,74228,72559,67038,62195,58155,55054,54870,52032,51346,50488,50477,50323,49750,49622,47571,47248,47247,47246,46742,46741,46716,46709,46708,46556,46555,46359,46358,46357,46142,46140,45339,45337,45230,44919,44878,44877,44876,44872,44871,44851,44743,44725,44723,44158,42637,39605,37072,35068,26537,25081,25080,24931,24930,24929,24927,24926,24924,23635,23128,14392,14376,14375,12136,9564,7010,6929,6466,5817,5614,5613,5611,5610,5609,5606,5188,4047,3412,3370,3368,3342,3331,3323,3314,3313,3312,3310,3296,3144)) OR (`ID`=4 AND `CreatureID`=169177) OR (`ID`=2 AND `CreatureID` IN (169177,74228,44158,17252,3296)) OR (`ID`=5 AND `CreatureID`=169177) OR (`ID`=6 AND `CreatureID`=169177) OR (`ID`=3 AND `CreatureID`=44158);

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=56819 WHERE (`Idx`=0 AND `CreatureID` IN (222782,200248,23635,32642,32641,44745,46742,46741,46709,46708,3412,3368,199202,52032,46718,46716,7010,3372,3371,31146,62114,114066,61869,61868,67040,61846,17213,61867,61844,40789,67038,61866,61845,67032,35162,153285,142668,142666,17252,25080,24934,24931,170866,24927,25081,25075,24935,24930,24929,24926,24924,50088,52812,52809,52810,133271,130911,45230,44743,44725,44723,12136,141528,43062,9564,63626,44160,26537,20493,20488,20486,15476,14881,198557,198553,198542,50488,50477,50323,44948,44919,44918,44158,3310,14499,229736,199275,20492,20491,20490,20489,168459,62195,44876,44854,44852,5817,3313,88701,44877,44856,44853,44851,14392,5610,137762,135202,88702,5611,5609,5606,176261,203246,203245,201230,175084,44878,6929,5614,5613,46358,46357,46572,37072,47247,47248,1863,185670,46512,3331,52034,3370,47571,199015,51195,14375,185669,17098,140210,52382,42637,197767,199643,199016,44868,38821,72559,58155,204340,44872,3314,199264,46359,29929,199625,199017,47246,3323,44867,152643,28960,199265,185473,135201,416,89830,72654,197770,199018,165189,49837,3319,49131,62821,204648,46140,139093,35068,45337,55054,201314,176554,88703,171791,3342,199115,26125,32520,199164,27489,198541,62822,74228,197771,3144,5188,44865,121541,39605,198497,46142,44871,46556,54870,6466,173386,49622,49750,62198,173281,183978,45339,199602,46555,62115,186199,173279,23128,51346,44338,44866,185472,3296,191463,138741,14376,49743,3312,4047,169177,21354,33030,63502,18365,31698,35362,65011,60941,69066,64993,71486,70356,69219,68288,65016,63042,59072,56921,54879,54741,54423,47654,40725,40625,40165,356,25064,32158,28363,28302,18379,14505,304,305,40054)) OR (`Idx`=1 AND `CreatureID` IN (200248,62114,114066,40789,67038,50088,52810,133271,45230,44160,15476,14881,44158,14499,168459,203246,203245,140210,38821,72559,152643,28960,89830,72654,49837,46140,26125,32520,74228,46142,173281,183978,62115,186199,173279,51346,3296,191463,49743,169177,40725,40165)) OR (`Idx`=3 AND `CreatureID` IN (62114,114066,67038,133271,45230,44160,15476,44158,14499,168459,89830,49837,46140,26125,74228,46142,173281,62115,173279,51346,3296,49743,169177)) OR (`Idx`=2 AND `CreatureID` IN (62114,114066,67038,133271,45230,44160,15476,44158,14499,168459,140210,89830,49837,46140,26125,74228,46142,173281,62115,173279,51346,3296,49743,169177)) OR (`Idx`=5 AND `CreatureID` IN (45230,46140,173281,3296,169177)) OR (`Idx`=4 AND `CreatureID` IN (45230,46140,173281,3296,169177)) OR (`Idx`=7 AND `CreatureID` IN (46140,173281,169177)) OR (`Idx`=6 AND `CreatureID` IN (46140,173281,169177)) OR (`Idx`=11 AND `CreatureID`=169177) OR (`Idx`=10 AND `CreatureID`=169177) OR (`Idx`=9 AND `CreatureID`=169177) OR (`Idx`=8 AND `CreatureID`=169177);

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (110606, 112186, 98892, 79475, 113851, 113850, 112329, 116250, 122113, 122112, 122110, 122109);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(110606, 0.722000002861022949, 3, 0, 56819),
(112186, 0.700270593166351318, 0.300000011920928955, 0, 56819),
(98892, 2.671835184097290039, 1.5, 0, 56819),
(79475, 0.305999994277954101, 1.5, 0, 56819),
(113851, 0.347222000360488891, 1.5, 0, 56819),
(113850, 0.347222000360488891, 1.5, 0, 56819),
(112329, 1, 1, 0, 56819),
(116250, 0.382499992847442626, 1.875, 0, 56819),
(122113, 1.371798515319824218, 1, 0, 56819),
(122112, 1.409832358360290527, 0.900000035762786865, 0, 56819),
(122110, 1.586356878280639648, 1.5, 0, 56819),
(122109, 0.420000016689300537, 1.80000007152557373, 0, 56819);

UPDATE `creature_model_info` SET `VerifiedBuild`=56819 WHERE `DisplayID` IN (47165, 93505, 29564, 38804, 26375, 110794, 110760, 64062, 110614, 110605, 106345, 110514, 110191, 110183, 110187, 110138, 109709, 109512, 111139, 111138, 37643, 106967, 106964, 27153, 100444, 99385, 92900, 9132, 2735, 8631, 27589, 27599, 4231, 4602, 70436, 96328, 96330, 96326, 96331, 96327, 96086, 64307, 34252, 1592, 83228, 81476, 34208, 34207, 24979, 8001, 61024, 61023, 31737, 99507, 31738, 99462, 49781, 49770, 45680, 45666, 45663, 45664, 45665, 44851, 5705, 42722, 42720, 42389, 42385, 45896, 41931, 39116, 39207, 39049, 39047, 32575, 39044, 40012, 42562, 33303, 22769, 38047, 37864, 37724, 37328, 37331, 37329, 37330, 37138, 37020, 31760, 37437, 36598, 36585, 36583, 36584, 36615, 7511, 8971, 36559, 31988, 35695, 35500, 35499, 35498, 35148, 35140, 35141, 35133, 35053, 35052, 35051, 14369, 14370, 89419, 89800, 34412, 34406, 9391, 2141, 30413, 34185, 34184, 1310, 1320, 1318, 8000, 9133, 34157, 34156, 34155, 34154, 34144, 34143, 34141, 34139, 34136, 34059, 34047, 34045, 304, 33698, 33700, 33701, 33699, 4368, 32981, 32904, 21072, 4382, 30462, 29569, 25103, 27686, 25871, 21342, 22493, 24164, 22750, 22744, 22739, 21264, 17701, 17722, 17719, 17721, 17720, 17699, 17700, 16910, 16850, 15470, 15471, 44816, 14554, 38418, 51613, 14415, 14413, 12229, 10186, 8848, 5706, 5205, 4356, 3609, 3608, 3606, 7137, 3605, 3604, 3128, 4514, 1392, 1358, 99458, 1323, 1319, 1314, 1313, 1312, 1311, 4259, 99452, 4601, 99453, 4260, 99451, 82115);
UPDATE `creature_model_info` SET `VerifiedBuild`=56819 WHERE `DisplayID` IN (119076, 110583, 84775, 84776, 84774, 80060, 46930, 28048, 77690, 77687, 99809, 35244, 99810, 35242, 35241, 35237, 99808, 30501, 30108, 28118, 28120, 27510, 22873, 22746, 22745, 22743, 22740, 14414, 6839, 99818, 1394, 1393, 1390);
UPDATE `creature_model_info` SET `BoundingRadius`=0.772917687892913818, `VerifiedBuild`=56819 WHERE `DisplayID`=86021;
UPDATE `creature_model_info` SET `BoundingRadius`=0.280177772045135498, `CombatReach`=1, `VerifiedBuild`=56819 WHERE `DisplayID`=87564;
UPDATE `creature_model_info` SET `BoundingRadius`=0.885321557521820068, `VerifiedBuild`=56819 WHERE `DisplayID`=73093;
UPDATE `creature_model_info` SET `BoundingRadius`=1.066666722297668457, `VerifiedBuild`=56819 WHERE `DisplayID`=79383;
UPDATE `creature_model_info` SET `BoundingRadius`=1.23741316795349121, `CombatReach`=2.70000004768371582, `VerifiedBuild`=56819 WHERE `DisplayID`=101441;
UPDATE `creature_model_info` SET `BoundingRadius`=0.442888736724853515, `CombatReach`=1, `VerifiedBuild`=56819 WHERE `DisplayID`=24745;
UPDATE `creature_model_info` SET `BoundingRadius`=0.171312570571899414, `CombatReach`=0.150000005960464477, `VerifiedBuild`=56819 WHERE `DisplayID` IN (15468, 15467);

-- Difficulties
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=56819 WHERE (`Entry`=17213 AND `DifficultyID`=0); -- 17213 (Broom) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20080100, `VerifiedBuild`=56819 WHERE (`Entry`=40789 AND `DifficultyID`=0); -- 40789 (Generic Controller Bunny (CSA)) - Sessile, Amphibious, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=56819 WHERE (`Entry`=67040 AND `DifficultyID`=0); -- 67040 (Hellscream's Fist Deckswabber) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=56819 WHERE (`Entry`=67038 AND `DifficultyID`=0); -- 67038 (Hellscream's Fist Engineer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=56819 WHERE (`Entry`=67032 AND `DifficultyID`=0); -- 67032 (Gunship Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=864, `StaticFlags1`=0x30000000, `VerifiedBuild`=56819 WHERE (`Entry`=170866 AND `DifficultyID`=0); -- 170866 (Orgrimmar Wind Rider) - CanSwim, Floating
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (170866,67040,67038,67032,40789,17213) AND `DifficultyID`=1;

-- Gameobject templates
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=56819 WHERE `entry`=191640; -- Anvil

-- Creature spawns
SET @SPAWNGROUP := 1259;
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+3;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP+0, 0, @CGUID+48),
(@SPAWNGROUP+1, 0, @CGUID+49),
(@SPAWNGROUP+2, 0, @CGUID+46),
(@SPAWNGROUP+3, 0, @CGUID+47);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+104;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1789.7452392578125, 1326.7279052734375, 23.32601547241210937, 3.65703439712524414, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+1, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1763.518310546875, 1323.9095458984375, 18.56777191162109375, 3.577862501144409179, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+2, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1620.6214599609375, 1141.0804443359375, 34.46206283569335937, 3.661552906036376953, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+3, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1773.1240234375, 1277.4849853515625, 33.94271469116210937, 1.26128387451171875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+4, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1828.9891357421875, 1571.6427001953125, 25.85111236572265625, 3.816943883895874023, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+5, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1754.0760498046875, 1316.247802734375, 27.90841102600097656, 3.956035375595092773, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1951.52587890625, 1195.732666015625, 25.29047584533691406, 2.145257949829101562, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1660.266357421875, 1337.1173095703125, 30.370269775390625, 5.643963813781738281, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1650.521484375, 1204.099853515625, 18.99119186401367187, 4.712388992309570312, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 65207, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1967.4873046875, 1466.973876953125, 31.45277214050292968, 1.943491697311401367, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+10, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1783.841796875, 1375.753173828125, 23.81683921813964843, 2.95611882209777832, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+11, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1719.7777099609375, 1117.5045166015625, 20.07037734985351562, 5.198012351989746093, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 65207, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1623.3663330078125, 1142.5416259765625, 33.99567413330078125, 3.548183679580688476, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+13, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1852.099609375, 1207.2767333984375, 14.74231433868408203, 4.9661102294921875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 65209, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1669.6246337890625, 1338.887451171875, 10.44999980926513671, 4.184916496276855468, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+15, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1754.8876953125, 1316.431640625, 29.88301658630371093, 0.73880934715270996, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+16, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1663.8798828125, 1336.5657958984375, 31.68233489990234375, 2.759795904159545898, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1719.1326904296875, 1117.7626953125, 20.08334541320800781, 5.868938922882080078, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 65207, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1966.9879150390625, 1468.189697265625, 31.32956314086914062, 2.140692710876464843, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+19, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1783.3472900390625, 1382.4683837890625, 25.10213661193847656, 3.829726457595825195, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1850.5567626953125, 1207.0440673828125, 14.39219284057617187, 4.671327114105224609, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 65207, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1623.279541015625, 1142.045166015625, 33.9403533935546875, 3.663904666900634765, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1657.7625732421875, 1489.508056640625, 16.70968246459960937, 4.300419330596923828, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 65209, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1639.6875, 1326.4461669921875, 12.25523948669433593, 1.689028263092041015, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+24, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1616.1865234375, 1341.3101806640625, 32.34295654296875, 2.626653909683227539, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1965.7755126953125, 1470.5006103515625, 31.07440185546875, 2.022632122039794921, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1925.7301025390625, 1422.075927734375, 12.36990070343017578, 2.341855525970458984, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 58951, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1783.4149169921875, 1333.55908203125, 6.384816169738769531, 1.588249564170837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Trigger (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+28, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1805.071044921875, 1332.92822265625, 23.6486053466796875, 4.87811279296875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+29, 65209, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1626.9881591796875, 1325.9010009765625, 10.44999980926513671, 3.896676301956176757, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+30, 65207, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1931.859375, 1129.1302490234375, 28.97992706298828125, 5.740293025970458984, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+31, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1933.678466796875, 1127.43994140625, 28.92253494262695312, 5.573817729949951171, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+32, 65209, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1628.6978759765625, 1345.28125, 12.37590217590332031, 2.18117690086364746, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+33, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1617.9903564453125, 1336.9093017578125, 32.34294509887695312, 4.434304714202880859, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+34, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1830.947021484375, 1120.5450439453125, 20.47720146179199218, 1.9561082124710083, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+35, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1785.673095703125, 1327.003662109375, 23.33595466613769531, 1.357039451599121093, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1928.0096435546875, 1416.96484375, 12.55990982055664062, 4.348969936370849609, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+37, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1754.17626953125, 1354.6884765625, 24.7605438232421875, 5.592080116271972656, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+38, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1830.4091796875, 1571.0565185546875, 25.71176338195800781, 5.293349742889404296, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1767.5631103515625, 1273.6688232421875, 36.67034530639648437, 5.0028533935546875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+40, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1949.05615234375, 1195.2598876953125, 25.30850028991699218, 3.043081283569335937, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 65206, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1696.5380859375, 1557.7576904296875, 22.785614013671875, 2.481467485427856445, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+42, 65205, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1793.47412109375, 1334.873046875, 19.48966789245605468, 2.649313926696777343, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Gilded Moth (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 65209, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1660.6875, 1336.4583740234375, 11.32715511322021484, 1.695375800132751464, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+44, 65207, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1931.438232421875, 1129.7901611328125, 28.80927658081054687, 2.830842971801757812, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Golden Civet Kitten (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+45, 65209, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1622.8958740234375, 1317.854736328125, 10.44999980926513671, 6.107137680053710937, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56008), -- Dancing Water Skimmer (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking) (possible waypoints or random movement)
(@CGUID+46, 62240, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1850.3055419921875, 1249.9930419921875, 13.49555587768554687, 1.588249564170837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Red Beam (Area: Temple of Kotmogu - Difficulty: 0) CreateObject2 (Auras: 121221 - Orange Ball Aura)
(@CGUID+47, 62237, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1716.8211669921875, 1249.6788330078125, 13.36339282989501953, 1.588249564170837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Yellow Beam (Area: Temple of Kotmogu - Difficulty: 0) CreateObject2 (Auras: 121217 - Yellow Ball Aura)
(@CGUID+48, 62239, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1716.8853759765625, 1416.7899169921875, 13.28889942169189453, 1.588249564170837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Green Beam (Area: Temple of Kotmogu - Difficulty: 0) CreateObject2 (Auras: 121220 - Green Ball Aura)
(@CGUID+49, 62238, 998, 6051, 6136, '0', 0, 0, -1, 0, 0, 1850.0208740234375, 1416.689208984375, 13.39783096313476562, 1.588249564170837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Blue Beam (Area: Temple of Kotmogu - Difficulty: 0) CreateObject2 (Auras: 121219 - Purple Ball Aura)
(@CGUID+50, 13117, 998, 6051, 6136, '0', 0, 0, -1, 0, 1, 1675.2899169921875, 1523.85595703125, 16.86186981201171875, 5.576955795288085937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Horde Spirit Guide (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+51, 13116, 998, 6051, 6136, '0', 0, 0, -1, 0, 1, 1895.3350830078125, 1522.0972900390625, 16.29700660705566406, 3.56899261474609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Alliance Spirit Guide (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+52, 13117, 998, 6051, 6136, '0', 0, 0, -1, 0, 1, 1678.185791015625, 1146.751708984375, 17.45750236511230468, 0.850761175155639648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Horde Spirit Guide (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+53, 13116, 998, 6051, 6136, '0', 0, 0, -1, 0, 1, 1892.0867919921875, 1153.8941650390625, 15.00300025939941406, 2.315886497497558593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56008), -- Alliance Spirit Guide (Area: Temple of Kotmogu - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+54, 54870, 1, 1637, 5356, '0', 0, 0, -1, 0, 1, 1670.8055419921875, -4353.01220703125, 26.84072494506835937, 3.000042438507080078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- General Nazgrim (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 90442 - Generic Quest Invisibility 17)
(@CGUID+55, 55054, 1, 1637, 1637, '0', 0, 0, -1, 0, 1, 1840.6458740234375, -4419.41650390625, 135.3163604736328125, 0.715584993362426757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- General Nazgrim (Area: Orgrimmar - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+56, 61844, 1, 1637, 1637, '0', 0, 0, -1, 0, 0, 1843.9322509765625, -4420.845703125, 135.316131591796875, 1.820238590240478515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Rivett Clutchpop (Area: Orgrimmar - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+57, 61845, 1, 1637, 1637, '0', 0, 0, -1, 0, 0, 1847.8072509765625, -4408.08154296875, 135.1502532958984375, 3.938601016998291015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Orgrimmar - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+58, 61845, 1, 1637, 1637, '0', 0, 0, -1, 0, 0, 1851.7396240234375, -4417.5869140625, 135.3153839111328125, 2.529423952102661132, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Orgrimmar - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+59, 61845, 1, 1637, 1637, '0', 0, 0, -1, 0, 0, 1851.407958984375, -4411.51220703125, 135.148284912109375, 3.939165115356445312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Orgrimmar - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+60, 61846, 1, 1637, 1637, '0', 0, 0, -1, 0, 0, 1842.060791015625, -4408.59375, 135.3155059814453125, 5.53992462158203125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Gorrok (Area: Orgrimmar - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+61, 61866, 1, 1637, 1637, '0', 0, 0, -1, 0, 0, 1848.9254150390625, -4419, 135.315643310546875, 3.363948583602905273, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Shokia (Area: Orgrimmar - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+62, 61867, 1, 1637, 1637, '0', 0, 0, -1, 0, 0, 1847.0538330078125, -4419.12353515625, 135.3157501220703125, 0.157710805535316467, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Kiryn (Area: Orgrimmar - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+63, 61868, 1, 1637, 1637, '0', 0, 0, -1, 0, 0, 1840.3541259765625, -4412.35595703125, 135.316162109375, 5.835348129272460937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Zin'jun (Area: Orgrimmar - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+64, 61869, 1, 1637, 1637, '0', 0, 0, -1, 0, 0, 1839.85595703125, -4415.26025390625, 135.3163604736328125, 5.805415153503417968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Snuff (Area: Orgrimmar - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+65, 17213, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1864.6423, -5479.9844, 444.05933, 0, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Broom (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+66, 40789, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1831.3299560546875, -5463.3701171875, 454.385345458984375, 3.143285512924194335, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Generic Controller Bunny (CSA) (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (Auras: 132224 - FX_Hordegunship_Idle_Loop)
(@CGUID+67, 55054, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1862.28125, -5461.90087890625, 443.81402587890625, 3.174382448196411132, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- General Nazgrim (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+68, 61844, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1848.3716, -5441.2847, 443.51755, 2.215219020843505859, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Rivett Clutchpop (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+69, 61845, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1829.3959, -5477.262, 442.66663, 0, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+70, 61845, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1820.6094, -5442.7085, 443.13733, 0, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+71, 61845, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1839.9514, -5489.2446, 441.44098, 0, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+72, 61845, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1841.7396240234375, -5463.015625, 495.15374755859375, 3.288609981536865234, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+73, 61845, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1864.9617919921875, -5461.923828125, 495.15374755859375, 0.238025233149528503, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+74, 61845, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1861.638916015625, -5457.626953125, 443.630035400390625, 0.034142464399337768, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+75, 61845, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1895.0243, -5470.528, 439.15887, 2.65421915054321289, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+76, 61845, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1879.1702, -5439.125, 445.27353, 0, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+77, 61846, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1888.5243, -5460.8125, 419.27628, 0, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Gorrok (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+78, 61866, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1839.4617919921875, -5475.68212890625, 442.99444580078125, 0.3363572359085083, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Shokia (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+79, 61867, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1841.5, -5474.81787109375, 443.029205322265625, 3.65752577781677246, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Kiryn (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+80, 61868, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1867.265625, -5439.55908203125, 444.541259765625, 1.761279463768005371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Zin'jun (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+81, 61869, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1869.888916015625, -5438.08154296875, 444.778564453125, 2.025144338607788085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Snuff (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+82, 67032, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1866.41845703125, -5497.23291015625, 419.70147705078125, 4.757791996002197265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+83, 67032, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1839.8385009765625, -5498.38720703125, 419.725982666015625, 4.757791996002197265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+84, 67032, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1853.138916015625, -5497.79345703125, 419.1302490234375, 4.757791996002197265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+85, 67032, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1850.220458984375, -5426.96875, 419.131011962890625, 1.599296450614929199, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+86, 67032, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1863.4896240234375, -5426.40625, 419.71697998046875, 1.599296450614929199, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+87, 67032, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1836.9305419921875, -5427.51220703125, 419.710235595703125, 1.599296450614929199, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+88, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1866.4583740234375, -5487.90478515625, 444.500640869140625, 3.777480840682983398, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (Auras: 79367 - Holding a Cannonball)
(@CGUID+89, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1856.1771240234375, -5435.3369140625, 445.485382080078125, 1.913024306297302246, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+90, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1860.41845703125, -5435.79345703125, 444.358184814453125, 1.913024306297302246, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+91, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1885.5573, -5449.3267, 419.4912, 1.660551786422729492, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+92, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1850.0242919921875, -5428.88720703125, 419.0731201171875, 1.541719436645507812, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+93, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1822.4617919921875, -5474.78466796875, 419.200225830078125, 4.529586315155029296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+94, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1838.3177490234375, -5460.45166015625, 451.208984375, 3.636371135711669921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+95, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1832.079833984375, -5469.109375, 451.81427001953125, 4.892142772674560546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+96, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1815.7603759765625, -5452.10595703125, 420.34033203125, 0.940434634685516357, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+97, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1822.217041015625, -5451.99462890625, 419.16162109375, 2.110541343688964843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+98, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1851.611083984375, -5427.33349609375, 419.136474609375, 2.788624763488769531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+99, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1900.3472900390625, -5457.8525390625, 419.52978515625, 0.312810629606246948, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+100, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1897.53125, -5469.046875, 419.59649658203125, 5.653588294982910156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+101, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1836.18408203125, -5429.7744140625, 419.8115234375, 1.251509428024291992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+102, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1862.4461669921875, -5428.455078125, 419.643310546875, 5.752133846282958984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+103, 67038, 1, 14, 6529, '0', 1663, 0, 1074, 0, 1, 1864.484375, -5429.75341796875, 419.81658935546875, 2.6260223388671875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+104, 67040, 1, 14, 6529, '0', 1663, 0, 1074, 0, 0, 1862.6938, -5480.4355, 443.9552, 0.228, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819); -- Hellscream's Fist Deckswabber (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (Auras: 131804 - Arcane Channeling) (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+104;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '90442'), -- General Nazgrim - 90442 - Generic Quest Invisibility 17
(@CGUID+55, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '94223'), -- General Nazgrim - 94223 - Generic Quest Invisibility 25
(@CGUID+56, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Rivett Clutchpop - 94223 - Generic Quest Invisibility 25
(@CGUID+57, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Hellscream's Vanguard - 94223 - Generic Quest Invisibility 25
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Hellscream's Vanguard - 94223 - Generic Quest Invisibility 25
(@CGUID+59, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Hellscream's Vanguard - 94223 - Generic Quest Invisibility 25
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Gorrok - 94223 - Generic Quest Invisibility 25
(@CGUID+61, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Shokia - 94223 - Generic Quest Invisibility 25
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Kiryn - 94223 - Generic Quest Invisibility 25
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Zin'jun - 94223 - Generic Quest Invisibility 25
(@CGUID+64, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Snuff - 94223 - Generic Quest Invisibility 25
(@CGUID+66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '132224'), -- Generic Controller Bunny (CSA) - 132224 - FX_Hordegunship_Idle_Loop
(@CGUID+88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+89, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+90, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+93, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+94, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+95, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+96, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+97, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+98, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+99, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+101, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''); -- Hellscream's Fist Engineer

-- Paths
SET @MOVERGUID := @CGUID+65;
SET @ENTRY := 17213;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+65;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+65, @CGUID+65, 0, 0, 515, 0, 0),
(@CGUID+65, @CGUID+104, 2, 0, 515, 0, 0);

DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 1.5, 'Broom - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1857.3923, -5477.2344, 444.05933, NULL, 0), -- Spline
(@PATH, 1, 1849.3923, -5470.9844, 443.55933, NULL, 0), -- Spline
(@PATH, 2, 1851.8923, -5465.9844, 443.80933, NULL, 0), -- Spline
(@PATH, 3, 1855.6423, -5460.4844, 443.80933, NULL, 0), -- Spline
(@PATH, 4, 1849.1423, -5452.2344, 443.55933, NULL, 0), -- Spline
(@PATH, 5, 1856.8923, -5444.7344, 444.05933, NULL, 0), -- Spline
(@PATH, 6, 1861.8923, -5440.2344, 444.30933, NULL, 0), -- Spline
(@PATH, 7, 1854.1423, -5439.4844, 444.05933, NULL, 0), -- Spline
(@PATH, 8, 1846.3923, -5444.9844, 443.80933, NULL, 0), -- Spline
(@PATH, 9, 1844.6423, -5451.9844, 443.55933, NULL, 0), -- Spline
(@PATH, 10, 1846.8923, -5459.7344, 443.55933, NULL, 0), -- Spline
(@PATH, 11, 1850.6423, -5465.4844, 443.55933, NULL, 0), -- Spline
(@PATH, 12, 1852.6423, -5470.9844, 443.80933, NULL, 0), -- Spline
(@PATH, 13, 1851.3923, -5478.4844, 443.80933, NULL, 0), -- Spline
(@PATH, 14, 1858.3923, -5481.2344, 444.05933, NULL, 0), -- Spline
(@PATH, 15, 1864.6423, -5479.9844, 444.05933, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+68;
SET @ENTRY := 61844;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Rivett Clutchpop - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1848.3716, -5441.2847, 443.51755, 2.215219020843505859, 7500),
(@PATH, 1, 1849.1459, -5458.6978, 443.18222, NULL, 0),
(@PATH, 2, 1849.507, -5479.354, 443.42105, NULL, 0),
(@PATH, 3, 1847.5817, -5487.561, 443.34912, NULL, 7000),
(@PATH, 4, 1849.5608, -5467.528, 443.17072, NULL, 0),
(@PATH, 5, 1848.8317, -5443.1963, 443.513, NULL, 250);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+69;
SET @ENTRY := 61845;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, 1.5, 'Hellscream''s Vanguard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1829.3959, -5477.262, 442.66663, NULL, 250),
(@PATH, 1, 1824.1389, -5477.672, 443.6393, NULL, 0),
(@PATH, 2, 1818.5399, -5484.884, 443.1334, NULL, 0),
(@PATH, 3, 1812.2812, -5484.1235, 443.1881, NULL, 0),
(@PATH, 4, 1800.2413, -5479.134, 443.3974, NULL, 0),
(@PATH, 5, 1800.1663, -5478.9844, 443.40213, NULL, 0),
(@PATH, 6, 1798.408, -5475.479, 443.5573, NULL, 250),
(@PATH, 7, 1812.2812, -5484.1235, 443.1881, NULL, 0),
(@PATH, 8, 1818.5399, -5484.884, 443.1334, NULL, 0),
(@PATH, 9, 1824.1389, -5477.672, 443.6393, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+70;
SET @ENTRY := 61845;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, 1.5, 'Hellscream''s Vanguard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1820.6094, -5442.7085, 443.13733, NULL, 250),
(@PATH, 1, 1814.7639, -5442.895, 443.31442, NULL, 0), -- Spline
(@PATH, 2, 1808.2639, -5445.145, 443.31442, NULL, 0), -- Spline
(@PATH, 3, 1802.2639, -5448.395, 443.56442, NULL, 0), -- Spline
(@PATH, 4, 1796.7639, -5451.395, 443.56442, NULL, 10), -- Spline
(@PATH, 5, 1793.9185, -5450.0815, 443.49152, NULL, 31500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+71;
SET @ENTRY := 61845;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, 1.85, 'Hellscream''s Vanguard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1839.9514, -5489.2446, 441.44098, NULL, 250),
(@PATH, 1, 1834.1892, -5489.1113, 438.07062, NULL, 0),
(@PATH, 2, 1826.9688, -5488.384, 433.78827, NULL, 0),
(@PATH, 3, 1819.4791, -5486.394, 429.89764, NULL, 0),
(@PATH, 4, 1812.2916, -5483.625, 426.2034, NULL, 0),
(@PATH, 5, 1804.8403, -5479.7275, 423.97452, NULL, 0),
(@PATH, 6, 1799.0312, -5474.866, 422.18555, NULL, 0),
(@PATH, 7, 1795.8334, -5470.382, 422.1491, NULL, 0),
(@PATH, 8, 1794.6423, -5464.6196, 422.06064, NULL, 0),
(@PATH, 9, 1795.6562, -5458.8057, 422.1367, NULL, 0),
(@PATH, 10, 1802.5764, -5449.6685, 423.74796, NULL, 0),
(@PATH, 11, 1808.8959, -5445.424, 425.84082, NULL, 0),
(@PATH, 12, 1817.0781, -5441.6807, 429.6221, NULL, 0),
(@PATH, 13, 1822.4375, -5439.866, 432.32947, NULL, 0),
(@PATH, 14, 1828.4427, -5438.257, 435.99728, NULL, 0),
(@PATH, 15, 1835.717, -5437.311, 440.29, NULL, 0),
(@PATH, 16, 1842.7743, -5436.7207, 443.15982, NULL, 250),
(@PATH, 17, 1835.717, -5437.311, 440.29, NULL, 0),
(@PATH, 18, 1828.4427, -5438.257, 435.99728, NULL, 0),
(@PATH, 19, 1822.5642, -5439.832, 432.39252, NULL, 0),
(@PATH, 20, 1817.0781, -5441.6807, 429.6221, NULL, 0),
(@PATH, 21, 1808.8959, -5445.424, 425.84082, NULL, 0),
(@PATH, 22, 1802.5764, -5449.6685, 423.74796, NULL, 0),
(@PATH, 23, 1795.6562, -5458.8057, 422.1367, NULL, 0),
(@PATH, 24, 1794.6423, -5464.6196, 422.06064, NULL, 0),
(@PATH, 25, 1795.8334, -5470.382, 422.1491, NULL, 0),
(@PATH, 26, 1799.0312, -5474.866, 422.18555, NULL, 0),
(@PATH, 27, 1804.8403, -5479.7275, 423.97452, NULL, 0),
(@PATH, 28, 1812.2916, -5483.625, 426.2034, NULL, 0),
(@PATH, 29, 1819.4791, -5486.394, 429.89764, NULL, 0),
(@PATH, 30, 1826.9688, -5488.384, 433.78827, NULL, 0),
(@PATH, 31, 1834.1892, -5489.1113, 438.07062, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+72;
SET @ENTRY := 61845;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 1.5, 'Hellscream''s Vanguard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1841.7396, -5463.0156, 495.15375, NULL, 31000),
(@PATH, 1, 1846.2084, -5462.6846, 494.09393, NULL, 0),
(@PATH, 2, 1850.2084, -5465.4346, 494.09393, NULL, 0),
(@PATH, 3, 1853.4584, -5470.9346, 494.34393, NULL, 0),
(@PATH, 4, 1853.7084, -5476.6846, 496.84393, NULL, 0),
(@PATH, 5, 1853.7084, -5483.1846, 499.09393, NULL, 0),
(@PATH, 6, 1850.7084, -5486.4346, 499.09393, NULL, 0),
(@PATH, 7, 1841.9584, -5488.4346, 499.09393, NULL, 0),
(@PATH, 8, 1830.6771, -5490.354, 499.0341, NULL, 31000),
(@PATH, 9, 1836.7084, -5489.4346, 499.09393, NULL, 0),
(@PATH, 10, 1845.2084, -5487.9346, 499.09393, NULL, 0),
(@PATH, 11, 1853.7084, -5483.4346, 499.09393, NULL, 0),
(@PATH, 12, 1853.7084, -5475.9346, 496.34393, NULL, 0),
(@PATH, 13, 1853.4584, -5469.1846, 494.09393, NULL, 0),
(@PATH, 14, 1847.4584, -5463.4346, 494.09393, NULL, 0),
(@PATH, 15, 1843.4584, -5462.6846, 495.09393, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+73;
SET @ENTRY := 61845;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 1.5, 'Hellscream''s Vanguard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1861.0929, -5461.5107, 494.23907, NULL, 0),
(@PATH, 1, 1855.5929, -5459.0107, 494.23907, NULL, 0),
(@PATH, 2, 1853.3429, -5452.2607, 494.73907, NULL, 0),
(@PATH, 3, 1852.5929, -5445.0107, 497.73907, NULL, 0),
(@PATH, 4, 1852.5929, -5441.2607, 499.23907, NULL, 0),
(@PATH, 5, 1857.8429, -5437.2607, 498.98907, NULL, 0),
(@PATH, 6, 1867.0929, -5434.2607, 498.98907, NULL, 0),
(@PATH, 7, 1879.224, -5431.597, 498.82437, NULL, 31000),
(@PATH, 8, 1874.3429, -5432.2607, 498.98907, NULL, 0),
(@PATH, 9, 1867.0929, -5434.5107, 498.98907, NULL, 0),
(@PATH, 10, 1857.8429, -5437.2607, 498.98907, NULL, 0),
(@PATH, 11, 1852.8429, -5441.5107, 499.23907, NULL, 0),
(@PATH, 12, 1853.0929, -5448.7607, 496.23907, NULL, 0),
(@PATH, 13, 1853.5929, -5455.0107, 494.23907, NULL, 0),
(@PATH, 14, 1858.5929, -5460.7607, 494.23907, NULL, 0),
(@PATH, 15, 1863.3429, -5462.0107, 495.23907, NULL, 0),
(@PATH, 16, 1864.9618, -5461.924, 495.15375, NULL, 31000);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+74;
SET @ENTRY := 61845;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, 1.5, 'Hellscream''s Vanguard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1871.7031, -5457.001, 443.14447, NULL, 0), -- Spline
(@PATH, 1, 1879.2031, -5456.251, 440.89447, NULL, 0), -- Spline
(@PATH, 2, 1887.9531, -5454.751, 439.64447, NULL, 0), -- Spline
(@PATH, 3, 1893.7673, -5451.875, 439.15887, NULL, 400),
(@PATH, 4, 1893.7673, -5451.875, 439.15887, 3.65622711181640625, 31250),
(@PATH, 5, 1887.9531, -5454.751, 439.64447, NULL, 0), -- Spline
(@PATH, 6, 1879.4531, -5456.501, 440.89447, NULL, 0), -- Spline
(@PATH, 7, 1871.7031, -5457.001, 443.14447, NULL, 0), -- Spline
(@PATH, 8, 1861.6389, -5457.627, 443.63004, NULL, 31500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+75;
SET @ENTRY := 61845;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, 1.5, 'Hellscream''s Vanguard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1887.6145, -5467.1875, 439.64777, NULL, 0), -- Spline
(@PATH, 1, 1880.1145, -5466.6875, 440.64777, NULL, 0), -- Spline
(@PATH, 2, 1872.1145, -5467.1875, 443.14777, NULL, 0), -- Spline
(@PATH, 3, 1862.2048, -5466.347, 443.6367, NULL, 31250),
(@PATH, 4, 1872.1145, -5467.1875, 443.14777, NULL, 0), -- Spline
(@PATH, 5, 1880.1145, -5466.9375, 440.64777, NULL, 0), -- Spline
(@PATH, 6, 1887.6145, -5467.4375, 439.64777, NULL, 0), -- Spline
(@PATH, 7, 1895.0243, -5470.528, 439.15887, NULL, 100),
(@PATH, 8, 1895.0243, -5470.528, 439.15887, 2.65421915054321289, 31000);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+76;
SET @ENTRY := 61845;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, 1.6, 'Hellscream''s Vanguard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1891.9618, -5440.866, 445.9387, NULL, 0),
(@PATH, 1, 1904.2448, -5446.2085, 447.18033, NULL, 0),
(@PATH, 2, 1913.3142, -5454.655, 448.3496, NULL, 0),
(@PATH, 3, 1913.658, -5466.116, 448.3837, NULL, 0),
(@PATH, 4, 1907.5677, -5472.9844, 447.3973, NULL, 0),
(@PATH, 5, 1897.5469, -5479.1284, 446.25885, NULL, 0),
(@PATH, 6, 1882.7673, -5483.2207, 445.36072, NULL, 250),
(@PATH, 7, 1897.5469, -5479.1284, 446.25885, NULL, 0),
(@PATH, 8, 1907.5677, -5472.9844, 447.3973, NULL, 0),
(@PATH, 9, 1913.658, -5466.116, 448.3837, NULL, 0),
(@PATH, 10, 1913.3142, -5454.655, 448.3496, NULL, 0),
(@PATH, 11, 1904.2448, -5446.2085, 447.18033, NULL, 0),
(@PATH, 12, 1891.9618, -5440.866, 445.9387, NULL, 0),
(@PATH, 13, 1879.1702, -5439.125, 445.27353, NULL, 250);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+77;
SET @ENTRY := 61846;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, 1.6, 'Gorrok - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1874.4202, -5461.5503, 418.39847, NULL, 0),
(@PATH, 1, 1866.4323, -5461.7847, 415.35764, NULL, 0),
(@PATH, 2, 1852.349, -5462.4204, 414.86203, NULL, 0),
(@PATH, 3, 1838.6545, -5463.137, 414.8746, NULL, 0),
(@PATH, 4, 1837.0007, -5463.098, 415.1945, NULL, 0), -- Spline
(@PATH, 5, 1833.5007, -5463.348, 415.6945, NULL, 0), -- Spline
(@PATH, 6, 1833.2507, -5463.348, 415.9445, NULL, 0), -- Spline
(@PATH, 7, 1827.5007, -5463.348, 417.6945, NULL, 0), -- Spline
(@PATH, 8, 1826.0007, -5463.348, 418.1945, NULL, 0), -- Spline
(@PATH, 9, 1822.6945, -5463.672, 418.52347, NULL, 0),
(@PATH, 10, 1813.9479, -5464.0884, 419.8875, NULL, 500),
(@PATH, 11, 1822.6945, -5463.672, 418.52347, NULL, 0),
(@PATH, 12, 1825.7357, -5463.57, 418.05176, NULL, 0),
(@PATH, 13, 1827.1753, -5463.522, 417.40518, NULL, 0),
(@PATH, 14, 1833.257, -5463.318, 415.44995, NULL, 0),
(@PATH, 15, 1833.483, -5463.3105, 415.39157, NULL, 0),
(@PATH, 16, 1836.8435, -5463.1978, 414.88644, NULL, 0),
(@PATH, 17, 1838.6545, -5463.137, 414.8746, NULL, 0),
(@PATH, 18, 1852.349, -5462.4204, 414.86203, NULL, 0),
(@PATH, 19, 1866.4323, -5461.7847, 415.35764, NULL, 0),
(@PATH, 20, 1874.4202, -5461.5503, 418.39847, NULL, 0),
(@PATH, 21, 1888.5243, -5460.8125, 419.27628, NULL, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+91;
SET @ENTRY := 67038;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1882.9713, -5454.0376, 419.56934, NULL, 0), -- Spline
(@PATH, 1, 1877.7213, -5458.5376, 419.31934, NULL, 0), -- Spline
(@PATH, 2, 1871.7213, -5459.0376, 417.56934, NULL, 0), -- Spline
(@PATH, 3, 1865.9713, -5464.7876, 415.81934, NULL, 0), -- Spline
(@PATH, 4, 1865.7213, -5472.5376, 416.81934, NULL, 0), -- Spline
(@PATH, 5, 1865.4713, -5478.5376, 419.06934, NULL, 0), -- Spline
(@PATH, 6, 1866.7213, -5489.5376, 419.31934, NULL, 0), -- Spline
(@PATH, 7, 1866.3854, -5495.7485, 419.6475, NULL, 42000),
(@PATH, 8, 1866.7213, -5488.7876, 419.31934, NULL, 0), -- Spline
(@PATH, 9, 1866.2213, -5481.0376, 419.06934, NULL, 0), -- Spline
(@PATH, 10, 1866.2213, -5470.0376, 416.06934, NULL, 0), -- Spline
(@PATH, 11, 1867.9713, -5463.0376, 416.06934, NULL, 0), -- Spline
(@PATH, 12, 1873.7213, -5460.5376, 418.56934, NULL, 0), -- Spline
(@PATH, 13, 1879.7213, -5457.0376, 419.31934, NULL, 0), -- Spline
(@PATH, 14, 1885.5573, -5449.3267, 419.4912, NULL, 350),
(@PATH, 15, 1885.5573, -5449.3267, 419.4912, 1.660551786422729492, 35000);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+92;
SET @ENTRY := 67038;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1850.9141, -5441.205, 418.62073, NULL, 0), -- Spline
(@PATH, 1, 1851.1641, -5446.955, 418.62073, NULL, 0), -- Spline
(@PATH, 2, 1851.1641, -5454.205, 415.62073, NULL, 0), -- Spline
(@PATH, 3, 1848.1641, -5461.955, 415.37073, NULL, 0), -- Spline
(@PATH, 4, 1840.6641, -5465.205, 415.37073, NULL, 0), -- Spline
(@PATH, 5, 1838.9141, -5470.455, 415.87073, NULL, 0), -- Spline
(@PATH, 6, 1839.4141, -5479.955, 418.87073, NULL, 0), -- Spline
(@PATH, 7, 1839.6641, -5489.705, 419.37073, NULL, 0), -- Spline
(@PATH, 8, 1839.8038, -5497.0225, 419.66833, NULL, 40250),
(@PATH, 9, 1839.9141, -5491.705, 419.37073, NULL, 0), -- Spline
(@PATH, 10, 1839.6641, -5486.955, 419.37073, NULL, 0), -- Spline
(@PATH, 11, 1839.4141, -5479.705, 418.87073, NULL, 0), -- Spline
(@PATH, 12, 1838.6641, -5469.455, 415.87073, NULL, 0), -- Spline
(@PATH, 13, 1840.1641, -5464.455, 415.37073, NULL, 0), -- Spline
(@PATH, 14, 1845.1641, -5462.955, 415.37073, NULL, 0), -- Spline
(@PATH, 15, 1850.9141, -5458.455, 415.37073, NULL, 0), -- Spline
(@PATH, 16, 1851.6641, -5451.955, 416.12073, NULL, 0), -- Spline
(@PATH, 17, 1851.1641, -5442.455, 418.62073, NULL, 0), -- Spline
(@PATH, 18, 1849.9141, -5435.455, 418.87073, NULL, 0), -- Spline
(@PATH, 19, 1850.0243, -5428.887, 419.07312, NULL, 41000);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 191640, 1, 14, 6529, '0', 1663, 0, 1074, 1891.0684814453125, -5446.04345703125, 419.7188720703125, 4.288222312927246093, -0.0033416748046875, 0.005175590515136718, -0.84009170532226562, 0.542409360408782958, 120, 255, 1, 56819); -- Anvil (Area: Hellscream's Fist - Difficulty: 0) CreateObject1

-- Terrain swap
DELETE FROM `terrain_swap_defaults` WHERE `MapId`=1 AND `TerrainSwapMap`=1074;
INSERT INTO `terrain_swap_defaults` (`MapId`, `TerrainSwapMap`, `Comment`) VALUES
(1, 1074, 'Kalimdor - Orgrimmar Gunship Pandaria Start');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=25 AND `SourceEntry`=1074;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=-@CONDREFID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25,0,1074,0,0,-@CONDREFID,0,0,0,0,'',0,0,0,'','Apply terrain swap 1074 if condition reference 40002 is fulfilled'),
(-@CONDREFID,0,0,0,0,47,0,29611,64,0,'',0,0,0,'','Apply condition reference if quest 29611 is rewarded'),
(-@CONDREFID,0,0,0,1,47,0,29612,64,0,'',0,0,0,'','Apply condition reference if quest 29612 is rewarded'),
(-@CONDREFID,0,0,0,2,47,0,49538,64,0,'',0,0,0,'','Apply condition reference if quest 49538 is rewarded'),
(-@CONDREFID,0,0,0,3,47,0,49852,64,0,'',0,0,0,'','Apply condition reference if quest 49852 is rewarded'),
(-@CONDREFID,0,0,0,4,47,0,60126,64,0,'',0,0,0,'','Apply condition reference if quest 60126 is rewarded');

-- Smart scripts
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (55054, 61846, 61866, 61867, 67038, 67040);

UPDATE `smart_scripts` SET `comment`='Areatrigger 8463 - On enter - Invoker casts ''Art of War Movie Aura''' WHERE `entryorguid`=8463 AND `source_type`=2;

UPDATE `creature` SET `StringId`='OrgrimmarGunship' WHERE `guid`=@CGUID+67 AND `id`=55054;

DELETE FROM `smart_scripts` WHERE `entryorguid`=55054 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(55054,0,0,0,'',11,0,100,0,0,0,0,0,0,'',11,46905,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'General Nazgrim - On respawn - Cast ''Summon Collision Object'''),
(55054,0,1,0,'',1,0,100,0,0,15000,30000,45000,0,'',1,0,0,1,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'General Nazgrim - Out of combat (30-45s) - Talk');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=55054;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,55054,0,0,58,1,0,0,0,'OrgrimmarGunship',0,0,0,'','Trigger smart event if object has StringId ''OrgrimmarGunship'''),
(22,2,55054,0,0,58,1,0,0,0,'OrgrimmarGunship',0,0,0,'','Trigger smart event if object has StringId ''OrgrimmarGunship''');

DELETE FROM `creature_text` WHERE `CreatureID`=55054 AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(55054, 0, 0, 'Keep polishing those cannonballs. I want to see my face in them!', 12, 0, 100, 0, 0, 0, 68497, 0, 'General Nazgrim'),
(55054, 0, 1, 'I want this deck so clean I could eat off of it!', 12, 0, 100, 0, 0, 0, 68499, 0, 'General Nazgrim'),
(55054, 0, 2, 'Careful with that! If I see a single scratch on my new ship, it''ll be your head!', 12, 0, 100, 0, 0, 0, 68500, 0, 'General Nazgrim'),
(55054, 0, 3, 'Pick up the pace, men. We''re about ready to set off!', 12, 0, 100, 0, 0, 0, 68501, 0, 'General Nazgrim');

DELETE FROM `smart_scripts` WHERE `entryorguid`=61846 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61846,0,0,0,'',1,0,100,0,0,15000,30000,45000,0,'',1,0,0,1,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Gorrok - Out of combat (30-45s) - Talk');

DELETE FROM `creature_text` WHERE `CreatureID`=61846 AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(61846, 0, 0, 'Keep working! The general won''t tolerate failure.', 12, 0, 100, 0, 0, 0, 68490, 0, 'Gorrok'),
(61846, 0, 1, 'Get those engines running! Now!', 12, 0, 100, 0, 0, 0, 68491, 0, 'Gorrok'),
(61846, 0, 2, 'Put your backs into it! You''re the most pathetic group of goblins I''ve ever seen!', 12, 0, 100, 0, 0, 0, 68492, 0, 'Gorrok'),
(61846, 0, 3, 'Faster! The warchief''s eyes are upon you.', 12, 0, 100, 0, 0, 0, 68494, 0, 'Gorrok');

DELETE FROM `smart_scripts` WHERE `entryorguid`=61866 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61866,0,0,0,'',1,0,100,0,0,16000,15000,16000,0,'',10,22,70,273,396,397,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Shokia - Out of combat (15-16s) - Play random emote');

DELETE FROM `smart_scripts` WHERE `entryorguid`=61867 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61867,0,0,0,'',1,0,100,0,0,17000,16000,17000,0,'',10,22,70,273,396,397,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Kiryn - Out of combat (16-17s) - Play random emote');

UPDATE `creature` SET `StringId`='LoadCannon' WHERE `guid`=@CGUID+88 AND `id`=67038;
UPDATE `creature` SET `StringId`='RandomEmote' WHERE `guid` IN (@CGUID+102, @CGUID+103) AND `id`=67038;

SET @ENTRY := 67038;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
SET @ACTIONLIST := 67038 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=67038 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` BETWEEN @ACTIONLIST+0 AND @ACTIONLIST+5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(67038,0,0,0,'',40,0,100,0,7,@PATH+0,0,0,0,'',80,@ACTIONLIST+0,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 1 node 7 reached - Call timed actionlist 1'),
(67038,0,1,0,'',40,0,100,0,15,@PATH+0,0,0,0,'',80,@ACTIONLIST+1,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 1 node 15 reached - Call timed actionlist 2'),
(67038,0,2,0,'',40,0,100,0,8,@PATH+1,0,0,0,'',80,@ACTIONLIST+2,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 2 node 8 reached - Call timed actionlist 3'),
(67038,0,3,0,'',40,0,100,0,19,@PATH+1,0,0,0,'',80,@ACTIONLIST+3,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 2 node 19 reached - Call timed actionlist 4'),
(67038,0,4,0,'',1,0,100,0,0,30000,60000,90000,0,'',80,@ACTIONLIST+4,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - Out of combat (60-90s) - Call timed actionlist 5'),
(67038,0,5,0,'',58,0,100,0,0xFFFFFFFF,@PATH+2,0,0,0,'',80,@ACTIONLIST+5,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On scripted path 1 ended - Call timed actionlist 6'),
(67038,0,6,0,'',1,0,100,0,0,3000,6000,9000,0,'',10,5,14,15,25,274,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - Out of combat (6-9s) - Play random emote'),
(@ACTIONLIST+0,9,0,0,'',0,0,100,0,2000,2000,0,0,0,'',17,133,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Set emote state'),
(@ACTIONLIST+0,9,1,0,'',0,0,100,0,40000,40000,0,0,0,'',17,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove emote state'),
(@ACTIONLIST+1,9,0,0,'',0,0,100,0,0,0,0,0,0,'',17,233,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Set emote state'),
(@ACTIONLIST+1,9,1,0,'',0,0,100,0,35000,35000,0,0,0,'',17,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove emote state'),
(@ACTIONLIST+2,9,0,0,'',0,0,100,0,250,250,0,0,0,'',17,69,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Set emote state'),
(@ACTIONLIST+2,9,1,0,'',0,0,100,0,40000,40000,0,0,0,'',17,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove emote state'),
(@ACTIONLIST+3,9,0,0,'',0,0,100,0,250,250,0,0,0,'',17,233,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Set emote state'),
(@ACTIONLIST+3,9,1,0,'',0,0,100,0,40850,40850,0,0,0,'',17,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove emote state'),
(@ACTIONLIST+4,9,0,0,'',0,0,100,0,0,0,0,0,0,'',5,381,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Play emote'),
(@ACTIONLIST+4,9,1,0,'',0,0,100,0,0,0,0,0,0,'',11,79367,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Cast ''Holding a Cannonball'''),
(@ACTIONLIST+4,9,2,0,'',0,0,100,0,0,0,0,0,0,'',53,0,@PATH+2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Start scripted path 1'),
(@ACTIONLIST+5,9,0,0,'',0,0,100,0,2500,2500,0,0,0,'',5,61,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Play emote'),
(@ACTIONLIST+5,9,1,0,'',0,0,100,0,0,0,0,0,0,'',28,79367,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove aura ''Holding a Cannonball'''),
(@ACTIONLIST+5,9,2,0,'',0,0,100,0,1200,1200,0,0,0,'',53,0,@PATH+3,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Start scripted path 2'),
(@ACTIONLIST+5,9,3,0,'',0,0,100,0,0,0,0,0,0,'',1,0,0,1,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Talk');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=67038;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,5,67038,0,0,58,1,0,0,0,'LoadCannon',0,0,0,'','Trigger smart event if object has StringId ''LoadCannon'''),
(22,7,67038,0,0,58,1,0,0,0,'RandomEmote',0,0,0,'','Trigger smart event if object has StringId ''RandomEmote''');

DELETE FROM `creature_text` WHERE `CreatureID`=67038 AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(67038, 0, 0, 'Cannon loaded!', 12, 0, 100, 0, 0, 0, 68477, 0, 'Hellscream''s Fist Engineer');

DELETE FROM `waypoint_path` WHERE `PathId` IN (@PATH+2, @PATH+3);
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH+2, 0, 0x2, 1, 'Hellscream''s Fist Engineer - Scripted Path'),
(@PATH+3, 0, 0x2, 2, 'Hellscream''s Fist Engineer - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH+2, @PATH+3);
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH+2, 0, 1867.2361, -5490.635, 445.39252, NULL, 0), -- Spline
(@PATH+2, 1, 1863.7361, -5492.885, 445.14252, NULL, 0), -- Spline
(@PATH+2, 2, 1861.4861, -5493.885, 444.89252, NULL, 0), -- Spline
(@PATH+2, 3, 1861.0139, -5493.3647, 444.78436, NULL, 0),
(@PATH+3, 0, 1863.7361, -5492.885, 445.14252, NULL, 0), -- Spline
(@PATH+3, 1, 1866.9861, -5490.635, 445.39252, NULL, 0), -- Spline
(@PATH+3, 2, 1866.4584, -5487.905, 444.50064, NULL, 350),
(@PATH+3, 3, 1866.4584, -5487.905, 444.50064, 3.777480840682983398, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=67040 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(67040,0,0,0,'',11,0,100,0,0,0,0,0,0,'',11,131804,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Deckswabber - On respawn - Cast ''Arcane Channeling''');
