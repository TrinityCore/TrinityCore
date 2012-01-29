-- [Q] [H] Teron Gorefiend, I am...
-- Ancient Shadowmoon Spirit SAI
SET @ENTRY := 21797;
SET @QUEST := 10639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `Id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Ancient Shadowmoon Spirit - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ancient Shadowmoon Spirit - On Script - Say Line 0"),
(@ENTRY*100,9,1,0,0,0,100,0,5000,5000,0,0,12,21877,1,300000,0,0,0,8,0,0,0,-4536.58,1028.76,8.8266,3.72963,"Ancient Shadowmoon Spirit - On Script - Summon Karsius the Ancient Watcher");
-- Text
DELETE FROM `db_script_string` WHERE `entry`=2000000031;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Your body is mine! Our fates are forever intertwined!",14,0,100,0,0,0,"Ancient Shadowmoon Spirit");
