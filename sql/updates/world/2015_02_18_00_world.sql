-- Mug'gok SAI
SET @ENTRY := 18475;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,18475,1,0,0,2,1,0,0,0,0,0,0,0,"Mug'gok - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,18475,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'gok - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,1,18475,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'gok - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY*100+00,9,0,0,0,0,100,0,2000,2000,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'gok - On Script - Say Line 0"),
(@ENTRY*100+00,9,1,0,0,0,100,0,2000,2000,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'gok - On Script - Say Line 1"),
(@ENTRY*100+00,9,3,0,0,0,100,0,2000,2000,0,0,1,2,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'gok - On Script - Say Line 2");

-- Add text
DELETE FROM `creature_text` WHERE `entry`=18475;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(18475, 0, 0, 'Come out, little birdies! Mug''gok want to play!', 14, 0, 100, 0, 0, 0, 'Muggok', 15463),
(18475, 1, 0, 'No hurt Mug''gok''s feelings, bird-men!', 14, 0, 100, 0, 0, 0, 'Muggok', 15464),
(18475, 2, 0, 'Fine! Birdies be dat way! Mug''gok find new friends!', 14, 0, 100, 14, 0, 0, 'Muggok', 15465);

-- Add waypoints
DELETE FROM `waypoints` WHERE `entry`=18475;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(18475, 1, -3586.119,5789.734,-4.249763, 'Muggok'),
(18475, 2, -3607.362,5802.457,-4.015522, 'Muggok'),
(18475, 3, -3611.601,5813.162,-4.286913, 'Muggok'),
(18475, 4, -3620.696,5832.479,0.1701524, 'Muggok'),
(18475, 5, -3632.274,5845.131,-0.2069848, 'Muggok'),
(18475, 6, -3644.935,5868.452,-4.990351, 'Muggok'),
(18475, 7, -3637.306,5910.221,-21.84441, 'Muggok'),
(18475, 8, -3641.046,5941.752,-30.85709, 'Muggok'),
(18475, 9, -3638.008,5970.188,-22.30242, 'Muggok'),
(18475, 10, -3625.294,5984.689,-19.98056, 'Muggok'),
(18475, 11, -3593.81,5984.915,-30.74051, 'Muggok'),
(18475, 12, -3560.429,5994.253,-34.44781, 'Muggok'),
(18475, 13, -3533.398,6024.583,-24.52451, 'Muggok'),
(18475, 14, -3525.008,6048.768,-20.22229, 'Muggok'),
(18475, 15, -3509.135,6060.514,-15.46761, 'Muggok'),
(18475, 16, -3465.905,6061.523,-15.65, 'Muggok'),
(18475, 17, -3455.743,6054.097,-12.08964, 'Muggok'),
(18475, 18, -3452,6032.292,-14.2308, 'Muggok'),
(18475, 19, -3449.686,6012.386,-17.47238, 'Muggok'),
(18475, 20, -3443.185,5993.315,-23.15056, 'Muggok'),
(18475, 21, -3440.388,5986.851,-24.24662, 'Muggok'),
(18475, 22, -3435.465,5956.201,-24.91395, 'Muggok'),
(18475, 23, -3446.49,5924.918,-33.08622, 'Muggok'),
(18475, 24, -3466.203,5894.721,-28.9427, 'Muggok'),
(18475, 25, -3483.424,5870.367,-23.49757, 'Muggok'),
(18475, 26, -3495.208,5849.559,-15.93699, 'Muggok'),
(18475, 27, -3507.46,5820.458,-12.90878, 'Muggok'),
(18475, 28, -3519.906,5799.604,-7.427849, 'Muggok'),
(18475, 29, -3532.312,5789.58,-6.70218, 'Muggok'),
(18475, 30, -3553.792,5784.59,-4.330991, 'Muggok'),
(18475, 31, -3562.554,5785.313,-1.650567, 'Muggok');
