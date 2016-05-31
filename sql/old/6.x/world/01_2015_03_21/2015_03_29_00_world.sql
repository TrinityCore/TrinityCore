-- Calming the Kodo
-- Enraged Kodo SAI
SET @ENTRY := 36094;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,18000,22000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Kodo - In Combat - Cast 'Trample'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,18501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Kodo - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,4,38,0,100,0,1,0,0,0,29,1,0,36079,1,1,0,19,36079,30,0,0,0,0,0,"Enraged Kodo - On Data Set 1 0 - Start Follow Closest Creature 'Enraged Kodo KC Bunny'"),
(@ENTRY,0,3,5,65,0,100,0,0,0,0,0,86,68331,0,18,35,0,0,1,20,0,0,0,0,0,0,"Enraged Kodo - On Follow Complete - Cross Cast 'Kill Credit'"),
(@ENTRY,0,4,0,61,0,100,0,1,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Kodo - On Data Set 1 0 - Set Reactstate Passive"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Kodo - On Follow Complete - Play Emote 33"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,12,36113,3,120000,0,0,0,1,0,0,0,0,0,0,0,"Enraged Kodo - On Follow Complete - Summon Creature 'Pacified Kodo'"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Kodo - On Follow Complete - Despawn In 1 ms");

-- Pacified Kodo SAI
SET @ENTRY := 36113;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,46,30,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pacified Kodo - On Just Summoned - Move Forward 30 Yards"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pacified Kodo - On Just Summoned - Despawn In 5000 ms");

-- Enraged Kodo KC Bunny SAI
SET @ENTRY := 36079;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,45,1,0,0,0,0,0,19,36094,30,0,0,0,0,0,"Enraged Kodo KC Bunny - On Just Summoned - Set Data 1 0");
