UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=4880;

DELETE FROM `smart_scripts` WHERE `entryorguid`=4880  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(488000,488001)  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4880,0,0,2,19,0,100,0,1270,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Quest Accept (Stinkys Escape - H) - Store Targetlist'),
(4880,0,1,2,19,0,100,0,1222,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Quest Accept (Stinkys Escape - A) - Store Targetlist'),
(4880,0,2,0,61,0,100,0,0,0,0,0,80,488000,2,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Link - Run Script'),
(4880,0,3,4,40,0,100,0,8,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP8 - Pause WP (3 Seconds)'),
(4880,0,4,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP8 - Say Line 1'),
(4880,0,5,6,40,0,100,0,12,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP12 - Pause WP (3 Seconds)'),
(4880,0,6,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP12 - Say Line 2'),
(4880,0,7,0,40,0,100,0,26,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP26 - Say Line 3'),
(4880,0,8,9,40,0,100,0,27,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached 27 - Pause WP (6 Seconds)'),
(4880,0,9,0,61,0,100,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached 27 - Say Line 4'),
(4880,0,10,11,40,0,100,0,28,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP28 - Pause WP (6 Seconds)'),
(4880,0,11,0,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached 28 - Say Line 5'),
(4880,0,12,13,40,0,100,0,29,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP29 - Pause WP (6 Seconds)'),
(4880,0,13,14,61,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached 29 - Set Bytes 1'),
(4880,0,14,27,61,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached 29 - Say Line 6'),
(4880,0,15,16,40,0,100,0,30,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP30 - Set Bytes 1'),
(4880,0,16,0,61,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP30 - Say Line 7'),
(4880,0,17,18,40,0,100,0,38,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP38 - Pause WP (6 Seconds)'),
(4880,0,18,19,61,0,100,0,0,0,0,0,1,8,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP38 - Say Line 8'),
(4880,0,19,20,61,0,100,0,0,0,0,0,15,1270,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP38 - Complete Quest'),
(4880,0,20,21,61,0,100,0,0,0,0,0,15,1222,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP38 - Complete Quest'),
(4880,0,21,0,40,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP38 - Set Run On'),
(4880,0,22,23,40,0,100,0,40,0,0,0,1,9,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP40 - Say Line 9'),
(4880,0,23,0,61,0,100,0,40,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP40 - Despawn'),
(4880,0,24,26,6,0,100,0,0,0,0,0,6,1270,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Death - Fail Quest'),
(4880,0,25,0,61,0,100,0,0,0,0,0,6,1222,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Death - Fail Quest'),
(4880,0,26,0,0,0,100,0,1000,1000,30000,30000,1,10,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - IC  - Say Line 10'),
(4880,0,27,0,61,0,100,0,0,0,0,0,70,300,0,0,0,0,0,14,11757,20939,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP29 - Despawn Bogbean Plant'),
(4880,0,28,0,24,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Evade - Set Bytes 1'),
(488000,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Set NPC Flags'),
(488000,9,1,0,0,0,100,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Set Faction'),
(488000,9,2,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Set Bytes 1'),
(488000,9,3,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Set aggresive'),
(488000,9,4,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Say Line 0'),
(488000,9,5,0,0,0,100,0,0,0,0,0,53,0,4880,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Start WP');

DELETE FROM `waypoints` WHERE `entry`=4880;
DELETE FROM `script_waypoint` WHERE `entry`=4880;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(4880, 1, -2646.43, -3436.07, 35.3732, '"Stinky" Ignatz'),
(4880, 2, -2650.83, -3440.15, 35.1381, '"Stinky" Ignatz'),
(4880, 3, -2662.31, -3447.67, 35.1089, '"Stinky" Ignatz'),
(4880, 4, -2680.48, -3454.6, 34.6538, '"Stinky" Ignatz'),
(4880, 5, -2701.02, -3457.44, 34.2691, '"Stinky" Ignatz'),
(4880, 6, -2724.06, -3458.64, 33.6735, '"Stinky" Ignatz'),
(4880, 7, -2745.01, -3459.28, 32.5346, '"Stinky" Ignatz'),
(4880, 8, -2759.42, -3464.78, 32.7143, '"Stinky" Ignatz'), -- 3000
(4880, 9, -2763.63, -3471.51, 33.5388, '"Stinky" Ignatz'),
(4880, 10, -2771.79, -3480.89, 33.2553, '"Stinky" Ignatz'),
(4880, 11, -2780.66, -3488.76, 31.875, '"Stinky" Ignatz'),
(4880, 12, -2796.14, -3489.01, 30.8585, '"Stinky" Ignatz'), -- 3000
(4880, 13, -2792.12, -3495.97, 30.7324, '"Stinky" Ignatz'),
(4880, 14, -2789.06, -3502.37, 30.6704, '"Stinky" Ignatz'),
(4880, 15, -2787.72, -3515.01, 31.1176, '"Stinky" Ignatz'),
(4880, 16, -2790.84, -3523.31, 30.5733, '"Stinky" Ignatz'),
(4880, 17, -2796.59, -3520.62, 29.9187, '"Stinky" Ignatz'),
(4880, 18, -2798.56, -3518.91, 30.3887, '"Stinky" Ignatz'),
(4880, 19, -2801.47, -3516.75, 30.1915, '"Stinky" Ignatz'),
(4880, 20, -2804.36, -3513.9, 29.5508, '"Stinky" Ignatz'),
(4880, 21, -2807.98, -3518, 29.9488, '"Stinky" Ignatz'),
(4880, 22, -2815.68, -3521.74, 29.7723, '"Stinky" Ignatz'),
(4880, 23, -2823.39, -3526.23, 31.7194, '"Stinky" Ignatz'),
(4880, 24, -2836.11, -3544.7, 32.4939, '"Stinky" Ignatz'),
(4880, 25, -2830.39, -3568.86, 30.4104, '"Stinky" Ignatz'),
(4880, 26, -2824.84, -3569.52, 31.2811, '"Stinky" Ignatz'),
(4880, 27, -2818.66, -3567.8, 30.9204, '"Stinky" Ignatz'), -- 6000
(4880, 28, -2817.66, -3568.94, 30.4312, '"Stinky" Ignatz'), -- 6000
(4880, 29, -2820.39, -3592.22, 30.7163, '"Stinky" Ignatz'), -- 6000
(4880, 30, -2820.77, -3592.5, 30.8861, '"Stinky" Ignatz'),
(4880, 31, -2829.91, -3588.73, 30.6831, '"Stinky" Ignatz'),
(4880, 32, -2842.32, -3577.5, 36.8489, '"Stinky" Ignatz'),
(4880, 33, -2851.18, -3567.58, 38.5159, '"Stinky" Ignatz'),
(4880, 34, -2865.55, -3551.58, 41.439, '"Stinky" Ignatz'),
(4880, 35, -2871.23, -3548.15, 40.7614, '"Stinky" Ignatz'),
(4880, 36, -2877.84, -3544.15, 38.6702, '"Stinky" Ignatz'),
(4880, 37, -2890.39, -3542.39, 34.3144, '"Stinky" Ignatz'),
(4880, 38, -2898.73, -3543.64, 34.32, '"Stinky" Ignatz'), -- 6000
(4880, 39, -2910.06, -3568.96, 34.25, '"Stinky" Ignatz'),
(4880, 40, -2932.51, -3584.62, 37.2385, '"Stinky" Ignatz');

DELETE FROM `creature_text` WHERE `entry`=4880;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(4880, 0, 0, 'Ok, let''s get started.', 12, 0, 100, 0, 0, 0, 1610, 0, '"Stinky" Ignatz'),
(4880, 1, 0, 'Now let''s look for the herb.', 12, 0, 100, 0, 0, 0, 1611, 0, '"Stinky" Ignatz'),
(4880, 2, 0, 'Nope, not here...', 12, 0, 100, 0, 0, 0, 1612, 0, '"Stinky" Ignatz'),
(4880, 3, 0, 'There must be one around here somewhere...', 12, 0, 100, 0, 0, 0, 1613, 0, '"Stinky" Ignatz'),
(4880, 4, 0, 'Ah, there''s one!', 12, 0, 100, 0, 0, 0, 1614, 0, '"Stinky" Ignatz'),
(4880, 5, 0, 'Come, $n!  Let''s go over there and collect it!', 12, 0, 100, 0, 0, 0, 1615, 0, '"Stinky" Ignatz'),
(4880, 6, 0, '%s picks the herb from the ground.', 16, 0, 100, 0, 0, 0, 1616, 0, '"Stinky" Ignatz'),
(4880, 7, 0, 'Ok, now let''s get out of here!', 12, 0, 100, 0, 0, 0, 1617, 0, '"Stinky" Ignatz'),
(4880, 8, 0, 'I can make it from here.  Thanks, $n!  And talk to my employer about a reward!', 12, 0, 100, 0, 0, 0, 1618, 0, '"Stinky" Ignatz'),
(4880, 9, 0, '%s disappears back into the swamp.', 16, 0, 100, 0, 0, 0, 1619, 0, '"Stinky" Ignatz'),
(4880, 10, 0, 'Help! I''m under attack!', 12, 0, 100, 0, 0, 0, 1629, 0, '"Stinky" Ignatz'),
(4880, 10, 1, 'Help!  The beast is on me!', 12, 0, 100, 0, 0, 0, 1630, 0, '"Stinky" Ignatz');

UPDATE `vehicle_template_accessory` SET `minion`=1 WHERE `entry` IN(32640,32633);
