-- 
-- Pustulating Horror SAI
SET @ENTRY := 10404;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,10000,10000,11,71089,0,0,0,0,0,5,0,0,0,0,0,0,0,"Pustulating Horror - In Combat - Cast 'Bubbling Pus'"),
(@ENTRY,0,1,0,2,0,100,0,0,10,60000,60000,11,71088,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pustulating Horror - Between 0-10% Health - Cast 'Blight Bomb'");
