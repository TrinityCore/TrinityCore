-- DB/Creature: Taleris Dawngazer - Emoteevent
DELETE FROM `waypoints` WHERE `entry`=17015;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(17015,1,-650.434021,4136.919922,64.620346),
(17015,2,-649.897,4149.45,64.13),
(17015,3,-650.945,4153.25,64.3724),
(17015,4,-653.408,4159.69,65.9067),
(17015,5,-649.211,4169.54,67.9885),
(17015,6,-647.255,4172.52,68.3677),
(17015,7,-646.951,4176.908,68.51362),
(17015,8,-653.285,4163.94,67.01),
(17015,9,-651.272,4154.21,64.553),
(17015,10,-649.733,4147.03,64.231),
(17015,11,-650.434021,4136.919922,64.620346);

-- Taleris Dawngazer SAI
SET @ENTRY := 17015;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,17015,1,0,0,0,1,0,0,0,0,0,0,0,"Taleris Dawngazer - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,7,17015,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Taleris Dawngazer - On Waypoint 7 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1701500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,"On Script - Play Emote 2"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,10,11,7,6,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Random Emote (11, 7, 6)"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,10,7,0,11,6,0,0,19,17046,20,0,0,0,0,0,"On Script - Play Random Emote (7, 0, 11, 6)"),
(@ENTRY,9,4,0,0,0,100,0,4000,4000,0,0,10,11,6,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Random Emote (11, 6)"),
(@ENTRY,9,5,0,0,0,100,0,6000,6000,0,0,10,7,11,6,0,0,0,19,17046,20,0,0,0,0,0,"On Script - Play Random Emote (7, 11, 6)");
