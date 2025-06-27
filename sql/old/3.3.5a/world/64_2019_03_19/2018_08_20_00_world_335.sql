-- Suntara Stones
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (8284,8338,8337);
UPDATE `creature_addon` SET `bytes1`= 0 WHERE `guid`= 6823;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (147516,147517);
UPDATE `gameobject` SET `spawntimesecs`=100 WHERE `id` IN (147516, 147517);
DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id`=175704);
DELETE FROM `gameobject` WHERE `id`=175704;

DELETE FROM `smart_scripts` WHERE `entryorguid`IN (828400,828401,828402,828403,828404,828405, 833800, 14751700) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (8337,8284,8338) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (147516,147517) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)  VALUES
(8284, 0, 0,1, 11, 0,100,0, 0, 0,0,0, 18, 768, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On Spawn - Add Unit Flag'),
(8284, 0, 1,0, 61, 0,100,0, 0, 0,0,0, 90, 7, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On Spawn - Add Bytes1 death State'),
(8284, 0, 2,3, 19, 0,100,0, 3367, 0,0,0, 53, 0,82840,0,0,30000,1, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On Quest Accept - Start WP movement'),
(8284, 0, 3,4, 61, 0,100,0, 0, 0,0,0, 19, 768, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On Quest Accept - Remove Unit Flag'),
(8284, 0, 4,5, 61, 0,100,0, 0, 0,0,0, 91, 7, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On Quest Accept - Remove Bytes1 Death State'),
(8284, 0, 5,6, 61, 0,100,0, 0, 0,0,0, 64, 1, 0,0, 0, 0,0, 7, 0,0,0,0,0,0,0, 'Dorius Stonetender - On Quest Accept - Store target'),
(8284, 0, 6,0, 61, 0,100,0, 0, 0,0,0, 2, 250, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On Quest Accept - Set faction'),
(8284, 0, 7,0, 40, 0,100,0, 17, 82840,0,0, 80,828400, 2,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On WP Reached - Start Action List'),
(8284, 0, 8,0, 40, 0,100,0, 25, 82840,0,0, 80,828401, 2,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On WP Reached - Start Action List'),
(8284, 0, 9,0, 40, 0,100,0, 33, 82840,0,0, 80,828402, 2,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On WP Reached - Start Action List'),
(8284, 0, 10,0, 40, 0,100,0, 37, 82840,0,0, 80,828403, 2,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On WP Reached - Start Action List'),
(8284, 0, 11,0, 40, 0,100,0, 50, 82840,0,0, 80,828404, 2,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On WP Reached - Start Action List'),
(8284, 0, 12,0, 38, 0,100,0, 1, 1,0,0, 80,828405, 2,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On data set - Start Action List'),
(8284, 0, 13,0, 40, 0,100,0, 15, 82840,0,0, 45,2, 2,0, 0, 0,0, 15, 147516,50,0,0,0,0,0, 'Dorius Stonetender - On WP Reached - Set data'),
(8284, 0, 14,0, 4, 0,50,0, 0, 0,0,0, 1,8, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - On aggro - Say text'),
-- first stop
(828400,9, 0,0, 0, 0,100,0, 0, 0,0,0, 1, 0, 0,0, 0, 0,0,12, 1,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Say Line 0'),
(828400,9, 1,0, 0, 0,100,0, 0, 0,0,0, 54, 10000, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Pause WP (10 seconds)'),
(828400,9, 2,0, 0, 0,100,0, 500, 500,0,0, 90, 8, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Add Bytes1 Stand State (Kneel)'),
(828400,9, 3,0, 0, 0,100,0, 10000,10000,0,0, 91, 8, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Remove Bytes1 Stand State'),
-- second stop
(828401,9, 0,0, 0, 0,100,0, 0, 0,0,0, 54, 12000, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Pause WP (12 seconds)'),
(828401,9, 1,0, 0, 0,100,0, 500, 500,0,0, 90, 8, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Add Bytes1 Stand State (Kneel)'),
(828401,9, 2,0, 0, 0,100,0, 2000,2000,0,0, 91, 8, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Remove Bytes1 Stand State'),
(828401,9, 3,0, 0, 0,100,0, 0,0,0,0, 1, 1, 0,0, 0, 0,0,12, 1,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Say Line 1'),
(828401,9, 4,0, 0, 0,100,0, 9000,9000,0,0, 1, 9, 0,0, 0, 0,0,12, 1,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Say Line 9'),
-- third stop + spawns
(828402,9, 0,0, 0, 0,100,0, 0, 0,0,0, 1, 2, 0,0, 0, 0,0,12, 1,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Say Line 2'),
(828402,9, 1,0, 0, 0,100,0, 0, 0,0,0, 54, 10000, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Pause WP (10 seconds)'),
(828402,9, 2,0, 0, 0,100,0, 500, 500,0,0, 90, 8, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Add Bytes1 Stand State (Kneel)'),
(828402,9, 3,0, 0, 0,100,0, 9000,9000,0,0, 91, 8, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Remove Bytes1 Stand State'),
(828402,9, 4,0, 0, 0,100,0, 0, 0,0,0, 45, 2, 2,0, 0, 0,0, 15, 147517,50,0,0,0,0,0, 'Dorius Stonetender - Action List - Set data'),
-- start run
(828403,9, 0,0, 0, 0,100,0, 0, 0,0,0, 1, 3, 0,0, 0, 0,0,12, 1,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Say Line 3'),
(828403,9, 1,0, 0, 0,100,0, 0, 0,0,0, 54, 3000, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Pause WP (3 seconds)'),
(828403,9, 2,0, 0, 0,100,0, 0, 0,0,0, 59, 1, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Set Run On'),
-- start finale event
(828404,9, 0,0, 0, 0,100,0, 0, 0,0,0, 54, 30000, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Pause WP (30000 seconds)'),
(828404,9, 1,0, 0, 0,100,0, 0, 0,0,0, 1,4, 0,0, 0, 0,0, 12, 1,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Say text'), 
(828404,9, 2,0, 0, 0,100,0, 0, 0,0,0, 12, 8338, 8,0, 1, 0,0, 8, 0,0,0,-6370.26,-1974.93,256.79,3.55, 'Dorius Stonetender - Action List - Summon Dark Iron Marksman'),
-- end finale event
(828405,9, 0,0, 0, 0,100,0, 0, 0,0,0, 1, 5, 0,0, 0, 0,0,1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Say Line 5'),
(828405,9, 1,0, 0, 0,100,0, 0, 0,0,0, 11, 12218, 2,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Cast Spell Man Down!'),
(828405,9, 2,0, 0, 0,100,0, 0, 0,0,0, 90, 7, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Add Bytes1 Death State'),
(828405,9, 3,0, 0, 0,100,0, 0, 0,0,0, 50, 175704, 60,1, 0, 0,0, 8, 0,0,0,-6386.8901, -1984.05, 246.7299,0, 'Dorius Stonetender - Action List - Summon '),
(828405,9, 4,0, 0, 0,100,0, 0, 0,0,0, 15, 3367, 0,0, 0, 0,0,12, 1,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Quest explored'),
(828405,9, 5,0, 0, 0,100,0, 2000, 2000,0,0, 1, 6, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Say Line 6'),
(828405,9, 6,0, 0, 0,100,0, 1000, 1000,0,0, 1, 7, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Say Line 7'),
(828405,9, 7,0, 0, 0,100,0, 0, 0,0,0, 37, 0, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dorius Stonetender - Action List - Die'),
-- Dark Iron Marksman
(8338, 0, 0,0, 54, 0,100,0, 0, 0,0,0, 80,833800, 2,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dark Iron Marksman - On just summoned - Call Action List'),
(833800,9, 0,0, 0, 0,100,0, 1500, 1500,0,0, 1, 0, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dark Iron Marksman - Action List - Say Line 0'),
(833800,9, 1,0, 0, 0,100,0, 0, 0,0,0, 11, 12198, 0,0, 0, 0,0,19,8284,50,0,0,0,0,0, 'Dark Iron Marksman - Action List - Cast Marksman Hit'),
(833800,9, 2,0, 0, 0,100,0, 2000, 2000,0,0, 45, 1, 1,0, 0, 0,0,19,8284,50,0,0,0,0,0, 'Dark Iron Marksman - Action List - set data Marksman Hit'),
(833800,9, 3,0, 0, 0,100,0, 1000, 1000,0,0, 41, 0, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dark Iron Marksman - Action List - Despawn'),
(8337, 0, 0,0, 63, 0,100,0, 0, 0,0,0, 49,0, 0,0, 0, 0,0, 19, 8284,70,0,0,0,0,0, 'Dark Iron Steelshifter - On just Created - Start attack'),
(8337, 0, 1,0, 4, 0,50,0, 0, 0,0,0, 1, 0, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dark Iron Steelshifter - On aggro - Say Line 0'),
(147516, 1, 0,0, 38, 0,100,0, 2, 2,0,0, 80,14751700, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dark Iron - On data set - action list'),
(147517, 1, 0,0, 38, 0,100,0, 2, 2,0,0, 80,14751700, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dark Iron - On data set - action list'),
(14751700,9, 0,0, 0, 0,100,0, 0, 0,0,0, 118, 2, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dark Iron - Action List - set gob state'),
(14751700,9, 1,0, 0, 0,100,0, 0, 0,0,0, 11, 12168, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dark Iron - Action List - cast'),
(14751700,9, 2,0, 0, 0,100,0, 1000, 1000,0,0, 41, 0, 0,0, 0, 0,0, 1, 0,0,0,0,0,0,0, 'Dark Iron - Action List - Despawn');

DELETE FROM `creature_text` WHERE `CreatureID` IN (8284,8337,8338);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8284,0,0,"Stop... need to catch.... my breath.",12,0,100,0,0,0,4345,0,"Dorius Stonetender"),
(8284,1,0,"This is the place, $r: The Cauldron! Mark it on a map or do something so that you don''t forget. If anything ever happened to me, my team would be stuck in that mine forever.",12,0,100,25,0,0,4354,0,"Dorius Stonetender"),
(8284,2,0,"I''ve got to quit smoking! Give me a minute to catch my breath.",12,0,100,0,0,0,4356,0,"Dorius Stonetender"),
(8284,3,0,"We''re almost to safety. From here, we run. Try not to get too far behind! GO!",12,0,100,0,0,0,4357,0,"Dorius Stonetender"),
(8284,4,0,"The gate is in sight! We''re going to make it! But first, I need to take a breather.",12,0,100,0,0,0,4363,0,"Dorius Stonetender"),
(8284,5,0,"ARRRRRGH! He got me!",12,0,100,0,0,0,4359,0,"Dorius Stonetender"),
(8284,6,0,"%s points to the parchment on the ground.",16,0,100,0,0,0,5944,0,"Dorius Stonetender"),
(8284,7,0,"%s disappears in a cloud of dust.",16,0,100,0,0,0,4362,0,"Dorius Stonetender"),
(8284,8,0,"Are you going to let an injured dwarf do all the work for you?",12,0,100,0,0,0,4352,0,"Dorius Stonetender"),
(8284,8,1,"It's on! $n, meet my fists. Fists, say hello to $n.",12,0,100,0,0,0,4353,0,"Dorius Stonetender"),
(8284,9,0,"Onward! And be on guard this time! I'm not going to carry anymore fights.",12,0,100,0,0,0,4355,0,"Dorius Stonetender"),
(8337,0,0,"The secrets of Suntara will not leave these lands.", 14,0,100,0,0,0,4346,0,"Summon Dark Iron Steelshifter"),
(8338,0,0,"He''s mine...",14,0,100,0,0,0,4358,0,"Dark Iron Marksman");

DELETE FROM `waypoints` WHERE `entry`=82840;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`) VALUES
(82840, 1, -7005.02, -1742.09, 234.09),
(82840, 2, -7007.01, -1730.48, 234.09),
(82840, 3, -7004.89, -1726.50, 234.25),
(82840, 4, -7000.51, -1727.69, 235.47),
(82840, 5, -6989.39, -1737.25, 240.65),
(82840, 6, -6976.65, -1737.33, 241.83),
(82840, 7, -6954.92, -1742.04, 241.66),
(82840, 8, -6933.73, -1730.35, 241.70),
(82840, 9, -6931.64, -1719.75, 242.27),
(82840, 10, -6909.71, -1714.02, 241.26),
(82840, 11, -6898.56, -1723.56, 243.11),
(82840, 12, -6883.09, -1728.15, 241.00),
(82840, 13, -6879.24, -1737.66, 242.25),
(82840, 14, -6875.63, -1738.84, 244.00),
(82840, 15, -6868.03, -1745.78, 248.92),
(82840, 16, -6865.56, -1747.40, 250.42),
(82840, 17, -6857.70, -1748.29, 251.52), -- first stop
(82840, 18, -6853.29, -1745.18, 251.52),
(82840, 19, -6861.59, -1732.91, 251.66),
(82840, 20, -6860.00, -1723.85, 252.05),
(82840, 21, -6857.88, -1715.04, 251.52),
(82840, 22, -6850.99, -1698.89, 250.48),
(82840, 23, -6830.43, -1675.30, 251.52),
(82840, 24, -6818.79, -1674.68, 251.31),
(82840, 25, -6814.35, -1671.13, 250.31), -- second stop
(82840, 26, -6809.37, -1680.91, 250.10),
(82840, 27, -6801.58, -1695.83, 258.82),
(82840, 28, -6790.76, -1703.73, 259.55),
(82840, 29, -6781.22, -1715.15, 259.55),
(82840, 30, -6778.56, -1727.06, 259.55),
(82840, 31, -6777.09, -1744.06, 259.54),
(82840, 32, -6775.59, -1761.05, 257.50),
(82840, 33, -6777.40, -1780.64, 256.85), -- next break
(82840, 34, -6776.03, -1781.77, 256.85),
(82840, 35, -6728.56, -1814.42, 253.44),
(82840, 36, -6700.18, -1814.54, 250.46),
(82840, 37, -6677.81, -1821.25, 250.28), -- start run
(82840, 38, -6640.54, -1884.70, 244.27),
(82840, 39, -6612.79, -1916.98, 244.15),
(82840, 40, -6569.94, -1922.81, 244.16),
(82840, 41, -6540.13, -1938.87, 244.15),
(82840, 42, -6520.90, -1946.45, 244.15),
(82840, 43, -6504.90, -1955.36, 244.15),
(82840, 44, -6483.21, -1965.20, 244.24),
(82840, 45, -6471.10, -1968.55, 244.27),
(82840, 46, -6451.37, -1976.94, 244.45),
(82840, 47, -6405.94, -1974.30, 248.94),
(82840, 48, -6395.49, -1977.74, 247.89),
(82840, 49, -6389.20, -1978.71, 247.48),
(82840, 50, -6388.39, -1983.85, 246.72),
(82840, 51, -6388.39, -1983.85, 246.72);
