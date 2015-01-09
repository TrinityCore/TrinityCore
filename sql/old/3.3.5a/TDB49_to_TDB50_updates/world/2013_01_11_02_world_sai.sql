-- Colonel Zerran SAI
SET @ENTRY := 15385;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,11000,8000,9000,11,24317,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Colonel Zerran - In Combat - Cast Sunder Armor'),
(@ENTRY,0,1,0,0,0,100,2,12000,13000,8000,9000,11,25462,0,0,0,0,0,6,0,0,0,0,0,0,0, 'Colonel Zerran - In Combat - Cast Enlarge'),
(@ENTRY,0,2,0,0,0,100,2,13000,17000,14000,18000,23,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Colonel Zerran - In Combat - Increment phase'),
(@ENTRY,0,3,0,0,1,100,2,1000,1000,1000,1000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Colonel Zerran - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,4,0,0,1,100,2,2000,2000,2000,2000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Colonel Zerran - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,5,0,0,1,100,2,3000,3000,3000,3000,23,0,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Colonel Zerran - In Combat - Decrement phase (Phase 1)');

-- Major Yeggeth SAI
SET @ENTRY := 15386;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,11000,8000,9000,11,24317,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Major Yeggeth - In Combat - Cast Sunder Armor'),
(@ENTRY,0,1,0,0,0,100,2,12000,13000,8000,9000,11,25282,0,0,0,0,0,6,0,0,0,0,0,0,0, 'Major Yeggeth - In Combat - Cast Shield of Rajaxx'),
(@ENTRY,0,2,0,0,0,100,2,13000,17000,14000,18000,23,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Major Yeggeth - In Combat - Increment phase'),
(@ENTRY,0,3,0,0,1,100,2,1000,1000,1000,1000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Major Yeggeth - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,4,0,0,1,100,2,2000,2000,2000,2000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Major Yeggeth - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,5,0,0,1,100,2,3000,3000,3000,3000,23,0,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Major Yeggeth - In Combat - Decrement phase (Phase 1)');

-- Qiraji Warrior SAI
SET @ENTRY := 15387;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,25,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Qiraji Warrior - @25%HP - Cast Enrage'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Qiraji Warrior - @20%HP - Say 0');

-- Add aura for Qiraji Warrior
DELETE FROM `creature_template_addon` WHERE `entry`=15387;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES
(15387,1, '18950');

-- NPC talk text for Qiraji Warrior
DELETE FROM `creature_text` WHERE `entry` IN (15387);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15387,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'Qiraji Warrior');

-- Major Pakkon SAI
SET @ENTRY := 15388;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,11000,8000,9000,11,24317,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Major Pakkon - In Combat - Cast Sunder Armor'),
(@ENTRY,0,1,0,0,0,100,2,12000,13000,14000,15000,11,25322,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Major Pakkon - In Combat - Cast Sweeping Slam'),
(@ENTRY,0,2,0,0,0,100,2,13000,17000,14000,18000,23,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Major Pakkon - In Combat - Increment phase'),
(@ENTRY,0,3,0,0,1,100,2,1000,1000,1000,1000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Major Pakkon - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,4,0,0,1,100,2,2000,2000,2000,2000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Major Pakkon - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,5,0,0,1,100,2,3000,3000,3000,3000,23,0,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Major Pakkon - In Combat - Decrement phase (Phase 1)');

-- Captain Drenn SAI
SET @ENTRY := 15389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,11000,8000,9000,11,24317,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Drenn - In Combat - Cast Sunder Armor'),
(@ENTRY,0,1,0,0,0,100,2,12000,13000,14000,15000,11,26550,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Captain Drenn - In Combat - Cast Lightning Cloud'),
(@ENTRY,0,2,0,0,0,100,2,13000,17000,14000,18000,23,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Drenn - In Combat - Increment phase'),
(@ENTRY,0,3,0,0,1,100,2,1000,1000,1000,1000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Drenn - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,4,0,0,1,100,2,2000,2000,2000,2000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Drenn - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,5,0,0,1,100,2,3000,3000,3000,3000,23,0,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Drenn - In Combat - Decrement phase (Phase 1)');

-- Captain Xurrem SAI
SET @ENTRY := 15390;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,11000,8000,9000,11,24317,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Xurrem - In Combat - Cast Sunder Armor'),
(@ENTRY,0,1,0,0,0,100,2,12000,13000,14000,15000,11,25425,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Captain Xurrem - In Combat - Cast Shockwave'),
(@ENTRY,0,2,0,0,0,100,2,13000,17000,14000,18000,23,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Xurrem - In Combat - Increment phase'),
(@ENTRY,0,3,0,0,1,100,2,1000,1000,1000,1000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Xurrem - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,4,0,0,1,100,2,2000,2000,2000,2000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Xurrem - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,5,0,0,1,100,2,3000,3000,3000,3000,23,0,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Xurrem - In Combat - Decrement phase (Phase 1)');

-- Captain Qeez SAI
SET @ENTRY := 15391;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,11000,8000,9000,11,24317,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Qeez - In Combat - Cast Sunder Armor'),
(@ENTRY,0,1,0,0,0,100,2,12000,13000,14000,15000,11,19134,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Captain Qeez - In Combat - Cast Frightening Shout'),
(@ENTRY,0,2,0,0,0,100,2,13000,17000,14000,18000,23,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Qeez - In Combat - Increment phase'),
(@ENTRY,0,3,0,0,1,100,2,1000,1000,1000,1000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Qeez - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,4,0,0,1,100,2,2000,2000,2000,2000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Qeez - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,5,0,0,1,100,2,3000,3000,3000,3000,23,0,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Qeez - In Combat - Decrement phase (Phase 1)');

-- Captain Tuubid SAI
SET @ENTRY := 15392;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,11000,8000,9000,11,24317,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Tuubid - In Combat - Cast Sunder Armor'),
(@ENTRY,0,1,0,0,0,100,2,12000,13000,14000,15000,11,25471,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Captain Tuubid - In Combat - Cast Attack Order'), -- Needs scripting
(@ENTRY,0,2,0,0,0,100,2,13000,17000,14000,18000,23,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Tuubid - In Combat - Increment phase'),
(@ENTRY,0,3,0,0,1,100,2,1000,1000,1000,1000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Tuubid - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,4,0,0,1,100,2,2000,2000,2000,2000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Tuubid - In Combat - Cast Cleave (Phase 1)'),
(@ENTRY,0,5,0,0,1,100,2,3000,3000,3000,3000,23,0,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Tuubid - In Combat - Decrement phase (Phase 1)');
