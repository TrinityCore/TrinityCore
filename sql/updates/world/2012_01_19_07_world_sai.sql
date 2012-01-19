-- [Q] [A/H] Making Sense of It
-- J.D. Collie SAI
SET @ENTRY := 9117;
SET @QUEST := 4321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,6000,6000,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Emote ONESHOT_QUESTION"),
(@ENTRY*100,9,1,0,0,0,100,0,4000,4000,0,0,5,22,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Emote ONESHOT_SHOUT"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 0"),
(@ENTRY*100,9,3,0,0,0,100,0,10000,10000,0,0,15,@QUEST,0,0,0,0,7,0,0,0,0,0,0,0,0,"J.D. Collie - On Script - Quest Credit");
-- Text
DELETE FROM `db_script_string` WHERE `entry`=2000000030;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"This makes sense!",12,0,100,0,0,0,"J.D. Collie");
