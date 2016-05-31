-- Enraged Foulweald SAI
SET @ENTRY := 12921;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6821,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Foulweald - On Respawn - Cast 6821"),
(@ENTRY,0,1,2,8,0,100,1,20746,0,0,0,11,20786,1,0,0,0,0,7,0,0,0,0,0,0,0,"Enraged Foulweald - On Spellhit By 20746 - Cast 20786"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Foulweald - On Spellhit By 20746 - Say Line 0");
