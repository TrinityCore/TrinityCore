 --
 --
 -- Silverpine Forest

--
-- The Shining Strand

-- Note: deleting wrong spawns since only the vehicle should be scripted and implemented to summon its own accessories.
DELETE FROM `creature` WHERE `guid` IN (321253, 321256, 321257, 321260, 321259, 321255, 321258, 320991, 321009, 321012, 321014, 321011, 321010, 321013, 320990, 321745, 321746, 321750, 321747, 321749, 321751, 321748, 321744, 321254, 326732, 326733, 326734, 326735, 326736, 326737, 326090, 326091, 326092, 326093, 326094, 326095, 325730, 325728, 325732, 325729, 325734, 325735, 325733, 325731, 322266, 322276, 322278, 322280, 322277, 322279, 322281);

-- Horde Hauler
UPDATE `creature` SET `phaseUseFlags` = 1 WHERE `guid` = 322265;

UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_horde_hauler'  WHERE `entry` = 44731;

DELETE FROM `creature_template_movement` WHERE `CreatureId`=44731;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Random`, `InteractionPauseTimer`) VALUES 
(44731, 1, 0, 0, 0, 0, NULL);

DELETE FROM `spell_script_names` WHERE `spell_id` = 84238 AND `ScriptName` = 'spell_silverpine_magical_chains_hauler';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(84238, 'spell_silverpine_magical_chains_hauler');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83464 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44737 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 83464, 0, 2, 31, 0, 3, 44737, 0, 0, 0, 0, '', 'Magical Chains - Target Subdued Forest Ettin');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83467 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44737 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 83467, 0, 2, 31, 0, 3, 44737, 0, 0, 0, 0, '', 'Magical Chains - Target Subdued Forest Ettin');

DELETE FROM `spell_script_names` WHERE `spell_id` = 83477 AND `ScriptName` = 'spell_gen_eject_passengers_3_8';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83477, 'spell_gen_eject_passengers_3_8');

DELETE FROM `vehicle_template_accessory` WHERE `entry` = 44731;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(44731, 44734, 0, 1, 'Sitting on top - Horde Engineer', 8, 30000),
(44731, 44737, 1, 1, 'Subdued Forest Ettin', 8, 30000),
(44731, 0, 2, 0, 'Sitting on floor (top left) - Player side', 8, 30000),
(44731, 44733, 3, 0, 'Sitting on floor (top right) - Female Trooper', 8, 30000),
(44731, 44732, 4, 0, 'Sitting on floor (bottom left) - Male Trooper', 8, 30000),
(44731, 44733, 5, 0, 'Sitting on floor (bottom right) - Female Trooper', 8, 30000),
(44731, 44733, 6, 0, 'Sitting on shelf (bottom left) - Female trooper', 8, 30000),
(44731, 44732, 7, 0, 'Sitting on shelf (bottom right) - Male trooper', 8, 30000);

DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry` IN (8394, 8395, 8396, 8397);
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES 
(8394, 3.14159, 0, 0, 0, 0, 0),
(8395, 3.14159, 0, 0, 0, 0, 0),
(8396, 3.14159, 0, 0, 0, 0, 0),
(8397, 3.14159, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 447310;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(447310, 1, 1442.45, 683.194, 47.21392, NULL, 0, 1, 0, 0, 0),
(447310, 2, 1422.39, 713.509, 47.1535, NULL, 0, 1, 0, 0, 0),
(447310, 3, 1410.4, 745.214, 47.251, NULL, 0, 1, 0, 0, 0),
(447310, 4, 1394.08, 784.649, 47.12907, NULL, 0, 1, 0, 0, 0),
(447310, 5, 1376.23, 828.832, 48.75095, NULL, 0, 1, 0, 0, 0),
(447310, 6, 1365.51, 856.457, 51.24048, NULL, 0, 1, 0, 0, 0),
(447310, 7, 1354.39, 887.825, 54.36447, NULL, 0, 1, 0, 0, 0),
(447310, 8, 1343.64, 925.507, 54.68269, NULL, 0, 1, 0, 0, 0),
(447310, 9, 1337.94, 956.62, 54.63557, NULL, 0, 1, 0, 0, 0),
(447310, 10, 1332.58, 998.137, 54.67904, NULL, 0, 1, 0, 0, 0),
(447310, 11, 1326.23, 1016.23, 54.71355, NULL, 22863, 1, 0, 0, 0),
(447310, 12, 1296.54, 1066.29, 54.07921, NULL, 0, 1, 0, 0, 0),
(447310, 13, 1271.49, 1096.01, 51.89646, NULL, 0, 1, 0, 0, 0),
(447310, 14, 1242.83, 1120.81, 50.58637, NULL, 0, 1, 0, 0, 0),
(447310, 15, 1215.21, 1141.04, 50.52694, NULL, 0, 1, 0, 0, 0),
(447310, 16, 1179.04, 1166.92, 48.97422, NULL, 0, 1, 0, 0, 0),
(447310, 17, 1143.06, 1189.04, 47.96444, NULL, 0, 1, 0, 0, 0),
(447310, 18, 1104.62, 1214.52, 46.48087, NULL, 0, 1, 0, 0, 0),
(447310, 19, 1079.26, 1238.68, 46.27145, NULL, 0, 1, 0, 0, 0),
(447310, 20, 1058.24, 1260.29, 46.20926, NULL, 0, 1, 0, 0, 0),
(447310, 21, 1031.2, 1283.19, 46.02351, NULL, 0, 1, 0, 0, 0),
(447310, 22, 1003.73, 1300.82, 45.92109, NULL, 0, 1, 0, 0, 0),
(447310, 23, 973.655, 1319.77, 45.81734, NULL, 0, 1, 0, 0, 0),
(447310, 24, 944.924, 1337.44, 46.59942, NULL, 0, 1, 0, 0, 0),
(447310, 25, 914.736, 1350.73, 48.26861, NULL, 0, 1, 0, 0, 0),
(447310, 26, 884.262, 1359.47, 51.60058, NULL, 0, 1, 0, 0, 0),
(447310, 27, 862.208, 1360.47, 55.05869, NULL, 0, 1, 0, 0, 0),
(447310, 28, 817.226, 1360.42, 56.82727, NULL, 0, 1, 0, 0, 0),
(447310, 29, 781.707, 1361.56, 63.38396, NULL, 0, 1, 0, 0, 0),
(447310, 30, 756.422, 1363.12, 68.24586, NULL, 0, 1, 0, 0, 0),
(447310, 31, 726.372, 1355.76, 72.68143, NULL, 0, 1, 0, 0, 0),
(447310, 32, 706.53, 1343.75, 76.35209, NULL, 0, 1, 0, 0, 0),
(447310, 33, 684.753, 1324.13, 79.64048, NULL, 0, 1, 0, 0, 0),
(447310, 34, 657.045, 1307.14, 83.46642, NULL, 0, 1, 0, 0, 0),
(447310, 35, 632.7715, 1297.872, 86.28932, NULL, 22727, 1, 0, 0, 0),
(447310, 36, 588.17, 1264.16, 87.0507, NULL, 0, 1, 0, 0, 0),
(447310, 37, 563.847, 1243.76, 86.40284, NULL, 0, 1, 0, 0, 0),
(447310, 38, 538.931, 1232.14, 88.07486, NULL, 0, 1, 0, 0, 0),
(447310, 39, 510.122, 1229.87, 89.16954, NULL, 0, 1, 0, 0, 0),
(447310, 40, 473.8, 1229.53, 88.59075, NULL, 0, 1, 0, 0, 0),
(447310, 41, 426.493, 1231.84, 86.02214, NULL, 0, 1, 0, 0, 0),
(447310, 42, 380.946, 1236.21, 82.31158, NULL, 0, 1, 0, 0, 0),
(447310, 43, 354.031, 1242.62, 81.45962, NULL, 0, 1, 0, 0, 0),
(447310, 44, 316.095, 1254.61, 79.77526, NULL, 0, 1, 0, 0, 0),
(447310, 45, 276.116, 1268.98, 76.91445, NULL, 0, 1, 0, 0, 0),
(447310, 46, 252.155, 1271.47, 76.86637, NULL, 0, 1, 0, 0, 0),
(447310, 47, 229.385, 1269.64, 75.74796, NULL, 0, 1, 0, 0, 0),
(447310, 48, 196.939, 1261.47, 73.74019, NULL, 0, 1, 0, 0, 0),
(447310, 49, 165.106, 1252.77, 71.03636, NULL, 0, 1, 0, 0, 0),
(447310, 50, 129.401, 1241.76, 70.83018, NULL, 0, 1, 0, 0, 0),
(447310, 51, 99.1649, 1232.69, 68.65864, NULL, 0, 1, 0, 0, 0),
(447310, 52, 72.3872, 1224.89, 66.99799, NULL, 0, 1, 0, 0, 0),
(447310, 53, 41.9844, 1217.66, 65.97113, NULL, 0, 1, 0, 0, 0),
(447310, 54, 6.75347, 1207.66, 64.7567, NULL, 0, 1, 0, 0, 0),
(447310, 55, -22.8194, 1196.91, 64.54131, NULL, 0, 1, 0, 0, 0),
(447310, 56, -55.3455, 1183.69, 64.11707, NULL, 0, 1, 0, 0, 0),
(447310, 57, -74.224, 1185.74, 64.07846, NULL, 0, 1, 0, 0, 0),
(447310, 58, -97.8073, 1205.1, 61.67491, NULL, 0, 1, 0, 0, 0),
(447310, 59, -122.601, 1218.69, 57.16767, NULL, 0, 1, 0, 0, 0),
(447310, 60, -140.623, 1220.49, 55.77021, NULL, 14437, 1, 0, 0, 0),
(447310, 61, -217.497, 1197.7, 61.34966, NULL, 0, 1, 0, 0, 0),
(447310, 62, -237.741, 1184, 63.89516, NULL, 0, 1, 0, 0, 0),
(447310, 63, -277.264, 1186.42, 63.71381, NULL, 0, 1, 0, 0, 0);

-- Horde Engineer
DELETE FROM `creature_text` WHERE `CreatureID` = 44734;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(44734, 0, 0, 'This is one way trip, kid, and you definitely don\'t want to be comin\' back on the other wagon.', 12, 0, 100, 1, 0, 0, 44790, 0, ''),
(44734, 1, 0, 'ALL ABOARD! Next stop: The Sepulcher.', 14, 0, 100, 1, 0, 0, 44796, 1, ''),
(44734, 2, 0, 'ALL ABOARD! Last stop: The Forsaken Front!', 14, 0, 100, 1, 0, 0, 44797, 1, ''),
(44734, 3, 0, 'Final stop, the Forsaken Front! EVERYBODY OUT!', 14, 0, 100, 1, 0, 0, 44788, 1, '');

 -- Forsaken Trooper
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (44732, 44733);

DELETE FROM `waypoint_data` WHERE `id` = 447320;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(447320, 0, -138.467, 1210.44, 57.902, NULL, 0, 1, 0, 0, 0),
(447320, 1, -147.641, 1199.19, 60.5892, NULL, 0, 1, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 447321;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(447321, 0, -132.394, 1210.54, 58.138, NULL, 0, 1, 0, 0, 0),
(447321, 1, -120.899, 1201.57, 60.6242, NULL, 0, 1, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 447322;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(447322, 0, -121.82, 1219.51, 56.9907, NULL, 0, 1, 0, 0, 0),
(447322, 1, -109.419, 1222.84, 57.6165, NULL, 0, 1, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 447323;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(447323, 0, -127.809, 1233.05, 54.2031, NULL, 0, 1, 0, 0, 0),
(447323, 1, -124.922, 1245.05, 53.6781, NULL, 0, 1, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 447324;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(447324, 0, -144.589, 1234.47, 52.8815, NULL, 0, 1, 0, 0, 0),
(447324, 1, -142.385, 1242.93, 53.0675, NULL, 0, 1, 0, 0, 0);

SET @ENTRY := 44732;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 40, 0, 100, 0, 1, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On waypoint 1 of any path reached - Self: Despawn instantly");

SET @ENTRY := 44733;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 40, 0, 100, 0, 1, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On waypoint 1 of any path reached - Self: Despawn instantly");

-- Dreadguard
UPDATE `creature` SET `position_x`= 1384.912, `position_y`= 775.5963, `position_z`= 47.12907, `MovementType`= 2 WHERE `guid` = 322155;
UPDATE `creature` SET `position_x`= 1384.912, `position_y`= 775.5963, `position_z`= 47.12907 WHERE `guid` = 322154;
UPDATE `creature` SET `position_x`= 1384.912, `position_y`= 775.5963, `position_z`= 47.12907 WHERE `guid` = 322153;
UPDATE `creature` SET `position_x`= 1384.912, `position_y`= 775.5963, `position_z`= 47.12907 WHERE `guid` = 322152;

DELETE FROM `creature_formations` WHERE `MemberGUID` IN (322155, 322154, 322153, 322152);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(322155, 322155, 0, 0, 515, 0, 53),
(322155, 322154, 3.5, 0, 515, 0, 0),
(322155, 322153, 7, 0, 515, 0, 0),
(322155, 322152, 10.5, 0, 515, 0, 0);

SET @PATH := 322155 * 10;
DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 1384.91200, 775.5963, 47.12907, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 1383.60300, 778.6824, 47.12907, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 1382.29100, 781.7736, 47.12907, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 1380.96400, 784.9004, 47.12907, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 1379.64800, 788.0018, 47.12907, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 1378.33100, 791.1057, 47.12907, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 1377.01000, 794.2172, 47.12907, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 1375.70100, 797.3033, 47.12907, NULL, 0, 0, 0, 0, 0),
(@PATH, 9, 1374.58300, 799.975, 47.12907, NULL, 0, 0, 0, 0, 0),
(@PATH, 10, 1373.37800, 802.7822, 47.25095, NULL, 0, 0, 0, 0, 0),
(@PATH, 11, 1372.18600, 805.5614, 47.25095, NULL, 0, 0, 0, 0, 0),
(@PATH, 12, 1370.97900, 808.3718, 47.61301, NULL, 0, 0, 0, 0, 0),
(@PATH, 13, 1369.78800, 811.1464, 47.75095, NULL, 0, 0, 0, 0, 0),
(@PATH, 14, 1368.58500, 813.9491, 47.9874, NULL, 0, 0, 0, 0, 0),
(@PATH, 15, 1367.42100, 816.6592, 48.12595, NULL, 0, 0, 0, 0, 0),
(@PATH, 16, 1366.22500, 819.4452, 48.59261, NULL, 0, 0, 0, 0, 0),
(@PATH, 17, 1365.08200, 822.1055, 48.95602, NULL, 0, 0, 0, 0, 0),
(@PATH, 18, 1363.81900, 825.0491, 49.02438, NULL, 0, 0, 0, 0, 0),
(@PATH, 19, 1362.63200, 827.8148, 49.03439, NULL, 0, 0, 0, 0, 0),
(@PATH, 20, 1361.43700, 830.5966, 49.63009, NULL, 0, 0, 0, 0, 0),
(@PATH, 21, 1360.24400, 833.3763, 49.89441, NULL, 0, 0, 0, 0, 0),
(@PATH, 22, 1359.03900, 836.1404, 49.974, NULL, 0, 0, 0, 0, 0),
(@PATH, 23, 1357.79000, 838.8621, 50.18054, NULL, 0, 0, 0, 0, 0),
(@PATH, 24, 1356.86100, 841.723, 50.46521, NULL, 0, 0, 0, 0, 0),
(@PATH, 25, 1355.92900, 844.5958, 50.95178, NULL, 0, 0, 0, 0, 0),
(@PATH, 26, 1355.00200, 847.4554, 51.1145, NULL, 0, 0, 0, 0, 0),
(@PATH, 27, 1354.07000, 850.3271, 51.45178, NULL, 0, 0, 0, 0, 0),
(@PATH, 28, 1353.13300, 853.2153, 51.57678, NULL, 0, 0, 0, 0, 0),
(@PATH, 29, 1352.22900, 856.001, 51.95178, NULL, 0, 0, 0, 0, 0),
(@PATH, 30, 1351.31100, 858.8301, 52.20178, NULL, 0, 0, 0, 0, 0),
(@PATH, 31, 1350.33200, 861.8473, 52.17908, NULL, 0, 0, 0, 0, 0),
(@PATH, 32, 1349.39500, 864.7361, 52.57678, NULL, 0, 0, 0, 0, 0),
(@PATH, 33, 1348.46300, 867.6093, 52.79013, NULL, 0, 0, 0, 0, 0),
(@PATH, 34, 1347.52100, 870.5141, 52.98947, NULL, 0, 0, 0, 0, 0),
(@PATH, 35, 1346.57700, 873.4212, 53.38925, NULL, 0, 0, 0, 0, 0),
(@PATH, 36, 1345.64700, 876.2899, 53.54172, NULL, 0, 0, 0, 0, 0),
(@PATH, 37, 1344.72900, 878.959, 53.86447, NULL, 0, 0, 0, 0, 0),
(@PATH, 38, 1343.81200, 881.9557, 54.11447, NULL, 0, 0, 0, 0, 0),
(@PATH, 39, 1342.92200, 884.8824, 54.45102, NULL, 0, 0, 0, 0, 0),
(@PATH, 40, 1342.04400, 887.7709, 54.61447, NULL, 0, 0, 0, 0, 0),
(@PATH, 41, 1341.15500, 890.6928, 54.61447, NULL, 0, 0, 0, 0, 0),
(@PATH, 42, 1340.27200, 893.5956, 54.61447, NULL, 0, 0, 0, 0, 0),
(@PATH, 43, 1339.38700, 896.5056, 54.61447, NULL, 0, 0, 0, 0, 0),
(@PATH, 44, 1338.50400, 899.4136, 54.61447, NULL, 0, 0, 0, 0, 0),
(@PATH, 45, 1337.62500, 902.2969, 54.68269, NULL, 0, 0, 0, 0, 0),
(@PATH, 46, 1336.75300, 905.1589, 54.68269, NULL, 0, 0, 0, 0, 0),
(@PATH, 47, 1335.84600, 908.0656, 54.68269, NULL, 0, 0, 0, 0, 0),
(@PATH, 48, 1335.00400, 911.0021, 54.68269, NULL, 0, 0, 0, 0, 0),
(@PATH, 49, 1334.16100, 913.9387, 54.68269, NULL, 0, 0, 0, 0, 0),
(@PATH, 50, 1333.31900, 916.8751, 54.69089, NULL, 0, 0, 0, 0, 0),
(@PATH, 51, 1332.48300, 919.79, 54.69089, NULL, 0, 0, 0, 0, 0),
(@PATH, 52, 1331.64400, 922.7169, 54.69089, NULL, 0, 0, 0, 0, 0),
(@PATH, 53, 1330.80900, 925.6294, 54.69089, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` = 322155;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(322155, @PATH, 0, 0, 0, 1, 0, 0, 0, 0, 0, '18950');

UPDATE `creature` SET `position_x`= 1353.238, `position_y`= 905.6061, `position_z`= 54.68269, `MovementType`= 2 WHERE `guid` = 322251;
UPDATE `creature` SET `position_x`= 1353.238, `position_y`= 905.6061, `position_z`= 54.68269, `MovementType`= 2 WHERE `guid` = 322252;
UPDATE `creature` SET `position_x`= 1353.238, `position_y`= 905.6061, `position_z`= 54.68269, `MovementType`= 2 WHERE `guid` = 322253;
UPDATE `creature` SET `position_x`= 1353.238, `position_y`= 905.6061, `position_z`= 54.68269, `MovementType`= 2 WHERE `guid` = 322254;

DELETE FROM `creature_formations` WHERE `MemberGUID` IN (322251, 322252, 322253, 322254);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(322251, 322251, 0, 0, 515, 53, 4),
(322251, 322252, 3.5, 0, 515, 0, 0),
(322251, 322253, 7, 0, 515, 0, 0),
(322251, 322254, 10.5, 0, 515, 0, 0);

SET @PATH := 322251 * 10;
DELETE FROM `waypoint_data` WHERE `id` = 3222510;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 1353.23800, 905.6061, 54.68269, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 1352.52000, 908.5473, 54.68269, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 1351.73400, 911.1792, 54.68269, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 1351.06100, 914.1871, 54.68269, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 1346.56600, 934.3003, 54.63557, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 1347.23000, 931.3288, 54.68269, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 1401.84200, 773.3932, 47.15433, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 1402.98600, 770.5794, 47.15433, NULL, 0, 0, 0, 0, 0),
(@PATH, 9, 1403.93000, 768.2547, 47.15433, NULL, 0, 0, 0, 0, 0),
(@PATH, 10, 1405.04100, 765.4214, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 11, 1406.22400, 762.5724, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 12, 1407.40500, 759.7258, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 13, 1408.58300, 756.8862, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 14, 1409.76600, 754.035, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 15, 1410.94200, 751.2024, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 16, 1412.11400, 748.3769, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 17, 1413.30100, 745.5162, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 18, 1414.49200, 742.6462, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 19, 1415.66900, 739.8113, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 20, 1416.84400, 736.9788, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 21, 1417.29500, 734.1919, 47.251, NULL, 0, 0, 0, 0, 0),
(@PATH, 22, 1418.71400, 731.4598, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 23, 1420.13600, 728.7234, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 24, 1421.55100, 726.0003, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 25, 1422.96400, 723.2817, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 26, 1424.36800, 720.5789, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 27, 1425.78400, 717.8535, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 28, 1427.18800, 715.1529, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 29, 1428.59300, 712.4478, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 30, 1430.00800, 709.7247, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 31, 1429.77100, 707.3503, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 32, 1431.67700, 704.8401, 47.1535, NULL, 0, 0, 0, 0, 0),
(@PATH, 33, 1433.59100, 702.3196, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 34, 1435.49700, 699.8094, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 35, 1437.40200, 697.3013, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 36, 1439.31500, 694.7828, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 37, 1441.20800, 692.2891, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 38, 1443.11500, 689.7789, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 39, 1445.03000, 687.2563, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 40, 1446.94300, 684.7378, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 41, 1448.47300, 682.1757, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 42, 1450.41700, 679.8464, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 43, 1452.35200, 677.5286, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 44, 1454.29700, 675.1973, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 45, 1456.24700, 672.862, 47.21392, NULL, 0, 0, 0, 0, 0),
(@PATH, 46, 1458.20500, 670.5154, 47.08892, NULL, 0, 0, 0, 0, 0),
(@PATH, 47, 1460.05400, 668.3008, 46.96392, NULL, 0, 0, 0, 0, 0),
(@PATH, 48, 1462.10100, 665.8486, 46.76156, NULL, 0, 0, 0, 0, 0),
(@PATH, 49, 1464.05600, 663.505, 46.69552, NULL, 0, 0, 0, 0, 0),
(@PATH, 50, 1466.02100, 661.1499, 46.48605, NULL, 0, 0, 0, 0, 0),
(@PATH, 51, 1467.96700, 658.8179, 46.47313, NULL, 0, 0, 0, 0, 0),
(@PATH, 52, 1468.69400, 657.9465, 46.45701, NULL, 0, 0, 0, 0, 0),
(@PATH, 53, 1476.30300, 648.8282, 46.75413, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` = 322251;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(322251, @PATH, 0, 0, 0, 1, 0, 0, 0, 0, 0, '18950');

-- Forsaken Trooper
UPDATE `creature` SET `equipment_id` = FLOOR(RAND()*(4-1+1)+1) WHERE `id` IN (44791, 44792);

DELETE FROM `creature_addon` WHERE `guid`=322255;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(322255, 0, 0, 0, 0, 1, 455, 0, 0, 0, 0, '');

UPDATE `creature` SET `position_x`= 1350.161, `position_y`= 721.5967, `position_z`= 35.88817, `MovementType`= 2 WHERE `guid` = 322132;

SET @PATH := 322132 * 10;
DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 1350.16100, 721.5967, 35.88817, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 1348.21000, 715.925, 35.11083, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 1345.82000, 708.566, 34.57409, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 1351.31000, 699.536, 34.77248, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 1354.06000, 696.601, 34.87526, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 1357.15000, 689.958, 35.07387, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 1357.43000, 676.587, 34.29592, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 1357.66000, 686.674, 34.77761, NULL, 0, 0, 0, 0, 0),
(@PATH, 9, 1357.15000, 689.958, 35.07387, NULL, 0, 0, 0, 0, 0),
(@PATH, 10, 1354.06000, 696.601, 34.87526, NULL, 0, 0, 0, 0, 0),
(@PATH, 11, 1351.31000, 699.536, 34.77248, NULL, 0, 0, 0, 0, 0),
(@PATH, 12, 1348.87000, 702.816, 34.66368, NULL, 0, 0, 0, 0, 0),
(@PATH, 13, 1345.82000, 708.566, 34.57409, NULL, 0, 0, 0, 0, 0),
(@PATH, 14, 1348.21000, 715.925, 35.11083, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` = 322132;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(322132, @PATH, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

UPDATE `creature` SET `position_x`= 1341.49000, `position_y`= 799.936, `position_z`= 38.71292, `MovementType`= 2 WHERE `guid` = 322142;

SET @PATH := 322142 * 10;
DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 1341.49000, 799.936, 38.71292, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 1339.70000, 804.5, 38.41317, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 1339.83000, 808.889, 38.98666, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 1336.01000, 823.51, 40.24935, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 1339.37000, 817.385, 40.23898, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 1339.83000, 808.889, 38.98666, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 1339.70000, 804.5, 38.41317, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 1341.49000, 799.936, 38.71292, NULL, 0, 0, 0, 0, 0),
(@PATH, 9, 1345.15000, 794.715, 39.35074, NULL, 0, 0, 0, 0, 0),
(@PATH, 10, 1347.98600, 791.8906, 40.28397, NULL, 0, 0, 0, 0, 0),
(@PATH, 11, 1349.11000, 787.653, 40.27603, NULL, 0, 0, 0, 0, 0),
(@PATH, 12, 1345.16400, 794.7012, 39.40897, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` = 322142;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(322142, @PATH, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

UPDATE `creature` SET `position_x`= 1244.41000, `position_y`= 943.512, `position_z`= 36.76421, `MovementType`= 2 WHERE `guid` = 322117;

SET @PATH := 322117 * 10;
DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 1244.41000, 943.512, 36.76421, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 1246.07000, 951.793, 37.05437, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 1241.86000, 960.908, 36.70818, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 1246.07000, 951.793, 37.05437, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 1244.41000, 943.512, 36.76421, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 1247.22000, 934.955, 36.60844, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 1255.40000, 927.849, 37.75205, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 1259.95000, 926.09, 38.88926, NULL, 0, 0, 0, 0, 0),
(@PATH, 9, 1263.57500, 924.3984, 39.92661, NULL, 0, 0, 0, 0, 0),
(@PATH, 10, 1266.38000, 920.392, 39.75181, NULL, 0, 0, 0, 0, 0),
(@PATH, 11, 1267.09000, 914.234, 38.43447, NULL, 0, 0, 0, 0, 0),
(@PATH, 12, 1266.38000, 920.392, 39.75181, NULL, 0, 0, 0, 0, 0),
(@PATH, 13, 1263.70000, 924.342, 39.93174, NULL, 0, 0, 0, 0, 0),
(@PATH, 14, 1260.07500, 926.0332, 38.80161, NULL, 0, 0, 0, 0, 0),
(@PATH, 15, 1255.41200, 927.8447, 37.80161, NULL, 0, 0, 0, 0, 0),
(@PATH, 16, 1247.22000, 934.955, 36.60844, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` = 322117;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(322117, @PATH, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

UPDATE `creature` SET `position_x`= 1118.4019, `position_y`= 1128.5939, `position_z`= 42.3922, `MovementType`= 1 WHERE `guid` = 321943;

-- Forsaken Apothecary
SET @ENTRY := 46483;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 500, 1000, 15000, 30000, 10, 16, 133, 467, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 15 - 30 seconds (0.5 - 1s initially) (OOC) - Self: Play random emote: ONESHOT_KNEEL (16), STATE_USESTANDING_NOSHEATHE (133), ONESHOT_WORK_MINING (467),");

DELETE FROM `creature_template_addon` WHERE `entry`=46483;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(46483, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

-- Worgen Renegade
UPDATE `creature` SET `position_x`= 1118.4019, `position_y`= 1128.5939, `position_z`= 42.3922, `MovementType`= 1 WHERE `guid` = 321945;

UPDATE `creature` SET `MovementType`= 0, `wander_distance`= 0 WHERE `guid` IN (321944, 321946, 321947);

DELETE FROM `creature_addon` WHERE `guid` IN (321944, 321946, 321947);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(321944, 0, 0, 0, 0, 0, 455, 0, 0, 0, 0, ''),
(321946, 0, 0, 0, 0, 0, 455, 0, 0, 0, 0, ''),
(321947, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, '');

-- Bolgaff
UPDATE `creature_template_addon` SET `mount` = 27660 WHERE `entry` = 47003;

-- Rabid Dog
UPDATE `creature` SET `id` = 1797, `MovementType` = 0, `unit_flags` = 768, `wander_distance` = 0 WHERE `guid` = 321854;
UPDATE `creature` SET `MovementType` = 0, `unit_flags` = 768, `wander_distance` = 0 WHERE `guid` = 321855;

DELETE FROM `creature_addon` WHERE `guid` IN (321854, 321855);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(321854, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '80636'),
(321855, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '80636');

-- Giant Rabid Bear
UPDATE `creature` SET `MovementType` = 0, `unit_flags` = 768, `wander_distance` = 0 WHERE `guid` = 321853;

DELETE FROM `creature_addon` WHERE `guid` = 321853;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(321853, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '80636');

-- Gorefang
UPDATE `creature` SET `MovementType` = 1, `wander_distance` = 5 WHERE `guid` = 322260;

-- Snake
UPDATE `creature` SET `MovementType` = 1, `wander_distance` = 5 WHERE `id` = 2914;
