-- 
-- Razormaw SAI
SET @ENTRY := 17592;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,3000,5000,11,31279,64,0,0,0,0,2,0,0,0,0,0,0,0,"Razormaw - In Combat - Cast 'Swipe'"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,6000,8000,11,8873,64,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - In Combat - Cast 'Flame Breath'"),
(@ENTRY,0,2,0,2,0,50,1,0,50,0,0,11,14100,64,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - Between 0-50% Health - Cast 'Terrifying Roar' (No Repeat)"),
(@ENTRY,0,3,11,11,0,100,0,0,0,0,0,53,1,17592,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - On Respawn - Start Waypoint"),
(@ENTRY,0,4,18,40,0,100,0,10,17592,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - On Waypoint 10 Reached - Remove Flag Immune To Players"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - On Respawn - Set Active On"),
(@ENTRY,0,14,18,40,0,100,0,9,17592,0,0,91,2,3,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - On Waypoint 9 Reached - Remove Flag Hover"),
(@ENTRY,0,18,0,61,0,100,0,10,17592,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - On Waypoint 10 Reached - Set Reactstate Aggressive"),
(@ENTRY,0,19,0,40,0,100,0,11,17592,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - On Waypoint 11 Reached - Set Home Position"),
(@ENTRY,0,20,23,40,0,100,0,1,17592,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - On Waypoint 1 Reached - Set Flag Immune To Players"),
(@ENTRY,0,21,22,25,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - On Reset - Set Reactstate Aggressive"),
(@ENTRY,0,22,0,61,0,100,0,0,0,0,0,91,2,3,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - On Reset - Remove Flag Hover"),
(@ENTRY,0,23,0,61,0,100,0,1,17592,0,0,90,2,3,0,0,0,0,1,0,0,0,0,0,0,0,"Razormaw - On Waypoint 1 Reached - Set Flag Hover");

UPDATE `waypoints` SET `position_z` = 96.5391 WHERE `entry`=17592 AND `pointid`=11;
