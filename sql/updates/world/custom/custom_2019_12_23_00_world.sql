-- Pathing for  Entry: 35222 'TDB FORMAT' 
SET @NPC := 251597;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8233.455, `position_y`= 1480.944, `position_z`= 40.66653 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 29681, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8233.455, 1480.944, 40.66653, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -8237.281, 1496.12, 40.95306, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8252.676, 1513.839, 42.39288, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8253.342, 1526.059, 42.42412, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8239.639, 1542.602, 40.09546, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8230.052, 1552.523, 37.37603, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8212.354, 1568.214, 31.73001, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8210.224, 1583.332, 32.44701, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8212.531, 1598.168, 32.47481, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -8214.422, 1615.536, 32.92865, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -8214.42, 1635.781, 32.7856, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -8204.966, 1642.373, 31.1757, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -8179.627, 1641.858, 24.55478, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -8162.3, 1640.451, 20.44201, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -8157.21, 1631.747, 19.03548, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -8157.158, 1614.363, 19.06247, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -8157.061, 1597.688, 19.18612, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -8157.382, 1577.392, 19.189, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -8148.551, 1569.641, 17.52326, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -8115.444, 1570.345, 10.37805, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -8101.983, 1578.865, 8.922841, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -8099.21, 1603.134, 8.727924, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -8098.87, 1633.561, 9.007867, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -8108.307, 1641.675, 10.29583, 0, 0, 0, 0, 100, 0),
(@PATH, 25, -8129.188, 1642.641, 13.99003, 0, 0, 0, 0, 100, 0),
(@PATH, 26, -8146.531, 1642.632, 17.22144, 0, 0, 0, 0, 100, 0),
(@PATH, 27, -8177.627, 1642.247, 24.21005, 0, 0, 0, 0, 100, 0),
(@PATH, 28, -8204.576, 1644.285, 30.96981, 0, 0, 0, 0, 100, 0),
(@PATH, 29, -8218.049, 1653.472, 35.63245, 0, 0, 0, 0, 100, 0),
(@PATH, 30, -8228.363, 1668.866, 40.80247, 0, 0, 0, 0, 100, 0),
(@PATH, 31, -8240.214, 1681.243, 44.13697, 0, 0, 0, 0, 100, 0),
(@PATH, 32, -8254.935, 1690.868, 47.42791, 0, 0, 0, 0, 100, 0),
(@PATH, 33, -8267.382, 1687.951, 49.48492, 0, 0, 0, 0, 100, 0),
(@PATH, 34, -8281.208, 1684.418, 50.42019, 0, 0, 0, 0, 100, 0),
(@PATH, 35, -8293.889, 1688.729, 50.96144, 0, 0, 0, 0, 100, 0),
(@PATH, 36, -8305.844, 1685.063, 51.15885, 0, 0, 0, 0, 100, 0),
(@PATH, 37, -8319.908, 1679.288, 51.42967, 0, 0, 0, 0, 100, 0),
(@PATH, 38, -8329.658, 1679.269, 53.93888, 0, 0, 0, 0, 100, 0),
(@PATH, 39, -8343.842, 1676.309, 59.27012, 0, 0, 0, 0, 100, 0),
(@PATH, 40, -8354.016, 1668.293, 63.6382, 0, 0, 0, 0, 100, 0),
(@PATH, 41, -8359.497, 1656.74, 66.98524, 0, 0, 0, 0, 100, 0),
(@PATH, 42, -8360.849, 1641.818, 70.35321, 0, 0, 0, 0, 100, 0),
(@PATH, 43, -8361.453, 1628.172, 72.28253, 0, 0, 0, 0, 100, 0),
(@PATH, 44, -8369.929, 1616.59, 73.11777, 0, 0, 0, 0, 100, 0),
(@PATH, 45, -8382.868, 1611.306, 71.88938, 0, 0, 0, 0, 100, 0),
(@PATH, 46, -8404.38, 1609.531, 72.62751, 0, 0, 0, 0, 100, 0),
(@PATH, 47, -8419.185, 1605.875, 69.93181, 0, 0, 0, 0, 100, 0),
(@PATH, 48, -8430.29, 1598.693, 65.64894, 0, 0, 0, 0, 100, 0),
(@PATH, 49, -8433.799, 1583.304, 62.93398, 0, 0, 0, 0, 100, 0),
(@PATH, 50, -8426.707, 1571.021, 62.11591, 0, 0, 0, 0, 100, 0),
(@PATH, 51, -8415.888, 1564.595, 62.94149, 0, 0, 0, 0, 100, 0),
(@PATH, 52, -8403.188, 1562.898, 63.33728, 0, 0, 0, 0, 100, 0),
(@PATH, 53, -8390.013, 1561.646, 62.19341, 0, 0, 0, 0, 100, 0),
(@PATH, 54, -8375.259, 1555.483, 60.82091, 0, 0, 0, 0, 100, 0),
(@PATH, 55, -8364.721, 1543.839, 60.14793, 0, 0, 0, 0, 100, 0),
(@PATH, 56, -8353.77, 1533.451, 55.55624, 0, 0, 0, 0, 100, 0),
(@PATH, 57, -8338.031, 1520.948, 48.7411, 0, 0, 0, 0, 100, 0),
(@PATH, 58, -8317.601, 1507.241, 46.77857, 0, 0, 0, 0, 100, 0),
(@PATH, 59, -8313.639, 1495.793, 46.00465, 0, 0, 0, 0, 100, 0),
(@PATH, 60, -8310.938, 1477.773, 45.44294, 0, 0, 0, 0, 100, 0),
(@PATH, 61, -8305.391, 1465.811, 44.83179, 0, 0, 0, 0, 100, 0),
(@PATH, 62, -8292.056, 1452.323, 43.01766, 0, 0, 0, 0, 100, 0),
(@PATH, 63, -8270.036, 1446.597, 40.38112, 0, 0, 0, 0, 100, 0),
(@PATH, 64, -8252.078, 1450.355, 40.64065, 0, 0, 0, 0, 100, 0),
(@PATH, 65, -8238.17, 1462.04, 40.783, 0, 0, 0, 0, 100, 0);
-- 0x2030945100226580006D240001FF1553 .go xyz -8233.455 1480.944 40.66653

