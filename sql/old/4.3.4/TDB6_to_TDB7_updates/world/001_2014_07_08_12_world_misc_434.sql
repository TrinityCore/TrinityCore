-- Chief Hawkwind SAI For Quest 24861 "Last Rites, First Rites" 4XX
SET @ENTRY   := 2981; -- NPC entry
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY*100; -- delete bad `source_type`=0 from previous fix old/updates_01/062_sai.sql
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,24861,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Hawkwind - On Quest 24861 Accept - Run Script'),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Hawkwind - Script - say 0'),
(@ENTRY*100,9,1,0,0,0,100,0,6000,6000,6000,6000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Hawkwind - Script - say 1'),
(@ENTRY*100,9,2,0,0,0,100,0,8000,8000,8000,8000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Hawkwind - Script - say 2'),
(@ENTRY*100,9,3,0,0,0,100,0,7000,7000,7000,7000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Hawkwind - Script - say 3'),
(@ENTRY*100,9,4,61,0,0,100,0,0,0,0,0,33,38438,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Chief Hawkwind - give credit');
