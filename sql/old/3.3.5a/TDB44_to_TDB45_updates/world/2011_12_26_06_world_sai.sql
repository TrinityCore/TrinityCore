-- [Q] [A/H] Did You Lose This?
-- Trenton Lighthammer SAI
SET @ENTRY := 7804;
SET @QUEST := 3321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `quest_end_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,@QUEST,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Trenton Lighthammer - On Quest Complete - Say Line 0"),
(@ENTRY,0,1,0,19,0,100,0,@QUEST,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Trenton Lighthammer - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trenton Lighthammer - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,1,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trenton Lighthammer - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,2,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trenton Lighthammer - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,3,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trenton Lighthammer - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,4,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trenton Lighthammer - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,5,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.842743,"Trenton Lighthammer - On Script - Face Forge"),
(@ENTRY*100,9,6,0,0,0,100,0,1000,1000,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trenton Lighthammer - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,7,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trenton Lighthammer - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,8,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trenton Lighthammer - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,9,0,0,0,100,0,2000,2000,0,0,15,@QUEST,0,0,0,0,0,7,0,0,0,0,0,0,0,"Trenton Lighthammer - On Script - Quest Credit");
-- Texts
DELETE FROM `db_script_string` WHERE `entry`=2000000076;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Hear ye, denizens of Tanaris! Let it be known $N is an exalted member of the Mithril Order. A blacksmith of honor, dedication, and infinite patience. Three cheers for $N!",14,0,100,0,0,0,"Trenton Lighthammer");