DELETE FROM `creature_text` WHERE `CreatureID`= 35222;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(35222, 0, 0, 'Is that you, $n? What are you doing away from headquarters? Get back to work!', 14, 0, 100, 5, 0, 19546, 37243, 'Trade Prince Gallywix to Player'),
(35222, 0, 1, 'Drink Kaja\'Cola!', 14, 0, 100, 5, 0, 19549, 37246, 'Trade Prince Gallywix to Player'),
(35222, 0, 2, 'What\'s this I hear about a party? I wasn\'t invited!', 14, 0, 100, 6, 0, 19543, 37240, 'Trade Prince Gallywix to Player'),
(35222, 0, 3, 'You\'re all lazy! Get back to work. Especially you, $n!', 14, 0, 100, 25, 0, 19544, 37241, 'Trade Prince Gallywix to Player'),
(35222, 0, 4, 'All hail the greatest trade prince on Azeroth... me!', 14, 0, 100, 1, 0, 19547, 37244, 'Trade Prince Gallywix to Player'),
(35222, 0, 5, 'Thank you for your hard work and dedication. Unpaid overtime is approved for all!', 14, 0, 100, 1, 0, 19548, 37245, 'Trade Prince Gallywix to Player'),
(35222, 0, 6, 'It\'s demotions for everyone if the Sharks beat the Buccaneers!', 14, 0, 100, 1, 0, 19545, 37242, 'Trade Prince Gallywix to Player');

-- Creature Trade Prince Gallywix 35222 SAI
SET @ENTRY := 35222;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 35000, 60000, 35000, 60000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 35000 and 60000 ms (and later repeats every 35000 and 60000 ms) - Self: Talk 0 // ");
