-- Remove from quest_end_scripts
DELETE FROM `quest_end_scripts` WHERE `id` IN (12657,12597,10988,10850,10447,9565);

-- Convert quest_end_script "12657" to SAI
-- Indexes:
SET @DARION_MORGRAINE := 28444;
SET @SCRIPT := @DARION_MORGRAINE * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@DARION_MORGRAINE;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@DARION_MORGRAINE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DARION_MORGRAINE AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DARION_MORGRAINE,0,0,0,20,0,100,0,12657,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Highlord Darion Morgraine - On quest 12657 rewarded - Start action list'),
(@DARION_MORGRAINE,0,1,0,1,0,100,0,60000,90000,60000,90000,4,12893,1,0,0,0,0,0,0,0,0,0,0,0,0, 'Highlord Darion Morgraine - OOC - Play sound'),
(@SCRIPT,9,0,0,0,0,100,0,16000,16000,0,0,5,22,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Highlord Darion Morgraine - Action 0 - Play emote 22'),
(@SCRIPT,9,1,0,0,0,100,0,0,0,0,0,12,28487,3,46000,0,0,0,8,0,0,0,2465.47,-5567.3,372.16,1.64, 'Highlord Darion Morgraine - Action 1 - Summon'),
(@SCRIPT,9,2,0,0,0,100,0,0,0,0,0,12,28487,3,46000,0,0,0,8,0,0,0,2434.52,-5588.56,372.16,3.26, 'Highlord Darion Morgraine - Action 2 - Summon'),
(@SCRIPT,9,3,0,0,0,100,0,0,0,0,0,12,28487,3,46000,0,0,0,8,0,0,0,2455.59,-5618.32,372.16,4.59, 'Highlord Darion Morgraine - Action 3 - Summon'),
(@SCRIPT,9,4,0,0,0,100,0,0,0,0,0,12,28487,3,46000,0,0,0,8,0,0,0,2439.31,-5608.69,372.16,3.77, 'Highlord Darion Morgraine - Action 4 - Summon'),
(@SCRIPT,9,5,0,0,0,100,0,0,0,0,0,12,28487,3,46000,0,0,0,8,0,0,0,2486.72,-5598.66,372.16,6.02, 'Highlord Darion Morgraine - Action 5 - Summon'),
(@SCRIPT,9,6,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Highlord Darion Morgraine - Action 6 - Say line 0'),
(@SCRIPT,9,7,0,0,0,100,0,16000,16000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Highlord Darion Morgraine - Action 7 - Say line 1');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000005409,2000005410);
DELETE FROM `creature_text` WHERE `entry`=@DARION_MORGRAINE;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@DARION_MORGRAINE,0,0, '%s calls upon the mighty armies of the Scourge!',42,0,100,1,0,0, 'Highlord Darion Morgraine'),
(@DARION_MORGRAINE,1,0, 'Armies of the Scourge, hear my call! The scarlet apocalypse has begun! Tear this land asunder and leave only death in your wake!',12,0,100,1,0,0, 'Highlord Darion Morgraine');

-- Convert quest_end_script "10988" to SAI
-- Indexes:
SET @Arthorn_Windsong := 22924;
SET @SCRIPT := @Arthorn_Windsong * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Arthorn_Windsong;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Arthorn_Windsong AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Arthorn_Windsong,0,0,0,20,0,100,0,10988,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Captain Brandon - On quest 10988 rewarded - Start script'),
(@SCRIPT,9,0,0,0,0,100,0,30000,30000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arthorn Windsong - Action 0 - Say line 0'),
(@SCRIPT,9,1,0,0,0,100,0,43000,43000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arthorn Windsong - Action 1 - Say line 1'),
(@SCRIPT,9,2,0,0,0,100,0,43000,43000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arthorn Windsong - Action 2 - Play emote 1'),
(@SCRIPT,9,3,0,0,0,100,0,56000,56000,0,0,69,1,0,0,0,0,0,8,0,0,0,3024.32,5511.29,146.051,2.31064, 'Arthorn Windsong - Action 3 - Move to'),
(@SCRIPT,9,4,0,0,0,100,0,17000,17000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arthorn Windsong - Action 4 - Play emote 1'),
(@SCRIPT,9,5,0,0,0,100,0,17000,17000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arthorn Windsong - Action 5 - Say line 2'),
(@SCRIPT,9,6,0,0,0,100,0,11000,11000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arthorn Windsong - Action 6 - Play emote'),
(@SCRIPT,9,7,0,0,0,100,0,11000,11000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arthorn Windsong - Action 7- Say line 3'),
(@SCRIPT,9,8,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arthorn Windsong - Action 8 - Say line 4'),
(@SCRIPT,9,9,0,0,0,100,0,11000,11000,0,0,11,39679,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arthorn Windsong - Action 9 - Cast spell'),
(@SCRIPT,9,10,0,0,0,100,0,10000,10000,0,0,69,0,0,0,0,0,0,8,0,0,0,3044.22,5510.91,146.033,4.654, 'Windsong - Action 10 - Move to pos'),
(@SCRIPT,9,11,0,0,0,100,0,56000,56000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arthorn Windsong - Action 11 - Say line 5');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000073,2000000074,2000000072,2000000071,2000000070,2000000075);
DELETE FROM `creature_text` WHERE `entry`=@Arthorn_Windsong;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Arthorn_Windsong,0,0, 'There''s something else here, too. After a discription of a bloody battle and the downfall of the raven, there''s a prophecy. Anzu will haunt the dreams of his enemies, twisting them to affect a return to this world...',12,0,100,1,0,0, 'Arthorn Windsong'),
(@Arthorn_Windsong,1,0, 'The tablet has the confirmation we need, just as I thought. Now, we have to use this information to draw out and defeat this Anzu before he can do any more damage to the Emerald Dream!',12,0,100,1,0,0, 'Arthorn Windsong'),
(@Arthorn_Windsong,2,0, 'It''s all here... how the raven''s followers captured and subdued the sprints of rivals, trapping them forever within stone statues! The tablet even mentions the raven god''s name -- Anzu. I''d thought it was lost to history!',12,0,100,1,0,0, 'Arthorn Windsong'),
(@Arthorn_Windsong,3,0, 'This is it! This is really it -- the Book of the Raven!',12,0,100,1,0,0, 'Arthorn Windsong'),
(@Arthorn_Windsong,4,0, 'It would''ve taken years to find the Book of the Raven without you, young sparrowhawk. Return to your home in Nagrand with our gratitude.',12,0,100,1,0,0, 'Arthorn Windsong'),
(@Arthorn_Windsong,5,0, 'Since the sparrowhawks have proven such a success in hunting down the raven stones, Watcher Elaira has trained another one to relay my voice at a great distance. He can help us communicate as you investigate the bird spirits revealed in the tablet!',12,0,100,1,0,0, 'Arthorn Windsong');

-- Convert quest_end_script "10850" to SAI
-- Indexes:
SET @Inactive_Fel_Reaver := 22293;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Inactive_Fel_Reaver;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Inactive_Fel_Reaver AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Inactive_Fel_Reaver,0,0,0,20,0,100,0,10850,0,0,0,15,10855,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Inactive Fel Reaver - On quest 10850 rewarded - Call Quest Explored for invoker');

-- Convert quest_end_script "10447" to SAI
-- Indexes:
SET @Toki := 18447;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Toki;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Toki AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Toki,0,0,0,20,0,100,0,10447,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Toki - On quest 10447 rewarded - Say line 0');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry`=2000000062;
DELETE FROM `creature_text` WHERE `entry`=@Toki;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Toki,0,0, 'The threat be over! $N be savin'' us all!',12,0,100,1,0,0, 'Toki');

-- Convert quest_end_script "9565" to SAI
-- Indexes:
SET @Blood_Crystal := 181748;
SET @SCRIPT := @Blood_Crystal * 100;

-- Add SAI support
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@Blood_Crystal;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Blood_Crystal AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Blood_Crystal,1,0,0,20,0,100,0,9565,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Blood Crystal - On quest 9565 rewarded - Start actionlist'),
(@SCRIPT,9,0,0,0,0,100,0,2000,2000,0,0,12,17189,3,180000,0,0,0,8,0,0,0,-3105.36,-12549.2,-1.28,4.6, 'Blood Crystal - Action 0 - Summon'),
(@SCRIPT,9,1,0,0,0,100,0,2000,2000,0,0,12,17189,3,180000,0,0,0,8,0,0,0,-3128.49,-12540.2,-2.54,1.5, 'Blood Crystal  - Action 1 - Summon');
