-- Plague Scientist SAI
SET @ENTRY := 37023;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,23000,24000,11,71103,0,0,0,0,0,6,0,0,0,0,0,0,0,"Plague Scientist - In Combat - Cast 'Combobulating Spray'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,5000,6000,11,73079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plague Scientist - In Combat - Cast 'Plague Blast'"),
(@ENTRY,0,2,0,0,0,100,0,9000,10000,25000,26000,11,69871,0,0,0,0,0,9,0,0,30,0,0,0,0,"Plague Scientist - In Combat - Cast 'Plague Stream'"),
(@ENTRY,0,3,0,1,0,100,0,2000,3000,10000,10000,11,69871,0,0,0,0,0,9,10404,0,10,0,0,0,0,"Plague Scientist - Out of Combat - Cast 'Plague Stream'");
