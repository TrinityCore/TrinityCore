-- [Q] [H] Hinott's Assistance
-- Serge Hinott SAI
SET @ENTRY := 2391;
SET @QUEST := 2480;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Serge Hinott - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4.33,-900.68,57.54,1.54,"Serge Hinott - On Script - Move To Pos"),
(@ENTRY*100,9,1,0,0,0,100,0,18000,18000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Serge Hinott - On Script - Say Line 0"),
(@ENTRY*100,9,2,0,0,0,100,0,10000,10000,0,0,15,@QUEST,0,0,0,0,0,7,0,0,0,0,0,0,0,"Serge Hinott - On Script - Quest Credit"),
(@ENTRY*100,9,3,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4.66,-903.92,57.54,3.48,"Serge Hinott - On Script - Move To Pos");
-- Text
DELETE FROM `db_script_string` WHERE `entry`=2000000026;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Whoops!",12,0,100,113,0,0,"Serge Hinott");
