SET @ENTRY_FIRJUS := 24213;
SET @ENTRY_JLARBORN := 24215;
SET @ENTRY_YORUS := 24214;
SET @ENTRY_OLUF := 23931;
SET @QUEST := 11300;

-- Summon Firjus on quest accept - this starts the quest
UPDATE `quest_template` SET `StartScript`=@QUEST WHERE `entry`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
INSERT INTO `quest_start_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@QUEST,3,10,@ENTRY_FIRJUS,300000,0,799.653931,-4718.678711,-96.236053,4.992353);

-- Firjus, Jlarborn, Yorus and Oluf SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ENTRY_FIRJUS,@ENTRY_JLARBORN,@ENTRY_YORUS,@ENTRY_OLUF);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@ENTRY_FIRJUS,@ENTRY_JLARBORN,@ENTRY_YORUS,@ENTRY_OLUF);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY_FIRJUS,@ENTRY_JLARBORN,@ENTRY_YORUS,@ENTRY_OLUF) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY_FIRJUS,0,0,0,0,0,100,0,3000,6000,12000,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Firjus - In Combat - Cleave'),
(@ENTRY_FIRJUS,0,1,0,0,0,100,0,10000,10000,10000,10000,11,43348,0,0,0,0,0,2,0,0,0,0,0,0,0,'Firjus - In Combat - Head Crush'),
(@ENTRY_FIRJUS,0,2,0,6,0,100,1,0,0,0,0,12,@ENTRY_JLARBORN,1,300000,0,0,0,8,0,0,0,799.653931,-4718.678711,-96.236053,4.992353,'Firjus - On Death - Summon Jlarborn'),
(@ENTRY_JLARBORN,0,0,0,0,0,100,1,1000,2000,0,0,11,19131,0,0,0,0,0,2,0,0,0,0,0,0,0,'Jlarborn - In Combat - Shield Charge'),
(@ENTRY_JLARBORN,0,1,0,0,0,100,0,4000,5000,15000,16000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jlarborn - In Combat - Shield Block'),
(@ENTRY_JLARBORN,0,2,0,0,0,100,0,7000,8000,18000,19000,11,38233,0,0,0,0,0,2,0,0,0,0,0,0,0,'Jlarborn - In Combat - Shield Bash'),
(@ENTRY_JLARBORN,0,3,0,0,0,100,0,10000,10000,10000,10000,11,8374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Jlarborn - In Combat - Arcing Smash'),
(@ENTRY_JLARBORN,0,4,0,6,0,100,1,0,0,0,0,12,@ENTRY_YORUS,1,300000,0,0,0,8,0,0,0,799.653931,-4718.678711,-96.236053,4.992353,'Jlarborn - On Death - Summon Yorus'),
(@ENTRY_YORUS,0,0,0,0,0,100,0,3000,6000,12000,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Yorus - In Combat - Cleave'),
(@ENTRY_YORUS,0,1,0,0,0,100,0,8000,9000,18000,19000,11,41057,0,0,0,0,0,1,0,0,0,0,0,0,0,'Yorus - In Combat - Whirlwind'),
(@ENTRY_YORUS,0,2,0,6,0,100,1,0,0,0,0,12,@ENTRY_OLUF,1,300000,0,0,0,8,0,0,0,799.653931,-4718.678711,-96.236053,4.992353,'Yorus - On Death - Summon Oluf'),
(@ENTRY_OLUF,0,0,0,0,0,100,0,3000,6000,12000,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Oluf - In Combat - Cleave'),
(@ENTRY_OLUF,0,1,0,0,0,100,0,8000,9000,28000,29000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Oluf - In Combat - Demoralizing Shout'),
(@ENTRY_OLUF,0,2,0,0,0,100,0,7000,7000,21000,21000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,'Oluf - In Combat - Net'),
(@ENTRY_OLUF,0,3,0,0,0,100,1,1000,1000,0,0,11,42870,0,0,0,0,0,2,0,0,0,0,0,0,0,'Oluf - In Combat - Throw Harpoon'),
(@ENTRY_OLUF,0,4,0,0,0,100,0,10000,10000,10000,10000,11,41057,0,0,0,0,0,1,0,0,0,0,0,0,0,'Oluf - In Combat - Whirlwind'),
(@ENTRY_OLUF,0,5,0,6,0,100,1,0,0,0,0,50,186640,90000,0,0,0,0,8,0,0,0,799.653931,-4718.678711,-96.236053,4.992353,'Oluf - On Death - Summon Ancient Cipher');
