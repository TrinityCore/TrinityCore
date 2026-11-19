-- [Q] [A/H] The Torch of Retribution
-- Kalaran Windblade SAI
SET @ENTRY := 8479;
SET @QUEST := 3453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,10000,10000,0,0,11,12511,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Cast Torch Combine"),
(@ENTRY*100,9,1,0,0,0,100,0,8000,8000,0,0,11,12511,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Cast Torch Combine"),
(@ENTRY*100,9,2,0,0,0,100,0,7000,7000,0,0,11,12511,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Cast Torch Combine"),
(@ENTRY*100,9,3,0,0,0,100,0,10000,10000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Say Line 0"),
(@ENTRY*100,9,4,0,0,0,100,0,5000,5000,0,0,11,12511,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Cast Torch Combine"),
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,0,0,70,0,0,0,0,0,0,14,24166,149410,0,0,0,0,0,"Kalaran Windblade - On Script - Respawn Light of Retribution (GO)"),
(@ENTRY*100,9,6,0,0,0,100,0,2000,2000,0,0,70,0,0,0,0,0,0,14,16762,149047,0,0,0,0,0,"Kalaran Windblade - On Script - Respawn Torch of Retribution (GO)"),
(@ENTRY*100,9,7,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Say Line 1"),
(@ENTRY*100,9,8,0,0,0,100,0,1000,1000,0,0,15,@QUEST,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Quest Credit");
-- Text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000019,2000000044);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Be patient, $N. The torch is almost done.",12,0,100,0,0,0,"Kalaran Windblade"),
(@ENTRY,1,0,"It is done...",12,0,100,0,0,0,"Kalaran Windblade");
