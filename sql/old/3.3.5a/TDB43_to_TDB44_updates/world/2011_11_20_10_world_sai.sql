-- [Q] [A/H] The Skettis Offensive
-- Defender Grashna SAI
SET @ENTRY := 22373;
SET @QUEST := 10879;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0,`SpecialFlags`=2 WHERE `entry`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Defender Grashna - On Quest Accept - Run Script"),
-- Wave one - no text
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,12,22376,1,60000,0,0,0,8,0,0,0,-1626.12,5402.47,-42.31,2.08131,"Defender Grashna - On Script - Summon Minion of Terokk"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,12,22376,1,60000,0,0,0,8,0,0,0,-1626.12,5402.47,-42.31,2.08131,"Defender Grashna - On Script - Summon Minion of Terokk"),
-- Wave two
(@ENTRY*100,9,2,0,0,0,100,0,30000,30000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defender Grashna - On Script - Say Line 0"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,12,22376,1,60000,0,0,0,8,0,0,0,-1626.12,5402.47,-42.31,2.08131,"Defender Grashna - On Script - Summon Minion of Terokk"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,12,22376,1,60000,0,0,0,8,0,0,0,-1626.12,5402.47,-42.31,2.08131,"Defender Grashna - On Script - Summon Minion of Terokk"),
-- Wave three
(@ENTRY*100,9,5,0,0,0,100,0,30000,30000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defender Grashna - On Script - Say Line 1"),
(@ENTRY*100,9,6,0,0,0,100,0,0,0,0,0,12,22376,1,60000,0,0,0,8,0,0,0,-1626.12,5402.47,-42.31,2.08131,"Defender Grashna - On Script - Summon Minion of Terokk"),
(@ENTRY*100,9,7,0,0,0,100,0,0,0,0,0,12,22376,1,60000,0,0,0,8,0,0,0,-1626.12,5402.47,-42.31,2.08131,"Defender Grashna - On Script - Summon Minion of Terokk"),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,12,22376,1,60000,0,0,0,8,0,0,0,-1626.12,5402.47,-42.31,2.08131,"Defender Grashna - On Script - Summon Minion of Terokk"),
-- Wave four
(@ENTRY*100,9,9,0,0,0,100,0,30000,30000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defender Grashna - On Script - Say Line 2"),
(@ENTRY*100,9,10,0,0,0,100,0,0,0,0,0,12,22375,1,60000,0,0,0,8,0,0,0,-1626.12,5402.47,-42.31,2.08131,"Defender Grashna - On Script - Summon Avatar of Terokk"),
(@ENTRY,0,1,0,38,0,100,0,1,1,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defender Grashna - On Data Set - Say Line 3");
-- Text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000022,2000000023,2000000024,2000000025);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"More Minions of Terokk are coming!",12,0,100,0,0,0,"Defender Grashna"),
(@ENTRY,1,0,"The invaders persist! Hold them off!",12,0,100,0,0,0,"Defender Grashna"),
(@ENTRY,2,0,"An Avatar of Terokk!! To arms!",12,0,100,0,0,0,"Defender Grashna"),
(@ENTRY,3,0,"The Avatar of Terokk has been defeated! Death to Terokk! Death to Skettis!",12,0,100,0,0,0,"Defender Grashna");
-- Minion of Terokk SAI
SET @ENTRY := 22376;
SET @SPELL_SCREECH := 38021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-1647.329956,5443.410156,-40.911999,2.254425,"Minion of Terokk - Just Summoned - Move To Pos"),
(@ENTRY,0,1,0,0,0,100,1,3000,4000,8000,8000,11,@SPELL_SCREECH,0,0,0,0,0,2,0,0,0,0,0,0,0,"Minion of Terokk - In Combat - Cast Terrifying Screech");
-- Avatar of Terokk SAI
SET @ENTRY := 22375;
SET @SPELL_CHARGE := 24193;
SET @SPELL_FEATHER_BURST := 39068;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-1641.118652,5436.648926,-43.344521,0.803601,"Avatar of Terokk - Just Summoned - Move To Pos"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-1641.118652,5436.648926,-43.344521,0.803601,"Avatar of Terokk - Just Summoned - Move To Pos"),
(@ENTRY,0,2,3,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,6546,0,0,0,0,0,0,"Avatar of Terokk - On Death - Set Data Defender Grashna"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,15,@QUEST,0,0,0,0,0,7,0,0,0,0,0,0,0,"Avatar of Terokk - On Death - Quest Credit"),
(@ENTRY,0,4,0,4,0,100,1,0,0,0,0,11,@SPELL_CHARGE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avatar of Terokk - On Aggro - Cast Charge"),
(@ENTRY,0,5,0,0,0,100,0,6000,9000,11000,14000,11,@SPELL_FEATHER_BURST,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avatar of Terokk - In Combat - Cast Feather Burst");
