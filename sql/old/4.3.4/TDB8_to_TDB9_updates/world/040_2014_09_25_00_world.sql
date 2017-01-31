-- Converted Sentry SAI
SET @ENTRY := 24981;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName` = '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,63,0,100,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Converted Sentry - Just Summoned - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,61,0,100,1,0,0,0,0,11,45009,0,0,0,0,0,7,0,0,0,0,0,0,0,"Converted Sentry - Just Summoned - Cast Converted Sentry Credit (No Repeat)"),
(@ENTRY,0,2,3,61,0,100,1,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Converted Sentry - Just Summoned - Set random movement (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,41,7500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Converted Sentry - Just Summoned - Cast Despawn In 7500 ms (No Repeat)");
