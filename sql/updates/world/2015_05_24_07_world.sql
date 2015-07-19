-- Dragonflayer Fanatic
DELETE FROM `waypoints` WHERE `entry`=26553;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(26553,1,467.5089,-325.5417,104.0859),
(26553,2,483.179,-325.046,104.0471);

-- Dragonflayer Fanatic SAI
SET @GUID := -126160;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26553;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,53,0,26553,1,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fanatic - On Reset - Start Waypoint"),
(@GUID,0,1,0,40,0,100,0,1,26553,0,0,80,12616000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fanatic - On Waypoint 1 Reached - Run Script"),
(@GUID,0,2,0,40,0,100,0,2,26553,0,0,80,12616001,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fanatic - On Waypoint 2 Reached - Run Script"),
(@GUID,0,3,0,1,1,100,0,2000,2000,2000,2000,10,274,25,5,22,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fanatic - Out of Combat - Play Random Emote (274, 25, 5, 22)");

-- Actionlist SAI
SET @ENTRY := 12616000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,35000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Event Phase 1"),
(@ENTRY,9,2,0,0,0,100,0,35000,35000,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Event Phase 2");

-- Actionlist SAI
SET @ENTRY := 12616001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.986479,"On Script - Set Orientation 5,986479");
