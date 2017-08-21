-- http://wow.gamepedia.com/Matt
DELETE FROM `creature_text` WHERE `entry`=794;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(794, 0, 0, 'Dang! Fish arent biting here either. I am gonna go back to my ol fishin hole!', 12, 7, 100, 0, 0, 0, 'Matt', 894),
(794, 1, 0, 'Gee, fish sure dont seem to be biting here. Maybe I should go over to Crystal Lake to try my luck there!', 12, 7, 100, 0, 0, 0, 'Matt', 893);

-- Matt SAI
SET @ENTRY := 794;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100+00,@ENTRY*100+01) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,512,0,0,0,0,53,0,794,1,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,512,1,794,0,0,54,3597000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,512,1,794,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,512,26,794,0,0,54,900000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Waypoint 26 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,40,0,100,512,26,794,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Waypoint 26 Reached - Run Script"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,71,1,0,1117,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Change Equipment"),
(@ENTRY*100+00,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,-9387.45,-117.388,58.8643,2.61799,"Matt - On Script - Set Orientation 2,61799"),
(@ENTRY*100+00,9,2,0,0,0,100,0,3597000,3597000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Say Line 0"),
(@ENTRY*100+00,9,3,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Change Equipment"),
(@ENTRY*100+01,9,0,0,0,0,100,0,0,0,0,0,71,1,0,1117,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Change Equipment"),
(@ENTRY*100+01,9,1,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,8,0,0,0,-9429.23,148.94,56.5713,2.118,"Matt - On Script - Set Orientation 2,118"),
(@ENTRY*100+01,9,2,0,0,0,100,0,897000,897000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Say Line 1"),
(@ENTRY*100+01,9,3,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matt - On Script - Change Equipment");

-- Matt Waypoint
DELETE FROM `waypoints` WHERE `entry`=794;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@ENTRY, 1 ,-9387.448,-117.388,58.86428, 'Matt'), -- 14:31:28 -- 3600000
(@ENTRY, 2 ,-9383.961,-114.8808,59.08251, 'Matt'), -- 15:15:41
(@ENTRY, 3 ,-9380.154,-108.276,59.25655, 'Matt'), -- 15:15:43
(@ENTRY, 4 ,-9380.848,-101.6898,61.68277, 'Matt'), -- 15:15:45
(@ENTRY, 5 ,-9387.704,-91.85216,63.20706, 'Matt'), -- 15:15:48
(@ENTRY, 6 ,-9390.816,-90.64014,64.34749, 'Matt'), -- 15:15:53
(@ENTRY, 7 ,-9407.41,-88.2923,61.98596, 'Matt'), -- 15:15:56
(@ENTRY, 8 ,-9413.96,-87.82951,61.04494, 'Matt'), -- 15:16:01
(@ENTRY, 9 ,-9417.158,-87.50026,60.49351, 'Matt'), -- 15:16:05
(@ENTRY, 10,-9421.599,-80.92403,60.69189, 'Matt'), -- 15:16:07
(@ENTRY, 11,-9423.156,-52.4566,63.79184, 'Matt'), -- 15:16:13
(@ENTRY, 12,-9420.547,-36.44093,63.29053, 'Matt'), -- 15:16:21
(@ENTRY, 13,-9421.891,-23.8332,62.43909, 'Matt'), -- 15:16:27
(@ENTRY, 14,-9429.023,0.1944809,60.95766, 'Matt'), -- 15:16:34
(@ENTRY, 15,-9430.42,6.69886,59.95515, 'Matt'), -- 15:16:41
(@ENTRY, 16,-9433.049,28.14976,58.22381, 'Matt'), -- 15:16:49
(@ENTRY, 17,-9432.948,36.57756,57.2988, 'Matt'), -- 15:16:54
(@ENTRY, 18,-9432.741,48.06789,56.85545, 'Matt'), -- 15:17:01
(@ENTRY, 19,-9436.523,61.44022,56.62671, 'Matt'), -- 15:17:07
(@ENTRY, 20,-9423.229,92.4316,57.68261, 'Matt'), -- 15:17:13
(@ENTRY, 21,-9417.555,104.966,59.53194, 'Matt'), -- 15:17:20
(@ENTRY, 22,-9413.809,111.0759,60.54739, 'Matt'), -- 15:17:26
(@ENTRY, 23,-9410.355,126.8208,59.89996, 'Matt'), -- 15:17:32
(@ENTRY, 24,-9416.291,137.0582,59.09748, 'Matt'), -- 15:17:37
(@ENTRY, 25,-9421.65,142.9827,58.27094, 'Matt'), -- 15:17:41
(@ENTRY, 26,-9429.229,148.94,56.57125, 'Matt'), -- 15:17:44  -- 900000
(@ENTRY, 27,-9424.639,136.6448,59.14201, 'Matt'), -- 14:29:13
(@ENTRY, 28,-9416.943,128.2254,59.84607, 'Matt'), -- 14:29:20
(@ENTRY, 29,-9408.01,117.3048,60.68095, 'Matt'), -- 14:29:26
(@ENTRY, 30,-9404.777,110.4311,60.1431, 'Matt'), -- 14:29:29
(@ENTRY, 31,-9404.203,99.88391,59.06318, 'Matt'), -- 14:29:34
(@ENTRY, 32,-9415.88,87.02467,57.41075, 'Matt'), -- 14:29:39
(@ENTRY, 33,-9420.471,83.63406,56.86155, 'Matt'), -- 14:29:46
(@ENTRY, 34,-9436.522,69.25112,56.50404, 'Matt'), -- 14:29:55
(@ENTRY, 35,-9440.947,60.83078,56.30841, 'Matt'), -- 14:29:59
(@ENTRY, 36,-9430.784,43.44138,57.09395, 'Matt'), -- 14:30:03
(@ENTRY, 37,-9419.325,27.65322,58.00757, 'Matt'), -- 14:30:11
(@ENTRY, 38,-9403.117,7.486176,60.30029, 'Matt'), -- 14:30:17
(@ENTRY, 39,-9393.432,-3.420914,61.21665, 'Matt'), -- 14:30:28
(@ENTRY, 40,-9380.711,-17.91664,62.45811, 'Matt'), -- 14:30:32
(@ENTRY, 41,-9379.764,-19.26388,62.62563, 'Matt'), -- 14:30:40
(@ENTRY, 42,-9366.547,-30.96574,63.63699, 'Matt'), -- 14:30:43
(@ENTRY, 43,-9358.822,-43.82347,65.27631, 'Matt'), -- 14:30:48
(@ENTRY, 44,-9356.564,-49.49134,66.07014, 'Matt'), -- 14:30:56
(@ENTRY, 45,-9358.139,-71.0817,64.59801, 'Matt'), -- 14:30:59
(@ENTRY, 46,-9358.818,-73.2935,65.17371, 'Matt'), -- 14:31:05
(@ENTRY, 47,-9364.586,-80.76942,64.87081, 'Matt'), -- 14:31:08
(@ENTRY, 48,-9367.941,-84.89754,64.55246, 'Matt'), -- 14:31:11
(@ENTRY, 49,-9374.869,-96.70338,63.28677, 'Matt'), -- 14:31:14
(@ENTRY, 50,-9377.46,-102.744,61.81012, 'Matt'), -- 14:31:16
(@ENTRY, 51,-9379.592,-109.5267,59.26672, 'Matt'), -- 14:31:20
(@ENTRY, 52,-9383.477,-114.4253,59.07925, 'Matt'), -- 14:31:24
(@ENTRY, 53,-9385.668,-116.1328,59.09434, 'Matt'); -- 14:31:26
