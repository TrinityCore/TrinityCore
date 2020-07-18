-- Farseer Nobundo
UPDATE `creature` SET `position_z` = -99.245 WHERE `guid` = 67174;
UPDATE `creature` SET `position_z` = -99.245 WHERE `guid` = 67177;
-- Farseer Nobundo SAI
SET @ENTRY := 17204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,17204,1,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,17204,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,2,17204,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,9,17204,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Waypoint 9 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,16,17204,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Waypoint 16 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1720400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.82184,"Farseer Nobundo - On Script - Set Orientation 1,82184"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Script - Remove Flag Standstate Kneel");

-- Actionlist SAI
SET @ENTRY := 1720401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.73819,"Farseer Nobundo - On Script - Set Orientation 5,73819"),
(@ENTRY,9,2,0,0,0,100,0,19000,19000,0,0,11,32991,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Script - Cast 'Nature Cast Visual'"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,75,33010,0,0,0,0,0,10,67174,18814,0,0,0,0,0,"Farseer Nobundo - On Script - Add Aura 'Windfury Impact Visual'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,75,33010,0,0,0,0,0,10,67177,18814,0,0,0,0,0,"Farseer Nobundo - On Script - Add Aura 'Windfury Impact Visual'"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,5,273,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farseer Nobundo - On Script - Play Emote 273");

SET @PATH := 17204;
DELETE FROM `waypoints` WHERE `entry`=17204;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@PATH,1,-3844.04,-11380.4,-103.781, 'Farseer Nobundo'),
(@PATH,2,-3845.13,-11376.6,-103.779, 'Farseer Nobundo'),
(@PATH,3,-3843.57,-11383.7,-103.789, 'Farseer Nobundo'),
(@PATH,4,-3841.76,-11389.6,-103.79, 'Farseer Nobundo'),
(@PATH,5,-3837.74,-11394.3,-103.758, 'Farseer Nobundo'),
(@PATH,6,-3831.88,-11397.2,-104.576, 'Farseer Nobundo'),
(@PATH,7,-3821.25,-11396.5,-104.446, 'Farseer Nobundo'),
(@PATH,8,-3810.23,-11396,-104.317, 'Farseer Nobundo'),
(@PATH,9,-3804.58,-11397,-104.254, 'Farseer Nobundo'),
(@PATH,10,-3809.89,-11396.1,-104.314, 'Farseer Nobundo'),
(@PATH,11,-3821.03,-11396.5,-104.445, 'Farseer Nobundo'),
(@PATH,12,-3831.71,-11397.2,-104.573, 'Farseer Nobundo'),
(@PATH,13,-3837.76,-11394.4,-103.761, 'Farseer Nobundo'),
(@PATH,14,-3841.95,-11389.5,-103.791, 'Farseer Nobundo'),
(@PATH,15,-3843.63,-11383.7,-103.79, 'Farseer Nobundo'),
(@PATH,16,-3844.04,-11380.4,-103.781, 'Farseer Nobundo');
