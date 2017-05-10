-- 
-- DB/SAI: Update Moonglade
-- Lunar Festival Sentinel SAI
SET @ENTRY := 15961;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lunar Festival Sentinel - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,18396,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lunar Festival Sentinel - On Aggro - Cast 'Dismounting Blast' (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,13600,14500,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lunar Festival Sentinel - Within 0-5 Range - Cast 'Mortal Strike'"),
(@ENTRY,0,3,0,0,0,100,0,2000,4500,12000,20000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lunar Festival Sentinel - In Combat - Cast 'Snap Kick'"),
(@ENTRY,0,4,0,0,0,100,0,8000,8000,24000,28000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lunar Festival Sentinel - In Combat - Cast 'Incapacitating Shout'");

-- Moonglade Warden SAI
SET @ENTRY := 11822;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Moonglade Warden - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,13600,14500,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moonglade Warden - Within 0-5 Range - Cast 'Cleave'");
