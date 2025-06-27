--
SET @CGUID := 144155; -- 80 free guid set by TC
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+79;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 30136, 571, 1, 2, 7443.688, -997.967, 791.5563, 5.77704, 0, 0, 0),
(@CGUID+1, 30136, 571, 1, 2, 7464.026, -982.6368, 796.7954, 5.445427, 0, 0, 0),
(@CGUID+2, 30136, 571, 1, 2, 7439.698, -1004.994, 791.5581, 5.88176, 0, 0, 0),
(@CGUID+3, 30136, 571, 1, 2, 7432.88, -996.9908, 538.754, 5.8294, 0, 0, 0),
(@CGUID+4, 30136, 571, 1, 2, 7440.099, -971.4941, 596.7019, 5.5676, 0, 0, 0),
(@CGUID+5, 30136, 571, 1, 2, 7443.239, -957.6465, 704.6074, 5.445427, 0, 0, 0),
(@CGUID+6, 30136, 571, 1, 2, 7436.259, -995.6957, 538.7682, 5.794493, 0, 0, 0),
(@CGUID+7, 30136, 571, 1, 2, 7453.724, -975.0106, 538.7589, 5.480334, 0, 0, 0),
(@CGUID+8, 30136, 571, 1, 2, 7453.564, -978.4579, 538.7731, 5.51524, 0, 0, 0),
(@CGUID+9, 30136, 571, 1, 2, 7432.952, -993.7203, 594.6988, 5.794493, 0, 0, 0),
(@CGUID+10, 30136, 571, 1, 2, 7470.03, -953.4771, 538.7057, 5.183628, 0, 0, 0),
(@CGUID+11, 30136, 571, 1, 2, 7509.529, -942.8323, 596.5732, 4.747295, 0, 0, 0),
(@CGUID+12, 30136, 571, 1, 2, 7512.031, -952.4295, 793.3883, 4.729842, 0, 0, 0),
(@CGUID+13, 30136, 571, 1, 2, 7522.184, -944.5262, 538.7827, 4.590216, 0, 0, 0),
(@CGUID+14, 30136, 571, 1, 2, 7567.444, -977.0383, 595.8424, 3.944444, 0, 0, 0),
(@CGUID+15, 30136, 571, 1, 2, 7587.854, -1034.644, 711.9574, 3.159046, 0, 0, 0),
(@CGUID+16, 30136, 571, 1, 2, 7496.645, -940.393, 538.7007, 4.886922, 0, 0, 0),
(@CGUID+17, 30136, 571, 1, 2, 7530.056, -967.2031, 689.8135, 4.45059, 0, 0, 0),
(@CGUID+18, 30136, 571, 1, 2, 7536.476, -957.3798, 594.0485, 4.39823, 0, 0, 0),
(@CGUID+19, 30136, 571, 1, 2, 7518.525, -943.5374, 538.7671, 4.642576, 0, 0, 0),
(@CGUID+20, 30136, 571, 1, 2, 7524.424, -965.8981, 688.9619, 4.537856, 0, 0, 0),
(@CGUID+21, 30136, 571, 1, 2, 7480.429, -1015.052, 738.4304, 5.707227, 0, 0, 0),
(@CGUID+22, 30136, 571, 1, 2, 7562.215, -946.9121, 816.2698, 4.18879, 0, 0, 0),
(@CGUID+23, 30136, 571, 1, 2, 7493.477, -944.535, 596.1667, 4.921828, 0, 0, 0),
(@CGUID+24, 30136, 571, 1, 2, 7594.04, -1016.391, 710.2169, 3.368485, 0, 0, 0),
(@CGUID+25, 30136, 571, 1, 2, 7561.688, -985.4562, 696.1497, 3.926991, 0, 0, 0),
(@CGUID+26, 30493, 571, 1, 2, 7258.688, -865.7031, 924.9865, 5.602507, 0, 0, 0),
(@CGUID+27, 30502, 571, 1, 2, 7246.357, -866.1553, 924.8257, 0.03490658, 0, 0, 0),
(@CGUID+28, 30502, 571, 1, 2, 7329.806, -1027.244, 908.9823, 1.902409, 0, 0, 0),
(@CGUID+29, 30502, 571, 1, 2, 7258.124, -851.6719, 926.1149, 4.869469, 0, 0, 0),
(@CGUID+30, 30502, 571, 1, 2, 7379.61, -910.0995, 908.1426, 2.670354, 0, 0, 0),
(@CGUID+31, 30502, 571, 1, 2, 7360.499, -1137.121, 907.58, 1.937315, 0, 0, 0),
(@CGUID+32, 30502, 571, 1, 2, 7518.664, -1240.335, 913.9808, 3.822271, 0, 0, 0),
(@CGUID+33, 30502, 571, 1, 2, 7369.898, -1214.435, 904.9849, 0.2268928, 0, 0, 0),
(@CGUID+34, 30502, 571, 1, 2, 7283.155, -1084.717, 939.2233, 1.762783, 0, 0, 0),
(@CGUID+35, 30502, 571, 1, 2, 7451.647, -843.4373, 917.2958, 3.246312, 0, 0, 0),
(@CGUID+36, 30502, 571, 1, 2, 7261.373, -1013.67, 918.5519, 1.413717, 0, 0, 0),
(@CGUID+37, 30502, 571, 1, 2, 7606.527, -1225.569, 929.4883, 4.29351, 0, 0, 0),
(@CGUID+38, 30502, 571, 1, 2, 7554.601, -1320.671, 930.3687, 4.660029, 0, 0, 0),
(@CGUID+39, 30502, 571, 1, 2, 7430.659, -1318.579, 911.7595, 4.468043, 0, 0, 0),
(@CGUID+40, 30502, 571, 1, 2, 7283.702, -1305.297, 909.7721, 5.88176, 0, 0, 0),
(@CGUID+41, 30064, 571, 1, 2, 7260.882, -1363.916, 911.7665, 0.4014257, 0, 0, 0),
(@CGUID+42, 30064, 571, 1, 2, 7294.543, -1239.342, 910.2243, 6.126106, 0, 0, 0),
(@CGUID+43, 30064, 571, 1, 2, 7447.73, -1222.154, 906.4549, 3.979351, 0, 0, 0),
(@CGUID+44, 30064, 571, 1, 2, 7021.103, -1281.485, 925.2195, 5.751715, 0, 0, 0),
(@CGUID+45, 30064, 571, 1, 2, 7366.789, -921.5516, 908.176, 1.151917, 0, 0, 0),
(@CGUID+46, 30064, 571, 1, 2, 7366.549, -1167.878, 907.7737, 4.276057, 0, 0, 0),
(@CGUID+47, 30064, 571, 1, 2, 7266.572, -1061.63, 941.623, 3.45743, 0, 0, 0),
(@CGUID+48, 30064, 571, 1, 2, 7274.531, -973.0413, 919.6902, 3.892084, 0, 0, 0),
(@CGUID+49, 30064, 571, 1, 2, 7344.521, -1002.784, 907.9092, 1.370535, 0, 0, 0),
(@CGUID+50, 30504, 571, 1, 2, 7264.177, -1064.293, 941.6094, 1.58825, 0, 0, 0),
(@CGUID+51, 30504, 571, 1, 2, 7261.539, -1060.268, 942.1428, 1.58825, 0, 0, 0),
(@CGUID+52, 30504, 571, 1, 2, 7258.846, -1064.966, 941.6843, 1.570796, 0, 0, 0),
(@CGUID+53, 30504, 571, 1, 2, 7285.515, -995.3761, 915.2917, 1.780236, 0, 0, 0),
(@CGUID+54, 30504, 571, 1, 2, 7291.571, -993.6209, 915.0613, 1.832596, 0, 0, 0),
(@CGUID+55, 30504, 571, 1, 2, 7284.015, -942.5671, 919.7255, 1.884956, 0, 0, 0),
(@CGUID+56, 30504, 571, 1, 2, 7295.979, -986.884, 915.3113, 1.867502, 0, 0, 0),
(@CGUID+57, 30504, 571, 1, 2, 7297.396, -992.0636, 914.5924, 1.867502, 0, 0, 0),
(@CGUID+58, 30504, 571, 1, 2, 7290.535, -988.4466, 915.6047, 1.832596, 0, 0, 0),
(@CGUID+59, 30504, 571, 1, 2, 7288.845, -939.8006, 919.2185, 1.954769, 0, 0, 0),
(@CGUID+60, 30504, 571, 1, 2, 7284.822, -936.735, 920.152, 1.919862, 0, 0, 0),
(@CGUID+61, 30504, 571, 1, 2, 7284.391, -990.1196, 915.7115, 1.780236, 0, 0, 0),
(@CGUID+62, 30504, 571, 1, 2, 7347.897, -934.4936, 908.6702, 2.478368, 0, 0, 0),
(@CGUID+63, 30504, 571, 1, 2, 7352.746, -928.9537, 908.5024, 2.548181, 0, 0, 0),
(@CGUID+64, 30504, 571, 1, 2, 7345.77, -927.7479, 909.7731, 2.513274, 0, 0, 0),
(@CGUID+65, 30504, 571, 1, 2, 7278.971, -906.7933, 926.6701, 2.042035, 0, 0, 0),
(@CGUID+66, 30504, 571, 1, 2, 7328.465, -894.0953, 920.5985, 2.75762, 0, 0, 0),
(@CGUID+67, 30504, 571, 1, 2, 7271.211, -905.6917, 927.1619, 1.902409, 0, 0, 0),
(@CGUID+68, 30504, 571, 1, 2, 7326.755, -908.373, 917.7892, 2.583087, 0, 0, 0),
(@CGUID+69, 30504, 571, 1, 2, 7330.237, -902.4053, 918.4761, 2.670354, 0, 0, 0),
(@CGUID+70, 30504, 571, 1, 2, 7281.855, -898.8499, 926.4277, 2.199115, 0, 0, 0),
(@CGUID+71, 30504, 571, 1, 2, 7284.128, -903.6423, 926.1991, 2.181662, 0, 0, 0),
(@CGUID+72, 30504, 571, 1, 2, 7273.202, -910.2079, 927.0142, 1.902409, 0, 0, 0),
(@CGUID+73, 30504, 571, 1, 2, 7321.779, -905.3262, 919.6216, 2.583087, 0, 0, 0),
(@CGUID+74, 30504, 571, 1, 2, 7276.896, -902.2155, 926.9134, 2.059489, 0, 0, 0),
(@CGUID+75, 30504, 571, 1, 2, 7333.466, -896.3923, 918.7648, 2.75762, 0, 0, 0),
(@CGUID+76, 30382, 571, 1, 1, 7525.702, -971.7235, 478.799, 5.637414, 0, 0, 0),
(@CGUID+77, 30383, 571, 1, 1, 7515.811, -975.2843, 467.4983, 3.857178, 0, 0, 0),
(@CGUID+78, 30401, 571, 1, 1, 6647.1733, -310.2567, 989.5303, 1.2511, 0, 0, 0),
(@CGUID+79, 30504, 571, 1, 2, 7325.687, -899.111, 920.3403, 2.758484, 0, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry`=30493;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(30493, 0, 0, 0, 0, 0, '29266');

DELETE FROM `creature_addon` WHERE `guid`=@CGUID+78;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@CGUID+78, 0, 0, 0, 0, 0, '54503'); -- quest invisibility

DELETE FROM `spell_area` WHERE `spell`=55782 AND `area`=4432;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(55782, 4432, 12973, 0, 0, 0, 2, 1, 74, 0);

DELETE FROM `spell_area` WHERE `spell`=54504 AND `area`=4428;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(54504, 4428, 12973, 0, 0, 0, 2, 1, 10, 0);

SET @Brann          := 30107; 
SET @Brann1         := 30382; -- Brann   60888 cosmetic movement
SET @Brann2         := 30405;
SET @Machine        := 30134; -- Machine
SET @Soldier        := 30136; -- Stormforged Soldier  
Set @Yorg           := 30408; -- Yorg Stormheart spell to summon=56676
Set @Magni          := 30411; -- Magni Bronzebeard spell to summon=56697
SET @SPELL1         := 56603;
SET @Machine2       := 30383; -- Machine static

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Soldier AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Brann1 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Brann1*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Brann2 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Brann2*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Brann AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Brann*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Brann*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Machine AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Machine*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Machine2 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Yorg AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Yorg*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Yorg*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Magni AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Magni*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Magni*100+1 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Brann1, 0, 0, 0, 19, 0, 100, 0, 12973, 0, 0, 0, 80, @Brann1*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brann - On Quest Accept - action list'),
(@Brann1*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 56558, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brann - action liste - cast spell to invoque'),
(@brann1*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Machine2, 20, 0, 0, 0, 0, 0, 'Brann  - On ActionList - despawn'),
(@brann1*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 44, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Brann  - On ActionList - Set phase 3'),
(@brann1*100, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brann  - On ActionList - despawn'),
(@Brann1, 0, 1, 0, 1, 0, 100, 0, 4000, 4000, 4000, 7000, 11, 60888, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brann - Ooc - Cast cosmetic movement'),
(@Machine, 0, 16, 0, 63, 0, 100, 0, 0, 0, 0, 0, 44, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Just created - Set phase 3'),
(@Machine, 0, 0, 0, 27, 0, 100, 0, 0, 0, 0, 0, 80, @Machine*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On passeger boarded - action list'),
(@Machine*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 1, @Machine, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - action list - start wp'),
(@Machine*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 19, @Brann, 10, 0, 0, 0, 0, 0, 'Brann - On Script - Set React Passive'),
(@Machine*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On Script - Set React Passive'), 
(@Machine*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 131072, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On Script - set PACIFIED'),
(@Soldier, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 4000, 4000, 11, 56621, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0,0,'Stormforged Soldier - In Combat - Cast Thunder Orb'),
(@Machine, 0, 1, 0, 40, 0, 100, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @brann, 10, 0, 0, 0, 0, 0, 'Machine - On waypoint - talk'),
(@Machine, 0, 2, 0, 40, 0, 100, 0, 4, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @brann, 10, 0, 0, 0, 0, 0, 'Machine - On waypoint - talk'),
(@Machine, 0, 3, 0, 40, 0, 100, 0, 7, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @brann, 10, 0, 0, 0, 0, 0, 'Machine - On waypoint - talk'),
(@Machine, 0, 4, 0, 40, 0, 100, 0, 22, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @brann, 10, 0, 0, 0, 0, 0, 'Machine - On waypoint - talk'),
(@Machine, 0, 5, 0, 40, 0, 100, 0, 27, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, @brann, 10, 0, 0, 0, 0, 0, 'Machine - On waypoint - talk'),
(@Machine, 0, 6, 0, 40, 0, 100, 0, 31, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, @brann, 10, 0, 0, 0, 0, 0, 'Machine - On waypoint - talk'),
(@Machine, 0, 7, 0, 40, 0, 100, 0, 35, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, @brann, 10, 0, 0, 0, 0, 0, 'Machine - On waypoint - talk'),
(@Machine, 0, 8, 0, 40, 0, 100, 0, 36, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, @brann, 10, 0, 0, 0, 0, 0, 'Machine - On waypoint - talk'),
(@Machine, 0, 9, 0, 40, 0, 100, 0, 41, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 19, @brann, 10, 0, 0, 0, 0, 0, 'Machine - On waypoint - talk'),
(@Machine, 0, 10, 11, 40, 0, 100, 0, 42, 0, 0, 0, 11, 68576, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On waypoint - Eject passengenrs'),
(@Machine, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 85, 56675, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 'Machine - On waypoint - Invoker cast to Spawn Brann'),
(@Machine, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine  - On waypoint - Despawn'),
(@Machine, 0, 13, 0, 1, 0, 100, 0, 3000, 3000, 3000, 3000, 86, 56622, 1, 9, @Soldier, 5, 50, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine  - OOC - CROSSCAST'),
(@Machine, 0, 14, 0, 1, 0, 100, 0, 3000, 3000, 3000, 3000, 86, 55089, 1, 19, @Soldier, 40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - OOC - CROSSCAST'),
(@brann2, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - Just created - Remove npcflag'),
(@brann2, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @brann2*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - Has aura - action list'),
(@brann2*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - set run off'),
(@brann2*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6696.584473, -301.435760, 989.392761, 3.094404, 'brann - ActionList - move to pos'),
(@brann2*100, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 11, 56676, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList- spawn Yorg'),
(@brann2*100, 9, 3, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 4, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 5, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 7, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 8, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 9, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 11, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 12, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 13, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 56697, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - spawn Magni'),
(@brann2*100, 9, 15, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 16, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 66, 2.662433, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6696.584473, -301.435760, 989.392761, 2.662433, 'brann - ActionList - Set orientation'),
(@brann2*100, 9, 17, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 18, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Magni, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 19, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 20, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Magni, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 21, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 22, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 9, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 23, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, @Magni, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 24, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, @Magni, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 25, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 10, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 26, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 27, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 11, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 28, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, @Magni, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 29, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 12, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 30, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, @Magni, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 31, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 32, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 13, 0, 0, 0, 0, 0, 19, @Yorg, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 33, 0, 0, 0, 100, 0, 0, 0, 0, 0, 75, 71385, 0, 0, 0, 0, 0, 11, @Yorg, 20, 0, 0, 0, 0, 0, 'brann - ActionList - add aura'),
(@brann2*100, 9, 34, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 19, @Magni, 10, 0, 0, 0, 0, 0, 'brann - ActionList - talk'),
(@brann2*100, 9, 35, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 75, 71385, 0, 0, 0, 0, 0, 11, @Magni, 20, 0, 0, 0, 0, 0, 'brann - ActionList - add aura'),  
(@brann2*100, 9, 36, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 56742, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'brann - ActionList - Cast credit spell'),
(@brann2*100, 9, 37, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6740.549316, -293.961212, 993.427979, 3.559861, 'brann - ActionList - move to pos'),
(@brann2*100, 9, 38, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brann  - On ActionList - despawn'),
(@Yorg, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Yorg*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Yorg - On spawn - ActionList'),
(@Yorg*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Yorg - ActionList - set run off'),
(@Yorg*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6692.118164, -301.678192, 989.427734, 6.194374, 'Yorg - ActionList - go to pos'),
(@Yorg*100, 9, 2, 0, 0, 0, 100, 0, 90000, 90000, 0, 0, 66, 0.579558, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6692.118164, -301.678192, 989.427734, 0.579558, 'Yorg - ActionList - Set orientation'),
(@Yorg, 0, 1, 0, 23, 0, 100, 1, 71385, 1, 0, 0, 80, @Yorg*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Yorg - call timed actionlist when has aura'),
(@Yorg*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6608.733887, -282.180756, 986.123230, 3.491027, 'Yorg - ActionList - move to pos'),
(@Yorg*100+1, 9, 1, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Yorg  - ActionList - despawn'),
(@Magni, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Magni*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magni - On Spawn - ActionList'),
(@Magni*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6694.134766, -297.678925, 989.207092, 4.757878, 'Magni - ActionList - Go to pos'),
(@Magni*100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magni - ActionList - talk'),
(@Magni*100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magni - ActionList - talk'),
(@Magni*100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 66, 4.757878, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6694.134766, -297.678925, 989.207092, 4.757878, 'Magni - ActionList - Set orientation'),
(@Magni, 0, 1, 0, 23, 0, 100, 1, 71385, 1, 0, 0, 80, @Magni*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magni - call timed actionlist when has aura'),
(@Magni*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magni - ActionList - Set run off'),
(@Magni*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6740.549316, -293.961212, 993.427979, 3.559861, 'Magni - ActionList - Go to pos'),
(@Magni*100+1, 9, 2, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magni  - ActionList - despawn');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`in (@Brann, @Brann1, @Brann2, @Magni, @Yorg, @Machine, @Machine2);
UPDATE `creature_template` SET `faction`=2102, `AIName`='SmartAI' WHERE `entry`=@Soldier;
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `type_flags`=2048, `speed_run`=2.14, `VehicleId`=219, `InhabitType`=4, `RegenHealth`=0 WHERE `entry`=@Machine;
UPDATE `creature_template` SET `unit_flags`=537166144, `dynamicflags`=32 WHERE  `entry`=30493;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56621;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,56621,0,0,31,0,3,@Soldier,0,1,0,0,'','Only the Machine is a target for the spell.');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56622;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,56622,0,0,31,0,3,@Soldier,0,1,0,0,'','Only the Machine is a target for the spell.');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@Machine;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@Machine,0,0,9,0,12973,0,0,0,0,'','Vehicle flying machine require quest 12973');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=55089;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,55089,0,0,31,0,3,@Machine,0,0,0,0,'','Only the flying machine is a target for the spell.');

