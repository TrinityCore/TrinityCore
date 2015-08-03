-- Terenthis SAI
SET @ENTRY := 3693;
SET @QUEST := 986;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `quest_end_scripts` WHERE `id`=993; -- For some reason this entry was different..
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Start quest
(@ENTRY,0,0,0,19,0,100,0,@QUEST,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,12,6086,1,25000,0,0,0,8,0,0,0,6435.25,368.004,13.9412,1.09956,"Terenthis - On Script - Summon Auberdine Sentinel"),
(@ENTRY*100,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 0"),
(@ENTRY*100,9,2,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 1"),
(@ENTRY*100,9,3,0,0,0,100,0,9000,9000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 2"),
-- End quest
(@ENTRY,0,1,0,20,0,100,0,@QUEST,0,0,0,80,@ENTRY*100+1,0,2,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Quest Finish - Run Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,12,3695,1,50000,0,0,0,8,0,0,0,6435.25,368.004,13.9412,1.09956,"Terenthis - On Script - Summon Grimclaw"),
(@ENTRY*100+1,9,1,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 3"),
(@ENTRY*100+1,9,2,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 4"),
(@ENTRY*100+1,9,3,0,0,0,100,0,9000,9000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 5"),
(@ENTRY*100+1,9,4,0,0,0,100,0,11000,11000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 6"),
(@ENTRY*100+1,9,5,0,0,0,100,0,14000,14000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 7");
-- Texts
DELETE FROM `db_script_string` WHERE `entry` IN (2000000009,2000000010,2000000011,2000000050,2000000051,2000000052,2000000053,2000000054);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"What is happening?",12,0,0,0,0,0,"Terenthis"),
(@ENTRY,1,0,"Volcor needs help?",12,0,0,0,0,0,"Terenthis"),
(@ENTRY,2,0,"All right, I shall find people to help him.",12,0,0,0,0,0,"Terenthis"),

(@ENTRY,3,0,"Hello Grimclaw.",12,0,0,0,0,0,"Terenthis"),
(@ENTRY,4,0,"What is happening?",12,0,0,0,0,0,"Terenthis"),
(@ENTRY,5,0,"Volcor needs help?",12,0,0,0,0,0,"Terenthis"),
(@ENTRY,6,0,"You know where he is?",12,0,0,0,0,0,"Terenthis"),
(@ENTRY,7,0,"Well, ok. I am sending people. We will need to find and help him!",12,0,0,0,0,0,"Terenthis");

-- Grimclaw SAI
SET @ENTRY := 3695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,101,5000,5000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimclaw - Emote Receive 'Wave' - Emote Line 0");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Grimclaw growls in your direction before taking time to sniff you.",16,0,0,0,0,0,"Grimclaw");
