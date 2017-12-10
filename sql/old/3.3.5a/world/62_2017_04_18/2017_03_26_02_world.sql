-- Improved Land Mine SAI
SET @ENTRY := 29475;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Improved Land Mine - On Reset - Start Random Movement"),
(@ENTRY,0,1,2,60,0,100,0,0,0,1000,1000,11,54537,0,0,0,0,0,1,0,0,0,0,0,0,0,"Improved Land Mine - On Update - Cast 'Detonation'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,1000,1000,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Improved Land Mine - On Update - Despawn In 500 ms"),
(@ENTRY,0,3,0,5,0,100,0,0,0,0,29618,33,29618,0,0,0,0,0,21,50,0,0,0,0,0,0,"Improved Land Mine - On Killed Unit - Update Quest Kill Credit for 'A Delicate Touch' or 'Overstock'"),
(@ENTRY,0,4,0,5,0,100,0,0,0,0,29619,33,29618,0,0,0,0,0,21,50,0,0,0,0,0,0,"Improved Land Mine - On Killed Unit - Update Quest Kill Credit for 'A Delicate Touch' or 'Overstock'");
--