DELETE FROM `vehicle_template_accessory` where `entry`= @Machine;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)
VALUES(@Machine,@Brann,0,1,'Brann flying machine',8,0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = @Machine;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@Machine, 43671, 1, 1),
(@Machine, @SPELL1, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry` IN  (@SPELL1, 43671);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,@Machine,@SPELL1,0,0,9,0,12973,0,0,0,0,'','Required quest active for spellclick'),
(18,@Machine,43671,0,0,31,0,3,0,0,0,0,'','Only npc for spellclick');

DELETE FROM `spell_target_position` WHERE `id`=56558; 
INSERT INTO `spell_target_position` (`id`,`mapid`,`positionx`,`positiony`,`positionz`,`orientation`) VALUES
(56558, 571, 7515.810059, -975.283997, 478.508027, 3.883507);
DELETE FROM `spell_target_position` WHERE `id`=56676;
INSERT INTO `spell_target_position` (`id`,`mapid`,`positionx`,`positiony`,`positionz`,`orientation`) VALUES
(56676, 571, 6668.243164, -300.716309, 989.048035, 0.049131);  
DELETE FROM `spell_target_position` WHERE `id`=56697;
INSERT INTO `spell_target_position` (`id`,`mapid`,`positionx`,`positiony`,`positionz`,`orientation`) VALUES
(56697, 571, 6646.655762, -292.56268, 982.318909, 6.077349); 

DELETE FROM `waypoints` WHERE entry=@Machine;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Machine,1,7482.256, -1010.183, 480.4727,'Brann flying machine'),
(@Machine,2,7487.624, -1073.279, 486.6947,'Brann flying machine'),
(@Machine,3,7554.068, -1073.744, 504.4724,'Brann flying machine'),
(@Machine,4,7540.521, -994.4729, 521.6666,'Brann flying machine'),
(@Machine,5,7476.892, -979.5384, 539.4715,'Brann flying machine'),
(@Machine,6,7441.698, -1035.954, 552.1108,'Brann flying machine'),
(@Machine,7,7471.937, -1091.025, 565.5829,'Brann flying machine'),
(@Machine,8,7510.604, -1098.736, 585.0275,'Brann flying machine'),
(@Machine,9,7560.741, -1064.01, 596.1101,'Brann flying machine'),
(@Machine,10,7558.652, -991.4143, 606.4708,'Brann flying machine'),
(@Machine,11,7481.208, -966.8239, 614.276,'Brann flying machine'),
(@Machine,12,7430.998, -1039.164, 622.7203,'Brann flying machine'),
(@Machine,13,7464.418, -1092.93, 634.8871,'Brann flying machine'),
(@Machine,14,7535.688, -1088.016, 651.7204,'Brann flying machine'),
(@Machine,15,7563.452, -1036.534, 661.0538,'Brann flying machine'),
(@Machine,16,7516.293, -977.355, 676.6924,'Brann flying machine'),
(@Machine,17,7455.716, -999.9194, 689.1921,'Brann flying machine'),
(@Machine,18,7447.983, -1050.863, 710.22,'Brann flying machine'),
(@Machine,19,7518.54, -1090.449, 733.2756,'Brann flying machine'),
(@Machine,20,7565.333, -1038.004, 745.6921,'Brann flying machine'),
(@Machine,21,7532.994, -979.3826, 757.9145,'Brann flying machine'),
(@Machine,22,7434.272, -1013.309, 756.1094,'Brann flying machine'),
(@Machine,23,7460.686, -1081.453, 775.8036,'Brann flying machine'),
(@Machine,24,7518.524, -1091.506, 800.887,'Brann flying machine'),
(@Machine,25,7563.83, -1015.821, 824.6927,'Brann flying machine'),
(@Machine,26,7485.566, -970.3575, 842.8317,'Brann flying machine'),
(@Machine,27,7446.667, -1061.756, 867.8871,'Brann flying machine'),
(@Machine,28,7479.346, -1108.014, 896.2759,'Brann flying machine'),
(@Machine,29,7534.174, -1115.574, 932.2327,'Brann flying machine'),
(@Machine,30,7583.952, -1166.912, 949.7326,'Brann flying machine'),
(@Machine,31,7569.052, -1238.047, 949.7327,'Brann flying machine'),
(@Machine,32,7505.558, -1260.738, 959.0381,'Brann flying machine'),
(@Machine,33,7425.231, -1227.18, 965.1213,'Brann flying machine'),
(@Machine,34,7358.262, -1154.908, 965.1213,'Brann flying machine'),
(@Machine,35,7316.554, -1004.713, 969.5936,'Brann flying machine'),
(@Machine,36,7273.263, -897.3846, 973.7048,'Brann flying machine'),
(@Machine,37,7216.268, -811.6398, 984.3438,'Brann flying machine'),
(@Machine,38,7148.946, -634.7748, 984.3438,'Brann flying machine'),
(@Machine,39,7051.731, -506.0969, 984.3438,'Brann flying machine'),
(@Machine,40,6928.087, -372.7923, 1013.677,'Brann flying machine'),
(@Machine,41,6820.645, -310.3642, 1017.538,'Brann flying machine'),
(@Machine,42,6741.966, -291.7396, 996.2623,'Brann flying machine'); 

DELETE FROM `creature_text` WHERE `entry` IN (@Brann, @Yorg, @Magni, @Brann2) ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Brann, 0, 0, 'I can''t thank you enough for all of your help in putting together the keystone. Great things will come of this, I assure you.', 12, 0, 100, 0, 0, 0, 'Brann', 31023),
(@Brann, 1, 0, 'Iron dwarves... everywhere.... they''re making their way down from the top. They certainly are persistent.', 12, 0, 100, 0, 0, 0, 'Brann', 31024),
(@Brann, 2, 0, 'They''re trying to take down the plane! I can''t pull up any steeper... you need to keep them off of us!', 12, 0, 100, 0, 0, 0, 'Brann', 31025),
(@Brann, 3, 0, 'There are more just ahead - keep at it!', 12, 0, 100, 0, 0, 0, 'Brann', 31026),
(@Brann, 4, 0, 'We''re almost out... just a little bit further.', 12, 0, 100, 0, 0, 0, 'Brann', 31027),
(@Brann, 5, 0, 'Barring stray boulders from those giants, we should be clear... it seems a mess from down there though.', 12, 0, 100, 0, 0, 0, 'Brann', 31028),
(@Brann, 6, 0, 'Their numbers are unbelievable... I''m glad to hear King Stormheart came to your aid. I only hear good things of him - I think it''s high time we meet.', 12, 0, 100, 0, 0, 0, 'Brann', 31029),
(@Brann, 7, 0, 'Poor Creteus. He was a good keeper... I''m glad he at least got to see his task to completion, I imagine that''s all that really mattered to him.', 12, 0, 100, 0, 0, 0, 'Brann', 31030),
(@Brann, 8, 0, 'We''re coming up on Frosthold. I would be very appreciative if you would introduce me to King Stormeheart before you go. I believe we are both very much in his debt.', 12, 0, 100, 0, 0, 0, 'Brann', 31031),
(@Brann2, 0, 0, 'By all the gods... it can''t be... Muradin?', 12, 0, 100, 0, 0, 0, 'Brann', 31032),
(@Brann2, 1, 0, 'Come on boy, there''s no mistak''n it - it''s definately you. Don''t ya recognize your younger brother?', 12, 0, 100, 0, 0, 0, 'Brann', 31033),
(@Brann2, 2, 0, 'I can''t believe this! You were dead! All accounts said so... what happened, Muradin. How did you get here?', 12, 0, 100, 0, 0, 0, 'Brann', 31034),
(@Brann2, 3, 0, 'Indeed! Magni will be so happy to see you too! He''s gotten nothing but bad news for a long time now, but this changes everything!', 12, 0, 100, 0, 0, 0, 'Brann', 31035),
(@Brann2, 4, 0, 'He''s here in Northrend, brother, looking for you. A seer in Wintergarde brought word that you were not dead, and he left Ironforge immediately to come find you.', 12, 0, 100, 0, 0, 0, 'Brann', 31036),
(@Brann2, 5, 0, 'Speaking of which...', 12, 0, 100, 0, 0, 0, 'Brann', 31087),
(@Brann2, 6, 0, 'That''s in the past, Muradin. Regrets won''t change anything.', 12, 0, 100, 0, 0, 0, 'Brann', 31096),
(@Brann2, 7, 0, 'Aye, be safe Muradin. I''d join you, but I''m on top of the most amazing discovery the world has yet seen. I can''t abandon it now.', 12, 0, 100, 0, 0, 0, 'Brann', 31102),
(@Yorg, 0, 0, 'What''s that? You talkin'' to me, lad?', 12, 0, 100, 0, 0, 0, 'Yorg', 31037),
(@Yorg, 1, 0, 'My brother... yes... I do have brothers...', 12, 0, 100, 0, 0, 0, 'Yorg', 31038),
(@Yorg, 2, 0, 'Muradin clutches his head and reels for a moment as the memories rush back to him.', 16, 0, 100, 0, 0, 0, 'Yorg', 31039),
(@Yorg, 3, 0, '...Brann?', 12, 0, 100, 0, 0, 0, 'Yorg', 31040),
(@Yorg, 4, 0, 'I... I dunno, Brann. I''ve been ''ere a long time... all I ''ave of me life before this place are flashes and nightmares.', 12, 0, 100, 0, 0, 0, 'Yorg', 31042),
(@Yorg, 5, 0, 'It''s good te see you though, brother. More than words can say.', 12, 0, 100, 0, 0, 0, 'Yorg', 31043),
(@Yorg, 6, 0, 'Magn! Forgive me, the memories are comin'' back slowly, brother.', 12, 0, 100, 0, 0, 0, 'Yorg', 31045),
(@Yorg, 7, 0, 'The frostborn have been very good to me. They''re strong people.', 12, 0, 100, 0, 0, 0, 'Yorg', 31048),
(@Yorg, 8, 0, 'Not much, Magni. I''ve had nightmares of a human... tall... light hair... death black armor. His name rests on the tip of me tongue, but...', 12, 0, 100, 0, 0, 0, 'Yorg', 31089),
(@Yorg, 9, 0, '...Arthas.', 12, 0, 100, 0, 0, 0, 'Yorg', 31091),
(@Yorg, 10, 0, 'Aye, I know. I watched him turn... I watched him give up all that was right and I didn''t lift a hand... I didn''t even consider it until it was too late.', 12, 0, 100, 0, 0, 0, 'Yorg', 31094),
(@Yorg, 11, 0, 'No... no they won''t. But I can make this right. I have te. I''m goin'' after the boy. I''ll make''m answer for everything he''s done.', 12, 0, 100, 0, 0, 0, 'Yorg', 31097),
(@Yorg, 12, 0, 'I''m sure, Magni. I''ll see this through, don''t ya worry.', 12, 0, 100, 0, 0, 0, 'Yorg', 31100),
(@Yorg, 13, 0, 'Go Brann. Bring back an epic tale when we meet again. Farewell for now, brothers...', 12, 0, 100, 0, 0, 0, 'Yorg', 31103),
(@Magni, 0, 0, 'Look, Lagnus, I consider you a capable man, but my patience is wearing thin. I know that Muradin is here, can you point me to him or not?', 14, 0, 100, 0, 0, 0, 'Magni', 31084),
(@Magni, 1, 0, 'Brother! There you are! I can barely believe my eyes... you''re alive!', 14, 0, 100, 0, 0, 0, 'Magni', 31085),
(@Magni, 2, 0, 'It''s so good to see you again, Muradin. And what''s this I heard about you being a King in your own right now? The Bronzebeards were always destined to greatness.', 12, 0, 100, 0, 0, 0, 'Magni', 31086),
(@Magni, 3, 0, 'So it seems! And you haven''t lost any muscle yourself. Do you remember anything of what happened, Muradin? Fate as turned ill in your absence.', 12, 0, 100, 0, 0, 0, 'Magni', 31088),
(@Magni, 4, 0, 'Magni nods.', 16, 0, 100, 0, 0, 0, 'Magni', 31092),
(@Magni, 5, 0, 'He''s not the boy of your memories anymore, Muradin. He''s become something else entirely.', 12, 0, 100, 0, 0, 0, 'Magni', 31093),
(@Magni, 6, 0, 'Are you sure Muradin? I just got you back after years of thinking you were dead. I do not want to lose you again.', 12, 0, 100, 0, 0, 0, 'Magni', 31099),
(@Magni, 7, 0, 'So be it then. I have to return to my people, brothers. Come back to me in one piece.', 12, 0, 100, 0, 0, 0, 'Magni', 31101),
(@Magni, 8, 0, '...farewell brother.', 12, 0, 100, 0, 0, 0, 'Magni', 31129);

UPDATE `gameobject` SET `phaseMask`=7 WHERE id=195308;
