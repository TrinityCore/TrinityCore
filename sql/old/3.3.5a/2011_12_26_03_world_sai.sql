-- [Q] [A/H] Freed from the Hive
-- Zukk'ash Pod SAI
SET @ENTRY := 164954;
SET @QUEST := 4265;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,19,0,100,0,@QUEST,0,0,0,12,9546,1,25000,0,0,0,8,0,0,0,-5314.81,430.89,11.79,3.46,"Zukk'ash Pod - On Quest Accept - Summon Raschal the Courier");
-- Raschal the Courier SAI
SET @ENTRY := 9546;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Raschal the Courier - Just Summoned - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Say Line 0"),
(@ENTRY*100,9,1,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Say Line 1"),
(@ENTRY*100,9,2,0,0,0,100,0,8000,8000,0,0,15,@QUEST,0,0,0,0,7,0,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Quest Credit"),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Forced Despawn");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Oh man, I thought I was dead for sure. Ugh... still dizzy...",12,0,100,0,0,0,"Raschal the Courier"),
(@ENTRY,1,0,"I can get back to the Stronghold on my own, I think. Now that you bought me some time, I should be able to stealth out of here. Who ever you are... thank you. May Elune bless you always!",12,0,100,0,0,0,"Raschal the Courier");
