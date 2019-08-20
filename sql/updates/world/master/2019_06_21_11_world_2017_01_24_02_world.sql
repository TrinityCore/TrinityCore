-- Jimmy the Stable Boy
UPDATE `creature` SET `position_x`=2260.2114, `position_y`=5205.3139, `position_z`=11.4189, `orientation`=5.8917 WHERE  `guid`=117744;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0, `position_x`=2255.84643, `position_y`=5207.1347, `position_z`=11.2519, `orientation`=5.8878 WHERE  `guid`=117793;

-- Jimmy the Stable Boy SAI
SET @ENTRY := 27364;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,34,0,100,0,2,1,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jimmy the Stable Boy - On Reached Point 1 - Run Script"),
(@ENTRY,0,1,0,34,0,100,0,2,9,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jimmy the Stable Boy - On Reached Point 9 - Run Script"),
(@ENTRY,0,2,0,34,0,100,0,2,23,0,0,1,4,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Jimmy the Stable Boy - On Reached Point 23 - Say Line 4"),
(@ENTRY,0,3,0,34,0,100,0,2,27,0,0,28,48478,0,0,0,0,0,10,117793,27365,0,0,0,0,0,"Jimmy the Stable Boy - On Reached Point 27 - Remove Aura 'Transform - Stabled Pet Appearance'");

-- Actionlist SAI
SET @ENTRY := 2736400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Jimmy the Stable Boy - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,6000,6000,0,0,1,0,6000,0,0,0,0,10,107742,27010,0,0,0,0,0,"Jimmy the Stable Boy - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,75,48478,0,0,0,0,0,10,117793,27365,0,0,0,0,0,"Jimmy the Stable Boy - On Script - Add Aura 'Transform - Stabled Pet Appearance'"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Jimmy the Stable Boy - On Script - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 2736401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,6000,6000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Jimmy the Stable Boy - On Script - Say Line 2"),
(@ENTRY,9,1,0,0,0,100,0,6000,6000,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Jimmy the Stable Boy - On Script - Say Line 3");

DELETE FROM `waypoint_data` WHERE `id`=1177440;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1177440, 1, 2260.21, 5205.31, 11.4189, 0, 0, 0, 0, 100, 0),
(1177440, 2, 2260.21, 5205.31, 11.4189, 0, 20000, 0, 0, 100, 0),
(1177440, 3, 2258.42, 5206.38, 11.3041, 0, 0, 0, 0, 100, 0),
(1177440, 4, 2260.78, 5212.97, 11.2323, 0, 0, 0, 0, 100, 0),
(1177440, 5, 2265.26, 5222.43, 11.285, 0, 0, 0, 0, 100, 0),
(1177440, 6, 2275.49, 5231.85, 11.3558, 0, 0, 0, 0, 100, 0),
(1177440, 7, 2284.1, 5249.56, 11.2543, 0, 0, 0, 0, 100, 0),
(1177440, 8, 2285.7, 5265.13, 11.3355, 0, 0, 0, 0, 100, 0),
(1177440, 9, 2285.82, 5269.38, 11.3778, 0, 0, 0, 0, 100, 0),
(1177440, 10, 2288.5, 5271.9, 11.4001, 0, 15000, 0, 0, 100, 0),
(1177440, 11, 2282.43, 5249.42, 11.2138, 0, 0, 0, 0, 100, 0),
(1177440, 12, 2275.66, 5250.47, 11.2624, 0, 0, 0, 0, 100, 0),
(1177440, 13, 2265.76, 5253.98, 7.16312, 0, 0, 0, 0, 100, 0),
(1177440, 14, 2252.91, 5259.53, 10.2728, 0, 0, 0, 0, 100, 0),
(1177440, 15, 2246.47, 5262.26, 11.7963, 0, 0, 0, 0, 100, 0),
(1177440, 16, 2236.65, 5265.97, 9.08925, 0, 0, 0, 0, 100, 0),
(1177440, 17, 2226.8, 5269.61, 7.16322, 0, 0, 0, 0, 100, 0),
(1177440, 18, 2209.85, 5275.66, 10.8121, 0, 0, 0, 0, 100, 0),
(1177440, 19, 2208.18, 5268.86, 10.7009, 0, 0, 0, 0, 100, 0),
(1177440, 20, 2203.12, 5252.14, 10.5775, 0, 0, 0, 0, 100, 0),
(1177440, 21, 2192.52, 5236.56, 10.5738, 0, 0, 0, 0, 100, 0),
(1177440, 22, 2176.46, 5233.64, 11.5804, 0, 0, 0, 0, 100, 0),
(1177440, 23, 2160.99, 5234.54, 17.9753, 0, 0, 0, 0, 100, 0),
(1177440, 24, 2137.26, 5245.75, 19.4465, 0, 0, 0, 0, 100, 0),
(1177440, 25, 2111.31, 5256.28, 19.4465, 0, 0, 0, 0, 100, 0),
(1177440, 26, 2087.92, 5269.58, 19.4465, 0, 0, 0, 0, 100, 0),
(1177440, 27, 2087.94, 5290.85, 19.4495, 0, 0, 0, 0, 100, 0),
(1177440, 28, 2092.85, 5313.56, 19.4495, 0, 5000, 0, 0, 100, 0),
(1177440, 29, 2091.17, 5300.7, 19.4495, 0, 22000, 0, 0, 100, 0),
(1177440, 30, 2086.89, 5273.04, 19.4482, 0, 0, 0, 0, 100, 0),
(1177440, 31, 2108.96, 5257.42, 19.4467, 0, 0, 0, 0, 100, 0),
(1177440, 32, 2138.17, 5245.65, 19.4467, 0, 0, 0, 0, 100, 0),
(1177440, 33, 2157.61, 5237.7, 19.0772, 0, 0, 0, 0, 100, 0),
(1177440, 34, 2177, 5234.21, 11.426, 0, 0, 0, 0, 100, 0),
(1177440, 35, 2194.04, 5236.1, 10.5729, 0, 0, 0, 0, 100, 0),
(1177440, 36, 2202.59, 5250.43, 10.5729, 0, 0, 0, 0, 100, 0),
(1177440, 37, 2210.88, 5273.46, 10.814, 0, 0, 0, 0, 100, 0),
(1177440, 38, 2228.14, 5268.23, 7.1635, 0, 0, 0, 0, 100, 0),
(1177440, 39, 2245.5, 5263.03, 11.7909, 0, 0, 0, 0, 100, 0),
(1177440, 40, 2264.42, 5255.25, 7.16331, 0, 0, 0, 0, 100, 0),
(1177440, 41, 2281.83, 5245.22, 11.317, 0, 0, 0, 0, 100, 0),
(1177440, 42, 2280.49, 5237.07, 11.4029, 0, 0, 0, 0, 100, 0),
(1177440, 43, 2269.62, 5227.42, 11.2536, 0, 0, 0, 0, 100, 0),
(1177440, 44, 2261.16, 5215.02, 11.2106, 0, 0, 0, 0, 100, 0),
(1177440, 45, 2256.64, 5205.68, 11.2277, 0, 0, 0, 0, 100, 0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (1080, 1081);

DELETE FROM `creature_formations` WHERE `leaderGUID`=117744;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(117744, 117744, 0, 0, 7, 0, 0),
(117744, 117793, 7, 359, 7, 0, 0);

DELETE FROM `creature_text` WHERE `CreatureID` IN (27010, 27364);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(27010, 0, 0, 'All these folks are keeping me busy.  Take this horse over to your stables.', 12, 7, 100, 396, 0, 0, 26522, 'Celidh Aletracker to Jimmy the Stable Boy'),
(27364, 0, 0, 'Hey Celidh!  Do you have any pets you want me to take over to the stable?', 12, 7, 100, 0, 0, 0, 26428, 'Jimmy the Stable Boy'),
(27364, 1, 0, 'Let''s go boy.', 12, 7, 100, 0, 0, 0, 26432, 'Jimmy the Stable Boy'),
(27364, 2, 0, 'If I were king, I''d have a horse like you.  I''d make sure you didn''t get lost, and I bet you''d make sure I never got lost.', 12, 7, 100, 0, 0, 0, 26478, 'Jimmy the Stable Boy'),
(27364, 3, 0, 'We''d be best friends.  I bet me and Anduin would also be best friends, too.  Friends are important.  ', 12, 7, 100, 0, 0, 0, 26479, 'Jimmy the Stable Boy'),
(27364, 4, 0, 'I''ll take you to some other horses.  You probably miss being around other horses.  They can be your friend too.', 12, 7, 100, 0, 0, 0, 26486, 'Jimmy the Stable Boy');
