/*
-- Tormented Spirit -- http://wotlk.openwow.com/npc=1533
SET @NPC := 49222;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2882.23, 1037.63, 111.597, 0),
(@PATH, 2, 2891.75, 1028.41, 107.154, 0),
(@PATH, 3, 2897.44, 1009.81, 108.33, 0),
(@PATH, 4, 2898.23, 975.086, 114.218, 0),
(@PATH, 5, 2898.81, 957.889, 115.079, 0),
(@PATH, 6, 2900.9, 948.054, 115.272, 0),
(@PATH, 7, 2908.08, 932.171, 114.899, 0),
(@PATH, 8, 2908.56, 927.233, 114.845, 0),
(@PATH, 9, 2904.41, 921.068, 114.925, 0),
(@PATH, 10, 2897.89, 915.506, 114.76, 0),
(@PATH, 11, 2891.89, 912.366, 114.579, 0),
(@PATH, 12, 2864.54, 888.054, 112.785, 0),
(@PATH, 13, 2846.08, 873.334, 112.199, 0),
(@PATH, 14, 2822.72, 864.899, 111.841, 0),
(@PATH, 15, 2805.19, 861.231, 111.841, 0),
(@PATH, 16, 2792.86, 863.311, 111.756, 0),
(@PATH, 17, 2785.89, 866.45, 111.558, 0),
(@PATH, 18, 2763.86, 884.346, 111.468, 0),
(@PATH, 19, 2752.15, 900.057, 111.775, 0),
(@PATH, 20, 2745.14, 912.963, 110.819, 0),
(@PATH, 21, 2735.78, 942.471, 109.498, 0),
(@PATH, 22, 2733.88, 952.497, 109.278, 0),
(@PATH, 23, 2733.97, 964.451, 109.262, 0),
(@PATH, 24, 2735.98, 972.289, 109.316, 0),
(@PATH, 25, 2748.28, 980.282, 109.316, 0),
(@PATH, 26, 2759.92, 988.789, 109.336, 0),
(@PATH, 27, 2767.27, 997.694, 109.877, 0),
(@PATH, 28, 2770.28, 1005.85, 109.477, 0),
(@PATH, 29, 2772.9, 1017.25, 108.61, 0),
(@PATH, 30, 2773.85, 1027.46, 108.478, 0),
(@PATH, 31, 2790.31, 1042.25, 110.684, 0),
(@PATH, 32, 2810.03, 1038.34, 111.127, 0),
(@PATH, 33, 2824.45, 1037.32, 112.118, 0),
(@PATH, 34, 2839.4, 1037.63, 113.927, 0),
(@PATH, 35, 2853.29, 1041.9, 115.65, 0),
(@PATH, 36, 2861.56, 1043.2, 115.985, 0),
(@PATH, 37, 2882.23, 1037.63, 111.597, 20000);


UPDATE `creature` SET `position_x`=2869.45,`position_y`=1046.28,`position_z`=114.79 WHERE `guid`=49222;

-- Tormented Spirit SAI
SET @ENTRY := 1533;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,16000,18000,11,7713,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormented Spirit - Within 0-8 Range - Cast 'Wailing Dead'");
*/
