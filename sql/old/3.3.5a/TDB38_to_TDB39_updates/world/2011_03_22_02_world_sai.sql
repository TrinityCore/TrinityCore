-- Pathing for Stormfleet Deckhand SAI
SET @ENTRY := 25234;
SET @PATH1 := @ENTRY*100;
SET @PATH2 := @ENTRY*100+1;
SET @PATH3 := @ENTRY*100+2;
SET @PATH4 := @ENTRY*100+3;
-- Remove old waypoint data and scripts
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=2265.704,`position_y`=5314.686,`position_z`=22.43809 WHERE `guid`=109653;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=2253.791,`position_y`=5252.389,`position_z`=35.69936 WHERE `guid`=109654;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=2220.033,`position_y`=5292.010,`position_z`=10.70095 WHERE `guid`=109652;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=2233.497,`position_y`=5291.667,`position_z`=11.21773 WHERE `guid`=109655;
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid` IN (109653,109654,109652,109655);
DELETE FROM `waypoint_data` WHERE `id` IN (1096530,1096540,1096520,1096550);
DELETE FROM `waypoint_scripts` WHERE `id` IN (1057,1058,1059,1060,1061,1130,1131,1132,1133);
-- SAI for Stormfleet Deckhand
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-109653,-109654,-109652,-109655);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-109653,0,0,0,11,0,100,0,0,0,0,0,53,0,@PATH1,1,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - On spawn - Start WP movement'),
(-109653,0,1,2,40,0,100,0,4,@PATH1,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 4 - pause wp'),
(-109653,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 4 - run script'),
(-109653,0,3,4,40,0,100,0,8,@PATH1,0,0,54,21000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 8 - pause wp'),
(-109653,0,4,5,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.794493, 'Stormfleet Deckhand - Reach wp 8 - turn to'),
(-109653,0,5,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 8 - run script'),
(-109654,0,0,0,11,0,100,0,0,0,0,0,53,0,@PATH2,1,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - On spawn - Start WP movement'),
(-109654,0,1,2,40,0,100,0,6,@PATH2,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 6 - pause wp'),
(-109654,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 6 - run script'),
(-109654,0,3,4,40,0,100,0,13,@PATH2,0,0,54,21000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 13 - pause wp'),
(-109654,0,4,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 13 - run script'),
(-109652,0,0,0,11,0,100,0,0,0,0,0,53,0,@PATH3,1,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - On spawn - Start WP movement'),
(-109652,0,1,2,40,0,100,0,17,@PATH3,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 17 - pause wp'),
(-109652,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 17 - run script'),
(-109652,0,3,4,40,0,100,0,9,@PATH3,0,0,54,21000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 9 - pause wp'),
(-109652,0,4,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 9 - run script'),
(-109655,0,0,0,11,0,100,0,0,0,0,0,53,0,@PATH4,1,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - On spawn - Start WP movement'),
(-109655,0,1,2,40,0,100,0,3,@PATH4,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 3 - pause wp'),
(-109655,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 3 - run script'),
(-109655,0,3,4,40,0,100,0,13,@PATH4,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 13 - pause wp'),
(-109655,0,4,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 13 - run script'),
(-109655,0,5,6,40,0,100,0,16,@PATH4,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 16 - pause wp'),
(-109655,0,6,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 16 - run script'),
(-109655,0,7,8,40,0,100,0,25,@PATH4,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 25 - pause wp'),
(-109655,0,8,9,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.969026, 'Stormfleet Deckhand - Reach wp 25 - turn to'),
(-109655,0,9,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - Reach wp 25 - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - script - set bytes1'),
(@ENTRY*100,9,1,0,0,0,100,0,10000,10000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - script - remove bytes1'),
(@ENTRY*100+1,9,0,0,0,0,100,0,3000,3000,0,0,5,22,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - script - emote'),
(@ENTRY*100+1,9,1,0,0,0,100,0,6000,6000,0,0,5,70,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - script - emote'),
(@ENTRY*100+1,9,2,0,0,0,100,0,6000,6000,0,0,5,22,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - script - emote'),
(@ENTRY*100+2,9,0,0,0,0,100,0,1000,1000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - script - set state STATE_USESTANDING'),
(@ENTRY*100+2,9,1,0,0,0,100,0,8000,8000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - script - set state NONE'),
(@ENTRY*100+2,9,2,0,0,0,100,0,0,0,0,0,90,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - script - set bytes1'),
(@ENTRY*100+2,9,3,0,0,0,100,0,2000,2000,0,0,91,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stormfleet Deckhand - script - remove bytes1');
-- Waypoints for Stormfleet Deckhand from sniff
DELETE FROM `waypoints` WHERE `entry` IN (@PATH1,@PATH2,@PATH3,@PATH4);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@PATH1,1,2261.388,5305.248,21.68184, 'Stormfleet Deckhand'),
(@PATH1,2,2259.963,5295.583,20.08975, 'Stormfleet Deckhand'),
(@PATH1,3,2260.002,5286.996,15.49093, 'Stormfleet Deckhand'),
(@PATH1,4,2257.711,5281.927,12.09341, 'Stormfleet Deckhand'),
(@PATH1,5,2261.763,5286.725,15.76729, 'Stormfleet Deckhand'),
(@PATH1,6,2260.902,5294.649,19.95268, 'Stormfleet Deckhand'),
(@PATH1,7,2263.460,5304.816,21.72922, 'Stormfleet Deckhand'),
(@PATH1,8,2265.704,5314.686,22.43809, 'Stormfleet Deckhand'),
(@PATH2,1,2248.875,5255.391,36.45885, 'Stormfleet Deckhand'),
(@PATH2,2,2246.625,5256.641,37.20885, 'Stormfleet Deckhand'),
(@PATH2,3,2244.625,5258.641,36.45885, 'Stormfleet Deckhand'),
(@PATH2,4,2241.625,5258.391,37.20885, 'Stormfleet Deckhand'),
(@PATH2,5,2238.625,5259.391,36.45885, 'Stormfleet Deckhand'),
(@PATH2,6,2232.960,5260.392,35.71835, 'Stormfleet Deckhand'),
(@PATH2,7,2235.375,5260.141,36.20885, 'Stormfleet Deckhand'),
(@PATH2,8,2239.375,5259.141,36.45885, 'Stormfleet Deckhand'),
(@PATH2,9,2241.625,5258.641,37.20885, 'Stormfleet Deckhand'),
(@PATH2,10,2244.625,5258.641,36.45885, 'Stormfleet Deckhand'),
(@PATH2,11,2247.125,5256.391,37.20885, 'Stormfleet Deckhand'),
(@PATH2,12,2249.125,5255.391,36.45885, 'Stormfleet Deckhand'),
(@PATH2,13,2253.791,5252.389,35.69936, 'Stormfleet Deckhand'),
(@PATH3,1,2212.298,5281.927,10.82595, 'Stormfleet Deckhand'),
(@PATH3,2,2211.701,5275.361,10.82595, 'Stormfleet Deckhand'),
(@PATH3,3,2224.383,5268.124,7.166187, 'Stormfleet Deckhand'),
(@PATH3,4,2235.353,5264.704,8.606246, 'Stormfleet Deckhand'),
(@PATH3,5,2244.243,5262.414,11.81635, 'Stormfleet Deckhand'),
(@PATH3,6,2248.373,5259.464,11.78494, 'Stormfleet Deckhand'),
(@PATH3,7,2247.781,5252.418,11.96684, 'Stormfleet Deckhand'),
(@PATH3,8,2246.383,5249.14,15.53435, 'Stormfleet Deckhand'),
(@PATH3,9,2243.871,5243.415,21.4974, 'Stormfleet Deckhand'),
(@PATH3,10,2245.975,5248.252,16.51618, 'Stormfleet Deckhand'),
(@PATH3,11,2248.437,5255.79,11.86939, 'Stormfleet Deckhand'),
(@PATH3,12,2248.403,5261.318,11.747, 'Stormfleet Deckhand'),
(@PATH3,13,2228.012,5267.475,7.16457, 'Stormfleet Deckhand'),
(@PATH3,14,2215.574,5274.178,11.13563, 'Stormfleet Deckhand'),
(@PATH3,15,2213.556,5283.097,10.82595, 'Stormfleet Deckhand'),
(@PATH3,16,2218.244,5291.424,10.70095, 'Stormfleet Deckhand'),
(@PATH3,17,2224.214,5293.65,10.82595, 'Stormfleet Deckhand'),
(@PATH3,18,2220.033,5292.01,10.70095, 'Stormfleet Deckhand'),
(@PATH4,1,2232.031,5289.312,11.11433, 'Stormfleet Deckhand'),
(@PATH4,2,2229.514,5285.923,11.22073, 'Stormfleet Deckhand'),
(@PATH4,3,2231.239,5285.13,11.22661, 'Stormfleet Deckhand'),
(@PATH4,4,2229.854,5285.705,11.22414, 'Stormfleet Deckhand'),
(@PATH4,5,2228.48,5291.178,11.13671, 'Stormfleet Deckhand'),
(@PATH4,6,2226.165,5291.41,10.95095, 'Stormfleet Deckhand'),
(@PATH4,7,2223.731,5291.465,10.82595, 'Stormfleet Deckhand'),
(@PATH4,8,2218.564,5293.642,10.70095, 'Stormfleet Deckhand'),
(@PATH4,9,2213.531,5285.789,10.70095, 'Stormfleet Deckhand'),
(@PATH4,10,2208.855,5275.448,10.82595, 'Stormfleet Deckhand'),
(@PATH4,11,2206.379,5260.244,10.58918, 'Stormfleet Deckhand'),
(@PATH4,12,2211.11,5256.537,10.71418, 'Stormfleet Deckhand'),
(@PATH4,13,2219.187,5252.958,11.33607, 'Stormfleet Deckhand'),
(@PATH4,14,2216.945,5251.284,11.26102, 'Stormfleet Deckhand'),
(@PATH4,15,2215.487,5248.678,11.44615, 'Stormfleet Deckhand'),
(@PATH4,16,2217.447,5248.063,11.4383, 'Stormfleet Deckhand'),
(@PATH4,17,2213.407,5251.713,10.96418, 'Stormfleet Deckhand'),
(@PATH4,18,2207.356,5257.069,10.71418, 'Stormfleet Deckhand'),
(@PATH4,19,2205.434,5262.277,10.58918, 'Stormfleet Deckhand'),
(@PATH4,20,2208.177,5274.885,10.82595, 'Stormfleet Deckhand'),
(@PATH4,21,2214.61,5286.973,10.82595, 'Stormfleet Deckhand'),
(@PATH4,22,2219.416,5292.909,10.70095, 'Stormfleet Deckhand'),
(@PATH4,23,2224.719,5291.44,10.82595, 'Stormfleet Deckhand'),
(@PATH4,24,2228.346,5291.136,10.95095, 'Stormfleet Deckhand'),
(@PATH4,25,2233.497,5291.667,11.21773, 'Stormfleet Deckhand');
